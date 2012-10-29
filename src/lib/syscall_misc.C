/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/syscall_misc.C $                                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#define __HIDDEN_SYSCALL_SHUTDOWN

#include <sys/misc.h>
#include <sys/syscall.h>
#include <sys/task.h>

using namespace Systemcalls;

void shutdown(uint64_t i_status,
              uint64_t i_payload_base,
              uint64_t i_payload_entry)
{
    _syscall3(MISC_SHUTDOWN,
                reinterpret_cast<void*>(i_status),
                reinterpret_cast<void*>(i_payload_base),
                reinterpret_cast<void*>(i_payload_entry));
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

size_t cpu_thread_count()
{
    size_t threads = 0;
    ProcessorCoreType core_type = cpu_core_type();
    switch(core_type)
    {
        case CORE_POWER8_MURANO:
        case CORE_POWER8_VENICE:
            threads = 8;
            break;

        default:
            break;
    }
    return threads;
}

int cpu_start_core(uint64_t pir)
{
    return reinterpret_cast<int64_t>(
        _syscall1(MISC_CPUSTARTCORE, reinterpret_cast<void*>(pir)));
}

uint64_t cpu_spr_value(CpuSprNames spr)
{
    return reinterpret_cast<uint64_t>(
        _syscall1(MISC_CPUSPRVALUE, reinterpret_cast<void*>(spr)));
}

int cpu_master_winkle()
{
    task_affinity_pin();
    task_affinity_migrate_to_master();

    int rc = reinterpret_cast<int64_t>(_syscall0(MISC_CPUWINKLE));

    task_affinity_unpin();

    return rc;
}


void cpu_crit_assert(uint64_t i_failAddr)
{
   _syscall1(MISC_CRITASSERT, reinterpret_cast<void*>(i_failAddr));
}
