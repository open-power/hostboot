/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_pcie_scominit/proc_pcie_scominit.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// $Id: proc_pcie_scominit.H,v 1.5 2013/10/11 14:54:22 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_pcie_scominit.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
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
#include "p8_scom_addresses.H"

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// SCOM initfile to execute
const char * const PROC_PCIE_SCOMINIT_PHASE1_IF = "p8.pe.phase1.scom.if";

// PCIe physical constants
const uint8_t PROC_PCIE_SCOMINIT_NUM_IOP = 2;
const uint8_t PROC_PCIE_SCOMINIT_NUM_PHB = 3;

// PCIe GP0 register field/bit definitions
const uint32_t PCIE_GP0_PHB_IOVALID_BIT[PROC_PCIE_SCOMINIT_NUM_PHB] =
{
    48,
    49,
    50
};

const uint32_t PCIE_GP0_PHB_REFCLOCK_DRIVE_EN_BIT[PROC_PCIE_SCOMINIT_NUM_PHB] =
{
    52,
    53,
    54
};

// PCIe GP4 register field/bit definitions
const uint32_t PCIE_GP4_IOP_RESET_BIT[PROC_PCIE_SCOMINIT_NUM_IOP] =
{
    37,
    38
};
const uint32_t PCIE_GP4_IOP_LANE_CFG_START_BIT = 41;
const uint32_t PCIE_GP4_IOP_LANE_CFG_END_BIT = 44;
const uint32_t PCIE_GP4_IOP_SWAP_START_BIT[PROC_PCIE_SCOMINIT_NUM_IOP] =
{
    47,
    53
};
const uint32_t PCIE_GP4_IOP_SWAP_END_BIT[PROC_PCIE_SCOMINIT_NUM_IOP] =
{
    49,
    55
};

// Murano/Venice support lane configurations bewtween 0x0 & 0xC,
// swap values between 0x0 & 0x7
const uint8_t PCIE_GP4_IOP_LANE_CFG_MAX = 0xC;
const uint8_t PCIE_GP4_IOP_SWAP_MAX = 0x7;


// PCIe PLL Global Control Register 2 field/bit definitions
const uint64_t PROC_PCIE_SCOMINIT_PLL_GLOBAL_CONTROL2[PROC_PCIE_SCOMINIT_NUM_IOP] =
{
    PCIE_IOP0_PLL_GLOBAL_CONTROL2_0x8000080A0901143F,
    PCIE_IOP1_PLL_GLOBAL_CONTROL2_0x8000080A0901187F
};
const uint32_t PLL_GLOBAL_CONTROL2_PROG_COMPLETE_BIT = 50;

// PCIe PLL FIR register field/bit definitions
const uint32_t PROC_PCIE_SCOMINIT_PLL_FIR[PROC_PCIE_SCOMINIT_NUM_IOP] =
{
    PCIE_IOP0_PLL_FIR_0x09011400,
    PCIE_IOP1_PLL_FIR_0x09011840
};

const uint32_t PROC_PCIE_SCOMINIT_PLL_FIR_WOF[PROC_PCIE_SCOMINIT_NUM_IOP] =
{
    PCIE_IOP0_PLL_FIR_WOF_0x09011408,
    PCIE_IOP1_PLL_FIR_WOF_0x09011848
};

const uint32_t PROC_PCIE_SCOMINIT_PLL_FIR_MASK[PROC_PCIE_SCOMINIT_NUM_IOP] =
{
    PCIE_IOP0_PLL_FIR_MASK_0x09011403,
    PCIE_IOP1_PLL_FIR_MASK_0x09011843
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
