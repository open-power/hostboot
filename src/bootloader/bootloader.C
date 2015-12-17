/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/bootloader.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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

#define __BOOT_LOADER_C

#include <stdint.h>
#include <bootloader/bootloader.H>
#include <bootloader/bootloader_trace.H>
#include <bootloader/bl_pnorAccess.H>

#include <lpc_const.H>
#include <pnor_utils.H>

#include <ecc.H>

#include <stdlib.h>

extern uint64_t kernel_other_thread_spinlock;
extern PNOR::SectionData_t bootloader_hbbSection;

namespace Bootloader{
    /**
     * @brief Pointer to bootloader scratch space
     *
     * Pointer to location in main storage which bootloader uses as
     * scratch space
     */
    uint8_t *g_blScratchSpace;

    /** Apply Secure Signature Validation function.
     *
     *  @note Currently just a stub.
     */
    void applySecureSignatureValidation()
    {
        // (just an empty stub function for now) @TODO RTC:143902
    }


    /** Bootloader main function to work with and start HBB.
     *
     * @return 0.
     *
     * @note Should branch to HBB and never return.
     */
    extern "C"
    int main()
    {
        // Initialization
        bootloader_trace_index = 0;
        BOOTLOADER_TRACE(BTLDR_TRC_MAIN_START);
        g_blScratchSpace = reinterpret_cast<uint8_t*>(HBBL_SCRATCH_SPACE_ADDR);

        // Set variables needed for getting location of HB base code
        // @TODO RTC:138268 Support multiple sides of PNOR in bootloader
        uint64_t l_pnorStart = LPC::LPC_PHYS_BASE + LPC::LPCHC_FW_SPACE
                             + PNOR::LPC_SFC_MMIO_OFFSET;
        uint32_t l_errCode = PNOR::NO_ERROR;
        uint8_t l_tocUsed = 0;

        // Get location of HB base code in PNOR from TOC
        // @TODO RTC:138268 Support multiple sides of PNOR in bootloader
        bl_pnorAccess::getHBBSection(l_pnorStart,
                                     bootloader_hbbSection,
                                     l_errCode,
                                     l_tocUsed);
        BOOTLOADER_TRACE(BTLDR_TRC_MAIN_GETHBBSECTION_RTN );

        if(PNOR::NO_ERROR == l_errCode)
        {
            // get hbbFlashOffset
            uint64_t l_hbbFlashOffset = bootloader_hbbSection.flashAddr;
            // get hbbLength without size of ECC data
            uint32_t l_hbbLength = bootloader_hbbSection.size;
            // get hbbEcc
            bool l_hbbEcc =
                ( bootloader_hbbSection.integrity == FFS_INTEG_ECC_PROTECT);
            // set hbbSbeHeaderSize @TODO RTC:137480 subject to future removal
            uint64_t l_hbbSbeHeaderSize = (l_hbbEcc)
                                        ? (0x18 * LENGTH_W_ECC) / LENGTH_WO_ECC
                                        : 0x18;

            // Copy HB base code from PNOR to working location
            handleMMIO(l_pnorStart + l_hbbFlashOffset + l_hbbSbeHeaderSize,
                       (l_hbbEcc) ? HBB_ECC_WORKING_ADDR : HBB_WORKING_ADDR,
                       (l_hbbEcc) ? (l_hbbLength * LENGTH_W_ECC)/LENGTH_WO_ECC
                                  : l_hbbLength,
                   BYTESIZE);
            BOOTLOADER_TRACE(BTLDR_TRC_MAIN_WORKING_HANDLEMMIO_RTN);

            PNOR::ECC::eccStatus rc = PNOR::ECC::CLEAN;
            if(l_hbbEcc)
            {
                // Remove ECC from HB base code at in working location and
                // store result in new working location
                rc = PNOR::ECC::removeECC(
                    reinterpret_cast<uint8_t*>(HBB_ECC_WORKING_ADDR |
                                               IGNORE_HRMOR_MASK),
                    reinterpret_cast<uint8_t*>(HBB_WORKING_ADDR |
                                               IGNORE_HRMOR_MASK),
                    l_hbbLength);
                if (rc != PNOR::ECC::CLEAN)
                {
                    BOOTLOADER_TRACE(BTLDR_TRC_MAIN_REMOVEECC_RTN);
                }
                else if (rc != PNOR::ECC::CORRECTED)
                {
                    BOOTLOADER_TRACE(BTLDR_TRC_MAIN_REMOVEECC_CORRECTED);
                }
            }

            if (rc != PNOR::ECC::UNCORRECTABLE)
            {
                // Apply secure signature validation @TODO RTC:143902
                applySecureSignatureValidation();
                BOOTLOADER_TRACE(BTLDR_TRC_MAIN_APPLYSECSIGVAL_RTN);

                // Copy HBB image into address where it executes
                uint64_t *l_src_addr =
                   reinterpret_cast<uint64_t*>(HBB_WORKING_ADDR |
                                               IGNORE_HRMOR_MASK);
                uint64_t *l_dest_addr =
                   reinterpret_cast<uint64_t*>(HBB_RUNNING_ADDR |
                                               IGNORE_HRMOR_MASK);
                for(uint32_t i = 0;
                    i < l_hbbLength / sizeof(uint64_t);
                    i++)
                {
                    l_dest_addr[i] = l_src_addr[i];
                }
                BOOTLOADER_TRACE(BTLDR_TRC_MAIN_COPY_HBB_DONE);

                // Start executing HBB
                enterHBB(HBB_HRMOR, HBB_RUNNING_OFFSET);
            }
            else
            {
                BOOTLOADER_TRACE_W_BRK(BTLDR_TRC_MAIN_REMOVEECC_FAIL);
            }
        }
        else
        {
            BOOTLOADER_TRACE_W_BRK(BTLDR_TRC_MAIN_GETHBBSECTION_FAIL);
        }

        return 0;
    }


    /** Handle MMIO to copy code/data from location to another.
     *
     * @param[in] i_srcAddr - The source location.
     * @param[in] i_destAddr - The destination location.
     * @param[in] i_size - The size of the code/data.
     * @param[in] i_ld_st_size - The size of each load/store operation.
     *
     * @return void.
     */
    void handleMMIO(uint64_t i_srcAddr,
                    uint64_t i_destAddr,
                    uint32_t i_size,
                    MMIOLoadStoreSizes i_ld_st_size)
    {
        BOOTLOADER_TRACE(BTLDR_TRC_HANDLEMMIO_START);

        // Set base addresses, Ignore HRMOR setting
        uint64_t l_srcAddr_base = i_srcAddr | IGNORE_HRMOR_MASK;
        uint64_t l_destAddr_base = i_destAddr | IGNORE_HRMOR_MASK;

        uint32_t l_targetGPR = 0;

        for(uint32_t i = 0;
            i < i_size;
            i += i_ld_st_size)
        {
            // Set addresses
            uint64_t l_srcAddr = l_srcAddr_base + i;
            uint64_t l_destAddr = l_destAddr_base + i;

            if(i_ld_st_size == BYTESIZE)
            {
                // Cache-inhibited load byte from hypervisor state.
                // lbzcix      BOP1,Ref_G0,BOP2
                asm volatile("lbzcix %0, 0, %1"
                             : "=r" (l_targetGPR)    // output, %0
                             : "r" (l_srcAddr)       // input,  %1
                             : );                    // no impacts

                // Cache-inhibited store byte.
                // stbcix      BOP1,Ref_G0,BOP2
                asm volatile("stbcix %0,0,%1"
                             :: "r" (l_targetGPR) , "r" (l_destAddr));
            }
            else if(i_ld_st_size == WORDSIZE)
            {
                // Cache-inhibited load word from hypervisor state.
                // lwzcix      BOP1,Ref_G0,BOP2
                asm volatile("lwzcix %0, 0, %1"
                             : "=r" (l_targetGPR)    // output, %0
                             : "r" (l_srcAddr)       // input,  %1
                             : );                    // no impacts

                // Cache-inhibited store word.
                // stwcix      BOP1,Ref_G0,BOP2
                asm volatile("stwcix %0,0,%1"
                             :: "r" (l_targetGPR) , "r" (l_destAddr));
            }
            else
            {
                // Cache-inhibited load double word from hypervisor state.
                // ldcix       BOP1,Ref_G0,BOP2
                asm volatile("ldcix %0, 0, %1"
                             : "=r" (l_targetGPR)    // output, %0
                             : "r" (l_srcAddr)       // input,  %1
                             : );                    // no impacts

                // Cache-inhibited store double word.
                // stdcix      BOP1,Ref_G0,BOP2
                asm volatile("stdcix %0,0,%1"
                             :: "r" (l_targetGPR) , "r" (l_destAddr));
            }
        }
    }
} // end namespace Bootloader
