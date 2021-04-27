/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_fbc_ioo_tl_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0x1 = 0x1;
constexpr uint64_t literal_0x40 = 0x40;
constexpr uint64_t literal_12 = 12;
constexpr uint64_t literal_10 = 10;
constexpr uint64_t literal_154 = 154;
constexpr uint64_t literal_0x36 = 0x36;
constexpr uint64_t literal_0x37 = 0x37;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_0x2A = 0x2A;
constexpr uint64_t literal_0x2C = 0x2C;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_5 = 5;
constexpr uint64_t literal_74 = 74;
constexpr uint64_t literal_0x1B = 0x1B;
constexpr uint64_t literal_0x1C = 0x1C;
constexpr uint64_t literal_6 = 6;
constexpr uint64_t literal_95 = 95;
constexpr uint64_t literal_0x22 = 0x22;
constexpr uint64_t literal_0x24 = 0x24;
constexpr uint64_t literal_0x10 = 0x10;
constexpr uint64_t literal_0x1F = 0x1F;
constexpr uint64_t literal_0x3C = 0x3C;
constexpr uint64_t literal_0x0E = 0x0E;
constexpr uint64_t literal_0b0001 = 0b0001;
constexpr uint64_t literal_0b0100 = 0b0100;

fapi2::ReturnCode p9_fbc_ioo_tl_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                                     const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
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
        uint64_t l_def_OBUS0_FBC_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                                             fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE)
                                            || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                                                fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE));
        fapi2::ATTR_FREQ_A_MHZ_Type l_TGT1_ATTR_FREQ_A_MHZ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_A_MHZ, TGT1, l_TGT1_ATTR_FREQ_A_MHZ));
        fapi2::ATTR_FREQ_PB_MHZ_Type l_TGT1_ATTR_FREQ_PB_MHZ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PB_MHZ, TGT1, l_TGT1_ATTR_FREQ_PB_MHZ));
        uint64_t l_def_LO_LIMIT_R = ((l_TGT1_ATTR_FREQ_PB_MHZ * literal_10) > (l_TGT1_ATTR_FREQ_A_MHZ * literal_12));
        uint64_t l_def_OBUS0_LO_LIMIT_D = (l_TGT1_ATTR_FREQ_A_MHZ * literal_10);
        uint64_t l_def_OBUS0_LO_LIMIT_N = (l_TGT1_ATTR_FREQ_PB_MHZ * literal_154);
        uint64_t l_def_OBUS1_FBC_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                                             fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE)
                                            || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                                                fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE));
        uint64_t l_def_OBUS1_LO_LIMIT_D = l_TGT1_ATTR_FREQ_A_MHZ;
        uint64_t l_def_OBUS1_LO_LIMIT_N = (l_TGT1_ATTR_FREQ_PB_MHZ * literal_12);
        uint64_t l_def_OBUS2_FBC_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                                             fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE)
                                            || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                                                fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE));
        uint64_t l_def_OBUS2_LO_LIMIT_D = (l_TGT1_ATTR_FREQ_A_MHZ * literal_10);
        uint64_t l_def_OBUS2_LO_LIMIT_N = (l_TGT1_ATTR_FREQ_PB_MHZ * literal_74);
        uint64_t l_def_OBUS3_FBC_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                                             fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE)
                                            || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                                                fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE));
        uint64_t l_def_OBUS3_LO_LIMIT_D = (l_TGT1_ATTR_FREQ_A_MHZ * literal_10);
        uint64_t l_def_OBUS3_LO_LIMIT_N = (l_TGT1_ATTR_FREQ_PB_MHZ * literal_95);
        fapi2::ATTR_PROC_FABRIC_SMP_OPTICS_MODE_Type l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SMP_OPTICS_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE));
        uint64_t l_def_OPTICS_IS_A_BUS = (l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE ==
                                          fapi2::ENUM_ATTR_PROC_FABRIC_SMP_OPTICS_MODE_OPTICS_IS_A_BUS);
        uint64_t l_def_OB0_IS_PAIRED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] ==
                                         fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE)
                                        || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE));
        uint64_t l_def_OB1_IS_PAIRED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] ==
                                         fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE)
                                        || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE));
        uint64_t l_def_OB2_IS_PAIRED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] ==
                                         fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE)
                                        || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE));
        uint64_t l_def_OB3_IS_PAIRED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] ==
                                         fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE)
                                        || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE));
        fapi2::ATTR_PROC_NPU_REGION_ENABLED_Type l_TGT0_ATTR_PROC_NPU_REGION_ENABLED;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NPU_REGION_ENABLED, TGT0, l_TGT0_ATTR_PROC_NPU_REGION_ENABLED));
        fapi2::ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_Type l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE, TGT0, l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE));
        uint64_t l_def_NVLINK_ACTIVE = ((((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] ==
                                           fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV)
                                          || (l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                                         || (l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                                        || ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV)
                                            && l_TGT0_ATTR_PROC_NPU_REGION_ENABLED));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501380aull, l_scom_buffer ));

            if (( ! l_def_OBUS0_FBC_ENABLED))
            {
                constexpr auto l_PB_IOO_SCOM_A0_MODE_BLOCKED = 0xf;
                l_scom_buffer.insert<20, 1, 60, uint64_t>(l_PB_IOO_SCOM_A0_MODE_BLOCKED );
                l_scom_buffer.insert<25, 1, 61, uint64_t>(l_PB_IOO_SCOM_A0_MODE_BLOCKED );
                l_scom_buffer.insert<52, 1, 62, uint64_t>(l_PB_IOO_SCOM_A0_MODE_BLOCKED );
                l_scom_buffer.insert<57, 1, 63, uint64_t>(l_PB_IOO_SCOM_A0_MODE_BLOCKED );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOO_SCOM_A0_MODE_NORMAL = 0x0;
                l_scom_buffer.insert<20, 1, 60, uint64_t>(l_PB_IOO_SCOM_A0_MODE_NORMAL );
                l_scom_buffer.insert<25, 1, 61, uint64_t>(l_PB_IOO_SCOM_A0_MODE_NORMAL );
                l_scom_buffer.insert<52, 1, 62, uint64_t>(l_PB_IOO_SCOM_A0_MODE_NORMAL );
                l_scom_buffer.insert<57, 1, 63, uint64_t>(l_PB_IOO_SCOM_A0_MODE_NORMAL );
            }

            if (l_def_OBUS0_FBC_ENABLED)
            {
                l_scom_buffer.insert<22, 2, 62, uint64_t>(literal_0x1 );
            }

            if (l_def_OBUS0_FBC_ENABLED)
            {
                l_scom_buffer.insert<12, 8, 56, uint64_t>(literal_0x40 );
            }

            constexpr auto l_PB_IOO_SCOM_FP0_DISABLE_GATHERING_ON = 0x1;
            l_scom_buffer.insert<1, 1, 63, uint64_t>(l_PB_IOO_SCOM_FP0_DISABLE_GATHERING_ON );

            if ((l_def_OBUS0_FBC_ENABLED && (l_def_LO_LIMIT_R == literal_1)))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x36 - (l_def_OBUS0_LO_LIMIT_N / l_def_OBUS0_LO_LIMIT_D)) );
            }
            else if (l_def_OBUS0_FBC_ENABLED)
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x37 - (l_def_OBUS0_LO_LIMIT_N / l_def_OBUS0_LO_LIMIT_D)) );
            }

            if (l_def_OBUS0_FBC_ENABLED)
            {
                l_scom_buffer.insert<44, 8, 56, uint64_t>(literal_0x40 );
            }

            constexpr auto l_PB_IOO_SCOM_FP1_DISABLE_GATHERING_ON = 0x1;
            l_scom_buffer.insert<33, 1, 63, uint64_t>(l_PB_IOO_SCOM_FP1_DISABLE_GATHERING_ON );

            if ((l_def_OBUS0_FBC_ENABLED && (l_def_LO_LIMIT_R == literal_1)))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x36 - (l_def_OBUS0_LO_LIMIT_N / l_def_OBUS0_LO_LIMIT_D)) );
            }
            else if (l_def_OBUS0_FBC_ENABLED)
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x37 - (l_def_OBUS0_LO_LIMIT_N / l_def_OBUS0_LO_LIMIT_D)) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x501380aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501380bull, l_scom_buffer ));

            if (( ! l_def_OBUS1_FBC_ENABLED))
            {
                constexpr auto l_PB_IOO_SCOM_A1_MODE_BLOCKED = 0xf;
                l_scom_buffer.insert<20, 1, 60, uint64_t>(l_PB_IOO_SCOM_A1_MODE_BLOCKED );
                l_scom_buffer.insert<25, 1, 61, uint64_t>(l_PB_IOO_SCOM_A1_MODE_BLOCKED );
                l_scom_buffer.insert<52, 1, 62, uint64_t>(l_PB_IOO_SCOM_A1_MODE_BLOCKED );
                l_scom_buffer.insert<57, 1, 63, uint64_t>(l_PB_IOO_SCOM_A1_MODE_BLOCKED );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOO_SCOM_A1_MODE_NORMAL = 0x0;
                l_scom_buffer.insert<20, 1, 60, uint64_t>(l_PB_IOO_SCOM_A1_MODE_NORMAL );
                l_scom_buffer.insert<25, 1, 61, uint64_t>(l_PB_IOO_SCOM_A1_MODE_NORMAL );
                l_scom_buffer.insert<52, 1, 62, uint64_t>(l_PB_IOO_SCOM_A1_MODE_NORMAL );
                l_scom_buffer.insert<57, 1, 63, uint64_t>(l_PB_IOO_SCOM_A1_MODE_NORMAL );
            }

            if (l_def_OBUS1_FBC_ENABLED)
            {
                l_scom_buffer.insert<22, 2, 62, uint64_t>(literal_0x1 );
            }

            if (l_def_OBUS1_FBC_ENABLED)
            {
                l_scom_buffer.insert<12, 8, 56, uint64_t>(literal_0x40 );
            }

            constexpr auto l_PB_IOO_SCOM_FP2_DISABLE_GATHERING_ON = 0x1;
            l_scom_buffer.insert<1, 1, 63, uint64_t>(l_PB_IOO_SCOM_FP2_DISABLE_GATHERING_ON );

            if ((l_def_OBUS1_FBC_ENABLED && (l_def_LO_LIMIT_R == literal_1)))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x2A - (l_def_OBUS1_LO_LIMIT_N / l_def_OBUS1_LO_LIMIT_D)) );
            }
            else if (l_def_OBUS1_FBC_ENABLED)
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x2C - (l_def_OBUS1_LO_LIMIT_N / l_def_OBUS1_LO_LIMIT_D)) );
            }

            if (l_def_OBUS1_FBC_ENABLED)
            {
                l_scom_buffer.insert<44, 8, 56, uint64_t>(literal_0x40 );
            }

            constexpr auto l_PB_IOO_SCOM_FP3_DISABLE_GATHERING_ON = 0x1;
            l_scom_buffer.insert<33, 1, 63, uint64_t>(l_PB_IOO_SCOM_FP3_DISABLE_GATHERING_ON );

            if ((l_def_OBUS1_FBC_ENABLED && (l_def_LO_LIMIT_R == literal_1)))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x2A - (l_def_OBUS1_LO_LIMIT_N / l_def_OBUS1_LO_LIMIT_D)) );
            }
            else if (l_def_OBUS1_FBC_ENABLED)
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x2C - (l_def_OBUS1_LO_LIMIT_N / l_def_OBUS1_LO_LIMIT_D)) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x501380bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501380cull, l_scom_buffer ));

            if (( ! l_def_OBUS2_FBC_ENABLED))
            {
                constexpr auto l_PB_IOO_SCOM_A2_MODE_BLOCKED = 0xf;
                l_scom_buffer.insert<20, 1, 60, uint64_t>(l_PB_IOO_SCOM_A2_MODE_BLOCKED );
                l_scom_buffer.insert<25, 1, 61, uint64_t>(l_PB_IOO_SCOM_A2_MODE_BLOCKED );
                l_scom_buffer.insert<52, 1, 62, uint64_t>(l_PB_IOO_SCOM_A2_MODE_BLOCKED );
                l_scom_buffer.insert<57, 1, 63, uint64_t>(l_PB_IOO_SCOM_A2_MODE_BLOCKED );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOO_SCOM_A2_MODE_NORMAL = 0x0;
                l_scom_buffer.insert<20, 1, 60, uint64_t>(l_PB_IOO_SCOM_A2_MODE_NORMAL );
                l_scom_buffer.insert<25, 1, 61, uint64_t>(l_PB_IOO_SCOM_A2_MODE_NORMAL );
                l_scom_buffer.insert<52, 1, 62, uint64_t>(l_PB_IOO_SCOM_A2_MODE_NORMAL );
                l_scom_buffer.insert<57, 1, 63, uint64_t>(l_PB_IOO_SCOM_A2_MODE_NORMAL );
            }

            if (l_def_OBUS2_FBC_ENABLED)
            {
                l_scom_buffer.insert<22, 2, 62, uint64_t>(literal_0x1 );
            }

            if (l_def_OBUS2_FBC_ENABLED)
            {
                l_scom_buffer.insert<12, 8, 56, uint64_t>(literal_0x40 );
            }

            constexpr auto l_PB_IOO_SCOM_FP4_DISABLE_GATHERING_ON = 0x1;
            l_scom_buffer.insert<1, 1, 63, uint64_t>(l_PB_IOO_SCOM_FP4_DISABLE_GATHERING_ON );

            if ((l_def_OBUS2_FBC_ENABLED && (l_def_LO_LIMIT_R == literal_1)))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x1B - (l_def_OBUS2_LO_LIMIT_N / l_def_OBUS2_LO_LIMIT_D)) );
            }
            else if (l_def_OBUS2_FBC_ENABLED)
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x1C - (l_def_OBUS2_LO_LIMIT_N / l_def_OBUS2_LO_LIMIT_D)) );
            }

            if (l_def_OBUS2_FBC_ENABLED)
            {
                l_scom_buffer.insert<44, 8, 56, uint64_t>(literal_0x40 );
            }

            constexpr auto l_PB_IOO_SCOM_FP5_DISABLE_GATHERING_ON = 0x1;
            l_scom_buffer.insert<33, 1, 63, uint64_t>(l_PB_IOO_SCOM_FP5_DISABLE_GATHERING_ON );

            if ((l_def_OBUS2_FBC_ENABLED && (l_def_LO_LIMIT_R == literal_1)))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x1B - (l_def_OBUS2_LO_LIMIT_N / l_def_OBUS2_LO_LIMIT_D)) );
            }
            else if (l_def_OBUS2_FBC_ENABLED)
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x1C - (l_def_OBUS2_LO_LIMIT_N / l_def_OBUS2_LO_LIMIT_D)) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x501380cull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501380dull, l_scom_buffer ));

            if (( ! l_def_OBUS3_FBC_ENABLED))
            {
                constexpr auto l_PB_IOO_SCOM_A3_MODE_BLOCKED = 0xf;
                l_scom_buffer.insert<20, 1, 60, uint64_t>(l_PB_IOO_SCOM_A3_MODE_BLOCKED );
                l_scom_buffer.insert<25, 1, 61, uint64_t>(l_PB_IOO_SCOM_A3_MODE_BLOCKED );
                l_scom_buffer.insert<52, 1, 62, uint64_t>(l_PB_IOO_SCOM_A3_MODE_BLOCKED );
                l_scom_buffer.insert<57, 1, 63, uint64_t>(l_PB_IOO_SCOM_A3_MODE_BLOCKED );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOO_SCOM_A3_MODE_NORMAL = 0x0;
                l_scom_buffer.insert<20, 1, 60, uint64_t>(l_PB_IOO_SCOM_A3_MODE_NORMAL );
                l_scom_buffer.insert<25, 1, 61, uint64_t>(l_PB_IOO_SCOM_A3_MODE_NORMAL );
                l_scom_buffer.insert<52, 1, 62, uint64_t>(l_PB_IOO_SCOM_A3_MODE_NORMAL );
                l_scom_buffer.insert<57, 1, 63, uint64_t>(l_PB_IOO_SCOM_A3_MODE_NORMAL );
            }

            if (l_def_OBUS3_FBC_ENABLED)
            {
                l_scom_buffer.insert<22, 2, 62, uint64_t>(literal_0x1 );
            }

            if (l_def_OBUS3_FBC_ENABLED)
            {
                l_scom_buffer.insert<12, 8, 56, uint64_t>(literal_0x40 );
            }

            constexpr auto l_PB_IOO_SCOM_FP6_DISABLE_GATHERING_ON = 0x1;
            l_scom_buffer.insert<1, 1, 63, uint64_t>(l_PB_IOO_SCOM_FP6_DISABLE_GATHERING_ON );

            if ((l_def_OBUS3_FBC_ENABLED && (l_def_LO_LIMIT_R == literal_1)))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x22 - (l_def_OBUS3_LO_LIMIT_N / l_def_OBUS3_LO_LIMIT_D)) );
            }
            else if (l_def_OBUS3_FBC_ENABLED)
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x24 - (l_def_OBUS3_LO_LIMIT_N / l_def_OBUS3_LO_LIMIT_D)) );
            }

            if (l_def_OBUS3_FBC_ENABLED)
            {
                l_scom_buffer.insert<44, 8, 56, uint64_t>(literal_0x40 );
            }

            constexpr auto l_PB_IOO_SCOM_FP7_DISABLE_GATHERING_ON = 0x1;
            l_scom_buffer.insert<33, 1, 63, uint64_t>(l_PB_IOO_SCOM_FP7_DISABLE_GATHERING_ON );

            if ((l_def_OBUS3_FBC_ENABLED && (l_def_LO_LIMIT_R == literal_1)))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x22 - (l_def_OBUS3_LO_LIMIT_N / l_def_OBUS3_LO_LIMIT_D)) );
            }
            else if (l_def_OBUS3_FBC_ENABLED)
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x24 - (l_def_OBUS3_LO_LIMIT_N / l_def_OBUS3_LO_LIMIT_D)) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x501380dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013810ull, l_scom_buffer ));

            if ((l_def_OBUS0_FBC_ENABLED && l_def_OPTICS_IS_A_BUS))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0x10 );
            }
            else if (l_def_OBUS0_FBC_ENABLED)
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0x1F );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x23)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10))
                || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x12)) || ((l_chip_id == 0x6)
                        && (l_chip_ec == 0x13)) || ((l_chip_id == 0x7) && (l_chip_ec == 0x10)) )
            {
                if (l_def_OBUS0_FBC_ENABLED)
                {
                    l_scom_buffer.insert<9, 7, 57, uint64_t>(literal_0x3C );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_def_OBUS0_FBC_ENABLED)
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x3C );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x23)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10))
                || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x12)) || ((l_chip_id == 0x6)
                        && (l_chip_ec == 0x13)) || ((l_chip_id == 0x7) && (l_chip_ec == 0x10)) )
            {
                if (l_def_OBUS0_FBC_ENABLED)
                {
                    l_scom_buffer.insert<17, 7, 57, uint64_t>(literal_0x3C );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_def_OBUS0_FBC_ENABLED)
                {
                    l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x3C );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x23)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10))
                || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x12)) || ((l_chip_id == 0x6)
                        && (l_chip_ec == 0x13)) || ((l_chip_id == 0x7) && (l_chip_ec == 0x10)) )
            {
                if (l_def_OBUS0_FBC_ENABLED)
                {
                    l_scom_buffer.insert<41, 7, 57, uint64_t>(literal_0x3C );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_def_OBUS0_FBC_ENABLED)
                {
                    l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3C );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x23)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10))
                || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x12)) || ((l_chip_id == 0x6)
                        && (l_chip_ec == 0x13)) || ((l_chip_id == 0x7) && (l_chip_ec == 0x10)) )
            {
                if (l_def_OBUS0_FBC_ENABLED)
                {
                    l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x3C );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_def_OBUS0_FBC_ENABLED)
                {
                    l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x3C );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013810ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013811ull, l_scom_buffer ));

            if ((l_def_OBUS1_FBC_ENABLED && l_def_OPTICS_IS_A_BUS))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0x10 );
            }
            else if (l_def_OBUS1_FBC_ENABLED)
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0x1F );
            }

            if (l_def_OBUS1_FBC_ENABLED)
            {
                l_scom_buffer.insert<1, 7, 57, uint64_t>(literal_0x40 );
            }

            if (l_def_OBUS1_FBC_ENABLED)
            {
                l_scom_buffer.insert<9, 7, 57, uint64_t>(literal_0x3C );
            }

            if (l_def_OBUS1_FBC_ENABLED)
            {
                l_scom_buffer.insert<17, 7, 57, uint64_t>(literal_0x3C );
            }

            if (l_def_OBUS1_FBC_ENABLED)
            {
                l_scom_buffer.insert<33, 7, 57, uint64_t>(literal_0x40 );
            }

            if (l_def_OBUS1_FBC_ENABLED)
            {
                l_scom_buffer.insert<41, 7, 57, uint64_t>(literal_0x3C );
            }

            if (l_def_OBUS1_FBC_ENABLED)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x3C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013811ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013812ull, l_scom_buffer ));

            if ((l_def_OBUS2_FBC_ENABLED && l_def_OPTICS_IS_A_BUS))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0x10 );
            }
            else if (l_def_OBUS2_FBC_ENABLED)
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0x1F );
            }

            if (l_def_OBUS2_FBC_ENABLED)
            {
                l_scom_buffer.insert<1, 7, 57, uint64_t>(literal_0x40 );
            }

            if (l_def_OBUS2_FBC_ENABLED)
            {
                l_scom_buffer.insert<9, 7, 57, uint64_t>(literal_0x3C );
            }

            if (l_def_OBUS2_FBC_ENABLED)
            {
                l_scom_buffer.insert<17, 7, 57, uint64_t>(literal_0x3C );
            }

            if (l_def_OBUS2_FBC_ENABLED)
            {
                l_scom_buffer.insert<33, 7, 57, uint64_t>(literal_0x40 );
            }

            if (l_def_OBUS2_FBC_ENABLED)
            {
                l_scom_buffer.insert<41, 7, 57, uint64_t>(literal_0x3C );
            }

            if (l_def_OBUS2_FBC_ENABLED)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x3C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013812ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013813ull, l_scom_buffer ));

            if ((l_def_OBUS3_FBC_ENABLED && l_def_OPTICS_IS_A_BUS))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0x0E );
            }
            else if (l_def_OBUS3_FBC_ENABLED)
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0x1C );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x23)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10))
                || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x12)) || ((l_chip_id == 0x6)
                        && (l_chip_ec == 0x13)) || ((l_chip_id == 0x7) && (l_chip_ec == 0x10)) )
            {
                if (l_def_OBUS3_FBC_ENABLED)
                {
                    l_scom_buffer.insert<9, 7, 57, uint64_t>(literal_0x3C );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_def_OBUS3_FBC_ENABLED)
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x3C );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x23)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10))
                || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x12)) || ((l_chip_id == 0x6)
                        && (l_chip_ec == 0x13)) || ((l_chip_id == 0x7) && (l_chip_ec == 0x10)) )
            {
                if (l_def_OBUS3_FBC_ENABLED)
                {
                    l_scom_buffer.insert<17, 7, 57, uint64_t>(literal_0x3C );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_def_OBUS3_FBC_ENABLED)
                {
                    l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x3C );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x23)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10))
                || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x12)) || ((l_chip_id == 0x6)
                        && (l_chip_ec == 0x13)) || ((l_chip_id == 0x7) && (l_chip_ec == 0x10)) )
            {
                if (l_def_OBUS3_FBC_ENABLED)
                {
                    l_scom_buffer.insert<41, 7, 57, uint64_t>(literal_0x3C );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_def_OBUS3_FBC_ENABLED)
                {
                    l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3C );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x23)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10))
                || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x12)) || ((l_chip_id == 0x6)
                        && (l_chip_ec == 0x13)) || ((l_chip_id == 0x7) && (l_chip_ec == 0x10)) )
            {
                if (l_def_OBUS3_FBC_ENABLED)
                {
                    l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x3C );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_def_OBUS3_FBC_ENABLED)
                {
                    l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x3C );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013813ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013823ull, l_scom_buffer ));

            if (l_def_OB0_IS_PAIRED)
            {
                constexpr auto l_PB_IOO_SCOM_PB_CFG_IOO01_IS_LOGICAL_PAIR_ON = 0x1;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_PB_IOO_SCOM_PB_CFG_IOO01_IS_LOGICAL_PAIR_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOO_SCOM_PB_CFG_IOO01_IS_LOGICAL_PAIR_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_PB_IOO_SCOM_PB_CFG_IOO01_IS_LOGICAL_PAIR_OFF );
            }

            if (l_def_OBUS0_FBC_ENABLED)
            {
                constexpr auto l_PB_IOO_SCOM_LINKS01_TOD_ENABLE_ON = 0x1;
                l_scom_buffer.insert<8, 1, 63, uint64_t>(l_PB_IOO_SCOM_LINKS01_TOD_ENABLE_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOO_SCOM_LINKS01_TOD_ENABLE_OFF = 0x0;
                l_scom_buffer.insert<8, 1, 63, uint64_t>(l_PB_IOO_SCOM_LINKS01_TOD_ENABLE_OFF );
            }

            if (l_def_OB1_IS_PAIRED)
            {
                constexpr auto l_PB_IOO_SCOM_PB_CFG_IOO23_IS_LOGICAL_PAIR_ON = 0x1;
                l_scom_buffer.insert<1, 1, 63, uint64_t>(l_PB_IOO_SCOM_PB_CFG_IOO23_IS_LOGICAL_PAIR_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOO_SCOM_PB_CFG_IOO23_IS_LOGICAL_PAIR_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 63, uint64_t>(l_PB_IOO_SCOM_PB_CFG_IOO23_IS_LOGICAL_PAIR_OFF );
            }

            if (l_def_OBUS1_FBC_ENABLED)
            {
                constexpr auto l_PB_IOO_SCOM_LINKS23_TOD_ENABLE_ON = 0x1;
                l_scom_buffer.insert<9, 1, 63, uint64_t>(l_PB_IOO_SCOM_LINKS23_TOD_ENABLE_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOO_SCOM_LINKS23_TOD_ENABLE_OFF = 0x0;
                l_scom_buffer.insert<9, 1, 63, uint64_t>(l_PB_IOO_SCOM_LINKS23_TOD_ENABLE_OFF );
            }

            if (l_def_OB2_IS_PAIRED)
            {
                constexpr auto l_PB_IOO_SCOM_PB_CFG_IOO45_IS_LOGICAL_PAIR_ON = 0x1;
                l_scom_buffer.insert<2, 1, 63, uint64_t>(l_PB_IOO_SCOM_PB_CFG_IOO45_IS_LOGICAL_PAIR_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOO_SCOM_PB_CFG_IOO45_IS_LOGICAL_PAIR_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 63, uint64_t>(l_PB_IOO_SCOM_PB_CFG_IOO45_IS_LOGICAL_PAIR_OFF );
            }

            if (l_def_OBUS2_FBC_ENABLED)
            {
                constexpr auto l_PB_IOO_SCOM_LINKS45_TOD_ENABLE_ON = 0x1;
                l_scom_buffer.insert<10, 1, 63, uint64_t>(l_PB_IOO_SCOM_LINKS45_TOD_ENABLE_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOO_SCOM_LINKS45_TOD_ENABLE_OFF = 0x0;
                l_scom_buffer.insert<10, 1, 63, uint64_t>(l_PB_IOO_SCOM_LINKS45_TOD_ENABLE_OFF );
            }

            if (l_def_OB3_IS_PAIRED)
            {
                constexpr auto l_PB_IOO_SCOM_PB_CFG_IOO67_IS_LOGICAL_PAIR_ON = 0x1;
                l_scom_buffer.insert<3, 1, 63, uint64_t>(l_PB_IOO_SCOM_PB_CFG_IOO67_IS_LOGICAL_PAIR_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOO_SCOM_PB_CFG_IOO67_IS_LOGICAL_PAIR_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 63, uint64_t>(l_PB_IOO_SCOM_PB_CFG_IOO67_IS_LOGICAL_PAIR_OFF );
            }

            if (l_def_OBUS3_FBC_ENABLED)
            {
                constexpr auto l_PB_IOO_SCOM_LINKS67_TOD_ENABLE_ON = 0x1;
                l_scom_buffer.insert<11, 1, 63, uint64_t>(l_PB_IOO_SCOM_LINKS67_TOD_ENABLE_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOO_SCOM_LINKS67_TOD_ENABLE_OFF = 0x0;
                l_scom_buffer.insert<11, 1, 63, uint64_t>(l_PB_IOO_SCOM_LINKS67_TOD_ENABLE_OFF );
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
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0001 );
            }

            if (l_def_OBUS0_FBC_ENABLED)
            {
                l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b0001 );
            }

            if (l_def_OBUS0_FBC_ENABLED)
            {
                l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b0100 );
            }

            if (l_def_OBUS0_FBC_ENABLED)
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b0100 );
            }

            if ((( ! l_def_OBUS0_FBC_ENABLED) && l_def_OBUS1_FBC_ENABLED))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0b0001 );
            }

            if ((( ! l_def_OBUS0_FBC_ENABLED) && l_def_OBUS1_FBC_ENABLED))
            {
                l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_0b0001 );
            }

            if ((( ! l_def_OBUS0_FBC_ENABLED) && l_def_OBUS1_FBC_ENABLED))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_0b0100 );
            }

            if ((( ! l_def_OBUS0_FBC_ENABLED) && l_def_OBUS1_FBC_ENABLED))
            {
                l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0b0100 );
            }

            if (((( ! l_def_OBUS0_FBC_ENABLED) && ( ! l_def_OBUS1_FBC_ENABLED)) && l_def_OBUS2_FBC_ENABLED))
            {
                l_scom_buffer.insert<32, 4, 60, uint64_t>(literal_0b0001 );
            }

            if (((( ! l_def_OBUS0_FBC_ENABLED) && ( ! l_def_OBUS1_FBC_ENABLED)) && l_def_OBUS2_FBC_ENABLED))
            {
                l_scom_buffer.insert<40, 4, 60, uint64_t>(literal_0b0001 );
            }

            if (((( ! l_def_OBUS0_FBC_ENABLED) && ( ! l_def_OBUS1_FBC_ENABLED)) && l_def_OBUS2_FBC_ENABLED))
            {
                l_scom_buffer.insert<36, 4, 60, uint64_t>(literal_0b0100 );
            }

            if (((( ! l_def_OBUS0_FBC_ENABLED) && ( ! l_def_OBUS1_FBC_ENABLED)) && l_def_OBUS2_FBC_ENABLED))
            {
                l_scom_buffer.insert<44, 4, 60, uint64_t>(literal_0b0100 );
            }

            if ((((( ! l_def_OBUS0_FBC_ENABLED) && ( ! l_def_OBUS1_FBC_ENABLED)) && ( ! l_def_OBUS2_FBC_ENABLED))
                 && l_def_OBUS3_FBC_ENABLED))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0001 );
            }

            if ((((( ! l_def_OBUS0_FBC_ENABLED) && ( ! l_def_OBUS1_FBC_ENABLED)) && ( ! l_def_OBUS2_FBC_ENABLED))
                 && l_def_OBUS3_FBC_ENABLED))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0b0001 );
            }

            if ((((( ! l_def_OBUS0_FBC_ENABLED) && ( ! l_def_OBUS1_FBC_ENABLED)) && ( ! l_def_OBUS2_FBC_ENABLED))
                 && l_def_OBUS3_FBC_ENABLED))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0100 );
            }

            if ((((( ! l_def_OBUS0_FBC_ENABLED) && ( ! l_def_OBUS1_FBC_ENABLED)) && ( ! l_def_OBUS2_FBC_ENABLED))
                 && l_def_OBUS3_FBC_ENABLED))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013824ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
