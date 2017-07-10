/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9n_mcs_scom.C $ */
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
#include "p9n_mcs_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0b0111 = 0b0111;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_8 = 8;
constexpr uint64_t literal_25 = 25;
constexpr uint64_t literal_0b001111 = 0b001111;
constexpr uint64_t literal_0b0001100000000 = 0b0001100000000;
constexpr uint64_t literal_1350 = 1350;
constexpr uint64_t literal_1000 = 1000;
constexpr uint64_t literal_0b0000000000001000 = 0b0000000000001000;

fapi2::ReturnCode p9n_mcs_scom(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& TGT0,
                               const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT2,
                               const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& TGT3)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT2, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT2, l_chip_ec));
        fapi2::ATTR_CHIP_EC_FEATURE_HW398139_Type l_TGT2_ATTR_CHIP_EC_FEATURE_HW398139;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW398139, TGT2, l_TGT2_ATTR_CHIP_EC_FEATURE_HW398139));
        fapi2::ATTR_RISK_LEVEL_Type l_TGT1_ATTR_RISK_LEVEL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_RISK_LEVEL, TGT1, l_TGT1_ATTR_RISK_LEVEL));
        fapi2::ATTR_FREQ_PB_MHZ_Type l_TGT1_ATTR_FREQ_PB_MHZ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PB_MHZ, TGT1, l_TGT1_ATTR_FREQ_PB_MHZ));
        fapi2::ATTR_MSS_FREQ_Type l_TGT3_ATTR_MSS_FREQ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_FREQ, TGT3, l_TGT3_ATTR_MSS_FREQ));
        uint64_t l_def_mn_freq_ratio = ((literal_1000 * l_TGT3_ATTR_MSS_FREQ) / l_TGT1_ATTR_FREQ_PB_MHZ);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010810ull, l_scom_buffer ));

            l_scom_buffer.insert<46, 4, 60, uint64_t>(literal_0b0111 );
            l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0 );
            constexpr auto l_MC01_PBI01_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST_ON = 0x1;
            l_scom_buffer.insert<61, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST_ON );

            if ((l_TGT2_ATTR_CHIP_EC_FEATURE_HW398139 == literal_1))
            {
                l_scom_buffer.insert<32, 7, 57, uint64_t>(literal_8 );
            }
            else if ((l_TGT2_ATTR_CHIP_EC_FEATURE_HW398139 != literal_1))
            {
                l_scom_buffer.insert<32, 7, 57, uint64_t>(literal_25 );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) )
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b001111 );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) )
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE_ON = 0x1;
                l_scom_buffer.insert<63, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5010810ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5010811ull, l_scom_buffer ));

                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_SYNC_ON = 0x1;
                l_scom_buffer.insert<20, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_SYNC_ON );
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_64_128B_READ_ON = 0x1;
                l_scom_buffer.insert<9, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_64_128B_READ_ON );
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_DROP_FP_DYN64_ACTIVE_ON = 0x1;
                l_scom_buffer.insert<8, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_DROP_FP_DYN64_ACTIVE_ON );
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_CENTAURP_ENABLE_ECRESP_OFF = 0x0;
                l_scom_buffer.insert<7, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_CENTAURP_ENABLE_ECRESP_OFF );
                FAPI_TRY(fapi2::putScom(TGT0, 0x5010811ull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010812ull, l_scom_buffer ));

            constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT_ON = 0x1;
            l_scom_buffer.insert<10, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5010812ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010813ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_TGT1_ATTR_RISK_LEVEL == literal_0))
                {
                    l_scom_buffer.insert<1, 13, 51, uint64_t>(literal_0b0001100000000 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_mn_freq_ratio <= literal_1350))
                {
                    constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE_OFF = 0x0;
                    l_scom_buffer.insert<0, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE_OFF );
                }
                else if ((l_def_mn_freq_ratio > literal_1350))
                {
                    constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE_ON = 0x1;
                    l_scom_buffer.insert<0, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE_ON );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) )
            {
                l_scom_buffer.insert<24, 16, 48, uint64_t>(literal_0b0000000000001000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5010813ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
