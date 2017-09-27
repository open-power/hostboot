/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_set_fsi_gp_shadow.C $ */
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
//------------------------------------------------------------------------------
/// @file  p9_set_fsi_gp_shadow.C
///
/// @brief --IPL step 0.8 proc_prep_ipl
//------------------------------------------------------------------------------
// *HWP HW Owner        : Anusha Reddy Rangareddygari <anusrang@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Brian Silver <bsilver@us.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 3
// *HWP Consumed by     : SBE
//------------------------------------------------------------------------------


//## auto_generated
#include "p9_set_fsi_gp_shadow.H"
//## auto_generated
#include "p9_const_common.H"

#include <p9_perv_scom_addresses.H>
#include <p9n2_perv_scom_addresses_fld.H>


fapi2::ReturnCode p9_set_fsi_gp_shadow(const
                                       fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    fapi2::buffer<uint8_t> l_read_attr;
    fapi2::buffer<uint32_t> l_cfam_data;
    FAPI_INF("p9_set_fsi_gp_shadow: Entering ...");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_FSI_GP_SHADOWS_OVERWRITE, i_target_chip,
                           l_read_attr));

    if ( l_read_attr )
    {
        FAPI_DBG("Setting flush values for root_ctrl_copy and perv_ctrl_copy registers");
        //Setting ROOT_CTRL0_COPY register value
        //CFAM.ROOT_CTRL0_COPY = p9SetFsiGpShadow::ROOT_CTRL0_FLUSHVALUE
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL0_COPY_FSI,
                                        p9SetFsiGpShadow::ROOT_CTRL0_FLUSHVALUE));

        //Setting ROOT_CTRL1_COPY register value
        //CFAM.ROOT_CTRL1_COPY = p9SetFsiGpShadow::ROOT_CTRL1_FLUSHVALUE
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL1_COPY_FSI,
                                        p9SetFsiGpShadow::ROOT_CTRL1_FLUSHVALUE));

        //Setting ROOT_CTRL2_COPY register value
        //CFAM.ROOT_CTRL2_COPY = p9SetFsiGpShadow::ROOT_CTRL2_FLUSHVALUE
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL2_COPY_FSI,
                                        p9SetFsiGpShadow::ROOT_CTRL2_FLUSHVALUE));

        //Setting ROOT_CTRL3_COPY register value
        //CFAM.ROOT_CTRL3_COPY = p9SetFsiGpShadow::ROOT_CTRL3_FLUSHVALUE
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL3_COPY_FSI,
                                        p9SetFsiGpShadow::ROOT_CTRL3_FLUSHVALUE));

        //Setting ROOT_CTRL4_COPY register value
        //CFAM.ROOT_CTRL4_COPY = p9SetFsiGpShadow::ROOT_CTRL4_FLUSHVALUE
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL4_COPY_FSI,
                                        p9SetFsiGpShadow::ROOT_CTRL4_FLUSHVALUE));

        //Setting ROOT_CTRL5_COPY register value
        //CFAM.ROOT_CTRL5_COPY = p9SetFsiGpShadow::ROOT_CTRL5_FLUSHVALUE
        FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_ROOT_CTRL5_COPY_FSI,
                                        l_cfam_data));
        l_cfam_data = (l_cfam_data & p9SetFsiGpShadow::ROOT_CTRL5_MASK) |
                      p9SetFsiGpShadow::ROOT_CTRL5_FLUSHVALUE;
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL5_COPY_FSI,
                                        l_cfam_data));

        //Setting ROOT_CTRL6_COPY register value
        //CFAM.ROOT_CTRL6_COPY = p9SetFsiGpShadow::ROOT_CTRL6_FLUSHVALUE
        FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_ROOT_CTRL6_COPY_FSI,
                                        l_cfam_data));
        l_cfam_data = (l_cfam_data & p9SetFsiGpShadow::ROOT_CTRL6_MASK) |
                      p9SetFsiGpShadow::ROOT_CTRL6_FLUSHVALUE;
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL6_COPY_FSI,
                                        l_cfam_data));

        //Setting ROOT_CTRL7_COPY register value
        //CFAM.ROOT_CTRL7_COPY = p9SetFsiGpShadow::ROOT_CTRL7_FLUSHVALUE
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL7_COPY_FSI,
                                        p9SetFsiGpShadow::ROOT_CTRL7_FLUSHVALUE));

        //Setting ROOT_CTRL8_COPY register value
        //CFAM.ROOT_CTRL8_COPY = p9SetFsiGpShadow::ROOT_CTRL8_FLUSHVALUE
        FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_ROOT_CTRL8_COPY_FSI,
                                        l_cfam_data));
        l_cfam_data = (l_cfam_data & p9SetFsiGpShadow::ROOT_CTRL8_MASK) |
                      p9SetFsiGpShadow::ROOT_CTRL8_FLUSHVALUE;
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL8_COPY_FSI,
                                        l_cfam_data));

        //Setting PERV_CTRL0_COPY register value
        //CFAM.PERV_CTRL0_COPY = p9SetFsiGpShadow::PERV_CTRL0_FLUSHVALUE
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_PERV_CTRL0_COPY_FSI,
                                        p9SetFsiGpShadow::PERV_CTRL0_FLUSHVALUE));

        //Setting PERV_CTRL1_COPY register value
        //CFAM.PERV_CTRL1_COPY = p9SetFsiGpShadow::PERV_CTRL1_FLUSHVALUE
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_PERV_CTRL1_COPY_FSI,
                                        p9SetFsiGpShadow::PERV_CTRL1_FLUSHVALUE));
    }

    /* Write the value of FUSED_CORE_MODE into PERV_CTRL0(23) regardless of chip EC; the bit is nonfunctional on Nimbus DD1 */
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUSED_CORE_MODE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_read_attr));
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_PERV_CTRL0_COPY_FSI, l_cfam_data));

    if (l_read_attr)
    {
        l_cfam_data.setBit<P9N2_PERV_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE>();
    }
    else
    {
        l_cfam_data.clearBit<P9N2_PERV_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE>();
    }

    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_PERV_CTRL0_COPY_FSI, l_cfam_data));

    FAPI_INF("p9_set_fsi_gp_shadow: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
