/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/kernel/misc.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#include <kernel/misc.H>
#include <kernel/cpumgr.H>
#include <kernel/cpuid.H>
#include <kernel/console.H>
#include <kernel/barrier.H>

extern "C" void kernel_shutdown(size_t, uint64_t, uint64_t) NO_RETURN;


namespace KernelMisc
{

    uint64_t g_payload_base = 0;
    uint64_t g_payload_entry = 0;

    void shutdown()
    {
        // Update scratch SPR for shutdown status.
        cpu_t* c = CpuManager::getCurrentCPU();
        if (c->master)
        {
            register uint64_t status = CpuManager::getShutdownStatus();
            printk("Shutdown Requested. Status = 0x%lx\n", status);

            register uint64_t scratch_address = 0; // Values from PervSpec
            switch(CpuID::getCpuType())
            {
                case CORE_POWER8_MURANO:
                case CORE_POWER8_VENICE:
                    scratch_address = 0x40;
                    break;

                case CORE_POWER7:
                case CORE_POWER7_PLUS:
                default:
                    scratch_address = 0x20;
                    break;
            }

            asm volatile("mtspr 276, %0\n"
                         "isync\n"
                         "mtspr 277, %1"
                         :: "r" (scratch_address), "r" (status));
        }

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
                printk("No payload... doze'ing all threads.\n");
            }

            // Clear LPCR values that wakes up from doze.  LPCR[49, 50, 51]
            setLPCR(getLPCR() & (~0x0000000000007000));

            while(1)
            {
                doze();
            }
        }
        else
        {
            static Barrier* l_barrier = new Barrier(CpuManager::getCpuCount());

            if (c->master)
            {
                printk("Preparing to enter payload...%lx:%lx\n",
                       g_payload_base, g_payload_entry);
            }

            l_barrier->wait();

            kernel_shutdown(CpuManager::getCpuCount(),
                            g_payload_base,
                            g_payload_entry);
        }
    }
};
