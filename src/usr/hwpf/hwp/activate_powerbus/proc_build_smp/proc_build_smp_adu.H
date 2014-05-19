/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp_adu.H $ */
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
// $Id: proc_build_smp_adu.H,v 1.5 2014/02/23 21:41:06 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_build_smp_adu.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_build_smp_adu.H
// *! DESCRIPTION : Interface for ADU operations required to support fabric
// *!               configuration actions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_BUILD_SMP_ADU_H_
#define _PROC_BUILD_SMP_ADU_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>
#include <proc_build_smp.H>

extern "C" {

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: perform fabric C/D configuration switch on a single chip
// parameters: i_smp_chip => structure encapsulating chip
//             i_smp      => structure encapsulating SMP
// returns: FAPI_RC_SUCCESS if fabric reconfiguration is successful,
//          FAPI_RC_PLAT_ERR_ADU_LOCKED if operation failed due to state of
//              ADU atomic lock,
//          RC_PROC_ADU_UTILS_INVALID_LOCK_OPERATION if an unsupported operation
//              is specified,
//          RC_PROC_ADU_UTILS_INVALID_LOCK_ATTEMPTS if invalid number of attempts
//              is specified,
//          RC_PROC_BUILD_SMP_ADU_STATUS_MISMATCH if ADU status mismatches
//              for switch operation,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_switch_cd(
    proc_build_smp_chip& i_smp_chip,
    proc_build_smp_system& i_smp);


//------------------------------------------------------------------------------
// function: quiesce slave fabrics by issuing fabric quiesce operation on
//           specified chips
//           NOTE: ADU atomic lock will be obtained for all chips prior
//                 to issuing quiesce operation on specified chips
// parameters: i_smp => structure encapsulating SMP
//             i_op  => enumerated type representing SMP build phase
//                      (SMP_ACTIVATE_PHASE1 = HBI,
//                       SMP_ACTIVATE_PHASE2 = FSP)
// returns: FAPI_RC_SUCCESS if fabric reconfiguration is successful,
//          FAPI_RC_PLAT_ERR_ADU_LOCKED if operation failed due to state of
//              ADU atomic lock,
//          RC_PROC_ADU_UTILS_INVALID_LOCK_OPERATION if an unsupported operation
//              is specified,
//          RC_PROC_ADU_UTILS_INVALID_LOCK_ATTEMPTS if invalid number of attempts
//              is specified,
//          RC_PROC_BUILD_SMP_ADU_STATUS_MISMATCH if ADU status mismatches
//              for switch operation,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_quiesce_pb(
    proc_build_smp_system& i_smp,
    const proc_build_smp_operation i_op);


//------------------------------------------------------------------------------
// function: perform fabric A/B configuration switch on all chips present in SMP
//           NOTE: ADU atomic lock will be obtained for all chips prior to
//                 issuing switch from master chip (defined by
//                 i_master_smp_chip)
// parameters: i_smp => structure encapsulating SMP
//             i_op  => enumerated type representing SMP build phase
//                      (SMP_ACTIVATE_PHASE1 = HBI,
//                       SMP_ACTIVATE_PHASE2 = FSP)
// returns: FAPI_RC_SUCCESS if fabric reconfiguration is successful,
//          FAPI_RC_PLAT_ERR_ADU_LOCKED if operation failed due to state of
//              ADU atomic lock,
//          RC_PROC_ADU_UTILS_INVALID_LOCK_OPERATION if an unsupported operation
//              is specified,
//          RC_PROC_ADU_UTILS_INVALID_LOCK_ATTEMPTS if invalid number of attempts
//              is specified,
//          RC_PROC_BUILD_SMP_ADU_STATUS_MISMATCH if ADU status mismatches
//              for switch operation,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_switch_ab(
    proc_build_smp_system& i_smp,
    const proc_build_smp_operation i_op);


} // extern "C"

#endif // _PROC_BUILD_SMP_ADU_H_
