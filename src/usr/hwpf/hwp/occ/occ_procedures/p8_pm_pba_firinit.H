/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_pba_firinit.H $     */
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
// $Id: p8_pm_pba_firinit.H,v 1.6 2013/04/01 04:27:50 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_pba_firinit.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : p8_pm_pba_firinit.H
// *! DESCRIPTION : SET PBA FIRINITS
// *!
// *! OWNER NAME  : Greg Still    Email: stillgs@us.ibm.com
// *! BACKUP NAME : Pradeep CN    Email: padeepcn@in.ibm.com
// *!
//------------------------------------------------------------------------------

#include "p8_pm_firinit.H"

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pm_pba_firinit_FP_t) (const fapi::Target&  , uint32_t mode);

extern "C" {

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: FAPI p8_pm_pba_firinit  HWP entry point
//           operates on chips passed in i_target argument to perform
//           desired settings of FIRS of OHA macro 
// parameters: i_target        => chip target

// returns: FAPI_RC_SUCCESS if all specified operations complete successfully,
//          else return code for failing operation
//------------------------------------------------------------------------------
fapi::ReturnCode 
p8_pm_pba_firinit(const fapi::Target& i_target, uint32_t mode );


} // extern "C"


