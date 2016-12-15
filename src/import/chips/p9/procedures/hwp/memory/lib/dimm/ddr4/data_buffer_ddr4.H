/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/data_buffer_ddr4.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: HB:FSP

#ifndef _MSS_DATA_BUFFER_DDR4_H_
#define _MSS_DATA_BUFFER_DDR4_H_

#include <vector>
#include <fapi2.H>
#include <lib/utils/c_str.H>
#include <lib/dimm/bcw_load_ddr4.H>
#include <lib/phy/dp16.H>
#include <lib/dimm/ddr4/control_word_ddr4.H>

namespace mss
{

enum nibble : size_t
{
    LOWER = 2,
    UPPER = 3,
};

// function space and control word definitions
enum db02_def
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
    BUFF_TRAIN_CONFIG_CW = 0x4,
    DRAM_VREF_CW = 0x6,
};

namespace ddr4
{

// buffer training steps from DB02 DDR4 spec
// which makes them ddr4 specific
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
/// @tparam T the functon space number we want
/// @param[in] i_target a DIMM target
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< uint64_t T >
inline fapi2::ReturnCode function_space_select(const fapi2::Target< fapi2::TARGET_TYPE_DIMM >& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst)
{
    // From DB02 spec - F[3:0]BC7x control word
    constexpr size_t MAX_FUNC_SPACE = 7;

    if( T > MAX_FUNC_SPACE )
    {
        // Function spaces are typically user selected.
        // Sometimes function spaces are selected based on rank number
        // or MDQ lane number which currently are also user inputs.

        // We assert out for user programming erros
        FAPI_ERR("%s. Invalid function space selection: %d, max valid function space is %d",
                 mss::c_str(i_target), T, MAX_FUNC_SPACE);

        fapi2::Assert(false);
    }

    // function space bits for the function space selector are
    // don't cares (XXX).  We choose 0 for simplicity.
    cw_data l_data( FUNC_SPACE_0, FUNC_SPACE_SELECT_CW, T, mss::tmrd() );

    FAPI_TRY( control_word_engine<BCW_8BIT>(i_target, l_data, io_inst),
              "%s. Failed control_word_engine for 8-bit BCW (F%dBC%02lxX)",
              mss::c_str(i_target), uint8_t(l_data.iv_func_space), uint8_t(l_data.iv_number) );

    // I don't know what already existed in this ccs instruction vector beforehand so
    // I use the back() method to access the last added ccs instruction of interest
    FAPI_INF("%s. F%dBC%02lx ccs inst 0x%016llx:0x%016llx, data: %d",
             mss::c_str(i_target), uint8_t(l_data.iv_func_space), uint8_t(l_data.iv_number),
             uint64_t(io_inst.back().arr0), uint64_t(io_inst.back().arr1), uint8_t(l_data.iv_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets the function space for the BCW
/// @param[in] i_target a DIMM target
/// @param[in] i_func_space the functon space number we want
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
inline fapi2::ReturnCode function_space_select(const fapi2::Target< fapi2::TARGET_TYPE_DIMM >& i_target,
        const uint64_t i_func_space,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst)
{
    // From DB02 spec - F[3:0]BC7x control word
    constexpr size_t MAX_FUNC_SPACE = 7;

    if( i_func_space > MAX_FUNC_SPACE )
    {
        // Function spaces are typically user selected.
        // Sometimes function spaces are selected based on rank number
        // or MDQ lane number which currently are also user inputs.

        // We assert out for user programming erros
        FAPI_ERR("%s. Invalid function space selection: %d, max valid function space is %d",
                 mss::c_str(i_target), i_func_space, MAX_FUNC_SPACE);

        fapi2::Assert(false);
    }

    // function space bits for the function space selector are
    // don't cares (XXX).  We choose 0 for simplicity.
    cw_data l_data( FUNC_SPACE_0, FUNC_SPACE_SELECT_CW, i_func_space, mss::tmrd() );

    FAPI_TRY( control_word_engine<BCW_8BIT>(i_target, l_data, io_inst),
              "%s. Failed control_word_engine for 8-bit BCW (F%dBC%02lxX)",
              mss::c_str(i_target), uint8_t(l_data.iv_func_space), uint8_t(l_data.iv_number) );

    // I don't know what already existed in this ccs instruction vector beforehand so
    // I use the back() method to access the last added ccs instruction of interest
    FAPI_INF("%s. F%dBC%02lx ccs inst 0x%016llx:0x%016llx, data: %d",
             mss::c_str(i_target), uint8_t(l_data.iv_func_space), uint8_t(l_data.iv_number),
             uint64_t(io_inst.back().arr0), uint64_t(io_inst.back().arr1), uint8_t(l_data.iv_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets data buffer training mode control word
/// @tparam T TargetType of the CCS instruction
/// @param[in] i_target the DIMM target
/// @param[in] i_mode buffer training mode
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Sets buffer control word  (BC0C) setting
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode set_buffer_training( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const training i_mode,
        std::vector< ccs::instruction_t<T> >& io_inst )
{
    // This doesn't need to be reused so it is left local to this function scope
    static const std::vector< std::pair<training, uint64_t> > BUFF_TRAINING =
    {
        { NORMAL, 0 },
        { MREP, 1   },
        { DWL, 4    },
        { HWL, 5    },
        { MRD, 6    },
        { MWD, 7    },
        { HIW, 8    },
    };

    // If we can't find the key then the user passed in an invalid mode
    // and this is a user programming error.  So we assert out.
    // find_value_from_key API does the error checking and fails out
    // for any invalid user input. Easier to handle for sparsed arrays.
    uint64_t l_encoding = 0;
    fapi2::Assert(find_value_from_key(BUFF_TRAINING, i_mode, l_encoding));

    cw_data l_data(FUNC_SPACE_0, BUFF_TRAIN_MODE_CW, l_encoding, mss::tmrc());

    FAPI_TRY( function_space_select(i_target, l_data.iv_func_space, io_inst),
              "%s. Failed to select function space %d",
              mss::c_str(i_target), uint8_t(l_data.iv_func_space) );

    FAPI_TRY( control_word_engine<BCW_4BIT>(i_target, l_data, io_inst),
              "%s. Failed control_word_engine for 4-bit BCW (F%dBC%02lx)",
              mss::c_str(i_target), uint8_t(l_data.iv_func_space), uint8_t(l_data.iv_number) );

    // I don't know what already existed in this ccs instruction vector beforehand so
    // I use the back() method to access the last added ccs instruction of interest
    FAPI_INF("%s. F%dBC%02lx ccs inst 0x%016llx:0x%016llx, data: %d",
             mss::c_str(i_target), uint8_t(l_data.iv_func_space), uint8_t(l_data.iv_number),
             uint64_t(io_inst.back().arr0), uint64_t(io_inst.back().arr1), uint8_t(l_data.iv_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets rank presence control word
/// @param[in] i_num_package_ranks num of package ranks for LRDIMM
/// @param[out] o_setting bc07 settings
/// @return FAPI2_RC_SUCCESS iff okay
///
static fapi2::ReturnCode rank_presence_helper(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_num_package_ranks,
        uint64_t& o_setting)
{
    switch(i_num_package_ranks)
    {
        case 1:
            o_setting = 0b1110;
            break;

        case 2:
            o_setting = 0b1100;
            break;

        case 3:
            o_setting = 0b1000;
            break;

        case 4:
            o_setting = 0b0000;
            break;

        default:
            // While an invalid input can signify a programming error
            // it is expected that this input can come from the eff_master_rank accessor.
            // If it is the latter than we will want to call out an error
            // to raise red flags regarding decoded SPD data that sets this attribute
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_NUM_PKG_RANKS()
                         .set_DIMM_TARGET(i_target)
                         .set_NUM_PKG_RANKS(i_num_package_ranks),
                         "%s. Received invalid package rank %d",
                         mss::c_str(i_target), i_num_package_ranks );
            break;
    }

    // If we got here than success
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // If we are here than we FAPI_ASSERT'ed out
    return fapi2::current_err;
}

///
/// @brief Sets rank presence control word
/// @tparam T TargetType of the CCS instruction
/// @param[in] i_target the DIMM target
/// @param[in] i_num_package_ranks num of package ranks for LRDIMM
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Sets buffer control word (BC07) setting
///
template< fapi2::TargetType T>
inline fapi2::ReturnCode set_rank_presence( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_num_package_ranks,
        std::vector< ccs::instruction_t<T> >& io_inst )
{
    // Helper function handles error checking
    uint64_t l_encoding = 0;
    FAPI_TRY( rank_presence_helper( i_target, i_num_package_ranks, l_encoding),
              "%s. Failed to set rank_presence BCW for %d number of package ranks",
              mss::c_str(i_target), i_num_package_ranks );
    {
        cw_data l_data(FUNC_SPACE_0, RANK_PRESENCE_CW, l_encoding, mss::tmrc());

        FAPI_TRY( function_space_select(i_target, l_data.iv_func_space, io_inst),
                  "%s. Failed to select function space %d",
                  mss::c_str(i_target), uint8_t(l_data.iv_func_space) );

        FAPI_TRY( control_word_engine<BCW_4BIT>(i_target, l_data, io_inst),
                  "%s. Failed control_word_engine for 4-bit BCW (F%dBC%02lx)",
                  mss::c_str(i_target), uint8_t(l_data.iv_func_space), uint8_t(l_data.iv_number) );

        // I don't know what already existed in this ccs instruction vector beforehand so
        // I use the back() method to access the last added ccs instruction of interest
        FAPI_INF("%s. F%dBC%02lx ccs inst 0x%016llx:0x%016llx, data: %d",
                 mss::c_str(i_target), uint8_t(l_data.iv_func_space), uint8_t(l_data.iv_number),
                 uint64_t(io_inst.back().arr0), uint64_t(io_inst.back().arr1), uint8_t(l_data.iv_data) );

    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets Upper/Lower nibble DRAM interface receive enable training control word
/// @tparam T the nibble of in training (upper/lower)
/// @tparam OT TargetType of the CCS instruction
/// @param[in] i_target the DIMM target
/// @param[in] i_rank DIMM0 rank [0:3] or DIMM1 rank [4:7]
/// @param[in] i_trained_timing the delay MDQS receive enable timing
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Sets buffer control word ( F[3:0]BC2x ) setting
///
template< mss::nibble N, fapi2::TargetType OT>
fapi2::ReturnCode set_mrep_timing_control( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_rank,
        const uint64_t i_trained_timing,
        std::vector< ccs::instruction_t<OT> >& io_inst )
{
    constexpr size_t MAX_DELAY = 63;

    // These fail assertions are programming input erros
    if( i_rank >= MAX_MRANK_PER_PORT )
    {
        FAPI_ERR("Invalid ranks received (%d) from max allowed (%d)]", i_rank, MAX_MRANK_PER_PORT - 1);
        fapi2::Assert(false);
    }

    if( i_trained_timing > MAX_DELAY )
    {
        FAPI_ERR("Invalid trained delay received (%d tCK) from max allowed (%d tck)", i_trained_timing, MAX_DELAY);
        fapi2::Assert(false);
    }

    // Function space is determined by rank index for control word since it has a [0:3] range
    cw_data l_data( mss::index(i_rank), N, i_trained_timing, mss::tmrc() );

    FAPI_TRY( function_space_select(i_target, l_data.iv_func_space, io_inst),
              "%s. Failed to select function space %d",
              mss::c_str(i_target), uint8_t(l_data.iv_func_space) );

    FAPI_TRY( control_word_engine<BCW_8BIT>(i_target, l_data, io_inst),
              "%s. Failed control_word_engine for 8-bit BCW (F%dBC%02lxX)",
              mss::c_str(i_target), uint8_t(l_data.iv_func_space), uint8_t(l_data.iv_number) );

    // I don't know what already existed in this ccs instruction vector beforehand so
    // I use the back() method to access the last added ccs instruction of interest
    FAPI_INF("%s. F%dBC%02lxX ccs inst 0x%016llx:0x%016llx, data: %d",
             mss::c_str(i_target), uint8_t(l_data.iv_func_space), uint8_t(l_data.iv_number),
             uint64_t(io_inst.back().arr0), uint64_t(io_inst.back().arr1), uint8_t(l_data.iv_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets command space control word
/// @tparam T TargetType of the CCS instruction
/// @param[in] i_target the DIMM target
/// @param[in] i_command command name
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Sets buffer control word (BC06) setting
///
template< fapi2::TargetType T>
inline fapi2::ReturnCode set_command_space( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const command i_command,
        std::vector< ccs::instruction_t<T> >& io_inst )
{
    constexpr uint64_t MAX_VALID_CMD = 4;

    // User input programming error asserts program termination
    if( i_command > MAX_VALID_CMD )
    {
        FAPI_ERR( "%s. Invalid command received: %d, largest valid command is %d",
                  mss::c_str(i_target), i_command, MAX_VALID_CMD );
        fapi2::Assert(false);
    }

    // From the DDR4DB02 Spec: BC06 - Command Space Control Word
    // After issuing a data buffer command via writes to BC06 waiting for tMRC(16 tCK)
    // is required before the next DRAM command or BCW write can be issued.
    cw_data l_data(FUNC_SPACE_0, CMD_SPACE_CW, i_command, mss::tmrc());

    FAPI_TRY( function_space_select(i_target, l_data.iv_func_space, io_inst),
              "%s. Failed to select function space %d",
              mss::c_str(i_target), uint8_t(l_data.iv_func_space) );

    FAPI_TRY( control_word_engine<BCW_4BIT>(i_target, l_data, io_inst),
              "%s. Failed control_word_engine for 4-bit BCW (F%dBC%02lx)",
              mss::c_str(i_target), uint8_t(l_data.iv_func_space), uint8_t(l_data.iv_number) );

    // I don't know what already existed in this ccs instruction vector beforehand so
    // I use the back() method to access the last added ccs instruction of interest
    FAPI_INF("%s. F%dBC%02lx ccs inst 0x%016llx:0x%016llx, data: %d",
             mss::c_str(i_target), uint8_t(l_data.iv_func_space), uint8_t(l_data.iv_number),
             uint64_t(io_inst.back().arr0), uint64_t(io_inst.back().arr1), uint8_t(l_data.iv_data) );

fapi_try_exit:
    return fapi2::current_err;
}

}// namespace ddr4
} // namespace mss

#endif
