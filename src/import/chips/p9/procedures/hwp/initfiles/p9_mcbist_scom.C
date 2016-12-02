/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_mcbist_scom.C $ */
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
#include "p9_mcbist_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr auto literal_0b010000000000000000000000000000000000000000000000 =
    0b010000000000000000000000000000000000000000000000;
constexpr auto literal_0b00000000000000000000001111111011111111111111 = 0b00000000000000000000001111111011111111111111;
constexpr auto literal_0b10000000000000000 = 0b10000000000000000;
constexpr auto literal_0b10000000001000000000000000000100000000000000 = 0b10000000001000000000000000000100000000000000;
constexpr auto literal_0b11110000000 = 0b11110000000;
constexpr auto literal_0b00001000000000000000 = 0b00001000000000000000;
constexpr auto literal_0b100 = 0b100;
constexpr auto literal_0b0100 = 0b0100;

fapi2::ReturnCode p9_mcbist_scom(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& TGT0)
{
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7012380ull, l_scom_buffer ));

            l_scom_buffer.insert<uint64_t> (literal_0b010000000000000000000000000000000000000000000000, 0, 48, 16 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x7012380ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7012381ull, l_scom_buffer ));

            l_scom_buffer.insert<uint64_t> (literal_0b00000000000000000000001111111011111111111111, 0, 44, 20 );
            l_scom_buffer.insert<uint64_t> (literal_0b10000000000000000, 44, 17, 47 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x7012381ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7012383ull, l_scom_buffer ));

            l_scom_buffer.insert<uint64_t> (literal_0b10000000001000000000000000000100000000000000, 0, 44, 20 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x7012383ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x70123e0ull, l_scom_buffer ));

            constexpr auto l_MCP_MCBIST_MBA_SCOMFIR_MCBCFGQ_CFG_LOG_COUNTS_IN_TRACE_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_MCP_MCBIST_MBA_SCOMFIR_MCBCFGQ_CFG_LOG_COUNTS_IN_TRACE_OFF, 36, 1, 63 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x70123e0ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x70123e8ull, l_scom_buffer ));

            constexpr auto l_MCP_MCBIST_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_MCP_MCBIST_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE_ON, 0, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b11110000000, 23, 11, 53 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x70123e8ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x70123e9ull, l_scom_buffer ));

            constexpr auto l_MCP_MCBIST_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_MCP_MCBIST_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE_ON, 0, 1, 63 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x70123e9ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x70123eaull, l_scom_buffer ));

            l_scom_buffer.insert<uint64_t> (literal_0b00001000000000000000, 20, 20, 44 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x70123eaull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x70123ebull, l_scom_buffer ));

            l_scom_buffer.insert<uint64_t> (literal_0b100, 23, 3, 61 );
            l_scom_buffer.insert<uint64_t> (literal_0b0100, 37, 4, 60 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x70123ebull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
