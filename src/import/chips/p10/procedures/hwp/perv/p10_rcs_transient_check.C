/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_rcs_transient_check.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
// EKB-Mirror-To: hostboot
///
/// @file p10_rcs_transient_check.C
/// @brief Transient RCS functions and constants
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ryan Miller <ryan.miller@ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------

#include <fapi2.H>
#include <vector>
#include <utils.H>
#include "p10_scom_perv_0.H"
#include "p10_scom_perv_2.H"
#include "p10_scom_perv_3.H"
#include "p10_scom_perv_8.H"
#include "p10_scom_perv_a.H"
#include "p10_scom_perv_d.H"
#include "p10_scom_perv_f.H"
#include "p10_scom_proc_5.H"
#include "p10_scom_proc_e.H"
#include <target_filters.H>
#include <p10_rcs_transient_check.H>
#include <p10_scom_iohs.H>
#include "p10_perv_sbe_cmn.H"
#include "p10_clock_test_cmn.H"

enum P10_RCS_TRANSIENT_CHECK_Private_Constants
{
    HW_NS_DELAY = 20,               // unit is nano seconds
    SIM_CYCLE_DELAY = 100000,       // unit is sim cycles
    POLL_COUNT = 10,                // number of loops for simple clock detector
    RCS_NS_DELAY = 5000000,         // unit is nano seconds (5ms)
    RCS_SIM_CYCLE_DELAY = 100       // unit is sim cycles
};

static fapi2::ReturnCode p10_sbe_rcs_setup_test_latches(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    uint8_t attr_cp_refclock_select,
    bool set_rcs_clock_test_in,
    bool& o_status);



/// @brief Check error to see if it is transient or hard error
/// @param[in] i_target_chip        chip target
/// @param[in] i_side               which side we want to check for a transient error (Aside=0, Bside=1)
/// @param[out] o_status            Status of the net (True=transient, False=hard error)
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_rcs_transient_check(const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
        const uint32_t i_side,
        bool& o_status)
{
    using namespace scomt;
    using namespace scomt::perv;
    using namespace scomt::proc;

    o_status = true;
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_data64_rc5, l_data64_rc3, l_pll_expect, l_pll_status, l_data64_rcsns;

    fapi2::Target<fapi2::TARGET_TYPE_PERV> l_tpchiplet =
        i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>(fapi2::TARGET_FILTER_TP, fapi2::TARGET_STATE_FUNCTIONAL)[0];

    // Just verify that the side passed in to check is valid
    FAPI_ASSERT(((i_side == 0) || (i_side == 1)),
                fapi2::RCS_INVALID_SIDE()
                .set_SELECTED_SIDE(i_side),
                "User selected side is not valid (%d)", i_side);


    FAPI_DBG("Begin RCS Transient Error Check");

    // SW526040
    FAPI_DBG("RCS Transient Code is Disabled. Returning Hard Fail...");
    o_status = false; // Return Hard Fail
    goto fapi_try_exit;


    // Error Recovery Step 2:  Disable ALTREFCLK on selected side
    FAPI_DBG("Disable RCS filter PLL altrefclk selects");
    FAPI_TRY(fapi2::getScom(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL3_RW, l_data64_rc3));

    if (i_side == 0)
    {
        l_data64_rc3.writeBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC>(0);
    }
    else
    {
        l_data64_rc3.writeBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC>(0);
    }

    FAPI_TRY(fapi2::putScom(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL3_RW, l_data64_rc3));

    FAPI_TRY(fapi2::delay(RCS_NS_DELAY, RCS_SIM_CYCLE_DELAY));


    // Error Recovery Step 3:  Check if dedicated RCS Filter PLL is locked
    FAPI_DBG("Check if dedicated RCS Filter PLL is locked");

    l_pll_expect.flush<0>()
    .setBit(i_side);

    FAPI_DBG("    l_pll_expect<0>: %d  l_pll_expect<1>: %d", l_pll_expect.getBit<0>(), l_pll_expect.getBit<1>());
    l_rc = p10_perv_sbe_cmn_poll_pll_lock(l_tpchiplet, l_pll_expect, true, l_pll_status);
    o_status = (l_rc != fapi2::FAPI2_RC_FALSE);

    if (l_rc == fapi2::FAPI2_RC_FALSE)
    {
        FAPI_DBG("Error from p10_perv_sbe_cmn_poll_pll_lock... FPLL failed to lock");
        goto fapi_try_exit;
    }
    else if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        FAPI_ERR("Unknown error from p10_perv_sbe_cmn_poll_pll_lock");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }


    // Error Recovery Step 4:  Check the simple clock detector
    for(int i = 0; i < POLL_COUNT; i++)
    {
        FAPI_DBG("Set input values to clock test latches - RCS_CLOCK_TEST_IN = 1");
        FAPI_TRY(p10_sbe_rcs_setup_test_latches(i_target_chip, i_side, true, o_status));

        if (!o_status)
        {
            goto fapi_try_exit;
        }

        FAPI_DBG("Set input values to clock test latches - RCS_CLOCK_TEST_IN = 0");
        FAPI_TRY(p10_sbe_rcs_setup_test_latches(i_target_chip, i_side, false, o_status));

        if (!o_status)
        {
            goto fapi_try_exit;
        }
    }

    // Error Recovery Step 5:  Clear RCS sticky errors
    FAPI_DBG("Clear RCS sticky errors");
    l_data64_rc5.flush<0>();
    FAPI_TRY(PREP_FSXCOMP_FSXLOG_ROOT_CTRL5_SET_WO_OR(i_target_chip));
    SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SET_CLEAR_CLK_ERROR_A(l_data64_rc5);
    SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SET_CLEAR_CLK_ERROR_B(l_data64_rc5);
    FAPI_TRY(PUT_FSXCOMP_FSXLOG_ROOT_CTRL5_SET_WO_OR(i_target_chip, l_data64_rc5));

    FAPI_TRY(fapi2::delay(RCS_NS_DELAY, RCS_SIM_CYCLE_DELAY));

    //Do not clear l_data64_rc5 here
    FAPI_TRY(PREP_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR(i_target_chip));
    FAPI_TRY(PUT_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR(i_target_chip, l_data64_rc5));

    FAPI_TRY(fapi2::delay(RCS_NS_DELAY, RCS_SIM_CYCLE_DELAY));


    // Error Recovery Step 6:  Check for errors
    FAPI_DBG("Check for errors");
    GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO(i_target_chip, l_data64_rcsns);

    //Check if there was a clock error
    if (i_side == 0)
    {
        o_status = !((l_data64_rcsns.getBit<6>()) || (l_data64_rcsns.getBit<7>()));
    }
    else
    {
        o_status = !((l_data64_rcsns.getBit<8>()) || (l_data64_rcsns.getBit<9>()));
    }


fapi_try_exit:
    FAPI_DBG("End RCS Transient Error Check");
    return fapi2::current_err;
}


/// @brief Verify that latches clocked by input clocks transported input value to output
///
/// @param[in]     i_target_chip   Reference to TARGET_TYPE_PROC_CHIP target
/// @param[in]     bool        RCS_CLOCK_TEST_IN
/// @return  FAPI2_RC_SUCCESS if success, else error code.
static fapi2::ReturnCode p10_sbe_rcs_setup_test_latches(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    uint8_t i_cp_refclock_select,
    bool set_rcs_clock_test_in,
    bool& o_status)
{
    using namespace scomt;
    using namespace scomt::perv;

    fapi2::buffer<uint64_t> l_data64;
    fapi2::ReturnCode l_rc;

    l_data64.flush<0>().setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC>();
    FAPI_TRY(fapi2::putScom(i_target_chip,
                            set_rcs_clock_test_in ? FSXCOMP_FSXLOG_ROOT_CTRL5_SET_WO_OR :
                            FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR,
                            l_data64));

    fapi2::delay(HW_NS_DELAY, SIM_CYCLE_DELAY);

    FAPI_DBG("Reading Sense Reg");
    FAPI_TRY(fapi2::getScom(i_target_chip, FSXCOMP_FSXLOG_SNS1LTH_RO, l_data64));

    o_status = false;

    if ((i_cp_refclock_select == 0 && l_data64.getBit<4>() == set_rcs_clock_test_in) ||
        (i_cp_refclock_select == 1 && l_data64.getBit<5>() == set_rcs_clock_test_in))
    {
        o_status = true;
    }

fapi_try_exit:
    return fapi2::current_err;

}
