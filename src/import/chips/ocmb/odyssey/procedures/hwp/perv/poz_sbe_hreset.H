/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/poz_sbe_hreset.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
/// @file  poz_sbe_hreset.H
/// @brief Applying hreset for any POZ chip
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Swathips (swathips@in.ibm.com)
// *HWP FW Maintainer   : Amit Tendolkar (amit.tendolkar@in.ibm.com)
//------------------------------------------------------------------------------

#pragma once

#include <fapi2.H>

typedef struct
{
    uint32_t  max_polls;
    uint64_t poll_delay_cycles;
    uint64_t poll_delay_ns;
} poz_sbe_boot_parms;

/// @brief       Applying hreset for Ody chip
/// @param[in]   i_target         Reference to TARGET_TYPE_ANY_POZ_CHIP
/// @param[in]   i_boot_parms     Expected SPPE end state, polling guidance
/// @param[in]   i_use_scom_path  Set it to true to use SCOM Path else cfam path
///// @return  FAPI2_RC_SUCCESS if success, else error code.

fapi2::ReturnCode poz_sbe_hreset(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    const poz_sbe_boot_parms i_boot_parms, bool i_use_scom_path);
