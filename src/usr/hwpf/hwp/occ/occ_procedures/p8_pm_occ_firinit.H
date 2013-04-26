/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_occ_firinit.H $     */
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
// $Id: p8_pm_occ_firinit.H,v 1.6 2013/04/01 04:27:49 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_occ_firinit.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_pm_oha_firinit.H
// *! DESCRIPTION : Configures the OCC LFIR Mask and Action 
// *!
// *! OWNER NAME: Jim Yacynych         Email: jimyac@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _P8_PM_OCC_FIRINIT_H_
#define _P8_PM_OCC_FIRINIT_H_

#include "p8_pm_firinit.H"
#include <fapi.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pm_occ_firinit_FP_t) (const fapi::Target& , uint32_t mode);

extern "C" {
//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// \brief  Configures the OCC LFIR Mask and Action
/// \param[in]  i_target              => Chip Target

fapi::ReturnCode 
p8_pm_occ_firinit(const fapi::Target& i_target , uint32_t mode);
 
} // extern "C"

#endif 
