/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_phb_hv_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

///----------------------------------------------------------------------------
/// @file p10_phb_hv_utils.H
/// @brief Functions to support PHB HV Indirect access procedure (FAPI2)
///
/// *HWP HWP Owner: Ricardo Mata Jr. ricmata@us.ibm.com
/// *HWP FW Owner:
/// *HWP Team: Nest
/// *HWP Level:
/// *HWP Consumed by: FSP
/// ---------------------------------------------------------------------------
#ifndef _P10_PHB_HV_UTILS_H_
#define _P10_PHB_HV_UTILS_H_

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_phb_constants.H>

//-----------------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------------

const uint64_t PHB_PHB5_SCOM_HVIDR = 0x08010901ull;

//8B for PHB register access. 4B for Config Ops
const uint32_t PHB_HV_IND_ADDR_SIZE_8 = 0;
const uint32_t PHB_HV_IND_ADDR_SIZE_4 = 1;

//PHB HV address range definition
const uint32_t PHB_HV_MAX_ADDR = 0x1FFF;

//-----------------------------------------------------------------------------------
// Function prototypes
//-----------------------------------------------------------------------------------

/// @brief check that the ETU is out of reset for PHB HV accesses
/// @param[in] i_target  => reference for PHB target
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_phb_hv_check_etu_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target);

/// @brief check that the address is aligned and within the address range
///        allowed by the PHB HV Indirect Address logic
/// @param[in] i_target  => reference for PHB target
/// @param[in] i_address => address for the PHB HV Indirect operation
/// @param[in] i_size    => boolean flag to set the size (true: 4B; false: 8B)
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_phb_hv_check_args(
    const fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target,
    const uint32_t i_address,
    bool const i_size);

/// @brief does the setup for the PHB HV Indirect operation
/// @param[in] i_target  => reference for PHB target
/// @param[in] i_address => address for the PHB HV Indirect operation
/// @param[in] i_size    => boolean flag to set the size (true: 4B; false: 8B)
/// @return FAPI_RC_SUCCESS if setting up the phb_hv registers is a success
fapi2::ReturnCode p10_phb_hv_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target,
    const uint32_t i_address,
    bool const i_size);

/// @brief does the write for the PHB HV
/// @param[in] i_target     => reference for PHB target
/// @param[in] i_address    => address for this write
/// @param[in] i_size       => boolean flag to set the size (true: 4B; false: 8B)
/// @param[in] i_write_data => the data that is to be written to the
///                            PHB HV Indirect Data Register
/// @return FAPI_RC_SUCCESS if writing the PHB HV is a success
fapi2::ReturnCode p10_phb_hv_write(
    const fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target,
    const uint32_t i_address,
    bool const i_size,
    uint64_t& i_write_data);

/// @brief does the read for the PHB HV
/// @param[in] i_target     => reference for PHB target
/// @param[in] i_address    => address for this read
/// @param[in] i_size       => boolean flag to set the size for 4B or 8B
/// @param[out] o_read_data => the data that is read from the PHB HV
/// @return FAPI_RC_SUCCESS if reading the PHB HV is a success
fapi2::ReturnCode p10_phb_hv_read(
    const fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target,
    const uint32_t i_address,
    bool const i_size,
    uint64_t& o_read_data);

/// @brief does the clear for the PHB HV
/// @param[in] i_target => reference for PHB target
/// @return FAPI_RC_SUCCESS if clearing the PHB HV is a success
fapi2::ReturnCode p10_phb_hv_clear(
    const fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target);

#endif //_P10_PHB_HV_UTILS_H_
