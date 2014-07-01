/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp_epsilon.H $ */
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
// $Id: proc_build_smp_epsilon.H,v 1.8 2014/02/23 21:41:06 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_build_smp_epsilon.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_build_smp_epsilon.H
// *! DESCRIPTION : Epsilon calculation/application functions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_BUILD_SMP_EPSILON_H_
#define _PROC_BUILD_SMP_EPSILON_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_build_smp.H>


extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: utility function to round to ceiling
// parameters: i_n => numerator
//             i_d => denominator
// returns: ceiling of i_n / i_d (integer)
//------------------------------------------------------------------------------
uint32_t proc_build_smp_round_ceiling(
    uint32_t i_n,
    uint32_t i_d);


//------------------------------------------------------------------------------
// function: set target epsilon values into system attributes/HW
// parameters: i_smp => structure encapsulating SMP
// returns: FAPI_RC_SUCCESS if application is successful
//          RC_PROC_BUILD_SMP_EPSILON_INVALID_TABLE_ERR if invalid epsilon
//              table type/content is detected,
//          RC_PROC_BUILD_SMP_EPSILON_RANGE_ERR if any target value is out of
//              range given underlying HW storage,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_epsilons(
    proc_build_smp_system & i_smp);

} // extern "C"

#endif // _PROC_BUILD_SMP_EPSILON_H_
