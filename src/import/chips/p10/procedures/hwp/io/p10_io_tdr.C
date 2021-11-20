/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_tdr.C $         */
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
fapi2::ReturnCode p10_io_tdr_find_short_crossing(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const uint32_t i_phase,
        const uint32_t i_dac,
        const uint32_t i_lane,
        const uint32_t i_x_offset,
        const uint32_t i_pulse_width,
        bool i_direction,
        int32_t& o_offset);
fapi2::ReturnCode p10_io_tdr_get_capt_val(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>&, const uint64_t, uint32_t&);
fapi2::ReturnCode p10_io_tdr_set_pulse_offset(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>&, const uint32_t);
fapi2::ReturnCode p10_io_tdr_find_limit(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
                                        uint32_t i_offset_start,
                                        uint32_t i_offset_end,
                                        uint32_t i_lane,
                                        bool i_max_not_min,
                                        int32_t& o_limit);

/// @brief Use TDR to check for net opens and shorts
/// @param[in] i_iolink_target      IOLINK target to get thread id for
/// @param[in] i_lanes              Lanes to run TDR on
/// @param[out] o_status            Status of the net (Open, Short, Good)
/// @param[out] o_length_ps         Length from TX to open (in ps)
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_tdr(
    const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>& i_iolink_target,
    const std::vector<uint32_t>& i_lanes,
    std::vector<uint32_t>& o_status,
    std::vector<uint32_t>& o_length_ps)
{
    using namespace scomt::iohs;

    FAPI_DBG("Begin TDR Isolation (Version 0.0)");

    const uint32_t c_pulse_width = 100;

    uint32_t min_offset       = 0;
    uint32_t max_offset       = 0;
    uint32_t l_lane_translate = 0;                 // lane index value
    uint32_t l_xlate_lane     = 0;
    uint32_t tdr_offset_width = 0;
    uint32_t o_length_ui      = 0;
    float c_fs_per_ui         = 0;
    int32_t base_point_y1     = 0;
    int32_t base_point_y2     = 0;
    // uint32_t min_length_ui    = 0;
    std::vector<uint32_t> l_status(2, TdrResult::None);
    std::vector<uint32_t> l_length_ui(2, 0ul);

    bool loopExit = false;
    bool l_action_state = false;
    fapi2::ATTR_CHIP_EC_FEATURE_DD2_TDR_Type l_tdr_dd2;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_iolink_num;
    fapi2::ATTR_FREQ_IOHS_LINK_MHZ_Type l_iohs_freq;
    fapi2::buffer<uint64_t> l_dl_status;
    fapi2::buffer<uint64_t> l_phy_psave_data;

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

    // only support HWP execution when DL layer is down -- if link is up, skip
    // execution and return DidNotRun status on all lanes
    FAPI_TRY(GET_DLP_DLL_STATUS(l_iohs_target, l_dl_status));

    FAPI_TRY(p10_iohs_phy_get_action_state(l_iohs_target, l_action_state))

    if ((((l_iolink_num % 2) == 0) && (l_dl_status.getBit<DLP_DLL_STATUS_0_LINK_UP>())) || // even link
        (((l_iolink_num % 2) == 1) && (l_dl_status.getBit<DLP_DLL_STATUS_1_LINK_UP>())) || // odd link
        l_action_state)
    {
        for (uint32_t l_index = 0; l_index < i_lanes.size(); l_index++)
        {
            o_status[l_index] = TdrResult::DidNotRun;
        }

        FAPI_DBG("Analysis skipped, link is up or action in progress...");
        goto fapi_try_exit;
    }

    FAPI_TRY(p10_iohs_phy_set_action_state(l_iohs_target, 0x1));

    // ensure that TX psav force/fence controls are dropped prior to running TDR
    // given that we only support execution when the DL layer is down, we should be
    // safe to turn everything on here
    if ((l_iolink_num % 2) == 0)
    {
        FAPI_TRY(fapi2::getScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG, l_phy_psave_data));
        l_phy_psave_data.clearBit<48, 9>();
        FAPI_TRY(fapi2::putScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG, l_phy_psave_data));

        FAPI_TRY(fapi2::getScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG, l_phy_psave_data));
        l_phy_psave_data.clearBit<48, 9>();
        FAPI_TRY(fapi2::putScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG, l_phy_psave_data));
    }
    else
    {
        FAPI_TRY(fapi2::getScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG, l_phy_psave_data));
        l_phy_psave_data.clearBit<57, 7>();
        FAPI_TRY(fapi2::putScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG, l_phy_psave_data));

        FAPI_TRY(fapi2::getScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG, l_phy_psave_data));
        l_phy_psave_data.clearBit<48, 2>();
        FAPI_TRY(fapi2::putScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG, l_phy_psave_data));

        FAPI_TRY(fapi2::getScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG, l_phy_psave_data));
        l_phy_psave_data.clearBit<57, 7>();
        FAPI_TRY(fapi2::putScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG, l_phy_psave_data));

        FAPI_TRY(fapi2::getScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG, l_phy_psave_data));
        l_phy_psave_data.clearBit<48, 2>();
        FAPI_TRY(fapi2::putScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG, l_phy_psave_data));
    }

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

    if (!l_tdr_dd2)
    {
        tdr_offset_width *= 2;
    }

    FAPI_DBG("***TDR Offset width: %d", tdr_offset_width);

    min_offset = (tdr_offset_width * 3) / 8;
    max_offset = (tdr_offset_width * 7) / 8;

    if(l_iolink_num % 2)
    {
        l_lane_translate += 9;    // if we are odd, we are the second half of the bus
    }

    // loop through each of the specified lanes
    for(uint32_t l_index = 0; l_index < i_lanes.size(); l_index++)
    {
        // Map DL / Package Lane to PHY Lanes
        // DL/PKG[00]     = PHY[00]
        // DL/PKG[01]     = PHY[01]
        // DL/PKG[02]     = PHY[02]
        // DL/PKG[03]     = PHY[03]
        // DL/PKG[04]     = PHY[05] (+1)
        // DL/PKG[05]     = PHY[06] (+1)
        // DL/PKG[06]     = PHY[07] (+1)
        // DL/PKG[07]     = PHY[08] (+1)
        // DL/PKG[08](SP) = PHY[04] Swapped between Lanes 3/4
        if (i_lanes[l_index] == 8)
        {
            l_xlate_lane = 4;
        }
        else if (i_lanes[l_index] >= 4)
        {
            l_xlate_lane = i_lanes[l_index] + 1;
        }
        else
        {
            l_xlate_lane = i_lanes[l_index];
        }

        l_xlate_lane += l_lane_translate;

        // reset the length to 0 for each lane
        o_length_ui = 0;

        //initialize the local results
        for(int32_t l_phase = 0; l_phase <= 1; l_phase++)
        {
            l_status[l_phase] = TdrResult::None;
            l_length_ui[l_phase] = 0;
        }

        // loop through each of the 2 phases
        for(int32_t l_phase = 0; l_phase <= 1; l_phase++)
        {

            FAPI_DBG("Looping on Lane(%d) and Phase(%d)", l_xlate_lane, l_phase);
            FAPI_TRY(p10_io_tdr_initialize(l_iohs_target, l_xlate_lane, c_pulse_width, l_phase));

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
            FAPI_TRY(p10_io_tdr_sample_point(l_iohs_target, min_offset, l_xlate_lane, base_point_y1));
            FAPI_TRY(p10_io_tdr_sample_point(l_iohs_target, max_offset, l_xlate_lane, base_point_y2));

            // Add an extra point of precision
            FAPI_DBG("TDR base1(%d) base2(%d)", base_point_y1, base_point_y2);
            base_point_y1 = (base_point_y1 << 1) + 1;
            base_point_y2 = (base_point_y2 << 1) + 1;

            FAPI_DBG( "Base Point 1 (X,Y): %3d,%3d", min_offset, base_point_y1 );
            FAPI_DBG( "Base Point 2 (X,Y): %3d,%3d", max_offset, base_point_y2 );

            FAPI_TRY(p10_io_tdr_diagnose(base_point_y1, base_point_y2, l_status[l_phase]));

            switch( l_status[l_phase] )
            {
                case TdrResult::UnableToDetermine:
                    {
                        break;
                    }

                case TdrResult::Open:
                    {
                        FAPI_DBG("TDR Open found");
                        uint32_t x1_crossing = 0;
                        uint32_t x2_crossing = 0;
                        uint32_t max = ( base_point_y1 > base_point_y2 ) ? base_point_y1 : base_point_y2;
                        uint32_t min = ( base_point_y1 > base_point_y2 ) ? base_point_y2 : base_point_y1;
                        uint32_t l_y1 = min + (((max - min) + 2) / 4);
                        uint32_t l_y2 = min + ((((max - min) * 3) + 2) / 4);
                        FAPI_DBG("TDR Y1(%d) Y2(%d)", l_y1, l_y2);

                        FAPI_TRY( p10_io_tdr_find_horizontal_crossing(
                                      l_iohs_target,
                                      l_phase,
                                      l_y1 >> 1,
                                      l_xlate_lane,
                                      min_offset,
                                      max_offset,
                                      x1_crossing ) );
                        x1_crossing = (x1_crossing << 1) + 1;

                        FAPI_TRY( p10_io_tdr_find_horizontal_crossing(
                                      l_iohs_target,
                                      l_phase,
                                      l_y2 >> 1,
                                      l_xlate_lane,
                                      min_offset,
                                      max_offset,
                                      x2_crossing ) );
                        x2_crossing = (x2_crossing << 1) + 1;

                        if(l_tdr_dd2)       // if true, this is dd2
                        {
                            l_length_ui[l_phase] = (x1_crossing > x2_crossing)
                                                   ? ((x1_crossing - x2_crossing + 1) / 2)
                                                   : ((x2_crossing - x1_crossing + 1) / 2);
                        }
                        else
                        {
                            l_length_ui[l_phase] = (x1_crossing > x2_crossing)
                                                   ? ((x1_crossing - x2_crossing + 2) / 4)
                                                   : ((x2_crossing - x1_crossing + 2) / 4);
                        }

                        FAPI_DBG( "TDR Result:: Open Fault: %d / 2 UI from Driver x1(%d) x2(%d).", l_length_ui[l_phase], x1_crossing,
                                  x2_crossing );
                        // loopExit = true;    // if we find an open, no need to run the next phase
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
                            FAPI_TRY(p10_io_tdr_find_limit(l_iohs_target, min_offset, max_offset, l_xlate_lane, true, l_dacmax));
                            l_middac = (l_base + l_dacmax) / 2;
                        }
                        else if (l_status[l_phase] == TdrResult::ShortToVdd)
                        {
                            FAPI_TRY(p10_io_tdr_find_limit(l_iohs_target, min_offset, max_offset, l_xlate_lane, false, l_dacmin));
                            l_middac = (l_base + l_dacmin) / 2;
                        }
                        else
                        {
                            FAPI_TRY(p10_io_tdr_find_limit(l_iohs_target, min_offset, max_offset, l_xlate_lane, true, l_dacmax));
                            FAPI_TRY(p10_io_tdr_find_limit(l_iohs_target, min_offset, max_offset, l_xlate_lane, false, l_dacmin));
                            l_middac = (l_dacmax + l_dacmin) / 2;
                        }

                        if (abs(l_base - l_middac) < 2)
                        {
                            l_length_ui[l_phase] = 0;
                            break;
                        }

                        // search from min offset to the right
                        FAPI_TRY( p10_io_tdr_find_short_crossing(
                                      l_iohs_target,
                                      l_phase,
                                      l_middac,
                                      l_xlate_lane,
                                      min_offset,
                                      tdr_offset_width,
                                      true,
                                      x1_crossing ) );

                        FAPI_DBG("x1 crossing: %d", x1_crossing);

                        if (x1_crossing == -1)
                        {
                            l_length_ui[l_phase] = 0;
                            l_status[l_phase] |= TdrResult::UnableToDetermine;
                            break;
                        }

                        // search from max offset to the left
                        FAPI_TRY( p10_io_tdr_find_short_crossing(
                                      l_iohs_target,
                                      l_phase,
                                      l_middac,
                                      l_xlate_lane,
                                      max_offset,
                                      tdr_offset_width,
                                      false,
                                      x2_crossing ) );

                        FAPI_DBG("x1 crossing: %d", x1_crossing);

                        if (x2_crossing == -1)
                        {
                            l_length_ui[l_phase] = 0;
                            l_status[l_phase] |= TdrResult::UnableToDetermine;
                            break;
                        }

                        if(l_tdr_dd2)       // if true, this is dd2
                        {
                            l_length_ui[l_phase] = (x1_crossing > x2_crossing) ? ((x1_crossing - x2_crossing) / 2) : ((
                                                       x2_crossing - x1_crossing) / 2);
                        }
                        else
                        {
                            l_length_ui[l_phase] = (x1_crossing > x2_crossing) ? ((x1_crossing - x2_crossing) / 4) : ((
                                                       x2_crossing - x1_crossing) / 4);
                        }

                        FAPI_DBG( "TDR Result:: Short Fault: %d UI from Driver.", l_length_ui[l_phase] );
                        loopExit = true;    // if we find an short, no need to run the next phase
                        break;
                    }


                case TdrResult::Good:
                    {
                        FAPI_DBG("TDR Found a good net for Lane(%d) and Phase(%d)", l_xlate_lane, l_phase);
                    }
            }

            // we need to take the shortest length between the two legs, in case only 1 of the legs is Open
            // if (( o_status[l_index] == TdrResult::Open ) && (( o_length_ui < min_length_ui ) || ( min_length_ui == 0 )))
            // {
            //     min_length_ui = o_length_ui;
            // }

            if (loopExit)
            {
                break;
            }
        }


        FAPI_DBG("N-leg status: %d     P-leg status: %d", l_status[0], l_status[1]);
        FAPI_DBG("N-leg length: %d     P-leg length: %d", l_length_ui[0], l_length_ui[1]);

        // Set length and status based on both phases
        if ((l_status[0] == TdrResult::Good)  && (l_status[1] == TdrResult::Good))
        {
            o_status[l_index] = TdrResult::Good;
            o_length_ui = 0;
        }
        else if (l_status[0] == TdrResult::Open)
        {
            o_status[l_index] = TdrResult::Open;

            if (l_status[1] == TdrResult::Open)
            {
                // if Open, set o_length_ui to shorter of the open lengths
                // o_length_ui = (l_length_ui[0] > l_length_ui[1]) ? l_length_ui[1] : l_length_ui[0];
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
            o_status[l_index] = TdrResult::Open;
            o_length_ui = l_length_ui[1];
        }
        else if (l_status[0] & TdrResult::Short)
        {
            o_status[l_index] = l_status[0];
            o_length_ui = l_length_ui[0];
        }
        else if (l_status[1] & TdrResult::Short)
        {
            o_status[l_index] = l_status[1];
            o_length_ui = l_length_ui[1];
        }
        else
        {
            o_status[l_index] = TdrResult::UnableToDetermine;
            o_length_ui = 0;
        }


        if ((o_status[l_index] == TdrResult::Good) || (o_status[l_index] == TdrResult::UnableToDetermine))
        {
            o_length_ps[l_index] = 0;
        }
        else
        {
            // convert UI to fs
            o_length_ps[l_index] = (o_length_ui % 2) ?
                                   (((o_length_ui >> 1) * c_fs_per_ui) + (3 * c_fs_per_ui / 4)) :
                                   (((o_length_ui >> 1) * c_fs_per_ui) + (1 * c_fs_per_ui / 4));

            // Convert from fs to ps
            o_length_ps[l_index] = (o_length_ps[l_index] + 500) / 1000;
        }
    }

    // leave with TX psav force/fence controls asserted
    if ((l_iolink_num % 2) == 0)
    {
        FAPI_TRY(fapi2::getScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG, l_phy_psave_data));
        l_phy_psave_data.setBit<48, 9>();
        FAPI_TRY(fapi2::putScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG, l_phy_psave_data));

        FAPI_TRY(fapi2::getScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG, l_phy_psave_data));
        l_phy_psave_data.setBit<48, 9>();
        FAPI_TRY(fapi2::putScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG, l_phy_psave_data));
    }
    else
    {
        FAPI_TRY(fapi2::getScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG, l_phy_psave_data));
        l_phy_psave_data.setBit<57, 7>();
        FAPI_TRY(fapi2::putScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG, l_phy_psave_data));

        FAPI_TRY(fapi2::getScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG, l_phy_psave_data));
        l_phy_psave_data.setBit<48, 2>();
        FAPI_TRY(fapi2::putScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG, l_phy_psave_data));

        FAPI_TRY(fapi2::getScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG, l_phy_psave_data));
        l_phy_psave_data.setBit<57, 7>();
        FAPI_TRY(fapi2::putScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG, l_phy_psave_data));

        FAPI_TRY(fapi2::getScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG, l_phy_psave_data));
        l_phy_psave_data.setBit<48, 2>();
        FAPI_TRY(fapi2::putScom(l_iohs_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG, l_phy_psave_data));
    }

    FAPI_TRY(p10_iohs_phy_set_action_state(l_iohs_target, 0x0));
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
    const int32_t LOOP_MAX  = 255;
    const int32_t DAC_MAX  = 255;   // The upper limit of the dac
    const int32_t DAC_MIN  = 0;     // The lower limit of the dac
    const uint32_t DIRECTION_CHANGE_MAX = 5;
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

    while( loop_count < LOOP_MAX )
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

    if ((prev_dac < o_dac) && (o_dac != DAC_MIN) && (o_dac != DAC_MAX))
    {
        o_dac = prev_dac;
    }


fapi_try_exit:
    FAPI_DBG("End TDR Sample Point");
    return fapi2::current_err;
}

/// @brief Calculates max
/// @param[in] i_target             IOHS target
/// @param[in] i_offset             TDR offset to take the measurement
/// @param[out] o_dac               TDR DAC value at desired offset
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_tdr_find_limit(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
                                        uint32_t i_offset_start,
                                        uint32_t i_offset_end,
                                        uint32_t i_lane,
                                        bool i_max_not_min,
                                        int32_t& o_limit)
{

    using namespace scomt::iohs;
    fapi2::buffer<uint64_t> l_data = 0;
    const int32_t LOOP_MAX = 255;   // Loop Max
    const int32_t DAC_MAX  = 255;   // The upper limit of the dac
    const int32_t DAC_MIN  = 0;     // The lower limit of the dac
    uint32_t l_loop = 0;
    uint32_t l_capture = 0;
    int32_t l_prev_limit = 0;

    // set TDR dac value
    FAPI_DBG("Setting TDR Dac: %d", o_limit);
    FAPI_TRY(GET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG(i_target, l_data));
    SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(o_limit, l_data);
    FAPI_TRY(PUT_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG(i_target, l_data));

    FAPI_DBG("Start TDR Find Limit");

    for (uint32_t l_offset = i_offset_start; l_offset < i_offset_end; l_offset++)
    {
        FAPI_TRY(p10_io_tdr_set_pulse_offset(i_target, l_offset));

        while( l_loop < LOOP_MAX )
        {
            // set TDR dac value
            if (l_prev_limit != o_limit)
            {
                FAPI_DBG("Setting TDR Dac: %d", o_limit);
                FAPI_TRY(GET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG(i_target, l_data));
                SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(o_limit, l_data);
                FAPI_TRY(PUT_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG(i_target, l_data));
                l_prev_limit = o_limit;
            }

            // read the TDR capture value for the selected lane
            FAPI_TRY(p10_io_tdr_get_capt_val(i_target, i_lane, l_capture));

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
fapi2::ReturnCode p10_io_tdr_diagnose(const uint32_t i_bp1,
                                      const uint32_t i_bp2,
                                      uint32_t& o_result)
{

    const uint32_t MAX             = 255 << 1;
    const uint32_t OPEN_THRESHOLD  = (3 * MAX) / 5;
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
        o_result = TdrResult::Good;
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


    FAPI_DBG("o_result = 0x%04x", o_result);

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
        const uint32_t i_pulse_width,
        bool i_direction,
        int32_t& o_offset)
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
    const uint32_t TDR_NS_DELAY = 100000; // 100us
    const uint32_t TDR_SIM_CYCLES = 10;
    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_addr = 0x0;

    fapi2::delay(TDR_NS_DELAY, TDR_SIM_CYCLES);

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
