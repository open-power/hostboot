/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mcbist/mcbist_traits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file mcbist_traits.H
/// @brief Run and manage the MCBIST engine
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_MCBIST_TRAITS_H_
#define _MSS_MCBIST_TRAITS_H_

#include <fapi2.H>

#include <lib/shared/mss_const.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_address.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_traits.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

namespace mss
{

///
/// @class mcbistMCTraits
/// @brief A MC to MC_TARGET_TYPE mapping
///
template<>
class mcbistMCTraits<mss::mc_type::NIMBUS>
{
    public:
        static constexpr fapi2::TargetType MC_TARGET_TYPE = fapi2::TARGET_TYPE_MCBIST;
        static constexpr fapi2::TargetType FWMS_ADDR_TARGET_TYPE = fapi2::TARGET_TYPE_MCA;

        ///
        /// @brief Returns an error for memdiags compare error in last pattern
        /// @return memdiags error
        ///
        static fapi2::MSS_MEMDIAGS_COMPARE_ERROR_IN_LAST_PATTERN memdiags_compare_error_in_last_pattern()
        {
            return fapi2::MSS_MEMDIAGS_COMPARE_ERROR_IN_LAST_PATTERN();
        }

        ///
        /// @brief Returns an error for memdiags error in last pattern
        /// @return memdiags error
        ///
        static fapi2::MSS_MEMDIAGS_ERROR_IN_LAST_PATTERN memdiags_error_in_last_pattern()
        {
            return fapi2::MSS_MEMDIAGS_ERROR_IN_LAST_PATTERN();
        }

        ///
        /// @brief Returns an error if memdiags failed to start
        /// @return memdiags error
        ///
        static fapi2::MSS_MEMDIAGS_MCBIST_FAILED_TO_START memdiags_failed_to_start()
        {
            return fapi2::MSS_MEMDIAGS_MCBIST_FAILED_TO_START();
        }

        ///
        /// @brief Returns an error if memdiags failed to stop
        /// @return memdiags error
        ///
        static fapi2::MSS_MEMDIAGS_MCBIST_FAILED_TO_STOP memdiags_failed_to_stop()
        {
            return fapi2::MSS_MEMDIAGS_MCBIST_FAILED_TO_STOP();
        }

        ///
        /// @brief Returns an error if memdiags has a non-functional port
        /// @return memdiags error
        ///
        static fapi2::MSS_MEMDIAGS_PORT_NOT_FUNCTIONAL memdiags_port_not_functional()
        {
            return fapi2::MSS_MEMDIAGS_PORT_NOT_FUNCTIONAL();
        }

        ///
        /// @brief Returns an error if memdiags super fast init failed to init
        /// @return memdiags error
        ///
        static fapi2::MSS_MEMDIAGS_SUPERFAST_INIT_FAILED_TO_INIT memdiags_sf_init_failed_init()
        {
            return fapi2::MSS_MEMDIAGS_SUPERFAST_INIT_FAILED_TO_INIT();
        }

        ///
        /// @brief Returns an error if memdiags super fast read failed to init
        /// @return memdiags error
        ///
        static fapi2::MSS_MEMDIAGS_SUPERFAST_READ_FAILED_TO_INIT memdiags_sf_read_failed_init()
        {
            return fapi2::MSS_MEMDIAGS_SUPERFAST_READ_FAILED_TO_INIT();
        }

        ///
        /// @brief Returns an error if memdiags continuous scrub failed to init
        /// @return memdiags error
        ///
        static fapi2::MSS_MEMDIAGS_CONTINUOUS_SCRUB_FAILED_TO_INIT memdiags_continuous_scrub_failed_init()
        {
            return fapi2::MSS_MEMDIAGS_CONTINUOUS_SCRUB_FAILED_TO_INIT();
        }

        ///
        /// @brief Returns an error if memdiags targeted scrub failed to init
        /// @return memdiags error
        ///
        static fapi2::MSS_MEMDIAGS_TARGETED_SCRUB_FAILED_TO_INIT memdiags_targeted_scrub_failed_init()
        {
            return fapi2::MSS_MEMDIAGS_TARGETED_SCRUB_FAILED_TO_INIT();
        }

        ///
        /// @brief Returns an error if memdiags is already at a boundary
        /// @return memdiags error
        ///
        static fapi2::MSS_MEMDIAGS_ALREADY_AT_BOUNDARY memdiags_already_at_boundary()
        {
            return fapi2::MSS_MEMDIAGS_ALREADY_AT_BOUNDARY();
        }

        ///
        /// @brief Returns an error if MCBIST timesout
        /// @return MCBIST error
        ///
        static fapi2::MSS_MCBIST_TIMEOUT mcbist_timeout()
        {
            return fapi2::MSS_MCBIST_TIMEOUT();
        }

        ///
        /// @brief Returns an error if MCBIST has an unknown failure
        /// @return MCBIST error
        ///
        static fapi2::MSS_MCBIST_UNKNOWN_FAILURE mcbist_unknown_failure()
        {
            return fapi2::MSS_MCBIST_UNKNOWN_FAILURE();
        }

        ///
        /// @brief Returns an error if MCBIST has a data miscompare
        /// @return MCBIST error
        ///
        static fapi2::MSS_MCBIST_DATA_FAIL mcbist_data_fail()
        {
            return fapi2::MSS_MCBIST_DATA_FAIL();
        }
};

///
/// @class mcbistTraits
/// @brief a collection of traits associated with the Nimbus MCBIST engine or hardware
///
template<>
class mcbistTraits<mss::mc_type::NIMBUS, fapi2::TARGET_TYPE_MCBIST>
{
    public:

        // PORT_TYPE used in continuous_scrub_operation
        static constexpr enum fapi2::TargetType PORT_TYPE = fapi2::TARGET_TYPE_MCA;

        // ATTN support
        static constexpr mss::states CFG_ENABLE_ATTN_SUPPORT = mss::states::YES;
        static constexpr mss::states BROADCAST_CAPABLE = mss::states::YES;

        // Multi-ports, dimms
        static constexpr mss::states MULTI_PORTS = mss::states::YES;

        // Subtest
        static constexpr size_t SUBTEST_PER_REG = 4;
        static constexpr size_t SUBTEST_PER_PROGRAM = 32;
        static constexpr size_t BITS_IN_SUBTEST = 16; // 2 Bytes
        static constexpr size_t LEFT_SHIFT = (sizeof(uint64_t) * 8) - BITS_IN_SUBTEST;

        // LARGEST_ADDRESS
        static constexpr uint64_t LARGEST_ADDRESS = ~0 >> mss::mcbist::address::MAGIC_PAD;

        // Length of expected patterns
        static constexpr uint64_t EXPECTED_PATTERN_SIZE = 4;

        // Size
        static constexpr size_t PORTS_PER_MCBIST = mss::PORTS_PER_MCBIST;
        static constexpr size_t MAX_DIMM_PER_PORT = mss::MAX_DIMM_PER_PORT;
        static constexpr size_t MAX_PRIMARY_RANKS_PER_PORT = mss::MAX_PRIMARY_RANKS_PER_PORT;
        static constexpr size_t MAX_DQ_BITS = 72;
        static constexpr size_t MAX_DQ_NIBBLES = MAX_DQ_BITS /
                BITS_PER_NIBBLE; ///< For ISDIMMs are 18 DQ nibbles for DQ 72 bits
        static constexpr size_t MAX_DRAMS_X8 = MAX_DQ_BITS / BITS_PER_BYTE; ///< For x8's there are 9 DRAM for 72 bits
        static constexpr size_t MAX_DRAMS_X4 = MAX_DQ_BITS / BITS_PER_NIBBLE; ///< For x4's there are 18 DRAM for 72 bits

        /// MCBIST "memory registers" - config for subtests.
        static constexpr uint64_t MCBMR0_REG = MCBIST_MCBMR0Q;
        static constexpr uint64_t MCBMR1_REG = MCBIST_MCBMR1Q;
        static constexpr uint64_t MCBMR2_REG = MCBIST_MCBMR2Q;
        static constexpr uint64_t MCBMR3_REG = MCBIST_MCBMR3Q;
        static constexpr uint64_t MCBMR4_REG = MCBIST_MCBMR4Q;
        static constexpr uint64_t MCBMR5_REG = MCBIST_MCBMR5Q;
        static constexpr uint64_t MCBMR6_REG = MCBIST_MCBMR6Q;
        static constexpr uint64_t MCBMR7_REG = MCBIST_MCBMR7Q;
        static constexpr uint64_t CFGQ_REG = MCBIST_MCBCFGQ;
        static constexpr uint64_t CNTLQ_REG = MCBIST_MCB_CNTLQ;
        static constexpr uint64_t STATQ_REG = MCBIST_MCB_CNTLSTATQ;
        static constexpr uint64_t MCBSTATQ_REG = MCBIST_MCBSTATQ;
        static constexpr uint64_t MCBPARMQ_REG = MCBIST_MCBPARMQ;
        static constexpr uint64_t MCBAGRAQ_REG = MCBIST_MCBAGRAQ;
        static constexpr uint64_t SRERR0_REG = MCBIST_MBSEC0Q;
        static constexpr uint64_t SRERR1_REG = MCBIST_MBSEC1Q;
        static constexpr uint64_t THRESHOLD_REG = MCBIST_MBSTRQ;
        static constexpr uint64_t FIRQ_REG = MCBIST_MCBISTFIRQ;
        static constexpr uint64_t LAST_ADDR_REG = MCBIST_MCBMCATQ;

        static constexpr uint64_t MCBAMR0A0Q_REG = MCBIST_MCBAMR0A0Q;
        static constexpr uint64_t MCBAMR1A0Q_REG = MCBIST_MCBAMR1A0Q;
        static constexpr uint64_t MCBAMR2A0Q_REG = MCBIST_MCBAMR2A0Q;
        static constexpr uint64_t MCBAMR3A0Q_REG = MCBIST_MCBAMR3A0Q;
        static constexpr uint64_t LFSR_REG = MCBIST_MCBLFSRA0Q;
        static const std::vector<uint64_t> LFSR_MASK_VALUES;

        // MCBIST FIR registers
        static constexpr uint64_t MCBFIRMASK_REG = MCBIST_MCBISTFIRMASK;
        static constexpr uint64_t MCBFIRQ_REG = MCBIST_MCBISTFIRQ;

        // All of the pattern registers are calculated off of this base
        static constexpr uint64_t PATTERN0_REG = MCBIST_MCBFD0Q;
        static constexpr uint64_t PATTERN1_REG = MCBIST_MCBFD1Q;
        static constexpr uint64_t PATTERN2_REG = MCBIST_MCBFD2Q;
        static constexpr uint64_t PATTERN3_REG = MCBIST_MCBFD3Q;
        static constexpr uint64_t PATTERN4_REG = MCBIST_MCBFD4Q;
        static constexpr uint64_t PATTERN5_REG = MCBIST_MCBFD5Q;
        static constexpr uint64_t PATTERN6_REG = MCBIST_MCBFD6Q;
        static constexpr uint64_t PATTERN7_REG = MCBIST_MCBFD7Q;

        static constexpr uint64_t DATA_ROTATE_CNFG_REG = MCBIST_MCBDRCRQ;
        static constexpr uint64_t DATA_ROTATE_SEED_REG = MCBIST_MCBDRSRQ;

        static constexpr uint16_t MAX_ADDRESS_START_END_REGISTERS = 4;
        static constexpr uint64_t START_ADDRESS_0 = MCBIST_MCBSA0Q;
        static constexpr uint64_t START_ADDRESS_1 = MCBIST_MCBSA1Q;
        static constexpr uint64_t START_ADDRESS_2 = MCBIST_MCBSA2Q;
        static constexpr uint64_t START_ADDRESS_3 = MCBIST_MCBSA3Q;

        static constexpr uint64_t END_ADDRESS_0 = MCBIST_MCBEA0Q;
        static constexpr uint64_t END_ADDRESS_1 = MCBIST_MCBEA1Q;
        static constexpr uint64_t END_ADDRESS_2 = MCBIST_MCBEA2Q;
        static constexpr uint64_t END_ADDRESS_3 = MCBIST_MCBEA3Q;

        static constexpr uint64_t RANDOM_DATA_SEED0 = MCBIST_MCBRDS0Q;
        static constexpr uint64_t RANDOM_DATA_SEED1 = MCBIST_MCBRDS1Q;


        static constexpr uint64_t  MBSTRQ_CFG_PAUSE_ON_MPE = MCBIST_MBSTRQ_CFG_PAUSE_ON_MPE;


        // MCBIST Compare Masks, used to setup the ECC traps
        // TK there is one reg per port, does writing to this one write to all?
        static constexpr uint64_t COMPARE_MASK = MCA_MCBCM;

        static constexpr uint64_t PATTERN_COUNT = 4;

        // Sometimes we want to access the start/end address registers based off
        // of an index, like master rank. This allows us to do that.
        static const std::pair<uint64_t, uint64_t> address_pairs[];
        static constexpr uint64_t ADDRESS_PAIRS = 4;

        // Subtest types that need to be run in FIFO mode
        static const std::vector< mss::mcbist::op_type > FIFO_MODE_REQUIRED_OP_TYPES;

        // Which bit in the end boundary which siginifies this is a slave rank detect situation
        static constexpr uint64_t SLAVE_RANK_INDICATED_BIT = 61;

        enum
        {
            // The start/end address config registers have common lengths and bits, just including 1 below
            MCB_ADDR_CONFIG = MCBIST_MCBEA0Q_CFG_END_ADDR_0,
            MCB_ADDR_CONFIG_LEN = MCBIST_MCBEA0Q_CFG_END_ADDR_0_LEN,

            // Subtest control bits. These are the same in all '16 bit subtest' field
            COMPL_1ST_CMD = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_COMPL_1ST_CMD,
            COMPL_2ND_CMD = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_COMPL_2ND_CMD,
            COMPL_3RD_CMD = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_COMPL_3RD_CMD,
            ADDR_REV_MODE = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_ADDR_REV_MODE,
            ADDR_RAND_MODE = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_ADDR_RAND_MODE,

            // Goto subtests use the compl_1st - rand_mode to define the subtest to jump to
            GOTO_SUBTEST = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_COMPL_1ST_CMD,
            GOTO_SUBTEST_LEN = 5,

            // Refresh Only bitcode - No global enums
            REFRESH_ONLY = 0b001,

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
            MCBIST_RESUME = MCBIST_MCB_CNTLQ_RESUME_FROM_PAUSE,
            MCBIST_RESET_ERRORS = MCBIST_MCB_CNTLQ_RESET_ERROR_LOGS,

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
            SUBTEST_NUM_INDICATOR = MCBIST_MCBSTATQ_MCBIST_SUBTEST_NUM_INDICATOR,
            SUBTEST_NUM_INDICATOR_LEN = MCBIST_MCBSTATQ_MCBIST_SUBTEST_NUM_INDICATOR_LEN,

            UE_COUNT = MCBIST_MBSEC1Q_UE_COUNT,
            UE_COUNT_LEN = MCBIST_MBSEC1Q_UE_COUNT_LEN,

            MBSTRQ_CFG_MAINT_RCE_WITH_CE = MCBIST_MBSTRQ_CFG_MAINT_RCE_WITH_CE,

            CFG_AMAP_DIMM_SELECT = MCBIST_MCBAMR0A0Q_CFG_AMAP_DIMM_SELECT,
            CFG_AMAP_DIMM_SELECT_LEN = MCBIST_MCBAMR0A0Q_CFG_AMAP_DIMM_SELECT_LEN,
            CFG_AMAP_MRANK0 = MCBIST_MCBAMR0A0Q_CFG_AMAP_MRANK0,
            CFG_AMAP_MRANK0_LEN = MCBIST_MCBAMR0A0Q_CFG_AMAP_MRANK0_LEN,
            CFG_AMAP_MRANK1 = MCBIST_MCBAMR0A0Q_CFG_AMAP_MRANK1,
            CFG_AMAP_MRANK1_LEN = MCBIST_MCBAMR0A0Q_CFG_AMAP_MRANK1_LEN,
            CFG_AMAP_SRANK0 = MCBIST_MCBAMR0A0Q_CFG_AMAP_SRANK0,
            CFG_AMAP_SRANK0_LEN = MCBIST_MCBAMR0A0Q_CFG_AMAP_SRANK0_LEN,
            CFG_AMAP_SRANK1 = MCBIST_MCBAMR0A0Q_CFG_AMAP_SRANK1,
            CFG_AMAP_SRANK1_LEN = MCBIST_MCBAMR0A0Q_CFG_AMAP_SRANK1_LEN,
            CFG_AMAP_SRANK2 = MCBIST_MCBAMR0A0Q_CFG_AMAP_SRANK2,
            CFG_AMAP_SRANK2_LEN = MCBIST_MCBAMR0A0Q_CFG_AMAP_SRANK2_LEN,
            CFG_AMAP_BANK2 = MCBIST_MCBAMR0A0Q_CFG_AMAP_BANK2,
            CFG_AMAP_BANK2_LEN = MCBIST_MCBAMR0A0Q_CFG_AMAP_BANK2_LEN ,
            CFG_AMAP_BANK1 = MCBIST_MCBAMR0A0Q_CFG_AMAP_BANK1,
            CFG_AMAP_BANK1_LEN = MCBIST_MCBAMR0A0Q_CFG_AMAP_BANK1_LEN ,
            CFG_AMAP_BANK0 = MCBIST_MCBAMR0A0Q_CFG_AMAP_BANK0,
            CFG_AMAP_BANK0_LEN = MCBIST_MCBAMR0A0Q_CFG_AMAP_BANK0_LEN ,

            CFG_AMAP_BANK_GROUP1 = MCBIST_MCBAMR1A0Q_CFG_AMAP_BANK_GROUP1,
            CFG_AMAP_BANK_GROUP1_LEN = MCBIST_MCBAMR1A0Q_CFG_AMAP_BANK_GROUP1_LEN ,
            CFG_AMAP_BANK_GROUP0 = MCBIST_MCBAMR1A0Q_CFG_AMAP_BANK_GROUP0,
            CFG_AMAP_BANK_GROUP0_LEN = MCBIST_MCBAMR1A0Q_CFG_AMAP_BANK_GROUP0_LEN ,
            CFG_AMAP_ROW17 = MCBIST_MCBAMR1A0Q_CFG_AMAP_ROW17,
            CFG_AMAP_ROW17_LEN = MCBIST_MCBAMR1A0Q_CFG_AMAP_ROW17_LEN,
            CFG_AMAP_ROW16 = MCBIST_MCBAMR1A0Q_CFG_AMAP_ROW16,
            CFG_AMAP_ROW16_LEN = MCBIST_MCBAMR1A0Q_CFG_AMAP_ROW16_LEN,
            CFG_AMAP_ROW15 = MCBIST_MCBAMR1A0Q_CFG_AMAP_ROW15,
            CFG_AMAP_ROW15_LEN = MCBIST_MCBAMR1A0Q_CFG_AMAP_ROW15_LEN,
            CFG_AMAP_ROW14 = MCBIST_MCBAMR1A0Q_CFG_AMAP_ROW14,
            CFG_AMAP_ROW14_LEN = MCBIST_MCBAMR1A0Q_CFG_AMAP_ROW14_LEN,
            CFG_AMAP_ROW13 = MCBIST_MCBAMR1A0Q_CFG_AMAP_ROW13,
            CFG_AMAP_ROW13_LEN = MCBIST_MCBAMR1A0Q_CFG_AMAP_ROW13_LEN,
            CFG_AMAP_ROW12 = MCBIST_MCBAMR1A0Q_CFG_AMAP_ROW12,
            CFG_AMAP_ROW12_LEN = MCBIST_MCBAMR1A0Q_CFG_AMAP_ROW12_LEN,
            CFG_AMAP_ROW11 = MCBIST_MCBAMR1A0Q_CFG_AMAP_ROW11,
            CFG_AMAP_ROW11_LEN = MCBIST_MCBAMR1A0Q_CFG_AMAP_ROW11_LEN,
            CFG_AMAP_ROW10 = MCBIST_MCBAMR1A0Q_CFG_AMAP_ROW10,
            CFG_AMAP_ROW10_LEN = MCBIST_MCBAMR1A0Q_CFG_AMAP_ROW10_LEN,

            CFG_AMAP_ROW9 = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW9,
            CFG_AMAP_ROW9_LEN = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW9_LEN,
            CFG_AMAP_ROW8 = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW8,
            CFG_AMAP_ROW8_LEN = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW8_LEN,
            CFG_AMAP_ROW7 = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW7,
            CFG_AMAP_ROW7_LEN = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW7_LEN,
            CFG_AMAP_ROW6 = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW6,
            CFG_AMAP_ROW6_LEN = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW6_LEN,
            CFG_AMAP_ROW5 = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW5,
            CFG_AMAP_ROW5_LEN = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW5_LEN,
            CFG_AMAP_ROW4 = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW4,
            CFG_AMAP_ROW4_LEN = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW4_LEN,
            CFG_AMAP_ROW3 = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW3,
            CFG_AMAP_ROW3_LEN = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW3_LEN,
            CFG_AMAP_ROW2 = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW2,
            CFG_AMAP_ROW2_LEN = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW2_LEN,
            CFG_AMAP_ROW1 = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW1,
            CFG_AMAP_ROW1_LEN = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW1_LEN,
            CFG_AMAP_ROW0 = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW0,
            CFG_AMAP_ROW0_LEN = MCBIST_MCBAMR2A0Q_CFG_AMAP_ROW0_LEN,

            CFG_AMAP_COL9 = MCBIST_MCBAMR3A0Q_CFG_AMAP_COL9,
            CFG_AMAP_COL9_LEN = MCBIST_MCBAMR3A0Q_CFG_AMAP_COL9_LEN,
            CFG_AMAP_COL8 = MCBIST_MCBAMR3A0Q_CFG_AMAP_COL8,
            CFG_AMAP_COL8_LEN = MCBIST_MCBAMR3A0Q_CFG_AMAP_COL8_LEN,
            CFG_AMAP_COL7 = MCBIST_MCBAMR3A0Q_CFG_AMAP_COL7,
            CFG_AMAP_COL7_LEN = MCBIST_MCBAMR3A0Q_CFG_AMAP_COL7_LEN,
            CFG_AMAP_COL6 = MCBIST_MCBAMR3A0Q_CFG_AMAP_COL6,
            CFG_AMAP_COL6_LEN = MCBIST_MCBAMR3A0Q_CFG_AMAP_COL6_LEN,
            CFG_AMAP_COL5 = MCBIST_MCBAMR3A0Q_CFG_AMAP_COL5,
            CFG_AMAP_COL5_LEN = MCBIST_MCBAMR3A0Q_CFG_AMAP_COL5_LEN,
            CFG_AMAP_COL4 = MCBIST_MCBAMR3A0Q_CFG_AMAP_COL4,
            CFG_AMAP_COL4_LEN = MCBIST_MCBAMR3A0Q_CFG_AMAP_COL4_LEN,
            CFG_AMAP_COL3 = MCBIST_MCBAMR3A0Q_CFG_AMAP_COL3,
            CFG_AMAP_COL3_LEN = MCBIST_MCBAMR3A0Q_CFG_AMAP_COL3_LEN,
            CFG_AMAP_COL2 = MCBIST_MCBAMR3A0Q_CFG_AMAP_COL2,
            CFG_AMAP_COL2_LEN = MCBIST_MCBAMR3A0Q_CFG_AMAP_COL2_LEN,

            LFSR_MASK = MCBIST_MCBLFSRA0Q_CFG_LFSR_MASK_A0,
            LFSR_MASK_LEN = MCBIST_MCBLFSRA0Q_CFG_LFSR_MASK_A0_LEN,

            CFG_DATA_ROT_SEED1 = MCBIST_MCBDRSRQ_CFG_DATA_ROT_SEED,
            CFG_DATA_ROT_SEED1_LEN = MCBIST_MCBDRSRQ_CFG_DATA_ROT_SEED_LEN,
            CFG_DATA_ROT = MCBIST_MCBDRCRQ_CFG_DATA_ROT,
            CFG_DATA_ROT_LEN = MCBIST_MCBDRCRQ_CFG_DATA_ROT_LEN,
            CFG_DATA_ROT_SEED2 = MCBIST_MCBDRCRQ_CFG_DATA_ROT_SEED,
            CFG_DATA_ROT_SEED2_LEN = MCBIST_MCBDRCRQ_CFG_DATA_ROT_SEED_LEN,
            CFG_DATA_SEED_MODE = MCBIST_MCBDRCRQ_CFG_DATA_SEED_MODE,
            CFG_DATA_SEED_MODE_LEN = MCBIST_MCBDRCRQ_CFG_DATA_SEED_MODE_LEN,

            CFG_TRAP_CE_ENABLE = MCA_MCBCM_MCBIST_TRAP_CE_ENABLE,
            CFG_TRAP_UE_ENABLE = MCA_MCBCM_MCBIST_TRAP_UE_ENABLE,
            CFG_TRAP_MPE_ENABLE = MCA_MCBCM_MCBIST_TRAP_MPE_ENABLE,

            CFG_DGEN_RNDD_SEED0 = MCBIST_MCBRDS0Q_DGEN_RNDD_SEED0,
            CFG_DGEN_RNDD_SEED0_LEN = MCBIST_MCBRDS0Q_DGEN_RNDD_SEED0_LEN,
            CFG_DGEN_RNDD_SEED1 = MCBIST_MCBRDS0Q_DGEN_RNDD_SEED1,
            CFG_DGEN_RNDD_SEED1_LEN = MCBIST_MCBRDS0Q_DGEN_RNDD_SEED1_LEN,
            CFG_DGEN_RNDD_SEED2 = MCBIST_MCBRDS1Q_DGEN_RNDD_SEED2,
            CFG_DGEN_RNDD_SEED2_LEN = MCBIST_MCBRDS1Q_DGEN_RNDD_SEED2_LEN,
            CFG_DGEN_RNDD_DATA_MAPPING = MCBIST_MCBRDS1Q_DGEN_RNDD_DATA_MAPPING,
            CFG_DGEN_RNDD_DATA_MAPPING_LEN = MCBIST_MCBRDS1Q_DGEN_RNDD_DATA_MAPPING_LEN,

            // THRESHOLD control bits
            MBSTRQ_CFG_THRESH_MAG_NCE_INT = MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_INT,
            MBSTRQ_CFG_THRESH_MAG_NCE_INT_LEN = MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_INT_LEN,
            MBSTRQ_CFG_THRESH_MAG_NCE_SOFT = MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_SOFT,
            MBSTRQ_CFG_THRESH_MAG_NCE_SOFT_LEN = MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_SOFT_LEN,
            MBSTRQ_CFG_THRESH_MAG_NCE_HARD = MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_HARD,
            MBSTRQ_CFG_THRESH_MAG_NCE_HARD_LEN = MCBIST_MBSTRQ_CFG_THRESH_MAG_NCE_HARD_LEN,
            MBSTRQ_CFG_THRESH_MAG_RCE = MCBIST_MBSTRQ_CFG_THRESH_MAG_RCE,
            MBSTRQ_CFG_THRESH_MAG_RCE_LEN = MCBIST_MBSTRQ_CFG_THRESH_MAG_RCE_LEN,
            MBSTRQ_CFG_THRESH_MAG_ICE = MCBIST_MBSTRQ_CFG_THRESH_MAG_ICE,
            MBSTRQ_CFG_THRESH_MAG_ICE_LEN = MCBIST_MBSTRQ_CFG_THRESH_MAG_ICE_LEN,
            MBSTRQ_CFG_THRESH_MAG_MCE_INT = MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_INT,
            MBSTRQ_CFG_THRESH_MAG_MCE_INT_LEN = MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_INT_LEN,
            MBSTRQ_CFG_THRESH_MAG_MCE_SOFT = MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_SOFT,
            MBSTRQ_CFG_THRESH_MAG_MCE_SOFT_LEN = MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_SOFT_LEN,
            MBSTRQ_CFG_THRESH_MAG_MCE_HARD = MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_HARD,
            MBSTRQ_CFG_THRESH_MAG_MCE_HARD_LEN = MCBIST_MBSTRQ_CFG_THRESH_MAG_MCE_HARD_LEN,
            MBSTRQ_CFG_PAUSE_ON_SCE = MCBIST_MBSTRQ_CFG_PAUSE_ON_SCE,
            MBSTRQ_CFG_PAUSE_ON_MCE = MCBIST_MBSTRQ_CFG_PAUSE_ON_MCE,
            MBSTRQ_CFG_PAUSE_ON_UE = MCBIST_MBSTRQ_CFG_PAUSE_ON_UE,
            MBSTRQ_CFG_PAUSE_ON_SUE = MCBIST_MBSTRQ_CFG_PAUSE_ON_SUE,
            MBSTRQ_CFG_PAUSE_ON_AUE = MCBIST_MBSTRQ_CFG_PAUSE_ON_AUE,
            MBSTRQ_CFG_PAUSE_ON_RCD = MCBIST_MBSTRQ_CFG_PAUSE_ON_RCD,
            MBSTRQ_CFG_SYMBOL_COUNTER_MODE = MCBIST_MBSTRQ_CFG_SYMBOL_COUNTER_MODE,
            MBSTRQ_CFG_SYMBOL_COUNTER_MODE_LEN = MCBIST_MBSTRQ_CFG_SYMBOL_COUNTER_MODE_LEN,
            MBSTRQ_CFG_NCE_SOFT_SYMBOL_COUNT_ENABLE = MCBIST_MBSTRQ_CFG_NCE_SOFT_SYMBOL_COUNT_ENABLE,
            MBSTRQ_CFG_NCE_INTER_SYMBOL_COUNT_ENABLE = MCBIST_MBSTRQ_CFG_NCE_INTER_SYMBOL_COUNT_ENABLE,
            MBSTRQ_CFG_NCE_HARD_SYMBOL_COUNT_ENABLE = MCBIST_MBSTRQ_CFG_NCE_HARD_SYMBOL_COUNT_ENABLE,
            MBSTRQ_CFG_PAUSE_MCB_ERROR = MCBIST_MBSTRQ_CFG_PAUSE_MCB_ERROR,
            MBSTRQ_CFG_PAUSE_MCB_LOG_FULL = MCBIST_MBSTRQ_CFG_PAUSE_MCB_LOG_FULL,
            MBSTRQ_CFG_MCE_SOFT_SYMBOL_COUNT_ENABLE = MCBIST_MBSTRQ_CFG_MCE_SOFT_SYMBOL_COUNT_ENABLE,
            MBSTRQ_CFG_MCE_INTER_SYMBOL_COUNT_ENABLE = MCBIST_MBSTRQ_CFG_MCE_INTER_SYMBOL_COUNT_ENABLE,
            MBSTRQ_CFG_MCE_HARD_SYMBOL_COUNT_ENABLE = MCBIST_MBSTRQ_CFG_MCE_HARD_SYMBOL_COUNT_ENABLE,

            // Bit mapping for MCBIST error log control data (address+ in Nimbus doc)
            ERROR_LOG_SUBTEST = 0,
            ERROR_LOG_SUBTEST_LEN = 5,
            ERROR_LOG_SUBCMD = 5,
            ERROR_LOG_SUBCMD_LEN = 2,
            ERROR_LOG_ADDR_DIMM = 7,
            ERROR_LOG_ADDR_MRANK = 8,
            ERROR_LOG_ADDR_MRANK_LEN = 2,
            ERROR_LOG_ADDR_SRANK = 10,
            ERROR_LOG_ADDR_SRANK_LEN = 3,
            ERROR_LOG_ADDR_BANK_GROUP = 13,
            ERROR_LOG_ADDR_BANK_GROUP_LEN = 2,
            ERROR_LOG_ADDR_BANK = 15,
            ERROR_LOG_ADDR_BANK_LEN = 3,
            ERROR_LOG_ADDR_ROW = 18,
            ERROR_LOG_ADDR_ROW_LEN = 18,
            ERROR_LOG_ADDR_COLUMN = 36,
            ERROR_LOG_ADDR_COLUMN_LEN = 8,
            ERROR_LOG_BEAT = 44,
            ERROR_LOG_BEAT_LEN = 2,
            ERROR_LOG_TYPE = 46,
            ERROR_LOG_TYPE_LEN = 2,

            //MCBIST FIR mask
            MCB_PROGRAM_COMPLETE = MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE,
            MCB_WAT_DEBUG_ATTN = MCBIST_MCBISTFIRQ_WAT_DEBUG_ATTN,
            MCB_PROGRAM_COMPLETE_MASK = MCB_PROGRAM_COMPLETE,
            MCB_WAT_DEBUG_ATTN_MASK = MCB_WAT_DEBUG_ATTN,
            MCB_DATA_ERROR = MCBIST_MCBISTFIRQ_MCBIST_DATA_ERROR,

            //XLT address valid offset
            XLT0_SLOT1_D_VALID     = MCS_PORT13_MCP0XLT0_SLOT1_VALID,
            XLT0_SLOT0_M1_VALID    = MCS_PORT13_MCP0XLT0_SLOT0_M1_VALID,
            XLT0_SLOT0_M0_VALID    = MCS_PORT13_MCP0XLT0_SLOT0_M0_VALID,
            XLT0_SLOT0_S2_VALID    = MCS_PORT13_MCP0XLT0_SLOT0_S2_VALID,
            XLT0_SLOT0_S1_VALID    = MCS_PORT13_MCP0XLT0_SLOT0_S1_VALID,
            XLT0_SLOT0_S0_VALID    = MCS_PORT13_MCP0XLT0_SLOT0_S0_VALID,
            XLT0_SLOT0_ROW17_VALID = MCS_PORT02_MCP0XLT0_SLOT0_ROW17_VALID,
            XLT0_SLOT0_ROW16_VALID = MCS_PORT02_MCP0XLT0_SLOT0_ROW16_VALID,
            XLT0_SLOT0_ROW15_VALID = MCS_PORT02_MCP0XLT0_SLOT0_ROW15_VALID,

        };


};


///
/// @class mcbistTraits
/// @brief a collection of traits associated with the Nimbus MCA
///
template<>
class mcbistTraits<mss::mc_type::NIMBUS, fapi2::TARGET_TYPE_MCA>
{
    public:
        // MCBIST error log related registers
        static constexpr uint64_t ERROR_LOG_PTR_REG = MCA_ELPR;
        static constexpr uint64_t RMW_WRT_BUF_CTL_REG = MCA_WREITE_AACR;
        static constexpr uint64_t RMW_WRT_BUF_DATA_REG = MCA_AADR;
        static constexpr uint64_t RMW_WRT_BUF_ECC_REG = MCA_AAER;

        // XLT registers
        static constexpr uint64_t XLTATE0 = MCA_MBA_MCP0XLT0;
        static constexpr uint64_t XLTATE1 = MCA_MBA_MCP0XLT1;
        static constexpr uint64_t XLTATE2 = MCA_MBA_MCP0XLT2;

        // Maintenance data location within the array
        static constexpr uint64_t MAINT_DATA_INDEX_START = 0b111110000;
        static constexpr uint64_t MAINT_DATA_INDEX_END   = 0b111111000;

        enum
        {
            // Register field constants
            ERROR_LOG_PTR = MCA_ELPR_LOG_POINTER,
            ERROR_LOG_PTR_LEN = MCA_ELPR_LOG_POINTER_LEN,
            ERROR_LOG_FULL = MCA_ELPR_LOG_FULL,
            RMW_WRT_BUFFER_SEL = MCA_WREITE_AACR_BUFFER,
            RMW_WRT_ADDRESS = MCA_WREITE_AACR_ADDRESS,
            RMW_WRT_ADDRESS_LEN = MCA_WREITE_AACR_ADDRESS_LEN,
            RMW_WRT_AUTOINC = MCA_WREITE_AACR_AUTOINC,
            RMW_WRT_ECCGEN = MCA_WREITE_AACR_ECCGEN,

            XLTATE_SLOT0_VALID = MCS_PORT02_MCP0XLT0_SLOT0_VALID,
            XLTATE_SLOT1_VALID = MCS_PORT02_MCP0XLT0_SLOT1_VALID,

            // Constants used for field settings
            SELECT_RMW_BUFFER = 0,
            SELECT_WRT_BUFFER = 1,

            // Other constants
            NUM_COMPARE_LOG_ENTRIES = 64,
            // In compare mode, there is one "info" entry per 4 data (log) entries
            // so compare mode only uses 16 info entries total in the rmw array
            NUM_COMPARE_DATA_PER_INFO_LOG = 4,
            NUM_COMPARE_INFO_ENTRIES = 16,
        };

};


///
/// @class mcbistTraits
/// @brief a collection of traits associated with the Nimbus MCS
///
template<>
class mcbistTraits<mss::mc_type::NIMBUS, fapi2::TARGET_TYPE_MCS>
{
    public:
        // MCBIST error log related registers
        static constexpr uint64_t RD_BUF_CTL_REG = MCS_PORT02_AACR;
        static constexpr uint64_t RD_BUF_DATA_REG = MCS_PORT02_AADR;
        static constexpr uint64_t RD_BUF_ECC_REG = MCS_PORT02_AAER;

        enum
        {
            // Register field constants
            RB_BUFFER_SEL = MCS_PORT02_AACR_BUFFER,
            RB_ADDRESS = MCS_PORT02_AACR_ADDRESS,
            RB_ADDRESS_LEN = MCS_PORT02_AACR_ADDRESS_LEN,
            RB_AUTOINC = MCS_PORT02_AACR_AUTOINC,

            // Other constants
            NUM_COMPARE_LOG_ENTRIES = 64,
        };

};


} // namespace mss

#endif
