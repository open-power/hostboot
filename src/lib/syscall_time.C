#include <sys/time.h>
#include <sys/syscall.h>

using namespace Systemcalls;

int nanosleep(uint64_t sec, uint64_t nsec)
{
    return (int64_t) _syscall2(TIME_NANOSLEEP, (void*)sec, (void*)nsec);
}
