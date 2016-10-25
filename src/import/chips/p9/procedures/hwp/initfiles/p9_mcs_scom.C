/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_mcs_scom.C $  */
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
#include "p9_mcs_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0b0111 = 0b0111;
constexpr uint64_t literal_0 = 0;

fapi2::ReturnCode p9_mcs_scom(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& TGT0)
{
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010810ull, l_scom_buffer ));

            l_scom_buffer.insert<46, 4, 60, uint64_t>(literal_0b0111 );
            l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5010810ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010812ull, l_scom_buffer ));

            constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT_ON = 0x1;
            l_scom_buffer.insert<10, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5010812ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
