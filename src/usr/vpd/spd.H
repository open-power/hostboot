/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/spd.H $                                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2023                        */
/* [+] Evan Lojewski                                                      */
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
#ifndef __SPD_H
#define __SPD_H

/**
 * @file spd.H
 *
 * @brief Provides the interfaces for the SPD device driver
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <errl/errlentry.H>
#include <vpd/spdenums.H>
#include "vpd.H"
#include <attributeenums.H>
#include <eeprom/eeprom_const.H>

namespace SPD
{

/**
 * @brief Enumerations for Module Specific Keywords
 */
enum modSpecTypes_t
{
    NA        = 0x00, // Invalid Type
    UMM       = 0x01, // Unbuffered Memory Modules
    RMM       = 0x02, // Registered Memory Modules
    CMM       = 0x04, // Clocked Memory Modules
    LRMM      = 0x08, // Load Reduction Memory Modules
    DDIMM     = 0x10, // Differential DIMM
    PLANAR    = 0x20, // Planar EEPROM
    ALL       = 0xFFFF,
};

/**
* @brief Structure to define the lookup table for SPD keywords
*       for DIMMs.
*/
struct KeywordData
{
    uint16_t keyword;   // SPD keyword this data corresponds to
    uint16_t offset;    // Byte offset in the SPD data
    uint16_t length;    // Number of bytes to retrieve
    uint8_t bitMask;    // Bit mask, if non-zero it is used to mask off bits.
                        // This applies to only byte0 in a non special case
    uint8_t shift;      // Used for fields < 1 byte to right justify all values.
    bool isSpecialCase; // Whether or not this entry is a special case.
    bool writable;      // Whether this keyword can be written to.
    modSpecTypes_t modSpec; // Module Specific type keyword is valid for.
};

/**
 * @brief This function is used to read SPD keywords from collected
 *      SPD data for the given target
 *
 * @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
 *       driververif.H
 *
 * @param[in] i_target - DIMM Target device
 *
 * @param [in/out] io_buffer - Pointer to the data that was read from
 *       the target device.
 *
 * @param [in/out] io_buflen - Length of the buffer to be read
 *       from the target.  This value should indicate the size of the
 *       io_buffer parameter that has been allocated.  Being returned it will
 *       indicate the number of valid bytes in the buffer being returned.
 *
 * @param [in] i_accessType - Access Type - See DeviceFW::AccessType in
 *       usrif.H
 *
 * @param [in] i_args - This is an argument list for the device driver
 *       framework.
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t spdGetKeywordValue ( DeviceFW::OperationType i_opType,
                                TARGETING::Target * i_target,
                                void * io_buffer,
                                size_t & io_buflen,
                                int64_t i_accessType,
                                va_list i_args );

/**
 * @brief This function is used to write SPD keyword values.
 *
 * @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
 *       driververif.H
 *
 * @param[in] i_target - DIMM Target device
 *
 * @param [in/out] io_buffer - Pointer to the data that will contain data
 *       to be written to the device.
 *
 * @param [in/out] io_buflen - Length of the buffer to be written
 *       to the target.  This value should indicate the size of the
 *       io_buffer parameter that has been allocated.  Being returned it will
 *       indicate the number of valid bytes written to the target.
 *
 * @param [in] i_accessType - Access Type - See DeviceFW::AccessType in
 *       usrif.H
 *
 * @param [in] i_args - This is an argument list for the device driver
 *       framework.
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t spdWriteKeywordValue ( DeviceFW::OperationType i_opType,
                                  TARGETING::Target * i_target,
                                  void * io_buffer,
                                  size_t & io_buflen,
                                  int64_t i_accessType,
                                  va_list i_args );

/**
 * @param This function is a wrapper for reading the correct keyword.
 *      It will route the read to whatever function has the latest
 *      supported access code.
 *
 * @param[in] i_byteAddress - The offset into the JEDEC SPD layout.
 *
 * @param[in] i_numbytes - Number of bytes to read.
 *
 * @param[out] o_data - The data buffer that will return the data read.
 *
 * @param[in] i_target - The target DIMM to access.
 *
 * @param[in] i_eepromSource Eeprom source (CACHE/HARDWARE).
 *                           Default AUTOSELECT
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t spdFetchData(uint64_t i_byteAddr,
                       size_t i_numBytes,
                       void * o_data,
                       TARGETING::Target * i_target,
                       EEPROM::EEPROM_SOURCE i_eepromSource = EEPROM::AUTOSELECT
                    );

/**
 * @brief This function is a wrapper for writing the correct keyword.
 *      It will route the write to whatever function has the latest
 *      supported access code.
 *
 * @param[in] i_offset - The offset into the JEDEC SPD layout.
 *
 * @param[in] i_numbytes - Number of bytes to read.
 *
 * @param[in] i_data - The data buffer that will return the data read.
 *
 * @param[in] i_target - The target DIMM to access.
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t spdWriteData ( uint64_t i_offset,
                          size_t i_numBytes,
                          void * i_data,
                          TARGETING::Target * i_target );


/**
 * @param This function will read the SPD keyword from the appropriate
 *      table.
 *
 * @param[in] i_keyword - The SPD keyword to access.
 *
 * @param[in/out] io_buffer - The buffer that will contain the data
 *      read from the SPD data.
 *
 * @param[in/out] io_buflen - The requested number of bytes to read.
 *      The actual number of bytes read will be returned.
 *
 * @param[in] i_target - The target DIMM to access the data for.
 *
 * @param[in] i_DDRRev - The DIMM DDR Revision.
 *
 * @param[in] i_eepromSource The eeprom source (CACHE/HARDWARE).
 *                           Default AUTOSELECT
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t spdGetValue(VPD::vpdKeyword i_keyword,
                       void * io_buffer,
                       size_t & io_buflen,
                       TARGETING::Target * i_target,
                       uint64_t i_DDRRev,
                       EEPROM::EEPROM_SOURCE i_eepromSource = EEPROM::AUTOSELECT
                      );


/**
 * @brief This function will write the SPD keyword from the appropriate
 *      table.
 *
 * @param[in] i_keyword - The SPD keyword to access.
 *
 * @param[in/out] io_buffer - The buffer that will contain the data
 *      written from the SPD data.
 *
 * @param[in/out] io_buflen - The requested number of bytes to write.
 *      The actual number of bytes written will be returned.
 *
 * @param[in] i_target - The target DIMM to access the data for.
 *
 * @param[in] i_DDRRev - The DIMM DDR Revision.
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t spdWriteValue ( VPD::vpdKeyword i_keyword,
                           void * io_buffer,
                           size_t & io_buflen,
                           TARGETING::Target * i_target,
                           uint64_t i_DDRRev );


/**
 * @param This function handles the special case keywords where
 *      the data isn't sequential, or is broken up between two different
 *      offsets within the layout.
 *
 * @param[in] i_kwdData - The SPD keyword to access.
 *
 * @param[in/out] io_buffer - The buffer that will contain the data
 *      read from the SPD data.
 *
 * @param[in] i_target - The target DIMM to access the data for.
 *
 * @param[in] i_DDRRev - The DIMM DDR Revision.
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t spdSpecialCases ( const KeywordData & i_kwdData,
                             void * io_buffer,
                             TARGETING::Target * i_target,
                             uint64_t i_DDRRev );

/**
 * @brief This function checks to make sure that the buffer allocated
 *      is large enough to hold the data that needs to be returned.
 *
 * @param[in] i_bufferSz - The size of the buffer passed in by the caller.
 *
 * @param[in] i_expBufferSz - The expected buffer size for the keyword
 *      requested.
 *
 * @param[in] i_keyword - The SPD Keyword requested.
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t spdCheckSize ( size_t i_bufferSz,
                          size_t i_expBufferSz,
                          VPD::vpdKeyword i_keyword );

/**
 * @brief This function is used to check if the given target
 *        is present
 *
 * @param[in] i_target - DIMM Target device
 *
 * @return bool - true if present, false if not present
 */
bool spdPresent ( TARGETING::Target * i_target );

/**
 * @brief This function performs the presence detect for all DIMMs.
 *
 * @param[in] i_opType - Operation type, see DeviceFW::OperationType
 *      in driverif.H
 *
 * @param[in] i_target - The target to query.
 *
 * @param[in/out] io_buffer - Buffer to contain the boolean for presence
 *      detect.
 *
 * @param[in/out] io_buflen - Size of buffer provided for doing the presence
 *      detect.  Will always be 1.  If size returned equals 0, the request
 *      failed.
 *
 * @param[in] i_accessType - DeviceFW::AccessType enum.
 *
 * @param[in] i_args - An argument for the Device Driver framework.  There
 *      are no args for this function.
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t dimmPresenceDetect( DeviceFW::OperationType i_opType,
                               TARGETING::Target * i_target,
                               void * io_buffer,
                               size_t & io_buflen,
                               int64_t i_accessType,
                               va_list i_args );


/**
 * @brief This function will read the DIMM module type.
 *
 * @param[out] o_modType - The module type value to return.
 *
 * @param[in] i_target - The target to read data from.
 *
 * @param[in] i_memType - The memory type
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer
 *      to the error log.
 */
errlHndl_t getModType ( modSpecTypes_t & o_modType,
                        TARGETING::Target * i_target,
                        uint64_t i_memType );

/**
 * @brief This function will scan the table and return the entry
 *      corresponding to the keyword being requested.
 *
 * @param[in] i_keyword - The keyword being requested.
 *
 * @param[in] i_memType - The memory type of the target.
 *
 * @param[in] i_target - Target (only used for callouts)
 *
 * @param[out] o_entry - The table entry corresponding to the keyword.
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t getKeywordEntry(VPD::vpdKeyword    i_keyword,
                           uint64_t           i_memType,
                           TARGETING::Target* i_target,
                           const KeywordData* &o_entry );
/**
 * @brief This function is used to check the parameters in the SPD data that
 *      indicate which module specific keywords are valid, and then check that
 *      against the data in the table flags.
 *
 * @param[in] i_kwdData - The table entry for the keyword being requested.
 *
 * @param[in] i_memType - The DDRx revision value from Byte 2 of the SPD data.
 *
 * @param[in] i_target - The chip target.
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t checkModSpecificKeyword ( KeywordData i_kwdData,
                                     uint64_t i_memType,
                                     TARGETING::Target * i_target );

/**
 * @brief This function compares value of the keyword in CACHE/HARDWARE
 *        and returns the result
 *
 * @param[in] i_target - Target device
 *
 * @param[in] i_eepromType - Eeprom content type of target device
 *
 * @param [in] i_keyword - Keyword to compare
 *
 * @param [in] o_match - Result of keyword compare
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the
 *         error log.  A mismatch will not return an error.
 */
errlHndl_t cmpEecacheToEeprom(TARGETING::Target *            i_target,
                              TARGETING::EEPROM_CONTENT_TYPE i_eepromType,
                              VPD::vpdKeyword                i_keyword,
                              bool&                          o_match);


}; // end SPD namespace

#endif  // __SPD_H
