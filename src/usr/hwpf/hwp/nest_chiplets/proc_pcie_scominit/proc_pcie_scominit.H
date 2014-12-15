/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_pcie_scominit/proc_pcie_scominit.H $ */
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
// $Id: proc_pcie_scominit.H,v 1.7 2014/11/18 17:38:50 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_pcie_scominit.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_pcie_scominit.H
// *! DESCRIPTION : Perform PCIe Physical IO Inits (Phase 1, Steps 1-9 &
// *!               Phase 2, Step 33) (FAPI)
// *!
// *! OWNER NAME  : Joe McGill        Email: jmcgill@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!   Set IOP lane config/swap bits
// *!   Set iovalid for active PHBs
// *!   Remove active IOPs from reset
// *!   Perform IOP overrides/customization
// *!   Mark IOP programming complete
// *!
//------------------------------------------------------------------------------

#ifndef PROC_PCIE_SCOMINIT_H_
#define PROC_PCIE_SCOMINIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>
#include <p8_scom_addresses.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// SCOM initfile to execute
const char * const PROC_PCIE_SCOMINIT_PHASE1_IF = "p8.pe.phase1.scom.if";

// PCIe physical constants
const uint8_t PROC_PCIE_SCOMINIT_NUM_IOP = 3;
const uint8_t PROC_PCIE_SCOMINIT_NUM_PHB = 4;

// PCIe GP0 register field/bit definitions
const uint32_t PCIE_GP0_PHB_IOVALID_BIT[PROC_PCIE_SCOMINIT_NUM_PHB] =
{
    48,
    49,
    50,
    51
};

const uint32_t PCIE_GP0_PHB_REFCLOCK_DRIVE_EN_BIT[PROC_PCIE_SCOMINIT_NUM_PHB] =
{
    52,
    53,
    54,
    55
};

// PCIe GP4 register field/bit definitions
const uint32_t PCIE_GP4_IOP_RESET_BIT[PROC_PCIE_SCOMINIT_NUM_IOP] =
{
    37,
    38,
    39
};
const uint32_t PCIE_GP4_IOP_LANE_CFG_START_BIT = 41;
const uint32_t PCIE_GP4_IOP_LANE_CFG_END_BIT = 44;
const uint32_t PCIE_GP4_IOP_SWAP_START_BIT[PROC_PCIE_SCOMINIT_NUM_IOP] =
{
    47,
    53,
    50
};
const uint32_t PCIE_GP4_IOP_SWAP_END_BIT[PROC_PCIE_SCOMINIT_NUM_IOP] =
{
    49,
    55,
    52
};

// Murano/Venice support lane configurations bewtween 0x0 & 0xC,
// swap values between 0x0 & 0x7
const uint8_t PCIE_GP4_IOP_LANE_CFG_MAX = 0xC;
const uint8_t PCIE_GP4_IOP_SWAP_MAX = 0x7;


// PCIe PLL Global Control Register 2 field/bit definitions
const uint64_t PROC_PCIE_SCOMINIT_PLL_GLOBAL_CONTROL2[PROC_PCIE_SCOMINIT_NUM_IOP] =
{
    PCIE_IOP0_PLL_GLOBAL_CONTROL2_0x8000080A0901143F,
    PCIE_IOP1_PLL_GLOBAL_CONTROL2_0x8000080A0901187F,
    PCIE_IOP2_PLL_GLOBAL_CONTROL2_0x8000080A09011C7F
};
const uint32_t PLL_GLOBAL_CONTROL2_PROG_COMPLETE_BIT = 50;

// PCIe PLL FIR register field/bit definitions
const uint32_t PROC_PCIE_SCOMINIT_PLL_FIR[PROC_PCIE_SCOMINIT_NUM_IOP] =
{
    PCIE_IOP0_PLL_FIR_0x09011400,
    PCIE_IOP1_PLL_FIR_0x09011840,
    PCIE_IOP2_PLL_FIR_0x09011C40
};

const uint32_t PROC_PCIE_SCOMINIT_PLL_FIR_WOF[PROC_PCIE_SCOMINIT_NUM_IOP] =
{
    PCIE_IOP0_PLL_FIR_WOF_0x09011408,
    PCIE_IOP1_PLL_FIR_WOF_0x09011848,
    PCIE_IOP2_PLL_FIR_WOF_0x09011C48
};

const uint32_t PROC_PCIE_SCOMINIT_PLL_FIR_MASK[PROC_PCIE_SCOMINIT_NUM_IOP] =
{
    PCIE_IOP0_PLL_FIR_MASK_0x09011403,
    PCIE_IOP1_PLL_FIR_MASK_0x09011843,
    PCIE_IOP2_PLL_FIR_MASK_0x09011C43
};

const uint64_t PCIE_PLL_FIR_MASK_VAL = 0x0080000000000000ULL;


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_pcie_scominit_FP_t)(const fapi::Target & i_target);

extern "C" {

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: perform PCIe Physical IO Inits (Phase 1, Steps 1-9)
// parameters: i_target => processor chip target
// returns: FAPI_RC_SUCCESS if all programming is successful,
//          RC_PROC_PCIE_SCOMINIT_IOP_CONFIG_ATTR_ERR if invalid IOP lane
//            configuration attribute value is presented,
//          RC_PROC_PCIE_SCOMINIT_IOP_SWAP_ATTR_ERR if invalid IOP swap
//            attribute value is presented,
//          RC_PROC_PCIE_SCOMINIT_INVALID_TARGET if invalid target is supplied,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_pcie_scominit(const fapi::Target & i_target);


} // extern "C"

#endif // PROC_PCIE_SCOMINIT_H_
