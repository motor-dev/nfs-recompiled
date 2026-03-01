def cg_nop(instruction, function_bounds, function_names):
    return [';']


def cg_cpuid(instruction, function_bounds, function_names):
    return ['cpu.cpuid();']


def cg_int3(instruction, function_bounds, function_names):
    return ['NFS2_ASSERT(false);']


def cg_rdtsc(instruction, function_bounds, function_names):
    return ['cpu.rdtsc();']