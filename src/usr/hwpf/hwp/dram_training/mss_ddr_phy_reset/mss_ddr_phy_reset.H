//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/dram_training/mss_ddr_phy_reset/mss_ddr_phy_reset.H $
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
// $Id: mss_ddr_phy_reset.H,v 1.1 2011/11/19 19:19:34 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_ddr_phy_reset.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_ddr_phy_reset.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Mark Fredrickson  Email: mfred@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_ddr_phy_reset.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.1    | mfred  | 11/19/11| Updated

#ifndef MSS_DDR_PHY_RESETHWPB_H_
#define MSS_DDR_PHY_RESETHWPB_H_

#include <fapi.H>

extern "C"
{

/**
 * @brief ddr_phy_reset procedure.
 *
 * @param[in]  i_target  Reference to target
 *
 * @return ReturnCode
 */

fapi::ReturnCode mss_ddr_phy_reset(const fapi::Target target);

} // extern "C"

#endif // MSS_DDR_PHY_RESETHWPB_H_
