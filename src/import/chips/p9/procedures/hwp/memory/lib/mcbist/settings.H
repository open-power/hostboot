/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/mcbist/settings.H $        */
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
/// @file settings.H
/// @brief MCBIST settings, like stop conditions, thresholds, etc
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_MCBIST_SETTINGS_H_
#define _MSS_MCBIST_SETTINGS_H_

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/mcbist/address.H>
#include <lib/utils/bit_count.H>

namespace mss
{

namespace mcbist
{

/// End boundaries for MCBIST programs - where to stop when stopping or pausing
enum end_boundary : uint64_t
{
    // We're gonna get a little hacky here. The pause on error mode field
    // is two bits, with another bit representing slave/master. So we craft
    // the enum so that we can insertFromRight and get the proper vaules, and
    // leave on bit out of that two-bit range to represent master or slave
    NONE                      = 0b000,
    STOP_AFTER_ADDRESS        = 0b001,
    STOP_AFTER_MASTER_RANK    = 0b010,
    STOP_AFTER_SLAVE_RANK     = 0b110,
    STOP_AFTER_SUBTEST        = 0b011,

    DONT_CHANGE               = 0xFF,
};

/// Speeds for performing MCBIST operations
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
/// @note Matches Nimbus MBSTRQ, but might be changed later for Centaur, or mapped.
///
class stop_conditions
{
    public:

        // Many of the config fields share a disable bit pattern, so we define it here
        static constexpr uint64_t DISABLE       = 0b1111;
        static constexpr uint64_t MAX_THRESHOLD = 0b1110;

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
            uint64_t l_largest = 63 - first_bit_set(i_value);

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
        inline stop_conditions& set_pause_on_threshold( const states i_on_or_off )
        {
            if (i_on_or_off == mss::OFF)
            {
                iv_value.insertFromRight<F, L>(DISABLE);
                return *this;
            }

            uint64_t l_thresh = 0;
            iv_value.extractToRight<F, L>(l_thresh);

            if (l_thresh != DISABLE)
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
        inline stop_conditions& set_thresh_nce_int( const uint64_t i_value )
        {
            iv_value.insertFromRight<MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_INT,
                                     MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_INT_LEN>(make_threshold_setting(i_value));
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
        inline stop_conditions& set_pause_on_nce_int( const states i_on_or_off )
        {
            return set_pause_on_threshold<MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_INT,
                   MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_INT_LEN>(i_on_or_off);
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
        inline stop_conditions& set_thresh_nce_soft( const uint64_t i_value )
        {
            iv_value.insertFromRight<MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_SOFT,
                                     MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_SOFT_LEN>(make_threshold_setting(i_value));
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
        inline stop_conditions& set_pause_on_nce_soft( const states i_on_or_off )
        {
            return set_pause_on_threshold<MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_SOFT,
                   MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_SOFT_LEN>(i_on_or_off);
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
        inline stop_conditions& set_thresh_nce_hard( const uint64_t i_value )
        {
            iv_value.insertFromRight<MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_HARD,
                                     MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_HARD_LEN>(make_threshold_setting(i_value));
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
        inline stop_conditions& set_pause_on_nce_hard( const states i_on_or_off )
        {
            return set_pause_on_threshold<MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_HARD,
                   MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_HARD_LEN>(i_on_or_off);
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
        inline stop_conditions& set_thresh_rce( const uint64_t i_value )
        {
            iv_value.insertFromRight<MCBIST_MBSTRQ_CFG_THRESH_MAG_RCE,
                                     MCBIST_MBSTRQ_CFG_THRESH_MAG_RCE_LEN>(make_threshold_setting(i_value));
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
        inline stop_conditions& set_pause_on_rce( const states i_on_or_off )
        {
            return set_pause_on_threshold<MCBIST_MBSTRQ_CFG_THRESH_MAG_RCE,
                   MCBIST_MBSTRQ_CFG_THRESH_MAG_RCE_LEN>(i_on_or_off);
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
        inline stop_conditions& set_thresh_ice( const uint64_t i_value )
        {
            iv_value.insertFromRight<MCBIST_MBSTRQ_CFG_THRESH_MAG_ICE,
                                     MCBIST_MBSTRQ_CFG_THRESH_MAG_ICE_LEN>(make_threshold_setting(i_value));
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
        inline stop_conditions& set_pause_on_ice( const states i_on_or_off )
        {
            return set_pause_on_threshold<MCBIST_MBSTRQ_CFG_THRESH_MAG_ICE,
                   MCBIST_MBSTRQ_CFG_THRESH_MAG_ICE_LEN>(i_on_or_off);
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
        inline stop_conditions& set_thresh_mce_int( const uint64_t i_value )
        {
            iv_value.insertFromRight<MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_INT,
                                     MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_INT_LEN>(make_threshold_setting(i_value));
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
        inline stop_conditions& set_pause_on_mce_int( const states i_on_or_off )
        {
            return set_pause_on_threshold<MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_INT,
                   MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_INT_LEN>(i_on_or_off);
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
        inline stop_conditions& set_thresh_mce_soft( const uint64_t i_value )
        {
            iv_value.insertFromRight<MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_SOFT,
                                     MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_SOFT_LEN>(make_threshold_setting(i_value));
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
        inline stop_conditions& set_pause_on_mce_soft( const states i_on_or_off )
        {
            return set_pause_on_threshold<MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_SOFT,
                   MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_SOFT_LEN>(i_on_or_off);
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
        inline stop_conditions& set_thresh_mce_hard( const uint64_t i_value )
        {
            iv_value.insertFromRight<MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_HARD,
                                     MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_HARD_LEN>(make_threshold_setting(i_value));
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
        inline stop_conditions& set_pause_on_mce_hard( const states i_on_or_off )
        {
            return set_pause_on_threshold<MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_HARD,
                   MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_HARD_LEN>(i_on_or_off);
        }

        ///
        /// @brief set_pause_on_sce
        /// @param[in] i_value the value of the field
        /// Enable pause on SCE error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions& set_pause_on_sce( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_PAUSE_ON_SCE>(i_value);
            return *this;
        }

        ///
        /// @brief set_pause_on_mce
        /// @param[in] i_value the value of the field
        /// Enable pause on MCE error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions& set_pause_on_mce( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_PAUSE_ON_MCE>(i_value);
            return *this;
        }

        ///
        /// @brief set_pause_on_mpe
        /// @param[in] i_value the value of the field
        /// Enable pause on MPE error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions& set_pause_on_mpe( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_PAUSE_ON_MPE>(i_value);
            return *this;
        }

        ///
        /// @brief set_pause_on_ue
        /// @param[in] i_value the value of the field
        /// Enable pause on UE error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions& set_pause_on_ue( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_PAUSE_ON_UE>(i_value);
            return *this;
        }

        ///
        /// @brief set_pause_on_sue
        /// @param[in] i_value the value of the field
        /// Enable pause on SUE error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions& set_pause_on_sue( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_PAUSE_ON_SUE>(i_value);
            return *this;
        }

        ///
        /// @brief set_pause_on_aue
        /// @param[in] i_value the value of the field
        /// Enable pause on AUE error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions& set_pause_on_aue( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_PAUSE_ON_AUE>(i_value);
            return *this;
        }

        ///
        /// @brief set_pause_on_rcd
        /// @param[in] i_value the value of the field
        /// Enable pause on RCD error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions& set_pause_on_rcd( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_PAUSE_ON_RCD>(i_value);
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
        inline stop_conditions& set_symbol_counter_mode( const uint64_t i_value )
        {
            iv_value.insertFromRight<MCBIST_MBSTRQ_CFG_SYMBOL_COUNTER_MODE,
                                     MCBIST_MBSTRQ_CFG_SYMBOL_COUNTER_MODE_LEN>(i_value);
            return *this;
        }

        ///
        /// @brief set_nce_soft_symbol_count_enable
        /// @param[in] i_value the value of the field
        /// Enables soft NCEs to trigger per symbol NCE error counting Only applies to
        /// scrub where we have different types of NCE. Non scrub counts all NCE.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions& set_nce_soft_symbol_count_enable( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_NCE_SOFT_SYMBOL_COUNT_ENABLE>(i_value);
            return *this;
        }

        ///
        /// @brief set_nce_inter_symbol_count_enable
        /// @param[in] i_value the value of the field
        /// Enables intermittent NCEs to trigger per symbol NCE error counting Only applies
        /// to scrub where we have different types of NCE. Non scrub counts all NCE.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions& set_nce_inter_symbol_count_enable( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_NCE_INTER_SYMBOL_COUNT_ENABLE>(i_value);
            return *this;
        }

        ///
        /// @brief set_nce_hard_symbol_count_enable
        /// @param[in] i_value the value of the field
        /// Enables hard NCEs to trigger per symbol NCE error counting Only applies to
        /// scrub where we have different types of NCE. Non scrub counts all NCE.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions& set_nce_hard_symbol_count_enable( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_NCE_HARD_SYMBOL_COUNT_ENABLE>(i_value);
            return *this;
        }

        ///
        /// @brief set_pause_mcb_error
        /// @param[in] i_value the value of the field
        /// Enable pause when MCBIST error is logged. When enabled, MCBIST will pause at
        /// the boundary configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions& set_pause_mcb_error( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_PAUSE_MCB_ERROR>(i_value);
            return *this;
        }

        ///
        /// @brief set_pause_mcb_log_full
        /// @param[in] i_value the value of the field
        /// Enable pause when MCBIST log is full. When enabled, MCBIST will pause at the
        /// boundary configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions& set_pause_mcb_log_full( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_PAUSE_MCB_LOG_FULL>(i_value);
            return *this;
        }

        ///
        /// @brief set_maint_rce_with_ce
        /// @param[in] i_value the value of the field
        /// cfg_maint_rce_with_ce - not implemented. Need to investigate if needed for nimbus.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions& set_maint_rce_with_ce( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_MAINT_RCE_WITH_CE>(i_value);
            return *this;
        }

        ///
        /// @brief set_mce_soft_symbol_count_enable
        /// @param[in] i_value the value of the field
        /// Enables soft MCEs to trigger per symbol MCE error counting Only applies to
        /// scrub where we have different types of MCE. Non scrub counts all MCE.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions& set_mce_soft_symbol_count_enable( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_MCE_SOFT_SYMBOL_COUNT_ENABLE>(i_value);
            return *this;
        }

        ///
        /// @brief set_mce_inter_symbol_count_enable
        /// @param[in] i_value the value of the field
        /// Enables intermittent MCEs to trigger per symbol MCE error counting Only applies
        /// to scrub where we have different types of MCE. Non scrub counts all MCE.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions& set_mce_inter_symbol_count_enable( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_MCE_INTER_SYMBOL_COUNT_ENABLE>(i_value);
            return *this;
        }

        ///
        /// @brief set_mce_hard_symbol_count_enable
        /// @param[in] i_value the value of the field
        /// Enables hard MCEs to trigger per symbol MCE error counting Only applies to
        /// scrub where we have different types of MCE. Non scrub counts all MCE.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        ///
        inline stop_conditions& set_mce_hard_symbol_count_enable( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_MCE_HARD_SYMBOL_COUNT_ENABLE>(iv_value);
            return *this;
        }

    private:

        fapi2::buffer<uint64_t> iv_value;
};

///
/// @class memdiags operational constraints
///
struct constraints
{
    ///
    /// @brief constraints constructor
    ///
    constraints():
        iv_stop(),
        iv_pattern(NO_PATTERN),
        iv_end_boundary(NONE),
        iv_speed(LUDICROUS),
        iv_start_address(0),
        iv_end_address(0)
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
    constraints( const stop_conditions& i_stop ):
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
    constraints( const stop_conditions& i_stop,
                 const address& i_start_address ):
        constraints(i_stop)
    {
        iv_start_address = i_start_address;
        FAPI_INF("setting up constraints with start address 0x%016lx", uint64_t(i_start_address));
    }

    ///
    /// @brief constraints constructor
    /// @param[in] i_stop stop conditions
    /// @param[in] i_start_address address to start from
    ///
    constraints( const stop_conditions& i_stop,
                 const speed i_speed,
                 const end_boundary i_end_boundary,
                 const address& i_start_address ):
        constraints(i_stop, i_start_address)
    {
        iv_end_boundary = i_end_boundary;
        iv_speed = i_speed;
        FAPI_INF("setting up constraints with end boundary %d and speed 0x%x", i_end_boundary, i_speed);
    }

    stop_conditions iv_stop;
    uint64_t iv_pattern;
    end_boundary iv_end_boundary;
    speed iv_speed;
    mcbist::address iv_start_address;
    mcbist::address iv_end_address;
};


} // namespace
} // namespace
#endif

