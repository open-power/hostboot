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

enum P10_CLOCK_TEST_Private_Constants
{
    HW_NS_DELAY = 20, // unit is nano seconds
    SIM_CYCLE_DELAY = 1000, // unit is sim cycles
    POLL_COUNT = 10
};

static fapi2::ReturnCode p10_clock_test_latches(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    bool set_rcs_clock_test_in);

fapi2::ReturnCode p10_clock_test(const
                                 fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    using namespace scomt;
    using namespace scomt::perv;

    fapi2::buffer<uint32_t> l_data32;

    FAPI_INF("p10_clock_test: Entering ...");

    FAPI_DBG("unfence input wires to register 2810");
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, l_data32));
    l_data32.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, l_data32));

    FAPI_DBG("unfence input wires to register 2910");
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI, l_data32));
    l_data32.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI, l_data32));


    for(int i = 0; i < POLL_COUNT; i++)
    {
        FAPI_DBG("Set input valuse to clock test latches - RCS_CLOCK_TEST_IN = 1");
        FAPI_TRY(p10_clock_test_latches(i_target_chip, true));

        FAPI_DBG("Set input valuse to clock test latches - RCS_CLOCK_TEST_IN = 0");
        FAPI_TRY(p10_clock_test_latches(i_target_chip, false));
    }

    FAPI_INF("p10_clock_test: Exiting ...");

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
    bool set_rcs_clock_test_in)
{
    using namespace scomt;
    using namespace scomt::perv;

    fapi2::buffer<uint32_t> l_data32;
    uint8_t l_cp_refclck_select;
    bool check_clockA;
    bool check_clockB;

    FAPI_INF("p10_clock_test_latches: Entering ...");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CP_REFCLOCK_SELECT, i_target_chip, l_cp_refclck_select),
             "Error from FAPI_ATTR_GET (ATTR_CP_REFCLOCK_SELECT)");

    l_data32.flush<0>().setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip,
                                    set_rcs_clock_test_in ? FSXCOMP_FSXLOG_ROOT_CTRL5_SET_FSI : FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI,
                                    l_data32));

    fapi2::delay(HW_NS_DELAY, SIM_CYCLE_DELAY);

    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, FSXCOMP_FSXLOG_SNS1LTH_FSI,
                                    l_data32));

    check_clockA = set_rcs_clock_test_in ? (l_data32.getBit<4>() == 1) : (l_data32.getBit<4>() == 0) ;
    check_clockB = set_rcs_clock_test_in ? (l_data32.getBit<5>() == 1) : (l_data32.getBit<5>() == 0) ;

    if (! (l_cp_refclck_select == fapi2::ENUM_ATTR_CP_REFCLOCK_SELECT_OSC1))
    {
        FAPI_ASSERT(check_clockA,
                    fapi2::CLOCK_TEST_OUT_RCS_ERR()
                    .set_READ_SNS1LTH(l_data32)
                    .set_ATTR_CP_REFCLOCK_SELECT_VALUE(l_cp_refclck_select)
                    .set_RCS_CLOCK_TEST_IN(set_rcs_clock_test_in),
                    "Clock A is bad");
    }

    if (! (l_cp_refclck_select == fapi2::ENUM_ATTR_CP_REFCLOCK_SELECT_OSC0))
    {
        FAPI_ASSERT(check_clockB,
                    fapi2::CLOCK_TEST_OUT_RCS_ERR()
                    .set_READ_SNS1LTH(l_data32)
                    .set_ATTR_CP_REFCLOCK_SELECT_VALUE(l_cp_refclck_select)
                    .set_RCS_CLOCK_TEST_IN(set_rcs_clock_test_in),
                    "Clock B is bad");
    }

    FAPI_INF("p10_clock_test_latches: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
