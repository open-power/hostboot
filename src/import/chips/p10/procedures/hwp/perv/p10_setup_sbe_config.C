/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_setup_sbe_config.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file  p10_setup_sbe_config.C
///
/// @brief proc setup sbe config
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
// *HWP Consumed by     : FSP
//------------------------------------------------------------------------------

#include <p10_setup_sbe_config.H>
#include <p10_sbe_scratch_regs.H>
#include <p10_scom_perv.H>

// description in header
fapi2::ReturnCode p10_setup_sbe_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    using namespace scomt::perv;

    FAPI_INF("p10_setup_sbe_config::  Entering ...");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    // when running in Hostboot context, use SCOM to reach master only
    bool l_use_scom = false;

    if (fapi2::is_platform<fapi2::PLAT_HOSTBOOT>())
    {
        fapi2::ATTR_PROC_SBE_MASTER_CHIP_Type l_sbe_master_chip;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_SBE_MASTER_CHIP, i_target_chip, l_sbe_master_chip),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_SBE_MASTER_CHIP");

        l_use_scom = (l_sbe_master_chip == fapi2::ENUM_ATTR_PROC_SBE_MASTER_CHIP_TRUE);
    }
    // clear secure access bit if instructed to disable security
    else
    {
        fapi2::ATTR_SECURITY_MODE_Type l_attr_security_mode;
        fapi2::buffer<uint32_t> l_cbs_cs_reg;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SECURITY_MODE, FAPI_SYSTEM, l_attr_security_mode),
                 "Error from FAPI_ATTR_GET (ATTR_SECURITY_MODE)");

        if (!l_attr_security_mode)
        {
            // The Secure Access Bit is only writeable on DD1 chips,
            // so we won't need to put an EC level switch in here.
            FAPI_DBG("Attempting to disable security");
            FAPI_TRY(fapi2::getCfamRegister(i_target_chip,
                                            FSXCOMP_FSXLOG_CBS_CS_FSI,
                                            l_cbs_cs_reg),
                     "Error reading CBS Control/Status register");

            l_cbs_cs_reg.clearBit<FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT>();

            FAPI_TRY(fapi2::putCfamRegister(i_target_chip,
                                            FSXCOMP_FSXLOG_CBS_CS_FSI,
                                            l_cbs_cs_reg),
                     "Error writing CBS Control/Status register");
        }

    }

    // set fused mode behavior
    {
        fapi2::ATTR_FUSED_CORE_MODE_Type l_attr_fused_core_mode;
        fapi2::ATTR_CORE_LPAR_MODE_POLICY_Type l_attr_core_lpar_mode_policy;
        fapi2::ATTR_CORE_LPAR_MODE_Type l_attr_core_lpar_mode;
        fapi2::buffer<uint64_t> l_perv_ctrl0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CORE_LPAR_MODE_POLICY, FAPI_SYSTEM, l_attr_core_lpar_mode_policy),
                 "Error from FAPI_ATTR_GET (ATTR_CORE_LPAR_MODE_POLICY)");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUSED_CORE_MODE, FAPI_SYSTEM, l_attr_fused_core_mode),
                 "Error from FAPI_ATTR_GET (ATTR_FUSED_CORE_MODE)");

        if (l_attr_core_lpar_mode_policy == fapi2::ENUM_ATTR_CORE_LPAR_MODE_POLICY_FOLLOW_FUSED_STATE)
        {
            if (l_attr_fused_core_mode == fapi2::ENUM_ATTR_FUSED_CORE_MODE_CORE_FUSED)
            {
                l_attr_core_lpar_mode = fapi2::ENUM_ATTR_CORE_LPAR_MODE_LPAR_PER_CORE;
            }
            else
            {
                l_attr_core_lpar_mode = fapi2::ENUM_ATTR_CORE_LPAR_MODE_LPAR_PER_THREAD;
            }
        }
        else if (l_attr_core_lpar_mode_policy == fapi2::ENUM_ATTR_CORE_LPAR_MODE_POLICY_LPAR_PER_CORE)
        {
            l_attr_core_lpar_mode = fapi2::ENUM_ATTR_CORE_LPAR_MODE_LPAR_PER_CORE;
        }
        else
        {
            l_attr_core_lpar_mode = fapi2::ENUM_ATTR_CORE_LPAR_MODE_LPAR_PER_THREAD;
        }


        if (l_use_scom)
        {
            FAPI_TRY(fapi2::getScom(i_target_chip,
                                    FSXCOMP_FSXLOG_PERV_CTRL0_RW,
                                    l_perv_ctrl0),
                     "Error reading PERV_CTRL0 (scom)");
        }
        else
        {
            fapi2::buffer<uint32_t> l_perv_ctrl0_cfam;
            FAPI_TRY(fapi2::getCfamRegister(i_target_chip,
                                            FSXCOMP_FSXLOG_PERV_CTRL0_FSI,
                                            l_perv_ctrl0_cfam),
                     "Error reading PERV_CTRL0 (cfam)");
            l_perv_ctrl0.insert<0, 32, 0>(l_perv_ctrl0_cfam);
        }

        l_perv_ctrl0.writeBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE>(
            l_attr_fused_core_mode == fapi2::ENUM_ATTR_FUSED_CORE_MODE_CORE_FUSED);
        l_perv_ctrl0.writeBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC>(
            l_attr_core_lpar_mode);

        if (l_use_scom)
        {
            FAPI_TRY(fapi2::putScom(i_target_chip,
                                    FSXCOMP_FSXLOG_PERV_CTRL0_RW,
                                    l_perv_ctrl0),
                     "Error writing PERV_CTRL0 (scom)");
        }
        else
        {
            fapi2::buffer<uint32_t> l_perv_ctrl0_cfam;
            l_perv_ctrl0_cfam.insert<0, 32, 0>(l_perv_ctrl0);
            FAPI_TRY(fapi2::putCfamRegister(i_target_chip,
                                            FSXCOMP_FSXLOG_PERV_CTRL0_FSI,
                                            l_perv_ctrl0_cfam),
                     "Error writing PERV_CTRL0 (cfam)");
        }

        // copy
        if (l_use_scom)
        {
            FAPI_TRY(fapi2::getScom(i_target_chip,
                                    FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW,
                                    l_perv_ctrl0),
                     "Error reading PERV_CTRL0_COPY (scom)");
        }
        else
        {
            fapi2::buffer<uint32_t> l_perv_ctrl0_cfam;
            FAPI_TRY(fapi2::getCfamRegister(i_target_chip,
                                            FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI,
                                            l_perv_ctrl0_cfam),
                     "Error reading PERV_CTRL0_COPY (cfam)");
            l_perv_ctrl0.insert<0, 32, 0>(l_perv_ctrl0_cfam);
        }

        l_perv_ctrl0.writeBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE>(
            l_attr_fused_core_mode == fapi2::ENUM_ATTR_FUSED_CORE_MODE_CORE_FUSED);
        l_perv_ctrl0.writeBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC>(
            l_attr_core_lpar_mode);

        if (l_use_scom)
        {
            FAPI_TRY(fapi2::putScom(i_target_chip,
                                    FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW,
                                    l_perv_ctrl0),
                     "Error writing PERV_CTRL0_COPY (scom)");
        }
        else
        {
            fapi2::buffer<uint32_t> l_perv_ctrl0_cfam;
            l_perv_ctrl0_cfam.insert<0, 32, 0>(l_perv_ctrl0);
            FAPI_TRY(fapi2::putCfamRegister(i_target_chip,
                                            FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI,
                                            l_perv_ctrl0_cfam),
                     "Error writing PERV_CTRL0_COPY (cfam)");
        }
    }

    // configure mailbox scratch registers
    {
        FAPI_TRY(p10_sbe_scratch_regs_update(i_target_chip, true, l_use_scom),
                 "Error from p10_sbe_scratch_regs_update");
    }

fapi_try_exit:
    FAPI_INF("p10_setup_sbe_config: Exiting ...");
    return fapi2::current_err;

}
