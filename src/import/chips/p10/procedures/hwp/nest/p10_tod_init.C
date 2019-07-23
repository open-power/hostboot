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

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// @brief Clears TOD error register
/// @param[in] i_tod_node Pointer to TOD topology (including FAPI targets)
/// @return FAPI_RC_SUCCESS if TOD topology is cleared of previous errors
///         else FAPI or ECMD error is sent through
fapi2::ReturnCode p10_tod_clear_error_reg(const tod_topology_node* i_tod_node)

{
    FAPI_DBG("Start");

    // Clear the TOD error register by writing all bits to 1
    FAPI_DBG("Clear any previous errors from PERV_TOD_ERROR_REG");
    fapi2::buffer<uint64_t> l_data;
    l_data.flush<1>();
    FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                            PERV_TOD_ERROR_REG,
                            l_data),
             "Error from putScom (PERV_TOD_ERROR_REG)!");

    // Clear the TOD error register on all children
    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        FAPI_TRY(p10_tod_clear_error_reg(*l_child),
                 "Failure clearing errors from downstream node!");
    }

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}

/// @brief Retrieves targets in the TOD topology
/// @param[in] i_tod_node Reference to TOD topology
/// @param[in] i_depth Current depth into TOD topology network
/// @param[in] o_targets Vector of targets, to be appended
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
/// @return FAPI_RC_SUCCESS if TOD sync is succesful else error
fapi2::ReturnCode sync_spread(
    const tod_topology_node* i_tod_node)
{
    FAPI_DBG("Start");

    std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>> l_targets;
    get_targets(i_tod_node, 0, l_targets);
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_master_chip;
    fapi2::buffer<uint64_t> l_tod_value_data;
    fapi2::buffer<uint64_t> l_tod_timer_data;
    uint8_t l_sync_spread = 0;

    FAPI_ASSERT(l_targets.size(),
                fapi2::P10_TOD_SETUP_NULL_NODE(),
                "Null node or target passed into function!");
    l_master_chip = l_targets.front();

#if 0
    // FIXME @RTC 213485 port to P10
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FORCE_SYNC_SS_PLL_SPREAD,
                           fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_sync_spread),
             "Error from FAPI_ATTR_GET (ATTR_FORCE_SYNC_SS_PLL_SPREAD)");
#endif

#if 0

    // FIXME @RTC 213485 port to P10
    if (!l_sync_spread)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_SYNC_SS_PLL_SPREAD,
                               l_master_chip,
                               l_sync_spread),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_SYNC_SS_PLL_SPREAD)");
    }

#endif

    if (!l_sync_spread)
    {
        goto fapi_try_exit;
    }

    // Read tod_value from TOD Value Register
    FAPI_TRY(fapi2::getScom(l_master_chip,
                            PERV_TOD_VALUE_REG,
                            l_tod_value_data),
             "Error reading TOD_VALUE_REG");

    l_tod_timer_data = ((l_tod_value_data + (C_SSCG_START_DELAY << 4)) &
                        0xFFFFFFFFFFFFFFF0ULL) | 0xC;

    // Write value > tod_value to TOD Timer Register
    for (auto l_chip : l_targets)
    {
        FAPI_TRY(fapi2::putScom(l_chip,
                                PERV_TOD_TIMER_REG,
                                l_tod_timer_data),
                 "Error writing to TOD_TIMER_REG");
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
            FAPI_TRY(fapi2::getScom(*l_chip_it,
                                    PERV_TOD_TIMER_REG,
                                    l_tod_timer_data),
                     "Error polling TOD_TIMER_REG");

            if (l_tod_timer_data.getBit<PERV_TOD_TIMER_REG_STATUS>())
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

/// @brief Helper function for p10_tod_init
/// @param[in] i_tod_node Pointer to TOD topology (including FAPI targets)
/// @param[out] o_failingTodProc Pointer to the fapi target, will be populated
///             with processor target unable to receive proper signals from OSC.
//              Caller needs to look at this parameter only when p10_tod_init
///             fails and reason code indicated OSC failure. Defaulted to NULL.
/// @return FAPI_RC_SUCCESS if TOD topology is successfully initialized
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
    FAPI_DBG("Start");

    // Sequence details are in TOD Workbook section 1.6.3
    // Is the current TOD being processed the master drawer master TOD?
    if (i_tod_node->i_tod_master && i_tod_node->i_drawer_master)
    {
        fapi2::buffer<uint64_t> l_data;
        // TOD Step checkers enable - write TOD_TX_TTYPE_2_REG to enable
        // TOD STEP checking on all chips
        FAPI_DBG("Master: Chip TOD step checkers enable");
        l_data.flush<0>().setBit<PERV_TOD_TX_TTYPE_2_REG_TRIGGER>();
        FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                                PERV_TOD_TX_TTYPE_2_REG,
                                l_data),
                 "Master: Error from putScom (PERV_TOD_TX_TTYPE_2_REG)!");

        FAPI_DBG("Master: switch local Chip TOD to 'Not Set' state");
        l_data.flush<0>().setBit<PERV_TOD_LOAD_TOD_MOD_REG_FSM_TRIGGER>();
        FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                                PERV_TOD_LOAD_TOD_MOD_REG,
                                l_data),
                 "Master: Error from putScom (PERV_TOD_LOAD_TOD_MOD_REG)!");

        FAPI_DBG("Master: switch all Chip TOD in the system to 'Not Set' state");
        l_data.flush<0>().setBit<PERV_TOD_TX_TTYPE_5_REG_TRIGGER>();
        FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                                PERV_TOD_TX_TTYPE_5_REG,
                                l_data),
                 "Master: Error from putScom (PERV_TOD_TX_TTYPE_5_REG)!");

        FAPI_DBG("Master: Chip TOD load value (move TB to TOD)");
        l_data = PERV_TOD_LOAD_REG_LOAD_VALUE;
        FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                                PERV_TOD_LOAD_TOD_REG,
                                l_data),
                 "Master: Error from putScom (PERV_TOD_LOAD_TOD_REG)!");

        FAPI_DBG("Master: Chip TOD start_tod (switch local Chip TOD to 'Running' state)");
        l_data.flush<0>().setBit<PERV_TOD_START_TOD_REG_FSM_TRIGGER>();
        FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                                PERV_TOD_START_TOD_REG,
                                l_data),
                 "Master: Error from putScom (PERV_TOD_START_TOD_REG)!");

        FAPI_DBG("Master: Send local Chip TOD value to all Chip TODs");
        l_data.flush<0>().setBit<PERV_TOD_TX_TTYPE_4_REG_TRIGGER>();
        FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                                PERV_TOD_TX_TTYPE_4_REG,
                                l_data),
                 "Master: Error from putScom (PERV_TOD_TX_TTYPE_4_REG)!");
    }

    FAPI_DBG("Check TOD is Running");

    while (l_tod_init_pending_count < P10_TOD_UTIL_TIMEOUT_COUNT)
    {
        FAPI_DBG("Waiting for TOD to assert TOD_FSM_REG_TOD_IS_RUNNING...");
        FAPI_TRY(fapi2::delay(P10_TOD_UTILS_HW_NS_DELAY, P10_TOD_UTILS_SIM_CYCLE_DELAY),
                 "Error from delay!");
        FAPI_TRY(fapi2::getScom(*(i_tod_node->i_target),
                                PERV_TOD_FSM_REG,
                                l_tod_fsm_reg),
                 "Error from getScom (PERV_TOD_FSM_REG)!");

        if (l_tod_fsm_reg.getBit<PERV_TOD_FSM_REG_IS_RUNNING>())
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
        FAPI_TRY(fapi2::getScom(*(i_tod_node->i_target),
                                PERV_TOD_ERROR_REG,
                                l_tod_err_reg),
                 "Error from getScom (PERV_TOD_ERROR_REG)!");

        FAPI_ASSERT(!l_tod_err_reg.getBit<PERV_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT>(),
                    fapi2::P10_TOD_MF_CLK_FAILURE()
                    .set_TARGET(*(i_tod_node->i_target)),
                    "Interrupt from TOD Oscillator Switch");
    }

    FAPI_ASSERT((l_tod_init_pending_count < P10_TOD_UTIL_TIMEOUT_COUNT),
                fapi2::P10_TOD_INIT_NOT_RUNNING()
                .set_TARGET(*(i_tod_node->i_target))
                .set_COUNT(l_tod_init_pending_count)
                .set_TOD_FSM_DATA(l_tod_fsm_reg()),
                "TOD is expected to be running, but is not!");

    {
        FAPI_DBG("Clear TTYPE#2, TTYPE#4, and TTYPE#5 status");
        fapi2::buffer<uint64_t> l_tod_err_reg = 0;
        fapi2::buffer<uint64_t> l_tod_err_mask_reg = 0;
        l_tod_err_reg.setBit<PERV_TOD_ERROR_REG_RX_TTYPE_2>();
        l_tod_err_reg.setBit<PERV_TOD_ERROR_REG_RX_TTYPE_4>();
        l_tod_err_reg.setBit<PERV_TOD_ERROR_REG_RX_TTYPE_5>();
        FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                                PERV_TOD_ERROR_REG,
                                l_tod_err_reg),
                 "Error from putScom (PERV_TOD_ERROR_REG)!");

        FAPI_DBG("Checking for TOD errors");
        FAPI_TRY(fapi2::getScom(*(i_tod_node->i_target),
                                PERV_TOD_ERROR_REG,
                                l_tod_err_reg),
                 "Error from getScom (PERV_TOD_ERROR_REG)!");

        // going to assert, populate pointer prior to exit
        if (l_tod_err_reg.getBit<PERV_TOD_ERROR_REG_M_PATH_0_STEP_CHECK>() ||
            l_tod_err_reg.getBit<PERV_TOD_ERROR_REG_M_PATH_1_STEP_CHECK>())
        {
            *o_failingTodProc = *(i_tod_node->i_target);
        }

        FAPI_ASSERT(!l_tod_err_reg.getBit<PERV_TOD_ERROR_REG_M_PATH_0_STEP_CHECK>(),
                    fapi2::P10_TOD_INIT_M_PATH_0_STEP_CHECK_ERROR()
                    .set_TARGET(*(i_tod_node->i_target))
                    .set_TOD_ERROR_REG(l_tod_err_reg),
                    "M_PATH_0_STEP_CHECK_ERROR!");
        FAPI_ASSERT(!l_tod_err_reg.getBit<PERV_TOD_ERROR_REG_M_PATH_1_STEP_CHECK>(),
                    fapi2::P10_TOD_INIT_M_PATH_1_STEP_CHECK_ERROR()
                    .set_TARGET(*(i_tod_node->i_target))
                    .set_TOD_ERROR_REG(l_tod_err_reg),
                    "M_PATH_1_STEP_CHECK_ERROR!");
        FAPI_ASSERT(!l_tod_err_reg(),
                    fapi2::P10_TOD_INIT_ERROR()
                    .set_TARGET(*(i_tod_node->i_target))
                    .set_TOD_ERROR_REG(l_tod_err_reg),
                    "FIR bit active!");

        FAPI_DBG("Set error mask to runtime configuration");
        // Mask TTYPE received informational bits 38:43
        l_tod_err_mask_reg.setBit<PERV_TOD_ERROR_MASK_REG_RX_TTYPE_0>()
        .setBit<PERV_TOD_ERROR_MASK_REG_RX_TTYPE_1>()
        .setBit<PERV_TOD_ERROR_MASK_REG_RX_TTYPE_2>()
        .setBit<PERV_TOD_ERROR_MASK_REG_RX_TTYPE_3>()
        .setBit<PERV_TOD_ERROR_MASK_REG_RX_TTYPE_4>()
        .setBit<PERV_TOD_ERROR_MASK_REG_RX_TTYPE_5>();
        FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                                PERV_TOD_ERROR_MASK_REG,
                                l_tod_err_mask_reg),
                 "Error from putScom (PERV_TOD_ERROR_MASK_REG)");
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
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}


// NOTE: description in header
fapi2::ReturnCode p10_tod_init(
    const tod_topology_node* i_tod_node,
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* o_failingTodProc)
{
    FAPI_DBG("Start");

    // Clear the error register so we don't get any "fake" errors
    FAPI_TRY(p10_tod_clear_error_reg(i_tod_node),
             "Error from p10_tod_clear_error_reg!");

    // Start configuring each node; (init_tod_node will recurse on each child)
    FAPI_TRY(init_tod_node(i_tod_node, o_failingTodProc),
             "Error from init_tod_node!");

    // sync spread across chips in topology
    FAPI_TRY(sync_spread(i_tod_node),
             "Error from sync_spread!");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}
