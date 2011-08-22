#include <sys/misc.h>
#include <sys/syscall.h>
#include <sys/mmio.h>

using namespace Systemcalls;

void shutdown(uint64_t i_status)
{
    mmio_scratch_write(MMIO_SCRATCH_IPLSTEP_CONFIG, 0x1234ABCD);
    _syscall1(MISC_SHUTDOWN, reinterpret_cast<void*>(i_status));
}

ProcessorCoreType cpu_core_type()
{
    return static_cast<ProcessorCoreType>(
            reinterpret_cast<uint64_t>(_syscall0(MISC_CPUCORETYPE)));
}

uint8_t cpu_dd_level()
{
    return reinterpret_cast<uint64_t>(_syscall0(MISC_CPUDDLEVEL));
}

