/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/freq/cas_latency.H $       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
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

#include <map>
#include <memory>
#include <cstdint>

#include <fapi2.H>
#include <spd/spd_decoder.H>

namespace mss
{


enum constants : std::uint64_t
{
    // From JEDEC Standard No. 79-4A
    // Speed Bins pg. 164
    /// Time in picoseconds
    TAA_MAX_DDR4 = 18000,

    // Low range CAS latency from SPD
    LOW_RANGE_MIN_CL_DDR4 = 7,
    LOW_RANGE_MAX_CL_DDR4 = 36,

    // High range CAS latency SPD
    HIGH_RANGE_MIN_CL_DDR4 = 23,
    HIGH_RANGE_MAX_CL_DDR4 = 52,
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
        ///
        cas_latency(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target_mcs,
                    const std::map<uint32_t, std::shared_ptr<spd::decoder> >& i_caches);

        // Default destructor
        ~cas_latency() = default;

        ///
        /// @brief      Calculates CAS latency and checks if it is supported and within JEDEC spec.
        /// @param[in]  i_target the controller target
        /// @param[out] o_cas_latency selected CAS latency
        /// @param[out] o_tCK cycle time corresponding to seleted CAS latency
        /// @return     fapi2::FAPI2_RC_SUCCESS if ok
        ///
        fapi2::ReturnCode find_CL(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target_mcs,
                                  uint64_t& o_cas_latency,
                                  uint64_t& o_tCK);

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
        /// @param[in]  i_supported_CL
        /// @return     the maximum supported CL
        /// @note       Depends on bit 7 of byte 23 from the DDR4 SPD
        ///
        inline uint64_t get_max_CL(const fapi2::buffer<uint64_t> i_supported_CL) const;

        ///
        /// @brief      Gets min CAS latency (CL) for the appropriate High/Low Range
        /// @param[in]  i_supported_CL
        /// @return     the minimum supported CL
        /// @note       Depends on bit 7 of byte 23 from the DDR4 SPD
        ///
        inline uint64_t get_min_CL(const fapi2::buffer<uint64_t>& i_supported_CL) const;

        ///
        /// @brief Calculates CAS latency time from tCK and tAA
        /// @param[in]  i_tAA cas latency time
        /// @param[in]  i_tCK min cycle time
        /// @return     o_cas_latency calculated CAS latency
        ///
        inline uint64_t calc_cas_latency(const uint64_t i_tAA, const uint64_t i_tCK) const;

        ///
        /// @brief      Helper function to create a vector of supported CAS latencies from a bitmap
        /// @param[in]  i_common_CL common CAS latency bitmap
        /// @return     vector of supported CAS latencies
        ///
        std::vector<uint64_t> create_common_cl_vector(const uint64_t i_common_CL) const;

        ///
        /// @brief      Determines if a requested CAS latency (CL) is supported in the bin of common CLs
        /// @param[in]  i_common_CLs vector of common CAS latencies
        /// @param[in]  i_cas_latency CAS latency we are comparing against
        /// @return     true if CAS latency is supported
        ///
        inline bool is_CL_supported_in_common(const std::vector<uint64_t>& i_common_CLs,
                                              const uint64_t i_cas_latency) const;


        ///
        /// @brief      Checks that CAS latency doesn't exceed largest CAS latency time
        /// @param[in]  i_cas_latency cas latency
        /// @param[in]  i_tCK cycle time
        /// @return     bool true if CAS latency exceeds the largest CAS latency time
        ///             false otherwise
        ///
        inline bool is_CL_exceeding_tAAmax(const uint64_t i_cas_latency,
                                           const uint64_t i_tCK) const;

        ///
        /// @brief Helper function to determines next lowest CAS latency (CL)
        /// @param[in] i_common_CLs vector of common CAS latencies
        /// @param[in] i_desired_cas_latency current CAS latency
        /// @return the next lowest CL
        ///
        inline uint64_t next_lowest_CL(const std::vector<uint64_t>& i_common_CLs,
                                       const uint64_t i_desired_cas_latency);

        ///
        /// @brief          Checks that CAS latency (CL) is supported among all dimms
        ///                 and if it isn't we try to find a CL that is.
        /// @param[in]      i_common_CLs vector of common CAS latencies
        /// @param[in]      i_tAA CAS latency time
        /// @param[in,out]  io_tCK cycle time that corresponds to cas latency
        /// @param[in,out]  io_desired_cas_lat cas latency supported for all dimms
        /// @return         fapi2::FAPI2_RC_SUCCESS if we find a valid CL also common among all dimms
        ///
        fapi2::ReturnCode choose_actual_CL (const std::vector<uint64_t>& i_common_CLs,
                                            const uint64_t i_tAA,
                                            uint64_t& io_tCK,
                                            uint64_t& io_desired_cas_lat);
        ///
        /// @brief          Checks that CAS latency (CL) doesn't exceed max CAS latency time (tAAmax)
        ///                 and if it does it tries to find a valid CL that doesn't exceed tAAmax.
        /// @param[in]      i_common_CLs vector of common CAS latencies
        /// @param[in]      i_tAA CAS latency time
        /// @param[in,out]  io_tCK cycle time that corresponds to cas latency
        /// @param[in,out]  io_desired_cas_lat cas latency supported for all dimms
        /// @return         fapi2::FAPI2_RC_SUCCESS if CL doesn't exceed tAAmax
        ///
        fapi2::ReturnCode validate_valid_CL (const std::vector<uint64_t>& i_common_CLs,
                                             const uint64_t i_tAA,
                                             uint64_t& io_tCK,
                                             uint64_t& io_desired_cas_lat);

    private:

        /////////////////////////
        // Private variables
        /////////////////////////
        uint64_t iv_largest_taamin;// cas latency time
        uint64_t iv_proposed_tck;// cycle time
        uint64_t iv_common_CL; // common cas latency

};// cas_latency


}// mss

#endif //_MSS_CAS_LATENCY_H_
