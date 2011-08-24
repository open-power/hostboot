//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/misc.C $
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
#include <kernel/misc.H>
#include <kernel/cpumgr.H>
#include <kernel/cpuid.H>
#include <kernel/console.H>

namespace KernelMisc
{
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
                case CORE_POWER8_SALERNO:
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

        while(1)
        {
            doze();
        }
    }
};
