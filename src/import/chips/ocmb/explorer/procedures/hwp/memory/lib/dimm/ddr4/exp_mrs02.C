/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/ddr4/exp_mrs02.C $ */
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
/// @file exp_mrs02.C
/// @brief Run and manage the DDR4 MRS02 loading
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
#include <generic/memory/lib/dimm/ddr4/mrs02.H>
#include <generic/memory/lib/mss_generic_system_attribute_getters.H>

namespace mss
{

namespace ddr4
{

///
/// @brief mrs02_data ctor
/// @param[in] a fapi2::TARGET_TYPE_DIMM target
/// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
mrs02_data<mss::mc_type::EXPLORER>::mrs02_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        fapi2::ReturnCode& o_rc ):
    iv_lpasr(0),
    iv_cwl(0),
    iv_write_crc(0)
{
    const auto l_port_target = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

    FAPI_TRY( mss::attr::get_exp_resp_dram_lpasr(l_port_target, iv_lpasr), "Error in mrs02_data()" );
    FAPI_TRY( mss::attr::get_dram_cwl(l_port_target, iv_cwl), "Error in mrs02_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_dram_rtt_wr(i_target, iv_dram_rtt_wr), "Error in mrs02_data()" );
    FAPI_TRY( mss::attr::get_mrw_dram_write_crc(iv_write_crc), "Error in mrs02_data()" );

    o_rc = fapi2::FAPI2_RC_SUCCESS;
    return;

fapi_try_exit:
    o_rc = fapi2::current_err;
    FAPI_ERR("%s unable to get attributes for mrs02", mss::c_str(i_target));
    return;
}

template<>
fapi2::ReturnCode (*mrs02_data<mss::mc_type::EXPLORER>::make_ccs_instruction)(const
        fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mrs02_data<mss::mc_type::EXPLORER>& i_data,
        ccs::instruction_t& io_inst,
        const uint64_t i_rank) = &mrs02;

template<>
fapi2::ReturnCode (*mrs02_data<mss::mc_type::EXPLORER>::decode)(const ccs::instruction_t& i_inst,
        const uint64_t i_rank) = &mrs02_decode;

} // ns ddr4

} // ns mss
