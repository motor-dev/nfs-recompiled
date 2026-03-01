#ifndef LIB_REGISTRY_H_
#define LIB_REGISTRY_H_

#include <lib/winapp.h>
#include <string>
#include <map>

namespace win32
{

static const x86::reg32 HKEY_CLASSES_ROOT = 0x80000000;
static const x86::reg32 HKEY_CURRENT_USER = 0x80000001;
static const x86::reg32 HKEY_LOCAL_MACHINE = 0x80000002;
static const x86::reg32 HKEY_USERS = 0x80000003;
static const x86::reg32 HKEY_PERFORMANCE_DATA = 0x80000004;
static const x86::reg32 HKEY_PERFORMANCE_TEXT = 0x80000050;
static const x86::reg32 HKEY_PERFORMANCE_NLSTEXT = 0x80000060;
static const x86::reg32 HKEY_CURRENT_CONFIG = 0x80000005;
static const x86::reg32 HKEY_DYN_DATA = 0x80000006;


class RegistryValue : public GenericResource
{
public:
    RegistryValue(x86::reg32 value);
    RegistryValue(x86::reg64 value);
    RegistryValue(const std::string& value);

    x86::reg32 query(x86::reg32* type, void* data, x86::reg32* dataSize);

public:
    enum ValueType
    {
        REG_NONE                = 0,
        REG_SZ                  = 1,
        REG_EXPAND_SZ           = 2,
        REG_BINARY              = 3,
        REG_DWORD               = 4,
        REG_DWORD_LITTLE_ENDIAN = REG_DWORD,
        REG_DWORD_BIG_ENDIAN    = 5,
        REG_LINK                = 6,
        REG_MULTI_SZ            = 7,
        REG_QWORD               = 11,
        REG_QWORD_LITTLE_ENDIAN = REG_QWORD,
    };

private:
    union Value
    {
        x86::reg32  dword;
        x86::reg64  qword;
        char        str[4096];
    };

private:
    ValueType   m_type;
    Value       m_value;
};

class RegistryKey : public GenericResource
{
public:
    RegistryKey();
    ~RegistryKey();

    void addChild(const std::string& name, RegistryKey* key);
    void addValue(const std::string& name, RegistryValue* value);
    RegistryKey* getChild(const std::string& name) const;
    RegistryValue* getValue(const std::string& name) const;

private:
    struct ci_less
    {
        // case-independent (ci) compare_less binary function
        struct nocase_compare
        {
            bool operator() (const unsigned char& c1, const unsigned char& c2) const
            {
                return tolower (c1) < tolower (c2); 
            }
        };
        
        bool operator() (const std::string& s1, const std::string& s2) const
        {
            return std::lexicographical_compare(s1.begin(), s1.end(),
                                                s2.begin(), s2.end(),
                                                nocase_compare());
    }
  };
    std::map< std::string, RegistryKey*, ci_less >      m_children;
    std::map< std::string, RegistryValue*, ci_less >    m_values;
};

}

#endif
