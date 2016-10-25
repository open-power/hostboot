/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_psi_scom.C $  */
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
#include "p9_psi_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0xFE00000000000000 = 0xFE00000000000000;
constexpr uint64_t literal_0x0000000000000000 = 0x0000000000000000;
constexpr uint64_t literal_0b00111001000000101111111111111 = 0b00111001000000101111111111111;
constexpr uint64_t literal_0b00000000000000000000000000000 = 0b00000000000000000000000000000;
constexpr uint64_t literal_0b11000110001010010000000000000 = 0b11000110001010010000000000000;
constexpr uint64_t literal_0x000 = 0x000;
constexpr uint64_t literal_0b00000 = 0b00000;

fapi2::ReturnCode p9_psi_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x4011803ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 7, 0, uint64_t>(literal_0xFE00000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x4011803ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x4011806ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 7, 0, uint64_t>(literal_0x0000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x4011806ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x4011807ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 7, 0, uint64_t>(literal_0x0000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x4011807ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012903ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 29, 35, uint64_t>(literal_0b00111001000000101111111111111 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5012903ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012906ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 29, 35, uint64_t>(literal_0b00000000000000000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5012906ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012907ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 29, 35, uint64_t>(literal_0b11000110001010010000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5012907ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501290full, l_scom_buffer ));

            l_scom_buffer.insert<16, 12, 52, uint64_t>(literal_0x000 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x501290full, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
