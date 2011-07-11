#include <sys/time.h>
#include <sys/syscall.h>

using namespace Systemcalls;

void nanosleep(uint64_t sec, uint64_t nsec)
{
    _syscall2(TIME_NANOSLEEP, (void*)sec, (void*)nsec);
}
