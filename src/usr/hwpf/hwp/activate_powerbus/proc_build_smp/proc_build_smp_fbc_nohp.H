/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp_fbc_nohp.H $ */
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
// $Id: proc_build_smp_fbc_nohp.H,v 1.3 2014/02/23 21:41:07 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_build_smp_fbc_nohp.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
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
