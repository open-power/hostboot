/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scan/scandd.H $                                       */
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
#ifndef __SCAN_H
#define __SCAN_H

/**
 * @file scandd.H
 *
 * @brief Provides the interfaces for the scan device driver
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <errl/errlentry.H>
#include <sbeio/sbe_psudd.H>

namespace SCANDD
{

 const uint32_t HEADER_CHECK_DATA = 0xdeadbeef;

// ------------------------------------------------------------------
// scanPerformOp
// ------------------------------------------------------------------
errlHndl_t scanPerformOp( DeviceFW::OperationType i_opType,
                          TARGETING::Target * i_target,
                          void * io_buffer,
                          size_t & io_buflen,
                          int64_t i_accessType,
                          va_list i_args );


/// @brief sends Put Ring from Image message to SBE via scan interface
/// @param[in] i_target  target includes the target type that is needed
/// @param[in] va_list i_args contains:  ringID, RingMode, flags
/// @return errlHndl_t  returns non-zero value if there is error.
errlHndl_t sbeScanPerformOp( TARGETING::Target * i_target, va_list i_args );

errlHndl_t scanDoScan(    DeviceFW::OperationType i_opType,
                          TARGETING::Target * i_target,
                          void * io_buffer,
                          size_t & io_buflen,
                          uint64_t i_ring,
                          uint64_t i_ringlength,
                          uint64_t i_flag );

/// @brief translates HB target types to SBE target type groups
/// @param[in] i_hbTarget includes the HB target type
/// @return SBEIO::SBE_TARGET_TYPES returns SBE_TARGET_TYPE_UNKNOWN in error
SBEIO::SBE_TARGET_TYPES
    translateToSBETargetType(TARGETING::Target * i_hbTarget);

/// @brief returns a ChipletID for a give target
/// @param[in] i_hbTarget includes the HB target type
/// @return: ChipletID for i_hbTarget target
uint8_t getChipletIDForSBE(TARGETING::Target * i_hbTarget);


}; // end SCAN namespace

#endif  // __SCAN_H
