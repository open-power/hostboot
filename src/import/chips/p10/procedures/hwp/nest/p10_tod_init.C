/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_tod_init.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
#include <p10_scom_eq.H>
#include <p10_scom_c.H>
#include <p10_pm_hcd_flags.h>
#include <p10_sbe_tp_chiplet_init.H>
#include <multicast_group_defs.H>
#include <cstdint>

//------------------------------------------------------------------------------
// Namespace declarations
//------------------------------------------------------------------------------

using namespace scomt;
using namespace scomt::perv;
using namespace scomt::eq;
using namespace scomt::c;

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
// Implement workaround for P10 defect HW527708.
const bool IMPLEMENT_HW527708_WORKAROUND = true;

// This is the number of Sync pulse periods which will be added to the
// current Master TOD Value register and placed into the TOD Timer registers.
// From the VHDL comments for the receipt of a TTYPE_4:
//    "TOD was sent via fabric on sync_2x boundary and is now waiting on sync to be
//     started on sync_1x+sync_1x boundary."
// A value of 2 works here, but I used 4 in case of any unexpected corner cases.
const uint32_t P10_TOD_TIMER_SYNC_WAIT_PERIOD = 4;

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

/// @brief Decode the SPS (Steps per Sync) encoded field
/// @param[in] i_sps Encoded SPS field
/// @param[out] o_steps_per_sync Decoded SPS field
/// @return FAPI2_RC_SUCCESS if succesful else error
fapi2::ReturnCode p10_tod_decode_sps(
    fapi2::buffer<uint64_t> i_sps,
    uint64_t& o_steps_per_sync)
{

    switch (i_sps())
    {
        case TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_512:
            o_steps_per_sync = 512;
            break;

        case TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_128:
            o_steps_per_sync = 128;
            break;

        case TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_64:
            o_steps_per_sync = 64;
            break;

        case TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_32:
            o_steps_per_sync = 32;
            break;

        case TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_4096:
            o_steps_per_sync = 4096;
            break;

        case TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_2048:
            o_steps_per_sync = 2048;
            break;

        case TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_1024:
            o_steps_per_sync = 1024;
            break;

        case TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_256:
            o_steps_per_sync = 256;
            break;

        default:
            // Should not ever reach this point, something wrong in the code.
            FAPI_ASSERT(false,
                        fapi2::P10_TOD_INVALID_SPS()
                        .set_TOD_SPS(i_sps),
                        "Invalid TOD SPS field in TOD_M_PATH_CTRL_REG!");
            break;
    }

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Return the number of configured TOD Master Steps per Sync
/// @param[in] i_tod_node Reference to TOD topology
/// @return FAPI2_RC_SUCCESS if succesful else error
fapi2::ReturnCode p10_tod_steps_per_sync(
    const tod_topology_node* i_tod_node,
    uint64_t& o_steps_per_sync)
{
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(i_tod_node->i_target);
    fapi2::buffer<uint64_t> l_m_path_ctrl_reg = 0;
    fapi2::buffer<uint64_t> l_sps_select = 0;

    FAPI_DBG("Start");

    // Read TOD_M_PATH_CTRL_REG
    FAPI_TRY(GET_TOD_M_PATH_CTRL_REG(l_target, l_m_path_ctrl_reg),
             "Error from GET_TOD_M_PATH_CTRL_REG");

    // Get the SPS select field
    GET_TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT(l_m_path_ctrl_reg, l_sps_select);

    FAPI_TRY(p10_tod_decode_sps(l_sps_select, o_steps_per_sync));

    if (GET_TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE(l_m_path_ctrl_reg))
    {
        // DUAL_EDGE_DISABLE has the effect of dividing the SPS by half.
        o_steps_per_sync >>= 1;
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// @brief Convert TOD count into a polling delay in either NS or sim cycles
/// @param[in] i_is_simulation True if simulation, else false
/// @param[in] i_tod_count Number of TOD counts (step pulses)
/// @param[in] i_polling_count Number of times to poll
/// @param[out] o_poll_cycle_delay  Poll cycle delay in NS or sim cycles
/// @return FAPI2_RC_SUCCESS if succesful else error
fapi2::ReturnCode p10_tod_polling_delay(
    const bool i_is_simulation,
    const uint64_t& i_tod_count,
    const uint64_t& i_polling_count,
    uint64_t& o_poll_cycle_delay)
{
    // Number of simulation cycles per TOD clock.
    const uint64_t  P10_TOD_SIM_CYCLES_PER_TOD_CLOCK = 2000;
    // 31.25ns rounded up
    const uint64_t  P10_TOD_NS_PER_TOD_COUNT = 32;
    FAPI_DBG("Start");

    FAPI_ASSERT(i_is_simulation ? (i_tod_count <= UINT64_MAX / P10_TOD_SIM_CYCLES_PER_TOD_CLOCK) :
                (i_tod_count <= UINT64_MAX / P10_TOD_NS_PER_TOD_COUNT),
                fapi2::P10_TOD_POLLING_DELAY_CALC_OVERFLOW()
                .set_TOD_COUNT(i_tod_count)
                .set_TOD_DIVISOR(i_is_simulation ? P10_TOD_SIM_CYCLES_PER_TOD_CLOCK : P10_TOD_NS_PER_TOD_COUNT)
                .set_NUMERIC_LIMIT(UINT64_MAX),
                "Polling delay calculation overflow!");

    o_poll_cycle_delay = i_is_simulation ? (i_tod_count * P10_TOD_SIM_CYCLES_PER_TOD_CLOCK) :
                         (i_tod_count * P10_TOD_NS_PER_TOD_COUNT) ;

    // Divide the total polling delay amongst each polling cycle
    o_poll_cycle_delay /= i_polling_count;

    FAPI_DBG("i_tod_count = %llu i_polling_count = %llu o_poll_cycle_delay = %llu", i_tod_count, i_polling_count,
             o_poll_cycle_delay);

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// @brief Wait one Sync period on the current TOD node
/// @param[in] i_tod_node Reference to TOD topology
/// @return FAPI2_RC_SUCCESS if succesful else error
fapi2::ReturnCode p10_tod_wait_sync_period(
    const tod_topology_node* i_tod_node,
    const bool i_is_simulation)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(i_tod_node->i_target);
    fapi2::buffer<uint64_t> l_tod_value_reg;
    fapi2::buffer<uint64_t> l_tod_value_reg_tod_value_initial;
    fapi2::buffer<uint64_t> l_tod_value_reg_tod_value;
    fapi2::buffer<uint64_t> l_steps_per_sync = 0;
    uint64_t l_poll_cycle_delay = 0;

    // Read initial tod_value from TOD Value Register
    FAPI_TRY(GET_TOD_VALUE_REG(l_target, l_tod_value_reg),
             "Error from GET_TOD_VALUE_REG");
    GET_TOD_VALUE_REG_TOD_VALUE(l_tod_value_reg, l_tod_value_reg_tod_value_initial);

    // Get the number of Steps per Sync
    FAPI_TRY(p10_tod_steps_per_sync(i_tod_node, l_steps_per_sync));

    FAPI_TRY(p10_tod_polling_delay(i_is_simulation,
                                   2 * l_steps_per_sync(),  // Wait twice the expected delay before declaring timeout
                                   P10_TOD_UTIL_TIMEOUT_COUNT,
                                   l_poll_cycle_delay));

    // Wait until the TOD Timer has counted off the required number of TOD Steps
    // which represent one Sync period.
    for (uint32_t i = 0; i < P10_TOD_UTIL_TIMEOUT_COUNT ; i++)
    {
        fapi2::delay(l_poll_cycle_delay, l_poll_cycle_delay);

        FAPI_TRY(GET_TOD_VALUE_REG(l_target, l_tod_value_reg),
                 "Error from GET_TOD_VALUE_REG");
        GET_TOD_VALUE_REG_TOD_VALUE(l_tod_value_reg, l_tod_value_reg_tod_value);

        if (l_steps_per_sync < (l_tod_value_reg_tod_value - l_tod_value_reg_tod_value_initial))
        {
            break;
        }
    }

    FAPI_ASSERT(l_steps_per_sync < (l_tod_value_reg_tod_value - l_tod_value_reg_tod_value_initial),
                fapi2::P10_TOD_TIMER_STEP_COUNT_ERROR()
                .set_TARGET(l_target)
                .set_STEPS_PER_SYNC(l_steps_per_sync)
                .set_TOD_VALUE(l_tod_value_reg_tod_value)
                .set_TOD_VALUE_INITIAL(l_tod_value_reg_tod_value_initial),
                "TOD Timer step count error!");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// @brief Setup the TOD Value registers to distribute synchronization signal to SS PLL using
///        TOD network
/// @param[in] i_tod_node Reference to TOD topology
/// @return FAPI2_RC_SUCCESS if TOD sync is succesful else error
fapi2::ReturnCode sync_spread_setup(
    const tod_topology_node* i_tod_node)
{
    fapi2::buffer<uint64_t> l_steps_per_sync = 0;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>> l_targets;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_master_chip;
    fapi2::buffer<uint64_t> l_tod_value_reg_tod_value;
    fapi2::buffer<uint64_t> l_tod_value_reg;
    fapi2::buffer<uint64_t> l_tod_timer_data;

    FAPI_DBG("Start");

    get_targets(i_tod_node, 0, l_targets);
    FAPI_ASSERT(l_targets.size(),
                fapi2::P10_TOD_SETUP_NULL_NODE(),
                "Null node or target passed into function!");
    l_master_chip = l_targets.front();

    // Read tod_value from TOD Value Register
    FAPI_TRY(GET_TOD_VALUE_REG(l_master_chip, l_tod_value_reg),
             "Error from GET_TOD_VALUE_REG");

    // Get Internal path Time-of-day register value
    GET_TOD_VALUE_REG_TOD_VALUE(l_tod_value_reg, l_tod_value_reg_tod_value);

    // Get the number of Steps per Sync
    FAPI_TRY(p10_tod_steps_per_sync(i_tod_node, l_steps_per_sync));

    // Set the Timer registers in the future to fire their status bits simultaneously
    // on all chips.
    for (auto l_chip : l_targets)
    {
        FAPI_TRY(PREP_TOD_TIMER_REG(l_chip));
        SET_TOD_TIMER_REG_VALUE(l_tod_value_reg_tod_value + P10_TOD_TIMER_SYNC_WAIT_PERIOD * l_steps_per_sync,
                                l_tod_timer_data);
        SET_TOD_TIMER_REG_ENABLE0(l_tod_timer_data);
        SET_TOD_TIMER_REG_ENABLE1(l_tod_timer_data);
        FAPI_TRY(PUT_TOD_TIMER_REG(l_chip, l_tod_timer_data),
                 "Error from PUT_TOD_TIMER_REG");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// @brief Check setup of the TOD Value registers to distribute synchronization signal to SS PLL using
///        TOD network
/// @param[in] i_tod_node Reference to TOD topology
/// @param[in] i_is_simulation True if simulation, else false
/// @return FAPI2_RC_SUCCESS if TOD sync is succesful else error
fapi2::ReturnCode sync_spread_check(
    const tod_topology_node* i_tod_node,
    const bool i_is_simulation)
{
    uint64_t l_poll_cycle_delay = 0;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>> l_targets;
    fapi2::buffer<uint64_t> l_tod_value_reg;
    fapi2::buffer<uint64_t> l_tod_timer_data;
    fapi2::buffer<uint64_t> l_steps_per_sync = 0;

    FAPI_DBG("Start");

    get_targets(i_tod_node, 0, l_targets);

    // Get the number of Steps per Sync
    FAPI_TRY(p10_tod_steps_per_sync(i_tod_node, l_steps_per_sync));

    FAPI_TRY(p10_tod_polling_delay(i_is_simulation,
                                   2 * P10_TOD_TIMER_SYNC_WAIT_PERIOD * l_steps_per_sync,  // Wait twice the expected delay before declaring timeout
                                   P10_TOD_UTIL_TIMEOUT_COUNT,
                                   l_poll_cycle_delay));

    // Wait for SSCG start signal
    for (uint32_t i = 0;
         (i < P10_TOD_UTIL_TIMEOUT_COUNT) && !l_targets.empty();
         i++)
    {
        fapi2::delay(l_poll_cycle_delay, l_poll_cycle_delay);

        for (auto l_chip_it = l_targets.begin();
             l_chip_it != l_targets.end();
            )
        {
            FAPI_TRY(GET_TOD_VALUE_REG(*l_chip_it,
                                       l_tod_value_reg),
                     "Error from GET_TOD_VALUE_REG");

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


/// @brief Helper function for p10_tod_init
/// @param[in] i_tod_node Pointer to TOD topology (including FAPI targets)
/// @param[in] i_is_simulation True if simulation, else false
/// @param[in] i_disable_tod_sync_spread True if disable Sync Spread, else false
/// @param[out] o_failingTodProc Pointer to the fapi target, will be populated
///             with processor target unable to receive proper signals from OSC,
///              or the processor target where the TOD secondary topology failed.
///              Caller needs to look at this parameter only when p10_tod_init
///             fails and reason code indicated OSC or TOD secondary topology
///              failure. Defaulted to NULL.
///  @param[out] o_secondary_topology_failed Secondary TOD topology failed initialization.
/// @return FAPI2_RC_SUCCESS if TOD topology is successfully initialized
///         else error
fapi2::ReturnCode init_tod_node(
    const tod_topology_node* i_tod_node,
    const bool i_is_simulation,
    const bool i_disable_tod_sync_spread,
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* o_failingTodProc,
    bool& o_secondary_topology_failed)
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

        if (IMPLEMENT_HW527708_WORKAROUND)
        {
            // Before enabling the Step checkers on the Slaves,
            // wait for a full Sync period on the MDMT to workaround defect HW527708
            FAPI_TRY(p10_tod_wait_sync_period(i_tod_node, i_is_simulation),
                     "Error from p10_tod_wait_sync_period!");
        }

        // Load-TOD:
        // TOD_LOAD_TOD_REG(@0x21)
        // [00:59] = desired TOD value
        FAPI_DBG("Master: Chip TOD load value (move TB to TOD)");
        FAPI_TRY(PREP_TOD_LOAD_REG(l_target));
        SET_TOD_LOAD_REG_LOAD_TOD_VALUE( P10_TOD_LOAD_REG_LOAD_VALUE , l_data);
        SET_TOD_LOAD_REG_WOF( P10_TOD_LOAD_REG_START_TOD, l_data);
        FAPI_TRY(PUT_TOD_LOAD_REG(l_target, l_data),
                 "Master: Error from PUT_TOD_LOAD_REG");

        // STEP checking enable:
        // TOD_TX_TTYPE_2_REG(@0x13)[00] = 0b1: TX-TTYPE-2
        FAPI_DBG("Master: Chip TOD step checkers enable");
        FAPI_TRY(PREP_TOD_TX_TTYPE_2_REG(l_target));
        l_data.flush<0>();
        SET_TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER(l_data);
        FAPI_TRY(PUT_TOD_TX_TTYPE_2_REG(l_target, l_data),
                 "Master: Error from PUT_TOD_TX_TTYPE_2_REG");

        // Load-TOD-mod:
        // Initiate a TX-TTYPE-5 from the TOD master:
        // TOD_TX_TTYPE_5_REG(@0x16)[00] = 0b1
        FAPI_DBG("Master: switch all Chip TOD in the system to 'Not Set' state");
        FAPI_TRY(PREP_TOD_TX_TTYPE_5_REG(l_target));
        l_data.flush<0>();
        SET_TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER(l_data);
        FAPI_TRY(PUT_TOD_TX_TTYPE_5_REG(l_target, l_data),
                 "Master: Error from PUT_TOD_TX_TTYPE_5_REG");

        // Load-TOD:
        // Initiate a TTYPE-4 from the TOD master:
        // TOD_TX_TTYPE_4_REG(@0x15)[00] = 0b1
        // The TTYPE_4 is not sent out from the Master until the Master TOD FSM
        // is in the 'Running' State, which happens during the SCOM write to the
        // TOD_START register below.
        FAPI_DBG("Master: Send local Chip TOD value to all Chip TODs");
        FAPI_TRY(PREP_TOD_TX_TTYPE_4_REG(l_target));
        l_data.flush<0>();
        SET_TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER(l_data);
        FAPI_TRY(PUT_TOD_TX_TTYPE_4_REG(l_target, l_data),
                 "Master: Error from PUT_TOD_TX_TTYPE_4_REG");

        // Setup the TOD Timer registers for sync_spread.
        if (i_disable_tod_sync_spread == 0)
        {
            FAPI_TRY(sync_spread_setup(i_tod_node), "Error from sync_spread_setup!");
        }

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

    // TODO: Can a better/more reliable estimate of the delay/polling count
    // be calculated here using p10_tod_polling_delay()?
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

        // The Secondary topology is not required to successfully IPL.
        // Add a new error code for Secondary topology failures to distinguish
        // this failure from all other failures, but only if it is the only
        // failure.  Any other failure will cause an assertion first before
        // the end of the HWP.  Continue to the end of the HWP if only the
        // secondary topology fails.

        // NOTE: If the Secondary topology fails, the unmasked TOD error
        // bit will remain set, and the TOD error will potentially propagate
        // out to cause checkstops, if configured to do so.

        if (GET_TOD_ERROR_REG_S_PATH_1_PARITY_ERROR(l_tod_err_reg))
        {
            o_secondary_topology_failed = true;
            // Clear the error locally here, and assert on it later.
            // Leave TOD error bit set.
            l_tod_err_reg.clearBit<TOD_ERROR_REG_S_PATH_1_PARITY_ERROR>();
            *o_failingTodProc = l_target;
        }

        if (GET_TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR(l_tod_err_reg))
        {
            o_secondary_topology_failed = true;
            // Clear the error locally here, and assert on it later.
            // Leave TOD error bit set.
            l_tod_err_reg.clearBit<TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR>();
            *o_failingTodProc = l_target;
        }

        FAPI_ASSERT(!l_tod_err_reg(),
                    fapi2::P10_TOD_INIT_ERROR()
                    .set_TARGET(l_target)
                    .set_TOD_ERROR_REG(l_tod_err_reg),
                    "TOD FIR bit active!");

        FAPI_DBG("Set error mask to runtime configuration");
        FAPI_TRY(PREP_TOD_ERROR_MASK_REG(l_target));
        FAPI_TRY(PUT_TOD_ERROR_MASK_REG(l_target, TOD_ERROR_MASK),
                 "Error from PUT_TOD_ERROR_MASK_REG");
    }

    // recursively configure downstream nodes
    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        FAPI_TRY(init_tod_node(*l_child,
                               i_is_simulation,
                               i_disable_tod_sync_spread,
                               o_failingTodProc,
                               o_secondary_topology_failed),
                 "Failure configuring downstream node!");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Helper function for p10_tod_init to notify QMEs of TOD setup
/// @param[in] i_tod_node Pointer to TOD topology (including FAPI targets)
/// @return FAPI2_RC_SUCCESS if QMEs are successfully notified
///         else error
fapi2::ReturnCode qme_tod_notify(
    const tod_topology_node* i_tod_node)
{
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target;
    FAPI_DBG("Start");

    FAPI_ASSERT((i_tod_node != NULL) &&
                (i_tod_node->i_target != NULL),
                fapi2::P10_TOD_SETUP_NULL_NODE(),
                "Null node or target passed into function!");

    l_target = *(i_tod_node->i_target);

    // Avoid cross-initialization errors
    {
        fapi2::buffer<uint64_t> l_data64;
        auto l_eq_mc  =
            l_target.getMulticast<fapi2::TARGET_TYPE_EQ, fapi2::MULTICAST_OR >(fapi2::MCGROUP_GOOD_EQ);

        FAPI_DBG("Inform QME that TOD is ready for TimeFac Shadowing");
        l_data64.flush<0>().setBit<p10hcd::QME_FLAGS_TOD_SETUP_COMPLETE>();
        FAPI_TRY( putScom( l_eq_mc, QME_FLAGS_WO_OR, l_data64 ) );

        // do scom write to PC to put their state machine in standby so they will accept the TFAC data coming in.
        FAPI_DBG("Reset the core timefac to ACTIVE via PC.COMMON.TFX[0-1]=0b01");

        for (const auto& l_core_target :
             l_target.getChildren<fapi2::TARGET_TYPE_CORE>(fapi2::TARGET_STATE_FUNCTIONAL) )
        {
            fapi2::ATTR_ECO_MODE_Type l_eco_mode;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ECO_MODE, l_core_target, l_eco_mode));

            if (l_eco_mode == fapi2::ENUM_ATTR_ECO_MODE_DISABLED)
            {
                l_data64.flush<0>().setBit<1>();
                FAPI_TRY( putScom( l_core_target, EC_PC_TFX_SM, l_data64 ) );
            }
        }
    }

    // recursively configure downstream nodes
    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        FAPI_TRY(qme_tod_notify(*l_child),
                 "Failure notifying QME TOD in downstream node!");
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
    bool l_secondary_topology_failed = false;
    fapi2::ATTR_IS_SIMULATION_Type l_attr_is_simulation;
    fapi2::ATTR_DISABLE_TOD_SYNC_SPREAD_Type l_disable_tod_sync_spread;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION,
                           fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_attr_is_simulation));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_DISABLE_TOD_SYNC_SPREAD,
                           fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_disable_tod_sync_spread));

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
    FAPI_TRY(init_tod_node(i_tod_node,
                           l_attr_is_simulation,
                           l_disable_tod_sync_spread,
                           o_failingTodProc,
                           l_secondary_topology_failed),
             "Error from init_tod_node!");

    // sync spread across chips in topology
    if (l_disable_tod_sync_spread == 0)
    {
        FAPI_TRY(sync_spread_check(i_tod_node, l_attr_is_simulation),
                 "Error from sync_spread_check!");
    }

    // Notify the QMEs in each node that TOD setup is complete;
    //     (qme_tod_notify will recurse on each child)
    // This is necessary to enable timefac shadowing for STOP operations.
    FAPI_TRY(qme_tod_notify(i_tod_node),
             "Error from qme_tod_notify!");

    // Always check for the secondary topology failure last so other steps
    // are never skipped if this fails.
    FAPI_ASSERT(!l_secondary_topology_failed,
                fapi2::P10_TOD_INIT_SECONDARY_TOPOLOGY_ERROR()
                .set_TARGET(*o_failingTodProc),
                "TOD secondary topology failed!");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
