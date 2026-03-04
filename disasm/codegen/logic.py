from . import arguments
from capstone import x86


def cg_bswap(instruction, function_bounds, function_names, parameter):
    assert parameter.size == 4
    if parameter.type == x86.X86_OP_MEM:
        tmp = '    x86::reg32 tmp = %s;' % arguments.get_value(instruction, parameter)
    else:
        tmp = '    x86::reg32& tmp = %s;' % arguments.get_value(instruction, parameter)

    return ['{',
            tmp,
            '    tmp = ( tmp               << 16) ^  (tmp >> 16);',
            '    tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);',
            '}'
        ]


def cg_sahf(instruction, function_bounds, function_names):
    return ['cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);']

def cg_lahf(instruction, function_bounds, function_names):
    return ['cpu.ah = 0x02 | (cpu.flags.lo & 0xD7);']


def cg_sal(instruction, function_bounds, function_names, operand, shift):
    if not instruction.precious_flags:
        return ['%s <<= %s %% 32;' % (arguments.get_value(instruction, operand),
                                      arguments.get_value(instruction, shift))]
    else:
        return ['{',
                '    x86::reg%d tmp = %s %% 32;' % (shift.size * 8, arguments.get_value(instruction, shift)),
                '    x86::reg%d& op = %s;' % (operand.size * 8, arguments.get_value(instruction, operand)),
                '    if (tmp)',
                '    {',
                '        cpu.flags.cf = 1 & (op >> (%d - tmp));' % (operand.size * 8),
                '        cpu.set_szp((op <<= tmp));',
                '        if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (%d - 1))));' % (operand.size * 8),
                '    }',
                '}']
cg_shl = cg_sal


def cg_sar(instruction, function_bounds, function_names, operand, shift):
    if not instruction.precious_flags:
        return ['%s = x86::reg%d(x86::sreg%d(%s) >> (%s %% 32));' % (arguments.get_value(instruction, operand),
                                                                     operand.size * 8,
                                                                     operand.size * 8,
                                                                     arguments.get_value(instruction, operand),
                                                                     arguments.get_value(instruction, shift))]
    else:
        return ['{',
                '    x86::reg%d tmp = %s %% 32;' % (shift.size * 8, arguments.get_value(instruction, shift)),
                '    x86::reg%d& op = %s;' % (operand.size * 8, arguments.get_value(instruction, operand)),
                '    if (tmp)',
                '    {',
                '        cpu.flags.cf = 1 & (x86::sreg%d(op) >> (tmp - 1));' % (operand.size * 8),
                '        if (tmp == 1) cpu.flags.of = 0;',
                '        cpu.set_szp((op = x86::reg%d(x86::sreg%d(op) >> tmp)));' % (operand.size * 8, operand.size * 8),
                '    }',
                '}']


def cg_shr(instruction, function_bounds, function_names, operand, shift):
    if not instruction.precious_flags:
        return ['%s >>= %s %% 32;' % (arguments.get_value(instruction, operand),
                                      arguments.get_value(instruction, shift))]
    else:
        return ['{',
                '    x86::reg%d tmp = %s %% 32;' % (shift.size * 8, arguments.get_value(instruction, shift)),
                '    x86::reg%d& op = %s;' % (operand.size * 8, arguments.get_value(instruction, operand)),
                '    if (tmp)',
                '    {',
                '        cpu.flags.cf = 1 & (op >> (tmp - 1));',
                '        if (tmp == 1) cpu.flags.of = (1 & (op >> (%d - 1)));' % (operand.size * 8),
                '        cpu.set_szp((op >>= tmp));',
                '    }',
                '}']

def cg_shld(instruction, function_bounds, function_names, destination, operand, shift):
    if not instruction.precious_flags:
        return ['{',
                '    x86::reg%d& destination = %s;' % (operand.size * 8, arguments.get_value(instruction, destination)),
                '    destination <<= (%s %% %d);' % (arguments.get_value(instruction, shift), operand.size*8),
                '    destination |= %s >> (%d - (%s %% %d));' % (arguments.get_value(instruction, operand),
                                                                  operand.size*8,
                                                                  arguments.get_value(instruction, shift),
                                                                  operand.size*8),
                '}']
    else:
        return ['{',
                '    x86::reg%d& destination = %s;' % (operand.size * 8, arguments.get_value(instruction, destination)),
                '    cpu.flags.cf = 1 & (destination >> (%d - (%s %% %d)));' % (operand.size*8,
                                                                               arguments.get_value(instruction, shift),
                                                                               operand.size*8),
                '    cpu.flags.of = 1 & (destination >> (%d - 1));' % (operand.size*8),
                '    destination <<= (%s %% %d);' % (arguments.get_value(instruction, shift), operand.size*8),
                '    destination |= %s >> (%d - (%s %% %d));' % (arguments.get_value(instruction, operand),
                                                                  operand.size*8,
                                                                  arguments.get_value(instruction, shift),
                                                                  operand.size*8),
                '    cpu.flags.of ^= 1 & (destination >> (%d - 1));' % (operand.size*8),
                '    cpu.set_szp(destination);',
                '}']


def cg_shrd(instruction, function_bounds, function_names, destination, operand, shift):
    if not instruction.precious_flags:
        return ['{',
                '    x86::reg%d& destination = %s;' % (operand.size * 8, arguments.get_value(instruction, destination)),
                '    destination >>= (%s %% %d);' % (arguments.get_value(instruction, shift), operand.size*8),
                '    destination |= %s  << (%d - (%s %% %d));' % (arguments.get_value(instruction, operand),
                                                                  operand.size*8,
                                                                  arguments.get_value(instruction, shift),
                                                                  operand.size*8),
                '}']
    else:
        return ['{',
                '    x86::reg%d& destination = %s;' % (operand.size * 8, arguments.get_value(instruction, destination)),
                '    cpu.flags.cf = 1 & (destination >> (%s - 1));' % arguments.get_value(instruction, shift),
                '    cpu.flags.of = 1 & (destination >> (%d - 1));' % (operand.size*8),
                '    destination >>= (%s %% %d);' % (arguments.get_value(instruction, shift), operand.size*8),
                '    destination |= %s  << (%d - (%s %% %d));' % (arguments.get_value(instruction, operand),
                                                                  operand.size*8,
                                                                  arguments.get_value(instruction, shift),
                                                                  operand.size*8),
                '    cpu.flags.of ^= 1 & (destination >> (%d - 1));' % (operand.size*8),
                '    cpu.set_szp(destination);',
                '}']

def cg_rcr(instruction, function_bounds, function_names, operand, shift):
    return ['{',
            '    x86::reg%d& op = %s;' % (operand.size*8, arguments.get_value(instruction, operand)),
            '    x86::reg32 shift = %s %% %s;' % (arguments.get_value(instruction, shift), operand.size*8),
            '    cpu.flags.of = (1 & (op >> %d)) ^ cpu.flags.cf;' % (operand.size*8-1),
            '    while (shift)',
            '    {',
            '        x86::reg%d cf = op & 1;' % (operand.size*8),
            '        op = op >> 1 | x86::reg32(cpu.flags.cf) << %d;' % (operand.size*8-1),
            '        cpu.flags.cf = cf;',
            '        shift--;',
            '    }',
            '}']

def cg_ror(instruction, function_bounds, function_names, operand, shift):
    if not instruction.precious_flags:
        return ['{',
                '    x86::reg%d& op = %s;' % (operand.size*8, arguments.get_value(instruction, operand)),
                '    x86::reg32 shift = %s %% %s;' % (arguments.get_value(instruction, shift), operand.size*8),
                '    while (shift)',
                '    {',
                '        x86::reg%d cf = op & 1;' % (operand.size*8),
                '        op = op >> 1 | cf << %d;' % (operand.size*8-1),
                '        shift--;',
                '    }',
                '}']
    else:
        return [
            '{',
            '    x86::reg%d& op = %s;' % (operand.size*8, arguments.get_value(instruction, operand)),
            '    x86::reg32 count = %s %% %d;' % (arguments.get_value(instruction, shift), operand.size*8),
            '    if (count) {',
            '        op = (op >> count) | (op << (%d - count));' % (operand.size*8),
            '        cpu.flags.cf = (op >> (%d - 1)) & 1;' % (operand.size*8),
            '        if (count == 1) {',
            '            cpu.flags.of = ((op >> (%d - 1)) ^ (op >> (%d - 2))) & 1;' % (operand.size*8, operand.size*8),
            '        }',
            '    }',
            '}'
        ]


def cg_rol(instruction, function_bounds, function_names, operand, shift):
    if not instruction.precious_flags:
        return ['{',
                '    x86::reg%d& op = %s;' % (operand.size*8, arguments.get_value(instruction, operand)),
                '    x86::reg32 shift = %s %% %s;' % (arguments.get_value(instruction, shift), operand.size*8),
                '    while (shift)',
                '    {',
                '        x86::reg%d cf = (op & 0x8%s);' % (operand.size*8, '0'*(operand.size*2-1)),
                '        op = op << 1 | cf >> %d;' % (operand.size*8-1),
                '        shift--;',
                '    }',
                '}']
    else:
        return [
            '{',
            '    x86::reg%d& op = %s;' % (operand.size*8, arguments.get_value(instruction, operand)),
            '    x86::reg32 count = %s %% %d;' % (arguments.get_value(instruction, shift), operand.size*8),
            '    if (count) {',
            '        op = (op << count) | (op >> (%d - count));' % (operand.size*8),
            '        cpu.flags.cf = op & 1;',
            '        if (count == 1) {',
            '            cpu.flags.of = ((op >> (%d - 1)) ^ cpu.flags.cf) & 1;' % (operand.size*8),
            '        }',
            '    }',
            '}'
        ]


def cg_not(instruction, function_bounds, function_names, destination):
    return ['%s = ~%s;' % (arguments.get_value(instruction, destination), arguments.get_value(instruction, destination))]


def cg_and(instruction, function_bounds, function_names, destination, operand):
    if not instruction.precious_flags:
        return ['%s &= x86::reg%d(%s);' % (arguments.get_value(instruction, destination),
                                           destination.size*8,
                                           arguments.sign_extend(instruction, operand, destination.size))]
    else:
        return ['cpu.clear_co();',
                'cpu.set_szp((%s &= x86::reg%d(%s)));' % (arguments.get_value(instruction, destination),
                                                          destination.size*8,
                                                          arguments.sign_extend(instruction, operand, destination.size))]


def cg_or(instruction, function_bounds, function_names, destination, operand):
    if not instruction.precious_flags:
        return ['%s |= x86::reg%d(%s);' % (arguments.get_value(instruction, destination),
                                           destination.size*8,
                                           arguments.sign_extend(instruction, operand, destination.size))]
    else:
        return ['cpu.clear_co();',
                'cpu.set_szp((%s |= x86::reg%d(%s)));' % (arguments.get_value(instruction, destination),
                                                          destination.size*8,
                                                          arguments.sign_extend(instruction, operand, destination.size))]


def cg_xor(instruction, function_bounds, function_names, destination, operand):
    if not instruction.precious_flags:
        return ['%s ^= x86::reg%d(%s);' % (arguments.get_value(instruction, destination),
                                           destination.size*8,
                                           arguments.sign_extend(instruction, operand, destination.size))]
    else:
        return ['cpu.clear_co();',
                'cpu.set_szp((%s ^= x86::reg%d(%s)));' % (arguments.get_value(instruction, destination),
                                                          destination.size*8,
                                                          arguments.sign_extend(instruction, operand, destination.size))]

def cg_bsr(instruction, function_bounds, function_names, destination, source):
    return ['if (%s == 0)' % arguments.get_value(instruction, source),
            '{',
            '    cpu.flags.zf = 1;',
            '}',
            'else',
            '{',
            '    cpu.flags.zf = 0;',
            '    %s = x86::reg%d(31 - __builtin_clz(%s));' % (arguments.get_value(instruction, destination),
                                                              destination.size * 8,
                                                              arguments.get_value(instruction, source)),
            '}']

def cg_bsf(instruction, function_bounds, function_names, destination, source):
    return ['if (%s == 0)' % arguments.get_value(instruction, source),
            '{',
            '    cpu.flags.zf = 1;',
            '}',
            'else',
            '{',
            '    cpu.flags.zf = 0;',
            '    %s = x86::reg%d(__builtin_ctz(%s));' % (arguments.get_value(instruction, destination),
                                                         destination.size * 8,
                                                         arguments.get_value(instruction, source)),
            '}']
