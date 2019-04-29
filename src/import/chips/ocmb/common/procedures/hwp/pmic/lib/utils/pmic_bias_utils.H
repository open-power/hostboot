/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/pmic_bias_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file pmic_bias_utils.H
/// @brief Procedure definition to bias PMIC
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#ifndef __PMIC_BIAS_UTILS_H__
#define __PMIC_BIAS_UTILS_H__

#include <fapi2.H>

namespace mss
{
namespace pmic
{

///
/// @brief Rail settings that the bias procedure can modify
///
enum setting
{
    // We order these by rail in groups of 4 so they match with the rail enums,
    // so the rail can be derived from just a % 4 when we have more settings to change
    SWA_VOLT = 0,
    SWB_VOLT = 1,
    SWC_VOLT = 2,
    SWD_VOLT = 3,
    NO_SETTING = 4,
};

///
/// @brief Different methods of biasing
///
enum unit
{
    NO_UNIT = 0, // default value that we can use for error checking
    VALUE = 1,
    PERCENT = 2,
};

}// pmic
}// mss

#endif
