/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9a_get_mmio.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
//------------------------------------------------------------------------------------
//
/// @file p9a_get_mmio.H
/// @brief Implement getMMIO via ADU
//
// *HWP HWP Owner: Ben Gass bgass@us.ibm.com
// *HWP FW Owner: Daniel Crowell dcrowell@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB
//

#ifndef _P9A_GET_MMIO_H__
#define _P9A_GET_MMIO_H__

#include <fapi2.H>
#include <vector>

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9a_get_mmio_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
 const uint64_t,
 const size_t,
 std::vector<uint8_t>&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

/// @brief Reads data via mmio from the target
///
/// @param[in]  i_target     HW target to operate on.
/// @param[in]  i_mmioAddr   Address to read, relative to this Target's system
///                          MMIO address.
/// @param[in]  i_transSize  The transaction size.
/// @param[out] o_data       Buffer that holds data read from HW target.
///                          The size of the buffer determines the number of
///                          amount of bytes that are read.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p9a_get_mmio(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   const uint64_t i_mmioAddr,
                                   const size_t i_transSize,
                                   std::vector<uint8_t>& o_data);

}
#endif
