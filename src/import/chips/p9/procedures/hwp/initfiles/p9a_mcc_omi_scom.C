/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9a_mcc_omi_scom.C $ */
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
#include "p9a_mcc_omi_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0b100000 = 0b100000;
constexpr uint64_t literal_0b0001 = 0b0001;
constexpr uint64_t literal_0b1000000 = 0b1000000;
constexpr uint64_t literal_0b011000 = 0b011000;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_7 = 7;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_6363 = 6363;
constexpr uint64_t literal_10000 = 10000;
constexpr uint64_t literal_4500 = 4500;
constexpr uint64_t literal_7272 = 7272;
constexpr uint64_t literal_5800 = 5800;
constexpr uint64_t literal_5 = 5;
constexpr uint64_t literal_8181 = 8181;
constexpr uint64_t literal_7000 = 7000;
constexpr uint64_t literal_6 = 6;
constexpr uint64_t literal_9090 = 9090;
constexpr uint64_t literal_8000 = 8000;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0b0000110000 = 0b0000110000;

fapi2::ReturnCode p9a_mcc_omi_scom(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& TGT0,
                                   const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT3)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT3, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT3, l_chip_ec));
        uint64_t l_def_ENABLE_MCU_TIMEOUTS = literal_1;
        fapi2::ATTR_IS_SIMULATION_Type l_TGT1_ATTR_IS_SIMULATION;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, TGT1, l_TGT1_ATTR_IS_SIMULATION));
        uint64_t l_def_IS_SIM = (l_TGT1_ATTR_IS_SIMULATION == literal_1);
        fapi2::ATTR_FREQ_PB_MHZ_Type l_TGT1_ATTR_FREQ_PB_MHZ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PB_MHZ, TGT1, l_TGT1_ATTR_FREQ_PB_MHZ));
        fapi2::ATTR_FREQ_MCA_MHZ_Type l_TGT1_ATTR_FREQ_MCA_MHZ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_MCA_MHZ, TGT1, l_TGT1_ATTR_FREQ_MCA_MHZ));
        uint64_t l_def_MCA_FREQ = l_TGT1_ATTR_FREQ_MCA_MHZ;
        uint64_t l_def_MN_FREQ_RATIO = ((literal_10000 * l_def_MCA_FREQ) / l_TGT1_ATTR_FREQ_PB_MHZ);
        uint64_t l_def_ENABLE_HWFM = literal_1;
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x701090aull, l_scom_buffer ));

            l_scom_buffer.insert<2, 6, 58, uint64_t>(literal_0b100000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b0001 );
            l_scom_buffer.insert<17, 7, 57, uint64_t>(literal_0b1000000 );
            l_scom_buffer.insert<50, 6, 58, uint64_t>(literal_0b011000 );
            l_scom_buffer.insert<58, 6, 58, uint64_t>(literal_0b011000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x701090aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x701090bull, l_scom_buffer ));

            if ((l_def_ENABLE_MCU_TIMEOUTS == literal_1))
            {
                l_scom_buffer.insert<49, 3, 61, uint64_t>(literal_7 );
            }

            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x701090bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7010a0bull, l_scom_buffer ));

            if ((l_def_IS_SIM == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_4 );
            }
            else if (((l_def_MN_FREQ_RATIO >= literal_4500) && (l_def_MN_FREQ_RATIO < literal_6363)))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_4 );
            }
            else if (((l_def_MN_FREQ_RATIO >= literal_5800) && (l_def_MN_FREQ_RATIO < literal_7272)))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_5 );
            }
            else if (((l_def_MN_FREQ_RATIO >= literal_7000) && (l_def_MN_FREQ_RATIO < literal_8181)))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_6 );
            }
            else if (((l_def_MN_FREQ_RATIO >= literal_8000) && (l_def_MN_FREQ_RATIO < literal_9090)))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_7 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x7010a0bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7010a0full, l_scom_buffer ));

            if ((l_def_ENABLE_HWFM == literal_1))
            {
                l_scom_buffer.insert<1, 6, 58, uint64_t>(literal_1 );
            }
            else if ((l_def_ENABLE_HWFM == literal_0))
            {
                l_scom_buffer.insert<1, 6, 58, uint64_t>(literal_0 );
            }

            if ((l_def_ENABLE_HWFM == literal_1))
            {
                constexpr auto l_MCP_CHAN0_USTL_USTLMCHWFM_ENABLE_ON = 0x1;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_MCP_CHAN0_USTL_USTLMCHWFM_ENABLE_ON );
            }
            else if ((l_def_ENABLE_HWFM == literal_0))
            {
                constexpr auto l_MCP_CHAN0_USTL_USTLMCHWFM_ENABLE_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_MCP_CHAN0_USTL_USTLMCHWFM_ENABLE_OFF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x7010a0full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x7010a13ull, l_scom_buffer ));

            l_scom_buffer.insert<48, 10, 54, uint64_t>(literal_0b0000110000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x7010a13ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
