/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ccs/ody_ccs_read_processing.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2024                        */
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
/// @file ody_ccs_read_processing.H
/// @brief MCBIST lab data traps for Odyssey
///
// *HWP HWP Owner: Adithi Ganapathi <adithi.t.ganapathi@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <ody_scom_ody_odc.H>
#include <lib/shared/ody_consts.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_traits.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist.H>

namespace mss
{
namespace ccs
{
///
/// @brief Grab the ccs trap data from the maint buffer
/// @param[in] i_target OCMB target on which to operate
/// @param[in] i_address the buffer position to read from
/// @param[out] o_aadr_data the AADR data read from the buffer
/// @param[out] o_aaer_data the AAER data read from the buffer
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode grab_ody_ccs_trap_data( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint64_t i_address,
        fapi2::buffer<uint64_t>& o_aadr_data,
        fapi2::buffer<uint64_t>& o_aaer_data);

///
/// @brief Processes the first spare and ecc data into the beat pair
/// @param[in, out] io_beat_pair processed beat pair data
/// @param[in] i_aaer the aaer data
///
void process_aaer_first(mss::beat_pair& io_beat_pair, const fapi2::buffer<uint64_t>& i_aaer);

///
/// @brief Processes the second spare and ecc data into the beat pair
/// @param[in, out] io_beat_pair processed beat pair data
/// @param[in] i_aaer the aaer data
///
void process_aaer_second(mss::beat_pair& io_beat_pair, const fapi2::buffer<uint64_t>& i_aaer);

///
/// @brief Reads and process the CCS data out of the buffers
/// @param[in] i_target OCMB target on which to operate
/// @param[out] o_data the data read from the buffer
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode prepare_ody_ccs_beat_data(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        mss::pair<uint64_t, uint16_t> (&o_data)[mss::ody::CCS_BEAT_DATA_SIZE]);


///
/// @brief To process and extract the OP code data from individual buffers
/// @param[in] i_dram_number to increment based on dram number
/// @param[in] i_dram_width number of dqs per device type
/// @param[in] i_data processed and assembled data from maint buffer
/// @param[out] o_op_code final op code data
/// @return FAPI2_RC_SUCCSS iff ok
//
fapi2::ReturnCode get_op_code(const uint8_t i_dram_number, const uint8_t i_dram_width,
                              const mss::pair<uint64_t, uint16_t> (&i_data)[mss::ody::CCS_BEAT_DATA_SIZE], uint8_t& o_op_code);

} // namespace ccs
} // namespace mss
