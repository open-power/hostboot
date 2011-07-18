#include <sys/misc.h>
#include <sys/syscall.h>

using namespace Systemcalls;

void shutdown(uint64_t i_status)
{
    _syscall1(MISC_SHUTDOWN, reinterpret_cast<void*>(i_status));
}

