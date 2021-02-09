/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getMBvpdAttr.C $ */
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
///  @file getMBvpdAttr.C
///  @brief Prototype for getMBvpdAttr() -get Attribute Data from MBvpd
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#include    <stdint.h>

//  fapi2 support
#include    <fapi2.H>
#include    <getMBvpdAttr.H>
#include  <generic/memory/lib/utils/c_str.H>
// Used to ensure attribute enums are equal at compile time
class Error_ConstantsDoNotMatch;
template<const bool MATCH> void checkConstantsMatch()
{
    Error_ConstantsDoNotMatch();
}
template <> inline void checkConstantsMatch<true>() {}

extern "C"
{
    using   namespace   fapi2;
    using   namespace   getAttrData;

// ----------------------------------------------------------------------------
// local functions
// ----------------------------------------------------------------------------
    /**
     *  @brief Find attribute definition in global table
     */
    fapi2::ReturnCode findAttrDef (const fapi2::Target<fapi2::TARGET_TYPE_MBA>&     i_mbaTarget,
                                   const DimmType&         i_dimmType,
                                   const fapi2::AttributeId& i_attr,
                                   const MBvpdAttrDef*&    o_pAttrDef,
                                   const VpdVersion&       i_version);
    /**
     *  @brief Read the attribute keyword
     */
    fapi2::ReturnCode readKeyword (const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&    i_mbTarget,
                                   const fapi2::Target<fapi2::TARGET_TYPE_MBA>&    i_mbaTarget,
                                   const MBvpdAttrDef*    i_pAttrDef,
                                   const DimmType&        i_dimmType,
                                   uint8_t*         i_pBuffer,
                                   const uint32_t&        i_bufsize,
                                   const VpdVersion&      i_version);
    /**
     *  @brief return default output value
     */
    fapi2::ReturnCode returnDefault (const MBvpdAttrDef*     i_pAttrDef,
                                     void*           o_pVal,
                                     const size_t&           i_valSize);

    /**
     *  @brief Return the output value
     */
    fapi2::ReturnCode returnValue (const MBvpdAttrDef*     i_pAttrDef,
                                   const uint8_t&          i_pos,
                                   void*             o_pVal,
                                   const size_t&           i_valSize,
                                   uint8_t*          i_pBuffer,
                                   const VpdVersion&       i_version);

// return version from keyword VM or VZ or VD
    fapi2::ReturnCode getVersion  (const fapi2::Target<fapi2::TARGET_TYPE_MBA>&     i_mbaTarget,
                                   const DimmType&         i_dimmType,
                                   VpdVersion&             o_version);


    /**
     *  @brief Translation functions
     */
    fapi2::ReturnCode xlate_DRAM_RON (const fapi2::AttributeId i_attr,
                                      uint8_t& io_value);
    fapi2::ReturnCode xlate_RTT_NOM  (const fapi2::AttributeId i_attr,
                                      uint8_t& io_value);
    fapi2::ReturnCode xlate_RTT_PARK  (const fapi2::AttributeId i_attr,
                                       uint8_t& io_value);
    fapi2::ReturnCode xlate_RTT_WR   (const fapi2::AttributeId i_attr,
                                      uint8_t& io_value);
    fapi2::ReturnCode xlate_WR_VREF  (const fapi2::AttributeId i_attr,
                                      uint32_t& io_value);
    fapi2::ReturnCode xlate_RD_VREF  (const fapi2::AttributeId i_attr,
                                      uint32_t& io_value);
    fapi2::ReturnCode xlate_SLEW_RATE (const fapi2::AttributeId i_attr,
                                       uint8_t& io_value);

    /**
     *  @brief Find the ISDIMM MR keyword
     */
    fapi2::ReturnCode FindMRkeyword (const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&        i_mbTarget,
                                     fapi2::MBvpdKeyword& o_keyword);
    /**
     *  @brief Find the ISDIMM MT keyword
     */
    fapi2::ReturnCode FindMTkeyword (const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&        i_mbTarget,
                                     const fapi2::Target<fapi2::TARGET_TYPE_MBA>&        i_mbaTarget,
                                     fapi2::MBvpdKeyword& o_keyword,
                                     const VpdVersion&          i_version);

    keywordLayout* layoutFactory :: getLayout(const uint32_t& i_keyword,
            const uint32_t& i_ver)
    {
        switch(i_ver)
        {
            case VM_01:
                {
                    switch(i_keyword)
                    {
                        case MBVPD_KEYWORD_MT:
                        case MBVPD_KEYWORD_PD1:
                        case MBVPD_KEYWORD_PDZ:
                        case MBVPD_KEYWORD_PD4:
                        case MBVPD_KEYWORD_PD5:
                        case MBVPD_KEYWORD_PD6:
                        case MBVPD_KEYWORD_PD8:
                        case MBVPD_KEYWORD_PDY:
                            {
                                return ( new VM_01_MT_layout());
                            }

                        case MBVPD_KEYWORD_M1:
                        case MBVPD_KEYWORD_M2:
                        case MBVPD_KEYWORD_M3:
                        case MBVPD_KEYWORD_M4:
                        case MBVPD_KEYWORD_M5:
                        case MBVPD_KEYWORD_M6:
                        case MBVPD_KEYWORD_M7:
                        case MBVPD_KEYWORD_M8:
                        case MBVPD_KEYWORD_MR:
                            {
                                return ( new VM_01_MR_layout());
                            }

                        default:
                            return NULL;
                    }
                }

            default:
                {
                    switch(i_keyword)
                    {
                        case MBVPD_KEYWORD_MT:
                        case MBVPD_KEYWORD_T1:
                        case MBVPD_KEYWORD_T2:
                        case MBVPD_KEYWORD_T4:
                        case MBVPD_KEYWORD_T5:
                        case MBVPD_KEYWORD_T6:
                        case MBVPD_KEYWORD_T8:
                            {
                                return ( new VM_00_MT_layout());
                            }

                        case MBVPD_KEYWORD_M1:
                        case MBVPD_KEYWORD_M2:
                        case MBVPD_KEYWORD_M3:
                        case MBVPD_KEYWORD_M4:
                        case MBVPD_KEYWORD_M5:
                        case MBVPD_KEYWORD_M6:
                        case MBVPD_KEYWORD_M7:
                        case MBVPD_KEYWORD_M8:
                        case MBVPD_KEYWORD_MR:
                            {
                                return ( new VM_00_MR_layout());
                            }

                        default:
                            return NULL;
                    }
                }
        }
    }


///
/// @brief get Attribute Data from MBvpd
/// @param[in]  i_mbaTarget       -   mba target
/// @param[in]  i_attr            -   Attribute ID
/// @param[out] o_pVal            -   pointer to variable typed output variable
/// @param[in]  i_valSize         -   size of output variable
/// @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,relevant error code for failure.
///
    fapi2::ReturnCode getMBvpdAttr(const fapi2::Target<fapi2::TARGET_TYPE_MBA>&   i_mbaTarget,
                                   const fapi2::AttributeId i_attr,
                                   void*   o_pVal,
                                   const size_t i_valSize)
    {
        uint8_t*    l_pBuffer = NULL;
        uint32_t    l_bufsize = 0;

        FAPI_DBG("getMBvpdAttr: entry attr=0x%02x, size=%d ",
                 i_attr, i_valSize  );

        do
        {
            fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_mbTarget;
            uint8_t  l_pos = NUM_PORTS;     //initialize to out of range value (+1)
            DimmType l_dimmType = DimmType::ALL_DIMM;
            const MBvpdAttrDef* l_pAttrDef = NULL;
            VpdVersion l_version = INVALID_VER; // invalid vpd value

            // find DIMM Info; parent, position, dimm type
            FAPI_TRY(findDimmInfo (i_mbaTarget, l_mbTarget, l_pos, l_dimmType));

            //read VPD version
            FAPI_TRY(getVersion (i_mbaTarget,
                                 l_dimmType,
                                 l_version),
                     "findAttrDef: getVersion failed");
            // find Attribute definition
            FAPI_TRY(findAttrDef (i_mbaTarget,
                                  l_dimmType,
                                  i_attr,
                                  l_pAttrDef,
                                  l_version));

            FAPI_DBG("getMBvpdAttr: attr=0x%08x, dimmType=%d "
                     "keyword=%d offset=%d outType=0x%04x default=%d ",
                     i_attr, l_dimmType, l_pAttrDef->iv_keyword, l_pAttrDef->iv_offset,
                     l_pAttrDef->iv_outputType, l_pAttrDef->iv_defaultValue  );

            // Either just return defaults or read keyword and return vpd data
            // Mask off the special processing flags from the output type.
            if (DEFAULT_VALUE ==
                ((l_pAttrDef->iv_outputType) & SPECIAL_PROCESSING_MASK))
            {
                FAPI_TRY(returnDefault (l_pAttrDef,
                                        o_pVal,
                                        i_valSize));

            }
            else
            {
                fapi2::MBvpdKeyword l_keyword = l_pAttrDef->iv_keyword;
                uint32_t l_keywordsize = 0;
                keywordLayout* l_kwLayout = layoutFactory::getLayout( l_keyword,
                                            l_version);

                if( l_kwLayout != NULL)
                {
                    l_keywordsize = l_kwLayout->getKeywordSize();
                }
                else
                {
                    FAPI_ASSERT(false,
                                fapi2::CEN_MBVPD_UNEXPECTED_KEYWORD().
                                set_ATTR_ID(i_attr).
                                set_KEYWORD(l_keyword).
                                set_VERSION(l_version).
                                set_DIMM_TYPE(l_dimmType),
                                "layoutFactory::getLayout:"
                                " returned NULL pointer for Keyword: 0x%x ,Version :0x%x",
                                l_keyword, l_version);
                }

                delete l_kwLayout;

                l_pBuffer = new uint8_t[l_keywordsize];
                l_bufsize = l_keywordsize;

                FAPI_TRY(readKeyword (l_mbTarget,
                                      i_mbaTarget,
                                      l_pAttrDef,
                                      l_dimmType,
                                      l_pBuffer,
                                      l_bufsize,
                                      l_version));

                // retrun the output value
                FAPI_TRY(returnValue (l_pAttrDef,
                                      l_pos,
                                      o_pVal,
                                      i_valSize,
                                      l_pBuffer,
                                      l_version));
            }
        }
        while (0);

        delete[] l_pBuffer;
        l_pBuffer = NULL;

    fapi_try_exit:
        return fapi2::current_err;
    }

// ----------------------------------------------------------------------------
// local functions
// ----------------------------------------------------------------------------

///
/// @brief Find dimm info; parent, type, position
/// @param[in] i_mbaTarget - mba target
/// @param[out] o_mbTarget - Parent chip
/// @param[out] o_pos - Dimm Position
/// @param[out] o_dimmType - Dimm type
/// @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,relevant error code for failure.
///
    fapi2::ReturnCode findDimmInfo (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mbaTarget,
                                    fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& o_mbTarget,
                                    uint8_t&       o_pos,
                                    DimmType&      o_dimmType)
    {
        // find the position of the passed mba on the centuar
        auto l_target_dimm_array = i_mbaTarget.getChildren<fapi2::TARGET_TYPE_DIMM>();
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_mbaTarget, o_pos), " getMBvpdAttr: Get MBA position failed ");
        FAPI_DBG("findDimmInfo: mba %s position=%d",
                 mss::c_str(i_mbaTarget),
                 o_pos);

        // find the Centaur memmory buffer from the passed MBA
        o_mbTarget = i_mbaTarget.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
        FAPI_DBG("findDimmInfo: parent path=%s ",
                 mss::c_str(o_mbTarget)  );

        // Determine if ISDIMM or CDIMM

        if(l_target_dimm_array.size() != 0)
        {
            uint8_t l_customDimm = 0;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_CUSTOM, l_target_dimm_array[0],
                                   l_customDimm), "findDimmInfo: ATTR_CEN_SPD_CUSTOM failed ");

            if (l_customDimm == fapi2::ENUM_ATTR_CEN_SPD_CUSTOM_YES)
            {
                o_dimmType = DimmType::CDIMM;
                FAPI_DBG("findDimmInfo: CDIMM TYPE!!!");
            }
            else
            {
                o_dimmType = DimmType::ISDIMM;
                FAPI_DBG("findDimmInfo: ISDIMM TYPE!!!");
            }
        }
        else
        {
            o_dimmType = DimmType::ISDIMM;
            FAPI_DBG("findDimmInfo: ISDIMM TYPE (dimm array size = 0)");
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief return version from fapi2 attribute if initialized else keyword VM else VZ else VD
/// @param[in] i_mbaTarget - mba target
/// @param[in] i_dimmType - CDIMM or ISDIMM
/// @param[out] o_version - output version
/// @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,relevant error code for failure.
///
    fapi2::ReturnCode getVersion  (const fapi2::Target<fapi2::TARGET_TYPE_MBA>&     i_mbaTarget,
                                   const DimmType&         i_dimmType,
                                   VpdVersion&             o_version)
    {
        fapi2::MBvpdKeyword l_keyword = MBVPD_KEYWORD_VM;  // try VM first
        fapi2::MBvpdRecord  l_record  = fapi2::MBVPD_RECORD_SPDX; // default to SPDX
        MBvpdVMKeyword l_vmVersionBuf = {};
        uint32_t l_version = 0;
        size_t l_vmBufSize = sizeof(MBvpdVMKeyword); // VM keyword is of 4 bytes.
        uint16_t l_versionBuf = 0;
        size_t l_bufSize = sizeof(l_versionBuf);
        bool     l_sizeMismatch = false;  // to track returned size vs expected size

        // find the Centaur memory buffer from the passed MBA
        auto l_mbTarget = i_mbaTarget.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

        // First try to get the MBVPD version from attrib
        // Proceed gracefully if the value is not initialized yet
        FAPI_ATTR_GET(fapi2::ATTR_CEN_MBVPD_VERSION,
                      l_mbTarget,
                      l_version);

        // If the version has been set, just use it directly and leave
        if( l_version != 0)
        {
            o_version = static_cast<VpdVersion>(l_version);
            FAPI_DBG("%s getVersion: vpd version=0x%x,", mss::c_str(i_mbaTarget),
                     o_version);
            return fapi2::FAPI2_RC_SUCCESS;
        }
        else
        {
            FAPI_INF("%s getVersion: read of MBVPD_VERSION attribute failed",
                     mss::c_str(i_mbaTarget));
        }

        // Couldn't  get the Version from attribute
        // So proceed to find the version and update the attrib
        if (DimmType::CDIMM == i_dimmType)
        {
            l_record = fapi2::MBVPD_RECORD_VSPD;
        }

        o_version = VM_VER;    // initialize to finding VM keyword

        // try to get VM keyword from SPDX or VSPD
        fapi2::current_err = getMBvpdField(l_record,
                                           l_keyword,
                                           l_mbTarget,
                                           reinterpret_cast<uint8_t*>(&l_vmVersionBuf),
                                           l_vmBufSize);

        if (l_vmBufSize < sizeof(MBvpdVMKeyword))
        {
            l_sizeMismatch = true;
        }

        if((fapi2::current_err == fapi2::FAPI2_RC_SUCCESS) && (!l_sizeMismatch))
        {
            FAPI_INF("getVersion: %s"
                     " returned vm data : 0x%x ", mss::c_str(i_mbaTarget),
                     l_vmVersionBuf.iv_version);

            // Get the first byte from VM keyword which has version value.
            l_versionBuf = l_vmVersionBuf.iv_version;
            FAPI_ASSERT(l_versionBuf <= VM_SUPPORTED_HIGH_VER,
                        fapi2::CEN_MBVPD_INVALID_VM_VERSION_RETURNED().
                        set_KEYWORD(l_keyword).
                        set_RETURNED_VALUE(l_versionBuf).
                        set_RECORD_NAME(l_record).
                        set_DIMM_TYPE(i_dimmType).
                        set_CHIP_TARGET(l_mbTarget),
                        "getVersion: "
                        "un-supported vm version returned : 0x%x ",
                        l_versionBuf);

            if(l_versionBuf != VM_NOT_SUPPORTED)
            {
                o_version = static_cast<VpdVersion>(o_version |
                                                    static_cast<VpdVersion>(l_versionBuf));
            }
        }

        // Get the VD in case of VM read error or
        // VM returned size is fine but with  value 0, then the Version is in
        // VD format.
        if((fapi2::current_err != fapi2::FAPI2_RC_SUCCESS) ||
           ((!l_sizeMismatch) && (l_versionBuf == VM_NOT_SUPPORTED)))
        {
            o_version = VD_VER;    // initialize to finding VD keyword
            l_keyword = MBVPD_KEYWORD_VD;
            l_bufSize = sizeof(l_versionBuf);

            // try to get VD keyword from SPDX or VSPD
            fapi2::current_err = getMBvpdField(l_record,
                                               l_keyword,
                                               l_mbTarget,
                                               reinterpret_cast<uint8_t*>(&l_versionBuf),
                                               l_bufSize);

            if (l_bufSize < sizeof(l_versionBuf))
            {
                l_sizeMismatch = true;
            }
            else if(fapi2::current_err == fapi2::FAPI2_RC_SUCCESS)
            {
                o_version = static_cast<VpdVersion>(o_version |
                                                    static_cast<VpdVersion>(be16toh(l_versionBuf)));
                l_sizeMismatch = false;
            }
        }

        // try record VINI keyword VZ (should work)
        if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
        {
            o_version = VZ_VER;    // VZ keyword
            l_record  = fapi2::MBVPD_RECORD_VINI;
            l_keyword = MBVPD_KEYWORD_VZ;
            l_bufSize = sizeof(l_versionBuf);

            fapi2::current_err = getMBvpdField(l_record,
                                               l_keyword,
                                               l_mbTarget,
                                               reinterpret_cast<uint8_t*>(&l_versionBuf),
                                               l_bufSize);

            if (l_bufSize < sizeof(l_versionBuf))
            {
                l_sizeMismatch = true;
            }
            else if(fapi2::current_err == fapi2::FAPI2_RC_SUCCESS)
            {
                o_version = static_cast<VpdVersion>(o_version |
                                                    static_cast<VpdVersion>(be16toh(l_versionBuf)));
                l_sizeMismatch = false;
            }
        }

        if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_ERR("getVersion: Read of VM,VD and VZ keyword failed");
            return fapi2::current_err;
        }

        if (l_sizeMismatch)
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MBVPD_INSUFFICIENT_VPD_RETURNED().
                        set_KEYWORD(l_keyword).
                        set_RETURNED_SIZE(l_bufSize).
                        set_CHIP_TARGET(l_mbTarget),
                        "getVersion:"
                        " less keyword data returned than expected %d < %d",
                        l_bufSize, sizeof(l_versionBuf));
        }

        FAPI_INF("getVersion: %s vpd version=0x%x keyword=%d",
                 mss::c_str(i_mbaTarget),
                 o_version, l_keyword);

        // cache the version value by updating attribute
        l_version = static_cast<uint32_t>(o_version);
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MBVPD_VERSION,
                               l_mbTarget,
                               l_version),
                 "getVersion: Setting of MBVPD_VERSION attribute failed");

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief find attribute definition
/// @param[in] i_mbaTarget - mba target
/// @param[in] i_dimmType - ISDIMM or CDIMM
/// @param[in] i_attr - input attribute
/// @param[out] o_pAttrDef - Attribute definition
/// @param[in] i_version - vpd version
/// @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,relevant error code for failure.
// table rules:
//     Vesions must be in decreasing order (highest first...)
//        for a specific Dimm Type. The first match found, searching
//        from row index 0 to the end, will be used.
    fapi2::ReturnCode findAttrDef (const fapi2::Target<fapi2::TARGET_TYPE_MBA>&     i_mbaTarget,
                                   const DimmType&         i_dimmType,
                                   const AttributeId&      i_attr,
                                   const MBvpdAttrDef*&    o_pAttrDef,
                                   const VpdVersion&       i_version)
    {
        o_pAttrDef = NULL;

        // find first row in the attribute defintion table for this attribute

        uint32_t i = 0; //at this scope for the debug message at end

        for (; i < g_MBVPD_ATTR_DEF_array_size; i++)
        {
            if ( (g_MBVPD_ATTR_DEF_array[i].iv_attrId == i_attr) &&
                 ((DimmType::ALL_DIMM   == g_MBVPD_ATTR_DEF_array[i].iv_dimmType) ||
                  (i_dimmType == g_MBVPD_ATTR_DEF_array[i].iv_dimmType)) )
            {

                // Some of them are expected to be the same for all Dimm Types and versions
                if (ALL_VER  == g_MBVPD_ATTR_DEF_array[i].iv_version)
                {
                    o_pAttrDef = &g_MBVPD_ATTR_DEF_array[i];
                    break; //use this row
                }

                // If this row is for this version type (VM or VD or VZ)
                // and is equal or less than the version, then use it
                if ((g_MBVPD_ATTR_DEF_array[i].iv_version &
                     (VpdVersion)(ALL_VER & i_version)) &&
                    ((g_MBVPD_ATTR_DEF_array[i].iv_version & VER_MASK) <=
                     (i_version & VER_MASK)) )
                {
                    o_pAttrDef = &g_MBVPD_ATTR_DEF_array[i];
                    break; //use this row
                }
            }
        }

        // return an error if definition was not found
        // Could be due to a table error, which shouldn't happen because
        // every attribute has an ALL_DIMM ALL_VER entry.
        // More likely due to an invalid attribute ID being passed.
        FAPI_ASSERT(o_pAttrDef != NULL,
                    fapi2::CEN_MBVPD_ATTRIBUTE_NOT_FOUND().
                    set_ATTR_ID(i_attr).
                    set_DIMM_TYPE(i_dimmType).
                    set_VERSION(i_version),
                    "findAttrDef:"
                    " attr ID 0x%x not in table  dimmType=%d version=%x",
                    i_attr,
                    i_dimmType,
                    i_version);

        FAPI_DBG("findAttrDef: use attribute definition row=%d", i );
    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief read the attribute keyword
/// @note: i_pAttrDef->iv_dimmType is likely ALL_DIMM were as
/// @note      l_dimmType will be either CDIMM or ISDIMM
/// @param[in] i_mbTarget - Membuf chip target
/// @param[in] i_mbaTarget - MBA target
/// @param[in] i_pAttrDef - Attribute definition
/// @param[in] i_dimmType - CDIMM or ISDIMM
/// @param[in] i_pBuffer - pointer
/// @param[in] i_bufsize - buffer size
/// @param[in] i_version - vpd version
/// @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,relevant error code for failure.
///
    fapi2::ReturnCode readKeyword (const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&    i_mbTarget,
                                   const fapi2::Target<fapi2::TARGET_TYPE_MBA>&    i_mbaTarget,
                                   const MBvpdAttrDef*    i_pAttrDef,
                                   const DimmType&        i_dimmType,
                                   uint8_t*         i_pBuffer,
                                   const uint32_t&        i_bufsize,
                                   const VpdVersion&      i_version)
    {
        size_t l_bufsize = i_bufsize;
        uint32_t l_keywordsize = 0;
        fapi2::MBvpdKeyword l_keyword = i_pAttrDef->iv_keyword; //default for CDIMMs
        fapi2::MBvpdRecord  l_record  = MBVPD_RECORD_VSPD;      //default for CDIMMs

        FAPI_DBG("readKeyword: Read keyword %d ", l_keyword);

        if (DimmType::CDIMM != i_dimmType)
        {
            if (MBVPD_KEYWORD_MT == l_keyword)
            {
                FAPI_TRY(FindMTkeyword (i_mbTarget,
                                        i_mbaTarget,
                                        l_keyword,
                                        i_version));
            }
            else if (MBVPD_KEYWORD_MR == l_keyword)
            {
                FAPI_TRY(FindMRkeyword (i_mbTarget,
                                        l_keyword));
            }
            else //table error, shouldn't happen
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MBVPD_UNEXPECTED_ISDIMM_KEYWORD().
                            set_ATTR_ID(i_pAttrDef->iv_attrId).
                            set_KEYWORD(l_keyword),
                            "readKeyword: invalid keyword %d for dimmType=%d");
            }

            l_record  = fapi2::MBVPD_RECORD_SPDX;      // for ISDIMMs

        }
        else
        {
            if(( i_version == VM_01 ) && (MBVPD_KEYWORD_MT == l_keyword))
            {
                l_keyword = MBVPD_KEYWORD_PDY;
            }
        }

        // Retrieve attribute keyword
        FAPI_TRY(getMBvpdField(l_record,
                               l_keyword,
                               i_mbTarget,
                               reinterpret_cast<uint8_t*>(i_pBuffer),
                               l_bufsize));
        // "readKeyword: Read of attr keyword failed\nreadKeyword:Attribute : 0x%x ,version : 0x%x\nreadKeyword : Keyword : 0x%x , record 0x%x",
        // i_pAttrDef->iv_attrId, i_version, l_keyword , l_record);

        // Check that sufficient keyword was returned.
        FAPI_ASSERT(l_bufsize >= i_bufsize,
                    fapi2::CEN_MBVPD_INSUFFICIENT_VPD_RETURNED().
                    set_KEYWORD(l_keyword).
                    set_RETURNED_SIZE(l_bufsize).
                    set_CHIP_TARGET(i_mbTarget),
                    "readKeyword:"
                    " less keyword returned than expected %d < %d",
                    l_bufsize, l_keywordsize);

    fapi_try_exit:
        return fapi2::current_err;
    }

// used by returnValue to consolidate setting invalid size error
    fapi2::ReturnCode sizeMismatch (const size_t   i_correctSize,
                                    const size_t   i_inputSize,
                                    const fapi2::AttributeId i_attr)
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MBVPD_INVALID_OUTPUT_VARIABLE_SIZE().
                    set_ATTR_ID(i_attr).
                    set_EXPECTED_SIZE(i_correctSize).
                    set_PASSED_SIZE(i_inputSize),
                    "sizeMismatch:"
                    " output variable size does not match expected %d != %d"
                    " for attr id=0x%08x",
                    i_correctSize, i_inputSize, i_attr);
    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief return default output value
/// @param[in] i_pAttrDef - Attribute def
/// @param[out] o_pVal - pointer
/// @param[in] i_valSize - Size
/// @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,relevant error code for failure.
///
    fapi2::ReturnCode returnDefault (const MBvpdAttrDef*   i_pAttrDef,
                                     void*                 o_pVal,
                                     const size_t&         i_valSize)
    {
        uint16_t  l_outputType = i_pAttrDef->iv_outputType & OUTPUT_TYPE_MASK;

        FAPI_DBG("returnDefault: default value outputType=0x%04x ",
                 l_outputType);

        // return default according to the attribute varible type
        switch (l_outputType)
        {
            case UINT8_BY2:        // uint8_t [2]
                {
                    // make sure return value size is correct
                    if (sizeof(UINT8_BY2_t) != i_valSize)
                    {
                        FAPI_TRY(sizeMismatch(sizeof(UINT8_BY2_t),
                                              i_valSize,
                                              i_pAttrDef->iv_attrId));
                        break;
                    }

                    uint8_t l_value = (uint8_t)i_pAttrDef->iv_defaultValue;

                    (*(UINT8_BY2_t*)o_pVal)[0] = l_value;
                    (*(UINT8_BY2_t*)o_pVal)[1] = l_value;
                    break;
                }

            case  UINT8_BY2_BY2:     // uint8_t  [2][2]
                {
                    // make sure return value size is correct
                    if (sizeof(UINT8_BY2_BY2_t) != i_valSize)
                    {
                        FAPI_TRY(sizeMismatch(sizeof(UINT8_BY2_BY2_t),
                                              i_valSize,
                                              i_pAttrDef->iv_attrId));
                        break; //return with error
                    }

                    uint8_t l_value =  (uint8_t)i_pAttrDef->iv_defaultValue;

                    for (uint8_t l_port = 0; l_port < NUM_PORTS; l_port++)
                    {
                        for (uint8_t l_j = 0; l_j < NUM_DIMMS; l_j++)
                        {
                            (*(UINT8_BY2_BY2_t*)o_pVal)[l_port][l_j] = l_value;
                        }
                    }

                    break;
                }

            case  UINT8_BY2_BY2_BY4: // uint8_t  [2][2][4]
                {
                    // make sure return value size is correct
                    if (sizeof(UINT8_BY2_BY2_BY4_t) != i_valSize)
                    {
                        FAPI_TRY(sizeMismatch(sizeof(UINT8_BY2_BY2_BY4_t),
                                              i_valSize,
                                              i_pAttrDef->iv_attrId));
                        break; //return with error
                    }

                    uint8_t l_value = (uint8_t)i_pAttrDef->iv_defaultValue;

                    for (uint8_t l_port = 0; l_port < NUM_PORTS; l_port++)
                    {
                        for (uint8_t l_j = 0; l_j < NUM_DIMMS; l_j++)
                        {
                            for (uint8_t l_k = 0; l_k < NUM_RANKS; l_k++)
                            {
                                (*(UINT8_BY2_BY2_BY4_t*)o_pVal)[l_port][l_j][l_k] =
                                    l_value;
                            }
                        }
                    }

                    break;
                }

            case  UINT32_BY2:        // uint32_t [2]
                {
                    // make sure return value size is correct
                    if (sizeof(UINT32_BY2_t) != i_valSize)
                    {
                        FAPI_TRY(sizeMismatch(sizeof(UINT32_BY2_t),
                                              i_valSize,
                                              i_pAttrDef->iv_attrId));
                        break; //return with error
                    }

                    uint32_t l_value = (uint32_t)i_pAttrDef->iv_defaultValue;

                    for (uint8_t l_port = 0; l_port < 2; l_port++)
                    {
                        (*(UINT32_BY2_t*)o_pVal)[l_port] = l_value;
                    }

                    break;
                }

            case  UINT32_BY2_BY2:        // uint32_t [2][2]
                {
                    // make sure return value size is correct
                    if (sizeof(UINT32_BY2_BY2_t) != i_valSize)
                    {
                        FAPI_TRY(sizeMismatch(sizeof(UINT32_BY2_BY2_t),
                                              i_valSize,
                                              i_pAttrDef->iv_attrId));
                        break; //return with error
                    }

                    uint32_t l_value = (uint32_t)i_pAttrDef->iv_defaultValue;

                    for (uint8_t l_port = 0; l_port < NUM_PORTS; l_port++)
                    {
                        for (uint8_t l_j = 0; l_j < NUM_DIMMS; l_j++)
                        {
                            (*(UINT32_BY2_BY2_t*)o_pVal)[l_port][l_j] = l_value;
                        }
                    }

                    break;
                }

            case  UINT64:            // uint64_t
                {
                    // make sure return value size is correct
                    if (sizeof(UINT64_t) != i_valSize)
                    {
                        FAPI_TRY(sizeMismatch(sizeof(UINT64_t),
                                              i_valSize,
                                              i_pAttrDef->iv_attrId));
                        break; //return with error
                    }

                    uint64_t l_value = (uint64_t)i_pAttrDef->iv_defaultValue;
                    (*(UINT64_t*)o_pVal) = l_value;
                    break ;
                }

            default: // Hard to do, but needs to be caught
                FAPI_ASSERT(false,
                            fapi2::CEN_MBVPD_DEFAULT_UNEXPECTED_OUTPUT_TYPE().
                            set_ATTR_ID(i_pAttrDef->iv_attrId).
                            set_DIMM_TYPE(i_pAttrDef->iv_dimmType).
                            set_OUTPUT_TYPE(i_pAttrDef->iv_outputType),
                            "returnDefault: invalid output type 0x%04x for"
                            " attribute ID 0x%08x",
                            i_pAttrDef->iv_outputType,
                            i_pAttrDef->iv_attrId);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief used by returnValue to consolidate pulling an uint32_t value from vpd based
/// on the size of the data in the vpd layout (uint8_t, uint16_t, or uint32_t).
/// @param[in] i_dataSpecial
/// @param[in] i_pBuffer
/// @return uint32_t
///
    uint32_t getUint32 (const uint16_t& i_dataSpecial,
                        uint8_t*   i_pBuffer)
    {
        uint32_t o_val = 0;

        if (UINT8_DATA == i_dataSpecial)
        {
            o_val = *i_pBuffer;
        }
        else if (UINT16_DATA == i_dataSpecial)
        {
            o_val = *(i_pBuffer + 1);    // LSB
            o_val |= ((*i_pBuffer) << 8); // MSB
        }
        else
        {
            o_val  = be32toh(*(uint32_t*) i_pBuffer);
        }

        return o_val;
    }

///
/// @brief return the output value
/// @note i_pBuffer will be NULL if the default value is to be used.
/// @param[in] i_pos
/// @param[in] o_pVal
/// @param[out] i_valSize
/// @param[in] i_pBuffer
/// @param[in] i_version
/// @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,relevant error code for failure.
///
    fapi2::ReturnCode returnValue (const MBvpdAttrDef*   i_pAttrDef,
                                   const uint8_t&          i_pos,
                                   void*             o_pVal,
                                   const size_t&           i_valSize,
                                   uint8_t*          i_pBuffer,
                                   const VpdVersion&       i_version)
    {
        const uint8_t l_attrOffset = i_pAttrDef->iv_offset;
        uint32_t l_port_spec_sec_size = 0;
        uint32_t l_mba_sec_size = 0;
        fapi2::MBvpdKeyword l_keyword = i_pAttrDef->iv_keyword;
        uint16_t  l_outputType = i_pAttrDef->iv_outputType & OUTPUT_TYPE_MASK;
        uint16_t  l_special   = i_pAttrDef->iv_outputType & SPECIAL_PROCESSING_MASK;

        FAPI_DBG("returnValue: output offset=0%02x pos=%d outputType=0x%04x"
                 " special=0x%04x ",
                 l_attrOffset, i_pos, l_outputType, l_special);

        // UINT8 : only 1 value is present, it isn't stored per mba/port
        if( l_outputType != UINT8 )
        {
            keywordLayout* l_kwLayout = layoutFactory::getLayout( l_keyword,
                                        i_version);

            if( l_kwLayout != NULL)
            {
                // Move the pointer to port specific section data
                i_pBuffer += l_kwLayout->getNonPortHeadSize();
                l_port_spec_sec_size = l_kwLayout->getPortSectionSize();
                l_mba_sec_size       = l_port_spec_sec_size * NUM_PORTS;
                delete l_kwLayout;
            }
        }

        // return data according to the attribute varible type
        switch (l_outputType)
        {
            case UINT8_BY2:        // uint8_t [2]
                {
                    // make sure return value size is correct
                    if (sizeof(UINT8_BY2_t) != i_valSize)
                    {
                        FAPI_TRY(sizeMismatch(sizeof(UINT8_BY2_t),
                                              i_valSize,
                                              i_pAttrDef->iv_attrId));
                        break; //return with error
                    }

                    // pull data from keyword buffer
                    uint8_t l_port0 = *( i_pBuffer + ( i_pos * l_mba_sec_size)
                                         + (0 *  l_port_spec_sec_size) + l_attrOffset);
                    uint8_t l_port1 = *( i_pBuffer + ( i_pos * l_mba_sec_size)
                                         + (1 *  l_port_spec_sec_size) + l_attrOffset);

                    switch (l_special)
                    {
                        case LOW_NIBBLE: // return low nibble
                            l_port0 = l_port0 & 0x0F;
                            l_port1 = l_port1 & 0x0F;
                            break;

                        case HIGH_NIBBLE: // return high nibble
                            l_port0 = ((l_port0 & 0xF0) >> 4);
                            l_port1 = ((l_port1 & 0xF0) >> 4);
                            break;

                        case PORT00: // return port 0 for both ports 0 and 1
                            l_port1 = l_port0;
                            break;

                        case PORT11: // return port 1 for both ports 0 and 1
                            l_port0 = l_port1;
                            break;

                        case XLATE_SLEW:
                            FAPI_TRY(xlate_SLEW_RATE( i_pAttrDef->iv_attrId, l_port0));
                            FAPI_TRY(xlate_SLEW_RATE( i_pAttrDef->iv_attrId, l_port1));

                        default:
                            ;      // use data  directly from  keyword buffer
                    }

                    (*(UINT8_BY2_t*)o_pVal)[0] = l_port0;
                    (*(UINT8_BY2_t*)o_pVal)[1] = l_port1;
                    break;
                }

            case  UINT8_BY2_BY2:     // uint8_t  [2][2]
                {
                    // make sure return value size is correct
                    if (sizeof(UINT8_BY2_BY2_t) != i_valSize)
                    {
                        FAPI_TRY(sizeMismatch(sizeof(UINT8_BY2_BY2_t),
                                              i_valSize,
                                              i_pAttrDef->iv_attrId));
                        break; //return with error
                    }

                    for (uint8_t l_port = 0; l_port < NUM_PORTS; l_port++)
                    {
                        uint8_t l_dimm0 = *( i_pBuffer + ( i_pos * l_mba_sec_size)
                                             + (l_port *  l_port_spec_sec_size) + l_attrOffset);
                        uint8_t l_dimm1 = 0;

                        if (BOTH_DIMMS == l_special)
                        {
                            l_dimm1 = l_dimm0; //use vpd value for both DIMMs
                        }
                        else
                        {
                            l_dimm1 = *( i_pBuffer + ( i_pos * l_mba_sec_size)
                                         + (l_port *  l_port_spec_sec_size) + l_attrOffset + 1);

                            switch (l_special)
                            {
                                case XLATE_DRAM_RON: // translate
                                    FAPI_TRY(
                                        xlate_DRAM_RON(i_pAttrDef->iv_attrId, l_dimm0));
                                    FAPI_TRY(
                                        xlate_DRAM_RON(i_pAttrDef->iv_attrId, l_dimm1));

                                default:
                                    ;      // use data  directly from  keyword buffer
                            }
                        }

                        (*(UINT8_BY2_BY2_t*)o_pVal)[l_port][0] = l_dimm0;
                        (*(UINT8_BY2_BY2_t*)o_pVal)[l_port][1] = l_dimm1;
                    }

                    break;
                }

            case  UINT8_BY2_BY2_BY4: // uint8_t  [2][2][4]
                {
                    // make sure return value size is correct
                    if (sizeof(UINT8_BY2_BY2_BY4_t) != i_valSize)
                    {
                        FAPI_TRY(sizeMismatch(sizeof(UINT8_BY2_BY2_BY4_t),
                                              i_valSize,
                                              i_pAttrDef->iv_attrId));
                        break; //return with error
                    }

                    uint8_t l_value = 0;

                    for (uint8_t l_port = 0; l_port < NUM_PORTS; l_port++)
                    {
                        for (uint8_t l_j = 0; l_j < NUM_DIMMS; l_j++)
                        {
                            for (uint8_t l_k = 0; l_k < NUM_RANKS; l_k++)
                            {
                                l_value = *( i_pBuffer + ( i_pos * l_mba_sec_size)
                                             + (l_port *  l_port_spec_sec_size)
                                             + ( l_attrOffset + (l_j) * NUM_RANKS + l_k));

                                switch (l_special)
                                {
                                    case XLATE_RTT_NOM: // translate
                                        FAPI_TRY(xlate_RTT_NOM(i_pAttrDef->iv_attrId,
                                                               l_value));
                                        break;

                                    case XLATE_RTT_PARK: // translate
                                        FAPI_TRY(xlate_RTT_PARK(i_pAttrDef->iv_attrId,
                                                                l_value));
                                        break;

                                    case XLATE_RTT_WR: // translate
                                        FAPI_TRY(xlate_RTT_WR(i_pAttrDef->iv_attrId,
                                                              l_value));

                                    default:
                                        ;     // use data  directly from  keyword buffer
                                }

                                (*(UINT8_BY2_BY2_BY4_t*)o_pVal)[l_port][l_j][l_k] =
                                    l_value;
                            }
                        }
                    }

                    break;

                }

            case  UINT32_BY2:        // uint32_t [2]
                {
                    // make sure return value size is correct
                    if (sizeof(UINT32_BY2_t) != i_valSize)
                    {
                        FAPI_TRY(sizeMismatch(sizeof(UINT32_BY2_t),
                                              i_valSize,
                                              i_pAttrDef->iv_attrId));
                        break; //return with error
                    }

                    uint16_t l_xlateSpecial = SPECIAL_XLATE_MASK & l_special;
                    uint16_t l_dataSpecial  = SPECIAL_DATA_MASK  & l_special;

                    for (uint8_t l_port = 0; l_port < 2; l_port++)
                    {
                        uint32_t l_value = getUint32 (l_dataSpecial,
                                                      ( i_pBuffer + ( i_pos * l_mba_sec_size) +
                                                        + (l_port *  l_port_spec_sec_size) + l_attrOffset));

                        switch (l_xlateSpecial)
                        {
                            case XLATE_RD_VREF: // translate
                                FAPI_TRY(xlate_RD_VREF(i_pAttrDef->iv_attrId,
                                                       l_value));
                                break;

                            case XLATE_WR_VREF: // translate
                                FAPI_TRY(xlate_WR_VREF(i_pAttrDef->iv_attrId,
                                                       l_value));

                            default:
                                ;     // use data  directly from  keyword buffer
                        }

                        (*(UINT32_BY2_t*)o_pVal)[l_port] = l_value;
                    }

                    break;
                }

            case  UINT32_BY2_BY2:        // uint32_t [2][2]
                {
                    // make sure return value size is correct
                    if (sizeof(UINT32_BY2_BY2_t) != i_valSize)
                    {
                        FAPI_TRY(sizeMismatch(sizeof(UINT32_BY2_BY2_t),
                                              i_valSize,
                                              i_pAttrDef->iv_attrId));
                        break; //return with error
                    }

                    uint16_t l_dataSpecial  = SPECIAL_DATA_MASK  & l_special;
                    uint8_t  l_vpdIncrement = 4; //default to 4 byte vpd field

                    if  (UINT8_DATA == l_dataSpecial)
                    {
                        l_vpdIncrement = 1;     // vpd is only 1 byte
                    }
                    else if  (UINT16_DATA == l_dataSpecial)
                    {
                        l_vpdIncrement = 2;     // vpd is 2 bytes
                    }

                    for (uint8_t l_port = 0; l_port < 2; l_port++)
                    {
                        uint8_t l_vpdOffset = 0;

                        for (uint8_t l_j = 0; l_j < NUM_DIMMS; l_j++)
                        {
                            uint32_t l_value = getUint32 (l_dataSpecial,
                                                          ( i_pBuffer + ( i_pos * l_mba_sec_size) +
                                                            + (l_port *  l_port_spec_sec_size)
                                                            + (l_attrOffset + l_vpdOffset)));

                            (*(UINT32_BY2_BY2_t*)o_pVal)[l_port][l_j] = l_value;
                            l_vpdOffset += l_vpdIncrement;
                        }
                    }

                    break;
                }

            case  UINT64:            // uint64_t
                {
                    // make sure return value size is correct
                    if (sizeof(UINT64_t) != i_valSize)
                    {
                        FAPI_TRY(sizeMismatch(sizeof(UINT64_t),
                                              i_valSize,
                                              i_pAttrDef->iv_attrId));
                        break; //return with error
                    }

                    uint64_t l_value = 0;

                    if (MERGE == l_special)
                    {
                        uint32_t l_port0 = getUint32 (UINT32_DATA,
                                                      ( i_pBuffer + ( i_pos * l_mba_sec_size) +
                                                        + (0 *  l_port_spec_sec_size) + l_attrOffset));
                        uint32_t l_port1 = getUint32 (UINT32_DATA,
                                                      ( i_pBuffer + ( i_pos * l_mba_sec_size) +
                                                        + (1 *  l_port_spec_sec_size) + l_attrOffset));

                        l_value = ( ((static_cast<uint64_t>(l_port0)) << 32) |
                                    (static_cast<uint64_t>(l_port1)) );
                    }
                    else
                    {
                        FAPI_ASSERT(false,
                                    fapi2::CEN_MBVPD_UINT64_UNEXPECTED_OUTPUT_TYPE().
                                    set_ATTR_ID(i_pAttrDef->iv_attrId).
                                    set_DIMM_TYPE(i_pAttrDef->iv_dimmType).
                                    set_OUTPUT_TYPE(i_pAttrDef->iv_outputType),
                                    "returnValue: invalid output type 0x%04x for"
                                    " attribute ID 0x%08x UINT64_T",
                                    i_pAttrDef->iv_outputType,
                                    i_pAttrDef->iv_attrId);
                    }

                    (*(UINT64_t*)o_pVal) = l_value;
                    break ;
                }

            case  UINT8:            // uint8_t
                {
                    // make sure return value size is correct
                    if (sizeof(UINT8_t) != i_valSize)
                    {
                        FAPI_TRY(sizeMismatch(sizeof(UINT8_t),
                                              i_valSize,
                                              i_pAttrDef->iv_attrId));
                        break; //return with error
                    }

                    // only 1 value is present, it isn't stored per mba/port
                    uint8_t l_value = (reinterpret_cast<uint8_t*>(i_pBuffer))[l_attrOffset];
                    (*(UINT8_t*)o_pVal) = l_value;
                    break ;
                }

            default: // Hard to do, but needs to be caught
                FAPI_ASSERT(false,
                            fapi2::CEN_MBVPD_UNEXPECTED_OUTPUT_TYPE().
                            set_ATTR_ID(i_pAttrDef->iv_attrId).
                            set_DIMM_TYPE(i_pAttrDef->iv_dimmType).
                            set_OUTPUT_TYPE(i_pAttrDef->iv_outputType),
                            "returnValue: invalid output type 0x%04x for"
                            " attribute ID 0x%08x",
                            i_pAttrDef->iv_outputType,
                            i_pAttrDef->iv_attrId);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief Translate vpd values to attribute enumeration for ATTR_CEN_VPD_DRAM_RON
/// @param[in] i_attr - Attribute ID
/// @param[in, out] io_value - ENUM
/// @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,relevant error code for failure.
///
    fapi2::ReturnCode xlate_DRAM_RON (const fapi2::AttributeId i_attr,
                                      uint8_t& io_value)
    {
        const uint8_t VPD_DRAM_RON_INVALID = 0x00;
        const uint8_t VPD_DRAM_RON_OHM34 = 0x07;
        const uint8_t VPD_DRAM_RON_OHM40 = 0x03;
        const uint8_t VPD_DRAM_RON_OHM48 = 0x01;

        switch (io_value)
        {
            case VPD_DRAM_RON_INVALID:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RON_INVALID;
                break;

            case VPD_DRAM_RON_OHM34:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RON_OHM34;
                break;

            case VPD_DRAM_RON_OHM40:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RON_OHM40;
                break;

            case VPD_DRAM_RON_OHM48:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RON_OHM48;
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::CEN_MBVPD_TERM_DATA_UNSUPPORTED_VPD_ENCODE().
                            set_ATTR_ID(i_attr).
                            set_VPD_VALUE(io_value),
                            "Unsupported VPD encode for ATTR_CEN_VPD_DRAM_RON 0x%02x",
                            io_value);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief Translate vpd values to attribute enumeration for ATTR_CEN_VPD_DRAM_RTT_NOM
/// @param[in] i_attr - Attribute ID
/// @param[in, out] io_value - ENUM
/// @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,relevant error code for failure.
///
    fapi2::ReturnCode xlate_RTT_NOM (const fapi2::AttributeId i_attr,
                                     uint8_t& io_value)
    {
        const uint8_t DRAM_RTT_NOM_DISABLE = 0x00;
        const uint8_t DRAM_RTT_NOM_OHM20 = 0x04;
        const uint8_t DRAM_RTT_NOM_OHM30 = 0x05;
        const uint8_t DRAM_RTT_NOM_OHM34 = 0x07;
        const uint8_t DRAM_RTT_NOM_OHM40 = 0x03;
        const uint8_t DRAM_RTT_NOM_OHM48 = 0x85;
        const uint8_t DRAM_RTT_NOM_OHM60 = 0x01;
        const uint8_t DRAM_RTT_NOM_OHM80 = 0x06;
        const uint8_t DRAM_RTT_NOM_OHM120 = 0x02;
        const uint8_t DRAM_RTT_NOM_OHM240 = 0x84;

        switch(io_value)
        {
            case DRAM_RTT_NOM_DISABLE:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_DISABLE;
                break;

            case DRAM_RTT_NOM_OHM20:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM20;
                break;

            case DRAM_RTT_NOM_OHM30:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM30;
                break;

            case DRAM_RTT_NOM_OHM34:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM34;
                break;

            case DRAM_RTT_NOM_OHM40:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM40;
                break;

            case DRAM_RTT_NOM_OHM48:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM48;
                break;

            case DRAM_RTT_NOM_OHM60:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM60;
                break;

            case DRAM_RTT_NOM_OHM80:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM80;
                break;

            case DRAM_RTT_NOM_OHM120:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM120;
                break;

            case DRAM_RTT_NOM_OHM240:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM240;
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::CEN_MBVPD_TERM_DATA_UNSUPPORTED_VPD_ENCODE().
                            set_ATTR_ID(i_attr).
                            set_VPD_VALUE(io_value),
                            "Unsupported VPD encode for ATTR_CEN_VPD_DRAM_RTT_NOM 0x%02x",
                            io_value);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief Translate vpd values to attribute enumeration for ATTR_CEN_VPD_DRAM_RTT_PARK
/// @param[in] i_attr - Attribute ID
/// @param[in, out] io_value - ENUM
/// @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,relevant error code for failure.
///
    fapi2::ReturnCode xlate_RTT_PARK (const fapi2::AttributeId i_attr,
                                      uint8_t& io_value)
    {
        const uint8_t DRAM_RTT_PARK_DISABLE = 0x00;
        const uint8_t DRAM_RTT_PARK_OHM34 = 0x07;
        const uint8_t DRAM_RTT_PARK_OHM40 = 0x03;
        const uint8_t DRAM_RTT_PARK_OHM48 = 0x85;
        const uint8_t DRAM_RTT_PARK_OHM60 = 0x01;
        const uint8_t DRAM_RTT_PARK_OHM80 = 0x06;
        const uint8_t DRAM_RTT_PARK_OHM120 = 0x02;
        const uint8_t DRAM_RTT_PARK_OHM240 = 0x84;

        switch(io_value)
        {
            case DRAM_RTT_PARK_DISABLE:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_DISABLE;
                break;

            case DRAM_RTT_PARK_OHM34:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_34OHM;
                break;

            case DRAM_RTT_PARK_OHM40:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_40OHM;
                break;

            case DRAM_RTT_PARK_OHM48:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_48OHM;
                break;

            case DRAM_RTT_PARK_OHM60:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_60OHM;
                break;

            case DRAM_RTT_PARK_OHM80:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_80OHM;
                break;

            case DRAM_RTT_PARK_OHM120:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_120OHM;
                break;

            case DRAM_RTT_PARK_OHM240:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_240OHM;
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::CEN_MBVPD_TERM_DATA_UNSUPPORTED_VPD_ENCODE().
                            set_ATTR_ID(i_attr).
                            set_VPD_VALUE(io_value),
                            "Unsupported VPD encode for ATTR_CEN_VPD_DRAM_RTT_PARK 0x%02x",
                            io_value);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief Translate vpd values to attribute enumeration for ATTR_CEN_VPD_DRAM_RTT_WR
/// @param[in] i_attr - Attribute ID
/// @param[in, out] io_value - ENUM
/// @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,relevant error code for failure.
///
    fapi2::ReturnCode xlate_RTT_WR (const fapi2::AttributeId i_attr,
                                    uint8_t& io_value)
    {
        const uint8_t DRAM_RTT_WR_DISABLE = 0x00;
        const uint8_t DRAM_RTT_WR_OHM60   = 0x01;
        const uint8_t DRAM_RTT_WR_OHM120  = 0x02;

        switch(io_value)
        {
            case DRAM_RTT_WR_DISABLE:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_WR_DISABLE;
                break;

            case DRAM_RTT_WR_OHM60:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_WR_OHM60;
                break;

            case DRAM_RTT_WR_OHM120:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_WR_OHM120;
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::CEN_MBVPD_TERM_DATA_UNSUPPORTED_VPD_ENCODE().
                            set_ATTR_ID(i_attr).
                            set_VPD_VALUE(io_value),
                            "Unsupported VPD encode for ATTR_CEN_VPD_DRAM_RTT_WR 0x%02x",
                            io_value);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief Translate vpd values to attribute enumeration for ATTR_CEN_VPD_DRAM_WR_VREF
/// @param[in] i_attr - Attribute ID
/// @param[in, out] io_value - ENUM
/// @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,relevant error code for failure.
///
    fapi2::ReturnCode xlate_WR_VREF (const fapi2::AttributeId i_attr,
                                     uint32_t& io_value)
    {
        // The following intentionally skips 0x0a..0x0f, 0x1a..0x1f, and 0x2a..0x2f
        const uint8_t WR_VREF_VDD420 = 0x00;
        const uint8_t WR_VREF_VDD425 = 0x01;
        const uint8_t WR_VREF_VDD430 = 0x02;
        const uint8_t WR_VREF_VDD435 = 0x03;
        const uint8_t WR_VREF_VDD440 = 0x04;
        const uint8_t WR_VREF_VDD445 = 0x05;
        const uint8_t WR_VREF_VDD450 = 0x06;
        const uint8_t WR_VREF_VDD455 = 0x07;
        const uint8_t WR_VREF_VDD460 = 0x08;
        const uint8_t WR_VREF_VDD465 = 0x09;
        const uint8_t WR_VREF_VDD470 = 0x10;
        const uint8_t WR_VREF_VDD475 = 0x11;
        const uint8_t WR_VREF_VDD480 = 0x12;
        const uint8_t WR_VREF_VDD485 = 0x13;
        const uint8_t WR_VREF_VDD490 = 0x14;
        const uint8_t WR_VREF_VDD495 = 0x15;
        const uint8_t WR_VREF_VDD500 = 0x16;
        const uint8_t WR_VREF_VDD505 = 0x17;
        const uint8_t WR_VREF_VDD510 = 0x18;
        const uint8_t WR_VREF_VDD515 = 0x19;
        const uint8_t WR_VREF_VDD520 = 0x20;
        const uint8_t WR_VREF_VDD525 = 0x21;
        const uint8_t WR_VREF_VDD530 = 0x22;
        const uint8_t WR_VREF_VDD535 = 0x23;
        const uint8_t WR_VREF_VDD540 = 0x24;
        const uint8_t WR_VREF_VDD545 = 0x25;
        const uint8_t WR_VREF_VDD550 = 0x26;
        const uint8_t WR_VREF_VDD555 = 0x27;
        const uint8_t WR_VREF_VDD560 = 0x28;
        const uint8_t WR_VREF_VDD565 = 0x29;
        const uint8_t WR_VREF_VDD570 = 0x30;
        const uint8_t WR_VREF_VDD575 = 0x31;

        switch(io_value)
        {
            case WR_VREF_VDD420:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD420;
                break;

            case WR_VREF_VDD425:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD425;
                break;

            case WR_VREF_VDD430:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD430;
                break;

            case WR_VREF_VDD435:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD435;
                break;

            case WR_VREF_VDD440:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD440;
                break;

            case WR_VREF_VDD445:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD445;
                break;

            case WR_VREF_VDD450:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD450;
                break;

            case WR_VREF_VDD455:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD455;
                break;

            case WR_VREF_VDD460:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD460;
                break;

            case WR_VREF_VDD465:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD465;
                break;

            case WR_VREF_VDD470:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD470;
                break;

            case WR_VREF_VDD475:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD475;
                break;

            case WR_VREF_VDD480:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD480;
                break;

            case WR_VREF_VDD485:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD485;
                break;

            case WR_VREF_VDD490:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD490;
                break;

            case WR_VREF_VDD495:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD495;
                break;

            case WR_VREF_VDD500:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD500;
                break;

            case WR_VREF_VDD505:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD505;
                break;

            case WR_VREF_VDD510:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD510;
                break;

            case WR_VREF_VDD515:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD515;
                break;

            case WR_VREF_VDD520:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD520;
                break;

            case WR_VREF_VDD525:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD525;
                break;

            case WR_VREF_VDD530:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD530;
                break;

            case WR_VREF_VDD535:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD535;
                break;

            case WR_VREF_VDD540:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD540;
                break;

            case WR_VREF_VDD545:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD545;
                break;

            case WR_VREF_VDD550:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD550;
                break;

            case WR_VREF_VDD555:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD555;
                break;

            case WR_VREF_VDD560:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD560;
                break;

            case WR_VREF_VDD565:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD565;
                break;

            case WR_VREF_VDD570:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD570;
                break;

            case WR_VREF_VDD575:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_DRAM_WR_VREF_VDD575;
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::CEN_MBVPD_TERM_DATA_UNSUPPORTED_VPD_ENCODE().
                            set_ATTR_ID(i_attr).
                            set_VPD_VALUE(io_value),
                            "Unsupported VPD encode for ATTR_CEN_VPD_DRAM_WR_VREF 0x%08x",
                            io_value);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief Translate vpd values to attribute enumeration for ATTR_CEN_VPD_RD_VREF
/// @param[in] i_attr - Attribute ID
/// @param[in, out] io_value - ENUM
/// @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,relevant error code for failure.
///
    fapi2::ReturnCode xlate_RD_VREF (const fapi2::AttributeId i_attr,
                                     uint32_t& io_value)
    {
        const uint8_t RD_VREF_VDD61000 = 0x15;
        const uint8_t RD_VREF_VDD59625 = 0x14;
        const uint8_t RD_VREF_VDD58250 = 0x13;
        const uint8_t RD_VREF_VDD56875 = 0x12;
        const uint8_t RD_VREF_VDD55500 = 0x11;
        const uint8_t RD_VREF_VDD54125 = 0x10;
        const uint8_t RD_VREF_VDD52750 = 0x09;
        const uint8_t RD_VREF_VDD51375 = 0x08;
        const uint8_t RD_VREF_VDD50000 = 0x07;
        const uint8_t RD_VREF_VDD48625 = 0x06;
        const uint8_t RD_VREF_VDD47250 = 0x05;
        const uint8_t RD_VREF_VDD45875 = 0x04;
        const uint8_t RD_VREF_VDD44500 = 0x03;
        const uint8_t RD_VREF_VDD43125 = 0x02;
        const uint8_t RD_VREF_VDD41750 = 0x01;
        const uint8_t RD_VREF_VDD40375 = 0x00;
        const uint8_t RD_VREF_VDD81000 = 0x31;
        const uint8_t RD_VREF_VDD79625 = 0x30;
        const uint8_t RD_VREF_VDD78250 = 0x29;
        const uint8_t RD_VREF_VDD76875 = 0x28;
        const uint8_t RD_VREF_VDD75500 = 0x27;
        const uint8_t RD_VREF_VDD74125 = 0x26;
        const uint8_t RD_VREF_VDD72750 = 0x25;
        const uint8_t RD_VREF_VDD71375 = 0x24;
        const uint8_t RD_VREF_VDD70000 = 0x23;
        const uint8_t RD_VREF_VDD68625 = 0x22;
        const uint8_t RD_VREF_VDD67250 = 0x21;
        const uint8_t RD_VREF_VDD65875 = 0x20;
        const uint8_t RD_VREF_VDD64500 = 0x19;
        const uint8_t RD_VREF_VDD63125 = 0x18;
        const uint8_t RD_VREF_VDD61750 = 0x17;
        const uint8_t RD_VREF_VDD60375 = 0x16;

        switch(io_value)
        {
            case RD_VREF_VDD61000:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD61000;
                break;

            case RD_VREF_VDD59625:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD59625;
                break;

            case RD_VREF_VDD58250:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD58250;
                break;

            case RD_VREF_VDD56875:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD56875;
                break;

            case RD_VREF_VDD55500:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD55500;
                break;

            case RD_VREF_VDD54125:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD54125;
                break;

            case RD_VREF_VDD52750:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD52750;
                break;

            case RD_VREF_VDD51375:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD51375;
                break;

            case RD_VREF_VDD50000:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD50000;
                break;

            case RD_VREF_VDD48625:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD48625;
                break;

            case RD_VREF_VDD47250:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD47250;
                break;

            case RD_VREF_VDD45875:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD45875;
                break;

            case RD_VREF_VDD44500:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD44500;
                break;

            case RD_VREF_VDD43125:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD43125;
                break;

            case RD_VREF_VDD41750:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD41750;
                break;

            case RD_VREF_VDD40375:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD40375;
                break;

            case RD_VREF_VDD81000:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD81000;
                break;

            case RD_VREF_VDD79625:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD79625;
                break;

            case RD_VREF_VDD78250:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD78250;
                break;

            case RD_VREF_VDD76875:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD76875;
                break;

            case RD_VREF_VDD75500:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD75500;
                break;

            case RD_VREF_VDD74125:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD74125;
                break;

            case RD_VREF_VDD72750:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD72750;
                break;

            case RD_VREF_VDD71375:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD71375;
                break;

            case RD_VREF_VDD70000:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD70000;
                break;

            case RD_VREF_VDD68625:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD68625;
                break;

            case RD_VREF_VDD67250:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD67250;
                break;

            case RD_VREF_VDD65875:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD65875;
                break;

            case RD_VREF_VDD64500:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD64500;
                break;

            case RD_VREF_VDD63125:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD63125;
                break;

            case RD_VREF_VDD61750:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD61750;
                break;

            case RD_VREF_VDD60375:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_RD_VREF_VDD60375;
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::CEN_MBVPD_TERM_DATA_UNSUPPORTED_VPD_ENCODE().
                            set_ATTR_ID(i_attr).
                            set_VPD_VALUE(io_value),
                            "Unsupported VPD encode for ATTR_CEN_VPD_RD_VREF 0x%08x",
                            io_value);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief Translate vpd values to attribute enumeration for ATTR_CEN_VPD_SLEW_RATE*
/// @param[in] i_attr - Attribute ID
/// @param[in, out] io_value - ENUM
/// @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,relevant error code for failure.
///
    fapi2::ReturnCode xlate_SLEW_RATE (const fapi2::AttributeId i_attr,
                                       uint8_t& io_value)
    {
        const uint8_t SLEW_RATE_3V_NS = 0x03;
        const uint8_t SLEW_RATE_4V_NS = 0x04;
        const uint8_t SLEW_RATE_5V_NS = 0x05;
        const uint8_t SLEW_RATE_6V_NS = 0x06;
        const uint8_t SLEW_RATE_MAXV_NS = 0x0F;

//  Ensure that the enums are equal so that one routine can be shared
        checkConstantsMatch<(uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_3V_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_ADDR_SLEW_3V_NS>();
        checkConstantsMatch<(uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_3V_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_CLK_SLEW_3V_NS>();
        checkConstantsMatch<(uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_3V_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_SPCKE_SLEW_3V_NS>();
        checkConstantsMatch<(uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_3V_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_CNTL_SLEW_3V_NS>();

        checkConstantsMatch<(uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_4V_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_ADDR_SLEW_4V_NS>();
        checkConstantsMatch<(uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_4V_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_CLK_SLEW_4V_NS>();
        checkConstantsMatch<(uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_4V_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_SPCKE_SLEW_4V_NS>();
        checkConstantsMatch<(uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_4V_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_CNTL_SLEW_4V_NS>();

        checkConstantsMatch<(uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_5V_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_ADDR_SLEW_5V_NS>();
        checkConstantsMatch<(uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_5V_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_CLK_SLEW_5V_NS>();
        checkConstantsMatch<(uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_5V_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_SPCKE_SLEW_5V_NS>();
        checkConstantsMatch<(uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_5V_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_CNTL_SLEW_5V_NS>();

        checkConstantsMatch<(uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_6V_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_ADDR_SLEW_6V_NS>();
        checkConstantsMatch<(uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_6V_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_CLK_SLEW_6V_NS>();
        checkConstantsMatch<(uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_6V_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_SPCKE_SLEW_6V_NS>();
        checkConstantsMatch<(uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_6V_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_CNTL_SLEW_6V_NS>();

        checkConstantsMatch <
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_MAXV_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_ADDR_SLEW_MAXV_NS > ();
        checkConstantsMatch <
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_MAXV_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_CLK_SLEW_MAXV_NS > ();
        checkConstantsMatch <
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_MAXV_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_SPCKE_SLEW_MAXV_NS > ();
        checkConstantsMatch <
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_MAXV_NS ==
        (uint8_t)ENUM_ATTR_CEN_VPD_SLEW_RATE_CNTL_SLEW_MAXV_NS > ();

        switch(io_value)
        {
            case SLEW_RATE_3V_NS:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_3V_NS;
                break;

            case SLEW_RATE_4V_NS:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_4V_NS;
                break;

            case SLEW_RATE_5V_NS:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_5V_NS;
                break;

            case SLEW_RATE_6V_NS:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_6V_NS;
                break;

            case SLEW_RATE_MAXV_NS:
                io_value = fapi2::ENUM_ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_SLEW_MAXV_NS;
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::CEN_MBVPD_TERM_DATA_UNSUPPORTED_VPD_ENCODE().
                            set_ATTR_ID(i_attr).
                            set_VPD_VALUE(io_value),
                            "Unsupported VPD encode for ATTR_CEN_VPD_SLEW_RATE 0x%02x",
                            io_value);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief Determine ISDIMM MR keyword to use
/// @param[in] i_mbTarget - Membuf chip target
/// @param[out] o_keyword - Keyword output
/// @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,relevant error code for failure.
///
    fapi2::ReturnCode FindMRkeyword (const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mbTarget,
                                     fapi2::MBvpdKeyword& o_keyword)
    {
        const uint8_t l_M0_KEYWORD_SIZE = 32;
        uint8_t l_m0_keyword[l_M0_KEYWORD_SIZE];
        size_t l_M0Bufsize = l_M0_KEYWORD_SIZE;
        uint8_t l_actualM0Data = 0;
        uint8_t l_index = 0;

        FAPI_TRY(getMBvpdField(fapi2::MBVPD_RECORD_SPDX,
                               MBVPD_KEYWORD_M0,
                               i_mbTarget,
                               (uint8_t*)(&l_m0_keyword),
                               l_M0Bufsize),
                 "FindMRkeyword: Read of M0 keyword failed");

        FAPI_ASSERT(l_M0_KEYWORD_SIZE <= l_M0Bufsize,
                    fapi2::CEN_MBVPD_INSUFFICIENT_VPD_RETURNED().
                    set_KEYWORD(MBVPD_KEYWORD_M0).
                    set_RETURNED_SIZE(l_M0Bufsize).
                    set_CHIP_TARGET(i_mbTarget),
                    "FindMRkeyword:"
                    " less M0 keyword returned than expected %d < %d",
                    l_M0Bufsize, l_M0_KEYWORD_SIZE);

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_ISDIMM_MBVPD_INDEX, i_mbTarget,
                               l_index), "FindMRkeyword: read of ISDIMM MBVPD Index failed");

        FAPI_ASSERT(l_M0_KEYWORD_SIZE >= l_index,
                    fapi2::CEN_MBVPD_INVALID_M0_DATA().
                    set_M0_DATA(l_index),
                    "unsupported MBVPD index : 0x%02x", l_index);

        o_keyword = MBVPD_KEYWORD_M1;

        l_actualM0Data = l_m0_keyword[l_index];

        switch (l_actualM0Data)
        {
            case 1:
                o_keyword = MBVPD_KEYWORD_M1;
                break;

            case 2:
                o_keyword = MBVPD_KEYWORD_M2;
                break;

            case 3:
                o_keyword = MBVPD_KEYWORD_M3;
                break;

            case 4:
                o_keyword = MBVPD_KEYWORD_M4;
                break;

            case 5:
                o_keyword = MBVPD_KEYWORD_M5;
                break;

            case 6:
                o_keyword = MBVPD_KEYWORD_M6;
                break;

            case 7:
                o_keyword = MBVPD_KEYWORD_M7;
                break;

            case 8:
                o_keyword = MBVPD_KEYWORD_M8;
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::CEN_MBVPD_INVALID_M0_DATA().
                            set_M0_DATA(l_actualM0Data),
                            "Incorrect M0 data : 0x%02x", l_actualM0Data);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief Determine ISDIMM MT keyword to use
/// @param[in] i_mbTarget - Membuf chip target
/// @param[in] i_mbaTarget - MBA chip target
/// @param[out] o_keyword - Keyword output
/// @param[in] i_version - VPD version
/// @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,relevant error code for failure.
///
    fapi2::ReturnCode FindMTkeyword (const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&        i_mbTarget,
                                     const fapi2::Target<fapi2::TARGET_TYPE_MBA>&        i_mbaTarget,
                                     fapi2::MBvpdKeyword& o_keyword,
                                     const VpdVersion&          i_version)
    {
        //MT keyword is located in the SPDX record,
        //and found by using ATTR_CEN_SPD_NUM_RANKS
        //T1: one dimm, rank 1  T2: one dimm, rank 2   T3: one dimm, rank 4
        //T5: two dimm, rank 1  T6: two dimm, rank 2   T8: two dimm, rank 4
        fapi2::ATTR_CEN_SPD_NUM_RANKS_Type l_spd_dimm_ranks[2][2] =
        {
            {
                fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_RX,
                fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_RX
            },
            {
                fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_RX,
                fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_RX
            }
        };
        uint8_t l_mba_port;
        uint8_t l_mba_dimm;

        auto l_target_dimm_array = i_mbaTarget.getChildren<fapi2::TARGET_TYPE_DIMM>();
        uint8_t l_dimmInvalid = 0;
        bool l_double_drop = false;
        fapi2::ATTR_CEN_SPD_NUM_RANKS_Type l_rankCopy = fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_RX;

        for(uint8_t l_dimm_index = 0; l_dimm_index < l_target_dimm_array.size();
            l_dimm_index += 1)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_PORT,
                                   l_target_dimm_array[l_dimm_index],
                                   l_mba_port),
                     "FindMTkeyword: read of ATTR_CEN_MBA_PORT failed");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_DIMM,
                                   l_target_dimm_array[l_dimm_index],
                                   l_mba_dimm),
                     "FindMTkeyword: read of ATTR_CEN_MBA_DIMM failed");

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_NUM_RANKS,
                                   l_target_dimm_array[l_dimm_index],
                                   l_spd_dimm_ranks[l_mba_port][l_mba_dimm]),
                     "FindMTkeyword: read of ATTR_CEN_SPD_NUM_RANKS failed");
        }

        /* Mismatched rank numbers between the paired ports is an error
        * that should deconfigure the parent MBA so the data for that
        * MBA should never be fetched. The same is for mismatched slot 1
        * and slot 0 on the same port
        */

        //single or double drop
        if( (l_spd_dimm_ranks[0][1] == fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_RX)
            && (l_spd_dimm_ranks[1][1] == fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_RX) )
        {
            //if the two match, it's a valid case.
            if(l_spd_dimm_ranks[0][0] == l_spd_dimm_ranks[1][0])
            {
                //0000, set to 1
                l_rankCopy = 1;
                FAPI_ASSERT(l_spd_dimm_ranks[0][0] != fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_RX,
                            fapi2::CEN_MBVPD_DIMMS_NOT_FOUND().
                            set_DIMM_P0S0(l_spd_dimm_ranks[0][0]).
                            set_DIMM_P0S1(l_spd_dimm_ranks[0][1]).
                            set_DIMM_P1S0(l_spd_dimm_ranks[1][0]).
                            set_DIMM_P1S1(l_spd_dimm_ranks[1][1]),
                            "FindMTkeyword: No dimm's found");

                //either 0101,0202,0404.
                l_rankCopy = l_spd_dimm_ranks[0][0];
            }
            else
            {
                //throwing error for invalid dimm combination
                l_dimmInvalid = 1;
            }

            //if all 4 are the same, its double ranked
        }
        else if(l_spd_dimm_ranks[0][1] == l_spd_dimm_ranks[0][0] &&
                l_spd_dimm_ranks[1][1] == l_spd_dimm_ranks[1][0] &&
                l_spd_dimm_ranks[0][1] == l_spd_dimm_ranks[1][1])
        {
            //either 1111,2222,4444
            l_rankCopy = l_spd_dimm_ranks[0][0];
            l_double_drop = true;
        }
        else
        {
            //throwing error for invalid dimm combination
            l_dimmInvalid = 1;
        }

        FAPI_ASSERT(!l_dimmInvalid,
                    fapi2::CEN_MBVPD_INVALID_DIMM_FOUND().
                    set_INVALID_DIMM_P0S0(l_spd_dimm_ranks[0][0]).
                    set_INVALID_DIMM_P0S1(l_spd_dimm_ranks[0][1]).
                    set_INVALID_DIMM_P1S0(l_spd_dimm_ranks[1][0]).
                    set_INVALID_DIMM_P1S1(l_spd_dimm_ranks[1][1]),
                    "There is an invalid combination of dimm's found");

        switch (l_rankCopy)
        {
            case fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_R1:
                if( l_double_drop )
                {
                    if(i_version == VM_01)
                    {
                        o_keyword = MBVPD_KEYWORD_PD5;
                    }
                    else
                    {
                        o_keyword = MBVPD_KEYWORD_T5;
                    }
                }
                else
                {
                    if(i_version == VM_01)
                    {
                        o_keyword = MBVPD_KEYWORD_PD1;
                    }
                    else
                    {
                        o_keyword = MBVPD_KEYWORD_T1;
                    }
                }

                break;

            case fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_R2:
                if( l_double_drop )
                {
                    if(i_version == VM_01)
                    {
                        o_keyword = MBVPD_KEYWORD_PD6;
                    }
                    else
                    {
                        o_keyword = MBVPD_KEYWORD_T6;
                    }
                }
                else
                {
                    if(i_version == VM_01)
                    {
                        o_keyword = MBVPD_KEYWORD_PDZ;
                    }
                    else
                    {
                        o_keyword = MBVPD_KEYWORD_T2;
                    }
                }

                break;

            case fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_R4:
                if( l_double_drop )
                {
                    if(i_version == VM_01)
                    {
                        o_keyword = MBVPD_KEYWORD_PD8;
                    }
                    else
                    {
                        o_keyword = MBVPD_KEYWORD_T8;
                    }
                }
                else
                {
                    if(i_version == VM_01)
                    {
                        o_keyword = MBVPD_KEYWORD_PD4;
                    }
                    else
                    {
                        o_keyword = MBVPD_KEYWORD_T4;
                    }
                }

                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::CEN_MBVPD_INVALID_MT_DATA().
                            set_RANK_NUM(l_rankCopy),
                            "Invalid dimm rank : 0x%02x", l_rankCopy);
        }


    fapi_try_exit:
        return fapi2::current_err;
    }

}   // extern "C"
