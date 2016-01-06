/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_training/mss_draminit_training.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
// $Id: mss_draminit_training.H,v 1.4 2016/01/06 16:09:54 thi Exp $

//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|   Date:  | Author:  | Comment:
//---------|----------|----------|-----------------------------------------------
//  1.3    | 07/16/12 | bellows | added in Id tag
//  1.1    | 02/20/12 | divyakum | Added target description
//  1.0    | 11/14/11 | divyakum | First draft.

#ifndef mss_draminit_training_H_
#define mss_draminit_training_H_
#include <fapi.H>

typedef fapi::ReturnCode (*mss_draminit_training_FP_t)(const fapi::Target & target );

extern "C"
{

/**
 * @brief Draminit Training procedure. Calibrating DRAMs
 *
 * @param[in]  target  Reference to centaur.mba target
 *
 * @return ReturnCode
 */

fapi::ReturnCode mss_draminit_training(const fapi::Target & target);

} // extern "C"

#endif // mss_draminit_training_H_
