/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/common/io_ppe_common.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
/// @file io_ppe_common.H
///
/// @brief Class that supports command execution and polling functions
///        for IO hwps
///
/// *HWP HW Maintainer: Josh Chica <Josh.Chica@ibm.com>
/// *HWP FW Maintainer:
/// *HWP Consumed by: SBE
///

#pragma once

#include <fapi2.H>
#include <io_ppe_lib.H>
#include <io_scom_lib.H>

enum IO_PPE_CONSTS
{
    IO_PPE_MAX_THREADS = 9,
    IO_PPE_DCCAL_DONE_POLL_TRYS = 100,
    IO_PPE_DCCAL_DONE_POLL_DELAY_NS = 10000,
    IO_PPE_DCCAL_DONE_POLL_DELAY_SIM_CYCLES = 100000000,
    IO_PPE_EL_DONE_POLL_TRYS = 100,
    IO_PPE_EL_DONE_POLL_DELAY_NS = 10000,
    IO_PPE_EL_DONE_POLL_DELAY_SIM_CYCLES = 100000000,
};

//WARNING!!  Since these are hard coded and not generated
// from the image register definitions, any changes or
// inconsistances between image commands would cause
// problems.
enum IO_PPE_EXT_CMD_REQ_BITS
{
    //                              1111111111222222222233
    //                    01234567890123456789012345678901
    HW_REG_INIT_PG    = 0b10000000000000000000000000000000,
    IORESET_PL        = 0b01000000000000000000000000000000,
    NOP_RX_DETECT_PL  = 0b00100000000000000000000000000000,
    DCCAL_PL          = 0b00010000000000000000000000000000,
    TX_ZCAL_PL        = 0b00001000000000000000000000000000,
    TX_FFE_PL         = 0b00000100000000000000000000000000,
    POWER_OFF_PL      = 0b00000010000000000000000000000000,
    POWER_ON_PL       = 0b00000001000000000000000000000000,
    TX_FIFO_INIT_PL   = 0b00000000100000000000000000000000,
    NOP_RX_BIST_TESTS = 0b00000000010000000000000000000000,
    TX_BIST_TESTS_PL  = 0b00000000001000000000000000000000,
    TRAIN_PL          = 0b00000000000100000000000000000000,
    RECAL_PL          = 0b00000000000010000000000000000000,
    BIST_FINAL        = 0b00000000000001000000000000000000,
    RESERVED_14       = 0b00000000000000100000000000000000,
    RESERVED_15       = 0b00000000000000010000000000000000,
};

template<fapi2::TargetType K, fapi2::MulticastType M = fapi2::MULTICAST_OR, typename V = fapi2::plat_target_handle_t>
class io_ppe_common
{
    public:
        io_ppe_regs<K, M, V>* iv_regs;

        io_ppe_common(io_ppe_regs<K, M, V>* i_regs) :
            iv_regs(i_regs)
        {
            FAPI_DBG("io_ppe_common constructor");
        }

        fapi2::ReturnCode config_threads(const fapi2::Target<K, M, V>& i_target,
                                         const fapi2::buffer<uint64_t> i_num_threads);

        fapi2::ReturnCode config_lanes(const fapi2::Target<K, M, V>& i_target,
                                       const fapi2::buffer<uint64_t> i_thread,
                                       const fapi2::buffer<uint64_t> i_gcr_id,
                                       const fapi2::buffer<uint64_t> i_num_rx_lanes,
                                       const fapi2::buffer<uint64_t> i_num_tx_lanes,
                                       const fapi2::buffer<uint64_t> i_spread_en,
                                       const fapi2::buffer<uint64_t> i_pcie_mode,
                                       const fapi2::buffer<uint64_t> i_serdes_16_to_1);

        fapi2::ReturnCode config(const fapi2::Target<K, M, V>& i_target,
                                 const fapi2::buffer<uint64_t> i_num_threads,
                                 const fapi2::buffer<uint64_t> i_gcr_ids[],
                                 const fapi2::buffer<uint64_t> i_rx_lanes[],
                                 const fapi2::buffer<uint64_t> i_tx_lanes[],
                                 const fapi2::buffer<uint64_t> i_spread_en,
                                 const fapi2::buffer<uint64_t> i_pcie_mode,
                                 const fapi2::buffer<uint64_t> i_serdes_16_to_1);

        fapi2::ReturnCode bist_init(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    const uint32_t& i_thread,
                                    const uint8_t& i_bist_timer_sel);

        fapi2::ReturnCode bist_init_rx(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       const uint64_t& i_baseAddr,
                                       const uint32_t& i_thread,
                                       const uint8_t& i_esdTest,
                                       const uint8_t& i_dacTest,
                                       uint32_t i_rx_mask);

        fapi2::ReturnCode bist_init_tx(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       const uint32_t& i_thread,
                                       uint32_t i_tx_mask);

        fapi2::ReturnCode bist_cleanup(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       const fapi2::buffer<uint64_t> i_num_threads,
                                       const uint32_t i_rx_lanes_0_31,
                                       const uint32_t i_tx_lanes_0_31,
                                       fapi2::buffer<uint64_t>& o_done,
                                       fapi2::buffer<uint64_t>& o_fail);

        fapi2::ReturnCode ppe_init_threads(const fapi2::Target<K, M, V>& i_target,
                                           const fapi2::buffer<uint64_t> i_num_threads);

        fapi2::ReturnCode ppe_init_thread(const fapi2::Target<K, M, V>& i_target,
                                          const fapi2::buffer<uint64_t> i_thread,
                                          const fapi2::buffer<uint64_t> i_gcr_id,
                                          const fapi2::buffer<uint64_t> i_num_rx_lanes,
                                          const fapi2::buffer<uint64_t> i_num_tx_lanes,
                                          const fapi2::buffer<uint64_t> i_spread_en,
                                          const fapi2::buffer<uint64_t> i_pcie_mode,
                                          const fapi2::buffer<uint64_t> i_serdes_16_to_1);

        fapi2::ReturnCode ppe_init(const fapi2::Target<K, M, V>& i_target,
                                   const fapi2::buffer<uint64_t> i_num_threads,
                                   const fapi2::buffer<uint64_t> i_gcr_ids[],
                                   const fapi2::buffer<uint64_t> i_rx_lanes[],
                                   const fapi2::buffer<uint64_t> i_tx_lanes[],
                                   const fapi2::buffer<uint64_t> i_spread_en,
                                   const fapi2::buffer<uint64_t> i_pcie_mode,
                                   const fapi2::buffer<uint64_t> i_serdes_16_to_1);

        fapi2::ReturnCode clear_ext_cmd_thread(const fapi2::Target<K, M, V>& i_target,
                                               const fapi2::buffer<uint64_t> i_thread);

        fapi2::ReturnCode clear_ext_cmd(const fapi2::Target<K, M, V>& i_target,
                                        const fapi2::buffer<uint64_t> i_num_threads);

        fapi2::ReturnCode ext_cmd_start_thread(const fapi2::Target<K, M, V>& i_target,
                                               const fapi2::buffer<uint32_t> i_thread,
                                               const uint32_t i_rx_lanes_0_31,
                                               const uint32_t i_tx_lanes_0_31,
                                               fapi2::buffer<uint64_t> i_ext_cmd_req);

        fapi2::ReturnCode ext_cmd_start(const fapi2::Target<K, M, V>& i_target,
                                        const fapi2::buffer<uint64_t> i_num_threads,
                                        const uint32_t i_rx_lanes_0_31,
                                        const uint32_t i_tx_lanes_0_31,
                                        fapi2::buffer<uint64_t> i_ext_cmd_req);

        fapi2::ReturnCode ext_cmd_check(const fapi2::Target<K, M, V>& i_target,
                                        const fapi2::buffer<uint32_t> i_thread,
                                        fapi2::buffer<uint64_t> i_ext_cmd_req,
                                        fapi2::buffer<uint64_t>& o_done,
                                        fapi2::buffer<uint64_t>& o_fail);

        fapi2::ReturnCode ext_cmd_poll(const fapi2::Target<K, M, V>& i_target,
                                       const fapi2::buffer<uint64_t> i_num_threads,
                                       fapi2::buffer<uint64_t> i_ext_cmd_req,
                                       fapi2::buffer<uint64_t>& o_done,
                                       fapi2::buffer<uint64_t>& o_fail);


        fapi2::ReturnCode enable_lanes(const fapi2::Target<K, M, V>& i_target,
                                       const fapi2::buffer<uint64_t> i_num_threads,
                                       const uint32_t i_rx_lanes_0_31,
                                       const uint32_t i_tx_lanes_0_31);

        fapi2::ReturnCode check_enable_lanes_done(const fapi2::Target<K, M, V>& i_target,
                const fapi2::buffer<uint64_t> i_num_threads,
                fapi2::buffer<uint64_t>& o_done,
                fapi2::buffer<uint64_t>& o_fail);

        fapi2::ReturnCode bist_start(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                     const fapi2::buffer<uint64_t> i_num_threads,
                                     const uint32_t i_rx_lanes_0_31,
                                     const uint32_t i_tx_lanes_0_31,
                                     const fapi2::buffer<uint64_t> i_ext_cmd_override = 0);

        fapi2::ReturnCode bist_poll(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    const fapi2::buffer<uint64_t> i_num_threads,
                                    fapi2::buffer<uint64_t>& o_done,
                                    fapi2::buffer<uint64_t>& o_fail,
                                    const fapi2::buffer<uint64_t> i_ext_cmd_override = 0);

        fapi2::ReturnCode fast_mode_thread(const fapi2::Target<K, M, V>& i_target,
                                           const fapi2::buffer<uint64_t> i_thread);

        fapi2::ReturnCode fast_mode(const fapi2::Target<K, M, V>& i_target,
                                    const fapi2::buffer<uint64_t> i_num_threads);

        uint8_t get_num_lanes(uint32_t);
};

// ===============================================================
// phy_config
// ===============================================================
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::config_threads(const fapi2::Target<K, M, V>& i_target,
        const fapi2::buffer<uint64_t> i_num_threads)
{
    FAPI_DBG("Start");
    FAPI_TRY(IMG_REG_PPE_NUM_THREADS_PUT(iv_regs, i_target, i_num_threads));
fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::config_lanes(const fapi2::Target<K, M, V>& i_target,
        const fapi2::buffer<uint64_t> i_thread,
        const fapi2::buffer<uint64_t> i_gcr_id,
        const fapi2::buffer<uint64_t> i_num_rx_lanes,
        const fapi2::buffer<uint64_t> i_num_tx_lanes,
        const fapi2::buffer<uint64_t> i_spread_en,
        const fapi2::buffer<uint64_t> i_pcie_mode,
        const fapi2::buffer<uint64_t> i_serdes_16_to_1)
{
    FAPI_DBG("Start");
#ifdef IOT_IMAGE
    FAPI_TRY(FW_REG_FW_TX_CLOCK_LANE_PUT(iv_regs, i_target, i_thread, i_num_tx_lanes));
#endif
    FAPI_TRY(FW_REG_FW_GCR_BUS_ID_PUT(iv_regs, i_target, i_thread, i_gcr_id));
    FAPI_TRY(FW_REG_FW_NUM_LANES_RX_PUT(iv_regs, i_target, i_thread, i_num_rx_lanes));
    FAPI_TRY(FW_REG_FW_NUM_LANES_TX_PUT(iv_regs, i_target, i_thread, i_num_tx_lanes));
    FAPI_TRY(FW_REG_FW_SERDES_16_TO_1_MODE_PUT(iv_regs, i_target, i_thread, i_serdes_16_to_1));
    FAPI_TRY(FW_REG_FW_SPREAD_EN_PUT(iv_regs, i_target, i_thread, i_spread_en));
#ifndef IOT_IMAGE
    FAPI_TRY(FW_REG_FW_PCIE_MODE_PUT(iv_regs, i_target, i_thread, i_pcie_mode));
#endif
    FAPI_TRY(FW_REG_FW_STOP_THREAD_PUT(iv_regs, i_target, i_thread, 0));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::config(const fapi2::Target<K, M, V>& i_target,
        const fapi2::buffer<uint64_t> i_num_threads,
        const fapi2::buffer<uint64_t> i_gcr_ids[],
        const fapi2::buffer<uint64_t> i_rx_lanes[],
        const fapi2::buffer<uint64_t> i_tx_lanes[],
        const fapi2::buffer<uint64_t> i_spread_en,
        const fapi2::buffer<uint64_t> i_pcie_mode,
        const fapi2::buffer<uint64_t> i_serdes_16_to_1)
{
    FAPI_DBG("Start");

    FAPI_TRY(config_threads(i_target, i_num_threads));

    for (uint32_t l_thread = 0; l_thread < i_num_threads; l_thread++)
    {
        FAPI_TRY(config_lanes(i_target,
                              l_thread,
                              i_gcr_ids[l_thread],
                              i_rx_lanes[l_thread],
                              i_tx_lanes[l_thread],
                              i_spread_en,
                              i_pcie_mode,
                              i_serdes_16_to_1));
    }

    //Turn off unused threads.
    for (uint32_t l_thread = i_num_threads + 1; l_thread < IO_PPE_MAX_THREADS; l_thread++)
    {
        FAPI_TRY(FW_REG_FW_STOP_THREAD_PUT(iv_regs, i_target, l_thread, 1));
    }

    FAPI_TRY(iv_regs->flushCache(i_target));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

// ===============================================================
// BIST INIT
// ===============================================================

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::bist_init(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint32_t& i_thread,
        const uint8_t& i_bist_timer_sel)
{
    // write the timer
    FAPI_DBG("Setting BIST timer sel: %d", i_bist_timer_sel);
    FAPI_TRY(MEM_REG_RX_BER_TIMER_SEL_BIST_PUT(iv_regs, i_target, i_thread, i_bist_timer_sel));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::bist_init_rx(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint64_t& i_baseAddr,
        const uint32_t& i_thread,
        const uint8_t& i_esdTest,
        const uint8_t& i_dacTest,
        uint32_t i_rx_mask)
{
    const uint16_t c_reg_rx_datasm_cnt22 = 0x146;
    const uint16_t c_reg_rx_ctl_cntl5 = 0x124;
    const uint8_t c_max_lanes = 8;

    const uint8_t c_bit_rx_esd_test = 6;        // rx_datasm_cnt22
    const uint8_t c_bit_rx_dac_test = 15;       // rx_datasm_cnt22
    const uint8_t c_bit_rx_perv_capt = 48;      // rx_ctl_cntl5
    const uint8_t c_bit_tc_bist_shared = 49;    // rx_ctl_cntl5
    const uint8_t c_bit_tc_bist_code = 51;      // rx_ctl_cntl5
    const uint8_t c_len_rx = 1;

    fapi2::buffer<uint64_t> l_buffer;

    uint64_t l_addr = 0;
    uint8_t l_lane = 0;

    for (l_lane = 0; l_lane < c_max_lanes; l_lane++)
    {
        if (i_rx_mask & 0x1)
        {
            l_addr = buildAddr(i_baseAddr, 0, l_lane, c_reg_rx_datasm_cnt22);

            // Write rx_dac_test_check_en = 0
            FAPI_DBG("Setting RX DAC test Check enabled");
            l_buffer.insertFromRight(i_dacTest, c_bit_rx_dac_test, c_len_rx);

            // Write rx_dac_test_check_en = 0
            FAPI_DBG("Setting RX ESD test Check enabled");
            l_buffer.insertFromRight(i_esdTest, c_bit_rx_esd_test, c_len_rx);

            FAPI_TRY(putScom(i_target, l_addr, l_buffer),
                     "Error putscom to address 0x%08X.", l_addr);

            l_buffer = 0;

            l_addr = buildAddr(i_baseAddr, 0, l_lane, c_reg_rx_ctl_cntl5);

            // Write rx_pervasive_capt = 1
            FAPI_DBG("Setting RX Pervasive Capt enabled");
            l_buffer.insertFromRight(1, c_bit_rx_perv_capt, c_len_rx);

            // Write tc_bist_shared_ovrd = 1
            FAPI_DBG("Setting TC BIST shared overload enabled");
            l_buffer.insertFromRight(1, c_bit_tc_bist_shared, c_len_rx);

            // Write tc_bist_code_go = 1
            FAPI_DBG("Setting TC BIST code go enabled");
            l_buffer.insertFromRight(1, c_bit_tc_bist_code, c_len_rx);

            FAPI_TRY(putScom(i_target, l_addr, l_buffer),
                     "Error putscom to address 0x%08X.", l_addr);
        }

        i_rx_mask = i_rx_mask >> 1;
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::bist_init_tx(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint32_t& i_thread,
        uint32_t i_tx_mask)
{
    const uint8_t c_max_lanes = 8;
    uint8_t l_lane = 0;

    for (l_lane = 0; l_lane < c_max_lanes; l_lane++)
    {
        if (i_tx_mask & 0x1)
        {
            // Write fw_bist_en = 1
            FAPI_DBG("Setting BIST HS enabled");
            FAPI_TRY(FW_REG_FW_BIST_EN_PL_PUT(iv_regs, i_target, i_thread, l_lane, 1));
        }

        i_tx_mask = i_tx_mask >> 1;
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// ===============================================================
// BIST CLEANUP
// ===============================================================
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::bist_cleanup(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const fapi2::buffer<uint64_t> i_num_threads,
        const uint32_t i_rx_lanes_0_31,
        const uint32_t i_tx_lanes_0_31,
        fapi2::buffer<uint64_t>& o_done,
        fapi2::buffer<uint64_t>& o_fail)
{
    const fapi2::buffer<uint64_t> l_ext_cmd = IORESET_PL;

    FAPI_DBG("Starting BIST cleanup");
    FAPI_TRY(ext_cmd_start(i_target, i_num_threads, i_rx_lanes_0_31, i_tx_lanes_0_31, l_ext_cmd));

    FAPI_DBG("Polling for BIST cleanup done");
    FAPI_TRY(ext_cmd_poll(i_target, i_num_threads, l_ext_cmd, o_done, o_fail));

fapi_try_exit:
    FAPI_DBG("End BIST cleanup");
    return fapi2::current_err;
}

// ===============================================================
// PPE_INIT
// ===============================================================
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::ppe_init_threads(const fapi2::Target<K, M, V>& i_target,
        const fapi2::buffer<uint64_t> i_num_threads)
{
    FAPI_TRY(IMG_REG_PPE_NUM_THREADS_PUT(iv_regs, i_target, i_num_threads));
fapi_try_exit:
    return fapi2::current_err;
}


template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::ppe_init_thread(const fapi2::Target<K, M, V>& i_target,
        const fapi2::buffer<uint64_t> i_thread,
        const fapi2::buffer<uint64_t> i_gcr_id,
        const fapi2::buffer<uint64_t> i_num_rx_lanes,
        const fapi2::buffer<uint64_t> i_num_tx_lanes,
        const fapi2::buffer<uint64_t> i_spread_en,
        const fapi2::buffer<uint64_t> i_pcie_mode,
        const fapi2::buffer<uint64_t> i_serdes_16_to_1)
{
    FAPI_DBG("Starting io_ppe_common::ppe_init_thread");
    FAPI_TRY(FW_REG_FW_GCR_BUS_ID_PUT(iv_regs, i_target, i_thread, i_gcr_id));
    FAPI_TRY(FW_REG_FW_NUM_LANES_RX_PUT(iv_regs, i_target, i_thread, i_num_rx_lanes));
    FAPI_TRY(FW_REG_FW_NUM_LANES_TX_PUT(iv_regs, i_target, i_thread, i_num_tx_lanes));
    FAPI_TRY(FW_REG_FW_SERDES_16_TO_1_MODE_PUT(iv_regs, i_target, i_thread, i_serdes_16_to_1));
    FAPI_TRY(FW_REG_FW_SPREAD_EN_PUT(iv_regs, i_target, i_thread, i_spread_en));
    FAPI_TRY(FW_REG_FW_PCIE_MODE_PUT(iv_regs, i_target, i_thread, i_pcie_mode));
    FAPI_TRY(FW_REG_FW_STOP_THREAD_PUT(iv_regs, i_target, i_thread, 0));

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::ppe_init_thread");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::ppe_init(const fapi2::Target<K, M, V>& i_target,
        const fapi2::buffer<uint64_t> i_num_threads,
        const fapi2::buffer<uint64_t> i_gcr_ids[],
        const fapi2::buffer<uint64_t> i_rx_lanes[],
        const fapi2::buffer<uint64_t> i_tx_lanes[],
        const fapi2::buffer<uint64_t> i_spread_en,
        const fapi2::buffer<uint64_t> i_pcie_mode,
        const fapi2::buffer<uint64_t> i_serdes_16_to_1)
{
    FAPI_DBG("Starting io_ppe_common::ppe_init");

    FAPI_TRY(ppe_init_threads(i_target, i_num_threads));

    for (uint32_t l_thread = 0; l_thread < i_num_threads; l_thread++)
    {
        FAPI_TRY(ppe_init_thread(i_target,
                                 l_thread,
                                 i_gcr_ids[l_thread],
                                 i_rx_lanes[l_thread],
                                 i_tx_lanes[l_thread],
                                 i_spread_en,
                                 i_pcie_mode,
                                 i_serdes_16_to_1));
    }

    //Turn off unused threads.
    for (uint32_t l_thread = i_num_threads + 1; l_thread < IO_PPE_MAX_THREADS; l_thread++)
    {
        FAPI_TRY(FW_REG_FW_STOP_THREAD_PUT(iv_regs, i_target, l_thread, 1));
    }

    FAPI_TRY(iv_regs->flushCache(i_target));

    FAPI_TRY(iv_regs->hardReset(i_target));
    fapi2::delay(50000, 10000000); //ns, sim cycles
    FAPI_TRY(iv_regs->resume(i_target));

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::ppe_init");
    return fapi2::current_err;
}


// ===============================================================
// CLEAR_EXT_CMD_REQ
// ===============================================================
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::clear_ext_cmd_thread(const fapi2::Target<K, M, V>& i_target,
        const fapi2::buffer<uint64_t> i_thread)
{
    FAPI_DBG("Starting io_ppe_common::clear_ext_cmd_thread");

    fapi2::buffer<uint64_t> l_data = 0;

    FAPI_TRY(FW_REG_EXT_CMD_REQ_00_15_PUT(iv_regs, i_target, i_thread, l_data));
    FAPI_TRY(FW_REG_EXT_CMD_REQ_16_31_PUT(iv_regs, i_target, i_thread, l_data));

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::clear_ext_cmd_thread");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::clear_ext_cmd(const fapi2::Target<K, M, V>& i_target,
        const fapi2::buffer<uint64_t> i_num_threads)
{
    FAPI_DBG("Starting io_ppe_common::clear_ext_cmd");

    for (fapi2::buffer<uint64_t> l_thread = 0; l_thread < i_num_threads; l_thread++)
    {
        FAPI_TRY(clear_ext_cmd_thread(i_target, l_thread));
    }

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::clear_ext_cmd");
    return fapi2::current_err;
}


// ===============================================================
// EXT_CMD FUNCTIONS
// ===============================================================
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::ext_cmd_start_thread(const fapi2::Target<K, M, V>& i_target,
        const fapi2::buffer<uint32_t> i_thread,
        const uint32_t i_rx_lanes_0_31,
        const uint32_t i_tx_lanes_0_31,
        fapi2::buffer<uint64_t> i_ext_cmd_req)
{
    FAPI_DBG("Starting io_ppe_common::ext_cmd_start_thread");

    fapi2::buffer<uint64_t> l_data = 0;

    // RX
    fapi2::buffer<uint64_t> l_rx_lanes_0_15 = (i_rx_lanes_0_31 >> 16) & 0xFFFF;
    fapi2::buffer<uint64_t> l_rx_lanes_16_31 = (i_rx_lanes_0_31) & 0xFFFF;
    // TX
    fapi2::buffer<uint64_t> l_tx_lanes_0_15 = (i_tx_lanes_0_31 >> 16) & 0xFFFF;
    fapi2::buffer<uint64_t> l_tx_lanes_16_31 = (i_tx_lanes_0_31) & 0xFFFF;

    fapi2::buffer<uint64_t> l_ext_cmd_req_0_15 = (i_ext_cmd_req >> 16) & 0xFFFF;
    fapi2::buffer<uint64_t> l_ext_cmd_req_16_31 = (i_ext_cmd_req) & 0xFFFF;

    FAPI_DBG("l_rx_lanes_0_15 %x l_rx_lanes_16_31: %x l_tx_lanes_0_15: %x l_tx_lanes_16_31: %x", l_rx_lanes_0_15,
             l_rx_lanes_16_31, l_tx_lanes_0_15, l_tx_lanes_16_31);

    // RX
    FAPI_TRY(FW_REG_EXT_CMD_LANES_RX_00_15_PUT(iv_regs, i_target, i_thread, l_rx_lanes_0_15));
    FAPI_TRY(FW_REG_EXT_CMD_LANES_RX_16_31_PUT(iv_regs, i_target, i_thread, l_rx_lanes_16_31));
    // TX
    FAPI_TRY(FW_REG_EXT_CMD_LANES_TX_00_15_PUT(iv_regs, i_target, i_thread, l_tx_lanes_0_15));
    FAPI_TRY(FW_REG_EXT_CMD_LANES_TX_16_31_PUT(iv_regs, i_target, i_thread, l_tx_lanes_16_31));

    //MUST flush lanes before start
    FAPI_TRY(iv_regs->flushCache(i_target));

    FAPI_DBG("EXT_CMD_REQ_00_15");
    FAPI_TRY(FW_REG_EXT_CMD_REQ_00_15_PUT(iv_regs, i_target, i_thread, l_ext_cmd_req_0_15));

    FAPI_DBG("EXT_CMD_REQ_16_31");
    FAPI_TRY(FW_REG_EXT_CMD_REQ_16_31_PUT(iv_regs, i_target, i_thread, l_ext_cmd_req_16_31));

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::ext_cmd_start_thread");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::ext_cmd_start(const fapi2::Target<K, M, V>& i_target,
        const fapi2::buffer<uint64_t> i_num_threads,
        const uint32_t i_rx_lanes_0_31,
        const uint32_t i_tx_lanes_0_31,
        fapi2::buffer<uint64_t> i_ext_cmd_req)
{
    FAPI_DBG("Starting io_ppe_common::ext_cmd_start");

    for (fapi2::buffer<uint32_t> l_thread = 0; l_thread < i_num_threads; l_thread++)
    {
        FAPI_TRY(ext_cmd_start_thread(i_target, l_thread, i_rx_lanes_0_31, i_tx_lanes_0_31, i_ext_cmd_req));
    }

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::ext_cmd_start");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::ext_cmd_check(const fapi2::Target<K, M, V>& i_target,
        const fapi2::buffer<uint32_t> i_thread,
        fapi2::buffer<uint64_t> i_ext_cmd_req,
        fapi2::buffer<uint64_t>& o_done,
        fapi2::buffer<uint64_t>& o_fail)
{
    FAPI_DBG("Starting io_ppe_common::ext_cmd_check");

    fapi2::buffer<uint64_t> l_data = 0;

    FAPI_TRY(FW_REG_EXT_CMD_DONE_00_15_GET(iv_regs, i_target, i_thread, l_data));
    FAPI_DBG("io_ppe_common::ext_cmd_check 00_15 done: %llx exp: %llx\n", l_data, (i_ext_cmd_req >> 16));
    o_done = ((l_data << 16) & (0xFFFF0000 & i_ext_cmd_req)) == (0xFFFF0000 & i_ext_cmd_req);

    FAPI_TRY(FW_REG_EXT_CMD_DONE_16_31_GET(iv_regs, i_target, i_thread, l_data));
    FAPI_DBG("io_ppe_common::ext_cmd_check 16_31 done: %llx exp: %llx\n", l_data, (i_ext_cmd_req & 0xFFFF));
    o_done = o_done && ((l_data & (0xFFFF & i_ext_cmd_req)) == (0xFFFF & i_ext_cmd_req));

    FAPI_TRY(FW_REG_EXT_CMD_FAIL_00_15_GET(iv_regs, i_target, i_thread, l_data));
    FAPI_DBG("io_ppe_common::ext_cmd_check 00_15 fail: %llx\n", l_data);
    o_fail = l_data;

    FAPI_TRY(FW_REG_EXT_CMD_FAIL_16_31_GET(iv_regs, i_target, i_thread, l_data));
    FAPI_DBG("io_ppe_common::ext_cmd_check 16_31 fail: %llx\n", l_data);
    o_fail = o_fail || l_data;

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::ext_cmd_check");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::ext_cmd_poll(const fapi2::Target<K, M, V>& i_target,
        const fapi2::buffer<uint64_t> i_num_threads,
        fapi2::buffer<uint64_t> i_ext_cmd_req,
        fapi2::buffer<uint64_t>& o_done,
        fapi2::buffer<uint64_t>& o_fail)
{
    FAPI_DBG("Starting io_ppe_common::ext_cmd_poll");

    o_done = 0;
    o_fail = 0;
    int l_timeout = 1000;
    int l_loop_count = 0;

    for (fapi2::buffer<uint32_t> l_thread = 0; l_thread < i_num_threads; l_thread++)
    {
        while (!o_done && !o_fail && (l_loop_count < l_timeout))
        {
            FAPI_DBG("ext_cmd_poll: thread: %d", l_thread);
            FAPI_TRY(iv_regs->flushCache(i_target));
            FAPI_TRY(ext_cmd_check(i_target, l_thread, i_ext_cmd_req, o_done, o_fail));

            if (!o_done && !o_fail)
            {
                fapi2::delay(1000000, 1000000); //ns, sim cycles. 1ms
            }

            l_loop_count++;
        }
    }

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::ext_cmd_req_poll");
    return fapi2::current_err;
}

// ===============================================================
// BIST START
// ===============================================================
static fapi2::buffer<uint64_t> BIST_START_CMD = HW_REG_INIT_PG |
        DCCAL_PL | TX_ZCAL_PL |
        TX_BIST_TESTS_PL | TRAIN_PL |
        RECAL_PL | BIST_FINAL;

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::bist_start(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const fapi2::buffer<uint64_t> i_num_threads,
        const uint32_t i_rx_lanes_0_31,
        const uint32_t i_tx_lanes_0_31,
        const fapi2::buffer<uint64_t> i_ext_cmd_override)
{
    FAPI_DBG("Starting io_ppe_common::bist_start");

    fapi2::buffer<uint64_t> l_cmd;
    l_cmd = (!i_ext_cmd_override) ? BIST_START_CMD : i_ext_cmd_override;

    FAPI_TRY(ext_cmd_start(i_target, i_num_threads, i_rx_lanes_0_31, i_tx_lanes_0_31, l_cmd));

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::bist_start");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::bist_poll(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const fapi2::buffer<uint64_t> i_num_threads,
        fapi2::buffer<uint64_t>& o_done,
        fapi2::buffer<uint64_t>& o_fail,
        const fapi2::buffer<uint64_t> i_ext_cmd_override)
{
    FAPI_DBG("Starting io_ppe_common::bist_poll");

    fapi2::buffer<uint64_t> l_cmd;
    l_cmd = (!i_ext_cmd_override) ? BIST_START_CMD : i_ext_cmd_override;

    fapi2::buffer<uint64_t> l_done = 0;
    fapi2::buffer<uint64_t> l_fail = 0;

    FAPI_TRY(ext_cmd_poll(i_target, i_num_threads, l_cmd, l_done, l_fail));

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::bist_poll");
    return fapi2::current_err;
}


// ===============================================================
// ENABLE_LANES
// ===============================================================
static fapi2::buffer<uint64_t> ENABLE_LANES_CMD = POWER_ON_PL | TX_FIFO_INIT_PL;

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::enable_lanes(const fapi2::Target<K, M, V>& i_target,
        const fapi2::buffer<uint64_t> i_num_threads,
        const uint32_t i_rx_lanes_0_31,
        const uint32_t i_tx_lanes_0_31)
{
    FAPI_DBG("Starting io_ppe_common::enable_lanes");

    FAPI_TRY(ext_cmd_start(i_target, i_num_threads, i_rx_lanes_0_31, i_tx_lanes_0_31, ENABLE_LANES_CMD));

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::enable_lanes");
    return fapi2::current_err;
}


template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::check_enable_lanes_done(const fapi2::Target<K, M, V>& i_target,
        const fapi2::buffer<uint64_t> i_num_threads,
        fapi2::buffer<uint64_t>& o_done,
        fapi2::buffer<uint64_t>& o_fail)
{
    FAPI_DBG("Starting io_ppe_common::check_enable_lanes_done");

    FAPI_TRY(ext_cmd_poll(i_target, i_num_threads, ENABLE_LANES_CMD, o_done, o_fail));

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::check_enable_lanes_done");
    return fapi2::current_err;
}


// ===============================================================
// FAST MODE (SIM ONLY)
// ===============================================================
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::fast_mode_thread(const fapi2::Target<K, M, V>& i_target,
        const fapi2::buffer<uint64_t> i_thread)
{
    FAPI_DBG("Starting io_ppe_common::fast_mode_thread");

    fapi2::buffer<uint64_t> l_data = 1;
    FAPI_TRY(MEM_REG_LOFF_SETTING_OVR_ENB_PUT(iv_regs, i_target, i_thread, l_data));
    FAPI_TRY(MEM_REG_AMP_SETTING_OVR_ENB_PUT(iv_regs, i_target, i_thread, l_data));
    l_data = 0;
    FAPI_TRY(MEM_REG_RX_EO_CONVERGED_END_COUNT_PUT(iv_regs, i_target, i_thread, l_data));
    FAPI_TRY(MEM_REG_RX_MIN_RECAL_CNT_PUT(iv_regs, i_target, i_thread, l_data));
    l_data = 4;
    FAPI_TRY(MEM_REG_TX_DCC_MAIN_MIN_SAMPLES_PUT(iv_regs, i_target, i_thread, l_data));

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::fast_mode_thread");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::fast_mode(const fapi2::Target<K, M, V>& i_target,
        const fapi2::buffer<uint64_t> i_num_threads)
{
    FAPI_DBG("Starting io_ppe_common::fast_mode");

    for (fapi2::buffer<uint64_t> l_thread; l_thread < i_num_threads; l_thread++)
    {
        FAPI_TRY(fast_mode_thread(i_target, l_thread));
    }

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::fast_mode");
    return fapi2::current_err;
}

uint8_t get_num_lanes(uint32_t i_lane_mask)
{
    uint8_t count = 0;

    while(i_lane_mask)
    {
        count += i_lane_mask & 0x1;
        i_lane_mask >>= 0x1;
    }

    return count;
}
