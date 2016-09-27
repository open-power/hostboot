/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_sbe_common.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file  p9_sbe_common.H
///
/// @brief Common Modules for SBE
//------------------------------------------------------------------------------
// *HWP HW Owner        : Abhishek Agarwal <abagarw8@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : sunil kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : SBE
//------------------------------------------------------------------------------


#ifndef _P9_SBE_COMMON_H_
#define _P9_SBE_COMMON_H_


#include <fapi2.H>


fapi2::ReturnCode p9_sbe_common_align_chiplets(const
        fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplets);

fapi2::ReturnCode p9_sbe_common_check_cc_status_function(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target,
    const fapi2::buffer<uint8_t> i_clock_cmd,
    const fapi2::buffer<uint16_t> i_regions,
    const fapi2::buffer<uint8_t> i_clock_types);

fapi2::ReturnCode p9_sbe_common_check_status(const fapi2::buffer<uint64_t>
        i_regions,
        const fapi2::buffer<uint64_t> i_clock_status,
        const bool i_reg,
        const fapi2::buffer<uint8_t> i_clock_cmd,
        fapi2::buffer<uint64_t>& o_exp_clock_status);

fapi2::ReturnCode p9_sbe_common_clock_start_allRegions(const
        fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_anychiplet);

fapi2::ReturnCode p9_sbe_common_clock_start_stop(const
        fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target,
        const fapi2::buffer<uint8_t> i_clock_cmd,
        const bool i_startslave,
        const bool i_startmaster,
        const fapi2::buffer<uint64_t> i_regions,
        const fapi2::buffer<uint8_t> i_clock_types);

fapi2::ReturnCode p9_sbe_common_cplt_ctrl_action_function(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet,
    const fapi2::buffer<uint16_t> i_attr_pg);

fapi2::ReturnCode p9_sbe_common_flushmode(const
        fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet);

fapi2::ReturnCode p9_sbe_common_get_pg_vector(const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
        fapi2::buffer<uint64_t>& o_pg_vector);

fapi2::ReturnCode p9_sbe_common_set_scan_ratio(const
        fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplets);

#endif
