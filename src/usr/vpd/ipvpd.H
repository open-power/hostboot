/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/ipvpd.H $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
#ifndef _VPD_IPVPD_H
#define _VPD_IPVPD_H


#include <list>
#include <map>
#include <pnor/pnorif.H>
#include <devicefw/driverif.H>
#include "vpd.H"
#include <eeprom/eeprom_const.H>
#include <vpd/ipz_vpd_consts.H>

/** @file ipvpd.H
 *  @brief Provides base support for i/p-Series style IBM VPD
 */

// Global variable to determine if the ECC APIs are present and available.
// Defined and set in file vpd_ecc_api.C.
extern const bool g_vpd_ecc_api_present;

/**
 *  @brief  Base class for i/p-Series VPD
 *
 */
class IpVpdFacade
{
  public:

    /**
     * @brief Structure for all VPD dd input parameter arguments
     */
    typedef struct device_driver_input_args
    {
        VPD::vpdRecord        record;
        VPD::vpdKeyword       keyword;
        VPD::vpdCmdTarget     location;
        EEPROM::EEPROM_SOURCE eepromSource;

        // Default constructor
        device_driver_input_args() : record(0xFFFFFFFF),
                                     keyword(0xFFFFFFFF),
                                     location(VPD::AUTOSELECT),
                                     eepromSource(EEPROM::AUTOSELECT)
        {};

        // This constructor allows for existing code using brace-enclosed
        // initializer lists of the first three arguments to continue to
        // function normally. Since the default behavior for EEPROM_SOURCE is
        // AUTOSELECT, setting it automatically here is done to maintain that
        // default assumption.
        device_driver_input_args(VPD::vpdRecord    i_record,
                                 VPD::vpdKeyword   i_keyword,
                                 VPD::vpdCmdTarget i_location)
            : record(i_record),
              keyword(i_keyword),
              location(i_location),
              eepromSource(EEPROM::AUTOSELECT)
        {};


    } input_args_t;

    /**
     * @brief Mapping from keyword enum into 4 character string
     */
    typedef struct
    {
        VPD::vpdRecord record;
        char recordName[RECORD_BYTE_SIZE+1];
    } recordInfo;

    /**
     * @brief Mapping from keyword enum into 2 character string
     */
    typedef struct
    {
        VPD::vpdKeyword keyword;
        char keywordName[KEYWORD_BYTE_SIZE+1];
    } keywordInfo;

    /**
     * @brief Mapping from record enum into PNOR section
     *        where override might be
     */
    typedef struct
    {
        VPD::vpdRecord record;
        PNOR::SectionId section;
    } recordOverrideInfo_t;

    /**
     * @brief Structure defining where to read/write VPD data
     */
    typedef struct
    {
        bool vpdReadPNOR;
        bool vpdReadHW;
        bool vpdWritePNOR;
        bool vpdWriteHW;
    } configInfo;

    /**
     * @brief - Data Struct for TOC Entry
     */
    struct tocData
    {
        tocData()
        {
            bzero(asciiRec, sizeof(asciiRec));
            bzero(offset, sizeof(offset));
            bzero(unusedByte, sizeof(unusedByte));
        }

        uint8_t asciiRec[RECORD_BYTE_SIZE];
        uint8_t offset[RECORD_ADDR_BYTE_SIZE];
        uint8_t unusedByte[RECORD_ADDR_BYTE_SIZE];
    };

    /**
     * @brief  Constructor
     *
     * @param[in] i_vpdRecords -     Pointer to array of VPD Records to use
     *
     * @param[in] i_recSize -       size of i_vpdRecords array
     *
     * @param[in] i_vpdKeywords -    Pointer to array of VPD Keywords to use
     *
     * @param[in] i_keySize -        size of i_vpdKeywords array
     *
     * @param[in] i_pnorSection -    PNOR Section containing VPD for current
     *                               chip
     *
     * @param[in] i_mutex -          Mutex to ensure instance variable updates
     *                               are thread safe
     *
     * @param[in] i_vpdMsgType -     Message type to use when sending write
     *                               data to FSP
     *
     */
    IpVpdFacade(const  recordInfo* i_vpdRecords,
                uint64_t i_recSize,
                const  keywordInfo* i_vpdKeywords,
                uint64_t i_keySize,
                PNOR::SectionId i_pnorSection,
                mutex_t i_mutex,
                VPD::VPD_MSG_TYPE i_vpdMsgType );


    /**
     * @brief This function will perform the steps required to do a read from
     *      the Hostboot I/P Series VPD data.
     *
     * @param[in] i_target -Target device
     *
     * @param [in/out] io_buffer - Pointer to the data that was read from
     *       the target device.  This parameter, when set to NULL, will return
     *       the keyword size value in io_buflen.
     *
     * @param [in/out] io_buflen - Length of the buffer to be read or written
     *       to/from the target.  This value should indicate the size of the
     *       io_buffer parameter that has been allocated.  Being returned it
     *       will indicate the number of valid bytes in the buffer being
     *       returned. This parameter will contain the size of a keyword when
     *       the io_buffer parameter is passed in NULL.
     *
     * @param [in] i_args - Records/Keyword struct
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the
     *       error log.
     */
    errlHndl_t read ( TARGETING::Target * i_target,
                      void* io_buffer,
                      size_t & io_buflen,
                      input_args_t i_args );

    /**
     * @brief This function will perform the steps required to do a write to
     *      the Hostboot I/P Series VPD data.
     *
     * @param[in] i_target -Target device
     *
     * @param [in/out] io_buffer - Pointer to the data that was read from
     *       the target device.  It will also be used to contain data to
     *       be written to the device.
     *
     * @param [in/out] io_buflen - Length of the buffer to be read or written
     *       to/from the target.  This value should indicate the size of the
     *       io_buffer parameter that has been allocated.  Being returned it
     *       willindicate the number of valid bytes in the buffer being
     *       returned.
     *
     * @param [in] i_args - Records/Keyword struct
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the
     *       error log.
     */
    errlHndl_t write ( TARGETING::Target * i_target,
                      void* io_buffer,
                      size_t & io_buflen,
                      input_args_t i_args );

    /**
     * @brief this function checks to see if the given target
     * is present.
     *
     * @param[in] i_target - target VPD to search for.
     *
     * @return - bool - true if vpd is present, false if it is not.
     */
    bool hasVpdPresent ( TARGETING::Target * i_target,
                         VPD::vpdRecord record,
                         VPD::vpdKeyword keyword );


    /**
     * @brief This function compares the specified record/keyword
     *        in CACHE/HARDWARE and returns the result.  A mismatch
     *        will not return an error.
     *
     * @param[in]  i_target    Target device
     *
     * @param[in]  i_record    Record to compare
     *
     * @param[in]  i_keyword   Keyword to compare
     *
     * @param[out] o_match     Result of compare
     *
     * @return errlHndl_t      NULL if successful, otherwise a pointer to the
     *                         error log.
     */
    errlHndl_t cmpEecacheToEeprom(TARGETING::Target * i_target,
                                  VPD::vpdRecord      i_record,
                                  VPD::vpdKeyword     i_keyword,
                                  bool              & o_match);

    /**
     * @brief This function compares the specified record/keyword
     *      in PNOR/SEEPROM and returns the result.  A mismatch
     *      will not return an error.
     *
     * @param[in] i_target - Target device
     *
     * @param[in] i_record - Record to compare
     *
     * @param[in] i_keyword - Keyword to compare
     *
     * @param[out] o_match - Result of compare
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the
     *       error log.
     */
    errlHndl_t cmpPnorToSeeprom ( TARGETING::Target * i_target,
                                  VPD::vpdRecord i_record,
                                  VPD::vpdKeyword i_keyword,
                                  bool &o_match );

    /**
     * @brief This function compares the specified record/keyword
     *      in SEEPROM to zero and returns the result.  A mismatch
     *      will not return an error.
     *
     * @param[in] i_target - Target device
     *
     * @param[in] i_record - Record to compare
     *
     * @param[in] i_keyword - Keyword to compare
     *
     * @param[out] o_match - Result of compare
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the
     *       error log.
     */
    errlHndl_t cmpSeepromToZero ( TARGETING::Target * i_target,
                                  VPD::vpdRecord i_record,
                                  VPD::vpdKeyword i_keyword,
                                  bool &o_match );

    /**
     * @brief This function will perform the steps required to load the
     *      MVPD data from SEEPROM into the PNOR cache.
     *
     * @param[in] i_target - Target device
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the
     *       error log.
     */
    errlHndl_t loadPnor ( TARGETING::Target * i_target );

    /**
     * @brief This function will perform the steps required to invalidate
     *      the MVPD in the PNOR cache.
     *
     * @param[in] i_target - Target device
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the
     *       error log.
     */
    errlHndl_t invalidatePnor ( TARGETING::Target * i_target );

    /**
     * @brief This function sets the config flags to use HW and not PNOR
     */
    void setConfigFlagsHW ( );

    /**
     * @brief Retrieve the record and update the record's ECC data
     *
     * @param[in] i_target - Pointer to the PROC target where the record is located.
     * @param[in] i_args   - Device driver input args: Struct that contains the
     *                       record ID, location of record and EEPROM source.
     *                       Keyword data is not used.
     * @param[in](optional) i_ptEntry - If not a nullptr then the meta data will be
     *                                  used from this parameter and therefore will not
     *                                  be retrieved for the record which can be a
     *                                  time saver.
     * @return errlHndl_t  - NULL if successful, otherwise a pointer to the error log.
     */
    errlHndl_t updateRecordEccData ( const TARGETING::TargetHandle_t  i_target,
                                     const IpVpdFacade::input_args_t &i_args,
                                     const pt_entry                  *i_ptEntry = nullptr );

    /**
     * @brief Validate all the MVPD records' ECC data
     *
     * @details This method will iterate thru all the MVPD records and validate
     *          the ECC data for each record. If validation fails on an MVPD then
     *          the next source for the MVPD will be examined until all MVPD
     *          sources are exhausted.
     *          A target will be deconfigured for the following reasons:
     *              * Validation of a record's ECC data failed after all MVPD
     *                sources have been exhausted.
     *              * The API to get the next MVPD source erred which prevents validation.
     *
     * @pre Target handle (i_target) must be of type PROC.
     *
     * @param[in] i_target - Pointer to the PROC target where the records are located.
     * @return errlHndl_t  - NULL if successful, otherwise a pointer to the error log.
     */
    errlHndl_t validateAllRecordEccData ( const TARGETING::TargetHandle_t  i_target );

#ifdef CONFIG_SECUREBOOT
    /**
     * @brief Load/unload the appropriate secure section for
     *        an overriden PNOR section
     * @param[in] i_args    Record/keyword
     * @param[in] i_target  Target pointer
     * @param[in] i_load    true=load, false=unload
     * @param[out] o_loaded true=section loaded, false=section not loaded
     * @return Error log
     */
    virtual errlHndl_t loadUnloadSecureSection( input_args_t i_args,
                                                TARGETING::Target* i_target,
                                                bool i_load,
                                                bool& o_loaded );
#endif


  protected:  // Methods

    /**
     * @brief This function will translate the enumeration for the VPD record
     *      into a char * variable to be used for comparing what was read from
     *      the VPD data.
     *
     * @param[in] i_record - The record enumeration.
     *
     * @param[out] o_record - The char representation of the record.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t translateRecord ( VPD::vpdRecord i_record,
                                 const char *& o_record );

    /**
     * @brief This function will translate the enumeration for the VPD keyword
     *      into a char * variable to be used for comparing what was read from
     *      the VPD data.
     *
     * @param[in] i_keyword - The keyword enumeration.
     *
     * @param[out] o_keyword - The char representation of the record.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t translateKeyword ( VPD::vpdKeyword i_keyword,
                                  const char *& o_keyword );

    /**
     * @brief This function calls the PNOR or EEPROM version of
     *      the findRecordOffset fuction based on the configInfo.
     *
     * @param[in] i_record - String value for the record to look for.
     *
     * @param[out] o_offset - The offset where the record is located.
     *
     * @param[in] i_rwPnorEnabled - Config value specifying
     *      whether PNOR reads/writes are enabled for this VPD type
     *
     * @param[in] i_rwHwEnabled - Config value specifying
     *      whether SEEPROM reads/writes are enabled for this VPD type
     *
     * @param[in] i_target - The target to retrieve the data for.
     *
     * @param[in] i_args - The input arguments.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t findRecordOffset ( const char * i_record,
                                  uint16_t & o_offset,
                                  bool i_rwPnorEnabled,
                                  bool i_rwHwEnabled,
                                  TARGETING::Target * i_target,
                                  input_args_t i_args );

    /**
     * @brief This function searches for the VPD record and returns
     * True if it is there, False otherwise. This function works similarly
     * to findRecordOffsetPnor except it does not create error logs if
     * the record was not found. This will replace some of the code in
     * findRecordOffsetPnor
     *
     * @param[in] i_record - String value for the record to look for.
     *
     * @param[out] offset - The offset where the record is located.
     *
     * @param[in] i_target - The target to retrieve the data for.
     *
     * @param[in] i_location - VPD location to fetch data from (PNOR/SEEPROM)
     *
     * @return bool - True if the record is found, False otherwise.
     */
    virtual bool recordPresent( const char * i_record,
                        uint16_t & offset,
                        TARGETING::Target * i_target,
                        VPD::vpdCmdTarget i_location );

    /**
     * @brief This function will read the VPD TOC to find the offset where the
     *      given record is located within the chunk of data.
     *
     * @param[in] i_record - String value for the record to look for.
     *
     * @param[out] o_offset - The offset where the record is located.
     *
     * @param[in] i_target - The target to retrieve the data for.
     *
     * @param[in] i_args - The input arguments.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t findRecordOffsetPnor ( const char * i_record,
                                      uint16_t & o_offset,
                                      TARGETING::Target * i_target,
                                      input_args_t i_args );

    /**
     * @brief This function will read the VPD VTOC to find the offset where the
     *      given record is located within the chunk of data.
     *
     * @param[in] i_record - String value for the record to look for.
     *
     * @param[out] o_offset - The offset where the record is located.
     *
     * @param[out] o_length - The length of the record.
     *
     * @param[in] i_target - The target to retrieve the data for.
     *
     * @param[in] i_args - The input arguments.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t findRecordOffsetSeeprom ( const char * i_record,
                                         uint16_t & o_offset,
                                         uint16_t & o_length,
                                         TARGETING::Target * i_target,
                                         input_args_t i_args );

    /**
     * @brief Get a record's meta data - record offset, record length, ECC offset
     *        and ECC length.
     *
     * @details A record is book ended by starting byte 0x84 and ending byte 0x78.
     *          In the document 'Common VPD Architecture' these bytes are referred
     *          to as 'Large Resource' for byte 0x84 and 'Small Resource' for
     *          byte 0x78.
     *          The record offset, that is returned, points to the 'Large Resource'
     *          byte 0x84, and the record length consists of the two book end bytes
     *          plus the size of the data between these two bytes.
     *
     * @param[in] i_record        - The record to find
     * @param[out] o_recordOffset - The offset of the record within the VPD.
     *                              The offset points to the 'Large Resource' byte 0x84.
     * @param[out] o_recordLength - The length of the record within the VPD.
     *                              This length consists of the two book end bytes
     *                              plus the size of the data between these two bytes.
     * @param[out] o_eccOffset    - The offset of the ECC within the VPD
     * @param[out] o_eccLength    - The length of the ECC within the VPD
     * @param[in] i_target        - Target pointer
     * @param[in] i_args          - The input arguments, key, record, location and
     *                              the EEPROM source.
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the
     *                      error log.
     */
    errlHndl_t findRecordMetaDataSeeprom ( const char * i_record,
                                           uint16_t & o_recordOffset,
                                           uint16_t & o_recordLength,
                                           uint16_t & o_eccOffset,
                                           uint16_t & o_eccLength,
                                           TARGETING::Target * i_target,
                                           const input_args_t &i_args );

    /**
     * @brief This function will scan the SEEPROM and return a list of VPD
     *      records for this target.
     *
     * @param[out] o_recList - The list of entries in the pt keyword representing
     *                         VPD records.
     *
     * @param[in] i_target - The target to retrieve the data for.
     *
     * @param[in] i_args - The input arguments.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t getRecordListSeeprom ( std::list<pt_entry> & o_recList,
                                      TARGETING::Target * i_target,
                                      input_args_t i_args );

    /**
     * @brief This function will read the required keyword from the VPD data.
     *
     * @param[in] i_keywordName - String representation of the keyword.
     *
     * @param[in] i_recordName - String representation of the record.
     *
     * @param[in] i_offset - The offset to start reading.
     *
     * @param[in] i_index - The index of the keyword to return if there are
     *       multiple instances of the same keyword.
     *
     * @param[in] i_target - The target to retrieve data for.
     *
     * @param[out] io_buffer - The buffer to place the data in.
     *
     * @param[in/out] io_buflen - Length of the buffer to be read or written
     *       to/from the target.  This value should indicate the size of the
     *       io_buffer parameter that has been allocated.  Being returned it
     *       will indicate the number of valid bytes in the buffer being
     *       returned.
     *
     * @param[in] i_args - The input arguments.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t retrieveKeyword ( const char * i_keywordName,
                                 const char * i_recordName,
                                 uint16_t i_offset,
                                 uint16_t i_index,
                                 TARGETING::Target * i_target,
                                 void * io_buffer,
                                 size_t & io_buflen,
                                 input_args_t i_args );

    /**
     * @brief This function will read the required record from the VPD data.
     *
     * @param[in] i_recordName - String representation of the record.
     *
     * @param[in] i_offset - The offset to start reading.
     *
     * @param[in] i_target - The target to retrieve data for.
     *
     * @param[out] io_buffer - The buffer to place the data in.
     *
     * @param[in/out] io_buflen - Length of the buffer to be read or written
     *       to/from the target.  This value should indicate the size of the
     *       io_buffer parameter that has been allocated.  Being returned it
     *       will indicate the number of valid bytes in the buffer being
     *       returned.
     *
     * @param[in] i_args - The input arguments.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t retrieveRecord ( const char * i_recordName,
                                 uint16_t i_offset,
                                 TARGETING::Target * i_target,
                                 void * io_buffer,
                                 size_t & io_buflen,
                                 input_args_t i_args );

    /**
     * @brief This function will write the required keyword into the VPD data.
     *
     * @param[in] i_keywordName - String representation of the keyword.
     *
     * @param[in] i_recordName - String representation of the record.
     *
     * @param[in] i_offset - The offset to start writing.
     *
     * @param[in] i_target - The target to write data for.
     *
     * @param[in] i_buffer - The buffer to pull the data from.
     *
     * @param[in] i_buflen - Length of the buffer to be written
     *       to the target's VPD area.  This value should indicate the
     *       size of the io_buffer parameter that has been allocated.
     *
     * @param[in] i_args - The input arguments.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t writeKeyword ( const char * i_keywordName,
                              const char * i_recordName,
                              uint16_t i_offset,
                              TARGETING::Target * i_target,
                              void * i_buffer,
                              size_t & i_buflen,
                              input_args_t i_args );

    /**
     * @brief This function will locate the byte address of a keyword
     *   within its VPD section.
     *
     * @param[in] i_keywordName - String representation of the keyword.
     *
     * @param[in] i_recordName - String representation of the record.
     *
     * @param[in] i_offset - The offset to start searching.
     *
     * @param[in] i_index - The index of the keyword to return if there are
     *    multiple instances of the same keyword.
     *
     * @param[in] i_target - The target to write data for.
     *
     * @param[out] o_keywordSize - Size of keyword in bytes.
     *
     * @param[out] o_byteAddr - Address of keyword, relative to this target's
     *    section.
     *
     * @param[in] i_args - The original input arguments.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t findKeywordAddr ( const char * i_keywordName,
                                 const char * i_recordName,
                                 uint16_t i_offset,
                                 uint16_t i_index,
                                 TARGETING::Target * i_target,
                                 size_t& o_keywordSize,
                                 uint16_t& o_byteAddr,
                                 input_args_t i_args );



    /**
     * @brief This function calls the PNOR or EEPROM version of
     *           the fetchData function based on the configInfo
     *
     * @param[in] i_byteAddr - The offset to be read.
     *
     * @param[in] i_numBytes - The number of bytes to read.
     *
     * @param[out] o_data - The data buffer where the data will be placed.
     *
     * @param[in] i_target - Target device.
     *
     * @param[in] i_location - VPD location to fetch data from (PNOR/SEEPROM)
     *
     * @param[in] i_record - String representation of the record.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t fetchData(uint64_t            i_byteAddr,
                         size_t              i_numBytes,
                         void *              o_data,
                         TARGETING::Target * i_target,
                         VPD::vpdCmdTarget   i_location,
                         const char*         i_record);

    /**
     * @brief This function calls the PNOR or EEPROM version of
     *           the fetchData function based on the configInfo
     *
     * @param[in] i_byteAddr  The offset to be read.
     *
     * @param[in] i_numBytes  The number of bytes to read.
     *
     * @param[out] o_data     The data buffer where the data will be placed.
     *
     * @param[in] i_target    Target device.
     *
     * @param[in] i_args      The input arguments
     *
     * @param[in] i_record    String representation of the record.
     *
     * @return errHndl_t      NULL if successful, otherwise a pointer to the
     *                        error log.
     */
    errlHndl_t fetchData(uint64_t            i_byteAddr,
                         size_t              i_numBytes,
                         void *              o_data,
                         TARGETING::Target * i_target,
                         input_args_t        i_args,
                         const char*         i_record);

    /**
     * @brief This function actually reads the data from PNOR
     *
     * @param[in] i_byteAddr - The offset to be read.
     *
     * @param[in] i_numBytes - The number of bytes to read.
     *
     * @param[out] o_data - The data buffer where the data will be placed.
     *
     * @param[in] i_target - Target device.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t fetchDataFromPnor ( uint64_t i_byteAddr,
                                   size_t i_numBytes,
                                   void * o_data,
                                   TARGETING::Target * i_target );

    /**
     * @brief This function actually reads the data from EEPROM
     *
     * @param[in] i_byteAddr - The offset to be read.
     *
     * @param[in] i_numBytes - The number of bytes to read.
     *
     * @param[out] o_data - The data buffer where the data will be placed.
     *
     * @param[in] i_target - Target device.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t fetchDataFromEeprom(uint64_t i_byteAddr,
               size_t i_numBytes,
               void * o_data,
               TARGETING::Target * i_target,
               EEPROM::EEPROM_SOURCE i_eepromSource = EEPROM::AUTOSELECT);

   /**
     * @brief This function compares 2 ipvpd record values.  Used for binary
     *       search to find a match.
     *
     * @param[in] e1 - Entry 1 to be compared.
     *
     * @param[in] e2 - Entry 2 to be compared.
     *
     * @return bool - Whether or not the e2 value is larger than the e1 value.
     */
    static bool compareKeywords ( const keywordInfo e1,
                                  const keywordInfo e2 );

    /**
     * @brief This function compares 2 vpd keyword values.  Used for binary
     *       search to find a match.
     *
     * @param[in] e1 - Entry 1 to be compared.
     *
     * @param[in] e2 - Entry 2 to be compared.
     *
     * @return bool - Whether or not the e2 value is larger than the e1 value.
     */
    static bool compareRecords ( const recordInfo e1,
                                 const recordInfo e2 );

    /**
     * @brief This function compares sizes to be sure buffers are large enough
     *      to handle the data to be put in them.  If it is not, it will return
     *      an error.
     *
     * @param[in] i_bufferSize - The size of the buffer to check.
     *
     * @param[in] i_expectedSize - The minimum size the buffer should be.
     *
     * @param[in] i_target - Target device. (Only used for error callout)
     *
     * @return errlHndl_t - An error log will be returned if the buffer is not
     *      large enough.
     */
    errlHndl_t checkBufferSize( size_t i_bufferSize,
                                size_t i_expectedSize,
                                TARGETING::Target * i_target );
    /**
     * @brief This function returns a primary and an alternate list of records
     *       that should be copied to pnor. The Alternate list is optional.
     *
     * @param[out] o_primaryVpdRecords - Pointer to array of VPD Records to use
     *
     * @param[out] o_primaryRecSize -    Size of o_primaryVpdRecords array
     *
     * @param[out] o_altVpdRecords -     Pointer to array of VPD Records to use
     *
     * @param[out] o_altRecSize -        Size of o_altVpdRecords array
     *
     */
    virtual void getRecordLists(
                const  recordInfo* & o_primaryVpdRecords,
                uint64_t           & o_primaryRecSize,
                const  recordInfo* & o_altVpdRecords,
                uint64_t           & o_altRecSize);

    /**
     * @brief Returns the cached pnor address
     *
     */
    inline static uint64_t getPnorAddr(const IpVpdFacade& x)
    {
        return x.iv_cachePnorAddr;
    };

    /**
     * @brief Set the cached pnor address to the given value
     *
     */
    inline void setPnorAddr(uint64_t i_pnorAddr)
    {
        this->iv_cachePnorAddr = i_pnorAddr;
    };


    /**
     * @brief Callback function to check for a record override and
     *        set iv_overridePtr appropriately
     * @param[in] i_record  Record name
     * @param[in] i_target  Target pointer
     * @param[out] o_ptr    Pointer to location of record in PNOR,
     *                      ==nullptr if there is no override
     * @return Error log
     */
    virtual errlHndl_t checkForRecordOverride( const char* i_record,
                                               TARGETING::Target* i_target,
                                               uint8_t*& o_ptr );

    /**
     * @brief Retrieve the VTOC meta data - record name, record type, record offset,
     *        record length, ecc offset and ecc length.
     *
     * @details If the input parameter i_vhdrFullRecordData is NULL then the meta
     *          data will be retrieved via the retrieveKeyword API using the
     *          input i_args as parameters.  If i_vhdrFullRecordData is not NULL,
     *          then the VTOC meta data will be extracted from this input.
     *
     * @pre If the optional input argument i_vhdrFullRecordData is given, then
     *      it must be fully initialized, meaning that the VTOC meta data must
     *      be filled in. The constructor for the argument i_vhdrFullRecordData,
     *      of type vhdr_record, will not fill in the VTOC data therefore it must
     *      be filled in by other means. If the VTOC meta data is not present then
     *      an assertion will be raised.
     *
     * @post If no error occurs then the output parameter o_ptEntry will contain
     *       the record meta data.  If an error occurs, an error log will be
     *       returned and the output parameter o_ptEntry will be zeroed out.
     *
     * @param[in] i_target - Pointer to the PROC target to retrieve the VTOC record from
     * @param[in] i_args   - Device driver input args: Struct that contains the record
     *                       ID, keyword ID, location of record and EEPROM source.
     * @param[out] o_vtocRecordMetaData - Struct to contain the record meta data - record name,
     *                                    record type, record offset, record length, ecc offset
     *                                    and ecc length. The meta data returned is in big endian,
     *                                    will need to convert to little endian, if necessary.
     * @param[in](optional) i_vhdrFullRecordData - If given the VHDR record, then
     *                      the VTOC record meta data will be extracted from this record.
     * @return errlHndl_t  - NULL if successful, otherwise a pointer to an error log.
     */
    errlHndl_t getVtocRecordMetaData (
                TARGETING::Target*      i_target,
                const input_args_t      &i_args,
                pt_entry                &o_vtocRecordMetaData,
                const vhdr_record* const i_vhdrFullRecordData = nullptr );

    /**
     * @brief Validate all the MVPD records' ECC data
     *
     * @details This method will iterate thru all the MVPD records and validate
     *          the ECC data for each record.
     *
     * @pre Target handle (i_target) must be of type PROC, if not, an assertion is raised.
     *
     * @param[in] i_target - Pointer to the PROC target where the records are located.
     * @return errlHndl_t  - NULL if successful, otherwise a pointer to the error log.
     */
    errlHndl_t _validateAllRecordEccData ( const TARGETING::TargetHandle_t  i_target );

    /**
     * @brief Validate the VHDR's (VPD Header Record) ECC data.
     *
     * @details Validate that the VHDR's ECC data is correct for the VHDR's record
     *          data. If a correctable error is returned, while validating the
     *          data, then update the VHDR record with the corrected record data.
     *          All other errors are passed back.
     *
     * @post If no error occurs then the outgoing parameter, o_vhdrRecordData, will have it's
     *       VTOC meta data filled in.
     *
     * @param[in] i_target - Pointer to the PROC target to retrieve the VHDR record from.
     * @param[in] i_args   - Device driver input args: Struct that contains the record
     *                       ID, keyword ID, location of record and EEPROM source.
     *                       Record ID and keyword ID are not used and therefore not necessary.
     * @param[out] o_vhdrRecordData - The VHDR record data to be populated with the VTOC meta data
     * @return errlHndl_t  - NULL if successful, otherwise a pointer to an error log.
     */
    errlHndl_t validateVhdrRecordEccData(
                const TARGETING::TargetHandle_t i_target,
                const input_args_t              &i_args,
                vhdr_record                     &o_vhdrRecordData );

    /**
     * @brief Get the full VHDR (VPD Header Record) data which includes ECC data, etc.
     *
     * @post If no error occurs then the outgoing parameter, o_vhdrRecordData, will have it's
     *       VTOC meta data filled in.
     *
     * @param[in] i_target - Pointer to the PROC target to retrieve the VHDR record from.
     * @param[in] i_args   - Device driver input args: Struct that contains the record
     *                       ID, keyword ID, location of record and EEPROM source.
     *                       Record ID and keyword ID are not used and therefore not necessary.
     * @param[out] o_vhdrRecordData - The VHDR record data to be populated with the VTOC meta data
     * @return errlHndl_t  - NULL if successful, otherwise a pointer to an error log.
     */
    errlHndl_t getFullVhdrRecordData (
                const TARGETING::TargetHandle_t i_target,
                const input_args_t              &i_args,
                vhdr_record                     &o_vhdrRecordData );

    /**
     * @brief Validate the VTOC's (VPD Table of Content) record ECC data
     *
     * @param[in] i_target - Pointer to the PROC target to retrieve the VTOC record from.
     * @param[in] i_args   - Device driver input args: Struct that contains the record
     *                       ID, keyword ID, location of record and EEPROM source.
     *                       Record ID and keyword ID are not used and therefore not necessary.
     * @param[in] i_vhdrRecordData - The VHDR record data that contains the VTOC meta data.
     * @return errlHndl_t  - NULL if successful, otherwise a pointer to an error log.
     */
    errlHndl_t validateVtocRecordEccData (
               const TARGETING::TargetHandle_t  i_target,
               const IpVpdFacade::input_args_t &i_args,
               const vhdr_record               &i_vhdrRecordData);

    /**
     * @brief This method will validate all record's ECC data, not including the
     *        VHDR and the VTOC records.
     *
     * @param[in] i_target - Pointer to the PROC target where the records are located.
     * @param[in] i_args   - Device driver input args: Struct that contains the record
     *                       ID, keyword ID, location of record and EEPROM source.
     *                       Record ID and keyword ID are not used and therefore not necessary.
     * @param[in] i_vhdrRecordData - The VHDR record data that contains the VTOC meta data.
     * @return errlHndl_t  - NULL if successful, otherwise a pointer to the error log.
     */
    errlHndl_t validateAllOtherRecordEccData(
                const TARGETING::TargetHandle_t  i_target,
                const input_args_t              &i_args,
                const vhdr_record               &i_vhdrRecordData );

    /**
     * @brief Get the meta data for all records of the VPD, excluding the VHDR
     *        and VTOC record.
     *
     * @param[in] i_target - Pointer to the PROC target where the records are located.
     * @param[in] i_args   - Device driver input args: Struct that contains the record
     *                       ID, keyword ID, location of record and EEPROM source.
     *                       Record ID and keyword ID are not used and therefore not necessary.
     * @param[out] o_recordMetaDataList - The list of meta data for each record found,
     *                                    minus the VHDR and VTOC record. The meta data returned
     *                                    is in big endian, will need to convert to little endian,
     *                                    if necessary.
     * @param[in] i_vhdrRecordData - The VHDR record data that contains the VTOC meta data.
     * @return errlHndl_t  - NULL if successful, otherwise a pointer to the error log.
     */
    errlHndl_t getAllRecordMetaData (
                const TARGETING::TargetHandle_t i_target,
                const input_args_t             &i_args,
                std::list<pt_entry>            &o_recordMetaDataList,
                const vhdr_record              &i_vhdrRecordData );

    /**
     * @brief Get the meta data for the record named in the input args, i_args.record,
     *        from the VPD.
     *
     * @param[in] i_target - Pointer to the PROC target where the record is located.
     * @param[in] i_args   - Device driver input args: Struct that contains the record
     *                       ID, keyword ID, location of record and EEPROM source.
     *                       The record ID, identifies the record that the meta data
     *                       will be retrieved for. Keyword ID is not used.
     * @param[out] o_recordMetaData - Will contain the record meta data, if found, else
     *                                will be "zeroed" out. The meta data returned is in
     *                                big endian, will need to convert to little endian,
     *                                if necessary.
     * @param[in](optional) i_recordName - If not a nullptr, must be the translated record
     *                                     name of i_args.record. Providing a value will
     *                                     expedite the execution of this method.
     * @return errlHndl_t  - NULL if successful, otherwise a pointer to the error log.
     */
    errlHndl_t getRecordMetaData (
                const TARGETING::TargetHandle_t  i_target,
                const input_args_t              &i_args,
                pt_entry                        &o_recordMetaData,
                const char* const                i_recordName = nullptr );

    /**
     * @brief If i_recordName is a nullptr, then get the meta data for all records of the VPD,
     *        excluding the VHDR and VTOC record, else if i_recordName if not NULL, then
     *        only get the meta data for i_recordName.
     *
     * @param[in] i_target - Pointer to the PROC target where the records are located.
     * @param[in] i_args   - Device driver input args: Struct that contains the record
     *                       ID, keyword ID, location of record and EEPROM source.
     *                       Record ID and keyword ID are not used and therefore not necessary.
     * @param[in] i_vtocRecordMetaData - The VTOC record meta data.  The VTOC record contains a
     *                                   reference to all other records. The meta data will need
     *                                   to be in big endian.
     * @param[out] o_recordMetaDataList - If i_recordName is not a nullptr then will contain a single
     *                                    entry for that record else, if i_recordName is null, then
     *                                    the list of meta data for each record found, minus the
     *                                    VHDR and VTOC record. The meta data returned is in big endian,
     *                                    will need to convert to little endian, if necessary.
     * @param[in](optional) i_recordName - If not null, will only retrieve the meta data for this
     *                                     record, if NULL, then all record meta data is retrieved
     *                                     excluding the VHDR and VTOC record.
     * @return errlHndl_t  - NULL if successful, otherwise a pointer to the error log.
     */
    errlHndl_t _getRecordMetaData (
                const TARGETING::TargetHandle_t  i_target,
                const pt_entry                  &i_vtocRecordMetaData,
                const input_args_t              &i_args,
                std::list<pt_entry>             &o_recordMetaDataList,
                const char* const                i_recordName = nullptr );

    /**
     * @brief Check the return code of the create ECC data API, returning
     *        a proper error log, if necessary, for the return code given.
     *
     * @details This method just creates an error log, it is up to the caller
     *          to expand upon/modify/commit or delete the error log as needed.
     *          The error log returned will be of type unrecoverable,
     *          ERRL_SEV_UNRECOVERABLE.
     *          The module ID will be VPD::VPD_IPVPD_ECC_DATA_UPDATE with an
     *          appropriate reason code: VPD::VPD_ECC_DATA_ECC_SIZE_ISSUE
     *          or VPD::VPD_ECC_DATA_UNKNOWN_FAILURE.
     *          The user data will consist of the HUID of the target, record to create
     *          the ECC data for, error code returned from call to vpdecc_create_ecc,
     *          record data offset, record data length, ecc data offset and ecc data length.
     *
     * @param[in] i_createEccDataReturnCode - The return code from calling the
     *                                        create the ECC data API.
     * @param[in] i_target  - Pointer to the PROC target where the record is located.
     * @param[in] i_args    - Struct that contains the record ID, location of record
     *                        and EEPROM source.  Keyword data is not used.
     * @param[in] i_recordName   - Name of the record having it's ECC data validated.
     * @param[in] i_recordOffset - Offset to the record's data.
     * @param[in] i_recordLength - Length of the record's data.
     * @param[in] i_eccOffset    - Offset to the record's ECC data.
     * @param[in] i_eccLength    - Length of the record's ECC data.
     * @return errlHndl_t  - NULL if successful, otherwise a pointer to the
     *                       error log.
     */
    errlHndl_t checkCreateEccDataReturnCode(
                      size_t                     i_createEccDataReturnCode,
                const TARGETING::TargetHandle_t  i_target,
                const IpVpdFacade::input_args_t &i_args,
                const char *                     i_recordName,
                      uint16_t                   i_recordOffset,
                      uint16_t                   i_recordLength,
                      uint16_t                   i_eccOffset,
                      uint16_t                   i_eccLength );

    /**
     * @brief Check the return code of the ECC data validation API, returning
     *        a proper error log, if necessary, for the return code given.
     *
     * @details This method just creates an error log, it is up to the caller
     *          to expand upon/modify/commit or delete the error log as needed.
     *          With the exception of a correctable error, the error log returned
     *          will be of type unrecoverable, ERRL_SEV_UNRECOVERABLE, while a
     *          correctable error is of type informational, ERRL_SEV_INFORMATIONAL.
     *          The module ID will be VPD::VPD_IPVPD_ECC_DATA_CHECK be with an
     *          appropriate reason code: VPD::VPD_ECC_DATA_ECC_SIZE_ISSUE,
     *          VPD::VPD_ECC_DATA_UNCORRECTABLE_DATA, VPD::VPD_ECC_DATA_CORRECTABLE_DATA,
     *          or VPD::VPD_ECC_DATA_UNKNOWN_FAILURE. The user data will consist
     *          of the HUID of the target, record to validate ECC data for, error
     *          code returned from call to vpdecc_check_data, record data offset,
     *          record data length, ecc data offset and ecc data length.
     *
     * @param[in] i_eccDataValidationReturnCode - The return code from calling the
     *                                            ECC data validation API.
     * @param[in] i_target  - Pointer to the PROC target where the record is located.
     * @param[in] i_args    - Device driver input args: Struct that contains the record
     *                        ID, keyword ID, location of record and EEPROM source.
     * @param[in] i_recordName   - Name of the record having it's ECC data validated.
     * @param[in] i_recordOffset - Offset to the record's data.
     * @param[in] i_recordLength - Length of the record's data.
     * @param[in] i_eccOffset    - Offset to the record's ECC data.
     * @param[in] i_eccLength    - Length of the record's ECC data.
     * @return errlHndl_t - NULL if the return code is a known good state, else
     *                      an error log that is specific to the return code.
     */
    errlHndl_t checkEccDataValidationReturnCode(
                      size_t                     i_eccDataValidationReturnCode,
                const TARGETING::TargetHandle_t  i_target,
                const IpVpdFacade::input_args_t &i_args,
                const char *                     i_recordName,
                      uint16_t                   i_recordOffset,
                      uint16_t                   i_recordLength,
                      uint16_t                   i_eccOffset,
                      uint16_t                   i_eccLength );

    /**
     * @brief A wrapper around the vpdecc_create_ecc API.
     *
     * @details For the given record data and length of the record this method
     *          returns the created ECC data for that given record. Caller must
     *          create the ECC data buffer to contain the created ECC data. If
     *          the ECC data buffer is not large enough to contain the created
     *          ECC data then an error code will be returned indicating that.
     *
     * @note The parameters are not in HB style, but match the API vpdecc_create_ecc.
     *
     * @pre Caller must create the ECC data buffer that will be populated with the ECC
     *      data.  The ECC data length should be size of the created ECC data buffer.
     *
     * @post If no error occurs then the output parameter, o_eccData, will contain
     *       the created ECC data for the given record.  The returned ECC data length,
     *       of the created ECC data, may or may not be smaller than the given ECC
     *       data length.
     *
     * @param[in] i_recordData  - Pointer to a VPD's record data. Starting with
     *                            the Large Resource ID, 0x84, and ending with the
     *                            Small Resource ID, 0x78, inclusively.
     * @param[in] i_recordLength - The length of the record data.
     * @param[out] o_eccData     - Pointer to the created ECC data that is
     *                             associated with the record data.
     * @param[in/out] io_eccLength - [in]  A pointer to the length of the ECC data buffer.
     *                               [out] A pointer to the length of the returned ECC
     *                                     data, created in the ECC data buffer.
     * @return 0 if success, non-zero for failure/issues
     */
    int vpdeccCreateEcc (
                const unsigned char* i_recordData, size_t  i_recordLength,
                unsigned char*       o_eccData,    size_t* io_eccLength);

    /**
     * @brief A wrapper around the vpdecc_check_data API.
     *
     * @details For the given record data and ECC data of the given record, this
     *          method will verify that the ECC data is correct for the record
     *          data. If the given record data has an issue and can be corrected
     *          then the record data will be updated and a return code indicating
     *          that. If there was an issue validating the ECC data then an error
     *          code is returned indicating the failure.
     *
     * @note The parameters are not in HB style, but match the API vpdecc_create_ecc.
     *
     * @param[in/out] io_recordData  - [in] Pointer to a VPD's record data. Starting
     *                                      with the Large Resource ID, 0x84, and ending
     *                                      with the Small Resource ID, 0x78, inclusively.
     *                                 [out] If a correctable error occurrs then this will
     *                                       contain an updated buffer with the corrected data.
     * @param[in] i_recordLength - The length of the record data.
     * @param[in] i_eccData      - Pointer to the ECC data associated with the record data.
     * @param[in] i_eccLength    - The length of the ecc data.
     * @return 0 if success, non-zero for failure/issues
     */
    int vpdeccCheckData(
                unsigned char*       io_recordData, size_t i_recordLength,
                const unsigned char* i_eccData,     size_t i_eccLength);

  protected: // Variables

    /**
     * @brief Indicates allocated space for each chip's VPD
     *        data in PNOR.
     */
    uint64_t iv_vpdSectionSize;

    /**
     * @brief Indicates number of VPD sections in PNOR for
     *        current type of chip
     */
    uint64_t iv_vpdMaxSections;

  public: //Used by static function
    /**
     * @brief Pointer to array of VPD Record information
     *
     */
    const recordInfo* iv_vpdRecords;

    /**
     * @brief Number of VPD Records for current chip
     *
     */
    const uint64_t iv_recSize;

  protected:
    /**
     * @brief Pointer to array of VPD Keyword information
     *
     */
    const keywordInfo* iv_vpdKeywords;

    /**
     * @brief Number of VPD Keywords for current chip
     *
     */
    const uint64_t iv_keySize;

    /**
     * @brief PNOR section enum for vpd type
     *
     */
    PNOR::SectionId iv_pnorSection;

    /**
     * @brief VPD Operation Mutex
     *
     */
    mutex_t iv_mutex;

    /**
     * @brief cached PNOR offset for VPD
     *
     */
    uint64_t iv_cachePnorAddr;

    /**
     * @brief cached PNOR offset for VPD
     *
     */
    VPD::VPD_MSG_TYPE iv_vpdMsgType;

    /**
     * @brief Config defining where to read/write
     *          VPD data
     */
    configInfo iv_configInfo;

    /**
     * @brief Used to denote if a record is being
     *        fetched from a copy in our code image versus the
     *        real VPD EEPROM (or cache)
     */
    VPD::OverrideMap_t iv_overridePtr;

};



#endif /* _VPD_IPVPD_H */
