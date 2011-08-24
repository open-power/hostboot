//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/lib/syscall_misc.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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

