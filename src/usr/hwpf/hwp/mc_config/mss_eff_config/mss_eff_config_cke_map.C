/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_config_cke_map.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: mss_eff_config_cke_map.C,v 1.5 2014/01/07 21:50:06 bellows Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_eff_config_cke_map.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_config_cke_map
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Anuwat Saetow     Email: asaetow@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// This procedure takes in attributes and determines proper cke map.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.5   | bellows  |02-JAN-14| VPD attribute removal
//   1.4   | kcook    |16-AUG-12| Added LRDIMM support.
//   1.3   | asaetow  |14-NOV-12| Added ATTR_EFF_SPCKE_MAP. 
//   1.2   | asaetow  |13-NOV-12| Added FAPI_ERR for else "Undefined IBM_TYPE". 
//         |          |         | Removed outter NUM_DROPS_PER_PORT check.
//   1.1   | asaetow  |07-NOV-12| First Draft.



//----------------------------------------------------------------------
//  My Includes
//----------------------------------------------------------------------



//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>



extern "C" {

//----------------------------------------------------------------------
// ENUMs and CONSTs
//----------------------------------------------------------------------



//******************************************************************************
//* name=mss_eff_config_cke_map, param=i_target_mba, return=ReturnCode
//******************************************************************************
fapi::ReturnCode mss_eff_config_cke_map(const fapi::Target i_target_mba) {
   fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;
   const char * const PROCEDURE_NAME = "mss_eff_config_cke_map";
   FAPI_INF("*** Running %s on %s ... ***", PROCEDURE_NAME, i_target_mba.toEcmdString());


   // Define attribute array size

   // Set attributes

   FAPI_INF("%s on %s COMPLETE", PROCEDURE_NAME, i_target_mba.toEcmdString());
   return rc;
}



} // extern "C"
