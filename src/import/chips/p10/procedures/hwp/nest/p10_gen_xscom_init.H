/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_gen_xscom_init.H $ */
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
/// @file p10_gen_xscom_init.H
/// @brief Generate XSCOM init for specified SCOM address given data and
///        data valid mask.  Data bit positions with zero in corresponding
///        data valid mask bit positions will be sampled from HW via SCOM.

//
// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by  : HB
//

#ifndef _P10_GEN_XSCOM_INIT_H_
#define _P10_GEN_XSCOM_INIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_scominfo.H>

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

///
/// @brief Generate XSCOM init for specified SCOM address given data and
///        data valid mask.  Data bit positions with zero in corresponding
///        data valid mask bit positions will be sampled from HW via SCOM.
///
/// @param[in]  i_target            Reference to processor chip target
/// @param[in]  i_cu_pairing        Chip unit and instance number associated
///                                 with i_scom_addr
/// @param[in]  i_scom_addr         Requested SCOM address, relative to
///                                 chip unit type in i_cu_pairing
/// @param[in]  i_data              Data to write
/// @param[in]  i_data_valid_mask   Data valid bitmask
/// @param[out] o_xscom_inits       Vector (address/data pairs) to append
///                                 required XSCOM inits
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_gen_xscom_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p10_chipUnitPairing_t i_cu_pairing,
    const uint64_t i_scom_addr,
    const uint64_t i_data,
    const uint64_t i_data_valid_mask,
    std::vector<std::pair<uint64_t, uint64_t>>& o_xscom_inits);


#endif // _P10_GEN_XSCOM_INIT_H_
