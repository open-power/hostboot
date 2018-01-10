/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/freq/cas_latency.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
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

// mss lib
#include <generic/memory/lib/spd/common/ddr4/spd_decoder_ddr4.H>
#include <lib/utils/conversions.H>
#include <lib/freq/sync.H>

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
/// @class cas_latency
/// @brief CAS latency class that encapsulates JEDEC calculation algorithm
///
class cas_latency
{
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
        /// @param[in] i_caches decoder caches
        /// @param[in] i_supported_freqs vector of supported frequencies
        /// @param[out] o_rc returns FAPI2_RC_SUCCESS if constructor initialzed successfully
        ///
        cas_latency(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target_mcs,
                    const std::vector< std::shared_ptr<spd::decoder> >& i_caches,
                    const std::vector<uint32_t>& i_supported_freqs,
                    fapi2::ReturnCode& o_rc);

        ///
        /// @brief Constructor that allows the user to set desired data in lieu of SPD - helpful for testing
        /// @param[in] i_target the controller target
        /// @param[in] i_taa_min largest tAAmin we want to set in picoseconds
        /// @param[in] i_tck_min proposed tCKmin in picoseconds
        /// @param[in] i_common_cl_mask common CAS latency mask we want to use (bitmap)
        /// @param[in] i_is_3ds loading::IS_3DS if this is for 3DS, loading::NOT_3DS otherwise
        /// @param[in] i_req_sync_mode required synchronous mode -- defaulted to SYNCH_MODE_UNDETERMINED,
        /// @param[in] i_supported_freqs vector of supported frequencies -- defaulted to NIMBUS_SUPPORTED_FREQS
        ///
        cas_latency(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                    const uint64_t i_taa_min,
                    const uint64_t i_tck_min,
                    const uint64_t i_common_cl_mask,
                    const loading i_is_3ds,
                    const uint8_t i_req_sync_mode = fapi2::ENUM_ATTR_REQUIRED_SYNCH_MODE_UNDETERMINED,
                    const std::vector<uint32_t>& i_supported_freqs = NIMBUS_SUPPORTED_FREQS);

        ///
        /// @brief Default destructor
        ///
        ~cas_latency() = default;

        ///
        /// @brief Calculates CAS latency and checks if it is supported and within JEDEC spec.
        /// @param[out] o_cas_latency selected CAS latency
        /// @param[out] o_tck cycle time corresponding to seleted CAS latency
        /// @return fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode find_cl(uint64_t& o_cas_latency,
                                  uint64_t& o_tck);

        ///
        /// @brief Selects DIMM frequency to run based on supported system frequencies -- helper function for testing
        /// @tparam TT the freq_select type
        /// @param[in] i_supported_freqs vector supported frequencies
        /// @param[in,out] io_dimm_freq input is current dimm freq & output is next
        /// lowest dimm freq between 1866 MT/s - 2666 MT/s
        /// @return FAPI2_RC_SUCCESS iff ok
        /// @note Frequency values obtained from:
        /// @note From P9 User's Manual Version 0.8 - June 08, 2015
        /// @note Memory Controller Unit - page 199 of 456
        ///
        template< freq_select TT >
        inline fapi2::ReturnCode select_supported_freq_helper( const std::vector<uint32_t>& i_supported_freqs,
                uint64_t& io_dimm_freq)
        {
            FAPI_ASSERT( !i_supported_freqs.empty(),
                         fapi2::MSS_EMPTY_VECTOR().
                         set_FUNCTION(SELECT_SUPPORTED_FREQ).
                         set_TARGET(iv_target),
                         "Empty supported frequency vector received for %s",
                         mss::c_str(iv_target));

            for( const auto& freq : i_supported_freqs )
            {
                FAPI_DBG("Supported freqs taking into account VPD, SPD, & MRW constraints %d for %s", freq, mss::c_str(iv_target) );
            }

            FAPI_DBG("Input frequency %d for %s", io_dimm_freq, mss::c_str(iv_target) );
            {
                auto l_iterator = search_list<TT>(i_supported_freqs, io_dimm_freq);

                // Doing this because the HB compiler freaks out if we have it within the FAPI_ASSERT.
                // Outputting the value and then incrementing the iterator, that's why it's a post increment
                // We have at most 4 memory freqs (1866, 2133, 2400, & 2666), if we ever get a list with < 4 items
                // a value of 0 is logged in FFDC once we hit i_supported_freqs.end()...which is better than no logging.
                auto l_supported = i_supported_freqs.begin();

                const auto l_freq0 = (l_supported != i_supported_freqs.end()) ? *(l_supported++) : 0;
                const auto l_freq1 = (l_supported != i_supported_freqs.end()) ? *(l_supported++) : 0;
                const auto l_freq2 = (l_supported != i_supported_freqs.end()) ? *(l_supported++) : 0;
                const auto l_freq3 = (l_supported != i_supported_freqs.end()) ? *(l_supported++) : 0;

                // We can't choose a lower freq than the 1st element of this vector,
                // hitting this case means that we exhausted all possible frequencies
                FAPI_ASSERT( l_iterator != i_supported_freqs.begin(),
                             fapi2::MSS_SELECTED_FREQ_NOT_SUPPORTED()
                             .set_FREQ(io_dimm_freq)
                             .set_SUPPORTED_FREQ_0( l_freq0 )
                             .set_SUPPORTED_FREQ_1( l_freq1 )
                             .set_SUPPORTED_FREQ_2( l_freq2 )
                             .set_SUPPORTED_FREQ_3( l_freq3 )
                             .set_TARGET(iv_target),
                             "%s Error finding selected freq (%d) from list",
                             mss::c_str(iv_target),
                             io_dimm_freq );

                // Lower bound checks for greater than or equal to input freq,
                // we decrement to get the next lowest freq
                io_dimm_freq = *(--l_iterator);

                FAPI_DBG("Output frequency %d for %s", io_dimm_freq, mss::c_str(iv_target) );
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
        fapi2::Target<fapi2::TARGET_TYPE_MCA> iv_target;
        uint64_t iv_largest_taamin;// cas latency time
        uint64_t iv_proposed_tck;// cycle time
        loading iv_is_3ds;
        uint64_t iv_common_cl_bitmap;
        bool iv_enable_freq_overrides;
        std::vector<uint64_t> iv_common_cl; // common cas latency
        uint8_t iv_req_sync_mode;
        std::vector<uint32_t> iv_supported_freqs;

        ///
        /// @brief Retrieves SDRAM Minimum CAS Latency Time (tAAmin) from SPD
        /// @param[in] i_pDecoder the SPD decoder
        /// @param[out] o_value tCKmin value in ps
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode get_taamin(const std::shared_ptr<mss::spd::decoder>& i_pDecoder,
                                     uint64_t& o_value);

        ///
        /// @brief Gets max CAS latency (CL) for the appropriate High/Low Range
        /// @param[in] i_supported_cl
        /// @return the maximum supported CL
        /// @note Depends on bit 7 of byte 23 from the DDR4 SPD
        ///
        uint64_t get_max_cl(const fapi2::buffer<uint64_t> i_supported_cl) const;

        ///
        /// @brief Gets min CAS latency (CL) for the appropriate High/Low Range
        /// @param[in] i_supported_cl
        /// @return the minimum supported CL
        /// @note Depends on bit 7 of byte 23 from the DDR4 SPD
        ///
        uint64_t get_min_cl(const fapi2::buffer<uint64_t>& i_supported_cl) const;

        ///
        /// @brief Calculates CAS latency time from tCK and tAA
        /// @param[in] i_taa cas latency time
        /// @param[in] i_tck min cycle time
        /// @param[out] o_cas_latency calculated CAS latency
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode calc_cas_latency(const uint64_t i_taa,
                                           const uint64_t i_tck,
                                           uint64_t& o_cas_latency) const;

        ///
        /// @brief Helper function to create a vector of supported CAS latencies from a bitmap
        /// @param[in] i_common_cl common CAS latency bitmap
        /// @return vector of supported CAS latencies
        ///
        std::vector<uint64_t> integral_bitmap_to_vector(const uint64_t i_bitmap) const;

        ///
        /// @brief Determines if a requested CAS latency (CL) is supported in the bin of common CLs
        /// @param[in] i_common_cls vector of common CAS latencies
        /// @param[in] i_cas_latency CAS latency we are comparing against
        /// @return true iff desired CL was found in the bitmap of common CLs, false otherwise
        ///
        bool is_cl_supported_in_common(const std::vector<uint64_t>& i_common_cls,
                                       const uint64_t i_cas_latency) const;

        ///
        /// @brief Checks that CAS latency doesn't exceed largest CAS latency time
        /// @param[in] i_cas_latency cas latency
        /// @param[in] i_tck cycle time
        /// @return true iff CL exceeds tAAmax, false otherwise
        ///
        bool is_cl_exceeding_taa_max(const uint64_t i_cas_latency,
                                     const uint64_t i_tck) const;

        ///
        /// @brief Selects DIMM frequency to run based on supported system frequencies
        /// @tparam TT the freq_select type
        /// @param[in,out] io_dimm_freq input is current dimm freq & output is next
        /// lowest dimm freq between 1866 MT/s - 2666 MT/s
        /// @return FAPI2_RC_SUCCESS iff ok
        /// @note Frequency values obtained from:
        /// @note From P9 User's Manual Version 0.8 - June 08, 2015
        /// @note Memory Controller Unit - page 199 of 456
        ///
        template< freq_select TT >
        inline fapi2::ReturnCode select_supported_freq(uint64_t& io_dimm_freq)
        {
            FAPI_TRY( (select_supported_freq_helper<TT>(iv_supported_freqs, io_dimm_freq)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Limits tCK to system constraints (VPD and MRW)
        /// @tparam T freq_select type
        /// @param[in,out] io_tck input is current tCK, output is highest supported tCK (HIGHEST_COMMON specialization)
        /// or the next highest supported tCK (BIN_DOWN specialization)
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        template< freq_select T >
        fapi2::ReturnCode apply_freq_constraints(uint64_t& io_tck)
        {
            uint64_t l_proposed_freq = 0;
            FAPI_TRY( mss::ps_to_freq(io_tck, l_proposed_freq) );

            FAPI_TRY( (select_supported_freq<T>(l_proposed_freq)),
                      "%s. Failed select_supported_freq()", mss::c_str(iv_target) );

            FAPI_TRY( freq_to_ps(l_proposed_freq, io_tck),
                      "%s. Failed freq_to_ps()", mss::c_str(iv_target) );

            FAPI_INF("%s Supported dimm speed override %d MT/s (Clock period %d in ps)",
                     mss::c_str(iv_target), l_proposed_freq, io_tck);

            // Sanity check
            FAPI_ASSERT(io_tck > 0,
                        fapi2::MSS_INVALID_CALCULATED_TCK().
                        set_TAAMIN(iv_largest_taamin).
                        set_PROPOSED_TCK(io_tck).
                        set_IS_3DS(iv_is_3ds).
                        set_MCA_TARGET(iv_target),
                        "%s. Invalid calculated clock period(<= 0 nCK) : %d",
                        mss::c_str(iv_target),
                        io_tck);

        fapi_try_exit:
            return fapi2::current_err;
        }

};// cas_latency

}// mss

#endif //_MSS_CAS_LATENCY_H_
