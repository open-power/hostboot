/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_pau_scom.C $ */
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
#include "p10_pau_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;


fapi2::ReturnCode p10_pau_scom(const fapi2::Target<fapi2::TARGET_TYPE_PAU>& TGT0,
                               const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT2)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT1, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT1, l_chip_ec));
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T0_Type l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T0, TGT2, l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T0));
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T1_Type l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T1, TGT2, l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T1));
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T2_Type l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T2, TGT2, l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T2));
        fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T1_Type l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T1, TGT2, l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T1));
        fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T2_Type l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T2, TGT2, l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T2));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010802ull, l_scom_buffer ));

            l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T0 );
            l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T1 );
            l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T2 );
            l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
            l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010802ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010862ull, l_scom_buffer ));

            l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T0 );
            l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T1 );
            l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T2 );
            l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
            l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010862ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x100108c2ull, l_scom_buffer ));

            l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T0 );
            l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T1 );
            l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T2 );
            l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
            l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x100108c2ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10010922ull, l_scom_buffer ));

            l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T0 );
            l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T1 );
            l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_READ_CYCLES_T2 );
            l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
            l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x10010922ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
