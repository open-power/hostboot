/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/proc_setup_bars/mss_setup_bars.H $ */
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
// $Id: mss_setup_bars.H,v 1.9 2014/04/08 16:04:12 gpaulraj Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *!
// *! TITLE       : mss_setup_bars.C
// *! DESCRIPTION : Program MCS base address registers (BARs) (FAPI)
// *!
// *! OWNER NAME  : Girisankar Paulraj      Email: gpaulraj@in.ibm.com
// *! OWNER NAME  : Mark Bellows            Email: bellows@us.ibm.com
// *!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.9    | gpaulraj | 04/08/14|  5/5 FW review feedback - gerrit process - SW251227
//  1.4    | jdsloat  | 03/13/14| changed const names to stop interfering with eff_grouping
//  1.3    | bellows  | 07/16/12| added in ID tag
//  1.1    | gpaulraj | 03/19/12| Updated
//------------------------------------------------------------------------------

#ifndef MSS_SETUP_BARS_H_
#define MSS_SETUP_BARS_H_

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

#include <fapi.H>
#include "p8_scom_addresses.H"


//------------------------------------------------------------------------------
//  Constant definitions
//------------------------------------------------------------------------------

// MCFGP bit/field definitions
const uint32_t MCFGP_VALID_BIT = 0;
const uint32_t MCFGP_MCS_UNITS_PER_GROUP_START_BIT = 1;
const uint32_t MCFGP_MCS_UNITS_PER_GROUP_END_BIT = 3;
const uint32_t MCFGP_GROUP_MEMBER_ID_START_BIT = 4;
const uint32_t MCFGP_GROUP_MEMBER_ID_END_BIT = 8;
const uint32_t MCFGP_ENABLE_RCMD0_BIT = 9;
const uint32_t MCFGP_ENABLE_RCMD1_BIT = 10;
const uint32_t MCFGP_GROUP_SIZE_START_BIT = 11;
const uint32_t MCFGP_GROUP_SIZE_END_BIT = 23;
const uint32_t MCFGP_RSVD_1_BIT = 24;
const uint32_t MCFGP_ENABLE_FASTPATH_BIT = 25;
const uint32_t MCFGP_BASE_ADDRESS_START_BIT = 26;
const uint32_t MCFGP_BASE_ADDRESS_END_BIT = 43;

// MCFGPA bit/field defintions
const uint32_t MCFGPA_VALID_BIT = 0;
const uint32_t MCFGPA_GROUP_SIZE_START_BIT = 11;
const uint32_t MCFGPA_GROUP_SIZE_END_BIT = 23;
const uint32_t MCFGPA_BASE_ADDRESS_START_BIT = 26;
const uint32_t MCFGPA_BASE_ADDRESS_END_BIT = 43;

// MCFGPM bit/field definitions
const uint32_t MCFGPM_VALID_BIT = 0;
const uint32_t MCFGPM_GROUP_SIZE_START_BIT = 11;
const uint32_t MCFGPM_GROUP_SIZE_END_BIT = 23;
const uint32_t MCFGPM_BASE_ADDRESS_START_BIT = 26;
const uint32_t MCFGPM_BASE_ADDRESS_END_BIT = 43;

// MCFGPMA bit/field definitions
const uint32_t MCFGPMA_VALID_BIT = 0;
const uint32_t MCFGPMA_GROUP_SIZE_START_BIT = 11;
const uint32_t MCFGPMA_GROUP_SIZE_END_BIT = 23;
const uint32_t MCFGPMA_BASE_ADDRESS_START_BIT = 26;
const uint32_t MCFGPMA_BASE_ADDRESS_END_BIT = 43;

// attribute index constants
// first array dimension (group ID)
const uint8_t MSS_MCS_GROUP_32_NM_START_INDEX = 0;
const uint8_t MSS_MCS_GROUP_32_NM_END_INDEX   = 7;
const uint8_t MSS_MCS_GROUP_32_M_START_INDEX  = 8;
const uint8_t MSS_MCS_GROUP_32_M_END_INDEX    = 15;

// second array dimension (group definition)
const uint8_t MSS_MCS_GROUP_32_MCS_IN_GROUP_INDEX  = 1;
const uint8_t MSS_MCS_GROUP_32_SIZE_INDEX          = 2;
const uint8_t MSS_MCS_GROUP_32_BASE_INDEX          = 3;
const uint8_t MSS_MCS_GROUP_32_MEMBERS_START_INDEX = 4;
const uint8_t MSS_MCS_GROUP_32_ALT_VALID_INDEX     = 12;
const uint8_t MSS_MCS_GROUP_32_ALT_SIZE_INDEX      = 13;
const uint8_t MSS_MCS_GROUP_32_ALT_BASE_INDEX      = 14;




//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*mss_setup_bars_FP_t)(const fapi::Target& i_pu_target, std::vector<fapi::Target> & i_associated_centaurs);


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

//------------------------------------------------------------------------------
// function: program MCS base address registers (BARs)
//           writes non-mirrored (MCFGP/MCFGPA) &
//           mirrored BAR registers (MCFGPM/MCFGPMA)
// parameters: i_pu_target  => chip level target
// returns: FAPI_RC_SUCCESS if all register writes are successful,
//          RC_MSS_SETUP_BARS_MULTIPLE_GROUP_ERR if a child MCS is listed
//            as a member in multiple groups
//          else failing return code
//------------------------------------------------------------------------------
fapi::ReturnCode mss_setup_bars(const fapi::Target& i_pu_target, std::vector<fapi::Target> & i_associated_centaurs);


} // extern "C"

#endif // MSS_SETUP_BARS_H_
