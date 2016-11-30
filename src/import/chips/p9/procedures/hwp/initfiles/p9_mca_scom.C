/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_mca_scom.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

constexpr auto literal_0b0100 = 0b0100;
constexpr auto literal_0b11100 = 0b11100;
constexpr auto literal_0b110 = 0b110;
constexpr auto literal_0x1 = 0x1;
constexpr auto literal_4 = 4;
constexpr auto literal_1 = 1;
constexpr auto literal_17 = 17;
constexpr auto literal_0 = 0;
constexpr auto literal_2 = 2;
constexpr auto literal_13 = 13;
constexpr auto literal_1867 = 1867;
constexpr auto literal_19 = 19;
constexpr auto literal_14 = 14;
constexpr auto literal_20 = 20;
constexpr auto literal_15 = 15;
constexpr auto literal_2134 = 2134;
constexpr auto literal_21 = 21;
constexpr auto literal_16 = 16;
constexpr auto literal_22 = 22;
constexpr auto literal_2401 = 2401;
constexpr auto literal_23 = 23;
constexpr auto literal_18 = 18;
constexpr auto literal_24 = 24;
constexpr auto literal_2667 = 2667;
constexpr auto literal_25 = 25;
constexpr auto literal_26 = 26;
constexpr auto literal_3 = 3;
constexpr auto literal_27 = 27;
constexpr auto literal_28 = 28;
constexpr auto literal_5 = 5;
constexpr auto literal_6 = 6;
constexpr auto literal_7 = 7;
constexpr auto literal_8 = 8;
constexpr auto literal_9 = 9;
constexpr auto literal_10 = 10;
constexpr auto literal_11 = 11;
constexpr auto literal_12 = 12;
constexpr auto literal_267 = 267;
constexpr auto literal_1866 = 1866;
constexpr auto literal_0b011000 = 0b011000;
constexpr auto literal_0b000 = 0b000;
constexpr auto literal_0b100 = 0b100;
constexpr auto literal_0b010 = 0b010;
constexpr auto literal_0x0 = 0x0;
constexpr auto literal_0b001 = 0b001;
constexpr auto literal_0b101 = 0b101;
constexpr auto literal_0b011 = 0b011;
constexpr auto literal_0b111 = 0b111;
constexpr auto literal_597 = 597;
constexpr auto literal_768 = 768;
constexpr auto literal_939 = 939;

fapi2::ReturnCode p9_mca_scom(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_MCS>& TGT2,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT3)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T0_Type l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T0;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T0, TGT3, l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T0);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_EPS_READ_CYCLES_T0)");
            break;
        }

        fapi2::ATTR_PROC_EPS_READ_CYCLES_T1_Type l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T1;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T1, TGT3, l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T1);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_EPS_READ_CYCLES_T1)");
            break;
        }

        fapi2::ATTR_PROC_EPS_READ_CYCLES_T2_Type l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T2;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T2, TGT3, l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T2);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_EPS_READ_CYCLES_T2)");
            break;
        }

        fapi2::ATTR_IS_SIMULATION_Type l_TGT3_ATTR_IS_SIMULATION;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, TGT3, l_TGT3_ATTR_IS_SIMULATION);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_IS_SIMULATION)");
            break;
        }

        auto l_def_IS_SIM = (l_TGT3_ATTR_IS_SIMULATION == literal_1);
        auto l_def_IS_HW = (l_TGT3_ATTR_IS_SIMULATION == literal_0);
        fapi2::ATTR_EFF_DIMM_TYPE_Type l_TGT2_ATTR_EFF_DIMM_TYPE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_DIMM_TYPE, TGT2, l_TGT2_ATTR_EFF_DIMM_TYPE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_DIMM_TYPE)");
            break;
        }

        fapi2::ATTR_CHIP_UNIT_POS_Type l_TGT0_ATTR_CHIP_UNIT_POS;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, TGT0, l_TGT0_ATTR_CHIP_UNIT_POS);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
            break;
        }

        auto l_def_POSITION = l_TGT0_ATTR_CHIP_UNIT_POS;
        auto l_def_PORT_INDEX = (l_def_POSITION % literal_2);
        fapi2::ATTR_EFF_DRAM_CL_Type l_TGT2_ATTR_EFF_DRAM_CL;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_CL, TGT2, l_TGT2_ATTR_EFF_DRAM_CL);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_DRAM_CL)");
            break;
        }

        fapi2::ATTR_MSS_FREQ_Type l_TGT1_ATTR_MSS_FREQ;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_MSS_FREQ, TGT1, l_TGT1_ATTR_MSS_FREQ);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_MSS_FREQ)");
            break;
        }

        auto l_def_MSS_FREQ_EQ_1866 = (l_TGT1_ATTR_MSS_FREQ < literal_1867);
        auto l_def_MEM_TYPE_1866_13 = (l_def_MSS_FREQ_EQ_1866 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_13));
        auto l_def_MEM_TYPE_1866_14 = (l_def_MSS_FREQ_EQ_1866 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_14));
        auto l_def_MSS_FREQ_EQ_2133 = ((l_TGT1_ATTR_MSS_FREQ >= literal_1867) && (l_TGT1_ATTR_MSS_FREQ < literal_2134));
        auto l_def_MEM_TYPE_2133_15 = (l_def_MSS_FREQ_EQ_2133 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_15));
        auto l_def_MEM_TYPE_2133_16 = (l_def_MSS_FREQ_EQ_2133 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_16));
        auto l_def_MSS_FREQ_EQ_2400 = ((l_TGT1_ATTR_MSS_FREQ >= literal_2134) && (l_TGT1_ATTR_MSS_FREQ < literal_2401));
        auto l_def_MEM_TYPE_2400_16 = (l_def_MSS_FREQ_EQ_2400 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_16));
        auto l_def_MEM_TYPE_2400_17 = (l_def_MSS_FREQ_EQ_2400 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_17));
        auto l_def_MEM_TYPE_2400_18 = (l_def_MSS_FREQ_EQ_2400 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_18));
        auto l_def_MSS_FREQ_EQ_2667 = (l_TGT1_ATTR_MSS_FREQ >= literal_2667);
        auto l_def_MEM_TYPE_2667_18 = (l_def_MSS_FREQ_EQ_2667 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_18));
        auto l_def_MEM_TYPE_2667_19 = (l_def_MSS_FREQ_EQ_2667 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_19));
        auto l_def_MEM_TYPE_2667_20 = (l_def_MSS_FREQ_EQ_2667 && (l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] == literal_20));
        auto l_def_RANK_SWITCH_TCK = (literal_4 + ((l_TGT1_ATTR_MSS_FREQ - literal_1866) / literal_267));
        fapi2::ATTR_EFF_DRAM_TCCD_L_Type l_TGT2_ATTR_EFF_DRAM_TCCD_L;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TCCD_L, TGT2, l_TGT2_ATTR_EFF_DRAM_TCCD_L);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_DRAM_TCCD_L)");
            break;
        }

        fapi2::ATTR_EFF_DRAM_CWL_Type l_TGT2_ATTR_EFF_DRAM_CWL;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_CWL, TGT2, l_TGT2_ATTR_EFF_DRAM_CWL);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_DRAM_CWL)");
            break;
        }

        auto l_def_BUS_TURNAROUND_TCK = (literal_4 + ((l_TGT1_ATTR_MSS_FREQ - literal_1866) / literal_267));
        fapi2::ATTR_EFF_DRAM_TWTR_S_Type l_TGT2_ATTR_EFF_DRAM_TWTR_S;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TWTR_S, TGT2, l_TGT2_ATTR_EFF_DRAM_TWTR_S);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_DRAM_TWTR_S)");
            break;
        }

        fapi2::ATTR_EFF_DRAM_TWTR_L_Type l_TGT2_ATTR_EFF_DRAM_TWTR_L;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TWTR_L, TGT2, l_TGT2_ATTR_EFF_DRAM_TWTR_L);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_DRAM_TWTR_L)");
            break;
        }

        fapi2::ATTR_EFF_DRAM_TFAW_Type l_TGT2_ATTR_EFF_DRAM_TFAW;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TFAW, TGT2, l_TGT2_ATTR_EFF_DRAM_TFAW);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_DRAM_TFAW)");
            break;
        }

        fapi2::ATTR_EFF_DRAM_TRCD_Type l_TGT2_ATTR_EFF_DRAM_TRCD;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TRCD, TGT2, l_TGT2_ATTR_EFF_DRAM_TRCD);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_DRAM_TRCD)");
            break;
        }

        fapi2::ATTR_EFF_DRAM_TRP_Type l_TGT2_ATTR_EFF_DRAM_TRP;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TRP, TGT2, l_TGT2_ATTR_EFF_DRAM_TRP);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_DRAM_TRP)");
            break;
        }

        fapi2::ATTR_EFF_DRAM_TRAS_Type l_TGT2_ATTR_EFF_DRAM_TRAS;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TRAS, TGT2, l_TGT2_ATTR_EFF_DRAM_TRAS);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_DRAM_TRAS)");
            break;
        }

        fapi2::ATTR_EFF_DRAM_TWR_Type l_TGT2_ATTR_EFF_DRAM_TWR;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TWR, TGT2, l_TGT2_ATTR_EFF_DRAM_TWR);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_DRAM_TWR)");
            break;
        }

        fapi2::ATTR_EFF_DRAM_TRTP_Type l_TGT2_ATTR_EFF_DRAM_TRTP;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TRTP, TGT2, l_TGT2_ATTR_EFF_DRAM_TRTP);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_DRAM_TRTP)");
            break;
        }

        fapi2::ATTR_EFF_DRAM_TRRD_S_Type l_TGT2_ATTR_EFF_DRAM_TRRD_S;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TRRD_S, TGT2, l_TGT2_ATTR_EFF_DRAM_TRRD_S);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_DRAM_TRRD_S)");
            break;
        }

        fapi2::ATTR_EFF_DRAM_TRRD_L_Type l_TGT2_ATTR_EFF_DRAM_TRRD_L;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TRRD_L, TGT2, l_TGT2_ATTR_EFF_DRAM_TRRD_L);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_DRAM_TRRD_L)");
            break;
        }

        fapi2::ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_Type l_TGT2_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, TGT2, l_TGT2_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM)");
            break;
        }

        auto l_def_SLOT0_DENOMINATOR = ((l_TGT2_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM[l_def_PORT_INDEX][literal_0] == literal_0x0)
                                        | l_TGT2_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM[l_def_PORT_INDEX][literal_0]);
        fapi2::ATTR_EFF_NUM_RANKS_PER_DIMM_Type l_TGT2_ATTR_EFF_NUM_RANKS_PER_DIMM;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_NUM_RANKS_PER_DIMM, TGT2, l_TGT2_ATTR_EFF_NUM_RANKS_PER_DIMM);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_NUM_RANKS_PER_DIMM)");
            break;
        }

        auto l_def_SLOT0_DRAM_STACK_HEIGHT = (l_TGT2_ATTR_EFF_NUM_RANKS_PER_DIMM[l_def_PORT_INDEX][literal_0] /
                                              l_def_SLOT0_DENOMINATOR);
        auto l_def_SLOT1_DENOMINATOR = ((l_TGT2_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM[l_def_PORT_INDEX][literal_1] == literal_0x0)
                                        | l_TGT2_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM[l_def_PORT_INDEX][literal_1]);
        auto l_def_SLOT1_DRAM_STACK_HEIGHT = (l_TGT2_ATTR_EFF_NUM_RANKS_PER_DIMM[l_def_PORT_INDEX][literal_1] /
                                              l_def_SLOT1_DENOMINATOR);
        fapi2::ATTR_MSS_VPD_MT_ODT_RD_Type l_TGT2_ATTR_MSS_VPD_MT_ODT_RD;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_MSS_VPD_MT_ODT_RD, TGT2, l_TGT2_ATTR_MSS_VPD_MT_ODT_RD);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_MSS_VPD_MT_ODT_RD)");
            break;
        }

        fapi2::ATTR_MSS_VPD_MT_ODT_WR_Type l_TGT2_ATTR_MSS_VPD_MT_ODT_WR;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_MSS_VPD_MT_ODT_WR, TGT2, l_TGT2_ATTR_MSS_VPD_MT_ODT_WR);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_MSS_VPD_MT_ODT_WR)");
            break;
        }

        auto l_def_NUM_RANKS = (l_TGT2_ATTR_EFF_NUM_RANKS_PER_DIMM[l_def_PORT_INDEX][literal_0] +
                                l_TGT2_ATTR_EFF_NUM_RANKS_PER_DIMM[l_def_PORT_INDEX][literal_1]);
        fapi2::ATTR_EFF_DRAM_TREFI_Type l_TGT2_ATTR_EFF_DRAM_TREFI;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TREFI, TGT2, l_TGT2_ATTR_EFF_DRAM_TREFI);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_DRAM_TREFI)");
            break;
        }

        auto l_def_REFRESH_INTERVAL = (l_TGT2_ATTR_EFF_DRAM_TREFI[l_def_PORT_INDEX] / (literal_8 * l_def_NUM_RANKS));
        fapi2::ATTR_EFF_DRAM_TRFC_Type l_TGT2_ATTR_EFF_DRAM_TRFC;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TRFC, TGT2, l_TGT2_ATTR_EFF_DRAM_TRFC);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_DRAM_TRFC)");
            break;
        }

        fapi2::ATTR_EFF_DRAM_TRFC_DLR_Type l_TGT2_ATTR_EFF_DRAM_TRFC_DLR;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_TRFC_DLR, TGT2, l_TGT2_ATTR_EFF_DRAM_TRFC_DLR);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_EFF_DRAM_TRFC_DLR)");
            break;
        }

        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            l_rc = fapi2::getScom( TGT0, 0x5010824ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5010824ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b0100, 28, 4, 60 );
            l_scom_buffer.insert<uint64_t> (literal_0b11100, 50, 5, 59 );
            l_scom_buffer.insert<uint64_t> (literal_0b110, 37, 3, 61 );
            l_rc = fapi2::putScom(TGT0, 0x5010824ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5010824ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x5010826ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5010826ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0x1, 0, 8, 56 );
            l_scom_buffer.insert<uint64_t> ((l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T0 / literal_4), 8, 8, 56 );
            l_scom_buffer.insert<uint64_t> ((l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T1 / literal_4), 16, 8, 56 );
            l_scom_buffer.insert<uint64_t> ((l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T2 / literal_4), 32, 8, 56 );
            l_scom_buffer.insert<uint64_t> ((l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T1 / literal_4), 24, 8, 56 );
            l_scom_buffer.insert<uint64_t> ((l_TGT3_ATTR_PROC_EPS_READ_CYCLES_T2 / literal_4), 40, 8, 56 );
            l_rc = fapi2::putScom(TGT0, 0x5010826ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5010826ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x701090aull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x701090aull)");
                break;
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_17, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_1866_13 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_19, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_1866_14 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_20, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_2133_15 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_21, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_2133_16 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_22, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_2400_16 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_22, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_2400_17 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_23, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_2400_18 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_24, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_2667_18 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_24, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_2667_19 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_25, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_2667_20 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_26, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_1866_13 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_21, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_1866_14 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_22, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_2133_15 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_23, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_2133_16 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_24, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_2400_16 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_24, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_2400_17 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_25, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_2400_18 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_26, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_2667_18 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_26, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_2667_19 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_27, 36, 6, 58 );
            }
            else if ((((l_def_MEM_TYPE_2667_20 == literal_1)
                       && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)) && l_def_IS_HW))
            {
                l_scom_buffer.insert<uint64_t> (literal_28, 36, 6, 58 );
            }

            if (((l_def_MSS_FREQ_EQ_1866 == literal_1) && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)))
            {
                l_scom_buffer.insert<uint64_t> (literal_3, 30, 6, 58 );
            }
            else if (((l_def_MSS_FREQ_EQ_2133 == literal_1)
                      && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)))
            {
                l_scom_buffer.insert<uint64_t> (literal_4, 30, 6, 58 );
            }
            else if (((l_def_MSS_FREQ_EQ_2400 == literal_1)
                      && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)))
            {
                l_scom_buffer.insert<uint64_t> (literal_5, 30, 6, 58 );
            }
            else if (((l_def_MSS_FREQ_EQ_2667 == literal_1)
                      && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_1)))
            {
                l_scom_buffer.insert<uint64_t> (literal_6, 30, 6, 58 );
            }
            else if (((l_def_MSS_FREQ_EQ_1866 == literal_1)
                      && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)))
            {
                l_scom_buffer.insert<uint64_t> (literal_2, 30, 6, 58 );
            }
            else if (((l_def_MSS_FREQ_EQ_2133 == literal_1)
                      && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)))
            {
                l_scom_buffer.insert<uint64_t> (literal_3, 30, 6, 58 );
            }
            else if (((l_def_MSS_FREQ_EQ_2400 == literal_1)
                      && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)))
            {
                l_scom_buffer.insert<uint64_t> (literal_4, 30, 6, 58 );
            }
            else if (((l_def_MSS_FREQ_EQ_2667 == literal_1)
                      && (l_TGT2_ATTR_EFF_DIMM_TYPE[l_def_PORT_INDEX][literal_0] == literal_3)))
            {
                l_scom_buffer.insert<uint64_t> (literal_5, 30, 6, 58 );
            }

            l_scom_buffer.insert<uint64_t> (literal_24, 24, 6, 58 );

            if ((l_def_MEM_TYPE_1866_13 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_4, 0, 6, 58 );
            }
            else if ((l_def_MEM_TYPE_1866_14 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_5, 0, 6, 58 );
            }
            else if ((l_def_MEM_TYPE_2133_15 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_6, 0, 6, 58 );
            }
            else if ((l_def_MEM_TYPE_2133_16 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_7, 0, 6, 58 );
            }
            else if ((l_def_MEM_TYPE_2400_16 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_7, 0, 6, 58 );
            }
            else if ((l_def_MEM_TYPE_2400_17 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_8, 0, 6, 58 );
            }
            else if ((l_def_MEM_TYPE_2400_18 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_9, 0, 6, 58 );
            }
            else if ((l_def_MEM_TYPE_2667_18 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_9, 0, 6, 58 );
            }
            else if ((l_def_MEM_TYPE_2667_19 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_10, 0, 6, 58 );
            }
            else if ((l_def_MEM_TYPE_2667_20 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_11, 0, 6, 58 );
            }

            if ((l_def_MEM_TYPE_1866_13 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_9, 6, 6, 58 );
            }
            else if ((l_def_MEM_TYPE_1866_14 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_10, 6, 6, 58 );
            }
            else if ((l_def_MEM_TYPE_2133_15 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_11, 6, 6, 58 );
            }
            else if ((l_def_MEM_TYPE_2133_16 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_12, 6, 6, 58 );
            }
            else if ((l_def_MEM_TYPE_2400_16 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_12, 6, 6, 58 );
            }
            else if ((l_def_MEM_TYPE_2400_17 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_13, 6, 6, 58 );
            }
            else if ((l_def_MEM_TYPE_2400_18 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_14, 6, 6, 58 );
            }
            else if ((l_def_MEM_TYPE_2667_18 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_14, 6, 6, 58 );
            }
            else if ((l_def_MEM_TYPE_2667_19 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_15, 6, 6, 58 );
            }
            else if ((l_def_MEM_TYPE_2667_20 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_16, 6, 6, 58 );
            }

            l_scom_buffer.insert<uint64_t> (literal_1, 12, 6, 58 );
            l_scom_buffer.insert<uint64_t> (literal_6, 18, 6, 58 );
            l_rc = fapi2::putScom(TGT0, 0x701090aull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x701090aull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x701090bull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x701090bull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> ((literal_4 + l_def_RANK_SWITCH_TCK), 0, 4, 60 );
            l_scom_buffer.insert<uint64_t> (literal_4, 4, 4, 60 );
            l_scom_buffer.insert<uint64_t> (literal_4, 8, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_EFF_DRAM_TCCD_L[l_def_PORT_INDEX], 12, 4, 60 );
            l_scom_buffer.insert<uint64_t> ((literal_4 + l_def_RANK_SWITCH_TCK), 16, 4, 60 );
            l_scom_buffer.insert<uint64_t> (literal_4, 20, 4, 60 );
            l_scom_buffer.insert<uint64_t> (literal_4, 24, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_EFF_DRAM_TCCD_L[l_def_PORT_INDEX], 28, 4, 60 );
            l_scom_buffer.insert<uint64_t> ((((l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] + literal_4) + l_def_BUS_TURNAROUND_TCK) -
                                             l_TGT2_ATTR_EFF_DRAM_CWL[l_def_PORT_INDEX]), 32, 5, 59 );
            l_scom_buffer.insert<uint64_t> ((((l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] + literal_4) + l_def_BUS_TURNAROUND_TCK) -
                                             l_TGT2_ATTR_EFF_DRAM_CWL[l_def_PORT_INDEX]), 37, 5, 59 );
            l_scom_buffer.insert<uint64_t> ((((l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX] + literal_4) + l_def_BUS_TURNAROUND_TCK) -
                                             l_TGT2_ATTR_EFF_DRAM_CWL[l_def_PORT_INDEX]), 42, 5, 59 );
            l_scom_buffer.insert<uint64_t> ((((l_TGT2_ATTR_EFF_DRAM_CWL[l_def_PORT_INDEX] + literal_4) + l_def_BUS_TURNAROUND_TCK) -
                                             l_TGT2_ATTR_EFF_DRAM_CL[l_def_PORT_INDEX]), 47, 4, 60 );
            l_scom_buffer.insert<uint64_t> (((l_TGT2_ATTR_EFF_DRAM_CWL[l_def_PORT_INDEX] + literal_4) +
                                             l_TGT2_ATTR_EFF_DRAM_TWTR_S[l_def_PORT_INDEX]), 51, 6, 58 );
            l_scom_buffer.insert<uint64_t> (((l_TGT2_ATTR_EFF_DRAM_CWL[l_def_PORT_INDEX] + literal_4) +
                                             l_TGT2_ATTR_EFF_DRAM_TWTR_S[l_def_PORT_INDEX]), 57, 6, 58 );
            l_rc = fapi2::putScom(TGT0, 0x701090bull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x701090bull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x701090cull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x701090cull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_EFF_DRAM_TCCD_L[l_def_PORT_INDEX], 0, 4, 60 );
            l_scom_buffer.insert<uint64_t> (((l_TGT2_ATTR_EFF_DRAM_CWL[l_def_PORT_INDEX] + literal_4) +
                                             l_TGT2_ATTR_EFF_DRAM_TWTR_L[l_def_PORT_INDEX]), 4, 6, 58 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_EFF_DRAM_TFAW[l_def_PORT_INDEX], 10, 6, 58 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_EFF_DRAM_TRCD[l_def_PORT_INDEX], 16, 5, 59 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_EFF_DRAM_TRP[l_def_PORT_INDEX], 21, 5, 59 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_EFF_DRAM_TRAS[l_def_PORT_INDEX], 26, 6, 58 );
            l_scom_buffer.insert<uint64_t> (((l_TGT2_ATTR_EFF_DRAM_CWL[l_def_PORT_INDEX] + literal_4) +
                                             l_TGT2_ATTR_EFF_DRAM_TWR[l_def_PORT_INDEX]), 41, 7, 57 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_EFF_DRAM_TRTP[l_def_PORT_INDEX], 48, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_EFF_DRAM_TRRD_S[l_def_PORT_INDEX], 52, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_EFF_DRAM_TRRD_L[l_def_PORT_INDEX], 56, 4, 60 );

            if ((l_def_MSS_FREQ_EQ_1866 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_8, 60, 4, 60 );
            }
            else if ((l_def_MSS_FREQ_EQ_2133 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_9, 60, 4, 60 );
            }
            else if ((l_def_MSS_FREQ_EQ_2400 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_10, 60, 4, 60 );
            }
            else if ((l_def_MSS_FREQ_EQ_2667 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_11, 60, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x701090cull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x701090cull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x701090eull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x701090eull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b011000, 24, 6, 58 );
            l_rc = fapi2::putScom(TGT0, 0x701090eull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x701090eull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x7010913ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x7010913ull)");
                break;
            }

            constexpr auto l_MCP_PORT0_SRQ_MBA_FARB0Q_CFG_PARITY_AFTER_CMD_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_MCP_PORT0_SRQ_MBA_FARB0Q_CFG_PARITY_AFTER_CMD_ON, 38, 1, 63 );
            constexpr auto l_MCP_PORT0_SRQ_MBA_FARB0Q_CFG_OE_ALWAYS_ON_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_MCP_PORT0_SRQ_MBA_FARB0Q_CFG_OE_ALWAYS_ON_ON, 55, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x7010913ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x7010913ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x7010914ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x7010914ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b000, 0, 3, 61 );
            l_scom_buffer.insert<uint64_t> (literal_0b100, 3, 3, 61 );
            l_scom_buffer.insert<uint64_t> (literal_0b010, 6, 3, 61 );
            l_scom_buffer.insert<uint64_t> (literal_0b110, 9, 3, 61 );

            if ((l_def_SLOT0_DRAM_STACK_HEIGHT == literal_8))
            {
                l_scom_buffer.insert<uint64_t> (literal_0b001, 12, 3, 61 );
            }
            else if ((l_def_SLOT0_DRAM_STACK_HEIGHT != literal_8))
            {
                l_scom_buffer.insert<uint64_t> (literal_0b000, 12, 3, 61 );
            }

            if ((l_def_SLOT0_DRAM_STACK_HEIGHT == literal_8))
            {
                l_scom_buffer.insert<uint64_t> (literal_0b101, 15, 3, 61 );
            }
            else if ((l_def_SLOT0_DRAM_STACK_HEIGHT != literal_8))
            {
                l_scom_buffer.insert<uint64_t> (literal_0b100, 15, 3, 61 );
            }

            if ((l_def_SLOT0_DRAM_STACK_HEIGHT == literal_8))
            {
                l_scom_buffer.insert<uint64_t> (literal_0b011, 18, 3, 61 );
            }
            else if ((l_def_SLOT0_DRAM_STACK_HEIGHT != literal_8))
            {
                l_scom_buffer.insert<uint64_t> (literal_0b010, 18, 3, 61 );
            }

            if ((l_def_SLOT0_DRAM_STACK_HEIGHT == literal_8))
            {
                l_scom_buffer.insert<uint64_t> (literal_0b111, 21, 3, 61 );
            }
            else if ((l_def_SLOT0_DRAM_STACK_HEIGHT != literal_8))
            {
                l_scom_buffer.insert<uint64_t> (literal_0b110, 21, 3, 61 );
            }

            l_scom_buffer.insert<uint64_t> (literal_0b000, 24, 3, 61 );
            l_scom_buffer.insert<uint64_t> (literal_0b100, 27, 3, 61 );
            l_scom_buffer.insert<uint64_t> (literal_0b010, 30, 3, 61 );
            l_scom_buffer.insert<uint64_t> (literal_0b110, 33, 3, 61 );

            if ((l_def_SLOT1_DRAM_STACK_HEIGHT == literal_8))
            {
                l_scom_buffer.insert<uint64_t> (literal_0b001, 36, 3, 61 );
            }
            else if ((l_def_SLOT1_DRAM_STACK_HEIGHT != literal_8))
            {
                l_scom_buffer.insert<uint64_t> (literal_0b000, 36, 3, 61 );
            }

            if ((l_def_SLOT1_DRAM_STACK_HEIGHT == literal_8))
            {
                l_scom_buffer.insert<uint64_t> (literal_0b101, 39, 3, 61 );
            }
            else if ((l_def_SLOT1_DRAM_STACK_HEIGHT != literal_8))
            {
                l_scom_buffer.insert<uint64_t> (literal_0b100, 39, 3, 61 );
            }

            if ((l_def_SLOT1_DRAM_STACK_HEIGHT == literal_8))
            {
                l_scom_buffer.insert<uint64_t> (literal_0b011, 42, 3, 61 );
            }
            else if ((l_def_SLOT1_DRAM_STACK_HEIGHT != literal_8))
            {
                l_scom_buffer.insert<uint64_t> (literal_0b010, 42, 3, 61 );
            }

            if ((l_def_SLOT1_DRAM_STACK_HEIGHT == literal_8))
            {
                l_scom_buffer.insert<uint64_t> (literal_0b111, 45, 3, 61 );
            }
            else if ((l_def_SLOT1_DRAM_STACK_HEIGHT != literal_8))
            {
                l_scom_buffer.insert<uint64_t> (literal_0b110, 45, 3, 61 );
            }

            l_rc = fapi2::putScom(TGT0, 0x7010914ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x7010914ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x7010915ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x7010915ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_0], 0, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_1], 4, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_2], 8, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_0][literal_3], 12, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_0], 16, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_1], 20, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_2], 24, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_MSS_VPD_MT_ODT_RD[l_def_PORT_INDEX][literal_1][literal_3], 28, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_0], 32, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_1], 36, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_2], 40, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_0][literal_3], 44, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_0], 48, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_1], 52, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_2], 56, 4, 60 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_MSS_VPD_MT_ODT_WR[l_def_PORT_INDEX][literal_1][literal_3], 60, 4, 60 );
            l_rc = fapi2::putScom(TGT0, 0x7010915ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x7010915ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x7010932ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x7010932ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (l_def_REFRESH_INTERVAL, 8, 11, 53 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_EFF_DRAM_TRFC[l_def_PORT_INDEX], 30, 10, 54 );
            l_scom_buffer.insert<uint64_t> (l_TGT2_ATTR_EFF_DRAM_TRFC_DLR[l_def_PORT_INDEX], 40, 10, 54 );
            l_rc = fapi2::putScom(TGT0, 0x7010932ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x7010932ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x7010934ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x7010934ull)");
                break;
            }

            if ((l_def_MSS_FREQ_EQ_1866 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_5, 16, 5, 59 );
            }
            else if ((l_def_MSS_FREQ_EQ_2133 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_6, 16, 5, 59 );
            }
            else if ((l_def_MSS_FREQ_EQ_2400 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_6, 16, 5, 59 );
            }
            else if ((l_def_MSS_FREQ_EQ_2667 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_7, 16, 5, 59 );
            }

            if ((l_def_MSS_FREQ_EQ_1866 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_5, 11, 5, 59 );
            }
            else if ((l_def_MSS_FREQ_EQ_2133 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_6, 11, 5, 59 );
            }
            else if ((l_def_MSS_FREQ_EQ_2400 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_6, 11, 5, 59 );
            }
            else if ((l_def_MSS_FREQ_EQ_2667 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_7, 11, 5, 59 );
            }

            if ((l_def_MSS_FREQ_EQ_1866 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_6, 6, 5, 59 );
            }
            else if ((l_def_MSS_FREQ_EQ_2133 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_7, 6, 5, 59 );
            }
            else if ((l_def_MSS_FREQ_EQ_2400 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_8, 6, 5, 59 );
            }
            else if ((l_def_MSS_FREQ_EQ_2667 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_9, 6, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x7010934ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x7010934ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x7010935ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x7010935ull)");
                break;
            }

            if ((l_def_MSS_FREQ_EQ_1866 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_10, 17, 5, 59 );
            }
            else if ((l_def_MSS_FREQ_EQ_2133 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_11, 17, 5, 59 );
            }
            else if ((l_def_MSS_FREQ_EQ_2400 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_12, 17, 5, 59 );
            }
            else if ((l_def_MSS_FREQ_EQ_2667 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_14, 17, 5, 59 );
            }

            if ((l_def_MSS_FREQ_EQ_1866 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_10, 22, 5, 59 );
            }
            else if ((l_def_MSS_FREQ_EQ_2133 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_11, 22, 5, 59 );
            }
            else if ((l_def_MSS_FREQ_EQ_2400 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_12, 22, 5, 59 );
            }
            else if ((l_def_MSS_FREQ_EQ_2667 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_14, 22, 5, 59 );
            }

            l_scom_buffer.insert<uint64_t> (literal_5, 12, 5, 59 );

            if ((l_def_MSS_FREQ_EQ_1866 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_597, 27, 11, 53 );
            }
            else if ((l_def_MSS_FREQ_EQ_2133 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_768, 27, 11, 53 );
            }
            else if ((l_def_MSS_FREQ_EQ_2400 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_768, 27, 11, 53 );
            }
            else if ((l_def_MSS_FREQ_EQ_2667 == literal_1))
            {
                l_scom_buffer.insert<uint64_t> (literal_939, 27, 11, 53 );
            }

            l_rc = fapi2::putScom(TGT0, 0x7010935ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x7010935ull)");
                break;
            }
        }

    }
    while(0);

    return l_rc;
}
