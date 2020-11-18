/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mc/exp_port.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file exp_port.C
/// @brief Code to support ports
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <lib/shared/exp_defaults.H>
#include <lib/mcbist/exp_mcbist_traits.H>
#include <exp_port.H>

namespace mss
{

///
/// @brief Set up memory controller specific settings for ECC registers (at the end of draminit_mc)
/// @param[in] i_target the target
/// @param[in,out] io_data contents of RECR register
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note mc_type::EXPLORER specialization
///
template< >
fapi2::ReturnCode ecc_reg_settings_draminit_mc<mss::mc_type::EXPLORER>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    fapi2::buffer<uint64_t>& io_data )
{
    using TT = portTraits<mss::mc_type::EXPLORER>;
    fapi2::buffer<uint64_t> l_ctcr_data;

    // Explorer specific settings for RECR
    io_data.setBit<TT::RECR_ENABLE_MPE_NOISE_WINDOW>();
    io_data.setBit<TT::RECR_RETRY_UNMARKED_ERRORS>();
    io_data.clearBit<TT::RECR_CFG_MAINT_USE_TIMERS>();

    // Set up CTCR timers to 20x4^3 (1280 clock cycles; typical read latency is 120ish, so this is about 10x)
    // This is a preliminary guess from the design team. Also enable UE lockout window
    // CTCR -> 51A8E00000000000
    FAPI_TRY( mss::getScom(i_target, TT::CTCR_REG, l_ctcr_data) );

    l_ctcr_data.insertFromRight<TT::CTCR_MPE_TIMER, TT::CTCR_MPE_TIMER_LEN>(0b010100);
    l_ctcr_data.insertFromRight<TT::CTCR_MPE_TIMEBASE, TT::CTCR_MPE_TIMEBASE_LEN>(0b011);
    l_ctcr_data.insertFromRight<TT::CTCR_UE_TIMER, TT::CTCR_UE_TIMER_LEN>(0b010100);
    l_ctcr_data.insertFromRight<TT::CTCR_UE_TIMEBASE, TT::CTCR_UE_TIMEBASE_LEN>(0b011);
    l_ctcr_data.setBit<TT::CTCR_UE_LOCKOUT_ENABLE>();

    FAPI_TRY( mss::putScom(i_target, TT::CTCR_REG, l_ctcr_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enable the MC Periodic calibration functionality
/// @param[in] i_target the target
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note EXPLORER, OCMB_CHIP specialization
///
template<>
fapi2::ReturnCode enable_periodic_cal<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    using TT = portTraits<mss::mc_type::EXPLORER>;

    // Settings: INTERVAL = 16K * 128 = 2M cycles, CTRLUPD_MIN = 128
    constexpr uint8_t CAL_INTERVAL_TB_16384_CYCLES = 0x02;
    constexpr uint16_t CAL_INTERVAL_VALUE = 0x0080;
    constexpr uint16_t CAL_CTRLUPD_MIN_VALUE = 0x0080;

    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY( mss::getScom(i_target, TT::FARB9Q_REG, l_data) );

    // Set up noise window triggered calibration
    l_data.setBit<TT::CFG_CTRLUPD_AFTER_ERR>();

    // Set up periodic calibration
    l_data.setBit<TT::CFG_MC_PER_CAL_ENABLE>();
    l_data.insertFromRight<TT::CFG_MC_PER_CAL_INTERVAL_TB,
                           TT::CFG_MC_PER_CAL_INTERVAL_TB_LEN>(CAL_INTERVAL_TB_16384_CYCLES);
    l_data.insertFromRight<TT::CFG_MC_PER_CAL_INTERVAL,
                           TT::CFG_MC_PER_CAL_INTERVAL_LEN>(CAL_INTERVAL_VALUE);
    l_data.clearBit<TT::CFG_MC_PER_CAL_FIXED_RUN_LENGTH_EN>();
    l_data.insertFromRight<TT::CFG_MC_PER_CAL_RUN_LENGTH,
                           TT::CFG_MC_PER_CAL_RUN_LENGTH_LEN>(0);
    l_data.insertFromRight<TT::CFG_MC_PER_CAL_CTRLUPD_MIN,
                           TT::CFG_MC_PER_CAL_CTRLUPD_MIN_LEN>(CAL_CTRLUPD_MIN_VALUE);

    FAPI_TRY( mss::putScom(i_target, TT::FARB9Q_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get the number of bytes to check in restore_repairs, mc_type EXPLORER specialization
/// @param[in] i_spare_support value of ATTR_DIMM_SPARE for this [DIMM][RANK] combo
/// @return total number of bytes
///
template<>
uint64_t get_total_bytes<mss::mc_type::EXPLORER>(const uint8_t i_spare_support)
{
    using MT = mss::mcbistTraits<mss::mc_type::EXPLORER, fapi2::TARGET_TYPE_OCMB_CHIP>;

    constexpr uint64_t MAX_DQ_BYTES = MT::MAX_DQ_NIBBLES / mss::conversions::NIBBLES_PER_BYTE;

    return MAX_DQ_BYTES;
}

///
/// @brief Figure out if selected nibble is a non-existent spare in restore_repairs, mc_type EXPLORER specialization
/// @param[in] i_spare_support value of ATTR_DIMM_SPARE for this [DIMM][RANK] combo
/// @param[in] i_byte logical byte index
/// @param[in] i_nibble logical nibble index
/// @return true if selected nibble is a non-existent spare and needs to be skipped
///
template<>
bool skip_dne_spare_nibble<mss::mc_type::EXPLORER>(const uint8_t i_spare_support,
        const uint64_t i_byte,
        const size_t i_nibble)
{
    // Note: restore repairs and our ECC logic use the MC/DFI perspective
    // As such, our spare is located on byte 5
    constexpr uint64_t SPARE_DQ_BYTE = 5;

    // The spare nibble is always on the same byte for Explorer, so return false if we're not there
    if (i_byte != SPARE_DQ_BYTE)
    {
        return false;
    }

    // If the spare is the low nibble skip the high nibble, and vice versa
    return (((i_spare_support == fapi2::ENUM_ATTR_MEM_EFF_DIMM_SPARE_LOW_NIBBLE) && (i_nibble == 1)) ||
            ((i_spare_support == fapi2::ENUM_ATTR_MEM_EFF_DIMM_SPARE_HIGH_NIBBLE) && (i_nibble == 0)) ||
            (i_spare_support == fapi2::ENUM_ATTR_MEM_EFF_DIMM_SPARE_NO_SPARE));
}

}// namespace mss
