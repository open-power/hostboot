/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9c_dmi_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#include "p9c_dmi_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_8 = 8;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_24 = 24;
constexpr uint64_t literal_12 = 12;
constexpr uint64_t literal_0b0100 = 0b0100;
constexpr uint64_t literal_28 = 28;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0x1 = 0x1;
constexpr uint64_t literal_0x3 = 0x3;
constexpr uint64_t literal_0x5 = 0x5;
constexpr uint64_t literal_0x7 = 0x7;
constexpr uint64_t literal_0b0000000000000000111111111 = 0b0000000000000000111111111;
constexpr uint64_t literal_0b1100111111111111111111111 = 0b1100111111111111111111111;
constexpr uint64_t literal_6 = 6;
constexpr uint64_t literal_0x26 = 0x26;
constexpr uint64_t literal_0x33 = 0x33;
constexpr uint64_t literal_0x40 = 0x40;
constexpr uint64_t literal_3 = 3;
constexpr uint64_t literal_0b0 = 0b0;

fapi2::ReturnCode p9c_dmi_scom(const fapi2::Target<fapi2::TARGET_TYPE_DMI>& TGT0,
                               const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT3)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT3, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT3, l_chip_ec));
        uint64_t l_def_ENABLE_AMO_CACHING = literal_1;
        uint64_t l_def_ENABLE_AMO_CLEAN_LINES = literal_1;
        uint64_t l_def_ENABLE_DYNAMIC_64_128B_READS = literal_0;
        uint64_t l_def_ENABLE_PREFETCH_DROP_PROMOTE_BASIC = literal_1;
        uint64_t l_def_ENABLE_RMW_IN_PROC = literal_1;
        uint64_t l_def_ENABLE_PREFETCH_DROP_PROMOTE_PERFORMANCE = literal_1;
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T0_Type l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T0, TGT1, l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0));
        uint64_t l_def_MC_EPSILON_CFG_T0 = ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 + literal_6) / literal_4);
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T1_Type l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T1, TGT1, l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1));
        uint64_t l_def_MC_EPSILON_CFG_T1 = ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 + literal_6) / literal_4);
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T2_Type l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T2, TGT1, l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2));
        uint64_t l_def_MC_EPSILON_CFG_T2 = ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 + literal_6) / literal_4);
        uint64_t l_def_ENABLE_MCBUSY = literal_1;
        uint64_t l_def_ENABLE_MCU_TIMEOUTS = literal_1;
        uint64_t l_def_MCICFG_REPLAY_DELAY = literal_1;
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010823ull, l_scom_buffer ));

            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_4 );
            l_scom_buffer.insert<40, 6, 58, uint64_t>(literal_8 );

            if (l_def_ENABLE_AMO_CACHING)
            {
                l_scom_buffer.insert<22, 6, 58, uint64_t>(literal_24 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5010823ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010824ull, l_scom_buffer ));

            if ((l_def_ENABLE_AMO_CLEAN_LINES == literal_1))
            {
                l_scom_buffer.insert<44, 6, 58, uint64_t>(literal_12 );
            }

            l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0b0100 );
            constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_ENABLE_REFRESH_BLOCK_SQ_OFF = 0x0;
            l_scom_buffer.insert<16, 1, 63, uint64_t>(l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_ENABLE_REFRESH_BLOCK_SQ_OFF );
            constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_ENABLE_REFRESH_BLOCK_NSQ_OFF = 0x0;
            l_scom_buffer.insert<17, 1, 63, uint64_t>(l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_ENABLE_REFRESH_BLOCK_NSQ_OFF );
            constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_ENABLE_REFRESH_BLOCK_DISP_OFF = 0x0;
            l_scom_buffer.insert<18, 1, 63, uint64_t>(l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_ENABLE_REFRESH_BLOCK_DISP_OFF );
            l_scom_buffer.insert<50, 5, 59, uint64_t>(literal_28 );

            if ((l_def_ENABLE_DYNAMIC_64_128B_READS == literal_1))
            {
                constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_EN_64_128_PB_READ_ON = 0x1;
                l_scom_buffer.insert<36, 1, 63, uint64_t>(l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_EN_64_128_PB_READ_ON );
            }
            else if ((l_def_ENABLE_DYNAMIC_64_128B_READS == literal_0))
            {
                constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_EN_64_128_PB_READ_OFF = 0x0;
                l_scom_buffer.insert<36, 1, 63, uint64_t>(l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_EN_64_128_PB_READ_OFF );
            }

            if (l_def_ENABLE_DYNAMIC_64_128B_READS)
            {
                l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_8 );
            }

            if (l_def_ENABLE_PREFETCH_DROP_PROMOTE_BASIC)
            {
                l_scom_buffer.insert<0, 3, 61, uint64_t>(literal_0x1 );
            }

            if (l_def_ENABLE_PREFETCH_DROP_PROMOTE_BASIC)
            {
                l_scom_buffer.insert<3, 3, 61, uint64_t>(literal_0x3 );
            }

            if (l_def_ENABLE_PREFETCH_DROP_PROMOTE_BASIC)
            {
                l_scom_buffer.insert<6, 3, 61, uint64_t>(literal_0x5 );
            }

            if (l_def_ENABLE_PREFETCH_DROP_PROMOTE_BASIC)
            {
                l_scom_buffer.insert<9, 3, 61, uint64_t>(literal_0x7 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5010824ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010825ull, l_scom_buffer ));

            if ((l_def_ENABLE_AMO_CLEAN_LINES == literal_1))
            {
                constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_ON = 0x1;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_ON );
            }

            if ((l_def_ENABLE_RMW_IN_PROC == literal_1))
            {
                l_scom_buffer.insert<32, 25, 39, uint64_t>(literal_0b0000000000000000111111111 );
            }

            if (l_def_ENABLE_AMO_CACHING)
            {
                l_scom_buffer.insert<4, 25, 39, uint64_t>(literal_0b1100111111111111111111111 );
            }

            if (l_def_ENABLE_AMO_CACHING)
            {
                constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_128B_RW_64B_DATA = 0x1;
                l_scom_buffer.insert<29, 3, 61, uint64_t>(l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_128B_RW_64B_DATA );
            }

            if (l_def_ENABLE_PREFETCH_DROP_PROMOTE_PERFORMANCE)
            {
                constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 63, uint64_t>(l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0_OFF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5010825ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010826ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_MC_EPSILON_CFG_T0 );
            l_scom_buffer.insert<16, 8, 56, uint64_t>(l_def_MC_EPSILON_CFG_T1 );
            l_scom_buffer.insert<24, 8, 56, uint64_t>(l_def_MC_EPSILON_CFG_T1 );
            l_scom_buffer.insert<32, 8, 56, uint64_t>(l_def_MC_EPSILON_CFG_T2 );
            l_scom_buffer.insert<40, 8, 56, uint64_t>(l_def_MC_EPSILON_CFG_T2 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5010826ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010827ull, l_scom_buffer ));

            if (l_def_ENABLE_MCBUSY)
            {
                constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS_ON = 0x1;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS_ON );
            }

            if (l_def_ENABLE_MCBUSY)
            {
                constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_1024_CYCLES = 0x1;
                l_scom_buffer.insert<1, 3, 61, uint64_t>(l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_1024_CYCLES );
            }

            if (l_def_ENABLE_MCBUSY)
            {
                l_scom_buffer.insert<4, 10, 54, uint64_t>(literal_0x26 );
            }

            if (l_def_ENABLE_MCBUSY)
            {
                l_scom_buffer.insert<14, 10, 54, uint64_t>(literal_0x33 );
            }

            if (l_def_ENABLE_MCBUSY)
            {
                l_scom_buffer.insert<24, 10, 54, uint64_t>(literal_0x40 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5010827ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501082bull, l_scom_buffer ));

            if (l_def_ENABLE_AMO_CACHING)
            {
                constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL_ON = 0x1;
                l_scom_buffer.insert<45, 1, 63, uint64_t>(l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL_ON );
            }

            if (l_def_ENABLE_PREFETCH_DROP_PROMOTE_PERFORMANCE)
            {
                constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 63, uint64_t>(l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY_OFF );
            }

            if (l_def_ENABLE_PREFETCH_DROP_PROMOTE_PERFORMANCE)
            {
                l_scom_buffer.insert<15, 4, 60, uint64_t>(literal_0 );
            }

            if (l_def_ENABLE_PREFETCH_DROP_PROMOTE_PERFORMANCE)
            {
                l_scom_buffer.insert<19, 4, 60, uint64_t>(literal_0 );
            }

            if (l_def_ENABLE_PREFETCH_DROP_PROMOTE_PERFORMANCE)
            {
                l_scom_buffer.insert<23, 4, 60, uint64_t>(literal_0 );
            }

            if (l_def_ENABLE_PREFETCH_DROP_PROMOTE_PERFORMANCE)
            {
                l_scom_buffer.insert<27, 4, 60, uint64_t>(literal_0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x501082bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x701090aull, l_scom_buffer ));

            if ((l_def_ENABLE_MCU_TIMEOUTS == literal_1))
            {
                l_scom_buffer.insert<47, 3, 61, uint64_t>(literal_3 );
            }

            l_scom_buffer.insert<21, 4, 60, uint64_t>(l_def_MCICFG_REPLAY_DELAY );
            FAPI_TRY(fapi2::putScom(TGT0, 0x701090aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x701090eull, l_scom_buffer ));

            constexpr auto l_MCP_CHAN0_CHI_MCICFG1Q_ECC_RDC_CFG_FIFO_TENURE_3_OFF = 0x0;
            l_scom_buffer.insert<33, 1, 63, uint64_t>(l_MCP_CHAN0_CHI_MCICFG1Q_ECC_RDC_CFG_FIFO_TENURE_3_OFF );
            l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0b0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x701090eull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7010914ull, l_scom_buffer ));

            constexpr auto l_MCP_CHAN0_CHI_MBSECCQ_DELAY_NONBYPASS_ON = 0x1;
            l_scom_buffer.insert<37, 1, 63, uint64_t>(l_MCP_CHAN0_CHI_MBSECCQ_DELAY_NONBYPASS_ON );
            l_scom_buffer.insert<35, 2, 62, uint64_t>(literal_0 );
            constexpr auto l_MCP_CHAN0_CHI_MBSECCQ_DELAY_VALID_1X_OFF = 0x0;
            l_scom_buffer.insert<34, 1, 63, uint64_t>(l_MCP_CHAN0_CHI_MBSECCQ_DELAY_VALID_1X_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x7010914ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7012348ull, l_scom_buffer ));

            if (l_def_ENABLE_AMO_CACHING)
            {
                constexpr auto l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE_ON = 0x1;
                l_scom_buffer.insert<9, 1, 63, uint64_t>(l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x7012348ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
