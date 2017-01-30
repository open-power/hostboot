/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_vas_scom.C $  */
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
#include "p9_vas_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0x00200102000D7FFF = 0x00200102000D7FFF;
constexpr uint64_t literal_0x0000000000000000 = 0x0000000000000000;
constexpr uint64_t literal_0x00DF0201C0000000 = 0x00DF0201C0000000;
constexpr uint64_t literal_0x80000000 = 0x80000000;
constexpr uint64_t literal_0x8000000 = 0x8000000;
constexpr uint64_t literal_0x1 = 0x1;

fapi2::ReturnCode p9_vas_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011803ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 54, 0, uint64_t>(literal_0x00200102000D7FFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011803ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011806ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 54, 0, uint64_t>(literal_0x0000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011806ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011807ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 54, 0, uint64_t>(literal_0x00DF0201C0000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011807ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301180aull, l_scom_buffer ));

            l_scom_buffer.insert<8, 31, 33, uint64_t>(literal_0x80000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301180aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301180bull, l_scom_buffer ));

            l_scom_buffer.insert<8, 28, 36, uint64_t>(literal_0x8000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301180bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301184dull, l_scom_buffer ));

            l_scom_buffer.insert<19, 1, 63, uint64_t>(literal_0x1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301184dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301184eull, l_scom_buffer ));

            constexpr auto l_VA_VA_SOUTH_VA_EG_EG_SCF_ADDR_BAR_MODE_OFF = 0x0;
            l_scom_buffer.insert<13, 1, 63, uint64_t>(l_VA_VA_SOUTH_VA_EG_EG_SCF_ADDR_BAR_MODE_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301184eull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301184full, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0x1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301184full, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
