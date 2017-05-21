/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9n_ddrphy_scom.C $ */
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
#include "p9n_ddrphy_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0x0120 = 0x0120;
constexpr uint64_t literal_0x8100 = 0x8100;
constexpr uint64_t literal_0x8000 = 0x8000;
constexpr uint64_t literal_0xffe0 = 0xffe0;
constexpr uint64_t literal_0x6740 = 0x6740;
constexpr uint64_t literal_0x0402 = 0x0402;
constexpr uint64_t literal_0x6000 = 0x6000;
constexpr uint64_t literal_0x4000 = 0x4000;
constexpr uint64_t literal_0x7F7F = 0x7F7F;
constexpr uint64_t literal_0x0800 = 0x0800;
constexpr uint64_t literal_0x2020 = 0x2020;
constexpr uint64_t literal_0xFFFF = 0xFFFF;
constexpr uint64_t literal_0x5000 = 0x5000;
constexpr uint64_t literal_0x4040 = 0x4040;
constexpr uint64_t literal_0xE058 = 0xE058;
constexpr uint64_t literal_0x0202 = 0x0202;

fapi2::ReturnCode p9n_ddrphy_scom(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& TGT0,
                                  const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT1, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT1, l_chip_ec));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x800000030701103full, l_scom_buffer ));

                if (( true ))
                {
                    l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0120 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x800000030701103full, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000240701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000240701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000250701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000250701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000260701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000260701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000270701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000270701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000280701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000280701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000290701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000290701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000002a0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0x6740 );
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0x6740 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000002a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000002b0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0x6740 );
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0x6740 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000002b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000002c0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 6, 48, uint64_t>(literal_0x0402 );
                l_scom_buffer.insert<56, 7, 56, uint64_t>(literal_0x0402 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000002c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000002d0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 6, 48, uint64_t>(literal_0x0402 );
                l_scom_buffer.insert<56, 7, 56, uint64_t>(literal_0x0402 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000002d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000740701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<49, 7, 49, uint64_t>(literal_0x6000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000740701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000750701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0x4000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000750701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000780701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x7F7F );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000780701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000a40701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 7, 48, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<56, 2, 56, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000a40701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000a50701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 7, 48, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<56, 2, 56, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000a50701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000a60701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 5, 48, uint64_t>(literal_0x0800 );
                l_scom_buffer.insert<56, 6, 56, uint64_t>(literal_0x0800 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000a60701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000a70701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 5, 48, uint64_t>(literal_0x0800 );
                l_scom_buffer.insert<56, 6, 56, uint64_t>(literal_0x0800 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000a70701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000a80701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000a80701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000a90701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000a90701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000aa0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000aa0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000ab0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000ab0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000ac0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 11, 48, uint64_t>(literal_0x2020 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000ac0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000ad0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 11, 48, uint64_t>(literal_0x2020 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000ad0701103full, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x800004030701103full, l_scom_buffer ));

                if (( true ))
                {
                    l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0120 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x800004030701103full, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004240701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004240701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004250701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004250701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004260701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004260701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004270701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004270701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004280701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004280701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004290701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004290701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000042a0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0x6740 );
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0x6740 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000042a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000042b0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0x6740 );
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0x6740 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000042b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000042c0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 6, 48, uint64_t>(literal_0x0402 );
                l_scom_buffer.insert<56, 7, 56, uint64_t>(literal_0x0402 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000042c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000042d0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 6, 48, uint64_t>(literal_0x0402 );
                l_scom_buffer.insert<56, 7, 56, uint64_t>(literal_0x0402 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000042d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004740701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<49, 7, 49, uint64_t>(literal_0x6000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004740701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004750701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0x4000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004750701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004780701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x7F7F );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004780701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004a40701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 7, 48, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<56, 2, 56, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004a40701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004a50701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 7, 48, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<56, 2, 56, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004a50701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004a60701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 5, 48, uint64_t>(literal_0x0800 );
                l_scom_buffer.insert<56, 6, 56, uint64_t>(literal_0x0800 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004a60701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004a70701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 5, 48, uint64_t>(literal_0x0800 );
                l_scom_buffer.insert<56, 6, 56, uint64_t>(literal_0x0800 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004a70701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004a80701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004a80701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004a90701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004a90701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004aa0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004aa0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004ab0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004ab0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004ac0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 11, 48, uint64_t>(literal_0x2020 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004ac0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004ad0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 11, 48, uint64_t>(literal_0x2020 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004ad0701103full, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x800008030701103full, l_scom_buffer ));

                if (( true ))
                {
                    l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0120 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x800008030701103full, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008240701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008240701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008250701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008250701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008260701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008260701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008270701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008270701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008280701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008280701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008290701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008290701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000082a0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0x6740 );
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0x6740 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000082a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000082b0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0x6740 );
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0x6740 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000082b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000082c0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 6, 48, uint64_t>(literal_0x0402 );
                l_scom_buffer.insert<56, 7, 56, uint64_t>(literal_0x0402 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000082c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000082d0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 6, 48, uint64_t>(literal_0x0402 );
                l_scom_buffer.insert<56, 7, 56, uint64_t>(literal_0x0402 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000082d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008740701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<49, 7, 49, uint64_t>(literal_0x6000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008740701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008750701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0x4000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008750701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008780701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x7F7F );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008780701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008a40701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 7, 48, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<56, 2, 56, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008a40701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008a50701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 7, 48, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<56, 2, 56, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008a50701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008a60701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 5, 48, uint64_t>(literal_0x0800 );
                l_scom_buffer.insert<56, 6, 56, uint64_t>(literal_0x0800 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008a60701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008a70701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 5, 48, uint64_t>(literal_0x0800 );
                l_scom_buffer.insert<56, 6, 56, uint64_t>(literal_0x0800 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008a70701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008a80701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008a80701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008a90701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008a90701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008aa0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008aa0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008ab0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008ab0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008ac0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 11, 48, uint64_t>(literal_0x2020 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008ac0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008ad0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 11, 48, uint64_t>(literal_0x2020 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008ad0701103full, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x80000c030701103full, l_scom_buffer ));

                if (( true ))
                {
                    l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0120 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x80000c030701103full, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c240701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c240701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c250701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c250701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c260701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c260701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c270701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c270701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c280701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c280701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c290701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c290701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c2a0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0x6740 );
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0x6740 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c2a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c2b0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0x6740 );
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0x6740 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c2b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c2c0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 6, 48, uint64_t>(literal_0x0402 );
                l_scom_buffer.insert<56, 7, 56, uint64_t>(literal_0x0402 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c2c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c2d0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 6, 48, uint64_t>(literal_0x0402 );
                l_scom_buffer.insert<56, 7, 56, uint64_t>(literal_0x0402 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c2d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c740701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<49, 7, 49, uint64_t>(literal_0x6000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c740701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c750701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0x4000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c750701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c780701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x7F7F );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c780701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000ca40701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 7, 48, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<56, 2, 56, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000ca40701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000ca50701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 7, 48, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<56, 2, 56, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000ca50701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000ca60701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 5, 48, uint64_t>(literal_0x0800 );
                l_scom_buffer.insert<56, 6, 56, uint64_t>(literal_0x0800 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000ca60701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000ca70701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 5, 48, uint64_t>(literal_0x0800 );
                l_scom_buffer.insert<56, 6, 56, uint64_t>(literal_0x0800 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000ca70701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000ca80701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000ca80701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000ca90701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000ca90701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000caa0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000caa0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000cab0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000cab0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000cac0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 11, 48, uint64_t>(literal_0x2020 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000cac0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000cad0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 11, 48, uint64_t>(literal_0x2020 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000cad0701103full, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x800010030701103full, l_scom_buffer ));

                if (( true ))
                {
                    l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0120 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x800010030701103full, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010240701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010240701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010250701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010250701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010260701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010260701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010270701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010270701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010280701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010280701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010290701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010290701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000102a0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0x6740 );
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0x6740 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000102a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000102b0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0x6740 );
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0x6740 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000102b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000102c0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 6, 48, uint64_t>(literal_0x0402 );
                l_scom_buffer.insert<56, 7, 56, uint64_t>(literal_0x0402 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000102c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000102d0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 6, 48, uint64_t>(literal_0x0402 );
                l_scom_buffer.insert<56, 7, 56, uint64_t>(literal_0x0402 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000102d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010740701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<49, 7, 49, uint64_t>(literal_0x6000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010740701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010750701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0x4000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010750701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010780701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x7F7F );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010780701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010a40701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 7, 48, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<56, 2, 56, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010a40701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010a50701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 7, 48, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<56, 2, 56, uint64_t>(literal_0x8000 );
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010a50701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010a60701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 5, 48, uint64_t>(literal_0x0800 );
                l_scom_buffer.insert<56, 6, 56, uint64_t>(literal_0x0800 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010a60701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010a70701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 5, 48, uint64_t>(literal_0x0800 );
                l_scom_buffer.insert<56, 6, 56, uint64_t>(literal_0x0800 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010a70701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010a80701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010a80701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010a90701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0x8000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010a90701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010aa0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010aa0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010ab0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 15, 48, uint64_t>(literal_0xffe0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010ab0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010ac0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 11, 48, uint64_t>(literal_0x2020 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010ac0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010ad0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 11, 48, uint64_t>(literal_0x2020 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010ad0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800040000701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800040000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800044000701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800044000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800044010701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x5000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800044010701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800044050701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x4040 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800044050701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800044070701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x4040 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800044070701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800048000701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800048000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80004c000701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80004c000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800080310701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xE058 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800080310701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800080330701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x6000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800080330701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000803d0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0x6740 );
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0x6740 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000803d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800084310701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xE058 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800084310701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800084330701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x6000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800084330701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000843d0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0x6740 );
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0x6740 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000843d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00c0701103full, l_scom_buffer ));

            if (( true ))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0202 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00c0701103full, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
