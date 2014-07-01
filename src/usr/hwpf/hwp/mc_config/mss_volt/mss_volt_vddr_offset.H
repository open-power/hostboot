/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_volt/mss_volt_vddr_offset.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
// $Id: mss_volt_vddr_offset.H,v 1.4 2014/06/18 20:34:39 dcadiga Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_volt_vddr_offset.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Stephen Glancy    Email: sglancy@us.ibm.com
// *! BACKUP NAME : Jacob Sloat      Email: jdsloat@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_volt_vddr_offset.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:   | Comment:
//---------|----------|----------|-----------------------------------------------
//  1.4    | sglancy  | 06/16/14 | Updated to include output attribute
//  1.3    | sglancy  | 06/04/14 | Updated to include output attribute
//  1.2    | sglancy  | 05/30/14 | changed function to return a value in uV
//  1.1    | sglancy  | 05/20/14 | initial drop
#ifndef MSS_VOLT_VDDR_OFFSET_H_
#define MSS_VOLT_VDDR_OFFSET_H_

#include <fapi.H>

typedef fapi::ReturnCode (*mss_volt_vddr_offset_FP_t)(std::vector<fapi::Target> &);

extern "C"
{

/**
 * @brief mss_volt_vddr_offset procedure. Determines operating vddr voltage for dimms behind a vddr voltage domain
 *
 * @param[in]  std::vector<fapi::Target> l_targets  Reference to vector of Centaur Targets in a particular vddr power domain
 *
 * @return ReturnCode
 */

  fapi::ReturnCode mss_volt_vddr_offset(std::vector<fapi::Target> & i_targets);

} // extern "C"

#endif // MSS_VOLT_VDDR_OFFSET_H_
