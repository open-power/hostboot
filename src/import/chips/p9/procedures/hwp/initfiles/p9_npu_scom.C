/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_npu_scom.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
#include "p9_npu_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>
#include <attribute_ids.H>
#include <target_types.H>
#include <fapi2_attribute_service.H>
using namespace fapi2;

#define ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_ATTRIBUTE_VALUE_2    2
#define LITERAL_NPU_CONFIG_EPSILON_RATE_0x0    0x0
#define LITERAL_NPU_MISC_FIR_ACTION0_0_0x0000000000000000    0x0000000000000000
#define LITERAL_NPU_MISC_FIR_ACTION1_0_0x0000000000000000    0x0000000000000000
#define LITERAL_NPU_MISC_FIR_MASK_0_0x1111111111111111    0x1111111111111111

fapi2::ReturnCode p9_npu_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> NPU_MISC_FIR_ACTION0_0_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5011406ull, NPU_MISC_FIR_ACTION0_0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5011406)");
            break;
        }

        fapi2::buffer<uint64_t> NPU_MISC_FIR_ACTION0_1_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5011446ull, NPU_MISC_FIR_ACTION0_1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5011446)");
            break;
        }

        NPU_MISC_FIR_ACTION0_0_scom0.insert<uint64_t> (LITERAL_NPU_MISC_FIR_ACTION0_0_0x0000000000000000, 0, 64, 0 );
        NPU_MISC_FIR_ACTION0_1_scom0.insert<uint64_t> (LITERAL_NPU_MISC_FIR_ACTION0_0_0x0000000000000000, 0, 64, 0 );

        fapi2::buffer<uint64_t> NPU_MISC_FIR_ACTION1_0_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5011407ull, NPU_MISC_FIR_ACTION1_0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5011407)");
            break;
        }

        fapi2::buffer<uint64_t> NPU_MISC_FIR_ACTION1_1_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5011447ull, NPU_MISC_FIR_ACTION1_1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5011447)");
            break;
        }

        NPU_MISC_FIR_ACTION1_0_scom0.insert<uint64_t> (LITERAL_NPU_MISC_FIR_ACTION1_0_0x0000000000000000, 0, 64, 0 );
        NPU_MISC_FIR_ACTION1_1_scom0.insert<uint64_t> (LITERAL_NPU_MISC_FIR_ACTION1_0_0x0000000000000000, 0, 64, 0 );

        fapi2::buffer<uint64_t> NPU_MISC_FIR_MASK_0_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5011403ull, NPU_MISC_FIR_MASK_0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5011403)");
            break;
        }

        NPU_MISC_FIR_MASK_0_scom0.insert<uint64_t> (LITERAL_NPU_MISC_FIR_MASK_0_0x1111111111111111, 0, 64, 0 );

        ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_Type iv_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE;
        l_rc = FAPI_ATTR_GET(ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE, TGT0, iv_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (iv_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE)");
            break;
        }

        fapi2::buffer<uint64_t> NPU_CONFIG_ENABLE_MACHINE_ALLOC_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5011008ull, NPU_CONFIG_ENABLE_MACHINE_ALLOC_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5011008)");
            break;
        }

        NPU_CONFIG_ENABLE_MACHINE_ALLOC_scom0.insert<uint64_t> (((((iv_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[0] ==
                ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_ATTRIBUTE_VALUE_2)
                || (iv_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[1] == ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_ATTRIBUTE_VALUE_2))
                || (iv_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[2] == ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_ATTRIBUTE_VALUE_2))
                || (iv_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[3] == ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_ATTRIBUTE_VALUE_2)), 51, 1,
                63 );

        fapi2::buffer<uint64_t> NPU_CONFIG_ENABLE_PBUS_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5011000ull, NPU_CONFIG_ENABLE_PBUS_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5011000)");
            break;
        }

        NPU_CONFIG_ENABLE_PBUS_scom0.insert<uint64_t> (((((iv_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[0] ==
                ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_ATTRIBUTE_VALUE_2)
                || (iv_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[1] == ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_ATTRIBUTE_VALUE_2))
                || (iv_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[2] == ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_ATTRIBUTE_VALUE_2))
                || (iv_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[3] == ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_ATTRIBUTE_VALUE_2)), 38, 1,
                63 );

        ATTR_PROC_EPS_READ_CYCLES_Type iv_TGT1_ATTR_PROC_EPS_READ_CYCLES;
        l_rc = FAPI_ATTR_GET(ATTR_PROC_EPS_READ_CYCLES, TGT1, iv_TGT1_ATTR_PROC_EPS_READ_CYCLES);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (iv_TGT1_ATTR_PROC_EPS_READ_CYCLES)");
            break;
        }

        fapi2::buffer<uint64_t> NPU_CONFIG_EPSILON_R0_COUNT_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5011002ull, NPU_CONFIG_EPSILON_R0_COUNT_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5011002)");
            break;
        }

        NPU_CONFIG_EPSILON_R0_COUNT_scom0.insert<uint64_t> (iv_TGT1_ATTR_PROC_EPS_READ_CYCLES[0], 28, 12, 52 );

        NPU_CONFIG_EPSILON_R0_COUNT_scom0.insert<uint64_t> (iv_TGT1_ATTR_PROC_EPS_READ_CYCLES[1], 40, 12, 52 );

        NPU_CONFIG_EPSILON_R0_COUNT_scom0.insert<uint64_t> (iv_TGT1_ATTR_PROC_EPS_READ_CYCLES[2], 52, 12, 52 );

        NPU_CONFIG_EPSILON_R0_COUNT_scom0.insert<uint64_t> (LITERAL_NPU_CONFIG_EPSILON_RATE_0x0, 0, 4, 60 );

        ATTR_PROC_EPS_WRITE_CYCLES_Type iv_TGT1_ATTR_PROC_EPS_WRITE_CYCLES;
        l_rc = FAPI_ATTR_GET(ATTR_PROC_EPS_WRITE_CYCLES, TGT1, iv_TGT1_ATTR_PROC_EPS_WRITE_CYCLES);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (iv_TGT1_ATTR_PROC_EPS_WRITE_CYCLES)");
            break;
        }

        NPU_CONFIG_EPSILON_R0_COUNT_scom0.insert<uint64_t> (iv_TGT1_ATTR_PROC_EPS_WRITE_CYCLES[0], 4, 12, 52 );

        NPU_CONFIG_EPSILON_R0_COUNT_scom0.insert<uint64_t> (iv_TGT1_ATTR_PROC_EPS_WRITE_CYCLES[1], 16, 12, 52 );


        l_rc = fapi2::putScom( TGT0, 0x5011000ull, NPU_CONFIG_ENABLE_PBUS_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5011000)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x5011002ull, NPU_CONFIG_EPSILON_R0_COUNT_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5011002)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x5011008ull, NPU_CONFIG_ENABLE_MACHINE_ALLOC_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5011008)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x5011403ull, NPU_MISC_FIR_MASK_0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5011403)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x5011406ull, NPU_MISC_FIR_ACTION0_0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5011406)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x5011407ull, NPU_MISC_FIR_ACTION1_0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5011407)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x5011446ull, NPU_MISC_FIR_ACTION0_1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5011446)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x5011447ull, NPU_MISC_FIR_ACTION1_1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5011447)");
            break;
        }

    }
    while(0);

    return l_rc;
}
