/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/edi_regs.h $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
//----------------------------------------------------- 
//      ____  ____     _   ______  ______ 
//     / __ \/ __ \   / | / / __ \/_  __/ 
//    / / / / / / /  /  |/ / / / / / /    
//   / /_/ / /_/ /  / /|  / /_/ / / /     
//  /_____/\____/  /_/ |_/\____/ /_/      
//                                    
//      __________  __________
//     / ____/ __ \/  _/_  __/
//    / __/ / / / // /  / /   
//   / /___/ /_/ // /  / /    
//  /_____/_____/___/ /_/     
//                                    
//    ________  ___________    ____________    ________
//   /_  __/ / / /  _/ ___/   / ____/  _/ /   / ____/ /
//    / / / /_/ // / \__ \   / /_   / // /   / __/ / / 
//   / / / __  // / ___/ /  / __/ _/ // /___/ /___/_/  
//  /_/ /_/ /_/___//____/  /_/   /___/_____/_____(_)   
//----------------------------------------------------- 
// Constant file for edi_reg_attribute.txt_fixed
// File generated at 16:23 on 8/31/2011 using system_pervasive/common/tools/CreateConstantsH.pl
// $Id: edi_regs.h,v 1.10 2014/02/20 13:27:29 varkeykv Exp $
// $URL: $
//
// *!**************************************************************************
// *!           All Rights Reserved -- Property of IBM
// *!                   ***  ***
// *!***************************************************************************
// *! FILENAME    : /afs/apd.pok.ibm.com/func/vlsi/eclipz/c22/verif/p8dd1/system_pervasive/common/include/edi_regs.h
//
// *! PERL SCRIPT OWNER NAME             : Jim Goldade      Email: goldade@us.ibm.com
// *! edi_reg_attribute.txt_fixed
//-----------------------------------------------------------------------------------------------------------------------------
// EDI Register Def
//-----------------------------------------------------------------------------------------------------------------------------
#ifndef _edi_regs_h
#define _edi_regs_h
//FROM EDI_REGS

typedef enum {
tx_mode_pl,
	tx_cntl_stat_pl,
	tx_spare_mode_pl,
	tx_bist_stat_pl,
	tx_prbs_mode_pl,
	tx_data_cntl_gcrmsg_pl,
	tx_sync_pattern_gcrmsg_pl,
	tx_fir_pl,
	tx_fir_mask_pl,
	tx_fir_error_inject_pl,
	tx_mode_fast_pl,
	tx_tdr_stat_pl,
	tx_cntl_gcrmsg_pl,
	tx_clk_mode_pg,
	tx_spare_mode_pg,
	tx_cntl_stat_pg,
	tx_mode_pg,
	tx_bus_repair_pg,
	tx_grp_repair_vec_0_15_pg,
	tx_grp_repair_vec_16_31_pg,
	tx_reset_act_pg,
	tx_bist_stat_pg,
	tx_fir_pg,
	tx_fir_mask_pg,
	tx_fir_error_inject_pg,
	tx_id1_pg,
	tx_id2_pg,
	tx_id3_pg,
	tx_clk_cntl_gcrmsg_pg,
	tx_ffe_mode_pg,
	tx_ffe_main_pg,
	tx_ffe_post_pg,
	tx_ffe_margin_pg,
	tx_bad_lane_enc_gcrmsg_pg,
	tx_sls_lane_enc_gcrmsg_pg,
	tx_wt_seg_enable_pg,
	tx_lane_disabled_vec_0_15_pg,
	tx_lane_disabled_vec_16_31_pg,
	tx_sls_lane_mux_gcrmsg_pg,
	tx_dyn_rpr_pg,
	tx_slv_mv_sls_ln_req_gcrmsg_pg,
	tx_wiretest_pp,
	tx_mode_pp,
	tx_sls_gcrmsg_pp,
	tx_ber_cntl_a_pp,
	tx_ber_cntl_b_pp,
	tx_dyn_recal_timeouts_pp,
	tx_bist_cntl_pp,
	tx_ber_cntl_sls_pp,
	tx_cntl_pp,
	tx_reset_cfg_pp,
	tx_tdr_cntl1_pp,
	tx_tdr_cntl2_pp,
	tx_tdr_cntl3_pp,
	tx_impcal_pb,
	tx_impcal_nval_pb,
	tx_impcal_pval_pb,
	tx_impcal_p_4x_pb,
	tx_impcal_swo1_pb,
	tx_impcal_swo2_pb,
	tx_analog_iref_pb,
	tx_minikerf_pb,
	tx_init_version_pb,
	tx_scratch_reg_pb,
	rx_mode_pl,
	rx_cntl_pl,
	rx_spare_mode_pl,
	rx_prot_edge_status_pl,
	rx_bist_stat_pl,
	rx_offset_even_pl,
	rx_offset_odd_pl,
	rx_amp_val_pl,
	rx_amp_cntl_pl,
	rx_prot_status_pl,
	rx_prot_mode_pl,
	rx_prot_cntl_pl,
	rx_fifo_stat_pl,
	rx_ap_pl,
	rx_an_pl,
	rx_amin_pl,
	rx_h1_even_pl,
	rx_h1_odd_pl,
	rx_prbs_mode_pl,
	rx_stat_pl,
	rx_deskew_stat_pl,
	rx_fir_pl,
	rx_fir_mask_pl,
	rx_fir_error_inject_pl,
	rx_sls_pl,
	rx_wt_status_pl,
	rx_fifo_cntl_pl,
	rx_ber_status_pl,
	rx_ber_timer_0_15_pl,
	rx_ber_timer_16_31_pl,
	rx_ber_timer_32_39_pl,
	rx_servo_cntl_pl,
	rx_fifo_diag_0_15_pl,
	rx_fifo_diag_16_31_pl,
	rx_fifo_diag_32_47_pl,
	rx_eye_width_status_pl,
	rx_eye_width_cntl_pl,
	rx_dfe_clkadj_pl,
	rx_trace_pl,
	rx_servo_ber_count_pl,
	rx_eye_opt_stat_pl,
	rx_clk_mode_pg,
	rx_spare_mode_pg,
	rx_stop_cntl_stat_pg,
	rx_mode_pg,
	rx_bus_repair_pg,
	rx_grp_repair_vec_0_15_pg,
	rx_grp_repair_vec_16_31_pg,
	rx_stop_addr_lsb_pg,
	rx_stop_mask_lsb_pg,
	rx_reset_act_pg,
	rx_id1_pg,
	rx_id2_pg,
	rx_id3_pg,
	rx_minikerf_pg,
	rx_sls_mode_pg,
	rx_training_start_pg,
	rx_training_status_pg,
	rx_recal_status_pg,
	rx_timeout_sel_pg,
	rx_fifo_mode_pg,
	rx_sls_status_pg,
	rx_fir1_pg,
	rx_fir2_pg,
	rx_fir1_mask_pg,
	rx_fir2_mask_pg,
	rx_fir1_error_inject_pg,
	rx_fir2_error_inject_pg,
	rx_fir_training_pg,
	rx_fir_training_mask_pg,
	rx_timeout_sel1_pg,
	rx_lane_bad_vec_0_15_pg,
	rx_lane_bad_vec_16_31_pg,
	rx_lane_disabled_vec_0_15_pg,
	rx_lane_disabled_vec_16_31_pg,
	rx_lane_swapped_vec_0_15_pg,
	rx_lane_swapped_vec_16_31_pg,
	rx_init_state_pg,
	rx_wiretest_state_pg,
	rx_wiretest_laneinfo_pg,
	rx_wiretest_gcrmsgs_pg,
	rx_deskew_gcrmsgs_pg,
	rx_deskew_state_pg,
	rx_deskew_mode_pg,
	rx_deskew_status_pg,
	rx_bad_lane_enc_gcrmsg_pg,
	rx_static_repair_state_pg,
	rx_tx_bus_info_pg,
	rx_sls_lane_enc_gcrmsg_pg,
	rx_fence_pg,
	rx_timeout_sel2_pg,
	rx_misc_analog_pg,
	rx_dyn_rpr_pg,
	rx_dyn_rpr_gcrmsg_pg,
	rx_dyn_rpr_err_tallying1_pg,
	rx_eo_final_l2u_gcrmsgs_pg,
	rx_gcr_msg_debug_dest_ids_pg,
	rx_gcr_msg_debug_src_ids_pg,
	rx_gcr_msg_debug_dest_addr_pg,
	rx_gcr_msg_debug_write_data_pg,
	rx_dyn_recal_pg,
	rx_wt_clk_status_pg,
	rx_dyn_recal_config_pg,
	rx_dyn_recal_gcrmsg_pg,
	rx_wiretest_pll_cntl_pg,
	rx_eo_step_cntl_pg,
	rx_eo_step_stat_pg,
	rx_eo_step_fail_pg,
	rx_ap_pg,
	rx_an_pg,
	rx_amin_pg,
	rx_amax_pg,
	rx_amp_val_pg,
	rx_amp_offset_pg,
	rx_eo_convergence_pg,
	rx_sls_rcvy_pg,
	rx_sls_rcvy_gcrmsg_pg,
	rx_tx_lane_info_gcrmsg_pg,
	rx_err_tallying_gcrmsg_pg,
	rx_trace_pg,
	rx_rc_step_cntl_pg,
	rx_eo_recal_pg,
	rx_servo_ber_count_pg,
	rx_func_state_pg,
	rx_dyn_rpr_debug_pg,
	rx_dyn_rpr_err_tallying2_pg,
	rx_result_chk_pg,
	rx_ber_chk_pg,
	rx_sls_rcvy_fin_gcrmsg_pg,
	rx_wiretest_pp,
	rx_mode1_pp,
	rx_cntl_pp,
	rx_dyn_recal_timeouts_pp,
	rx_mode2_pp,
	rx_ber_cntl_pp,
	rx_ber_mode_pp,
	rx_servo_to1_pp,
	rx_servo_to2_pp,
	rx_servo_to3_pp,
	rx_dfe_config_pp,
	rx_dfe_timers_pp,
	rx_reset_cfg_pp,
	rx_recal_to1_pp,
	rx_recal_to2_pp,
	rx_recal_to3_pp,
	rx_recal_cntl_pp,
	rx_trace_pp,
	rx_bist_gcrmsg_pp,
	rx_scope_cntl_pp,
	rx_fir_reset_pb,
	rx_fir_pb,
	rx_fir_mask_pb,
	rx_fir_error_inject_pb,
	rx_fir_msg_pb,
	
	ei4_tx_mode_pl,
	ei4_tx_cntl_stat_pl,
	ei4_tx_spare_mode_pl,
	ei4_tx_bist_stat_pl,
	ei4_tx_prbs_mode_pl,
	ei4_tx_data_cntl_gcrmsg_pl,
	ei4_tx_sync_pattern_gcrmsg_pl,
	ei4_tx_fir_pl,
	ei4_tx_fir_mask_pl,
	ei4_tx_fir_error_inject_pl,
	ei4_tx_mode_fast_pl,
	ei4_tx_clk_mode_pg,
	ei4_tx_spare_mode_pg,
	ei4_tx_cntl_stat_pg,
	ei4_tx_mode_pg,
	ei4_tx_bus_repair_pg,
	ei4_tx_grp_repair_vec_0_15_pg,
	ei4_tx_grp_repair_vec_16_31_pg,
	ei4_tx_reset_act_pg,
	ei4_tx_bist_stat_pg,
	ei4_tx_fir_pg,
	ei4_tx_fir_mask_pg,
	ei4_tx_fir_error_inject_pg,
	ei4_tx_id1_pg,
	ei4_tx_id2_pg,
	ei4_tx_id3_pg,
	ei4_tx_clk_cntl_gcrmsg_pg,
	ei4_tx_bad_lane_enc_gcrmsg_pg,
	ei4_tx_sls_lane_enc_gcrmsg_pg,
	ei4_tx_wt_seg_enable_pg,
	ei4_tx_pc_ffe_pg,
	ei4_tx_misc_analog_pg,
	ei4_tx_lane_disabled_vec_0_15_pg,
	ei4_tx_lane_disabled_vec_16_31_pg,
	ei4_tx_sls_lane_mux_gcrmsg_pg,
	ei4_tx_dyn_rpr_pg,
	ei4_tx_slv_mv_sls_ln_req_gcrmsg_pg,
	ei4_tx_rdt_cntl_pg,
	ei4_rx_dll_cal_cntl_pg,
	ei4_rx_dll1_setpoint1_pg,
	ei4_rx_dll1_setpoint2_pg,
	ei4_rx_dll1_setpoint3_pg,
	ei4_rx_dll2_setpoint1_pg,
	ei4_rx_dll2_setpoint2_pg,
	ei4_rx_dll2_setpoint3_pg,
	ei4_rx_dll_filter_mode_pg,
	ei4_rx_dll_analog_tweaks_pg,
	ei4_tx_wiretest_pp,
	ei4_tx_mode_pp,
	ei4_tx_sls_gcrmsg_pp,
	ei4_tx_ber_cntl_a_pp,
	ei4_tx_ber_cntl_b_pp,
	ei4_tx_bist_cntl_pp,
	ei4_tx_ber_cntl_sls_pp,
	ei4_tx_cntl_pp,
	ei4_tx_reset_cfg_pp,
	ei4_tx_tdr_cntl2_pp,
	ei4_tx_tdr_cntl3_pp,
	ei4_rx_mode_pl,
	ei4_rx_cntl_pl,
	ei4_rx_spare_mode_pl,
	ei4_rx_bist_stat_pl,
	ei4_rx_offset_even_pl,
	ei4_rx_offset_odd_pl,
	ei4_rx_amp_val_pl,
	ei4_rx_prot_status_pl,
	ei4_rx_prot_mode_pl,
	ei4_rx_prot_cntl_pl,
	ei4_rx_fifo_stat_pl,
	ei4_rx_prbs_mode_pl,
	ei4_rx_vref_pl,
	ei4_rx_stat_pl,
	ei4_rx_deskew_stat_pl,
	ei4_rx_fir_pl,
	ei4_rx_fir_mask_pl,
	ei4_rx_fir_error_inject_pl,
	ei4_rx_sls_pl,
	ei4_rx_wt_status_pl,
	ei4_rx_fifo_cntl_pl,
	ei4_rx_ber_status_pl,
	ei4_rx_ber_timer_0_15_pl,
	ei4_rx_ber_timer_16_31_pl,
	ei4_rx_ber_timer_32_39_pl,
	ei4_rx_servo_cntl_pl,
	ei4_rx_fifo_diag_0_15_pl,
	ei4_rx_fifo_diag_16_31_pl,
	ei4_rx_fifo_diag_32_47_pl,
	ei4_rx_eye_width_status_pl,
	ei4_rx_eye_width_cntl_pl,
	ei4_rx_trace_pl,
	ei4_rx_servo_ber_count_pl,
	ei4_rx_eye_opt_stat_pl,
	ei4_rx_clk_mode_pg,
	ei4_rx_spare_mode_pg,
	ei4_rx_stop_cntl_stat_pg,
	ei4_rx_mode_pg,
	ei4_rx_bus_repair_pg,
	ei4_rx_grp_repair_vec_0_15_pg,
	ei4_rx_grp_repair_vec_16_31_pg,
	ei4_rx_stop_addr_lsb_pg,
	ei4_rx_stop_mask_lsb_pg,
	ei4_rx_reset_act_pg,
	ei4_rx_id1_pg,
	ei4_rx_id2_pg,
	ei4_rx_id3_pg,
	ei4_rx_sls_mode_pg,
	ei4_rx_training_start_pg,
	ei4_rx_training_status_pg,
	ei4_rx_recal_status_pg,
	ei4_rx_timeout_sel_pg,
	ei4_rx_fifo_mode_pg,
	ei4_rx_sls_status_pg,
	ei4_rx_fir1_pg,
	ei4_rx_fir2_pg,
	ei4_rx_fir1_mask_pg,
	ei4_rx_fir2_mask_pg,
	ei4_rx_fir1_error_inject_pg,
	ei4_rx_fir2_error_inject_pg,
	ei4_rx_fir_training_pg,
	ei4_rx_fir_training_mask_pg,
	ei4_rx_timeout_sel1_pg,
	ei4_rx_lane_bad_vec_0_15_pg,
	ei4_rx_lane_bad_vec_16_31_pg,
	ei4_rx_lane_disabled_vec_0_15_pg,
	ei4_rx_lane_disabled_vec_16_31_pg,
	ei4_rx_lane_swapped_vec_0_15_pg,
	ei4_rx_lane_swapped_vec_16_31_pg,
	ei4_rx_init_state_pg,
	ei4_rx_wiretest_state_pg,
	ei4_rx_wiretest_laneinfo_pg,
	ei4_rx_wiretest_gcrmsgs_pg,
	ei4_rx_deskew_gcrmsgs_pg,
	ei4_rx_deskew_state_pg,
	ei4_rx_deskew_mode_pg,
	ei4_rx_deskew_status_pg,
	ei4_rx_bad_lane_enc_gcrmsg_pg,
	ei4_rx_static_repair_state_pg,
	ei4_rx_ei4_tx_bus_info_pg,
	ei4_rx_sls_lane_enc_gcrmsg_pg,
	ei4_rx_fence_pg,
	ei4_rx_term_pg,
	ei4_rx_timeout_sel2_pg,
	ei4_rx_dyn_rpr_pg,
	ei4_rx_dyn_rpr_gcrmsg_pg,
	ei4_rx_dyn_rpr_err_tallying1_pg,
	ei4_rx_eo_final_l2u_gcrmsgs_pg,
	ei4_rx_gcr_msg_debug_dest_ids_pg,
	ei4_rx_gcr_msg_debug_src_ids_pg,
	ei4_rx_gcr_msg_debug_dest_addr_pg,
	ei4_rx_gcr_msg_debug_write_data_pg,
	ei4_rx_wt_clk_status_pg,
	ei4_rx_wiretest_pll_cntl_pg,
	ei4_rx_eo_step_cntl_pg,
	ei4_rx_eo_step_stat_pg,
	ei4_rx_eo_step_fail_pg,
	ei4_rx_amp_val_pg,
	ei4_rx_sls_rcvy_pg,
	ei4_rx_sls_rcvy_gcrmsg_pg,
	ei4_rx_ei4_tx_lane_info_gcrmsg_pg,
	ei4_rx_err_tallying_gcrmsg_pg,
	ei4_rx_trace_pg,
	ei4_rx_rdt_cntl_pg,
	ei4_rx_rc_step_cntl_pg,
	ei4_rx_eo_recal_pg,
	ei4_rx_servo_ber_count_pg,
	ei4_rx_func_state_pg,
	ei4_rx_dyn_rpr_debug_pg,
	ei4_rx_dyn_rpr_err_tallying2_pg,
	ei4_rx_result_chk_pg,
	ei4_rx_sls_rcvy_fin_gcrmsg_pg,
	ei4_rx_wiretest_pp,
	ei4_rx_mode1_pp,
	ei4_rx_cntl_pp,
	ei4_rx_ei4_cal_cntl_pp,
	ei4_rx_ei4_cal_inc_a_d_pp,
	ei4_rx_ei4_cal_inc_e_h_pp,
	ei4_rx_ei4_cal_dec_a_d_pp,
	ei4_rx_ei4_cal_dec_e_h_pp,
	ei4_rx_mode2_pp,
	ei4_rx_ber_cntl_pp,
	ei4_rx_ber_mode_pp,
	ei4_rx_servo_to1_pp,
	ei4_rx_servo_to2_pp,
	ei4_rx_reset_cfg_pp,
	ei4_rx_recal_to1_pp,
	ei4_rx_recal_to2_pp,
	ei4_rx_recal_cntl_pp,
	ei4_rx_trace_pp,
	ei4_rx_bist_gcrmsg_pp,
	ei4_rx_fir_reset_pb,
	ei4_rx_fir_pb,
	ei4_rx_fir_mask_pb,
	ei4_rx_fir_error_inject_pb,
	ei4_rx_fir_msg_pb,
        ei4_rx_dcd_adj_pl,
NUM_REGS
} GCR_sub_registers;


// merged ei4 and edi ext addresses
const uint32_t  GCR_sub_reg_ext_addr[] =     { 0x080, 0x081, 0x082, 0x085, 0x086, 0x087, 0x088, 0x08A, 0x08B, 0x08C, 0x08D, 0x08E, 0x08F, 0x180, 0x181, 0x182, 0x183, 0x184, 0x185, 0x186, 0x188, 0x189, 0x18A, 0x18B, 0x18C, 0x192, 0x193, 0x194, 0x198, 0x199, 0x19A, 0x19B, 0x19C, 0x19D, 0x19F, 0x1A0, 0x1A3, 0x1A4, 0x1A5, 0x1A6, 0x1A7, 0x1D0, 0x1D1, 0x1D2, 0x1D3, 0x1D4, 0x1D5, 0x1D6, 0x1D7, 0x1D8, 0x1D9, 0x1DA, 0x1DB, 0x1DC, 0x1E0, 0x1E1, 0x1E2, 0x1E3, 0x1E4, 0x1E5, 0x1E6, 0x1E7, 0x1E8, 0x1E9, 0x000, 0x001, 0x002, 0x003, 0x005, 0x008, 0x009, 0x00A, 0x00B, 0x00C, 0x00D, 0x00E, 0x00F, 0x010, 0x011, 0x012, 0x013, 0x014, 0x016, 0x018, 0x019, 0x01A, 0x01B, 0x01C, 0x01D, 0x01E, 0x01F, 0x020, 0x021, 0x022, 0x023, 0x024, 0x025, 0x026, 0x027, 0x028, 0x029, 0x02A, 0x02B, 0x02C, 0x02D, 0x100, 0x101, 0x102, 0x103, 0x104, 0x105, 0x106, 0x107, 0x108, 0x109, 0x10A, 0x10B, 0x10C, 0x10D, 0x10F, 0x110, 0x111, 0x112, 0x113, 0x114, 0x117, 0x11A, 0x11B, 0x11C, 0x11D, 0x11E, 0x11F, 0x120, 0x121, 0x122, 0x123, 0x124, 0x125, 0x126, 0x127, 0x128, 0x129, 0x12A, 0x12B, 0x12C, 0x12D, 0x12E, 0x12F, 0x130, 0x131, 0x132, 0x133, 0x134, 0x135, 0x137, 0x138, 0x139, 0x13A, 0x13B, 0x13C, 0x13D, 0x13E, 0x13F, 0x140, 0x141, 0x142, 0x143, 0x145, 0x146, 0x147, 0x148, 0x149, 0x14A, 0x14B, 0x14C, 0x14D, 0x14E, 0x14F, 0x150, 0x151, 0x152, 0x153, 0x154, 0x155, 0x157, 0x158, 0x159, 0x15A, 0x15B, 0x15C, 0x15D, 0x15E, 0x15F, 0x160, 0x161, 0x162, 0x168, 0x169, 0x16A, 0x16B, 0x16C, 0x16D, 0x16E, 0x16F, 0x170, 0x171, 0x172, 0x173, 0x174, 0x175, 0x176, 0x177, 0x178, 0x1F0, 0x1F1, 0x1F2, 0x1F3, 0x1FF,
											   0x080, 0x081, 0x082, 0x085, 0x086, 0x087, 0x088, 0x08A, 0x08B, 0x08C, 0x08D, 0x180, 0x181, 0x182, 0x183, 0x184, 0x185, 0x186, 0x188, 0x189, 0x18A, 0x18B, 0x18C, 0x192, 0x193, 0x194, 0x198, 0x19D, 0x19F, 0x1A0, 0x1A1, 0x1A2, 0x1A3, 0x1A4, 0x1A5, 0x1A6, 0x1A7, 0x1A8, 0x1C7, 0x1C8, 0x1C9, 0x1CA, 0x1CB, 0x1CC, 0x1CD, 0x1CE, 0x1CF, 0x1D0, 0x1D1, 0x1D2, 0x1D3, 0x1D4, 0x1D6, 0x1D7, 0x1D8, 0x1D9, 0x1DB, 0x1DC, 0x000, 0x001, 0x002, 0x005, 0x008, 0x009, 0x00A, 0x00C, 0x00D, 0x00E, 0x00F, 0x016, 0x017, 0x018, 0x019, 0x01A, 0x01B, 0x01C, 0x01D, 0x01E, 0x01F, 0x020, 0x021, 0x022, 0x023, 0x024, 0x025, 0x026, 0x027, 0x028, 0x029, 0x02B, 0x02C, 0x02D, 0x100, 0x101, 0x102, 0x103, 0x104, 0x105, 0x106, 0x107, 0x108, 0x109, 0x10A, 0x10B, 0x10C, 0x10F, 0x110, 0x111, 0x112, 0x113, 0x114, 0x117, 0x11A, 0x11B, 0x11C, 0x11D, 0x11E, 0x11F, 0x120, 0x121, 0x122, 0x123, 0x124, 0x125, 0x126, 0x127, 0x128, 0x129, 0x12A, 0x12B, 0x12C, 0x12D, 0x12E, 0x12F, 0x130, 0x131, 0x132, 0x133, 0x134, 0x135, 0x136, 0x137, 0x139, 0x13A, 0x13B, 0x13C, 0x13D, 0x13E, 0x13F, 0x140, 0x142, 0x146, 0x147, 0x148, 0x149, 0x14E, 0x151, 0x152, 0x153, 0x154, 0x155, 0x156, 0x157, 0x158, 0x159, 0x15A, 0x15B, 0x15C, 0x15D, 0x15F, 0x160, 0x161, 0x162, 0x163, 0x164, 0x165, 0x166, 0x167, 0x169, 0x16A, 0x16B, 0x16C, 0x16D, 0x171, 0x172, 0x173, 0x175, 0x176, 0x177, 0x1F0, 0x1F1, 0x1F2, 0x1F3, 0x1FF,0x02E};
//merged ei4 and edi 
const char* const GCR_sub_reg_names[] = {
	"TX Lane Mode Reg",
	"TX Cntl and Status Reg",
	"TX Per-Lane Spare Mode Reg",
	"TX BIST Status Reg",
	"TX Per-Lane PRBS Mode Reg",
	"TX Data Control Reg",
	"TX Sync Pattern Control Reg",
	"TX Per-Lane FIR Error Source-Isolation Reg",
	"TX Per-Lane FIR Error Mask Reg",
	"TX Per-Lane FIR Error Injection Reg",
	"TX Per-Lane Fast-Clocked Mode Reg",
	"TX TDR Capture status",
	"TX Cntl Reg via GCR Messages",
	"TX Per-Group Clk Mode Reg",
	"TX Per-Group Spare Mode Reg",
	"TX Cntl and Status Reg",
	"TX Mode Reg",
	"TX Bus Repair Reg",
	"TX Clkgrp Repair Lanes 0-15 Reg",
	"TX Clkgrp Repair Lanes 16-31 Reg",
	"TX Reset Control Action Register (RCAR)",
	"TX BIST CLK Status Reg",
	"TX Per-Group FIR Error Source-Isolation Reg",
	"TX Per-Group FIR Error Source-Isolation Reg",
	"TX Per-Group FIR Error Injection Reg",
	"TX Clock Group Identification 1 Reg",
	"TX Clock Group Identification 2 Reg",
	"TX Clock Group Identification 3 Reg",
	"TX Clock Control Reg",
	"TX FFE Test Mode Reg",
	"TX FFE Main Reg",
	"TX FFE Post Reg",
	"TX FFE Margin Reg",
	"TX Bad Lanes Encoded",
	"TX SLS Lane Encoded",
	"TX Wiretest Driver Segment Enable",
	"TX Lane Disable(d) 0 to 15 Reg",
	"TX Lane Disable(d) 16 to 31 Reg",
	"TX SLS Lane TX Mux Setting",
	"TX Dynamic Repair & Recalibration Status",
	"TX Dynamic Repair & Recalibration Messages",
	"TX Wiretest Per-Group & Pack Shadow Reg",
	"TX Mode Per-Pack Shadow Reg",
	"TX SLS Command",
	"TX Bit Error Injection Control A Shadow Reg",
	"TX Bit Error Injection Control B Shadow Reg",
	"TX Dynamic Recalibration Timeout Selects",
	"TX BIST Cntl Reg",
	"TX Bit Error Injection Control SLS Shadow Reg",
	"TX Cntl Per-Pack Reg",
	"TX Configurable Reset Control Register (CRCR)",
	"TX TDR Control Register",
	"TX TDR Control Register",
	"TX TDR Control Register",
	"TX Impedance Cal Cntl and Status Reg",
	"TX Impedance Cal N Value Reg",
	"TX Impedance Cal P Value Reg",
	"TX Impedance Cal P 4x Value Reg",
	"TX Impedance Cal SW Workaround 1 Reg",
	"TX Impedance Cal SW Workaround 2 Reg",
	"TX Iref bias code input",
	"TX Minikerf Cntl Reg",
	"TX Initfile Version Reg",
	"TX Scratch Reg",
	"RX Lane Mode Reg",
	"RX Cntl and Status Reg",
	"RX Per-lane Spare Mode Reg",
	"RX Phase Rotator Edge Status Reg",
	"RX BIST Status Reg",
	"RX Even Sample Latch Offset Cntl Reg",
	"RX Odd Sample Latch Offset Cntl Reg",
	"RX Preamp value Reg",
	"RX Preamp value Reg",
	"RX Phase Rotator Status Reg",
	"RX Phase Rotator Mode Reg",
	"RX Phase Rotator Control Reg",
	"RX FIFO Status Reg",
	"RX Ap Even/Odd Sampler Reg",
	"RX An Even/Odd Sampler Reg",
	"RX Amin Reg",
	"RX H1 Even Sampler Reg",
	"RX H1 Odd Sampler Reg",
	"RX Per-Lane PRBS Mode Reg",
	"RX Per-Lane Deskew Status Reg",
	"RX FIFO deskew status/error register",
	"RX Per-Lane FIR Error Source-Isolation Reg",
	"RX Per-Lane FIR Error Source-Isolation Mask Reg",
	"RX Per-Lane FIR Error Injection Reg",
	"RX SLS Settings Register",
	"RX Wiretest Status register  ",
	"RX FIFO control Reg",
	"RX BER Status Reg",
	"RX BER Current Timer Value Reg - Bits 0 to 15",
	"RX BER Current Timer Value Reg - Bits 16 to 31",
	"RX BER Current Timer Value Reg - Bits 32 to 39",
	"RX Servo Operation command and control",
	"RX FIFO output 0 to 15 for diag",
	"RX FIFO output 16 to 31 for diag",
	"RX FIFO output 32 to 47 for diag",
	"RX Current and historic minimum eye width",
	"RX historic minimum eye width reset control",
	"RX dfe clock adjust register",
	"RX Trace Per Lane Settings",
	"RX servo-based BER count PL",
	"RX Eye optimization error register",
	"RX Per-Group Clk Mode Reg",
	"RX Per-Group Spare Mode Reg",
	"RX Trace/State stop control/status/ MSB Reg",
	"RX Mode Reg",
	"RX Bus Repair Reg",
	"RX Clkgrp Repair Lanes 0-15 Reg",
	"RX Clkgrp Repair Lanes 16-31 Reg",
	"RX Trace/State stop address 4-19  Reg",
	"RX Trace/State stop mask    4-19  Reg",
	"RX Reset Control Action Register (RCAR)",
	"RX Clock Group Identification 1 Reg",
	"RX Clock Group Identification 2 Reg",
	"RX Clock Group Identification 3 Reg",
	"RX Minikerf Cntl Reg",
	"RX Spare Lane Signaling Mode Reg",
	"RX Training State Start Reg",
	"RX Training State Status Reg",
	"RX Recal Status Reg",
	"RX Timeout Select Reg",
	"RX FIFO Mode Reg",
	"RX Spare Lane Signalling Status Reg",
	"RX Per-Group FIR Error Source-Isolation Reg",
	"RX Per-Group FIR Error Source-Isolation Reg",
	"RX Per-Group FIR Error Source-Isolation Mask Reg",
	"RX Per-Group FIR Error Source-Isolation Mask Reg",
	"RX Per-Group FIR Error Injection Reg",
	"RX Per-Group FIR Error Injection Reg",
	"RX Per-Group Training FIR Error Reg",
	"RX Per-Group Training FIR Error Mask Reg",
	"RX Timeout Select Reg 1",
	"RX Bad Lanes 0 to 15 Reg",
	"RX Bad Lanes 16 to 31 Reg",
	"RX Lane Disable(d) 0 to 15 Reg",
	"RX Lane Disable(d) 16_31 Reg",
	"RX P & N Lanes Swapped 0 to 15 Reg",
	"RX P & N Lanes Swapped 16 to 31 Reg",
	"RX Init Machine Status",
	"RX Wiretest State Machine Reg",
	"RX Wiretest Lane Info Reg",
	"RX Wiretest GCR Message Reg",
	"RX Deskew GCR Message Reg",
	"RX Deskew State Machine Status Reg",
	"RX Deskew State Machine Control Reg",
	"RX Deskew State Machine Status Values",
	"RX Bad Lanes Encoded",
	"RX Static Repair State Machine Reg",
	"TX Bus info for RX Ctl Macs",
	"RX SLS Lane Encoded",
	"RX Per Group Fence",
	"RX Timeout Select Reg 2",
	"RX Misc Analog Reg",
	"RX Dynamic Repair & Recalibration Status",
	"CRC/ECC Dynamic Repair GCR Message Reg",
	"CRC/ECC Dynamic Repair Lane Error Frequency Settings",
	"RX Final Load to Unload GCR Messages",
	"RX SW Initiated GCR Message Destination IDs",
	"RX SW Initiated GCR Message Source IDs",
	"RX SW Initiated GCR Message Destination Addr",
	"RX SW Initiated GCR Message Write Data",
	"RX Dynamic Recalibration Status",
	"RX Clock Wiretest Status",
	"RX Dynamic Recalibration Configuration",
	"RX Dynamic Recalibration GCR Messages",
	"RX PLL or DLL reset and calibration controls",
	"RX Eye optimization step control",
	"RX Eye optimization step status",
	"RX Eye optimization step fail flags",
	"RX Eye optimization Ap   working registers",
	"RX Eye optimization An   working registers",
	"RX Eye optimization Amin working registers",
	"RX Eye optimization Amax limit   registers",
	"RX Eye optimization Amp  working registers",
	"RX Eye optimization Amp  Offset limts     ",
	"RX Eye optimization Convergence control regs",
	"RX SLS Handshake Recovery Register",
	"RX SLS Handshake Recovery GCR Messages",
	"RX: TX Lane Info",
	"CRC/ECC Syndrome Tallying GCR Message Reg",
	"RX Trace Mode Reg",
	"RX Recalibraton     step control",
	"RX Eye Opt and Recal Status",
	"RX Recal Bit Error Rate Count Working Register",
	"RX Func Mode Status",
	"Dynamic Repair Testfloor/Debug Register",
	"CRC/ECC Dynamic Repair Bus Error Frequency Settings",
	"Eye widhth/height results check limits",
	"Bit error rate check max rate k limits",
	"RX SLS Handshake Recovery Finish GCR Messages",
	"RX Wiretest Per-Pack Shadow Reg",
	"RX Mode Per-Pack Shadow Reg",
	"RX Cntl Per-Pack Shadow Reg",
	"RX Dynamic Recalibration Timeout Selects",
	"RX Mode Per-Pack Shadow Reg",
	"RX BER Control Reg",
	"RX BER Mode Reg",
	"RX Servo Timeout Select Regs 1",
	"RX Servo Timeout Select Regs 2",
	"RX Servo Timeout Select Regs 3",
	"RX DFE Configuration Register",
	"RX DFE timers Configuration Register",
	"RX Configurable Reset Control Register (CRCR)",
	"RX Recal Servo Timeout Select Regs 1",
	"RX Recal Servo Timeout Select Regs 2",
	"RX Recal Servo Timeout Select Regs 3",
	"RX Recal in progress control",
	"RX Trace Per Pack Settings",
	"RX BIST Cntl Reg",
	"RX Scope Cntl Reg",
	"Per-Bus BUSCTL FIR Error Reset Reg",
	"Per-Bus FIR Error Source-Isolation Reg",
	"Per-Bus FIR Error Source-Isolation Mask Reg",
	"Per-Bus FIR Error Injection Reg",
    "Per-Bus FIR Register Write Alias",
	"TX Lane Mode Reg",
	"TX Cntl and Status Reg",
	"TX Per-Lane Spare Mode Reg",
	"TX BIST Status Reg",
	"TX Per-Lane PRBS Mode Reg",
	"TX Data Control Reg",
	"TX Sync Pattern Control Reg",
	"TX Per-Lane FIR Error Source-Isolation Reg",
	"TX Per-Lane FIR Error Mask Reg",
	"TX Per-Lane FIR Error Injection Reg",
	"TX Per-Lane Fast-Clocked Mode Reg",
	"TX Per-Group Clk Mode Reg",
	"TX Per-Group Spare Mode Reg",
	"TX Cntl and Status Reg",
	"TX Mode Reg",
	"TX Bus Repair Reg",
	"TX Clkgrp Repair Lanes 0-15 Reg",
	"TX Clkgrp Repair Lanes 16-31 Reg",
	"TX Reset Control Action Register (RCAR)",
	"TX BIST CLK Status Reg",
	"TX Per-Group FIR Error Source-Isolation Reg",
	"TX Per-Group FIR Error Source-Isolation Reg",
	"TX Per-Group FIR Error Injection Reg",
	"TX Clock Group Identification 1 Reg",
	"TX Clock Group Identification 2 Reg",
	"TX Clock Group Identification 3 Reg",
	"TX Clock Control Reg",
	"TX Bad Lanes Encoded",
	"TX SLS Lane Encoded",
	"TX Wiretest Driver Segment Enable",
	"TX Precomp and Impedance Reg",
	"TX Misc Analog Reg",
	"TX Lane Disable(d) 0 to 15 Reg",
	"TX Lane Disable(d) 16 to 31 Reg",
	"TX SLS Lane TX Mux Setting",
	"TX Dynamic Repair & Recalibration Status",
	"TX Dynamic Repair & Recalibration Messages",
	"TX control for RDT (EI3-Mode only)",
	"RX DLL Calibration Sequence Status",
	"RX DLL 1 Manual Delay/Vreg DAC Coarse Override",
	"RX DLL 1 Manual Vreg DAC Fine Override",
	"RX DLL 1 Manual Vreg DAC Fine Override",
	"RX DLL 2 Manual Delay/Vreg DAC Coarse Override",
	"RX DLL 2 Manual Vreg DAC Fine Override",
	"RX DLL 2 Manual Vreg DAC Fine Override",
	"RX DLL Clock Phase Detector Filtering",
	"RX DLL Analog Fine Tuning",
	"TX Wiretest Per-Group & Pack Shadow Reg",
	"TX Mode Per-Pack Shadow Reg",
	"TX SLS Command",
	"TX Bit Error Injection Control A Shadow Reg",
	"TX Bit Error Injection Control B Shadow Reg",
	"TX BIST Cntl Reg",
	"TX Bit Error Injection Control SLS Shadow Reg",
	"TX Cntl Per-Pack Reg",
	"TX Configurable Reset Control Register (CRCR)",
	"TX TDR Control Register",
	"TX TDR Control Register",
	"RX Lane Mode Reg",
	"RX Cntl and Status Reg",
	"RX Per-lane Spare Mode Reg",
	"RX BIST Status Reg",
	"RX Even Sample Latch Offset Cntl Reg",
	"RX Odd Sample Latch Offset Cntl Reg",
	"RX Preamp value Reg",
	"RX Phase Rotator Status Reg",
	"RX Phase Rotator Mode Reg",
	"RX Phase Rotator Control Reg",
	"RX FIFO Status Reg",
	"RX Per-Lane PRBS Mode Reg",
	"RX Voltage Reference Reg",
	"RX Per-Lane Deskew Status Reg",
	"RX FIFO deskew status/error register",
	"RX Per-Lane FIR Error Source-Isolation Reg",
	"RX Per-Lane FIR Error Source-Isolation Mask Reg",
	"RX Per-Lane FIR Error Injection Reg",
	"RX SLS Settings Register",
	"RX Wiretest Status register  ",
	"RX FIFO control Reg",
	"RX BER Status Reg",
	"RX BER Current Timer Value Reg - Bits 0 to 15",
	"RX BER Current Timer Value Reg - Bits 16 to 31",
	"RX BER Current Timer Value Reg - Bits 32 to 39",
	"RX Servo Operation command and control",
	"RX FIFO output 0 to 15 for diag",
	"RX FIFO output 16 to 31 for diag",
	"RX FIFO output 32 to 47 for diag",
	"RX Current and historic minimum eye width",
	"RX historic minimum eye width reset control",
	"RX Trace Per Lane Settings",
	"RX servo-based BER count PL",
	"RX Eye optimization error register",
	"RX Per-Group Clk Mode Reg",
	"RX Per-Group Spare Mode Reg",
	"RX Trace/State stop control/status/ MSB Reg",
	"RX Mode Reg",
	"RX Bus Repair Reg",
	"RX Clkgrp Repair Lanes 0-15 Reg",
	"RX Clkgrp Repair Lanes 16-31 Reg",
	"RX Trace/State stop address 4-19  Reg",
	"RX Trace/State stop mask    4-19  Reg",
	"RX Reset Control Action Register (RCAR)",
	"RX Clock Group Identification 1 Reg",
	"RX Clock Group Identification 2 Reg",
	"RX Clock Group Identification 3 Reg",
	"RX Spare Lane Signaling Mode Reg",
	"RX Training State Start Reg",
	"RX Training State Status Reg",
	"RX Recal Status Reg",
	"RX Timeout Select Reg",
	"RX FIFO Mode Reg",
	"RX Spare Lane Signalling Status Reg",
	"RX Per-Group FIR Error Source-Isolation Reg",
	"RX Per-Group FIR Error Source-Isolation Reg",
	"RX Per-Group FIR Error Source-Isolation Mask Reg",
	"RX Per-Group FIR Error Source-Isolation Mask Reg",
	"RX Per-Group FIR Error Injection Reg",
	"RX Per-Group FIR Error Injection Reg",
	"RX Per-Group Training FIR Error Reg",
	"RX Per-Group Training FIR Error Mask Reg",
	"RX Timeout Select Reg 1",
	"RX Bad Lanes 0 to 15 Reg",
	"RX Bad Lanes 16 to 31 Reg",
	"RX Lane Disable(d) 0 to 15 Reg",
	"RX Lane Disable(d) 16_31 Reg",
	"RX P & N Lanes Swapped 0 to 15 Reg",
	"RX P & N Lanes Swapped 16 to 31 Reg",
	"RX Init Machine Status",
	"RX Wiretest State Machine Reg",
	"RX Wiretest Lane Info Reg",
	"RX Wiretest GCR Message Reg",
	"RX Deskew GCR Message Reg",
	"RX Deskew State Machine Status Reg",
	"RX Deskew State Machine Control Reg",
	"RX Deskew State Machine Status Values",
	"RX Bad Lanes Encoded",
	"RX Static Repair State Machine Reg",
	"TX Bus info for RX Ctl Macs",
	"RX SLS Lane Encoded",
	"RX Per Group Fence",
	"RX Termination Reg",
	"RX Timeout Select Reg 2",
	"RX Dynamic Repair & Recalibration Status",
	"CRC/ECC Dynamic Repair GCR Message Reg",
	"CRC/ECC Dynamic Repair Lane Error Frequency Settings",
	"RX Final Load to Unload GCR Messages",
	"RX SW Initiated GCR Message Destination IDs",
	"RX SW Initiated GCR Message Source IDs",
	"RX SW Initiated GCR Message Destination Addr",
	"RX SW Initiated GCR Message Write Data",
	"RX Clock Wiretest Status",
	"RX PLL or DLL reset and calibration controls",
	"RX Eye optimization step control",
	"RX Eye optimization step status",
	"RX Eye optimization step fail flags",
	"RX Eye optimization Amp  working registers",
	"RX SLS Handshake Recovery Register",
	"RX SLS Handshake Recovery GCR Messages",
	"RX: TX Lane Info",
	"CRC/ECC Syndrome Tallying GCR Message Reg",
	"RX Trace Mode Reg",
	"RX control for RDT (EI3-Mode only)",
	"RX Recalibraton     step control",
	"RX Eye Opt and Recal Status",
	"RX Recal Bit Error Rate Count Working Register",
	"RX Func Mode Status",
	"Dynamic Repair Testfloor/Debug Register",
	"CRC/ECC Dynamic Repair Bus Error Frequency Settings",
	"Eye widhth/height results check limits",
	"RX SLS Handshake Recovery Finish GCR Messages",
	"RX Wiretest Per-Pack Shadow Reg",
	"RX Mode Per-Pack Shadow Reg",
	"RX Cntl Per-Pack Shadow Reg",
	"RX Cal Cntl Per-Pack Shadow Reg",
	"RX Cal Accum inc value Reg",
	"RX Cal Accum inc value Reg",
	"RX Cal Accum dec value Reg",
	"RX Cal Accum dec value Reg",
	"RX Mode Per-Pack Shadow Reg",
	"RX BER Control Reg",
	"RX BER Mode Reg",
	"RX Servo Timeout Select Regs 1",
	"RX Servo Timeout Select Regs 2",
	"RX Configurable Reset Control Register (CRCR)",
	"RX Recal Servo Timeout Select Regs 1",
	"RX Recal Servo Timeout Select Regs 2",
	"RX Recal in progress control",
	"RX Trace Per Pack Settings",
	"RX BIST Cntl Reg",
	"Per-Bus BUSCTL FIR Error Reset Reg",
	"Per-Bus FIR Error Source-Isolation Reg",
	"Per-Bus FIR Error Source-Isolation Mask Reg",
	"Per-Bus FIR Error Injection Reg",
	"Per-Bus FIR Register Write Alias",
        "RX Clock Duty Cycle Adjust register"
};

// tx_mode_pl Register field name                                       data value   Description
#define     tx_lane_pdwn                                      0x8000     //Used to drive inhibit (tristate) and fully power down a lane independent of the logical lane disable. This control is independent from the per-group logical lane disable settings (tx_lane_disable_vec*) in order to allow for flexibility. Note that this control routes through the boundary scan logic, which has dominance.  Also note that per-group registers tx_lane_disabled_vec_0_15 and tx_lane_disabled_vec_16_31 are used to logically disable a lane with respect to the training, recalibration, and repair machines so both this per-lane and the per-group registers need to be set in order to logically disable and powerdown a lane. Note that this per-lane register is adjusted for lane swizzling automatically in HW but it is NOT adjusted automatically in HW when in the MSB-LSB swap mode so the eRepair procedure needs to take care to power down the correct lane when in this mode. 
#define     tx_lane_pdwn_clear                                0x7FFF     // Clear mask
#define     tx_lane_invert                                    0x4000     //Used to invert the polarity of a lane.
#define     tx_lane_invert_clear                              0xBFFF     // Clear mask
#define     tx_lane_quiesce_p_quiesce_to_0                    0x1000     //Used to force the output of the positive differential leg of a lane to a particular value.  Quiesce Lane to a Static 0 value
#define     tx_lane_quiesce_p_quiesce_to_1                    0x2000     //Used to force the output of the positive differential leg of a lane to a particular value.  Quiesce Lane to a Static 1 value
#define     tx_lane_quiesce_p_quiesce_to_z                    0x3000     //Used to force the output of the positive differential leg of a lane to a particular value.  Tri-State Lane Output
#define     tx_lane_quiesce_p_clear                           0xCFFF     // Clear mask
#define     tx_lane_quiesce_n_quiesce_to_0                    0x0400     //Used to force the output of the negative differential leg of a lane to a particular value.  Quiesce Lane to a Static 0 value
#define     tx_lane_quiesce_n_quiesce_to_1                    0x0800     //Used to force the output of the negative differential leg of a lane to a particular value.  Quiesce Lane to a Static 1 value
#define     tx_lane_quiesce_n_quiesce_to_z                    0x0C00     //Used to force the output of the negative differential leg of a lane to a particular value.  Tri-State Lane Output
#define     tx_lane_quiesce_n_clear                           0xF3FF     // Clear mask
#define     tx_lane_scramble_disable                          0x0200     //Used to disable the TX scrambler on a specific lane or all lanes by using a per-lane/per-group global write.
#define     tx_lane_scramble_disable_clear                    0xFDFF     // Clear mask

// tx_cntl_stat_pl Register field name                                  data value   Description
#define     tx_fifo_err                                       0x8000     //Indicates an error condition in the TX FIFO.
#define     tx_fifo_err_clear                                 0x7FFF     // Clear mask

// tx_spare_mode_pl Register field name                                 data value   Description
#define     tx_pl_spare_mode_0                                0x8000     //Per-lane spare mode latch
#define     tx_pl_spare_mode_0_clear                          0x7FFF     // Clear mask
#define     tx_pl_spare_mode_1                                0x4000     //Per-lane spare mode latch
#define     tx_pl_spare_mode_1_clear                          0xBFFF     // Clear mask
#define     tx_pl_spare_mode_2                                0x2000     //Per-lane spare mode latch
#define     tx_pl_spare_mode_2_clear                          0xDFFF     // Clear mask
#define     tx_pl_spare_mode_3                                0x1000     //Per-lane spare mode latch
#define     tx_pl_spare_mode_3_clear                          0xEFFF     // Clear mask
#define     tx_pl_spare_mode_4                                0x0800     //Per-lane spare mode latch
#define     tx_pl_spare_mode_4_clear                          0xF7FF     // Clear mask
#define     tx_pl_spare_mode_5                                0x0400     //Per-lane spare mode latch
#define     tx_pl_spare_mode_5_clear                          0xFBFF     // Clear mask
#define     tx_pl_spare_mode_6                                0x0200     //Per-lane spare mode latch
#define     tx_pl_spare_mode_6_clear                          0xFDFF     // Clear mask
#define     tx_pl_spare_mode_7                                0x0100     //Per-lane spare mode latch
#define     tx_pl_spare_mode_7_clear                          0xFEFF     // Clear mask

// tx_bist_stat_pl Register field name                                  data value   Description
#define     tx_lane_bist_err                                  0x8000     //Indicates a TXBIST error occurred.
#define     tx_lane_bist_err_clear                            0x7FFF     // Clear mask
#define     tx_lane_bist_done                                 0x4000     //Indicates TXBIST has completed. 
#define     tx_lane_bist_done_clear                           0xBFFF     // Clear mask

// tx_prbs_mode_pl Register field name                                  data value   Description
#define     tx_prbs_tap_id_pattern_b                          0x2000     //TX Per-Lane PRBS Tap Selector  PRBS tap point B
#define     tx_prbs_tap_id_pattern_c                          0x4000     //TX Per-Lane PRBS Tap Selector  PRBS tap point C
#define     tx_prbs_tap_id_pattern_d                          0x6000     //TX Per-Lane PRBS Tap Selector  PRBS tap point D
#define     tx_prbs_tap_id_pattern_e                          0x8000     //TX Per-Lane PRBS Tap Selector  PRBS tap point E
#define     tx_prbs_tap_id_pattern_f                          0xA000     //TX Per-Lane PRBS Tap Selector  PRBS tap point F
#define     tx_prbs_tap_id_pattern_g                          0xC000     //TX Per-Lane PRBS Tap Selector  PRBS tap point G
#define     tx_prbs_tap_id_pattern_h                          0xE000     //TX Per-Lane PRBS Tap Selector  PRBS tap point H
#define     tx_prbs_tap_id_clear                              0x1FFF     // Clear mask

// tx_data_cntl_gcrmsg_pl Register field name                           data value   Description
#define     tx_drv_data_pattern_gcrmsg_drv_wt                 0x1000     //GCR Message: TX Per Data Lane Drive Patterns  Drive Wiretest Pattern
#define     tx_drv_data_pattern_gcrmsg_drv_1s                 0x2000     //GCR Message: TX Per Data Lane Drive Patterns  Drive All 1s Pattern
#define     tx_drv_data_pattern_gcrmsg_drv_simple_A           0x3000     //GCR Message: TX Per Data Lane Drive Patterns  Drive Simple Pattern A
#define     tx_drv_data_pattern_gcrmsg_drv_simple_B           0x4000     //GCR Message: TX Per Data Lane Drive Patterns  Drive Simple Pattern B
#define     tx_drv_data_pattern_gcrmsg_drv_full_prbs23        0x5000     //GCR Message: TX Per Data Lane Drive Patterns  PRBS-23 Full Speed Scramble Pattern A thru H
#define     tx_drv_data_pattern_gcrmsg_drv_red_prbs23         0x6000     //GCR Message: TX Per Data Lane Drive Patterns  PRBS-23 Reduced Density Scramble Pattern A thru H
#define     tx_drv_data_pattern_gcrmsg_drv_9th_prbs23         0x7000     //GCR Message: TX Per Data Lane Drive Patterns  PRBS-23 9th pattern
#define     tx_drv_data_pattern_gcrmsg_drv_ei3_iap            0x8000     //GCR Message: TX Per Data Lane Drive Patterns  EI-3 Busy IAP Pattern (EI4 only
#define     tx_drv_data_pattern_gcrmsg_drv_ei3_prbs12         0x9000     //GCR Message: TX Per Data Lane Drive Patterns  Drive EI-3 PRBS-12 Shifted RDT Pattern (EI4 only
#define     tx_drv_data_pattern_gcrmsg_TDR_square_wave        0xA000     //GCR Message: TX Per Data Lane Drive Patterns  Drives TDR Pulse-Square waves
#define     tx_drv_data_pattern_gcrmsg_k28_5                  0xB000     //GCR Message: TX Per Data Lane Drive Patterns  Drives 20-bit K28.5 pattern - padded to 32 bits
#define     tx_drv_data_pattern_gcrmsg_unused_A               0xC000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     tx_drv_data_pattern_gcrmsg_unused_B               0xD000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     tx_drv_data_pattern_gcrmsg_unused_C               0xE000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     tx_drv_data_pattern_gcrmsg_unused_D               0xF000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     tx_drv_data_pattern_gcrmsg_clear                  0x0FFF     // Clear mask
#define     tx_drv_func_data_gcrmsg                           0x0800     //GCR Message: Functional Data
#define     tx_drv_func_data_gcrmsg_clear                     0xF7FF     // Clear mask
#define     tx_sls_lane_sel_gcrmsg                            0x0400     //GCR Message: SLS Commands & Recalibration
#define     tx_sls_lane_sel_gcrmsg_clear                      0xFBFF     // Clear mask

// tx_sync_pattern_gcrmsg_pl Register field name                        data value   Description
#define     tx_drv_sync_patt_gcrmsg                           0x4000     //Sync Pattern
#define     tx_drv_sync_patt_gcrmsg_clear                     0xBFFF     // Clear mask

// tx_fir_pl Register field name                                        data value   Description
#define     tx_pl_fir_errs                                    0x8000     //A 1 in this field indicates that a register or state machine parity error has occurred in per-lane logic.
#define     tx_pl_fir_errs_clear                              0x7FFF     // Clear mask

// tx_fir_mask_pl Register field name                                   data value   Description
#define     tx_pl_fir_errs_mask                               0x8000     //FIR mask for all per-lane register or per-lane state machine parity errors.
#define     tx_pl_fir_errs_mask_clear                         0x7FFF     // Clear mask

// tx_fir_error_inject_pl Register field name                           data value   Description
#define     tx_pl_fir_err_inj                                 0x8000     //TX Per-Lane Parity Error Injection
#define     tx_pl_fir_err_inj_clear                           0x7FFF     // Clear mask

// tx_mode_fast_pl Register field name                                  data value   Description
#define     tx_err_inject                                     0x0000     //Software-only controlled register to inject one or more errors for one deserialized clock pulse on one or more specified beats on this lane.  Set bit position X to inject on beat X of a cycle.  Bits 0:3 are used in EDI and 0:1 are used in EI4. 
#define     tx_err_inject_clear                               0x0FFF     // Clear mask
#define     tx_err_inj_A_enable                               0x0800     //Control to enable the random bit error injection pattern A for this lane.(default)
#define     tx_err_inj_A_enable_clear                         0xF7FF     // Clear mask
#define     tx_err_inj_B_enable                               0x0400     //Control to enable the random bit error injection pattern B for this lane.(default)
#define     tx_err_inj_B_enable_clear                         0xFBFF     // Clear mask

// tx_tdr_stat_pl Register field name                                   data value   Description
#define     tx_tdr_capt_val                                   0x8000     //value captured by TDR function, 1-bit shared over a pack, so this value should be the same for each bit (dmb)
#define     tx_tdr_capt_val_clear                             0x7FFF     // Clear mask

// tx_cntl_gcrmsg_pl Register field name                                data value   Description
#define     tx_pdwn_lite_gcrmsg                               0x8000     //GCR Message: When set, gates TX data path (post FIFO) to 0s on unused spare lanes when not being recalibrated
#define     tx_pdwn_lite_gcrmsg_clear                         0x7FFF     // Clear mask

// tx_clk_mode_pg Register field name                                   data value   Description
#define     tx_clk_pdwn                                       0x8000     //Used to disable the TX clock and put it into a low power state.
#define     tx_clk_pdwn_clear                                 0x7FFF     // Clear mask
#define     tx_clk_invert                                     0x4000     //Used to invert the polarity of the clock.
#define     tx_clk_invert_clear                               0xBFFF     // Clear mask
#define     tx_clk_quiesce_p_quiesce_to_0                     0x1000     //Used to force the output of the positive differential leg of the clock lane to a particular value.  Note that the 0 and 1 settings for EDI are for lab characterization only, and the circuits are not deemed to have the proper drive strength in those modes to meet production level quality.  Quiesce Clock Lane to a Static 0 value
#define     tx_clk_quiesce_p_quiesce_to_1                     0x2000     //Used to force the output of the positive differential leg of the clock lane to a particular value.  Note that the 0 and 1 settings for EDI are for lab characterization only, and the circuits are not deemed to have the proper drive strength in those modes to meet production level quality.  Quiesce Clock Lane to a Static 1 value
#define     tx_clk_quiesce_p_quiesce_to_z                     0x3000     //Used to force the output of the positive differential leg of the clock lane to a particular value.  Note that the 0 and 1 settings for EDI are for lab characterization only, and the circuits are not deemed to have the proper drive strength in those modes to meet production level quality.  Tri-State Clock Lane Output
#define     tx_clk_quiesce_p_clear                            0xCFFF     // Clear mask
#define     tx_clk_quiesce_n_quiesce_to_0                     0x0400     //Used to force the output of the negative differential leg of the clock lane to a particular value.  Note that the 0 and 1 settings for EDI are for lab characterization only, and the circuits are not deemed to have the proper drive strength in those modes to meet production level quality.  Quiesce Clock Lane to a Static 0 value
#define     tx_clk_quiesce_n_quiesce_to_1                     0x0800     //Used to force the output of the negative differential leg of the clock lane to a particular value.  Note that the 0 and 1 settings for EDI are for lab characterization only, and the circuits are not deemed to have the proper drive strength in those modes to meet production level quality.  Quiesce Clock Lane to a Static 1 value
#define     tx_clk_quiesce_n_quiesce_to_z                     0x0C00     //Used to force the output of the negative differential leg of the clock lane to a particular value.  Note that the 0 and 1 settings for EDI are for lab characterization only, and the circuits are not deemed to have the proper drive strength in those modes to meet production level quality.  Tri-State Clock Lane Output
#define     tx_clk_quiesce_n_clear                            0xF3FF     // Clear mask
#define     tx_clk_ddr_mode                                   0x0200     //Used to select TX clock QDR mode or DDR mode. 
#define     tx_clk_ddr_mode_clear                             0xFDFF     // Clear mask

// tx_spare_mode_pg Register field name                                 data value   Description
#define     tx_pg_spare_mode_0                                0x8000     //Per-group spare mode latch
#define     tx_pg_spare_mode_0_clear                          0x7FFF     // Clear mask
#define     tx_pg_spare_mode_1                                0x4000     //Per-group spare mode latch
#define     tx_pg_spare_mode_1_clear                          0xBFFF     // Clear mask
#define     tx_pg_spare_mode_2                                0x2000     //Per-group spare mode latch
#define     tx_pg_spare_mode_2_clear                          0xDFFF     // Clear mask
#define     tx_pg_spare_mode_3                                0x1000     //Per-group spare mode latch
#define     tx_pg_spare_mode_3_clear                          0xEFFF     // Clear mask
#define     tx_pg_spare_mode_4                                0x0800     //Per-group spare mode latch
#define     tx_pg_spare_mode_4_clear                          0xF7FF     // Clear mask
#define     tx_pg_spare_mode_5                                0x0400     //Per-group spare mode latch
#define     tx_pg_spare_mode_5_clear                          0xFBFF     // Clear mask
#define     tx_pg_spare_mode_6                                0x0200     //Per-group spare mode latch
#define     tx_pg_spare_mode_6_clear                          0xFDFF     // Clear mask
#define     tx_pg_spare_mode_7                                0x0100     //Per-group spare mode latch
#define     tx_pg_spare_mode_7_clear                          0xFEFF     // Clear mask

// tx_cntl_stat_pg Register field name                                  data value   Description
#define     tx_fifo_init                                      0x4000     //Used to initialize the TX FIFO and put it into a known reset state. This will cause the load to unload delay of the FIFO to be set to the value in the TX_FIFO_L2U_DLY field of the TX_FIFO_Mode register.
#define     tx_fifo_init_clear                                0xBFFF     // Clear mask

// tx_mode_pg Register field name                                       data value   Description
#define     tx_max_bad_lanes                                  0x0000     //Static Repair, Dynamic Repair & Recal max number of bad lanes per TX bus (NOTE: should match RX side)
#define     tx_max_bad_lanes_clear                            0x07FF     // Clear mask
#define     tx_msbswap                                        0x0400     //Used to enable end-for-end or msb swap of TX lanes.  For example, lanes 0 and N-1 swap, lanes 1 and N-2 swap, etc. 
#define     tx_msbswap_clear                                  0xFBFF     // Clear mask
#define     tx_pdwn_lite_disable                              0x0200     //Disables the power down lite feature of unused spare lanes (generally should match rx_pdwn_lite_disable)
#define     tx_pdwn_lite_disable_clear                        0xFDFF     // Clear mask

// tx_bus_repair_pg Register field name                                 data value   Description
#define     tx_bus_repair_count                               0x0000     //This field is used to TBD.
#define     tx_bus_repair_count_clear                         0x3FFF     // Clear mask
#define     tx_bus_repair_pos_0                               0x0000     //This field is used to TBD.
#define     tx_bus_repair_pos_0_clear                         0xC07F     // Clear mask
#define     tx_bus_repair_pos_1                               0x0000     //This field is used to TBD.
#define     tx_bus_repair_pos_1_clear                         0x3F80     // Clear mask

// tx_grp_repair_vec_0_15_pg Register field name                        data value   Description
#define     tx_grp_repair_vec_0_15                            0x0000     //This field is used to TBD.
#define     tx_grp_repair_vec_0_15_clear                      0x0000     // Clear mask

// tx_grp_repair_vec_16_31_pg Register field name                       data value   Description
#define     tx_grp_repair_vec_16_31                           0x0000     //This field is used to TBD.
#define     tx_grp_repair_vec_16_31_clear                     0x0000     // Clear mask

// tx_reset_act_pg Register field name                                  data value   Description
#define     tx_reset_cfg_ena                                  0x8000     //Enable Configurable Group Reset
#define     tx_reset_cfg_ena_clear                            0x7FFF     // Clear mask
#define     tx_clr_par_errs                                   0x0002     //Clear All TX Parity Error Latches
#define     tx_clr_par_errs_clear                             0xFFFD     // Clear mask
#define     tx_fir_reset                                      0x0001     //FIR Reset
#define     tx_fir_reset_clear                                0xFFFE     // Clear mask

// tx_bist_stat_pg Register field name                                  data value   Description
#define     tx_clk_bist_err                                   0x4000     //Indicates a TXBIST error occurred.
#define     tx_clk_bist_err_clear                             0xBFFF     // Clear mask
#define     tx_clk_bist_done                                  0x1000     //Indicates TXBIST has completed. 
#define     tx_clk_bist_done_clear                            0xEFFF     // Clear mask

// tx_fir_pg Register field name                                        data value   Description
#define     tx_pg_fir_errs_clear                              0x00FF     // Clear mask
#define     tx_pl_fir_err                                     0x0001     //Summary bit indicating a TX per-lane register or state machine parity error has occurred in one or more lanes. The tx_fir_pl register from each lane should be read to isolate to a particular piece of logic. There is no mechanism to determine which lane had the fault without reading FIR status from each lane.
#define     tx_pl_fir_err_clear                               0xFFFE     // Clear mask

// tx_fir_mask_pg Register field name                                   data value   Description
#define     tx_pg_fir_errs_mask_clear                         0x00FF     // Clear mask
#define     tx_pl_fir_err_mask                                0x0001     //FIR mask for the summary bit that indicates a per-lane TX register or state machine parity error has occurred. This mask bit is used to block ALL per-lane TX parity errors from causing a FIR error.\pmt
#define     tx_pl_fir_err_mask_clear                          0xFFFE     // Clear mask

// tx_fir_error_inject_pg Register field name                           data value   Description
#define     tx_pg_fir_err_inj_inj_par_err                     0x1000     //TX Per-Group Parity Error Injection  Causes a parity flip in the specific parity checker.
#define     tx_pg_fir_err_inj_clear                           0x00FF     // Clear mask

// tx_id1_pg Register field name                                        data value   Description
#define     tx_bus_id                                         0x0000     //This field is used to programmably set the bus number that a clkgrp belongs to.
#define     tx_bus_id_clear                                   0x03FF     // Clear mask
#define     tx_group_id                                       0x0000     //This field is used to programmably set the clock group number within a bus.
#define     tx_group_id_clear                                 0xFE07     // Clear mask

// tx_id2_pg Register field name                                        data value   Description
#define     tx_last_group_id                                  0x0000     //This field is used to programmably set the last clock group number within a bus.
#define     tx_last_group_id_clear                            0x03FF     // Clear mask

// tx_id3_pg Register field name                                        data value   Description
#define     tx_start_lane_id                                  0x0000     //This field is used to programmably set the first lane position in the group but relative to the bus.
#define     tx_start_lane_id_clear                            0x80FF     // Clear mask
#define     tx_end_lane_id                                    0x0000     //This field is used to programmably set the last lane position in the group but relative to the bus.
#define     tx_end_lane_id_clear                              0x7F80     // Clear mask

// tx_clk_cntl_gcrmsg_pg Register field name                            data value   Description
#define     tx_drv_clk_pattern_gcrmsg_drv_wt                  0x4000     //TX Clock Drive Patterns  Drive Wiretest Pattern
#define     tx_drv_clk_pattern_gcrmsg_drv_c4                  0x8000     //TX Clock Drive Patterns  Drive Clock Pattern
#define     tx_drv_clk_pattern_gcrmsg_unused                  0xC000     //TX Clock Drive Patterns  Unused
#define     tx_drv_clk_pattern_gcrmsg_clear                   0x3FFF     // Clear mask

// tx_ffe_mode_pg Register field name                                   data value   Description
#define     tx_ffe_test_mode_seg_test                         0x1000     //Driver Segment Test mode  Driver Output Test Mode
#define     tx_ffe_test_mode_unused1                          0x2000     //Driver Segment Test mode  Reserved
#define     tx_ffe_test_mode_unused2                          0x3000     //Driver Segment Test mode  Reserved
#define     tx_ffe_test_mode_clear                            0xCFFF     // Clear mask
#define     tx_ffe_test_override1r                            0x0200     //Driver Segment Test 1R Override
#define     tx_ffe_test_override1r_clear                      0xFDFF     // Clear mask
#define     tx_ffe_test_override2r                            0x0100     //Driver Segment Test 2R Override
#define     tx_ffe_test_override2r_clear                      0xFEFF     // Clear mask

// tx_ffe_main_pg Register field name                                   data value   Description
#define     tx_ffe_main_p_enc                                 0x0000     //TBD
#define     tx_ffe_main_p_enc_clear                           0x80FF     // Clear mask
#define     tx_ffe_main_n_enc                                 0x0000     //TBD
#define     tx_ffe_main_n_enc_clear                           0x7F80     // Clear mask

// tx_ffe_post_pg Register field name                                   data value   Description
#define     tx_ffe_post_p_enc                                 0x0000     //TBD This field is updated during TX BIST by logic temporarily
#define     tx_ffe_post_p_enc_clear                           0x00FF     // Clear mask
#define     tx_ffe_post_n_enc                                 0x0000     //TBD
#define     tx_ffe_post_n_enc_clear                           0x1FE0     // Clear mask

// tx_ffe_margin_pg Register field name                                 data value   Description
#define     tx_ffe_margin_p_enc                               0x0000     //TBD
#define     tx_ffe_margin_p_enc_clear                         0x00FF     // Clear mask
#define     tx_ffe_margin_n_enc                               0x0000     //TBD
#define     tx_ffe_margin_n_enc_clear                         0x1FE0     // Clear mask

// tx_bad_lane_enc_gcrmsg_pg Register field name                        data value   Description
#define     tx_bad_lane1_gcrmsg                               0x0000     //GCR Message: Encoded bad lane one in relation to the entire TX bus
#define     tx_bad_lane1_gcrmsg_clear                         0x01FF     // Clear mask
#define     tx_bad_lane2_gcrmsg                               0x0000     //GCR Message: Encoded bad lane two in relation to the entire TX bus
#define     tx_bad_lane2_gcrmsg_clear                         0xFE03     // Clear mask
#define     tx_bad_lane_code_gcrmsg_bad_ln1_val               0x0001     //GCR Message: TX Bad Lane Code  Bad Lane 1 Valid
#define     tx_bad_lane_code_gcrmsg_bad_lns12_val             0x0002     //GCR Message: TX Bad Lane Code  Bad Lanes 1 and 2 Valid
#define     tx_bad_lane_code_gcrmsg_3plus_bad_lns             0x0003     //GCR Message: TX Bad Lane Code  3+ bad lanes
#define     tx_bad_lane_code_gcrmsg_clear                     0xFFF0     // Clear mask

// tx_sls_lane_enc_gcrmsg_pg Register field name                        data value   Description
#define     tx_sls_lane_gcrmsg                                0x0000     //GCR Message: Encoded SLS lane in relation to the entire TX bus
#define     tx_sls_lane_gcrmsg_clear                          0x01FF     // Clear mask
#define     tx_sls_lane_val_gcrmsg                            0x0100     //GCR Message: TX SLS Lane Valid
#define     tx_sls_lane_val_gcrmsg_clear                      0xFEFF     // Clear mask

// tx_wt_seg_enable_pg Register field name                              data value   Description
#define     tx_wt_en_all_clk_segs_gcrmsg                      0x8000     //TX Clock Wiretest driver segnments enable
#define     tx_wt_en_all_clk_segs_gcrmsg_clear                0x7FFF     // Clear mask
#define     tx_wt_en_all_data_segs_gcrmsg                     0x4000     //TX Data  Wiretest driver segnments enable
#define     tx_wt_en_all_data_segs_gcrmsg_clear               0xBFFF     // Clear mask

// tx_lane_disabled_vec_0_15_pg Register field name                     data value   Description
#define     tx_lane_disabled_vec_0_15                         0x0000     //Lanes disabled by HW (status) or method to force lane to be disabled (save power) from software (control).
#define     tx_lane_disabled_vec_0_15_clear                   0x0000     // Clear mask

// tx_lane_disabled_vec_16_31_pg Register field name                    data value   Description
#define     tx_lane_disabled_vec_16_31                        0x0000     //Lanes disabled by HW (status) or method to force lane to be disabled (save power) from software (control).
#define     tx_lane_disabled_vec_16_31_clear                  0x0000     // Clear mask

// tx_sls_lane_mux_gcrmsg_pg Register field name                        data value   Description
#define     tx_sls_lane_shdw_gcrmsg                           0x8000     //GCR Message: SLS lane shadowing or unshadowing functional data (used to set up TX mux controls)
#define     tx_sls_lane_shdw_gcrmsg_clear                     0x7FFF     // Clear mask

// tx_dyn_rpr_pg Register field name                                    data value   Description
#define     tx_sls_hndshk_state_clear                         0x07FF     // Clear mask

// tx_slv_mv_sls_ln_req_gcrmsg_pg Register field name                   data value   Description
#define     tx_slv_mv_sls_shdw_req_gcrmsg                     0x8000     //GCR Message: Request to TX Slave to Move SLS Lane
#define     tx_slv_mv_sls_shdw_req_gcrmsg_clear               0x7FFF     // Clear mask
#define     tx_slv_mv_sls_shdw_rpr_req_gcrmsg                 0x4000     //GCR Message: Request to TX Slave to Move SLS Lane & Set Bad Lane Register
#define     tx_slv_mv_sls_shdw_rpr_req_gcrmsg_clear           0xBFFF     // Clear mask
#define     tx_slv_mv_sls_unshdw_req_gcrmsg                   0x2000     //GCR Message: Request to TX Slave to Move SLS Lane
#define     tx_slv_mv_sls_unshdw_req_gcrmsg_clear             0xDFFF     // Clear mask
#define     tx_slv_mv_sls_unshdw_rpr_req_gcrmsg               0x1000     //GCR Message: Request to TX Slave to Move SLS Lane & Set Bad Lane Register
#define     tx_slv_mv_sls_unshdw_rpr_req_gcrmsg_clear         0xEFFF     // Clear mask
#define     tx_bus_width                                      0x0000     //GCR Message: TX Bus Width
#define     tx_bus_width_clear                                0xF01F     // Clear mask
#define     tx_slv_mv_sls_rpr_req_gcrmsg                      0x0010     //GCR Message: Request to TX Slave to Move SLS Lane & Set Bad Lane Register
#define     tx_slv_mv_sls_rpr_req_gcrmsg_clear                0xFFEF     // Clear mask
#define     tx_sls_lane_sel_lg_gcrmsg                         0x0008     //GCR Message: Sets the tx_sls_lane_sel_gcrmsg for the last good lane per bus during recal bad lane scenarios
#define     tx_sls_lane_sel_lg_gcrmsg_clear                   0xFFF7     // Clear mask
#define     tx_sls_lane_unsel_lg_gcrmsg                       0x0004     //GCR Message: Clears the tx_sls_lane_sel_gcrmsg for the last good lane per bus during recal bad lane scenarios
#define     tx_sls_lane_unsel_lg_gcrmsg_clear                 0xFFFB     // Clear mask
#define     tx_spr_lns_pdwn_lite_gcrmsg                       0x0002     //GCR Message: Signals the TX side to Power Down Lite (data gate) unused spare lanes at the end of static repair
#define     tx_spr_lns_pdwn_lite_gcrmsg_clear                 0xFFFD     // Clear mask

// tx_wiretest_pp Register field name                                   data value   Description
#define     tx_wt_pattern_length_256                          0x4000     //TX Wiretest Pattern Length  256
#define     tx_wt_pattern_length_512                          0x8000     //TX Wiretest Pattern Length  512
#define     tx_wt_pattern_length_1024                         0xC000     //TX Wiretest Pattern Length  1024
#define     tx_wt_pattern_length_clear                        0x3FFF     // Clear mask

// tx_mode_pp Register field name                                       data value   Description
#define     tx_reduced_scramble_mode_full_1                   0x4000     //Enables/Disables and sets reduced density of scramble pattern.   Full density 
#define     tx_reduced_scramble_mode_div2                     0x8000     //Enables/Disables and sets reduced density of scramble pattern.   Enable Div2 Reduced Density 
#define     tx_reduced_scramble_mode_div4                     0xC000     //Enables/Disables and sets reduced density of scramble pattern.   Enable Div4 Reduced Density.
#define     tx_reduced_scramble_mode_clear                    0x3FFF     // Clear mask
#define     tx_fifo_l2u_dly_4_to_6_ui                         0x0800     //This field is used to read or set the TX FIFO load to unload delay according to the following.  4 to 6 UI (default
#define     tx_fifo_l2u_dly_8_to_10_ui                        0x1000     //This field is used to read or set the TX FIFO load to unload delay according to the following.  8 to 10 UI
#define     tx_fifo_l2u_dly_12_to_14_ui                       0x1800     //This field is used to read or set the TX FIFO load to unload delay according to the following.  12 to 14 UI 
#define     tx_fifo_l2u_dly_16_to_18_ui                       0x2000     //This field is used to read or set the TX FIFO load to unload delay according to the following.  16 to 18 UI 
#define     tx_fifo_l2u_dly_20_to_22_ui                       0x2800     //This field is used to read or set the TX FIFO load to unload delay according to the following.  20 to 22 UI
#define     tx_fifo_l2u_dly_24_to_26_ui                       0x3000     //This field is used to read or set the TX FIFO load to unload delay according to the following.  24 to 26 UI
#define     tx_fifo_l2u_dly_28_to_30_ui                       0x3800     //This field is used to read or set the TX FIFO load to unload delay according to the following.  28 to 30 UI
#define     tx_fifo_l2u_dly_clear                             0xC7FF     // Clear mask

// tx_sls_gcrmsg_pp Register field name                                 data value   Description
#define     tx_snd_sls_cmd_gcrmsg                             0x8000     //GCR Message: Send SLS Command or Recalibration Data
#define     tx_snd_sls_cmd_gcrmsg_clear                       0x7FFF     // Clear mask
#define     tx_dyn_recal_tsr_ignore_gcrmsg                    0x4000     //GCR Message: Send Dynamic Recal SLS Commands all the time (not just during the Status Reporting interval)
#define     tx_dyn_recal_tsr_ignore_gcrmsg_clear              0xBFFF     // Clear mask
#define     tx_sls_cmd_gcrmsg                                 0x0000     //GCR Message: TX SLS Command
#define     tx_sls_cmd_gcrmsg_clear                           0xC0FF     // Clear mask
#define     tx_snd_sls_cmd_prev_gcrmsg                        0x0080     //GCR Message: Revert to sending previous SLS Command or Recalibration Data after recovery repair made
#define     tx_snd_sls_cmd_prev_gcrmsg_clear                  0xFF7F     // Clear mask
#define     tx_snd_sls_using_reg_scramble                     0x0040     //GCR Message: Send SLS command using normal scramble pattern instead of 9th pattern
#define     tx_snd_sls_using_reg_scramble_clear               0xFFBF     // Clear mask

// tx_ber_cntl_a_pp Register field name                                 data value   Description
#define     tx_err_inj_a_rand_beat_dis                        0x8000     //Used to disable randomization of error inject on different beats of data for pattern A.
#define     tx_err_inj_a_rand_beat_dis_clear                  0x7FFF     // Clear mask
#define     tx_err_inj_a_fine_sel_1_16                        0x1000     //Random LSB/fine-grained cycle offset variation control for pattern A, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Random offset in range of 1-16 cycles
#define     tx_err_inj_a_fine_sel_1_8                         0x2000     //Random LSB/fine-grained cycle offset variation control for pattern A, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Random offset in range of 1-8 cycles
#define     tx_err_inj_a_fine_sel_1_4                         0x3000     //Random LSB/fine-grained cycle offset variation control for pattern A, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Random offset in range of 1-4 cycles
#define     tx_err_inj_a_fine_sel_1_2                         0x4000     //Random LSB/fine-grained cycle offset variation control for pattern A, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Random offset in range of 1-2 cycles
#define     tx_err_inj_a_fine_sel_fixed1                      0x5000     //Random LSB/fine-grained cycle offset variation control for pattern A, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Fixed offset of 1 cycle
#define     tx_err_inj_a_fine_sel_fixed3                      0x6000     //Random LSB/fine-grained cycle offset variation control for pattern A, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Fixed offset of 3 cycles 
#define     tx_err_inj_a_fine_sel_fixed7                      0x7000     //Random LSB/fine-grained cycle offset variation control for pattern A, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Fixed offset of 7 cycles.
#define     tx_err_inj_a_fine_sel_clear                       0x8FFF     // Clear mask
#define     tx_err_inj_a_coarse_sel_9_24                      0x0100     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 9-24, mean of 16.5
#define     tx_err_inj_a_coarse_sel_13_20                     0x0200     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 13-20, mean of 16.5
#define     tx_err_inj_a_coarse_sel_16_19                     0x0300     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 16-19, mean of 16.5
#define     tx_err_inj_a_coarse_sel_17_18                     0x0400     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 16-17, mean of 16.5
#define     tx_err_inj_a_coarse_sel_1_8                       0x0500     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 1-8, mean of 4.5
#define     tx_err_inj_a_coarse_sel_3_6                       0x0600     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.     Range of 3-6, mean of 4.5
#define     tx_err_inj_a_coarse_sel_4_5                       0x0700     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.     Range of 4-5, mean of 4.5
#define     tx_err_inj_a_coarse_sel_fixed1                    0x0800     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 1
#define     tx_err_inj_a_coarse_sel_fixed3                    0x0900     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 3
#define     tx_err_inj_a_coarse_sel_fixed5                    0x0A00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 5
#define     tx_err_inj_a_coarse_sel_fixed6                    0x0B00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 6
#define     tx_err_inj_a_coarse_sel_fixed7                    0x0C00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 7
#define     tx_err_inj_a_coarse_sel_fixed17                   0x0D00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 17
#define     tx_err_inj_a_coarse_sel_fixed21                   0x0E00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 21
#define     tx_err_inj_a_coarse_sel_fixed25                   0x0F00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 25
#define     tx_err_inj_a_coarse_sel_clear                     0xF0FF     // Clear mask
#define     tx_err_inj_a_ber_sel                              0x0000     //Used to set the random bit error injection rate for pattern A.  When set to a binary value of N, the average bit error rate is 1/(2^N*beats*mean(msb)). 
#define     tx_err_inj_a_ber_sel_clear                        0x3FC0     // Clear mask

// tx_ber_cntl_b_pp Register field name                                 data value   Description
#define     tx_err_inj_b_rand_beat_dis                        0x8000     //Used to disable randomization of error inject on different beats of data for pattern B.
#define     tx_err_inj_b_rand_beat_dis_clear                  0x7FFF     // Clear mask
#define     tx_err_inj_b_fine_sel_1_16                        0x1000     //Random LSB/fine-grained cycle offset variation control for pattern B, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Random offset in range of 1-16 cycles
#define     tx_err_inj_b_fine_sel_1_8                         0x2000     //Random LSB/fine-grained cycle offset variation control for pattern B, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Random offset in range of 1-8 cycles
#define     tx_err_inj_b_fine_sel_1_4                         0x3000     //Random LSB/fine-grained cycle offset variation control for pattern B, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Random offset in range of 1-4 cycles
#define     tx_err_inj_b_fine_sel_1_2                         0x4000     //Random LSB/fine-grained cycle offset variation control for pattern B, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Random offset in range of 1-2 cycles
#define     tx_err_inj_b_fine_sel_fixed1                      0x5000     //Random LSB/fine-grained cycle offset variation control for pattern B, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Fixed offset of 1 cycle
#define     tx_err_inj_b_fine_sel_fixed3                      0x6000     //Random LSB/fine-grained cycle offset variation control for pattern B, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Fixed offset of 3 cycles 
#define     tx_err_inj_b_fine_sel_fixed7                      0x7000     //Random LSB/fine-grained cycle offset variation control for pattern B, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Fixed offset of 7 cycles.
#define     tx_err_inj_b_fine_sel_clear                       0x8FFF     // Clear mask
#define     tx_err_inj_b_coarse_sel_9_24                      0x0100     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 9-24, mean of 16.5
#define     tx_err_inj_b_coarse_sel_13_20                     0x0200     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 13-20, mean of 16.5
#define     tx_err_inj_b_coarse_sel_16_19                     0x0300     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 16-19, mean of 16.5
#define     tx_err_inj_b_coarse_sel_17_18                     0x0400     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 16-17, mean of 16.5
#define     tx_err_inj_b_coarse_sel_1_8                       0x0500     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 1-8, mean of 4.5
#define     tx_err_inj_b_coarse_sel_3_6                       0x0600     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.     Range of 3-6, mean of 4.5
#define     tx_err_inj_b_coarse_sel_4_5                       0x0700     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.     Range of 4-5, mean of 4.5
#define     tx_err_inj_b_coarse_sel_fixed1                    0x0800     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 1
#define     tx_err_inj_b_coarse_sel_fixed3                    0x0900     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 3
#define     tx_err_inj_b_coarse_sel_fixed5                    0x0A00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 5
#define     tx_err_inj_b_coarse_sel_fixed6                    0x0B00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 6
#define     tx_err_inj_b_coarse_sel_fixed7                    0x0C00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 7
#define     tx_err_inj_b_coarse_sel_fixed17                   0x0D00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 17
#define     tx_err_inj_b_coarse_sel_fixed21                   0x0E00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 21
#define     tx_err_inj_b_coarse_sel_fixed25                   0x0F00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 25
#define     tx_err_inj_b_coarse_sel_clear                     0xF0FF     // Clear mask
#define     tx_err_inj_b_ber_sel                              0x0000     //Used to set the random bit error injection rate for pattern B.  When set to a binary value of N, the average bit error rate is 1/(2^N*beats*mean(msb)). 
#define     tx_err_inj_b_ber_sel_clear                        0x3FC0     // Clear mask

// tx_dyn_recal_timeouts_pp Register field name                         data value   Description
#define     tx_dyn_recal_interval_timeout_sel_tap1            0x1000     //TX Dynamic Recalibration Interval Timeout Selects  16kUI or 1.7us
#define     tx_dyn_recal_interval_timeout_sel_tap2            0x2000     //TX Dynamic Recalibration Interval Timeout Selects  32kUI or 3.4us
#define     tx_dyn_recal_interval_timeout_sel_tap3            0x3000     //TX Dynamic Recalibration Interval Timeout Selects  64kUI or 6.8us
#define     tx_dyn_recal_interval_timeout_sel_tap4            0x4000     //TX Dynamic Recalibration Interval Timeout Selects  128kUI or 106.5ns
#define     tx_dyn_recal_interval_timeout_sel_tap5            0x5000     //TX Dynamic Recalibration Interval Timeout Selects  256kUI or 1.7us
#define     tx_dyn_recal_interval_timeout_sel_tap6            0x6000     //TX Dynamic Recalibration Interval Timeout Selects  8192kUI or 872.4us
#define     tx_dyn_recal_interval_timeout_sel_tap7            0x7000     //TX Dynamic Recalibration Interval Timeout Selects  infinite
#define     tx_dyn_recal_interval_timeout_sel_clear           0x8FFF     // Clear mask
#define     tx_dyn_recal_status_rpt_timeout_sel_tap1          0x0400     //TX Dynamic Recalibration Status Reporting Timeout Selects  1024UI or 106.5ns
#define     tx_dyn_recal_status_rpt_timeout_sel_tap2          0x0800     //TX Dynamic Recalibration Status Reporting Timeout Selects  2048UI or 212.9ns
#define     tx_dyn_recal_status_rpt_timeout_sel_tap3          0x0C00     //TX Dynamic Recalibration Status Reporting Timeout Selects  4096UI or 426.0ns
#define     tx_dyn_recal_status_rpt_timeout_sel_clear         0xF3FF     // Clear mask

// tx_bist_cntl_pp Register field name                                  data value   Description
#define     tx_bist_en                                        0x8000     //TBD. jgr
#define     tx_bist_en_clear                                  0x7FFF     // Clear mask
#define     tx_bist_clr                                       0x4000     //TBD. jgr
#define     tx_bist_clr_clear                                 0xBFFF     // Clear mask
#define     tx_bist_prbs7_en                                  0x2000     //TBD. This field is updated by the TX BIST logic when BIST is running. jgr
#define     tx_bist_prbs7_en_clear                            0xDFFF     // Clear mask

// tx_ber_cntl_sls_pp Register field name                               data value   Description
#define     tx_err_inj_sls_mode                               0x8000     //Used to set the random bit error injection for pattern A to work during SLS transmission only. 
#define     tx_err_inj_sls_mode_clear                         0x7FFF     // Clear mask
#define     tx_err_inj_sls_all_cmd                            0x4000     //Used to qualify the SLS mode error injection for pattern A, to inject on all SLS command transmissions. 
#define     tx_err_inj_sls_all_cmd_clear                      0xBFFF     // Clear mask
#define     tx_err_inj_sls_recal                              0x2000     //Used to qualify the SLS mode error injection for pattern A, to inject on the calibration lane only when not sending an SLS command. See workbook for details.
#define     tx_err_inj_sls_recal_clear                        0xDFFF     // Clear mask
#define     tx_err_inj_sls_cmd                                0x0000     //Used to qualify the SLS mode error injection for pattern A, to inject on only this SLS command transmission. See workbook for SLS command codes.
#define     tx_err_inj_sls_cmd_clear                          0xFFC0     // Clear mask

// tx_cntl_pp Register field name                                       data value   Description
#define     tx_enable_reduced_scramble                        0x8000     //Enables reduced density of scramble pattern. 
#define     tx_enable_reduced_scramble_clear                  0x7FFF     // Clear mask

// tx_reset_cfg_pp Register field name                                  data value   Description
#define     tx_reset_cfg_hld_clear                            0x0000     // Clear mask

// tx_tdr_cntl1_pp Register field name                                  data value   Description
#define     tx_tdr_dac_cntl                                   0x0000     //Controls Variable Threshold Receiver for TDR function
#define     tx_tdr_dac_cntl_clear                             0x00FF     // Clear mask
#define     tx_tdr_phase_sel                                  0x0040     //Controls Phase Select for TDR function, 0 is for _n loeg, 1 is for _p leg.
#define     tx_tdr_phase_sel_clear                            0xFFBF     // Clear mask

// tx_tdr_cntl2_pp Register field name                                  data value   Description
#define     tx_tdr_pulse_offset                               0x0000     //Offset value for TDR pulse.
#define     tx_tdr_pulse_offset_clear                         0x000F     // Clear mask

// tx_tdr_cntl3_pp Register field name                                  data value   Description
#define     tx_tdr_pulse_width                                0x0000     //With of TDR pulse.
#define     tx_tdr_pulse_width_clear                          0x000F     // Clear mask

// tx_impcal_pb Register field name                                     data value   Description
#define     tx_zcal_req                                       0x4000     //Impedance Calibration Sequence Enable
#define     tx_zcal_req_clear                                 0xBFFF     // Clear mask
#define     tx_zcal_done                                      0x2000     //Impedance Calibration Sequence Complete
#define     tx_zcal_done_clear                                0xDFFF     // Clear mask
#define     tx_zcal_error                                     0x1000     //Impedance Calibration Sequence Error
#define     tx_zcal_error_clear                               0xEFFF     // Clear mask
#define     tx_zcal_busy                                      0x0800     //Impedance Calibration Sequence Busy
#define     tx_zcal_busy_clear                                0xF7FF     // Clear mask
#define     tx_zcal_force_sample                              0x0400     //Impedance Comparison Sample Force
#define     tx_zcal_force_sample_clear                        0xFBFF     // Clear mask
#define     tx_zcal_cmp_out                                   0x0200     //Calibration Circuit Unqualified Sample
#define     tx_zcal_cmp_out_clear                             0xFDFF     // Clear mask
#define     tx_zcal_sample_cnt_clear                          0xFE00     // Clear mask

// tx_impcal_nval_pb Register field name                                data value   Description
#define     tx_zcal_n                                         0x0000     //Calibration Circuit NSeg Enable Value This holds the current value of the enabled segments and is 4x multiple of the actual segment count. May be read for current calibration result set during Calibration Sequence. May be written to immediately update circuit enables on each write. Used with tx_zcal_swo_* for manual calibration. Do not write when tx_zcal_req = 1. (binary code - 0x00 is zero slices and 0xA1 is maximum slices).
#define     tx_zcal_n_clear                                   0x007F     // Clear mask

// tx_impcal_pval_pb Register field name                                data value   Description
#define     tx_zcal_p                                         0x0000     //Calibration Circuit PSeg Enable Value This holds the current value of the enabled segments and is 4x multiple of the actual segment count. May be read for current calibration result set during Calibration Sequence. May be written to immediately update circuit enables on each write. Used with tx_zcal_swo_* for manual calibration. Do not write when tx_zcal_req = 1. (binary code - 0x00 is zero slices and 0xA1 is maximum slices).
#define     tx_zcal_p_clear                                   0x007F     // Clear mask

// tx_impcal_p_4x_pb Register field name                                data value   Description
#define     tx_zcal_p_4x                                      0x0000     //Calibration Circuit PSeg-4X Enable Value This holds the current value of the enabled segments and is 2x multiple of the actual segment count. May be read for current calibration result set during Calibration Sequence. May be written to immediately update circuit enables on each write. Used with tx_zcal_swo_* for manual calibration. Do not write when tx_zcal_req = 1. (binary code - 0x00 is zero slices and 0x15 is maximum slices).
#define     tx_zcal_p_4x_clear                                0x07FF     // Clear mask

// tx_impcal_swo1_pb Register field name                                data value   Description
#define     tx_zcal_swo_en                                    0x8000     //Impedance Calibration Software Override
#define     tx_zcal_swo_en_clear                              0x7FFF     // Clear mask
#define     tx_zcal_swo_cal_segs                              0x4000     //Impedance Calibration Software Bank Select
#define     tx_zcal_swo_cal_segs_clear                        0xBFFF     // Clear mask
#define     tx_zcal_swo_cmp_inv                               0x2000     //Impedance Calibration Software Compare Invert
#define     tx_zcal_swo_cmp_inv_clear                         0xDFFF     // Clear mask
#define     tx_zcal_swo_cmp_offset                            0x1000     //Impedance Calibration Software Offset Flush
#define     tx_zcal_swo_cmp_offset_clear                      0xEFFF     // Clear mask
#define     tx_zcal_swo_cmp_reset                             0x0800     //Impedance Calibration Software Comparator reset
#define     tx_zcal_swo_cmp_reset_clear                       0xF7FF     // Clear mask
#define     tx_zcal_swo_powerdown                             0x0400     //Impedance Calibration Software Circuit Powerdown
#define     tx_zcal_swo_powerdown_clear                       0xFBFF     // Clear mask
#define     tx_zcal_cya_data_inv                              0x0200     //Impedance Calibration CYA Sample Inversion
#define     tx_zcal_cya_data_inv_clear                        0xFDFF     // Clear mask
#define     tx_zcal_test_ovr_2r                               0x0100     //Impedance Calibration Test-Only 2R segment override
#define     tx_zcal_test_ovr_2r_clear                         0xFEFF     // Clear mask
#define     tx_zcal_debug_mode_Filters                        0x0001     //Calibration Circuit Debug Mode Select  probeA=rcin_p, probeB=rcin_n Observe filter input nodes, rcin_n is off-chip.
#define     tx_zcal_debug_mode_Comparators                    0x0002     //Calibration Circuit Debug Mode Select  probeA=comp_in_p, probeB=comp_in_n  Observe comparator inputs.
#define     tx_zcal_debug_mode_disabled11                     0x0003     //Calibration Circuit Debug Mode Select  Debug mode disabled
#define     tx_zcal_debug_mode_clear                          0xFFF0     // Clear mask

// tx_impcal_swo2_pb Register field name                                data value   Description
#define     tx_zcal_sm_min_val                                0x0000     //Impedance Calibration Minimum Search Threshold Low-side segment count limit used in calibration process. See circuit spec (binary code - 0x00 is zero slices and 0x50 is maximum slices).
#define     tx_zcal_sm_min_val_clear                          0x01FF     // Clear mask
#define     tx_zcal_sm_max_val                                0x0000     //Impedance Calibration Maximum Search Threshold High-side segment count limit used in calibration process. See circuit spec (binary code - 0x00 is zero slices and 0x50 is maximum slices).
#define     tx_zcal_sm_max_val_clear                          0xFE03     // Clear mask

// tx_analog_iref_pb Register field name                                data value   Description
#define     tx_iref_bc                                        0x0000     //Bias Code for the Iref macros on the TX side. All eight 3 bit codes enable current out. The cml voltage swings of the output current will vary with this code.
#define     tx_iref_bc_clear                                  0x1FFF     // Clear mask

// tx_minikerf_pb Register field name                                   data value   Description
#define     tx_minikerf                                       0x0000     //Used to configure the TX Minikerf for analog characterization.
#define     tx_minikerf_clear                                 0x0000     // Clear mask

// tx_init_version_pb Register field name                               data value   Description
#define     tx_init_version_clear                             0x0000     // Clear mask

// tx_scratch_reg_pb Register field name                                data value   Description
#define     tx_scratch_reg_clear                              0x0000     // Clear mask

// rx_mode_pl Register field name                                       data value   Description
#define     rx_lane_pdwn                                      0x8000     //Used to receive inhibit and fully power down a lane independent of the logical lane disable. This control is independent from the per-group logical lane disable settings (rx_lane_disable_vec*) in order to allow for flexibility. Note that this control routes through the boundary scan logic, which has dominance.  Also note that per-group registers rx_lane_disabled_vec_0_15 and rx_lane_disabled_vec_16_31 are used to logically disable a lane with respect to the training, recalibration, and repair machines so both this per-lane and the per-group registers need to be set in order to logically disable and powerdown a lane. Note that this per-lane register is adjusted for lane swizzling automatically in HW but it is NOT adjusted automatically in HW when in the MSB-LSB swap mode so the eRepair procedure needs to take care to power down the correct lane when in this mode. 
#define     rx_lane_pdwn_clear                                0x7FFF     // Clear mask
#define     rx_lane_scramble_disable                          0x0200     //Used to disable the RX descrambler on a specific lane or all lanes by using a per-lane/per-group global write.
#define     rx_lane_scramble_disable_clear                    0xFDFF     // Clear mask

// rx_cntl_pl Register field name                                       data value   Description
#define     rx_block_lock_lane                                0x8000     //Enables rotation and checking for block lock. 
#define     rx_block_lock_lane_clear                          0x7FFF     // Clear mask
#define     rx_check_skew_lane                                0x4000     //Per-Lane Initialization controls. Checks skew request
#define     rx_check_skew_lane_clear                          0xBFFF     // Clear mask
#define     rx_pdwn_lite                                      0x2000     //GCR Message: When set, partially powers down unused spare lanes when not being recalibrated
#define     rx_pdwn_lite_clear                                0xDFFF     // Clear mask

// rx_spare_mode_pl Register field name                                 data value   Description
#define     rx_pl_spare_mode_0                                0x8000     //Per-lane spare mode latch
#define     rx_pl_spare_mode_0_clear                          0x7FFF     // Clear mask
#define     rx_pl_spare_mode_1                                0x4000     //Per-lane spare mode latch
#define     rx_pl_spare_mode_1_clear                          0xBFFF     // Clear mask
#define     rx_pl_spare_mode_2                                0x2000     //Per-lane spare mode latch
#define     rx_pl_spare_mode_2_clear                          0xDFFF     // Clear mask
#define     rx_pl_spare_mode_3                                0x1000     //Per-lane spare mode latch
#define     rx_pl_spare_mode_3_clear                          0xEFFF     // Clear mask
#define     rx_pl_spare_mode_4                                0x0800     //Per-lane spare mode latch
#define     rx_pl_spare_mode_4_clear                          0xF7FF     // Clear mask
#define     rx_pl_spare_mode_5                                0x0400     //Per-lane spare mode latch
#define     rx_pl_spare_mode_5_clear                          0xFBFF     // Clear mask
#define     rx_pl_spare_mode_6                                0x0200     //Per-lane spare mode latch
#define     rx_pl_spare_mode_6_clear                          0xFDFF     // Clear mask
#define     rx_pl_spare_mode_7                                0x0100     //Per-lane spare mode latch
#define     rx_pl_spare_mode_7_clear                          0xFEFF     // Clear mask

// rx_prot_edge_status_pl Register field name                           data value   Description
#define     rx_phaserot_left_edge                             0x0000     //RX Phase Rotator left edge.
#define     rx_phaserot_left_edge_clear                       0xC0FF     // Clear mask
#define     rx_phaserot_right_edge                            0x0000     //RX Phase Rotator right edge.
#define     rx_phaserot_right_edge_clear                      0xFF03     // Clear mask

// rx_bist_stat_pl Register field name                                  data value   Description
#define     rx_bist_err                                       0x8000     //Indicates a RXBIST error occurred.
#define     rx_bist_err_clear                                 0x7FFF     // Clear mask
#define     rx_bist_done                                      0x4000     //Indicates a RXBIST has completed. 
#define     rx_bist_done_clear                                0xBFFF     // Clear mask

// rx_offset_even_pl Register field name                                data value   Description
#define     rx_offset_even_samp1                              0x0000     //This is the vertical offset of the even sampling latch.
#define     rx_offset_even_samp1_clear                        0x80FF     // Clear mask
#define     rx_offset_even_samp0                              0x0000     //This is the vertical offset of the even sampling latch.
#define     rx_offset_even_samp0_clear                        0x7F80     // Clear mask

// rx_offset_odd_pl Register field name                                 data value   Description
#define     rx_offset_odd_samp1                               0x0000     //This is the vertical offset of the odd sampling latch.
#define     rx_offset_odd_samp1_clear                         0x00FF     // Clear mask
#define     rx_offset_odd_samp0                               0x0000     //This is the vertical offset of the odd sampling latch.
#define     rx_offset_odd_samp0_clear                         0x7F80     // Clear mask

// rx_amp_val_pl Register field name                                    data value   Description
#define     rx_amp_peak                                       0x0000     //This is the vertical offset of the pre-amp.
#define     rx_amp_peak_clear                                 0x0FFF     // Clear mask
#define     rx_amp_gain                                       0x0000     //This is the gain setting of the pre-amp.
#define     rx_amp_gain_clear                                 0xF0FF     // Clear mask
#define     rx_amp_offset                                     0x0000     //This is the peaking setting of the pre-amp.
#define     rx_amp_offset_clear                               0x3FC0     // Clear mask

// rx_amp_cntl_pl Register field name                                   data value   Description
#define     rx_amp_adj_done                                   0x8000     //VGA adjust is complete for this lane.
#define     rx_amp_adj_done_clear                             0x7FFF     // Clear mask
#define     rx_amp_adj_all_done_b                             0x4000     //VGA adjust is complete for this lane--qualified and asserted low for dot-OR reading.
#define     rx_amp_adj_all_done_b_clear                       0xBFFF     // Clear mask

// rx_prot_status_pl Register field name                                data value   Description
#define     rx_phaserot_val                                   0x0000     //RX Phase Rotator current value.
#define     rx_phaserot_val_clear                             0xC0FF     // Clear mask
#define     rx_phaserot_ddc_complete                          0x0080     //RX DDC State Machine completion indicator.
#define     rx_phaserot_ddc_complete_clear                    0xFF7F     // Clear mask
#define     rx_phaserot_block_lock_err                        0x0040     //RX DDC State Machine block lock error indicator.
#define     rx_phaserot_block_lock_err_clear                  0xFFBF     // Clear mask

// rx_prot_mode_pl Register field name                                  data value   Description
#define     rx_phaserot_offset                                0x0000     //RX Phase Rotator fixed offset from learned value.
#define     rx_phaserot_offset_clear                          0xC0FF     // Clear mask

// rx_prot_cntl_pl Register field name                                  data value   Description
#define     rx_bump_left_half_ui                              0x8000     //Per-Lane Bump left 1/2 UI control (Self-Clearing)
#define     rx_bump_left_half_ui_clear                        0x7FFF     // Clear mask
#define     rx_bump_right_half_ui                             0x4000     //Per-Lane Bump right 1/2 UI control (Self-Clearing)
#define     rx_bump_right_half_ui_clear                       0xBFFF     // Clear mask
#define     rx_bump_one_ui                                    0x2000     //Per-Lane Bump 1 UI control (Self-Clearing)
#define     rx_bump_one_ui_clear                              0xDFFF     // Clear mask
#define     rx_bump_two_ui                                    0x1000     //Per-Lane Bump 2 UI control (Self-Clearing)
#define     rx_bump_two_ui_clear                              0xEFFF     // Clear mask
#define     rx_ext_sr                                         0x0800     //RX Manual Phase Rotator Shift Right Pulse
#define     rx_ext_sr_clear                                   0xF7FF     // Clear mask
#define     rx_ext_sl                                         0x0400     //RX Manual Phase Rotator Shift Left Pulse
#define     rx_ext_sl_clear                                   0xFBFF     // Clear mask

// rx_fifo_stat_pl Register field name                                  data value   Description
#define     rx_fifo_l2u_dly                                   0x0000     //RX FIFO load-to-unload delay, initailed during FIFO init and modified thereafter by the deskew machine.  For setting X, the latency is 4*X to 4*X+4 UI.  Default is 20-24 UI.
#define     rx_fifo_l2u_dly_clear                             0x0FFF     // Clear mask
#define     rx_fifo_init                                      0x0800     //Initializes the fifo unload counter with the load counter and initializes the fifo load to unload delay
#define     rx_fifo_init_clear                                0xF7FF     // Clear mask

// rx_ap_pl Register field name                                         data value   Description
#define     rx_ap_even_samp                                   0x0000     //TBD
#define     rx_ap_even_samp_clear                             0x00FF     // Clear mask
#define     rx_ap_odd_samp                                    0x0000     //TBD
#define     rx_ap_odd_samp_clear                              0xFF00     // Clear mask

// rx_an_pl Register field name                                         data value   Description
#define     rx_an_even_samp                                   0x0000     //TBD
#define     rx_an_even_samp_clear                             0x00FF     // Clear mask
#define     rx_an_odd_samp                                    0x0000     //TBD
#define     rx_an_odd_samp_clear                              0xFF00     // Clear mask

// rx_amin_pl Register field name                                       data value   Description
#define     rx_amin_even                                      0x0000     //TBD
#define     rx_amin_even_clear                                0x00FF     // Clear mask
#define     rx_amin_odd                                       0x0000     //TBD
#define     rx_amin_odd_clear                                 0xFF00     // Clear mask

// rx_h1_even_pl Register field name                                    data value   Description
#define     rx_h1_even_samp1                                  0x0000     //TBD
#define     rx_h1_even_samp1_clear                            0x00FF     // Clear mask
#define     rx_h1_even_samp0                                  0x0000     //TBD
#define     rx_h1_even_samp0_clear                            0x7F80     // Clear mask

// rx_h1_odd_pl Register field name                                     data value   Description
#define     rx_h1_odd_samp1                                   0x0000     //TBD
#define     rx_h1_odd_samp1_clear                             0x00FF     // Clear mask
#define     rx_h1_odd_samp0                                   0x0000     //TBD
#define     rx_h1_odd_samp0_clear                             0x7F80     // Clear mask

// rx_prbs_mode_pl Register field name                                  data value   Description
#define     rx_prbs_tap_id_pattern_b                          0x2000     //Per-Lane PRBS Tap Selector  PRBS tap point B
#define     rx_prbs_tap_id_pattern_c                          0x4000     //Per-Lane PRBS Tap Selector  PRBS tap point C
#define     rx_prbs_tap_id_pattern_d                          0x6000     //Per-Lane PRBS Tap Selector  PRBS tap point D
#define     rx_prbs_tap_id_pattern_e                          0x8000     //Per-Lane PRBS Tap Selector  PRBS tap point E
#define     rx_prbs_tap_id_pattern_F                          0xA000     //Per-Lane PRBS Tap Selector  PRBS tap point F
#define     rx_prbs_tap_id_pattern_g                          0xC000     //Per-Lane PRBS Tap Selector  PRBS tap point G
#define     rx_prbs_tap_id_pattern_h                          0xE000     //Per-Lane PRBS Tap Selector  PRBS tap point H
#define     rx_prbs_tap_id_clear                              0x1FFF     // Clear mask

// rx_stat_pl Register field name                                       data value   Description
#define     rx_some_block_locked                              0x8000     //Per-Lane Block Lock Indicator
#define     rx_some_block_locked_clear                        0x7FFF     // Clear mask
#define     rx_all_block_locked_b                             0x4000     //Per-Lane Block Lock Indicator
#define     rx_all_block_locked_b_clear                       0xBFFF     // Clear mask
#define     rx_some_skew_valid                                0x2000     //Per-Lane Deskew Pattern B Detect Indicator
#define     rx_some_skew_valid_clear                          0xDFFF     // Clear mask
#define     rx_all_skew_valid_b                               0x1000     //Per-Lane Deskew Pattern B Detect Indicato (Active Low)r
#define     rx_all_skew_valid_b_clear                         0xEFFF     // Clear mask
#define     rx_some_prbs_synced                               0x0800     //Per-Lane PRBS Synchronization Indicator
#define     rx_some_prbs_synced_clear                         0xF7FF     // Clear mask
#define     rx_prbs_synced_b                                  0x0400     //Per-Lane PRBS Synchronization Indicator (Active Low)
#define     rx_prbs_synced_b_clear                            0xFBFF     // Clear mask
#define     rx_skew_value                                     0x0000     //Per-Lane PRBS Synchronization Count
#define     rx_skew_value_clear                               0xFC0F     // Clear mask

// rx_deskew_stat_pl Register field name                                data value   Description
#define     rx_bad_block_lock                                 0x8000     //Deskew Step block lock not established--lane marked bad
#define     rx_bad_block_lock_clear                           0x7FFF     // Clear mask
#define     rx_bad_skew                                       0x4000     //Deskew Step skew value not detected--lane marked bad
#define     rx_bad_skew_clear                                 0xBFFF     // Clear mask
#define     rx_bad_deskew                                     0x2000     //Deskew Step deskew value
#define     rx_bad_deskew_clear                               0xDFFF     // Clear mask

// rx_fir_pl Register field name                                        data value   Description
#define     rx_pl_fir_errs_clear                              0x3FFF     // Clear mask

// rx_fir_mask_pl Register field name                                   data value   Description
#define     rx_pl_fir_errs_mask_err_pl_mask_ddc_sm            0x4000     //FIR mask for register or state machine parity checkers in per-lane logic. A value of 1 masks the error from generating a FIR error.  Per-Lane DDC SM Parity Error.
#define     rx_pl_fir_errs_mask_clear                         0x3FFF     // Clear mask

// rx_fir_error_inject_pl Register field name                           data value   Description
#define     rx_pl_fir_err_inj_inj_par_err                     0x4000     //RX Per-Lane Parity Error Injection  While this value is a 1, the parity bit is inverted in the specific parity checker.
#define     rx_pl_fir_err_inj_clear                           0x3FFF     // Clear mask

// rx_sls_pl Register field name                                        data value   Description
#define     rx_sls_lane_sel                                   0x8000     //Selects which lane to receive SLS Commands and Recalibration Data on
#define     rx_sls_lane_sel_clear                             0x7FFF     // Clear mask
#define     rx_9th_pattern_en                                 0x4000     //Sets RX Descrabmler to use 9th Scramble Pattern
#define     rx_9th_pattern_en_clear                           0xBFFF     // Clear mask

// rx_wt_status_pl Register field name                                  data value   Description
#define     rx_wt_lane_disabled                               0x8000     //Per-Lane Wiretest lane disabled status
#define     rx_wt_lane_disabled_clear                         0x7FFF     // Clear mask
#define     rx_wt_lane_inverted                               0x4000     //Per-Lane Wiretest lane inverted/swapped status
#define     rx_wt_lane_inverted_clear                         0xBFFF     // Clear mask
#define     rx_wt_lane_bad_code_n_stuck_1                     0x0800     //Per-Lane Wiretest Lane Bad code  N-leg stuck at 1.
#define     rx_wt_lane_bad_code_n_stuck_0                     0x1000     //Per-Lane Wiretest Lane Bad code  N-leg stuck at 0.
#define     rx_wt_lane_bad_code_p_stuck_1                     0x1800     //Per-Lane Wiretest Lane Bad code  P-leg stuck at 1.
#define     rx_wt_lane_bad_code_p_stuck_0                     0x2000     //Per-Lane Wiretest Lane Bad code  P-leg stuck at 0.
#define     rx_wt_lane_bad_code_n_or_p_floating               0x2800     //Per-Lane Wiretest Lane Bad code  N- or P- leg floating-swapping undetermined.
#define     rx_wt_lane_bad_code_p_or_n_floating               0x3000     //Per-Lane Wiretest Lane Bad code  P or N leg floating--swapping undetermined.
#define     rx_wt_lane_bad_code_unknown                       0x3800     //Per-Lane Wiretest Lane Bad code  Unknown failure.
#define     rx_wt_lane_bad_code_clear                         0xC7FF     // Clear mask

// rx_fifo_cntl_pl Register field name                                  data value   Description
#define     rx_fifo_inc_l2u_dly                               0x8000     //Increment existing FIFO load-to-unload delay register.
#define     rx_fifo_inc_l2u_dly_clear                         0x7FFF     // Clear mask
#define     rx_fifo_dec_l2u_dly                               0x4000     //Decrement existing FIFO load-to-unload delay register.
#define     rx_fifo_dec_l2u_dly_clear                         0xBFFF     // Clear mask
#define     rx_clr_skew_valid                                 0x2000     //Clear skew valid registers                            
#define     rx_clr_skew_valid_clear                           0xDFFF     // Clear mask

// rx_ber_status_pl Register field name                                 data value   Description
#define     rx_ber_count                                      0x0000     //Per-Lane (PL) Diagnostic Bit Error Rate (BER) error counter. Increments when in diagnostic BER mode AND the output of the descrambler is non-zero. This counter counts errors on every UI so it is a true BER counter.
#define     rx_ber_count_clear                                0x00FF     // Clear mask
#define     rx_ber_count_saturated                            0x0080     //PL Diag BER Error Counter saturation indicator. When '1' indicates that the error counter has saturated to the selected max value. A global per-lane read of this field will indicate if any lane error counters in the group are saturated.
#define     rx_ber_count_saturated_clear                      0xFF7F     // Clear mask
#define     rx_ber_count_frozen_by_lane                       0x0040     //PL Diag BER Error Counter and or PP Timer has been frozen by another lane's error counter being saturated.
#define     rx_ber_count_frozen_by_lane_clear                 0xFFBF     // Clear mask
#define     rx_ber_count_frozen_by_timer                      0x0020     //PL Diag BER Error Counter has been frozen by a diag BER timer becoming saturated.
#define     rx_ber_count_frozen_by_timer_clear                0xFFDF     // Clear mask
#define     rx_ber_timer_saturated                            0x0010     //PL Diag BER Timer saturation indicator. When '1' indicates that the pack BER timer has saturated to the max value. A global per-lane read of this field will indicate if any timer in the group has saturated.
#define     rx_ber_timer_saturated_clear                      0xFFEF     // Clear mask

// rx_ber_timer_0_15_pl Register field name                             data value   Description
#define     rx_ber_timer_value_0_15                           0x0000     //PL Diag BER Timer value for this lane, bits 0-15. All lanes in a pack share a timer and will have the same timer value. The value can either be read on one lane in a pack to save data collection time or all lanes can be read.
#define     rx_ber_timer_value_0_15_clear                     0x0000     // Clear mask

// rx_ber_timer_16_31_pl Register field name                            data value   Description
#define     rx_ber_timer_value_16_31                          0x0000     //PL Diag BER Timer value, bits 16-31.
#define     rx_ber_timer_value_16_31_clear                    0x0000     // Clear mask

// rx_ber_timer_32_39_pl Register field name                            data value   Description
#define     rx_ber_timer_value_32_39                          0x0000     //PL Diag BER Timer value, bits 32-39.
#define     rx_ber_timer_value_32_39_clear                    0x00FF     // Clear mask

// rx_servo_cntl_pl Register field name                                 data value   Description
#define     rx_servo_op_done                                  0x8000     //Servo Op completed
#define     rx_servo_op_done_clear                            0x7FFF     // Clear mask
#define     rx_servo_op_all_done_b                            0x4000     //All Servo Op (asserted low for global dot-Or reading)
#define     rx_servo_op_all_done_b_clear                      0xBFFF     // Clear mask
#define     rx_servo_op                                       0x0000     //Servo Operation code
#define     rx_servo_op_clear                                 0xC1FF     // Clear mask
#define     rx_scope_en                                       0x0100     //Set this bit to enable per lane scope mode
#define     rx_scope_en_clear                                 0xFEFF     // Clear mask

// rx_fifo_diag_0_15_pl Register field name                             data value   Description
#define     rx_fifo_out_0_15                                  0x0000     //Diag Capture: fifo entries 0 to 15
#define     rx_fifo_out_0_15_clear                            0x0000     // Clear mask

// rx_fifo_diag_16_31_pl Register field name                            data value   Description
#define     rx_fifo_out_16_31                                 0x0000     //Diag Capture: fifo entries 16 to 31
#define     rx_fifo_out_16_31_clear                           0x0000     // Clear mask

// rx_fifo_diag_32_47_pl Register field name                            data value   Description
#define     rx_fifo_out_32_47                                 0x0000     //Diag Capture: fifo entries 32 to 47
#define     rx_fifo_out_32_47_clear                           0x0000     // Clear mask

// rx_eye_width_status_pl Register field name                           data value   Description
#define     rx_eye_width                                      0x0000     //RX Current Eye Width (in PR steps).
#define     rx_eye_width_clear                                0x00FF     // Clear mask
#define     rx_hist_min_eye_width_valid                       0x0080     //RX Historic Eye Minimum is valid for this lane.
#define     rx_hist_min_eye_width_valid_clear                 0xFF7F     // Clear mask
#define     rx_hist_min_eye_width                             0x0000     //RX Historic Eye Minimum--per-pack register valid for this lane if rx_hist_eye_min_valid is asserted for this lane.
#define     rx_hist_min_eye_width_clear                       0xDFC0     // Clear mask

// rx_eye_width_cntl_pl Register field name                             data value   Description
#define     rx_reset_hist_eye_width_min                       0x8000     //RX Historic Eye Minimum Reset--reset historic min to maximum value and clears valid bits.
#define     rx_reset_hist_eye_width_min_clear                 0x7FFF     // Clear mask

// rx_dfe_clkadj_pl Register field name                                 data value   Description
#define     rx_dfe_clkadj                                     0x0000     //TBD
#define     rx_dfe_clkadj_clear                               0x0FFF     // Clear mask

// rx_trace_pl Register field name                                      data value   Description
#define     rx_ln_trc_en                                      0x8000     //Enable tracing of this lane
#define     rx_ln_trc_en_clear                                0x7FFF     // Clear mask

// rx_servo_ber_count_pl Register field name                            data value   Description
#define     rx_servo_ber_count                                0x0000     //Servo-based bit error count.
#define     rx_servo_ber_count_clear                          0x000F     // Clear mask

// rx_eye_opt_stat_pl Register field name                               data value   Description
#define     rx_bad_eye_opt_ber                                0x8000     //Eye opt Step failed BER test--lane marked bad
#define     rx_bad_eye_opt_ber_clear                          0x7FFF     // Clear mask
#define     rx_bad_eye_opt_width                              0x4000     //Eye opt Step failed width test--lane marked bad
#define     rx_bad_eye_opt_width_clear                        0xBFFF     // Clear mask
#define     rx_bad_eye_opt_height                             0x2000     //Eye opt Step failed height test--lane marked bad
#define     rx_bad_eye_opt_height_clear                       0xDFFF     // Clear mask
#define     rx_bad_eye_opt_ddc                                0x1000     //Eye opt Step failed dynamic data centering--lane marked bad
#define     rx_bad_eye_opt_ddc_clear                          0xEFFF     // Clear mask

// rx_clk_mode_pg Register field name                                   data value   Description
#define     rx_clk_pdwn                                       0x8000     //Used to disable the rx clock and put it into a low power state.
#define     rx_clk_pdwn_clear                                 0x7FFF     // Clear mask
#define     rx_clk_invert                                     0x4000     //Used to invert the polarity of the clock.
#define     rx_clk_invert_clear                               0xBFFF     // Clear mask

// rx_spare_mode_pg Register field name                                 data value   Description
#define     rx_pg_spare_mode_0                                0x8000     //Per-group spare mode latch
#define     rx_pg_spare_mode_0_clear                          0x7FFF     // Clear mask
#define     rx_pg_spare_mode_1                                0x4000     //Per-group spare mode latch
#define     rx_pg_spare_mode_1_clear                          0xBFFF     // Clear mask
#define     rx_pg_spare_mode_2                                0x2000     //Per-group spare mode latch
#define     rx_pg_spare_mode_2_clear                          0xDFFF     // Clear mask
#define     rx_pg_spare_mode_3                                0x1000     //Per-group spare mode latch
#define     rx_pg_spare_mode_3_clear                          0xEFFF     // Clear mask
#define     rx_pg_spare_mode_4                                0x0800     //Per-group spare mode latch
#define     rx_pg_spare_mode_4_clear                          0xF7FF     // Clear mask
#define     rx_pg_spare_mode_5                                0x0400     //Per-group spare mode latch
#define     rx_pg_spare_mode_5_clear                          0xFBFF     // Clear mask
#define     rx_pg_spare_mode_6                                0x0200     //Per-group spare mode latch
#define     rx_pg_spare_mode_6_clear                          0xFDFF     // Clear mask
#define     rx_pg_spare_mode_7                                0x0100     //Per-group spare mode latch
#define     rx_pg_spare_mode_7_clear                          0xFEFF     // Clear mask

// rx_stop_cntl_stat_pg Register field name                             data value   Description
#define     rx_stop_state_enable                              0x8000     //Enable State machine stop of address
#define     rx_stop_state_enable_clear                        0x7FFF     // Clear mask
#define     rx_state_stopped                                  0x4000     //State Machines stopped
#define     rx_state_stopped_clear                            0xBFFF     // Clear mask
#define     rx_resume_from_stop                               0x2000     //Resume stopped state machines and /or counters
#define     rx_resume_from_stop_clear                         0xDFFF     // Clear mask
#define     rx_stop_addr_msb                                  0x0000     //Stop address Most-significant four bits 0 to 3
#define     rx_stop_addr_msb_clear                            0xFF0F     // Clear mask
#define     rx_stop_mask_msb                                  0x0000     //Stop mask    Most-significant four bits 0 to 3
#define     rx_stop_mask_msb_clear                            0xF0F0     // Clear mask

// rx_mode_pg Register field name                                       data value   Description
#define     rx_master_mode                                    0x8000     //Master Mode
#define     rx_master_mode_clear                              0x7FFF     // Clear mask
#define     rx_disable_fence_reset                            0x4000     //Set to disable clearing of the RX and TX fence controls at the end of training. 
#define     rx_disable_fence_reset_clear                      0xBFFF     // Clear mask
#define     rx_pdwn_lite_disable                              0x2000     //Disables the power down lite feature of unused spare lanes (generally should match tx_pdwn_lite_disable)
#define     rx_pdwn_lite_disable_clear                        0xDFFF     // Clear mask
#define     rx_use_sls_as_spr                                 0x1000     //Determines whether the RX SLS lane can be used as a spare lane on the bus to repair bad lanes (NOTE: if yes, recal is disabled once the SLS lane has been used as a spare lane.)
#define     rx_use_sls_as_spr_clear                           0xEFFF     // Clear mask

// rx_bus_repair_pg Register field name                                 data value   Description
#define     rx_bus_repair_count                               0x0000     //TBD
#define     rx_bus_repair_count_clear                         0x3FFF     // Clear mask
#define     rx_bus_repair_pos_0                               0x0000     //TBD
#define     rx_bus_repair_pos_0_clear                         0xC07F     // Clear mask
#define     rx_bus_repair_pos_1                               0x0000     //TBD
#define     rx_bus_repair_pos_1_clear                         0x3F80     // Clear mask

// rx_grp_repair_vec_0_15_pg Register field name                        data value   Description
#define     rx_grp_repair_vec_0_15                            0x0000     //TBD
#define     rx_grp_repair_vec_0_15_clear                      0x0000     // Clear mask

// rx_grp_repair_vec_16_31_pg Register field name                       data value   Description
#define     rx_grp_repair_vec_16_31                           0x0000     //TBD
#define     rx_grp_repair_vec_16_31_clear                     0x0000     // Clear mask

// rx_stop_addr_lsb_pg Register field name                              data value   Description
#define     rx_stop_addr_lsb                                  0x0000     //Stop address least-significant 16 bits 4 to 19 
#define     rx_stop_addr_lsb_clear                            0x0000     // Clear mask

// rx_stop_mask_lsb_pg Register field name                              data value   Description
#define     rx_stop_mask_lsb                                  0x0000     //Stop mask    least-significant 16 bits 4 to 19
#define     rx_stop_mask_lsb_clear                            0x0000     // Clear mask

// rx_reset_act_pg Register field name                                  data value   Description
#define     rx_reset_cfg_ena                                  0x8000     //Enable Configurable Group Reset
#define     rx_reset_cfg_ena_clear                            0x7FFF     // Clear mask
#define     rx_clr_par_errs                                   0x0002     //Clear All RX Parity Error Latches
#define     rx_clr_par_errs_clear                             0xFFFD     // Clear mask
#define     rx_fir_reset                                      0x0001     //FIR Reset
#define     rx_fir_reset_clear                                0xFFFE     // Clear mask

// rx_id1_pg Register field name                                        data value   Description
#define     rx_bus_id                                         0x0000     //This field is used to programmably set the bus number that a clkgrp belongs to.
#define     rx_bus_id_clear                                   0x03FF     // Clear mask
#define     rx_group_id                                       0x0000     //This field is used to programmably set the clock group number within a bus.
#define     rx_group_id_clear                                 0xFE07     // Clear mask

// rx_id2_pg Register field name                                        data value   Description
#define     rx_last_group_id                                  0x0000     //This field is used to programmably set the last clock group number within a bus.
#define     rx_last_group_id_clear                            0x03FF     // Clear mask

// rx_id3_pg Register field name                                        data value   Description
#define     rx_start_lane_id                                  0x0000     //This field is used to programmably set the first lane position in the group but relative to the bus.
#define     rx_start_lane_id_clear                            0x80FF     // Clear mask
#define     rx_end_lane_id                                    0x0000     //This field is used to programmably set the last lane position in the group but relative to the bus.
#define     rx_end_lane_id_clear                              0x7F80     // Clear mask

// rx_minikerf_pg Register field name                                   data value   Description
#define     rx_minikerf                                       0x0000     //Used to configure the rx Minikerf for analog characterization.
#define     rx_minikerf_clear                                 0x0000     // Clear mask

// rx_sls_mode_pg Register field name                                   data value   Description
#define     rx_sls_disable                                    0x8000     //Disables receiving & decoding of SLS commands
#define     rx_sls_disable_clear                              0x7FFF     // Clear mask
#define     tx_sls_disable                                    0x4000     //Disables the sending of SLS commands
#define     tx_sls_disable_clear                              0xBFFF     // Clear mask
#define     rx_sls_cntr_tap_pts_tap2                          0x1000     //How Long the SLS RX Command Needs to be Stable for.  EDI - 32 c8 clks; EI4 - 64 c4 clks
#define     rx_sls_cntr_tap_pts_tap3                          0x2000     //How Long the SLS RX Command Needs to be Stable for.  EDI - 64 c8 clks; EI4 - 128 c4 clks
#define     rx_sls_cntr_tap_pts_tap4                          0x3000     //How Long the SLS RX Command Needs to be Stable for.  EDI - 128 c8 clks; EI4 - 256 c4 clks
#define     rx_sls_cntr_tap_pts_clear                         0xCFFF     // Clear mask
#define     rx_nonsls_cntr_tap_pts_tap2                       0x0400     //How Long a Non-SLS RX Command Needs to be Stable for (to know we have switched from an SLS command to data).  EDI - 64 c8 clks; EI4 - 128 c4 clks
#define     rx_nonsls_cntr_tap_pts_tap3                       0x0800     //How Long a Non-SLS RX Command Needs to be Stable for (to know we have switched from an SLS command to data).  EDI - 128 c8 clks; EI4 - 256 c4 clks
#define     rx_nonsls_cntr_tap_pts_tap4                       0x0C00     //How Long a Non-SLS RX Command Needs to be Stable for (to know we have switched from an SLS command to data).  EDI - 256 c8 clks; EI4 - 512 c4 clks
#define     rx_nonsls_cntr_tap_pts_clear                      0xF3FF     // Clear mask
#define     rx_sls_err_chk_run                                0x0200     //Run SLS error check counter
#define     rx_sls_err_chk_run_clear                          0xFDFF     // Clear mask

// rx_training_start_pg Register field name                             data value   Description
#define     rx_start_wiretest                                 0x8000     //When this register is written to a 1 the training state machine will run the wiretest portion of the training states.
#define     rx_start_wiretest_clear                           0x7FFF     // Clear mask
#define     rx_start_deskew                                   0x4000     //When this register is written to a 1 the training state machine will run the deskew portion of the training states.
#define     rx_start_deskew_clear                             0xBFFF     // Clear mask
#define     rx_start_eye_opt                                  0x2000     //When this register is written to a 1 the training state machine will run the data eye optimization portion of the training states.
#define     rx_start_eye_opt_clear                            0xDFFF     // Clear mask
#define     rx_start_repair                                   0x1000     //When this register is written to a 1 the training state machine will run the static lane repair portion of the training states.
#define     rx_start_repair_clear                             0xEFFF     // Clear mask
#define     rx_start_func_mode                                0x0800     //When this register is written to a 1 the training state machine will run the transition to functional data portion of the training states.
#define     rx_start_func_mode_clear                          0xF7FF     // Clear mask
#define     rx_start_bist                                     0x0400     //Run initializations for BIST before enabling the BIST state machine. 
#define     rx_start_bist_clear                               0xFBFF     // Clear mask
#define     rx_start_offset_cal                               0x0200     //Run offset cal. 
#define     rx_start_offset_cal_clear                         0xFDFF     // Clear mask
#define     rx_start_wt_bypass                                0x0100     //Run wiretest bypass. 
#define     rx_start_wt_bypass_clear                          0xFEFF     // Clear mask

// rx_training_status_pg Register field name                            data value   Description
#define     rx_wiretest_done                                  0x8000     //When this bit is read as a 1, the wiretest training state has completed. Check the corresponding rx_ts_*_failed register field for the pass/fail status of this training state.
#define     rx_wiretest_done_clear                            0x7FFF     // Clear mask
#define     rx_deskew_done                                    0x4000     //When this bit is read as a 1, the deskew training state has completed. Check the corresponding rx_ts_*_failed register field for the pass/fail status of this training state.
#define     rx_deskew_done_clear                              0xBFFF     // Clear mask
#define     rx_eye_opt_done                                   0x2000     //When this bit is read as a 1, the eye optimization training state has completed. Check the corresponding rx_ts_*_failed register field for the pass/fail status of this training state.
#define     rx_eye_opt_done_clear                             0xDFFF     // Clear mask
#define     rx_repair_done                                    0x1000     //When this bit is read as a 1, the static lane repair training state has completed. Check the corresponding rx_ts_*_failed register field for the pass/fail status of this training state.
#define     rx_repair_done_clear                              0xEFFF     // Clear mask
#define     rx_func_mode_done                                 0x0800     //When this bit is read as a 1, the transition to functional data training state has completed. Check the corresponding rx_ts_*_failed register field for the pass/fail status of this training state.
#define     rx_func_mode_done_clear                           0xF7FF     // Clear mask
#define     rx_bist_started                                   0x0400     //When this bit is read as a 1, the RX BIST initialization has finished and RX BIST has started running. 
#define     rx_bist_started_clear                             0xFBFF     // Clear mask
#define     rx_offset_cal_done                                0x0200     //When this bit is read as a 1, offset cal has completed. 
#define     rx_offset_cal_done_clear                          0xFDFF     // Clear mask
#define     rx_wt_bypass_done                                 0x0100     //When this bit is read as a 1, wiretest bypass has completed. 
#define     rx_wt_bypass_done_clear                           0xFEFF     // Clear mask
#define     rx_wiretest_failed                                0x0080     //When this bit is read as a 1, the wiretest training state encountered an error.
#define     rx_wiretest_failed_clear                          0xFF7F     // Clear mask
#define     rx_deskew_failed                                  0x0040     //When this bit is read as a 1, the deskew training state encountered an error.
#define     rx_deskew_failed_clear                            0xFFBF     // Clear mask
#define     rx_eye_opt_failed                                 0x0020     //When this bit is read as a 1, the eye optimization training state encountered an error.
#define     rx_eye_opt_failed_clear                           0xFFDF     // Clear mask
#define     rx_repair_failed                                  0x0010     //When this bit is read as a 1, the static lane repair training state encountered an error.
#define     rx_repair_failed_clear                            0xFFEF     // Clear mask
#define     rx_func_mode_failed                               0x0008     //When this bit is read as a 1, the transition to functional data training state encountered an error.
#define     rx_func_mode_failed_clear                         0xFFF7     // Clear mask
#define     rx_start_bist_failed                              0x0004     //When this bit is read as a 1, the RX BIST initialization has encountered and error. 
#define     rx_start_bist_failed_clear                        0xFFFB     // Clear mask
#define     rx_offset_cal_failed                              0x0002     //When this bit is read as a 1, offset cal has encountered an error. 
#define     rx_offset_cal_failed_clear                        0xFFFD     // Clear mask
#define     rx_wt_bypass_failed                               0x0001     //When this bit is read as a 1, wiretest bypass has encountered an error. 
#define     rx_wt_bypass_failed_clear                         0xFFFE     // Clear mask

// rx_recal_status_pg Register field name                               data value   Description
#define     rx_recal_status                                   0x0000     //RX Recalibration Status
#define     rx_recal_status_clear                             0x0000     // Clear mask

// rx_timeout_sel_pg Register field name                                data value   Description
#define     rx_sls_timeout_sel_tap1                           0x2000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  54.6us 
#define     rx_sls_timeout_sel_tap2                           0x4000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  109.2us 
#define     rx_sls_timeout_sel_tap3                           0x6000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  218.4us 
#define     rx_sls_timeout_sel_tap4                           0x8000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  436.7us 
#define     rx_sls_timeout_sel_tap5                           0xA000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  873.5us 
#define     rx_sls_timeout_sel_tap6                           0xC000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  28.0ms 
#define     rx_sls_timeout_sel_tap7                           0xE000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  infinite
#define     rx_sls_timeout_sel_clear                          0x1FFF     // Clear mask
#define     rx_ds_bl_timeout_sel_tap1                         0x0400     //Selects Deskew Block Lock Timeout value.   128k UI or 13.6us 
#define     rx_ds_bl_timeout_sel_tap2                         0x0800     //Selects Deskew Block Lock Timeout value.   256k UI or 27.3us 
#define     rx_ds_bl_timeout_sel_tap3                         0x0C00     //Selects Deskew Block Lock Timeout value.   1M UI or 109.2us 
#define     rx_ds_bl_timeout_sel_tap4                         0x1000     //Selects Deskew Block Lock Timeout value.   2M UI or 218.5us 
#define     rx_ds_bl_timeout_sel_tap5                         0x1400     //Selects Deskew Block Lock Timeout value.   4M UI or 436.9us 
#define     rx_ds_bl_timeout_sel_tap6                         0x1800     //Selects Deskew Block Lock Timeout value.   8M UI or 873.8us 
#define     rx_ds_bl_timeout_sel_tap7                         0x1C00     //Selects Deskew Block Lock Timeout value.   infinite
#define     rx_ds_bl_timeout_sel_clear                        0xE3FF     // Clear mask
#define     rx_cl_timeout_sel_tap1                            0x0080     //Selects Clock Lock Timeout value.   128k UI or 13.6us 
#define     rx_cl_timeout_sel_tap2                            0x0100     //Selects Clock Lock Timeout value.   256k UI or 27.3us 
#define     rx_cl_timeout_sel_tap3                            0x0180     //Selects Clock Lock Timeout value.   1M UI or 109.2us 
#define     rx_cl_timeout_sel_tap4                            0x0200     //Selects Clock Lock Timeout value.   2M UI or 218.5us 
#define     rx_cl_timeout_sel_tap5                            0x0280     //Selects Clock Lock Timeout value.   4M UI or 436.9us 
#define     rx_cl_timeout_sel_tap6                            0x0300     //Selects Clock Lock Timeout value.   8M UI or 873.8us 
#define     rx_cl_timeout_sel_tap7                            0x0380     //Selects Clock Lock Timeout value.   infinite
#define     rx_cl_timeout_sel_clear                           0xFC7F     // Clear mask
#define     rx_wt_timeout_sel_tap1                            0x0010     //Selects Wiretest Timeout value.   128k UI or 13.6us 
#define     rx_wt_timeout_sel_tap2                            0x0020     //Selects Wiretest Timeout value.   256k UI or 27.3us 
#define     rx_wt_timeout_sel_tap3                            0x0030     //Selects Wiretest Timeout value.   1M UI or 109.2us 
#define     rx_wt_timeout_sel_tap4                            0x0040     //Selects Wiretest Timeout value.   2M UI or 218.5us 
#define     rx_wt_timeout_sel_tap5                            0x0050     //Selects Wiretest Timeout value.   4M UI or 436.9us 
#define     rx_wt_timeout_sel_tap6                            0x0060     //Selects Wiretest Timeout value.   8M UI or 873.8us 
#define     rx_wt_timeout_sel_tap7                            0x0070     //Selects Wiretest Timeout value.   infinite
#define     rx_wt_timeout_sel_clear                           0xC78F     // Clear mask
#define     rx_ds_timeout_sel_tap1                            0x0002     //Selects Deskew  Timeout value.   128k UI or 13.6us 
#define     rx_ds_timeout_sel_tap2                            0x0004     //Selects Deskew  Timeout value.   256k UI or 27.3us 
#define     rx_ds_timeout_sel_tap3                            0x0006     //Selects Deskew  Timeout value.   1M UI or 109.2us 
#define     rx_ds_timeout_sel_tap4                            0x0008     //Selects Deskew  Timeout value.   2M UI or 218.5us 
#define     rx_ds_timeout_sel_tap5                            0x000A     //Selects Deskew  Timeout value.   4M UI or 436.9us 
#define     rx_ds_timeout_sel_tap6                            0x000C     //Selects Deskew  Timeout value.   8M UI or 873.8us 
#define     rx_ds_timeout_sel_tap7                            0x000E     //Selects Deskew  Timeout value.   infinite
#define     rx_ds_timeout_sel_clear                           0xFF11     // Clear mask

// rx_fifo_mode_pg Register field name                                  data value   Description
#define     rx_fifo_initial_l2u_dly                           0x0000     //RX FIFO Initial Load to Unload Delay. For setting X, the latency is 4*X to 4*X+4 UI.  Default is 16-20 UI.
#define     rx_fifo_initial_l2u_dly_clear                     0x0FFF     // Clear mask
#define     rx_fifo_final_l2u_dly                             0x0000     //RX FIFO Final Load to Unload Delay. For setting X, the latency is 4*X to 4*X+4 UI.  Default is 8-12 UI.
#define     rx_fifo_final_l2u_dly_clear                       0xF0FF     // Clear mask
#define     rx_fifo_max_deskew                                0x0000     //RX FIFO Max Deskew Control Value. TBD
#define     rx_fifo_max_deskew_clear                          0xFF0F     // Clear mask
#define     rx_fifo_final_l2u_min_err_thresh_tap1             0x0004     //RX FIFO error threshold used to qualify the minimum load to unload delay as bad, which is used as the point of reference for adjusting to the final load to unload delay. Note that the errors are accumulated across the entire clock group for a length of time selected by rx_eo_final_l2u_timeout_sel.   16 errors 
#define     rx_fifo_final_l2u_min_err_thresh_tap2             0x0008     //RX FIFO error threshold used to qualify the minimum load to unload delay as bad, which is used as the point of reference for adjusting to the final load to unload delay. Note that the errors are accumulated across the entire clock group for a length of time selected by rx_eo_final_l2u_timeout_sel.   128 errors 
#define     rx_fifo_final_l2u_min_err_thresh_tap3             0x000C     //RX FIFO error threshold used to qualify the minimum load to unload delay as bad, which is used as the point of reference for adjusting to the final load to unload delay. Note that the errors are accumulated across the entire clock group for a length of time selected by rx_eo_final_l2u_timeout_sel.   255 errors
#define     rx_fifo_final_l2u_min_err_thresh_clear            0xFF33     // Clear mask

// rx_sls_status_pg Register field name                                 data value   Description
#define     rx_sls_cmd_val                                    0x8000     //Current SLS Command Valid
#define     rx_sls_cmd_val_clear                              0x7FFF     // Clear mask
#define     rx_sls_cmd_encode_shadow_request                  0x0100     //Current SLS Command  Driven by the RX side to request shadowing of its receive lane from lane n-1 to lane n
#define     rx_sls_cmd_encode_shadow_done                     0x0200     //Current SLS Command  Driven by the RX side to signal now receiving lane n-1s data on lane n
#define     rx_sls_cmd_encode_shadow_repair_request           0x0300     //Current SLS Command  Driven by the RX side to request shadowing and repair of its receive lane from lane n-1 to n.
#define     rx_sls_cmd_encode_shadow_repair_done              0x0400     //Current SLS Command  Driven by the RX side to signal lane n-1 is repaired.
#define     rx_sls_cmd_encode_unshadow_request                0x0500     //Current SLS Command  Driven by the RX side to request shadowing of receive lane from lane n+1 to lane n.
#define     rx_sls_cmd_encode_unshadow_done                   0x0600     //Current SLS Command  Driven by the RX side to signal now receiving lane n+1 data on lane n
#define     rx_sls_cmd_encode_unshadow_repair_request         0x0700     //Current SLS Command  Driven by the RX side to request unshadowing and repair of its receive lane from lane n+1 to lane n.
#define     rx_sls_cmd_encode_unshadow_repair_done            0x0800     //Current SLS Command  Driven by the RX side to signal lane n+1 is repaired.
#define     rx_sls_cmd_encode_sls_exception                   0x0900     //Current SLS Command  Driven by the RX side to indicate to the other side of the bus its RX SLS lane is broken.
#define     rx_sls_cmd_encode_init_done                       0x0A00     //Current SLS Command  Driven to signal the CTLE/DFE/offset (re-
#define     rx_sls_cmd_encode_recal_request                   0x0B00     //Current SLS Command  Driven on recalibration lane x to request a recalibration of its receive recalibration lane y.
#define     rx_sls_cmd_encode_recal_running                   0x0C00     //Current SLS Command  Driven during the status reporting interval of recalibration to indicate recalibration has not completed
#define     rx_sls_cmd_encode_recal_done                      0x0D00     //Current SLS Command  Driven to indicate its recalibration is complete.
#define     rx_sls_cmd_encode_recal_failed                    0x0E00     //Current SLS Command  Driven to indicate recalibration has failed on its receive recalibration lane
#define     rx_sls_cmd_encode_recal_abort                     0x0F00     //Current SLS Command  Abort recalibration.
#define     rx_sls_cmd_encode_reserved2                       0x1000     //Current SLS Command  Reserved.010001
#define     rx_sls_cmd_encode_reserved4                       0x1200     //Current SLS Command  Reserved.
#define     rx_sls_cmd_encode_reserved5                       0x1300     //Current SLS Command  Reserved.
#define     rx_sls_cmd_encode_reserved6                       0x1400     //Current SLS Command  Reserved.
#define     rx_sls_cmd_encode_reserved7                       0x1500     //Current SLS Command  Reserved.
#define     rx_sls_cmd_encode_reserved8                       0x1600     //Current SLS Command  Reserved.
#define     rx_sls_cmd_encode_reserved9                       0x1700     //Current SLS Command  Reserved.
#define     rx_sls_cmd_encode_reserved10                      0x1800     //Current SLS Command  Reserved.
#define     rx_sls_cmd_encode_init_ack_done                   0x1900     //Current SLS Command  Driven in response to an init_done (not currently used
#define     rx_sls_cmd_encode_reserved11                      0x1A00     //Current SLS Command  Reserved.
#define     rx_sls_cmd_encode_recal_ack                       0x1B00     //Current SLS Command  Driven on recalibration lane y in response to a recal_request on its receive recalibration lane x
#define     rx_sls_cmd_encode_reserved12                      0x1C00     //Current SLS Command  Reserved.
#define     rx_sls_cmd_encode_reserved13                      0x1D00     //Current SLS Command  Reserved.
#define     rx_sls_cmd_encode_reserved14                      0x1E00     //Current SLS Command  Reserved.
#define     rx_sls_cmd_encode_recal_abort_ack                 0x1F00     //Current SLS Command  Abort recalibration acknowledge.
#define     rx_sls_cmd_encode_clear                           0xC0FF     // Clear mask
#define     rx_sls_err_chk_cnt                                0x0000     //Error count result for SLS error checking mode
#define     rx_sls_err_chk_cnt_clear                          0xFF00     // Clear mask

// rx_fir1_pg Register field name                                       data value   Description
#define     rx_pg_fir1_errs_par_err_rx_rpr_state              0x0800     //A Per-Group RXCTL Register or State Machine Parity Error has occurred. 
#define     rx_pg_fir1_errs_par_err_rx_eyeopt_state           0x0C00     //A Per-Group RXCTL Register or State Machine Parity Error has occurred. 
#define     rx_pg_fir1_errs_par_err_dsm_state                 0x0400     //A Per-Group RXCTL Register or State Machine Parity Error has occurred. 
#define     rx_pg_fir1_errs_par_err_rxdsm_state               0x0400     //A Per-Group RXCTL Register or State Machine Parity Error has occurred. 
#define     rx_pg_fir1_errs_clear                             0x0003     // Clear mask
#define     rx_pl_fir_err                                     0x0001     //Summary bit indicating an RX per-lane register or state machine parity error has occurred in one or more lanes. The rx_fir_pl register from each lane should be read to isolate to a particular piece of logic. There is no mechanism to determine which lane had the fault without reading FIR status from each lane.
#define     rx_pl_fir_err_clear                               0xFFFE     // Clear mask

// rx_fir2_pg Register field name                                       data value   Description
#define     rx_pg_fir2_errs_err_sls_hndshk_sm                 0x0200     //A Per-Group Register or State Machine Parity Error has occurred.  RXCTL SLS Handshake SM Parity Error.
#define     rx_pg_fir2_errs_clear                             0x01FF     // Clear mask

// rx_fir1_mask_pg Register field name                                  data value   Description
#define     rx_pg_fir1_errs_mask_clear                        0x0003     // Clear mask
#define     rx_pl_fir_err_mask                                0x0001     //FIR mask for the summary bit that indicates an RX register or state machine parity error has occurred. This mask bit is used to block ALL per-lane parity errors from causing a FIR error.
#define     rx_pl_fir_err_mask_clear                          0xFFFE     // Clear mask

// rx_fir2_mask_pg Register field name                                  data value   Description
#define     rx_pg_fir2_errs_mask_mask_sls_hndshk_sm           0x0200     //FIR mask for register or state machine parity checkers in per-group RX logic. A value of 1 masks the error from generating a FIR error.  RXCTL SLS Handshake SM Parity Error Mask.
#define     rx_pg_fir2_errs_mask_clear                        0x01FF     // Clear mask

// rx_fir1_error_inject_pg Register field name                          data value   Description
#define     rx_pg_fir1_err_inj_1                              0x4000     //RX Per-Group Parity Error Injection  Causes a parity flip in the specific parity checker.
#define     rx_pg_fir1_err_inj_inj_rpr_sm                     0x0800     //RX Per-Group Parity Error Injection  RXCTL Repair SM Parity Error Inject.
#define     rx_pg_fir1_err_inj_inj_eyeopt_sm                  0x0C00     //RX Per-Group Parity Error Injection  RXCTL Eyeopt SM Parity Error Inject.
#define     rx_pg_fir1_err_inj_inj_dsm_sm                     0x0400     //RX Per-Group Parity Error Injection  RXCTL Deskew SM Parity Error Inject.
#define     rx_pg_fir1_err_inj_inj_rxdsm_sm                   0x0400     //RX Per-Group Parity Error Injection  RXCTL RX Deskew SM Parity Error Inject.
#define     rx_pg_fir1_err_inj_clear                          0x0003     // Clear mask

// rx_fir2_error_inject_pg Register field name                          data value   Description
#define     rx_pg_fir2_err_inj_1                              0x2000     //RX Per-Group Parity Error Injection  Causes a parity flip in the specific parity checker.
#define     rx_pg_fir2_err_inj_inj_sls_hndshk_sm              0x0200     //RX Per-Group Parity Error Injection  RXCTL SLS Handshake SM Parity Error Inject.
#define     rx_pg_fir2_err_inj_clear                          0x01FF     // Clear mask

// rx_fir_training_pg Register field name                               data value   Description
#define     rx_pg_fir_training_error                          0x8000     //This field is now defunct and is permanently masked in the rx_fir_training_mask_pg FIR isolation register.
#define     rx_pg_fir_training_error_clear                    0x7FFF     // Clear mask
#define     rx_pg_fir_static_spare_deployed                   0x4000     //A spare lane has been deployed during training to heal a lane that was detected as bad. rx_Static_Spare_Deployed (SSD) will be set after the repair training step if during training either wiretest, deskew, eyeopt or repair has detected one or more bad lanes have been detected. The rx_bad_lane_enc_gcrmsg_pg register can be read to isolate which lane(s) were healed and the rx_bad_lane.
#define     rx_pg_fir_static_spare_deployed_clear             0xBFFF     // Clear mask
#define     rx_pg_fir_static_max_spares_exceeded              0x2000     //A lane has been detected as bad during training but there are no spare lanes available to heal it. THIS FIR WILL NOT BE SET UNTIL THE REPAIR TRAINING STEP HAS BEEN RUN. THIS IS A CATASTROPHIC FAILURE FOR THE BUS WHEN IN MISSION MODE BUT ALL TRAINING STEPS WILL STILL BE RUN ON WHATEVER GOOD LANES THERE ARE. rx_static_max_spares_exceeded will be set if wiretest, deskew, eyeopt or repair find the excessive number of bad lanes.
#define     rx_pg_fir_static_max_spares_exceeded_clear        0xDFFF     // Clear mask
#define     rx_pg_fir_dynamic_repair_error                    0x1000     //A Dynamic Repair error has occurred. The Recal Error FFDC registers should be read to help isolate to a particular piece of logic.
#define     rx_pg_fir_dynamic_repair_error_clear              0xEFFF     // Clear mask
#define     rx_pg_fir_dynamic_spare_deployed                  0x0800     //A spare lane has been deployed by ECC/CRC logic to heal a lane that was detected as bad. The rx_bad_lane_enc_gcrmsg_pg register can be read to isolate which lane(s) were healed.
#define     rx_pg_fir_dynamic_spare_deployed_clear            0xF7FF     // Clear mask
#define     rx_pg_fir_dynamic_max_spares_exceeded             0x0400     //A lane has been detected as bad by ECC/CRC logic but there are no spare lanes to heal it. THIS IS A CATASTROPHIC FAILURE FOR THE BUS.
#define     rx_pg_fir_dynamic_max_spares_exceeded_clear       0xFBFF     // Clear mask
#define     rx_pg_fir_recal_error                             0x0200     //A Recalibration Error has occurred. The Recal Error FFDC registers should be read to help isolate to a particular piece of logic.
#define     rx_pg_fir_recal_error_clear                       0xFDFF     // Clear mask
#define     rx_pg_fir_recal_spare_deployed                    0x0100     //A spare lane has been deployed during Recal to heal a lane that was detected as bad. The rx_bad_lane_enc_gcrmsg_pg register can be read to isolate which lane(s) were healed.
#define     rx_pg_fir_recal_spare_deployed_clear              0xFEFF     // Clear mask
#define     rx_pg_fir_recal_max_spares_exceeded               0x0080     //A lane has been detected as bad during Recal but there are no spare lanes to heal it. THIS IS A CATASTROPHIC FAILURE FOR THE BUS.
#define     rx_pg_fir_recal_max_spares_exceeded_clear         0xFF7F     // Clear mask
#define     rx_pg_fir_too_many_bus_errors                     0x0040     //More than one lane has been detected as having too many errors during functional operation. THIS IS A CATASTROPHIC FAILURE FOR THE BUS.
#define     rx_pg_fir_too_many_bus_errors_clear               0xFFBF     // Clear mask

// rx_fir_training_mask_pg Register field name                          data value   Description
#define     rx_pg_fir_training_error_mask                     0x8000     //FIR mask for rx_pg_fir_training_error.
#define     rx_pg_fir_training_error_mask_clear               0x7FFF     // Clear mask
#define     rx_pg_fir_static_spare_deployed_mask              0x4000     //FIR mask for rx_pg_fir_static_spare_deployed.
#define     rx_pg_fir_static_spare_deployed_mask_clear        0xBFFF     // Clear mask
#define     rx_pg_fir_static_max_spares_exceeded_mask         0x2000     //FIR mask for rx_pg_fir_static_max_spares_exceeded
#define     rx_pg_fir_static_max_spares_exceeded_mask_clear   0xDFFF     // Clear mask
#define     rx_pg_fir_dynamic_repair_error_mask               0x1000     //FIR mask for rx_pg_fir_dynamic_repair_error
#define     rx_pg_fir_dynamic_repair_error_mask_clear         0xEFFF     // Clear mask
#define     rx_pg_fir_dynamic_spare_deployed_mask             0x0800     //FIR mask for rx_pg_fir_dynamic_spare_deployed.
#define     rx_pg_fir_dynamic_spare_deployed_mask_clear       0xF7FF     // Clear mask
#define     rx_pg_fir_dynamic_max_spares_exceeded_mask        0x0400     //FIR mask for rx_pg_fir_dynamic_max_spares_exceeded.
#define     rx_pg_fir_dynamic_max_spares_exceeded_mask_clear  0xFBFF     // Clear mask
#define     rx_pg_fir_recal_error_mask                        0x0200     //FIR mask for rx_pg_fir_recal_error.
#define     rx_pg_fir_recal_error_mask_clear                  0xFDFF     // Clear mask
#define     rx_pg_fir_recal_spare_deployed_mask               0x0100     //FIR mask for rx_pg_fir_recal_spare_deployed.
#define     rx_pg_fir_recal_spare_deployed_mask_clear         0xFEFF     // Clear mask
#define     rx_pg_fir_recal_max_spares_exceeded_mask          0x0080     //FIR mask for rx_pg_fir_recal_max_spares_exceeded.
#define     rx_pg_fir_recal_max_spares_exceeded_mask_clear    0xFF7F     // Clear mask
#define     rx_pg_fir_too_many_bus_errors_mask                0x0040     //FIR mask for rx_pg_fir_too_many_bus_errors.
#define     rx_pg_fir_too_many_bus_errors_mask_clear          0xFFBF     // Clear mask

// rx_timeout_sel1_pg Register field name                               data value   Description
#define     rx_eo_offset_timeout_sel_tap1                     0x2000     //Selects Latch offset timeout.   128k UI or 13.6us 
#define     rx_eo_offset_timeout_sel_tap2                     0x4000     //Selects Latch offset timeout.   256k UI or 27.3us 
#define     rx_eo_offset_timeout_sel_tap3                     0x6000     //Selects Latch offset timeout.   1M UI or 109.2us 
#define     rx_eo_offset_timeout_sel_tap4                     0x8000     //Selects Latch offset timeout.   2M UI or 218.5us 
#define     rx_eo_offset_timeout_sel_tap5                     0xA000     //Selects Latch offset timeout.   4M UI or 436.9us 
#define     rx_eo_offset_timeout_sel_tap6                     0xC000     //Selects Latch offset timeout.   8M UI or 873.8us 
#define     rx_eo_offset_timeout_sel_tap7                     0xE000     //Selects Latch offset timeout.   infinite
#define     rx_eo_offset_timeout_sel_clear                    0x1FFF     // Clear mask
#define     rx_eo_amp_timeout_sel_tap1                        0x0400     //Selects  Amplitude measurement watchdog timeout.   128k UI or 13.6us 
#define     rx_eo_amp_timeout_sel_tap2                        0x0800     //Selects  Amplitude measurement watchdog timeout.   256k UI or 27.3us 
#define     rx_eo_amp_timeout_sel_tap3                        0x0C00     //Selects  Amplitude measurement watchdog timeout.   1M UI or 109.2us 
#define     rx_eo_amp_timeout_sel_tap4                        0x1000     //Selects  Amplitude measurement watchdog timeout.   2M UI or 218.5us 
#define     rx_eo_amp_timeout_sel_tap5                        0x1400     //Selects  Amplitude measurement watchdog timeout.   4M UI or 436.9us 
#define     rx_eo_amp_timeout_sel_tap6                        0x1800     //Selects  Amplitude measurement watchdog timeout.   8M UI or 873.8us 
#define     rx_eo_amp_timeout_sel_tap7                        0x1C00     //Selects  Amplitude measurement watchdog timeout.   infinite
#define     rx_eo_amp_timeout_sel_clear                       0xE3FF     // Clear mask
#define     rx_eo_ctle_timeout_sel_tap1                       0x0080     //Selects  CTLE ajdust watchdog timeout.   128k UI or 13.6us 
#define     rx_eo_ctle_timeout_sel_tap2                       0x0100     //Selects  CTLE ajdust watchdog timeout.   256k UI or 27.3us 
#define     rx_eo_ctle_timeout_sel_tap3                       0x0180     //Selects  CTLE ajdust watchdog timeout.   1M UI or 109.2us 
#define     rx_eo_ctle_timeout_sel_tap4                       0x0200     //Selects  CTLE ajdust watchdog timeout.   2M UI or 218.5us 
#define     rx_eo_ctle_timeout_sel_tap5                       0x0280     //Selects  CTLE ajdust watchdog timeout.   4M UI or 436.9us 
#define     rx_eo_ctle_timeout_sel_tap6                       0x0300     //Selects  CTLE ajdust watchdog timeout.   8M UI or 873.8us 
#define     rx_eo_ctle_timeout_sel_tap7                       0x0380     //Selects  CTLE ajdust watchdog timeout.   infinite
#define     rx_eo_ctle_timeout_sel_clear                      0xFC7F     // Clear mask
#define     rx_eo_h1ap_timeout_sel_tap1                       0x0010     //Selects  H1Ap ajdust watchdog timeout.   128k UI or 13.6us 
#define     rx_eo_h1ap_timeout_sel_tap2                       0x0020     //Selects  H1Ap ajdust watchdog timeout.   256k UI or 27.3us 
#define     rx_eo_h1ap_timeout_sel_tap3                       0x0030     //Selects  H1Ap ajdust watchdog timeout.   1M UI or 109.2us 
#define     rx_eo_h1ap_timeout_sel_tap4                       0x0040     //Selects  H1Ap ajdust watchdog timeout.   2M UI or 218.5us 
#define     rx_eo_h1ap_timeout_sel_tap5                       0x0050     //Selects  H1Ap ajdust watchdog timeout.   4M UI or 436.9us 
#define     rx_eo_h1ap_timeout_sel_tap6                       0x0060     //Selects  H1Ap ajdust watchdog timeout.   8M UI or 873.8us 
#define     rx_eo_h1ap_timeout_sel_tap7                       0x0070     //Selects  H1Ap ajdust watchdog timeout.   infinite
#define     rx_eo_h1ap_timeout_sel_clear                      0xC78F     // Clear mask
#define     rx_eo_ddc_timeout_sel_tap1                        0x0002     //Selects  DDC watchdog timeout (EDI ONLY).   128k UI or 13.6us 
#define     rx_eo_ddc_timeout_sel_tap2                        0x0004     //Selects  DDC watchdog timeout (EDI ONLY).   256k UI or 27.3us 
#define     rx_eo_ddc_timeout_sel_tap3                        0x0006     //Selects  DDC watchdog timeout (EDI ONLY).   1M UI or 109.2us 
#define     rx_eo_ddc_timeout_sel_tap4                        0x0008     //Selects  DDC watchdog timeout (EDI ONLY).   2M UI or 218.5us 
#define     rx_eo_ddc_timeout_sel_tap5                        0x000A     //Selects  DDC watchdog timeout (EDI ONLY).   4M UI or 436.9us 
#define     rx_eo_ddc_timeout_sel_tap6                        0x000C     //Selects  DDC watchdog timeout (EDI ONLY).   8M UI or 873.8us 
#define     rx_eo_ddc_timeout_sel_tap7                        0x000E     //Selects  DDC watchdog timeout (EDI ONLY).   infinite
#define     rx_eo_ddc_timeout_sel_clear                       0xFF11     // Clear mask
#define     rx_eo_final_l2u_timeout_sel                       0x0001     //Selects Final Load to Unload Delay qualification time per step. 
#define     rx_eo_final_l2u_timeout_sel_clear                 0xFFFE     // Clear mask

// rx_lane_bad_vec_0_15_pg Register field name                          data value   Description
#define     rx_lane_bad_vec_0_15_clear                        0x0000     // Clear mask

// rx_lane_bad_vec_16_31_pg Register field name                         data value   Description
#define     rx_lane_bad_vec_16_31                             0x0000     //Lanes found bad by HW (status) or method to force lane bad from software (control).
#define     rx_lane_bad_vec_16_31_clear                       0x0000     // Clear mask

// rx_lane_disabled_vec_0_15_pg Register field name                     data value   Description
#define     rx_lane_disabled_vec_0_15                         0x0000     //Lanes disabled by HW (status) or method to force lane to be disabled (save power) from software (control).
#define     rx_lane_disabled_vec_0_15_clear                   0x0000     // Clear mask

// rx_lane_disabled_vec_16_31_pg Register field name                    data value   Description
#define     rx_lane_disabled_vec_16_31                        0x0000     //Lanes disabled by HW (status) or method to force lane to be disabled (save power) from software (control).
#define     rx_lane_disabled_vec_16_31_clear                  0x0000     // Clear mask

// rx_lane_swapped_vec_0_15_pg Register field name                      data value   Description
#define     rx_lane_swapped_vec_0_15                          0x0000     //Wiretest found that the P & N wire legs have been swapped on the lane indicated. Has the effect of basically inverting the signal.  Note that this status is invalid if the lane is marked bad.
#define     rx_lane_swapped_vec_0_15_clear                    0x0000     // Clear mask

// rx_lane_swapped_vec_16_31_pg Register field name                     data value   Description
#define     rx_lane_swapped_vec_16_31                         0x0000     //Wiretest found that the P & N wire legs have been swapped on the lane indicated. Has the effect of basically inverting the signal.  Note that this status is invalid if the lane is marked bad.
#define     rx_lane_swapped_vec_16_31_clear                   0x0000     // Clear mask

// rx_init_state_pg Register field name                                 data value   Description
#define     rx_main_init_state_1                              0x1000     //Main Initialization State Machine(RJR):  Wiretest Running
#define     rx_main_init_state_2                              0x2000     //Main Initialization State Machine(RJR):  Deskew Running
#define     rx_main_init_state_3                              0x3000     //Main Initialization State Machine(RJR):  Eye Optimization Running
#define     rx_main_init_state_4                              0x4000     //Main Initialization State Machine(RJR):  Repair Running
#define     rx_main_init_state_5                              0x5000     //Main Initialization State Machine(RJR):  Go Functional Running
#define     rx_main_init_state_6                              0x9000     //Main Initialization State Machine(RJR):  Wiretest Failed
#define     rx_main_init_state_7                              0x5000     //Main Initialization State Machine(RJR):  Deskew Failed
#define     rx_main_init_state_8                              0xB000     //Main Initialization State Machine(RJR):  Eye Optimization Failed
#define     rx_main_init_state_9                              0xC000     //Main Initialization State Machine(RJR):  Repair Failed
#define     rx_main_init_state_10                             0xD000     //Main Initialization State Machine(RJR):  Go Functional Failed
#define     rx_main_init_state_clear                          0x0FFF     // Clear mask

// rx_wiretest_state_pg Register field name                             data value   Description
#define     rx_wtm_state_clear                                0x07FF     // Clear mask
#define     rx_wtr_state_clear                                0xF87F     // Clear mask
#define     rx_wtl_state_clear                                0x0FE0     // Clear mask

// rx_wiretest_laneinfo_pg Register field name                          data value   Description
#define     rx_wtr_cur_lane                                   0x0000     //Wiretest Current Lane Under Test(RJR)
#define     rx_wtr_cur_lane_clear                             0x07FF     // Clear mask
#define     rx_wtr_max_bad_lanes_clear                        0xF83F     // Clear mask
#define     rx_wtr_bad_lane_count                             0x0000     //Wiretest Current Number Of Bad Lanes in This Clk Group(RJR)
#define     rx_wtr_bad_lane_count_clear                       0x07E0     // Clear mask

// rx_wiretest_gcrmsgs_pg Register field name                           data value   Description
#define     rx_wt_prev_done_gcrmsg                            0x8000     //GCR Message: Previous Clk Group Has Completed Wiretest
#define     rx_wt_prev_done_gcrmsg_clear                      0x7FFF     // Clear mask
#define     rx_wt_all_done_gcrmsg                             0x4000     //GCR Message: All Clk Groups Have Completed Wiretest
#define     rx_wt_all_done_gcrmsg_clear                       0xBFFF     // Clear mask

// rx_deskew_gcrmsgs_pg Register field name                             data value   Description
#define     rx_deskew_seq_gcrmsg_dsalldeskewed                0x2000     //GCR Message: RX Deskew Sequencer GCR messages  Indicate all groups deskewed.
#define     rx_deskew_seq_gcrmsg_dsprevdone                   0x4000     //GCR Message: RX Deskew Sequencer GCR messages  Indicate prior group completed deskew.
#define     rx_deskew_seq_gcrmsg_dsalldone                    0x6000     //GCR Message: RX Deskew Sequencer GCR messages  Indicate all groups completed deskew.
#define     rx_deskew_seq_gcrmsg_dsprevskew                   0x8000     //GCR Message: RX Deskew Sequencer GCR messages  Transmit skew values from prior group.
#define     rx_deskew_seq_gcrmsg_dsmaxskew                    0xA000     //GCR Message: RX Deskew Sequencer GCR messages  Transmit max skew values to all groups.
#define     rx_deskew_seq_gcrmsg_unused                       0xC000     //GCR Message: RX Deskew Sequencer GCR messages  Unused.
#define     rx_deskew_seq_gcrmsg_dsnomsg                      0xE000     //GCR Message: RX Deskew Sequencer GCR messages  No message.
#define     rx_deskew_seq_gcrmsg_clear                        0x1FFF     // Clear mask
#define     rx_deskew_skmin_gcrmsg                            0x0000     //GCR Message: Min Skew Value for deskew sequence.
#define     rx_deskew_skmin_gcrmsg_clear                      0xF03F     // Clear mask
#define     rx_deskew_skmax_gcrmsg                            0x0000     //GCR Message: Max Skew Value for deskew sequence.
#define     rx_deskew_skmax_gcrmsg_clear                      0x0FC0     // Clear mask

// rx_deskew_state_pg Register field name                               data value   Description
#define     rx_dsm_state_clear                                0x00FF     // Clear mask
#define     rx_rxdsm_state_clear                              0x7F80     // Clear mask

// rx_deskew_mode_pg Register field name                                data value   Description
#define     rx_deskew_max_limit                               0x0000     //Maximum Deskewable Skew Fail Threshold
#define     rx_deskew_max_limit_clear                         0x03FF     // Clear mask

// rx_deskew_status_pg Register field name                              data value   Description
#define     rx_deskew_minskew_grp                             0x0000     //Deskew Per-Group Raw Skew Min
#define     rx_deskew_minskew_grp_clear                       0x03FF     // Clear mask
#define     rx_deskew_maxskew_grp                             0x0000     //Deskew Per-Group Raw Skew Max
#define     rx_deskew_maxskew_grp_clear                       0xFC0F     // Clear mask

// rx_bad_lane_enc_gcrmsg_pg Register field name                        data value   Description
#define     rx_bad_lane1_gcrmsg                               0x0000     //GCR Message: Encoded bad lane one in relation to the entire RX bus
#define     rx_bad_lane1_gcrmsg_clear                         0x01FF     // Clear mask
#define     rx_bad_lane2_gcrmsg                               0x0000     //GCR Message: Encoded bad lane two in relation to the entire RX bus
#define     rx_bad_lane2_gcrmsg_clear                         0xFE03     // Clear mask
#define     rx_bad_lane_code_gcrmsg_bad_ln1_val               0x0001     //GCR Message: RX Bad Lane Code  Bad Lane 1 Valid
#define     rx_bad_lane_code_gcrmsg_bad_lns12_val             0x0002     //GCR Message: RX Bad Lane Code  Bad Lanes 1 and 2 Valid
#define     rx_bad_lane_code_gcrmsg_3plus_bad_lns             0x0003     //GCR Message: RX Bad Lane Code  3+ bad lanes
#define     rx_bad_lane_code_gcrmsg_clear                     0xFFF0     // Clear mask

// rx_static_repair_state_pg Register field name                        data value   Description
#define     rx_rpr_state_clear                                0x03FF     // Clear mask

// rx_tx_bus_info_pg Register field name                                data value   Description
#define     rx_tx_bus_width                                   0x0000     //TX Bus Width
#define     rx_tx_bus_width_clear                             0x01FF     // Clear mask
#define     rx_rx_bus_width                                   0x0000     //RX Bus Width
#define     rx_rx_bus_width_clear                             0xFE03     // Clear mask

// rx_sls_lane_enc_gcrmsg_pg Register field name                        data value   Description
#define     rx_sls_lane_gcrmsg                                0x0000     //GCR Message: Encoded SLS lane in relation to the entire RX bus
#define     rx_sls_lane_gcrmsg_clear                          0x01FF     // Clear mask
#define     rx_sls_lane_val_gcrmsg                            0x0100     //GCR Message: RX SLS Lane Valid
#define     rx_sls_lane_val_gcrmsg_clear                      0xFEFF     // Clear mask

// rx_fence_pg Register field name                                      data value   Description
#define     rx_fence                                          0x8000     //RX fence bit
#define     rx_fence_clear                                    0x7FFF     // Clear mask

// rx_timeout_sel2_pg Register field name                               data value   Description
#define     rx_func_mode_timeout_sel_tap1                     0x2000     //Selects Functional Mode wait timeout. Note that his should be longer than rx_sls_timeout_sel.   128k UI or 13.7us 
#define     rx_func_mode_timeout_sel_tap2                     0x4000     //Selects Functional Mode wait timeout. Note that his should be longer than rx_sls_timeout_sel.   256k UI or 27.3us 
#define     rx_func_mode_timeout_sel_tap3                     0x6000     //Selects Functional Mode wait timeout. Note that his should be longer than rx_sls_timeout_sel.   512k UI or 54.6us 
#define     rx_func_mode_timeout_sel_tap4                     0x8000     //Selects Functional Mode wait timeout. Note that his should be longer than rx_sls_timeout_sel.   1M UI or 109.2us 
#define     rx_func_mode_timeout_sel_tap5                     0xA000     //Selects Functional Mode wait timeout. Note that his should be longer than rx_sls_timeout_sel.   2M UI or 218.5us 
#define     rx_func_mode_timeout_sel_tap6                     0xC000     //Selects Functional Mode wait timeout. Note that his should be longer than rx_sls_timeout_sel.   64M UI or 7ms
#define     rx_func_mode_timeout_sel_tap7                     0xE000     //Selects Functional Mode wait timeout. Note that his should be longer than rx_sls_timeout_sel.   infinite
#define     rx_func_mode_timeout_sel_clear                    0x1FFF     // Clear mask
#define     rx_rc_slowdown_timeout_sel_tap1                   0x0400     //Selects Recal  Slowdown      timeout. Note that his should be longer than rx_sls_timeout_sel.   128k UI or 13.7us 
#define     rx_rc_slowdown_timeout_sel_tap2                   0x0800     //Selects Recal  Slowdown      timeout. Note that his should be longer than rx_sls_timeout_sel.   256k UI or 27.3us 
#define     rx_rc_slowdown_timeout_sel_tap3                   0x0C00     //Selects Recal  Slowdown      timeout. Note that his should be longer than rx_sls_timeout_sel.   512k UI or 54.6us 
#define     rx_rc_slowdown_timeout_sel_tap4                   0x1000     //Selects Recal  Slowdown      timeout. Note that his should be longer than rx_sls_timeout_sel.   1M UI or 109.2us 
#define     rx_rc_slowdown_timeout_sel_tap5                   0x1400     //Selects Recal  Slowdown      timeout. Note that his should be longer than rx_sls_timeout_sel.   2M UI or 218.5us 
#define     rx_rc_slowdown_timeout_sel_tap6                   0x1800     //Selects Recal  Slowdown      timeout. Note that his should be longer than rx_sls_timeout_sel.   64M UI or 7ms
#define     rx_rc_slowdown_timeout_sel_tap7                   0x1C00     //Selects Recal  Slowdown      timeout. Note that his should be longer than rx_sls_timeout_sel.   infinite
#define     rx_rc_slowdown_timeout_sel_clear                  0xE3FF     // Clear mask
#define     rx_pup_lite_wait_sel_tap1                         0x0100     //How long to wait for analog logic to power up an unused spare lane for recal/repair  107ns (default value
#define     rx_pup_lite_wait_sel_tap2                         0x0200     //How long to wait for analog logic to power up an unused spare lane for recal/repair  213ns
#define     rx_pup_lite_wait_sel_tap3                         0x0300     //How long to wait for analog logic to power up an unused spare lane for recal/repair  427ns
#define     rx_pup_lite_wait_sel_clear                        0xFCFF     // Clear mask

// rx_misc_analog_pg Register field name                                data value   Description
#define     rx_c4_sel                                         0x0000     //Select 1 of 4 possible phases for the C4 clock to send along with the data for integration flexibility and tuning for slack into the Rx FIFO.
#define     rx_c4_sel_clear                                   0x3FFF     // Clear mask
#define     rx_negz_en                                        0x2000     //Turns on a gyrator stage in the CTLE pushing up the high freq corner
#define     rx_negz_en_clear                                  0xDFFF     // Clear mask
#define     rx_prot_speed_slct                                0x1000     //TBD (Enable the flux capacitor?)
#define     rx_prot_speed_slct_clear                          0xEFFF     // Clear mask
#define     rx_iref_bc                                        0x0000     //Bias Code for the Iref macros on the RX side. All eight 3 bit codes enable current out. The cml voltage swings of the output current will vary with this code.
#define     rx_iref_bc_clear                                  0xF1FF     // Clear mask

// rx_dyn_rpr_pg Register field name                                    data value   Description
#define     rx_dyn_rpr_state_clear                            0xC0FF     // Clear mask
#define     rx_sls_hndshk_state_clear                         0xFF00     // Clear mask

// rx_dyn_rpr_gcrmsg_pg Register field name                             data value   Description
#define     rx_dyn_rpr_req_gcrmsg                             0x8000     //GCR Message: CRC/ECC Tallying logic has a Dynamic Repair Request
#define     rx_dyn_rpr_req_gcrmsg_clear                       0x7FFF     // Clear mask
#define     rx_dyn_rpr_lane2rpr_gcrmsg                        0x0000     //GCR Message: CRC/ECC Tallying logic bad lane to repair
#define     rx_dyn_rpr_lane2rpr_gcrmsg_clear                  0x80FF     // Clear mask
#define     rx_dyn_rpr_ip_gcrmsg                              0x0080     //GCR Message: CRC/ECC Bad Lane Repair In Progress
#define     rx_dyn_rpr_ip_gcrmsg_clear                        0xFF7F     // Clear mask
#define     rx_dyn_rpr_complete_gcrmsg                        0x0040     //GCR Message: CRC/ECC Bad Lane Repaired
#define     rx_dyn_rpr_complete_gcrmsg_clear                  0xFFBF     // Clear mask

// rx_dyn_rpr_err_tallying1_pg Register field name                      data value   Description
#define     rx_dyn_rpr_bad_lane_max                           0x0000     //CRC/ECC Dynamic Repair: Max number of times a lane can be found bad before repaired
#define     rx_dyn_rpr_bad_lane_max_clear                     0x01FF     // Clear mask
#define     rx_dyn_rpr_err_cntr1_duration_tap1                0x0020     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  853.0ns & 1.3uS
#define     rx_dyn_rpr_err_cntr1_duration_tap2                0x0040     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  27.3uS & 41.0uS
#define     rx_dyn_rpr_err_cntr1_duration_tap3                0x0060     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  873.5uS & 1.3mS
#define     rx_dyn_rpr_err_cntr1_duration_tap4                0x0080     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  1.7mS & 2.6mS
#define     rx_dyn_rpr_err_cntr1_duration_tap5                0x00A0     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  3.5mS & 5.1mS
#define     rx_dyn_rpr_err_cntr1_duration_tap6                0x00C0     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  7.0mS & 10.5mS
#define     rx_dyn_rpr_err_cntr1_duration_tap7                0x00E0     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  14.0mS & 21.0mS
#define     rx_dyn_rpr_err_cntr1_duration_tap8                0x0100     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  28.0mS & 41.9mS
#define     rx_dyn_rpr_err_cntr1_duration_tap9                0x0120     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  55.9mS & 83.9mS
#define     rx_dyn_rpr_err_cntr1_duration_tap10               0x0140     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  111.8mS & 167.8mS
#define     rx_dyn_rpr_err_cntr1_duration_tap11               0x0160     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  223.6mS & 335.5mS
#define     rx_dyn_rpr_err_cntr1_duration_tap12               0x0180     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  447.2mS & 671.1mS
#define     rx_dyn_rpr_err_cntr1_duration_tap13               0x01A0     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  894.4mS & 1.3 S
#define     rx_dyn_rpr_err_cntr1_duration_tap14               0x01C0     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  1.8 S & 2.7 S
#define     rx_dyn_rpr_err_cntr1_duration_tap15               0x01E0     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  infinite
#define     rx_dyn_rpr_err_cntr1_duration_clear               0x3E1F     // Clear mask
#define     rx_dyn_rpr_clr_err_cntr1                          0x0010     //CRC/ECC Dynamic Repair: Firmware-based clear of lane error counter1 register
#define     rx_dyn_rpr_clr_err_cntr1_clear                    0xFFEF     // Clear mask
#define     rx_dyn_rpr_disable                                0x0008     //CRC/ECC Dynamic Repair: When set, disables dynamic repair error tallying (both per lane and per bus error counters...cntr1 & cntr2)
#define     rx_dyn_rpr_disable_clear                          0xFFF7     // Clear mask
#define     rx_dyn_rpr_enc_bad_data_lane_width                0x0000     //CRC/ECC Dynamic Repair: Width of the enc_bad_data_lane vector used to determine number of 1s in clear code
#define     rx_dyn_rpr_enc_bad_data_lane_width_clear          0xFFB8     // Clear mask

// rx_eo_final_l2u_gcrmsgs_pg Register field name                       data value   Description
#define     rx_eo_final_l2u_dly_seq_gcrmsg_fl2uallchg         0x4000     //GCR Message: RX Final Load to Unload Delay GCR messages  Indicate all groups have calculated max load to unload change.
#define     rx_eo_final_l2u_dly_seq_gcrmsg_unused             0x8000     //GCR Message: RX Final Load to Unload Delay GCR messages  Unused.
#define     rx_eo_final_l2u_dly_seq_gcrmsg_fl2unomsg          0xC000     //GCR Message: RX Final Load to Unload Delay GCR messages  No message.
#define     rx_eo_final_l2u_dly_seq_gcrmsg_clear              0x3FFF     // Clear mask
#define     rx_eo_final_l2u_dly_maxchg_gcrmsg                 0x0000     //GCR Message: Max change in miniumum load to unload delay.
#define     rx_eo_final_l2u_dly_maxchg_gcrmsg_clear           0xC0FF     // Clear mask
#define     rx_eo_final_l2u_dly_chg                           0x0000     //GCR Message: Local change in miniumum load to unload delay.
#define     rx_eo_final_l2u_dly_chg_clear                     0x3FC0     // Clear mask

// rx_gcr_msg_debug_dest_ids_pg Register field name                     data value   Description
#define     rx_gcr_msg_debug_dest_bus_id_clear                0x03FF     // Clear mask
#define     rx_gcr_msg_debug_dest_group_id_clear              0xFC0F     // Clear mask

// rx_gcr_msg_debug_src_ids_pg Register field name                      data value   Description
#define     rx_gcr_msg_debug_src_bus_id_clear                 0x03FF     // Clear mask
#define     rx_gcr_msg_debug_src_group_id_clear               0xFC0F     // Clear mask

// rx_gcr_msg_debug_dest_addr_pg Register field name                    data value   Description
#define     rx_gcr_msg_debug_dest_addr_clear                  0x007F     // Clear mask
#define     rx_gcr_msg_debug_send_msg                         0x0001     //GCR Messaging Debug: Send GCR Message on rising edge of this bit.
#define     rx_gcr_msg_debug_send_msg_clear                   0xFFFE     // Clear mask

// rx_gcr_msg_debug_write_data_pg Register field name                   data value   Description
#define     rx_gcr_msg_debug_write_data_clear                 0x0000     // Clear mask

// rx_dyn_recal_pg Register field name                                  data value   Description
#define     rx_servo_recal_ip                                 0x8000     //RX Servo Lane Calibration In Progress
#define     rx_servo_recal_ip_clear                           0x7FFF     // Clear mask
#define     rx_dyn_recal_main_state_clear                     0xC0FF     // Clear mask
#define     rx_dyn_recal_hndshk_state_clear                   0x7F80     // Clear mask

// rx_wt_clk_status_pg Register field name                              data value   Description
#define     rx_wt_clk_lane_inverted                           0x4000     //Clock Wiretest lane inverted/swapped status 
#define     rx_wt_clk_lane_inverted_clear                     0xBFFF     // Clear mask
#define     rx_wt_clk_lane_bad_code_n_stuck_1                 0x0800     //Clock Wiretest Lane Bad code  N leg stuck at 1 
#define     rx_wt_clk_lane_bad_code_n_stuck_0                 0x1000     //Clock Wiretest Lane Bad code  N leg stuck at 0 
#define     rx_wt_clk_lane_bad_code_p_stuck_1                 0x1800     //Clock Wiretest Lane Bad code  P leg stuck at 1 
#define     rx_wt_clk_lane_bad_code_p_stuck_0                 0x2000     //Clock Wiretest Lane Bad code  P leg stuck at 0 
#define     rx_wt_clk_lane_bad_code_n_or_p_floating           0x2800     //Clock Wiretest Lane Bad code  N  or P leg floating or swapping undetermined 
#define     rx_wt_clk_lane_bad_code_NOT_USED_110              0x3000     //Clock Wiretest Lane Bad code Unused.
#define     rx_wt_clk_lane_bad_code_NOT_USED_111              0x3800     //Clock Wiretest Lane Bad code Unused.
#define     rx_wt_clk_lane_bad_code_clear                     0xC7FF     // Clear mask

// rx_dyn_recal_config_pg Register field name                           data value   Description
#define     rx_dyn_recal_overall_timeout_sel_tap1             0x2000     //Dynamic Recalibration Overall Timeout Selects  436.73us - smallest value for normal operation
#define     rx_dyn_recal_overall_timeout_sel_tap2             0x4000     //Dynamic Recalibration Overall Timeout Selects  873.46uS
#define     rx_dyn_recal_overall_timeout_sel_tap3             0x6000     //Dynamic Recalibration Overall Timeout Selects  1.75mS
#define     rx_dyn_recal_overall_timeout_sel_tap4             0x8000     //Dynamic Recalibration Overall Timeout Selects  3.49mS - Recal should be around 2mS
#define     rx_dyn_recal_overall_timeout_sel_tap5             0xA000     //Dynamic Recalibration Overall Timeout Selects  13.97mS
#define     rx_dyn_recal_overall_timeout_sel_tap6             0xC000     //Dynamic Recalibration Overall Timeout Selects  55.90mS - largest value for normal operation
#define     rx_dyn_recal_overall_timeout_sel_tap7             0xE000     //Dynamic Recalibration Overall Timeout Selects  Infinite- For debug purposes
#define     rx_dyn_recal_overall_timeout_sel_clear            0x1FFF     // Clear mask
#define     rx_dyn_recal_suspend                              0x1000     //Suspend Dynamic Recalibration; otherwise starts automatically after link training
#define     rx_dyn_recal_suspend_clear                        0xEFFF     // Clear mask

// rx_dyn_recal_gcrmsg_pg Register field name                           data value   Description
#define     rx_dyn_recal_ip_gcrmsg                            0x8000     //GCR Message: RX Dynamic Recalibration In Progress
#define     rx_dyn_recal_ip_gcrmsg_clear                      0x7FFF     // Clear mask
#define     rx_dyn_recal_failed_gcrmsg                        0x4000     //GCR Message: RX Dynamic Recalibration Failed
#define     rx_dyn_recal_failed_gcrmsg_clear                  0xBFFF     // Clear mask
#define     rx_dyn_recal_ripple_gcrmsg                        0x2000     //GCR Message: RX Dynamic Recalibration: Reached end of bus...ripple back down to the beginning
#define     rx_dyn_recal_ripple_gcrmsg_clear                  0xDFFF     // Clear mask
#define     rx_dyn_recal_timeout_gcrmsg                       0x1000     //GCR Message: RX Dynamic Recalibration: Recal Handshake Timed Out
#define     rx_dyn_recal_timeout_gcrmsg_clear                 0xEFFF     // Clear mask

// rx_wiretest_pll_cntl_pg Register field name                          data value   Description
#define     rx_wt_cu_pll_pgood                                0x8000     //RX PLL/DLL Enable
#define     rx_wt_cu_pll_pgood_clear                          0x7FFF     // Clear mask
#define     rx_wt_cu_pll_reset                                0x4000     //RX PLL/DLL Enable Request
#define     rx_wt_cu_pll_reset_clear                          0xBFFF     // Clear mask
#define     rx_wt_cu_pll_pgooddly_50ns                        0x0800     //RX PLL/DLL PGOOD Delay Selects length of reset period after rx_wt_cu_pll_reset is set.   Nominal 50ns Reset per PLL Spec 
#define     rx_wt_cu_pll_pgooddly_100ns                       0x1000     //RX PLL/DLL PGOOD Delay Selects length of reset period after rx_wt_cu_pll_reset is set.   Double Nominal 50ns Reset per PLL Spec 
#define     rx_wt_cu_pll_pgooddly_960ui                       0x1800     //RX PLL/DLL PGOOD Delay Selects length of reset period after rx_wt_cu_pll_reset is set.   Typical simulation delay exceeding TX PLL 40-refclk locking period 
#define     rx_wt_cu_pll_pgooddly_unused_100                  0x2000     //RX PLL/DLL PGOOD Delay Selects length of reset period after rx_wt_cu_pll_reset is set.   Reserved 
#define     rx_wt_cu_pll_pgooddly_unused_101                  0x2800     //RX PLL/DLL PGOOD Delay Selects length of reset period after rx_wt_cu_pll_reset is set.   Reserved 
#define     rx_wt_cu_pll_pgooddly_MAX                         0x3000     //RX PLL/DLL PGOOD Delay Selects length of reset period after rx_wt_cu_pll_reset is set.   1024 UI  
#define     rx_wt_cu_pll_pgooddly_disable                     0x3800     //RX PLL/DLL PGOOD Delay Selects length of reset period after rx_wt_cu_pll_reset is set.   Disable rx_wt_cu_pll_reset
#define     rx_wt_cu_pll_pgooddly_clear                       0xC7FF     // Clear mask
#define     rx_wt_cu_pll_lock                                 0x0400     //RX PLL/DLL Locked
#define     rx_wt_cu_pll_lock_clear                           0xFBFF     // Clear mask
#define     rx_wt_pll_refclksel                               0x0200     //Select between IO clock and BIST/Refclock
#define     rx_wt_pll_refclksel_clear                         0xFDFF     // Clear mask
#define     rx_pll_refclksel_scom_en                          0x0100     //Selects between PLL controls and GCR register to select refclk
#define     rx_pll_refclksel_scom_en_clear                    0xFEFF     // Clear mask

// rx_eo_step_cntl_pg Register field name                               data value   Description
#define     rx_eo_enable_latch_offset_cal                     0x8000     //RX eye optimization latch offset adjustment enable
#define     rx_eo_enable_latch_offset_cal_clear               0x7FFF     // Clear mask
#define     rx_eo_enable_ctle_cal                             0x4000     //RX eye optimization CTLE/Peakin enable
#define     rx_eo_enable_ctle_cal_clear                       0xBFFF     // Clear mask
#define     rx_eo_enable_vga_cal                              0x2000     //RX eye optimization VGA gainand offset adjust enable
#define     rx_eo_enable_vga_cal_clear                        0xDFFF     // Clear mask
#define     rx_eo_enable_dfe_h1_cal                           0x0800     //RX eye optimization DFE H1  adjust enable
#define     rx_eo_enable_dfe_h1_cal_clear                     0xF7FF     // Clear mask
#define     rx_eo_enable_h1ap_tweak                           0x0400     //RX eye optimization H1/AN PR adjust enable
#define     rx_eo_enable_h1ap_tweak_clear                     0xFBFF     // Clear mask
#define     rx_eo_enable_ddc                                  0x0200     //RX eye optimization Dynamic data centering enable
#define     rx_eo_enable_ddc_clear                            0xFDFF     // Clear mask
#define     rx_eo_enable_final_l2u_adj                        0x0080     //RX eye optimization Final RX FIFO load-to-unload delay adjustment enable
#define     rx_eo_enable_final_l2u_adj_clear                  0xFF7F     // Clear mask
#define     rx_eo_enable_ber_test                             0x0040     //RX eye optimization Bit error rate test enable
#define     rx_eo_enable_ber_test_clear                       0xFFBF     // Clear mask
#define     rx_eo_enable_result_check                         0x0020     //RX eye optimization Final results check enable
#define     rx_eo_enable_result_check_clear                   0xFFDF     // Clear mask
#define     rx_eo_enable_ctle_edge_track_only                 0x0010     //RX eye optimization CTLE/Peakin enable with edge tracking only
#define     rx_eo_enable_ctle_edge_track_only_clear           0xFFEF     // Clear mask

// rx_eo_step_stat_pg Register field name                               data value   Description
#define     rx_eo_latch_offset_done                           0x8000     //RX eye optimization latch offset adjustment done
#define     rx_eo_latch_offset_done_clear                     0x7FFF     // Clear mask
#define     rx_eo_ctle_done                                   0x4000     //RX eye optimization CTLE/Peaking done
#define     rx_eo_ctle_done_clear                             0xBFFF     // Clear mask
#define     rx_eo_vga_done                                    0x2000     //RX eye optimization VGA gain/offset adjust done
#define     rx_eo_vga_done_clear                              0xDFFF     // Clear mask
#define     rx_eo_dfe_h1_done                                 0x0800     //RX eye optimization DFE H1  adjust done
#define     rx_eo_dfe_h1_done_clear                           0xF7FF     // Clear mask
#define     rx_eo_h1ap_tweak_done                             0x0400     //RX eye optimization H1/AN PR adjust done
#define     rx_eo_h1ap_tweak_done_clear                       0xFBFF     // Clear mask
#define     rx_eo_ddc_done                                    0x0200     //RX eye optimization Dynamic data centering done
#define     rx_eo_ddc_done_clear                              0xFDFF     // Clear mask
#define     rx_eo_final_l2u_adj_done                          0x0080     //RX eye optimization Final RX FIFO load-to-unload adjust done
#define     rx_eo_final_l2u_adj_done_clear                    0xFF7F     // Clear mask
#define     rx_eo_dfe_flag                                    0x0040     //RX eye optimization DFE mode flag              
#define     rx_eo_dfe_flag_clear                              0xFFBF     // Clear mask
#define     rx_eo_ber_test_done                               0x0020     //RX eye optimization Bit Error rate test done
#define     rx_eo_ber_test_done_clear                         0xFFDF     // Clear mask
#define     rx_eo_result_check_done                           0x0010     //RX eye optimization Eye width/heightER check done 
#define     rx_eo_result_check_done_clear                     0xFFEF     // Clear mask

// rx_eo_step_fail_pg Register field name                               data value   Description
#define     rx_eo_latch_offset_failed                         0x8000     //RX eye optimization latch offset adjustment  failed
#define     rx_eo_latch_offset_failed_clear                   0x7FFF     // Clear mask
#define     rx_eo_ctle_failed                                 0x4000     //RX eye optimization CTLE/Peaking  failed
#define     rx_eo_ctle_failed_clear                           0xBFFF     // Clear mask
#define     rx_eo_vga_failed                                  0x2000     //RX eye optimization VGA gain/offset adjust  failed
#define     rx_eo_vga_failed_clear                            0xDFFF     // Clear mask
#define     rx_eo_dfe_h1_failed                               0x0800     //RX eye optimization DFE H1  adjust failed
#define     rx_eo_dfe_h1_failed_clear                         0xF7FF     // Clear mask
#define     rx_eo_h1ap_tweak_failed                           0x0400     //RX eye optimization H1/AN PR adjust failed
#define     rx_eo_h1ap_tweak_failed_clear                     0xFBFF     // Clear mask
#define     rx_eo_ddc_failed                                  0x0200     //RX eye optimization Dynamic data centering failed
#define     rx_eo_ddc_failed_clear                            0xFDFF     // Clear mask
#define     rx_eo_final_l2u_adj_failed                        0x0080     //RX eye optimization Final RX FIFO load-to-unload adjust  failed
#define     rx_eo_final_l2u_adj_failed_clear                  0xFF7F     // Clear mask
#define     rx_eo_result_check_failed                         0x0040     //RX eye optimization Final Result checking failed
#define     rx_eo_result_check_failed_clear                   0xFFBF     // Clear mask

// rx_ap_pg Register field name                                         data value   Description
#define     rx_ap_even_work                                   0x0000     //RX Ap even working register
#define     rx_ap_even_work_clear                             0x00FF     // Clear mask
#define     rx_ap_odd_work                                    0x0000     //Rx Ap odd  working register
#define     rx_ap_odd_work_clear                              0xFF00     // Clear mask

// rx_an_pg Register field name                                         data value   Description
#define     rx_an_even_work                                   0x0000     //RX An even working register
#define     rx_an_even_work_clear                             0x00FF     // Clear mask
#define     rx_an_odd_work                                    0x0000     //Rx An odd  working register
#define     rx_an_odd_work_clear                              0xFF00     // Clear mask

// rx_amin_pg Register field name                                       data value   Description
#define     rx_amin_even_work                                 0x0000     //RX Amin even working register
#define     rx_amin_even_work_clear                           0x00FF     // Clear mask
#define     rx_amin_odd_work                                  0x0000     //Rx Amin odd  working register
#define     rx_amin_odd_work_clear                            0xFF00     // Clear mask

// rx_amax_pg Register field name                                       data value   Description
#define     rx_amax_high                                      0x0000     //RX Amax high limit default 125
#define     rx_amax_high_clear                                0x00FF     // Clear mask
#define     rx_amax_low                                       0x0000     //Rx Amax low limit  default 75
#define     rx_amax_low_clear                                 0xFF00     // Clear mask

// rx_amp_val_pg Register field name                                    data value   Description
#define     rx_amp_peak_work                                  0x0000     //Rx amp peak working register
#define     rx_amp_peak_work_clear                            0x0FFF     // Clear mask
#define     rx_amp_gain_work                                  0x0000     //Rx Amp gain working register
#define     rx_amp_gain_work_clear                            0xF0FF     // Clear mask
#define     rx_amp_offset_work                                0x0000     //Rx amp offset working register
#define     rx_amp_offset_work_clear                          0x3FC0     // Clear mask

// rx_amp_offset_pg Register field name                                 data value   Description
#define     rx_amp_offset_max                                 0x0000     //Rx amp maximum allowable offset
#define     rx_amp_offset_max_clear                           0x03FF     // Clear mask
#define     rx_amp_offset_min                                 0x0000     //Rx Amp minimum allowable offset
#define     rx_amp_offset_min_clear                           0xFC0F     // Clear mask

// rx_eo_convergence_pg Register field name                             data value   Description
#define     rx_eo_converged_count                             0x0000     //RX eye optimization Convergence counter current value
#define     rx_eo_converged_count_clear                       0x0FFF     // Clear mask
#define     rx_eo_converged_end_count                         0x0000     //RX eye optimization Covergence counter end value
#define     rx_eo_converged_end_count_clear                   0xF0FF     // Clear mask

// rx_sls_rcvy_pg Register field name                                   data value   Description
#define     rx_sls_rcvy_disable                               0x8000     //Disable SLS Recovery
#define     rx_sls_rcvy_disable_clear                         0x7FFF     // Clear mask
#define     rx_sls_rcvy_state_clear                           0xE0FF     // Clear mask

// rx_sls_rcvy_gcrmsg_pg Register field name                            data value   Description
#define     rx_sls_rcvy_req_gcrmsg                            0x8000     //GCR Message: SLS Rcvy; RX Lane Repair Req
#define     rx_sls_rcvy_req_gcrmsg_clear                      0x7FFF     // Clear mask
#define     rx_sls_rcvy_ip_gcrmsg                             0x4000     //GCR Message: SLS Rcvy; RX Lane Repair IP
#define     rx_sls_rcvy_ip_gcrmsg_clear                       0xBFFF     // Clear mask
#define     rx_sls_rcvy_done_gcrmsg                           0x2000     //GCR Message: SLS Rcvy; RX Lane Repair Done
#define     rx_sls_rcvy_done_gcrmsg_clear                     0xDFFF     // Clear mask

// rx_tx_lane_info_gcrmsg_pg Register field name                        data value   Description
#define     rx_tx_bad_lane_cntr_gcrmsg                        0x0000     //GCR Message: RX Side TX Bad Lane Counter
#define     rx_tx_bad_lane_cntr_gcrmsg_clear                  0x3FFF     // Clear mask

// rx_err_tallying_gcrmsg_pg Register field name                        data value   Description
#define     rx_dis_synd_tallying_gcrmsg                       0x8000     //GCR Message: Disable Syndrome Tallying
#define     rx_dis_synd_tallying_gcrmsg_clear                 0x7FFF     // Clear mask

// rx_trace_pg Register field name                                      data value   Description
#define     rx_trc_mode_tap1                                  0x1000     //RX Trace Mode  Dynamic Repair State Machines
#define     rx_trc_mode_tap2                                  0x2000     //RX Trace Mode  SLS Handshake State Machines with Recovery
#define     rx_trc_mode_tap3                                  0x3000     //RX Trace Mode  Dynamic Recal State Machines
#define     rx_trc_mode_tap4                                  0x4000     //RX Trace Mode  Recal Handshake State Machine with Recovery
#define     rx_trc_mode_tap5                                  0x5000     //RX Trace Mode  CRC or ECC Tallying Logic
#define     rx_trc_mode_tap6                                  0x6000     //RX Trace Mode  RX SLS Commands
#define     rx_trc_mode_tap7                                  0x7000     //RX Trace Mode  RX Bad Lanes
#define     rx_trc_mode_tap8                                  0x8000     //RX Trace Mode  RX SLS Lanes
#define     rx_trc_mode_tap9                                  0x9000     //RX Trace Mode  GCR
#define     rx_trc_mode_tap10                                 0xA000     //RX Trace Mode  Per Lane / Per Pack Trace (see rx_pp_trc_mode for details
#define     rx_trc_mode_tap11                                 0xB000     //RX Trace Mode  TBD
#define     rx_trc_mode_tap12                                 0xC000     //RX Trace Mode  TBD
#define     rx_trc_mode_tap13                                 0xD000     //RX Trace Mode  TBD
#define     rx_trc_mode_tap14                                 0xE000     //RX Trace Mode  TBD
#define     rx_trc_mode_tap15                                 0xF000     //RX Trace Mode  TBD
#define     rx_trc_mode_clear                                 0x0FFF     // Clear mask
#define     rx_trc_grp_clear                                  0xFC0F     // Clear mask

// rx_rc_step_cntl_pg Register field name                               data value   Description
#define     rx_rc_enable_latch_offset_cal                     0x8000     //RX recalibration    latch offset adjustment enable
#define     rx_rc_enable_latch_offset_cal_clear               0x7FFF     // Clear mask
#define     rx_rc_enable_ctle_cal                             0x4000     //RX recalibration    CTLE/Peaking enable
#define     rx_rc_enable_ctle_cal_clear                       0xBFFF     // Clear mask
#define     rx_rc_enable_vga_cal                              0x2000     //RX recalibration    VGA gainand offset adjust enable
#define     rx_rc_enable_vga_cal_clear                        0xDFFF     // Clear mask
#define     rx_rc_enable_dfe_h1_cal                           0x0800     //RX recalibration    DFE H1  adjust enable
#define     rx_rc_enable_dfe_h1_cal_clear                     0xF7FF     // Clear mask
#define     rx_rc_enable_h1ap_tweak                           0x0400     //RX recalibration    H1/AN PR adjust enable
#define     rx_rc_enable_h1ap_tweak_clear                     0xFBFF     // Clear mask
#define     rx_rc_enable_ddc                                  0x0200     //RX recalibration    Dynamic data centering enable
#define     rx_rc_enable_ddc_clear                            0xFDFF     // Clear mask
#define     rx_rc_enable_ber_test                             0x0080     //RX recalibration    Bit error rate test enable
#define     rx_rc_enable_ber_test_clear                       0xFF7F     // Clear mask
#define     rx_rc_enable_result_check                         0x0040     //RX recalibration    Final results check enable
#define     rx_rc_enable_result_check_clear                   0xFFBF     // Clear mask
#define     rx_rc_enable_ctle_edge_track_only                 0x0010     //RX recalibration    CTLE/Peaking enable with edge tracking only
#define     rx_rc_enable_ctle_edge_track_only_clear           0xFFEF     // Clear mask

// rx_eo_recal_pg Register field name                                   data value   Description
#define     rx_eye_opt_state                                  0x0000     //Common EDI/EI4 Eye optimizaton State Machine
#define     rx_eye_opt_state_clear                            0x00FF     // Clear mask
#define     rx_recal_state                                    0x0000     //Common EDI/EI4 recalibration State Machine
#define     rx_recal_state_clear                              0xFF00     // Clear mask

// rx_servo_ber_count_pg Register field name                            data value   Description
#define     rx_servo_ber_count_work                           0x0000     //Rx servo-based bit error rate count working register
#define     rx_servo_ber_count_work_clear                     0x000F     // Clear mask

// rx_func_state_pg Register field name                                 data value   Description
#define     rx_func_mode_state                                0x0000     //Functional Mode State Machine(RJR):
#define     rx_func_mode_state_clear                          0x0FFF     // Clear mask

// rx_dyn_rpr_debug_pg Register field name                              data value   Description
#define     rx_dyn_rpr_enc_bad_data_lane_debug                0x0000     //For testfloor/debug purposes, specify the encoded bad data lane to report to the dynamic repair tally logic
#define     rx_dyn_rpr_enc_bad_data_lane_debug_clear          0x01FF     // Clear mask
#define     rx_dyn_rpr_bad_lane_valid_debug                   0x0080     //For testfloor/debug purposes, the specified encoded bad data lane will be tallied as having one cycle of a valid CRC/ECC error (this is a write-only pulse register)
#define     rx_dyn_rpr_bad_lane_valid_debug_clear             0xFF7F     // Clear mask

// rx_dyn_rpr_err_tallying2_pg Register field name                      data value   Description
#define     rx_dyn_rpr_bad_bus_max                            0x0000     //CRC/ECC Dynamic Repair: Max number of times CRC or ECC errors can be found on the bus (not included in the bad lane cntr1 tally) before setting a FIR error
#define     rx_dyn_rpr_bad_bus_max_clear                      0x01FF     // Clear mask
#define     rx_dyn_rpr_err_cntr2_duration_tap1                0x0020     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  853.0ns & 1.3uS
#define     rx_dyn_rpr_err_cntr2_duration_tap2                0x0040     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  27.3uS & 41.0uS
#define     rx_dyn_rpr_err_cntr2_duration_tap3                0x0060     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  873.5uS & 1.3mS
#define     rx_dyn_rpr_err_cntr2_duration_tap4                0x0080     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  1.7mS & 2.6mS
#define     rx_dyn_rpr_err_cntr2_duration_tap5                0x00A0     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  3.5mS & 5.1mS
#define     rx_dyn_rpr_err_cntr2_duration_tap6                0x00C0     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  7.0mS & 10.5mS
#define     rx_dyn_rpr_err_cntr2_duration_tap7                0x00E0     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  14.0mS & 21.0mS
#define     rx_dyn_rpr_err_cntr2_duration_tap8                0x0100     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  28.0mS & 41.9mS
#define     rx_dyn_rpr_err_cntr2_duration_tap9                0x0120     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  55.9mS & 83.9mS
#define     rx_dyn_rpr_err_cntr2_duration_tap10               0x0140     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  111.8mS & 167.8mS
#define     rx_dyn_rpr_err_cntr2_duration_tap11               0x0160     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  223.6mS & 335.5mS
#define     rx_dyn_rpr_err_cntr2_duration_tap12               0x0180     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  447.2mS & 671.1mS
#define     rx_dyn_rpr_err_cntr2_duration_tap13               0x01A0     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  894.4mS & 1.3 S
#define     rx_dyn_rpr_err_cntr2_duration_tap14               0x01C0     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  1.8 S & 2.7 S
#define     rx_dyn_rpr_err_cntr2_duration_tap15               0x01E0     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  infinite
#define     rx_dyn_rpr_err_cntr2_duration_clear               0x3E1F     // Clear mask
#define     rx_dyn_rpr_clr_err_cntr2                          0x0010     //CRC/ECC Dynamic Repair: Firmware-based clear of bus error counter2 register
#define     rx_dyn_rpr_clr_err_cntr2_clear                    0xFFEF     // Clear mask

// rx_result_chk_pg Register field name                                 data value   Description
#define     rx_min_eye_width                                  0x0000     //Minimum acceptable eye width used during init or recal results checking--EDI or EI4
#define     rx_min_eye_width_clear                            0xC0FF     // Clear mask
#define     rx_min_eye_height                                 0x0000     //Minimum acceptable eye height used during init or recal results checking--EDI only
#define     rx_min_eye_height_clear                           0xFF00     // Clear mask

// rx_ber_chk_pg Register field name                                    data value   Description
#define     rx_max_ber_check_count                            0x0000     //Maximum acceptable number of bit errors allowable after recal--EDI only
#define     rx_max_ber_check_count_clear                      0x0000     // Clear mask

// rx_sls_rcvy_fin_gcrmsg_pg Register field name                        data value   Description
#define     rx_slv_shdw_done_fin_gcrmsg                       0x8000     //GCR Message: Slave RX SLS Lane Repaired; Need to finish slave shadow handshake starting with waiting for shdw_done
#define     rx_slv_shdw_done_fin_gcrmsg_clear                 0x7FFF     // Clear mask
#define     rx_slv_shdw_nop_fin_gcrmsg                        0x4000     //GCR Message: Slave RX SLS Lane Repaired; Need to finish slave shadow handshake starting with waiting for nop
#define     rx_slv_shdw_nop_fin_gcrmsg_clear                  0xBFFF     // Clear mask
#define     rx_slv_shdw_rpr_done_fin_gcrmsg                   0x2000     //GCR Message: Slave RX SLS Lane Repaired; Need to finish slave shadow handshake starting with waiting for shdw_rpr_done
#define     rx_slv_shdw_rpr_done_fin_gcrmsg_clear             0xDFFF     // Clear mask
#define     rx_slv_shdw_rpr_nop_fin_gcrmsg                    0x1000     //GCR Message: Slave RX SLS Lane Repaired; Need to finish slave shadow handshake starting with waiting for nop
#define     rx_slv_shdw_rpr_nop_fin_gcrmsg_clear              0xEFFF     // Clear mask
#define     rx_slv_unshdw_done_fin_gcrmsg                     0x0800     //GCR Message: Slave RX SLS Lane Repaired; Need to finish slave shadow handshake starting with waiting for unshdw_done
#define     rx_slv_unshdw_done_fin_gcrmsg_clear               0xF7FF     // Clear mask
#define     rx_slv_unshdw_nop_fin_gcrmsg                      0x0400     //GCR Message: Slave RX SLS Lane Repaired; Need to finish slave shadow handshake starting with waiting for nop
#define     rx_slv_unshdw_nop_fin_gcrmsg_clear                0xFBFF     // Clear mask
#define     rx_slv_unshdw_rpr_done_fin_gcrmsg                 0x0200     //GCR Message: Slave RX SLS Lane Repaired; Need to finish slave shadow handshake starting with waiting for unshdw_rpr_done
#define     rx_slv_unshdw_rpr_done_fin_gcrmsg_clear           0xFDFF     // Clear mask
#define     rx_slv_unshdw_rpr_nop_fin_gcrmsg                  0x0100     //GCR Message: Slave RX SLS Lane Repaired; Need to finish slave shadow handshake starting with waiting for nop
#define     rx_slv_unshdw_rpr_nop_fin_gcrmsg_clear            0xFEFF     // Clear mask
#define     rx_slv_recal_done_nop_fin_gcrmsg                  0x0080     //GCR Message: Slave Recal Done; Need to finish slave recal handshake starting with waiting for nop
#define     rx_slv_recal_done_nop_fin_gcrmsg_clear            0xFF7F     // Clear mask
#define     rx_slv_recal_fail_nop_fin_gcrmsg                  0x0040     //GCR Message: Slave Recal Fail; Need to finish slave recal handshake starting with waiting for nop
#define     rx_slv_recal_fail_nop_fin_gcrmsg_clear            0xFFBF     // Clear mask
#define     rx_slv_recal_presults_fin_gcrmsg                  0x0020     //GCR Message: Slave Recal Pass Results; Need to finish slave recal handshake starting with waiting for results
#define     rx_slv_recal_presults_fin_gcrmsg_clear            0xFFDF     // Clear mask
#define     rx_slv_recal_fresults_fin_gcrmsg                  0x0010     //GCR Message: Slave Recal Fail Results; Need to finish slave recal handshake starting with waiting for results
#define     rx_slv_recal_fresults_fin_gcrmsg_clear            0xFFEF     // Clear mask
#define     rx_slv_recal_abort_ack_fin_gcrmsg                 0x0008     //GCR Message: Slave Recal Abort; Need to finish slave recal handshake starting with waiting for nop
#define     rx_slv_recal_abort_ack_fin_gcrmsg_clear           0xFFF7     // Clear mask
#define     rx_slv_recal_abort_mnop_fin_gcrmsg                0x0004     //GCR Message: Slave Recal Abort; Need to finish slave recal handshake starting with waiting for nop
#define     rx_slv_recal_abort_mnop_fin_gcrmsg_clear          0xFFFB     // Clear mask
#define     rx_slv_recal_abort_snop_fin_gcrmsg                0x0002     //GCR Message: Slave Recal Abort; Need to finish slave recal handshake starting with waiting for nop
#define     rx_slv_recal_abort_snop_fin_gcrmsg_clear          0xFFFD     // Clear mask

// rx_wiretest_pp Register field name                                   data value   Description
#define     rx_wt_pattern_length_256                          0x4000     //RX Wiretest Pattern Length  256
#define     rx_wt_pattern_length_512                          0x8000     //RX Wiretest Pattern Length  512
#define     rx_wt_pattern_length_1024                         0xC000     //RX Wiretest Pattern Length  1024
#define     rx_wt_pattern_length_clear                        0x3FFF     // Clear mask

// rx_mode1_pp Register field name                                      data value   Description
#define     rx_reduced_scramble_mode_disable_1                0x4000     //Sets reduced density of scramble pattern.   Disable reduced density 
#define     rx_reduced_scramble_mode_enable_div2              0x8000     //Sets reduced density of scramble pattern.   Enable Div2 Reduced Density 
#define     rx_reduced_scramble_mode_enable_div4              0xC000     //Sets reduced density of scramble pattern.   Enable Div4 Reduced Density
#define     rx_reduced_scramble_mode_clear                    0x3FFF     // Clear mask
#define     rx_act_check_timeout_sel_128ui                    0x0800     //Sets Activity check timeout value.   128 UI 
#define     rx_act_check_timeout_sel_256ui                    0x1000     //Sets Activity check timeout value.   256 UI 
#define     rx_act_check_timeout_sel_512ui                    0x1800     //Sets Activity check timeout value.   512 UI 
#define     rx_act_check_timeout_sel_1024ui                   0x2000     //Sets Activity check timeout value.   1024 UI 
#define     rx_act_check_timeout_sel_2048ui                   0x2800     //Sets Activity check timeout value.   2048 UI 
#define     rx_act_check_timeout_sel_4096ui                   0x3000     //Sets Activity check timeout value.   4096 UI 
#define     rx_act_check_timeout_sel_infinite                 0x3800     //Sets Activity check timeout value.   Infinite
#define     rx_act_check_timeout_sel_clear                    0xC7FF     // Clear mask
#define     rx_block_lock_timeout_sel_1024ui                  0x0100     //Sets block lock timeout value.   1024 UI 
#define     rx_block_lock_timeout_sel_2048ui                  0x0200     //Sets block lock timeout value.   2048 UI 
#define     rx_block_lock_timeout_sel_4096ui                  0x0300     //Sets block lock timeout value.   4096 UI 
#define     rx_block_lock_timeout_sel_8192ui                  0x0400     //Sets block lock timeout value.   8192 UI 
#define     rx_block_lock_timeout_sel_16384ui                 0x0500     //Sets block lock timeout value.   16384 UI 
#define     rx_block_lock_timeout_sel_32768ui                 0x0600     //Sets block lock timeout value.   32768 UI 
#define     rx_block_lock_timeout_sel_infinite                0x0700     //Sets block lock timeout value.   Infinite
#define     rx_block_lock_timeout_sel_clear                   0xF8FF     // Clear mask
#define     rx_bit_lock_timeout_sel_512ui                     0x0020     //Sets bit lock/edge detect timeout value.   512 UI 
#define     rx_bit_lock_timeout_sel_1024ui                    0x0040     //Sets bit lock/edge detect timeout value.   1024 UI 
#define     rx_bit_lock_timeout_sel_2048ui                    0x0060     //Sets bit lock/edge detect timeout value.   2048 UI 
#define     rx_bit_lock_timeout_sel_4096ui                    0x0080     //Sets bit lock/edge detect timeout value.   4096 UI 
#define     rx_bit_lock_timeout_sel_8192ui                    0x00A0     //Sets bit lock/edge detect timeout value.   8192 UI 
#define     rx_bit_lock_timeout_sel_16384ui                   0x00C0     //Sets bit lock/edge detect timeout value.   16384 UI 
#define     rx_bit_lock_timeout_sel_infinite                  0x00E0     //Sets bit lock/edge detect timeout value.   Infinite
#define     rx_bit_lock_timeout_sel_clear                     0x1F1F     // Clear mask

// rx_cntl_pp Register field name                                       data value   Description
#define     rx_prbs_check_sync                                0x4000     //Enables checking for the 12 ui scramble sync pattern. 
#define     rx_prbs_check_sync_clear                          0xBFFF     // Clear mask
#define     rx_enable_reduced_scramble                        0x2000     //Enables reduced density of scramble pattern. 
#define     rx_enable_reduced_scramble_clear                  0xDFFF     // Clear mask
#define     rx_prbs_inc                                       0x1000     //Shift the PRBS pattern forward in time by one extra local cycle (4ui for EDI, 2ui for EI4).
#define     rx_prbs_inc_clear                                 0xEFFF     // Clear mask
#define     rx_prbs_dec                                       0x0800     //Shift the PRBS pattern back in time by holding it one local cycle (4ui for EDI, 2ui for EI4).
#define     rx_prbs_dec_clear                                 0xF7FF     // Clear mask

// rx_dyn_recal_timeouts_pp Register field name                         data value   Description
#define     rx_dyn_recal_interval_timeout_sel_tap1            0x1000     //RX Dynamic Recalibration Interval Timeout Selects  16kUI or 1.7us
#define     rx_dyn_recal_interval_timeout_sel_tap2            0x2000     //RX Dynamic Recalibration Interval Timeout Selects  32kUI or 3.4us
#define     rx_dyn_recal_interval_timeout_sel_tap3            0x3000     //RX Dynamic Recalibration Interval Timeout Selects  64kUI or 6.8us
#define     rx_dyn_recal_interval_timeout_sel_tap4            0x4000     //RX Dynamic Recalibration Interval Timeout Selects  128kUI or 106.5ns
#define     rx_dyn_recal_interval_timeout_sel_tap5            0x5000     //RX Dynamic Recalibration Interval Timeout Selects  256kUI or 1.7us
#define     rx_dyn_recal_interval_timeout_sel_tap6            0x6000     //RX Dynamic Recalibration Interval Timeout Selects  8192kUI or 872.4us
#define     rx_dyn_recal_interval_timeout_sel_tap7            0x7000     //RX Dynamic Recalibration Interval Timeout Selects  infinite
#define     rx_dyn_recal_interval_timeout_sel_clear           0x8FFF     // Clear mask
#define     rx_dyn_recal_status_rpt_timeout_sel_tap1          0x0400     //RX Dynamic Recalibration Status Reporting Timeout Selects  1024UI or 106.5ns
#define     rx_dyn_recal_status_rpt_timeout_sel_tap2          0x0800     //RX Dynamic Recalibration Status Reporting Timeout Selects  2048UI or 212.9ns
#define     rx_dyn_recal_status_rpt_timeout_sel_tap3          0x0C00     //RX Dynamic Recalibration Status Reporting Timeout Selects  4096UI or 426.0ns
#define     rx_dyn_recal_status_rpt_timeout_sel_clear         0xF3FF     // Clear mask

// rx_mode2_pp Register field name                                      data value   Description
#define     rx_bist_jitter_pulse_ctl_0                        0x4000     //Jitter Select  (steps8
#define     rx_bist_jitter_pulse_ctl_1                        0x8000     //Jitter Select  (steps2
#define     rx_bist_jitter_pulse_ctl_2                        0xC000     //Jitter Select  (steps0
#define     rx_bist_jitter_pulse_ctl_clear                    0x3FFF     // Clear mask
#define     rx_bist_min_eye_width                             0x0000     //Sets the minimum eye width value considered acceptable by PHYBIST.
#define     rx_bist_min_eye_width_clear                       0xE07F     // Clear mask

// rx_ber_cntl_pp Register field name                                   data value   Description
#define     rx_ber_en                                         0x8000     //Per-Pack (PP) Diagnostic Bit Error Rate (BER) error checking enable control. When 1 enables error checking. When 0 the error checking is disabled. This control enables the BER timer as well as enables the error checker and BER counters. The assumption is that the driver(s) are currently driving PRBS23 and the link has been trained before enabling BER checking.
#define     rx_ber_en_clear                                   0x7FFF     // Clear mask
#define     rx_ber_count_clr                                  0x4000     //PP Diag BER error counter clear pulse. When written to a 1 the per-lane error counters are cleared to all zeroes. Writing both this bit and the timer clear bit to a 1 will clear both and allow a new set of measurements to be run.
#define     rx_ber_count_clr_clear                            0xBFFF     // Clear mask
#define     rx_ber_timer_clr                                  0x2000     //PP Diag BER timer clear pulse. When written to a 1 the per-pack timers are cleared to all zeroes. Writing both this bit and the error counter clear bit to a 1 will clear both and allow a new set of measurements to be run.
#define     rx_ber_timer_clr_clear                            0xDFFF     // Clear mask

// rx_ber_mode_pp Register field name                                   data value   Description
#define     rx_ber_timer_freeze_en                            0x8000     //Per-Pack (PP) Diagnostic Bit Error Rate (BER) Timer freeze enable. When set to a 1 the per-pack timer is frozen when any lane error count saturates in that pack.
#define     rx_ber_timer_freeze_en_clear                      0x7FFF     // Clear mask
#define     rx_ber_count_freeze_en                            0x4000     //PP Diag BER Lane Error Counter freeze enable. When set to a 1 the per-lane error counters are frozen when the timer saturates in that pack.
#define     rx_ber_count_freeze_en_clear                      0xBFFF     // Clear mask
#define     rx_ber_count_sel_2                                0x0400     //PP Diag BER Lane Error Counter saturation select. Selects the number of errors that will saturate the counter and cause a freeze event.   2
#define     rx_ber_count_sel_4                                0x0800     //PP Diag BER Lane Error Counter saturation select. Selects the number of errors that will saturate the counter and cause a freeze event.   4
#define     rx_ber_count_sel_8                                0x0C00     //PP Diag BER Lane Error Counter saturation select. Selects the number of errors that will saturate the counter and cause a freeze event.   8
#define     rx_ber_count_sel_16                               0x1000     //PP Diag BER Lane Error Counter saturation select. Selects the number of errors that will saturate the counter and cause a freeze event.   16
#define     rx_ber_count_sel_32                               0x1400     //PP Diag BER Lane Error Counter saturation select. Selects the number of errors that will saturate the counter and cause a freeze event.   32
#define     rx_ber_count_sel_64                               0x1800     //PP Diag BER Lane Error Counter saturation select. Selects the number of errors that will saturate the counter and cause a freeze event.   64
#define     rx_ber_count_sel_128                              0x1C00     //PP Diag BER Lane Error Counter saturation select. Selects the number of errors that will saturate the counter and cause a freeze event.   128
#define     rx_ber_count_sel_clear                            0xE3FF     // Clear mask
#define     rx_ber_timer_sel_2tothe36th                       0x0080     //PP Diag BER Timer saturation select. Selects the timer value that will saturate the timer and cause a freeze event.   2^36
#define     rx_ber_timer_sel_2tothe32nd                       0x0100     //PP Diag BER Timer saturation select. Selects the timer value that will saturate the timer and cause a freeze event.   2^32
#define     rx_ber_timer_sel_2tothe28th                       0x0180     //PP Diag BER Timer saturation select. Selects the timer value that will saturate the timer and cause a freeze event.   2^28
#define     rx_ber_timer_sel_2tothe24th                       0x0200     //PP Diag BER Timer saturation select. Selects the timer value that will saturate the timer and cause a freeze event.   2^24
#define     rx_ber_timer_sel_2tothe20th                       0x0280     //PP Diag BER Timer saturation select. Selects the timer value that will saturate the timer and cause a freeze event.   2^20
#define     rx_ber_timer_sel_2tothe16th                       0x0300     //PP Diag BER Timer saturation select. Selects the timer value that will saturate the timer and cause a freeze event.   2^16
#define     rx_ber_timer_sel_2tothe12th                       0x0380     //PP Diag BER Timer saturation select. Selects the timer value that will saturate the timer and cause a freeze event.   2^12
#define     rx_ber_timer_sel_clear                            0xFC7F     // Clear mask
#define     rx_ber_clr_count_on_read_en                       0x0040     //PP Diag BER Lane Error Counter clear on read. When set to a 1 this enables the clearing of a lanes error counter when it is read.
#define     rx_ber_clr_count_on_read_en_clear                 0xFFBF     // Clear mask
#define     rx_ber_clr_timer_on_read_en                       0x0020     //PP Diag BER Timer clear on read. When set to a 1 this enables the clearing of a lanes per-pack timer when it is read from any lane in the pack.
#define     rx_ber_clr_timer_on_read_en_clear                 0xFFDF     // Clear mask

// rx_servo_to1_pp Register field name                                  data value   Description
#define     rx_servo_timeout_sel_A_512ui                      0x1000     //RX servo operation timeout A.  512 UI 
#define     rx_servo_timeout_sel_A_1Kui                       0x2000     //RX servo operation timeout A.  1K UI 
#define     rx_servo_timeout_sel_A_2Kui                       0x3000     //RX servo operation timeout A.  2K UI 
#define     rx_servo_timeout_sel_A_4Kui                       0x4000     //RX servo operation timeout A.  4096 UI 
#define     rx_servo_timeout_sel_A_8Kui                       0x5000     //RX servo operation timeout A.  8K UI 
#define     rx_servo_timeout_sel_A_16Kui                      0x6000     //RX servo operation timeout A.  16K UI 
#define     rx_servo_timeout_sel_A_32Kui                      0x7000     //RX servo operation timeout A.  32K UI 
#define     rx_servo_timeout_sel_A_64Kui                      0x8000     //RX servo operation timeout A.  64K UI 
#define     rx_servo_timeout_sel_A_128Kui                     0x9000     //RX servo operation timeout A.  128K UI 
#define     rx_servo_timeout_sel_A_256Kui                     0xA000     //RX servo operation timeout A.  256K UI 
#define     rx_servo_timeout_sel_A_512Kui                     0xB000     //RX servo operation timeout A.  512K UI 
#define     rx_servo_timeout_sel_A_1Mui                       0xC000     //RX servo operation timeout A.  1M UI 
#define     rx_servo_timeout_sel_A_2Mui                       0xD000     //RX servo operation timeout A.  2M UI 
#define     rx_servo_timeout_sel_A_4Mui                       0xE000     //RX servo operation timeout A.  4M UI
#define     rx_servo_timeout_sel_A_Infinite                   0xF000     //RX servo operation timeout A.  Infinite
#define     rx_servo_timeout_sel_A_clear                      0x0FFF     // Clear mask
#define     rx_servo_timeout_sel_B_512ui                      0x0100     //RX servo operation timeout B.  512 UI 
#define     rx_servo_timeout_sel_B_1Kui                       0x0200     //RX servo operation timeout B.  1K UI 
#define     rx_servo_timeout_sel_B_2Kui                       0x0300     //RX servo operation timeout B.  2K UI 
#define     rx_servo_timeout_sel_B_4Kui                       0x0400     //RX servo operation timeout B.  4096 UI 
#define     rx_servo_timeout_sel_B_8Kui                       0x0500     //RX servo operation timeout B.  8K UI 
#define     rx_servo_timeout_sel_B_16Kui                      0x0600     //RX servo operation timeout B.  16K UI 
#define     rx_servo_timeout_sel_B_32Kui                      0x0700     //RX servo operation timeout B.  32K UI 
#define     rx_servo_timeout_sel_B_64Kui                      0x0800     //RX servo operation timeout B.  64K UI 
#define     rx_servo_timeout_sel_B_128Kui                     0x0900     //RX servo operation timeout B.  128K UI 
#define     rx_servo_timeout_sel_B_256Kui                     0x0A00     //RX servo operation timeout B.  256K UI 
#define     rx_servo_timeout_sel_B_512Kui                     0x0B00     //RX servo operation timeout B.  512K UI 
#define     rx_servo_timeout_sel_B_1Mui                       0x0C00     //RX servo operation timeout B.  1M UI 
#define     rx_servo_timeout_sel_B_2Mui                       0x0D00     //RX servo operation timeout B.  2M UI 
#define     rx_servo_timeout_sel_B_4Mui                       0x0E00     //RX servo operation timeout B.  4M UI
#define     rx_servo_timeout_sel_B_Infinite                   0x0F00     //RX servo operation timeout B.  Infinite
#define     rx_servo_timeout_sel_B_clear                      0xF0FF     // Clear mask
#define     rx_servo_timeout_sel_C_512ui                      0x0010     //RX servo operation timeout C.  512 UI 
#define     rx_servo_timeout_sel_C_1Kui                       0x0020     //RX servo operation timeout C.  1K UI 
#define     rx_servo_timeout_sel_C_2Kui                       0x0030     //RX servo operation timeout C.  2K UI 
#define     rx_servo_timeout_sel_C_4Kui                       0x0040     //RX servo operation timeout C.  4096 UI 
#define     rx_servo_timeout_sel_C_8Kui                       0x0050     //RX servo operation timeout C.  8K UI 
#define     rx_servo_timeout_sel_C_16Kui                      0x0060     //RX servo operation timeout C.  16K UI 
#define     rx_servo_timeout_sel_C_32Kui                      0x0070     //RX servo operation timeout C.  32K UI 
#define     rx_servo_timeout_sel_C_64Kui                      0x0080     //RX servo operation timeout C.  64K UI 
#define     rx_servo_timeout_sel_C_128Kui                     0x0090     //RX servo operation timeout C.  128K UI 
#define     rx_servo_timeout_sel_C_256Kui                     0x00A0     //RX servo operation timeout C.  256K UI 
#define     rx_servo_timeout_sel_C_512Kui                     0x00B0     //RX servo operation timeout C.  512K UI 
#define     rx_servo_timeout_sel_C_1Mui                       0x00C0     //RX servo operation timeout C.  1M UI 
#define     rx_servo_timeout_sel_C_2Mui                       0x00D0     //RX servo operation timeout C.  2M UI 
#define     rx_servo_timeout_sel_C_4Mui                       0x00E0     //RX servo operation timeout C.  4M UI
#define     rx_servo_timeout_sel_C_Infinite                   0x00F0     //RX servo operation timeout C.  Infinite
#define     rx_servo_timeout_sel_C_clear                      0x0F0F     // Clear mask
#define     rx_servo_timeout_sel_D_512ui                      0x0001     //RX servo operation timeout D.  512 UI 
#define     rx_servo_timeout_sel_D_1Kui                       0x0002     //RX servo operation timeout D.  1K UI 
#define     rx_servo_timeout_sel_D_2Kui                       0x0003     //RX servo operation timeout D.  2K UI 
#define     rx_servo_timeout_sel_D_4Kui                       0x0004     //RX servo operation timeout D.  4096 UI 
#define     rx_servo_timeout_sel_D_8Kui                       0x0005     //RX servo operation timeout D.  8K UI 
#define     rx_servo_timeout_sel_D_16Kui                      0x0006     //RX servo operation timeout D.  16K UI 
#define     rx_servo_timeout_sel_D_32Kui                      0x0007     //RX servo operation timeout D.  32K UI 
#define     rx_servo_timeout_sel_D_64Kui                      0x0008     //RX servo operation timeout D.  64K UI 
#define     rx_servo_timeout_sel_D_128Kui                     0x0009     //RX servo operation timeout D.  128K UI 
#define     rx_servo_timeout_sel_D_256Kui                     0x000A     //RX servo operation timeout D.  256K UI 
#define     rx_servo_timeout_sel_D_512Kui                     0x000B     //RX servo operation timeout D.  512K UI 
#define     rx_servo_timeout_sel_D_1Mui                       0x000C     //RX servo operation timeout D.  1M UI 
#define     rx_servo_timeout_sel_D_2Mui                       0x000D     //RX servo operation timeout D.  2M UI 
#define     rx_servo_timeout_sel_D_4Mui                       0x000E     //RX servo operation timeout D.  4M UI
#define     rx_servo_timeout_sel_D_Infinite                   0x000F     //RX servo operation timeout D.  Infinite
#define     rx_servo_timeout_sel_D_clear                      0xFF00     // Clear mask

// rx_servo_to2_pp Register field name                                  data value   Description
#define     rx_servo_timeout_sel_E_512ui                      0x1000     //RX servo operation timeout E.  512 UI 
#define     rx_servo_timeout_sel_E_1Kui                       0x2000     //RX servo operation timeout E.  1K UI 
#define     rx_servo_timeout_sel_E_2Kui                       0x3000     //RX servo operation timeout E.  2K UI 
#define     rx_servo_timeout_sel_E_4Kui                       0x4000     //RX servo operation timeout E.  4096 UI 
#define     rx_servo_timeout_sel_E_8Kui                       0x5000     //RX servo operation timeout E.  8K UI 
#define     rx_servo_timeout_sel_E_16Kui                      0x6000     //RX servo operation timeout E.  16K UI 
#define     rx_servo_timeout_sel_E_32Kui                      0x7000     //RX servo operation timeout E.  32K UI 
#define     rx_servo_timeout_sel_E_64Kui                      0x8000     //RX servo operation timeout E.  64K UI 
#define     rx_servo_timeout_sel_E_128Kui                     0x9000     //RX servo operation timeout E.  128K UI 
#define     rx_servo_timeout_sel_E_256Kui                     0xA000     //RX servo operation timeout E.  256K UI 
#define     rx_servo_timeout_sel_E_512Kui                     0xB000     //RX servo operation timeout E.  512K UI 
#define     rx_servo_timeout_sel_E_1Mui                       0xC000     //RX servo operation timeout E.  1M UI 
#define     rx_servo_timeout_sel_E_2Mui                       0xD000     //RX servo operation timeout E.  2M UI 
#define     rx_servo_timeout_sel_E_4Mui                       0xE000     //RX servo operation timeout E.  4M UI
#define     rx_servo_timeout_sel_E_Infinite                   0xF000     //RX servo operation timeout E.  Infinite
#define     rx_servo_timeout_sel_E_clear                      0x0FFF     // Clear mask
#define     rx_servo_timeout_sel_F_512ui                      0x0100     //RX servo operation timeout F.  512 UI 
#define     rx_servo_timeout_sel_F_1Kui                       0x0200     //RX servo operation timeout F.  1K UI 
#define     rx_servo_timeout_sel_F_2Kui                       0x0300     //RX servo operation timeout F.  2K UI 
#define     rx_servo_timeout_sel_F_4Kui                       0x0400     //RX servo operation timeout F.  4096 UI 
#define     rx_servo_timeout_sel_F_8Kui                       0x0500     //RX servo operation timeout F.  8K UI 
#define     rx_servo_timeout_sel_F_16Kui                      0x0600     //RX servo operation timeout F.  16K UI 
#define     rx_servo_timeout_sel_F_32Kui                      0x0700     //RX servo operation timeout F.  32K UI 
#define     rx_servo_timeout_sel_F_64Kui                      0x0800     //RX servo operation timeout F.  64K UI 
#define     rx_servo_timeout_sel_F_128Kui                     0x0900     //RX servo operation timeout F.  128K UI 
#define     rx_servo_timeout_sel_F_256Kui                     0x0A00     //RX servo operation timeout F.  256K UI 
#define     rx_servo_timeout_sel_F_512Kui                     0x0B00     //RX servo operation timeout F.  512K UI 
#define     rx_servo_timeout_sel_F_1Mui                       0x0C00     //RX servo operation timeout F.  1M UI 
#define     rx_servo_timeout_sel_F_2Mui                       0x0D00     //RX servo operation timeout F.  2M UI 
#define     rx_servo_timeout_sel_F_4Mui                       0x0E00     //RX servo operation timeout F.  4M UI
#define     rx_servo_timeout_sel_F_Infinite                   0x0F00     //RX servo operation timeout F.  Infinite
#define     rx_servo_timeout_sel_F_clear                      0xF0FF     // Clear mask
#define     rx_servo_timeout_sel_G_512ui                      0x0010     //RX servo operation timeout G.  512 UI 
#define     rx_servo_timeout_sel_G_1Kui                       0x0020     //RX servo operation timeout G.  1K UI 
#define     rx_servo_timeout_sel_G_2Kui                       0x0030     //RX servo operation timeout G.  2K UI 
#define     rx_servo_timeout_sel_G_4Kui                       0x0040     //RX servo operation timeout G.  4096 UI 
#define     rx_servo_timeout_sel_G_8Kui                       0x0050     //RX servo operation timeout G.  8K UI 
#define     rx_servo_timeout_sel_G_16Kui                      0x0060     //RX servo operation timeout G.  16K UI 
#define     rx_servo_timeout_sel_G_32Kui                      0x0070     //RX servo operation timeout G.  32K UI 
#define     rx_servo_timeout_sel_G_64Kui                      0x0080     //RX servo operation timeout G.  64K UI 
#define     rx_servo_timeout_sel_G_128Kui                     0x0090     //RX servo operation timeout G.  128K UI 
#define     rx_servo_timeout_sel_G_256Kui                     0x00A0     //RX servo operation timeout G.  256K UI 
#define     rx_servo_timeout_sel_G_512Kui                     0x00B0     //RX servo operation timeout G.  512K UI 
#define     rx_servo_timeout_sel_G_1Mui                       0x00C0     //RX servo operation timeout G.  1M UI 
#define     rx_servo_timeout_sel_G_2Mui                       0x00D0     //RX servo operation timeout G.  2M UI 
#define     rx_servo_timeout_sel_G_4Mui                       0x00E0     //RX servo operation timeout G.  4M UI
#define     rx_servo_timeout_sel_G_Infinite                   0x00F0     //RX servo operation timeout G.  Infinite
#define     rx_servo_timeout_sel_G_clear                      0x0F0F     // Clear mask
#define     rx_servo_timeout_sel_H_512ui                      0x0001     //RX servo operation timeout H.  512 UI 
#define     rx_servo_timeout_sel_H_1Kui                       0x0002     //RX servo operation timeout H.  1K UI 
#define     rx_servo_timeout_sel_H_2Kui                       0x0003     //RX servo operation timeout H.  2K UI 
#define     rx_servo_timeout_sel_H_4Kui                       0x0004     //RX servo operation timeout H.  4096 UI 
#define     rx_servo_timeout_sel_H_8Kui                       0x0005     //RX servo operation timeout H.  8K UI 
#define     rx_servo_timeout_sel_H_16Kui                      0x0006     //RX servo operation timeout H.  16K UI 
#define     rx_servo_timeout_sel_H_32Kui                      0x0007     //RX servo operation timeout H.  32K UI 
#define     rx_servo_timeout_sel_H_64Kui                      0x0008     //RX servo operation timeout H.  64K UI 
#define     rx_servo_timeout_sel_H_128Kui                     0x0009     //RX servo operation timeout H.  128K UI 
#define     rx_servo_timeout_sel_H_256Kui                     0x000A     //RX servo operation timeout H.  256K UI 
#define     rx_servo_timeout_sel_H_512Kui                     0x000B     //RX servo operation timeout H.  512K UI 
#define     rx_servo_timeout_sel_H_1Mui                       0x000C     //RX servo operation timeout H.  1M UI 
#define     rx_servo_timeout_sel_H_2Mui                       0x000D     //RX servo operation timeout H.  2M UI 
#define     rx_servo_timeout_sel_H_4Mui                       0x000E     //RX servo operation timeout H.  4M UI
#define     rx_servo_timeout_sel_H_Infinite                   0x000F     //RX servo operation timeout H.  Infinite
#define     rx_servo_timeout_sel_H_clear                      0xFF00     // Clear mask

// rx_servo_to3_pp Register field name                                  data value   Description
#define     rx_servo_timeout_sel_I_512ui                      0x1000     //RX servo operation timeout I.  512 UI 
#define     rx_servo_timeout_sel_I_1Kui                       0x2000     //RX servo operation timeout I.  1K UI 
#define     rx_servo_timeout_sel_I_2Kui                       0x3000     //RX servo operation timeout I.  2K UI 
#define     rx_servo_timeout_sel_I_4Kui                       0x4000     //RX servo operation timeout I.  4096 UI 
#define     rx_servo_timeout_sel_I_8Kui                       0x5000     //RX servo operation timeout I.  8K UI 
#define     rx_servo_timeout_sel_I_16Kui                      0x6000     //RX servo operation timeout I.  16K UI 
#define     rx_servo_timeout_sel_I_32Kui                      0x7000     //RX servo operation timeout I.  32K UI 
#define     rx_servo_timeout_sel_I_64Kui                      0x8000     //RX servo operation timeout I.  64K UI 
#define     rx_servo_timeout_sel_I_128Kui                     0x9000     //RX servo operation timeout I.  128K UI 
#define     rx_servo_timeout_sel_I_256Kui                     0xA000     //RX servo operation timeout I.  256K UI 
#define     rx_servo_timeout_sel_I_512Kui                     0xB000     //RX servo operation timeout I.  512K UI 
#define     rx_servo_timeout_sel_I_1Mui                       0xC000     //RX servo operation timeout I.  1M UI 
#define     rx_servo_timeout_sel_I_2Mui                       0xD000     //RX servo operation timeout I.  2M UI 
#define     rx_servo_timeout_sel_I_4Mui                       0xE000     //RX servo operation timeout I.  4M UI
#define     rx_servo_timeout_sel_I_Infinite                   0xF000     //RX servo operation timeout I.  Infinite
#define     rx_servo_timeout_sel_I_clear                      0x0FFF     // Clear mask
#define     rx_servo_timeout_sel_J_512ui                      0x0100     //RX servo operation timeout J.  512 UI 
#define     rx_servo_timeout_sel_J_1Kui                       0x0200     //RX servo operation timeout J.  1K UI 
#define     rx_servo_timeout_sel_J_2Kui                       0x0300     //RX servo operation timeout J.  2K UI 
#define     rx_servo_timeout_sel_J_4Kui                       0x0400     //RX servo operation timeout J.  4096 UI 
#define     rx_servo_timeout_sel_J_8Kui                       0x0500     //RX servo operation timeout J.  8K UI 
#define     rx_servo_timeout_sel_J_16Kui                      0x0600     //RX servo operation timeout J.  16K UI 
#define     rx_servo_timeout_sel_J_32Kui                      0x0700     //RX servo operation timeout J.  32K UI 
#define     rx_servo_timeout_sel_J_64Kui                      0x0800     //RX servo operation timeout J.  64K UI 
#define     rx_servo_timeout_sel_J_128Kui                     0x0900     //RX servo operation timeout J.  128K UI 
#define     rx_servo_timeout_sel_J_256Kui                     0x0A00     //RX servo operation timeout J.  256K UI 
#define     rx_servo_timeout_sel_J_512Kui                     0x0B00     //RX servo operation timeout J.  512K UI 
#define     rx_servo_timeout_sel_J_1Mui                       0x0C00     //RX servo operation timeout J.  1M UI 
#define     rx_servo_timeout_sel_J_2Mui                       0x0D00     //RX servo operation timeout J.  2M UI 
#define     rx_servo_timeout_sel_J_4Mui                       0x0E00     //RX servo operation timeout J.  4M UI
#define     rx_servo_timeout_sel_J_Infinite                   0x0F00     //RX servo operation timeout J.  Infinite
#define     rx_servo_timeout_sel_J_clear                      0xF0FF     // Clear mask
#define     rx_servo_timeout_sel_K_512ui                      0x0010     //RX servo operation timeout K.  512 UI 
#define     rx_servo_timeout_sel_K_1Kui                       0x0020     //RX servo operation timeout K.  1K UI 
#define     rx_servo_timeout_sel_K_2Kui                       0x0030     //RX servo operation timeout K.  2K UI 
#define     rx_servo_timeout_sel_K_4Kui                       0x0040     //RX servo operation timeout K.  4096 UI 
#define     rx_servo_timeout_sel_K_8Kui                       0x0050     //RX servo operation timeout K.  8K UI 
#define     rx_servo_timeout_sel_K_16Kui                      0x0060     //RX servo operation timeout K.  16K UI 
#define     rx_servo_timeout_sel_K_32Kui                      0x0070     //RX servo operation timeout K.  32K UI 
#define     rx_servo_timeout_sel_K_64Kui                      0x0080     //RX servo operation timeout K.  64K UI 
#define     rx_servo_timeout_sel_K_128Kui                     0x0090     //RX servo operation timeout K.  128K UI 
#define     rx_servo_timeout_sel_K_256Kui                     0x00A0     //RX servo operation timeout K.  256K UI 
#define     rx_servo_timeout_sel_K_512Kui                     0x00B0     //RX servo operation timeout K.  512K UI 
#define     rx_servo_timeout_sel_K_1Mui                       0x00C0     //RX servo operation timeout K.  1M UI 
#define     rx_servo_timeout_sel_K_2Mui                       0x00D0     //RX servo operation timeout K.  2M UI 
#define     rx_servo_timeout_sel_K_4Mui                       0x00E0     //RX servo operation timeout K.  4M UI
#define     rx_servo_timeout_sel_K_Infinite                   0x00F0     //RX servo operation timeout K.  Infinite
#define     rx_servo_timeout_sel_K_clear                      0x0F0F     // Clear mask
#define     rx_servo_timeout_sel_L_512ui                      0x0001     //RX servo operation timeout L.  512 UI 
#define     rx_servo_timeout_sel_L_1Kui                       0x0002     //RX servo operation timeout L.  1K UI 
#define     rx_servo_timeout_sel_L_2Kui                       0x0003     //RX servo operation timeout L.  2K UI 
#define     rx_servo_timeout_sel_L_4Kui                       0x0004     //RX servo operation timeout L.  4096 UI 
#define     rx_servo_timeout_sel_L_8Kui                       0x0005     //RX servo operation timeout L.  8K UI 
#define     rx_servo_timeout_sel_L_16Kui                      0x0006     //RX servo operation timeout L.  16K UI 
#define     rx_servo_timeout_sel_L_32Kui                      0x0007     //RX servo operation timeout L.  32K UI 
#define     rx_servo_timeout_sel_L_64Kui                      0x0008     //RX servo operation timeout L.  64K UI 
#define     rx_servo_timeout_sel_L_128Kui                     0x0009     //RX servo operation timeout L.  128K UI 
#define     rx_servo_timeout_sel_L_256Kui                     0x000A     //RX servo operation timeout L.  256K UI 
#define     rx_servo_timeout_sel_L_512Kui                     0x000B     //RX servo operation timeout L.  512K UI 
#define     rx_servo_timeout_sel_L_1Mui                       0x000C     //RX servo operation timeout L.  1M UI 
#define     rx_servo_timeout_sel_L_2Mui                       0x000D     //RX servo operation timeout L.  2M UI 
#define     rx_servo_timeout_sel_L_4Mui                       0x000E     //RX servo operation timeout L.  4M UI
#define     rx_servo_timeout_sel_L_Infinite                   0x000F     //RX servo operation timeout L.  Infinite
#define     rx_servo_timeout_sel_L_clear                      0xFF00     // Clear mask

// rx_dfe_config_pp Register field name                                 data value   Description
#define     rx_peak_cfg                                       0x0000     //RX DFE Peaking settings
#define     rx_peak_cfg_clear                                 0x3FFF     // Clear mask
#define     rx_amin_cfg                                       0x0000     //RX DFE Amin settings
#define     rx_amin_cfg_clear                                 0xC7FF     // Clear mask
#define     rx_anap_cfg                                       0x0000     //RX DFE An-Ap settings
#define     rx_anap_cfg_clear                                 0xF9FF     // Clear mask
#define     rx_h1_cfg                                         0x0000     //RX DFE H1 settings
#define     rx_h1_cfg_clear                                   0xFE7F     // Clear mask
#define     rx_h1ap_cfg                                       0x0000     //RX DFE H1 over Ap settings
#define     rx_h1ap_cfg_clear                                 0x3F8F     // Clear mask
#define     rx_dfe_ca_cfg                                     0x0000     //RX DFE clock adjust settings
#define     rx_dfe_ca_cfg_clear                               0xF8F3     // Clear mask
#define     rx_spmux_cfg                                      0x0000     //RX DFE speculation mux toggle settings
#define     rx_spmux_cfg_clear                                0xE3CC     // Clear mask

// rx_dfe_timers_pp Register field name                                 data value   Description
#define     rx_init_tmr_cfg                                   0x0000     //RX clock init timer settings
#define     rx_init_tmr_cfg_clear                             0x1FFF     // Clear mask
#define     rx_ber_cfg                                        0x0000     //RX DDC Bit error rate timer settings
#define     rx_ber_cfg_clear                                  0xE3FF     // Clear mask
#define     rx_fifo_dly_cfg                                   0x0000     //RX Fifo Delay Blackout settings
#define     rx_fifo_dly_cfg_clear                             0xFCFF     // Clear mask
#define     rx_ddc_cfg                                        0x0000     //RX DDC config settings
#define     rx_ddc_cfg_clear                                  0xFF3F     // Clear mask
#define     rx_dac_bo_cfg                                     0x0000     //RX DAC black out period settings
#define     rx_dac_bo_cfg_clear                               0xCFC7     // Clear mask
#define     rx_prot_cfg                                       0x0000     //RX phase rotator filter settings
#define     rx_prot_cfg_clear                                 0x7E39     // Clear mask

// rx_reset_cfg_pp Register field name                                  data value   Description
#define     rx_reset_cfg_hld_clear                            0x0000     // Clear mask

// rx_recal_to1_pp Register field name                                  data value   Description
#define     rx_recal_timeout_sel_A_512ui                      0x1000     //RX recal servo operation timeout A.  512 UI 
#define     rx_recal_timeout_sel_A_1Kui                       0x2000     //RX recal servo operation timeout A.  1K UI 
#define     rx_recal_timeout_sel_A_2Kui                       0x3000     //RX recal servo operation timeout A.  2K UI 
#define     rx_recal_timeout_sel_A_4Kui                       0x4000     //RX recal servo operation timeout A.  4096 UI 
#define     rx_recal_timeout_sel_A_8Kui                       0x5000     //RX recal servo operation timeout A.  8K UI 
#define     rx_recal_timeout_sel_A_16Kui                      0x6000     //RX recal servo operation timeout A.  16K UI 
#define     rx_recal_timeout_sel_A_32Kui                      0x7000     //RX recal servo operation timeout A.  32K UI 
#define     rx_recal_timeout_sel_A_64Kui                      0x8000     //RX recal servo operation timeout A.  64K UI 
#define     rx_recal_timeout_sel_A_128Kui                     0x9000     //RX recal servo operation timeout A.  128K UI 
#define     rx_recal_timeout_sel_A_256Kui                     0xA000     //RX recal servo operation timeout A.  256K UI 
#define     rx_recal_timeout_sel_A_512Kui                     0xB000     //RX recal servo operation timeout A.  512K UI 
#define     rx_recal_timeout_sel_A_1Mui                       0xC000     //RX recal servo operation timeout A.  1M UI 
#define     rx_recal_timeout_sel_A_2Mui                       0xD000     //RX recal servo operation timeout A.  2M UI 
#define     rx_recal_timeout_sel_A_4Mui                       0xE000     //RX recal servo operation timeout A.  4M UI
#define     rx_recal_timeout_sel_A_Infinite                   0xF000     //RX recal servo operation timeout A.  Infinite
#define     rx_recal_timeout_sel_A_clear                      0x0FFF     // Clear mask
#define     rx_recal_timeout_sel_B_512ui                      0x0100     //RX recal servo operation timeout B.  512 UI 
#define     rx_recal_timeout_sel_B_1Kui                       0x0200     //RX recal servo operation timeout B.  1K UI 
#define     rx_recal_timeout_sel_B_2Kui                       0x0300     //RX recal servo operation timeout B.  2K UI 
#define     rx_recal_timeout_sel_B_4Kui                       0x0400     //RX recal servo operation timeout B.  4096 UI 
#define     rx_recal_timeout_sel_B_8Kui                       0x0500     //RX recal servo operation timeout B.  8K UI 
#define     rx_recal_timeout_sel_B_16Kui                      0x0600     //RX recal servo operation timeout B.  16K UI 
#define     rx_recal_timeout_sel_B_32Kui                      0x0700     //RX recal servo operation timeout B.  32K UI 
#define     rx_recal_timeout_sel_B_64Kui                      0x0800     //RX recal servo operation timeout B.  64K UI 
#define     rx_recal_timeout_sel_B_128Kui                     0x0900     //RX recal servo operation timeout B.  128K UI 
#define     rx_recal_timeout_sel_B_256Kui                     0x0A00     //RX recal servo operation timeout B.  256K UI 
#define     rx_recal_timeout_sel_B_512Kui                     0x0B00     //RX recal servo operation timeout B.  512K UI 
#define     rx_recal_timeout_sel_B_1Mui                       0x0C00     //RX recal servo operation timeout B.  1M UI 
#define     rx_recal_timeout_sel_B_2Mui                       0x0D00     //RX recal servo operation timeout B.  2M UI 
#define     rx_recal_timeout_sel_B_4Mui                       0x0E00     //RX recal servo operation timeout B.  4M UI
#define     rx_recal_timeout_sel_B_Infinite                   0x0F00     //RX recal servo operation timeout B.  Infinite
#define     rx_recal_timeout_sel_B_clear                      0xF0FF     // Clear mask

// rx_recal_to2_pp Register field name                                  data value   Description
#define     rx_recal_timeout_sel_G_512ui                      0x0010     //RX recal servo operation timeout G.  512 UI 
#define     rx_recal_timeout_sel_G_1Kui                       0x0020     //RX recal servo operation timeout G.  1K UI 
#define     rx_recal_timeout_sel_G_2Kui                       0x0030     //RX recal servo operation timeout G.  2K UI 
#define     rx_recal_timeout_sel_G_4Kui                       0x0040     //RX recal servo operation timeout G.  4096 UI 
#define     rx_recal_timeout_sel_G_8Kui                       0x0050     //RX recal servo operation timeout G.  8K UI 
#define     rx_recal_timeout_sel_G_16Kui                      0x0060     //RX recal servo operation timeout G.  16K UI 
#define     rx_recal_timeout_sel_G_32Kui                      0x0070     //RX recal servo operation timeout G.  32K UI 
#define     rx_recal_timeout_sel_G_64Kui                      0x0080     //RX recal servo operation timeout G.  64K UI 
#define     rx_recal_timeout_sel_G_128Kui                     0x0090     //RX recal servo operation timeout G.  128K UI 
#define     rx_recal_timeout_sel_G_256Kui                     0x00A0     //RX recal servo operation timeout G.  256K UI 
#define     rx_recal_timeout_sel_G_512Kui                     0x00B0     //RX recal servo operation timeout G.  512K UI 
#define     rx_recal_timeout_sel_G_1Mui                       0x00C0     //RX recal servo operation timeout G.  1M UI 
#define     rx_recal_timeout_sel_G_2Mui                       0x00D0     //RX recal servo operation timeout G.  2M UI 
#define     rx_recal_timeout_sel_G_4Mui                       0x00E0     //RX recal servo operation timeout G.  4M UI
#define     rx_recal_timeout_sel_G_Infinite                   0x00F0     //RX recal servo operation timeout G.  Infinite
#define     rx_recal_timeout_sel_G_clear                      0x0F0F     // Clear mask
#define     rx_recal_timeout_sel_H_512ui                      0x0001     //RX recal servo operation timeout H.  512 UI 
#define     rx_recal_timeout_sel_H_1Kui                       0x0002     //RX recal servo operation timeout H.  1K UI 
#define     rx_recal_timeout_sel_H_2Kui                       0x0003     //RX recal servo operation timeout H.  2K UI 
#define     rx_recal_timeout_sel_H_4Kui                       0x0004     //RX recal servo operation timeout H.  4096 UI 
#define     rx_recal_timeout_sel_H_8Kui                       0x0005     //RX recal servo operation timeout H.  8K UI 
#define     rx_recal_timeout_sel_H_16Kui                      0x0006     //RX recal servo operation timeout H.  16K UI 
#define     rx_recal_timeout_sel_H_32Kui                      0x0007     //RX recal servo operation timeout H.  32K UI 
#define     rx_recal_timeout_sel_H_64Kui                      0x0008     //RX recal servo operation timeout H.  64K UI 
#define     rx_recal_timeout_sel_H_128Kui                     0x0009     //RX recal servo operation timeout H.  128K UI 
#define     rx_recal_timeout_sel_H_256Kui                     0x000A     //RX recal servo operation timeout H.  256K UI 
#define     rx_recal_timeout_sel_H_512Kui                     0x000B     //RX recal servo operation timeout H.  512K UI 
#define     rx_recal_timeout_sel_H_1Mui                       0x000C     //RX recal servo operation timeout H.  1M UI 
#define     rx_recal_timeout_sel_H_2Mui                       0x000D     //RX recal servo operation timeout H.  2M UI 
#define     rx_recal_timeout_sel_H_4Mui                       0x000E     //RX recal servo operation timeout H.  4M UI
#define     rx_recal_timeout_sel_H_Infinite                   0x000F     //RX recal servo operation timeout H.  Infinite
#define     rx_recal_timeout_sel_H_clear                      0xFF00     // Clear mask

// rx_recal_to3_pp Register field name                                  data value   Description
#define     rx_recal_timeout_sel_I_512ui                      0x1000     //RX recal servo operation timeout I.  512 UI 
#define     rx_recal_timeout_sel_I_1Kui                       0x2000     //RX recal servo operation timeout I.  1K UI 
#define     rx_recal_timeout_sel_I_2Kui                       0x3000     //RX recal servo operation timeout I.  2K UI 
#define     rx_recal_timeout_sel_I_4Kui                       0x4000     //RX recal servo operation timeout I.  4096 UI 
#define     rx_recal_timeout_sel_I_8Kui                       0x5000     //RX recal servo operation timeout I.  8K UI 
#define     rx_recal_timeout_sel_I_16Kui                      0x6000     //RX recal servo operation timeout I.  16K UI 
#define     rx_recal_timeout_sel_I_32Kui                      0x7000     //RX recal servo operation timeout I.  32K UI 
#define     rx_recal_timeout_sel_I_64Kui                      0x8000     //RX recal servo operation timeout I.  64K UI 
#define     rx_recal_timeout_sel_I_128Kui                     0x9000     //RX recal servo operation timeout I.  128K UI 
#define     rx_recal_timeout_sel_I_256Kui                     0xA000     //RX recal servo operation timeout I.  256K UI 
#define     rx_recal_timeout_sel_I_512Kui                     0xB000     //RX recal servo operation timeout I.  512K UI 
#define     rx_recal_timeout_sel_I_1Mui                       0xC000     //RX recal servo operation timeout I.  1M UI 
#define     rx_recal_timeout_sel_I_2Mui                       0xD000     //RX recal servo operation timeout I.  2M UI 
#define     rx_recal_timeout_sel_I_4Mui                       0xE000     //RX recal servo operation timeout I.  4M UI
#define     rx_recal_timeout_sel_I_Infinite                   0xF000     //RX recal servo operation timeout I.  Infinite
#define     rx_recal_timeout_sel_I_clear                      0x0FFF     // Clear mask
#define     rx_recal_timeout_sel_J_512ui                      0x0100     //RX recal servo operation timeout J.  512 UI 
#define     rx_recal_timeout_sel_J_1Kui                       0x0200     //RX recal servo operation timeout J.  1K UI 
#define     rx_recal_timeout_sel_J_2Kui                       0x0300     //RX recal servo operation timeout J.  2K UI 
#define     rx_recal_timeout_sel_J_4Kui                       0x0400     //RX recal servo operation timeout J.  4096 UI 
#define     rx_recal_timeout_sel_J_8Kui                       0x0500     //RX recal servo operation timeout J.  8K UI 
#define     rx_recal_timeout_sel_J_16Kui                      0x0600     //RX recal servo operation timeout J.  16K UI 
#define     rx_recal_timeout_sel_J_32Kui                      0x0700     //RX recal servo operation timeout J.  32K UI 
#define     rx_recal_timeout_sel_J_64Kui                      0x0800     //RX recal servo operation timeout J.  64K UI 
#define     rx_recal_timeout_sel_J_128Kui                     0x0900     //RX recal servo operation timeout J.  128K UI 
#define     rx_recal_timeout_sel_J_256Kui                     0x0A00     //RX recal servo operation timeout J.  256K UI 
#define     rx_recal_timeout_sel_J_512Kui                     0x0B00     //RX recal servo operation timeout J.  512K UI 
#define     rx_recal_timeout_sel_J_1Mui                       0x0C00     //RX recal servo operation timeout J.  1M UI 
#define     rx_recal_timeout_sel_J_2Mui                       0x0D00     //RX recal servo operation timeout J.  2M UI 
#define     rx_recal_timeout_sel_J_4Mui                       0x0E00     //RX recal servo operation timeout J.  4M UI
#define     rx_recal_timeout_sel_J_Infinite                   0x0F00     //RX recal servo operation timeout J.  Infinite
#define     rx_recal_timeout_sel_J_clear                      0xF0FF     // Clear mask
#define     rx_recal_timeout_sel_K_512ui                      0x0010     //RX recal servo operation timeout K.  512 UI 
#define     rx_recal_timeout_sel_K_1Kui                       0x0020     //RX recal servo operation timeout K.  1K UI 
#define     rx_recal_timeout_sel_K_2Kui                       0x0030     //RX recal servo operation timeout K.  2K UI 
#define     rx_recal_timeout_sel_K_4Kui                       0x0040     //RX recal servo operation timeout K.  4096 UI 
#define     rx_recal_timeout_sel_K_8Kui                       0x0050     //RX recal servo operation timeout K.  8K UI 
#define     rx_recal_timeout_sel_K_16Kui                      0x0060     //RX recal servo operation timeout K.  16K UI 
#define     rx_recal_timeout_sel_K_32Kui                      0x0070     //RX recal servo operation timeout K.  32K UI 
#define     rx_recal_timeout_sel_K_64Kui                      0x0080     //RX recal servo operation timeout K.  64K UI 
#define     rx_recal_timeout_sel_K_128Kui                     0x0090     //RX recal servo operation timeout K.  128K UI 
#define     rx_recal_timeout_sel_K_256Kui                     0x00A0     //RX recal servo operation timeout K.  256K UI 
#define     rx_recal_timeout_sel_K_512Kui                     0x00B0     //RX recal servo operation timeout K.  512K UI 
#define     rx_recal_timeout_sel_K_1Mui                       0x00C0     //RX recal servo operation timeout K.  1M UI 
#define     rx_recal_timeout_sel_K_2Mui                       0x00D0     //RX recal servo operation timeout K.  2M UI 
#define     rx_recal_timeout_sel_K_4Mui                       0x00E0     //RX recal servo operation timeout K.  4M UI
#define     rx_recal_timeout_sel_K_Infinite                   0x00F0     //RX recal servo operation timeout K.  Infinite
#define     rx_recal_timeout_sel_K_clear                      0x0F0F     // Clear mask
#define     rx_recal_timeout_sel_L_512ui                      0x0001     //RX recal servo operation timeout L.  512 UI 
#define     rx_recal_timeout_sel_L_1Kui                       0x0002     //RX recal servo operation timeout L.  1K UI 
#define     rx_recal_timeout_sel_L_2Kui                       0x0003     //RX recal servo operation timeout L.  2K UI 
#define     rx_recal_timeout_sel_L_4Kui                       0x0004     //RX recal servo operation timeout L.  4096 UI 
#define     rx_recal_timeout_sel_L_8Kui                       0x0005     //RX recal servo operation timeout L.  8K UI 
#define     rx_recal_timeout_sel_L_16Kui                      0x0006     //RX recal servo operation timeout L.  16K UI 
#define     rx_recal_timeout_sel_L_32Kui                      0x0007     //RX recal servo operation timeout L.  32K UI 
#define     rx_recal_timeout_sel_L_64Kui                      0x0008     //RX recal servo operation timeout L.  64K UI 
#define     rx_recal_timeout_sel_L_128Kui                     0x0009     //RX recal servo operation timeout L.  128K UI 
#define     rx_recal_timeout_sel_L_256Kui                     0x000A     //RX recal servo operation timeout L.  256K UI 
#define     rx_recal_timeout_sel_L_512Kui                     0x000B     //RX recal servo operation timeout L.  512K UI 
#define     rx_recal_timeout_sel_L_1Mui                       0x000C     //RX recal servo operation timeout L.  1M UI 
#define     rx_recal_timeout_sel_L_2Mui                       0x000D     //RX recal servo operation timeout L.  2M UI 
#define     rx_recal_timeout_sel_L_4Mui                       0x000E     //RX recal servo operation timeout L.  4M UI
#define     rx_recal_timeout_sel_L_Infinite                   0x000F     //RX recal servo operation timeout L.  Infinite
#define     rx_recal_timeout_sel_L_clear                      0xFF00     // Clear mask

// rx_recal_cntl_pp Register field name                                 data value   Description
#define     rx_recal_in_progress                              0x8000     //Selects which servo timeouts are used. 
#define     rx_recal_in_progress_clear                        0x7FFF     // Clear mask

// rx_trace_pp Register field name                                      data value   Description
#define     rx_pp_trc_mode_tap1                               0x2000     //Per Pack RX Trace Mode  TBD
#define     rx_pp_trc_mode_tap2                               0x4000     //Per Pack RX Trace Mode  TBD
#define     rx_pp_trc_mode_tap3                               0x6000     //Per Pack RX Trace Mode  TBD
#define     rx_pp_trc_mode_tap4                               0x8000     //Per Pack RX Trace Mode  TBD
#define     rx_pp_trc_mode_tap5                               0xA000     //Per Pack RX Trace Mode  TBD
#define     rx_pp_trc_mode_tap6                               0xC000     //Per Pack RX Trace Mode  TBD
#define     rx_pp_trc_mode_tap7                               0xE000     //Per Pack RX Trace Mode  TBD
#define     rx_pp_trc_mode_clear                              0x1FFF     // Clear mask

// rx_bist_gcrmsg_pp Register field name                                data value   Description
#define     rx_bist_en                                        0x8000     //TBD
#define     rx_bist_en_clear                                  0x7FFF     // Clear mask

// rx_scope_cntl_pp Register field name                                 data value   Description
#define     rx_scope_control                                  0x0000     //Bit 0 odd/even (1 is odd) Bit 1 speculation latch 0=0 1=1.
#define     rx_scope_control_clear                            0x3FFF     // Clear mask
#define     rx_bump_scope                                     0x2000     //This is a write only pulse which must stay on for 1 slow cycle. When pulsed it will bump the scope sync counter one notch.
#define     rx_bump_scope_clear                               0xDFFF     // Clear mask

// rx_fir_reset_pb Register field name                                  data value   Description
#define     rx_pb_clr_par_errs                                0x0002     //Clear All RX Parity Error Latches
#define     rx_pb_clr_par_errs_clear                          0xFFFD     // Clear mask
#define     rx_pb_fir_reset                                   0x0001     //FIR Reset
#define     rx_pb_fir_reset_clear                             0xFFFE     // Clear mask

// rx_fir_pb Register field name                                        data value   Description
#define     rx_pb_fir_errs_err_busctl_gcrs_ld_sm              0x0400     //A Per-Bus BUSCTL Register or State Machine Parity Error has occurred.  BUSCTL GCR Load SM Parity Error.
#define     rx_pb_fir_errs_clear                              0x003F     // Clear mask

// rx_fir_mask_pb Register field name                                   data value   Description
#define     rx_pb_fir_errs_mask_err_busctl_gcrs_ld_sm         0x0400     //FIR mask for register or state machine parity checkers in per-bus BUSCTL logic. A value of 1 masks the error from generating a FIR error.  BUSCTL GCR Load SM Parity Error.
#define     rx_pb_fir_errs_mask_clear                         0x003F     // Clear mask

// rx_fir_error_inject_pb Register field name                           data value   Description
#define     rx_pb_fir_errs_inj_1                              0x4000     //RX Per-Group Parity Error Injection  Causes a parity flip in the specific parity checker.
#define     rx_pb_fir_errs_inj_err_inj_busctl_gcrs_ld_sm      0x0400     //RX Per-Group Parity Error Injection  BUSCTL GCR Load SM Parity Error Inject.
#define     rx_pb_fir_errs_inj_clear                          0x003F     // Clear mask



// ei4_tx_mode_pl Register field name                                       data value   Description
#define     ei4_tx_lane_pdwn                                      0x8000     //Used to drive inhibit (tristate) and fully power down a lane independent of the logical lane disable. This control is independent from the per-group logical lane disable settings (ei4_tx_lane_disable_vec*) in order to allow for flexibility. Note that this control routes through the boundary scan logic, which has dominance.  Also note that per-group registers ei4_tx_lane_disabled_vec_0_15 and ei4_tx_lane_disabled_vec_16_31 are used to logically disable a lane with respect to the training, recalibration, and repair machines so both this per-lane and the per-group registers need to be set in order to logically disable and powerdown a lane. Note that this per-lane register is adjusted for lane swizzling automatically in HW but it is NOT adjusted automatically in HW when in the MSB-LSB swap mode so the eRepair procedure needs to take care to power down the correct lane when in this mode. 
#define     ei4_tx_lane_pdwn_clear                                0x7FFF     // Clear mask
#define     ei4_tx_lane_invert                                    0x4000     //Used to invert the polarity of a lane.
#define     ei4_tx_lane_invert_clear                              0xBFFF     // Clear mask
#define     ei4_tx_lane_quiesce_quiesce_to_0                      0x1000     //Used to force the output of a lane to a particular value.  Quiesce Lane to a Static 0 value
#define     ei4_tx_lane_quiesce_quiesce_to_1                      0x2000     //Used to force the output of a lane to a particular value.  Quiesce Lane to a Static 1 value
#define     ei4_tx_lane_quiesce_quiesce_to_z                      0x3000     //Used to force the output of a lane to a particular value.  Tri-State Lane Output
#define     ei4_tx_lane_quiesce_clear                             0xCFFF     // Clear mask
#define     ei4_tx_lane_scramble_disable                          0x0200     //Used to disable the TX scrambler on a specific lane or all lanes by using a per-lane/per-group global write.
#define     ei4_tx_lane_scramble_disable_clear                    0xFDFF     // Clear mask

// ei4_tx_cntl_stat_pl Register field name                                  data value   Description
#define     ei4_tx_fifo_err                                       0x8000     //Indicates an error condition in the TX FIFO.
#define     ei4_tx_fifo_err_clear                                 0x7FFF     // Clear mask

// ei4_tx_spare_mode_pl Register field name                                 data value   Description
#define     ei4_tx_pl_spare_mode_0                                0x8000     //Per-lane spare mode latch
#define     ei4_tx_pl_spare_mode_0_clear                          0x7FFF     // Clear mask
#define     ei4_tx_pl_spare_mode_1                                0x4000     //Per-lane spare mode latch
#define     ei4_tx_pl_spare_mode_1_clear                          0xBFFF     // Clear mask
#define     ei4_tx_pl_spare_mode_2                                0x2000     //Per-lane spare mode latch
#define     ei4_tx_pl_spare_mode_2_clear                          0xDFFF     // Clear mask
#define     ei4_tx_pl_spare_mode_3                                0x1000     //Per-lane spare mode latch
#define     ei4_tx_pl_spare_mode_3_clear                          0xEFFF     // Clear mask
#define     ei4_tx_pl_spare_mode_4                                0x0800     //Per-lane spare mode latch
#define     ei4_tx_pl_spare_mode_4_clear                          0xF7FF     // Clear mask
#define     ei4_tx_pl_spare_mode_5                                0x0400     //Per-lane spare mode latch
#define     ei4_tx_pl_spare_mode_5_clear                          0xFBFF     // Clear mask
#define     ei4_tx_pl_spare_mode_6                                0x0200     //Per-lane spare mode latch
#define     ei4_tx_pl_spare_mode_6_clear                          0xFDFF     // Clear mask
#define     ei4_tx_pl_spare_mode_7                                0x0100     //Per-lane spare mode latch
#define     ei4_tx_pl_spare_mode_7_clear                          0xFEFF     // Clear mask

// ei4_tx_bist_stat_pl Register field name                                  data value   Description
#define     ei4_tx_lane_bist_err                                  0x8000     //Indicates a TXBIST error occurred.
#define     ei4_tx_lane_bist_err_clear                            0x7FFF     // Clear mask
#define     ei4_tx_lane_bist_done                                 0x4000     //Indicates TXBIST has completed. 
#define     ei4_tx_lane_bist_done_clear                           0xBFFF     // Clear mask

// ei4_tx_prbs_mode_pl Register field name                                  data value   Description
#define     ei4_tx_prbs_tap_id_pattern_b                          0x2000     //TX Per-Lane PRBS Tap Selector  PRBS tap point B
#define     ei4_tx_prbs_tap_id_pattern_c                          0x4000     //TX Per-Lane PRBS Tap Selector  PRBS tap point C
#define     ei4_tx_prbs_tap_id_pattern_d                          0x6000     //TX Per-Lane PRBS Tap Selector  PRBS tap point D
#define     ei4_tx_prbs_tap_id_pattern_e                          0x8000     //TX Per-Lane PRBS Tap Selector  PRBS tap point E
#define     ei4_tx_prbs_tap_id_pattern_f                          0xA000     //TX Per-Lane PRBS Tap Selector  PRBS tap point F
#define     ei4_tx_prbs_tap_id_pattern_g                          0xC000     //TX Per-Lane PRBS Tap Selector  PRBS tap point G
#define     ei4_tx_prbs_tap_id_pattern_h                          0xE000     //TX Per-Lane PRBS Tap Selector  PRBS tap point H
#define     ei4_tx_prbs_tap_id_clear                              0x1FFF     // Clear mask

// ei4_tx_data_cntl_gcrmsg_pl Register field name                           data value   Description
#define     ei4_tx_drv_data_pattern_gcrmsg_drv_wt                 0x1000     //GCR Message: TX Per Data Lane Drive Patterns  Drive Wiretest Pattern
#define     ei4_tx_drv_data_pattern_gcrmsg_drv_1s                 0x2000     //GCR Message: TX Per Data Lane Drive Patterns  Drive All 1s Pattern
#define     ei4_tx_drv_data_pattern_gcrmsg_drv_simple_A           0x3000     //GCR Message: TX Per Data Lane Drive Patterns  Drive Simple Pattern A
#define     ei4_tx_drv_data_pattern_gcrmsg_drv_simple_B           0x4000     //GCR Message: TX Per Data Lane Drive Patterns  Drive Simple Pattern B
#define     ei4_tx_drv_data_pattern_gcrmsg_drv_full_prbs23        0x5000     //GCR Message: TX Per Data Lane Drive Patterns  PRBS-23 Full Speed Scramble Pattern A thru H
#define     ei4_tx_drv_data_pattern_gcrmsg_drv_red_prbs23         0x6000     //GCR Message: TX Per Data Lane Drive Patterns  PRBS-23 Reduced Density Scramble Pattern A thru H
#define     ei4_tx_drv_data_pattern_gcrmsg_drv_9th_prbs23         0x7000     //GCR Message: TX Per Data Lane Drive Patterns  PRBS-23 9th pattern
#define     ei4_tx_drv_data_pattern_gcrmsg_drv_ei3_iap            0x8000     //GCR Message: TX Per Data Lane Drive Patterns  EI-3 Busy IAP Pattern (EI4 only
#define     ei4_tx_drv_data_pattern_gcrmsg_drv_ei3_prbs12         0x9000     //GCR Message: TX Per Data Lane Drive Patterns  Drive EI-3 PRBS-12 Shifted RDT Pattern (EI4 only
#define     ei4_tx_drv_data_pattern_gcrmsg_TDR_square_wave        0xA000     //GCR Message: TX Per Data Lane Drive Patterns  Drives TDR Pulse-Square waves
#define     ei4_tx_drv_data_pattern_gcrmsg_k28_5                  0xB000     //GCR Message: TX Per Data Lane Drive Patterns  Drives 20-bit K28.5 pattern - padded to 32 bits
#define     ei4_tx_drv_data_pattern_gcrmsg_unused_A               0xC000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     ei4_tx_drv_data_pattern_gcrmsg_unused_B               0xD000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     ei4_tx_drv_data_pattern_gcrmsg_unused_C               0xE000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     ei4_tx_drv_data_pattern_gcrmsg_unused_D               0xF000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     ei4_tx_drv_data_pattern_gcrmsg_clear                  0x0FFF     // Clear mask
#define     ei4_tx_drv_func_data_gcrmsg                           0x0800     //GCR Message: Functional Data
#define     ei4_tx_drv_func_data_gcrmsg_clear                     0xF7FF     // Clear mask
#define     ei4_tx_sls_lane_sel_gcrmsg                            0x0400     //GCR Message: SLS Commands & Recalibration
#define     ei4_tx_sls_lane_sel_gcrmsg_clear                      0xFBFF     // Clear mask

// ei4_tx_sync_pattern_gcrmsg_pl Register field name                        data value   Description
#define     ei4_tx_drv_sync_patt_gcrmsg                           0x4000     //Sync Pattern
#define     ei4_tx_drv_sync_patt_gcrmsg_clear                     0xBFFF     // Clear mask

// ei4_tx_fir_pl Register field name                                        data value   Description
#define     ei4_tx_pl_fir_errs                                    0x8000     //A 1 in this field indicates that a register or state machine parity error has occurred in per-lane logic.
#define     ei4_tx_pl_fir_errs_clear                              0x7FFF     // Clear mask

// ei4_tx_fir_mask_pl Register field name                                   data value   Description
#define     ei4_tx_pl_fir_errs_mask                               0x8000     //FIR mask for all per-lane register or per-lane state machine parity errors.
#define     ei4_tx_pl_fir_errs_mask_clear                         0x7FFF     // Clear mask

// ei4_tx_fir_error_inject_pl Register field name                           data value   Description
#define     ei4_tx_pl_fir_err_inj                                 0x8000     //TX Per-Lane Parity Error Injection
#define     ei4_tx_pl_fir_err_inj_clear                           0x7FFF     // Clear mask

// ei4_tx_mode_fast_pl Register field name                                  data value   Description
#define     ei4_tx_err_inject                                     0x0000     //Software-only controlled register to inject one or more errors for one deserialized clock pulse on one or more specified beats on this lane.  Set bit position X to inject on beat X of a cycle.  Bits 0:3 are used in EDI and 0:1 are used in EI4. 
#define     ei4_tx_err_inject_clear                               0x0FFF     // Clear mask
#define     ei4_tx_err_inj_A_enable                               0x0800     //Control to enable the random bit error injection pattern A for this lane.(default)
#define     ei4_tx_err_inj_A_enable_clear                         0xF7FF     // Clear mask
#define     ei4_tx_err_inj_B_enable                               0x0400     //Control to enable the random bit error injection pattern B for this lane.(default)
#define     ei4_tx_err_inj_B_enable_clear                         0xFBFF     // Clear mask

// ei4_tx_clk_mode_pg Register field name                                   data value   Description
#define     ei4_tx_clk_pdwn                                       0x8000     //Used to disable the TX clock and put it into a low power state.
#define     ei4_tx_clk_pdwn_clear                                 0x7FFF     // Clear mask
#define     ei4_tx_clk_invert                                     0x4000     //Used to invert the polarity of the clock.
#define     ei4_tx_clk_invert_clear                               0xBFFF     // Clear mask
#define     ei4_tx_clk_quiesce_p_quiesce_to_0                     0x1000     //Used to force the output of the positive differential leg of the clock lane to a particular value.  Note that the 0 and 1 settings for EDI are for lab characterization only, and the circuits are not deemed to have the proper drive strength in those modes to meet production level quality.  Quiesce Clock Lane to a Static 0 value
#define     ei4_tx_clk_quiesce_p_quiesce_to_1                     0x2000     //Used to force the output of the positive differential leg of the clock lane to a particular value.  Note that the 0 and 1 settings for EDI are for lab characterization only, and the circuits are not deemed to have the proper drive strength in those modes to meet production level quality.  Quiesce Clock Lane to a Static 1 value
#define     ei4_tx_clk_quiesce_p_quiesce_to_z                     0x3000     //Used to force the output of the positive differential leg of the clock lane to a particular value.  Note that the 0 and 1 settings for EDI are for lab characterization only, and the circuits are not deemed to have the proper drive strength in those modes to meet production level quality.  Tri-State Clock Lane Output
#define     ei4_tx_clk_quiesce_p_clear                            0xCFFF     // Clear mask
#define     ei4_tx_clk_quiesce_n_quiesce_to_0                     0x0400     //Used to force the output of the negative differential leg of the clock lane to a particular value.  Note that the 0 and 1 settings for EDI are for lab characterization only, and the circuits are not deemed to have the proper drive strength in those modes to meet production level quality.  Quiesce Clock Lane to a Static 0 value
#define     ei4_tx_clk_quiesce_n_quiesce_to_1                     0x0800     //Used to force the output of the negative differential leg of the clock lane to a particular value.  Note that the 0 and 1 settings for EDI are for lab characterization only, and the circuits are not deemed to have the proper drive strength in those modes to meet production level quality.  Quiesce Clock Lane to a Static 1 value
#define     ei4_tx_clk_quiesce_n_quiesce_to_z                     0x0C00     //Used to force the output of the negative differential leg of the clock lane to a particular value.  Note that the 0 and 1 settings for EDI are for lab characterization only, and the circuits are not deemed to have the proper drive strength in those modes to meet production level quality.  Tri-State Clock Lane Output
#define     ei4_tx_clk_quiesce_n_clear                            0xF3FF     // Clear mask

// ei4_tx_spare_mode_pg Register field name                                 data value   Description
#define     ei4_tx_pg_spare_mode_0                                0x8000     //Per-group spare mode latch
#define     ei4_tx_pg_spare_mode_0_clear                          0x7FFF     // Clear mask
#define     ei4_tx_pg_spare_mode_1                                0x4000     //Per-group spare mode latch
#define     ei4_tx_pg_spare_mode_1_clear                          0xBFFF     // Clear mask
#define     ei4_tx_pg_spare_mode_2                                0x2000     //Per-group spare mode latch
#define     ei4_tx_pg_spare_mode_2_clear                          0xDFFF     // Clear mask
#define     ei4_tx_pg_spare_mode_3                                0x1000     //Per-group spare mode latch
#define     ei4_tx_pg_spare_mode_3_clear                          0xEFFF     // Clear mask
#define     ei4_tx_pg_spare_mode_4                                0x0800     //Per-group spare mode latch
#define     ei4_tx_pg_spare_mode_4_clear                          0xF7FF     // Clear mask
#define     ei4_tx_pg_spare_mode_5                                0x0400     //Per-group spare mode latch
#define     ei4_tx_pg_spare_mode_5_clear                          0xFBFF     // Clear mask
#define     ei4_tx_pg_spare_mode_6                                0x0200     //Per-group spare mode latch
#define     ei4_tx_pg_spare_mode_6_clear                          0xFDFF     // Clear mask
#define     ei4_tx_pg_spare_mode_7                                0x0100     //Per-group spare mode latch
#define     ei4_tx_pg_spare_mode_7_clear                          0xFEFF     // Clear mask

// ei4_tx_cntl_stat_pg Register field name                                  data value   Description
#define     ei4_tx_fifo_init                                      0x4000     //Used to initialize the TX FIFO and put it into a known reset state. This will cause the load to unload delay of the FIFO to be set to the value in the ei4_tx_FIFO_L2U_DLY field of the ei4_tx_FIFO_Mode register.
#define     ei4_tx_fifo_init_clear                                0xBFFF     // Clear mask

// ei4_tx_mode_pg Register field name                                       data value   Description
#define     ei4_tx_max_bad_lanes                                  0x0000     //Static Repair, Dynamic Repair & Recal max number of bad lanes per TX bus (NOTE: should match RX side)
#define     ei4_tx_max_bad_lanes_clear                            0x07FF     // Clear mask
#define     ei4_tx_msbswap                                        0x0400     //Used to enable end-for-end or msb swap of TX lanes.  For example, lanes 0 and N-1 swap, lanes 1 and N-2 swap, etc. 
#define     ei4_tx_msbswap_clear                                  0xFBFF     // Clear mask

// ei4_tx_bus_repair_pg Register field name                                 data value   Description
#define     ei4_tx_bus_repair_count                               0x0000     //This field is used to TBD.
#define     ei4_tx_bus_repair_count_clear                         0x3FFF     // Clear mask
#define     ei4_tx_bus_repair_pos_0                               0x0000     //This field is used to TBD.
#define     ei4_tx_bus_repair_pos_0_clear                         0xC07F     // Clear mask
#define     ei4_tx_bus_repair_pos_1                               0x0000     //This field is used to TBD.
#define     ei4_tx_bus_repair_pos_1_clear                         0x3F80     // Clear mask

// ei4_tx_grp_repair_vec_0_15_pg Register field name                        data value   Description
#define     ei4_tx_grp_repair_vec_0_15                            0x0000     //This field is used to TBD.
#define     ei4_tx_grp_repair_vec_0_15_clear                      0x0000     // Clear mask

// ei4_tx_grp_repair_vec_16_31_pg Register field name                       data value   Description
#define     ei4_tx_grp_repair_vec_16_31                           0x0000     //This field is used to TBD.
#define     ei4_tx_grp_repair_vec_16_31_clear                     0x0000     // Clear mask

// ei4_tx_reset_act_pg Register field name                                  data value   Description
#define     ei4_tx_reset_cfg_ena                                  0x8000     //Enable Configurable Group Reset
#define     ei4_tx_reset_cfg_ena_clear                            0x7FFF     // Clear mask
#define     ei4_tx_clr_par_errs                                   0x0002     //Clear All TX Parity Error Latches
#define     ei4_tx_clr_par_errs_clear                             0xFFFD     // Clear mask
#define     ei4_tx_fir_reset                                      0x0001     //FIR Reset
#define     ei4_tx_fir_reset_clear                                0xFFFE     // Clear mask

// ei4_tx_bist_stat_pg Register field name                                  data value   Description
#define     ei4_tx_clk_bist_err                                   0x0000     //TBD
#define     ei4_tx_clk_bist_err_clear                             0x3FFF     // Clear mask
#define     ei4_tx_clk_bist_done                                  0x0000     //TBD
#define     ei4_tx_clk_bist_done_clear                            0xCFFF     // Clear mask

// ei4_tx_fir_pg Register field name                                        data value   Description
#define     ei4_tx_pg_fir_errs_clear                              0x00FF     // Clear mask
#define     ei4_tx_pl_fir_err                                     0x0001     //Summary bit indicating a TX per-lane register or state machine parity error has occurred in one or more lanes. The ei4_tx_fir_pl register from each lane should be read to isolate to a particular piece of logic. There is no mechanism to determine which lane had the fault without reading FIR status from each lane.
#define     ei4_tx_pl_fir_err_clear                               0xFFFE     // Clear mask

// ei4_tx_fir_mask_pg Register field name                                   data value   Description
#define     ei4_tx_pg_fir_errs_mask_clear                         0x00FF     // Clear mask
#define     ei4_tx_pl_fir_err_mask                                0x0001     //FIR mask for the summary bit that indicates a per-lane TX register or state machine parity error has occurred. This mask bit is used to block ALL per-lane TX parity errors from causing a FIR error.\pmt
#define     ei4_tx_pl_fir_err_mask_clear                          0xFFFE     // Clear mask

// ei4_tx_fir_error_inject_pg Register field name                           data value   Description
#define     ei4_tx_pg_fir_err_inj_inj_par_err                     0x1000     //TX Per-Group Parity Error Injection  Causes a parity flip in the specific parity checker.
#define     ei4_tx_pg_fir_err_inj_clear                           0x00FF     // Clear mask

// ei4_tx_id1_pg Register field name                                        data value   Description
#define     ei4_tx_bus_id                                         0x0000     //This field is used to programmably set the bus number that a clkgrp belongs to.
#define     ei4_tx_bus_id_clear                                   0x03FF     // Clear mask
#define     ei4_tx_group_id                                       0x0000     //This field is used to programmably set the clock group number within a bus.
#define     ei4_tx_group_id_clear                                 0xFE07     // Clear mask

// ei4_tx_id2_pg Register field name                                        data value   Description
#define     ei4_tx_last_group_id                                  0x0000     //This field is used to programmably set the last clock group number within a bus.
#define     ei4_tx_last_group_id_clear                            0x03FF     // Clear mask

// ei4_tx_id3_pg Register field name                                        data value   Description
#define     ei4_tx_start_lane_id                                  0x0000     //This field is used to programmably set the first lane position in the group but relative to the bus.
#define     ei4_tx_start_lane_id_clear                            0x80FF     // Clear mask
#define     ei4_tx_end_lane_id                                    0x0000     //This field is used to programmably set the last lane position in the group but relative to the bus.
#define     ei4_tx_end_lane_id_clear                              0x7F80     // Clear mask

// ei4_tx_clk_cntl_gcrmsg_pg Register field name                            data value   Description
#define     ei4_tx_drv_clk_pattern_gcrmsg_drv_wt                  0x4000     //TX Clock Drive Patterns  Drive Wiretest Pattern
#define     ei4_tx_drv_clk_pattern_gcrmsg_drv_c4                  0x8000     //TX Clock Drive Patterns  Drive Clock Pattern
#define     ei4_tx_drv_clk_pattern_gcrmsg_unused                  0xC000     //TX Clock Drive Patterns  Unused
#define     ei4_tx_drv_clk_pattern_gcrmsg_clear                   0x3FFF     // Clear mask

// ei4_tx_bad_lane_enc_gcrmsg_pg Register field name                        data value   Description
#define     ei4_tx_bad_lane1_gcrmsg                               0x0000     //GCR Message: Encoded bad lane one in relation to the entire TX bus
#define     ei4_tx_bad_lane1_gcrmsg_clear                         0x01FF     // Clear mask
#define     ei4_tx_bad_lane2_gcrmsg                               0x0000     //GCR Message: Encoded bad lane two in relation to the entire TX bus
#define     ei4_tx_bad_lane2_gcrmsg_clear                         0xFE03     // Clear mask
#define     ei4_tx_bad_lane_code_gcrmsg_bad_ln1_val               0x0001     //GCR Message: TX Bad Lane Code  Bad Lane 1 Valid
#define     ei4_tx_bad_lane_code_gcrmsg_bad_lns12_val             0x0002     //GCR Message: TX Bad Lane Code  Bad Lanes 1 and 2 Valid
#define     ei4_tx_bad_lane_code_gcrmsg_3plus_bad_lns             0x0003     //GCR Message: TX Bad Lane Code  3+ bad lanes
#define     ei4_tx_bad_lane_code_gcrmsg_clear                     0xFFF0     // Clear mask

// ei4_tx_sls_lane_enc_gcrmsg_pg Register field name                        data value   Description
#define     ei4_tx_sls_lane_gcrmsg                                0x0000     //GCR Message: Encoded SLS lane in relation to the entire TX bus
#define     ei4_tx_sls_lane_gcrmsg_clear                          0x01FF     // Clear mask
#define     ei4_tx_sls_lane_val_gcrmsg                            0x0100     //GCR Message: TX SLS Lane Valid
#define     ei4_tx_sls_lane_val_gcrmsg_clear                      0xFEFF     // Clear mask

// ei4_tx_wt_seg_enable_pg Register field name                              data value   Description
#define     ei4_tx_wt_en_all_clk_segs_gcrmsg                      0x8000     //TX Clock Wiretest driver segnments enable
#define     ei4_tx_wt_en_all_clk_segs_gcrmsg_clear                0x7FFF     // Clear mask
#define     ei4_tx_wt_en_all_data_segs_gcrmsg                     0x4000     //TX Data  Wiretest driver segnments enable
#define     ei4_tx_wt_en_all_data_segs_gcrmsg_clear               0xBFFF     // Clear mask

// ei4_tx_pc_ffe_pg Register field name                                     data value   Description
#define     ei4_tx_pc_test_mode                                   0x8000     //Driver Segment Test mode
#define     ei4_tx_pc_test_mode_clear                             0x7FFF     // Clear mask
#define     ei4_tx_main_slice_en_enc                              0x0000     //240ohm main slice enable (binary code - 0000 is zero slices and 0110 is maximum slices)
#define     ei4_tx_main_slice_en_enc_clear                        0xF0FF     // Clear mask
#define     ei4_tx_pc_slice_en_enc                                0x0000     //240ohm precompensation slice enable (binary code - 0000 is zero slices and 1110 is maximum slices)
#define     ei4_tx_pc_slice_en_enc_clear                          0x0FF0     // Clear mask

// ei4_tx_misc_analog_pg Register field name                                data value   Description
#define     ei4_tx_slewctl_slew110ps                              0x4000     //Driver Slew Control (bits 2:3 are reserved)  110ps nominal rate 
#define     ei4_tx_slewctl_slew140ps                              0x8000     //Driver Slew Control (bits 2:3 are reserved)  140ps nominal rate 
#define     ei4_tx_slewctl_slew170ps                              0xC000     //Driver Slew Control (bits 2:3 are reserved)  170ps nominal rate 
#define     ei4_tx_slewctl_clear                                  0x0FFF     // Clear mask
#define     ei4_tx_pvtnl_enc_2400ohms                             0x0010     //PVT pfet enables for all driver slices  min pvt pfet enabled in parallel 
#define     ei4_tx_pvtnl_enc_1200ohms                             0x0020     //PVT pfet enables for all driver slices  max pvt pfet enabled in parallel 
#define     ei4_tx_pvtnl_enc_800ohms                              0x0030     //PVT pfet enables for all driver slices  both pvt pfets enabled in parallel
#define     ei4_tx_pvtnl_enc_clear                                0xF3CF     // Clear mask
#define     ei4_tx_pvtpl_enc_2400ohms                             0x0001     //PVT nfet enables for all driver slices  Min pvt nfet enabled in parallel 
#define     ei4_tx_pvtpl_enc_1200ohms                             0x0002     //PVT nfet enables for all driver slices  Max pvt nfet enabled in parallel 
#define     ei4_tx_pvtpl_enc_800ohms                              0x0003     //PVT nfet enables for all driver slices  Both pvt nfets enabled in parallel
#define     ei4_tx_pvtpl_enc_clear                                0xFFF0     // Clear mask

// ei4_tx_lane_disabled_vec_0_15_pg Register field name                     data value   Description
#define     ei4_tx_lane_disabled_vec_0_15                         0x0000     //Lanes disabled by HW (status) or method to force lane to be disabled (save power) from software (control).
#define     ei4_tx_lane_disabled_vec_0_15_clear                   0x0000     // Clear mask

// ei4_tx_lane_disabled_vec_16_31_pg Register field name                    data value   Description
#define     ei4_tx_lane_disabled_vec_16_31                        0x0000     //Lanes disabled by HW (status) or method to force lane to be disabled (save power) from software (control).
#define     ei4_tx_lane_disabled_vec_16_31_clear                  0x0000     // Clear mask

// ei4_tx_sls_lane_mux_gcrmsg_pg Register field name                        data value   Description
#define     ei4_tx_sls_lane_shdw_gcrmsg                           0x8000     //GCR Message: SLS lane shadowing or unshadowing functional data (used to set up TX mux controls)
#define     ei4_tx_sls_lane_shdw_gcrmsg_clear                     0x7FFF     // Clear mask

// ei4_tx_dyn_rpr_pg Register field name                                    data value   Description
#define     ei4_tx_sls_hndshk_state_clear                         0x07FF     // Clear mask

// ei4_tx_slv_mv_sls_ln_req_gcrmsg_pg Register field name                   data value   Description
#define     ei4_tx_slv_mv_sls_shdw_req_gcrmsg                     0x8000     //GCR Message: Request to TX Slave to Move SLS Lane
#define     ei4_tx_slv_mv_sls_shdw_req_gcrmsg_clear               0x7FFF     // Clear mask
#define     ei4_tx_slv_mv_sls_shdw_rpr_req_gcrmsg                 0x4000     //GCR Message: Request to TX Slave to Move SLS Lane & Set Bad Lane Register
#define     ei4_tx_slv_mv_sls_shdw_rpr_req_gcrmsg_clear           0xBFFF     // Clear mask
#define     ei4_tx_slv_mv_sls_unshdw_req_gcrmsg                   0x2000     //GCR Message: Request to TX Slave to Move SLS Lane
#define     ei4_tx_slv_mv_sls_unshdw_req_gcrmsg_clear             0xDFFF     // Clear mask
#define     ei4_tx_slv_mv_sls_unshdw_rpr_req_gcrmsg               0x1000     //GCR Message: Request to TX Slave to Move SLS Lane & Set Bad Lane Register
#define     ei4_tx_slv_mv_sls_unshdw_rpr_req_gcrmsg_clear         0xEFFF     // Clear mask
#define     ei4_tx_bus_width                                      0x0000     //GCR Message: TX Bus Width
#define     ei4_tx_bus_width_clear                                0xF01F     // Clear mask
#define     ei4_tx_slv_mv_sls_rpr_req_gcrmsg                      0x0010     //GCR Message: Request to TX Slave to Move SLS Lane & Set Bad Lane Register
#define     ei4_tx_slv_mv_sls_rpr_req_gcrmsg_clear                0xFFEF     // Clear mask
#define     ei4_tx_sls_lane_sel_lg_gcrmsg                         0x0008     //GCR Message: Sets the ei4_tx_sls_lane_sel_gcrmsg for the last good lane per bus during recal bad lane scenarios
#define     ei4_tx_sls_lane_sel_lg_gcrmsg_clear                   0xFFF7     // Clear mask
#define     ei4_tx_sls_lane_unsel_lg_gcrmsg                       0x0004     //GCR Message: Clears the ei4_tx_sls_lane_sel_gcrmsg for the last good lane per bus during recal bad lane scenarios
#define     ei4_tx_sls_lane_unsel_lg_gcrmsg_clear                 0xFFFB     // Clear mask

// ei4_tx_rdt_cntl_pg Register field name                                   data value   Description
#define     ei4_tx_rdt_mode                                       0x8000     //Sets RDT mode
#define     ei4_tx_rdt_mode_clear                                 0x7FFF     // Clear mask
#define     ei4_tx_run_rdt                                        0x4000     //Drives RDT pattern
#define     ei4_tx_run_rdt_clear                                  0xBFFF     // Clear mask

// ei4_rx_dll_cal_cntl_pg Register field name                               data value   Description
#define     ei4_rx_dll1_cal_good                                  0x8000     //RX DLL 1 Calibration has completed successfully and clock is properly aligned. This remains static (not dynamically updated) unless the initialization process requests either a new calibration or a fine update.
#define     ei4_rx_dll1_cal_good_clear                            0x7FFF     // Clear mask
#define     ei4_rx_dll1_cal_error                                 0x4000     //RX DLL 1 Calibration has failed to pass coarse delay or coarse vreg calibration and clock is not aligned.
#define     ei4_rx_dll1_cal_error_clear                           0xBFFF     // Clear mask
#define     ei4_rx_dll1_cal_error_fine                            0x2000     //RX DLL 1 Calibration has failed to pass fine vreg calibration on either reset or on update and clock is not aligned.
#define     ei4_rx_dll1_cal_error_fine_clear                      0xDFFF     // Clear mask
#define     ei4_rx_dll1_cal_skip_skip_delay                       0x0800     //RX DLL 1 Calibration Skip StepsIf any steps are skipped respective manual settings must be supplied. Fine cal cannot be skipped.  Skip coarse delay cal only
#define     ei4_rx_dll1_cal_skip_skip_vreg                        0x1000     //RX DLL 1 Calibration Skip StepsIf any steps are skipped respective manual settings must be supplied. Fine cal cannot be skipped.  Skip coarse vreg cal only
#define     ei4_rx_dll1_cal_skip_skip_both                        0x1800     //RX DLL 1 Calibration Skip StepsIf any steps are skipped respective manual settings must be supplied. Fine cal cannot be skipped.  Skip both coarse vreg and coarse delay cal
#define     ei4_rx_dll1_cal_skip_clear                            0xE7FF     // Clear mask
#define     ei4_rx_dll1_coarse_adj_by2                            0x0400     //RX DLL 1 Calibration Coarse Delay Backoff TweakWhen coarse delay is calibrated normally 1 delay step is removed to assist finding the edge for fine delay. This allows for 2 steps adjustment.
#define     ei4_rx_dll1_coarse_adj_by2_clear                      0xFBFF     // Clear mask
#define     ei4_rx_dll2_cal_good                                  0x0080     //RX DLL 2 Calibration has completed successfully and clock is properly aligned. This remains static (not dynamically updated) unless the initialization process requests either a new calibration or a fine update.
#define     ei4_rx_dll2_cal_good_clear                            0xFF7F     // Clear mask
#define     ei4_rx_dll2_cal_error                                 0x0040     //RX DLL 2 Calibration has failed to pass coarse delay or coarse vreg calibration and clock is not aligned.
#define     ei4_rx_dll2_cal_error_clear                           0xFFBF     // Clear mask
#define     ei4_rx_dll2_cal_error_fine                            0x0020     //RX DLL 2 Calibration has failed to pass fine vreg calibration on either reset or on update and clock is not aligned.
#define     ei4_rx_dll2_cal_error_fine_clear                      0xFFDF     // Clear mask
#define     ei4_rx_dll2_cal_skip_skip_delay                       0x0008     //RX DLL 2 Calibration Skip StepsIf any steps are skipped respective manual settings must be supplied. Fine cal cannot be skipped.  Skip coarse delay cal only
#define     ei4_rx_dll2_cal_skip_skip_vreg                        0x0010     //RX DLL 2 Calibration Skip StepsIf any steps are skipped respective manual settings must be supplied. Fine cal cannot be skipped.  Skip coarse vreg cal only
#define     ei4_rx_dll2_cal_skip_skip_both                        0x0018     //RX DLL 2 Calibration Skip StepsIf any steps are skipped respective manual settings must be supplied. Fine cal cannot be skipped.  Skip both coarse vreg and coarse delay cal
#define     ei4_rx_dll2_cal_skip_clear                            0xFCE7     // Clear mask
#define     ei4_rx_dll2_coarse_adj_by2                            0x0004     //RX DLL 2 Calibration Coarse Delay Backoff TweakWhen coarse delay is calibrated normally 1 delay step is removed to assist finding the edge for fine delay. This allows for 2 steps adjustment.
#define     ei4_rx_dll2_coarse_adj_by2_clear                      0xFFFB     // Clear mask

// ei4_rx_dll1_setpoint1_pg Register field name                             data value   Description
#define     ei4_rx_dll1_coarse_en                                 0x0000     //RX DLL 1 Calibration Result/Setting for Coarse Delay Adjust
#define     ei4_rx_dll1_coarse_en_clear                           0x03FF     // Clear mask
#define     ei4_rx_dll1_vreg_dac_coarse                           0x0000     //RX DLL 1 Calibration Result/Setting for Coarse VREG DAC
#define     ei4_rx_dll1_vreg_dac_coarse_clear                     0xFE03     // Clear mask

// ei4_rx_dll1_setpoint2_pg Register field name                             data value   Description
#define     ei4_rx_dll1_vreg_dac_lower                            0x0000     //RX DLL 1 Calibration Result/Setting for Fine VREG DAC Lower
#define     ei4_rx_dll1_vreg_dac_lower_clear                      0x0001     // Clear mask

// ei4_rx_dll1_setpoint3_pg Register field name                             data value   Description
#define     ei4_rx_dll1_vreg_dac_upper                            0x0000     //RX DLL 1 Calibration Result/Setting for Fine VREG DAC Upper
#define     ei4_rx_dll1_vreg_dac_upper_clear                      0x0001     // Clear mask

// ei4_rx_dll2_setpoint1_pg Register field name                             data value   Description
#define     ei4_rx_dll2_coarse_en                                 0x0000     //RX DLL 2 Calibration Result/Setting for Coarse Delay Adjust
#define     ei4_rx_dll2_coarse_en_clear                           0x03FF     // Clear mask
#define     ei4_rx_dll2_vreg_dac_coarse                           0x0000     //RX DLL 2 Calibration Result/Setting for Coarse VREG DAC
#define     ei4_rx_dll2_vreg_dac_coarse_clear                     0xFE03     // Clear mask

// ei4_rx_dll2_setpoint2_pg Register field name                             data value   Description
#define     ei4_rx_dll2_vreg_dac_lower                            0x0000     //RX DLL 2 Calibration Result/Setting for Fine VREG DAC Lower
#define     ei4_rx_dll2_vreg_dac_lower_clear                      0x0001     // Clear mask

// ei4_rx_dll2_setpoint3_pg Register field name                             data value   Description
#define     ei4_rx_dll2_vreg_dac_upper                            0x0000     //RX DLL 2 Calibration Result/Setting for Fine VREG DAC Upper
#define     ei4_rx_dll2_vreg_dac_upper_clear                      0x0001     // Clear mask

// ei4_rx_dll_filter_mode_pg Register field name                            data value   Description
#define     ei4_rx_dll_dll_filter_length_two                      0x2000     //\bRX DLL Phase Detector Digital Filter Select\b. The DLL delay calibration digitally samples a Lead/Lag clock edge detector. This filter specifies the samples to take for different levels of filtering in 8 increments of 2*N. More filtering means longer detect time.  2 samples
#define     ei4_rx_dll_dll_filter_length_four                     0x4000     //\bRX DLL Phase Detector Digital Filter Select\b. The DLL delay calibration digitally samples a Lead/Lag clock edge detector. This filter specifies the samples to take for different levels of filtering in 8 increments of 2*N. More filtering means longer detect time.  4 samples
#define     ei4_rx_dll_dll_filter_length_eight                    0x6000     //\bRX DLL Phase Detector Digital Filter Select\b. The DLL delay calibration digitally samples a Lead/Lag clock edge detector. This filter specifies the samples to take for different levels of filtering in 8 increments of 2*N. More filtering means longer detect time.  8 samples
#define     ei4_rx_dll_dll_filter_length_sixteen                  0x8000     //\bRX DLL Phase Detector Digital Filter Select\b. The DLL delay calibration digitally samples a Lead/Lag clock edge detector. This filter specifies the samples to take for different levels of filtering in 8 increments of 2*N. More filtering means longer detect time.  16 samples
#define     ei4_rx_dll_dll_filter_length_thirtytwo                0xA000     //\bRX DLL Phase Detector Digital Filter Select\b. The DLL delay calibration digitally samples a Lead/Lag clock edge detector. This filter specifies the samples to take for different levels of filtering in 8 increments of 2*N. More filtering means longer detect time.  32 samples
#define     ei4_rx_dll_dll_filter_length_sixtyfour                0xC000     //\bRX DLL Phase Detector Digital Filter Select\b. The DLL delay calibration digitally samples a Lead/Lag clock edge detector. This filter specifies the samples to take for different levels of filtering in 8 increments of 2*N. More filtering means longer detect time.  64 samples
#define     ei4_rx_dll_dll_filter_length_one28                    0xE000     //\bRX DLL Phase Detector Digital Filter Select\b. The DLL delay calibration digitally samples a Lead/Lag clock edge detector. This filter specifies the samples to take for different levels of filtering in 8 increments of 2*N. More filtering means longer detect time.  128 samples
#define     ei4_rx_dll_dll_filter_length_clear                    0x1FFF     // Clear mask
#define     ei4_rx_dll_dll_lead_lag_separation                    0x0000     //\bRX DLL Phase Detector Hysteresis Select\b. The DLL phase detector filters the clock Lead/Lag indicator. This specifies hysteresis separation between a valid lead and valid lag filter sample count in total number of samples. Do not set this higher than the ei4_rx_dll_dll_filter_length
#define     ei4_rx_dll_dll_lead_lag_separation_clear              0xF1FF     // Clear mask

// ei4_rx_dll_analog_tweaks_pg Register field name                          data value   Description
#define     ei4_rx_dll_vreg_con                                   0x8000     //RX DLL Vreg KPrime Voltage Level Adjust.
#define     ei4_rx_dll_vreg_con_clear                             0x7FFF     // Clear mask
#define     ei4_rx_dll_vreg_compcon_clear                         0x8FFF     // Clear mask
#define     ei4_rx_dll_vreg_ref_sel                               0x0000     //RX DLL Vreg Active Voltage Range Adjust. This is primarily for experimentation.000 is default. Others TBD.
#define     ei4_rx_dll_vreg_ref_sel_clear                         0xF1FF     // Clear mask
#define     ei4_rx_dll1_vreg_drvcon_clear                         0xFE3F     // Clear mask
#define     ei4_rx_dll2_vreg_drvcon_clear                         0x8FC7     // Clear mask
#define     ei4_rx_dll_vreg_dac_pullup                            0x0004     //RX DLL Vreg DAC Pullup Chickenswitchadjust dac range for bad hardware.
#define     ei4_rx_dll_vreg_dac_pullup_clear                      0xFFFB     // Clear mask

// ei4_tx_wiretest_pp Register field name                                   data value   Description
#define     ei4_tx_wt_pattern_length_256                          0x4000     //TX Wiretest Pattern Length  256
#define     ei4_tx_wt_pattern_length_512                          0x8000     //TX Wiretest Pattern Length  512
#define     ei4_tx_wt_pattern_length_1024                         0xC000     //TX Wiretest Pattern Length  1024
#define     ei4_tx_wt_pattern_length_clear                        0x3FFF     // Clear mask

// ei4_tx_mode_pp Register field name                                       data value   Description
#define     ei4_tx_reduced_scramble_mode_full_1                   0x4000     //Enables/Disables and sets reduced density of scramble pattern.   Full density 
#define     ei4_tx_reduced_scramble_mode_div2                     0x8000     //Enables/Disables and sets reduced density of scramble pattern.   Enable Div2 Reduced Density 
#define     ei4_tx_reduced_scramble_mode_div4                     0xC000     //Enables/Disables and sets reduced density of scramble pattern.   Enable Div4 Reduced Density.
#define     ei4_tx_reduced_scramble_mode_clear                    0x3FFF     // Clear mask
#define     ei4_tx_ei3_mode                                       0x0001     //EI3 mode - See also ei4_rx_ei3_mode 
#define     ei4_tx_ei3_mode_clear                                 0xFFFE     // Clear mask

// ei4_tx_sls_gcrmsg_pp Register field name                                 data value   Description
#define     ei4_tx_snd_sls_cmd_gcrmsg                             0x8000     //GCR Message: Send SLS Command or Recalibration Data
#define     ei4_tx_snd_sls_cmd_gcrmsg_clear                       0x7FFF     // Clear mask
#define     ei4_tx_dyn_recal_tsr_ignore_gcrmsg                    0x4000     //GCR Message: Send Dynamic Recal SLS Commands all the time (not just during the Status Reporting interval)
#define     ei4_tx_dyn_recal_tsr_ignore_gcrmsg_clear              0xBFFF     // Clear mask
#define     ei4_tx_sls_cmd_gcrmsg                                 0x0000     //GCR Message: TX SLS Command
#define     ei4_tx_sls_cmd_gcrmsg_clear                           0xC0FF     // Clear mask
#define     ei4_tx_snd_sls_cmd_prev_gcrmsg                        0x0080     //GCR Message: Revert to sending previous SLS Command or Recalibration Data after recovery repair made
#define     ei4_tx_snd_sls_cmd_prev_gcrmsg_clear                  0xFF7F     // Clear mask
#define     ei4_tx_snd_sls_using_reg_scramble                     0x0040     //GCR Message: Send SLS command using normal scramble pattern instead of 9th pattern
#define     ei4_tx_snd_sls_using_reg_scramble_clear               0xFFBF     // Clear mask

// ei4_tx_ber_cntl_a_pp Register field name                                 data value   Description
#define     ei4_tx_err_inj_a_rand_beat_dis                        0x8000     //Used to disable randomization of error inject on different beats of data for pattern A.
#define     ei4_tx_err_inj_a_rand_beat_dis_clear                  0x7FFF     // Clear mask
#define     ei4_tx_err_inj_a_fine_sel_1_16                        0x1000     //Random LSB/fine-grained cycle offset variation control for pattern A, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Random offset in range of 1-16 cycles
#define     ei4_tx_err_inj_a_fine_sel_1_8                         0x2000     //Random LSB/fine-grained cycle offset variation control for pattern A, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Random offset in range of 1-8 cycles
#define     ei4_tx_err_inj_a_fine_sel_1_4                         0x3000     //Random LSB/fine-grained cycle offset variation control for pattern A, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Random offset in range of 1-4 cycles
#define     ei4_tx_err_inj_a_fine_sel_1_2                         0x4000     //Random LSB/fine-grained cycle offset variation control for pattern A, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Random offset in range of 1-2 cycles
#define     ei4_tx_err_inj_a_fine_sel_fixed1                      0x5000     //Random LSB/fine-grained cycle offset variation control for pattern A, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Fixed offset of 1 cycle
#define     ei4_tx_err_inj_a_fine_sel_fixed3                      0x6000     //Random LSB/fine-grained cycle offset variation control for pattern A, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Fixed offset of 3 cycles 
#define     ei4_tx_err_inj_a_fine_sel_fixed7                      0x7000     //Random LSB/fine-grained cycle offset variation control for pattern A, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Fixed offset of 7 cycles.
#define     ei4_tx_err_inj_a_fine_sel_clear                       0x8FFF     // Clear mask
#define     ei4_tx_err_inj_a_coarse_sel_9_24                      0x0100     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 9-24, mean of 16.5
#define     ei4_tx_err_inj_a_coarse_sel_13_20                     0x0200     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 13-20, mean of 16.5
#define     ei4_tx_err_inj_a_coarse_sel_16_19                     0x0300     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 16-19, mean of 16.5
#define     ei4_tx_err_inj_a_coarse_sel_17_18                     0x0400     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 16-17, mean of 16.5
#define     ei4_tx_err_inj_a_coarse_sel_1_8                       0x0500     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 1-8, mean of 4.5
#define     ei4_tx_err_inj_a_coarse_sel_3_6                       0x0600     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.     Range of 3-6, mean of 4.5
#define     ei4_tx_err_inj_a_coarse_sel_4_5                       0x0700     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.     Range of 4-5, mean of 4.5
#define     ei4_tx_err_inj_a_coarse_sel_fixed1                    0x0800     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 1
#define     ei4_tx_err_inj_a_coarse_sel_fixed3                    0x0900     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 3
#define     ei4_tx_err_inj_a_coarse_sel_fixed5                    0x0A00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 5
#define     ei4_tx_err_inj_a_coarse_sel_fixed6                    0x0B00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 6
#define     ei4_tx_err_inj_a_coarse_sel_fixed7                    0x0C00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 7
#define     ei4_tx_err_inj_a_coarse_sel_fixed17                   0x0D00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 17
#define     ei4_tx_err_inj_a_coarse_sel_fixed21                   0x0E00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 21
#define     ei4_tx_err_inj_a_coarse_sel_fixed25                   0x0F00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern A.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 25
#define     ei4_tx_err_inj_a_coarse_sel_clear                     0xF0FF     // Clear mask
#define     ei4_tx_err_inj_a_ber_sel                              0x0000     //Used to set the random bit error injection rate for pattern A.  When set to a binary value of N, the average bit error rate is 1/(2^N*beats*mean(msb)). 
#define     ei4_tx_err_inj_a_ber_sel_clear                        0x3FC0     // Clear mask

// ei4_tx_ber_cntl_b_pp Register field name                                 data value   Description
#define     ei4_tx_err_inj_b_rand_beat_dis                        0x8000     //Used to disable randomization of error inject on different beats of data for pattern B.
#define     ei4_tx_err_inj_b_rand_beat_dis_clear                  0x7FFF     // Clear mask
#define     ei4_tx_err_inj_b_fine_sel_1_16                        0x1000     //Random LSB/fine-grained cycle offset variation control for pattern B, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Random offset in range of 1-16 cycles
#define     ei4_tx_err_inj_b_fine_sel_1_8                         0x2000     //Random LSB/fine-grained cycle offset variation control for pattern B, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Random offset in range of 1-8 cycles
#define     ei4_tx_err_inj_b_fine_sel_1_4                         0x3000     //Random LSB/fine-grained cycle offset variation control for pattern B, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Random offset in range of 1-4 cycles
#define     ei4_tx_err_inj_b_fine_sel_1_2                         0x4000     //Random LSB/fine-grained cycle offset variation control for pattern B, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Random offset in range of 1-2 cycles
#define     ei4_tx_err_inj_b_fine_sel_fixed1                      0x5000     //Random LSB/fine-grained cycle offset variation control for pattern B, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Fixed offset of 1 cycle
#define     ei4_tx_err_inj_b_fine_sel_fixed3                      0x6000     //Random LSB/fine-grained cycle offset variation control for pattern B, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Fixed offset of 3 cycles 
#define     ei4_tx_err_inj_b_fine_sel_fixed7                      0x7000     //Random LSB/fine-grained cycle offset variation control for pattern B, where cycles are deserialized domain cycles (2 UI for EI4, 4 UI for EDI).   Fixed offset of 7 cycles.
#define     ei4_tx_err_inj_b_fine_sel_clear                       0x8FFF     // Clear mask
#define     ei4_tx_err_inj_b_coarse_sel_9_24                      0x0100     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 9-24, mean of 16.5
#define     ei4_tx_err_inj_b_coarse_sel_13_20                     0x0200     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 13-20, mean of 16.5
#define     ei4_tx_err_inj_b_coarse_sel_16_19                     0x0300     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 16-19, mean of 16.5
#define     ei4_tx_err_inj_b_coarse_sel_17_18                     0x0400     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 16-17, mean of 16.5
#define     ei4_tx_err_inj_b_coarse_sel_1_8                       0x0500     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Range of 1-8, mean of 4.5
#define     ei4_tx_err_inj_b_coarse_sel_3_6                       0x0600     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.     Range of 3-6, mean of 4.5
#define     ei4_tx_err_inj_b_coarse_sel_4_5                       0x0700     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.     Range of 4-5, mean of 4.5
#define     ei4_tx_err_inj_b_coarse_sel_fixed1                    0x0800     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 1
#define     ei4_tx_err_inj_b_coarse_sel_fixed3                    0x0900     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 3
#define     ei4_tx_err_inj_b_coarse_sel_fixed5                    0x0A00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 5
#define     ei4_tx_err_inj_b_coarse_sel_fixed6                    0x0B00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 6
#define     ei4_tx_err_inj_b_coarse_sel_fixed7                    0x0C00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 7
#define     ei4_tx_err_inj_b_coarse_sel_fixed17                   0x0D00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 17
#define     ei4_tx_err_inj_b_coarse_sel_fixed21                   0x0E00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 21
#define     ei4_tx_err_inj_b_coarse_sel_fixed25                   0x0F00     //Random MSB/coarse-grained multiplier for the base error rate counter, which controls bit error rate variation for pattern B.  There are also a number of nonrandom settings which are specifically chosen to avoid powers of two.    Fixed 25
#define     ei4_tx_err_inj_b_coarse_sel_clear                     0xF0FF     // Clear mask
#define     ei4_tx_err_inj_b_ber_sel                              0x0000     //Used to set the random bit error injection rate for pattern B.  When set to a binary value of N, the average bit error rate is 1/(2^N*beats*mean(msb)). 
#define     ei4_tx_err_inj_b_ber_sel_clear                        0x3FC0     // Clear mask

// ei4_tx_bist_cntl_pp Register field name                                  data value   Description
#define     ei4_tx_bist_en                                        0x8000     //TBD. jgr
#define     ei4_tx_bist_en_clear                                  0x7FFF     // Clear mask
#define     ei4_tx_bist_clr                                       0x4000     //TBD. jgr
#define     ei4_tx_bist_clr_clear                                 0xBFFF     // Clear mask
#define     ei4_tx_bist_prbs7_en                                  0x2000     //TBD. This field is updated by the TX BIST logic when BIST is running. jgr
#define     ei4_tx_bist_prbs7_en_clear                            0xDFFF     // Clear mask

// ei4_tx_ber_cntl_sls_pp Register field name                               data value   Description
#define     ei4_tx_err_inj_sls_mode                               0x8000     //Used to set the random bit error injection for pattern A to work during SLS transmission only. 
#define     ei4_tx_err_inj_sls_mode_clear                         0x7FFF     // Clear mask
#define     ei4_tx_err_inj_sls_all_cmd                            0x4000     //Used to qualify the SLS mode error injection for pattern A, to inject on all SLS command transmissions. 
#define     ei4_tx_err_inj_sls_all_cmd_clear                      0xBFFF     // Clear mask
#define     ei4_tx_err_inj_sls_recal                              0x2000     //Used to qualify the SLS mode error injection for pattern A, to inject on the calibration lane only when not sending an SLS command. See workbook for details.
#define     ei4_tx_err_inj_sls_recal_clear                        0xDFFF     // Clear mask
#define     ei4_tx_err_inj_sls_cmd                                0x0000     //Used to qualify the SLS mode error injection for pattern A, to inject on only this SLS command transmission. See workbook for SLS command codes.
#define     ei4_tx_err_inj_sls_cmd_clear                          0xFFC0     // Clear mask

// ei4_tx_cntl_pp Register field name                                       data value   Description
#define     ei4_tx_enable_reduced_scramble                        0x8000     //Enables reduced density of scramble pattern. 
#define     ei4_tx_enable_reduced_scramble_clear                  0x7FFF     // Clear mask

// ei4_tx_reset_cfg_pp Register field name                                  data value   Description
#define     ei4_tx_reset_cfg_hld_clear                            0x0000     // Clear mask

// ei4_tx_tdr_cntl2_pp Register field name                                  data value   Description
#define     ei4_tx_tdr_pulse_offset                               0x0000     //Offset value for TDR pulse.
#define     ei4_tx_tdr_pulse_offset_clear                         0x000F     // Clear mask

// ei4_tx_tdr_cntl3_pp Register field name                                  data value   Description
#define     ei4_tx_tdr_pulse_width                                0x0000     //With of TDR pulse.
#define     ei4_tx_tdr_pulse_width_clear                          0x000F     // Clear mask

// ei4_rx_mode_pl Register field name                                       data value   Description
#define     ei4_rx_lane_pdwn                                      0x8000     //Used to receive inhibit and fully power down a lane independent of the logical lane disable. This control is independent from the per-group logical lane disable settings (ei4_rx_lane_disable_vec*) in order to allow for flexibility. Note that this control routes through the boundary scan logic, which has dominance.  Also note that per-group registers ei4_rx_lane_disabled_vec_0_15 and ei4_rx_lane_disabled_vec_16_31 are used to logically disable a lane with respect to the training, recalibration, and repair machines so both this per-lane and the per-group registers need to be set in order to logically disable and powerdown a lane. Note that this per-lane register is adjusted for lane swizzling automatically in HW but it is NOT adjusted automatically in HW when in the MSB-LSB swap mode so the eRepair procedure needs to take care to power down the correct lane when in this mode. 
#define     ei4_rx_lane_pdwn_clear                                0x7FFF     // Clear mask
#define     ei4_rx_lane_scramble_disable                          0x0200     //Used to disable the RX descrambler on a specific lane or all lanes by using a per-lane/per-group global write.
#define     ei4_rx_lane_scramble_disable_clear                    0xFDFF     // Clear mask

// ei4_rx_cntl_pl Register field name                                       data value   Description
#define     ei4_rx_block_lock_lane                                0x8000     //Enables rotation and checking for block lock. 
#define     ei4_rx_block_lock_lane_clear                          0x7FFF     // Clear mask
#define     ei4_rx_check_skew_lane                                0x4000     //Per-Lane Initialization controls. Checks skew request
#define     ei4_rx_check_skew_lane_clear                          0xBFFF     // Clear mask

// ei4_rx_spare_mode_pl Register field name                                 data value   Description
#define     ei4_rx_pl_spare_mode_0                                0x8000     //Per-lane spare mode latch
#define     ei4_rx_pl_spare_mode_0_clear                          0x7FFF     // Clear mask
#define     ei4_rx_pl_spare_mode_1                                0x4000     //Per-lane spare mode latch
#define     ei4_rx_pl_spare_mode_1_clear                          0xBFFF     // Clear mask
#define     ei4_rx_pl_spare_mode_2                                0x2000     //Per-lane spare mode latch
#define     ei4_rx_pl_spare_mode_2_clear                          0xDFFF     // Clear mask
#define     ei4_rx_pl_spare_mode_3                                0x1000     //Per-lane spare mode latch
#define     ei4_rx_pl_spare_mode_3_clear                          0xEFFF     // Clear mask
#define     ei4_rx_pl_spare_mode_4                                0x0800     //Per-lane spare mode latch
#define     ei4_rx_pl_spare_mode_4_clear                          0xF7FF     // Clear mask
#define     ei4_rx_pl_spare_mode_5                                0x0400     //Per-lane spare mode latch
#define     ei4_rx_pl_spare_mode_5_clear                          0xFBFF     // Clear mask
#define     ei4_rx_pl_spare_mode_6                                0x0200     //Per-lane spare mode latch
#define     ei4_rx_pl_spare_mode_6_clear                          0xFDFF     // Clear mask
#define     ei4_rx_pl_spare_mode_7                                0x0100     //Per-lane spare mode latch
#define     ei4_rx_pl_spare_mode_7_clear                          0xFEFF     // Clear mask

// ei4_rx_bist_stat_pl Register field name                                  data value   Description
#define     ei4_rx_bist_err                                       0x8000     //Indicates a RXBIST error occurred.
#define     ei4_rx_bist_err_clear                                 0x7FFF     // Clear mask
#define     ei4_rx_bist_done                                      0x4000     //Indicates a RXBIST has completed. 
#define     ei4_rx_bist_done_clear                                0xBFFF     // Clear mask

// ei4_rx_offset_even_pl Register field name                                data value   Description
#define     ei4_rx_offset_even_samp1                              0x0000     //This is the vertical offset of the even sampling latch.
#define     ei4_rx_offset_even_samp1_clear                        0x80FF     // Clear mask
#define     ei4_rx_offset_even_samp0                              0x0000     //This is the vertical offset of the even sampling latch.
#define     ei4_rx_offset_even_samp0_clear                        0x7F80     // Clear mask

// ei4_rx_offset_odd_pl Register field name                                 data value   Description
#define     ei4_rx_offset_odd_samp1                               0x0000     //This is the vertical offset of the odd sampling latch.
#define     ei4_rx_offset_odd_samp1_clear                         0x00FF     // Clear mask
#define     ei4_rx_offset_odd_samp0                               0x0000     //This is the vertical offset of the odd sampling latch.
#define     ei4_rx_offset_odd_samp0_clear                         0x7F80     // Clear mask

// ei4_rx_amp_val_pl Register field name                                    data value   Description
#define     ei4_rx_amp_peak                                       0x0000     //This is the vertical offset of the pre-amp.
#define     ei4_rx_amp_peak_clear                                 0x0FFF     // Clear mask

// ei4_rx_prot_status_pl Register field name                                data value   Description
#define     ei4_rx_phaserot_val                                   0x0000     //RX Phase Rotator current value.
#define     ei4_rx_phaserot_val_clear                             0x80FF     // Clear mask

// ei4_rx_prot_mode_pl Register field name                                  data value   Description
#define     ei4_rx_phaserot_offset                                0x0000     //RX Phase Rotator fixed offset from learned value.
#define     ei4_rx_phaserot_offset_clear                          0x80FF     // Clear mask

// ei4_rx_prot_cntl_pl Register field name                                  data value   Description
#define     ei4_rx_prot_cntl_pl_dummy                             0x8000     //Per-Lane phase rotator control r/w register to make tools happy
#define     ei4_rx_prot_cntl_pl_dummy_clear                       0x7FFF     // Clear mask
#define     ei4_rx_ext_sr                                         0x0800     //RX Manual Phase Rotator Shift Right Pulse
#define     ei4_rx_ext_sr_clear                                   0xF7FF     // Clear mask
#define     ei4_rx_ext_sl                                         0x0400     //RX Manual Phase Rotator Shift Left Pulse
#define     ei4_rx_ext_sl_clear                                   0xFBFF     // Clear mask

// ei4_rx_fifo_stat_pl Register field name                                  data value   Description
#define     ei4_rx_fifo_l2u_dly                                   0x0000     //RX FIFO load-to-unload delay, initailed during FIFO init and modified thereafter by the deskew machine.  For setting X, the latency is 2*X to 2*X+2 UI.  Default is 8-10 UI.
#define     ei4_rx_fifo_l2u_dly_clear                             0x0FFF     // Clear mask
#define     ei4_rx_fifo_init                                      0x0800     //Initializes the fifo unload counter with the load counter and initializes the fifo load to unload delay
#define     ei4_rx_fifo_init_clear                                0xF7FF     // Clear mask

// ei4_rx_prbs_mode_pl Register field name                                  data value   Description
#define     ei4_rx_prbs_tap_id_pattern_b                          0x2000     //Per-Lane PRBS Tap Selector  PRBS tap point B
#define     ei4_rx_prbs_tap_id_pattern_c                          0x4000     //Per-Lane PRBS Tap Selector  PRBS tap point C
#define     ei4_rx_prbs_tap_id_pattern_d                          0x6000     //Per-Lane PRBS Tap Selector  PRBS tap point D
#define     ei4_rx_prbs_tap_id_pattern_e                          0x8000     //Per-Lane PRBS Tap Selector  PRBS tap point E
#define     ei4_rx_prbs_tap_id_pattern_F                          0xA000     //Per-Lane PRBS Tap Selector  PRBS tap point F
#define     ei4_rx_prbs_tap_id_pattern_g                          0xC000     //Per-Lane PRBS Tap Selector  PRBS tap point G
#define     ei4_rx_prbs_tap_id_pattern_h                          0xE000     //Per-Lane PRBS Tap Selector  PRBS tap point H
#define     ei4_rx_prbs_tap_id_clear                              0x1FFF     // Clear mask

// ei4_rx_vref_pl Register field name                                       data value   Description
#define     ei4_rx_vref                                           0x0000     //This is the voltage reference setting of the pre-amp.
#define     ei4_rx_vref_clear                                     0x00FF     // Clear mask

// ei4_rx_stat_pl Register field name                                       data value   Description
#define     ei4_rx_some_block_locked                              0x8000     //Per-Lane Block Lock Indicator
#define     ei4_rx_some_block_locked_clear                        0x7FFF     // Clear mask
#define     ei4_rx_all_block_locked_b                             0x4000     //Per-Lane Block Lock Indicator
#define     ei4_rx_all_block_locked_b_clear                       0xBFFF     // Clear mask
#define     ei4_rx_some_skew_valid                                0x2000     //Per-Lane Deskew Pattern B Detect Indicator
#define     ei4_rx_some_skew_valid_clear                          0xDFFF     // Clear mask
#define     ei4_rx_all_skew_valid_b                               0x1000     //Per-Lane Deskew Pattern B Detect Indicato (Active Low)r
#define     ei4_rx_all_skew_valid_b_clear                         0xEFFF     // Clear mask
#define     ei4_rx_some_prbs_synced                               0x0800     //Per-Lane PRBS Synchronization Indicator
#define     ei4_rx_some_prbs_synced_clear                         0xF7FF     // Clear mask
#define     ei4_rx_prbs_synced_b                                  0x0400     //Per-Lane PRBS Synchronization Indicator (Active Low)
#define     ei4_rx_prbs_synced_b_clear                            0xFBFF     // Clear mask
#define     ei4_rx_skew_value                                     0x0000     //Per-Lane PRBS Synchronization Count
#define     ei4_rx_skew_value_clear                               0xFC0F     // Clear mask

// ei4_rx_deskew_stat_pl Register field name                                data value   Description
#define     ei4_rx_bad_block_lock                                 0x8000     //Deskew Step block lock not established--lane marked bad
#define     ei4_rx_bad_block_lock_clear                           0x7FFF     // Clear mask
#define     ei4_rx_bad_skew                                       0x4000     //Deskew Step skew value not detected--lane marked bad
#define     ei4_rx_bad_skew_clear                                 0xBFFF     // Clear mask
#define     ei4_rx_bad_deskew                                     0x2000     //Deskew Step deskew value
#define     ei4_rx_bad_deskew_clear                               0xDFFF     // Clear mask

// ei4_rx_fir_pl Register field name                                        data value   Description
#define     ei4_rx_pl_fir_errs                                    0x8000     //A Per-Lane Register or State Machine Parity Error has occurred.
#define     ei4_rx_pl_fir_errs_clear                              0x7FFF     // Clear mask

// ei4_rx_fir_mask_pl Register field name                                   data value   Description
#define     ei4_rx_pl_fir_errs_mask                               0x8000     //FIR mask for register or state machine parity checkers in per-lane logic. A value of 1 masks the error from generating a FIR error.
#define     ei4_rx_pl_fir_errs_mask_clear                         0x7FFF     // Clear mask

// ei4_rx_fir_error_inject_pl Register field name                           data value   Description
#define     ei4_rx_pl_fir_err_inj                                 0x8000     //RX Per-Lane Parity Error Injection
#define     ei4_rx_pl_fir_err_inj_clear                           0x7FFF     // Clear mask

// ei4_rx_sls_pl Register field name                                        data value   Description
#define     ei4_rx_sls_lane_sel                                   0x8000     //Selects which lane to receive SLS Commands and Recalibration Data on
#define     ei4_rx_sls_lane_sel_clear                             0x7FFF     // Clear mask
#define     ei4_rx_9th_pattern_en                                 0x4000     //Sets RX Descrabmler to use 9th Scramble Pattern
#define     ei4_rx_9th_pattern_en_clear                           0xBFFF     // Clear mask

// ei4_rx_wt_status_pl Register field name                                  data value   Description
#define     ei4_rx_wt_lane_disabled                               0x8000     //Per-Lane Wiretest lane disabled status
#define     ei4_rx_wt_lane_disabled_clear                         0x7FFF     // Clear mask
#define     ei4_rx_wt_lane_inverted                               0x4000     //Per-Lane Wiretest lane inverted/swapped status
#define     ei4_rx_wt_lane_inverted_clear                         0xBFFF     // Clear mask
#define     ei4_rx_wt_lane_bad_code_n_stuck_1                     0x0800     //Per-Lane Wiretest Lane Bad code  N-leg stuck at 1.
#define     ei4_rx_wt_lane_bad_code_n_stuck_0                     0x1000     //Per-Lane Wiretest Lane Bad code  N-leg stuck at 0.
#define     ei4_rx_wt_lane_bad_code_p_stuck_1                     0x1800     //Per-Lane Wiretest Lane Bad code  P-leg stuck at 1.
#define     ei4_rx_wt_lane_bad_code_p_stuck_0                     0x2000     //Per-Lane Wiretest Lane Bad code  P-leg stuck at 0.
#define     ei4_rx_wt_lane_bad_code_n_or_p_floating               0x2800     //Per-Lane Wiretest Lane Bad code  N- or P- leg floating-swapping undetermined.
#define     ei4_rx_wt_lane_bad_code_p_or_n_floating               0x3000     //Per-Lane Wiretest Lane Bad code  P or N leg floating--swapping undetermined.
#define     ei4_rx_wt_lane_bad_code_unknown                       0x3800     //Per-Lane Wiretest Lane Bad code  Unknown failure.
#define     ei4_rx_wt_lane_bad_code_clear                         0xC7FF     // Clear mask

// ei4_rx_fifo_cntl_pl Register field name                                  data value   Description
#define     ei4_rx_fifo_inc_l2u_dly                               0x8000     //Increment existing FIFO load-to-unload delay register.
#define     ei4_rx_fifo_inc_l2u_dly_clear                         0x7FFF     // Clear mask
#define     ei4_rx_fifo_dec_l2u_dly                               0x4000     //Decrement existing FIFO load-to-unload delay register.
#define     ei4_rx_fifo_dec_l2u_dly_clear                         0xBFFF     // Clear mask
#define     ei4_rx_clr_skew_valid                                 0x2000     //Clear skew valid registers                            
#define     ei4_rx_clr_skew_valid_clear                           0xDFFF     // Clear mask

// ei4_rx_ber_status_pl Register field name                                 data value   Description
#define     ei4_rx_ber_count                                      0x0000     //Per-Lane (PL) Diagnostic Bit Error Rate (BER) error counter. Increments when in diagnostic BER mode AND the output of the descrambler is non-zero. This counter counts errors on every UI so it is a true BER counter.
#define     ei4_rx_ber_count_clear                                0x00FF     // Clear mask
#define     ei4_rx_ber_count_saturated                            0x0080     //PL Diag BER Error Counter saturation indicator. When '1' indicates that the error counter has saturated to the selected max value. A global per-lane read of this field will indicate if any lane error counters in the group are saturated.
#define     ei4_rx_ber_count_saturated_clear                      0xFF7F     // Clear mask
#define     ei4_rx_ber_count_frozen_by_lane                       0x0040     //PL Diag BER Error Counter and or PP Timer has been frozen by another lane's error counter being saturated.
#define     ei4_rx_ber_count_frozen_by_lane_clear                 0xFFBF     // Clear mask
#define     ei4_rx_ber_count_frozen_by_timer                      0x0020     //PL Diag BER Error Counter has been frozen by a diag BER timer becoming saturated.
#define     ei4_rx_ber_count_frozen_by_timer_clear                0xFFDF     // Clear mask
#define     ei4_rx_ber_timer_saturated                            0x0010     //PL Diag BER Timer saturation indicator. When '1' indicates that the pack BER timer has saturated to the max value. A global per-lane read of this field will indicate if any timer in the group has saturated.
#define     ei4_rx_ber_timer_saturated_clear                      0xFFEF     // Clear mask

// ei4_rx_ber_timer_0_15_pl Register field name                             data value   Description
#define     ei4_rx_ber_timer_value_0_15                           0x0000     //PL Diag BER Timer value for this lane, bits 0-15. All lanes in a pack share a timer and will have the same timer value. The value can either be read on one lane in a pack to save data collection time or all lanes can be read.
#define     ei4_rx_ber_timer_value_0_15_clear                     0x0000     // Clear mask

// ei4_rx_ber_timer_16_31_pl Register field name                            data value   Description
#define     ei4_rx_ber_timer_value_16_31                          0x0000     //PL Diag BER Timer value, bits 16-31.
#define     ei4_rx_ber_timer_value_16_31_clear                    0x0000     // Clear mask

// ei4_rx_ber_timer_32_39_pl Register field name                            data value   Description
#define     ei4_rx_ber_timer_value_32_39                          0x0000     //PL Diag BER Timer value, bits 32-39.
#define     ei4_rx_ber_timer_value_32_39_clear                    0x00FF     // Clear mask

// ei4_rx_servo_cntl_pl Register field name                                 data value   Description
#define     ei4_rx_servo_op_done                                  0x8000     //Servo Op completed
#define     ei4_rx_servo_op_done_clear                            0x7FFF     // Clear mask
#define     ei4_rx_servo_op_all_done_b                            0x4000     //All Servo Op (asserted low for global dot-Or reading)
#define     ei4_rx_servo_op_all_done_b_clear                      0xBFFF     // Clear mask
#define     ei4_rx_servo_op                                       0x0000     //Servo Operation code
#define     ei4_rx_servo_op_clear                                 0xC1FF     // Clear mask

// ei4_rx_fifo_diag_0_15_pl Register field name                             data value   Description
#define     ei4_rx_fifo_out_0_15                                  0x0000     //Diag Capture: fifo entries 0 to 15
#define     ei4_rx_fifo_out_0_15_clear                            0x0000     // Clear mask

// ei4_rx_fifo_diag_16_31_pl Register field name                            data value   Description
#define     ei4_rx_fifo_out_16_31                                 0x0000     //Diag Capture: fifo entries 16 to 31
#define     ei4_rx_fifo_out_16_31_clear                           0x0000     // Clear mask

// ei4_rx_fifo_diag_32_47_pl Register field name                            data value   Description
#define     ei4_rx_fifo_out_32_47                                 0x0000     //Diag Capture: fifo entries 32 to 47
#define     ei4_rx_fifo_out_32_47_clear                           0x0000     // Clear mask

// ei4_rx_eye_width_status_pl Register field name                           data value   Description
#define     ei4_rx_eye_width                                      0x0000     //RX Current Eye Width (in PR steps).
#define     ei4_rx_eye_width_clear                                0x00FF     // Clear mask
#define     ei4_rx_hist_min_eye_width_valid                       0x0080     //RX Historic Eye Minimum is valid for this lane.
#define     ei4_rx_hist_min_eye_width_valid_clear                 0xFF7F     // Clear mask
#define     ei4_rx_hist_min_eye_width                             0x0000     //RX Historic Eye Minimum--per-pack register valid for this lane if ei4_rx_hist_eye_min_valid is asserted for this lane.
#define     ei4_rx_hist_min_eye_width_clear                       0xDFC0     // Clear mask

// ei4_rx_eye_width_cntl_pl Register field name                             data value   Description
#define     ei4_rx_reset_hist_eye_width_min                       0x8000     //RX Historic Eye Minimum Reset--reset historic min to maximum value and clears valid bits.
#define     ei4_rx_reset_hist_eye_width_min_clear                 0x7FFF     // Clear mask

// ei4_rx_trace_pl Register field name                                      data value   Description
#define     ei4_rx_ln_trc_en                                      0x8000     //Enable tracing of this lane
#define     ei4_rx_ln_trc_en_clear                                0x7FFF     // Clear mask

// ei4_rx_servo_ber_count_pl Register field name                            data value   Description
#define     ei4_rx_servo_ber_count                                0x0000     //Servo-based bit error count.
#define     ei4_rx_servo_ber_count_clear                          0x000F     // Clear mask

// ei4_rx_eye_opt_stat_pl Register field name                               data value   Description
#define     ei4_rx_bad_eye_opt_ber                                0x8000     //Eye opt Step failed BER test--lane marked bad
#define     ei4_rx_bad_eye_opt_ber_clear                          0x7FFF     // Clear mask
#define     ei4_rx_bad_eye_opt_width                              0x4000     //Eye opt Step failed width test--lane marked bad
#define     ei4_rx_bad_eye_opt_width_clear                        0xBFFF     // Clear mask

// ei4_rx_clk_mode_pg Register field name                                   data value   Description
#define     ei4_rx_clk_pdwn                                       0x8000     //Used to disable the rx clock and put it into a low power state.
#define     ei4_rx_clk_pdwn_clear                                 0x7FFF     // Clear mask
#define     ei4_rx_clk_invert                                     0x4000     //Used to invert the polarity of the clock.
#define     ei4_rx_clk_invert_clear                               0xBFFF     // Clear mask

// ei4_rx_spare_mode_pg Register field name                                 data value   Description
#define     ei4_rx_pg_spare_mode_0                                0x8000     //Per-group spare mode latch
#define     ei4_rx_pg_spare_mode_0_clear                          0x7FFF     // Clear mask
#define     ei4_rx_pg_spare_mode_1                                0x4000     //Per-group spare mode latch
#define     ei4_rx_pg_spare_mode_1_clear                          0xBFFF     // Clear mask
#define     ei4_rx_pg_spare_mode_2                                0x2000     //Per-group spare mode latch
#define     ei4_rx_pg_spare_mode_2_clear                          0xDFFF     // Clear mask
#define     ei4_rx_pg_spare_mode_3                                0x1000     //Per-group spare mode latch
#define     ei4_rx_pg_spare_mode_3_clear                          0xEFFF     // Clear mask
#define     ei4_rx_pg_spare_mode_4                                0x0800     //Per-group spare mode latch
#define     ei4_rx_pg_spare_mode_4_clear                          0xF7FF     // Clear mask
#define     ei4_rx_pg_spare_mode_5                                0x0400     //Per-group spare mode latch
#define     ei4_rx_pg_spare_mode_5_clear                          0xFBFF     // Clear mask
#define     ei4_rx_pg_spare_mode_6                                0x0200     //Per-group spare mode latch
#define     ei4_rx_pg_spare_mode_6_clear                          0xFDFF     // Clear mask
#define     ei4_rx_pg_spare_mode_7                                0x0100     //Per-group spare mode latch
#define     ei4_rx_pg_spare_mode_7_clear                          0xFEFF     // Clear mask

// ei4_rx_stop_cntl_stat_pg Register field name                             data value   Description
#define     ei4_rx_stop_state_enable                              0x8000     //Enable State machine stop of address
#define     ei4_rx_stop_state_enable_clear                        0x7FFF     // Clear mask
#define     ei4_rx_state_stopped                                  0x4000     //State Machines stopped
#define     ei4_rx_state_stopped_clear                            0xBFFF     // Clear mask
#define     ei4_rx_resume_from_stop                               0x2000     //Resume stopped state machines and /or counters
#define     ei4_rx_resume_from_stop_clear                         0xDFFF     // Clear mask
#define     ei4_rx_stop_addr_msb                                  0x0000     //Stop address Most-significant four bits 0 to 3
#define     ei4_rx_stop_addr_msb_clear                            0xFF0F     // Clear mask
#define     ei4_rx_stop_mask_msb                                  0x0000     //Stop mask    Most-significant four bits 0 to 3
#define     ei4_rx_stop_mask_msb_clear                            0xF0F0     // Clear mask

// ei4_rx_mode_pg Register field name                                       data value   Description
#define     ei4_rx_master_mode                                    0x8000     //Master Mode
#define     ei4_rx_master_mode_clear                              0x7FFF     // Clear mask
#define     ei4_rx_disable_fence_reset                            0x4000     //Set to disable clearing of the RX and TX fence controls at the end of training. 
#define     ei4_rx_disable_fence_reset_clear                      0xBFFF     // Clear mask

// ei4_rx_bus_repair_pg Register field name                                 data value   Description
#define     ei4_rx_bus_repair_count                               0x0000     //TBD
#define     ei4_rx_bus_repair_count_clear                         0x3FFF     // Clear mask
#define     ei4_rx_bus_repair_pos_0                               0x0000     //TBD
#define     ei4_rx_bus_repair_pos_0_clear                         0xC07F     // Clear mask
#define     ei4_rx_bus_repair_pos_1                               0x0000     //TBD
#define     ei4_rx_bus_repair_pos_1_clear                         0x3F80     // Clear mask

// ei4_rx_grp_repair_vec_0_15_pg Register field name                        data value   Description
#define     ei4_rx_grp_repair_vec_0_15                            0x0000     //TBD
#define     ei4_rx_grp_repair_vec_0_15_clear                      0x0000     // Clear mask

// ei4_rx_grp_repair_vec_16_31_pg Register field name                       data value   Description
#define     ei4_rx_grp_repair_vec_16_31                           0x0000     //TBD
#define     ei4_rx_grp_repair_vec_16_31_clear                     0x0000     // Clear mask

// ei4_rx_stop_addr_lsb_pg Register field name                              data value   Description
#define     ei4_rx_stop_addr_lsb                                  0x0000     //Stop address least-significant 16 bits 4 to 19 
#define     ei4_rx_stop_addr_lsb_clear                            0x0000     // Clear mask

// ei4_rx_stop_mask_lsb_pg Register field name                              data value   Description
#define     ei4_rx_stop_mask_lsb                                  0x0000     //Stop mask    least-significant 16 bits 4 to 19
#define     ei4_rx_stop_mask_lsb_clear                            0x0000     // Clear mask

// ei4_rx_reset_act_pg Register field name                                  data value   Description
#define     ei4_rx_reset_cfg_ena                                  0x8000     //Enable Configurable Group Reset
#define     ei4_rx_reset_cfg_ena_clear                            0x7FFF     // Clear mask
#define     ei4_rx_clr_par_errs                                   0x0002     //Clear All RX Parity Error Latches
#define     ei4_rx_clr_par_errs_clear                             0xFFFD     // Clear mask
#define     ei4_rx_fir_reset                                      0x0001     //FIR Reset
#define     ei4_rx_fir_reset_clear                                0xFFFE     // Clear mask

// ei4_rx_id1_pg Register field name                                        data value   Description
#define     ei4_rx_bus_id                                         0x0000     //This field is used to programmably set the bus number that a clkgrp belongs to.
#define     ei4_rx_bus_id_clear                                   0x03FF     // Clear mask
#define     ei4_rx_group_id                                       0x0000     //This field is used to programmably set the clock group number within a bus.
#define     ei4_rx_group_id_clear                                 0xFE07     // Clear mask

// ei4_rx_id2_pg Register field name                                        data value   Description
#define     ei4_rx_last_group_id                                  0x0000     //This field is used to programmably set the last clock group number within a bus.
#define     ei4_rx_last_group_id_clear                            0x03FF     // Clear mask

// ei4_rx_id3_pg Register field name                                        data value   Description
#define     ei4_rx_start_lane_id                                  0x0000     //This field is used to programmably set the first lane position in the group but relative to the bus.
#define     ei4_rx_start_lane_id_clear                            0x80FF     // Clear mask
#define     ei4_rx_end_lane_id                                    0x0000     //This field is used to programmably set the last lane position in the group but relative to the bus.
#define     ei4_rx_end_lane_id_clear                              0x7F80     // Clear mask

// ei4_rx_sls_mode_pg Register field name                                   data value   Description
#define     ei4_rx_sls_disable                                    0x8000     //Disables receiving & decoding of SLS commands
#define     ei4_rx_sls_disable_clear                              0x7FFF     // Clear mask
#define     ei4_tx_sls_disable                                    0x4000     //Disables the sending of SLS commands
#define     ei4_tx_sls_disable_clear                              0xBFFF     // Clear mask
#define     ei4_rx_sls_cntr_tap_pts_tap2                          0x1000     //How Long the SLS RX Command Needs to be Stable for.  EDI - 32 c8 clks; EI4 - 64 c4 clks
#define     ei4_rx_sls_cntr_tap_pts_tap3                          0x2000     //How Long the SLS RX Command Needs to be Stable for.  EDI - 64 c8 clks; EI4 - 128 c4 clks
#define     ei4_rx_sls_cntr_tap_pts_tap4                          0x3000     //How Long the SLS RX Command Needs to be Stable for.  EDI - 128 c8 clks; EI4 - 256 c4 clks
#define     ei4_rx_sls_cntr_tap_pts_clear                         0xCFFF     // Clear mask
#define     ei4_rx_nonsls_cntr_tap_pts_tap2                       0x0400     //How Long a Non-SLS RX Command Needs to be Stable for (to know we have switched from an SLS command to data).  EDI - 64 c8 clks; EI4 - 128 c4 clks
#define     ei4_rx_nonsls_cntr_tap_pts_tap3                       0x0800     //How Long a Non-SLS RX Command Needs to be Stable for (to know we have switched from an SLS command to data).  EDI - 128 c8 clks; EI4 - 256 c4 clks
#define     ei4_rx_nonsls_cntr_tap_pts_tap4                       0x0C00     //How Long a Non-SLS RX Command Needs to be Stable for (to know we have switched from an SLS command to data).  EDI - 256 c8 clks; EI4 - 512 c4 clks
#define     ei4_rx_nonsls_cntr_tap_pts_clear                      0xF3FF     // Clear mask
#define     ei4_rx_sls_err_chk_run                                0x0200     //Run SLS error check counter
#define     ei4_rx_sls_err_chk_run_clear                          0xFDFF     // Clear mask

// ei4_rx_training_start_pg Register field name                             data value   Description
#define     ei4_rx_start_wiretest                                 0x8000     //When this register is written to a 1 the training state machine will run the wiretest portion of the training states.
#define     ei4_rx_start_wiretest_clear                           0x7FFF     // Clear mask
#define     ei4_rx_start_deskew                                   0x4000     //When this register is written to a 1 the training state machine will run the deskew portion of the training states.
#define     ei4_rx_start_deskew_clear                             0xBFFF     // Clear mask
#define     ei4_rx_start_eye_opt                                  0x2000     //When this register is written to a 1 the training state machine will run the data eye optimization portion of the training states.
#define     ei4_rx_start_eye_opt_clear                            0xDFFF     // Clear mask
#define     ei4_rx_start_repair                                   0x1000     //When this register is written to a 1 the training state machine will run the static lane repair portion of the training states.
#define     ei4_rx_start_repair_clear                             0xEFFF     // Clear mask
#define     ei4_rx_start_func_mode                                0x0800     //When this register is written to a 1 the training state machine will run the transition to functional data portion of the training states.
#define     ei4_rx_start_func_mode_clear                          0xF7FF     // Clear mask
#define     ei4_rx_start_bist                                     0x0400     //Run initializations for BIST before enabling the BIST state machine. 
#define     ei4_rx_start_bist_clear                               0xFBFF     // Clear mask
#define     ei4_rx_start_offset_cal                               0x0200     //Run offset cal. 
#define     ei4_rx_start_offset_cal_clear                         0xFDFF     // Clear mask
#define     ei4_rx_start_wt_bypass                                0x0100     //Run wiretest bypass. 
#define     ei4_rx_start_wt_bypass_clear                          0xFEFF     // Clear mask

// ei4_rx_training_status_pg Register field name                            data value   Description
#define     ei4_rx_wiretest_done                                  0x8000     //When this bit is read as a 1, the wiretest training state has completed. Check the corresponding ei4_rx_ts_*_failed register field for the pass/fail status of this training state.
#define     ei4_rx_wiretest_done_clear                            0x7FFF     // Clear mask
#define     ei4_rx_deskew_done                                    0x4000     //When this bit is read as a 1, the deskew training state has completed. Check the corresponding ei4_rx_ts_*_failed register field for the pass/fail status of this training state.
#define     ei4_rx_deskew_done_clear                              0xBFFF     // Clear mask
#define     ei4_rx_eye_opt_done                                   0x2000     //When this bit is read as a 1, the eye optimization training state has completed. Check the corresponding ei4_rx_ts_*_failed register field for the pass/fail status of this training state.
#define     ei4_rx_eye_opt_done_clear                             0xDFFF     // Clear mask
#define     ei4_rx_repair_done                                    0x1000     //When this bit is read as a 1, the static lane repair training state has completed. Check the corresponding ei4_rx_ts_*_failed register field for the pass/fail status of this training state.
#define     ei4_rx_repair_done_clear                              0xEFFF     // Clear mask
#define     ei4_rx_func_mode_done                                 0x0800     //When this bit is read as a 1, the transition to functional data training state has completed. Check the corresponding ei4_rx_ts_*_failed register field for the pass/fail status of this training state.
#define     ei4_rx_func_mode_done_clear                           0xF7FF     // Clear mask
#define     ei4_rx_bist_started                                   0x0400     //When this bit is read as a 1, the RX BIST initialization has finished and RX BIST has started running. 
#define     ei4_rx_bist_started_clear                             0xFBFF     // Clear mask
#define     ei4_rx_offset_cal_done                                0x0200     //When this bit is read as a 1, offset cal has completed. 
#define     ei4_rx_offset_cal_done_clear                          0xFDFF     // Clear mask
#define     ei4_rx_wt_bypass_done                                 0x0100     //When this bit is read as a 1, wiretest bypass has completed. 
#define     ei4_rx_wt_bypass_done_clear                           0xFEFF     // Clear mask
#define     ei4_rx_wiretest_failed                                0x0080     //When this bit is read as a 1, the wiretest training state encountered an error.
#define     ei4_rx_wiretest_failed_clear                          0xFF7F     // Clear mask
#define     ei4_rx_deskew_failed                                  0x0040     //When this bit is read as a 1, the deskew training state encountered an error.
#define     ei4_rx_deskew_failed_clear                            0xFFBF     // Clear mask
#define     ei4_rx_eye_opt_failed                                 0x0020     //When this bit is read as a 1, the eye optimization training state encountered an error.
#define     ei4_rx_eye_opt_failed_clear                           0xFFDF     // Clear mask
#define     ei4_rx_repair_failed                                  0x0010     //When this bit is read as a 1, the static lane repair training state encountered an error.
#define     ei4_rx_repair_failed_clear                            0xFFEF     // Clear mask
#define     ei4_rx_func_mode_failed                               0x0008     //When this bit is read as a 1, the transition to functional data training state encountered an error.
#define     ei4_rx_func_mode_failed_clear                         0xFFF7     // Clear mask
#define     ei4_rx_start_bist_failed                              0x0004     //When this bit is read as a 1, the RX BIST initialization has encountered and error. 
#define     ei4_rx_start_bist_failed_clear                        0xFFFB     // Clear mask
#define     ei4_rx_offset_cal_failed                              0x0002     //When this bit is read as a 1, offset cal has encountered an error. 
#define     ei4_rx_offset_cal_failed_clear                        0xFFFD     // Clear mask
#define     ei4_rx_wt_bypass_failed                               0x0001     //When this bit is read as a 1, wiretest bypass has encountered an error. 
#define     ei4_rx_wt_bypass_failed_clear                         0xFFFE     // Clear mask

// ei4_rx_recal_status_pg Register field name                               data value   Description
#define     ei4_rx_recal_status                                   0x0000     //RX Recalibration Status
#define     ei4_rx_recal_status_clear                             0x0000     // Clear mask

// ei4_rx_timeout_sel_pg Register field name                                data value   Description
#define     ei4_rx_sls_timeout_sel_tap1                           0x2000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  54.6us 
#define     ei4_rx_sls_timeout_sel_tap2                           0x4000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  109.2us 
#define     ei4_rx_sls_timeout_sel_tap3                           0x6000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  218.4us 
#define     ei4_rx_sls_timeout_sel_tap4                           0x8000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  436.7us 
#define     ei4_rx_sls_timeout_sel_tap5                           0xA000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  873.5us 
#define     ei4_rx_sls_timeout_sel_tap6                           0xC000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  28.0ms 
#define     ei4_rx_sls_timeout_sel_tap7                           0xE000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  infinite
#define     ei4_rx_sls_timeout_sel_clear                          0x1FFF     // Clear mask
#define     ei4_rx_ds_bl_timeout_sel_tap1                         0x0400     //Selects Deskew Block Lock Timeout value.   128k UI or 13.6us 
#define     ei4_rx_ds_bl_timeout_sel_tap2                         0x0800     //Selects Deskew Block Lock Timeout value.   256k UI or 27.3us 
#define     ei4_rx_ds_bl_timeout_sel_tap3                         0x0C00     //Selects Deskew Block Lock Timeout value.   1M UI or 109.2us 
#define     ei4_rx_ds_bl_timeout_sel_tap4                         0x1000     //Selects Deskew Block Lock Timeout value.   2M UI or 218.5us 
#define     ei4_rx_ds_bl_timeout_sel_tap5                         0x1400     //Selects Deskew Block Lock Timeout value.   4M UI or 436.9us 
#define     ei4_rx_ds_bl_timeout_sel_tap6                         0x1800     //Selects Deskew Block Lock Timeout value.   8M UI or 873.8us 
#define     ei4_rx_ds_bl_timeout_sel_tap7                         0x1C00     //Selects Deskew Block Lock Timeout value.   infinite
#define     ei4_rx_ds_bl_timeout_sel_clear                        0xE3FF     // Clear mask
#define     ei4_rx_cl_timeout_sel_tap1                            0x0080     //Selects Clock Lock Timeout value.   128k UI or 13.6us 
#define     ei4_rx_cl_timeout_sel_tap2                            0x0100     //Selects Clock Lock Timeout value.   256k UI or 27.3us 
#define     ei4_rx_cl_timeout_sel_tap3                            0x0180     //Selects Clock Lock Timeout value.   1M UI or 109.2us 
#define     ei4_rx_cl_timeout_sel_tap4                            0x0200     //Selects Clock Lock Timeout value.   2M UI or 218.5us 
#define     ei4_rx_cl_timeout_sel_tap5                            0x0280     //Selects Clock Lock Timeout value.   4M UI or 436.9us 
#define     ei4_rx_cl_timeout_sel_tap6                            0x0300     //Selects Clock Lock Timeout value.   8M UI or 873.8us 
#define     ei4_rx_cl_timeout_sel_tap7                            0x0380     //Selects Clock Lock Timeout value.   infinite
#define     ei4_rx_cl_timeout_sel_clear                           0xFC7F     // Clear mask
#define     ei4_rx_wt_timeout_sel_tap1                            0x0010     //Selects Wiretest Timeout value.   128k UI or 13.6us 
#define     ei4_rx_wt_timeout_sel_tap2                            0x0020     //Selects Wiretest Timeout value.   256k UI or 27.3us 
#define     ei4_rx_wt_timeout_sel_tap3                            0x0030     //Selects Wiretest Timeout value.   1M UI or 109.2us 
#define     ei4_rx_wt_timeout_sel_tap4                            0x0040     //Selects Wiretest Timeout value.   2M UI or 218.5us 
#define     ei4_rx_wt_timeout_sel_tap5                            0x0050     //Selects Wiretest Timeout value.   4M UI or 436.9us 
#define     ei4_rx_wt_timeout_sel_tap6                            0x0060     //Selects Wiretest Timeout value.   8M UI or 873.8us 
#define     ei4_rx_wt_timeout_sel_tap7                            0x0070     //Selects Wiretest Timeout value.   infinite
#define     ei4_rx_wt_timeout_sel_clear                           0xC78F     // Clear mask
#define     ei4_rx_ds_timeout_sel_tap1                            0x0002     //Selects Deskew  Timeout value.   128k UI or 13.6us 
#define     ei4_rx_ds_timeout_sel_tap2                            0x0004     //Selects Deskew  Timeout value.   256k UI or 27.3us 
#define     ei4_rx_ds_timeout_sel_tap3                            0x0006     //Selects Deskew  Timeout value.   1M UI or 109.2us 
#define     ei4_rx_ds_timeout_sel_tap4                            0x0008     //Selects Deskew  Timeout value.   2M UI or 218.5us 
#define     ei4_rx_ds_timeout_sel_tap5                            0x000A     //Selects Deskew  Timeout value.   4M UI or 436.9us 
#define     ei4_rx_ds_timeout_sel_tap6                            0x000C     //Selects Deskew  Timeout value.   8M UI or 873.8us 
#define     ei4_rx_ds_timeout_sel_tap7                            0x000E     //Selects Deskew  Timeout value.   infinite
#define     ei4_rx_ds_timeout_sel_clear                           0xFF11     // Clear mask

// ei4_rx_fifo_mode_pg Register field name                                  data value   Description
#define     ei4_rx_fifo_initial_l2u_dly                           0x0000     //RX FIFO Initial Load to Unload Delay. For setting X, the latency is 4*X to 4*X+4 UI.  Default is 16-20 UI.
#define     ei4_rx_fifo_initial_l2u_dly_clear                     0x0FFF     // Clear mask
#define     ei4_rx_fifo_final_l2u_dly                             0x0000     //RX FIFO Final Load to Unload Delay. For setting X, the latency is 4*X to 4*X+4 UI.  Default is 8-12 UI.
#define     ei4_rx_fifo_final_l2u_dly_clear                       0xF0FF     // Clear mask
#define     ei4_rx_fifo_max_deskew                                0x0000     //RX FIFO Max Deskew Control Value. TBD
#define     ei4_rx_fifo_max_deskew_clear                          0xFF0F     // Clear mask
#define     ei4_rx_fifo_final_l2u_min_err_thresh_tap1             0x0004     //RX FIFO error threshold used to qualify the minimum load to unload delay as bad, which is used as the point of reference for adjusting to the final load to unload delay. Note that the errors are accumulated across the entire clock group for a length of time selected by ei4_rx_eo_final_l2u_timeout_sel.   16 errors 
#define     ei4_rx_fifo_final_l2u_min_err_thresh_tap2             0x0008     //RX FIFO error threshold used to qualify the minimum load to unload delay as bad, which is used as the point of reference for adjusting to the final load to unload delay. Note that the errors are accumulated across the entire clock group for a length of time selected by ei4_rx_eo_final_l2u_timeout_sel.   128 errors 
#define     ei4_rx_fifo_final_l2u_min_err_thresh_tap3             0x000C     //RX FIFO error threshold used to qualify the minimum load to unload delay as bad, which is used as the point of reference for adjusting to the final load to unload delay. Note that the errors are accumulated across the entire clock group for a length of time selected by ei4_rx_eo_final_l2u_timeout_sel.   255 errors
#define     ei4_rx_fifo_final_l2u_min_err_thresh_clear            0xFF33     // Clear mask

// ei4_rx_sls_status_pg Register field name                                 data value   Description
#define     ei4_rx_sls_cmd_val                                    0x8000     //Current SLS Command Valid
#define     ei4_rx_sls_cmd_val_clear                              0x7FFF     // Clear mask
#define     ei4_rx_sls_cmd_encode_shadow_request                  0x0100     //Current SLS Command  Driven by the RX side to request shadowing of its receive lane from lane n-1 to lane n
#define     ei4_rx_sls_cmd_encode_shadow_done                     0x0200     //Current SLS Command  Driven by the RX side to signal now receiving lane n-1s data on lane n
#define     ei4_rx_sls_cmd_encode_shadow_repair_request           0x0300     //Current SLS Command  Driven by the RX side to request shadowing and repair of its receive lane from lane n-1 to n.
#define     ei4_rx_sls_cmd_encode_shadow_repair_done              0x0400     //Current SLS Command  Driven by the RX side to signal lane n-1 is repaired.
#define     ei4_rx_sls_cmd_encode_unshadow_request                0x0500     //Current SLS Command  Driven by the RX side to request shadowing of receive lane from lane n+1 to lane n.
#define     ei4_rx_sls_cmd_encode_unshadow_done                   0x0600     //Current SLS Command  Driven by the RX side to signal now receiving lane n+1 data on lane n
#define     ei4_rx_sls_cmd_encode_unshadow_repair_request         0x0700     //Current SLS Command  Driven by the RX side to request unshadowing and repair of its receive lane from lane n+1 to lane n.
#define     ei4_rx_sls_cmd_encode_unshadow_repair_done            0x0800     //Current SLS Command  Driven by the RX side to signal lane n+1 is repaired.
#define     ei4_rx_sls_cmd_encode_sls_exception                   0x0900     //Current SLS Command  Driven by the RX side to indicate to the other side of the bus its RX SLS lane is broken.
#define     ei4_rx_sls_cmd_encode_init_done                       0x0A00     //Current SLS Command  Driven to signal the CTLE/DFE/offset (re-
#define     ei4_rx_sls_cmd_encode_recal_request                   0x0B00     //Current SLS Command  Driven on recalibration lane x to request a recalibration of its receive recalibration lane y.
#define     ei4_rx_sls_cmd_encode_recal_running                   0x0C00     //Current SLS Command  Driven during the status reporting interval of recalibration to indicate recalibration has not completed
#define     ei4_rx_sls_cmd_encode_recal_done                      0x0D00     //Current SLS Command  Driven to indicate its recalibration is complete.
#define     ei4_rx_sls_cmd_encode_recal_failed                    0x0E00     //Current SLS Command  Driven to indicate recalibration has failed on its receive recalibration lane
#define     ei4_rx_sls_cmd_encode_recal_abort                     0x0F00     //Current SLS Command  Abort recalibration.
#define     ei4_rx_sls_cmd_encode_reserved2                       0x1000     //Current SLS Command  Reserved.010001
#define     ei4_rx_sls_cmd_encode_reserved4                       0x1200     //Current SLS Command  Reserved.
#define     ei4_rx_sls_cmd_encode_reserved5                       0x1300     //Current SLS Command  Reserved.
#define     ei4_rx_sls_cmd_encode_reserved6                       0x1400     //Current SLS Command  Reserved.
#define     ei4_rx_sls_cmd_encode_reserved7                       0x1500     //Current SLS Command  Reserved.
#define     ei4_rx_sls_cmd_encode_reserved8                       0x1600     //Current SLS Command  Reserved.
#define     ei4_rx_sls_cmd_encode_reserved9                       0x1700     //Current SLS Command  Reserved.
#define     ei4_rx_sls_cmd_encode_reserved10                      0x1800     //Current SLS Command  Reserved.
#define     ei4_rx_sls_cmd_encode_init_ack_done                   0x1900     //Current SLS Command  Driven in response to an init_done (not currently used
#define     ei4_rx_sls_cmd_encode_reserved11                      0x1A00     //Current SLS Command  Reserved.
#define     ei4_rx_sls_cmd_encode_recal_ack                       0x1B00     //Current SLS Command  Driven on recalibration lane y in response to a recal_request on its receive recalibration lane x
#define     ei4_rx_sls_cmd_encode_reserved12                      0x1C00     //Current SLS Command  Reserved.
#define     ei4_rx_sls_cmd_encode_reserved13                      0x1D00     //Current SLS Command  Reserved.
#define     ei4_rx_sls_cmd_encode_reserved14                      0x1E00     //Current SLS Command  Reserved.
#define     ei4_rx_sls_cmd_encode_recal_abort_ack                 0x1F00     //Current SLS Command  Abort recalibration acknowledge.
#define     ei4_rx_sls_cmd_encode_clear                           0xC0FF     // Clear mask
#define     ei4_rx_sls_err_chk_cnt                                0x0000     //Error count result for SLS error checking mode
#define     ei4_rx_sls_err_chk_cnt_clear                          0xFF00     // Clear mask

// ei4_rx_fir1_pg Register field name                                       data value   Description
#define     ei4_rx_pg_fir1_errs_par_err_ei4_rx_rpr_state              0x0800     //A Per-Group RXCTL Register or State Machine Parity Error has occurred. 
#define     ei4_rx_pg_fir1_errs_par_err_ei4_rx_eyeopt_state           0x0C00     //A Per-Group RXCTL Register or State Machine Parity Error has occurred. 
#define     ei4_rx_pg_fir1_errs_par_err_dsm_state                 0x0400     //A Per-Group RXCTL Register or State Machine Parity Error has occurred. 
#define     ei4_rx_pg_fir1_errs_par_err_rxdsm_state               0x0400     //A Per-Group RXCTL Register or State Machine Parity Error has occurred. 
#define     ei4_rx_pg_fir1_errs_clear                             0x0003     // Clear mask
#define     ei4_rx_pl_fir_err                                     0x0001     //Summary bit indicating an RX per-lane register or state machine parity error has occurred in one or more lanes. The ei4_rx_fir_pl register from each lane should be read to isolate to a particular piece of logic. There is no mechanism to determine which lane had the fault without reading FIR status from each lane.
#define     ei4_rx_pl_fir_err_clear                               0xFFFE     // Clear mask

// ei4_rx_fir2_pg Register field name                                       data value   Description
#define     ei4_rx_pg_fir2_errs_err_sls_hndshk_sm                 0x0200     //A Per-Group Register or State Machine Parity Error has occurred.  RXCTL SLS Handshake SM Parity Error.
#define     ei4_rx_pg_fir2_errs_clear                             0x01FF     // Clear mask

// ei4_rx_fir1_mask_pg Register field name                                  data value   Description
#define     ei4_rx_pg_fir1_errs_mask_clear                        0x0003     // Clear mask
#define     ei4_rx_pl_fir_err_mask                                0x0001     //FIR mask for the summary bit that indicates an RX register or state machine parity error has occurred. This mask bit is used to block ALL per-lane parity errors from causing a FIR error.
#define     ei4_rx_pl_fir_err_mask_clear                          0xFFFE     // Clear mask

// ei4_rx_fir2_mask_pg Register field name                                  data value   Description
#define     ei4_rx_pg_fir2_errs_mask_mask_sls_hndshk_sm           0x0200     //FIR mask for register or state machine parity checkers in per-group RX logic. A value of 1 masks the error from generating a FIR error.  RXCTL SLS Handshake SM Parity Error Mask.
#define     ei4_rx_pg_fir2_errs_mask_clear                        0x01FF     // Clear mask

// ei4_rx_fir1_error_inject_pg Register field name                          data value   Description
#define     ei4_rx_pg_fir1_err_inj_1                              0x4000     //RX Per-Group Parity Error Injection  Causes a parity flip in the specific parity checker.
#define     ei4_rx_pg_fir1_err_inj_inj_rpr_sm                     0x0800     //RX Per-Group Parity Error Injection  RXCTL Repair SM Parity Error Inject.
#define     ei4_rx_pg_fir1_err_inj_inj_eyeopt_sm                  0x0C00     //RX Per-Group Parity Error Injection  RXCTL Eyeopt SM Parity Error Inject.
#define     ei4_rx_pg_fir1_err_inj_inj_dsm_sm                     0x0400     //RX Per-Group Parity Error Injection  RXCTL Deskew SM Parity Error Inject.
#define     ei4_rx_pg_fir1_err_inj_inj_rxdsm_sm                   0x0400     //RX Per-Group Parity Error Injection  RXCTL RX Deskew SM Parity Error Inject.
#define     ei4_rx_pg_fir1_err_inj_clear                          0x0003     // Clear mask

// ei4_rx_fir2_error_inject_pg Register field name                          data value   Description
#define     ei4_rx_pg_fir2_err_inj_1                              0x2000     //RX Per-Group Parity Error Injection  Causes a parity flip in the specific parity checker.
#define     ei4_rx_pg_fir2_err_inj_inj_sls_hndshk_sm              0x0200     //RX Per-Group Parity Error Injection  RXCTL SLS Handshake SM Parity Error Inject.
#define     ei4_rx_pg_fir2_err_inj_clear                          0x01FF     // Clear mask

// ei4_rx_fir_training_pg Register field name                               data value   Description
#define     ei4_rx_pg_fir_training_error                          0x8000     //This field is now defunct and is permanently masked in the ei4_rx_fir_training_mask_pg FIR isolation register.
#define     ei4_rx_pg_fir_training_error_clear                    0x7FFF     // Clear mask
#define     ei4_rx_pg_fir_static_spare_deployed                   0x4000     //A spare lane has been deployed during training to heal a lane that was detected as bad. ei4_rx_Static_Spare_Deployed (SSD) will be set after the repair training step if during training either wiretest, deskew, eyeopt or repair has detected one or more bad lanes have been detected. The ei4_rx_bad_lane_enc_gcrmsg_pg register can be read to isolate which lane(s) were healed and the ei4_rx_bad_lane.
#define     ei4_rx_pg_fir_static_spare_deployed_clear             0xBFFF     // Clear mask
#define     ei4_rx_pg_fir_static_max_spares_exceeded              0x2000     //A lane has been detected as bad during training but there are no spare lanes available to heal it. THIS FIR WILL NOT BE SET UNTIL THE REPAIR TRAINING STEP HAS BEEN RUN. THIS IS A CATASTROPHIC FAILURE FOR THE BUS WHEN IN MISSION MODE BUT ALL TRAINING STEPS WILL STILL BE RUN ON WHATEVER GOOD LANES THERE ARE. ei4_rx_static_max_spares_exceeded will be set if wiretest, deskew, eyeopt or repair find the excessive number of bad lanes.
#define     ei4_rx_pg_fir_static_max_spares_exceeded_clear        0xDFFF     // Clear mask
#define     ei4_rx_pg_fir_dynamic_repair_error                    0x1000     //A Dynamic Repair error has occurred. The Recal Error FFDC registers should be read to help isolate to a particular piece of logic.
#define     ei4_rx_pg_fir_dynamic_repair_error_clear              0xEFFF     // Clear mask
#define     ei4_rx_pg_fir_dynamic_spare_deployed                  0x0800     //A spare lane has been deployed by ECC/CRC logic to heal a lane that was detected as bad. The ei4_rx_bad_lane_enc_gcrmsg_pg register can be read to isolate which lane(s) were healed.
#define     ei4_rx_pg_fir_dynamic_spare_deployed_clear            0xF7FF     // Clear mask
#define     ei4_rx_pg_fir_dynamic_max_spares_exceeded             0x0400     //A lane has been detected as bad by ECC/CRC logic but there are no spare lanes to heal it. THIS IS A CATASTROPHIC FAILURE FOR THE BUS.
#define     ei4_rx_pg_fir_dynamic_max_spares_exceeded_clear       0xFBFF     // Clear mask
#define     ei4_rx_pg_fir_recal_error                             0x0200     //A Recalibration Error has occurred. The Recal Error FFDC registers should be read to help isolate to a particular piece of logic.
#define     ei4_rx_pg_fir_recal_error_clear                       0xFDFF     // Clear mask
#define     ei4_rx_pg_fir_recal_spare_deployed                    0x0100     //A spare lane has been deployed during Recal to heal a lane that was detected as bad. The ei4_rx_bad_lane_enc_gcrmsg_pg register can be read to isolate which lane(s) were healed.
#define     ei4_rx_pg_fir_recal_spare_deployed_clear              0xFEFF     // Clear mask
#define     ei4_rx_pg_fir_recal_max_spares_exceeded               0x0080     //A lane has been detected as bad during Recal but there are no spare lanes to heal it. THIS IS A CATASTROPHIC FAILURE FOR THE BUS.
#define     ei4_rx_pg_fir_recal_max_spares_exceeded_clear         0xFF7F     // Clear mask
#define     ei4_rx_pg_fir_too_many_bus_errors                     0x0040     //More than one lane has been detected as having too many errors during functional operation. THIS IS A CATASTROPHIC FAILURE FOR THE BUS.
#define     ei4_rx_pg_fir_too_many_bus_errors_clear               0xFFBF     // Clear mask

// ei4_rx_fir_training_mask_pg Register field name                          data value   Description
#define     ei4_rx_pg_fir_training_error_mask                     0x8000     //FIR mask for ei4_rx_pg_fir_training_error.
#define     ei4_rx_pg_fir_training_error_mask_clear               0x7FFF     // Clear mask
#define     ei4_rx_pg_fir_static_spare_deployed_mask              0x4000     //FIR mask for ei4_rx_pg_fir_static_spare_deployed.
#define     ei4_rx_pg_fir_static_spare_deployed_mask_clear        0xBFFF     // Clear mask
#define     ei4_rx_pg_fir_static_max_spares_exceeded_mask         0x2000     //FIR mask for ei4_rx_pg_fir_static_max_spares_exceeded
#define     ei4_rx_pg_fir_static_max_spares_exceeded_mask_clear   0xDFFF     // Clear mask
#define     ei4_rx_pg_fir_dynamic_repair_error_mask               0x1000     //FIR mask for ei4_rx_pg_fir_dynamic_repair_error
#define     ei4_rx_pg_fir_dynamic_repair_error_mask_clear         0xEFFF     // Clear mask
#define     ei4_rx_pg_fir_dynamic_spare_deployed_mask             0x0800     //FIR mask for ei4_rx_pg_fir_dynamic_spare_deployed.
#define     ei4_rx_pg_fir_dynamic_spare_deployed_mask_clear       0xF7FF     // Clear mask
#define     ei4_rx_pg_fir_dynamic_max_spares_exceeded_mask        0x0400     //FIR mask for ei4_rx_pg_fir_dynamic_max_spares_exceeded.
#define     ei4_rx_pg_fir_dynamic_max_spares_exceeded_mask_clear  0xFBFF     // Clear mask
#define     ei4_rx_pg_fir_recal_error_mask                        0x0200     //FIR mask for ei4_rx_pg_fir_recal_error.
#define     ei4_rx_pg_fir_recal_error_mask_clear                  0xFDFF     // Clear mask
#define     ei4_rx_pg_fir_recal_spare_deployed_mask               0x0100     //FIR mask for ei4_rx_pg_fir_recal_spare_deployed.
#define     ei4_rx_pg_fir_recal_spare_deployed_mask_clear         0xFEFF     // Clear mask
#define     ei4_rx_pg_fir_recal_max_spares_exceeded_mask          0x0080     //FIR mask for ei4_rx_pg_fir_recal_max_spares_exceeded.
#define     ei4_rx_pg_fir_recal_max_spares_exceeded_mask_clear    0xFF7F     // Clear mask
#define     ei4_rx_pg_fir_too_many_bus_errors_mask                0x0040     //FIR mask for ei4_rx_pg_fir_too_many_bus_errors.
#define     ei4_rx_pg_fir_too_many_bus_errors_mask_clear          0xFFBF     // Clear mask

// ei4_rx_timeout_sel1_pg Register field name                               data value   Description
#define     ei4_rx_eo_offset_timeout_sel_tap1                     0x2000     //Selects Latch offset timeout.   128k UI or 13.6us 
#define     ei4_rx_eo_offset_timeout_sel_tap2                     0x4000     //Selects Latch offset timeout.   256k UI or 27.3us 
#define     ei4_rx_eo_offset_timeout_sel_tap3                     0x6000     //Selects Latch offset timeout.   1M UI or 109.2us 
#define     ei4_rx_eo_offset_timeout_sel_tap4                     0x8000     //Selects Latch offset timeout.   2M UI or 218.5us 
#define     ei4_rx_eo_offset_timeout_sel_tap5                     0xA000     //Selects Latch offset timeout.   4M UI or 436.9us 
#define     ei4_rx_eo_offset_timeout_sel_tap6                     0xC000     //Selects Latch offset timeout.   8M UI or 873.8us 
#define     ei4_rx_eo_offset_timeout_sel_tap7                     0xE000     //Selects Latch offset timeout.   infinite
#define     ei4_rx_eo_offset_timeout_sel_clear                    0x1FFF     // Clear mask
#define     ei4_rx_eo_vref_timeout_sel_tap1                       0x0400     //Selects  Vref adjust watchdog timeout (EI-4 ONLY).   128k UI or 13.6us 
#define     ei4_rx_eo_vref_timeout_sel_tap2                       0x0800     //Selects  Vref adjust watchdog timeout (EI-4 ONLY).   256k UI or 27.3us 
#define     ei4_rx_eo_vref_timeout_sel_tap3                       0x0C00     //Selects  Vref adjust watchdog timeout (EI-4 ONLY).   1M UI or 109.2us 
#define     ei4_rx_eo_vref_timeout_sel_tap4                       0x1000     //Selects  Vref adjust watchdog timeout (EI-4 ONLY).   2M UI or 218.5us 
#define     ei4_rx_eo_vref_timeout_sel_tap5                       0x1400     //Selects  Vref adjust watchdog timeout (EI-4 ONLY).   4M UI or 436.9us 
#define     ei4_rx_eo_vref_timeout_sel_tap6                       0x1800     //Selects  Vref adjust watchdog timeout (EI-4 ONLY).   8M UI or 873.8us 
#define     ei4_rx_eo_vref_timeout_sel_tap7                       0x1C00     //Selects  Vref adjust watchdog timeout (EI-4 ONLY).   infinite
#define     ei4_rx_eo_vref_timeout_sel_clear                      0xE3FF     // Clear mask
#define     ei4_rx_eo_ctle_timeout_sel_tap1                       0x0080     //Selects  CTLE ajdust watchdog timeout.   128k UI or 13.6us 
#define     ei4_rx_eo_ctle_timeout_sel_tap2                       0x0100     //Selects  CTLE ajdust watchdog timeout.   256k UI or 27.3us 
#define     ei4_rx_eo_ctle_timeout_sel_tap3                       0x0180     //Selects  CTLE ajdust watchdog timeout.   1M UI or 109.2us 
#define     ei4_rx_eo_ctle_timeout_sel_tap4                       0x0200     //Selects  CTLE ajdust watchdog timeout.   2M UI or 218.5us 
#define     ei4_rx_eo_ctle_timeout_sel_tap5                       0x0280     //Selects  CTLE ajdust watchdog timeout.   4M UI or 436.9us 
#define     ei4_rx_eo_ctle_timeout_sel_tap6                       0x0300     //Selects  CTLE ajdust watchdog timeout.   8M UI or 873.8us 
#define     ei4_rx_eo_ctle_timeout_sel_tap7                       0x0380     //Selects  CTLE ajdust watchdog timeout.   infinite
#define     ei4_rx_eo_ctle_timeout_sel_clear                      0xFC7F     // Clear mask
#define     ei4_rx_eo_et_timeout_sel_tap1                         0x0002     //Selects  Measure eye watchdog timeout (EI-4 ONLY).   128k UI or 13.6us 
#define     ei4_rx_eo_et_timeout_sel_tap2                         0x0004     //Selects  Measure eye watchdog timeout (EI-4 ONLY).   256k UI or 27.3us 
#define     ei4_rx_eo_et_timeout_sel_tap3                         0x0006     //Selects  Measure eye watchdog timeout (EI-4 ONLY).   1M UI or 109.2us 
#define     ei4_rx_eo_et_timeout_sel_tap4                         0x0008     //Selects  Measure eye watchdog timeout (EI-4 ONLY).   2M UI or 218.5us 
#define     ei4_rx_eo_et_timeout_sel_tap5                         0x000A     //Selects  Measure eye watchdog timeout (EI-4 ONLY).   4M UI or 436.9us 
#define     ei4_rx_eo_et_timeout_sel_tap6                         0x000C     //Selects  Measure eye watchdog timeout (EI-4 ONLY).   8M UI or 873.8us 
#define     ei4_rx_eo_et_timeout_sel_tap7                         0x000E     //Selects  Measure eye watchdog timeout (EI-4 ONLY).   infinite
#define     ei4_rx_eo_et_timeout_sel_clear                        0xFF11     // Clear mask
#define     ei4_rx_eo_final_l2u_timeout_sel                       0x0001     //Selects Final Load to Unload Delay qualification time per step. 
#define     ei4_rx_eo_final_l2u_timeout_sel_clear                 0xFFFE     // Clear mask

// ei4_rx_lane_bad_vec_0_15_pg Register field name                          data value   Description
#define     ei4_rx_lane_bad_vec_0_15_clear                        0x0000     // Clear mask

// ei4_rx_lane_bad_vec_16_31_pg Register field name                         data value   Description
#define     ei4_rx_lane_bad_vec_16_31                             0x0000     //Lanes found bad by HW (status) or method to force lane bad from software (control).
#define     ei4_rx_lane_bad_vec_16_31_clear                       0x0000     // Clear mask

// ei4_rx_lane_disabled_vec_0_15_pg Register field name                     data value   Description
#define     ei4_rx_lane_disabled_vec_0_15                         0x0000     //Lanes disabled by HW (status) or method to force lane to be disabled (save power) from software (control).
#define     ei4_rx_lane_disabled_vec_0_15_clear                   0x0000     // Clear mask

// ei4_rx_lane_disabled_vec_16_31_pg Register field name                    data value   Description
#define     ei4_rx_lane_disabled_vec_16_31                        0x0000     //Lanes disabled by HW (status) or method to force lane to be disabled (save power) from software (control).
#define     ei4_rx_lane_disabled_vec_16_31_clear                  0x0000     // Clear mask

// ei4_rx_lane_swapped_vec_0_15_pg Register field name                      data value   Description
#define     ei4_rx_lane_swapped_vec_0_15                          0x0000     //Wiretest found that the P & N wire legs have been swapped on the lane indicated. Has the effect of basically inverting the signal.  Note that this status is invalid if the lane is marked bad.
#define     ei4_rx_lane_swapped_vec_0_15_clear                    0x0000     // Clear mask

// ei4_rx_lane_swapped_vec_16_31_pg Register field name                     data value   Description
#define     ei4_rx_lane_swapped_vec_16_31                         0x0000     //Wiretest found that the P & N wire legs have been swapped on the lane indicated. Has the effect of basically inverting the signal.  Note that this status is invalid if the lane is marked bad.
#define     ei4_rx_lane_swapped_vec_16_31_clear                   0x0000     // Clear mask

// ei4_rx_init_state_pg Register field name                                 data value   Description
#define     ei4_rx_main_init_state_1                              0x1000     //Main Initialization State Machine(RJR):  Wiretest Running
#define     ei4_rx_main_init_state_2                              0x2000     //Main Initialization State Machine(RJR):  Deskew Running
#define     ei4_rx_main_init_state_3                              0x3000     //Main Initialization State Machine(RJR):  Eye Optimization Running
#define     ei4_rx_main_init_state_4                              0x4000     //Main Initialization State Machine(RJR):  Repair Running
#define     ei4_rx_main_init_state_5                              0x5000     //Main Initialization State Machine(RJR):  Go Functional Running
#define     ei4_rx_main_init_state_6                              0x9000     //Main Initialization State Machine(RJR):  Wiretest Failed
#define     ei4_rx_main_init_state_7                              0x5000     //Main Initialization State Machine(RJR):  Deskew Failed
#define     ei4_rx_main_init_state_8                              0xB000     //Main Initialization State Machine(RJR):  Eye Optimization Failed
#define     ei4_rx_main_init_state_9                              0xC000     //Main Initialization State Machine(RJR):  Repair Failed
#define     ei4_rx_main_init_state_10                             0xD000     //Main Initialization State Machine(RJR):  Go Functional Failed
#define     ei4_rx_main_init_state_clear                          0x0FFF     // Clear mask

// ei4_rx_wiretest_state_pg Register field name                             data value   Description
#define     ei4_rx_wtm_state_clear                                0x07FF     // Clear mask
#define     ei4_rx_wtr_state_clear                                0xF87F     // Clear mask
#define     ei4_rx_wtl_state_clear                                0x0FE0     // Clear mask

// ei4_rx_wiretest_laneinfo_pg Register field name                          data value   Description
#define     ei4_rx_wtr_cur_lane                                   0x0000     //Wiretest Current Lane Under Test(RJR)
#define     ei4_rx_wtr_cur_lane_clear                             0x07FF     // Clear mask
#define     ei4_rx_wtr_max_bad_lanes_clear                        0xF83F     // Clear mask
#define     ei4_rx_wtr_bad_lane_count                             0x0000     //Wiretest Current Number Of Bad Lanes in This Clk Group(RJR)
#define     ei4_rx_wtr_bad_lane_count_clear                       0x07E0     // Clear mask

// ei4_rx_wiretest_gcrmsgs_pg Register field name                           data value   Description
#define     ei4_rx_wt_prev_done_gcrmsg                            0x8000     //GCR Message: Previous Clk Group Has Completed Wiretest
#define     ei4_rx_wt_prev_done_gcrmsg_clear                      0x7FFF     // Clear mask
#define     ei4_rx_wt_all_done_gcrmsg                             0x4000     //GCR Message: All Clk Groups Have Completed Wiretest
#define     ei4_rx_wt_all_done_gcrmsg_clear                       0xBFFF     // Clear mask

// ei4_rx_deskew_gcrmsgs_pg Register field name                             data value   Description
#define     ei4_rx_deskew_seq_gcrmsg_dsalldeskewed                0x2000     //GCR Message: RX Deskew Sequencer GCR messages  Indicate all groups deskewed.
#define     ei4_rx_deskew_seq_gcrmsg_dsprevdone                   0x4000     //GCR Message: RX Deskew Sequencer GCR messages  Indicate prior group completed deskew.
#define     ei4_rx_deskew_seq_gcrmsg_dsalldone                    0x6000     //GCR Message: RX Deskew Sequencer GCR messages  Indicate all groups completed deskew.
#define     ei4_rx_deskew_seq_gcrmsg_dsprevskew                   0x8000     //GCR Message: RX Deskew Sequencer GCR messages  Transmit skew values from prior group.
#define     ei4_rx_deskew_seq_gcrmsg_dsmaxskew                    0xA000     //GCR Message: RX Deskew Sequencer GCR messages  Transmit max skew values to all groups.
#define     ei4_rx_deskew_seq_gcrmsg_unused                       0xC000     //GCR Message: RX Deskew Sequencer GCR messages  Unused.
#define     ei4_rx_deskew_seq_gcrmsg_dsnomsg                      0xE000     //GCR Message: RX Deskew Sequencer GCR messages  No message.
#define     ei4_rx_deskew_seq_gcrmsg_clear                        0x1FFF     // Clear mask
#define     ei4_rx_deskew_skmin_gcrmsg                            0x0000     //GCR Message: Min Skew Value for deskew sequence.
#define     ei4_rx_deskew_skmin_gcrmsg_clear                      0xF03F     // Clear mask
#define     ei4_rx_deskew_skmax_gcrmsg                            0x0000     //GCR Message: Max Skew Value for deskew sequence.
#define     ei4_rx_deskew_skmax_gcrmsg_clear                      0x0FC0     // Clear mask

// ei4_rx_deskew_state_pg Register field name                               data value   Description
#define     ei4_rx_dsm_state_clear                                0x00FF     // Clear mask
#define     ei4_rx_rxdsm_state_clear                              0x7F80     // Clear mask

// ei4_rx_deskew_mode_pg Register field name                                data value   Description
#define     ei4_rx_deskew_max_limit                               0x0000     //Maximum Deskewable Skew Fail Threshold
#define     ei4_rx_deskew_max_limit_clear                         0x03FF     // Clear mask

// ei4_rx_deskew_status_pg Register field name                              data value   Description
#define     ei4_rx_deskew_minskew_grp                             0x0000     //Deskew Per-Group Raw Skew Min
#define     ei4_rx_deskew_minskew_grp_clear                       0x03FF     // Clear mask
#define     ei4_rx_deskew_maxskew_grp                             0x0000     //Deskew Per-Group Raw Skew Max
#define     ei4_rx_deskew_maxskew_grp_clear                       0xFC0F     // Clear mask

// ei4_rx_bad_lane_enc_gcrmsg_pg Register field name                        data value   Description
#define     ei4_rx_bad_lane1_gcrmsg                               0x0000     //GCR Message: Encoded bad lane one in relation to the entire RX bus
#define     ei4_rx_bad_lane1_gcrmsg_clear                         0x01FF     // Clear mask
#define     ei4_rx_bad_lane2_gcrmsg                               0x0000     //GCR Message: Encoded bad lane two in relation to the entire RX bus
#define     ei4_rx_bad_lane2_gcrmsg_clear                         0xFE03     // Clear mask
#define     ei4_rx_bad_lane_code_gcrmsg_bad_ln1_val               0x0001     //GCR Message: RX Bad Lane Code  Bad Lane 1 Valid
#define     ei4_rx_bad_lane_code_gcrmsg_bad_lns12_val             0x0002     //GCR Message: RX Bad Lane Code  Bad Lanes 1 and 2 Valid
#define     ei4_rx_bad_lane_code_gcrmsg_3plus_bad_lns             0x0003     //GCR Message: RX Bad Lane Code  3+ bad lanes
#define     ei4_rx_bad_lane_code_gcrmsg_clear                     0xFFF0     // Clear mask

// ei4_rx_static_repair_state_pg Register field name                        data value   Description
#define     ei4_rx_rpr_state_clear                                0x03FF     // Clear mask

// ei4_rx_ei4_tx_bus_info_pg Register field name                                data value   Description
#define     ei4_rx_ei4_tx_bus_width                                   0x0000     //TX Bus Width
#define     ei4_rx_ei4_tx_bus_width_clear                             0x01FF     // Clear mask
#define     ei4_rx_ei4_rx_bus_width                                   0x0000     //RX Bus Width
#define     ei4_rx_ei4_rx_bus_width_clear                             0xFE03     // Clear mask

// ei4_rx_sls_lane_enc_gcrmsg_pg Register field name                        data value   Description
#define     ei4_rx_sls_lane_gcrmsg                                0x0000     //GCR Message: Encoded SLS lane in relation to the entire RX bus
#define     ei4_rx_sls_lane_gcrmsg_clear                          0x01FF     // Clear mask
#define     ei4_rx_sls_lane_val_gcrmsg                            0x0100     //GCR Message: RX SLS Lane Valid
#define     ei4_rx_sls_lane_val_gcrmsg_clear                      0xFEFF     // Clear mask

// ei4_rx_fence_pg Register field name                                      data value   Description
#define     ei4_rx_fence                                          0x8000     //RX fence bit
#define     ei4_rx_fence_clear                                    0x7FFF     // Clear mask

// ei4_rx_term_pg Register field name                                       data value   Description
#define     ei4_rx_term_test_mode                                 0x8000     //Termination Segment Test mode
#define     ei4_rx_term_test_mode_clear                           0x7FFF     // Clear mask
#define     ei4_rx_term_mode_enc                                  0x0000     //Slice enable for pfet/nfet pairs for termination mode.  Bits 0:3 determine how many 240ohm pairs to enable, out of 14.  Bit 4 enables a half-strength 480ohm pfet/nfet pair, and also controls whether that pair is enabled in test mode.
#define     ei4_rx_term_mode_enc_clear                            0xE0FF     // Clear mask

// ei4_rx_timeout_sel2_pg Register field name                               data value   Description
#define     ei4_rx_func_mode_timeout_sel_tap1                     0x2000     //Selects Functional Mode wait timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   128k UI or 13.7us 
#define     ei4_rx_func_mode_timeout_sel_tap2                     0x4000     //Selects Functional Mode wait timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   256k UI or 27.3us 
#define     ei4_rx_func_mode_timeout_sel_tap3                     0x6000     //Selects Functional Mode wait timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   512k UI or 54.6us 
#define     ei4_rx_func_mode_timeout_sel_tap4                     0x8000     //Selects Functional Mode wait timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   1M UI or 109.2us 
#define     ei4_rx_func_mode_timeout_sel_tap5                     0xA000     //Selects Functional Mode wait timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   2M UI or 218.5us 
#define     ei4_rx_func_mode_timeout_sel_tap6                     0xC000     //Selects Functional Mode wait timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   64M UI or 7ms
#define     ei4_rx_func_mode_timeout_sel_tap7                     0xE000     //Selects Functional Mode wait timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   infinite
#define     ei4_rx_func_mode_timeout_sel_clear                    0x1FFF     // Clear mask
#define     ei4_rx_rc_slowdown_timeout_sel_tap1                   0x0400     //Selects Recal  Slowdown      timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   128k UI or 13.7us 
#define     ei4_rx_rc_slowdown_timeout_sel_tap2                   0x0800     //Selects Recal  Slowdown      timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   256k UI or 27.3us 
#define     ei4_rx_rc_slowdown_timeout_sel_tap3                   0x0C00     //Selects Recal  Slowdown      timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   512k UI or 54.6us 
#define     ei4_rx_rc_slowdown_timeout_sel_tap4                   0x1000     //Selects Recal  Slowdown      timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   1M UI or 109.2us 
#define     ei4_rx_rc_slowdown_timeout_sel_tap5                   0x1400     //Selects Recal  Slowdown      timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   2M UI or 218.5us 
#define     ei4_rx_rc_slowdown_timeout_sel_tap6                   0x1800     //Selects Recal  Slowdown      timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   64M UI or 7ms
#define     ei4_rx_rc_slowdown_timeout_sel_tap7                   0x1C00     //Selects Recal  Slowdown      timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   infinite
#define     ei4_rx_rc_slowdown_timeout_sel_clear                  0xE3FF     // Clear mask
#define     ei4_rx_pup_lite_wait_sel_tap1                         0x0100     //How long to wait for analog logic to power up an unused spare lane for recal/repair  107ns (default value
#define     ei4_rx_pup_lite_wait_sel_tap2                         0x0200     //How long to wait for analog logic to power up an unused spare lane for recal/repair  213ns
#define     ei4_rx_pup_lite_wait_sel_tap3                         0x0300     //How long to wait for analog logic to power up an unused spare lane for recal/repair  427ns
#define     ei4_rx_pup_lite_wait_sel_clear                        0xFCFF     // Clear mask

// ei4_rx_dyn_rpr_pg Register field name                                    data value   Description
#define     ei4_rx_dyn_rpr_state_clear                            0xC0FF     // Clear mask
#define     ei4_rx_sls_hndshk_state_clear                         0xFF00     // Clear mask

// ei4_rx_dyn_rpr_gcrmsg_pg Register field name                             data value   Description
#define     ei4_rx_dyn_rpr_req_gcrmsg                             0x8000     //GCR Message: CRC/ECC Tallying logic has a Dynamic Repair Request
#define     ei4_rx_dyn_rpr_req_gcrmsg_clear                       0x7FFF     // Clear mask
#define     ei4_rx_dyn_rpr_lane2rpr_gcrmsg                        0x0000     //GCR Message: CRC/ECC Tallying logic bad lane to repair
#define     ei4_rx_dyn_rpr_lane2rpr_gcrmsg_clear                  0x80FF     // Clear mask
#define     ei4_rx_dyn_rpr_ip_gcrmsg                              0x0080     //GCR Message: CRC/ECC Bad Lane Repair In Progress
#define     ei4_rx_dyn_rpr_ip_gcrmsg_clear                        0xFF7F     // Clear mask
#define     ei4_rx_dyn_rpr_complete_gcrmsg                        0x0040     //GCR Message: CRC/ECC Bad Lane Repaired
#define     ei4_rx_dyn_rpr_complete_gcrmsg_clear                  0xFFBF     // Clear mask

// ei4_rx_dyn_rpr_err_tallying1_pg Register field name                      data value   Description
#define     ei4_rx_dyn_rpr_bad_lane_max                           0x0000     //CRC/ECC Dynamic Repair: Max number of times a lane can be found bad before repaired
#define     ei4_rx_dyn_rpr_bad_lane_max_clear                     0x01FF     // Clear mask
#define     ei4_rx_dyn_rpr_err_cntr1_duration_tap1                0x0020     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  853.0ns & 1.3uS
#define     ei4_rx_dyn_rpr_err_cntr1_duration_tap2                0x0040     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  27.3uS & 41.0uS
#define     ei4_rx_dyn_rpr_err_cntr1_duration_tap3                0x0060     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  873.5uS & 1.3mS
#define     ei4_rx_dyn_rpr_err_cntr1_duration_tap4                0x0080     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  1.7mS & 2.6mS
#define     ei4_rx_dyn_rpr_err_cntr1_duration_tap5                0x00A0     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  3.5mS & 5.1mS
#define     ei4_rx_dyn_rpr_err_cntr1_duration_tap6                0x00C0     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  7.0mS & 10.5mS
#define     ei4_rx_dyn_rpr_err_cntr1_duration_tap7                0x00E0     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  14.0mS & 21.0mS
#define     ei4_rx_dyn_rpr_err_cntr1_duration_tap8                0x0100     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  28.0mS & 41.9mS
#define     ei4_rx_dyn_rpr_err_cntr1_duration_tap9                0x0120     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  55.9mS & 83.9mS
#define     ei4_rx_dyn_rpr_err_cntr1_duration_tap10               0x0140     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  111.8mS & 167.8mS
#define     ei4_rx_dyn_rpr_err_cntr1_duration_tap11               0x0160     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  223.6mS & 335.5mS
#define     ei4_rx_dyn_rpr_err_cntr1_duration_tap12               0x0180     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  447.2mS & 671.1mS
#define     ei4_rx_dyn_rpr_err_cntr1_duration_tap13               0x01A0     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  894.4mS & 1.3 S
#define     ei4_rx_dyn_rpr_err_cntr1_duration_tap14               0x01C0     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  1.8 S & 2.7 S
#define     ei4_rx_dyn_rpr_err_cntr1_duration_tap15               0x01E0     //CRC/ECC Dynamic Repair: Duration the lane error counter1 can run before being cleared (determines the allowed error frequency)  infinite
#define     ei4_rx_dyn_rpr_err_cntr1_duration_clear               0x3E1F     // Clear mask
#define     ei4_rx_dyn_rpr_clr_err_cntr1                          0x0010     //CRC/ECC Dynamic Repair: Firmware-based clear of lane error counter1 register
#define     ei4_rx_dyn_rpr_clr_err_cntr1_clear                    0xFFEF     // Clear mask
#define     ei4_rx_dyn_rpr_disable                                0x0008     //CRC/ECC Dynamic Repair: When set, disables dynamic repair error tallying (both per lane and per bus error counters...cntr1 & cntr2)
#define     ei4_rx_dyn_rpr_disable_clear                          0xFFF7     // Clear mask
#define     ei4_rx_dyn_rpr_enc_bad_data_lane_width                0x0000     //CRC/ECC Dynamic Repair: Width of the enc_bad_data_lane vector used to determine number of 1s in clear code
#define     ei4_rx_dyn_rpr_enc_bad_data_lane_width_clear          0xFFB8     // Clear mask

// ei4_rx_eo_final_l2u_gcrmsgs_pg Register field name                       data value   Description
#define     ei4_rx_eo_final_l2u_dly_seq_gcrmsg_fl2uallchg         0x4000     //GCR Message: RX Final Load to Unload Delay GCR messages  Indicate all groups have calculated max load to unload change.
#define     ei4_rx_eo_final_l2u_dly_seq_gcrmsg_unused             0x8000     //GCR Message: RX Final Load to Unload Delay GCR messages  Unused.
#define     ei4_rx_eo_final_l2u_dly_seq_gcrmsg_fl2unomsg          0xC000     //GCR Message: RX Final Load to Unload Delay GCR messages  No message.
#define     ei4_rx_eo_final_l2u_dly_seq_gcrmsg_clear              0x3FFF     // Clear mask
#define     ei4_rx_eo_final_l2u_dly_maxchg_gcrmsg                 0x0000     //GCR Message: Max change in miniumum load to unload delay.
#define     ei4_rx_eo_final_l2u_dly_maxchg_gcrmsg_clear           0xC0FF     // Clear mask
#define     ei4_rx_eo_final_l2u_dly_chg                           0x0000     //GCR Message: Local change in miniumum load to unload delay.
#define     ei4_rx_eo_final_l2u_dly_chg_clear                     0x3FC0     // Clear mask

// ei4_rx_gcr_msg_debug_dest_ids_pg Register field name                     data value   Description
#define     ei4_rx_gcr_msg_debug_dest_bus_id_clear                0x03FF     // Clear mask
#define     ei4_rx_gcr_msg_debug_dest_group_id_clear              0xFC0F     // Clear mask

// ei4_rx_gcr_msg_debug_src_ids_pg Register field name                      data value   Description
#define     ei4_rx_gcr_msg_debug_src_bus_id_clear                 0x03FF     // Clear mask
#define     ei4_rx_gcr_msg_debug_src_group_id_clear               0xFC0F     // Clear mask

// ei4_rx_gcr_msg_debug_dest_addr_pg Register field name                    data value   Description
#define     ei4_rx_gcr_msg_debug_dest_addr_clear                  0x007F     // Clear mask
#define     ei4_rx_gcr_msg_debug_send_msg                         0x0001     //GCR Messaging Debug: Send GCR Message on rising edge of this bit.
#define     ei4_rx_gcr_msg_debug_send_msg_clear                   0xFFFE     // Clear mask

// ei4_rx_gcr_msg_debug_write_data_pg Register field name                   data value   Description
#define     ei4_rx_gcr_msg_debug_write_data_clear                 0x0000     // Clear mask

// ei4_rx_wt_clk_status_pg Register field name                              data value   Description
#define     ei4_rx_wt_clk_lane_inverted                           0x4000     //Clock Wiretest lane inverted/swapped status 
#define     ei4_rx_wt_clk_lane_inverted_clear                     0xBFFF     // Clear mask
#define     ei4_rx_wt_clk_lane_bad_code_n_stuck_1                 0x0800     //Clock Wiretest Lane Bad code  N leg stuck at 1 
#define     ei4_rx_wt_clk_lane_bad_code_n_stuck_0                 0x1000     //Clock Wiretest Lane Bad code  N leg stuck at 0 
#define     ei4_rx_wt_clk_lane_bad_code_p_stuck_1                 0x1800     //Clock Wiretest Lane Bad code  P leg stuck at 1 
#define     ei4_rx_wt_clk_lane_bad_code_p_stuck_0                 0x2000     //Clock Wiretest Lane Bad code  P leg stuck at 0 
#define     ei4_rx_wt_clk_lane_bad_code_n_or_p_floating           0x2800     //Clock Wiretest Lane Bad code  N  or P leg floating or swapping undetermined 
#define     ei4_rx_wt_clk_lane_bad_code_NOT_USED_110              0x3000     //Clock Wiretest Lane Bad code Unused.
#define     ei4_rx_wt_clk_lane_bad_code_NOT_USED_111              0x3800     //Clock Wiretest Lane Bad code Unused.
#define     ei4_rx_wt_clk_lane_bad_code_clear                     0xC7FF     // Clear mask

// ei4_rx_wiretest_pll_cntl_pg Register field name                          data value   Description
#define     ei4_rx_wt_cu_pll_pgood                                0x8000     //RX PLL/DLL Enable
#define     ei4_rx_wt_cu_pll_pgood_clear                          0x7FFF     // Clear mask
#define     ei4_rx_wt_cu_pll_reset                                0x4000     //RX PLL/DLL Enable Request
#define     ei4_rx_wt_cu_pll_reset_clear                          0xBFFF     // Clear mask
#define     ei4_rx_wt_cu_pll_pgooddly_50ns                        0x0800     //RX PLL/DLL PGOOD Delay Selects length of reset period after ei4_rx_wt_cu_pll_reset is set.   Nominal 50ns Reset per PLL Spec 
#define     ei4_rx_wt_cu_pll_pgooddly_100ns                       0x1000     //RX PLL/DLL PGOOD Delay Selects length of reset period after ei4_rx_wt_cu_pll_reset is set.   Double Nominal 50ns Reset per PLL Spec 
#define     ei4_rx_wt_cu_pll_pgooddly_960ui                       0x1800     //RX PLL/DLL PGOOD Delay Selects length of reset period after ei4_rx_wt_cu_pll_reset is set.   Typical simulation delay exceeding TX PLL 40-refclk locking period 
#define     ei4_rx_wt_cu_pll_pgooddly_unused_100                  0x2000     //RX PLL/DLL PGOOD Delay Selects length of reset period after ei4_rx_wt_cu_pll_reset is set.   Reserved 
#define     ei4_rx_wt_cu_pll_pgooddly_unused_101                  0x2800     //RX PLL/DLL PGOOD Delay Selects length of reset period after ei4_rx_wt_cu_pll_reset is set.   Reserved 
#define     ei4_rx_wt_cu_pll_pgooddly_MAX                         0x3000     //RX PLL/DLL PGOOD Delay Selects length of reset period after ei4_rx_wt_cu_pll_reset is set.   1024 UI  
#define     ei4_rx_wt_cu_pll_pgooddly_disable                     0x3800     //RX PLL/DLL PGOOD Delay Selects length of reset period after ei4_rx_wt_cu_pll_reset is set.   Disable ei4_rx_wt_cu_pll_reset
#define     ei4_rx_wt_cu_pll_pgooddly_clear                       0xC7FF     // Clear mask
#define     ei4_rx_wt_cu_pll_lock                                 0x0400     //RX PLL/DLL Locked
#define     ei4_rx_wt_cu_pll_lock_clear                           0xFBFF     // Clear mask
#define     ei4_rx_wt_pll_refclksel                               0x0200     //Select between IO clock and BIST/Refclock
#define     ei4_rx_wt_pll_refclksel_clear                         0xFDFF     // Clear mask

// ei4_rx_eo_step_cntl_pg Register field name                               data value   Description
#define     ei4_rx_eo_enable_latch_offset_cal                     0x8000     //RX eye optimization latch offset adjustment enable
#define     ei4_rx_eo_enable_latch_offset_cal_clear               0x7FFF     // Clear mask
#define     ei4_rx_eo_enable_ctle_cal                             0x4000     //RX eye optimization CTLE/Peakin enable
#define     ei4_rx_eo_enable_ctle_cal_clear                       0xBFFF     // Clear mask
#define     ei4_rx_eo_enable_vref_cal                             0x1000     //RX eye optimization VRef adjust enable
#define     ei4_rx_eo_enable_vref_cal_clear                       0xEFFF     // Clear mask
#define     ei4_rx_eo_enable_measure_eye_width                    0x0100     //RX eye optimization Eye width check enable
#define     ei4_rx_eo_enable_measure_eye_width_clear              0xFEFF     // Clear mask
#define     ei4_rx_eo_enable_final_l2u_adj                        0x0080     //RX eye optimization Final RX FIFO load-to-unload delay adjustment enable
#define     ei4_rx_eo_enable_final_l2u_adj_clear                  0xFF7F     // Clear mask
#define     ei4_rx_eo_enable_ber_test                             0x0040     //RX eye optimization Bit error rate test enable
#define     ei4_rx_eo_enable_ber_test_clear                       0xFFBF     // Clear mask
#define     ei4_rx_eo_enable_result_check                         0x0020     //RX eye optimization Final results check enable
#define     ei4_rx_eo_enable_result_check_clear                   0xFFDF     // Clear mask

// ei4_rx_eo_step_stat_pg Register field name                               data value   Description
#define     ei4_rx_eo_latch_offset_done                           0x8000     //RX eye optimization latch offset adjustment done
#define     ei4_rx_eo_latch_offset_done_clear                     0x7FFF     // Clear mask
#define     ei4_rx_eo_ctle_done                                   0x4000     //RX eye optimization CTLE/Peaking done
#define     ei4_rx_eo_ctle_done_clear                             0xBFFF     // Clear mask
#define     ei4_rx_eo_vref_done                                   0x1000     //RX eye optimization VRef adjust done
#define     ei4_rx_eo_vref_done_clear                             0xEFFF     // Clear mask
#define     ei4_rx_eo_measure_eye_width_done                      0x0100     //RX eye optimization Eye width check done
#define     ei4_rx_eo_measure_eye_width_done_clear                0xFEFF     // Clear mask
#define     ei4_rx_eo_final_l2u_adj_done                          0x0080     //RX eye optimization Final RX FIFO load-to-unload adjust done
#define     ei4_rx_eo_final_l2u_adj_done_clear                    0xFF7F     // Clear mask
#define     ei4_rx_eo_result_check_done                           0x0010     //RX eye optimization Eye width/heightER check done 
#define     ei4_rx_eo_result_check_done_clear                     0xFFEF     // Clear mask

// ei4_rx_eo_step_fail_pg Register field name                               data value   Description
#define     ei4_rx_eo_latch_offset_failed                         0x8000     //RX eye optimization latch offset adjustment  failed
#define     ei4_rx_eo_latch_offset_failed_clear                   0x7FFF     // Clear mask
#define     ei4_rx_eo_ctle_failed                                 0x4000     //RX eye optimization CTLE/Peaking  failed
#define     ei4_rx_eo_ctle_failed_clear                           0xBFFF     // Clear mask
#define     ei4_rx_eo_vref_failed                                 0x1000     //RX eye optimization VRef adjust  failed
#define     ei4_rx_eo_vref_failed_clear                           0xEFFF     // Clear mask
#define     ei4_rx_eo_measure_eye_width_failed                    0x0100     //RX eye optimization Measure eye width failed
#define     ei4_rx_eo_measure_eye_width_failed_clear              0xFEFF     // Clear mask
#define     ei4_rx_eo_final_l2u_adj_failed                        0x0080     //RX eye optimization Final RX FIFO load-to-unload adjust  failed
#define     ei4_rx_eo_final_l2u_adj_failed_clear                  0xFF7F     // Clear mask
#define     ei4_rx_eo_result_check_failed                         0x0040     //RX eye optimization Final Result checking failed
#define     ei4_rx_eo_result_check_failed_clear                   0xFFBF     // Clear mask

// ei4_rx_amp_val_pg Register field name                                    data value   Description
#define     ei4_rx_amp_peak_work                                  0x0000     //Rx amp peak working register
#define     ei4_rx_amp_peak_work_clear                            0x0FFF     // Clear mask

// ei4_rx_sls_rcvy_pg Register field name                                   data value   Description
#define     ei4_rx_sls_rcvy_disable                               0x8000     //Disable SLS Recovery
#define     ei4_rx_sls_rcvy_disable_clear                         0x7FFF     // Clear mask
#define     ei4_rx_sls_rcvy_state_clear                           0xE0FF     // Clear mask

// ei4_rx_sls_rcvy_gcrmsg_pg Register field name                            data value   Description
#define     ei4_rx_sls_rcvy_req_gcrmsg                            0x8000     //GCR Message: SLS Rcvy; RX Lane Repair Req
#define     ei4_rx_sls_rcvy_req_gcrmsg_clear                      0x7FFF     // Clear mask
#define     ei4_rx_sls_rcvy_ip_gcrmsg                             0x4000     //GCR Message: SLS Rcvy; RX Lane Repair IP
#define     ei4_rx_sls_rcvy_ip_gcrmsg_clear                       0xBFFF     // Clear mask
#define     ei4_rx_sls_rcvy_done_gcrmsg                           0x2000     //GCR Message: SLS Rcvy; RX Lane Repair Done
#define     ei4_rx_sls_rcvy_done_gcrmsg_clear                     0xDFFF     // Clear mask

// ei4_rx_ei4_tx_lane_info_gcrmsg_pg Register field name                        data value   Description
#define     ei4_rx_ei4_tx_bad_lane_cntr_gcrmsg                        0x0000     //GCR Message: RX Side TX Bad Lane Counter
#define     ei4_rx_ei4_tx_bad_lane_cntr_gcrmsg_clear                  0x3FFF     // Clear mask

// ei4_rx_err_tallying_gcrmsg_pg Register field name                        data value   Description
#define     ei4_rx_dis_synd_tallying_gcrmsg                       0x8000     //GCR Message: Disable Syndrome Tallying
#define     ei4_rx_dis_synd_tallying_gcrmsg_clear                 0x7FFF     // Clear mask

// ei4_rx_trace_pg Register field name                                      data value   Description
#define     ei4_rx_trc_mode_tap1                                  0x1000     //RX Trace Mode  Dynamic Repair State Machines
#define     ei4_rx_trc_mode_tap2                                  0x2000     //RX Trace Mode  SLS Handshake State Machines with Recovery
#define     ei4_rx_trc_mode_tap3                                  0x3000     //RX Trace Mode  Dynamic Recal State Machines
#define     ei4_rx_trc_mode_tap4                                  0x4000     //RX Trace Mode  Recal Handshake State Machine with Recovery
#define     ei4_rx_trc_mode_tap5                                  0x5000     //RX Trace Mode  CRC or ECC Tallying Logic
#define     ei4_rx_trc_mode_tap6                                  0x6000     //RX Trace Mode  RX SLS Commands
#define     ei4_rx_trc_mode_tap7                                  0x7000     //RX Trace Mode  RX Bad Lanes
#define     ei4_rx_trc_mode_tap8                                  0x8000     //RX Trace Mode  RX SLS Lanes
#define     ei4_rx_trc_mode_tap9                                  0x9000     //RX Trace Mode  GCR
#define     ei4_rx_trc_mode_tap10                                 0xA000     //RX Trace Mode  Per Lane / Per Pack Trace (see ei4_rx_pp_trc_mode for details
#define     ei4_rx_trc_mode_tap11                                 0xB000     //RX Trace Mode  TBD
#define     ei4_rx_trc_mode_tap12                                 0xC000     //RX Trace Mode  TBD
#define     ei4_rx_trc_mode_tap13                                 0xD000     //RX Trace Mode  TBD
#define     ei4_rx_trc_mode_tap14                                 0xE000     //RX Trace Mode  TBD
#define     ei4_rx_trc_mode_tap15                                 0xF000     //RX Trace Mode  TBD
#define     ei4_rx_trc_mode_clear                                 0x0FFF     // Clear mask
#define     ei4_rx_trc_grp_clear                                  0xFC0F     // Clear mask

// ei4_rx_rdt_cntl_pg Register field name                                   data value   Description
#define     ei4_rx_run_rdt                                        0x8000     //RCV RDT pattern 0:(0) RDT off 
#define     ei4_rx_run_rdt_clear                                  0x7FFF     // Clear mask
#define     ei4_rx_rdt_check_mask                                 0x0000     //RCV RDT bit mask:  11111 checks all bits, otherwise only check the bit specified
#define     ei4_rx_rdt_check_mask_clear                           0xC1FF     // Clear mask
#define     ei4_rx_rdt_failed                                     0x0100     //RCV RDT FAILED
#define     ei4_rx_rdt_failed_clear                               0xFEFF     // Clear mask

// ei4_rx_rc_step_cntl_pg Register field name                               data value   Description
#define     ei4_rx_rc_enable_edge_track                           0x1000     //RX recalibration    Eye tracking
#define     ei4_rx_rc_enable_edge_track_clear                     0xEFFF     // Clear mask
#define     ei4_rx_rc_enable_measure_eye_width                    0x0100     //RX recalibration    Eye width check enable
#define     ei4_rx_rc_enable_measure_eye_width_clear              0xFEFF     // Clear mask
#define     ei4_rx_rc_enable_result_check                         0x0040     //RX recalibration    Final results check enable
#define     ei4_rx_rc_enable_result_check_clear                   0xFFBF     // Clear mask
#define     ei4_rx_rc_enable_dll_update                           0x0020     //RX recalibration    DLL update enable
#define     ei4_rx_rc_enable_dll_update_clear                     0xFFDF     // Clear mask

// ei4_rx_eo_recal_pg Register field name                                   data value   Description
#define     ei4_rx_eye_opt_state                                  0x0000     //Common EDI/EI4 Eye optimizaton State Machine
#define     ei4_rx_eye_opt_state_clear                            0x00FF     // Clear mask
#define     ei4_rx_recal_state                                    0x0000     //Common EDI/EI4 recalibration State Machine
#define     ei4_rx_recal_state_clear                              0xFF00     // Clear mask

// ei4_rx_servo_ber_count_pg Register field name                            data value   Description
#define     ei4_rx_servo_ber_count_work                           0x0000     //Rx servo-based bit error rate count working register
#define     ei4_rx_servo_ber_count_work_clear                     0x000F     // Clear mask

// ei4_rx_func_state_pg Register field name                                 data value   Description
#define     ei4_rx_func_mode_state                                0x0000     //Functional Mode State Machine(RJR):
#define     ei4_rx_func_mode_state_clear                          0x0FFF     // Clear mask

// ei4_rx_dyn_rpr_debug_pg Register field name                              data value   Description
#define     ei4_rx_dyn_rpr_enc_bad_data_lane_debug                0x0000     //For testfloor/debug purposes, specify the encoded bad data lane to report to the dynamic repair tally logic
#define     ei4_rx_dyn_rpr_enc_bad_data_lane_debug_clear          0x01FF     // Clear mask
#define     ei4_rx_dyn_rpr_bad_lane_valid_debug                   0x0080     //For testfloor/debug purposes, the specified encoded bad data lane will be tallied as having one cycle of a valid CRC/ECC error (this is a write-only pulse register)
#define     ei4_rx_dyn_rpr_bad_lane_valid_debug_clear             0xFF7F     // Clear mask

// ei4_rx_dyn_rpr_err_tallying2_pg Register field name                      data value   Description
#define     ei4_rx_dyn_rpr_bad_bus_max                            0x0000     //CRC/ECC Dynamic Repair: Max number of times CRC or ECC errors can be found on the bus (not included in the bad lane cntr1 tally) before setting a FIR error
#define     ei4_rx_dyn_rpr_bad_bus_max_clear                      0x01FF     // Clear mask
#define     ei4_rx_dyn_rpr_err_cntr2_duration_tap1                0x0020     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  853.0ns & 1.3uS
#define     ei4_rx_dyn_rpr_err_cntr2_duration_tap2                0x0040     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  27.3uS & 41.0uS
#define     ei4_rx_dyn_rpr_err_cntr2_duration_tap3                0x0060     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  873.5uS & 1.3mS
#define     ei4_rx_dyn_rpr_err_cntr2_duration_tap4                0x0080     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  1.7mS & 2.6mS
#define     ei4_rx_dyn_rpr_err_cntr2_duration_tap5                0x00A0     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  3.5mS & 5.1mS
#define     ei4_rx_dyn_rpr_err_cntr2_duration_tap6                0x00C0     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  7.0mS & 10.5mS
#define     ei4_rx_dyn_rpr_err_cntr2_duration_tap7                0x00E0     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  14.0mS & 21.0mS
#define     ei4_rx_dyn_rpr_err_cntr2_duration_tap8                0x0100     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  28.0mS & 41.9mS
#define     ei4_rx_dyn_rpr_err_cntr2_duration_tap9                0x0120     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  55.9mS & 83.9mS
#define     ei4_rx_dyn_rpr_err_cntr2_duration_tap10               0x0140     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  111.8mS & 167.8mS
#define     ei4_rx_dyn_rpr_err_cntr2_duration_tap11               0x0160     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  223.6mS & 335.5mS
#define     ei4_rx_dyn_rpr_err_cntr2_duration_tap12               0x0180     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  447.2mS & 671.1mS
#define     ei4_rx_dyn_rpr_err_cntr2_duration_tap13               0x01A0     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  894.4mS & 1.3 S
#define     ei4_rx_dyn_rpr_err_cntr2_duration_tap14               0x01C0     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  1.8 S & 2.7 S
#define     ei4_rx_dyn_rpr_err_cntr2_duration_tap15               0x01E0     //CRC/ECC Dynamic Repair: Duration the bad bus cntr2 error counter can run before being cleared (determines the allowed error frequency)  infinite
#define     ei4_rx_dyn_rpr_err_cntr2_duration_clear               0x3E1F     // Clear mask
#define     ei4_rx_dyn_rpr_clr_err_cntr2                          0x0010     //CRC/ECC Dynamic Repair: Firmware-based clear of bus error counter2 register
#define     ei4_rx_dyn_rpr_clr_err_cntr2_clear                    0xFFEF     // Clear mask

// ei4_rx_result_chk_pg Register field name                                 data value   Description
#define     ei4_rx_min_eye_width                                  0x0000     //Minimum acceptable eye width used during init or recal results checking--EDI or EI4
#define     ei4_rx_min_eye_width_clear                            0xC0FF     // Clear mask

// ei4_rx_sls_rcvy_fin_gcrmsg_pg Register field name                        data value   Description
#define     ei4_rx_slv_shdw_done_fin_gcrmsg                       0x8000     //GCR Message: Slave RX SLS Lane Repaired; Need to finish slave shadow handshake starting with waiting for shdw_done
#define     ei4_rx_slv_shdw_done_fin_gcrmsg_clear                 0x7FFF     // Clear mask
#define     ei4_rx_slv_shdw_nop_fin_gcrmsg                        0x4000     //GCR Message: Slave RX SLS Lane Repaired; Need to finish slave shadow handshake starting with waiting for nop
#define     ei4_rx_slv_shdw_nop_fin_gcrmsg_clear                  0xBFFF     // Clear mask
#define     ei4_rx_slv_shdw_rpr_done_fin_gcrmsg                   0x2000     //GCR Message: Slave RX SLS Lane Repaired; Need to finish slave shadow handshake starting with waiting for shdw_rpr_done
#define     ei4_rx_slv_shdw_rpr_done_fin_gcrmsg_clear             0xDFFF     // Clear mask
#define     ei4_rx_slv_shdw_rpr_nop_fin_gcrmsg                    0x1000     //GCR Message: Slave RX SLS Lane Repaired; Need to finish slave shadow handshake starting with waiting for nop
#define     ei4_rx_slv_shdw_rpr_nop_fin_gcrmsg_clear              0xEFFF     // Clear mask
#define     ei4_rx_slv_unshdw_done_fin_gcrmsg                     0x0800     //GCR Message: Slave RX SLS Lane Repaired; Need to finish slave shadow handshake starting with waiting for unshdw_done
#define     ei4_rx_slv_unshdw_done_fin_gcrmsg_clear               0xF7FF     // Clear mask
#define     ei4_rx_slv_unshdw_nop_fin_gcrmsg                      0x0400     //GCR Message: Slave RX SLS Lane Repaired; Need to finish slave shadow handshake starting with waiting for nop
#define     ei4_rx_slv_unshdw_nop_fin_gcrmsg_clear                0xFBFF     // Clear mask
#define     ei4_rx_slv_unshdw_rpr_done_fin_gcrmsg                 0x0200     //GCR Message: Slave RX SLS Lane Repaired; Need to finish slave shadow handshake starting with waiting for unshdw_rpr_done
#define     ei4_rx_slv_unshdw_rpr_done_fin_gcrmsg_clear           0xFDFF     // Clear mask
#define     ei4_rx_slv_unshdw_rpr_nop_fin_gcrmsg                  0x0100     //GCR Message: Slave RX SLS Lane Repaired; Need to finish slave shadow handshake starting with waiting for nop
#define     ei4_rx_slv_unshdw_rpr_nop_fin_gcrmsg_clear            0xFEFF     // Clear mask
#define     ei4_rx_slv_recal_done_nop_fin_gcrmsg                  0x0080     //GCR Message: Slave Recal Done; Need to finish slave recal handshake starting with waiting for nop
#define     ei4_rx_slv_recal_done_nop_fin_gcrmsg_clear            0xFF7F     // Clear mask
#define     ei4_rx_slv_recal_fail_nop_fin_gcrmsg                  0x0040     //GCR Message: Slave Recal Fail; Need to finish slave recal handshake starting with waiting for nop
#define     ei4_rx_slv_recal_fail_nop_fin_gcrmsg_clear            0xFFBF     // Clear mask
#define     ei4_rx_slv_recal_presults_fin_gcrmsg                  0x0020     //GCR Message: Slave Recal Pass Results; Need to finish slave recal handshake starting with waiting for results
#define     ei4_rx_slv_recal_presults_fin_gcrmsg_clear            0xFFDF     // Clear mask
#define     ei4_rx_slv_recal_fresults_fin_gcrmsg                  0x0010     //GCR Message: Slave Recal Fail Results; Need to finish slave recal handshake starting with waiting for results
#define     ei4_rx_slv_recal_fresults_fin_gcrmsg_clear            0xFFEF     // Clear mask
#define     ei4_rx_slv_recal_abort_ack_fin_gcrmsg                 0x0008     //GCR Message: Slave Recal Abort; Need to finish slave recal handshake starting with waiting for nop
#define     ei4_rx_slv_recal_abort_ack_fin_gcrmsg_clear           0xFFF7     // Clear mask
#define     ei4_rx_slv_recal_abort_mnop_fin_gcrmsg                0x0004     //GCR Message: Slave Recal Abort; Need to finish slave recal handshake starting with waiting for nop
#define     ei4_rx_slv_recal_abort_mnop_fin_gcrmsg_clear          0xFFFB     // Clear mask
#define     ei4_rx_slv_recal_abort_snop_fin_gcrmsg                0x0002     //GCR Message: Slave Recal Abort; Need to finish slave recal handshake starting with waiting for nop
#define     ei4_rx_slv_recal_abort_snop_fin_gcrmsg_clear          0xFFFD     // Clear mask

// ei4_rx_wiretest_pp Register field name                                   data value   Description
#define     ei4_rx_wt_pattern_length_256                          0x4000     //RX Wiretest Pattern Length  256
#define     ei4_rx_wt_pattern_length_512                          0x8000     //RX Wiretest Pattern Length  512
#define     ei4_rx_wt_pattern_length_1024                         0xC000     //RX Wiretest Pattern Length  1024
#define     ei4_rx_wt_pattern_length_clear                        0x3FFF     // Clear mask

// ei4_rx_mode1_pp Register field name                                      data value   Description
#define     ei4_rx_reduced_scramble_mode_disable_1                0x4000     //Sets reduced density of scramble pattern.   Disable reduced density 
#define     ei4_rx_reduced_scramble_mode_enable_div2              0x8000     //Sets reduced density of scramble pattern.   Enable Div2 Reduced Density 
#define     ei4_rx_reduced_scramble_mode_enable_div4              0xC000     //Sets reduced density of scramble pattern.   Enable Div4 Reduced Density
#define     ei4_rx_reduced_scramble_mode_clear                    0x3FFF     // Clear mask
#define     ei4_rx_act_check_timeout_sel_128ui                    0x0800     //Sets Activity check timeout value.   128 UI 
#define     ei4_rx_act_check_timeout_sel_256ui                    0x1000     //Sets Activity check timeout value.   256 UI 
#define     ei4_rx_act_check_timeout_sel_512ui                    0x1800     //Sets Activity check timeout value.   512 UI 
#define     ei4_rx_act_check_timeout_sel_1024ui                   0x2000     //Sets Activity check timeout value.   1024 UI 
#define     ei4_rx_act_check_timeout_sel_2048ui                   0x2800     //Sets Activity check timeout value.   2048 UI 
#define     ei4_rx_act_check_timeout_sel_4096ui                   0x3000     //Sets Activity check timeout value.   4096 UI 
#define     ei4_rx_act_check_timeout_sel_infinite                 0x3800     //Sets Activity check timeout value.   Infinite
#define     ei4_rx_act_check_timeout_sel_clear                    0xC7FF     // Clear mask
#define     ei4_rx_block_lock_timeout_sel_1024ui                  0x0100     //Sets block lock timeout value.   1024 UI 
#define     ei4_rx_block_lock_timeout_sel_2048ui                  0x0200     //Sets block lock timeout value.   2048 UI 
#define     ei4_rx_block_lock_timeout_sel_4096ui                  0x0300     //Sets block lock timeout value.   4096 UI 
#define     ei4_rx_block_lock_timeout_sel_8192ui                  0x0400     //Sets block lock timeout value.   8192 UI 
#define     ei4_rx_block_lock_timeout_sel_16384ui                 0x0500     //Sets block lock timeout value.   16384 UI 
#define     ei4_rx_block_lock_timeout_sel_32768ui                 0x0600     //Sets block lock timeout value.   32768 UI 
#define     ei4_rx_block_lock_timeout_sel_infinite                0x0700     //Sets block lock timeout value.   Infinite
#define     ei4_rx_block_lock_timeout_sel_clear                   0xF8FF     // Clear mask
#define     ei4_rx_bit_lock_timeout_sel_512ui                     0x0020     //Sets bit lock/edge detect timeout value.   512 UI 
#define     ei4_rx_bit_lock_timeout_sel_1024ui                    0x0040     //Sets bit lock/edge detect timeout value.   1024 UI 
#define     ei4_rx_bit_lock_timeout_sel_2048ui                    0x0060     //Sets bit lock/edge detect timeout value.   2048 UI 
#define     ei4_rx_bit_lock_timeout_sel_4096ui                    0x0080     //Sets bit lock/edge detect timeout value.   4096 UI 
#define     ei4_rx_bit_lock_timeout_sel_8192ui                    0x00A0     //Sets bit lock/edge detect timeout value.   8192 UI 
#define     ei4_rx_bit_lock_timeout_sel_16384ui                   0x00C0     //Sets bit lock/edge detect timeout value.   16384 UI 
#define     ei4_rx_bit_lock_timeout_sel_infinite                  0x00E0     //Sets bit lock/edge detect timeout value.   Infinite
#define     ei4_rx_bit_lock_timeout_sel_clear                     0x1F1F     // Clear mask
#define     ei4_rx_reverse_shift                                  0x0002     //RX Phase Rotator Direction
#define     ei4_rx_reverse_shift_clear                            0xFFFD     // Clear mask
#define     ei4_rx_ei3_mode                                       0x0001     //EI3 mode - See also ei4_tx_ei3_mode 
#define     ei4_rx_ei3_mode_clear                                 0xFFFE     // Clear mask

// ei4_rx_cntl_pp Register field name                                       data value   Description
#define     ei4_rx_prbs_check_sync                                0x4000     //Enables checking for the 12 ui scramble sync pattern. 
#define     ei4_rx_prbs_check_sync_clear                          0xBFFF     // Clear mask
#define     ei4_rx_enable_reduced_scramble                        0x2000     //Enables reduced density of scramble pattern. 
#define     ei4_rx_enable_reduced_scramble_clear                  0xDFFF     // Clear mask
#define     ei4_rx_prbs_inc                                       0x1000     //Shift the PRBS pattern forward in time by one extra local cycle (4ui for EDI, 2ui for EI4).
#define     ei4_rx_prbs_inc_clear                                 0xEFFF     // Clear mask
#define     ei4_rx_prbs_dec                                       0x0800     //Shift the PRBS pattern back in time by holding it one local cycle (4ui for EDI, 2ui for EI4).
#define     ei4_rx_prbs_dec_clear                                 0xF7FF     // Clear mask

// ei4_rx_ei4_cal_cntl_pp Register field name                               data value   Description
#define     ei4_rx_ddc_use_cyc_block_lock                         0x8000     //0 - use phase rot, 1 - use cycle sim block lock
#define     ei4_rx_ddc_use_cyc_block_lock_clear                   0x7FFF     // Clear mask

// ei4_rx_ei4_cal_inc_a_d_pp Register field name                            data value   Description
#define     ei4_rx_cal_inc_val_A                                  0x0000     //RX Servo Accum Inc Value A
#define     ei4_rx_cal_inc_val_A_clear                            0x0FFF     // Clear mask
#define     ei4_rx_cal_inc_val_B                                  0x0000     //RX Servo Accum Inc Value B
#define     ei4_rx_cal_inc_val_B_clear                            0xF0FF     // Clear mask
#define     ei4_rx_cal_inc_val_C                                  0x0000     //RX Servo Accum Inc Value C
#define     ei4_rx_cal_inc_val_C_clear                            0xFF0F     // Clear mask
#define     ei4_rx_cal_inc_val_D                                  0x0000     //RX Servo Accum Inc Value D
#define     ei4_rx_cal_inc_val_D_clear                            0xF0F0     // Clear mask

// ei4_rx_ei4_cal_inc_e_h_pp Register field name                            data value   Description
#define     ei4_rx_cal_inc_val_E                                  0x0000     //RX Servo Accum Inc Value E
#define     ei4_rx_cal_inc_val_E_clear                            0x0FFF     // Clear mask
#define     ei4_rx_cal_inc_val_F                                  0x0000     //RX Servo Accum Inc Value F
#define     ei4_rx_cal_inc_val_F_clear                            0xF0FF     // Clear mask
#define     ei4_rx_cal_inc_val_G                                  0x0000     //RX Servo Accum Inc Value G
#define     ei4_rx_cal_inc_val_G_clear                            0xFF0F     // Clear mask
#define     ei4_rx_cal_inc_val_H                                  0x0000     //RX Servo Accum Inc Value H
#define     ei4_rx_cal_inc_val_H_clear                            0xF0F0     // Clear mask

// ei4_rx_ei4_cal_dec_a_d_pp Register field name                            data value   Description
#define     ei4_rx_cal_dec_val_A                                  0x0000     //RX Servo Accum Dec Value A
#define     ei4_rx_cal_dec_val_A_clear                            0x0FFF     // Clear mask
#define     ei4_rx_cal_dec_val_B                                  0x0000     //RX Servo Accum Dec Value B
#define     ei4_rx_cal_dec_val_B_clear                            0xF0FF     // Clear mask
#define     ei4_rx_cal_dec_val_C                                  0x0000     //RX Servo Accum Dec Value C
#define     ei4_rx_cal_dec_val_C_clear                            0xFF0F     // Clear mask
#define     ei4_rx_cal_dec_val_D                                  0x0000     //RX Servo Accum Dec Value D
#define     ei4_rx_cal_dec_val_D_clear                            0xF0F0     // Clear mask

// ei4_rx_ei4_cal_dec_e_h_pp Register field name                            data value   Description
#define     ei4_rx_cal_dec_val_E                                  0x0000     //RX Servo Accum Dec Value E
#define     ei4_rx_cal_dec_val_E_clear                            0x0FFF     // Clear mask
#define     ei4_rx_cal_dec_val_F                                  0x0000     //RX Servo Accum Dec Value F
#define     ei4_rx_cal_dec_val_F_clear                            0xF0FF     // Clear mask
#define     ei4_rx_cal_dec_val_G                                  0x0000     //RX Servo Accum Dec Value G
#define     ei4_rx_cal_dec_val_G_clear                            0xFF0F     // Clear mask
#define     ei4_rx_cal_dec_val_H                                  0x0000     //RX Servo Accum Dec Value H
#define     ei4_rx_cal_dec_val_H_clear                            0xF0F0     // Clear mask

// ei4_rx_mode2_pp Register field name                                      data value   Description
#define     ei4_rx_bist_jitter_pulse_ctl_0                        0x4000     //Jitter Select  (steps8
#define     ei4_rx_bist_jitter_pulse_ctl_1                        0x8000     //Jitter Select  (steps2
#define     ei4_rx_bist_jitter_pulse_ctl_2                        0xC000     //Jitter Select  (steps0
#define     ei4_rx_bist_jitter_pulse_ctl_clear                    0x3FFF     // Clear mask
#define     ei4_rx_bist_min_eye_width                             0x0000     //Sets the minimum eye width value considered acceptable by PHYBIST.
#define     ei4_rx_bist_min_eye_width_clear                       0xC07F     // Clear mask

// ei4_rx_ber_cntl_pp Register field name                                   data value   Description
#define     ei4_rx_ber_en                                         0x8000     //Per-Pack (PP) Diagnostic Bit Error Rate (BER) error checking enable control. When 1 enables error checking. When 0 the error checking is disabled. This control enables the BER timer as well as enables the error checker and BER counters. The assumption is that the driver(s) are currently driving PRBS23 and the link has been trained before enabling BER checking.
#define     ei4_rx_ber_en_clear                                   0x7FFF     // Clear mask
#define     ei4_rx_ber_count_clr                                  0x4000     //PP Diag BER error counter clear pulse. When written to a 1 the per-lane error counters are cleared to all zeroes. Writing both this bit and the timer clear bit to a 1 will clear both and allow a new set of measurements to be run.
#define     ei4_rx_ber_count_clr_clear                            0xBFFF     // Clear mask
#define     ei4_rx_ber_timer_clr                                  0x2000     //PP Diag BER timer clear pulse. When written to a 1 the per-pack timers are cleared to all zeroes. Writing both this bit and the error counter clear bit to a 1 will clear both and allow a new set of measurements to be run.
#define     ei4_rx_ber_timer_clr_clear                            0xDFFF     // Clear mask

// ei4_rx_ber_mode_pp Register field name                                   data value   Description
#define     ei4_rx_ber_timer_freeze_en                            0x8000     //Per-Pack (PP) Diagnostic Bit Error Rate (BER) Timer freeze enable. When set to a 1 the per-pack timer is frozen when any lane error count saturates in that pack.
#define     ei4_rx_ber_timer_freeze_en_clear                      0x7FFF     // Clear mask
#define     ei4_rx_ber_count_freeze_en                            0x4000     //PP Diag BER Lane Error Counter freeze enable. When set to a 1 the per-lane error counters are frozen when the timer saturates in that pack.
#define     ei4_rx_ber_count_freeze_en_clear                      0xBFFF     // Clear mask
#define     ei4_rx_ber_count_sel_2                                0x0400     //PP Diag BER Lane Error Counter saturation select. Selects the number of errors that will saturate the counter and cause a freeze event.   2
#define     ei4_rx_ber_count_sel_4                                0x0800     //PP Diag BER Lane Error Counter saturation select. Selects the number of errors that will saturate the counter and cause a freeze event.   4
#define     ei4_rx_ber_count_sel_8                                0x0C00     //PP Diag BER Lane Error Counter saturation select. Selects the number of errors that will saturate the counter and cause a freeze event.   8
#define     ei4_rx_ber_count_sel_16                               0x1000     //PP Diag BER Lane Error Counter saturation select. Selects the number of errors that will saturate the counter and cause a freeze event.   16
#define     ei4_rx_ber_count_sel_32                               0x1400     //PP Diag BER Lane Error Counter saturation select. Selects the number of errors that will saturate the counter and cause a freeze event.   32
#define     ei4_rx_ber_count_sel_64                               0x1800     //PP Diag BER Lane Error Counter saturation select. Selects the number of errors that will saturate the counter and cause a freeze event.   64
#define     ei4_rx_ber_count_sel_128                              0x1C00     //PP Diag BER Lane Error Counter saturation select. Selects the number of errors that will saturate the counter and cause a freeze event.   128
#define     ei4_rx_ber_count_sel_clear                            0xE3FF     // Clear mask
#define     ei4_rx_ber_timer_sel_2tothe36th                       0x0080     //PP Diag BER Timer saturation select. Selects the timer value that will saturate the timer and cause a freeze event.   2^36
#define     ei4_rx_ber_timer_sel_2tothe32nd                       0x0100     //PP Diag BER Timer saturation select. Selects the timer value that will saturate the timer and cause a freeze event.   2^32
#define     ei4_rx_ber_timer_sel_2tothe28th                       0x0180     //PP Diag BER Timer saturation select. Selects the timer value that will saturate the timer and cause a freeze event.   2^28
#define     ei4_rx_ber_timer_sel_2tothe24th                       0x0200     //PP Diag BER Timer saturation select. Selects the timer value that will saturate the timer and cause a freeze event.   2^24
#define     ei4_rx_ber_timer_sel_2tothe20th                       0x0280     //PP Diag BER Timer saturation select. Selects the timer value that will saturate the timer and cause a freeze event.   2^20
#define     ei4_rx_ber_timer_sel_2tothe16th                       0x0300     //PP Diag BER Timer saturation select. Selects the timer value that will saturate the timer and cause a freeze event.   2^16
#define     ei4_rx_ber_timer_sel_2tothe12th                       0x0380     //PP Diag BER Timer saturation select. Selects the timer value that will saturate the timer and cause a freeze event.   2^12
#define     ei4_rx_ber_timer_sel_clear                            0xFC7F     // Clear mask
#define     ei4_rx_ber_clr_count_on_read_en                       0x0040     //PP Diag BER Lane Error Counter clear on read. When set to a 1 this enables the clearing of a lanes error counter when it is read.
#define     ei4_rx_ber_clr_count_on_read_en_clear                 0xFFBF     // Clear mask
#define     ei4_rx_ber_clr_timer_on_read_en                       0x0020     //PP Diag BER Timer clear on read. When set to a 1 this enables the clearing of a lanes per-pack timer when it is read from any lane in the pack.
#define     ei4_rx_ber_clr_timer_on_read_en_clear                 0xFFDF     // Clear mask

// ei4_rx_servo_to1_pp Register field name                                  data value   Description
#define     ei4_rx_servo_timeout_sel_A_512ui                      0x1000     //RX servo operation timeout A.  512 UI 
#define     ei4_rx_servo_timeout_sel_A_1Kui                       0x2000     //RX servo operation timeout A.  1K UI 
#define     ei4_rx_servo_timeout_sel_A_2Kui                       0x3000     //RX servo operation timeout A.  2K UI 
#define     ei4_rx_servo_timeout_sel_A_4Kui                       0x4000     //RX servo operation timeout A.  4096 UI 
#define     ei4_rx_servo_timeout_sel_A_8Kui                       0x5000     //RX servo operation timeout A.  8K UI 
#define     ei4_rx_servo_timeout_sel_A_16Kui                      0x6000     //RX servo operation timeout A.  16K UI 
#define     ei4_rx_servo_timeout_sel_A_32Kui                      0x7000     //RX servo operation timeout A.  32K UI 
#define     ei4_rx_servo_timeout_sel_A_64Kui                      0x8000     //RX servo operation timeout A.  64K UI 
#define     ei4_rx_servo_timeout_sel_A_128Kui                     0x9000     //RX servo operation timeout A.  128K UI 
#define     ei4_rx_servo_timeout_sel_A_256Kui                     0xA000     //RX servo operation timeout A.  256K UI 
#define     ei4_rx_servo_timeout_sel_A_512Kui                     0xB000     //RX servo operation timeout A.  512K UI 
#define     ei4_rx_servo_timeout_sel_A_1Mui                       0xC000     //RX servo operation timeout A.  1M UI 
#define     ei4_rx_servo_timeout_sel_A_2Mui                       0xD000     //RX servo operation timeout A.  2M UI 
#define     ei4_rx_servo_timeout_sel_A_4Mui                       0xE000     //RX servo operation timeout A.  4M UI
#define     ei4_rx_servo_timeout_sel_A_Infinite                   0xF000     //RX servo operation timeout A.  Infinite
#define     ei4_rx_servo_timeout_sel_A_clear                      0x0FFF     // Clear mask
#define     ei4_rx_servo_timeout_sel_B_512ui                      0x0100     //RX servo operation timeout B.  512 UI 
#define     ei4_rx_servo_timeout_sel_B_1Kui                       0x0200     //RX servo operation timeout B.  1K UI 
#define     ei4_rx_servo_timeout_sel_B_2Kui                       0x0300     //RX servo operation timeout B.  2K UI 
#define     ei4_rx_servo_timeout_sel_B_4Kui                       0x0400     //RX servo operation timeout B.  4096 UI 
#define     ei4_rx_servo_timeout_sel_B_8Kui                       0x0500     //RX servo operation timeout B.  8K UI 
#define     ei4_rx_servo_timeout_sel_B_16Kui                      0x0600     //RX servo operation timeout B.  16K UI 
#define     ei4_rx_servo_timeout_sel_B_32Kui                      0x0700     //RX servo operation timeout B.  32K UI 
#define     ei4_rx_servo_timeout_sel_B_64Kui                      0x0800     //RX servo operation timeout B.  64K UI 
#define     ei4_rx_servo_timeout_sel_B_128Kui                     0x0900     //RX servo operation timeout B.  128K UI 
#define     ei4_rx_servo_timeout_sel_B_256Kui                     0x0A00     //RX servo operation timeout B.  256K UI 
#define     ei4_rx_servo_timeout_sel_B_512Kui                     0x0B00     //RX servo operation timeout B.  512K UI 
#define     ei4_rx_servo_timeout_sel_B_1Mui                       0x0C00     //RX servo operation timeout B.  1M UI 
#define     ei4_rx_servo_timeout_sel_B_2Mui                       0x0D00     //RX servo operation timeout B.  2M UI 
#define     ei4_rx_servo_timeout_sel_B_4Mui                       0x0E00     //RX servo operation timeout B.  4M UI
#define     ei4_rx_servo_timeout_sel_B_Infinite                   0x0F00     //RX servo operation timeout B.  Infinite
#define     ei4_rx_servo_timeout_sel_B_clear                      0xF0FF     // Clear mask
#define     ei4_rx_servo_timeout_sel_C_512ui                      0x0010     //RX servo operation timeout C.  512 UI 
#define     ei4_rx_servo_timeout_sel_C_1Kui                       0x0020     //RX servo operation timeout C.  1K UI 
#define     ei4_rx_servo_timeout_sel_C_2Kui                       0x0030     //RX servo operation timeout C.  2K UI 
#define     ei4_rx_servo_timeout_sel_C_4Kui                       0x0040     //RX servo operation timeout C.  4096 UI 
#define     ei4_rx_servo_timeout_sel_C_8Kui                       0x0050     //RX servo operation timeout C.  8K UI 
#define     ei4_rx_servo_timeout_sel_C_16Kui                      0x0060     //RX servo operation timeout C.  16K UI 
#define     ei4_rx_servo_timeout_sel_C_32Kui                      0x0070     //RX servo operation timeout C.  32K UI 
#define     ei4_rx_servo_timeout_sel_C_64Kui                      0x0080     //RX servo operation timeout C.  64K UI 
#define     ei4_rx_servo_timeout_sel_C_128Kui                     0x0090     //RX servo operation timeout C.  128K UI 
#define     ei4_rx_servo_timeout_sel_C_256Kui                     0x00A0     //RX servo operation timeout C.  256K UI 
#define     ei4_rx_servo_timeout_sel_C_512Kui                     0x00B0     //RX servo operation timeout C.  512K UI 
#define     ei4_rx_servo_timeout_sel_C_1Mui                       0x00C0     //RX servo operation timeout C.  1M UI 
#define     ei4_rx_servo_timeout_sel_C_2Mui                       0x00D0     //RX servo operation timeout C.  2M UI 
#define     ei4_rx_servo_timeout_sel_C_4Mui                       0x00E0     //RX servo operation timeout C.  4M UI
#define     ei4_rx_servo_timeout_sel_C_Infinite                   0x00F0     //RX servo operation timeout C.  Infinite
#define     ei4_rx_servo_timeout_sel_C_clear                      0x0F0F     // Clear mask
#define     ei4_rx_servo_timeout_sel_D_512ui                      0x0001     //RX servo operation timeout D.  512 UI 
#define     ei4_rx_servo_timeout_sel_D_1Kui                       0x0002     //RX servo operation timeout D.  1K UI 
#define     ei4_rx_servo_timeout_sel_D_2Kui                       0x0003     //RX servo operation timeout D.  2K UI 
#define     ei4_rx_servo_timeout_sel_D_4Kui                       0x0004     //RX servo operation timeout D.  4096 UI 
#define     ei4_rx_servo_timeout_sel_D_8Kui                       0x0005     //RX servo operation timeout D.  8K UI 
#define     ei4_rx_servo_timeout_sel_D_16Kui                      0x0006     //RX servo operation timeout D.  16K UI 
#define     ei4_rx_servo_timeout_sel_D_32Kui                      0x0007     //RX servo operation timeout D.  32K UI 
#define     ei4_rx_servo_timeout_sel_D_64Kui                      0x0008     //RX servo operation timeout D.  64K UI 
#define     ei4_rx_servo_timeout_sel_D_128Kui                     0x0009     //RX servo operation timeout D.  128K UI 
#define     ei4_rx_servo_timeout_sel_D_256Kui                     0x000A     //RX servo operation timeout D.  256K UI 
#define     ei4_rx_servo_timeout_sel_D_512Kui                     0x000B     //RX servo operation timeout D.  512K UI 
#define     ei4_rx_servo_timeout_sel_D_1Mui                       0x000C     //RX servo operation timeout D.  1M UI 
#define     ei4_rx_servo_timeout_sel_D_2Mui                       0x000D     //RX servo operation timeout D.  2M UI 
#define     ei4_rx_servo_timeout_sel_D_4Mui                       0x000E     //RX servo operation timeout D.  4M UI
#define     ei4_rx_servo_timeout_sel_D_Infinite                   0x000F     //RX servo operation timeout D.  Infinite
#define     ei4_rx_servo_timeout_sel_D_clear                      0xFF00     // Clear mask

// ei4_rx_servo_to2_pp Register field name                                  data value   Description
#define     ei4_rx_servo_timeout_sel_E_512ui                      0x1000     //RX servo operation timeout E.  512 UI 
#define     ei4_rx_servo_timeout_sel_E_1Kui                       0x2000     //RX servo operation timeout E.  1K UI 
#define     ei4_rx_servo_timeout_sel_E_2Kui                       0x3000     //RX servo operation timeout E.  2K UI 
#define     ei4_rx_servo_timeout_sel_E_4Kui                       0x4000     //RX servo operation timeout E.  4096 UI 
#define     ei4_rx_servo_timeout_sel_E_8Kui                       0x5000     //RX servo operation timeout E.  8K UI 
#define     ei4_rx_servo_timeout_sel_E_16Kui                      0x6000     //RX servo operation timeout E.  16K UI 
#define     ei4_rx_servo_timeout_sel_E_32Kui                      0x7000     //RX servo operation timeout E.  32K UI 
#define     ei4_rx_servo_timeout_sel_E_64Kui                      0x8000     //RX servo operation timeout E.  64K UI 
#define     ei4_rx_servo_timeout_sel_E_128Kui                     0x9000     //RX servo operation timeout E.  128K UI 
#define     ei4_rx_servo_timeout_sel_E_256Kui                     0xA000     //RX servo operation timeout E.  256K UI 
#define     ei4_rx_servo_timeout_sel_E_512Kui                     0xB000     //RX servo operation timeout E.  512K UI 
#define     ei4_rx_servo_timeout_sel_E_1Mui                       0xC000     //RX servo operation timeout E.  1M UI 
#define     ei4_rx_servo_timeout_sel_E_2Mui                       0xD000     //RX servo operation timeout E.  2M UI 
#define     ei4_rx_servo_timeout_sel_E_4Mui                       0xE000     //RX servo operation timeout E.  4M UI
#define     ei4_rx_servo_timeout_sel_E_Infinite                   0xF000     //RX servo operation timeout E.  Infinite
#define     ei4_rx_servo_timeout_sel_E_clear                      0x0FFF     // Clear mask
#define     ei4_rx_servo_timeout_sel_F_512ui                      0x0100     //RX servo operation timeout F.  512 UI 
#define     ei4_rx_servo_timeout_sel_F_1Kui                       0x0200     //RX servo operation timeout F.  1K UI 
#define     ei4_rx_servo_timeout_sel_F_2Kui                       0x0300     //RX servo operation timeout F.  2K UI 
#define     ei4_rx_servo_timeout_sel_F_4Kui                       0x0400     //RX servo operation timeout F.  4096 UI 
#define     ei4_rx_servo_timeout_sel_F_8Kui                       0x0500     //RX servo operation timeout F.  8K UI 
#define     ei4_rx_servo_timeout_sel_F_16Kui                      0x0600     //RX servo operation timeout F.  16K UI 
#define     ei4_rx_servo_timeout_sel_F_32Kui                      0x0700     //RX servo operation timeout F.  32K UI 
#define     ei4_rx_servo_timeout_sel_F_64Kui                      0x0800     //RX servo operation timeout F.  64K UI 
#define     ei4_rx_servo_timeout_sel_F_128Kui                     0x0900     //RX servo operation timeout F.  128K UI 
#define     ei4_rx_servo_timeout_sel_F_256Kui                     0x0A00     //RX servo operation timeout F.  256K UI 
#define     ei4_rx_servo_timeout_sel_F_512Kui                     0x0B00     //RX servo operation timeout F.  512K UI 
#define     ei4_rx_servo_timeout_sel_F_1Mui                       0x0C00     //RX servo operation timeout F.  1M UI 
#define     ei4_rx_servo_timeout_sel_F_2Mui                       0x0D00     //RX servo operation timeout F.  2M UI 
#define     ei4_rx_servo_timeout_sel_F_4Mui                       0x0E00     //RX servo operation timeout F.  4M UI
#define     ei4_rx_servo_timeout_sel_F_Infinite                   0x0F00     //RX servo operation timeout F.  Infinite
#define     ei4_rx_servo_timeout_sel_F_clear                      0xF0FF     // Clear mask
#define     ei4_rx_servo_timeout_sel_G_512ui                      0x0010     //RX servo operation timeout G.  512 UI 
#define     ei4_rx_servo_timeout_sel_G_1Kui                       0x0020     //RX servo operation timeout G.  1K UI 
#define     ei4_rx_servo_timeout_sel_G_2Kui                       0x0030     //RX servo operation timeout G.  2K UI 
#define     ei4_rx_servo_timeout_sel_G_4Kui                       0x0040     //RX servo operation timeout G.  4096 UI 
#define     ei4_rx_servo_timeout_sel_G_8Kui                       0x0050     //RX servo operation timeout G.  8K UI 
#define     ei4_rx_servo_timeout_sel_G_16Kui                      0x0060     //RX servo operation timeout G.  16K UI 
#define     ei4_rx_servo_timeout_sel_G_32Kui                      0x0070     //RX servo operation timeout G.  32K UI 
#define     ei4_rx_servo_timeout_sel_G_64Kui                      0x0080     //RX servo operation timeout G.  64K UI 
#define     ei4_rx_servo_timeout_sel_G_128Kui                     0x0090     //RX servo operation timeout G.  128K UI 
#define     ei4_rx_servo_timeout_sel_G_256Kui                     0x00A0     //RX servo operation timeout G.  256K UI 
#define     ei4_rx_servo_timeout_sel_G_512Kui                     0x00B0     //RX servo operation timeout G.  512K UI 
#define     ei4_rx_servo_timeout_sel_G_1Mui                       0x00C0     //RX servo operation timeout G.  1M UI 
#define     ei4_rx_servo_timeout_sel_G_2Mui                       0x00D0     //RX servo operation timeout G.  2M UI 
#define     ei4_rx_servo_timeout_sel_G_4Mui                       0x00E0     //RX servo operation timeout G.  4M UI
#define     ei4_rx_servo_timeout_sel_G_Infinite                   0x00F0     //RX servo operation timeout G.  Infinite
#define     ei4_rx_servo_timeout_sel_G_clear                      0x0F0F     // Clear mask
#define     ei4_rx_servo_timeout_sel_H_512ui                      0x0001     //RX servo operation timeout H.  512 UI 
#define     ei4_rx_servo_timeout_sel_H_1Kui                       0x0002     //RX servo operation timeout H.  1K UI 
#define     ei4_rx_servo_timeout_sel_H_2Kui                       0x0003     //RX servo operation timeout H.  2K UI 
#define     ei4_rx_servo_timeout_sel_H_4Kui                       0x0004     //RX servo operation timeout H.  4096 UI 
#define     ei4_rx_servo_timeout_sel_H_8Kui                       0x0005     //RX servo operation timeout H.  8K UI 
#define     ei4_rx_servo_timeout_sel_H_16Kui                      0x0006     //RX servo operation timeout H.  16K UI 
#define     ei4_rx_servo_timeout_sel_H_32Kui                      0x0007     //RX servo operation timeout H.  32K UI 
#define     ei4_rx_servo_timeout_sel_H_64Kui                      0x0008     //RX servo operation timeout H.  64K UI 
#define     ei4_rx_servo_timeout_sel_H_128Kui                     0x0009     //RX servo operation timeout H.  128K UI 
#define     ei4_rx_servo_timeout_sel_H_256Kui                     0x000A     //RX servo operation timeout H.  256K UI 
#define     ei4_rx_servo_timeout_sel_H_512Kui                     0x000B     //RX servo operation timeout H.  512K UI 
#define     ei4_rx_servo_timeout_sel_H_1Mui                       0x000C     //RX servo operation timeout H.  1M UI 
#define     ei4_rx_servo_timeout_sel_H_2Mui                       0x000D     //RX servo operation timeout H.  2M UI 
#define     ei4_rx_servo_timeout_sel_H_4Mui                       0x000E     //RX servo operation timeout H.  4M UI
#define     ei4_rx_servo_timeout_sel_H_Infinite                   0x000F     //RX servo operation timeout H.  Infinite
#define     ei4_rx_servo_timeout_sel_H_clear                      0xFF00     // Clear mask

// ei4_rx_reset_cfg_pp Register field name                                  data value   Description
#define     ei4_rx_reset_cfg_hld_clear                            0x0000     // Clear mask

// ei4_rx_recal_to1_pp Register field name                                  data value   Description
#define     ei4_rx_recal_timeout_sel_A_512ui                      0x1000     //RX recal servo operation timeout A.  512 UI 
#define     ei4_rx_recal_timeout_sel_A_1Kui                       0x2000     //RX recal servo operation timeout A.  1K UI 
#define     ei4_rx_recal_timeout_sel_A_2Kui                       0x3000     //RX recal servo operation timeout A.  2K UI 
#define     ei4_rx_recal_timeout_sel_A_4Kui                       0x4000     //RX recal servo operation timeout A.  4096 UI 
#define     ei4_rx_recal_timeout_sel_A_8Kui                       0x5000     //RX recal servo operation timeout A.  8K UI 
#define     ei4_rx_recal_timeout_sel_A_16Kui                      0x6000     //RX recal servo operation timeout A.  16K UI 
#define     ei4_rx_recal_timeout_sel_A_32Kui                      0x7000     //RX recal servo operation timeout A.  32K UI 
#define     ei4_rx_recal_timeout_sel_A_64Kui                      0x8000     //RX recal servo operation timeout A.  64K UI 
#define     ei4_rx_recal_timeout_sel_A_128Kui                     0x9000     //RX recal servo operation timeout A.  128K UI 
#define     ei4_rx_recal_timeout_sel_A_256Kui                     0xA000     //RX recal servo operation timeout A.  256K UI 
#define     ei4_rx_recal_timeout_sel_A_512Kui                     0xB000     //RX recal servo operation timeout A.  512K UI 
#define     ei4_rx_recal_timeout_sel_A_1Mui                       0xC000     //RX recal servo operation timeout A.  1M UI 
#define     ei4_rx_recal_timeout_sel_A_2Mui                       0xD000     //RX recal servo operation timeout A.  2M UI 
#define     ei4_rx_recal_timeout_sel_A_4Mui                       0xE000     //RX recal servo operation timeout A.  4M UI
#define     ei4_rx_recal_timeout_sel_A_Infinite                   0xF000     //RX recal servo operation timeout A.  Infinite
#define     ei4_rx_recal_timeout_sel_A_clear                      0x0FFF     // Clear mask

// ei4_rx_recal_to2_pp Register field name                                  data value   Description
#define     ei4_rx_recal_timeout_sel_E_512ui                      0x1000     //RX recal servo operation timeout E.  512 UI 
#define     ei4_rx_recal_timeout_sel_E_1Kui                       0x2000     //RX recal servo operation timeout E.  1K UI 
#define     ei4_rx_recal_timeout_sel_E_2Kui                       0x3000     //RX recal servo operation timeout E.  2K UI 
#define     ei4_rx_recal_timeout_sel_E_4Kui                       0x4000     //RX recal servo operation timeout E.  4096 UI 
#define     ei4_rx_recal_timeout_sel_E_8Kui                       0x5000     //RX recal servo operation timeout E.  8K UI 
#define     ei4_rx_recal_timeout_sel_E_16Kui                      0x6000     //RX recal servo operation timeout E.  16K UI 
#define     ei4_rx_recal_timeout_sel_E_32Kui                      0x7000     //RX recal servo operation timeout E.  32K UI 
#define     ei4_rx_recal_timeout_sel_E_64Kui                      0x8000     //RX recal servo operation timeout E.  64K UI 
#define     ei4_rx_recal_timeout_sel_E_128Kui                     0x9000     //RX recal servo operation timeout E.  128K UI 
#define     ei4_rx_recal_timeout_sel_E_256Kui                     0xA000     //RX recal servo operation timeout E.  256K UI 
#define     ei4_rx_recal_timeout_sel_E_512Kui                     0xB000     //RX recal servo operation timeout E.  512K UI 
#define     ei4_rx_recal_timeout_sel_E_1Mui                       0xC000     //RX recal servo operation timeout E.  1M UI 
#define     ei4_rx_recal_timeout_sel_E_2Mui                       0xD000     //RX recal servo operation timeout E.  2M UI 
#define     ei4_rx_recal_timeout_sel_E_4Mui                       0xE000     //RX recal servo operation timeout E.  4M UI
#define     ei4_rx_recal_timeout_sel_E_Infinite                   0xF000     //RX recal servo operation timeout E.  Infinite
#define     ei4_rx_recal_timeout_sel_E_clear                      0x0FFF     // Clear mask
#define     ei4_rx_recal_timeout_sel_F_512ui                      0x0100     //RX recal servo operation timeout F.  512 UI 
#define     ei4_rx_recal_timeout_sel_F_1Kui                       0x0200     //RX recal servo operation timeout F.  1K UI 
#define     ei4_rx_recal_timeout_sel_F_2Kui                       0x0300     //RX recal servo operation timeout F.  2K UI 
#define     ei4_rx_recal_timeout_sel_F_4Kui                       0x0400     //RX recal servo operation timeout F.  4096 UI 
#define     ei4_rx_recal_timeout_sel_F_8Kui                       0x0500     //RX recal servo operation timeout F.  8K UI 
#define     ei4_rx_recal_timeout_sel_F_16Kui                      0x0600     //RX recal servo operation timeout F.  16K UI 
#define     ei4_rx_recal_timeout_sel_F_32Kui                      0x0700     //RX recal servo operation timeout F.  32K UI 
#define     ei4_rx_recal_timeout_sel_F_64Kui                      0x0800     //RX recal servo operation timeout F.  64K UI 
#define     ei4_rx_recal_timeout_sel_F_128Kui                     0x0900     //RX recal servo operation timeout F.  128K UI 
#define     ei4_rx_recal_timeout_sel_F_256Kui                     0x0A00     //RX recal servo operation timeout F.  256K UI 
#define     ei4_rx_recal_timeout_sel_F_512Kui                     0x0B00     //RX recal servo operation timeout F.  512K UI 
#define     ei4_rx_recal_timeout_sel_F_1Mui                       0x0C00     //RX recal servo operation timeout F.  1M UI 
#define     ei4_rx_recal_timeout_sel_F_2Mui                       0x0D00     //RX recal servo operation timeout F.  2M UI 
#define     ei4_rx_recal_timeout_sel_F_4Mui                       0x0E00     //RX recal servo operation timeout F.  4M UI
#define     ei4_rx_recal_timeout_sel_F_Infinite                   0x0F00     //RX recal servo operation timeout F.  Infinite
#define     ei4_rx_recal_timeout_sel_F_clear                      0xF0FF     // Clear mask

// ei4_rx_recal_cntl_pp Register field name                                 data value   Description
#define     ei4_rx_recal_in_progress                              0x8000     //Selects which servo timeouts are used. 
#define     ei4_rx_recal_in_progress_clear                        0x7FFF     // Clear mask

// ei4_rx_trace_pp Register field name                                      data value   Description
#define     ei4_rx_pp_trc_mode_tap1                               0x2000     //Per Pack RX Trace Mode  TBD
#define     ei4_rx_pp_trc_mode_tap2                               0x4000     //Per Pack RX Trace Mode  TBD
#define     ei4_rx_pp_trc_mode_tap3                               0x6000     //Per Pack RX Trace Mode  TBD
#define     ei4_rx_pp_trc_mode_tap4                               0x8000     //Per Pack RX Trace Mode  TBD
#define     ei4_rx_pp_trc_mode_tap5                               0xA000     //Per Pack RX Trace Mode  TBD
#define     ei4_rx_pp_trc_mode_tap6                               0xC000     //Per Pack RX Trace Mode  TBD
#define     ei4_rx_pp_trc_mode_tap7                               0xE000     //Per Pack RX Trace Mode  TBD
#define     ei4_rx_pp_trc_mode_clear                              0x1FFF     // Clear mask

// ei4_rx_bist_gcrmsg_pp Register field name                                data value   Description
#define     ei4_rx_bist_en                                        0x8000     //TBD
#define     ei4_rx_bist_en_clear                                  0x7FFF     // Clear mask

// ei4_rx_fir_reset_pb Register field name                                  data value   Description
#define     ei4_rx_pb_clr_par_errs                                0x0002     //Clear All RX Parity Error Latches
#define     ei4_rx_pb_clr_par_errs_clear                          0xFFFD     // Clear mask
#define     ei4_rx_pb_fir_reset                                   0x0001     //FIR Reset
#define     ei4_rx_pb_fir_reset_clear                             0xFFFE     // Clear mask

// ei4_rx_fir_pb Register field name                                        data value   Description
#define     ei4_rx_pb_fir_errs_err_busctl_gcrs_ld_sm              0x0400     //A Per-Bus BUSCTL Register or State Machine Parity Error has occurred.  BUSCTL GCR Load SM Parity Error.
#define     ei4_rx_pb_fir_errs_clear                              0x003F     // Clear mask

// ei4_rx_fir_mask_pb Register field name                                   data value   Description
#define     ei4_rx_pb_fir_errs_mask_err_busctl_gcrs_ld_sm         0x0400     //FIR mask for register or state machine parity checkers in per-bus BUSCTL logic. A value of 1 masks the error from generating a FIR error.  BUSCTL GCR Load SM Parity Error.
#define     ei4_rx_pb_fir_errs_mask_clear                         0x003F     // Clear mask

// ei4_rx_fir_error_inject_pb Register field name                           data value   Description
#define     ei4_rx_pb_fir_errs_inj_1                              0x4000     //RX Per-Group Parity Error Injection  Causes a parity flip in the specific parity checker.
#define     ei4_rx_pb_fir_errs_inj_err_inj_busctl_gcrs_ld_sm      0x0400     //RX Per-Group Parity Error Injection  BUSCTL GCR Load SM Parity Error Inject.
#define     ei4_rx_pb_fir_errs_inj_clear                          0x003F     // Clear mask





#endif

