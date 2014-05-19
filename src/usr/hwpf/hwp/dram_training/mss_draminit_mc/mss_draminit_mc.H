/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_mc/mss_draminit_mc.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: mss_draminit_mc.H,v 1.5 2012/07/17 13:22:39 bellows Exp $
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|   Date:  | Author:  | Comment:
//---------|----------|----------|-----------------------------------------------
//  1.5    | 07/16/12 | bellows  | added in Id tag
//  1.4    | 03/07/12 | jdsloat  | changed target to centaur
//  1.3    | 02/17/12 | jdsloat  | Added the other &
//  1.1    | 02/02/12 | jdsloat  | Added & and description of target type
//  1.0    | 12/08/11 | dcadiga  | First draft.

#ifndef mss_draminit_mc_H_
#define mss_draminit_mc_H_
#include <fapi.H>

typedef fapi::ReturnCode (*mss_draminit_mc_FP_t)(const fapi::Target& target);

extern "C"
{

/**
 * @brief Draminit MC procedure. Enable MC functions and set IML complete within centaur
 *
 * @param[in]  i_target  Reference to centaur target
 *
 * @return ReturnCode
 */

fapi::ReturnCode mss_draminit_mc(const fapi::Target& target);

} // extern "C"

#endif // mss_draminit_mc_H_
