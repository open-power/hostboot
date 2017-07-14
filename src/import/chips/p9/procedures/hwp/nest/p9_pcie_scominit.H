/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_pcie_scominit.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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

/// ---------------------------------------------------------------------------
///
/// @file p9_pcie_scominit.H
/// @brief Perform PCIE Phase1 init sequence (FAPI2)
///
/// *HWP HWP Owner: Ricardo Mata Jr. ricmata@us.ibm.com
/// *HWP FW Owner: Thi Tran thi@us.ibm.com
/// *HWP Team: Nest
/// *HWP Level: 3
/// *HWP Consumed by: HB
/// ---------------------------------------------------------------------------
#ifndef _P9_PCIE_SCOMINIT_H_
#define _P9_PCIE_SCOMINIT_H_

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <fapi2.H>

//-----------------------------------------------------------------------------------
// Helper Macros
//-----------------------------------------------------------------------------------
#define SET_REG_RMW_WITH_SINGLE_ATTR_8(in_attr_name, in_reg_name, in_start_bit, in_bit_count)\
    FAPI_TRY(FAPI_ATTR_GET(in_attr_name, l_pec_chiplets, l_attr_8)); \
    FAPI_TRY(fapi2::getScom(l_pec_chiplets, in_reg_name, l_buf)); \
    FAPI_TRY(l_buf.insertFromRight(l_attr_8, in_start_bit, in_bit_count)); \
    FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf()); \
    FAPI_TRY(fapi2::putScom(l_pec_chiplets, in_reg_name, l_buf));

#define SET_REG_RMW_WITH_SINGLE_ATTR_16(in_attr_name, in_reg_name, in_start_bit, in_bit_count)\
    FAPI_TRY(FAPI_ATTR_GET(in_attr_name, l_pec_chiplets, l_attr_16)); \
    FAPI_TRY(fapi2::getScom(l_pec_chiplets, in_reg_name, l_buf)); \
    FAPI_TRY(l_buf.insertFromRight(l_attr_16, in_start_bit, in_bit_count)); \
    FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf()); \
    FAPI_TRY(fapi2::putScom(l_pec_chiplets, in_reg_name, l_buf));

#define SET_REG_WR_WITH_SINGLE_ATTR_16(in_attr_name, in_reg_name, in_start_bit, in_bit_count)\
    l_buf = 0; \
    FAPI_TRY(FAPI_ATTR_GET(in_attr_name, l_pec_chiplets, l_attr_16)); \
    FAPI_TRY(l_buf.insertFromRight(l_attr_16, in_start_bit, in_bit_count)); \
    FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf()); \
    FAPI_TRY(fapi2::putScom(l_pec_chiplets, in_reg_name, l_buf));

#define SET_REG_RMW(in_value, in_reg_name, in_start_bit, in_bit_count)\
    FAPI_TRY(fapi2::getScom(l_pec_chiplets, in_reg_name, l_buf)); \
    FAPI_TRY(l_buf.insertFromRight(in_value, in_start_bit, in_bit_count)); \
    FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf()); \
    FAPI_TRY(fapi2::putScom(l_pec_chiplets, in_reg_name, l_buf));

#define SET_REG_WR(in_value, in_reg_name, in_start_bit, in_bit_count)\
    FAPI_TRY(l_buf.insertFromRight(in_value, in_start_bit, in_bit_count)); \
    FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf()); \
    FAPI_TRY(fapi2::putScom(l_pec_chiplets, in_reg_name, l_buf));

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------
//function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pcie_scominit_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

extern "C" {

//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------

/// @brief Perform PCIE Phase1 init sequence
/// @param[in] i_target => P9 chip target
/// @return FAPI_RC_SUCCESS if the setup completes successfully,
//
    fapi2::ReturnCode p9_pcie_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} //extern"C"

#endif //_P9_PCIE_SCOMINIT_H_
