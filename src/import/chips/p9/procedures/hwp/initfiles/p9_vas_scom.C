/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_vas_scom.C $  */
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
#include "p9_vas_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0x00200102000D7FFF = 0x00200102000D7FFF;
constexpr uint64_t literal_0x0000000000000000 = 0x0000000000000000;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0x00DD0201C0000000 = 0x00DD0201C0000000;
constexpr uint64_t literal_0x00DF0201C0000000 = 0x00DF0201C0000000;
constexpr uint64_t literal_0x0080000000000000 = 0x0080000000000000;
constexpr uint64_t literal_0x1 = 0x1;
constexpr uint64_t literal_0xFC = 0xFC;

fapi2::ReturnCode p9_vas_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_CHIP_EC_FEATURE_HW414700_Type l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW414700, TGT0, l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700));
        fapi2::ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID_Type l_TGT1_ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID, TGT1, l_TGT1_ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID));
        fapi2::ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID_Type l_TGT1_ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID, TGT1, l_TGT1_ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID));
        fapi2::ATTR_PROC_FABRIC_PUMP_MODE_Type l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PUMP_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011803ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 54, 0, uint64_t>(literal_0x00200102000D7FFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011803ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011806ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 54, 0, uint64_t>(literal_0x0000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011806ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011807ull, l_scom_buffer ));

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 != literal_0))
            {
                l_scom_buffer.insert<0, 54, 0, uint64_t>(literal_0x00DD0201C0000000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<0, 54, 0, uint64_t>(literal_0x00DF0201C0000000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3011807ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x301180aull, l_scom_buffer ));

                l_scom_buffer.insert<8, 31, 8, uint64_t>(literal_0x0080000000000000 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x301180aull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x301180bull, l_scom_buffer ));

                l_scom_buffer.insert<8, 28, 8, uint64_t>(literal_0x0080000000000000 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x301180bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x301180eull, l_scom_buffer ));

                l_scom_buffer.insert<8, 44, 8, uint64_t>(literal_0x0080000000000000 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x301180eull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x301180full, l_scom_buffer ));

                l_scom_buffer.insert<8, 44, 8, uint64_t>(literal_0x0080000000000000 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x301180full, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301184dull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(l_TGT1_ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID );
                l_scom_buffer.insert<4, 3, 61, uint64_t>(l_TGT1_ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<19, 1, 63, uint64_t>(literal_0x1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301184dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301184eull, l_scom_buffer ));

            constexpr auto l_VA_VA_SOUTH_VA_EG_EG_SCF_ADDR_BAR_MODE_OFF = 0x0;
            l_scom_buffer.insert<13, 1, 63, uint64_t>(l_VA_VA_SOUTH_VA_EG_EG_SCF_ADDR_BAR_MODE_OFF );

            if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
            {
                constexpr auto l_VA_VA_SOUTH_VA_EG_EG_SCF_SKIP_G_ON = 0x1;
                l_scom_buffer.insert<14, 1, 63, uint64_t>(l_VA_VA_SOUTH_VA_EG_EG_SCF_SKIP_G_ON );
            }
            else if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_NODE))
            {
                constexpr auto l_VA_VA_SOUTH_VA_EG_EG_SCF_SKIP_G_OFF = 0x0;
                l_scom_buffer.insert<14, 1, 63, uint64_t>(l_VA_VA_SOUTH_VA_EG_EG_SCF_SKIP_G_OFF );
            }

            l_scom_buffer.insert<20, 8, 56, uint64_t>(literal_0xFC );
            l_scom_buffer.insert<28, 8, 56, uint64_t>(literal_0xFC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301184eull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x301184full, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0x1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x301184full, l_scom_buffer));
            }
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
