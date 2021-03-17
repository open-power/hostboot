/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_mi_omi_pretrain_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
#include "p10_mi_omi_pretrain_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0xFFFF = 0xFFFF;
constexpr uint64_t literal_112 = 112;
constexpr uint64_t literal_0x7 = 0x7;

fapi2::ReturnCode p10_mi_omi_pretrain_scom(const fapi2::Target<fapi2::TARGET_TYPE_MI>& TGT0,
        const fapi2::Target<fapi2::TARGET_TYPE_OMI>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_MCC>& TGT2,
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT3)
{
    {
        fapi2::ATTR_CHIP_UNIT_POS_Type l_TGT1_ATTR_CHIP_UNIT_POS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, TGT1, l_TGT1_ATTR_CHIP_UNIT_POS));
        uint64_t l_def_OMI_POSITION = (l_TGT1_ATTR_CHIP_UNIT_POS % literal_2);
        fapi2::ATTR_CHIP_UNIT_POS_Type l_TGT2_ATTR_CHIP_UNIT_POS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, TGT2, l_TGT2_ATTR_CHIP_UNIT_POS));
        uint64_t l_def_MCC_POSITION = (l_TGT2_ATTR_CHIP_UNIT_POS % literal_2);
        fapi2::ATTR_SYS_DISABLE_MCU_TIMEOUTS_Type l_TGT3_ATTR_SYS_DISABLE_MCU_TIMEOUTS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYS_DISABLE_MCU_TIMEOUTS, TGT3, l_TGT3_ATTR_SYS_DISABLE_MCU_TIMEOUTS));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010c13ull, l_scom_buffer ));

            if (((l_def_MCC_POSITION == literal_0) && (l_def_OMI_POSITION == literal_0)))
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b1 );
            }

            if (((l_def_MCC_POSITION == literal_0) && (l_def_OMI_POSITION == literal_1)))
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            if (((l_def_MCC_POSITION == literal_1) && (l_def_OMI_POSITION == literal_0)))
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
            }

            if (((l_def_MCC_POSITION == literal_1) && (l_def_OMI_POSITION == literal_1)))
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0xc010c13ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010c1bull, l_scom_buffer ));

            if ((l_TGT3_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                constexpr auto l_MCP_PBI01_SCOMFIR_MCTO_SELECT_PB_HANG_PULSE_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCTO_SELECT_PB_HANG_PULSE_OFF );
            }

            if ((l_TGT3_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                constexpr auto l_MCP_PBI01_SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE_ON = 0x1;
                l_scom_buffer.insert<1, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE_ON );
            }

            if ((l_TGT3_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                constexpr auto l_MCP_PBI01_SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG_ON = 0x1;
                l_scom_buffer.insert<36, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG_ON );
            }

            if ((l_TGT3_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                constexpr auto l_MCP_PBI01_SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG_ON = 0x1;
                l_scom_buffer.insert<32, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG_ON );
            }

            if ((l_TGT3_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                constexpr auto l_MCP_PBI01_SCOMFIR_MCTO_ENABLE_CHANNEL_HANG_ON = 0x1;
                l_scom_buffer.insert<33, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCTO_ENABLE_CHANNEL_HANG_ON );
            }

            if ((l_TGT3_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                constexpr auto l_MCP_PBI01_SCOMFIR_MCTO_ENABLE_APO_HANG_ON = 0x1;
                l_scom_buffer.insert<34, 1, 63, uint64_t>(l_MCP_PBI01_SCOMFIR_MCTO_ENABLE_APO_HANG_ON );
            }

            if ((l_TGT3_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                l_scom_buffer.insert<8, 16, 48, uint64_t>(literal_0xFFFF );
            }

            if ((l_TGT3_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_112 );
            }

            if ((l_TGT3_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                l_scom_buffer.insert<5, 3, 61, uint64_t>(literal_0x7 );
            }

            if ((l_TGT3_ATTR_SYS_DISABLE_MCU_TIMEOUTS == literal_0))
            {
                l_scom_buffer.insert<37, 3, 61, uint64_t>(literal_2 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0xc010c1bull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
