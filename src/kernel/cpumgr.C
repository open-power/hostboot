/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/cpumgr.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2021                        */
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
#include <assert.h>
#include <kernel/cpumgr.H>
#include <kernel/task.H>
#include <kernel/cpu.H>
#include <kernel/scheduler.H>
#include <kernel/taskmgr.H>
#include <kernel/pagemgr.H>
#include <kernel/console.H>
#include <util/singleton.H>
#include <arch/ppc.H>
#include <kernel/timemgr.H>
#include <sys/sync.h>
#include <kernel/cpuid.H>
#include <kernel/ptmgr.H>
#include <kernel/heapmgr.H>
#include <kernel/intmsghandler.H>
#include <errno.h>
#include <kernel/deferred.H>
#include <kernel/misc.H>
#include <kernel/terminate.H>
#include <kernel/hbterminatetypes.H>
#include <kernel/kernel_reasoncodes.H>
#include <kernel/cpuid.H>
#include <kernel/doorbell.H>
#include <arch/pvrformat.H>
#include <arch/magic.H>

cpu_t* CpuManager::cv_cpus[KERNEL_MAX_SUPPORTED_CPUS_PER_INST] = {nullptr};
bool CpuManager::cv_shutdown_requested = false;
uint64_t CpuManager::cv_shutdown_status = 0;
size_t CpuManager::cv_cpuSeq = 0;
uint8_t CpuManager::cv_forcedMemPeriodic = 0;
InteractiveDebug CpuManager::cv_interactive_debug;

const uint64_t WAKEUP_MSR_VALUE  = 0x9000000000001000;
const uint64_t WAKEUP_LPCR_VALUE = 0x000000000000F00A;
const uint64_t WAKEUP_RPR_VALUE  = 0x0001032021223F;
const uint64_t MSR_SMF_MASK      = 0x0000000000400000;

CpuManager::CpuManager() : iv_lastStartTimebase(0)
{
    memset(&cv_interactive_debug, '\0', sizeof(cv_interactive_debug));
}

cpu_t* CpuManager::getMasterCPU()
{
    for (int i = 0; i < KERNEL_MAX_SUPPORTED_CPUS_PER_INST; i++)
    {
        if ((nullptr != cv_cpus[i]) && (cv_cpus[i]->master))
        {
            return cv_cpus[i];
        }
    }

    return nullptr;
}

void CpuManager::init()
{
    // For the initial boot we only want to set up CPU objects for the threads
    // on this core.  Otherwise we waste memory with kernel / idle task stacks.
    //
    // As long as the CPU object pointer is NULL, the start.S code won't
    // enter the kernel, so we skip initializing all the other CPUs for now.

    // Determine number of threads on this core.
    size_t threads = getThreadCount();

    // Create CPU objects starting at the thread-0 for this core.
    size_t baseCpu = getCpuId() & ~(threads-1);
    for (size_t i = 0; i < threads; i++)
    {
        Singleton<CpuManager>::instance().startCPU(i + baseCpu);
    }
}

void CpuManager::init_slave_smp(cpu_t* cpu)
{
    Singleton<CpuManager>::instance().startSlaveCPU(cpu);
}

void CpuManager::requestShutdown(uint64_t i_status, uint32_t i_error_data)
{
    cv_shutdown_status = i_status;
    __sync_synchronize();
    cv_shutdown_requested = true;

    if (i_status != SHUTDOWN_STATUS_GOOD)
    {
        termWriteStatus(TI_SHUTDOWN, i_status, 0, i_error_data);
        printk("TI initiated on all threads (shutdown)\n");
    }

    class ExecuteShutdown : public DeferredWork
    {
        public:
            void masterPreWork()
            {
                // The stats can be retrieved from global variables as needed.
                // This can be uncommented for debug if desired
                #ifdef __MEMSTATS__
                if(c->master)
                    HeapManager::stats();
                #endif
            }

            void activeMainWork()
            {
                KernelMisc::shutdown();
            }

            void nonactiveMainWork()
            {
                // Something wasn't synchronized correctly if we got to here.
                // Should not have CPUs coming online while trying to execute
                // a shutdown.
                kassert(false);
            }
    };

    DeferredQueue::insert(new ExecuteShutdown());
}

void CpuManager::startCPU(ssize_t i)
{
    // This printk shows up a lot and can cause important debug information to be lost later in the IPL if it's longer
    // than absolutely necessary.
    printk("sCPU:%ld\n",i);

    // Save away the current timebase for TB synchronization.
    iv_lastStartTimebase = getTB();

    bool currentCPU = false;
    if (i < 0)
    {
        i = getCpuId();
        currentCPU = true;
    }
    else if (getCpuId() == (uint64_t)i)
    {
        currentCPU = true;
    }

    size_t cpuId = i;

    // Initialize CPU structure.
    if (nullptr == cv_cpus[cpuId])
    {
        printkd("Start pir 0x%lx...", i);
        cpu_t* cpu = cv_cpus[cpuId] = new cpu_t();

        // Initialize CPU.
        cpu->cpu = i;
        if (currentCPU)
        {
            cpu->master = true;
        }
        else
        {
            cpu->master = false;
        }
        cpu->scheduler = &Singleton<Scheduler>::instance();
        cpu->scheduler_extra = NULL;

        const size_t kernel_page_count = 4;
        const size_t kernel_page_offset = kernel_page_count * PAGESIZE -
                                          8 * sizeof(uint64_t);
        cpu->kernel_stack_bottom = PageManager::allocatePage(kernel_page_count);
        cpu->kernel_stack = reinterpret_cast<void*>(
            reinterpret_cast<uintptr_t>(cpu->kernel_stack_bottom) +
            kernel_page_offset);

        cpu->xscom_mutex = NULL;

        if (NULL == cpu->xscom_mutex)
        {
            cpu->xscom_mutex = new mutex_t;
            mutex_init(cpu->xscom_mutex);
        }

        // Create idle task.
        cpu->idle_task = TaskManager::createIdleTask();
        cpu->idle_task->cpu = cpu;
        cpu->periodic_count = 0;
        cpu->cpu_restore_tb = 0;

        // Call TimeManager setup for a CPU.
        TimeManager::init_cpu(cpu);

        printkd("done\n");
    }

    if (currentCPU)
    {
        setDEC(TimeManager::getTimeSliceCount());
        activateCPU(getCpu(i));
    }
    return;
}

void CpuManager::startSlaveCPU(cpu_t* cpu)
{
    // Activate CPU.
    activateCPU(cpu);

    // Sync timebase with master.
    while(getTB() < iv_lastStartTimebase)
    {
        class SyncTimebase : public DeferredWork
        {
            public:
                void masterPreWork()
                {
                    iv_timebase = getTB();
                }

                void activeMainWork()
                {
                    if (getTB() < iv_timebase)
                    {
                        setTB(iv_timebase);
                    }
                }

            private:
                uint64_t iv_timebase;
        };

        SyncTimebase* deferred = new SyncTimebase();
        DeferredQueue::insert(deferred, true /* only if empty */);
        DeferredQueue::execute();
    }

    // Update decrementer.
    setDEC(TimeManager::getTimeSliceCount());

    return;
}

void CpuManager::activateCPU(cpu_t * i_cpu)
{
    // Set active.
    i_cpu->active = true;

    // Update sequence ID.
    do
    {
        uint64_t old_seq = cv_cpuSeq;
        i_cpu->cpu_start_seqid = old_seq + 1 + (1ull << 32);

        if (__sync_bool_compare_and_swap(&cv_cpuSeq, old_seq,
                                         i_cpu->cpu_start_seqid))
        {
            break;
        }
    } while (1);
    i_cpu->cpu_start_seqid >>= 32;

    // Verify / set SPRs.
    uint64_t msr = getMSR();
    msr |= 0x1000; // MSR[ME] is not saved on initial wakeup, but we set on
                   // entering userspace, so ignore this bit in assert.
    msr &= ~MSR_SMF_MASK; //Don't check SMF as it is variable
                          //ie keep HB code agnostic
    kassert(WAKEUP_MSR_VALUE == msr);
    setLPCR(WAKEUP_LPCR_VALUE);
    setRPR(WAKEUP_RPR_VALUE);
    setPSSCR(PSSCR_STOP2_VALUE);
}

void CpuManager::deactivateCPU(cpu_t * i_cpu)
{
    // Set inactive.
    i_cpu->active = false;

    // Update sequence ID.
    do
    {
        uint64_t old_seq = cv_cpuSeq;
        uint64_t new_seq = old_seq - 1 + (1ull << 32);

        if (__sync_bool_compare_and_swap(&cv_cpuSeq, old_seq, new_seq))
        {
            break;
        }
    } while(1);
}

void CpuManager::executePeriodics(cpu_t * i_cpu)
{
    if(i_cpu->master)
    {
        if (cv_interactive_debug.isReady())
        {
            cv_interactive_debug.startDebugTask();
        }

        bool forceMemoryPeriodic = __sync_fetch_and_and(&cv_forcedMemPeriodic,
                                                        0);

        ++(i_cpu->periodic_count);
        if((0 == (i_cpu->periodic_count % CPU_PERIODIC_CHECK_MEMORY)) ||
           (forceMemoryPeriodic))
        {
            uint64_t pcntAvail = PageManager::queryAvail();
            if((pcntAvail < PageManager::LOWMEM_NORM_LIMIT) ||
               (forceMemoryPeriodic))
            {
                VmmManager::flushPageTable();
                ++(i_cpu->periodic_count);   // prevent another flush below
                if(pcntAvail < PageManager::LOWMEM_CRIT_LIMIT)
                {
                    VmmManager::castOutPages(VmmManager::CRITICAL);
                }
                else
                {
                    VmmManager::castOutPages(VmmManager::NORMAL);
                }
            }
        }
        if(0 == (i_cpu->periodic_count % CPU_PERIODIC_FLUSH_PAGETABLE))
        {
            VmmManager::flushPageTable();
        }
        if(((0 == (i_cpu->periodic_count % CPU_PERIODIC_DEFRAG))
            && PageManager::isSmallMemEnv()) // only defrag if in small mem env
           || (forceMemoryPeriodic))
        {
            class MemoryCoalesce : public DeferredWork
            {
                public:
                    void masterPreWork()
                    {
                        setThreadPriorityVeryHigh();

                        HeapManager::coalesce();
                        PageManager::coalesce();

                        setThreadPriorityHigh();
                    }
            };

            DeferredQueue::insert(new MemoryCoalesce());
        }
    }

    DeferredQueue::execute();

}

void CpuManager::startCore(uint64_t pir,uint64_t i_threads)
{
    size_t threads = getThreadCount();
    pir = pir & ~(threads-1);

    if (pir >= KERNEL_MAX_SUPPORTED_CPUS_PER_INST)
    {
        TASK_SETRTN(TaskManager::getCurrentTask(), -ENXIO);
        return;
    }

    for(size_t i = 0; i < threads; i++)
    {
        // Only start the threads we were told to start
        if( i_threads & (0x8000000000000000 >> i) )
        {
            Singleton<CpuManager>::instance().startCPU(pir + i);
        }
    }
    __sync_synchronize();

    //Send a message to userspace that a core with this base pir is being added
    // userspace will know which threads on the core to expect already
    InterruptMsgHdlr::addCpuCore(pir);

    for(size_t i = 0; i < threads; i++)
    {
        // Only wakeup the threads we were told to wakeup
        if( i_threads & (0x8000000000000000 >> i) )
        {
            // This printk shows up a lot and can cause important debug information to be lost later in the IPL if it's
            // longer than absolutely necessary.
            printk("DB:%lu\n", pir + i);
            //Initiate the Doorbell for this core/pir
            send_doorbell_wakeup(pir + i);
        }
    }

    return;
};

void CpuManager::wakeupCore(uint64_t pir,uint64_t i_threads)
{
    size_t threads = getThreadCount();
    pir = pir & ~(threads-1);

    if (pir >= KERNEL_MAX_SUPPORTED_CPUS_PER_INST)
    {
        TASK_SETRTN(TaskManager::getCurrentTask(), -ENXIO);
        return;
    }

    //Send a message to userspace that a core with this base pir is being added
    // userspace will know which threads on the core to expect already
    InterruptMsgHdlr::addCpuCore(pir);

    // Physically wakeup the threads with doorbells
    //  Assumption is that startCore has already run so all
    //  internal structures are setup
    for(size_t i = 0; i < threads; i++)
    {
        // Only wakeup the threads we were told to wakeup
        if( i_threads & (0x8000000000000000 >> i) )
        {
            printk("DB2:%lu\n", pir + i);
            //Initiate the Doorbell for this core/pir
            doorbell_send(pir + i);
        }
    }

    return;
};

size_t CpuManager::getThreadCount()
{
    size_t threads = 0;
    switch (CpuID::getCpuType())
    {
        case CORE_POWER10:
            threads = 4;
            break;

        case CORE_UNKNOWN:
        default:
            PVR_t l_pvr( getPVR() );
            printk("cputype=%d, pvr=%.8X\n",
                   CpuID::getCpuType(), l_pvr.word);
            kassert(false);
            break;
    }

    return threads;
}

void CpuManager::forceMemoryPeriodic()
{
    cv_forcedMemPeriodic = 1;
}


void CpuManager::critAssert(uint64_t i_failAddr)
{
    /*@
     * @errortype
     * @moduleid     KERNEL::MOD_KERNEL_INVALID
     * @reasoncode   KERNEL::RC_SHUTDOWN
     * @userdata1    Failing address
     * @userdata2    <unused>
     * @devdesc      Kernel encountered an unhandled exception.
     * @custdesc     Boot firmware has crashed with an internal
     *               error.
     */
    /* create SRC amd call terminate immediate*/
    termWriteSRC(TI_CRIT_ASSERT,KERNEL::RC_SHUTDOWN, i_failAddr);

    class ExecuteCritAssert : public DeferredWork
    {
      public:
        void masterPreWork()
        {
            // print status to the console.
            printk("TI initiated on all threads (crit_assert)\n");
            MAGIC_INSTRUCTION(MAGIC_BREAK_ON_ERROR);
        }

        void activeMainWork()
        {
            // Call the function to perform the TI
            terminateExecuteTI();
        }

        void nonactiveMainWork()
        {
            // Something wasn't synchronized correctly if we got to here.
            // Should not have CPUs coming online while trying to execute
            // a shutdown.
            terminateExecuteTI();
        }
    };

    DeferredQueue::insert(new ExecuteCritAssert());

    // Force executeion of the deferred queue.
    DeferredQueue::execute();

}
