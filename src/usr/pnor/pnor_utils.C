/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnor_utils.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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


/****************** Description *****************************************/
//This file provides a variety of utility functions primarily interacting
//with the table of contents(TOC) of pnor flash. This code is shared by HB
//with the bootloader code (/src/bootloader) so traces can be tricky,
//use the PNOR_UTIL macros to record logs.
/************************************************************************/

#include "pnor_utils.H"
#include <pnor/pnor_const.H>

#if  !defined(__BOOT_LOADER_H)
#include <errl/errlmanager.H>
extern trace_desc_t* g_trac_pnor;
#define PNOR_UTIL_TRACE(arg0, args...) TRACFCOMP(g_trac_pnor, args)
#define PNOR_UTIL_TRACE_W_BRK(arg0, args...) TRACFCOMP(g_trac_pnor, args)
#else
#include <bootloader/bootloader_trace.H>
#define PNOR_UTIL_TRACE(arg0, args...) BOOTLOADER_TRACE(arg0)
#define PNOR_UTIL_TRACE_W_BRK(arg0, args...) BOOTLOADER_TRACE_W_BRK(arg0)
#endif


#include "common/ffs_hb.H"
#include <util/align.H>

/**
 * Eyecatcher strings for PNOR TOC entries
 */
const char* cv_EYECATCHER[] = {
    "part",      /**< PNOR::TOC              : Table of Contents */
    "HBI",       /**< PNOR::HB_EXT_CODE      : Hostboot Extended Image */
    "GLOBAL",    /**< PNOR::GLOBAL_DATA      : Global Data */
    "HBB",       /**< PNOR::HB_BASE_CODE     : Hostboot Base Image */
    "SBEC",      /**< PNOR::CENTAUR_SBE      : Centaur Self-Boot Engine image */
    "SBE",       /**< PNOR::SBE_IPL          : Self-Boot Enginer IPL image */
    "WINK",      /**< PNOR::WINK             : Sleep Winkle Reference image */
    "PAYLOAD",   /**< PNOR::PAYLOAD          : HAL/OPAL */
    "HBRT",      /**< PNOR::HB_RUNTIME       : Hostboot Runtime(for Sapphire)*/
    "HBD",       /**< PNOR::HB_DATA          : Hostboot Data */
    "GUARD",     /**< PNOR::GUARD_DATA       : Hostboot Data */
    "HBEL",      /**< PNOR::HB_ERRLOGS       : Hostboot Error log Repository */
    "DJVPD",     /**< PNOR::DIMM_JEDEC_VPD   : Dimm JEDEC VPD */
    "MVPD",      /**< PNOR::MODULE_VPD       : Module VPD */
    "CVPD",      /**< PNOR::CENTAUR_VPD      : Centaur VPD */
    "NVRAM",     /**< PNOR::NVRAM            : OPAL Storage */
    "OCC",       /**< PNOR::OCC              : OCC LID */
    "FIRDATA",   /**< PNOR::FIRDATA          : FIRDATA */
    "ATTR_TMP",  /**< PNOR::ATTR_TMP         : Temporary Attribute Overrides */
    "ATTR_PERM", /**< PNOR::ATTR_PERM        : Permanent Attribute Overrides */
    "CAPP",      /**< PNOR::CAPP             : CAPP LID */
    "VERSION",   /**< PNOR::VERSION          : PNOR Version string */
    "HBBL",      /**<PNOR::HB_BOOTLOADER     : Hostboot Bootloader image */
    "TEST",      /**< PNOR::TEST             : Test space for PNOR*/
    "TESTRO",    /**< PNOR::TESTRO           : ReadOnly Test space for PNOR */
    "BACKUP_PART", /**PNOR::BACKUP_PART      : Backup of PART*/
};

/**
 * @brief calculates the checksum on data(ffs header/entry) and will return
 *    0 if the checksums match
 */
uint32_t PNOR::pnor_ffs_checksum(void* i_data, size_t i_size)
{
    uint32_t checksum = 0;
    for (size_t i = 0; i < (i_size/4); i++)
    {
        checksum ^= ((uint32_t*)i_data)[i];
    }
    checksum = htobe32(checksum);

    return checksum;
}

//RTC: 147939 Refactor Local Memset
void * localMemset(void *i_dest, int8_t i_value, uint8_t i_size)
{
    unsigned char *buf = (unsigned char *)i_dest;
    while (i_size--)
    {
        *(buf++) = (unsigned char)i_value;
    }
    return i_dest;
}

/**
* @brief Set up some initial information about the sections of the TOC.
*        The section's ID and flashAddr are set to specific values while
*        the rest of the data for the struct is set to 0.
*/
void PNOR::initializeSections(PNOR::SectionData_t io_toc[NUM_SECTIONS])
{
    for( size_t id = PNOR::FIRST_SECTION;
          id <= PNOR::NUM_SECTIONS; //include extra entry for error paths
          ++id )
    {
        localMemset(&io_toc[id], 0, sizeof(io_toc[id]));

        //Set the id to be the name corresponding to this section
        io_toc[id].id = (PNOR::SectionId)id;

        //All sections are initially set to INVALID_FLASH_OFFSET
        //this is large value that is not in the valid addressing range.
        //We chose a large value instead of 0 because the first section
        //has a flash addr of 0 and we want to avoid confusion.
        io_toc[id].flashAddr = INVALID_FLASH_OFFSET;

    }
}



/**
  * @brief Ensure the buffer is not NULL, if it is, then return
  *        the appropriate err code from the o_errCode param.
  *        if the buffer is not NULL then cast it to a ffs_hdr
  *        and return that out through the respective o_param
  */
void PNOR::checkForNullBuffer(uint8_t* i_tocBuffer,
                              uint32_t& o_errCode,
                              ffs_hdr*& o_ffs_hdr)
{
    if(!i_tocBuffer)
    {
        o_errCode |= BUFF_IS_NULL;
        o_ffs_hdr = NULL;
    }
    else
    {
        o_ffs_hdr = (ffs_hdr*)i_tocBuffer;
    }
}


/**
  * @brief Perform a series of checks on the header of the table of contents
  *        These checks include: looking for valid magic #, valid block size,
  *        valid block count, valid entry size, valid entry count, version and
  *        total size.
  *
  */
void PNOR::checkHeader (ffs_hdr* i_ffs_hdr,
                        uint32_t& io_errCode)
{
    uint64_t spaceUsed = (sizeof(ffs_entry))*i_ffs_hdr->entry_count;

    // Checking FFS Header to make sure it looks valid
    // Not breaking after one error, want to collect them all
    if(i_ffs_hdr->magic != FFS_MAGIC)
    {
        PNOR_UTIL_TRACE_W_BRK(BTLDR_TRC_UTILS_CHECKHEADER_MAGIC,
                               "E>PNOR::parseTOC: Invalid magic"
                " number in FFS header: 0x%.4X",i_ffs_hdr->magic);
        io_errCode |= INVALID_MAGIC;
    }
    if(i_ffs_hdr->version != SUPPORTED_FFS_VERSION)
    {
        PNOR_UTIL_TRACE_W_BRK(BTLDR_TRC_UTILS_CHECKHEADER_VERSION,
          "E>PNOR::parseTOC:Unsupported FFS"
                " Header version: 0x%.4X", i_ffs_hdr->version);
        io_errCode |= UNSUPPORTED_FFS;
    }
    if(i_ffs_hdr->entry_size != sizeof(ffs_entry))
    {
        PNOR_UTIL_TRACE_W_BRK(BTLDR_TRC_UTILS_CHECKHEADER_ENTRYSIZE,
                               "E>PNOR::parseTOC: Unexpected"
                " entry_size(0x%.8x) in FFS header: 0x%.4X",
                i_ffs_hdr->entry_size);
        io_errCode |= INVALID_ENTRY_SIZE;
    }
    if(i_ffs_hdr->entry_count == 0)
    {
        PNOR_UTIL_TRACE_W_BRK(BTLDR_TRC_UTILS_CHECKHEADER_ENTRYCNT,
                               "E>PNOR::parseTOC:"
                                " FFS Header pointer to entries is NULL.");
        io_errCode |= NO_ENTRIES;
    }
    if(i_ffs_hdr->block_size != PAGESIZE)
    {
        PNOR_UTIL_TRACE_W_BRK(BTLDR_TRC_UTILS_CHECKHEADER_BLOCKSIZE,
                              "E>PNOR::parseTOC:  Unsupported"
                              " Block Size(0x%.4X). PNOR Blocks must be 4k",
                              i_ffs_hdr->block_size);
        io_errCode |= INVALID_BLOCK_SIZE;
    }
    if(i_ffs_hdr->block_count == 0)
    {
        PNOR_UTIL_TRACE_W_BRK(BTLDR_TRC_UTILS_CHECKHEADER_BLOCKCNT,
                              "E>PNOR::parseTOC:  Unsupported"
                " Block COunt(0x%.4X). Device cannot be zero"
                " blocks in length.",i_ffs_hdr->block_count);
        io_errCode |= INVALID_BLOCK_COUNT;
    }
    //Make sure all the entries fit in specified partition
    //table size
    if(spaceUsed >
        ((i_ffs_hdr->block_size*i_ffs_hdr->size)-sizeof(ffs_hdr)))
    {
        PNOR_UTIL_TRACE_W_BRK(BTLDR_TRC_UTILS_CHECKHEADER_HDRSIZE,
                              "E>PNOR::parseTOC:  FFS Entries"
                        " (0x%.16X) go past end of FFS Table.",spaceUsed);
        io_errCode |= INVALID_HEADER_SIZE;

    }
    if(io_errCode != NO_ERROR)
    {
        io_errCode |= HEADER_ERR;
    }
}

/**
  * @brief Takes in an ffs_entry and returns the enum version of the section
  *         title.
  */
void PNOR::getSectionEnum (ffs_entry* i_entry,
                           uint32_t* o_secId)
{
    *o_secId = PNOR::INVALID_SECTION;
    //Figure out section enum
    for(uint32_t eyeIndex=PNOR::TOC;eyeIndex<PNOR::NUM_SECTIONS;
                      eyeIndex++)
    {
        if(strcmp(cv_EYECATCHER[eyeIndex],i_entry->name) == 0)
        {
            *o_secId = eyeIndex;
            break;
        }
    }
}

/**
  * @brief Iterate through the entries, each which represent a section in pnor.
  *         During the iteration we are checking that the entries are valid
  *        and we set the sectionData_t for each section in the TOC.
  */
void PNOR::parseEntries (ffs_hdr* i_ffs_hdr,
                         uint32_t& io_errCode,
                         SectionData_t * io_TOC,
                         ffs_entry*& o_err_entry)
{
    //Walk through all the entries in the table and parse the data.
    for(uint32_t i=0; i<i_ffs_hdr->entry_count; i++)
    {
        ffs_entry* cur_entry = (&i_ffs_hdr->entries[i]);
        uint32_t secId = PNOR::INVALID_SECTION;

        // ffs entry check, 0 if checksums match
        if( PNOR::pnor_ffs_checksum(cur_entry, FFS_ENTRY_SIZE) != 0)
        {
            PNOR_UTIL_TRACE_W_BRK(BTLDR_TRC_UTILS_PARSE_CHECKSUM_ERROR,
                                   "E>PNOR::parseTOC:  "
                                   "Check sum error while parseing entry ",
                                   "%d in TOC", i);
            io_errCode |= ENTRY_ERR;
            io_errCode |= ENTRY_CHECKSUM_ERR;
            //note the entry we failed on
            o_err_entry = cur_entry;
            //break beacuse we are going to waste time checking other entries
            break;
        }
        //Figure out section enum
        getSectionEnum(cur_entry, &secId);

        if(secId == PNOR::INVALID_SECTION)
        {
            PNOR_UTIL_TRACE(BTLDR_TRC_UTILS_PARSE_INVALID_SECTION,
                            "PNOR::parseTOC: "
                            "Unsupported section found while parsing entry ",
                            "%d in TOC \n Entry name is \"%s\"", i,
                            cur_entry->name);
            //continue to skip invalid section
            continue;
        }
        ffs_hb_user_t* ffsUserData = NULL;
        ffsUserData = (ffs_hb_user_t*)&(cur_entry->user);

        //size
        io_TOC[secId].size =
                        ((uint64_t)cur_entry->size)*(i_ffs_hdr->block_size);

        //flashAddr
        io_TOC[secId].flashAddr=
                          ((uint64_t)cur_entry->base)*(i_ffs_hdr->block_size);

        //chipSelect
        io_TOC[secId].chip = ffsUserData->chip;

        //user data
        io_TOC[secId].integrity = ffsUserData->dataInteg;
        io_TOC[secId].version = ffsUserData->verCheck;
        io_TOC[secId].misc = ffsUserData->miscFlags;
        io_TOC[secId].compress = ffsUserData->compressType;
        io_TOC[secId].xzDecompressSize =
                (ffsUserData->decompressSize);
        if((io_TOC[secId].flashAddr + io_TOC[secId].size) >
                (i_ffs_hdr->block_count*PAGESIZE))
        {
            PNOR_UTIL_TRACE_W_BRK(BTLDR_TRC_UTILS_PARSE_EXCEEDS_FLASH,
                                  "E>PNOR::parseTOC:  "
                                   "Exceeded flash while parsing entry ",
                                   "%d in TOC \n Entry name is \"%s\"", i,
                                    cur_entry->name);
            io_errCode |= ENTRY_ERR;
            io_errCode |= ENTRY_EXTENDS_BEYOND_FLASH;
            //note the entry we failed on
            o_err_entry = cur_entry;
            break;
        }

        if (io_TOC[secId].integrity == FFS_INTEG_ECC_PROTECT)
        {
            io_TOC[secId].size = ALIGN_PAGE_DOWN
                                ((io_TOC[secId].size * 8 ) / 9);
        }

        // TODO RTC:96009 handle version header w/secureboot
        if (io_TOC[secId].version == FFS_VERS_SHA512)
        {
              //increment flash addr for sha header
            if (io_TOC[secId].integrity == FFS_INTEG_ECC_PROTECT)
            {
                io_TOC[secId].flashAddr += PAGESIZE_PLUS_ECC ;
            }
            else
            {
                io_TOC[secId].flashAddr += PAGESIZE ;
            }
            io_TOC[secId].size -= PAGESIZE;
        }

    } // For TOC Entries
}



