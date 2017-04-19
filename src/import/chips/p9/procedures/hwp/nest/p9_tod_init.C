/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_tod_init.C $       */
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
//
//
/// @file p9_tod_init.C
/// @brief Procedures to initialize the TOD to 'running' state
///
// *HWP HWP Owner: Nick Klazynski jklazyns@us.ibm.com
// *HWP HWP Owner: Joachim Fenkes fenkes@de.ibm.com
// *HWP FW Owner: Manish Chowdhary manichow@in.ibm.com
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: HB
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_tod_init.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// @brief Clears TOD error register
/// @param[in] i_tod_node Pointer to TOD topology (including FAPI targets)
/// @return FAPI_RC_SUCCESS if TOD topology is cleared of previous errors
///         else FAPI or ECMD error is sent through
fapi2::ReturnCode p9_tod_clear_error_reg(const tod_topology_node* i_tod_node)

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
        FAPI_TRY(p9_tod_clear_error_reg(*l_child),
                 "Failure clearing errors from downstream node!");
    }

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}


/// @brief Helper function for p9_tod_init
/// @param[in] i_tod_node Pointer to TOD topology (including FAPI targets)
/// @param[out] o_failingTodProc Pointer to the fapi target, will be populated
///             with processor target unable to receive proper signals from OSC.
//              Caller needs to look at this parameter only when p9_tod_init
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

    while (l_tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT)
    {
        FAPI_DBG("Waiting for TOD to assert TOD_FSM_REG_TOD_IS_RUNNING...");
        FAPI_TRY(fapi2::delay(P9_TOD_UTILS_HW_NS_DELAY, P9_TOD_UTILS_SIM_CYCLE_DELAY),
                 "Error from delay!");
        FAPI_TRY(fapi2::getScom(*(i_tod_node->i_target),
                                PERV_TOD_FSM_REG,
                                l_tod_fsm_reg),
                 "Error from getScom (PERV_TOD_FSM_REG)!");

        if (l_tod_fsm_reg.getBit<PERV_TOD_FSM_REG_IS_RUNNING>())
        {
            FAPI_DBG("TOD is running!");
            break;
        }

        ++l_tod_init_pending_count;
    }

    FAPI_ASSERT((l_tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT),
                fapi2::P9_TOD_INIT_NOT_RUNNING()
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
                    fapi2::P9_TOD_INIT_M_PATH_0_STEP_CHECK_ERROR()
                    .set_TARGET(*(i_tod_node->i_target))
                    .set_TOD_ERROR_REG(l_tod_err_reg),
                    "M_PATH_0_STEP_CHECK_ERROR!");
        FAPI_ASSERT(!l_tod_err_reg.getBit<PERV_TOD_ERROR_REG_M_PATH_1_STEP_CHECK>(),
                    fapi2::P9_TOD_INIT_M_PATH_1_STEP_CHECK_ERROR()
                    .set_TARGET(*(i_tod_node->i_target))
                    .set_TOD_ERROR_REG(l_tod_err_reg),
                    "M_PATH_1_STEP_CHECK_ERROR!");
        FAPI_ASSERT(!l_tod_err_reg(),
                    fapi2::P9_TOD_INIT_ERROR()
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
fapi2::ReturnCode p9_tod_init(
    const tod_topology_node* i_tod_node,
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* o_failingTodProc)
{
    FAPI_DBG("Start");

    // Clear the error register so we don't get any "fake" errors
    FAPI_TRY(p9_tod_clear_error_reg(i_tod_node),
             "Error from p9_tod_clear_error_reg!");

    // Start configuring each node; (init_tod_node will recurse on each child)
    FAPI_TRY(init_tod_node(i_tod_node, o_failingTodProc),
             "Error from init_tod_node!");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}
