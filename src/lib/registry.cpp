#include <lib/registry.h>

namespace win32
{

RegistryValue::RegistryValue(x86::reg32 value)
    :   m_type(REG_DWORD)
{
    m_value.dword = value;
}

RegistryValue::RegistryValue(const std::string& value)
    :   m_type(REG_SZ)
{
    memcpy(m_value.str, value.c_str(), value.size()+1);
}

x86::reg32 RegistryValue::query(x86::reg32* type, void* data, x86::reg32* dataSize)
{
    if (type)
        *type = m_type;
    switch (m_type)
    {
    case REG_DWORD:
        if (*dataSize >= sizeof(m_value.dword))
        {
            memcpy(data, &m_value.dword, sizeof(m_value.dword));
        }
        *dataSize = sizeof(m_value.dword);
        return 0;
    case REG_SZ:
        {
            x86::reg32 len = x86::reg32(strlen(m_value.str) + 1);
            if (*dataSize >= len)
            {
                memcpy(data, m_value.str, len);
            }
            *dataSize = len;
            return 0;
        }
    default:
        NFS2_ASSERT(false);
        return 1;
    }
}

RegistryKey::RegistryKey()
{
}
RegistryKey::~RegistryKey()
{
}

void RegistryKey::addChild(const std::string& name, RegistryKey* key)
{
    m_children[name] = key;
}

RegistryKey* RegistryKey::getChild(const std::string& name) const
{
    std::map< std::string, RegistryKey*, ci_less >::const_iterator it = m_children.find(name);
    if (it != m_children.end())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

void RegistryKey::addValue(const std::string& name, RegistryValue* value)
{
    m_values[name] = value;
}

RegistryValue* RegistryKey::getValue(const std::string& name) const
{
    std::map< std::string, RegistryValue*, ci_less >::const_iterator it = m_values.find(name);
    if (it != m_values.end())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

}