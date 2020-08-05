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

fapi2::ReturnCode p10_int_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                               const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010803ull, l_scom_buffer ));

            l_scom_buffer.insert<14, 2, 62, uint64_t>(literal_0b00 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2010803ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010816ull, l_scom_buffer ));

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

    };
fapi_try_exit:
    return fapi2::current_err;
}
