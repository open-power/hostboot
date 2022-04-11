/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnor_common.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2022                        */
/* [+] Google Inc.                                                        */
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
#include <secureboot/trustedbootif.H>
#include <devicefw/driverif.H>

#ifndef __HOSTBOOT_RUNTIME
#include <kernel/bltohbdatamgr.H>
#else
#include <targeting/common/targetservice.H>
#include <targeting/common/target.H>
#include <util/misc.H>
#endif

#ifdef CONFIG_FILE_XFER_VIA_PLDM
#include <pnor/pnor_pldm_utils.H>
#include <openbmc/pldm/oem/ibm/libpldm/file_io.h>
#include <pldm/requests/pldm_fileio_requests.H>
#include <pldm/base/hb_bios_attrs.H>
#include <pldm/pldm_errl.H>
#endif

// Trace definition
trace_desc_t* g_trac_pnor = NULL;

#ifndef __HOSTBOOT_RUNTIME
// If this is IPL time code, initialize the trace buffer as normal. If this is
// runtime code, we need to ensure that this is initialized before the RtPnor
// instance, so we explicitly sequence the initialization ourselves in rt_pnor.C
TRAC_INIT(&g_trac_pnor, PNOR_COMP_NAME, 4*KILOBYTE, TRACE::BUFFER_SLOW); //4K
#endif

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)


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
 * @brief used to translate mmio offset stored in mbox scratch 3
 *        to physical offset of HBB Image
 */
errlHndl_t  PNOR::mmioToPhysicalOffset(uint64_t& o_hbbAddress)
{
    errlHndl_t l_err = NULL;
    do
    {
#if 0 // @FIXME RTC 132398
        uint64_t l_hbbMMIO = 0;
        size_t l_size = sizeof(uint64_t);
        TARGETING::Target* l_masterProc =
            TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

        //MBOX_SCRATCH_REG3 = 0x5003A
        l_err = DeviceFW::deviceRead(l_masterProc, &l_hbbMMIO,l_size,
                   DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MBOX_SCRATCH_REG3));
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

#ifdef CONFIG_PNOR_INIT_FOUR_BYTE_ADDR
        // If the PNOR came up in 3-byte mode, then make sure to mask off
        // the address appropriately.
        o_hbbAddress &= 0x00ffffffu;
#endif

#else                      // @FIXME RTC 132398
        o_hbbAddress = 1;  // @FIXME RTC 132398
#endif
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
errlHndl_t PNOR::parseTOC( uint8_t* i_tocBuffer,SectionData_t * o_TOC,
                           bool i_pnorInitialized )
{
    TRACUCOMP(g_trac_pnor,"PNOR::parseTOC>");
    errlHndl_t l_errhdl = NULL;

    do{
        // Zero out my table
        PNOR::initializeSections(o_TOC);

        uint32_t l_errCode(0);
        ffs_hdr* l_ffs_hdr(reinterpret_cast<ffs_hdr*>(i_tocBuffer));

        TRACDCOMP(g_trac_pnor, "PNOR::parseTOC verifying TOC");
        if (!l_ffs_hdr)
        {
            l_errCode = PNOR::BUFF_IS_NULL;
            l_ffs_hdr = nullptr;
        }

        //Check if the buffer is null
        if(l_errCode != NO_ERROR)
        {
            TRACFCOMP(g_trac_pnor, "Null TOC Buffer found while checking TOC" );

            // prevent hang between ErrlManager and Pnor
            assert(i_pnorInitialized,
                   "Null TOC Buffer found while checking TOC"
                   " during pnor initialization");
            /*@
            * @errortype
            * @moduleid PNOR::MOD_PNORRP_READTOC
            * @reasoncode PNOR::RC_NULL_TOC_BUFFER
            * @userdata1 Address of toc buffer
            * @userdata2 Error code
            * @devdesc Expected buffer to have contents of TOC,
            *                      instead was NULL
            * @custdesc A problem occurred while reading
            *           Processor NOR flash partition table
            */
            l_errhdl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    PNOR::MOD_PNORRP_READTOC,
                                    PNOR::RC_NULL_TOC_BUFFER,
                                    reinterpret_cast<uint64_t>(&i_tocBuffer),
                                    l_errCode,
                                    true /*Add HB SW Callout*/);
            l_errhdl->collectTrace(PNOR_COMP_NAME);
            break;
        }


        if(PNOR::pnor_ffs_checksum(l_ffs_hdr, FFS_HDR_SIZE) != 0)
        {
            l_errCode |= CHECKSUM_ERR;
        }

        //Checksum on header
        if (l_errCode != NO_ERROR)
        {
            TRACFCOMP(g_trac_pnor, "PNOR::parseTOC Checksum error in TOC's header");

            // prevent hang between ErrlManager and Pnor
            assert(i_pnorInitialized,
                      "PNOR::parseTOC Found checksum error in TOC's header"
                      " during pnor initialization");

            /*@
            * @errortype
            * @moduleid PNOR::MOD_PNORRP_READTOC
            * @reasoncode PNOR::RC_TOC_HDR_CHECKSUM_ERR
            * @userdata1 Address of toc buffer
            * @userdata2 Error Code
            * @devdesc Hdr of TOC of PNOR failed checksum
            * @custdesc A problem occurred while reading
            *           Processor NOR flash partition table
            */
            l_errhdl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    PNOR::MOD_PNORRP_READTOC,
                                    PNOR::RC_TOC_HDR_CHECKSUM_ERR,
                                    reinterpret_cast<uint64_t>(&i_tocBuffer),
                                    l_errCode,
                                    false );
            l_errhdl->addPartCallout(
                            TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                            HWAS::PNOR_PART_TYPE,
                            HWAS::SRCI_PRIORITY_HIGH);
            l_errhdl->collectTrace(PNOR_COMP_NAME);
            break;
        }

        PNOR::checkHeader(l_ffs_hdr, l_errCode);
        if(l_errCode != NO_ERROR)
        {
            TRACFCOMP(g_trac_pnor, "PNOR::parseTOC Error found parsing hdr of TOC" );

            // prevent hang between ErrlManager and Pnor
            assert(i_pnorInitialized,
                      "PNOR::parseTOC Error found parsing hdr of TOC"
                      " during pnor initialization");
            /*@
            * @errortype
            * @moduleid PNOR::MOD_PNORRP_READTOC
            * @reasoncode PNOR::RC_BAD_TOC_HEADER
            * @userdata1 Address of toc buffer
            * @userdata2 Error Code
            * @devdesc Hdr of TOC of PNOR failed series of tests
            * @custdesc A problem occurred while reading
            *           Processor NOR flash partition table
            */
            l_errhdl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    PNOR::MOD_PNORRP_READTOC,
                                    PNOR::RC_BAD_TOC_HEADER,
                                    reinterpret_cast<uint64_t>(&i_tocBuffer),
                                    l_errCode,
                                    false );
            l_errhdl->addPartCallout(
                            TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                            HWAS::PNOR_PART_TYPE,
                            HWAS::SRCI_PRIORITY_HIGH);
            l_errhdl->collectTrace(PNOR_COMP_NAME);
            break;
        }

        TRACDCOMP(g_trac_pnor, "PNOR::parseTOC: FFS Block size=0x%.8X,"
        " Partition Table Size = 0x%.8x, entry_count=%d",
        l_ffs_hdr->block_size,l_ffs_hdr->size,l_ffs_hdr->entry_count);

        ffs_entry* l_err_entry = NULL;

        l_errhdl = PNOR::parseEntries(l_ffs_hdr, l_errCode, o_TOC, l_err_entry);
        if (l_errhdl)
        {
            TRACFCOMP(g_trac_pnor, "PNOR::parseTOC parseEntries returned an error log");
            break;
        }
        else if(l_errCode != NO_ERROR)
        {
            TRACFCOMP(g_trac_pnor, "PNOR::parseTOC parseEntries returned an error code");
            o_TOC = NULL;

            // prevent hang between ErrlManager and Pnor
            assert(i_pnorInitialized,
                    "PNOR::parseTOC parseEntries returned an error code"
                    " during pnor initialization");

            /*@
            * @errortype
            * @moduleid PNOR::MOD_PNORRP_READTOC
            * @reasoncode PNOR::RC_PNOR_PARSE_ENTRIES_ERR
            * @userdata1 Address of toc buffer
            * @userdata2 Error Code
            * @devdesc Error while parsing pnor TOC entries
            * @custdesc A problem occurred while reading
            *           Processor NOR flash partition table
            */
            l_errhdl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    PNOR::MOD_PNORRP_READTOC,
                                    PNOR::RC_PNOR_PARSE_ENTRIES_ERR,
                                    reinterpret_cast<uint64_t>(&i_tocBuffer),
                                    l_errCode,
                                    true /*Add HB SW Callout*/);
            l_errhdl->addPartCallout(
                            TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                            HWAS::PNOR_PART_TYPE,
                            HWAS::SRCI_PRIORITY_HIGH);
            l_errhdl->collectTrace(PNOR_COMP_NAME);
            TRACFBIN(g_trac_pnor, "Entry in TOC that caused error during parsing", l_err_entry, FFS_ENTRY_SIZE);
            break;
        }


        //Walk through all the entries in the table and record some info
        for(uint32_t i=0; i<l_ffs_hdr->entry_count; i++)
        {
            PNOR::SectionId l_secId = PNOR::INVALID_SECTION;
            ffs_entry* cur_entry = &(l_ffs_hdr->entries[i]);
            TRACUCOMP(g_trac_pnor, "PNOR::parseTOC: TOC %d,  Entry %d, name=%s, pointer=0x%X",l_tocBeingChecked, i,cur_entry->name, (uint64_t)cur_entry);

            //Figure out section enum
            PNOR::getSectionEnum(cur_entry, &l_secId);
            if(l_secId == PNOR::INVALID_SECTION)
            {
              TRACFCOMP(g_trac_pnor, "PNOR::parseTOC:  Unrecognized Section name(%s), skipping",cur_entry->name);
              continue;
            }

            TRACUCOMP(g_trac_pnor,"PNOR::parseTOC: User Data %s",
                      cur_entry->name);

            if (o_TOC[l_secId].integrity == FFS_INTEG_ECC_PROTECT)
            {
              TRACUCOMP(g_trac_pnor, "PNOR::TOC: ECC enabled for %s",
                              cur_entry->name);

            }
        }

        for(int tmpId = 0;
        tmpId < PNOR::NUM_SECTIONS;
        tmpId ++ )
        {
            TRACFCOMP(g_trac_pnor, "%s:    secure=0x%.2X  size=0x%.8X  flash=0x%.8X misc=0x%.2X",
                  PNOR::SectionIdToString(tmpId), o_TOC[tmpId].secure,
                  o_TOC[tmpId].size, o_TOC[tmpId].flashAddr, o_TOC[tmpId].misc);
        }

    } while (0);

    TRACUCOMP(g_trac_pnor, "< PNOR::parseTOC" );
    return l_errhdl;
}

bool PNOR::isInhibitedSection(const uint32_t i_section)
{
#ifdef CONFIG_SECUREBOOT
    bool retVal = false;

    if ((i_section == ATTR_PERM ||
         i_section == ATTR_TMP  ||
         i_section == RINGOVD )
         && SECUREBOOT::enabled() )
    {
        // Default to these sections not being allowed in secure mode
        retVal = true;


#ifndef __HOSTBOOT_RUNTIME
        // This is the scenario where a section might be inhibited so check
        // global struct from bootloader for this setting
        retVal = ! ( g_BlToHbDataManager.getAllowAttrOverrides() );

        TRACFCOMP(g_trac_pnor, INFO_MRK"PNOR::isInhibitedSection: "
                  "Inside Attr check: retVal=0x%X, i_section=%s",
                  retVal,
                  PNOR::SectionIdToString(i_section));

#else
        // This is the scenario where a section might be inhibited so check
        // attribute to determine if these sections are allowed
        if ( Util::isTargetingLoaded() )
        {
            TARGETING::TargetService& tS = TARGETING::targetService();
            TARGETING::Target* sys = nullptr;
            (void) tS.getTopLevelTarget( sys );
            assert(sys, "PNOR::isInhibitedSection() system target is NULL");

            retVal = ! (sys->getAttr<
                TARGETING::ATTR_ALLOW_ATTR_OVERRIDES_IN_SECURE_MODE>());

            TRACFCOMP(g_trac_pnor, INFO_MRK"PNOR::isInhibitedSection: "
                      "Inside Attr check: retVal=0x%X, attr=0x%X, i_section=%s",
                      retVal,
                      sys->getAttr<
                        TARGETING::ATTR_ALLOW_ATTR_OVERRIDES_IN_SECURE_MODE>(),
                      PNOR::SectionIdToString(i_section));
       }
#endif

    }

    return retVal;
#else
    return false;
#endif
}

bool PNOR::isSectionEmpty(const PNOR::SectionId i_section)
{
    errlHndl_t l_errhdl = nullptr;
    bool l_result = true;

    PNOR::SectionInfo_t l_sectionInfo;
    l_errhdl = PNOR::getSectionInfo( i_section, l_sectionInfo );
    if (l_errhdl)
    {
        // If section is not in PNOR, just delete error and return false
        delete l_errhdl;
        l_errhdl = nullptr;
    }
    else
    {
        std::array<uint8_t,PAGESIZE> empty_buffer{};
        // Empty ECC sections are filled with 0xFF's to ensure good ECC
        if (l_sectionInfo.eccProtected)
        {
            empty_buffer.fill(0xFF);
        }

        l_result = memcmp(&empty_buffer,
                          reinterpret_cast<uint8_t*>(l_sectionInfo.vaddr),
                          sizeof(empty_buffer)) ==0;
    }

    TRACFCOMP(g_trac_pnor, "PNOR::isSectionEmpty: i_section=%s isSectionEmpty=%d",
              PNOR::SectionIdToString(i_section), l_result);

    return l_result;
}

#ifdef CONFIG_FILE_XFER_VIA_PLDM

errlHndl_t sectionIdFileTableLookup( const PNOR::SectionId i_secId,
                                     const std::vector<uint8_t> & i_fileTable,
                                     const std::array<uint32_t, PNOR::NUM_SECTIONS> & i_lid_ids,
                                     pldm_file_attr_table_entry *& o_tableEntryPtr)
{
    using namespace PLDM_PNOR;
    errlHndl_t errl = nullptr;
    do
    {
        /* See PLDM for File Based I/O document for details */
        // Up to 3 bytes of padding are added to the end of the table
        // to make table 4 byte aligned. This is needed to correctly append
        // the CRC32 checksum at the end of the entire table. Together
        // these will be up to 7 bytes.
        const size_t CHKSUM_PADDING = 7;
        auto start_ptr = const_cast<uint8_t *>(i_fileTable.data());
        auto end_ptr = start_ptr + i_fileTable.size() - CHKSUM_PADDING;
        bool match_found = false;
        o_tableEntryPtr = nullptr;

        uint32_t lid_id = 0;
        errl = sectionIdToLidId(i_secId, lid_id, i_lid_ids);
        if(errl)
        {
            TRACFCOMP(g_trac_pnor,
                      "sectionIdFileTableLookup> An error occurred looking up the lid id mapped to SectionId %d"
                      TRACE_ERR_FMT,
                      i_secId,
                      TRACE_ERR_ARGS(errl));
            break;
        }

        while(start_ptr < end_ptr)
        {
            o_tableEntryPtr =
              reinterpret_cast<pldm_file_attr_table_entry *>(start_ptr);

            const size_t NAME_SZ = 8;
            char entry_lid_ascii[NAME_SZ+1] = {0};
            strncpy(entry_lid_ascii,
                    const_cast<const char *>(reinterpret_cast<char *>(&o_tableEntryPtr->file_attr_table_nst[0])),
                    NAME_SZ);
            entry_lid_ascii[NAME_SZ] = '\0';
            auto entry_lid_id = strtoul(reinterpret_cast<char *>(&entry_lid_ascii[0]), nullptr, 16);

            if(entry_lid_id == lid_id)
            {
                match_found = true;
                break;
            }
            else
            {
                start_ptr += sizeof(o_tableEntryPtr->file_handle);
                start_ptr += sizeof(o_tableEntryPtr->file_name_length);
                start_ptr += le16toh(o_tableEntryPtr->file_name_length);
                start_ptr += sizeof(uint32_t); // FileSize
                start_ptr += sizeof(uint32_t); // FileTraits
            }
        }

        if(!match_found)
        {
            o_tableEntryPtr = nullptr;
        }
    }while(0);

    return errl;
}

errlHndl_t PNOR::populateTOC( SectionData_t * o_TOC ,
                              std::array<uint32_t, PNOR::NUM_SECTIONS> & i_lid_ids,
                              bool i_pnorInitialized)
{
    std::vector<uint8_t> file_table;
    errlHndl_t l_errhdl = nullptr;

    do{

        l_errhdl = PLDM::getFileTable(file_table);
        if(l_errhdl)
        {
            TRACFCOMP(g_trac_pnor, "An error occurred when we requested the PLDM file table from the BMC");
            break;
        }

        // Use the file table to lookup information for each
        // section listed in the enum SectionId defined in pnor_const.H
        static_assert(PNOR::NUM_SECTIONS == i_lid_ids.size(),
              "SectionId will over run lid mapping list");

        for(size_t i = 0; i < NUM_SECTIONS; i++)
        {
            auto section_id = static_cast<SectionId>(i);
            o_TOC[i].id        = section_id;

            if(i_lid_ids[section_id] == PLDM_PNOR::INVALID_LID)
            {
                TRACFCOMP(g_trac_pnor, "populateTOC> Skipping lid %d", section_id);
                // If there is no lid associated with this section
                // then skip this pnor section
                continue;
            }
            o_TOC[i].flashAddr = i * VMM_SIZE_RESERVED_PER_SECTION;
            o_TOC[i].virtAddr  = o_TOC[i].flashAddr | VMM_VADDR_PNOR_RP;
            o_TOC[i].chip      = 0; // always default to chip 0

            pldm_file_attr_table_entry * file_table_entry = nullptr;
            l_errhdl = sectionIdFileTableLookup(section_id,
                                                file_table,
                                                i_lid_ids,
                                                file_table_entry);

            if(l_errhdl)
            {
                TRACFCOMP(g_trac_pnor,
                          "populateTOC> An error occurred looking up SectionId %d in the PLDM file table"
                          TRACE_ERR_FMT,
                          section_id,
                          TRACE_ERR_ARGS(l_errhdl));
                break;
            }

            if(file_table_entry == nullptr)
            {
                /*@
                * @errortype
                * @moduleid     PNOR::MOD_POPULATE_TOC
                * @reasoncode   PNOR::RC_INVALID_SECTION
                * @userdata1    Section ID we are looking up
                * @userdata2    unused
                * @devdesc      PnorRP::populateTOC> Could not find section id in PLDM file table
                * @custdesc     A problem occurred while accessing the boot firmware.
                */
                l_errhdl = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              PNOR::MOD_POPULATE_TOC,
                              PNOR::RC_INVALID_SECTION,
                              section_id,
                              0,
                              ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
                TRACFCOMP(g_trac_pnor,
                          "populateTOC> Could not find section id in PLDM file table %d"
                          TRACE_ERR_FMT,
                          section_id,
                          TRACE_ERR_ARGS(l_errhdl));
                l_errhdl->collectTrace(PNOR_COMP_NAME);
                PLDM::addBmcErrorCallouts(l_errhdl);
                break;
            }

            // file's name, size, and traits
            uint8_t * entry_nst = &(file_table_entry->file_attr_table_nst[0]);

            o_TOC[i].size =
                le32toh(*reinterpret_cast<uint32_t *>(entry_nst +
                                              le16toh(file_table_entry->file_name_length)));
            if( o_TOC[i].size > VMM_SIZE_RESERVED_PER_SECTION)
            {
                /*@
                * @errortype
                * @moduleid     PNOR::MOD_POPULATE_TOC
                * @reasoncode   PNOR::RC_SECTION_SIZE_IS_BIG
                * @userdata1    Section
                * @userdata2    Section Size
                * @devdesc      File size reported by BMC is larger than our max supported.
                * @custdesc     A problem occurred accessing boot firmware.
                */
                l_errhdl = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              PNOR::MOD_POPULATE_TOC,
                              PNOR::RC_SECTION_SIZE_IS_BIG,
                              i,
                              o_TOC[i].size,
                              ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
                TRACFCOMP(g_trac_pnor,
                          "populateTOC> Size reported by bmc is larger (0x%x) than we can handle (0x%x) for section %d"
                          TRACE_ERR_FMT,
                          o_TOC[i].size,
                          VMM_SIZE_RESERVED_PER_SECTION,
                          section_id,
                          TRACE_ERR_ARGS(l_errhdl));
                l_errhdl->collectTrace(PNOR_COMP_NAME);
                PLDM::addBmcErrorCallouts(l_errhdl);
                break;
            }
            auto entry_traits =
                le32toh(*reinterpret_cast<uint32_t *>(entry_nst +
                                              le16toh(file_table_entry->file_name_length) +
                                              sizeof(uint32_t)));

            if(entry_traits & PLDM_PNOR::READ_ONLY)
            {
                o_TOC[i].misc |= FFS_MISC_READ_ONLY;
            }

            o_TOC[i].secure = PNOR::isEnforcedSecureSection(i);
        }
    }while(0);

    if(l_errhdl)
    {
        // prevent hang between ErrlManager and Pnor
        assert(i_pnorInitialized,
                "Failed to get file table from BMC "
                " during pnor initialization");
    }
    return l_errhdl;
}

#endif
