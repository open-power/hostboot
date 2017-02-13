/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_fbc_ioo_tl_scom.C $ */
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
#include "p9_fbc_ioo_tl_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_3 = 3;
constexpr uint64_t literal_6 = 6;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_5 = 5;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_0xFFFFFFFFFFFFFFFF = 0xFFFFFFFFFFFFFFFF;
constexpr uint64_t literal_0b0101 = 0b0101;

fapi2::ReturnCode p9_fbc_ioo_tl_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, TGT0,
                               l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG));
        fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, TGT0,
                               l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG));
        uint64_t l_def_OBUS3_FBC_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] != literal_0)
                                            || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] != literal_0));
        uint64_t l_def_OBUS2_FBC_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] != literal_0)
                                            || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] != literal_0));
        uint64_t l_def_OBUS1_FBC_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] != literal_0)
                                            || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] != literal_0));
        uint64_t l_def_OBUS0_FBC_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] != literal_0)
                                            || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] != literal_0));
        fapi2::ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_Type l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE, TGT0, l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE));
        uint64_t l_def_NVLINK_ACTIVE = ((((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] ==
                                           fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV)
                                          || (l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                                         || (l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                                        || (l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013803ull, l_scom_buffer ));

            if ((((l_def_OBUS0_FBC_ENABLED || l_def_OBUS1_FBC_ENABLED) || l_def_OBUS2_FBC_ENABLED) || l_def_OBUS3_FBC_ENABLED))
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFFFFFFFFFFFFFFFF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013803ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013823ull, l_scom_buffer ));

            if (l_def_OBUS0_FBC_ENABLED)
            {
                constexpr auto l_PB_IOO_SCOM_PB_CFG_IOO01_IS_LOGICAL_PAIR_ON = 0x1;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_PB_IOO_SCOM_PB_CFG_IOO01_IS_LOGICAL_PAIR_ON );
            }

            if (l_def_OBUS1_FBC_ENABLED)
            {
                constexpr auto l_PB_IOO_SCOM_PB_CFG_IOO23_IS_LOGICAL_PAIR_ON = 0x1;
                l_scom_buffer.insert<1, 1, 63, uint64_t>(l_PB_IOO_SCOM_PB_CFG_IOO23_IS_LOGICAL_PAIR_ON );
            }

            if (l_def_OBUS2_FBC_ENABLED)
            {
                constexpr auto l_PB_IOO_SCOM_PB_CFG_IOO45_IS_LOGICAL_PAIR_ON = 0x1;
                l_scom_buffer.insert<2, 1, 63, uint64_t>(l_PB_IOO_SCOM_PB_CFG_IOO45_IS_LOGICAL_PAIR_ON );
            }

            if (l_def_OBUS3_FBC_ENABLED)
            {
                constexpr auto l_PB_IOO_SCOM_PB_CFG_IOO67_IS_LOGICAL_PAIR_ON = 0x1;
                l_scom_buffer.insert<3, 1, 63, uint64_t>(l_PB_IOO_SCOM_PB_CFG_IOO67_IS_LOGICAL_PAIR_ON );
            }

            if (l_def_NVLINK_ACTIVE)
            {
                constexpr auto l_PB_IOO_SCOM_SEL_03_NPU_NOT_PB_ON = 0x1;
                l_scom_buffer.insert<13, 1, 63, uint64_t>(l_PB_IOO_SCOM_SEL_03_NPU_NOT_PB_ON );
            }

            if (l_def_NVLINK_ACTIVE)
            {
                constexpr auto l_PB_IOO_SCOM_SEL_04_NPU_NOT_PB_ON = 0x1;
                l_scom_buffer.insert<14, 1, 63, uint64_t>(l_PB_IOO_SCOM_SEL_04_NPU_NOT_PB_ON );
            }

            if (l_def_NVLINK_ACTIVE)
            {
                constexpr auto l_PB_IOO_SCOM_SEL_05_NPU_NOT_PB_ON = 0x1;
                l_scom_buffer.insert<15, 1, 63, uint64_t>(l_PB_IOO_SCOM_SEL_05_NPU_NOT_PB_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013823ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013824ull, l_scom_buffer ));

            if (l_def_OBUS0_FBC_ENABLED)
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0101 );
                l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b0101 );
            }

            if (l_def_OBUS0_FBC_ENABLED)
            {
                l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b0101 );
                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b0101 );
            }

            if ((( ! l_def_OBUS0_FBC_ENABLED) && l_def_OBUS1_FBC_ENABLED))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0b0101 );
                l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_0b0101 );
            }

            if ((( ! l_def_OBUS0_FBC_ENABLED) && l_def_OBUS1_FBC_ENABLED))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_0b0101 );
                l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0b0101 );
            }

            if (((( ! l_def_OBUS0_FBC_ENABLED) && ( ! l_def_OBUS1_FBC_ENABLED)) && l_def_OBUS2_FBC_ENABLED))
            {
                l_scom_buffer.insert<32, 4, 60, uint64_t>(literal_0b0101 );
                l_scom_buffer.insert<40, 4, 60, uint64_t>(literal_0b0101 );
            }

            if (((( ! l_def_OBUS0_FBC_ENABLED) && ( ! l_def_OBUS1_FBC_ENABLED)) && l_def_OBUS2_FBC_ENABLED))
            {
                l_scom_buffer.insert<36, 4, 60, uint64_t>(literal_0b0101 );
                l_scom_buffer.insert<44, 4, 60, uint64_t>(literal_0b0101 );
            }

            if ((((( ! l_def_OBUS0_FBC_ENABLED) && ( ! l_def_OBUS1_FBC_ENABLED)) && ( ! l_def_OBUS2_FBC_ENABLED))
                 && l_def_OBUS3_FBC_ENABLED))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0101 );
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0b0101 );
            }

            if ((((( ! l_def_OBUS0_FBC_ENABLED) && ( ! l_def_OBUS1_FBC_ENABLED)) && ( ! l_def_OBUS2_FBC_ENABLED))
                 && l_def_OBUS3_FBC_ENABLED))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0101 );
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0101 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013824ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
