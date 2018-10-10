/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9c_mc_scom.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#include "p9c_mc_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0x400000000000 = 0x400000000000;
constexpr uint64_t literal_0b0001111111111111111111111111111111111111111010000000000000000 =
    0b0001111111111111111111111111111111111111111010000000000000000;
constexpr uint64_t literal_0x20000000001 = 0x20000000001;
constexpr uint64_t literal_0x800000000000 = 0x800000000000;
constexpr uint64_t literal_0x8000000000000000 = 0x8000000000000000;
constexpr uint64_t literal_0x00000000000C0000 = 0x00000000000C0000;
constexpr uint64_t literal_0b00000011000000000000000000100100000000000000000000000000000 =
    0b00000011000000000000000000100100000000000000000000000000000;
constexpr uint64_t literal_0b01110 = 0b01110;

fapi2::ReturnCode p9c_mc_scom(const fapi2::Target<fapi2::TARGET_TYPE_MC>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7012380ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 48, 16, uint64_t>(literal_0x400000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x7012380ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7012381ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 61, 3, uint64_t>(literal_0b0001111111111111111111111111111111111111111010000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x7012381ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7012383ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 44, 20, uint64_t>(literal_0x20000000001 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x7012383ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7012385ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 48, 16, uint64_t>(literal_0x400000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x7012385ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7012386ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 61, 3, uint64_t>(literal_0b0001111111111111111111111111111111111111111010000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x7012386ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7012388ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 44, 20, uint64_t>(literal_0x20000000001 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x7012388ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x701238aull, l_scom_buffer ));

            l_scom_buffer.insert<0, 48, 16, uint64_t>(literal_0x400000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x701238aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x701238bull, l_scom_buffer ));

            l_scom_buffer.insert<0, 61, 3, uint64_t>(literal_0b0001111111111111111111111111111111111111111010000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x701238bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x701238dull, l_scom_buffer ));

            l_scom_buffer.insert<0, 44, 20, uint64_t>(literal_0x20000000001 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x701238dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x701238full, l_scom_buffer ));

            l_scom_buffer.insert<0, 48, 16, uint64_t>(literal_0x400000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x701238full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7012390ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 61, 3, uint64_t>(literal_0b0001111111111111111111111111111111111111111010000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x7012390ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7012392ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 44, 20, uint64_t>(literal_0x20000000001 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x7012392ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x70123afull, l_scom_buffer ));

            constexpr auto l_MCP_MISC_MBA_SCOMFIR_MCBPARMQ_CFG_CLOCK_MONITOR_EN_ON = 0x1;
            l_scom_buffer.insert<59, 1, 63, uint64_t>(l_MCP_MISC_MBA_SCOMFIR_MCBPARMQ_CFG_CLOCK_MONITOR_EN_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x70123afull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x70123e8ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 48, 16, uint64_t>(literal_0x800000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x70123e8ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x70123e9ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x8000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x70123e9ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x70123eaull, l_scom_buffer ));

            l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x00000000000C0000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x70123eaull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x70123ebull, l_scom_buffer ));

            l_scom_buffer.insert<0, 59, 5, uint64_t>(literal_0b00000011000000000000000000100100000000000000000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x70123ebull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800f1c000701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01110 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800f1c000701103full, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
