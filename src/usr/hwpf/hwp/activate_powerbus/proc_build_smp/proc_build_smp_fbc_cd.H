/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp_fbc_cd.H $ */
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
// $Id: proc_build_smp_fbc_cd.H,v 1.17 2014/02/23 21:41:07 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_build_smp_fbc_cd.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_build_smp_fbc_cd.H
// *! DESCRIPTION : Fabric configuration (hotplug, CD) functions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_BUILD_SMP_FBC_CD_H_
#define _PROC_BUILD_SMP_FBC_CD_H_

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
// function: program fabric configuration register (hotplug, C/D set)
// parameters: i_smp => structure encapsulating SMP topology
// returns: FAPI_RC_SUCCESS if register reads are successful and all shadow
//               registers are equivalent,
//          FAPI_RC_PLAT_ERR_ADU_LOCKED if operation failed due to state of
//              ADU atomic lock,
//          RC_PROC_ADU_UTILS_INVALID_LOCK_OPERATION if an unsupported operation
//              is specified,
//          RC_PROC_ADU_UTILS_INVALID_LOCK_ATTEMPTS if invalid number of attempts
//              is specified,
//          RC_PROC_ADU_UTILS_INVALID_FBC_OP if invalid fabric operation
//              parameters are specified,
//          RC_PROC_BUILD_SMP_ADU_STATUS_MISMATCH if ADU status mismatches
//              for switch operation,
//          RC_PROC_BUILD_SMP_CORE_FLOOR_RATIO_ERR if cache/nest frequency
//              ratio is unsupported,
//          RC_PROC_BUILD_SMP_CORE_CEILING_RATIO_ERR if cache/nest frequency
//              ratio is unsupported,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_fbc_cd(
    proc_build_smp_system& i_smp);


} // extern "C"

#endif // _PROC_BUILD_SMP_FBC_CD_H_
