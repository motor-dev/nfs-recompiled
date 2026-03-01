import sys
try:
    import capstone
except ImportError:
    print('Capstone not found; verify that the Capstone extension for Python is installed')
    print('%s -m pip show capstone' % sys.executable)
    sys.exit(1)
import ctypes
from .subroutine import Subroutine
from .application import Application

nops = (
    b'\x8d\x80\x00\x00\x00\x00\x8d\x92\x00\x00\x00\x00\x8d\x40\x00',
    b'\x8b\xc0\x8d\x80\x00\x00\x00\x00\x8d\x92\x00\x00\x00\x00',
    b'\x8d\x80\x00\x00\x00\x00\x8d\x92\x00\x00\x00\x00\x8b\xc0',
    b'\x90\x8d\x80\x00\x00\x00\x00\x8d\x92\x00\x00\x00\x00',
    b'\x8d\x80\x00\x00\x00\x00\x8d\x92\x00\x00\x00\x00\x90',
    b'\x8d\x80\x00\x00\x00\x00\x8d\x92\x00\x00\x00\x00',
    b'\x8d\x80\x00\x00\x00\x00\x8d\x52\x00\x8b\xdb',
    b'\x8d\x80\x00\x00\x00\x00\x8d\x54\x22\x00',
    b'\x8d\x80\x00\x00\x00\x00\x8d\x52\x00',
    b'\x8d\x80\x00\x00\x00\x00\x8b\xd2',
    b'\x8d\x80\x00\x00\x00\x00\x90',
    b'\x8d\x80\x00\x00\x00\x00',
    b'\x8d\x40\x00\x8b\xc9',
    b'\x8d\x44\x20\x00',
    b'\x8d\x40\x00',
    b'\x8b\xc0',
    b'\x90',
)


def realign(application, section, current_address):
    new_current_address = (current_address + 15) & 0xfffffff0
    skipped_code = application.read_section_data(section, current_address, new_current_address)
    if current_address != new_current_address:
        if sum([c for c in skipped_code]) == 0:
            current_address = new_current_address
        elif skipped_code in nops:
            current_address = new_current_address
    if current_address != new_current_address:
        new_current_address = (current_address + 3) & 0xfffffffc
        skipped_code = application.read_section_data(section, current_address, new_current_address)
        if sum([c for c in skipped_code]) == 0:
            current_address = new_current_address
        elif skipped_code in nops:
            current_address = new_current_address
        else:
            new_current_address = (current_address + 1) & 0xfffffffe
            skipped_code = application.read_section_data(section, current_address, new_current_address)
            if sum([c for c in skipped_code]) == 0:
                current_address = new_current_address
            elif skipped_code in nops:
                current_address = new_current_address
            else:
                #print('oops: 0x%08x %s' % (current_address, ''.join('%02x'%c for c in skipped_code)))
                skipped_code = ''
    return (current_address, skipped_code)


def disassemble(name, exe_path, data_segments=[], known_subroutines=[], split_instructions=[],
                thread_routines=[], thread_segments=[], merge_hints=[], skip_instructions=[],
                type=Application, rebase_after=None):
    disassembler = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    disassembler.detail = True

    rebase_address = 0
    if rebase_after:
        rebase_address = rebase_after.sections[-1][1] + rebase_after.sections[-1][2]
    application = type(name, exe_path, rebase_address)

    subroutines_to_check = []
    found_subroutines = known_subroutines[:]

    for section in application.get_code_sections():
        current_address = application.get_address(section)
        try:
            while current_address < application.get_address_end(section):
                data_blob = ''
                jump_table = []
                labels = []

                current_address, skipped_code = realign(application, section, current_address)
                for data_segment in data_segments:
                    if data_segment[0] == current_address:
                        current_address = data_segment[1]
                        data_blob = application.read_section_data(section, data_segment[0], data_segment[1])

                x = application.get_dword(current_address)
                y = application.get_dword(current_address + 4)
                if application.is_code_address(x) and application.is_code_address(y):
                    while application.is_code_address(x):
                        current_address += 4
                        x = application.get_dword(current_address)
                for data_segment in data_segments:
                    if data_segment[0] == current_address:
                        current_address = data_segment[1]
                        data_blob = application.read_section_data(section, data_segment[0], data_segment[1])

                if current_address >= application.get_address_end(section):
                    break

                current_address, skipped_code_2 = realign(application, section, current_address)
                skipped_code = skipped_code_2 or skipped_code

                if current_address >= application.get_address_end(section):
                    break

                #print('subroutine start [0x%08x]' % current_address)
                instructions = [x for x in application.read_section_data(section, current_address, current_address + 2)]
                if instructions[0] < 0x51 or instructions[0] > 0x57 or instructions[1] < 0x51 or instructions[1] > 0x57:
                    subroutines_to_check.append(current_address)

                code_part = application.read_section_data(section, current_address, current_address+8192)
                if code_part:
                    subroutine = Subroutine(application, section, skipped_code, data_blob, jump_table, current_address in thread_routines)
                    for instruction in disassembler.disasm(code_part, current_address):
                        current_address = subroutine.add_instruction(instruction)
                        if current_address:
                            break
                        for split_instruction in split_instructions:
                            if instruction.address < split_instruction and instruction.address + instruction.size > split_instruction:
                                subroutine.add_split_instruction(split_instruction)
                                for extra_inst in disassembler.disasm(application.read_section_data(section, split_instruction, instruction.address + instruction.size), split_instruction):
                                    subroutine.add_instruction(extra_inst)
                    else:
                        print('Invalid instruction or end of stream at address 0x%08x' % (instruction.address + instruction.size))
                        current_address = instruction.address + instruction.size + 1
                    application.add_subroutine(subroutine)
                else:
                    break
        except KeyboardInterrupt:
            pass

    application.reduce_subroutines(merge_hints)
    application.split_subroutines(known_subroutines)

    return application
