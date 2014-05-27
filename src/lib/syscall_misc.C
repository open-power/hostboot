/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/syscall_misc.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#define __HIDDEN_SYSCALL_SHUTDOWN

#include <sys/misc.h>
#include <sys/syscall.h>
#include <sys/task.h>

using namespace Systemcalls;

void shutdown(uint64_t i_status,
              uint64_t i_payload_base,
              uint64_t i_payload_entry,
              uint64_t i_payload_data,
              uint64_t i_masterHBInstance)
{
    _syscall5(MISC_SHUTDOWN,
                reinterpret_cast<void*>(i_status),
                reinterpret_cast<void*>(i_payload_base),
                reinterpret_cast<void*>(i_payload_entry),
                reinterpret_cast<void*>(i_payload_data),
                reinterpret_cast<void*>(i_masterHBInstance));
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
        case CORE_POWER8_NAPLES:
            threads = 8;
            break;

        default:
            break;
    }
    return threads;
}

int cpu_start_core(uint64_t pir,uint64_t i_threads)
{
    return reinterpret_cast<int64_t>(
        _syscall2(MISC_CPUSTARTCORE,
                  reinterpret_cast<void*>(pir),
                  reinterpret_cast<void*>(i_threads)));
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

    int rc = reinterpret_cast<int64_t>(
                _syscall1(MISC_CPUWINKLE,
                          reinterpret_cast<void*>(WINKLE_SCOPE_MASTER)));

    task_affinity_unpin();

    return rc;
}

int cpu_all_winkle()
{
    task_affinity_pin();
    task_affinity_migrate_to_master();

    int rc = reinterpret_cast<int64_t>(
                _syscall1(MISC_CPUWINKLE,
                          reinterpret_cast<void*>(WINKLE_SCOPE_ALL)));

    task_affinity_unpin();

    return rc;
}


void cpu_crit_assert(uint64_t i_failAddr)
{
   _syscall1(MISC_CRITASSERT, reinterpret_cast<void*>(i_failAddr));
}
