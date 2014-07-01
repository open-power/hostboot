/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pcbs_init.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
// $Id: p8_pcbs_init.H,v 1.4 2013/04/12 01:32:01 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pcbs_init.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Ralf Maier         Email: ralf.maier@de.ibm.com
// *!
// *!   The purpose of this procedure is to establish the safe setting for PCBSLV
// *!   o set psafe value
// *!   o set PMIN clip/Pmax clip
// *!   o PMCR default values
// *!   o PMICR default values
// *!
// *!  include file for pcbs_init with constants, definitions, prototypes
// *!
//------------------------------------------------------------------------------

#ifndef _P8_PCBSINIT_H_
#define _P8_PCBSINIT_H_

/// \todo : PSAFE, PUV_MIN, PUV_MAX - Attributes defined as uint8 but should be int8
typedef struct {
    uint8_t     ivrms_enabled;          // ATTR_IVRMS_ENABLED
    uint8_t     PSAFE;                  // ATTR_SAFE_PSTATE PSAFE
    uint8_t     PUV_MIN;                // ATTR_PSTATE_UNDERVOLTING_MINIMUM
    uint8_t     PUV_MAX;                // ATTR_PSTATE_UNDERVOLTING_MAXIMUM
    uint32_t    MAX_PSAFE_FSM_LOOPS;    // max number of times PCBS-PMSR has been checked
    uint32_t    MAX_DELAY;              // max number of Delay
    uint32_t    MAX_SIM_CYCLES;         // max number of SimCycles (will be used when FSP is target)
    char        GLOBAL_ACTUAL_PSTATE;   // Global Actual PSTATE
    char        MIN_PSTATE;             //
    char        FNOM;                   //
    char        DPLL_FMIN;              //
    char        DPLL_FMAX;              //
    char        PMIN_CLIP;              //
    char        PMAX_CLIP;              //
    char        KUV;                    //
} struct_pcbs_val_init_type;


// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pcbs_init_FP_t) (const fapi::Target&, uint32_t);

extern "C" {

/// \param[in]      &i_target           Chip target
/// \param[in]      mode                Mode 1:    CONFIG-Mode
///                                     Mode 2:    RESET-Mode
///                                     Mode 3:    INIT-Mode

fapi::ReturnCode p8_pcbs_init (const fapi::Target& i_target, uint32_t mode);

} // extern "C"

#endif // _P8_PCBSINIT_H_
