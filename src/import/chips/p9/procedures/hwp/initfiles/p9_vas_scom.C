/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_vas_scom.C $  */
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
#include "p9_vas_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0x00000100000D7FFF = 0x00000100000D7FFF;
constexpr uint64_t literal_0x0000000000000FFF = 0x0000000000000FFF;
constexpr uint64_t literal_0x00FF0203C00C0FFF = 0x00FF0203C00C0FFF;
constexpr uint64_t literal_0x1 = 0x1;

fapi2::ReturnCode p9_vas_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_PROC_FABRIC_ADDR_BAR_MODE_Type l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_ADDR_BAR_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011803ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 54, 0, uint64_t>(literal_0x00000100000D7FFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011803ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011806ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 54, 0, uint64_t>(literal_0x0000000000000FFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011806ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011807ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 54, 0, uint64_t>(literal_0x00FF0203C00C0FFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011807ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301184dull, l_scom_buffer ));

            l_scom_buffer.insert<19, 1, 63, uint64_t>(literal_0x1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301184dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301184eull, l_scom_buffer ));

            if ((l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_ADDR_BAR_MODE_SMALL_SYSTEM))
            {
                constexpr auto l_VA_VA_SOUTH_VA_EG_EG_SCF_ADDR_BAR_MODE_ON = 0x1;
                l_scom_buffer.insert<13, 1, 63, uint64_t>(l_VA_VA_SOUTH_VA_EG_EG_SCF_ADDR_BAR_MODE_ON );
            }
            else if ((l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_ADDR_BAR_MODE_LARGE_SYSTEM))
            {
                constexpr auto l_VA_VA_SOUTH_VA_EG_EG_SCF_ADDR_BAR_MODE_OFF = 0x0;
                l_scom_buffer.insert<13, 1, 63, uint64_t>(l_VA_VA_SOUTH_VA_EG_EG_SCF_ADDR_BAR_MODE_OFF );
            }

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
