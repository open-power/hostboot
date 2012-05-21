/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/bus_training/edi_regs.h $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
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
// $Id: edi_regs.h,v 1.7 2012/05/17 08:32:23 varkeykv Exp $
// $URL: $
//
// *!**************************************************************************
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
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
	tx_minikerf_pg,
	tx_clk_cntl_gcrmsg_pg,
	tx_ffe_mode_pg,
	tx_ffe_main_pg,
	tx_ffe_post_pg,
	tx_ffe_margin_pg,
	tx_bad_lane_enc_gcrmsg_pg,
	tx_sls_lane_enc_gcrmsg_pg,
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
	tx_impcal_pb,
	tx_impcal_nval_pb,
	tx_impcal_pval_pb,
	tx_impcal_p_4x_pb,
	tx_impcal_swo1_pb,
	tx_impcal_swo2_pb,
	rx_mode_pl,
	rx_cntl_pl,
	rx_spare_mode_pl,
	rx_prot_edge_status_pl,
	rx_bist_stat_pl,
	rx_eyeopt_mode_pl,
	rx_eyeopt_stat_pl,
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
	rx_clk_mode_pg,
	rx_spare_mode_pg,
	rx_mode_pg,
	rx_bus_repair_pg,
	rx_grp_repair_vec_0_15_pg,
	rx_grp_repair_vec_16_31_pg,
	rx_recal_mode_pg,
	rx_reset_act_pg,
	rx_id1_pg,
	rx_id2_pg,
	rx_id3_pg,
	rx_minikerf_pg,
	rx_bist_cntl_pg,
	rx_sls_mode_pg,
	rx_training_start_pg,
	rx_training_status_pg,
	rx_recal_status_pg,
	rx_timeout_sel_pg,
	rx_fifo_mode_pg,
	rx_state_debug_pg,
	rx_state_val_pg,
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
	rx_dyn_rpr_err_tallying_pg,
	rx_eo_final_l2u_gcrmsgs_pg,
	rx_gcr_msg_debug_dest_ids_pg,
	rx_gcr_msg_debug_src_ids_pg,
	rx_gcr_msg_debug_dest_addr_pg,
	rx_gcr_msg_debug_write_data_pg,
	rx_dyn_recal_pg,
	rx_wt_clk_status_pg,
	rx_dyn_recal_config_pg,
	rx_servo_recal_gcrmsg_pg,
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
	rx_wiretest_pp,
	rx_mode_pp,
	rx_cntl_pp,
	rx_dyn_recal_timeouts_pp,
	rx_servo_recal_gcrmsg_pp,
	rx_ber_cntl_pp,
	rx_ber_mode_pp,
	rx_servo_to1_pp,
	rx_servo_to2_pp,
	rx_servo_to3_pp,
	rx_dfe_config_pp,
	rx_dfe_timers_pp,
	rx_reset_cfg_pp,
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
	ei4_tx_minikerf_pg,
	ei4_tx_clk_cntl_gcrmsg_pg,
	ei4_tx_bad_lane_enc_gcrmsg_pg,
	ei4_tx_sls_lane_enc_gcrmsg_pg,
	ei4_tx_pc_ffe_pg,
	ei4_tx_misc_analog_pg,
	ei4_tx_lane_disabled_vec_0_15_pg,
	ei4_tx_lane_disabled_vec_16_31_pg,
	ei4_tx_sls_lane_mux_gcrmsg_pg,
	ei4_tx_dyn_rpr_pg,
	ei4_tx_slv_mv_sls_ln_req_gcrmsg_pg,
	ei4_tx_wiretest_pp,
	ei4_tx_mode_pp,
	ei4_tx_sls_gcrmsg_pp,
	ei4_tx_ber_cntl_a_pp,
	ei4_tx_ber_cntl_b_pp,
	ei4_tx_bist_cntl_pp,
	ei4_tx_ber_cntl_sls_pp,
	ei4_tx_cntl_pp,
	ei4_tx_reset_cfg_pp,
	ei4_rx_mode_pl,
	ei4_rx_cntl_pl,
	ei4_rx_spare_mode_pl,
	ei4_rx_prot_edge_status_pl,
	ei4_rx_bist_stat_pl,
	ei4_rx_eyeopt_mode_pl,
	ei4_rx_eyeopt_stat_pl,
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
	ei4_rx_clk_mode_pg,
	ei4_rx_spare_mode_pg,
	ei4_rx_mode_pg,
	ei4_rx_bus_repair_pg,
	ei4_rx_grp_repair_vec_0_15_pg,
	ei4_rx_grp_repair_vec_16_31_pg,
	ei4_rx_recal_mode_pg,
	ei4_rx_reset_act_pg,
	ei4_rx_id1_pg,
	ei4_rx_id2_pg,
	ei4_rx_id3_pg,
	ei4_rx_minikerf_pg,
	ei4_rx_bist_cntl_pg,
	ei4_rx_sls_mode_pg,
	ei4_rx_training_start_pg,
	ei4_rx_training_status_pg,
	ei4_rx_recal_status_pg,
	ei4_rx_timeout_sel_pg,
	ei4_rx_fifo_mode_pg,
	ei4_rx_state_debug_pg,
	ei4_rx_state_val_pg,
	ei4_rx_sls_status_pg,
	ei4_rx_prot_mode_pg,
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
	ei4_rx_dyn_rpr_err_tallying_pg,
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
	ei4_rx_wiretest_pp,
	ei4_rx_mode_pp,
	ei4_rx_cntl_pp,
	ei4_rx_ei4_cal_cntl_pp,
	ei4_rx_ei4_cal_inc_a_d_pp,
	ei4_rx_ei4_cal_inc_e_h_pp,
	ei4_rx_ei4_cal_dec_a_d_pp,
	ei4_rx_ei4_cal_dec_e_h_pp,
	ei4_rx_ber_cntl_pp,
	ei4_rx_ber_mode_pp,
	ei4_rx_servo_to1_pp,
	ei4_rx_servo_to2_pp,
	ei4_rx_reset_cfg_pp,
	ei4_rx_fir_msg_pb,
NUM_REGS
} GCR_sub_registers;


// merged ei4 and edi ext addresses
const uint32_t  GCR_sub_reg_ext_addr[] =     { 0x080, 0x081, 0x082, 0x085, 0x086, 0x087, 0x088, 0x08A, 0x08B, 0x08C, 0x08D, 0x180, 0x181, 0x182, 0x183, 0x184, 0x185, 0x186, 0x188, 0x189, 0x18A, 0x18B, 0x18C, 0x192, 0x193, 0x194, 0x195, 0x198, 0x199, 0x19A, 0x19B, 0x19C, 0x19D, 0x19F, 0x1A3, 0x1A4, 0x1A5, 0x1A6, 0x1A7, 0x1D0, 0x1D1, 0x1D2, 0x1D3, 0x1D4, 0x1D5, 0x1D6, 0x1D7, 0x1D8, 0x1D9, 0x1E0, 0x1E1, 0x1E2, 0x1E3, 0x1E4, 0x1E5, 0x000, 0x001, 0x002, 0x003, 0x005, 0x006, 0x007, 0x008, 0x009, 0x00A, 0x00B, 0x00C, 0x00D, 0x00E, 0x00F, 0x010, 0x011, 0x012, 0x013, 0x014, 0x016, 0x018, 0x019, 0x01A, 0x01B, 0x01C, 0x01D, 0x01E, 0x01F, 0x020, 0x021, 0x022, 0x023, 0x024, 0x025, 0x026, 0x027, 0x028, 0x029, 0x02A, 0x100, 0x101, 0x103, 0x104, 0x105, 0x106, 0x107, 0x109, 0x10A, 0x10B, 0x10C, 0x10D, 0x10E, 0x10F, 0x110, 0x111, 0x112, 0x113, 0x114, 0x115, 0x116, 0x117, 0x11A, 0x11B, 0x11C, 0x11D, 0x11E, 0x11F, 0x120, 0x121, 0x122, 0x123, 0x124, 0x125, 0x126, 0x127, 0x128, 0x129, 0x12A, 0x12B, 0x12C, 0x12D, 0x12E, 0x12F, 0x130, 0x131, 0x132, 0x133, 0x134, 0x135, 0x137, 0x138, 0x139, 0x13A, 0x13B, 0x13C, 0x13D, 0x13E, 0x13F, 0x140, 0x141, 0x142, 0x143, 0x144, 0x145, 0x146, 0x147, 0x148, 0x149, 0x14A, 0x14B, 0x14C, 0x14D, 0x14E, 0x14F, 0x150, 0x151, 0x152, 0x153, 0x154, 0x155, 0x160, 0x161, 0x162, 0x168, 0x169, 0x16A, 0x16B, 0x16C, 0x16D, 0x16E, 0x16F, 0x1FE, 0x108 ,
0x080, 0x081, 0x082, 0x085, 0x086, 0x087, 0x088, 0x08A, 0x08B, 0x08C, 0x08D, 0x180, 0x181, 0x182, 0x183, 0x184, 0x185, 0x186, 0x188, 0x189, 0x18A, 0x18B, 0x18C, 0x192, 0x193, 0x194, 0x195, 0x198, 0x19D, 0x19F, 0x1A1, 0x1A2, 0x1A3, 0x1A4, 0x1A5, 0x1A6, 0x1A7, 0x1D0, 0x1D1, 0x1D2, 0x1D3, 0x1D4, 0x1D6, 0x1D7, 0x1D8, 0x1D9, 0x000, 0x001, 0x002, 0x003, 0x005, 0x006, 0x007, 0x008, 0x009, 0x00A, 0x00C, 0x00D, 0x00E, 0x00F, 0x016, 0x017, 0x018, 0x019, 0x01A, 0x01B, 0x01C, 0x01D, 0x01E, 0x01F, 0x020, 0x021, 0x022, 0x023, 0x024, 0x025, 0x026, 0x027, 0x028, 0x029, 0x100, 0x101, 0x103, 0x104, 0x105, 0x106, 0x107, 0x109, 0x10A, 0x10B, 0x10C, 0x10D, 0x10E, 0x10F, 0x110, 0x111, 0x112, 0x113, 0x114, 0x115, 0x116, 0x117, 0x118, 0x11A, 0x11B, 0x11C, 0x11D, 0x11E, 0x11F, 0x120, 0x121, 0x122, 0x123, 0x124, 0x125, 0x126, 0x127, 0x128, 0x129, 0x12A, 0x12B, 0x12C, 0x12D, 0x12E, 0x12F, 0x130, 0x131, 0x132, 0x133, 0x134, 0x135, 0x136, 0x137, 0x139, 0x13A, 0x13B, 0x13C, 0x13D, 0x13E, 0x13F, 0x140, 0x142, 0x146, 0x147, 0x148, 0x149, 0x14E, 0x151, 0x152, 0x153, 0x154, 0x155, 0x160, 0x161, 0x162, 0x163, 0x164, 0x165, 0x166, 0x167, 0x16A, 0x16B, 0x16C, 0x16D, 0x108 };

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
	"TX Minikerf Cntl Reg",
	"TX Clock Control Reg",
	"TX FFE Test Mode Reg",
	"TX FFE Main Reg",
	"TX FFE Post Reg",
	"TX FFE Margin Reg",
	"TX Bad Lanes Encoded",
	"TX SLS Lane Encoded",
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
	"TX Impedance Cal Cntl and Status Reg",
	"TX Impedance Cal N Value Reg",
	"TX Impedance Cal P Value Reg",
	"TX Impedance Cal P 4x Value Reg",
	"TX Impedance Cal SW Workaround 1 Reg",
	"TX Impedance Cal SW Workaround 2 Reg",
	"RX Lane Mode Reg",
	"RX Cntl and Status Reg",
	"RX Per-lane Spare Mode Reg",
	"RX Phase Rotator Edge Status Reg",
	"RX BIST Status Reg",
	"RX Eye Optimization Mode Reg",
	"RX Eye Optimization Status Reg",
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
	"RX Per-Group Clk Mode Reg",
	"RX Per-Group Spare Mode Reg",
	"RX Mode Reg",
	"RX Bus Repair Reg",
	"RX Clkgrp Repair Lanes 0-15 Reg",
	"RX Clkgrp Repair Lanes 16-31 Reg",
	"RX Bus Repair Reg",
	"RX Reset Control Action Register (RCAR)",
	"RX Clock Group Identification 1 Reg",
	"RX Clock Group Identification 2 Reg",
	"RX Clock Group Identification 3 Reg",
	"RX Minikerf Cntl Reg",
	"RX BIST Cntl Reg",
	"RX Spare Lane Signaling Mode Reg",
	"RX Training State Start Reg",
	"RX Training State Status Reg",
	"RX Recal Status Reg",
	"RX Timeout Select Reg",
	"RX FIFO Mode Reg",
	"RX State Machine Debug Cntl/Status Reg",
	"RX State Machine Debug Value Reg",
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
	"CRC/ECC Dynamic Repair Error Frequency Settings",
	"RX Final Load to Unload GCR Messages",
	"RX SW Initiated GCR Message Destination IDs",
	"RX SW Initiated GCR Message Source IDs",
	"RX SW Initiated GCR Message Destination Addr",
	"RX SW Initiated GCR Message Write Data",
	"RX Dynamic Recalibration Status",
	"RX Clock Wiretest Status",
	"RX Dynamic Recalibration Configuration",
	"RX Servo Dynamic Recalibration GCR Messages",
	"RX Dynamic Recalibration GCR Messages",
	"RX Cleanup PLL Enable ",
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
	"RX Wiretest Per-Pack Shadow Reg",
	"RX Mode Per-Pack Shadow Reg",
	"RX Cntl Per-Pack Shadow Reg",
	"RX Dynamic Recalibration Timeout Selects",
	"RX Servo Dynamic Recalibration GCR Messages",
	"RX BER Control Reg",
	"RX BER Mode Reg",
	"RX Servo Timeout Select Regs 1",
	"RX Servo Timeout Select Regs 2",
	"RX Servo Timeout Select Regs 3",
	"RX DFE Configuration Register",
	"RX DFE timers Configuration Register",
	"RX Configurable Reset Control Register (CRCR)",
	
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
	"TX Minikerf Cntl Reg",
	"TX Clock Control Reg",
	"TX Bad Lanes Encoded",
	"TX SLS Lane Encoded",
	"TX Precomp and Impedance Reg",
	"TX Misc Analog Reg",
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
	"TX BIST Cntl Reg",
	"TX Bit Error Injection Control SLS Shadow Reg",
	"TX Cntl Per-Pack Reg",
	"TX Configurable Reset Control Register (CRCR)",
	"RX Lane Mode Reg",
	"RX Cntl and Status Reg",
	"RX Per-lane Spare Mode Reg",
	"RX Phase Rotator Edge Status Reg",
	"RX BIST Status Reg",
	"RX Eye Optimization Mode Reg",
	"RX Eye Optimization Status Reg",
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
	"RX Per-Group Clk Mode Reg",
	"RX Per-Group Spare Mode Reg",
	"RX Mode Reg",
	"RX Bus Repair Reg",
	"RX Clkgrp Repair Lanes 0-15 Reg",
	"RX Clkgrp Repair Lanes 16-31 Reg",
	"RX Bus Repair Reg",
	"RX Reset Control Action Register (RCAR)",
	"RX Clock Group Identification 1 Reg",
	"RX Clock Group Identification 2 Reg",
	"RX Clock Group Identification 3 Reg",
	"RX Minikerf Cntl Reg",
	"RX BIST Cntl Reg",
	"RX Spare Lane Signaling Mode Reg",
	"RX Training State Start Reg",
	"RX Training State Status Reg",
	"RX Recal Status Reg",
	"RX Timeout Select Reg",
	"RX FIFO Mode Reg",
	"RX State Machine Debug Cntl/Status Reg",
	"RX State Machine Debug Value Reg",
	"RX Spare Lane Signalling Status Reg",
	"RX Phase Rotator/Detector Mode Reg",
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
	"CRC/ECC Dynamic Repair Error Frequency Settings",
	"RX Final Load to Unload GCR Messages",
	"RX SW Initiated GCR Message Destination IDs",
	"RX SW Initiated GCR Message Source IDs",
	"RX SW Initiated GCR Message Destination Addr",
	"RX SW Initiated GCR Message Write Data",
	"RX Clock Wiretest Status",
	"RX Cleanup PLL Enable ",
	"RX Eye optimization step control",
	"RX Eye optimization step status",
	"RX Eye optimization step fail flags",
	"RX Eye optimization Amp  working registers",
	"RX SLS Handshake Recovery Register",
	"RX SLS Handshake Recovery GCR Messages",
	"RX: TX Lane Info",
	"CRC/ECC Syndrome Tallying GCR Message Reg",
	"RX Trace Mode Reg",
	"RX Wiretest Per-Pack Shadow Reg",
	"RX Mode Per-Pack Shadow Reg",
	"RX Cntl Per-Pack Shadow Reg",
	"RX Cal Cntl Per-Pack Shadow Reg",
	"RX Cal Accum inc value Reg",
	"RX Cal Accum inc value Reg",
	"RX Cal Accum dec value Reg",
	"RX Cal Accum dec value Reg",
	"RX BER Control Reg",
	"RX BER Mode Reg",
	"RX Servo Timeout Select Regs 1",
	"RX Servo Timeout Select Regs 2",
	"RX Configurable Reset Control Register (CRCR)"
};

const char* const ei4_GCR_sub_reg_names[] = {
	
};



// tx_mode_pl Register field name                                       data value   Description
#define     tx_lane_pdwn                                      0x8000     //Used to drive inhibit (tristate) and fully power down a lane. Note that this control routes through the boundary scan logic, which has dominance.  Also note that per-group registers tx_lane_disabled_vec_0_15 and tx_lane_disabled_vec_16_31 are used to logically disable a lane with respect to the training, recalibration, and repair machines. 
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
#define     tx_lane_error_inject_mode_single_err_inj          0x0001     //Used to set the error injection rate to a particular value.  Single Error Injection
#define     tx_lane_error_inject_mode_0                       0x0002     //Used to set the error injection rate to a particular value.  TBD
#define     tx_lane_error_inject_mode_1                       0x0003     //Used to set the error injection rate to a particular value.  TBD
#define     tx_lane_error_inject_mode_2                       0x0010     //Used to set the error injection rate to a particular value.  TBD 
#define     tx_lane_error_inject_mode_3                       0x0011     //Used to set the error injection rate to a particular value.  TBD
#define     tx_lane_error_inject_mode_4                       0x0012     //Used to set the error injection rate to a particular value.  TBD
#define     tx_lane_error_inject_mode_5                       0x0013     //Used to set the error injection rate to a particular value.  TBD
#define     tx_lane_error_inject_mode_6                       0x0020     //Used to set the error injection rate to a particular value.  TBD 
#define     tx_lane_error_inject_mode_7                       0x0021     //Used to set the error injection rate to a particular value.  TBD
#define     tx_lane_error_inject_mode_8                       0x0022     //Used to set the error injection rate to a particular value.  TBD
#define     tx_lane_error_inject_mode_9                       0x0023     //Used to set the error injection rate to a particular value.  TBD
#define     tx_lane_error_inject_mode_10                      0x0030     //Used to set the error injection rate to a particular value.  TBD 
#define     tx_lane_error_inject_mode_11                      0x0031     //Used to set the error injection rate to a particular value.  TBD
#define     tx_lane_error_inject_mode_12                      0x0032     //Used to set the error injection rate to a particular value.  TBD
#define     tx_lane_error_inject_mode_13                      0x0033     //Used to set the error injection rate to a particular value.  TBD
#define     tx_lane_error_inject_mode_clear                   0xF300     // Clear mask

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
#define     tx_prbs_tap_id_pattern_F                          0xA000     //TX Per-Lane PRBS Tap Selector  PRBS tap point F
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
#define     tx_drv_data_pattern_gcrmsg_unused_A               0xA000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     tx_drv_data_pattern_gcrmsg_unused_B               0xB000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     tx_drv_data_pattern_gcrmsg_unused_C               0xC000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     tx_drv_data_pattern_gcrmsg_unused_D               0xD000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     tx_drv_data_pattern_gcrmsg_unused_E               0xE000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     tx_drv_data_pattern_gcrmsg_unused_F               0xF000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     tx_drv_data_pattern_gcrmsg_clear                  0x0FFF     // Clear mask
#define     tx_drv_func_data_gcrmsg                           0x0800     //GCR Message: Functional Data
#define     tx_drv_func_data_gcrmsg_clear                     0xF7FF     // Clear mask
#define     tx_sls_lane_sel_gcrmsg                            0x0400     //GCR Message: SLS Commands & Recalibration
#define     tx_sls_lane_sel_gcrmsg_clear                      0xFBFF     // Clear mask

// tx_sync_pattern_gcrmsg_pl Register field name                        data value   Description
#define     tx_sync_pattern_gcrmsg_pl_spare                   0x8000     //REMOVE ME ONCE CREATEREGS WO/RO ADDRESS DECLARATION BUG IS FIXED
#define     tx_sync_pattern_gcrmsg_pl_spare_clear             0x7FFF     // Clear mask
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
#define     tx_err_inject_lane0                               0x8000     //One Hot - Software Only controled register to inject a error for one pulse on a specified lane.(default)  Inject error on lane 0.
#define     tx_err_inject_lane1                               0x4000     //One Hot - Software Only controled register to inject a error for one pulse on a specified lane.(default)  Inject error on lane 1.
#define     tx_err_inject_lane2                               0x2000     //One Hot - Software Only controled register to inject a error for one pulse on a specified lane.(default)  inject error on lane 2.
#define     tx_err_inject_lane3                               0x1000     //One Hot - Software Only controled register to inject a error for one pulse on a specified lane.(default)  Inject error on lane 3.
#define     tx_err_inject_clear                               0x0FFF     // Clear mask
#define     tx_err_inj_A_enable                               0x0800     //Control to enable the random bit error injection A.(default)
#define     tx_err_inj_A_enable_clear                         0xF7FF     // Clear mask
#define     tx_err_inj_B_enable                               0x0400     //Control to enable the random bit error injection B.(default)
#define     tx_err_inj_B_enable_clear                         0xFBFF     // Clear mask

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
#define     tx_cntl_stat_pg_spare                             0x8000     //REMOVE ME ONCE CREATEREGS WO/RO ADDRESS DECLARATION BUG IS FIXED
#define     tx_cntl_stat_pg_spare_clear                       0x7FFF     // Clear mask
#define     tx_fifo_init                                      0x4000     //Used to initialize the TX FIFO and put it into a known reset state. This will cause the load to unload delay of the FIFO to be set to the value in the TX_FIFO_L2U_DLY field of the TX_FIFO_Mode register.
#define     tx_fifo_init_clear                                0xBFFF     // Clear mask

// tx_mode_pg Register field name                                       data value   Description
#define     tx_max_bad_lanes                                  0x0000     //Static Repair, Dynamic Repair & Recal max number of bad lanes per TX bus
#define     tx_max_bad_lanes_clear                            0x07FF     // Clear mask
#define     tx_msbswap                                        0x0400     //Used to enable end-for-end or msb swap of TX lanes.  For example, lanes 0 and N-1 swap, lanes 1 and N-2 swap, etc. 
#define     tx_msbswap_clear                                  0xFBFF     // Clear mask

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
#define     tx_clk_bist_err                                   0x8000     //Indicates a TXBIST error occurred.
#define     tx_clk_bist_err_clear                             0x7FFF     // Clear mask
#define     tx_clk_bist_done                                  0x4000     //Indicates TXBIST has completed. 
#define     tx_clk_bist_done_clear                            0xBFFF     // Clear mask

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

// tx_minikerf_pg Register field name                                   data value   Description
#define     tx_minikerf                                       0x0000     //Used to configure the TX Minikerf for analog characterization.
#define     tx_minikerf_clear                                 0x0000     // Clear mask

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
#define     tx_ffe_main_p_enc_clear                           0xC0FF     // Clear mask
#define     tx_ffe_main_n_enc                                 0x0000     //TBD
#define     tx_ffe_main_n_enc_clear                           0x3FC0     // Clear mask

// tx_ffe_post_pg Register field name                                   data value   Description
#define     tx_ffe_post_p_enc                                 0x0000     //TBD
#define     tx_ffe_post_p_enc_clear                           0x00FF     // Clear mask
#define     tx_ffe_post_n_enc                                 0x0000     //TBD
#define     tx_ffe_post_n_enc_clear                           0x0FF0     // Clear mask

// tx_ffe_margin_pg Register field name                                 data value   Description
#define     tx_ffe_margin_p_enc                               0x0000     //TBD
#define     tx_ffe_margin_p_enc_clear                         0x00FF     // Clear mask
#define     tx_ffe_margin_n_enc                               0x0000     //TBD
#define     tx_ffe_margin_n_enc_clear                         0x0FF0     // Clear mask

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
#define     tx_bus_width                                      0x0000     //TX Bus Width
#define     tx_bus_width_clear                                0xF01F     // Clear mask
#define     tx_slv_mv_sls_rpr_req_gcrmsg                      0x0010     //GCR Message: Request to TX Slave to Move SLS Lane & Set Bad Lane Register
#define     tx_slv_mv_sls_rpr_req_gcrmsg_clear                0xFFEF     // Clear mask

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

// tx_ber_cntl_a_pp Register field name                                 data value   Description
#define     tx_err_inj_a_rand_beat_dis                        0x8000     //Used to disable randomization of error inject on different beats of data.
#define     tx_err_inj_a_rand_beat_dis_clear                  0x7FFF     // Clear mask
#define     tx_err_inj_a_fine_sel_0_15                        0x1000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Range of 0-15
#define     tx_err_inj_a_fine_sel_0_7                         0x2000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Range of 0-7
#define     tx_err_inj_a_fine_sel_0_3                         0x3000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Range of 0-3
#define     tx_err_inj_a_fine_sel_0_1                         0x4000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Range of 0-1
#define     tx_err_inj_a_fine_sel_fixed1                      0x5000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Fixed 1
#define     tx_err_inj_a_fine_sel_fixed3                      0x6000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Fixed 3
#define     tx_err_inj_a_fine_sel_fixed7                      0x7000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Fixed 7.
#define     tx_err_inj_a_fine_sel_clear                       0x8FFF     // Clear mask
#define     tx_err_inj_a_coarse_sel_8_23                      0x0100     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Range of 8-32, mean of 16
#define     tx_err_inj_a_coarse_sel_12_19                     0x0200     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Range of 12-19, mean of 16
#define     tx_err_inj_a_coarse_sel_14_17                     0x0300     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Range of 14-17, mean of 16
#define     tx_err_inj_a_coarse_sel_min                       0x0400     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Min range of 15-16, mean of 16
#define     tx_err_inj_a_coarse_sel_fixed16                   0x0500     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Fixed 16
#define     tx_err_inj_a_coarse_sel_fixed24                   0x0600     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Fixed 24
#define     tx_err_inj_a_coarse_sel_fixed20                   0x0700     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Fixed 20.
#define     tx_err_inj_a_coarse_sel_clear                     0xF8FF     // Clear mask
#define     tx_err_inj_a_ber_sel                              0x0000     //Used to set the random bit error injection rate to a particular value. See workbook for details.
#define     tx_err_inj_a_ber_sel_clear                        0x3FC0     // Clear mask

// tx_ber_cntl_b_pp Register field name                                 data value   Description
#define     tx_err_inj_b_rand_beat_dis                        0x8000     //Used to disable randomization of error inject on different beats of data.(default)
#define     tx_err_inj_b_rand_beat_dis_clear                  0x7FFF     // Clear mask
#define     tx_err_inj_b_fine_sel_0_15                        0x1000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Range of 0-15
#define     tx_err_inj_b_fine_sel_0_7                         0x2000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Range of 0-7
#define     tx_err_inj_b_fine_sel_0_3                         0x3000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Range of 0-3
#define     tx_err_inj_b_fine_sel_0_1                         0x4000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Range of 0-1
#define     tx_err_inj_b_fine_sel_fixed1                      0x5000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Fixed 1
#define     tx_err_inj_b_fine_sel_fixed3                      0x6000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Fixed 3
#define     tx_err_inj_b_fine_sel_fixed7                      0x7000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Fixed 7.
#define     tx_err_inj_b_fine_sel_clear                       0x8FFF     // Clear mask
#define     tx_err_inj_b_coarse_sel_8_23                      0x0100     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Range of 8-32, mean of 16
#define     tx_err_inj_b_coarse_sel_12_19                     0x0200     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Range of 12-19, mean of 16
#define     tx_err_inj_b_coarse_sel_14_17                     0x0300     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Range of 14-17, mean of 16
#define     tx_err_inj_b_coarse_sel_min                       0x0400     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Min range of 15-16, mean of 16
#define     tx_err_inj_b_coarse_sel_fixed16                   0x0500     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Fixed 16
#define     tx_err_inj_b_coarse_sel_fixed24                   0x0600     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Fixed 24
#define     tx_err_inj_b_coarse_sel_fixed20                   0x0700     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Fixed 20.
#define     tx_err_inj_b_coarse_sel_clear                     0xF8FF     // Clear mask
#define     tx_err_inj_b_ber_sel                              0x0000     //Used to set the random bit error injection rate to a particular value. See workbook for details.
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
#define     tx_bist_en                                        0x8000     //TBD
#define     tx_bist_en_clear                                  0x7FFF     // Clear mask
#define     tx_bist_clr                                       0x4000     //TBD
#define     tx_bist_clr_clear                                 0xBFFF     // Clear mask
#define     tx_bist_prbs7_en                                  0x2000     //TBD
#define     tx_bist_prbs7_en_clear                            0xDFFF     // Clear mask

// tx_ber_cntl_sls_pp Register field name                               data value   Description
#define     tx_err_inj_sls_mode                               0x8000     //Used to set the random bit error injection during SLS. See workbook for details.
#define     tx_err_inj_sls_mode_clear                         0x7FFF     // Clear mask
#define     tx_err_inj_sls_all_cmd                            0x4000     //Used to qualify the SLS mode error injection, to inject on all command values. See workbook for details.
#define     tx_err_inj_sls_all_cmd_clear                      0xBFFF     // Clear mask
#define     tx_err_inj_sls_cmd                                0x0000     //Used to qualify the SLS mode error injection, to only inject on this set command value. See workbook for details.
#define     tx_err_inj_sls_cmd_clear                          0xFFC0     // Clear mask

// tx_cntl_pp Register field name                                       data value   Description
#define     tx_enable_reduced_scramble                        0x8000     //Enables reduced density of scramble pattern. 
#define     tx_enable_reduced_scramble_clear                  0x7FFF     // Clear mask

// tx_reset_cfg_pp Register field name                                  data value   Description
#define     tx_reset_cfg_hld_clear                            0x0000     // Clear mask

// tx_impcal_pb Register field name                                     data value   Description
#define     tx_zcal_spare                                     0x8000     //REMOVE ME ONCE CREATEREGS WO/RO ADDRESS DECLARATION BUG IS FIXED.
#define     tx_zcal_spare_clear                               0x7FFF     // Clear mask
#define     tx_zcal_req                                       0x4000     //\bImpedance Calibration Sequence Enable\b
#define     tx_zcal_req_clear                                 0xBFFF     // Clear mask
#define     tx_zcal_done                                      0x2000     //\bImpedance Calibration Sequence Complete\b
#define     tx_zcal_done_clear                                0xDFFF     // Clear mask
#define     tx_zcal_error                                     0x1000     //\bImpedance Calibration Sequence Error\b
#define     tx_zcal_error_clear                               0xEFFF     // Clear mask
#define     tx_zcal_busy                                      0x0800     //\bImpedance Calibration Sequence Busy\b
#define     tx_zcal_busy_clear                                0xF7FF     // Clear mask
#define     tx_zcal_force_sample                              0x0400     //\bImpedance Comparison Sample Force\b
#define     tx_zcal_force_sample_clear                        0xFBFF     // Clear mask
#define     tx_zcal_cmp_out                                   0x0200     //\bCalibration Circuit Unqualified Sample\b
#define     tx_zcal_cmp_out_clear                             0xFDFF     // Clear mask
#define     tx_zcal_sample_cnt_clear                          0xFE00     // Clear mask

// tx_impcal_nval_pb Register field name                                data value   Description
#define     tx_zcal_n                                         0x0000     //\bCalibration Circuit NSeg Enable Value\b May be read for current calibration result set during Calibration Sequence. May be written to immediately update circuit enables on each write. Used with tx_zcal_swo_* for manual calibration. Do not write when tx_zcal_req = 1. (binary code - 0x00 is zero slices and 0xA1 is maximum slices).
#define     tx_zcal_n_clear                                   0x007F     // Clear mask

// tx_impcal_pval_pb Register field name                                data value   Description
#define     tx_zcal_p                                         0x0000     //\bCalibration Circuit PSeg Enable Value\b May be read for current calibration result set during Calibration Sequence. May be written to immediately update circuit enables on each write. Used with tx_zcal_swo_* for manual calibration. Do not write when tx_zcal_req = 1. (binary code - 0x00 is zero slices and 0xA1 is maximum slices).
#define     tx_zcal_p_clear                                   0x007F     // Clear mask

// tx_impcal_p_4x_pb Register field name                                data value   Description
#define     tx_zcal_p_4x                                      0x0000     //\bCalibration Circuit PSeg-4X Enable Value\b May be read for current calibration result set during Calibration Sequence. May be written to immediately update circuit enables on each write. Used with tx_zcal_swo_* for manual calibration. Do not write when tx_zcal_req = 1. (binary code - 0x00 is zero slices and 0x15 is maximum slices).
#define     tx_zcal_p_4x_clear                                0x07FF     // Clear mask

// tx_impcal_swo1_pb Register field name                                data value   Description
#define     tx_zcal_swo_en                                    0x8000     //\bImpedance Calibration Software Override\b
#define     tx_zcal_swo_en_clear                              0x7FFF     // Clear mask
#define     tx_zcal_swo_cal_segs                              0x4000     //\bImpedance Calibration Software Bank Select\b
#define     tx_zcal_swo_cal_segs_clear                        0xBFFF     // Clear mask
#define     tx_zcal_swo_cmp_inv                               0x2000     //\bImpedance Calibration Software Compare Invert\b
#define     tx_zcal_swo_cmp_inv_clear                         0xDFFF     // Clear mask
#define     tx_zcal_swo_cmp_offset                            0x1000     //\bImpedance Calibration Software Offset Flush\b
#define     tx_zcal_swo_cmp_offset_clear                      0xEFFF     // Clear mask
#define     tx_zcal_swo_cmp_reset                             0x0800     //\bImpedance Calibration Software Comparator reset\b
#define     tx_zcal_swo_cmp_reset_clear                       0xF7FF     // Clear mask
#define     tx_zcal_swo_powerdown                             0x0400     //\bImpedance Calibration Software Circuit Powerdown\b
#define     tx_zcal_swo_powerdown_clear                       0xFBFF     // Clear mask
#define     tx_zcal_cya_data_inv                              0x0200     //\bImpedance Calibration CYA Sample Inversion\b
#define     tx_zcal_cya_data_inv_clear                        0xFDFF     // Clear mask
#define     tx_zcal_test_ovr_2r                               0x0100     //\bImpedance Calibration Test-Only 2R segment override\b
#define     tx_zcal_test_ovr_2r_clear                         0xFEFF     // Clear mask

// tx_impcal_swo2_pb Register field name                                data value   Description
#define     tx_zcal_sm_min_val                                0x0000     //\bImpedance Calibration Minimum Search Threshold\b Low-side segment count limit used in calibration process. See circuit spec (binary code - 0x00 is zero slices and 0x50 is maximum slices).
#define     tx_zcal_sm_min_val_clear                          0x01FF     // Clear mask
#define     tx_zcal_sm_max_val                                0x0000     //\bImpedance Calibration Maximum Search Threshold\b High-side segment count limit used in calibration process. See circuit spec (binary code - 0x00 is zero slices and 0x50 is maximum slices).
#define     tx_zcal_sm_max_val_clear                          0xFE03     // Clear mask

// rx_mode_pl Register field name                                       data value   Description
#define     rx_lane_pdwn                                      0x8000     //Used to receive inhibit and fully power down a lane. Note that this control routes through the boundary scan logic, which has dominance.  Also note that per-group registers rx_lane_disabled_vec_0_15 and rx_lane_disabled_vec_16_31 are used to logically disable a lane with respect to the training, recalibration, and repair machines. 
#define     rx_lane_pdwn_clear                                0x7FFF     // Clear mask
#define     rx_lane_scramble_disable                          0x0200     //Used to disable the RX descrambler on a specific lane or all lanes by using a per-lane/per-group global write.
#define     rx_lane_scramble_disable_clear                    0xFDFF     // Clear mask

// rx_cntl_pl Register field name                                       data value   Description
#define     rx_block_lock_lane                                0x8000     //Enables rotation and checking for block lock. 
#define     rx_block_lock_lane_clear                          0x7FFF     // Clear mask
#define     rx_check_skew_lane                                0x4000     //Per-Lane Initialization controls  checks skew requst
#define     rx_check_skew_lane_clear                          0xBFFF     // Clear mask
#define     rx_cntl_pl_tbd                                    0x0000     //TBD
#define     rx_cntl_pl_tbd_clear                              0xC07F     // Clear mask

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

// rx_eyeopt_mode_pl Register field name                                data value   Description
#define     rx_ddc_disable                                    0x8000     //When set to a 1 this causes the phase detector to stop running which results in the phase rotator value to stop updating. This mode is used for diagnostics and characterization.
#define     rx_ddc_disable_clear                              0x7FFF     // Clear mask

// rx_eyeopt_stat_pl Register field name                                data value   Description
#define     rx_eyeopt_stat_tbd                                0x8000     //Eye optimization status. TBD
#define     rx_eyeopt_stat_tbd_clear                          0x7FFF     // Clear mask

// rx_offset_even_pl Register field name                                data value   Description
#define     rx_offset_even_samp1                              0x0000     //This is the vertical offset of the even sampling latch.
#define     rx_offset_even_samp1_clear                        0xC0FF     // Clear mask
#define     rx_offset_even_samp0                              0x0000     //This is the vertical offset of the even sampling latch.
#define     rx_offset_even_samp0_clear                        0x3FC0     // Clear mask

// rx_offset_odd_pl Register field name                                 data value   Description
#define     rx_offset_odd_samp1                               0x0000     //This is the vertical offset of the odd sampling latch.
#define     rx_offset_odd_samp1_clear                         0x00FF     // Clear mask
#define     rx_offset_odd_samp0                               0x0000     //This is the vertical offset of the odd sampling latch.
#define     rx_offset_odd_samp0_clear                         0x3FC0     // Clear mask

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
#define     rx_fifo_l2u_dly                                   0x0000     //RX FIFO load-to-unload delay, initailed during FIFO init and modified thereafter by the deskew machine.  For setting X, the latency is 4*X to 4*X+4 UI.  Default is 16-20 UI.
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
#define     rx_pl_fir_errs_mask                               0x0000     //A 1 in this field indicates that a register or state machine parity error has occurred in per-group logic.
#define     rx_pl_fir_errs_mask_clear                         0x3FFF     // Clear mask

// rx_fir_error_inject_pl Register field name                           data value   Description
#define     rx_pl_fir_err_inj_inj_par_err                     0x4000     //RX Per-Lane Parity Error Injection  Causes a parity flip in the specific parity checker.
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
#define     rx_fifo_cntl_spare                                0x1000     //Spare to make cr happy.
#define     rx_fifo_cntl_spare_clear                          0xEFFF     // Clear mask

// rx_ber_status_pl Register field name                                 data value   Description
#define     rx_ber_count                                      0x0000     //Per-Lane (PL) Diagnostic Bit Error Rate (BER) error counter. Increments when in diagnostic BER mode AND the output of the descrambler is non-zero. This counter counts errors on every UI so it is a true BER counter.
#define     rx_ber_count_clear                                0x80FF     // Clear mask
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
#define     rx_eye_width_cntl_pl_spare                        0x4000     //RX Eye width control spare
#define     rx_eye_width_cntl_pl_spare_clear                  0xBFFF     // Clear mask

// rx_dfe_clkadj_pl Register field name                                 data value   Description
#define     rx_dfe_clkadj                                     0x0000     //TBD
#define     rx_dfe_clkadj_clear                               0x0FFF     // Clear mask

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

// rx_mode_pg Register field name                                       data value   Description
#define     rx_master_mode                                    0x8000     //Master Mode
#define     rx_master_mode_clear                              0x7FFF     // Clear mask
#define     rx_disable_fence_reset                            0x4000     //Set to disable clearing of the RX and TX fence controls at the end of training. 
#define     rx_disable_fence_reset_clear                      0xBFFF     // Clear mask

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

// rx_recal_mode_pg Register field name                                 data value   Description
#define     rx_recal_disable                                  0x8000     //TBD
#define     rx_recal_disable_clear                            0x7FFF     // Clear mask

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

// rx_bist_cntl_pg Register field name                                  data value   Description
#define     rx_bist_en                                        0x8000     //TBD
#define     rx_bist_en_clear                                  0x7FFF     // Clear mask
#define     rx_bist_jitter_pulse_ctl                          0x0000     //TBD
#define     rx_bist_jitter_pulse_ctl_clear                    0x9FFF     // Clear mask
#define     rx_bist_min_eye_width                             0x0000     //TBD
#define     rx_bist_min_eye_width_clear                       0xF03F     // Clear mask

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
#define     rx_start_bist_helper_1                            0x0200     //Starts BIST helper state machine.   (wtbyp
#define     rx_start_bist_helper_2                            0x0400     //Starts BIST helper state machine.   (ocal
#define     rx_start_bist_helper_3                            0x0600     //Starts BIST helper state machine.   (bist
#define     rx_start_bist_helper_clear                        0xF9FF     // Clear mask


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
#define     rx_bist_helper_done                               0x0400     //When this bit is read as a 1, the BIST helper state machine has completed.
#define     rx_bist_helper_done_clear                         0xFBFF     // Clear mask
#define     rx_wiretest_failed                                0x0080     //When this bit is read as a 1, the wiretest training state encountered an error.
#define     rx_wiretest_failed_clear                          0xFF7F     // Clear mask
#define     rx_deskew_failed                                  0x0040     //When this bit is read as a 1, the deskew training state encountered an error.
#define     rx_deskew_failed_clear                            0xFFBF     // Clear mask
#define     rx_eye_opt_failed                                 0x0020     //When this bit is read as a 1, the eye optimization training state encountered an error.
#define     rx_eye_opt_failed_clear                           0xFFDF     // Clear mask
#define     rx_repair_failed                                  0x0010     //When this bit is read as a 1, the static lane repair training state encountered an error.
#define     rx_repair_failed_clear                            0xFFEF     // Clear mask
#define     rx_func_mode_failed                               0x0008     //When this bit is read as a 1, the transition to functional data training state encountered and error.
#define     rx_func_mode_failed_clear                         0xFFF7     // Clear mask



// rx_recal_status_pg Register field name                               data value   Description
#define     rx_recal_status                                   0x0000     //\bRX Recalibration Status\b
#define     rx_recal_status_clear                             0x0000     // Clear mask

// rx_timeout_sel_pg Register field name                                data value   Description
#define     rx_sls_timeout_sel_tap1                           0x2000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  64k UI 
#define     rx_sls_timeout_sel_tap2                           0x4000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  128k UI 
#define     rx_sls_timeout_sel_tap3                           0x6000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  256k UI 
#define     rx_sls_timeout_sel_tap4                           0x8000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  512k UI 
#define     rx_sls_timeout_sel_tap5                           0xA000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  1024k UI 
#define     rx_sls_timeout_sel_tap6                           0xC000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  32768k UI 
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

// rx_state_debug_pg Register field name                                data value   Description
#define     rx_start_at_state_en                              0x8000     //Enable Statemachine to Start
#define     rx_start_at_state_en_clear                        0x7FFF     // Clear mask
#define     rx_stop_at_state_en                               0x4000     //Enable Statemachine to Stop
#define     rx_stop_at_state_en_clear                         0xBFFF     // Clear mask
#define     rx_state_stopped                                  0x2000     //Statemachine Has Stopped at RX_STOP_STATE
#define     rx_state_stopped_clear                            0xDFFF     // Clear mask
#define     rx_cur_state                                      0x0000     //Current Value of Statemachine Vector
#define     rx_cur_state_clear                                0xE01F     // Clear mask

// rx_state_val_pg Register field name                                  data value   Description
#define     rx_start_state                                    0x0000     //Start Value for Statemachine
#define     rx_start_state_clear                              0x00FF     // Clear mask
#define     rx_stop_state                                     0x0000     //Stop Value for Statemachine
#define     rx_stop_state_clear                               0xFF00     // Clear mask

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
#define     rx_pg_fir1_errs_clear                             0x0003     // Clear mask
#define     rx_pl_fir_err                                     0x0001     //Summary bit indicating an RX per-lane register or state machine parity error has occurred in one or more lanes. The rx_fir_pl register from each lane should be read to isolate to a particular piece of logic. There is no mechanism to determine which lane had the fault without reading FIR status from each lane.
#define     rx_pl_fir_err_clear                               0xFFFE     // Clear mask

// rx_fir2_pg Register field name                                       data value   Description
#define     rx_pg_fir2_errs_clear                             0x1FFF     // Clear mask

// rx_fir1_mask_pg Register field name                                  data value   Description
#define     rx_pg_fir1_errs_mask_clear                        0x0003     // Clear mask
#define     rx_pg_chan_fail_mask                              0x0002     //FIR mask for generation of channel fail error when Max Spares Exceeded is active. Default is disabled with a value of 1.
#define     rx_pg_chan_fail_mask_clear                        0xFFFD     // Clear mask
#define     rx_pl_fir_err_mask                                0x0001     //FIR mask for the summary bit that indicates an RX register or state machine parity error has occurred. This mask bit is used to block ALL per-lane parity errors from causing a FIR error.
#define     rx_pl_fir_err_mask_clear                          0xFFFE     // Clear mask

// rx_fir2_mask_pg Register field name                                  data value   Description
#define     rx_pg_fir2_errs_mask_clear                        0x1FFF     // Clear mask

// rx_fir1_error_inject_pg Register field name                          data value   Description
#define     rx_pg_fir1_err_inj_inj_par_err                    0x4000     //RX Per-Group Parity Error Injection  Causes a parity flip in the specific parity checker.
#define     rx_pg_fir1_err_inj_clear                          0x0003     // Clear mask

// rx_fir2_error_inject_pg Register field name                          data value   Description
#define     rx_pg_fir2_err_inj_inj_par_err                    0x2000     //RX Per-Group Parity Error Injection  Causes a parity flip in the specific parity checker.
#define     rx_pg_fir2_err_inj_clear                          0x1FFF     // Clear mask

// rx_fir_training_pg Register field name                               data value   Description
#define     rx_pg_fir_training_error                          0x8000     //A Training Error has occurred. The Training Error FFDC registers should be read to help isolate to a particular piece of logic.
#define     rx_pg_fir_training_error_clear                    0x7FFF     // Clear mask
#define     rx_pg_fir_static_spare_deployed                   0x4000     //A spare lane has been deployed during training to heal a lane that was detected as bad. The rx_bad_lane_enc_gcrmsg_pg register can be read to isolate which lane(s) were healed
#define     rx_pg_fir_static_spare_deployed_clear             0xBFFF     // Clear mask
#define     rx_pg_fir_static_max_spares_exceeded              0x2000     //A lane has been detected as bad during training but there are no spare lanes to heal it. THIS IS A CATASTROPHIC FAILURE FOR THE BUS.
#define     rx_pg_fir_static_max_spares_exceeded_clear        0xDFFF     // Clear mask
#define     rx_pg_fir_dynamic_spare_deployed                  0x1000     //A spare lane has been deployed by ECC/CRC logic to heal a lane that was detected as bad. The rx_bad_lane_enc_gcrmsg_pg register can be read to isolate which lane(s) were healed.
#define     rx_pg_fir_dynamic_spare_deployed_clear            0xEFFF     // Clear mask
#define     rx_pg_fir_dynamic_max_spares_exceeded             0x0800     //A lane has been detected as bad by ECC/CRC logic but there are no spare lanes to heal it. THIS IS A CATASTROPHIC FAILURE FOR THE BUS.
#define     rx_pg_fir_dynamic_max_spares_exceeded_clear       0xF7FF     // Clear mask
#define     rx_pg_fir_recal_error                             0x0400     //A Recalibration Error has occurred. The Recal Error FFDC registers should be read to help isolate to a particular piece of logic.
#define     rx_pg_fir_recal_error_clear                       0xFBFF     // Clear mask
#define     rx_pg_fir_recal_spare_deployed                    0x0200     //A spare lane has been deployed during Recal to heal a lane that was detected as bad. The rx_bad_lane_enc_gcrmsg_pg register can be read to isolate which lane(s) were healed.
#define     rx_pg_fir_recal_spare_deployed_clear              0xFDFF     // Clear mask
#define     rx_pg_fir_recal_max_spares_exceeded               0x0100     //A lane has been detected as bad during Recal but there are no spare lanes to heal it. THIS IS A CATASTROPHIC FAILURE FOR THE BUS.
#define     rx_pg_fir_recal_max_spares_exceeded_clear         0xFEFF     // Clear mask

// rx_fir_training_mask_pg Register field name                          data value   Description
#define     rx_pg_fir_training_error_mask                     0x8000     //FIR mask for rx_pg_fir_training_error.
#define     rx_pg_fir_training_error_mask_clear               0x7FFF     // Clear mask
#define     rx_pg_fir_static_spare_deployed_mask              0x4000     //FIR mask for rx_pg_fir_static_spare_deployed.
#define     rx_pg_fir_static_spare_deployed_mask_clear        0xBFFF     // Clear mask
#define     rx_pg_fir_static_max_spares_exceeded_mask         0x2000     //FIR mask for rx_pg_fir_static_max_spares_exceeded
#define     rx_pg_fir_static_max_spares_exceeded_mask_clear   0xDFFF     // Clear mask
#define     rx_pg_fir_dynamic_spare_deployed_mask             0x1000     //FIR mask for rx_pg_fir_dynamic_spare_deployed.
#define     rx_pg_fir_dynamic_spare_deployed_mask_clear       0xEFFF     // Clear mask
#define     rx_pg_fir_dynamic_max_spares_exceeded_mask        0x0800     //FIR mask for rx_pg_fir_dynamic_max_spares_exceeded.
#define     rx_pg_fir_dynamic_max_spares_exceeded_mask_clear  0xF7FF     // Clear mask
#define     rx_pg_fir_recal_error_mask                        0x0400     //FIR mask for rx_pg_fir_recal_error.
#define     rx_pg_fir_recal_error_mask_clear                  0xFBFF     // Clear mask
#define     rx_pg_fir_recal_spare_deployed_mask               0x0200     //FIR mask for rx_pg_fir_recal_spare_deployed.
#define     rx_pg_fir_recal_spare_deployed_mask_clear         0xFDFF     // Clear mask
#define     rx_pg_fir_recal_max_spares_exceeded_mask          0x0100     //FIR mask for rx_pg_fir_recal_max_spares_exceeded.
#define     rx_pg_fir_recal_max_spares_exceeded_mask_clear    0xFEFF     // Clear mask

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
#define     rx_lane_bad_vec_0_15                              0x0000     //Lanes found bad by HW (status) or method to force lane bad from software (control).
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

// rx_dyn_rpr_err_tallying_pg Register field name                       data value   Description
#define     rx_dyn_rpr_bad_lane_max                           0x0000     //CRC/ECC Dynamic Repair: Max number of times a lane can be found bad before repaired
#define     rx_dyn_rpr_bad_lane_max_clear                     0x07FF     // Clear mask
#define     rx_dyn_rpr_err_cntr_duration_tap1                 0x0100     //CRC/ECC Dynamic Repair: Duration the error counter can run before being cleared (determines the allowed error frequency)  106.6ns
#define     rx_dyn_rpr_err_cntr_duration_tap2                 0x0200     //CRC/ECC Dynamic Repair: Duration the error counter can run before being cleared (determines the allowed error frequency)  1.7uS
#define     rx_dyn_rpr_err_cntr_duration_tap3                 0x0300     //CRC/ECC Dynamic Repair: Duration the error counter can run before being cleared (determines the allowed error frequency)  27.3uS
#define     rx_dyn_rpr_err_cntr_duration_tap4                 0x0400     //CRC/ECC Dynamic Repair: Duration the error counter can run before being cleared (determines the allowed error frequency)  436.7uS
#define     rx_dyn_rpr_err_cntr_duration_tap5                 0x0500     //CRC/ECC Dynamic Repair: Duration the error counter can run before being cleared (determines the allowed error frequency)  7.0mS
#define     rx_dyn_rpr_err_cntr_duration_tap6                 0x0600     //CRC/ECC Dynamic Repair: Duration the error counter can run before being cleared (determines the allowed error frequency)  111.8mS
#define     rx_dyn_rpr_err_cntr_duration_tap7                 0x0700     //CRC/ECC Dynamic Repair: Duration the error counter can run before being cleared (determines the allowed error frequency)  1.8S
#define     rx_dyn_rpr_err_cntr_duration_clear                0xF8FF     // Clear mask
#define     rx_dyn_rpr_clr_err_cntr                           0x0080     //CRC/ECC Dynamic Repair: Firmware-based clear of error counter register
#define     rx_dyn_rpr_clr_err_cntr_clear                     0xFF7F     // Clear mask

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
#define     rx_dyn_recal_main_state_clear                     0x00FF     // Clear mask
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
#define     rx_dyn_recal_latch_offset                         0x0200     //RX Dynamic Recalibration latch offset adjustment enable  (EDI only)
#define     rx_dyn_recal_latch_offset_clear                   0xFDFF     // Clear mask
#define     rx_dyn_recal_ctle                                 0x0100     //RX Dynamic Recalibration CTLE/Peakin enable (EDI only)
#define     rx_dyn_recal_ctle_clear                           0xFEFF     // Clear mask
#define     rx_dyn_recal_vga                                  0x0080     //RX Dynamic Recalibration VGA gain and offset adjust enable (EDI only)
#define     rx_dyn_recal_vga_clear                            0xFF7F     // Clear mask
#define     rx_dyn_recal_dfe_h1                               0x0040     //RX Dynamic Recalibration DFE H1 adjust enable (EDI only)
#define     rx_dyn_recal_dfe_h1_clear                         0xFFBF     // Clear mask
#define     rx_dyn_recal_h1ap_tweak                           0x0020     //RX Dynamic Recalibration H1/AN PR adjust enable (EDI only)
#define     rx_dyn_recal_h1ap_tweak_clear                     0xFFDF     // Clear mask
#define     rx_dyn_recal_ddc                                  0x0010     //RX Dynamic Recalibration Dynamic data centering enable (EDI only)
#define     rx_dyn_recal_ddc_clear                            0xFFEF     // Clear mask
#define     rx_dyn_recal_ber_test                             0x0008     //RX Dynamic Recalibration Dynamic data centering enable (EDI only)
#define     rx_dyn_recal_ber_test_clear                       0xFFF7     // Clear mask
#define     rx_dyn_recal_ber_test_timeout                     0x0000     //RX Dynamic Recalibration Bit Error Rate test timeout (EDI only)
#define     rx_dyn_recal_ber_test_timeout_clear               0xFFB8     // Clear mask

// rx_servo_recal_gcrmsg_pg Register field name                         data value   Description
#define     rx_servo_recal_done_gcrmsg                        0x8000     //GCR Message: RX Servo Done Calibrating Lane for Dynamic Recal
#define     rx_servo_recal_done_gcrmsg_clear                  0x7FFF     // Clear mask

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
#define     rx_wt_cu_pll_pgood                                0x8000     //RX cleanup PLL Enable
#define     rx_wt_cu_pll_pgood_clear                          0x7FFF     // Clear mask
#define     rx_wt_cu_pll_reset                                0x4000     //RX cleanup PLL Enable Request
#define     rx_wt_cu_pll_reset_clear                          0xBFFF     // Clear mask
#define     rx_wt_cu_pll_pgooddly_50ns                        0x0800     //RX cleanup PLL PGOOD Delay Selects length of reset period after rx_wt_cu_pll_reset is set.   Nominal 50ns Reset per PLL Spec 
#define     rx_wt_cu_pll_pgooddly_100ns                       0x1000     //RX cleanup PLL PGOOD Delay Selects length of reset period after rx_wt_cu_pll_reset is set.   Double Nominal 50ns Reset per PLL Spec 
#define     rx_wt_cu_pll_pgooddly_960ui                       0x1800     //RX cleanup PLL PGOOD Delay Selects length of reset period after rx_wt_cu_pll_reset is set.   Typical simulation delay exceeding TX PLL 40-refclk locking period 
#define     rx_wt_cu_pll_pgooddly_unused_100                  0x2000     //RX cleanup PLL PGOOD Delay Selects length of reset period after rx_wt_cu_pll_reset is set.   Reserved 
#define     rx_wt_cu_pll_pgooddly_unused_101                  0x2800     //RX cleanup PLL PGOOD Delay Selects length of reset period after rx_wt_cu_pll_reset is set.   Reserved 
#define     rx_wt_cu_pll_pgooddly_MAX                         0x3000     //RX cleanup PLL PGOOD Delay Selects length of reset period after rx_wt_cu_pll_reset is set.   1024 UI  
#define     rx_wt_cu_pll_pgooddly_disable                     0x3800     //RX cleanup PLL PGOOD Delay Selects length of reset period after rx_wt_cu_pll_reset is set.   Disable rx_wt_cu_pll_reset
#define     rx_wt_cu_pll_pgooddly_clear                       0xC7FF     // Clear mask
#define     rx_wt_cu_pll_lock                                 0x0400     //RX cleanup PLL Locked
#define     rx_wt_cu_pll_lock_clear                           0xFBFF     // Clear mask

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
#define     rx_sls_rcvy_state_clear                           0xE0FF     // Clear mask

// rx_sls_rcvy_gcrmsg_pg Register field name                            data value   Description
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
#define     rx_sls_rcvy_rx_ip_gcrmsg                          0x0020     //GCR Message: SLS Rcvy; RX Lane Repair IP
#define     rx_sls_rcvy_rx_ip_gcrmsg_clear                    0xFFDF     // Clear mask
#define     rx_sls_rcvy_rx_rpred_gcrmsg                       0x0010     //GCR Message: SLS Rcvy; RX Lane Repair Done
#define     rx_sls_rcvy_rx_rpred_gcrmsg_clear                 0xFFEF     // Clear mask

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
#define     rx_trc_mode_tap5                                  0x5000     //RX Trace Mode  CRC/ECC Tallying Logic
#define     rx_trc_mode_tap6                                  0x6000     //RX Trace Mode  RX SLS Commands
#define     rx_trc_mode_tap7                                  0x7000     //RX Trace Mode  RX Bad Lanes
#define     rx_trc_mode_tap8                                  0x8000     //RX Trace Mode  RX SLS Lanes
#define     rx_trc_mode_tap9                                  0x9000     //RX Trace Mode  TBD
#define     rx_trc_mode_tap10                                 0xA000     //RX Trace Mode  TBD
#define     rx_trc_mode_tap11                                 0xB000     //RX Trace Mode  TBD
#define     rx_trc_mode_tap12                                 0xC000     //RX Trace Mode  TBD
#define     rx_trc_mode_tap13                                 0xD000     //RX Trace Mode  TBD
#define     rx_trc_mode_tap14                                 0xE000     //RX Trace Mode  TBD
#define     rx_trc_mode_tap15                                 0xF000     //RX Trace Mode  TBD
#define     rx_trc_mode_clear                                 0x0FFF     // Clear mask
#define     rx_trc_grp_clear                                  0xFC0F     // Clear mask

// rx_wiretest_pp Register field name                                   data value   Description
#define     rx_wt_pattern_length_256                          0x4000     //RX Wiretest Pattern Length  256
#define     rx_wt_pattern_length_512                          0x8000     //RX Wiretest Pattern Length  512
#define     rx_wt_pattern_length_1024                         0xC000     //RX Wiretest Pattern Length  1024
#define     rx_wt_pattern_length_clear                        0x3FFF     // Clear mask

// rx_mode_pp Register field name                                       data value   Description
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

// rx_servo_recal_gcrmsg_pp Register field name                         data value   Description
#define     rx_servo_recal_ip_gcrmsg                          0x8000     //GCR Message: RX Servo Lane Calibration In Progress
#define     rx_servo_recal_ip_gcrmsg_clear                    0x7FFF     // Clear mask

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

// tx_mode_pl Register field name                                       data value   Description
#define     ei4_tx_lane_pdwn                                      0x8000     //Used to drive inhibit (tristate) and fully power down a lane. Note that this control routes through the boundary scan logic, which has dominance.  Also note that per-group registers ei4_tx_lane_disabled_vec_0_15 and ei4_tx_lane_disabled_vec_16_31 are used to logically disable a lane with respect to the training, recalibration, and repair machines. 
#define     ei4_tx_lane_pdwn_clear                                0x7FFF     // Clear mask
#define     ei4_tx_lane_invert                                    0x4000     //Used to invert the polarity of a lane.
#define     ei4_tx_lane_invert_clear                              0xBFFF     // Clear mask
#define     ei4_tx_lane_quiesce_quiesce_to_0                      0x1000     //Used to force the output of a lane to a particular value.  Quiesce Lane to a Static 0 value
#define     ei4_tx_lane_quiesce_quiesce_to_1                      0x2000     //Used to force the output of a lane to a particular value.  Quiesce Lane to a Static 1 value
#define     ei4_tx_lane_quiesce_quiesce_to_z                      0x3000     //Used to force the output of a lane to a particular value.  Tri-State Lane Output
#define     ei4_tx_lane_quiesce_clear                             0xCFFF     // Clear mask
#define     ei4_tx_lane_scramble_disable                          0x0200     //Used to disable the TX scrambler on a specific lane or all lanes by using a per-lane/per-group global write.
#define     ei4_tx_lane_scramble_disable_clear                    0xFDFF     // Clear mask
#define     ei4_tx_lane_error_inject_mode_single_err_inj          0x0001     //Used to set the error injection rate to a particular value.  Single Error Injection
#define     ei4_tx_lane_error_inject_mode_0                       0x0002     //Used to set the error injection rate to a particular value.  TBD
#define     ei4_tx_lane_error_inject_mode_1                       0x0003     //Used to set the error injection rate to a particular value.  TBD
#define     ei4_tx_lane_error_inject_mode_2                       0x0010     //Used to set the error injection rate to a particular value.  TBD 
#define     ei4_tx_lane_error_inject_mode_3                       0x0011     //Used to set the error injection rate to a particular value.  TBD
#define     ei4_tx_lane_error_inject_mode_4                       0x0012     //Used to set the error injection rate to a particular value.  TBD
#define     ei4_tx_lane_error_inject_mode_5                       0x0013     //Used to set the error injection rate to a particular value.  TBD
#define     ei4_tx_lane_error_inject_mode_6                       0x0020     //Used to set the error injection rate to a particular value.  TBD 
#define     ei4_tx_lane_error_inject_mode_7                       0x0021     //Used to set the error injection rate to a particular value.  TBD
#define     ei4_tx_lane_error_inject_mode_8                       0x0022     //Used to set the error injection rate to a particular value.  TBD
#define     ei4_tx_lane_error_inject_mode_9                       0x0023     //Used to set the error injection rate to a particular value.  TBD
#define     ei4_tx_lane_error_inject_mode_10                      0x0030     //Used to set the error injection rate to a particular value.  TBD 
#define     ei4_tx_lane_error_inject_mode_11                      0x0031     //Used to set the error injection rate to a particular value.  TBD
#define     ei4_tx_lane_error_inject_mode_12                      0x0032     //Used to set the error injection rate to a particular value.  TBD
#define     ei4_tx_lane_error_inject_mode_13                      0x0033     //Used to set the error injection rate to a particular value.  TBD
#define     ei4_tx_lane_error_inject_mode_clear                   0xF300     // Clear mask

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
#define     ei4_tx_prbs_tap_id_pattern_F                          0xA000     //TX Per-Lane PRBS Tap Selector  PRBS tap point F
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
#define     ei4_tx_drv_data_pattern_gcrmsg_unused_A               0xA000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     ei4_tx_drv_data_pattern_gcrmsg_unused_B               0xB000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     ei4_tx_drv_data_pattern_gcrmsg_unused_C               0xC000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     ei4_tx_drv_data_pattern_gcrmsg_unused_D               0xD000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     ei4_tx_drv_data_pattern_gcrmsg_unused_E               0xE000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     ei4_tx_drv_data_pattern_gcrmsg_unused_F               0xF000     //GCR Message: TX Per Data Lane Drive Patterns  Unused
#define     ei4_tx_drv_data_pattern_gcrmsg_clear                  0x0FFF     // Clear mask
#define     ei4_tx_drv_func_data_gcrmsg                           0x0800     //GCR Message: Functional Data
#define     ei4_tx_drv_func_data_gcrmsg_clear                     0xF7FF     // Clear mask
#define     ei4_tx_sls_lane_sel_gcrmsg                            0x0400     //GCR Message: SLS Commands & Recalibration
#define     ei4_tx_sls_lane_sel_gcrmsg_clear                      0xFBFF     // Clear mask

// ei4_tx_sync_pattern_gcrmsg_pl Register field name                        data value   Description
#define     ei4_tx_sync_pattern_gcrmsg_pl_spare                   0x8000     //REMOVE ME ONCE CREATEREGS WO/RO ADDRESS DECLARATION BUG IS FIXED
#define     ei4_tx_sync_pattern_gcrmsg_pl_spare_clear             0x7FFF     // Clear mask
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
#define     ei4_tx_err_inject_lane0                               0x8000     //One Hot - Software Only controled register to inject a error for one pulse on a specified lane.(default)  Inject error on lane 0.
#define     ei4_tx_err_inject_lane1                               0x4000     //One Hot - Software Only controled register to inject a error for one pulse on a specified lane.(default)  Inject error on lane 1.
#define     ei4_tx_err_inject_lane2                               0x2000     //One Hot - Software Only controled register to inject a error for one pulse on a specified lane.(default)  inject error on lane 2.
#define     ei4_tx_err_inject_lane3                               0x1000     //One Hot - Software Only controled register to inject a error for one pulse on a specified lane.(default)  Inject error on lane 3.
#define     ei4_tx_err_inject_clear                               0x0FFF     // Clear mask
#define     ei4_tx_err_inj_A_enable                               0x0800     //Control to enable the random bit error injection A.(default)
#define     ei4_tx_err_inj_A_enable_clear                         0xF7FF     // Clear mask
#define     ei4_tx_err_inj_B_enable                               0x0400     //Control to enable the random bit error injection B.(default)
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
#define     ei4_tx_cntl_stat_pg_spare                             0x8000     //REMOVE ME ONCE CREATEREGS WO/RO ADDRESS DECLARATION BUG IS FIXED
#define     ei4_tx_cntl_stat_pg_spare_clear                       0x7FFF     // Clear mask
#define     ei4_tx_fifo_init                                      0x4000     //Used to initialize the TX FIFO and put it into a known reset state. This will cause the load to unload delay of the FIFO to be set to the value in the ei4_tx_FIFO_L2U_DLY field of the ei4_tx_FIFO_Mode register.
#define     ei4_tx_fifo_init_clear                                0xBFFF     // Clear mask

// ei4_tx_mode_pg Register field name                                       data value   Description
#define     ei4_tx_max_bad_lanes                                  0x0000     //Static Repair, Dynamic Repair & Recal max number of bad lanes per TX bus
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
#define     ei4_tx_clk_bist_err                                   0x8000     //Indicates a TXBIST error occurred.
#define     ei4_tx_clk_bist_err_clear                             0x7FFF     // Clear mask
#define     ei4_tx_clk_bist_done                                  0x4000     //Indicates TXBIST has completed. 
#define     ei4_tx_clk_bist_done_clear                            0xBFFF     // Clear mask

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

// ei4_tx_minikerf_pg Register field name                                   data value   Description
#define     ei4_tx_minikerf                                       0x0000     //Used to configure the TX Minikerf for analog characterization.
#define     ei4_tx_minikerf_clear                                 0x0000     // Clear mask

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

// ei4_tx_pc_ffe_pg Register field name                                     data value   Description
#define     ei4_tx_pc_test_mode                                   0x8000     //Driver Segment Test mode
#define     ei4_tx_pc_test_mode_clear                             0x7FFF     // Clear mask
#define     ei4_tx_main_slice_en_enc                              0x0000     //240ohm main slice enable (binary code - 0000 is zero slices and 0110 is maximum slices)
#define     ei4_tx_main_slice_en_enc_clear                        0xF0FF     // Clear mask
#define     ei4_tx_pc_slice_en_enc                                0x0000     //240ohm precompensation slice enable (binary code - 0000 is zero slices and 1110 is maximum slices)
#define     ei4_tx_pc_slice_en_enc_clear                          0x0FF0     // Clear mask

// ei4_tx_misc_analog_pg Register field name                                data value   Description
#define     ei4_tx_slewctl                                        0x0000     //TBD
#define     ei4_tx_slewctl_clear                                  0x0FFF     // Clear mask
#define     ei4_tx_pvtnl_enc                                      0x0000     //TBD
#define     ei4_tx_pvtnl_enc_clear                                0xFF0F     // Clear mask
#define     ei4_tx_pvtpl_enc                                      0x0000     //TBD
#define     ei4_tx_pvtpl_enc_clear                                0xF0F0     // Clear mask

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
#define     ei4_tx_bus_width                                      0x0000     //TX Bus Width
#define     ei4_tx_bus_width_clear                                0xF01F     // Clear mask
#define     ei4_tx_slv_mv_sls_rpr_req_gcrmsg                      0x0010     //GCR Message: Request to TX Slave to Move SLS Lane & Set Bad Lane Register
#define     ei4_tx_slv_mv_sls_rpr_req_gcrmsg_clear                0xFFEF     // Clear mask

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

// ei4_tx_ber_cntl_a_pp Register field name                                 data value   Description
#define     ei4_tx_err_inj_a_rand_beat_dis                        0x8000     //Used to disable randomization of error inject on different beats of data.
#define     ei4_tx_err_inj_a_rand_beat_dis_clear                  0x7FFF     // Clear mask
#define     ei4_tx_err_inj_a_fine_sel_0_15                        0x1000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Range of 0-15
#define     ei4_tx_err_inj_a_fine_sel_0_7                         0x2000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Range of 0-7
#define     ei4_tx_err_inj_a_fine_sel_0_3                         0x3000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Range of 0-3
#define     ei4_tx_err_inj_a_fine_sel_0_1                         0x4000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Range of 0-1
#define     ei4_tx_err_inj_a_fine_sel_fixed1                      0x5000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Fixed 1
#define     ei4_tx_err_inj_a_fine_sel_fixed3                      0x6000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Fixed 3
#define     ei4_tx_err_inj_a_fine_sel_fixed7                      0x7000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Fixed 7.
#define     ei4_tx_err_inj_a_fine_sel_clear                       0x8FFF     // Clear mask
#define     ei4_tx_err_inj_a_coarse_sel_8_23                      0x0100     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Range of 8-32, mean of 16
#define     ei4_tx_err_inj_a_coarse_sel_12_19                     0x0200     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Range of 12-19, mean of 16
#define     ei4_tx_err_inj_a_coarse_sel_14_17                     0x0300     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Range of 14-17, mean of 16
#define     ei4_tx_err_inj_a_coarse_sel_min                       0x0400     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Min range of 15-16, mean of 16
#define     ei4_tx_err_inj_a_coarse_sel_fixed16                   0x0500     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Fixed 16
#define     ei4_tx_err_inj_a_coarse_sel_fixed24                   0x0600     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Fixed 24
#define     ei4_tx_err_inj_a_coarse_sel_fixed20                   0x0700     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Fixed 20.
#define     ei4_tx_err_inj_a_coarse_sel_clear                     0xF8FF     // Clear mask
#define     ei4_tx_err_inj_a_ber_sel                              0x0000     //Used to set the random bit error injection rate to a particular value. See workbook for details.
#define     ei4_tx_err_inj_a_ber_sel_clear                        0x3FC0     // Clear mask

// ei4_tx_ber_cntl_b_pp Register field name                                 data value   Description
#define     ei4_tx_err_inj_b_rand_beat_dis                        0x8000     //Used to disable randomization of error inject on different beats of data.(default)
#define     ei4_tx_err_inj_b_rand_beat_dis_clear                  0x7FFF     // Clear mask
#define     ei4_tx_err_inj_b_fine_sel_0_15                        0x1000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Range of 0-15
#define     ei4_tx_err_inj_b_fine_sel_0_7                         0x2000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Range of 0-7
#define     ei4_tx_err_inj_b_fine_sel_0_3                         0x3000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Range of 0-3
#define     ei4_tx_err_inj_b_fine_sel_0_1                         0x4000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Range of 0-1
#define     ei4_tx_err_inj_b_fine_sel_fixed1                      0x5000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Fixed 1
#define     ei4_tx_err_inj_b_fine_sel_fixed3                      0x6000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Fixed 3
#define     ei4_tx_err_inj_b_fine_sel_fixed7                      0x7000     //Acts as an adder to the error rate and so does not have any over all effect on the average of the bit error rate.  Fixed 7.
#define     ei4_tx_err_inj_b_fine_sel_clear                       0x8FFF     // Clear mask
#define     ei4_tx_err_inj_b_coarse_sel_8_23                      0x0100     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Range of 8-32, mean of 16
#define     ei4_tx_err_inj_b_coarse_sel_12_19                     0x0200     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Range of 12-19, mean of 16
#define     ei4_tx_err_inj_b_coarse_sel_14_17                     0x0300     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Range of 14-17, mean of 16
#define     ei4_tx_err_inj_b_coarse_sel_min                       0x0400     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Min range of 15-16, mean of 16
#define     ei4_tx_err_inj_b_coarse_sel_fixed16                   0x0500     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Fixed 16
#define     ei4_tx_err_inj_b_coarse_sel_fixed24                   0x0600     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Fixed 24
#define     ei4_tx_err_inj_b_coarse_sel_fixed20                   0x0700     //Multipler for the error rate, narrows or widens the range of the variance in the bit error rate.  Fixed 20.
#define     ei4_tx_err_inj_b_coarse_sel_clear                     0xF8FF     // Clear mask
#define     ei4_tx_err_inj_b_ber_sel                              0x0000     //Used to set the random bit error injection rate to a particular value. See workbook for details.
#define     ei4_tx_err_inj_b_ber_sel_clear                        0x3FC0     // Clear mask

// ei4_tx_bist_cntl_pp Register field name                                  data value   Description
#define     ei4_tx_bist_en                                        0x8000     //TBD
#define     ei4_tx_bist_en_clear                                  0x7FFF     // Clear mask
#define     ei4_tx_bist_clr                                       0x4000     //TBD
#define     ei4_tx_bist_clr_clear                                 0xBFFF     // Clear mask
#define     ei4_tx_bist_prbs7_en                                  0x2000     //TBD
#define     ei4_tx_bist_prbs7_en_clear                            0xDFFF     // Clear mask

// ei4_tx_ber_cntl_sls_pp Register field name                               data value   Description
#define     ei4_tx_err_inj_sls_mode                               0x8000     //Used to set the random bit error injection during SLS. See workbook for details.
#define     ei4_tx_err_inj_sls_mode_clear                         0x7FFF     // Clear mask
#define     ei4_tx_err_inj_sls_all_cmd                            0x4000     //Used to qualify the SLS mode error injection, to inject on all command values. See workbook for details.
#define     ei4_tx_err_inj_sls_all_cmd_clear                      0xBFFF     // Clear mask
#define     ei4_tx_err_inj_sls_cmd                                0x0000     //Used to qualify the SLS mode error injection, to only inject on this set command value. See workbook for details.
#define     ei4_tx_err_inj_sls_cmd_clear                          0xFFC0     // Clear mask

// ei4_tx_cntl_pp Register field name                                       data value   Description
#define     ei4_tx_enable_reduced_scramble                        0x8000     //Enables reduced density of scramble pattern. 
#define     ei4_tx_enable_reduced_scramble_clear                  0x7FFF     // Clear mask

// ei4_tx_reset_cfg_pp Register field name                                  data value   Description
#define     ei4_tx_reset_cfg_hld_clear                            0x0000     // Clear mask

// ei4_rx_mode_pl Register field name                                       data value   Description
#define     ei4_rx_lane_pdwn                                      0x8000     //Used to receive inhibit and fully power down a lane. Note that this control routes through the boundary scan logic, which has dominance.  Also note that per-group registers ei4_rx_lane_disabled_vec_0_15 and ei4_rx_lane_disabled_vec_16_31 are used to logically disable a lane with respect to the training, recalibration, and repair machines. 
#define     ei4_rx_lane_pdwn_clear                                0x7FFF     // Clear mask
#define     ei4_rx_lane_scramble_disable                          0x0200     //Used to disable the RX descrambler on a specific lane or all lanes by using a per-lane/per-group global write.
#define     ei4_rx_lane_scramble_disable_clear                    0xFDFF     // Clear mask

// ei4_rx_cntl_pl Register field name                                       data value   Description
#define     ei4_rx_block_lock_lane                                0x8000     //Enables rotation and checking for block lock. 
#define     ei4_rx_block_lock_lane_clear                          0x7FFF     // Clear mask
#define     ei4_rx_check_skew_lane                                0x4000     //Per-Lane Initialization controls  checks skew requst
#define     ei4_rx_check_skew_lane_clear                          0xBFFF     // Clear mask
#define     ei4_rx_cntl_pl_tbd                                    0x0000     //TBD
#define     ei4_rx_cntl_pl_tbd_clear                              0xC07F     // Clear mask

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

// ei4_rx_prot_edge_status_pl Register field name                           data value   Description
#define     ei4_rx_phaserot_left_edge                             0x0000     //RX Phase Rotator left edge.
#define     ei4_rx_phaserot_left_edge_clear                       0x80FF     // Clear mask

// ei4_rx_bist_stat_pl Register field name                                  data value   Description
#define     ei4_rx_bist_err                                       0x8000     //Indicates a RXBIST error occurred.
#define     ei4_rx_bist_err_clear                                 0x7FFF     // Clear mask
#define     ei4_rx_bist_done                                      0x4000     //Indicates a RXBIST has completed. 
#define     ei4_rx_bist_done_clear                                0xBFFF     // Clear mask

// ei4_rx_eyeopt_mode_pl Register field name                                data value   Description
#define     ei4_rx_ddc_disable                                    0x8000     //When set to a 1 this causes the phase detector to stop running which results in the phase rotator value to stop updating. This mode is used for diagnostics and characterization.
#define     ei4_rx_ddc_disable_clear                              0x7FFF     // Clear mask

// ei4_rx_eyeopt_stat_pl Register field name                                data value   Description
#define     ei4_rx_eyeopt_stat_tbd                                0x8000     //Eye optimization status. TBD
#define     ei4_rx_eyeopt_stat_tbd_clear                          0x7FFF     // Clear mask

// ei4_rx_offset_even_pl Register field name                                data value   Description
#define     ei4_rx_offset_even_samp1                              0x0000     //This is the vertical offset of the even sampling latch.
#define     ei4_rx_offset_even_samp1_clear                        0xC0FF     // Clear mask
#define     ei4_rx_offset_even_samp0                              0x0000     //This is the vertical offset of the even sampling latch.
#define     ei4_rx_offset_even_samp0_clear                        0x3FC0     // Clear mask

// ei4_rx_offset_odd_pl Register field name                                 data value   Description
#define     ei4_rx_offset_odd_samp1                               0x0000     //This is the vertical offset of the odd sampling latch.
#define     ei4_rx_offset_odd_samp1_clear                         0x00FF     // Clear mask
#define     ei4_rx_offset_odd_samp0                               0x0000     //This is the vertical offset of the odd sampling latch.
#define     ei4_rx_offset_odd_samp0_clear                         0x3FC0     // Clear mask

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
#define     ei4_rx_fifo_l2u_dly                                   0x0000     //RX FIFO load-to-unload delay, initailed during FIFO init and modified thereafter by the deskew machine.  For setting X, the latency is 4*X to 4*X+4 UI.  Default is 16-20 UI.
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
#define     ei4_rx_pl_fir_errs_mask                               0x8000     //A 1 in this field indicates that a register or state machine parity error has occurred in per-group logic.
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
#define     ei4_rx_fifo_cntl_spare                                0x1000     //Spare to make cr happy.
#define     ei4_rx_fifo_cntl_spare_clear                          0xEFFF     // Clear mask

// ei4_rx_ber_status_pl Register field name                                 data value   Description
#define     ei4_rx_ber_count                                      0x0000     //Per-Lane (PL) Diagnostic Bit Error Rate (BER) error counter. Increments when in diagnostic BER mode AND the output of the descrambler is non-zero. This counter counts errors on every UI so it is a true BER counter.
#define     ei4_rx_ber_count_clear                                0x80FF     // Clear mask
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
#define     ei4_rx_eye_width_cntl_pl_spare                        0x4000     //RX Eye width control spare
#define     ei4_rx_eye_width_cntl_pl_spare_clear                  0xBFFF     // Clear mask

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

// ei4_rx_recal_mode_pg Register field name                                 data value   Description
#define     ei4_rx_recal_disable                                  0x8000     //TBD
#define     ei4_rx_recal_disable_clear                            0x7FFF     // Clear mask

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

// ei4_rx_minikerf_pg Register field name                                   data value   Description
#define     ei4_rx_minikerf                                       0x0000     //Used to configure the rx Minikerf for analog characterization.
#define     ei4_rx_minikerf_clear                                 0x0000     // Clear mask

// ei4_rx_bist_cntl_pg Register field name                                  data value   Description
#define     ei4_rx_bist_en                                        0x8000     //TBD
#define     ei4_rx_bist_en_clear                                  0x7FFF     // Clear mask
#define     ei4_rx_bist_jitter_pulse_ctl                          0x0000     //TBD
#define     ei4_rx_bist_jitter_pulse_ctl_clear                    0x9FFF     // Clear mask
#define     ei4_rx_bist_min_eye_width                             0x0000     //TBD
#define     ei4_rx_bist_min_eye_width_clear                       0xE03F     // Clear mask

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
#define     ei4_rx_start_bist_helper_1                            0x0200     //Starts BIST helper state machine.   (wtbyp
#define     ei4_rx_start_bist_helper_2                            0x0400     //Starts BIST helper state machine.   (ocal
#define     ei4_rx_start_bist_helper_3                            0x0600     //Starts BIST helper state machine.   (bist
#define     ei4_rx_start_bist_helper_clear                        0xF9FF     // Clear mask

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
#define     ei4_rx_bist_helper_done                               0x0400     //When this bit is read as a 1, the BIST helper state machine has completed.
#define     ei4_rx_bist_helper_done_clear                         0xFBFF     // Clear mask
#define     ei4_rx_wiretest_failed                                0x0080     //When this bit is read as a 1, the wiretest training state encountered an error.
#define     ei4_rx_wiretest_failed_clear                          0xFF7F     // Clear mask
#define     ei4_rx_deskew_failed                                  0x0040     //When this bit is read as a 1, the deskew training state encountered an error.
#define     ei4_rx_deskew_failed_clear                            0xFFBF     // Clear mask
#define     ei4_rx_eye_opt_failed                                 0x0020     //When this bit is read as a 1, the eye optimization training state encountered an error.
#define     ei4_rx_eye_opt_failed_clear                           0xFFDF     // Clear mask
#define     ei4_rx_repair_failed                                  0x0010     //When this bit is read as a 1, the static lane repair training state encountered an error.
#define     ei4_rx_repair_failed_clear                            0xFFEF     // Clear mask
#define     ei4_rx_func_mode_failed                               0x0008     //When this bit is read as a 1, the transition to functional data training state encountered and error.
#define     ei4_rx_func_mode_failed_clear                         0xFFF7     // Clear mask

// ei4_rx_recal_status_pg Register field name                               data value   Description
#define     ei4_rx_recal_status                                   0x0000     //\bRX Recalibration Status\b
#define     ei4_rx_recal_status_clear                             0x0000     // Clear mask

// ei4_rx_timeout_sel_pg Register field name                                data value   Description
#define     ei4_rx_sls_timeout_sel_tap1                           0x2000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  64k UI 
#define     ei4_rx_sls_timeout_sel_tap2                           0x4000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  128k UI 
#define     ei4_rx_sls_timeout_sel_tap3                           0x6000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  256k UI 
#define     ei4_rx_sls_timeout_sel_tap4                           0x8000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  512k UI 
#define     ei4_rx_sls_timeout_sel_tap5                           0xA000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  1024k UI 
#define     ei4_rx_sls_timeout_sel_tap6                           0xC000     //Selects Spare Lane Signalling Timeout value (how long to wait for a SLS handshake command)  32768k UI 
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

// ei4_rx_state_debug_pg Register field name                                data value   Description
#define     ei4_rx_start_at_state_en                              0x8000     //Enable Statemachine to Start
#define     ei4_rx_start_at_state_en_clear                        0x7FFF     // Clear mask
#define     ei4_rx_stop_at_state_en                               0x4000     //Enable Statemachine to Stop
#define     ei4_rx_stop_at_state_en_clear                         0xBFFF     // Clear mask
#define     ei4_rx_state_stopped                                  0x2000     //Statemachine Has Stopped at ei4_rx_STOP_STATE
#define     ei4_rx_state_stopped_clear                            0xDFFF     // Clear mask
#define     ei4_rx_cur_state                                      0x0000     //Current Value of Statemachine Vector
#define     ei4_rx_cur_state_clear                                0xE01F     // Clear mask

// ei4_rx_state_val_pg Register field name                                  data value   Description
#define     ei4_rx_start_state                                    0x0000     //Start Value for Statemachine
#define     ei4_rx_start_state_clear                              0x00FF     // Clear mask
#define     ei4_rx_stop_state                                     0x0000     //Stop Value for Statemachine
#define     ei4_rx_stop_state_clear                               0xFF00     // Clear mask

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

// ei4_rx_prot_mode_pg Register field name                                  data value   Description
#define     ei4_rx_reverse_shift                                  0x8000     //RX Phase Rotator Direction
#define     ei4_rx_reverse_shift_clear                            0x7FFF     // Clear mask

// ei4_rx_fir1_pg Register field name                                       data value   Description
#define     ei4_rx_pg_fir1_errs_clear                             0x0003     // Clear mask
#define     ei4_rx_pl_fir_err                                     0x0001     //Summary bit indicating an RX per-lane register or state machine parity error has occurred in one or more lanes. The ei4_rx_fir_pl register from each lane should be read to isolate to a particular piece of logic. There is no mechanism to determine which lane had the fault without reading FIR status from each lane.
#define     ei4_rx_pl_fir_err_clear                               0xFFFE     // Clear mask

// ei4_rx_fir2_pg Register field name                                       data value   Description
#define     ei4_rx_pg_fir2_errs_clear                             0x1FFF     // Clear mask

// ei4_rx_fir1_mask_pg Register field name                                  data value   Description
#define     ei4_rx_pg_fir1_errs_mask_clear                        0x0003     // Clear mask
#define     ei4_rx_pg_chan_fail_mask                              0x0002     //FIR mask for generation of channel fail error when Max Spares Exceeded is active. Default is disabled with a value of 1.
#define     ei4_rx_pg_chan_fail_mask_clear                        0xFFFD     // Clear mask
#define     ei4_rx_pl_fir_err_mask                                0x0001     //FIR mask for the summary bit that indicates an RX register or state machine parity error has occurred. This mask bit is used to block ALL per-lane parity errors from causing a FIR error.
#define     ei4_rx_pl_fir_err_mask_clear                          0xFFFE     // Clear mask

// ei4_rx_fir2_mask_pg Register field name                                  data value   Description
#define     ei4_rx_pg_fir2_errs_mask_clear                        0x1FFF     // Clear mask

// ei4_rx_fir1_error_inject_pg Register field name                          data value   Description
#define     ei4_rx_pg_fir1_err_inj_inj_par_err                    0x4000     //RX Per-Group Parity Error Injection  Causes a parity flip in the specific parity checker.
#define     ei4_rx_pg_fir1_err_inj_clear                          0x0003     // Clear mask

// ei4_rx_fir2_error_inject_pg Register field name                          data value   Description
#define     ei4_rx_pg_fir2_err_inj_inj_par_err                    0x2000     //RX Per-Group Parity Error Injection  Causes a parity flip in the specific parity checker.
#define     ei4_rx_pg_fir2_err_inj_clear                          0x1FFF     // Clear mask

// ei4_rx_fir_training_pg Register field name                               data value   Description
#define     ei4_rx_pg_fir_training_error                          0x8000     //A Training Error has occurred. The Training Error FFDC registers should be read to help isolate to a particular piece of logic.
#define     ei4_rx_pg_fir_training_error_clear                    0x7FFF     // Clear mask
#define     ei4_rx_pg_fir_static_spare_deployed                   0x4000     //A spare lane has been deployed during training to heal a lane that was detected as bad. The ei4_rx_bad_lane_enc_gcrmsg_pg register can be read to isolate which lane(s) were healed
#define     ei4_rx_pg_fir_static_spare_deployed_clear             0xBFFF     // Clear mask
#define     ei4_rx_pg_fir_static_max_spares_exceeded              0x2000     //A lane has been detected as bad during training but there are no spare lanes to heal it. THIS IS A CATASTROPHIC FAILURE FOR THE BUS.
#define     ei4_rx_pg_fir_static_max_spares_exceeded_clear        0xDFFF     // Clear mask
#define     ei4_rx_pg_fir_dynamic_spare_deployed                  0x1000     //A spare lane has been deployed by ECC/CRC logic to heal a lane that was detected as bad. The ei4_rx_bad_lane_enc_gcrmsg_pg register can be read to isolate which lane(s) were healed.
#define     ei4_rx_pg_fir_dynamic_spare_deployed_clear            0xEFFF     // Clear mask
#define     ei4_rx_pg_fir_dynamic_max_spares_exceeded             0x0800     //A lane has been detected as bad by ECC/CRC logic but there are no spare lanes to heal it. THIS IS A CATASTROPHIC FAILURE FOR THE BUS.
#define     ei4_rx_pg_fir_dynamic_max_spares_exceeded_clear       0xF7FF     // Clear mask
#define     ei4_rx_pg_fir_recal_error                             0x0400     //A Recalibration Error has occurred. The Recal Error FFDC registers should be read to help isolate to a particular piece of logic.
#define     ei4_rx_pg_fir_recal_error_clear                       0xFBFF     // Clear mask
#define     ei4_rx_pg_fir_recal_spare_deployed                    0x0200     //A spare lane has been deployed during Recal to heal a lane that was detected as bad. The ei4_rx_bad_lane_enc_gcrmsg_pg register can be read to isolate which lane(s) were healed.
#define     ei4_rx_pg_fir_recal_spare_deployed_clear              0xFDFF     // Clear mask
#define     ei4_rx_pg_fir_recal_max_spares_exceeded               0x0100     //A lane has been detected as bad during Recal but there are no spare lanes to heal it. THIS IS A CATASTROPHIC FAILURE FOR THE BUS.
#define     ei4_rx_pg_fir_recal_max_spares_exceeded_clear         0xFEFF     // Clear mask

// ei4_rx_fir_training_mask_pg Register field name                          data value   Description
#define     ei4_rx_pg_fir_training_error_mask                     0x8000     //FIR mask for ei4_rx_pg_fir_training_error.
#define     ei4_rx_pg_fir_training_error_mask_clear               0x7FFF     // Clear mask
#define     ei4_rx_pg_fir_static_spare_deployed_mask              0x4000     //FIR mask for ei4_rx_pg_fir_static_spare_deployed.
#define     ei4_rx_pg_fir_static_spare_deployed_mask_clear        0xBFFF     // Clear mask
#define     ei4_rx_pg_fir_static_max_spares_exceeded_mask         0x2000     //FIR mask for ei4_rx_pg_fir_static_max_spares_exceeded
#define     ei4_rx_pg_fir_static_max_spares_exceeded_mask_clear   0xDFFF     // Clear mask
#define     ei4_rx_pg_fir_dynamic_spare_deployed_mask             0x1000     //FIR mask for ei4_rx_pg_fir_dynamic_spare_deployed.
#define     ei4_rx_pg_fir_dynamic_spare_deployed_mask_clear       0xEFFF     // Clear mask
#define     ei4_rx_pg_fir_dynamic_max_spares_exceeded_mask        0x0800     //FIR mask for ei4_rx_pg_fir_dynamic_max_spares_exceeded.
#define     ei4_rx_pg_fir_dynamic_max_spares_exceeded_mask_clear  0xF7FF     // Clear mask
#define     ei4_rx_pg_fir_recal_error_mask                        0x0400     //FIR mask for ei4_rx_pg_fir_recal_error.
#define     ei4_rx_pg_fir_recal_error_mask_clear                  0xFBFF     // Clear mask
#define     ei4_rx_pg_fir_recal_spare_deployed_mask               0x0200     //FIR mask for ei4_rx_pg_fir_recal_spare_deployed.
#define     ei4_rx_pg_fir_recal_spare_deployed_mask_clear         0xFDFF     // Clear mask
#define     ei4_rx_pg_fir_recal_max_spares_exceeded_mask          0x0100     //FIR mask for ei4_rx_pg_fir_recal_max_spares_exceeded.
#define     ei4_rx_pg_fir_recal_max_spares_exceeded_mask_clear    0xFEFF     // Clear mask

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
#define     ei4_rx_lane_bad_vec_0_15                              0x0000     //Lanes found bad by HW (status) or method to force lane bad from software (control).
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
#define     ei4_rx_term_p_mode_enc                                0x0000     //Slice enable for 240ohm pfet for termination mode (binary code - 0000 is zero slices and 1000 is maximum slices)
#define     ei4_rx_term_p_mode_enc_clear                          0xF0FF     // Clear mask
#define     ei4_rx_term_test_mode                                 0x0080     //Termination Segment Test mode
#define     ei4_rx_term_test_mode_clear                           0xFF7F     // Clear mask

// ei4_rx_timeout_sel2_pg Register field name                               data value   Description
#define     ei4_rx_func_mode_timeout_sel_tap1                     0x2000     //Selects Functional Mode wait timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   128k UI or 13.7us 
#define     ei4_rx_func_mode_timeout_sel_tap2                     0x4000     //Selects Functional Mode wait timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   256k UI or 27.3us 
#define     ei4_rx_func_mode_timeout_sel_tap3                     0x6000     //Selects Functional Mode wait timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   512k UI or 54.6us 
#define     ei4_rx_func_mode_timeout_sel_tap4                     0x8000     //Selects Functional Mode wait timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   1M UI or 109.2us 
#define     ei4_rx_func_mode_timeout_sel_tap5                     0xA000     //Selects Functional Mode wait timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   2M UI or 218.5us 
#define     ei4_rx_func_mode_timeout_sel_tap6                     0xC000     //Selects Functional Mode wait timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   64M UI or 7ms
#define     ei4_rx_func_mode_timeout_sel_tap7                     0xE000     //Selects Functional Mode wait timeout. Note that his should be longer than ei4_rx_sls_timeout_sel.   infinite
#define     ei4_rx_func_mode_timeout_sel_clear                    0x1FFF     // Clear mask

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

// ei4_rx_dyn_rpr_err_tallying_pg Register field name                       data value   Description
#define     ei4_rx_dyn_rpr_bad_lane_max                           0x0000     //CRC/ECC Dynamic Repair: Max number of times a lane can be found bad before repaired
#define     ei4_rx_dyn_rpr_bad_lane_max_clear                     0x07FF     // Clear mask
#define     ei4_rx_dyn_rpr_err_cntr_duration_tap1                 0x0100     //CRC/ECC Dynamic Repair: Duration the error counter can run before being cleared (determines the allowed error frequency)  106.6ns
#define     ei4_rx_dyn_rpr_err_cntr_duration_tap2                 0x0200     //CRC/ECC Dynamic Repair: Duration the error counter can run before being cleared (determines the allowed error frequency)  1.7uS
#define     ei4_rx_dyn_rpr_err_cntr_duration_tap3                 0x0300     //CRC/ECC Dynamic Repair: Duration the error counter can run before being cleared (determines the allowed error frequency)  27.3uS
#define     ei4_rx_dyn_rpr_err_cntr_duration_tap4                 0x0400     //CRC/ECC Dynamic Repair: Duration the error counter can run before being cleared (determines the allowed error frequency)  436.7uS
#define     ei4_rx_dyn_rpr_err_cntr_duration_tap5                 0x0500     //CRC/ECC Dynamic Repair: Duration the error counter can run before being cleared (determines the allowed error frequency)  7.0mS
#define     ei4_rx_dyn_rpr_err_cntr_duration_tap6                 0x0600     //CRC/ECC Dynamic Repair: Duration the error counter can run before being cleared (determines the allowed error frequency)  111.8mS
#define     ei4_rx_dyn_rpr_err_cntr_duration_tap7                 0x0700     //CRC/ECC Dynamic Repair: Duration the error counter can run before being cleared (determines the allowed error frequency)  1.8S
#define     ei4_rx_dyn_rpr_err_cntr_duration_clear                0xF8FF     // Clear mask
#define     ei4_rx_dyn_rpr_clr_err_cntr                           0x0080     //CRC/ECC Dynamic Repair: Firmware-based clear of error counter register
#define     ei4_rx_dyn_rpr_clr_err_cntr_clear                     0xFF7F     // Clear mask

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
#define     ei4_rx_wt_cu_pll_pgood                                0x8000     //RX cleanup PLL Enable
#define     ei4_rx_wt_cu_pll_pgood_clear                          0x7FFF     // Clear mask
#define     ei4_rx_wt_cu_pll_reset                                0x4000     //RX cleanup PLL Enable Request
#define     ei4_rx_wt_cu_pll_reset_clear                          0xBFFF     // Clear mask
#define     ei4_rx_wt_cu_pll_pgooddly_50ns                        0x0800     //RX cleanup PLL PGOOD Delay Selects length of reset period after ei4_rx_wt_cu_pll_reset is set.   Nominal 50ns Reset per PLL Spec 
#define     ei4_rx_wt_cu_pll_pgooddly_100ns                       0x1000     //RX cleanup PLL PGOOD Delay Selects length of reset period after ei4_rx_wt_cu_pll_reset is set.   Double Nominal 50ns Reset per PLL Spec 
#define     ei4_rx_wt_cu_pll_pgooddly_960ui                       0x1800     //RX cleanup PLL PGOOD Delay Selects length of reset period after ei4_rx_wt_cu_pll_reset is set.   Typical simulation delay exceeding TX PLL 40-refclk locking period 
#define     ei4_rx_wt_cu_pll_pgooddly_unused_100                  0x2000     //RX cleanup PLL PGOOD Delay Selects length of reset period after ei4_rx_wt_cu_pll_reset is set.   Reserved 
#define     ei4_rx_wt_cu_pll_pgooddly_unused_101                  0x2800     //RX cleanup PLL PGOOD Delay Selects length of reset period after ei4_rx_wt_cu_pll_reset is set.   Reserved 
#define     ei4_rx_wt_cu_pll_pgooddly_MAX                         0x3000     //RX cleanup PLL PGOOD Delay Selects length of reset period after ei4_rx_wt_cu_pll_reset is set.   1024 UI  
#define     ei4_rx_wt_cu_pll_pgooddly_disable                     0x3800     //RX cleanup PLL PGOOD Delay Selects length of reset period after ei4_rx_wt_cu_pll_reset is set.   Disable ei4_rx_wt_cu_pll_reset
#define     ei4_rx_wt_cu_pll_pgooddly_clear                       0xC7FF     // Clear mask
#define     ei4_rx_wt_cu_pll_lock                                 0x0400     //RX cleanup PLL Locked
#define     ei4_rx_wt_cu_pll_lock_clear                           0xFBFF     // Clear mask

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

// ei4_rx_eo_step_fail_pg Register field name                               data value   Description
#define     ei4_rx_eo_latch_offset_failed                         0x8000     //RX eye optimization latch offset adjustment  failed
#define     ei4_rx_eo_latch_offset_failed_clear                   0x7FFF     // Clear mask
#define     ei4_rx_eo_ctle_failed                                 0x4000     //RX eye optimization CTLE/Peaking  failed
#define     ei4_rx_eo_ctle_failed_clear                           0xBFFF     // Clear mask
#define     ei4_rx_eo_vref_failed                                 0x1000     //RX eye optimization VRef adjust  failed
#define     ei4_rx_eo_vref_failed_clear                           0xEFFF     // Clear mask
#define     ei4_rx_eo_measure_eye_width_failed                    0x0100     //RX eye optimization Measure eye width filed
#define     ei4_rx_eo_measure_eye_width_failed_clear              0xFEFF     // Clear mask
#define     ei4_rx_eo_final_l2u_adj_failed                        0x0080     //RX eye optimization Final RX FIFO load-to-unload adjust  failed
#define     ei4_rx_eo_final_l2u_adj_failed_clear                  0xFF7F     // Clear mask

// ei4_rx_amp_val_pg Register field name                                    data value   Description
#define     ei4_rx_amp_peak_work                                  0x0000     //Rx amp peak working register
#define     ei4_rx_amp_peak_work_clear                            0x0FFF     // Clear mask

// ei4_rx_sls_rcvy_pg Register field name                                   data value   Description
#define     ei4_rx_sls_rcvy_state_clear                           0xE0FF     // Clear mask

// ei4_rx_sls_rcvy_gcrmsg_pg Register field name                            data value   Description
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
#define     ei4_rx_sls_rcvy_ei4_rx_ip_gcrmsg                          0x0020     //GCR Message: SLS Rcvy; RX Lane Repair IP
#define     ei4_rx_sls_rcvy_ei4_rx_ip_gcrmsg_clear                    0xFFDF     // Clear mask
#define     ei4_rx_sls_rcvy_ei4_rx_rpred_gcrmsg                       0x0010     //GCR Message: SLS Rcvy; RX Lane Repair Done
#define     ei4_rx_sls_rcvy_ei4_rx_rpred_gcrmsg_clear                 0xFFEF     // Clear mask

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
#define     ei4_rx_trc_mode_tap5                                  0x5000     //RX Trace Mode  CRC/ECC Tallying Logic
#define     ei4_rx_trc_mode_tap6                                  0x6000     //RX Trace Mode  RX SLS Commands
#define     ei4_rx_trc_mode_tap7                                  0x7000     //RX Trace Mode  RX Bad Lanes
#define     ei4_rx_trc_mode_tap8                                  0x8000     //RX Trace Mode  RX SLS Lanes
#define     ei4_rx_trc_mode_tap9                                  0x9000     //RX Trace Mode  TBD
#define     ei4_rx_trc_mode_tap10                                 0xA000     //RX Trace Mode  TBD
#define     ei4_rx_trc_mode_tap11                                 0xB000     //RX Trace Mode  TBD
#define     ei4_rx_trc_mode_tap12                                 0xC000     //RX Trace Mode  TBD
#define     ei4_rx_trc_mode_tap13                                 0xD000     //RX Trace Mode  TBD
#define     ei4_rx_trc_mode_tap14                                 0xE000     //RX Trace Mode  TBD
#define     ei4_rx_trc_mode_tap15                                 0xF000     //RX Trace Mode  TBD
#define     ei4_rx_trc_mode_clear                                 0x0FFF     // Clear mask
#define     ei4_rx_trc_grp_clear                                  0xFC0F     // Clear mask

// ei4_rx_wiretest_pp Register field name                                   data value   Description
#define     ei4_rx_wt_pattern_length_256                          0x4000     //RX Wiretest Pattern Length  256
#define     ei4_rx_wt_pattern_length_512                          0x8000     //RX Wiretest Pattern Length  512
#define     ei4_rx_wt_pattern_length_1024                         0xC000     //RX Wiretest Pattern Length  1024
#define     ei4_rx_wt_pattern_length_clear                        0x3FFF     // Clear mask

// ei4_rx_mode_pp Register field name                                       data value   Description
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


#endif
