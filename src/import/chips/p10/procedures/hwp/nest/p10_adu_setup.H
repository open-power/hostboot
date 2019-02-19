/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_adu_setup.H $    */
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
/// @file p10_adu_setup.H
/// @brief Setup the adu to issue powerbus commands or coherent reads/writes
///
/// The purpose of this procedure is to acquire use of the alter/display unit to
/// issue powerbus commands or coherent reads/writes and setup the necessary
/// registers for the specified operation.
///
/// When the adu is used to do reads/writes, the procedure will returned the
/// number of granules (number of 8B reads/writes) that can be done before setup
/// needs to be called again.
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: SBE
///

#ifndef _P10_ADU_SETUP_H_
#define _P10_ADU_SETUP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_adu_constants.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_adu_setup_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const uint64_t,
    const bool,
    const uint32_t,
    uint32_t&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Setup the adu to issue powerbus commands or coherent reads/writes
///
/// @param[in] i_target        Reference to processor chip target
/// @param[in] i_address       Base real address for read/write operation (expected to be 8B aligned)
/// @param[in] i_rnw           True if the operation is read not write (1 for read, 0 for write)
/// @param[in] i_flags         Other information that is needed; see the p10_adu_constants adu_flags enums for bit definitions
///                            Note: The adu_operationFlag class can be used to construct the flag
/// @param[out] o_numGranules  Number of 8B granules that can be read/written before setup needs to be called again
///
/// @return FAPI_RC_SUCCESS if the setup completes successfully, else error code.
///
    fapi2::ReturnCode p10_adu_setup(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_address,
        const bool i_rnw,
        const uint32_t i_flags,
        uint32_t& o_numGranules);

} //extern "C"

#endif //_P10_ADU_SETUP_H_
