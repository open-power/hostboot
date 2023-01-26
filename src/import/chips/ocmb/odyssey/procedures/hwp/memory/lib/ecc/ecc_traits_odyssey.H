/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ecc/ecc_traits_odyssey.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
/// @file ecc_traits_odyssey.H
/// @brief Traits class for the MC ECC syndrome registers
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Matt Hickman <Matthew.Hickman@ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_ECC_TRAITS_ODYSSEY_H_
#define _MSS_ECC_TRAITS_ODYSSEY_H_

#include <fapi2.H>
#include <lib/shared/ody_consts.H>
#include <generic/memory/lib/ecc/ecc_traits.H>
#include <ody_scom_ody.H>

namespace mss
{

///
/// @class eccMCTraits
/// @brief a collection of traits associated with the Odyssey memory controller
///
template<>
class eccMCTraits<mc_type::ODYSSEY>
{
    public:
        static constexpr fapi2::TargetType MEM_PORT_TARGET_TYPE = fapi2::TARGET_TYPE_MEM_PORT;
        static constexpr fapi2::TargetType MC_TARGET_TYPE = fapi2::TARGET_TYPE_OCMB_CHIP;
};

///
/// @class eccTraits
/// @brief a collection of traits associated with the Odyssey Mem Port ECC interface
///
template<>
class eccTraits<mc_type::ODYSSEY, fapi2::TARGET_TYPE_MEM_PORT>
{
    public:
        // Mark store registers (port specific - scom using MEM_PORT target)
        static constexpr uint64_t HARDWARE_MS0_REG = scomt::ody::ODC_RDF0_SCOM_HWMS0;
        static constexpr uint64_t HARDWARE_MS1_REG = scomt::ody::ODC_RDF0_SCOM_HWMS1;
        static constexpr uint64_t HARDWARE_MS2_REG = scomt::ody::ODC_RDF0_SCOM_HWMS2;
        static constexpr uint64_t HARDWARE_MS3_REG = scomt::ody::ODC_RDF0_SCOM_HWMS3;
        static constexpr uint64_t HARDWARE_MS4_REG = scomt::ody::ODC_RDF0_SCOM_HWMS4;
        static constexpr uint64_t HARDWARE_MS5_REG = scomt::ody::ODC_RDF0_SCOM_HWMS5;
        static constexpr uint64_t HARDWARE_MS6_REG = scomt::ody::ODC_RDF0_SCOM_HWMS6;
        static constexpr uint64_t HARDWARE_MS7_REG = scomt::ody::ODC_RDF0_SCOM_HWMS7;
        static constexpr uint64_t FIRMWARE_MS0_REG = scomt::ody::ODC_RDF0_SCOM_FWMS0;
        static constexpr uint64_t FIRMWARE_MS1_REG = scomt::ody::ODC_RDF0_SCOM_FWMS1;
        static constexpr uint64_t FIRMWARE_MS2_REG = scomt::ody::ODC_RDF0_SCOM_FWMS2;
        static constexpr uint64_t FIRMWARE_MS3_REG = scomt::ody::ODC_RDF0_SCOM_FWMS3;
        static constexpr uint64_t FIRMWARE_MS4_REG = scomt::ody::ODC_RDF0_SCOM_FWMS4;
        static constexpr uint64_t FIRMWARE_MS5_REG = scomt::ody::ODC_RDF0_SCOM_FWMS5;
        static constexpr uint64_t FIRMWARE_MS6_REG = scomt::ody::ODC_RDF0_SCOM_FWMS6;
        static constexpr uint64_t FIRMWARE_MS7_REG = scomt::ody::ODC_RDF0_SCOM_FWMS7;

        // Mark shadow register (port specific - scom using MEM_PORT target)
        static constexpr uint64_t MARK_SHADOW_REG = scomt::ody::ODC_RDF0_SCOM_MSR;

        // TODO:ZEN-MST:1781  Verify the number of ranks for the ECC traits
        static constexpr uint64_t ECC_MAX_MRANK_PER_PORT = ody::MAX_MRANK_PER_PORT;
        static constexpr uint64_t ECC_MAX_DQ_BITS = ody::MAX_DQ_BITS_PER_PORT;
        static constexpr uint64_t ECC_MAX_SYMBOLS = ody::MAX_SYMBOLS_PER_PORT;


        // MCBIST ECC registers
        constexpr static const uint64_t MAINLINE_NCE_REGS[] =
        {
            scomt::ody::ODC_MCBIST_SCOM_MBNCER0Q,
            scomt::ody::ODC_MCBIST_SCOM_MBNCER0Q,
        };

        constexpr static const uint64_t MAINLINE_RCE_REGS[] =
        {
            scomt::ody::ODC_MCBIST_SCOM_MBRCER0Q,
            scomt::ody::ODC_MCBIST_SCOM_MBRCER0Q,
        };

        constexpr static const uint64_t MAINLINE_MPE_REGS[] =
        {
            scomt::ody::ODC_MCBIST_SCOM_MBMPER0Q,
            scomt::ody::ODC_MCBIST_SCOM_MBMPER0Q,
        };

        constexpr static const uint64_t MAINLINE_UE_REGS[] =
        {
            scomt::ody::ODC_MCBIST_SCOM_MBUER0Q,
            scomt::ody::ODC_MCBIST_SCOM_MBUER0Q,
        };

        constexpr static const uint64_t MAINLINE_AUE_REGS[] =
        {
            scomt::ody::ODC_MCBIST_SCOM_MBAUER0Q,
            scomt::ody::ODC_MCBIST_SCOM_MBAUER0Q,
        };

        constexpr static const uint64_t ERROR_VECTOR_REGS[] =
        {
            scomt::ody::ODC_MCBIST_SCOM_MBSEVR0Q,
            scomt::ody::ODC_MCBIST_SCOM_MBSEVR0Q,
        };

        // Fields
        enum
        {
            HARDWARE_MS_CHIPMARK = scomt::ody::ODC_RDF0_SCOM_HWMS0_CHIPMARK,
            HARDWARE_MS_CHIPMARK_LEN = scomt::ody::ODC_RDF0_SCOM_HWMS0_CHIPMARK_LEN,
            HARDWARE_MS_CONFIRMED = scomt::ody::ODC_RDF0_SCOM_HWMS0_CONFIRMED,
            HARDWARE_MS_EXIT1 = scomt::ody::ODC_RDF0_SCOM_HWMS0_EXIT_1,
            FIRMWARE_MS_MARK = scomt::ody::ODC_RDF0_SCOM_FWMS0_MARK,
            FIRMWARE_MS_MARK_LEN = scomt::ody::ODC_RDF0_SCOM_FWMS0_MARK_LEN,
            FIRMWARE_MS_TYPE = scomt::ody::ODC_RDF0_SCOM_FWMS0_TYPE,
            FIRMWARE_MS_REGION = scomt::ody::ODC_RDF0_SCOM_FWMS0_REGION,
            FIRMWARE_MS_REGION_LEN = scomt::ody::ODC_RDF0_SCOM_FWMS0_REGION_LEN,
            FIRMWARE_MS_ADDRESS = scomt::ody::ODC_RDF0_SCOM_FWMS0_ADDRESS,
            FIRMWARE_MS_ADDRESS_LEN = scomt::ody::ODC_RDF0_SCOM_FWMS0_ADDRESS_LEN,
            FIRMWARE_MS_EXIT1 = scomt::ody::ODC_RDF0_SCOM_FWMS0_EXIT_1,
            NCE_ADDR_TRAP = scomt::ody::ODC_MCBIST_SCOM_MBNCER0Q_ADDR_TRAP,
            NCE_ADDR_TRAP_LEN = scomt::ody::ODC_MCBIST_SCOM_MBNCER0Q_ADDR_TRAP_LEN,
            NCE_ON_RCE = scomt::ody::ODC_MCBIST_SCOM_MBNCER0Q_ON_RCE,
            NCE_IS_TCE = scomt::ody::ODC_MCBIST_SCOM_MBNCER0Q_IS_TCE,
            RCE_ADDR_TRAP = scomt::ody::ODC_MCBIST_SCOM_MBRCER0Q_PORT_0_MAINLINE_RCE_ADDR_TRAP,
            RCE_ADDR_TRAP_LEN = scomt::ody::ODC_MCBIST_SCOM_MBRCER0Q_PORT_0_MAINLINE_RCE_ADDR_TRAP_LEN,
            MPE_ADDR_TRAP = scomt::ody::ODC_MCBIST_SCOM_MBMPER0Q_PORT_0_MAINLINE_MPE_ADDR_TRAP,
            MPE_ADDR_TRAP_LEN = scomt::ody::ODC_MCBIST_SCOM_MBMPER0Q_PORT_0_MAINLINE_MPE_ADDR_TRAP_LEN,
            MPE_ON_RCE = scomt::ody::ODC_MCBIST_SCOM_MBMPER0Q_PORT_0_MAINLINE_MPE_ON_RCE,
            UE_ADDR_TRAP = scomt::ody::ODC_MCBIST_SCOM_MBUER0Q_PORT_0_MAINLINE_UE_ADDR_TRAP,
            UE_ADDR_TRAP_LEN = scomt::ody::ODC_MCBIST_SCOM_MBUER0Q_PORT_0_MAINLINE_UE_ADDR_TRAP_LEN,
            AUE_ADDR_TRAP = scomt::ody::ODC_MCBIST_SCOM_MBAUER0Q_PORT_0_MAINLINE_AUE_ADDR_TRAP,
            AUE_ADDR_TRAP_LEN = scomt::ody::ODC_MCBIST_SCOM_MBAUER0Q_PORT_0_MAINLINE_AUE_ADDR_TRAP_LEN,
            P0_NCE_GALOIS = scomt::ody::ODC_MCBIST_SCOM_MBSEVR0Q_0_MAINLINE_NCE_GALOIS_FIELD,
            P0_NCE_GALOIS_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSEVR0Q_0_MAINLINE_NCE_GALOIS_FIELD_LEN,
            P0_NCE_MAGNITUDE = scomt::ody::ODC_MCBIST_SCOM_MBSEVR0Q_0_MAINLINE_NCE_MAGNITUDE_FIELD,
            P0_NCE_MAGNITUDE_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSEVR0Q_0_MAINLINE_NCE_MAGNITUDE_FIELD_LEN,
            P0_TCE_GALOIS = scomt::ody::ODC_MCBIST_SCOM_MBSEVR0Q_0_MAINLINE_TCE_GALOIS_FIELD,
            P0_TCE_GALOIS_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSEVR0Q_0_MAINLINE_TCE_GALOIS_FIELD_LEN,
            P0_TCE_MAGNITUDE = scomt::ody::ODC_MCBIST_SCOM_MBSEVR0Q_0_MAINLINE_TCE_MAGNITUDE_FIELD,
            P0_TCE_MAGNITUDE_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSEVR0Q_0_MAINLINE_TCE_MAGNITUDE_FIELD_LEN,
            CURRENT_ADDR_TRAP = scomt::ody::ODC_MCBIST_SCOM_MCBMCATQ_ADDR_TRAP,
            CURRENT_ADDR_TRAP_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBMCATQ_ADDR_TRAP_LEN,
            CURRENT_PORT = scomt::ody::ODC_MCBIST_SCOM_MCBMCATQ_PORT_TRAP,
            CURRENT_PORT_LEN = scomt::ody::ODC_MCBIST_SCOM_MCBMCATQ_PORT_TRAP_LEN,
            CURRENT_DIMM = scomt::ody::ODC_MCBIST_SCOM_MCBMCATQ_DIMM_TRAP,
            SHADOW_CHIPMARK = scomt::ody::ODC_RDF0_SCOM_MSR_CHIPMARK,
            SHADOW_CHIPMARK_LEN = scomt::ody::ODC_RDF0_SCOM_MSR_CHIPMARK_LEN,
            SHADOW_RANK = scomt::ody::ODC_RDF0_SCOM_MSR_RANK,
            SHADOW_RANK_LEN = scomt::ody::ODC_RDF0_SCOM_MSR_RANK_LEN,

        };

        // Symbol to Galois code mapping table for Odyssey x4
        // Note: in x8 mode, we don't use symbols 8-39
        // TODO Zen:MST-1420 Create specialization of restore_repairs for x8 if we need it
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

        // Symbol to DQ index mapping table for Odyssey x4
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

        // Symbol to DQ index mapping table for Odyssey x8
        // dq = symbol2dq[symbol]
        // Note that in x8 mode each symbol is for 2 DQ bits, so we encode only the higher of the two here
        // For example, symbol0 is for DQ47 and DQ46
        // Also, we ignore symbols 8-39 just like in the symbol2galois table
        // TODO Zen:MST-1420 Create specialization of restore_repairs for x8 if we need it
        constexpr static const uint8_t symbol2dq_x8[] =
        {
            47, 45, 43, 41,
            39, 37, 35, 33,
            0,  0,  0,  0,
            0,  0,  0,  0,
            0,  0,  0,  0,
            0,  0,  0,  0,
            0,  0,  0,  0,
            0,  0,  0,  0,
            0,  0,  0,  0,
            0,  0,  0,  0,
            79, 77, 75, 73,
            71, 69, 67, 65,
            63, 61, 59, 57,
            55, 53, 51, 49,
            31, 29, 27, 25,
            23, 21, 19, 17,
            15, 13, 11, 9,
            7,  5,  3,  1
        };
};

///
/// @class eccTraits
/// @brief a collection of traits associated with the Odyssey MC ECC interface
///
template<>
class eccTraits<mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>
{
    public:
        // MCBIST ECC registers - must be 64 bits.
        static constexpr uint64_t READ_ERROR_COUNT_REG0 = scomt::ody::ODC_MCBIST_SCOM_MBSEC0Q;
        static constexpr uint64_t READ_ERROR_COUNT_REG1 = scomt::ody::ODC_MCBIST_SCOM_MBSEC1Q;
        static constexpr uint64_t READ_ERROR_COUNT_REG2 = scomt::ody::ODC_MCBIST_SCOM_MBSEC2Q;
        static constexpr uint64_t MARK_SYMBOL_COUNT_REG = scomt::ody::ODC_MCBIST_SCOM_MBSMSECQ;
        static constexpr uint64_t MODAL_SYM_COUNT0_REG = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC0Q;
        static constexpr uint64_t MODAL_SYM_COUNT1_REG = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC1Q;
        static constexpr uint64_t MODAL_SYM_COUNT2_REG = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC2Q;
        static constexpr uint64_t MODAL_SYM_COUNT3_REG = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC3Q;
        static constexpr uint64_t MODAL_SYM_COUNT4_REG = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC4Q;
        static constexpr uint64_t MODAL_SYM_COUNT5_REG = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC5Q;
        static constexpr uint64_t MODAL_SYM_COUNT6_REG = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC6Q;
        static constexpr uint64_t MODAL_SYM_COUNT7_REG = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC7Q;
        static constexpr uint64_t MODAL_SYM_COUNT8_REG = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC8Q;
        static constexpr uint64_t MODAL_SYM_COUNT9_REG = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC9Q;
        static constexpr uint64_t MPE_ADDR_TRAP_REG = scomt::ody::ODC_MCBIST_SCOM_MCBMCATQ;
        static constexpr uint64_t ECC_MAX_MRANK_PER_PORT = ody::MAX_MRANK_PER_PORT;
        static constexpr uint64_t ECC_MAX_DQ_BITS = ody::MAX_DQ_BITS_PER_PORT;
        static constexpr uint64_t ECC_MAX_SYMBOLS = ody::MAX_SYMBOLS_PER_PORT;

        // Stores the symbol counter registers in a vector for easier access for MCBIST
        static constexpr uint64_t REQUIRED_NUMBER_OF_SYMBOL_REGS = 10;
        static const std::vector<uint64_t> SYMBOL_COUNT_REG;

        // Fields, can be any size.
        enum
        {
            INTERMITTENT_CE_COUNT = scomt::ody::ODC_MCBIST_SCOM_MBSEC0Q_INTERMITTENT_CE_COUNT,
            INTERMITTENT_CE_COUNT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSEC0Q_INTERMITTENT_CE_COUNT_LEN,
            SOFT_CE_COUNT = scomt::ody::ODC_MCBIST_SCOM_MBSEC0Q_SOFT_CE_COUNT,
            SOFT_CE_COUNT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSEC0Q_SOFT_CE_COUNT_LEN,
            HARD_CE_COUNT = scomt::ody::ODC_MCBIST_SCOM_MBSEC0Q_HARD_CE_COUNT,
            HARD_CE_COUNT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSEC0Q_HARD_CE_COUNT_LEN,
            INTERMITTENT_MCE_COUNT = scomt::ody::ODC_MCBIST_SCOM_MBSEC0Q_INTERMITTENT_MCE_COUNT,
            INTERMITTENT_MCE_COUNT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSEC0Q_INTERMITTENT_MCE_COUNT_LEN,
            SOFT_MCE_COUNT = scomt::ody::ODC_MCBIST_SCOM_MBSEC0Q_SOFT_MCE_COUNT,
            SOFT_MCE_COUNT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSEC0Q_SOFT_MCE_COUNT_LEN,
            HARD_MCE_COUNT = scomt::ody::ODC_MCBIST_SCOM_MBSEC1Q_HARD_MCE_COUNT,
            HARD_MCE_COUNT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSEC1Q_HARD_MCE_COUNT_LEN,
            ICE_COUNT = scomt::ody::ODC_MCBIST_SCOM_MBSEC1Q_ICE_COUNT,
            ICE_COUNT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSEC1Q_ICE_COUNT_LEN,
            UE_COUNT = scomt::ody::ODC_MCBIST_SCOM_MBSEC1Q_UE_COUNT,
            UE_COUNT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSEC1Q_UE_COUNT_LEN,
            AUE_COUNT = scomt::ody::ODC_MCBIST_SCOM_MBSEC1Q_AUE_COUNT,
            AUE_COUNT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSEC1Q_AUE_COUNT_LEN,
            IUE_COUNT = scomt::ody::ODC_MCBIST_SCOM_MBSEC1Q_IUE_COUNT,
            IUE_COUNT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSEC1Q_IUE_COUNT_LEN,
            IAUE_COUNT = scomt::ody::ODC_MCBIST_SCOM_MBSEC2Q_IAUE_COUNT,
            IAUE_COUNT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSEC2Q_IAUE_COUNT_LEN,
            IRCD_COUNT = scomt::ody::ODC_MCBIST_SCOM_MBSEC2Q_IRCD_COUNT,
            IRCD_COUNT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSEC2Q_IRCD_COUNT_LEN,
            SYMBOL0_COUNT = scomt::ody::ODC_MCBIST_SCOM_MBSMSECQ_SYMBOL0_COUNT,
            SYMBOL0_COUNT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSMSECQ_SYMBOL0_COUNT_LEN,
            SYMBOL1_COUNT = scomt::ody::ODC_MCBIST_SCOM_MBSMSECQ_SYMBOL1_COUNT,
            SYMBOL1_COUNT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSMSECQ_SYMBOL1_COUNT_LEN,
            SYMBOL2_COUNT = scomt::ody::ODC_MCBIST_SCOM_MBSMSECQ_SYMBOL2_COUNT,
            SYMBOL2_COUNT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSMSECQ_SYMBOL2_COUNT_LEN,
            SYMBOL3_COUNT = scomt::ody::ODC_MCBIST_SCOM_MBSMSECQ_SYMBOL3_COUNT,
            SYMBOL3_COUNT_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSMSECQ_SYMBOL3_COUNT_LEN,
            MODAL_SYMBOL_COUNTER_00 = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC0Q_00,
            MODAL_SYMBOL_COUNTER_00_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC0Q_00_LEN,
            MODAL_SYMBOL_COUNTER_01 = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC0Q_01,
            MODAL_SYMBOL_COUNTER_01_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC0Q_01_LEN,
            MODAL_SYMBOL_COUNTER_02 = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC0Q_02,
            MODAL_SYMBOL_COUNTER_02_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC0Q_02_LEN,
            MODAL_SYMBOL_COUNTER_03 = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC0Q_03,
            MODAL_SYMBOL_COUNTER_03_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC0Q_03_LEN,
            MODAL_SYMBOL_COUNTER_04 = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC0Q_04,
            MODAL_SYMBOL_COUNTER_04_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC0Q_04_LEN,
            MODAL_SYMBOL_COUNTER_05 = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC0Q_05,
            MODAL_SYMBOL_COUNTER_05_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC0Q_05_LEN,
            MODAL_SYMBOL_COUNTER_06 = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC0Q_06,
            MODAL_SYMBOL_COUNTER_06_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC0Q_06_LEN,
            MODAL_SYMBOL_COUNTER_07 = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC0Q_07,
            MODAL_SYMBOL_COUNTER_07_LEN = scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC0Q_07_LEN,

            // and a couple constants
            NUM_MBSSYM_REGS = 10,
            MODAL_SYMBOL_COUNTERS_PER_REG = 8,
        };

};

} // close namespace mss

#endif
