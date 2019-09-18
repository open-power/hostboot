/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_nmmu_scom.C $ */
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
#include "p10_nmmu_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0x0024700000000000 = 0x0024700000000000;
constexpr uint64_t literal_0x0000000000000000 = 0x0000000000000000;
constexpr uint64_t literal_0x04FF000000000000 = 0x04FF000000000000;
constexpr uint64_t literal_0x0400FAFC00CB0000 = 0x0400FAFC00CB0000;
constexpr uint64_t literal_0x9CFF000300440000 = 0x9CFF000300440000;

fapi2::ReturnCode p10_nmmu_scom(const fapi2::Target<fapi2::TARGET_TYPE_NMMU>& TGT0,
                                const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010c03ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 20, 44, uint64_t>(literal_0x0024700000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2010c03ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010c06ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 20, 44, uint64_t>(literal_0x0000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2010c06ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010c07ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 20, 44, uint64_t>(literal_0x04FF000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2010c07ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010c43ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 46, 2, uint64_t>(literal_0x0400FAFC00CB0000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2010c43ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010c46ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 46, 2, uint64_t>(literal_0x0000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2010c46ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010c47ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 46, 2, uint64_t>(literal_0x9CFF000300440000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2010c47ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
