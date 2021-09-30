/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_clock_test.C $   */
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
//------------------------------------------------------------------------------
/// @file  p10_clock_test.C
///
/// @brief Test to see if the ref clock is valid.
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
// *HWP Consumed by     : FSP
//------------------------------------------------------------------------------

#include "p10_clock_test.H"
#include "p10_scom_perv_0.H"
#include "p10_scom_perv_2.H"
#include "p10_scom_perv_d.H"
#include "p10_scom_perv_f.H"
#include "p10_scom_perv_7.H"
#include "p10_clock_test_cmn.H"

enum P10_CLOCK_TEST_Private_Constants
{
    HW_NS_DELAY = 20, // unit is nano seconds
    SIM_CYCLE_DELAY = 1000, // unit is sim cycles
    POLL_COUNT = 10
};

static fapi2::ReturnCode p10_clock_test_latches(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    const uint8_t i_cp_refclock_select,
    bool set_rcs_clock_test_in);

fapi2::ReturnCode p10_clock_test(const
                                 fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    using namespace scomt;
    using namespace scomt::perv;

    fapi2::buffer<uint32_t> l_root_ctrl0;
    fapi2::buffer<uint32_t> l_root_ctrl0_copy;
    fapi2::buffer<uint32_t> l_root_ctrl6;

    fapi2::ATTR_CHIP_EC_FEATURE_HW543822_Type l_hw543822;
    fapi2::ATTR_HW543822_WAR_MODE_Type l_hw543822_war_mode;
    fapi2::ATTR_CP_REFCLOCK_SELECT_Type l_cp_refclck_select;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    FAPI_INF("p10_clock_test: Entering ...");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CP_REFCLOCK_SELECT, i_target_chip, l_cp_refclck_select));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW543822, i_target_chip, l_hw543822));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HW543822_WAR_MODE, FAPI_SYSTEM, l_hw543822_war_mode));

    if ((l_hw543822 != 0) &&
        (l_hw543822_war_mode != fapi2::ENUM_ATTR_HW543822_WAR_MODE_NONE))
    {
        fapi2::buffer<uint32_t> l_root_ctrl6_temp;
        // set sys0/sys1 refclock termination to 50ohm to ground when running clock test
        FAPI_TRY(fapi2::getCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, l_root_ctrl6));
        l_root_ctrl6_temp = l_root_ctrl6;

        l_root_ctrl6_temp.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM,
                                          FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM_LEN>(l_hw543822_war_mode);
        l_root_ctrl6_temp.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM,
                                          FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM_LEN>(l_hw543822_war_mode);

        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, l_root_ctrl6_temp));
    }

    FAPI_DBG("unfence input wires to register 2810");
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, l_root_ctrl0));
    l_root_ctrl0.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, l_root_ctrl0));

    FAPI_DBG("unfence input wires to register 2910");
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI, l_root_ctrl0_copy));
    l_root_ctrl0_copy.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI, l_root_ctrl0_copy));

    FAPI_TRY(p10_clock_test_loop(i_target_chip, l_cp_refclck_select));

    if ((l_hw543822 != 0) &&
        (l_hw543822_war_mode != fapi2::ENUM_ATTR_HW543822_WAR_MODE_NONE))
    {
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, l_root_ctrl6));
    }

    FAPI_INF("p10_clock_test: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief run the clock test loop using p10_clock_test_latches
///
/// @param[in]     i_target_chip   Reference to TARGET_TYPE_PROC_CHIP target
/// @param[in]     i_cp_refclock_select     input indicating which all clock has to be tested
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_clock_test_loop(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    const uint8_t i_cp_refclock_select)
{
    for(int i = 0; i < POLL_COUNT; i++)
    {
        FAPI_DBG("Set input value to clock test latches - RCS_CLOCK_TEST_IN = 1");
        FAPI_TRY(p10_clock_test_latches(i_target_chip, i_cp_refclock_select, true));

        FAPI_DBG("Set input value to clock test latches - RCS_CLOCK_TEST_IN = 0");
        FAPI_TRY(p10_clock_test_latches(i_target_chip, i_cp_refclock_select, false));
    }

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Verify that latches clocked by input clocks transported input value to output
///
/// @param[in]     i_target_chip   Reference to TARGET_TYPE_PROC_CHIP target
/// @param[in]     bool        RCS_CLOCK_TEST_IN
/// @return  FAPI2_RC_SUCCESS if success, else error code.
static fapi2::ReturnCode p10_clock_test_latches(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    const uint8_t i_cp_refclock_select,
    const bool set_rcs_clock_test_in)
{
    using namespace scomt;
    using namespace scomt::perv;

    fapi2::buffer<uint32_t> l_data32;

    l_data32.flush<0>().setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip,
                                    set_rcs_clock_test_in ? FSXCOMP_FSXLOG_ROOT_CTRL5_SET_FSI :
                                    FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI,
                                    l_data32));

    fapi2::delay(HW_NS_DELAY, SIM_CYCLE_DELAY);

    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, FSXCOMP_FSXLOG_SNS1LTH_FSI, l_data32));
    FAPI_TRY(p10_clock_test_check_error(i_target_chip, i_cp_refclock_select, set_rcs_clock_test_in, l_data32));

fapi_try_exit:
    return fapi2::current_err;
}
