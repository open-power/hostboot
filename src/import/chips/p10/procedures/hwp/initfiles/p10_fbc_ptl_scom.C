/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_fbc_ptl_scom.C $ */
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
#include "p10_fbc_ptl_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_0x5 = 0x5;
constexpr uint64_t literal_0x6 = 0x6;
constexpr uint64_t literal_10 = 10;
constexpr uint64_t literal_85 = 85;
constexpr uint64_t literal_0x16 = 0x16;
constexpr uint64_t literal_51 = 51;
constexpr uint64_t literal_0x0C = 0x0C;
constexpr uint64_t literal_0x04 = 0x04;
constexpr uint64_t literal_2063 = 2063;
constexpr uint64_t literal_1611 = 1611;
constexpr uint64_t literal_7 = 7;
constexpr uint64_t literal_6 = 6;
constexpr uint64_t literal_12 = 12;
constexpr uint64_t literal_11 = 11;
constexpr uint64_t literal_0b10 = 0b10;
constexpr uint64_t literal_0x10 = 0x10;
constexpr uint64_t literal_0x1F = 0x1F;
constexpr uint64_t literal_0x40 = 0x40;
constexpr uint64_t literal_0x01 = 0x01;
constexpr uint64_t literal_0x1C = 0x1C;
constexpr uint64_t literal_0xFF = 0xFF;
constexpr uint64_t literal_0x03 = 0x03;
constexpr uint64_t literal_0x1 = 0x1;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_0b0 = 0b0;
constexpr uint64_t literal_5 = 5;
constexpr uint64_t literal_3 = 3;
constexpr uint64_t literal_0b11000 = 0b11000;
constexpr uint64_t literal_0b10000 = 0b10000;
constexpr uint64_t literal_0b00000 = 0b00000;

fapi2::ReturnCode p10_fbc_ptl_scom(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& TGT0,
                                   const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT2)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT1, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT1, l_chip_ec));
        fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_TGT2_ATTR_PROC_FABRIC_BROADCAST_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, TGT2, l_TGT2_ATTR_PROC_FABRIC_BROADCAST_MODE));
        uint64_t l_def_IS_TWO_HOP = (l_TGT2_ATTR_PROC_FABRIC_BROADCAST_MODE ==
                                     fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_2HOP_CHIP_IS_NODE);
        fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type l_TGT1_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, TGT1,
                               l_TGT1_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG));
        fapi2::ATTR_CHIP_UNIT_POS_Type l_TGT0_ATTR_CHIP_UNIT_POS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, TGT0, l_TGT0_ATTR_CHIP_UNIT_POS));
        uint64_t l_def_OPTX = (l_TGT0_ATTR_CHIP_UNIT_POS * literal_2);
        fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_TGT1_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, TGT1,
                               l_TGT1_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG));
        uint64_t l_def_AX0_ODD_CNFG = ((((l_TGT1_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[l_def_OPTX] ==
                                          fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE)
                                         || (l_TGT1_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[l_def_OPTX] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE))
                                        || (l_TGT1_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[l_def_OPTX] ==
                                            fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_ODD_ONLY))
                                       || (l_TGT1_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[l_def_OPTX] ==
                                           fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_ODD_ONLY));
        uint64_t l_def_AX0_EVN_CNFG = ((((l_TGT1_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[l_def_OPTX] ==
                                          fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE)
                                         || (l_TGT1_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[l_def_OPTX] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE))
                                        || (l_TGT1_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[l_def_OPTX] ==
                                            fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_EVEN_ONLY))
                                       || (l_TGT1_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[l_def_OPTX] ==
                                           fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_EVEN_ONLY));
        uint64_t l_def_AX0_ENABLED = (l_def_AX0_EVN_CNFG || l_def_AX0_ODD_CNFG);
        fapi2::ATTR_FREQ_PROC_IOHS_MHZ_Type l_TGT1_ATTR_FREQ_PROC_IOHS_MHZ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PROC_IOHS_MHZ, TGT1, l_TGT1_ATTR_FREQ_PROC_IOHS_MHZ));
        uint64_t l_def_AX0_FW_LIMIT_D = (l_TGT1_ATTR_FREQ_PROC_IOHS_MHZ[l_def_OPTX] * literal_10);
        fapi2::ATTR_FREQ_PAU_MHZ_Type l_TGT2_ATTR_FREQ_PAU_MHZ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PAU_MHZ, TGT2, l_TGT2_ATTR_FREQ_PAU_MHZ));
        uint64_t l_def_AX_FW_LIMIT_N = (l_TGT2_ATTR_FREQ_PAU_MHZ * literal_85);
        uint64_t l_def_AX0_HW_LIMIT_D = (l_TGT1_ATTR_FREQ_PROC_IOHS_MHZ[l_def_OPTX] * literal_10);
        uint64_t l_def_AX_HW_LIMIT_N = (l_TGT2_ATTR_FREQ_PAU_MHZ * literal_51);
        uint64_t l_def_OPTY = ((l_TGT0_ATTR_CHIP_UNIT_POS * literal_2) + literal_1);
        uint64_t l_def_AX1_ODD_CNFG = ((((l_TGT1_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[l_def_OPTY] ==
                                          fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE)
                                         || (l_TGT1_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[l_def_OPTY] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE))
                                        || (l_TGT1_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[l_def_OPTY] ==
                                            fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_ODD_ONLY))
                                       || (l_TGT1_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[l_def_OPTY] ==
                                           fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_ODD_ONLY));
        uint64_t l_def_AX1_EVN_CNFG = ((((l_TGT1_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[l_def_OPTY] ==
                                          fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE)
                                         || (l_TGT1_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[l_def_OPTY] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE))
                                        || (l_TGT1_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[l_def_OPTY] ==
                                            fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_EVEN_ONLY))
                                       || (l_TGT1_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[l_def_OPTY] ==
                                           fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_EVEN_ONLY));
        uint64_t l_def_AX1_ENABLED = (l_def_AX1_EVN_CNFG || l_def_AX1_ODD_CNFG);
        uint64_t l_def_AX1_FW_LIMIT_D = (l_TGT1_ATTR_FREQ_PROC_IOHS_MHZ[l_def_OPTY] * literal_10);
        uint64_t l_def_AX1_HW_LIMIT_D = (l_TGT1_ATTR_FREQ_PROC_IOHS_MHZ[l_def_OPTY] * literal_10);
        uint64_t l_def_AX0_CMD_RATE_2B_R = (((literal_7 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611) %
                                            (l_TGT1_ATTR_FREQ_PROC_IOHS_MHZ[l_def_OPTX] * literal_2063));
        fapi2::ATTR_PROC_FABRIC_IOHS_BUS_WIDTH_Type l_TGT1_ATTR_PROC_FABRIC_IOHS_BUS_WIDTH;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_IOHS_BUS_WIDTH, TGT1, l_TGT1_ATTR_PROC_FABRIC_IOHS_BUS_WIDTH));
        uint64_t l_def_AX0_BUS_WIDTH_2B = (l_TGT1_ATTR_PROC_FABRIC_IOHS_BUS_WIDTH[l_def_OPTX] ==
                                           fapi2::ENUM_ATTR_PROC_FABRIC_IOHS_BUS_WIDTH_2_BYTE);
        uint64_t l_def_AX0_CMD_RATE_D = (l_TGT1_ATTR_FREQ_PROC_IOHS_MHZ[l_def_OPTX] * literal_2063);
        uint64_t l_def_AX_CMD_RATE_2B_N = ((literal_7 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611);
        uint64_t l_def_AX0_CMD_RATE_2B_RA = (((literal_6 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611) %
                                             (l_TGT1_ATTR_FREQ_PROC_IOHS_MHZ[l_def_OPTX] * literal_2063));
        uint64_t l_def_AX_CMD_RATE_2B_NA = ((literal_6 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611);
        uint64_t l_def_AX0_CMD_RATE_1B_R = (((literal_12 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611) %
                                            (l_TGT1_ATTR_FREQ_PROC_IOHS_MHZ[l_def_OPTX] * literal_2063));
        uint64_t l_def_AX_CMD_RATE_1B_N = ((literal_12 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611);
        uint64_t l_def_AX0_CMD_RATE_1B_RA = (((literal_11 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611) %
                                             (l_TGT1_ATTR_FREQ_PROC_IOHS_MHZ[l_def_OPTX] * literal_2063));
        uint64_t l_def_AX_CMD_RATE_1B_NA = ((literal_11 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611);
        uint64_t l_def_AX1_CMD_RATE_2B_R = (((literal_7 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611) %
                                            (l_TGT1_ATTR_FREQ_PROC_IOHS_MHZ[l_def_OPTY] * literal_2063));
        uint64_t l_def_AX1_BUS_WIDTH_2B = (l_TGT1_ATTR_PROC_FABRIC_IOHS_BUS_WIDTH[l_def_OPTY] ==
                                           fapi2::ENUM_ATTR_PROC_FABRIC_IOHS_BUS_WIDTH_2_BYTE);
        uint64_t l_def_AX1_CMD_RATE_D = (l_TGT1_ATTR_FREQ_PROC_IOHS_MHZ[l_def_OPTY] * literal_2063);
        uint64_t l_def_AX1_CMD_RATE_2B_RA = (((literal_6 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611) %
                                             (l_TGT1_ATTR_FREQ_PROC_IOHS_MHZ[l_def_OPTY] * literal_2063));
        uint64_t l_def_AX1_CMD_RATE_1B_R = (((literal_12 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611) %
                                            (l_TGT1_ATTR_FREQ_PROC_IOHS_MHZ[l_def_OPTY] * literal_2063));
        uint64_t l_def_AX1_CMD_RATE_1B_RA = (((literal_11 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611) %
                                             (l_TGT1_ATTR_FREQ_PROC_IOHS_MHZ[l_def_OPTY] * literal_2063));
        fapi2::ATTR_HW543384_WAR_MODE_Type l_TGT2_ATTR_HW543384_WAR_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HW543384_WAR_MODE, TGT2, l_TGT2_ATTR_HW543384_WAR_MODE));
        fapi2::ATTR_CHIP_EC_FEATURE_HW543384_Type l_TGT1_ATTR_CHIP_EC_FEATURE_HW543384;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW543384, TGT1, l_TGT1_ATTR_CHIP_EC_FEATURE_HW543384));
        uint64_t l_def_LETHAL_COFFEE_WAR = ((l_TGT1_ATTR_CHIP_EC_FEATURE_HW543384 != literal_0)
                                            && ((l_TGT2_ATTR_HW543384_WAR_MODE == fapi2::ENUM_ATTR_HW543384_WAR_MODE_FBC_FLOW_CONTROL)
                                                || (l_TGT2_ATTR_HW543384_WAR_MODE == fapi2::ENUM_ATTR_HW543384_WAR_MODE_BOTH)));
        fapi2::ATTR_PROC_FABRIC_A_INDIRECT_Type l_TGT2_ATTR_PROC_FABRIC_A_INDIRECT;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_INDIRECT, TGT2, l_TGT2_ATTR_PROC_FABRIC_A_INDIRECT));
        uint64_t l_def_DUAL_VC_MODE = ((l_TGT2_ATTR_PROC_FABRIC_BROADCAST_MODE ==
                                        fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_2HOP_CHIP_IS_NODE)
                                       || (l_TGT2_ATTR_PROC_FABRIC_A_INDIRECT == fapi2::ENUM_ATTR_PROC_FABRIC_A_INDIRECT_ON));
        uint64_t l_def_AX0_IS_PAIRED = (l_def_AX0_EVN_CNFG && l_def_AX0_ODD_CNFG);
        uint64_t l_def_AX1_IS_PAIRED = (l_def_AX1_EVN_CNFG && l_def_AX1_ODD_CNFG);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x1001180aull, l_scom_buffer ));

            if (((l_def_AX0_ENABLED == literal_1) && (l_def_IS_TWO_HOP == literal_0)))
            {
                l_scom_buffer.insert<21, 3, 61, uint64_t>(literal_0x5 );
            }
            else if (((l_def_AX0_ENABLED == literal_1) && (l_def_IS_TWO_HOP != literal_0)))
            {
                l_scom_buffer.insert<21, 3, 61, uint64_t>(literal_0x6 );
            }

            if ((l_def_AX0_EVN_CNFG == literal_1))
            {
                constexpr auto l_PB_PTLSCOM10_FP0_FMR_ENABLE_1PER4_PRESP_ON = 0x1;
                l_scom_buffer.insert<20, 1, 63, uint64_t>(l_PB_PTLSCOM10_FP0_FMR_ENABLE_1PER4_PRESP_ON );
            }

            if ((l_def_AX0_EVN_CNFG == literal_1))
            {
                l_scom_buffer.insert<4, 6, 58, uint64_t>((literal_0x16 - (l_def_AX_FW_LIMIT_N / l_def_AX0_FW_LIMIT_D)) );
            }

            if ((l_def_AX0_EVN_CNFG == literal_1))
            {
                l_scom_buffer.insert<10, 6, 58, uint64_t>((literal_0x0C - (l_def_AX_HW_LIMIT_N / l_def_AX0_HW_LIMIT_D)) );
            }

            if ((l_def_AX0_EVN_CNFG == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0x04 );
            }

            if ((l_def_AX0_EVN_CNFG == literal_1))
            {
                constexpr auto l_PB_PTLSCOM10_FP0_CREDIT_PRIORITY_4_NOT_8_ON = 0x1;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_PB_PTLSCOM10_FP0_CREDIT_PRIORITY_4_NOT_8_ON );
            }

            if ((l_def_AX0_ODD_CNFG == literal_1))
            {
                constexpr auto l_PB_PTLSCOM10_FP1_FMR_ENABLE_1PER4_PRESP_ON = 0x1;
                l_scom_buffer.insert<52, 1, 63, uint64_t>(l_PB_PTLSCOM10_FP1_FMR_ENABLE_1PER4_PRESP_ON );
            }

            if ((l_def_AX0_ODD_CNFG == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0x16 - (l_def_AX_FW_LIMIT_N / l_def_AX0_FW_LIMIT_D)) );
            }

            if ((l_def_AX0_ODD_CNFG == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>((literal_0x0C - (l_def_AX_HW_LIMIT_N / l_def_AX0_HW_LIMIT_D)) );
            }

            if ((l_def_AX0_ODD_CNFG == literal_1))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x04 );
            }

            if ((l_def_AX0_ODD_CNFG == literal_1))
            {
                constexpr auto l_PB_PTLSCOM10_FP1_CREDIT_PRIORITY_4_NOT_8_ON = 0x1;
                l_scom_buffer.insert<32, 1, 63, uint64_t>(l_PB_PTLSCOM10_FP1_CREDIT_PRIORITY_4_NOT_8_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x1001180aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x1001180bull, l_scom_buffer ));

            if (((l_def_AX1_ENABLED == literal_1) && (l_def_IS_TWO_HOP == literal_0)))
            {
                l_scom_buffer.insert<21, 3, 61, uint64_t>(literal_0x5 );
            }
            else if (((l_def_AX1_ENABLED == literal_1) && (l_def_IS_TWO_HOP != literal_0)))
            {
                l_scom_buffer.insert<21, 3, 61, uint64_t>(literal_0x6 );
            }

            if ((l_def_AX1_EVN_CNFG == literal_1))
            {
                constexpr auto l_PB_PTLSCOM10_FP2_FMR_ENABLE_1PER4_PRESP_ON = 0x1;
                l_scom_buffer.insert<20, 1, 63, uint64_t>(l_PB_PTLSCOM10_FP2_FMR_ENABLE_1PER4_PRESP_ON );
            }

            if ((l_def_AX1_EVN_CNFG == literal_1))
            {
                l_scom_buffer.insert<4, 6, 58, uint64_t>((literal_0x16 - (l_def_AX_FW_LIMIT_N / l_def_AX1_FW_LIMIT_D)) );
            }

            if ((l_def_AX1_EVN_CNFG == literal_1))
            {
                l_scom_buffer.insert<10, 6, 58, uint64_t>((literal_0x0C - (l_def_AX_HW_LIMIT_N / l_def_AX1_HW_LIMIT_D)) );
            }

            if ((l_def_AX1_EVN_CNFG == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0x04 );
            }

            if ((l_def_AX1_EVN_CNFG == literal_1))
            {
                constexpr auto l_PB_PTLSCOM10_FP2_CREDIT_PRIORITY_4_NOT_8_ON = 0x1;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_PB_PTLSCOM10_FP2_CREDIT_PRIORITY_4_NOT_8_ON );
            }

            if ((l_def_AX1_ODD_CNFG == literal_1))
            {
                constexpr auto l_PB_PTLSCOM10_FP3_FMR_ENABLE_1PER4_PRESP_ON = 0x1;
                l_scom_buffer.insert<52, 1, 63, uint64_t>(l_PB_PTLSCOM10_FP3_FMR_ENABLE_1PER4_PRESP_ON );
            }

            if ((l_def_AX1_ODD_CNFG == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0x16 - (l_def_AX_FW_LIMIT_N / l_def_AX1_FW_LIMIT_D)) );
            }

            if ((l_def_AX1_ODD_CNFG == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>((literal_0x0C - (l_def_AX_HW_LIMIT_N / l_def_AX1_HW_LIMIT_D)) );
            }

            if ((l_def_AX1_ODD_CNFG == literal_1))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x04 );
            }

            if ((l_def_AX1_ODD_CNFG == literal_1))
            {
                constexpr auto l_PB_PTLSCOM10_FP3_CREDIT_PRIORITY_4_NOT_8_ON = 0x1;
                l_scom_buffer.insert<32, 1, 63, uint64_t>(l_PB_PTLSCOM10_FP3_CREDIT_PRIORITY_4_NOT_8_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x1001180bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x1001180cull, l_scom_buffer ));

            if ((((l_def_AX0_ENABLED == literal_1) && (l_def_AX0_BUS_WIDTH_2B == literal_1))
                 && (l_def_AX0_CMD_RATE_2B_R != literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>((l_def_AX_CMD_RATE_2B_N / l_def_AX0_CMD_RATE_D) );
            }
            else if ((((l_def_AX0_ENABLED == literal_1) && (l_def_AX0_BUS_WIDTH_2B == literal_1))
                      && (l_def_AX0_CMD_RATE_2B_R == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(((l_def_AX_CMD_RATE_2B_N / l_def_AX0_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_def_AX0_ENABLED == literal_1) && (l_def_AX0_BUS_WIDTH_2B == literal_1))
                      && (l_def_AX0_CMD_RATE_2B_RA != literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>((l_def_AX_CMD_RATE_2B_NA / l_def_AX0_CMD_RATE_D) );
            }
            else if ((((l_def_AX0_ENABLED == literal_1) && (l_def_AX0_BUS_WIDTH_2B == literal_1))
                      && (l_def_AX0_CMD_RATE_2B_RA == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(((l_def_AX_CMD_RATE_2B_NA / l_def_AX0_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_def_AX0_ENABLED == literal_1) && (l_def_AX0_BUS_WIDTH_2B != literal_1))
                      && (l_def_AX0_CMD_RATE_1B_R != literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>((l_def_AX_CMD_RATE_1B_N / l_def_AX0_CMD_RATE_D) );
            }
            else if ((((l_def_AX0_ENABLED == literal_1) && (l_def_AX0_BUS_WIDTH_2B != literal_1))
                      && (l_def_AX0_CMD_RATE_1B_R == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(((l_def_AX_CMD_RATE_1B_N / l_def_AX0_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_def_AX0_ENABLED == literal_1) && (l_def_AX0_BUS_WIDTH_2B != literal_1))
                      && (l_def_AX0_CMD_RATE_1B_RA != literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>((l_def_AX_CMD_RATE_1B_NA / l_def_AX0_CMD_RATE_D) );
            }
            else if ((((l_def_AX0_ENABLED == literal_1) && (l_def_AX0_BUS_WIDTH_2B != literal_1))
                      && (l_def_AX0_CMD_RATE_1B_RA == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(((l_def_AX_CMD_RATE_1B_NA / l_def_AX0_CMD_RATE_D) - literal_1) );
            }

            if ((l_def_AX0_ENABLED == literal_1))
            {
                l_scom_buffer.insert<29, 3, 61, uint64_t>(literal_0b10 );
            }

            if ((l_def_AX0_ENABLED == literal_1))
            {
                constexpr auto l_PB_PTLSCOM10_PTLX_DISABLE_TURBO_ON = 0x1;
                l_scom_buffer.insert<24, 1, 63, uint64_t>(l_PB_PTLSCOM10_PTLX_DISABLE_TURBO_ON );
            }

            if ((((l_def_AX1_ENABLED == literal_1) && (l_def_AX1_BUS_WIDTH_2B == literal_1))
                 && (l_def_AX1_CMD_RATE_2B_R != literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>((l_def_AX_CMD_RATE_2B_N / l_def_AX1_CMD_RATE_D) );
            }
            else if ((((l_def_AX1_ENABLED == literal_1) && (l_def_AX1_BUS_WIDTH_2B == literal_1))
                      && (l_def_AX1_CMD_RATE_2B_R == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(((l_def_AX_CMD_RATE_2B_N / l_def_AX1_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_def_AX1_ENABLED == literal_1) && (l_def_AX1_BUS_WIDTH_2B == literal_1))
                      && (l_def_AX1_CMD_RATE_2B_RA != literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>((l_def_AX_CMD_RATE_2B_NA / l_def_AX1_CMD_RATE_D) );
            }
            else if ((((l_def_AX1_ENABLED == literal_1) && (l_def_AX1_BUS_WIDTH_2B == literal_1))
                      && (l_def_AX1_CMD_RATE_2B_RA == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(((l_def_AX_CMD_RATE_2B_NA / l_def_AX1_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_def_AX1_ENABLED == literal_1) && (l_def_AX1_BUS_WIDTH_2B != literal_1))
                      && (l_def_AX1_CMD_RATE_1B_R != literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>((l_def_AX_CMD_RATE_1B_N / l_def_AX1_CMD_RATE_D) );
            }
            else if ((((l_def_AX1_ENABLED == literal_1) && (l_def_AX1_BUS_WIDTH_2B != literal_1))
                      && (l_def_AX1_CMD_RATE_1B_R == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(((l_def_AX_CMD_RATE_1B_N / l_def_AX1_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_def_AX1_ENABLED == literal_1) && (l_def_AX1_BUS_WIDTH_2B != literal_1))
                      && (l_def_AX1_CMD_RATE_1B_RA != literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>((l_def_AX_CMD_RATE_1B_NA / l_def_AX1_CMD_RATE_D) );
            }
            else if ((((l_def_AX1_ENABLED == literal_1) && (l_def_AX1_BUS_WIDTH_2B != literal_1))
                      && (l_def_AX1_CMD_RATE_1B_RA == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(((l_def_AX_CMD_RATE_1B_NA / l_def_AX1_CMD_RATE_D) - literal_1) );
            }

            if ((l_def_AX1_ENABLED == literal_1))
            {
                l_scom_buffer.insert<37, 3, 61, uint64_t>(literal_0b10 );
            }

            if ((l_def_AX1_ENABLED == literal_1))
            {
                constexpr auto l_PB_PTLSCOM10_PTLY_DISABLE_TURBO_ON = 0x1;
                l_scom_buffer.insert<32, 1, 63, uint64_t>(l_PB_PTLSCOM10_PTLY_DISABLE_TURBO_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x1001180cull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10011810ull, l_scom_buffer ));

            if ((((l_def_AX0_ENABLED == literal_1) && l_def_DUAL_VC_MODE) && l_def_LETHAL_COFFEE_WAR))
            {
                l_scom_buffer.insert<32, 5, 59, uint64_t>(literal_0x04 );
            }
            else if (((l_def_AX0_ENABLED == literal_1) && l_def_DUAL_VC_MODE))
            {
                l_scom_buffer.insert<32, 5, 59, uint64_t>(literal_0x10 );
            }
            else if ((l_def_AX0_ENABLED == literal_1))
            {
                l_scom_buffer.insert<32, 5, 59, uint64_t>(literal_0x1F );
            }

            if ((l_def_AX0_ENABLED == literal_1))
            {
                l_scom_buffer.insert<1, 7, 57, uint64_t>(literal_0x40 );
            }

            if ((l_def_AX0_ENABLED == literal_1))
            {
                l_scom_buffer.insert<9, 7, 57, uint64_t>(literal_0x40 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x10011810ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10011811ull, l_scom_buffer ));

            if ((((l_def_AX1_ENABLED == literal_1) && l_def_DUAL_VC_MODE) && l_def_LETHAL_COFFEE_WAR))
            {
                l_scom_buffer.insert<32, 5, 59, uint64_t>(literal_0x04 );
            }
            else if (((l_def_AX1_ENABLED == literal_1) && l_def_DUAL_VC_MODE))
            {
                l_scom_buffer.insert<32, 5, 59, uint64_t>(literal_0x10 );
            }
            else if ((l_def_AX1_ENABLED == literal_1))
            {
                l_scom_buffer.insert<32, 5, 59, uint64_t>(literal_0x1F );
            }

            if ((l_def_AX1_ENABLED == literal_1))
            {
                l_scom_buffer.insert<1, 7, 57, uint64_t>(literal_0x40 );
            }

            if ((l_def_AX1_ENABLED == literal_1))
            {
                l_scom_buffer.insert<9, 7, 57, uint64_t>(literal_0x40 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x10011811ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10011814ull, l_scom_buffer ));

            if ((l_def_AX0_ENABLED == literal_1))
            {
                constexpr auto l_PB_PTLSCOM10_PSAVE01_MODE_NORMAL = 0x0;
                l_scom_buffer.insert<0, 2, 62, uint64_t>(l_PB_PTLSCOM10_PSAVE01_MODE_NORMAL );
            }

            if ((l_def_AX0_ENABLED == literal_1))
            {
                constexpr auto l_PB_PTLSCOM10_PSAVE01_WIDTH_DISABLED = 0x0;
                l_scom_buffer.insert<2, 3, 61, uint64_t>(l_PB_PTLSCOM10_PSAVE01_WIDTH_DISABLED );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x10011814ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10011815ull, l_scom_buffer ));

            if ((l_def_AX0_ENABLED == literal_1))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x01 );
            }

            if ((l_def_AX0_ENABLED == literal_1))
            {
                l_scom_buffer.insert<21, 5, 59, uint64_t>(literal_0x1C );
            }

            if ((l_def_AX0_ENABLED == literal_1))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xFF );
            }

            if ((l_def_AX0_ENABLED == literal_1))
            {
                l_scom_buffer.insert<16, 5, 59, uint64_t>(literal_0x03 );
            }

            if ((l_def_AX0_ENABLED == literal_1))
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0x1 );
            }

            if ((l_def_AX0_ENABLED == literal_1))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>(literal_0x01 );
            }

            if ((l_def_AX0_ENABLED == literal_1))
            {
                l_scom_buffer.insert<49, 5, 59, uint64_t>(literal_0x1C );
            }

            if ((l_def_AX0_ENABLED == literal_1))
            {
                l_scom_buffer.insert<28, 8, 56, uint64_t>(literal_0xFF );
            }

            if ((l_def_AX0_ENABLED == literal_1))
            {
                l_scom_buffer.insert<44, 5, 59, uint64_t>(literal_0x03 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x10011815ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10011816ull, l_scom_buffer ));

            if ((l_def_AX1_ENABLED == literal_1))
            {
                constexpr auto l_PB_PTLSCOM10_PSAVE23_MODE_NORMAL = 0x0;
                l_scom_buffer.insert<0, 2, 62, uint64_t>(l_PB_PTLSCOM10_PSAVE23_MODE_NORMAL );
            }

            if ((l_def_AX1_ENABLED == literal_1))
            {
                constexpr auto l_PB_PTLSCOM10_PSAVE23_WIDTH_DISABLED = 0x0;
                l_scom_buffer.insert<2, 3, 61, uint64_t>(l_PB_PTLSCOM10_PSAVE23_WIDTH_DISABLED );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x10011816ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10011817ull, l_scom_buffer ));

            if ((l_def_AX1_ENABLED == literal_1))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x01 );
            }

            if ((l_def_AX1_ENABLED == literal_1))
            {
                l_scom_buffer.insert<21, 5, 59, uint64_t>(literal_0x1C );
            }

            if ((l_def_AX1_ENABLED == literal_1))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xFF );
            }

            if ((l_def_AX1_ENABLED == literal_1))
            {
                l_scom_buffer.insert<16, 5, 59, uint64_t>(literal_0x03 );
            }

            if ((l_def_AX1_ENABLED == literal_1))
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0x1 );
            }

            if ((l_def_AX1_ENABLED == literal_1))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>(literal_0x01 );
            }

            if ((l_def_AX1_ENABLED == literal_1))
            {
                l_scom_buffer.insert<49, 5, 59, uint64_t>(literal_0x1C );
            }

            if ((l_def_AX1_ENABLED == literal_1))
            {
                l_scom_buffer.insert<28, 8, 56, uint64_t>(literal_0xFF );
            }

            if ((l_def_AX1_ENABLED == literal_1))
            {
                l_scom_buffer.insert<44, 5, 59, uint64_t>(literal_0x03 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x10011817ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10011825ull, l_scom_buffer ));

            if (((l_def_AX0_ENABLED == literal_1) && (l_def_AX0_IS_PAIRED == literal_1)))
            {
                constexpr auto l_PB_PTLSCOM10_PTLX_MODE_DUAL = 0x7;
                l_scom_buffer.insert<0, 2, 61, uint64_t>(l_PB_PTLSCOM10_PTLX_MODE_DUAL );
                l_scom_buffer.insert<4, 1, 63, uint64_t>(l_PB_PTLSCOM10_PTLX_MODE_DUAL );
            }
            else if (((l_def_AX0_ENABLED == literal_1) && (l_def_AX0_EVN_CNFG == literal_1)))
            {
                constexpr auto l_PB_PTLSCOM10_PTLX_MODE_EVN = 0x4;
                l_scom_buffer.insert<0, 2, 61, uint64_t>(l_PB_PTLSCOM10_PTLX_MODE_EVN );
                l_scom_buffer.insert<4, 1, 63, uint64_t>(l_PB_PTLSCOM10_PTLX_MODE_EVN );
            }
            else if (((l_def_AX0_ENABLED == literal_1) && (l_def_AX0_ODD_CNFG == literal_1)))
            {
                constexpr auto l_PB_PTLSCOM10_PTLX_MODE_ODD = 0x2;
                l_scom_buffer.insert<0, 2, 61, uint64_t>(l_PB_PTLSCOM10_PTLX_MODE_ODD );
                l_scom_buffer.insert<4, 1, 63, uint64_t>(l_PB_PTLSCOM10_PTLX_MODE_ODD );
            }
            else if ((l_def_AX0_ENABLED == literal_0))
            {
                constexpr auto l_PB_PTLSCOM10_PTLX_MODE_OFF = 0x0;
                l_scom_buffer.insert<0, 2, 61, uint64_t>(l_PB_PTLSCOM10_PTLX_MODE_OFF );
                l_scom_buffer.insert<4, 1, 63, uint64_t>(l_PB_PTLSCOM10_PTLX_MODE_OFF );
            }

            if (((l_def_AX1_ENABLED == literal_1) && (l_def_AX1_IS_PAIRED == literal_1)))
            {
                constexpr auto l_PB_PTLSCOM10_PTLY_MODE_DUAL = 0x7;
                l_scom_buffer.insert<2, 2, 61, uint64_t>(l_PB_PTLSCOM10_PTLY_MODE_DUAL );
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_PB_PTLSCOM10_PTLY_MODE_DUAL );
            }
            else if (((l_def_AX1_ENABLED == literal_1) && (l_def_AX1_EVN_CNFG == literal_1)))
            {
                constexpr auto l_PB_PTLSCOM10_PTLY_MODE_EVN = 0x4;
                l_scom_buffer.insert<2, 2, 61, uint64_t>(l_PB_PTLSCOM10_PTLY_MODE_EVN );
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_PB_PTLSCOM10_PTLY_MODE_EVN );
            }
            else if (((l_def_AX1_ENABLED == literal_1) && (l_def_AX1_ODD_CNFG == literal_1)))
            {
                constexpr auto l_PB_PTLSCOM10_PTLY_MODE_ODD = 0x2;
                l_scom_buffer.insert<2, 2, 61, uint64_t>(l_PB_PTLSCOM10_PTLY_MODE_ODD );
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_PB_PTLSCOM10_PTLY_MODE_ODD );
            }
            else if ((l_def_AX1_ENABLED == literal_0))
            {
                constexpr auto l_PB_PTLSCOM10_PTLY_MODE_OFF = 0x0;
                l_scom_buffer.insert<2, 2, 61, uint64_t>(l_PB_PTLSCOM10_PTLY_MODE_OFF );
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_PB_PTLSCOM10_PTLY_MODE_OFF );
            }

            if (((l_def_AX0_EVN_CNFG == literal_1) && (l_def_OPTX == literal_0)))
            {
                l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (((l_def_AX0_EVN_CNFG == literal_1) && (((l_def_OPTX == literal_2) || (l_def_OPTX == literal_4))
                      || (l_def_OPTX == literal_6))))
            {
                l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_def_AX0_ODD_CNFG == literal_1) && (l_def_OPTX == literal_0)))
            {
                l_scom_buffer.insert<14, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (((l_def_AX0_ODD_CNFG == literal_1) && (((l_def_OPTX == literal_2) || (l_def_OPTX == literal_4))
                      || (l_def_OPTX == literal_6))))
            {
                l_scom_buffer.insert<14, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_def_AX1_EVN_CNFG == literal_1) && (l_def_OPTY == literal_1)))
            {
                l_scom_buffer.insert<16, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (((l_def_AX1_EVN_CNFG == literal_1) && (((l_def_OPTY == literal_3) || (l_def_OPTY == literal_5))
                      || (l_def_OPTY == literal_7))))
            {
                l_scom_buffer.insert<16, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_def_AX1_ODD_CNFG == literal_1) && (l_def_OPTY == literal_1)))
            {
                l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (((l_def_AX1_ODD_CNFG == literal_1) && (((l_def_OPTY == literal_3) || (l_def_OPTY == literal_5))
                      || (l_def_OPTY == literal_7))))
            {
                l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_def_AX0_EVN_CNFG == literal_1) && (l_def_OPTX == literal_0)))
            {
                l_scom_buffer.insert<10, 1, 59, uint64_t>(literal_0b11000 );
                l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0b11000 );
            }
            else if (((l_def_AX1_EVN_CNFG == literal_1) && (((l_def_OPTY == literal_3) || (l_def_OPTY == literal_5))
                      || (l_def_OPTY == literal_7))))
            {
                l_scom_buffer.insert<10, 1, 59, uint64_t>(literal_0b10000 );
                l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0b10000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<10, 1, 59, uint64_t>(literal_0b00000 );
                l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0b00000 );
            }

            if (((l_def_AX0_ODD_CNFG == literal_1) && (l_def_OPTX == literal_0)))
            {
                l_scom_buffer.insert<11, 1, 59, uint64_t>(literal_0b11000 );
                l_scom_buffer.insert<32, 4, 60, uint64_t>(literal_0b11000 );
            }
            else if (((l_def_AX1_ODD_CNFG == literal_1) && (((l_def_OPTY == literal_3) || (l_def_OPTY == literal_5))
                      || (l_def_OPTY == literal_7))))
            {
                l_scom_buffer.insert<11, 1, 59, uint64_t>(literal_0b10000 );
                l_scom_buffer.insert<32, 4, 60, uint64_t>(literal_0b10000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<11, 1, 59, uint64_t>(literal_0b00000 );
                l_scom_buffer.insert<32, 4, 60, uint64_t>(literal_0b00000 );
            }

            if (((l_def_AX1_EVN_CNFG == literal_1) && (l_def_OPTY == literal_1)))
            {
                l_scom_buffer.insert<8, 1, 59, uint64_t>(literal_0b11000 );
                l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_0b11000 );
            }
            else if (((l_def_AX0_EVN_CNFG == literal_1) && (((l_def_OPTX == literal_2) || (l_def_OPTX == literal_4))
                      || (l_def_OPTX == literal_6))))
            {
                l_scom_buffer.insert<8, 1, 59, uint64_t>(literal_0b10000 );
                l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_0b10000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<8, 1, 59, uint64_t>(literal_0b00000 );
                l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_0b00000 );
            }

            if (((l_def_AX1_ODD_CNFG == literal_1) && (l_def_OPTY == literal_1)))
            {
                l_scom_buffer.insert<9, 1, 59, uint64_t>(literal_0b11000 );
                l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_0b11000 );
            }
            else if (((l_def_AX0_ODD_CNFG == literal_1) && (((l_def_OPTX == literal_2) || (l_def_OPTX == literal_4))
                      || (l_def_OPTX == literal_6))))
            {
                l_scom_buffer.insert<9, 1, 59, uint64_t>(literal_0b10000 );
                l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_0b10000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<9, 1, 59, uint64_t>(literal_0b00000 );
                l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_0b00000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x10011825ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
