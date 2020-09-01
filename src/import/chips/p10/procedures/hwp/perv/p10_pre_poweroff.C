/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_pre_poweroff.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// @file  p10_pre_poweroff.C
///
/// @brief Raises the fences
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
// *HWP Consumed by     : FSP
//------------------------------------------------------------------------------


#include "p10_pre_poweroff.H"
#include "p10_scom_perv.H"

enum P10_PRE_POWEROFF_Private_Constants
{
    HW_NS_DELAY = 200, // unit is nano seconds
    SIM_CYCLE_DELAY = 100000 // unit is sim cycles
};

fapi2::ReturnCode p10_pre_poweroff(const
                                   fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    using namespace scomt::perv;

    fapi2::buffer<uint32_t> l_read_reg_rc0, l_read_reg_pc0, l_read_reg_rc1, l_read_reg_rc7;

    FAPI_INF("p10_pre_poweroff : Entering ...");

    FAPI_DBG("Assert all PERST# outputs");
    l_read_reg_rc1.flush<0>().setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_FSI,
                                    l_read_reg_rc1));

    FAPI_DBG("Assert OCMB reset");
    l_read_reg_rc0.flush<0>().setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_SET_FSI,
                                    l_read_reg_rc0));

    // wait 1ms
    fapi2::delay(HW_NS_DELAY, SIM_CYCLE_DELAY);

    FAPI_DBG("Raise pervasive chiplet fence and endpoint reset");
    l_read_reg_pc0.flush<0>()
    .setBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC>()
    .setBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI,
                                    l_read_reg_pc0));

    // RC0 bit0: cfam protection 0, bit8: cfam protection 1, bit9: cfam protection 2
    FAPI_DBG("Raise Cfam protection");
    l_read_reg_rc0.flush<0>()
    .setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC>()
    .setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC>()
    .setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC>()
    .setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC>()
    .setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE>()
    .setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE>()
    .setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE>()
    .setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_SET_FSI,
                                    l_read_reg_rc0));

    FAPI_DBG("Set global endpoint reset");
    l_read_reg_rc0.flush<0>().setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_SET_FSI,
                                    l_read_reg_rc0));

    FAPI_DBG("Turn off all outgoing refclocks");
    l_read_reg_rc7.flush<0>().setBit<0, 28>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI,
                                    l_read_reg_rc7));

    FAPI_DBG("Disable TP drivers and receivers");
    l_read_reg_rc1.flush<0>()
    .setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B>()
    .setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B>()
    .setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B>()
    .setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_FSI,
                                    l_read_reg_rc1));

    FAPI_DBG("Clear FSI I2C fence to allow access from FSP side");
    l_read_reg_rc0.flush<0>().setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI,
                                    l_read_reg_rc0));

    FAPI_INF("p10_pre_poweroff : Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
