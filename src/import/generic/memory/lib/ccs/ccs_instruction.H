/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/ccs/ccs_instruction.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/// @file ccs_instruction.H
/// @brief CCS instruction class
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_CCS_INSTRUCTION_H_
#define _MSS_CCS_INSTRUCTION_H_

#include <fapi2.H>

#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/buffer_ops.H>
#include <generic/memory/lib/utils/index.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_memdiags.H>
#include <generic/memory/lib/ccs/ccs_traits.H>

namespace mss
{

namespace ccs
{

enum rank_configuration
{
    DUAL_DIRECT = 0,
    QUAD_ENCODED = 1,
    // Note: we don't include QUAD_DIRECT in here
    // That's because it uses 4 CS and is board wiring dependent
    // Not sure if it would use CS23 or CID01 for CS2/3
};

///
/// @class instruction_t
/// @brief Class for ccs instructions
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @note A ccs instruction is data (array 0) and some control information (array 1)cc
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
class instruction_t
{
    public:
        fapi2::buffer<uint64_t> arr0;
        fapi2::buffer<uint64_t> arr1;
        // The port indexed rank on which to operate. If this is invalid, all ranks will be disabled
        uint64_t iv_port_rank;
        // Different memory controllers handle the 16-bit idle and repeats separately
        // As such, we store the idle and repeat command values here
        // They will then be updated immediately prior to the arrays buffers being loaded into the registers
        uint16_t iv_idles;
        uint16_t iv_repeats;
        // We want to have a switch to update rank or not. A user might want to setup CS in some weird way
        // In that case, they don't want us "fixing" their CS values
        // We'll default the rank to be updated - we want to send out CS properly
        bool iv_update_rank;

        ///
        /// @brief Sets any signals associated with the chip selects for this instruction
        /// @param[in] i_csn01 chip selects 0 and 1
        /// @param[in] i_csn23 chip selects 2 and 3
        /// @param[in] i_cid the chip ID values to set
        /// @param[in] i_update_cid if true, the CID is updated, if not it is ignored
        /// @note This helper is created to allow different memory controllers to handle the ranks differently
        /// Largely, this is to allow for different DRAM generations between memory controllers
        ///
        void set_chipselects_helper(const uint8_t i_csn01, const uint8_t i_csn23, const uint8_t i_cid, const bool i_update_cid);

        ///
        /// @brief Gets the CKE signals (Memory controller and DRAM technology dependent)
        /// @param[out] o_cke the CKE for this instruction
        /// @note This helper is created to allow different memory controllers to handle the CKE differently
        /// Largely, this is to allow for different DRAM generations between memory controllers
        ///
        void get_cke_helper(uint8_t& o_cke) const;

        ///
        /// @brief Gets the CKE signals (Memory controller and DRAM technology dependent)
        /// @param[in] i_cke the CKE for this instruction
        /// @note This helper is created to allow different memory controllers to handle the CKE differently
        /// Largely, this is to allow for different DRAM generations between memory controllers
        ///
        void set_cke_helper(const uint8_t i_cke);

        ///
        /// @brief intstruction_t ctor
        /// @param[in] i_port_rank the port rank this instruction is headed for
        /// @param[in] i_arr0 the initial value for arr0, defaults to 0
        /// @param[in] i_arr1 the initial value for arr1, defaults to 0
        /// @param[in] i_update_rank true if the rank should be updated before being sent, defaults to true
        ///
        instruction_t( const uint64_t i_port_rank = NO_CHIP_SELECT_ACTIVE,
                       const fapi2::buffer<uint64_t> i_arr0 = 0,
                       const fapi2::buffer<uint64_t> i_arr1 = 0,
                       const uint16_t i_idles = 0,
                       const uint16_t i_repeats = 0,
                       const bool i_update_rank = true):
            arr0(i_arr0),
            arr1(i_arr1),
            iv_port_rank(i_port_rank),
            iv_idles(i_idles),
            iv_repeats(i_repeats),
            iv_update_rank(i_update_rank)
        {
            // Skip setting up the rank if the user doesn't want us to
            if(iv_update_rank)
            {
                // Set the chip selects to be 1's (not active)
                // We'll fix these up before executing the instructions
                set_chipselects_helper(0b11, 0b11, 0b00, false);
            }
        }

        ///
        /// @brief Updates the idles and repeats based upon the memory controller
        /// @param[in] i_target the port target for this instruction - for error logging
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
        ///
        fapi2::ReturnCode configure_idles_and_repeats( const fapi2::Target<TT::PORT_TARGET_TYPE>& i_target );

        ///
        /// @brief Grabs the idles from the CCS array
        ///
        void get_idles();

        ///
        /// @brief Grabs the repeats from the CCS array
        ///
        void get_repeats();

        ///
        /// @brief Updates the rank based upon the passed in rank configuration encoding
        /// @param[in] i_target the port target for this instruction - for error logging
        /// @param[in] i_rank_config the rank configuration
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
        ///
        fapi2::ReturnCode configure_rank(
            const fapi2::Target<TT::PORT_TARGET_TYPE>& i_target,
            const rank_configuration i_rank_config )
        {
            // If this instruction is set to not update the rank, then don't update the rank
            if(!iv_update_rank)
            {
                return fapi2::FAPI2_RC_SUCCESS;
            }

            // Regardless of rank configurations, if we have NO_CHIP_SELECT_ACTIVE, deactivate all CS
            if(iv_port_rank == NO_CHIP_SELECT_ACTIVE)
            {
                set_chipselects_helper(0b11, 0b11, 0b00, false);
                return fapi2::FAPI2_RC_SUCCESS;
            }

            // First, check rank - we need to make sure that we have a valid rank
            FAPI_ASSERT(iv_port_rank < TT::CCS_MAX_MRANK_PER_PORT,
                        fapi2::MSS_INVALID_RANK()
                        .set_PORT_TARGET(i_target)
                        .set_RANK(iv_port_rank)
                        .set_FUNCTION(generic_ffdc_codes::CCS_INST_CONFIGURE_RANK),
                        "%s rank out of bounds rank%u", mss::c_str(i_target), iv_port_rank);

            // Now the fun happens and we can deal with the actual encoding

            // If we're quad mode, setup the encoding accordingly
            if(i_rank_config == rank_configuration::QUAD_ENCODED)
            {
                // CS 0/1 are first, while CID0/1 are second
                // In quad enabled mode, CID acts as a "package select"
                // It selects R0/2 vs R1/3
                // CS0 vs CS1 selects the low vs high rank in the package
                // CS0 will select rank 0/1
                // CS1 will select rank 2/3

                const auto l_dimm_rank = mss::index(iv_port_rank);
                const bool l_is_dimm0 = iv_port_rank < TT::CCS_MAX_RANK_PER_DIMM;
                constexpr uint64_t NON_DIMM_CS = 0b11;

                // Assigns the CS based upon which DIMM we're at
                const uint64_t CS01 = l_is_dimm0 ? TT::CS_N[l_dimm_rank].first : NON_DIMM_CS;
                uint64_t CS23 = l_is_dimm0 ? NON_DIMM_CS : TT::CS_N[l_dimm_rank].first;

                // Set CS23 <-- CS01 if CS needs to be tied
                FAPI_TRY(TT::cs_tied(i_target, CS01, CS23));

                // Setup that rank
                set_chipselects_helper(CS01, CS23, TT::CS_N[l_dimm_rank].second, true);
            }

            // Otherwise, setup for dual-direct mode (our only other supported mode at the moment)
            else
            {
                const auto l_dimm_rank = mss::index(iv_port_rank);
                const bool l_is_dimm0 = iv_port_rank < TT::CCS_MAX_RANK_PER_DIMM;

                // Assigns the CS based upon which DIMM we're at
                const uint64_t CS01 = l_is_dimm0 ? TT::CS_ND[l_dimm_rank].first : TT::CS_ND[l_dimm_rank].second;
                uint64_t CS23 = l_is_dimm0 ? TT::CS_ND[l_dimm_rank].second : TT::CS_ND[l_dimm_rank].first;

                // Set CS23 <-- CS01 if CS needs to be tied
                FAPI_TRY(TT::cs_tied(i_target, CS01, CS23));

                // Setup that rank
                set_chipselects_helper(CS01, CS23, 0b00, false);

                // Check that we don't have a rank out of bounds case here
                // We can only have that if
                // 1) we are DIMM1
                // 2) our DIMM rank is greater than the maximum allowed number of ranks on DIMM1
                // So, we pass always if we're DIMM0, or if our DIMM rank is less than the maximum number of DIMM's on rank 1
                FAPI_ASSERT((l_dimm_rank < TT::CCS_MAX_RANKS_DIMM1) || l_is_dimm0,
                            fapi2::MSS_INVALID_RANK()
                            .set_PORT_TARGET(i_target)
                            .set_RANK(iv_port_rank)
                            .set_FUNCTION(generic_ffdc_codes::CCS_INST_CONFIGURE_RANK),
                            "%s rank out of bounds rank%u", mss::c_str(i_target), iv_port_rank);
            }

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Equals comparison operator
        /// @param[in] i_rhs - the instruction to compare to
        /// @return True if both instructions are equal
        ///
        inline bool operator==( const instruction_t<MC>& i_rhs ) const
        {
            return arr0 == i_rhs.arr0 &&
                   arr1 == i_rhs.arr1 &&
                   iv_port_rank == i_rhs.iv_port_rank &&
                   iv_update_rank == i_rhs.iv_update_rank &&
                   iv_idles == i_rhs.iv_idles &&
                   iv_repeats == i_rhs.iv_repeats;
        }
};

} // ends namespace ccs
} // ends namespace mss

#endif
