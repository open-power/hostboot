//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/mc_init/mss_eff_config/mss_eff_config_rank_group.H $
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
// $Id: mss_eff_config_rank_group.H,v 1.3 2012/02/15 01:39:30 asaetow Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_eff_config_rank_group.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_config_rank_group.H
// *! DESCRIPTION : Header file for mss_eff_config_rank_group.
// *! OWNER NAME  : Anuwat Saetow     Email: asaetow@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
//
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.4   |          |         |
//   1.3   | asaetow  |14-FEB-12| Fixed "fapi::" for hostboot, added "const", renamed "i_target_mba", and changed comments.
//   1.2   | asaetow  |24-JAN-12| Added typedef and extern "C".
//   1.1   | asaetow  |03-NOV-11| First Draft.


#ifndef MSS_EFF_CONFIG_RANK_GROUP_H_
#define MSS_EFF_CONFIG_RANK_GROUP_H_

//----------------------------------------------------------------------
//  My Includes
//----------------------------------------------------------------------


//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>


typedef fapi::ReturnCode (*mss_eff_config_rank_group_FP_t)(const fapi::Target i_target_mba);

extern "C" {

//******************************************************************************
//* name=mss_eff_config_rank_group, param=i_target_mba, return=ReturnCode
//******************************************************************************
fapi::ReturnCode mss_eff_config_rank_group(const fapi::Target i_target_mba);

} // extern "C"

#endif // MSS_EFF_CONFIG_RANK_GROUP_H_
