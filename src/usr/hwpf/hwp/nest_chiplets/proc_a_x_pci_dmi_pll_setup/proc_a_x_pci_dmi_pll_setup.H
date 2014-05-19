/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_setup.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: proc_a_x_pci_dmi_pll_setup.H,v 1.7 2014/04/02 14:02:33 jmcgill Exp $
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
