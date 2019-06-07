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
constexpr uint64_t literal_0x5 = 0x5;
constexpr uint64_t literal_0x6 = 0x6;
constexpr uint64_t literal_0x0B = 0x0B;
constexpr uint64_t literal_0x06 = 0x06;
constexpr uint64_t literal_0b10 = 0b10;
constexpr uint64_t literal_2063 = 2063;
constexpr uint64_t literal_1611 = 1611;
constexpr uint64_t literal_7 = 7;
constexpr uint64_t literal_6 = 6;
constexpr uint64_t literal_12 = 12;
constexpr uint64_t literal_11 = 11;
constexpr uint64_t literal_0x40 = 0x40;
constexpr uint64_t literal_0x01 = 0x01;
constexpr uint64_t literal_0x1C = 0x1C;
constexpr uint64_t literal_0xFF = 0xFF;
constexpr uint64_t literal_0x03 = 0x03;
constexpr uint64_t literal_0x1 = 0x1;

fapi2::ReturnCode p10_fbc_ptl_scom(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& TGT0,
                                   const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT2,
                                   const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& TGT3)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT1, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT1, l_chip_ec));
        fapi2::ATTR_PROC_FABRIC_A_LINKS_CNFG_Type l_TGT1_ATTR_PROC_FABRIC_A_LINKS_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_LINKS_CNFG, TGT1, l_TGT1_ATTR_PROC_FABRIC_A_LINKS_CNFG));
        uint64_t l_def_NUM_A_LINKS_CFG = l_TGT1_ATTR_PROC_FABRIC_A_LINKS_CNFG;
        fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type l_TGT1_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, TGT1,
                               l_TGT1_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG));
        fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_TGT1_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, TGT1,
                               l_TGT1_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG));
        uint64_t l_def_AX0_ENABLED = ((l_TGT1_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                                       fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE)
                                      || (l_TGT1_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                                          fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE));
        fapi2::ATTR_FREQ_IOHS_MHZ_Type l_TGT3_ATTR_FREQ_IOHS_MHZ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_IOHS_MHZ, TGT3, l_TGT3_ATTR_FREQ_IOHS_MHZ));
        fapi2::ATTR_FREQ_PAU_MHZ_Type l_TGT2_ATTR_FREQ_PAU_MHZ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PAU_MHZ, TGT2, l_TGT2_ATTR_FREQ_PAU_MHZ));
        uint64_t l_def_AX_CMD_RATE_2B_R = (((literal_7 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611) %
                                           (l_TGT3_ATTR_FREQ_IOHS_MHZ * literal_2063));
        fapi2::ATTR_IOHS_BUS_WIDTH_Type l_TGT3_ATTR_IOHS_BUS_WIDTH;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_BUS_WIDTH, TGT3, l_TGT3_ATTR_IOHS_BUS_WIDTH));
        uint64_t l_def_AX_CMD_RATE_D = (l_TGT3_ATTR_FREQ_IOHS_MHZ * literal_2063);
        uint64_t l_def_AX_CMD_RATE_2B_N = ((literal_7 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611);
        uint64_t l_def_AX_CMD_RATE_2B_RA = (((literal_6 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611) %
                                            (l_TGT3_ATTR_FREQ_IOHS_MHZ * literal_2063));
        uint64_t l_def_AX_CMD_RATE_2B_NA = ((literal_6 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611);
        uint64_t l_def_AX_CMD_RATE_1B_R = (((literal_12 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611) %
                                           (l_TGT3_ATTR_FREQ_IOHS_MHZ * literal_2063));
        uint64_t l_def_AX_CMD_RATE_1B_N = ((literal_12 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611);
        uint64_t l_def_AX_CMD_RATE_1B_RA = (((literal_11 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611) %
                                            (l_TGT3_ATTR_FREQ_IOHS_MHZ * literal_2063));
        uint64_t l_def_AX_CMD_RATE_1B_NA = ((literal_11 * l_TGT2_ATTR_FREQ_PAU_MHZ) * literal_1611);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x1001180aull, l_scom_buffer ));

            if (((l_def_AX0_ENABLED == literal_1) && (l_def_NUM_A_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<21, 3, 61, uint64_t>(literal_0x5 );
            }
            else if (((l_def_AX0_ENABLED == literal_1) && (l_def_NUM_A_LINKS_CFG != literal_0)))
            {
                l_scom_buffer.insert<21, 3, 61, uint64_t>(literal_0x6 );
            }

            if ((l_def_AX0_ENABLED == literal_1))
            {
                constexpr auto l_PB_PTLSCOM10_FP0_FMR_ENABLE_1PER4_PRESP_ON = 0x1;
                l_scom_buffer.insert<20, 1, 63, uint64_t>(l_PB_PTLSCOM10_FP0_FMR_ENABLE_1PER4_PRESP_ON );
            }

            l_scom_buffer.insert<4, 8, 56, uint64_t>(literal_0x0B );
            l_scom_buffer.insert<12, 8, 56, uint64_t>(literal_0x06 );

            if ((l_def_AX0_ENABLED == literal_1))
            {
                constexpr auto l_PB_PTLSCOM10_FP1_FMR_ENABLE_1PER4_PRESP_ON = 0x1;
                l_scom_buffer.insert<52, 1, 63, uint64_t>(l_PB_PTLSCOM10_FP1_FMR_ENABLE_1PER4_PRESP_ON );
            }

            l_scom_buffer.insert<36, 8, 56, uint64_t>(literal_0x0B );
            l_scom_buffer.insert<44, 8, 56, uint64_t>(literal_0x06 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x1001180aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x1001180cull, l_scom_buffer ));

            if ((l_def_AX0_ENABLED == literal_1))
            {
                l_scom_buffer.insert<25, 2, 62, uint64_t>(literal_0b10 );
            }

            if (((l_TGT3_ATTR_IOHS_BUS_WIDTH == fapi2::ENUM_ATTR_IOHS_BUS_WIDTH_2_BYTE) && (l_def_AX_CMD_RATE_2B_R != literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>((l_def_AX_CMD_RATE_2B_N / l_def_AX_CMD_RATE_D) );
            }
            else if (((l_TGT3_ATTR_IOHS_BUS_WIDTH == fapi2::ENUM_ATTR_IOHS_BUS_WIDTH_2_BYTE)
                      && (l_def_AX_CMD_RATE_2B_R == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(((l_def_AX_CMD_RATE_2B_N / l_def_AX_CMD_RATE_D) - literal_1) );
            }
            else if (((l_TGT3_ATTR_IOHS_BUS_WIDTH == fapi2::ENUM_ATTR_IOHS_BUS_WIDTH_2_BYTE)
                      && (l_def_AX_CMD_RATE_2B_RA != literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>((l_def_AX_CMD_RATE_2B_NA / l_def_AX_CMD_RATE_D) );
            }
            else if (((l_TGT3_ATTR_IOHS_BUS_WIDTH == fapi2::ENUM_ATTR_IOHS_BUS_WIDTH_2_BYTE)
                      && (l_def_AX_CMD_RATE_2B_RA == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(((l_def_AX_CMD_RATE_2B_NA / l_def_AX_CMD_RATE_D) - literal_1) );
            }
            else if (((l_TGT3_ATTR_IOHS_BUS_WIDTH == fapi2::ENUM_ATTR_IOHS_BUS_WIDTH_1_BYTE)
                      && (l_def_AX_CMD_RATE_1B_R != literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>((l_def_AX_CMD_RATE_1B_N / l_def_AX_CMD_RATE_D) );
            }
            else if (((l_TGT3_ATTR_IOHS_BUS_WIDTH == fapi2::ENUM_ATTR_IOHS_BUS_WIDTH_1_BYTE)
                      && (l_def_AX_CMD_RATE_1B_R == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(((l_def_AX_CMD_RATE_1B_N / l_def_AX_CMD_RATE_D) - literal_1) );
            }
            else if (((l_TGT3_ATTR_IOHS_BUS_WIDTH == fapi2::ENUM_ATTR_IOHS_BUS_WIDTH_1_BYTE)
                      && (l_def_AX_CMD_RATE_1B_RA != literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>((l_def_AX_CMD_RATE_1B_NA / l_def_AX_CMD_RATE_D) );
            }
            else if (((l_TGT3_ATTR_IOHS_BUS_WIDTH == fapi2::ENUM_ATTR_IOHS_BUS_WIDTH_1_BYTE)
                      && (l_def_AX_CMD_RATE_1B_RA == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(((l_def_AX_CMD_RATE_1B_NA / l_def_AX_CMD_RATE_D) - literal_1) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x1001180cull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x10011810ull, l_scom_buffer ));

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

            FAPI_TRY(fapi2::putScom(TGT0, 0x10011815ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
