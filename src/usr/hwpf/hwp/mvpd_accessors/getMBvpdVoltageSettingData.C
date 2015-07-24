/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getMBvpdVoltageSettingData.C $ */
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
// $Id: getMBvpdVoltageSettingData.C,v 1.2 2015/09/29 20:55:55 janssens Exp $
/**
 *  @file getMBvpdVoltageSettingData.C
 *
 *  @brief get the Voltage Setting Data from DW keyword of MBVPD SPDX record
 *  *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>
#include    <fapiUtil.H>
#include    <getMBvpdVoltageSettingData.H>
#include    <fapiSystemConfig.H>
#include    <getMBvpdAttr.H>

extern "C"
{
using   namespace   fapi;
using   namespace   getAttrData;

fapi::ReturnCode getMBvpdVoltageSettingData(const fapi::Target   &i_mbTarget,
                                            uint32_t & o_val)
{
    fapi::ReturnCode l_fapirc;
    DimmType l_dimmType = ISDIMM;
    fapi::MBvpdRecord  l_record  = fapi::MBVPD_RECORD_SPDX;
    uint16_t l_vpdVoltageSettingData = DW_KEYWORD_DEFAULT_VALUE;
    uint32_t l_bufSize = sizeof(l_vpdVoltageSettingData);

    FAPI_DBG("getMBvpdVoltageSettingData: entry ");

    do {

        FAPI_DBG("getMBvpdVoltageSettingData: Membuff path=%s ",
             i_mbTarget.toEcmdString()  );

        // Find the dimm type
        // Determine if ISDIMM or CDIMM

        // Find one mba target for passing it to fapiGetAssociatedDimms
        std::vector<fapi::Target> l_mba_chiplets;
        l_fapirc = fapiGetChildChiplets( i_mbTarget ,
                        fapi::TARGET_TYPE_MBA_CHIPLET, l_mba_chiplets );
        if((l_fapirc) || (l_mba_chiplets.size() == 0))
        { 
           FAPI_ERR("getMBvpdVoltageSettingData: Problem getting MBA's of Membuff");
           break;   //return error
        }

        std::vector<fapi::Target> l_target_dimm_array;
        l_fapirc = fapiGetAssociatedDimms(l_mba_chiplets[0], l_target_dimm_array);
        if(l_fapirc)
        {
           FAPI_ERR("getMBvpdVoltageSettingData: Problem getting DIMMs of Membuf");
           break;   //return error
        }
        if(l_target_dimm_array.size() != 0)
        {
            uint8_t l_customDimm=0;
            l_fapirc = FAPI_ATTR_GET(ATTR_SPD_CUSTOM,&l_target_dimm_array[0],
                          l_customDimm);
            if(l_fapirc) {
               FAPI_ERR("getMBvpdVoltageSettingData: ATTR_SPD_CUSTOM failed ");
               break;   //return error
            }

            if (l_customDimm == fapi::ENUM_ATTR_SPD_CUSTOM_YES)
            {
                l_dimmType = CDIMM;
                FAPI_DBG("getMBvpdVoltageSettingData: CDIMM TYPE!!!");
            }
            else
            {
                l_dimmType = ISDIMM;
                FAPI_DBG("getMBvpdVoltageSettingData: ISDIMM TYPE!!!");
            }
        }
        else
        {
           l_dimmType = ISDIMM;
           FAPI_DBG("getMBvpdVoltageSettingData: ISDIMM TYPE (dimm array size = 0)");
        }

       
        if(l_dimmType == CDIMM)
        {
            l_record = fapi::MBVPD_RECORD_VSPD;
        }
        // get voltage setting data from record SPDX keyword DW
        l_fapirc = fapiGetMBvpdField(l_record,
                                     fapi::MBVPD_KEYWORD_DW,
                                     i_mbTarget,
                                     reinterpret_cast<uint8_t *>(&l_vpdVoltageSettingData),
                                     l_bufSize);
        if (l_fapirc)
        {
            FAPI_ERR("getMBvpdVersion: Read of DW keyword failed");
            break;  //  break out with fapirc
        }

        // Check that sufficient size was returned.
        if (l_bufSize < sizeof(l_vpdVoltageSettingData) )
        {
            FAPI_ERR("getMBvpdVoltageSettingData:"
                     " less keyword data returned than expected %d < %d",
                       l_bufSize, sizeof(l_vpdVoltageSettingData));
            const uint32_t & KEYWORD = fapi::MBVPD_KEYWORD_DW;
            const uint32_t & RETURNED_SIZE = l_bufSize;
            const fapi::Target & CHIP_TARGET = i_mbTarget;
            FAPI_SET_HWP_ERROR(l_fapirc,RC_MBVPD_INSUFFICIENT_VPD_RETURNED);
            break;  //  break out with fapirc
        }
        // return value
        o_val = static_cast<uint32_t>(FAPI_BE16TOH(l_vpdVoltageSettingData));

        FAPI_DBG("getMBvpdVoltageSettingData: voltage setting Data=0x%08x",
                o_val);


    } while (0);

    FAPI_DBG("getMBvpdVoltageSettingData: exit rc=0x%08x)",
               static_cast<uint32_t>(l_fapirc));

    return  l_fapirc;
}

}   // extern "C"
