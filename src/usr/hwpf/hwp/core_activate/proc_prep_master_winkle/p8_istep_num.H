/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/proc_prep_master_winkle/p8_istep_num.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __P8_ISTEP_NUM_H
#define __P8_ISTEP_NUM_H

// $Id: p8_istep_num.H,v 1.16 2012/09/14 21:11:54 mfred Exp $

/// Istep number encoding for all SEEPROM and PNOR procedures.  Used to update
/// the SBEVITAL register to record procedure progress and to create unique
/// hooki bind points on procedure completion.

CONST_UINT64_T(proc_sbe_enable_seeprom_istep_num,           ULL(0x0101));

CONST_UINT64_T(proc_sbe_tp_chiplet_init1_istep_num,         ULL(0x0201));
CONST_UINT64_T(proc_sbe_tp_ld_image_istep_num,              ULL(0x0202));
CONST_UINT64_T(proc_sbe_nest_skewadjust_istep_num,          ULL(0x0203));
CONST_UINT64_T(proc_sbe_npll_initf_istep_num,               ULL(0x0204));
CONST_UINT64_T(proc_sbe_npll_setup_istep_num,               ULL(0x0205));
CONST_UINT64_T(proc_sbe_tp_switch_gears_istep_num,          ULL(0x0206));
CONST_UINT64_T(proc_sbe_tp_chiplet_init2_istep_num,         ULL(0x0207));
CONST_UINT64_T(proc_sbe_tp_arrayinit_istep_num,             ULL(0x0208));
CONST_UINT64_T(proc_sbe_tp_chiplet_init3_istep_num,         ULL(0x0209));
CONST_UINT64_T(proc_sbe_chiplet_init_istep_num,             ULL(0x020A));
CONST_UINT64_T(proc_sbe_arrayinit_istep_num,                ULL(0x020B));
CONST_UINT64_T(proc_sbe_setup_evid_istep_num,               ULL(0x020C));
CONST_UINT64_T(proc_sbe_initf_istep_num,                    ULL(0x020D));
CONST_UINT64_T(proc_sbe_pb_startclocks_istep_num,           ULL(0x020E));
CONST_UINT64_T(proc_sbe_scominit_istep_num,                 ULL(0x020F));
CONST_UINT64_T(proc_sbe_fabricinit_istep_num,               ULL(0x0210));
CONST_UINT64_T(proc_sbe_check_master_istep_num,             ULL(0x0211));
CONST_UINT64_T(proc_sbe_select_ex_istep_num,                ULL(0x0212));
CONST_UINT64_T(proc_sbe_run_exinit_istep_num,               ULL(0x0213));

CONST_UINT64_T(proc_sbe_pnor_setup_istep_num,               ULL(0x0301));

CONST_UINT64_T(proc_sbe_ex_chiplet_reset_istep_num,         ULL(0x0401));
CONST_UINT64_T(proc_sbe_ex_gptr_time_initf_istep_num,       ULL(0x0402));
CONST_UINT64_T(proc_sbe_ex_core_gptr_time_initf_istep_num,  ULL(0x0403));
CONST_UINT64_T(proc_sbe_ex_dpll_initf_istep_num,            ULL(0x0404));
CONST_UINT64_T(proc_sbe_ex_dpll_setup_istep_num,            ULL(0x0405));
CONST_UINT64_T(proc_sbe_ex_chiplet_init_istep_num,          ULL(0x0406));
CONST_UINT64_T(proc_sbe_ex_repair_initf_istep_num,          ULL(0x0407));
CONST_UINT64_T(proc_sbe_ex_core_repair_initf_istep_num,     ULL(0x0408));
CONST_UINT64_T(proc_sbe_ex_arrayinit_istep_num,             ULL(0x0409));
CONST_UINT64_T(proc_sbe_ex_initf_istep_num,                 ULL(0x040A));
CONST_UINT64_T(proc_sbe_ex_core_initf_istep_num,            ULL(0x040B));
CONST_UINT64_T(proc_sbe_ex_do_manual_inits_istep_num,       ULL(0x040C));
CONST_UINT64_T(proc_sbe_ex_startclocks_istep_num,           ULL(0x040D));
CONST_UINT64_T(proc_sbe_ex_init_escape_istep_num,           ULL(0x040E));
CONST_UINT64_T(proc_sbe_ex_sp_runtime_scom_istep_num,       ULL(0x040F));
CONST_UINT64_T(proc_sbe_ex_occ_runtime_scom_istep_num,      ULL(0x0410));
CONST_UINT64_T(proc_sbe_ex_host_runtime_scom_istep_num,     ULL(0x0411));

CONST_UINT64_T(proc_sbe_enable_pnor_istep_num,              ULL(0x0500));
CONST_UINT64_T(proc_sbe_lco_loader_istep_num,               ULL(0x0501));
CONST_UINT64_T(proc_sbe_instruct_start_istep_num,           ULL(0x0502));

CONST_UINT64_T(proc_sbe_trigger_winkle_istep_num,           ULL(0x0F01));

#define PROC_SBE_TRIGGER_WINKLE_ISTEP_NUM proc_sbe_trigger_winkle_istep_num
#define PROC_SBE_CHECK_MASTER_ISTEP_NUM proc_sbe_check_master_istep_num

#endif  // __P8_ISTEP_NUM_H
