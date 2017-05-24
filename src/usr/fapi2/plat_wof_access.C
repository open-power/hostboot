/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_wof_access.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
 *  @file plat_wof_access.C
 *
 *  @brief Implements the GetWofTables function
 */

#include <stdint.h>
#include <fapi2.H>
#include <attribute_service.H>
#include <attributeenums.H>
#include <errl/errludattribute.H>
#include <errl/errlreasoncodes.H>
#include <util/utillidmgr.H>
#include <p9_pstates_common.h>

namespace fapi2
{

namespace platAttrSvc
{

const uint32_t WOF_IMAGE_MAGIC_VALUE = 0x57544948;  // WTIH
const uint32_t WOF_TABLES_MAGIC_VALUE = 0x57465448; // WFTH
const uint32_t RES_VERSION_MASK = 0xFF;
const uint32_t WOF_IMAGE_VERSION = 1;
const uint32_t WOF_TABLES_VERSION = 1;


/*
        WOF Tables In PNOR
    ---------------------------
    |      Image Header       |  Points to Section Table
    |-------------------------|
    |  Section Table Entry 1  |  Section Table
    |  Section Table Entry 2  |    Each entry points to
    |  ...                    |    a WOF Table
    |-------------------------|
    |   WOF Tables Header 1   |  WOF Table
    |        VRFT 1           |    Returned if match
    |        VRFT 2           |
    |        ...              |
    |-------------------------|
    |   WOF Tables Header 2   |  WOF Table
    |        VRFT 1           |    Returned if match
    |        VRFT 2           |
    |        ...              |
    |-------------------------|
    |   ...                   |
    ---------------------------

    The structs for the Image Header and
    Section Table Entry are defined below.
    The struct for the WOF Tables Header
    is defined in p9_pstates_common.h.
*/


typedef struct __attribute__((__packed__))  wofImageHeader
{
    uint32_t magicNumber;
    uint8_t  version;
    uint8_t  entryCount;
    uint32_t offset;
} wofImageHeader_t;


typedef struct __attribute__((__packed__))  wofSectionTableEntry
{
    uint32_t offset;
    uint32_t size;
} wofSectionTableEntry_t;


fapi2::ReturnCode platParseWOFTables(uint8_t* o_wofData)
{
    FAPI_DBG("Entering platParseWOFTables ....");

    errlHndl_t l_errl = nullptr;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;;

    TARGETING::Target * l_sys = nullptr;
    TARGETING::Target * l_mProc = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_sys);
    TARGETING::targetService().masterProcChipTargetHandle( l_mProc );

    // Get the number of present cores
    TARGETING::TargetHandleList pECList;
    getChildChiplets(pECList, l_mProc, TARGETING::TYPE_CORE, false);
    uint32_t l_numCores = pECList.size();

    // Choose a sort freq
    uint32_t l_sortFreq = 0;

    // Get the socket power
    uint32_t l_socketPower = 0;
    uint8_t l_wofPowerLimit =
                l_sys->getAttr<TARGETING::ATTR_WOF_POWER_LIMIT>();

    if(l_wofPowerLimit == TARGETING::WOF_POWER_LIMIT_TURBO)
    {
        l_socketPower =
                l_sys->getAttr<TARGETING::ATTR_SOCKET_POWER_TURBO>();
        l_sortFreq = l_sys->getAttr<TARGETING::ATTR_FREQ_CORE_MAX>();
    }
    else
    {
        l_socketPower =
                l_sys->getAttr<TARGETING::ATTR_SOCKET_POWER_NOMINAL>();
        l_sortFreq = l_sys->getAttr<TARGETING::ATTR_NOMINAL_FREQ_MHZ>();
    }

    // Get the frequencies
    uint32_t l_nestFreq =
                l_sys->getAttr<TARGETING::ATTR_FREQ_PB_MHZ>();

    // Trace the input params
    FAPI_INF("WOF table search: "
             "Cores %d SocketPower 0x%X NestFreq 0x%X SortFreq 0x%X",
             l_numCores, l_socketPower, l_nestFreq, l_sortFreq);

    void* l_pWofImage = nullptr;
    size_t l_lidImageSize = 0;

    do {
        // @todo RTC 172776 Make WOF table parser PNOR accesses more efficient
        // Lid number is system dependent
        uint32_t l_lidNumber =
            l_sys->getAttr<TARGETING::ATTR_WOF_TABLE_LID_NUMBER>();
        UtilLidMgr l_wofLidMgr(l_lidNumber);

        // Get the size of the full wof tables image
        l_errl = l_wofLidMgr.getLidSize(l_lidImageSize);
        if(l_errl)
        {
            FAPI_ERR("platParseWOFTables getLidSize failed");
            l_rc.setPlatDataPtr(reinterpret_cast<void *>(l_errl));
            break;
        }

        // Allocate space, remember to free it later
        l_pWofImage = static_cast<void*>(malloc(l_lidImageSize));

        // Get the tables from pnor or lid
        l_errl = l_wofLidMgr.getLid(l_pWofImage, l_lidImageSize);
        if(l_errl)
        {
            FAPI_ERR("platParseWOFTables getLid failed "
                     "pLidImage %p imageSize %d",
                     l_pWofImage, l_lidImageSize);
            l_rc.setPlatDataPtr(reinterpret_cast<void *>(l_errl));
            break;
        }

        // Get the Image Header
        wofImageHeader_t* l_img =
                reinterpret_cast<wofImageHeader_t*>(l_pWofImage);

        // Check for the eyecatcher
        if(l_img->magicNumber != WOF_IMAGE_MAGIC_VALUE)
        {
            FAPI_ERR("Image Header Magic Value != WTIH(0x%X)",
                     WOF_IMAGE_MAGIC_VALUE);
            /*@
            * @errortype
            * @moduleid          fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES
            * @reasoncode        fapi2::RC_WOF_IMAGE_MAGIC_MISMATCH
            * @userdata1[00:31]  Image header magic value
            * @userdata1[32:63]  Expected magic value
            * @userdata2[00:31]  LID ID
            * @userdata2[32:63]  Image header version
            * @devdesc           Image header magic value mismatch
            * @custdesc          Firmware Error
            */
            l_errl = new ERRORLOG::ErrlEntry(
                             ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                             fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
                             fapi2::RC_WOF_IMAGE_MAGIC_MISMATCH,
                             TWO_UINT32_TO_UINT64(
                                l_img->magicNumber,
                                WOF_IMAGE_MAGIC_VALUE),
                             TWO_UINT32_TO_UINT64(
                                l_lidNumber,
                                l_img->version),
                             true); //software callout
            l_rc.setPlatDataPtr(reinterpret_cast<void *>(l_errl));
            break;
        }

        // Check for a valid image header version
        if(l_img->version > WOF_IMAGE_VERSION)
        {
            FAPI_ERR("Image header version not supported: "
                     " Header Version %d Supported Version %d",
                     l_img->version, WOF_IMAGE_VERSION);
            /*@
            * @errortype
            * @moduleid          fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES
            * @reasoncode        fapi2::RC_WOF_IMAGE_VERSION_MISMATCH
            * @userdata1[00:31]  Image header version
            * @userdata1[32:63]  Supported header version
            * @userdata2         LID ID
            * @devdesc           Image header version not supported
            * @custdesc          Firmware Error
            */
            l_errl = new ERRORLOG::ErrlEntry(
                             ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                             fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
                             fapi2::RC_WOF_IMAGE_VERSION_MISMATCH,
                             TWO_UINT32_TO_UINT64(
                                l_img->version,
                                WOF_IMAGE_VERSION),
                             l_lidNumber,
                             true); //software callout
            l_rc.setPlatDataPtr(reinterpret_cast<void *>(l_errl));
            break;
        }

        // Image info
        FAPI_INF("WOF Image: Magic 0x%X Version %d Entries %d Offset %p",
                 l_img->magicNumber, l_img->version,
                 l_img->entryCount, l_img->offset);

        // Get a pointer to the first section table entry
        wofSectionTableEntry_t* l_ste =
            reinterpret_cast<wofSectionTableEntry_t*>
                (reinterpret_cast<uint8_t*>(l_pWofImage) + l_img->offset);

        WofTablesHeader_t* l_wth = nullptr;
        std::vector<WofTablesHeader_t*> l_headers;
        l_headers.clear();
        uint32_t l_ent = 0;
        uint32_t l_ver = 0;

        // Loop through all section table entries
        for( l_ent = 0; l_ent < l_img->entryCount; l_ent++ )
        {
            // Get a pointer to the WOF table
            l_wth = reinterpret_cast<WofTablesHeader_t*>
                        (reinterpret_cast<uint8_t*>(l_pWofImage)
                            + l_ste[l_ent].offset);
            l_ver = l_wth->reserved_version & RES_VERSION_MASK;

            // Check for the eyecatcher
            if(l_wth->magic_number != WOF_TABLES_MAGIC_VALUE)
            {
                FAPI_ERR("WOF Tables Header Magic Number != WFTH(0x%X)",
                         WOF_TABLES_MAGIC_VALUE);
                /*@
                * @errortype
                * @moduleid          fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES
                * @reasoncode        fapi2::RC_WOF_TABLES_MAGIC_MISMATCH
                * @userdata1[00:31]  WOF tables header magic value
                * @userdata1[32:63]  Expected magic value
                * @userdata2[00:31]  WOF tables entry number
                * @userdata2[32:63]  WOF tables header version
                * @devdesc           WOF tables header magic value mismatch
                * @custdesc          Firmware Error
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
                                fapi2::RC_WOF_TABLES_MAGIC_MISMATCH,
                                TWO_UINT32_TO_UINT64(
                                    l_wth->magic_number,
                                    WOF_TABLES_MAGIC_VALUE),
                                TWO_UINT32_TO_UINT64(
                                    l_ent,
                                    l_ver),
                                true); //software callout
                l_rc.setPlatDataPtr(reinterpret_cast<void *>(l_errl));
                break;
            }

            // Check for a valid tables header version
            if(l_ver > WOF_TABLES_VERSION)
            {
                FAPI_ERR("WOF tables header version not supported: "
                        " Header Version %d Supported Version %d",
                        l_ver, WOF_TABLES_VERSION);
                /*@
                * @errortype
                * @moduleid          fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES
                * @reasoncode        fapi2::RC_WOF_TABLES_VERSION_MISMATCH
                * @userdata1[00:31]  WOF tables header version
                * @userdata1[32:63]  Supported header version
                * @userdata2         WOF tables entry number
                * @devdesc           WOF tables header version not supported
                * @custdesc          Firmware Error
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
                                fapi2::RC_WOF_TABLES_VERSION_MISMATCH,
                                TWO_UINT32_TO_UINT64(
                                    l_ver,
                                    WOF_TABLES_VERSION),
                                l_ent,
                                true); //software callout
                l_rc.setPlatDataPtr(reinterpret_cast<void *>(l_errl));
                break;
            }

            // Trace the WOF table fields
            FAPI_INF("WOF table fields "
                     "SectionTableEntry %d "
                     "SectionTableOffset 0x%X "
                     "SectionTableSize %d "
                     "Version %d Cores %d SocketPower 0x%X "
                     "NestFreq 0x%X NomFreq 0x%X",
                     l_ent, l_ste[l_ent].offset, l_ste[l_ent].size,
                     l_ver, l_wth->core_count, l_wth->socket_power_w,
                     l_wth->nest_frequency_mhz, l_wth->sort_power_freq_mhz);

            // Compare the fields
            if( (l_wth->core_count == l_numCores) &&
                (l_wth->socket_power_w == l_socketPower) &&
                (l_wth->nest_frequency_mhz == l_nestFreq) &&
                (l_wth->sort_power_freq_mhz == l_sortFreq) )
            {
                // Found a match
                FAPI_INF("Found a WOF table match");

                // Copy the WOF table to the ouput pointer
                memcpy(o_wofData,
                       reinterpret_cast<uint8_t*>(l_wth),
                       l_ste[l_ent].size);

                break;
            }
            else
            {
                // Save the header for later
                l_headers.push_back(l_wth);
            }
        }

        if(l_errl)
        {
            break;
        }

        //Check for no match
        if(l_ent == l_img->entryCount)
        {
            FAPI_ERR("No WOF table match found");
            /*@
            * @errortype
            * @moduleid          fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES
            * @reasoncode        fapi2::RC_WOF_TABLE_NOT_FOUND
            * @userdata1[00:15]  Number of cores
            * @userdata1[16:31]  WOF Power Mode (0=Nominal,1=Turbo)
            * @userdata1[32:63]  Socket power
            * @userdata2[00:31]  Nest frequency
            * @userdata2[32:63]  Sort frequency
            * @devdesc           No WOF table match found
            * @custdesc          Firmware Error
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
                            fapi2::RC_WOF_TABLE_NOT_FOUND,
                            TWO_UINT16_ONE_UINT32_TO_UINT64(
                                    l_numCores,
                                    l_wofPowerLimit,
                                    l_socketPower),
                            TWO_UINT32_TO_UINT64(
                                    l_nestFreq,
                                    l_sortFreq),
                            true); //software callout
            l_errl->collectTrace(FAPI_TRACE_NAME);

            // Add data
            ERRORLOG::ErrlUserDetailsAttribute(
                            l_sys,
                            TARGETING::ATTR_WOF_TABLE_LID_NUMBER)
                            .addToLog(l_errl);
            while(l_headers.size())
            {
                l_errl->addFFDC(
                        HWPF_COMP_ID,
                        l_headers.back(),
                        sizeof(WofTablesHeader_t),
                        0,                           // version
                        ERRORLOG::ERRL_UDT_NOFORMAT, // parser ignores data
                        false );                     // merge
                l_headers.pop_back();
            }

            l_rc.setPlatDataPtr(reinterpret_cast<void *>(l_errl));
            break;
        }

    } while(0);

    // Free the wof tables memory
    if(l_pWofImage != nullptr)
    {
        free(l_pWofImage);
    }

    FAPI_DBG("Exiting platParseWOFTables ....");

    return l_rc;
}

} // End platAttrSvc namespace
} // End fapi2 namespace
