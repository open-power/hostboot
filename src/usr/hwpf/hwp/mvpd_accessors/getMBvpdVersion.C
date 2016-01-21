/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getMBvpdVersion.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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
// $Id: getMBvpdVersion.C,v 1.4 2015/09/23 13:49:51 dcrowell Exp $
/**
 *  @file getMBvpdVersion.C
 *
 *  @brief get the vpd version from MBvpd record VINI keyword VZ
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>
#include    <fapiUtil.H>
#include    <getMBvpdVersion.H>

extern "C"
{
using   namespace   fapi;

fapi::ReturnCode getMBvpdVersion(
                              const fapi::Target   &i_mbaTarget,
                              uint32_t  & o_val)
{
    fapi::ReturnCode l_fapirc;
    fapi::Target l_mbTarget;
    uint16_t l_vpdVersion = fapi::ENUM_ATTR_VPD_VERSION_UNKNOWN;
    uint32_t l_bufSize = sizeof(l_vpdVersion);

    FAPI_DBG("getMBvpdVersion: entry ");

    do {
        // The version represented here represents one of three
        //  distinct vintages of parts, see dimm_spd_attributes.xml
        //  for descriptions.

        // find the Centaur memory buffer from the passed MBA
        l_fapirc = fapiGetParentChip (i_mbaTarget,l_mbTarget);
        if (l_fapirc)
        {
            FAPI_ERR("getMBvpdVersion: Finding the parent mb failed ");
            break;  //  break out with fapirc
        }
        FAPI_DBG("getMBvpdVersion: parent path=%s ",
             l_mbTarget.toEcmdString()  );

        // Determine if ISDIMM or CDIMM
        std::vector<fapi::Target> l_target_dimm_array;
        l_fapirc = fapiGetAssociatedDimms(i_mbaTarget, l_target_dimm_array);
        if(l_fapirc)
        {
           FAPI_ERR("findDimmInfo: Problem getting DIMMs of MBA");
           break;   //return error
        }
        if(l_target_dimm_array.size() != 0)
        {
            uint8_t l_customDimm=0;
            l_fapirc = FAPI_ATTR_GET(ATTR_SPD_CUSTOM,&l_target_dimm_array[0],
                          l_customDimm);
            if(l_fapirc) {
               FAPI_ERR("findDimmInfo: ATTR_SPD_CUSTOM failed ");
               break;   //return error
            }

            if (l_customDimm == fapi::ENUM_ATTR_SPD_CUSTOM_NO)
            {
                l_vpdVersion = fapi::ENUM_ATTR_VPD_VERSION_CURRENT;
                FAPI_INF("isdimm :: l_vpdVersion=0x%x",l_vpdVersion);
                break;
            }

            // get vpd version from record VINI keyword VZ
            l_fapirc = fapiGetMBvpdField(fapi::MBVPD_RECORD_VINI,
                                 fapi::MBVPD_KEYWORD_VZ,
                                 l_mbTarget,
                                 reinterpret_cast<uint8_t *>(&l_vpdVersion),
                                 l_bufSize);
            if (l_fapirc)
            {
                FAPI_ERR("getMBvpdVersion: Read of VZ keyword failed");
                break;  //  break out with fapirc
            }

            // Check that sufficient size was returned.
            if (l_bufSize < sizeof(l_vpdVersion) )
            {
                FAPI_ERR("getMBvpdVersion:"
                         " less keyword data returned than expected %d < %d",
                         l_bufSize, sizeof(l_vpdVersion));
                const uint32_t & KEYWORD = fapi::MBVPD_KEYWORD_VZ;
                const uint32_t & RETURNED_SIZE = l_bufSize;
                const fapi::Target & CHIP_TARGET = l_mbTarget;
                FAPI_SET_HWP_ERROR(l_fapirc,RC_MBVPD_INSUFFICIENT_VPD_RETURNED);
                break;  //  break out with fapirc
            }

            // return value
            uint16_t l_vz = FAPI_BE16TOH(l_vpdVersion);
            if( l_vz < 0x3130 ) //10 in ASCII
            {
                FAPI_DBG("getMBvpdVersion: VZ=0x%04x",l_vz);
                l_vpdVersion = fapi::ENUM_ATTR_VPD_VERSION_OLD_CDIMM;
                FAPI_INF("old cdimm :: l_vpdVersion=0x%x",l_vpdVersion);
            }
            else
            {
                l_vpdVersion = fapi::ENUM_ATTR_VPD_VERSION_CURRENT;
                FAPI_INF("new cdimm :: l_vpdVersion=0x%x",l_vpdVersion);
            }
        }
        else //No dimms can only be ISDIMM system
        {
            l_vpdVersion = fapi::ENUM_ATTR_VPD_VERSION_CURRENT;
            FAPI_INF("no dimms :: l_vpdVersion=0x%x",l_vpdVersion);
        }


    } while (0);

    FAPI_DBG("getMBvpdVersion: exit rc=0x%08x)",
               static_cast<uint32_t>(l_fapirc));
    o_val = l_vpdVersion;

    return  l_fapirc;
}

}   // extern "C"
