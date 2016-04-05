/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_common_poweronoff.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
///
/// @file  p9_common_poweronoff.H
/// @brief common procedure for power on/off
///

// *HWP HWP Owner          : David Du       <daviddu@us.ibm.com>
// *HWP Backup HWP Owner   : Greg Still     <stillgs@us.ibm.com>
// *HWP FW Owner           : Sangeetha T S  <sangeet2@in.ibm.com>
// *HWP Team               : PM
// *HWP Consumed by        : SBE:SGPE:CME
// *HWP Level              : 2

#ifndef __P9_COMMON_POWERONOFF_H__
#define __P9_COMMON_POWERONOFF_H__

#include <fapi2.H>

namespace p9power
{
enum powerOperation_t
{
    POWER_ON      = 0x0,
    POWER_OFF     = 0xFF,
    POWER_ON_VDD  = 0x1,
    POWER_OFF_VDD = 0xFE
};



// For SBE, the initial power-on times are not overly time critical so they are
// hardcoded for the delay necessary when running with the fastest nest (2.4GHz).
// When these same values are used with slower nest frequencies, the delays will
// get longer (more conservative).
//
// For istep 15, the delay settings are computed based on the setting of
// ATTR_FREQ_PB
//
// pfet_delay = (1/nest_frequency_mhz)*1000*4 (PPM clock period in ns) *
//               2^(15-pfet_delay_value).
//
// or
//
//                                                pfet_delay
// 2^(15-pfet_delay_value) =           ------------------------------
//                                     (1/nest_frequency_mhz)*1000*4
//
//                                     pfet_delay * nest_frequency_mhz
// 2^(15-pfet_delay_value  =           ------------------------------
//                                                1000*4
//
//                                    ( pfet_delay * nest_frequency_mhz)
// 15-pfet_delay_value     =      log2(  ------------------------------)
//                                    (             1000*4             )
//
//                                    ( pfet_delay * nest_frequency_mhz)
// pfet_delay_value        = 15 - log2(  ------------------------------)
//                                    (             1000*4             )
//
//            ( pfet_delay * nest_frequency_mhz)
// logexp   = (  ------------------------------)
//            (             1000*4             )
//
//          = pfet_delay * nest_frequency_mhz / (1000 * 4)
//          = pfet_delay * (nest_frequency_mhz / (1000 * 4))
//          = pfet_delay * (2400 / (1000 * 4))
//          = pfet_delay * (.6)
//
// For core delay of 250ns per step, logexp = 250 * .6 = 150
//   --> log2(150) = 8 (rounded up to next integer)
//  -- > pfet_delay_value = 15 - 8 = 7
//
// For EQ delay of 500ns per step, logexp = 500 * .6 = 300
//   --> log2(150) = 9 (rounded up to next integer)
//  -- > pfet_delay_value = 15 - 9 = 6


enum pfetDelays
{
    PFET_DELAY_POWERDOWN_EQ     = 0x1,
    PFET_DELAY_POWERDOWN_CORE   = 0x1,
#ifndef PRODUCT_DEFAULT_PFET_DELAYS
    PFET_DELAY_POWERUP_EQ       = 0x1,
    PFET_DELAY_POWERUP_CORE     = 0x1
#else
    PFET_DELAY_POWERUP_EQ       = 0x6,
    PFET_DELAY_POWERUP_CORE     = 0x7
#endif
};


} // namespace

/// @typedef p9_common_poweronoff_FP_t
/// function pointer typedef definition for HWP call support
/// @todo: consider template solution here
typedef fapi2::ReturnCode (*p9_common_poweronoff_FP_t) (
    const fapi2::Target < fapi2::TARGET_TYPE_EQ |
    fapi2::TARGET_TYPE_CORE > &,
    const p9power::powerOperation_t i_operation);

/// @brief common procedure for power on/off
///
/// @param [in] i_target    TARGET_TYPE_EQ|TARGET_TYPE_CORE target
/// @param [in] i_operation ENUM(ON,OFF)
///
/// @attr
/// @attritem ATTR_PFET_TIMING - EX target, uint32
///
/// @retval FAPI_RC_SUCCESS
template <fapi2::TargetType K>
fapi2::ReturnCode
p9_common_poweronoff(
    const fapi2::Target<K>& i_target,
    const p9power::powerOperation_t i_operation);

#endif  // __P9_COMMON_POWERONOFF_H__
