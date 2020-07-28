/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnor_utils.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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

#ifdef BOOTLOADER
#include <bootloader/bootloader_trace.H>
#include <bootloader/bootloader.H>
#include <bootloader/hbblreasoncodes.H>
#define PNOR_UTIL_TRACE(arg0, args...) BOOTLOADER_TRACE(arg0)
#define PNOR_UTIL_TRACE_W_BRK(arg0, args...) BOOTLOADER_TRACE_W_BRK(arg0)
#define PNOR_UTIL_TRACE_BL_SKIP(arg0, args...)

#else // HBI and HBRT

#include <errl/errlmanager.H>
#include <assert.h>

#ifdef __HOSTBOOT_RUNTIME
extern trace_desc_t* g_trac_hbrt;;
#define PNOR_UTIL_TRACE(arg0, args...) TRACFCOMP(g_trac_hbrt, args)
#define PNOR_UTIL_TRACE_W_BRK(arg0, args...) TRACFCOMP(g_trac_hbrt, args)
#define PNOR_UTIL_TRACE_BL_SKIP(arg0, args...) TRACFCOMP(g_trac_hbrt, args)

#else //HBI
extern trace_desc_t* g_trac_pnor;;
#define PNOR_UTIL_TRACE(arg0, args...) TRACFCOMP(g_trac_pnor, args)
#define PNOR_UTIL_TRACE_W_BRK(arg0, args...) TRACFCOMP(g_trac_pnor, args)
#define PNOR_UTIL_TRACE_BL_SKIP(arg0, args...) TRACFCOMP(g_trac_pnor, args)

#endif

#endif


#include "common/ffs_hb.H"
#include <util/align.H>
#include <securerom/ROM.H>

#include <pnor/pnorif.H>

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
                               "E>PNOR::checkHeader: Invalid magic"
                " number in FFS header: 0x%.4X",i_ffs_hdr->magic);
        io_errCode |= INVALID_MAGIC;
    }
    if(i_ffs_hdr->version != SUPPORTED_FFS_VERSION)
    {
        PNOR_UTIL_TRACE_W_BRK(BTLDR_TRC_UTILS_CHECKHEADER_VERSION,
          "E>PNOR::checkHeader:Unsupported FFS"
                " Header version: 0x%.4X", i_ffs_hdr->version);
        io_errCode |= UNSUPPORTED_FFS;
    }
    if(i_ffs_hdr->entry_size != sizeof(ffs_entry))
    {
        PNOR_UTIL_TRACE_W_BRK(BTLDR_TRC_UTILS_CHECKHEADER_ENTRYSIZE,
                               "E>PNOR::checkHeader: Unexpected"
                " entry_size(0x%.8x) in FFS header: 0x%.4X",
                i_ffs_hdr->entry_size);
        io_errCode |= INVALID_ENTRY_SIZE;
    }
    if(i_ffs_hdr->entry_count == 0)
    {
        PNOR_UTIL_TRACE_W_BRK(BTLDR_TRC_UTILS_CHECKHEADER_ENTRYCNT,
                               "E>PNOR::checkHeader:"
                                " FFS Header pointer to entries is NULL.");
        io_errCode |= NO_ENTRIES;
    }
    if(i_ffs_hdr->block_size != PAGESIZE)
    {
        PNOR_UTIL_TRACE_W_BRK(BTLDR_TRC_UTILS_CHECKHEADER_BLOCKSIZE,
                              "E>PNOR::checkHeader:  Unsupported"
                              " Block Size(0x%.4X). PNOR Blocks must be 4k",
                              i_ffs_hdr->block_size);
        io_errCode |= INVALID_BLOCK_SIZE;
    }
    if(i_ffs_hdr->block_count == 0)
    {
        PNOR_UTIL_TRACE_W_BRK(BTLDR_TRC_UTILS_CHECKHEADER_BLOCKCNT,
                              "E>PNOR::checkHeader:  Unsupported"
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
                              "E>PNOR::checkHeader:  FFS Entries"
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
void PNOR::getSectionEnum (const ffs_entry* i_entry,
                           SectionId* o_secId)
{
    *o_secId = PNOR::INVALID_SECTION;
    //Figure out section enum
    for(uint32_t eyeIndex=PNOR::TOC;eyeIndex<PNOR::NUM_SECTIONS;
                      eyeIndex++)
    {
        if(strcmp(PNOR::SectionIdToString(eyeIndex),i_entry->name) == 0)
        {
            *o_secId = SectionId(eyeIndex);
            break;
        }
    }
}

/**
  * @brief Iterate through the entries, each which represent a section in pnor.
  *         During the iteration we are checking that the entries are valid
  *        and we set the sectionData_t for each section in the TOC.
  */
#ifdef BOOTLOADER
void
#else
errlHndl_t
#endif
PNOR::parseEntries (ffs_hdr* i_ffs_hdr,
                    uint32_t& io_errCode,
                    PNOR::SectionData_t * io_TOC,
                    ffs_entry*& o_err_entry)
{
#ifndef BOOTLOADER
    errlHndl_t l_errhdl = nullptr;
#endif

    //Walk through all the entries in the table and parse the data.
    for(uint32_t i=0; i<i_ffs_hdr->entry_count; i++)
    {
        ffs_entry* cur_entry = (&i_ffs_hdr->entries[i]);
        PNOR::SectionId secId = PNOR::INVALID_SECTION;

        // ffs entry check, 0 if checksums match
        if( PNOR::pnor_ffs_checksum(cur_entry, FFS_ENTRY_SIZE) != 0)
        {
            PNOR_UTIL_TRACE_W_BRK(BTLDR_TRC_UTILS_PARSE_CHECKSUM_ERROR,
                                   "E>PNOR::parseEntries:  "
                                   "Check sum error while parseing entry "
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
            PNOR_UTIL_TRACE_BL_SKIP(BTLDR_TRC_UTILS_PARSE_INVALID_SECTION,
                                    "PNOR::parseEntries: "
                                    "Unsupported section found while parsing "
                                    "entry %d in TOC \n Entry name is \"%s\"",
                                    i, cur_entry->name);
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
        if((io_TOC[secId].flashAddr + io_TOC[secId].size) >
                (i_ffs_hdr->block_count*PAGESIZE))
        {
            PNOR_UTIL_TRACE_W_BRK(BTLDR_TRC_UTILS_PARSE_EXCEEDS_FLASH,
                                  "E>PNOR::parseEntries:  "
                                   "Exceeded flash while parsing entry "
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

        // isEnforcedSecureSection should always handle SB compiled in or not,
        // but if that ever changes, force flag to false in PNOR TOC.
#if defined CONFIG_SECUREBOOT || defined BOOTLOADER
        io_TOC[secId].secure = PNOR::isEnforcedSecureSection(secId);
#else
        io_TOC[secId].secure = false;
#endif

        // If secureboot is compiled in, skip header if not a secure section
        // Otherwise always skip header as the secure flag is always false and
        // SpnorRp will not handle skipping the header if one is indicated in PNOR
        if ( (io_TOC[secId].version & FFS_VERS_SHA512)
              && !io_TOC[secId].secure)
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

            // now that we've skipped the header
            // adjust the size to reflect that
            io_TOC[secId].size -= PAGESIZE;
        }

    } // For TOC Entries

#ifndef BOOTLOADER
    return l_errhdl;
#endif

}

bool PNOR::isEnforcedSecureSection(const uint32_t i_section)
{
#if defined CONFIG_SECUREBOOT || defined BOOTLOADER
    #ifdef BOOTLOADER
        return i_section == HB_BASE_CODE;
    #else
        return i_section == HB_BOOTLOADER ||
               i_section == HB_EXT_CODE ||
               i_section == HB_DATA ||
               i_section == SBE_IPL ||
               i_section == PAYLOAD ||
#ifdef CONFIG_LOAD_PHYP_FROM_BOOTKERNEL
               i_section == BOOTKERNEL ||
#endif
               i_section == SBKT ||
               i_section == OCC ||
               i_section == HCODE ||
               i_section == HCODE_LID ||
               i_section == HB_RUNTIME ||
               i_section == WOFDATA ||
               i_section == CAPP ||
               i_section == TESTLOAD ||
               i_section == VERSION ||
               i_section == OCMBFW;
    #endif
#else
    return false;
#endif
}

bool PNOR::isCoreRootOfTrustSection(const PNOR::SectionId i_section)
{
#if defined CONFIG_SECUREBOOT || defined BOOTLOADER
    #ifdef BOOTLOADER
        return i_section == HB_BASE_CODE;
    #else
        return i_section == HB_BOOTLOADER ||
               i_section == HB_EXT_CODE ||
               i_section == HB_DATA ||
               i_section == SBE_IPL ||
               i_section == HB_BASE_CODE;
    #endif
#else
    return false;
#endif
}

const char * PNOR::SectionIdToString( uint32_t i_secIdIndex )
{
    /**
     * Eyecatcher strings for PNOR TOC entries
     * Use an array vs switch statement for O(1) lookup
     * Not using std::array so we can check the actual size filled in vs N
     *   in std:array<const char*, N>.
     */
    static const char* SectionIdToStringArr[] =
    {
        "part",        /**< PNOR::TOC            : Table of Contents */
#ifndef BOOTLOADER
        "HBI",         /**< PNOR::HB_EXT_CODE    : Hostboot Extended Image */
#endif
        "HBB",         /**< PNOR::HB_BASE_CODE   : Hostboot Base Image */
#ifndef BOOTLOADER
        "SBE",         /**< PNOR::SBE_IPL        : Self-Boot Enginer IPL image */
        "HCODE",       /**< PNOR::HCODE          : HCODE Reference image */
        "PAYLOAD",     /**< PNOR::PAYLOAD        : HAL/OPAL */
        "HBRT",        /**< PNOR::HB_RUNTIME     : Hostboot Runtime(for Sapphire)*/
        "HBD",         /**< PNOR::HB_DATA        : Hostboot Data */
        "GUARD",       /**< PNOR::GUARD_DATA     : Hostboot Data */
        "HBEL",        /**< PNOR::HB_ERRLOGS     : Hostboot Error log Repository */
        "DJVPD",       /**< PNOR::DIMM_JEDEC_VPD : Dimm JEDEC VPD */
        "MVPD",        /**< PNOR::MODULE_VPD     : Module VPD */
        "NVRAM",       /**< PNOR::NVRAM          : OPAL Storage */
        "OCC",         /**< PNOR::OCC            : OCC LID */
        "FIRDATA",     /**< PNOR::FIRDATA        : DEPRECATED: FIRs for checkstop analysis */
        "ATTR_TMP",    /**< PNOR::ATTR_TMP       : Temporary Attribute Overrides */
        "ATTR_PERM",   /**< PNOR::ATTR_PERM      : Permanent Attribute Overrides */
        "CAPP",        /**< PNOR::CAPP           : CAPP LID */
        "VERSION",     /**< PNOR::VERSION        : PNOR Version string */
        "HBBL",        /**<PNOR::HB_BOOTLOADER   : Hostboot Bootloader image */
        "TEST",        /**< PNOR::TEST           : Test space for PNOR*/
        "TESTRO",      /**< PNOR::TESTRO         : ReadOnly Test space for PNOR */
        "BACKUP_PART", /**PNOR::BACKUP_PART      : Backup of PART*/
        "RINGOVD",     /**< PNOR::RINGOVD        : Ring overrides */
        "WOFDATA",     /**< PNOR::WOFDATA        : VFRT data tables for WOF */
        "SBKT",        /**< PNOR::SBKT           : SecureBoot Key Transition */
        "HB_VOLATILE", /**< PNOR::HB_VOLATILE    : Semi volatile partition */
        "TESTLOAD",    /**< PNOR::TESTLOAD       : Secureboot Test Load */
        "HDAT",        /**< PNOR::HDAT           : Hdat Data */
        "EECACHE",     /**< PNOR::EECACHE        : Cached data from various EEPROMs */
        "OCMBFW",      /**< PNOR::OCMBFW         : OCMB image */
#ifdef CONFIG_DEVTREE
        "DEVTREE",     /**< PNOR::DEVTREE        : DEVTREE image */
#endif
#ifdef CONFIG_LOAD_PHYP_FROM_BOOTKERNEL
        "BOOTKERNEL",  /**< PNOR::BOOTKERNEL     : OPAL == petitboot,PHYP == PowerVM */
#endif
        "HCODE_LID",   /**< PNOR::HCODE_LID      : HCODE_LID Reference image */
#endif
    };

    // Get actual number of entries of array.
    const size_t numEntries = sizeof(SectionIdToStringArr)/sizeof(char*);

    // Assert that the number of entries equals PNOR::NUM_SECTIONS
    static_assert (numEntries == (PNOR::NUM_SECTIONS),
               "Mismatch between number of SectionIds and correlating strings");

    // Assert if accessing index out of array or not INVALID section
    assert(i_secIdIndex <= (PNOR::NUM_SECTIONS),
#ifdef BOOTLOADER
           BTLDR_TRC_UTILS_PNOR_SECID_OUT_OF_RANGE,
           Bootloader::RC_PNOR_SECID_OUT_OF_RANGE
#else
           "SectionIdToString PNOR section id out of range"
#endif
    );

    const char * l_str = "INVALID_SECTION";
    if(i_secIdIndex < PNOR::INVALID_SECTION)
    {
       l_str = SectionIdToStringArr[i_secIdIndex];
    }

    return l_str;
}

bool PNOR::cmpSecurebootMagicNumber(const uint8_t* i_vaddr)
{
    // Assert if accessing index out of array.
    assert(i_vaddr != nullptr,
#ifdef BOOTLOADER
           BTLDR_TRC_UTILS_CMP_MAGIC_NUM_NULLPTR,
           Bootloader::RC_PNOR_NULLPTR
#else
           "cmpSecurebootMagicNumber requested address to compare is a nullptr"
#endif
    );

    return memcmp(&ROM_MAGIC_NUMBER, i_vaddr, sizeof(ROM_MAGIC_NUMBER))==0;
}
