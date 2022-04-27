/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/bl_pnorAccess.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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

/**
 * @file bl_pnorAccess.C
 *
 * @brief Bootloader PNOR access functions to find/read PNOR TOC and HBB
 */

#include <bootloader/bl_pnorAccess.H>
#include <bootloader/bootloader_trace.H>
#include <bootloader/hbblreasoncodes.H>
#include <util/singleton.H>
#include <util/align.H>
#include <bootloader/bootloader.H>
#include <lpc_const.H>
#ifdef PNORUTILSTEST_H
#define BOOTLOADER_TRACE(args) TRACFCOMP(g_trac_pnor,"##args")
#define BOOTLOADER_TRACE_W_BRK(args) TRACFCOMP(g_trac_pnor,"##args")
#endif

/**
* @brief Takes in a buffer containing a ToC, as well as a base address
         Returns out a boolean whether or not this toc was valid
         also returns a SectionData_t struct if the toc was valid
*/
void bl_pnorAccess::readTOC(uint8_t i_tocBuffer[PNOR::TOC_SIZE],
                            uint32_t& o_errCode,
                            PNOR::SectionData_t * o_TOC,
                            uint64_t& o_pnorStart,
                            uint64_t i_pnorEnd)
{
    do
    {
        o_errCode = PNOR::NO_ERROR;
        o_pnorStart = NULL;

        ffs_hdr* l_ffs_hdr = NULL;
        //zero out the section data for each section
        PNOR::initializeSections(o_TOC);

        BOOTLOADER_TRACE(BTLDR_TRC_PA_READTOC_ZEROSECTION_RTN);

        // Create a convenient way to access the ffs_hdr struct
        l_ffs_hdr = reinterpret_cast<ffs_hdr*>(i_tocBuffer);

        BOOTLOADER_TRACE(BTLDR_TRC_PA_READTOC_CHECKNULLBUFFER_RTN);

        //Do a checksum on the header
        if(PNOR::pnor_ffs_checksum(l_ffs_hdr, FFS_HDR_SIZE) != 0)
        {
            o_errCode |= PNOR::CHECKSUM_ERR;
        }

        if(o_errCode != PNOR::NO_ERROR)
        {
            BOOTLOADER_TRACE_W_BRK(BTLDR_TRC_PA_READTOC_HDRCHECKSUM_ERR);
            // Set TI information but caller decides to TI or not
            /*@
             * @errortype
             * @moduleid     Bootloader::MOD_PNORACC_READTOC
             * @reasoncode   Bootloader::RC_HDR_CHECKSUM_ERR
             * @userdata1[0:15]   TI_WITH_SRC
             * @userdata1[16:31]  TI_BOOTLOADER
             * @userdata1[32:63]  Failing address = 0
             * @userdata2[0:31]   Pointer to FFS header
             * @userdata2[32:63]  Error code
             * @devdesc      FFS header checksum error
             * @custdesc     A problem occurred while running processor
             *               boot code.
             */
            bl_terminate(Bootloader::MOD_PNORACC_READTOC,
                         Bootloader::RC_HDR_CHECKSUM_ERR,
                         reinterpret_cast<uint64_t>(l_ffs_hdr),
                         o_errCode,
                         false);
            break;
        }

        BOOTLOADER_TRACE(BTLDR_TRC_PA_READTOC_HDRCHECKSUM_RTN);

        //Check out the header to make sure its all valid
        PNOR::checkHeader(l_ffs_hdr, o_errCode);

        if(o_errCode != PNOR::NO_ERROR)
        {
            BOOTLOADER_TRACE_W_BRK(BTLDR_TRC_PA_READTOC_CHECKHEADER_ERR);
            // Set TI information but caller decides to TI or not
            /*@
             * @errortype
             * @moduleid     Bootloader::MOD_PNORACC_READTOC
             * @reasoncode   Bootloader::RC_CHECK_HEADER_ERR
             * @userdata1[0:15]   TI_WITH_SRC
             * @userdata1[16:31]  TI_BOOTLOADER
             * @userdata1[32:63]  Failing address = 0
             * @userdata2[0:31]   Pointer to FFS header
             * @userdata2[32:63]  Error code
             * @devdesc      Check FFS header error(s)
             * @custdesc     A problem occurred while running processor
             *               boot code.
             */
            bl_terminate(Bootloader::MOD_PNORACC_READTOC,
                         Bootloader::RC_CHECK_HEADER_ERR,
                         reinterpret_cast<uint64_t>(l_ffs_hdr),
                         o_errCode,
                         false);
            break;
        }

        BOOTLOADER_TRACE(BTLDR_TRC_PA_READTOC_CHECKHEADER_RTN);

        //Subtract the size of the pnor from the end address to find the start
        o_pnorStart = i_pnorEnd -
                        (l_ffs_hdr->block_size * l_ffs_hdr->block_count) + 1;

        //if an error is found with an entry we use this variable to hold
        //the value of the entry. That way we can record which entry is causing
        //an issue.
        ffs_entry* l_err_entry = NULL;

        //parse through the entries and check for any errors
        PNOR::parseEntries(l_ffs_hdr, o_errCode, o_TOC, l_err_entry);

        if(o_errCode != PNOR::NO_ERROR)
        {
            BOOTLOADER_TRACE_W_BRK(BTLDR_TRC_PA_READTOC_PARSEENTRIES_ERR);
            // Set TI information but caller decides to TI or not
            /*@
             * @errortype
             * @moduleid     Bootloader::MOD_PNORACC_READTOC
             * @reasoncode   Bootloader::RC_PARSE_ENTRIES_ERR
             * @userdata1[0:15]   TI_WITH_SRC
             * @userdata1[16:31]  TI_BOOTLOADER
             * @userdata1[32:63]  Failing address = 0
             * @userdata2[0:31]   Pointer to FFS entry with error
             * @userdata2[32:63]  Error code
             * @devdesc      Parse FFS entries error
             * @custdesc     A problem occurred while running processor
             *               boot code.
             */
            bl_terminate(Bootloader::MOD_PNORACC_READTOC,
                         Bootloader::RC_PARSE_ENTRIES_ERR,
                         reinterpret_cast<uint64_t>(l_err_entry),
                         o_errCode,
                         false);
            break;
        }

        BOOTLOADER_TRACE(BTLDR_TRC_PA_READTOC_PARSEENTRIES_RTN);
    } while(0);
}

void bl_pnorAccess::findTOC(uint64_t i_lpcBar, PNOR::SectionData_t * o_TOC,
                            uint32_t& o_errCode, uint64_t& o_pnorStart)
{
    //pnorEnd is the end of flash, which is base of lpc, plus
    //the offset of the FW space, plus the TOP memory address in FW space
    uint64_t i_pnorEnd = i_lpcBar + LPC::LPCHC_FW_SPACE + PNOR::LPC_TOP_OF_FLASH_OFFSET;

    uint8_t *l_tocBuffer = g_blScratchSpace;

    //The first TOC is 1 TOC size + 1 page back from the end of the flash (+ 1)
    uint64_t l_mmioAddr = i_pnorEnd - PNOR::TOC_OFFSET_FROM_TOP_OF_FLASH;
#ifdef CONFIG_VPO_COMPILE
    l_mmioAddr -= 0x3C00000; // In VPO, the size of the PNOR is smaller (4MB),
                             // so we need to make an adjustment to find the
                             // TOC at the end of the smaller PNOR correctly.
                             // 0x3C00000 is the difference in PNOR sizes
#endif
    l_mmioAddr = ALIGN_PAGE_DOWN(l_mmioAddr);

    do
    {
        //@TODO RTC:138268 Set up multiple side of PNOR for bootloader
        o_errCode = 0;

        uint64_t l_mmioStatusAddr = LPC::LPCHC_ERR_SPACE + i_lpcBar;

        // First do a dummy LPC access (if an LPC error condition exists,
        // an access can be necessary to get the error indicated in the
        // status register. This read will force the error condition to
        // properly be shown in the LPC error status reg
        Bootloader::handleMMIO(l_mmioAddr,
                    reinterpret_cast<uint64_t>(l_tocBuffer),
                    Bootloader::WORDSIZE,
                    Bootloader::WORDSIZE,
                    Bootloader::READ);

        // Now Read OPB Master Status Reg offset (LPC Addr 0xC0010000)
        Bootloader::handleMMIO(l_mmioStatusAddr,
                               reinterpret_cast<uint64_t>(l_tocBuffer),
                               Bootloader::WORDSIZE,
                               Bootloader::WORDSIZE,
                               Bootloader::READ);

        uint32_t *l_val = reinterpret_cast<uint32_t *>(l_tocBuffer);

        // Check Error Condition
        if (*l_val & LPC::OPB_ERROR_MASK)
        {
            // New priority is to force a specific checkstop so that PRD can
            // handle the callout
            Bootloader::bl_forceCheckstopOnLpcErrors();

            // Shouldn't return back from forcing a checkstop, but if so, just
            // follow the previous error path here

            //PNOR error found
            o_errCode = PNOR::LPC_ERR;
            BOOTLOADER_TRACE(BTLDR_TRC_PA_FINDTOC_TOC1_LPC_ERR);
            /*@
             * @errortype
             * @moduleid     Bootloader::MOD_PNORACC_FINDTOC
             * @reasoncode   Bootloader::RC_LPC_ERR
             * @userdata1[0:15]   TI_WITH_SRC
             * @userdata1[16:31]  TI_BOOTLOADER
             * @userdata1[32:63]  Failing address = 0
             * @userdata2[0:31]   LPC error/status
             * @userdata2[32:63]  Error code
             * @devdesc      LPC error detected.
             * @custdesc     A problem occurred while running processor
             *               boot code.
             */
            bl_terminate(Bootloader::MOD_PNORACC_FINDTOC,
                         Bootloader::RC_LPC_ERR,
                         (*l_val),
                         o_errCode,
                         true);
            break;
        }

        //Copy Table of Contents from PNOR flash to a local buffer
        Bootloader::handleMMIO(l_mmioAddr,
                    reinterpret_cast<uint64_t>(l_tocBuffer),
                    (PNOR::TOC_SIZE),
                    Bootloader::WORDSIZE,
                    Bootloader::READ);

        BOOTLOADER_TRACE(BTLDR_TRC_PA_FINDTOC_TOC1_HANDLEMMIO_RTN);

        readTOC(l_tocBuffer, o_errCode, o_TOC, o_pnorStart, i_pnorEnd);

        if(o_errCode == PNOR::NO_ERROR)
        {
            BOOTLOADER_TRACE(BTLDR_TRC_PA_FINDTOC_TOC1_READTOC_RTN);
            break;
        }
        else
        {
            if(o_pnorStart != NULL)
            {
                // Use PNOR start address for next MMIO
                BOOTLOADER_TRACE(BTLDR_TRC_PA_FINDTOC_USE_PNOR_START);
                l_mmioAddr = o_pnorStart;

                // Reset saved trace index
                g_blData->bl_trace_index_saved = BOOTLOADER_TRACE_SIZE;
            }
            else
            {
                // Check if a trace index is not saved
                if(g_blData->bl_trace_index_saved >= BOOTLOADER_TRACE_SIZE)
                {
                    // Save trace index for future passes through loop
                    g_blData->bl_trace_index_saved = g_blData->bl_trace_index;

                    // Save this PNOR MMIO address
                    g_blData->bl_first_pnor_mmio = l_mmioAddr;
                }
                else // A trace index was saved
                {
                    // Replace trace index, reuse trace entries for this loop
                    g_blData->bl_trace_index = g_blData->bl_trace_index_saved;
                }

                // Adjust to new location in PNOR flash for next MMIO
                BOOTLOADER_TRACE(BTLDR_TRC_PA_FINDTOC_ADJUST_PNOR_ADDR);
                l_mmioAddr -= PAGESIZE;

                // Increment loop counter
                g_blData->bl_pnor_loop_count++;
            }

            // Check that address is still in FW space
            if(l_mmioAddr <
                (g_blData->blToHbData.lpcBAR + LPC::LPCHC_FW_SPACE))
            {
                BOOTLOADER_TRACE_W_BRK(BTLDR_TRC_PA_FINDTOC_READTOC_ERR);
                /*@
                 * @errortype
                 * @moduleid     Bootloader::MOD_PNORACC_FINDTOC
                 * @reasoncode   Bootloader::RC_TOC_NOT_FOUND_ERR
                 * @userdata1[0:15]   TI_WITH_SRC
                 * @userdata1[16:31]  TI_BOOTLOADER
                 * @userdata1[32:63]  Failing address = 0
                 * @userdata2    MMIO Address
                 * @devdesc      TOC not found
                 * @custdesc     A problem occurred while running processor
                 *               boot code.
                 */
                bl_terminate(Bootloader::MOD_PNORACC_FINDTOC,
                             Bootloader::RC_TOC_NOT_FOUND_ERR,
                             // Extract the l_mmioAddr address among 2 - 32 bits
                             (l_mmioAddr >> 32),
                             l_mmioAddr,
                             true);
                break;
            }
        }
    }while(1);
}

/**
 * @brief Get the hostboot base image
 */
void bl_pnorAccess::getHBBSection(uint64_t i_lpcBar,
                                  PNOR::SectionData_t& o_hbbSection,
                                  uint32_t& o_errCode,
                                  uint64_t& o_pnorStart)
{
    BOOTLOADER_TRACE(BTLDR_TRC_PA_GETHBBSECTION_START);
    do
    {

        o_errCode = 0;
        PNOR::SectionData_t l_TOC[PNOR::NUM_SECTIONS+1];

        findTOC(i_lpcBar, l_TOC, o_errCode, o_pnorStart);

        if(o_errCode != PNOR::NO_ERROR)
        {
            // Note findTOC should have TI'd so won't get here
            BOOTLOADER_TRACE_W_BRK(BTLDR_TRC_PA_GETHBBSECTION_FINDTOC_ERR);
            break;
        }
        o_hbbSection = l_TOC[PNOR::HB_BASE_CODE];

        if(o_hbbSection.flashAddr == PNOR::INVALID_FLASH_OFFSET)
        {
            o_errCode = PNOR::NO_HBB_SECTION;
            BOOTLOADER_TRACE_W_BRK(BTLDR_TRC_PA_GETHBBSECTION_FINDTOC_NOHBB);
            /*@
             * @errortype
             * @moduleid     Bootloader::MOD_PNORACC_GETHBBSECT
             * @reasoncode   Bootloader::RC_NO_HBB_IN_TOC
             * @userdata1[0:15]   TI_WITH_SRC
             * @userdata1[16:31]  TI_BOOTLOADER
             * @userdata1[32:63]  Failing address = 0
             * @userdata2[0:31]   Pointer to HBB Section data
             * @userdata2[32:63]  HBB Section flash address
             * @devdesc      Invalid flash address for HBB
             * @custdesc     A problem occurred while running processor
             *               boot code.
             */
            bl_terminate(Bootloader::MOD_PNORACC_GETHBBSECT,
                         Bootloader::RC_NO_HBB_IN_TOC,
                         reinterpret_cast<uint64_t>(&o_hbbSection),
                         o_hbbSection.flashAddr);
            break;
        }
    } while(0);
    BOOTLOADER_TRACE(BTLDR_TRC_PA_GETHBBSECTION_FINDTOC_RTN);
}

