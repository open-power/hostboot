/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/procedures/hwp/initfiles/odyssey_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
#include "odyssey_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_3201 = 3201;
constexpr uint64_t literal_3 = 3;
constexpr uint64_t literal_4001 = 4001;
constexpr uint64_t literal_5 = 5;
constexpr uint64_t literal_7 = 7;
constexpr uint64_t literal_14 = 14;
constexpr uint64_t literal_64 = 64;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_32 = 32;
constexpr uint64_t literal_20 = 20;
constexpr uint64_t literal_16 = 16;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_8 = 8;
constexpr uint64_t literal_6 = 6;
constexpr uint64_t literal_27 = 27;
constexpr uint64_t literal_33 = 33;
constexpr uint64_t literal_39 = 39;
constexpr uint64_t literal_10 = 10;
constexpr uint64_t literal_0xFF = 0xFF;
constexpr uint64_t literal_0x1 = 0x1;
constexpr uint64_t literal_18 = 18;
constexpr uint64_t literal_12 = 12;
constexpr uint64_t literal_40 = 40;
constexpr uint64_t literal_128 = 128;
constexpr uint64_t literal_24 = 24;
constexpr uint64_t literal_13 = 13;
constexpr uint64_t literal_15 = 15;
constexpr uint64_t literal_17 = 17;
constexpr uint64_t literal_19 = 19;
constexpr uint64_t literal_9 = 9;
constexpr uint64_t literal_11 = 11;
constexpr uint64_t literal_0x0 = 0x0;
constexpr uint64_t literal_512 = 512;
constexpr uint64_t literal_640 = 640;
constexpr uint64_t literal_768 = 768;
constexpr uint64_t literal_30 = 30;
constexpr uint64_t literal_36 = 36;
constexpr uint64_t literal_0b11111 = 0b11111;
constexpr uint64_t literal_0b10001 = 0b10001;
constexpr uint64_t literal_0b01111 = 0b01111;
constexpr uint64_t literal_0x2 = 0x2;
constexpr uint64_t literal_0x3 = 0x3;
constexpr uint64_t literal_0x4 = 0x4;
constexpr uint64_t literal_0x5 = 0x5;
constexpr uint64_t literal_0x6 = 0x6;
constexpr uint64_t literal_0x7 = 0x7;

fapi2::ReturnCode odyssey_scom(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& TGT0,
                               const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT2)
{
    {
        fapi2::ATTR_MSS_OCMB_HALF_DIMM_MODE_Type l_TGT0_ATTR_MSS_OCMB_HALF_DIMM_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_HALF_DIMM_MODE, TGT0, l_TGT0_ATTR_MSS_OCMB_HALF_DIMM_MODE));
        uint64_t l_def_ATTR_MSS_OCMB_HALF_DIMM_MODE = l_TGT0_ATTR_MSS_OCMB_HALF_DIMM_MODE;
        fapi2::ATTR_MEM_EFF_FREQ_Type l_TGT1_ATTR_MEM_EFF_FREQ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_FREQ, TGT1, l_TGT1_ATTR_MEM_EFF_FREQ));
        uint64_t l_def_MEM_EFF_FREQ_EQ_3200 = (l_TGT1_ATTR_MEM_EFF_FREQ < literal_3201);
        fapi2::ATTR_MEM_EFF_DRAM_CL_Type l_TGT1_ATTR_MEM_EFF_DRAM_CL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_CL, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_CL));
        uint64_t l_def_MEM_EFF_FREQ_EQ_4000 = ((l_TGT1_ATTR_MEM_EFF_FREQ >= literal_3201)
                                               && (l_TGT1_ATTR_MEM_EFF_FREQ < literal_4001));
        uint64_t l_def_MEM_EFF_FREQ_EQ_4800 = (l_TGT1_ATTR_MEM_EFF_FREQ >= literal_4001);
        fapi2::ATTR_MEM_EFF_DRAM_TCCD_L_WR_Type l_TGT1_ATTR_MEM_EFF_DRAM_TCCD_L_WR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TCCD_L_WR, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TCCD_L_WR));
        fapi2::ATTR_MEM_EFF_DRAM_TWTR_S_Type l_TGT1_ATTR_MEM_EFF_DRAM_TWTR_S;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TWTR_S, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TWTR_S));
        fapi2::ATTR_MEM_DRAM_CWL_Type l_TGT1_ATTR_MEM_DRAM_CWL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_DRAM_CWL, TGT1, l_TGT1_ATTR_MEM_DRAM_CWL));
        fapi2::ATTR_MEM_EFF_DRAM_TCCD_L_Type l_TGT1_ATTR_MEM_EFF_DRAM_TCCD_L;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TCCD_L, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TCCD_L));
        fapi2::ATTR_MEM_EFF_DRAM_TWTR_L_Type l_TGT1_ATTR_MEM_EFF_DRAM_TWTR_L;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TWTR_L, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TWTR_L));
        fapi2::ATTR_MEM_EFF_DRAM_TRCD_Type l_TGT1_ATTR_MEM_EFF_DRAM_TRCD;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TRCD, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TRCD));
        fapi2::ATTR_MEM_EFF_DRAM_TRP_Type l_TGT1_ATTR_MEM_EFF_DRAM_TRP;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TRP, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TRP));
        fapi2::ATTR_MEM_EFF_DRAM_TWR_Type l_TGT1_ATTR_MEM_EFF_DRAM_TWR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TWR, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TWR));
        fapi2::ATTR_MEM_EFF_DRAM_TRRD_S_Type l_TGT1_ATTR_MEM_EFF_DRAM_TRRD_S;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TRRD_S, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TRRD_S));
        fapi2::ATTR_MEM_EFF_DRAM_TRRD_L_Type l_TGT1_ATTR_MEM_EFF_DRAM_TRRD_L;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TRRD_L, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TRRD_L));
        fapi2::ATTR_MEM_EFF_DRAM_TFAW_Type l_TGT1_ATTR_MEM_EFF_DRAM_TFAW;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TFAW, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TFAW));
        fapi2::ATTR_MEM_EFF_DDR5_MEM_PORT_ENABLE_Type l_TGT0_ATTR_MEM_EFF_DDR5_MEM_PORT_ENABLE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DDR5_MEM_PORT_ENABLE, TGT0, l_TGT0_ATTR_MEM_EFF_DDR5_MEM_PORT_ENABLE));
        fapi2::ATTR_MEM_EFF_DRAM_DENSITY_Type l_TGT1_ATTR_MEM_EFF_DRAM_DENSITY;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_DENSITY, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_DENSITY));
        uint64_t l_def_24GB_DRAM = (l_TGT1_ATTR_MEM_EFF_DRAM_DENSITY[literal_0] == literal_24);
        fapi2::ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_Type l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM, TGT1,
                               l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM));
        uint64_t l_def_M_EN = (l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0] == literal_2);
        uint64_t l_def_R16_EN = ((l_TGT1_ATTR_MEM_EFF_DRAM_DENSITY[literal_0] == literal_24)
                                 || (l_TGT1_ATTR_MEM_EFF_DRAM_DENSITY[literal_0] == literal_32));
        uint64_t l_def_D_EN = (l_TGT0_ATTR_MEM_EFF_DDR5_MEM_PORT_ENABLE == literal_3);
        fapi2::ATTR_MEM_EFF_DRAM_WIDTH_Type l_TGT1_ATTR_MEM_EFF_DRAM_WIDTH;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_WIDTH, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_WIDTH));
        uint64_t l_def_C10_EN = (l_TGT1_ATTR_MEM_EFF_DRAM_WIDTH[literal_0] != literal_8);
        fapi2::ATTR_MEM_3DS_HEIGHT_Type l_TGT1_ATTR_MEM_3DS_HEIGHT;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_3DS_HEIGHT, TGT1, l_TGT1_ATTR_MEM_3DS_HEIGHT));
        uint64_t l_def_S2_EN = (l_TGT1_ATTR_MEM_3DS_HEIGHT[literal_0] != literal_0);
        uint64_t l_def_S1_EN = (l_TGT1_ATTR_MEM_3DS_HEIGHT[literal_0] == literal_4);
        fapi2::ATTR_MEM_EFF_DIMM_TYPE_Type l_TGT1_ATTR_MEM_EFF_DIMM_TYPE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DIMM_TYPE, TGT1, l_TGT1_ATTR_MEM_EFF_DIMM_TYPE));
        uint64_t l_def_72B_DIMM = ((l_TGT1_ATTR_MEM_EFF_DIMM_TYPE[literal_0] == literal_1)
                                   || (l_TGT1_ATTR_MEM_EFF_DIMM_TYPE[literal_0] == literal_2));
        fapi2::ATTR_MEM_EFF_DDR5_RTT_PARK_RD_Type l_TGT1_ATTR_MEM_EFF_DDR5_RTT_PARK_RD;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DDR5_RTT_PARK_RD, TGT1, l_TGT1_ATTR_MEM_EFF_DDR5_RTT_PARK_RD));
        fapi2::ATTR_MEM_EFF_DDR5_RTT_PARK_WR_Type l_TGT1_ATTR_MEM_EFF_DDR5_RTT_PARK_WR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DDR5_RTT_PARK_WR, TGT1, l_TGT1_ATTR_MEM_EFF_DDR5_RTT_PARK_WR));
        fapi2::ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM_Type l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM, TGT1, l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM));
        uint64_t l_def_NUM_RANKS = (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] +
                                    (l_def_ATTR_MSS_OCMB_HALF_DIMM_MODE * l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0]));
        uint64_t l_def_NUM_RANKS_DENOMINATOR = ((l_def_NUM_RANKS == literal_0x0) | l_def_NUM_RANKS);
        fapi2::ATTR_MEM_EFF_DRAM_TREFI_Type l_TGT1_ATTR_MEM_EFF_DRAM_TREFI;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TREFI, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TREFI));
        uint64_t l_def_REFRESH_INTERVAL = (l_TGT1_ATTR_MEM_EFF_DRAM_TREFI / (literal_16 * l_def_NUM_RANKS_DENOMINATOR));
        uint64_t l_def_REFR_CHECK_INTERVAL = (((l_def_REFRESH_INTERVAL * l_def_NUM_RANKS) + l_def_NUM_RANKS) - literal_1);
        fapi2::ATTR_MEM_EFF_DRAM_TRFC_Type l_TGT1_ATTR_MEM_EFF_DRAM_TRFC;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TRFC, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TRFC));
        fapi2::ATTR_MEM_EFF_DRAM_TRFC_DLR_Type l_TGT1_ATTR_MEM_EFF_DRAM_TRFC_DLR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TRFC_DLR, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TRFC_DLR));
        fapi2::ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_Type l_TGT2_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_POWER_CONTROL_REQUESTED, TGT2, l_TGT2_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED));
        uint64_t l_def_NUM_UPPER_ADDR_BITS = (((((l_def_D_EN + l_def_M_EN) + l_def_S2_EN) + l_def_S1_EN) + l_def_R16_EN) +
                                              l_def_C10_EN);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80108e4ull, l_scom_buffer ));

            if ((l_def_ATTR_MSS_OCMB_HALF_DIMM_MODE == literal_1))
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80108e4ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801100cull, l_scom_buffer ));

            if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>((l_TGT1_ATTR_MEM_EFF_DRAM_CL + literal_3) );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4000 == literal_1))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>((l_TGT1_ATTR_MEM_EFF_DRAM_CL + literal_5) );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4800 == literal_1))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>((l_TGT1_ATTR_MEM_EFF_DRAM_CL + literal_7) );
            }

            l_scom_buffer.insert<8, 8, 56, uint64_t>((l_TGT1_ATTR_MEM_EFF_DRAM_CL - literal_14) );
            l_scom_buffer.insert<16, 8, 56, uint64_t>((l_TGT1_ATTR_MEM_EFF_DRAM_CL - literal_14) );
            l_scom_buffer.insert<24, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<31, 4, 60, uint64_t>(literal_0 );
            l_scom_buffer.insert<35, 4, 60, uint64_t>(literal_0 );
            l_scom_buffer.insert<39, 7, 57, uint64_t>(literal_32 );
            l_scom_buffer.insert<46, 6, 58, uint64_t>((l_TGT1_ATTR_MEM_EFF_DRAM_CL - literal_20) );
            l_scom_buffer.insert<52, 6, 58, uint64_t>((l_TGT1_ATTR_MEM_EFF_DRAM_CL - literal_16) );
            l_scom_buffer.insert<58, 6, 58, uint64_t>((l_TGT1_ATTR_MEM_EFF_DRAM_CL - literal_16) );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801100cull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801100dull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_7 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_4 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_4 );
            l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_7 );
            l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_4 );
            l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_4 );
            l_scom_buffer.insert<28, 5, 59, uint64_t>((l_TGT1_ATTR_MEM_EFF_DRAM_TCCD_L_WR / literal_2) );
            l_scom_buffer.insert<33, 4, 60, uint64_t>(literal_8 );
            l_scom_buffer.insert<37, 5, 59, uint64_t>(literal_8 );
            l_scom_buffer.insert<42, 5, 59, uint64_t>(literal_8 );
            l_scom_buffer.insert<47, 4, 60, uint64_t>(literal_6 );
            l_scom_buffer.insert<51, 6, 58, uint64_t>(((((l_TGT1_ATTR_MEM_DRAM_CWL + literal_8) + l_TGT1_ATTR_MEM_EFF_DRAM_TWTR_S) +
                    literal_1) / literal_2) );
            l_scom_buffer.insert<57, 6, 58, uint64_t>(((((l_TGT1_ATTR_MEM_DRAM_CWL + literal_8) + l_TGT1_ATTR_MEM_EFF_DRAM_TWTR_S) +
                    literal_1) / literal_2) );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801100dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801100eull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(((l_TGT1_ATTR_MEM_EFF_DRAM_TCCD_L + literal_1) / literal_2) );
            l_scom_buffer.insert<4, 6, 58, uint64_t>(((((l_TGT1_ATTR_MEM_DRAM_CWL + literal_8) + l_TGT1_ATTR_MEM_EFF_DRAM_TWTR_L) +
                    literal_1) / literal_2) );
            l_scom_buffer.insert<16, 6, 58, uint64_t>(((l_TGT1_ATTR_MEM_EFF_DRAM_TRCD + literal_1) / literal_2) );
            l_scom_buffer.insert<22, 6, 58, uint64_t>((l_TGT1_ATTR_MEM_EFF_DRAM_TRP / literal_2) );

            if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<28, 7, 57, uint64_t>(literal_27 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4000 == literal_1))
            {
                l_scom_buffer.insert<28, 7, 57, uint64_t>(literal_33 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4800 == literal_1))
            {
                l_scom_buffer.insert<28, 7, 57, uint64_t>(literal_39 );
            }

            l_scom_buffer.insert<36, 8, 56, uint64_t>((((l_TGT1_ATTR_MEM_DRAM_CWL + l_TGT1_ATTR_MEM_EFF_DRAM_TWR) + literal_10) /
                    literal_2) );

            if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<44, 8, 56, uint64_t>(literal_7 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4000 == literal_1))
            {
                l_scom_buffer.insert<44, 8, 56, uint64_t>(literal_8 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4800 == literal_1))
            {
                l_scom_buffer.insert<44, 8, 56, uint64_t>(literal_10 );
            }

            l_scom_buffer.insert<52, 4, 60, uint64_t>(((l_TGT1_ATTR_MEM_EFF_DRAM_TRRD_S + literal_1) / literal_2) );
            l_scom_buffer.insert<56, 4, 60, uint64_t>(((l_TGT1_ATTR_MEM_EFF_DRAM_TRRD_L + literal_1) / literal_2) );
            l_scom_buffer.insert<10, 6, 58, uint64_t>((l_TGT1_ATTR_MEM_EFF_DRAM_TFAW / literal_2) );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801100eull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801100full, l_scom_buffer ));

            l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xFF );
            l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xFF );
            l_scom_buffer.insert<24, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<25, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<26, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<27, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<28, 2, 62, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<30, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<31, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<32, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<33, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<35, 11, 53, uint64_t>(literal_32 );
            l_scom_buffer.insert<46, 5, 59, uint64_t>(literal_0 );
            l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_6 );
            l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801100full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011010ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_18 );
            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_18 );
            l_scom_buffer.insert<12, 5, 59, uint64_t>(literal_12 );
            l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<19, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<20, 5, 59, uint64_t>(literal_10 );
            l_scom_buffer.insert<25, 5, 59, uint64_t>(literal_10 );
            l_scom_buffer.insert<30, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<31, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<32, 5, 59, uint64_t>(literal_8 );
            l_scom_buffer.insert<37, 5, 59, uint64_t>(literal_12 );
            l_scom_buffer.insert<42, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<43, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<44, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<45, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<46, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<47, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011010ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011011ull, l_scom_buffer ));

            l_scom_buffer.insert<1, 2, 62, uint64_t>(literal_3 );
            l_scom_buffer.insert<3, 9, 55, uint64_t>(literal_8 );
            l_scom_buffer.insert<12, 8, 56, uint64_t>(literal_20 );
            l_scom_buffer.insert<20, 2, 62, uint64_t>(literal_1 );
            l_scom_buffer.insert<22, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<23, 6, 58, uint64_t>(literal_40 );
            l_scom_buffer.insert<33, 2, 62, uint64_t>(literal_2 );
            l_scom_buffer.insert<35, 9, 55, uint64_t>(literal_128 );
            l_scom_buffer.insert<44, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<45, 10, 54, uint64_t>(literal_0 );
            l_scom_buffer.insert<55, 9, 55, uint64_t>(literal_128 );
            l_scom_buffer.insert<31, 1, 63, uint64_t>(literal_1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011011ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011012ull, l_scom_buffer ));

            if (((l_TGT0_ATTR_MEM_EFF_DDR5_MEM_PORT_ENABLE != literal_1)
                 && (l_TGT0_ATTR_MEM_EFF_DDR5_MEM_PORT_ENABLE != literal_3)))
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0 );
            }
            else if (((l_TGT0_ATTR_MEM_EFF_DDR5_MEM_PORT_ENABLE == literal_1)
                      || (l_TGT0_ATTR_MEM_EFF_DDR5_MEM_PORT_ENABLE == literal_3)))
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
            }

            if ((l_TGT0_ATTR_MEM_EFF_DDR5_MEM_PORT_ENABLE < literal_2))
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0 );
            }
            else if ((l_TGT0_ATTR_MEM_EFF_DDR5_MEM_PORT_ENABLE >= literal_2))
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_1 );
            }

            if ((l_TGT0_ATTR_MEM_EFF_DDR5_MEM_PORT_ENABLE != literal_2))
            {
                l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0 );
            }
            else if ((l_TGT0_ATTR_MEM_EFF_DDR5_MEM_PORT_ENABLE == literal_2))
            {
                l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_1 );
            }

            if ((l_def_24GB_DRAM == literal_0))
            {
                l_scom_buffer.insert<24, 1, 63, uint64_t>(literal_0 );
            }
            else if ((l_def_24GB_DRAM == literal_1))
            {
                l_scom_buffer.insert<24, 1, 63, uint64_t>(literal_1 );
            }

            l_scom_buffer.insert<25, 1, 63, uint64_t>(literal_0 );

            if ((l_def_24GB_DRAM == literal_0))
            {
                l_scom_buffer.insert<26, 1, 63, uint64_t>(literal_0 );
            }
            else if ((l_def_24GB_DRAM == literal_1))
            {
                l_scom_buffer.insert<26, 1, 63, uint64_t>(literal_1 );
            }

            l_scom_buffer.insert<27, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<30, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<31, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<8, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<17, 1, 63, uint64_t>(l_def_M_EN );
            l_scom_buffer.insert<18, 1, 63, uint64_t>(l_def_M_EN );
            l_scom_buffer.insert<41, 1, 63, uint64_t>(l_def_R16_EN );
            l_scom_buffer.insert<42, 1, 63, uint64_t>(l_def_R16_EN );
            l_scom_buffer.insert<33, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_0 );

            if ((l_def_ATTR_MSS_OCMB_HALF_DIMM_MODE != ENUM_ATTR_MSS_OCMB_HALF_DIMM_MODE_HALF_DIMM))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0 );
            }
            else if (((l_def_D_EN == literal_0)
                      && (l_def_ATTR_MSS_OCMB_HALF_DIMM_MODE == ENUM_ATTR_MSS_OCMB_HALF_DIMM_MODE_HALF_DIMM)))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_1 );
            }
            else if (((l_def_D_EN == literal_1)
                      && (l_def_ATTR_MSS_OCMB_HALF_DIMM_MODE == ENUM_ATTR_MSS_OCMB_HALF_DIMM_MODE_HALF_DIMM)))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_2 );
            }

            if ((l_def_D_EN == literal_0))
            {
                l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0 );
            }
            else if (((l_def_D_EN == literal_1)
                      && (l_def_ATTR_MSS_OCMB_HALF_DIMM_MODE == ENUM_ATTR_MSS_OCMB_HALF_DIMM_MODE_HALF_DIMM)))
            {
                l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_1 );
            }
            else if (((l_def_D_EN == literal_1)
                      && (l_def_ATTR_MSS_OCMB_HALF_DIMM_MODE != ENUM_ATTR_MSS_OCMB_HALF_DIMM_MODE_HALF_DIMM)))
            {
                l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_2 );
            }

            if ((l_def_M_EN == literal_0))
            {
                l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_0 );
            }
            else if ((((l_def_M_EN == literal_1) && (l_def_D_EN == literal_0)) && (l_def_C10_EN == literal_0)))
            {
                l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_13 );
            }
            else if (((((l_def_M_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_C10_EN == literal_0))
                      || (((l_def_M_EN == literal_1) && (l_def_D_EN == literal_0)) && (l_def_C10_EN == literal_1))))
            {
                l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_14 );
            }
            else if ((((l_def_M_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_C10_EN == literal_1)))
            {
                l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_15 );
            }

            if (((((l_def_D_EN == literal_0) && (l_def_S2_EN == literal_0)) && (l_def_M_EN == literal_0))
                 && (l_def_C10_EN == literal_0)))
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_13 );
            }
            else if ((((((((l_def_D_EN == literal_1) && (l_def_S2_EN == literal_0)) && (l_def_M_EN == literal_0))
                         && (l_def_C10_EN == literal_0)) || (((((l_def_D_EN == literal_0) && (l_def_S2_EN == literal_1))
                                 && (l_def_S1_EN == literal_0)) && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_0)))
                       || ((((l_def_D_EN == literal_0) && (l_def_S2_EN == literal_0)) && (l_def_M_EN == literal_1))
                           && (l_def_C10_EN == literal_0))) || ((((l_def_D_EN == literal_0) && (l_def_S2_EN == literal_0))
                                   && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_1))))
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_14 );
            }
            else if ((((((((((((l_def_D_EN == literal_1) && (l_def_S2_EN == literal_1)) && (l_def_S1_EN == literal_0))
                             && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_0)) || ((((l_def_D_EN == literal_1)
                                     && (l_def_S2_EN == literal_0)) && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_0)))
                          || ((((l_def_D_EN == literal_1) && (l_def_S2_EN == literal_0)) && (l_def_M_EN == literal_0))
                              && (l_def_C10_EN == literal_1))) || (((((l_def_D_EN == literal_0) && (l_def_S2_EN == literal_1))
                                      && (l_def_S1_EN == literal_0)) && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_0)))
                        || (((((l_def_D_EN == literal_0) && (l_def_S2_EN == literal_1)) && (l_def_S1_EN == literal_0))
                             && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_1))) || ((((l_def_D_EN == literal_0)
                                     && (l_def_S2_EN == literal_0)) && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_1)))
                      || (((((l_def_D_EN == literal_0) && (l_def_S2_EN == literal_1)) && (l_def_S1_EN == literal_1))
                           && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_0))))
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_15 );
            }
            else if ((((((((((((l_def_D_EN == literal_1) && (l_def_S2_EN == literal_1)) && (l_def_S1_EN == literal_1))
                             && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_0)) || (((((l_def_D_EN == literal_1)
                                     && (l_def_S2_EN == literal_1)) && (l_def_S1_EN == literal_0)) && (l_def_M_EN == literal_1))
                                     && (l_def_C10_EN == literal_0))) || (((((l_def_D_EN == literal_1) && (l_def_S2_EN == literal_1))
                                             && (l_def_S1_EN == literal_0)) && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_1)))
                         || (((((l_def_D_EN == literal_1) && (l_def_S2_EN == literal_0)) && (l_def_S1_EN == literal_0))
                              && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_1))) || (((((l_def_D_EN == literal_0)
                                      && (l_def_S2_EN == literal_1)) && (l_def_S1_EN == literal_0)) && (l_def_M_EN == literal_1))
                                      && (l_def_C10_EN == literal_1))) || (((((l_def_D_EN == literal_0) && (l_def_S2_EN == literal_1))
                                              && (l_def_S1_EN == literal_1)) && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_0)))
                      || (((((l_def_D_EN == literal_0) && (l_def_S2_EN == literal_1)) && (l_def_S1_EN == literal_1))
                           && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_1))))
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_16 );
            }
            else if (((((((((l_def_D_EN == literal_1) && (l_def_S2_EN == literal_1)) && (l_def_S1_EN == literal_1))
                          && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_0)) || (((((l_def_D_EN == literal_1)
                                  && (l_def_S2_EN == literal_1)) && (l_def_S1_EN == literal_1)) && (l_def_M_EN == literal_0))
                                  && (l_def_C10_EN == literal_1))) || (((((l_def_D_EN == literal_1) && (l_def_S2_EN == literal_1))
                                          && (l_def_S1_EN == literal_0)) && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_1)))
                      || (((((l_def_D_EN == literal_0) && (l_def_S2_EN == literal_1)) && (l_def_S1_EN == literal_1))
                           && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_1))))
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_17 );
            }
            else if ((((((l_def_D_EN == literal_1) && (l_def_S2_EN == literal_1)) && (l_def_S1_EN == literal_1))
                       && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_1)))
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_18 );
            }

            if ((l_def_R16_EN == literal_0))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0 );
            }
            else if ((((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_0)) && (l_def_S2_EN == literal_0))
                       && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_0)))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_14 );
            }
            else if (((((((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_S2_EN == literal_0))
                          && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_0)) || ((((((l_def_R16_EN == literal_1)
                                  && (l_def_D_EN == literal_0)) && (l_def_S2_EN == literal_1)) && (l_def_S1_EN == literal_0))
                                  && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_0))) || (((((l_def_R16_EN == literal_1)
                                          && (l_def_D_EN == literal_0)) && (l_def_S2_EN == literal_0)) && (l_def_M_EN == literal_1))
                                          && (l_def_C10_EN == literal_0))) || (((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_0))
                                                  && (l_def_S2_EN == literal_0)) && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_1))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_15 );
            }
            else if (((((((((((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_S2_EN == literal_1))
                              && (l_def_S1_EN == literal_0)) && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_0))
                           || (((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_S2_EN == literal_0))
                                && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_0))) || (((((l_def_R16_EN == literal_1)
                                        && (l_def_D_EN == literal_1)) && (l_def_S2_EN == literal_0)) && (l_def_M_EN == literal_0))
                                        && (l_def_C10_EN == literal_1))) || ((((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_0))
                                                && (l_def_S2_EN == literal_1)) && (l_def_S1_EN == literal_0)) && (l_def_M_EN == literal_1))
                                                && (l_def_C10_EN == literal_0))) || ((((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_0))
                                                        && (l_def_S2_EN == literal_1)) && (l_def_S1_EN == literal_0)) && (l_def_M_EN == literal_0))
                                                        && (l_def_C10_EN == literal_1))) || (((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_0))
                                                                && (l_def_S2_EN == literal_0)) && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_1)))
                      || ((((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_0)) && (l_def_S2_EN == literal_1))
                            && (l_def_S1_EN == literal_1)) && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_0))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_16 );
            }
            else if (((((((((((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_S2_EN == literal_1))
                              && (l_def_S1_EN == literal_1)) && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_0))
                           || ((((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_S2_EN == literal_1))
                                 && (l_def_S1_EN == literal_0)) && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_0)))
                          || ((((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_S2_EN == literal_1))
                                && (l_def_S1_EN == literal_0)) && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_1)))
                         || ((((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_S2_EN == literal_0))
                               && (l_def_S1_EN == literal_0)) && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_1)))
                        || ((((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_0)) && (l_def_S2_EN == literal_1))
                              && (l_def_S1_EN == literal_0)) && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_1)))
                       || ((((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_0)) && (l_def_S2_EN == literal_1))
                             && (l_def_S1_EN == literal_1)) && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_0)))
                      || ((((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_0)) && (l_def_S2_EN == literal_1))
                            && (l_def_S1_EN == literal_1)) && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_1))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_17 );
            }
            else if ((((((((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_S2_EN == literal_1))
                           && (l_def_S1_EN == literal_1)) && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_0))
                        || ((((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_S2_EN == literal_1))
                              && (l_def_S1_EN == literal_1)) && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_1)))
                       || ((((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_S2_EN == literal_1))
                             && (l_def_S1_EN == literal_0)) && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_1)))
                      || ((((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_0)) && (l_def_S2_EN == literal_1))
                            && (l_def_S1_EN == literal_1)) && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_1))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_18 );
            }
            else if (((((((l_def_R16_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_S2_EN == literal_1))
                        && (l_def_S1_EN == literal_1)) && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_1)))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_19 );
            }

            l_scom_buffer.insert<35, 5, 59, uint64_t>(literal_0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011012ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011013ull, l_scom_buffer ));

            l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<9, 1, 63, uint64_t>(l_def_S1_EN );
            l_scom_buffer.insert<10, 1, 63, uint64_t>(l_def_S1_EN );
            l_scom_buffer.insert<17, 1, 63, uint64_t>(l_def_S2_EN );
            l_scom_buffer.insert<18, 1, 63, uint64_t>(l_def_S2_EN );

            if ((l_def_D_EN == literal_0))
            {
                l_scom_buffer.insert<35, 5, 59, uint64_t>(literal_7 );
            }
            else if ((l_def_D_EN == literal_1))
            {
                l_scom_buffer.insert<35, 5, 59, uint64_t>(literal_8 );
            }

            if ((l_def_D_EN == literal_0))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_8 );
            }
            else if ((l_def_D_EN == literal_1))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_9 );
            }

            if ((l_def_D_EN == literal_0))
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_9 );
            }
            else if ((l_def_D_EN == literal_1))
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_10 );
            }

            if ((l_def_D_EN == literal_0))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_10 );
            }
            else if ((l_def_D_EN == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_11 );
            }

            if ((l_def_S2_EN == literal_0))
            {
                l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_0 );
            }
            else if (((((l_def_S2_EN == literal_1) && (l_def_D_EN == literal_0)) && (l_def_M_EN == literal_0))
                      && (l_def_C10_EN == literal_0)))
            {
                l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_13 );
            }
            else if (((((((l_def_S2_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_M_EN == literal_0))
                        && (l_def_C10_EN == literal_0)) || ((((l_def_S2_EN == literal_1) && (l_def_D_EN == literal_0))
                                && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_0))) || ((((l_def_S2_EN == literal_1)
                                        && (l_def_D_EN == literal_0)) && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_1))))
            {
                l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_14 );
            }
            else if (((((((l_def_S2_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_M_EN == literal_1))
                        && (l_def_C10_EN == literal_0)) || ((((l_def_S2_EN == literal_1) && (l_def_D_EN == literal_1))
                                && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_1))) || ((((l_def_S2_EN == literal_1)
                                        && (l_def_D_EN == literal_0)) && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_1))))
            {
                l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_15 );
            }
            else if (((((l_def_S2_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_M_EN == literal_1))
                      && (l_def_C10_EN == literal_1)))
            {
                l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_16 );
            }

            if ((l_def_S1_EN == literal_0))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0 );
            }
            else if (((((l_def_S1_EN == literal_1) && (l_def_D_EN == literal_0)) && (l_def_M_EN == literal_0))
                      && (l_def_C10_EN == literal_0)))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_14 );
            }
            else if (((((((l_def_S1_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_M_EN == literal_0))
                        && (l_def_C10_EN == literal_0)) || ((((l_def_S1_EN == literal_1) && (l_def_D_EN == literal_0))
                                && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_0))) || ((((l_def_S1_EN == literal_1)
                                        && (l_def_D_EN == literal_0)) && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_1))))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_15 );
            }
            else if (((((((l_def_S1_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_M_EN == literal_1))
                        && (l_def_C10_EN == literal_0)) || ((((l_def_S1_EN == literal_1) && (l_def_D_EN == literal_1))
                                && (l_def_M_EN == literal_0)) && (l_def_C10_EN == literal_1))) || ((((l_def_S1_EN == literal_1)
                                        && (l_def_D_EN == literal_0)) && (l_def_M_EN == literal_1)) && (l_def_C10_EN == literal_1))))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_16 );
            }
            else if (((((l_def_S1_EN == literal_1) && (l_def_D_EN == literal_1)) && (l_def_M_EN == literal_1))
                      && (l_def_C10_EN == literal_1)))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_17 );
            }

            l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011013ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011014ull, l_scom_buffer ));

            l_scom_buffer.insert<17, 1, 63, uint64_t>(l_def_C10_EN );
            l_scom_buffer.insert<18, 1, 63, uint64_t>(l_def_C10_EN );
            l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<33, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_1 );

            if ((l_def_D_EN == literal_0))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_2 );
            }
            else if ((l_def_D_EN == literal_1))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_3 );
            }

            if ((l_def_D_EN == literal_0))
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_3 );
            }
            else if ((l_def_D_EN == literal_1))
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_4 );
            }

            if ((l_def_D_EN == literal_0))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_4 );
            }
            else if ((l_def_D_EN == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_5 );
            }

            if ((l_def_D_EN == literal_0))
            {
                l_scom_buffer.insert<27, 5, 59, uint64_t>(literal_5 );
            }
            else if ((l_def_D_EN == literal_1))
            {
                l_scom_buffer.insert<27, 5, 59, uint64_t>(literal_6 );
            }

            if ((l_def_D_EN == literal_0))
            {
                l_scom_buffer.insert<35, 5, 59, uint64_t>(literal_6 );
            }
            else if ((l_def_D_EN == literal_1))
            {
                l_scom_buffer.insert<35, 5, 59, uint64_t>(literal_7 );
            }

            if ((l_def_D_EN == literal_0))
            {
                l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_11 );
            }
            else if ((l_def_D_EN == literal_1))
            {
                l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_12 );
            }

            if ((l_def_D_EN == literal_0))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_12 );
            }
            else if ((l_def_D_EN == literal_1))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_13 );
            }

            if ((l_def_C10_EN == literal_0))
            {
                l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_0 );
            }
            else if (((l_def_C10_EN == literal_1) && (l_def_D_EN == literal_0)))
            {
                l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_13 );
            }
            else if (((l_def_C10_EN == literal_1) && (l_def_D_EN == literal_1)))
            {
                l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_14 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8011014ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011015ull, l_scom_buffer ));

            l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0 );

            if ((l_def_72B_DIMM == literal_1))
            {
                l_scom_buffer.insert<39, 1, 63, uint64_t>(literal_0 );
            }
            else if ((l_def_72B_DIMM == literal_0))
            {
                l_scom_buffer.insert<39, 1, 63, uint64_t>(literal_1 );
            }

            l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_10 );
            l_scom_buffer.insert<41, 2, 62, uint64_t>(literal_2 );
            l_scom_buffer.insert<40, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011015ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011016ull, l_scom_buffer ));

            l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0 );

            if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_11 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4000 == literal_1))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_13 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4800 == literal_1))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_16 );
            }

            l_scom_buffer.insert<5, 5, 59, uint64_t>(literal_3 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011016ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011017ull, l_scom_buffer ));

            if ((l_TGT1_ATTR_MEM_EFF_DDR5_RTT_PARK_RD[literal_0][literal_0] == literal_0))
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
            }
            else if ((l_TGT1_ATTR_MEM_EFF_DDR5_RTT_PARK_RD[literal_0][literal_0] != literal_0))
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0 );
            }

            if ((l_TGT1_ATTR_MEM_EFF_DDR5_RTT_PARK_WR[literal_0][literal_0] == literal_0))
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_1 );
            }
            else if ((l_TGT1_ATTR_MEM_EFF_DDR5_RTT_PARK_WR[literal_0][literal_0] != literal_0))
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8011017ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011018ull, l_scom_buffer ));

            l_scom_buffer.insert<31, 14, 50, uint64_t>(literal_0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011018ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801101aull, l_scom_buffer ));

            l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801101aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011029ull, l_scom_buffer ));

            l_scom_buffer.insert<1, 2, 62, uint64_t>(literal_3 );
            l_scom_buffer.insert<3, 2, 62, uint64_t>(literal_3 );
            l_scom_buffer.insert<40, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<39, 1, 63, uint64_t>(literal_0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011029ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011031ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 24, 40, uint64_t>(literal_0 );
            l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0 );
            l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011031ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011034ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<3, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<5, 3, 61, uint64_t>(literal_1 );
            l_scom_buffer.insert<8, 11, 53, uint64_t>(l_def_REFRESH_INTERVAL );
            l_scom_buffer.insert<50, 11, 53, uint64_t>(l_def_REFR_CHECK_INTERVAL );
            l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<30, 10, 54, uint64_t>(((l_TGT1_ATTR_MEM_EFF_DRAM_TRFC + literal_1) / literal_2) );
            l_scom_buffer.insert<40, 10, 54, uint64_t>(((l_TGT1_ATTR_MEM_EFF_DRAM_TRFC_DLR + literal_1) / literal_2) );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011034ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011035ull, l_scom_buffer ));

            l_scom_buffer.insert<17, 11, 53, uint64_t>(((l_TGT1_ATTR_MEM_EFF_DRAM_TRFC + literal_1) / literal_3) );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011035ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011036ull, l_scom_buffer ));

            l_scom_buffer.insert<22, 1, 63, uint64_t>(literal_1 );

            if ((l_TGT2_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED == ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_OFF))
            {
                l_scom_buffer.insert<23, 10, 54, uint64_t>(literal_64 );
            }
            else if ((l_TGT2_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED != ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_OFF))
            {
                l_scom_buffer.insert<23, 10, 54, uint64_t>(literal_4 );
            }

            if (((l_TGT2_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED != ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR)
                 && (l_TGT2_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED != ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP)))
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0 );
            }
            else if (((l_TGT2_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED == ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR)
                      || (l_TGT2_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED == ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP)))
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
            }

            if (((l_TGT2_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED != ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR)
                 && (l_TGT2_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED != ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP)))
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0 );
            }
            else if (((l_TGT2_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED == ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR)
                      || (l_TGT2_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED == ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP)))
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_1 );
            }

            if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<16, 5, 59, uint64_t>(literal_6 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4000 == literal_1))
            {
                l_scom_buffer.insert<16, 5, 59, uint64_t>(literal_8 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4800 == literal_1))
            {
                l_scom_buffer.insert<16, 5, 59, uint64_t>(literal_9 );
            }

            if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_6 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4000 == literal_1))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_8 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4800 == literal_1))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_9 );
            }

            if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>(literal_6 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4000 == literal_1))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>(literal_8 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4800 == literal_1))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>(literal_9 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8011036ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011037ull, l_scom_buffer ));

            l_scom_buffer.insert<46, 11, 53, uint64_t>(l_def_REFRESH_INTERVAL );
            l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<2, 10, 54, uint64_t>(literal_8 );

            if (((l_TGT2_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED != ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR)
                 && (l_TGT2_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED != ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP)))
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0 );
            }
            else if (((l_TGT2_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED == ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR)
                      || (l_TGT2_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED == ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP)))
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
            }

            if ((l_TGT2_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED != ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP))
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0 );
            }
            else if ((l_TGT2_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED == ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP))
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_1 );
            }

            l_scom_buffer.insert<57, 4, 60, uint64_t>(literal_0 );
            l_scom_buffer.insert<38, 8, 56, uint64_t>(literal_0 );

            if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<12, 5, 59, uint64_t>(literal_4 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4000 == literal_1))
            {
                l_scom_buffer.insert<12, 5, 59, uint64_t>(literal_5 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4800 == literal_1))
            {
                l_scom_buffer.insert<12, 5, 59, uint64_t>(literal_6 );
            }

            if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_5 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4000 == literal_1))
            {
                l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_6 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4800 == literal_1))
            {
                l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_7 );
            }

            if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<22, 5, 59, uint64_t>(literal_8 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4000 == literal_1))
            {
                l_scom_buffer.insert<22, 5, 59, uint64_t>(literal_10 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4800 == literal_1))
            {
                l_scom_buffer.insert<22, 5, 59, uint64_t>(literal_12 );
            }

            if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<27, 11, 53, uint64_t>(literal_512 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4000 == literal_1))
            {
                l_scom_buffer.insert<27, 11, 53, uint64_t>(literal_640 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4800 == literal_1))
            {
                l_scom_buffer.insert<27, 11, 53, uint64_t>(literal_768 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8011037ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011038ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_4 );

            if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<53, 6, 58, uint64_t>(literal_24 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4000 == literal_1))
            {
                l_scom_buffer.insert<53, 6, 58, uint64_t>(literal_30 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4800 == literal_1))
            {
                l_scom_buffer.insert<53, 6, 58, uint64_t>(literal_36 );
            }

            if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_12 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4000 == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_15 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_4800 == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_18 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8011038ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011c05ull, l_scom_buffer ));

            l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011c05ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011c08ull, l_scom_buffer ));

            if ((l_def_72B_DIMM == literal_0))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_0b11111 );
            }
            else if ((l_def_72B_DIMM == literal_1))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_0b10001 );
            }

            if ((l_def_72B_DIMM == literal_0))
            {
                l_scom_buffer.insert<5, 5, 59, uint64_t>(literal_0b11111 );
            }
            else if ((l_def_72B_DIMM == literal_1))
            {
                l_scom_buffer.insert<5, 5, 59, uint64_t>(literal_0b01111 );
            }

            if ((l_def_72B_DIMM == literal_0))
            {
                l_scom_buffer.insert<10, 5, 59, uint64_t>(literal_0b11111 );
            }
            else if ((l_def_72B_DIMM == literal_1))
            {
                l_scom_buffer.insert<10, 5, 59, uint64_t>(literal_0b10001 );
            }

            if ((l_def_72B_DIMM == literal_0))
            {
                l_scom_buffer.insert<15, 5, 59, uint64_t>(literal_0b11111 );
            }
            else if ((l_def_72B_DIMM == literal_1))
            {
                l_scom_buffer.insert<15, 5, 59, uint64_t>(literal_0b01111 );
            }

            if ((l_def_72B_DIMM == literal_0))
            {
                l_scom_buffer.insert<20, 5, 59, uint64_t>(literal_0b11111 );
            }
            else if ((l_def_72B_DIMM == literal_1))
            {
                l_scom_buffer.insert<20, 5, 59, uint64_t>(literal_0b10001 );
            }

            if ((l_def_72B_DIMM == literal_0))
            {
                l_scom_buffer.insert<25, 5, 59, uint64_t>(literal_0b11111 );
            }
            else if ((l_def_72B_DIMM == literal_1))
            {
                l_scom_buffer.insert<25, 5, 59, uint64_t>(literal_0b01111 );
            }

            if ((l_def_72B_DIMM == literal_0))
            {
                l_scom_buffer.insert<30, 5, 59, uint64_t>(literal_0b11111 );
            }
            else if ((l_def_72B_DIMM == literal_1))
            {
                l_scom_buffer.insert<30, 5, 59, uint64_t>(literal_0b10001 );
            }

            if ((l_def_72B_DIMM == literal_0))
            {
                l_scom_buffer.insert<35, 5, 59, uint64_t>(literal_0b11111 );
            }
            else if ((l_def_72B_DIMM == literal_1))
            {
                l_scom_buffer.insert<35, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8011c08ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011c0bull, l_scom_buffer ));

            l_scom_buffer.insert<16, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<36, 1, 63, uint64_t>(literal_1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011c0bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801200dull, l_scom_buffer ));

            if ((l_def_NUM_UPPER_ADDR_BITS == literal_0))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0x1 );
            }
            else if ((l_def_NUM_UPPER_ADDR_BITS == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0x2 );
            }
            else if ((l_def_NUM_UPPER_ADDR_BITS == literal_2))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0x3 );
            }
            else if ((l_def_NUM_UPPER_ADDR_BITS == literal_3))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((l_def_NUM_UPPER_ADDR_BITS == literal_4))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0x5 );
            }
            else if ((l_def_NUM_UPPER_ADDR_BITS == literal_5))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0x6 );
            }
            else if ((l_def_NUM_UPPER_ADDR_BITS == literal_6))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0x7 );
            }
            else if ((l_def_NUM_UPPER_ADDR_BITS > literal_6))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x801200dull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
