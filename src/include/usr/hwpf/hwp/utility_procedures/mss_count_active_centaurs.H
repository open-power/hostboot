/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/utility_procedures/mss_count_active_centaurs.H $ */
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
// $Id: mss_count_active_centaurs.H,v 1.1 2014/06/16 16:06:27 dcadiga Exp $
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
// Header file for mss_volt.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:   | Comment:
//---------|----------|----------|-----------------------------------------------
//  1.2    | sglancy  | 06/04/14 | Updated to include output attribute
//  1.1    | sglancy  | 05/20/14 | initial drop
#ifndef MSS_COUNT_ACTIVE_CENT_H_
#define MSS_COUNT_ACTIVE_CENT_H_

#include <fapi.H>

typedef fapi::ReturnCode (*mss_count_active_centaurs_FP_t)(std::vector<fapi::Target> & , uint32_t & , uint32_t &);

extern "C"
{

/**
 * @brief mss_count_active_centaurs procedure. Determines operating vpp voltage for dimms behind a voltage domain
 *
 * @param[in]  std::vector<fapi::Target> l_targets  Reference to vector of Centaur Targets
 *             uint32_t & var_num_active_centaur   - number of active centaurs - to be returned out of the function
 *             uint32_t & var_num_inactive_centaur - number of inactive centaurs - to be returned out of the function
 *
 * @return ReturnCode
 */

  fapi::ReturnCode mss_count_active_centaurs(std::vector<fapi::Target> & i_targets, uint32_t & var_num_active_centaur, uint32_t &var_num_inactive_centaur);

} // extern "C"

#endif // MSS_COUNT_ACTIVE_CENT_H_
