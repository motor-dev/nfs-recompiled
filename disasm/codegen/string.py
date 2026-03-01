from . import arguments, condition


def cg_stos(instruction, function_bounds, function_names, edi, eax):
    return ['%s = %s;' % (arguments.get_value(instruction, edi), arguments.get_value(instruction, eax)),
            'if (cpu.flags.df)',
            '{',
            '    cpu.edi -= %d;' % eax.size,
            '}',
            'else',
            '{',
            '    cpu.edi += %d;' % eax.size,
            '}']
cg_stosb = cg_stos
cg_stosw = cg_stos
cg_stosd = cg_stos


def cg_movs(instruction, function_bounds, function_names, edi, esi):
    return ['%s = %s;' % (arguments.get_value(instruction, edi), arguments.get_value(instruction, esi)),
            'if (cpu.flags.df)',
            '{',
            '    cpu.edi -= %d;' % edi.size,
            '    cpu.esi -= %d;' % esi.size,
            '}',
            'else',
            '{',
            '    cpu.edi += %d;' % edi.size,
            '    cpu.esi += %d;' % esi.size,
            '}']
cg_movsb = cg_movs
cg_movsw = cg_movs
cg_movsd = cg_movs


def cg_scas(instruction, function_bounds, function_names, eax, edi):
    return condition.cg_cmp(instruction, function_bounds, function_names, eax, edi) + [
            'if (cpu.flags.df)',
            '{',
            '    cpu.edi -= %d;' % eax.size,
            '}',
            'else',
            '{',
            '    cpu.edi += %d;' % eax.size,
            '}']
cg_scasb = cg_scas
cg_scasw = cg_scas
cg_scasd = cg_scas


def cg_cmpsb(instruction, function_bounds, function_names, esi, edi):
    return condition.cg_cmp(instruction, function_bounds, function_names, esi, edi) + [
            'if (cpu.flags.df)',
            '{',
            '    cpu.edi -= 1;',
            '    cpu.esi -= 1;',
            '}',
            'else',
            '{',
            '    cpu.edi += 1;',
            '    cpu.esi += 1;',
            '}']
