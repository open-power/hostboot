/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_init_done.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2025                        */
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
///
/// @file p10_io_init_done.C
/// @brief Wait for dccal done and power-up all configured links/lanes
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------

#include <p10_io_init_done.H>
#include <p10_io_ppe_lib.H>
#include <p10_io_ppe_regs.H>
#include <p10_scom_pauc.H>
#include <p10_scom_iohs.H>
#include <p10_scom_omi.H>
#include <p10_io_init_start_ppe.H>
#include <p10_io_lib.H>

class p10_io_done : public p10_io_ppe_cache_proc
{
    public:
        fapi2::ReturnCode p10_io_init_done_pon_check_thread_done(
            const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
            const int& i_thread,
            bool& o_done);

        fapi2::ReturnCode p10_io_init_done_poff_check_thread_done(
            const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
            const int& i_thread,
            bool& o_done);

        fapi2::ReturnCode p10_io_init_done_check_fails(
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

        fapi2::ReturnCode p10_io_init_done_sw531947_check_x18_swizzle(
            const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target);

        fapi2::ReturnCode p11_isc_optimizations(
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

};

///
/// @brief SW531947:: If there is a x18 swizzle, we need to power down the unused slices
///
/// @param[in] i_iohs_target IOHS Target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_init_done_sw531947_check_x18_swizzle(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target)
{
    using namespace scomt::iohs;

    fapi2::ATTR_IOHS_FABRIC_LANE_REVERSAL_Type l_lane_reversal;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_FABRIC_LANE_REVERSAL, i_iohs_target, l_lane_reversal),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_FABRIC_LANE_REVERSAL)");

    // Check for x18 Tx Lane Swap
    if (l_lane_reversal & 0x80)
    {
        auto l_iolink_targets = i_iohs_target.getChildren<fapi2::TARGET_TYPE_IOLINK>();

        // handle Cronus platform implementation of IOLINK targets -- both
        // children are always returned as functional, even if no valid remote endpoint
        // connection exists
        if (fapi2::is_platform<fapi2::PLAT_CRONUS>())
        {
            std::vector<fapi2::Target<fapi2::TARGET_TYPE_IOLINK>> l_iolink_targets_filtered;

            for (auto l_loc_iolink_target : l_iolink_targets)
            {
                fapi2::ReturnCode l_rc;
                fapi2::Target<fapi2::TARGET_TYPE_IOLINK> l_rem_iolink_target;
                l_rc = l_loc_iolink_target.getOtherEnd(l_rem_iolink_target);

                if (l_rc == fapi2::FAPI2_RC_SUCCESS)
                {
                    l_iolink_targets_filtered.push_back(l_loc_iolink_target);
                }
            }

            l_iolink_targets = l_iolink_targets_filtered;
        }

        // Check if we are in half width mode
        if(l_iolink_targets.size() == 1)
        {
            fapi2::buffer<uint64_t> l_rx_psave_00_15;
            fapi2::buffer<uint64_t> l_rx_psave_16_23;
            fapi2::buffer<uint64_t> l_tx_psave_00_15;
            fapi2::buffer<uint64_t> l_tx_psave_16_23;

            for (const auto l_iolink_target : l_iolink_targets)
            {
                fapi2::ATTR_CHIP_UNIT_POS_Type l_iolink_pos;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iolink_target, l_iolink_pos),
                         "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

                if (l_iolink_pos % 2)
                {
                    // Link0[00:08]: Tx(ON) Rx(OFF), Link1[09:17]: Tx(OFF) Rx(ON)
                    l_rx_psave_00_15.insertFromRight(0xFF80,
                                                     IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1,
                                                     IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1_LEN);

                    l_tx_psave_00_15.insertFromRight(0x007F,
                                                     IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1,
                                                     IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1_LEN);
                    l_tx_psave_16_23.insertFromRight(0xC0,
                                                     IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1,
                                                     IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1_LEN);
                }
                else
                {
                    // Link0[00:08]: Tx(OFF) Rx(ON), Link1[09:17]: Tx(ON) Rx(OFF)
                    l_rx_psave_00_15.insertFromRight(0x007F,
                                                     IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1,
                                                     IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1_LEN);
                    l_rx_psave_16_23.insertFromRight(0xC0,
                                                     IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1,
                                                     IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1_LEN);

                    l_tx_psave_00_15.insertFromRight(0xFF80,
                                                     IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1,
                                                     IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1_LEN);
                }
            }

            // TODO Write Force
            FAPI_TRY(PREP_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG(i_iohs_target));
            FAPI_TRY(PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG(i_iohs_target, l_rx_psave_00_15));
            FAPI_TRY(PREP_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG(i_iohs_target));
            FAPI_TRY(PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG(i_iohs_target, l_rx_psave_16_23));

            FAPI_TRY(PREP_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG(i_iohs_target));
            FAPI_TRY(PUT_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG(i_iohs_target, l_tx_psave_00_15));
            FAPI_TRY(PREP_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG(i_iohs_target));
            FAPI_TRY(PUT_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG(i_iohs_target, l_tx_psave_16_23));

            // TODO Write Fence
            FAPI_TRY(PREP_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL5_PG(i_iohs_target));
            FAPI_TRY(PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL5_PG(i_iohs_target, l_rx_psave_00_15));
            FAPI_TRY(PREP_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG(i_iohs_target));
            FAPI_TRY(PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG(i_iohs_target, l_rx_psave_16_23));

            FAPI_TRY(PREP_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG(i_iohs_target));
            FAPI_TRY(PUT_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG(i_iohs_target, l_tx_psave_00_15));
            FAPI_TRY(PREP_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG(i_iohs_target));
            FAPI_TRY(PUT_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG(i_iohs_target, l_tx_psave_16_23));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check done status for reg_init, dccal, lane power on, and fifo init for a thread
///
/// @param[in] i_pauc_target The PAUC target to read from
/// @param[in] i_thread The thread to read
/// @param[out] o_done Set to false if something isn't done
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_done::p10_io_init_done_pon_check_thread_done(
    const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
    const int& i_thread,
    bool& o_done)
{
    fapi2::buffer<uint64_t> l_data = 0;

    FAPI_TRY(p10_io_ppe_ext_cmd_done_hw_reg_init_pg[i_thread].getData(i_pauc_target, l_data, true));

    FAPI_DBG("Thread: %d, ext_cmd_done_hw_reg_init: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

    FAPI_TRY(p10_io_ppe_ext_cmd_done_dccal_pl[i_thread].getData(i_pauc_target, l_data, true));

    FAPI_DBG("Thread: %d, ext_cmd_done_dccal: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

    FAPI_TRY(p10_io_ppe_ext_cmd_done_tx_zcal_pl[i_thread].getData(i_pauc_target, l_data, true));

    FAPI_DBG("Thread: %d, ext_cmd_done_tx_zcal_pl: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

    FAPI_TRY(p10_io_ppe_ext_cmd_done_tx_ffe_pl[i_thread].getData(i_pauc_target, l_data, true));

    FAPI_DBG("Thread: %d, ext_cmd_done_tx_ffe_pl: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

    FAPI_TRY(p10_io_ppe_ext_cmd_done_power_on_pl[i_thread].getData(i_pauc_target, l_data, true));

    FAPI_DBG("Thread: %d, ext_cmd_done_power_on_pl: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check done status for reg_init, dccal, lane power on, and fifo init for a thread
///
/// @param[in] i_pauc_target The PAUC target to read from
/// @param[in] i_thread The thread to read
/// @param[out] o_done Set to false if something isn't done
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_done::p10_io_init_done_poff_check_thread_done(
    const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
    const int& i_thread,
    bool& o_done)
{
    fapi2::buffer<uint64_t> l_data = 0;

    FAPI_TRY(p10_io_ppe_ext_cmd_done_hw_reg_init_pg[i_thread].getData(i_pauc_target, l_data, true));

    FAPI_DBG("Thread: %d, ext_cmd_done_hw_reg_init: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

    FAPI_TRY(p10_io_ppe_ext_cmd_done_dccal_pl[i_thread].getData(i_pauc_target, l_data, true));

    FAPI_DBG("Thread: %d, ext_cmd_done_dccal: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

    FAPI_TRY(p10_io_ppe_ext_cmd_done_tx_zcal_pl[i_thread].getData(i_pauc_target, l_data, true));

    FAPI_DBG("Thread: %d, ext_cmd_done_tx_zcal_pl: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

    FAPI_TRY(p10_io_ppe_ext_cmd_done_tx_ffe_pl[i_thread].getData(i_pauc_target, l_data, true));

    FAPI_DBG("Thread: %d, ext_cmd_done_tx_ffe_pl: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

    FAPI_TRY(p10_io_ppe_ext_cmd_done_power_off_pl[i_thread].getData(i_pauc_target, l_data, true));

    FAPI_DBG("Thread: %d, ext_cmd_done_power_off_pl: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Update CDR BW
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_omi_fix_cdr_bw(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt::omi;
    int l_num_lanes = P10_IO_LIB_NUMBER_OF_OMI_LANES;
    auto l_pauc_targets = i_target.getChildren<fapi2::TARGET_TYPE_PAUC>();

    for (auto l_pauc_target : l_pauc_targets)
    {
        auto l_omic_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_OMIC>();

        for (auto l_omic_target : l_omic_targets)
        {
            auto l_omi_targets = l_omic_target.getChildren<fapi2::TARGET_TYPE_OMI>();

            for (auto l_omi_target : l_omi_targets)
            {
                // Update CDR Bandwidth (rx_pr_phase_step)
                FAPI_TRY(p10_io_omi_put_pl_regs(l_omi_target,
                                                RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE4_PL,
                                                RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP,
                                                RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN,
                                                l_num_lanes,
                                                0x10));
            }
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Add fail information for any links that did not finish init
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_done::p10_io_init_done_check_fails(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    bool l_done = false;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    auto l_pauc_targets = i_target.getChildren<fapi2::TARGET_TYPE_PAUC>();

    for (auto l_pauc_target : l_pauc_targets)
    {
        fapi2::ATTR_CHIP_UNIT_POS_Type l_pauc_num;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_pauc_target, l_pauc_num),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
        FAPI_DBG("Getting DCCAL status for PAUC: %d", l_pauc_num);

        auto l_iohs_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_IOHS>();
        auto l_omic_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_OMIC>();


        for (auto l_iohs_target : l_iohs_targets)
        {
            int l_thread = 0;
            fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_num;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs_target, l_iohs_num),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

            FAPI_TRY(p10_io_get_iohs_thread(l_iohs_target, l_thread));

            FAPI_TRY(p10_io_init_done_pon_check_thread_done(l_pauc_target, l_thread, l_done));


            if (!l_done)
            {
                char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
                fapi2::toString(l_iohs_target, l_tgt_str, sizeof(l_tgt_str));

                char l_pauc_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
                fapi2::toString(l_pauc_target, l_pauc_tgt_str, sizeof(l_pauc_tgt_str));


                fapi2::buffer<uint64_t> l_ffdc_thread = l_thread;
                fapi2::buffer<uint64_t> l_ext_cmd_req = 0;
                fapi2::buffer<uint64_t> l_ext_cmd_done = 0;
                fapi2::buffer<uint64_t> l_ext_cmd_lanes_00_15 = 0;
                fapi2::buffer<uint64_t> l_ext_cmd_lanes_16_31 = 0;
                fapi2::buffer<uint64_t> l_debug_state = 0;
                fapi2::buffer<uint64_t> l_error_state = 0;
                fapi2::buffer<uint64_t> l_error_valid = 0;
                fapi2::buffer<uint64_t> l_error_thread = 0;
                fapi2::buffer<uint64_t> l_error_lane = 0;
                FAPI_TRY(p10_io_ppe_ext_cmd_req[l_thread].getData(l_pauc_target, l_ext_cmd_req, true));
                FAPI_TRY(p10_io_ppe_ext_cmd_done[l_thread].getData(l_pauc_target, l_ext_cmd_done, true));
                FAPI_TRY(p10_io_ppe_ext_cmd_lanes_00_15[l_thread].getData(l_pauc_target, l_ext_cmd_lanes_00_15, true));
                FAPI_TRY(p10_io_ppe_ext_cmd_lanes_16_31[l_thread].getData(l_pauc_target, l_ext_cmd_lanes_16_31, true));
                FAPI_TRY(p10_io_ppe_ppe_debug_state[l_thread].getData(l_pauc_target, l_debug_state, true));

                FAPI_TRY(p10_io_ppe_ppe_error_state.getData(l_pauc_target, l_error_state, true));
                FAPI_TRY(p10_io_ppe_ppe_error_valid.getData(l_pauc_target, l_error_valid, true));
                FAPI_TRY(p10_io_ppe_ppe_error_thread.getData(l_pauc_target, l_error_thread, true));
                FAPI_TRY(p10_io_ppe_ppe_error_lane.getData(l_pauc_target, l_error_lane, true));

                FAPI_ASSERT(false,
                            fapi2::P10_IO_INIT_DONE_TIMEOUT_ERROR()
                            .set_TARGET(l_iohs_target)
                            .set_THREAD(l_ffdc_thread)
                            .set_EXT_CMD_REQ(l_ext_cmd_req)
                            .set_EXT_CMD_DONE(l_ext_cmd_done)
                            .set_EXT_CMD_LANES_00_15(l_ext_cmd_lanes_00_15)
                            .set_EXT_CMD_LANES_16_31(l_ext_cmd_lanes_16_31)
                            .set_DEBUG_STATE(l_debug_state)
                            .set_ERROR_STATE(l_error_state)
                            .set_ERROR_VALID(l_error_valid)
                            .set_ERROR_THREAD(l_error_thread)
                            .set_ERROR_LANE(l_error_lane),
                            "Timeout waiting for I/O init to complete on %s(%s:thread(%d))",
                            l_tgt_str, l_pauc_tgt_str, l_thread);
                l_rc = fapi2::current_err;
            }
        }

        for (auto l_omic_target : l_omic_targets)
        {
            int l_thread = 0;
            fapi2::ATTR_CHIP_UNIT_POS_Type l_omic_num;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_omic_target, l_omic_num),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

            FAPI_TRY(p10_io_get_omic_thread(l_omic_target, l_thread));

            FAPI_TRY(p10_io_init_done_pon_check_thread_done(l_pauc_target, l_thread, l_done));

            if (!l_done)
            {
                char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
                fapi2::toString(l_omic_target, l_tgt_str, sizeof(l_tgt_str));

                char l_pauc_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
                fapi2::toString(l_pauc_target, l_pauc_tgt_str, sizeof(l_pauc_tgt_str));

                fapi2::buffer<uint64_t> l_ffdc_thread = l_thread;
                fapi2::buffer<uint64_t> l_ext_cmd_req = 0;
                fapi2::buffer<uint64_t> l_ext_cmd_done = 0;
                fapi2::buffer<uint64_t> l_ext_cmd_lanes_00_15 = 0;
                fapi2::buffer<uint64_t> l_ext_cmd_lanes_16_31 = 0;
                fapi2::buffer<uint64_t> l_debug_state = 0;
                fapi2::buffer<uint64_t> l_error_state = 0;
                fapi2::buffer<uint64_t> l_error_valid = 0;
                fapi2::buffer<uint64_t> l_error_thread = 0;
                fapi2::buffer<uint64_t> l_error_lane = 0;
                FAPI_TRY(p10_io_ppe_ext_cmd_req[l_thread].getData(l_pauc_target, l_ext_cmd_req, true));
                FAPI_TRY(p10_io_ppe_ext_cmd_done[l_thread].getData(l_pauc_target, l_ext_cmd_done, true));
                FAPI_TRY(p10_io_ppe_ext_cmd_lanes_00_15[l_thread].getData(l_pauc_target, l_ext_cmd_lanes_00_15, true));
                FAPI_TRY(p10_io_ppe_ext_cmd_lanes_16_31[l_thread].getData(l_pauc_target, l_ext_cmd_lanes_16_31, true));
                FAPI_TRY(p10_io_ppe_ppe_debug_state[l_thread].getData(l_pauc_target, l_debug_state, true));

                FAPI_TRY(p10_io_ppe_ppe_error_state.getData(l_pauc_target, l_error_state, true));
                FAPI_TRY(p10_io_ppe_ppe_error_valid.getData(l_pauc_target, l_error_valid, true));
                FAPI_TRY(p10_io_ppe_ppe_error_thread.getData(l_pauc_target, l_error_thread, true));
                FAPI_TRY(p10_io_ppe_ppe_error_lane.getData(l_pauc_target, l_error_lane, true));

                FAPI_ASSERT(false,
                            fapi2::P10_IO_INIT_DONE_TIMEOUT_ERROR()
                            .set_TARGET(l_omic_target)
                            .set_THREAD(l_ffdc_thread)
                            .set_EXT_CMD_REQ(l_ext_cmd_req)
                            .set_EXT_CMD_DONE(l_ext_cmd_done)
                            .set_EXT_CMD_LANES_00_15(l_ext_cmd_lanes_00_15)
                            .set_EXT_CMD_LANES_16_31(l_ext_cmd_lanes_16_31)
                            .set_DEBUG_STATE(l_debug_state)
                            .set_ERROR_STATE(l_error_state)
                            .set_ERROR_VALID(l_error_valid)
                            .set_ERROR_THREAD(l_error_thread)
                            .set_ERROR_LANE(l_error_lane),
                            "Timeout waiting for I/O init to complete on %s(%s:thread(%d))",
                            l_tgt_str, l_pauc_tgt_str, l_thread);
                l_rc = fapi2::current_err;
            }
        }
    }

    if (l_rc)
    {
        fapi2::current_err = l_rc;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Optimization for P11 ISC
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_done::p11_isc_optimizations(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("ISC Optimizations");

    constexpr uint16_t c_max_tx_segments_0_15 = 0xFFFF;
    constexpr uint16_t c_max_tx_segments_16_24 = 0x1FF;

    constexpr uint8_t c_pr_phase_step = 4;
    constexpr uint8_t c_fw_inertia_amt = 4;
    constexpr uint8_t c_peak1_disable = 0;
    constexpr uint8_t c_peak2_disable = 1;
    constexpr uint8_t c_peak1 = 0;
    constexpr uint8_t c_broadcast_lane = 31;
    constexpr uint8_t c_group_0 = 0;

    auto l_pauc_targets = i_target.getChildren<fapi2::TARGET_TYPE_PAUC>();

    fapi2::buffer<uint64_t> l_data;
    uint64_t l_addr = 0;

    uint8_t l_peak2 = 0;
    int l_thread = 0;
    fapi2::ATTR_IO_IOHS_CHANNEL_LOSS_Type l_channel_loss = 0;

    for (auto l_pauc_target : l_pauc_targets)
    {
        auto l_iohs_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_IOHS>();
        auto l_omic_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_OMIC>();

        // IOHS Targets
        for (auto l_iohs_target : l_iohs_targets)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_IOHS_CHANNEL_LOSS_ISC1_WORKAROUND, l_iohs_target, l_channel_loss),
                     "Error from FAPI_ATTR_GET (ATTR_IO_IOHS_CHANNEL_LOSS_ISC1_WORKAROUND)");

            if (l_channel_loss == fapi2::ENUM_ATTR_IO_IOHS_CHANNEL_LOSS_LOW_LOSS)
            {
                l_peak2 = 0;
            }
            else if (l_channel_loss == fapi2::ENUM_ATTR_IO_IOHS_CHANNEL_LOSS_MID_LOSS)
            {
                l_peak2 = 2;
            }
            else if (l_channel_loss == fapi2::ENUM_ATTR_IO_IOHS_CHANNEL_LOSS_HIGH_LOSS)
            {
                l_peak2 = 12;
            }

            FAPI_TRY(p10_io_get_iohs_thread(l_iohs_target, l_thread));

            // Peak Disable Broadcast
            FAPI_TRY(p10_io_ppe_ppe_ctle_peak1_disable[l_thread].putData(l_pauc_target, c_peak1_disable));
            FAPI_TRY(p10_io_ppe_ppe_ctle_peak2_disable[l_thread].putData(l_pauc_target, c_peak2_disable));

            // Flush the data to the sram
            FAPI_TRY(p10_io_ppe_mem_regs[l_thread].flush());

            // Peak ABANK Broadcast
            l_data.flush<0>();
            l_addr = generate_address(scomt::iohs::IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL, c_group_0, c_broadcast_lane);
            l_data.insertFromRight<scomt::iohs::IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK1, scomt::iohs::IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN>
            (c_peak1);
            l_data.insertFromRight<scomt::iohs::IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK2, scomt::iohs::IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN>
            (l_peak2);
            FAPI_TRY(fapi2::putScom(l_iohs_target, l_addr, l_data));

            // Peak BBANK Broadcast
            l_data.flush<0>();
            l_addr = generate_address(scomt::iohs::IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL, c_group_0, c_broadcast_lane);
            l_data.insertFromRight<scomt::iohs::IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_PEAK1, scomt::iohs::IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN>
            (c_peak1);
            l_data.insertFromRight<scomt::iohs::IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_PEAK2, scomt::iohs::IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN>
            (l_peak2);
            FAPI_TRY(fapi2::putScom(l_iohs_target, l_addr, l_data));

            // PR Phase Step Broadcast
            l_data.flush<0>();
            l_addr = generate_address(scomt::iohs::IOO_RX0_0_RD_RX_BIT_REGS_MODE4_PL, c_group_0, c_broadcast_lane);
            l_data.insertFromRight<scomt::iohs::IOO_RX0_0_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP, scomt::iohs::IOO_RX0_0_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN>
            (c_pr_phase_step);
            l_data.insertFromRight<scomt::iohs::IOO_RX0_0_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT, scomt::iohs::IOO_RX0_0_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN>
            (c_fw_inertia_amt);
            FAPI_TRY(fapi2::putScom(l_iohs_target, l_addr, l_data));

            // Tx P-Segment 0-15 Broadcast
            l_data.flush<0>();
            l_addr = generate_address(scomt::iohs::IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL, c_group_0, c_broadcast_lane);
            l_data.insertFromRight<scomt::iohs::IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN, scomt::iohs::IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>
            (c_max_tx_segments_0_15);
            FAPI_TRY(fapi2::putScom(l_iohs_target, l_addr, l_data));

            // Tx P-Segment 16-24 Broadcast
            l_data.flush<0>();
            l_addr = generate_address(scomt::iohs::IOO_TX0_0_DD_TX_BIT_REGS_CNTL9_PL, c_group_0, c_broadcast_lane);
            l_data.insertFromRight<scomt::iohs::IOO_TX0_0_DD_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_24_HS_EN, scomt::iohs::IOO_TX0_0_DD_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_24_HS_EN_LEN>
            (c_max_tx_segments_16_24);
            FAPI_TRY(fapi2::putScom(l_iohs_target, l_addr, l_data));

            // Tx N-Segment 0-15 Broadcast
            l_data.flush<0>();
            l_addr = generate_address(scomt::iohs::IOO_TX0_0_DD_TX_BIT_REGS_CNTL10_PL, c_group_0, c_broadcast_lane);
            l_data.insertFromRight<scomt::iohs::IOO_TX0_0_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN, scomt::iohs::IOO_TX0_0_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>
            (c_max_tx_segments_0_15);
            FAPI_TRY(fapi2::putScom(l_iohs_target, l_addr, l_data));

            // Tx N-Segment 16-24 Broadcast
            l_data.flush<0>();
            l_addr = generate_address(scomt::iohs::IOO_TX0_0_DD_TX_BIT_REGS_CNTL11_PL, c_group_0, c_broadcast_lane);
            l_data.insertFromRight<scomt::iohs::IOO_TX0_0_DD_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_24_HS_EN, scomt::iohs::IOO_TX0_0_DD_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_24_HS_EN_LEN>
            (c_max_tx_segments_16_24);
            FAPI_TRY(fapi2::putScom(l_iohs_target, l_addr, l_data));

        }

        // OMIC Targets
        for (auto l_omic_target : l_omic_targets)
        {

            FAPI_TRY(p10_io_get_omic_thread(l_omic_target, l_thread));

            // PR Phase Step Broadcast
            l_data.flush<0>();
            l_addr = generate_address(scomt::omi::RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE4_PL, c_group_0, c_broadcast_lane);
            FAPI_TRY(fapi2::getScom(l_omic_target, l_addr, l_data));
            l_data.insertFromRight<scomt::omi::RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP, scomt::omi::RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN>
            (c_pr_phase_step);
            l_data.insertFromRight<scomt::omi::RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT, scomt::omi::RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN>
            (c_fw_inertia_amt);
            FAPI_TRY(fapi2::putScom(l_omic_target, l_addr, l_data));

            // Tx P-Segment 0-15 Broadcast
            l_data.flush<0>();
            l_addr = generate_address(scomt::omi::TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL, c_group_0, c_broadcast_lane);
            FAPI_TRY(fapi2::getScom(l_omic_target, l_addr, l_data));
            l_data.insertFromRight<scomt::omi::TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN, scomt::omi::TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>
            (c_max_tx_segments_0_15);
            FAPI_TRY(fapi2::putScom(l_omic_target, l_addr, l_data));

            // Tx P-Segment 16-24 Broadcast
            l_data.flush<0>();
            l_addr = generate_address(scomt::omi::TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL9_PL, c_group_0, c_broadcast_lane);
            FAPI_TRY(fapi2::getScom(l_omic_target, l_addr, l_data));
            l_data.insertFromRight<scomt::omi::TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_24_HS_EN, scomt::omi::TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_24_HS_EN_LEN>
            (c_max_tx_segments_16_24);
            FAPI_TRY(fapi2::putScom(l_omic_target, l_addr, l_data));

            // Tx N-Segment 0-15 Broadcast
            l_data.flush<0>();
            l_addr = generate_address(scomt::omi::TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL, c_group_0, c_broadcast_lane);
            FAPI_TRY(fapi2::getScom(l_omic_target, l_addr, l_data));
            l_data.insertFromRight<scomt::omi::TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN, scomt::omi::TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>
            (c_max_tx_segments_0_15);
            FAPI_TRY(fapi2::putScom(l_omic_target, l_addr, l_data));

            // Tx N-Segment 16-24 Broadcast
            l_data.flush<0>();
            l_addr = generate_address(scomt::omi::TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL11_PL, c_group_0, c_broadcast_lane);
            FAPI_TRY(fapi2::getScom(l_omic_target, l_addr, l_data));
            l_data.insertFromRight<scomt::omi::TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_24_HS_EN, scomt::omi::TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_24_HS_EN_LEN>
            (c_max_tx_segments_16_24);
            FAPI_TRY(fapi2::putScom(l_omic_target, l_addr, l_data));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Wait for dccal done and power-up all configured links/lanes
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_init_done(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    const uint32_t IO_INIT_DONE_NS_DELAY = 10000000;
    const uint32_t IO_INIT_DONE_CYCLES   = 10000000;
    bool l_done = false;
    p10_io_done l_proc;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    auto l_pauc_targets = i_target.getChildren<fapi2::TARGET_TYPE_PAUC>();
    fapi2::ATTR_INTERPOSER_FEATURE_HW632898_Type l_isc_defect = 0;

    //Poll for done
    int POLLING_LOOPS = 1000;

    fapi2::ATTR_IS_SIMICS_Type l_simics;
    fapi2::ATTR_IS_SIMULATION_Type l_is_sim;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMICS, FAPI_SYSTEM, l_simics),
             "Error from FAPI_ATTR_GET (ATTR_IS_SIMICS)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, FAPI_SYSTEM, l_is_sim),
             "Error from FAPI_ATTR_GET (ATTR_IS_SIMULATION)");

    // In simics we don't want to wait a long time since it will either be done or not instantly
    if( l_simics == fapi2::ENUM_ATTR_IS_SIMICS_SIMICS )
    {
        POLLING_LOOPS = 2; // using 2 so that we can still get maximum code coverage in the loop
    }

    for (int l_try = 0; l_try < POLLING_LOOPS && !l_done; l_try++)
    {
        l_done = true;

        for (auto l_pauc_target : l_pauc_targets)
        {
            fapi2::ATTR_CHIP_UNIT_POS_Type l_pauc_num;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_pauc_target, l_pauc_num),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
            FAPI_DBG("Getting DCCAL status for PAUC: %d", l_pauc_num);

            auto l_iohs_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_IOHS>();
            auto l_omic_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_OMIC>();


            for (auto l_iohs_target : l_iohs_targets)
            {
                int l_thread = 0;
                fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_num;
                fapi2::ATTR_IOHS_CONFIG_MODE_Type l_config_mode;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs_target, l_iohs_num),
                         "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_CONFIG_MODE, l_iohs_target, l_config_mode),
                         "Error from FAPI_ATTR_GET (ATTR_IOHS_CONFIG_MODE)");

                FAPI_TRY(p10_io_get_iohs_thread(l_iohs_target, l_thread));

                if (l_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX)
                {
                    FAPI_TRY(l_proc.p10_io_init_done_pon_check_thread_done(l_pauc_target, l_thread, l_done));

                    if (l_done)
                    {
                        FAPI_TRY(p10_io_init_done_sw531947_check_x18_swizzle(l_iohs_target));
                    }
                }
                else if (l_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA)
                {
                    FAPI_TRY(l_proc.p10_io_init_done_poff_check_thread_done(l_pauc_target, l_thread, l_done));
                }
            }

            for (auto l_omic_target : l_omic_targets)
            {
                int l_thread = 0;
                fapi2::ATTR_CHIP_UNIT_POS_Type l_omic_num;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_omic_target, l_omic_num),
                         "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

                FAPI_TRY(p10_io_get_omic_thread(l_omic_target, l_thread));

                FAPI_TRY(l_proc.p10_io_init_done_pon_check_thread_done(l_pauc_target, l_thread, l_done));
            }
        }

        fapi2::delay(IO_INIT_DONE_NS_DELAY, IO_INIT_DONE_CYCLES);
    }

    FAPI_TRY(p10_omi_fix_cdr_bw(i_target));


    // Avoid failing in Simics until the models get updated
    if( !l_done && (l_simics == fapi2::ENUM_ATTR_IS_SIMICS_SIMICS) )
    {
        FAPI_INF("p10_io_init_done> Skipping timeout in Simics");
    }
    else if (!l_done)
    {
        FAPI_TRY(l_proc.p10_io_init_done_check_fails(i_target))
    }

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_INTERPOSER_FEATURE_HW632898, i_target, l_isc_defect),
             "Error from FAPI_ATTR_GET (ATTR_INTERPOSER_FEATURE_HW632898)");

    // P11 ISC optimizations. Skipping simulation environment because they're not set up for lane broadcasting
    if((l_isc_defect == fapi2::ENUM_ATTR_INTERPOSER_FEATURE_HW632898_TRUE) && !l_is_sim)
    {
        FAPI_TRY(l_proc.p11_isc_optimizations(i_target));
    }

fapi_try_exit:
    return fapi2::current_err;
}
