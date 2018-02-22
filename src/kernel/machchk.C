/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/machchk.C $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
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
#include <kernel/machchk.H>
#include <kernel/console.H>
#include <kernel/vmmmgr.H>
#include <sys/mmio.h>
#include <arch/memorymap.H>

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
            uint64_t ibAddrStart = 0;
            for(uint32_t l_groupId=0; l_groupId<4; l_groupId++)
            {
                for(uint32_t l_chipId=0; l_chipId<4; l_chipId++)
                {
                    ibAddrStart = computeMemoryMapOffset( MMIO_IBSCOM_BASE,
                                                          l_groupId,
                                                          l_chipId );
                    if((phys >= ibAddrStart) &&
                       (phys <= ibAddrStart + MMIO_IBSCOM_SIZE - 1))
                    {
                        ueMagicValue = MMIO_IBSCOM_UE_DETECTED;
                        break;
                    }
                }
                if(ueMagicValue == MMIO_IBSCOM_UE_DETECTED)
                {
                    break;
                }
            }
            if(ueMagicValue != MMIO_IBSCOM_UE_DETECTED)
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
