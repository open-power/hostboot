/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_pcbs_firinit.H $    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
/* begin_generated_IBM_copyright_prolog                            */
/*                                                                 */
/* This is an automatically generated copyright prolog.            */
/* After initializing,  DO NOT MODIFY OR MOVE                      */ 
/* --------------------------------------------------------------- */
/* IBM Confidential                                                */
/*                                                                 */
/* Licensed Internal Code Source Materials                         */
/*                                                                 */
/* (C)Copyright IBM Corp.  2014, 2014                              */
/*                                                                 */
/* The Source code for this program is not published  or otherwise */
/* divested of its trade secrets,  irrespective of what has been   */
/* deposited with the U.S. Copyright Office.                       */
/*  -------------------------------------------------------------- */
/*                                                                 */
/* end_generated_IBM_copyright_prolog                              */
// $Id: p8_pm_pcbs_firinit.H,v 1.2 2012/09/19 09:55:21 rmaier Exp $
// $Source: /afs/awd.austin.ibm.com/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_pcbs_firinit.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_pm_pcbs_firinit.H
// *! DESCRIPTION : Configures the PCBS FIR errors
// *!
// *! OWNER NAME  : Ralf Maier    Email: ralf.maier@de.ibm.com
// *! BACKUP NAME : Pradeep CN    Email: padeepcn@in.ibm.com
// *!
//------------------------------------------------------------------------------



// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pm_pcbs_firinit_FP_t) (const fapi::Target&  );



// 0x010A  PM Error Mask Register  
// pm_reg.pm_error_mask_lt 0..42   PCB      
// 0       RW      pcbs_sleep_entry_notify_pmc_hang_err_mask                    Mask for this error: 1=masked, 0=not masked
// 1       RW      pcbs_sleep_entry_notify_pmc_assist_hang_err_mask             Mask for this error: 1=masked, 0=not masked
// 2       RW      pcbs_sleep_entry_notify_pmc_err_mask                         Mask for this error: 1=masked, 0=not masked
// 3       RW      pcbs_sleep_exit_invoke_pore_err_mask                         Mask for this error: 1=masked, 0=not masked
// 4       RW      pcbs_winkle_entry_notify_pmc_err_mask                        Mask for this error: 1=masked, 0=not masked
// 5       RW      pcbs_winkle_entry_send_int_assist_err_mask                   Mask for this error: 1=masked, 0=not masked
// 6       RW      pcbs_winkle_exit_notify_pmc_err_mask                         Mask for this error: 1=masked, 0=not masked
// 7       RW      pcbs_wait_dpll_lock_err_mask                                 Mask for this error: 1=masked, 0=not masked
// 8       RW      pcbs_spare8_err_mask                                         Mask for this error: 1=masked, 0=not masked
// 9       RW      pcbs_winkle_exit_send_int_assist_err_mask                    Mask for this error: 1=masked, 0=not masked
// 10      RW      pcbs_winkle_exit_send_int_powup_assist_err_mask              Mask for this error: 1=masked, 0=not masked
// 11      RW      pcbs_write_fsm_goto_reg_in_invalid_state_err_mask            Mask for this error: 1=masked, 0=not masked
// 12      RW      pcbs_write_pmgp0_in_invalid_state_err_mask                   Mask for this error: 1=masked, 0=not masked
// 13      RW      pcbs_freq_overflow_in_pstate_mode_err_mask                   Mask for this error: 1=masked, 0=not masked
// 14      RW      pcbs_eco_rs_bypass_confusion_err_mask                        Mask for this error: 1=masked, 0=not masked
// 15      RW      pcbs_core_rs_bypass_confusion_err_mask                       Mask for this error: 1=masked, 0=not masked
// 16      RW      pcbs_read_lpst_in_pstate_mode_err_mask                       Mask for this error: 1=masked, 0=not masked
// 17      RW      pcbs_lpst_read_corr_err_mask                                 Mask for this error: 1=masked, 0=not masked
// 18      RW      pcbs_lpst_read_uncorr_err_mask                               Mask for this error: 1=masked, 0=not masked
// 19      RW      pcbs_pfet_strength_overflow_err_mask                         Mask for this error: 1=masked, 0=not masked
// 20      RW      pcbs_vds_lookup_err_mask                                     Mask for this error: 1=masked, 0=not masked
// 21      RW      pcbs_idle_interrupt_timeout_err_mask                         Mask for this error: 1=masked, 0=not masked
// 22      RW      pcbs_pstate_interrupt_timeout_err_mask                       Mask for this error: 1=masked, 0=not masked
// 23      RW      pcbs_global_actual_sync_interrupt_timeout_err_mask           Mask for this error: 1=masked, 0=not masked
// 24      RW      pcbs_pmax_sync_interrupt_timeout_err_mask                    Mask for this error: 1=masked, 0=not masked
// 25      RW      pcbs_global_actual_pstate_protocol_err_mask                  Mask for this error: 1=masked, 0=not masked
// 26      RW      pcbs_pmax_protocol_err_mask                                  Mask for this error: 1=masked, 0=not masked
// 27      RW      pcbs_ivrm_gross_or_fine_err_mask                             Mask for this error: 1=masked, 0=not masked
// 28      RW      pcbs_ivrm_range_err_mask                                     Mask for this error: 1=masked, 0=not masked
// 29      RW      pcbs_dpll_cpm_fmin_err_mask                                  Mask for this error: 1=masked, 0=not masked
// 30      RW      pcbs_dpll_dco_full_err_mask                                  Mask for this error: 1=masked, 0=not masked
// 31      RW      pcbs_dpll_dco_empty_err_mask                                 Mask for this error: 1=masked, 0=not masked
// 32      RW      pcbs_dpll_int_err_mask                                       Mask for this error: 1=masked, 0=not masked
// 33      RW      pcbs_fmin_and_not_cpmbit_err_mask                            Mask for this error: 1=masked, 0=not masked
// 34      RW      pcbs_dpll_faster_than_fmax_plus_delta1_err_mask              Mask for this error: 1=masked, 0=not masked
// 35      RW      pcbs_dpll_slower_than_fmin_minus_delta2_err_mask             Mask for this error: 1=masked, 0=not masked
// 36      RW      pcbs_resclk_csb_instr_vector_chg_in_invalid_state_err_mask   Mask for this error: 1=masked, 0=not masked
// 37      RW      pcbs_reslkc_band_boundary_chg_in_invalid_state_err_mask      Mask for this error: 1=masked, 0=not masked
// 38      RW      pcbs_occ_heartbeat_loss_err_mask                             Mask for this error: 1=masked, 0=not masked
// 39      RW      pcbs_spare39_err_mask                                        Mask for this error: 1=masked, 0=not masked
// 40      RW      pcbs_spare40_err_mask                                        Mask for this error: 1=masked, 0=not masked
// 41      RW      pcbs_spare41_err_mask                                        Mask for this error: 1=masked, 0=not masked
// 42      RW      pcbs_spare42_err_mask                                        Mask for this error: 1=masked, 0=not masked


enum
{
  PCBS_SLEEP_ENTRY_NOTIFY_PMC_HANG_ERR_MASK = 0,
  PCBS_SLEEP_ENTRY_NOTIFY_PMC_ASSIST_HANG_ERR_MASK = 1,
  PCBS_SLEEP_ENTRY_NOTIFY_PMC_ERR_MASK = 2,                         
  PCBS_SLEEP_EXIT_INVOKE_PORE_ERR_MASK = 3,                         
  PCBS_WINKLE_ENTRY_NOTIFY_PMC_ERR_MASK = 4,                        
  PCBS_WINKLE_ENTRY_SEND_INT_ASSIST_ERR_MASK = 5,                   
  PCBS_WINKLE_EXIT_NOTIFY_PMC_ERR_MASK = 6,                         
  PCBS_WAIT_DPLL_LOCK_ERR_MASK = 7,                                 
  PCBS_SPARE8_ERR_MASK = 8,                                         
  PCBS_WINKLE_EXIT_SEND_INT_ASSIST_ERR_MASK = 9,                    
  PCBS_WINKLE_EXIT_SEND_INT_POWUP_ASSIST_ERR_MASK = 10,              
  PCBS_WRITE_FSM_GOTO_REG_IN_INVALID_STATE_ERR_MASK = 11,            
  PCBS_WRITE_PMGP0_IN_INVALID_STATE_ERR_MASK = 12,                   
  PCBS_FREQ_OVERFLOW_IN_PSTATE_MODE_ERR_MASK = 13,                   
  PCBS_ECO_RS_BYPASS_CONFUSION_ERR_MASK = 14,                        
  PCBS_CORE_RS_BYPASS_CONFUSION_ERR_MASK = 15,                       
  PCBS_READ_LPST_IN_PSTATE_MODE_ERR_MASK = 16,                       
  PCBS_LPST_READ_CORR_ERR_MASK = 17,                                 
  PCBS_LPST_READ_UNCORR_ERR_MASK = 18,                               
  PCBS_PFET_STRENGTH_OVERFLOW_ERR_MASK = 19,                         
  PCBS_VDS_LOOKUP_ERR_MASK = 20,                                     
  PCBS_IDLE_INTERRUPT_TIMEOUT_ERR_MASK = 21,                         
  PCBS_PSTATE_INTERRUPT_TIMEOUT_ERR_MASK = 22,                       
  PCBS_GLOBAL_ACTUAL_SYNC_INTERRUPT_TIMEOUT_ERR_MASK = 23,           
  PCBS_PMAX_SYNC_INTERRUPT_TIMEOUT_ERR_MASK = 24,                    
  PCBS_GLOBAL_ACTUAL_PSTATE_PROTOCOL_ERR_MASK = 25,                  
  PCBS_PMAX_PROTOCOL_ERR_MASK = 26,                                  
  PCBS_IVRM_GROSS_OR_FINE_ERR_MASK = 27,                             
  PCBS_IVRM_RANGE_ERR_MASK = 28,                                     
  PCBS_DPLL_CPM_FMIN_ERR_MASK = 29,                                  
  PCBS_DPLL_DCO_FULL_ERR_MASK = 30,                                  
  PCBS_DPLL_DCO_EMPTY_ERR_MASK = 31,                                 
  PCBS_DPLL_INT_ERR_MASK = 32,                                       
  PCBS_FMIN_AND_NOT_CPMBIT_ERR_MASK = 33,                            
  PCBS_DPLL_FASTER_THAN_FMAX_PLUS_DELTA1_ERR_MASK = 34,              
  PCBS_DPLL_SLOWER_THAN_FMIN_MINUS_DELTA2_ERR_MASK = 35,             
  PCBS_RESCLK_CSB_INSTR_VECTOR_CHG_IN_INVALID_STATE_ERR_MASK = 36,   
  PCBS_RESLKC_BAND_BOUNDARY_CHG_IN_INVALID_STATE_ERR_MASK = 37,      
  PCBS_OCC_HEARTBEAT_LOSS_ERR_MASK = 38,                             
  PCBS_SPARE39_ERR_MASK = 39,                                        
  PCBS_SPARE40_ERR_MASK = 40,                                        
  PCBS_SPARE41_ERR_MASK = 41,                                        
  PCBS_SPARE42_ERR_MASK = 42              
} ;




extern "C" {

/// \param[in]      &i_target           Chip target
 
fapi::ReturnCode  p8_pm_pcbs_firinit(const fapi::Target& i_target );


} // extern "C"


