/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_getecid/proc_getecid.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
// $Id: proc_getecid.H,v 1.8 2014/10/03 21:56:49 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/utils/proc_getecid.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
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
