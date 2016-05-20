/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_tod_move_tod_to_tb.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file p9_tod_move_tod_to_tb.C
/// @brief Procedures to check if move_tod_to_tb works
///
// *HWP HWP Owner Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: None - this is a test for VBU
//
//--------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_tod_move_tod_to_tb.H>

extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode p9_tod_move_tod_to_tb(const tod_topology_node* i_tod_node, const uint8_t i_thread_num,
                                            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* i_failingTodProc )
    {
        fapi2::ReturnCode rc;
        fapi2::buffer<uint64_t> data;
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* target = i_tod_node->i_target;
        uint32_t tod_init_pending_count = 0; // Timeout counter for bits that are cleared by hardware
        uint64_t tfmr_state = 0;
        //bool is_mdmt = true;

        FAPI_DBG("Start");
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE>> l_cores = target->getChildren<fapi2::TARGET_TYPE_CORE>();
        fapi2::Target<fapi2::TARGET_TYPE_CORE> coreTarget = l_cores[0];

        //-------Timebase Setup--------------
        //Read TFMR
        FAPI_TRY(p9_tod_utils_get_tfmr_reg(coreTarget, i_thread_num, data), "Could not read TFMR register");

        //Update TFMR bit (00:15) Timebase settings according to processor frequency
        data.insertFromRight((uint32_t)0xFF, TFMR_MAX_CYC_BET_STEPS, TFMR_MAX_CYC_BET_STEPS_LEN);
        data.insertFromRight(TFMR_N_CLKS_PER_STEP_4CLK, TFMR_N_CLKS_PER_STEP, TFMR_N_CLKS_PER_STEP_LEN);
        data.insertFromRight(TFMR_SYNC_BIT_SEL_16US, TFMR_SYNC_BIT_SEL, TFMR_SYNC_BIT_SEL_LEN);
        data.setBit<TFMR_TB_ECLIPZ>();

        FAPI_TRY(p9_tod_utils_set_tfmr_reg(coreTarget, i_thread_num, data),
                 "Could not write timebase settings according to processor frequency");

        tod_init_pending_count = 0;

        while(tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT)
        {
            FAPI_TRY(fapi2::delay(P9_TOD_UTILS_HW_NS_DELAY, P9_TOD_UTILS_SIM_CYCLE_DELAY), "fapiDelay error");
            FAPI_TRY(p9_tod_utils_get_tfmr_reg(coreTarget, i_thread_num, data), "Could not read TFMR register for polling");
            data.extract(tfmr_state, TFMR_STATE_START_BIT, TFMR_STATE_NUM_BITS, 60);

            if (tfmr_state == TFMR_STATE_TB_RESET)
            {
                FAPI_DBG("TFMR in TB_RESET state");
                break;
            }

            ++tod_init_pending_count;
        }

        FAPI_ASSERT(tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT,
                    fapi2::P9_TOD_INIT_TIMEOUT().set_TARGET(target).set_COUNT(tod_init_pending_count),
                    "TFMR state machine did not go to reset in time!");


        //-------Timebase load_tod_mode_tb(switch Timebase to "Not Set" state)
        //Update TFMR bit (16) = b'1' load_tod_mod_tb. This prepares the time facility logic to accept a new value for the 64-bit Timebase
        data.setBit<TFMR_LOAD_TOD_MOD_TB>();
        FAPI_TRY(p9_tod_utils_set_tfmr_reg(coreTarget, i_thread_num, data), "Could not load_tod_mod_tb");

        //Poll for TFMR bit (16) = b'0'. Hardware clears the bit when the operation is complete. A timeout is indicated by TFMR bit(54) = b'1'
        tod_init_pending_count = 0;

        while(tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT)
        {
            FAPI_TRY(fapi2::delay(P9_TOD_UTILS_HW_NS_DELAY, P9_TOD_UTILS_SIM_CYCLE_DELAY), "fapiDelay error");
            FAPI_TRY(p9_tod_utils_get_tfmr_reg(coreTarget, i_thread_num, data), "Could not read TFMR register for polling");
            data.extract(tfmr_state, TFMR_STATE_START_BIT, TFMR_STATE_NUM_BITS, 60);

            if (!data.getBit<TFMR_LOAD_TOD_MOD_TB>() && (tfmr_state == TFMR_STATE_TB_NOT_SET))
            {
                FAPI_DBG("TFMR_LOAD_TOD_MOD cleared.");
                break;
            }

            ++tod_init_pending_count;
        }

        FAPI_ASSERT(tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT,
                    fapi2::P9_TOD_INIT_TIMEOUT().set_TARGET(target).set_COUNT(tod_init_pending_count),
                    "TFMR_LOAD_TOD_MOD did not clear in time!");

        //-------TOD interrupt check----------------------
        //Read TFMR and check for TFMR(51) = b'0'. This indicates no interrupt pending from the TOD which means no STEP errors were detected, and the external TOD oscillator is operating properly.
        FAPI_TRY(p9_tod_utils_get_tfmr_reg(coreTarget, i_thread_num, data), "Could not read TFMR register to check bit 51");
        FAPI_ASSERT(!data.getBit<51>(), fapi2::P9_TOD_INIT_NOT_RUNNING(),
                    "STEP errors were detected or the external TOD oscillator is not operating properly");

        //------Move TOD value to Timebase---------
        //Update TFMR bit(18) = b'1' move_chip_tod_to_tb. This prepares the time facility logic to accept a new value after a SYNC boundary occurred
        FAPI_TRY(p9_tod_utils_get_tfmr_reg(coreTarget, i_thread_num, data), "Could not read TFMR to move_chip_tod_to_tb");
        data.setBit<TFMR_MOVE_CHIP_TOD_TO_TB>();
        FAPI_TRY(p9_tod_utils_set_tfmr_reg(coreTarget, i_thread_num, data), "Could not write TFMR to mvoe chip_tod_to_tb");

        //We don't check for TB_SYNC_WAIT since that state is fleeting

        tod_init_pending_count = 0;

        while(tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT)
        {
            FAPI_TRY(fapi2::delay(P9_TOD_UTILS_HW_NS_DELAY, P9_TOD_UTILS_SIM_CYCLE_DELAY), "fapiDelay error");
            FAPI_TRY(p9_tod_utils_get_tfmr_reg(coreTarget, i_thread_num, data), "Could not read TFMR register for polling");
            data.extract(tfmr_state, TFMR_STATE_START_BIT, TFMR_STATE_NUM_BITS, 60);

            if (tfmr_state == TFMR_STATE_GET_TOD)
            {
                FAPI_DBG("TFMR in GET_TOD state");
                break;
            }

            ++tod_init_pending_count;
        }

        FAPI_ASSERT(tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT,
                    fapi2::P9_TOD_INIT_TIMEOUT().set_TARGET(target).set_COUNT(tod_init_pending_count),
                    "TFMR state machine did not go to get_tod in time!");


        //Write TOD_MOVE_TOD_TO_TB_REG(@0x17)[00]=b'1'(move TOD to Timebase). The TOD transfers the TOD value to the Timebase after a SYNC boundary occurred. Note that TOD_TX_TTYPE_CTRL_REG(@0x27)[24:31] needs to be configured before issuing a TOD transfer to Timebase.The address of the PIB slave targeted by the TOD PIB master is configured as 0xNN0126a1 where NN is the configurable slave address specified in TOD_TX_TTYPE_CTRL_REG(@0x27)[24:31].
        // TODO: read PIR and set for each core
        data.flush<0>();
        /*data.insertFromRight(TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_MST_ADDR_CFG_C5,
                             TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_MST_ADDR_CFG, TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_MST_ADDR_CFG_LEN);*/
        data.insertFromRight(0x2E010AA310000000, 0, 64);
        //data.setBit<25>().setBit<27>();
        FAPI_TRY(fapi2::putScom(*target, PERV_TOD_TX_TTYPE_CTRL_REG, data), "Could not write PERV_TOD_TX_TTYPE_CTRL_REG");

        data.flush<0>();
        data.setBit<0>();
        FAPI_TRY(fapi2::putScom(*target, PERV_TOD_MOVE_TOD_TO_TB_REG, data), "Could not write TOD_MOVE_TOD_TO_TB_REG");

        tod_init_pending_count = 0;

        while(tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT)
        {
            FAPI_TRY(fapi2::delay(P9_TOD_UTILS_HW_NS_DELAY, P9_TOD_UTILS_SIM_CYCLE_DELAY), "fapiDelay error");
            FAPI_TRY(p9_tod_utils_get_tfmr_reg(coreTarget, i_thread_num, data), "Could not read TFMR register for polling");
            data.extract(tfmr_state, TFMR_STATE_START_BIT, TFMR_STATE_NUM_BITS, 60);

            if (tfmr_state == TFMR_STATE_TB_RUNNING)
            {
                FAPI_DBG("TFMR in TB_RUNNING state");
                break;
            }

            ++tod_init_pending_count;
        }

        FAPI_ASSERT(tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT,
                    fapi2::P9_TOD_INIT_TIMEOUT().set_TARGET(target).set_COUNT(tod_init_pending_count),
                    "TFMR state machine did not go to TB_RUNNING in time!");

        tod_init_pending_count = 0;

        //Poll for TFMR bit(18) = b'0'. Hardware clears the bit when the operation is complete.
        while(tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT)
        {
            FAPI_TRY(fapi2::delay(P9_TOD_UTILS_HW_NS_DELAY, P9_TOD_UTILS_SIM_CYCLE_DELAY), "fapiDelay error");
            FAPI_TRY(p9_tod_utils_get_tfmr_reg(coreTarget, i_thread_num, data), "Could not read TFMR");

            if (!data.getBit<TFMR_MOVE_CHIP_TOD_TO_TB>())
            {
                FAPI_DBG("TFMR_MOVE_CHIP_TOD_TO_TB cleared.");
                break;
            }

            ++tod_init_pending_count;
        }

        FAPI_ASSERT(tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT,
                    fapi2::P9_TOD_INIT_TIMEOUT().set_TARGET(target).set_COUNT(tod_init_pending_count),
                    "TFMR_MOVE_CHIP_TOD_TO_TB did not clear in time!");

        // Finish configuring downstream nodes
        for (std::list<tod_topology_node*>::const_iterator child = (i_tod_node->i_children).begin();
             child != (i_tod_node->i_children).end();
             ++child)
        {
            tod_topology_node* tod_node = *child;
            FAPI_TRY(p9_tod_move_tod_to_tb(tod_node, i_thread_num, i_failingTodProc), "Failure configuring downstream node!");
        }


    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

} // extern "C"
