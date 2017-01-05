/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_mca_scom.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#include "p9_mca_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0b0100 = 0b0100;
constexpr uint64_t literal_0b11100 = 0b11100;
constexpr uint64_t literal_0b110 = 0b110;
constexpr uint64_t literal_0x1 = 0x1;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_17 = 17;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_13 = 13;
constexpr uint64_t literal_1867 = 1867;
constexpr uint64_t literal_22 = 22;
constexpr uint64_t literal_14 = 14;
constexpr uint64_t literal_15 = 15;
constexpr uint64_t literal_2134 = 2134;
constexpr uint64_t literal_26 = 26;
constexpr uint64_t literal_16 = 16;
constexpr uint64_t literal_2401 = 2401;
constexpr uint64_t literal_18 = 18;
constexpr uint64_t literal_2667 = 2667;
constexpr uint64_t literal_19 = 19;
constexpr uint64_t literal_28 = 28;
constexpr uint64_t literal_20 = 20;
constexpr uint64_t literal_3 = 3;
constexpr uint64_t literal_24 = 24;
constexpr uint64_t literal_30 = 30;
constexpr uint64_t literal_8 = 8;
constexpr uint64_t literal_9 = 9;
constexpr uint64_t literal_5 = 5;
constexpr uint64_t literal_6 = 6;
constexpr uint64_t literal_7 = 7;
constexpr uint64_t literal_10 = 10;
constexpr uint64_t literal_11 = 11;
constexpr uint64_t literal_12 = 12;
constexpr uint64_t literal_267 = 267;
constexpr uint64_t literal_1866 = 1866;
constexpr uint64_t literal_0b011000 = 0b011000;
constexpr uint64_t literal_0b000 = 0b000;
constexpr uint64_t literal_0b100 = 0b100;
constexpr uint64_t literal_0b010 = 0b010;
constexpr uint64_t literal_0x0 = 0x0;
constexpr uint64_t literal_0b001 = 0b001;
constexpr uint64_t literal_0b101 = 0b101;
constexpr uint64_t literal_0b011 = 0b011;
constexpr uint64_t literal_0b111 = 0b111;
constexpr uint64_t literal_597 = 597;
constexpr uint64_t literal_768 = 768;
constexpr uint64_t literal_939 = 939;

fapi2::ReturnCode p9_mca_scom(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_MCS>& TGT2,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT3)
{
    {
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T0_Type l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T0, TGT3, l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T0));
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T1_Type l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T1, TGT3, l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T1));
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T2_Type l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T2, TGT3, l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T2));
        fapi2::ATTR_IS_SIMULATION_Type l_TGT3_ATTR_IS_SIMULATION;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, TGT3, l_TGT3_ATTR_IS_SIMULATION));
        uint64_t l_def_IS_SIM = (l_TGT3_ATTR_IS_SIMULATION == literal_1);
        uint64_t l_def_IS_HW = (l_TGT3_ATTR_IS_SIMULATION == literal_0);
        fapi2::ATTR_EFF_DIMM_TYPE_Type l_TGT2_ATTR_EFF_DIMM_TYPE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_DIMM_TYPE, TGT2, l_TGT2_ATTR_EFF_DIMM_TYPE));
        fapi2::ATTR_CHIP_UNIT_POS_Type l_TGT0_ATTR_CHIP_UNIT_POS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, TGT0, l_TGT0_ATTR_CHIP_UNIT_POS));
        uint64_t l_def_POSITION = l_TGT0_ATTR_CHIP_UNIT_POS;
        uint64_t l_def_PORT_INDEX = (l_def_POSITION % literal_2);
        fapi2::ATTR_EFF_DRAM_CL_Type l_TGT2_ATTR_EFF_DRAM_CL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_CL, TGT2, l_TGT2_ATTR_EFF_DRAM_CL));
        fapi2::ATTR_MSS_FREQ_Type l_TGT1_ATTR_MSS_FREQ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_FREQ, TGT1, l_TGT1_ATTR_MSS_FREQ));
        uint64_t l_def_MSS_FREQ_EQ_1866 = (l_TGT1_ATTR_MSS_FREQ < literal_1867);
        uint64_t l_def_MEM_TYPE_1866_13 = (l_def_MSS_FREQ_EQ_1866 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_13));
        uint64_t l_def_MEM_TYPE_1866_14 = (l_def_MSS_FREQ_EQ_1866 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_14));
        uint64_t l_def_MSS_FREQ_EQ_2133 = ((l_TGT1_ATTR_MSS_FREQ >= literal_1867) && (l_TGT1_ATTR_MSS_FREQ < literal_2134));
        uint64_t l_def_MEM_TYPE_2133_15 = (l_def_MSS_FREQ_EQ_2133 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_15));
        uint64_t l_def_MEM_TYPE_2133_16 = (l_def_MSS_FREQ_EQ_2133 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_16));
        uint64_t l_def_MSS_FREQ_EQ_2400 = ((l_TGT1_ATTR_MSS_FREQ >= literal_2134) && (l_TGT1_ATTR_MSS_FREQ < literal_2401));
        uint64_t l_def_MEM_TYPE_2400_16 = (l_def_MSS_FREQ_EQ_2400 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_16));
        uint64_t l_def_MEM_TYPE_2400_17 = (l_def_MSS_FREQ_EQ_2400 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_17));
        uint64_t l_def_MEM_TYPE_2400_18 = (l_def_MSS_FREQ_EQ_2400 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_18));
        uint64_t l_def_MSS_FREQ_EQ_2667 = (l_TGT1_ATTR_MSS_FREQ >= literal_2667);
        uint64_t l_def_MEM_TYPE_2667_18 = (l_def_MSS_FREQ_EQ_2667 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_18));
        uint64_t l_def_MEM_TYPE_2667_19 = (l_def_MSS_FREQ_EQ_2667 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_19));
        uint64_t l_def_MEM_TYPE_2667_20 = (l_def_MSS_FREQ_EQ_2667 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_20));
        fapi2::ATTR_MSS_VPD_MR_DPHY_WLO_Type l_TGT2_ATTR_MSS_VPD_MR_DPHY_WLO;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_VPD_MR_DPHY_WLO, TGT2, l_TGT2_ATTR_MSS_VPD_MR_DPHY_WLO));
        fapi2::ATTR_EFF_DRAM_CWL_Type l_TGT2_ATTR_EFF_DRAM_CWL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_CWL, TGT2, l_TGT2_ATTR_EFF_DRAM_CWL));
        uint64_t l_def_RANK_SWITCH_TCK = (literal_4 + ((l_TGT1_ATTR_MSS_FREQ - literal_1866) / literal_267));
        fapi2::ATTR_EFF_DRAM_TCCD_L_Type l_TGT2_ATTR_EFF_DRAM_TCCD_L;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TCCD_L, TGT2, l_TGT2_ATTR_EFF_DRAM_TCCD_L));
        uint64_t l_def_BUS_TURNAROUND_TCK = (literal_4 + ((l_TGT1_ATTR_MSS_FREQ - literal_1866) / literal_267));
        fapi2::ATTR_EFF_DRAM_TWTR_S_Type l_TGT2_ATTR_EFF_DRAM_TWTR_S;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TWTR_S, TGT2, l_TGT2_ATTR_EFF_DRAM_TWTR_S));
        fapi2::ATTR_EFF_DRAM_TWTR_L_Type l_TGT2_ATTR_EFF_DRAM_TWTR_L;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TWTR_L, TGT2, l_TGT2_ATTR_EFF_DRAM_TWTR_L));
        fapi2::ATTR_EFF_DRAM_TFAW_Type l_TGT2_ATTR_EFF_DRAM_TFAW;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TFAW, TGT2, l_TGT2_ATTR_EFF_DRAM_TFAW));
        fapi2::ATTR_EFF_DRAM_TRCD_Type l_TGT2_ATTR_EFF_DRAM_TRCD;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TRCD, TGT2, l_TGT2_ATTR_EFF_DRAM_TRCD));
        fapi2::ATTR_EFF_DRAM_TRP_Type l_TGT2_ATTR_EFF_DRAM_TRP;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TRP, TGT2, l_TGT2_ATTR_EFF_DRAM_TRP));
        fapi2::ATTR_EFF_DRAM_TRAS_Type l_TGT2_ATTR_EFF_DRAM_TRAS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TRAS, TGT2, l_TGT2_ATTR_EFF_DRAM_TRAS));
        fapi2::ATTR_EFF_DRAM_TWR_Type l_TGT2_ATTR_EFF_DRAM_TWR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TWR, TGT2, l_TGT2_ATTR_EFF_DRAM_TWR));
        fapi2::ATTR_EFF_DRAM_TRTP_Type l_TGT2_ATTR_EFF_DRAM_TRTP;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TRTP, TGT2, l_TGT2_ATTR_EFF_DRAM_TRTP));
        fapi2::ATTR_EFF_DRAM_TRRD_S_Type l_TGT2_ATTR_EFF_DRAM_TRRD_S;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TRRD_S, TGT2, l_TGT2_ATTR_EFF_DRAM_TRRD_S));
        fapi2::ATTR_EFF_DRAM_TRRD_L_Type l_TGT2_ATTR_EFF_DRAM_TRRD_L;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TRRD_L, TGT2, l_TGT2_ATTR_EFF_DRAM_TRRD_L));
        fapi2::ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_Type l_TGT2_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, TGT2, l_TGT2_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM));
        uint64_t l_def_SLOT0_DENOMINATOR = ((l_TGT2_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM[l_def_PORT_INDEX][literal_0] ==
                                             literal_0x0) | l_TGT2_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM[l_def_PORT_INDEX][literal_0]);
        fapi2::ATTR_EFF_NUM_RANKS_PER_DIMM_Type l_TGT2_ATTR_EFF_NUM_RANKS_PER_DIMM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_NUM_RANKS_PER_DIMM, TGT2, l_TGT2_ATTR_EFF_NUM_RANKS_PER_DIMM));
        uint64_t l_def_SLOT0_DRAM_STACK_HEIGHT = (l_TGT2_ATTR_EFF_NUM_RANKS_PER_DIMM[l_def_PORT_INDEX][literal_0] /
                l_def_SLOT0_DENOMINATOR);
        uint64_t l_def_SLOT1_DENOMINATOR = ((l_TGT2_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM[l_def_PORT_INDEX][literal_1] ==
                                             literal_0x0) | l_TGT2_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM[l_def_PORT_INDEX][literal_1]);
        uint64_t l_def_SLOT1_DRAM_STACK_HEIGHT = (l_TGT2_ATTR_EFF_NUM_RANKS_PER_DIMM[l_def_PORT_INDEX][literal_1] /
                l_def_SLOT1_DENOMINATOR);
        fapi2::ATTR_MSS_VPD_MT_ODT_RD_Type l_TGT2_ATTR_MSS_VPD_MT_ODT_RD;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_VPD_MT_ODT_RD, TGT2, l_TGT2_ATTR_MSS_VPD_MT_ODT_RD));
        fapi2::ATTR_MSS_VPD_MT_ODT_WR_Type l_TGT2_ATTR_MSS_VPD_MT_ODT_WR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_VPD_MT_ODT_WR, TGT2, l_TGT2_ATTR_MSS_VPD_MT_ODT_WR));
        uint64_t l_def_NUM_RANKS = (l_TGT2_ATTR_EFF_NUM_RANKS_PER_DIMM[l_def_PORT_INDEX][literal_0] +
                                    l_TGT2_ATTR_EFF_NUM_RANKS_PER_DIMM[l_def_PORT_INDEX][literal_1]);
        fapi2::ATTR_EFF_DRAM_TREFI_Type l_TGT2_ATTR_EFF_DRAM_TREFI;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TREFI, TGT2, l_TGT2_ATTR_EFF_DRAM_TREFI));
        uint64_t l_def_REFRESH_INTERVAL = (l_TGT2_ATTR_EFF_DRAM_TREFI[l_def_PORT_INDEX] / (literal_8 * l_def_NUM_RANKS));
        fapi2::ATTR_EFF_DRAM_TRFC_Type l_TGT2_ATTR_EFF_DRAM_TRFC;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TRFC, TGT2, l_TGT2_ATTR_EFF_DRAM_TRFC));
        fapi2::ATTR_EFF_DRAM_TRFC_DLR_Type l_TGT2_ATTR_EFF_DRAM_TRFC_DLR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TRFC_DLR, TGT2, l_TGT2_ATTR_EFF_DRAM_TRFC_DLR));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010824ull, l_scom_buffer ));

            l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0b0100 );
            l_scom_buffer.insert<50, 5, 59, uint64_t>(literal_0b11100 );
            l_scom_buffer.insert<37, 3, 61, uint64_t>(literal_0b110 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5010824ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010826ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<8, 8, 56, uint64_t>((l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T0 / literal_4) );
            l_scom_buffer.insert<16, 8, 56, uint64_t>((l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T1 / literal_4) );
            l_scom_buffer.insert<32, 8, 56, uint64_t>((l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T2 / literal_4) );
            l_scom_buffer.insert<24, 8, 56, uint64_t>((l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T1 / literal_4) );
            l_scom_buffer.insert<40, 8, 56, uint64_t>((l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T2 / literal_4) );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5010826ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x701090aull, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_17 );
            }
            else if ((((l_def_MEM_TYPE_1866_13 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_22 );
            }
            else if ((((l_def_MEM_TYPE_1866_14 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_22 );
            }
            else if ((((l_def_MEM_TYPE_2133_15 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_26 );
            }
            else if ((((l_def_MEM_TYPE_2133_16 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_26 );
            }
            else if ((((l_def_MEM_TYPE_2400_16 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_26 );
            }
            else if ((((l_def_MEM_TYPE_2400_17 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_26 );
            }
            else if ((((l_def_MEM_TYPE_2400_18 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_26 );
            }
            else if ((((l_def_MEM_TYPE_2667_18 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_26 );
            }
            else if ((((l_def_MEM_TYPE_2667_19 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_28 );
            }
            else if ((((l_def_MEM_TYPE_2667_20 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_28 );
            }
            else if ((((l_def_MEM_TYPE_1866_13 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_24 );
            }
            else if ((((l_def_MEM_TYPE_1866_14 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_24 );
            }
            else if ((((l_def_MEM_TYPE_2133_15 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_28 );
            }
            else if ((((l_def_MEM_TYPE_2133_16 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_28 );
            }
            else if ((((l_def_MEM_TYPE_2400_16 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_28 );
            }
            else if ((((l_def_MEM_TYPE_2400_17 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_28 );
            }
            else if ((((l_def_MEM_TYPE_2400_18 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_28 );
            }
            else if ((((l_def_MEM_TYPE_2667_18 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_26 );
            }
            else if ((((l_def_MEM_TYPE_2667_19 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_30 );
            }
            else if ((((l_def_MEM_TYPE_2667_20 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_30 );
            }

            if ((l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(((l_TGT2_ATTR_EFF_DRAM_CWL[l_def_PORT_INDEX] +
                        l_TGT2_ATTR_MSS_VPD_MR_DPHY_WLO[l_def_PORT_INDEX]) - literal_8) );
            }
            else if ((l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] != literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(((l_TGT2_ATTR_EFF_DRAM_CWL[l_def_PORT_INDEX] +
                        l_TGT2_ATTR_MSS_VPD_MR_DPHY_WLO[l_def_PORT_INDEX]) - literal_9) );
            }

            l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_24 );

            if ((l_def_MEM_TYPE_1866_13 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_4 );
            }
            else if ((l_def_MEM_TYPE_1866_14 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_5 );
            }
            else if ((l_def_MEM_TYPE_2133_15 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_6 );
            }
            else if ((l_def_MEM_TYPE_2133_16 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_7 );
            }
            else if ((l_def_MEM_TYPE_2400_16 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_7 );
            }
            else if ((l_def_MEM_TYPE_2400_17 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_8 );
            }
            else if ((l_def_MEM_TYPE_2400_18 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_9 );
            }
            else if ((l_def_MEM_TYPE_2667_18 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_9 );
            }
            else if ((l_def_MEM_TYPE_2667_19 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_10 );
            }
            else if ((l_def_MEM_TYPE_2667_20 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_11 );
            }

            if ((l_def_MEM_TYPE_1866_13 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_9 );
            }
            else if ((l_def_MEM_TYPE_1866_14 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_10 );
            }
            else if ((l_def_MEM_TYPE_2133_15 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_11 );
            }
            else if ((l_def_MEM_TYPE_2133_16 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_12 );
            }
            else if ((l_def_MEM_TYPE_2400_16 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_12 );
            }
            else if ((l_def_MEM_TYPE_2400_17 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_13 );
            }
            else if ((l_def_MEM_TYPE_2400_18 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_14 );
            }
            else if ((l_def_MEM_TYPE_2667_18 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_14 );
            }
            else if ((l_def_MEM_TYPE_2667_19 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_15 );
            }
            else if ((l_def_MEM_TYPE_2667_20 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_16 );
            }

            l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_1 );
            l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_6 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x701090aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x701090bull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>((literal_4 + l_def_RANK_SWITCH_TCK) );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_4 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_4 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(l_TGT2_ATTR_EFF_DRAM_TCCD_L[l_def_PORT_INDEX] );
            l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_4 + l_def_RANK_SWITCH_TCK) );
            l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_4 );
            l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_4 );
            l_scom_buffer.insert<28, 4, 60, uint64_t>(l_TGT2_ATTR_EFF_DRAM_TCCD_L[l_def_PORT_INDEX] );
            l_scom_buffer.insert<32, 5, 59, uint64_t>((((l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] + literal_4) +
                    l_def_BUS_TURNAROUND_TCK) - l_TGT2_ATTR_EFF_DRAM_CWL[l_def_PORT_INDEX]) );
            l_scom_buffer.insert<37, 5, 59, uint64_t>((((l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] + literal_4) +
                    l_def_BUS_TURNAROUND_TCK) - l_TGT2_ATTR_EFF_DRAM_CWL[l_def_PORT_INDEX]) );
            l_scom_buffer.insert<42, 5, 59, uint64_t>((((l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] + literal_4) +
                    l_def_BUS_TURNAROUND_TCK) - l_TGT2_ATTR_EFF_DRAM_CWL[l_def_PORT_INDEX]) );
            l_scom_buffer.insert<47, 4, 60, uint64_t>((((l_TGT2_ATTR_EFF_DRAM_CWL[l_def_PORT_INDEX] + literal_4) +
                    l_def_BUS_TURNAROUND_TCK) - l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX]) );
            l_scom_buffer.insert<51, 6, 58, uint64_t>(((l_TGT2_ATTR_EFF_DRAM_CWL[l_def_PORT_INDEX] + literal_4) +
                    l_TGT2_ATTR_EFF_DRAM_TWTR_S[l_def_PORT_INDEX]) );
            l_scom_buffer.insert<57, 6, 58, uint64_t>(((l_TGT2_ATTR_EFF_DRAM_CWL[l_def_PORT_INDEX] + literal_4) +
                    l_TGT2_ATTR_EFF_DRAM_TWTR_S[l_def_PORT_INDEX]) );
            FAPI_TRY(fapi2::putScom(TGT0, 0x701090bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x701090cull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(l_TGT2_ATTR_EFF_DRAM_TCCD_L[l_def_PORT_INDEX] );
            l_scom_buffer.insert<4, 6, 58, uint64_t>(((l_TGT2_ATTR_EFF_DRAM_CWL[l_def_PORT_INDEX] + literal_4) +
                    l_TGT2_ATTR_EFF_DRAM_TWTR_L[l_def_PORT_INDEX]) );
            l_scom_buffer.insert<10, 6, 58, uint64_t>(l_TGT2_ATTR_EFF_DRAM_TFAW[l_def_PORT_INDEX] );
            l_scom_buffer.insert<16, 5, 59, uint64_t>(l_TGT2_ATTR_EFF_DRAM_TRCD[l_def_PORT_INDEX] );
            l_scom_buffer.insert<21, 5, 59, uint64_t>(l_TGT2_ATTR_EFF_DRAM_TRP[l_def_PORT_INDEX] );
            l_scom_buffer.insert<26, 6, 58, uint64_t>(l_TGT2_ATTR_EFF_DRAM_TRAS[l_def_PORT_INDEX] );
            l_scom_buffer.insert<41, 7, 57, uint64_t>(((l_TGT2_ATTR_EFF_DRAM_CWL[l_def_PORT_INDEX] + literal_4) +
                    l_TGT2_ATTR_EFF_DRAM_TWR[l_def_PORT_INDEX]) );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(l_TGT2_ATTR_EFF_DRAM_TRTP[l_def_PORT_INDEX] );
            l_scom_buffer.insert<52, 4, 60, uint64_t>(l_TGT2_ATTR_EFF_DRAM_TRRD_S[l_def_PORT_INDEX] );
            l_scom_buffer.insert<56, 4, 60, uint64_t>(l_TGT2_ATTR_EFF_DRAM_TRRD_L[l_def_PORT_INDEX] );

            if ((l_def_MSS_FREQ_EQ_1866 == literal_1))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_8 );
            }
            else if ((l_def_MSS_FREQ_EQ_2133 == literal_1))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_9 );
            }
            else if ((l_def_MSS_FREQ_EQ_2400 == literal_1))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_10 );
            }
            else if ((l_def_MSS_FREQ_EQ_2667 == literal_1))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x701090cull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x701090eull, l_scom_buffer ));

            l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b011000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x701090eull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7010913ull, l_scom_buffer ));

            constexpr auto l_MCP_PORT0_SRQ_MBA_FARB0Q_CFG_PARITY_AFTER_CMD_ON = 0x1;
            l_scom_buffer.insert<38, 1, 63, uint64_t>(l_MCP_PORT0_SRQ_MBA_FARB0Q_CFG_PARITY_AFTER_CMD_ON );
            constexpr auto l_MCP_PORT0_SRQ_MBA_FARB0Q_CFG_OE_ALWAYS_ON_ON = 0x1;
            l_scom_buffer.insert<55, 1, 63, uint64_t>(l_MCP_PORT0_SRQ_MBA_FARB0Q_CFG_OE_ALWAYS_ON_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x7010913ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7010914ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<3, 3, 61, uint64_t>(literal_0b100 );
            l_scom_buffer.insert<6, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<9, 3, 61, uint64_t>(literal_0b110 );

            if ((l_def_SLOT0_DRAM_STACK_HEIGHT == literal_8))
            {
                l_scom_buffer.insert<12, 3, 61, uint64_t>(literal_0b001 );
            }
            else if ((l_def_SLOT0_DRAM_STACK_HEIGHT != literal_8))
            {
                l_scom_buffer.insert<12, 3, 61, uint64_t>(literal_0b000 );
            }

            if ((l_def_SLOT0_DRAM_STACK_HEIGHT == literal_8))
            {
                l_scom_buffer.insert<15, 3, 61, uint64_t>(literal_0b101 );
            }
            else if ((l_def_SLOT0_DRAM_STACK_HEIGHT != literal_8))
            {
                l_scom_buffer.insert<15, 3, 61, uint64_t>(literal_0b100 );
            }

            if ((l_def_SLOT0_DRAM_STACK_HEIGHT == literal_8))
            {
                l_scom_buffer.insert<18, 3, 61, uint64_t>(literal_0b011 );
            }
            else if ((l_def_SLOT0_DRAM_STACK_HEIGHT != literal_8))
            {
                l_scom_buffer.insert<18, 3, 61, uint64_t>(literal_0b010 );
            }

            if ((l_def_SLOT0_DRAM_STACK_HEIGHT == literal_8))
            {
                l_scom_buffer.insert<21, 3, 61, uint64_t>(literal_0b111 );
            }
            else if ((l_def_SLOT0_DRAM_STACK_HEIGHT != literal_8))
            {
                l_scom_buffer.insert<21, 3, 61, uint64_t>(literal_0b110 );
            }

            l_scom_buffer.insert<24, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<27, 3, 61, uint64_t>(literal_0b100 );
            l_scom_buffer.insert<30, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<33, 3, 61, uint64_t>(literal_0b110 );

            if ((l_def_SLOT1_DRAM_STACK_HEIGHT == literal_8))
            {
                l_scom_buffer.insert<36, 3, 61, uint64_t>(literal_0b001 );
            }
            else if ((l_def_SLOT1_DRAM_STACK_HEIGHT != literal_8))
            {
                l_scom_buffer.insert<36, 3, 61, uint64_t>(literal_0b000 );
            }

            if ((l_def_SLOT1_DRAM_STACK_HEIGHT == literal_8))
            {
                l_scom_buffer.insert<39, 3, 61, uint64_t>(literal_0b101 );
            }
            else if ((l_def_SLOT1_DRAM_STACK_HEIGHT != literal_8))
            {
                l_scom_buffer.insert<39, 3, 61, uint64_t>(literal_0b100 );
            }

            if ((l_def_SLOT1_DRAM_STACK_HEIGHT == literal_8))
            {
                l_scom_buffer.insert<42, 3, 61, uint64_t>(literal_0b011 );
            }
            else if ((l_def_SLOT1_DRAM_STACK_HEIGHT != literal_8))
            {
                l_scom_buffer.insert<42, 3, 61, uint64_t>(literal_0b010 );
            }

            if ((l_def_SLOT1_DRAM_STACK_HEIGHT == literal_8))
            {
                l_scom_buffer.insert<45, 3, 61, uint64_t>(literal_0b111 );
            }
            else if ((l_def_SLOT1_DRAM_STACK_HEIGHT != literal_8))
            {
                l_scom_buffer.insert<45, 3, 61, uint64_t>(literal_0b110 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x7010914ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7010915ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_0] >>
                    literal_7) );
            l_scom_buffer.insert<1, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_0] >>
                    literal_6) );
            l_scom_buffer.insert<2, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_0] >>
                    literal_3) );
            l_scom_buffer.insert<3, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_0] >>
                    literal_2) );
            l_scom_buffer.insert<4, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_1] >>
                    literal_7) );
            l_scom_buffer.insert<5, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_1] >>
                    literal_6) );
            l_scom_buffer.insert<6, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_1] >>
                    literal_3) );
            l_scom_buffer.insert<7, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_1] >>
                    literal_2) );
            l_scom_buffer.insert<8, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_2] >>
                    literal_7) );
            l_scom_buffer.insert<9, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_2] >>
                    literal_6) );
            l_scom_buffer.insert<10, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_2] >>
                    literal_3) );
            l_scom_buffer.insert<11, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_2] >>
                    literal_2) );
            l_scom_buffer.insert<12, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_3] >>
                    literal_7) );
            l_scom_buffer.insert<13, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_3] >>
                    literal_6) );
            l_scom_buffer.insert<14, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_3] >>
                    literal_3) );
            l_scom_buffer.insert<15, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_3] >>
                    literal_2) );
            l_scom_buffer.insert<16, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_0] >>
                    literal_7) );
            l_scom_buffer.insert<17, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_0] >>
                    literal_6) );
            l_scom_buffer.insert<18, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_0] >>
                    literal_3) );
            l_scom_buffer.insert<19, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_0] >>
                    literal_2) );
            l_scom_buffer.insert<20, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_1] >>
                    literal_7) );
            l_scom_buffer.insert<21, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_1] >>
                    literal_6) );
            l_scom_buffer.insert<22, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_1] >>
                    literal_3) );
            l_scom_buffer.insert<23, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_1] >>
                    literal_2) );
            l_scom_buffer.insert<24, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_2] >>
                    literal_7) );
            l_scom_buffer.insert<25, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_2] >>
                    literal_6) );
            l_scom_buffer.insert<26, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_2] >>
                    literal_3) );
            l_scom_buffer.insert<27, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_2] >>
                    literal_2) );
            l_scom_buffer.insert<28, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_3] >>
                    literal_7) );
            l_scom_buffer.insert<29, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_3] >>
                    literal_6) );
            l_scom_buffer.insert<30, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_3] >>
                    literal_3) );
            l_scom_buffer.insert<31, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_3] >>
                    literal_2) );
            l_scom_buffer.insert<32, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_0] >>
                    literal_7) );
            l_scom_buffer.insert<33, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_0] >>
                    literal_6) );
            l_scom_buffer.insert<34, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_0] >>
                    literal_3) );
            l_scom_buffer.insert<35, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_0] >>
                    literal_2) );
            l_scom_buffer.insert<36, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_1] >>
                    literal_7) );
            l_scom_buffer.insert<37, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_1] >>
                    literal_6) );
            l_scom_buffer.insert<38, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_1] >>
                    literal_3) );
            l_scom_buffer.insert<39, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_1] >>
                    literal_2) );
            l_scom_buffer.insert<40, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_2] >>
                    literal_7) );
            l_scom_buffer.insert<41, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_2] >>
                    literal_6) );
            l_scom_buffer.insert<42, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_2] >>
                    literal_3) );
            l_scom_buffer.insert<43, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_2] >>
                    literal_2) );
            l_scom_buffer.insert<44, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_3] >>
                    literal_7) );
            l_scom_buffer.insert<45, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_3] >>
                    literal_6) );
            l_scom_buffer.insert<46, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_3] >>
                    literal_3) );
            l_scom_buffer.insert<47, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_3] >>
                    literal_2) );
            l_scom_buffer.insert<48, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_0] >>
                    literal_7) );
            l_scom_buffer.insert<49, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_0] >>
                    literal_6) );
            l_scom_buffer.insert<50, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_0] >>
                    literal_3) );
            l_scom_buffer.insert<51, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_0] >>
                    literal_2) );
            l_scom_buffer.insert<52, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_1] >>
                    literal_7) );
            l_scom_buffer.insert<53, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_1] >>
                    literal_6) );
            l_scom_buffer.insert<54, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_1] >>
                    literal_3) );
            l_scom_buffer.insert<55, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_1] >>
                    literal_2) );
            l_scom_buffer.insert<56, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_2] >>
                    literal_7) );
            l_scom_buffer.insert<57, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_2] >>
                    literal_6) );
            l_scom_buffer.insert<58, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_2] >>
                    literal_3) );
            l_scom_buffer.insert<59, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_2] >>
                    literal_2) );
            l_scom_buffer.insert<60, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_3] >>
                    literal_7) );
            l_scom_buffer.insert<61, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_3] >>
                    literal_6) );
            l_scom_buffer.insert<62, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_3] >>
                    literal_3) );
            l_scom_buffer.insert<63, 1, 63, uint64_t>((l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_3] >>
                    literal_2) );
            FAPI_TRY(fapi2::putScom(TGT0, 0x7010915ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7010932ull, l_scom_buffer ));

            l_scom_buffer.insert<8, 11, 53, uint64_t>(l_def_REFRESH_INTERVAL );
            l_scom_buffer.insert<30, 10, 54, uint64_t>(l_TGT2_ATTR_EFF_DRAM_TRFC[l_def_PORT_INDEX] );
            l_scom_buffer.insert<40, 10, 54, uint64_t>(l_TGT2_ATTR_EFF_DRAM_TRFC_DLR[l_def_PORT_INDEX] );
            FAPI_TRY(fapi2::putScom(TGT0, 0x7010932ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7010934ull, l_scom_buffer ));

            if ((l_def_MSS_FREQ_EQ_1866 == literal_1))
            {
                l_scom_buffer.insert<16, 5, 59, uint64_t>(literal_5 );
            }
            else if ((l_def_MSS_FREQ_EQ_2133 == literal_1))
            {
                l_scom_buffer.insert<16, 5, 59, uint64_t>(literal_6 );
            }
            else if ((l_def_MSS_FREQ_EQ_2400 == literal_1))
            {
                l_scom_buffer.insert<16, 5, 59, uint64_t>(literal_6 );
            }
            else if ((l_def_MSS_FREQ_EQ_2667 == literal_1))
            {
                l_scom_buffer.insert<16, 5, 59, uint64_t>(literal_7 );
            }

            if ((l_def_MSS_FREQ_EQ_1866 == literal_1))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_5 );
            }
            else if ((l_def_MSS_FREQ_EQ_2133 == literal_1))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_6 );
            }
            else if ((l_def_MSS_FREQ_EQ_2400 == literal_1))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_6 );
            }
            else if ((l_def_MSS_FREQ_EQ_2667 == literal_1))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_7 );
            }

            if ((l_def_MSS_FREQ_EQ_1866 == literal_1))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>(literal_6 );
            }
            else if ((l_def_MSS_FREQ_EQ_2133 == literal_1))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>(literal_7 );
            }
            else if ((l_def_MSS_FREQ_EQ_2400 == literal_1))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>(literal_8 );
            }
            else if ((l_def_MSS_FREQ_EQ_2667 == literal_1))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>(literal_9 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x7010934ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7010935ull, l_scom_buffer ));

            if ((l_def_MSS_FREQ_EQ_1866 == literal_1))
            {
                l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_10 );
            }
            else if ((l_def_MSS_FREQ_EQ_2133 == literal_1))
            {
                l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_11 );
            }
            else if ((l_def_MSS_FREQ_EQ_2400 == literal_1))
            {
                l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_12 );
            }
            else if ((l_def_MSS_FREQ_EQ_2667 == literal_1))
            {
                l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_14 );
            }

            if ((l_def_MSS_FREQ_EQ_1866 == literal_1))
            {
                l_scom_buffer.insert<22, 5, 59, uint64_t>(literal_10 );
            }
            else if ((l_def_MSS_FREQ_EQ_2133 == literal_1))
            {
                l_scom_buffer.insert<22, 5, 59, uint64_t>(literal_11 );
            }
            else if ((l_def_MSS_FREQ_EQ_2400 == literal_1))
            {
                l_scom_buffer.insert<22, 5, 59, uint64_t>(literal_12 );
            }
            else if ((l_def_MSS_FREQ_EQ_2667 == literal_1))
            {
                l_scom_buffer.insert<22, 5, 59, uint64_t>(literal_14 );
            }

            l_scom_buffer.insert<12, 5, 59, uint64_t>(literal_5 );

            if ((l_def_MSS_FREQ_EQ_1866 == literal_1))
            {
                l_scom_buffer.insert<27, 11, 53, uint64_t>(literal_597 );
            }
            else if ((l_def_MSS_FREQ_EQ_2133 == literal_1))
            {
                l_scom_buffer.insert<27, 11, 53, uint64_t>(literal_768 );
            }
            else if ((l_def_MSS_FREQ_EQ_2400 == literal_1))
            {
                l_scom_buffer.insert<27, 11, 53, uint64_t>(literal_768 );
            }
            else if ((l_def_MSS_FREQ_EQ_2667 == literal_1))
            {
                l_scom_buffer.insert<27, 11, 53, uint64_t>(literal_939 );
            }

            l_scom_buffer.insert<46, 11, 53, uint64_t>(l_def_REFRESH_INTERVAL );
            FAPI_TRY(fapi2::putScom(TGT0, 0x7010935ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
