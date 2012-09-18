/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_pmc_deconfig_setup.H $ */
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
// $Id: p8_pmc_deconfig_setup.H,v 1.1 2012/09/19 11:43:46 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pmc_deconfig_setup.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *| \file p8_pmc_deconfig_setup.C
// *| \brief Setup PMC Deconfig based on EX chiplet enable bit (GP0(0))
// *!
// *! OWNER NAME  : Greg Still      Email: stillgs@us.ibm.com
// *! BACKUP NAME : Pradeep CN      Email: pradeepcn@in.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_PMCDECONFIG_H_
#define _PROC_PMCDECONFIG_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pmc_deconfig_setup_FP_t) (const fapi::Target&);

extern "C" {


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Parameter structure definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// \param[in] i_target Chip target

/// \retval ECMD_SUCCESS if something good happens,
/// \retval BAD_RETURN_CODE otherwise
fapi::ReturnCode 
p8_pmc_deconfig_setup(const fapi::Target& i_target);


} // extern "C"

#endif // _PROC_PMCDECONFIG_H_
