/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mem_pll_setup/cen_mem_pll_initf.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// $Id: cen_mem_pll_initf.H,v 1.3 2013/11/15 16:29:59 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/cen_mem_pll_initf.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : cen_mem_pll_initf.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Mark Fredrickson  Email: mfred@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for cen_mem_pll_initf.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.0    | mfred    | 08/09/12| Initial creation
//  1.3    | mjjones  | 11/12/13| Deleted internal func prototype

#ifndef CEN_MEM_PLL_INITF_H_
#define CEN_MEM_PLL_INITF_H_

#include <fapi.H>

typedef fapi::ReturnCode (*cen_mem_pll_initf_FP_t)(const fapi::Target& i_target);

extern "C"
{

/**
 * @brief cen_mem_pll_initf procedure.
 *
 * The purpose of this procedure is to scan the right values in to the Centaur
 * MEM PLL controller..
 *
 * @param[in]  i_target  Reference to centaur target
 * @return ReturnCode
 */
fapi::ReturnCode cen_mem_pll_initf(const fapi::Target& i_target);

} // extern "C"

#endif // CEN_MEM_PLL_INITF_H_
