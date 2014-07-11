/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_volt/mss_volt_vpp_offset.H $   */
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
// $Id: mss_volt_vpp_offset.H,v 1.5 2014/07/09 15:24:55 sglancy Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_volt_vpp_offset.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Stephen Glancy    Email: sglancy@us.ibm.com
// *! BACKUP NAME : Jacob Sloat      Email: jdsloat@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_volt_vpp_offset.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:   | Comment:
//---------|----------|----------|-----------------------------------------------
//  1.5    | sglancy  | 07/09/14 | Added Default attribute values
//  1.4    | sglancy  | 06/16/14 | Updated to fix formatting
//  1.3    | sglancy  | 06/04/14 | Updated to account for output attribute
//  1.2    | sglancy  | 05/30/14 | changed function to return a value in uV
//  1.1    | sglancy  | 05/20/14 | initial drop
#ifndef MSS_VOLT_VPP_OFFSET_H_
#define MSS_VOLT_VPP_OFFSET_H_

#include <fapi.H>

#define DRAM_WIDTH_DEFAULT fapi::ENUM_ATTR_SPD_DRAM_WIDTH_W4
#define NUM_RANKS_PER_DIMM_DEFAULT fapi::ENUM_ATTR_SPD_NUM_RANKS_R1 
#define DIMM_SPARE_DEFAULT fapi::ENUM_ATTR_VPD_DIMM_SPARE_FULL_BYTE

typedef fapi::ReturnCode (*mss_volt_vpp_offset_FP_t)(std::vector<fapi::Target> &);

extern "C"
{

/**
 * @brief mss_volt_vpp_offset procedure. Determines operating vpp voltage for dimms behind a vpp voltage domain
 *
 * @param[in]  std::vector<fapi::Target> l_targets  Reference to vector of Centaur Targets in a particular vpp power domain
 *
 * @return ReturnCode
 */

  fapi::ReturnCode mss_volt_vpp_offset(std::vector<fapi::Target> & i_targets);

} // extern "C"

#endif // MSS_VOLT_VPP_OFFSET_H_
