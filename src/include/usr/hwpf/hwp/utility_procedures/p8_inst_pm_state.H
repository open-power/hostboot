/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/utility_procedures/p8_inst_pm_state.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
// $Id: p8_inst_pm_state.H,v 1.7 2014/06/19 14:38:44 cmolsen Exp $
//------------------------------------------------------------------------------
//  Title:  p8_inst_pm_state.H
//  Description:  Contains definitions needed for calculating the
//                Instantaneous PM State (IPMS).
//------------------------------------------------------------------------------

#ifndef _P8_INST_PM_STATE_H_
#define _P8_INST_PM_STATE_H_

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------

#include <fapi.H>
#include <vector>

//------------------------------------------------------------------------------
// Defines
//------------------------------------------------------------------------------

// The following enum list must start at 0x00 and must increment by 0x01.
// They are used as index to INST_PM_STATE_NAMES[INST_PM_STATE_xyz].
enum  INSTANTANEOUS_IDLE_STATES
{
    INST_PM_STATE_FS_ENTRY           = 0x00,
    INST_PM_STATE_DS_ENTRY           = 0x01,
    INST_PM_STATE_FS_EXIT            = 0x02,
    INST_PM_STATE_DS_EXIT            = 0x03,
    INST_PM_STATE_FW_ENTRY           = 0x04,
    INST_PM_STATE_DW_ENTRY           = 0x05,
    INST_PM_STATE_FW_EXIT            = 0x06,
    INST_PM_STATE_DW_EXIT            = 0x07,
    INST_PM_STATE_NAP_ENTRY          = 0x08,
    INST_PM_STATE_NAP_EXIT           = 0x09,
    INST_PM_STATE_RUN                = 0x0a,
    INST_PM_STATE_RUN_OHA_ENTRY      = 0x0b,
    INST_PM_STATE_PCBS_ANY_ENTRY     = 0x0c,  // Was not queued
    INST_PM_STATE_PCBS_FS_EXIT       = 0x0d,  // Was not queued
    INST_PM_STATE_PCBS_DS_EXIT       = 0x0e,  // Was not queued
    INST_PM_STATE_PCBS_FW_EXIT       = 0x0f,  // Was not queued
    INST_PM_STATE_PCBS_DW_EXIT       = 0x10,  // Was not queued
    INST_PM_STATE_QUEUED_FS_ENTRY    = 0x11,  // Incl PMC-stuck state
    INST_PM_STATE_QUEUED_DS_ENTRY    = 0x12,  // Incl PMC-stuck state
    INST_PM_STATE_QUEUED_FS_EXIT     = 0x13,  // Incl PMC-stuck state
    INST_PM_STATE_QUEUED_DS_EXIT     = 0x14,  // Incl PMC-stuck state
    INST_PM_STATE_QUEUED_FW_ENTRY    = 0x15,  // Incl PMC-stuck state
    INST_PM_STATE_QUEUED_DW_ENTRY    = 0x16,  // Incl PMC-stuck state
    INST_PM_STATE_QUEUED_FW_EXIT     = 0x17,  // Incl PMC-stuck state
    INST_PM_STATE_QUEUED_DW_EXIT     = 0x18,  // Incl PMC-stuck state
    INST_PM_STATE_SPECIAL_WAKEUP     = 0x19,
    INST_PM_STATE_NAP_STATIC         = 0x1a,
    INST_PM_STATE_FS_STATIC          = 0x1b,
    INST_PM_STATE_DS_STATIC          = 0x1c,
    INST_PM_STATE_FW_STATIC          = 0x1d,
    INST_PM_STATE_DW_STATIC          = 0x1e,
    INST_PM_STATE_UNRESOLVED         = 0x1f,  // Final state, if no other valid state found
    INST_PM_STATE_UNDEFINED          = 0x20,  // Initialized state
    INST_PM_STATE_LAST_ENTRY         = 0x21
};
// The following strings must precisely match the above enum INSTANTANEOUS_IDLE_STATES.
const char * const INST_PM_STATE_NAMES[INST_PM_STATE_LAST_ENTRY] =
{
    "FAST_SLEEP_ENTRY",
    "DEEP_SLEEP_ENTRY",
    "FAST_SLEEP_EXIT",
    "DEEP_SLEEP_EXIT",
    "FAST_WINKLE_ENTRY",
    "DEEP_WINKLE_ENTRY",
    "FAST_WINKLE_EXIT",
    "DEEP_WINKLE_EXIT",
    "NAP_ENTRY",
    "NAP_EXIT",
    "RUN",
    "RUN_OHA_ENTRY",
    "PCBS_ANY_ENTRY",
    "PCBS_FAST_SLEEP_EXIT",
    "PCBS_DEEP_SLEEP_EXIT",
    "PCBS_FAST_WINKLE_EXIT",
    "PCBS_DEEP_WINKLE_EXIT",
    "QUEUED_FAST_SLEEP_ENTRY",
    "QUEUED_DEEP_SLEEP_ENTRY",
    "QUEUED_FAST_SLEEP_EXIT",
    "QUEUED_DEEP_SLEEP_EXIT",
    "QUEUED_FAST_WINKLE_ENTRY",
    "QUEUED_DEEP_WINKLE_ENTRY",
    "QUEUED_FAST_WINKLE_EXIT",
    "QUEUED_DEEP_WINKLE_EXIT",
    "SPECIAL_WAKEUP",
    "NAP_STATIC",
    "FAST_SLEEP_STATIC",
    "DEEP_SLEEP_STATIC",
    "FAST_WINKLE_STATIC",
    "DEEP_WINKLE_STATIC",
    "UNRESOLVED",
    "UNDEFINED"
};


enum  PCBS_FSM_STATES
{
    PCBS_FSM_IDLE             = 0x00, // "IDLE" means idling here. Not PM idle.
    PCBS_FSM_ANY_IDLE_ENTRY   = 0x2e,
    PCBS_FSM_ANY_SLEEP_EXIT   = 0x50,
    PCBS_FSM_ANY_WINKLE_EXIT  = 0x51,
    PCBS_FSM_DEEP_WINKLE_EXIT = 0x57
};

enum  PORRR_START_VECTOR
{
    PORRR_SV_FS_ENTRY   = 0x00,
    PORRR_SV_DS_ENTRY   = 0x01,
    PORRR_SV_FS_EXIT    = 0x02,
    PORRR_SV_DS_EXIT    = 0x03,
    PORRR_SV_FW_ENTRY   = 0x04,
    PORRR_SV_DW_ENTRY   = 0x05,
    PORRR_SV_FW_EXIT    = 0x06,
    PORRR_SV_DW_EXIT    = 0x07,
    PORRR_SV_NAP_ENTRY  = 0x08,
    PORRR_SV_NAP_EXIT   = 0x09
};


// The following enum list must start at 0x00 and must increment by 0x01.
// They are used as index to PMHIST_STATE_NAMES[PMHIST_STATE_xyz].
enum PMHIST_STATES
{
    PMHIST_STATE_RUN             = 0x0,
    PMHIST_STATE_SPECIAL_WAKEUP  = 0x1,
    PMHIST_STATE_NAP             = 0x2,
    PMHIST_STATE_LEGACY_SLEEP    = 0x3,
    PMHIST_STATE_FAST_SLEEP      = 0x4,
    PMHIST_STATE_DEEP_SLEEP      = 0x5,
    PMHIST_STATE_FAST_WINKLE     = 0x6,
    PMHIST_STATE_DEEP_WINKLE     = 0x7
};
// The following strings must precisely match the above enum PMHIST_STATES.
const char * const PMHIST_STATE_NAMES[8] =
{
    "RUN",
    "SPECIAL_WAKEUP",
    "NAP",
    "LEGACY_SLEEP",
    "FAST_SLEEP",
    "DEEP_SLEEP",
    "FAST_WINKLE",
    "DEEP_WINKLE"
};

// PIRRx masks and meanings
const uint32_t PMC_QUEUE_PENDING_MASK       = 0x00000080;
const uint32_t PMC_QUEUE_OP_TYPE_SCOPE_MASK = 0x00000078; 
const uint32_t PMC_QUEUE_ASSIST_MASK        = 0x00000004;
const uint32_t PMC_QUEUE_NAP_ENTRY          = 0x00000020; 
const uint32_t PMC_QUEUE_NAP_EXIT           = 0x00000030; 
const uint32_t PMC_QUEUE_FS_ENTRY           = 0x00000040; 
const uint32_t PMC_QUEUE_DS_ENTRY           = 0x00000048; 
const uint32_t PMC_QUEUE_FS_EXIT            = 0x00000050; 
const uint32_t PMC_QUEUE_DS_EXIT            = 0x00000058; 
const uint32_t PMC_QUEUE_FW_ENTRY           = 0x00000060; 
const uint32_t PMC_QUEUE_DW_ENTRY           = 0x00000068; 
const uint32_t PMC_QUEUE_FW_EXIT            = 0x00000070; 
const uint32_t PMC_QUEUE_DW_EXIT            = 0x00000078; 
 


extern "C"
{

// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------

// Determines Instantaneous PM State (IPMS).
fapi::ReturnCode ex_determine_inst_pm_state(    const fapi::Target &i_ex_target,
                                                uint32_t  i_pm_settle_usec,
                                                uint32_t  i_pm_polls,
                                                uint8_t   &o_inst_pm_state);
// Determines IPMS from the PM HIST reg state.
fapi::ReturnCode ex_determine_ipms_from_pmhist( const fapi::Target &i_ex_target,
                                                uint32_t  i_pmhist_state, 
                                                uint8_t   &o_inst_pm_state,
                                                bool      &o_bGoodState);
// Determines IPMS from the PMC PIRRx registers.
fapi::ReturnCode ex_determine_ipms_from_pirrx(  const fapi::Target &i_ex_target, 
                                                uint32_t  i_pcbs_fsm,
                                                uint32_t  i_pmc_queue_state,
                                                uint8_t   &o_inst_pm_state,
                                                bool      &o_bGoodState);
}


#endif
