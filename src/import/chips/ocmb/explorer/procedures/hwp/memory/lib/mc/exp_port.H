/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mc/exp_port.H $ */
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
/// @file exp_port.H
/// @brief Code to support ports
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef __MSS_EXP_PORT_H_
#define __MSS_EXP_PORT_H_

#include <fapi2.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <explorer_scom_addresses_fld_fixes.H>
#include <lib/exp_attribute_accessors_manual.H>
#include <lib/utils/mss_exp_conversions.H>
#include <mss_explorer_attribute_getters.H>
#include <lib/shared/exp_consts.H>
#include <lib/dimm/exp_rank.H>
#include <generic/memory/lib/utils/mc/gen_mss_port.H>
#include <generic/memory/lib/utils/mc/gen_mss_restore_repairs.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <mss_generic_attribute_getters.H>

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
        // PORT_TYPE
        static constexpr fapi2::TargetType PORT_TYPE = fapi2::TARGET_TYPE_MEM_PORT;

        // scom register definition
        static constexpr uint64_t MBARPC0Q_REG = EXPLR_SRQ_MBARPC0Q;

        static constexpr uint64_t FARB0Q_REG = EXPLR_SRQ_MBA_FARB0Q;
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
            WRQ_FIFO_MODE = EXPLR_SRQ_MBA_WRQ0Q_CFG_WRQ_FIFO_MODE,
        };
};

///
/// @brief ATTR_MSS_MEM_MVPD_FWMS getter
/// @param[in] const ref to the TARGET_TYPE_OCMB_CHIP
/// @param[out] uint32_t&[] array reference to store the value
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note  Mark store records from OCMB VPD. The array dimension is [port][mark]. Explorer
/// only has one port so only [0][mark] is used in explorer.
///
template<>
inline fapi2::ReturnCode mvpd_fwms< mss::mc_type::EXPLORER >(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    uint32_t (&o_array)[mss::MARK_STORE_COUNT])
{
    return mss::attr::get_mvpd_fwms(i_target, o_array);
}

/// @brief Get the attributes for the reorder queue setting
/// @param[in] const ref to the mc target
/// @param[out] uint8_t& reference to store the value
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note  Contains the settings for write/read reorder
/// queue
///
template< >
inline fapi2::ReturnCode reorder_queue_setting<mss::mc_type::EXPLORER>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    uint8_t& o_value)
{
    return mss::attr::get_reorder_queue_setting(i_target, o_value);
}

///
/// @brief ATTR_MEM_EFF_DIMM_SPARE getter
/// @param[in] const ref to the TARGET_TYPE_DIMM
/// @param[out] uint32_t&[] array reference to store the value
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note  Spare DRAM availability. Used in various locations and is computed in mss_eff_cnfg.
/// Array indexes are [DIMM][RANK]
///
template<>
inline fapi2::ReturnCode dimm_spare< mss::mc_type::EXPLORER >(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    uint8_t (&o_array)[mss::MAX_RANK_PER_DIMM_ATTR])
{
    return mss::attr::get_dimm_spare(i_target, o_array);
}

///
/// @brief Change the state of the force_str bit - mc_type::EXPLORER specialization
/// @tparam MC the memory controller type
/// @param[in] i_target the target
/// @param[in] i_state the state
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< >
inline fapi2::ReturnCode change_force_str<DEFAULT_MC_TYPE>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const states i_state )
{
    using TT = portTraits<mss::mc_type::EXPLORER>;
    fapi2::buffer<uint64_t> l_data;

    FAPI_DBG("Change force_str to %s %s", (i_state == HIGH ? "high" : "low"), mss::c_str(i_target));
    FAPI_TRY( mss::getScom(i_target, TT::STR0Q_REG, l_data) );
    l_data.writeBit<TT::CFG_FORCE_STR>(i_state);
    FAPI_TRY( mss::putScom(i_target, TT::STR0Q_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

}// mss

#endif
