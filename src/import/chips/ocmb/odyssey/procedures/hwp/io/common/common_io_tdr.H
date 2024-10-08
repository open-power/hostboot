/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/common/common_io_tdr.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @file common_io_tdr.H
/// @brief TDR Functions
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Josh Chica <Josh.Chica@ibm.com>
/// *HW FW Maintainer:
/// *HW Consumed by  : SBE
///-----------------------------------------------------------------------------
#pragma once
#include <fapi2.H>
#include <io_scom_lib.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
enum TdrResult
{
    None = 0x00,
    NoIssues = 0x10,
    Open = 0x20,
    Short = 0x30,
    ShortToGnd = 0x01 | Short,
    ShortToVdd = 0x02 | Short,
    DidNotRun = 0x40,
    NotSupported = 0x50,
    UnableToDetermine = 0x60
};

enum TdrRegisters
{
    tx_cntl3_pl = 0x0888,
    tx_cntl15_pl = 0x0948,
    tx_ctl_cntl4_pg = 0x18B8,
    tx_ctl_cntl5_pg = 0x18C8,
    tx_ctl_cntl6_pg = 0x18D8,
    tx_stat1_pl = 0x0A48,
    tx_ctl_mode1_pg = 0x1818,
};

enum TdrConsts
{
    tdrDacStart = 56,
    tdrDacLength = 8,
};

struct TdrStruct
{
    uint32_t iv_lane;
    TdrResult iv_status;
    uint32_t iv_length;
};

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
/// @brief Use TDR to check for net opens and shorts
/// @param[in] i_iolink_target      IOLINK target to get thread id for
/// @param[in] i_lanes              Lanes to run TDR on
/// @param[out] o_status            Status of the net (Open, Short, Good)
/// @param[out] o_length_mm         Length from TX to open (in mm)
/// @return FAPI_RC_SUCCESS if arguments are valid
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr_initialize(const fapi2::Target<K, M, V>&,
        const uint64_t,
        const uint32_t,
        const uint32_t,
        const uint32_t,
        uint32_t);
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr_get_tdr_offsets(const fapi2::Target<K, M, V>&,
        const uint32_t,
        uint32_t&);
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr_sample_point(const fapi2::Target<K, M, V>&,
        const uint64_t,
        const uint32_t,
        const uint32_t,
        const uint32_t,
        int32_t&);
inline fapi2::ReturnCode common_io_tdr_diagnose(const uint32_t&,
        const uint32_t,
        uint32_t&);
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr_find_horizontal_crossing(const fapi2::Target<K, M, V>&,
        const uint64_t,
        const uint32_t,
        const uint32_t,
        const uint32_t,
        const uint32_t,
        const uint32_t,
        const uint32_t,
        uint32_t&);
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr_find_short_crossing(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_baseAddr,
        const uint32_t i_group,
        const uint32_t i_phase,
        const uint32_t i_dac,
        const uint32_t i_lane,
        const uint32_t i_x_offset,
        const uint32_t i_pulse_width,
        bool i_direction,
        int32_t& o_offset);
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr_get_capt_val(const fapi2::Target<K, M, V>&,
        const uint64_t,
        const uint32_t,
        const uint32_t,
        uint32_t&);
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr_set_pulse_offset(const fapi2::Target<K, M, V>&,
        const uint64_t,
        const uint32_t,
        const uint32_t,
        const uint32_t);
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr_find_limit(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_baseAddr,
        const uint32_t i_group,
        const uint32_t i_offset_start,
        const uint32_t i_offset_end,
        const uint32_t i_lane,
        bool i_max_not_min,
        int32_t& o_limit);
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr_cleanup(const fapi2::Target<K, M, V>& i_target,
                                        const uint64_t i_baseAddr,
                                        const uint32_t i_group,
                                        const uint32_t i_lane);

/// @brief Use TDR to check for net opens and shorts
/// @param[in] i_target         Target to get thread id for
/// @param[in] i_group          Group to run TDR on
/// @param[in] i_lane           Lanes to run TDR on
/// @param[in] i_freq           Frequency TDR runs at
/// @param[out] o_status        Status of the net (Open, Short, Good)
/// @param[out] o_length_ps     Length from TX to open (in ps)
/// @return FAPI_RC_SUCCESS if arguments are valid
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr(
    const fapi2::Target<K, M, V>& i_target,
    const uint64_t& i_baseAddr,
    const uint32_t& i_group,
    const uint32_t& i_lane,
    const uint32_t& i_freq,
    TdrResult& o_status,
    uint32_t& o_length_ps)
{

    FAPI_DBG("Begin TDR Isolation (Version 0.0): base(0x%08X) group(%d) lane(%d) freq(%d)", i_baseAddr, i_group, i_lane,
             i_freq);

    const uint32_t c_pulse_width = 100;
    const uint32_t c_fs_per_ui = 100000000 / i_freq;

    uint32_t min_offset = 0;
    uint32_t max_offset = 0;
    uint32_t tdr_offset_width = 0;
    uint32_t o_length_ui = 0;
    int32_t base_point_y1 = 0;
    int32_t base_point_y2 = 0;

    uint8_t l_vec_init = 0;
    std::vector<uint32_t> l_status;

    for (l_vec_init = 0; l_vec_init < 2; l_vec_init++)
    {
        l_status.push_back(TdrResult::None);
    }

    std::vector<uint32_t> l_length_ui;

    for (l_vec_init = 0; l_vec_init < 2; l_vec_init++)
    {
        l_length_ui.push_back(0ul);
    }

    bool loopExit = false;

    // char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];

    // fapi2::toString(i_target, l_tgt_str, sizeof(l_tgt_str));

    FAPI_TRY(common_io_tdr_get_tdr_offsets(i_target, c_pulse_width, tdr_offset_width));

    FAPI_INF("Your freq(%d) c_fs_per_ui(%d) tdr_offset_width(%d)", i_freq, c_fs_per_ui, tdr_offset_width);

    min_offset = (tdr_offset_width * 3) / 8;
    max_offset = (tdr_offset_width * 7) / 8;

    // reset the length to 0 for each lane
    o_length_ui = 0;

    // initialize the local results
    for (int32_t l_phase = 0; l_phase <= 1; l_phase++)
    {
        l_status[l_phase] = TdrResult::None;
        l_length_ui[l_phase] = 0;
    }

    // loop through each of the 2 phases
    for (int32_t l_phase = 0; l_phase <= 1; l_phase++)
    {

        // FAPI_INF("Looping on Lane(%d) and Phase(%d)", i_lane, l_phase);
        FAPI_TRY(common_io_tdr_initialize(i_target, i_baseAddr, i_group, i_lane, c_pulse_width, l_phase));

        if (l_phase == 0)
        {
            base_point_y1 = 192;
            base_point_y2 = 63;
        }
        else
        {
            base_point_y1 = 63;
            base_point_y2 = 192;
        }

        // The base points always return back the minimum value
        FAPI_TRY(common_io_tdr_sample_point(i_target, i_baseAddr, i_group, i_lane, min_offset, base_point_y1));
        FAPI_TRY(common_io_tdr_sample_point(i_target, i_baseAddr, i_group, i_lane, max_offset, base_point_y2));

        // Add an extra point of precision
        base_point_y1 = (base_point_y1 << 1) + 1;
        base_point_y2 = (base_point_y2 << 1) + 1;

        FAPI_INF("Lane(%d) Phase(%d) | Base Points: %3d,%3d", i_lane, l_phase, base_point_y1, base_point_y2);

        FAPI_TRY(common_io_tdr_diagnose(base_point_y1, base_point_y2, l_status[l_phase]));

        switch (l_status[l_phase])
        {
            case TdrResult::UnableToDetermine:
                {
                    break;
                }

            case TdrResult::Open:
                {
                    uint32_t x1_crossing = 0;
                    uint32_t x2_crossing = 0;
                    uint32_t max = (base_point_y1 > base_point_y2) ? base_point_y1 : base_point_y2;
                    uint32_t min = (base_point_y1 > base_point_y2) ? base_point_y2 : base_point_y1;
                    uint32_t l_y1 = min + (((max - min) + 2) / 4);
                    uint32_t l_y2 = min + ((((max - min) * 3) + 2) / 4);
                    FAPI_DBG("TDR Y1(%d) Y2(%d)", l_y1, l_y2);

                    FAPI_TRY(common_io_tdr_find_horizontal_crossing(
                                 i_target,
                                 i_baseAddr,
                                 i_group,
                                 l_phase,
                                 l_y1 >> 1,
                                 i_lane,
                                 min_offset,
                                 max_offset,
                                 x1_crossing));
                    x1_crossing = (x1_crossing << 1) + 1;

                    FAPI_TRY(common_io_tdr_find_horizontal_crossing(
                                 i_target,
                                 i_baseAddr,
                                 i_group,
                                 l_phase,
                                 l_y2 >> 1,
                                 i_lane,
                                 min_offset,
                                 max_offset,
                                 x2_crossing));
                    x2_crossing = (x2_crossing << 1) + 1;

                    l_length_ui[l_phase] = (x1_crossing > x2_crossing)
                                           ? ((x1_crossing - x2_crossing + 1) / 2)
                                           : ((x2_crossing - x1_crossing + 1) / 2);

                    FAPI_INF("TDR Result:: Open Fault: %d / 2 UI from Driver x1(%d) x2(%d).", l_length_ui[l_phase], x1_crossing,
                             x2_crossing);
                    break;
                }

            case TdrResult::Short:
            case TdrResult::ShortToGnd:
            case TdrResult::ShortToVdd:
                {
                    FAPI_DBG("TDR Short found, starting at base_point_y1(%d)", base_point_y1);
                    int32_t l_base = (base_point_y1 + base_point_y2) / 2;
                    int32_t x1_crossing = 0;
                    int32_t x2_crossing = 0;
                    int32_t l_dacmin = 255;
                    int32_t l_dacmax = 0;
                    int32_t l_middac = 0;

                    if (l_status[l_phase] == TdrResult::ShortToGnd)
                    {
                        FAPI_TRY(common_io_tdr_find_limit(i_target, i_baseAddr, i_group, min_offset, max_offset, i_lane, true, l_dacmax));
                        l_middac = (l_base + l_dacmax) / 2;
                    }
                    else if (l_status[l_phase] == TdrResult::ShortToVdd)
                    {
                        FAPI_TRY(common_io_tdr_find_limit(i_target, i_baseAddr, i_group, min_offset, max_offset, i_lane, false, l_dacmin));
                        l_middac = (l_base + l_dacmin) / 2;
                    }
                    else
                    {
                        FAPI_TRY(common_io_tdr_find_limit(i_target, i_baseAddr, i_group, min_offset, max_offset, i_lane, true, l_dacmax));
                        FAPI_TRY(common_io_tdr_find_limit(i_target, i_baseAddr, i_group, min_offset, max_offset, i_lane, false, l_dacmin));
                        l_middac = (l_dacmax + l_dacmin) / 2;
                    }

                    if ((l_base - l_middac) < 2 || (l_base - l_middac) > -2)
                    {
                        l_length_ui[l_phase] = 0;
                        break;
                    }

                    // search from min offset to the right
                    FAPI_TRY(common_io_tdr_find_short_crossing(
                                 i_target,
                                 i_baseAddr,
                                 i_group,
                                 l_phase,
                                 l_middac,
                                 i_lane,
                                 min_offset,
                                 tdr_offset_width,
                                 true,
                                 x1_crossing));

                    FAPI_DBG("x1 crossing: %d", x1_crossing);

                    if (x1_crossing == -1)
                    {
                        l_length_ui[l_phase] = 0;
                        l_status[l_phase] |= TdrResult::UnableToDetermine;
                        break;
                    }

                    // search from max offset to the left
                    FAPI_TRY(common_io_tdr_find_short_crossing(
                                 i_target,
                                 i_baseAddr,
                                 i_group,
                                 l_phase,
                                 l_middac,
                                 i_lane,
                                 max_offset,
                                 tdr_offset_width,
                                 false,
                                 x2_crossing));

                    FAPI_DBG("x2 crossing: %d", x2_crossing);

                    if (x2_crossing == -1)
                    {
                        l_length_ui[l_phase] = 0;
                        l_status[l_phase] |= TdrResult::UnableToDetermine;
                        break;
                    }

                    l_length_ui[l_phase] = (x1_crossing > x2_crossing) ? ((x1_crossing - x2_crossing) / 2) : ((
                                               x2_crossing - x1_crossing) / 2);

                    FAPI_INF("TDR Result:: Short Fault: %d UI from Driver.", l_length_ui[l_phase]);
                    loopExit = true; // if we find an short, no need to run the next phase
                    break;
                }

            case TdrResult::NoIssues:
                {
                    //FAPI_INF("TDR Found a good net for Lane(%d) and Phase(%d)", i_lane, l_phase);
                    break;
                }
        }

        if (loopExit)
        {
            break;
        }
    }

    FAPI_INF("N-leg status(0x%04X) length(%d) :: P-leg status(0x%04X) length(%d) :: 0x0010(GOOD), 0x0020(OPEN), 0x0030(SHORT), 0x0040(DID_NOT_RUN), 0x0050(NOT SUPPORTED), 0x0060(UNABLE)",
             l_status[0],
             l_length_ui[0], l_status[1], l_length_ui[1]);

    // Set length and status based on both phases
    if ((l_status[0] == TdrResult::NoIssues) && (l_status[1] == TdrResult::NoIssues))
    {
        o_status = TdrResult::NoIssues;
        o_length_ui = 0;
    }
    else if (l_status[0] == TdrResult::Open)
    {
        o_status = TdrResult::Open;

        if (l_status[1] == TdrResult::Open)
        {
            // if Open, set o_length_ui to shorter of the open lengths
            if (l_length_ui[0] > l_length_ui[1])
            {
                o_length_ui = l_length_ui[1];
            }
            else
            {
                o_length_ui = l_length_ui[0];
            }
        }
        else
        {
            o_length_ui = l_length_ui[0];
        }
    }
    else if (l_status[1] == TdrResult::Open)
    {
        o_status = TdrResult::Open;
        o_length_ui = l_length_ui[1];
    }
    else if (l_status[0] & TdrResult::Short)
    {
        o_status = static_cast<TdrResult>(l_status[0]);
        o_length_ui = l_length_ui[0];
    }
    else if (l_status[1] & TdrResult::Short)
    {
        o_status = static_cast<TdrResult>(l_status[1]);
        o_length_ui = l_length_ui[1];
    }
    else
    {
        o_status = TdrResult::UnableToDetermine;
        o_length_ui = 0;
    }

    if ((o_status == TdrResult::NoIssues) || (o_status == TdrResult::UnableToDetermine))
    {
        o_length_ps = 0;
    }
    else
    {
        // convert UI to fs
        o_length_ps = (o_length_ui % 2) ? (((o_length_ui >> 1) * c_fs_per_ui) + (3 * c_fs_per_ui / 4)) : (((
                          o_length_ui >> 1) * c_fs_per_ui) + (1 * c_fs_per_ui / 4));

        // Convert from fs to ps
        o_length_ps = (o_length_ps + 500) / 1000;
    }

    FAPI_TRY(common_io_tdr_cleanup(i_target, i_baseAddr, i_group, i_lane));
fapi_try_exit:

    FAPI_DBG("End TDR Isolation");
    return fapi2::current_err;
}

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr_cleanup(const fapi2::Target<K, M, V>& i_target,
                                        const uint64_t i_baseAddr,
                                        const uint32_t i_group,
                                        const uint32_t i_lane)
{
    const uint8_t c_tdrEnBit = 48;
    const uint8_t c_phaseSelBit = 57;
    const uint32_t c_pulseWidthBit = 48;
    const uint32_t c_pulseWidthLen = 9;
    fapi2::buffer<uint64_t> l_data_buf = 0;
    uint64_t l_addr = 0;

    // set TDR pulse width
    l_addr = buildAddr(i_baseAddr, i_group, 0, TdrRegisters::tx_ctl_cntl6_pg);
    FAPI_TRY(rmwIoHardwareReg(i_target, l_addr, 0, c_pulseWidthBit, c_pulseWidthLen));

    // set TDR phase sel
    l_addr = buildAddr(i_baseAddr, i_group, 0, TdrRegisters::tx_ctl_cntl4_pg);
    FAPI_TRY(rmwIoHardwareReg(i_target, l_addr, 0, c_phaseSelBit, 1));

    // TDR Enable
    l_addr = buildAddr(i_baseAddr, i_group, i_lane, TdrRegisters::tx_cntl3_pl);
    FAPI_TRY(rmwIoHardwareReg(i_target, l_addr, 0, c_tdrEnBit, 1));

fapi_try_exit:
    FAPI_DBG("End TDR Cleanup");
    return fapi2::current_err;
}


/// @brief Initialize the phy for TDR
/// @param[in] i_target             Target to get thread id for
/// @param[in] i_group              Group to run TDR on
/// @param[in] i_lane               Lanes to run TDR on
/// @param[in] i_pw                 TDR pulse width
/// @param[in] i_phase              phase to select, either N or P
/// @return FAPI_RC_SUCCESS if arguments are valid

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr_initialize(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_baseAddr,
        const uint32_t i_group,
        const uint32_t i_lane,
        const uint32_t i_pw,
        uint32_t i_phase)
{
    const uint8_t c_tdrEnBit = 48;
    const uint8_t c_phaseSelBit = 57;
    const uint8_t c_hsBistEnBit = 56;
    const uint32_t c_pulseWidthBit = 48;
    const uint32_t c_pulseWidthLen = 9;
    fapi2::buffer<uint64_t> l_data_buf = 0;
    uint64_t l_addr = 0;
    uint32_t l_tdr_enable = 1;

    FAPI_DBG("Begin TDR Initialization");
    // Set tx_bist_hs_en to 0
    l_addr = buildAddr(i_baseAddr, i_group, 0, TdrRegisters::tx_ctl_mode1_pg);
    FAPI_TRY(rmwIoHardwareReg(i_target, l_addr, 0, c_hsBistEnBit, 1),
             "Error on RMW to disable HS Bist to address %d", l_addr);

    // set TDR pulse width
    l_addr = buildAddr(i_baseAddr, i_group, 0, TdrRegisters::tx_ctl_cntl6_pg);
    FAPI_TRY(rmwIoHardwareReg(i_target, l_addr, i_pw, c_pulseWidthBit, c_pulseWidthLen),
             "Error on RMW to set pulse width to %d to address %d", i_pw, l_addr);

    // set TDR phase sel
    l_addr = buildAddr(i_baseAddr, i_group, 0, TdrRegisters::tx_ctl_cntl4_pg);
    FAPI_TRY(rmwIoHardwareReg(i_target, l_addr, i_phase, c_phaseSelBit, 1),
             "Error on RMW to set phase select to %d to address %d", i_phase, l_addr);

    // TDR Enable
    l_addr = buildAddr(i_baseAddr, i_group, i_lane, TdrRegisters::tx_cntl3_pl);
    FAPI_TRY(rmwIoHardwareReg(i_target, l_addr, l_tdr_enable, c_tdrEnBit, 1),
             "Error on RMW to set TDR Enable to %d at address %d", l_tdr_enable, l_addr);

fapi_try_exit:
    FAPI_DBG("End TDR Initialization");
    return fapi2::current_err;
}

/// @brief Calculates the total TDR offsets
/// @param[in] i_target             Target
/// @param[in] i_pw                 TDR pulse width
/// @param[out] o_tdr_width         TDR offset width
/// @return FAPI_RC_SUCCESS if arguments are valid
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr_get_tdr_offsets(const fapi2::Target<K, M, V>& i_target,
        const uint32_t i_pw,
        uint32_t& o_tdr_width)
{
    uint32_t tx_mode = 16; // 16to1 mode is always set
    o_tdr_width = 4 * tx_mode * i_pw;
    FAPI_DBG("TDR Offset width: %d", o_tdr_width);

    return fapi2::current_err;
}

/// @brief Calculates the TDR sample points
/// @param[in] i_target             Target
/// @param[in] i_group              Group to run TDR on
/// @param[in] i_lane               Lanes to run TDR on
/// @param[in] i_offset             TDR offset to take the measurement
/// @param[out] o_dac               TDR DAC value at desired offset
/// @return FAPI_RC_SUCCESS if arguments are valid
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr_sample_point(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_baseAddr,
        const uint32_t i_group,
        const uint32_t i_lane,
        const uint32_t i_offset,
        int32_t& o_dac)
{

    const uint64_t c_tx_cntl15_pl = buildAddr(i_baseAddr, i_group, i_lane, TdrRegisters::tx_cntl15_pl);

    fapi2::buffer<uint64_t> l_data = 0;
    const int32_t LOOP_MAX = 255;
    const int32_t DAC_MAX = 255; // The upper limit of the dac
    const int32_t DAC_MIN = 0;   // The lower limit of the dac
    const uint32_t DIRECTION_CHANGE_MAX = 3;
    uint32_t loop_count = 0;
    uint32_t direction_change_count = 0;
    int32_t direction[2] = {0, 0};
    uint32_t tdr_capt_data = 0;
    const int32_t step = 1;
    int32_t prev_dac = 0;
    fapi2::buffer<uint64_t> l_buffer;

    // set TDR pulse offset
    FAPI_DBG("Start TDR Sample Point");
    // FAPI_INF("setting pulse offset: %d", i_offset);
    FAPI_TRY(common_io_tdr_set_pulse_offset(i_target, i_baseAddr, i_group, i_lane, i_offset));

    FAPI_TRY(getScom(i_target, c_tx_cntl15_pl, l_buffer));

    while (loop_count < LOOP_MAX)
    {
        direction[1] = direction[0];

        // set TDR dac value
        l_buffer.insertFromRight(o_dac, TdrConsts::tdrDacStart, TdrConsts::tdrDacLength);
        FAPI_TRY(putScom(i_target, c_tx_cntl15_pl, l_buffer));

        // read the TDR capture value for the selected lane
        FAPI_TRY(common_io_tdr_get_capt_val(i_target, i_baseAddr, i_group, i_lane, tdr_capt_data));

        prev_dac = o_dac;

        if (tdr_capt_data > 0)
        {
            direction[0] = step;
            o_dac += 1;
        }
        else
        {
            direction[0] = step * -1;
            o_dac -= 1;
        }

        if (direction[0] == direction[1])
        {
            direction_change_count = 0;
        }
        else
        {
            direction_change_count += 1;
        }

        if (direction_change_count >= DIRECTION_CHANGE_MAX)
        {
            break;
        }

        if (o_dac > DAC_MAX)
        {
            o_dac = DAC_MAX;
            break;
        }
        else if (o_dac < DAC_MIN)
        {
            o_dac = DAC_MIN;
            break;
        }

        loop_count++;
    }

    FAPI_DBG("Setting TDR Dac: %d", o_dac);
    // FAPI_INF("Direction change %d | Loop count %d", direction_change_count, loop_count);

    if ((prev_dac < o_dac) && (o_dac != DAC_MIN) && (o_dac != DAC_MAX))
    {
        o_dac = prev_dac;
    }

fapi_try_exit:
    FAPI_DBG("End TDR Sample Point");
    return fapi2::current_err;
}

/// @brief Calculates max
/// @param[in] i_target             Target
/// @param[in] i_baseAddr           Base address for register writes/reads
/// @param[in] i_group              Groups to run TDR on
/// @param[in] i_lane               Lanes to run TDR on
/// @param[in] i_offset_start       TDR offset to start taking the measurement
/// @param[in] i_offset_end         TDR offset to finish taking the measurement
/// @param[in] i_max_not_min        Check if looking for max or min value
/// @param[out] o_dac               TDR DAC value at desired offset
/// @return FAPI_RC_SUCCESS if arguments are valid
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr_find_limit(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_baseAddr,
        const uint32_t i_group,
        const uint32_t i_offset_start,
        const uint32_t i_offset_end,
        const uint32_t i_lane,
        bool i_max_not_min,
        int32_t& o_limit)
{
    FAPI_DBG("Start TDR Find Limit");

    const int32_t LOOP_MAX = 255; // Loop Max
    const int32_t DAC_MAX = 255;  // The upper limit of the dac
    const int32_t DAC_MIN = 0;    // The lower limit of the dac

    fapi2::buffer<uint64_t> l_data = 0;

    uint64_t l_addr = 0;
    uint32_t l_loop = 0;
    uint32_t l_capture = 0;
    int32_t l_prev_limit = 0;

    // set TDR dac value
    // FAPI_INF("Setting TDR Dac: %d", o_limit);
    l_addr = buildAddr(i_baseAddr, i_group, i_lane, TdrRegisters::tx_cntl15_pl);
    FAPI_TRY(rmwIoHardwareReg(i_target, l_addr, o_limit, TdrConsts::tdrDacStart, TdrConsts::tdrDacLength),
             "Error on RMW to set DAC value to %d at address %d", o_limit, l_addr);

    for (uint32_t l_offset = i_offset_start; l_offset < i_offset_end; l_offset++)
    {
        FAPI_TRY(common_io_tdr_set_pulse_offset(i_target, i_baseAddr, i_group, i_lane, l_offset));

        while (l_loop < LOOP_MAX)
        {
            // set TDR dac value
            if (l_prev_limit != o_limit)
            {
                // FAPI_INF("Setting TDR Dac: %d", o_limit);
                l_addr = buildAddr(i_baseAddr, i_group, i_lane, TdrRegisters::tx_cntl15_pl);
                FAPI_TRY(rmwIoHardwareReg(i_target, l_addr, o_limit, TdrConsts::tdrDacStart, TdrConsts::tdrDacLength),
                         "Error on RMW to set DAC value to %d at address %d", o_limit, l_addr);
                l_prev_limit = o_limit;
            }

            // read the TDR capture value for the selected lane
            FAPI_TRY(common_io_tdr_get_capt_val(i_target, i_baseAddr, i_group, i_lane, l_capture));

            if (l_capture > 0)
            {
                if (i_max_not_min)
                {
                    o_limit++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (i_max_not_min)
                {
                    break;
                }
                else
                {
                    o_limit--;
                    break;
                }
            }

            if (o_limit > DAC_MAX)
            {
                o_limit = DAC_MAX;
                break;
            }
            else if (o_limit < DAC_MIN)
            {
                o_limit = DAC_MIN;
                break;
            }

            l_loop++;
        }

        if (o_limit == DAC_MAX && i_max_not_min)
        {
            break;
        }
        else if (o_limit == DAC_MIN && !i_max_not_min)
        {
            break;
        }
    }

fapi_try_exit:
    FAPI_DBG("End TDR Sample Point");
    return fapi2::current_err;
}

/// @brief Diagnose whether the bus is OPEN, SHORT, or GOOD
/// @param[in] i_bp1            base point 1
/// @param[in] i_bp2            base point 2
/// @param[out] o_result        status of the net (OPEN, SHORT, GOOD)
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode common_io_tdr_diagnose(const uint32_t& i_bp1,
        const uint32_t i_bp2,
        uint32_t& o_result)
{

    const uint32_t MAX = 255 << 1;
    const uint32_t OPEN_THRESHOLD = (3 * MAX) / 5;
    const uint32_t SHORT_THRESHOLD = MAX / 4;
    const uint32_t C_EXPECTED_LOWER = MAX / 4;
    const uint32_t C_EXPECTED_UPPER = (3 * MAX) / 4;

    // Open Cases
    // difference > 3/4 * MAX
    uint32_t diff = (i_bp1 > i_bp2) ? i_bp1 - i_bp2 : i_bp2 - i_bp1;

    if (diff > OPEN_THRESHOLD)
    {
        o_result = TdrResult::Open;
    }
    else if (diff > SHORT_THRESHOLD)
    {
        o_result = TdrResult::NoIssues;
    }
    else if (i_bp1 < C_EXPECTED_LOWER)
    {
        o_result = TdrResult::ShortToGnd;
    }
    else if (i_bp1 > C_EXPECTED_UPPER)
    {
        o_result = TdrResult::ShortToVdd;
    }
    else
    {
        o_result = TdrResult::UnableToDetermine;
    }

    // FAPI_INF("o_result = 0x%04x", o_result);

    FAPI_DBG("End TDR Diagnose");
    return fapi2::current_err;
}

/// @brief Find where the TDR pulse crosses the specified Dac value
/// @param[in] i_target             Target
/// @param[in] i_phase              TDR phase (N:0, P:1)
/// @param[in] i_dac                check for crossing at this Dac value
/// @param[in] i_lane               lane to check
/// @param[in] i_x_min              min x offset
/// @param[in] i_x_max              max x offset
/// @param[out] o_offset            offset where TDR crosses the selected Dac
/// @return FAPI_RC_SUCCESS if arguments are valid
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr_find_horizontal_crossing(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_baseAddr,
        const uint32_t i_group,
        const uint32_t i_phase,
        const uint32_t i_dac,
        const uint32_t i_lane,
        const uint32_t i_x_min,
        const uint32_t i_x_max,
        uint32_t& o_offset)
{
    const uint8_t c_phaseSelBit = 57;
    fapi2::buffer<uint64_t> l_cntl4_data = 0;
    uint64_t l_addr = 0;
    uint32_t x_vals[2] = {i_x_min, i_x_max};
    uint32_t y_vals[2] = {0, 0};
    uint32_t current_x = 0;
    uint32_t current_y = 0;

    // set TDR Dac and phase sel
    FAPI_INF("Horizontal Crossing - Setting (TDR Dac/Phase): (%d / %d)", i_dac, i_phase);
    l_addr = buildAddr(i_baseAddr, i_group, i_lane, TdrRegisters::tx_cntl15_pl);
    FAPI_TRY(rmwIoHardwareReg(i_target, l_addr, i_dac, TdrConsts::tdrDacStart, TdrConsts::tdrDacLength),
             "Error on RMW to set DAC value to %d at address %d", i_dac, l_addr);
    l_addr = buildAddr(i_baseAddr, i_group, 0, TdrRegisters::tx_ctl_cntl4_pg);
    FAPI_TRY(rmwIoHardwareReg(i_target, l_addr, i_phase, c_phaseSelBit, 1),
             "Error on RMW to set phase select to %d at address %d", i_phase, l_addr);

    // Check xMin horizontal crossing
    // set TDR pulse offset
    FAPI_INF("Horizontal Crossing - Setting TDR Pulse Offset: %d", x_vals[0]);
    FAPI_TRY(common_io_tdr_set_pulse_offset(i_target, i_baseAddr, i_group, i_lane, x_vals[0]));
    FAPI_TRY(common_io_tdr_get_capt_val(i_target, i_baseAddr, i_group, i_lane, y_vals[0]));

    // Check xMax horizontal crossing
    // set TDR pulse offset
    FAPI_INF("Horizontal Crossing - Setting TDR Pulse Offset: %d", x_vals[1]);
    FAPI_TRY(common_io_tdr_set_pulse_offset(i_target, i_baseAddr, i_group, i_lane, x_vals[1]));
    FAPI_TRY(common_io_tdr_get_capt_val(i_target, i_baseAddr, i_group, i_lane, y_vals[1]));

    FAPI_INF("y_vals[0]: %d   y_vals[1]: %d", y_vals[0], y_vals[1]);

    // If the two y_vals are the same, assert error
    FAPI_ASSERT(y_vals[0] != y_vals[1],
                fapi2::POZ_IO_TDR_EDGE_ERROR()
                .set_TARGET_CHIP(i_target),
                "There is no horizontal edge crossing");

    while ((x_vals[1] - x_vals[0]) > 1)
    {
        current_x = x_vals[0] + ((x_vals[1] - x_vals[0]) / 2);
        FAPI_TRY(common_io_tdr_set_pulse_offset(i_target, i_baseAddr, i_group, i_lane, current_x));
        FAPI_TRY(common_io_tdr_get_capt_val(i_target, i_baseAddr, i_group, i_lane, current_y));

        // FAPI_INF("(%03d,%03d) < ",
        //          x_vals[0], y_vals[0]);
        FAPI_INF("TDR H-Crossing Binary Search dac(%3d) xoffset(%3d) sample(%1d)", i_dac, current_x, current_y);
        // FAPI_INF("(%03d,%03d)",
        //          x_vals[1], y_vals[1]);

        if (current_y == y_vals[0])
        {
            x_vals[0] = current_x;
        }
        else
        {
            x_vals[1] = current_x;
        }
    }

    if (y_vals[0] == 1)
    {
        o_offset = x_vals[0];
    }
    else
    {
        o_offset = x_vals[1];
    }

fapi_try_exit:
    FAPI_DBG("End TDR Find Horizontal Crossing");
    return fapi2::current_err;
}

/// @brief Find where the TDR pulse crosses the specified Dac value
/// @param[in] i_target             Target
/// @param[in] i_phase              TDR phase (N:0, P:1)
/// @param[in] i_dac                check for crossing at this Dac value
/// @param[in] i_lane               lane to check
/// @param[in] i_x_min              min x offset
/// @param[out] o_offset            offset where TDR crosses the selected Dac
/// @return FAPI_RC_SUCCESS if arguments are valid
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr_find_short_crossing(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_baseAddr,
        const uint32_t i_group,
        const uint32_t i_phase,
        const uint32_t i_dac,
        const uint32_t i_lane,
        const uint32_t i_x_offset,
        const uint32_t i_pulse_width,
        bool i_direction,
        int32_t& o_offset)
{
    const uint8_t c_phaseSelBit = 57;
    fapi2::buffer<uint64_t> l_cntl4_data = 0;
    uint64_t l_addr = 0;
    uint32_t current_x = i_x_offset;
    uint32_t current_y = 0;
    uint32_t prev_y = 0;
    int32_t step = 0;

    step = (i_direction) ? 1 : -1; // increment/decrement determined by which way we are scanning

    // set TDR Dac and phase sel
    FAPI_INF("Short Crossing - Setting (TDR Dac/Phase): (%d / %d)", i_dac, i_phase);
    l_addr = buildAddr(i_baseAddr, i_group, i_lane, TdrRegisters::tx_cntl15_pl);
    FAPI_TRY(rmwIoHardwareReg(i_target, l_addr, i_dac, TdrConsts::tdrDacStart, TdrConsts::tdrDacLength),
             "Error on RMW to set DAC value to %d at address %d", i_dac, l_addr);
    l_addr = buildAddr(i_baseAddr, i_group, 0, TdrRegisters::tx_ctl_cntl4_pg);
    FAPI_TRY(rmwIoHardwareReg(i_target, l_addr, i_phase, c_phaseSelBit, 1),
             "Error on RMW to set phase select to %d at address %d", i_phase, l_addr);

    // set TDR pulse offset
    FAPI_INF("Short Crossing - Setting TDR Pulse Offset: %d", current_x);
    FAPI_TRY(common_io_tdr_set_pulse_offset(i_target, i_baseAddr, i_group, i_lane, current_x));
    FAPI_TRY(common_io_tdr_get_capt_val(i_target, i_baseAddr, i_group, i_lane, current_y));
    prev_y = current_y;

    while ((current_y == prev_y))
    {
        current_x = current_x + step;
        FAPI_TRY(common_io_tdr_set_pulse_offset(i_target, i_baseAddr, i_group, i_lane, current_x));
        FAPI_TRY(common_io_tdr_get_capt_val(i_target, i_baseAddr, i_group, i_lane, current_y));

        FAPI_INF("(%05d,%d (%d))",
                 current_x, current_y, prev_y);

        if (current_x <= 0 || current_x >= i_pulse_width)
        {
            current_x = -1;
            break;
        }
    }

    o_offset = current_x;

fapi_try_exit:
    FAPI_DBG("End TDR Find Short Crossing");
    return fapi2::current_err;
}

/// @brief Return the TDR capture value
/// @param[in] i_target             Target
/// @param[in] i_lane               lane to check
/// @param[out] o_tdr_val           offset where TDR crosses the selected Dac
/// @return FAPI_RC_SUCCESS if arguments are valid
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr_get_capt_val(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_baseAddr,
        const uint32_t i_group,
        const uint32_t i_lane,
        uint32_t& o_tdr_val)
{
    const uint32_t TDR_NS_DELAY = 500000; // 500us
    const uint32_t TDR_SIM_CYCLES = 10;
    const uint8_t c_capt_val_sig_bit = 63;
    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_addr = 0x0;

    fapi2::delay(TDR_NS_DELAY, TDR_SIM_CYCLES);

    // read the TDR capture value for the selected lane
    l_addr = buildAddr(i_baseAddr, i_group, i_lane, TdrRegisters::tx_stat1_pl);
    FAPI_TRY(fapi2::getScom(i_target, l_addr, l_data));

    o_tdr_val = l_data.getBit<c_capt_val_sig_bit>();

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Set the TDR pulse offset value
/// @param[in] i_target             Target
/// @param[in] i_pulse_offset       TDR pulse offset
/// @return FAPI_RC_SUCCESS if arguments are valid
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_io_tdr_set_pulse_offset(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_baseAddr,
        const uint32_t i_group,
        const uint32_t i_lane,
        const uint32_t i_pulse_offset)
{
    const uint8_t c_pulseOffsetBit = 48;
    const uint8_t c_pulseOffsetLen = 15;
    fapi2::buffer<uint64_t> l_cntl5_data = 0;
    uint64_t l_addr = 0;

    l_addr = buildAddr(i_baseAddr, i_group, 0, TdrRegisters::tx_ctl_cntl5_pg);
    FAPI_TRY(rmwIoHardwareReg(i_target, l_addr, i_pulse_offset, c_pulseOffsetBit, c_pulseOffsetLen),
             "Error on RMW to set pulse offset to %d to address %d", i_pulse_offset, l_addr);

fapi_try_exit:
    return fapi2::current_err;
}
