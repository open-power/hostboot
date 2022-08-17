/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/mc/ody_port_traits.H $ */
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
/// @file ody_port_traits.H
/// @brief Traits for Odyssey memory ports
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_ODY_PORT_TRAITS_H_
#define _MSS_ODY_PORT_TRAITS_H_

#include <fapi2.H>
#include <ody_scom_ody.H>
#include <generic/memory/lib/utils/mc/gen_mss_port_traits.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/shared/ody_consts.H>

namespace mss
{

//////////////////////////////////////////////////////////////
// Traits values for Odyssey
//////////////////////////////////////////////////////////////
///
/// @class Traits and policy class for port code - specialization for Odyssey. The target of registers is TARGET_TYPE_OCMB_CHIP
///
template<>
class portTraits< mss::mc_type::ODYSSEY >
{
    public:

        ///
        /// @brief Gets the correct target for the FARB registers off of a MEM_PORT target
        /// @return Returns the OCMB_CHIP target
        ///
        static fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> get_farb_target(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
                i_target)
        {
            return mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);
        }

        ///
        /// @brief Gets the correct target for the read reorder queue registers off of a MEM_PORT target
        /// @return Returns the OCMB_CHIP target
        ///
        static fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> get_rrq_target(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
                i_target)
        {
            return mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);
        }

        // MC_TYPE
        static constexpr fapi2::TargetType MC_TARGET_TYPE = fapi2::TARGET_TYPE_OCMB_CHIP;

        // PORT_TYPE
        static constexpr fapi2::TargetType PORT_TYPE = fapi2::TARGET_TYPE_MEM_PORT;

        // scom register definition
        static constexpr uint64_t MBARPC0Q_REG = scomt::ody::ODC_SRQ_MBARPC0Q;
        static constexpr uint64_t SRQ_MBAREFAQ = scomt::ody::ODC_SRQ_MBAREFAQ;
        static constexpr uint64_t FARB0Q_REG = scomt::ody::ODC_SRQ_MBA_FARB0Q;
        static constexpr uint64_t FARB5Q_REG = scomt::ody::ODC_SRQ_MBA_FARB5Q;
        static constexpr uint64_t FARB6Q_REG = scomt::ody::ODC_SRQ_MBA_FARB6Q;
        static constexpr uint64_t FARB9Q_REG = scomt::ody::ODC_SRQ_MBA_FARB9Q;
        static constexpr uint64_t REFRESH_REG = scomt::ody::ODC_SRQ_MBAREF0Q;
        static constexpr uint64_t STR0Q_REG = scomt::ody::ODC_SRQ_MBASTR0Q;
        static constexpr uint64_t ECC_REG = scomt::ody::ODC_WDF_REGS_RECR;
        static constexpr uint64_t CTCR_REG = scomt::ody::ODC_WDF_REGS_CTCR;
        static constexpr uint64_t DSM0Q_REG = scomt::ody::ODC_SRQ_MBA_DSM0Q;

        // NOTE: ROQ has replaced both WRQ/RRQ
        //       Retaining the later two for generic implementation
        static constexpr uint64_t ROQ_REG = scomt::ody::ODC_SRQ_MBA_ROQ0Q;
        static constexpr uint64_t RRQ_REG = scomt::ody::ODC_SRQ_MBA_ROQ0Q;
        static constexpr uint64_t WRQ_REG = scomt::ody::ODC_SRQ_MBA_ROQ0Q;

        // Note: restore repairs and our ECC logic use the MC/DFI perspective
        // As such, our spare is located on byte 5
        static constexpr uint64_t SPARE_DQ_BYTE = 5;

        // This number includes the two spare nibbles, it is compared against
        // the actual nibble index we're at
        // TODO Zen:MST-1404 Verify this for Odyssey
        static constexpr uint8_t MAX_NIBBLE_IDX = 19;


        static constexpr uint8_t SYMBOL_ROUNDER = 4;

        static const std::vector<uint8_t> NON_SPARE_NIBBLES;
        static const std::vector<uint8_t> SPARE_NIBBLES;

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

        // Odyssey has 2 maximum ranks in HW
        static constexpr uint8_t MAX_MRANK_PER_PORT = mss::ody::HW_MAX_MRANK_PER_PORT;
        static constexpr uint8_t MAX_SYMBOLS_PER_PORT = mss::ody::MAX_SYMBOLS_PER_PORT;

        // scom register field definition
        enum
        {
            // TODO Zen:MST-1405 Power management settings have changed in Odyssey. Need to update generic function
            // and traits to accommodate changes
            // CFG_MIN_MAX_DOMAINS_ENABLE = EXPLR_SRQ_MBARPC0Q_CFG_MIN_MAX_DOMAINS_ENABLE,

            CFG_CCS_INST_RESET_ENABLE = scomt::ody::ODC_SRQ_MBA_FARB5Q_CFG_CCS_INST_RESET_ENABLE,
            CFG_DDR_RESETN = scomt::ody::ODC_SRQ_MBA_FARB5Q_CFG_DDR_RESETN,
            CFG_CCS_ADDR_MUX_SEL = scomt::ody::ODC_SRQ_MBA_FARB5Q_CFG_CCS_ADDR_MUX_SEL,

            // TODO Zen:MST-1406 Check with design team if we have an "init complete" indicator in Odyssey.
            // This was assigned to an unused (and unnamed) bit on Explorer PMU8Q.
            CFG_INIT_COMPLETE = 63,

            CFG_ZQ_PER_CAL_ENABLE = scomt::ody::ODC_SRQ_MBA_FARB9Q_ZQ_PER_CAL_ENABLE,

            REFRESH_ENABLE = scomt::ody::ODC_SRQ_MBAREF0Q_CFG_REFRESH_ENABLE,

            CFG_FORCE_STR = scomt::ody::ODC_SRQ_MBASTR0Q_FORCE_STR,

            ECC_CHECK_DISABLE = scomt::ody::ODC_WDF_REGS_RECR_MBSECCQ_DISABLE_MEMORY_ECC_CHECK_CORRECT,
            ECC_CORRECT_DISABLE = scomt::ody::ODC_WDF_REGS_RECR_MBSECCQ_DISABLE_MEMORY_ECC_CORRECT,
            ECC_USE_ADDR_HASH = scomt::ody::ODC_WDF_REGS_RECR_MBSECCQ_USE_ADDRESS_HASH,

            PORT_FAIL_DISABLE = scomt::ody::ODC_SRQ_MBA_FARB0Q_CFG_PORT_FAIL_DISABLE,
            DFI_INIT_START = scomt::ody::ODC_SRQ_MBA_FARB0Q_CFG_INIT_START,
            RCD_RECOVERY_DISABLE = scomt::ody::ODC_SRQ_MBA_FARB0Q_CFG_DISABLE_RCD_RECOVERY,
            BW_WINDOW_SIZE = scomt::ody::ODC_SRQ_MBA_FARB0Q_CFG_BW_WINDOW_SIZE,
            BW_WINDOW_SIZE_LEN = scomt::ody::ODC_SRQ_MBA_FARB0Q_CFG_BW_WINDOW_SIZE_LEN,

            // TODO Zen:MST-1405 We now have bandwidth split between side0 and side1, so need to figure out if we want to
            // read these separately or sum together - function is get_bw_snapshot in gen_mss_port.H
            BW_SNAPSHOT_SIDE0 = scomt::ody::ODC_SRQ_MBA_FARB6Q_CFG_BW_SNAPSHOT_SIDE0,
            BW_SNAPSHOT_SIDE0_LEN = scomt::ody::ODC_SRQ_MBA_FARB6Q_CFG_BW_SNAPSHOT_SIDE0_LEN,
            BW_SNAPSHOT_SIDE1 = scomt::ody::ODC_SRQ_MBA_FARB6Q_CFG_BW_SNAPSHOT_SIDE1,
            BW_SNAPSHOT_SIDE1_LEN = scomt::ody::ODC_SRQ_MBA_FARB6Q_CFG_BW_SNAPSHOT_SIDE1_LEN,

            RECR_ENABLE_MPE_NOISE_WINDOW = scomt::ody::ODC_WDF_REGS_RECR_MBSECCQ_ENABLE_MPE_NOISE_WINDOW,
            RECR_ENABLE_UE_NOISE_WINDOW = scomt::ody::ODC_WDF_REGS_RECR_MBSECCQ_ENABLE_UE_NOISE_WINDOW,
            RECR_TCE_CORRECTION = scomt::ody::ODC_WDF_REGS_RECR_MBSECCQ_ENABLE_TCE_CORRECTION,
            RECR_MBSECCQ_DATA_INVERSION = scomt::ody::ODC_WDF_REGS_RECR_MBSECCQ_DATA_INVERSION,
            RECR_MBSECCQ_DATA_INVERSION_LEN = scomt::ody::ODC_WDF_REGS_RECR_MBSECCQ_DATA_INVERSION_LEN,
            RECR_RETRY_UNMARKED_ERRORS = scomt::ody::ODC_WDF_REGS_RECR_RECR_RETRY_UNMARKED_ERRORS,
            RECR_CFG_MAINT_USE_TIMERS = scomt::ody::ODC_WDF_REGS_RECR_CFG_MAINT_USE_TIMERS,
            RECR_MBSECCQ_MAINT_NO_RETRY_UE = scomt::ody::ODC_WDF_REGS_RECR_MBSECCQ_MAINT_NO_RETRY_UE,
            RECR_MBSECCQ_MAINT_NO_RETRY_MPE = scomt::ody::ODC_WDF_REGS_RECR_MBSECCQ_MAINT_NO_RETRY_MPE,

            DFI_INIT_COMPLETE0 = scomt::ody::ODC_SRQ_MBA_FARB6Q_CFG_INIT_COMPLETE_SIDE0,
            DFI_INIT_COMPLETE1 = scomt::ody::ODC_SRQ_MBA_FARB6Q_CFG_INIT_COMPLETE_SIDE1,

            CFG_CTRLUPD_AFTER_ERR = scomt::ody::ODC_SRQ_MBA_FARB9Q_CTRLUPD_AFTER_ERR,
            CFG_MC_PER_CAL_ENABLE = scomt::ody::ODC_SRQ_MBA_FARB9Q_MC_PER_CAL_ENABLE,
            CFG_MC_PER_CAL_INTERVAL_TB = scomt::ody::ODC_SRQ_MBA_FARB9Q_MC_PER_CAL_INTERVAL_TB,
            CFG_MC_PER_CAL_INTERVAL_TB_LEN = scomt::ody::ODC_SRQ_MBA_FARB9Q_MC_PER_CAL_INTERVAL_TB_LEN,
            CFG_MC_PER_CAL_INTERVAL = scomt::ody::ODC_SRQ_MBA_FARB9Q_MC_PER_CAL_INTERVAL,
            CFG_MC_PER_CAL_INTERVAL_LEN = scomt::ody::ODC_SRQ_MBA_FARB9Q_MC_PER_CAL_INTERVAL_LEN,
            CFG_MC_PER_CAL_FIXED_RUN_LENGTH_EN = scomt::ody::ODC_SRQ_MBA_FARB9Q_MC_PER_CAL_FIXED_RUN_LENGTH_EN,
            CFG_MC_PER_CAL_RUN_LENGTH = scomt::ody::ODC_SRQ_MBA_FARB9Q_MC_PER_CAL_RUN_LENGTH,
            CFG_MC_PER_CAL_RUN_LENGTH_LEN = scomt::ody::ODC_SRQ_MBA_FARB9Q_MC_PER_CAL_RUN_LENGTH_LEN,
            CFG_MC_PER_CAL_CTRLUPD_MIN = scomt::ody::ODC_SRQ_MBA_FARB9Q_MC_PER_CAL_CTRLUPD_MIN,
            CFG_MC_PER_CAL_CTRLUPD_MIN_LEN = scomt::ody::ODC_SRQ_MBA_FARB9Q_MC_PER_CAL_CTRLUPD_MIN_LEN,

            CTCR_MPE_TIMER = scomt::ody::ODC_WDF_REGS_CTCR_MPE_TIMER,
            CTCR_MPE_TIMER_LEN = scomt::ody::ODC_WDF_REGS_CTCR_MPE_TIMER_LEN,
            CTCR_MPE_TIMEBASE = scomt::ody::ODC_WDF_REGS_CTCR_MPE_TIMEBASE,
            CTCR_MPE_TIMEBASE_LEN = scomt::ody::ODC_WDF_REGS_CTCR_MPE_TIMEBASE_LEN,
            CTCR_UE_TIMER = scomt::ody::ODC_WDF_REGS_CTCR_UE_TIMER,
            CTCR_UE_TIMER_LEN = scomt::ody::ODC_WDF_REGS_CTCR_UE_TIMER_LEN,
            CTCR_UE_TIMEBASE = scomt::ody::ODC_WDF_REGS_CTCR_UE_TIMEBASE,
            CTCR_UE_TIMEBASE_LEN = scomt::ody::ODC_WDF_REGS_CTCR_UE_TIMEBASE_LEN,
            CTCR_UE_LOCKOUT_ENABLE = scomt::ody::ODC_WDF_REGS_CTCR_UE_LOCKOUT_ENABLE,

            DSM0Q_RDTAG_DLY = scomt::ody::ODC_SRQ_MBA_DSM0Q_RDTAG_DLY,
            DSM0Q_RDTAG_DLY_LEN = scomt::ody::ODC_SRQ_MBA_DSM0Q_RDTAG_DLY_LEN,
            DSM0Q_WRDONE_DLY = scomt::ody::ODC_SRQ_MBA_DSM0Q_WRDONE_DLY,
            DSM0Q_WRDONE_DLY_LEN = scomt::ody::ODC_SRQ_MBA_DSM0Q_WRDONE_DLY_LEN,
            FARB0Q_RCD_PROTECTION_TIME = scomt::ody::ODC_SRQ_MBA_FARB0Q_CFG_RCD_PROTECTION_TIME,
            FARB0Q_RCD_PROTECTION_TIME_LEN = scomt::ody::ODC_SRQ_MBA_FARB0Q_CFG_RCD_PROTECTION_TIME_LEN,

            // NOTE: ROQ has replaced both WRQ/RRQ
            //       Retaining the later two for generic implementation
            ROQ_FIFO_MODE = scomt::ody::ODC_SRQ_MBA_ROQ0Q_CFG_FIFO_MODE,
            RRQ_FIFO_MODE = scomt::ody::ODC_SRQ_MBA_ROQ0Q_CFG_FIFO_MODE,
            WRQ_FIFO_MODE = scomt::ody::ODC_SRQ_MBA_ROQ0Q_CFG_FIFO_MODE,

            SRQ_MBAREFAQ_CFG_TSTAB = scomt::ody::ODC_SRQ_MBAREFAQ_CFG_TSTAB,
            SRQ_MBAREFAQ_CFG_TSTAB_LEN = scomt::ody::ODC_SRQ_MBAREFAQ_CFG_TSTAB_LEN,
        };
};


}// mss

#endif
