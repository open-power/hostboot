/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9c_mi_scom.C $  */
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
#include "p9c_mi_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_7 = 7;
constexpr uint64_t literal_16 = 16;
constexpr uint64_t literal_8 = 8;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0x19 = 0x19;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_1167 = 1167;
constexpr uint64_t literal_1000 = 1000;
constexpr uint64_t literal_1273 = 1273;
constexpr uint64_t literal_1200 = 1200;
constexpr uint64_t literal_1400 = 1400;
constexpr uint64_t literal_1500 = 1500;
constexpr uint64_t literal_0b0000000000001000000 = 0b0000000000001000000;
constexpr uint64_t literal_0b0000000000001000 = 0b0000000000001000;
constexpr uint64_t literal_0b01 = 0b01;
constexpr uint64_t literal_5 = 5;

fapi2::ReturnCode p9c_mi_scom(const fapi2::Target<fapi2::TARGET_TYPE_MI>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT2)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT2, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT2, l_chip_ec));
        uint64_t l_def_ENABLE_PREFETCH_DROP_PROMOTE_BASIC = literal_1;
        fapi2::ATTR_CHIP_EC_FEATURE_HW413362_P9UDD11_ASYNC_Type l_TGT2_ATTR_CHIP_EC_FEATURE_HW413362_P9UDD11_ASYNC;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW413362_P9UDD11_ASYNC, TGT2,
                               l_TGT2_ATTR_CHIP_EC_FEATURE_HW413362_P9UDD11_ASYNC));
        fapi2::ATTR_MC_SYNC_MODE_Type l_TGT2_ATTR_MC_SYNC_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MC_SYNC_MODE, TGT2, l_TGT2_ATTR_MC_SYNC_MODE));
        fapi2::ATTR_FREQ_PB_MHZ_Type l_TGT1_ATTR_FREQ_PB_MHZ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PB_MHZ, TGT1, l_TGT1_ATTR_FREQ_PB_MHZ));
        fapi2::ATTR_FREQ_MCA_MHZ_Type l_TGT1_ATTR_FREQ_MCA_MHZ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_MCA_MHZ, TGT1, l_TGT1_ATTR_FREQ_MCA_MHZ));
        uint64_t l_def_MCA_FREQ = l_TGT1_ATTR_FREQ_MCA_MHZ;
        uint64_t l_def_MN_FREQ_RATIO = ((literal_1000 * l_def_MCA_FREQ) / l_TGT1_ATTR_FREQ_PB_MHZ);
        uint64_t l_def_ENABLE_DYNAMIC_64_128B_READS = literal_0;
        uint64_t l_def_ENABLE_ECRESP = literal_1;
        uint64_t l_def_ENABLE_AMO_CACHING = literal_1;
        uint64_t l_def_ENABLE_HWFM = literal_1;
        uint64_t l_def_ENABLE_MCU_TIMEOUTS = literal_1;
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010810ull, l_scom_buffer ));

            l_scom_buffer.insert<46, 4, 60, uint64_t>(literal_7 );
            l_scom_buffer.insert<50, 5, 59, uint64_t>(literal_16 );
            l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_8 );

            if ((l_def_ENABLE_PREFETCH_DROP_PROMOTE_BASIC == literal_1))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST_ON = 0x1;
                l_scom_buffer.insert<61, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST_ON );
            }

            if ((l_def_ENABLE_PREFETCH_DROP_PROMOTE_BASIC == literal_1))
            {
                l_scom_buffer.insert<32, 7, 57, uint64_t>(literal_0x19 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5010810ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010811ull, l_scom_buffer ));

            if (((l_TGT2_ATTR_MC_SYNC_MODE == literal_1) && (l_TGT2_ATTR_CHIP_EC_FEATURE_HW413362_P9UDD11_ASYNC == literal_0)))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ASYNC_MODE_ON = 0x1;
                l_scom_buffer.insert<6, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ASYNC_MODE_ON );
            }
            else if (((l_TGT2_ATTR_MC_SYNC_MODE == literal_1) && (l_TGT2_ATTR_CHIP_EC_FEATURE_HW413362_P9UDD11_ASYNC == literal_1)))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ASYNC_MODE_OFF = 0x0;
                l_scom_buffer.insert<6, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ASYNC_MODE_OFF );
            }
            else if (((l_TGT2_ATTR_MC_SYNC_MODE == literal_0) && (l_def_MN_FREQ_RATIO < literal_1167)))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ASYNC_MODE_ON = 0x1;
                l_scom_buffer.insert<6, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ASYNC_MODE_ON );
            }
            else if ((((l_TGT2_ATTR_MC_SYNC_MODE == literal_0) && (l_def_MN_FREQ_RATIO >= literal_1200))
                      && (l_def_MN_FREQ_RATIO < literal_1273)))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ASYNC_MODE_ON = 0x1;
                l_scom_buffer.insert<6, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ASYNC_MODE_ON );
            }
            else if ((((l_TGT2_ATTR_MC_SYNC_MODE == literal_0) && (l_def_MN_FREQ_RATIO >= literal_1167))
                      && (l_def_MN_FREQ_RATIO < literal_1200)))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ASYNC_MODE_ON = 0x1;
                l_scom_buffer.insert<6, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ASYNC_MODE_ON );
            }
            else if ((((l_TGT2_ATTR_MC_SYNC_MODE == literal_0) && (l_def_MN_FREQ_RATIO >= literal_1273))
                      && (l_def_MN_FREQ_RATIO < literal_1400)))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ASYNC_MODE_ON = 0x1;
                l_scom_buffer.insert<6, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ASYNC_MODE_ON );
            }
            else if ((((l_TGT2_ATTR_MC_SYNC_MODE == literal_0) && (l_def_MN_FREQ_RATIO >= literal_1400))
                      && (l_def_MN_FREQ_RATIO < literal_1500)))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ASYNC_MODE_ON = 0x1;
                l_scom_buffer.insert<6, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ASYNC_MODE_ON );
            }

            if (((l_TGT2_ATTR_MC_SYNC_MODE == literal_1) && (l_TGT2_ATTR_CHIP_EC_FEATURE_HW413362_P9UDD11_ASYNC == literal_0)))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_SYNC_MODE_OFF = 0x0;
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_SYNC_MODE_OFF );
            }
            else if (((l_TGT2_ATTR_MC_SYNC_MODE == literal_1) && (l_TGT2_ATTR_CHIP_EC_FEATURE_HW413362_P9UDD11_ASYNC == literal_1)))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_SYNC_MODE_ON = 0x1;
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_SYNC_MODE_ON );
            }
            else if (((l_TGT2_ATTR_MC_SYNC_MODE == literal_0) && (l_def_MN_FREQ_RATIO < literal_1167)))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_SYNC_MODE_OFF = 0x0;
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_SYNC_MODE_OFF );
            }
            else if ((((l_TGT2_ATTR_MC_SYNC_MODE == literal_0) && (l_def_MN_FREQ_RATIO >= literal_1200))
                      && (l_def_MN_FREQ_RATIO < literal_1273)))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_SYNC_MODE_OFF = 0x0;
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_SYNC_MODE_OFF );
            }
            else if ((((l_TGT2_ATTR_MC_SYNC_MODE == literal_0) && (l_def_MN_FREQ_RATIO >= literal_1167))
                      && (l_def_MN_FREQ_RATIO < literal_1200)))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_SYNC_MODE_OFF = 0x0;
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_SYNC_MODE_OFF );
            }
            else if ((((l_TGT2_ATTR_MC_SYNC_MODE == literal_0) && (l_def_MN_FREQ_RATIO >= literal_1273))
                      && (l_def_MN_FREQ_RATIO < literal_1400)))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_SYNC_MODE_OFF = 0x0;
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_SYNC_MODE_OFF );
            }
            else if ((((l_TGT2_ATTR_MC_SYNC_MODE == literal_0) && (l_def_MN_FREQ_RATIO >= literal_1400))
                      && (l_def_MN_FREQ_RATIO < literal_1500)))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_SYNC_MODE_OFF = 0x0;
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_SYNC_MODE_OFF );
            }

            constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC_ON = 0x1;
            l_scom_buffer.insert<27, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC_ON );
            constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_PAIR_SYNC_ON = 0x1;
            l_scom_buffer.insert<28, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_PAIR_SYNC_ON );
            constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND_OFF );
            constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE_ON = 0x1;
            l_scom_buffer.insert<21, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE_ON );
            constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND_ON = 0x1;
            l_scom_buffer.insert<22, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND_ON );
            constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND_ON = 0x1;
            l_scom_buffer.insert<23, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND_ON );

            if ((l_def_ENABLE_DYNAMIC_64_128B_READS == literal_1))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_64_128B_READ_ON = 0x1;
                l_scom_buffer.insert<9, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_64_128B_READ_ON );
            }
            else if ((l_def_ENABLE_DYNAMIC_64_128B_READS == literal_0))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_64_128B_READ_OFF = 0x0;
                l_scom_buffer.insert<9, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_64_128B_READ_OFF );
            }

            if ((l_def_ENABLE_ECRESP == literal_1))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_CENTAURP_ENABLE_ECRESP_ON = 0x1;
                l_scom_buffer.insert<7, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_CENTAURP_ENABLE_ECRESP_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5010811ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010812ull, l_scom_buffer ));

            l_scom_buffer.insert<33, 19, 45, uint64_t>(literal_0b0000000000001000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5010812ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010813ull, l_scom_buffer ));

            if ((l_def_ENABLE_AMO_CACHING == literal_1))
            {
                l_scom_buffer.insert<24, 16, 48, uint64_t>(literal_0b0000000000001000 );
            }

            if ((l_def_ENABLE_HWFM == literal_1))
            {
                l_scom_buffer.insert<47, 6, 58, uint64_t>(literal_1 );
            }
            else if ((l_def_ENABLE_HWFM == literal_0))
            {
                l_scom_buffer.insert<47, 6, 58, uint64_t>(literal_0 );
            }

            if ((l_def_ENABLE_HWFM == literal_1))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE2_MCHWFM_ENABLE_ON = 0x1;
                l_scom_buffer.insert<46, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE2_MCHWFM_ENABLE_ON );
            }
            else if ((l_def_ENABLE_HWFM == literal_0))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE2_MCHWFM_ENABLE_OFF = 0x0;
                l_scom_buffer.insert<46, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE2_MCHWFM_ENABLE_OFF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5010813ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501081bull, l_scom_buffer ));

            if ((l_def_ENABLE_MCU_TIMEOUTS == literal_1))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCTO_SELECT_PB_HANG_PULSE_ON = 0x1;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCTO_SELECT_PB_HANG_PULSE_ON );
            }

            constexpr auto l_MC01_PBI01_SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE_OFF = 0x0;
            l_scom_buffer.insert<1, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE_OFF );

            if ((l_def_ENABLE_MCU_TIMEOUTS == literal_1))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG_ON = 0x1;
                l_scom_buffer.insert<36, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG_ON );
            }

            if ((l_def_ENABLE_MCU_TIMEOUTS == literal_1))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG_ON = 0x1;
                l_scom_buffer.insert<32, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG_ON );
            }

            if ((l_def_ENABLE_MCU_TIMEOUTS == literal_1))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCTO_ENABLE_MIRROR_HANG_ON = 0x1;
                l_scom_buffer.insert<33, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCTO_ENABLE_MIRROR_HANG_ON );
            }

            if ((l_def_ENABLE_MCU_TIMEOUTS == literal_1))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCTO_ENABLE_APO_HANG_ON = 0x1;
                l_scom_buffer.insert<34, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCTO_ENABLE_APO_HANG_ON );
            }

            if ((l_def_ENABLE_MCU_TIMEOUTS == literal_1))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCTO_ENABLE_CLIB_HANG_ON = 0x1;
                l_scom_buffer.insert<35, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCTO_ENABLE_CLIB_HANG_ON );
            }

            l_scom_buffer.insert<2, 2, 62, uint64_t>(literal_0b01 );

            if ((l_def_ENABLE_MCU_TIMEOUTS == literal_1))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_1 );
            }

            if ((l_def_ENABLE_MCU_TIMEOUTS == literal_1))
            {
                l_scom_buffer.insert<5, 3, 61, uint64_t>(literal_7 );
            }

            if ((l_def_ENABLE_MCU_TIMEOUTS == literal_1))
            {
                l_scom_buffer.insert<37, 3, 61, uint64_t>(literal_5 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x501081bull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
