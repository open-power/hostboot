/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mcbist/mcbist.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file mcbist.H
/// @brief Run and manage the MCBIST engine
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_MCBIST_H_
#define _MSS_MCBIST_H_

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/utils/poll.H>
#include <generic/memory/lib/utils/memory_size.H>
#include <lib/shared/mss_const.H>
#include <lib/utils/bit_count.H>
#include <lib/utils/num.H>
#include <lib/mcbist/patterns.H>
#include <lib/mcbist/settings.H>
#include <lib/mc/port.H>
#include <lib/dimm/kind.H>

namespace mss
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
        static constexpr uint64_t SRERR0_REG = MCBIST_MBSEC0Q;
        static constexpr uint64_t SRERR1_REG = MCBIST_MBSEC1Q;
        static constexpr uint64_t THRESHOLD_REG = MCBIST_MBSTRQ;
        static constexpr uint64_t FIRQ_REG = MCBIST_MCBISTFIRQ;
        static constexpr uint64_t LAST_ADDR_REG = MCBIST_MCBMCATQ;

        static constexpr uint64_t MCBAMR0A0Q_REG = MCBIST_MCBAMR0A0Q;
        static constexpr uint64_t MCBAMR1A0Q_REG = MCBIST_MCBAMR1A0Q;
        static constexpr uint64_t MCBAMR2A0Q_REG = MCBIST_MCBAMR2A0Q;
        static constexpr uint64_t MCBAMR3A0Q_REG = MCBIST_MCBAMR3A0Q;

        // All of the pattern registers are calculated off of this base
        static constexpr uint64_t PATTERN0_REG = MCBIST_MCBFD0Q;

        static constexpr uint64_t DATA_ROTATE_CNFG_REG = MCBIST_MCBDRCRQ;
        static constexpr uint64_t DATA_ROTATE_SEED_REG = MCBIST_MCBDRSRQ;

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


        // MCBIST Compare Masks, used to setup the ECC traps
        // TK there is one reg per port, does writing to this one write to all?
        static constexpr uint64_t COMPARE_MASK = MCA_MCBCM;

        static constexpr uint64_t PATTERN_COUNT = 4;

        // Sometimes we want to access the start/end address registers based off
        // of an index, like master rank. This allows us to do that.
        static const std::pair<uint64_t, uint64_t> address_pairs[];

        // Subtest types that need to be run in FIFO mode
        static const std::vector< mss::mcbist::op_type > FIFO_MODE_REQUIRED_OP_TYPES;

        enum
        {
            // Subtest control bits. These are the same in all '16 bit subtest' field
            COMPL_1ST_CMD = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_COMPL_1ST_CMD,
            COMPL_2ND_CMD = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_COMPL_2ND_CMD,
            COMPL_3RD_CMD = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_COMPL_3RD_CMD,
            ADDR_REV_MODE = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_ADDR_REV_MODE,
            ADDR_RAND_MODE = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_ADDR_RAND_MODE,

            // Goto subtests use the compl_1st - rand_mode to define the subtest to jump to
            GOTO_SUBTEST = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_COMPL_1ST_CMD,
            GOTO_SUBTEST_LEN = 5,

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
        };

};

///
/// @class mcbistTraits
/// @brief a collection of traits associated with the Nimbus MCA
///
template<>
class mcbistTraits<fapi2::TARGET_TYPE_MCA>
{
    public:
        // MCBIST error log related registers
        static constexpr uint64_t ERROR_LOG_PTR_REG = MCA_ELPR;
        static constexpr uint64_t RMW_WRT_BUF_CTL_REG = MCA_WREITE_AACR;
        static constexpr uint64_t RMW_WRT_BUF_DATA_REG = MCA_AADR;
        static constexpr uint64_t RMW_WRT_BUF_ECC_REG = MCA_AAER;

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
class mcbistTraits<fapi2::TARGET_TYPE_MCS>
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

namespace mcbist
{

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
        /// @brief Checks if the op type requires FIFO mode to be on
        /// @return bool fifo_mode_requried - true if FIFO mode is required to be forced on
        ///
        inline bool fifo_mode_required() const
        {
            // Gets the op type for this subtest
            uint64_t l_value_to_find = 0;
            iv_mcbmr.extractToRight<TT::OP_TYPE, TT::OP_TYPE_LEN>(l_value_to_find);

            // Finds if this op type is in the vector that stores the OP types that require FIFO mode to be run
            const auto l_op_type_it = std::find(TT::FIFO_MODE_REQUIRED_OP_TYPES.begin(), TT::FIFO_MODE_REQUIRED_OP_TYPES.end(),
                                                l_value_to_find);

            // If the op type is required (aka was found), it will be less than end
            // std::find returns the ending iterator if it was not found, so this will return false in that case
            return l_op_type_it != TT::FIFO_MODE_REQUIRED_OP_TYPES.end();
        }

        ///
        /// @brief Convert to a 16 bit int
        /// @return the subtest as a 16 bit integer, useful for testing
        ///
        inline operator uint16_t()
        {
            return uint16_t(iv_mcbmr);
        }

        ///
        /// @brief Complement the data for the first subcommand
        /// @param[in] i_state the desired state (mss::ON or mss::OFF)
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
        /// @brief Get the port from this subtest
        /// @note The port number is relative to the MCBIST
        /// @return the port of the subtest
        ///
        inline uint64_t get_port() const
        {
            uint64_t l_port = 0;
            constexpr uint64_t l_len = (TT::COMPL_2ND_CMD - TT::COMPL_1ST_CMD) + 1;
            iv_mcbmr.template extractToRight<TT::COMPL_1ST_CMD, l_len>(l_port);
            return l_port;
        }

        ///
        /// @brief Get the DIMM from this subtest
        /// @return the DIMM this subtest has been configured for
        ///
        inline uint64_t get_dimm() const
        {
            return iv_mcbmr.template getBit<TT::COMPL_3RD_CMD>() ? 1 : 0;
        }

        ///
        /// @brief Add the subtest to go to
        /// @param[in] the subtest to jump to
        /// @return void
        ///
        inline void change_goto_subtest( const uint64_t i_jmp_to )
        {
            iv_mcbmr.template insertFromRight<TT::GOTO_SUBTEST, TT::GOTO_SUBTEST_LEN>(i_jmp_to);
            FAPI_INF("changing subtest to jump to %d (0x%02x)", i_jmp_to, iv_mcbmr);
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
            constexpr uint16_t MAX_ADDRESS_START_END_REGISTERS = 3 + 1;
            iv_mcbmr.template insertFromRight<TT::ADDR_SEL, TT::ADDR_SEL_LEN>(i_index % MAX_ADDRESS_START_END_REGISTERS);
            FAPI_INF("changed address select to index %d (0x%x)", i_index, iv_mcbmr);
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

    // 12    = 1    - ecc
    // By default we want to turn on ECC. Caller can turn it off.
    l_subtest.change_ecc_mode(mss::ON);

    // 14:15 = 0 address select config registers 0

    return l_subtest;
}


///
/// @brief Return an alter subtest - configured simply
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @return mss::mcbist::subtest_t
/// @note Turns on ECC mode for the returned subtest - caller can turn it off
/// @note Configures for start/end address select bit as address config register 0
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline subtest_t<T> alter_subtest()
{
    // Starts life full of 0's
    subtest_t<T> l_subtest;

    // 0:3   = 1011 - we want subtest type to be a Alter
    l_subtest.iv_mcbmr.template insertFromRight<TT::OP_TYPE, TT::OP_TYPE_LEN>(op_type::ALTER);

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
/// @brief Return an display subtest - configured simply
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @return mss::mcbist::subtest_t
/// @note Turns on ECC mode for the returned subtest - caller can turn it off
/// @note Configures for start/end address select bit as address config register 0
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline subtest_t<T> display_subtest()
{
    // Starts life full of 0's
    subtest_t<T> l_subtest;

    // 0:3   = 1100 - we want subtest type to be a Display
    l_subtest.iv_mcbmr.template insertFromRight<TT::OP_TYPE, TT::OP_TYPE_LEN>(op_type::DISPLAY);

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
/// @brief Return an scrub subtest - configured simply
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @return mss::mcbist::subtest_t
/// @note Turns on ECC mode for the returned subtest - caller can turn it off
/// @note Configures for start/end address select bit as address config register 0
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline subtest_t<T> scrub_subtest()
{
    // Starts life full of 0's
    subtest_t<T> l_subtest;

    // 0:3   = 1001 - we want subtest type to be a Scrub
    l_subtest.iv_mcbmr.template insertFromRight<TT::OP_TYPE, TT::OP_TYPE_LEN>(op_type::SCRUB_RRWR);

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
/// @brief Return a steer subtest - configured simply
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @return mss::mcbist::subtest_t
/// @note Turns on ECC mode for the returned subtest - caller can turn it off
/// @note Configures for start/end address select bit as address config register 0
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline subtest_t<T> steer_subtest()
{
    // Starts life full of 0's
    subtest_t<T> l_subtest;

    // 0:3   = 1010 - we want subtest type to be a Steer
    l_subtest.iv_mcbmr.template insertFromRight<TT::OP_TYPE, TT::OP_TYPE_LEN>(op_type::STEER_RW);

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
/// @brief Return a read write subtest - configured simply
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @return mss::mcbist::subtest_t
/// @note Turns on ECC mode for the returned subtest - caller can turn it off
/// @note Configures for start/end address select bit as address config register 0
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline subtest_t<T> read_write_subtest()
{
    // Starts life full of 0's
    subtest_t<T> l_subtest;

    // 0:3   = 0010 - we want subtest type to be a Read Write (RW)
    l_subtest.iv_mcbmr.template insertFromRight<TT::OP_TYPE, TT::OP_TYPE_LEN>(op_type::READ_WRITE);

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
/// @brief Return a read write read subtest - configured simply
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @return mss::mcbist::subtest_t
/// @note Turns on ECC mode for the returned subtest - caller can turn it off
/// @note Configures for start/end address select bit as address config register 0
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline subtest_t<T> read_write_read_subtest()
{
    // Starts life full of 0's
    subtest_t<T> l_subtest;

    // 0:3   = 0100 - we want subtest type to be a Read Write Read (RWR)          7
    l_subtest.iv_mcbmr.template insertFromRight<TT::OP_TYPE, TT::OP_TYPE_LEN>(op_type::READ_WRITE_READ);

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
/// @brief Return a random subtest - configured simply
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @return mss::mcbist::subtest_t
/// @note Turns on ECC mode for the returned subtest - caller can turn it off
/// @note Configures for start/end address select bit as address config register 0
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline subtest_t<T> random_subtest()
{
    // Starts life full of 0's
    subtest_t<T> l_subtest;

    // 0:3   = 0110 - we want subtest type to be a Random Seq, a randomly chosen read or write
    l_subtest.iv_mcbmr.template insertFromRight<TT::OP_TYPE, TT::OP_TYPE_LEN>(op_type::RAND_SEQ);

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
/// @brief Return a goto subtest - configured simply
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @param[in] the subtest we should go to
/// @return mss::mcbist::subtest_t
/// @note Turns on ECC mode for the returned subtest - caller can turn it off
/// @note Configures for start/end address select bit as address config register 0
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline subtest_t<T> goto_subtest( const uint64_t i_jump_to )
{
    // Starts life full of 0's
    subtest_t<T> l_subtest;

    // 0:3   = 0111 - we want subtest type to be a Goto
    l_subtest.iv_mcbmr.template insertFromRight<TT::OP_TYPE, TT::OP_TYPE_LEN>(op_type::GOTO_SUBTEST_N);

    // Plug in the subtest the user passed in
    l_subtest.change_goto_subtest(i_jump_to);
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
/// - ENABLE_HOST_ATTN - enabled
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
            iv_data_rotate_cnfg(0),
            iv_data_rotate_seed(0),
            iv_config(0),
            iv_control(0),
            iv_async(false),
            iv_pattern(PATTERN_0),
            iv_random24_data_seed(RANDOM24_SEEDS_0),
            iv_random24_seed_map(RANDOM24_SEED_MAP_0),
            iv_compare_mask(0)
        {
            // Enable the maintenance mode addressing
            change_maint_address_mode(mss::ON);

            // Enable 64B lengths by default. Commands which need 128B (scrub, steer, alter, display)
            // can change this to 128B (mss::OFF).
            change_len64(mss::ON);

            // Turn off counting mode for all address configs
            iv_addr_gen.insertFromRight<TT::ADDR_COUNTER_MODE, TT::ADDR_COUNTER_MODE_LEN>(0b0000);

            // By default if there's an error, we stop after the errored address
            iv_config.insertFromRight<TT::CFG_PAUSE_ON_ERROR_MODE,
                                      TT::CFG_PAUSE_ON_ERROR_MODE_LEN>(end_boundary::STOP_AFTER_ADDRESS);

            // All mcbist attentions are host attentions, special attention bit is already clear
            iv_config.setBit<TT::CFG_ENABLE_HOST_ATTN>();

        }

        ///
        /// @brief Change the DIMM select in the address mapping
        /// @param[in] i_bitmap DIMM select bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_dimm_select_bit( const uint64_t i_bitmap )
        {
            iv_addr_map0.insertFromRight<TT::CFG_AMAP_DIMM_SELECT, TT::CFG_AMAP_DIMM_SELECT_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the MRANK0 address mapping when not in 5D mode
        /// @param[in] i_bitmap MRANK0 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_mrank0_bit( const uint64_t i_bitmap )
        {
            iv_addr_map0.insertFromRight<TT::CFG_AMAP_MRANK0, TT::CFG_AMAP_MRANK0_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the MRANK0 address mapping when in 5D mode
        /// @param[in] i_bitmap MRANK0 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_mrank0_bit_5d( const uint64_t i_bitmap )
        {
            iv_addr_map0.insertFromRight<TT::CFG_AMAP_SRANK0, TT::CFG_AMAP_SRANK0_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the MRANK1 address mapping when not in 5D mode
        /// @param[in] i_bitmap MRANK1 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_mrank1_bit( const uint64_t i_bitmap )
        {
            iv_addr_map0.insertFromRight<TT::CFG_AMAP_MRANK1, TT::CFG_AMAP_MRANK1_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the MRANK1 address mapping when in 5D mode
        /// @param[in] i_bitmap MRANK1 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_mrank1_bit_5d( const uint64_t i_bitmap )
        {
            iv_addr_map0.insertFromRight<TT::CFG_AMAP_SRANK1, TT::CFG_AMAP_SRANK1_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the MRANK2 address mapping when in 5D mode
        /// @param[in] i_bitmap MRANK2 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_mrank2_bit_5d( const uint64_t i_bitmap )
        {
            iv_addr_map0.insertFromRight<TT::CFG_AMAP_SRANK2, TT::CFG_AMAP_SRANK2_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the SRANK0 address mapping when in 5D mode
        /// @param[in] i_bitmap SRANK0 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_srank0_bit( const uint64_t i_bitmap )
        {
            iv_addr_map0.insertFromRight<TT::CFG_AMAP_SRANK0, TT::CFG_AMAP_SRANK0_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the SRANK1 address mapping
        /// @param[in] i_bitmap SRANK1 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_srank1_bit( const uint64_t i_bitmap )
        {
            iv_addr_map0.insertFromRight<TT::CFG_AMAP_SRANK1, TT::CFG_AMAP_SRANK1_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the SRANK2 address mapping
        /// @param[in] i_bitmap SRANK2 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_srank2_bit( const uint64_t i_bitmap )
        {
            iv_addr_map0.insertFromRight<TT::CFG_AMAP_SRANK2, TT::CFG_AMAP_SRANK2_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the BANK2 address mapping
        /// @param[in] i_bitmap BANK2 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_bank2_bit( const uint64_t i_bitmap )
        {
            iv_addr_map0.insertFromRight<TT::CFG_AMAP_BANK2, TT::CFG_AMAP_BANK2_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the BANK1 address mapping
        /// @param[in] i_bitmap BANK1 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_bank1_bit( const uint64_t i_bitmap )
        {
            iv_addr_map0.insertFromRight<TT::CFG_AMAP_BANK1, TT::CFG_AMAP_BANK1_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the BANK0 address mapping
        /// @param[in] i_bitmap BANK0 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_bank0_bit( const uint64_t i_bitmap )
        {
            iv_addr_map0.insertFromRight<TT::CFG_AMAP_BANK0, TT::CFG_AMAP_BANK0_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the BANK_GROUP1 address mapping
        /// @param[in] i_bitmap BANK_GROUP1 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_bank_group1_bit( const uint64_t i_bitmap )
        {
            iv_addr_map1.insertFromRight<TT::CFG_AMAP_BANK_GROUP1, TT::CFG_AMAP_BANK_GROUP1_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the BANK_GROUP0 address mapping
        /// @param[in] i_bitmap BANK_GROUP0 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_bank_group0_bit( const uint64_t i_bitmap )
        {
            iv_addr_map1.insertFromRight<TT::CFG_AMAP_BANK_GROUP0, TT::CFG_AMAP_BANK_GROUP0_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the ROW17 address mapping
        /// @param[in] i_bitmap ROW17 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_row17_bit( const uint64_t i_bitmap )
        {
            iv_addr_map1.insertFromRight<TT::CFG_AMAP_ROW17, TT::CFG_AMAP_ROW17_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the ROW16 address mapping
        /// @param[in] i_bitmap ROW16 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_row16_bit( const uint64_t i_bitmap )
        {
            iv_addr_map1.insertFromRight<TT::CFG_AMAP_ROW16, TT::CFG_AMAP_ROW16_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the ROW15 address mapping
        /// @param[in] i_bitmap ROW15 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_row15_bit( const uint64_t i_bitmap )
        {
            iv_addr_map1.insertFromRight<TT::CFG_AMAP_ROW15, TT::CFG_AMAP_ROW15_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the ROW14 address mapping
        /// @param[in] i_bitmap ROW14 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_row14_bit( const uint64_t i_bitmap )
        {
            iv_addr_map1.insertFromRight<TT::CFG_AMAP_ROW14, TT::CFG_AMAP_ROW14_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the ROW13 address mapping
        /// @param[in] i_bitmap ROW13 bit map in the address counter
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_row13_bit( const uint64_t i_bitmap )
        {
            iv_addr_map1.insertFromRight<TT::CFG_AMAP_ROW13, TT::CFG_AMAP_ROW13_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the ROW12 address mapping
        /// @param[in] i_bitmap ROW12 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_row12_bit( const uint64_t i_bitmap )
        {
            // CFG_AMAP_ROW12     = MCBIST_MCBAMR1A0Q_CFG_AMAP_ROW12     ,
            iv_addr_map1.insertFromRight<TT::CFG_AMAP_ROW12, TT::CFG_AMAP_ROW12_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the ROW11 address mapping
        /// @param[in] i_bitmap ROW11 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_row11_bit( const uint64_t i_bitmap )
        {
            iv_addr_map1.insertFromRight<TT::CFG_AMAP_ROW11, TT::CFG_AMAP_ROW11_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the ROW10 address mapping
        /// @param[in] i_bitmap ROW10 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_row10_bit( const uint64_t i_bitmap )
        {
            iv_addr_map1.insertFromRight<TT::CFG_AMAP_ROW10, TT::CFG_AMAP_ROW10_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the ROW9 address mapping
        /// @param[in] i_bitmap ROW9 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_row9_bit( const uint64_t i_bitmap )
        {
            iv_addr_map2.insertFromRight<TT::CFG_AMAP_ROW9, TT::CFG_AMAP_ROW9_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the ROW8 address mapping
        /// @param[in] i_bitmap ROW8 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_row8_bit( const uint64_t i_bitmap )
        {
            iv_addr_map2.insertFromRight<TT::CFG_AMAP_ROW8, TT::CFG_AMAP_ROW8_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the ROW7 address mapping
        /// @param[in] i_bitmap ROW7 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_row7_bit( const uint64_t i_bitmap )
        {
            iv_addr_map2.insertFromRight<TT::CFG_AMAP_ROW7, TT::CFG_AMAP_ROW7_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the ROW6 address mapping
        /// @param[in] i_bitmap ROW6 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_row6_bit( const uint64_t i_bitmap )
        {
            iv_addr_map2.insertFromRight<TT::CFG_AMAP_ROW6, TT::CFG_AMAP_ROW6_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the ROW5 address mapping
        /// @param[in] i_bitmap ROW5 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_row5_bit( const uint64_t i_bitmap )
        {
            iv_addr_map2.insertFromRight<TT::CFG_AMAP_ROW5, TT::CFG_AMAP_ROW5_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the ROW4 address mapping
        /// @param[in] i_bitmap ROW4 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_row4_bit( const uint64_t i_bitmap )
        {
            iv_addr_map2.insertFromRight<TT::CFG_AMAP_ROW4, TT::CFG_AMAP_ROW4_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the ROW3 address mapping
        /// @param[in] i_bitmap ROW3 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_row3_bit( const uint64_t i_bitmap )
        {
            iv_addr_map2.insertFromRight<TT::CFG_AMAP_ROW3, TT::CFG_AMAP_ROW3_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the ROW2 address mapping
        /// @param[in] i_bitmap ROW2 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_row2_bit( const uint64_t i_bitmap )
        {
            iv_addr_map2.insertFromRight<TT::CFG_AMAP_ROW2, TT::CFG_AMAP_ROW2_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the ROW1 address mapping
        /// @param[in] i_bitmap ROW1 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_row1_bit( const uint64_t i_bitmap )
        {
            iv_addr_map2.insertFromRight<TT::CFG_AMAP_ROW1, TT::CFG_AMAP_ROW1_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the ROW0 address mapping
        /// @param[in] i_bitmap ROW0 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_row0_bit( const uint64_t i_bitmap )
        {
            iv_addr_map2.insertFromRight<TT::CFG_AMAP_ROW0, TT::CFG_AMAP_ROW0_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the COL9 address mapping
        /// @param[in] i_bitmap COL9 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_col9_bit( const uint64_t i_bitmap )
        {
            iv_addr_map3.insertFromRight<TT::CFG_AMAP_COL9, TT::CFG_AMAP_COL9_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the COL8 address mapping
        /// @param[in] i_bitmap COL8 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_col8_bit( const uint64_t i_bitmap )
        {
            iv_addr_map3.insertFromRight<TT::CFG_AMAP_COL8, TT::CFG_AMAP_COL8_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the COL7 address mapping
        /// @param[in] i_bitmap COL7 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_col7_bit( const uint64_t i_bitmap )
        {
            iv_addr_map3.insertFromRight<TT::CFG_AMAP_COL7, TT::CFG_AMAP_COL7_LEN>(i_bitmap);
            return;
        }

        ///
        /// @brief Change the COL6 address mapping
        /// @param[in] i_bitmap COL6 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_col6_bit( const uint64_t i_bitmap )
        {
            iv_addr_map3.insertFromRight<TT::CFG_AMAP_COL6, TT::CFG_AMAP_COL6_LEN>(i_bitmap);
            return;
        }

        /// @brief Change the COL5 address mapping
        /// @param[in] i_bitmap COL5 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_col5_bit( const uint64_t i_bitmap )
        {
            iv_addr_map3.insertFromRight<TT::CFG_AMAP_COL5, TT::CFG_AMAP_COL5_LEN>(i_bitmap);
            return;
        }

        /// @brief Change the COL4 address mapping
        /// @param[in] i_bitmap COL4 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_col4_bit( const uint64_t i_bitmap )
        {
            iv_addr_map3.insertFromRight<TT::CFG_AMAP_COL4, TT::CFG_AMAP_COL4_LEN>(i_bitmap);
            return;
        }

        /// @brief Change the COL3 address mapping
        /// @param[in] i_bitmap COL3 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_col3_bit( const uint64_t i_bitmap )
        {
            iv_addr_map3.insertFromRight<TT::CFG_AMAP_COL3, TT::CFG_AMAP_COL3_LEN>(i_bitmap);
            return;
        }

        /// @brief Change the COL2 address mapping
        /// @param[in] i_bitmap COL2 bit map in the address counter
        /// @note Assumes data is right-aligned
        ///
        inline void change_col2_bit( const uint64_t i_bitmap )
        {
            iv_addr_map3.insertFromRight<TT::CFG_AMAP_COL2, TT::CFG_AMAP_COL2_LEN>(i_bitmap);
            return;
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
        /// @brief Change the random address all address mode
        /// @param[in] i_state mss::ON if you random addressing all addresses, mss::OFF if you don't
        /// @return void
        ///
        inline void random_address_all( const mss::states i_state )
        {
            iv_config.writeBit<TT::RAND_ADDR_ALL_ADDR_MODE_EN>(i_state);
            return;
        }

        ///
        /// @brief Change the broadcast sync enable bit
        /// @param[in] i_state mss::ON to enable the sync pulse, mss::OFF to disable
        /// @return void
        ///
        inline void broadcast_sync_enable( const mss::states i_state )
        {
            iv_config.writeBit<TT::SYNC_EN>(i_state);
            return;
        }

        ///
        /// @brief Change the broadcast mode sync timbase count
        /// @param[in] i_broadcast_timebase
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_broadcast_timebase( mss::mcbist::broadcast_timebase i_broadcast_timebase )
        {
            iv_config.insertFromRight<TT::SYNC_WAIT, TT::SYNC_WAIT_LEN>(i_broadcast_timebase);
            return;
        }

        ///
        /// @brief Change the mcbist thresholds
        /// @param[in] i_thresholds the new thresholds/stop conditions
        /// @return void
        ///
        inline void change_thresholds( const stop_conditions& i_thresholds )
        {
            iv_thresholds = i_thresholds;
            return;
        }

        ///
        /// @brief Change the data rotate value
        /// @param[in] i_data_rotate
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_data_rotate( mss::mcbist::data_rotate_mode i_data_rotate )
        {
            iv_data_rotate_cnfg.insertFromRight<TT::CFG_DATA_ROT, TT::CFG_DATA_ROT_LEN>(i_data_rotate);
            return;
        }

        ///
        /// @brief Get the data rotate value
        /// @note Assumes data is right aligned
        /// @return the data rotate value config
        ///
        inline uint64_t get_data_rotate()
        {
            uint64_t l_data_rotate = 0;
            iv_data_rotate_cnfg.extractToRight<TT::CFG_DATA_ROT, TT::CFG_DATA_ROT_LEN>(l_data_rotate);
            return l_data_rotate;
        }

        ///
        /// @brief Change the data seed mode value
        /// @param[in] i_data_seed_mode
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_data_seed_mode( const mss::mcbist::data_seed_mode i_data_seed_mode )
        {
            iv_data_rotate_cnfg.insertFromRight<TT::CFG_DATA_SEED_MODE, TT::CFG_DATA_SEED_MODE_LEN>(i_data_seed_mode);
            return;
        }

        ///
        /// @brief Get the data seed mode value
        /// @note Assumes data is right aligned
        /// @return the data seed mode value
        ///
        inline uint64_t get_data_seed_mode()
        {
            uint64_t l_data_seed_mode = 0;
            iv_data_rotate_cnfg.extractToRight<TT::CFG_DATA_SEED_MODE, TT::CFG_DATA_SEED_MODE_LEN>(l_data_seed_mode);
            return l_data_seed_mode;
        }

        ///
        /// @brief Change the data rotate seed for data bits 0:63
        /// @param[in] i_width
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_data_rotate_seed1( const uint64_t i_data_rotate_seed1 )
        {
            iv_data_rotate_seed.insertFromRight<TT::CFG_DATA_ROT_SEED1, TT::CFG_DATA_ROT_SEED1_LEN>(i_data_rotate_seed1);
            return;
        }

        ///
        /// @brief Get the data rotate seed for data bits 0:63
        /// @note Assumes data is right aligned
        /// @return the data rotate seed for data bits 0:63
        ///
        inline uint64_t get_data_rotate_seed1()
        {
            uint64_t l_data_rotate_seed1 = 0;
            iv_data_rotate_seed.extractToRight<TT::CFG_DATA_ROT_SEED1, TT::CFG_DATA_ROT_SEED1_LEN>(l_data_rotate_seed1);
            return l_data_rotate_seed1;
        }

        ///
        /// @brief Change the data rotate seed for data bits 64:79
        /// @param[in] i_width
        /// @note Assumes data is right-aligned
        /// @return void
        ///
        inline void change_data_rotate_seed2( const uint64_t i_data_rotate_seed2 )
        {
            iv_data_rotate_cnfg.insertFromRight<TT::CFG_DATA_ROT_SEED2, TT::CFG_DATA_ROT_SEED2_LEN>(i_data_rotate_seed2);
            return;
        }

        ///
        /// @brief Get the data rotate seed for data bits 64:79
        /// @note Assumes data is right aligned
        /// @return the data rotate seed for data bits 64:79
        ///
        inline uint64_t get_data_rotate_seed2()
        {
            uint64_t l_data_rotate_seed2 = 0;
            iv_data_rotate_cnfg.extractToRight<TT::CFG_DATA_ROT_SEED2, TT::CFG_DATA_ROT_SEED2_LEN>(l_data_rotate_seed2);
            return l_data_rotate_seed2;
        }

        ///
        /// @brief Change the compare mask CE trap enable
        /// @param[in] i_state mss::ON to enable the trap, mss::OFF to disable the trap
        /// @return void
        ///
        inline void change_ce_trap_enable( const mss::states i_state )
        {
            iv_compare_mask.writeBit<TT::CFG_TRAP_CE_ENABLE>(i_state);
            return;
        }

        ///
        /// @brief Change the compare mask UE trap enable
        /// @param[in] i_state mss::ON to enable the trap, mss::OFF to disable the trap
        /// @return void
        ///
        inline void change_ue_trap_enable( const mss::states i_state )
        {
            iv_compare_mask.writeBit<TT::CFG_TRAP_UE_ENABLE>(i_state);
            return;
        }

        ///
        /// @brief Change the compare mask MPE trap enable
        /// @param[in] i_state mss::ON to enable the trap, mss::OFF to disable the trap
        /// @return void
        ///
        inline void change_mpe_trap_enable( const mss::states i_state )
        {
            iv_compare_mask.writeBit<TT::CFG_TRAP_MPE_ENABLE>(i_state);
            return;
        }

        ///
        /// @brief Change the forced pause state
        /// @param[in] i_end the end_boundary to pause at
        /// @return void
        ///
        inline void change_forced_pause( const end_boundary& i_end )
        {
            if (i_end == end_boundary::DONT_CHANGE)
            {
                return;
            }

            // Clear all the forced pause bits so we don't stack pauses
            iv_config.clearBit<TT::MCBIST_CFG_FORCE_PAUSE_AFTER_ADDR>();
            iv_config.clearBit<TT::MCBIST_CFG_PAUSE_AFTER_RANK>();
            iv_config.clearBit<TT::MCBIST_CFG_FORCE_PAUSE_AFTER_SUBTEST>();
            iv_addr_gen.clearBit<TT::MAINT_DETECT_SRANK_BOUNDARIES>();

            switch (i_end)
            {
                case end_boundary::STOP_AFTER_ADDRESS:
                    iv_config.setBit<TT::MCBIST_CFG_FORCE_PAUSE_AFTER_ADDR>();
                    break;

                case end_boundary::STOP_AFTER_SLAVE_RANK:
                    iv_config.setBit<TT::MCBIST_CFG_PAUSE_AFTER_RANK>();
                    iv_addr_gen.setBit<TT::MAINT_DETECT_SRANK_BOUNDARIES>();
                    break;

                case end_boundary::STOP_AFTER_MASTER_RANK:
                    iv_config.setBit<TT::MCBIST_CFG_PAUSE_AFTER_RANK>();
                    iv_addr_gen.clearBit<TT::MAINT_DETECT_SRANK_BOUNDARIES>();
                    break;

                case end_boundary::STOP_AFTER_SUBTEST:
                    iv_config.setBit<TT::MCBIST_CFG_FORCE_PAUSE_AFTER_SUBTEST>();
                    break;

                // None is all set, we cleared the bits above
                case end_boundary::NONE:
                    break;

                // Default is a no forced pause (as we cleared all the bits)
                default:
                    FAPI_INF("no forced pause state - end state %d unknown", i_end);
                    break;
            };

            return;
        }

        ///
        /// @brief Calculate minimum command gap for BG_SCRUB
        /// @param[in] i_target the target behind which the memory sits
        /// @param[in] i_freq the DRAM frequency
        /// @param[in] i_size the sum of all DIMM sizes
        /// @param[out] o_min_cmd_gap the setting for MCBPARMQ_CFG_MIN_CMD_GAP
        /// @param[out] o_timebase the setting for MCBPARMQ_CFG_MIN_GAP_TIMEBASE
        ///
        inline void calculate_min_cmd_gap( const fapi2::Target<T>& i_target,
                                           const uint64_t i_freq,
                                           const uint64_t i_size,
                                           uint64_t& o_min_cmd_gap,
                                           mss::states& o_timebase )
        {
            constexpr uint64_t l_seconds = SEC_IN_HOUR * BG_SCRUB_IN_HOURS;
            constexpr uint64_t MIN_CMD_GAP = 0x001;

            // Sanity check our inputs, just assert if bad since they come directly from eff_config
            // this will prevent us from any divide by zero problems
            if ((i_freq == 0) || (i_size == 0))
            {
                FAPI_ERR("received zero memory freq or size in calculate_min_cmd_gap");
                fapi2::Assert(false);
            }

            // MIN CMD GAP = TOTAL CYCLES / TOTAL ADDRESSES
            // TOTAL CYCLES = 12 hours x 60 min/hr x 60 sec/min x [DRAM freq] cycles/sec x
            //    1/2 (MEM logic runs half DRAM freq)
            const uint64_t l_mem_cycles_per_sec = (i_freq * T_PER_MT) / 2;
            const uint64_t l_total_cycles = l_seconds * l_mem_cycles_per_sec;

            // TOTAL ADDRESSES = sum over all dimms of ( [DIMM CAPACITY]/128B )
            const uint64_t l_total_addresses = i_size * BYTES_PER_GB / 128;

            const auto l_min_cmd_gap = l_total_cycles / l_total_addresses;

            // If we're greater than the timebase, set the multiplier and divide down to get the gap setting
            if (CMD_TIMEBASE < l_min_cmd_gap)
            {
                o_min_cmd_gap = l_min_cmd_gap / CMD_TIMEBASE;
                o_timebase = mss::ON;
                return;
            }

            // If we're greater than the max gap setting, get as close to 12 hours as we can instead of just truncating
            if (l_min_cmd_gap > MAX_CMD_GAP)
            {
                // work backwards to calculate what the total scrub time would be with the highest cmd gap with no multiplier...
                const uint64_t l_scrub_time_fff = (l_total_addresses * MAX_CMD_GAP) / l_mem_cycles_per_sec;
                // and with the lowest cmd gap with the multiplier
                const uint64_t l_scrub_time_001 = (l_total_addresses * CMD_TIMEBASE) / l_mem_cycles_per_sec;

                if ((l_seconds - l_scrub_time_fff) > (l_scrub_time_001 - l_seconds))
                {
                    FAPI_INF("%s gap is greater than the field will allow. Setting to: %03x", mss::c_str(i_target), MIN_CMD_GAP);
                    o_min_cmd_gap = MIN_CMD_GAP;
                    o_timebase = mss::ON;
                }
                else
                {
                    FAPI_INF("%s gap is greater than the field will allow. Setting to: %03x", mss::c_str(i_target), MAX_CMD_GAP);
                    o_min_cmd_gap = MAX_CMD_GAP;
                    o_timebase = mss::OFF;
                }

                return;
            }

            // Else, we're good to just set the calculated gap value directly
            o_min_cmd_gap = l_min_cmd_gap;
            o_timebase = mss::OFF;
        }

        ///
        /// @brief Change MCBIST Speed
        /// @param[in] i_target the target behind which the memory sits
        /// @param[in] i_speed the speed eunmeration
        /// @return FAPI2_RC_SUCCSS iff ok
        ///
        inline fapi2::ReturnCode change_speed( const fapi2::Target<T>& i_target, const speed i_speed )
        {
            switch (i_speed)
            {
                case speed::LUDICROUS:
                    change_min_cmd_gap(0);
                    change_min_gap_timebase(mss::OFF);
                    return fapi2::FAPI2_RC_SUCCESS;
                    break;

                case speed::BG_SCRUB:
                    {
                        uint64_t l_freq = 0;
                        uint64_t l_size = 0;
                        uint64_t l_min_cmd_gap = 0;
                        mss::states l_timebase = mss::OFF;

                        constexpr uint64_t l_seconds = SEC_IN_HOUR * BG_SCRUB_IN_HOURS;

                        FAPI_TRY( mss::freq(i_target, l_freq) );
                        FAPI_TRY( mss::eff_memory_size(i_target, l_size) );

                        calculate_min_cmd_gap(i_target, l_freq, l_size, l_min_cmd_gap, l_timebase);

                        FAPI_INF("%s setting bg scrub speed: %dMT/s, memory: %dGB, duration: %ds, gap: %d",
                                 mss::c_str(i_target), l_freq, l_size, l_seconds, l_min_cmd_gap);

                        change_min_cmd_gap(l_min_cmd_gap);
                        change_min_gap_timebase(l_timebase);

                        return fapi2::FAPI2_RC_SUCCESS;
                    }
                    break;

                // Otherwise it's SAME_SPEED or something else in which case we do nothing
                default:
                    break;
            };

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Get a list of ports involved in the program
        /// @tparam P fapi2 target type of port
        /// @param[in] i_target the target for this program
        /// @return vector of port targets
        ///
        template< fapi2::TargetType P >
        std::vector<fapi2::Target<P>> get_port_list( const fapi2::Target<T>& i_target ) const;

        ///
        /// @brief Change MCBIST Stop-on-error conditions (end boundaries)
        /// @param[in] i_end the end boundary
        /// @note By default the MCBIST is programmed to always stop after an errored address. This API
        /// allows the caller to force a stop at a boundary or to force no stopping on errors
        ///
        inline void change_end_boundary( const end_boundary i_end )
        {
            // Which bit in the end boundary which siginifies this is a slave rank detect situation
            constexpr uint64_t SLAVE_RANK_INDICATED_BIT = 61;

            // If there's no change, just get outta here
            if (i_end == DONT_CHANGE)
            {
                return;
            }

            // The values of the enum were crafted so that we can simply insertFromRight into the register.
            // We take note of whether to set the slave or master rank indicator and set that as well.
            // The hardware has to have a 1 or a 0 - so there is no choice for the rank detection. So it
            // doesn't matter that we're processing other end boundaries here - they'll just look like we
            // asked for a master rank detect.
            iv_config.insertFromRight<TT::CFG_PAUSE_ON_ERROR_MODE, TT::CFG_PAUSE_ON_ERROR_MODE_LEN>(i_end);

            uint64_t l_detect_slave = fapi2::buffer<uint64_t>(i_end).getBit<SLAVE_RANK_INDICATED_BIT>();
            iv_addr_gen.writeBit<TT::MAINT_DETECT_SRANK_BOUNDARIES>( l_detect_slave );
            FAPI_INF("load MCBIST end boundaries 0x%016lx detect slave? %s",
                     i_end, (l_detect_slave == 1 ? "yes" : "no") );
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
        /// @brief Get the fixed width address config
        /// @note Assumes data is right aligned
        /// @return the fixed width address config
        ///
        inline uint64_t get_fixed_width()
        {
            uint64_t l_fixed_width = 0;
            iv_addr_gen.extractToRight<TT::FIXED_WIDTH, TT::FIXED_WIDTH_LEN>(l_fixed_width);
            return l_fixed_width;
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
        /// @tparam MCBIST target type
        /// @tparam T fapi2::TargetType representing the fapi2 target which
        /// contains the MCBIST engine (e.g., fapi2::TARGET_TYPE_MCBIST)
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        /// This shouldn't be called in firmware? Check with PRD
        ///
        inline fapi2::ReturnCode process_errors( const fapi2::Target<T> i_target ) const
        {
            // Until reading the error array is documented, comparison errors 'just' result in
            // a flag indicating there was a problem on port.
            {
                fapi2::buffer<uint64_t> l_data;
                uint64_t l_port = 0;
                uint64_t l_subtest = 0;
                FAPI_TRY( mss::getScom(i_target, TT::MCBSTATQ_REG, l_data), "%s Failed getScom", mss::c_str(i_target) );
                l_data.extractToRight<TT::LOGGED_ERROR_ON_PORT_INDICATOR, TT::LOGGED_ERROR_ON_PORT_INDICATOR_LEN>(l_port);
                l_data.extractToRight<TT::SUBTEST_NUM_INDICATOR, TT::SUBTEST_NUM_INDICATOR_LEN>(l_subtest);

                FAPI_ASSERT( l_port == 0,
                             fapi2::MSS_MEMDIAGS_COMPARE_ERROR_IN_LAST_PATTERN()
                             .set_MCBIST_TARGET(i_target)
                             .set_PORT(mss::first_bit_set(l_port))
                             .set_SUBTEST(l_subtest),
                             "%s MCBIST error on port %d subtest %d", mss::c_str(i_target), mss::first_bit_set(l_port), l_subtest );
            }

            // Check for UE errors
            {
                fapi2::buffer<uint64_t> l_read0;
                fapi2::buffer<uint64_t> l_read1;

                FAPI_TRY( mss::getScom(i_target, TT::SRERR0_REG, l_read0), "%s Failed getScom", mss::c_str(i_target) );
                FAPI_TRY( mss::getScom(i_target, TT::SRERR1_REG, l_read1), "%s Failed getScom", mss::c_str(i_target) );

                FAPI_ASSERT( ((l_read0 == 0) && (l_read1 == 0)),
                             fapi2::MSS_MEMDIAGS_ERROR_IN_LAST_PATTERN()
                             .set_MCBIST_TARGET(i_target)
                             .set_STATUS0(l_read0)
                             .set_STATUS1(l_read1),
                             "%s MCBIST scrub/read error reg0: 0x%016lx reg1: 0x%016lx", mss::c_str(i_target), l_read0, l_read1 );
            }

            FAPI_INF("%s Execution success - no errors seen from MCBIST program", mss::c_str(i_target));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Store off the pattern index. We'll use this to write the patterns when we load the program
        /// @param[in] i_index an index such as mss::mcbist::PATTERN_0
        /// @return fapi2::ReturnCode checks for bad pattern index
        /// @warning if you give a pattern index which does not exist your pattern will not change.
        /// @note patterns default to PATTERN_0
        ///
        inline fapi2::ReturnCode change_pattern( const uint64_t i_pattern )
        {
            FAPI_INF("change MCBIST pattern index %d", i_pattern);

            // Sanity check the pattern since they're just numbers.
            FAPI_ASSERT( i_pattern <= mcbist::NO_PATTERN,
                         fapi2::MSS_MEMDIAGS_INVALID_PATTERN_INDEX().set_INDEX(i_pattern),
                         "Attempting to change a pattern which does not exist %d", i_pattern );

            iv_pattern = i_pattern;

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Store off the random 24b data seed index. We'll use this to write the 24b random data seeds when we load the program
        /// @param[in] i_index an index such as mss::mcbist::RANDOM24_SEEDS_0
        /// @return fapi2::ReturnCode checks for bad pattern index
        /// @warning if you give a pattern index which does not exist your pattern will not change.
        /// @note patterns default to PATTERN_0
        ///
        inline fapi2::ReturnCode change_random_24b_seeds( const uint64_t i_random24_seed )
        {
            FAPI_INF("change MCBIST 24b random data seeds index %d", i_random24_seed );

            // TK Want a new RC for random 24
            // Sanity check the pattern since they're just numbers.
            FAPI_ASSERT( i_random24_seed <= mcbist::NO_RANDOM24_SEEDS,
                         fapi2::MSS_MEMDIAGS_INVALID_PATTERN_INDEX().set_INDEX(i_random24_seed),
                         "Attempting to change to a 24b random data seed which does not exist %d", i_random24_seed );

            iv_random24_data_seed = i_random24_seed;

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Store off the random 24b data seed mapping index. We'll use this to write the 24b random data seed mappings when we load the program
        /// @param[in] i_index an index such as mss::mcbist::RANDOM24_SEEDS_0
        /// @return fapi2::ReturnCode checks for bad pattern index
        /// @warning if you give a pattern index which does not exist your pattern will not change.
        /// @note patterns default to PATTERN_0
        ///
        inline fapi2::ReturnCode change_random_24b_maps( const uint64_t i_random24_map )
        {
            FAPI_INF("change MCBIST 24b random data seed mappings index %d", i_random24_map );

            // TK Want a new RC for random 24
            // Sanity check the pattern since they're just numbers.
            FAPI_ASSERT( i_random24_map <= mcbist::NO_RANDOM24_SEED_MAP,
                         fapi2::MSS_MEMDIAGS_INVALID_PATTERN_INDEX().set_INDEX(i_random24_map),
                         "Attempting to change to a random seed map which does not exist %d", i_random24_map );

            iv_random24_seed_map = i_random24_map;

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief checks if two programs are equal
        /// @param[in] i_rhs program to compare
        /// @return bool true if equal
        ///
        inline bool operator==( const program<T>& i_rhs ) const
        {
            //checks the vector first, to save time if they're not equal (no sense in checking everything else)
            if(iv_subtests != i_rhs.iv_subtests)
            {
                return false;
            }

            //checks everything else
            bool l_equal = iv_parameters == i_rhs.iv_parameters;
            l_equal &= iv_addr_gen == i_rhs.iv_addr_gen;
            l_equal &= iv_test_type == i_rhs.iv_test_type;
            l_equal &= iv_poll == i_rhs.iv_poll;
            l_equal &= iv_addr_map0 == i_rhs.iv_addr_map0;
            l_equal &= iv_addr_map1 == i_rhs.iv_addr_map1;
            l_equal &= iv_addr_map2 == i_rhs.iv_addr_map2;
            l_equal &= iv_addr_map3 == i_rhs.iv_addr_map3;
            l_equal &= iv_config == i_rhs.iv_config;
            l_equal &= iv_control == i_rhs.iv_control;
            l_equal &= iv_async == i_rhs.iv_async;
            l_equal &= iv_pattern == i_rhs.iv_pattern;
            l_equal &= iv_thresholds == i_rhs.iv_thresholds;
            l_equal &= iv_data_rotate_cnfg == i_rhs.iv_data_rotate_cnfg;
            l_equal &= iv_data_rotate_seed == i_rhs.iv_data_rotate_seed;
            l_equal &= iv_random24_data_seed == i_rhs.iv_random24_data_seed;
            l_equal &= iv_random24_seed_map == i_rhs.iv_random24_seed_map;
            l_equal &= iv_data_rotate_cnfg == i_rhs.iv_data_rotate_cnfg;
            l_equal &= iv_data_rotate_seed == i_rhs.iv_data_rotate_seed;
            l_equal &= iv_compare_mask == i_rhs.iv_compare_mask;

            //returns result
            return  l_equal;
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
        // uint64_t                 iv_addr_map0;
        // uint64_t                 iv_addr_map1;
        // uint64_t                 iv_addr_map2;
        // uint64_t                 iv_addr_map3;
        //Perhaps this isn't the right approach, we can discuss and change if needed, leaving the above comments for now
        fapi2::buffer<uint64_t>     iv_addr_map0;
        fapi2::buffer<uint64_t>     iv_addr_map1;
        fapi2::buffer<uint64_t>     iv_addr_map2;
        fapi2::buffer<uint64_t>     iv_addr_map3;

        // Data Rotate Seed and Config Registers
        fapi2::buffer<uint64_t>     iv_data_rotate_cnfg;
        fapi2::buffer<uint64_t>     iv_data_rotate_seed;

        // Config register
        fapi2::buffer<uint64_t>     iv_config;

        // Control register
        fapi2::buffer<uint64_t>     iv_control;

        // True iff we want to run in asynchronous mode
        bool                        iv_async;

        // The pattern for the pattern generator
        uint64_t                    iv_pattern;

        // The pattern for the random 24b seeds
        uint64_t                    iv_random24_data_seed;

        // The pattern for the random 24b data seed mapping
        uint64_t                    iv_random24_seed_map;

        // The pattern for the pattern generator
        fapi2::buffer<uint64_t>     iv_compare_mask;

        // The error stop conditions, thresholds for the program
        stop_conditions             iv_thresholds;
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

    // Copy the program's config settings - we want to modify them if we're in sim.
    fapi2::buffer<uint64_t> l_config = i_program.iv_config;

    // If we're running in Cronus, there is no interrupt so any attention bits will
    // hang something somewhere. Make sure there's nothing in this config which can
    // turn on attention bits unless we're running in hostboot
#ifndef __HOSTBOOT_MODULE
    l_config.template clearBit<TT::CFG_ENABLE_HOST_ATTN>();
    l_config.template clearBit<TT::CFG_ENABLE_SPEC_ATTN>();
#endif

    FAPI_TRY( mss::putScom(i_target, TT::CFGQ_REG, l_config) );

fapi_try_exit:
    return fapi2::current_err;
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
/// @brief Resume the MCBIST engine
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff OK
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode resume( const fapi2::Target<T>& i_target )
{
    fapi2::buffer<uint64_t> l_buf;

    FAPI_TRY( mss::getScom(i_target, TT::CNTLQ_REG, l_buf) );
    FAPI_TRY( mss::putScom(i_target, TT::CNTLQ_REG, l_buf.setBit<TT::MCBIST_RESUME>()) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset the MCBIST error logs
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff OK
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode reset_errors( const fapi2::Target<T>& i_target )
{
    fapi2::buffer<uint64_t> l_buf;

    FAPI_TRY( mss::getScom(i_target, TT::CNTLQ_REG, l_buf) );
    FAPI_TRY( mss::putScom(i_target, TT::CNTLQ_REG, l_buf.setBit<TT::MCBIST_RESET_ERRORS>()) );

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
    FAPI_TRY( mss::putScom(i_target, TT::MCBAMR2A0Q_REG, i_program.iv_addr_map2) );

    FAPI_INF("load MCBIST address map register 3: 0x%016lx", i_program.iv_addr_map3);
    FAPI_TRY( mss::putScom(i_target, TT::MCBAMR3A0Q_REG, i_program.iv_addr_map3) );

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
/// @brief Clear mcbist errors
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target fapi2::Target<T> of the MCBIST
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode clear_errors( const fapi2::Target<T> i_target )
{
    // TK: Clear the more detailed errors checked above
    FAPI_INF("Clear MCBIST error state");
    FAPI_TRY( mss::putScom(i_target, TT::MCBSTATQ_REG, 0) );
    FAPI_TRY( mss::putScom(i_target, TT::SRERR0_REG, 0) );
    FAPI_TRY( mss::putScom(i_target, TT::SRERR1_REG, 0) );
    FAPI_TRY( mss::putScom(i_target, TT::FIRQ_REG, 0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Load MCBIST pattern given a pattern
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_pattern an mcbist::patterns
/// @param[in] i_invert whether to invert the pattern or not
/// @note this overload disappears when we have real patterns.
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode load_pattern( const fapi2::Target<T>& i_target, const pattern& i_pattern, const bool i_invert )
{
    uint64_t l_address = TT::PATTERN0_REG;

    // TODO RTC:155561 Add random pattern support.

    // TK: algorithm for patterns which include ECC bits in them
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
/// @param[in] i_index the pattern index
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode load_pattern( const fapi2::Target<T>& i_target, uint64_t i_pattern )
{
    if (NO_PATTERN != i_pattern)
    {
        bool l_invert = false;

        // Sanity check the pattern since they're just numbers.
        // Belt-and-suspenders FAPI_ASSERT as the sim-only uses this API directly.
        FAPI_ASSERT( i_pattern <= mcbist::LAST_PATTERN,
                     fapi2::MSS_MEMDIAGS_INVALID_PATTERN_INDEX().set_INDEX(i_pattern),
                     "Attempting to load a pattern which does not exist %d", i_pattern );

        // The indexes are split in to even and odd where the odd indexes don't really exist.
        // They're just indicating that we want to grab the even index and invert it. So calculate
        // the proper vector index and acknowledge the inversion if necessary.
        if (mss::is_odd(i_pattern))
        {
            l_invert = true;
            i_pattern -= 1;
        }

        return load_pattern(i_target, patterns[i_pattern / 2], l_invert);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Load MCBIST pattern given an index
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_program the mcbist::program
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode load_pattern( const fapi2::Target<T>& i_target, const mcbist::program<T>& i_program )
{
    return load_pattern(i_target, i_program.iv_pattern);
}

///
/// @brief Load MCBIST maint pattern given a pattern
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_pattern an mcbist::patterns
/// @param[in] i_invert whether to invert the pattern or not
/// @note this overload disappears when we have real patterns.
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
fapi2::ReturnCode load_maint_pattern( const fapi2::Target<T>& i_target, const pattern& i_pattern, const bool i_invert );


///
/// @brief Load MCBIST maint pattern given an index
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_index the pattern index
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode load_maint_pattern( const fapi2::Target<T>& i_target, uint64_t i_pattern )
{
    if (NO_PATTERN != i_pattern)
    {
        bool l_invert = false;

        // Sanity check the pattern since they're just numbers.
        // Belt-and-suspenders FAPI_ASSERT as the sim-only uses this API directly.
        FAPI_ASSERT( i_pattern <= mcbist::LAST_PATTERN,
                     fapi2::MSS_MEMDIAGS_INVALID_PATTERN_INDEX().set_INDEX(i_pattern),
                     "Attempting to load a pattern which does not exist %d", i_pattern );

        // The indexes are split in to even and odd where the odd indexes don't really exist.
        // They're just indicating that we want to grab the even index and invert it. So calculate
        // the proper vector index and acknowledge the inversion if necessary.
        if ((i_pattern % 2) != 0)
        {
            l_invert = true;
            i_pattern -= 1;
        }

        return load_maint_pattern(i_target, patterns[i_pattern / 2], l_invert);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Load MCBIST Maint mode pattern given an index
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_program the mcbist::program
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode load_maint_pattern( const fapi2::Target<T>& i_target, const mcbist::program<T>& i_program )
{
    return load_maint_pattern(i_target, i_program.iv_pattern);
}


///
/// @brief Load MCBIST 24b random data seeds given a pattern index
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_random24_data_seed mcbist::random24_data_seed
/// @param[in] i_random24_map mcbist::random24_seed_map
/// @param[in] i_invert whether to invert the pattern or not
/// @note this overload disappears when we have real patterns.
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
fapi2::ReturnCode load_random24b_seeds( const fapi2::Target<T>& i_target,
                                        const random24_data_seed& i_random24_data_seed,
                                        const random24_seed_map& i_random24_map,
                                        const bool i_invert );

///
/// @brief Load MCBIST 24b Random data seeds given a pattern index
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_data_seed the 24b random data seed index
/// @param[in] i_seed_map the 24b random data map index
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode load_random24b_seeds( const fapi2::Target<T>& i_target, uint64_t i_data_seed,
        uint64_t i_seed_map )
{
    if ((NO_RANDOM24_SEEDS != i_data_seed) && (NO_RANDOM24_SEED_MAP != i_seed_map))
    {
        bool l_invert = false;

        // TK Want a new RC for random 24
        // Sanity check the pattern since they're just numbers.
        // Belt-and-suspenders FAPI_ASSERT as the sim-only uses this API directly.
        FAPI_ASSERT( i_data_seed <= mcbist::LAST_RANDOM24_SEEDS,
                     fapi2::MSS_MEMDIAGS_INVALID_PATTERN_INDEX().set_INDEX(i_data_seed),
                     "Attempting to load a 24b random data seed set which does not exist %d", i_data_seed );

        // The indexes are split in to even and odd where the odd indexes don't really exist.
        // They're just indicating that we want to grab the even index and invert it. So calculate
        // the proper vector index and acknowledge the inversion if necessary.
        if ((i_data_seed % 2) != 0)
        {
            l_invert = true;
            i_data_seed -= 1;
        }

        return load_random24b_seeds(i_target, random24_data_seeds[i_data_seed / 2], random24_seed_maps[i_seed_map], l_invert);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Load MCBIST 24b Random data seeds given a program conatining a pattern index
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_program the mcbist::program
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode load_random24b_seeds( const fapi2::Target<T>& i_target, const mcbist::program<T>& i_program )
{
    return load_random24b_seeds(i_target, i_program.iv_random24_data_seed, i_program.iv_random24_seed_map);
}

///
/// @brief Loads the FIFO value if needed
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_program the mcbist::program
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode load_fifo_mode( const fapi2::Target<T>& i_target, const mcbist::program<T>& i_program )
{

    // Checks if FIFO mode is required by checking all subtests
    const auto l_subtest_it = std::find_if(i_program.iv_subtests.begin(),
                                           i_program.iv_subtests.end(), []( const mss::mcbist::subtest_t<T>& i_rhs) -> bool
    {
        return i_rhs.fifo_mode_required();
    });

    // if the FIFO load is not needed (no subtest requiring it was found), just exit out
    if(l_subtest_it == i_program.iv_subtests.end())
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Turns on FIFO mode
    constexpr mss::states FIFO_ON = mss::states::ON;

    FAPI_TRY(mss::configure_wrq(i_target, FIFO_ON));
    FAPI_TRY(mss::configure_rrq(i_target, FIFO_ON));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Load MCBIST data patterns and configuration
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_program the mcbist::program
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode load_data_config( const fapi2::Target<T>& i_target, const mcbist::program<T>& i_program )
{
    uint64_t l_data_rotate_cnfg_addr = TT::DATA_ROTATE_CNFG_REG;
    uint64_t l_data_rotate_seed_addr = TT::DATA_ROTATE_SEED_REG;

    // First load the data pattern registers
    FAPI_INF("Loading the data pattern seeds!");
    FAPI_TRY( mss::mcbist::load_pattern(i_target, i_program.iv_pattern) );

    // Load the 24b random data pattern seeds registers
    FAPI_INF("Loading the 24b Random data pattern seeds!");
    FAPI_TRY( mss::mcbist::load_random24b_seeds(i_target, i_program.iv_random24_data_seed,
              i_program.iv_random24_seed_map) );

    // Load the maint data pattern into the Maint entry in the RMW buffer
    // TK Might want to only load the RMW buffer if maint commands are present in the program
    // The load takes 33 Putscoms to load 16 64B registers, might slow down mcbist programs that
    // don't need the RMW buffer maint entry loaded
    FAPI_INF("Loading the maint data pattern into the RMW buffer!");
    FAPI_TRY( mss::mcbist::load_maint_pattern(i_target, i_program.iv_pattern) );

    FAPI_INF("Loading the data rotate config and seeds!");
    FAPI_TRY( mss::putScom(i_target, l_data_rotate_cnfg_addr, i_program.iv_data_rotate_cnfg) );
    FAPI_TRY( mss::putScom(i_target, l_data_rotate_seed_addr, i_program.iv_data_rotate_seed) );

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Load MCBIST data compare mask registers
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_program the mcbist::program
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
fapi2::ReturnCode load_data_compare_mask( const fapi2::Target<T>& i_target,
        const mcbist::program<T>& i_program );

///
/// @brief Load MCBIST Thresholds
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

///
/// @brief Load MCBIST Threshold Register
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_program the program containing the thresholds
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode load_thresholds( const fapi2::Target<T>& i_target, const mcbist::program<T>& i_program )
{
    return load_thresholds(i_target, i_program.iv_thresholds);
}

///
/// @brief Read entries from MCBIST Read Modify Write (RMW) array
/// @tparam T, the fapi2::TargetType
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_start_addr the array address to read first
/// @param[in] i_num_entries the number of array entries to read
/// @param[in] i_roll_over_for_compare_mode set to true if only using first
/// NUM_COMPARE_INFO_ENTRIES of array, so array address rolls over at correct value
/// @param[out] o_data vector of output data
/// @param[out] o_ecc_data vector of ecc data
/// @return FAPI2_RC_SUCCSS iff ok
/// @note The number of entries in the array depends on i_roll_over_for_compare_mode parameter:
/// (NUM_COMPARE_LOG_ENTRIES for false, NUM_COMPARE_INFO_ENTRIES for true) but user may read more than
/// that since reads work in a circular buffer fashion
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
fapi2::ReturnCode read_rmw_array(const fapi2::Target<T>& i_target,
                                 const uint64_t i_start_addr,
                                 const uint64_t i_num_entries,
                                 const bool i_roll_over_for_compare_mode,
                                 std::vector< fapi2::buffer<uint64_t> >& o_data,
                                 std::vector< fapi2::buffer<uint64_t> >& o_ecc_data);

///
/// @brief Read entries from MCBIST Read Modify Write (RMW) array
/// Overload for the case where o_ecc_data is not needed
/// @tparam T, the fapi2::TargetType
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_start_addr the array address to read first
/// @param[in] i_num_entries the number of array entries to read
/// @param[in] i_roll_over_for_compare_mode set to true if only using first
/// NUM_COMPARE_INFO_ENTRIES of array, so array address rolls over at correct value
/// @param[out] o_data vector of output data
/// @return FAPI2_RC_SUCCSS iff ok
/// @note The number of entries in the array depends on i_roll_over_for_compare_mode parameter:
/// (NUM_COMPARE_LOG_ENTRIES for false, NUM_COMPARE_INFO_ENTRIES for true) but user may read more than
/// that since reads work in a circular buffer fashion
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
inline fapi2::ReturnCode read_rmw_array(const fapi2::Target<T>& i_target,
                                        const uint64_t i_start_addr,
                                        const uint64_t i_num_entries,
                                        const bool i_roll_over_for_compare_mode,
                                        std::vector< fapi2::buffer<uint64_t> >& o_data)
{
    std::vector< fapi2::buffer<uint64_t> > l_temp;
    return read_rmw_array(i_target, i_start_addr, i_num_entries, i_roll_over_for_compare_mode, o_data, l_temp);
}

///
/// @brief Read entries from MCBIST Read Buffer (RB) array
/// @tparam T, the fapi2::TargetType
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_start_addr the array address to read first
/// @param[in] i_num_entries the number of array entries to read
/// @param[out] o_data vector of output data
/// @param[out] o_ecc_data vector of ecc data
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
fapi2::ReturnCode read_rb_array(const fapi2::Target<T>& i_target,
                                const uint64_t i_start_addr,
                                const uint64_t i_num_entries,
                                std::vector< fapi2::buffer<uint64_t> >& o_data,
                                std::vector< fapi2::buffer<uint64_t> >& o_ecc_data);

///
/// @brief Read entries from MCBIST Read Buffer (RB) array
/// Overload for the case where o_ecc_data is not needed
/// @tparam T, the fapi2::TargetType
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_start_addr the array address to read first
/// @param[in] i_num_entries the number of array entries to read
/// @param[out] o_data vector of output data
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
fapi2::ReturnCode read_rb_array(const fapi2::Target<T>& i_target,
                                const uint64_t i_start_addr,
                                const uint64_t i_num_entries,
                                std::vector< fapi2::buffer<uint64_t> >& o_data)
{
    std::vector< fapi2::buffer<uint64_t> > l_temp;
    return read_rb_array(i_target, i_start_addr, i_num_entries, o_data, l_temp);
}

///
/// @brief Checks if broadcast mode is capable of being enabled on this target
/// @param[in] i_target the target to effect
/// @param[in] i_bc_force attribute's value to force off broadcast mode
/// @param[in] i_bc_enable attribute's value to enable or disable broadcast mode
/// @param[in] i_chip_bc_capable true if the chip is BC capable
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
const mss::states is_broadcast_capable_helper(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
        const uint8_t i_bc_force,
        const uint8_t i_bc_enable,
        const bool i_chip_bc_capable);

///
/// @brief Checks if broadcast mode is capable of being enabled on this target
/// @tparam T, the fapi2::TargetType
/// @param[in] i_target the target to effect
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
template< fapi2::TargetType T >
const mss::states is_broadcast_capable(const fapi2::Target<T>& i_target);

///
/// @brief Checks if broadcast mode is capable of being enabled on this vector of targets
/// @tparam T, the fapi2::TargetType
/// @param[in] i_targets the vector of targets to analyze
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
template< fapi2::TargetType T >
const mss::states is_broadcast_capable(const std::vector<fapi2::Target<T>>& i_targets);

///
/// @brief Checks if broadcast mode is capable of being enabled on this vector of targets
/// @param[in] i_target the target to effect
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
const mss::states is_broadcast_capable(const std::vector<mss::dimm::kind>& i_kinds);

///
/// @brief Configures all of the ports for broadcast mode
/// @tparam T, the fapi2::TargetType
/// @param[in] i_target the target to effect
/// @param[out] o_port_select - the configuration of the selected ports
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode setup_broadcast_port_select(const fapi2::Target<T>& i_target, uint64_t& o_port_select);

///
/// @brief Checks if broadcast mode is capable based upon the timings
/// @param[in] i_targets the targets to effect
/// @param[out] o_broadcast_capable YES if BC capable, otherwise NO
/// @return FAPI2_RC_SUCCSS iff ok
/// @note all timing attributes must be equal for broadcast to be capable
///
fapi2::ReturnCode is_broadcast_capable_timings(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCA>>& i_targets,
        mss::states& o_broadcast_capable);

///
/// @brief Enables broadcast mode
/// @tparam T, the fapi2::TargetType
/// @param[in] i_target the target to effect
/// @param[in,out] io_program the mcbist::program
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode enable_broadcast_mode(const fapi2::Target<T>& i_target, mcbist::program<T>& io_program);

///
/// @brief Configures broadcast mode, if it is needed
/// @tparam T, the fapi2::TargetType
/// @param[in] i_target the target to effect
/// @param[in,out] io_program the mcbist::program
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode configure_broadcast_mode(const fapi2::Target<T>& i_target, mcbist::program<T>& io_program)
{
    // If we're not capable to do broadcast mode on this target, exit out
    const auto l_broadcast_capable = is_broadcast_capable(i_target);

    if(l_broadcast_capable == mss::states::NO)
    {
        FAPI_INF("%s is not broadcast capable, skipping enablement of broadcast mode", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Enable broadcast mode
    FAPI_INF("%s is broadcast capable, enabling broadcast mode", mss::c_str(i_target));
    return enable_broadcast_mode(i_target, io_program);
}

} // namespace

} // namespace

#endif
