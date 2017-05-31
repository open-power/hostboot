/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/ccs/ccs.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file ccs.H
/// @brief Run and manage the CCS engine
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_CCS_H_
#define _MSS_CCS_H_

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/utils/poll.H>
#include <lib/utils/swizzle.H>
#include <lib/mc/port.H>
#include <lib/shared/mss_const.H>

constexpr uint64_t CKE_HIGH = 0b1111;

// I have a dream that the CCS engine code can be shared among controllers. So, I drive the
// engine from a set of traits. This might be folly. Allow me to dream. BRS
///
/// @class ccsTraits
/// @brief Nimbus CCS Engine traits
///
template< fapi2::TargetType T >
class ccsTraits;

template<>
class ccsTraits<fapi2::TARGET_TYPE_MEMBUF_CHIP>
{
    public:
};

template<>
class ccsTraits<fapi2::TARGET_TYPE_MCBIST>
{
    public:
        static constexpr uint64_t MODEQ_REG = MCBIST_CCS_MODEQ;
        static constexpr uint64_t MCB_CNTL_REG = MCBIST_MCB_CNTLQ;
        static constexpr uint64_t CNTLQ_REG = MCBIST_CCS_CNTLQ;
        static constexpr uint64_t STATQ_REG = MCBIST_CCS_STATQ;

        enum
        {
            // CCS MODEQ
            STOP_ON_ERR = MCBIST_CCS_MODEQ_STOP_ON_ERR,
            UE_DISABLE = MCBIST_CCS_MODEQ_UE_DISABLE,
            DATA_COMPARE_BURST_SEL = MCBIST_CCS_MODEQ_DATA_COMPARE_BURST_SEL,
            DATA_COMPARE_BURST_SEL_LEN = MCBIST_CCS_MODEQ_DATA_COMPARE_BURST_SEL_LEN,
            DDR_CAL_TIMEOUT_CNT = MCBIST_CCS_MODEQ_DDR_CAL_TIMEOUT_CNT,
            DDR_CAL_TIMEOUT_CNT_LEN = MCBIST_CCS_MODEQ_DDR_CAL_TIMEOUT_CNT_LEN,
            CFG_PARITY_AFTER_CMD = MCBIST_CCS_MODEQ_CFG_PARITY_AFTER_CMD,
            COPY_CKE_TO_SPARE_CKE = MCBIST_CCS_MODEQ_COPY_CKE_TO_SPARE_CKE,
            DISABLE_ECC_ARRAY_CHK = MCBIST_CCS_MODEQ_DISABLE_ECC_ARRAY_CHK,
            DISABLE_ECC_ARRAY_CORRECTION = MCBIST_CCS_MODEQ_DISABLE_ECC_ARRAY_CORRECTION,
            CFG_DGEN_FIXED_MODE = MCBIST_CCS_MODEQ_CFG_DGEN_FIXED_MODE,
            DDR_CAL_TIMEOUT_CNT_MULT = MCBIST_CCS_MODEQ_DDR_CAL_TIMEOUT_CNT_MULT,
            DDR_CAL_TIMEOUT_CNT_MULT_LEN = MCBIST_CCS_MODEQ_DDR_CAL_TIMEOUT_CNT_MULT_LEN,
            IDLE_PAT_ADDRESS_0_13 = MCBIST_CCS_MODEQ_IDLE_PAT_ADDRESS_0_13,
            IDLE_PAT_ADDRESS_0_13_LEN = MCBIST_CCS_MODEQ_IDLE_PAT_ADDRESS_0_13_LEN,
            IDLE_PAT_ADDRESS_17 = MCBIST_CCS_MODEQ_IDLE_PAT_ADDRESS_17,
            IDLE_PAT_BANK_GROUP_1 = MCBIST_CCS_MODEQ_IDLE_PAT_BANK_GROUP_1,
            IDLE_PAT_BANK_0_1 = MCBIST_CCS_MODEQ_IDLE_PAT_BANK_0_1,
            IDLE_PAT_BANK_0_1_LEN = MCBIST_CCS_MODEQ_IDLE_PAT_BANK_0_1_LEN,
            IDLE_PAT_BANK_GROUP_0 = MCBIST_CCS_MODEQ_IDLE_PAT_BANK_GROUP_0,
            IDLE_PAT_ACTN = MCBIST_CCS_MODEQ_IDLE_PAT_ACTN,
            IDLE_PAT_ADDRESS_16 = MCBIST_CCS_MODEQ_IDLE_PAT_ADDRESS_16,
            IDLE_PAT_ADDRESS_15 = MCBIST_CCS_MODEQ_IDLE_PAT_ADDRESS_15,
            IDLE_PAT_ADDRESS_14 = MCBIST_CCS_MODEQ_IDLE_PAT_ADDRESS_14,
            NTTM_MODE = MCBIST_CCS_MODEQ_NTTM_MODE,
            NTTM_RW_DATA_DLY = MCBIST_CCS_MODEQ_NTTM_RW_DATA_DLY,
            NTTM_RW_DATA_DLY_LEN = MCBIST_CCS_MODEQ_NTTM_RW_DATA_DLY_LEN,
            IDLE_PAT_BANK_2 = MCBIST_CCS_MODEQ_IDLE_PAT_BANK_2,
            DDR_PARITY_ENABLE = MCBIST_CCS_MODEQ_DDR_PARITY_ENABLE,
            IDLE_PAT_PARITY = MCBIST_CCS_MODEQ_IDLE_PAT_PARITY,

            // MCB_CNTRL
            MCB_CNTL_PORT_SEL = MCBIST_MCB_CNTLQ_MCBCNTL_PORT_SEL,
            MCB_CNTL_PORT_SEL_LEN = MCBIST_MCB_CNTLQ_MCBCNTL_PORT_SEL_LEN,

            // CCS CNTL
            CCS_START = MCBIST_CCS_CNTLQ_START,
            CCS_STOP = MCBIST_CCS_CNTLQ_STOP,

            // CCS STATQ
            CCS_IN_PROGRESS = MCBIST_CCS_STATQ_IP,

            // ARR0
            ARR0_DDR_ADDRESS_0_13 = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_0_13,
            ARR0_DDR_ADDRESS_0_13_LEN = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_0_13_LEN,
            ARR0_DDR_ADDRESS_0_9 = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_0_13, // Useful for rd/wr cmds
            ARR0_DDR_ADDRESS_0_9_LEN = 10, // CA bits are 9:0, total length of 10
            ARR0_DDR_ADDRESS_10 = 10, // ADR10 is the 10th bit from the left in Nimbus ARR0
            ARR0_DDR_ADDRESS_17 = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_17,
            ARR0_DDR_BANK_GROUP_1 = MCBIST_CCS_INST_ARR0_00_DDR_BANK_GROUP_1,
            ARR0_DDR_RESETN = MCBIST_CCS_INST_ARR0_00_DDR_RESETN,
            ARR0_DDR_BANK_0_1 = MCBIST_CCS_INST_ARR0_00_DDR_BANK_0_1,
            ARR0_DDR_BANK_0_1_LEN = MCBIST_CCS_INST_ARR0_00_DDR_BANK_0_1_LEN,
            ARR0_DDR_BANK_GROUP_0 = MCBIST_CCS_INST_ARR0_00_DDR_BANK_GROUP_0,
            ARR0_DDR_ACTN = MCBIST_CCS_INST_ARR0_00_DDR_ACTN,
            ARR0_DDR_ADDRESS_16 = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_16,
            ARR0_DDR_ADDRESS_15 = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_15,
            ARR0_DDR_ADDRESS_14 = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_14,
            ARR0_DDR_CKE = MCBIST_CCS_INST_ARR0_00_DDR_CKE,
            ARR0_DDR_CKE_LEN = MCBIST_CCS_INST_ARR0_00_DDR_CKE_LEN,
            ARR0_DDR_CSN_0_1 = MCBIST_CCS_INST_ARR0_00_DDR_CSN_0_1,
            ARR0_DDR_CSN_0_1_LEN = MCBIST_CCS_INST_ARR0_00_DDR_CSN_0_1_LEN,
            ARR0_DDR_CID_0_1 = MCBIST_CCS_INST_ARR0_00_DDR_CID_0_1,
            ARR0_DDR_CID_0_1_LEN = MCBIST_CCS_INST_ARR0_00_DDR_CID_0_1_LEN,
            ARR0_DDR_CSN_2_3 = MCBIST_CCS_INST_ARR0_00_DDR_CSN_2_3,
            ARR0_DDR_CSN_2_3_LEN = MCBIST_CCS_INST_ARR0_00_DDR_CSN_2_3_LEN,
            ARR0_DDR_CID_2 = MCBIST_CCS_INST_ARR0_00_DDR_CID_2,
            ARR0_DDR_ODT = MCBIST_CCS_INST_ARR0_00_DDR_ODT,
            ARR0_DDR_ODT_LEN = MCBIST_CCS_INST_ARR0_00_DDR_ODT_LEN,
            ARR0_DDR_CAL_TYPE = MCBIST_CCS_INST_ARR0_00_DDR_CAL_TYPE,
            ARR0_DDR_CAL_TYPE_LEN = MCBIST_CCS_INST_ARR0_00_DDR_CAL_TYPE_LEN,
            ARR0_DDR_PARITY = MCBIST_CCS_INST_ARR0_00_DDR_PARITY,
            ARR0_DDR_BANK_2 = MCBIST_CCS_INST_ARR0_00_DDR_BANK_2,
            ARR0_LOOP_BREAK_MODE = MCBIST_CCS_INST_ARR0_00_LOOP_BREAK_MODE,
            ARR0_LOOP_BREAK_MODE_LEN = MCBIST_CCS_INST_ARR0_00_LOOP_BREAK_MODE_LEN,

            // ARR1
            ARR1_IDLES = MCBIST_CCS_INST_ARR1_00_IDLES,
            ARR1_IDLES_LEN = MCBIST_CCS_INST_ARR1_00_IDLES_LEN,
            ARR1_REPEAT_CMD_CNT = MCBIST_CCS_INST_ARR1_00_REPEAT_CMD_CNT,
            ARR1_REPEAT_CMD_CNT_LEN = MCBIST_CCS_INST_ARR1_00_REPEAT_CMD_CNT_LEN,
            ARR1_READ_OR_WRITE_DATA = MCBIST_CCS_INST_ARR1_00_READ_OR_WRITE_DATA,
            ARR1_READ_OR_WRITE_DATA_LEN = MCBIST_CCS_INST_ARR1_00_READ_OR_WRITE_DATA_LEN,
            ARR1_READ_COMPARE_REQUIRED = MCBIST_CCS_INST_ARR1_00_READ_COMPARE_REQUIRED,
            ARR1_DDR_CAL_RANK = MCBIST_CCS_INST_ARR1_00_DDR_CAL_RANK,
            ARR1_DDR_CAL_RANK_LEN = MCBIST_CCS_INST_ARR1_00_DDR_CAL_RANK_LEN,
            ARR1_DDR_CALIBRATION_ENABLE = MCBIST_CCS_INST_ARR1_00_DDR_CALIBRATION_ENABLE,
            ARR1_END = MCBIST_CCS_INST_ARR1_00_END,
            ARR1_GOTO_CMD = MCBIST_CCS_INST_ARR1_00_GOTO_CMD,
            ARR1_GOTO_CMD_LEN = MCBIST_CCS_INST_ARR1_00_GOTO_CMD_LEN,

        };
};

namespace mss
{
namespace ccs
{

enum
{
    // Success is defined as done-bit set, no others.
    STAT_QUERY_SUCCESS    = 0x4000000000000000,

    // Bit positions 3:5
    STAT_READ_MISCOMPARE = 0x1000000000000000,
    STAT_UE_SUE          = 0x0800000000000000,
    STAT_CAL_TIMEOUT     = 0x0400000000000000,

    // If the fail type isn't one of these, we're hung
    STAT_HUNG = 0x0ull,
};


///
/// @class instruction_t
/// @brief Class for ccs instructions
/// @tparam T fapi2::TargetType representing the target of the CCS instructions
/// @note A ccs instruction is data (array 0) and some control information (array 1)cc
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
class instruction_t
{
    public:
        fapi2::buffer<uint64_t> arr0;
        fapi2::buffer<uint64_t> arr1;

        ///
        /// @brief intstruction_t ctor
        /// @param[in] i_target the DIMM this instruction is headed for
        /// @param[in] i_rank the rank this instruction is headed for
        /// @param[in] i_arr0 the initial value for arr0, defaults to 0
        /// @param[in] i_arr1 the initial value for arr1, defaults to 0
        ///
        instruction_t( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target = fapi2::Target<fapi2::TARGET_TYPE_DIMM>(),
                       uint64_t i_rank = NO_CHIP_SELECT_ACTIVE,
                       const fapi2::buffer<uint64_t> i_arr0 = 0,
                       const fapi2::buffer<uint64_t> i_arr1 = 0):
            arr0(i_arr0),
            arr1(i_arr1)
        {
            // For DIMM0 .first is the CSN_0_1 setting, .second is the CSN_2_3 setting.
            // For DIMM1 .first is the CSN_2_3 setting, .second is the CSN_0_1 setting.
            static const std::pair<uint64_t, uint64_t> CS_N[mss::MAX_RANK_PER_DIMM] =
            {
                // CS0 L CS1 H => CS2 => H CS3 => H Rank 0
                { 0b01, 0b11 },

                // CS0 H CS1 L => CS2 => H CS3 => H Rank 1
                { 0b10, 0b11 },

                // CS0 H CS1 H => CS2 => L CS3 => H Rank 2
                { 0b11, 0b01 },

                // CS0 H CS1 H => CS2 => H CS3 => L Rank 3
                { 0b11, 0b10 },
            };

            // If the rank indicates nothing selected (active low) then we're done.
            if (i_rank == NO_CHIP_SELECT_ACTIVE)
            {
                arr0.insertFromRight<TT::ARR0_DDR_CSN_0_1, TT::ARR0_DDR_CSN_0_1_LEN>(0b11);
                arr0.insertFromRight<TT::ARR0_DDR_CSN_2_3, TT::ARR0_DDR_CSN_2_3_LEN>(0b11);
                return;
            }

            //
            // Note: This likely needs to be able to handle all DIMM, stacked, encoded CS_n, etc. This
            // might not cut it. Turn this in to a dispatched funtion like c_str() and rcd_load() BRS
            //

            // Direct CS mode - just clear the CS_N you're interested in.
            // Setup the chip select based on which dimm in the slot and the rank
            if (mss::index(i_target) == 0)
            {
                // Sanity check the incoming rank. It has to be 0-3 since we're DIMM0
                // Assert since this is a programming error
                if (i_rank >= MAX_RANK_PER_DIMM)
                {
                    FAPI_ERR("DIMM0 %s CCS instruction looking for bad rank/chip select (%d)",
                             mss::c_str(i_target), i_rank);
                    fapi2::Assert(false);
                    // Not reached but fapi2::Assert isn't [[no return]] so the compiler thinks we're going
                    // to run off the array but we're not so this makes the compiler happy.
                    return;
                }

                arr0.insertFromRight<TT::ARR0_DDR_CSN_0_1,
                                     TT::ARR0_DDR_CSN_0_1_LEN>(CS_N[i_rank].first);
                arr0.insertFromRight<TT::ARR0_DDR_CSN_2_3,
                                     TT::ARR0_DDR_CSN_2_3_LEN>(CS_N[i_rank].second);
            }
            else
            {
                // DIMM1's ranks are {4,5,6,7} so we subract the mid-point rank to normalize i_rank for DIMM1
                const uint64_t l_effective_rank = i_rank - RANK_MID_POINT;

                // Sanity check that we don't have more than 2 ranks on DIMM1. Effective Config
                // should have caught this with the plug rules, but we will select the rank in the
                // wrong DIMM with this CCS instruction if we blew it, so lets check ... We can assert
                // our way out of this as this is a code bug in Effective Config, so they should have
                // reported a real error long ago ...
                if (l_effective_rank >= MAX_RANKS_DIMM1)
                {
                    FAPI_ERR("DIMM1 %s CCS instruction looking for bad rank/chip select (%d, %d)",
                             mss::c_str(i_target), i_rank, l_effective_rank);
                    fapi2::Assert(false);
                    // Not reached but fapi2::Assert isn't [[no return]] so the compiler thinks we're going
                    // to run off the array but we're not so this makes the compiler happy.
                    return;
                }

                // Deselect ranks on DIMM1
                arr0.insertFromRight<TT::ARR0_DDR_CSN_0_1,
                                     TT::ARR0_DDR_CSN_0_1_LEN>(CS_N[l_effective_rank].second);
                arr0.insertFromRight<TT::ARR0_DDR_CSN_2_3,
                                     TT::ARR0_DDR_CSN_2_3_LEN>(CS_N[l_effective_rank].first);
            }
        }
};

///
/// @brief A class representing a series of CCS instructions, and the
/// CCS engine parameters associated with running the instructions
/// @tparam T fapi2::TargetType  representing the fapi2 target which
/// @tparam P fapi2::TargetType representing the port
/// contains the CCS engine (e.g., fapi2::TARGET_TYPE_MCBIST)
template< fapi2::TargetType T, fapi2::TargetType P = fapi2::TARGET_TYPE_MCA >
class program
{
    public:
        // Setup our poll parameters so the CCS executer can see
        // whether to use the delays in the instruction stream or not
        program(): iv_poll(0, 0)
        {}

        // Vector of instructions
        std::vector< instruction_t<T> > iv_instructions;
        poll_parameters                 iv_poll;

        // Vector of polling probes
        std::vector< poll_probe<P> >    iv_probes;
};

///
/// @brief Common setup for all MRS/RCD instructions
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in,out] i_arr0 fapi2::buffer<uint64_t> representing the ARR0 of the instruction
/// @return void
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
static void mrs_rcd_helper( fapi2::buffer<uint64_t>& i_arr0 )
{
    //
    // Generic DDR4 MRS setup (RCD is an MRS)
    //
    // CKE is high Note: P8 set all 4 of these high - not sure if that's correct. BRS
    i_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    // ACT is high
    i_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // RAS, CAS, WE low
    i_arr0.clearBit<TT::ARR0_DDR_ADDRESS_16>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_15>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_14>();
}

///
/// @brief Create, initialize an RCD (RCW - JEDEC) CCS command
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the DIMM this instruction is headed for
/// @return the RCD CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
inline instruction_t<T> rcd_command( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target )
{
    fapi2::buffer<uint64_t> rcd_boilerplate_arr0;
    fapi2::buffer<uint64_t> rcd_boilerplate_arr1;

    //
    // Generic DDR4 MRS setup (RCD is an MRS)
    //
    mrs_rcd_helper<fapi2::TARGET_TYPE_MCBIST>(rcd_boilerplate_arr0);

    //
    // RCD setup
    //
    // DDR4: Set BG1 to 0 during an MRS.
    // BG0, BA1:BA0 to 0b111 selects RCW (aka MR7).
    rcd_boilerplate_arr0.clearBit<TT::ARR0_DDR_BANK_GROUP_1>()
    .template insertFromRight<TT::ARR0_DDR_BANK_0_1, TT::ARR0_DDR_BANK_0_1_LEN>(0b11)
    .template setBit<TT::ARR0_DDR_BANK_GROUP_0>();

    // RCD always goes to the 0th rank on the DIMM; either 0 or 4.
    return instruction_t<T>(i_target, (mss::index(i_target) == 0) ? 0 : 4, rcd_boilerplate_arr0, rcd_boilerplate_arr1);
}

///
/// @brief Create, initialize an MRS CCS command
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the DIMM this instruction is headed for
/// @param[in] i_rank the rank on this dimm
/// @param[in] i_mrs the specific MRS
/// @return the MRS CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
inline instruction_t<T> mrs_command( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const uint64_t i_rank,
                                     const uint64_t i_mrs )
{
    fapi2::buffer<uint64_t> rcd_boilerplate_arr0;
    fapi2::buffer<uint64_t> rcd_boilerplate_arr1;
    fapi2::buffer<uint8_t> mrs(i_mrs);

    //
    // Generic DDR4 MRS setup (RCD is an MRS)
    //
    mrs_rcd_helper<fapi2::TARGET_TYPE_MCBIST>(rcd_boilerplate_arr0);

    //
    // MRS setup
    //
    // DDR4: Set BG1 to 0. BG0, BA1:BA0 to i_mrs
    rcd_boilerplate_arr0.clearBit<TT::ARR0_DDR_BANK_GROUP_1>();
    mss::swizzle<TT::ARR0_DDR_BANK_0_1, 3, 7>(mrs, rcd_boilerplate_arr0);
    FAPI_DBG("mrs rcd boiler 0x%llx 0x%llx", uint8_t(mrs), uint64_t(rcd_boilerplate_arr0));
    return instruction_t<T>(i_target, i_rank, rcd_boilerplate_arr0, rcd_boilerplate_arr1);
}

///
/// @brief Create, initialize a JEDEC Device Deselect CCS command
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @return the Device Deselect CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
inline instruction_t<T> des_command()
{
    fapi2::buffer<uint64_t> rcd_boilerplate_arr0;
    fapi2::buffer<uint64_t> rcd_boilerplate_arr1;

    // ACT is high. It's a no-care in the spec but it seems to raise questions when
    // people look at the trace, so lets set it high.
    rcd_boilerplate_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // CKE is high Note: P8 set all 4 of these high - not sure if that's correct. BRS
    rcd_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    // ACT is high no-care
    // RAS, CAS, WE no-care

    // Device Deslect wants CS_n always high (select nothing using rank NO_CHIP_SELECT_ACTIVE)
    return instruction_t<T>(fapi2::Target<fapi2::TARGET_TYPE_DIMM>(), NO_CHIP_SELECT_ACTIVE,
                            rcd_boilerplate_arr0, rcd_boilerplate_arr1);
}

///
/// @brief Create, initialize an instruction which indicates an initial cal
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_rp the rank-pair (rank) to cal
/// @return the initial cal instruction
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
inline instruction_t<T> initial_cal_command(const uint64_t i_rp)
{
    // An initial cal arr0 looks just like a DES, but we set the initial cal bits
    instruction_t<T> l_inst = des_command<T>();

    // ACT is low - per Centaur spec (Shelton to confirm for Nimbus) BRS
    l_inst.arr0.template clearBit<TT::ARR0_DDR_ACTN>();

    l_inst.arr0.template insertFromRight<TT::ARR0_DDR_CAL_TYPE, TT::ARR0_DDR_CAL_TYPE_LEN>(0b1100);
    l_inst.arr1.template setBit<TT::ARR1_DDR_CALIBRATION_ENABLE>();

#ifdef USE_LOTS_OF_IDLES
    // Idles is 0xFFFF - per Centaur spec (Shelton to confirm for Nimbus) BRS
    l_inst.arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(0xFFFF);
#else
    l_inst.arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(0x0);
#endif

    // The rank we're calibrating is enacoded - it's an int. So rank 3 is 0011 not 0001
    l_inst.arr1.template insertFromRight<TT::ARR1_DDR_CAL_RANK, TT::ARR1_DDR_CAL_RANK_LEN>(i_rp);

    return l_inst;
}

///
/// @brief Setup ZQ Long instruction
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the DIMM this instruction is headed for
/// @param[in] i_rank the rank on this dimm
/// @return the MRS CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
inline instruction_t<T> zqcl_command( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const uint64_t i_rank )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0;
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    // CKE is high Note: P8 set all 4 of these high - not sure if that's correct. BRS
    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    // ACT is high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // RAS/CAS high, WE low
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_16>()
    .template setBit<TT::ARR0_DDR_ADDRESS_15>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_14>();

    // ADDR10/AP is high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_10>();

    return instruction_t<T>(i_target, i_rank, l_boilerplate_arr0, l_boilerplate_arr1);
}

///
/// @brief Setup read command helper function
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the DIMM this instruction is headed for
/// @param[in] i_rank the rank on this dimm
/// @param[in] i_bank_addr bank address bits [BG0:BG1] = [62:63] (right aligned)
/// @param[in] i_bank_group_addr bank group address bits [BA0:BA1] = [62:63] (right aligned)
/// @param[in] i_column_addr column address bits [A0:A9] = [54:63] (right aligned)
/// @return the read command CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
static fapi2::buffer<uint64_t> read_cmd_boilerplate( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_rank,
        const fapi2::buffer<uint64_t>& i_bank_addr = 0,
        const fapi2::buffer<uint64_t>& i_bank_group_addr = 0,
        const fapi2::buffer<uint64_t>& i_column_addr = 0)
{
    // TODO - RTC 166175 Encapsulate command truth table in a subclass for ccs.H
    fapi2::buffer<uint64_t> l_boilerplate_arr0;

    // CKE is high Note: P8 set all 4 of these high - not sure if that's correct. AAM
    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE,
                                       TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    // ACT is high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // RAS high, CAS low, WE high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_16>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_15>()
    .template setBit<TT::ARR0_DDR_ADDRESS_14>();

    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_BANK_0_1,
                                       TT::ARR0_DDR_BANK_0_1_LEN>(i_bank_addr);

    // Bank Group takes a little effort - the bits aren't contiguous
    constexpr uint64_t BG0_BIT = 62;
    constexpr uint64_t BG1_BIT = 63;

    l_boilerplate_arr0.writeBit<TT::ARR0_DDR_BANK_GROUP_0>(i_bank_group_addr.getBit<BG0_BIT>())
    .template writeBit<TT::ARR0_DDR_BANK_GROUP_1>(i_bank_group_addr.getBit<BG1_BIT>());

    // CA is A[0:9]
    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_ADDRESS_0_9,
                                       TT::ARR0_DDR_ADDRESS_0_9_LEN>(i_column_addr);

    return l_boilerplate_arr0;
}

///
/// @brief Setup read command (Fixed BL8 or BC4) instruction
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the DIMM this instruction is headed for
/// @param[in] i_rank the rank on this dimm
/// @param[in] i_bank_addr bank address bits [BG0:BG1] = [62:63] (right aligned)
/// @param[in] i_bank_group_addr bank group address bits [BA0:BA1] = [62:63] (right aligned)
/// @param[in] i_column_addr column address bits [A0:A9] = [54:63] (right aligned)
/// @return the read command CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
inline instruction_t<T> rd_command( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    const uint64_t i_rank,
                                    const fapi2::buffer<uint64_t>& i_bank_addr = 0,
                                    const fapi2::buffer<uint64_t>& i_bank_group_addr = 0,
                                    const fapi2::buffer<uint64_t>& i_column_addr = 0)
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0;
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    l_boilerplate_arr0 = read_cmd_boilerplate<fapi2::TARGET_TYPE_MCBIST>(i_target, i_rank, i_bank_addr,
                         i_bank_group_addr, i_column_addr);

    // Setup ADDR10/AP based on read type
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_ADDRESS_10>();

    return instruction_t<T>(i_target, i_rank, l_boilerplate_arr0, l_boilerplate_arr1);
}

///
/// @brief Setup read w/auto precharge command (Fixed BL8 or BC4) instruction
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the DIMM this instruction is headed for
/// @param[in] i_rank the rank on this dimm
/// @param[in] i_bank_addr bank address bits [BG0:BG1] = [62:63] (right aligned)
/// @param[in] i_bank_group_addr bank group address bits [BA0:BA1] = [62:63] (right aligned)
/// @param[in] i_column_addr column address bits [A0:A9] = [54:63] (right aligned)
/// @return the read command CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
inline instruction_t<T> rda_command( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const uint64_t i_rank,
                                     const fapi2::buffer<uint64_t>& i_bank_addr = 0,
                                     const fapi2::buffer<uint64_t>& i_bank_group_addr = 0,
                                     const fapi2::buffer<uint64_t>& i_column_addr = 0)
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0;
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    l_boilerplate_arr0 = read_cmd_boilerplate<fapi2::TARGET_TYPE_MCBIST>(i_target, i_rank, i_bank_addr,
                         i_bank_group_addr, i_column_addr);

    // Setup ADDR10/AP based on read type
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_10>();

    return instruction_t<T>(i_target, i_rank, l_boilerplate_arr0, l_boilerplate_arr1);
}

///
/// @brief Setup precharge all banks command instruction
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the DIMM this instruction is headed for
/// @param[in] i_rank the rank on this dimm
/// @return the precharge all banks command CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
inline instruction_t<T> precharge_all_command( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_rank )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0;
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    // CKE is high Note: P8 set all 4 of these high - not sure if that's correct. AAM
    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    // ACT is high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // RAS low, CAS high, WE low
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_ADDRESS_16>()
    .template setBit<TT::ARR0_DDR_ADDRESS_15>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_14>();

    // Setup ADDR10/AP high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_10>();

    // From DDR4 Spec table 17:
    // All other bits from the command truth table or 'V', for valid (1 or 0)

    return instruction_t<T>(i_target, i_rank, l_boilerplate_arr0, l_boilerplate_arr1);
}

//
// These functions are a little sugar to keep callers from doing the traits-dance to get the
// appropriate bit field
//

///
/// @brief Select the port(s) to be used by the CCS
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in] i_ports the buffer representing the ports
/// @return void
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
inline fapi2::ReturnCode select_ports( const fapi2::Target<T>& i_target, uint64_t i_ports)
{
    fapi2::buffer<uint64_t> l_data;
    fapi2::buffer<uint64_t> l_ports;

    // Not handling multiple ports here, can't do that for CCS. BRS
    FAPI_TRY( l_ports.setBit(i_ports) );

    FAPI_TRY( mss::getScom(i_target, TT::MCB_CNTL_REG, l_data) );
    l_data.insert<TT::MCB_CNTL_PORT_SEL, TT::MCB_CNTL_PORT_SEL_LEN>(l_ports);
    FAPI_TRY( mss::putScom(i_target, TT::MCB_CNTL_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief User sets to a '1'b to tell the Hdw to stop CCS whenever failure occurs. When a
///        '0'b, Hdw will continue CCS even if a failure occurs.
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in]  the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @param[in] i_value true iff stop whenever failure occurs.
/// @return void
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
inline void stop_on_err( const fapi2::Target<T>&, fapi2::buffer<uint64_t>& io_buffer, const states i_value)
{
    io_buffer.writeBit<TT::STOP_ON_ERR>(i_value);
}

///
/// @brief Disable ECC checking on the CCS arrays
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @return void
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
inline void disable_ecc( const fapi2::Target<T>&, fapi2::buffer<uint64_t>& io_buffer)
{
    io_buffer.setBit<TT::DISABLE_ECC_ARRAY_CHK>()
    .template setBit<TT::DISABLE_ECC_ARRAY_CORRECTION>();
}

///
/// @brief User sets to a '1'b to force the Hdw to ignore any array ue or sue errors
///        during CCS command fetching.
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @param[in] i_value true iff ignore any array ue or sue errors.
/// @return void
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
inline void ue_disable( const fapi2::Target<T>&, fapi2::buffer<uint64_t>& io_buffer, const states i_value)
{
    io_buffer.writeBit<TT::UE_DISABLE>(i_value);
}

///
/// @brief User sets to a '1'b to force the Hdw to delay parity a cycle
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @param[in] i_value mss::ON iff delay parity a cycle
/// @return void
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
inline void parity_after_cmd( const fapi2::Target<T>&, fapi2::buffer<uint64_t>& io_buffer, const states i_value)
{
    io_buffer.writeBit<TT::CFG_PARITY_AFTER_CMD>(i_value);
}

///
/// @brief DDr calibration counter
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @param[in] i_count the count to wait for DDR cal to complete.
/// @param[in] i_mult the DDR calibration time multiplaction factor
/// @return void
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
inline void cal_count( const fapi2::Target<T>&, fapi2::buffer<uint64_t>& io_buffer,
                       const uint64_t i_count, const uint64_t i_mult)
{
    io_buffer.insertFromRight<TT::DDR_CAL_TIMEOUT_CNT, TT::DDR_CAL_TIMEOUT_CNT_LEN>(i_count);
    io_buffer.insertFromRight<TT::DDR_CAL_TIMEOUT_CNT_MULT, TT::DDR_CAL_TIMEOUT_CNT_MULT_LEN>(i_mult);
}

///
/// @brief Copy CKE signals to CKE Spare on both ports NOTE: DOESN'T APPLY FOR NIMBUS. NO
///        SPARE CHIPS TO COPY TO. 0 - Spare CKEs not copied with values from CKE(0:1) and
///         CKE(4:5) 1 - Port A CKE(0:1) copied to Port A CKE(2:3), Port A CKE(4:5) copied
///         to Port A CKE(6:7), Port B CKE(0:1) copied to Port B CKE(2:3) and Port B CKE(4:5)
///         copied to Port B CKE(6:7)
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the ccsTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @param[in] i_value mss::ON iff Copy CKE signals to CKE Spare on both ports
/// @note no-op for p9n
/// @return void
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
void copy_cke_to_spare_cke( const fapi2::Target<T>&, fapi2::buffer<uint64_t>& io_buffer, const states i_value);

///
/// @brief Read the modeq register appropriate for this target
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
inline fapi2::ReturnCode read_mode( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& io_buffer)
{
    FAPI_DBG("read mode 0x%llx", TT::MODEQ_REG);
    return mss::getScom(i_target, TT::MODEQ_REG, io_buffer);
}

///
/// @brief Write the modeq register appropriate for this target
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in] i_buffer the buffer representing the mode register
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
inline fapi2::ReturnCode write_mode( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_buffer)
{
    return mss::putScom(i_target, TT::MODEQ_REG, i_buffer);
}

///
/// @brief Execute a set of CCS instructions - multiple ports
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in] i_program the vector of instructions
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, fapi2::TargetType P, typename TT = ccsTraits<T> >
fapi2::ReturnCode execute( const fapi2::Target<T>& i_target,
                           ccs::program<T>& i_program,
                           const std::vector< fapi2::Target<P> >& i_ports);

///
/// @brief Execute a set of CCS instructions - single port
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam P the target of the CCS instruction (the port)
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in] i_program the vector of instructions
/// @param[in] i_port The target that's being programmed by the array
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, fapi2::TargetType P, typename TT = ccsTraits<T> >
fapi2::ReturnCode execute( const fapi2::Target<T>& i_target,
                           ccs::program<T>& i_program,
                           const fapi2::Target<P>& i_port)
{
    // Mmm. Might want to find a better way to do this - seems expensive. BRS
    std::vector< fapi2::Target<P> > l_ports{ i_port };
    return execute(i_target, i_program, l_ports);
}

///
/// @brief Execute a CCS array already loaded in to the engine
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam P the target of the CCS instruction (the port)
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in] i_program the MCBIST ccs program - to get the polling parameters
/// @param[in] i_port the port associated with the MCBIST array
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, fapi2::TargetType P, typename TT = ccsTraits<T> >
fapi2::ReturnCode execute_inst_array(const fapi2::Target<T>& i_target,
                                     ccs::program<T>& i_program,
                                     const fapi2::Target<P>& i_port);

///
/// @brief Start or stop the CCS engine
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target The MCBIST containing the CCS engine
/// @param[in] i_start_stop bool MSS_CCS_START for starting MSS_CCS_STOP otherwise
/// @return FAPI2_RC_SUCCESS iff success
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
fapi2::ReturnCode start_stop( const fapi2::Target<T>& i_target, const bool i_start_stop );

///
/// @brief Query the status of the CCS engine
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target The MCBIST containing the CCS engine
/// @param[out] io_status The query result first being the result, second the type
/// @return FAPI2_RC_SUCCESS iff success
///
template< fapi2::TargetType T, typename TT = ccsTraits<T> >
fapi2::ReturnCode status_query( const fapi2::Target<T>& i_target, std::pair<uint64_t, uint64_t>& io_status );

} // ends namespace ccs
}

#endif
