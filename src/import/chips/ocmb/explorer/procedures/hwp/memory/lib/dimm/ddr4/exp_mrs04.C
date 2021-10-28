/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/ddr4/exp_mrs04.C $ */
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
/// @file exp_mrs04.C
/// @brief Run and manage the DDR4 MRS04 loading
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
#include <generic/memory/lib/dimm/ddr4/mrs04.H>
#include <generic/memory/lib/mss_generic_system_attribute_getters.H>

namespace mss
{

namespace ddr4
{

///
/// @brief mrs04_data ctor
/// @param[in] a fapi2::TARGET_TYPE_DIMM target
/// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
mrs04_data<mss::mc_type::EXPLORER>::mrs04_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        fapi2::ReturnCode& o_rc ):
    iv_max_pd_mode(static_cast<uint8_t>(fapi2::ENUM_ATTR_MSS_EXP_RESP_MAX_POWERDOWN_MODE_DISABLE)),
    iv_temp_refresh_range(static_cast<uint8_t>(fapi2::ENUM_ATTR_MSS_MRW_TEMP_REFRESH_RANGE_NORMAL)),
    iv_temp_ref_mode(static_cast<uint8_t>(fapi2::ENUM_ATTR_MSS_MRW_TEMP_REFRESH_MODE_DISABLE)),
    iv_vref_mon(static_cast<uint8_t>(fapi2::ENUM_ATTR_MSS_EXP_RESP_INTERNAL_VREF_MONITOR_DISABLE)),
    iv_cs_cmd_latency(static_cast<uint8_t>(fapi2::ENUM_ATTR_MEM_CS_CMD_LATENCY_DISABLE)),
    iv_ref_abort(static_cast<uint8_t>(fapi2::ENUM_ATTR_MSS_EXP_RESP_SELF_REF_ABORT_DISABLE)),
    iv_rd_pre_train_mode(static_cast<uint8_t>(fapi2::ENUM_ATTR_MSS_EXP_RESP_RD_PREAMBLE_TRAIN_DISABLE)),
    iv_rd_preamble(static_cast<uint8_t>(fapi2::ENUM_ATTR_MSS_EXP_RESP_RD_PREAMBLE_TRAIN_DISABLE)),
    iv_wr_preamble(static_cast<uint8_t>(fapi2::ENUM_ATTR_MSS_EXP_RESP_RD_PREAMBLE_1NCLK)),
    iv_ppr(static_cast<uint8_t>(fapi2::ENUM_ATTR_MEM_EFF_DRAM_PPR_NOT_SUPPORTED)),
    iv_soft_ppr(static_cast<uint8_t>(fapi2::ENUM_ATTR_MEM_EFF_DRAM_SOFT_PPR_NOT_SUPPORTED))
{
    const auto l_port_target = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

    // From DDR4 Spec: 3.3 RESET and Initialization Procedure
    // PPR and soft PPR must be disabled during initialization
    // so we don't call the attribute accessor for them
    FAPI_TRY( mss::attr::get_exp_resp_max_powerdown_mode(l_port_target, iv_max_pd_mode), "Error in mrs04_data()" );
    FAPI_TRY( mss::attr::get_mrw_temp_refresh_range(iv_temp_refresh_range), "Error in mrs04_data()" );
    FAPI_TRY( mss::attr::get_mrw_temp_refresh_mode(iv_temp_ref_mode), "Error in mrs04_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_internal_vref_monitor(l_port_target, iv_vref_mon), "Error in mrs04_data()" );
    FAPI_TRY( mss::attr::get_cs_cmd_latency(i_target, iv_cs_cmd_latency), "Error in mrs04_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_self_ref_abort(l_port_target, iv_ref_abort), "Error in mrs04_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_rd_preamble_train(l_port_target, iv_rd_pre_train_mode), "Error in mrs04_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_rd_preamble(l_port_target, iv_rd_preamble), "Error in mrs04_data()" );
    FAPI_TRY( mss::attr::get_exp_resp_wr_preamble(l_port_target, iv_wr_preamble), "Error in mrs04_data()" );

    FAPI_INF("%s MR4 attributes: MAX_PD: 0x%x, TEMP_REFRESH_RANGE: 0x%x, TEMP_REF_MODE: 0x%x "
             "VREF_MON: 0x%x, CSL: 0x%x, REF_ABORT: 0x%x, RD_PTM: 0x%x, RD_PRE: 0x%x, "
             "WR_PRE: 0x%x, PPR: 0x%x, SOFT PPR: 0x%x",
             mss::c_str(i_target), iv_max_pd_mode, iv_temp_refresh_range, iv_temp_ref_mode, iv_vref_mon,
             iv_cs_cmd_latency, iv_ref_abort,
             iv_rd_pre_train_mode, iv_rd_preamble, iv_wr_preamble, iv_ppr, iv_soft_ppr);

    //Let's make sure the temp_refresh_mode attribute is valid, even though it's mrw, gotta double check spec
    o_rc = fapi2::FAPI2_RC_SUCCESS;
    return;

fapi_try_exit:
    o_rc = fapi2::current_err;
    FAPI_ERR("%s unable to get attributes for mrs04", mss::c_str(i_target));
    return;
}

template<>
fapi2::ReturnCode (*mrs04_data<mss::mc_type::EXPLORER>::make_ccs_instruction)(const
        fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mrs04_data<mss::mc_type::EXPLORER>& i_data,
        ccs::instruction_t& io_inst,
        const uint64_t i_rank) = &mrs04;

template<>
fapi2::ReturnCode (*mrs04_data<mss::mc_type::EXPLORER>::decode)(const ccs::instruction_t& i_inst,
        const uint64_t i_rank) = &mrs04_decode;

} // ns ddr4
} // ns mss
