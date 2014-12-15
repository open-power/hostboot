/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/proc_pcie_config/proc_pcie_config.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
// $Id: proc_pcie_config.H,v 1.5 2014/11/18 17:41:59 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_pcie_config.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_pcie_config.H
// *! DESCRIPTION : Perform PCIe PBCQ/AIB Inits (Phase 2, Steps 9-22) (FAPI)
// *!
// *! OWNER NAME  : Joe McGill        Email: jmcgill@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!   Configure PBCQ/AIB registers
// *!   Clear PBCQ FIRs, setup for runtime
// *!
//------------------------------------------------------------------------------

#ifndef PROC_PCIE_CONFIG_H_
#define PROC_PCIE_CONFIG_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>
#include <p8_scom_addresses.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// SCOM initfile to execute
const char * const PROC_PCIE_CONFIG_PHASE2_IF = "p8.pe.phase2.scom.if";

// PCIe physical constants
const uint8_t PROC_PCIE_CONFIG_NUM_PHB = 4;

const uint32_t PROC_PCIE_CONFIG_PCIE_NEST_FIR[PROC_PCIE_CONFIG_NUM_PHB] =
{
    PCIE0_FIR_0x02012000,
    PCIE1_FIR_0x02012400,
    PCIE2_FIR_0x02012800,
    PCIE3_FIR_0x02012C00
};

const uint32_t PROC_PCIE_CONFIG_PCIE_NEST_FIR_WOF[PROC_PCIE_CONFIG_NUM_PHB] =
{
    PCIE0_FIR_WOF_0x02012008,
    PCIE1_FIR_WOF_0x02012408,
    PCIE2_FIR_WOF_0x02012808,
    PCIE3_FIR_WOF_0x02012C08
};

const uint32_t PROC_PCIE_CONFIG_PCIE_NEST_FIR_ACTION0[PROC_PCIE_CONFIG_NUM_PHB] =
{
    PCIE0_FIR_ACTION0_0x02012006,
    PCIE1_FIR_ACTION0_0x02012406,
    PCIE2_FIR_ACTION0_0x02012806,
    PCIE3_FIR_ACTION0_0x02012C06
};

const uint32_t PROC_PCIE_CONFIG_PCIE_NEST_FIR_ACTION1[PROC_PCIE_CONFIG_NUM_PHB] =
{
    PCIE0_FIR_ACTION1_0x02012007,
    PCIE1_FIR_ACTION1_0x02012407,
    PCIE2_FIR_ACTION1_0x02012807,
    PCIE3_FIR_ACTION1_0x02012C07
};

const uint32_t PROC_PCIE_CONFIG_PCIE_NEST_FIR_MASK[PROC_PCIE_CONFIG_NUM_PHB] =
{
    PCIE0_FIR_MASK_0x02012003,
    PCIE1_FIR_MASK_0x02012403,
    PCIE2_FIR_MASK_0x02012803,
    PCIE3_FIR_MASK_0x02012C03
};

const uint64_t PROC_PCIE_CONFIG_PCIE_NEST_FIR_ACTION0_VAL = 0x5B0F819000000000ULL;
const uint64_t PROC_PCIE_CONFIG_PCIE_NEST_FIR_ACTION1_VAL = 0x7F0F819000000000ULL;
const uint64_t PROC_PCIE_CONFIG_PCIE_NEST_FIR_MASK_VAL = 0x0030006E00000000ULL;


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_pcie_config_FP_t)(const fapi::Target & i_target);

extern "C" {

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: perform PCIe PBCQ/AIB Inits (Phase 2, Steps 9-22)
// parameters: i_target => processor chip target
// returns: FAPI_RC_SUCCESS if all programming is successful,
//          RC_PROC_PCIE_CONFIG_INVALID_TARGET if invalid target is supplied,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_pcie_config(const fapi::Target & i_target);


} // extern "C"

#endif // PROC_PCIE_CONFIG_H_
