//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/dram_training/mss_draminit/mss_draminit.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
// $Id: mss_draminit.H,v 1.5 2012/02/10 21:59:20 jdsloat Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_draminit.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_draminit.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Jacob Sloat     Email: jdsloat@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_draminit.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.4    | jdsloat  |  2/10/12| & fix
//  1.3    | jdsloat  |  2/08/12| added description to target
//  1.2    | jdsloat  |  1/13/12| added "fapi::" and "const" in typedef to match the call in the extern
//  1.1    | jdsloat  | 11/18/11| Updated

#ifndef MSS_DRAMINITHWPB_H_
#define MSS_DRAMINITHWPB_H_

#include <fapi.H>

typedef fapi::ReturnCode (*mss_draminit_FP_t)(const fapi::Target& i_target);

extern "C"
{

/**
 * @brief Draminit procedure. Loading RCD and MRS into the drams.
 *
 * @param[in]  i_target  Reference to centaur.mba target
 *
 * @return ReturnCode
 */

fapi::ReturnCode mss_draminit(const fapi::Target& i_target);

} // extern "C"

#endif // MSS_DRAMINITHWPB_H_
