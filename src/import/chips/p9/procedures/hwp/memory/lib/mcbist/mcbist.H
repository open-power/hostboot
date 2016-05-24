/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/mcbist/mcbist.H $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file mcbist.H
/// @brief Run and manage the MCBIST engine
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_MCBIST_H_
#define _MSS_MCBIST_H_

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/utils/poll.H>
#include <lib/shared/mss_const.H>
#include <lib/utils/bit_count.H>
#include <lib/mcbist/patterns.H>
#include <lib/mcbist/settings.H>

namespace mss
{
namespace mcbist
{

// I have a dream that the MCBIST engine code can be shared among controllers. So, I drive the
// engine from a set of traits. This might be folly. Allow me to dream. BRS

///
/// @class mcbistTraits
/// @brief a collection of traits associated with the MCBIST engine or hardware
///
template< fapi2::TargetType T >
class mcbistTraits;

///
/// @class mcbistTraits
/// @brief a collection of traits associated with the Centaur MCBIST engine or hardware
///
template<>
class mcbistTraits<fapi2::TARGET_TYPE_MEMBUF_CHIP>
{
};

///
/// @class mcbistTraits
/// @brief a collection of traits associated with the Nimbus MCBIST engine or hardware
///
template<>
class mcbistTraits<fapi2::TARGET_TYPE_MCBIST>
{
    public:
        /// MCBIST "memory registers" - config for subtests.
        static constexpr uint64_t MCBMR0_REG = MCBIST_MCBMR0Q;
        static constexpr uint64_t CFGQ_REG = MCBIST_MCBCFGQ;
        static constexpr uint64_t CNTLQ_REG = MCBIST_MCB_CNTLQ;
        static constexpr uint64_t STATQ_REG = MCBIST_MCB_CNTLSTATQ;
        static constexpr uint64_t MCBSTATQ_REG = MCBIST_MCBSTATQ;
        static constexpr uint64_t MCBPARMQ_REG = MCBIST_MCBPARMQ;
        static constexpr uint64_t MCBAGRAQ_REG = MCBIST_MCBAGRAQ;
        static constexpr uint64_t SRERR_REG = MCBIST_MBSEC1Q;
        static constexpr uint64_t THRESHOLD_REG = MCBIST_MBSTRQ;
        static constexpr uint64_t FIRQ_REG = MCBIST_MCBISTFIRQ;

        static constexpr uint64_t MCBAMR0A0Q_REG = MCBIST_MCBAMR0A0Q;
        static constexpr uint64_t MCBAMR1A0Q_REG = MCBIST_MCBAMR1A0Q;
        static constexpr uint64_t MCBAMR2A0Q_REG = MCBIST_MCBAMR2A0Q;
        static constexpr uint64_t MCBAMR3A0Q_REG = MCBIST_MCBAMR3A0Q;

        // All of the pattern registers are calculated off of this base
        static constexpr uint64_t PATTERN0_REG = MCBIST_MCBFD0Q;

        static constexpr uint64_t START_ADDRESS_0 = MCBIST_MCBSA0Q;
        static constexpr uint64_t START_ADDRESS_1 = MCBIST_MCBSA1Q;
        static constexpr uint64_t START_ADDRESS_2 = MCBIST_MCBSA2Q;
        static constexpr uint64_t START_ADDRESS_3 = MCBIST_MCBSA3Q;

        static constexpr uint64_t END_ADDRESS_0 = MCBIST_MCBEA0Q;
        static constexpr uint64_t END_ADDRESS_1 = MCBIST_MCBEA1Q;
        static constexpr uint64_t END_ADDRESS_2 = MCBIST_MCBEA2Q;
        static constexpr uint64_t END_ADDRESS_3 = MCBIST_MCBEA3Q;

        static constexpr uint64_t PATTERN_COUNT = 4;

        // Sometimes we want to access the start/end address registers based off
        // of an index, like master rank. This allows us to do that.
        static const std::pair<uint64_t, uint64_t> address_pairs[];

        enum
        {
            // Subtest control bits. These are the same in all '16 bit subtest' field
            COMPL_1ST_CMD = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_COMPL_1ST_CMD,
            COMPL_2ND_CMD = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_COMPL_2ND_CMD,
            COMPL_3RD_CMD = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_COMPL_3RD_CMD,
            ADDR_REV_MODE = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_ADDR_REV_MODE,
            ADDR_RAND_MODE = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_ADDR_RAND_MODE,
            ECC_MODE = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_ECC_MODE,
            DATA_MODE = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_DATA_MODE,
            DATA_MODE_LEN = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_DATA_MODE_LEN,
            ADDR_SEL = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_ADDR_SEL,
            ADDR_SEL_LEN = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_ADDR_SEL_LEN,
            OP_TYPE = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_OP_TYPE,
            OP_TYPE_LEN = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_OP_TYPE_LEN,
            DONE = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_DONE,

            SYNC_EN = MCBIST_MCBCFGQ_BROADCAST_SYNC_EN,
            SYNC_WAIT = MCBIST_MCBCFGQ_BROADCAST_SYNC_WAIT,
            SYNC_WAIT_LEN = MCBIST_MCBCFGQ_BROADCAST_SYNC_WAIT_LEN,

            PORT_SEL = MCBIST_MCB_CNTLQ_MCBCNTL_PORT_SEL,
            PORT_SEL_LEN = MCBIST_MCB_CNTLQ_MCBCNTL_PORT_SEL_LEN,

            MCBIST_START = MCBIST_MCB_CNTLQ_START,
            MCBIST_STOP = MCBIST_MCB_CNTLQ_STOP,

            MCBIST_IN_PROGRESS = MCBIST_MCB_CNTLSTATQ_IP,
            MCBIST_DONE = MCBIST_MCB_CNTLSTATQ_DONE,
            MCBIST_FAIL = MCBIST_MCB_CNTLSTATQ_FAIL,

            MIN_CMD_GAP = MCBIST_MCBPARMQ_CFG_MIN_CMD_GAP,
            MIN_CMD_GAP_LEN = MCBIST_MCBPARMQ_CFG_MIN_CMD_GAP_LEN,
            MIN_GAP_TIMEBASE = MCBIST_MCBPARMQ_CFG_MIN_GAP_TIMEBASE,
            MIN_CMD_GAP_BLIND_STEER = MCBIST_MCBPARMQ_CFG_MIN_CMD_GAP_BLIND_STEER,
            MIN_CMD_GAP_BLIND_STEER_LEN = MCBIST_MCBPARMQ_CFG_MIN_CMD_GAP_BLIND_STEER_LEN,
            MIN_GAP_TIMEBASE_BLIND_STEER = MCBIST_MCBPARMQ_CFG_MIN_GAP_TIMEBASE_BLIND_STEER,
            RANDCMD_WGT = MCBIST_MCBPARMQ_CFG_RANDCMD_WGT,
            RANDCMD_WGT_LEN = MCBIST_MCBPARMQ_CFG_RANDCMD_WGT_LEN,
            CLOCK_MONITOR_EN = MCBIST_MCBPARMQ_CFG_CLOCK_MONITOR_EN,
            EN_RANDCMD_GAP = MCBIST_MCBPARMQ_CFG_EN_RANDCMD_GAP,
            RANDGAP_WGT = MCBIST_MCBPARMQ_CFG_RANDGAP_WGT,
            RANDGAP_WGT_LEN = MCBIST_MCBPARMQ_CFG_RANDGAP_WGT_LEN,
            BC4_EN = MCBIST_MCBPARMQ_CFG_BC4_EN,

            FIXED_WIDTH = MCBIST_MCBAGRAQ_CFG_FIXED_WIDTH,
            FIXED_WIDTH_LEN = MCBIST_MCBAGRAQ_CFG_FIXED_WIDTH_LEN,
            ADDR_COUNTER_MODE = MCBIST_MCBAGRAQ_CFG_ADDR_COUNTER_MODE,
            ADDR_COUNTER_MODE_LEN = MCBIST_MCBAGRAQ_CFG_ADDR_COUNTER_MODE_LEN,
            MAINT_ADDR_MODE_EN = MCBIST_MCBAGRAQ_CFG_MAINT_ADDR_MODE_EN,
            MAINT_BROADCAST_MODE_EN = MCBIST_MCBAGRAQ_CFG_MAINT_BROADCAST_MODE_EN,
            MAINT_DETECT_SRANK_BOUNDARIES = MCBIST_MCBAGRAQ_CFG_MAINT_DETECT_SRANK_BOUNDARIES,

            CFG_CMD_TIMEOUT_MODE = MCBIST_MCBCFGQ_CFG_CMD_TIMEOUT_MODE,
            CFG_CMD_TIMEOUT_MODE_LEN = MCBIST_MCBCFGQ_CFG_CMD_TIMEOUT_MODE_LEN,
            RESET_KEEPER = MCBIST_MCBCFGQ_RESET_KEEPER,
            CFG_CURRENT_ADDR_TRAP_UPDATE_DIS = MCBIST_MCBCFGQ_CFG_CURRENT_ADDR_TRAP_UPDATE_DIS,
            CFG_CCS_RETRY_DIS = MCBIST_MCBCFGQ_CFG_CCS_RETRY_DIS,
            RESERVED_13_34 = MCBIST_MCBCFGQ_RESERVED_13_34,
            RESERVED_13_34_LEN = MCBIST_MCBCFGQ_RESERVED_13_34_LEN,
            CFG_RESET_CNTS_START_OF_RANK = MCBIST_MCBCFGQ_CFG_RESET_CNTS_START_OF_RANK,
            CFG_LOG_COUNTS_IN_TRACE = MCBIST_MCBCFGQ_CFG_LOG_COUNTS_IN_TRACE,
            SKIP_INVALID_ADDR_DIMM_DIS = MCBIST_MCBCFGQ_SKIP_INVALID_ADDR_DIMM_DIS,
            REFRESH_ONLY_SUBTEST_EN = MCBIST_MCBCFGQ_REFRESH_ONLY_SUBTEST_EN,
            REFRESH_ONLY_SUBTEST_TIMEBASE_SEL = MCBIST_MCBCFGQ_REFRESH_ONLY_SUBTEST_TIMEBASE_SEL,
            REFRESH_ONLY_SUBTEST_TIMEBASE_SEL_LEN = MCBIST_MCBCFGQ_REFRESH_ONLY_SUBTEST_TIMEBASE_SEL_LEN,
            RAND_ADDR_ALL_ADDR_MODE_EN = MCBIST_MCBCFGQ_RAND_ADDR_ALL_ADDR_MODE_EN,
            MCBIST_CFG_REF_WAIT_TIME = MCBIST_MCBCFGQ_MCBIST_CFG_REF_WAIT_TIME,
            MCBIST_CFG_REF_WAIT_TIME_LEN = MCBIST_MCBCFGQ_MCBIST_CFG_REF_WAIT_TIME_LEN,
            CFG_MCB_LEN64 = MCBIST_MCBCFGQ_CFG_MCB_LEN64,
            CFG_PAUSE_ON_ERROR_MODE = MCBIST_MCBCFGQ_CFG_PAUSE_ON_ERROR_MODE,
            CFG_PAUSE_ON_ERROR_MODE_LEN = MCBIST_MCBCFGQ_CFG_PAUSE_ON_ERROR_MODE_LEN,
            MCBIST_CFG_PAUSE_AFTER_CCS_SUBTEST = MCBIST_MCBCFGQ_MCBIST_CFG_PAUSE_AFTER_CCS_SUBTEST,
            MCBIST_CFG_FORCE_PAUSE_AFTER_ADDR = MCBIST_MCBCFGQ_MCBIST_CFG_FORCE_PAUSE_AFTER_ADDR,
            MCBIST_CFG_FORCE_PAUSE_AFTER_SUBTEST = MCBIST_MCBCFGQ_MCBIST_CFG_FORCE_PAUSE_AFTER_SUBTEST,
            CFG_ENABLE_SPEC_ATTN = MCBIST_MCBCFGQ_CFG_ENABLE_SPEC_ATTN,
            CFG_ENABLE_HOST_ATTN = MCBIST_MCBCFGQ_CFG_ENABLE_HOST_ATTN,
            MCBIST_CFG_PAUSE_AFTER_RANK = MCBIST_MCBCFGQ_CFG_MCBIST_CFG_FORCE_PAUSE_AFTER_RANK,

            LOGGED_ERROR_ON_PORT_INDICATOR = MCBIST_MCBSTATQ_MCBIST_LOGGED_ERROR_ON_PORT_INDICATOR,
            LOGGED_ERROR_ON_PORT_INDICATOR_LEN = MCBIST_MCBSTATQ_MCBIST_LOGGED_ERROR_ON_PORT_INDICATOR_LEN,

            UE_COUNT = MCBIST_MBSEC1Q_UE_COUNT,
            UE_COUNT_LEN = MCBIST_MBSEC1Q_UE_COUNT_LEN,
        };

};

///
/// @class subtest_t
/// @brief encapsulation of an MCBIST subtest.
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
class subtest_t
{
    public:
        subtest_t( const uint16_t i_data = 0 ):
            iv_mcbmr(i_data)
        {}

        ///
        /// @brief Complement the data for the first subcommand
        /// @param[in] i_state the desired state (mss::ON or mss::OFF)
        /// @return void
        ///
        inline void change_compliment_1st_cmd( const mss::states i_state )
        {
            iv_mcbmr.template writeBit<TT::COMPL_1ST_CMD>(i_state);
            return;
        }

        ///
        /// @brief Complement the data for the second subcommand
        /// @param[in] i_state the desired state (mss::ON or mss::OFF)
        /// @return void
        ///
        inline void change_compliment_2nd_cmd( const mss::states i_state )
        {
            iv_mcbmr.template writeBit<TT::COMPL_2ND_CMD>(i_state);
            return;
        }

        ///
        /// @brief Complement the data for the third subcommand
        /// @param[in] i_state the desired state (mss::ON or mss::OFF)
        /// @return void
        ///
        inline void change_compliment_3rd_cmd( const mss::states i_state )
        {
            iv_mcbmr.template writeBit<TT::COMPL_3RD_CMD>(i_state);
            return;
        }

        ///
        /// @brief Enable a specific port for this test - maint address mode
        /// @param[in] i_port the port desired to be enabled - int 0, 1, 2, 3
        /// @note The port number is relative to the MCBIST
        /// @return void
        ///
        inline void enable_port( const uint64_t i_port )
        {
            constexpr uint64_t l_len = (TT::COMPL_2ND_CMD - TT::COMPL_1ST_CMD) + 1;
            iv_mcbmr.template insertFromRight<TT::COMPL_1ST_CMD, l_len>(i_port);
            return;
        }

        ///
        /// @brief Enable a specific dimm for this test - maint address mode
        /// @param[in] i_dimm the dimm desired to be enabled - int 0, 1
        /// @return void
        ///
        inline void enable_dimm( const uint64_t i_dimm )
        {
            iv_mcbmr.template writeBit<TT::COMPL_3RD_CMD>(i_dimm);
            return;
        }


        ///
        /// @brief Generate addresses in reverse order
        /// @param[in] i_state the desired state of the function; mss:ON, mss::OFF
        /// @return void
        ///
        inline void change_addr_rev_mode( const mss::states i_state )
        {
            iv_mcbmr.template writeBit<TT::ADDR_REV_MODE>(i_state);
            return;
        }

        ///
        /// @brief Generate addresses in random order
        /// @param[in] i_state the desired state of the function; mss:ON, mss::OFF
        /// @return void
        ///
        inline void change_addr_rand_mode( const mss::states i_state )
        {
            iv_mcbmr.template writeBit<TT::ADDR_RAND_MODE>(i_state);
            return;
        }

        ///
        /// @brief Generate and check data with ECC
        /// @param[in] i_state the desired state of the function; mss:ON, mss::OFF
        /// @return void
        ///
        inline void change_ecc_mode( const mss::states i_state )
        {
            iv_mcbmr.template writeBit<TT::ECC_MODE>(i_state);
            return;
        }

        ///
        /// @brief Set the 'done after this test' bit
        /// @param[in] i_state the desired state of the function; mss:ON, mss::OFF
        /// @return void
        ///
        inline void change_done( const mss::states i_state )
        {
            iv_mcbmr.template writeBit<TT::DONE>(i_state);
            return;
        }

        ///
        /// @brief Set the data mode for this subtest
        /// @param[in] i_mode the desired mcbist::data_mode
        /// @return void
        ///
        inline void change_data_mode( const data_mode i_mode )
        {
            iv_mcbmr.template insertFromRight<TT::DATA_MODE, TT::DATA_MODE_LEN>(i_mode);
            return;
        }

        ///
        /// @brief Set the operation type for this subtest
        /// @param[in] i_mode the desired mcbist::op_type
        /// @return void
        ///
        inline void change_op_type( const op_type i_type )
        {
            iv_mcbmr.template insertFromRight<TT::OP_TYPE, TT::OP_TYPE_LEN>(i_type);
            return;
        }

        ///
        /// @brief Configure which address registers to use for this subtest
        /// @param[in] i_index 0 = MCBSA0Q, 1 = MCBSA1Q, ...
        /// @note wraps to 0-3 no matter what value you pass in.
        /// @return void
        ///
        inline void change_addr_sel( const uint16_t i_index )
        {
            // Roll the index around - tidy support for an index which is out of range.
            static const uint16_t MAX_ADDRESS_START_END_REGISTERS = 3 + 1;
            iv_mcbmr.template insertFromRight<TT::ADDR_SEL, TT::ADDR_SEL_LEN>(i_index % MAX_ADDRESS_START_END_REGISTERS);
            return;
        }

        //
        // @brief operator== for mcbist subtests
        // @param[in] i_rhs the right hand side of the compare
        // @return bool, true iff i_rhs == this
        inline bool operator==(const subtest_t<T>& i_rhs) const
        {
            return i_rhs.iv_mcbmr == iv_mcbmr;
        }

        /// The mcbist 'memory register' for this subtest.
        // Note that it is only 16 bits.
        // Each 64b memory register contains multiple 16 bit subtest definitions.
        // As we create a vector of subtests, we'll drop them in to their appropriate
        // MCBMR register before executing.
        fapi2::buffer<uint16_t> iv_mcbmr;
};

///
/// @brief Return a write subtest - configured simply
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @return mss::mcbist::subtest_t
/// @note Turns on ECC mode for the returned subtest - caller can turn it off
/// @note Configures for start/end address select bit as address config register 0
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline subtest_t<T> write_subtest()
{
    // Starts life full of 0's
    subtest_t<T> l_subtest;

    // 0:3   = 0000 - we want subtest type to be a Write (W)
    l_subtest.iv_mcbmr.template insertFromRight<TT::OP_TYPE, TT::OP_TYPE_LEN>(op_type::WRITE);

    // - Not a special subtest, so no other configs associated
    // 4     = 0    - we don't want to complement data for our Writes
    // 5:6   = 00   - don't know whether we complement 2nd and 3rd subcommand, caller to fix
    // 7     = 0    - forward address generation
    // 8     = 0    - non random address generation
    // - Don't need to set up anything for LFSRs
    // 9:11  = 000  - Fixed data mode

    // 14:15 = 0 address select config registers 0

    // By default we want to turn on ECC. Caller can turn it off.
    l_subtest.change_ecc_mode(mss::ON);

    return l_subtest;
}

///
/// @brief Return a read subtest - configured simply
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @return mss::mcbist::subtest_t
/// @note Turns on ECC mode for the returned subtest - caller can turn it off
/// @note Configures for start/end address select bit as address config register 0
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline subtest_t<T> read_subtest()
{
    // Starts life full of 0's
    subtest_t<T> l_subtest;

    // 0:3   = 0001 - we want subtest type to be a Read (R)
    l_subtest.iv_mcbmr.template insertFromRight<TT::OP_TYPE, TT::OP_TYPE_LEN>(op_type::READ);

    // - Not a special subtest, so no other configs associated
    // 4     = 0    - we don't want to complement data for our Writes
    // 5:6   = 00   - don't know whether we complement 2nd and 3rd subcommand, caller to fix
    // 7     = 0    - forward address generation
    // 8     = 0    - non random address generation
    // - Don't need to set up anything for LFSRs
    // 9:11  = 000  - Fixed data mode

    // 14:15 = 0 address select config registers 0

    // By default we want to turn on ECC. Caller can turn it off.
    l_subtest.change_ecc_mode(mss::ON);

    return l_subtest;
}

///
/// @brief Return an init subtest - configured simply
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @return mss::mcbist::subtest_t
/// @note Configures for start/end address select bit as address config register 0
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline subtest_t<T> init_subtest()
{
    return write_subtest<T>();
}

///
/// @brief A class representing a series of MCBIST subtests, and the
/// MCBIST engine parameters associated with running the subtests
/// @tparam T fapi2::TargetType representing the fapi2 target which
/// contains the MCBIST engine (e.g., fapi2::TARGET_TYPE_MCBIST)
/// @tparam TT, the mssTraits associtated with T
/// @note MCBIST Memory Parameter Register defaults to
/// - issue commands as fast as possible
/// - even weighting of read/write if random addressing
/// - disable clock monitoring
/// - random command gap is disabled
/// - BC4 disabled
/// - no selected ports
/// @note Address Generation Config Register defaults to
/// - 0 fixed slots
/// - All address counter modes on (so addr configs are start + len)
/// - maint address mode enabled
/// - maint broadcast mode disabled
/// - maint slave rank boundary detect disabled
/// @note Config register defaults to
/// - BROADCAST_SYNC_EN disabled
/// - BROADCAST_SYNC_WAIT 0
/// - TIMEOUT_MODE - wait 524288 cycles until timeout is called
/// - RESET_KEEPER - 0
/// - CURRENT_ADDR_TRAP_UPDATE_DIS - 0
/// - CCS_RETRY_DIS - 0
/// - RESET_CNTS_START_OF_RANK - 0
/// - LOG_COUNTS_IN_TRACE - 0
/// - SKIP_INVALID_ADDR_DIMM_DIS - 0
/// - REFRESH_ONLY_SUBTEST_EN - 0
/// - REFRESH_ONLY_SUBTEST_TIMEBASE_SEL(0:1) - 0
/// - RAND_ADDR_ALL_ADDR_MODE_EN - 0
/// - REF_WAIT_TIME(0:13) - 0
/// - MCB_LEN64 - 1
/// - PAUSE_ON_ERROR_MODE(0:1) - don't pause on error
/// - PAUSE_AFTER_CCS_SUBTEST - don't puase after CCS subtest
/// - FORCE_PAUSE_AFTER_ADDR - don't pause after current address
/// - FORCE_PAUSE_AFTER_SUBTEST - no pause after subtest
/// - ENABLE_SPEC_ATTN - disabled
/// - ENABLE_HOST_ATTN - disabled
///

template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
class program
{
    public:
        // Setup our poll parameters so the MCBIST executer can see
        // whether to use the delays in the instruction stream or not
        program():
            iv_parameters(0),
            iv_addr_gen(0),
            iv_test_type(CENSHMOO), // Used as default in Centaur
            iv_addr_map0(0),
            iv_addr_map1(0),
            iv_addr_map2(0),
            iv_addr_map3(0),
            iv_config(0),
            iv_control(0),
            iv_async(false)
        {
            // Enable the maintenance mode addressing
            change_maint_address_mode(mss::ON);

            // Enable 64B lengths by default. Commands which need 128B (scrub, steer, alter, display)
            // can change this to 128B (mss::OFF).
            change_len64(mss::ON);

            // Turn off counting mode for all address configs
            iv_addr_gen.insertFromRight<TT::ADDR_COUNTER_MODE, TT::ADDR_COUNTER_MODE_LEN>(0b0000);
        }

        ///
        /// @brief Change the mcbist 64/128 byte control
        /// @param[in] i_state mss::ON if you want 64B, mss::OFF if you want 128B
        /// @return void
        ///
        inline void change_len64( const mss::states i_state )
        {
            iv_config.writeBit<TT::CFG_MCB_LEN64>(i_state);
            return;
        }

        ///
        /// @brief Change MCBIST Stop conditions
        /// @param[in] i_stops the stop conditions
        /// @return FAPI2_RC_SUCCSS iff ok
        /// @note if the user askes for stop-on-error we stop after the operation on the failed address has completed
        ///
        inline void change_stops( const stop_conditions i_stops )
        {
            if (i_stops != DONT_CHANGE)
            {
                iv_config.insertFromRight<TT::CFG_PAUSE_ON_ERROR_MODE, TT::CFG_PAUSE_ON_ERROR_MODE_LEN>(i_stops);
            }

            FAPI_INF("load MCBIST stops: 0x%016lx (0x%016lx)", i_stops, iv_config);
        }

        ///
        /// @brief Change the mcbist min command gap
        /// @param[in] i_gap minimum number of cycles between commands when cfg_en_randcmd_gap is a 0 (disabled)
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_min_cmd_gap( const uint64_t i_gap )
        {
            iv_parameters.insertFromRight<TT::MIN_CMD_GAP, TT::MIN_CMD_GAP_LEN>(i_gap);
            return;
        }

        ///
        /// @brief Change the mcbist gap timebase
        /// @param[in] i_tb When set to mss::ON and cfg_en_randcmd_gap is a 0, then the number of minimum
        /// cycles between commands will be cfg_min_cmd_gap multiplied by 2^13.
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_min_gap_timebase( const bool i_tb )
        {
            iv_parameters.writeBit<TT::MIN_GAP_TIMEBASE>(i_tb);
            return;
        }

        ///
        /// @brief Change the mcbist min command gap blind steer
        /// @param[in] i_gap min gap between commands when doing steering
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_min_cmd_gap_blind_steer( const uint64_t i_gap )
        {
            iv_parameters.insertFromRight<TT::MIN_CMD_GAP_BLIND_STEER, TT::MIN_CMD_GAP_BLIND_STEER_LEN>(i_gap);
            return;
        }

        ///
        /// @brief Change the mcbist gap timebase for blind steer
        /// @param[in] i_program the program in question
        /// @param[in] i_tb When set to mss::ON and cfg_en_randcmd_gap is a 0, then the number of minimum
        /// cycles between commands will be cfg_min_cmd_gap multiplied by 2^13.
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_min_gap_timebase_blind_steer( const bool i_tb )
        {
            iv_parameters.writeBit<TT::MIN_GAP_TIMEBASE_BLIND_STEER>(i_tb);
            return;
        }

        ///
        /// @brief Change the weights for random mcbist reads, writes
        /// @param[in] i_weight
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_randcmd_wgt( const uint64_t i_weight )
        {
            iv_parameters.insertFromRight<TT::RANDCMD_WGT, TT::RANDCMD_WGT_LEN>(i_weight);
            return;
        }

        ///
        /// @brief Change the weights for random mcbist command gaps
        /// @param[in] i_program the program in question
        /// @param[in] i_weight
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_randgap_wgt( const uint64_t i_weight )
        {
            iv_parameters.insertFromRight<TT::RANDGAP_WGT, TT::RANDGAP_WGT_LEN>(i_weight);
            return;
        }

        ///
        /// @brief Enable or disable mcbist clock monitoring
        /// @param[in] i_monitor mss::ON to monitor
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_clock_monitor_en( const bool i_monitor )
        {
            iv_parameters.writeBit<TT::CLOCK_MONITOR_EN>(i_monitor);
            return;
        }

        ///
        /// @brief Enable or disable mcbist random command gaps
        /// @param[in] i_rndgap mss::ON to enable
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_en_randcmd_gap( const bool i_rndgap )
        {
            iv_parameters.writeBit<TT::EN_RANDCMD_GAP>(i_rndgap);
            return;
        }

        ///
        /// @brief Enable or disable mcbist BC4 support
        /// @param[in] i_bc4 mss::ON to enable
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_bc4_en( const bool i_bc4 )
        {
            iv_parameters.writeBit<TT::BC4_EN>(i_bc4);
            return;
        }

        ///
        /// @brief Change fixed width address generator config
        /// @param[in] i_width
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_fixed_width( const uint64_t i_width )
        {
            iv_addr_gen.insertFromRight<TT::FIXED_WIDTH, TT::FIXED_WIDTH_LEN>(i_width);
            return;
        }

        ///
        /// @brief Enable or disable address counting mode for address config 0
        /// @param[in] i_mode mss::ON to enable
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_address_counter_mode0( const bool i_mode )
        {
            fapi2::buffer<uint64_t> l_value;
            iv_addr_gen.extract<TT::ADDR_COUNTER_MODE, TT::ADDR_COUNTER_MODE_LEN>(l_value);
            l_value.writeBit<0>(i_mode);
            iv_addr_gen.insert<TT::ADDR_COUNTER_MODE, TT::ADDR_COUNTER_MODE_LEN>(l_value);
            return;
        }

        ///
        /// @brief Enable or disable address counting mode for address config 1
        /// @param[in] i_mode mss::ON to enable
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_address_counter_mode1( const bool i_mode )
        {
            fapi2::buffer<uint64_t> l_value;
            iv_addr_gen.extract<TT::ADDR_COUNTER_MODE, TT::ADDR_COUNTER_MODE_LEN>(l_value);
            l_value.writeBit<1>(i_mode);
            iv_addr_gen.insert<TT::ADDR_COUNTER_MODE, TT::ADDR_COUNTER_MODE_LEN>(l_value);
            return;
        }

        ///
        /// @brief Enable or disable address counting mode for address config 2
        /// @param[in] i_mode mss::ON to enable
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_address_counter_mode2( const bool i_mode )
        {
            fapi2::buffer<uint64_t> l_value;
            iv_addr_gen.extract<TT::ADDR_COUNTER_MODE, TT::ADDR_COUNTER_MODE_LEN>(l_value);
            l_value.writeBit<2>(i_mode);
            iv_addr_gen.insert<TT::ADDR_COUNTER_MODE, TT::ADDR_COUNTER_MODE_LEN>(l_value);
            return;
        }

        ///
        /// @brief Enable or disable address counting mode for address config 3
        /// @param[in] i_program, the program in question
        /// @param[in] i_mode mss::ON to enable
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_address_counter_mode3( const bool i_mode )
        {
            fapi2::buffer<uint64_t> l_value;
            iv_addr_gen.extract<TT::ADDR_COUNTER_MODE, TT::ADDR_COUNTER_MODE_LEN>(l_value);
            l_value.writeBit<3>(i_mode);
            iv_addr_gen.insert<TT::ADDR_COUNTER_MODE, TT::ADDR_COUNTER_MODE_LEN>(l_value);
            return;
        }


        ///
        /// @brief Enable or disable maint address mode
        /// @param[in] i_program the program in question
        /// @param[in] i_mode mss::ON to enable
        /// @warn Address counter modes must be 0 for this to work.
        /// @note When enabled subtest complement bits become 3-bit port-dimm selector field
        /// (Note: when turning this off, make sure you clear or reprogram complement bits)
        /// @return void
        ///
        inline void change_maint_address_mode( const bool i_mode )
        {
            iv_addr_gen.writeBit<TT::MAINT_ADDR_MODE_EN>(i_mode);
            return;
        }


        ///
        /// @brief Enable or disable broadcast mode
        /// @param[in] i_program the program in question
        /// @param[in] i_mode mss::ON to enable
        /// @warn Maint address mode must be enabled for this to work
        /// @return void
        ///
        inline void change_maint_broadcast_mode( const bool i_mode )
        {
            iv_addr_gen.writeBit<TT::MAINT_BROADCAST_MODE_EN>(i_mode);
            return;
        }


        ///
        /// @brief Enable or disable slave rank boundary detect
        /// @param[in] i_program the program in question
        /// @param[in] i_mode mss::ON to enable
        /// @return void
        ///
        inline void change_srank_boundaries( const bool i_mode )
        {
            iv_addr_gen.writeBit<TT::MAINT_DETECT_SRANK_BOUNDARIES>(i_mode);
            return;
        }

        ///
        /// @brief Enable or disable async mode
        /// @param[in] i_program the program in question
        /// @param[in] i_mode mss::ON to enable, programs will run async
        /// @return void
        ///
        inline void change_async( const bool i_mode )
        {
            iv_async = i_mode;
            return;
        }

        ///
        /// @brief Select the port(s) to be used by the MCBIST
        /// @param[in] i_ports uint64_t representing the ports. Multiple bits set imply broadcast
        /// i_ports is a right-aligned uint64_t, of which only the right-most 4 bits are used. The register
        /// field is defined such that the left-most bit in the field represents port 0, the right most
        /// bit in the field represents port 3. So, to run on port 0, i_ports should be 0b1000. 0b0001
        /// (or 0x1) is port 3 - not port 0
        /// @return void
        ///
        inline void select_ports( const uint64_t i_ports )
        {
            iv_control.insertFromRight<TT::PORT_SEL, TT::PORT_SEL_LEN>(i_ports);
            FAPI_INF("mcbist select ports: iv_control 0x%016lx (ports: 0x%x)", iv_control, i_ports);

            return;
        }

        ///
        /// @brief Process mcbist errors
        /// @param[in] i_target fapi2::Target<T> of the MCBIST
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        inline fapi2::ReturnCode process_errors( const fapi2::Target<T> i_target ) const
        {
            // TK: Check for more detailed errors

            // Until reading the error array is documented, comparison errors 'just' result in
            // a flag indicating there was a problem on port.
            {
                fapi2::buffer<uint64_t> l_data;
                uint64_t l_read = 0;
                FAPI_TRY( mss::getScom(i_target, TT::MCBSTATQ_REG, l_data) );
                l_data.extractToRight<TT::LOGGED_ERROR_ON_PORT_INDICATOR, TT::LOGGED_ERROR_ON_PORT_INDICATOR_LEN>(l_read);

                FAPI_ASSERT( l_read == 0,
                             fapi2::MSS_MEMDIAGS_COMPARE_ERROR_IN_LAST_PATTERN()
                             .set_TARGET(i_target)
                             .set_PORT(mss::first_bit_set(l_read)),
                             "MCBIST error on port %d", mss::first_bit_set(l_read) );
            }

            // Check for UE errors
            {
                fapi2::buffer<uint64_t> l_data;
                uint64_t l_read = 0;
                FAPI_TRY( mss::getScom(i_target, TT::SRERR_REG, l_data) );

                // For now, lets catch anything in the scrub/read error reg - not just UE
#ifdef CATCH_UE_ONLY
                l_data.extractToRight<TT::UE_COUNT, TT::UE_COUNT_LEN>(l_read);
#else
                l_read = l_data;
#endif

                FAPI_ASSERT( l_read == 0,
                             fapi2::MSS_MEMDIAGS_UE_OR_SUE_IN_LAST_PATTERN()
                             .set_TARGET(i_target)
                             .set_STATUS(l_read),
                             "MCBIST scrub/read error 0x%016lx", l_read );
            }

            FAPI_INF("Execution success - no errors seen from MCBIST program");

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Clear mcbist errors
        /// @param[in] i_target fapi2::Target<T> of the MCBIST
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        inline fapi2::ReturnCode clear_errors( const fapi2::Target<T> i_target ) const
        {
            // TK: Clear the more detailed errors checked above
            FAPI_INF("Clear MCBIST error state");
            FAPI_TRY( mss::putScom(i_target, TT::MCBSTATQ_REG, 0) );
            FAPI_TRY( mss::putScom(i_target, TT::SRERR_REG, 0) );
            FAPI_TRY( mss::putScom(i_target, TT::FIRQ_REG, 0) );

        fapi_try_exit:
            return fapi2::current_err;
        }


        // Vector of subtests. Note the MCBIST subtests are spread across
        // 8 registers - 4 subtests fit in one 64b register
        // (16 bits/test, 4 x 16 == 64, 4x8 = 32 subtests)
        // We keep a vector of 16 bit subtests here, and we program the
        // MCBIST engine (i.e., spread the subtests over the 8 registers)
        // when we're told to execute the program.
        std::vector< subtest_t<T> > iv_subtests;

        // Place to hold the value of the MCBIST Memory Parameter Register. We'll scom
        // it when we execute the program.
        fapi2::buffer<uint64_t>     iv_parameters;

        // Place to hold the value of the MCBIST Address Generation Config. We'll scom
        // it when we execute the program.
        fapi2::buffer<uint64_t>     iv_addr_gen;

        test_type                   iv_test_type;

        poll_parameters             iv_poll;

        // Address Map Registers
        // We might want to refactor to a vector ... BRS
        uint64_t                    iv_addr_map0;
        uint64_t                    iv_addr_map1;
        uint64_t                    iv_addr_map2;
        uint64_t                    iv_addr_map3;

        // Config register
        fapi2::buffer<uint64_t>     iv_config;

        // Control register
        fapi2::buffer<uint64_t>     iv_control;

        // True iff we want to run in asynchronous mode
        bool                        iv_async;
};

///
/// @brief Load the mcbist config register
/// @tparam T fapi2::TargetType of the MCBIST engine
/// @tparam TT the mssTraits associtated with T
/// @param[in] i_target the target to effect
/// @param[in] i_program the mcbist::program
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode load_config( const fapi2::Target<T>& i_target, const mcbist::program<T>& i_program )
{
    FAPI_INF("loading MCBIST Config 0x%016lx", i_program.iv_config);
    return mss::putScom(i_target, TT::CFGQ_REG, i_program.iv_config);
}


///
/// @brief Load the mcbist control register
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_program the mcbist::program
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode load_control( const fapi2::Target<T>& i_target, const mcbist::program<T>& i_program )
{
    FAPI_INF("loading MCBIST Control 0x%016lx", i_program.iv_control);
    return mss::putScom(i_target, TT::CNTLQ_REG, i_program.iv_control);
}


///
/// @brief Load the address generator config
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_program the mcbist::program
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode load_addr_gen( const fapi2::Target<T>& i_target, const mcbist::program<T>& i_program )
{
    FAPI_INF("loading MCBIST Address Generation 0x%016lx", i_program.iv_addr_gen);
    return mss::putScom(i_target, TT::MCBAGRAQ_REG, i_program.iv_addr_gen);
}

///
/// @brief Configure address range based on index
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_start 64b right-aligned address
/// @param[in] i_end 64b right-aligned address
/// @param[in] i_index which start/end pair to effect
/// @return FAPI2_RC_SUCCSS iff ok
/// @note Only the right-most 37 bits of the start/end are used.
/// @warn if address counting mode is enabled in the MCBIST program, these bits are start, len
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode config_address_range( const fapi2::Target<T>& i_target, const uint64_t i_start,
        const uint64_t i_end, const uint64_t i_index )
{
    FAPI_INF("config MCBIST address range %d start: 0x%016lx (0x%016lx), end/len 0x%016lx (0x%016lx)",
             i_index, i_start, (i_start << 26), i_end, (i_end << 26));
    FAPI_TRY( mss::putScom(i_target, TT::address_pairs[i_index].first, i_start << 26) );
    FAPI_TRY( mss::putScom(i_target, TT::address_pairs[i_index].second, i_end << 26) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure address range 0
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_start 64b right-aligned address
/// @param[in] i_end 64b right-aligned address
/// @return FAPI2_RC_SUCCSS iff ok
/// @note Only the right-most 37 bits of the start/end are used.
/// @warn if address counting mode is enabled in the MCBIST program, these bits are start, len
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode config_address_range0( const fapi2::Target<T>& i_target, const uint64_t i_start,
        const uint64_t i_end )
{
    return config_address_range(i_target, i_start, i_end, 0);
}


///
/// @brief Configure address range 1
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_start 64b right-aligned address
/// @param[in] i_end 64b right-aligned address
/// @return FAPI2_RC_SUCCSS iff ok
/// @note Only the right-most 37 bits of the start/end are used.
/// @warn if address counting mode is enabled in the MCBIST program, these bits are start, len
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode config_address_range1( const fapi2::Target<T>& i_target, const uint64_t i_start,
        const uint64_t i_end )
{
    return config_address_range(i_target, i_start, i_end, 1);
}


///
/// @brief Configure address range 2
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_start 64b right-aligned address
/// @param[in] i_end 64b right-aligned address
/// @return FAPI2_RC_SUCCSS iff ok
/// @note Only the right-most 37 bits of the start/end are used.
/// @warn if address counting mode is enabled in the MCBIST program, these bits are start, len
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode config_address_range2( const fapi2::Target<T>& i_target, const uint64_t i_start,
        const uint64_t i_end )
{
    return config_address_range(i_target, i_start, i_end, 2);
}


///
/// @brief Configure address range 3
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_start 64b right-aligned address
/// @param[in] i_end 64b right-aligned address
/// @return FAPI2_RC_SUCCSS iff ok
/// @note Only the right-most 37 bits of the start/end are used.
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode config_address_range3( const fapi2::Target<T>& i_target, const uint64_t i_start,
        const uint64_t i_end )
{
    return config_address_range(i_target, i_start, i_end, 3);
}

///
/// @brief Start or stop the MCBIST engine
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_start_stop bool START for starting, STOP otherwise
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff OK
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode start_stop( const fapi2::Target<T>& i_target, bool i_start_stop )
{
    // This is the same as the CCS start_stop ... perhaps we need one template for all
    // 'engine' control functions? BRS
    fapi2::buffer<uint64_t> l_buf;
    FAPI_TRY(mss::getScom(i_target, TT::CNTLQ_REG, l_buf));

    FAPI_TRY( mss::putScom(i_target, TT::CNTLQ_REG,
                           i_start_stop ? l_buf.setBit<TT::MCBIST_START>() : l_buf.setBit<TT::MCBIST_STOP>()) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return whether or not the MCBIST engine has an operation in progress
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the target to effect
/// @param[out] i_in_progress - false if no operation is in progress
/// @return FAPI2_RC_SUCCESS if getScom succeeded
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode in_progress( const fapi2::Target<T>& i_target, bool o_in_progress )
{
    fapi2::buffer<uint64_t> l_buf;

    FAPI_TRY(mss::getScom(i_target, TT::STATQ_REG, l_buf));
    o_in_progress = l_buf.getBit<TT::MCBIST_IN_PROGRESS>();
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Execute the mcbist program
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the target to effect
/// @param[in] i_program the mcbist program to execute
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff OK
///
template< fapi2::TargetType T >
fapi2::ReturnCode execute( const fapi2::Target<T>& i_target, const program<T>& i_program );

///
/// @brief Load a set of MCBIST subtests in to the MCBIST registers
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_program the mcbist::program
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
fapi2::ReturnCode load_mcbmr( const fapi2::Target<T>& i_target, const mcbist::program<T>& i_program );


///
/// @brief Load a set of MCBIST address map registers
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] the target to effect
/// @param[in] the mcbist::program
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
fapi2::ReturnCode load_mcbamr( const fapi2::Target<T>& i_target, const mcbist::program<T>& i_program )
{
    // Vector? Can decide when we fully understand the methods to twiddle the maps themselves. BRS
    FAPI_INF("load MCBIST address map register 0: 0x%016lx", i_program.iv_addr_map0);
    FAPI_TRY( mss::putScom(i_target, TT::MCBAMR0A0Q_REG, i_program.iv_addr_map0) );

    FAPI_INF("load MCBIST address map register 1: 0x%016lx", i_program.iv_addr_map1);
    FAPI_TRY( mss::putScom(i_target, TT::MCBAMR1A0Q_REG, i_program.iv_addr_map1) );

    FAPI_INF("load MCBIST address map register 2: 0x%016lx", i_program.iv_addr_map2);
    FAPI_TRY( mss::putScom(i_target, TT::MCBAMR1A0Q_REG, i_program.iv_addr_map2) );

    FAPI_INF("load MCBIST address map register 3: 0x%016lx", i_program.iv_addr_map3);
    FAPI_TRY( mss::putScom(i_target, TT::MCBAMR1A0Q_REG, i_program.iv_addr_map3) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Load MCBIST Memory Parameter Register
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] the target to effect
/// @param[in] the mcbist::program
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode load_mcbparm( const fapi2::Target<T>& i_target, const mcbist::program<T>& i_program )
{
    FAPI_INF("load MCBIST parameter register: 0x%016lx", i_program.iv_parameters);
    return mss::putScom(i_target, TT::MCBPARMQ_REG, i_program.iv_parameters);
}

///
/// @brief Load MCBIST pattern given a pattern
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_pattern an mcbist::patterns
/// @param[in] i_invert whether to invert the pattern or not
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode load_pattern( const fapi2::Target<T>& i_target, const pattern& i_pattern, const bool i_invert )
{
    uint64_t l_address = TT::PATTERN0_REG;

    // Sanity check the pattern as the user can pass in anything they like
    FAPI_ASSERT( i_pattern.size() == TT::PATTERN_COUNT,
                 fapi2::MSS_MEMDIAGS_INVALID_PATTERN_SIZE().set_SIZE(i_pattern.size()).set_TARGET(i_target),
                 "Attempting to load a pattern which is not %d elements (%d)", TT::PATTERN_COUNT, i_pattern.size() );

    // Loop over the cache lines in the pattern. We write one half of the cache line
    // to the even register and half to the odd.
    for (const auto& l_cache_line : i_pattern)
    {
        fapi2::buffer<uint64_t> l_value_first  = i_invert ? ~l_cache_line.first : l_cache_line.first;
        fapi2::buffer<uint64_t> l_value_second = i_invert ? ~l_cache_line.second : l_cache_line.second;
        FAPI_INF("Loading cache line pattern 0x%016lx 0x%016lx", l_value_first, l_value_second);
        FAPI_TRY( mss::putScom(i_target, l_address, l_value_first) );
        FAPI_TRY( mss::putScom(i_target, ++l_address, l_value_second) );
        ++l_address;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Load MCBIST pattern given an index
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_index an index representing the pattern you'd like
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode load_pattern( const fapi2::Target<T>& i_target, uint64_t i_index )
{
    if (NO_PATTERN != i_index)
    {
        bool l_invert = false;

        FAPI_INF("%s load MCBIST pattern index %d", mss::c_str(i_target), i_index);

        // Sanity check the pattern since they're just numbers.
        FAPI_ASSERT( i_index <= mcbist::LAST_PATTERN,
                     fapi2::MSS_MEMDIAGS_INVALID_PATTERN_INDEX().set_INDEX(i_index).set_TARGET(i_target),
                     "Attempting to load a pattern which does not exist %d", i_index );

        // The indexes are split in to even and odd where the odd indexes don't really exist.
        // They're just indicating that we want to grab the even index and invert it. So calculate
        // the proper vector index and acknowledge the inversion if necessary.
        if ((i_index % 2) != 0)
        {
            l_invert = true;
            i_index -= 1;
        }

        return load_pattern(i_target, patterns[i_index / 2], l_invert);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Load MCBIST Threshold Register
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_thresholds the thresholds
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode load_thresholds( const fapi2::Target<T>& i_target, const uint64_t i_thresholds )
{
    FAPI_INF("load MCBIST threshold register: 0x%016lx", i_thresholds );
    return mss::putScom(i_target, TT::THRESHOLD_REG, i_thresholds);
}

} // namespace

} // namespace

#endif
