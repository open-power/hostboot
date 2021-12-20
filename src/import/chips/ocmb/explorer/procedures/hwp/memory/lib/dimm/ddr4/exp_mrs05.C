/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/ddr4/exp_mrs05.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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
/// @file exp_mrs05.C
/// @brief Run and manage the DDR4 MRS05 loading
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <lib/ecc/ecc_traits_explorer.H>
#include <lib/dimm/exp_mrs_traits.H>
#include <lib/ccs/ccs_traits_explorer.H>
#include <generic/memory/lib/dimm/ddr4/mrs_load_ddr4.H>
#include <generic/memory/lib/dimm/ddr4/mrs05.H>
#include <mss_generic_system_attribute_getters.H>
#include <mss_generic_attribute_getters.H>
#include <mss_explorer_attribute_getters.H>

using fapi2::TARGET_TYPE_MEM_PORT;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

namespace ddr4
{

///
/// @brief mrs05_data ctor
/// @param[in] a fapi2::TARGET_TYPE_DIMM target
/// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
mrs05_data<mss::mc_type::EXPLORER>::mrs05_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        fapi2::ReturnCode& o_rc ):
    iv_ca_parity_latency(static_cast<uint8_t>(fapi2::ENUM_ATTR_MEM_CA_PARITY_LATENCY_DISABLE)),
    iv_crc_error_clear(static_cast<uint8_t>(fapi2::ENUM_ATTR_MSS_EXP_RESP_CRC_ERROR_CLEAR_CLEAR)),
    iv_ca_parity_error_status(static_cast<uint8_t>(fapi2::ENUM_ATTR_MSS_EXP_RESP_CA_PARITY_ERROR_STATUS_CLEAR)),
    iv_odt_input_buffer(static_cast<uint8_t>(fapi2::ENUM_ATTR_MSS_EXP_RESP_ODT_INPUT_BUFF_DEACTIVATED)),
    iv_ca_parity(static_cast<uint8_t>(fapi2::ENUM_ATTR_MSS_EXP_RESP_CA_PARITY_DISABLE)),
    iv_data_mask(static_cast<uint8_t>(fapi2::ENUM_ATTR_MSS_EXP_RESP_DATA_MASK_DISABLE)),
    iv_write_dbi(static_cast<uint8_t>(fapi2::ENUM_ATTR_MSS_EXP_RESP_WRITE_DBI_DISABLE)),
    iv_read_dbi(static_cast<uint8_t>(fapi2::ENUM_ATTR_MSS_EXP_RESP_READ_DBI_DISABLE))
{
    const auto l_port_target = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

    FAPI_TRY( mss::attr::get_ca_parity_latency(i_target, iv_ca_parity_latency), "Error in mrs05_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_crc_error_clear(l_port_target, iv_crc_error_clear), "Error in mrs05_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_ca_parity_error_status(l_port_target, iv_ca_parity_error_status),
              "Error in mrs05_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_odt_input_buff(l_port_target, iv_odt_input_buffer), "Error in mrs05_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_dram_rtt_park(i_target, iv_rtt_park), "Error in mrs05_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_ca_parity(l_port_target, iv_ca_parity), "Error in mrs05_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_data_mask(l_port_target, iv_data_mask), "Error in mrs05_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_write_dbi(l_port_target, iv_write_dbi), "Error in mrs05_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_read_dbi(l_port_target, iv_read_dbi), "Error in mrs05_data()" );

    o_rc = fapi2::FAPI2_RC_SUCCESS;
    return;

fapi_try_exit:
    o_rc = fapi2::current_err;
    FAPI_ERR("%s unable to get attributes for mrs05", mss::c_str(i_target));
    return;
}

template<>
fapi2::ReturnCode (*mrs05_data<mss::mc_type::EXPLORER>::make_ccs_instruction)(const
        fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mrs05_data<mss::mc_type::EXPLORER>& i_data,
        ccs::instruction_t<mss::mc_type::EXPLORER>& io_inst,
        const uint64_t i_rank) = &mrs05;

template<>
fapi2::ReturnCode (*mrs05_data<mss::mc_type::EXPLORER>::decode)(const ccs::instruction_t<mss::mc_type::EXPLORER>&
        i_inst,
        const uint64_t i_rank) = &mrs05_decode;

} // ns ddr4
} // ns mss
