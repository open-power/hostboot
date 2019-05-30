/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/eff_config/explorer_efd_processing.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file explorer_efd_processing.C
/// @brief Processing for EFD for eff config
///

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:CI

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <exp_data_structs.H>
#include <generic/memory/lib/data_engine/data_engine_traits_def.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <generic/memory/lib/spd/spd_facade.H>
#include <mss_explorer_attribute_getters.H>
#include <mss_explorer_attribute_setters.H>
#include <lib/eff_config/explorer_efd_processing.H>

namespace mss
{
namespace exp
{
namespace efd
{

///
/// @brief Processes the CAC delay A side
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode cac_delay_a(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    // Get the data
    uint8_t l_addr_delay_a[DRAMINIT_NUM_ADDR_DELAYS] = {};
    const auto& l_port = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

    FAPI_TRY(mss::attr::get_exp_atxdly_a(l_port, l_addr_delay_a));

    // Update the values
    FAPI_TRY(i_efd_data->cac_delay_a_side_group_0(l_addr_delay_a[0]));
    FAPI_TRY(i_efd_data->cac_delay_a_side_group_1(l_addr_delay_a[1]));
    FAPI_TRY(i_efd_data->cac_delay_a_side_group_2(l_addr_delay_a[2]));
    FAPI_TRY(i_efd_data->cac_delay_a_side_group_3(l_addr_delay_a[3]));
    FAPI_TRY(i_efd_data->cac_delay_a_side_group_4(l_addr_delay_a[4]));
    FAPI_TRY(i_efd_data->cac_delay_a_side_group_5(l_addr_delay_a[5]));
    FAPI_TRY(i_efd_data->cac_delay_a_side_group_6(l_addr_delay_a[6]));
    FAPI_TRY(i_efd_data->cac_delay_a_side_group_7(l_addr_delay_a[7]));

    // Set the attribute
    FAPI_TRY(mss::attr::set_exp_atxdly_a(l_port, l_addr_delay_a));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the CAC delay B side
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode cac_delay_b(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    // Get the data
    uint8_t l_addr_delay_b[DRAMINIT_NUM_ADDR_DELAYS] = {};
    const auto& l_port = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

    FAPI_TRY(mss::attr::get_exp_atxdly_b(l_port, l_addr_delay_b));

    // Update the values
    FAPI_TRY(i_efd_data->cac_delay_b_side_group_0(l_addr_delay_b[0]));
    FAPI_TRY(i_efd_data->cac_delay_b_side_group_1(l_addr_delay_b[1]));
    FAPI_TRY(i_efd_data->cac_delay_b_side_group_2(l_addr_delay_b[2]));
    FAPI_TRY(i_efd_data->cac_delay_b_side_group_3(l_addr_delay_b[3]));
    FAPI_TRY(i_efd_data->cac_delay_b_side_group_4(l_addr_delay_b[4]));
    FAPI_TRY(i_efd_data->cac_delay_b_side_group_5(l_addr_delay_b[5]));
    FAPI_TRY(i_efd_data->cac_delay_b_side_group_6(l_addr_delay_b[6]));
    FAPI_TRY(i_efd_data->cac_delay_b_side_group_7(l_addr_delay_b[7]));

    // Set the attribute
    FAPI_TRY(mss::attr::set_exp_atxdly_b(l_port, l_addr_delay_b));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the Host RD VREF DQ
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode host_rd_vref_dq(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    // Get the data
    uint8_t l_vref = 0;
    const auto& l_port = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

    FAPI_TRY(mss::attr::get_exp_init_vref_dq(l_port, l_vref));

    // Update the values
    FAPI_TRY(i_efd_data->phy_vref_percent(l_vref));

    // Set the attribute
    FAPI_TRY(mss::attr::set_exp_init_vref_dq(l_port, l_vref));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the CS command latency
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode cs_cmd_latency(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    // Get the data
    uint8_t l_cmd_latency = 0;
    FAPI_TRY(mss::attr::get_cs_cmd_latency(i_target, l_cmd_latency));

    // Update the values
    FAPI_TRY(i_efd_data->bist_ca_latency_mode(l_cmd_latency));

    // Set the attribute
    FAPI_TRY(mss::attr::set_cs_cmd_latency(i_target, l_cmd_latency));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the CA parity latency
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode ca_parity_latency(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    // Get the data
    uint8_t l_ca_parity_latency = 0;
    FAPI_TRY(mss::attr::get_ca_parity_latency(i_target, l_ca_parity_latency));

    // Update the values
    FAPI_TRY(i_efd_data->bist_ca_pl_mode(l_ca_parity_latency));

    // Set the attribute
    FAPI_TRY(mss::attr::set_ca_parity_latency(i_target, l_ca_parity_latency));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the DFIMRL_DDRCLK
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode dfimrl_ddrclk(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    // Get the data
    uint8_t l_dfimrl_ddrclk = 0;
    const auto& l_port = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

    FAPI_TRY(mss::attr::get_exp_dfimrl_clk(l_port, l_dfimrl_ddrclk));

    // Update the values
    FAPI_TRY(i_efd_data->dfimrl_ddrclk(l_dfimrl_ddrclk));

    // Set the attribute
    FAPI_TRY(mss::attr::get_exp_dfimrl_clk(l_port, l_dfimrl_ddrclk));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Process the EFD data and set attributes
/// @param[in] i_target DIMM target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode process(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                          const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    FAPI_TRY(host_rd_vref_dq(i_target, i_efd_data));
    FAPI_TRY(cs_cmd_latency(i_target, i_efd_data));
    FAPI_TRY(ca_parity_latency(i_target, i_efd_data));
    FAPI_TRY(dfimrl_ddrclk(i_target, i_efd_data));
    FAPI_TRY(cac_delay_a(i_target, i_efd_data));
    FAPI_TRY(cac_delay_b(i_target, i_efd_data));

fapi_try_exit:
    return fapi2::current_err;
}

} // ns efd
} // ns exp
} // ns mss
