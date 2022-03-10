/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/freq/cas_latency.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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
/// @file cas_latency.H
/// @brief CAS latency class declaration
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_CAS_LATENCY_H_
#define _MSS_CAS_LATENCY_H_

// std lib
#include <map>
#include <memory>
#include <cstdint>

// fapi2
#include <fapi2.H>

// mss generic lib
#include <generic/memory/lib/utils/conversions.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/spd/spd_utils_ddr4.H>
#include <generic/memory/lib/spd/spd_fields_ddr4.H>
#include <generic/memory/lib/spd/spd_utils_ddr5.H>
#include <generic/memory/lib/spd/spd_fields_ddr5.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/utils/count_dimm.H>

namespace mss
{

// I choose enumerations over boolean because I feel
// it makes the interface clearer than could be depicted
// by 'true' and 'false' alone.
enum class loading : size_t
{
    NOT_3DS,
    IS_3DS,
};

enum freq_select : uint8_t
{
    BIN_DOWN, ///< option to bin down frequency
    HIGHEST_COMMON ///< option to find highest common freq w/o bin down - useful for testing
};

///
/// @brief Returns the iterator if a given freq is found
/// @tparam T the freq_select type
/// @param[in] i_supported_freqs a vector of sorted frequences
/// @param[im] i_dimm_freq current dimm speed
/// @return FAPI2_RC_SUCESS iff okay
///
template< freq_select T >
static inline std::vector<uint32_t>::const_iterator search_list( const std::vector<uint32_t>& i_supported_freqs,
        const uint32_t i_dimm_freq);

///
/// @brief Returns the iterator if a given freq is found - BIN_DOWN specialization
/// @param[in] i_supported_freqs a vector of sorted frequences
/// @param[in] i_dimm_freq current dimm speed
/// @return FAPI2_RC_SUCESS iff okay
///
template< >
inline std::vector<uint32_t>::const_iterator search_list<BIN_DOWN>( const std::vector<uint32_t>& i_supported_freqs,
        const uint32_t i_dimm_freq)
{
    return std::lower_bound(i_supported_freqs.begin(), i_supported_freqs.end(), i_dimm_freq);
}

///
/// @brief Returns the iterator if a given freq is found - HIGHEST_COMMON specialization
/// @param[in] i_supported_freqs a vector of sorted frequences
/// param[in] i_dimm_freq current dimm speed
/// @return FAPI2_RC_SUCESS iff okay
///
template< >
inline std::vector<uint32_t>::const_iterator search_list<HIGHEST_COMMON>( const std::vector<uint32_t>&
        i_supported_freqs,
        const uint32_t i_dimm_freq)
{
    return std::upper_bound(i_supported_freqs.begin(), i_supported_freqs.end(), i_dimm_freq);
}

///
/// @brief Traits based upon the memory controller type for allowed frequencies
/// @tparam MC Memory Controller type
/// @note Given that one target type can have multiple controllers associated with it (DIMM, OCMB, MEMPORT, etc) MC is used to differentiate the controller type rather than target type
/// We need to be able to distinguish between the MC types to determine the supported set of frequencies. We also use the MC type to derive what target type to use.
///
template <mc_type MC>
class CasLatencyTraits
{};

///
/// @brief Traits based upon the memory controller type for allowed frequencies - specialization for EXPLORER
///
template <>
class CasLatencyTraits<mc_type::EXPLORER>
{
    public:
        static constexpr fapi2::TargetType TARGET_TYPE = fapi2::TARGET_TYPE_MEM_PORT;
        static const std::vector<uint32_t> SUPPORTED_FREQS;
        static constexpr const char* MC_STR = "EXPLORER";
        static constexpr uint8_t SPD_CL_FIRST_BYTE = 20;
        static constexpr uint8_t SPD_NUM_CL_BYTES = 4;
};

///
/// @brief Traits based upon the memory controller type for allowed frequencies - specialization for ODYSSEY
///
template <>
class CasLatencyTraits<mc_type::ODYSSEY>
{
    public:
        static constexpr fapi2::TargetType TARGET_TYPE = fapi2::TARGET_TYPE_MEM_PORT;
        static const std::vector<uint32_t> SUPPORTED_FREQS;
        static constexpr const char* MC_STR = "ODYSSEY";
        static constexpr uint8_t SPD_CL_FIRST_BYTE = 24;
        static constexpr uint8_t SPD_NUM_CL_BYTES = 5;
};

///
/// @brief CAS latency class that encapsulates JEDEC calculation algorithm
/// @tparam MC the memory controller type
/// @tparam TT the CasLatencyTraits - defaulted to be the traits associated with the MC
///
template<mss::mc_type MC, typename TT = CasLatencyTraits<MC>>
class cas_latency
{};

///
/// @brief CAS latency class that encapsulates JEDEC calculation algorithm - EXPLORER (DDR4) specialization
/// @note Using spd::c_str as the frequency isn't setup yet, and that might be required for c_str prints
///
template<>
class cas_latency<mss::mc_type::EXPLORER>
{
        using TT = CasLatencyTraits<mss::mc_type::EXPLORER>;

    public:
        bool iv_dimm_list_empty;

        /////////////////////////
        // Public Member Methods
        /////////////////////////

        // Default constructor
        // class dependent on SPD data obtained internally
        // won't work when instantiated w/o neccesary params
        cas_latency() = delete;

        ///
        /// @brief Class constructor that retrieves required SPD data held by internal state
        /// @param[in] i_target the controller target
        /// @param[in] i_supported_freqs vector of supported frequencies
        /// @param[out] o_rc returns FAPI2_RC_SUCCESS if constructor initialzed successfully
        ///
        cas_latency(const fapi2::Target<TT::TARGET_TYPE>& i_target,
                    const std::vector<uint32_t>& i_supported_freqs,
                    fapi2::ReturnCode& o_rc):
            iv_dimm_list_empty(false),
            iv_target(i_target),
            iv_largest_taamin(0),
            iv_proposed_tck(0),
            iv_common_cl_bitmap(UINT64_MAX),
            iv_supported_freqs(i_supported_freqs)
        {
            o_rc = fapi2::FAPI2_RC_SUCCESS;

            if (mss::count_dimm(i_target) == 0)
            {
                FAPI_INF("cas latency ctor seeing no DIMMs on %s", mss::spd::c_str(i_target) );
                iv_dimm_list_empty = true;
                return;
            }

            for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
            {
                std::vector<uint8_t> l_spd;
                FAPI_TRY(mss::spd::get_raw_data(l_dimm, l_spd));
                FAPI_TRY(cas_latency_ctr_helper(l_dimm, l_spd));
            } // per dimm

            // Why didn't I encapsulate common CL operations and checking in a function
            // like the timing params? Well, I want to check the "final" common CL and
            // the creation of common CLs (bitwise ANDING) is at the dimm level operation
            FAPI_ASSERT(iv_common_cl_bitmap != 0,
                        fapi2::MSS_FREQ_NO_COMMON_SUPPORTED_CL().
                        set_MC_TYPE(mss::mc_type::EXPLORER).
                        set_CL_SUPPORTED(iv_common_cl_bitmap).
                        set_PORT_TARGET(iv_target),
                        "%s. MC type: %s No common CAS latencies (CL bitmap = 0)",
                        mss::spd::c_str(iv_target), TT::MC_STR );

            FAPI_INF("Largest tAAmin (ps): %d, tCKmin (ps): %d, and supported CL bitmap 0x%llX for all modules across %s",
                     iv_largest_taamin, iv_proposed_tck, iv_common_cl_bitmap, mss::spd::c_str(iv_target));

            iv_common_cl = integral_bitmap_to_vector(iv_common_cl_bitmap);

        fapi_try_exit:
            o_rc = fapi2::current_err;
            return;
        }// ctor

        ///
        /// @brief Constructor that allows the user to set desired data in lieu of SPD - helpful for testing
        /// @param[in] i_target the controller target
        /// @param[in] i_taa_min largest tAAmin we want to set in picoseconds
        /// @param[in] i_trcd_min largest tRCDmin we want to set in picoseconds
        /// @param[in] i_tck_min proposed tCKmin in picoseconds
        /// @param[in] i_common_cl_mask common CAS latency mask we want to use (bitmap)
        /// @param[in] i_is_3ds loading::IS_3DS if this is for 3DS, loading::NOT_3DS otherwise
        /// @param[in] i_supported_freqs vector of supported frequencies - defaulted to the traits supported frequencies
        ///
        cas_latency(const fapi2::Target<TT::TARGET_TYPE>& i_target,
                    const uint64_t i_taa_min,
                    const uint64_t i_trcd_min,
                    const uint64_t i_tck_min,
                    const uint64_t i_common_cl_mask,
                    const loading i_is_3ds,
                    const std::vector<uint32_t>& i_supported_freqs = TT::SUPPORTED_FREQS):
            iv_dimm_list_empty(false),
            iv_target(i_target),
            iv_largest_taamin(i_taa_min),
            iv_proposed_tck(i_tck_min),
            iv_is_3ds(i_is_3ds),
            iv_common_cl_bitmap(i_common_cl_mask),
            iv_supported_freqs(i_supported_freqs)
        {
            const auto l_dimm_list = find_targets<fapi2::TARGET_TYPE_DIMM>(iv_target);

            if(l_dimm_list.empty())
            {
                FAPI_INF("cas latency ctor seeing no DIMM on %s", mss::spd::c_str(iv_target));
                iv_dimm_list_empty = true;
            }

            iv_common_cl = integral_bitmap_to_vector(iv_common_cl_bitmap);
        }

        ///
        /// @brief Default destructor
        ///
        ~cas_latency() = default;

        ///
        /// @brief Helper function for CAS Latency constructor, unit testable
        ///
        /// @param[in] i_dimm DIMM target
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        fapi2::ReturnCode cas_latency_ctr_helper(
            const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
            const std::vector<uint8_t>& i_spd)
        {
            using F = mss::spd::fields<mss::spd::device_type::DDR4, mss::spd::module_params::BASE_CNFG>;
            // Retrieve timing values from the SPD
            uint64_t l_taa_min_in_ps = 0;
            uint64_t l_tckmax_in_ps = 0;
            uint64_t l_tck_min_in_ps = 0;

            const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_dimm);
            const auto& l_port = mss::find_target<TT::TARGET_TYPE>(i_dimm);

            FAPI_TRY( get_taamin(i_dimm, i_spd, l_taa_min_in_ps),
                      "%s. Failed to get tAAmin", mss::spd::c_str(i_dimm) );
            FAPI_TRY( spd::ddr4::get_tckmax(i_dimm, i_spd, l_tckmax_in_ps),
                      "%s. Failed to get tCKmax", mss::spd::c_str(i_dimm) );
            FAPI_TRY( spd::ddr4::get_tckmin(i_dimm, i_spd, l_tck_min_in_ps),
                      "%s. Failed to get tCKmin", mss::spd::c_str(i_dimm) );

            // Determine largest tAAmin value
            iv_largest_taamin = std::max(iv_largest_taamin, l_taa_min_in_ps);

            // Determine a proposed tCK value that is greater than or equal tCKmin
            // But less than tCKmax
            iv_proposed_tck = std::max(iv_proposed_tck, l_tck_min_in_ps);
            iv_proposed_tck = std::min(iv_proposed_tck, l_tckmax_in_ps);

            // Collecting stack type
            // If I have at least one 3DS DIMM connected I have
            // to use 3DS tAAmax of 21.5 ps versus 18 ps for non-3DS DDR4
            // iv_is_3ds isn't setup until below. how is this not a bug??
            // if( iv_is_3ds != loading::IS_3DS)
            {
                uint8_t l_stack_type = 0;
                FAPI_TRY(mss::spd::get_field_spd(l_ocmb, F::PRIM_SIGNAL_LOADING, i_spd, SET_PRIM_STACK_TYPE, l_stack_type));

                // Is there a more algorithmic efficient approach? - AAM
                iv_is_3ds = (l_stack_type == fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_3DS) ?
                            loading::IS_3DS : loading::NOT_3DS;
            }

            {
                // Retrieve dimm supported cas latencies from SPD
                uint32_t l_dimm_supported_cl = 0;

                // Rev is already populated from pre-init fields
                uint8_t l_rev = 0;
                FAPI_TRY(mss::attr::get_spd_revision(l_port, l_rev));

                // TK get real rev
                FAPI_TRY( mss::gen::ddr4::get_supported_cas_latencies(i_dimm,
                          i_spd,
                          static_cast<mss::spd::rev>(l_rev),
                          l_dimm_supported_cl),
                          "%s. Failed to get supported CAS latency", mss::spd::c_str(i_dimm) );

                // Bitwise ANDING the bitmap from all modules creates a bitmap w/a common CL
                iv_common_cl_bitmap &= l_dimm_supported_cl;
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Calculates CAS latency and checks if it is supported and within JEDEC spec.
        /// @param[out] o_cas_latency selected CAS latency
        /// @param[out] o_tck cycle time corresponding to seleted CAS latency
        /// @return fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode find_cl(uint64_t& o_cas_latency,
                                  uint64_t& o_tck)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

            // note: iv_common_cl is sorted in increasing order
            const uint64_t l_max_cl = iv_common_cl.back();
            const uint64_t l_min_cl = *iv_common_cl.begin();

            bool l_is_cl_in_common = false;
            bool l_is_cl_exceeding_taa = true;
            uint64_t l_desired_cas_latency = 0;
            bool l_is_1st_iteration = true;

            if(iv_dimm_list_empty)
            {
                // If the inputted target has no dimm configured then both
                // CAS latency and tCK are safe as 0's
                o_cas_latency = 0;
                o_tck = 0;
                return fapi2::FAPI2_RC_SUCCESS;
            }

            while(!l_is_cl_in_common && l_is_cl_exceeding_taa)
            {
                if( l_is_1st_iteration )
                {
                    // Our first run should try to run the highest common supported freq.
                    // If we don't meet JEDEC requirements then every iteration afterwards
                    // will bin down
                    l_is_1st_iteration = false;
                    FAPI_TRY( apply_freq_constraints<HIGHEST_COMMON>(iv_proposed_tck) );
                }
                else
                {
                    // Limit tCK from system constraints such as supported VPD for the system
                    // as well as MRW frequency overrides, if enabled. This guy will bin freq down until
                    // we can't and then we fail out, prevents infinite loop when raising tCK
                    FAPI_TRY( apply_freq_constraints<BIN_DOWN>(iv_proposed_tck) );
                }

                // For a proposed tCK value between tCKmin(all) and tCKmax, determine the desired CAS Latency.
                FAPI_TRY( calc_cas_latency(iv_largest_taamin, iv_proposed_tck, l_desired_cas_latency),
                          "%s. Failed to calculate CAS latency", mss::spd::c_str(iv_target) );

                // Choose an actual CAS Latency (CLactual) that is greater than or equal to CLdesired
                // and is supported by all modules on the memory channel
                l_is_cl_in_common = is_cl_supported_in_common(iv_common_cl, l_desired_cas_latency);

                while( !l_is_cl_in_common && (l_desired_cas_latency < l_max_cl) )
                {
                    ++l_desired_cas_latency;
                    l_is_cl_in_common = is_cl_supported_in_common(iv_common_cl, l_desired_cas_latency);

                }

                // If no such value exists, choose a higher tCKproposed value and repeat until a solution is found.
                if(!l_is_cl_in_common)
                {
                    FAPI_INF("%s Desired CL isn't supported by all DIMMs, choosing a higher tCK", mss::spd::c_str(iv_target));
                    continue;
                }

                // Once the calculation of CLactual is completed
                // verify that this CAS Latency value does not exceed tAAmax.
                l_is_cl_exceeding_taa = is_cl_exceeding_taa_max (l_desired_cas_latency, iv_proposed_tck);

                // If not, choose a lower CL value and repeat until a solution is found.
                while( l_is_cl_exceeding_taa && (l_desired_cas_latency > l_min_cl) )
                {
                    --l_desired_cas_latency;
                    l_is_cl_exceeding_taa = is_cl_exceeding_taa_max (l_desired_cas_latency, iv_proposed_tck);
                }

                l_is_cl_in_common = is_cl_supported_in_common(iv_common_cl, l_desired_cas_latency);

            }// end while

            FAPI_ASSERT( !l_is_cl_exceeding_taa,
                         fapi2::MSS_FREQ_CL_EXCEEDS_TAA_MAX()
                         .set_CAS_LATENCY(l_desired_cas_latency)
                         .set_TCK(iv_proposed_tck)
                         .set_COMPARE(l_desired_cas_latency * iv_proposed_tck)
                         .set_TAA_MAX(iv_largest_taamin)
                         .set_IS_3DS(iv_is_3ds)
                         .set_PORT_TARGET(iv_target)
                         .set_MC_TYPE(mss::mc_type::EXPLORER),
                         "%s: mc_type: %s Calculated Cas Latency (CL %d * tCK %d) exceeds JEDEC value of tAAmax %d",
                         mss::spd::c_str(iv_target), TT::MC_STR,
                         l_desired_cas_latency, iv_proposed_tck, iv_largest_taamin);

            // If the cas_latency wasn't found, we return an error
            // Passing in timing values which were used to calculated i_cas_latency for extra info
            // iv_common_cl contains all of the valid cas latencies that populate the input vector
            FAPI_ASSERT( l_is_cl_in_common,
                         fapi2::MSS_FREQ_FAILED_TO_FIND_SUPPORTED_CL()
                         .set_DESIRED_CAS_LATENCY(l_desired_cas_latency)
                         .set_TAA(iv_largest_taamin)
                         .set_TCK(iv_proposed_tck)
                         .set_COMMON_CLS(iv_common_cl_bitmap)
                         .set_PORT_TARGET(iv_target)
                         .set_MC_TYPE(mss::mc_type::EXPLORER),
                         "%s. mc_type %s Failed to find a common CAS latency supported among all modules"
                         "Desired %d, common CL's %016lx",
                         mss::spd::c_str(iv_target),
                         TT::MC_STR,
                         l_desired_cas_latency,
                         iv_common_cl_bitmap);

            // Update output values after all criteria is met
            o_cas_latency = l_desired_cas_latency;
            o_tck = iv_proposed_tck;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Selects DIMM frequency to run based on supported system frequencies -- helper function for testing
        /// @tparam F the freq_select type
        /// @param[in] i_supported_freqs vector supported frequencies
        /// @param[in,out] io_dimm_freq input is current dimm freq & output is next
        /// @return FAPI2_RC_SUCCESS iff ok
        /// @note Frequency values obtained from:
        /// @note From P9 User's Manual Version 0.8 - June 08, 2015
        /// @note Memory Controller Unit - page 199 of 456
        ///
        template< freq_select F >
        inline fapi2::ReturnCode select_supported_freq_helper( const std::vector<uint32_t>& i_supported_freqs,
                uint64_t& io_dimm_freq)
        {
            FAPI_ASSERT( !i_supported_freqs.empty(),
                         fapi2::MSS_EMPTY_VECTOR().
                         set_FUNCTION(SELECT_SUPPORTED_FREQ).
                         set_TARGET(iv_target),
                         "Empty supported frequency vector received for %s",
                         mss::spd::c_str(iv_target));

            for( const auto& freq : i_supported_freqs )
            {
                FAPI_DBG("Supported freqs taking into account VPD, SPD, & MRW constraints %d for %s", freq,
                         mss::spd::c_str(iv_target) );
            }

            FAPI_DBG("Input frequency %d for %s", io_dimm_freq, mss::spd::c_str(iv_target) );
            {
                auto l_iterator = search_list<F>(i_supported_freqs, io_dimm_freq);

                // Doing this because the HB compiler freaks out if we have it within the FAPI_ASSERT.
                // Outputting the value and then incrementing the iterator, that's why it's a post increment
                // We have at most 4 memory freqs, if we ever get a list with < 4 items
                // a value of 0 is logged in FFDC once we hit i_supported_freqs.end()...which is better than no logging.
                auto l_supported = i_supported_freqs.begin();

                const auto l_freq0 = (l_supported != i_supported_freqs.end()) ? *(l_supported++) : 0;
                const auto l_freq1 = (l_supported != i_supported_freqs.end()) ? *(l_supported++) : 0;
                const auto l_freq2 = (l_supported != i_supported_freqs.end()) ? *(l_supported++) : 0;
                const auto l_freq3 = (l_supported != i_supported_freqs.end()) ? *(l_supported++) : 0;

                // We can't choose a lower freq than the 1st element of this vector,
                // hitting this case means that we exhausted all possible frequencies
                FAPI_ASSERT( l_iterator != i_supported_freqs.begin(),
                             fapi2::MSS_FREQ_SELECTED_FREQ_NOT_SUPPORTED()
                             .set_FREQ(io_dimm_freq)
                             .set_SUPPORTED_FREQ_0( l_freq0 )
                             .set_SUPPORTED_FREQ_1( l_freq1 )
                             .set_SUPPORTED_FREQ_2( l_freq2 )
                             .set_SUPPORTED_FREQ_3( l_freq3 )
                             .set_TARGET(iv_target)
                             .set_MC_TYPE(mss::mc_type::EXPLORER),
                             "%s mc_type: %s Error finding selected freq (%d) from list",
                             mss::spd::c_str(iv_target),
                             TT::MC_STR,
                             io_dimm_freq );

                // Lower bound checks for greater than or equal to input freq,
                // we decrement to get the next lowest freq
                io_dimm_freq = *(--l_iterator);

                FAPI_DBG("Output frequency %d for %s", io_dimm_freq, mss::spd::c_str(iv_target) );
            }

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }

    private:

        enum
        {
            // From JEDEC Standard No. 79-4A
            // Speed Bins pg. 164
            /// Time in picoseconds
            TAA_MAX_DDR4 = 18000,

            // From JEDEC Standard No. 79-4 3DS
            // Speed Bins pg. 135
            /// Time in picoseconds
            TAA_MAX_DDR4_3DS = 21500,

            // Low range CAS latency from SPD
            LOW_RANGE_MIN_CL_DDR4 = 7,
            LOW_RANGE_MAX_CL_DDR4 = 36,

            // High range CAS latency SPD
            HIGH_RANGE_MIN_CL_DDR4 = 23,
            HIGH_RANGE_MAX_CL_DDR4 = 52,

            CAS_LAT_RANGE_BIT = 31,
        };

        /////////////////////////
        // Private variables
        /////////////////////////
        fapi2::Target<TT::TARGET_TYPE> iv_target;
        uint64_t iv_largest_taamin;// cas latency time
        uint64_t iv_proposed_tck;// cycle time
        loading iv_is_3ds;
        uint64_t iv_common_cl_bitmap;
        bool iv_enable_freq_overrides;
        std::vector<uint64_t> iv_common_cl; // common cas latency
        std::vector<uint32_t> iv_supported_freqs;

        ///
        /// @brief Retrieves SDRAM Minimum CAS Latency Time (tAAmin) from SPD
        /// @param[in] i_dimm DIMM target
        /// @param[in] i_spd SPD binary
        /// @param[out] o_value tCKmin value in ps
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode get_taamin(
            const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
            const std::vector<uint8_t>& i_spd,
            uint64_t& o_value)
        {
            using F = mss::spd::fields<mss::spd::device_type::DDR4, mss::spd::module_params::BASE_CNFG>;

            uint8_t l_timing_ftb = 0;
            uint8_t l_timing_mtb = 0;
            uint8_t l_medium_timebase = 0;
            uint8_t l_fine_timebase = 0;
            int64_t l_temp = 0;

            // Retrieve timing parameters
            const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_dimm);

            FAPI_TRY( spd::ddr4::get_timebases(l_ocmb, i_spd, l_medium_timebase, l_fine_timebase),
                      "%s. Failed Failed get_timebases",  mss::spd::c_str(i_dimm) );

            FAPI_TRY(spd::get_field_spd(l_ocmb, F::TAA_MIN, i_spd, GET_TAAMIN, l_timing_mtb));
            FAPI_TRY(spd::get_field_spd(l_ocmb, F::OFFSET_TAA_MIN, i_spd, GET_TAAMIN, l_timing_ftb));

            // Calculate timing value
            l_temp = spd::ddr4::calc_timing_from_timebase(l_timing_mtb,
                     l_medium_timebase,
                     l_timing_ftb,
                     l_fine_timebase);

            // Sanity check
            FAPI_ASSERT(l_temp > 0,
                        fapi2::MSS_INVALID_TIMING_VALUE().
                        set_VALUE(l_temp).
                        set_FUNCTION(GET_TAAMIN).
                        set_DIMM_TARGET(i_dimm),
                        "%s. tAAmin invalid (<= 0) : %d",
                        mss::spd::c_str(i_dimm),
                        l_temp);

            o_value = l_temp;
            FAPI_DBG( "%s. tAAmin (ps): %d",
                      mss::spd::c_str(i_dimm),
                      o_value);

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Gets max CAS latency (CL) for the appropriate High/Low Range
        /// @param[in] i_supported_cl
        /// @return the maximum supported CL
        /// @note Depends on bit 7 of byte 23 from the DDR4 SPD
        ///
        uint64_t get_max_cl(const fapi2::buffer<uint64_t> i_supported_cl) const
        {
            // If the last of Byte 23 of the SPD is 1, this selects CL values
            // in the High CL range (23 to 52)

            // If the last bit of Byte 23 of the SPD is 0, this selects CL values
            // in the Low CL range (7 to 36)
            //Assuming bitmap is right aligned
            return i_supported_cl.getBit<CAS_LAT_RANGE_BIT>() ? HIGH_RANGE_MAX_CL_DDR4 : LOW_RANGE_MAX_CL_DDR4;
        }

        ///
        /// @brief Gets min CAS latency (CL) for the appropriate High/Low Range
        /// @param[in] i_supported_cl
        /// @return the minimum supported CL
        /// @note Depends on bit 7 of byte 23 from the DDR4 SPD
        ///
        uint64_t get_min_cl(const fapi2::buffer<uint64_t>& i_supported_cl) const
        {
            // If the last of Byte 23 of the SPD is 1, this selects CL values
            // in the High CL range (23 to 52)

            // If the last bit of Byte 23 of the SPD is 0, this selects CL values
            // in the Low CL range (7 to 36)
            return  i_supported_cl.getBit<CAS_LAT_RANGE_BIT>() ? HIGH_RANGE_MIN_CL_DDR4 : LOW_RANGE_MIN_CL_DDR4;

        }

        ///
        /// @brief Calculates CAS latency time from tCK and tAA
        /// @param[in] i_taa cas latency time
        /// @param[in] i_tck min cycle time
        /// @param[out] o_cas_latency calculated CAS latency
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode calc_cas_latency(const uint64_t i_taa,
                                           const uint64_t i_tck,
                                           uint64_t& o_cas_latency) const
        {
            FAPI_TRY( spd::ddr4::calc_nck(mss::generic_ffdc_codes::CALC_CAS_LATENCY, i_taa, i_tck,
                                          spd::INVERSE_DDR4_CORRECTION_FACTOR,
                                          o_cas_latency) );

            FAPI_DBG("%s. tAA (ps): %d, tCK (ps): %d, CL (nck): %d",
                     mss::spd::c_str(iv_target),
                     i_taa,
                     i_tck,
                     o_cas_latency);

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Helper function to create a vector of supported CAS latencies from a bitmap
        /// @param[in] i_common_cl common CAS latency bitmap
        /// @return vector of supported CAS latencies
        ///
        std::vector<uint64_t> integral_bitmap_to_vector(const uint64_t i_common_cl) const
        {
            std::vector<uint64_t> l_vector;
            fapi2::buffer<uint64_t> l_cl_mask(i_common_cl);

            const uint64_t l_min_cl = get_min_cl(l_cl_mask);
            const uint64_t l_max_cl = get_max_cl(l_cl_mask);

            FAPI_DBG("%s. min CL %lu", mss::spd::c_str(iv_target), l_min_cl);
            FAPI_DBG("%s. max CL %lu", mss::spd::c_str(iv_target), l_max_cl);

            for(uint64_t l_cas_latency = l_min_cl; l_cas_latency <= l_max_cl; ++l_cas_latency)
            {
                // 64 bit is buffer length - indexed at 0 - 63
                constexpr uint64_t l_buffer_length = 64 - 1;
                uint64_t l_bit_pos = l_buffer_length - (l_cas_latency - l_min_cl);

                // Traversing through buffer one bit at a time
                // 0 means unsupported CAS latency
                // 1 means supported  CAS latency
                // We are pushing supported CAS latencies into a vector for direct use
                if( l_cl_mask.getBit(l_bit_pos) )
                {
                    // I want don't this to print all the time, DBG is fine
                    FAPI_DBG( "%s. Supported CL (%d) from common CL mask (0x%llX)",
                              mss::spd::c_str(iv_target), l_cas_latency, i_common_cl );

                    l_vector.push_back(l_cas_latency);
                }
            }

            return l_vector;
        }

        ///
        /// @brief Determines if a requested CAS latency (CL) is supported in the bin of common CLs
        /// @param[in] i_common_cls vector of common CAS latencies
        /// @param[in] i_cas_latency CAS latency we are comparing against
        /// @return true iff desired CL was found in the bitmap of common CLs, false otherwise
        ///
        bool is_cl_supported_in_common(const std::vector<uint64_t>& i_common_cls,
                                       const uint64_t i_cas_latency) const
        {
            const bool l_found = std::binary_search(i_common_cls.begin(), i_common_cls.end(), i_cas_latency);

            FAPI_DBG("Found CL: %d in common CL mask: 0x%llX ? %s for %s",
                     i_cas_latency, iv_common_cl_bitmap, l_found ? "yes" : "no", mss::spd::c_str(iv_target));

            return l_found;
        }


        ///
        /// @brief Checks that CAS latency doesn't exceed largest CAS latency time
        /// @param[in] i_cas_latency cas latency
        /// @param[in] i_tck cycle time
        /// @return true iff CL exceeds tAAmax, false otherwise
        ///
        bool is_cl_exceeding_taa_max(const uint64_t i_cas_latency,
                                     const uint64_t i_tck) const
        {
            // JEDEC SPD spec requirement
            const auto l_cas_latency_time = i_cas_latency * i_tck;
            const size_t l_taa_max = (iv_is_3ds == loading::NOT_3DS) ? TAA_MAX_DDR4 : TAA_MAX_DDR4_3DS;
            const bool l_is_cl_exceeding_taa = l_cas_latency_time > l_taa_max;

            FAPI_DBG("%s. CL (%d) * tCK (%d) = %d > %d ? %s",
                     mss::spd::c_str(iv_target),
                     i_cas_latency,
                     i_tck,
                     l_cas_latency_time,
                     l_taa_max,
                     l_is_cl_exceeding_taa ? "yes" : "no");

            return l_is_cl_exceeding_taa;
        }

        ///
        /// @brief Selects DIMM frequency to run based on supported system frequencies
        /// @tparam F the freq_select type
        /// @param[in,out] io_dimm_freq input is current dimm freq & output is next
        /// lowest dimm freq between 1866 MT/s - 2666 MT/s
        /// @return FAPI2_RC_SUCCESS iff ok
        /// @note Frequency values obtained from:
        /// @note From P9 User's Manual Version 0.8 - June 08, 2015
        /// @note Memory Controller Unit - page 199 of 456
        ///
        template< freq_select F >
        inline fapi2::ReturnCode select_supported_freq(uint64_t& io_dimm_freq)
        {
            FAPI_TRY( (select_supported_freq_helper<F>(iv_supported_freqs, io_dimm_freq)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Limits tCK to system constraints (VPD and MRW)
        /// @tparam F freq_select type
        /// @param[in,out] io_tck input is current tCK, output is highest supported tCK (HIGHEST_COMMON specialization)
        /// or the next highest supported tCK (BIN_DOWN specialization)
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        template< freq_select F >
        fapi2::ReturnCode apply_freq_constraints(uint64_t& io_tck)
        {
            uint64_t l_proposed_freq = 0;
            FAPI_TRY( mss::ps_to_freq(io_tck, l_proposed_freq) );

            FAPI_TRY( (select_supported_freq<F>(l_proposed_freq)),
                      "%s. Failed select_supported_freq()", mss::spd::c_str(iv_target) );

            FAPI_TRY( freq_to_ps(l_proposed_freq, io_tck),
                      "%s. Failed freq_to_ps()", mss::spd::c_str(iv_target) );

            FAPI_DBG("%s Supported dimm speed override %d MT/s (Clock period %d in ps)",
                     mss::spd::c_str(iv_target), l_proposed_freq, io_tck);

            // Sanity check
            FAPI_ASSERT(io_tck > 0,
                        fapi2::MSS_FREQ_INVALID_CALCULATED_TCK()
                        .set_TAAMIN(iv_largest_taamin)
                        .set_PROPOSED_TCK(io_tck)
                        .set_IS_3DS(iv_is_3ds)
                        .set_PORT_TARGET(iv_target)
                        .set_MC_TYPE(mss::mc_type::EXPLORER),
                        "%s. mc_type: %s Invalid calculated clock period(<= 0 nCK) : %d",
                        mss::spd::c_str(iv_target),
                        TT::MC_STR,
                        io_tck);

        fapi_try_exit:
            return fapi2::current_err;
        }

};// cas_latency - EXPLORER

///
/// @brief CAS latency class that encapsulates JEDEC calculation algorithm - ODYSSEY (DDR5) specialization
/// @note Using spd::c_str as the frequency isn't setup yet, and that might be required for c_str prints
///
template<>
class cas_latency<mss::mc_type::ODYSSEY>
{
        using TT = CasLatencyTraits<mss::mc_type::ODYSSEY>;

    public:
        bool iv_dimm_list_empty;

        /////////////////////////
        // Public Member Methods
        /////////////////////////

        // Default constructor
        // class dependent on SPD data obtained internally
        // won't work when instantiated w/o neccesary params
        cas_latency() = delete;

        ///
        /// @brief Class constructor that retrieves required SPD data held by internal state
        /// @param[in] i_target the controller target
        /// @param[in] i_supported_freqs vector of supported frequencies
        /// @param[out] o_rc returns FAPI2_RC_SUCCESS if constructor initialzed successfully
        ///
        cas_latency(const fapi2::Target<TT::TARGET_TYPE>& i_target,
                    const std::vector<uint32_t>& i_supported_freqs,
                    fapi2::ReturnCode& o_rc):
            iv_dimm_list_empty(false),
            iv_target(i_target),
            iv_largest_taamin(0),
            iv_largest_trcdmin(0),
            iv_proposed_tck(0),
            iv_common_cl_bitmap(UINT64_MAX),
            iv_supported_freqs(i_supported_freqs)
        {
            o_rc = fapi2::FAPI2_RC_SUCCESS;

            if (mss::count_dimm(i_target) == 0)
            {
                FAPI_INF("cas latency ctor seeing no DIMMs on %s", mss::spd::c_str(i_target) );
                iv_dimm_list_empty = true;
                return;
            }

            for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
            {
                std::vector<uint8_t> l_spd;
                FAPI_TRY(mss::spd::get_raw_data(l_dimm, l_spd));
                FAPI_TRY(cas_latency_ctr_helper(l_dimm, l_spd));
            } // per dimm

            // Why didn't I encapsulate common CL operations and checking in a function
            // like the timing params? Well, I want to check the "final" common CL and
            // the creation of common CLs (bitwise ANDING) is at the dimm level operation
            FAPI_ASSERT(iv_common_cl_bitmap != 0,
                        fapi2::MSS_FREQ_NO_COMMON_SUPPORTED_CL().
                        set_MC_TYPE(mss::mc_type::ODYSSEY).
                        set_CL_SUPPORTED(iv_common_cl_bitmap).
                        set_PORT_TARGET(iv_target),
                        "%s. MC type: %s No common CAS latencies (CL bitmap = 0)",
                        mss::spd::c_str(iv_target), TT::MC_STR );

            FAPI_INF("Largest tAAmin (ps): %d, largest tRCDmin (ps): %d, tCKmin (ps): %d,"
                     "and supported CL bitmap 0x%010X for all modules across %s",
                     iv_largest_taamin, iv_largest_trcdmin, iv_proposed_tck,
                     iv_common_cl_bitmap, mss::spd::c_str(iv_target));

            iv_common_cl = integral_bitmap_to_vector(iv_common_cl_bitmap);

        fapi_try_exit:
            o_rc = fapi2::current_err;
            return;
        }// ctor

        ///
        /// @brief Constructor that allows the user to set desired data in lieu of SPD - helpful for testing
        /// @param[in] i_target the controller target
        /// @param[in] i_taa_min largest tAAmin we want to set in picoseconds
        /// @param[in] i_trcd_min largest tRCDmin we want to set in picoseconds
        /// @param[in] i_tck_min proposed tCKmin in picoseconds
        /// @param[in] i_common_cl_mask common CAS latency mask we want to use (bitmap)
        /// @param[in] i_is_3ds loading::IS_3DS if this is for 3DS, loading::NOT_3DS otherwise
        /// @param[in] i_supported_freqs vector of supported frequencies - defaulted to the traits supported frequencies
        ///
        cas_latency(const fapi2::Target<TT::TARGET_TYPE>& i_target,
                    const uint64_t i_taa_min,
                    const uint64_t i_trcd_min,
                    const uint64_t i_tck_min,
                    const uint64_t i_common_cl_mask,
                    const loading i_is_3ds,
                    const std::vector<uint32_t>& i_supported_freqs = TT::SUPPORTED_FREQS):
            iv_dimm_list_empty(false),
            iv_target(i_target),
            iv_largest_taamin(i_taa_min),
            iv_largest_trcdmin(i_trcd_min),
            iv_proposed_tck(i_tck_min),
            iv_common_cl_bitmap(i_common_cl_mask),
            iv_is_3ds(i_is_3ds),
            iv_supported_freqs(i_supported_freqs)
        {
            const auto l_dimm_list = find_targets<fapi2::TARGET_TYPE_DIMM>(iv_target);

            if(l_dimm_list.empty())
            {
                FAPI_INF("cas latency ctor seeing no DIMM on %s", mss::spd::c_str(iv_target));
                iv_dimm_list_empty = true;
            }

            iv_common_cl = integral_bitmap_to_vector(iv_common_cl_bitmap);
        }

        ///
        /// @brief Default destructor
        ///
        ~cas_latency() = default;

        ///
        /// @brief Helper function for CAS Latency constructor, unit testable
        ///
        /// @param[in] i_dimm DIMM target
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        /// @note implements CAS latency algorithm from DDR5 SPD spec
        ///
        fapi2::ReturnCode cas_latency_ctr_helper(
            const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
            const std::vector<uint8_t>& i_spd)
        {
            using F = mss::spd::fields<mss::spd::device_type::DDR5, mss::spd::module_params::BASE_CNFG>;
            // Retrieve timing values from the SPD
            uint64_t l_taa_min_in_ps = 0;
            uint64_t l_trcd_min_in_ps = 0;
            uint64_t l_tckmax_in_ps = 0;
            uint64_t l_tck_min_in_ps = 0;
            uint64_t l_taa_min_corr = 0;
            uint64_t l_trcd_min_corr = 0;

            const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_dimm);
            const auto& l_port = mss::find_target<TT::TARGET_TYPE>(i_dimm);

            // Get raw timing values for tAA and tRCD from SPD
            auto l_byte = F::TAA_MIN_LSB.get_byte(i_spd);
            FAPI_TRY(spd::ddr5::get_timing(i_dimm, i_spd, l_byte, GET_TAAMIN, l_taa_min_in_ps),
                     "%s failed to get TAA_MIN", mss::spd::c_str(i_dimm));
            l_byte = F::TRCD_MIN_LSB.get_byte(i_spd);
            FAPI_TRY(spd::ddr5::get_timing(i_dimm, i_spd, l_byte, GET_TRCDMIN, l_trcd_min_in_ps),
                     "%s failed to get TRCD_MIN", mss::spd::c_str(i_dimm));

            // Correct the raw timings using JEDEC rounding algorithm
            FAPI_TRY(spd::ddr5::corrected_ps_per_jedec(GET_TAAMIN, l_taa_min_in_ps, l_taa_min_corr));
            FAPI_TRY(spd::ddr5::corrected_ps_per_jedec(GET_TRCDMIN, l_trcd_min_in_ps, l_trcd_min_corr));

            FAPI_TRY( spd::ddr5::get_tckmax(i_dimm, i_spd, l_tckmax_in_ps),
                      "%s failed to get TCK_MAX", mss::spd::c_str(i_dimm) );
            FAPI_TRY( spd::ddr5::get_tckmin(i_dimm, i_spd, l_tck_min_in_ps),
                      "%s failed to get TCK_MIN", mss::spd::c_str(i_dimm) );

            // Determine largest tAAmin and tRCDmin values
            iv_largest_taamin = std::max(iv_largest_taamin, l_taa_min_corr);
            iv_largest_trcdmin = std::max(iv_largest_trcdmin, l_trcd_min_corr);

            // Determine a proposed tCK value that is greater than or equal tCKmin
            // But less than tCKmax
            iv_proposed_tck = std::max(iv_proposed_tck, l_tck_min_in_ps);
            iv_proposed_tck = std::min(iv_proposed_tck, l_tckmax_in_ps);

            {
                // Retrieve dimm supported cas latencies from SPD
                uint64_t l_dimm_supported_cl = 0;

                // Rev is already populated from pre-init fields
                uint8_t l_rev = 0;
                FAPI_TRY(mss::attr::get_spd_revision(l_port, l_rev));

                FAPI_TRY( mss::gen::ddr5::get_supported_cas_latencies(i_dimm,
                          i_spd,
                          static_cast<mss::spd::rev>(l_rev),
                          l_dimm_supported_cl),
                          "%s. Failed to get supported CAS latency", mss::spd::c_str(i_dimm) );

                // Bitwise ANDING the bitmap from all modules creates a bitmap w/a common CL
                iv_common_cl_bitmap &= l_dimm_supported_cl;
            }

            // Collecting stack type
            if( iv_is_3ds != loading::IS_3DS)
            {
                constexpr uint8_t MONOLITHIC_SDRAM = 0;
                uint8_t l_die_per_pkg = 0;
                FAPI_TRY(mss::spd::get_field_spd(l_ocmb, F::DIE_PER_PACKAGE, i_spd, SET_PRIM_DIE_COUNT, l_die_per_pkg));

                iv_is_3ds = (l_die_per_pkg == MONOLITHIC_SDRAM) ? loading::NOT_3DS : loading::IS_3DS;
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Calculates CAS latency and checks if it is supported and within JEDEC spec.
        /// @param[out] o_cas_latency selected CAS latency
        /// @param[out] o_tck cycle time corresponding to seleted CAS latency
        /// @return fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode find_cl(uint64_t& o_cas_latency,
                                  uint64_t& o_tck)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

            bool l_is_cl_in_common = false;
            bool l_is_cl_exceeding_taa = true;
            std::vector<uint64_t> l_cas_latency_list;
            bool l_is_1st_iteration = true;

            if(iv_dimm_list_empty)
            {
                // If the inputted target has no dimm configured then both
                // CAS latency and tCK are safe as 0's
                o_cas_latency = 0;
                o_tck = 0;
                return fapi2::FAPI2_RC_SUCCESS;
            }

            while(!l_is_cl_in_common && l_is_cl_exceeding_taa)
            {
                if( l_is_1st_iteration )
                {
                    // Our first run should try to run the highest common supported freq.
                    // If we don't meet JEDEC requirements then every iteration afterwards
                    // will bin down
                    l_is_1st_iteration = false;
                    FAPI_TRY( apply_freq_constraints<HIGHEST_COMMON>(iv_proposed_tck) );
                }
                else
                {
                    // Limit tCK from system constraints such as supported VPD for the system
                    // as well as MRW frequency overrides, if enabled. This guy will bin freq down until
                    // we can't and then we fail out, prevents infinite loop when raising tCK
                    FAPI_TRY( apply_freq_constraints<BIN_DOWN>(iv_proposed_tck) );
                }

                // For a proposed tCK value between tCKmin(all) and tCKmax, determine the valid CAS Latency values
                FAPI_TRY( calc_cas_latency(iv_largest_taamin,
                                           iv_largest_trcdmin,
                                           iv_proposed_tck,
                                           l_cas_latency_list),
                          "%s. Failed to calculate CAS latency", mss::spd::c_str(iv_target) );

                // Choose an actual CAS Latency (CLactual) from the list returned that
                // is supported by all modules on the memory channel
                l_is_cl_in_common = false;

                for (const auto l_proposed_cl : l_cas_latency_list)
                {
                    l_is_cl_in_common = is_cl_supported_in_common(iv_common_cl, l_proposed_cl);

                    if (l_is_cl_in_common)
                    {
                        o_cas_latency = l_proposed_cl;
                        break;
                    }
                }

                // If no such value exists, choose a higher tCKproposed value and repeat until a solution is found.
                if(!l_is_cl_in_common)
                {
                    FAPI_INF("%s No supported CL found for tCK = %d ps, choosing a higher tCK", mss::spd::c_str(iv_target),
                             iv_proposed_tck);
                    continue;
                }

            }// end while

            // If the cas_latency wasn't found, we return an error
            // Passing in timing values which were used to calculate i_cas_latency for extra info
            // iv_common_cl contains all of the valid cas latencies that populate the input vector
            FAPI_ASSERT( l_is_cl_in_common,
                         fapi2::MSS_FREQ_DDR5_FAILED_TO_FIND_SUPPORTED_CL()
                         .set_TAA(iv_largest_taamin)
                         .set_TRCD(iv_largest_trcdmin)
                         .set_TCK(iv_proposed_tck)
                         .set_COMMON_CLS(iv_common_cl_bitmap)
                         .set_PORT_TARGET(iv_target)
                         .set_MC_TYPE(mss::mc_type::ODYSSEY),
                         "%s. mc_type %s Failed to find a common CAS latency supported among all modules"
                         " common CL's %016lx",
                         mss::spd::c_str(iv_target),
                         TT::MC_STR,
                         iv_common_cl_bitmap);

            o_tck = iv_proposed_tck;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Selects DIMM frequency to run based on supported system frequencies -- helper function for testing
        /// @tparam F the freq_select type
        /// @param[in] i_supported_freqs vector supported frequencies
        /// @param[in,out] io_dimm_freq input is current dimm freq & output is next
        /// @return FAPI2_RC_SUCCESS iff ok
        /// @note Frequency values obtained from:
        /// @note From P9 User's Manual Version 0.8 - June 08, 2015
        /// @note Memory Controller Unit - page 199 of 456
        ///
        template< freq_select F >
        inline fapi2::ReturnCode select_supported_freq_helper( const std::vector<uint32_t>& i_supported_freqs,
                uint64_t& io_dimm_freq)
        {
            FAPI_ASSERT( !i_supported_freqs.empty(),
                         fapi2::MSS_EMPTY_VECTOR().
                         set_FUNCTION(SELECT_SUPPORTED_FREQ).
                         set_TARGET(iv_target),
                         "Empty supported frequency vector received for %s",
                         mss::spd::c_str(iv_target));

            for( const auto& freq : i_supported_freqs )
            {
                FAPI_DBG("Supported freqs taking into account VPD, SPD, & MRW constraints %d for %s", freq,
                         mss::spd::c_str(iv_target) );
            }

            FAPI_DBG("Input frequency %d for %s", io_dimm_freq, mss::spd::c_str(iv_target) );
            {
                auto l_iterator = search_list<F>(i_supported_freqs, io_dimm_freq);

                // Doing this because the HB compiler freaks out if we have it within the FAPI_ASSERT.
                // Outputting the value and then incrementing the iterator, that's why it's a post increment
                // We have at most 4 memory freqs, if we ever get a list with < 4 items
                // a value of 0 is logged in FFDC once we hit i_supported_freqs.end()...which is better than no logging.
                auto l_supported = i_supported_freqs.begin();

                const auto l_freq0 = (l_supported != i_supported_freqs.end()) ? *(l_supported++) : 0;
                const auto l_freq1 = (l_supported != i_supported_freqs.end()) ? *(l_supported++) : 0;
                const auto l_freq2 = (l_supported != i_supported_freqs.end()) ? *(l_supported++) : 0;
                const auto l_freq3 = (l_supported != i_supported_freqs.end()) ? *(l_supported++) : 0;

                // We can't choose a lower freq than the 1st element of this vector,
                // hitting this case means that we exhausted all possible frequencies
                FAPI_ASSERT( l_iterator != i_supported_freqs.begin(),
                             fapi2::MSS_FREQ_SELECTED_FREQ_NOT_SUPPORTED()
                             .set_FREQ(io_dimm_freq)
                             .set_SUPPORTED_FREQ_0( l_freq0 )
                             .set_SUPPORTED_FREQ_1( l_freq1 )
                             .set_SUPPORTED_FREQ_2( l_freq2 )
                             .set_SUPPORTED_FREQ_3( l_freq3 )
                             .set_TARGET(iv_target)
                             .set_MC_TYPE(mss::mc_type::ODYSSEY),
                             "%s mc_type: %s Error finding selected freq (%d) from list",
                             mss::spd::c_str(iv_target),
                             TT::MC_STR,
                             io_dimm_freq );

                // Lower bound checks for greater than or equal to input freq,
                // we decrement to get the next lowest freq
                io_dimm_freq = *(--l_iterator);

                FAPI_DBG("Output frequency %d for %s", io_dimm_freq, mss::spd::c_str(iv_target) );
            }

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }

    private:

        enum
        {
            // From JEDEC Standard No. 79-4A
            // Speed Bins pg. 164
            /// Time in picoseconds
            TAA_MAX_DDR5 = 22222,

            // CAS latency range from SPD
            MIN_CL_DDR5 = 20,
            MAX_CL_DDR5 = 98,
        };

        /////////////////////////
        // Private variables
        /////////////////////////
        fapi2::Target<TT::TARGET_TYPE> iv_target;
        uint64_t iv_largest_taamin;
        uint64_t iv_largest_trcdmin;
        uint64_t iv_proposed_tck;// cycle time
        uint64_t iv_common_cl_bitmap;
        loading iv_is_3ds;
        std::vector<uint64_t> iv_common_cl; // common cas latency
        std::vector<uint32_t> iv_supported_freqs;

        ///
        /// @brief Calculates CAS latency time from tCK, tAA, and tRCD
        /// @param[in] i_taa tAA value
        /// @param[in] i_trcd tRCD value
        /// @param[in] i_tck min cycle time
        /// @param[out] o_cas_latency_list vector of supported CAS latency values
        /// @return FAPI2_RC_SUCCESS iff okay
        /// @note Implements CAS Latency Algorithm from the Speed Bins section in the DDR5 spec
        /// @note The spec provides pseudocode for this calculation, which this code follows very closely
        ///
        fapi2::ReturnCode calc_cas_latency(const uint64_t i_taa,
                                           const uint64_t i_trcd,
                                           const uint64_t i_tck,
                                           std::vector<uint64_t>& o_cas_latency_list) const
        {
            // General timing constants and conversions from data rate to ps
            constexpr uint64_t DATA_RATE_TO_PS = 2000000;
            constexpr uint64_t MTS1980_IN_PS = DATA_RATE_TO_PS / 1980;
            constexpr uint64_t MTS2000_IN_PS = DATA_RATE_TO_PS / 2000;
            constexpr uint64_t MTS2100_IN_PS = DATA_RATE_TO_PS / 2100;
            constexpr uint64_t MTS2933_IN_PS = DATA_RATE_TO_PS / 2933;
            constexpr uint64_t MTS3200_IN_PS = DATA_RATE_TO_PS / 3200;
            constexpr uint64_t MTS3600_IN_PS = DATA_RATE_TO_PS / 3600;
            constexpr uint64_t MTS8400_IN_PS = DATA_RATE_TO_PS / 8400;

            // Timing targets (in ps) used in the CAS latency algorithm
            // Note: Each array is indexed like [iv_is_3ds][bin] with bin in the order of bin B, BN, C, B_SLOW
            // Bin B_SLOW value is for tRCD for speeds <= 3600
            constexpr uint64_t BIN_AN      = 0;
            constexpr uint64_t BIN_B       = 1;
            constexpr uint64_t BIN_BN      = 2;
            constexpr uint64_t BIN_C       = 3;
            constexpr uint64_t BIN_B_SLOW  = 4;
            constexpr const uint64_t TARGET_TAA[2][4] =  { {14000, 16000, 16000, 17500}, // monolithic
                {16000, 18500, 18500, 20000}
            }; // 3ds
            constexpr const uint64_t TARGET_TRCD[2][5] = { {14000, 16000, 16000, 17500, 16250}, // monolithic
                {14000, 16000, 16000, 17500, 16250}
            }; // 3ds

            uint64_t l_tck_std = 0;
            o_cas_latency_list.clear();

            // Round tCKreal down to the next faster standard frequency (tCK in ps)
            if ((i_tck <= MTS1980_IN_PS) && (i_tck >= MTS2100_IN_PS))
            {
                // Assign standard 2000ps tCK for 1980-2100 nominal data rates
                l_tck_std = MTS2000_IN_PS;
            }
            else if ((i_tck <= MTS2933_IN_PS) && (i_tck >= MTS3200_IN_PS))
            {
                // Assign standard 3200ps tCK for 2933-3200 nominal data rates
                l_tck_std = MTS3200_IN_PS;
            }
            else
            {
                for (uint64_t l_data_rate_nom = 3200; l_data_rate_nom <= 8000; l_data_rate_nom += 400)
                {
                    if ((i_tck < (DATA_RATE_TO_PS / l_data_rate_nom)) && (i_tck >= (DATA_RATE_TO_PS / (l_data_rate_nom + 400))))
                    {
                        // Assign standard 3600-8400ps tCK for >3200-8000 nominal data rates
                        l_tck_std = (DATA_RATE_TO_PS / (l_data_rate_nom + 400));
                    }
                }
            }

            FAPI_DBG("%s tCK_std (ps): %d",
                     mss::spd::c_str(iv_target),
                     l_tck_std);

            FAPI_ASSERT( l_tck_std != 0,
                         fapi2::MSS_FREQ_DDR5_COMPUTED_ZERO_TCK_STD()
                         .set_TCK_MIN(i_tck)
                         .set_PORT_TARGET(iv_target)
                         .set_MC_TYPE(mss::mc_type::ODYSSEY),
                         "%s mc_type: %s Computed zero tCKstd. tCKmin was %d",
                         mss::spd::c_str(iv_target),
                         TT::MC_STR,
                         i_tck );

            // CL Algorithm using l_tck_std as computed above
            // Only even CL’s (not odd CL’s) are valid per the DDR5 SDRAM specification
            if (l_tck_std == MTS2000_IN_PS)
            {
                // CL22 is the only valid CL for 1980-2100 data rates
                o_cas_latency_list.push_back(22);
            }
            else if ((l_tck_std <= MTS3200_IN_PS) && (l_tck_std >= MTS8400_IN_PS))
            {
                // Get all of our target values
                const uint8_t l_3ds = (iv_is_3ds == loading::NOT_3DS) ? 0 : 1;
                const uint64_t l_bin_an_taa_target = TARGET_TAA[l_3ds][BIN_AN];
                const uint64_t l_bin_b_taa_target  = TARGET_TAA[l_3ds][BIN_B];
                const uint64_t l_bin_bn_taa_target = TARGET_TAA[l_3ds][BIN_BN];
                const uint64_t l_bin_c_taa_target  = TARGET_TAA[l_3ds][BIN_C];

                const uint64_t l_bin_an_trcd_target = TARGET_TRCD[l_3ds][BIN_AN];
                const uint64_t l_bin_bn_trcd_target = TARGET_TRCD[l_3ds][BIN_BN];
                const uint64_t l_bin_c_trcd_target  = TARGET_TRCD[l_3ds][BIN_C];
                // Bin B has special handling because it has a different value for slower speeds
                const uint8_t l_bin_b_index = (l_tck_std < MTS3600_IN_PS) ? BIN_B : BIN_B_SLOW;
                const uint64_t l_bin_b_trcd_target = TARGET_TRCD[l_3ds][l_bin_b_index];

                // RA on these variables stands for Rounding Algorithm, which is labeled in the spec as RA(value)
                // these variables are number of clocks
                uint64_t l_bin_an_taa_ra = 0;
                uint64_t l_bin_b_taa_ra = 0;
                uint64_t l_bin_bn_taa_ra = 0;
                uint64_t l_bin_c_taa_ra = 0;
                uint64_t l_bin_an_taa_ra_even = 0;
                uint64_t l_bin_b_taa_ra_even = 0;
                uint64_t l_bin_bn_taa_ra_even = 0;
                uint64_t l_bin_c_taa_ra_even = 0;

                uint64_t l_bin_an_trcd_ra = 0;
                uint64_t l_bin_b_trcd_ra = 0;
                uint64_t l_bin_bn_trcd_ra = 0;
                uint64_t l_bin_c_trcd_ra = 0;
                uint64_t l_bin_an_trcd_ra_even = 0;
                uint64_t l_bin_b_trcd_ra_even = 0;
                uint64_t l_bin_bn_trcd_ra_even = 0;
                uint64_t l_bin_c_trcd_ra_even = 0;

                // Round the target values per Jedec rounding algorithm: RA(value)
                FAPI_TRY(spd::ddr5::calc_nck(mss::generic_ffdc_codes::CALC_CAS_LATENCY, l_bin_an_taa_target, l_tck_std,
                                             l_bin_an_taa_ra));
                FAPI_TRY(spd::ddr5::calc_nck(mss::generic_ffdc_codes::CALC_CAS_LATENCY, l_bin_b_taa_target, l_tck_std, l_bin_b_taa_ra));
                FAPI_TRY(spd::ddr5::calc_nck(mss::generic_ffdc_codes::CALC_CAS_LATENCY, l_bin_bn_taa_target, l_tck_std,
                                             l_bin_bn_taa_ra));
                FAPI_TRY(spd::ddr5::calc_nck(mss::generic_ffdc_codes::CALC_CAS_LATENCY, l_bin_c_taa_target, l_tck_std, l_bin_c_taa_ra));

                FAPI_TRY(spd::ddr5::calc_nck(mss::generic_ffdc_codes::CALC_CAS_LATENCY, l_bin_an_trcd_target, l_tck_std,
                                             l_bin_an_trcd_ra));
                FAPI_TRY(spd::ddr5::calc_nck(mss::generic_ffdc_codes::CALC_CAS_LATENCY, l_bin_b_trcd_target, l_tck_std,
                                             l_bin_b_trcd_ra));
                FAPI_TRY(spd::ddr5::calc_nck(mss::generic_ffdc_codes::CALC_CAS_LATENCY, l_bin_bn_trcd_target, l_tck_std,
                                             l_bin_bn_trcd_ra));
                FAPI_TRY(spd::ddr5::calc_nck(mss::generic_ffdc_codes::CALC_CAS_LATENCY, l_bin_c_trcd_target, l_tck_std,
                                             l_bin_c_trcd_ra));

                // Round the target values up to the next even value: EVEN(RA(value))
                FAPI_TRY(spd::ddr5::round_to_even(mss::generic_ffdc_codes::CALC_CAS_LATENCY, l_bin_an_taa_ra, l_bin_an_taa_ra_even));
                FAPI_TRY(spd::ddr5::round_to_even(mss::generic_ffdc_codes::CALC_CAS_LATENCY, l_bin_b_taa_ra, l_bin_b_taa_ra_even));
                FAPI_TRY(spd::ddr5::round_to_even(mss::generic_ffdc_codes::CALC_CAS_LATENCY, l_bin_bn_taa_ra, l_bin_bn_taa_ra_even));
                FAPI_TRY(spd::ddr5::round_to_even(mss::generic_ffdc_codes::CALC_CAS_LATENCY, l_bin_c_taa_ra, l_bin_c_taa_ra_even));

                FAPI_TRY(spd::ddr5::round_to_even(mss::generic_ffdc_codes::CALC_CAS_LATENCY, l_bin_an_trcd_ra, l_bin_an_trcd_ra_even));
                FAPI_TRY(spd::ddr5::round_to_even(mss::generic_ffdc_codes::CALC_CAS_LATENCY, l_bin_b_trcd_ra, l_bin_b_trcd_ra_even));
                FAPI_TRY(spd::ddr5::round_to_even(mss::generic_ffdc_codes::CALC_CAS_LATENCY, l_bin_bn_trcd_ra, l_bin_bn_trcd_ra_even));
                FAPI_TRY(spd::ddr5::round_to_even(mss::generic_ffdc_codes::CALC_CAS_LATENCY, l_bin_c_trcd_ra, l_bin_c_trcd_ra_even));

                // Now select one or more CL values using target tAA values that are greater than or equal to
                // our tAA_min, while the corresponding target tRCD greater than or equal to tRCD_min

                // Check bin AN with tRCD even
                if (((l_bin_an_taa_ra_even * l_tck_std) >= i_taa) && ((l_bin_an_trcd_ra_even * l_tck_std) >= i_trcd))
                {
                    // Push all the binning values onto the vector
                    o_cas_latency_list.push_back(l_bin_an_taa_ra_even);
                    o_cas_latency_list.push_back(l_bin_b_taa_ra_even);
                    o_cas_latency_list.push_back(l_bin_bn_taa_ra_even);
                    o_cas_latency_list.push_back(l_bin_c_taa_ra_even);
                }
                // Check bin B with tRCD even or odd
                else if (((l_bin_b_taa_ra_even * l_tck_std) >= i_taa) && ((l_bin_b_trcd_ra * l_tck_std) >= i_trcd))
                {
                    o_cas_latency_list.push_back(l_bin_b_taa_ra_even);
                    o_cas_latency_list.push_back(l_bin_bn_taa_ra_even);
                    o_cas_latency_list.push_back(l_bin_c_taa_ra_even);
                }
                // Check bin BN with tRCD even
                else if (((l_bin_bn_taa_ra_even * l_tck_std) >= i_taa) && ((l_bin_bn_trcd_ra_even * l_tck_std) >= i_trcd))
                {
                    o_cas_latency_list.push_back(l_bin_bn_taa_ra_even);
                    o_cas_latency_list.push_back(l_bin_c_taa_ra_even);
                }
                // Check bin C with tRCD even or odd
                else if (((l_bin_c_taa_ra_even * l_tck_std) >= i_taa) && ((l_bin_c_trcd_ra * l_tck_std) >= i_trcd))
                {
                    o_cas_latency_list.push_back(l_bin_c_taa_ra_even);
                }
            }

            for (const auto l_cl : o_cas_latency_list)
            {
                FAPI_DBG("%s. tAA (ps): %d, tRCD (ps): %d, tCK (ps): %d, CL (nck): %d",
                         mss::spd::c_str(iv_target), i_taa, i_trcd, i_tck, l_cl);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Helper function to create a vector of supported CAS latencies from a bitmap
        /// @param[in] i_common_cl common CAS latency bitmap
        /// @return vector of supported CAS latencies
        ///
        std::vector<uint64_t> integral_bitmap_to_vector(const uint64_t i_common_cl) const
        {
            std::vector<uint64_t> l_vector;
            fapi2::buffer<uint64_t> l_cl_mask(i_common_cl);

            // Note that only even CAS latencies are supported for DDR5, hence the += 2 below
            for(uint64_t l_cas_latency = MIN_CL_DDR5; l_cas_latency <= MAX_CL_DDR5; l_cas_latency += 2)
            {
                // 64 bit is buffer length - indexed at 0 - 63
                constexpr uint64_t l_buffer_length = 64 - 1;
                const uint64_t l_bit_pos = l_buffer_length - (l_cas_latency - MIN_CL_DDR5) / 2;

                // Traversing through buffer one bit at a time
                // 0 means unsupported CAS latency
                // 1 means supported  CAS latency
                // We are pushing supported CAS latencies into a vector for direct use
                if( l_cl_mask.getBit(l_bit_pos) )
                {
                    FAPI_DBG( "%s. Supported CL (%d) from common CL mask (0x%010X)",
                              mss::spd::c_str(iv_target), l_cas_latency, i_common_cl );

                    l_vector.push_back(l_cas_latency);
                }
            }

            return l_vector;
        }

        ///
        /// @brief Determines if a requested CAS latency (CL) is supported in the bin of common CLs
        /// @param[in] i_common_cls vector of common CAS latencies
        /// @param[in] i_cas_latency CAS latency we are comparing against
        /// @return true iff desired CL was found in the bitmap of common CLs, false otherwise
        ///
        bool is_cl_supported_in_common(const std::vector<uint64_t>& i_common_cls,
                                       const uint64_t i_cas_latency) const
        {
            const bool l_found = std::binary_search(i_common_cls.begin(), i_common_cls.end(), i_cas_latency);

            FAPI_DBG("Found CL: %d in common CL mask: 0x%llX ? %s for %s",
                     i_cas_latency, iv_common_cl_bitmap, l_found ? "yes" : "no", mss::spd::c_str(iv_target));

            return l_found;
        }


        ///
        /// @brief Selects DIMM frequency to run based on supported system frequencies
        /// @tparam F the freq_select type
        /// @param[in,out] io_dimm_freq input is current dimm freq & output is next
        /// lowest dimm freq between 1866 MT/s - 2666 MT/s
        /// @return FAPI2_RC_SUCCESS iff ok
        /// @note Frequency values obtained from:
        /// @note From P9 User's Manual Version 0.8 - June 08, 2015
        /// @note Memory Controller Unit - page 199 of 456
        ///
        template< freq_select F >
        inline fapi2::ReturnCode select_supported_freq(uint64_t& io_dimm_freq)
        {
            FAPI_TRY( (select_supported_freq_helper<F>(iv_supported_freqs, io_dimm_freq)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Limits tCK to system constraints (VPD and MRW)
        /// @tparam F freq_select type
        /// @param[in,out] io_tck input is current tCK, output is highest supported tCK (HIGHEST_COMMON specialization)
        /// or the next highest supported tCK (BIN_DOWN specialization)
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        template< freq_select F >
        fapi2::ReturnCode apply_freq_constraints(uint64_t& io_tck)
        {
            uint64_t l_proposed_freq = 0;
            FAPI_TRY( mss::ps_to_freq(io_tck, l_proposed_freq) );

            FAPI_TRY( (select_supported_freq<F>(l_proposed_freq)),
                      "%s. Failed select_supported_freq()", mss::spd::c_str(iv_target) );

            FAPI_TRY( freq_to_ps(l_proposed_freq, io_tck),
                      "%s. Failed freq_to_ps()", mss::spd::c_str(iv_target) );

            FAPI_DBG("%s Supported dimm speed override %d MT/s (Clock period %d in ps)",
                     mss::spd::c_str(iv_target), l_proposed_freq, io_tck);

            // Sanity check
            FAPI_ASSERT(io_tck > 0,
                        fapi2::MSS_FREQ_INVALID_CALCULATED_TCK()
                        .set_TAAMIN(iv_largest_taamin)
                        .set_PROPOSED_TCK(io_tck)
                        .set_IS_3DS(iv_is_3ds)
                        .set_PORT_TARGET(iv_target)
                        .set_MC_TYPE(mss::mc_type::ODYSSEY),
                        "%s. mc_type: %s Invalid calculated clock period(<= 0 nCK) : %d",
                        mss::spd::c_str(iv_target),
                        TT::MC_STR,
                        io_tck);

        fapi_try_exit:
            return fapi2::current_err;
        }

};// cas_latency - ODYSSEY

}// mss

#endif //_MSS_CAS_LATENCY_H_
