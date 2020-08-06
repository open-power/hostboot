/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_ppe_regs.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_io_ppe_regs.H
/// @brief GENERTED DO NOT EDIT - Objects for manipulating PPE SRAM registers
///
/// *HWP HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

#ifndef __P10_IO_PPE_REGS_H_
#define __P10_IO_PPE_REGS_H_

#include <p10_io_ppe_lib.H>

class p10_io_ppe_cache_proc
{
    public:
        p10_io_ppe_cache_proc();

        static const uint64_t p10_io_ppe_img_regs_start = 0xffff1190ull;
        static const uint64_t p10_io_ppe_fw_regs0_start = 0xffff11b0ull;
        static const uint64_t p10_io_ppe_fw_regs1_start = 0xffff11c0ull;
        static const uint64_t p10_io_ppe_fw_regs2_start = 0xffff11d0ull;
        static const uint64_t p10_io_ppe_fw_regs3_start = 0xffff11e0ull;
        static const uint64_t p10_io_ppe_fw_regs4_start = 0xffff11f0ull;
        static const uint64_t p10_io_ppe_kernel_stack_start = 0xffff1200ull;
        static const uint64_t p10_io_ppe_io_thread_stack0_start = 0xffff1400ull;
        static const uint64_t p10_io_ppe_io_thread_stack1_start = 0xffff1800ull;
        static const uint64_t p10_io_ppe_io_thread_stack2_start = 0xffff1c00ull;
        static const uint64_t p10_io_ppe_io_thread_stack3_start = 0xffff2000ull;
        static const uint64_t p10_io_ppe_io_thread_stack4_start = 0xffff2400ull;
        static const uint64_t p10_io_ppe_mem_regs0_start = 0xffff2800ull;
        static const uint64_t p10_io_ppe_mem_regs1_start = 0xffff2c00ull;
        static const uint64_t p10_io_ppe_mem_regs2_start = 0xffff3000ull;
        static const uint64_t p10_io_ppe_mem_regs3_start = 0xffff3400ull;
        static const uint64_t p10_io_ppe_mem_regs4_start = 0xffff3800ull;
        static const uint64_t p10_io_ppe_debug_log_start = 0xffff3c00ull;

        p10_io_ppe_cache p10_io_ppe_img_regs;

        p10_io_ppe_sram_reg p10_io_ppe_ppe_current_thread;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_debug_log_num;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_error_lane;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_error_state;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_error_thread;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_error_valid;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_num_threads;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_bist_busy;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_bist_busy_done_alias;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_bist_busy_done_fail_alias;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_bist_done;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_bist_done_fail_alias;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_bist_en;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_bist_fail;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_busy;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_busy_done_alias;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_busy_done_error_alias;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_done;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_done_error_alias;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_error;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_n;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_p;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_vio_volts;
        p10_io_ppe_sram_reg p10_io_ppe_ppe_watchdog_select_sim_mode;
        p10_io_ppe_sram_reg p10_io_ppe_ucontroller_test_en;
        p10_io_ppe_sram_reg p10_io_ppe_ucontroller_test_stat;

        p10_io_ppe_cache p10_io_ppe_fw_regs[5];

        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done_bist_final_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done_dccal_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done_hw_reg_init_pg[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done_ioreset_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done_power_off_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done_power_on_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done_recal_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done_rx_bist_tests_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done_rx_detect_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done_train_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done_tx_bist_tests_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done_tx_ffe_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done_tx_fifo_init_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done_tx_zcal_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_lanes_00_15[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_lanes_16_31[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req_bist_final_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req_dccal_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req_hw_reg_init_pg[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req_ioreset_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req_power_off_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req_power_on_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req_recal_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req_rx_bist_tests_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req_rx_detect_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req_train_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req_tx_bist_tests_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req_tx_ffe_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req_tx_fifo_init_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req_tx_zcal_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_fw_bist_en[5];
        p10_io_ppe_sram_reg p10_io_ppe_fw_debug[5];
        p10_io_ppe_sram_reg p10_io_ppe_fw_gcr_bus_id[5];
        p10_io_ppe_sram_reg p10_io_ppe_fw_num_lanes[5];
        p10_io_ppe_sram_reg p10_io_ppe_fw_serdes_16_to_1_mode[5];
        p10_io_ppe_sram_reg p10_io_ppe_fw_spread_en[5];
        p10_io_ppe_sram_reg p10_io_ppe_fw_stop_thread[5];
        p10_io_ppe_sram_reg p10_io_ppe_fw_thread_stopped[5];
        p10_io_ppe_sram_reg p10_io_ppe_fw_zcal_tdr_mode[5];

        p10_io_ppe_cache p10_io_ppe_mem_regs[5];

        p10_io_ppe_sram_reg p10_io_ppe_amp_setting_ovr_enb[5];
        p10_io_ppe_sram_reg p10_io_ppe_bist_in_hold_loop[5];
        p10_io_ppe_sram_reg p10_io_ppe_bist_in_progress[5];
        p10_io_ppe_sram_reg p10_io_ppe_bist_internal_error[5];
        p10_io_ppe_sram_reg p10_io_ppe_bist_other_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_bist_overall_pass[5];
        p10_io_ppe_sram_reg p10_io_ppe_bist_rx_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_bist_spare_0[5];
        p10_io_ppe_sram_reg p10_io_ppe_bist_spare_1[5];
        p10_io_ppe_sram_reg p10_io_ppe_bist_tx_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_jump_table_used[5];
        p10_io_ppe_sram_reg p10_io_ppe_lanes_pon_00_15[5];
        p10_io_ppe_sram_reg p10_io_ppe_lanes_pon_16_23[5];
        p10_io_ppe_sram_reg p10_io_ppe_loff_setting_ovr_enb[5];
        p10_io_ppe_sram_reg p10_io_ppe_poff_avg_a[5];
        p10_io_ppe_sram_reg p10_io_ppe_poff_avg_b[5];
        p10_io_ppe_sram_reg p10_io_ppe_ppe_channel_loss[5];
        p10_io_ppe_sram_reg p10_io_ppe_ppe_data_rate[5];
        p10_io_ppe_sram_reg p10_io_ppe_ppe_debug_state[5];
        p10_io_ppe_sram_reg p10_io_ppe_ppe_debug_stopwatch_time_us[5];
        p10_io_ppe_sram_reg p10_io_ppe_ppe_eoff_edge_hysteresis[5];
        p10_io_ppe_sram_reg p10_io_ppe_ppe_lte_gain_disable[5];
        p10_io_ppe_sram_reg p10_io_ppe_ppe_lte_gain_zero_disable_alias[5];
        p10_io_ppe_sram_reg p10_io_ppe_ppe_lte_hysteresis[5];
        p10_io_ppe_sram_reg p10_io_ppe_ppe_lte_zero_disable[5];
        p10_io_ppe_sram_reg p10_io_ppe_ppe_recal_not_run_sim_mode[5];
        p10_io_ppe_sram_reg p10_io_ppe_ppe_servo_status0[5];
        p10_io_ppe_sram_reg p10_io_ppe_ppe_servo_status1[5];
        p10_io_ppe_sram_reg p10_io_ppe_ppe_thread_lock_sim_mode[5];
        p10_io_ppe_sram_reg p10_io_ppe_ppe_thread_loop_count[5];
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_meas_filter_depth[5];
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_meas_max[5];
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_meas_min[5];
        p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_reset_time_us[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_bad_dfe_conv[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_bank_sync_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_ber_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_ctle_gain_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_ctle_peak1_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_ctle_peak2_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_ddc_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_ddc_hyst_left_edge[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_ddc_hyst_right_edge[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_dfe_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_dfe_h1_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_eoff_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_lane_hist_min_eye_width[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_last_eye_height[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_latch_offset_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_lte_gain_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_lte_zero_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_quad_phase_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_a_step_done_alias[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_amp_gain_cnt_max[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_b_bank_sync_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_b_ber_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_b_ctle_gain_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_b_ctle_peak1_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_b_ctle_peak2_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_b_ddc_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_b_ddc_hyst_left_edge[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_b_ddc_hyst_right_edge[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_b_dfe_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_b_dfe_h1_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_b_eoff_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_b_lane_hist_min_eye_width[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_b_last_eye_height[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_b_latch_offset_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_b_lte_gain_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_b_lte_zero_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_b_quad_phase_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_b_step_done_alias[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_bad_eye_opt_height[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_bad_eye_opt_width[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_bank_sync_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_ber_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_clr_lane_recal_cnt[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_cmd_init_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_gain_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_gain_max_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_gain_min_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_hysteresis[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_mode[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_peak1_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_peak1_max_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_peak1_min_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_peak2_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_peak2_max_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_peak2_min_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_quad_diff_thresh[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_current_cal_lane[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_dc_enable_latch_offset_cal[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_dc_step_cntl_opt_alias[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_dccal_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_ddc_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_ddc_hysteresis[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_ddc_measure_limited[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_ddc_min_err_lim[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_dfe_clkadj_coeff[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_dfe_debug[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_dfe_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_dfe_full_mode[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_dfe_full_quad[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_dfe_h1_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_dfe_max_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_dfe_min_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_disable_bank_pdwn[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_enable_auto_recal[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_enable_lane_cal_copy[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_enable_lane_cal_lte_copy[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_eo_converged_end_count[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_eo_enable_bank_sync[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_eo_enable_ctle_peak_cal[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_eo_enable_ddc[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_eo_enable_dfe_cal[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_eo_enable_dfe_full_cal[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_eo_enable_edge_offset_cal[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_eo_enable_lte_cal[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_eo_enable_quad_phase_cal[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_eo_enable_vga_cal[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_eo_step_cntl_opt_alias[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_eo_vga_ctle_loop_not_converged[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_eoff_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_eoff_max_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_eoff_min_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_eoff_poff_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_epoff_max_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_epoff_min_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_eye_height_min_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_eye_width_min_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_fail_flag[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_hist_min_eye_height[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_hist_min_eye_height_lane[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_hist_min_eye_height_valid[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_hist_min_eye_width[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_hist_min_eye_width_lane[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_hist_min_eye_width_mode[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_hist_min_eye_width_valid[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_init_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_lane_bad[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_lane_bad_0_15[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_lane_bad_16_23[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_lane_busy[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_lane_cal_time_us[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_lane_hist_min_eye_height[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_lane_hist_min_eye_height_bank[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_lane_hist_min_eye_height_latch[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_lane_hist_min_eye_height_quad[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_lane_hist_min_eye_height_valid[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_lane_hist_min_eye_width_valid[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_lane_recal_cnt[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_last_init_lane[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_latch_offset_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_latchoff_max_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_latchoff_min_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_linklayer_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_linklayer_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_lte_gain_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_lte_gain_max_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_lte_gain_min_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_lte_zero_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_lte_zero_max_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_lte_zero_min_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_manual_servo_filter_depth[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_min_recal_cnt[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_min_recal_cnt_reached[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_qpa_cdrlock_ignore[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_qpa_ee_obs[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_qpa_hysteresis_enable[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_qpa_ne_obs[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_qpa_pattern[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_qpa_pattern_enable[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_qpa_se_obs[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_qpa_we_obs[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_quad_ph_adj_max_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_quad_ph_adj_min_check[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_quad_phase_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_rc_enable_bank_sync[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_rc_enable_ctle_peak_cal[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_rc_enable_ddc[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_rc_enable_dfe_cal[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_rc_enable_edge_offset_cal[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_rc_enable_lte_cal[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_rc_enable_quad_phase_cal[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_rc_enable_vga_cal[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_rc_step_cntl_opt_alias[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_recal_abort[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_recal_before_init[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_recal_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_recal_run_or_unused_0_15[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_recal_run_or_unused_16_23[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_step_fail_alias[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_vga_amax[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_vga_amax_target[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_vga_converged[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_vga_debug[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_vga_jump_target[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_vga_recal_max_target[5];
        p10_io_ppe_sram_reg p10_io_ppe_rx_vga_recal_min_target[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_bist_dcc_i_max[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_bist_dcc_i_min[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_bist_dcc_iq_max[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_bist_dcc_iq_min[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_bist_dcc_q_max[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_bist_dcc_q_min[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_bist_fail_0_15[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_bist_fail_16_23[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_bist_hs_dac_thresh_max[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_bist_hs_dac_thresh_min[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_dc_enable_dcc[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_dcc_debug[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_dcc_main_min_samples[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_ffe_margin_coef[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_ffe_pre1_coef[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_ffe_pre2_coef[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_rc_enable_dcc[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_seg_test_1r_segs[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_seg_test_2r_seg[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_seg_test_en[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_seg_test_fail[5];
        p10_io_ppe_sram_reg p10_io_ppe_tx_seg_test_frc_2r[5];
};
#endif
