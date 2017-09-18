/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scan/scandd.H $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
#include <sbeio/sbe_utils.H>
#include <p9_ring_id.h>
#include <hw_access_def.H>

namespace SCANDD
{

 const uint32_t HEADER_CHECK_DATA = 0xdeadbeef;

/**
 * @brief High-level device driver interface for all scan
 *     operations
 * <see deviceOp_t for parms>
 */
errlHndl_t scanPerformOp( DeviceFW::OperationType i_opType,
                          TARGETING::Target * i_target,
                          void * io_buffer,
                          size_t & io_buflen,
                          int64_t i_accessType,
                          va_list i_args );

/**
 * @brief Sends Put Ring from Image message to SBE via PSU
 * @param[in]  i_target  Target chip/unit to scan
 * @param[in]  i_ring    Ring modifier/id
 * @param[in]  i_ringlength  Length of ring in bits
 * @return errlHndl_t  returns non-zero value if there is error.
*/
errlHndl_t sbeScanPerformOp( TARGETING::Target * i_target,
                             RingId_t i_ringID,
                             fapi2::RingMode i_ringMode );

/**
 * @brief Perform a scan operation using the pib
 *
 * @param[in]  i_opType  Read/write
 * @param[in]  i_target  Target chip to scan
 * @param[out] o_buffer  Output buffer, allocated by caller
 * @param[inout] io_buflen In: Size of output buffer in bytes
 *                       Out: Number of bytes read/written
 * @param[in]  i_ring    Ring modifier/id
 * @param[in]  i_ringlength  Length of ring in bits
 * @param[in]  i_flags   Flags to affect the scan operation
 * @return Error handle, NULL on success
 */
errlHndl_t scanDoPibScan( DeviceFW::OperationType i_opType,
                          TARGETING::Target * i_target,
                          void* o_buffer,
                          size_t & io_buflen,
                          uint64_t i_ring,
                          uint64_t i_ringlength,
                          uint64_t i_flags );


}; // end SCAN namespace

#endif  // __SCAN_H
