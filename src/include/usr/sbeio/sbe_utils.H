/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/sbe_utils.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#ifndef __SBE_UTILS_H
#define __SBE_UTILS_H

#include <targeting/common/commontargeting.H>

/**
 * @file sbe_utils.H
 * @brief Common sbeio utilities for both PSU and FIFO
 */

namespace SBEIO
{

    enum SBE_TARGET_TYPES {
        SBE_TARGET_TYPE_PROC     = 0x00,
        SBE_TARGET_TYPE_EX       = 0x01,
        SBE_TARGET_TYPE_PERV     = 0x02,
        SBE_TARGET_TYPE_MCS      = 0x03,
        SBE_TARGET_TYPE_TOTAL          ,
        SBE_TARGET_TYPE_UNKNOWN  = 0xFF
    };

    /// @brief translates HB target types to SBE target type groups
    /// @param[in] i_hbTarget includes the HB target type
    /// @return SBEIO::SBE_TARGET_TYPES returns SBE_TARGET_TYPE_UNKNOWN in error
    SBE_TARGET_TYPES translateToSBETargetType(TARGETING::Target * i_hbTarget);

    /// @brief returns a ChipletID for a give target
    /// @param[in] i_hbTarget includes the HB target type
    /// @return: ChipletID for i_hbTarget target
    uint8_t getChipletIDForSBE(TARGETING::Target * i_hbTarget);

}

#endif  // __SBE_UTILS_H