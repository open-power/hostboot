/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/ddr4/exp_mrs03.C $ */
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
/// @file exp_mrs03.C
/// @brief Run and manage mrs03
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
#include <generic/memory/lib/dimm/ddr4/mrs03.H>
#include <generic/memory/lib/mss_generic_system_attribute_getters.H>

namespace mss
{

namespace ddr4
{

///
/// @brief Helper function to decode CRC WR latency to the MRS value - explorer specialization
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_value the value to be decoded
/// @param[out] o_decode the MRS decoded value
/// @return FAPI2_RC_SUCCESS iff OK
///
template<>
fapi2::ReturnCode crc_wr_latency_helper<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_value,
        fapi2::buffer<uint8_t>& o_decode)
{
    constexpr uint8_t MAX_VALUE = 0b10;
    FAPI_ASSERT( i_value < MAX_VALUE,
                 fapi2::MSS_BAD_MR_PARAMETER()
                 .set_MR_NUMBER(3)
                 .set_PARAMETER(OUTPUT_IMPEDANCE)
                 .set_PARAMETER_VALUE(i_value)
                 .set_DIMM_IN_ERROR(i_target),
                 "Bad value for Write CMD Latency: %d (%s)",
                 i_value,
                 mss::c_str(i_target));

    o_decode = i_value;

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief mrs03_data ctor
/// @param[in] a fapi2::TARGET_TYPE_DIMM target
/// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
mrs03_data<mss::mc_type::EXPLORER>::mrs03_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        fapi2::ReturnCode& o_rc ):
    iv_mpr_mode(fapi2::ENUM_ATTR_MSS_EXP_RESP_MPR_MODE_DISABLE),
    iv_mpr_page(fapi2::ENUM_ATTR_MSS_EXP_RESP_MPR_PAGE_PG0),
    iv_geardown(0),
    iv_pda(fapi2::ENUM_ATTR_MSS_EXP_RESP_PER_DRAM_ACCESS_DISABLE),
    iv_crc_wr_latency(0),
    iv_temp_readout(fapi2::ENUM_ATTR_MSS_EXP_RESP_TEMP_READOUT_DISABLE),
    iv_fine_refresh(0),
    iv_read_format(fapi2::ENUM_ATTR_MSS_EXP_RESP_MPR_RD_FORMAT_SERIAL)
{
    const auto l_port_target = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

    FAPI_TRY( mss::attr::get_exp_resp_mpr_mode(l_port_target, iv_mpr_mode), "Error in mrs03_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_mpr_page(l_port_target, iv_mpr_page), "Error in mrs03_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_geardown_mode(l_port_target, iv_geardown), "Error in mrs03_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_per_dram_access(l_port_target, iv_pda), "Error in mrs03_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_temp_readout(l_port_target, iv_temp_readout), "Error in mrs03_data()" );
    FAPI_TRY( mss::attr::get_mrw_fine_refresh_mode(iv_fine_refresh), "Error in mrs03_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_crc_wr_latency(l_port_target, iv_crc_wr_latency), "Error in mrs03_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_mpr_rd_format(l_port_target, iv_read_format), "Error in mrs03_data()" );

    FAPI_INF("%s MR3 attributes: MPR_MODE: 0x%x, MPR_PAGE: 0x%x, GD: 0x%x, PDA: 0x%x, "
             "TEMP: 0x%x FR: 0x%x, CRC_WL: 0x%x, RF: 0x%x",
             mss::c_str(i_target), iv_mpr_mode, iv_mpr_page, iv_geardown, iv_pda,
             iv_temp_readout, iv_fine_refresh, iv_crc_wr_latency, iv_read_format);

    o_rc = fapi2::FAPI2_RC_SUCCESS;
    return;

fapi_try_exit:
    o_rc = fapi2::current_err;
    FAPI_ERR("%s unable to get attributes for mrs03");
    return;
}

template<>
fapi2::ReturnCode (*mrs03_data<mss::mc_type::EXPLORER>::make_ccs_instruction)(const
        fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mrs03_data<mss::mc_type::EXPLORER>& i_data,
        ccs::instruction_t& io_inst,
        const uint64_t i_rank) = &mrs03;

template<>
fapi2::ReturnCode (*mrs03_data<mss::mc_type::EXPLORER>::decode)(const ccs::instruction_t& i_inst,
        const uint64_t i_rank) = &mrs03_decode;

} // ns ddr4
} // ns mss
