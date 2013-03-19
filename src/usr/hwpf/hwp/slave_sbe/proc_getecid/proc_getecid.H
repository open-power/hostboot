/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_getecid/proc_getecid.H $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
// $Id: proc_getecid.H,v 1.7 2013/03/28 17:21:10 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/utils/proc_getecid.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_getecid.H
// *! DESCRIPTION : Get ECID string from target using SCOM
// *!
// *! OWNER NAME  : Joe McGill     Email: jmcgill@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS:
// *!
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_GETECID_H_
#define _PROC_GETECID_H_

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
(*proc_getecid_FP_t)(const fapi::Target&, ecmdDataBufferBase& fuseString);


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// OTPROM mode register field/bit definitions
const uint32_t OTPC_M_MODE_REGISTER_ECC_ENABLE_BIT = 1;


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

// function: FAPI proc_getecid HWP entry point
// parameters: i_target      => P8 chip target
//             io_fuseString => ecmdDataBuffer which will return ECID data
//                              (also written to ATTR_ECID)
// returns: FAPI_RC_SUCCESS if successful, else error
fapi::ReturnCode proc_getecid(
    const fapi::Target& i_target,
    ecmdDataBufferBase& io_fuseString);

} // extern "C"

#endif // _PROC_GETECID_H_
