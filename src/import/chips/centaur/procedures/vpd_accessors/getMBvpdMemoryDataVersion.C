/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getMBvpdMemoryDataVersion.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
///  @file getMBvpdMemoryDataVersion.C
///  @brief MBVPD Accessor for providing the ATTR_VPD_VM_KEYWORD attribute
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#include    <stdint.h>

//  fapi2 support
#include    <fapi2.H>
#include    <getMBvpdMemoryDataVersion.H>
#include    <getMBvpdAttr.H>
#include  <generic/memory/lib/utils/c_str.H>

extern "C"
{
    using namespace fapi2;
    using namespace getAttrData;

///
/// @brief Get the ATTR_VPD_VM_KEYWORD FAPI attribute
/// Return the Memory Data version from MBvpd record SPDX keyword VM.
///
/// The ATTR_VPD_VM_KEYWORD attribute is associated with a DIMM. The platfrom must
/// get the associated Membuff chip to be passed to this hwp accessor.
///
/// @param[in]  i_mbTarget - Reference to membuf Target
/// @param[out] o_val      - Filled in with vpd version
/// @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode getMBvpdMemoryDataVersion(
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&   i_mbTarget,
        uint32_t&   o_val)
    {
        union l_KeywordUnion
        {
            uint32_t vpdMemoryDataVersion;
            MBvpdVMKeyword mBvpdVMKeyword;
        };

        fapi2::ReturnCode l_fapi2rc;
        DimmType l_dimmType = DimmType::ISDIMM;
        fapi2::MBvpdRecord  l_record  = fapi2::MBVPD_RECORD_SPDX;
        l_KeywordUnion l_vpdMDataUnion = {VM_KEYWORD_DEFAULT_VALUE};
        size_t l_bufSize = sizeof(l_vpdMDataUnion.vpdMemoryDataVersion);

        FAPI_DBG("getMBvpdMemoryDataVersion: entry ");

        FAPI_DBG("getMBvpdMemoryDataVersion: Membuff path=%s ",
                 mss::c_str(i_mbTarget));

        // Find the dimm type
        // Determine if ISDIMM or CDIMM

        // Find one mba target for getting associated dimms
        auto l_mba_chiplets = i_mbTarget.getChildren<fapi2::TARGET_TYPE_MBA>();

        if(l_mba_chiplets.size() == 0)
        {
            FAPI_ERR("getMBvpdMemoryDataVersion: Problem getting MBA's of Membuff");
            return FAPI2_RC_FALSE;   //return error
        }

        auto l_target_dimm_array = l_mba_chiplets[0].getChildren<fapi2::TARGET_TYPE_DIMM>();

        if(l_target_dimm_array.size() != 0)
        {
            uint8_t l_customDimm = 0;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_CUSTOM, l_target_dimm_array[0],
                                   l_customDimm), "getMBvpdMemoryDataVersion: ATTR_SPD_CUSTOM failed");

            if (l_customDimm == fapi2::ENUM_ATTR_CEN_SPD_CUSTOM_YES)
            {
                l_dimmType = DimmType::CDIMM;
                FAPI_DBG("getMBvpdMemoryDataVersion: CDIMM TYPE!!!");
            }
            else
            {
                l_dimmType = DimmType::ISDIMM;
                FAPI_DBG("getMBvpdMemoryDataVersion: ISDIMM TYPE!!!");
            }
        }
        else
        {
            l_dimmType = DimmType::ISDIMM;
            FAPI_DBG("getMBvpdMemoryDataVersion: ISDIMM TYPE (dimm array size = 0)");
        }

        if( l_dimmType == DimmType::CDIMM)
        {
            l_record = fapi2::MBVPD_RECORD_VSPD;
        }

        // get Memory Data  version from record VSPD/SPDX keyword VM
        l_fapi2rc = getMBvpdField(l_record,
                                  fapi2::MBVPD_KEYWORD_VM,
                                  i_mbTarget,
                                  reinterpret_cast<uint8_t*>(&l_vpdMDataUnion.vpdMemoryDataVersion),
                                  l_bufSize);

        if (l_fapi2rc)
        {
            FAPI_DBG("getMBvpdMemoryDataVersion: Returning default"
                     " as VM keyword read failed.");
            return fapi2::FAPI2_RC_SUCCESS;// Lets make it success and return default
        }

        // Check that sufficient size was returned.
        FAPI_ASSERT(l_bufSize >= sizeof(l_vpdMDataUnion.vpdMemoryDataVersion),
                    fapi2::CEN_MBVPD_INSUFFICIENT_VPD_RETURNED().
                    set_KEYWORD(fapi2::MBVPD_KEYWORD_VM).
                    set_RETURNED_SIZE(l_bufSize).
                    set_CHIP_TARGET(i_mbTarget),
                    "getMBvpdMemoryDataVersion:"
                    " less keyword data returned than expected %d < %d",
                    l_bufSize, sizeof(l_vpdMDataUnion.vpdMemoryDataVersion));

        // Check if the format byte in the value returned is in between valid
        // range
        FAPI_ASSERT(( l_vpdMDataUnion.mBvpdVMKeyword.iv_version <=
                      VM_SUPPORTED_HIGH_VER ) &&
                    ( l_vpdMDataUnion.mBvpdVMKeyword.iv_version !=
                      VM_NOT_SUPPORTED ),
                    fapi2::CEN_MBVPD_INVALID_VM_DATA_RETURNED().
                    set_KEYWORD(fapi2::MBVPD_KEYWORD_VM).
                    set_RETURNED_VALUE(l_vpdMDataUnion.vpdMemoryDataVersion).
                    set_RECORD_NAME(l_record).
                    set_DIMM_TYPE(l_dimmType).
                    set_CHIP_TARGET(i_mbTarget),
                    "getMBvpdMemoryDataVersion:"
                    " keyword data returned is invalid : %d ",
                    l_vpdMDataUnion.vpdMemoryDataVersion);

        // return value
        o_val = static_cast<uint32_t>(be16toh(l_vpdMDataUnion.vpdMemoryDataVersion));

        FAPI_DBG("getMBvpdMemoryDataVersion: Memory Data version=0x%08x",
                 o_val);


        FAPI_DBG("getMBvpdMemoryDataVersion: exit");
    fapi_try_exit:
        return fapi2::current_err;
    }

}   // extern "C"
