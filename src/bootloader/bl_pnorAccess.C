/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/bl_pnorAccess.C $                              */
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

#include <bootloader/bl_pnorAccess.H>
#include <bootloader/bootloader_trace.H>
#include <bootloader/hbblreasoncodes.H>
#include <util/singleton.H>
#include <bootloader/bootloader.H>
#ifdef PNORUTILSTEST_H
#define BOOTLOADER_TRACE(args) TRACFCOMP(g_trac_pnor,"##args")
#define BOOTLOADER_TRACE_W_BRK(args) TRACFCOMP(g_trac_pnor,"##args")
#endif


extern const char* cv_EYECATCHER[];
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

        //make sure that the buffer is not null
        PNOR::checkForNullBuffer(i_tocBuffer, o_errCode, l_ffs_hdr);

        if(o_errCode != PNOR::NO_ERROR)
        {
            BOOTLOADER_TRACE_W_BRK(BTLDR_TRC_PA_READTOC_CHKNULLBUFFER_NULL);
            // Set TI information but caller decides to TI or not
            /*@
             * @errortype
             * @moduleid     MOD_PNORACC_READTOC
             * @reasoncode   RC_CHK_NULL_BUFFER
             * @userdata1[0:15]   TI_WITH_SRC
             * @userdata1[16:31]  TI_BOOTLOADER
             * @userdata1[32:63]  Failing address = 0
             * @userdata2[0:31]   Pointer to TOC buffer
             * @userdata2[32:63]  Error code
             * @devdesc      Invalid TOC buffer pointer
             * @custdesc     A problem occurred while running processor
             *               boot code.
             */
            bl_terminate(Bootloader::MOD_PNORACC_READTOC,
                         Bootloader::RC_CHK_NULL_BUFFER,
                         reinterpret_cast<uint64_t>(i_tocBuffer),
                         o_errCode,
                         false);
            break;
        }

        BOOTLOADER_TRACE(BTLDR_TRC_PA_READTOC_CHECKNULLBUFFER_RTN);

        //Subtract the size of the pnor from the end address to find the start
        o_pnorStart = i_pnorEnd -
                        (l_ffs_hdr->block_size * l_ffs_hdr->block_count) + 1;

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
             * @moduleid     MOD_PNORACC_READTOC
             * @reasoncode   RC_HDR_CHECKSUM_ERR
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
             * @moduleid     MOD_PNORACC_READTOC
             * @reasoncode   RC_CHECK_HEADER_ERR
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
             * @moduleid     MOD_PNORACC_READTOC
             * @reasoncode   RC_PARSE_ENTRIES_ERR
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

void bl_pnorAccess::findTOC(uint64_t i_pnorEnd, PNOR::SectionData_t * o_TOC,
                            uint32_t& o_errCode,  uint8_t& o_tocUsed,
                            uint64_t& o_pnorStart)
{
    uint8_t *l_tocBuffer = Bootloader::g_blScratchSpace;
    do
    {
        //@TODO RTC:138268 Set up multiple side of PNOR for bootloader
        o_errCode = 0;
        o_tocUsed = 0;
        //Copy Table of Contents from PNOR flash to a local buffer
        //The first TOC is 2 TOC sizes back from the end of the flash (+ 1)
        Bootloader::handleMMIO(i_pnorEnd - PNOR::TOC_OFFSET_FROM_TOP_OF_FLASH,
                    reinterpret_cast<uint64_t>(l_tocBuffer),
                    (PNOR::TOC_SIZE),
                    Bootloader::WORDSIZE);

        BOOTLOADER_TRACE(BTLDR_TRC_PA_FINDTOC_TOC1_HANDLEMMIO_RTN);

        readTOC(l_tocBuffer, o_errCode, o_TOC, o_pnorStart, i_pnorEnd);

        if(o_errCode == PNOR::NO_ERROR)
        {
            BOOTLOADER_TRACE(BTLDR_TRC_PA_FINDTOC_TOC1_READTOC_RTN);
            o_tocUsed = 0;
            break;
        }
        else
        {
            // @TODO RTC:164445 Can remove if there is a way to find another TOC
            // TI with data from readTOC
            terminateExecuteTI();

            //If the first toc was invalid, look for the backup in the start
            Bootloader::handleMMIO(o_pnorStart,
                              reinterpret_cast<uint64_t>(l_tocBuffer),
                              (PNOR::TOC_SIZE),
                              Bootloader::WORDSIZE);

            o_errCode = 0;
            readTOC(l_tocBuffer, o_errCode, o_TOC, o_pnorStart, i_pnorEnd);
            if(o_errCode == PNOR::NO_ERROR)
            {
                o_tocUsed = 1;
                break;
            }
            BOOTLOADER_TRACE_W_BRK(BTLDR_TRC_PA_FINDTOC_READTOC_ERR);
            // TI with data from readTOC
            terminateExecuteTI();
        }

        break;
    }while(0);
}

/**
 * @brief Get the hostboot base image
 */
void bl_pnorAccess::getHBBSection(uint64_t i_pnorEnd,
                                  PNOR::SectionData_t& o_hbbSection,
                                  uint32_t& o_errCode,
                                  uint8_t& o_tocUsed,
                                  uint64_t& o_pnorStart)
{
    BOOTLOADER_TRACE(BTLDR_TRC_PA_GETHBBSECTION_START);
    do
    {
        PNOR::SectionData_t l_TOC[PNOR::NUM_SECTIONS];

        findTOC(i_pnorEnd, l_TOC, o_errCode, o_tocUsed, o_pnorStart);

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
             * @moduleid     MOD_PNORACC_GETHBBSECT
             * @reasoncode   RC_NO_HBB_IN_TOC
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

