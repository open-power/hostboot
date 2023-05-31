/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemCaptureData.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2023                        */
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

#ifndef __prdfMemCaptureData_H
#define __prdfMemCaptureData_H

#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>

namespace PRDF
{

namespace MemCaptureData
{

/**
 * @brief Adds memory ECC FFDC to an SDC.
 * @param i_chip OCMB.
 * @param io_sc  Step code data struct.
 * @param i_port Target memory port.
 */
template<TARGETING::TYPE T>
void addEccData( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc,
                 uint8_t i_port );

/**
 * @brief Adds Memory ECC FFDC to an error log.
 * @note  This is intended to be used in non-normal analysis paths that do not
 *        have an SDC (i.e. Restore DRAM Repairs, IPL MNFG CE Isolation).
 * @note  The data will be limited and include things like the DRAM Repairs data
 *        but will not include stuff like the CE/UE tables, because that
 *        information is not relevant during its intended uses.
 * @param i_trgt An OCMB target
 * @param o_errl Error log.
 * @param i_port Target memory port.
 */
template<TARGETING::TYPE T>
void addEccData( TARGETING::TargetHandle_t i_trgt, errlHndl_t io_errl,
                 uint8_t i_port );

/**
 * @brief Adds a new user data section to the error log containing a MemoryMru
 *        plus extended data for extra FFDC.
 * @param i_memMru The memory mru
 * @param io_errl  Target error log.
 */
void addExtMemMruData( const MemoryMru & i_memMru, errlHndl_t io_errl );

/**
 * @brief Queries hardware for all DRAM repairs data (chip/symbol marks, DRAM
 *        spare, etc.) for the given OCMB and adds it to the capture data.
 * @param i_trgt An OCMB target.
 * @param io_cd  Capture data struct.
 * @param i_port Target memory port.
 * @note  This function will be used to capture DRAM repair data into the
 *        capture data struct. Other functions can call this function and
 *        update the error log.
 */
template<TARGETING::TYPE T>
void captureDramRepairsData( TARGETING::TargetHandle_t i_trgt,
                             CaptureData & io_cd, uint8_t i_port );

/**
 * @brief Queries the Bad DQ attributes for the content of the DRAM repairs VPD
 *        and adds it to the capture data.
 * @param i_trgt An OCMB target.
 * @param io_cd  Capture data struct.
 * @param i_port Target memory port.
 * @note  This function will be used to capture DRAM repair data into the
 *        capture data struct. Other functions can call this function and
 *        update the error log.
 */
template<TARGETING::TYPE T>
void captureDramRepairsVpd( TARGETING::TargetHandle_t i_trgt,
                            CaptureData & io_cd, uint8_t i_port );

/**
 * @brief Queries the Row Repair attributes for the content of the DRAM repairs
 *        VPD and adds it to the capture data.
 * @param i_trgt An OCMB target.
 * @param io_cd  Capture data struct.
 * @param i_port Target memory port.
 * @note  This function will be used to capture row repair data into the
 *        capture data struct. Other functions can call this function and
 *        update the error log.
 */
template<TARGETING::TYPE T>
void captureRowRepairVpd( TARGETING::TargetHandle_t i_trgt,
                          CaptureData & io_cd, uint8_t i_port );

/**
 * @brief Queries the IUE threshold variable for the IUE counts and adds them
 *        to the capture data.
 * @param i_trgt An OCMB target.
 * @param i_db The OCMB data bundle.
 * @param io_cd  Capture data struct.
 */
template<typename D>
void captureIueCounts( TARGETING::TargetHandle_t i_trgt, D i_db,
                       CaptureData & io_cd );

} // end namespace MemCaptureData

} // end namespace PRDF

#endif // __prdfMemCaptureData_H

