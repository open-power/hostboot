/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_fbc_ioo_dl_scom.C $ */
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
#include "p9_fbc_ioo_dl_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr auto literal_0xFFFFFFFFFFFFFFFF = 0xFFFFFFFFFFFFFFFF;

fapi2::ReturnCode p9_fbc_ioo_dl_scom(const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& TGT0)
{
    {
        fapi2::ATTR_OPTICS_CONFIG_MODE_Type l_TGT0_ATTR_OPTICS_CONFIG_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OPTICS_CONFIG_MODE, TGT0, l_TGT0_ATTR_OPTICS_CONFIG_MODE));
        auto l_def_OBUS_FBC_ENABLED = (l_TGT0_ATTR_OPTICS_CONFIG_MODE == ENUM_ATTR_OPTICS_CONFIG_MODE_SMP);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x9010803ull, l_scom_buffer ));

            if (l_def_OBUS_FBC_ENABLED)
            {
                l_scom_buffer.insert<uint64_t> (literal_0xFFFFFFFFFFFFFFFF, 0, 64, 0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x9010803ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x901080aull, l_scom_buffer ));

            if (l_def_OBUS_FBC_ENABLED)
            {
                constexpr auto l_PB_IOO_LL0_CONFIG_LINK_PAIR_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_PB_IOO_LL0_CONFIG_LINK_PAIR_ON, 0, 1, 63 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x901080aull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
