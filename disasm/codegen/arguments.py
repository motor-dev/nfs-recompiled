from capstone import x86


def get_value(instruction, operand):
    if operand.type == x86.X86_OP_IMM:
        return '%d /*%#x*/' % (operand.imm, operand.imm)
    elif operand.type == x86.X86_OP_REG:
        return 'cpu.%s' % (instruction.reg_name(operand.reg))
    elif operand.type == x86.X86_OP_MEM:
        offsets = []
        if operand.mem.segment:
            offsets.append('cpu.e%s' % instruction.reg_name(operand.mem.segment))
        if operand.mem.base != 0:
            offsets.append('cpu.%s' % instruction.reg_name(operand.mem.base))
        if operand.mem.disp != 0:
            offsets.append('x86::reg32(%d) /* %#x */' % (operand.mem.disp, operand.mem.disp))
        if operand.mem.index != 0:
            offsets.append('cpu.%s * %s' % (instruction.reg_name(operand.mem.index),
                                            operand.mem.scale))
        else:
            if operand.mem.scale != 1:
                print('%#x' % instruction.address, instruction.mnemonic, instruction.op_str)
        return '*app->getMemory<x86::reg%s>(%s)' % (operand.size*8, ' + '.join(offsets))
    else:
        assert False, operand.type


def get_mmx_value(instruction, operand):
    if operand.type == x86.X86_OP_IMM:
        return '%d /*%#x*/' % (operand.imm, operand.imm)
    elif operand.type == x86.X86_OP_REG:
        return 'cpu.mmx.%s' % (instruction.reg_name(operand.reg))
    elif operand.type == x86.X86_OP_MEM:
        offsets = []
        if operand.mem.segment:
            offsets.append('cpu.e%s' % instruction.reg_name(operand.mem.segment))
        if operand.mem.base != 0:
            offsets.append('cpu.%s' % instruction.reg_name(operand.mem.base))
        if operand.mem.disp != 0:
            offsets.append('x86::reg32(%d) /* %#x */' % (operand.mem.disp, operand.mem.disp))
        if operand.mem.index != 0:
            offsets.append('cpu.%s * %s' % (instruction.reg_name(operand.mem.index),
                                            operand.mem.scale))
        else:
            if operand.mem.scale != 1:
                print('%#x' % instruction.address, instruction.mnemonic, instruction.op_str)
        return 'x86::regmmx(*app->getMemory<x86::reg64>(%s))' % (' + '.join(offsets))
    else:
        assert False, operand.type


def get_float(instruction, operand):
    if operand.type == x86.X86_OP_IMM:
        return '%g' % operand.imm
    elif operand.type == x86.X86_OP_REG:
        reg_name = instruction.reg_name(operand.reg)
        if reg_name[-1] == ')':
            reg_name = reg_name[-2]
        else:
            reg_name = reg_name[-1]
        return 'cpu.fpu.st(%s)' % reg_name
    elif operand.type == x86.X86_OP_MEM:
        offsets = []
        if operand.mem.segment:
            offsets.append('cpu.e%s' % instruction.reg_name(operand.mem.segment))
        if operand.mem.base != 0:
            offsets.append('cpu.%s' % instruction.reg_name(operand.mem.base))
        if operand.mem.disp != 0:
            offsets.append('x86::reg32(%d) /* %#x */' % (operand.mem.disp, operand.mem.disp))
        if operand.mem.index != 0:
            offsets.append('cpu.%s * %s' % (instruction.reg_name(operand.mem.index),
                                            operand.mem.scale))
        else:
            if operand.mem.scale != 1:
                print('%#x' % instruction.address, instruction.mnemonic, instruction.op_str)
        if operand.size == 4:
            return '*app->getMemory<float>(%s)' % (' + '.join(offsets))
        elif operand.size == 8:
            return '*app->getMemory<double>(%s)' % (' + '.join(offsets))
        elif operand.size == 10:
            return '*app->getMemory<x86::IEEEf80>(%s)' % (' + '.join(offsets))
        else:
            assert False, operand.size
    else:
        assert False, instruction.op_str

def get_float_type(size):
    if size == 4:
        return 'float'
    elif size == 8:
        return 'double'
    else:
        return 'x86::Float'

def get_address(instruction, operand):
    if operand.type == x86.X86_OP_IMM:
        return '%d /*%#x*/' % (operand.imm, operand.imm)
    elif operand.type == x86.X86_OP_REG:
        return 'cpu.%s' % (instruction.reg_name(operand.reg))
    elif operand.type == x86.X86_OP_MEM:
        offsets = []
        if operand.mem.segment:
            offsets.append('cpu.e%s' % instruction.reg_name(operand.mem.segment))
        if operand.mem.base != 0:
            offsets.append('cpu.%s' % instruction.reg_name(operand.mem.base))
        if operand.mem.disp != 0:
            offsets.append('x86::reg32(%d) /* %#x */' % (operand.mem.disp, operand.mem.disp))
        if operand.mem.index != 0:
            offsets.append('cpu.%s * %s' % (instruction.reg_name(operand.mem.index),
                                            operand.mem.scale))
        else:
            if operand.mem.scale != 1:
                print('%#x' % instruction.address, instruction.mnemonic, instruction.op_str)
        return ' + '.join(offsets)
    else:
        assert False, operand.type


def get_goto_address(instruction, function_bounds, function_names, operand):
    if operand.type == x86.X86_OP_IMM:
        if operand.imm >= function_bounds[0] and operand.imm < function_bounds[1]:
            return 'goto L_0x%08x;' % operand.imm
        else:
            if operand.imm in function_names:
                return 'return %s(app, cpu);' % function_names[operand.imm]
            else:
                return 'return sub_%x(app, cpu);' % operand.imm
    elif operand.type == x86.X86_OP_REG:
        return 'return app->dynamic_call(cpu.%s, cpu);' % (instruction.reg_name(operand.reg))
    elif operand.type == x86.X86_OP_MEM:
        offsets = []
        if operand.mem.base != 0:
            offsets.append('cpu.%s' % instruction.reg_name(operand.mem.base))
        if operand.mem.disp != 0:
            offsets.append('%d' % operand.mem.disp)
        if operand.mem.index != 0:
            offsets.append('cpu.%s * %s' % (instruction.reg_name(operand.mem.index),
                                            operand.mem.scale))
        else:
            if operand.mem.scale != 1:
                print('%#x' % instruction.address, instruction.mnemonic, instruction.op_str)
        for dest in instruction.potential_destinations:
            if dest < function_bounds[0] or dest > function_bounds[1]:
                print('error! switch/case with at least one jump out of reach; function 0x%x/0x%x, jump to 0x%x' % (function_bounds[0], function_bounds[1], dest))
                return 'return app->dynamic_call(*app->getMemory<x86::reg32>(%s), cpu);' % (' + '.join(offsets))
        else:
            if instruction.potential_destinations:
                return 'cpu.ip = *app->getMemory<x86::reg32>(%s); goto dynamic_jump;' % (' + '.join(offsets))
            else:
                return 'return app->dynamic_call(*app->getMemory<x86::reg32>(%s), cpu);' % (' + '.join(offsets))
    else:
        assert False, operand.type


def sign_extend(instruction, operand, size):
    result = 'x86::sreg%d(%s)' % (operand.size*8, get_value(instruction, operand))
    if operand.size != size:
        result = 'x86::sreg%d(%s)' % (size*8, result)
    return result
