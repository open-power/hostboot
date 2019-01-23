/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/eepromCache.H $                                   */
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
#ifndef __EEPROM_CACHE_H
#define __EEPROM_CACHE_H

#include <i2c/eeprom_const.H>
#include <errl/errlentry.H>

namespace EEPROM
{

/**
*
* @brief Perform a read or write operation on an eeprom record inside EEACHE
*
*
* @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
*       driververif.H
*
* @param[in] i_target - Target device associated w/ the EEPROM.
*
* @param[in/out] io_buffer
*       INPUT: Pointer to the data that will be  written to the target
*           device.
*       OUTPUT: Pointer to the data that was read from the target device.
*
* @param[in] i_buflen
*       INPUT: Length of the buffer to be written to target device or
*       length of buffer to be read from target device.
*
* @param [in] i_eepromInfo struct containing information needed to perform
*        operation on the given i2c eeprom. NOTE It is expected that
*        eepromRole and offset have been filled out in this struct
*        prior to passing it into this function
*
* @return errlHndl_t - nullptr if successful, otherwise a pointer to the
*       error log.
*
*/
errlHndl_t eepromPerformOpCache(DeviceFW::OperationType i_opType,
                                TARGETING::Target * i_target,
                                void * io_buffer,
                                size_t i_buflen,
                                eeprom_addr_t &i_eepromInfo);

/**
*
* @brief Build up a struct that is used to compare cached eeprom entries
*        in the EECACHE section. Each eeprom will get an entry in the
*        eepromRecordHeader order in the EECACHE section header
*
* @param[in] i_target - Target device associated w/ the EEPROM.
*
* @param [in/out] io_eepromInfo struct containing information needed to perform
*        operation on the given i2c eeprom. NOTE It is expected that
*        eepromRole has been filled out in this struct prior to passing
*        it into this function
* @param [out] o_eepromRecordHeader struct that will be populated with infromation
*        that can be used to determine if the eeprom has been cached yet or not,
*        or for looking up an eeprom we want to write to/ read from.
*
* @pre  It is expected that io_i2cInfo.eepromRole will have a valid role set
*
* @post After function o_eepromRecordHeader will be filled in with information
*       found while looking up the eeprom info from the target's attributes.
*       o_eepromRecordHeader can be used to see if a cached copy exists
*
* @return errlHndl_t - nullptr if successful, otherwise a pointer to the
*       error log.
*
*/
errlHndl_t buildEepromRecordHeader(TARGETING::Target * i_target,
                                    eeprom_addr_t & io_eepromInfo,
                                    eepromRecordHeader & o_eepromRecordHeader);

/**
*
* @brief Perform a lookup on the global map g_cachedEeproms to get a
*        virtual address for a given EEPROM
*
* @param[in] i_eepromRecordHeader
*
* @pre  It is expected that i_eepromRecordHeader has valid information for
*       the uniqueID (i2cm_huid, port, engine, devAddr, mux_select)
*
* @return uint64_t virtual address pointing to the cached eeprom data in pnor
*
*/
uint64_t lookupEepromAddr(const eepromRecordHeader & i_eepromRecordHeader);

}

#endif