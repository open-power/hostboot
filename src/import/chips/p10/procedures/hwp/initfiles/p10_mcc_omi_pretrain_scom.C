/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_mcc_omi_pretrain_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#include "p10_mcc_omi_pretrain_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0b100000 = 0b100000;
constexpr uint64_t literal_0b0001 = 0b0001;
constexpr uint64_t literal_0b1000000 = 0b1000000;
constexpr uint64_t literal_0b011000 = 0b011000;

fapi2::ReturnCode p10_mcc_omi_pretrain_scom(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& TGT0,
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010d0aull, l_scom_buffer ));

            l_scom_buffer.insert<2, 6, 58, uint64_t>(literal_0b100000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b0001 );
            l_scom_buffer.insert<17, 7, 57, uint64_t>(literal_0b1000000 );
            l_scom_buffer.insert<50, 6, 58, uint64_t>(literal_0b011000 );
            l_scom_buffer.insert<58, 6, 58, uint64_t>(literal_0b011000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc010d0aull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
