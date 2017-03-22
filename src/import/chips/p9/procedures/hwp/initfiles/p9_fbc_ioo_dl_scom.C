/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_fbc_ioo_dl_scom.C $ */
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
#include "p9_fbc_ioo_dl_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;


fapi2::ReturnCode p9_fbc_ioo_dl_scom(const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& TGT0,
                                     const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT1, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT1, l_chip_ec));
        fapi2::ATTR_OPTICS_CONFIG_MODE_Type l_TGT0_ATTR_OPTICS_CONFIG_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OPTICS_CONFIG_MODE, TGT0, l_TGT0_ATTR_OPTICS_CONFIG_MODE));
        uint64_t l_def_OBUS_FBC_ENABLED = (l_TGT0_ATTR_OPTICS_CONFIG_MODE == fapi2::ENUM_ATTR_OPTICS_CONFIG_MODE_SMP);
        uint64_t l_def_OBUS_NV_ENABLED = (l_TGT0_ATTR_OPTICS_CONFIG_MODE == fapi2::ENUM_ATTR_OPTICS_CONFIG_MODE_NV);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x901080aull, l_scom_buffer ));

            if (l_def_OBUS_FBC_ENABLED)
            {
                constexpr auto l_PB_IOO_LL0_CONFIG_LINK_PAIR_ON = 0x1;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_LINK_PAIR_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x901080aull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x901080cull, l_scom_buffer ));

                if (l_def_OBUS_NV_ENABLED)
                {
                    constexpr auto l_PB_IOO_LL0_CONFIG_NV0_NPU_ENABLED_ON = 0x1;
                    l_scom_buffer.insert<61, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_NV0_NPU_ENABLED_ON );
                    constexpr auto l_PB_IOO_LL0_CONFIG_NV1_NPU_ENABLED_ON = 0x1;
                    l_scom_buffer.insert<62, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_NV1_NPU_ENABLED_ON );
                    constexpr auto l_PB_IOO_LL0_CONFIG_NV2_NPU_ENABLED_ON = 0x1;
                    l_scom_buffer.insert<63, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_NV2_NPU_ENABLED_ON );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x901080cull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x901080full, l_scom_buffer ));

                if (l_def_OBUS_NV_ENABLED)
                {
                    constexpr auto l_PB_IOO_LL0_CONFIG_NV0_NPU_ENABLED_ON = 0x1;
                    l_scom_buffer.insert<61, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_NV0_NPU_ENABLED_ON );
                    constexpr auto l_PB_IOO_LL0_CONFIG_NV1_NPU_ENABLED_ON = 0x1;
                    l_scom_buffer.insert<62, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_NV1_NPU_ENABLED_ON );
                    constexpr auto l_PB_IOO_LL0_CONFIG_NV2_NPU_ENABLED_ON = 0x1;
                    l_scom_buffer.insert<63, 1, 63, uint64_t>(l_PB_IOO_LL0_CONFIG_NV2_NPU_ENABLED_ON );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x901080full, l_scom_buffer));
            }
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
