from . import arguments
from capstone import x86


def cg_call(instruction, function_bounds, function_names, destination):
    if destination.type == x86.X86_OP_IMM:
        if destination.imm in function_names:
            return ['cpu.esp -= 4;',
                    '%s(app, cpu);' % function_names[destination.imm],
                    'if (cpu.terminate) return;']
        else:
            return ['cpu.esp -= 4;',
                    'sub_%x(app, cpu);' % destination.imm,
                    'if (cpu.terminate) return;']
    else:
        return ['cpu.ip = %s;' % arguments.get_value(instruction, destination),
                'cpu.esp -= 4;',
                'app->dynamic_call(cpu.ip, cpu);',
                'if (cpu.terminate) return;']


def cg_ret(instruction, function_bounds, function_names, *value):
    if value:
        return ['cpu.esp += 4+%s;' % arguments.get_value(instruction, value[0]),
                'return;']
    else:
        return ['cpu.esp += 4;', 'return;']
