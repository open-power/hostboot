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

constexpr auto literal_0x80031F98D8717 = 0x80031F98D8717;
constexpr auto literal_0x0B1C000104060 = 0x0B1C000104060;
constexpr auto literal_0x2B9C0001240E0 = 0x2B9C0001240E0;
constexpr auto literal_0b0000 = 0b0000;
constexpr auto literal_0b111 = 0b111;
constexpr auto literal_0b0010 = 0b0010;
constexpr auto literal_0b0001 = 0b0001;

fapi2::ReturnCode p9_cxa_scom(const fapi2::Target<fapi2::TARGET_TYPE_CAPP>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            l_rc = fapi2::getScom( TGT0, 0x2010803ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x2010803ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0x80031F98D8717, 0, 52, 0 );
            }

            l_rc = fapi2::putScom(TGT0, 0x2010803ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x2010803ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x2010806ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x2010806ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0x0B1C000104060, 0, 52, 12 );
            }

            l_rc = fapi2::putScom(TGT0, 0x2010806ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x2010806ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x2010807ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x2010807ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0x2B9C0001240E0, 0, 52, 12 );
            }

            l_rc = fapi2::putScom(TGT0, 0x2010807ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x2010807ull)");
                break;
            }
        }
        fapi2::ATTR_PROC_FABRIC_ADDR_BAR_MODE_Type l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_ADDR_BAR_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_ADDR_BAR_MODE)");
            break;
        }

        fapi2::ATTR_PROC_FABRIC_PUMP_MODE_Type l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PUMP_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_PUMP_MODE)");
            break;
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x2010818ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x2010818ull)");
                break;
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_ADDR_BAR_MODE_SMALL_SYSTEM))
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 1, 1, 63 );
                }
                else if ((l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_ADDR_BAR_MODE_LARGE_SYSTEM))
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 1, 1, 63 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 6, 1, 63 );
                }
                else if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_NODE))
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 6, 1, 63 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x2010818ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x2010818ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x2010819ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x2010819ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 4, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x2010819ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x2010819ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x201081bull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x201081bull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b111, 45, 3, 61 );
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b0010, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x201081bull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x201081bull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x201081cull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x201081cull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b0001, 18, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x201081cull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x201081cull)");
                break;
            }
        }
    }
    while (0);

    return l_rc;
}
