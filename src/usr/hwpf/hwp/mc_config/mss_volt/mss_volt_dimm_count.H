/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_volt/mss_volt_dimm_count.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
// $Id: mss_volt_dimm_count.H,v 1.1 2015/02/17 19:33:58 pardeik Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_volt_dimm_count.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Michael Pardeik    Email: pardeik@us.ibm.com
// *! BACKUP NAME : Jacob Sloat        Email: jdsloat@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_volt_dimm_count.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:   | Comment:
//---------|----------|----------|-----------------------------------------------
//  1.1    | pardeik  | 02/17/15 | initial drop

#ifndef MSS_VOLT_DIMM_COUNT_H_
#define MSS_VOLT_DIMM_COUNT_H_

#include <fapi.H>

typedef fapi::ReturnCode (*mss_volt_dimm_count_FP_t)(std::vector<fapi::Target> &);

extern "C"
{

/**
 * @brief mss_volt_dimm_count procedure. Determines number of dimms present behind a voltage domain
 *
 * @param[in]  std::vector<fapi::Target> l_targets  Reference to vector of present Centaur Targets in a particular power domain
 *
 * @return ReturnCode
 */

  fapi::ReturnCode mss_volt_dimm_count(std::vector<fapi::Target> & i_targets_memb);

} // extern "C"

#endif // MSS_VOLT_DIMM_COUNT_H_
