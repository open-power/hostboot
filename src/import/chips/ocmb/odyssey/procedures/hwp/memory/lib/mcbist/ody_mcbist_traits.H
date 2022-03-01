/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/mcbist/ody_mcbist_traits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file ody_mcbist_traits.H
/// @brief Odyssey's MCBIST traits
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_ODY_MCBIST_TRAITS_H_
#define _MSS_ODY_MCBIST_TRAITS_H_

#include <fapi2.H>

#include <ody_scom_ody_odc.H>

#include <lib/shared/ody_consts.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_address.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist.H>

namespace mss
{

///
/// @class mcbistMCTraits
/// @brief A MC to MC_TARGET_TYPE mapping specialization for ODYSSEY
///
template<>
class mcbistMCTraits< mss::mc_type::ODYSSEY>
{
    public:
        static constexpr fapi2::TargetType MC_TARGET_TYPE = fapi2::TARGET_TYPE_OCMB_CHIP;
        static constexpr fapi2::TargetType FWMS_ADDR_TARGET_TYPE = fapi2::TARGET_TYPE_MEM_PORT;

        ///
        /// @brief Returns an error for memdiags compare error in last pattern
        /// @return memdiags error
        ///
        static fapi2::ODY_MEMDIAGS_COMPARE_ERROR_IN_LAST_PATTERN memdiags_compare_error_in_last_pattern()
        {
            return fapi2::ODY_MEMDIAGS_COMPARE_ERROR_IN_LAST_PATTERN();
        }

        ///
        /// @brief Returns an error for memdiags error in last pattern
        /// @return memdiags error
        ///
        static fapi2::ODY_MEMDIAGS_ERROR_IN_LAST_PATTERN memdiags_error_in_last_pattern()
        {
            return fapi2::ODY_MEMDIAGS_ERROR_IN_LAST_PATTERN();
        }

        ///
        /// @brief Returns an error if memdiags failed to start
        /// @return memdiags error
        ///
        static fapi2::ODY_MEMDIAGS_MCBIST_FAILED_TO_START memdiags_failed_to_start()
        {
            return fapi2::ODY_MEMDIAGS_MCBIST_FAILED_TO_START();
        }

        ///
        /// @brief Returns an error if memdiags failed to stop
        /// @return memdiags error
        ///
        static fapi2::ODY_MEMDIAGS_MCBIST_FAILED_TO_STOP memdiags_failed_to_stop()
        {
            return fapi2::ODY_MEMDIAGS_MCBIST_FAILED_TO_STOP();
        }

        ///
        /// @brief Returns an error if memdiags has a non-functional port
        /// @return memdiags error
        ///
        static fapi2::ODY_MEMDIAGS_PORT_NOT_FUNCTIONAL memdiags_port_not_functional()
        {
            return fapi2::ODY_MEMDIAGS_PORT_NOT_FUNCTIONAL();
        }

        ///
        /// @brief Returns an error if memdiags super fast init failed to init
        /// @return memdiags error
        ///
        static fapi2::ODY_MEMDIAGS_SUPERFAST_INIT_FAILED_TO_INIT memdiags_sf_init_failed_init()
        {
            return fapi2::ODY_MEMDIAGS_SUPERFAST_INIT_FAILED_TO_INIT();
        }

        ///
        /// @brief Returns an error if memdiags super fast read failed to init
        /// @return memdiags error
        ///
        static fapi2::ODY_MEMDIAGS_SUPERFAST_READ_FAILED_TO_INIT memdiags_sf_read_failed_init()
        {
            return fapi2::ODY_MEMDIAGS_SUPERFAST_READ_FAILED_TO_INIT();
        }

        ///
        /// @brief Returns an error if memdiags super fast read failed to init
        /// @return memdiags error
        ///
        static fapi2::ODY_MEMDIAGS_CONTINUOUS_SCRUB_FAILED_TO_INIT memdiags_continuous_scrub_failed_init()
        {
            return fapi2::ODY_MEMDIAGS_CONTINUOUS_SCRUB_FAILED_TO_INIT();
        }

        ///
        /// @brief Returns an error if memdiags targeted scrub failed to init
        /// @return memdiags error
        ///
        static fapi2::ODY_MEMDIAGS_TARGETED_SCRUB_FAILED_TO_INIT memdiags_targeted_scrub_failed_init()
        {
            return fapi2::ODY_MEMDIAGS_TARGETED_SCRUB_FAILED_TO_INIT();
        }

        ///
        /// @brief Returns an error if memdiags is already at a boundary
        /// @return memdiags error
        ///
        static fapi2::ODY_MEMDIAGS_ALREADY_AT_BOUNDARY memdiags_already_at_boundary()
        {
            return fapi2::ODY_MEMDIAGS_ALREADY_AT_BOUNDARY();
        }

        ///
        /// @brief Returns an error if MCBIST timesout
        /// @return MCBIST error
        ///
        static fapi2::ODY_MCBIST_TIMEOUT mcbist_timeout()
        {
            return fapi2::ODY_MCBIST_TIMEOUT();
        }

        ///
        /// @brief Returns an error if MCBIST has an unknown failure
        /// @return MCBIST error
        ///
        static fapi2::ODY_MCBIST_UNKNOWN_FAILURE mcbist_unknown_failure()
        {
            return fapi2::ODY_MCBIST_UNKNOWN_FAILURE();
        }

        ///
        /// @brief Returns an error if MCBIST has a data miscompare
        /// @return MCBIST error
        ///
        static fapi2::ODY_MCBIST_DATA_FAIL mcbist_data_fail()
        {
            return fapi2::ODY_MCBIST_DATA_FAIL();
        }
};

///
/// @class mcbistTraits
/// @brief a collection of traits associated with the Explorer MCBIST engine or hardware
///
template<>
class mcbistTraits< mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>
{
    public:

        // PORT_TYPE used in continuous_scrub_operation
        static constexpr fapi2::TargetType PORT_TYPE = fapi2::TARGET_TYPE_MEM_PORT;

        // ATTN support
        static constexpr mss::states BROADCAST_CAPABLE = mss::states::NO;

        // Multi-ports, dimms
        static constexpr mss::states MULTI_PORTS = mss::states::NO;

        // Subtest
        static constexpr size_t SUBTEST_PER_REG = 4;
        static constexpr size_t SUBTEST_PER_PROGRAM = 32;
        static constexpr size_t BITS_IN_SUBTEST = 16; // 2 Bytes
        static constexpr size_t LEFT_SHIFT = (sizeof(uint64_t) * 8) - BITS_IN_SUBTEST;

        // LARGEST_ADDRESS. port select (bit0~1) are always 0 so shift 2 more bits.
        static constexpr uint64_t LARGEST_ADDRESS = ~0 >> (mss::mcbist::address::MAGIC_PAD + 2);

        // Length of expected patterns
        // TODO:ZEN-MST1396 Update Odyssey MCBIST fixed data and patten size
        static constexpr uint64_t EXPECTED_PATTERN_SIZE = 4;

        // Size
        static constexpr size_t PORTS_PER_MCBIST = mss::ody::MAX_PORT_PER_OCMB;
        static constexpr size_t MAX_DIMM_PER_PORT = mss::ody::HW_MAX_DIMM_PER_PORT;
        static constexpr size_t MAX_PRIMARY_RANKS_PER_PORT = mss::ody::HW_MAX_RANK_PER_DIMM;
        static constexpr size_t MAX_DQ_BITS = mss::ody::MAX_DQ_BITS_PER_PORT;
        static constexpr size_t MAX_DQ_NIBBLES = MAX_DQ_BITS / BITS_PER_NIBBLE;
        static constexpr size_t MAX_DRAMS_X8 = MAX_DQ_BITS / BITS_PER_BYTE;
        static constexpr size_t MAX_DRAMS_X4 = MAX_DQ_BITS / BITS_PER_NIBBLE;

        /// MCBIST "memory registers" - config for subtests.
        static constexpr uint64_t MCBMR0_REG = scomt::ody::ODC_MCBIST_SCOM_MCBMR0Q;
        static constexpr uint64_t MCBMR1_REG = scomt::ody::ODC_MCBIST_SCOM_MCBMR1Q;
        static constexpr uint64_t MCBMR2_REG = scomt::ody::ODC_MCBIST_SCOM_MCBMR2Q;
        static constexpr uint64_t MCBMR3_REG = scomt::ody::ODC_MCBIST_SCOM_MCBMR3Q;
        static constexpr uint64_t MCBMR4_REG = scomt::ody::ODC_MCBIST_SCOM_MCBMR4Q;
        static constexpr uint64_t MCBMR5_REG = scomt::ody::ODC_MCBIST_SCOM_MCBMR5Q;
        static constexpr uint64_t MCBMR6_REG = scomt::ody::ODC_MCBIST_SCOM_MCBMR6Q;
        static constexpr uint64_t MCBMR7_REG = scomt::ody::ODC_MCBIST_SCOM_MCBMR7Q;
        static constexpr uint64_t CFGQ_REG = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ;
        static constexpr uint64_t CNTLQ_REG = scomt::ody::ODC_MCBIST_SCOM_MCB_CNTLQ;
        static constexpr uint64_t STATQ_REG = scomt::ody::ODC_MCBIST_SCOM_MCB_CNTLSTATQ;
        static constexpr uint64_t MCBSTATQ_REG = scomt::ody::ODC_MCBIST_SCOM_MCBSTATQ;
        static constexpr uint64_t MCBPARMQ_REG = scomt::ody::ODC_MCBIST_SCOM_MCBPARMQ;
        static constexpr uint64_t MCBAGRAQ_REG = scomt::ody::ODC_MCBIST_SCOM_MCBAGRAQ;
        static constexpr uint64_t SRERR0_REG = scomt::ody::ODC_MCBIST_SCOM_MBSEC0Q;
        static constexpr uint64_t SRERR1_REG = scomt::ody::ODC_MCBIST_SCOM_MBSEC1Q;
        static constexpr uint64_t THRESHOLD_REG = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ;
        static constexpr uint64_t FIRQ_REG = scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_RW_WCLEAR;
        static constexpr uint64_t FIRQ_MASK_SET = scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRMASK_WO_OR;
        static constexpr uint64_t FIRQ_MASK_CLEAR = scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRMASK_RW_WCLEAR;
        static constexpr uint64_t LAST_ADDR_REG = scomt::ody::ODC_MCBIST_SCOM_MCBMCATQ;

        static constexpr uint64_t MCBAMR0A0Q_REG = scomt::ody::ODC_MCBIST_SCOM_MCBAMR0A0Q;
        static constexpr uint64_t MCBAMR1A0Q_REG = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q;
        static constexpr uint64_t MCBAMR2A0Q_REG = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q;
        static constexpr uint64_t MCBAMR3A0Q_REG = scomt::ody::ODC_MCBIST_SCOM_MCBAMR3A0Q;
        static constexpr uint64_t LFSR_REG = scomt::ody::ODC_MCBIST_SCOM_MCBLFSRA0Q;
        static const std::vector<uint64_t> LFSR_MASK_VALUES;

        // TODO:ZEN-MST1396 Update Odyssey MCBIST fixed data and patten size
        // All of the pattern registers are calculated off of this base
        static constexpr uint64_t PATTERN0_REG = scomt::ody::ODC_MCBIST_SCOM_MCBFD0Q;
        static constexpr uint64_t PATTERN1_REG = scomt::ody::ODC_MCBIST_SCOM_MCBFD1Q;
        static constexpr uint64_t PATTERN2_REG = scomt::ody::ODC_MCBIST_SCOM_MCBFD2Q;
        static constexpr uint64_t PATTERN3_REG = scomt::ody::ODC_MCBIST_SCOM_MCBFD3Q;
        static constexpr uint64_t PATTERN4_REG = scomt::ody::ODC_MCBIST_SCOM_MCBFD4Q;
        static constexpr uint64_t PATTERN5_REG = scomt::ody::ODC_MCBIST_SCOM_MCBFD5Q;
        static constexpr uint64_t PATTERN6_REG = scomt::ody::ODC_MCBIST_SCOM_MCBFD6Q;
        static constexpr uint64_t PATTERN7_REG = scomt::ody::ODC_MCBIST_SCOM_MCBFD7Q;

        static constexpr uint64_t DATA_ROTATE_CNFG_REG = scomt::ody::ODC_MCBIST_SCOM_MCBDRCRQ;
        static constexpr uint64_t DATA_ROTATE_SEED_REG = scomt::ody::ODC_MCBIST_SCOM_MCBDRSRQ;

        static constexpr uint16_t MAX_ADDRESS_START_END_REGISTERS = 4;
        static constexpr uint64_t START_ADDRESS_0 = scomt::ody::ODC_MCBIST_SCOM_MCBSA0Q;
        static constexpr uint64_t START_ADDRESS_1 = scomt::ody::ODC_MCBIST_SCOM_MCBSA1Q;
        static constexpr uint64_t START_ADDRESS_2 = scomt::ody::ODC_MCBIST_SCOM_MCBSA2Q;
        static constexpr uint64_t START_ADDRESS_3 = scomt::ody::ODC_MCBIST_SCOM_MCBSA3Q;

        static constexpr uint64_t END_ADDRESS_0 = scomt::ody::ODC_MCBIST_SCOM_MCBEA0Q;
        static constexpr uint64_t END_ADDRESS_1 = scomt::ody::ODC_MCBIST_SCOM_MCBEA1Q;
        static constexpr uint64_t END_ADDRESS_2 = scomt::ody::ODC_MCBIST_SCOM_MCBEA2Q;
        static constexpr uint64_t END_ADDRESS_3 = scomt::ody::ODC_MCBIST_SCOM_MCBEA3Q;

        static constexpr uint64_t RANDOM_DATA_SEED0 = scomt::ody::ODC_MCBIST_SCOM_MCBRDS0Q;
        static constexpr uint64_t RANDOM_DATA_SEED1 = scomt::ody::ODC_MCBIST_SCOM_MCBRDS1Q;

        static constexpr uint64_t  MBSTRQ_CFG_PAUSE_ON_MPE = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_PAUSE_ON_MPE;

        // MCBIST Compare Masks, used to setup the ECC traps
        static constexpr uint64_t COMPARE_MASK = scomt::ody::ODC_RDF0_SCOM_MCBCM;

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
            MCB_ADDR_CONFIG = scomt::ody::ODC_MCBIST_SCOM_MCBEA0Q_MCBEA0Q_CFG_END_ADDR_0,
            MCB_ADDR_CONFIG_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBEA0Q_MCBEA0Q_CFG_END_ADDR_0_LEN,

            // Subtest control bits. These are the same in all '16 bit subtest' field
            COMPL_1ST_CMD = scomt::ody::ODC_MCBIST_SCOM_MCBMR0Q_0_COMPL_1ST_CMD,
            COMPL_2ND_CMD = scomt::ody::ODC_MCBIST_SCOM_MCBMR0Q_0_COMPL_2ND_CMD,
            COMPL_3RD_CMD = scomt::ody::ODC_MCBIST_SCOM_MCBMR0Q_0_COMPL_3RD_CMD,
            ADDR_REV_MODE = scomt::ody::ODC_MCBIST_SCOM_MCBMR0Q_0_ADDR_REV_MODE,
            ADDR_RAND_MODE = scomt::ody::ODC_MCBIST_SCOM_MCBMR0Q_0_ADDR_RAND_MODE,

            // Goto subtests use the compl_1st - rand_mode to define the subtest to jump to
            GOTO_SUBTEST = scomt::ody::ODC_MCBIST_SCOM_MCBMR0Q_0_COMPL_1ST_CMD,
            GOTO_SUBTEST_LEN = 5,

            // Refresh Only bitcode - No global enums
            REFRESH_ONLY = 0b001,

            ECC_MODE = scomt::ody::ODC_MCBIST_SCOM_MCBMR0Q_0_ECC_MODE,
            DATA_MODE = scomt::ody::ODC_MCBIST_SCOM_MCBMR0Q_0_DATA_MODE,
            DATA_MODE_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBMR0Q_0_DATA_MODE_LEN,
            ADDR_SEL = scomt::ody::ODC_MCBIST_SCOM_MCBMR0Q_0_ADDR_SEL,
            ADDR_SEL_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBMR0Q_0_ADDR_SEL_LEN,
            OP_TYPE = scomt::ody::ODC_MCBIST_SCOM_MCBMR0Q_0_OP_TYPE,
            OP_TYPE_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBMR0Q_0_OP_TYPE_LEN,
            DONE = scomt::ody::ODC_MCBIST_SCOM_MCBMR0Q_0_DONE,

            // No broadcast in Odyssey due to port interleavings in the MCBIST engine
            // SYNC_EN
            // SYNC_WAIT
            // SYNC_WAIT_LEN

            // Unused bits due to ports being selected as addressing bits
            // Note: disabled as MULTI_PORTS is NO
            // No port sel in Odyssey due to only one port per MCBIST
            PORT_SEL = 0,
            PORT_SEL_LEN = 1,

            MCBIST_START = scomt::ody::ODC_MCBIST_SCOM_MCB_CNTLQ_MCB_START,
            MCBIST_STOP = scomt::ody::ODC_MCBIST_SCOM_MCB_CNTLQ_MCB_STOP,
            MCBIST_RESUME = scomt::ody::ODC_MCBIST_SCOM_MCB_CNTLQ_MCB_RESUME_FROM_PAUSE,
            MCBIST_RESET_ERRORS = scomt::ody::ODC_MCBIST_SCOM_MCB_CNTLQ_MCB_RESET_ERROR_LOGS,

            MCBIST_IN_PROGRESS = scomt::ody::ODC_MCBIST_SCOM_MCB_CNTLSTATQ_IP,
            MCBIST_DONE = scomt::ody::ODC_MCBIST_SCOM_MCB_CNTLSTATQ_DONE,
            MCBIST_FAIL = scomt::ody::ODC_MCBIST_SCOM_MCB_CNTLSTATQ_FAIL,

            MIN_CMD_GAP = scomt::ody::ODC_MCBIST_SCOM_MCBPARMQ_CFG_MIN_CMD_GAP,
            MIN_CMD_GAP_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBPARMQ_CFG_MIN_CMD_GAP_LEN,
            MIN_GAP_TIMEBASE = scomt::ody::ODC_MCBIST_SCOM_MCBPARMQ_CFG_MIN_GAP_TIMEBASE,
            MIN_CMD_GAP_BLIND_STEER = scomt::ody::ODC_MCBIST_SCOM_MCBPARMQ_CFG_MIN_CMD_GAP_BLIND_STEER,
            MIN_CMD_GAP_BLIND_STEER_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBPARMQ_CFG_MIN_CMD_GAP_BLIND_STEER_LEN,
            MIN_GAP_TIMEBASE_BLIND_STEER = scomt::ody::ODC_MCBIST_SCOM_MCBPARMQ_CFG_MIN_GAP_TIMEBASE_BLIND_STEER,
            RANDCMD_WGT = scomt::ody::ODC_MCBIST_SCOM_MCBPARMQ_CFG_RANDCMD_WGT,
            RANDCMD_WGT_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBPARMQ_CFG_RANDCMD_WGT_LEN,
            // No clock monitor for explorer
            // CLOCK_MONITOR_EN
            EN_RANDCMD_GAP = scomt::ody::ODC_MCBIST_SCOM_MCBPARMQ_CFG_EN_RANDCMD_GAP,
            RANDGAP_WGT = scomt::ody::ODC_MCBIST_SCOM_MCBPARMQ_CFG_RANDGAP_WGT,
            RANDGAP_WGT_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBPARMQ_CFG_RANDGAP_WGT_LEN,
            BC4_EN = scomt::ody::ODC_MCBIST_SCOM_MCBPARMQ_CFG_BC4_EN,

            FIXED_WIDTH = scomt::ody::ODC_MCBIST_SCOM_MCBAGRAQ_CFG_FIXED_WIDTH,
            FIXED_WIDTH_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAGRAQ_CFG_FIXED_WIDTH_LEN,
            ADDR_COUNTER_MODE = scomt::ody::ODC_MCBIST_SCOM_MCBAGRAQ_CFG_ADDR_COUNTER_MODE,
            ADDR_COUNTER_MODE_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAGRAQ_CFG_ADDR_COUNTER_MODE_LEN,
            MAINT_ADDR_MODE_EN = scomt::ody::ODC_MCBIST_SCOM_MCBAGRAQ_CFG_MAINT_ADDR_MODE_EN,

            // No broadcast in explorer due to only one port per MCBIST
            //MAINT_BROADCAST_MODE_EN
            MAINT_DETECT_SRANK_BOUNDARIES = scomt::ody::ODC_MCBIST_SCOM_MCBAGRAQ_CFG_MAINT_DETECT_SRANK_BOUNDARIES,

            CFG_CMD_TIMEOUT_MODE = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_CFGQ_CFG_CMD_TIMEOUT_MODE,
            CFG_CMD_TIMEOUT_MODE_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_CFGQ_CFG_CMD_TIMEOUT_MODE_LEN,
            CFG_CURRENT_ADDR_TRAP_UPDATE_DIS = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_CFGQ_CFG_CURRENT_ADDR_TRAP_UPDATE_DIS,
            CFG_CCS_RETRY_DIS = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_CFGQ_CFG_CCS_RETRY_DIS,
            CFG_RESET_CNTS_START_OF_RANK = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_CFGQ_CFG_RESET_CNTS_START_OF_RANK,
            CFG_LOG_COUNTS_IN_TRACE = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_CFGQ_CFG_LOG_COUNTS_IN_TRACE,
            SKIP_INVALID_ADDR_DIMM_DIS = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_CFGQ_SKIP_INVALID_ADDR_DIMM_DIS,
            REFRESH_ONLY_SUBTEST_EN = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_CFGQ_REFRESH_ONLY_SUBTEST_EN,
            REFRESH_ONLY_SUBTEST_TIMEBASE_SEL = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_CFGQ_REFRESH_ONLY_SUBTEST_TIMEBASE_SEL,
            REFRESH_ONLY_SUBTEST_TIMEBASE_SEL_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_CFGQ_REFRESH_ONLY_SUBTEST_TIMEBASE_SEL_LEN,
            RAND_ADDR_ALL_ADDR_MODE_EN = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_CFGQ_RAND_ADDR_ALL_MODE_EN,
            MCBIST_CFG_REF_WAIT_TIME = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_IST_CFG_REF_WAIT_TIME,
            MCBIST_CFG_REF_WAIT_TIME_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_IST_CFG_REF_WAIT_TIME_LEN,
            CFG_MCB_LEN64 = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_CFGQ_CFG_MCB_LEN64,
            CFG_PAUSE_ON_ERROR_MODE = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_CFGQ_CFG_PAUSE_ON_ERROR_MODE,
            CFG_PAUSE_ON_ERROR_MODE_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_CFGQ_CFG_PAUSE_ON_ERROR_MODE_LEN,
            MCBIST_CFG_PAUSE_AFTER_CCS_SUBTEST = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_IST_CFG_PAUSE_AFTER_CCS_SUBTEST,
            MCBIST_CFG_FORCE_PAUSE_AFTER_ADDR = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_IST_CFG_FORCE_PAUSE_AFTER_ADDR,
            MCBIST_CFG_FORCE_PAUSE_AFTER_SUBTEST = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_IST_CFG_FORCE_PAUSE_AFTER_SUBTEST,

            MCBIST_CFG_PAUSE_AFTER_RANK = scomt::ody::ODC_MCBIST_SCOM_MCBCFGQ_IST_CFG_FORCE_PAUSE_AFTER_RANK,

            LOGGED_ERROR_ON_PORT_INDICATOR = scomt::ody::ODC_MCBIST_SCOM_MCBSTATQ_MCBIST_LOGGED_ERROR_ON_PORT_INDICATOR,
            LOGGED_ERROR_ON_PORT_INDICATOR_LEN = 1,
            SUBTEST_NUM_INDICATOR = scomt::ody::ODC_MCBIST_SCOM_MCBSTATQ_MCBIST_SUBTEST_NUM_INDICATOR,
            SUBTEST_NUM_INDICATOR_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBSTATQ_MCBIST_SUBTEST_NUM_INDICATOR_LEN,

            UE_COUNT = scomt::ody::ODC_MCBIST_SCOM_MBSEC1Q_UE_COUNT,
            UE_COUNT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSEC1Q_UE_COUNT_LEN,

            MBSTRQ_CFG_MAINT_RCE_WITH_CE = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_MAINT_RCE_WITH_CE,

            // TODO:ZEN-MST1395 Add Odyssey MCBIST address mapping traits
            CFG_AMAP_DIMM_SELECT = 0, // appears to be DNE
            CFG_AMAP_DIMM_SELECT_LEN = 0, // appears to be DNE
            CFG_AMAP_MRANK0 = 0,
            CFG_AMAP_MRANK0_LEN = 6,
            CFG_AMAP_SRANK0 = 0,
            CFG_AMAP_SRANK0_LEN = 6,
            CFG_AMAP_SRANK1 = 0,
            CFG_AMAP_SRANK1_LEN = 6,
            CFG_AMAP_SRANK2 = 0,
            CFG_AMAP_SRANK2_LEN = 6,
            CFG_AMAP_BANK2 = 0,
            CFG_AMAP_BANK2_LEN = 6 ,
            CFG_AMAP_BANK1 = 0,
            CFG_AMAP_BANK1_LEN = 6 ,
            CFG_AMAP_BANK0 = 0,
            CFG_AMAP_BANK0_LEN = 6 ,

            CFG_AMAP_BANK_GROUP1 = 0,
            CFG_AMAP_BANK_GROUP1_LEN = 6 ,
            CFG_AMAP_BANK_GROUP0 = 0,
            CFG_AMAP_BANK_GROUP0_LEN = 6 ,
            CFG_AMAP_ROW17 = 0,
            CFG_AMAP_ROW17_LEN = 6,
            CFG_AMAP_ROW16 = 0,
            CFG_AMAP_ROW16_LEN = 6,
            CFG_AMAP_ROW15 = 0,
            CFG_AMAP_ROW15_LEN = 6,
            CFG_AMAP_ROW14 = 0,
            CFG_AMAP_ROW14_LEN = 6,
            CFG_AMAP_ROW13 = 0,
            CFG_AMAP_ROW13_LEN = 6,
            CFG_AMAP_ROW12 = 0,
            CFG_AMAP_ROW12_LEN = 6,
            CFG_AMAP_ROW11 = 0,
            CFG_AMAP_ROW11_LEN = 6,
            CFG_AMAP_ROW10 = 0,
            CFG_AMAP_ROW10_LEN = 6,

            CFG_AMAP_ROW9 = 0,
            CFG_AMAP_ROW9_LEN = 6,
            CFG_AMAP_ROW8 = 0,
            CFG_AMAP_ROW8_LEN = 6,
            CFG_AMAP_ROW7 = 0,
            CFG_AMAP_ROW7_LEN = 6,
            CFG_AMAP_ROW6 = 0,
            CFG_AMAP_ROW6_LEN = 6,
            CFG_AMAP_ROW5 = 0,
            CFG_AMAP_ROW5_LEN = 6,
            CFG_AMAP_ROW4 = 0,
            CFG_AMAP_ROW4_LEN = 6,
            CFG_AMAP_ROW3 = 0,
            CFG_AMAP_ROW3_LEN = 6,
            CFG_AMAP_ROW2 = 0,
            CFG_AMAP_ROW2_LEN = 6,
            CFG_AMAP_ROW1 = 0,
            CFG_AMAP_ROW1_LEN = 6,
            CFG_AMAP_ROW0 = 0,
            CFG_AMAP_ROW0_LEN = 6,

            CFG_AMAP_COL9 = 0,
            CFG_AMAP_COL9_LEN = 6,
            CFG_AMAP_COL8 = 0,
            CFG_AMAP_COL8_LEN = 6,
            CFG_AMAP_COL7 = 0,
            CFG_AMAP_COL7_LEN = 6,
            CFG_AMAP_COL6 = 0,
            CFG_AMAP_COL6_LEN = 6,
            CFG_AMAP_COL5 = 0,
            CFG_AMAP_COL5_LEN = 6,
            CFG_AMAP_COL4 = 0,
            CFG_AMAP_COL4_LEN = 6,
            CFG_AMAP_COL3 = 0,
            CFG_AMAP_COL3_LEN = 6,
            CFG_AMAP_COL2 = 0,
            CFG_AMAP_COL2_LEN = 6,
#if 0
            CFG_AMAP_DIMM_SELECT = 0, // appears to be DNE
            CFG_AMAP_DIMM_SELECT_LEN = 0, // appears to be DNE
            CFG_AMAP_MRANK0 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR0A0Q_CFG_AMAP_MRANK,
            CFG_AMAP_MRANK0_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR0A0Q_CFG_AMAP_MRANK_LEN,
            CFG_AMAP_SRANK0 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR0A0Q_CFG_AMAP_SRANK0,
            CFG_AMAP_SRANK0_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR0A0Q_CFG_AMAP_SRANK0_LEN,
            CFG_AMAP_SRANK1 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR0A0Q_CFG_AMAP_SRANK1,
            CFG_AMAP_SRANK1_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR0A0Q_CFG_AMAP_SRANK1_LEN,
            CFG_AMAP_SRANK2 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR0A0Q_CFG_AMAP_SRANK2,
            CFG_AMAP_SRANK2_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR0A0Q_CFG_AMAP_SRANK2_LEN,
            CFG_AMAP_BANK2 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR0A0Q_CFG_AMAP_BANK2,
            CFG_AMAP_BANK2_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR0A0Q_CFG_AMAP_BANK2_LEN ,
            CFG_AMAP_BANK1 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR0A0Q_CFG_AMAP_BANK1,
            CFG_AMAP_BANK1_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR0A0Q_CFG_AMAP_BANK1_LEN ,
            CFG_AMAP_BANK0 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR0A0Q_CFG_AMAP_BANK0,
            CFG_AMAP_BANK0_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR0A0Q_CFG_AMAP_BANK0_LEN ,

            CFG_AMAP_BANK_GROUP1 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_BANK_GROUP1,
            CFG_AMAP_BANK_GROUP1_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_BANK_GROUP1_LEN ,
            CFG_AMAP_BANK_GROUP0 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_BANK_GROUP0,
            CFG_AMAP_BANK_GROUP0_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_BANK_GROUP0_LEN ,
            CFG_AMAP_ROW17 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_ROW17,
            CFG_AMAP_ROW17_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_ROW17_LEN,
            CFG_AMAP_ROW16 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_ROW16,
            CFG_AMAP_ROW16_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_ROW16_LEN,
            CFG_AMAP_ROW15 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_ROW15,
            CFG_AMAP_ROW15_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_ROW15_LEN,
            CFG_AMAP_ROW14 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_ROW14,
            CFG_AMAP_ROW14_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_ROW14_LEN,
            CFG_AMAP_ROW13 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_ROW13,
            CFG_AMAP_ROW13_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_ROW13_LEN,
            CFG_AMAP_ROW12 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_ROW12,
            CFG_AMAP_ROW12_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_ROW12_LEN,
            CFG_AMAP_ROW11 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_ROW11,
            CFG_AMAP_ROW11_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_ROW11_LEN,
            CFG_AMAP_ROW10 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_ROW10,
            CFG_AMAP_ROW10_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR1A0Q_CFG_AMAP_ROW10_LEN,

            CFG_AMAP_ROW9 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW9,
            CFG_AMAP_ROW9_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW9_LEN,
            CFG_AMAP_ROW8 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW8,
            CFG_AMAP_ROW8_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW8_LEN,
            CFG_AMAP_ROW7 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW7,
            CFG_AMAP_ROW7_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW7_LEN,
            CFG_AMAP_ROW6 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW6,
            CFG_AMAP_ROW6_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW6_LEN,
            CFG_AMAP_ROW5 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW5,
            CFG_AMAP_ROW5_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW5_LEN,
            CFG_AMAP_ROW4 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW4,
            CFG_AMAP_ROW4_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW4_LEN,
            CFG_AMAP_ROW3 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW3,
            CFG_AMAP_ROW3_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW3_LEN,
            CFG_AMAP_ROW2 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW2,
            CFG_AMAP_ROW2_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW2_LEN,
            CFG_AMAP_ROW1 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW1,
            CFG_AMAP_ROW1_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW1_LEN,
            CFG_AMAP_ROW0 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW0,
            CFG_AMAP_ROW0_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR2A0Q_CFG_AMAP_ROW0_LEN,

            CFG_AMAP_COL9 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR3A0Q_CFG_AMAP_COL9,
            CFG_AMAP_COL9_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR3A0Q_CFG_AMAP_COL9_LEN,
            CFG_AMAP_COL8 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR3A0Q_CFG_AMAP_COL8,
            CFG_AMAP_COL8_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR3A0Q_CFG_AMAP_COL8_LEN,
            CFG_AMAP_COL7 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR3A0Q_CFG_AMAP_COL7,
            CFG_AMAP_COL7_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR3A0Q_CFG_AMAP_COL7_LEN,
            CFG_AMAP_COL6 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR3A0Q_CFG_AMAP_COL6,
            CFG_AMAP_COL6_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR3A0Q_CFG_AMAP_COL6_LEN,
            CFG_AMAP_COL5 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR3A0Q_CFG_AMAP_COL5,
            CFG_AMAP_COL5_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR3A0Q_CFG_AMAP_COL5_LEN,
            CFG_AMAP_COL4 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR3A0Q_CFG_AMAP_COL4,
            CFG_AMAP_COL4_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR3A0Q_CFG_AMAP_COL4_LEN,
            CFG_AMAP_COL3 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR3A0Q_CFG_AMAP_COL3,
            CFG_AMAP_COL3_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR3A0Q_CFG_AMAP_COL3_LEN,
            CFG_AMAP_COL2 = scomt::ody::ODC_MCBIST_SCOM_MCBAMR3A0Q_CFG_AMAP_COL2,
            CFG_AMAP_COL2_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBAMR3A0Q_CFG_AMAP_COL2_LEN,
#endif
            LFSR_MASK = scomt::ody::ODC_MCBIST_SCOM_MCBLFSRA0Q_CFG_LFSR_MASK_A0,
            LFSR_MASK_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBLFSRA0Q_CFG_LFSR_MASK_A0_LEN,

            CFG_DATA_ROT_SEED1 = scomt::ody::ODC_MCBIST_SCOM_MCBDRCRQ_CFG_DATA_ROT_SEED,
            CFG_DATA_ROT_SEED1_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBDRCRQ_CFG_DATA_ROT_SEED_LEN,
            CFG_DATA_ROT = scomt::ody::ODC_MCBIST_SCOM_MCBDRCRQ_CFG_DATA_ROT,
            CFG_DATA_ROT_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBDRCRQ_CFG_DATA_ROT_LEN,
            CFG_DATA_ROT_SEED2 = scomt::ody::ODC_MCBIST_SCOM_MCBDRCRQ_CFG_DATA_ROT_SEED,
            CFG_DATA_ROT_SEED2_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBDRCRQ_CFG_DATA_ROT_SEED_LEN,
            CFG_DATA_SEED_MODE = scomt::ody::ODC_MCBIST_SCOM_MCBDRCRQ_CFG_DATA_SEED_MODE,
            CFG_DATA_SEED_MODE_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBDRCRQ_CFG_DATA_SEED_MODE_LEN,

            CFG_TRAP_CE_ENABLE = scomt::ody::ODC_RDF0_SCOM_MCBCM_TRAP_CE_ENABLE,
            CFG_TRAP_UE_ENABLE = scomt::ody::ODC_RDF0_SCOM_MCBCM_TRAP_UE_ENABLE,
            CFG_TRAP_MPE_ENABLE = scomt::ody::ODC_RDF0_SCOM_MCBCM_TRAP_MPE_ENABLE,

            CFG_DGEN_RNDD_SEED0 = scomt::ody::ODC_MCBIST_SCOM_MCBRDS0Q_0,
            CFG_DGEN_RNDD_SEED0_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBRDS0Q_0_LEN,
            CFG_DGEN_RNDD_SEED1 = scomt::ody::ODC_MCBIST_SCOM_MCBRDS0Q_1,
            CFG_DGEN_RNDD_SEED1_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBRDS0Q_1_LEN,
            CFG_DGEN_RNDD_SEED2 = scomt::ody::ODC_MCBIST_SCOM_MCBRDS1Q_SEED2,
            CFG_DGEN_RNDD_SEED2_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBRDS1Q_SEED2_LEN,
            CFG_DGEN_RNDD_DATA_MAPPING = scomt::ody::ODC_MCBIST_SCOM_MCBRDS1Q_DATA_MAPPING,
            CFG_DGEN_RNDD_DATA_MAPPING_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBRDS1Q_DATA_MAPPING_LEN,

            // THRESHOLD control bits
            MBSTRQ_CFG_THRESH_MAG_NCE_INT = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_THRESH_MAG_NCE_INT,
            MBSTRQ_CFG_THRESH_MAG_NCE_INT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_THRESH_MAG_NCE_INT_LEN,
            MBSTRQ_CFG_THRESH_MAG_NCE_SOFT = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_THRESH_MAG_NCE_SOFT,
            MBSTRQ_CFG_THRESH_MAG_NCE_SOFT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_THRESH_MAG_NCE_SOFT_LEN,
            MBSTRQ_CFG_THRESH_MAG_NCE_HARD = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_THRESH_MAG_NCE_HARD,
            MBSTRQ_CFG_THRESH_MAG_NCE_HARD_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_THRESH_MAG_NCE_HARD_LEN,
            MBSTRQ_CFG_THRESH_MAG_RCE = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_THRESH_MAG_RCE,
            MBSTRQ_CFG_THRESH_MAG_RCE_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_THRESH_MAG_RCE_LEN,
            MBSTRQ_CFG_THRESH_MAG_ICE = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_THRESH_MAG_ICE,
            MBSTRQ_CFG_THRESH_MAG_ICE_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_THRESH_MAG_ICE_LEN,
            MBSTRQ_CFG_THRESH_MAG_MCE_INT = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_THRESH_MAG_MCE_INT,
            MBSTRQ_CFG_THRESH_MAG_MCE_INT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_THRESH_MAG_MCE_INT_LEN,
            MBSTRQ_CFG_THRESH_MAG_MCE_SOFT = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_THRESH_MAG_MCE_SOFT,
            MBSTRQ_CFG_THRESH_MAG_MCE_SOFT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_THRESH_MAG_MCE_SOFT_LEN,
            MBSTRQ_CFG_THRESH_MAG_MCE_HARD = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_THRESH_MAG_MCE_HARD,
            MBSTRQ_CFG_THRESH_MAG_MCE_HARD_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_THRESH_MAG_MCE_HARD_LEN,
            MBSTRQ_CFG_PAUSE_ON_SCE = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_PAUSE_ON_SCE,

            // NO MBSTRQ_CFG_PAUSE_ON_MCE
            // MBSTRQ_CFG_PAUSE_ON_MCE
            MBSTRQ_CFG_PAUSE_ON_UE = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_PAUSE_ON_UE,
            MBSTRQ_CFG_PAUSE_ON_SUE = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_PAUSE_ON_SUE,
            MBSTRQ_CFG_PAUSE_ON_AUE = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_PAUSE_ON_AUE,
            MBSTRQ_CFG_PAUSE_ON_RCD = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_PAUSE_ON_RCD,
            MBSTRQ_CFG_SYMBOL_COUNTER_MODE = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_SYMBOL_COUNTER_MODE,
            MBSTRQ_CFG_SYMBOL_COUNTER_MODE_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_SYMBOL_COUNTER_MODE_LEN,
            MBSTRQ_CFG_NCE_SOFT_SYMBOL_COUNT_ENABLE = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_NCE_SOFT_SYMBOL_COUNT_ENABLE,
            MBSTRQ_CFG_NCE_INTER_SYMBOL_COUNT_ENABLE = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_NCE_INTER_SYMBOL_COUNT_ENABLE,
            MBSTRQ_CFG_NCE_HARD_SYMBOL_COUNT_ENABLE = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_NCE_HARD_SYMBOL_COUNT_ENABLE,
            MBSTRQ_CFG_PAUSE_MCB_ERROR = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_PAUSE_MCB_ERROR,
            MBSTRQ_CFG_PAUSE_MCB_LOG_FULL = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_PAUSE_MCB_LOG_FULL,
            MBSTRQ_CFG_MCE_SOFT_SYMBOL_COUNT_ENABLE = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_MCE_SOFT_SYMBOL_COUNT_ENABLE,
            MBSTRQ_CFG_MCE_INTER_SYMBOL_COUNT_ENABLE = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_MCE_INTER_SYMBOL_COUNT_ENABLE,
            MBSTRQ_CFG_MCE_HARD_SYMBOL_COUNT_ENABLE = scomt::ody::ODC_MCBIST_SCOM_MBSTRQ_CFG_MCE_HARD_SYMBOL_COUNT_ENABLE,

            // Bit mapping for MCBIST error log control data
            // TODO:ZEN-MST1390 Add MCBIST data/address trap processing
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
            MCB_PROGRAM_COMPLETE = scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_ISTFIRQ_MCBIST_PROGRAM_COMPLETE,
            MCB_WAT_DEBUG_ATTN = scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_ISTFIRQ_WAT_DEBUG_ATTN,
            MCB_DATA_ERROR = scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_ISTFIRQ_MCBIST_DATA_ERROR,

            //XLT address valid offset
            XLT0_SLOT1_D_VALID     = 0,
            XLT0_SLOT0_M1_VALID    = 0,
            XLT0_SLOT0_M0_VALID    = 0,
            XLT0_SLOT0_S2_VALID    = 0,
            XLT0_SLOT0_S1_VALID    = 0,
            XLT0_SLOT0_S0_VALID    = 0,
            XLT0_SLOT0_ROW17_VALID = 0,
            XLT0_SLOT0_ROW16_VALID = 0,
            XLT0_SLOT0_ROW15_VALID = 0,

        };

        // MCBIST error log related registers
        // TODO:ZEN-MST1390 Add MCBIST data/address trap processing
        static constexpr uint64_t RD_BUF_CTL_REG = 0;
        static constexpr uint64_t RD_BUF_DATA_REG = 0;
        static constexpr uint64_t RD_BUF_ECC_REG = 0;

        enum
        {
            // Register field constants
            RB_ADDRESS = 0,
            RB_ADDRESS_LEN = 0,
            RB_AUTOINC = 0,

            // Other constants
            NUM_COMPARE_LOG_ENTRIES = 64,
        };
};


///
/// @class mcbistTraits
/// @brief a collection of traits associated with the Explorer MEM_PORT
///
template<>
class mcbistTraits< mss::mc_type::EXPLORER, fapi2::TARGET_TYPE_MEM_PORT>
{
    public:
        // MCBIST error log related registers
        // TODO:ZEN-MST1390 Add MCBIST data/address trap processing
        static constexpr uint64_t ERROR_LOG_PTR_REG = 0;
        static constexpr uint64_t RMW_WRT_BUF_CTL_REG = 0;
        static constexpr uint64_t RMW_WRT_BUF_DATA_REG = 0;
        static constexpr uint64_t RMW_WRT_BUF_ECC_REG = 0;

        static constexpr uint64_t XLTATE0 = scomt::ody::ODC_SRQ_MBXLT0;
        static constexpr uint64_t XLTATE1 = scomt::ody::ODC_SRQ_MBXLT1;
        static constexpr uint64_t XLTATE2 = scomt::ody::ODC_SRQ_MBXLT2;

        // Maintenance data location within the array
        static constexpr uint64_t MAINT_DATA_INDEX_START = 0b000000000;
        static constexpr uint64_t MAINT_DATA_INDEX_END   = 0b000001000;

        enum
        {
            // Register field constants
            // TODO:ZEN-MST1390 Add MCBIST data/address trap processing
            ERROR_LOG_PTR = 0,
            ERROR_LOG_PTR_LEN = 0,
            ERROR_LOG_FULL = 0,
            RMW_WRT_BUFFER_SEL = 0,
            RMW_WRT_ADDRESS = 0,
            RMW_WRT_ADDRESS_LEN = 0,
            RMW_WRT_AUTOINC = 0,
            RMW_WRT_ECCGEN = 0,

            // TODO:ZEN-MST1395 Add Odyssey MCBIST address mapping traits
            XLTATE_SLOT0_VALID = 0,
            XLTATE_SLOT1_VALID = 0,

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

}// mss
#endif
