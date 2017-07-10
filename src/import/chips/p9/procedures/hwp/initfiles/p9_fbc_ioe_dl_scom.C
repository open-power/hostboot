/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_fbc_ioe_dl_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#include "p9_fbc_ioe_dl_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0x0B = 0x0B;
constexpr uint64_t literal_0x0 = 0x0;
constexpr uint64_t literal_0xE00 = 0xE00;
constexpr uint64_t literal_0x0000 = 0x0000;
constexpr uint64_t literal_0b11 = 0b11;

fapi2::ReturnCode p9_fbc_ioe_dl_scom(const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& TGT0,
                                     const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT1, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT1, l_chip_ec));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x601180aull, l_scom_buffer ));

            constexpr auto l_PB_IOE_LL1_CONFIG_LINK_PAIR_ON = 0x1;
            l_scom_buffer.insert<0, 1, 63, uint64_t>(l_PB_IOE_LL1_CONFIG_LINK_PAIR_ON );
            constexpr auto l_PB_IOE_LL1_CONFIG_CRC_LANE_ID_ON = 0x1;
            l_scom_buffer.insert<2, 1, 63, uint64_t>(l_PB_IOE_LL1_CONFIG_CRC_LANE_ID_ON );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0x0B );
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0x0B );
            }

            l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0x0 );
            constexpr auto l_PB_IOE_LL1_CONFIG_SL_UE_CRC_ERR_ON = 0x1;
            l_scom_buffer.insert<4, 1, 63, uint64_t>(l_PB_IOE_LL1_CONFIG_SL_UE_CRC_ERR_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x601180aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x6011818ull, l_scom_buffer ));

            l_scom_buffer.insert<8, 3, 61, uint64_t>(literal_0xE00 );
            l_scom_buffer.insert<32, 16, 48, uint64_t>(literal_0x0000 );
            l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0x0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x6011818ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x6011819ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<8, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<8, 3, 61, uint64_t>(literal_0b11 );
            }

            l_scom_buffer.insert<32, 16, 48, uint64_t>(literal_0x0000 );
            l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0x0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x6011819ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
