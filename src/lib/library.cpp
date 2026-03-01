#include <lib/library.h>
#include <algorithm>

namespace win32
{

static Library* s_libraries = 0;

x86::reg32 Library::getSymbolIndex()
{
    static x86::reg32 s_symbolIndex = 0x400500;
    return s_symbolIndex++;
}

Library::Library(const char* name)
    :   m_next(s_libraries)
    ,   m_name(name)
{
    s_libraries = this;
}

Library::~Library()
{
    NFS2_ASSERT(s_libraries == this);
    s_libraries = m_next;
}

void Library::registerSymbols(WinApplication *app)
{
    for (std::map<std::string, Symbol>::iterator it = m_methods.begin();
         it != m_methods.end();
         ++it)
    {
        app->registerMethod(it->second.first, {it->first, it->second.second});
    }
}

Library* Library::findLibrary(std::string name)
{
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    for (Library* l = s_libraries; l; l = l->m_next)
    {
        if (l->m_name == name)
            return l;
    }
    return nullptr;
}

LibraryHandle::LibraryHandle(const char* name)
    :   m_library(Library::findLibrary(name))
{
}

LibraryHandle::~LibraryHandle()
{
}

}

