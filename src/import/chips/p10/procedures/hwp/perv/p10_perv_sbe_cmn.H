/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_perv_sbe_cmn.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file  p10_perv_sbe_cmn.H
///
/// @brief Modules for scan 0 and array init
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
// *HWP Consumed by     : FSP
//------------------------------------------------------------------------------

#ifndef _P10_PERV_SBE_CMN_H_
#define _P10_PERV_SBE_CMN_H_


#include <fapi2.H>


fapi2::ReturnCode p10_perv_sbe_cmn_array_init_module(const
        fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_mcast_target,
        const fapi2::buffer<uint16_t> i_regions,
        const fapi2::buffer<uint64_t> i_loop_counter,
        const fapi2::buffer<uint64_t> i_start_abist_match_value);

fapi2::ReturnCode p10_perv_sbe_cmn_scan0_module(const
        fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_mcast_target,
        const fapi2::buffer<uint16_t> i_regions,
        const fapi2::buffer<uint16_t> i_scan_types);

fapi2::ReturnCode p10_perv_sbe_cmn_clock_start_stop(const
        fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_OR > & i_mcast_target,
        const fapi2::buffer<uint8_t> i_clock_cmd,
        const bool i_startslave,
        const bool i_startmaster,
        const fapi2::buffer<uint64_t> i_regions,
        const fapi2::buffer<uint8_t> i_clock_types);

fapi2::ReturnCode p10_perv_sbe_cmn_setup_hangpulse_counters(const
        fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet,
        const uint32_t base_address,
        const uint8_t pre_divider);

fapi2::ReturnCode p10_perv_sbe_cmn_setup_multicast_groups(const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip);

fapi2::ReturnCode p10_perv_sbe_cmn_cplt_status(const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
        uint64_t pgood_option,
        fapi2::buffer<uint64_t>& o_cplt_status_mask);

fapi2::ReturnCode p10_perv_sbe_cmn_align_chiplets(const
        fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_COMPARE > & i_mcast_target);

#endif
