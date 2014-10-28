/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnor_common.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

#include "pnor_common.H"
#include <pnor/pnorif.H>
#include <pnor/pnor_reasoncodes.H>

#include "ffs.h"           //Common header file with BuildingBlock.
#include "common/ffs_hb.H" //Hostboot def of user data in ffs_entry struct

#include <initservice/initserviceif.H>
#include <util/align.H>

// Trace definition
trace_desc_t* g_trac_pnor = NULL;
TRAC_INIT(&g_trac_pnor, PNOR_COMP_NAME, 4*KILOBYTE, TRACE::BUFFER_SLOW); //4K

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

/**
 * Eyecatcher strings for PNOR TOC entries
 */
const char* cv_EYECATCHER[] = {
    "part",     /**< PNOR::TOC            : Table of Contents */
    "HBI",      /**< PNOR::HB_EXT_CODE    : Hostboot Extended Image */
    "GLOBAL",   /**< PNOR::GLOBAL_DATA    : Global Data */
    "HBB",      /**< PNOR::HB_BASE_CODE   : Hostboot Base Image */
    "SBEC",     /**< PNOR::CENTAUR_SBE    : Centaur Self-Boot Engine image */
    "SBE",      /**< PNOR::SBE_IPL        : Self-Boot Enginer IPL image */
    "WINK",     /**< PNOR::WINK           : Sleep Winkle Reference image */
    "PAYLOAD",  /**< PNOR::PAYLOAD        : HAL/OPAL */
    "HBRT",     /**< PNOR::HB_RUNTIME     : Hostboot Runtime (for Sapphire) */
    "HBD",      /**< PNOR::HB_DATA        : Hostboot Data */
    "GUARD",    /**< PNOR::GUARD_DATA     : Hostboot Data */
    "HBEL",     /**< PNOR::HB_ERRLOGS     : Hostboot Error log Repository */
    "DJVPD",    /**< PNOR::DIMM_JEDEC_VPD : Dimm JEDEC VPD */
    "MVPD",     /**< PNOR::MODULE_VPD     : Module VPD */
    "CVPD",     /**< PNOR::CENTAUR_VPD    : Centaur VPD */
    "NVRAM",    /**< PNOR::NVRAM          : OPAL Storage */
    "OCC",      /**< PNOR::OCC            : OCC LID */
    "FIRDATA",  /**< PNOR::FIRDATA        : FIRDATA */
    "ATTR_TMP",  /**< PNOR::ATTR_TMP       : Temporary Attribute Overrides */
    "ATTR_PERM", /**< PNOR::ATTR_PERM      : Permanent Attribute Overrides */
    "TEST",     /**< PNOR::TEST           : Test space for PNOR*/
    //Not currently used
//    "XXX",    /**< NUM_SECTIONS       : Used as invalid entry */
};

/**
 * @brief calculates the checksum on data(ffs header/entry) and will return
 *    0 if the checksums match
 */
uint32_t PNOR::pnor_ffs_checksum(void* data, size_t size)
{
    uint32_t checksum = 0;

    for (size_t i = 0; i < (size/4); i++)
    {
        checksum ^= ((uint32_t*)data)[i];
    }

    checksum = htobe32(checksum);
    return checksum;
}

errlHndl_t PNOR::parseTOC(uint8_t* i_toc0Buffer, uint8_t* i_toc1Buffer,
           uint32_t & o_TOC_used, SectionData_t * o_TOC, uint64_t i_baseVAddr)
{
    TRACUCOMP(g_trac_pnor,"PNOR::parseTOC>");
    errlHndl_t l_errhdl = NULL;

    bool TOC_0_failed = false;

    do{
        o_TOC_used = 0;

        for (uint32_t cur_TOC = 0; cur_TOC < NUM_TOCS; ++cur_TOC)
        {
            TRACFCOMP(g_trac_pnor, "PNOR::parseTOC verifying TOC: %d",cur_TOC);
            uint64_t nextVAddr = i_baseVAddr;

            // Zero out my table
            for( size_t id = PNOR::FIRST_SECTION;
                 id <= PNOR::NUM_SECTIONS; //include extra entry for error paths
                 ++id )
            {
                o_TOC[id].id = (PNOR::SectionId)id;
                //everything else should default to zero
            }
            // Read TOC information from TOC 0 and then TOC 1
            ffs_hdr* l_ffs_hdr;
            if (cur_TOC == 0)
            {
                l_ffs_hdr = (ffs_hdr*) i_toc0Buffer;
            }
            else if (cur_TOC == 1)
            {
                l_ffs_hdr = (ffs_hdr*) i_toc1Buffer;
            }

            // ffs entry check, 0 if checksums match
            if( PNOR::pnor_ffs_checksum(l_ffs_hdr, FFS_HDR_SIZE) != 0)
            {
                //@TODO - RTC:90780 - May need to handle this differently
                // in SP-less config
                TRACFCOMP(g_trac_pnor,"PNOR::parseTOC pnor_ffs_checksum header"
                        " checksums do not match.");
                if (cur_TOC == 0)
                {
                    TRACFCOMP(g_trac_pnor, "PNOR::parseTOC TOC 0 failed header checksum");
                    TOC_0_failed = true;
                    o_TOC_used = 1;
                    continue;
                }
                else if (cur_TOC == 1 && TOC_0_failed)
                {
                    // Both TOC's failed
                    TRACFCOMP(g_trac_pnor, "PNOR::parseTOC both TOCs are corrupted");
                    /*@
                     * @errortype
                     * @moduleid   PNOR::MOD_PNORCOMMON_PARSETOC
                     * @reasoncode PNOR::RC_CORRUPTED_TOCS
                     * @devdesc    Both TOCs are corruputed
                     */
                    //@todo Add PNOR callout RTC:116145
                    l_errhdl = new ERRORLOG::ErrlEntry
                               (ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                PNOR::MOD_PNORCOMMON_PARSETOC,
                                PNOR::RC_CORRUPTED_TOCS,
                                0, 0, true);
                    break;
                }
                else
                {
                    // TOC 1 failed
                    TRACFCOMP(g_trac_pnor, "PNOR::parseTOC TOC 1 failed header checksum");
                    break;
                }
            }

            // Only check header if on first TOC or the first TOC failed
            if (cur_TOC == 0 || TOC_0_failed)
            {
                TRACFCOMP(g_trac_pnor, "PNOR::parseTOC: FFS Block size=0x%.8X,"
                 " Partition Table Size = 0x%.8x, entry_count=%d",
                 l_ffs_hdr->block_size,l_ffs_hdr->size,l_ffs_hdr->entry_count);

                uint64_t spaceUsed = (sizeof(ffs_entry))*l_ffs_hdr->entry_count;

                /* Checking FFS Header to make sure it looks valid */
                bool header_good = true;
                if(l_ffs_hdr->magic != FFS_MAGIC)
                {
                    TRACFCOMP(g_trac_pnor, "E>PNOR::parseTOC: Invalid magic"
                            " number in FFS header: 0x%.4X",l_ffs_hdr->magic);
                    header_good = false;
                }
                else if(l_ffs_hdr->version != SUPPORTED_FFS_VERSION)
                {
                    TRACFCOMP(g_trac_pnor, "E>PNOR::parseTOC:Unsupported FFS"
                            " Header version: 0x%.4X", l_ffs_hdr->version);
                    header_good = false;
                }
                else if(l_ffs_hdr->entry_size != sizeof(ffs_entry))
                {
                    TRACFCOMP(g_trac_pnor, "E>PNOR::parseTOC: Unexpected"
                            " entry_size(0x%.8x) in FFS header: 0x%.4X",
                            l_ffs_hdr->entry_size);
                    header_good = false;
                }
                else if(l_ffs_hdr->entries == NULL)
                {
                    TRACFCOMP(g_trac_pnor, "E>PNOR::parseTOC:"
                            "  FFS Header pointer to entries is NULL.");
                    header_good = false;
                }
                else if(l_ffs_hdr->block_size != PAGESIZE)
                {
                    TRACFCOMP(g_trac_pnor, "E>PNOR::parseTOC:  Unsupported"
                            " Block Size(0x%.4X). PNOR Blocks must be 4k",
                              l_ffs_hdr->block_size);
                    header_good = false;
                }
                else if(l_ffs_hdr->block_count == 0)
                {
                    TRACFCOMP(g_trac_pnor, "E>PNOR::parseTOC:  Unsupported"
                            " Block COunt(0x%.4X). Device cannot be zero"
                            " blocks in length.",l_ffs_hdr->block_count);
                    header_good = false;
                }
                //Make sure all the entries fit in specified partition
                //table size
                else if(spaceUsed >
                    ((l_ffs_hdr->block_size*l_ffs_hdr->size)-sizeof(ffs_hdr)))
                {
                    TRACFCOMP(g_trac_pnor, "E>PNOR::parseTOC:  FFS Entries"
                            " (0x%.16X) go past end of FFS Table.",spaceUsed);
                    header_good = false;
                }

                if(!header_good)
                {
                    //Shutdown if we detected a partition table issue
                    //for any reason
                    if (TOC_0_failed)
                    {
                       /*@
                        * @errortype
                        * @moduleid   PNOR::MOD_PNORCOMMON_PARSETOC
                        * @reasoncode PNOR::RC_BAD_TOC_HEADER
                        * @devdesc    TOC 0 doesn't have a good header
                        */
                        l_errhdl = new ERRORLOG::ErrlEntry
                                             (ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              PNOR::MOD_PNORCOMMON_PARSETOC,
                                              PNOR::RC_BAD_TOC_HEADER,
                                              0, 0, true);
                        break;
                    }
                    else
                    {
                        TOC_0_failed = true;
                    }
                    //Try TOC1
                    continue;
                }
            }

            ffs_hb_user_t* ffsUserData = NULL;

            //Walk through all the entries in the table and parse the data.
            for(uint32_t i=0; i<l_ffs_hdr->entry_count; i++)
            {
                ffs_entry* cur_entry = (&l_ffs_hdr->entries[i]);

                TRACUCOMP(g_trac_pnor, "PNOR::parseTOC:  Entry %d, name=%s, "
                        "pointer=0x%X",i,cur_entry->name, (uint64_t)cur_entry);

                uint32_t secId = PNOR::INVALID_SECTION;

                // ffs entry check, 0 if checksums match
                if( PNOR::pnor_ffs_checksum(cur_entry, FFS_ENTRY_SIZE) != 0)
                {
                    //@TODO - RTC:90780 - May need to handle this differently
                    // in SP-less config
                    TRACFCOMP(g_trac_pnor, "PNOR::parseTOC pnor_ffs_checksum"
                            " entry checksums do not match");
                    if (cur_TOC == 0)
                    {
                        TRACFCOMP(g_trac_pnor,"PNOR::parseTOC TOC 0 entry"
                                " checksum failed");
                        TOC_0_failed = true;
                        o_TOC_used = 1;
                        break;
                    }
                    else if (cur_TOC == 1 && TOC_0_failed)
                    {
                        // Both TOC's failed
                        TRACFCOMP(g_trac_pnor, "PNOR::parseTOC both TOC's are"
                                  " corrupted");
                       /*@
                        * @errortype
                        * @moduleid   PNOR::MOD_PNORCOMMON_PARSETOC
                        * @reasoncode PNOR::RC_PARTITION_TABLE_INVALID
                        * @devdesc    Both TOCs are corrupted
                        */
                        l_errhdl = new ERRORLOG::ErrlEntry
                                             (ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              PNOR::MOD_PNORCOMMON_PARSETOC,
                                              PNOR::RC_PARTITION_TABLE_INVALID,
                                              0, 0, true);
                        break;
                    }
                    else
                    {
                        // TOC 1 failed
                        TRACFCOMP(g_trac_pnor, "PNOR::parseTOC TOC 1 entry"
                                " checksum failed");
                        break;
                    }
                }

                // Only set data if on first TOC or the first TOC failed
                if (cur_TOC == 0 || TOC_0_failed)
                {
                    //Figure out section enum
                    for(uint32_t eyeIndex=PNOR::TOC;eyeIndex<PNOR::NUM_SECTIONS;
                                     eyeIndex++)
                    {
                        if(strcmp(cv_EYECATCHER[eyeIndex],cur_entry->name) == 0)
                        {
                            secId = eyeIndex;
                            TRACUCOMP(g_trac_pnor, "PNOR::parseTOC: sectionId=%d", secId);
                            break;
                        }
                    }

                    if(secId == PNOR::INVALID_SECTION)
                    {
                        TRACFCOMP(g_trac_pnor, "PNOR::parseTOC:  Unrecognized"
                                " Section name(%s), skipping",cur_entry->name);
                        continue;
                    }

                    ffsUserData = (ffs_hb_user_t*)&(cur_entry->user);

                    //size
                    o_TOC[secId].size = ((uint64_t)cur_entry->size)*PAGESIZE;

                    //virtAddr
                    o_TOC[secId].virtAddr = nextVAddr;
                    nextVAddr += o_TOC[secId].size;

                    //flashAddr
                    o_TOC[secId].flashAddr=((uint64_t)cur_entry->base)*PAGESIZE;

                    //chipSelect
                    o_TOC[secId].chip = ffsUserData->chip;

                    //user data
                    o_TOC[secId].integrity = ffsUserData->dataInteg;
                    o_TOC[secId].version = ffsUserData->verCheck;
                    o_TOC[secId].misc = ffsUserData->miscFlags;

                    TRACFCOMP(g_trac_pnor,"PNOR::parseTOC: User Data %s",
                            cur_entry->name);

                    if (o_TOC[secId].integrity == FFS_INTEG_ECC_PROTECT)
                    {
                        TRACFCOMP(g_trac_pnor, "PNOR::TOC: ECC enabled for %s",
                                cur_entry->name);
                        o_TOC[secId].size = ALIGN_PAGE_DOWN
                                            ((o_TOC[secId].size * 8 ) / 9);
                    }

                    // TODO RTC:96009 handle version header w/secureboot
                    if (o_TOC[secId].version == FFS_VERS_SHA512)
                    {
                        TRACFCOMP(g_trac_pnor, "PNOR::parseTOC: Incrementing"
                                " Flash Address for SHA Header");
                        if (o_TOC[secId].integrity == FFS_INTEG_ECC_PROTECT)
                        {
                            o_TOC[secId].flashAddr += PAGESIZE_PLUS_ECC;
                        }
                        else
                        {
                            o_TOC[secId].flashAddr += PAGESIZE;
                        }
                    }

                    if((o_TOC[secId].flashAddr + o_TOC[secId].size) >
                            (l_ffs_hdr->block_count*PAGESIZE))
                    {
                        TRACFCOMP(g_trac_pnor, "E>PNOR::parseTOC:Partition(%s)"
                                " at base address (0x%.8x) extends past end of"
                                " flash device",cur_entry->name,
                                o_TOC[secId].flashAddr);
                       /*@
                        * @errortype
                        * @moduleid   PNOR::MOD_PNORCOMMON_PARSETOC
                        * @reasoncode PNOR::RC_SECTION_SIZE_IS_BIG
                        * @devdesc    Invalid partition table
                        */
                        l_errhdl = new ERRORLOG::ErrlEntry
                                             (ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              PNOR::MOD_PNORCOMMON_PARSETOC,
                                              PNOR::RC_SECTION_SIZE_IS_BIG,
                                              0, 0, true);
                        break;
                    }
                }
            }
            if (l_errhdl)
            {
                TRACFCOMP(g_trac_pnor, ERR_MRK"PNOR::parseTOC: error parsing");
                break;
            }

            for(PNOR::SectionId tmpId = PNOR::FIRST_SECTION;
                tmpId < PNOR::NUM_SECTIONS;
                tmpId = (PNOR::SectionId) (tmpId + 1) )
            {
                TRACFCOMP(g_trac_pnor, "%s:    size=0x%.8X  flash=0x%.8X  "
                       "virt=0x%.16X", cv_EYECATCHER[tmpId], o_TOC[tmpId].size,
                       o_TOC[tmpId].flashAddr, o_TOC[tmpId].virtAddr );
            }
        }
    } while(0);

    TRACUCOMP(g_trac_pnor, "< PNOR::parseTOC" );
    return l_errhdl;
}

