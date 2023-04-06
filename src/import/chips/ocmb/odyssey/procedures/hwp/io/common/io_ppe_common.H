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

#define IO_PPE_COMMON_PRINT(_fail_, _fmt_, _args_...) if (!(_fail_)) { FAPI_DBG(_fmt_, ##_args_);} else { FAPI_ERR(_fmt_, ##_args_);}

enum IO_PPE_CONSTS
{
    IO_PPE_MAX_THREADS = 9,
    IO_PPE_DCCAL_DONE_POLL_TRYS = 100,
    IO_PPE_DCCAL_DONE_POLL_DELAY_NS = 10000,
    IO_PPE_DCCAL_DONE_POLL_DELAY_SIM_CYCLES = 100000000,
    IO_PPE_EL_DONE_POLL_TRYS = 100,
    IO_PPE_EL_DONE_POLL_DELAY_NS = 10000,
    IO_PPE_EL_DONE_POLL_DELAY_SIM_CYCLES = 100000000,

    IO_PPE_RX_DAC_CNTL3_PL = 0x0030,
    IO_PPE_RX_DAC_CNTL4_PL = 0x0040,
    IO_PPE_RX_DAC_CNTL6_PL = 0x0060,
    IO_PPE_RX_DAC_CNTL13_PL = 0x00D0,
    IO_PPE_RX_LTE_GAIN = 48,
    IO_PPE_RX_LTE_GAIN_LEN = 3,
    IO_PPE_RX_LTE_ZERO = 51,
    IO_PPE_RX_LTE_ZERO_LEN = 3,
    IO_PPE_RX_CTLE_PEAK1 = 56,
    IO_PPE_RX_CTLE_PEAK1_LEN = 4,
    IO_PPE_RX_CTLE_PEAK2 = 60,
    IO_PPE_RX_CTLE_PEAK2_LEN = 4,
    IO_PPE_HARD_RESET_DELAY_NS = 5000,
    IO_PPE_HARD_RESET_DELAY_SIM_CYCLES = 10000000,
    IO_PPE_RESUME_DELAY_NS = 5000,
    IO_PPE_RESUME_DELAY_SIM_CYCLES = 10000000,
};

//WARNING!!  Since these are hard coded and not generated
// from the image register definitions, any changes or
// inconsistances between image commands would cause
// problems.
enum IO_PPE_EXT_CMD_REQ_BITS
{
    //                              1111111111222222222233
    //                    01234567890123456789012345678901
    CLEAR             = 0b00000000000000000000000000000000,
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
    BIST_START_CMD    = HW_REG_INIT_PG | DCCAL_PL | TX_BIST_TESTS_PL | TRAIN_PL | RECAL_PL | BIST_FINAL,
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

        fapi2::ReturnCode ppe_start(const fapi2::Target<K, M, V>& i_target,
                                    const uint64_t& i_xixcr,
                                    const uint64_t& i_xidbgpro,
                                    const uint64_t& i_lfir);

        fapi2::ReturnCode config_ppe(const fapi2::Target<K, M, V>& i_target,
                                     const uint8_t i_num_threads,
                                     const uint32_t i_vio_volts);

        fapi2::ReturnCode config_thread(const fapi2::Target<K, M, V>& i_target,
                                        const uint8_t i_thread,
                                        const uint8_t i_gcr_id,
                                        const uint8_t i_num_rx_lanes,
                                        const uint8_t i_num_tx_lanes);

        fapi2::ReturnCode bist_init_thread(const fapi2::Target<K, M, V>& i_target,
                                           const uint8_t i_thread,
                                           const uint32_t i_rx_mask,
                                           const uint8_t i_bist_timer_sel);

        fapi2::ReturnCode bist_init(const fapi2::Target<K, M, V>& i_target,
                                    const uint32_t i_num_threads,
                                    const uint32_t i_rx_mask,
                                    const uint8_t i_dacTest,
                                    const uint8_t i_esdTest,
                                    const uint8_t i_bist_timer_sel);

        fapi2::ReturnCode bist_cleanup(const fapi2::Target<K, M, V>& i_target,
                                       const uint8_t i_thread,
                                       const uint32_t i_rx_lanes_0_31,
                                       const uint32_t i_tx_lanes_0_31,
                                       uint8_t& o_done,
                                       uint32_t& o_fail);

        fapi2::ReturnCode hss_init(const fapi2::Target<K, M, V>& i_target,
                                   const uint8_t i_thread,
                                   const uint32_t i_data_rate,
                                   const uint32_t i_channel_length,
                                   const uint8_t i_spread_en,
                                   const uint8_t i_pcie_mode,
                                   const uint32_t i_auto_recal_mask);
        fapi2::ReturnCode hss_init_tx(const fapi2::Target<K, M, V>& i_target,
                                      const uint8_t i_thread,
                                      const uint32_t i_lane_mask,
                                      const uint8_t i_tx_pre1,
                                      const uint8_t i_tx_pre2,
                                      const uint8_t i_tx_post);
        fapi2::ReturnCode hss_init_rx(const fapi2::Target<K, M, V>& i_target,
                                      const uint8_t i_thread,
                                      const uint32_t i_lane_mask,
                                      const int32_t& i_rx_lte_g,
                                      const int32_t& i_rx_lte_z,
                                      const int32_t& i_rx_peak1,
                                      const int32_t& i_rx_peak2,
                                      const int32_t& i_rx_pr_phase_step);

        fapi2::ReturnCode setup_func_margin(const fapi2::Target<K, M, V>& i_target,
                                            const uint8_t i_thread,
                                            const uint8_t i_rx_vert_offset,
                                            const uint8_t i_rx_horiz_data_offset,
                                            const uint8_t i_rx_horiz_edge_offset);

        fapi2::ReturnCode ext_cmd_start(const fapi2::Target<K, M, V>& i_target,
                                        const uint8_t i_thread,
                                        const uint32_t i_rx_lanes_0_31,
                                        const uint32_t i_tx_lanes_0_31,
                                        const uint32_t i_ext_cmd_req);

        fapi2::ReturnCode ext_cmd_check(const fapi2::Target<K, M, V>& i_target,
                                        const uint8_t i_thread,
                                        const uint32_t i_ext_cmd_req,
                                        uint8_t& o_done,
                                        uint32_t& o_fail);

        fapi2::ReturnCode ext_cmd_poll(const fapi2::Target<K, M, V>& i_target,
                                       const uint8_t i_thread,
                                       const uint32_t i_ext_cmd_req,
                                       uint8_t& o_done,
                                       uint32_t& o_fail);

        fapi2::ReturnCode debug_display(const fapi2::Target<K, M, V>& i_target,
                                        const uint8_t i_thread,
                                        const uint32_t i_rx_lanes_0_31,
                                        const uint32_t i_tx_lanes_0_31);

        fapi2::ReturnCode enable_lanes(const fapi2::Target<K, M, V>& i_target,
                                       const fapi2::buffer<uint64_t> i_num_threads,
                                       const uint32_t i_rx_lanes_0_31,
                                       const uint32_t i_tx_lanes_0_31);

        fapi2::ReturnCode check_enable_lanes_done(const fapi2::Target<K, M, V>& i_target,
                const fapi2::buffer<uint64_t> i_num_threads,
                fapi2::buffer<uint64_t>& o_done,
                fapi2::buffer<uint64_t>& o_fail);

        fapi2::ReturnCode bist_start(const fapi2::Target<K, M, V>& i_target,
                                     const uint8_t i_thread,
                                     const uint32_t i_rx_lanes_0_31,
                                     const uint32_t i_tx_lanes_0_31,
                                     const uint32_t i_ext_cmd_override);


        fapi2::ReturnCode bist_poll(const fapi2::Target<K, M, V>& i_target,
                                    const uint8_t i_num_threads,
                                    uint8_t& o_done,
                                    uint32_t& o_fail,
                                    const uint32_t i_ext_cmd_override);

        fapi2::ReturnCode fast_mode(const fapi2::Target<K, M, V>& i_target,
                                    const uint8_t i_thread);

        uint8_t get_num_lanes(uint32_t);
};

// ===============================================================
// phy_config
// ===============================================================


template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::config_ppe(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_num_threads,
        const uint32_t i_vio_mv)
{
    FAPI_DBG("Start");
    uint8_t l_vio_volts = 0;

    if (i_vio_mv > 900)
    {
        l_vio_volts = 0;
    }
    else if (i_vio_mv > 850)
    {
        l_vio_volts = 1;
    }
    else if (i_vio_mv > 800)
    {
        l_vio_volts = 2;
    }
    else
    {
        l_vio_volts = 3;
    }


    FAPI_TRY(IMG_REG_PPE_NUM_THREADS_PUT(iv_regs, i_target, i_num_threads));

    //"ppe_vio_volts": 2, >850mv && <=900mv
    FAPI_TRY(IMG_REG_PPE_VIO_VOLTS_PUT(iv_regs, i_target, l_vio_volts));

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

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::config_thread(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint8_t i_gcr_id,
        const uint8_t i_num_rx_lanes,
        const uint8_t i_num_tx_lanes)
{
    FAPI_DBG("Start");
    FAPI_TRY(FW_REG_FW_GCR_BUS_ID_PUT(iv_regs, i_target, i_thread, i_gcr_id));
    FAPI_TRY(FW_REG_FW_NUM_LANES_RX_PUT(iv_regs, i_target, i_thread, i_num_rx_lanes));
    FAPI_TRY(FW_REG_FW_NUM_LANES_TX_PUT(iv_regs, i_target, i_thread, i_num_tx_lanes));
    FAPI_TRY(FW_REG_FW_STOP_THREAD_PUT(iv_regs, i_target, i_thread, 0));
    FAPI_TRY(iv_regs->flushCache(i_target));
fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

// ===============================================================
// PPE START
// ===============================================================

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::ppe_start(const fapi2::Target<K, M, V>& i_target,
        const uint64_t& i_xixcr,
        const uint64_t& i_xidbgpro,
        const uint64_t& i_lfir)
{
    const uint64_t c_ppe_start_reset_iar = 0xfffe0040 >> 2;
    const uint8_t c_sram_scrub_enable_bit = 1;
    const uint8_t c_xidbgpro_bit = 32;
    const uint8_t c_xidbgpro_len = 30;

    const uint8_t c_ppe_halted_bit = 17;

    fapi2::buffer<uint64_t> l_buffer = 0;
    uint32_t l_iar = 0;

    // SRAM Scrub, set via Write-OR to CSCR
    FAPI_DBG("SRAM Scrub");
    l_buffer.setBit<c_sram_scrub_enable_bit>();
    FAPI_TRY(fapi2::putScom(i_target, (iv_regs->base_addr + 0xC), l_buffer));
    l_buffer.flush<0>();

    // Hard reset PPE
    FAPI_DBG("IO hard reset.");
    l_buffer = 0x6000000000000000ULL;
    FAPI_TRY(fapi2::putScom(i_target, i_xixcr, l_buffer));
    fapi2::delay(IO_PPE_HARD_RESET_DELAY_NS, IO_PPE_HARD_RESET_DELAY_SIM_CYCLES);

    // Verify IAR @ reset vector loc
    FAPI_DBG("Verify IAR reset.");
    FAPI_TRY(fapi2::getScom(i_target, i_xidbgpro, l_buffer));
    l_buffer.extractToRight<c_xidbgpro_bit, c_xidbgpro_len, uint32_t>(l_iar);
    FAPI_ASSERT(
        l_iar == c_ppe_start_reset_iar,
        fapi2::ODY_OMI_PPE_RESET()
        .set_TARGET_CHIP(i_target)
        .set_IAR(l_iar),
        "IAR (0x%8x) did not reset.", l_iar);
    l_buffer.flush<0>();

    // Resume PPE
    FAPI_DBG("IO resume");
    l_buffer = 0x2000000000000000ULL;
    FAPI_TRY(fapi2::putScom(i_target, i_xixcr, l_buffer));
    fapi2::delay(IO_PPE_RESUME_DELAY_NS, IO_PPE_RESUME_DELAY_SIM_CYCLES);

    FAPI_DBG("Verify IAR cleared.");
    FAPI_TRY(fapi2::getScom(i_target, i_xidbgpro, l_buffer));
    l_buffer.extractToRight<c_xidbgpro_bit, c_xidbgpro_len, uint32_t>(l_iar);
    FAPI_ASSERT(
        l_iar != c_ppe_start_reset_iar,
        fapi2::ODY_OMI_PPE_RESET()
        .set_TARGET_CHIP(i_target)
        .set_IAR(l_iar),
        "IAR (0x%8x) did not resume.", l_iar);
    l_buffer.flush<0>();

    // Clear Halted FIR Bit
    // Reg is RW_CLEAR
    FAPI_DBG("Clear halted FIR.");
    FAPI_TRY(fapi2::getScom(i_target, i_lfir, l_buffer),
             "Error getscom to MAC0_LFIR_REG.");
    l_buffer.setBit<c_ppe_halted_bit>();
    FAPI_TRY(fapi2::putScom(i_target, i_lfir, l_buffer),
             "Error putscom to MAC0_LFIR_REG (clear halt).");
    l_buffer.flush<0>();

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

// ===============================================================
// BIST INIT
// ===============================================================

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::bist_init_thread(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_rx_mask,
        const uint8_t i_bist_timer_sel)
{
    FAPI_DBG("Start");
    uint32_t l_rx_mask = i_rx_mask;

    // write the timer
    FAPI_DBG("Setting BIST timer sel: %d", i_bist_timer_sel);
    FAPI_TRY(MEM_REG_RX_BER_TIMER_SEL_BIST_PUT(iv_regs, i_target, i_thread, i_bist_timer_sel));

    // Write fw_bist_en = 1
    FAPI_DBG("Setting FW BIST EN enabled");
    FAPI_TRY(FW_REG_FW_BIST_EN_PUT(iv_regs, i_target, i_thread, 1));

    //"ppe_lte_gain_disable": 1,
    FAPI_TRY(MEM_REG_PPE_LTE_GAIN_DISABLE_PUT(iv_regs, i_target, i_thread, 1));
    //"ppe_lte_zero_disable": 1,
    FAPI_TRY(MEM_REG_PPE_LTE_ZERO_DISABLE_PUT(iv_regs, i_target, i_thread, 1));
    //"ppe_channel_loss": 2,
    FAPI_TRY(MEM_REG_PPE_CHANNEL_LOSS_PUT(iv_regs, i_target, i_thread, 2));

    //"rx_ctle_peak1_cal_disable": 0, *
    FAPI_TRY(MEM_REG_RX_CTLE_PEAK1_CAL_DISABLE_PUT(iv_regs, i_target, i_thread, 0));

    for (uint32_t l_lane = 0; l_lane < 8; l_lane++)
    {
        if (l_rx_mask & 0x80000000)
        {
            //"rx_quad_ph_adj_min_check": 0, *
            FAPI_TRY(MEM_REG_RX_QUAD_PH_ADJ_MIN_CHECK_PL_PUT(iv_regs, i_target, i_thread, l_lane, 0));
            //"rx_quad_ph_adj_max_check": 31 *
            FAPI_TRY(MEM_REG_RX_QUAD_PH_ADJ_MAX_CHECK_PL_PUT(iv_regs, i_target, i_thread, l_lane, 31));
        }

        l_rx_mask <<= 1;
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::bist_init(const fapi2::Target<K, M, V>& i_target,
        const uint32_t i_num_threads,
        const uint32_t i_rx_mask,
        const uint8_t i_dacTest,
        const uint8_t i_esdTest,
        const uint8_t i_bist_timer_sel)
{
    const uint16_t c_reg_rx_datasm_cnt22 = 0x1460;
    const uint16_t c_reg_rx_ctl_cntl5 = 0x1240;

    const uint8_t c_bit_rx_esd_test = 6;        // rx_datasm_cnt22
    const uint8_t c_bit_rx_dac_test = 15;       // rx_datasm_cnt22
    const uint8_t c_bit_rx_perv_capt =   0;   //48;      // rx_ctl_cntl5
    const uint8_t c_bit_tc_bist_shared = 1;   //49;       // rx_ctl_cntl5
    const uint8_t c_bit_tc_bist_code =   3;   //51;      // rx_ctl_cntl5
    const uint8_t c_len_rx = 1;

    fapi2::buffer<uint64_t> l_buffer;

    uint8_t l_lane = 0;
    uint64_t l_addr = 0;
    uint32_t l_rx_mask = i_rx_mask;

    fapi2::buffer<uint64_t> l_data;

    l_addr = buildAddr(iv_regs->base_addr, 0, 0, c_reg_rx_datasm_cnt22);

    // Write rx_dac_test_check_en = 0
    FAPI_DBG("Setting RX DAC test Check enabled");
    l_buffer.insertFromRight(i_dacTest, c_bit_rx_dac_test + 48, c_len_rx);

    // Write rx_dac_test_check_en = 0
    FAPI_DBG("Setting RX ESD test Check enabled");
    l_buffer.insertFromRight(i_esdTest, c_bit_rx_esd_test + 48, c_len_rx);

    FAPI_TRY(putScom(i_target, l_addr, l_buffer),
             "Error putscom to address 0x%08X.", l_addr);

    l_buffer = 0;

    l_addr = buildAddr(iv_regs->base_addr, 0, 0, c_reg_rx_ctl_cntl5);

    // Write rx_pervasive_capt = 1
    FAPI_DBG("Setting RX Pervasive Capt enabled");
    l_buffer.insertFromRight(1, c_bit_rx_perv_capt + 48, c_len_rx);

    // Write tc_bist_shared_ovrd = 1
    FAPI_DBG("Setting TC BIST shared overload enabled");
    l_buffer.insertFromRight(1, c_bit_tc_bist_shared + 48, c_len_rx);

    // Write tc_bist_code_go = 1
    FAPI_DBG("Setting TC BIST code go enabled");
    l_buffer.insertFromRight(1, c_bit_tc_bist_code + 48, c_len_rx);

    FAPI_TRY(putScom(i_target, l_addr, l_buffer),
             "Error putscom to address 0x%08X.", l_addr);

    for (l_lane = 0; l_lane < 8; l_lane++)
    {
        if (l_rx_mask & 0x80000000)
        {
            l_buffer.flush<0>();
            l_buffer.insertFromRight(7, IO_PPE_RX_LTE_GAIN, IO_PPE_RX_LTE_GAIN_LEN);
            l_buffer.insertFromRight(0, IO_PPE_RX_LTE_ZERO, IO_PPE_RX_LTE_ZERO_LEN);
            l_addr = buildAddr(iv_regs->base_addr, 0, l_lane, IO_PPE_RX_DAC_CNTL3_PL); // A Bank LTE G/Z
            FAPI_TRY(putScom(i_target, l_addr, l_buffer));
            l_addr = buildAddr(iv_regs->base_addr, 0, l_lane, IO_PPE_RX_DAC_CNTL4_PL); // B Bank LTE G/Z
            FAPI_TRY(putScom(i_target, l_addr, l_buffer));
        }

        l_rx_mask <<= 1;
    }

    FAPI_TRY(iv_regs->flushCache(i_target));

    for (uint32_t l_thread = 0; l_thread < i_num_threads; l_thread++)
    {
        FAPI_TRY(bist_init_thread(i_target,
                                  l_thread,
                                  i_rx_mask,
                                  i_bist_timer_sel));
    }

    FAPI_TRY(iv_regs->flushCache(i_target));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

// ===============================================================
// BIST CLEANUP
// ===============================================================
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::bist_cleanup(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_rx_lanes_0_31,
        const uint32_t i_tx_lanes_0_31,
        uint8_t& o_done,
        uint32_t& o_fail)
{
    const fapi2::buffer<uint64_t> l_ext_cmd = IORESET_PL;

    FAPI_DBG("Starting BIST cleanup");

    FAPI_DBG("Clearing error registers");
    FAPI_TRY(FW_REG_FW_BIST_EN_PUT(iv_regs, i_target, i_thread, 0));

    FAPI_TRY(MEM_REG_RX_DISABLE_BANK_PDWN_PUT(iv_regs, i_target, i_thread, 0));

    FAPI_TRY(MEM_REG_PPE_ERROR_STATE_PUT(iv_regs, i_target, i_thread, 0));
    FAPI_TRY(MEM_REG_PPE_ERROR_LANE_PUT(iv_regs, i_target, i_thread, 0));
    FAPI_TRY(MEM_REG_PPE_ERROR_THREAD_PUT(iv_regs, i_target, i_thread, 0));
    FAPI_TRY(MEM_REG_PPE_ERROR_VALID_PUT(iv_regs, i_target, i_thread, 0));

    FAPI_TRY(MEM_REG_RX_LANE_FAIL_0_15_PUT(iv_regs, i_target, i_thread, 0));
    FAPI_TRY(MEM_REG_RX_LANE_FAIL_16_23_PUT(iv_regs, i_target, i_thread, 0));

    FAPI_TRY(MEM_REG_TX_BIST_FAIL_0_15_PUT(iv_regs, i_target, i_thread, 0));
    FAPI_TRY(MEM_REG_TX_BIST_FAIL_16_23_PUT(iv_regs, i_target, i_thread, 0));

    FAPI_TRY(MEM_REG_PPE_SERVO_STATUS0_PUT(iv_regs, i_target, i_thread, 0));
    FAPI_TRY(MEM_REG_PPE_SERVO_STATUS1_PUT(iv_regs, i_target, i_thread, 0));

    FAPI_DBG("Clearing per-image registers");
    FAPI_TRY(IMG_REG_PPE_DEBUG_LOG_NUM_PUT(iv_regs, i_target, 0));

    FAPI_TRY(iv_regs->flushCache(i_target));

    FAPI_DBG("Starting BIST cleanup ext_cmd");
    FAPI_TRY(ext_cmd_start(i_target, i_thread, i_rx_lanes_0_31, i_tx_lanes_0_31, l_ext_cmd));

    FAPI_DBG("Polling for BIST cleanup ext_cmd done");
    FAPI_TRY(ext_cmd_poll(i_target, i_thread, l_ext_cmd, o_done, o_fail));


fapi_try_exit:
    FAPI_DBG("End BIST cleanup");
    return fapi2::current_err;
}

// ===============================================================
// PPE_INIT
// ===============================================================
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::hss_init(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_data_rate,
        const uint32_t i_channel_length,
        const uint8_t i_spread_en,
        const uint8_t i_pcie_mode,
        const uint32_t i_auto_recal_mask)
{
    FAPI_DBG("Starting io_ppe_common::hss_init");
    const uint32_t c_high_loss_channel = 8000; // 8000 mils or 8.000 inches
    uint32_t l_channel_loss_parm = 2; // 0: high loss, 1: mid loss, 2: low loss
    uint8_t l_ppe_data_rate = 0;

    if (i_data_rate <= 2500)
    {
        l_ppe_data_rate = 0;
    }
    else if (i_data_rate <= 5000)
    {
        l_ppe_data_rate = 1;
    }
    else if (i_data_rate <= 8000)
    {
        l_ppe_data_rate = 2;
    }
    else if (i_data_rate <= 16000)
    {
        l_ppe_data_rate = 3;
    }
    else if (i_data_rate <= 21333)
    {
        l_ppe_data_rate = 4;
    }
    else if (i_data_rate <= 25600)
    {
        l_ppe_data_rate = 5;
    }
    else if (i_data_rate <= 32000)
    {
        l_ppe_data_rate = 6;
    }
    else
    {
        l_ppe_data_rate = 7;
    }

    MEM_REG_PPE_DATA_RATE_PUT(iv_regs, i_target, i_thread, l_ppe_data_rate);

    if (i_channel_length > c_high_loss_channel)
    {
        l_channel_loss_parm = 0;
    }

    MEM_REG_PPE_CHANNEL_LOSS_PUT(iv_regs, i_target, i_thread, l_channel_loss_parm);

    FAPI_TRY(FW_REG_FW_SERDES_16_TO_1_MODE_PUT(iv_regs, i_target, i_thread, 1));
    FAPI_TRY(FW_REG_FW_SPREAD_EN_PUT(iv_regs, i_target, i_thread, i_spread_en));
    FAPI_TRY(FW_REG_FW_PCIE_MODE_PUT(iv_regs, i_target, i_thread, i_pcie_mode));

    MEM_REG_RX_ENABLE_AUTO_RECAL_0_15_PUT(iv_regs, i_target, i_thread, (i_auto_recal_mask >> 16) & 0xFFFF);
    MEM_REG_RX_ENABLE_AUTO_RECAL_16_23_PUT(iv_regs, i_target, i_thread, (i_auto_recal_mask >> 8) & 0xFFFF);
    FAPI_TRY(iv_regs->flushCache(i_target));
fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::hss_init");
    return fapi2::current_err;
}
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::hss_init_tx(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_lane_mask,
        const uint8_t i_tx_pre1,
        const uint8_t i_tx_pre2,
        const uint8_t i_tx_post)
{
    FAPI_DBG("Starting io_ppe_common::hss_init_tx");
    MEM_REG_TX_FFE_PRE1_COEF_PUT(iv_regs, i_target, i_thread, i_tx_pre1);
    MEM_REG_TX_FFE_PRE2_COEF_PUT(iv_regs, i_target, i_thread, i_tx_pre2);
    MEM_REG_TX_FFE_POST_COEF_PUT(iv_regs, i_target, i_thread, i_tx_post);
    FAPI_TRY(iv_regs->flushCache(i_target));
fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::hss_init_tx");
    return fapi2::current_err;
}
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::hss_init_rx(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_lane_mask,
        const int32_t& i_rx_lte_g,
        const int32_t& i_rx_lte_z,
        const int32_t& i_rx_peak1,
        const int32_t& i_rx_peak2,
        const int32_t& i_rx_pr_phase_step)
{
    FAPI_DBG("Starting io_ppe_common::hss_init_rx");
    uint64_t l_addr = 0;
    uint8_t l_lane = 0;
    fapi2::buffer<uint64_t> l_lte_buffer = 0;
    fapi2::buffer<uint64_t> l_peak_buffer = 0;

    if (i_rx_lte_g != -1)
    {
        FAPI_TRY(MEM_REG_PPE_LTE_GAIN_DISABLE_PUT(iv_regs, i_target, i_thread, 1));
        l_lte_buffer.insertFromRight<IO_PPE_RX_LTE_GAIN, IO_PPE_RX_LTE_GAIN_LEN, uint32_t>(i_rx_lte_g);
    }

    if (i_rx_lte_z != -1)
    {
        FAPI_TRY(MEM_REG_PPE_LTE_ZERO_DISABLE_PUT(iv_regs, i_target, i_thread, 1));
        l_lte_buffer.insertFromRight<IO_PPE_RX_LTE_ZERO, IO_PPE_RX_LTE_ZERO_LEN, uint32_t>(i_rx_lte_z);
    }

    if (i_rx_peak1 != -1)
    {
        FAPI_TRY(MEM_REG_RX_CTLE_PEAK1_CAL_DISABLE_PUT(iv_regs, i_target, i_thread, 1));
        l_peak_buffer.insertFromRight<IO_PPE_RX_CTLE_PEAK1, IO_PPE_RX_CTLE_PEAK1_LEN, uint32_t>(i_rx_peak1);
    }

    if (i_rx_peak2 != -1)
    {
        FAPI_TRY(MEM_REG_RX_CTLE_PEAK2_CAL_DISABLE_PUT(iv_regs, i_target, i_thread, 1));
        l_peak_buffer.insertFromRight<IO_PPE_RX_CTLE_PEAK2, IO_PPE_RX_CTLE_PEAK2_LEN, uint32_t>(i_rx_peak2);
    }

    for (l_lane = 0; l_lane < 8; l_lane++)
    {
        if (i_lane_mask & (0x80000000 >> l_lane))
        {
            // LTE Gain and Zero
            l_addr = buildAddr(iv_regs->base_addr, 0, l_lane, IO_PPE_RX_DAC_CNTL3_PL); // A Bank LTE G/Z
            FAPI_TRY(putScom(i_target, l_addr, l_lte_buffer));
            l_addr = buildAddr(iv_regs->base_addr, 0, l_lane, IO_PPE_RX_DAC_CNTL4_PL); // B Bank LTE G/Z
            FAPI_TRY(putScom(i_target, l_addr, l_lte_buffer));

            // CTLE Peak1 and Peak2
            l_addr = buildAddr(iv_regs->base_addr, 0, l_lane, IO_PPE_RX_DAC_CNTL6_PL); // A Bank CTLE PEAK1/2
            FAPI_TRY(putScom(i_target, l_addr, l_peak_buffer));
            l_addr = buildAddr(iv_regs->base_addr, 0, l_lane, IO_PPE_RX_DAC_CNTL13_PL); // B Bank CTLE PEAK1/2
            FAPI_TRY(putScom(i_target, l_addr, l_peak_buffer));

            // TODO what do we do with phase_step? It is overwritten in the ppe code
        }
    }

    FAPI_TRY(iv_regs->flushCache(i_target));
fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::hss_init_rx");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::setup_func_margin(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint8_t i_rx_vert_offset,
        const uint8_t i_rx_horiz_data_offset,
        const uint8_t i_rx_horiz_edge_offset)
{
    FAPI_DBG("Starting io_ppe_common::setup_func_margin");
    FAPI_TRY(MEM_REG_PPE_OFFSET_MARGIN_MODE_PUT(iv_regs, i_target, i_thread, 3));

    FAPI_TRY(MEM_REG_PPE_LOFF_OFFSET_D_OVERRIDE_PUT(iv_regs, i_target, i_thread, i_rx_vert_offset));
    FAPI_TRY(MEM_REG_PPE_LOFF_OFFSET_PAUSE_PUT(iv_regs, i_target, i_thread, 0));

    FAPI_TRY(MEM_REG_PPE_PR_OFFSET_D_OVERRIDE_PUT(iv_regs, i_target, i_thread, i_rx_horiz_data_offset));
    FAPI_TRY(MEM_REG_PPE_PR_OFFSET_E_OVERRIDE_PUT(iv_regs, i_target, i_thread, i_rx_horiz_edge_offset));
    FAPI_TRY(MEM_REG_PPE_PR_OFFSET_PAUSE_PUT(iv_regs, i_target, i_thread, 0));

    FAPI_TRY(iv_regs->flushCache(i_target));
fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::setup_func_margin");
    return fapi2::current_err;
}


// ===============================================================
// EXT_CMD FUNCTIONS
// ===============================================================
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::ext_cmd_start(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_rx_lanes_0_31,
        const uint32_t i_tx_lanes_0_31,
        const uint32_t i_ext_cmd_req)
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

    // RX
    FAPI_TRY(FW_REG_EXT_CMD_LANES_RX_00_15_PUT(iv_regs, i_target, i_thread, l_rx_lanes_0_15));
    FAPI_TRY(FW_REG_EXT_CMD_LANES_RX_16_31_PUT(iv_regs, i_target, i_thread, l_rx_lanes_16_31));
    // TX
    FAPI_TRY(FW_REG_EXT_CMD_LANES_TX_00_15_PUT(iv_regs, i_target, i_thread, l_tx_lanes_0_15));
    FAPI_TRY(FW_REG_EXT_CMD_LANES_TX_16_31_PUT(iv_regs, i_target, i_thread, l_tx_lanes_16_31));

    //MUST flush lanes before start
    FAPI_TRY(iv_regs->flushCache(i_target));

    FAPI_TRY(FW_REG_EXT_CMD_REQ_00_15_PUT(iv_regs, i_target, i_thread, l_ext_cmd_req_0_15));
    FAPI_TRY(FW_REG_EXT_CMD_REQ_16_31_PUT(iv_regs, i_target, i_thread, l_ext_cmd_req_16_31));

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::ext_cmd_start_thread");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::ext_cmd_check(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_ext_cmd_req,
        uint8_t& o_done,
        uint32_t& o_fail)
{
    FAPI_DBG("Starting io_ppe_common::ext_cmd_check");

    fapi2::buffer<uint64_t> l_data = 0;

    FAPI_TRY(FW_REG_EXT_CMD_DONE_00_15_GET(iv_regs, i_target, i_thread, l_data));
    o_done = ((l_data << 16) & (0xFFFF0000 & i_ext_cmd_req)) == (0xFFFF0000 & i_ext_cmd_req);
    FAPI_DBG("io_ppe_common::ext_cmd_check FW_REG_EXT_CMD_DONE_00_15_GET: l_data 0x%08X%08X, exp: 0x%04X\n",
             (l_data >> 32) & 0xFFFFFFFF, l_data & 0xFFFFFFFF, (i_ext_cmd_req & 0xFFFF0000) >> 16);

    FAPI_TRY(FW_REG_EXT_CMD_DONE_16_31_GET(iv_regs, i_target, i_thread, l_data));
    o_done = o_done && ((l_data & (0xFFFF & i_ext_cmd_req)) == (0xFFFF & i_ext_cmd_req));
    FAPI_DBG("io_ppe_common::ext_cmd_check FW_REG_EXT_CMD_DONE_16_31_GET: l_data 0x%08X%08X, exp: 0x%04X\n",
             (l_data >> 32) & 0xFFFFFFFF, l_data & 0xFFFFFFFF, i_ext_cmd_req & 0xFFFF);

    FAPI_TRY(FW_REG_EXT_CMD_FAIL_00_15_GET(iv_regs, i_target, i_thread, l_data));
    o_fail = (l_data << 16); ////Update to shift bits 00_15 left 16 bits before we do a bitwise or with the 16_31 bits
    FAPI_DBG("io_ppe_common::ext_cmd_check FW_REG_EXT_CMD_FAIL_00_15_GET: l_data 0x%08X%08X\n",
             (l_data >> 32) & 0xFFFFFFFF, l_data & 0xFFFFFFFF);

    FAPI_TRY(FW_REG_EXT_CMD_FAIL_16_31_GET(iv_regs, i_target, i_thread, l_data));
    o_fail = o_fail | l_data;
    FAPI_DBG("io_ppe_common::ext_cmd_check FW_REG_EXT_CMD_FAIL_16_31_GET: l_data 0x%08X%08X\n",
             (l_data >> 32) & 0xFFFFFFFF, l_data & 0xFFFFFFFF);

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::ext_cmd_check (done %d, fail 0x%08x)", o_done, o_fail);
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::ext_cmd_poll(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_ext_cmd_req,
        uint8_t& o_done,
        uint32_t& o_fail)
{
    FAPI_DBG("Starting io_ppe_common::ext_cmd_poll");

    o_done = 0;
    o_fail = 0;
    int l_timeout = 1000;
    int l_loop_count = 0;

    while (!o_done && (l_loop_count < l_timeout))
    {
        FAPI_DBG("ext_cmd_poll: thread: %d", i_thread);
        FAPI_TRY(iv_regs->flushCache(i_target));
        FAPI_TRY(ext_cmd_check(i_target, i_thread, i_ext_cmd_req, o_done, o_fail));

        if (!o_done)
        {
            fapi2::delay(2000000, 2000000); //ns, sim cycles. 1ms
        }

        l_loop_count++;
    }

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::ext_cmd_req_poll");
    return fapi2::current_err;
}

// ===============================================================
// Debug dump
// ===============================================================
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::debug_display(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_rx_lanes_0_31,
        const uint32_t i_tx_lanes_0_31)
{
    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_data = 0;
    uint32_t l_lane = 0;

    FAPI_TRY(iv_regs->flushCache(i_target));

    FAPI_TRY(MEM_REG_PPE_ERROR_STATE_GET(iv_regs, i_target, i_thread, l_data));
    FAPI_DBG("PPE_ERROR_STATE: 0x%X, thread: %d", l_data, i_thread);

    FAPI_TRY(MEM_REG_TX_BIST_FAIL_0_15_GET(iv_regs, i_target, i_thread, l_data));
    FAPI_DBG("MEM_REG_TX_BIST_FAIL_0_15: 0x%X, thread: %d", l_data, i_thread);

    FAPI_TRY(MEM_REG_PPE_ERROR_VALID_GET(iv_regs, i_target, i_thread, l_data));
    IO_PPE_COMMON_PRINT(l_data != 0, "Thread %d PPE_ERROR_VALID: %d", i_thread, l_data)

    if (l_data) // ppe_error_valid is set
    {
        FAPI_TRY(MEM_REG_PPE_ERROR_THREAD_GET(iv_regs, i_target, i_thread, l_data));
        FAPI_ERR("Thread %d PPE_ERROR_THREAD: %d", i_thread, l_data);
        FAPI_TRY(MEM_REG_PPE_ERROR_LANE_GET(iv_regs, i_target, i_thread, l_data));
        FAPI_ERR("Thread %d PPE_ERROR_LANE: %d", i_thread, l_data);
        FAPI_TRY(MEM_REG_PPE_ERROR_STATE_GET(iv_regs, i_target, i_thread, l_data));
        FAPI_ERR("Thread %d PPE_ERROR_STATE: 0x%04x", i_thread, l_data);
    }


    FAPI_TRY(MEM_REG_RX_LANE_FAIL_0_15_GET(iv_regs, i_target, i_thread, l_data));
    IO_PPE_COMMON_PRINT(l_data != 0, "Thread %d RX_LANE_FAIL_0_15:  0x%04x", i_thread, l_data)

    FAPI_TRY(MEM_REG_RX_LANE_FAIL_16_23_GET(iv_regs, i_target, i_thread, l_data));
    IO_PPE_COMMON_PRINT(l_data != 0, "Thread %d RX_LANE_FAIL_16_23: 0x%04x", i_thread, l_data)


    FAPI_TRY(MEM_REG_TX_BIST_FAIL_0_15_GET(iv_regs, i_target, i_thread, l_data));
    IO_PPE_COMMON_PRINT(l_data != 0, "Thread %d TX_BIST_FAIL_0_15:  0x%04x", i_thread, l_data)

    FAPI_TRY(MEM_REG_TX_BIST_FAIL_16_23_GET(iv_regs, i_target, i_thread, l_data));
    IO_PPE_COMMON_PRINT(l_data != 0, "Thread %d TX_BIST_FAIL_16_23: 0x%04x", i_thread, l_data)


    for (uint32_t l_lanes = i_rx_lanes_0_31; l_lanes & 0x80000000; l_lanes <<= 1)
    {
        FAPI_TRY(MEM_REG_RX_STEP_FAIL_ALIAS_PL_GET(iv_regs, i_target, i_thread, l_lane, l_data));
        IO_PPE_COMMON_PRINT(l_data != 0, "Thread %d, Lane %d RX_STEP_FAIL_ALIAS:  0x%04x", i_thread, l_lane, l_data)
        l_lane++;
    }


    FAPI_TRY(MEM_REG_PPE_SERVO_STATUS1_GET(iv_regs, i_target, i_thread, l_data));

    if (l_data & (0x0F80)) // Check for any errors or min/max results
    {
        FAPI_TRY(MEM_REG_PPE_SERVO_STATUS0_GET(iv_regs, i_target, i_thread, l_data));
        FAPI_ERR("Thread %d PPE_SERVO_STATUS0:  0x%04x", i_thread, l_data);
        FAPI_TRY(MEM_REG_PPE_SERVO_STATUS1_GET(iv_regs, i_target, i_thread, l_data));
        FAPI_ERR("Thread %d PPE_SERVO_STATUS1:  0x%04x", i_thread, l_data);
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// ===============================================================
// BIST START
// ===============================================================
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::bist_start(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_rx_lanes_0_31,
        const uint32_t i_tx_lanes_0_31,
        const uint32_t i_ext_cmd_override)
{
    FAPI_DBG("Starting io_ppe_common::bist_start");

    fapi2::buffer<uint64_t> l_cmd;
    l_cmd = (!i_ext_cmd_override) ? BIST_START_CMD : i_ext_cmd_override;

    FAPI_TRY(ext_cmd_start(i_target, i_thread, i_rx_lanes_0_31, i_tx_lanes_0_31, l_cmd));

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::bist_start");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::bist_poll(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        uint8_t& o_done,
        uint32_t& o_fail,
        const uint32_t i_ext_cmd_override)
{
    FAPI_DBG("Starting io_ppe_common::bist_poll");

    fapi2::buffer<uint64_t> l_cmd;
    fapi2::buffer<uint64_t> l_data = 0;
    l_cmd = (!i_ext_cmd_override) ? BIST_START_CMD : i_ext_cmd_override;

    FAPI_TRY(ext_cmd_poll(i_target, i_thread, l_cmd, o_done, o_fail));

    FAPI_TRY(MEM_REG_BIST_OVERALL_PASS_GET(iv_regs, i_target, i_thread, l_data));
    IO_PPE_COMMON_PRINT(l_data == 0, "Thread %d BIST_OVERALL_PASS: 0x%04x", i_thread, l_data)

    // Use bit 31 for no overall-pass
    o_fail = o_fail | (l_data != 1);

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
fapi2::ReturnCode io_ppe_common<K, M, V>::fast_mode(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread)
{
    FAPI_DBG("Starting io_ppe_common::fast_mode");

    fapi2::buffer<uint64_t> l_data = 1;
    FAPI_TRY(MEM_REG_LOFF_SETTING_OVR_ENB_PUT(iv_regs, i_target, i_thread, l_data));
    FAPI_TRY(MEM_REG_AMP_SETTING_OVR_ENB_PUT(iv_regs, i_target, i_thread, l_data));
    l_data = 0;
    FAPI_TRY(MEM_REG_RX_EO_CONVERGED_END_COUNT_PUT(iv_regs, i_target, i_thread, l_data));
    FAPI_TRY(MEM_REG_RX_MIN_RECAL_CNT_PUT(iv_regs, i_target, i_thread, l_data));
    l_data = 4;
    FAPI_TRY(MEM_REG_TX_DCC_MAIN_MIN_SAMPLES_PUT(iv_regs, i_target, i_thread, l_data));

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::fast_mode");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
uint8_t io_ppe_common<K, M, V>::get_num_lanes(uint32_t i_lane_mask)
{
    uint8_t count = 0;

    while(i_lane_mask)
    {
        count += i_lane_mask & 0x1;
        i_lane_mask >>= 0x1;
    }

    return count;
}
