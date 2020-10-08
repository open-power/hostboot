/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_fbc_dlp_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#include "p10_fbc_dlp_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0x0F = 0x0F;
constexpr uint64_t literal_0xF = 0xF;
constexpr uint64_t literal_0x0 = 0x0;
constexpr uint64_t literal_0x001A = 0x001A;
constexpr uint64_t literal_0x5 = 0x5;
constexpr uint64_t literal_0b0001111 = 0b0001111;
constexpr uint64_t literal_0b1111111 = 0b1111111;
constexpr uint64_t literal_0b111 = 0b111;
constexpr uint64_t literal_0x6 = 0x6;
constexpr uint64_t literal_0x7 = 0x7;

fapi2::ReturnCode p10_fbc_dlp_scom(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& TGT0,
                                   const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT2)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT1, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT1, l_chip_ec));
        fapi2::ATTR_IOHS_LINK_TRAIN_Type l_TGT0_ATTR_IOHS_LINK_TRAIN;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, TGT0, l_TGT0_ATTR_IOHS_LINK_TRAIN));
        fapi2::ATTR_IOHS_CONFIG_MODE_Type l_TGT0_ATTR_IOHS_CONFIG_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_CONFIG_MODE, TGT0, l_TGT0_ATTR_IOHS_CONFIG_MODE));
        uint64_t l_def_FBC_ENABLED = ((l_TGT0_ATTR_IOHS_CONFIG_MODE == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX)
                                      || (l_TGT0_ATTR_IOHS_CONFIG_MODE == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA));
        uint64_t l_def_FBC_ODD_ENABLED = (l_def_FBC_ENABLED
                                          && ((l_TGT0_ATTR_IOHS_LINK_TRAIN == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH)
                                              || (l_TGT0_ATTR_IOHS_LINK_TRAIN == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_ODD_ONLY)));
        uint64_t l_def_FBC_EVN_ENABLED = (l_def_FBC_ENABLED
                                          && ((l_TGT0_ATTR_IOHS_LINK_TRAIN == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH)
                                              || (l_TGT0_ATTR_IOHS_LINK_TRAIN == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY)));
        fapi2::ATTR_LINK_SPEED_Type l_TGT0_ATTR_LINK_SPEED;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_LINK_SPEED, TGT0, l_TGT0_ATTR_LINK_SPEED));
        uint64_t l_def_50G_MODE = (l_TGT0_ATTR_LINK_SPEED == fapi2::ENUM_ATTR_LINK_SPEED_50G);
        fapi2::ATTR_IS_SIMULATION_Type l_TGT2_ATTR_IS_SIMULATION;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, TGT2, l_TGT2_ATTR_IS_SIMULATION));
        uint64_t l_def_IS_SIM = (l_TGT2_ATTR_IS_SIMULATION == literal_1);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x1801100aull, l_scom_buffer ));

            if ((l_def_FBC_EVN_ENABLED && l_def_FBC_ODD_ENABLED))
            {
                constexpr auto l_DLP0_DLP_CONFIG_LINK_PAIR_ON = 0x1;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_DLP0_DLP_CONFIG_LINK_PAIR_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_DLP0_DLP_CONFIG_LINK_PAIR_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_DLP0_DLP_CONFIG_LINK_PAIR_OFF );
            }

            l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0x0F );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0xF );
            constexpr auto l_DLP0_DLP_CONFIG_SL_UE_CRC_ERR_ON = 0x1;
            l_scom_buffer.insert<4, 1, 63, uint64_t>(l_DLP0_DLP_CONFIG_SL_UE_CRC_ERR_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x1801100aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x1801100cull, l_scom_buffer ));

            if (l_def_50G_MODE)
            {
                constexpr auto l_DLP0_DLP_CONFIG_50G_MODE_ON = 0x1;
                l_scom_buffer.insert<61, 1, 63, uint64_t>(l_DLP0_DLP_CONFIG_50G_MODE_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_DLP0_DLP_CONFIG_50G_MODE_OFF = 0x0;
                l_scom_buffer.insert<61, 1, 63, uint64_t>(l_DLP0_DLP_CONFIG_50G_MODE_OFF );
            }

            if (l_def_FBC_ENABLED)
            {
                constexpr auto l_DLP0_DLP_CONFIG_DL_SELECT_DLP = 0x1;
                l_scom_buffer.insert<62, 2, 62, uint64_t>(l_DLP0_DLP_CONFIG_DL_SELECT_DLP );
            }

            constexpr auto l_DLP0_DLP_CONFIG_PHY_TRAIN_A_ADJ_USE4 = 0x2;
            l_scom_buffer.insert<0, 2, 62, uint64_t>(l_DLP0_DLP_CONFIG_PHY_TRAIN_A_ADJ_USE4 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0x0 );
            constexpr auto l_DLP0_DLP_CONFIG_PHY_TRAIN_B_ADJ_USE12 = 0x2;
            l_scom_buffer.insert<2, 2, 62, uint64_t>(l_DLP0_DLP_CONFIG_PHY_TRAIN_B_ADJ_USE12 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0x0 );

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0xF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x1801100cull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x1801100dull, l_scom_buffer ));

            l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x001A );
            FAPI_TRY(fapi2::putScom(TGT0, 0x1801100dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x1801100full, l_scom_buffer ));

            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0x5 );
            l_scom_buffer.insert<9, 7, 57, uint64_t>(literal_0b0001111 );
            constexpr auto l_DLP0_DLP_CONFIG_FAST_ASYNC_CROSS_ON = 0x1;
            l_scom_buffer.insert<59, 1, 63, uint64_t>(l_DLP0_DLP_CONFIG_FAST_ASYNC_CROSS_ON );
            constexpr auto l_DLP0_DLP_CONFIG_LINK_FAIL_CRC_ERROR_ON = 0x1;
            l_scom_buffer.insert<3, 1, 63, uint64_t>(l_DLP0_DLP_CONFIG_LINK_FAIL_CRC_ERROR_ON );
            l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_0x5 );
            l_scom_buffer.insert<25, 7, 57, uint64_t>(literal_0b1111111 );
            constexpr auto l_DLP0_DLP_CONFIG_LINK_FAIL_NO_SPARE_ON = 0x1;
            l_scom_buffer.insert<2, 1, 63, uint64_t>(l_DLP0_DLP_CONFIG_LINK_FAIL_NO_SPARE_ON );
            constexpr auto l_DLP0_DLP_FULL_18_TX_LANE_SWAP_OFF = 0x0;
            l_scom_buffer.insert<39, 1, 63, uint64_t>(l_DLP0_DLP_FULL_18_TX_LANE_SWAP_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x1801100full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x18011018ull, l_scom_buffer ));

            l_scom_buffer.insert<8, 3, 61, uint64_t>(literal_0b111 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0xF );
            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0x6 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x18011018ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x18011019ull, l_scom_buffer ));

            l_scom_buffer.insert<8, 2, 62, uint64_t>(literal_0b111 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0xF );
            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0x7 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x18011019ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x1801101aull, l_scom_buffer ));

            l_scom_buffer.insert<8, 9, 55, uint64_t>(literal_0b111 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0xF );
            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0x7 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x1801101aull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
