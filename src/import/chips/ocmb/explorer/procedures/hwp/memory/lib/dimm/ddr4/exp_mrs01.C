/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/ddr4/exp_mrs01.C $ */
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
/// @file exp_mrs01.C
/// @brief Run and manage the DDR4 MRS01 loading
///
// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <lib/shared/exp_defaults.H>
#include <lib/dimm/exp_mrs_traits.H>
#include <lib/ccs/ccs_traits_explorer.H>
#include <generic/memory/lib/dimm/ddr4/mrs_load_ddr4.H>
#include <generic/memory/lib/dimm/ddr4/mrs01.H>

namespace mss
{

namespace ddr4
{

///
/// @brief Helper function to decode ODIC to the MRS value - explorer specialization
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_odic_value the value to be decoded for ODIC
/// @param[out] o_odic_decode the MRS decoded value for ODIC
/// @return FAPI2_RC_SUCCESS iff OK
///
template<>
fapi2::ReturnCode odic_helper<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_odic_value,
        fapi2::buffer<uint8_t>& o_odic_decode)
{
    constexpr uint8_t MAX_ODIC_VALUE = 0b01;
    FAPI_ASSERT( i_odic_value < MAX_ODIC_VALUE,
                 fapi2::MSS_BAD_MR_PARAMETER()
                 .set_MR_NUMBER(1)
                 .set_PARAMETER(OUTPUT_IMPEDANCE)
                 .set_PARAMETER_VALUE(i_odic_value)
                 .set_DIMM_IN_ERROR(i_target),
                 "Bad value for output driver impedance: %d (%s)",
                 i_odic_value,
                 mss::c_str(i_target));

    o_odic_decode = i_odic_value;

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief mrs01_data ctor
/// @param[in] a fapi2::TARGET_TYPE_DIMM target
/// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
mrs01_data<mss::mc_type::EXPLORER>::mrs01_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        fapi2::ReturnCode& o_rc ):
    iv_dll_enable(fapi2::ENUM_ATTR_MSS_EXP_RESP_DRAM_DLL_ENABLE_ENABLE),
    iv_additive_latency(0),
    iv_wl_enable(0),
    iv_tdqs(0),
    iv_qoff(0)
{
    const auto l_port_target = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

    FAPI_TRY( mss::attr::get_exp_resp_dram_dll_enable(l_port_target, iv_dll_enable),
              "Error in mrs01_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_dram_odic(i_target, iv_odic), "Error in mrs01_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_dram_al(l_port_target, iv_additive_latency), "Error in mrs01_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_dram_wr_lvl_enable(l_port_target, iv_wl_enable),
              "Error in mrs01_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_dram_rtt_nom(i_target, iv_rtt_nom), "Error in mrs01_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_dram_tdqs(l_port_target, iv_tdqs), "Error in mrs01_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_dram_output_buffer(l_port_target, iv_qoff), "Error in mrs01_data()" );

    o_rc = fapi2::FAPI2_RC_SUCCESS;
    return;

fapi_try_exit:
    o_rc = fapi2::current_err;
    FAPI_ERR("%s unable to get attributes for mrs01");
    return;
}

template<>
fapi2::ReturnCode (*mrs01_data<mss::mc_type::EXPLORER>::make_ccs_instruction)(const
        fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mrs01_data<mss::mc_type::EXPLORER>& i_data,
        ccs::instruction_t& io_inst,
        const uint64_t i_rank) = &mrs01;

template<>
fapi2::ReturnCode (*mrs01_data<mss::mc_type::EXPLORER>::decode)(const ccs::instruction_t& i_inst,
        const uint64_t i_rank) = &mrs01_decode;

} // ns ddr4

} // ns mss
