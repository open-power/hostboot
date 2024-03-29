/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mc/exp_port_traits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file exp_port_traits.H
/// @brief Traits for Explorer memory ports
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP
// EKB-Mirror-To: hostboot

#ifndef __MSS_EXP_PORT_TRAITS_H_
#define __MSS_EXP_PORT_TRAITS_H_

#include <fapi2.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <explorer_scom_addresses_fld_fixes.H>
#include <generic/memory/lib/utils/mc/gen_mss_port_traits.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/shared/exp_consts.H>

namespace mss
{

//////////////////////////////////////////////////////////////
// Traits values for EXPLORER
//////////////////////////////////////////////////////////////
///
/// @class Traits and policy class for port code - specialization for Explorer. The target of registers is TARGET_TYPE_OCMB_CHIP
///
template<>
class portTraits< mss::mc_type::EXPLORER >
{
    public:

        ///
        /// @brief Gets the correct target for the FARB registers off of a MEM_PORT target
        /// @return Returns the MEM_PORT target
        ///
        static fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> get_farb_target(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
                i_target)
        {
            return i_target;
        }

        ///
        /// @brief Gets the correct target for the read reorder queue registers off of a MEM_PORT target
        /// @return Returns the MEM_PORT target
        ///
        static fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> get_rrq_target(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
                i_target)
        {
            return i_target;
        }

        // MC_TYPE
        static constexpr fapi2::TargetType MC_TARGET_TYPE = fapi2::TARGET_TYPE_OCMB_CHIP;

        // PORT_TYPE
        static constexpr fapi2::TargetType PORT_TYPE = fapi2::TARGET_TYPE_MEM_PORT;

        // scom register definition
        static constexpr uint64_t MBARPC0Q_REG = EXPLR_SRQ_MBARPC0Q;
        static constexpr uint64_t SRQ_MBAREFAQ = EXPLR_SRQ_MBAREFAQ;
        static constexpr uint64_t FARB0Q_REG = EXPLR_SRQ_MBA_FARB0Q;
        static constexpr uint64_t FARB3Q_REG = EXPLR_SRQ_MBA_FARB3Q;
        static constexpr uint64_t FARB4Q_REG = EXPLR_SRQ_MBA_FARB4Q;
        static constexpr uint64_t FARB5Q_REG = EXPLR_SRQ_MBA_FARB5Q;
        static constexpr uint64_t FARB6Q_REG = EXPLR_SRQ_MBA_FARB6Q;
        static constexpr uint64_t FARB9Q_REG = EXPLR_SRQ_MBA_FARB9Q;
        static constexpr uint64_t PMU8Q_REG = EXPLR_SRQ_MBA_PMU8Q;
        static constexpr uint64_t REFRESH_REG = EXPLR_SRQ_MBAREF0Q;
        static constexpr uint64_t STR0Q_REG = EXPLR_SRQ_MBASTR0Q;
        static constexpr uint64_t ECC_REG = EXPLR_RDF_RECR;
        static constexpr uint64_t CTCR_REG = EXPLR_RDF_CTCR;
        static constexpr uint64_t DSM0Q_REG = EXPLR_SRQ_MBA_DSM0Q;
        static constexpr uint64_t FWMS_REG = EXPLR_RDF_FWMS0;

        static constexpr uint64_t RRQ_REG = EXPLR_SRQ_MBA_RRQ0Q;
        static constexpr uint64_t WRQ_REG = EXPLR_SRQ_MBA_WRQ0Q;

        static constexpr uint64_t MAGIC_NUMBER_SIM = 765;
        static constexpr uint64_t MAGIC_NUMBER_NOT_SIM = 196605;

        // Note: restore repairs and our ECC logic use the MC/DFI perspective
        // As such, our spare is located on byte 5
        static constexpr uint64_t SPARE_DQ_BYTE = 5;

        // This number includes the two spare nibbles, it is compared against
        // the actual nibble index we're at
        static constexpr uint8_t MAX_NIBBLE_IDX = 19;
        static constexpr uint8_t MAX_BYTE_IDX = 9;
        static constexpr uint8_t SYMBOL_ROUNDER = 4;

        static const std::vector<uint8_t> NON_SPARE_NIBBLES;
        static const std::vector<uint8_t> SPARE_NIBBLES;

        static const std::vector<uint8_t> NON_SPARE_BYTES;
        static const std::vector<uint8_t> SPARE_BYTES;

        // Settings: INTERVAL = 16K * 128 = 2M cycles, CTRLUPD_MIN = 128
        static constexpr uint8_t CAL_INTERVAL_TB_16384_CYCLES = 0x02;
        static constexpr uint16_t CAL_INTERVAL_VALUE = 0x0080;
        static constexpr uint16_t CAL_CTRLUPD_MIN_VALUE = 0x0080;

        static constexpr uint64_t MPE_TIMER_SETTING = 0b010100;
        static constexpr uint64_t MPE_TIMEBASE_SETTING = 0b011;
        static constexpr uint64_t UE_TIMER_SETTING = 0b010100;
        static constexpr uint64_t UE_TIMEBASE_SETTING = 0b011;

        // Delay we wait between updating the write_mux and the read_mux in program_steering_helper()
        // 1 cycle of periodic calibration
        static constexpr uint64_t  HW_STEERING_DELAY = (250 * mss::DELAY_1MS);
        static constexpr uint64_t  SIM_STEERING_DELAY = (2 * mss::DELAY_100US);

        static constexpr uint8_t MAX_MRANK_PER_PORT = mss::exp::MAX_MRANK_PER_PORT;
        static constexpr uint8_t MAX_SYMBOLS_PER_PORT = mss::exp::MAX_SYMBOLS_PER_PORT;

        // scom register field definition
        enum
        {
            CFG_MIN_MAX_DOMAINS_ENABLE = EXPLR_SRQ_MBARPC0Q_CFG_MIN_MAX_DOMAINS_ENABLE,
            CFG_CCS_INST_RESET_ENABLE = EXPLR_SRQ_MBA_FARB5Q_CFG_CCS_INST_RESET_ENABLE,
            CFG_DDR_RESETN = EXPLR_SRQ_MBA_FARB5Q_CFG_DDR_RESETN,
            CFG_CCS_ADDR_MUX_SEL = EXPLR_SRQ_MBA_FARB5Q_CFG_CCS_ADDR_MUX_SEL,
            CFG_INIT_COMPLETE = EXPLR_SRQ_MBA_PMU8Q_CFG_INIT_COMPLETE,
            CFG_ZQ_PER_CAL_ENABLE = EXPLR_SRQ_MBA_FARB9Q_CFG_ZQ_PER_CAL_ENABLE,

            REFRESH_ENABLE = EXPLR_SRQ_MBAREF0Q_CFG_REFRESH_ENABLE,

            CFG_FORCE_STR = EXPLR_SRQ_MBASTR0Q_CFG_FORCE_STR,

            ECC_CHECK_DISABLE = EXPLR_RDF_RECR_MBSECCQ_DISABLE_MEMORY_ECC_CHECK_CORRECT,
            ECC_CORRECT_DISABLE = EXPLR_RDF_RECR_MBSECCQ_DISABLE_MEMORY_ECC_CORRECT,
            ECC_USE_ADDR_HASH = EXPLR_RDF_RECR_MBSECCQ_USE_ADDRESS_HASH,

            PORT_FAIL_DISABLE = EXPLR_SRQ_MBA_FARB0Q_CFG_PORT_FAIL_DISABLE,
            DFI_INIT_START = EXPLR_SRQ_MBA_FARB0Q_CFG_INIT_START,
            RCD_RECOVERY_DISABLE = EXPLR_SRQ_MBA_FARB0Q_CFG_DISABLE_RCD_RECOVERY,
            BW_WINDOW_SIZE = EXPLR_SRQ_MBA_FARB0Q_CFG_BW_WINDOW_SIZE,
            BW_WINDOW_SIZE_LEN = EXPLR_SRQ_MBA_FARB0Q_CFG_BW_WINDOW_SIZE_LEN,
            BW_SNAPSHOT = EXPLR_SRQ_MBA_FARB6Q_CFG_BW_SNAPSHOT,
            BW_SNAPSHOT_LEN = EXPLR_SRQ_MBA_FARB6Q_CFG_BW_SNAPSHOT_LEN,

            RECR_ENABLE_MPE_NOISE_WINDOW = EXPLR_RDF_RECR_MBSECCQ_ENABLE_MPE_NOISE_WINDOW,
            RECR_ENABLE_UE_NOISE_WINDOW = EXPLR_RDF_RECR_MBSECCQ_ENABLE_UE_NOISE_WINDOW,
            RECR_TCE_CORRECTION = EXPLR_RDF_RECR_MBSECCQ_ENABLE_TCE_CORRECTION,
            RECR_MBSECCQ_DATA_INVERSION = EXPLR_RDF_RECR_MBSECCQ_DATA_INVERSION,
            RECR_MBSECCQ_DATA_INVERSION_LEN = EXPLR_RDF_RECR_MBSECCQ_DATA_INVERSION_LEN,
            RECR_RETRY_UNMARKED_ERRORS = EXPLR_RDF_RECR_RETRY_UNMARKED_ERRORS,
            RECR_CFG_MAINT_USE_TIMERS = EXPLR_RDF_RECR_CFG_MAINT_USE_TIMERS,
            RECR_MBSECCQ_MAINT_NO_RETRY_UE = EXPLR_RDF_RECR_MBSECCQ_MAINT_NO_RETRY_UE,
            RECR_MBSECCQ_MAINT_NO_RETRY_MPE = EXPLR_RDF_RECR_MBSECCQ_MAINT_NO_RETRY_MPE,

            CFG_CTRLUPD_AFTER_ERR = EXPLR_SRQ_MBA_FARB9Q_CFG_CTRLUPD_AFTER_ERR,
            CFG_MC_PER_CAL_ENABLE = EXPLR_SRQ_MBA_FARB9Q_CFG_MC_PER_CAL_ENABLE,
            CFG_MC_PER_CAL_INTERVAL_TB = EXPLR_SRQ_MBA_FARB9Q_CFG_MC_PER_CAL_INTERVAL_TB,
            CFG_MC_PER_CAL_INTERVAL_TB_LEN = EXPLR_SRQ_MBA_FARB9Q_CFG_MC_PER_CAL_INTERVAL_TB_LEN,
            CFG_MC_PER_CAL_INTERVAL = EXPLR_SRQ_MBA_FARB9Q_CFG_MC_PER_CAL_INTERVAL,
            CFG_MC_PER_CAL_INTERVAL_LEN = EXPLR_SRQ_MBA_FARB9Q_CFG_MC_PER_CAL_INTERVAL_LEN,
            CFG_MC_PER_CAL_FIXED_RUN_LENGTH_EN = EXPLR_SRQ_MBA_FARB9Q_CFG_MC_PER_CAL_FIXED_RUN_LENGTH_EN,
            CFG_MC_PER_CAL_RUN_LENGTH = EXPLR_SRQ_MBA_FARB9Q_CFG_MC_PER_CAL_RUN_LENGTH,
            CFG_MC_PER_CAL_RUN_LENGTH_LEN = EXPLR_SRQ_MBA_FARB9Q_CFG_MC_PER_CAL_RUN_LENGTH_LEN,
            CFG_MC_PER_CAL_CTRLUPD_MIN = EXPLR_SRQ_MBA_FARB9Q_CFG_MC_PER_CAL_CTRLUPD_MIN,
            CFG_MC_PER_CAL_CTRLUPD_MIN_LEN = EXPLR_SRQ_MBA_FARB9Q_CFG_MC_PER_CAL_CTRLUPD_MIN_LEN,

            CTCR_MPE_TIMER = EXPLR_RDF_CTCR_MPE_TIMER,
            CTCR_MPE_TIMER_LEN = EXPLR_RDF_CTCR_MPE_TIMER_LEN,
            CTCR_MPE_TIMEBASE = EXPLR_RDF_CTCR_MPE_TIMEBASE,
            CTCR_MPE_TIMEBASE_LEN = EXPLR_RDF_CTCR_MPE_TIMEBASE_LEN,
            CTCR_UE_TIMER = EXPLR_RDF_CTCR_UE_TIMER,
            CTCR_UE_TIMER_LEN = EXPLR_RDF_CTCR_UE_TIMER_LEN,
            CTCR_UE_TIMEBASE = EXPLR_RDF_CTCR_UE_TIMEBASE,
            CTCR_UE_TIMEBASE_LEN = EXPLR_RDF_CTCR_UE_TIMEBASE_LEN,
            CTCR_UE_LOCKOUT_ENABLE = EXPLR_RDF_CTCR_UE_LOCKOUT_ENABLE,

            DSM0Q_RDTAG_DLY = EXPLR_SRQ_MBA_DSM0Q_CFG_RDTAG_DLY,
            DSM0Q_RDTAG_DLY_LEN = EXPLR_SRQ_MBA_DSM0Q_CFG_RDTAG_DLY_LEN,
            DSM0Q_WRDONE_DLY = EXPLR_SRQ_MBA_DSM0Q_CFG_WRDONE_DLY,
            DSM0Q_WRDONE_DLY_LEN = EXPLR_SRQ_MBA_DSM0Q_CFG_WRDONE_DLY_LEN,
            FARB0Q_RCD_PROTECTION_TIME = EXPLR_SRQ_MBA_FARB0Q_CFG_RCD_PROTECTION_TIME,
            FARB0Q_RCD_PROTECTION_TIME_LEN = EXPLR_SRQ_MBA_FARB0Q_CFG_RCD_PROTECTION_TIME_LEN,

            FWMS0_MARK = EXPLR_RDF_FWMS0_MARK,
            FWMS0_MARK_LEN = EXPLR_RDF_FWMS0_MARK_LEN,
            FWMS0_EXIT_1 = EXPLR_RDF_FWMS0_EXIT_1,

            RRQ_FIFO_MODE = EXPLR_SRQ_MBA_RRQ0Q_CFG_RRQ_FIFO_MODE,
            RRQ_DISABLE_PAGE_MODE = EXPLR_SRQ_MBA_RRQ0Q_CFG_DISABLE_RD_PG_MODE,
            WRQ_FIFO_MODE = EXPLR_SRQ_MBA_WRQ0Q_CFG_WRQ_FIFO_MODE,

            SRQ_MBAREFAQ_CFG_TSTAB = EXPLR_SRQ_MBAREFAQ_CFG_TSTAB,
            SRQ_MBAREFAQ_CFG_TSTAB_LEN = EXPLR_SRQ_MBAREFAQ_CFG_TSTAB_LEN ,
        };
};


}// mss

#endif
