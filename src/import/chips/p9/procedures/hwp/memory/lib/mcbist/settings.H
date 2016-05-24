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

namespace mss
{

namespace mcbist
{

/// Stop conditions for MCBIST programs
enum stop_conditions
{
    NO_STOP_ON_ERROR   = 0b00,
    STOP_AFTER_ADDRESS = 0b01,
    STOP_AFTER_RANK    = 0b10,
    STOP_AFTER_SUBTEST = 0b11,

    /// Don't change the stop conditions when continuing
    DONT_CHANGE        = 0xFF,
};

/// Boundary conditions for operations - when to stopmc
enum end_boundary
{
    NONE         = 0,
    CONTINUOUS   = NONE,
    NEVER        = NONE,
    DONT_STOP    = NONE,
    MASTER_RANK  = 1,
    MRANK        = MASTER_RANK,
    SLAVE_RANK   = 2,
    SRANK        = SLAVE_RANK,
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
/// @class Memory diagnostic subsystem error thresholds
/// @note Matches Nimbus MBSTRQ, but might be changed later for Centaur, or mapped.
///
class thresholds
{
    public:
        // Many of the config fields share a disable bit pattern, so we define it here
        static constexpr uint64_t DISABLE = 0b1111;

        ///
        /// @brief Thresholds class ctor
        ///
        thresholds():
            iv_value(0)
        { }

        ///
        /// @brief Thresholds class dtor
        ///
        ~thresholds() = default;

        ///
        /// @brief uint64_t conversion
        ///
        inline operator uint64_t() const
        {
            return uint64_t(iv_value);
        }

        /// @brief set_thresh_mag_nce_int
        /// @param[in] i_value the value of the field
        /// NCE intermittent error threshold magnitude to trigger for triggering pause. If
        /// 1111, then pause will never be triggered (disabled). Else, then MCBIST will
        /// pause if it takes sees 2^[this value] number of errors of this type.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_thresh_mag_nce_int( const uint64_t i_value )
        {
            iv_value.insertFromRight<MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_INT, MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_INT_LEN>(i_value);
            return *this;
        }

        /// @brief set_thresh_mag_nce_soft
        /// @param[in] i_value the value of the field
        /// NCE soft error threshold magnitude to trigger for triggering pause. If 1111,
        /// then pause will never be triggered (disabled). Else, then MCBIST will pause if it
        /// takes sees 2^[this value] number of errors of this type.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_thresh_mag_nce_soft( const uint64_t i_value )
        {
            iv_value.insertFromRight<MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_SOFT, MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_SOFT_LEN>(i_value);
            return *this;
        }

        /// @brief set_thresh_mag_nce_hard
        /// @param[in] i_value the value of the field
        /// NCE hard error threshold magnitude to trigger for triggering pause. If 1111,
        /// then pause will never be triggered (disabled). Else, then MCBIST will pause if it
        /// takes sees 2^[this value] number of errors of this type.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_thresh_mag_nce_hard( const uint64_t i_value )
        {
            iv_value.insertFromRight<MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_HARD, MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_HARD_LEN>(i_value);
            return *this;
        }

        /// @brief set_thresh_mag_rce
        /// @param[in] i_value the value of the field
        /// RCE error threshold magnitude to trigger for triggering pause. If 1111, then
        /// pause will never be triggered (disabled). Else, then MCBIST will pause if it takes
        /// sees 2^[this value] number of errors of this type.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_thresh_mag_rce( const uint64_t i_value )
        {
            iv_value.insertFromRight<MCBIST_MBSTRQ_CFG_THRESH_MAG_RCE, MCBIST_MBSTRQ_CFG_THRESH_MAG_RCE_LEN>(i_value);
            return *this;
        }

        /// @brief set_thresh_mag_ice
        /// @param[in] i_value the value of the field
        /// ICE (IMPE) error threshold magnitude to trigger for triggering pause. If 1111,
        /// then pause will never be triggered (disabled). Else, then MCBIST will pause if
        /// it takes sees 2^[this value] number of errors of this type.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_thresh_mag_ice( const uint64_t i_value )
        {
            iv_value.insertFromRight<MCBIST_MBSTRQ_CFG_THRESH_MAG_ICE, MCBIST_MBSTRQ_CFG_THRESH_MAG_ICE_LEN>(i_value);
            return *this;
        }

        /// @brief set_thresh_mag_mce_int
        /// @param[in] i_value the value of the field
        /// MCE intermittent error threshold magnitude to trigger for triggering pause. If
        /// 1111, then pause will never be triggered (disabled). Else, then MCBIST will
        /// pause if it takes sees 2^[this value] number of errors of this type.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_thresh_mag_mce_int( const uint64_t i_value )
        {
            iv_value.insertFromRight<MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_INT, MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_INT_LEN>(i_value);
            return *this;
        }

        /// @brief set_thresh_mag_mce_soft
        /// @param[in] i_value the value of the field
        /// MCE soft error threshold magnitude to trigger for triggering pause. If 1111,
        /// then pause will never be triggered (disabled). Else, then MCBIST will pause if it
        /// takes sees 2^[this value] number of errors of this type.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_thresh_mag_mce_soft( const uint64_t i_value )
        {
            iv_value.insertFromRight<MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_SOFT, MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_SOFT_LEN>(i_value);
            return *this;
        }

        /// @brief set_thresh_mag_mce_hard
        /// @param[in] i_value the value of the field
        /// MCE hard error threshold magnitude to trigger for triggering pause. If 1111,
        /// then pause will never be triggered (disabled). Else, then MCBIST will pause if it
        /// takes sees 2^[this value] number of errors of this type.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_thresh_mag_mce_hard( const uint64_t i_value )
        {
            iv_value.insertFromRight<MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_HARD, MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_HARD_LEN>(i_value);
            return *this;
        }

        /// @brief set_pause_on_sce
        /// @param[in] i_value the value of the field
        /// Enable pause on SCE error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_pause_on_sce( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_PAUSE_ON_SCE>(i_value);
            return *this;
        }

        /// @brief set_pause_on_mce
        /// @param[in] i_value the value of the field
        /// Enable pause on MCE error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_pause_on_mce( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_PAUSE_ON_MCE>(i_value);
            return *this;
        }

        /// @brief set_pause_on_mpe
        /// @param[in] i_value the value of the field
        /// Enable pause on MPE error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_pause_on_mpe( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_PAUSE_ON_MPE>(i_value);
            return *this;
        }

        /// @brief set_pause_on_ue
        /// @param[in] i_value the value of the field
        /// Enable pause on UE error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_pause_on_ue( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_PAUSE_ON_UE>(i_value);
            return *this;
        }

        /// @brief set_pause_on_sue
        /// @param[in] i_value the value of the field
        /// Enable pause on SUE error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_pause_on_sue( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_PAUSE_ON_SUE>(i_value);
            return *this;
        }

        /// @brief set_pause_on_aue
        /// @param[in] i_value the value of the field
        /// Enable pause on AUE error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_pause_on_aue( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_PAUSE_ON_AUE>(i_value);
            return *this;
        }

        /// @brief set_pause_on_rcd
        /// @param[in] i_value the value of the field
        /// Enable pause on RCD error. When enabled, MCBIST will pause at the boundary
        /// configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_pause_on_rcd( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_PAUSE_ON_RCD>(i_value);
            return *this;
        }

        // Reserved. 39:52

        /// @brief set_symbol_counter_mode
        /// @param[in] i_value the value of the field
        /// Selects which mode to use symbol counter latches: Mode 0) MAINT 8-bit error
        /// counters for of 72 symbols Mode 1) MCBIST 4-bit error counters for 18 nibbles x 8
        /// ranks (port agnostic) Mode 2) MCBIST 4-bit error counters for 18 nibbles x 4
        /// ports (rank agnostic) and 1-bit error rank map for 18 nibbles x 4 ports
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_symbol_counter_mode( const uint64_t i_value )
        {
            iv_value.insertFromRight<MCBIST_MBSTRQ_CFG_SYMBOL_COUNTER_MODE, MCBIST_MBSTRQ_CFG_SYMBOL_COUNTER_MODE_LEN>(i_value);
            return *this;
        }

        /// @brief set_nce_soft_symbol_count_enable
        /// @param[in] i_value the value of the field
        /// Enables soft NCEs to trigger per symbol NCE error counting Only applies to
        /// scrub where we have different types of NCE. Non scrub counts all NCE.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_nce_soft_symbol_count_enable( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_NCE_SOFT_SYMBOL_COUNT_ENABLE>(i_value);
            return *this;
        }

        /// @brief set_nce_inter_symbol_count_enable
        /// @param[in] i_value the value of the field
        /// Enables intermittent NCEs to trigger per symbol NCE error counting Only applies
        /// to scrub where we have different types of NCE. Non scrub counts all NCE.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_nce_inter_symbol_count_enable( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_NCE_INTER_SYMBOL_COUNT_ENABLE>(i_value);
            return *this;
        }

        /// @brief set_nce_hard_symbol_count_enable
        /// @param[in] i_value the value of the field
        /// Enables hard NCEs to trigger per symbol NCE error counting Only applies to
        /// scrub where we have different types of NCE. Non scrub counts all NCE.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_nce_hard_symbol_count_enable( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_NCE_HARD_SYMBOL_COUNT_ENABLE>(i_value);
            return *this;
        }

        /// @brief set_pause_mcb_error
        /// @param[in] i_value the value of the field
        /// Enable pause when MCBIST error is logged. When enabled, MCBIST will pause at
        /// the boundary configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_pause_mcb_error( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_PAUSE_MCB_ERROR>(i_value);
            return *this;
        }

        /// @brief set_pause_mcb_log_full
        /// @param[in] i_value the value of the field
        /// Enable pause when MCBIST log is full. When enabled, MCBIST will pause at the
        /// boundary configured if this error is seen.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_pause_mcb_log_full( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_PAUSE_MCB_LOG_FULL>(i_value);
            return *this;
        }

        /// @brief set_maint_rce_with_ce
        /// @param[in] i_value the value of the field
        /// cfg_maint_rce_with_ce - not implemented. Need to investigate if needed for nimbus.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_maint_rce_with_ce( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_MAINT_RCE_WITH_CE>(i_value);
            return *this;
        }

        /// @brief set_mce_soft_symbol_count_enable
        /// @param[in] i_value the value of the field
        /// Enables soft MCEs to trigger per symbol MCE error counting Only applies to
        /// scrub where we have different types of MCE. Non scrub counts all MCE.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_mce_soft_symbol_count_enable( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_MCE_SOFT_SYMBOL_COUNT_ENABLE>(i_value);
            return *this;
        }

        /// @brief set_mce_inter_symbol_count_enable
        /// @param[in] i_value the value of the field
        /// Enables intermittent MCEs to trigger per symbol MCE error counting Only applies
        /// to scrub where we have different types of MCE. Non scrub counts all MCE.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_mce_inter_symbol_count_enable( const uint64_t i_value )
        {
            iv_value.writeBit<MCBIST_MBSTRQ_CFG_MCE_INTER_SYMBOL_COUNT_ENABLE>(i_value);
            return *this;
        }

        /// @brief set_mce_hard_symbol_count_enable
        /// @param[in] i_value the value of the field
        /// Enables hard MCEs to trigger per symbol MCE error counting Only applies to
        /// scrub where we have different types of MCE. Non scrub counts all MCE.
        /// @return fapi2::buffer<uint64_t>& this->iv_value useful for method chaining
        inline thresholds& set_mce_hard_symbol_count_enable( const uint64_t i_value )
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
        iv_stop(NO_STOP_ON_ERROR),
        iv_thresholds(),
        iv_pattern(NO_PATTERN),
        iv_end_boundary(NONE),
        iv_start_address(0),
        iv_end_address(0)
    {
    }

    ///
    /// @brief constraints constructor
    /// @param[in] i_pattern a pattern to set
    ///
    constraints( const uint64_t i_pattern):
        constraints()
    {
        iv_pattern = i_pattern;
        FAPI_INF("setting up constraints with pattern %d", i_pattern);
    }

    ///
    /// @brief constraints constructor
    /// @param[in] i_stop stop conditions
    /// @param[in] i_thresholds thresholds
    ///
    constraints( const stop_conditions i_stop,
                 const thresholds& i_thresholds ):
        constraints()
    {
        iv_stop = i_stop;
        iv_thresholds = i_thresholds;
        FAPI_INF("setting up constraints with stop %d and thresholds 0x%x", i_stop, uint64_t(i_thresholds));
    }

    ///
    /// @brief constraints constructor
    /// @param[in] i_stop stop conditions
    /// @param[in] i_thresholds thresholds
    /// @param[in] i_start_address address to start from
    ///
    constraints( const stop_conditions i_stop,
                 const thresholds& i_thresholds,
                 const address& i_start_address ):
        constraints(i_stop, i_thresholds)
    {
        iv_start_address = i_start_address;
        FAPI_INF("setting up constraints with stop %d and thresholds 0x%x start address",
                 i_stop, uint64_t(i_thresholds), uint64_t(i_start_address));
    }

    stop_conditions iv_stop;
    thresholds iv_thresholds;
    uint64_t iv_pattern;
    end_boundary iv_end_boundary;
    mcbist::address iv_start_address;
    mcbist::address iv_end_address;
};


} // namespace
} // namespace
#endif

