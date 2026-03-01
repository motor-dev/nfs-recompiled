#ifndef LIB_PROCESS_H_
#define LIB_PROCESS_H_

#include <lib/winapp.h>

namespace win32
{

class Process : public GenericResource
{
public:
    Process();
    ~Process();
};

}

#endif

