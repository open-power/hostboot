/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/proc_switch_cfsim/proc_switch_cfsim.H $ */
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
// $Id: proc_switch_cfsim.H,v 1.3 2012/05/03 10:41:52 rkoester Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_switch_cfsim.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : p8_switch_cfsim.H
// *! DESCRIPTION : (FAPI)
// *!
// *! OWNER NAME  : Ralph Koester Email: rkoester@de.ibm.com
// *! BACKUP NAME : Gebhard Weber Email: gweber@de.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
// *!               this is a function pointer of p8_switch_cfsim.C
// *!
//------------------------------------------------------------------------------

#ifndef _P8_SWITCH_CFSIM_H_
#define _P8_SWITCH_CFSIM_H_

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
(*proc_switch_cfsim_FP_t)(const fapi::Target&, bool, bool, bool, bool, bool,
                          bool, bool);




//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------


extern "C"
{


/**
 * @brief access GP4 of CFAM via MBOX
 *
 * @param[in] i_target     Processor Chip Target (Murano, Venice)
 * @param[in] RESET        True if all fences should be reset
 * @param[in] RESETOPB     Reset both OPB switches
 * @param[in] FENCEFSI0    Fence port FSI-0
 * @param[in] FENCEPIBnh   Fence PIB none HOST PIB port
 * @param[in] FENCEPIBh    Fence HOST PIB port
 * @param[in] FENCEFSI1    Fence Port FSI-1
 * @param[in] FENCEPIBSW1  fence PIB por
 *
 * @return ReturnCode
 */

fapi::ReturnCode proc_switch_cfsim(const fapi::Target& i_target,
                                   bool i_RESET,
                                   bool i_RESET_OPB_SWITCH,
                                   bool i_FENCE_FSI0,
                                   bool i_FENCE_PIB_NH,
                                   bool i_FENCE_PIB_H,
                                   bool i_FENCE_FSI1,
                                   bool i_FENCE_PIB_SW1);

} // extern "C"


#endif // _PROC_SWITCH_CFSIM_H_


