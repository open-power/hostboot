/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9a_int_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
#include "p9a_int_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0b10 = 0b10;
constexpr uint64_t literal_0b1000000 = 0b1000000;
constexpr uint64_t literal_0x2000005C04028000 = 0x2000005C04028000;
constexpr uint64_t literal_0x2000005C040281C3 = 0x2000005C040281C3;
constexpr uint64_t literal_0x0000005C040081C3 = 0x0000005C040081C3;
constexpr uint64_t literal_0x0000000000000000 = 0x0000000000000000;
constexpr uint64_t literal_0x9554021F80110FCF = 0x9554021F80110FCF;
constexpr uint64_t literal_0x9554021F80110E0C = 0x9554021F80110E0C;
constexpr uint64_t literal_0x18 = 0x18;
constexpr uint64_t literal_0x010003FF00100020 = 0x010003FF00100020;
constexpr uint64_t literal_0x050043EF00100020 = 0x050043EF00100020;
constexpr uint64_t literal_0xD8DFB200DFAFFFD7 = 0xD8DFB200DFAFFFD7;
constexpr uint64_t literal_0xFADFBB8CFFAFFFD7 = 0xFADFBB8CFFAFFFD7;
constexpr uint64_t literal_0x0002000410000000 = 0x0002000410000000;
constexpr uint64_t literal_0x0002000610000000 = 0x0002000610000000;
constexpr uint64_t literal_0x6262220242160000 = 0x6262220242160000;
constexpr uint64_t literal_0x5BBF = 0x5BBF;

fapi2::ReturnCode p9a_int_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                               const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_PROC_FABRIC_PUMP_MODE_Type l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PUMP_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE));
        fapi2::ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID_Type l_TGT1_ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID, TGT1, l_TGT1_ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID));
        fapi2::ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID_Type l_TGT1_ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID, TGT1, l_TGT1_ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID));
        fapi2::ATTR_SMF_CONFIG_Type l_TGT1_ATTR_SMF_CONFIG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SMF_CONFIG, TGT1, l_TGT1_ATTR_SMF_CONFIG));
        fapi2::ATTR_CHIP_EC_FEATURE_HW426891_Type l_TGT0_ATTR_CHIP_EC_FEATURE_HW426891;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW426891, TGT0, l_TGT0_ATTR_CHIP_EC_FEATURE_HW426891));
        fapi2::ATTR_CHIP_EC_FEATURE_HW411637_Type l_TGT0_ATTR_CHIP_EC_FEATURE_HW411637;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW411637, TGT0, l_TGT0_ATTR_CHIP_EC_FEATURE_HW411637));
        fapi2::ATTR_CHIP_EC_FEATURE_P9N_INT_DD10_Type l_TGT0_ATTR_CHIP_EC_FEATURE_P9N_INT_DD10;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_P9N_INT_DD10, TGT0, l_TGT0_ATTR_CHIP_EC_FEATURE_P9N_INT_DD10));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501300aull, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0 );

            if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_1 );
            }
            else if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_NODE))
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0 );
            }

            l_scom_buffer.insert<5, 4, 60, uint64_t>(l_TGT1_ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID );
            l_scom_buffer.insert<9, 3, 61, uint64_t>(l_TGT1_ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID );

            if ((l_TGT1_ATTR_SMF_CONFIG == fapi2::ENUM_ATTR_SMF_CONFIG_ENABLED))
            {
                l_scom_buffer.insert<12, 2, 62, uint64_t>(literal_0b10 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x501300aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013020ull, l_scom_buffer ));

            l_scom_buffer.insert<25, 7, 57, uint64_t>(literal_0b1000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5013020ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013021ull, l_scom_buffer ));

            if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_1 );
            }
            else if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_NODE))
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013021ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013033ull, l_scom_buffer ));

            if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW411637 == literal_1) && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW426891 == literal_0)))
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x2000005C04028000 );
            }
            else if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW411637 == literal_1) && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW426891 == literal_1)))
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x2000005C040281C3 );
            }
            else if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW411637 == literal_0) && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW426891 == literal_1)))
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0000005C040081C3 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013033ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013036ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5013036ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013037ull, l_scom_buffer ));

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_P9N_INT_DD10 == literal_1))
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x9554021F80110FCF );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_P9N_INT_DD10 == literal_0))
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x9554021F80110E0C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013037ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013130ull, l_scom_buffer ));

            l_scom_buffer.insert<2, 6, 58, uint64_t>(literal_0x18 );
            l_scom_buffer.insert<10, 6, 58, uint64_t>(literal_0x18 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5013130ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013140ull, l_scom_buffer ));

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426891 == literal_0))
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x010003FF00100020 );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426891 == literal_1))
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x050043EF00100020 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013140ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013141ull, l_scom_buffer ));

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426891 == literal_0))
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xD8DFB200DFAFFFD7 );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426891 == literal_1))
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFADFBB8CFFAFFFD7 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013141ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013178ull, l_scom_buffer ));

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426891 == literal_0))
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0002000410000000 );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426891 == literal_1))
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0002000610000000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013178ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501320eull, l_scom_buffer ));

            l_scom_buffer.insert<0, 48, 0, uint64_t>(literal_0x6262220242160000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x501320eull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013214ull, l_scom_buffer ));

            l_scom_buffer.insert<16, 16, 48, uint64_t>(literal_0x5BBF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5013214ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501322bull, l_scom_buffer ));

            l_scom_buffer.insert<58, 6, 58, uint64_t>(literal_0x18 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x501322bull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
