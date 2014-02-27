/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_mb_interleave/mss_eff_mb_interleave.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
// $Id: mss_eff_mb_interleave.H,v 1.3 2014/02/19 20:06:18 bellows Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_eff_mb_interleave.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2014
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *!  Licensed material - Program property of IBM
// *!  Refer to copyright instructions form no. G120-2083
// *! Created on Wed Jan  8 2014 at 07:56:37
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_mb_interleave
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  :  Bellows Mark D. (Mark D),319432 Email: bellows@us.ibm.com
// *! BACKUP NAME :                 Email: ______@us.ibm.com

// *! ADDITIONAL COMMENTS :
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.3   | bellows  |19-JAN-14| Additional RAS updates
//   1.2   | bellows  |17-JAN-14| RAS
//   1.1   | bellows  |08-JAN-14| Created.
#ifndef __MSS_EFF_MB_INTERLEAVE_H
#define __MSS_EFF_MB_INTERLEAVE_H

#include <fapi.H>

typedef fapi::ReturnCode (*mss_eff_mb_interleave_FP_t)(const fapi::Target& centaur );

extern "C"
{

// This hardware procedure checks the plugging rules for a centaur and works with interleaving within the centaur
// if various plug rules are violated at this level of the memory stack, error logs and deconfigures will happen
// Many deconfig by assoication rules are not checked here.  Just 4.1 and 4.2 plus a required Interleaving check
fapi::ReturnCode mss_eff_mb_interleave(const fapi::Target & i_cen_target);



} // extern "C"

#endif
