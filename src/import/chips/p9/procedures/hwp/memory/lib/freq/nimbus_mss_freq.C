/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/freq/nimbus_mss_freq.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file nimbus_mss_freq.C
/// @brief Nimbus specializations for frequency library
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <vpd_access.H>
#include <vector>

// Memory libraries
#include <lib/mss_attribute_accessors.H>
#include <lib/shared/mss_const.H>
#include <lib/freq/nimbus_freq_traits.H>
#include <lib/freq/sync.H>
#include <lib/workarounds/freq_workarounds.H>

// Generic libraries
#include <generic/memory/lib/utils/assert_noexit.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/freq/gen_mss_freq.H>
#include <generic/memory/lib/utils/freq/mss_freq_scoreboard.H>

namespace mss
{

const std::vector< uint64_t > frequency_traits<mss::proc_type::NIMBUS>::SUPPORTED_FREQS =
{
    mss::DIMM_SPEED_1866,
    mss::DIMM_SPEED_2133,
    mss::DIMM_SPEED_2400,
    mss::DIMM_SPEED_2666,
};

///
/// @brief      Sets DRAM CAS latency attributes - specialization for NIMBUS and MCA
/// @param[in]  i_target the controller target the cas_latency value
/// @param[in]  i_cas_latency cas latency to update
/// @return     FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode set_CL_attr<mss::proc_type::NIMBUS>(
    const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
    const uint64_t i_cas_latency)
{
    // I wish I could do the reinterpret cast or set the pointer to the vector :(
    // But no can do, manual copy pasta
    uint8_t l_temp [mss::PORTS_PER_MCS] = {0};

    // Local variable instead of calling it three times. Hopefully compiler can optimize this better
    const auto l_index = mss::index(i_target);
    const auto& l_mcs = mss::find_target<fapi2::TARGET_TYPE_MCS>(i_target);

    if ( l_index >= PORTS_PER_MCS)
    {
        FAPI_ERR("%s mss::index returned a value greater than PORTS_PER_MCS", mss::c_str(i_target) );
        fapi2::Assert(false);
    }

    FAPI_TRY(mss::eff_dram_cl(l_mcs, l_temp), "%s failed to get cas latency attribute", mss::c_str(i_target));

    l_temp[l_index] = i_cas_latency;

    //Check for rounding issues. Going from a uint64_t to a uint8_t
    FAPI_ASSERT( l_temp[l_index] == i_cas_latency,
                 fapi2::MSS_BAD_CL_CAST()
                 .set_CL(i_cas_latency)
                 .set_PORT_TARGET(i_target),
                 "%s bad cast for cas latency from %d to %d",
                 mss::c_str(i_target),
                 i_cas_latency,
                 l_temp[l_index]);

    FAPI_INF( "Final Chosen CL: %d for %s", l_temp[l_index], mss::c_str(i_target));

    // set CAS latency attribute
    // casts vector into the type FAPI_ATTR_SET is expecting by deduction
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_CL,
                            l_mcs,
                            l_temp) ,
              "%s Failed to set CAS latency attribute", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Sets the frequency value - specialization for NIMBUS and MCBIST
/// @param[in]  i_target the target on which to set the frequency values
/// @param[in]  i_freq frequency value to set
/// @return     FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode set_freq<mss::proc_type::NIMBUS>(
    const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
    const uint64_t i_freq)
{
    // Local variable to avoid compile fails - ATTR_SET cannot operate on consts
    auto l_freq = i_freq;
    return FAPI_ATTR_SET(fapi2::ATTR_MSS_FREQ, i_target, l_freq);
}

///
/// @brief      Gets the number of master ranks per DIMM - specialization for NIMBUS and MCA
/// @param[in]  i_target the target on which to get the number of master ranks per DIMM
/// @param[out] o_master_ranks number of master ranks per DIMM
/// @return     FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode get_master_rank_per_dimm<mss::proc_type::NIMBUS>(
    const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
    uint8_t* o_master_ranks)
{
    return mss::eff_num_master_ranks_per_dimm(i_target, o_master_ranks);
}

///
/// @brief Gets the attribute for the maximum - specialization for NIMBUS
/// @param[out] o_allowed_dimm_freq allowed dimm frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode max_allowed_dimm_freq<mss::proc_type::NIMBUS>(uint32_t* o_allowed_dimm_freq)
{
    return mss::max_allowed_dimm_freq(o_allowed_dimm_freq);
}

///
/// @brief      Gets the DIMM type - specialization for NIMBUS and MCA
/// @param[in]  i_target the target on which to get the DIMM types
/// @param[out] o_dimm_type DIMM types
/// @return     FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode get_dimm_type<mss::proc_type::NIMBUS>(
    const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
    uint8_t* o_dimm_type)
{
    return mss::eff_dimm_type(i_target, o_dimm_type);
}

///
/// @brief Calls out the code if we calculated a bad frequency for the domain - specialization for NIMBUS and MCBIST
/// @param[in] i_target target on which to operate
/// @param[in] i_final_freq frequency calculated for domain
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode callout_bad_freq_calculated<mss::proc_type::NIMBUS>(
    const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
    const uint64_t i_final_freq)
{
    using TT = mss::frequency_traits<mss::proc_type::NIMBUS>;

    // Declaring temporary variables to avoid linker errors associated with FAPI_ASSERT
    const auto FREQ0 = TT::SUPPORTED_FREQ0;
    const auto FREQ1 = TT::SUPPORTED_FREQ1;
    const auto FREQ2 = TT::SUPPORTED_FREQ2;
    const auto FREQ3 = TT::SUPPORTED_FREQ3;

    // If we don't find a valid frequency OR don't get a 0 (nothing configured on this clock domain), then error out
    FAPI_ASSERT( std::binary_search(TT::SUPPORTED_FREQS.begin(), TT::SUPPORTED_FREQS.end(), i_final_freq) ||
                 i_final_freq == 0,
                 fapi2::MSS_BAD_FREQ_CALCULATED()
                 .set_MSS_FREQ(i_final_freq)
                 .set_TARGET(i_target)
                 .set_PROC_TYPE(mss::proc_type::NIMBUS)
                 .set_SUPPORTED_FREQ_0(FREQ0)
                 .set_SUPPORTED_FREQ_1(FREQ1)
                 .set_SUPPORTED_FREQ_2(FREQ2)
                 .set_SUPPORTED_FREQ_3(FREQ3),
                 "%s: Calculated FREQ (%d) isn't supported",
                 mss::c_str(i_target),
                 i_final_freq);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configures the number of ranks in the VPD accessor - specialization for Nimbus and MCBIST
/// @param[in] i_target the target on which to set the frequency values
/// @param[in,out] io_vpd_info VPD information that needs to be configured
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode configure_vpd_ranks<mss::proc_type::NIMBUS>(
    const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
    fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS>& io_vpd_info)
{
    using TT = mss::frequency_traits<mss::proc_type::NIMBUS>;

    uint8_t l_rank_count_dimm[TT::MAX_DIMM_PER_PORT] = {};
    uint8_t l_dimm_type[TT::MAX_DIMM_PER_PORT] = {};

    // ATTR to update
    // Note: this flat out assumes that we have two DIMM per port max.
    // This goes against the directive to have arrays be dynamic in length and derived from ATTR's
    FAPI_TRY( get_master_rank_per_dimm<mss::proc_type::NIMBUS>(i_target, &(l_rank_count_dimm[0])) );
    FAPI_TRY( get_dimm_type<mss::proc_type::NIMBUS>(i_target, &(l_dimm_type[0])) );

    // So for LRDIMM, our SI works a bit differently than for non-LRDIMM
    // LRDIMM's have buffers that operate on a per-DIMM basis across multiple ranks
    // As such, they act as a single load, similar to a 1R DIMM would
    // per the IBM signal integrity team, the 1R DIMM settings should be used for LRDIMM's
    // So, if we are LRDIMM's and have ranks, we want to only note it as a 1R DIMM for purposes of querying the VPD
    FAPI_DBG("%s for DIMM 0 rank count %u dimm type %u %s",
             mss::c_str(i_target), l_rank_count_dimm[0], l_dimm_type[0], l_dimm_type[0] == TT::LRDIMM_TYPE ? "LRDIMM" : "RDIMM");
    FAPI_DBG("%s for DIMM 1 rank count %u dimm type %u %s",
             mss::c_str(i_target), l_rank_count_dimm[1], l_dimm_type[1], l_dimm_type[1] == TT::LRDIMM_TYPE ? "LRDIMM" : "RDIMM");

    l_rank_count_dimm[0] = ((l_dimm_type[0] == TT::LRDIMM_TYPE) && (l_rank_count_dimm[0] > 0)) ? 1 : l_rank_count_dimm[0];
    l_rank_count_dimm[1] = ((l_dimm_type[1] == TT::LRDIMM_TYPE) && (l_rank_count_dimm[1] > 0)) ? 1 : l_rank_count_dimm[1];

    FAPI_DBG("after LR modification %s for DIMM 0 rank count %u dimm type %u %s",
             mss::c_str(i_target), l_rank_count_dimm[0], l_dimm_type[0], l_dimm_type[0] == TT::LRDIMM_TYPE ? "LRDIMM" : "RDIMM");
    FAPI_DBG("after LR modification %s for DIMM 1 rank count %u dimm type %u %s",
             mss::c_str(i_target), l_rank_count_dimm[1], l_dimm_type[1], l_dimm_type[1] == TT::LRDIMM_TYPE ? "LRDIMM" : "RDIMM");

    io_vpd_info.iv_rank_count_dimm_0 = l_rank_count_dimm[0];
    io_vpd_info.iv_rank_count_dimm_1 = l_rank_count_dimm[1];

    FAPI_INF("%s. VPD info - rank count for dimm_0: %d, dimm_1: %d",
             mss::c_str(i_target), io_vpd_info.iv_rank_count_dimm_0, io_vpd_info.iv_rank_count_dimm_1);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check VPD config for support of a given freq - specialization for NIMBUS
/// @param[in] i_target the target on which to operate
/// @param[in] i_proposed_freq frequency to check for support
/// @param[out] o_supported true if VPD supports the proposed frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode check_freq_support_vpd<mss::proc_type::NIMBUS>(
    const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
    const uint64_t i_proposed_freq,
    bool& o_supported)
{
    using TT = mss::frequency_traits<mss::proc_type::NIMBUS>;

    o_supported = false;

    fapi2::VPDInfo<TT::VPD_TARGET_TYPE> l_vpd_info(TT::VPD_BLOB);

    const auto& l_vpd_target = mss::find_target<TT::VPD_TARGET_TYPE>(i_target);

    // Configures the number of ranks for the VPD configuration
    FAPI_TRY( configure_vpd_ranks<mss::proc_type::NIMBUS>(i_target, l_vpd_info),
              "%s failed to configure VPD ranks", mss::c_str(i_target));
    l_vpd_info.iv_is_config_ffdc_enabled = false;

    l_vpd_info.iv_freq_mhz = i_proposed_freq;
    FAPI_INF("VPD info - DDR frequency: %d MT/s", i_proposed_freq);

    // Checks if this VPD configuration is supported
    FAPI_TRY(is_vpd_config_supported<mss::proc_type::NIMBUS>(l_vpd_target, i_proposed_freq, l_vpd_info, o_supported),
             "%s failed to determine if %u freq is supported", mss::c_str(i_target), i_proposed_freq);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Update supported frequency scoreboard according to processor limits - specialization for NIMBUS and MCBIST
/// @param[in] i_target processor frequency domain
/// @param[in,out] io_scoreboard scoreboard of port targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode limit_freq_by_processor<mss::proc_type::NIMBUS>(
    const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
    freq_scoreboard& io_scoreboard)
{
    uint8_t l_req_sync_mode = 0;
    FAPI_TRY( mss::required_synch_mode(l_req_sync_mode) );
    FAPI_TRY( limit_freq_by_processor(i_target, l_req_sync_mode == fapi2::ENUM_ATTR_REQUIRED_SYNCH_MODE_ALWAYS,
                                      io_scoreboard) );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets the number of master ranks on each DIMM - specialization for the NIMBUS processor type
/// @param[in] i_target DIMM target
/// @param[out] o_master_ranks number of master ranks
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode num_master_ranks_per_dimm<mss::proc_type::NIMBUS>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
        i_target, uint8_t& o_master_ranks)
{
    return mss::eff_num_master_ranks_per_dimm(i_target, o_master_ranks);
}

///
/// @brief Calls out the target if no DIMM frequencies are supported - specialization for NIMBUS and MCBIST
/// @param[in] i_target target on which to operate
/// @param[in] i_supported_freq true if any FREQ's are supported
/// @param[in,out] io_scoreboard scoreboard of port targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode callout_no_common_freq<mss::proc_type::NIMBUS>(
    const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
    const bool l_supported_freq,
    const uint64_t i_num_ports)
{
    std::vector<uint32_t> l_max_mrw_freqs(NUM_MAX_FREQS, 0);
    uint8_t l_req_sync_mode = 0;
    FAPI_TRY( mss::required_synch_mode(l_req_sync_mode) );
    FAPI_TRY( max_allowed_dimm_freq(l_max_mrw_freqs.data()) );
    {
        const bool l_sync_mode = l_req_sync_mode == fapi2::ENUM_ATTR_REQUIRED_SYNCH_MODE_ALWAYS;
        FAPI_ASSERT(l_supported_freq,
                    fapi2::MSS_NO_SUPPORTED_FREQ()
                    .set_REQUIRED_SYNC_MODE(l_sync_mode)
                    .set_MCBIST_TARGET(i_target)
                    .set_NUM_PORTS(i_num_ports)
                    .set_MRW_MAX_FREQ_0(l_max_mrw_freqs[0])
                    .set_MRW_MAX_FREQ_1(l_max_mrw_freqs[1])
                    .set_MRW_MAX_FREQ_2(l_max_mrw_freqs[2])
                    .set_MRW_MAX_FREQ_3(l_max_mrw_freqs[3])
                    .set_MRW_MAX_FREQ_4(l_max_mrw_freqs[4]),
                    "%s didn't find a frequency that was supported on any ports", mss::c_str(i_target));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calls out the target if no DIMM frequencies are supported - specialization for NIMBUS and MCBIST
/// @param[in] i_target target on which to operate
/// @param[in] i_vpd_supported_freqs VPD supported frequencies for the callout
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode callout_max_freq_empty_set<mss::proc_type::NIMBUS>(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>&
        i_target,
        const std::vector<std::vector<uint32_t>>& i_vpd_supported_freqs)
{

    std::vector<uint32_t> l_port_vpd_max_freq;

    // Get the max freq supported on each port
    for ( const auto& l_port_supported_freqs : i_vpd_supported_freqs )
    {
        l_port_vpd_max_freq.push_back(l_port_supported_freqs.back());
    }

    std::vector<uint32_t> l_max_mrw_freqs(NUM_MAX_FREQS, 0);
    uint8_t l_req_sync_mode = 0;
    FAPI_TRY( mss::required_synch_mode(l_req_sync_mode) );
    FAPI_TRY( max_allowed_dimm_freq(l_max_mrw_freqs.data()) );

    {
        // TK Louis and I will be checking on this - I think we need this to be 4 instead of 8 and will need a mustfix
        const bool l_sync_mode = l_req_sync_mode == fapi2::ENUM_ATTR_REQUIRED_SYNCH_MODE_ALWAYS;
        FAPI_ASSERT(false,
                    fapi2::MSS_MRW_FREQ_MAX_FREQ_EMPTY_SET()
                    .set_MSS_VPD_FREQ_0(l_port_vpd_max_freq[0])
                    .set_MSS_VPD_FREQ_1(l_port_vpd_max_freq[1])
                    .set_MSS_VPD_FREQ_2(l_port_vpd_max_freq[2])
                    .set_MSS_VPD_FREQ_3(l_port_vpd_max_freq[3])
                    .set_MSS_MAX_FREQ_0(l_max_mrw_freqs[0])
                    .set_MSS_MAX_FREQ_1(l_max_mrw_freqs[1])
                    .set_MSS_MAX_FREQ_2(l_max_mrw_freqs[2])
                    .set_MSS_MAX_FREQ_3(l_max_mrw_freqs[3])
                    .set_MSS_MAX_FREQ_4(l_max_mrw_freqs[4])
                    .set_MSS_NEST_FREQ_0(fapi2::ENUM_ATTR_FREQ_PB_MHZ_1600)
                    .set_MSS_NEST_FREQ_1(fapi2::ENUM_ATTR_FREQ_PB_MHZ_1866)
                    .set_MSS_NEST_FREQ_2(fapi2::ENUM_ATTR_FREQ_PB_MHZ_2000)
                    .set_MSS_NEST_FREQ_3(fapi2::ENUM_ATTR_FREQ_PB_MHZ_2133)
                    .set_MSS_NEST_FREQ_4(fapi2::ENUM_ATTR_FREQ_PB_MHZ_2400)
                    .set_REQUIRED_SYNC_MODE(l_sync_mode)
                    .set_MCBIST_TARGET(i_target),
                    "%s didn't find a common frequency for all ports", mss::c_str(i_target));
    }
fapi_try_exit:
    return fapi2::current_err;
}
namespace check
{

///
/// @brief Checks the final frequency for the system type - NIMBUS and MCBIST specialization
/// @param[in] i_target the target on which to operate
/// @return FAPI2_RC_SUCCESS iff okay
///
template<>
fapi2::ReturnCode final_freq<mss::proc_type::NIMBUS>(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target)
{
    uint64_t l_mss_freq = 0;
    uint32_t l_nest_freq = 0;
    FAPI_TRY( mss::freq_pb_mhz(l_nest_freq) );
    FAPI_TRY( mss::freq(i_target, l_mss_freq) );
    FAPI_TRY( mss::workarounds::check_dimm_nest_freq_ratio(i_target, l_mss_freq, l_nest_freq) );

fapi_try_exit:
    return fapi2::current_err;
}

} // ns check

} // ns mss
