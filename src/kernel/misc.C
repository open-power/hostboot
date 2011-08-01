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
