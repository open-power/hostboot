/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/freq/cas_latency.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
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
#include <lib/spd/common/spd_decoder.H>

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

///
/// @class decoder
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
        /// @brief      Class constructor that retrieves required SPD data held by internal state
        /// @param[in]  i_target the controller target
        /// @param[in]  i_caches decoder caches
        /// @param[out] o_rc returns FAPI2_RC_SUCCESS if constructor initialzed successfully
        ///
        cas_latency(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target_mcs,
                    const std::map<uint32_t, std::shared_ptr<spd::decoder> >& i_caches,
                    fapi2::ReturnCode& o_rc);

        /// @brief      Constructor that allows the user to set desired data in lieu of SPD
        /// @param[in]  i_target the controller target
        /// @param[in]  i_taa_min largest tAAmin we want to set in picoseconds
        /// @param[in]  i_tck_min proposed tCKmin in picoseconds
        /// @param[in]  i_common_cl_mask common CAS latency mask we want to use (bitmap)
        /// @param[in]  i_is_3ds loading::IS_3DS if this is for 3DS,
        ///             loading::NOT_3DS otherwise (default)
        ///
        cas_latency(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                    const uint64_t i_taa_min,
                    const uint64_t i_tck_min,
                    const uint64_t i_common_cl_mask,
                    const loading i_is_3ds = loading::NOT_3DS);

        ///
        /// @brief Default destructor
        ///
        ~cas_latency() = default;

        ///
        /// @brief      Calculates CAS latency and checks if it is supported and within JEDEC spec.
        /// @param[out] o_cas_latency selected CAS latency
        /// @param[out] o_tck cycle time corresponding to seleted CAS latency
        /// @return     fapi2::FAPI2_RC_SUCCESS if ok
        ///
        fapi2::ReturnCode find_cl(uint64_t& o_cas_latency,
                                  uint64_t& o_tck);

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
        fapi2::Target<fapi2::TARGET_TYPE_MCS> iv_target;
        uint64_t iv_largest_taamin;// cas latency time
        uint64_t iv_proposed_tck;// cycle time
        uint64_t iv_common_cl; // common cas latency
        loading iv_is_3ds;

        ///
        /// @brief      Retrieves SDRAM Minimum CAS Latency Time (tAAmin) from SPD
        /// @param[in]  i_target the dimm target
        /// @param[in]  i_pDecoder the SPD decoder
        /// @param[out] o_value tCKmin value in ps
        /// @return     FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode get_taamin(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const std::shared_ptr<mss::spd::decoder>& i_pDecoder,
                                     uint64_t& o_value);
        ///
        /// @brief      Retrieves SDRAM Minimum Cycle Time (tCKmin) from SPD
        /// @param[in]  i_target the dimm target
        /// @param[in]  i_pDecoder the SPD decoder
        /// @param[out] o_value tCKmin value in ps
        /// @return     FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode get_tckmin(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const std::shared_ptr<mss::spd::decoder>& i_pDecoder,
                                     uint64_t& o_value);

        ///
        /// @brief      Retrieves SDRAM Maximum Cycle Time (tCKmax) from SPD
        /// @param[in]  i_target the dimm target
        /// @param[in]  i_pDecoder SPD decoder
        /// @param[out] o_value tCKmax value in ps
        /// @return     FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode get_tckmax(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const std::shared_ptr<mss::spd::decoder>& i_pDecoder,
                                     uint64_t& o_value);

        ///
        /// @brief      Gets max CAS latency (CL) for the appropriate High/Low Range
        /// @param[in]  i_supported_cl
        /// @return     the maximum supported CL
        /// @note       Depends on bit 7 of byte 23 from the DDR4 SPD
        ///
        inline uint64_t get_max_cl(const fapi2::buffer<uint64_t> i_supported_cl) const;

        ///
        /// @brief      Gets min CAS latency (CL) for the appropriate High/Low Range
        /// @param[in]  i_supported_cl
        /// @return     the minimum supported CL
        /// @note       Depends on bit 7 of byte 23 from the DDR4 SPD
        ///
        inline uint64_t get_min_cl(const fapi2::buffer<uint64_t>& i_supported_cl) const;

        ///
        /// @brief Calculates CAS latency time from tCK and tAA
        /// @param[in]  i_taa cas latency time
        /// @param[in]  i_tck min cycle time
        /// @param[out] o_cas_latency calculated CAS latency
        /// @return     FAPI2_RC_SUCCESS iff okay
        ///
        inline fapi2::ReturnCode calc_cas_latency(const uint64_t i_taa,
                const uint64_t i_tck,
                uint64_t& o_cas_latency) const;

        ///
        /// @brief      Helper function to create a vector of supported CAS latencies from a bitmap
        /// @param[in]  i_common_cl common CAS latency bitmap
        /// @return     vector of supported CAS latencies
        ///
        std::vector<uint64_t> integral_bitmap_to_vector(const uint64_t i_bitmap) const;

        ///
        /// @brief      Determines if a requested CAS latency (CL) is supported in the bin of common CLs
        /// @param[in]  i_common_cls vector of common CAS latencies
        /// @param[in]  i_cas_latency CAS latency we are comparing against
        /// @return     fapi2::FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode is_cl_supported_in_common(const std::vector<uint64_t>& i_common_cls,
                const uint64_t i_cas_latency) const;


        ///
        /// @brief      Checks that CAS latency doesn't exceed largest CAS latency time
        /// @param[in]  i_cas_latency cas latency
        /// @param[in]  i_tck cycle time
        /// @return     fapi2::FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode is_cl_exceeding_taa_max(const uint64_t i_cas_latency,
                const uint64_t i_tck) const;

};// cas_latency


}// mss

#endif //_MSS_CAS_LATENCY_H_
