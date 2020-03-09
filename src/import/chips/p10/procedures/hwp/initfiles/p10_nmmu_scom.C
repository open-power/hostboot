/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_nmmu_scom.C $ */
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
#include "p10_nmmu_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0x001 = 0x001;

fapi2::ReturnCode p10_nmmu_scom(const fapi2::Target<fapi2::TARGET_TYPE_NMMU>& TGT0,
                                const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT2)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT1, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT1, l_chip_ec));
        fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_TGT2_ATTR_PROC_FABRIC_BROADCAST_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, TGT2, l_TGT2_ATTR_PROC_FABRIC_BROADCAST_MODE));
        fapi2::ATTR_PROC_FABRIC_SL_DOMAIN_Type l_TGT1_ATTR_PROC_FABRIC_SL_DOMAIN;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SL_DOMAIN, TGT1, l_TGT1_ATTR_PROC_FABRIC_SL_DOMAIN));
        fapi2::ATTR_PROC_LCO_TARGETS_VECTOR_Type l_TGT1_ATTR_PROC_LCO_TARGETS_VECTOR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_LCO_TARGETS_VECTOR, TGT1, l_TGT1_ATTR_PROC_LCO_TARGETS_VECTOR));
        uint64_t l_def_LCO_TARGETS_VECTOR_CHIP =
            l_TGT1_ATTR_PROC_LCO_TARGETS_VECTOR[fapi2::ENUM_ATTR_PROC_LCO_TARGETS_VECTOR_CHIP];
        uint64_t l_def_LCO_TARGETS_VECTOR_EAST =
            l_TGT1_ATTR_PROC_LCO_TARGETS_VECTOR[fapi2::ENUM_ATTR_PROC_LCO_TARGETS_VECTOR_EAST];
        fapi2::ATTR_PROC_LCO_TARGETS_MIN_Type l_TGT1_ATTR_PROC_LCO_TARGETS_MIN;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_LCO_TARGETS_MIN, TGT1, l_TGT1_ATTR_PROC_LCO_TARGETS_MIN));
        uint64_t l_def_LCO_TARGETS_MIN_CHIP = l_TGT1_ATTR_PROC_LCO_TARGETS_MIN[fapi2::ENUM_ATTR_PROC_LCO_TARGETS_MIN_CHIP];
        uint64_t l_def_LCO_TARGETS_MIN_EAST = l_TGT1_ATTR_PROC_LCO_TARGETS_MIN[fapi2::ENUM_ATTR_PROC_LCO_TARGETS_MIN_EAST];
        fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T1_Type l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T1, TGT2, l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T1));
        fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T2_Type l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T2, TGT2, l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T2));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010c15ull, l_scom_buffer ));

            if ((l_TGT2_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                constexpr auto l_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_CFG_PUMP_MODE_ON = 0x1;
                l_scom_buffer.insert<39, 1, 63, uint64_t>(l_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_CFG_PUMP_MODE_ON );
            }
            else if ((l_TGT2_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                constexpr auto l_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_CFG_PUMP_MODE_OFF = 0x0;
                l_scom_buffer.insert<39, 1, 63, uint64_t>(l_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_CFG_PUMP_MODE_OFF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2010c15ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010c16ull, l_scom_buffer ));

            if ((l_TGT1_ATTR_PROC_FABRIC_SL_DOMAIN == fapi2::ENUM_ATTR_PROC_FABRIC_SL_DOMAIN_CHIP))
            {
                l_scom_buffer.insert<0, 32, 32, uint64_t>(l_def_LCO_TARGETS_VECTOR_CHIP );
            }
            else if ((l_TGT1_ATTR_PROC_FABRIC_SL_DOMAIN == fapi2::ENUM_ATTR_PROC_FABRIC_SL_DOMAIN_HEMISPHERE))
            {
                l_scom_buffer.insert<0, 32, 32, uint64_t>(l_def_LCO_TARGETS_VECTOR_EAST );
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_SL_DOMAIN == fapi2::ENUM_ATTR_PROC_FABRIC_SL_DOMAIN_CHIP))
            {
                l_scom_buffer.insert<32, 6, 58, uint64_t>(l_def_LCO_TARGETS_MIN_CHIP );
            }
            else if ((l_TGT1_ATTR_PROC_FABRIC_SL_DOMAIN == fapi2::ENUM_ATTR_PROC_FABRIC_SL_DOMAIN_HEMISPHERE))
            {
                l_scom_buffer.insert<32, 6, 58, uint64_t>(l_def_LCO_TARGETS_MIN_EAST );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2010c16ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010c1dull, l_scom_buffer ));

            if ((l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T1 != literal_0))
            {
                l_scom_buffer.insert<0, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
            }
            else if ((l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T1 == literal_0))
            {
                l_scom_buffer.insert<0, 12, 52, uint64_t>(literal_0x001 );
            }

            if ((l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T2 != literal_0))
            {
                l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
            }
            else if ((l_TGT2_ATTR_PROC_EPS_WRITE_CYCLES_T2 == literal_0))
            {
                l_scom_buffer.insert<16, 12, 52, uint64_t>(literal_0x001 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2010c1dull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
