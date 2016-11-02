/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_int_scom.C $  */
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
#include "p9_int_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr auto literal_0b00 = 0b00;
constexpr auto literal_0x0070000072040140 = 0x0070000072040140;
constexpr auto literal_0x0101042004201800 = 0x0101042004201800;
constexpr auto literal_0x010003FF00100020 = 0x010003FF00100020;
constexpr auto literal_0xD8DFB200FFAFFFD7 = 0xD8DFB200FFAFFFD7;
constexpr auto literal_0x0008002000002002 = 0x0008002000002002;
constexpr auto literal_0xEF6437D2DE7DD3FD = 0xEF6437D2DE7DD3FD;
constexpr auto literal_0x0002000410000000 = 0x0002000410000000;
constexpr auto literal_0x7710CCC3E0000701 = 0x7710CCC3E0000701;
constexpr auto literal_0x00001003000002 = 0x00001003000002;
constexpr auto literal_0xFFFFEFFCFFFFFC = 0xFFFFEFFCFFFFFC;
constexpr auto literal_0x0003C018006 = 0x0003C018006;
constexpr auto literal_0xFFFDFFEFFFA = 0xFFFDFFEFFFA;
constexpr auto literal_0x0000004000028000 = 0x0000004000028000;
constexpr auto literal_0x00000000040101C3 = 0x00000000040101C3;
constexpr auto literal_0x9554021F80100E0C = 0x9554021F80100E0C;
constexpr auto literal_1 = 1;
constexpr auto literal_0 = 0;

fapi2::ReturnCode p9_int_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        l_rc = FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id);

        if (l_rc)
        {
            FAPI_ERR("ERROR getting ATTR_NAME");
            break;
        }

        l_rc = FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec);

        if (l_rc)
        {
            FAPI_ERR("ERROR getting ATTR_EC");
            break;
        }

        {
            fapi2::buffer<uint64_t> l_scom_buffer;
            {
                l_rc = fapi2::getScom( TGT0, 0x5013124ull, l_scom_buffer );

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: getScom (0x5013124ull)");
                    break;
                }

                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 28, 2, 62 );
                }

                l_rc = fapi2::putScom(TGT0, 0x5013124ull, l_scom_buffer);

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: putScom (0x5013124ull)");
                    break;
                }
            }
        }

        {
            fapi2::buffer<uint64_t> l_scom_buffer;
            {
                l_rc = fapi2::getScom( TGT0, 0x5013022ull, l_scom_buffer );

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: getScom (0x5013022ull)");
                    break;
                }

                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0070000072040140, 0, 64, 0 );
                }

                l_rc = fapi2::putScom(TGT0, 0x5013022ull, l_scom_buffer);

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: putScom (0x5013022ull)");
                    break;
                }
            }
        }

        {
            fapi2::buffer<uint64_t> l_scom_buffer;
            {
                l_rc = fapi2::getScom( TGT0, 0x501311eull, l_scom_buffer );

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: getScom (0x501311eull)");
                    break;
                }

                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0101042004201800, 0, 56, 0 );
                }

                l_rc = fapi2::putScom(TGT0, 0x501311eull, l_scom_buffer);

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: putScom (0x501311eull)");
                    break;
                }
            }
        }

        {
            fapi2::buffer<uint64_t> l_scom_buffer;
            {
                l_rc = fapi2::getScom( TGT0, 0x5013140ull, l_scom_buffer );

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: getScom (0x5013140ull)");
                    break;
                }

                {
                    l_scom_buffer.insert<uint64_t> (literal_0x010003FF00100020, 0, 64, 0 );
                }

                l_rc = fapi2::putScom(TGT0, 0x5013140ull, l_scom_buffer);

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: putScom (0x5013140ull)");
                    break;
                }
            }
        }

        {
            fapi2::buffer<uint64_t> l_scom_buffer;
            {
                l_rc = fapi2::getScom( TGT0, 0x5013141ull, l_scom_buffer );

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: getScom (0x5013141ull)");
                    break;
                }

                {
                    l_scom_buffer.insert<uint64_t> (literal_0xD8DFB200FFAFFFD7, 0, 64, 0 );
                }

                l_rc = fapi2::putScom(TGT0, 0x5013141ull, l_scom_buffer);

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: putScom (0x5013141ull)");
                    break;
                }
            }
        }

        {
            fapi2::buffer<uint64_t> l_scom_buffer;
            {
                l_rc = fapi2::getScom( TGT0, 0x5013148ull, l_scom_buffer );

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: getScom (0x5013148ull)");
                    break;
                }

                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0008002000002002, 0, 64, 0 );
                }

                l_rc = fapi2::putScom(TGT0, 0x5013148ull, l_scom_buffer);

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: putScom (0x5013148ull)");
                    break;
                }
            }
        }

        {
            fapi2::buffer<uint64_t> l_scom_buffer;
            {
                l_rc = fapi2::getScom( TGT0, 0x5013149ull, l_scom_buffer );

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: getScom (0x5013149ull)");
                    break;
                }

                {
                    l_scom_buffer.insert<uint64_t> (literal_0xEF6437D2DE7DD3FD, 0, 64, 0 );
                }

                l_rc = fapi2::putScom(TGT0, 0x5013149ull, l_scom_buffer);

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: putScom (0x5013149ull)");
                    break;
                }
            }
        }

        {
            fapi2::buffer<uint64_t> l_scom_buffer;
            {
                l_rc = fapi2::getScom( TGT0, 0x5013178ull, l_scom_buffer );

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: getScom (0x5013178ull)");
                    break;
                }

                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0002000410000000, 0, 64, 0 );
                }

                l_rc = fapi2::putScom(TGT0, 0x5013178ull, l_scom_buffer);

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: putScom (0x5013178ull)");
                    break;
                }
            }
        }

        {
            fapi2::buffer<uint64_t> l_scom_buffer;
            {
                l_rc = fapi2::getScom( TGT0, 0x5013179ull, l_scom_buffer );

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: getScom (0x5013179ull)");
                    break;
                }

                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7710CCC3E0000701, 0, 64, 0 );
                }

                l_rc = fapi2::putScom(TGT0, 0x5013179ull, l_scom_buffer);

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: putScom (0x5013179ull)");
                    break;
                }
            }
        }

        {
            fapi2::buffer<uint64_t> l_scom_buffer;
            {
                l_rc = fapi2::getScom( TGT0, 0x5013270ull, l_scom_buffer );

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: getScom (0x5013270ull)");
                    break;
                }

                {
                    l_scom_buffer.insert<uint64_t> (literal_0x00001003000002, 0, 56, 8 );
                }

                l_rc = fapi2::putScom(TGT0, 0x5013270ull, l_scom_buffer);

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: putScom (0x5013270ull)");
                    break;
                }
            }
        }

        {
            fapi2::buffer<uint64_t> l_scom_buffer;
            {
                l_rc = fapi2::getScom( TGT0, 0x5013271ull, l_scom_buffer );

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: getScom (0x5013271ull)");
                    break;
                }

                {
                    l_scom_buffer.insert<uint64_t> (literal_0xFFFFEFFCFFFFFC, 0, 56, 8 );
                }

                l_rc = fapi2::putScom(TGT0, 0x5013271ull, l_scom_buffer);

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: putScom (0x5013271ull)");
                    break;
                }
            }
        }

        {
            fapi2::buffer<uint64_t> l_scom_buffer;
            {
                l_rc = fapi2::getScom( TGT0, 0x5013272ull, l_scom_buffer );

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: getScom (0x5013272ull)");
                    break;
                }

                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0003C018006, 0, 44, 20 );
                }

                l_rc = fapi2::putScom(TGT0, 0x5013272ull, l_scom_buffer);

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: putScom (0x5013272ull)");
                    break;
                }
            }
        }

        {
            fapi2::buffer<uint64_t> l_scom_buffer;
            {
                l_rc = fapi2::getScom( TGT0, 0x5013273ull, l_scom_buffer );

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: getScom (0x5013273ull)");
                    break;
                }

                {
                    l_scom_buffer.insert<uint64_t> (literal_0xFFFDFFEFFFA, 0, 44, 20 );
                }

                l_rc = fapi2::putScom(TGT0, 0x5013273ull, l_scom_buffer);

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: putScom (0x5013273ull)");
                    break;
                }
            }
        }

        {
            fapi2::buffer<uint64_t> l_scom_buffer;
            {
                l_rc = fapi2::getScom( TGT0, 0x5013033ull, l_scom_buffer );

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: getScom (0x5013033ull)");
                    break;
                }

                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0000004000028000, 0, 64, 0 );
                }

                l_rc = fapi2::putScom(TGT0, 0x5013033ull, l_scom_buffer);

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: putScom (0x5013033ull)");
                    break;
                }
            }
        }

        {
            fapi2::buffer<uint64_t> l_scom_buffer;
            {
                l_rc = fapi2::getScom( TGT0, 0x5013036ull, l_scom_buffer );

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: getScom (0x5013036ull)");
                    break;
                }

                {
                    l_scom_buffer.insert<uint64_t> (literal_0x00000000040101C3, 0, 64, 0 );
                }

                l_rc = fapi2::putScom(TGT0, 0x5013036ull, l_scom_buffer);

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: putScom (0x5013036ull)");
                    break;
                }
            }
        }

        {
            fapi2::buffer<uint64_t> l_scom_buffer;
            {
                l_rc = fapi2::getScom( TGT0, 0x5013037ull, l_scom_buffer );

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: getScom (0x5013037ull)");
                    break;
                }

                {
                    l_scom_buffer.insert<uint64_t> (literal_0x9554021F80100E0C, 0, 64, 0 );
                }

                l_rc = fapi2::putScom(TGT0, 0x5013037ull, l_scom_buffer);

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: putScom (0x5013037ull)");
                    break;
                }
            }
        }

        fapi2::ATTR_PROC_FABRIC_ADDR_BAR_MODE_Type l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_ADDR_BAR_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_ADDR_BAR_MODE)");
            break;
        }

        {
            fapi2::buffer<uint64_t> l_scom_buffer;
            {
                l_rc = fapi2::getScom( TGT0, 0x501300aull, l_scom_buffer );

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: getScom (0x501300aull)");
                    break;
                }

                {
                    if ((l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_ADDR_BAR_MODE_SMALL_SYSTEM))
                    {
                        l_scom_buffer.insert<uint64_t> (literal_1, 0, 1, 63 );
                    }
                    else if ((l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_ADDR_BAR_MODE_LARGE_SYSTEM))
                    {
                        l_scom_buffer.insert<uint64_t> (literal_0, 0, 1, 63 );
                    }
                }

                l_rc = fapi2::putScom(TGT0, 0x501300aull, l_scom_buffer);

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: putScom (0x501300aull)");
                    break;
                }
            }
        }

        fapi2::ATTR_PROC_FABRIC_PUMP_MODE_Type l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PUMP_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_PUMP_MODE)");
            break;
        }

        {
            fapi2::buffer<uint64_t> l_scom_buffer;
            {
                l_rc = fapi2::getScom( TGT0, 0x501300aull, l_scom_buffer );

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: getScom (0x501300aull)");
                    break;
                }

                {
                    if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                    {
                        l_scom_buffer.insert<uint64_t> (literal_1, 1, 1, 63 );
                    }
                    else if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_NODE))
                    {
                        l_scom_buffer.insert<uint64_t> (literal_0, 1, 1, 63 );
                    }
                }

                l_rc = fapi2::putScom(TGT0, 0x501300aull, l_scom_buffer);

                if (l_rc)
                {
                    FAPI_ERR("ERROR executing: putScom (0x501300aull)");
                    break;
                }
            }
        }

    }
    while(0);

    return l_rc;
}
