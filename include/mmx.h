#ifndef MMX_H_
#define MMX_H_

#include <x86.h>
//#include <intrin.h>
#include <immintrin.h>

namespace x86
{

struct regmmx
{
    __m128i reg;
    regmmx()
        :   reg()
    {
    }
    regmmx(const x86::reg64& value)
        :   reg(_mm_cvtsi64_si128(value))
    {
    }
    operator x86::reg64() const
    {
        return _mm_cvtsi128_si64(reg);
    }
    operator __m128i() const
    {
        return reg;
    }
    regmmx& operator=(const __m128i& other)
    {
        reg = other;
        return *this;
    }
};

struct MMX
{
    regmmx mm0;
    regmmx mm1;
    regmmx mm2;
    regmmx mm3;
    regmmx mm4;
    regmmx mm5;
    regmmx mm6;
    regmmx mm7;
    void init()
    {
        memset(this, 0, sizeof(*this));
    }
};

}

#endif /* !MMX_H_ */
