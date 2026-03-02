from . import arguments
from capstone import x86


def cg_emms(instruction, function_bounds, function_names):
    return ['cpu.mmx.init();']


def cg_movd(instruction, function_bounds, function_names, op1, op2):
    if op2.type == x86.X86_OP_REG and op2.size == 4:
        return ['%s = { _mm_cvtsi32_si128(%s) };' % (arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_value(instruction, op2))]
    elif op2.type == x86.X86_OP_IMM:
        return ['%s = { _mm_cvtsi32_si128(%s) };' % (arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_value(instruction, op2))]
    elif op2.type == x86.X86_OP_MEM:
        return ['%s = { _mm_loadu_si32(&%s) };' % (arguments.get_mmx_value(instruction, op1),
                                               arguments.get_value(instruction, op2))]
    else:
        if op1.type == x86.X86_OP_MEM:
            return ['_mm_storeu_si32(&%s, %s);' % (arguments.get_value(instruction, op1),
                                                    arguments.get_mmx_value(instruction, op2))]
        elif op1.type == x86.X86_OP_REG and op1.size == 4:
            return ['%s = _mm_cvtsi128_si32(%s);' % (arguments.get_value(instruction, op1),
                                                     arguments.get_mmx_value(instruction, op2))]
        else:
            assert False, instruction.op_str


def cg_movq(instruction, function_bounds, function_names, op1, op2):
    if op1.type == x86.X86_OP_MEM:
        return ['%s = %s;' % (arguments.get_value(instruction, op1),
                              arguments.get_mmx_value(instruction, op2))]
    else:
        return ['%s = %s;' % (arguments.get_mmx_value(instruction, op1),
                              arguments.get_mmx_value(instruction, op2))]


def cg_pxor(instruction, function_bounds, function_names, op1, op2):
    return ['%s = { _mm_xor_si128(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                             arguments.get_mmx_value(instruction, op1),
                                             arguments.get_mmx_value(instruction, op2))]


def cg_paddw(instruction, function_bounds, function_names, op1, op2):
    return ['%s = { _mm_add_epi16(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                             arguments.get_mmx_value(instruction, op1),
                                             arguments.get_mmx_value(instruction, op2))]


def cg_paddd(instruction, function_bounds, function_names, op1, op2):
    return ['%s = { _mm_add_epi32(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                             arguments.get_mmx_value(instruction, op1),
                                             arguments.get_mmx_value(instruction, op2))]


def cg_paddsb(instruction, function_bounds, function_names, op1, op2):
    return ['%s = { _mm_adds_epi8(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                             arguments.get_mmx_value(instruction, op1),
                                             arguments.get_mmx_value(instruction, op2))]


def cg_paddsw(instruction, function_bounds, function_names, op1, op2):
    return ['%s = { _mm_adds_epi16(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                              arguments.get_mmx_value(instruction, op1),
                                              arguments.get_mmx_value(instruction, op2))]


def cg_pmulhw(instruction, function_bounds, function_names, op1, op2):
    return ['%s = { _mm_mulhi_epi16(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                               arguments.get_mmx_value(instruction, op1),
                                               arguments.get_mmx_value(instruction, op2))]


def cg_pmaddwd(instruction, function_bounds, function_names, op1, op2):
    return ['%s = { _mm_madd_epi16(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                              arguments.get_mmx_value(instruction, op1),
                                              arguments.get_mmx_value(instruction, op2))]


def cg_pand(instruction, function_bounds, function_names, op1, op2):
    return ['%s = { _mm_and_si128(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                             arguments.get_mmx_value(instruction, op1),
                                             arguments.get_mmx_value(instruction, op2))]

def cg_por(instruction, function_bounds, function_names, op1, op2):
    return ['%s = { _mm_or_si128(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                            arguments.get_mmx_value(instruction, op1),
                                            arguments.get_mmx_value(instruction, op2))]


def cg_psllw(instruction, function_bounds, function_names, op1, op2):
    if op2.type == x86.X86_OP_IMM:
        return ['%s = { _mm_slli_epi16(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_value(instruction, op2))]
    else:
        return ['%s = { _mm_sll_epi16(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_mmx_value(instruction, op2))]


def cg_pslld(instruction, function_bounds, function_names, op1, op2):
    if op2.type == x86.X86_OP_IMM:
        return ['%s = { _mm_slli_epi32(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_value(instruction, op2))]
    else:
        return ['%s = { _mm_sll_epi32(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_mmx_value(instruction, op2))]


def cg_psllq(instruction, function_bounds, function_names, op1, op2):
    if op2.type == x86.X86_OP_IMM:
        return ['%s = { _mm_slli_epi64(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_value(instruction, op2))]
    else:
        return ['%s = { _mm_sll_epi64(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_mmx_value(instruction, op2))]


def cg_psrlw(instruction, function_bounds, function_names, op1, op2):
    if op2.type == x86.X86_OP_IMM:
        return ['%s = { _mm_srli_epi16(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_value(instruction, op2))]
    else:
        return ['%s = { _mm_srl_epi16(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_mmx_value(instruction, op2))]


def cg_psrld(instruction, function_bounds, function_names, op1, op2):
    if op2.type == x86.X86_OP_IMM:
        return ['%s = { _mm_srli_epi32(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_value(instruction, op2))]
    else:
        return ['%s = { _mm_srl_epi32(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_mmx_value(instruction, op2))]


def cg_psrlq(instruction, function_bounds, function_names, op1, op2):
    if op2.type == x86.X86_OP_IMM:
        return ['%s = { _mm_srli_epi64(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_value(instruction, op2))]
    else:
        return ['%s = { _mm_srl_epi64(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_mmx_value(instruction, op2))]
    

def cg_psraw(instruction, function_bounds, function_names, op1, op2):
    if op2.type == x86.X86_OP_IMM:
        return ['%s = { _mm_srai_epi16(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_value(instruction, op2))]
    else:
        return ['%s = { _mm_sra_epi16(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_mmx_value(instruction, op2))]


def cg_psrad(instruction, function_bounds, function_names, op1, op2):
    if op2.type == x86.X86_OP_IMM:
        return ['%s = { _mm_srai_epi32(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_value(instruction, op2))]
    else:
        return ['%s = { _mm_sra_epi32(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_mmx_value(instruction, op2))]


def cg_psraq(instruction, function_bounds, function_names, op1, op2):
    if op2.type == x86.X86_OP_IMM:
        return ['%s = { _mm_srai_epi64(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_value(instruction, op2))]
    else:
        return ['%s = { _mm_sra_epi64(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_mmx_value(instruction, op1),
                                                 arguments.get_mmx_value(instruction, op2))]


def cg_punpckhbw(instruction, function_bounds, function_names, op1, op2):
    # MMX punpckhbw interleaves bytes 4-7 (high half of 64-bit), but SSE _mm_unpackhi_epi8
    # interleaves bytes 8-15. Shift the 64-bit data right by 32 bits to move bytes 4-7
    # into positions 0-3, then use the lo-unpack intrinsic.
    return ['%s = { _mm_unpacklo_epi8(_mm_srli_epi64(%s, 32), _mm_srli_epi64(%s, 32)) };' % (
                arguments.get_mmx_value(instruction, op1),
                arguments.get_mmx_value(instruction, op1),
                arguments.get_mmx_value(instruction, op2))]


def cg_punpcklbw(instruction, function_bounds, function_names, op1, op2):
    return ['%s = { _mm_unpacklo_epi8(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_mmx_value(instruction, op2))]


def cg_punpckhwd(instruction, function_bounds, function_names, op1, op2):
    # MMX punpckhwd interleaves words 2-3 (high half of 64-bit), but SSE _mm_unpackhi_epi16
    # interleaves words 4-7. Shift right by 32 bits then use lo-unpack.
    return ['%s = { _mm_unpacklo_epi16(_mm_srli_epi64(%s, 32), _mm_srli_epi64(%s, 32)) };' % (
                arguments.get_mmx_value(instruction, op1),
                arguments.get_mmx_value(instruction, op1),
                arguments.get_mmx_value(instruction, op2))]


def cg_punpcklwd(instruction, function_bounds, function_names, op1, op2):
    return ['%s = { _mm_unpacklo_epi16(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_mmx_value(instruction, op2))]


def cg_punpckldq(instruction, function_bounds, function_names, op1, op2):
    return ['%s = { _mm_unpacklo_epi32(%s, %s) };' % (arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_mmx_value(instruction, op1),
                                                  arguments.get_mmx_value(instruction, op2))]


def cg_packuswb(instruction, function_bounds, function_names, op1, op2):
    # SSE _mm_packus_epi16 puts op1's 4 packed bytes in dword 0 and op2's in dword 2 (byte 8).
    # We must combine them into the low 64 bits: [op1 bytes 0-3, op2 bytes 0-3].
    return ['{ __m128i _packed = _mm_packus_epi16(%s, %s); %s = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }' % (
                arguments.get_mmx_value(instruction, op1),
                arguments.get_mmx_value(instruction, op2),
                arguments.get_mmx_value(instruction, op1))]


def cg_packssdw(instruction, function_bounds, function_names, op1, op2):
    # SSE packs op1's 2 valid dwords into result words 0-1 and op2's into words 4-5.
    # Combine into low 64 bits: [op1 words 0-1, op2 words 0-1].
    return ['{ __m128i _packed = _mm_packs_epi32(%s, %s); %s = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }' % (
                arguments.get_mmx_value(instruction, op1),
                arguments.get_mmx_value(instruction, op2),
                arguments.get_mmx_value(instruction, op1))]


def cg_packsswb(instruction, function_bounds, function_names, op1, op2):
    # SSE packs op1's 4 valid words into bytes 0-3 and op2's into bytes 8-11.
    # Combine into low 64 bits: [op1 bytes 0-3, op2 bytes 0-3].
    return ['{ __m128i _packed = _mm_packs_epi16(%s, %s); %s = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }' % (
                arguments.get_mmx_value(instruction, op1),
                arguments.get_mmx_value(instruction, op2),
                arguments.get_mmx_value(instruction, op1))]




