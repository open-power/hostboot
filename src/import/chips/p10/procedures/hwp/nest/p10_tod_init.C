/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_tod_init.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
//
// @file p10_tod_init.C
// @brief Procedures to initialize the TOD to 'running' state
//
// *HWP HW Maintainer    : Douglas Holtsinger <Douglas.Holtsinger@ibm.com>
// *HWP FW Maintainer    : Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by      : HB,FSP
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_tod_init.H>
#include <p10_scom_perv.H>

//------------------------------------------------------------------------------
// Namespace declarations
//------------------------------------------------------------------------------

using namespace scomt;
using namespace scomt::perv;

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// in TOD counts; needs to account for SCOM latency and number of chips to be
// started in sync
const uint64_t  C_SSCG_START_DELAY      = 0x100000;
// 31.25 rounded up
const uint64_t  C_SSCG_NS_PER_TOD_COUNT = 32;
const uint32_t  C_SSCG_START_POLL_DELAY = C_SSCG_START_DELAY * C_SSCG_NS_PER_TOD_COUNT;
const uint32_t  C_SSCG_START_POLL_COUNT = 10;

// FIXME @RTC 213485 -- temporary, if defined, then implement workaround for defect HW500611
#define P10_TOD_HW500611_IMPLEMENT_WORKAROUND

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// @brief Clears TOD error register
/// @param[in] i_tod_node Pointer to TOD topology (including FAPI targets)
/// @return FAPI2_RC_SUCCESS if TOD topology is cleared of previous errors
///         else FAPI or ECMD error is sent through
fapi2::ReturnCode p10_tod_clear_error_reg(const tod_topology_node* i_tod_node)

{
    FAPI_DBG("Start");

    // Clear the TOD error register by writing all bits to 1
    FAPI_DBG("Clear any previous errors from TOD_ERROR_REG");
    fapi2::buffer<uint64_t> l_data;
    l_data.flush<1>();
    FAPI_TRY(PREP_TOD_ERROR_REG(*(i_tod_node->i_target)));
    FAPI_TRY(PUT_TOD_ERROR_REG(*(i_tod_node->i_target), l_data),
             "Error from PUT_TOD_ERROR_REG");

    // Clear the TOD error register on all children
    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        FAPI_TRY(p10_tod_clear_error_reg(*l_child),
                 "Failure clearing errors from downstream node!");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// @brief Retrieves targets in the TOD topology
/// @param[in] i_tod_node Reference to TOD topology
/// @param[in] i_depth Current depth into TOD topology network
/// @param[out] o_targets Vector of targets, to be appended
/// @return void
void get_targets(
    const tod_topology_node* i_tod_node,
    const uint32_t i_depth,
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>& o_targets)
{
    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];

    if (i_tod_node == NULL || i_tod_node->i_target == NULL)
    {
        FAPI_INF("NULL tod_node or target parameter!");
        goto fapi_try_exit;
    }

    fapi2::toString(i_tod_node->i_target,
                    l_targetStr,
                    fapi2::MAX_ECMD_STRING_LEN);

    FAPI_INF("%s (Depth = %d)",
             l_targetStr, i_depth);

    o_targets.push_back(*(i_tod_node->i_target));

    for (auto& l_child : i_tod_node->i_children)
    {
        get_targets(l_child, i_depth + 1, o_targets);
    }

fapi_try_exit:
    return;
}

/// @brief Distribute synchronization signal to SS PLL using
///        TOD network
/// @param[in] i_tod_node Reference to TOD topology
/// @return FAPI2_RC_SUCCESS if TOD sync is succesful else error
fapi2::ReturnCode sync_spread(
    const tod_topology_node* i_tod_node)
{
    FAPI_DBG("Start");

    std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>> l_targets;
    get_targets(i_tod_node, 0, l_targets);
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_master_chip;
    fapi2::buffer<uint64_t> l_tod_value_data;
    fapi2::buffer<uint64_t> l_tod_timer_data;

    FAPI_ASSERT(l_targets.size(),
                fapi2::P10_TOD_SETUP_NULL_NODE(),
                "Null node or target passed into function!");
    l_master_chip = l_targets.front();

    // Read tod_value from TOD Value Register
    FAPI_TRY(GET_TOD_VALUE_REG(l_master_chip, l_tod_value_data),
             "Error from GET_TOD_VALUE_REG");

    // Write value > tod_value to TOD Timer Register and enable timers
    for (auto l_chip : l_targets)
    {
        FAPI_TRY(PREP_TOD_TIMER_REG(l_chip));
        SET_TOD_TIMER_REG_VALUE(l_tod_value_data + C_SSCG_START_DELAY, l_tod_timer_data);
        SET_TOD_TIMER_REG_ENABLE0(l_tod_timer_data);
        SET_TOD_TIMER_REG_ENABLE1(l_tod_timer_data);
        FAPI_TRY(PUT_TOD_TIMER_REG(l_chip, l_tod_timer_data),
                 "Error from PUT_TOD_TIMER_REG");
    }

    // Wait for SSCG start signal
    for (uint32_t i = 0;
         (i < C_SSCG_START_POLL_COUNT) && !l_targets.empty();
         i++)
    {
        fapi2::delay(C_SSCG_START_POLL_DELAY, C_SSCG_START_POLL_DELAY);

        for (auto l_chip_it = l_targets.begin();
             l_chip_it != l_targets.end();
            )
        {
            FAPI_TRY(GET_TOD_TIMER_REG(*l_chip_it,
                                       l_tod_timer_data),
                     "Error polling TOD_TIMER_REG");

            if (GET_TOD_TIMER_REG_STATUS1(l_tod_timer_data))
            {
                l_chip_it = l_targets.erase(l_chip_it);
            }
            else
            {
                l_chip_it++;
            }
        }
    }

    FAPI_ASSERT(l_targets.empty(),
                fapi2::P10_TOD_TIMER_START_SIGNAL_ERROR().
                set_TARGET(l_targets.front()),
                "Spread spectrum operation did not start on all processors; the SMP fabric might be dead now!");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// FIXME @RTC 213485 -- temporary, inserted for debug of HW500611.
//     Remove once fixed, since the entire TOD error register is checked
//     in the init_tod_node() routine.
/// @brief Check for the master request error in the TOD error register.
/// @param[in] i_target Chip target
/// @return FAPI2_RC_SUCCESS if no errors, else error
fapi2::ReturnCode p10_tod_check_error_reg_mreq(
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_target )
{
    fapi2::buffer<uint64_t> l_tod_err_reg = 0;
    fapi2::ReturnCode l_rc_fapi(fapi2::FAPI2_RC_SUCCESS);

    FAPI_TRY(GET_TOD_ERROR_REG(i_target, l_tod_err_reg),
             "Error from GET_TOD_ERROR_REG");

    if (GET_TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR(l_tod_err_reg))
    {
        l_rc_fapi = fapi2::FAPI2_RC_FALSE;
    }

fapi_try_exit:

    if (l_rc_fapi != fapi2::FAPI2_RC_SUCCESS)
    {
        fapi2::current_err = l_rc_fapi;
    }

    return fapi2::current_err;
}


/// @brief Helper function for p10_tod_init
/// @param[in] i_tod_node Pointer to TOD topology (including FAPI targets)
/// @param[out] o_failingTodProc Pointer to the fapi target, will be populated
///             with processor target unable to receive proper signals from OSC.
//              Caller needs to look at this parameter only when p10_tod_init
///             fails and reason code indicated OSC failure. Defaulted to NULL.
/// @return FAPI2_RC_SUCCESS if TOD topology is successfully initialized
///         else error
fapi2::ReturnCode init_tod_node(
    const tod_topology_node* i_tod_node,
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* o_failingTodProc)
{
    // Timeout counter for bits that are cleared by hardware
    uint32_t l_tod_init_pending_count = 0;
    fapi2::buffer<uint64_t> l_tod_fsm_reg;
    // Flag to check if the TOD FSM is running
    bool l_tod_running = false;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target;
    FAPI_DBG("Start");

    FAPI_ASSERT((i_tod_node != NULL) &&
                (i_tod_node->i_target != NULL),
                fapi2::P10_TOD_SETUP_NULL_NODE(),
                "Null node or target passed into function!");

    l_target = *(i_tod_node->i_target);

    // Sequence details are in TOD Workbook section 1.6.3
    // Is the current TOD being processed the master drawer master TOD?
    if (i_tod_node->i_tod_master && i_tod_node->i_drawer_master)
    {
        fapi2::buffer<uint64_t> l_data;

        //  Load-TOD-mod:
        //  TOD_LOAD_TOD_MOD_REG(@0x18)[00]= 0b1
        FAPI_DBG("Master: switch local Chip TOD to 'Not Set' state");
        FAPI_TRY(PREP_TOD_LOAD_MOD_REG(l_target));
        l_data.flush<0>();
        SET_TOD_LOAD_MOD_REG_TRIGGER(l_data);
        FAPI_TRY(PUT_TOD_LOAD_MOD_REG(l_target, l_data),
                 "Master: Error from PUT_TOD_LOAD_MOD_REG");

        // Load-TOD:
        // TOD_LOAD_TOD_REG(@0x21)
        // [00:59] = desired TOD value
        FAPI_DBG("Master: Chip TOD load value (move TB to TOD)");
        FAPI_TRY(PREP_TOD_LOAD_REG(l_target));
        // FIXME @RTC 213485 -- double-check this setting, See Table 1.4.1 in P10_perv workbook.
        SET_TOD_LOAD_REG_LOAD_TOD_VALUE( P10_TOD_LOAD_REG_LOAD_VALUE , l_data);
        // FIXME @RTC 213485 -- double-check this setting, See Table 1.4.1 in P10_perv workbook.
        SET_TOD_LOAD_REG_WOF( P10_TOD_LOAD_REG_START_TOD, l_data);
        FAPI_TRY(PUT_TOD_LOAD_REG(l_target, l_data),
                 "Master: Error from PUT_TOD_LOAD_REG");

#ifdef P10_TOD_HW500611_IMPLEMENT_WORKAROUND
        // FIXME @RTC 213485 -- temporary, workaround for defect HW500611
        FAPI_INF("Implementing workaround for defect HW500611");
#else
        // STEP checking enable:
        // TOD_TX_TTYPE_2_REG(@0x13)[00] = 0b1: TX-TTYPE-2
        FAPI_DBG("Master: Chip TOD step checkers enable");
        FAPI_TRY(PREP_TOD_TX_TTYPE_2_REG(l_target));
        l_data.flush<0>();
        SET_TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER(l_data);
        FAPI_TRY(PUT_TOD_TX_TTYPE_2_REG(l_target, l_data),
                 "Master: Error from PUT_TOD_TX_TTYPE_2_REG");

        // FIXME @RTC 213485 -- temporary, inserted for debug of HW500611
        FAPI_TRY(p10_tod_check_error_reg_mreq(l_target),
                 "Error from p10_tod_check_error_reg_mreq");

        // Load-TOD-mod:
        // Initiate a TX-TTYPE-5 from the TOD master:
        // TOD_TX_TTYPE_5_REG(@0x16)[00] = 0b1
        FAPI_DBG("Master: switch all Chip TOD in the system to 'Not Set' state");
        FAPI_TRY(PREP_TOD_TX_TTYPE_5_REG(l_target));
        l_data.flush<0>();
        SET_TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER(l_data);
        FAPI_TRY(PUT_TOD_TX_TTYPE_5_REG(l_target, l_data),
                 "Master: Error from PUT_TOD_TX_TTYPE_5_REG");

        // FIXME @RTC 213485 -- temporary, inserted for debug of HW500611
        FAPI_TRY(p10_tod_check_error_reg_mreq(l_target),
                 "Error from p10_tod_check_error_reg_mreq");

        // Load-TOD:
        // Initiate a TTYPE-4 from the TOD master:
        // TOD_TX_TTYPE_4_REG(@0x15)[00] = 0b1
        FAPI_DBG("Master: Send local Chip TOD value to all Chip TODs");
        FAPI_TRY(PREP_TOD_TX_TTYPE_4_REG(l_target));
        l_data.flush<0>();
        SET_TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER(l_data);
        FAPI_TRY(PUT_TOD_TX_TTYPE_4_REG(l_target, l_data),
                 "Master: Error from PUT_TOD_TX_TTYPE_4_REG");

        // FIXME @RTC 213485 -- temporary, inserted for debug of HW500611
        FAPI_TRY(p10_tod_check_error_reg_mreq(l_target),
                 "Error from p10_tod_check_error_reg_mreq");

        // STEP checking enable:
        // Initiate a TTYPE-2 from the TOD master:
        // TOD_TX_TTYPE_2_REG(@0x13)[00] = 0b1
        // Already done above.
        FAPI_DBG("Master: Chip TOD step checkers enable");
        FAPI_TRY(PREP_TOD_TX_TTYPE_2_REG(l_target));
        l_data.flush<0>();
        SET_TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER(l_data);
        FAPI_TRY(PUT_TOD_TX_TTYPE_2_REG(l_target, l_data),
                 "Master: Error from PUT_TOD_TX_TTYPE_2_REG");

        // FIXME @RTC 213485 -- temporary, inserted for debug of HW500611
        FAPI_TRY(p10_tod_check_error_reg_mreq(l_target),
                 "Error from p10_tod_check_error_reg_mreq");
#endif

        // FIXME @RTC 213485 -- this config write was in the P9 code,
        // but I can't find the requirement for this config write in
        // the design specification.  But it seems to be required
        // to get the TOD FSM into the Running State.
        // See P10_perv workbook, Figure 1.4.17
        FAPI_DBG("Master: Chip TOD start_tod (switch local Chip TOD to 'Running' state)");
        FAPI_TRY(PREP_TOD_START_REG(l_target));
        l_data.flush<0>();
        SET_TOD_START_REG_FSM_START_TOD_TRIGGER(l_data);
        // The DATA02 bit was NOT set in P9 HWP. However it seems to be required
        // in order to avoid an I_PATH_SYNC_CHECK_ERROR in the TOD_ERROR_REG in P10.
        // This bit forces the FSM to wait for a Sync before proceeding
        // to the Running State.  See P10_perv workbook, Figure 1.4.17
        SET_TOD_START_REG_FSM_START_TOD_DATA02(l_data);
        FAPI_TRY(PUT_TOD_START_REG(l_target, l_data),
                 "Master: Error from PUT_TOD_START_REG");

    }

    FAPI_DBG("Check TOD is Running");

    while (l_tod_init_pending_count < P10_TOD_UTIL_TIMEOUT_COUNT)
    {
        FAPI_DBG("Waiting for TOD to assert TOD_FSM_REG_TOD_IS_RUNNING...");
        FAPI_TRY(fapi2::delay(P10_TOD_UTILS_HW_NS_DELAY, P10_TOD_UTILS_SIM_CYCLE_DELAY),
                 "Error from delay!");
        FAPI_TRY(GET_TOD_FSM_REG(l_target, l_tod_fsm_reg),
                 "Error from GET_TOD_FSM_REG");

        if (GET_TOD_FSM_REG_TOD_IS_RUNNING(l_tod_fsm_reg))
        {
            FAPI_DBG("TOD is running!");
            l_tod_running = true;
            break;
        }

        ++l_tod_init_pending_count;
    }

    if (l_tod_running == false)
    {
        FAPI_DBG("TOD FSM failed !");
        fapi2::buffer<uint64_t> l_tod_err_reg = 0;
        FAPI_TRY(GET_TOD_ERROR_REG(l_target, l_tod_err_reg),
                 "Error from GET_TOD_ERROR_REG");

        FAPI_ASSERT(!GET_TOD_ERROR_REG_OSCSWITCH_INTERRUPT(l_tod_err_reg),
                    fapi2::P10_TOD_MF_CLK_FAILURE()
                    .set_TARGET(l_target),
                    "Interrupt from TOD Oscillator Switch");
    }

    FAPI_ASSERT((l_tod_init_pending_count < P10_TOD_UTIL_TIMEOUT_COUNT),
                fapi2::P10_TOD_INIT_NOT_RUNNING()
                .set_TARGET(l_target)
                .set_COUNT(l_tod_init_pending_count)
                .set_TOD_FSM_DATA(l_tod_fsm_reg()),
                "TOD is expected to be running, but is not!");

    {
        FAPI_DBG("Clear TTYPE#2, TTYPE#4, and TTYPE#5 status");
        fapi2::buffer<uint64_t> l_tod_err_reg = 0;
        fapi2::buffer<uint64_t> l_tod_err_mask_reg = 0;

        FAPI_TRY(PREP_TOD_ERROR_REG(l_target));
        SET_TOD_ERROR_REG_RX_TTYPE_2(l_tod_err_reg);
        SET_TOD_ERROR_REG_RX_TTYPE_4(l_tod_err_reg);
        SET_TOD_ERROR_REG_RX_TTYPE_5(l_tod_err_reg);
        FAPI_TRY(PUT_TOD_ERROR_REG(l_target, l_tod_err_reg),
                 "Error from PUT_TOD_ERROR_REG");

        FAPI_DBG("Checking for TOD errors");
        FAPI_TRY(GET_TOD_ERROR_REG(l_target, l_tod_err_reg),
                 "Error from GET_TOD_ERROR_REG");

        // Before going to assertion checks, populate pointer prior to exit
        if (o_failingTodProc != NULL &&
            (GET_TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR(l_tod_err_reg) ||
             GET_TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR(l_tod_err_reg)))
        {
            *o_failingTodProc = l_target;
        }

        FAPI_ASSERT(!GET_TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR(l_tod_err_reg),
                    fapi2::P10_TOD_INIT_M_PATH_0_STEP_CHECK_ERROR()
                    .set_TARGET(l_target)
                    .set_TOD_ERROR_REG(l_tod_err_reg),
                    "M_PATH_0_STEP_CHECK_ERROR!");
        FAPI_ASSERT(!GET_TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR(l_tod_err_reg),
                    fapi2::P10_TOD_INIT_M_PATH_1_STEP_CHECK_ERROR()
                    .set_TARGET(l_target)
                    .set_TOD_ERROR_REG(l_tod_err_reg),
                    "M_PATH_1_STEP_CHECK_ERROR!");
        FAPI_ASSERT(!l_tod_err_reg(),
                    fapi2::P10_TOD_INIT_ERROR()
                    .set_TARGET(l_target)
                    .set_TOD_ERROR_REG(l_tod_err_reg),
                    "TOD FIR bit active!");

        FAPI_DBG("Set error mask to runtime configuration");
        // Mask TTYPE received informational bits 38:43
        FAPI_TRY(PREP_TOD_ERROR_MASK_REG(l_target));
        SET_TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK(l_tod_err_mask_reg);
        SET_TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK(l_tod_err_mask_reg);
        SET_TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK(l_tod_err_mask_reg);
        SET_TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK(l_tod_err_mask_reg);
        SET_TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK(l_tod_err_mask_reg);
        SET_TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK(l_tod_err_mask_reg);
        FAPI_TRY(PUT_TOD_ERROR_MASK_REG(l_target, l_tod_err_mask_reg),
                 "Error from PUT_TOD_ERROR_MASK_REG");
    }

    // recursively configure downstream nodes
    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        FAPI_TRY(init_tod_node(*l_child, o_failingTodProc),
                 "Failure configuring downstream node!");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// NOTE: description in header
fapi2::ReturnCode p10_tod_init(
    const tod_topology_node* i_tod_node,
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* o_failingTodProc)
{
    FAPI_DBG("Start");

    FAPI_ASSERT((i_tod_node != NULL) &&
                (i_tod_node->i_target != NULL),
                fapi2::P10_TOD_SETUP_NULL_NODE(),
                "Null node or target passed into function!");

    FAPI_ASSERT((i_tod_node->i_tod_master) &&
                (i_tod_node->i_drawer_master),
                fapi2::P10_TOD_SETUP_INVALID_TOPOLOGY()
                .set_TARGET(*(i_tod_node->i_target))
                .set_OSCSEL(0)    // not used
                .set_TODSEL(0),   // not used
                "Non-root (slave) node passed into main function!");

    // Clear the error register so we don't get any "fake" errors
    FAPI_TRY(p10_tod_clear_error_reg(i_tod_node),
             "Error from p10_tod_clear_error_reg!");

    // Start configuring each node; (init_tod_node will recurse on each child)
    FAPI_TRY(init_tod_node(i_tod_node, o_failingTodProc),
             "Error from init_tod_node!");

#ifdef P10_TOD_HW500611_IMPLEMENT_WORKAROUND
    // FIXME @RTC 213485 -- temporary, workaround for defect HW500611
    FAPI_INF("Implementing workaround for defect HW500611");
#else
    // sync spread across chips in topology
    FAPI_TRY(sync_spread(i_tod_node),
             "Error from sync_spread!");
#endif

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
