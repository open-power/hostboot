/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_revert_sbe_mcs_setup/proc_revert_sbe_mcs_setup.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: proc_revert_sbe_mcs_setup.H,v 1.4 2013/04/27 17:23:43 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_revert_sbe_mcs_setup.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_revert_sbe_mcs_setup.H
// *! DESCRIPTION : Revert MCS configuration applied by SBE (FAPI)
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS:
// *!
// *! Disable MCS configuration written by SBE to enable initial phase of
// *! HBI execution (providing lpc_ack for dcbz prior to initialization
// *! of memory).  Registers touched by SBE (MCFGP, MCIFIRMASK) will be
// *! reset to flush state by this procedure.
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_REVERT_SBE_MCS_SETUP_H_
#define _PROC_REVERT_SBE_MCS_SETUP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <vector>
#include <fapi.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// Nest GP0 register constants
const uint32_t NEST_GP0_MCL_FENCE_B_BIT = 51;
const uint32_t NEST_GP0_MCR_FENCE_B_BIT = 52;

// MCFGP register constants
const uint32_t MCFGP_VALID_BIT = 0;
const uint32_t MCFGP_UNITS_PER_GROUP_START_BIT = 1;
const uint32_t MCFGP_UNITS_PER_GROUP_END_BIT = 3;
const uint32_t MCFGP_GROUP_MEMBER_ID_START_BIT = 4;
const uint32_t MCFGP_GROUP_MEMBER_ID_END_BIT = 8;
const uint32_t MCFGP_GROUP_SIZE_START_BIT = 11;
const uint32_t MCFGP_GROUP_SIZE_END_BIT = 23;
const uint32_t MCFGP_FASTPATH_ENABLE_BIT = 25;
const uint32_t MCFGP_GROUP_BASE_ADDR_START_BIT = 26;
const uint32_t MCFGP_GROUP_BASE_ADDR_END_BIT = 43;

// MCIFIR register constants
const uint32_t MCIFIR_CL_TIMEOUT_BIT = 27;
const uint32_t MCIFIR_CL_TIMEOUT_DUE_TO_CHANNEL_BIT = 40;


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_revert_sbe_mcs_setup_FP_t)(const fapi::Target&);


extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: disable MCS configuration written by SBE to enable initial phase of
//           HBI execution (providing lpc_ack for dcbz prior to initialization
//           of memory)
// parameters: i_target => P8 master chip target
// returns: FAPI_RC_SUCCESS if all register writes are successful,
//          else failing return code
fapi::ReturnCode proc_revert_sbe_mcs_setup(
    const fapi::Target& i_target);


} // extern "C"


#endif // _PROC_REVERT_SBE_MCS_SETUP_H_
