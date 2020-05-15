/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_vas_scom.C $ */
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
#include "p10_vas_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0b0 = 0b0;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_0x3FF = 0x3FF;
constexpr uint64_t literal_0x000 = 0x000;
constexpr uint64_t literal_0xFC = 0xFC;
constexpr uint64_t literal_0x1 = 0x1;

fapi2::ReturnCode p10_vas_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                               const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011403ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<10, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<11, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<13, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<14, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<15, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<16, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<19, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<20, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<21, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<22, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<23, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<24, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<25, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<26, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<27, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<28, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<29, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<30, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<31, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<32, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<33, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<35, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<36, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<37, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<39, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<3, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<40, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<41, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<42, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<43, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<44, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<45, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<46, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<47, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<8, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_0b0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2011403ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011406ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<10, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<11, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<13, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<14, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<15, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<16, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<19, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<20, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<21, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<22, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<23, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<24, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<25, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<26, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<27, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<28, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<29, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<30, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<31, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<32, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<33, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<35, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<36, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<37, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<39, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<3, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<40, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<41, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<42, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<43, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<44, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<45, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<46, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<47, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<8, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_0b0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2011406ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011407ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<10, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<11, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<13, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<14, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<15, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<16, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<19, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<20, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<21, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<22, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<23, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<24, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<25, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<26, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<27, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<28, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<29, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<30, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<31, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<32, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<33, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<35, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<36, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<37, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<39, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<3, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<40, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<41, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<42, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<43, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<44, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<45, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<46, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<47, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<8, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_0b1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2011407ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x201144eull, l_scom_buffer ));

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                constexpr auto l_VAS_VA_EG_EG_SCF_SKIP_G_ON = 0x1;
                l_scom_buffer.insert<14, 1, 63, uint64_t>(l_VAS_VA_EG_EG_SCF_SKIP_G_ON );
            }
            else if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                constexpr auto l_VAS_VA_EG_EG_SCF_SKIP_G_OFF = 0x0;
                l_scom_buffer.insert<14, 1, 63, uint64_t>(l_VAS_VA_EG_EG_SCF_SKIP_G_OFF );
            }

            l_scom_buffer.insert<20, 8, 56, uint64_t>(literal_0xFC );
            l_scom_buffer.insert<28, 8, 56, uint64_t>(literal_0xFC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x201144eull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x201144full, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0x1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x201144full, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
