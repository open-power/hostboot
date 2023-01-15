/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/utils/ody_generate_sbe_attribute_data.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
#include "ody_generate_sbe_attribute_data.H"
#include "sbe_attribute_utils.H"

using namespace fapi2;
using namespace sbeutil;

extern "C"
{
    ReturnCode ody_generate_sbe_attribute_data(
        const Target<TARGET_TYPE_OCMB_CHIP>& i_ocmb_targ, void* o_buf, const uint16_t i_buf_size)
    {
        FAPI_DBG("ody_generate_sbe_attribute_data Entering");
        ATTR_OCMB_PLL_BUCKET_Type l_pll_bucket;
        SbeAttributeUpdateFileGenerator l_update_gen;

        FAPI_TRY(l_update_gen.setChipTarget(i_ocmb_targ), "setChipTarget failed");

        // Adding only two targets as a sample implementation.

        // Generated code using attrtool
        FAPI_TRY(FAPI_ATTR_GET(ATTR_OCMB_PLL_BUCKET, i_ocmb_targ, l_pll_bucket),
                 "ATTR_OCMB_PLL_BUCKET read failed");
        FAPI_DBG("overriding 0x%08X, size=%d, value=0x%8X",
                 ATTR_OCMB_PLL_BUCKET, sizeof(ATTR_OCMB_PLL_BUCKET_Type), l_pll_bucket);
        FAPI_TRY(l_update_gen.addAttribute(
                     i_ocmb_targ,
                     ATTR_OCMB_PLL_BUCKET,
                     &l_pll_bucket,
                     sizeof(ATTR_OCMB_PLL_BUCKET_Type),
                     sizeof(uint8_t)),
                 "ATTR_OCMB_PLL_BUCKET addAttribute failed");

        for(auto& l_mem_targ :
            i_ocmb_targ.getChildren<TARGET_TYPE_MEM_PORT>(TARGET_STATE_PRESENT))
        {
            ATTR_DDR5_DRAM_DQS_RTT_PARK_Type l_val;
            FAPI_TRY(FAPI_ATTR_GET(ATTR_DDR5_DRAM_DQS_RTT_PARK, l_mem_targ, l_val),
                     "ATTR_DDR5_DRAM_DQS_RTT_PARK read failed");
            FAPI_DBG("overriding 0x%08X, size=%d",
                     ATTR_DDR5_DRAM_DQS_RTT_PARK, sizeof(ATTR_DDR5_DRAM_DQS_RTT_PARK_Type));

            FAPI_TRY(l_update_gen.addAttribute(
                         l_mem_targ,
                         ATTR_DDR5_DRAM_DQS_RTT_PARK,
                         &l_val,
                         sizeof(ATTR_DDR5_DRAM_DQS_RTT_PARK_Type),
                         sizeof(uint8_t)),
                     "ATTR_DDR5_DRAM_DQS_RTT_PARK addAttribute failed");
        }

        {
            ATTR_HOTPLUG_Type l_val;
            Target<TARGET_TYPE_SYSTEM> l_sysTarget;
            FAPI_TRY(FAPI_ATTR_GET(ATTR_HOTPLUG, l_sysTarget, l_val),
                     "ATTR_HOTPLUG read failed");
            FAPI_DBG("overriding 0x%08X, size=%d, value=0x%8X",
                     ATTR_HOTPLUG, sizeof(ATTR_HOTPLUG_Type), l_val);
            FAPI_TRY(l_update_gen.addAttribute(
                         l_sysTarget,
                         ATTR_HOTPLUG,
                         &l_val,
                         sizeof(ATTR_HOTPLUG_Type),
                         sizeof(uint8_t)),
                     "ATTR_HOTPLUG addAttribute failed");
        }

        for(auto& l_pervTarg :
            i_ocmb_targ.getChildren<TARGET_TYPE_PERV>(TARGET_STATE_PRESENT))
        {
            ATTR_PG_Type l_val;
            FAPI_TRY(FAPI_ATTR_GET(ATTR_PG, l_pervTarg, l_val),
                     "ATTR_PG read failed");
            FAPI_DBG("overriding 0x%08X, size=%d",
                     ATTR_PG, sizeof(ATTR_PG_Type));

            FAPI_TRY(l_update_gen.addAttribute(
                         l_pervTarg,
                         ATTR_PG,
                         &l_val,
                         sizeof(ATTR_PG_Type),
                         sizeof(uint32_t)),
                     "ATTR_PG addAttribute failed");
        }

        for(auto& l_dimmTarg :
            i_ocmb_targ.getChildren<TARGET_TYPE_DIMM>(TARGET_STATE_PRESENT))
        {
            ATTR_BAD_DQ_BITMAP_Type l_val;
            FAPI_TRY(FAPI_ATTR_GET(ATTR_BAD_DQ_BITMAP, l_dimmTarg, l_val),
                     "ATTR_BAD_DQ_BITMAP read failed");
            FAPI_DBG("overriding 0x%08X, size=%d",
                     ATTR_BAD_DQ_BITMAP, sizeof(ATTR_BAD_DQ_BITMAP_Type));

            FAPI_TRY(l_update_gen.addAttribute(
                         l_dimmTarg,
                         ATTR_BAD_DQ_BITMAP,
                         &l_val,
                         sizeof(ATTR_BAD_DQ_BITMAP_Type),
                         sizeof(uint8_t)),
                     "ATTR_BAD_DQ_BITMAP addAttribute failed");
        }

        for(auto& l_tempSensorTarg :
            i_ocmb_targ.getChildren<TARGET_TYPE_TEMP_SENSOR>(TARGET_STATE_PRESENT))
        {
            ATTR_SPPE_I2C_DEV_ADDR_Type l_val;
            FAPI_TRY(FAPI_ATTR_GET(ATTR_SPPE_I2C_DEV_ADDR, l_tempSensorTarg, l_val),
                     "ATTR_SPPE_I2C_DEV_ADDR read failed");
            FAPI_DBG("overriding 0x%08X, size=%d",
                     ATTR_SPPE_I2C_DEV_ADDR, sizeof(ATTR_SPPE_I2C_DEV_ADDR_Type));

            FAPI_TRY(l_update_gen.addAttribute(
                         l_tempSensorTarg,
                         ATTR_SPPE_I2C_DEV_ADDR,
                         &l_val,
                         sizeof(ATTR_SPPE_I2C_DEV_ADDR_Type),
                         sizeof(uint8_t)),
                     "ATTR_SPPE_I2C_DEV_ADDR addAttribute failed");
        }

        // Generated code ends here
        ////////////////////////////////////////////////////////////////////////

        FAPI_TRY(l_update_gen.genOutput("", o_buf, i_buf_size), "genOutput failed");

    fapi_try_exit:
        FAPI_DBG("ody_generate_sbe_attribute_data Exiting");
        return fapi2::current_err;
    }

}// extern C
