#ifndef FPU_H_
#define FPU_H_

#include <x86.h>
#include <cstring>
#include <cmath>

#define NFS2SE_X87_DEBUG 0

namespace x86
{

#ifdef WITH_PEDANTIC_FPU
    struct Float;
#endif

    struct IEEEf80Data
    {
        x86::reg16  data1;
        x86::reg16  data2;
        x86::reg16  data3;
        x86::reg16  data4;
        x86::reg16  data5;
    };
    struct IEEEf80
    {
        IEEEf80Data data;

        inline IEEEf80();
        inline IEEEf80(IEEEf80Data data) : data(data) {};
#ifndef WITH_PEDANTIC_FPU
        inline IEEEf80(double value);
#else
        inline void operator=(const Float &value);
#endif
        inline operator double() const;
        inline void operator=(double value);
    };

    extern "C" void convert80x64(const IEEEf80Data *fp80, double *fp64);
    extern "C" void convert80x32(const IEEEf80Data *fp80, float *fp32);
    extern "C" void convert64x80(const double *fp64, IEEEf80Data *fp80);
    extern "C" void convert32x80(const float *fp32, IEEEf80Data *fp80);
    extern "C" void converti16x80(const sreg16 *int16, IEEEf80Data *fp80);
    extern "C" void converti32x80(const sreg32 *int32, IEEEf80Data *fp80);
    extern "C" void converti64x80(const sreg64 *int64, IEEEf80Data *fp80);
    extern "C" void convert80xi16(const IEEEf80Data *fp80, sreg16 *int16);
    extern "C" void convert80xi32(const IEEEf80Data *fp80, sreg32 *int32);
    extern "C" void convert80xi64(const IEEEf80Data *fp80, sreg64 *int64);
    extern "C" x86::reg32 add80(IEEEf80Data *result, const IEEEf80Data *operand);
    extern "C" x86::reg32 sub80(IEEEf80Data *result, const IEEEf80Data *operand);
    extern "C" x86::reg32 mul80(IEEEf80Data *result, const IEEEf80Data *operand);
    extern "C" x86::reg32 div80(IEEEf80Data *result, const IEEEf80Data *operand);
    extern "C" x86::reg32 cmp80(const IEEEf80Data *f1, const IEEEf80Data *f2);
    extern "C" x86::reg32 chs80(IEEEf80Data *result);
    extern "C" x86::reg32 sin80(IEEEf80Data *result);
    extern "C" x86::reg32 cos80(IEEEf80Data *result);
    extern "C" x86::reg32 sqrt80(IEEEf80Data *result);
    extern "C" x86::reg32 tan80(IEEEf80Data *result);
    extern "C" x86::reg32 log280(IEEEf80Data *result);
    extern "C" x86::reg32 atan80(IEEEf80Data *result, const IEEEf80Data *operand);
    extern "C" x86::reg32 abs80(IEEEf80Data *result);
    extern "C" x86::reg32 round80(IEEEf80Data *result, x86::reg32 mode);
    extern "C" x86::reg32 f2xm180(IEEEf80Data *result);
    extern "C" x86::reg32 scale80(IEEEf80Data *result, const IEEEf80Data *operand);
    extern "C" x86::reg32 rem80(IEEEf80Data *result, const IEEEf80Data *operand);

    inline IEEEf80::IEEEf80()
        : data{0, 0, 0, 0, 0}
    {
    }

#ifndef WITH_PEDANTIC_FPU
    inline IEEEf80::IEEEf80(double value)
    {
        convert64x80(&value, &data);
    }
#endif

    IEEEf80::operator double() const
    {
        double result;
        convert80x64(&data, &result);
        return result;
    }

    void IEEEf80::operator=(double value)
    {
        convert64x80(&value, &data);
    }

#ifdef WITH_PEDANTIC_FPU
    struct Float
    {
        IEEEf80 f80value;
#ifdef NFS2SE_X87_DEBUG
        float dbgValue;
#endif

        Float()
            : f80value()
#ifdef NFS2SE_X87_DEBUG
              ,
              dbgValue(0)
#endif
        {
        }
        Float(const IEEEf80 &value)
            : f80value(value)
#ifdef NFS2SE_X87_DEBUG
              ,
              dbgValue(0)
#endif
        {
        }
        Float(float value)
        {
            convert32x80(&value, &f80value.data);
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&f80value.data, &dbgValue);
#endif
        }

        Float(double value)
        {
            convert64x80(&value, &f80value.data);
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&f80value.data, &dbgValue);
#endif
        }

        Float(sreg16 value)
        {
            converti16x80(&value, &f80value.data);
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&f80value.data, &dbgValue);
#endif
        }

        Float(sreg32 value)
        {
            converti32x80(&value, &f80value.data);
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&f80value.data, &dbgValue);
#endif
        }
        Float(sreg64 value)
        {
            converti64x80(&value, &f80value.data);
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&f80value.data, &dbgValue);
#endif
        }

        operator IEEEf80() const
        {
            return f80value;
        }

        operator double() const
        {
            double result;
            convert80x64(&f80value.data, &result);
            return result;
        }
        operator float() const
        {
            float result;
            convert80x32(&f80value.data, &result);
            return result;
        }
        operator sreg16() const
        {
            sreg16 result;
            convert80xi16(&f80value.data, &result);
            return result;
        }
        operator sreg32() const
        {
            sreg32 result;
            convert80xi32(&f80value.data, &result);
            return result;
        }
        operator sreg64() const
        {
            sreg64 result;
            convert80xi64(&f80value.data, &result);
            return result;
        }

        Float &operator+=(const Float &other)
        {
            add80(&f80value.data, &other.f80value.data);
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&f80value.data, &dbgValue);
#endif
            return *this;
        }

        Float &operator-=(const Float &other)
        {
            sub80(&f80value.data, &other.f80value.data);
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&f80value.data, &dbgValue);
#endif
            return *this;
        }

        Float &operator*=(const Float &other)
        {
            mul80(&f80value.data, &other.f80value.data);
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&f80value.data, &dbgValue);
#endif
            return *this;
        }

        Float &operator/=(const Float &other)
        {
            div80(&f80value.data, &other.f80value.data);
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&f80value.data, &dbgValue);
#endif
            return *this;
        }
        Float operator-() const
        {
            Float result = *this;
            chs80(&result.f80value.data);
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&result.f80value.data, &result.dbgValue);
#endif
            return result;
        }
    };

    static inline Float operator+(const Float &arg1, const Float &arg2)
    {
        Float result = arg1;
        result += arg2;
        return result;
    }

    static inline Float operator-(const Float &arg1, const Float &arg2)
    {
        Float result = arg1;
        result -= arg2;
        return result;
    }

    static inline Float operator*(const Float &arg1, const Float &arg2)
    {
        Float result = arg1;
        result *= arg2;
        return result;
    }

    static inline Float operator/(const Float &arg1, const Float &arg2)
    {
        Float result = arg1;
        result /= arg2;
        return result;
    }

    static inline Float operator+(const float &arg1, const Float &arg2)
    {
        Float result = arg1;
        result += arg2;
        return result;
    }

    static inline Float operator-(const float &arg1, const Float &arg2)
    {
        Float result = arg1;
        result -= arg2;
        return result;
    }

    static inline Float operator*(const float &arg1, const Float &arg2)
    {
        Float result = arg1;
        result *= arg2;
        return result;
    }

    static inline Float operator/(const float &arg1, const Float &arg2)
    {
        Float result = arg1;
        result /= arg2;
        return result;
    }
    static inline Float operator+(const double &arg1, const Float &arg2)
    {
        Float result = arg1;
        result += arg2;
        return result;
    }

    static inline Float operator-(const double &arg1, const Float &arg2)
    {
        Float result = arg1;
        result -= arg2;
        return result;
    }

    static inline Float operator*(const double &arg1, const Float &arg2)
    {
        Float result = arg1;
        result *= arg2;
        return result;
    }

    static inline Float operator/(const double &arg1, const Float &arg2)
    {
        Float result = arg1;
        result /= arg2;
        return result;
    }
#else
    typedef double Float;
#endif

    struct FPU
    {
        union
        {
            reg16 word;
            struct
            {
                reg8 im : 1;
                reg8 dm : 1;
                reg8 zm : 1;
                reg8 om : 1;
                reg8 um : 1;
                reg8 pm : 1;
                reg8 unused1 : 2;
                reg8 pc : 2;
                reg8 rc : 2;
                reg8 ic : 1;
                reg8 unused2 : 3;
            };
        } control;

        union
        {
            reg16 word;
            struct
            {
                reg8 ie : 1;
                reg8 de : 1;
                reg8 ze : 1;
                reg8 oe : 1;
                reg8 ue : 1;
                reg8 pe : 1;
                reg8 sf : 1;
                reg8 es : 1;
                reg8 c0 : 1;
                reg8 c1 : 1;
                reg8 c2 : 1;
                reg8 top : 3;
                reg8 c3 : 1;
                reg8 b : 1;
            };
        } status;
        x86::reg32 count;

        Float regs[8];
        void push(Float value)
        {
            count++;
            NFS2_ASSERT(count <= 8);
            regs[count & 7] = value;
        }
        Float pop()
        {
            if (count > 0)
            {
                Float result = regs[count & 7];
                count--;
                return result;
            }
            else
            {
                return 0.0;
            }
        }

        Float &st(int index)
        {
            Float &result = regs[(count - index) & 7];
            return result;
        }

        inline void init()
        {
            control.word = 0x37f;
            status.word = 0;
            count = 0;
        }

        inline void compare(const Float &val1, const Float &val2)
        {

#ifdef WITH_PEDANTIC_FPU
            x86::reg32 r = cmp80(&val1.f80value, &val2.f80value) & 0x4700;
            status.word &= ~0x4700;
            status.word |= r;
#else
            if (val1 == val2)
            {
                status.c3 = true;
                status.c2 = false;
                status.c0 = false;
            }
            else if (val1 > val2)
            {
                status.c3 = false;
                status.c2 = false;
                status.c0 = false;
            }
            else if (val1 < val2)
            {
                status.c3 = false;
                status.c2 = false;
                status.c0 = true;
            }
            else
            {
                status.c3 = true;
                status.c2 = true;
                status.c0 = true;
            }
#endif
        }

        inline Float log2(const Float &value)
        {
#ifdef WITH_PEDANTIC_FPU
            Float result = value;
            x86::reg32 r = log280(&result.f80value);
            status.word &= ~0x4700;
            status.word |= r & 0x4700;
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&result.f80value, &result.dbgValue);
#endif
            return result;
#else
            return ::log2(value);
#endif
        }

        inline Float sin(const Float &value)
        {
#ifdef WITH_PEDANTIC_FPU
            Float result = value;
            x86::reg32 r = sin80(&result.f80value);
            status.word &= ~0x4700;
            status.word |= r & 0x4700;
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&result.f80value, &result.dbgValue);
#endif
            return result;
#else
            return ::sin(value);
#endif
        }

        inline Float cos(const Float &value)
        {
#ifdef WITH_PEDANTIC_FPU
            Float result = value;
            x86::reg32 r = cos80(&result.f80value);
            status.word &= ~0x4700;
            status.word |= r & 0x4700;
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&result.f80value, &result.dbgValue);
#endif
            return result;
#else
            return ::cos(value);
#endif
        }

        inline Float tan(const Float &value)
        {
#ifdef WITH_PEDANTIC_FPU
            Float result = value;
            x86::reg32 r = tan80(&result.f80value.data);
            status.word &= ~0x4700;
            status.word |= r & 0x4700;
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&result.f80value.data, &result.dbgValue);
#endif
            return result;
#else
            return ::tan(value);
#endif
        }

        inline Float abs(const Float &value)
        {
#ifdef WITH_PEDANTIC_FPU
            Float result = value;
            x86::reg32 r = abs80(&result.f80value);
            status.word &= ~0x4700;
            status.word |= r & 0x4700;
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&result.f80value.data, &result.dbgValue);
#endif
            return result;
#else
            return ::fabs(value);
#endif
        }

        inline Float sqrt(const Float &value)
        {
#ifdef WITH_PEDANTIC_FPU
            Float result = value;
            x86::reg32 r = sqrt80(&result.f80value);
            status.word &= ~0x4700;
            status.word |= r & 0x4700;
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&result.f80value.data, &result.dbgValue);
#endif
            return result;
#else
            return ::sqrt(value);
#endif
        }

        inline Float atan(const Float &value, const Float &operand)
        {
#ifdef WITH_PEDANTIC_FPU
            Float result = value;
            x86::reg32 r = atan80(&result.f80value.data, &operand.f80value.data);
            status.word &= ~0x4700;
            status.word |= r & 0x4700;
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&result.f80value.data, &result.dbgValue);
#endif
            return result;
#else
            return ::atan2(operand, value);
#endif
        }

        inline Float rem(const Float &val1, const Float &val2)
        {
#ifdef WITH_PEDANTIC_FPU
            Float result = val1;
            x86::reg32 r = rem80(&result.f80value.data, &val2.f80value.data);
            status.word &= ~0x4700;
            status.word |= r & 0x4700;
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&result.f80value.data, &result.dbgValue);
#endif
            return result;
#else
            status.c2 = 0;
            return fmod(val1, val2);
#endif
        }

        inline Float scale(const Float &val1, const Float &val2)
        {
#ifdef WITH_PEDANTIC_FPU
            Float result = val1;
            x86::reg32 r = scale80(&result.f80value.data, &val2.f80value.data);
            status.word &= ~0x4700;
            status.word |= r & 0x4700;
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&result.f80value.data, &result.dbgValue);
#endif
            return result;
#else
            return val1 * ::pow(2, ::trunc(val2));
#endif
        }

        inline Float f2xm1(const Float &value)
        {
#ifdef WITH_PEDANTIC_FPU
            Float result = value;
            x86::reg32 r = f2xm180(&result.f80value);
            status.word &= ~0x4700;
            status.word |= r & 0x4700;
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&result.f80value, &result.dbgValue);
#endif
            return result;
#else
            return ::pow(2, value) - 1.0;
#endif
        }

        Float rndint()
        {
#ifdef WITH_PEDANTIC_FPU
            Float result = st(0);
            round80(&result.f80value, control.rc);
#ifdef NFS2SE_X87_DEBUG
            convert80x32(&result.f80value, &result.dbgValue);
#endif
            return result;
#else
            switch (control.rc)
            {
            case 0:
                return Float(round(double(st(0))));
            case 1:
                return Float(floor(double(st(0))));
            case 2:
                return Float(ceil(double(st(0))));
            case 3:
                return Float(trunc(double(st(0))));
            default:
                NFS2_ASSERT(false);
                return Float(trunc(double(st(0))));
            }
#endif
        }
    };

#ifdef WITH_PEDANTIC_FPU
    void IEEEf80::operator=(const Float &value)
    {
        *this = value.f80value;
    }
#endif

}

#endif /* !FPU_H_ */
