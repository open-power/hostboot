/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp_adu.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
// $Id: proc_build_smp_adu.H,v 1.2 2012/09/05 03:11:26 jmcgill Exp $
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
#include "proc_build_smp.H"

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------

const uint32_t PROC_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS = 1;
const bool PROC_BUILD_SMP_PHASE1_ADU_PICK_LOCK = false;
const uint32_t PROC_BUILD_SMP_PHASE1_POST_QUIESCE_DELAY = 128;
const uint32_t PROC_BUILD_SMP_PHASE1_PRE_INIT_DELAY = 128;

const uint32_t PROC_BUILD_SMP_PHASE2_ADU_LOCK_ATTEMPTS = 5;
const bool PROC_BUILD_SMP_PHASE2_ADU_PICK_LOCK = true;
const uint32_t PROC_BUILD_SMP_PHASE2_POST_QUIESCE_DELAY = 4096;
const uint32_t PROC_BUILD_SMP_PHASE2_PRE_INIT_DELAY = 512;


extern "C" {

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// function: perform fabric quiesce on a single chip
// parameters: i_smp_chip => structure encapsulating chip
// returns: FAPI_RC_SUCCESS if fabric reconfiguration is successful,
//          FAPI_RC_PLAT_ERR_ADU_LOCKED if operation failed due to state of
//              ADU atomic lock,
//          RC_PROC_ADU_UTILS_INVALID_ARGS if invalid parameters are detected
//              by ADU library code,
//          RC_PROC_ADU_UTILS_INTERNAL_ERR if an unexpected internal
//              logic error occurs in ADU library code,
//          RC_PROC_BUILD_SMP_ADU_STATUS_MISMATCH if ADU status mismatches
//              for switch operation,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_quiesce_pb(
    proc_build_smp_chip& i_smp_chip);

//------------------------------------------------------------------------------
// function: perform fabric C/D configuration switch on a single chip
// parameters: i_smp_chip => structure encapsulating chip
// returns: FAPI_RC_SUCCESS if fabric reconfiguration is successful,
//          FAPI_RC_PLAT_ERR_ADU_LOCKED if operation failed due to state of
//              ADU atomic lock,
//          RC_PROC_ADU_UTILS_INVALID_ARGS if invalid parameters are detected
//              by ADU library code,
//          RC_PROC_ADU_UTILS_INTERNAL_ERR if an unexpected internal
//              logic error occurs in ADU library code,
//          RC_PROC_BUILD_SMP_ADU_STATUS_MISMATCH if ADU status mismatches
//              for switch operation,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_switch_cd(
    proc_build_smp_chip& i_smp_chip);


//------------------------------------------------------------------------------
// function: perform fabric A/B configuration switch on all chips present in
//           SMP (defined by i_smp)
//           NOTE: ADU atomic lock will be obtained for all chips prior to
//                 issuing switch from master chip (defined by
//                 i_master_smp_chip)
// parameters: i_master_smp_chip => structure encapsulating current SMP master
//                                  chip
//             i_smp             => structure encapsulating SMP
// returns: FAPI_RC_SUCCESS if fabric reconfiguration is successful,
//          FAPI_RC_PLAT_ERR_ADU_LOCKED if operation failed due to state of
//              ADU atomic lock,
//          RC_PROC_ADU_UTILS_INVALID_ARGS if invalid parameters are detected
//              by ADU library code,
//          RC_PROC_ADU_UTILS_INTERNAL_ERR if an unexpected internal
//              logic error occurs in ADU library code,
//          RC_PROC_BUILD_SMP_ADU_STATUS_MISMATCH if ADU status mismatches
//              for switch operation,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_switch_ab(
    proc_build_smp_chip& i_master_smp_chip,
    proc_build_smp_system& i_smp);

} // extern "C"

#endif // _PROC_BUILD_SMP_ADU_H_
