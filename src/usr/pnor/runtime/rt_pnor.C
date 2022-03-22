/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/runtime/rt_pnor.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2022                        */
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

#include <stdlib.h>
#include <stdio.h>
#include <targeting/common/targetservice.H>
#include <initservice/taskargs.H>
#include <initservice/initserviceif.H>

#include <targeting/runtime/rt_targeting.H>
#include <runtime/interface.h>   // g_hostInterfaces, postInitCalls_t

#include <pnor/pnorif.H>
#include <pnor/ecc.H>
#include <pnor/pnor_reasoncodes.H>
#include "rt_pnor.H"

#include "../ffs.h"
#include "../common/ffs_hb.H"
#include <util/align.H>
#include <runtime/customize_attrs_for_payload.H>
#include <securerom/ROM.H>
#include "../pnor_utils.H"
#include <runtime/common/runtime_utils.H>

#ifdef CONFIG_FILE_XFER_VIA_PLDM
#include <pldm/base/hb_bios_attrs.H>
#include <pldm/requests/pldm_fileio_requests.H>
#include <pnor/pnor_pldm_utils.H>
#endif

// Trace definition
extern trace_desc_t* g_trac_pnor;

/**
 * @brief  Return the size and address of a given section of PNOR data
 */
errlHndl_t PNOR::getSectionInfo( PNOR::SectionId i_section,
                                 PNOR::SectionInfo_t& o_info )
{
    return Singleton<RtPnor>::instance().getSectionInfo(i_section,o_info);
}

/**
 * @brief  Write the data for a given section into PNOR
 */
errlHndl_t PNOR::flush (const PNOR::SectionId i_section,
                        void* const i_vaddr,
                        const size_t i_num_pages)
{
    return Singleton<RtPnor>::instance().flush(i_section, i_vaddr, i_num_pages);
}

/**
 * @brief  Returns information about a given side of PNOR
 */
errlHndl_t PNOR::getSideInfo( PNOR::SideId i_side,
                              PNOR::SideInfo_t& o_info)
{
    return Singleton<RtPnor>::instance().getSideInfo(i_side,o_info);
}

/**
 * @brief Clear pnor section
 */
errlHndl_t PNOR::clearSection(PNOR::SectionId i_section)
{
    return Singleton<RtPnor>::instance().clearSection(i_section);
}

void PNOR::getPnorInfo( PnorInfo_t& o_pnorInfo )
{
    o_pnorInfo.mmioOffset = LPC_SFC_MMIO_OFFSET | LPC_FW_SPACE;

    //Using sys target
    TARGETING::Target* sys = nullptr;
    TARGETING::targetService().getTopLevelTarget( sys );
    assert(sys != nullptr);

    o_pnorInfo.norWorkarounds = sys->getAttr<
            TARGETING::ATTR_PNOR_FLASH_WORKAROUNDS>();

#ifdef CONFIG_PNOR_IS_32MB
    o_pnorInfo.flashSize = 32*MEGABYTE;
#else
    o_pnorInfo.flashSize = 64*MEGABYTE;
#endif

}

#ifdef CONFIG_FILE_XFER_VIA_PLDM
const std::array<uint32_t, PNOR::NUM_SECTIONS>& PNOR::getLidIds()
{
    return Singleton<RtPnor>::instance().get_lid_ids();
}
#endif

/****************Public Methods***************************/

uint64_t RtPnor::iv_masterProcId = RUNTIME::HBRT_HYP_ID_UNKNOWN;

/**
 * STATIC
 * @brief Static Initializer
 */
void RtPnor::init(errlHndl_t &io_taskRetErrl)
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK"RtPnor::init()");

    Singleton<RtPnor>::instance().setInitialized(true);

    TRACFCOMP(g_trac_pnor, EXIT_MRK"RtPnor::init()");
}

/**************************************************************/
void RtPnor::setInitialized(bool i_initialized)
{
  iv_initialized = i_initialized;
}

/**************************************************************/
errlHndl_t RtPnor::getSectionInfo(PNOR::SectionId i_section,
                              PNOR::SectionInfo_t& o_info)
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK"RtPnor::getSectionInfo %d, initialized = %d", i_section, iv_initialized?1:0);
    errlHndl_t l_err = nullptr;
    do
    {
        // Check if Section is invalid or inhibited from loading at runtime.
        bool l_inhibited = false;
        bool l_secure = PNOR::isEnforcedSecureSection(i_section);
        bool l_preVerified = RUNTIME::isPreVerifiedSection(i_section);
#ifdef CONFIG_SECUREBOOT
        l_inhibited = PNOR::isInhibitedSection(i_section);
#endif
        if (i_section == PNOR::INVALID_SECTION || l_inhibited || l_secure ||
            l_preVerified)
        {
            TRACFCOMP(g_trac_pnor, "RtPnor::getSectionInfo: Invalid Section %d",
                      static_cast<int>(i_section));

            if (l_preVerified)
            {
                TRACFCOMP(g_trac_pnor, ERR_MRK"RtPnor::getSectionInfo: pre-verified sections should be loaded via Hostboot Reserved Memory ");
            }
#ifdef CONFIG_SECUREBOOT
            else if (l_inhibited)
            {
                TRACFCOMP(g_trac_pnor, ERR_MRK"RtPnor::getSectionInfo: attribute overrides inhibited by secureboot");
            }
            else if (l_secure)
            {
                TRACFCOMP(g_trac_pnor, ERR_MRK"RtPnor::getSectionInfo: secure sections should be loaded via Hostboot Reserved Memory");
            }
#endif

            /*@
             * @errortype
             * @moduleid    PNOR::MOD_RTPNOR_GETSECTIONINFO
             * @reasoncode  PNOR::RC_RTPNOR_INVALID_SECTION
             * @userdata1   PNOR::SectionId
             * @userdata2[0:15]   Inhibited by secureboot
             * @userdata2[16:31]  Indication of a secure section
             * @userdata2[32:47]  Indication of a pre-verified section
             * @userdata2[48:63]  0
             * @devdesc     invalid section passed to getSectionInfo  or
             *              section prohibited by secureboot
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_RTPNOR_GETSECTIONINFO,
                                            PNOR::RC_RTPNOR_INVALID_SECTION,
                                            i_section,
                                            FOUR_UINT16_TO_UINT64(l_inhibited,
                                                                  l_secure,
                                                                  l_preVerified,
                                                                  0),
                                            true);
            break;
        }

        //size of the section
        uint64_t l_sizeBytes = iv_TOC[i_section].size;

        if (l_sizeBytes == 0)
        {
            TRACFCOMP(g_trac_pnor,"RtPnor::getSectionInfo: Section %d"
                    " size is 0", static_cast<int>(i_section));

            // prevent hang between ErrlManager and rt_pnor
            assert(iv_initialized,
                   "RtPnor::getSectionInfo: Section size 0 returned"
                   " before completing PNOR initialization");
            /*@
             * @errortype
             * @moduleid    PNOR::MOD_RTPNOR_GETSECTIONINFO
             * @reasoncode  PNOR::RC_SECTION_SIZE_IS_ZERO
             * @userdata1   PNOR::SectionId
             * @devdesc     section size is zero
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_RTPNOR_GETSECTIONINFO,
                                            PNOR::RC_SECTION_SIZE_IS_ZERO,
                                            i_section, 0,true);
            break;
        }

        //ecc
        bool l_ecc = (iv_TOC[i_section].integrity&FFS_INTEG_ECC_PROTECT) ?
                      true : false;

        void* l_pWorking = nullptr;
        void* l_pClean   = nullptr;

        //find the section in the map first
        if(iv_pnorMap.find(i_section) != iv_pnorMap.end())
        {
            //get the addresses from the map
            PnorAddrPair_t l_addrPair = iv_pnorMap[i_section];
            l_pWorking = l_addrPair.first;
            l_pClean   = l_addrPair.second;
        }
        else
        {
            //malloc twice -- one working copy and one clean copy
            //So, we can diff and write only the dirty bytes
            l_pWorking = malloc(l_sizeBytes);
            l_pClean   = malloc(l_sizeBytes);

            //offset = 0 : read the entire section
            l_err = readFromDevice(iv_masterProcId, i_section, 0, l_sizeBytes,
                                   l_ecc, l_pWorking);
            if(l_err)
            {
                TRACFCOMP(g_trac_pnor, "RtPnor::getSectionInfo:readFromDevice"
                      " failed");
                break;
            }

            //copy data to another pointer to save a clean copy of data
            memcpy(l_pClean, l_pWorking, l_sizeBytes);

            //save it in the map
            iv_pnorMap [i_section] = PnorAddrPair_t(l_pWorking, l_pClean);
        }
        //return the data in the struct
        o_info.id           = i_section;
        o_info.name         = SectionIdToString(i_section);
        o_info.vaddr        = reinterpret_cast<uint64_t>(l_pWorking);
        o_info.flashAddr    = iv_TOC[i_section].flashAddr;
        o_info.size         = l_sizeBytes;
        o_info.eccProtected = l_ecc;
        o_info.sha512Version=
            (iv_TOC[i_section].version & FFS_VERS_SHA512) ? true : false;
        o_info.sha512perEC  =
           (iv_TOC[i_section].version & FFS_VERS_SHA512_PER_EC) ? true : false;
        o_info.secure = iv_TOC[i_section].secure;
    } while (0);

    TRACFCOMP(g_trac_pnor, EXIT_MRK"RtPnor::getSectionInfo %d", i_section);
    return l_err;
}

/**************************************************************/
errlHndl_t RtPnor::flush (const PNOR::SectionId i_section,
                          void* i_vaddr,
                          const size_t i_num_pages)
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK"RtPnor::flush");
    errlHndl_t l_err = nullptr;
    do
    {
        if (i_section == PNOR::INVALID_SECTION)
        {
            TRACFCOMP(g_trac_pnor,"RtPnor::flush: Invalid Section: %d",
                    (int)i_section);
            /*@
             * @errortype
             * @moduleid    PNOR::MOD_RTPNOR_FLUSH
             * @reasoncode  PNOR::RC_INVALID_SECTION
             * @userdata1   PNOR::SectionId
             * @devdesc     invalid section passed to flush
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_RTPNOR_FLUSH,
                                            PNOR::RC_INVALID_SECTION,
                                            i_section, 0,true);
            break;
        }
        size_t l_sizeBytes = iv_TOC[i_section].size;
        if (l_sizeBytes == 0)
        {
            TRACFCOMP(g_trac_pnor,"RtPnor::flush: Section %d"
                " size is 0", (int)i_section);

            /*@
             * @errortype
             * @moduleid    PNOR::MOD_RTPNOR_FLUSH
             * @reasoncode  PNOR::RC_SECTION_SIZE_IS_ZERO
             * @userdata1   PNOR::SectionId
             * @devdesc     section size is zero
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_RTPNOR_FLUSH,
                                            PNOR::RC_SECTION_SIZE_IS_ZERO,
                                            i_section, 0,true);
            break;
        }

        //get the saved pointers for the partitionName
        PnorAddrMap_t::iterator l_it = iv_pnorMap.find(i_section);
        if(l_it == iv_pnorMap.end())
        {
            TRACFCOMP(g_trac_pnor,"RtPnor::flush: section %d has not been read before",
                      i_section);
            break;
        }
        PnorAddrPair_t l_addrPair = l_it->second;
        uint8_t* l_pWorking = reinterpret_cast<uint8_t*>(l_addrPair.first);
        uint8_t* l_pClean   = reinterpret_cast<uint8_t*>(l_addrPair.second);
        uint8_t* const l_pWorkingEnd = l_pWorking + l_sizeBytes;
        size_t starting_page_index = 0;
        size_t max_pages_to_flush = UINT64_MAX;

        // Round start address down to nearest page
        i_vaddr = reinterpret_cast<uint8_t*>(ALIGN_PAGE_DOWN(reinterpret_cast<uintptr_t>(i_vaddr)));

        // Adjust working and clean pointers to start where the user requested
        if (i_vaddr && l_pWorking <= i_vaddr && i_vaddr < l_pWorking + l_sizeBytes)
        {
            const size_t starting_offset = static_cast<uint8_t*>(i_vaddr) - l_pWorking;
            l_pWorking += starting_offset;
            l_pClean += starting_offset;
            starting_page_index = starting_offset / PAGE_SIZE;
            max_pages_to_flush = i_num_pages ? i_num_pages : UINT64_MAX;
        }

        //ecc
        bool l_ecc = (iv_TOC[i_section].integrity&FFS_INTEG_ECC_PROTECT) ?
                            true : false;

        //find the diff between each pointer
        //write back to pnor what doesn't match
        TRACFCOMP(g_trac_pnor, "finding diff between working and clean copy...");
        for (size_t page_index = starting_page_index;
             l_pWorking < l_pWorkingEnd
                 && page_index - starting_page_index < max_pages_to_flush;
             ++page_index)
        {
            if (0 != memcmp(l_pWorking, l_pClean, PAGESIZE))
            {
                TRACFCOMP(g_trac_pnor, "RtPnor::flush: page %d is different,"
                        " writing back to pnor", page_index);
                l_err = writeToDevice(iv_masterProcId, i_section,
                                      page_index*PAGESIZE,PAGESIZE, l_ecc, l_pWorking);
                if (l_err)
                {
                    TRACFCOMP(g_trac_pnor, "RtPnor::flush: writeToDevice failed");
                    break;
                }
                //update the clean copy
                memcpy(l_pClean, l_pWorking, PAGESIZE);
            }
            l_pWorking += PAGESIZE;
            l_pClean   += PAGESIZE;
        }

        if (l_err)
        {
            TRACFCOMP(g_trac_pnor,"RtPnor::flush: error writing section %d"
                    " back to pnor",(int)i_section);
            break;
        }
    } while (0);

    TRACFCOMP(g_trac_pnor, EXIT_MRK"RtPnor::flush");
    return l_err;
}
/*******Protected Methods**************/
RtPnor::RtPnor()
{
    TRACFCOMP(g_trac_pnor, "RtPnor()::RtPnor()");
    iv_initialized = false;
    errlHndl_t l_err = nullptr;
    do {
        errlHndl_t l_err = getMasterProcId();
        if (l_err)
        {
            TRACFCOMP(g_trac_pnor, "RtPnor(): getMasterProcId returned an error");
            break;
        }
#ifndef CONFIG_FILE_XFER_VIA_PLDM
          l_err = readTOC();
          if (l_err)
          {
              TRACFCOMP(g_trac_pnor, "RtPnor(): readTOC returned an error");
              break;
          }
#else

        l_err = PLDM_PNOR::parse_ipl_lid_ids(iv_ipltime_lid_ids);
        if(l_err)
        {
            TRACFCOMP(g_trac_pnor, "RtPnor(): An error occurred when trying to get the ipl-time lid ids from the BMC");
            break;
        }

        l_err = PLDM_PNOR::parse_rt_lid_ids();
        if(l_err)
        {
            TRACFCOMP(g_trac_pnor, "RtPnor(): An error occurred when trying to get the runtime lid ids from the BMC");
            break;
        }

        l_err = PNOR::populateTOC(iv_TOC, iv_ipltime_lid_ids, iv_initialized);
        if(l_err)
        {
            TRACFCOMP(g_trac_pnor, "RtPnor(): populateTOC returned an error");
            break;
        }
#endif
    } while (0);

    if (l_err)
    {
        errlCommit(l_err, PNOR_COMP_ID);
    }
}

/*************************/
RtPnor::~RtPnor()
{
}

/*******************Private Methods*********************/
#ifndef CONFIG_FILE_XFER_VIA_PLDM
errlHndl_t RtPnor::readFromDeviceOpal(uint64_t i_procId,
                                      PNOR::SectionId i_section,
                                      uint64_t i_offset,
                                      size_t i_size,
                                      bool i_ecc,
                                      void* o_data) const
{
    errlHndl_t l_err        = nullptr;
    uint8_t*   l_eccBuffer  = nullptr;
    do
    {
        const char* l_partitionName  = SectionIdToString(i_section);
        void*  l_dataToRead          = o_data;
        size_t l_readSize            = i_size;
        size_t l_readSizePlusECC     = (i_size * 9)/8;
        uint64_t l_offset            = i_offset;

        // if we need to handle ECC, we need to read more
        if( i_ecc )
        {
            l_eccBuffer  = new uint8_t[l_readSizePlusECC]();
            l_dataToRead = l_eccBuffer;
            l_readSize   = l_readSizePlusECC;
            l_offset     = (i_offset * 9)/8;
        }

        int l_rc = 0;
        if (g_hostInterfaces && g_hostInterfaces->pnor_read)
        {
            // get the data from OPAL
            l_rc = g_hostInterfaces->pnor_read(i_procId, l_partitionName,
                    l_offset, l_dataToRead, l_readSize);
            if (l_rc < 0)
            {
                TRACFCOMP(g_trac_pnor, "readFromDeviceOpal: pnor_read"
                        " failed proc:%d, part:%s, offset:0x%X, size:0x%X,"
                        " dataPt:0x%X, rc:%d", i_procId, l_partitionName,
                        l_offset, l_readSize, l_dataToRead, l_rc);

                // prevent hang between ErrlManager and rt_pnor
                assert(iv_initialized,
                      "readFromDeviceOpal: pnor_read returned an error"
                      " during initialization");

                /*@
                 * @errortype
                 * @moduleid            PNOR::MOD_RTPNOR_READFROMDEVICE
                 * @reasoncode          PNOR::RC_PNOR_READ_FAILED
                 * @userdata1[00:31]    rc returned from pnor_read
                 * @userdata1[32:63]    section ID
                 * @userdata2[00:31]    offset within the section
                 * @userdata2[32:63]    size of data read in bytes
                 * @devdesc             g_hostInterfaces->pnor_read failed
                 * @custdesc            Error accessing system firmware flash
                 */
                //@todo Add PNOR callout RTC:116145
                l_err = new ERRORLOG::ErrlEntry(
                                 ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                 PNOR::MOD_RTPNOR_READFROMDEVICE,
                                 PNOR::RC_PNOR_READ_FAILED,
                                 TWO_UINT32_TO_UINT64(l_rc, i_section),
                                 TWO_UINT32_TO_UINT64(l_offset, l_readSize),
                                 true);
                break;
            }
            else if( l_rc != static_cast<int>(l_readSize) )
            {
                TRACFCOMP( g_trac_pnor, "readFromDeviceOpal: only read 0x%X bytes, expecting 0x%X", l_rc, l_readSize );

                if( PNOR::TOC == i_section )
                {
                    // we can't know how big the TOC partition is without
                    // reading it so we have to make a request for more
                    // data and then handle a smaller amount getting returned
                    TRACFCOMP( g_trac_pnor, "Ignoring mismatch for TOC" );
                }
                else // everything else should have a known size
                {
                  // prevent hang between ErrlManager and rt_pnor
                  assert(iv_initialized,
                      "readFromDeviceOpal: pnor_read failed to read "
                      "expected amount before rt_pnor initialization");

                    /*@
                     * @errortype
                     * @moduleid            PNOR::MOD_RTPNOR_READFROMDEVICE
                     * @reasoncode          PNOR::RC_WRONG_SIZE_FROM_READ
                     * @userdata1[00:31]    section ID
                     * @userdata1[32:63]    requested size of read
                     * @userdata2[00:31]    requested start offset into flash
                     * @userdata2[32:63]    actual amount read
                     * @devdesc             Amount of data read from pnor does
                     *                      not match expected size
                     * @custdesc          Error accessing system firmware flash
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                PNOR::MOD_RTPNOR_READFROMDEVICE,
                                PNOR::RC_WRONG_SIZE_FROM_READ,
                                TWO_UINT32_TO_UINT64(i_section,l_readSize),
                                TWO_UINT32_TO_UINT64(l_offset,l_rc),
                                true);
                    break;
                }
            }
        }
        else
        {
            TRACFCOMP(g_trac_pnor,"readFromDeviceOpal: This version of"
                    " OPAL does not support pnor_read");

            // prevent hang between ErrlManager and rt_pnor
            assert(iv_initialized,
                      "readFromDeviceOpal: OPAL version does NOT support"
                      "pnor_read during initialization");
            /*@
             * @errortype
             * @moduleid           PNOR::MOD_RTPNOR_READFROMDEVICE
             * @reasoncode         PNOR::RC_PNOR_READ_NOT_SUPPORTED
             * @devdesc            g_hostInterfaces->pnor_read not supported
             * @custdesc           Error accessing system firmware flash
             */
            //@todo Add PNOR callout RTC:116145
            l_err = new ERRORLOG::ErrlEntry(
                             ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                             PNOR::MOD_RTPNOR_READFROMDEVICE,
                             PNOR::RC_PNOR_READ_NOT_SUPPORTED,
                             0,0,true);
            break;
        }
        // remove the ECC data
        if( i_ecc )
        {
            TRACFCOMP(g_trac_pnor, "readFromDeviceOpal: removing ECC...");
            // remove the ECC and fix the original data if it is broken
            size_t l_eccSize = (l_rc/9)*8;
            l_eccSize = std::min( l_eccSize, i_size );
            PNOR::ECC::eccStatus ecc_stat =
                 PNOR::ECC::removeECC(reinterpret_cast<uint8_t*>(l_dataToRead),
                                      reinterpret_cast<uint8_t*>(o_data),
                                      l_eccSize); //logical size of read data

            // create an error if we couldn't correct things
            if( ecc_stat == PNOR::ECC::UNCORRECTABLE )
            {
                TRACFCOMP(g_trac_pnor,"readFromDeviceOpal>"
                    " Uncorrectable ECC error : chip=%d,offset=0x%.X",
                    i_procId, i_offset );

                // prevent hang between ErrlManager and rt_pnor
                assert(iv_initialized,
                      "readFromDeviceOpal: UNCORRECTABLE_ECC encountered"
                      " during initialization");
                /*@
                 * @errortype
                 * @moduleid    PNOR::MOD_RTPNOR_READFROMDEVICE
                 * @reasoncode  PNOR::RC_UNCORRECTABLE_ECC
                 * @devdesc     UNCORRECTABLE ECC
                 */
                //@todo Add PNOR callout RTC:116145
                l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    PNOR::MOD_RTPNOR_READFROMDEVICE,
                                    PNOR::RC_UNCORRECTABLE_ECC,
                                    0, 0, true);
                break;
            }

            // found an error so we need to fix something
            else if( ecc_stat != PNOR::ECC::CLEAN )
            {
                TRACFCOMP(g_trac_pnor,"readFromDeviceOpal>"
                      "Correctable ECC error : chip=%d, offset=0x%.X",
                      i_procId, i_offset );
                if (g_hostInterfaces && g_hostInterfaces->pnor_write)
                {

                    //need to write good data back to PNOR
                    int l_rc = g_hostInterfaces->pnor_write(i_procId,
                            l_partitionName,l_offset, l_dataToRead,l_readSize);
                    if (l_rc != static_cast<int>(l_readSize))
                    {
                        TRACFCOMP(g_trac_pnor, "readFromDeviceOpal> Error"
                        " writing corrected data back to device");

                        // prevent hang between ErrlManager and rt_pnor
                        assert(iv_initialized,
                            "readFromDeviceOpal: pnor_write returned an"
                            " error during initialization");

                        /*@
                         * @errortype
                         * @moduleid   PNOR::MOD_RTPNOR_READFROMDEVICE
                         * @reasoncode PNOR::RC_PNOR_WRITE_FAILED
                         * @userdata1  rc returned from pnor_write
                         * @userdata2  Expected size of write
                         * @devdesc    error writing corrected data back to PNOR
                         * @custdesc   Error accessing system firmware flash
                         */
                        l_err = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          PNOR::MOD_RTPNOR_READFROMDEVICE,
                                          PNOR::RC_PNOR_WRITE_FAILED,
                                          l_rc, l_readSize, true);
                        errlCommit(l_err, PNOR_COMP_ID);
                    }
                }
            }
        }
    } while(0);

    if( l_eccBuffer )
    {
        delete[] l_eccBuffer;
    }

    return l_err;
}

errlHndl_t RtPnor::writeToDeviceOpal(uint64_t i_procId,
                                     PNOR::SectionId i_section,
                                     uint64_t i_offset,
                                     size_t i_size,
                                     bool i_ecc,
                                     void* i_src)
{
    errlHndl_t l_err        = nullptr;
    uint8_t*   l_eccBuffer  = nullptr;
    do
    {
        void*  l_dataToWrite      = i_src;
        size_t l_writeSize        = i_size;
        size_t l_writeSizePlusECC = (i_size * 9)/8;
        uint64_t l_offset         = i_offset;

        // apply ECC to data if needed
        if( i_ecc )
        {
            l_eccBuffer = new uint8_t[l_writeSizePlusECC];
            PNOR::ECC::injectECC( reinterpret_cast<uint8_t*>(i_src),
                              l_writeSize,
                              reinterpret_cast<uint8_t*>(l_eccBuffer) );
            l_dataToWrite = reinterpret_cast<void*>(l_eccBuffer);
            l_writeSize = l_writeSizePlusECC;
            l_offset    = (i_offset * 9)/8;
        }

        const char* l_partitionName = SectionIdToString(i_section);
        if (g_hostInterfaces && g_hostInterfaces->pnor_write)
        {
            //make call into opal to write the data
            int l_rc = g_hostInterfaces->pnor_write(i_procId,
                        l_partitionName,l_offset,l_dataToWrite,l_writeSize);
            if (l_rc != static_cast<int>(l_writeSize))
            {
                TRACFCOMP(g_trac_pnor, "RtPnor::writeToDeviceOpal: pnor_write failed "
                    "proc:%d, part:%s, offset:0x%X, size:0x%X, dataPt:0x%X,"
                    " rc:%d", i_procId, l_partitionName, l_offset, l_writeSize,
                    l_dataToWrite, l_rc);
                /*@
                 * @errortype
                 * @moduleid            PNOR::MOD_RTPNOR_WRITETODEVICE
                 * @reasoncode          PNOR::RC_PNOR_WRITE_FAILED
                 * @userdata1[00:31]    rc returned from pnor_write
                 * @userdata1[32:63]    section ID
                 * @userdata2[00:31]    offset within the section
                 * @userdata2[32:63]    size of data written in bytes
                 * @devdesc             g_hostInterfaces->pnor_write failed
                 * @custdesc            Error accessing system firmware flash
                 */
                l_err = new ERRORLOG::ErrlEntry(
                             ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                             PNOR::MOD_RTPNOR_WRITETODEVICE,
                             PNOR::RC_PNOR_WRITE_FAILED,
                             TWO_UINT32_TO_UINT64(l_rc, i_section),
                             TWO_UINT32_TO_UINT64(l_offset, l_writeSize),
                             true);
                 break;
            }
        }
        else
        {
            TRACFCOMP(g_trac_pnor,"RtPnor::writeToDeviceOpal: This version of"
                    " OPAL does not support pnor_write");
            /*@
             * @errortype
             * @moduleid           PNOR::MOD_RTPNOR_WRITETODEVICE
             * @reasoncode         PNOR::RC_PNOR_WRITE_NOT_SUPPORTED
             * @devdesc            g_hostInterfaces->pnor_write not supported
             * @custdesc           Error accessing system firmware flash
             */
            //@todo Add PNOR callout RTC:116145
            l_err = new ERRORLOG::ErrlEntry(
                             ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                             PNOR::MOD_RTPNOR_WRITETODEVICE,
                             PNOR::RC_PNOR_WRITE_NOT_SUPPORTED,
                             0,0,true);
            break;

        }
    } while(0);

    if( l_eccBuffer )
    {
        delete[] l_eccBuffer;
    }

    return l_err;
}

#else

/**
  * @brief  Use PLDM to read data from the PNOR device
  *
  * @param[in] i_section section of the pnor to read back
  * @param[in] i_offset  offset into the pnor
  * @param[in] i_size    size of data to read in bytes
  * @param[in] o_data    Buffer to copy data into
  *
  * @return Error from device
  */
errlHndl_t readFromDevicePldm(PNOR::SectionId i_section,
                              uint64_t i_offset,
                              size_t i_size,
                              void* o_data)
{
    errlHndl_t errl = nullptr;

    do
    {
        auto actual_size = static_cast<uint32_t>(i_size);
        uint32_t lid_id = 0;

        errl = PLDM_PNOR::sectionIdToLidId(i_section, lid_id);
        if(errl)
        {
            TRACFCOMP(g_trac_pnor,
                      "RtPnor::readFromDevicePldm: an error occurred looking up the lid id for section %d"
                      TRACE_ERR_FMT,
                      i_section,
                      TRACE_ERR_ARGS(errl));
            break;
        }

        errl = PLDM::getLidFileFromOffset(lid_id,
                                          i_offset,
                                          actual_size,
                                          reinterpret_cast<uint8_t *>(o_data));
        if(errl)
        {
            TRACFCOMP(g_trac_pnor,
                      "RtPnor::readFromDevicePldm: an error occurred reading pnor data from the BMC"
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(errl));
            break;
        }
        else if(actual_size != i_size)
        {
            TRACFCOMP(g_trac_pnor,
                      "RtPnor::readFromDevicePldm: size returned (0x%lx) is less than size requested (0x%lx)",
                      actual_size,
                      i_size);
            /*@
            * @errortype
            * @moduleid            PNOR::MOD_RTPNOR_READFROMDEVICE_PLDM
            * @reasoncode          PNOR::RC_WRONG_SIZE_FROM_READ
            * @userdata1[00:31]    section ID
            * @userdata1[32:63]    offset within the section
            * @userdata2[00:31]    size we tried to read in bytes
            * @userdata2[32:63]    actual size of data read in bytes
            * @devdesc             getLidFileFromOffset PLDM call failed
            * @custdesc            Error accessing system firmware flash
            */
            errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            PNOR::MOD_RTPNOR_READFROMDEVICE_PLDM,
                            PNOR::RC_WRONG_SIZE_FROM_READ,
                            TWO_UINT32_TO_UINT64(i_section, i_offset),
                            TWO_UINT32_TO_UINT64(static_cast<uint32_t>(i_size), actual_size),
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }
    }while(0);

    return errl;
}

/**
  * @brief  Use PLDM to write data back to the PNOR device
  *
  * @param[in] i_section section of the pnor to write back
  * @param[in] i_offset  offset into the pnor
  * @param[in] i_size    size of data to write in bytes
  * @param[in] i_src     Buffer to copy data from
  *
  * @return Error from device
  */
errlHndl_t writeToDevicePldm(PNOR::SectionId i_section,
                             uint64_t i_offset,
                             size_t i_size,
                             void* i_src)
{
    errlHndl_t errl = nullptr;

    do
    {
        auto actual_size = static_cast<uint32_t>(i_size);
        uint32_t lid_id = 0;

        errl = PLDM_PNOR::sectionIdToLidId(i_section, lid_id);
        if(errl)
        {
            TRACFCOMP(g_trac_pnor,
                      "RtPnor::readFromDevicePldm: an error occurred looking up the lid id for section %d"
                      TRACE_ERR_FMT,
                      i_section,
                      TRACE_ERR_ARGS(errl));
            break;
        }

        errl = PLDM::writeLidFileFromOffset(lid_id,
                                            i_offset,
                                            actual_size,
                                            reinterpret_cast<const uint8_t *>(i_src));

        if(errl)
        {
            TRACFCOMP(g_trac_pnor,
                      "RtPnor::writeToDevicePldm: an error occurred writing pnor data from the BMC"
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(errl));
        }
        else if(actual_size != i_size)
        {
            TRACFCOMP(g_trac_pnor,
                      "RtPnor::writeToDevicePldm: size returned (0x%lx) is less than size requested (0x%lx)",
                      actual_size,
                      i_size);
            /*@
            * @errortype
            * @moduleid            PNOR::MOD_RTPNOR_WRITETODEVICE_PLDM
            * @reasoncode          PNOR::RC_WRONG_SIZE_FROM_WRITE
            * @userdata1[00:31]    section ID
            * @userdata1[32:63]    offset within the section
            * @userdata2[00:31]    size we tried to write in bytes
            * @userdata2[32:63]    actual size of data write in bytes
            * @devdesc             writeLidFileFromOffset PLDM call failed
            * @custdesc            Error accessing system firmware flash
            */
            errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            PNOR::MOD_RTPNOR_WRITETODEVICE_PLDM,
                            PNOR::RC_WRONG_SIZE_FROM_WRITE,
                            TWO_UINT32_TO_UINT64(i_section, i_offset),
                            TWO_UINT32_TO_UINT64(static_cast<uint32_t>(i_size), actual_size),
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }
    }while(0);

    return errl;
}
#endif

errlHndl_t RtPnor::readFromDevice (uint64_t i_procId,
                                   PNOR::SectionId i_section,
                                   uint64_t i_offset,
                                   size_t i_size,
                                   bool i_ecc,
                                   void* o_data) const
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK"RtPnor::readFromDevice: i_offset=0x%X, "
           "i_procId=%d sec=%d size=0x%X ecc=%d", i_offset, i_procId, i_section,
             i_size, i_ecc);
    errlHndl_t l_err        = nullptr;
#ifdef CONFIG_FILE_XFER_VIA_PLDM
    l_err = readFromDevicePldm(i_section, i_offset, i_size, o_data);
#else
    l_err = readFromDeviceOpal(i_procId, i_section, i_offset,
                               i_size, i_ecc, o_data);
#endif
    TRACFCOMP(g_trac_pnor, EXIT_MRK"RtPnor::readFromDevice" );
    return l_err;
}

/*********************************************************************/
errlHndl_t RtPnor::writeToDevice( uint64_t i_procId,
                                  PNOR::SectionId i_section,
                                  uint64_t i_offset,
                                  size_t i_size,
                                  bool i_ecc,
                                  void* i_src )
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK"RtPnor::writeToDevice: i_offset=0x%X, "
           "i_procId=%d sec=%d size=0x%X ecc=%d", i_offset, i_procId, i_section,
             i_size, i_ecc);
    errlHndl_t l_err        = nullptr;
#ifdef CONFIG_FILE_XFER_VIA_PLDM
    l_err = writeToDevicePldm(i_section, i_offset, i_size, i_src);
#else
    l_err = writeToDeviceOpal(i_procId, i_section, i_offset,
                              i_size, i_ecc, i_src);
#endif
    TRACFCOMP(g_trac_pnor, EXIT_MRK"RtPnor::writeToDevice" );
    return l_err;
}

/*****************************************************************/
errlHndl_t RtPnor::readTOC ()
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK"RtPnor::readTOC" );

    errlHndl_t l_err = nullptr;
    uint8_t* l_toc0Buffer = new uint8_t[PNOR::TOC_SIZE];
    do {
        if (g_hostInterfaces && g_hostInterfaces->pnor_read)
        {
            // offset = 0 means read the entire PNOR::TOC partition
            // This offset is offset into the partition, not offset from the
            // beginning of the flash
            l_err = readFromDevice (iv_masterProcId, PNOR::TOC, 0,
                                    PNOR::TOC_SIZE, false, l_toc0Buffer);
            if (l_err)
            {
                TRACFCOMP(g_trac_pnor,"RtPnor::readTOC:readFromDevice failed"
                          " for TOC0");
                break;
            }

            //Pass along TOC buffer to be parsed, parseTOC will parse through
            // the buffer and store needed information in iv_TOC
            // Note: that Opal should always return a valid TOC
            l_err = PNOR::parseTOC(l_toc0Buffer, iv_TOC, iv_initialized);
            if (l_err)
            {
                TRACFCOMP(g_trac_pnor, "RtPnor::readTOC: parseTOC failed");
                break;
            }
        }
    } while (0);

    if(l_toc0Buffer != nullptr)
    {
        delete[] l_toc0Buffer;
    }

    TRACFCOMP(g_trac_pnor, EXIT_MRK"RtPnor::readTOC" );
    return l_err;
}

/***********************************************************/
RtPnor& RtPnor::getInstance()
{
    return Singleton<RtPnor>::instance();
}
/***********************************************************/
errlHndl_t RtPnor::getSideInfo( PNOR::SideId i_side,
                                PNOR::SideInfo_t& o_info)
{
    errlHndl_t l_err = nullptr;

    do {
        // We only support the working side at runtime
        if( i_side != PNOR::WORKING )
        {
            /*@
             * @errortype
             * @moduleid           PNOR::MOD_RTPNOR_GETSIDEINFO
             * @reasoncode         PNOR::RC_INVALID_PNOR_SIDE
             * @userdata1          Requested SIDE
             * @userdata2          0
             * @devdesc            getSideInfo> Side not supported
             * @custdesc           A problem occurred while accessing the boot flash.
             */
            l_err = new ERRORLOG::ErrlEntry(
                             ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                             PNOR::MOD_RTPNOR_GETSIDEINFO,
                             PNOR::RC_INVALID_PNOR_SIDE,
                             TO_UINT64(i_side),
                             0,true);
            break;
        }

        o_info.id = PNOR::WORKING;
        o_info.side = (ALIGN_DOWN_X(iv_TOC[PNOR::HB_BASE_CODE].flashAddr,32*MEGABYTE) == 0)
          ? 'A':'B'; //@fixme TODO RTC:134436
        //iv_side[i].isGolden = (ffsUserData->miscFlags & FFS_MISC_GOLDEN);
        o_info.isGolden = false; //@fixme TODO RTC:134436
        o_info.isGuardPresent = (iv_TOC[PNOR::GUARD_DATA].flashAddr == 0)
          ? false : true;

        o_info.hasOtherSide = false; //@fixme TODO RTC:134436
        o_info.primaryTOC = iv_TOC[PNOR::TOC].flashAddr;
        o_info.backupTOC = 0; //@fixme TODO RTC:134436
        o_info.hbbAddress = iv_TOC[PNOR::HB_BASE_CODE].flashAddr;
        o_info.hbbMmioOffset = 0; //@fixme TODO RTC:134436
    } while(0);

    return l_err;
}


errlHndl_t RtPnor::clearSection(PNOR::SectionId i_section)
{
    TRACFCOMP(g_trac_pnor, "RtPnor::clearSection Section id = %d", i_section);
    errlHndl_t l_errl = nullptr;
    const uint64_t CLEAR_BYTE = 0xFF;
    uint8_t* l_buf = new uint8_t[PAGESIZE]();
    uint8_t* l_eccBuf = nullptr;

    do
    {
        // Flush pages of pnor section we are trying to clear
        l_errl = flush(i_section);
        if (l_errl)
        {
            TRACFCOMP( g_trac_pnor, ERR_MRK"RtPnor::clearSection: flush() failed on section",
                        i_section);
            break;
        }

        // Get PNOR section info
        uint64_t l_address = iv_TOC[i_section].flashAddr;
        uint64_t l_chipSelect = iv_TOC[i_section].chip;
        uint32_t l_size = iv_TOC[i_section].size;
        bool l_ecc = iv_TOC[i_section].integrity & FFS_INTEG_ECC_PROTECT;

        // Number of pages needed to cycle proper ECC
        // Meaning every 9th page will copy the l_eccBuf at offset 0
        const uint64_t l_eccCycleNum = 9;

        // Boundaries for properly splitting up an ECC page for 4K writes.
        // Subtract 1 from l_eccCycleNum because we start writing with offset 0
        // and add this value 8 times to complete a cycle.
        const uint64_t l_sizeOfOverlapSection =
                (PNOR::PAGESIZE_PLUS_ECC - PAGESIZE) /
                (l_eccCycleNum - 1);

        // Create clear section buffer
        memset(l_buf, CLEAR_BYTE, PAGESIZE);

        // apply ECC to data if needed
        if(l_ecc)
        {
            l_eccBuf = new uint8_t[PNOR::PAGESIZE_PLUS_ECC]();
            PNOR::ECC::injectECC( reinterpret_cast<uint8_t*>(l_buf),
                                  PAGESIZE,
                                  reinterpret_cast<uint8_t*>(l_eccBuf) );
            l_size = (l_size*9)/8;
        }

        // Write clear section page to PNOR
        for (uint64_t i = 0; i < l_size; i+=PAGESIZE)
        {
            if(l_ecc)
            {
                // Take (current page) mod (l_eccCycleNum) to get cycle position
                uint8_t l_bufPos = ( (i/PAGESIZE) % l_eccCycleNum );
                uint64_t l_bufOffset = l_sizeOfOverlapSection * l_bufPos;
                memcpy(l_buf, (l_eccBuf + l_bufOffset), PAGESIZE);
            }

            // Set ecc parameter to false to avoid double writes will only write
            // 4k at a time, even if the section is ecc protected.
            l_errl = writeToDevice( iv_masterProcId, i_section,
                                   (l_address + i), l_chipSelect,
                                   false, l_buf);
            if (l_errl)
            {
                TRACFCOMP( g_trac_pnor, ERR_MRK"RtPnor::clearSection: writeToDevice fail: eid=0x%X, rc=0x%X",
                           l_errl->eid(), l_errl->reasonCode());
                break;
            }
        }
        if (l_errl)
        {
            break;
        }
    } while(0);

    // Free allocated memory
    if(l_eccBuf)
    {
        delete[] l_eccBuf;
    }
    delete [] l_buf;

    return l_errl;
}

errlHndl_t RtPnor::getMasterProcId()
{
    errlHndl_t l_err = nullptr;

    do {
    TARGETING::Target* l_masterProc = nullptr;
    l_err = TARGETING::targetService().queryMasterProcChipTargetHandle(l_masterProc);
    if (l_err)
    {
        TRACFCOMP(g_trac_pnor, "RtPnor::getMasterProcId: queryMasterProcChipTargetHandle failed");
        break;
    }
    l_err = TARGETING::getRtTarget(l_masterProc, iv_masterProcId);
    if (l_err)
    {
        TRACFCOMP(g_trac_pnor, "RtPnor::getMasterProcId: getRtTarget failed for master proc");
        break;
    }
    } while(0);

    return l_err;
}

void initPnor()
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK"initPnor");

    errlHndl_t l_errl = nullptr;
    // Only run PNOR init on non-FSP based systems
    if ( !INITSERVICE::spBaseServicesEnabled() )
    {
      // call static init() function to save PNOR section into memory
      RtPnor::init(l_errl);
      if (l_errl)
      {
        TRACFCOMP(g_trac_pnor,ERR_MRK"initPnor: "
                      "Failed RtPnor::init() with EID %.8X:%.4X",
                      ERRL_GETEID_SAFE(l_errl),
                      ERRL_GETRC_SAFE(l_errl) );
        errlCommit (l_errl, PNOR_COMP_ID);
      }
    }
    TRACFCOMP(g_trac_pnor, EXIT_MRK"initPnor");
}

//------------------------------------------------------------------------

struct registerinitPnor
{
    registerinitPnor()
    {
        // Register interface for Host to call
        postInitCalls_t * rt_post = getPostInitCalls();
        rt_post->callInitPnor = &initPnor;
    }
};

registerinitPnor g_registerInitPnor;
