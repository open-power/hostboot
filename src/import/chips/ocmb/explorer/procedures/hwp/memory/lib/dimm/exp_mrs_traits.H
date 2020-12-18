/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/exp_mrs_traits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file exp_mrs_traits.H
/// @brief Contains the mc specific traits and settings for the mrs engine
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _EXP_MRS_TRAITS_H_
#define _EXP_MRS_TRAITS_H_

#include <fapi2.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

#include <generic/memory/lib/utils/mss_rank.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/shared/exp_consts.H>
#include <lib/exp_attribute_accessors_manual.H>
#include <lib/mc/exp_port.H>
#include <generic/memory/lib/dimm/mrs_traits.H>

///
/// @class mrsTraits
/// @brief Nimbus MRS Engine traits
///
template<>
class mrsTraits<mss::mc_type::EXPLORER>
{
    public:

        static constexpr fapi2::TargetType PORT_TARGET_TYPE = fapi2::TARGET_TYPE_MEM_PORT;
        static constexpr uint64_t TCCD_S = 4;
        static constexpr uint64_t TMRD = 16;

        ///
        /// @brief Returns if rcd mirror mode on
        /// @return false, currently set to disabled
        ///
        static uint8_t attr_mirror_mode_on()
        {
            constexpr uint8_t MIRRORED = 0x01;
            return MIRRORED;
        }

        ///
        /// @brief Returns if mirror mode is enabled, currently set to disabled
        /// @param[in] const ref to the fapi2::Target<fapi2::TARGET_TYPE_DIMM>
        /// @param[in] i_port_rank the rank on which to operate from the port perspective
        /// @param[out] ref to the value uint8_t
        /// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
        ///
        static fapi2::ReturnCode mirror_mode(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             const uint64_t i_port_rank,
                                             uint8_t& o_value)
        {
            constexpr uint64_t SINGLE_RANK_MASK = 0x1;

            // Makes sure that we have a good rank passed in
            FAPI_ASSERT(i_port_rank < mss::exp::MAX_MRANK_PER_PORT,
                        fapi2::MSS_INVALID_RANK().
                        set_FUNCTION(mss::generic_ffdc_codes::MRS_MIRROR_MODE).
                        set_RANK(i_port_rank).
                        set_PORT_TARGET(mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target)),
                        "%s mirror mode received invalid rank: %d",
                        mss::c_str(i_target), i_port_rank);

            FAPI_TRY(mss::attr::get_exp_dram_address_mirroring(i_target, o_value));

            {
                const auto l_dimm_rank = i_port_rank % mss::exp::MAX_RANK_PER_DIMM;
                o_value = o_value >> l_dimm_rank;
                o_value &= SINGLE_RANK_MASK;
            }

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Calls the get_dimm_target_from_rank port api
        /// @param[in] i_target the port target
        /// @param[in] i_port_rank the port rank number
        /// @param[out] o_dimm the DIMM target
        /// @return FAPI2_RC_SUCCESS iff all is ok, FAPI2_RC_INVALID_PARAMETER otherwise
        ///
        static fapi2::ReturnCode get_dimm_target_wrap (const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                const uint64_t i_port_rank,
                fapi2::Target<fapi2::TARGET_TYPE_DIMM>& o_dimm)
        {
            fapi2::ReturnCode l_rc;
            auto l_rank_info = mss::rank::info<mss::mc_type::EXPLORER>(i_target, i_port_rank, l_rc);
            FAPI_TRY (l_rc);
            o_dimm = l_rank_info.get_dimm_target();

        fapi_try_exit:
            return l_rc;
        }

        ///
        /// @brief Calls the ATTR_EFF_DRAM_TCCD_L getter
        /// @param[in] const ref to the TARGET_TYPE_MEM_PORT
        /// @param[out] uint8_t& reference to store the value
        /// @return FAPI2_RC_SUCCESS iff all is ok, FAPI2_RC_INVALID_PARAMETER otherwise
        ///
        static fapi2::ReturnCode dram_tccd_l (const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, uint8_t& o_value)
        {
            return mss::attr::get_dram_tccd_l(i_target, o_value);
        }

        ///
        /// @brief Calls the ATTR_EFF_DRAM_TRP getter
        /// @param[in] const ref to the TARGET_TYPE_MEM_PORT
        /// @param[out] uint8_t& reference to store the value
        /// @return FAPI2_RC_SUCCESS iff all is ok, FAPI2_RC_INVALID_PARAMETER otherwise
        ///
        static fapi2::ReturnCode dram_trp (const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, uint8_t& o_value)
        {
            return mss::attr::get_dram_trp(i_target, o_value);
        }

        ///
        /// @brief Calls the ATTR_EFF_DRAM_TCCD_L getter
        /// @param[in] const ref to the TARGET_TYPE_MEM_PORT
        /// @param[out] uint8_t& reference to store the value
        /// @return FAPI2_RC_SUCCESS iff all is ok, FAPI2_RC_INVALID_PARAMETER otherwise
        ///
        static fapi2::ReturnCode dram_tccd_l (const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, uint8_t& o_value)
        {
            auto l_port_target = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);
            return mss::attr::get_dram_tccd_l(l_port_target, o_value);
        }

        ///
        /// @brief Calls the ATTR_EFF_DRAM_TRP getter
        /// @param[in] const ref to the TARGET_TYPE_MEM_PORT
        /// @param[out] uint8_t& reference to store the value
        /// @return FAPI2_RC_SUCCESS iff all is ok, FAPI2_RC_INVALID_PARAMETER otherwise
        ///
        static fapi2::ReturnCode dram_trp (const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, uint8_t& o_value)
        {
            auto l_port_target = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);
            return mss::attr::get_dram_trp(l_port_target, o_value);
        }

        ///
        /// @brief Calls the tmod timing api
        /// @tparam T fapi2::TargetType of the target used to calculate cycles from ns
        /// @param[in] i_target the target used to get clocks
        /// @return max(24nCK,15ns) in clocks
        /// @note Returning the worst case tMOD - 24 nCK
        ///
        template < fapi2::TargetType T >
        static uint64_t mrs_tmod( const fapi2::Target<T>& i_target )
        {
            constexpr uint64_t WORST_CASE_TMOD = 24;
            return WORST_CASE_TMOD;
        }

        // Enum for the nibble locations in register
        enum nibble : size_t
        {
            LOWER = 2,
            UPPER = 3,
        };

        // function space and control word definitions
        // Need verification
        enum db02_def : size_t
        {
            // Function spaces
            FUNC_SPACE_0 = 0,
            FUNC_SPACE_1 = 1,
            FUNC_SPACE_2 = 2,
            FUNC_SPACE_3 = 3,
            FUNC_SPACE_4 = 4,
            FUNC_SPACE_5 = 5,
            FUNC_SPACE_6 = 6,
            FUNC_SPACE_7 = 7,

            // From DB02 spec - F[3:0]BC7x control word
            MAX_FUNC_SPACE = FUNC_SPACE_7,

            // 4 bit BCWs
            DQ_RTT_NOM_CW = 0x0,
            DQ_RTT_WR_CW = 0x1,
            DQ_RTT_PARK_CW = 0x2,
            DQ_DRIVER_CW = 0x3,
            MDQ_RTT_CW = 0x4,
            MDQ_DRIVER_CW = 0x5,
            CMD_SPACE_CW = 0x6,
            RANK_PRESENCE_CW = 0x7,
            RANK_SELECTION_CW = 0x8,
            POWER_SAVING_CW = 0x9,
            OPERATING_SPEED = 0xA,
            VOLT_AND_SLEW_RATE_CW = 0xB,
            BUFF_TRAIN_MODE_CW = 0xC,
            LDQ_OPERATION_CW = 0xD,
            PARITY_CW = 0xE,
            ERROR_STATUS_CW = 0xF,
            FUNC_SPACE_SELECT_CW = 0x7,

            // 8 bit BCWs
            BUFF_CONFIG_CW = 0x1, // Func space 0
            LRDIMM_OPERATING_SPEED = 0x6, // Func space 0
            HOST_DFE = 0xE, // Func space 2
            HOST_VREF_CW = 0x5, // Func space 5
            DRAM_VREF_CW = 0x6, // Func space 5
            BUFF_TRAIN_CONFIG_CW = 0x4, // Func space 6

            // Safe delays for BCW's
            BCW_SAFE_DELAY = 2000,
        };

};

#endif
