/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_pcbs_firinit.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: p8_pm_pcbs_firinit.H,v 1.5 2013/08/26 12:44:36 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_pcbs_firinit.H,v $
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


#include "p8_pm_firinit.H"

const uint32_t        PCB_FIR_REGISTER_LENGTH = 43 ;
enum PCB_FIRS
{
    PCBS_SLEEP_ENTRY_NOTIFY_PMC_HANG_ERR_MASK                   = 0,
    PCBS_SLEEP_ENTRY_NOTIFY_PMC_ASSIST_HANG_ERR_MASK            = 1,
    PCBS_SLEEP_ENTRY_NOTIFY_PMC_ERR_MASK                        = 2,
    PCBS_SLEEP_EXIT_INVOKE_PORE_ERR_MASK                        = 3,
    PCBS_WINKLE_ENTRY_NOTIFY_PMC_ERR_MASK                       = 4,
    PCBS_WINKLE_ENTRY_SEND_INT_ASSIST_ERR_MASK                  = 5,
    PCBS_WINKLE_EXIT_NOTIFY_PMC_ERR_MASK                        = 6,
    PCBS_WAIT_DPLL_LOCK_ERR_MASK                                = 7,
    PCBS_SPARE8_ERR_MASK                                        = 8,
    PCBS_WINKLE_EXIT_SEND_INT_ASSIST_ERR_MASK                   = 9,
    PCBS_WINKLE_EXIT_SEND_INT_POWUP_ASSIST_ERR_MASK             = 10,
    PCBS_WRITE_FSM_GOTO_REG_IN_INVALID_STATE_ERR_MASK           = 11,
    PCBS_WRITE_PMGP0_IN_INVALID_STATE_ERR_MASK                  = 12,
    PCBS_FREQ_OVERFLOW_IN_PSTATE_MODE_ERR_MASK                  = 13,
    PCBS_ECO_RS_BYPASS_CONFUSION_ERR_MASK                       = 14,
    PCBS_CORE_RS_BYPASS_CONFUSION_ERR_MASK                      = 15,
    PCBS_READ_LPST_IN_PSTATE_MODE_ERR_MASK                      = 16,
    PCBS_LPST_READ_CORR_ERR_MASK                                = 17,
    PCBS_LPST_READ_UNCORR_ERR_MASK                              = 18,
    PCBS_PFET_STRENGTH_OVERFLOW_ERR_MASK                        = 19,
    PCBS_VDS_LOOKUP_ERR_MASK                                    = 20,
    PCBS_IDLE_INTERRUPT_TIMEOUT_ERR_MASK                        = 21,
    PCBS_PSTATE_INTERRUPT_TIMEOUT_ERR_MASK                      = 22,
    PCBS_GLOBAL_ACTUAL_SYNC_INTERRUPT_TIMEOUT_ERR_MASK          = 23,
    PCBS_PMAX_SYNC_INTERRUPT_TIMEOUT_ERR_MASK                   = 24,
    PCBS_GLOBAL_ACTUAL_PSTATE_PROTOCOL_ERR_MASK                 = 25,
    PCBS_PMAX_PROTOCOL_ERR_MASK                                 = 26,
    PCBS_IVRM_GROSS_OR_FINE_ERR_MASK                            = 27,
    PCBS_IVRM_RANGE_ERR_MASK                                    = 28,
    PCBS_DPLL_CPM_FMIN_ERR_MASK                                 = 29,
    PCBS_DPLL_DCO_FULL_ERR_MASK                                 = 30,
    PCBS_DPLL_DCO_EMPTY_ERR_MASK                                = 31,
    PCBS_DPLL_INT_ERR_MASK                                      = 32,
    PCBS_FMIN_AND_NOT_CPMBIT_ERR_MASK                           = 33,
    PCBS_DPLL_FASTER_THAN_FMAX_PLUS_DELTA1_ERR_MASK             = 34,
    PCBS_DPLL_SLOWER_THAN_FMIN_MINUS_DELTA2_ERR_MASK            = 35,
    PCBS_RESCLK_CSB_INSTR_VECTOR_CHG_IN_INVALID_STATE_ERR_MASK  = 36,
    PCBS_RESLKC_BAND_BOUNDARY_CHG_IN_INVALID_STATE_ERR_MASK     = 37,
    PCBS_OCC_HEARTBEAT_LOSS_ERR_MASK                            = 38,
    PCBS_SPARE39_ERR_MASK                                       = 39,
    PCBS_SPARE40_ERR_MASK                                       = 40,
    PCBS_SPARE41_ERR_MASK                                       = 41,
    PCBS_SPARE42_ERR_MASK                                       = 42
};

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pm_pcbs_firinit_FP_t) (const fapi::Target& , uint32_t mode  );


extern "C" {

/// \param[in]      &i_target           Chip target

fapi::ReturnCode  p8_pm_pcbs_firinit(const fapi::Target& i_target , uint32_t mode  );


} // extern "C"


