from . import arguments


def cg_fninit(instruction, function_bounds, function_names):
    return ['cpu.fpu.init();']


def cg_wait(instruction, function_bounds, function_names):
    return ['/*nothing*/;']
cg_fwait = cg_wait
cg_fclex = cg_wait
cg_fnclex = cg_wait

def cg_fst(instruction, function_bounds, function_names, destination):
    return ['%s = %s(cpu.fpu.st(0));' % (arguments.get_float(instruction, destination), arguments.get_float_type(destination.size))]


def cg_fstp(instruction, function_bounds, function_names, destination):
    return cg_fst(instruction, function_bounds, function_names, destination) + ['cpu.fpu.pop();']


def cg_fld(instruction, function_bounds, function_names, value):
    return ['cpu.fpu.push(x86::Float(%s));' % arguments.get_float(instruction, value)]


def cg_fild(instruction, function_bounds, function_names, value):
    return ['cpu.fpu.push(x86::Float(x86::sreg%d(%s)));' % (value.size*8, arguments.get_value(instruction, value))]


def cg_fldz(instruction, function_bounds, function_names):
    return ['cpu.fpu.push(0.0);']


def cg_fld1(instruction, function_bounds, function_names):
    return ['cpu.fpu.push(1.0);']


def cg_fldpi(instruction, function_bounds, function_names):
    return ['cpu.fpu.push(3.1415926535897932);']


def cg_fldl2e(instruction, function_bounds, function_names):
    return ['cpu.fpu.push(1.4426950408889634);']

def cg_fldln2(instruction, function_bounds, function_names):
    return ['cpu.fpu.push(0.6931471805599453);']

def cg_fyl2x(instruction, function_bounds, function_names):
    return [
        'cpu.fpu.st(1) = cpu.fpu.log2(cpu.fpu.st(0)) * cpu.fpu.st(1);',
        'cpu.fpu.pop();'
    ]

def cg_fadd(instruction, function_bounds, function_names, *argument):
    if len(argument) == 1:
        return ['cpu.fpu.st(0) += x86::Float(%s);' % arguments.get_float(instruction, *argument)]
    elif len(argument) == 2:
        return ['%s += x86::Float(%s);' % (arguments.get_float(instruction, argument[0]), arguments.get_float(instruction, argument[1]))]
    else:
        assert False


def cg_faddp(instruction, function_bounds, function_names, *argument):
    if len(argument) == 0:
        return ['cpu.fpu.st(1) += cpu.fpu.st(0);', 'cpu.fpu.pop();']
    elif len(argument) == 1:
        return ['%s += cpu.fpu.st(0);' % arguments.get_float(instruction, *argument), 'cpu.fpu.pop();']
    else:
        assert False


def cg_fsub(instruction, function_bounds, function_names, *argument):
    if len(argument) == 1:
        return ['cpu.fpu.st(0) -= x86::Float(%s);' % arguments.get_float(instruction, *argument)]
    elif len(argument) == 2:
        return ['%s -= x86::Float(%s);' % (arguments.get_float(instruction, argument[0]), arguments.get_float(instruction, argument[1]))]
    else:
        assert False


def cg_fsubp(instruction, function_bounds, function_names, *argument):
    if len(argument) == 0:
        return ['cpu.fpu.st(1) -= cpu.fpu.st(0);', 'cpu.fpu.pop();']
    elif len(argument) == 1:
        return ['%s -= cpu.fpu.st(0);' % arguments.get_float(instruction, *argument), 'cpu.fpu.pop();']
    else:
        assert False


def cg_fsubr(instruction, function_bounds, function_names, *argument):
    if len(argument) == 1:
        return ['cpu.fpu.st(0) = %s - cpu.fpu.st(0);' % arguments.get_float(instruction, *argument)]
    elif len(argument) == 2:
        return ['%s = x86::Float(%s) - x86::Float(%s);' % (arguments.get_float(instruction, argument[0]),
                                   arguments.get_float(instruction, argument[1]),
                                   arguments.get_float(instruction, argument[0]))]
    else:
        assert False


def cg_fsubrp(instruction, function_bounds, function_names, *argument):
    if len(argument) == 0:
        return ['cpu.fpu.st(1) = cpu.fpu.st(0) - cpu.fpu.st(1);', 'cpu.fpu.pop();']
    elif len(argument) == 1:
        return ['%s = cpu.fpu.st(0) - x86::Float(%s);' % (arguments.get_float(instruction, *argument),
                                              arguments.get_float(instruction, *argument)),
                'cpu.fpu.pop();']
    else:
        assert False


def cg_fmul(instruction, function_bounds, function_names, *argument):
    if len(argument) == 1:
        return ['cpu.fpu.st(0) *= x86::Float(%s);' % arguments.get_float(instruction, *argument)]
    elif len(argument) == 2:
        return ['%s *= %s;' % (arguments.get_float(instruction, argument[0]), arguments.get_float(instruction, argument[1]))]
    else:
        assert False


def cg_fmulp(instruction, function_bounds, function_names, *argument):
    if len(argument) == 0:
        return ['cpu.fpu.st(1) *= cpu.fpu.st(0);', 'cpu.fpu.pop();']
    elif len(argument) == 1:
        return ['%s *= cpu.fpu.st(0);' % arguments.get_float(instruction, *argument), 'cpu.fpu.pop();']
    else:
        assert False


def cg_fdiv(instruction, function_bounds, function_names, *argument):
    if len(argument) == 1:
        return ['cpu.fpu.st(0) /= x86::Float(%s);' % arguments.get_float(instruction, *argument)]
    elif len(argument) == 2:
        return ['%s /= x86::Float(%s);' % (arguments.get_float(instruction, argument[0]), arguments.get_float(instruction, argument[1]))]
    else:
        assert False


def cg_fdivp(instruction, function_bounds, function_names, *argument):
    if len(argument) == 0:
        return ['cpu.fpu.st(1) /= cpu.fpu.st(0);', 'cpu.fpu.pop();']
    elif len(argument) == 1:
        return ['%s /= cpu.fpu.st(0);' % arguments.get_float(instruction, *argument), 'cpu.fpu.pop();']
    else:
        assert False


def cg_fdivr(instruction, function_bounds, function_names, *argument):
    if len(argument) == 1:
        return ['cpu.fpu.st(0) = x86::Float(%s) / cpu.fpu.st(0);' % (arguments.get_float(instruction, *argument))]
    elif len(argument) == 2:
        return ['%s = %s / %s;' % (arguments.get_float(instruction, argument[0]),
                                   arguments.get_float(instruction, argument[1]),
                                   arguments.get_float(instruction, argument[0]))]
    else:
        assert False, instruction.op_str


def cg_fdivrp(instruction, function_bounds, function_names, *argument):
    if len(argument) == 0:
        return ['cpu.fpu.st(1) = cpu.fpu.st(0) / cpu.fpu.st(1);',
                'cpu.fpu.pop();']
    elif len(argument) == 1:
        return ['%s = cpu.fpu.st(0) / x86::Float(%s);' % (arguments.get_float(instruction, *argument),
                                          arguments.get_float(instruction, *argument)),
                'cpu.fpu.pop();']
    else:
        assert False


def cg_frndint(instruction, function_bounds, function_names):
    return ['cpu.fpu.st(0) = cpu.fpu.rndint();']


def cg_fistp(instruction, function_bounds, function_names, destination):
    return ['%s = x86::reg%d(x86::sreg%s(cpu.fpu.rndint()));' % (arguments.get_value(instruction, destination),
                                                              destination.size * 8,
                                                              destination.size * 8),
            'cpu.fpu.pop();']


def cg_fxch(instruction, function_bounds, function_names, *argument):
    if len(argument) == 0:
        dest = 'cpu.fpu.st(1)'
    elif len(argument) == 1:
        dest = arguments.get_float(instruction, argument[0])
    elif len(argument) == 2:
        dest = arguments.get_float(instruction, argument[1])
    else:
        assert False
    return ['{',
            '    x86::Float tmp = cpu.fpu.st(0);',
            '    cpu.fpu.st(0) = %s;' % (dest),
            '    %s = tmp;' % (dest),
            '}']


def cg_fchs(instruction, function_bounds, function_names):
    return ['cpu.fpu.st(0) = -cpu.fpu.st(0);']


def cg_ftst(instruction, function_bounds, function_names):
    return ['cpu.fpu.compare(cpu.fpu.st(0), 0.0);']


def cg_fcom(instruction, function_bounds, function_names, operand):
    return ['cpu.fpu.compare(cpu.fpu.st(0), %s);' % arguments.get_float(instruction, operand)]


def cg_fcomp(instruction, function_bounds, function_names, operand):
    return cg_fcom(instruction, function_bounds, function_names, operand) + ['cpu.fpu.pop();']


def cg_fcompp(instruction, function_bounds, function_names):
    return ['cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));',
            'cpu.fpu.pop();',
            'cpu.fpu.pop();']


def cg_fnstsw(instruction, function_bounds, function_names, destination):
    return ['%s = cpu.fpu.status.word;' % arguments.get_value(instruction, destination)]
cg_fstsw = cg_fnstsw


def cg_fldcw(instruction, function_bounds, function_names, operand):
    return ['cpu.fpu.control.word = %s;' % arguments.get_value(instruction, operand)]


def cg_fstcw(instruction, function_bounds, function_names, destination):
    return ['%s = cpu.fpu.control.word;' % arguments.get_value(instruction, destination)]
cg_fnstcw = cg_fstcw


def cg_fptan(instruction, function_bounds, function_names):
    return ['cpu.fpu.st(0) = cpu.fpu.tan(cpu.fpu.st(0));',
            'cpu.fpu.push(1.0);']


def cg_fsin(instruction, function_bounds, function_names):
    return ['cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));']


def cg_fcos(instruction, function_bounds, function_names):
    return ['cpu.fpu.st(0) = cpu.fpu.cos(cpu.fpu.st(0));']


def cg_fabs(instruction, function_bounds, function_names):
    return ['cpu.fpu.st(0) = cpu.fpu.abs(cpu.fpu.st(0));']


def cg_fsqrt(instruction, function_bounds, function_names):
    return ['cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));']


def cg_fpatan(instruction, function_bounds, function_names):
    return ['cpu.fpu.st(1) = cpu.fpu.atan(cpu.fpu.st(0), cpu.fpu.st(1));',
            'cpu.fpu.pop();']


def cg_fprem(instruction, function_bounds, function_names):
    return ['cpu.fpu.st(0) = cpu.fpu.rem(cpu.fpu.st(0), cpu.fpu.st(1));']


def cg_fscale(instruction, function_bounds, function_names):
    return ['cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));']


def cg_f2xm1(instruction, function_bounds, function_names):
    return ['cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));']

