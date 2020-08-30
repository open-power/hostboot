/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_int_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#include "p10_int_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0b00 = 0b00;
constexpr uint64_t literal_0xF0 = 0xF0;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_0xFF = 0xFF;
constexpr uint64_t literal_8 = 8;
constexpr uint64_t literal_0x10 = 0x10;
constexpr uint64_t literal_0x20 = 0x20;
constexpr uint64_t literal_0x40 = 0x40;
constexpr uint64_t literal_0x80 = 0x80;
constexpr uint64_t literal_0x30 = 0x30;
constexpr uint64_t literal_0x50 = 0x50;
constexpr uint64_t literal_0x60 = 0x60;
constexpr uint64_t literal_0x90 = 0x90;
constexpr uint64_t literal_0xA0 = 0xA0;
constexpr uint64_t literal_0xC0 = 0xC0;
constexpr uint64_t literal_0x70 = 0x70;
constexpr uint64_t literal_0xB0 = 0xB0;
constexpr uint64_t literal_0xD0 = 0xD0;
constexpr uint64_t literal_0xE0 = 0xE0;
constexpr uint64_t literal_12 = 12;
constexpr uint64_t literal_15 = 15;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_0x775643213F3F00 = 0x775643213F3F00;
constexpr uint64_t literal_0x77564321000000 = 0x77564321000000;
constexpr uint64_t literal_0x0101010101010128 = 0x0101010101010128;
constexpr uint64_t literal_0x3F7F7F7F1CFFFFFF = 0x3F7F7F7F1CFFFFFF;
constexpr uint64_t literal_0b11 = 0b11;
constexpr uint64_t literal_0b10 = 0b10;
constexpr uint64_t literal_0b01 = 0b01;
constexpr uint64_t literal_0b110 = 0b110;
constexpr uint64_t literal_0b101 = 0b101;
constexpr uint64_t literal_0b100 = 0b100;
constexpr uint64_t literal_0b010 = 0b010;
constexpr uint64_t literal_0b011 = 0b011;
constexpr uint64_t literal_0b001 = 0b001;
constexpr uint64_t literal_0b100000 = 0b100000;
constexpr uint64_t literal_0b0 = 0b0;

fapi2::ReturnCode p10_int_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                               const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE));
        fapi2::ATTR_PROC_FABRIC_PRESENT_GROUPS_Type l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PRESENT_GROUPS, TGT1, l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS));
        uint64_t l_def_DENALI_1DRAWER = ((((l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS == literal_0x80)
                                           || (l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS == literal_0x40))
                                          || (l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS == literal_0x20))
                                         || (l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS == literal_0x10));
        uint64_t l_def_DENALI_2DRAWER = ((((((l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS == literal_0xC0)
                                             || (l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS == literal_0xA0))
                                            || (l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS == literal_0x90))
                                           || (l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS == literal_0x60))
                                          || (l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS == literal_0x50))
                                         || (l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS == literal_0x30));
        uint64_t l_def_DENALI_3DRAWER = ((((l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS == literal_0xE0)
                                           || (l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS == literal_0xD0))
                                          || (l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS == literal_0xB0))
                                         || (l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS == literal_0x70));
        uint64_t l_def_DENALI_4DRAWER = (l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS == literal_0xF0);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010803ull, l_scom_buffer ));

            l_scom_buffer.insert<14, 2, 62, uint64_t>(literal_0b00 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2010803ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010814ull, l_scom_buffer ));

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                constexpr auto l_INT_INT_CQ_INT_CQ_CFG_PB_GEN_PUMP_MODE_CHIP_IS_GROUP__EACH_CHIP_HAS_ITS_OWN_GROUP_ID_ = 0x1;
                l_scom_buffer.insert<0, 1, 63, uint64_t>
                (l_INT_INT_CQ_INT_CQ_CFG_PB_GEN_PUMP_MODE_CHIP_IS_GROUP__EACH_CHIP_HAS_ITS_OWN_GROUP_ID_ );
            }
            else if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                constexpr auto l_INT_INT_CQ_INT_CQ_CFG_PB_GEN_PUMP_MODE_CHIP_IS_NODE = 0x0;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_INT_INT_CQ_INT_CQ_CFG_PB_GEN_PUMP_MODE_CHIP_IS_NODE );
            }

            if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                 && (l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS <= literal_0xF0)))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_4 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_TGT1_ATTR_PROC_FABRIC_PRESENT_GROUPS <= literal_0xFF)))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_8 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_2HOP_CHIP_IS_NODE)
                      && l_def_DENALI_1DRAWER))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_4 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_2HOP_CHIP_IS_NODE)
                      && l_def_DENALI_2DRAWER))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_8 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_2HOP_CHIP_IS_NODE)
                      && l_def_DENALI_3DRAWER))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_12 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_2HOP_CHIP_IS_NODE)
                      && l_def_DENALI_4DRAWER))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_15 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2010814ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010816ull, l_scom_buffer ));

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_1 );
            }
            else if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0 );
            }

            l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0b1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2010816ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x201091full, l_scom_buffer ));

            l_scom_buffer.insert<0, 56, 0, uint64_t>(literal_0x775643213F3F00 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x201091full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010921ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 56, 0, uint64_t>(literal_0x77564321000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2010921ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010925ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0101010101010128 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2010925ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010988ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0b1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2010988ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010989ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x3F7F7F7F1CFFFFFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2010989ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010a1dull, l_scom_buffer ));

            l_scom_buffer.insert<8, 2, 62, uint64_t>(literal_0b11 );
            l_scom_buffer.insert<10, 2, 62, uint64_t>(literal_0b10 );
            l_scom_buffer.insert<12, 2, 62, uint64_t>(literal_0b01 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2010a1dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010a1full, l_scom_buffer ));

            l_scom_buffer.insert<5, 3, 61, uint64_t>(literal_0b110 );
            l_scom_buffer.insert<9, 3, 61, uint64_t>(literal_0b101 );
            l_scom_buffer.insert<13, 3, 61, uint64_t>(literal_0b100 );
            l_scom_buffer.insert<17, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<21, 3, 61, uint64_t>(literal_0b011 );
            l_scom_buffer.insert<25, 3, 61, uint64_t>(literal_0b001 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2010a1full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010a88ull, l_scom_buffer ));

            l_scom_buffer.insert<34, 6, 58, uint64_t>(literal_0b100000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2010a88ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010a8aull, l_scom_buffer ));

            l_scom_buffer.insert<16, 1, 63, uint64_t>(literal_0b0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2010a8aull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
