/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_dimm_power_test/mss_dimm_power_test.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: mss_dimm_power_test.C,v 1.1 2013/04/18 14:14:10 joabhend Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_dimm_power_test.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_dimm_power_test
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Joab Henderson    Email: joabhend@us.ibm.com
// *! BACKUP NAME : Michael Pardeik   Email: pardeik@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// DESCRIPTION:
// The purpose of this procedure is to run an insitu power test on ISDIMMs to determine max power draw
//
// TODO:
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.1   | joabhend |04-APR-13| Shell code - Only returns success



//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <mss_dimm_power_test.H>
#include <fapi.H>

extern "C" {

   using namespace fapi;


   // Procedures in this file
   fapi::ReturnCode mss_dimm_power_test(const fapi::Target & i_target);
   
   
//******************************************************************************
//
//******************************************************************************
   
fapi::ReturnCode mss_dimm_power_test(const fapi::Target & i_target)
{
   // Target is centaur.mba
    
   fapi::ReturnCode l_rc = fapi::FAPI_RC_SUCCESS;
   
   return l_rc;
}
   

} //end extern C

