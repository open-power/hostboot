/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_fbc_utils.H $ */
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
// $Id: proc_fbc_utils.H,v 1.3 2014/01/19 17:34:51 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/utils/proc_fbc_utils.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_fbc_utils.H
// *! DESCRIPTION : Fabric library functions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_FBC_UTILS_H_
#define _PROC_FBC_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>
#include <p8_scom_addresses.H>

extern "C" {

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// address range definitions
const uint64_t PROC_FBC_UTILS_FBC_MAX_ADDRESS = ((1ULL << 50)-1ULL);
const uint64_t PROC_FBC_UTILS_CACHELINE_MASK = 0x7FULL;
const uint64_t PROC_FBC_UTILS_LAST_ADDR_IN_CACHELINE = 0x78ULL;


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

// function: read PB Mode & ADU pMisc Mode registers to check state of fabric
//           init and stop control signals
// parameters: i_target         => P8 chip target
//             o_is_initialized => return state of fabric init signal
//             o_is_running     => return state of fabric pervasive stop control
// returns: FAPI_RC_SUCCESS if SCOM reads are successful,
//          else error
fapi::ReturnCode proc_fbc_utils_get_fbc_state(
    const fapi::Target& i_target,
    bool& o_is_initialized,
    bool& o_is_running);


// function: read-modify-write ADU pMisc Mode register to clear fabric stop
//           signal (override stop caused by checkstop)
// parameters: i_target         => P8 chip target
// returns: FAPI_RC_SUCCESS if SCOM sequence is successful,
//          else error
fapi::ReturnCode proc_fbc_utils_override_fbc_stop(
    const fapi::Target& i_target);


} // extern "C"

#endif // _PROC_FBC_UTILS_H_
