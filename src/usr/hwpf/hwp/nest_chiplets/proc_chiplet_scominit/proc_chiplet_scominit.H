/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_chiplet_scominit/proc_chiplet_scominit.H $ */
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
// $Id: proc_chiplet_scominit.H,v 1.15 2013/11/09 21:06:39 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_chiplet_scominit.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_chiplet_scominit.H
// *! DESCRIPTION : Invoke initfiles for proc_chiplet_scominit istep (FAPI)
// *!
// *! OWNER NAME  : Mike Jones        Email: mjjones@us.ibm.com
// *! BACKUP NAME : Joe McGill        Email: jmcgill@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

#ifndef PROC_CHIPLET_SCOMINIT_H_
#define PROC_CHIPLET_SCOMINIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

const char * const PROC_CHIPLET_SCOMINIT_FBC_IF         = "p8.fbc.scom.if";
const char * const PROC_CHIPLET_SCOMINIT_PSI_IF         = "p8.psi.scom.if";
const char * const PROC_CHIPLET_SCOMINIT_TPBRIDGE_IF    = "p8.tpbridge.scom.if";
const char * const PROC_CHIPLET_SCOMINIT_NX_IF          = "p8.nx.scom.if";
const char * const PROC_CHIPLET_SCOMINIT_AS_IF          = "p8.as.scom.if";
const char * const PROC_CHIPLET_SCOMINIT_CXA_IF         = "p8.cxa.scom.if";
const char * const PROC_CHIPLET_SCOMINIT_A_X_PCI_DMI_IF = "p8.a_x_pci_dmi_fir.scom.if";
const char * const PROC_CHIPLET_SCOMINIT_MCS_IF         = "p8.mcs.scom.if";


// FSI GP6 Register field/bit definitions
const uint32_t MBOX_FSIGP6_XBUS_RESONANT_CLOCK_CONFIG_START_BIT = 0;
const uint32_t MBOX_FSIGP6_XBUS_RESONANT_CLOCK_CONFIG_END_BIT   = 15;

const uint16_t XBUS_RESONANT_CLOCK_CONFIG = 0xF180;

// MCS Mode0 Register field/bit definitions
const uint32_t MCSMODE0_EN_CENTAUR_SYNC_BIT = 61;

// CAPP APC Master LCO Target Register field/bit definitions
const uint32_t CAPP_APC_MASTER_LCO_TARGET_MIN_START_BIT = 13;
const uint32_t CAPP_APC_MASTER_LCO_TARGET_MIN_END_BIT = 15;


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_chiplet_scominit_FP_t)(const fapi::Target & i_target);

extern "C" {

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

/**
 * @brief HWP which invokes initfiles for proc_chiplet_scominit istep
 *
 * Should be called with all functional proc chips. It invokes initfiles
 * on chiplets.
 *
 * @param[in] i_target Reference to target
 *                     If TARGET_TYPE_PROC_CHIP, calls:
 *                     - p8.fbc.scom.initfile
 *                     - p8.psi.scom.initfile
 *                     - p8.tpbridge.scom.initfile
 *                     - p8.nx.scom.initfile
 *                     - p8.cxa.scom.initfile
 *                     - p8.a_x_pci_dmi_fir.scom.initfile
 *                     - p8.as.scom.initfile
 *                     - p8.mcs.scom.initfile for each functional MCS chiplet
 *
 * @return ReturnCode
 */
fapi::ReturnCode proc_chiplet_scominit(const fapi::Target & i_target);


} // extern "C"

#endif // PROC_CHIPLET_SCOMINIT_H_
