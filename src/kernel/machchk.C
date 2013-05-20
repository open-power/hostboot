/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/machchk.C $                                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#include <kernel/machchk.H>
#include <kernel/console.H>
#include <kernel/vmmmgr.H>
#include <sys/mmio.h>

namespace Kernel
{
namespace MachineCheck
{

bool handleLoadUE(task_t* t)
{
    bool handled = false;

    static const uint32_t LDX_INSTR_MASK        = 0xFC0007FE;
    static const uint32_t LDX_INSTR             = 0x7C00002A;
    static const uint32_t LDX_RA_MASK           = 0x001F0000;
    static const uint32_t LDX_RB_MASK           = 0x0000F800;
    static const uint32_t LDX_RT_MASK           = 0x03E00000;

    do
    {
        //Get instruction that caused the SUE
        uint64_t physInstAddr = VmmManager::findKernelAddress(
                reinterpret_cast<uint64_t>(t->context.nip));
        uint32_t* instruction = reinterpret_cast<uint32_t*>(physInstAddr);

        if((*instruction & LDX_INSTR_MASK) != LDX_INSTR)
        {
            //Not an LDX instruction, unhandled exception
            printk("MachineCheck::handleUE: Instruction 0x%.8x not handled.\n",
                   *instruction);
            break;
        }

        uint64_t ueMagicValue = 0x0;

        // If task is tolerating UEs, replace with "Dead Data".
        if (t->tolerate_ue)
        {
            ueMagicValue = MM_UE_MAGIC_VALUE;
        }
        // Otherwise, check for specific MMIO addresses.
        else
        {
            //Compute the accessed address
            uint32_t rA = (*instruction & LDX_RA_MASK) >> 16;
            uint32_t rB = (*instruction & LDX_RB_MASK) >> 11;

            uint64_t vaddr = 0;
            if(rA != 0)
            {
                vaddr = t->context.gprs[rA] +
                t->context.gprs[rB];
            }
            else
            {
                vaddr = t->context.gprs[rB];
            }

            uint64_t phys = VmmManager::findPhysicalAddress(vaddr);

            //Check if address is in IBSCOM MMIO Range.
            if((phys >= MMIO_IBSCOM_START) &&
               (phys <= MMIO_IBSCOM_END))
            {
                ueMagicValue = MMIO_IBSCOM_UE_DETECTED;
            }
            else
            {
                printk("MachineCheck::handleUE: Unrecognized address %lx\n",
                       phys);
                break;
            }
        }

        // Write pattern into result register.
        uint32_t rT = (*instruction & LDX_RT_MASK) >> 21;
        t->context.gprs[rT] = ueMagicValue;

        // Advance to next instruction.
        uint32_t* nextInst = reinterpret_cast<uint32_t*>(t->context.nip);
        nextInst++;
        t->context.nip = reinterpret_cast<void*>(nextInst);

        // Successfully handled.
        handled = true;

    } while (false);

    return handled;
}

bool handleSLB(task_t* t)
{
    // Reinitialize the SLB.
    VmmManager::init_slb();
    return true;
}


}
}
