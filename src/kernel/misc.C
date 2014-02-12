/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/misc.C $                                           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#include <kernel/vmmmgr.H>              // INITIAL_MEM_SIZE
#include <kernel/memstate.H>
#include <kernel/intmsghandler.H>
#include <kernel/hbdescriptor.H>
#include <kernel/ipc.H>
#include <kernel/timemgr.H>


extern "C"
    void kernel_shutdown(size_t, uint64_t, uint64_t, uint64_t,
                         uint64_t, uint64_t) NO_RETURN;

extern HB_Descriptor kernel_hbDescriptor;

KernelIpc::start_payload_data_area_t KernelIpc::start_payload_data_area;

namespace KernelMisc
{

    uint64_t g_payload_base = 0;
    uint64_t g_payload_entry = 0;
    uint64_t g_payload_data = 0;
    uint64_t g_masterHBInstance = 0xfffffffffffffffful;

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

            // Call to set the Core Scratch Reg 0 with the status
            updateScratchReg(MMIO_SCRATCH_PROGRESS_CODE, status);

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
                uint64_t hrmor_base = KernelIpc::ipc_data_area.hrmor_base;
                uint64_t this_hb_instance =
                    l_lowestPIR/KERNEL_MAX_SUPPORTED_CPUS_PER_NODE;

                uint64_t hrmor_offset =
                    getHRMOR() - (this_hb_instance * hrmor_base);

                uint64_t dest_hrmor =
                    (g_masterHBInstance * hrmor_base) + hrmor_offset;

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
            updateScratchReg(MMIO_SCRATCH_HOSTBOOT_ACTIVE,0);

            terminateExecuteTI();
        }
    }

    void WinkleCore::masterPreWork()
    {
        printk("Winkle threads - ");

        // Save away the current timebase.  All threads are in this object
        // now so they're not going to be using the time for anything else.
        iv_timebase = getTB() + TimeManager::convertSecToTicks(1,0);
    }

    extern "C" void kernel_execute_winkle(task_t* t);

    void WinkleCore::activeMainWork()
    {
        cpu_t* cpu = CpuManager::getCurrentCPU();
        printk("%d", static_cast<int>(cpu->cpu & 0x7));

        // Return current task to run-queue so it isn't lost.
        cpu->scheduler->returnRunnable();
        TaskManager::setCurrentTask(cpu->idle_task);

        // Clear LPCR values that wakes up from winkle.  LPCR[49, 50, 51]
        // Otherwise, there may be an interrupt pending or something that
        // prevents us from fully entering winkle.
        setLPCR(getLPCR() & (~0x0000000000007000));

        // Deactivate CPU from kernel.
        cpu->winkled = true;
        CpuManager::deactivateCPU(cpu);

        // Create kernel save area and store ptr in bottom of kernel stack.
        task_t* saveArea = new task_t();
        saveArea->context.msr_mask = 0xD030; // EE, ME, PR, IR, DR.
        *(reinterpret_cast<task_t**>(cpu->kernel_stack_bottom)) = saveArea;

        // Execute winkle.
        kernel_execute_winkle(saveArea);

        // Re-activate CPU in kernel and re-init VMM SPRs.
        delete saveArea;
        cpu->winkled = false;
        CpuManager::activateCPU(cpu);
        VmmManager::init_slb();

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
        const char * hostboot_string = "hostboot";
        updateScratchReg(MMIO_SCRATCH_HOSTBOOT_ACTIVE,
                         *reinterpret_cast<const uint64_t*>(hostboot_string));

        // Restore caller of cpu_master_winkle().
        iv_caller->state = TASK_STATE_RUNNING;
        TaskManager::setCurrentTask(iv_caller);

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
        setLPCR(getLPCR() & (~0x0000000000007000));

        // Deactivate CPU from kernel.
        cpu->winkled = true;
        CpuManager::deactivateCPU(cpu);

        // Create kernel save area and store ptr in bottom of kernel stack.
        task_t* saveArea = new task_t();
        saveArea->context.msr_mask = 0xD030; // EE, ME, PR, IR, DR.
        *(reinterpret_cast<task_t**>(cpu->kernel_stack_bottom)) = saveArea;

        // Execute winkle.
        kernel_execute_winkle(saveArea);

        // Re-activate CPU in kernel and re-init VMM SPRs.
        delete saveArea;
        cpu->winkled = false;
        CpuManager::activateCPU(cpu);
        VmmManager::init_slb();

        // Wake up all the other threads.
        if(__sync_bool_compare_and_swap(&iv_firstThread, 0, 1))
        {
            for(uint64_t i = 0; i < KERNEL_MAX_SUPPORTED_CPUS_PER_NODE *
                                    KERNEL_MAX_SUPPORTED_NODES; i++)
            {
                cpu_t* slave = CpuManager::getCpu(i);

                if ((NULL != slave) && (slave != cpu))
                {
                    if (slave->winkled)
                    {
                        InterruptMsgHdlr::sendIPI(i);
                    }
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
        const char * hostboot_string = "hostboot";
        updateScratchReg(MMIO_SCRATCH_HOSTBOOT_ACTIVE,
                         *reinterpret_cast<const uint64_t*>(hostboot_string));

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

    int expand_half_cache()
    {
        static bool executed = false;

        if (executed) // Why are we being called a second time?
        {
            return -EFAULT;
        }

        uint64_t startAddr = 512*KILOBYTE;
        uint64_t endAddr = 1*MEGABYTE;

        size_t cache_columns = 0;

        switch(CpuID::getCpuType())
        {
            case CORE_POWER8_MURANO:
            case CORE_POWER8_VENICE:
                cache_columns = 4;
                break;

            default:
                kassert(false);
                break;
        }

        for (size_t i = 0; i < cache_columns; i++)
        {
            size_t offset = i * MEGABYTE;
            populate_cache_lines(
                reinterpret_cast<uint64_t*>(startAddr + offset),
                reinterpret_cast<uint64_t*>(endAddr + offset));

            PageManager::addMemory(startAddr + offset,
                                   (512*KILOBYTE)/PAGESIZE);
        }

        executed = true;

        KernelMemState::setMemScratchReg(KernelMemState::MEM_CONTAINED_L3,
                                         KernelMemState::HALF_CACHE);

        return 0;
    }

    int expand_full_cache()
    {
        static bool executed = false;

        if (executed) // Why are we being called a second time?
        {
            return -EFAULT;
        }

        uint64_t* startAddr = NULL;
        uint64_t* endAddr = NULL;

        switch(CpuID::getCpuType())
        {
            case CORE_POWER8_MURANO:
            case CORE_POWER8_VENICE:
                startAddr = reinterpret_cast<uint64_t*>
                                         ( VmmManager::INITIAL_MEM_SIZE ) ;
                endAddr =
                    reinterpret_cast<uint64_t*>(8 * MEGABYTE);
                break;

            default:
                kassert(false);
                break;
        }

        if (startAddr != NULL)
        {
            populate_cache_lines(startAddr, endAddr);
            size_t pages = (reinterpret_cast<uint64_t>(endAddr) -
                            reinterpret_cast<uint64_t>(startAddr)) / PAGESIZE;

            PageManager::addMemory(reinterpret_cast<uint64_t>(startAddr),
                                   pages);
        }

        executed = true;

        KernelMemState::setMemScratchReg(KernelMemState::MEM_CONTAINED_L3,
                                         KernelMemState::FULL_CACHE);

        return 0;
    }

    void populate_cache_lines(uint64_t* i_start, uint64_t* i_end)
    {
        size_t cache_line_size = getCacheLineWords();

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
          case CORE_POWER8_MURANO:
          case CORE_POWER8_VENICE:
          case CORE_UNKNOWN:
            l_scratch_addr = l_scratch_addr + 0x40;
            break;
        }

        writeScratchReg(l_scratch_addr, data);
    };


};

namespace KernelMemState
{
    void setMemScratchReg(MemLocation i_location,
                         MemSize i_size)
    {
        mem_location l_MemData;

        l_MemData.memMode = i_location;
        l_MemData.reserved = 0;
        l_MemData.memSize = i_size;

        isync();
        kernel_hbDescriptor.kernelMemoryState = l_MemData.Scratch6Data;
        KernelMisc::updateScratchReg(MMIO_SCRATCH_MEMORY_STATE,
                                   l_MemData.Scratch6Data);
        lwsync();

    }

};
