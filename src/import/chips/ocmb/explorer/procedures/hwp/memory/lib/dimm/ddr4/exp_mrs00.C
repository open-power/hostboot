/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/ddr4/exp_mrs00.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file exp_mrs00.C
/// @brief Run and manage the DDR4 MRS00 loading
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <lib/shared/exp_defaults.H>
#include <lib/ecc/ecc_traits_explorer.H>
#include <lib/dimm/exp_mrs_traits.H>
#include <lib/ccs/ccs_traits_explorer.H>
#include <generic/memory/lib/dimm/ddr4/mrs_load_ddr4.H>
#include <generic/memory/lib/dimm/ddr4/mrs00.H>

namespace mss
{

namespace ddr4
{

///
/// @brief mrs0_data ctor
/// @param[in] a fapi2::TARGET_TYPE_DIMM target
/// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note Burst Length will always be set to fixed x8 (0)
/// @note Burst Chop (x4) is not supported
///
template<>
mrs00_data<mss::mc_type::EXPLORER>::mrs00_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        fapi2::ReturnCode& o_rc ):
    iv_burst_length(0),
    iv_read_burst_type(fapi2::ENUM_ATTR_MSS_EXP_RESP_DRAM_RBT_SEQUENTIAL),
    iv_dll_reset(fapi2::ENUM_ATTR_MSS_EXP_RESP_DRAM_DLL_RESET_NO),
    iv_test_mode(fapi2::ENUM_ATTR_MSS_EXP_RESP_DRAM_TM_NORMAL),
    iv_write_recovery(0),
    iv_cas_latency(0)
{
    const auto l_port_target = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

    FAPI_TRY( mss::attr::get_exp_resp_dram_rbt(l_port_target, iv_read_burst_type), "Error in mrs00_data()" );
    FAPI_TRY( mss::attr::get_dram_cl(l_port_target, iv_cas_latency), "Error in mrs00_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_dram_dll_reset(l_port_target, iv_dll_reset), "Error in mrs00_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_dram_tm(l_port_target, iv_test_mode), "Error in mrs00_data()" );
    FAPI_TRY( mss::attr::get_dram_twr(l_port_target, iv_write_recovery), "Error in mrs00_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_dram_burst_length(l_port_target, iv_burst_length), "Error in mrs00_data()" );

    FAPI_INF("%s MR0 Attributes: BL: 0x%x, RBT: 0x%x, CL: 0x%x, TM: 0x%x, DLL_RESET: 0x%x, WR: 0x%x",
             mss::c_str(i_target), iv_burst_length, iv_read_burst_type, iv_cas_latency, iv_test_mode, iv_dll_reset,
             iv_write_recovery);

    o_rc = fapi2::FAPI2_RC_SUCCESS;
    return;
fapi_try_exit:
    o_rc = fapi2::current_err;
    FAPI_ERR("%s unable to get attributes for mrs00", mss::c_str(i_target));
    return;
}

template<>
fapi2::ReturnCode (*mrs00_data<mss::mc_type::EXPLORER>::make_ccs_instruction)(const
        fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mrs00_data<mss::mc_type::EXPLORER>& i_data,
        ccs::instruction_t& io_inst,
        const uint64_t i_rank) = &mrs00;

template<>
fapi2::ReturnCode (*mrs00_data<mss::mc_type::EXPLORER>::decode)(const ccs::instruction_t& i_inst,
        const uint64_t i_rank) = &mrs00_decode;

} // ns ddr4

} // ns mss
