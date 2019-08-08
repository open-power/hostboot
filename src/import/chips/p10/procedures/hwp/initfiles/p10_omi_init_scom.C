/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_omi_init_scom.C $ */
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
#include "p10_omi_init_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0b100 = 0b100;
constexpr uint64_t literal_0b0011 = 0b0011;

fapi2::ReturnCode p10_omi_init_scom(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& TGT0,
                                    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_PROC_ENABLE_DL_TMPL_7_Type l_TGT0_ATTR_PROC_ENABLE_DL_TMPL_7;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_ENABLE_DL_TMPL_7, TGT0, l_TGT0_ATTR_PROC_ENABLE_DL_TMPL_7));
        fapi2::ATTR_PROC_ENABLE_DL_TMPL_4_Type l_TGT0_ATTR_PROC_ENABLE_DL_TMPL_4;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_ENABLE_DL_TMPL_4, TGT0, l_TGT0_ATTR_PROC_ENABLE_DL_TMPL_4));
        fapi2::ATTR_PROC_TMPL_0_PACING_Type l_TGT0_ATTR_PROC_TMPL_0_PACING;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_TMPL_0_PACING, TGT0, l_TGT0_ATTR_PROC_TMPL_0_PACING));
        fapi2::ATTR_PROC_TMPL_1_PACING_Type l_TGT0_ATTR_PROC_TMPL_1_PACING;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_TMPL_1_PACING, TGT0, l_TGT0_ATTR_PROC_TMPL_1_PACING));
        fapi2::ATTR_PROC_TMPL_4_PACING_Type l_TGT0_ATTR_PROC_TMPL_4_PACING;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_TMPL_4_PACING, TGT0, l_TGT0_ATTR_PROC_TMPL_4_PACING));
        fapi2::ATTR_PROC_TMPL_7_PACING_Type l_TGT0_ATTR_PROC_TMPL_7_PACING;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_TMPL_7_PACING, TGT0, l_TGT0_ATTR_PROC_TMPL_7_PACING));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010d0bull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_ENABLE_DL_TMPL_7 == fapi2::ENUM_ATTR_PROC_ENABLE_DL_TMPL_7_ENABLED))
            {
                constexpr auto l_MCP_CHAN0_DSTL_DSTLCFG_TMPL7_ENABLE_ON = 0x1;
                l_scom_buffer.insert<2, 1, 63, uint64_t>(l_MCP_CHAN0_DSTL_DSTLCFG_TMPL7_ENABLE_ON );
            }

            if ((l_TGT0_ATTR_PROC_ENABLE_DL_TMPL_4 == fapi2::ENUM_ATTR_PROC_ENABLE_DL_TMPL_4_DISABLED))
            {
                constexpr auto l_MCP_CHAN0_DSTL_DSTLCFG_TMPL4_DISABLE_ON = 0x1;
                l_scom_buffer.insert<6, 1, 63, uint64_t>(l_MCP_CHAN0_DSTL_DSTLCFG_TMPL4_DISABLE_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0xc010d0bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010d0eull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(l_TGT0_ATTR_PROC_TMPL_0_PACING );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(l_TGT0_ATTR_PROC_TMPL_1_PACING );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(l_TGT0_ATTR_PROC_TMPL_4_PACING );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(l_TGT0_ATTR_PROC_TMPL_7_PACING );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc010d0eull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010e0bull, l_scom_buffer ));

            l_scom_buffer.insert<9, 3, 61, uint64_t>(literal_0b100 );
            l_scom_buffer.insert<40, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc010e0bull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
