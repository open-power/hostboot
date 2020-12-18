/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/mrs_traits_nimbus.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
/// @file mrs_traits_nimbus.H
/// @brief Run and manage the CCS engine
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_MRS_TRAITS_NIMBUS_H_
#define _MSS_MRS_TRAITS_NIMBUS_H_

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/shared/mss_const.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/mc/port.H>
#include <generic/memory/lib/dimm/mrs_traits.H>
#include <lib/eff_config/timing.H>

///
/// @class mrsTraits
/// @brief Nimbus MRS Engine traits
///
template<>
class mrsTraits<mss::mc_type::NIMBUS>
{
    public:

        static constexpr fapi2::TargetType PORT_TARGET_TYPE = fapi2::TARGET_TYPE_MCA;
        static constexpr uint64_t TCCD_S = 4;
        static constexpr uint64_t TMRD = 8;

        ///
        /// @brief Returns the attribute rcd mirror mode on
        /// @return rcd mirror mode on
        ///
        static uint8_t attr_mirror_mode_on()
        {
            return fapi2::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_ON;
        }

        ///
        /// @brief Returns the ATTR_EFF_DIMM_RCD_MIRROR_MODE getter
        /// @param[in] const ref to the fapi2::Target<fapi2::TARGET_TYPE_DIMM>
        /// @param[in] i_rank the rank on which to operate
        /// @param[out] ref to the value uint8_t
        /// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
        ///
        static fapi2::ReturnCode mirror_mode(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             const uint64_t i_rank,
                                             uint8_t& o_value)
        {
            uint8_t l_value = 0;
            o_value = fapi2::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_OFF;
            FAPI_TRY(mss::eff_dimm_rcd_mirror_mode(i_target, l_value));

            // We want to mirror if this DIMM has mirroring and we're an odd rank
            o_value = ((l_value == fapi2::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_ON) &&
                       (i_rank & 0x1)) ?
                      fapi2::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_ON :
                      fapi2::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_OFF;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Calls the get_dimm_target_from_rank port api
        /// @param[in] i_target the port target
        /// @param[in] i_rank the rank number
        /// @param[out] o_dimm the DIMM target
        /// @return FAPI2_RC_SUCCESS iff all is ok, FAPI2_RC_INVALID_PARAMETER otherwise
        ///
        static fapi2::ReturnCode get_dimm_target_wrap (const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                const uint64_t i_rank,
                fapi2::Target<fapi2::TARGET_TYPE_DIMM>& o_dimm)
        {
            return mss::rank::get_dimm_target_from_rank(i_target, i_rank, o_dimm);
        }

        ///
        /// @brief Calls the is_rank_on_dimm port api
        /// @param[in] i_target representing the DIMM
        /// @param[in] i_rank the rank number.
        /// @return true iff i_rank is a rank on i_target
        ///
        static bool rank_on_dimm_wrap (const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, const uint64_t i_rank)
        {
            return mss::rank::is_rank_on_dimm(i_target, i_rank);
        }

        ///
        /// @brief Calls the tmod timing api
        /// @tparam T fapi2::TargetType of the target used to calculate cycles from ns
        /// @param[in] i_target the target used to get clocks
        /// @return max(24nCK,15ns) in clocks
        ///
        template < fapi2::TargetType T >
        static uint64_t mrs_tmod( const fapi2::Target<T>& i_target )
        {
            return mss::tmod(i_target);
        }

        ///
        /// @brief Calls the ATTR_EFF_DRAM_TCCD_L getter
        /// @param[in] const ref to the fapi2::Target<fapi2::TARGET_TYPE_MCA>
        /// @param[out] ref to the value uint8_t
        /// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
        ///
        static fapi2::ReturnCode dram_tccd_l(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, uint8_t& o_value)
        {
            return mss::eff_dram_tccd_l(i_target, o_value);
        }

        ///
        /// @brief Calls the ATTR_EFF_DRAM_TRP getter
        /// @param[in] const ref to the fapi2::Target<fapi2::TARGET_TYPE_MCA>
        /// @param[out] ref to the value uint8_t
        /// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
        ///
        static fapi2::ReturnCode dram_trp(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, uint8_t& o_value)
        {
            return mss::eff_dram_trp(i_target, o_value);
        }

        // Enum for the nibble locations in register
        enum nibble : size_t
        {
            LOWER = 2,
            UPPER = 3,
        };

        // function space and control word definitions
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
