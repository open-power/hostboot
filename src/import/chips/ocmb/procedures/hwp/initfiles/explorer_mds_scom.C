/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/procedures/hwp/initfiles/explorer_mds_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
#include "explorer_mds_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_197 = 197;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_7 = 7;
constexpr uint64_t literal_24 = 24;
constexpr uint64_t literal_63 = 63;
constexpr uint64_t literal_5 = 5;
constexpr uint64_t literal_11 = 11;
constexpr uint64_t literal_6 = 6;
constexpr uint64_t literal_8 = 8;
constexpr uint64_t literal_17 = 17;
constexpr uint64_t literal_22 = 22;
constexpr uint64_t literal_35 = 35;
constexpr uint64_t literal_54 = 54;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_16 = 16;
constexpr uint64_t literal_85 = 85;
constexpr uint64_t literal_12 = 12;
constexpr uint64_t literal_14 = 14;
constexpr uint64_t literal_0b1000 = 0b1000;
constexpr uint64_t literal_511 = 511;
constexpr uint64_t literal_132 = 132;
constexpr uint64_t literal_100 = 100;
constexpr uint64_t literal_0x02 = 0x02;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_0x01 = 0x01;
constexpr uint64_t literal_0b0 = 0b0;
constexpr uint64_t literal_0x00 = 0x00;
constexpr uint64_t literal_64 = 64;
constexpr uint64_t literal_32 = 32;
constexpr uint64_t literal_0b000 = 0b000;
constexpr uint64_t literal_0b100 = 0b100;
constexpr uint64_t literal_0b010 = 0b010;
constexpr uint64_t literal_0b110 = 0b110;
constexpr uint64_t literal_0b001 = 0b001;
constexpr uint64_t literal_0b101 = 0b101;
constexpr uint64_t literal_0b011 = 0b011;
constexpr uint64_t literal_0b111 = 0b111;
constexpr uint64_t literal_3 = 3;
constexpr uint64_t literal_27 = 27;
constexpr uint64_t literal_190 = 190;
constexpr uint64_t literal_81 = 81;
constexpr uint64_t literal_734 = 734;
constexpr uint64_t literal_247 = 247;
constexpr uint64_t literal_1560 = 1560;
constexpr uint64_t literal_13 = 13;
constexpr uint64_t literal_854 = 854;
constexpr uint64_t literal_0b01111 = 0b01111;
constexpr uint64_t literal_0b10000 = 0b10000;
constexpr uint64_t literal_0b10001 = 0b10001;
constexpr uint64_t literal_0b10010 = 0b10010;
constexpr uint64_t literal_0b00000 = 0b00000;
constexpr uint64_t literal_0b00001 = 0b00001;
constexpr uint64_t literal_0b00100 = 0b00100;
constexpr uint64_t literal_0b01001 = 0b01001;
constexpr uint64_t literal_0b01010 = 0b01010;
constexpr uint64_t literal_0b01011 = 0b01011;
constexpr uint64_t literal_0b01100 = 0b01100;
constexpr uint64_t literal_0b00101 = 0b00101;
constexpr uint64_t literal_0b00110 = 0b00110;
constexpr uint64_t literal_0b00010 = 0b00010;
constexpr uint64_t literal_0b00011 = 0b00011;
constexpr uint64_t literal_0b00111 = 0b00111;
constexpr uint64_t literal_0b01000 = 0b01000;
constexpr uint64_t literal_0b01101 = 0b01101;
constexpr uint64_t literal_0b01110 = 0b01110;
constexpr uint64_t literal_0b0001 = 0b0001;

fapi2::ReturnCode explorer_mds_scom(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& TGT0,
                                    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT2,
                                    const fapi2::Target<fapi2::TARGET_TYPE_MC>& TGT3)
{
    {
        fapi2::ATTR_MEM_REORDER_QUEUE_SETTING_Type l_TGT0_ATTR_MEM_REORDER_QUEUE_SETTING;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_REORDER_QUEUE_SETTING, TGT0, l_TGT0_ATTR_MEM_REORDER_QUEUE_SETTING));
        uint64_t l_def_disable_fast_act = literal_1;
        fapi2::ATTR_MSS_MRW_DRAM_2N_MODE_Type l_TGT2_ATTR_MSS_MRW_DRAM_2N_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_DRAM_2N_MODE, TGT2, l_TGT2_ATTR_MSS_MRW_DRAM_2N_MODE));
        fapi2::ATTR_MEM_2N_MODE_Type l_TGT0_ATTR_MEM_2N_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_2N_MODE, TGT0, l_TGT0_ATTR_MEM_2N_MODE));
        fapi2::ATTR_MEM_MRW_IS_PLANAR_Type l_TGT0_ATTR_MEM_MRW_IS_PLANAR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_MRW_IS_PLANAR, TGT0, l_TGT0_ATTR_MEM_MRW_IS_PLANAR));
        fapi2::ATTR_MEM_SI_ODT_RD_Type l_TGT1_ATTR_MEM_SI_ODT_RD;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_SI_ODT_RD, TGT1, l_TGT1_ATTR_MEM_SI_ODT_RD));
        fapi2::ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_Type l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM, TGT1,
                               l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM));
        uint64_t l_def_dual_drop = ((l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0] > literal_0)
                                    && (l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_1] > literal_0));
        fapi2::ATTR_MEM_EFF_FOUR_RANK_MODE_Type l_TGT1_ATTR_MEM_EFF_FOUR_RANK_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_FOUR_RANK_MODE, TGT1, l_TGT1_ATTR_MEM_EFF_FOUR_RANK_MODE));
        uint64_t l_def_four_rank_mode = (l_TGT1_ATTR_MEM_EFF_FOUR_RANK_MODE[literal_0] == literal_1);
        uint64_t l_def_cs_tied = ((l_def_four_rank_mode == literal_0) && (l_def_dual_drop == literal_0));
        fapi2::ATTR_MEM_SI_ODT_WR_Type l_TGT1_ATTR_MEM_SI_ODT_WR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_SI_ODT_WR, TGT1, l_TGT1_ATTR_MEM_SI_ODT_WR));
        fapi2::ATTR_MSS_OCMB_CHECKSTOP_OBJ_HANDLE_Type l_TGT2_ATTR_MSS_OCMB_CHECKSTOP_OBJ_HANDLE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_CHECKSTOP_OBJ_HANDLE, TGT2, l_TGT2_ATTR_MSS_OCMB_CHECKSTOP_OBJ_HANDLE));
        fapi2::ATTR_MSS_OCMB_RECOV_OBJ_HANDLE_Type l_TGT2_ATTR_MSS_OCMB_RECOV_OBJ_HANDLE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_RECOV_OBJ_HANDLE, TGT2, l_TGT2_ATTR_MSS_OCMB_RECOV_OBJ_HANDLE));
        fapi2::ATTR_MSS_OCMB_SPECATTN_OBJ_HANDLE_Type l_TGT2_ATTR_MSS_OCMB_SPECATTN_OBJ_HANDLE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_SPECATTN_OBJ_HANDLE, TGT2, l_TGT2_ATTR_MSS_OCMB_SPECATTN_OBJ_HANDLE));
        fapi2::ATTR_MSS_OCMB_APPINTR_OBJ_HANDLE_Type l_TGT2_ATTR_MSS_OCMB_APPINTR_OBJ_HANDLE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_APPINTR_OBJ_HANDLE, TGT2, l_TGT2_ATTR_MSS_OCMB_APPINTR_OBJ_HANDLE));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801140cull, l_scom_buffer ));

            l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_197 );
            l_scom_buffer.insert<47, 5, 59, uint64_t>(literal_197 );
            l_scom_buffer.insert<42, 5, 59, uint64_t>(literal_197 );
            l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_7 );
            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_7 );
            l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_24 );
            l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_63 );
            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_63 );
            l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0 );
            l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_5 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801140cull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801140dull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_11 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_6 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_6 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_8 );
            l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_11 );
            l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_6 );
            l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_6 );
            l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_8 );
            l_scom_buffer.insert<32, 5, 59, uint64_t>(literal_17 );
            l_scom_buffer.insert<37, 5, 59, uint64_t>(literal_17 );
            l_scom_buffer.insert<42, 5, 59, uint64_t>(literal_17 );
            l_scom_buffer.insert<47, 4, 60, uint64_t>(literal_5 );
            l_scom_buffer.insert<51, 6, 58, uint64_t>(literal_22 );
            l_scom_buffer.insert<57, 6, 58, uint64_t>(literal_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801140dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801140eull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_8 );
            l_scom_buffer.insert<4, 6, 58, uint64_t>(literal_35 );
            l_scom_buffer.insert<10, 6, 58, uint64_t>(literal_54 );
            l_scom_buffer.insert<16, 5, 59, uint64_t>(literal_8 );
            l_scom_buffer.insert<33, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<21, 5, 59, uint64_t>(literal_2 );
            l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_16 );
            l_scom_buffer.insert<32, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<41, 7, 57, uint64_t>(literal_85 );
            l_scom_buffer.insert<39, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_12 );
            l_scom_buffer.insert<35, 4, 60, uint64_t>(literal_0 );
            l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_12 );
            l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_12 );
            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_14 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801140eull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801140full, l_scom_buffer ));

            l_scom_buffer.insert<5, 1, 63, uint64_t>(l_TGT0_ATTR_MEM_REORDER_QUEUE_SETTING );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0b1000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801140full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011410ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 1, 63, uint64_t>(l_TGT0_ATTR_MEM_REORDER_QUEUE_SETTING );
            l_scom_buffer.insert<12, 1, 63, uint64_t>(l_def_disable_fast_act );
            l_scom_buffer.insert<57, 4, 60, uint64_t>(literal_0b1000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011410ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011411ull, l_scom_buffer ));

            l_scom_buffer.insert<1, 2, 62, uint64_t>(literal_2 );
            l_scom_buffer.insert<3, 9, 55, uint64_t>(literal_511 );
            l_scom_buffer.insert<13, 8, 56, uint64_t>(literal_132 );
            l_scom_buffer.insert<21, 2, 62, uint64_t>(literal_0 );
            l_scom_buffer.insert<33, 2, 62, uint64_t>(literal_2 );
            l_scom_buffer.insert<35, 9, 55, uint64_t>(literal_8 );
            l_scom_buffer.insert<44, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<55, 9, 55, uint64_t>(literal_100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011411ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011415ull, l_scom_buffer ));

            l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0 );

            if ((l_TGT2_ATTR_MSS_MRW_DRAM_2N_MODE == literal_0x02))
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b1 );
            }
            else if ((l_TGT2_ATTR_MSS_MRW_DRAM_2N_MODE == literal_0x01))
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b0 );
            }
            else if (((l_TGT2_ATTR_MSS_MRW_DRAM_2N_MODE == literal_0x00) && (l_TGT0_ATTR_MEM_2N_MODE == literal_0x02)))
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (((l_TGT2_ATTR_MSS_MRW_DRAM_2N_MODE == literal_0x00) && (l_TGT0_ATTR_MEM_2N_MODE == literal_0x01)))
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b0 );
            }

            l_scom_buffer.insert<19, 1, 63, uint64_t>(l_TGT0_ATTR_MEM_MRW_IS_PLANAR );
            l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_8 );
            l_scom_buffer.insert<24, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<31, 7, 57, uint64_t>(literal_32 );
            l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_16 );
            l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011415ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011416ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<3, 3, 61, uint64_t>(literal_0b100 );
            l_scom_buffer.insert<6, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<9, 3, 61, uint64_t>(literal_0b110 );
            l_scom_buffer.insert<12, 3, 61, uint64_t>(literal_0b001 );
            l_scom_buffer.insert<15, 3, 61, uint64_t>(literal_0b101 );
            l_scom_buffer.insert<18, 3, 61, uint64_t>(literal_0b011 );
            l_scom_buffer.insert<21, 3, 61, uint64_t>(literal_0b111 );
            l_scom_buffer.insert<24, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<27, 3, 61, uint64_t>(literal_0b100 );
            l_scom_buffer.insert<30, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<33, 3, 61, uint64_t>(literal_0b110 );
            l_scom_buffer.insert<36, 3, 61, uint64_t>(literal_0b001 );
            l_scom_buffer.insert<39, 3, 61, uint64_t>(literal_0b101 );
            l_scom_buffer.insert<42, 3, 61, uint64_t>(literal_0b011 );
            l_scom_buffer.insert<45, 3, 61, uint64_t>(literal_0b111 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011416ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011417ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_0] >> literal_7) );
            l_scom_buffer.insert<1, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_0] >> literal_6) );
            l_scom_buffer.insert<2, 1, 63, uint64_t>(((((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_0] >> literal_3) &
                    literal_0b1) && (l_def_cs_tied == literal_0))
                    || (((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_0] >> literal_7) & literal_0b1) && (l_def_cs_tied == literal_1))) );
            l_scom_buffer.insert<3, 1, 63, uint64_t>(((((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_0] >> literal_2) &
                    literal_0b1) && (l_def_cs_tied == literal_0))
                    || (((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_0] >> literal_6) & literal_0b1) && (l_def_cs_tied == literal_1))) );
            l_scom_buffer.insert<4, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_1] >> literal_7) );
            l_scom_buffer.insert<5, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_1] >> literal_6) );
            l_scom_buffer.insert<6, 1, 63, uint64_t>(((((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_1] >> literal_3) &
                    literal_0b1) && (l_def_cs_tied == literal_0))
                    || (((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_1] >> literal_7) & literal_0b1) && (l_def_cs_tied == literal_1))) );
            l_scom_buffer.insert<7, 1, 63, uint64_t>(((((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_1] >> literal_2) &
                    literal_0b1) && (l_def_cs_tied == literal_0))
                    || (((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_1] >> literal_6) & literal_0b1) && (l_def_cs_tied == literal_1))) );
            l_scom_buffer.insert<8, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_2] >> literal_7) );
            l_scom_buffer.insert<9, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_2] >> literal_6) );
            l_scom_buffer.insert<10, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_2] >> literal_3) );
            l_scom_buffer.insert<11, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_2] >> literal_2) );
            l_scom_buffer.insert<12, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_3] >> literal_7) );
            l_scom_buffer.insert<13, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_3] >> literal_6) );
            l_scom_buffer.insert<14, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_3] >> literal_3) );
            l_scom_buffer.insert<15, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_3] >> literal_2) );
            l_scom_buffer.insert<16, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_0] >> literal_7) );
            l_scom_buffer.insert<17, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_0] >> literal_6) );
            l_scom_buffer.insert<18, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_0] >> literal_3) );
            l_scom_buffer.insert<19, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_0] >> literal_2) );
            l_scom_buffer.insert<20, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_1] >> literal_7) );
            l_scom_buffer.insert<21, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_1] >> literal_6) );
            l_scom_buffer.insert<22, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_1] >> literal_3) );
            l_scom_buffer.insert<23, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_1] >> literal_2) );
            l_scom_buffer.insert<24, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_2] >> literal_7) );
            l_scom_buffer.insert<25, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_2] >> literal_6) );
            l_scom_buffer.insert<26, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_2] >> literal_3) );
            l_scom_buffer.insert<27, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_2] >> literal_2) );
            l_scom_buffer.insert<28, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_3] >> literal_7) );
            l_scom_buffer.insert<29, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_3] >> literal_6) );
            l_scom_buffer.insert<30, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_3] >> literal_3) );
            l_scom_buffer.insert<31, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_3] >> literal_2) );
            l_scom_buffer.insert<32, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_0] >> literal_7) );
            l_scom_buffer.insert<33, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_0] >> literal_6) );
            l_scom_buffer.insert<34, 1, 63, uint64_t>(((((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_0] >> literal_3) &
                    literal_0b1) && (l_def_cs_tied == literal_0))
                    || (((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_0] >> literal_7) & literal_0b1) && (l_def_cs_tied == literal_1))) );
            l_scom_buffer.insert<35, 1, 63, uint64_t>(((((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_0] >> literal_2) &
                    literal_0b1) && (l_def_cs_tied == literal_0))
                    || (((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_0] >> literal_6) & literal_0b1) && (l_def_cs_tied == literal_1))) );
            l_scom_buffer.insert<36, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_1] >> literal_7) );
            l_scom_buffer.insert<37, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_1] >> literal_6) );
            l_scom_buffer.insert<38, 1, 63, uint64_t>(((((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_1] >> literal_3) &
                    literal_0b1) && (l_def_cs_tied == literal_0))
                    || (((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_1] >> literal_7) & literal_0b1) && (l_def_cs_tied == literal_1))) );
            l_scom_buffer.insert<39, 1, 63, uint64_t>(((((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_1] >> literal_2) &
                    literal_0b1) && (l_def_cs_tied == literal_0))
                    || (((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_1] >> literal_6) & literal_0b1) && (l_def_cs_tied == literal_1))) );
            l_scom_buffer.insert<40, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_2] >> literal_7) );
            l_scom_buffer.insert<41, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_2] >> literal_6) );
            l_scom_buffer.insert<42, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_2] >> literal_3) );
            l_scom_buffer.insert<43, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_2] >> literal_2) );
            l_scom_buffer.insert<44, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_3] >> literal_7) );
            l_scom_buffer.insert<45, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_3] >> literal_6) );
            l_scom_buffer.insert<46, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_3] >> literal_3) );
            l_scom_buffer.insert<47, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_3] >> literal_2) );
            l_scom_buffer.insert<48, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_0] >> literal_7) );
            l_scom_buffer.insert<49, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_0] >> literal_6) );
            l_scom_buffer.insert<50, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_0] >> literal_3) );
            l_scom_buffer.insert<51, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_0] >> literal_2) );
            l_scom_buffer.insert<52, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_1] >> literal_7) );
            l_scom_buffer.insert<53, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_1] >> literal_6) );
            l_scom_buffer.insert<54, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_1] >> literal_3) );
            l_scom_buffer.insert<55, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_1] >> literal_2) );
            l_scom_buffer.insert<56, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_2] >> literal_7) );
            l_scom_buffer.insert<57, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_2] >> literal_6) );
            l_scom_buffer.insert<58, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_2] >> literal_3) );
            l_scom_buffer.insert<59, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_2] >> literal_2) );
            l_scom_buffer.insert<60, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_3] >> literal_7) );
            l_scom_buffer.insert<61, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_3] >> literal_6) );
            l_scom_buffer.insert<62, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_3] >> literal_3) );
            l_scom_buffer.insert<63, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_3] >> literal_2) );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011417ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801141aull, l_scom_buffer ));

            l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801141aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011431ull, l_scom_buffer ));

            l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_27 );
            l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_190 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011431ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011434ull, l_scom_buffer ));

            l_scom_buffer.insert<8, 11, 53, uint64_t>(literal_81 );
            l_scom_buffer.insert<30, 10, 54, uint64_t>(literal_734 );
            l_scom_buffer.insert<40, 10, 54, uint64_t>(literal_247 );
            l_scom_buffer.insert<5, 3, 61, uint64_t>(literal_1 );
            l_scom_buffer.insert<50, 11, 53, uint64_t>(literal_1560 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011434ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011436ull, l_scom_buffer ));

            l_scom_buffer.insert<16, 5, 59, uint64_t>(literal_7 );
            l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_7 );
            l_scom_buffer.insert<6, 5, 59, uint64_t>(literal_8 );
            l_scom_buffer.insert<21, 1, 63, uint64_t>(literal_0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011436ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011437ull, l_scom_buffer ));

            l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_13 );
            l_scom_buffer.insert<22, 5, 59, uint64_t>(literal_13 );
            l_scom_buffer.insert<12, 5, 59, uint64_t>(literal_8 );
            l_scom_buffer.insert<27, 11, 53, uint64_t>(literal_854 );
            l_scom_buffer.insert<46, 11, 53, uint64_t>(literal_81 );
            l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011437ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801186full, l_scom_buffer ));

            l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0b01111 );
            l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<49, 5, 59, uint64_t>(literal_0b10001 );
            l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<10, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<11, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<25, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<26, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<27, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<13, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<29, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<14, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<30, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<15, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<31, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<16, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<21, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<22, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b10010 );
            l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b00000 );
            l_scom_buffer.insert<33, 5, 59, uint64_t>(literal_0b00000 );
            l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801186full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011870ull, l_scom_buffer ));

            l_scom_buffer.insert<30, 5, 59, uint64_t>(literal_0b00001 );
            l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_0b00100 );
            l_scom_buffer.insert<35, 5, 59, uint64_t>(literal_0b01001 );
            l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b01010 );
            l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_0b01011 );
            l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0b01100 );
            l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0b00101 );
            l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0b00110 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011870ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011871ull, l_scom_buffer ));

            l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_0b00010 );
            l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b00011 );
            l_scom_buffer.insert<27, 5, 59, uint64_t>(literal_0b00111 );
            l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_0b01000 );
            l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0b01101 );
            l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0b01110 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011871ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801240dull, l_scom_buffer ));

            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0001 );
            l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0001 );
            l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0b0001 );
            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0001 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801240dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8012410ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(l_TGT2_ATTR_MSS_OCMB_CHECKSTOP_OBJ_HANDLE );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8012410ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8012411ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(l_TGT2_ATTR_MSS_OCMB_RECOV_OBJ_HANDLE );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8012411ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8012412ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(l_TGT2_ATTR_MSS_OCMB_SPECATTN_OBJ_HANDLE );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8012412ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8012413ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(l_TGT2_ATTR_MSS_OCMB_APPINTR_OBJ_HANDLE );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8012413ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
