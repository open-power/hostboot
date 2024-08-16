/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ody_half_dimm_dqs_track_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2024                        */
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

// EKB-Mirror-To: hostboot

///
/// @file ody_half_dimm_dqs_track_utils.H
/// @brief  Tool to track and recal DQS for half dimm mode
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: SBE

#ifndef _ODY_HALF_DIMM_DQS_TRACK_UTILS_H_
#define _ODY_HALF_DIMM_DQS_TRACK_UTILS_H_

#include <fapi2.H>
#include <lib/dimm/ody_rank.H>
#include <lib/power_thermal/ody_temp_sensor_traits.H>
#include <lib/ccs/ody_ccs.H>
#include <lib/phy/ody_phy_access.H>
#include <ody_scom_mp_dbyte0_b0.H>
#include <ody_scom_mp_apbonly0.H>
#include <ody_scom_ody_odc.H>
#include <ody_dqs_track_utils.H>

namespace mss
{
namespace ody
{

///
/// @brief Checks if the latching FIR is set
/// @param[in] i_data data from the SRQ LFIR register containing the latching FIR (bit 28)
/// @return true if the read queues are empty
///
inline bool is_latching_fir_set(const fapi2::buffer<uint64_t>& i_data)
{
    return i_data.getBit<scomt::ody::ODC_SRQ_LFIR_IN28>();
}

///
/// @brief Checks if the RDF read queues are empty
/// @param[in] i_data data from the FARB6 register containing the read queues
/// @return true if the read queues are empty
///
inline bool are_read_queues_empty(const fapi2::buffer<uint64_t>& i_data)
{
    const bool l_is_port0_empty =
        !i_data.getBit<scomt::ody::ODC_SRQ_MBA_FARB6Q_CFG_ROQ_DEPTH_SIDE0, scomt::ody::ODC_SRQ_MBA_FARB6Q_CFG_ROQ_DEPTH_SIDE0_LEN>();
    const bool l_is_port1_empty =
        !i_data.getBit<scomt::ody::ODC_SRQ_MBA_FARB6Q_CFG_ROQ_DEPTH_SIDE1, scomt::ody::ODC_SRQ_MBA_FARB6Q_CFG_ROQ_DEPTH_SIDE1_LEN>();

    // Bus is quiesced if there are no reads queued
    return l_is_port0_empty && l_is_port1_empty;
}

///
/// @brief Polls to see if the bus has quiesced
/// @param[in] i_target the target on which to operate
/// @param[out] o_is_quiesced true if the bus has quiesced
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode poll_for_quiesced(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target, bool& o_is_quiesced);

///
/// @brief Extracts the drift track MR field out of the DQS tracking target attribute
/// @param[in] i_attr the attribute value
/// @return the rank value extracted from the attribute
///
inline drift_track_mr extract_mr_from_target_attr(const uint8_t i_attr)
{
    return (i_attr & 0x01) == 0 ? drift_track_mr::LSB_MR : drift_track_mr::MSB_MR;
}

///
/// @brief Extracts the rank field out of the DQS tracking target attribute
/// @param[in] i_attr the attribute value
/// @return the rank value extracted from the attribute
///
inline uint8_t extract_rank_from_target_attr(const uint8_t i_attr)
{
    return (i_attr & 0x02) >> 1;
}

///
/// @brief Extracts the channel field out of the DQS tracking target attribute
/// @param[in] i_attr the attribute value
/// @return the channel value extracted from the attribute
///
inline uint8_t extract_channel_from_target_attr(const uint8_t i_attr)
{
    return (i_attr & 0x04) >> 2;
}

///
/// @brief Extracts the port field out of the DQS tracking target attribute
/// @param[in] i_attr the attribute value
/// @return the port value extracted from the attribute
///
inline uint8_t extract_port_from_target_attr(const uint8_t i_attr)
{
    return (i_attr & 0x08) >> 3;
}

///
/// @brief Advances the algorithm to target the next configured port/channel/rank
/// @param[in] i_target the target on which to operate
/// @param[in] i_targets the ports for the target in question
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode next_port_channel_rank_info(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>>& i_ports);

///
/// @brief Gets the port/channel/rank targetting information from the targetting attribute
/// @param[in] i_ports the memory ports on which to operate
/// @param[in] i_attr the attribute value on which to operate
/// @param[out] o_rank_info the rank info containing the port/rank extracted from the targetting attribute
/// @param[out] o_channel the channel extracted from the targetting attribute
/// @param[out] o_mr the drift track MR value on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode get_port_channel_rank_info(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>>& i_ports,
        const uint8_t i_attr,
        mss::rank::info<mss::mc_type::ODYSSEY>& o_rank_info,
        mss::ccs::channel_select& o_channel,
        drift_track_mr& o_mr );

///
/// @brief Sets up the CCS program to run the next iteration of the half-dimm DQS track algorithm
/// @param[in] i_rank_info the rank information class upon which to operate
/// @param[in] i_mr the drift track MR value on which to operate
/// @param[in,out] io_program the program to update
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_ccs_halfdimm_dqs_instructions(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
        const drift_track_mr& i_mr,
        mss::ccs::program<mss::mc_type::ODYSSEY>& io_program );

///
/// @brief Configures the CCS engine to run the next test
/// @param[in] i_target the OCMB chip on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_ccs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Sets up the initial CCS test and the addressing for the cleanup command
/// @param[in] i_target the OCMB chip on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_ccs_initial(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Setsup the CCS array for the next execution
/// @param[in] i_target the OCMB chip on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_ccs_next_run(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Configures the MCBIST and CCS execution for the second run within the chip op
/// @param[in] i_target the OCMB chip on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_mcbist_test(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Execute CCS program in concurrent mode
/// @param[in] i_target the OCMB chip on which to operate
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode execute_half_dimm_concurrent_ccs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Wrapper that checks if the DQS tracking operation has failed. If not, runs the DQS tracking operation
/// @param[in] i_target the OCMB chip on which to operate
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode ody_half_dimm_dqs_track(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

} // namespace ody
} // namespace mss
#endif
