from . import arguments


def cg_mov(instruction, function_bounds, function_names, destination, operand):
    return ['%s = %s;' % (arguments.get_value(instruction, destination), arguments.get_value(instruction, operand))]


def cg_movzx(instruction, function_bounds, function_names, destination, operand):
    return ['%s = x86::reg%d(%s);' % (arguments.get_value(instruction, destination),
                                      destination.size*8,
                                      arguments.get_value(instruction, operand))]


def cg_lea(instruction, function_bounds, function_names, destination, operand):
    return ['%s = x86::reg32(%s);' % (arguments.get_value(instruction, destination), arguments.get_address(instruction, operand))]


def cg_xchg(instruction, function_bounds, function_names, destination, operand):
    return ['{',
            '    x86::reg%d tmp = %s;' % (destination.size*8, arguments.get_value(instruction, destination)),
            '    %s = %s;' % (arguments.get_value(instruction, destination), arguments.get_value(instruction, operand)),
            '    %s = tmp;' % (arguments.get_value(instruction, operand)),
            '}']
