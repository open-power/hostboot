/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/misc.C $                                           */
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

extern "C"
    void kernel_shutdown(size_t, uint64_t, uint64_t, uint64_t) NO_RETURN;


namespace KernelMisc
{

    uint64_t g_payload_base = 0;
    uint64_t g_payload_entry = 0;

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
                printk("Shutdown Requested. PLID = %ld (due to failure)\n",
                       status);
            }

            register uint64_t scratch_address = 0; // Values from PervSpec
            switch(CpuID::getCpuType())
            {
              case CORE_POWER8_MURANO:
              case CORE_POWER8_VENICE:
              case CORE_UNKNOWN:
                scratch_address = 0x40;
                break;
            }

            asm volatile("mtspr 276, %0\n"
                         "isync\n"
                         "mtspr 277, %1"
                         :: "r" (scratch_address), "r" (status));
        }

        // If the Shutdown was called with a status of GOOD then
        // perform a regular shutdown, otherwise assume we have an
        // error with a status value of the plid and perform a TI.
        if(status == SHUTDOWN_STATUS_GOOD)
        {

            // dump whatever is left in g_tracBinary
            MAGIC_INSTRUCTION(MAGIC_CONTINUOUS_TRACE);

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
                static uint64_t l_lowestPIR = 0xffffffffffffffffull;

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

                kernel_shutdown(CpuManager::getCpuCount(),
                                g_payload_base,
                                g_payload_entry,
                                l_lowestPIR);
            }
        }
        else
        {
            // Got a nonzero status value indicating we had a shutdown request
            // with a PLID and there force need to do  TI.  The plid info was
            // written to the data area earlier in CpuManager::requestShutdown
            terminateExecuteTI();
        }
    }

    void WinkleCore::masterPreWork()
    {
        printk("Winkle threads - ");

        // Save away the current timebase.  All threads are in this object
        // now so they're not going to be using the time for anything else.
        iv_timebase = getTB();
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
        task_t* saveArea = new task_t;
        memset(saveArea, '\0', sizeof(task_t));
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
                /* TODO: RTC 52972 - Change to INITIAL_MEM_SIZE once
                 *                   SLW images are put in the "right" spot.
                 */
                startAddr =
                    reinterpret_cast<uint64_t*>((OUTPUT_PORE_IMG_ADDR +
                                                 MAX_OUTPUT_PORE_IMG_SIZE));
                endAddr =
                    reinterpret_cast<uint64_t*>(8 * MEGABYTE);

            default:
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
};
