from . import arguments


def cg_jmp(instruction, function_bounds, function_names, destination):
    return [arguments.get_goto_address(instruction, function_bounds, function_names, destination)]


def cg_jcxz(instruction, function_bounds, function_names, destination):
    return ['if (cpu.cx == 0)', '{', '    '+arguments.get_goto_address(instruction, function_bounds, function_names, destination), '}']


def cg_jecxz(instruction, function_bounds, function_names, destination):
    return ['if (cpu.ecx == 0)', '{', '    '+arguments.get_goto_address(instruction, function_bounds, function_names, destination), '}']


def cg_jo(instruction, function_bounds, function_names, destination):
    return ['if (cpu.flags.of)', '{', '    '+arguments.get_goto_address(instruction, function_bounds, function_names, destination), '}']


def cg_jno(instruction, function_bounds, function_names, destination):
    return ['if (!cpu.flags.of)', '{', '    '+arguments.get_goto_address(instruction, function_bounds, function_names, destination), '}']


def cg_js(instruction, function_bounds, function_names, destination):
    return ['if (cpu.flags.sf)', '{', '    '+arguments.get_goto_address(instruction, function_bounds, function_names, destination), '}']


def cg_jns(instruction, function_bounds, function_names, destination):
    return ['if (!cpu.flags.sf)', '{', '    '+arguments.get_goto_address(instruction, function_bounds, function_names, destination), '}']


def cg_jz(instruction, function_bounds, function_names, destination):
    return ['if (cpu.flags.zf)', '{', '    '+arguments.get_goto_address(instruction, function_bounds, function_names, destination), '}']
cg_je = cg_jz


def cg_jnz(instruction, function_bounds, function_names, destination):
    return ['if (!cpu.flags.zf)', '{', '    '+arguments.get_goto_address(instruction, function_bounds, function_names, destination), '}']
cg_jne = cg_jnz


def cg_jc(instruction, function_bounds, function_names, destination):
    return ['if (cpu.flags.cf)', '{', '    '+arguments.get_goto_address(instruction, function_bounds, function_names, destination), '}']
cg_jb = cg_jc
cg_jnae = cg_jc


def cg_jnc(instruction, function_bounds, function_names, destination):
    return ['if (!cpu.flags.cf)', '{', '    '+arguments.get_goto_address(instruction, function_bounds, function_names, destination), '}']
cg_jnb = cg_jnc
cg_jae = cg_jnc


def cg_jbe(instruction, function_bounds, function_names, destination):
    return ['if (cpu.flags.cf || cpu.flags.zf)', '{', '    '+arguments.get_goto_address(instruction, function_bounds, function_names, destination), '}']
cg_jna = cg_jbe


def cg_jnbe(instruction, function_bounds, function_names, destination):
    return ['if (!cpu.flags.cf && !cpu.flags.zf)', '{', '    '+arguments.get_goto_address(instruction, function_bounds, function_names, destination), '}']
cg_ja = cg_jnbe


def cg_jl(instruction, function_bounds, function_names, destination):
    return ['if (cpu.flags.sf != cpu.flags.of)', '{', '    '+arguments.get_goto_address(instruction, function_bounds, function_names, destination), '}']
cg_jnge = cg_jl


def cg_jnl(instruction, function_bounds, function_names, destination):
    return ['if (cpu.flags.sf == cpu.flags.of)', '{', '    '+arguments.get_goto_address(instruction, function_bounds, function_names, destination), '}']
cg_jge = cg_jnl


def cg_jle(instruction, function_bounds, function_names, destination):
    return ['if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))', '{', '    '+arguments.get_goto_address(instruction, function_bounds, function_names, destination), '}']
cg_jng = cg_jle


def cg_jnle(instruction, function_bounds, function_names, destination):
    return ['if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))', '{', '    '+arguments.get_goto_address(instruction, function_bounds, function_names, destination), '}']
cg_jg = cg_jnle


def cg_jp(instruction, function_bounds, function_names, destination):
    return ['if (cpu.flags.pf)', '{', '    '+arguments.get_goto_address(instruction, function_bounds, function_names, destination), '}']
cg_jpe = cg_jp


def cg_jnp(instruction, function_bounds, function_names, destination):
    return ['if (!cpu.flags.pf)', '{', '    '+arguments.get_goto_address(instruction, function_bounds, function_names, destination), '}']
cg_jpo = cg_jnp
