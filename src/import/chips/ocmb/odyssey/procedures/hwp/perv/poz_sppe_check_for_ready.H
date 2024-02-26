/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/poz_sppe_check_for_ready.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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
/// @file  poz_sppe_check_for_ready.H
/// @brief Confirm that SPPE has reached expected state based on reset/boot type
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Sreekanth Reddy (skadapal@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
//------------------------------------------------------------------------------

#pragma once

#include <fapi2.H>

typedef struct
{
    uint32_t boot_flags;
    uint32_t  max_polls;
    uint64_t poll_delay_cycles;
    uint64_t poll_delay_ns;
} poz_sppe_boot_parms;

/// @brief       Confirm SPPE has reached expected state based on reset/boot type
/// @param[in]   i_target         Reference to TARGET_TYPE_ANY_POZ_CHIP
/// @param[in]   i_boot_parms     Expected SPPE end state, polling guidance
/// @param[in]   i_isHreset       To check Hreset bit is set or not , default is false
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode poz_sppe_check_for_ready(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    const poz_sppe_boot_parms i_boot_parms, const bool i_isHreset = false);
