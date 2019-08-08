/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_mcc_omi_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#include "p10_mcc_omi_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0b100000 = 0b100000;
constexpr uint64_t literal_0b0001 = 0b0001;
constexpr uint64_t literal_0b1000000 = 0b1000000;
constexpr uint64_t literal_0b011000 = 0b011000;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_7 = 7;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0b0000110000 = 0b0000110000;

fapi2::ReturnCode p10_mcc_omi_scom(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& TGT0,
                                   const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT3)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT3, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT3, l_chip_ec));
        uint64_t l_def_ENABLE_MCU_TIMEOUTS = literal_1;
        uint64_t l_def_ENABLE_HWFM = literal_1;
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010d0aull, l_scom_buffer ));

            l_scom_buffer.insert<2, 6, 58, uint64_t>(literal_0b100000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b0001 );
            l_scom_buffer.insert<17, 7, 57, uint64_t>(literal_0b1000000 );
            l_scom_buffer.insert<50, 6, 58, uint64_t>(literal_0b011000 );
            l_scom_buffer.insert<58, 6, 58, uint64_t>(literal_0b011000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc010d0aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010d0bull, l_scom_buffer ));

            if ((l_def_ENABLE_MCU_TIMEOUTS == literal_1))
            {
                l_scom_buffer.insert<49, 3, 61, uint64_t>(literal_7 );
            }

            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc010d0bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010e0full, l_scom_buffer ));

            if ((l_def_ENABLE_HWFM == literal_1))
            {
                l_scom_buffer.insert<1, 6, 58, uint64_t>(literal_1 );
            }
            else if ((l_def_ENABLE_HWFM == literal_0))
            {
                l_scom_buffer.insert<1, 6, 58, uint64_t>(literal_0 );
            }

            if ((l_def_ENABLE_HWFM == literal_1))
            {
                constexpr auto l_MCP_CHAN0_USTL_USTLMCHWFM_ENABLE_ON = 0x1;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_MCP_CHAN0_USTL_USTLMCHWFM_ENABLE_ON );
            }
            else if ((l_def_ENABLE_HWFM == literal_0))
            {
                constexpr auto l_MCP_CHAN0_USTL_USTLMCHWFM_ENABLE_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_MCP_CHAN0_USTL_USTLMCHWFM_ENABLE_OFF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0xc010e0full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010e13ull, l_scom_buffer ));

            l_scom_buffer.insert<48, 10, 54, uint64_t>(literal_0b0000110000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc010e13ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
