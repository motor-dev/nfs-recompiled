#ifndef LIB_MUTEX_H_
#define LIB_MUTEX_H_

#include <lib/winapp.h>
#include <string>

namespace win32
{

class Mutex : public GenericResource
{
public:
    Mutex(const char* name);
    ~Mutex();

    void lock();
    void unlock();

    x86::reg32 getResourceIndex() const { return m_resourceIndex; }

private:
    SDL_Mutex*  m_mutex;
    std::string m_name;
    x86::reg32  m_owner;
    x86::reg32  m_count;
};

}

#endif

