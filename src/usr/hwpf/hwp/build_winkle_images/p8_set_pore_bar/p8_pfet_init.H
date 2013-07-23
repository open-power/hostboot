/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_pfet_init.H $ */
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
// $Id: p8_pfet_init.H,v 1.2 2013/08/02 19:06:05 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pfet_init.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : p8_pfet_init.H
// *! DESCRIPTION : Initialization and reset the EX chiplet PFET controller
// *!
// *! OWNER NAME  : Ralf Maier    Email: ralf.maier@de.ibm.com
// *! BACKUP NAME : Greg Still    Email: stillgs@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _P8_PFET_INIT_H_
#define _P8_PFET_INIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------


// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pfet_init_FP_t) (const fapi::Target&, uint32_t);

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
/// \param[in] i_target  Chip target
/// \param[in] mode      Control mode (PM_CONFIG, PM_INIT, PM_RESET)

/// \retval FAPI_RC_SUCCESS if something good happens,
/// \retval RC per p8_pfet_init_errors.xml otherwise
fapi::ReturnCode 
p8_pfet_init(const fapi::Target& i_target, uint32_t i_mode);

} // extern "C"

#endif // _P8_PFET_INIT_H_
