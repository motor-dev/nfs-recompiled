#ifndef CPU_H_
#define CPU_H_

#include <x86.h>
#include <fpu.h>
#include <mmx.h>

#define REGISTER_A(n)       \
union                       \
{                           \
    x86::reg32      e##n##x;\
    x86::reg16      n##x;   \
    struct                  \
    {                       \
        x86::reg8   n##l;   \
        x86::reg8   n##h;   \
    };                      \
}


#define REGISTER_P(n)       \
union                       \
{                           \
    x86::reg32  e##n;       \
    x86::reg16  n;          \
}

namespace x86
{

struct CPU
{
    union Flags
    {
        reg32 eflags;
        struct
        {
            reg16 hiword;
            union
            {
                reg16 word;
                struct
                {
                    reg8 lo;
                    reg8 hi;
                };
                struct
                {
                    reg8 cf      : 1;
                    reg8 unused1 : 1;
                    reg8 pf      : 1;
                    reg8 unused2 : 1;
                    reg8 af      : 1;
                    reg8 unused3 : 1;
                    reg8 zf      : 1;
                    reg8 sf      : 1;
                    reg8 unused4 : 1;
                    reg8 unused5 : 1;
                    reg8 df      : 1;
                    reg8 of      : 1;
                    reg8 unused6 : 4;
                };
            };
        };
    };

    union
    {
        reg64 edx_eax;
        struct
        {
            REGISTER_A(a);
            REGISTER_A(d);
        };
    };
    REGISTER_A(c);
    REGISTER_A(b);
    REGISTER_P(sp);
    REGISTER_P(bp);
    REGISTER_P(si);
    REGISTER_P(di);

    REGISTER_P(cs);
    REGISTER_P(ds);
    REGISTER_P(es);
    REGISTER_P(fs);
    REGISTER_P(gs);
    REGISTER_P(ss);

    reg32 ip;

    Flags flags;

    inline void set_szp(reg8 v)
    {
        flags.zf = !v;
        flags.sf = 1 & (v >> 7);
    }
    inline void set_szp(reg16 v)
    {
        flags.zf = !v;
        flags.sf = 1 & (v >> 15);
    }
    inline void set_szp(reg32 v)
    {
        flags.zf = !v;
        flags.sf = 1 & (v >> 31);
    }
    inline void clear_co()
    {
        flags.cf = 0;
        flags.of = 0;
    }
    inline void init(reg32 fs, reg32 ip)
    {
        memset(this, 0, sizeof(*this));
        fpu.init();
        terminate = false;
        this->flags.eflags = 0x00200202;
        this->flags.cf = 0;
        this->flags.zf = 0;
        this->flags.of = 0;
        this->flags.sf = 0;
        this->flags.df = 0;
        this->flags.pf = 0;
        this->ecs = 0;
        this->eds = 0;
        this->ees = 0;
        this->efs = fs;
        this->egs = 0;
        this->ess = 0;
        this->ip = ip;
    }

    void cpuid();
    void rdtsc();
    FPU fpu;
    MMX mmx;
    bool terminate;
};

}

#endif /* !CPU_H_ */
