/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_wof_access.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
#include <p10_wof_override_structure.H>
#include <p10_wof_table_set_structure.H>

/*
Defining images containing WOF Tables that this file deals with:

- WOF Table: WOF information made up of a header (WofTablesHeader_t) and WOF data.
- WOF Image: An image made up of three WOF Tables.
  Its structure is made up of a header (wofImageHeader_t), a TOC section containing entries
  that point to the three WOF Tables (wofSectionTableEntry_t), and the three WOF Tables.
- WOF Override Image: An image made up of multiple WOF Images.
  Its structure is made up of a header (wofContainerHeader_t), a TOC section containing entries
  that point to the multiple WOF Images (wofOverrideTableEntry_t), and the multiple WOF Images.

Where these images come from:

- WOF in SEEPROM (or EECACHE if cached):
  The SEEPROM only contains a single WOF Image to be used if no override image can be used.
- WOF in a LID container (i.e. WOFDATA LID):
  This contains a single WOF Override Image. If the current system meets one of the criteria set by
  one of the many WOF Images here, then that WOF Image is used instead of the one in the SEEPROM.

The entry point to code in this file is through platParseWOFTables(...), but only by doing the
following call:

    fapi2::ATTR_WOF_TABLE_DATA_Type* l_wof_table_data =
        (fapi2::ATTR_WOF_TABLE_DATA_Type*)new fapi2::ATTR_WOF_TABLE_DATA_Type;
    l_rc = FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_DATA, procTarg, (*l_wof_table_data));
*/

using namespace TARGETING;

namespace fapi2
{

namespace platAttrSvc
{

const uint32_t WOF_IMAGE_MAGIC_VALUE    = 0x57544948; // "WTIH": WOF Tables Image Header
const uint32_t WOF_TABLES_MAGIC_VALUE   = 0x57465448; // "WFTH": WOF Tables Header
const uint32_t WOF_OVERRIDE_MAGIC_VALUE = 0x5754534f; // "WTSO": WOF Table Set Override
const uint32_t WOF_IMAGE_VERSION    = 1;
const uint32_t WOF_TABLE_VERSION    = 1;
const uint32_t WOF_OVERRIDE_VERSION = 1;

#ifndef __HOSTBOOT_RUNTIME
// File global pointer to WOFDATA lid in VM (VMM_VADDR_WOFDATA_LID)
static void* g_wofdataVMM = nullptr;
#endif

/*
NOTE: uint and struct must match in errl/plugins/errludwofdata.H and ErrlUserDetailsParserWofData in
src/usr/errl/plugins/ebmc/b0100.py
*/
const uint8_t WOF_OVERRIDE_ERROR_UD_VERSION = 1;
typedef struct __attribute__((__packed__)) wofOverrideCompareData
{
    // Data pulled from the TOC section of the WOF Override Image. I.e. data from
    // wofOverrideTableEntry_t used to search for an override set.
    uint8_t  core_count;
    uint16_t socket_power_w;
    uint16_t sort_power_freq_mhz;
} wofOverrideCompareData_t;

/*
The main function of this file is platParseWOFTables(...), which is ultimately used when getting
ATTR_WOF_TABLE_DATA using the FAPI_ATTR_GET macro.

The following are the helper functions used inside of platParseWOFTables(...)
*/

/**
 *  @brief Get WOF Table from SEEPROM (or EECACHE if cached).
 *  The table selected is based on the value of ATTR_WOF_INDEX_SELECT.
 *
 *  @param[in] i_procTarg       Proc chip target handle pointer
 *  @param[out] o_wofData       Pointer to memory allocated in the heap for
 *                              large WOF Table data, which includes
 *                              corresponding WOF Table Header and VRT data.
 *
 *  @return errlHndl_t    - nullptr if no errors encountered
 *                        - else error handler will contain error info
 */
errlHndl_t getSeepromWofTable(TARGETING::Target* i_procTarg, uint8_t* o_wofData);

/**
 *  @brief Get blocks of data from WOF data in the Backup SEEPROM.
 *  WOF data in the SEEPROM has ECC, therefore this method will remove ECC and
 *  return ECC-less WOF data.
 *  The data offset and size arguments should not take into account ECC, this function will
 *  translate those values to valid ECC-aligned offset and size.
 *
 *  @param[in] i_procTarg       Proc chip target handle pointer
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
 *  @brief Get override WOF Table from WOFDATA LID. The table selected is based on system config
 *  criteria and the value of ATTR_WOF_INDEX_SELECT.
 *
 *  @param[in] i_procTarg       Proc chip target handle pointer
 *  @param[out] o_wofData       Pointer to memory allocated from the heap for
 *                              large WOF Table data, which includes
 *                              corresponding WOF Table Header and VRT (Voltage Ratio Table) data.
 *  @param[out] o_didFindTable  Bool stating if a WOF Table was found or not
 *
 *  @return errlHndl_t    - nullptr if no errors encountered
 *                        - else error handler will contain error info
 */
errlHndl_t getOverrideWofTable(TARGETING::Target* i_procTarg, uint8_t* o_wofData, bool& o_didFindTable);

/**
 *  @brief Checks that in the WOF image header, the magic number equals
 *  WOF_IMAGE_MAGIC_VALUE and that version number is a supported level.
 *
 *  @param[in] i_procTarg            Proc chip target handle pointer
 *  @param[in] i_magicNum            Magic number in WOF image header
 *  @param[in] i_version             Version number in WOF image header
 *  @param[in] i_entryIndex=nullptr  Optional argument to be used when an override
 *                                   WOF table is being fetched.
 *                                   Value is only used in the UD section of the
 *                                   error log when an error is found.
 *
 *  @return errlHndl_t    - nullptr if no errors encountered
 *                        - else error handler will contain error info
 */
errlHndl_t checkWofImgHeaderForCorrectness(TARGETING::Target* i_procTarg,
                                           const uint32_t i_magicNum,
                                           const uint8_t i_version,
                                           const uint8_t* i_entryIndex = nullptr);

/**
 *  @brief Checks that for a certain WOF table header entry the magic number
 *  equals WOF_TABLES_MAGIC_VALUE and that version number is a supported level.
 *
 *  @param[in] i_procTarg           Proc chip target handle pointer
 *  @param[in] i_magicVal           Magic value of the WOF table header
 *  @param[in] i_version            Version number of the WOF table header
 *  @param[in] i_isOverride=false   Optional argument, default to false, to be used
 *                                  when an override WOF table is being fetched.
 *
 *  @return errlHndl_t    - nullptr if no errors encountered
 *                        - else error handler will contain error info
 */
errlHndl_t checkWofTableHeaderForCorrectness(TARGETING::Target* i_procTarg,
                                             const uint32_t i_magicVal,
                                             const uint8_t i_version,
                                             const bool i_isOverride = false);

/**
 *  @brief Checks that for a certain WOF Override image, the magic number
 *  equals WOF_OVERRIDE_MAGIC_VALUE and that version number is a supported level.
 *
 *  @param[in] i_procTarg           Proc target whose WOF data is being overridden
 *  @param[in] i_magicVal           Magic value of the WOF Override image
 *  @param[in] i_version            Version number of the WOF Override image
 *  @param[in] i_lidNumber          Lid number of WOFDATA (i.e. where the Override image comes from)
 *
 *  @return errlHndl_t    - nullptr if no errors encountered
 *                        - else error handler will contain error info
 */
errlHndl_t checkWofOverrideImgForCorrectness(TARGETING::Target* i_procTarg,
                                             const uint32_t i_magicVal,
                                             const uint8_t i_version,
                                             const uint32_t i_lidNumber);

/**
 *  @brief Add detail of the WOF override set entries searched to an error log
 *
 *     Format of WofData error buffer:
 *         uint16_t - Number of entries: i.e. entry with search info + all entries searched
 *         wofOverrideCompareData_t - Info used to perform search
 *         wofOverrideCompareData_t - last entry rejected for possible match
 *         ...
 *         wofOverrideCompareData_t - 1st entry rejected for possible match
 *         NOTE: format must match errl plugin parser (errludwofdata.H)
 *
 *  @param  io_err        Error log to add data into
 *  @param  i_searchInfo  Entry containing info that was searched for
 *  @param  i_searchedEntries     Entries that were searched and did not match info in i_searchInfo
 *
 *  @warning i_searchedEntries is totally consumed and will end up empty after function ends
 */
void addWofOverrideSearchEntriesToErrl(errlHndl_t &io_err,
                                       wofOverrideCompareData_t* i_searchInfo,
                                       std::vector<wofOverrideTableEntry_t*> i_searchedEntries);

/* End of declaration of helper methods for platParseWOFTables(...) */



/* platParseWOFTables(...) */

/**
 *  @brief This function will return the WOF table to use.
 *  This table is first searched in the WOF image retrieved using UtilLidMgr
 *  (the search criteria comes from the system's settings). If it's not found
 *  there, then the table data is picked up directly from the Backup EEPROM
 *  using the getSeepromWofTable(...) function.
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

    FAPI_INF("platParseWOFTables: Get WOF table for proc: 0x%.8X", get_huid(i_procTarg));

    // Assert if o_wofData is nullptr
    assert(o_wofData != nullptr, "Error! In plat_wof_access.C platParseWOFTables(), function "
        "argument o_wofData cannot be nullptr.");

    errlHndl_t l_errl = nullptr;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // Check if an override WOF Table was loaded in firmware image.
    // If not, get WOF Table from SEEPROM
    do
    {
        // Check override image

        bool l_didFindOverride = false;
        // Temporary workaround for SW532696, RTC 250794 will address missing WOFDATA binary
        if( INITSERVICE::spBaseServicesEnabled() )
        {
            l_errl = getOverrideWofTable(i_procTarg, o_wofData, l_didFindOverride);
        }
        else
        {
            FAPI_INF("platParseWOFTables: NON-FSP SKIPPED looking for WOF table in PNOR/LID");
        }

        if (l_didFindOverride && l_errl == nullptr)
        {
            // WOF table override found
            FAPI_INF("platParseWOFTables: Override WOF table was found and retrieved from LID");
            break;
        }

        // Get WOF override image errors are not passed back to caller as caller will get WOF table
        // from SEEPROM if not found in override
        if (l_errl)
        {
            // Check to see if HB has logged this error before
            auto fail_logged = i_procTarg->getAttr<ATTR_LOGGED_FAIL_GETTING_OVERRIDE_WOF_TABLE>();

            // Only log the error if it hasn't been logged before
            if (fail_logged == 0)
            {
                FAPI_INF("platParseWOFTables: Override WOF table was not found (fail_logged=%d) "
                         "Commiting Log: "
                         TRACE_ERR_FMT,
                         fail_logged,
                         TRACE_ERR_ARGS(l_errl));

                l_errl->collectTrace(FAPI_TRACE_NAME, 256);
                errlCommit(l_errl, FAPI2_COMP_ID);

                // Update attribute to 1 so that it is not logged again
                fail_logged = 1;
                i_procTarg->setAttr<ATTR_LOGGED_FAIL_GETTING_OVERRIDE_WOF_TABLE>(fail_logged);

            }
            else
            {
                FAPI_INF("platParseWOFTables: Override WOF table was not found (fail_logged=%d) "
                         "Previously logged, so deleting this error: "
                         TRACE_ERR_FMT,
                         fail_logged,
                         TRACE_ERR_ARGS(l_errl));

                delete l_errl;
                l_errl = nullptr;
            }
        }

        // Get from SEEPROM

        FAPI_INF("platParseWOFTables: No override WOF table found in PNOR");
        FAPI_INF("platParseWOFTables: Get WOF table from Backup SEEPROM");

        l_errl = getSeepromWofTable(i_procTarg, o_wofData);

        if (l_errl)
        {
            FAPI_ERR("platParseWOFTables: Failed to get WOF table from Backup SEEPROM");
            // Collect trace and add the error log pointer as data to the ReturnCode
            l_errl->collectTrace(FAPI_TRACE_NAME, 256);
            addErrlPtrToReturnCode(l_rc, l_errl);
        }
        else
        {
            // WOF table successfully retrieved from SEEPROM
            FAPI_INF("platParseWOFTables: WOF table successfully retrieved from Backup SEEPROM");
        }

    } while (0);

    return l_rc;
    FAPI_DBG("Exiting platParseWOFTables ....");
}

/* End of platParseWOFTables(...) */



/* Helper methods for platParseWOFTables(...) */


errlHndl_t getSeepromWofTable(TARGETING::Target* i_procTarg, uint8_t* o_wofData)
{
    FAPI_DBG("Entering getSeepromWofTable ....");

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
        l_errl = getSeepromEccLessWofData(i_procTarg, sizeof(l_imgHeader), 0, &l_imgHeader);
        if (l_errl)
        {
            break;
        }

        // Check header's version and magic number values
        l_errl = checkWofImgHeaderForCorrectness(i_procTarg, l_imgHeader.magicNumber, l_imgHeader.version);
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
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            fapi2::MOD_FAPI2_GET_DEFAULT_WOF_TABLE,
                            fapi2::RC_WOF_MRW_IDX_NOT_INCLUDED,
                            l_idxSelect,
                            l_imgHeader.entryCount);
            l_errl->addHwCallout(i_procTarg, HWAS::SRCI_PRIORITY_HIGH, HWAS::NO_DECONFIG, HWAS::GARD_NULL);
            break;
        }

        // Get Section Table Entry based on MRW selection index
        wofSectionTableEntry_t l_tableEntry;
        size_t l_entryOffset = l_imgHeader.offset + (l_idxSelect * sizeof(l_tableEntry));
        l_errl = getSeepromEccLessWofData(i_procTarg, sizeof(l_tableEntry), l_entryOffset, &l_tableEntry);

        if (l_errl)
        {
            break;
        }

        // Make sure that calculated offset and size of WOF table header entry does
        // not go beyond the bounds of the WOF image

        // Get WOF DATA info
        TARGETING::SpiWofDataInfo spiWOFDataInfo = i_procTarg->getAttr<TARGETING::ATTR_SPI_WOF_DATA_INFO>();

        // Get data size of WOF image
        const size_t l_wofImgSize = spiWOFDataInfo.dataSizeKB * CONVERSIONS::BYTES_PER_KB;

        if (l_wofImgSize < (l_tableEntry.offset + l_tableEntry.size))
        {
            const uint32_t l_endOfHeader = l_tableEntry.offset + l_tableEntry.size;

            FAPI_ERR("(Retrieved from SEEPROM) WOF Table Header to be fetched "
                "goes beyond bounds of WOF image. WOF image size: %lu, entry "
                "offset + size = %u + %u = %u", l_wofImgSize, l_tableEntry.offset,
                l_tableEntry.size, l_endOfHeader);

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
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            fapi2::MOD_FAPI2_GET_DEFAULT_WOF_TABLE,
                            fapi2::RC_WOF_HEADER_ENTRY_BEYOND_IMG,
                            TWO_UINT32_TO_UINT64(l_tableEntry.offset, l_tableEntry.size),
                            TWO_UINT32_TO_UINT64(l_idxSelect, l_wofImgSize));
            l_errl->addHwCallout(i_procTarg, HWAS::SRCI_PRIORITY_HIGH, HWAS::NO_DECONFIG, HWAS::GARD_NULL);
            break;
        }

        // Get WOF Table Header and put it in allocated memory from o_wofData
        l_errl = getSeepromEccLessWofData(i_procTarg, l_tableEntry.size, l_tableEntry.offset, o_wofData);
        if (l_errl)
        {
            break;
        }

        // Check WOF table header entry version number and magic value
        WofTablesHeader_t* l_tableHeader = reinterpret_cast<WofTablesHeader_t*>(o_wofData);

        l_errl = checkWofTableHeaderForCorrectness(i_procTarg, l_tableHeader->magic_number.value,
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

    FAPI_DBG("Exiting getSeepromWofTable ....");

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

        // Accumulate any ECC errors so that if correctable errors occur they can be written back to
        // Hardware.
        PE::eccErrors_t accumulatedEccErrors;
        PE::eccStatus l_eccStat = PE::removeECC(l_eccDataBuf, l_eccLessDataBuf, l_eccLessBuflen, &accumulatedEccErrors);

        switch(l_eccStat) {
        case PE::CLEAN:
            FAPI_DBG("getSeepromEccLessWofData: successfully removed ECC from WOF data block when "
                     "reading i_buflen: %u, i_offset: %u", i_buflen,  i_offset);
            break;
        case PE::CORRECTED:
            {
                FAPI_INF("getSeepromEccLessWofData: ECC correction was needed to successfully remove "
                         "ECC from WOF data block when reading i_buflen: %u, i_offset: %u. "
                         "Attempting to write back corrected data with ECC",
                         i_buflen,  i_offset);

                // Create a new buffer to contain the corrected WOF+ECC data
                uint8_t* l_correctedEccBlock = new uint8_t[l_eccBlock];

                // By stripping the ECC, the l_eccLessDataBuf already has the corrected data in it. To write back each
                // block of corrected data plus ECC byte iterate through the accumulated errors, copy the corrected WOF
                // data to the l_correctedEccBlock, add the ECC back onto the end of the buffer, and write the block.
                for (const auto& errorLocation : accumulatedEccErrors)
                {
                    // Error offset is recorded as the offset into the original ECCed data. Translate to ECCless offset.
                    size_t l_offset = (errorLocation.offset / l_eccBlock) * l_eccLessBlock;

                    // Copy the corrected ECCless data to the new buffer and inject the ECC
                    PE::injectECC(&l_eccLessDataBuf[l_offset], l_eccLessBlock, l_correctedEccBlock);

                    //  Write back the corrected data with a corrected ECC to EECACHE/HARDWARE
                    // A write to EECACHE is automatically a write-through to HARDWARE but use EEPROM::AUTOSELECT
                    // for safety.
                    size_t l_writeSize = l_eccBlock;
                    l_errl = deviceWrite(i_procTarg, l_correctedEccBlock, l_writeSize,
                             DEVICE_EEPROM_ADDRESS(EEPROM::WOF_DATA, errorLocation.offset, EEPROM::AUTOSELECT));

                    if (l_errl != nullptr)
                    {
                        FAPI_ERR("getSeepromEccLessWofData: An error occurred when attempting to write back the "
                                 "corrected data with ECC of size: %u at offset %u",
                                 l_eccBlock, errorLocation.offset);
                        break;
                    }
                }

                // Clean up.
                delete[] l_correctedEccBlock;
            }
            break;
        case PE::UNCORRECTABLE:
            FAPI_ERR("getSeepromEccLessWofData: ECC removal was uncorrectable when removing ECC "
                     "from WOF when reading: i_buflen: %u i_offset: %u i_procTarg HUID: 0x%.8X",
                     i_buflen,  i_offset, TARGETING::get_huid(i_procTarg));

            /*@
            * @errortype
            * @moduleid          fapi2::MOD_FAPI2_GET_SEEPROM_ECC_LESS_WOF_DATA
            * @reasoncode        fapi2::RC_WOF_READ_UNCORRECTABLE_ECC
            * @userdata1         Offset used to read WOF+ECC data from SEEPROM
            * @userdata2         Buffer length used to read WOF+ECC data from SEEPROM
            * @devdesc           WOF data has uncorrectable ECC
            * @custdesc          Hardware error inside processor module
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            fapi2::MOD_FAPI2_GET_SEEPROM_ECC_LESS_WOF_DATA,
                            fapi2::RC_WOF_READ_UNCORRECTABLE_ECC,
                            l_eccOffset,
                            l_eccBuflen);
            l_errl->addHwCallout(i_procTarg, HWAS::SRCI_PRIORITY_HIGH, HWAS::NO_DECONFIG, HWAS::GARD_NULL);
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

    FAPI_DBG("Exiting getSeepromEccLessWofData ....");

    return l_errl;
}



errlHndl_t getOverrideWofTable(TARGETING::Target* i_procTarg, uint8_t* o_wofData, bool& o_didFindTable)
{
    /*
    Summary of getOverrideWofTable
    - Set search criteria
    - Set a pointer to WOFDATA LID, i.e. the WOF Override image
    - Search all Override-set entries
        - Loop through all Override-set entries (wofOverrideTableEntry_t) in the Override image and
          search for entry matching search criteria
    - Go to WOF image header
        - I.e. wofImageHeader_t pointed to by matching Override-set entry
    - Get MRW selected WOF table
        - Using MRW's ATTR_WOF_INDEX_SELECT, set (o_wofData) override table (type WofTablesHeader_t)
    - Clear out any memory allocated for WOFDATA LID pointer
    */

    FAPI_DBG("Entering getOverrideWofTable ....");

    TARGETING::Target * l_sys = UTIL::assertGetToplevelTarget();
    errlHndl_t l_errl = nullptr;
    o_didFindTable = false; // flag if did find WOF override table

    /* Set Search Criteria: l_coreCount, l_nominalPowerWatts and l_wofbaseFreqMhz */

    // Core count (only present, non-eco cores used in WOF tables)
    TARGETING::TargetHandleList l_coreTargetList;
    getNonEcoCores(l_coreTargetList, i_procTarg, false);
    const uint8_t l_coreCount = l_coreTargetList.size();

    // Nominal power in Watts for Proc and WofBase Freq in Mhz for System
    const uint16_t l_nominalPowerWatts = i_procTarg->getAttr<TARGETING::ATTR_SOCKET_POWER_NOMINAL>();
    const uint16_t l_wofbaseFreqMhz = l_sys->getAttr<TARGETING::ATTR_WOFBASE_FREQ_MHZ>();

    FAPI_INF("getOverrideWofTable: Override WOF table search criteria: core count %d nominal "
             "power 0x%X wofbase freq 0x%X", l_coreCount, l_nominalPowerWatts, l_wofbaseFreqMhz);

    /* Set a pointer (l_pWofImage) to WOFDATA LID */

    void* l_pWofImage = nullptr;
    size_t l_lidImageSize = 0;

    do {
        // @todo RTC 172776 Make WOF table parser PNOR accesses more efficient
        uint32_t l_lidNumber = Util::WOF_LIDID;

        if( INITSERVICE::spBaseServicesEnabled() )
        {
            // Lid number is system dependent on FSP systems
            l_lidNumber = l_sys->getAttr<TARGETING::ATTR_WOF_TABLE_LID_NUMBER>();
        }

        UtilLidMgr l_wofLidMgr(l_lidNumber);

        // Get the size of the full WOF Override image
        l_errl = l_wofLidMgr.getLidSize(l_lidImageSize);

        if(l_errl)
        {
            FAPI_ERR("getOverrideWofTable: UtilLidMgr's getLidSize failed");
            break;
        }

        FAPI_INF("WOFDATA lid is: %d bytes", l_lidImageSize);

#ifdef __HOSTBOOT_RUNTIME
        // In HBRT case, phyp will call malloc and return the lid pointer to us. We do not need to
        // malloc the space ourselves. In fact, two mallocs on the WOF partition were leading to
        // heap overflows.
        l_pWofImage = nullptr;

        // Using getStoredLidImage because we want to use the cached copies if they exist.
        l_errl = l_wofLidMgr.getStoredLidImage(l_pWofImage, l_lidImageSize);
#else
        // Use a special VMM block to avoid the requirement for contiguous memory
        int l_mm_rc = 0;
        if (!g_wofdataVMM)
        {
            l_mm_rc = mm_alloc_block(nullptr, reinterpret_cast<void*>(VMM_VADDR_WOFDATA_LID),
                                     VMM_SIZE_WOFDATA_LID);
            if(l_mm_rc != 0)
            {
                FAPI_ERR("getOverrideWofTable: Fail from mm_alloc_block for WOFDATA, rc: %d", l_mm_rc);

                /*@
                 * @errortype
                 * @moduleid          fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE
                 * @reasoncode        fapi2::RC_MM_ALLOC_BLOCK_FAILED
                 * @userdata1         Address being allocated
                 * @userdata2[00:31]  Size of block allocation
                 * @userdata2[32:63]  rc from mm_alloc_block
                 * @devdesc           Error calling mm_alloc_block for WOFDATA
                 * @custdesc          Firmware Error
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_PREDICTIVE,
                               fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE,
                               fapi2::RC_MM_ALLOC_BLOCK_FAILED,
                               VMM_VADDR_WOFDATA_LID,
                               TWO_UINT32_TO_UINT64(VMM_SIZE_WOFDATA_LID, l_mm_rc),
                               ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }

            g_wofdataVMM = reinterpret_cast<void*>(VMM_VADDR_WOFDATA_LID);
        }

        l_mm_rc = mm_set_permission(reinterpret_cast<void*>(VMM_VADDR_WOFDATA_LID), l_lidImageSize,
                                    WRITABLE | ALLOCATE_FROM_ZERO );
        if (l_mm_rc != 0)
        {
            FAPI_ERR("getOverrideWofTable: Fail from mm_set_permission for WOFDATA, rc=%d", l_mm_rc);

            /*@
             * @errortype
             * @moduleid          fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE
             * @reasoncode        fapi2::RC_MM_SET_PERMISSION_FAILED
             * @userdata1         Address being changed
             * @userdata2[00:31]  Size of change
             * @userdata2[32:63]  rc from mm_set_permission
             * @devdesc           Error calling mm_set_permission for WOFDATA
             * @custdesc          Firmware Error
             */
            l_errl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_PREDICTIVE,
                               fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE,
                               fapi2::RC_MM_SET_PERMISSION_FAILED,
                               VMM_VADDR_WOFDATA_LID,
                               TWO_UINT32_TO_UINT64(VMM_SIZE_WOFDATA_LID, l_mm_rc),
                               ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        // Point my local pointer at the VMM space we allocated
        l_pWofImage = g_wofdataVMM;

        // Get the tables from PNOR or lid
        l_errl = l_wofLidMgr.getLid(l_pWofImage, l_lidImageSize);
#endif

        if(l_errl)
        {
            FAPI_ERR("getOverrideWofTable: getLid failed pLidImage %p imageSize %d", l_pWofImage,
                     l_lidImageSize);
            break;
        }

        /* Search all Override-set entries */

        // Cast out WOF Override image header into wofContainerHeader_t struct
        wofContainerHeader_t* l_containerHeader = reinterpret_cast<wofContainerHeader_t*>(l_pWofImage);
        const uint8_t l_entryCount = l_containerHeader->entryCount;

        FAPI_INF("getOverrideWofTable: WOF Override Image header info: Magic 0x%X Version %d Entry "
                 "Count %d Offset %p", l_containerHeader->magicNumber, l_containerHeader->version,
                 l_containerHeader->entryCount, l_containerHeader->offset);

        l_errl = checkWofOverrideImgForCorrectness(i_procTarg, l_containerHeader->magicNumber,
                                                   l_containerHeader->version, l_lidNumber);
        if (l_errl) { break; }

        // Get a pointer to the first override-set table entry
        wofOverrideTableEntry_t* l_overrideEntry = reinterpret_cast<wofOverrideTableEntry_t*>
            (reinterpret_cast<uint8_t*>(l_pWofImage) + l_containerHeader->offset);

        // Keep track of table entry that matched search criteria
        uint8_t l_entryIdx = 0;

        // When running in Simics, record any entry that matches search criteria, ignoring core count
        struct SimicsEntry
        {
            bool didFind = false;
            uint8_t entryIndex = 0;
        } l_simicsEntry;

        // Store pointers to searched override entries
        std::vector<wofOverrideTableEntry_t*> l_searchedEntries;
        l_searchedEntries.clear();

        // Search through all the override-set entries. If an entry matching the search criteria is
        // found (core count, power, and frequency), for-loop will exit.
        // In the case we're running in Simics, l_simicsEntry will be filled out if
        // a match is found, ignoring core count for it.
        for (l_entryIdx = 0; l_entryIdx < l_entryCount; l_entryIdx++)
        {
            FAPI_DBG("getOverrideWofTable: Possible WOF Override-set core_count: %d socket_power_w: 0x%X "
                "sort_power_freq_mhz: 0x%X ", l_overrideEntry[l_entryIdx].core_count,
                l_overrideEntry[l_entryIdx].socket_power_w, l_overrideEntry[l_entryIdx].sort_power_freq_mhz);

            // Checking against search criteria
            if ( (l_overrideEntry[l_entryIdx].core_count          == l_coreCount        ) &&
                 (l_overrideEntry[l_entryIdx].socket_power_w      == l_nominalPowerWatts) &&
                 (l_overrideEntry[l_entryIdx].sort_power_freq_mhz == l_wofbaseFreqMhz   ) )
            {
                FAPI_INF("getOverrideWofTable: WOF Override-set matching search criteria found "
                    "core_count: %d socket_power_w: 0x%X sort_power_freq_mhz: 0x%X ",
                    l_overrideEntry[l_entryIdx].core_count, l_overrideEntry[l_entryIdx].socket_power_w,
                    l_overrideEntry[l_entryIdx].sort_power_freq_mhz);
                break;
            }
            else
            {
                // Save entry info to be used by error log later if needed
                l_searchedEntries.push_back(&l_overrideEntry[l_entryIdx]);

                // Simics runs with fewer cores, ignore the core_count if we don't find a complete match
                if ( (Util::isSimicsRunning() && l_simicsEntry.didFind == false) &&
                          (l_overrideEntry[l_entryIdx].socket_power_w      == l_nominalPowerWatts) &&
                          (l_overrideEntry[l_entryIdx].sort_power_freq_mhz == l_wofbaseFreqMhz   ) )
                {
                    FAPI_INF("getOverrideWofTable: WOF Override-set matching search criteria found for "
                        "Simics run socket_power_w: 0x%X sort_power_freq_mhz: 0x%X ",
                        l_overrideEntry[l_entryIdx].socket_power_w, l_overrideEntry[l_entryIdx].sort_power_freq_mhz);
                    l_simicsEntry.didFind = true;
                    l_simicsEntry.entryIndex = l_entryIdx;
                    // Do not break, we may still find an override table matching all criteria
                }
            }

        }

        // Check if a WOF override-set match was found

        uint8_t l_entryValue = 0;  // ultimate index to select override-set
        bool l_didFindEntry = false;

        if (l_entryIdx < l_entryCount)
        {
            l_entryValue = l_entryIdx;
            l_didFindEntry = true;
        }
        else if (Util::isSimicsRunning() && (l_didFindEntry == false) && (l_simicsEntry.didFind == true))
        {
            l_entryValue = l_simicsEntry.entryIndex;
            l_didFindEntry = true;
        }

        if (l_didFindEntry == false)
        {
            FAPI_ERR("getOverrideWofTable: Did not find Override-set in Override WOF image");
            /*@
            * @errortype
            * @moduleid          fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE
            * @reasoncode        fapi2::RC_WOF_OVERRIDE_TABLE_NOT_FOUND
            * @userdata1[00:31]  Number of WOF override sets checked
            * @userdata1[32:63]  Core count
            * @userdata2[00:31]  Nominal power in watts
            * @userdata2[32:63]  WofBase frequency in Mhz
            * @devdesc           No override WOF table found
            * @custdesc          Firmware Error or unsupported part
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE,
                            fapi2::RC_WOF_OVERRIDE_TABLE_NOT_FOUND,
                            TWO_UINT32_TO_UINT64(TO_UINT32(l_entryCount),
                                                 TO_UINT32(l_coreCount)),
                            TWO_UINT32_TO_UINT64(TO_UINT32(l_nominalPowerWatts),
                                                 TO_UINT32(l_wofbaseFreqMhz)),
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            // Append info on entries that were searched:
            wofOverrideCompareData_t l_searchInfo;
            l_searchInfo.core_count = l_coreCount;
            l_searchInfo.socket_power_w = l_nominalPowerWatts;
            l_searchInfo.sort_power_freq_mhz = l_wofbaseFreqMhz;
            addWofOverrideSearchEntriesToErrl(l_errl, &l_searchInfo, l_searchedEntries);

            break;
        }

        /* Go to WOF image header */

        // search-selected override-set absolute offset within Override Image
        const uint32_t l_overrideSetAbsOffset = l_overrideEntry[l_entryValue].offset;

        wofImageHeader_t* l_imgHeader = reinterpret_cast<wofImageHeader_t*>
            (reinterpret_cast<uint8_t*>(l_pWofImage) + l_overrideSetAbsOffset);

        FAPI_INF("getOverrideWofTable: WOF Image Header Values: l_imgHeader: Magic 0x%X "
        "Version %d Entries %d Offset %p", l_imgHeader->magicNumber,
        l_imgHeader->version, l_imgHeader->entryCount, l_imgHeader->offset);

        // Check header's version and magic number values
        l_errl = checkWofImgHeaderForCorrectness(i_procTarg, l_imgHeader->magicNumber,
                                                 l_imgHeader->version, &l_entryValue);
        if (l_errl) { break; }

        // Set absolute offset to the table of content of the WOF image we've chosen
        const uint32_t l_tocAbsOffset = l_overrideSetAbsOffset + l_imgHeader->offset;

        /* Get MRW selected WOF table */

        fapi2::ATTR_WOF_INDEX_SELECT_Type l_idxSelect = l_sys->getAttr<TARGETING::ATTR_WOF_INDEX_SELECT>();
        FAPI_INF("getOverrideWofTable: MRW selection index ATTR_WOF_INDEX_SELECT: %u", l_idxSelect);

        // Get header entry for MRW selected WOF table
        const uint32_t l_tableEntryAbsOffset = l_tocAbsOffset + (l_idxSelect * sizeof(wofSectionTableEntry_t));
        wofSectionTableEntry_t* l_tableEntry = reinterpret_cast<wofSectionTableEntry_t*>
            (reinterpret_cast<uint8_t*>(l_pWofImage) + l_tableEntryAbsOffset);
        FAPI_INF("getOverrideWofTable l_tableEntry size: %lu, offset: %u", l_tableEntry->size, l_tableEntry->offset);

        // Get and copy out WOF override table
        const uint32_t l_tableHeaderAbsOffset = l_overrideSetAbsOffset + l_tableEntry->offset;
        WofTablesHeader_t* l_tableHeader = reinterpret_cast<WofTablesHeader_t*>
            (reinterpret_cast<uint8_t*>(l_pWofImage) + l_tableHeaderAbsOffset);

        l_errl = checkWofTableHeaderForCorrectness(i_procTarg, l_tableHeader->magic_number.value,
            l_tableHeader->header_version, true);
        if (l_errl) { break; }

        // Set data to output arguments:
        // If we get to this point, that means that we've successfully found an override WOF table
        memcpy(o_wofData, reinterpret_cast<uint8_t*>(l_tableHeader), l_tableEntry->size);
        o_didFindTable = true;

        // WOF table header fields
        FAPI_INF("getOverrideWofTable WOF Header Table Fields: magic: 0x%X "
            "Version %d Mode %d Cores %d SocketPower 0x%X NomFreq 0x%X",
            l_tableHeader->magic_number,
            l_tableHeader->header_version, l_tableHeader->ocs_mode,
            l_tableHeader->core_count, l_tableHeader->socket_power_w,
            l_tableHeader->sort_power_freq_mhz);

    } while(0);

    /* Clear out any memory allocated for WOFDATA LID pointer */

    if(l_pWofImage != nullptr)
    {
#ifndef __HOSTBOOT_RUNTIME
        errlHndl_t l_tmpErr = nullptr;
        // Release the memory we may still have allocated and set the
        //  permissions to prevent further access to it
        int l_mm_rc = mm_remove_pages(RELEASE, l_pWofImage, VMM_SIZE_WOFDATA_LID);
        if( l_mm_rc )
        {
            FAPI_INF("Fail from mm_remove_pages for WOFDATA, rc=%d", l_mm_rc);

            /*@
             * @errortype
             * @moduleid          fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE
             * @reasoncode        fapi2::RC_MM_REMOVE_PAGES_FAILED
             * @userdata1         Address being removed
             * @userdata2[00:31]  Size of removal
             * @userdata2[32:63]  rc from mm_remove_pages
             * @devdesc           Error calling mm_remove_pages for WOFDATA
             * @custdesc          Firmware Error
             */
            l_tmpErr = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_PREDICTIVE,
                                   fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE,
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

            /*@
             * @errortype
             * @moduleid          fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE
             * @reasoncode        fapi2::RC_MM_SET_PERMISSION2_FAILED
             * @userdata1         Address being changed
             * @userdata2[00:31]  Size of change
             * @userdata2[32:63]  rc from mm_set_permission
             * @devdesc           Error calling mm_set_permission for WOFDATA
             * @custdesc          Firmware Error
             */
            l_tmpErr = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_PREDICTIVE,
                                   fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE,
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

    FAPI_DBG("Exiting getOverrideWofTable ....");
    return l_errl; // error from main do-while loop
}



errlHndl_t checkWofImgHeaderForCorrectness(TARGETING::Target* i_procTarg,
                                           const uint32_t i_magicNum,
                                           const uint8_t i_version,
                                           const uint8_t* i_entryIndex)
{

    errlHndl_t l_errl = nullptr;
    uint64_t l_userData1(0), l_userData2(0);

    do
    {
        // Check for valid magic number
        if(i_magicNum != WOF_IMAGE_MAGIC_VALUE)
        {
            l_userData1 = TWO_UINT32_TO_UINT64(i_magicNum, WOF_IMAGE_MAGIC_VALUE);
            if (i_entryIndex)
            {
                // Error from Override WOF image in WOFDATA LID
                FAPI_ERR("WOF Image from WOF Override Image has Header Magic Value"
                    " Mismatch 0x%X != WTIH(0x%X)", i_magicNum, WOF_IMAGE_MAGIC_VALUE);
                l_userData2 = TWO_UINT32_TO_UINT64(get_huid(i_procTarg), *i_entryIndex);
                /*@
                * @errortype
                * @moduleid          fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE
                * @reasoncode        fapi2::RC_WOF_IMAGE_MAGIC_MISMATCH
                * @userdata1[00:31]  Image header magic value
                * @userdata1[32:63]  Expected magic value
                * @userdata2[00:31]  Proc whose WOF data is being overridden
                * @userdata2[32:63]  0-based index of Override WOF Image that match override search criteria
                * @devdesc           WOF image header magic value mismatch
                * @custdesc          Unsupported WOFDATA in current firmware image
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_PREDICTIVE,
                                fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE,
                                fapi2::RC_WOF_IMAGE_MAGIC_MISMATCH,
                                l_userData1,
                                l_userData2,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }
            else
            {
                // Error from WOF img in SEEPROM
                FAPI_ERR("(Retrieved from SEEPROM) WOF Image Header Magic Value "
                    "Mismatch 0x%X != WTIH(0x%X)", i_magicNum, WOF_IMAGE_MAGIC_VALUE);
                l_userData2 = TO_UINT64(i_version);

                /*@
                * @errortype
                * @moduleid          fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES
                * @reasoncode        fapi2::RC_WOF_IMAGE_MAGIC_MISMATCH
                * @userdata1[00:31]  Image header magic value
                * @userdata1[32:63]  Expected magic value
                * @userdata2[00:63]  Image header version
                * @devdesc           WOF image header magic value mismatch
                * @custdesc          Unsupported processor module
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
                                fapi2::RC_WOF_IMAGE_MAGIC_MISMATCH,
                                l_userData1,
                                l_userData2);
                l_errl->addHwCallout(i_procTarg, HWAS::SRCI_PRIORITY_HIGH, HWAS::NO_DECONFIG, HWAS::GARD_NULL);
                break;
            }
        }

        // Check for a valid image header version
        if(i_version != WOF_IMAGE_VERSION)
        {
            l_userData1 = TWO_UINT32_TO_UINT64(i_version, WOF_IMAGE_VERSION);
            if (i_entryIndex)
            {
                // Error from Override WOF image in WOFDATA LID
                FAPI_ERR("WOF Image from WOF Override Image has header version that is "
                    "not supported: Header Version %d, Supported Version is "
                    "%d", i_version, WOF_IMAGE_VERSION);
                l_userData2 = TWO_UINT32_TO_UINT64(get_huid(i_procTarg), *i_entryIndex);
                /*@
                * @errortype
                * @moduleid          fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE
                * @reasoncode        fapi2::RC_WOF_IMAGE_VERSION_MISMATCH
                * @userdata1[00:31]  Image header version
                * @userdata1[32:63]  Supported header version
                * @userdata2[00:31]  Proc whose WOF data is being overridden
                * @userdata2[32:63]  0-based index of Override WOF Image that match override search criteria
                * @devdesc           Image header version not supported
                * @custdesc          Unsupported WOFDATA in current firmware version
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                 ERRORLOG::ERRL_SEV_PREDICTIVE,
                                 fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE,
                                 fapi2::RC_WOF_IMAGE_VERSION_MISMATCH,
                                 l_userData1,
                                 l_userData2,
                                 ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }
            else
            {
                // Error from WOF img in SEEPROM
                FAPI_ERR("(Retrieved from SEEPROM) WOF Image header version not "
                    "supported: Header Version %d, Supported Version is "
                    "%d", i_version, WOF_IMAGE_VERSION);

                /*@
                * @errortype
                * @moduleid          fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES
                * @reasoncode        fapi2::RC_WOF_IMAGE_VERSION_MISMATCH
                * @userdata1[00:31]  Image header version
                * @userdata1[32:63]  Supported header version
                * @devdesc           Image header version not supported
                * @custdesc          Unsupported processor module for current firmware version
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                 ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                 fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
                                 fapi2::RC_WOF_IMAGE_VERSION_MISMATCH,
                                 l_userData1,
                                 0,
                                 ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                l_errl->addHwCallout(i_procTarg, HWAS::SRCI_PRIORITY_LOW, HWAS::NO_DECONFIG, HWAS::GARD_NULL);
                break;
            }
        }
    } while (0);

    return(l_errl);

}



errlHndl_t checkWofTableHeaderForCorrectness(TARGETING::Target* i_procTarg,
                                             const uint32_t i_magicVal,
                                             const uint8_t i_version,
                                             const bool i_isOverride)
{

    errlHndl_t l_errl = nullptr;
    uint64_t l_userData1(0), l_userData2(0);

    do
    {
        // Check for magic value mismatch
        if(i_magicVal != WOF_TABLES_MAGIC_VALUE)
        {
            l_userData1 = TWO_UINT32_TO_UINT64(i_magicVal, WOF_TABLES_MAGIC_VALUE);
            if (i_isOverride)
            {
                // Error from Override WOF image in WOFDATA LID
                FAPI_ERR("checkWofTableHeaderForCorrectness: WOF Table Header Magic "
                    "Value Mismatch 0x%X != WFTH(0x%X)", i_magicVal, WOF_TABLES_MAGIC_VALUE);
                /*@
                * @errortype
                * @moduleid          fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE
                * @reasoncode        fapi2::RC_WOF_TABLES_MAGIC_MISMATCH
                * @userdata1[00:31]  Override WOF table header magic value
                * @userdata1[32:63]  Expected magic value
                * @devdesc           WOF tables header magic value mismatch
                * @custdesc          Unsupported WOFDATA in current firmware image
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_PREDICTIVE,
                                fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE,
                                fapi2::RC_WOF_TABLES_MAGIC_MISMATCH,
                                l_userData1,
                                0,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }
            else
            {
                // Error from WOF img in SEEPROM
                FAPI_ERR("(Retrieved from SEEPROM) WOF Table Header Magic Value "
                    "Mismatch 0x%X != WFTH(0x%X)", i_magicVal,
                    WOF_TABLES_MAGIC_VALUE);
                l_userData2 = TO_UINT64(i_version);

                /*@
                * @errortype
                * @moduleid          fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES
                * @reasoncode        fapi2::RC_WOF_TABLES_MAGIC_MISMATCH
                * @userdata1[00:31]  WOF tables header magic value
                * @userdata1[32:63]  Expected magic value
                * @userdata2[00:63]  WOF tables header version
                * @devdesc           WOF tables header magic value mismatch
                * @custdesc          Unsupported processor module
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
                                fapi2::RC_WOF_TABLES_MAGIC_MISMATCH,
                                l_userData1,
                                l_userData2);
                l_errl->addHwCallout(i_procTarg, HWAS::SRCI_PRIORITY_HIGH, HWAS::NO_DECONFIG, HWAS::GARD_NULL);
                break;
            }
        }

        // Check for a valid tables header version
        if(i_version != WOF_TABLE_VERSION)
        {
            l_userData1 = TWO_UINT32_TO_UINT64(i_version, WOF_TABLE_VERSION);
            if (i_isOverride)
            {
                // Error from Override WOF image in WOFDATA LID
                FAPI_ERR("checkWofTableHeaderForCorrectness: WOF table header version not supported: "
                    "Header Version %d, Supported Version is %d", i_version, WOF_TABLE_VERSION);
                /*@
                * @errortype
                * @moduleid          fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE
                * @reasoncode        fapi2::RC_WOF_TABLES_VERSION_MISMATCH
                * @userdata1[00:31]  Override WOF tables header version
                * @userdata1[32:63]  Supported header version
                * @devdesc           WOF tables header version not supported
                * @custdesc          Unsupported WOFDATA in current firmware version
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_PREDICTIVE,
                                fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE,
                                fapi2::RC_WOF_TABLES_VERSION_MISMATCH,
                                l_userData1,
                                0,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }
            else
            {
                // Error from WOF img in SEEPROM
                FAPI_ERR("(Retrieved from SEEPROM) WOF table header version not "
                    "supported: Header Version %d, Supported Version is "
                    "%d", i_version, WOF_TABLE_VERSION);
                l_userData2 = 0;

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
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
                                fapi2::RC_WOF_TABLES_VERSION_MISMATCH,
                                l_userData1,
                                l_userData2,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                l_errl->addHwCallout(i_procTarg, HWAS::SRCI_PRIORITY_LOW, HWAS::NO_DECONFIG, HWAS::GARD_NULL);

                break;
            }
        }

    } while (0);

    return l_errl;

}



errlHndl_t checkWofOverrideImgForCorrectness(TARGETING::Target* i_procTarg,
                                             const uint32_t i_magicVal,
                                             const uint8_t i_version,
                                             const uint32_t i_lidNumber)
{
    errlHndl_t l_errl = nullptr;
    uint64_t l_userData1(0), l_userData2(0);
    do
    {
        // Compare against expected magic number
        if (i_magicVal != WOF_OVERRIDE_MAGIC_VALUE)
        {
            FAPI_ERR("checkWofOverrideImgForCorrectness: WOF Override image Magic Value mismatch "
                "0x%X != expected WFTH(0x%X)", i_magicVal, WOF_OVERRIDE_MAGIC_VALUE);
            l_userData1 = TWO_UINT32_TO_UINT64(i_magicVal, WOF_OVERRIDE_MAGIC_VALUE);
            l_userData2 = TWO_UINT32_TO_UINT64(get_huid(i_procTarg), i_lidNumber);
            // TODO RTC: 250659 WOF - Support Override of WOF from FSP; set ERRL_SEV_INFORMATIONAL to ERRL_SEV_PREDICTIVE
            /*@
            * @errortype
            * @moduleid          fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE
            * @reasoncode        fapi2::RC_WOF_OVERRIDE_MAGIC_MISMATCH
            * @userdata1[00:31]  WOF Override image magic value
            * @userdata1[32:63]  Expected magic value
            * @userdata2[00:31]  Proc whose WOF data is being overridden
            * @userdata2[32:63]  WOFDATA LID number that was used
            * @devdesc           WOF Override image magic value mismatch
            * @custdesc          Unsupported WOFDATA in current firmware version
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE,
                            fapi2::RC_WOF_OVERRIDE_MAGIC_MISMATCH,
                            l_userData1,
                            l_userData2,
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }
        // Check for a valid tables header version
        if (i_version != WOF_OVERRIDE_VERSION)
        {
            FAPI_ERR("checkWofOverrideImgForCorrectness: WOF Override image Version not supported "
                "Img Version: %d, Supported Version: %d", i_version, WOF_OVERRIDE_VERSION);
            l_userData1 = TWO_UINT32_TO_UINT64(i_version, WOF_OVERRIDE_VERSION);
            l_userData2 = TWO_UINT32_TO_UINT64(get_huid(i_procTarg), i_lidNumber);
            // TODO RTC: 250659 WOF - Support Override of WOF from FSP; set ERRL_SEV_INFORMATIONAL to ERRL_SEV_PREDICTIVE
            /*@
            * @errortype
            * @moduleid          fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE
            * @reasoncode        fapi2::RC_WOF_OVERRIDE_VERSION_MISMATCH
            * @userdata1[00:31]  WOF Override image header version
            * @userdata1[32:63]  Supported version number
            * @userdata2[00:31]  Proc whose WOF data is being overridden
            * @userdata2[32:63]  WOFDATA LID number that was used
            * @devdesc           WOF Override image version not supported
            * @custdesc          Unsupported WOFDATA in current firmware version
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE,
                            fapi2::RC_WOF_OVERRIDE_VERSION_MISMATCH,
                            l_userData1,
                            l_userData2,
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }
    } while (0);
    return l_errl;
}



void addWofOverrideSearchEntriesToErrl(errlHndl_t &io_err,
                                       wofOverrideCompareData_t* i_searchInfo,
                                       std::vector<wofOverrideTableEntry_t*> i_searchedEntries)
{
    uint16_t l_wofEntryCount = i_searchedEntries.size() + 1; // +1: include entry with search info as well

    // Allocate WofData error buffer
    uint32_t l_dataLen = sizeof(l_wofEntryCount) + l_wofEntryCount * sizeof(wofOverrideCompareData_t);
    uint8_t* l_data = new uint8_t[l_dataLen];

    // # of table entries in data
    memcpy(l_data, &l_wofEntryCount, sizeof(l_wofEntryCount));

    wofOverrideCompareData_t* l_entryPtr =
        reinterpret_cast<wofOverrideCompareData_t*>(l_data + sizeof(l_wofEntryCount));

    // first entry contains info that was used to perform search
    l_entryPtr[0] = *i_searchInfo;
    l_entryPtr++;

    // add info on all the non-matched WOF override entries
    while(i_searchedEntries.size())
    {
        wofOverrideTableEntry_t* l_tmpHeader = i_searchedEntries.back();
        l_entryPtr->core_count = l_tmpHeader->core_count;
        l_entryPtr->socket_power_w = l_tmpHeader->socket_power_w;
        l_entryPtr->sort_power_freq_mhz = l_tmpHeader->sort_power_freq_mhz;
        l_entryPtr++;
        i_searchedEntries.pop_back();
    }

    io_err->addFFDC(
            ERRL_COMP_ID,
            l_data,
            l_dataLen,
            WOF_OVERRIDE_ERROR_UD_VERSION, // FFDC version
            ERRORLOG::ERRL_UDT_WOFDATA,    // WOF DATA parser
            false );                       // merge

    delete [] l_data;
}


/* End of helper methods for platParseWOFTables(...) */


} // End platAttrSvc namespace
} // End fapi2 namespace
