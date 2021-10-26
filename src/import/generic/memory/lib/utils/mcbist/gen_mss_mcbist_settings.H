/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mcbist/gen_mss_mcbist_settings.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file gen_mss_mcbist_settings.H
/// @brief MCBIST settings, like stop conditions, thresholds, etc
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _GEN_MSS_MCBIST_SETTINGS_H_
#define _GEN_MSS_MCBIST_SETTINGS_H_

#include <fapi2.H>

#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_traits.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_address.H>
#include <generic/memory/lib/utils/bit_count.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_patterns.H>

namespace mss
{

namespace mcbist
{
///
/// @brief End boundaries for MCBIST programs - where to stop when stopping or pausing
///
enum end_boundary : uint64_t
{
    // We're gonna get a little hacky here. The pause on error mode field
    // is two bits, with another bit representing slave/master. So we craft
    // the enum so that we can insertFromRight and get the proper vaules, and
    // leave one bit out of that two-bit range to represent master or slave
    NONE                      = 0b000,
    STOP_AFTER_ADDRESS        = 0b001,
    STOP_AFTER_MASTER_RANK    = 0b010,
    STOP_AFTER_SLAVE_RANK     = 0b110,
    STOP_AFTER_SUBTEST        = 0b011,

    DONT_CHANGE               = 0xFF,
};

///
/// @brief Speeds for performing MCBIST operations
///
enum speed
{
    /// As fast as possible, often the default
    LUDICROUS = 0,

    /// Background scrubbing speed.
    BG_SCRUB = 1,

    /// Used to indicate to the continue current command to not change the speed of the commands
    SAME_SPEED = 4,
};

///
/// @class Memory diagnostic subsystem stop-on-error settings and thresholds
/// @tparam MC the mc type of the T
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @note Matches Nimbus MBSTRQ, but might be changed later for Centaur, or mapped.
///
template< mss::mc_type MC, fapi2::TargetType T = mss::mcbistMCTraits<MC>::MC_TARGET_TYPE , typename TT = mss::mcbistTraits<MC, T> >
class stop_conditions
{
    public:

        // Many of the config fields share a disable bit pattern, so we define it here
        static constexpr uint64_t DISABLE       = 0b1111;
        static constexpr uint64_t MAX_THRESHOLD = 0b1110;
        static constexpr uint64_t DONT_CHANGE = 0;

    private:

        ///
        /// @brief Little helper to convert threshold inputs to exponents
        /// @param[in] i_value, the value of the threshold (presumably)
        /// @return a value n such that 2^n <= i_value && n < 15
        ///
        uint64_t make_threshold_setting( const uint64_t i_value )
        {
            // If the user passes in DISABLE, let it past. This prevents callers from having to
            // do the conditional. Zero is none which is disable
            if ((i_value == DISABLE) || (i_value == 0))
            {
                return DISABLE;
            }

            // Find the first bit set. This represents the largest power of 2 this input can represent
            // The subtraction from 63 switches from a left-count to a right-count (e.g., 0 (left most
            // bit) is really bit 63 if you start on the right.)
            const uint64_t l_largest = 63 - first_bit_set(i_value);

            // If the first bit set is off in space and greater than 2^14, we just return 0b1110
            // Otherwise, l_largest is the droid we're looking for
            return l_largest >= MAX_THRESHOLD ? MAX_THRESHOLD : l_largest;
        }

        ///
        /// @brief Generic pause on threshold
        /// @tparam F, the bit field to manipulate
        /// @tparam L, the length of F
        /// @param[in] the state of the error - mss::ON or mss::OFF
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        /// @note If the input is mss::ON, this method enables the error, it's corresponding
        /// threshold defines the threshold at which the engine will stop. If no threshold is
        /// defined (the error is disabled) this method will set the threshold to 1. A previously
        /// defined threshold (i.e., not disabled) will be left intact. If the input
        /// is mss::OFF, this method will disable the error by setting the threshold to disabled.
        ///
        template< uint64_t F, uint64_t L >
        inline stop_conditions<MC, T, TT>& set_pause_on_threshold( const states i_on_or_off )
        {
            if (i_on_or_off == mss::OFF)
            {
                iv_value.insertFromRight<F, L>(DISABLE);
                return *this;
            }

            uint64_t l_thresh = 0;
            iv_value.extractToRight<F, L>(l_thresh);

            if (l_thresh == DISABLE)
            {
                // Note the threshold field is an exponent, so this is 2^0, or 1 count
                iv_value.insertFromRight<F, L>(0);
            }

            return *this;
        }

    public:
        ///
        /// @brief Stop/Thresholds class ctor
        ///
        stop_conditions():
            iv_value(0)
        {
            // By default we want to start everything in 'don't stop' mode. This means disabling
            // the errors which contain thresholds
            set_thresh_nce_int(DISABLE)
            .set_thresh_nce_soft(DISABLE)
            .set_thresh_nce_hard(DISABLE)
            .set_thresh_rce(DISABLE)
            .set_thresh_ice(DISABLE)
            .set_thresh_mce_int(DISABLE)
            .set_thresh_mce_soft(DISABLE)
            .set_thresh_mce_hard(DISABLE);
        }

        ///
        /// @brief Stop/Thresholds class ctor
        /// @param[in] uint64_t representing the threshold register contents
        ///
        stop_conditions(const uint64_t i_value):
            iv_value(i_value)
        {
        }

        ///
        /// @brief Stop/Thresholds class dtor
        ///
        ~stop_conditions() = default;

        ///
        /// @brief uint64_t conversion
        ///
        inline operator uint64_t() const
        {
            return uint64_t(iv_value);
        }

        ///
        /// @brief set_thresh_nce_int
        /// @param[in] i_value the value of the field
        /// NCE intermittent error threshold magnitude to trigger for triggering pause. If
        /// 1111, then pause will never be triggered (disabled). Else, then MCBIST will
        /// pause if it takes sees 2^[this value] number of errors of this type.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        /// @note The register field is actually an exponent. The hardware will count 2^n for the
        /// threshold. However, the input represents a count - how many. Thus we need to convert
        /// the input to a power of 2 to get a proper exponent. Your input will be rounded down
        /// to the nearest power of 2 which is less than 2^15 before being set in the register.
        ///
        inline stop_conditions<MC, T, TT>& set_thresh_nce_int( const uint64_t i_value )
        {
            iv_value.insertFromRight<TT::MBSTRQ_CFG_THRESH_MAG_NCE_INT,
                                     TT::MBSTRQ_CFG_THRESH_MAG_NCE_INT_LEN>(make_threshold_setting(i_value));
            return *this;
        }

        ///
        /// @brief set_pause_on_nce_int - enable NCE intermittent error
        /// @param[in] i_on_or_off - the desired state.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        /// @note If the input is mss::ON, this method enables the error, it's corresponding
        /// threshold defines the threshold at which the engine will stop. If no threshold is
        /// defined (the error is disabled) this method will set the threshold to 1. A previously
        /// defined threshold (i.e., not disabled) will be left intact. If the input
        /// is mss::OFF, this method will disable the error by setting the threshold to disabled.
        ///
        inline stop_conditions<MC, T, TT>& set_pause_on_nce_int( const states i_on_or_off )
        {
            return set_pause_on_threshold<TT::MBSTRQ_CFG_THRESH_MAG_NCE_INT,
                   TT::MBSTRQ_CFG_THRESH_MAG_NCE_INT_LEN>(i_on_or_off);
        }

        ///
        /// @brief set_thresh_nce_soft
        /// @param[in] i_value the value of the field
        /// NCE soft error threshold magnitude to trigger for triggering pause. If 1111,
        /// then pause will never be triggered (disabled). Else, then MCBIST will pause if it
        /// takes sees 2^[this value] number of errors of this type.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        /// @note The register field is actually an exponent. The hardware will count 2^n for the
        /// threshold. However, the input represents a count - how many. Thus we need to convert
        /// the input to a power of 2 to get a proper exponent. Your input will be rounded down
        /// to the nearest power of 2 which is less than 2^15 before being set in the register.
        ///
        inline stop_conditions<MC, T, TT>& set_thresh_nce_soft( const uint64_t i_value )
        {
            iv_value.insertFromRight<TT::MBSTRQ_CFG_THRESH_MAG_NCE_SOFT,
                                     TT::MBSTRQ_CFG_THRESH_MAG_NCE_SOFT_LEN>(make_threshold_setting(i_value));
            return *this;
        }

        ///
        /// @brief set_pause_on_nce_int - enable NCE soft error
        /// @param[in] i_on_or_off - the desired state.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        /// @note If the input is mss::ON, this method enables the error, it's corresponding
        /// threshold defines the threshold at which the engine will stop. If no threshold is
        /// defined (the error is disabled) this method will set the threshold to 1. A previously
        /// defined threshold (i.e., not disabled) will be left intact. If the input
        /// is mss::OFF, this method will disable the error by setting the threshold to disabled.
        ///
        inline stop_conditions<MC, T, TT>& set_pause_on_nce_soft( const states i_on_or_off )
        {
            return set_pause_on_threshold<TT::MBSTRQ_CFG_THRESH_MAG_NCE_SOFT,
                   TT::MBSTRQ_CFG_THRESH_MAG_NCE_SOFT_LEN>(i_on_or_off);
        }

        ///
        /// @brief set_thresh_nce_hard
        /// @param[in] i_value the value of the field
        /// NCE hard error threshold magnitude to trigger for triggering pause. If 1111,
        /// then pause will never be triggered (disabled). Else, then MCBIST will pause if it
        /// takes sees 2^[this value] number of errors of this type.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        /// @note The register field is actually an exponent. The hardware will count 2^n for the
        /// threshold. However, the input represents a count - how many. Thus we need to convert
        /// the input to a power of 2 to get a proper exponent. Your input will be rounded down
        /// to the nearest power of 2 which is less than 2^15 before being set in the register.
        ///
        inline stop_conditions<MC, T, TT>& set_thresh_nce_hard( const uint64_t i_value )
        {
            iv_value.insertFromRight<TT::MBSTRQ_CFG_THRESH_MAG_NCE_HARD,
                                     TT::MBSTRQ_CFG_THRESH_MAG_NCE_HARD_LEN>(make_threshold_setting(i_value));
            return *this;
        }

        ///
        /// @brief set_pause_on_nce_hard - enable NCE hard error
        /// @param[in] i_on_or_off - the desired state.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        /// @note If the input is mss::ON, this method enables the error, it's corresponding
        /// threshold defines the threshold at which the engine will stop. If no threshold is
        /// defined (the error is disabled) this method will set the threshold to 1. A previously
        /// defined threshold (i.e., not disabled) will be left intact. If the input
        /// is mss::OFF, this method will disable the error by setting the threshold to disabled.
        ///
        inline stop_conditions<MC, T, TT>& set_pause_on_nce_hard( const states i_on_or_off )
        {
            return set_pause_on_threshold<TT::MBSTRQ_CFG_THRESH_MAG_NCE_HARD,
                   TT::MBSTRQ_CFG_THRESH_MAG_NCE_HARD_LEN>(i_on_or_off);
        }

        ///
        /// @brief set_thresh_rce
        /// @param[in] i_value the value of the field
        /// RCE error threshold magnitude to trigger for triggering pause. If 1111, then
        /// pause will never be triggered (disabled). Else, then MCBIST will pause if it takes
        /// sees 2^[this value] number of errors of this type.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        /// @note The register field is actually an exponent. The hardware will count 2^n for the
        /// threshold. However, the input represents a count - how many. Thus we need to convert
        /// the input to a power of 2 to get a proper exponent. Your input will be rounded down
        /// to the nearest power of 2 which is less than 2^15 before being set in the register.
        ///
        inline stop_conditions<MC, T, TT>& set_thresh_rce( const uint64_t i_value )
        {
            iv_value.insertFromRight<TT::MBSTRQ_CFG_THRESH_MAG_RCE,
                                     TT::MBSTRQ_CFG_THRESH_MAG_RCE_LEN>(make_threshold_setting(i_value));
            return *this;
        }

        ///
        /// @brief set_pause_on_rce - enable RCE error
        /// @param[in] i_on_or_off - the desired state.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        /// @note If the input is mss::ON, this method enables the error, it's corresponding
        /// threshold defines the threshold at which the engine will stop. If no threshold is
        /// defined (the error is disabled) this method will set the threshold to 1. A previously
        /// defined threshold (i.e., not disabled) will be left intact. If the input
        /// is mss::OFF, this method will disable the error by setting the threshold to disabled.
        ///
        inline stop_conditions<MC, T, TT>& set_pause_on_rce( const states i_on_or_off )
        {
            return set_pause_on_threshold<TT::MBSTRQ_CFG_THRESH_MAG_RCE,
                   TT::MBSTRQ_CFG_THRESH_MAG_RCE_LEN>(i_on_or_off);
        }

        ///
        /// @brief set_thresh_ice
        /// @param[in] i_value the value of the field
        /// ICE (IMPE) error threshold magnitude to trigger for triggering pause. If 1111,
        /// then pause will never be triggered (disabled). Else, then MCBIST will pause if
        /// it takes sees 2^[this value] number of errors of this type.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        /// @note The register field is actually an exponent. The hardware will count 2^n for the
        /// threshold. However, the input represents a count - how many. Thus we need to convert
        /// the input to a power of 2 to get a proper exponent. Your input will be rounded down
        /// to the nearest power of 2 which is less than 2^15 before being set in the register.
        ///
        inline stop_conditions<MC, T, TT>& set_thresh_ice( const uint64_t i_value )
        {
            iv_value.insertFromRight<TT::MBSTRQ_CFG_THRESH_MAG_ICE,
                                     TT::MBSTRQ_CFG_THRESH_MAG_ICE_LEN>(make_threshold_setting(i_value));
            return *this;
        }

        ///
        /// @brief set_pause_on_ice - enable ICE (IMPE) error
        /// @param[in] i_on_or_off - the desired state.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        /// @note If the input is mss::ON, this method enables the error, it's corresponding
        /// threshold defines the threshold at which the engine will stop. If no threshold is
        /// defined (the error is disabled) this method will set the threshold to 1. A previously
        /// defined threshold (i.e., not disabled) will be left intact. If the input
        /// is mss::OFF, this method will disable the error by setting the threshold to disabled.
        ///
        inline stop_conditions<MC, T, TT>& set_pause_on_ice( const states i_on_or_off )
        {
            return set_pause_on_threshold<TT::MBSTRQ_CFG_THRESH_MAG_ICE,
                   TT::MBSTRQ_CFG_THRESH_MAG_ICE_LEN>(i_on_or_off);
        }

        ///
        /// @brief set_thresh_mce_int
        /// @param[in] i_value the value of the field
        /// MCE intermittent error threshold magnitude to trigger for triggering pause. If
        /// 1111, then pause will never be triggered (disabled). Else, then MCBIST will
        /// pause if it takes sees 2^[this value] number of errors of this type.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        /// @note The register field is actually an exponent. The hardware will count 2^n for the
        /// threshold. However, the input represents a count - how many. Thus we need to convert
        /// the input to a power of 2 to get a proper exponent. Your input will be rounded down
        /// to the nearest power of 2 which is less than 2^15 before being set in the register.
        ///
        inline stop_conditions<MC, T, TT>& set_thresh_mce_int( const uint64_t i_value )
        {
            iv_value.insertFromRight<TT::MBSTRQ_CFG_THRESH_MAG_MCE_INT,
                                     TT::MBSTRQ_CFG_THRESH_MAG_MCE_INT_LEN>(make_threshold_setting(i_value));
            return *this;
        }

        ///
        /// @brief set_pause_on_mce_int - enable MCE intermittent error
        /// @param[in] i_on_or_off - the desired state.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        /// @note If the input is mss::ON, this method enables the error, it's corresponding
        /// threshold defines the threshold at which the engine will stop. If no threshold is
        /// defined (the error is disabled) this method will set the threshold to 1. A previously
        /// defined threshold (i.e., not disabled) will be left intact. If the input
        /// is mss::OFF, this method will disable the error by setting the threshold to disabled.
        ///
        inline stop_conditions<MC, T, TT>& set_pause_on_mce_int( const states i_on_or_off )
        {
            return set_pause_on_threshold<TT::MBSTRQ_CFG_THRESH_MAG_MCE_INT,
                   TT::MBSTRQ_CFG_THRESH_MAG_MCE_INT_LEN>(i_on_or_off);
        }

        ///
        /// @brief set_thresh_mce_soft
        /// @param[in] i_value the value of the field
        /// MCE soft error threshold magnitude to trigger for triggering pause. If 1111,
        /// then pause will never be triggered (disabled). Else, then MCBIST will pause if it
        /// takes sees 2^[this value] number of errors of this type.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        /// @note The register field is actually an exponent. The hardware will count 2^n for the
        /// threshold. However, the input represents a count - how many. Thus we need to convert
        /// the input to a power of 2 to get a proper exponent. Your input will be rounded down
        /// to the nearest power of 2 which is less than 2^15 before being set in the register.
        ///
        inline stop_conditions<MC, T, TT>& set_thresh_mce_soft( const uint64_t i_value )
        {
            iv_value.insertFromRight<TT::MBSTRQ_CFG_THRESH_MAG_MCE_SOFT,
                                     TT::MBSTRQ_CFG_THRESH_MAG_MCE_SOFT_LEN>(make_threshold_setting(i_value));
            return *this;
        }

        ///
        /// @brief set_pause_on_mce_soft - enable MCE soft error
        /// @param[in] i_on_or_off - the desired state.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        /// @note If the input is mss::ON, this method enables the error, it's corresponding
        /// threshold defines the threshold at which the engine will stop. If no threshold is
        /// defined (the error is disabled) this method will set the threshold to 1. A previously
        /// defined threshold (i.e., not disabled) will be left intact. If the input
        /// is mss::OFF, this method will disable the error by setting the threshold to disabled.
        ///
        inline stop_conditions<MC, T, TT>& set_pause_on_mce_soft( const states i_on_or_off )
        {
            return set_pause_on_threshold<TT::MBSTRQ_CFG_THRESH_MAG_MCE_SOFT,
                   TT::MBSTRQ_CFG_THRESH_MAG_MCE_SOFT_LEN>(i_on_or_off);
        }

        ///
        /// @brief set_thresh_mce_hard
        /// @param[in] i_value the value of the field
        /// MCE hard error threshold magnitude to trigger for triggering pause. If 1111,
        /// then pause will never be triggered (disabled). Else, then MCBIST will pause if it
        /// takes sees 2^[this value] number of errors of this type.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        /// @note The register field is actually an exponent. The hardware will count 2^n for the
        /// threshold. However, the input represents a count - how many. Thus we need to convert
        /// the input to a power of 2 to get a proper exponent. Your input will be rounded down
        /// to the nearest power of 2 which is less than 2^15 before being set in the register.
        ///
        inline stop_conditions<MC, T, TT>& set_thresh_mce_hard( const uint64_t i_value )
        {
            iv_value.insertFromRight<TT::MBSTRQ_CFG_THRESH_MAG_MCE_HARD,
                                     TT::MBSTRQ_CFG_THRESH_MAG_MCE_HARD_LEN>(make_threshold_setting(i_value));
            return *this;
        }

        ///
        /// @brief set_pause_on_mce_hard - enable MCE hard error
        /// @param[in] i_on_or_off - the desired state.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        /// @note If the input is mss::ON, this method enables the error, it's corresponding
        /// threshold defines the threshold at which the engine will stop. If no threshold is
        /// defined (the error is disabled) this method will set the threshold to 1. A previously
        /// defined threshold (i.e., not disabled) will be left intact. If the input
        /// is mss::OFF, this method will disable the error by setting the threshold to disabled.
        ///
        inline stop_conditions<MC, T, TT>& set_pause_on_mce_hard( const states i_on_or_off )
        {
            return set_pause_on_threshold<TT::MBSTRQ_CFG_THRESH_MAG_MCE_HARD,
                   TT::MBSTRQ_CFG_THRESH_MAG_MCE_HARD_LEN>(i_on_or_off);
        }

        ///
        /// @brief set_pause_on_sce
        /// @param[in] i_on_or_off - the desired state.
        /// Enable pause on SCE error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions<MC, T, TT>& set_pause_on_sce( const states i_on_or_off )
        {
            iv_value.writeBit<TT::MBSTRQ_CFG_PAUSE_ON_SCE>(i_on_or_off);
            return *this;
        }

        ///
        /// @brief set_pause_on_mce
        /// @param[in] i_on_or_off - the desired state.
        /// Enable pause on MCE error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions<MC, T, TT>& set_pause_on_mce( const states i_on_or_off )
        {
            iv_value.writeBit<TT::MBSTRQ_CFG_PAUSE_ON_MCE>(i_on_or_off);
            return *this;
        }

        ///
        /// @brief set_pause_on_mpe
        /// @param[in] i_on_or_off - the desired state.
        /// Enable pause on MPE error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions<MC, T, TT>& set_pause_on_mpe( const states i_on_or_off )
        {
            iv_value.writeBit<TT::MBSTRQ_CFG_PAUSE_ON_MPE>(i_on_or_off);
            return *this;
        }

        ///
        /// @brief set_pause_on_ue
        /// @param[in] i_on_or_off - the desired state.
        /// Enable pause on UE error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions<MC, T, TT>& set_pause_on_ue( const states i_on_or_off )
        {
            iv_value.writeBit<TT::MBSTRQ_CFG_PAUSE_ON_UE>(i_on_or_off);
            return *this;
        }

        ///
        /// @brief set_pause_on_sue
        /// @param[in] i_on_or_off - the desired state.
        /// Enable pause on SUE error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions<MC, T, TT>& set_pause_on_sue( const states i_on_or_off )
        {
            iv_value.writeBit<TT::MBSTRQ_CFG_PAUSE_ON_SUE>(i_on_or_off);
            return *this;
        }

        ///
        /// @brief set_pause_on_aue
        /// @param[in] i_on_or_off - the desired state.
        /// Enable pause on AUE error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions<MC, T, TT>& set_pause_on_aue( const states i_on_or_off )
        {
            iv_value.writeBit<TT::MBSTRQ_CFG_PAUSE_ON_AUE>(i_on_or_off);
            return *this;
        }

        ///
        /// @brief set_pause_on_rcd
        /// @param[in] i_on_or_off - the desired state.
        /// Enable pause on RCD error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions<MC, T, TT>& set_pause_on_rcd( const states i_on_or_off )
        {
            iv_value.writeBit<TT::MBSTRQ_CFG_PAUSE_ON_RCD>(i_on_or_off);
            return *this;
        }

        ///
        /// @brief set_symbol_counter_mode
        /// @param[in] i_value the value of the field
        /// Selects which mode to use symbol counter latches: Mode 0) MAINT 8-bit error
        /// counters for of 72 symbols Mode 1) MCBIST 4-bit error counters for 18 nibbles x 8
        /// ranks (port agnostic) Mode 2) MCBIST 4-bit error counters for 18 nibbles x 4
        /// ports (rank agnostic) and 1-bit error rank map for 18 nibbles x 4 ports
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions<MC, T, TT>& set_symbol_counter_mode( const uint64_t i_value )
        {
            iv_value.insertFromRight<TT::MBSTRQ_CFG_SYMBOL_COUNTER_MODE,
                                     TT::MBSTRQ_CFG_SYMBOL_COUNTER_MODE_LEN>(i_value);
            return *this;
        }

        ///
        /// @brief set_nce_soft_symbol_count_enable
        /// @param[in] i_on_or_off - the desired state.
        /// Enables soft NCEs to trigger per symbol NCE error counting Only applies to
        /// scrub where we have different types of NCE. Non scrub counts all NCE.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions<MC, T, TT>& set_nce_soft_symbol_count_enable( const states i_on_or_off )
        {
            iv_value.writeBit<TT::MBSTRQ_CFG_NCE_SOFT_SYMBOL_COUNT_ENABLE>(i_on_or_off);
            return *this;
        }

        ///
        /// @brief set_nce_inter_symbol_count_enable
        /// @param[in] i_on_or_off - the desired state.
        /// Enables intermittent NCEs to trigger per symbol NCE error counting Only applies
        /// to scrub where we have different types of NCE. Non scrub counts all NCE.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions<MC, T, TT>& set_nce_inter_symbol_count_enable( const states i_on_or_off )
        {
            iv_value.writeBit<TT::MBSTRQ_CFG_NCE_INTER_SYMBOL_COUNT_ENABLE>(i_on_or_off);
            return *this;
        }

        ///
        /// @brief set_nce_hard_symbol_count_enable
        /// @param[in] i_on_or_off - the desired state.
        /// Enables hard NCEs to trigger per symbol NCE error counting Only applies to
        /// scrub where we have different types of NCE. Non scrub counts all NCE.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions<MC, T, TT>& set_nce_hard_symbol_count_enable( const states i_on_or_off )
        {
            iv_value.writeBit<TT::MBSTRQ_CFG_NCE_HARD_SYMBOL_COUNT_ENABLE>(i_on_or_off);
            return *this;
        }

        ///
        /// @brief set_pause_mcb_error
        /// @param[in] i_on_or_off - the desired state.
        /// Enable pause when MCBIST error is logged. When enabled, MCBIST will pause at
        /// the boundary configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions<MC, T, TT>& set_pause_mcb_error( const states i_on_or_off )
        {
            iv_value.writeBit<TT::MBSTRQ_CFG_PAUSE_MCB_ERROR>(i_on_or_off);
            return *this;
        }

        ///
        /// @brief set_pause_mcb_log_full
        /// @param[in] i_on_or_off - the desired state.
        /// Enable pause when MCBIST log is full. When enabled, MCBIST will pause at the
        /// boundary configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions<MC, T, TT>& set_pause_mcb_log_full( const states i_on_or_off )
        {
            iv_value.writeBit<TT::MBSTRQ_CFG_PAUSE_MCB_LOG_FULL>(i_on_or_off);
            return *this;
        }

        ///
        /// @brief set_maint_rce_with_ce
        /// @param[in] i_on_or_off - the desired state.
        /// cfg_maint_rce_with_ce - not implemented. Need to investigate if needed for nimbus.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions<MC, T, TT>& set_maint_rce_with_ce( const states i_on_or_off )
        {
            iv_value.writeBit<TT::MBSTRQ_CFG_MAINT_RCE_WITH_CE>(i_on_or_off);
            return *this;
        }

        ///
        /// @brief set_mce_soft_symbol_count_enable
        /// @param[in] i_on_or_off - the desired state.
        /// Enables soft MCEs to trigger per symbol MCE error counting Only applies to
        /// scrub where we have different types of MCE. Non scrub counts all MCE.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions<MC, T, TT>& set_mce_soft_symbol_count_enable( const states i_on_or_off )
        {
            iv_value.writeBit<TT::MBSTRQ_CFG_MCE_SOFT_SYMBOL_COUNT_ENABLE>(i_on_or_off);
            return *this;
        }

        ///
        /// @brief set_mce_inter_symbol_count_enable
        /// @param[in] i_on_or_off - the desired state.
        /// Enables intermittent MCEs to trigger per symbol MCE error counting Only applies
        /// to scrub where we have different types of MCE. Non scrub counts all MCE.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions<MC, T, TT>& set_mce_inter_symbol_count_enable( const states i_on_or_off )
        {
            iv_value.writeBit<TT::MBSTRQ_CFG_MCE_INTER_SYMBOL_COUNT_ENABLE>(i_on_or_off);
            return *this;
        }

        ///
        /// @brief set_mce_hard_symbol_count_enable
        /// @param[in] i_on_or_off - the desired state.
        /// Enables hard MCEs to trigger per symbol MCE error counting Only applies to
        /// scrub where we have different types of MCE. Non scrub counts all MCE.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions<MC, T, TT>& set_mce_hard_symbol_count_enable( const states i_on_or_off )
        {
            iv_value.writeBit<TT::MBSTRQ_CFG_MCE_HARD_SYMBOL_COUNT_ENABLE>(i_on_or_off);
            return *this;
        }

    private:

        fapi2::buffer<uint64_t> iv_value;
};

template< mss::mc_type MC, fapi2::TargetType T, typename TT>
constexpr uint64_t stop_conditions<MC, T, TT>::DISABLE;

template< mss::mc_type MC, fapi2::TargetType T, typename TT>
constexpr uint64_t stop_conditions<MC, T, TT>::MAX_THRESHOLD;

template< mss::mc_type MC, fapi2::TargetType T, typename TT>
constexpr uint64_t stop_conditions<MC, T, TT>::DONT_CHANGE;

///
/// @class memdiags operational constraints
/// @tparam MC the mc type of the T
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
///
template< mss::mc_type MC, fapi2::TargetType T = mss::mcbistMCTraits<MC>::MC_TARGET_TYPE , typename TT = mcbistTraits<MC, T> >
struct constraints
{
    ///
    /// @brief constraints default constructor
    ///
    constraints():
        iv_stop(),
        iv_pattern(NO_PATTERN),
        iv_end_boundary(NONE),
        iv_speed(LUDICROUS),
        iv_start_address(0),
        iv_end_address(TT::LARGEST_ADDRESS)
    {
    }

    ///
    /// @brief constraints constructor
    /// @param[in] i_pattern a pattern to set
    ///
    constraints( const uint64_t i_pattern ):
        constraints()
    {
        iv_pattern = i_pattern;
        FAPI_INF("setting up constraints with pattern %d", i_pattern);
    }

    ///
    /// @brief constraints constructor
    /// @param[in] i_stop stop conditions
    ///
    constraints( const stop_conditions<MC, T, TT>& i_stop ):
        constraints()
    {
        iv_stop = i_stop;
        FAPI_INF("setting up constraints with stop 0x%016lx", uint64_t(i_stop));
    }

    ///
    /// @brief constraints constructor
    /// @param[in] i_stop stop conditions
    /// @param[in] i_start_address address to start from
    ///
    constraints( const stop_conditions<MC, T, TT>& i_stop,
                 const address& i_start_address ):
        constraints(i_stop)
    {
        iv_start_address = i_start_address;
        FAPI_INF("setting up constraints with start address 0x%016lx", uint64_t(i_start_address));
    }

    ///
    /// @brief constraints constructor
    /// @param[in] i_stop stop conditions
    /// @param[in] i_speed the speed at which to run
    /// @param[in] i_end_boundary the place to stop on error
    /// @param[in] i_start_address address to start from
    /// @param[in] i_end_address address to end at (optional, run to end)
    ///
    constraints( const stop_conditions<MC, T, TT>& i_stop,
                 const speed i_speed,
                 const end_boundary i_end_boundary,
                 const address& i_start_address,
                 const address& i_end_address = mcbist::address(TT::LARGEST_ADDRESS) ):
        constraints(i_stop, i_start_address)
    {
        iv_end_boundary = i_end_boundary;
        iv_speed = i_speed;
        iv_end_address = i_end_address;

        FAPI_INF("setting up constraints with end boundary %d and speed 0x%x", i_end_boundary, i_speed);

        // If our end address is 'before' our start address, make the end address the same as the start.
        if (iv_start_address > iv_end_address)
        {
            iv_end_address = iv_start_address;
        }
    }

    // Member variable declaration
    stop_conditions<MC, T, TT> iv_stop;
    uint64_t iv_pattern;
    end_boundary iv_end_boundary;
    speed iv_speed;
    mcbist::address iv_start_address;
    mcbist::address iv_end_address;
};


} // namespace
} // namespace
#endif
