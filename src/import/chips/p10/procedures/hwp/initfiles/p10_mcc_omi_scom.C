/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_mcc_omi_scom.C $ */
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
#include "p10_mcc_omi_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0b100000 = 0b100000;
constexpr uint64_t literal_0b10000 = 0b10000;
constexpr uint64_t literal_0b00000 = 0b00000;
constexpr uint64_t literal_0b0100 = 0b0100;
constexpr uint64_t literal_0b1010 = 0b1010;
constexpr uint64_t literal_0b10 = 0b10;
constexpr uint64_t literal_0x1 = 0x1;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_6 = 6;
constexpr uint64_t literal_0xFF = 0xFF;
constexpr uint64_t literal_0b0000100011 = 0b0000100011;
constexpr uint64_t literal_0b0000110011 = 0b0000110011;
constexpr uint64_t literal_0b0001000000 = 0b0001000000;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_7 = 7;
constexpr uint64_t literal_0b0001 = 0b0001;
constexpr uint64_t literal_0b0010 = 0b0010;
constexpr uint64_t literal_0b1000 = 0b1000;
constexpr uint64_t literal_0b01 = 0b01;
constexpr uint64_t literal_0b0000 = 0b0000;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_0b0110000 = 0b0110000;
constexpr uint64_t literal_0b0100000 = 0b0100000;

fapi2::ReturnCode p10_mcc_omi_scom(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& TGT0,
                                   const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT2)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT2, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT2, l_chip_ec));
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T0_Type l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T0, TGT1, l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0));
        uint64_t l_def_MC_EPSILON_CFG_T0 = ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 + literal_6) / literal_4);
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T1_Type l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T1, TGT1, l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1));
        uint64_t l_def_MC_EPSILON_CFG_T1 = ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 + literal_6) / literal_4);
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T2_Type l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T2, TGT1, l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2));
        uint64_t l_def_MC_EPSILON_CFG_T2 = ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 + literal_6) / literal_4);
        fapi2::ATTR_CHIP_EC_FEATURE_HW548941_Type l_TGT2_ATTR_CHIP_EC_FEATURE_HW548941;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW548941, TGT2, l_TGT2_ATTR_CHIP_EC_FEATURE_HW548941));
        fapi2::ATTR_SYS_DISABLE_MCU_TIMEOUTS_Type l_TGT1_ATTR_SYS_DISABLE_MCU_TIMEOUTS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYS_DISABLE_MCU_TIMEOUTS, TGT1, l_TGT1_ATTR_SYS_DISABLE_MCU_TIMEOUTS));
        fapi2::ATTR_SYS_ENABLE_MC_HW520600_X4CTR_Type l_TGT1_ATTR_SYS_ENABLE_MC_HW520600_X4CTR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYS_ENABLE_MC_HW520600_X4CTR, TGT1, l_TGT1_ATTR_SYS_ENABLE_MC_HW520600_X4CTR));
        fapi2::ATTR_CHIP_EC_FEATURE_HW548786_Type l_TGT2_ATTR_CHIP_EC_FEATURE_HW548786;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW548786, TGT2, l_TGT2_ATTR_CHIP_EC_FEATURE_HW548786));
        fapi2::ATTR_SYS_DISABLE_HWFM_Type l_TGT1_ATTR_SYS_DISABLE_HWFM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYS_DISABLE_HWFM, TGT1, l_TGT1_ATTR_SYS_DISABLE_HWFM));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010c22ull, l_scom_buffer ));

            l_scom_buffer.insert<2, 6, 58, uint64_t>(literal_0b100000 );
            l_scom_buffer.insert<8, 6, 58, uint64_t>(literal_0b100000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc010c22ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010c23ull, l_scom_buffer ));

            l_scom_buffer.insert<25, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<30, 5, 59, uint64_t>(literal_0b00000 );
            l_scom_buffer.insert<43, 4, 60, uint64_t>(literal_0b0100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc010c23ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010c24ull, l_scom_buffer ));

            l_scom_buffer.insert<13, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<40, 2, 62, uint64_t>(literal_0b10 );
            l_scom_buffer.insert<42, 2, 62, uint64_t>(literal_0b10 );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc010c24ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010c26ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x1 );

            if ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 != literal_0))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_MC_EPSILON_CFG_T0 );
            }
            else if ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 == literal_0))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x1 );
            }

            if ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 != literal_0))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(l_def_MC_EPSILON_CFG_T1 );
            }
            else if ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 == literal_0))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x1 );
            }

            if ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 != literal_0))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(l_def_MC_EPSILON_CFG_T1 );
            }
            else if ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 == literal_0))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x1 );
            }

            if ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 != literal_0))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(l_def_MC_EPSILON_CFG_T2 );
            }
            else if ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 == literal_0))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1 );
            }

            if ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 != literal_0))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(l_def_MC_EPSILON_CFG_T2 );
            }
            else if ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 == literal_0))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x1 );
            }

            l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0xFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc010c26ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010c27ull, l_scom_buffer ));

            constexpr auto l_MCP_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS_ON = 0x1;
            l_scom_buffer.insert<0, 1, 63, uint64_t>(l_MCP_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS_ON );
            constexpr auto l_MCP_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_1024_CYCLES = 0x1;
            l_scom_buffer.insert<1, 3, 61, uint64_t>(l_MCP_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_1024_CYCLES );
            l_scom_buffer.insert<4, 10, 54, uint64_t>(literal_0b0000100011 );
            l_scom_buffer.insert<14, 10, 54, uint64_t>(literal_0b0000110011 );
            l_scom_buffer.insert<24, 10, 54, uint64_t>(literal_0b0001000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc010c27ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010c2bull, l_scom_buffer ));

            constexpr auto l_MCP_CHAN0_ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W_ON = 0x1;
            l_scom_buffer.insert<45, 1, 63, uint64_t>(l_MCP_CHAN0_ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W_ON );

            if ((l_TGT2_ATTR_CHIP_EC_FEATURE_HW548941 == literal_1))
            {
                constexpr auto l_MCP_CHAN0_ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_ON = 0x1;
                l_scom_buffer.insert<33, 1, 63, uint64_t>(l_MCP_CHAN0_ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0xc010c2bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010d0bull, l_scom_buffer ));

            if ((l_TGT1_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                l_scom_buffer.insert<49, 3, 61, uint64_t>(literal_7 );
            }

            l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0b0001 );
            l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_0b0010 );
            l_scom_buffer.insert<45, 4, 60, uint64_t>(literal_0b1000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc010d0bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010e0bull, l_scom_buffer ));

            if ((l_TGT1_ATTR_SYS_ENABLE_MC_HW520600_X4CTR == literal_1))
            {
                l_scom_buffer.insert<21, 2, 62, uint64_t>(literal_0b01 );
            }

            if ((l_TGT2_ATTR_CHIP_EC_FEATURE_HW548786 == literal_1))
            {
                l_scom_buffer.insert<40, 4, 60, uint64_t>(literal_0b0000 );
            }

            l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc010e0bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010e0full, l_scom_buffer ));

            if ((l_TGT1_ATTR_SYS_DISABLE_HWFM == literal_0))
            {
                l_scom_buffer.insert<1, 6, 58, uint64_t>(literal_1 );
            }
            else if ((l_TGT1_ATTR_SYS_DISABLE_HWFM == literal_1))
            {
                l_scom_buffer.insert<1, 6, 58, uint64_t>(literal_0 );
            }

            if ((l_TGT1_ATTR_SYS_DISABLE_HWFM == literal_0))
            {
                constexpr auto l_MCP_CHAN0_USTL_USTLMCHWFM_ENABLE_ON = 0x1;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_MCP_CHAN0_USTL_USTLMCHWFM_ENABLE_ON );
            }
            else if ((l_TGT1_ATTR_SYS_DISABLE_HWFM == literal_1))
            {
                constexpr auto l_MCP_CHAN0_USTL_USTLMCHWFM_ENABLE_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_MCP_CHAN0_USTL_USTLMCHWFM_ENABLE_OFF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0xc010e0full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010f48ull, l_scom_buffer ));

            constexpr auto l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE_ON = 0x1;
            l_scom_buffer.insert<9, 1, 63, uint64_t>(l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc010f48ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010f4dull, l_scom_buffer ));

            l_scom_buffer.insert<19, 7, 57, uint64_t>(literal_0b0110000 );
            l_scom_buffer.insert<27, 7, 57, uint64_t>(literal_0b0100000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc010f4dull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
