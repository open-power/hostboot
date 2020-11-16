/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/data_engine/data_engine_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file data_engine_utils.C
/// @brief Data engine to set memory driven data
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: CI
// EKB-Mirror-To: hostboot

#include <generic/memory/lib/data_engine/data_engine_utils.H>

namespace mss
{
namespace pmic
{

///
/// @brief Convert PMIC rail voltage offset from SPD to signed offset for attributes
///
/// @param[in] i_offset - unsigned offset value
/// @param[in] i_direction - direction (0 = positive, 1 = negative)
/// @return int8_t signed equivalent
/// @note Should be used with SPD data where the offset is 7 bits such that overflow could not be possible
///
int8_t convert_to_signed_offset(const uint8_t i_offset, const uint8_t i_direction)
{
    // Offset voltage from spd (+/-)
    static constexpr uint8_t OFFSET_MINUS = 1;

    // Since offset value must be 7 bits (from SPD), we can directly cast it to an int8_t
    int8_t l_signed_offset = static_cast<int8_t>(i_offset);

    if (i_direction == OFFSET_MINUS)
    {
        // Can't overflow since signed_offset was only 7 bits
        l_signed_offset = 0 - l_signed_offset;
    }

    return l_signed_offset;
}

}
}
