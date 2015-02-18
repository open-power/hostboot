/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp_fbc_nohp.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
// $Id: proc_build_smp_fbc_nohp.H,v 1.4 2015/02/09 22:37:59 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_build_smp_fbc_nohp.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_build_smp_fbc_nohp.H
// *! DESCRIPTION : Fabric configuration (non-hotplug) functions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_BUILD_SMP_FBC_NOHP_H_
#define _PROC_BUILD_SMP_FBC_NOHP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_build_smp.H>
#include <p8_scom_addresses.H>


extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: program fabric trace configuration registers (non-hotplug)
// parameters: i_smp => structure encapsulating SMP topology
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_fbc_nohp_trace(
    proc_build_smp_system& i_smp);

//------------------------------------------------------------------------------
// function: program fabric configuration registers (non-hotplug)
// parameters: i_smp => structure encapsulating SMP topology
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          RC_PROC_BUILD_SMP_INVALID_GROUP_SIZE_ERR if group size is too
//              small/large,
//          RC_PROC_BUILD_SMP_PACING_RATE_TABLE_ERR if pacing rate table lookup
//              is unsuccessful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_fbc_nohp(
    proc_build_smp_system& i_smp);

} // extern "C"

#endif // _PROC_BUILD_SMP_FBC_NOHP_H_
