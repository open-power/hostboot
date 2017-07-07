/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_cxa_scom.C $  */
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
#include "p9_cxa_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0x801B1F98C8717000 = 0x801B1F98C8717000;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0x801B1F98D8717000 = 0x801B1F98D8717000;
constexpr uint64_t literal_0x0000000000000 = 0x0000000000000;
constexpr uint64_t literal_0x2080000020080 = 0x2080000020080;
constexpr uint64_t literal_0b0000 = 0b0000;
constexpr uint64_t literal_0b111 = 0b111;
constexpr uint64_t literal_0b0010 = 0b0010;
constexpr uint64_t literal_0b0001 = 0b0001;

fapi2::ReturnCode p9_cxa_scom(const fapi2::Target<fapi2::TARGET_TYPE_CAPP>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT2)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT2, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT2, l_chip_ec));
        fapi2::ATTR_CHIP_EC_FEATURE_HW414700_Type l_TGT2_ATTR_CHIP_EC_FEATURE_HW414700;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW414700, TGT2, l_TGT2_ATTR_CHIP_EC_FEATURE_HW414700));
        fapi2::ATTR_PROC_FABRIC_PUMP_MODE_Type l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PUMP_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010803ull, l_scom_buffer ));

            if ((l_TGT2_ATTR_CHIP_EC_FEATURE_HW414700 != literal_0))
            {
                l_scom_buffer.insert<0, 53, 0, uint64_t>(literal_0x801B1F98C8717000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<0, 53, 0, uint64_t>(literal_0x801B1F98D8717000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2010803ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010806ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<0, 52, 12, uint64_t>(literal_0x0000000000000 );
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<0, 53, 11, uint64_t>(literal_0x0000000000000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2010806ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010807ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<0, 52, 12, uint64_t>(literal_0x2080000020080 );
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<0, 53, 11, uint64_t>(literal_0x2080000020080 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2010807ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010818ull, l_scom_buffer ));

            constexpr auto l_CAPP0_CXA_TOP_CXA_APC0_APCCTL_ADR_BAR_MODE_OFF = 0x0;
            l_scom_buffer.insert<1, 1, 63, uint64_t>(l_CAPP0_CXA_TOP_CXA_APC0_APCCTL_ADR_BAR_MODE_OFF );

            if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
            {
                constexpr auto l_CAPP0_CXA_TOP_CXA_APC0_APCCTL_SKIP_G_ON = 0x1;
                l_scom_buffer.insert<6, 1, 63, uint64_t>(l_CAPP0_CXA_TOP_CXA_APC0_APCCTL_SKIP_G_ON );
            }
            else if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_NODE))
            {
                constexpr auto l_CAPP0_CXA_TOP_CXA_APC0_APCCTL_SKIP_G_OFF = 0x0;
                l_scom_buffer.insert<6, 1, 63, uint64_t>(l_CAPP0_CXA_TOP_CXA_APC0_APCCTL_SKIP_G_OFF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2010818ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010819ull, l_scom_buffer ));

            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b0000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2010819ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x201081bull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<45, 3, 61, uint64_t>(literal_0b111 );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<45, 3, 61, uint64_t>(literal_0b111 );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0010 );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0010 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x201081bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x201081cull, l_scom_buffer ));

            l_scom_buffer.insert<18, 4, 60, uint64_t>(literal_0b0001 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x201081cull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
