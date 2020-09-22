/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/syscall_misc.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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

#include <arch/memorymap.H>
#include <sys/misc.h>
#include <sys/syscall.h>
#include <sys/task.h>
#include <usr/vmmconst.h>

using namespace Systemcalls;

void shutdown(uint64_t i_status,
              uint64_t i_payload_base,
              uint64_t i_payload_entry,
              uint64_t i_payload_data,
              uint64_t i_masterHBInstance,
              uint32_t i_error_data)
{
    _syscall6(MISC_SHUTDOWN,
                reinterpret_cast<void*>(i_status),
                reinterpret_cast<void*>(i_payload_base),
                reinterpret_cast<void*>(i_payload_entry),
                reinterpret_cast<void*>(i_payload_data),
                reinterpret_cast<void*>(i_masterHBInstance),
                reinterpret_cast<void*>(i_error_data));
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
        case CORE_POWER10:
            threads = 4;
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

uint64_t cpu_hrmor_nodal_base()
{
    return (cpu_spr_value(CPU_SPR_HRMOR) & MEMMAP::NODE_OFFSET_MASK);
}

uint64_t cpu_spr_set(CpuSprNames spr, uint64_t newValue)
{
    return reinterpret_cast<uint64_t>(
        _syscall2( MISC_CPUSPRSET,
                   reinterpret_cast<void*>(spr),
                   reinterpret_cast<void*>(newValue) ));
}

int cpu_master_winkle(bool  i_fusedCores)
{
    task_affinity_pin();
    task_affinity_migrate_to_master();

    int rc = reinterpret_cast<int64_t>(
                _syscall2(MISC_CPUWINKLE,
                          reinterpret_cast<void*>(WINKLE_SCOPE_MASTER),
                          reinterpret_cast<void*>(i_fusedCores) ));


    task_affinity_unpin();

    return rc;
}

int cpu_all_winkle()
{
    task_affinity_pin();
    task_affinity_migrate_to_master();

    int rc = reinterpret_cast<int64_t>(
                _syscall2(MISC_CPUWINKLE,
                          reinterpret_cast<void*>(WINKLE_SCOPE_ALL),
                          reinterpret_cast<void*>(false) ));

    task_affinity_unpin();

    return rc;
}

int cpu_wakeup_core(uint64_t pir,uint64_t i_threads)
{
    return reinterpret_cast<int64_t>(
        _syscall2(MISC_CPUWAKEUPCORE,
                  reinterpret_cast<void*>(pir),
                  reinterpret_cast<void*>(i_threads)));
}


void cpu_crit_assert(uint64_t i_failAddr)
{
   _syscall1(MISC_CRITASSERT, reinterpret_cast<void*>(i_failAddr));
}


void set_mchk_data(uint64_t i_xstopAddr, uint64_t i_xstopData)
{
    _syscall2(MISC_SETMCHKDATA,
              reinterpret_cast<void*>(i_xstopAddr),
              reinterpret_cast<void*>(i_xstopData));
}


void set_topology_mode(uint8_t i_topologyMode)
{
    _syscall1(MISC_SET_TOPOLOGY_MODE,
              reinterpret_cast<void*>(i_topologyMode));
}
