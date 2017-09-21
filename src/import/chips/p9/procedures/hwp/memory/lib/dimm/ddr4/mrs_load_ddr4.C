/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/mrs_load_ddr4.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file mrs_load_ddr4.C
/// @brief Run and manage the DDR4 mrs loading
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <mss.H>
#include <lib/dimm/ddr4/mrs_load_ddr4.H>
#include <lib/dimm/ddr4/control_word_ddr4.H>
#include <lib/dimm/ddr4/data_buffer_ddr4.H>
#include <lib/eff_config/timing.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;

using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

///
/// @brief Sets up MRS CCS instructions
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_data the completed MRS data to send
/// @param[in] i_rank the rank to send to
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< >
fapi2::ReturnCode mrs_engine( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const mrs_data<fapi2::TARGET_TYPE_MCBIST>& i_data,
                              const uint64_t i_rank,
                              std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst )
{
    FAPI_TRY( mrs_engine(i_target, i_data, i_rank, i_data.iv_delay, io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to determine whether the A17 is needed
/// @param[in] i_target the DIMM target
/// @param[out] o_is_needed boolean whether A17 should be turned on or off
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Based off of Table 2.8 Proposed DDR4 Full spec update(79-4B) page 28
///
template<>
fapi2::ReturnCode is_a17_needed(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                bool& o_is_needed)
{
    uint8_t l_dram_density = 0;
    uint8_t l_dram_width = 0;

    FAPI_TRY( eff_dram_density( i_target, l_dram_density) );
    FAPI_TRY( eff_dram_width( i_target, l_dram_width) );

    o_is_needed = (l_dram_density == fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_16G
                   && l_dram_width == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4) ?
                  true : false;
    FAPI_INF("%s Turning A17 %s", mss::c_str(i_target), o_is_needed ? "on" : "off" );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to determine whether the A17 is needed
/// @param[in] i_target the MCA target
/// @param[out] o_is_needed boolean whether A17 should be turned on or off
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Based off of Table 2.8 Proposed DDR4 Full spec update(79-4B) page 28
///
template<>
fapi2::ReturnCode is_a17_needed(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                bool& o_is_needed)
{
    // Set this to good in case no dimms and we're running unit tests
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    o_is_needed = false;

    // Loop over the DIMMs and see if A17 is needed for one of them
    // If so, we enable the parity bit in the PHY
    for (const auto& l_dimm : mss::find_targets<TARGET_TYPE_DIMM>(i_target) )
    {
        // Default to not used
        // Using temp because we want to OR the two results together. Don't want the false to overwrite
        bool l_temp = false;
        FAPI_TRY( is_a17_needed( l_dimm, l_temp), "%s Failed to get a17 boolean", mss::c_str(l_dimm) );

        o_is_needed = o_is_needed | l_temp;
    }

fapi_try_exit:
    return fapi2::current_err;
}

namespace ddr4
{

///
/// @brief Perform the mrs_load DDR4 operations - TARGET_TYPE_DIMM specialization
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode mrs_load( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                            std::vector< ccs::instruction_t<TARGET_TYPE_MCBIST> >& io_inst)
{
    FAPI_INF("ddr4::mrs_load %s", mss::c_str(i_target));

    // Doubling tMRD delay to increase margin per lab request
    const size_t DOUBLE_TMRD = 2 * mss::tmrd();
    const size_t DOUBLE_TMOD = 2 * mss::tmod(i_target);

    static const std::vector< mrs_data<TARGET_TYPE_MCBIST> > MRS_DATA =
    {
        // JEDEC ordering of MRS per DDR4 power on sequence
        {  3, mrs03, mrs03_decode, DOUBLE_TMRD  },
        {  6, mrs06, mrs06_decode, DOUBLE_TMRD  },
        {  5, mrs05, mrs05_decode, DOUBLE_TMRD  },
        {  4, mrs04, mrs04_decode, DOUBLE_TMRD  },
        {  2, mrs02, mrs02_decode, DOUBLE_TMRD  },
        {  1, mrs01, mrs01_decode, DOUBLE_TMRD  },
        // We need to wait tmod before zqcl, a non-mrs command
        {  0, mrs00, mrs00_decode, DOUBLE_TMOD },
    };

    std::vector< uint64_t > l_ranks;
    FAPI_TRY( mss::rank::ranks(i_target, l_ranks) );

    // Load MRS
    for (const auto& d : MRS_DATA)
    {
        for (const auto& r : l_ranks)
        {
            FAPI_TRY( mrs_engine(i_target, d, r, io_inst) );
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Maps RTT_WR setting to equivalent RTT_NOM setting
/// Specialization for TARGET_TYPE_DIMM
/// @param[in] i_target a DIMM target
/// @param[in] i_rtt_wr an RTT_WR setting
/// @param[out] o_rtt_nom equivalent RTT_NOM setting
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode rtt_wr_to_rtt_nom_helper(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rtt_wr,
        uint8_t& o_rtt_nom)
{
    switch(i_rtt_wr)
    {
        case RTT_WR_DYNAMIC_ODT_OFF:
        case RTT_WR_HIZ:
            o_rtt_nom = RTT_NOM_DISABLE;
            break;

        case RTT_WR_RZQ_OVER_3:
            o_rtt_nom = RTT_NOM_RZQ_OVER_3;
            break;

        case RTT_WR_RZQ_OVER_2:
            o_rtt_nom = RTT_NOM_RZQ_OVER_2;
            break;

        case RTT_WR_RZQ_OVER_1:
            o_rtt_nom = RTT_NOM_RZQ_OVER_1;
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_RTT_WR_ENCODING().
                         set_RTT_WR(i_rtt_wr).
                         set_DIMM_TARGET(i_target),
                         "Received invalid RTT_WR value: 0x%02x for %s.",
                         i_rtt_wr, mss::c_str(i_target) );
            break;
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Executes CCS instructions to set RTT_WR value into RTT_NOM
/// Specialization for TARGET_TYPE_DIMM
/// @param[in] i_target a DIMM target
/// @param[in] i_rank selected rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode rtt_nom_override(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                   const uint64_t i_rank,
                                   std::vector< ccs::instruction_t<TARGET_TYPE_MCBIST> >& io_inst)
{
    uint8_t l_rtt_nom_override_disable = 0;
    uint8_t l_rtt_wr_value[MAX_RANK_PER_DIMM] = {0};
    uint8_t l_rtt_nom_value[MAX_RANK_PER_DIMM] = {0};

    // eff_dram* attributes use a per-DIMM rank index, so get that
    const auto l_rank_idx = mss::index(i_rank);

    FAPI_TRY( mss::rtt_nom_override_disable(i_target, l_rtt_nom_override_disable) );

    if ( fapi2::ENUM_ATTR_MSS_RTT_NOM_OVERRIDE_DISABLE_YES == l_rtt_nom_override_disable )
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Map RTT_WR settings to RTT_NOM
    FAPI_TRY( mss::eff_dram_rtt_wr(i_target, &(l_rtt_wr_value[0])) );
    FAPI_TRY( rtt_wr_to_rtt_nom_helper(i_target, l_rtt_wr_value[l_rank_idx], l_rtt_nom_value[l_rank_idx]) );

    // Write the override values to RTT_NOM
    FAPI_DBG("Overriding RTT_NOM value to 0x%01x to match original RTT_WR value 0x%01x on rank %d",
             l_rtt_nom_value[l_rank_idx], l_rtt_wr_value[l_rank_idx], i_rank);
    FAPI_TRY( rtt_nom_load(i_target, l_rtt_nom_value, i_rank, io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Executes CCS instructions to disable RTT_WR
/// Specialization for TARGET_TYPE_DIMM
/// @param[in] i_target a DIMM target
/// @param[in] i_rank selected rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode rtt_wr_disable(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                 const uint64_t i_rank,
                                 std::vector< ccs::instruction_t<TARGET_TYPE_MCBIST> >& io_inst)
{
    uint8_t l_rtt_wr_value[MAX_RANK_PER_DIMM] = {0};

    // eff_dram* attributes use a per-DIMM rank index, so get that
    const auto l_rank_idx = mss::index(i_rank);

    // Write RTT_WR setting for the given rank to RTT_WR_DYNAMIC_ODT_OFF
    FAPI_TRY( mss::eff_dram_rtt_wr(i_target, &(l_rtt_wr_value[0])) );
    l_rtt_wr_value[l_rank_idx] = RTT_WR_DYNAMIC_ODT_OFF;

    FAPI_TRY( rtt_wr_load(i_target, l_rtt_wr_value, i_rank, io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Executes CCS instructions to restore original value of RTT_NOM
/// Specialization for TARGET_TYPE_DIMM
/// @param[in] i_target a DIMM target
/// @param[in] i_rank selected rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode rtt_nom_restore(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                  const uint64_t i_rank,
                                  std::vector< ccs::instruction_t<TARGET_TYPE_MCBIST> >& io_inst)
{
    uint8_t l_rtt_nom_override_disable = 0;
    uint8_t l_rtt_nom_value[MAX_RANK_PER_DIMM] = {0};

    FAPI_TRY( mss::rtt_nom_override_disable(i_target, l_rtt_nom_override_disable) );

    if ( fapi2::ENUM_ATTR_MSS_RTT_NOM_OVERRIDE_DISABLE_YES == l_rtt_nom_override_disable )
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Get original RTT_NOM value
    FAPI_TRY( mss::eff_dram_rtt_nom(i_target, &(l_rtt_nom_value[0])) );

    // Write the value to RTT_NOM
    FAPI_TRY( rtt_nom_load(i_target, l_rtt_nom_value, i_rank, io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Executes CCS instructions to restore original value of RTT_WR
/// Specialization for TARGET_TYPE_DIMM
/// @param[in] i_target a DIMM target
/// @param[in] i_rank selected rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode rtt_wr_restore(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                 const uint64_t i_rank,
                                 std::vector< ccs::instruction_t<TARGET_TYPE_MCBIST> >& io_inst)
{
    // Get original RTT_WR value
    uint8_t l_rtt_wr_value[MAX_RANK_PER_DIMM] = {0};
    FAPI_TRY( mss::eff_dram_rtt_wr(i_target, &(l_rtt_wr_value[0])) );

    // Write the value to RTT_WR
    FAPI_TRY( rtt_wr_load(i_target, l_rtt_wr_value, i_rank, io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}

} // ns ddr4
} // ns mss
