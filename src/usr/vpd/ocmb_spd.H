/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/ocmb_spd.H $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
#ifndef __OCMB_SPD_H
#define __OCMB_SPD_H

#include <i2c/eeprom_const.H>

namespace SPD
{

/**
* @brief Read keyword from SPD
*
*        Currently used to detect I2C_MUTEX and OCMB_CHIP targets
*
* @param[in]     i_target     OCMB target to read data from
* @param[in/out] io_buffer    databuffer SPD will be written to
* @param[in/out] io_buflen    length of the given data buffer
* @param[in]     i_keyword    keyword from spdenums.H to read
* @param[in]     i_memType    The memory type of this target.
* @param[in]     i_location   The EEPROM source (CACHE/HARDWARE).
*
* @pre io_buffer and i_target must be non-null
* @pre currenlty only supported value for i_keyword is ENTIRE_SPD
*
* @return  errlHndl_t
*/
errlHndl_t ocmbGetSPD(TARGETING::TargetHandle_t        i_target,
                      void*                            io_buffer,
                      size_t&                          io_buflen,
                      const VPD::vpdKeyword            i_keyword,
                      const uint8_t                    i_memType,
                      EEPROM::EEPROM_SOURCE            i_location);

// @TODO RTC 203788 doxygen
bool isValidOcmbDimmType(const uint8_t i_dimmType);

// @TODO RTC 203788 doxygen
errlHndl_t getMemType(uint8_t&                      o_memType,
                      TARGETING::TargetHandle_t     i_target,
                      EEPROM::EEPROM_SOURCE         i_location);

/**
 * @param This function is a wrapper for reading the correct keyword.
 *
 * @param[in]  i_target     The target DDIMM to access.
 *
 * @param[in]  i_byteAddr   The offset into the JEDEC SPD layout.
 *
 * @param[in]  i_numbytes   Number of bytes to read.
 *
 * @param[out] o_data       The data buffer that will return the data read.
 *
 * @param[in]  i_location   The EEPROM source (CACHE/HARDWARE).
 *
 * @return     errlHndl_t   nullptr if successful, otherwise a pointer to the
 *                          error log.
 */
errlHndl_t ocmbFetchData(TARGETING::TargetHandle_t    i_target,
                         uint64_t                     i_byteAddr,
                         size_t                       i_numBytes,
                         void*                        o_data,
                         EEPROM::EEPROM_SOURCE        i_location);

}

#endif
