from capstone import x86


class FakeJmpInstruction:
    class Operand:
        def __init__(self, address):
            self.type = x86.X86_OP_IMM
            self.imm = address
    def __init__(self, instruction_address, jump_address):
        self.prefix=[0, 0, 0, 0]
        self.bytes = b'\xca\xca'
        self.opcode = b'\xca\xca'
        self.mnemonic = 'jmp'
        self.operands = [self.Operand(jump_address)]
        self.address = instruction_address
        self.size = 0
        self.eflags = 0
    def regs_access(self):
        return ([], [])


class FakeRetInstruction:
    def __init__(self, instruction_address):
        self.mnemonic = 'ret'
        self.operands = []
        self.address = instruction_address
        self.size = 0
        self.eflags = 0
    def regs_access(self):
        return ([], [])


class Subroutine:
    def __init__(self, application, section, skipped_blob, data_blob, jump_table, thread_unsafe):
        self.application = application
        self.skipped_blob = skipped_blob
        self.data_blob = data_blob
        self.jump_table = jump_table
        self.thread_unsafe = thread_unsafe
        self.section = section

        self.phony = 0
        self.jump = 0
        self.instructions = []
        self.calls = []
        self.static_labels = []
        self.dynamic_labels = []
        self.out_jumps = []

    def __contains__(self, address):
        if not self.phony:
            return address >= self.instructions[0].address and address <= self.instructions[-1].address

    def get_entry_point(self):
        return self.phony or self.instructions[0].address

    def get_start_address(self):
        return self.instructions[0].address

    def get_end_address(self):
        return self.instructions[-1].address + self.instructions[-1].size

    @classmethod
    def merge(self, subroutine1, subroutine2):
        result = Subroutine(subroutine1.application, subroutine1.section, subroutine1.skipped_blob, subroutine1.data_blob,
                            subroutine1.jump_table, subroutine1.thread_unsafe or subroutine2.thread_unsafe)
        result.instructions = subroutine1.instructions + subroutine2.instructions
        result.calls = subroutine1.calls + subroutine2.calls
        result.static_labels = subroutine1.static_labels + subroutine2.static_labels
        result.dynamic_labels = subroutine1.dynamic_labels + subroutine2.dynamic_labels
        result.out_jumps = []
        return result

    def duplicate_split(self, split_address):
        # duplicate with jump
        s = Subroutine(self.application, self.section, [], [], [], self.thread_unsafe)
        s.phony = split_address
        s.instructions = self.instructions[:]
        s.static_labels = self.static_labels[:]
        s.dynamic_labels = self.dynamic_labels[:]
        return s

    def split(self, split_address):
        dup = self.duplicate_split(split_address)
        assert dup.instructions
        return self, dup

    ZF_FLAG = x86.X86_EFLAGS_UNDEFINED_ZF | x86.X86_EFLAGS_MODIFY_ZF | x86.X86_EFLAGS_SET_ZF | x86.X86_EFLAGS_RESET_ZF
    CF_FLAG = x86.X86_EFLAGS_UNDEFINED_CF | x86.X86_EFLAGS_MODIFY_CF | x86.X86_EFLAGS_SET_CF | x86.X86_EFLAGS_RESET_CF
    SF_FLAG = x86.X86_EFLAGS_UNDEFINED_SF | x86.X86_EFLAGS_MODIFY_SF | x86.X86_EFLAGS_SET_SF | x86.X86_EFLAGS_RESET_SF
    OF_FLAG = x86.X86_EFLAGS_UNDEFINED_OF | x86.X86_EFLAGS_MODIFY_OF | x86.X86_EFLAGS_SET_OF | x86.X86_EFLAGS_RESET_OF

    def propagate_flag_use(self, instruction, instructions):
        for i in instructions:
            if i.eflags:
                of = i.eflags & self.OF_FLAG
                sf = i.eflags & self.SF_FLAG
                cf = i.eflags & self.CF_FLAG
                zf = i.eflags & self.ZF_FLAG
                if of or sf or cf or zf:
                    i.precious_flags = True
                    if of and sf and cf and zf:
                        break
        else:
            if instruction.mnemonic not in ('jmp',):
                print('0x%x: %s no instruction to set flags' % (instruction.address, instruction.mnemonic))

    def add_instruction(self, instruction):
        instruction.precious_flags = False
        # assert not (instruction.eflags & x86.X86_EFLAGS_TEST_PF)
        if instruction.mnemonic in ('jmp', 'rcr', 'adc', 'sbb'): #CAPSTONE does not indicate rcr, sbb and adc require CF
            self.propagate_flag_use(instruction, self.instructions[::-1])
        elif instruction.mnemonic.startswith('repe') or instruction.mnemonic.startswith('repne'): #REP(N)E seems to test ZF
            self.propagate_flag_use(instruction, self.instructions[::-1])
        elif instruction.eflags & (x86.X86_EFLAGS_TEST_CF | x86.X86_EFLAGS_TEST_ZF | x86.X86_EFLAGS_TEST_SF | x86.X86_EFLAGS_TEST_OF):
            self.propagate_flag_use(instruction, self.instructions[::-1])
        self.instructions.append(instruction)
        if instruction.mnemonic == 'call':
            if instruction.operands[0].type == x86.X86_OP_IMM:
                self.calls.append((instruction.address, instruction.operands[0].imm))
            elif instruction.operands[0].type == x86.X86_OP_REG:
                print('--> 0x%08x %16s %s' % (instruction.address, instruction.mnemonic, instruction.op_str))
            elif instruction.operands[0].type == x86.X86_OP_MEM:
                vtable = instruction.operands[0].mem.disp
                instruction.potential_destinations = []
                vtable_size = 0
                dest = self.application.get_dword(vtable)
                while self.application.is_code_address(dest):
                    instruction.potential_destinations.append(dest)
                    vtable += 4
                    self.calls.append((instruction.address, dest))
                    dest = self.application.get_dword(vtable)
                    vtable_size += 1
                #print('found vtable 0x%08x - %d' % (instruction.operands[0].mem.disp, vtable_size))
        if instruction.mnemonic[0] == 'j':
            if instruction.operands[0].type == x86.X86_OP_IMM:
                dest = instruction.operands[0].imm
                self.static_labels.append((instruction.address, dest))
            elif instruction.operands[0].type == x86.X86_OP_REG:
                print('--> 0x%08x %16s %s' % (instruction.address, instruction.mnemonic, instruction.op_str))
            elif instruction.operands[0].type == x86.X86_OP_MEM:
                jtable = instruction.operands[0].mem.disp
                jtable_size = 0
                dest = self.application.get_dword(jtable)
                instruction.potential_destinations = []
                while self.application.is_code_address(dest):
                    instruction.potential_destinations.append(dest)
                    self.dynamic_labels.append((instruction.address, dest))
                    jtable += 4
                    dest = self.application.get_dword(jtable)
                    jtable_size += 1
                #if jtable_size == 0:
                #   print('Invalid jump table at instruction 0x%08x: 0x%08x' % (instruction.address, jtable))
        if instruction.mnemonic in ('jmp', 'ret'):
            dest_labels = [x for _, x in self.dynamic_labels + self.static_labels]
            if instruction.address + instruction.size not in dest_labels:
                next_code = self.application.read_section_data(self.section, instruction.address + instruction.size, instruction.address + instruction.size + 2)
                if instruction.address + instruction.size + 1 in dest_labels:
                    if next_code[0] != 0x90:
                        return instruction.address + instruction.size
                elif instruction.address + instruction.size + 2 in dest_labels:
                    if next_code[0] != 0x8b or next_code[1] != 0xc0:
                        return instruction.address + instruction.size
                else:
                    return instruction.address + instruction.size

    def add_split_instruction(self, split_address):
        if split_address not in [x for _, x in self.static_labels]:
            self.static_labels.append((split_address, self.instructions[-1].address + self.instructions[-1].size))
        self.add_instruction(FakeJmpInstruction(split_address-1, self.instructions[-1].address + self.instructions[-1].size))
