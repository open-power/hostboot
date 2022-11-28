/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ccs/ody_ccs_traits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2023                        */
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
/// @file ody_ccs_traits.H
/// @brief Run and manage the CCS engine for Odyssey
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _ODY_MSS_CCS_TRAITS_H_
#define _ODY_MSS_CCS_TRAITS_H_

#include <fapi2.H>

#include <ody_scom_ody_odc.H>

#include <lib/shared/ody_consts.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_address.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist.H>

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <generic/memory/lib/ccs/ccs_traits.H>

///
/// @class ccsTraits
/// @brief Explorer CCS Engine traits
///
template<>
class ccsTraits<mss::mc_type::ODYSSEY>
{
    public:
        static constexpr fapi2::TargetType MC_TARGET_TYPE = fapi2::TARGET_TYPE_OCMB_CHIP;
        static constexpr fapi2::TargetType PORT_TARGET_TYPE = fapi2::TARGET_TYPE_MEM_PORT;
        static constexpr uint64_t MODEQ_REG = scomt::ody::ODC_MCBIST_SCOM_CCS_MODEQ;
        static constexpr uint64_t MCB_CNTL_REG = scomt::ody::ODC_MCBIST_SCOM_MCB_CNTLQ;
        static constexpr uint64_t CNTLQ_REG = scomt::ody::ODC_MCBIST_SCOM_CCS_CNTLQ;
        static constexpr uint64_t STATQ_REG = scomt::ody::ODC_MCBIST_SCOM_CCS_STATQ;

        static constexpr uint64_t PORTS_PER_MC_TARGET = mss::ody::MAX_PORT_PER_OCMB;
        static constexpr uint64_t CCS_MAX_DIMM_PER_PORT = mss::ody::HW_MAX_DIMM_PER_PORT;
        static constexpr uint64_t CCS_MAX_MRANK_PER_PORT =  mss::ody::HW_MAX_RANK_PER_DIMM * mss::ody::HW_MAX_DIMM_PER_PORT;
        static constexpr uint64_t CCS_MAX_RANK_PER_DIMM = mss::ody::HW_MAX_RANK_PER_DIMM;
        static constexpr uint64_t CCS_MAX_RANKS_DIMM1 = 0;

        static constexpr uint64_t NTTM_READ_DELAY = 0x40;
        static constexpr uint64_t NTTM_MODE_FORCE_READ = 21;

        // Command Pass Disable Delay Time for Explorer - really a JEDEC timing
        // Note using the max value here (4800's delay)
        static constexpr uint64_t TIMING_TCPDED = 13;

        enum
        {
            // Non address values that are needed for helper functions

            // CCS MODEQ
            STOP_ON_ERR = scomt::ody::ODC_MCBIST_SCOM_CCS_MODEQ_CCS_STOP_ON_ERR,
            UE_DISABLE = scomt::ody::ODC_MCBIST_SCOM_CCS_MODEQ_CCS_UE_DISABLE,
            DATA_COMPARE_BURST_SEL = scomt::ody::ODC_MCBIST_SCOM_CCS_MODEQ_CCS_DATA_COMPARE_BURST_SEL,
            DATA_COMPARE_BURST_SEL_LEN = scomt::ody::ODC_MCBIST_SCOM_CCS_MODEQ_CCS_DATA_COMPARE_BURST_SEL_LEN,
            // TODO:MST-1437 Fix the next two bits for Odyssey CCS
            CFG_PARITY_AFTER_CMD = 24,
            COPY_CKE_TO_SPARE_CKE = 26,
            DISABLE_ECC_ARRAY_CHK = scomt::ody::ODC_MCBIST_SCOM_CCS_MODEQ_DISABLE_ECC_ARRAY_CHK,
            DISABLE_ECC_ARRAY_CORRECTION = scomt::ody::ODC_MCBIST_SCOM_CCS_MODEQ_DISABLE_ECC_ARRAY_CORRECTION,
            CFG_DGEN_FIXED_MODE = scomt::ody::ODC_MCBIST_SCOM_CCS_MODEQ_CFG_CCS_DGEN_FIXED_MODE,
            IDLE_PAT_ADDRESS_0_13 = scomt::ody::ODC_MCBIST_SCOM_CCS_MODEQ_CCS_IDLE_PAT_ADDRESS_0_13,
            IDLE_PAT_ADDRESS_0_13_LEN = scomt::ody::ODC_MCBIST_SCOM_CCS_MODEQ_CCS_IDLE_PAT_ADDRESS_0_13_LEN,
            NTTM_MODE = scomt::ody::ODC_MCBIST_SCOM_CCS_MODEQ_NTTM_MODE,
            NTTM_RW_DATA_DLY = scomt::ody::ODC_MCBIST_SCOM_CCS_MODEQ_NTTM_RW_DATA_DLY,
            NTTM_RW_DATA_DLY_LEN = scomt::ody::ODC_MCBIST_SCOM_CCS_MODEQ_NTTM_RW_DATA_DLY_LEN,
            DDR_PARITY_ENABLE = scomt::ody::ODC_MCBIST_SCOM_CCS_MODEQ_DDR_PARITY_ENABLE,
            IDLE_PAT_PARITY = scomt::ody::ODC_MCBIST_SCOM_CCS_MODEQ_CCS_IDLE_PAT_PARITY,
            PORT_SEL = scomt::ody::ODC_MCBIST_SCOM_CCS_MODEQ_CCS_PORT_SEL,
            PORT_SEL_LEN = scomt::ody::ODC_MCBIST_SCOM_CCS_MODEQ_CCS_PORT_SEL_LEN,

            // CCS CNTL
            CCS_START = scomt::ody::ODC_MCBIST_SCOM_CCS_CNTLQ_START,
            CCS_STOP = scomt::ody::ODC_MCBIST_SCOM_CCS_CNTLQ_STOP,

            // CCS STATQ
            CCS_IN_PROGRESS = scomt::ody::ODC_MCBIST_SCOM_CCS_STATQ_CCS_IP,

            // ARR0
            ARR0_CMD0_ADDRESS_0_13 = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD0_ADDRESS,
            ARR0_CMD0_ADDRESS_0_13_LEN = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD0_ADDRESS_LEN,
            ARR0_CMD0_CSN_0_1 = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD0_CSN,
            ARR0_CMD0_CSN_0_1_LEN = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD0_CSN_LEN,
            ARR0_CMD0_WRDATA_CSN = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD0_WRDATA_CSN,
            ARR0_CMD0_WRDATA_CSN_LEN = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD0_WRDATA_CSN_LEN,
            ARR0_CMD0_PARITY = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD0_PTY,
            ARR0_CMD0_RESETN = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD0_RESETN,
            ARR0_CMD0_ADDRESS_OP = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD0_ADDRESS_OP,
            ARR0_CMD0_ADDRESS_OP_LEN = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD0_ADDRESS_OP_LEN,
            ARR0_NESTED_LOOP_COUNT = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_NESTED_LOOP_CNT,
            ARR0_NESTED_LOOP_COUNT_LEN = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_NESTED_LOOP_CNT_LEN,
            ARR0_CMD0_CMD1_VLD = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD1_VLD,
            ARR0_CMD1_ADDRESS_0_13 = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD1_ADDRESS,
            ARR0_CMD1_ADDRESS_0_13_LEN = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD1_ADDRESS_LEN,
            ARR0_CMD1_CSN_0_1 = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD1_CSN,
            ARR0_CMD1_CSN_0_1_LEN = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD1_CSN_LEN,
            ARR0_CMD1_WRDATA_CSN = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD1_WRDATA_CSN,
            ARR0_CMD1_WRDATA_CSN_LEN = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD1_WRDATA_CSN_LEN,
            ARR0_CMD1_PARITY = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD1_PTY,
            ARR0_CMD1_RESETN = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD1_RESETN,
            ARR0_CMD1_ADDRESS_OP = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD1_ADDRESS_OP,
            ARR0_CMD1_ADDRESS_OP_LEN = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_CMD1_ADDRESS_OP_LEN,
            ARR0_PAUSE_INSTR = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_PAUSE_INSTR,
            ARR0_VAR_SEL = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_VAR_SEL,
            ARR0_VAR_SEL_LEN = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_VAR_SEL_LEN,
            ARR0_VAR_OP = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_VAR_OP,
            ARR0_VAR_OP_LEN = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00_VAR_OP_LEN,


            // ARR1
            ARR1_IDLES = scomt::ody::ODC_MCBIST_CCS_INST_ARR1_00_IDLE_CNT,
            ARR1_IDLES_LEN = scomt::ody::ODC_MCBIST_CCS_INST_ARR1_00_IDLE_CNT_LEN,
            ARR1_REPEAT_CMD_CNT = scomt::ody::ODC_MCBIST_CCS_INST_ARR1_00_REPEAT_CNT,
            ARR1_REPEAT_CMD_CNT_LEN = scomt::ody::ODC_MCBIST_CCS_INST_ARR1_00_REPEAT_CNT_LEN,
            ARR1_PADDING = scomt::ody::ODC_MCBIST_CCS_INST_ARR1_00_PADDING,
            ARR1_PADDING_LEN = scomt::ody::ODC_MCBIST_CCS_INST_ARR1_00_PADDING_LEN,
            ARR1_READ_COMPARE_REQUIRED = scomt::ody::ODC_MCBIST_CCS_INST_ARR1_00_READ_CMP,
            ARR1_END = scomt::ody::ODC_MCBIST_CCS_INST_ARR1_00_LAST_CMD,
            ARR1_READ_OR_WRITE_DATA = scomt::ody::ODC_MCBIST_CCS_INST_ARR1_00_RW_DATA,
            ARR1_READ_OR_WRITE_DATA_LEN = scomt::ody::ODC_MCBIST_CCS_INST_ARR1_00_RW_DATA_LEN,
            ARR1_FORCE_DATA = scomt::ody::ODC_MCBIST_CCS_INST_ARR1_00_FORCE_DATA,
            ARR1_PDA_WRITE = scomt::ody::ODC_MCBIST_CCS_INST_ARR1_00_PDA_WRITE,
            ARR1_GOTO_CMD = scomt::ody::ODC_MCBIST_CCS_INST_ARR1_00_GOTO_CMD,
            ARR1_GOTO_CMD_LEN = scomt::ody::ODC_MCBIST_CCS_INST_ARR1_00_GOTO_CMD_LEN,
            ARR1_BREAK_MODE = scomt::ody::ODC_MCBIST_CCS_INST_ARR1_00_BREAK_MODE,
            ARR1_BREAK_MODE_LEN = scomt::ody::ODC_MCBIST_CCS_INST_ARR1_00_BREAK_MODE_LEN,

            // CCS array constants
            CCS_ARRAY_LEN = 32,
            CCS_ARR0_START = scomt::ody::ODC_MCBIST_CCS_INST_ARR0_00,
            CCS_ARR1_START = scomt::ody::ODC_MCBIST_CCS_INST_ARR1_00,
        };

        ///
        /// @brief Enums for CCS return codes
        ///
        enum
        {
            // Success is defined as done-bit set, no others.
            STAT_QUERY_SUCCESS   = 0x4000000000000000,

            // Bit positions 3:5
            STAT_ERR_MASK        = 0x1800000000000000,
            STAT_READ_MISCOMPARE = 0x1000000000000000,
            STAT_UE_SUE          = 0x0800000000000000,

            // If the fail type isn't one of these, we're hung
            STAT_HUNG = 0x0ull,
        };

        // Map bits in the ARR0 register(s) to command address bits
        // For those familiar with DDR4, DDR4 had explicit command addresses for specific bits
        // However, DDR5 uses encoded commands, meaning that there are no explicit bits
        // For example, CID3 can and does hop to different addresses depending upon the command in question
        // As such, these enumerations are used to denote where each bit sits within the commands
        // All of these bits were generated by doing a look up between the Odyssey registers and the DDR5 JEDEC spec v1.7.1
        enum address_bits
        {
            CMD     = ARR0_CMD0_ADDRESS_0_13,
            CMD_LEN = 5,

            // Activates use Rows
            R0_3 = ARR0_CMD0_ADDRESS_0_13 + 2,
            R0_3_LEN = 4,
            R4_16 = ARR0_CMD1_ADDRESS_0_13,
            R4_16_LEN = ARR0_CMD1_ADDRESS_0_13_LEN - 1,

            BA0_1 = ARR0_CMD0_ADDRESS_0_13 + 6,
            BA0_1_LEN = 2,

            BG0_2 = ARR0_CMD0_ADDRESS_0_13 + 8,
            BG0_2_LEN = 3,

            CID0_2 = ARR0_CMD0_ADDRESS_0_13 + 11,
            CID0_2_LEN = 3,

            C3_C10 = ARR0_CMD1_ADDRESS_0_13 + 1,
            C3_C10_LEN = 8,

            WR_RD_CID3 = ARR0_CMD1_ADDRESS_0_13 + 13,
            PRE_REF_CID3 = ARR0_CMD0_ADDRESS_0_13 + 5,

            PDE_SRE = ARR0_CMD0_ADDRESS_0_13 + 10,
            PDE_ODT = ARR0_CMD0_ADDRESS_0_13 + 11,

            MRA0_7 = ARR0_CMD0_ADDRESS_0_13 + 5,
            MRA0_7_LEN = 8,

            CW = ARR0_CMD1_ADDRESS_0_13 + 10,
            AP = ARR0_CMD1_ADDRESS_0_13 + 10,

            SRE_FREQ_CHANGE = ARR0_CMD0_ADDRESS_0_13 + 9,
            SRE_VS_PDE = ARR0_CMD0_ADDRESS_0_13 + 10,

            REF_ALL = ARR0_CMD0_ADDRESS_0_13 + 10,
            REF_MAN = ARR0_CMD0_ADDRESS_0_13 + 9,

            MR_OP0_7 = ARR0_CMD1_ADDRESS_0_13,
            MR_OP0_7_LEN = 8,

            VREFCA = ARR0_CMD0_ADDRESS_0_13 + 12,
        };

        // Enumerations for the CCS idle/repeats padding
        enum delay_padding
        {
            // Note: using bit shifting throughout to ensure that the bit is in the proper order
            PADDING_NO_END = 0x100,
            PADDING_2_END  = PADDING_NO_END << 2,
            PADDING_4_END  = PADDING_NO_END << 4,
            NUM_MULTIPLIER_0 = 1 << 0,
            NUM_MULTIPLIER_2 = 1 << 2,
            NUM_MULTIPLIER_4 = 1 << 4,
            NUM_MULTIPLIER_8 = 1 << 8,
            REG_MULTIPLIER_0 = 0b00,
            REG_MULTIPLIER_2 = 0b01,
            REG_MULTIPLIER_4 = 0b10,
            REG_MULTIPLIER_8 = 0b11,
        };

        // Enumerations for WRDATA_CSN bits
        enum wrdata_csn
        {
            WRITE_DATA_PHASE0_POS = 17,
            WRITE_DATA_PHASE0_LEN = 2,
            WRITE_DATA_PHASE1_POS = 49,
            WRITE_DATA_PHASE1_LEN = 2,
        };

        // CSN Quad encoded settings - Not supported for Odyssey as we only have two ranks so we cannot have a quad encoded CS
        static constexpr std::pair<uint64_t, uint64_t> CS_N[mss::MAX_RANK_PER_DIMM] =
            {};

        // CSN Setup for Dual Direct Mode
        // Odyssey only has one DIMM and only has up to two ranks
        // However, attributes can have up to 4 ranks per DIMM -> keeping this constant for consistent code between MC's
        // For Odyssey, CS2/3 (the second number in the pair) are command 1's chip selects
        static constexpr std::pair<uint64_t, uint64_t> CS_ND[mss::MAX_RANK_PER_DIMM] =
        {
            // CMD0 CS0 L CMD0 CS1 H => CMD1 CS0 => H CMD1 CS1 => H Rank 0
            { 0b01, 0b11 },

            // CMD0 CS0 H CMD0 CS1 L => CMD1 CS0 => H CMD1 CS1 => H Rank 1
            { 0b10, 0b11 },

            // Note: Invalid for Odyssey as we can only have two ranks
            // CMD0 CS0 H CMD0 CS1 H => CMD1 CS0 => L CMD1 CS1 => H Rank 2
            { 0b11, 0b11 },

            // Note: Invalid for Odyssey as we can only have two ranks
            // CMD0 CS0 H CMD0 CS1 H => CMD1 CS0 => H CMD1 CS1 => L Rank 3
            { 0b11, 0b11 },
        };

        ///
        /// @brief Get and perform CS tied operation if needed
        ///
        /// @param[in] i_target PORT target type
        /// @param[in] i_CS01 CS01
        /// @param[in,out] io_CS23 CS23, to overwrite if tied
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff success, else error code
        ///
        static fapi2::ReturnCode cs_tied(
            const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
            const uint64_t i_CS01,
            uint64_t& io_CS23)
        {
            // Not tied, and we leave them alone
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Tie DIMM0 and DIMM1 ODTs if needed, when CS's are tied
        ///
        /// @param[in] i_target PORT target type
        /// @param[in,out] io_ccs_value CCS values with ODT fields
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        static fapi2::ReturnCode odt_tied(
            const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
            fapi2::buffer<uint8_t>& io_ccs_value)
        {
            // Not tied, and we leave them alone
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Gets if this port has an RCD
        /// @param[in] i_target the port target on which to operate
        /// @param[out] o_has_rcd true if this port has an RCD
        /// @return SUCCESS iff the code executes successfully
        ///
        static fapi2::ReturnCode get_has_rcd(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                             bool& o_has_rcd)
        {
            // TK replace this code when we have the methodology to get an RCD for odyssey
            //return mss::dimm::has_rcd<mss::mc_type::ODYSSEY>(i_target, o_has_rcd);
            // Assuming no RCD for now
            o_has_rcd = false;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Gets the attribute for checking our rank configuration
        /// @param[in] i_target the port target on which to operate
        /// @param[out] o_ranks the rank data
        /// @return The fully setup nimbus error
        ///
        static fapi2::ODY_CCS_HUNG_TRYING_TO_STOP setup_trying_to_stop_err(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
                i_target)
        {
            return fapi2::ODY_CCS_HUNG_TRYING_TO_STOP().set_MC_TARGET(i_target);
        }

        // Lab values
        static constexpr uint64_t LAB_MRS_CMD = 0x6000000000000000;
};

#endif
