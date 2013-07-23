/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_pfet_control.H $ */
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
// $Id: p8_pfet_control.H,v 1.4 2013/08/02 19:05:23 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pfet_control.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : p8_pfet_control.H
// *! DESCRIPTION : General routines for controlling EX chiplet PFET headers
// *!
// *! OWNER NAME  : Ralf Maier    Email: ralf.maier@de.ibm.com
// *! BACKUP NAME : Greg Still    Email: stillgs@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _P8_PFETCTL_H_
#define _P8_PFETCTL_H_


extern "C" {

#include "p8_pfet_types.H"


// \todo  Define the read structure for programmatic data return

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------


// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pfet_control_FP_t) (const fapi::Target&,
                                                uint8_t,
                                                pfet_dom_t,
                                                pfet_force_t
                                               );

typedef fapi::ReturnCode (*p8_pfet_read_FP_t)   (const fapi::Target&);

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Parameter structure definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// \param[in] i_target     Chip target
/// \param[in] i_ex_number  EX number
/// \param[in] i_domain     Domain: BOTH, ECO, CORE
/// \param[in] i_op         Operation: VON, VOFF, NONE
///
/// \retval ECMD_SUCCESS if something good happens,
/// \retval BAD_RETURN_CODE otherwise
fapi::ReturnCode
p8_pfet_control(    const fapi::Target& i_target,
                    uint8_t             i_ex_number,
                    pfet_dom_t          domain,
                    pfet_force_t        op
                 );


} // extern "C"

#endif // _P8_PFETCTL_H_
