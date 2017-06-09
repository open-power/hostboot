/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getMBvpdVersion.C $ */
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
///  @file getMBvpdVersion.C
///  @brief MBVPD Accessor for providing the ATTR_VPD_VERSION attribute
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#include    <stdint.h>

//  fapi2 support
#include    <fapi2.H>
#include    <getMBvpdVersion.H>
#include  <generic/memory/lib/utils/c_str.H>
#include <fapi2_mbvpd_access.H>

extern "C"
{
///
/// @brief Get the ATTR_VPD_VERSION FAPI attribute
///
/// @note Return the VPD version from MBvpd record VINI keyword VZ.
///
/// The ATTR_VPD_VERSION attribute is associated with a DIMM. The platfrom must
/// get the associated MBA chip to be passed to this hwp accessor.
///
/// @param[in]  i_mbaTarget - Reference to mba Target
/// @param[out] o_val      - Filled in with vpd version
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode getMBvpdVersion(
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>&   i_mbaTarget,
        uint32_t&   o_val)
    {
        uint16_t l_vpdVersion = fapi2::ENUM_ATTR_CEN_VPD_VERSION_UNKNOWN;
        size_t l_bufSize = sizeof(l_vpdVersion);

        FAPI_DBG("getMBvpdVersion: entry ");

        // The version represented here represents one of three
        //  distinct vintages of parts, see dimm_spd_attributes.xml
        //  for descriptions.

        // find the Centaur memory buffer from the passed MBA
        auto l_mbTarget = i_mbaTarget.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

        FAPI_DBG("getMBvpdVersion: parent path=%s ",
                 mss::c_str(l_mbTarget));

        // Determine if ISDIMM or CDIMM
        auto l_target_dimm_array = i_mbaTarget.getChildren<fapi2::TARGET_TYPE_DIMM>();

        if(l_target_dimm_array.size() != 0)
        {
            uint8_t l_customDimm = 0;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_CUSTOM, l_target_dimm_array[0],
                                   l_customDimm), "findDimmInfo: ATTR_CEN_SPD_CUSTOM failed ");

            if (l_customDimm == fapi2::ENUM_ATTR_CEN_SPD_CUSTOM_NO)
            {
                l_vpdVersion = fapi2::ENUM_ATTR_CEN_VPD_VERSION_CURRENT;
                FAPI_INF("isdimm :: l_vpdVersion=0x%x", l_vpdVersion);
                return fapi2::current_err;
            }

            // get vpd version from record VINI keyword VZ
            FAPI_TRY(getMBvpdField(fapi2::MBVPD_RECORD_VINI,
                                   fapi2::MBVPD_KEYWORD_VZ,
                                   l_mbTarget,
                                   reinterpret_cast<uint8_t*>(&l_vpdVersion),
                                   l_bufSize));

            // Check that sufficient size was returned.
            FAPI_ASSERT(l_bufSize >= sizeof(l_vpdVersion),
                        fapi2::CEN_MBVPD_INSUFFICIENT_VPD_RETURNED().
                        set_KEYWORD(fapi2::MBVPD_KEYWORD_VZ).
                        set_RETURNED_SIZE(l_bufSize).
                        set_CHIP_TARGET(l_mbTarget),
                        "getMBvpdVersion:"
                        " less keyword data returned than expected %d < %d",
                        l_bufSize, sizeof(l_vpdVersion));

            // return value
            uint16_t l_vz = be16toh(l_vpdVersion);

            if( l_vz < 0x3130 ) //10 in ASCII
            {
                FAPI_DBG("getMBvpdVersion: VZ=0x%04x", l_vz);
                l_vpdVersion = fapi2::ENUM_ATTR_CEN_VPD_VERSION_OLD_CDIMM;
                FAPI_INF("old cdimm :: l_vpdVersion=0x%x", l_vpdVersion);
            }
            else
            {
                l_vpdVersion = fapi2::ENUM_ATTR_CEN_VPD_VERSION_CURRENT;
                FAPI_INF("new cdimm :: l_vpdVersion=0x%x", l_vpdVersion);
            }
        }
        else //No dimms can only be ISDIMM system
        {
            l_vpdVersion = fapi2::ENUM_ATTR_CEN_VPD_VERSION_CURRENT;
            FAPI_INF("no dimms :: l_vpdVersion=0x%x", l_vpdVersion);
        }

        FAPI_DBG("getMBvpdVersion: exit");

        o_val = l_vpdVersion;
    fapi_try_exit:
        return fapi2::current_err;
    }

}   // extern "C"
