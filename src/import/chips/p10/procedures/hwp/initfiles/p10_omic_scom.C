/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_omic_scom.C $ */
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
#include "p10_omic_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0xFFFFFFFFFFFFFFFF = 0xFFFFFFFFFFFFFFFF;
constexpr uint64_t literal_0x0000000000000000 = 0x0000000000000000;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0b0001 = 0b0001;
constexpr uint64_t literal_0b101 = 0b101;
constexpr uint64_t literal_0b100 = 0b100;
constexpr uint64_t literal_0b00001 = 0b00001;
constexpr uint64_t literal_0b011 = 0b011;
constexpr uint64_t literal_0b00101 = 0b00101;
constexpr uint64_t literal_0b0100 = 0b0100;
constexpr uint64_t literal_0b0010 = 0b0010;
constexpr uint64_t literal_0b00011 = 0b00011;

fapi2::ReturnCode p10_omic_scom(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& TGT0,
                                const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT2)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT2, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT2, l_chip_ec));
        fapi2::ATTR_IS_SIMULATION_Type l_TGT1_ATTR_IS_SIMULATION;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, TGT1, l_TGT1_ATTR_IS_SIMULATION));
        uint64_t l_def_IS_SIM = (l_TGT1_ATTR_IS_SIMULATION == literal_1);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc011403ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 62, 2, uint64_t>(literal_0xFFFFFFFFFFFFFFFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc011403ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc011406ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 62, 2, uint64_t>(literal_0x0000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc011406ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc011407ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 62, 2, uint64_t>(literal_0xFFFFFFFFFFFFFFFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc011407ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008204010012c3full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0001 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0001 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0b0001 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0001 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8008204010012c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008284010012c3full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b101 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_0b00001 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0b00001 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8008284010012c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008304010012c3full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b011 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_0b00001 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0b00101 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8008304010012c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008404010012c3full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00001 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8008404010012c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008484010012c3full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0001 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0001 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0b0001 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8008484010012c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008784010012c3full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0001 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0001 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0b0001 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0010 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8008784010012c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008804010012c3full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b101 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_0b00001 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0b00001 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8008804010012c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008884010012c3full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b011 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_0b00001 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0b00101 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8008884010012c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008a04010012c3full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 5, 59, uint64_t>(literal_0b00011 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8008a04010012c3full, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
