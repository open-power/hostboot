/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_set_fsi_gp_shadow.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
#include "p10_scom_perv_0.H"
#include "p10_scom_perv_1.H"
#include "p10_scom_perv_2.H"
#include "p10_scom_perv_3.H"
#include "p10_scom_perv_4.H"
#include "p10_scom_perv_5.H"
#include "p10_scom_perv_6.H"
#include "p10_scom_perv_8.H"
#include "p10_scom_perv_9.H"
#include "p10_scom_perv_c.H"
#include "p10_scom_perv_d.H"
#include "p10_scom_perv_e.H"

using namespace scomt;
using namespace scomt::perv;

struct
{
    uint32_t reg_addr, reg_copy_addr, value;
} P10_SET_FSI_GP_SHADOW_GPREG_INITVALUES[] =
{

    { FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI, 0x80FF6007},
    { FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI, 0x00180020},
    { FSXCOMP_FSXLOG_ROOT_CTRL2_FSI, FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI, 0x04000000},
    { FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_COPY_FSI, 0xEFEEEEFF},
    { FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI, 0x00000000},
    { FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI, 0x7C022020},
    { FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI, 0x60000000}
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
