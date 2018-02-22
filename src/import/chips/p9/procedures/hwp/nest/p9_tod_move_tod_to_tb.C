/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_tod_move_tod_to_tb.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
// *HWP HWP Owner: Nick Klazynski jklazyns@us.ibm.com
// *HWP HWP Owner: Joachim Fenkes fenkes@de.ibm.com
// *HWP FW Owner: Manish Chowdhary manichow@in.ibm.com
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: Cronus only
//
//--------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_tod_move_tod_to_tb.H>


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// @brief Sets the value in the TFMR register
/// @param[in] i_target P9 core unit target
/// @param[in] i_thread_num Thread number to target
/// @param[in] i_tfmr_val Value that will be put in the TFMR register
/// @return FAPI_RC_SUCCESS if TFMR write is successful else error
fapi2::ReturnCode p9_tod_utils_set_tfmr_reg(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
    const uint8_t i_thread_num,
    fapi2::buffer<uint64_t>& i_tfmr_val)
{
    // mark HWP entry
    FAPI_DBG("Entering ...");

    // Setting SPR_MODE to thread number
    // Setting SPRC to thread's TMFR
    fapi2::buffer<uint64_t> l_spr_mode = 0;
    fapi2::buffer<uint64_t> l_scomc = 0;
    l_spr_mode.setBit<SPR_MODE_REG_MODE_SPRC_WR_EN>()
    .setBit<SPR_MODE_REG_MODE_SPRC0_SEL>();

    switch(i_thread_num)
    {
        case(0):
            l_spr_mode.setBit<C_SPR_MODE_MODEREG_SPRC_LT0_SEL>();
            l_scomc.insertFromRight<SPRC_REG_SEL, SPRC_REG_SEL_LEN>(SPRC_REG_SEL_TFMR_T0);
            break;

        case(1):
            l_spr_mode.setBit<C_SPR_MODE_MODEREG_SPRC_LT1_SEL>();
            l_scomc.insertFromRight<SPRC_REG_SEL, SPRC_REG_SEL_LEN>(SPRC_REG_SEL_TFMR_T1);
            break;

        case(2):
            l_spr_mode.setBit<C_SPR_MODE_MODEREG_SPRC_LT2_SEL>();
            l_scomc.insertFromRight<SPRC_REG_SEL, SPRC_REG_SEL_LEN>(SPRC_REG_SEL_TFMR_T2);
            break;

        case(3):
            l_spr_mode.setBit<C_SPR_MODE_MODEREG_SPRC_LT3_SEL>();
            l_scomc.insertFromRight<SPRC_REG_SEL, SPRC_REG_SEL_LEN>(SPRC_REG_SEL_TFMR_T3);
            break;

        case(4):
            l_spr_mode.setBit<C_SPR_MODE_MODEREG_SPRC_LT4_SEL>();
            l_scomc.insertFromRight<SPRC_REG_SEL, SPRC_REG_SEL_LEN>(SPRC_REG_SEL_TFMR_T4);
            break;

        case(5):
            l_spr_mode.setBit<C_SPR_MODE_MODEREG_SPRC_LT5_SEL>();
            l_scomc.insertFromRight<SPRC_REG_SEL, SPRC_REG_SEL_LEN>(SPRC_REG_SEL_TFMR_T5);
            break;

        case(6):
            l_spr_mode.setBit<C_SPR_MODE_MODEREG_SPRC_LT6_SEL>();
            l_scomc.insertFromRight<SPRC_REG_SEL, SPRC_REG_SEL_LEN>(SPRC_REG_SEL_TFMR_T6);
            break;

        case(7):
            l_spr_mode.setBit<C_SPR_MODE_MODEREG_SPRC_LT7_SEL>();
            l_scomc.insertFromRight<SPRC_REG_SEL, SPRC_REG_SEL_LEN>(SPRC_REG_SEL_TFMR_T7);
            break;

        default:
            FAPI_ASSERT(true,
                        fapi2::P9_TOD_MOVE_TOD_TO_TB_INVALID_THREAD_NUM()
                        .set_TARGET(i_target)
                        .set_THREAD_NUMBER(i_thread_num),
                        "Invaild thread number!");
    }

    FAPI_TRY(fapi2::putScom(i_target, C_SPR_MODE, l_spr_mode),
             "Error from putScom (C_SPR_MODE)!");

    FAPI_TRY(fapi2::putScom(i_target, C_SCOMC, l_scomc),
             "Error from putScom (C_SPRC)!");

    // Writing SPRD to set the thread's TMFR
    FAPI_TRY(fapi2::putScom(i_target, C_SCOMD, i_tfmr_val),
             "Error from putScom (C_SCOMD)!");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}


/// @brief Gets the value in the TFMR register
/// @param[in] i_target P9 core unit target
/// @param[in] i_thread_num Thread number to target
/// @param[out] o_tfmr_val Value that is in the TFMR register
/// @return FAPI_RC_SUCCESS if TFMR read is successful else error
fapi2::ReturnCode p9_tod_utils_get_tfmr_reg(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
    const uint8_t i_thread_num,
    fapi2::buffer<uint64_t>& o_tfmr_val)
{
    // mark HWP entry
    FAPI_DBG("Entering ...");

    // Setting SPR_MODE to thread number
    // Setting SPRC to thread's TMFR
    fapi2::buffer<uint64_t> l_spr_mode = 0;
    fapi2::buffer<uint64_t> l_scomc = 0;
    l_spr_mode.setBit<SPR_MODE_REG_MODE_SPRC_WR_EN>()
    .setBit<SPR_MODE_REG_MODE_SPRC0_SEL>();

    switch(i_thread_num)
    {
        case(0):
            l_spr_mode.setBit<C_SPR_MODE_MODEREG_SPRC_LT0_SEL>();
            l_scomc.insertFromRight<SPRC_REG_SEL, SPRC_REG_SEL_LEN>(SPRC_REG_SEL_TFMR_T0);
            break;

        case(1):
            l_spr_mode.setBit<C_SPR_MODE_MODEREG_SPRC_LT1_SEL>();
            l_scomc.insertFromRight<SPRC_REG_SEL, SPRC_REG_SEL_LEN>(SPRC_REG_SEL_TFMR_T1);
            break;

        case(2):
            l_spr_mode.setBit<C_SPR_MODE_MODEREG_SPRC_LT2_SEL>();
            l_scomc.insertFromRight<SPRC_REG_SEL, SPRC_REG_SEL_LEN>(SPRC_REG_SEL_TFMR_T2);
            break;

        case(3):
            l_spr_mode.setBit<C_SPR_MODE_MODEREG_SPRC_LT3_SEL>();
            l_scomc.insertFromRight<SPRC_REG_SEL, SPRC_REG_SEL_LEN>(SPRC_REG_SEL_TFMR_T3);
            break;

        case(4):
            l_spr_mode.setBit<C_SPR_MODE_MODEREG_SPRC_LT4_SEL>();
            l_scomc.insertFromRight<SPRC_REG_SEL, SPRC_REG_SEL_LEN>(SPRC_REG_SEL_TFMR_T4);
            break;

        case(5):
            l_spr_mode.setBit<C_SPR_MODE_MODEREG_SPRC_LT5_SEL>();
            l_scomc.insertFromRight<SPRC_REG_SEL, SPRC_REG_SEL_LEN>(SPRC_REG_SEL_TFMR_T5);
            break;

        case(6):
            l_spr_mode.setBit<C_SPR_MODE_MODEREG_SPRC_LT6_SEL>();
            l_scomc.insertFromRight<SPRC_REG_SEL, SPRC_REG_SEL_LEN>(SPRC_REG_SEL_TFMR_T6);
            break;

        case(7):
            l_spr_mode.setBit<C_SPR_MODE_MODEREG_SPRC_LT7_SEL>();
            l_scomc.insertFromRight<SPRC_REG_SEL, SPRC_REG_SEL_LEN>(SPRC_REG_SEL_TFMR_T7);
            break;

        default:
            FAPI_ASSERT(true,
                        fapi2::P9_TOD_MOVE_TOD_TO_TB_INVALID_THREAD_NUM()
                        .set_TARGET(i_target)
                        .set_THREAD_NUMBER(i_thread_num),
                        "Invaild thread number!");
    }

    FAPI_TRY(fapi2::putScom(i_target, C_SPR_MODE, l_spr_mode),
             "Error from putScom (C_SPR_MODE)!");

    FAPI_TRY(fapi2::putScom(i_target, C_SCOMC, l_scomc),
             "Error from putScom (C_SCOMC)!");

    // Reading SPRD for the thread's TMFR
    FAPI_TRY(fapi2::getScom(i_target,  C_SCOMD, o_tfmr_val),
             "Error from getScom (C_SCOMD)!");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}


// NOTE: description in header
fapi2::ReturnCode p9_tod_move_tod_to_tb(
    const tod_topology_node* i_tod_node,
    const uint8_t i_thread_num,
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* i_failingTodProc)
{
    fapi2::buffer<uint64_t> data;
    bool l_fused_core = false;

    FAPI_DBG("Start");

    // Get all the cores on this proc chip
    auto l_core_targets = i_tod_node->i_target->getChildren<fapi2::TARGET_TYPE_CORE>(
                              fapi2::TARGET_STATE_FUNCTIONAL);

    // Check if we are in fused mode
    if (l_core_targets.size() > 0)
    {
        fapi2::buffer<uint64_t> l_thread_state;
        FAPI_TRY(fapi2::getScom(l_core_targets[0],
                                C_CORE_THREAD_STATE,
                                l_thread_state),
                 "Error from getScom (C_CORE_THREAD_STATE)");

        if (l_thread_state.getBit<C_CORE_THREAD_STATE_LPAR_FUSED_CORE_MODE>())
        {
            l_fused_core = true;
            FAPI_DBG("Fused-core mode enabled");
        }
        else
        {
            l_fused_core = false;
            FAPI_DBG("Normal-core mode is enabled");
        }
    }

    for (auto l_core_target : l_core_targets)
    {
        uint8_t l_core_id = 0x0;
        fapi2::buffer<uint64_t> l_tfmr_reg;
        fapi2::buffer<uint64_t> l_tod_tx_ttype_ctrl_reg = 0;
        fapi2::buffer<uint64_t> l_move_tod_to_tb_reg = 0;
        uint64_t l_tfmr_state = 0;
        uint32_t l_tod_init_pending_count = 0;

        // Only run this on even cores if we are in fused core mode
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                               l_core_target,
                               l_core_id),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)!");

        if ((!l_fused_core) || (l_core_id % 2 == 0))
        {
            FAPI_DBG("Going to work on core %d", l_core_id);

            // -------Timebase Setup--------------
            // Read TFMR
            FAPI_TRY(p9_tod_utils_get_tfmr_reg(l_core_target,
                                               i_thread_num,
                                               l_tfmr_reg),
                     "Error from p9_tod_utils_get_tfmr_reg (setup for reset)");

            // Update TFMR bit (00:15) Timebase settings according to processor frequency
            l_tfmr_reg.setBit<CAPP_TFMR_MAX_CYC_BET_STEPS, CAPP_TFMR_MAX_CYC_BET_STEPS_LEN>()
            .insertFromRight<CAPP_TFMR_N_CLKS_PER_STEP, CAPP_TFMR_N_CLKS_PER_STEP_LEN>(TFMR_N_CLKS_PER_STEP_4CLK)
            .insertFromRight<CAPP_TFMR_SYNC_BIT_SEL, CAPP_TFMR_SYNC_BIT_SEL_LEN>(TFMR_SYNC_BIT_SEL_16US)
            .setBit<CAPP_TFMR_TB_ECLIPZ>();

            FAPI_TRY(p9_tod_utils_set_tfmr_reg(l_core_target,
                                               i_thread_num,
                                               l_tfmr_reg),
                     "Error from p9_tod_utils_set_tfmr_reg (setup for 'reset')");

            while (l_tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT)
            {
                FAPI_TRY(fapi2::delay(P9_TOD_UTILS_HW_NS_DELAY,
                                      P9_TOD_UTILS_SIM_CYCLE_DELAY),
                         "Error from delay");
                FAPI_TRY(p9_tod_utils_get_tfmr_reg(l_core_target,
                                                   i_thread_num,
                                                   l_tfmr_reg),
                         "Error from p9_tod_utils_get_tfmr_reg (poll for 'reset')");

                l_tfmr_reg.extractToRight<CAPP_TFMR_TBST_ENCODED,
                                          CAPP_TFMR_TBST_ENCODED_LEN>(l_tfmr_state);

                if (l_tfmr_state == TFMR_STATE_TB_RESET)
                {
                    FAPI_DBG("TFMR in TB_RESET state");
                    break;
                }

                ++l_tod_init_pending_count;
            }

            FAPI_ASSERT(l_tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT,
                        fapi2::P9_TOD_MOVE_TOD_TO_TB_INIT_TIMEOUT()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_COUNT(l_tod_init_pending_count)
                        .set_TFMR_STATE(l_tfmr_state)
                        .set_TFMR_EXPECTED_STATE(TFMR_STATE_TB_RESET)
                        .set_TFMR_REG(l_tfmr_reg),
                        "Timeout waiting for TFMR state machine to reach 'reset' state!");

            // -------Timebase load_tod_mode_tb (switch TB to "Not Set" state)
            // Update TFMR bit (16) = b'1' load_tod_mod_tb.
            // This prepares the time facility logic to accept a new value for
            // the 64-bit Timebase
            l_tfmr_reg.setBit<CAPP_TFMR_LOAD_TOD_MOD>();
            FAPI_TRY(p9_tod_utils_set_tfmr_reg(l_core_target,
                                               i_thread_num,
                                               l_tfmr_reg),
                     "Error from p9_tod_utils_set_tfmr_reg (setup for 'not set')");

            // Poll for TFMR bit (16) = b'0'. Hardware clears the bit when the
            // operation is complete. A timeout is indicated by
            // TFMR bit(54) = b'1'
            l_tod_init_pending_count = 0;

            while (l_tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT)
            {
                FAPI_TRY(fapi2::delay(P9_TOD_UTILS_HW_NS_DELAY,
                                      P9_TOD_UTILS_SIM_CYCLE_DELAY),
                         "Error from delay");
                FAPI_TRY(p9_tod_utils_get_tfmr_reg(l_core_target,
                                                   i_thread_num,
                                                   l_tfmr_reg),
                         "Error from p9_tod_utils_get_tfmr_reg (poll for 'not set')");
                l_tfmr_reg.extractToRight<CAPP_TFMR_TBST_ENCODED,
                                          CAPP_TFMR_TBST_ENCODED_LEN>(l_tfmr_state);

                if ((!l_tfmr_reg.getBit<CAPP_TFMR_LOAD_TOD_MOD>()) &&
                    ((uint32_t) l_tfmr_state == TFMR_STATE_TB_NOT_SET))
                {
                    FAPI_DBG("TFMR_LOAD_TOD_MOD cleared.");
                    break;
                }

                ++l_tod_init_pending_count;
            }

            FAPI_ASSERT(l_tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT,
                        fapi2::P9_TOD_MOVE_TOD_TO_TB_INIT_TIMEOUT()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_COUNT(l_tod_init_pending_count)
                        .set_TFMR_STATE(l_tfmr_state)
                        .set_TFMR_EXPECTED_STATE(TFMR_STATE_TB_NOT_SET)
                        .set_TFMR_REG(l_tfmr_reg),
                        "Timeout waiting for TFMR state machine to reach 'not set' state!");

            // -------TOD interrupt check----------------------
            // Read TFMR and check for TFMR(51) = b'0'. This indicates no
            // interrupt pending from the TOD which means no STEP errors were
            // detected, and the external TOD oscillator is operating properly.
            FAPI_TRY(p9_tod_utils_get_tfmr_reg(l_core_target,
                                               i_thread_num,
                                               l_tfmr_reg),
                     "Error from p9_tod_utils_get_tfmr_reg (interrupt check)");
            FAPI_ASSERT(!l_tfmr_reg.getBit<CAPP_TFMR_CHIP_TOD_INTERRUPT>(),
                        fapi2::P9_TOD_MOVE_TOD_TO_TB_INIT_ERROR()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_TFMR_REG(l_tfmr_reg),
                        "TOD interrupt detected!");

            // ------Move TOD value to Timebase---------
            // Update TFMR bit(18) = b'1' move_chip_tod_to_tb. This prepares the
            // time facility logic to accept a new value after a SYNC boundary
            // occurred
            FAPI_TRY(p9_tod_utils_get_tfmr_reg(l_core_target,
                                               i_thread_num,
                                               l_tfmr_reg),
                     "Error from p9_tod_utils_get_tfmr_reg (setup for 'get_tod')");
            l_tfmr_reg.setBit<CAPP_TFMR_MOVE_CHIP_TOD_TO_TB>();
            FAPI_TRY(p9_tod_utils_set_tfmr_reg(l_core_target,
                                               i_thread_num,
                                               l_tfmr_reg),
                     "Error from p9_tod_utils_set_tfmr_reg (setup for 'get_tod')");

            // We don't check for TB_SYNC_WAIT since that state is fleeting
            l_tod_init_pending_count = 0;

            while (l_tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT)
            {
                FAPI_TRY(fapi2::delay(P9_TOD_UTILS_HW_NS_DELAY,
                                      P9_TOD_UTILS_SIM_CYCLE_DELAY),
                         "Error from delay");
                FAPI_TRY(p9_tod_utils_get_tfmr_reg(l_core_target,
                                                   i_thread_num,
                                                   l_tfmr_reg),
                         "Error from p9_tod_utils_get_tfmr_reg (poll for 'get_tod')");
                l_tfmr_reg.extractToRight<CAPP_TFMR_TBST_ENCODED,
                                          CAPP_TFMR_TBST_ENCODED_LEN>(l_tfmr_state);

                if ((uint32_t) l_tfmr_state == TFMR_STATE_GET_TOD)
                {
                    FAPI_DBG("TFMR in GET_TOD state");
                    break;
                }

                ++l_tod_init_pending_count;
            }

            FAPI_ASSERT(l_tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT,
                        fapi2::P9_TOD_MOVE_TOD_TO_TB_INIT_TIMEOUT()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_COUNT(l_tod_init_pending_count)
                        .set_TFMR_STATE(l_tfmr_state)
                        .set_TFMR_EXPECTED_STATE(TFMR_STATE_GET_TOD)
                        .set_TFMR_REG(l_tfmr_reg),
                        "Timeout waiting for TFMR state machine to reach 'get_tod' state!");

            // Write TOD_MOVE_TOD_TO_TB_REG(@0x17)[00]=b'1'. The TOD
            // transfers the TOD value to the Timebase after a SYNC boundary
            // occurred. Note that TOD_TX_TTYPE_CTRL_REG(@0x27)[24:31] needs to
            // be configured before issuing a TOD transfer to Timebase.
            // The address of the PIB slave targeted by the TOD PIB master is
            // configured as 0xNN0126a1 where NN is the configurable slave
            // address specified in TOD_TX_TTYPE_CTRL_REG(@0x27)[24:31].
            // add core unit position to 0x20 ("base" chiplet number for unit 0)
            l_core_id = l_core_id + 0x20;
            l_tod_tx_ttype_ctrl_reg.insertFromRight <
            PERV_TOD_TX_TTYPE_CTRL_REG_MOVE_TO_TB_CORE_ADDRESS,
            PERV_TOD_TX_TTYPE_CTRL_REG_MOVE_TO_TB_CORE_ID_LEN > (l_core_id);

            // This will go to the TOD_READ register (0x20010AA3) for the core
            // that we are currently targeting
            l_tod_tx_ttype_ctrl_reg |= PERV_TOD_TX_TTYPE_CTRL_REG_MASK_VALUE;
            FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                                    PERV_TOD_TX_TTYPE_CTRL_REG,
                                    l_tod_tx_ttype_ctrl_reg),
                     "Error from putScom (PERV_TOD_TX_TTYPE_CTRL_REG)!");

            l_move_tod_to_tb_reg.setBit<PERV_TOD_MOVE_TOD_TO_TB_REG_TRIGGER>();
            FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                                    PERV_TOD_MOVE_TOD_TO_TB_REG,
                                    l_move_tod_to_tb_reg),
                     "Error from putScom (PERV_TOD_MOVE_TOD_TO_TB_REG)!");

            l_tod_init_pending_count = 0;

            while (l_tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT)
            {
                FAPI_TRY(fapi2::delay(P9_TOD_UTILS_HW_NS_DELAY,
                                      P9_TOD_UTILS_SIM_CYCLE_DELAY),
                         "Error from delay");
                FAPI_TRY(p9_tod_utils_get_tfmr_reg(l_core_target,
                                                   i_thread_num,
                                                   l_tfmr_reg),
                         "Error from p9_tod_utils_get_tfmr_reg (poll for 'tod_running')");
                l_tfmr_reg.extractToRight<CAPP_TFMR_TBST_ENCODED,
                                          CAPP_TFMR_TBST_ENCODED_LEN>(l_tfmr_state);



                if ((uint32_t) l_tfmr_state == TFMR_STATE_TB_RUNNING)
                {
                    FAPI_DBG("TFMR in TB_RUNNING state");
                    break;
                }
                else
                {
                    FAPI_DBG("TFMR Reg: %016llX", l_tfmr_reg());
                    FAPI_DBG("State: %X", l_tfmr_state);
                }

                ++l_tod_init_pending_count;
            }

            FAPI_ASSERT(l_tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT,
                        fapi2::P9_TOD_MOVE_TOD_TO_TB_INIT_TIMEOUT()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_COUNT(l_tod_init_pending_count)
                        .set_TFMR_STATE(l_tfmr_state)
                        .set_TFMR_EXPECTED_STATE(TFMR_STATE_TB_RUNNING)
                        .set_TFMR_REG(l_tfmr_reg),
                        "Timeout waiting for TFMR state machine to reach 'tb_running' state!");

            l_tod_init_pending_count = 0;

            // Poll for TFMR bit(18) = b'0'.
            // Hardware clears the bit when the operation is complete.
            while (l_tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT)
            {
                FAPI_TRY(fapi2::delay(P9_TOD_UTILS_HW_NS_DELAY,
                                      P9_TOD_UTILS_SIM_CYCLE_DELAY),
                         "Error from delay");
                FAPI_TRY(p9_tod_utils_get_tfmr_reg(l_core_target,
                                                   i_thread_num,
                                                   l_tfmr_reg),
                         "Error from p9_tod_utils_get_tfmr_reg (TOD to TB clear)");

                if (!l_tfmr_reg.getBit<CAPP_TFMR_MOVE_CHIP_TOD_TO_TB>())
                {
                    FAPI_DBG("TFMR_MOVE_CHIP_TOD_TO_TB cleared.");
                    break;
                }

                ++l_tod_init_pending_count;
            }

            FAPI_ASSERT(l_tod_init_pending_count < P9_TOD_UTIL_TIMEOUT_COUNT,
                        fapi2::P9_TOD_MOVE_TOD_TO_TB_INIT_TIMEOUT()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_COUNT(l_tod_init_pending_count)
                        .set_TFMR_STATE(l_tfmr_state)
                        .set_TFMR_EXPECTED_STATE(TFMR_STATE_TB_RUNNING)
                        .set_TFMR_REG(l_tfmr_reg),
                        "Timeout waiting for TOD to TB bit to clear!");
        }
    }

    // Finish configuring downstream nodes
    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        FAPI_TRY(p9_tod_move_tod_to_tb(*l_child, i_thread_num, i_failingTodProc),
                 "Failure configuring downstream node!");
    }

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}

