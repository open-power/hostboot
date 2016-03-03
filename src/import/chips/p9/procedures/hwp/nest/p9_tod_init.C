/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_tod_init.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
//--------------------------------------------------------------------------
//
//
/// @file p9_tod_init.C
/// @brief Procedures to initialize the TOD to 'running' state
///
// *HWP HWP Owner Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: SBE
//
//--------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_tod_init.H>

extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode p9_tod_init(const tod_topology_node* i_tod_node,
                                  fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* i_failingTodProc )
    {
        FAPI_DBG("Start");

        FAPI_TRY(p9_tod_clear_error_reg(i_tod_node), "Failure clearing TOD error registers!");

        //Start configuring each node; (init_tod_node will recurse on each child)
        FAPI_TRY(init_tod_node(i_tod_node, i_failingTodProc), "Failure initializing TOD!");

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    //------------------------------------------------------------------------------
    /// @brief p9_tod_clear_error_reg
    /// @param[in] i_tod_node => Reference to TOD topology (FAPI targets included within)
    /// @return FAPI_RC_SUCCESS if every TOD node is cleared of errors
    ///          else FAPI or ECMD error is sent through
    //------------------------------------------------------------------------------
    fapi2::ReturnCode p9_tod_clear_error_reg(const tod_topology_node* i_tod_node)
    {
        fapi2::buffer<uint64_t> data;
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* target = i_tod_node->i_target;

        FAPI_DBG("Start");

        FAPI_DBG("Clear any previous errors from PERV_TOD_ERROR_REG");
        data.flush<1>();
        FAPI_TRY(fapi2::putScom(*target, PERV_TOD_ERROR_REG, data), "Could not write PERV_TOD_ERROR_REG.");

        for (std::list<tod_topology_node*>::const_iterator child = (i_tod_node->i_children).begin();
             child != (i_tod_node->i_children).end();
             ++child)
        {
            tod_topology_node* tod_node = *child;
            FAPI_TRY(p9_tod_clear_error_reg(tod_node), "Failure clearing errors from downstream node!");
        }

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode init_tod_node(const tod_topology_node* i_tod_node,
                                    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* i_failingTodProc)
    {
        fapi2::ReturnCode rc;
        fapi2::buffer<uint64_t> data;
        uint32_t tod_init_pending_count = 0; // Timeout counter for bits that are cleared by hardware
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* target = i_tod_node->i_target;

        FAPI_DBG("Start");

        const bool is_mdmt = (i_tod_node->i_tod_master && i_tod_node->i_drawer_master);

        if (is_mdmt)
        {
            FAPI_DBG("Master: Chip TOD step checkers enable");
            data.flush<0>().setBit<0>();
            FAPI_TRY(fapi2::putScom(*target, PERV_TOD_TX_TTYPE_2_REG, data), "Could not write PERV_TOD_TX_TTYPE_2_REG.");

            FAPI_DBG("Master: switch local Chip TOD to 'Not Set' state");
            data.flush<0>().setBit<PERV_TOD_LOAD_TOD_MOD_REG_FSM_TRIGGER>();
            FAPI_TRY(fapi2::putScom(*target, PERV_TOD_LOAD_TOD_MOD_REG, data), "Master: Could not write PERV_TOD_LOAD_TOD_MOD_REG");

            FAPI_DBG("Master: switch all Chip TOD in the system to 'Not Set' state");
            data.flush<0>().setBit<0>();
            FAPI_TRY(fapi2::putScom(*target, PERV_TOD_TX_TTYPE_5_REG, data), "Master: Could not write PERV_TOD_TX_TTYPE_5_REG");

            FAPI_DBG("Master: Chip TOD load value (move TB to TOD)");
            data.flush<0>();
            data.insertFromRight(0x00000000, 0, 32);
            data.insertFromRight(0x3FFE, 50, 13); // bits 50:62 must be 1s
            FAPI_TRY(fapi2::putScom(*target, PERV_TOD_LOAD_TOD_REG, data), "Master: Could not write PERV_TOD_LOAD_TOD_REG");

            FAPI_DBG("Master: Chip TOD start_tod (switch local Chip TOD to 'Running' state)");
            data.flush<0>().setBit<PERV_TOD_START_TOD_REG_FSM_TRIGGER>();
            FAPI_TRY(fapi2::putScom(*target, PERV_TOD_START_TOD_REG, data), "Master: Could not write PERV_TOD_START_TOD_REG");

            FAPI_DBG("Master: Send local Chip TOD value to all Chip TODs");
            data.flush<0>().setBit<0>();
            FAPI_TRY(fapi2::putScom(*target, PERV_TOD_TX_TTYPE_4_REG, data), "Master: Could not write PERV_TOD_TX_TTYPE_4_REG");
        }

        FAPI_DBG("Check TOD is Running");
        tod_init_pending_count = 0;

        while (tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT)
        {
            FAPI_DBG("Waiting for TOD to assert TOD_FSM_REG_TOD_IS_RUNNING...");

            FAPI_TRY(fapi2::delay(P9_TOD_UTILS_HW_NS_DELAY, P9_TOD_UTILS_SIM_CYCLE_DELAY), "fapiDelay error");
            FAPI_TRY(fapi2::getScom(*target, PERV_TOD_FSM_REG, data), "Could not retrieve PERV_TOD_FSM_REG");

            if (data.getBit<PERV_TOD_FSM_REG_IS_RUNNING>())
            {
                FAPI_DBG("TOD is running!");
                break;
            }

            ++tod_init_pending_count;
        }

        FAPI_ASSERT((tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT),
                    fapi2::P9_TOD_INIT_NOT_RUNNING().set_TARGET(target).set_COUNT(tod_init_pending_count),
                    "TOD is not running! (It should be)");

        FAPI_DBG("clear TTYPE#2, TTYPE#4, and TTYPE#5 status");
        data.flush<0>();
        data.setBit<PERV_TOD_ERROR_REG_RX_TTYPE_2>();
        data.setBit<PERV_TOD_ERROR_REG_RX_TTYPE_4>();
        data.setBit<PERV_TOD_ERROR_REG_RX_TTYPE_5>();
        FAPI_TRY(fapi2::putScom(*target, PERV_TOD_ERROR_REG, data), "Could not write PERV_TOD_ERROR_REG.");

        FAPI_DBG("checking for TOD errors");
        FAPI_TRY(fapi2::getScom(*target, PERV_TOD_ERROR_REG, data), "Could not read PERV_TOD_ERROR_REG.");

        FAPI_ASSERT((!data.getBit<PERV_TOD_ERROR_REG_M_PATH_0_STEP_CHECK>()),
                    fapi2::P9_TOD_INIT_M_PATH_0_STEP_CHECK_ERROR().set_TARGET(target).set_DATA(data),
                    "M_PATH_0_STEP_CHECK_ERROR!");
        FAPI_ASSERT((!data.getBit<PERV_TOD_ERROR_REG_M_PATH_1_STEP_CHECK>()),
                    fapi2::P9_TOD_INIT_M_PATH_1_STEP_CHECK_ERROR().set_TARGET(target).set_DATA(data),
                    "M_PATH_1_STEP_CHECK_ERROR!");
        FAPI_ASSERT((data == 0), fapi2::P9_TOD_INIT_ERROR().set_TARGET(target).set_DATA(data),
                    "FIR bit active!");

        FAPI_DBG("set error mask to runtime configuration");
        data.flush<0>();
        data.insertFromRight(0x3F, 38, 6); // Mask TTYPE received informational bits 38:43
        FAPI_TRY(fapi2::putScom(*target, PERV_TOD_ERROR_MASK_REG, data), "Could not write PERV_TOD_ERROR_MASK_REG");

        // Finish configuring downstream nodes
        for (std::list<tod_topology_node*>::const_iterator child = (i_tod_node->i_children).begin();
             child != (i_tod_node->i_children).end();
             ++child)
        {
            tod_topology_node* tod_node = *child;
            FAPI_TRY(init_tod_node(tod_node, i_failingTodProc), "Failure configuring downstream node!");
        }

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

} // extern "C"
