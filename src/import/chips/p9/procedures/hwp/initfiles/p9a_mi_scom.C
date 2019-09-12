/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9a_mi_scom.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
#include "p9a_mi_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_7 = 7;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0x19 = 0x19;
constexpr uint64_t literal_0b1111000000 = 0b1111000000;
constexpr uint64_t literal_0b0111111 = 0b0111111;
constexpr uint64_t literal_0b0000000000001000 = 0b0000000000001000;
constexpr uint64_t literal_0b011 = 0b011;
constexpr uint64_t literal_0b01 = 0b01;

fapi2::ReturnCode p9a_mi_scom(const fapi2::Target<fapi2::TARGET_TYPE_MI>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        uint64_t l_def_ENABLE_PREFETCH_DROP_PROMOTE_BASIC = literal_1;
        fapi2::ATTR_ENABLE_MEM_EARLY_DATA_SCOM_Type l_TGT1_ATTR_ENABLE_MEM_EARLY_DATA_SCOM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ENABLE_MEM_EARLY_DATA_SCOM, TGT1, l_TGT1_ATTR_ENABLE_MEM_EARLY_DATA_SCOM));
        uint64_t l_def_ENABLE_AMO_CACHING = literal_1;
        uint64_t l_def_ENABLE_MCU_TIMEOUTS = literal_1;
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010810ull, l_scom_buffer ));

            l_scom_buffer.insert<17, 4, 60, uint64_t>(literal_7 );

            if ((l_def_ENABLE_PREFETCH_DROP_PROMOTE_BASIC == literal_1))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST_ON = 0x1;
                l_scom_buffer.insert<21, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST_ON );
            }

            if ((l_def_ENABLE_PREFETCH_DROP_PROMOTE_BASIC == literal_1))
            {
                l_scom_buffer.insert<10, 7, 57, uint64_t>(literal_0x19 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5010810ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010811ull, l_scom_buffer ));

            constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC_ON = 0x1;
            l_scom_buffer.insert<12, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC_ON );
            constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_PAIR_SYNC_ON = 0x1;
            l_scom_buffer.insert<13, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_PAIR_SYNC_ON );
            constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND_ON = 0x1;
            l_scom_buffer.insert<2, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND_ON );
            constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE_ON = 0x1;
            l_scom_buffer.insert<8, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE_ON );
            constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND_ON = 0x1;
            l_scom_buffer.insert<9, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND_ON );
            constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND_ON = 0x1;
            l_scom_buffer.insert<10, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND_ON );

            if ((l_TGT1_ATTR_ENABLE_MEM_EARLY_DATA_SCOM == fapi2::ENUM_ATTR_ENABLE_MEM_EARLY_DATA_SCOM_OFF))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_ECRESP_OFF = 0x0;
                l_scom_buffer.insert<4, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_ECRESP_OFF );
            }
            else if ((l_TGT1_ATTR_ENABLE_MEM_EARLY_DATA_SCOM == fapi2::ENUM_ATTR_ENABLE_MEM_EARLY_DATA_SCOM_ON))
            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_ECRESP_ON = 0x1;
                l_scom_buffer.insert<4, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_ENABLE_ECRESP_ON );
            }

            l_scom_buffer.insert<15, 10, 54, uint64_t>(literal_0b1111000000 );
            l_scom_buffer.insert<25, 7, 57, uint64_t>(literal_0b0111111 );
            constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID_ON = 0x1;
            l_scom_buffer.insert<5, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5010811ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5010813ull, l_scom_buffer ));

            if ((l_def_ENABLE_AMO_CACHING == literal_1))
            {
                l_scom_buffer.insert<24, 16, 48, uint64_t>(literal_0b0000000000001000 );
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
                constexpr auto l_MC01_PBI01_SCOMFIR_MCTO_ENABLE_CHANNEL_HANG_ON = 0x1;
                l_scom_buffer.insert<33, 1, 63, uint64_t>(l_MC01_PBI01_SCOMFIR_MCTO_ENABLE_CHANNEL_HANG_ON );
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

            l_scom_buffer.insert<37, 3, 61, uint64_t>(literal_0b011 );
            l_scom_buffer.insert<2, 2, 62, uint64_t>(literal_0b01 );

            if ((l_def_ENABLE_MCU_TIMEOUTS == literal_1))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_1 );
            }

            if ((l_def_ENABLE_MCU_TIMEOUTS == literal_1))
            {
                l_scom_buffer.insert<5, 3, 61, uint64_t>(literal_7 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x501081bull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
