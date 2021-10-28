/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/ecc/ecc_traits_explorer.H $ */
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
/// @file ecc_traits_explorer.H
/// @brief Traits class for the MC ECC syndrome registers
///
// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_ECC_TRAITS_EXPLORER_H_
#define _MSS_ECC_TRAITS_EXPLORER_H_

#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <explorer_scom_addresses_fixes.H>
#include <explorer_scom_addresses_fld_fixes.H>
#include <generic/memory/lib/ecc/ecc_traits.H>
#include <lib/shared/exp_consts.H>

namespace mss
{

///
/// @class eccMCTraits
/// @brief a collection of traits associated with the Explorer memory controller
///
template<>
class eccMCTraits<mc_type::EXPLORER>
{
    public:
        static constexpr fapi2::TargetType MEM_PORT_TARGET_TYPE = fapi2::TARGET_TYPE_MEM_PORT;
        static constexpr fapi2::TargetType MC_TARGET_TYPE = fapi2::TARGET_TYPE_OCMB_CHIP;
};

///
/// @class eccTraits
/// @brief a collection of traits associated with the Explorer Mem Port ECC interface
///
template<>
class eccTraits<mc_type::EXPLORER, fapi2::TARGET_TYPE_MEM_PORT>
{
    public:
        // MCA ECC registers - must be 64 bits.
        static constexpr uint64_t HARDWARE_MS0_REG = EXPLR_RDF_HWMS0;
        static constexpr uint64_t HARDWARE_MS1_REG = EXPLR_RDF_HWMS1;
        static constexpr uint64_t HARDWARE_MS2_REG = EXPLR_RDF_HWMS2;
        static constexpr uint64_t HARDWARE_MS3_REG = EXPLR_RDF_HWMS3;
        static constexpr uint64_t HARDWARE_MS4_REG = EXPLR_RDF_HWMS4;
        static constexpr uint64_t HARDWARE_MS5_REG = EXPLR_RDF_HWMS5;
        static constexpr uint64_t HARDWARE_MS6_REG = EXPLR_RDF_HWMS6;
        static constexpr uint64_t HARDWARE_MS7_REG = EXPLR_RDF_HWMS7;
        static constexpr uint64_t FIRMWARE_MS0_REG = EXPLR_RDF_FWMS0;
        static constexpr uint64_t FIRMWARE_MS1_REG = EXPLR_RDF_FWMS1;
        static constexpr uint64_t FIRMWARE_MS2_REG = EXPLR_RDF_FWMS2;
        static constexpr uint64_t FIRMWARE_MS3_REG = EXPLR_RDF_FWMS3;
        static constexpr uint64_t FIRMWARE_MS4_REG = EXPLR_RDF_FWMS4;
        static constexpr uint64_t FIRMWARE_MS5_REG = EXPLR_RDF_FWMS5;
        static constexpr uint64_t FIRMWARE_MS6_REG = EXPLR_RDF_FWMS6;
        static constexpr uint64_t FIRMWARE_MS7_REG = EXPLR_RDF_FWMS7;
        static constexpr uint64_t MARK_SHADOW_REG = EXPLR_RDF_MSR;
        static constexpr uint64_t ECC_MAX_MRANK_PER_PORT = exp::MAX_MRANK_PER_PORT;
        static constexpr uint64_t ECC_MAX_DQ_BITS = exp::MAX_DQ_BITS_PER_PORT;
        static constexpr uint64_t ECC_MAX_SYMBOLS = exp::MAX_SYMBOLS_PER_PORT;


        // MCBIST ECC registers - Register API uses an MEMPORT target instead
        // of MCBIST since MEMPORT's relative position is needed to find
        // correct reg+field
        constexpr static const uint64_t MAINLINE_NCE_REGS[] =
        {
            EXPLR_MCBIST_MBNCER0Q,
        };

        constexpr static const uint64_t MAINLINE_RCE_REGS[] =
        {
            EXPLR_MCBIST_MBRCER0Q,
        };

        constexpr static const uint64_t MAINLINE_MPE_REGS[] =
        {
            EXPLR_MCBIST_MBMPER0Q,
        };

        constexpr static const uint64_t MAINLINE_UE_REGS[] =
        {
            EXPLR_MCBIST_MBUER0Q,
        };

        constexpr static const uint64_t MAINLINE_AUE_REGS[] =
        {
            EXPLR_MCBIST_MBAUER0Q,
        };

        constexpr static const uint64_t ERROR_VECTOR_REGS[] =
        {
            EXPLR_MCBIST_MBSEVR0Q,
        };

        // Fields, can be any size.
        enum
        {
            HARDWARE_MS_CHIPMARK = EXPLR_RDF_HWMS0_CHIPMARK,
            HARDWARE_MS_CHIPMARK_LEN = EXPLR_RDF_HWMS0_CHIPMARK_LEN,
            HARDWARE_MS_CONFIRMED = EXPLR_RDF_HWMS0_CONFIRMED,
            HARDWARE_MS_EXIT1 = EXPLR_RDF_HWMS0_EXIT_1,
            FIRMWARE_MS_MARK = EXPLR_RDF_FWMS0_MARK,
            FIRMWARE_MS_MARK_LEN = EXPLR_RDF_FWMS0_MARK_LEN,
            FIRMWARE_MS_TYPE = EXPLR_RDF_FWMS0_TYPE,
            FIRMWARE_MS_REGION = EXPLR_RDF_FWMS0_REGION,
            FIRMWARE_MS_REGION_LEN = EXPLR_RDF_FWMS0_REGION_LEN,
            FIRMWARE_MS_ADDRESS = EXPLR_RDF_FWMS0_ADDRESS,
            FIRMWARE_MS_ADDRESS_LEN = EXPLR_RDF_FWMS0_ADDRESS_LEN,
            FIRMWARE_MS_EXIT1 = EXPLR_RDF_FWMS0_EXIT_1,
            NCE_ADDR_TRAP = EXPLR_MCBIST_MBNCER0Q_PORT_0_MAINLINE_NCE_ADDR_TRAP,
            NCE_ADDR_TRAP_LEN = EXPLR_MCBIST_MBNCER0Q_PORT_0_MAINLINE_NCE_ADDR_TRAP_LEN,
            NCE_ON_RCE = EXPLR_MCBIST_MBNCER0Q_PORT_0_MAINLINE_NCE_ON_RCE,
            NCE_IS_TCE = EXPLR_MCBIST_MBNCER0Q_PORT_0_MAINLINE_NCE_IS_TCE,
            RCE_ADDR_TRAP = EXPLR_MCBIST_MBRCER0Q_PORT_0_MAINLINE_RCE_ADDR_TRAP,
            RCE_ADDR_TRAP_LEN = EXPLR_MCBIST_MBRCER0Q_PORT_0_MAINLINE_RCE_ADDR_TRAP_LEN,
            MPE_ADDR_TRAP = EXPLR_MCBIST_MBMPER0Q_PORT_0_MAINLINE_MPE_ADDR_TRAP,
            MPE_ADDR_TRAP_LEN = EXPLR_MCBIST_MBMPER0Q_PORT_0_MAINLINE_MPE_ADDR_TRAP_LEN,
            MPE_ON_RCE = EXPLR_MCBIST_MBMPER0Q_PORT_0_MAINLINE_MPE_ON_RCE,
            UE_ADDR_TRAP = EXPLR_MCBIST_MBUER0Q_PORT_0_MAINLINE_UE_ADDR_TRAP,
            UE_ADDR_TRAP_LEN = EXPLR_MCBIST_MBUER0Q_PORT_0_MAINLINE_UE_ADDR_TRAP_LEN,
            AUE_ADDR_TRAP = EXPLR_MCBIST_MBAUER0Q_PORT_0_MAINLINE_AUE_ADDR_TRAP,
            AUE_ADDR_TRAP_LEN = EXPLR_MCBIST_MBAUER0Q_PORT_0_MAINLINE_AUE_ADDR_TRAP_LEN,
            P0_NCE_GALOIS = EXPLR_MCBIST_MBSEVR0Q_PORT_0_MAINLINE_NCE_GALOIS_FIELD,
            P0_NCE_GALOIS_LEN = EXPLR_MCBIST_MBSEVR0Q_PORT_0_MAINLINE_NCE_GALOIS_FIELD_LEN,
            P0_NCE_MAGNITUDE = EXPLR_MCBIST_MBSEVR0Q_PORT_0_MAINLINE_NCE_MAGNITUDE_FIELD,
            P0_NCE_MAGNITUDE_LEN = EXPLR_MCBIST_MBSEVR0Q_PORT_0_MAINLINE_NCE_MAGNITUDE_FIELD_LEN,
            P0_TCE_GALOIS = EXPLR_MCBIST_MBSEVR0Q_PORT_0_MAINLINE_TCE_GALOIS_FIELD,
            P0_TCE_GALOIS_LEN = EXPLR_MCBIST_MBSEVR0Q_PORT_0_MAINLINE_TCE_GALOIS_FIELD_LEN,
            P0_TCE_MAGNITUDE = EXPLR_MCBIST_MBSEVR0Q_PORT_0_MAINLINE_TCE_MAGNITUDE_FIELD,
            P0_TCE_MAGNITUDE_LEN = EXPLR_MCBIST_MBSEVR0Q_PORT_0_MAINLINE_TCE_MAGNITUDE_FIELD_LEN,
            CURRENT_ADDR_TRAP = EXPLR_MCBIST_MCBMCATQ_CFG_CURRENT_ADDR_TRAP,
            CURRENT_ADDR_TRAP_LEN = EXPLR_MCBIST_MCBMCATQ_CFG_CURRENT_ADDR_TRAP_LEN,
            CURRENT_PORT = EXPLR_MCBIST_MCBMCATQ_CFG_CURRENT_PORT_TRAP,
            CURRENT_PORT_LEN = EXPLR_MCBIST_MCBMCATQ_CFG_CURRENT_PORT_TRAP_LEN,
            CURRENT_DIMM = EXPLR_MCBIST_MCBMCATQ_CFG_CURRENT_DIMM_TRAP,
            SHADOW_CHIPMARK = EXPLR_RDF_MSR_CHIPMARK,
            SHADOW_CHIPMARK_LEN = EXPLR_RDF_MSR_CHIPMARK_LEN,
            SHADOW_RANK = EXPLR_RDF_MSR_RANK,
            SHADOW_RANK_LEN = EXPLR_RDF_MSR_RANK_LEN,

        };

        // Symbol to Galois code mapping table for Explorer
        constexpr static const uint8_t symbol2galois[] =
        {
            0x80, 0xa0, 0x90, 0xf0,
            0x08, 0x0a, 0x09, 0x0f,
            0x98, 0xda, 0xb9, 0x7f,
            0x91, 0xd7, 0xb2, 0x78,
            0x28, 0xea, 0x49, 0x9f,
            0x9a, 0xd4, 0xbd, 0x76,
            0x60, 0xb0, 0xc0, 0x20,
            0x06, 0x0b, 0x0c, 0x02,
            0xc6, 0xfb, 0x1c, 0x42,
            0xca, 0xf4, 0x1d, 0x46,
            0xd6, 0x8b, 0x3c, 0xc2,
            0xcb, 0xf3, 0x1f, 0x4e,
            0xe0, 0x10, 0x50, 0xd0,
            0x0e, 0x01, 0x05, 0x0d,
            0x5e, 0x21, 0xa5, 0x3d,
            0x5b, 0x23, 0xaf, 0x3e,
            0xfe, 0x61, 0x75, 0x5d,
            0x51, 0x27, 0xa2, 0x38
        };

        // Symbol to DQ index mapping table for Explorer
        // dq = symbol2dq[symbol]
        constexpr static const uint8_t symbol2dq[] =
        {
            39, 38, 37, 36,
            35, 34, 33, 32,
            79, 78, 77, 76,
            71, 70, 69, 68,
            63, 62, 61, 60,
            55, 54, 53, 52,
            31, 30, 29, 28,
            23, 22, 21, 20,
            15, 14, 13, 12,
            7,  6,  5,  4,
            75, 74, 73, 72,
            67, 66, 65, 64,
            59, 58, 57, 56,
            51, 50, 49, 48,
            27, 26, 25, 24,
            19, 18, 17, 16,
            11, 10, 9,  8,
            3,  2,  1,  0
        };

};

///
/// @class eccTraits
/// @brief a collection of traits associated with the Axone MC ECC interface
///
template<>
class eccTraits<mc_type::EXPLORER, fapi2::TARGET_TYPE_OCMB_CHIP>
{
    public:
        // MCBIST ECC registers - must be 64 bits.
        static constexpr uint64_t READ_ERROR_COUNT_REG0 = EXPLR_MCBIST_MBSEC0Q;
        static constexpr uint64_t READ_ERROR_COUNT_REG1 = EXPLR_MCBIST_MBSEC1Q;
        static constexpr uint64_t MARK_SYMBOL_COUNT_REG = EXPLR_MCBIST_MBSMSECQ;
        static constexpr uint64_t MODAL_SYM_COUNT0_REG = EXPLR_MCBIST_MBSSYMEC0Q;
        static constexpr uint64_t MODAL_SYM_COUNT1_REG = EXPLR_MCBIST_MBSSYMEC1Q;
        static constexpr uint64_t MODAL_SYM_COUNT2_REG = EXPLR_MCBIST_MBSSYMEC2Q;
        static constexpr uint64_t MODAL_SYM_COUNT3_REG = EXPLR_MCBIST_MBSSYMEC3Q;
        static constexpr uint64_t MODAL_SYM_COUNT4_REG = EXPLR_MCBIST_MBSSYMEC4Q;
        static constexpr uint64_t MODAL_SYM_COUNT5_REG = EXPLR_MCBIST_MBSSYMEC5Q;
        static constexpr uint64_t MODAL_SYM_COUNT6_REG = EXPLR_MCBIST_MBSSYMEC6Q;
        static constexpr uint64_t MODAL_SYM_COUNT7_REG = EXPLR_MCBIST_MBSSYMEC7Q;
        static constexpr uint64_t MODAL_SYM_COUNT8_REG = EXPLR_MCBIST_MBSSYMEC8Q;
        static constexpr uint64_t MODAL_SYM_COUNT9_REG = EXPLR_MCBIST_MBSSYMEC9Q;
        static constexpr uint64_t MPE_ADDR_TRAP_REG = EXPLR_MCBIST_MCBMCATQ;
        static constexpr uint64_t ECC_MAX_MRANK_PER_PORT = exp::MAX_MRANK_PER_PORT;
        static constexpr uint64_t ECC_MAX_DQ_BITS = exp::MAX_DQ_BITS_PER_PORT;
        static constexpr uint64_t ECC_MAX_SYMBOLS = exp::MAX_SYMBOLS_PER_PORT;

        // Stores the symbol counter registers in a vector for easier access for MCBIST
        static constexpr uint64_t REQUIRED_NUMBER_OF_SYMBOL_REGS = 10;
        static const std::vector<uint64_t> SYMBOL_COUNT_REG;

        // Fields, can be any size.
        enum
        {
            INTERMITTENT_CE_COUNT = EXPLR_MCBIST_MBSEC0Q_INTERMITTENT_CE_COUNT,
            INTERMITTENT_CE_COUNT_LEN = EXPLR_MCBIST_MBSEC0Q_INTERMITTENT_CE_COUNT_LEN,
            SOFT_CE_COUNT = EXPLR_MCBIST_MBSEC0Q_SOFT_CE_COUNT,
            SOFT_CE_COUNT_LEN = EXPLR_MCBIST_MBSEC0Q_SOFT_CE_COUNT_LEN,
            HARD_CE_COUNT = EXPLR_MCBIST_MBSEC0Q_HARD_CE_COUNT,
            HARD_CE_COUNT_LEN = EXPLR_MCBIST_MBSEC0Q_HARD_CE_COUNT_LEN,
            INTERMITTENT_MCE_COUNT = EXPLR_MCBIST_MBSEC0Q_INTERMITTENT_MCE_COUNT,
            INTERMITTENT_MCE_COUNT_LEN = EXPLR_MCBIST_MBSEC0Q_INTERMITTENT_MCE_COUNT_LEN,
            SOFT_MCE_COUNT = EXPLR_MCBIST_MBSEC0Q_SOFT_MCE_COUNT,
            SOFT_MCE_COUNT_LEN = EXPLR_MCBIST_MBSEC0Q_SOFT_MCE_COUNT_LEN,
            HARD_MCE_COUNT = EXPLR_MCBIST_MBSEC1Q_HARD_MCE_COUNT,
            HARD_MCE_COUNT_LEN = EXPLR_MCBIST_MBSEC1Q_HARD_MCE_COUNT_LEN,
            ICE_COUNT = EXPLR_MCBIST_MBSEC1Q_ICE_COUNT,
            ICE_COUNT_LEN = EXPLR_MCBIST_MBSEC1Q_ICE_COUNT_LEN,
            UE_COUNT = EXPLR_MCBIST_MBSEC1Q_UE_COUNT,
            UE_COUNT_LEN = EXPLR_MCBIST_MBSEC1Q_UE_COUNT_LEN,
            AUE_COUNT = EXPLR_MCBIST_MBSEC1Q_AUE,
            AUE_COUNT_LEN = EXPLR_MCBIST_MBSEC1Q_AUE_LEN,
            RCE_COUNT = EXPLR_MCBIST_MBSEC1Q_RCE_COUNT,
            RCE_COUNT_LEN = EXPLR_MCBIST_MBSEC1Q_RCE_COUNT_LEN,
            SYMBOL0_COUNT = EXPLR_MCBIST_MBSMSECQ_MCE_SYMBOL0_COUNT,
            SYMBOL0_COUNT_LEN = EXPLR_MCBIST_MBSMSECQ_MCE_SYMBOL0_COUNT_LEN,
            SYMBOL1_COUNT = EXPLR_MCBIST_MBSMSECQ_MCE_SYMBOL1_COUNT,
            SYMBOL1_COUNT_LEN = EXPLR_MCBIST_MBSMSECQ_MCE_SYMBOL1_COUNT_LEN,
            SYMBOL2_COUNT = EXPLR_MCBIST_MBSMSECQ_MCE_SYMBOL2_COUNT,
            SYMBOL2_COUNT_LEN = EXPLR_MCBIST_MBSMSECQ_MCE_SYMBOL2_COUNT_LEN,
            SYMBOL3_COUNT = EXPLR_MCBIST_MBSMSECQ_MCE_SYMBOL3_COUNT,
            SYMBOL3_COUNT_LEN = EXPLR_MCBIST_MBSMSECQ_MCE_SYMBOL3_COUNT_LEN,
            MODAL_SYMBOL_COUNTER_00 = EXPLR_MCBIST_MBSSYMEC0Q_MODAL_SYMBOL_COUNTER_00,
            MODAL_SYMBOL_COUNTER_00_LEN = EXPLR_MCBIST_MBSSYMEC0Q_MODAL_SYMBOL_COUNTER_00_LEN,
            MODAL_SYMBOL_COUNTER_01 = EXPLR_MCBIST_MBSSYMEC0Q_MODAL_SYMBOL_COUNTER_01,
            MODAL_SYMBOL_COUNTER_01_LEN = EXPLR_MCBIST_MBSSYMEC0Q_MODAL_SYMBOL_COUNTER_01_LEN,
            MODAL_SYMBOL_COUNTER_02 = EXPLR_MCBIST_MBSSYMEC0Q_MODAL_SYMBOL_COUNTER_02,
            MODAL_SYMBOL_COUNTER_02_LEN = EXPLR_MCBIST_MBSSYMEC0Q_MODAL_SYMBOL_COUNTER_02_LEN,
            MODAL_SYMBOL_COUNTER_03 = EXPLR_MCBIST_MBSSYMEC0Q_MODAL_SYMBOL_COUNTER_03,
            MODAL_SYMBOL_COUNTER_03_LEN = EXPLR_MCBIST_MBSSYMEC0Q_MODAL_SYMBOL_COUNTER_03_LEN,
            MODAL_SYMBOL_COUNTER_04 = EXPLR_MCBIST_MBSSYMEC0Q_MODAL_SYMBOL_COUNTER_04,
            MODAL_SYMBOL_COUNTER_04_LEN = EXPLR_MCBIST_MBSSYMEC0Q_MODAL_SYMBOL_COUNTER_04_LEN,
            MODAL_SYMBOL_COUNTER_05 = EXPLR_MCBIST_MBSSYMEC0Q_MODAL_SYMBOL_COUNTER_05,
            MODAL_SYMBOL_COUNTER_05_LEN = EXPLR_MCBIST_MBSSYMEC0Q_MODAL_SYMBOL_COUNTER_05_LEN,
            MODAL_SYMBOL_COUNTER_06 = EXPLR_MCBIST_MBSSYMEC0Q_MODAL_SYMBOL_COUNTER_06,
            MODAL_SYMBOL_COUNTER_06_LEN = EXPLR_MCBIST_MBSSYMEC0Q_MODAL_SYMBOL_COUNTER_06_LEN,
            MODAL_SYMBOL_COUNTER_07 = EXPLR_MCBIST_MBSSYMEC0Q_MODAL_SYMBOL_COUNTER_07,
            MODAL_SYMBOL_COUNTER_07_LEN = EXPLR_MCBIST_MBSSYMEC0Q_MODAL_SYMBOL_COUNTER_07_LEN,

            // and a couple constants
            NUM_MBSSYM_REGS = 10,
            MODAL_SYMBOL_COUNTERS_PER_REG = 8,
        };

};

} // close namespace mss

#endif
