/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_pau_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
#include "p10_pau_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_8 = 8;
constexpr uint64_t literal_0x0 = 0x0;
constexpr uint64_t literal_0x2 = 0x2;
constexpr uint64_t literal_0b000010 = 0b000010;
constexpr uint64_t literal_0b000110 = 0b000110;
constexpr uint64_t literal_0b0010 = 0b0010;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_0b010 = 0b010;
constexpr uint64_t literal_0b0010000000 = 0b0010000000;
constexpr uint64_t literal_0b0100000000 = 0b0100000000;
constexpr uint64_t literal_0b0110000000 = 0b0110000000;
constexpr uint64_t literal_0b011 = 0b011;
constexpr uint64_t literal_0b0100 = 0b0100;
constexpr uint64_t literal_0x0000b04500ac0000 = 0x0000b04500ac0000;
constexpr uint64_t literal_0x0007000005f20000 = 0x0007000005f20000;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0x0007000005f60000 = 0x0007000005f60000;
constexpr uint64_t literal_0x0000000000000010 = 0x0000000000000010;
constexpr uint64_t literal_0x0fffefff0fe5b8f8 = 0x0fffefff0fe5b8f8;
constexpr uint64_t literal_0x0000000000000300 = 0x0000000000000300;
constexpr uint64_t literal_0xfffb00000f03ffff = 0xfffb00000f03ffff;
constexpr uint64_t literal_0xfffff85f0fffffff = 0xfffff85f0fffffff;
constexpr uint64_t literal_0xfff8fffff09fffff = 0xfff8fffff09fffff;
constexpr uint64_t literal_0xf0000000f0180707 = 0xf0000000f0180707;

fapi2::ReturnCode p10_pau_scom(const fapi2::Target<fapi2::TARGET_TYPE_PAU>& TGT0,
                               const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT2)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT1, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT1, l_chip_ec));
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T0_Type l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T0, TGT2, l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T0));
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T1_Type l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T1, TGT2, l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T1));
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T2_Type l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T2, TGT2, l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T2));
        fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T1_Type l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T1, TGT2, l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T1));
        fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T2_Type l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T2, TGT2, l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T2));
        fapi2::ATTR_CHIP_EC_FEATURE_HW530359_XSL_PARITY_Type l_TGT1_ATTR_CHIP_EC_FEATURE_HW530359_XSL_PARITY;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW530359_XSL_PARITY, TGT1,
                               l_TGT1_ATTR_CHIP_EC_FEATURE_HW530359_XSL_PARITY));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010802ull, l_scom_buffer ));

            l_scom_buffer.insert<28, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T0 / literal_8) );
            l_scom_buffer.insert<40, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T1 / literal_8) );
            l_scom_buffer.insert<52, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T2 / literal_8) );
            l_scom_buffer.insert<4, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T1 / literal_8) );
            l_scom_buffer.insert<16, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T2 / literal_8) );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010802ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010831ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0x2 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010831ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010862ull, l_scom_buffer ));

            l_scom_buffer.insert<28, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T0 / literal_8) );
            l_scom_buffer.insert<40, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T1 / literal_8) );
            l_scom_buffer.insert<52, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T2 / literal_8) );
            l_scom_buffer.insert<4, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T1 / literal_8) );
            l_scom_buffer.insert<16, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T2 / literal_8) );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010862ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010891ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0x2 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010891ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x100108c2ull, l_scom_buffer ));

            l_scom_buffer.insert<28, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T0 / literal_8) );
            l_scom_buffer.insert<40, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T1 / literal_8) );
            l_scom_buffer.insert<52, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T2 / literal_8) );
            l_scom_buffer.insert<4, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T1 / literal_8) );
            l_scom_buffer.insert<16, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T2 / literal_8) );
            FAPI_TRY(fapi2::putScom(TGT0, 0x100108c2ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x100108f1ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0x2 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x100108f1ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010922ull, l_scom_buffer ));

            l_scom_buffer.insert<28, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T0 / literal_8) );
            l_scom_buffer.insert<40, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T1 / literal_8) );
            l_scom_buffer.insert<52, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T2 / literal_8) );
            l_scom_buffer.insert<4, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T1 / literal_8) );
            l_scom_buffer.insert<16, 12, 52, uint64_t>((l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T2 / literal_8) );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010922ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010951ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0x2 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010951ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010981ull, l_scom_buffer ));

            l_scom_buffer.insert<3, 6, 58, uint64_t>(literal_0b000010 );
            l_scom_buffer.insert<9, 6, 58, uint64_t>(literal_0b000110 );
            l_scom_buffer.insert<15, 4, 60, uint64_t>(literal_0b0010 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010981ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0xa) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x10010982ull, l_scom_buffer ));

                l_scom_buffer.insert<32, 1, 63, uint64_t>(literal_0b1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x10010982ull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x1001098aull, l_scom_buffer ));

            l_scom_buffer.insert<1, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<4, 10, 54, uint64_t>(literal_0b0010000000 );
            l_scom_buffer.insert<14, 10, 54, uint64_t>(literal_0b0100000000 );
            l_scom_buffer.insert<24, 10, 54, uint64_t>(literal_0b0110000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x1001098aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010a2bull, l_scom_buffer ));

            l_scom_buffer.insert<5, 3, 61, uint64_t>(literal_0b011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010a2bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010af5ull, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010af5ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010b3aull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0000b04500ac0000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010b3aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010b3bull, l_scom_buffer ));

            if (l_TGT1_ATTR_CHIP_EC_FEATURE_HW530359_XSL_PARITY)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0007000005f20000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0007000005f60000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x10010b3bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010b3cull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0000000000000010 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010b3cull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010bb0ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0fffefff0fe5b8f8 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010bb0ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010bb1ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0000000000000300 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010bb1ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010c03ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xfffb00000f03ffff );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010c03ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010c06ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0000b04500ac0000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010c06ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010c07ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xfffff85f0fffffff );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010c07ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010c43ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xfff8fffff09fffff );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010c43ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010c46ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0007000005f60000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010c46ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010c83ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xf0000000f0180707 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010c83ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010c86ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0fffefff0fe5b8f8 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010c86ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
