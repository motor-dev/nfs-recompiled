from . import arguments


def cg_movsx(instruction, function_bounds, function_names, destination, operand):
    return ['%s = x86::reg%d(static_cast<x86::sreg%d>(%s));' % (arguments.get_value(instruction, destination),
                                                                destination.size*8,
                                                                operand.size*8,
                                                                arguments.get_value(instruction, operand))]


def cg_cwb(instruction, function_bounds, function_names):
    return ['cpu.ax = x86::reg16(static_cast<x86::sreg8>(cpu.al));']


def cg_cwde(instruction, function_bounds, function_names):
    return ['cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));']


def cg_cdq(instruction, function_bounds, function_names):
    return ['cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));']


def cg_inc(instruction, function_bounds, function_names, destination):
    if not instruction.precious_flags:
        return ['(%s)++;' % arguments.get_value(instruction, destination)]
    else:
        return ['{',
                '    x86::reg%d& tmp = %s;' % (destination.size * 8, arguments.get_value(instruction, destination)),
                '    cpu.flags.of = ~(1 & (tmp >> %d));' % (destination.size * 8 - 1),
                '    tmp++;',
                '    cpu.flags.of &= 1 & (tmp >> %d);' % (destination.size * 8 - 1),
                '    cpu.set_szp(tmp);',
                '}']


def cg_mul(instruction, function_bounds, function_names, operand):
    if not instruction.precious_flags:
        if operand.size == 1:
            return ['cpu.ax = cpu.al * %s;' % arguments.get_value(instruction, operand)]
        elif operand.size == 4:
            return ['cpu.edx_eax = x86::reg%d(cpu.eax) * x86::reg%d(%s);' % (operand.size * 16, operand.size * 16,
                                                                             arguments.get_value(instruction, operand)),]
    else:
        if operand.size == 1:
            return ['{',
                    '    cpu.ax = cpu.al * %s;' % arguments.get_value(instruction, operand),
                    '    cpu.flags.of = cpu.flags.cf = (cpu.ah != 0);',
                    '}']
        elif operand.size == 4:
            return ['{',
                    '    cpu.edx_eax = x86::reg%d(cpu.eax) * x86::reg%d(%s);' % (operand.size * 16, operand.size * 16,
                                                                                 arguments.get_value(instruction, operand)),
                    '    cpu.flags.of = cpu.flags.cf = (cpu.edx != 0);',
                    '}']


def cg_imul(instruction, function_bounds, function_names, *operands):
    if len(operands) == 1:
        if operands[0].size == 1:
            dest =  'cpu.ax';
            dest_size = 2;
            op1 = 'x86::sreg16(static_cast<x86::sreg8>(cpu.al)';
        elif operands[0].size == 4:
            dest =  'cpu.edx_eax';
            dest_size = 8;
            op1 = 'x86::sreg64(static_cast<x86::sreg32>(cpu.eax))';
        op2 = arguments.sign_extend(instruction, operands[0], dest_size)
        if not instruction.precious_flags:
            return ['%s = x86::reg%d(%s * %s);' % (dest, dest_size * 8, op1, op2)]
        else:
            return ['{',
                    '    %s = %s * %s;' % (dest, op1, op2),
                    '    cpu.flags.of = cpu.flags.cf = (static_cast<x86::sreg%d>(%s) != %s);' % (dest_size*8, dest, op1),
                    '}']
    elif len(operands) >= 2:
        if len(operands) == 2:
            dest_size = operands[0].size * 2
            dest = arguments.get_value(instruction, operands[0])
            op1 = arguments.sign_extend(instruction, operands[0], dest_size)
            op2 = arguments.sign_extend(instruction, operands[1], dest_size)
        else:
            dest_size = operands[0].size * 2
            dest = arguments.get_value(instruction, operands[0])
            op1 = arguments.sign_extend(instruction, operands[1], dest_size)
            op2 = arguments.sign_extend(instruction, operands[2], dest_size)
        if not instruction.precious_flags:
            return ['%s = x86::reg%d(%s * %s);' % (dest, operands[0].size*8, op1, op2)]
        else:
            return ['{',
                    '    x86::sreg%d tmp = %s * %s;' % (dest_size*8, op1, op2),
                    '    %s = static_cast<x86::reg%d>(static_cast<x86::sreg%d>(tmp));' % (dest, operands[0].size*8, operands[0].size*8),
                    '    cpu.flags.of = cpu.flags.cf = (tmp != %s);' % (arguments.sign_extend(instruction, operands[0], dest_size)),
                    '}']


def cg_idiv(instruction, function_bounds, function_names, operand):
    if operand.size == 1:
        return ['{',
                '    x86::sreg16 tmp = x86::sreg16(cpu.ax);',
                '    x86::sreg8 d = x86::sreg8(%s);' % arguments.get_value(instruction, operand),
                '    cpu.ax = x86::reg16(tmp / d);',
                '    cpu.ah = x86::reg8(tmp % d);',
                '}']
    else: #4
        return ['{',
                '    x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);',
                '    x86::sreg32 d = x86::sreg32(%s);' % arguments.get_value(instruction, operand),
                '    cpu.edx_eax = x86::reg64(tmp / d);',
                '    cpu.edx = x86::reg32(tmp % d);',
                '}']



def cg_div(instruction, function_bounds, function_names, operand):
    if operand.size == 1:
        return ['{',
                '    x86::reg16 tmp = cpu.ax;',
                '    x86::reg8 d = %s;' % arguments.get_value(instruction, operand),
                '    cpu.ax /= d;',
                '    cpu.ah = tmp % d;',
                '}']
    else: #4
        return ['{',
                '    x86::reg64 tmp = cpu.edx_eax;',
                '    x86::reg32 d = %s;' % arguments.get_value(instruction, operand),
                '    cpu.edx_eax /= d;',
                '    cpu.edx = tmp % d;',
                '}']


def cg_add(instruction, function_bounds, function_names, destination, operand):
    if not instruction.precious_flags:
        return ['(%s) += x86::reg%d(%s);' % (arguments.get_value(instruction, destination),
                                             destination.size * 8,
                                             arguments.sign_extend(instruction, operand, destination.size))]
    else:
        return ['{',
                '    x86::reg%d& tmp1 = %s;' % (destination.size * 8, arguments.get_value(instruction, destination)),
                '    x86::reg%d tmp2 = x86::reg%d(%s);' % (destination.size * 8,
                                                           destination.size * 8,
                                                           arguments.sign_extend(instruction, operand, destination.size)),
                '    x86::reg%d result = tmp1 + tmp2;' % (destination.size * 8),
                '    cpu.flags.of = 1 & (tmp1 >> %d);' % (destination.size * 8 - 1),
                '    cpu.flags.of ^= 1 & (result >> %d);' % (destination.size * 8 - 1),
                '    cpu.flags.of &= (1 & (tmp1 >> %d)) == (1 & (tmp2 >> %d));' % ((destination.size * 8 - 1), (destination.size * 8 - 1)),
                '    cpu.flags.cf = result < tmp1;',
                '    tmp1 = result;',
                '    cpu.set_szp(tmp1);',
                '}']


def cg_adc(instruction, function_bounds, function_names, destination, operand):
    if not instruction.precious_flags:
        return ['(%s) += x86::reg%d(%s + cpu.flags.cf);' % (arguments.get_value(instruction, destination),
                                                            destination.size * 8,
                                                            arguments.sign_extend(instruction, operand, destination.size))]
    else:
        return ['{',
                '    x86::reg%d& tmp1 = %s;' % (destination.size * 8, arguments.get_value(instruction, destination)),
                '    x86::reg%d tmp2 = x86::reg%d(%s) + cpu.flags.cf;' % (destination.size * 8,
                                                                          destination.size * 8,
                                                                          arguments.sign_extend(instruction, operand, destination.size)),
                '    x86::reg%d result = tmp1 + tmp2;' % (destination.size * 8),
                '    cpu.flags.of = 1 & (tmp1 >> %d);' % (destination.size * 8 - 1),
                '    cpu.flags.of ^= 1 & (result >> %d);' % (destination.size * 8 - 1),
                '    cpu.flags.of &= (1 & (tmp1 >> %d)) == (1 & (tmp2 >> %d));' % ((destination.size * 8 - 1), (destination.size * 8 - 1)),
                '    cpu.flags.cf = result < tmp1;',
                '    tmp1 = result;',
                '    cpu.set_szp(tmp1);',
                '}']


def cg_dec(instruction, function_bounds, function_names, destination):
    if not instruction.precious_flags:
        return ['(%s)--;' % arguments.get_value(instruction, destination)]
    else:
        return ['{',
                '    x86::reg%d& tmp = %s;' % (destination.size * 8, arguments.get_value(instruction, destination)),
                '    cpu.flags.of = 1 & (tmp >> %d);' % (destination.size * 8 - 1),
                '    tmp--;',
                '    cpu.flags.of &= ~(1 & (tmp >> %d));' % (destination.size * 8 - 1),
                '    cpu.set_szp(tmp);',
                '}']


def cg_sub(instruction, function_bounds, function_names, destination, operand):
    if not instruction.precious_flags:
        return ['(%s) -= x86::reg%d(%s);' % (arguments.get_value(instruction, destination),
                                             destination.size * 8,
                                             arguments.sign_extend(instruction, operand, destination.size))]
    else:
        return ['{',
                '    x86::reg%d& tmp1 = %s;' % (destination.size * 8, arguments.get_value(instruction, destination)),
                '    x86::reg%d tmp2 = x86::reg%d(%s);' % (destination.size * 8, destination.size * 8, arguments.sign_extend(instruction, operand, destination.size)),
                '    x86::reg%d result = tmp1 - tmp2;' % (destination.size * 8),
                '    cpu.flags.cf = tmp1 < tmp2;',
                '    cpu.flags.of = 1 & (tmp1 >> %d);' % (destination.size * 8 - 1),
                '    cpu.flags.of ^= 1 & (result >> %d);' % (destination.size * 8 - 1),
                '    cpu.flags.of &= (1 & (tmp1 >> %d)) != (1 & (tmp2 >> %d));' % ((destination.size * 8 - 1), (destination.size * 8 - 1)),
                '    tmp1 = result;',
                '    cpu.set_szp(tmp1);',
                '}']


def cg_sbb(instruction, function_bounds, function_names, destination, operand):
    if not instruction.precious_flags:
        return ['(%s) -= x86::reg%d(%s + cpu.flags.cf);' % (arguments.get_value(instruction, destination),
                                                            destination.size * 8,
                                                            arguments.sign_extend(instruction, operand, destination.size))]
    else:
        return ['{',
                '    x86::reg%d& tmp1 = %s;' % (destination.size * 8, arguments.get_value(instruction, destination)),
                '    x86::reg%d tmp2 = x86::reg%d(%s) + cpu.flags.cf;' % (destination.size * 8, destination.size * 8, arguments.sign_extend(instruction, operand, destination.size)),
                '    x86::reg%d result = tmp1 - tmp2;' % (destination.size * 8),
                '    cpu.flags.cf = tmp1 < tmp2;',
                '    cpu.flags.of = 1 & (tmp1 >> %d);' % (destination.size * 8 - 1),
                '    cpu.flags.of ^= 1 & (result >> %d);' % (destination.size * 8 - 1),
                '    cpu.flags.of &= (1 & (tmp1 >> %d)) != (1 & (tmp2 >> %d));' % ((destination.size * 8 - 1), (destination.size * 8 - 1)),
                '    tmp1 = result;',
                '    cpu.set_szp(tmp1);',
                '}']


def cg_neg(instruction, function_bounds, function_names, destination):
    if not instruction.precious_flags:
        return ['%s = ~%s + 1;' % (arguments.get_value(instruction, destination), arguments.get_value(instruction, destination))]
    else:
        return ['{',
                '    x86::reg%d tmp1 = 0;' % (destination.size * 8),
                '    x86::reg%d& tmp2 = %s;' % (destination.size * 8, arguments.get_value(instruction, destination)),
                '    x86::reg%d result = tmp1 - tmp2;' % (destination.size * 8),
                '    cpu.flags.cf = tmp1 < tmp2;',
                '    cpu.flags.of = 1 & (tmp1 >> %d);' % (destination.size * 8 - 1),
                '    cpu.flags.of ^= 1 & (result >> %d);' % (destination.size * 8 - 1),
                '    cpu.flags.of &= (1 & (tmp1 >> %d)) != (1 & (tmp2 >> %d));' % ((destination.size * 8 - 1), (destination.size * 8 - 1)),
                '    tmp2 = result;',
                '    cpu.set_szp(tmp2);',
                '}']

def cg_clc(instruction, function_bounds, function_names):
    return ['cpu.flags.cf = 0;']

def cg_cmc(instruction, function_bounds, function_names):
    return ['cpu.flags.cf ^= 1;']

