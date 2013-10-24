/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_initf.H $ */
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
// $Id: proc_a_x_pci_dmi_pll_initf.H,v 1.4 2013/09/30 16:09:57 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_a_x_pci_dmi_pll_initf.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_a_x_pci_dmi_pll_initf.H
// *! DESCRIPTION : Scan PLL settings for A/X/PCI/DMI PLLs
// *!
// *! OWNER NAME  : Ralph Koester            Email: rkoester@de.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_A_X_PCI_DMI_PLL_INITF_H_
#define _PROC_A_X_PCI_DMI_PLL_INITF_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_a_x_pci_dmi_pll_initf_FP_t)(const fapi::Target &,
                           const bool, const bool, const bool, const bool);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

/**
 * @brief Scan PLL settings for A/X/PCI/DMI PLLs
 *
 * @param[in] i_target     Reference to target
 * @param[in] i_startX     True if x_bus PLL should be initalized, else false
 * @param[in] i_startA     True if A PLL should be initalized, else false
 * @param[in] i_startPCIE  True if PCIE PLL should be initalized, else false
 * @param[in] i_startDMI   True if DMI PLL should be initalized, else false
 *
 * @return ReturnCode
 */
  fapi::ReturnCode proc_a_x_pci_dmi_pll_initf(const fapi::Target & i_target,
                                   const bool i_startX,
                                   const bool i_startA,
                                   const bool i_startPCIE,
                                   const bool i_startDMI);

} // extern "C"

#endif // _PROC_A_X_PCI_DMI_PLL_INITF_H_
