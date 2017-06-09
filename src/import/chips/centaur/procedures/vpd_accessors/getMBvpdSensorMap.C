/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getMBvpdSensorMap.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
///  @file getMBvpdSensorMap.H
///  @brief Prototype for getMBvpdSensorMap() - get primary and secondary sensor map
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#include    <stdint.h>

//  fapi2 support
#include    <fapi2.H>
#include    <getMBvpdSensorMap.H>
#include <fapi2_mbvpd_access.H>
extern "C"
{

///
/// @brief Return primary and secondary sensor map from cvpd record VSPD
///        keyword MW for attributes:
///
///        ATTR_VPD_CDIMM_SENSOR_MAP_PRIMARY
///        ATTR_VPD_CDIMM_SENSOR_MAP_SECONDARY
///
/// @param[in]  i_mbTarget   -   Membuf chip target
/// @param[in]  i_attr       -   Enumerator to select requested value
/// @param[out] o_val        -   Primary or secondary sensor map
/// @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success, relevant error code for failure.
///
    fapi2::ReturnCode getMBvpdSensorMap(
        const        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mbTarget,
        const        fapi2::MBvpdSensorMap i_attr,
        uint8_t&      o_val)

    {
        fapi2::ReturnCode l_fapi2rc;

        //MW keyword layout
        struct mw_keyword
        {
            uint8_t     MWKeywordVersion;
            uint8_t     masterPowerSlope_MSB;     //big endian order
            uint8_t     masterPowerSlope_LSB;
            uint8_t     masterPowerIntercept_MSB; //big endian order
            uint8_t     masterPowerIntercept_LSB;
            uint8_t     reserved[4];
            uint8_t     tempSensorPrimaryLayout;
            uint8_t     tempSensorSecondaryLayout;
        };
        const uint32_t MW_KEYWORD_SIZE = sizeof(mw_keyword);  // keyword size

        mw_keyword* l_pMwBuffer = NULL;  // MBvpd MW keyword buffer
        size_t l_MwBufsize = sizeof(mw_keyword);

        FAPI_DBG("getMBvpdSensorMap: entry ");

        l_pMwBuffer = new mw_keyword;

        // Read the MW keyword field
        FAPI_TRY(getMBvpdField(fapi2::MBVPD_RECORD_VSPD,
                               fapi2::MBVPD_KEYWORD_MW,
                               i_mbTarget,
                               reinterpret_cast<uint8_t*>(l_pMwBuffer),
                               l_MwBufsize), "getMBvpdSensorMap: Read of MV keyword failed");
        // Check that sufficient MW keyword was returned.
        FAPI_ASSERT(l_MwBufsize >= MW_KEYWORD_SIZE,
                    fapi2::CEN_MBVPD_INSUFFICIENT_VPD_RETURNED().
                    set_KEYWORD(fapi2::MBVPD_KEYWORD_MW).
                    set_RETURNED_SIZE(l_MwBufsize).
                    set_CHIP_TARGET(i_mbTarget),
                    "getMBvpdSensorMap:"
                    " less MW keyword returned than expected %d < %d",
                    l_MwBufsize, MW_KEYWORD_SIZE);

        // Return requested value
        switch (i_attr)
        {
            case fapi2::SENSOR_MAP_PRIMARY:
                o_val = l_pMwBuffer->tempSensorPrimaryLayout;
                break;

            case fapi2::SENSOR_MAP_SECONDARY:
                o_val = l_pMwBuffer->tempSensorSecondaryLayout;
                break;

            default: // Hard to do, but needs to be caught
                FAPI_ASSERT(false,
                            fapi2::CEN_MBVPD_INVALID_ATTRIBUTE_ID().
                            set_ATTR_ID(i_attr),
                            "getMBvpdSensorMap: invalid attribute ID 0x%02x",
                            i_attr);
        }

        delete l_pMwBuffer;
        l_pMwBuffer = NULL;

        FAPI_DBG("getMBvpdSensorMap: exit");

    fapi_try_exit:
        return fapi2::current_err;

    }

}   // extern "C"
