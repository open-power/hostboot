/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/syscall_mmio.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2014              */
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
#include <sys/syscall.h>
#include <sys/mmio.h>
#include <assert.h>
#include <kernel/task.H>
#include <kernel/cpu.H>
#include <kernel/cpuid.H>

using namespace Systemcalls;

void* mmio_dev_map(void *ra, uint64_t i_devDataSize)
{
    return _syscall3(DEV_MAP, ra, (void*)i_devDataSize, (void*)0);
}

int mmio_dev_unmap(void *ea)
{
    return (int64_t) _syscall1(DEV_UNMAP, ea);
}

uint64_t mmio_hmer_read()
{
    return (uint64_t) _syscall0(MMIO_HMER_READ);
}

void mmio_hmer_write(uint64_t value)
{
    _syscall1(MMIO_HMER_WRITE, (void*)value);
}

/** @brief Determine the base register address of the mmio_scratch_base.
 *
 *  Since this code is called from within the kernel as part of static
 *  construction of g_mmio_scratch_base, we can use internal kernel
 *  functions here (and not system calls) to determine the CPU type.
 *
 *  @return Base address (SPRC value) of the scratch registers.
 */
static uint64_t mmio_scratch_base()
{
    ProcessorCoreType cpuType = CpuID::getCpuType();
    switch (cpuType)
    {
        case CORE_POWER8_MURANO:
        case CORE_POWER8_VENICE:
        case CORE_POWER8_NAPLES:
        case CORE_UNKNOWN:
        default:
            return 0x40;
    }
}
    /** Global cache of the scratch register SPRC base address. */
uint64_t g_mmio_scratch_base = mmio_scratch_base();

uint64_t mmio_scratch_read(uint64_t which)
{
    return (uint64_t) _syscall1(MMIO_SCRATCH_READ,
                                (void*)(which + g_mmio_scratch_base));
}

void mmio_scratch_write(uint64_t which, uint64_t value)
{
    _syscall2(MMIO_SCRATCH_WRITE,
              (void*)(which + g_mmio_scratch_base), (void*)value);
}

mutex_t * mmio_xscom_mutex()
{
    // Get task structure.
    register task_t* task;
    asm volatile("mr %0, 13" : "=r"(task));

    // Ensure task is pinned.
    crit_assert(task->affinity_pinned);

    // Return mutex from cpu structure.
    return task->cpu->xscom_mutex;
}
