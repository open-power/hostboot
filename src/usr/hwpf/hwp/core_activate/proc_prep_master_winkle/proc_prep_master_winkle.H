/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/core_activate/proc_prep_master_winkle/proc_prep_master_winkle.H $
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
// $Id: proc_prep_master_winkle.H,v 1.3 2012/08/01 18:37:38 jeshua Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_prep_master_winkle.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_prep_master_winkle.H
// *! DESCRIPTION : Prepares for the master core to winkle
// *!
// *! OWNER NAME  : Jeshua Smith            Email: jeshua@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_PREP_MASTER_WINKLE_H_
#define _PROC_PREP_MASTER_WINKLE_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>
#include "p8_scom_addresses.H"
#include "proc_sbe_ffdc.H"
#include "p8_istep_num.H"
#include "proc_sbe_trigger_winkle.H"

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_prep_master_winkle_FP_t)(const fapi::Target &,
                                                         const bool &);

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------


extern "C"
{

/**
 * @brief Start the auto-POR engine and the SBE
 *
 * @param[in] i_target  Reference to chip target
 *
 * @return ReturnCode
 */
  fapi::ReturnCode proc_prep_master_winkle(const fapi::Target & i_target,
                                           const bool useRealSBE);

} // extern "C"

#endif // _PROC_PREP_MASTER_WINKLE_H_
