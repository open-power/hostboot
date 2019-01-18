/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_set_fsi_gp_shadow.C $ */
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
/// @file p10_set_fsi_gp_shadow.C
/// @brief Setup initial values for RC and RC_copy registers
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
// *HWP Consumed by     : FSP
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_set_fsi_gp_shadow.H>
#include <p9_perv_scom_addresses.H>

struct
{
    uint32_t reg_addr, reg_copy_addr, value;
} P10_SET_FSI_GP_SHADOW_GPREG_INITVALUES[] =
{
    { PERV_ROOT_CTRL0_FSI, PERV_ROOT_CTRL0_COPY_FSI, 0x80FF5003},
    { PERV_ROOT_CTRL1_FSI, PERV_ROOT_CTRL1_COPY_FSI, 0x00180000},
    { PERV_ROOT_CTRL2_FSI, PERV_ROOT_CTRL2_COPY_FSI, 0x04000000},
    { PERV_ROOT_CTRL3_FSI, PERV_ROOT_CTRL3_COPY_FSI, 0xEEEEEEEE},
    { PERV_ROOT_CTRL7_FSI, PERV_ROOT_CTRL7_COPY_FSI, 0x00000000},
    { PERV_ROOT_CTRL8_FSI, PERV_ROOT_CTRL8_COPY_FSI, 0x00000000},
    { PERV_PERV_CTRL0_FSI, PERV_PERV_CTRL0_COPY_FSI, 0x7C062020},
    { PERV_PERV_CTRL1_FSI, PERV_PERV_CTRL1_COPY_FSI, 0x63C00000}
};

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_set_fsi_gp_shadow(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{

    FAPI_INF("p10_set_fsi_gp_shadow: Entering");

    for (auto rc : P10_SET_FSI_GP_SHADOW_GPREG_INITVALUES)
    {
        fapi2::buffer<uint32_t> l_data = rc.value;
        FAPI_TRY(fapi2::putCfamRegister(i_target, rc.reg_addr, l_data));
        FAPI_TRY(fapi2::putCfamRegister(i_target, rc.reg_copy_addr, l_data));
    }

    FAPI_INF("p10_set_fsi_gp_shadow: Exiting");

fapi_try_exit:
    return fapi2::current_err;
}
