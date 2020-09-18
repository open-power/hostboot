/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_mi_omi_scom.C $ */
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
#include "p10_mi_omi_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_0b01111 = 0b01111;
constexpr uint64_t literal_0b0000000000000000000 = 0b0000000000000000000;
constexpr uint64_t literal_0b1111111111111111111 = 0b1111111111111111111;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0xFFFF = 0xFFFF;
constexpr uint64_t literal_112 = 112;
constexpr uint64_t literal_0x7 = 0x7;
constexpr uint64_t literal_2 = 2;

fapi2::ReturnCode p10_mi_omi_scom(const fapi2::Target<fapi2::TARGET_TYPE_MI>& TGT0,
                                  const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT2)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT2, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT2, l_chip_ec));
        fapi2::ATTR_MEM_MIRROR_PLACEMENT_POLICY_Type l_TGT1_ATTR_MEM_MIRROR_PLACEMENT_POLICY;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_MIRROR_PLACEMENT_POLICY, TGT1, l_TGT1_ATTR_MEM_MIRROR_PLACEMENT_POLICY));
        fapi2::ATTR_PROC_MEMORY_ENCRYPTION_ENABLED_Type l_TGT2_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_MEMORY_ENCRYPTION_ENABLED, TGT2, l_TGT2_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED));
        fapi2::ATTR_SYS_DISABLE_MCU_TIMEOUTS_Type l_TGT1_ATTR_SYS_DISABLE_MCU_TIMEOUTS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYS_DISABLE_MCU_TIMEOUTS, TGT1, l_TGT1_ATTR_SYS_DISABLE_MCU_TIMEOUTS));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010c10ull, l_scom_buffer ));

            l_scom_buffer.insert<44, 1, 63, uint64_t>(literal_0b1 );
            constexpr auto l_MCP_PBI01_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE_ON = 0x1;
            l_scom_buffer.insert<22, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE_ON );
            l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b01111 );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc010c10ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010c11ull, l_scom_buffer ));

            constexpr auto l_MCP_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND_ON = 0x1;
            l_scom_buffer.insert<2, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND_ON );

            if ((l_TGT1_ATTR_MEM_MIRROR_PLACEMENT_POLICY == fapi2::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED))
            {
                constexpr auto l_MCP_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE_ON = 0x1;
                l_scom_buffer.insert<36, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE_ON );
            }
            else if ((l_TGT1_ATTR_MEM_MIRROR_PLACEMENT_POLICY == fapi2::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL))
            {
                constexpr auto l_MCP_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE_OFF = 0x0;
                l_scom_buffer.insert<36, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE_OFF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0xc010c11ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010c12ull, l_scom_buffer ));

            constexpr auto l_MCP_PBI01_SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT_ON = 0x1;
            l_scom_buffer.insert<9, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0xc010c12ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010c16ull, l_scom_buffer ));

            if ((l_TGT2_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED != fapi2::ENUM_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED_DISABLED))
            {
                constexpr auto l_MCP_PBI01_SCOMFIR_MCFGP0E_ENC_VALID_ON = 0x1;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCFGP0E_ENC_VALID_ON );
            }

            if ((l_TGT2_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED != fapi2::ENUM_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED_DISABLED))
            {
                constexpr auto l_MCP_PBI01_SCOMFIR_MCFGP0E_ENC_EXTEND_TO_END_OF_RANGE_ON = 0x1;
                l_scom_buffer.insert<1, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCFGP0E_ENC_EXTEND_TO_END_OF_RANGE_ON );
            }

            if ((l_TGT2_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED != fapi2::ENUM_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED_DISABLED))
            {
                l_scom_buffer.insert<2, 19, 45, uint64_t>(literal_0b0000000000000000000 );
            }

            if ((l_TGT2_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED != fapi2::ENUM_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED_DISABLED))
            {
                l_scom_buffer.insert<21, 19, 45, uint64_t>(literal_0b1111111111111111111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0xc010c16ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010c17ull, l_scom_buffer ));

            if ((l_TGT2_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED != fapi2::ENUM_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED_DISABLED))
            {
                constexpr auto l_MCP_PBI01_SCOMFIR_MCFGP1E_ENC_VALID_ON = 0x1;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCFGP1E_ENC_VALID_ON );
            }

            if ((l_TGT2_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED != fapi2::ENUM_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED_DISABLED))
            {
                constexpr auto l_MCP_PBI01_SCOMFIR_MCFGP1E_ENC_EXTEND_TO_END_OF_RANGE_ON = 0x1;
                l_scom_buffer.insert<1, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCFGP1E_ENC_EXTEND_TO_END_OF_RANGE_ON );
            }

            if ((l_TGT2_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED != fapi2::ENUM_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED_DISABLED))
            {
                l_scom_buffer.insert<2, 19, 45, uint64_t>(literal_0b0000000000000000000 );
            }

            if ((l_TGT2_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED != fapi2::ENUM_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED_DISABLED))
            {
                l_scom_buffer.insert<21, 19, 45, uint64_t>(literal_0b1111111111111111111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0xc010c17ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010c1bull, l_scom_buffer ));

            if ((l_TGT1_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                constexpr auto l_MCP_PBI01_SCOMFIR_MCTO_SELECT_PB_HANG_PULSE_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCTO_SELECT_PB_HANG_PULSE_OFF );
            }

            if ((l_TGT1_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                constexpr auto l_MCP_PBI01_SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE_ON = 0x1;
                l_scom_buffer.insert<1, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE_ON );
            }

            if ((l_TGT1_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                constexpr auto l_MCP_PBI01_SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG_ON = 0x1;
                l_scom_buffer.insert<36, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG_ON );
            }

            if ((l_TGT1_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                constexpr auto l_MCP_PBI01_SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG_ON = 0x1;
                l_scom_buffer.insert<32, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG_ON );
            }

            if ((l_TGT1_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                constexpr auto l_MCP_PBI01_SCOMFIR_MCTO_ENABLE_CHANNEL_HANG_ON = 0x1;
                l_scom_buffer.insert<33, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCTO_ENABLE_CHANNEL_HANG_ON );
            }

            if ((l_TGT1_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                constexpr auto l_MCP_PBI01_SCOMFIR_MCTO_ENABLE_APO_HANG_ON = 0x1;
                l_scom_buffer.insert<34, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCTO_ENABLE_APO_HANG_ON );
            }

            if ((l_TGT1_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                l_scom_buffer.insert<8, 16, 48, uint64_t>(literal_0xFFFF );
            }

            if ((l_TGT1_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_112 );
            }

            if ((l_TGT1_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                l_scom_buffer.insert<5, 3, 61, uint64_t>(literal_0x7 );
            }

            if ((l_TGT1_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                l_scom_buffer.insert<37, 3, 61, uint64_t>(literal_2 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0xc010c1bull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
