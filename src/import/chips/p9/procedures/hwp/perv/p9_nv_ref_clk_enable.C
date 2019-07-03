/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_nv_ref_clk_enable.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
/// @file p9_nv_ref_clk_enable.C
/// @brief Enable NV reference clocks (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Perv
// *HWP Level: 3
// *HWP Consumed by: HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_nv_ref_clk_enable.H>
#include <p9_perv_scom_addresses.H>
#include <p9_perv_scom_addresses_fld.H>
#include <p9a_perv_scom_addresses.H>
#include <p9a_perv_scom_addresses_fld.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint16_t TPFSI_OFFCHIP_REFCLK_EN_NV = 0xF;
// P9A_PERV_ROOT_CTRL7_TP_TPIO_NV_REFCLK_EN_DC_LEN == 6
const uint16_t P9A_NV_REFCLK_BIT_LEN = 4;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
p9_nv_ref_clk_enable(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("Start");
    fapi2::buffer<uint64_t> l_root_ctrl;
    fapi2::ATTR_CHIP_EC_FEATURE_ONE_NPU_TOP_Type l_one_npu;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_ONE_NPU_TOP, i_target, l_one_npu));

    if (l_one_npu)
    {
        FAPI_TRY(fapi2::getScom(i_target, PERV_ROOT_CTRL6_SCOM, l_root_ctrl),
                 "Error from getScom (PERV_ROOT_CTRL6_SCOM)");
        l_root_ctrl.insertFromRight<PERV_ROOT_CTRL6_TSFSI_NV_REFCLK_EN_DC,
                                    PERV_ROOT_CTRL6_TSFSI_NV_REFCLK_EN_DC_LEN>(TPFSI_OFFCHIP_REFCLK_EN_NV);
        FAPI_TRY(fapi2::putScom(i_target, PERV_ROOT_CTRL6_SCOM, l_root_ctrl),
                 "Error from putScom (PERV_ROOT_CTRL6_SCOM)");
    }
    else
    {
        FAPI_TRY(fapi2::getScom(i_target, P9A_PERV_ROOT_CTRL7_SCOM, l_root_ctrl),
                 "Error from getScom (P9A_PERV_ROOT_CTRL7_SCOM)");
        l_root_ctrl.setBit<P9A_PERV_ROOT_CTRL7_TP_TPIO_NV_REFCLK_EN_DC, P9A_NV_REFCLK_BIT_LEN>();
        FAPI_TRY(fapi2::putScom(i_target, P9A_PERV_ROOT_CTRL7_SCOM, l_root_ctrl),
                 "Error from putScom (P9A_PERV_ROOT_CTRL7_SCOM)");
    }

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}
