/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vpd/vpd_if.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2024                        */
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
#if !defined(__VPD_IF_H)
#define __VPD_IF_H

#include <pnor/pnorif.H>
#include <map>
#include <eeprom/eeprom_const.H>
#include <vpd/spdenums.H>

namespace VPD
{
    /**
     * @brief typdef for vpdRecord values
     */
    typedef uint32_t vpdRecord;
    /**
     * @brief typdef for vpdKeyword values
     */
    typedef uint32_t vpdKeyword;

    // Useful constants for some boolean parms
    constexpr bool COMPARE_TO_ATTRIBUTES = true;
    constexpr bool COMPARE_TO_EEPROM = false;

    /**
     * @brief Load the runtime VPD image into memory
     * @param[in] The virtual address of the VPD image
     * @return error handle if there was an error
     */
    errlHndl_t vpd_load_rt_image(uint64_t & i_vpd_addr);

    /**
     * @brief This function checks to see if the given mvpd target
     *      is present
     * @param[in] i_target - Target device to search for mvpd
     * @return bool - true if mvpd is present, false if it is not.
     */
    bool mvpdPresent ( TARGETING::Target * i_target );

    /**
     * @brief This function translates a character string representing a mvpd record
     *        to its corresponding enum value
     * @param[in]  i_record     - pointer record string, must not be nullptr
     * @param[out] o_recordEnum - enum value corresponding to i_record string
     * @return nullptr if successful, pointer to error log otherwise
     */
    errlHndl_t mvpdRecordStringtoEnum(const char * i_record, uint32_t & o_recordEnum);


    /**
     * @brief This function translates a character string representing a mvpd keyword
     *        to its corresponding enum value
     * @param[in]  i_keyword     - pointer keyword string, must not be nullptr
     * @param[out] o_keywordEnum - enum value corresponding to i_keyword string
     * @return nullptr if successful, pointer to error log otherwise
     */
    errlHndl_t mvpdKeywordStringtoEnum(const char * i_keyword, uint32_t & o_keywordEnum);

    /**
     * @brief This function checks to see if the given cvpd target
     *      is present
     * @param[in] i_target - Target device to search for cvpd
     * @return bool - true if cvpd is present, false if it is not.
     */
    bool cvpdPresent ( TARGETING::Target * i_target );


    /**
     * @brief This function sets the part and serial number attributes for
     *        a given processor target
     * @param[in] i_target - the processor target to set the attributes for
     *
     */
    void setPartAndSerialNumberAttributes( TARGETING::Target * i_target );

    /**
     * @brief This function checks to see if the given pvpd target
     *      is present
     * @param[in] i_target - Target device to search for pvpd
     * @return bool - true if pvpd is present, false if it is not.
     */
    bool pvpdPresent ( TARGETING::Target * i_target );

    /**
     * @brief This function checks if the eeprom cache for the target is in
     *        sync with hardware and returns the result in o_isInSync.
     *
     * @param[in]   i_target      Target device
     * @param[in]   i_eepromType  Eeprom content type of target device
     * @param[in] - i_useAttributes true: Compare eecache vs attributes,
     *                              false: Compare eecache vs eeprom
     * @param[out]  o_isInSync    true if part and serial numbers in cache match
     *                            hardware. Otherwise, false.
     * @param[out]  o_isNewPart   false for EECACHE_VPD_STATE_VPD_NEEDS_REFRESH
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t ensureEepromCacheIsInSync(
                            TARGETING::Target* i_target,
                            TARGETING::EEPROM_CONTENT_TYPE i_eepromType,
                            bool i_useAttributes,
                            bool& o_isInSync,
                            bool& o_isNewPart );

    /**
     * @brief Structure used to specify VPD overrides for runtime
     *        reserved memory usage
     */
    struct OverrideSpecifier_t
    {
        PNOR::SectionId pnorId;
        size_t size; // size in bytes
    };

    /**
     * @brief Map of override labels to sections
     *   index : uint64_t label = right-justified 4-digit ASCII string
     *   result : OverrideSpecifier_t
     */
    typedef std::map<uint64_t,OverrideSpecifier_t> OverrideRsvMemMap_t;

    /**
     * @brief Get a list of all overridden sections
     * @param[out]  List of known override sections
     */
    void getListOfOverrideSections( OverrideRsvMemMap_t& o_overrides );

    /**
     * @brief Retrieve the record and update the record's ECC data
     *
     * @param[in] i_target  - Pointer to the PROC target where the record is located.
     * @param[in] i_record  - The record ID.
     * @param[in] i_keyword - The keyword ID.
     * @param[in] i_eepromSource - The EEPROM source - AUTOSELECT, CACHE or HARDWARE.
     * @return errlHndl_t  - NULL if successful, otherwise a pointer to the error log.
     */
    errlHndl_t updateRecordEccData (
                   const TARGETING::TargetHandle_t  i_target,
                   uint32_t i_record,   uint32_t i_keyword,
                   uint32_t i_eepromSource );

    /**
     * @brief Validate all the records' ECC data
     *
     * @details This method will iterate thru all the MVPDs and validate the ECC
     *          data for each record.  If *not* in HB runtime and a validation fails on
     *          an MVPD then the next source for the MVPD will be examined until all
     *          MVPD sources are exhausted.
     *          A target will be deconfigured for the following reasons:
     *              * Validation of a record's ECC data failed after all MVPD
     *                sources have been exhausted.
     *              * The API to get the next MVPD source erred which prevents validation.
     *
     * @param[in] i_target - Pointer to the PROC target where the records are located.
     * @return errlHndl_t  - NULL if successful, otherwise a pointer to the error log.
     */
    errlHndl_t validateAllRecordEccData (
                   const TARGETING::TargetHandle_t  i_target );

}; //end vpd namespace

namespace SPD
{
    /**
     * @brief This function sets the part and serial number attributes for
     *        a given DIMM target
     * @param[in] i_target - the DIMM target to set the attributes for
     *
     */
    void setPartAndSerialNumberAttributes( TARGETING::Target * i_target );

    /**
     * @brief Mode parameter for checkCRC routine.
     */
    enum CRCMODE_t
    {
        CHECK, // Return error if SPD has bad CRC
        FIX, // Rewrite any CRC that miscompares, commit info log for any miscompare
        CHECK_AND_FIX // Rewrite any CRC that miscompares, also commit visible log
    };

    // Define a range to compute CRC for
    struct crc_section_t {
        size_t   start;      // offset of this section in the VPD
        size_t   numbytes;   // number of bytes in the section, including 2 CRC bytes
        uint16_t crcSPD;     // existing CRC value, stored in the VPD
        uint16_t crcActual;  // CRC calculated after the VPD read,
                             //  this shows the current state of the CRC
        crc_section_t(size_t i_start, size_t i_numbytes) :
               start(i_start), numbytes(i_numbytes), crcSPD(0), crcActual(0) {}
    };

    enum
    {
        SPD_DDR5_DDIMM_USER_SECTION_START    = 640,
        SPD_DDR5_DDIMM_USER_SECTION_LENGTH   = 384,
        SPD_DDR5_DDIMM_USER_SECTION_DATA_END = 1021,
    };

    /**
     * @brief Evaluate and/or correct all CRC entries for this DDIMM
     * @param[in] i_target - Target to fetch SPD for
     * @param[in] i_mode - Which operations to perform
     *      CHECK : Return error if SPD has bad CRC
     *      FIX : Rewrite any CRC that miscompares, commit info log for any miscompare
     *      CHECK_AND_FIX : Rewrite any CRC that miscompares, also
     *                      commit visible log
     * @param[in] i_role - Describes which EEPROM associated to the
     *                     target that is being requested to check the CRC on.
     *                     PRIMARY, BACKUP, etc.
     * @param[in] i_location - Read from cache or hardware
     * @param[out] o_crc_sections - calculated crc sections
     * @param[out] o_missing_vpd - Whether the error returned was due to missing VPD
     *                             rather than to a CRC or other error. If null,
     *                             this parameter is ignored.
     * @return Error log
     */
    errlHndl_t checkCRC( TARGETING::TargetHandle_t i_target,
                         enum CRCMODE_t i_mode,
                         EEPROM::EEPROM_ROLE i_role,
                         EEPROM::EEPROM_SOURCE i_location,
                         std::vector<crc_section_t> & o_crc_sections,
                         bool* o_missing_vpd = nullptr);

    /**
     * @brief read the vpd and compute the CRC for a section in this DDIMM
     * @param[in]     i_target - Target to fetch SPD for
     * @param[in]     i role   - Describes which EEPROM associated to the
     *                           target that is being requested to check the CRC on.
     *                           PRIMARY, BACKUP, etc.
     * @param[in]     i_location  - Read from cache or hardware
     * @param[in,out] io_section  - Data representing the section of VPD.
     *                              [in]  Data used to read the VPD section
     *                              [out] The CRC read from the end of the VPD,
     *                                    and the CRC calculated from the VPD read.
     * @param[out]    o_spd_data  - actual vpd data read from this DDIMM
     * @return Error log
     */
    errlHndl_t computeCRC(TARGETING::TargetHandle_t i_target,
                          EEPROM::EEPROM_ROLE       i_role,
                          EEPROM::EEPROM_SOURCE     i_location,
                          crc_section_t            &io_section,
                          uint8_t                  *o_spddata);

    /**
     * @brief write the CRC for a section of vpd in this DDIMM
     * @param[in]  i_target - Target to write the CRC for
     * @param[in]  i role   - Describes which EEPROM associated to the
     *                        target that is being requested to check the CRC on.
     *                        PRIMARY, BACKUP, etc.
     * @param[in]  i_location - Read from cache or hardware
     * @param[in]  i_section  - data representing the section of vpd
     * @return Error log
     */
    errlHndl_t updateCRC(TARGETING::TargetHandle_t i_target,
                         EEPROM::EEPROM_ROLE       i_role,
                         EEPROM::EEPROM_SOURCE     i_location,
                         crc_section_t             i_section);

    /**
     * @brief Generates a 16 bit CRC in CCITT XModem mode
     * @param[in]     i_ptr    - array of bytes to calculate CRC over
     * @param[in]     i_bytes  - number of bytes to calculate CRC
     * @return CRC calculated from the array
     *
     * Reference code taken from JEDEC Standard No. 21-C
     *  Page 4.1.2.12.3 ?? 44
     */
    uint16_t jedec_Crc16(const uint8_t *i_ptr,
                               size_t   i_bytes);

    /**
     * @brief Forcibly write our cached SPD data out to the hardware
     * @param[in] i_target - Target to fetch SPD for
     * @return Error log
     */
    errlHndl_t fixEEPROM( TARGETING::TargetHandle_t i_target );

    /**
     * @brief As a workaround to avoid some SPD corruption that can occur
     *  in power off scenarios, we want to park the eeprom onto a
     *  "safe" unused portion after any access.  We will do this
     *  by doing a 1-byte read to address 2048.
     *
     * @param[in]     i_target    OCMB or DIMM Target
     *
     * @return  errlHndl_t
     */
    errlHndl_t ddimmParkEeprom(TARGETING::TargetHandle_t i_target);

    /*
     * @brief This function will read the DIMM memory information for OCMBs.
     *
     * @param[in] i_target       - The OCMB target to read data from.
     * @param[out] o_memType      - DDR revision (e.g. DDR4, DDR5).
     * @param[out] o_memModType   - DIMM module type (e.g. DDIMM, RDIMM).
     * @param[out] o_memHeight    - DIMM Height (e.g. 4U, 2U).
     * @param[in] i_eepromSource - The EEPROM source (CACHE/HARDWARE or AUTOSELECT).
     *
     * @return errlHndl_t - nullptr if successful, otherwise a pointer
     *      to the error log.
     */
    errlHndl_t getMemInfo(TARGETING::TargetHandle_t     i_target,
                          SPD::spdMemType_t &           o_memType,
                          SPD::spdModType_t &           o_memModType,
                          SPD::dimmModHeight_t &        o_memHeight,
                          EEPROM::EEPROM_SOURCE i_eepromSource = EEPROM::AUTOSELECT);

}
#endif
