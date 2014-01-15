/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/proc_pcie_config/proc_pcie_config.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: proc_pcie_config.H,v 1.2 2014/01/13 18:21:59 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_pcie_config.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
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
#include "p8_scom_addresses.H"

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// SCOM initfile to execute
const char * const PROC_PCIE_CONFIG_PHASE2_IF = "p8.pe.phase2.scom.if";

// PCIe physical constants
const uint8_t PROC_PCIE_CONFIG_NUM_PHB = 3;

const uint32_t PROC_PCIE_CONFIG_PCIE_NEST_FIR[PROC_PCIE_CONFIG_NUM_PHB] =
{
    PCIE0_FIR_0x02012000,
    PCIE1_FIR_0x02012400,
    PCIE2_FIR_0x02012800
};

const uint32_t PROC_PCIE_CONFIG_PCIE_NEST_FIR_WOF[PROC_PCIE_CONFIG_NUM_PHB] =
{
    PCIE0_FIR_WOF_0x02012008,
    PCIE1_FIR_WOF_0x02012408,
    PCIE2_FIR_WOF_0x02012808
};

const uint32_t PROC_PCIE_CONFIG_PCIE_NEST_FIR_ACTION0[PROC_PCIE_CONFIG_NUM_PHB] =
{
    PCIE0_FIR_ACTION0_0x02012006,
    PCIE1_FIR_ACTION0_0x02012406,
    PCIE2_FIR_ACTION0_0x02012806
};

const uint32_t PROC_PCIE_CONFIG_PCIE_NEST_FIR_ACTION1[PROC_PCIE_CONFIG_NUM_PHB] =
{
    PCIE0_FIR_ACTION1_0x02012007,
    PCIE1_FIR_ACTION1_0x02012407,
    PCIE2_FIR_ACTION1_0x02012807
};

const uint32_t PROC_PCIE_CONFIG_PCIE_NEST_FIR_MASK[PROC_PCIE_CONFIG_NUM_PHB] =
{
    PCIE0_FIR_MASK_0x02012003,
    PCIE1_FIR_MASK_0x02012403,
    PCIE2_FIR_MASK_0x02012803
};

const uint64_t PROC_PCIE_CONFIG_PCIE_NEST_FIR_ACTION0_VAL = 0x5B8F819000000000ULL;
const uint64_t PROC_PCIE_CONFIG_PCIE_NEST_FIR_ACTION1_VAL = 0x7F8F819000000000ULL;
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
