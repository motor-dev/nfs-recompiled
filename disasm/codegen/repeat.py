def cg_cld(instruction, function_bounds, function_names):
    return ['cpu.flags.df = 0;']

def cg_std(instruction, function_bounds, function_names):
    return ['cpu.flags.df = 1;']

def cg_rep(instruction, code):
    return ['while (cpu.ecx)', '{'] + ['    %s'%c for c in code] + [
                '    --cpu.ecx;',
                '}'
           ]


def cg_repe(instruction, code):
    return ['while (cpu.ecx)', '{'] + ['    %s'%c for c in code] + [
                '    --cpu.ecx;',
                '    if (!cpu.flags.zf)',
                '        break;',
                '}',
           ]
cg_repz = cg_repe


def cg_repne(instruction, code):
    return ['while (cpu.ecx)', '{'] + ['    %s'%c for c in code] + [
                '    --cpu.ecx;',
                '    if (cpu.flags.zf)',
                '        break;',
                '}',
           ]
cg_repnz = cg_repne
