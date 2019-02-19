/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_adu_access.H $   */
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
///
/// @file p10_adu_access.H
/// @brief Read coherent state of memory via the adu
///
/// The purpose of this procedure is to perform a coherent read from
/// system memory via fabric commands issued from the Alter/Display Unit (ADU).
///
/// Successful operation assumes that:
/// - System clocks are running
/// - Fabric is initialized
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: SBE
///

#ifndef _P10_ADU_ACCESS_H_
#define _P10_ADU_ACCESS_H_

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_adu_constants.H>

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_adu_access_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const uint64_t,
    const bool,
    const uint32_t,
    const bool,
    const bool,
    uint8_t[]);

//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Execute the read/write operation from the adu
///
/// @param[in] i_target        Reference to processor chip target
/// @param[in] i_address       Base real address for read/write operation (expected to be 8B aligned)
/// @param[in] i_rnw           True if the operation is read not write (1 for read, 0 for write)
/// @param[in] i_flags         Other information that is needed, see the p10_adu_constants adu_flags enums for bit definitions
///                            Note: The adu_operationFlag class can be used to construct the flag
/// @param[in] i_firstGranule  True if this is the first 8B of data that we are collecting (true=firstGranule, false=notFirstGranule)
/// @param[in] i_lastGranule   True if this is the last 8B of data that we are collecting (true=lastGranule, false=notLastGranule)
/// @param[in, out] io_data    Data that is read/written
///
/// @return FAPI_RC_SUCCESS if the read/write completes successfully, else error code.
///
    fapi2::ReturnCode p10_adu_access(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_address,
        const bool i_rnw,
        const uint32_t i_flags,
        const bool i_firstGranule,
        const bool i_lastGranule,
        uint8_t io_data[]);

} //extern "C"

#endif //_P10_ADU_ACCESS_H_
