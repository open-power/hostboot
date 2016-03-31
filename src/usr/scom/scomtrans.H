/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/scomtrans.H $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
#ifndef __SCOMTRANS_H
#define __SCOMTRANS_H

#include <devicefw/driverif.H>
#include <p9_cu.H>

/** @file  scomtrans.H
 *  @brief Provides the interfaces to perform a SCom
 */

namespace SCOM
{
/**
 * @brief Performs translates the scom, handles indirect and does scom
 * This function performs the translation and get the
 * correct target and continues the scom Operation.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        SCom target
 * @param[in/out] io_buffer     Read: pointer to output data storage
 *                              Write: pointer to data to be written
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output: Read: size of output data
 *                                      Write: size of data written
 * @param[in]   i_accessType    Select from DeviceFW::AccessType enum
 *                              (usrif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              which is the SCom address value.
 */
errlHndl_t startScomProcess(DeviceFW::OperationType i_opType,
                  TARGETING::Target* i_target,
                  void* io_buffer,
                  size_t& io_buflen,
                  int64_t i_accessType,
                  va_list i_args);

/**
 * @brief Performs a SCom Translation of the scom address
 * This function performs the translation and gets the
 * correct target.
 *
 * @param[in]           i_target         SCom target
 * @param[in|out]       io_addr          SCom address
 * @param[in|out]       io_target_SW     target for SW
 * @param[in]           i_opMode         Defaults to 0 (Standard)
 * @return              errlHndl_t
 */
errlHndl_t scomTranslate(TARGETING::Target * &i_target,
                        uint64_t & io_addr,
                        TARGETING::Target * io_target_SW,
                        uint64_t i_opMode = 0);

/**
 * @brief This function translates a scom address using the
 *        the interface that the HW team provided.
 *
 * @param[in]      i_target      SCom target is passed in
 * @param[in]      i_type        Type of the target
 * @param[in|out]  io_addr       Address to be translated
 * @param[in|out]  io_target_SW  SW target for HBRT
 * @param[in]      i_opMode      Defaults to 0 (Standard)
 * @return         errlHndl_t
 */
errlHndl_t p9_translation (TARGETING::Target * &i_target,
                          TARGETING::TYPE i_type,
                           uint64_t &io_addr,
                           TARGETING::Target * io_target_SW,
                           uint64_t i_opMode = 0);

/**
 * @brief This function translates a scom address using the
 *        the interface that the HW team provided.
 *
 * @param[in]      i_type        Type of the target
 * @param[out]     o_chipUnit    Chip unit related to target type
 * @return         bool          True if there was an error trying to find
 *                               a chipUnit related to the inputed target type
 */
bool getChipUnit (TARGETING::TYPE i_type,
                       p9ChipUnits_t &o_chipUnit);



}; // End namespace

#endif
