/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_qme_build_attributes.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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


#include "p10_qme_build_attributes.H"
#include <endian.h>

// This function is auto-gen via chips/p10/procedures/ppe/tools/platXML/ppeCreateAttrMetaData.py
// and it is only used as a support function for Hcode_image_build.C

const uint8_t  HCODE_IMAGE_BUILD_ATTR_VERSION = 1;

const uint32_t COREQ_DUMMY_BUFFER_SIZE        = 32;

fapi2::ReturnCode
p10_qme_build_attributes(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_chip_tgt,
                         void* i_pQmeAttrTank, QmeAttrMeta_t* i_pQmeAttrMeta)
{
    FAPI_INF(">>p10_qme_build_attributes")

    const uint16_t l_hw_image_meta_ver = i_pQmeAttrMeta->meta_data_version;
    const uint16_t l_sys_bytes         = htobe16(i_pQmeAttrMeta->system_num_of_bytes);
    const uint16_t l_proc_bytes        = htobe16(i_pQmeAttrMeta->proc_chip_num_of_bytes);
    const uint16_t l_perv_bytes        = htobe16(i_pQmeAttrMeta->perv_num_of_bytes);
    const uint16_t l_ec_bytes          = htobe16(i_pQmeAttrMeta->ec_num_of_bytes);
    const uint16_t l_ex_bytes          = htobe16(i_pQmeAttrMeta->ex_num_of_bytes);
    const uint16_t l_eq_bytes          = htobe16(i_pQmeAttrMeta->eq_num_of_bytes);

    uint16_t       skip_size           = 0;
    uint16_t       alignment           = 0;
    uint16_t       leftover            = 0;

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_sys_tgt;
    auto l_perv_tgts = i_chip_tgt.getChildren<fapi2::TARGET_TYPE_PERV>(fapi2::TARGET_STATE_FUNCTIONAL);
    auto l_ec_tgts = i_chip_tgt.getChildren<fapi2::TARGET_TYPE_CORE>(fapi2::TARGET_STATE_FUNCTIONAL);
    auto l_eq_tgts = i_chip_tgt.getChildren<fapi2::TARGET_TYPE_EQ>(fapi2::TARGET_STATE_FUNCTIONAL);
    //Assume all attributes share the same value between cores
    //If that assumption is wrong, then should consider using
    //system/proc_chip level attribute array like the topology_vector


    if( l_hw_image_meta_ver != HCODE_IMAGE_BUILD_ATTR_VERSION )
    {
        FAPI_INF("CAREFUL!!! hw_image attr ver %x, hcode_image_build attr ver %x",
                 l_hw_image_meta_ver, HCODE_IMAGE_BUILD_ATTR_VERSION);
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, l_sys_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_PROC_FABRIC_BROADCAST_MODE");

        FAPI_DBG("ATTR_PROC_FABRIC_BROADCAST_MODE uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        uint8_t l_uint8_data[32] = {0};
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE, l_sys_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE");

        for( int index = 0; index < 32; index++ )
        {
            FAPI_DBG("ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE uint8_ Attribute Value: %x, Copy to Address: %x",
                     l_uint8_data[index], i_pQmeAttrTank);
            *(uint8_t*)i_pQmeAttrTank =  l_uint8_data[index] ;
            i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
        }
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_TOPOLOGY_MODE, l_sys_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_PROC_FABRIC_TOPOLOGY_MODE");

        FAPI_DBG("ATTR_PROC_FABRIC_TOPOLOGY_MODE uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        // 32b/64b data align at 4, 16b data align at 2
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 2;

        uint32_t l_uint32_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T0, l_sys_tgt, l_uint32_data),
                 "Error From FAPI_ATTR_GET For ATTR_PROC_EPS_READ_CYCLES_T0");

        FAPI_DBG("ATTR_PROC_EPS_READ_CYCLES_T0 uint32_ Attribute Value: %x, Copy to Address: %x",
                 l_uint32_data, i_pQmeAttrTank);
        *(uint32_t*)i_pQmeAttrTank = htobe32(l_uint32_data);
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 4;
    }

    {
        uint32_t l_uint32_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T1, l_sys_tgt, l_uint32_data),
                 "Error From FAPI_ATTR_GET For ATTR_PROC_EPS_READ_CYCLES_T1");

        FAPI_DBG("ATTR_PROC_EPS_READ_CYCLES_T1 uint32_ Attribute Value: %x, Copy to Address: %x",
                 l_uint32_data, i_pQmeAttrTank);
        *(uint32_t*)i_pQmeAttrTank = htobe32(l_uint32_data);
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 4;
    }

    {
        uint32_t l_uint32_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T2, l_sys_tgt, l_uint32_data),
                 "Error From FAPI_ATTR_GET For ATTR_PROC_EPS_READ_CYCLES_T2");

        FAPI_DBG("ATTR_PROC_EPS_READ_CYCLES_T2 uint32_ Attribute Value: %x, Copy to Address: %x",
                 l_uint32_data, i_pQmeAttrTank);
        *(uint32_t*)i_pQmeAttrTank = htobe32(l_uint32_data);
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 4;
    }

    {
        uint32_t l_uint32_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T1, l_sys_tgt, l_uint32_data),
                 "Error From FAPI_ATTR_GET For ATTR_PROC_EPS_WRITE_CYCLES_T1");

        FAPI_DBG("ATTR_PROC_EPS_WRITE_CYCLES_T1 uint32_ Attribute Value: %x, Copy to Address: %x",
                 l_uint32_data, i_pQmeAttrTank);
        *(uint32_t*)i_pQmeAttrTank = htobe32(l_uint32_data);
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 4;
    }

    {
        uint32_t l_uint32_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T2, l_sys_tgt, l_uint32_data),
                 "Error From FAPI_ATTR_GET For ATTR_PROC_EPS_WRITE_CYCLES_T2");

        FAPI_DBG("ATTR_PROC_EPS_WRITE_CYCLES_T2 uint32_ Attribute Value: %x, Copy to Address: %x",
                 l_uint32_data, i_pQmeAttrTank);
        *(uint32_t*)i_pQmeAttrTank = htobe32(l_uint32_data);
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 4;
    }

    {
        uint64_t l_uint64_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NX_RNG_BAR_BASE_ADDR_OFFSET, l_sys_tgt, l_uint64_data),
                 "Error From FAPI_ATTR_GET For ATTR_PROC_NX_RNG_BAR_BASE_ADDR_OFFSET");

        FAPI_DBG("ATTR_PROC_NX_RNG_BAR_BASE_ADDR_OFFSET uint64_ Attribute Value: %llx, Copy to Address: %x",
                 l_uint64_data, i_pQmeAttrTank);
        *(uint64_t*)i_pQmeAttrTank = htobe64(l_uint64_data);
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 8;
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_MIRROR_PLACEMENT_POLICY, l_sys_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_MEM_MIRROR_PLACEMENT_POLICY");

        FAPI_DBG("ATTR_MEM_MIRROR_PLACEMENT_POLICY uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_L3_HASH_DISABLE, l_sys_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_PROC_L3_HASH_DISABLE");

        FAPI_DBG("ATTR_PROC_L3_HASH_DISABLE uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_L2_HASH_DISABLE, l_sys_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_PROC_L2_HASH_DISABLE");

        FAPI_DBG("ATTR_PROC_L2_HASH_DISABLE uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUSED_CORE_MODE, l_sys_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_FUSED_CORE_MODE");

        FAPI_DBG("ATTR_FUSED_CORE_MODE uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_XSTOP_ON_SPATTN, l_sys_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_XSTOP_ON_SPATTN");

        FAPI_DBG("ATTR_XSTOP_ON_SPATTN uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_IPL_PHASE, l_sys_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_SYSTEM_IPL_PHASE");

        FAPI_DBG("ATTR_SYSTEM_IPL_PHASE uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CONTAINED_IPL_TYPE, l_sys_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_CONTAINED_IPL_TYPE");

        FAPI_DBG("ATTR_CONTAINED_IPL_TYPE uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_RUNN_MODE, l_sys_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_RUNN_MODE");

        FAPI_DBG("ATTR_RUNN_MODE uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SMF_CONFIG, l_sys_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_SMF_CONFIG");

        FAPI_DBG("ATTR_SMF_CONFIG uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_MMA_POWEROFF_DELAY_POWEROF2_MS, l_sys_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_SYSTEM_MMA_POWEROFF_DELAY_POWEROF2_MS");

        FAPI_DBG("ATTR_SYSTEM_MMA_POWEROFF_DELAY_POWEROF2_MS uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_MMA_POWERON_DISABLE, l_sys_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_SYSTEM_MMA_POWERON_DISABLE");

        FAPI_DBG("ATTR_SYSTEM_MMA_POWERON_DISABLE uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_MMA_POWEROFF_DISABLE, l_sys_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_SYSTEM_MMA_POWEROFF_DISABLE");

        FAPI_DBG("ATTR_SYSTEM_MMA_POWEROFF_DISABLE uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUSED_CORE_PAIRED_MODE_ENABLED, l_sys_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_FUSED_CORE_PAIRED_MODE_ENABLED");

        FAPI_DBG("ATTR_FUSED_CORE_PAIRED_MODE_ENABLED uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    //Co-req detection
    //IF bytes of QME_Image knows > bytes of Hcode_Image_build knowns
    //  meaning QME_Image updated with new attribute added
    //  as the result, Hcode_Image_Build needs to move pointer pass it
    //  thus the hwp needs to be updated to update the new attribute
    //  therefore, skip_size = dummy_size + (QI_size - HIB_size)
    //IF bytes of QME_Image knows < bytes of Hcode_Image_build knows
    //  meaning Hcode_Image_Build updated with new attribute added
    //  as the result, Hcode_Image_Build needs to write to dummy attribute
    //  for now until Qme_Image updated to create structure entry for it
    //  therefore, skip_size = dummy_size - (HIB_size - QI_size)

    {
        const uint32_t TARGET_TYPE_SYSTEM_ATTR_TOTAL_SIZE = 77;
        const uint32_t TARGET_TYPE_SYSTEM_ATTR_LIMIT_SIZE = 45;

        if( l_sys_bytes >= TARGET_TYPE_SYSTEM_ATTR_TOTAL_SIZE )
        {
            //it is ok if tank is much bigger than expected, just skip ahead
            skip_size = COREQ_DUMMY_BUFFER_SIZE + ( l_sys_bytes - TARGET_TYPE_SYSTEM_ATTR_TOTAL_SIZE );
        }
        else
        {
            //it is not ok if tank is COREQ_DUMMY_BUFFER_SIZE more smaller than expected,
            //meaning our dummy buffer for co-req protection isnt enough

            if( l_sys_bytes < TARGET_TYPE_SYSTEM_ATTR_LIMIT_SIZE )
            {
                FAPI_INF("ERROR: TARGET_TYPE_SYSTEM Attribute Co-Req Detected,\
                         hw_image attr size %x, hcode_image_build attr size 77", l_sys_bytes);
                FAPI_ASSERT(0, fapi2::QME_META_COREQ_PROTECT_FAIL()
                            .set_HW_IMAGE_ATTR_SIZE(l_sys_bytes)
                            .set_HCD_BUILD_ATTR_SIZE(TARGET_TYPE_SYSTEM_ATTR_TOTAL_SIZE),
                            "Fail to protect QME Attribute Co-Req");
            }

            skip_size = COREQ_DUMMY_BUFFER_SIZE - ( TARGET_TYPE_SYSTEM_ATTR_TOTAL_SIZE - l_sys_bytes );
        }

        //Skip Dummy Buffer for structure of TARGET_TYPE_SYSTEM
        //and realign pointer to next structure at 8 byte boundary
        alignment = COREQ_DUMMY_BUFFER_SIZE + l_sys_bytes;
        leftover  = (8 - (alignment % 8)) % 8;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + skip_size + leftover;

        FAPI_DBG("TARGET_TYPE_SYSTEM Image_Byte %d Build_Byte 77 Skip_Size %d Alignment %d Leftover %d",
                 l_sys_bytes, skip_size, alignment, leftover);
    }


    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, i_chip_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_NAME");

        FAPI_DBG("ATTR_NAME uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, i_chip_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_EC");

        FAPI_DBG("ATTR_EC uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID, i_chip_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_PROC_FABRIC_TOPOLOGY_ID");

        FAPI_DBG("ATTR_PROC_FABRIC_TOPOLOGY_ID uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID, i_chip_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID");

        FAPI_DBG("ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SL_DOMAIN, i_chip_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_PROC_FABRIC_SL_DOMAIN");

        FAPI_DBG("ATTR_PROC_FABRIC_SL_DOMAIN uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        uint8_t l_uint8_data[3] = {0};
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_LCO_TARGETS_COUNT, i_chip_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_PROC_LCO_TARGETS_COUNT");

        for( int index = 0; index < 3; index++ )
        {
            FAPI_DBG("ATTR_PROC_LCO_TARGETS_COUNT uint8_ Attribute Value: %x, Copy to Address: %x",
                     l_uint8_data[index], i_pQmeAttrTank);
            *(uint8_t*)i_pQmeAttrTank =  l_uint8_data[index] ;
            i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
        }
    }

    {
        uint32_t l_uint32_data[3] = {0};
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_LCO_TARGETS_VECTOR, i_chip_tgt, l_uint32_data),
                 "Error From FAPI_ATTR_GET For ATTR_PROC_LCO_TARGETS_VECTOR");

        for( int index = 0; index < 3; index++ )
        {
            FAPI_DBG("ATTR_PROC_LCO_TARGETS_VECTOR uint32_ Attribute Value: %x, Copy to Address: %x",
                     l_uint32_data[index], i_pQmeAttrTank);
            *(uint32_t*)i_pQmeAttrTank = htobe32(l_uint32_data[index]);
            i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 4;
        }
    }

    {
        uint8_t l_uint8_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NX_RNG_BAR_ENABLE, i_chip_tgt, l_uint8_data),
                 "Error From FAPI_ATTR_GET For ATTR_PROC_NX_RNG_BAR_ENABLE");

        FAPI_DBG("ATTR_PROC_NX_RNG_BAR_ENABLE uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    {
        // 32b/64b data align at 4, 16b data align at 2
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 3;

        uint32_t l_uint32_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_QME_STATE_LOSS_CORES, i_chip_tgt, l_uint32_data),
                 "Error From FAPI_ATTR_GET For ATTR_QME_STATE_LOSS_CORES");

        FAPI_DBG("ATTR_QME_STATE_LOSS_CORES uint32_ Attribute Value: %x, Copy to Address: %x",
                 l_uint32_data, i_pQmeAttrTank);
        *(uint32_t*)i_pQmeAttrTank = htobe32(l_uint32_data);
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 4;
    }

    //Co-req detection
    //IF bytes of QME_Image knows > bytes of Hcode_Image_build knowns
    //  meaning QME_Image updated with new attribute added
    //  as the result, Hcode_Image_Build needs to move pointer pass it
    //  thus the hwp needs to be updated to update the new attribute
    //  therefore, skip_size = dummy_size + (QI_size - HIB_size)
    //IF bytes of QME_Image knows < bytes of Hcode_Image_build knows
    //  meaning Hcode_Image_Build updated with new attribute added
    //  as the result, Hcode_Image_Build needs to write to dummy attribute
    //  for now until Qme_Image updated to create structure entry for it
    //  therefore, skip_size = dummy_size - (HIB_size - QI_size)

    {
        const uint32_t TARGET_TYPE_PROC_CHIP_ATTR_TOTAL_SIZE = 28;

        if( l_proc_bytes >= TARGET_TYPE_PROC_CHIP_ATTR_TOTAL_SIZE )
        {
            //it is ok if tank is much bigger than expected, just skip ahead
            skip_size = COREQ_DUMMY_BUFFER_SIZE + ( l_proc_bytes - TARGET_TYPE_PROC_CHIP_ATTR_TOTAL_SIZE );
        }
        else
        {
            skip_size = COREQ_DUMMY_BUFFER_SIZE - ( TARGET_TYPE_PROC_CHIP_ATTR_TOTAL_SIZE - l_proc_bytes );
        }

        //Skip Dummy Buffer for structure of TARGET_TYPE_PROC_CHIP
        //and realign pointer to next structure at 8 byte boundary
        alignment = COREQ_DUMMY_BUFFER_SIZE + l_proc_bytes;
        leftover  = (8 - (alignment % 8)) % 8;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + skip_size + leftover;

        FAPI_DBG("TARGET_TYPE_PROC_CHIP Image_Byte %d Build_Byte 28 Skip_Size %d Alignment %d Leftover %d",
                 l_proc_bytes, skip_size, alignment, leftover);
    }


    //Co-req detection
    //IF bytes of QME_Image knows > bytes of Hcode_Image_build knowns
    //  meaning QME_Image updated with new attribute added
    //  as the result, Hcode_Image_Build needs to move pointer pass it
    //  thus the hwp needs to be updated to update the new attribute
    //  therefore, skip_size = dummy_size + (QI_size - HIB_size)
    //IF bytes of QME_Image knows < bytes of Hcode_Image_build knows
    //  meaning Hcode_Image_Build updated with new attribute added
    //  as the result, Hcode_Image_Build needs to write to dummy attribute
    //  for now until Qme_Image updated to create structure entry for it
    //  therefore, skip_size = dummy_size - (HIB_size - QI_size)

    {
        const uint32_t TARGET_TYPE_PERV_ATTR_TOTAL_SIZE = 0;

        if( l_perv_bytes >= TARGET_TYPE_PERV_ATTR_TOTAL_SIZE )
        {
            //it is ok if tank is much bigger than expected, just skip ahead
            skip_size = COREQ_DUMMY_BUFFER_SIZE + ( l_perv_bytes - TARGET_TYPE_PERV_ATTR_TOTAL_SIZE );
        }
        else
        {
            skip_size = COREQ_DUMMY_BUFFER_SIZE - ( TARGET_TYPE_PERV_ATTR_TOTAL_SIZE - l_perv_bytes );
        }

        //Skip Dummy Buffer for structure of TARGET_TYPE_PERV
        //and realign pointer to next structure at 8 byte boundary
        alignment = COREQ_DUMMY_BUFFER_SIZE + l_perv_bytes;
        leftover  = (8 - (alignment % 8)) % 8;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + skip_size + leftover;

        FAPI_DBG("TARGET_TYPE_PERV Image_Byte %d Build_Byte 0 Skip_Size %d Alignment %d Leftover %d",
                 l_perv_bytes, skip_size, alignment, leftover);
    }


    {
        uint8_t l_uint8_data = 0;

        if (l_ec_tgts.size())
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_ec_tgts.front(), l_uint8_data),
                     "Error From FAPI_ATTR_GET For ATTR_CHIP_UNIT_POS");
        }

        FAPI_DBG("ATTR_CHIP_UNIT_POS uint8_ Attribute Value: %x, Copy to Address: %x",
                 l_uint8_data, i_pQmeAttrTank);
        *(uint8_t*)i_pQmeAttrTank =  l_uint8_data ;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + 1;
    }

    //Co-req detection
    //IF bytes of QME_Image knows > bytes of Hcode_Image_build knowns
    //  meaning QME_Image updated with new attribute added
    //  as the result, Hcode_Image_Build needs to move pointer pass it
    //  thus the hwp needs to be updated to update the new attribute
    //  therefore, skip_size = dummy_size + (QI_size - HIB_size)
    //IF bytes of QME_Image knows < bytes of Hcode_Image_build knows
    //  meaning Hcode_Image_Build updated with new attribute added
    //  as the result, Hcode_Image_Build needs to write to dummy attribute
    //  for now until Qme_Image updated to create structure entry for it
    //  therefore, skip_size = dummy_size - (HIB_size - QI_size)

    {
        const uint32_t TARGET_TYPE_CORE_ATTR_TOTAL_SIZE = 1;

        if( l_ec_bytes >= TARGET_TYPE_CORE_ATTR_TOTAL_SIZE )
        {
            //it is ok if tank is much bigger than expected, just skip ahead
            skip_size = COREQ_DUMMY_BUFFER_SIZE + ( l_ec_bytes - TARGET_TYPE_CORE_ATTR_TOTAL_SIZE );
        }
        else
        {
            skip_size = COREQ_DUMMY_BUFFER_SIZE - ( TARGET_TYPE_CORE_ATTR_TOTAL_SIZE - l_ec_bytes );
        }

        //Skip Dummy Buffer for structure of TARGET_TYPE_CORE
        //and realign pointer to next structure at 8 byte boundary
        alignment = COREQ_DUMMY_BUFFER_SIZE + l_ec_bytes;
        leftover  = (8 - (alignment % 8)) % 8;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + skip_size + leftover;

        FAPI_DBG("TARGET_TYPE_CORE Image_Byte %d Build_Byte 1 Skip_Size %d Alignment %d Leftover %d",
                 l_ec_bytes, skip_size, alignment, leftover);
    }


    //Co-req detection
    //IF bytes of QME_Image knows > bytes of Hcode_Image_build knowns
    //  meaning QME_Image updated with new attribute added
    //  as the result, Hcode_Image_Build needs to move pointer pass it
    //  thus the hwp needs to be updated to update the new attribute
    //  therefore, skip_size = dummy_size + (QI_size - HIB_size)
    //IF bytes of QME_Image knows < bytes of Hcode_Image_build knows
    //  meaning Hcode_Image_Build updated with new attribute added
    //  as the result, Hcode_Image_Build needs to write to dummy attribute
    //  for now until Qme_Image updated to create structure entry for it
    //  therefore, skip_size = dummy_size - (HIB_size - QI_size)

    {
        const uint32_t TARGET_TYPE_EX_ATTR_TOTAL_SIZE = 0;

        if( l_ex_bytes >= TARGET_TYPE_EX_ATTR_TOTAL_SIZE )
        {
            //it is ok if tank is much bigger than expected, just skip ahead
            skip_size = COREQ_DUMMY_BUFFER_SIZE + ( l_ex_bytes - TARGET_TYPE_EX_ATTR_TOTAL_SIZE );
        }
        else
        {
            skip_size = COREQ_DUMMY_BUFFER_SIZE - ( TARGET_TYPE_EX_ATTR_TOTAL_SIZE - l_ex_bytes );
        }

        //Skip Dummy Buffer for structure of TARGET_TYPE_EX
        //and realign pointer to next structure at 8 byte boundary
        alignment = COREQ_DUMMY_BUFFER_SIZE + l_ex_bytes;
        leftover  = (8 - (alignment % 8)) % 8;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + skip_size + leftover;

        FAPI_DBG("TARGET_TYPE_EX Image_Byte %d Build_Byte 0 Skip_Size %d Alignment %d Leftover %d",
                 l_ex_bytes, skip_size, alignment, leftover);
    }


    //Co-req detection
    //IF bytes of QME_Image knows > bytes of Hcode_Image_build knowns
    //  meaning QME_Image updated with new attribute added
    //  as the result, Hcode_Image_Build needs to move pointer pass it
    //  thus the hwp needs to be updated to update the new attribute
    //  therefore, skip_size = dummy_size + (QI_size - HIB_size)
    //IF bytes of QME_Image knows < bytes of Hcode_Image_build knows
    //  meaning Hcode_Image_Build updated with new attribute added
    //  as the result, Hcode_Image_Build needs to write to dummy attribute
    //  for now until Qme_Image updated to create structure entry for it
    //  therefore, skip_size = dummy_size - (HIB_size - QI_size)

    {
        const uint32_t TARGET_TYPE_EQ_ATTR_TOTAL_SIZE = 0;

        if( l_eq_bytes >= TARGET_TYPE_EQ_ATTR_TOTAL_SIZE )
        {
            //it is ok if tank is much bigger than expected, just skip ahead
            skip_size = COREQ_DUMMY_BUFFER_SIZE + ( l_eq_bytes - TARGET_TYPE_EQ_ATTR_TOTAL_SIZE );
        }
        else
        {
            skip_size = COREQ_DUMMY_BUFFER_SIZE - ( TARGET_TYPE_EQ_ATTR_TOTAL_SIZE - l_eq_bytes );
        }

        //Skip Dummy Buffer for structure of TARGET_TYPE_EQ
        //and realign pointer to next structure at 8 byte boundary
        alignment = COREQ_DUMMY_BUFFER_SIZE + l_eq_bytes;
        leftover  = (8 - (alignment % 8)) % 8;
        i_pQmeAttrTank = (uint8_t*)i_pQmeAttrTank + skip_size + leftover;

        FAPI_DBG("TARGET_TYPE_EQ Image_Byte %d Build_Byte 0 Skip_Size %d Alignment %d Leftover %d",
                 l_eq_bytes, skip_size, alignment, leftover);
    }

fapi_try_exit:
    FAPI_INF("<<p10_qme_build_attributes");
    return fapi2::current_err;
}
