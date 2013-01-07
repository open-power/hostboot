/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_start_clocks_chiplets/proc_start_clocks_chiplets.H $ */
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
// $Id: proc_start_clocks_chiplets.H,v 1.5 2012/12/07 18:15:17 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_start_clocks_chiplets.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ****
// *|
// *! TITLE       : proc_start_clocks_chiplets.H
// *! DESCRIPTION : Start X/A/PCIE chiplet clocks (FAPI)
// *!
// *! OWNER NAME  : Ralph Koester           Email: rkoester@de.ibm.com
// *! BACKUP NAME : Gebhard Weber           Email: gweber@de.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
// *! The purpose of this procedure is to start the clocks for X/A/PCIe chiplets
// *! Reference: FW specification: 7.3, PRV POR specification spreadsheet
// *!    - Start Xbus, ABus, PCIe clocks
// *!    - Drop fences
// *!
// *! Prerequisites: proc_a_x_pci_pll_setup
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_START_CLOCKS_CHIPLETS_H_
#define _PROC_START_CLOCKS_CHIPLETS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>
#include "p8_scom_addresses.H"

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_start_clocks_chiplets_FP_t)(const fapi::Target&, bool, bool, bool);

extern "C" {

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// GP3 register bit/field definitions
const uint8_t GP3_FENCE_EN_BIT = 18;

// GP0 register bit/field definitions
const uint8_t GP0_ABSTCLK_MUXSEL_BIT    = 0;
const uint8_t GP0_SYNCCLK_MUXSEL_BIT    = 1;
const uint8_t GP0_FLUSHMODE_INHIBIT_BIT = 2;
const uint8_t GP0_FORCE_ALIGN_BIT       = 3;
const uint8_t GP0_PERV_FENCE_BIT        = 63;

// Clock Region Register clock start data patterns
const uint64_t PROC_START_CLOCKS_CHIPLETS_CLK_REGION_REG_START_NSL_ARY = 0x4FE0060000000000ull;
const uint64_t PROC_START_CLOCKS_CHIPLETS_CLK_REGION_REG_START_ALL = 0x4FE00E0000000000ull;

// Chiplet FIR register expected pattern
const uint64_t PROC_START_CLOCKS_CHIPLETS_CHIPLET_FIR_REG_EXP = 0x0000000000000000ull;


// Input clock region vector mask (for bit manipulation of clock regions)
const uint64_t PROC_START_CLOCKS_CHIPLETS_CLOCK_REGION_MANIPULATION = 0xF0000FFFFFFFFFFFull;


//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

// function: FAPI proc_start_clocks_chiplets  HWP entry point
//           start clocks for X/A/PCIE chiplets
// parameters: i_target => P8 chip target
//             i_xbus   => start X chiplet clocks?
//             i_abus   => start A chiplet clocks?
//             i_pcie   => start PCIE chiplet clocks?
// returns: FAPI_RC_SUCCESS if clock start sequence completes successfully
//          else FAPI getscom/putscom return code for failing operation
fapi::ReturnCode proc_start_clocks_chiplets(const fapi::Target& i_target,
                                            bool i_xbus,
                                            bool i_abus,
                                            bool i_pcie);

} // extern "C"

#endif // _PROC_START_CLOCKS_CHIPLETS_H_
