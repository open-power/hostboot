/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/procedures/hwp/initfiles/odyssey_mp_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
#include "odyssey_mp_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0b11111 = 0b11111;
constexpr uint64_t literal_0b10001 = 0b10001;
constexpr uint64_t literal_0b01111 = 0b01111;
constexpr uint64_t literal_0b1 = 0b1;

fapi2::ReturnCode odyssey_mp_scom(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& TGT0)
{
    {
        fapi2::ATTR_MEM_EFF_DIMM_TYPE_Type l_TGT0_ATTR_MEM_EFF_DIMM_TYPE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DIMM_TYPE, TGT0, l_TGT0_ATTR_MEM_EFF_DIMM_TYPE));
        uint64_t l_def_72B_DIMM = ((l_TGT0_ATTR_MEM_EFF_DIMM_TYPE[literal_0] == literal_1)
                                   || (l_TGT0_ATTR_MEM_EFF_DIMM_TYPE[literal_0] == literal_2));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011820ull, l_scom_buffer ));

            if ((l_def_72B_DIMM == literal_0))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_0b11111 );
            }
            else if ((l_def_72B_DIMM == literal_1))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_0b10001 );
            }

            if ((l_def_72B_DIMM == literal_0))
            {
                l_scom_buffer.insert<5, 5, 59, uint64_t>(literal_0b11111 );
            }
            else if ((l_def_72B_DIMM == literal_1))
            {
                l_scom_buffer.insert<5, 5, 59, uint64_t>(literal_0b01111 );
            }

            if ((l_def_72B_DIMM == literal_0))
            {
                l_scom_buffer.insert<10, 5, 59, uint64_t>(literal_0b11111 );
            }
            else if ((l_def_72B_DIMM == literal_1))
            {
                l_scom_buffer.insert<10, 5, 59, uint64_t>(literal_0b10001 );
            }

            if ((l_def_72B_DIMM == literal_0))
            {
                l_scom_buffer.insert<15, 5, 59, uint64_t>(literal_0b11111 );
            }
            else if ((l_def_72B_DIMM == literal_1))
            {
                l_scom_buffer.insert<15, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8011820ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011831ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011831ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
