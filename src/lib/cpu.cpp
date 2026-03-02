#include <cpu.h>
//#include <intrin.h>
#include <SDL_timer.h>
#include <cstring>

namespace x86
{

void CPU::rdtsc()
{
    edx_eax = SDL_GetTicks();
}

void CPU::cpuid()
{
    switch(eax)
    {
    case 0:
        eax = 1;
        ebx = 0x756e6547;
        edx = 0x49656e69;
        ecx = 0x6c65746e;
        break;
    case 1:
        eax = 0x0510;
        ebx = 0x0000;
        ecx = 0x0000;
        #ifdef WITH_MMX
            edx = 0x008001BF; // Pentium MMX
        #else
            edx = 0x000001BF; // Pentium
        #endif
        break;
    default:
        NFS2_ASSERT(false);     
    }
}

}

#ifndef WITH_PEDANTIC_FPU

extern "C" void convert80x64(const x86::IEEEf80 *fp80, double *fp64)
{
    /* Read the 10 raw bytes as a little-endian 80-bit extended-precision
     * value.  Layout (bit numbering from LSB):
     *   bits  0-15  : data1  (mantissa low)
     *   bits 16-31  : data2
     *   bits 32-47  : data3
     *   bits 48-63  : data4  (mantissa high, bit 63 = explicit integer bit)
     *   bits 64-79  : data5  (bit 79 = sign, bits 78-64 = 15-bit exponent)
     */
    uint64_t mantissa = uint64_t(uint16_t(fp80->data1))
                      | (uint64_t(uint16_t(fp80->data2)) << 16)
                      | (uint64_t(uint16_t(fp80->data3)) << 32)
                      | (uint64_t(uint16_t(fp80->data4)) << 48);
    uint16_t expSign  = uint16_t(fp80->data5);
    uint32_t sign     = (expSign >> 15) & 1;
    uint32_t exp80    = expSign & 0x7FFF;

    uint64_t result;

    if (exp80 == 0)
    {
        /* Zero or denormal.  80-bit denormals are too tiny for double, so
         * flush to signed zero. */
        result = uint64_t(sign) << 63;
    }
    else if (exp80 == 0x7FFF)
    {
        /* Infinity or NaN.  Preserve the sign and NaN payload (top 51 bits
         * of the 63-bit fractional mantissa, skipping the integer bit). */
        uint64_t frac64 = mantissa & 0x7FFFFFFFFFFFFFFFULL; /* strip integer bit */
        uint64_t frac52 = frac64 >> 11;
        if (frac52 == 0 && (mantissa & 0x7FFFFFFFFFFFFFFFULL) != 0)
            frac52 = 1; /* keep NaN-ness: ensure at least one bit is set */
        result = (uint64_t(sign) << 63)
               | (uint64_t(0x7FF) << 52)
               | frac52;
    }
    else
    {
        /* Normal number.  Re-bias exponent: 80-bit bias = 16383, 64-bit = 1023 */
        int32_t unbiased = int32_t(exp80) - 16383;

        if (unbiased > 1023)
        {
            /* Overflow → infinity */
            result = (uint64_t(sign) << 63) | (uint64_t(0x7FF) << 52);
        }
        else if (unbiased < -1022)
        {
            /* Underflow → flush to signed zero (could denormalise, but for
             * game code this is perfectly fine). */
            result = uint64_t(sign) << 63;
        }
        else
        {
            uint32_t exp64 = uint32_t(unbiased + 1023);
            /* The 80-bit mantissa has an explicit integer bit (bit 63).
             * IEEE-754 double has an implicit one-bit, so we take the top
             * 52 fraction bits (bits 62..11) of the 80-bit mantissa. */
            uint64_t frac52 = (mantissa >> 11) & 0x000FFFFFFFFFFFFFULL;
            result = (uint64_t(sign) << 63)
                   | (uint64_t(exp64) << 52)
                   | frac52;
        }
    }

    memcpy(fp64, &result, sizeof(result));
}

extern "C" void convert64x80(const double *fp64, x86::IEEEf80 *fp80)
{
    uint64_t bits;
    memcpy(&bits, fp64, sizeof(bits));

    uint32_t sign   = uint32_t(bits >> 63);
    uint32_t exp64  = uint32_t((bits >> 52) & 0x7FF);
    uint64_t frac52 = bits & 0x000FFFFFFFFFFFFFULL;

    uint16_t expSign;
    uint64_t mantissa;

    if (exp64 == 0)
    {
        if (frac52 == 0)
        {
            /* Signed zero */
            expSign  = uint16_t(sign << 15);
            mantissa = 0;
        }
        else
        {
            /* Denormal double → normalise into 80-bit.  Shift fraction left
             * until the implicit bit is in position 63. */
            int shift = 0;
            uint64_t m = frac52;
            while ((m & (uint64_t(1) << 52)) == 0)
            {
                m <<= 1;
                shift++;
            }
            /* Now bit 52 of m is 1.  The unbiased exponent is
             * (1 - 1023 - shift) = -1022 - shift.  Re-bias to 80-bit. */
            int32_t unbiased = -1022 - shift;
            uint32_t exp80 = uint32_t(unbiased + 16383);
            expSign  = uint16_t((sign << 15) | exp80);
            /* Place the integer bit explicitly and shift the rest up. */
            mantissa = m << 11; /* bit 63 = integer bit (1) */
        }
    }
    else if (exp64 == 0x7FF)
    {
        /* Infinity or NaN */
        expSign = uint16_t((sign << 15) | 0x7FFF);
        if (frac52 == 0)
        {
            /* Infinity: integer bit set, fraction zero */
            mantissa = uint64_t(1) << 63;
        }
        else
        {
            /* NaN: integer bit set, preserve payload */
            mantissa = (uint64_t(1) << 63) | (frac52 << 11);
            if ((mantissa & 0x7FFFFFFFFFFFFFFFULL) == 0)
                mantissa |= 1; /* keep NaN-ness */
        }
    }
    else
    {
        /* Normal number */
        int32_t unbiased = int32_t(exp64) - 1023;
        uint32_t exp80   = uint32_t(unbiased + 16383);
        expSign  = uint16_t((sign << 15) | exp80);
        /* Reconstruct 64-bit mantissa: explicit integer bit (1) in bit 63,
         * then the 52 fraction bits in bits 62..11. */
        mantissa = (uint64_t(1) << 63) | (frac52 << 11);
    }

    fp80->data1 = x86::sreg16(uint16_t(mantissa));
    fp80->data2 = x86::sreg16(uint16_t(mantissa >> 16));
    fp80->data3 = x86::sreg16(uint16_t(mantissa >> 32));
    fp80->data4 = x86::sreg16(uint16_t(mantissa >> 48));
    fp80->data5 = x86::sreg16(expSign);
}

#endif
