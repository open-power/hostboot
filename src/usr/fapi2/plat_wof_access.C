/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_wof_access.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
#include <pstates_common.H>
#include <initservice/initserviceif.H>
#include <sys/mm.h>
#include <errl/errlmanager.H>
#include <util/misc.H>
#include <devicefw/userif.H>
#include <conversions.H>
#include <eeprom/eeprom_const.H>
#include <targeting/targplatutil.H>
#include <pnor/ecc.H> // Remove ECC

using namespace TARGETING;

namespace fapi2
{

namespace platAttrSvc
{

const uint32_t WOF_IMAGE_MAGIC_VALUE = 0x57544948;  // WTIH
const uint32_t WOF_TABLES_MAGIC_VALUE = 0x57465448; // WFTH
const uint32_t RES_VERSION_MASK = 0xFF;
const uint32_t WOF_IMAGE_VERSION = 1;
const uint32_t WOF_TABLE_VERSION = 1;

#ifndef __HOSTBOOT_RUNTIME
// Remember that we have already allocated the VMM space for
//  the WOFDATA lid
/* TODO 250903: WOF Selection Algorithm for P10
static void* g_wofdataVMM = nullptr;
*/
#endif


// TODO 250903: WOF Selection Algorithm for P10
// WOF Table layout changes to triplets, as seen in WOF data from SEEPROM
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
    is defined in pstates_common.H.
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


// Compared fields in each WOF table header entry
// NOTE: struct must match errl/plugins/errludwofdata.H
typedef struct __attribute__((__packed__)) wofTableCompareData
{
  uint8_t  core_count;
  uint8_t  mode;
  uint16_t socket_power_w;
  uint16_t sort_power_freq_mhz;
} wofTableCompareData_t;



/* Declaration of helper methods for platParseWOFTables(...) */

/**
 *  @brief Get WOF Table from SEEPROM (or EECACHE if cached).
 *  The table selected is based on the value of ATTR_WOF_INDEX_SELECT.
 *
 *  @param[in] i_target         Master proc chip target handle pointer
 *  @param[out] o_wofData       Pointer to memory allocated in the heap for
 *                              large WOF Table data, which includes
 *                              corresponding WOF Table Header and VRT data.
 *
 *  @warning Asserts if o_wofData is nullptr
 *
 *  @return errlHndl_t    - nullptr if no errors encountered
 *                        - else error handler will contain error info
 */
errlHndl_t getDefaultWofTable(TARGETING::Target* i_target, uint8_t* o_wofData);

/**
 *  @brief Get blocks of data from WOF data in the Backup SEEPROM.
 *  WOF data in the SEEPROM has ECC, therefore this method will remove ECC and
 *  return ECC-less WOF data.
 *  The data offset and size arguments should not take into account ECC, this function will
 *  translate those values to valid ECC-aligned offset and size.
 *
 *  @param[in] i_procTarg       Master proc chip target handle pointer
 *  @param[in] i_buflen         ECC-less length of data output (in bytes) in WOF image
 *  @param[in] i_offset         ECC-less absolute offset in WOF image (in bytes)
 *  @param[out] o_buffer        Buffer to put result ECC-less data into
 *
 *  @return errlHndl_t    - nullptr if no errors encountered
 *                        - else error handler will contain error info
*/
errlHndl_t getSeepromEccLessWofData(TARGETING::Target* i_procTarg,
                                    const size_t i_buflen,
                                    const size_t i_offset,
                                    void* o_buffer);

/**
 *  @brief Checks that in the WOF image header, the magic number equals
 *  WOF_IMAGE_MAGIC_VALUE and that version number is a supported level.
 *
 *  @param[in] i_procTarg            Master proc chip target handle pointer
 *  @param[in] i_magicNum            Magic number in WOF image header
 *  @param[in] i_version             Version number in WOF image header
 *  @param[in] i_lidNum = nullptr    Optional argument to be used when the WOF
 *                                   image header was retrieved using UtilLidMgr.
 *                                   Value is only used in the UD section of the
 *                                   error log when an error is found.
 *
 *  @return errlHndl_t    - nullptr if no errors encountered
 *                        - else error handler will contain error info
 */
errlHndl_t checkWofImgHeaderForCorrectness(TARGETING::Target* i_procTarg,
                                           const uint32_t i_magicNum,
                                           const uint8_t i_version,
                                           const uint32_t* i_lidNum = nullptr);

/**
 *  @brief Checks that for a certain WOF table header entry the magic number
 *  equals WOF_TABLES_MAGIC_VALUE and that version number is a supported level.
 *
 *  @param[in] i_procTarg           Master proc chip target handle pointer
 *  @param[in] i_magicVal           Magic value of the WOF table header
 *  @param[in] i_version            Version number of the WOF table header
 *  @param[in] i_entry = nullptr    Optional argument to be used when the WOF
 *                                  table header entry comes from looping
 *                                  through the WOF image retrieved using
 *                                  UtilLidMgr.
 *                                  Value is only used in the UD section of the
 *                                  error log when an error is found.
 *
 *  @return errlHndl_t    - nullptr if no errors encountered
 *                        - else error handler will contain error info
 */
errlHndl_t checkWofTableHeaderForCorrectness(TARGETING::Target* i_procTarg,
                                             const uint32_t i_magicVal,
                                             const uint8_t i_version,
                                             const uint32_t* i_entry = nullptr);

/* End of declaration of helper methods for platParseWOFTables(...) */



/* platParseWOFTables(...) */

/**
 *  @brief This function will return the WOF table to use.
 *  This table is first searched in the WOF image retrieved using UtilLidMgr
 *  (the search criteria comes from the system's settings). If it's not found
 *  there, then the table data is picked up directly from the Backup EEPROM
 *  using the getDefaultWofTable(...) function.
 *
 *  @param[in]  i_procTarget    Get WOF data hanging off of this processor
 *
 *  @param[out]  o_wofData      Pointer to WOF Table data, which includes
 *                              corresponding WOF Table Header and VRT data
 *
 *  @return fapi2::ReturnCode - fapi2::FAPI2_RC_SUCCESS if no errors encountered
 *                            - else ReturnCode will contain error info
 */
fapi2::ReturnCode platParseWOFTables(TARGETING::Target* i_procTarg, uint8_t* o_wofData)
{
    FAPI_DBG("Entering platParseWOFTables ....");

    errlHndl_t l_errl = nullptr;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    uint8_t* l_simMatch = nullptr;
    /* TODO 250903: WOF Selection Algorithm for P10
    size_t l_simMatchSize = 0;
    */

    TARGETING::Target * l_sys = UTIL::assertGetToplevelTarget();
    TARGETING::targetService().getTopLevelTarget(l_sys);

    // Get the number of present cores
    TARGETING::TargetHandleList l_coreTargetList;
    TARGETING::getChildAffinityTargetsByState( l_coreTargetList,
                                               i_procTarg,
                                               TARGETING::CLASS_UNIT,
                                               TARGETING::TYPE_CORE,
                                               TARGETING::UTIL_FILTER_PRESENT);

/* TODO 250903: WOF Selection Algorithm for P10
    uint32_t l_numCores = l_coreTargetList.size();

    // Get the socket power, mode, and choose sort frequency
    uint32_t l_socketPower = 0;
    uint32_t l_sortFreq = 0;
    WOF_MODE l_mode = WOF_MODE_UNKNOWN;

// Based on EKB, figure out what WOF modes to assign to l_mode.
// Hitting assert trying to get target
// Figure out what to do with these attributes
    uint8_t l_wofPowerLimit = l_sys->getAttr<TARGETING::ATTR_WOF_POWER_LIMIT>();
    if(l_wofPowerLimit == TARGETING::WOF_POWER_LIMIT_TURBO)
    {
        l_socketPower = l_sys->getAttr<TARGETING::ATTR_SOCKET_POWER_TURBO>();
        l_sortFreq = l_sys->getAttr<TARGETING::ATTR_FREQ_CORE_MAX>();
        l_mode = WOF_MODE_NORMAL;
    }
    else
    {
        l_socketPower = l_sys->getAttr<TARGETING::ATTR_SOCKET_POWER_NOMINAL>();
        l_sortFreq = l_sys->getAttr<TARGETING::ATTR_NOMINAL_FREQ_MHZ>();
        l_mode = WOF_MODE_NORMAL;
    }

// May need to remove ATTR_FREQ_PB_MHZ from HB. Previously may have been used for WOF table search
// criteria.

    FAPI_INF("First checking all WOF table entries from WOF image retrieved using UtilLidMgr");

    // Trace the input params
    FAPI_INF("WOF table search criteria: Cores %d SocketPower 0x%X SortFreq 0x%X Mode 0x%X",
             l_numCores, l_socketPower, l_sortFreq, l_mode);
*/
    void* l_pWofImage = nullptr;

    /* TODO 250903: WOF Selection Algorithm for P10
    size_t l_lidImageSize = 0;
    */

    // Track if WOF Table Header is found using UtilLidMgr
    bool l_didFindWTH = false;

//// FIXME: 250903 WOF Selection Algorithm for P10
//     // Try to find WOF table using UtilLidMgr
//     do {
//         // @todo RTC 172776 Make WOF table parser PNOR accesses more efficient
//         uint32_t l_lidNumber = Util::WOF_LIDID;
//         if( INITSERVICE::spBaseServicesEnabled() )
//         {
//             // Lid number is system dependent on FSP systems
//             l_lidNumber =
//               l_sys->getAttr<TARGETING::ATTR_WOF_TABLE_LID_NUMBER>();
//         }
//         UtilLidMgr l_wofLidMgr(l_lidNumber);

//         // Get the size of the full wof tables image
//         l_errl = l_wofLidMgr.getLidSize(l_lidImageSize);
//         if(l_errl)
//         {
//             FAPI_ERR("platParseWOFTables getLidSize failed");
//             // Add the error log pointer as data to the ReturnCode
//             addErrlPtrToReturnCode(l_rc, l_errl);
//             break;
//         }

//         FAPI_INF("WOFDATA lid is %d bytes", l_lidImageSize);

// #ifdef __HOSTBOOT_RUNTIME
//         // In HBRT case, phyp will call malloc and return
//         // the lid pointer to us. We do not need to malloc
//         // the space ourselves. In fact, two mallocs
//         // on the WOF partition were leading to heap overflows.
//         l_pWofImage = nullptr;

//         // Using getStoredLidImage because we want to use the cached copies
//         // if they exist.
//         l_errl = l_wofLidMgr.getStoredLidImage(l_pWofImage, l_lidImageSize);
// #else
//         // Use a special VMM block to avoid the requirement for
//         //  contiguous memory
//         int l_mm_rc = 0;
//         if( !g_wofdataVMM )
//         {
//             l_mm_rc = mm_alloc_block( nullptr,
//                           reinterpret_cast<void*>(VMM_VADDR_WOFDATA_LID),
//                           VMM_SIZE_WOFDATA_LID );
//             if(l_mm_rc != 0)
//             {
//                 FAPI_INF("Fail from mm_alloc_block for WOFDATA, rc=%d", l_mm_rc);

//                 /* FIXME 255501 Revert back to ERRL_SEV_UNRECOVERABLE*/
//                 /*@
//                  * @errortype
//                  * @moduleid          fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES
//                  * @reasoncode        fapi2::RC_MM_ALLOC_BLOCK_FAILED
//                  * @userdata1         Address being allocated
//                  * @userdata2[00:31]  Size of block allocation
//                  * @userdata2[32:63]  rc from mm_alloc_block
//                  * @devdesc           Error calling mm_alloc_block for WOFDATA
//                  * @custdesc          Firmware Error
//                  */
//                 l_errl = new ERRORLOG::ErrlEntry(
//                                ERRORLOG::ERRL_SEV_INFORMATIONAL,
//                                fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
//                                fapi2::RC_MM_ALLOC_BLOCK_FAILED,
//                                VMM_VADDR_WOFDATA_LID,
//                                TWO_UINT32_TO_UINT64(VMM_SIZE_WOFDATA_LID,
//                                                     l_mm_rc),
//                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
//                 // Add the error log pointer as data to the ReturnCode
//                 addErrlPtrToReturnCode(l_rc, l_errl);
//                 break;
//             }

//             g_wofdataVMM = reinterpret_cast<void*>(VMM_VADDR_WOFDATA_LID);
//         }

//         l_mm_rc = mm_set_permission(
//                          reinterpret_cast<void*>(VMM_VADDR_WOFDATA_LID),
//                          l_lidImageSize,
//                          WRITABLE | ALLOCATE_FROM_ZERO );
//         if(l_mm_rc != 0)
//         {
//             FAPI_INF("Fail from mm_set_permission for WOFDATA, rc=%d", l_mm_rc);

//             /* FIXME 255501 Revert back to ERRL_SEV_UNRECOVERABLE*/
//             /*@
//              * @errortype
//              * @moduleid          fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES
//              * @reasoncode        fapi2::RC_MM_SET_PERMISSION_FAILED
//              * @userdata1         Address being changed
//              * @userdata2[00:31]  Size of change
//              * @userdata2[32:63]  rc from mm_set_permission
//              * @devdesc           Error calling mm_set_permission for WOFDATA
//              * @custdesc          Firmware Error
//              */
//             l_errl = new ERRORLOG::ErrlEntry(
//                                ERRORLOG::ERRL_SEV_INFORMATIONAL,
//                                fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
//                                fapi2::RC_MM_SET_PERMISSION_FAILED,
//                                VMM_VADDR_WOFDATA_LID,
//                                TWO_UINT32_TO_UINT64(VMM_SIZE_WOFDATA_LID,
//                                                     l_mm_rc),
//                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
//             // Add the error log pointer as data to the ReturnCode
//             addErrlPtrToReturnCode(l_rc, l_errl);
//             break;
//         }

//         // Point my local pointer at the VMM space we allocated
//         l_pWofImage = g_wofdataVMM;

//         // Get the tables from PNOR or lid
//         l_errl = l_wofLidMgr.getLid(l_pWofImage, l_lidImageSize);
// #endif

//         if(l_errl)
//         {
//             FAPI_ERR("platParseWOFTables getLid failed "
//                      "pLidImage %p imageSize %d",
//                      l_pWofImage, l_lidImageSize);
//             // Add the error log pointer as data to the ReturnCode
//             addErrlPtrToReturnCode(l_rc, l_errl);
//             break;
//         }

//         // Get the Image Header
//         wofImageHeader_t* l_img =
//                 reinterpret_cast<wofImageHeader_t*>(l_pWofImage);

//         // Check header's version and magic number values
//         l_errl = checkWofImgHeaderForCorrectness(l_img->magicNumber,
//                     l_img->version, &l_lidNumber);

//         if (l_errl)
//         {
//             // Add the error log pointer as data to the ReturnCode
//             addErrlPtrToReturnCode(l_rc, l_errl);
//             break;
//         }

//         // Image info
//         FAPI_INF("(Retrieved using UtilLidMgr) WOF Image: Magic 0x%X "
//                  "Version %d Entries %d Offset %p",
//                  l_img->magicNumber, l_img->version,
//                  l_img->entryCount, l_img->offset);

//         // Get a pointer to the first section table entry
//         wofSectionTableEntry_t* l_ste =
//             reinterpret_cast<wofSectionTableEntry_t*>
//                 (reinterpret_cast<uint8_t*>(l_pWofImage) + l_img->offset);

//         WofTablesHeader_t* l_wth = nullptr;
//         uint32_t l_ent = 0; // entry index
//         uint32_t l_ver = 0; // WOF table header version

//         // Using WOF image retrieved using UtilLidMgr, loop through all section
//         // table entries until a WOF table header is found that matches the
//         // criteria set above.
//         // When running on Simics it is possible that the number of cores found
//         // on the master proc are less than expected, in which case we match
//         // with a WOF table by ignoring this value.
//         // If no matching WOF header is found, then entry will be fetched from
//         // SEEPROM.
//         for( l_ent = 0; l_ent < l_img->entryCount; l_ent++ )
//         {
//             // Get a pointer to the WOF table
//             l_wth = reinterpret_cast<WofTablesHeader_t*>
//                         (reinterpret_cast<uint8_t*>(l_pWofImage)
//                             + l_ste[l_ent].offset);
//             l_ver = l_wth->header_version;

//             // Check WOF table header entry version number and magic value
//             l_errl = checkWofTableHeaderForCorrectness(l_wth->magic_number.value, l_ver, &l_ent);

//             if (l_errl)
//             {
//                 // Add the error log pointer as data to the ReturnCode
//                 addErrlPtrToReturnCode(l_rc, l_errl);
//                 break;
//             }

//             // Trace the WOF table fields
//             FAPI_INF("(Retrieved using UtilLidMgr) WOF table fields "
//                      "SectionTableEntry %d "
//                      "SectionTableOffset 0x%X "
//                      "SectionTableSize %d "
//                      "Version %d Mode %d Cores %d SocketPower 0x%X "
//                      "NomFreq 0x%X",
//                      l_ent, l_ste[l_ent].offset, l_ste[l_ent].size,
//                      l_ver, l_wth->ocs_mode, l_wth->core_count,
//                      l_wth->socket_power_w,
//                      l_wth->sort_power_freq_mhz);

//             // Checking if header was was found using WOF data section from PNOR
//             // by comparing criteria fields.
//             if( (l_wth->core_count == l_numCores) &&
//                 (l_wth->socket_power_w == l_socketPower) &&
//                 (l_wth->sort_power_freq_mhz == l_sortFreq) &&
//                 ((l_ver < WOF_TABLE_VERSION_POWERMODE) ||  // mode is ignored
//                  ((l_ver >= WOF_TABLE_VERSION_POWERMODE) &&
//                   ((l_wth->ocs_mode == l_mode) ||  // match specific mode
//                    (l_wth->ocs_mode == WOF_MODE_UNKNOWN)))) // or wild-card
//               )
//             {
//                 FAPI_INF("(Retrieved using UtilLidMgr) Found a WOF table match");
//                 FAPI_INF("core_count: %d, socket power w: %d, sort power freq MHz: %d, ver: %d, mode: %d",
//                     l_numCores, l_socketPower, l_sortFreq, l_ver, l_mode);

//                 l_didFindWTH = true;

//                 // Copy the WOF table retrieved using UtilLidMgr to the output pointer
//                 memcpy(o_wofData,
//                        reinterpret_cast<uint8_t*>(l_wth),
//                        l_ste[l_ent].size);
//                 break;
//             }
//             else
//             {
//                 // We run with fewer cores in Simics, ignore the core field
//                 // if we don't find a complete match
//                 if( Util::isSimicsRunning() && l_simMatch == nullptr )
//                 {
//                     if( (l_wth->socket_power_w == l_socketPower) &&
//                         (l_wth->sort_power_freq_mhz == l_sortFreq) &&
//                         ((l_ver < WOF_TABLE_VERSION_POWERMODE) || //mode ignored
//                          ((l_ver >= WOF_TABLE_VERSION_POWERMODE) &&
//                           ((l_wth->ocs_mode == l_mode) ||  // match specific mode
//                           (l_wth->ocs_mode == WOF_MODE_UNKNOWN)))) // or wild-card
//                       )
//                     {
//                         FAPI_INF("(Retrieved using UtilLidMgr) Found a "
//                                     "potential WOF table match for Simics");
//                         // Copy the WOF table to a local var temporarily
//                         l_simMatchSize = l_ste[l_ent].size;
//                         l_simMatch = new uint8_t[l_simMatchSize];
//                         memcpy(l_simMatch,
//                                reinterpret_cast<uint8_t*>(l_wth),
//                                l_simMatchSize);
//                     }
//                 }
//             }
//         }

//         if(l_errl)
//         {
//             break;
//         }

//         if( Util::isSimicsRunning()
//             && (l_ent == l_img->entryCount)
//             && (l_simMatch != nullptr) )
//         {
//             WofTablesHeader_t* l_tableHeader =
//                 reinterpret_cast<WofTablesHeader_t*>(l_simMatch);
//             FAPI_INF("(Retrieved using UtilLidMgr) Found a WOF table match "
//                 "using fuzzy match for Simics");
//             FAPI_INF("core_count: %d, socket power w: %d, sort power freq MHz: %d, ver: %d, mode: %d",
//                 l_tableHeader->core_count, l_tableHeader->socket_power_w, l_wth->sort_power_freq_mhz, l_tableHeader->header_version, l_tableHeader->ocs_mode);

//             l_didFindWTH = true;

//             // Copy the WOF table to the ouput pointer
//             memcpy(o_wofData,
//                    l_simMatch,
//                    l_simMatchSize);
//         }

//     } while(0);

    if (!l_didFindWTH)
    {
        // Did not find WOF table header using UtilLidMgr, get data from SEEPROM

/* TODO 250903: WOF Selection Algorithm for P10
        FAPI_INF("No WOF table match found using UtilLidMgr");
*/
        FAPI_INF("Get WOF table from Backup SEEPROM");

        l_errl = getDefaultWofTable(i_procTarg, o_wofData);

        if (l_errl)
        {
            FAPI_ERR("Failed to get WOF table header entry from Backup "
                "SEEPROM");

            // If the default WOF data was not fetched due to some error, then the code path
            // ends up here.
            // If any error was encountered in the do-while loop above, then l_rc will have
            // pointers to those error logs.
            // In any case, for any error encountered while fetching WOF, the code path ends up
            // here, therefore we just need to collectTace here.
            l_errl->collectTrace(FAPI_TRACE_NAME, 256);

            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
        }
        else
        {
            // WOF table header successfully retrieved from SEEPROM
            FAPI_INF("WOF table header entry successfully retrieved from Backup SEEPROM");

            // If Wof has been fetched from SEEPROM (using getDefaultWofTable) without any errors,
            // then the fapi2 return code needs to show success.
            // There's a possibility that while trying to find a WOF table header match using
            // UtilLidMgr, an error may have been encountered. However, since WOF was successfully
            // retrieved from SEEPROM we can disregard those errors,
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }
    }

    // Free the wof tables memory
    if(l_pWofImage != nullptr)
    {
#ifndef __HOSTBOOT_RUNTIME
        errlHndl_t l_tmpErr = nullptr;
        // Release the memory we may still have allocated and set the
        //  permissions to prevent further access to it
        int l_mm_rc = mm_remove_pages(RELEASE,
                                      l_pWofImage,
                                      VMM_SIZE_WOFDATA_LID);
        if( l_mm_rc )
        {
            FAPI_INF("Fail from mm_remove_pages for WOFDATA, rc=%d", l_mm_rc);

            /* FIXME 255501 Revert back to ERRL_SEV_UNRECOVERABLE*/
            /*@
             * @errortype
             * @moduleid          fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES
             * @reasoncode        fapi2::RC_MM_REMOVE_PAGES_FAILED
             * @userdata1         Address being removed
             * @userdata2[00:31]  Size of removal
             * @userdata2[32:63]  rc from mm_remove_pages
             * @devdesc           Error calling mm_remove_pages for WOFDATA
             * @custdesc          Firmware Error
             */
            l_tmpErr = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                   fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
                                   fapi2::RC_MM_REMOVE_PAGES_FAILED,
                                   reinterpret_cast<uint64_t>(l_pWofImage),
                                   TWO_UINT32_TO_UINT64(VMM_SIZE_WOFDATA_LID,
                                                        l_mm_rc),
                                   ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_tmpErr->collectTrace(FAPI_TRACE_NAME, 256);
            errlCommit(l_tmpErr, FAPI2_COMP_ID);
        }
        l_mm_rc = mm_set_permission(l_pWofImage,
                                    VMM_SIZE_WOFDATA_LID,
                                    NO_ACCESS | ALLOCATE_FROM_ZERO );
        if( l_mm_rc )
        {
            FAPI_INF("Fail from mm_set_permission reset for WOFDATA, rc=%d", l_mm_rc);

            /* FIXME 255501 Revert back to ERRL_SEV_UNRECOVERABLE*/
            /*@
             * @errortype
             * @moduleid          fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES
             * @reasoncode        fapi2::RC_MM_SET_PERMISSION2_FAILED
             * @userdata1         Address being changed
             * @userdata2[00:31]  Size of change
             * @userdata2[32:63]  rc from mm_set_permission
             * @devdesc           Error calling mm_set_permission for WOFDATA
             * @custdesc          Firmware Error
             */
            l_tmpErr = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                   fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
                                   fapi2::RC_MM_SET_PERMISSION2_FAILED,
                                   reinterpret_cast<uint64_t>(l_pWofImage),
                                   TWO_UINT32_TO_UINT64(VMM_SIZE_WOFDATA_LID,
                                                        l_mm_rc),
                                   ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_tmpErr->collectTrace(FAPI_TRACE_NAME, 256);
            errlCommit(l_tmpErr, FAPI2_COMP_ID);
        }
#endif

    }

    if( l_simMatch )
    {
        delete[] l_simMatch;
    }

    FAPI_DBG("Exiting platParseWOFTables ....");

    return l_rc;

}

/* End of platParseWOFTables(...) */



/* Helper methods for platParseWOFTables(...) */


errlHndl_t getDefaultWofTable(TARGETING::Target* i_target, uint8_t* o_wofData)
{
    FAPI_DBG("Entering getDefaultWofTable ....");

    // Assert if o_wofData is nullptr
    assert(o_wofData != nullptr, "Error! In plat_wof_access.C getDefaultWofTable(), function "
        "argument o_wofData cannot be nullptr.");

    errlHndl_t l_errl = nullptr;

    // Get ATTR_WOF_INDEX_SELECT (uint8_t), which will be used to figure out
    // which WOF Section Table Entry to fetch
    TARGETING::Target * l_sys = UTIL::assertGetToplevelTarget();
    fapi2::ATTR_WOF_INDEX_SELECT_Type l_idxSelect = l_sys->getAttr<TARGETING::ATTR_WOF_INDEX_SELECT>();

    FAPI_INF("Getting WOF table data from WOF image in Backup SEEPROM, selection index "
        "ATTR_WOF_INDEX_SELECT: %u", l_idxSelect);

    // Get WOF Table Header
    do {

        // Get WOF image header
        wofImageHeader_t l_imgHeader;
        l_errl = getSeepromEccLessWofData(i_target, sizeof(l_imgHeader), 0, &l_imgHeader);
        if (l_errl)
        {
            break;
        }

        // Check header's version and magic number values
        l_errl = checkWofImgHeaderForCorrectness(i_target, l_imgHeader.magicNumber, l_imgHeader.version);
        if (l_errl)
        {
            break;
        }

        // WOF header image info
        FAPI_INF("(Retrieved from SEEPROM) WOF Image Header Values: Magic 0x%X "
            "Version %d Entries %d Offset %p", l_imgHeader.magicNumber,
            l_imgHeader.version, l_imgHeader.entryCount, l_imgHeader.offset);

        // Make sure that header entryCount includes MRW selection index (l_idxSelect)
        if ((l_idxSelect + 1) > l_imgHeader.entryCount)
        {
            FAPI_ERR("(Retrieved from SEEPROM) ATTR_MRW_WOF_TABLE_SELECTION_INDEX "
                "value %u is out of range, only %d table header entries found",
                l_idxSelect, l_imgHeader.entryCount);

            /* FIXME 255501 Revert back to ERRL_SEV_UNRECOVERABLE*/
            /*@
            * @errortype
            * @moduleid    fapi2::MOD_FAPI2_GET_DEFAULT_WOF_TABLE
            * @reasoncode  fapi2::RC_WOF_MRW_IDX_NOT_INCLUDED
            * @userdata1   MRW WOF selection index
            * @userdata2   Entry count in SEEPROM WOF image
            * @devdesc     MRW WOF selection index value not included in SEEPROM WOF image entries
            * @custdesc    Unsupported processor module
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            fapi2::MOD_FAPI2_GET_DEFAULT_WOF_TABLE,
                            fapi2::RC_WOF_MRW_IDX_NOT_INCLUDED,
                            l_idxSelect,
                            l_imgHeader.entryCount);
            l_errl->addHwCallout(i_target, HWAS::SRCI_PRIORITY_HIGH, HWAS::DELAYED_DECONFIG, HWAS::GARD_NULL);
            break;
        }

        // Get Section Table Entry based on MRW selection index
        wofSectionTableEntry_t l_tableEntry;
        size_t l_entryOffset = l_imgHeader.offset + (l_idxSelect * sizeof(l_tableEntry));
        l_errl = getSeepromEccLessWofData(i_target, sizeof(l_tableEntry), l_entryOffset, &l_tableEntry);

        if (l_errl)
        {
            break;
        }

        // Make sure that calculated offset and size of WOF table header entry does
        // not go beyond the bounds of the WOF image

        // Get WOF DATA info
        TARGETING::SpiWofDataInfo spiWOFDataInfo = i_target->getAttr<TARGETING::ATTR_SPI_WOF_DATA_INFO>();

        // Get data size of WOF image
        const size_t l_wofImgSize = spiWOFDataInfo.dataSizeKB * CONVERSIONS::BYTES_PER_KB;

        if (l_wofImgSize < (l_tableEntry.offset + l_tableEntry.size))
        {
            const uint32_t l_endOfHeader = l_tableEntry.offset + l_tableEntry.size;

            FAPI_ERR("(Retrieved from SEEPROM) WOF Table Header to be fetched "
                "goes beyond bounds of WOF image. WOF image size: %lu, entry "
                "offset + size = %u + %u = %u", l_wofImgSize, l_tableEntry.offset,
                l_tableEntry.size, l_endOfHeader);

            /* FIXME 255501 Revert back to ERRL_SEV_UNRECOVERABLE*/
            /*@
            * @errortype
            * @moduleid          fapi2::MOD_FAPI2_GET_DEFAULT_WOF_TABLE
            * @reasoncode        fapi2::RC_WOF_HEADER_ENTRY_BEYOND_IMG
            * @userdata1[00:31]  Offset of table header entry in WOF image
            * @userdata1[32:63]  Size of table header entry
            * @userdata2[00:31]  Selection index ATTR_WOF_INDEX_SELECT
            * @userdata2[32:63]  Size of WOF image
            * @devdesc           WOF table header entry to be fetched goes beyond WOF image in SEEPROM
            * @custdesc          Unsupported processor module
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            fapi2::MOD_FAPI2_GET_DEFAULT_WOF_TABLE,
                            fapi2::RC_WOF_HEADER_ENTRY_BEYOND_IMG,
                            TWO_UINT32_TO_UINT64(l_tableEntry.offset, l_tableEntry.size),
                            TWO_UINT32_TO_UINT64(l_idxSelect, l_wofImgSize));
            l_errl->addHwCallout(i_target, HWAS::SRCI_PRIORITY_HIGH, HWAS::DELAYED_DECONFIG, HWAS::GARD_NULL);
            break;
        }

        // Get WOF Table Header and put it in allocated memory from o_wofData
        l_errl = getSeepromEccLessWofData(i_target, l_tableEntry.size, l_tableEntry.offset, o_wofData);
        if (l_errl)
        {
            break;
        }

        // Check WOF table header entry version number and magic value
        WofTablesHeader_t* l_tableHeader = reinterpret_cast<WofTablesHeader_t*>(o_wofData);

        l_errl = checkWofTableHeaderForCorrectness(i_target, l_tableHeader->magic_number.value,
            l_tableHeader->header_version);

        if (l_errl)
        {
            break;
        }

        // WOF table header fields
        FAPI_INF("(Retrieved from SEEPROM) WOF Header Table Fields: "
            "SectionTableOffset 0x%X SectionTableSize %d "
            "Version %d Mode %d Cores %d SocketPower 0x%X NomFreq 0x%X",
            l_tableEntry.offset, l_tableEntry.size,
            l_tableHeader->header_version, l_tableHeader->ocs_mode,
            l_tableHeader->core_count, l_tableHeader->socket_power_w,
            l_tableHeader->sort_power_freq_mhz);

    } while(0);

    return l_errl;

}



errlHndl_t getSeepromEccLessWofData(TARGETING::Target* i_procTarg, size_t i_buflen,
                                    size_t i_offset, void* o_buffer)
{
    /*
    Notes on removing ECC from WOF+ECC:
    - The ECC algo we use is that every 8-byte word is followed by 1-byte ECC word
    - This means that to correctly remove the ECC from any subset of data from the WOF+ECC image,
      we need to:
      - fetch the data at 8-byte alignment offsets
      - fetch more data than we need to account for ECC
        - E.g.: wofImageHeader_t is an 10-byte struct, if the data-packet is 8-byte aligned then we
          need to fetch 8-byte data + 1 byte ECC + 8-byte data + 1 byte ECC = 18-bytes
        - If the data-packet is not aligned, we would need to fetch from a smaller offset that is
          aligned, and possibly increase the amout of ECC data we read.

    After all this is done, ECC can be removed and the WOF data packet returned via o_buffer.
    */

    FAPI_DBG("Entering getSeepromEccLessWofData ....");

    errlHndl_t l_errl = nullptr;

    constexpr size_t l_eccBlock = 9;     // 9 bytes: 8 bytes of data + 1 byte of ECC
    constexpr size_t l_eccLessBlock = 8; // 8 bytes describing the part of the ECC block without ECC

    // Number of l_eccBlock(s) that make up length of data to read from WOF+ECC
    // Note that this value will increase if we're not reading at an 8-byte offset and/or if the
    // data length is not 8-byte divisible
    size_t l_eccBuflenBlocks = 0;

    /* Calculate offset in WOF+ECC data */

    // Number of l_eccBlock(s) to be at an offset that will contain data being fetched
    size_t l_eccOffsetBlocks = i_offset / l_eccLessBlock;
    // By taking the floor, we may in fact be reading at a smaller offset. To correct for that,
    // we'll read an extra block:
    size_t l_eccOffsetExtraByte = i_offset % l_eccLessBlock;
    if (l_eccOffsetExtraByte)
    {
        l_eccBuflenBlocks += 1;
    }

    /* Calculate buffer size in WOF+ECC data */

    // Number of l_eccBlock(s) needed to read all data in i_buflen
    l_eccBuflenBlocks += i_buflen / l_eccLessBlock;
    // Add one more block if the data length i_buflen is not 8-byte divisible
    if (i_buflen % l_eccLessBlock)
    {
        l_eccBuflenBlocks += 1;
    }

    FAPI_DBG("getSeepromEccLessWofData: Read WOF+ECC data with ECC offset blocks: %u "
             "size blocks: %u", l_eccOffsetBlocks, l_eccBuflenBlocks);

    /*
    Read WOF+ECC data
    - l_eccDataBuf: buffer to store WOF+ECC data
    - l_eccLessBuflen: buffer to store WOF only data
    - Both l_eccDataBuf and l_eccLessBuflen may have more WOF data than we need in the cases where
      the data is not 8-byte aligned and/or is not 8-byte divisible

    At the end, l_eccLessBuflen will be memcpy to o_buffer with the correct offset address and
    size i_buflen
    */

    // Buffer length and offset for WOF+ECC data
    size_t l_eccBuflen = l_eccBuflenBlocks * l_eccBlock;
    size_t l_eccOffset = l_eccOffsetBlocks * l_eccBlock;
    // Allocate large chunk of memory for WOF+ECC (though the header entries are small, the WOF
    // tables are fairly large structures)
    uint8_t* l_eccDataBuf = new uint8_t[l_eccBuflen];
    // Allocate large chunk of memory for WOF only
    size_t l_eccLessBuflen = l_eccBuflenBlocks * l_eccLessBlock;
    uint8_t* l_eccLessDataBuf = new uint8_t[l_eccLessBuflen];

    do
    {
        // Read WOF+ECC
        l_errl = deviceRead(i_procTarg, l_eccDataBuf, l_eccBuflen,
                 DEVICE_EEPROM_ADDRESS(EEPROM::WOF_DATA, l_eccOffset, EEPROM::AUTOSELECT));

        if (l_errl)
        {
            FAPI_ERR("getSeepromEccLessWofData: Error on deviceRead WOF+ECC data l_eccDataBuf: %u, "
                     "l_eccBuflen: %u, l_eccOffset: %u", l_eccDataBuf, l_eccBuflen, l_eccOffset);
            break;
        }

        /* Remove ECC */

        // Aliasing namespace for readability. Done here because PNOR::ECC package is only used here
        namespace PE = PNOR::ECC;

        PE::eccStatus l_eccStat = PE::removeECC(l_eccDataBuf, l_eccLessDataBuf, l_eccLessBuflen);

        switch(l_eccStat) {
        case PE::CLEAN:
            FAPI_INF("getSeepromEccLessWofData: successfully removed ECC from WOF data block when "
                     "reading i_buflen: %u, i_offset: %u", i_buflen,  i_offset);
            break;
        case PE::CORRECTED:
            // TODO RTC: 260978 Write back WOF data to EECACHE if ECC is correctable.
            FAPI_INF("getSeepromEccLessWofData: ECC correction was needed to successfully remove "
                     "ECC from WOF data block when reading i_buflen: %u, i_offset: %u",
                     i_buflen,  i_offset);
            break;
        case PE::UNCORRECTABLE:
            FAPI_ERR("getSeepromEccLessWofData: ECC removal was uncorrectable when removing ECC "
                     "from WOF when reading: i_buflen: %u i_offset: %u i_procTarg HUID: 0x%.8X",
                     i_buflen,  i_offset, TARGETING::get_huid(i_procTarg));
            /* FIXME 255501 Revert back to ERRL_SEV_UNRECOVERABLE*/
            /*@
            * @errortype
            * @moduleid          fapi2::MOD_GET_SEEPROM_ECC_LESS_WOF_DATA
            * @reasoncode        fapi2::RC_WOF_READ_UNCORRECTABLE_ECC
            * @userdata1         Offset used to read WOF+ECC data from SEEPROM
            * @userdata2         Buffer length used to read WOF+ECC data from SEEPROM
            * @devdesc           WOF data has uncorrectable ECC
            * @custdesc          Hardware error inside processor module
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            fapi2::MOD_GET_SEEPROM_ECC_LESS_WOF_DATA,
                            fapi2::RC_WOF_READ_UNCORRECTABLE_ECC,
                            l_eccOffset,
                            l_eccBuflen);
            l_errl->addHwCallout(i_procTarg, HWAS::SRCI_PRIORITY_HIGH, HWAS::DELAYED_DECONFIG, HWAS::GARD_NULL);
            // If this error is seen, then with the l_eccOffset and l_eccBuflen you can find the
            // area of the WOF image that was read
            break;
        }

        // Debug, print first 32 bytes of WOF data being fetched
        // (or less if data length being fetched is smaller)
        size_t l_debugBinLen = 32;
        // "&& l_debugBinLen" is included in if-statement so that we don't get
        // "-Werror=unused-but-set-variable" compiler error
        if (i_buflen < 32 && l_debugBinLen)
        {
            l_debugBinLen = i_buflen;
        }
        TRACDBIN(g_fapiDbgTd, "Sample of WOF eec-less bytes read: ",
                 &l_eccLessDataBuf[l_eccOffsetExtraByte], l_debugBinLen);

        if (l_errl)
        {
            // Error caught in switch-case statement
            break;
        }

        /* Copy ECC-less WOF data to output o_buffer */
        // l_eccOffsetExtraByte is being used because we may have read at a smaller offset so that
        // we'd be 8-byte aligned
        memcpy(o_buffer, &l_eccLessDataBuf[l_eccOffsetExtraByte], i_buflen);

    } while (0);

    // Clean up
    delete[] l_eccDataBuf;
    delete[] l_eccLessDataBuf;

    return l_errl;
}



errlHndl_t checkWofImgHeaderForCorrectness(TARGETING::Target* i_procTarg,
                                           const uint32_t i_magicNum,
                                           const uint8_t i_version,
                                           const uint32_t* i_lidNum)
{

    errlHndl_t l_errl = nullptr;
    uint64_t l_userData1(0), l_userData2(0);

    do
    {
        // Check for the eyecatcher (magic number)
        if(i_magicNum != WOF_IMAGE_MAGIC_VALUE)
        {
            l_userData1 = TWO_UINT32_TO_UINT64(i_magicNum, WOF_IMAGE_MAGIC_VALUE);
            if (i_lidNum)
            {
                // UtilLidMgr was used to get WOF img
                FAPI_ERR("(Retrieved using UtilLidMgr) WOF Image Header Magic Value"
                " Mismatch 0x%X != WTIH(0x%X)", i_magicNum, WOF_IMAGE_MAGIC_VALUE);

                l_userData2 = TWO_UINT32_TO_UINT64(i_version, *i_lidNum);
            }
            else
            {
                FAPI_ERR("(Retrieved from SEEPROM) WOF Image Header Magic Value "
                "Mismatch 0x%X != WTIH(0x%X)", i_magicNum, WOF_IMAGE_MAGIC_VALUE);
                l_userData2 = TO_UINT64(i_version);
            }

            /* FIXME 255501 Revert back to ERRL_SEV_UNRECOVERABLE*/
            /*@
            * @errortype
            * @moduleid          fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES
            * @reasoncode        fapi2::RC_WOF_IMAGE_MAGIC_MISMATCH
            * @userdata1[00:31]  Image header magic value
            * @userdata1[32:63]  Expected magic value
            * @userdata2[00:31]  Image header version
            * @userdata2[32:63]  The LID ID if WOF img was retrieved from PNOR.
            *                    0 if WOF img was retrieved from EEPROM.
            * @devdesc           WOF image header magic value mismatch
            * @custdesc          Unsupported processor module
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
                            fapi2::RC_WOF_IMAGE_MAGIC_MISMATCH,
                            l_userData1,
                            l_userData2);
            l_errl->addHwCallout(i_procTarg, HWAS::SRCI_PRIORITY_HIGH, HWAS::DELAYED_DECONFIG, HWAS::GARD_NULL);
            break;
        }

        // Check for a valid image header version
        if(i_version != WOF_IMAGE_VERSION)
        {
            l_userData1 = TWO_UINT32_TO_UINT64(i_version, WOF_IMAGE_VERSION);
            if (i_lidNum)
            {
                // UtilLidMgr was used to get WOF img
                FAPI_ERR("(Retrieved using UtilLidMgr) WOF Image header version "
                    "not supported: Header Version %d, Supported Version is "
                    "%d", i_version, WOF_IMAGE_VERSION);
                l_userData2 = TO_UINT64(*i_lidNum);
            }
            else
            {
                FAPI_ERR("(Retrieved from SEEPROM) WOF Image header version not "
                    "supported: Header Version %d, Supported Version is "
                    "%d", i_version, WOF_IMAGE_VERSION);
                l_userData2 = 0;
            }

            /* FIXME 255501 Revert back to ERRL_SEV_UNRECOVERABLE*/
            /*@
            * @errortype
            * @moduleid          fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES
            * @reasoncode        fapi2::RC_WOF_IMAGE_VERSION_MISMATCH
            * @userdata1[00:31]  Image header version
            * @userdata1[32:63]  Supported header version
            * @userdata2         The LID ID if WOF img was retrieved from PNOR.
            *                    0 if WOF img was retrieved from EEPROM.
            * @devdesc           Image header version not supported
            * @custdesc          Unsupported processor module for current firmware version
            */
            l_errl = new ERRORLOG::ErrlEntry(
                             ERRORLOG::ERRL_SEV_INFORMATIONAL,
                             fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
                             fapi2::RC_WOF_IMAGE_VERSION_MISMATCH,
                             l_userData1,
                             l_userData2,
                             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_errl->addHwCallout(i_procTarg, HWAS::SRCI_PRIORITY_LOW, HWAS::DELAYED_DECONFIG, HWAS::GARD_NULL);

            break;
        }
    } while (0);

    return(l_errl);

}



errlHndl_t checkWofTableHeaderForCorrectness(TARGETING::Target* i_procTarg,
                                             const uint32_t i_magicVal,
                                             const uint8_t i_version,
                                             const uint32_t* i_entry)
{

    errlHndl_t l_errl = nullptr;
    uint64_t l_userData1(0), l_userData2(0);

    do
    {
        // Check for the eyecatcher (magic num)
        if(i_magicVal != WOF_TABLES_MAGIC_VALUE)
        {
            l_userData1 = TWO_UINT32_TO_UINT64(i_magicVal, WOF_TABLES_MAGIC_VALUE);
            if (i_entry)
            {
                // UtilLidMgr was used to get WOF img
                FAPI_ERR("(Retrieved using UtilLidMgr) WOF Table Header Magic "
                    "Value Mismatch 0x%X != WFTH(0x%X)", i_magicVal,
                    WOF_TABLES_MAGIC_VALUE);
                l_userData2 = TWO_UINT32_TO_UINT64(i_version, *i_entry);
            }
            else
            {
                FAPI_ERR("(Retrieved from SEEPROM) WOF Table Header Magic Value "
                    "Mismatch 0x%X != WFTH(0x%X)", i_magicVal,
                    WOF_TABLES_MAGIC_VALUE);
                l_userData2 = TO_UINT64(i_version);
            }

            /* FIXME 255501 Revert back to ERRL_SEV_UNRECOVERABLE*/
            /*@
            * @errortype
            * @moduleid          fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES
            * @reasoncode        fapi2::RC_WOF_TABLES_MAGIC_MISMATCH
            * @userdata1[00:31]  WOF tables header magic value
            * @userdata1[32:63]  Expected magic value
            * @userdata2[00:31]  WOF tables header version
            * @userdata2[32:63]  WOF tables entry number if WOF img was retrieved
            *                    from PNOR.
            *                    0 if WOF img was retrieved from EEPROM.
            * @devdesc           WOF tables header magic value mismatch
            * @custdesc          Unsupported processor module
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
                            fapi2::RC_WOF_TABLES_MAGIC_MISMATCH,
                            l_userData1,
                            l_userData2);
            l_errl->addHwCallout(i_procTarg, HWAS::SRCI_PRIORITY_HIGH, HWAS::DELAYED_DECONFIG, HWAS::GARD_NULL);
            break;
        }

        // Check for a valid tables header version
        if(i_version != WOF_TABLE_VERSION)
        {
            l_userData1 = TWO_UINT32_TO_UINT64(i_version, WOF_TABLE_VERSION);
            if (i_entry)
            {
                // UtilLidMgr was used to get WOF img
                FAPI_ERR("(Retrieved using UtilLidMgr) WOF table header version "
                    "not supported: Header Version %d, Supported Version is "
                    "%d", i_version, WOF_TABLE_VERSION);
                l_userData2 = TO_UINT64(*i_entry);
            }
            else
            {
                FAPI_ERR("(Retrieved from SEEPROM) WOF table header version not "
                    "supported: Header Version %d, Supported Version is "
                    "%d", i_version, WOF_TABLE_VERSION);
                l_userData2 = 0;
            }

            /* FIXME 255501 Revert back to ERRL_SEV_UNRECOVERABLE*/
            /*@
            * @errortype
            * @moduleid          fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES
            * @reasoncode        fapi2::RC_WOF_TABLES_VERSION_MISMATCH
            * @userdata1[00:31]  WOF tables header version
            * @userdata1[32:63]  Max supported header version
            * @userdata2         WOF tables entry number if WOF img was retrieved
            *                    from PNOR.
            *                    0 if WOF img was retrieved from EEPROM.
            * @devdesc           WOF tables header version not supported
            * @custdesc          Unsupported processor module for current firmware level
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
                            fapi2::RC_WOF_TABLES_VERSION_MISMATCH,
                            l_userData1,
                            l_userData2,
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_errl->addHwCallout(i_procTarg, HWAS::SRCI_PRIORITY_LOW, HWAS::DELAYED_DECONFIG, HWAS::GARD_NULL);

            break;
        }

    } while (0);

    return l_errl;

}

/* End of helper methods for platParseWOFTables(...) */



} // End platAttrSvc namespace
} // End fapi2 namespace
