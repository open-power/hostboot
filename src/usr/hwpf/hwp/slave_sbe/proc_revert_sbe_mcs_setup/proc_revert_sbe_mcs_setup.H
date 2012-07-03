/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/slave_sbe/proc_revert_sbe_mcs_setup/proc_revert_sbe_mcs_setup.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
// $Id: proc_revert_sbe_mcs_setup.H,v 1.1 2012/06/05 07:03:39 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_revert_sbe_mcs_setup.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
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
#include "p8_scom_addresses.H"


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

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
const uint32_t MCIFIR_CL_TIMEOUT_DUE_TO_CHANNEL_BIT = 28;


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
