/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr4/data_buffer_ddr4.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file data_buffer_ddr4.H
/// @brief Code to support data_buffer_ddr4
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _DATA_BUFFER_DDR4_H_
#define _DATA_BUFFER_DDR4_H_

#include <vector>
#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/dimm/mrs_traits.H>
#include <lib/dimm/bcw_load_ddr4.H>
#include <lib/phy/dp16.H>
#include <generic/memory/lib/dimm/ddr4/control_word_ddr4.H>
#include <generic/memory/lib/ccs/ccs_traits.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <generic/memory/lib/utils/mss_generic_check.H>

namespace mss
{

///
/// @brief upper and lower nimble
/// Not sure if these are still needed, will remove after commit builds
///
enum nibble : size_t
{
    LOWER = 2,
    UPPER = 3,
};

///
/// @brief function space and control word definitions
///
enum db02_def : size_t
{
    // Function spaces
    FUNC_SPACE_0 = 0,
    FUNC_SPACE_1 = 1,
    FUNC_SPACE_2 = 2,
    FUNC_SPACE_3 = 3,
    FUNC_SPACE_4 = 4,
    FUNC_SPACE_5 = 5,
    FUNC_SPACE_6 = 6,
    FUNC_SPACE_7 = 7,

    // From DB02 spec - F[3:0]BC7x control word
    MAX_FUNC_SPACE = FUNC_SPACE_7,

    // 4 bit BCWs
    DQ_RTT_NOM_CW = 0x0,
    DQ_RTT_WR_CW = 0x1,
    DQ_RTT_PARK_CW = 0x2,
    DQ_DRIVER_CW = 0x3,
    MDQ_RTT_CW = 0x4,
    MDQ_DRIVER_CW = 0x5,
    CMD_SPACE_CW = 0x6,
    RANK_PRESENCE_CW = 0x7,
    RANK_SELECTION_CW = 0x8,
    POWER_SAVING_CW = 0x9,
    OPERATING_SPEED = 0xA,
    VOLT_AND_SLEW_RATE_CW = 0xB,
    BUFF_TRAIN_MODE_CW = 0xC,
    LDQ_OPERATION_CW = 0xD,
    PARITY_CW = 0xE,
    ERROR_STATUS_CW = 0xF,
    FUNC_SPACE_SELECT_CW = 0x7,

    // 8 bit BCWs
    BUFF_CONFIG_CW = 0x1, // Func space 0
    LRDIMM_OPERATING_SPEED = 0x6, // Func space 0
    HOST_DFE = 0xE, // Func space 2
    HOST_VREF_CW = 0x5, // Func space 5
    DRAM_VREF_CW = 0x6, // Func space 5
    BUFF_TRAIN_CONFIG_CW = 0x4, // Func space 6

    // Safe delays for BCW's
    BCW_SAFE_DELAY = 2000,
};

namespace ddr4
{

///
/// @brief buffer training steps from DB02 DDR4 spec, ddr4 specific
///
enum training : size_t
{
    NORMAL,
    MREP,
    DWL,
    HWL,
    MRD,
    MWD,
    HIW,
};

///
/// @brief enum holding command codes
///
enum command : size_t
{
    RESET_DLL = 0,
    ZQCL = 1,
    ZQCS = 2,
    CLEAR_ERR_STAT = 3,
    SOFT_RESET = 4
};

///
/// @brief Sets the function space for the BCW
/// @param[in] i_target a DIMM target
/// @param[in] i_func_space the functon space number we want
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode function_space_select(const fapi2::Target< fapi2::TARGET_TYPE_DIMM >& i_target,
                                        const uint64_t i_func_space,
                                        std::vector< ccs::instruction_t<DEFAULT_MC_TYPE> >& io_inst);

///
/// @brief Boilerplate for setting & printing BCWs
/// @tparam T the functon space number we want
/// @param[in] i_target a DIMM target
/// @param[in] i_data control word data
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::control_word T >
static fapi2::ReturnCode settings_boilerplate(const fapi2::Target< fapi2::TARGET_TYPE_DIMM >& i_target,
        const cw_data& i_data,
        std::vector< ccs::instruction_t<DEFAULT_MC_TYPE> >& io_inst)
{
    uint8_t l_sim = 0;
    mss::is_simulation(l_sim);

    // DES first - make sure those CKE go high and stay there
    io_inst.push_back(mss::ccs::des_command<DEFAULT_MC_TYPE>());

    FAPI_TRY( function_space_select(i_target, i_data.iv_func_space, io_inst),
              "%s. Failed to select function space %d",
              mss::c_str(i_target), uint8_t(i_data.iv_func_space) );

    FAPI_TRY( control_word_engine<T>(i_target, i_data, l_sim, io_inst),
              "%s. Failed control_word_engine for 8-bit BCW (F%dBC%02lxX)",
              mss::c_str(i_target), uint8_t(i_data.iv_func_space), uint8_t(i_data.iv_number) );

    // I don't know what already existed in this ccs instruction vector beforehand so
    // I use the back() method to access the last added ccs instruction of interest
    FAPI_INF("%s. F%dBC%02lx ccs inst 0x%016llx:0x%016llx, data: %d",
             mss::c_str(i_target), uint8_t(i_data.iv_func_space), uint8_t(i_data.iv_number),
             uint64_t(io_inst.back().arr0), uint64_t(io_inst.back().arr1), uint8_t(i_data.iv_data) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Sets per buffer addressibility (PBA) mode
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to mrsTraits<MC>
/// @param[in] i_target the DIMM target
/// @param[in] i_state mss::ON or mss::OFF
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Sets DA0 setting for buffer control word (F0BC1x)
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = mrsTraits<MC> >
fapi2::ReturnCode set_pba_mode( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                const mss::states i_state,
                                std::vector< ccs::instruction_t<MC> >& io_inst )
{
    constexpr uint64_t OUT_OF_BOUNDS = 2;
    uint8_t l_nominal_bc_value = 0;

    // Error checking
    FAPI_TRY(mss::check::index_within_bounds(i_target,
             i_state,
             OUT_OF_BOUNDS,
             SET_PBA_MODE,
             "set_pba_mode"));

    // Gets our nominal BCW value
    FAPI_TRY(mss::eff_dimm_ddr4_f0bc1x(i_target, l_nominal_bc_value));

    {
        // PBA position is really bit 0, but we're right justified on our bit ordering here, so it's bit7
        constexpr uint64_t PBA_POSITION = 7;
        cw_data l_data(TT::FUNC_SPACE_0, TT::BUFF_CONFIG_CW, l_nominal_bc_value, mss::tmrd_l2());
        l_data.iv_data.writeBit<PBA_POSITION>(i_state);
        FAPI_INF("%s data 0x%02x", mss::c_str(i_target), l_data.iv_data);
        FAPI_TRY( settings_boilerplate<BCW_8BIT>(i_target, l_data, io_inst) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace ddr4
} // namespace mss

#endif
