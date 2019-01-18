/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_setup_ref_clock.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
//------------------------------------------------------------------------------
/// @file  p10_setup_ref_clock.H
///
/// @brief Setup the clock termination correctly for system/chip type
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
// *HWP Consumed by     : FSP
//------------------------------------------------------------------------------

#ifndef _P10_SETUP_REF_CLOCK_H_
#define _P10_SETUP_REF_CLOCK_H_


#include <fapi2.H>

namespace p10SetupRefClock
{
enum P10_SETUP_REF_CLOCK_Public_Constants
{
    DISABLE_WRITE_PROTECTION = 0x4453FFFF,
};
}

typedef fapi2::ReturnCode (*p10_setup_ref_clock_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);


/// @brief Setup the clock termination correctly, since this is the first procedure run against the chips it also clears the GP write protect
/// @return  FAPI2_RC_SUCCESS if success, else error code.
extern "C"
{
    fapi2::ReturnCode p10_setup_ref_clock(const
                                          fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip);
}

#endif
