/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/procedures/hwp/initfiles/odyssey_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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

constexpr uint64_t literal_0x29 = 0x29;
constexpr uint64_t literal_0x1C = 0x1C;
constexpr uint64_t literal_0x2A = 0x2A;
constexpr uint64_t literal_0x16 = 0x16;
constexpr uint64_t literal_0x1A = 0x1A;
constexpr uint64_t literal_0x7 = 0x7;
constexpr uint64_t literal_0x4 = 0x4;
constexpr uint64_t literal_0x18 = 0x18;
constexpr uint64_t literal_0x8 = 0x8;
constexpr uint64_t literal_0x6 = 0x6;
constexpr uint64_t literal_0x23 = 0x23;
constexpr uint64_t literal_0x10 = 0x10;
constexpr uint64_t literal_0x14 = 0x14;
constexpr uint64_t literal_0x27 = 0x27;
constexpr uint64_t literal_0x09 = 0x09;
constexpr uint64_t literal_0x3B = 0x3B;
constexpr uint64_t literal_0x06 = 0x06;
constexpr uint64_t literal_0x0 = 0x0;
constexpr uint64_t literal_0x1 = 0x1;
constexpr uint64_t literal_0x04 = 0x04;
constexpr uint64_t literal_0x08 = 0x08;
constexpr uint64_t literal_0x02 = 0x02;
constexpr uint64_t literal_0x00 = 0x00;
constexpr uint64_t literal_0x0F = 0x0F;
constexpr uint64_t literal_0x0A = 0x0A;
constexpr uint64_t literal_0x0B = 0x0B;
constexpr uint64_t literal_0x07 = 0x07;
constexpr uint64_t literal_0x03 = 0x03;
constexpr uint64_t literal_0x05 = 0x05;
constexpr uint64_t literal_0x0C = 0x0C;
constexpr uint64_t literal_0x0D = 0x0D;
constexpr uint64_t literal_0x0E = 0x0E;
constexpr uint64_t literal_0x01 = 0x01;
constexpr uint64_t literal_0x162 = 0x162;
constexpr uint64_t literal_0x249 = 0x249;
constexpr uint64_t literal_0x1F = 0x1F;
constexpr uint64_t literal_0x600 = 0x600;
constexpr uint64_t literal_0xD = 0xD;

fapi2::ReturnCode odyssey_scom(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& TGT0)
{
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801100cull, l_scom_buffer ));

            l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x29 );
            l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x1C );
            l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x1C );
            l_scom_buffer.insert<39, 7, 57, uint64_t>(literal_0x2A );
            l_scom_buffer.insert<46, 6, 58, uint64_t>(literal_0x16 );
            l_scom_buffer.insert<52, 6, 58, uint64_t>(literal_0x1A );
            l_scom_buffer.insert<58, 6, 58, uint64_t>(literal_0x1A );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801100cull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801100dull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0x7 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0x4 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0x4 );
            l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0x7 );
            l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_0x4 );
            l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_0x4 );
            l_scom_buffer.insert<28, 5, 59, uint64_t>(literal_0x18 );
            l_scom_buffer.insert<33, 4, 60, uint64_t>(literal_0x8 );
            l_scom_buffer.insert<47, 4, 60, uint64_t>(literal_0x6 );
            l_scom_buffer.insert<51, 6, 58, uint64_t>(literal_0x1A );
            l_scom_buffer.insert<57, 6, 58, uint64_t>(literal_0x1A );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801100dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801100eull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0x6 );
            l_scom_buffer.insert<4, 6, 58, uint64_t>(literal_0x23 );
            l_scom_buffer.insert<10, 6, 58, uint64_t>(literal_0x10 );
            l_scom_buffer.insert<16, 6, 58, uint64_t>(literal_0x14 );
            l_scom_buffer.insert<22, 6, 58, uint64_t>(literal_0x14 );
            l_scom_buffer.insert<28, 7, 57, uint64_t>(literal_0x27 );
            l_scom_buffer.insert<44, 8, 56, uint64_t>(literal_0x09 );
            l_scom_buffer.insert<36, 8, 56, uint64_t>(literal_0x3B );
            l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x4 );
            l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x6 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801100eull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801100full, l_scom_buffer ));

            l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_0x06 );
            l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<24, 1, 63, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<27, 1, 63, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<25, 1, 63, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<26, 1, 63, uint64_t>(literal_0x1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801100full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011010ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0x10 );
            l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0x14 );
            l_scom_buffer.insert<20, 5, 59, uint64_t>(literal_0x04 );
            l_scom_buffer.insert<25, 5, 59, uint64_t>(literal_0x08 );
            l_scom_buffer.insert<12, 5, 59, uint64_t>(literal_0x06 );
            l_scom_buffer.insert<44, 1, 63, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<45, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<46, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<47, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0x0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011010ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011012ull, l_scom_buffer ));

            l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0x02 );
            l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0x00 );
            l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_0x00 );
            l_scom_buffer.insert<35, 5, 59, uint64_t>(literal_0x00 );
            l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0x00 );
            l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_0x0F );
            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<41, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<42, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<33, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<8, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<24, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<25, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<26, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<27, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<30, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<31, 1, 63, uint64_t>(literal_0x0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011012ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011013ull, l_scom_buffer ));

            l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0x00 );
            l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0x00 );
            l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_0x00 );
            l_scom_buffer.insert<35, 5, 59, uint64_t>(literal_0x08 );
            l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0x09 );
            l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_0x0A );
            l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x0B );
            l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<10, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0x0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011013ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011014ull, l_scom_buffer ));

            l_scom_buffer.insert<27, 5, 59, uint64_t>(literal_0x06 );
            l_scom_buffer.insert<35, 5, 59, uint64_t>(literal_0x07 );
            l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0x03 );
            l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_0x04 );
            l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x05 );
            l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0x0C );
            l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0x0D );
            l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_0x0E );
            l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<33, 1, 63, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_0x1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011014ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011015ull, l_scom_buffer ));

            l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0x0A );
            l_scom_buffer.insert<7, 5, 59, uint64_t>(literal_0x00 );
            l_scom_buffer.insert<14, 2, 62, uint64_t>(literal_0x01 );
            l_scom_buffer.insert<12, 2, 62, uint64_t>(literal_0x00 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011015ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011016ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_0x10 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011016ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801101aull, l_scom_buffer ));

            l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801101aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011029ull, l_scom_buffer ));

            l_scom_buffer.insert<1, 2, 62, uint64_t>(literal_0x03 );
            l_scom_buffer.insert<3, 2, 62, uint64_t>(literal_0x03 );
            l_scom_buffer.insert<39, 1, 63, uint64_t>(literal_0x00 );
            l_scom_buffer.insert<40, 1, 63, uint64_t>(literal_0x01 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011029ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011034ull, l_scom_buffer ));

            l_scom_buffer.insert<30, 10, 54, uint64_t>(literal_0x162 );
            l_scom_buffer.insert<8, 11, 53, uint64_t>(literal_0x249 );
            l_scom_buffer.insert<50, 11, 53, uint64_t>(literal_0x249 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011034ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011036ull, l_scom_buffer ));

            l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x1F );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011036ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011037ull, l_scom_buffer ));

            l_scom_buffer.insert<27, 11, 53, uint64_t>(literal_0x600 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011037ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011038ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0xD );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011038ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
