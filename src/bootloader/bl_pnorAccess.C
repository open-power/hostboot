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
                            uint32_t & o_errCode,
                            PNOR::SectionData_t * o_TOC,
                            uint64_t i_baseAddr)
{
    do
    {
        o_errCode = PNOR::NO_ERROR;

        ffs_hdr* l_ffs_hdr = NULL;
        //zero out the section data for each section
        PNOR::initializeSections(o_TOC);

        BOOTLOADER_TRACE(BTLDR_TRC_PA_READTOC_ZEROSECTION_RTN);

        //make sure that the buffer is not null
        PNOR::checkForNullBuffer(i_tocBuffer, o_errCode, l_ffs_hdr);

        if(o_errCode != PNOR::NO_ERROR)
        {
            BOOTLOADER_TRACE_W_BRK(BTLDR_TRC_PA_READTOC_CHKNULLBUFFER_NULL);
            break;
        }

        BOOTLOADER_TRACE(BTLDR_TRC_PA_READTOC_CHECKNULLBUFFER_RTN);

        //Do a checksum on the header
        if(PNOR::pnor_ffs_checksum(l_ffs_hdr, FFS_HDR_SIZE) != 0)
        {
            o_errCode |= PNOR::CHECKSUM_ERR;
        }

        if(o_errCode != PNOR::NO_ERROR)
        {
            BOOTLOADER_TRACE_W_BRK(BTLDR_TRC_PA_READTOC_HDRCHECKSUM_ERR);
            break;
        }

        BOOTLOADER_TRACE(BTLDR_TRC_PA_READTOC_HDRCHECKSUM_RTN);

        //Check out the header to make sure its all valid
        PNOR::checkHeader(l_ffs_hdr, o_errCode);

        if(o_errCode != PNOR::NO_ERROR)
        {
            BOOTLOADER_TRACE_W_BRK(BTLDR_TRC_PA_READTOC_CHECKHEADER_ERR);
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
            break;
        }
        BOOTLOADER_TRACE(BTLDR_TRC_PA_READTOC_PARSEENTRIES_RTN);


    } while(0);
}

void bl_pnorAccess::findTOC(uint64_t i_pnorBase, PNOR::SectionData_t * o_TOC,
                            uint32_t& o_errCode,  uint8_t& o_tocUsed)
{
    uint8_t *l_tocBuffer = Bootloader::g_blScratchSpace;
    do
    {
        //@TODO RTC:138268 Set up multiple side of PNOR for bootloader
        o_errCode = 0;
        o_tocUsed = 0;
        //Copy Table of Contents from PNOR flash to a local buffer
        Bootloader::handleMMIO(i_pnorBase,
                    reinterpret_cast<uint64_t>(l_tocBuffer),
                    (PNOR::TOC_SIZE),
                    Bootloader::BYTESIZE);

        BOOTLOADER_TRACE(BTLDR_TRC_PA_FINDTOC_TOC1_HANDLEMMIO_RTN);

        readTOC(l_tocBuffer, o_errCode, o_TOC, i_pnorBase);

        if(o_errCode == PNOR::NO_ERROR)
        {
            BOOTLOADER_TRACE(BTLDR_TRC_PA_FINDTOC_TOC1_READTOC_RTN);
            o_tocUsed = 0;
            break;
        }
        else
        {
            Bootloader::handleMMIO(i_pnorBase + PNOR::BACKUP_TOC_OFFSET,
                              reinterpret_cast<uint64_t>(l_tocBuffer),
                              (PNOR::TOC_SIZE),
                              Bootloader::BYTESIZE);

            o_errCode = 0;
            readTOC(l_tocBuffer, o_errCode, o_TOC, i_pnorBase);
            if(o_errCode == PNOR::NO_ERROR)
            {
                o_tocUsed = 1;
                break;
            }
            BOOTLOADER_TRACE_W_BRK(BTLDR_TRC_PA_FINDTOC_READTOC_ERR);
        }

        break;
    }while(0);
}

/**
 * @brief Get the hostboot base image
 */
void bl_pnorAccess::getHBBSection(uint64_t i_pnorStart,
                                  PNOR::SectionData_t& o_hbbSection,
                                  uint32_t& o_errCode,
                                  uint8_t& o_tocUsed)
{
    BOOTLOADER_TRACE(BTLDR_TRC_PA_GETHBBSECTION_START);
    do
    {
        PNOR::SectionData_t l_TOC[PNOR::NUM_SECTIONS];

        findTOC(i_pnorStart, l_TOC, o_errCode, o_tocUsed);
        if(o_errCode != PNOR::NO_ERROR)
        {
            BOOTLOADER_TRACE_W_BRK(BTLDR_TRC_PA_GETHBBSECTION_FINDTOC_ERR);
            break;
        }
        o_hbbSection = l_TOC[PNOR::HB_BASE_CODE];

        if(o_hbbSection.flashAddr == PNOR::INVALID_FLASH_OFFSET)
        {
            o_errCode = PNOR::NO_HBB_SECTION;
            BOOTLOADER_TRACE_W_BRK(BTLDR_TRC_PA_GETHBBSECTION_FINDTOC_NOHBB);
            break;
        }
    } while(0);
    BOOTLOADER_TRACE(BTLDR_TRC_PA_GETHBBSECTION_FINDTOC_RTN);

}

