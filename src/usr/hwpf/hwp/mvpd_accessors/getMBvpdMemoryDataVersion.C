/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getMBvpdMemoryDataVersion.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
// $Id: getMBvpdMemoryDataVersion.C,v 1.3 2015/10/06 15:18:04 dcrowell Exp $
/**
 *  @file getMBvpdMemoryDataVersion.C
 *
 *  @brief get the Memory Data version from MBvpd record SPDX keyword VM
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>
#include    <fapiUtil.H>
#include    <getMBvpdMemoryDataVersion.H>
#include    <fapiSystemConfig.H>
#include    <getMBvpdAttr.H>
extern "C"
{
using   namespace   fapi;
using   namespace   getAttrData;

fapi::ReturnCode getMBvpdMemoryDataVersion(
                              const fapi::Target   &i_mbTarget,
                              uint32_t  & o_val)
{
    fapi::ReturnCode l_fapirc;
    DimmType l_dimmType = ISDIMM;
    fapi::MBvpdRecord  l_record  = fapi::MBVPD_RECORD_SPDX;
    MBvpdVMKeyword l_vpdMemoryDataVersion;
    uint32_t l_bufSize = sizeof(l_vpdMemoryDataVersion);

    FAPI_DBG("getMBvpdMemoryDataVersion: entry ");

    do {
        
        FAPI_DBG("getMBvpdMemoryDataVersion: Membuff path=%s ",
             i_mbTarget.toEcmdString()  );

        // Find the dimm type 
        // Determine if ISDIMM or CDIMM

        // Find one mba target for passing it to fapiGetAssociatedDimms
        std::vector<fapi::Target> l_mba_chiplets;
        l_fapirc = fapiGetChildChiplets( i_mbTarget ,
                        fapi::TARGET_TYPE_MBA_CHIPLET, l_mba_chiplets );
        if((l_fapirc) || (l_mba_chiplets.size() == 0))
        {
           FAPI_ERR("getMBvpdMemoryDataVersion: Problem getting MBA's of Membuff");
           break;   //return error
        }
        
        std::vector<fapi::Target> l_target_dimm_array;
        l_fapirc = fapiGetAssociatedDimms(l_mba_chiplets[0], l_target_dimm_array);
        if(l_fapirc)
        {
           FAPI_ERR("getMBvpdMemoryDataVersion: Problem getting DIMMs of Membuff");
           break;   //return error
        }
        if(l_target_dimm_array.size() != 0)
        {
            uint8_t l_customDimm=0;
            l_fapirc = FAPI_ATTR_GET(ATTR_SPD_CUSTOM,&l_target_dimm_array[0],
                          l_customDimm);
            if(l_fapirc) {
               FAPI_ERR("getMBvpdMemoryDataVersion: ATTR_SPD_CUSTOM failed ");
               break;   //return error
            }

            if (l_customDimm == fapi::ENUM_ATTR_SPD_CUSTOM_YES)
            {
                l_dimmType = CDIMM;
                FAPI_DBG("getMBvpdMemoryDataVersion: CDIMM TYPE!!!");
            }
            else
            {
                l_dimmType = ISDIMM;
                FAPI_DBG("getMBvpdMemoryDataVersion: ISDIMM TYPE!!!");
            }
        }
        else
        {
           l_dimmType = ISDIMM;
           FAPI_DBG("getMBvpdMemoryDataVersion: ISDIMM TYPE (dimm array size = 0)");
        }
       
        if( l_dimmType == CDIMM)
        {
            l_record = fapi::MBVPD_RECORD_VSPD;
        }

        // get Memory Data  version from record VSPD/SPDX keyword VM
        l_fapirc = fapiGetMBvpdField(l_record,
                                     fapi::MBVPD_KEYWORD_VM,
                                     i_mbTarget,
                                     reinterpret_cast<uint8_t *>(&l_vpdMemoryDataVersion),
                                     l_bufSize);
        if (l_fapirc)
        {
            FAPI_DBG("getMBvpdMemoryDataVersion: Returning default"
                        " as VM keyword read failed.");
            l_fapirc = FAPI_RC_SUCCESS;  // Lets make it success and return default
            break;  //  break out and return
        }

        // Check that sufficient size was returned.
        if (l_bufSize < sizeof(l_vpdMemoryDataVersion) )
        {
            FAPI_ERR("getMBvpdMemoryDataVersion:"
                     " less keyword data returned than expected %d < %d",
                       l_bufSize, sizeof(l_vpdMemoryDataVersion));
            const uint32_t & KEYWORD = fapi::MBVPD_KEYWORD_VM;
            const uint32_t & RETURNED_SIZE = l_bufSize;
            const fapi::Target & CHIP_TARGET = i_mbTarget;
            FAPI_SET_HWP_ERROR(l_fapirc,RC_MBVPD_INSUFFICIENT_VPD_RETURNED);
            break;  //  break out with fapirc
        }
                    
        // Check if the format byte in the value returned is in between valid range
        if ((l_vpdMemoryDataVersion.iv_version >  VM_SUPPORTED_HIGH_VER )||
            (l_vpdMemoryDataVersion.iv_version == VM_NOT_SUPPORTED ))
        {
            FAPI_ERR("getMBvpdMemoryDataVersion:"
                     " keyword data returned is invalid : %d ",
                       l_vpdMemoryDataVersion);
            const uint32_t & KEYWORD = fapi::MBVPD_KEYWORD_VM;
            const uint32_t & RETURNED_VALUE = l_vpdMemoryDataVersion;
            const uint32_t & RECORD_NAME = l_record;
            const uint32_t & DIMM_TYPE = l_dimmType;
            const fapi::Target & CHIP_TARGET = i_mbTarget;
            FAPI_SET_HWP_ERROR(l_fapirc,RC_MBVPD_INVALID_VM_DATA_RETURNED);
            break;  //  break out with fapirc
        }
        // return value
        o_val = static_cast<uint32_t>(FAPI_BE16TOH(l_vpdMemoryDataVersion));

        FAPI_DBG("getMBvpdMemoryDataVersion: Memory Data version=0x%08x",
                o_val);


    } while (0);

    FAPI_DBG("getMBvpdMemoryDataVersion: exit rc=0x%08x)",
               static_cast<uint32_t>(l_fapirc));

    return  l_fapirc;
}

}   // extern "C"
