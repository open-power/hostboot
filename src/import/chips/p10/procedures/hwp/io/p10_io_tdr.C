/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_tdr.C $         */
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
// EKB-Mirror-To: hostboot
///
/// @file p10_io_tdr.C
/// @brief Common TDR functions and constants
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------

#include <fapi2.H>
#include <vector>
#include <utils.H>
#include <p10_io_lib.H>
#include <p10_io_tdr.H>
#include <p10_scom_iohs.H>

fapi2::ReturnCode p10_io_tdr_initialize(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>&, uint32_t, const uint32_t,
                                        uint32_t);
fapi2::ReturnCode p10_io_tdr_get_tdr_offsets(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>&, const uint32_t, uint32_t&);
fapi2::ReturnCode p10_io_tdr_sample_point(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>&, uint32_t, uint32_t, int32_t&);
fapi2::ReturnCode p10_io_tdr_diagnose(const uint32_t, const uint32_t, uint32_t&);
fapi2::ReturnCode p10_io_tdr_find_horizontal_crossing(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>&, const uint32_t,
        const uint32_t, const uint32_t, const uint32_t, const uint32_t, uint32_t&);
fapi2::ReturnCode p10_io_tdr_find_short_crossing(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>&, const uint32_t,
        const uint32_t, const uint32_t, const uint32_t, bool, uint32_t&);
fapi2::ReturnCode p10_io_tdr_get_capt_val(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>&, const uint64_t, uint32_t&);
fapi2::ReturnCode p10_io_tdr_set_pulse_offset(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>&, const uint32_t);

enum TdrResult
{
    None              = 0x0000,
    Good              = 0x0010,
    Open              = 0x0020,
    Short             = 0x0030,
    ShortToGnd        = 0x0001 | Short,
    ShortToVdd        = 0x0002 | Short,
    NotSupported      = 0x4000,
    UnableToDetermine = 0x8000
};

/// @brief Use TDR to check for net opens and shorts
/// @param[in] i_iolink_target      IOLINK target to get thread id for
/// @param[in] i_lanes              Lanes to run TDR on
/// @param[out] o_status            Status of the net (Open, Short, Good)
/// @param[out] o_length_mm         Length from TX to open (in mm)
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_tdr(
    const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>& i_iolink_target,
    const std::vector<uint32_t>& i_lanes,
    std::vector<uint32_t>& o_status,
    std::vector<uint32_t>& o_length_mm)
{
    FAPI_DBG("Begin TDR Isolation");

    const uint32_t c_pulse_width = 100;
    // const uint32_t c_fs_per_inch = 165000; // 4ns / (39.37inch/meter) = 101599
    const float c_fs_per_mm = 6496;  //165000 / 25.4

    uint32_t min_offset = 0;
    uint32_t max_offset = 0;
    uint32_t l_lane_translate = 0;                 // lane index value
    uint32_t tdr_offset_width = 0;
    uint32_t o_length_ui = 0;
    float c_fs_per_ui = 0;

    int32_t base_point_y1 = 0;
    int32_t base_point_y2 = 0;

    bool loopExit = false;
    fapi2::ATTR_CHIP_EC_FEATURE_DD2_TDR_Type l_tdr_dd2;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_iolink_num;
    fapi2::ATTR_FREQ_IOHS_LINK_MHZ_Type l_iohs_freq;

    char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
    auto l_iohs_target = i_iolink_target.getParent<fapi2::TARGET_TYPE_IOHS>();
    auto l_chip_target = l_iohs_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    // check to see if we are dd1 or dd2, will determine how we calculate the length of the open
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_DD2_TDR,
                           l_chip_target, l_tdr_dd2));


    fapi2::toString(i_iolink_target, l_tgt_str, sizeof(l_tgt_str));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_iolink_target, l_iolink_num),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
    FAPI_DBG("IOLINK Target: %s   (unit): %d", l_tgt_str, l_iolink_num);

    // check the IOHS frequency
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_IOHS_LINK_MHZ, l_iohs_target, l_iohs_freq),
             "Error from FAPI_ATTR_GET (ATTR_FREQ_IOHS_LINK_MHZ)");

    switch (l_iohs_freq)
    {
        case 32500:
            {
                c_fs_per_ui = 30769;  // 32.5Gbps
                break;
            }

        case 32000:
            {
                c_fs_per_ui = 31250;  // 32.0Gbps
                break;
            }

        case 31875:
            {
                c_fs_per_ui = 31372;  // 31.875Gbps
                break;
            }

        case 25781:
            {
                c_fs_per_ui = 38788;  // 25.781Gbps
                break;
            }

        default:
            {
                break;
            }
    }

    FAPI_DBG("Your iohs freq: %d   -- c_fs_per_ui: %d", l_iohs_freq, c_fs_per_ui);

    FAPI_TRY(p10_io_tdr_get_tdr_offsets(l_iohs_target, c_pulse_width, tdr_offset_width));
    FAPI_DBG("***TDR Offset width: %d", tdr_offset_width);

    min_offset = tdr_offset_width / 4;
    max_offset = (tdr_offset_width * 3) / 4;

    if(l_iolink_num % 2)
    {
        l_lane_translate += 9;    // if we are odd, we are the second half of the bus
    }

    // loop through each of the specified lanes
    for(uint32_t l_index = 0; l_index < i_lanes.size(); l_index++)
    {
        // reset the length to 0 for each lane
        o_length_ui = 0;

        // loop through each of the 2 phases
        for(uint32_t l_phase = 0; l_phase < 2; l_phase++)
        {
            FAPI_DBG("Looping on Lane(%d) and Phase(%d)", (i_lanes[l_index] + l_lane_translate), l_phase);
            FAPI_TRY(p10_io_tdr_initialize(l_iohs_target, (i_lanes[l_index] + l_lane_translate), c_pulse_width, l_phase));

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

            FAPI_TRY(p10_io_tdr_sample_point(l_iohs_target, min_offset, (i_lanes[l_index] + l_lane_translate), base_point_y1));
            FAPI_TRY(p10_io_tdr_sample_point(l_iohs_target, max_offset, (i_lanes[l_index] + l_lane_translate), base_point_y2));

            FAPI_DBG( "Base Point 1 (X,Y): %3d,%3d", min_offset, base_point_y1 );
            FAPI_DBG( "Base Point 2 (X,Y): %3d,%3d", max_offset, base_point_y2 );

            FAPI_TRY(p10_io_tdr_diagnose(base_point_y1, base_point_y2, o_status[l_index]));

            switch( o_status[l_index] )
            {
                case TdrResult::Open:
                    {
                        FAPI_DBG("TDR Open found");
                        uint32_t x1_crossing = 0;
                        uint32_t x2_crossing = 0;
                        uint32_t max = ( base_point_y1 > base_point_y2 ) ? base_point_y1 : base_point_y2;
                        uint32_t min = ( base_point_y1 > base_point_y2 ) ? base_point_y2 : base_point_y1;
                        FAPI_TRY( p10_io_tdr_find_horizontal_crossing(
                                      l_iohs_target,
                                      l_phase,
                                      ( min + (max - min) / 4) ,
                                      (i_lanes[l_index] + l_lane_translate),
                                      min_offset,
                                      max_offset,
                                      x1_crossing ) );
                        FAPI_TRY( p10_io_tdr_find_horizontal_crossing(
                                      l_iohs_target,
                                      l_phase,
                                      ( min + ((max - min) * 3) / 4) ,
                                      (i_lanes[l_index] + l_lane_translate),
                                      min_offset,
                                      max_offset,
                                      x2_crossing ) );

                        if(l_tdr_dd2)       // if true, this is dd2
                        {
                            o_length_ui = (x1_crossing > x2_crossing) ? ((x1_crossing - x2_crossing) / 2) : ((x2_crossing - x1_crossing) / 2);
                        }
                        else
                        {
                            o_length_ui = (x1_crossing > x2_crossing) ? ((x1_crossing - x2_crossing) / 4) : ((x2_crossing - x1_crossing) / 4);
                        }

                        FAPI_DBG( "TDR Result:: Open Fault: %d UI from Driver.", o_length_ui );
                        loopExit = true;    // if we find an open, no need to run the next phase
                        break;

                    }

                case TdrResult::Short:
                    {
                        FAPI_DBG("TDR Short found");
                        uint32_t x1_crossing = 0;
                        uint32_t x2_crossing = 0;
                        int32_t dacval = 0;
                        int32_t dacmin = 255;
                        int32_t dacmax = 0;
                        int32_t middac = 0;

                        // first we have to scan the entire waveform from 1/4 offset to 3/4 offset for the max/min values
                        for (uint32_t soffset = min_offset; soffset <= max_offset; soffset++ )
                        {
                            FAPI_TRY(p10_io_tdr_sample_point(l_iohs_target, soffset, (i_lanes[l_index] + l_lane_translate), dacval));
                            dacmin = (dacval < dacmin) ? dacval : dacmin;
                            dacmax = (dacval > dacmax) ? dacval : dacmax;
                        }

                        middac = (dacmax - dacmin) / 2;

                        // search from min offset to the right
                        FAPI_TRY( p10_io_tdr_find_short_crossing(
                                      l_iohs_target,
                                      l_phase,
                                      ( dacmin + middac) ,
                                      (i_lanes[l_index] + l_lane_translate),
                                      min_offset,
                                      true,
                                      x1_crossing ) );
                        // search from max offset to the left
                        FAPI_TRY( p10_io_tdr_find_short_crossing(
                                      l_iohs_target,
                                      l_phase,
                                      ( dacmin + middac) ,
                                      (i_lanes[l_index] + l_lane_translate),
                                      max_offset,
                                      false,
                                      x2_crossing ) );

                        if(l_tdr_dd2)       // if true, this is dd2
                        {
                            o_length_ui = (x1_crossing > x2_crossing) ? ((x1_crossing - x2_crossing) / 2) : ((x2_crossing - x1_crossing) / 2);
                        }
                        else
                        {
                            o_length_ui = (x1_crossing > x2_crossing) ? ((x1_crossing - x2_crossing) / 4) : ((x2_crossing - x1_crossing) / 4);
                        }

                        FAPI_DBG( "TDR Result:: Short Fault: %d UI from Driver.", o_length_ui );
                        loopExit = true;    // if we find an short, no need to run the next phase
                        break;
                    }


                case TdrResult::ShortToGnd:
                case TdrResult::ShortToVdd:
                    {
                        o_status[l_index] |= TdrResult::NotSupported;
                    }
            }

            if (loopExit)
            {
                break;
            }
        }

        // convert UI into inches
        o_length_mm[l_index] = (o_length_ui * c_fs_per_ui) / c_fs_per_mm;
    }


fapi_try_exit:
    FAPI_DBG("End TDR Isolation");
    return fapi2::current_err;
}

/// @brief Initialize the phy for TDR
/// @param[in] i_target             IOHS target to get thread id for
/// @param[in] i_lane               Lanes to run TDR on
/// @param[in] i_pw                 TDR pulse width
/// @param[in] i_phase              phase to select, either N or P
/// @return FAPI_RC_SUCCESS if arguments are valid

fapi2::ReturnCode p10_io_tdr_initialize(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
                                        uint32_t i_lane,
                                        const uint32_t i_pw,
                                        uint32_t i_phase)
{
    using namespace scomt::iohs;

    fapi2::buffer<uint64_t> l_data_buf = 0;
    uint32_t l_tdr_enable = 1;

    FAPI_DBG("Begin TDR Initialization");
    // Set HS_BIST_EN to 0
    FAPI_TRY(GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG(i_target, l_data_buf));
    SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(0, l_data_buf);
    FAPI_TRY(PUT_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG(i_target, l_data_buf));

    // set TDR pulse width
    FAPI_TRY(GET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG(i_target, l_data_buf));
    SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH(i_pw, l_data_buf);
    FAPI_TRY(PUT_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG(i_target, l_data_buf));

    // set TDR phase sel
    FAPI_TRY(GET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG(i_target, l_data_buf));
    SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(i_phase, l_data_buf);
    FAPI_TRY(PUT_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG(i_target, l_data_buf));

    // tdr_enable = 1, pl, tx_cntl3_pl
    FAPI_TRY(p10_io_iohs_put_pl_regs_single(i_target,
                                            IOO_TX0_0_DD_TX_BIT_REGS_CNTL3_PL,
                                            IOO_TX0_0_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
                                            1,
                                            i_lane,
                                            l_tdr_enable));

fapi_try_exit:
    FAPI_DBG("End TDR Initialization");
    return fapi2::current_err;

}

/// @brief Calculates the total TDR offsets
/// @param[in] i_target             IOHS target
/// @param[in] i_pw                 TDR pulse width
/// @param[out] o_tdr_width         TDR offset width
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_tdr_get_tdr_offsets(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const uint32_t i_pw,
        uint32_t& o_tdr_width)
{
    uint32_t tx_mode = 16;          // 16to1 mode is always set for Abus
    fapi2::buffer<uint64_t> l_mode1_data = 0;

    o_tdr_width = 4 * tx_mode * i_pw;
    FAPI_DBG("TDR Offset width: %d", o_tdr_width);

fapi_try_exit:
    return fapi2::current_err;
}


/// @brief Calculates the TDR sample points
/// @param[in] i_target             IOHS target
/// @param[in] i_offset             TDR offset to take the measurement
/// @param[out] o_dac               TDR DAC value at desired offset
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_tdr_sample_point(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        uint32_t i_offset,
        uint32_t i_lane,
        int32_t& o_dac)
{

    using namespace scomt::iohs;
    fapi2::buffer<uint64_t> l_data = 0;
    const int32_t DAC_MAX  = 255;   // The upper limit of the dac
    const int32_t DAC_MIN  = 0;     // The lower limit of the dac
    const uint32_t DIRECTION_CHANGE_MAX = 3;
    uint32_t loop_count = 0;
    uint32_t direction_change_count = 0;
    int32_t direction[2] = {0, 0};
    uint32_t tdr_capt_data = 0;
    int32_t step = 1;
    int32_t prev_dac = 0;
    // int data[2] = { 0xFFFF, 0xFFFF };

    // set TDR pulse offset
    // FAPI_TRY(GET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL5_PG(i_target, l_data));
    // SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET(i_offset, l_data);
    // FAPI_TRY(PUT_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL5_PG(i_target, l_data));
    FAPI_DBG("Start TDR Sample Point");
    FAPI_DBG("setting pulse offset: %d", i_offset);
    FAPI_TRY(p10_io_tdr_set_pulse_offset(i_target, i_offset));

    while( loop_count < DAC_MAX )
    {
        // If dac is outside of acceptable range assert error
        FAPI_ASSERT((o_dac < DAC_MAX),
                    fapi2::P10_IO_TDR_DAC_RANGE_ERROR()
                    .set_TARGET(i_target),
                    "The DAC calibrated above of the max DAC range");
        // If dac is outside of acceptable range assert error
        FAPI_ASSERT((o_dac > DAC_MIN),
                    fapi2::P10_IO_TDR_DAC_RANGE_ERROR()
                    .set_TARGET(i_target),
                    "The DAC calibrated below of the min DAC range");

        direction[1] = direction[0];

        // set TDR dac value
        FAPI_DBG("Setting TDR Dac: %d", o_dac);
        FAPI_TRY(GET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG(i_target, l_data));
        SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(o_dac, l_data);
        FAPI_TRY(PUT_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG(i_target, l_data));

        // read the TDR capture value for the selected lane
        FAPI_TRY(p10_io_tdr_get_capt_val(i_target, i_lane, tdr_capt_data));

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

        loop_count += 1;
    }

    if (prev_dac < o_dac)
    {
        o_dac = prev_dac;
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
fapi2::ReturnCode p10_io_tdr_diagnose(const uint32_t i_bp1,
                                      const uint32_t i_bp2,
                                      uint32_t& o_result)
{

    const uint32_t MAX = 255;

    // Open Cases
    // difference > 3/4 * MAX
    uint32_t diff = (i_bp1 > i_bp2) ? i_bp1 - i_bp2 : i_bp2 - i_bp1;

    if(diff > ((3 * MAX) / 5))
    {
        o_result = TdrResult::Open;
    }
    else if(diff > (MAX / 4))
    {
        o_result = TdrResult::Good;
    }
    else
    {
        o_result = TdrResult::Short;
    }


fapi_try_exit:
    FAPI_DBG("End TDR Diagnose");
    return fapi2::current_err;
}


/// @brief Find where the TDR pulse crosses the specified Dac value
/// @param[in] i_target             IOHS Target
/// @param[in] i_phase              TDR phase (N:0, P:1)
/// @param[in] i_dac                check for crossing at this Dac value
/// @param[in] i_lane               lane to check
/// @param[in] i_x_min              min x offset
/// @param[in] i_x_max              max x offset
/// @param[out] o_offset            offset where TDR crosses the selected Dac
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_tdr_find_horizontal_crossing(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const uint32_t i_phase,
        const uint32_t i_dac,
        const uint32_t i_lane,
        const uint32_t i_x_min,
        const uint32_t i_x_max,
        uint32_t& o_offset)
{

    using namespace scomt::iohs;
    fapi2::buffer<uint64_t> l_cntl4_data = 0;
    uint32_t x_vals[2] = {i_x_min, i_x_max};
    uint32_t y_vals[2] = {0, 0};
    uint32_t current_x = 0;
    uint32_t current_y = 0;


    // char l_iohs_target[fapi2::MAX_ECMD_STRING_LEN];
    // fapi2::toString(i_target, l_iohs_target, sizeof(l_iohs_target));

    // set TDR Dac and phase sel
    FAPI_DBG("Horizontal Crossing - Setting (TDR Dac/Phase): (%d / %d)", i_dac, i_phase);
    FAPI_TRY(GET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG(i_target, l_cntl4_data));
    SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(i_dac, l_cntl4_data);
    SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(i_phase, l_cntl4_data);
    FAPI_TRY(PUT_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG(i_target, l_cntl4_data));

    // Check xMin horizontal crossing
    // set TDR pulse offset
    FAPI_DBG("Horizontal Crossing - Setting TDR Pulse Offset: %d", x_vals[0]);
    FAPI_TRY(p10_io_tdr_set_pulse_offset(i_target, x_vals[0]));
    FAPI_TRY(p10_io_tdr_get_capt_val(i_target, i_lane, y_vals[0]));


    // Check xMax horizontal crossing
    // set TDR pulse offset
    FAPI_DBG("Horizontal Crossing - Setting TDR Pulse Offset: %d", x_vals[1]);
    FAPI_TRY(p10_io_tdr_set_pulse_offset(i_target, x_vals[1]));
    FAPI_TRY(p10_io_tdr_get_capt_val(i_target, i_lane, y_vals[1]));

    FAPI_DBG("y_vals[0]: %d   y_vals[1]: %d", y_vals[0], y_vals[1]);

    // If the two y_vals are the same, assert error
    FAPI_ASSERT(y_vals[0] != y_vals[1],
                fapi2::P10_IO_TDR_EDGE_ERROR()
                .set_TARGET(i_target),
                "There is no horizontal edge crossing");

    while( ( x_vals[1] - x_vals[0] ) > 1 )
    {
        current_x = x_vals[0] + ( (x_vals[1] - x_vals[0]) / 2 );
        FAPI_TRY(p10_io_tdr_set_pulse_offset(i_target, current_x));
        FAPI_TRY(p10_io_tdr_get_capt_val( i_target, i_lane, current_y ) );

        FAPI_DBG("(%03d,%03d) < (%03d,%03d) < (%03d,%03d)",
                 x_vals[0], y_vals[0],
                 current_x, current_y,
                 x_vals[1], y_vals[1] );

        if( current_y == y_vals[0] )
        {
            x_vals[0] = current_x;
        }
        else
        {
            x_vals[1] = current_x;
        }
    }

    if( y_vals[0] == 1 )
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
/// @param[in] i_target             IOHS Target
/// @param[in] i_phase              TDR phase (N:0, P:1)
/// @param[in] i_dac                check for crossing at this Dac value
/// @param[in] i_lane               lane to check
/// @param[in] i_x_min              min x offset
/// @param[out] o_offset            offset where TDR crosses the selected Dac
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_tdr_find_short_crossing(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const uint32_t i_phase,
        const uint32_t i_dac,
        const uint32_t i_lane,
        const uint32_t i_x_offset,
        bool i_direction,
        uint32_t& o_offset)
{

    using namespace scomt::iohs;
    fapi2::buffer<uint64_t> l_cntl4_data = 0;
    // uint32_t x_vals[1] = {i_x_min};
    // uint32_t y_vals[2] = {0,0};
    // uint32_t counter = 2;       // the first 2 offsets read before the while loop
    uint32_t current_x = i_x_offset;
    uint32_t current_y = 0;
    uint32_t prev_y = 0;
    int32_t step = 0;

    step = (i_direction) ? 1 : -1;      // increment/decrement determined by which way we are scanning


    // char l_iohs_target[fapi2::MAX_ECMD_STRING_LEN];
    // fapi2::toString(i_target, l_iohs_target, sizeof(l_iohs_target));

    // set TDR Dac and phase sel
    FAPI_DBG("Short Crossing - Setting (TDR Dac/Phase): (%d / %d)", i_dac, i_phase);
    FAPI_TRY(GET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG(i_target, l_cntl4_data));
    SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(i_dac, l_cntl4_data);
    SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(i_phase, l_cntl4_data);
    FAPI_TRY(PUT_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG(i_target, l_cntl4_data));

    // set TDR pulse offset
    FAPI_DBG("Short Crossing - Setting TDR Pulse Offset: %d", current_x);
    FAPI_TRY(p10_io_tdr_set_pulse_offset(i_target, current_x));
    FAPI_TRY(p10_io_tdr_get_capt_val(i_target, i_lane, current_y));
    prev_y = current_y;

    // Check xMax horizontal crossing
    // set TDR pulse offset
    // FAPI_DBG("Short Crossing - Setting TDR Pulse Offset: %d", (x_vals[0]+1));
    // FAPI_TRY(p10_io_tdr_set_pulse_offset(i_target, (x_vals[0]+1)));
    // FAPI_TRY(p10_io_tdr_get_capt_val(i_target, i_lane, y_vals[1]));

    // FAPI_DBG("y_vals[0]: %d   y_vals[1]: %d", current_y, prev_y);

    // If the two y_vals are the same, assert error
    // FAPI_ASSERT(y_vals[0] != y_vals[1],
    //             fapi2::P10_IO_TDR_EDGE_ERROR()
    //             .set_TARGET(i_target),
    //             "There is no horizontal edge crossing for this short");

    while( ( current_y == prev_y )  )
    {
        current_x = current_x + step;
        FAPI_TRY(p10_io_tdr_set_pulse_offset(i_target, current_x));
        FAPI_TRY(p10_io_tdr_get_capt_val( i_target, i_lane, current_y ) );

        FAPI_DBG("(%05d,%d (%d))",
                 current_x, current_y, prev_y );


    }

    o_offset = current_x;


fapi_try_exit:
    FAPI_DBG("End TDR Find Short Crossing");
    return fapi2::current_err;
}


/// @brief Return the TDR capture value
/// @param[in] i_target             IOHS Target
/// @param[in] i_lane               lane to check
/// @param[out] o_tdr_val           offset where TDR crosses the selected Dac
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_tdr_get_capt_val(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const uint64_t i_lane,
        uint32_t& o_tdr_val)
{

    using namespace scomt::iohs;
    const uint32_t SCOM_LANE_SHIFT = 32;
    const uint64_t SCOM_LANE_MASK  = 0x0000001F00000000;
    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_addr = 0x0;

    // read the TDR capture value for the selected lane
    l_addr = IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL | ((i_lane << SCOM_LANE_SHIFT) & SCOM_LANE_MASK);
    FAPI_TRY(fapi2::getScom(i_target, l_addr, l_data));

    FAPI_TRY(l_data.extractToRight(o_tdr_val, IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL, 1));

fapi_try_exit:
    return fapi2::current_err;
}


/// @brief Set the TDR pulse offset value
/// @param[in] i_target             IOHS Target
/// @param[in] i_pulse_offset       TDR pulse offset
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_tdr_set_pulse_offset(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const uint32_t i_pulse_offset)
{

    using namespace scomt::iohs;
    fapi2::buffer<uint64_t> l_cntl5_data = 0;

    FAPI_TRY(GET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL5_PG(i_target, l_cntl5_data));
    SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET(i_pulse_offset, l_cntl5_data);
    FAPI_TRY(PUT_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL5_PG(i_target, l_cntl5_data));

fapi_try_exit:
    return fapi2::current_err;
}
