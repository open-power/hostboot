/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/machchk.C $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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
#include <arch/ppc.H>
#include <arch/magic.H>

namespace Kernel
{
namespace MachineCheck
{

//Keep track of the MMIO address that we can use to force a checkstop
static uint64_t* g_xstopRegPtr = nullptr;

//Keep track of the data to write into the xstop reg
static uint64_t g_xstopRegValue = 0;

/** Constants used to describe upper physical address range for MMIO
 *  Upper address range is inclusively between
 *  0x0006000000000000 and 0x0007F00000000000
 */
static const uint64_t MMIO_UPPER_RANGE_NIBBLE_MASK = 0xFFFF000000000000;
static const uint64_t MMIO_UPPER_RANGE_NIBBLE_MIN  = 0x0006000000000000;
static const uint64_t MMIO_UPPER_RANGE_NIBBLE_MAX  = 0x0007000000000000;


/** Constants used to define OCMB MMIO physical address ranges
 * Per chip offset and range:
 *  - OCMB physical memory starts at 3TB + 16GB
 *  - size per chip: 16 OCMBs/chip * (2GB CONFIG + 2GB MMIO) per OCMB = 64GB
*/
static const uint64_t MMIO_OCMB_RANGE_MASK  = 0x00000FFFFFFFFFFF;
static const uint64_t MMIO_OCMB_BASE_START  = 0x0000030400000000; // 3TB + 16GB
static const uint64_t MMIO_OCMB_BASE_END    = 0x0000031FFFFFFFFF; // Base + 64GB


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

            // Make sure address within MMIO range
            if ( ((phys & MMIO_UPPER_RANGE_NIBBLE_MASK) == MMIO_UPPER_RANGE_NIBBLE_MIN) ||
                 ((phys & MMIO_UPPER_RANGE_NIBBLE_MASK) == MMIO_UPPER_RANGE_NIBBLE_MAX) )
            {
                // Within MMIO address range, so now remove unique chip address part
                // Mask the physical address per chip MMIO range
                uint64_t physPerChipRange = phys & MMIO_OCMB_RANGE_MASK;

                // Check if phys memory is in the OCMB MMIO range
                if ( (physPerChipRange >= MMIO_OCMB_BASE_START) &&
                     (physPerChipRange <= MMIO_OCMB_BASE_END) )
                {
                    printk("MachineCheck::handleLoadUE: MMIO_OCMB_UE_DETECTED for %lx\n",
                        phys);
                    ueMagicValue = MMIO_OCMB_UE_DETECTED;
                }
                else
                {
                    printk("MachineCheck::handleLoadUE: Unrecognized address outside MMIO_OCMB range %lx\n",
                           phys);
                    break;
                }
            }
            else
            {
                printk("MachineCheck::handleLoadUE: Unrecognized address %lx\n",
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


/**
 *  @brief Tells the kernel how to force a checkstop for unrecoverable
 *         machine checks
 */
void setCheckstopData(uint64_t i_xstopAddr, uint64_t i_xstopData)
{
    g_xstopRegPtr = reinterpret_cast<uint64_t*>(i_xstopAddr
                                                |VmmManager::FORCE_PHYS_ADDR);
    g_xstopRegValue = i_xstopData;
    printk( "Arm MchChk Xstop: %p=%.16lX\n", g_xstopRegPtr, g_xstopRegValue );

    // Now that the machine check handler can do the xscom we
    //  can set MSR[ME]=1 to enable the regular machine check
    //  handling
    uint64_t l_msr = getMSR();
    l_msr |= 0x0000000000001000; //set bit 51
    setMSR(l_msr);
}

/**
 *  @brief Force a checkstop if we know how in order to get better
 *         error isolation for cache/memory UEs
 */
void forceCheckstop()
{
    if( g_xstopRegPtr != nullptr )
    {
        printk( "Forcing a xstop with %p = %.16lX\n",
                g_xstopRegPtr, g_xstopRegValue );

        // Per PowerPC ISA :
        // Store Doubleword Caching Inhibited Indexed
        // stdcix      RS,RA,RB
        // let the effective address (EA) be the sum(RA|0)+ (RB).
        // (RS) is stored into the doubleword in storage addressed by EA
        asm volatile("stdcix %0,0,%1"
                     :: "r" (g_xstopRegValue) , "r" (reinterpret_cast <uint64_t>(g_xstopRegPtr)));
    }
    else
    {
        printk( "Unable to force checkstop, No xstop reg set\n" );
    }
}

}
}
