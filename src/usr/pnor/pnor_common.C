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
#include <pnor/pnor_reasoncodes.H>

#include "ffs.h"           //Common header file with BuildingBlock.
#include "common/ffs_hb.H" //Hostboot def of user data in ffs_entry struct
#include <sys/mm.h>

#include <initservice/initserviceif.H>
#include <util/align.H>
#include <errl/errlmanager.H>
#include <config.h>        // @FIXME RTC 132398

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
    "part",      /**< PNOR::TOC            : Table of Contents */
    "HBI",       /**< PNOR::HB_EXT_CODE    : Hostboot Extended Image */
    "GLOBAL",    /**< PNOR::GLOBAL_DATA    : Global Data */
    "HBB",       /**< PNOR::HB_BASE_CODE   : Hostboot Base Image */
    "SBEC",      /**< PNOR::CENTAUR_SBE    : Centaur Self-Boot Engine image */
    "SBE",       /**< PNOR::SBE_IPL        : Self-Boot Enginer IPL image */
    "WINK",      /**< PNOR::WINK           : Sleep Winkle Reference image */
    "PAYLOAD",   /**< PNOR::PAYLOAD        : HAL/OPAL */
    "HBRT",      /**< PNOR::HB_RUNTIME     : Hostboot Runtime (for Sapphire) */
    "HBD",       /**< PNOR::HB_DATA        : Hostboot Data */
    "GUARD",     /**< PNOR::GUARD_DATA     : Hostboot Data */
    "HBEL",      /**< PNOR::HB_ERRLOGS     : Hostboot Error log Repository */
    "DJVPD",     /**< PNOR::DIMM_JEDEC_VPD : Dimm JEDEC VPD */
    "MVPD",      /**< PNOR::MODULE_VPD     : Module VPD */
    "CVPD",      /**< PNOR::CENTAUR_VPD    : Centaur VPD */
    "NVRAM",     /**< PNOR::NVRAM          : OPAL Storage */
    "OCC",       /**< PNOR::OCC            : OCC LID */
    "FIRDATA",   /**< PNOR::FIRDATA        : FIRDATA */
    "ATTR_TMP",  /**< PNOR::ATTR_TMP       : Temporary Attribute Overrides */
    "ATTR_PERM", /**< PNOR::ATTR_PERM      : Permanent Attribute Overrides */
    "CAPP",      /**< PNOR::CAPP           : CAPP LID */
    "VERSION",   /**< PNOR::VERSION        : PNOR Version string */
    "TEST",      /**< PNOR::TEST           : Test space for PNOR*/
    "TESTRO",    /**< PNOR::TESTRO         : ReadOnly Test space for PNOR */
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

/*
 * @brief determine the physical offset of the ffs entry
 *        (to be used before readTOC is called)
 */
void PNOR::findPhysicalOffset(ffs_hdr* i_tocAddress,
                                const char* i_entryName,
                                uint64_t & o_offset)
{
    for(uint32_t i = 0; i < i_tocAddress->entry_count; i++)
    {
        ffs_entry* l_curEntry = (&i_tocAddress->entries[i]);
        if(strcmp(i_entryName,l_curEntry->name) == 0)
        {
            o_offset = ((uint64_t)l_curEntry->base)*PAGESIZE;
            break;
        }
    }
}

/*
 * @brief used to translate mmio offset stored in mbox scratch 2
 *        to physical offset of HBB Image
 */
errlHndl_t  PNOR::mmioToPhysicalOffset(uint64_t& o_hbbAddress)
{
    errlHndl_t l_err = NULL;
    do
    {
#ifndef CONFIG_SFC_IS_FAKE // @FIXME RTC 132398
        uint64_t l_hbbMMIO = 0;
        size_t l_size = sizeof(uint64_t);
        TARGETING::Target* l_masterProc =
            TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

        //MBOX_SCRATCH_REG2 = 0x5003A
        l_err = DeviceFW::deviceRead(l_masterProc, &l_hbbMMIO,l_size,
                DEVICE_SCOM_ADDRESS(SPLESS::MBOX_SCRATCH_REG2));
        if (l_err)
        {
            TRACFCOMP(g_trac_pnor,"PNOR::mmioToPhysicalOffset: Failed to read"
                    " HB MMIO offset");
            break;
        }
        //All SCOMS are 64-bit, HB MMIO is stored in higher 32-bits.
        //ANDing with TOP_OF_FLASH to maskout anything in the higher bits
        l_hbbMMIO    = (l_hbbMMIO >> 32) & PNOR::LPC_TOP_OF_FLASH_OFFSET;
        o_hbbAddress = ((9*l_hbbMMIO) - (9*PNOR::LPC_SFC_MMIO_OFFSET)
                                 - PNOR::PNOR_SIZE) /8;
#else                      // @FIXME RTC 132398
        o_hbbAddress = 1;  // @FIXME RTC 132398
#endif                     // @FIXME RTC 132398
    } while (0);
    return l_err;
}

/*
 * @brief used to translate HBB Address to MMIO offset
 */
void  PNOR::physicalToMmioOffset(uint64_t  i_hbbAddress,
                                 uint64_t& o_mmioOffset)
{
    //Left shifting 32-bits because SCOMS store a 64-bit value
    //and HBB Offset is stored in the higher 32-bits
    o_mmioOffset = ((PNOR::LPC_SFC_MMIO_OFFSET + i_hbbAddress +
                   ((PNOR::PNOR_SIZE - i_hbbAddress)/9)) |
                   PNOR::LPC_FW_SPACE) << 32;
}

/*
 *  @brief: parse the TOCs read from memory and store section information
 *          from one of the verified TOCs
 */
errlHndl_t PNOR::parseTOC(uint8_t* i_toc0Buffer, uint8_t* i_toc1Buffer,
           TOCS & o_TOC_used, SectionData_t * o_TOC, uint64_t i_baseVAddr)
{
    TRACUCOMP(g_trac_pnor,"PNOR::parseTOC>");
    errlHndl_t l_errhdl = NULL;

    bool TOC_0_failed = false;

    do{
        o_TOC_used = TOC_0;

        for (TOCS cur_TOC = TOC_0; cur_TOC < NUM_TOCS;
            cur_TOC = (TOCS)(cur_TOC+1))
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
                if( !i_toc0Buffer )
                {
                    TRACFCOMP(g_trac_pnor, "TOC0 buffer is NULL");
                    TOC_0_failed = true;
                    o_TOC_used = TOC_1;
                    continue;
                }
                l_ffs_hdr = (ffs_hdr*) i_toc0Buffer;
            }
            else if (cur_TOC == 1)
            {
                if( !i_toc1Buffer )
                {
                    TRACFCOMP(g_trac_pnor, "TOC1 buffer is NULL");
                    continue;
                }
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
                    o_TOC_used = TOC_1;
                    continue;
                }
                else if (cur_TOC == TOC_1 && TOC_0_failed)
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
            if (cur_TOC == TOC_0 || TOC_0_failed)
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
                    if (cur_TOC == TOC_0)
                    {
                        TRACFCOMP(g_trac_pnor,"PNOR::parseTOC TOC 0 entry"
                                " checksum failed");
                        TOC_0_failed = true;
                        o_TOC_used = TOC_1;
                        break;
                    }
                    else if (cur_TOC == TOC_1 && TOC_0_failed)
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
                if (cur_TOC == TOC_0 || TOC_0_failed)
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

#ifndef __HOSTBOOT_RUNTIME
                    // Handle section permissions
                    if (o_TOC[secId].misc & FFS_MISC_READ_ONLY)
                    {
                        // Need to set permissions to allow writing to virtual
                        // addresses, but prevents the kernel from ejecting
                        // dirty pages (no WRITE_TRACKED).
                        int rc = mm_set_permission(
                                                (void*)o_TOC[secId].virtAddr,
                                                o_TOC[secId].size,
                                                WRITABLE);
                        if (rc)
                        {
                            TRACFCOMP(g_trac_pnor, "E>PnorRP::readTOC: Failed to set block permissions to WRITABLE for section %s.",
                                      cv_EYECATCHER[secId]);
                            /*@
                            * @errortype
                            * @moduleid PNOR::MOD_PNORRP_READTOC
                            * @reasoncode PNOR::RC_WRITABLE_PERM_FAIL
                            * @userdata1 PNOR section id
                            * @userdata2 PNOR section vaddr
                            * @devdesc Could not set permissions of the
                            * given PNOR section to WRITABLE
                            * @custdesc A problem occurred while reading PNOR partition table
                            */
                            l_errhdl = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORRP_READTOC,
                                            PNOR::RC_WRITABLE_PERM_FAIL,
                                            secId,
                                            o_TOC[secId].virtAddr,
                                            true /*Add HB SW Callout*/);
                            l_errhdl->collectTrace(PNOR_COMP_NAME);
                        }
                    }
                    else
                    {
                        // Need to set permissions to R/W
                        int rc = mm_set_permission(
                                            (void*)o_TOC[secId].virtAddr,
                                            o_TOC[secId].size,
                                            WRITABLE | WRITE_TRACKED);
                        if (rc)
                        {
                            TRACFCOMP(g_trac_pnor, "E>PnorRP::readTOC: Failed to set block permissions to WRITABLE/WRITE_TRACKED for section %s.",
                                      cv_EYECATCHER[secId]);
                            /*@
                            * @errortype
                            * @moduleid PNOR::MOD_PNORRP_READTOC
                            * @reasoncode PNOR::RC_WRITE_TRACKED_PERM_FAIL
                            * @userdata1 PNOR section id
                            * @userdata2 PNOR section vaddr
                            * @devdesc Could not set permissions of the
                            * given PNOR section to
                            * WRITABLE/WRITE_TRACKED
                            * @custdesc A problem occurred while reading
                            * PNOR partition table
                            */
                            l_errhdl = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORRP_READTOC,
                                            PNOR::RC_WRITE_TRACKED_PERM_FAIL,
                                            secId,
                                            o_TOC[secId].virtAddr,
                                            true /*Add HB SW Callout*/);
                            l_errhdl->collectTrace(PNOR_COMP_NAME);
                        }
                    }
#endif
                    if( l_errhdl )
                    {
                        // If both toc0 and toc1 fail break and return the error
                        if ( (cur_TOC == TOC_1) && (TOC_0_failed) )
                        {
                            TRACFCOMP(g_trac_pnor, "PNOR::parseTOC readFromDevice Failed on both TOCs");
                            break;
                        }

                        // Toc 1 has not been read yet or Toc 0 was read
                        // successfully
                        // Commit error and break to continue checking the next
                        // TOC
                        else
                        {
                            TRACFCOMP(g_trac_pnor, "PNOR::parseTOC readFromDevice Failed on TOC %d, commit error",
                                      cur_TOC);
                            errlCommit(l_errhdl,PNOR_COMP_ID);
                            l_errhdl = NULL;
                            break;
                        }
                    }
                }
            } // For TOC Entries
            if (l_errhdl)
            {
                break;
            }
            if (!TOC_0_failed)
            {
                //if we find a working TOC we don't need to loop again.
                //In runtime case, OPAL returns a working TOC.
                //So, we don't want to look at the second one.
                break;
            }
        } // For TOC's
        if (l_errhdl)
        {
            break;
        }
    } while(0);

    for(PNOR::SectionId tmpId = PNOR::FIRST_SECTION;
        tmpId < PNOR::NUM_SECTIONS;
        tmpId = (PNOR::SectionId) (tmpId + 1) )
    {
        TRACFCOMP(g_trac_pnor, "%s:    size=0x%.8X  flash=0x%.8X  "
               "virt=0x%.16X", cv_EYECATCHER[tmpId], o_TOC[tmpId].size,
               o_TOC[tmpId].flashAddr, o_TOC[tmpId].virtAddr );
    }

    TRACUCOMP(g_trac_pnor, "< PNOR::parseTOC" );
    return l_errhdl;
}

