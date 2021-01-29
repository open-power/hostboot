/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/misc.C $                                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
#include <kernel/misc.H>
#include <kernel/cpumgr.H>
#include <kernel/cpuid.H>
#include <kernel/console.H>
#include <kernel/barrier.H>
#include <kernel/scheduler.H>
#include <assert.h>
#include <kernel/terminate.H>
#include <kernel/hbterminatetypes.H>
#include <sys/mm.h>
#include <errno.h>
#include <kernel/pagemgr.H>
#include <kernel/memstate.H>
#include <kernel/intmsghandler.H>
#include <kernel/hbdescriptor.H>
#include <kernel/ipc.H>
#include <kernel/timemgr.H>
#include <util/singleton.H>
#include <kernel/doorbell.H>
#include <arch/pvrformat.H>
#include <arch/magic.H>

extern "C"
    void kernel_shutdown(size_t, uint64_t, uint64_t, uint64_t,
                         uint64_t, uint64_t) NO_RETURN;

extern HB_Descriptor kernel_hbDescriptor;

KernelIpc::start_payload_data_area_t KernelIpc::start_payload_data_area;

namespace KernelMisc
{

    uint64_t g_payload_base  = 0;
    uint64_t g_payload_entry = 0;
    uint64_t g_payload_data  = 0;
    uint64_t g_payload_attn_area_addr = 0x0ul;
    uint64_t g_masterHBInstance = 0xfffffffffffffffful;
    uint32_t g_error_data    = 0;

    void shutdown()
    {
        // Update scratch SPR for shutdown status.
        cpu_t* c = CpuManager::getCurrentCPU();
        register uint64_t status = CpuManager::getShutdownStatus();

        if (c->master)
        {
            // If good shutdown requested print out status
            if(status == SHUTDOWN_STATUS_GOOD)
            {
                printk("Shutdown Requested. Status = 0x%lx\n", status);
            }
            // Shtudown was called due to error.. print out plid of the
            // errorlog that caused the failure
            else
            {
                printk("Shutdown Requested. PLID = %lx (due to failure)\n",
                       status);
            }
        }

        // If the Shutdown was called with a status of GOOD then
        // perform a regular shutdown, otherwise assume we have an
        // error with a status value of the plid and perform a TI.
        if(status == SHUTDOWN_STATUS_GOOD)
        {

            // See magic_instruction_callback() in
            // src/build/debug/simics-debug-framework.py
            // for exactly how this is handled.
            MAGIC_INSTRUCTION(MAGIC_SHUTDOWN);

            // Check for a valid payload address.
            if ((0 == g_payload_base) && (0 == g_payload_entry))
            {
                // We really don't know what we're suppose to do now, so just
                // sleep all the processors.

                if (c->master)
                {
                    printk("No payload... nap'ing all threads.\n");
                    // Let Simics know that we booted successfully
                    MAGIC_INST_PRINT_ISTEP(0xFF,0xFF);
                }

                // Clear LPCR values that wakes up from nap.  LPCR[49, 50, 51]
                setLPCR(getLPCR() & (~0x0000000000007000));

                while(1)
                {
                    nap();
                }
            }
            else
            {
                static Barrier* l_barrier = new Barrier(CpuManager::getCpuCount());
                static uint64_t l_lowestPIR = 0xfffffffffffffffful;

                if (c->master)
                {
                    printk("Preparing to enter payload...%lx:%lx\n",
                           g_payload_base, g_payload_entry);
                }

                // Need to identify the thread with the lowest PIR because it needs
                // to be the last one to jump to PHYP.
                uint64_t l_pir = getPIR();
                do
                {
                    uint64_t currentPIR = l_lowestPIR;
                    if (l_pir > currentPIR)
                    {
                        break;
                    }

                    if (__sync_bool_compare_and_swap(&l_lowestPIR,
                                                     currentPIR, l_pir))
                    {
                        break;
                    }

                } while(1);

                l_barrier->wait();

                // only set this to valid PIR if local master
                // otherwise leave as default;
                uint64_t local_master_pir = 0xfffffffffffffffful;

                // Find the start_payload_data_area on the master node
                // Use IPC address of master node to find the necessary
                // Address
                uint64_t master_node_IPC =
                  reinterpret_cast<uint64_t>(
                  KernelIpc::ipc_data_area.remote_ipc_data_addr[
                                                    g_masterHBInstance]);

                uint64_t l_localAddrIPC =
                  reinterpret_cast<uint64_t>(& KernelIpc::ipc_data_area);

                uint64_t dest_hrmor = master_node_IPC - l_localAddrIPC;

                uint64_t start_payload_data_area_address =
                    reinterpret_cast<uint64_t>
                    (&KernelIpc::start_payload_data_area);

                start_payload_data_area_address += dest_hrmor;
                start_payload_data_area_address |= 0x8000000000000000ul;

                KernelIpc::start_payload_data_area_t * p_spda =
                    reinterpret_cast<KernelIpc::start_payload_data_area_t*>
                    (start_payload_data_area_address);

                if (c->master)
                {
                    local_master_pir = getPIR();

                    printkd("Local master pir %lx, start_data_area %lx\n",
                           local_master_pir, start_payload_data_area_address);
                    // Reset the memory state register so that the dump tools
                    // don't attempt to dump all of memory once payload runs.
                    KernelMemState::setMemScratchReg(
                            KernelMemState::MEM_CONTAINED_NR,
                            KernelMemState::NO_MEM);

                    // add this nodes cpu_count to the system cpu_count
                    __sync_add_and_fetch(&(p_spda->cpu_count),
                                         CpuManager::getCpuCount());

                    // set lowest system PIR based on local lowest PIR
                    do
                    {
                        uint64_t currentPIR = p_spda->lowest_PIR;
                        if (l_lowestPIR > currentPIR)
                        {
                            break;
                        }

                        if (__sync_bool_compare_and_swap(&p_spda->lowest_PIR,
                                                         currentPIR, l_lowestPIR))
                        {
                            break;
                        }

                    } while(1);

                }

                // Update the Core scratch reg 0 with the TI location of the
                // payload before passing to payload.
                updateScratchReg(MMIO_SCRATCH_TI_AREA_LOCATION,
                                 g_payload_attn_area_addr);

                kernel_shutdown(p_spda->node_count,
                                g_payload_base,
                                g_payload_entry,
                                g_payload_data,
                                local_master_pir,  //master PIR if local master
                                start_payload_data_area_address);
            }
        }
        else
        {
            // Got a nonzero status value indicating we had a shutdown request
            // with a PLID and there force need to do  TI.  The plid info was
            // written to the data area earlier in CpuManager::requestShutdown

            // First indicate to the FSP that we're done by clearing out the
            // "hostboot_done" register.  We need to do this since this is the
            // power off path.
            setHbScratchStatus(HB_SHUTDOWN);

            terminateExecuteTI();
        }
    }

    void setHbScratchStatus(enum HbRunning i_status)
    {
        if(i_status == HB_RUNNING)
        {
            const char * hostboot_string = "hostboot";
            updateScratchReg(MMIO_SCRATCH_HOSTBOOT_ACTIVE,
                        *reinterpret_cast<const uint64_t*>(hostboot_string));
        }
        else if(i_status == HB_STARTED_PAYLOAD)
        {
            updateScratchReg(MMIO_SCRATCH_HOSTBOOT_ACTIVE,0);
        }
        else if(i_status == HB_BOOTLOADER)
        {
            const char * hostboot_string = "bootload";
            updateScratchReg(MMIO_SCRATCH_HOSTBOOT_ACTIVE,
                        *reinterpret_cast<const uint64_t*>(hostboot_string));
        }
        else if(i_status == HB_START_BASE_IMAGE)
        {
            const char * hostboot_string = "starthbb";
            updateScratchReg(MMIO_SCRATCH_HOSTBOOT_ACTIVE,
                        *reinterpret_cast<const uint64_t*>(hostboot_string));
        }
        else if(i_status == HB_SHUTDOWN)
        {
            const char * hostboot_string = "shutdown";
            updateScratchReg(MMIO_SCRATCH_HOSTBOOT_ACTIVE,
                        *reinterpret_cast<const uint64_t*>(hostboot_string));
        }
    }

    void WinkleCore::masterPreWork()
    {
        printk("Winkle threads - ");

        // Save away the current timebase.  All threads are in this object
        // now so they're not going to be using the time for anything else.
        iv_timebase = getTB() + TimeManager::convertSecToTicks(1,0);

        if (true == iv_fusedCores)
        {
            uint64_t  l_numThreads = CpuManager::getThreadCount();
            cpu_t *   l_cput = CpuManager::getCurrentCPU();

            // creates cpu_t structure in advance for new threads
            // (should be next set of cpuIds past master core)
            for ( uint64_t  l_threadNum = l_numThreads;
                  (l_threadNum < (l_numThreads *2));
                   l_threadNum++ )
            {
                Singleton<CpuManager>::instance().startCPU(l_cput->cpu +
                                                           l_threadNum);
            }
        } // end if fused core mode
    }

    extern "C" void kernel_execute_stop(task_t* t);

    void WinkleCore::activeMainWork()
    {
        cpu_t* cpu = CpuManager::getCurrentCPU();
        printk("%d.", static_cast<int>(cpu->cpu));

        // Return current task to run-queue so it isn't lost.
        cpu->scheduler->returnRunnable();
        TaskManager::setCurrentTask(cpu->idle_task);

        // Clear LPCR values that wakes up from winkle.  LPCR[49, 50, 51]
        // Otherwise, there may be an interrupt pending or something that
        // prevents us from fully entering winkle.
        // Turn on LPCR[17] to enable Hypervisor External Interrupts
        setLPCR((getLPCR() & (~0x0000000000007000)) | 0x0000400000000000) ;

        // Deactivate CPU from kernel.
        cpu->winkled = true;
        CpuManager::deactivateCPU(cpu);

        // Create kernel save area and store ptr in bottom of kernel stack.
        task_t* saveArea = new task_t();
        saveArea->context.msr_mask = 0x100000000000D030; //HV,EE,ME,PR,IR,DR.
        *(reinterpret_cast<task_t**>(cpu->kernel_stack_bottom)) = saveArea;

        // Set register to indicate we want a 'stop 15' to occur (state loss)
        uint64_t l_psscr_saved = getPSSCR();
        setPSSCR( 0x00000000003F00FF );

        // Execute winkle.
        kernel_execute_stop(saveArea);

        // Re-activate CPU in kernel and re-init VMM SPRs.
        setPSSCR(l_psscr_saved);
        delete saveArea;
        cpu->winkled = false;
        CpuManager::activateCPU(cpu);
        VmmManager::init_slb();

        if(cpu->master)
        {
            // NOTE: The cpu_t structures for theads 1:3 were created
            //       during init (CpuManager::init).
            // Start with a base PIR of thread 0 + 1 (Thread 1) as thread 0
            // doesn't need to be woken up as it is already running.
            uint64_t l_pir = getPIR() + 1;
            for(size_t i = 0; i < CpuManager::getThreadCount()-1; i++)
            {
                // NOTE: The deferred work container verifies master core
                // threads 1-3 wake up so a direct doorbell can be sent. For
                // threads on other cores send_doorbell_wakeup() is used.
                send_doorbell_restore_tb(l_pir + i, iv_timebase);
            }

            //At this point there will usually be more threads than actual
            //work -- tweak the timeslice math so each threads gets a longer
            //time to work
            TimeManager::setTimeSlicePerSec(TimeManager::LARGE_THREAD_TIMESLICE_PER_SEC);
        }

        // Select a new task if not the master CPU.  Master CPU will resume
        // the code that called cpu_master_winkle().
        if (!cpu->master)
        {
            cpu->scheduler->setNextRunnable();
        }
    }

    void WinkleCore::masterPostWork()
    {
        printk(" - Awake!\n");

        // Restore timebase.
        setTB(iv_timebase);

        // Restore memory state register.
        updateScratchReg(MMIO_SCRATCH_MEMORY_STATE,
                         kernel_hbDescriptor.kernelMemoryState);

        // Set scratch register to indicate Hostboot is [still] active.
        setHbScratchStatus(HB_RUNNING);

        // Restore caller of cpu_master_winkle().
        iv_caller->state = TASK_STATE_RUNNING;
        TaskManager::setCurrentTask(iv_caller);

        //Issue sbe master workaround
        InterruptMsgHdlr::issueSbeMboxWA();
    }

    void WinkleCore::nonactiveMainWork()
    {
        // Race condition that should not occur...
        //
        // Attempted to winkle the master and another thread came online in
        // the process.
        kassert(false);
    }

    void WinkleAll::masterPreWork()
    {
        printk("Winkle all - ");

        // Save away the current timebase.  All threads are in this object
        // now so they're not going to be using the time for anything else.
        iv_timebase = getTB() + TimeManager::convertSecToTicks(1,0);
    }

    void WinkleAll::activeMainWork()
    {
        cpu_t* cpu = CpuManager::getCurrentCPU();

        // Return current task to run-queue so it isn't lost.
        cpu->scheduler->returnRunnable();
        TaskManager::setCurrentTask(cpu->idle_task);

        // Clear LPCR values that wakes up from winkle.  LPCR[49, 50, 51]
        // Otherwise, there may be an interrupt pending or something that
        // prevents us from fully entering winkle.
        // Turn on LPCR[17] to enable Hypervisor External Interrupts
        setLPCR((getLPCR() & (~0x0000000000007000)) | 0x0000400000000000) ;

        // Deactivate CPU from kernel.
        cpu->winkled = true;
        CpuManager::deactivateCPU(cpu);

        // Create kernel save area and store ptr in bottom of kernel stack.
        task_t* saveArea = new task_t();
        saveArea->context.msr_mask = 0x100000000000D030; //HV,EE,ME,PR,IR,DR.
        *(reinterpret_cast<task_t**>(cpu->kernel_stack_bottom)) = saveArea;

        // Set register to indicate we want a 'stop 15' to ocur (state loss)
        uint64_t l_psscr_saved = getPSSCR();
        setPSSCR( 0x00000000003F00FF );
        // Execute winkle.
        kernel_execute_stop(saveArea);

        // Re-activate CPU in kernel and re-init VMM SPRs.
        setPSSCR(l_psscr_saved);
        delete saveArea;
        cpu->winkled = false;
        CpuManager::activateCPU(cpu);
        VmmManager::init_slb();

        // Wake up all the other threads.
        if(__sync_bool_compare_and_swap(&iv_firstThread, 0, 1))
        {
            for(uint64_t i = 0; i < KERNEL_MAX_SUPPORTED_CPUS_PER_INST; i++)
            {
                cpu_t* slave = CpuManager::getCpu(i);
                if ((NULL != slave) && (slave != cpu))
                {
                    uint64_t l_pir = slave->cpu;
                    printkd("Sending dbell to wakeup cpu:%d", (int)l_pir);
                    doorbell_send(l_pir);
                }
            }
        };

        // Sync timebase.
        if (getTB() < iv_timebase)
        {
            setTB(iv_timebase);
        }

        // Select a new task if not the master CPU.  Master CPU will resume
        // the code that called cpu_master_winkle().
        if (!cpu->master)
        {
            cpu->scheduler->setNextRunnable();
        }
    }

    void WinkleAll::masterPostWork()
    {
        printk("Awake!\n");

        // Restore memory state register.
        updateScratchReg(MMIO_SCRATCH_MEMORY_STATE,
                         kernel_hbDescriptor.kernelMemoryState);

        // Set scratch register to indicate Hostboot is [still] active.
        setHbScratchStatus(HB_RUNNING);

        // Restore caller of cpu_all_winkle().
        iv_caller->state = TASK_STATE_RUNNING;
        TaskManager::setCurrentTask(iv_caller);
    }

    void WinkleAll::nonactiveMainWork()
    {
        // Race condition that should not occur...
        //
        // Attempted to winkle the threads and another thread came online in
        // the process.
        kassert(false);
    }

    void populate_cache_lines(uint64_t* i_start, uint64_t* i_end)
    {
        size_t cache_line_size = getCacheLineWords();

        // Assert start/end address is divisible by Cache Line Words
        kassert(reinterpret_cast<uint64_t>(i_start)%cache_line_size == 0);
        kassert(reinterpret_cast<uint64_t>(i_end)%cache_line_size == 0);
        while(i_start != i_end)
        {
            dcbz(i_start);
            i_start += cache_line_size;
        }
    }

    void updateScratchReg(MMIO_Scratch_Register scratch_addr,
                          uint64_t data)
    {

        uint64_t l_scratch_addr = static_cast<uint64_t>(scratch_addr);

        switch(CpuID::getCpuType())
        {
          case CORE_POWER10:
          case CORE_UNKNOWN:
          default:
              // See EX07.EC.CC.PCC0.COMMON.SPR_COMMON.SCOMC in scomdef for
              // info on this offset - MODE_CX_SCOMC: 0000xxx = SCRATCH xx SPR
              // It's 0 for P9 so just pass through scratch reg offset
              break;
        }
        writeScratchReg(l_scratch_addr, data);
    };

    /**
     *  @brief Collect the backtrace for the given task and print an
     */
    void printkBacktrace(task_t* i_task)
    {
        uint64_t* l_frame = nullptr;
        uint32_t l_tid = 0;
        bool l_kernelSpace = true;
        if( i_task == nullptr ) //user-space
        {
            l_tid = task_gettid();
            l_kernelSpace = false;
            printk("U:Backtrace for %d\n  ", l_tid);
            l_frame = static_cast<uint64_t*>(framePointer());
        }
        else //kernel-space
        {
            l_frame = reinterpret_cast<uint64_t*>( i_task->context.gprs[1] );
            l_tid = i_task->tid;
            printk("K:Backtrace for %d (lr = 0x%lx):\n  ", l_tid, i_task->context.lr );
        }

        printkd("frame=%p\n",l_frame);isync();
        while (l_frame != NULL)
        {
            printkd("\nf=%p\n",l_frame); isync();
            if( l_kernelSpace )
            {
                uint64_t* frame_p = reinterpret_cast<uint64_t*>
                  (VmmManager::findPhysicalAddress( reinterpret_cast<uint64_t>
                                                    (l_frame) ));
                printkd("frame_p=%p\n",frame_p); isync();
                l_frame = frame_p;
            }
            if( (0 != *l_frame) && (0 != l_frame[2]) )
            {
                printk( "<-0x%lX", l_frame[2] );
            }

            l_frame = reinterpret_cast<uint64_t*>(*l_frame);
        }

        if (i_task)
        {
            printk("\n  GPRs for %d:\n", l_tid);

            for (int i = 0; i < 16; ++i)
            {
                printk("    r%-2d = 0x%016lx    r%-2d = 0x%016lx\n",
                       i,
                       i_task->context.gprs[i],
                       i + 16,
                       i_task->context.gprs[i + 16]);
            }
        }

        printk("\n");
    }
};

namespace KernelMemState
{
    void setMemScratchReg(MemLocation i_location,
                          size_t i_sizeMb)
    {
        MemState_t l_MemData;

        l_MemData.location = i_location;
        l_MemData.hrmor = getHRMOR();
        l_MemData.size = i_sizeMb;
        kassert( i_sizeMb < KernelMemState::MAX_MEMORY );

        isync();
        kernel_hbDescriptor.kernelMemoryState = l_MemData.fullData;
        KernelMisc::updateScratchReg(MMIO_SCRATCH_MEMORY_STATE,
                                     l_MemData.fullData);
        lwsync();

    }
};

const char* ProcessorCoreTypeStrings[]
{
    "POWER10",
    "Unknown"
};
