/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_setup.H $ */
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
// $Id: proc_a_x_pci_dmi_pll_setup.H,v 1.6 2014/03/27 17:58:11 bgeukes Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_a_x_pci_dmi_pll_setup.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_a_x_pci_dmi_pll_setup.H
// *! DESCRIPTION : Initialize and lock A/X/PCI/DMI PLLs
// *!
// *! OWNER NAME  : Ralph Koester            Email: rkoester@de.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_A_X_PCI_DMI_PLL_SETUP_H_
#define _PROC_A_X_PCI_DMI_PLL_SETUP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>

//-----
// Constant Definitions
//

CONST_UINT64_T( PERV_PLL_LOCK_ERROR_INDICATION_0x010F001F    , ULL(0x010F001F) );
CONST_UINT64_T( NEST_PLL_LOCK_ERROR_INDICATION_0x020F001F    , ULL(0x020F001F) );
CONST_UINT64_T( ABUS_PLL_LOCK_ERROR_INDICATION_0x080F001F    , ULL(0x080F001F) );
CONST_UINT64_T( PCI_PLL_LOCK_ERROR_INDICATION_0x090F001F    , ULL(0x090F001F) );

CONST_UINT64_T( PERV_PLL_LOCK_MASK_0x010F001E    , ULL(0x010F001E) );
CONST_UINT64_T( NEST_PLL_LOCK_MASK_0x020F001E    , ULL(0x020F001E) );
CONST_UINT64_T( ABUS_PLL_LOCK_MASK_0x080F001E    , ULL(0x080F001E) );
CONST_UINT64_T( PCI_PLL_LOCK_MASK_0x090F001E    , ULL(0x090F001E) );


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_a_x_pci_dmi_pll_setup_FP_t)(const fapi::Target &,
                           const bool, const bool, const bool, const bool);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

/**
 * @brief Initialize and lock A/X/PCI/DMI PLLs
 *
 * @param[in] i_target     Reference to target
 * @param[in] i_startX     True if x_bus PLL should be started, else false
 * @param[in] i_startA     True if A PLL should be started, else false
 * @param[in] i_startPCIE  True if PCIE PLL should be started, else false
 * @param[in] i_startDMI   True if DMI PLL should be started, else false
 *
 * @return ReturnCode
 */
  fapi::ReturnCode proc_a_x_pci_dmi_pll_setup(const fapi::Target & i_target,
                                   const bool i_startX,
                                   const bool i_startA,
                                   const bool i_startPCIE,
                                   const bool i_startDMI);

} // extern "C"

#endif // _PROC_A_X_PCI_DMI_PLL_SETUP_H_
