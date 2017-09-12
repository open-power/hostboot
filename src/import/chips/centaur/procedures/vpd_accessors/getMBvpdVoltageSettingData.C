/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getMBvpdVoltageSettingData.C $ */
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
///  @file getMBvpdVoltageSettingData.H
///  @brief MBVPD Accessor for providing the ATTR_VPD_DW_KEYWORD attribute
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#include    <stdint.h>

//  fapi2 support
#include    <fapi2.H>
#include    <getMBvpdVoltageSettingData.H>
#include    <getMBvpdAttr.H>
#include <fapi2_mbvpd_access.H>
#include  <generic/memory/lib/utils/c_str.H>

extern "C"
{
    using namespace fapi2;
    using namespace getAttrData;

///
/// @brief Get the ATTR_VPD_DW_KEYWORD FAPI attribute
///
/// @note Return the voltage setting data from MBvpd record SPDX keyword DW.
///
/// The ATTR_VPD_DW_KEYWORD attribute is associated with a DIMM. The platfrom must
/// get the associated MemBuff chip to be passed to this hwp accessor.
///
/// @param[in]  i_mbTarget - Reference to membuff Target
/// @param[out] o_val      - Filled in with vpd version
/// @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode getMBvpdVoltageSettingData(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&   i_mbTarget,
            uint32_t& o_val)
    {
        DimmType l_dimmType = DimmType::ISDIMM;
        fapi2::MBvpdRecord  l_record  = fapi2::MBVPD_RECORD_SPDX;
        uint16_t l_vpdVoltageSettingData = DW_KEYWORD_DEFAULT_VALUE;
        size_t l_bufSize = sizeof(l_vpdVoltageSettingData);

        FAPI_DBG("getMBvpdVoltageSettingData: entry ");

        FAPI_DBG("getMBvpdVoltageSettingData: Membuff path=%s ",
                 mss::c_str(i_mbTarget));

        // Find the dimm type
        // Determine if ISDIMM or CDIMM

        // Find one mba target for passing it to fapi2GetAssociatedDimms
        auto l_mba_chiplets = i_mbTarget.getChildren<fapi2::TARGET_TYPE_MBA>();
        auto l_target_dimm_array = l_mba_chiplets[0].getChildren<fapi2::TARGET_TYPE_DIMM>();

        if(l_target_dimm_array.size() != 0)
        {
            uint8_t l_customDimm = 0;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_CUSTOM, l_target_dimm_array[0],
                                   l_customDimm), "getMBvpdVoltageSettingData: ATTR_SPD_CUSTOM failed ");

            if (l_customDimm == fapi2::ENUM_ATTR_CEN_SPD_CUSTOM_YES)
            {
                l_dimmType = DimmType::CDIMM;
                FAPI_DBG("getMBvpdVoltageSettingData: CDIMM TYPE!!!");
            }
            else
            {
                l_dimmType = DimmType::ISDIMM;
                FAPI_DBG("getMBvpdVoltageSettingData: ISDIMM TYPE!!!");
            }
        }
        else
        {
            l_dimmType = DimmType::ISDIMM;
            FAPI_DBG("getMBvpdVoltageSettingData: ISDIMM TYPE (dimm array size = 0)");
        }


        if(l_dimmType == DimmType::CDIMM)
        {
            l_record = fapi2::MBVPD_RECORD_VSPD;
        }

        // get voltage setting data from record SPDX keyword DW
        FAPI_TRY(getMBvpdField(l_record,
                               fapi2::MBVPD_KEYWORD_DW,
                               i_mbTarget,
                               reinterpret_cast<uint8_t*>(&l_vpdVoltageSettingData),
                               l_bufSize), "getMBvpdVersion: Read of DW keyword failed");

        // Check that sufficient size was returned.
        FAPI_ASSERT(l_bufSize >= sizeof(l_vpdVoltageSettingData),
                    fapi2::CEN_MBVPD_INSUFFICIENT_VPD_RETURNED().
                    set_KEYWORD(fapi2::MBVPD_KEYWORD_DW).
                    set_RETURNED_SIZE(l_bufSize).
                    set_CHIP_TARGET(i_mbTarget),
                    "getMBvpdVoltageSettingData:"
                    " less keyword data returned than expected %d < %d",
                    l_bufSize, sizeof(l_vpdVoltageSettingData));


        // return value
        o_val = static_cast<uint32_t>(be16toh(l_vpdVoltageSettingData));

        FAPI_DBG("getMBvpdVoltageSettingData: voltage setting Data=0x%08x",
                 o_val);

        FAPI_DBG("getMBvpdVoltageSettingData: exit");
    fapi_try_exit:
        return fapi2::current_err;
    }

}   // extern "C"
