/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_fbc_ioo_dl_scom.C $ */
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
#include "p9_fbc_ioo_dl_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0x0F = 0x0F;
constexpr uint64_t literal_0xF = 0xF;
constexpr uint64_t literal_0x0 = 0x0;
constexpr uint64_t literal_0xE = 0xE;
constexpr uint64_t literal_0x5 = 0x5;
constexpr uint64_t literal_0b0001111 = 0b0001111;
constexpr uint64_t literal_0b0111111 = 0b0111111;
constexpr uint64_t literal_0b111 = 0b111;
constexpr uint64_t literal_0x6 = 0x6;
constexpr uint64_t literal_0x7 = 0x7;

fapi2::ReturnCode p9_fbc_ioo_dl_scom(const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& TGT0,
                                     const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT1, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT1, l_chip_ec));
        fapi2::ATTR_LINK_TRAIN_Type l_TGT0_ATTR_LINK_TRAIN;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_LINK_TRAIN, TGT0, l_TGT0_ATTR_LINK_TRAIN));
        fapi2::ATTR_PROC_NPU_REGION_ENABLED_Type l_TGT1_ATTR_PROC_NPU_REGION_ENABLED;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NPU_REGION_ENABLED, TGT1, l_TGT1_ATTR_PROC_NPU_REGION_ENABLED));
        fapi2::ATTR_OPTICS_CONFIG_MODE_Type l_TGT0_ATTR_OPTICS_CONFIG_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OPTICS_CONFIG_MODE, TGT0, l_TGT0_ATTR_OPTICS_CONFIG_MODE));
        uint64_t l_def_OBUS_NV_ENABLED = ((l_TGT0_ATTR_OPTICS_CONFIG_MODE == fapi2::ENUM_ATTR_OPTICS_CONFIG_MODE_NV)
                                          && l_TGT1_ATTR_PROC_NPU_REGION_ENABLED);
        fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE_Type l_TGT0_ATTR_PROC_FABRIC_LINK_ACTIVE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE, TGT0, l_TGT0_ATTR_PROC_FABRIC_LINK_ACTIVE));
        uint64_t l_def_OBUS_FBC_ENABLED = ((l_TGT0_ATTR_OPTICS_CONFIG_MODE == fapi2::ENUM_ATTR_OPTICS_CONFIG_MODE_SMP)
                                           && l_TGT0_ATTR_PROC_FABRIC_LINK_ACTIVE);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x901080aull, l_scom_buffer ));

            if ((l_TGT0_ATTR_LINK_TRAIN == fapi2::ENUM_ATTR_LINK_TRAIN_BOTH))
            {
                constexpr auto l_PB_IOO_LL0_CONFIG_LINK_PAIR_ON = 0x1;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_LINK_PAIR_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOO_LL0_CONFIG_LINK_PAIR_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_LINK_PAIR_OFF );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0x0F );
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x5) && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6)
                             && (l_chip_ec == 0x11)) )
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0x0F );
            }

            l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0xF );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                l_scom_buffer.insert<32, 4, 60, uint64_t>(literal_0x0 );
            }

            constexpr auto l_PB_IOO_LL0_CONFIG_CRC_LANE_ID_ON = 0x1;
            l_scom_buffer.insert<2, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_CRC_LANE_ID_ON );
            constexpr auto l_PB_IOO_LL0_CONFIG_SL_UE_CRC_ERR_ON = 0x1;
            l_scom_buffer.insert<4, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_SL_UE_CRC_ERR_ON );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0xF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x901080aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x901080cull, l_scom_buffer ));

            if (l_def_OBUS_NV_ENABLED)
            {
                constexpr auto l_PB_IOO_LL0_CONFIG_NV0_NPU_ENABLED_ON = 0x1;
                l_scom_buffer.insert<61, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_NV0_NPU_ENABLED_ON );
                constexpr auto l_PB_IOO_LL0_CONFIG_NV1_NPU_ENABLED_ON = 0x1;
                l_scom_buffer.insert<62, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_NV1_NPU_ENABLED_ON );
                constexpr auto l_PB_IOO_LL0_CONFIG_NV2_NPU_ENABLED_ON = 0x1;
                l_scom_buffer.insert<63, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_NV2_NPU_ENABLED_ON );
            }

            if ((l_def_OBUS_FBC_ENABLED && (l_TGT0_ATTR_LINK_TRAIN != fapi2::ENUM_ATTR_LINK_TRAIN_ODD_ONLY)))
            {
                constexpr auto l_PB_IOO_LL0_CONFIG_LINK0_OLL_ENABLED_ON = 0x1;
                l_scom_buffer.insert<58, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_LINK0_OLL_ENABLED_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOO_LL0_CONFIG_LINK0_OLL_ENABLED_OFF = 0x0;
                l_scom_buffer.insert<58, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_LINK0_OLL_ENABLED_OFF );
            }

            if ((l_def_OBUS_FBC_ENABLED && (l_TGT0_ATTR_LINK_TRAIN != fapi2::ENUM_ATTR_LINK_TRAIN_EVEN_ONLY)))
            {
                constexpr auto l_PB_IOO_LL0_CONFIG_LINK1_OLL_ENABLED_ON = 0x1;
                l_scom_buffer.insert<59, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_LINK1_OLL_ENABLED_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOO_LL0_CONFIG_LINK1_OLL_ENABLED_OFF = 0x0;
                l_scom_buffer.insert<59, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_LINK1_OLL_ENABLED_OFF );
            }

            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0xE );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xE );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0x0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x901080cull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x901080full, l_scom_buffer ));

            if (l_def_OBUS_NV_ENABLED)
            {
                constexpr auto l_PB_IOO_LL0_CONFIG_NV0_NPU_ENABLED_ON = 0x1;
                l_scom_buffer.insert<61, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_NV0_NPU_ENABLED_ON );
                constexpr auto l_PB_IOO_LL0_CONFIG_NV1_NPU_ENABLED_ON = 0x1;
                l_scom_buffer.insert<62, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_NV1_NPU_ENABLED_ON );
                constexpr auto l_PB_IOO_LL0_CONFIG_NV2_NPU_ENABLED_ON = 0x1;
                l_scom_buffer.insert<63, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_NV2_NPU_ENABLED_ON );
            }

            if ((l_def_OBUS_FBC_ENABLED && (l_TGT0_ATTR_LINK_TRAIN != fapi2::ENUM_ATTR_LINK_TRAIN_ODD_ONLY)))
            {
                constexpr auto l_PB_IOO_LL0_CONFIG_LINK0_OLL_ENABLED_ON = 0x1;
                l_scom_buffer.insert<58, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_LINK0_OLL_ENABLED_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOO_LL0_CONFIG_LINK0_OLL_ENABLED_OFF = 0x0;
                l_scom_buffer.insert<58, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_LINK0_OLL_ENABLED_OFF );
            }

            if ((l_def_OBUS_FBC_ENABLED && (l_TGT0_ATTR_LINK_TRAIN != fapi2::ENUM_ATTR_LINK_TRAIN_EVEN_ONLY)))
            {
                constexpr auto l_PB_IOO_LL0_CONFIG_LINK1_OLL_ENABLED_ON = 0x1;
                l_scom_buffer.insert<59, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_LINK1_OLL_ENABLED_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOO_LL0_CONFIG_LINK1_OLL_ENABLED_OFF = 0x0;
                l_scom_buffer.insert<59, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_LINK1_OLL_ENABLED_OFF );
            }

            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0x5 );
            l_scom_buffer.insert<9, 7, 57, uint64_t>(literal_0b0001111 );
            constexpr auto l_PB_IOO_LL0_CONFIG_ELEVEN_LANE_MODE_ON = 0x1;
            l_scom_buffer.insert<37, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_ELEVEN_LANE_MODE_ON );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                constexpr auto l_PB_IOO_LL0_CONFIG_FAST_ASYNC_CROSS_ON = 0x1;
                l_scom_buffer.insert<59, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_FAST_ASYNC_CROSS_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                constexpr auto l_PB_IOO_LL0_CONFIG_LINK_FAIL_CRC_ERROR_ON = 0x1;
                l_scom_buffer.insert<3, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_LINK_FAIL_CRC_ERROR_ON );
            }

            l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_0x5 );
            l_scom_buffer.insert<25, 7, 57, uint64_t>(literal_0b0111111 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                constexpr auto l_PB_IOO_LL0_CONFIG_LINK_FAIL_NO_SPARE_ON = 0x1;
                l_scom_buffer.insert<2, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_LINK_FAIL_NO_SPARE_ON );
            }

            constexpr auto l_PB_IOO_LL0_CONFIG_REPLAY_BUFFER_SIZE_REPLAY_255 = 0x2;
            l_scom_buffer.insert<56, 2, 62, uint64_t>(l_PB_IOO_LL0_CONFIG_REPLAY_BUFFER_SIZE_REPLAY_255 );
            constexpr auto l_PB_IOO_LL0_LINK1_ELEVEN_LANE_SHIFT_ON = 0x1;
            l_scom_buffer.insert<39, 1, 63, uint64_t>(l_PB_IOO_LL0_LINK1_ELEVEN_LANE_SHIFT_ON );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                constexpr auto l_PB_IOO_LL0_LINK1_RX_LANE_SWAP_ON = 0x1;
                l_scom_buffer.insert<42, 1, 63, uint64_t>(l_PB_IOO_LL0_LINK1_RX_LANE_SWAP_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                constexpr auto l_PB_IOO_LL0_LINK1_TX_LANE_SWAP_ON = 0x1;
                l_scom_buffer.insert<43, 1, 63, uint64_t>(l_PB_IOO_LL0_LINK1_TX_LANE_SWAP_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x901080full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x9010818ull, l_scom_buffer ));

            l_scom_buffer.insert<8, 3, 61, uint64_t>(literal_0b111 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0xF );
            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0x6 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x9010818ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x9010819ull, l_scom_buffer ));

            l_scom_buffer.insert<8, 2, 62, uint64_t>(literal_0b111 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0xF );
            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0x7 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x9010819ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x901081aull, l_scom_buffer ));

            l_scom_buffer.insert<8, 9, 55, uint64_t>(literal_0b111 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0xF );
            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0x7 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x901081aull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
