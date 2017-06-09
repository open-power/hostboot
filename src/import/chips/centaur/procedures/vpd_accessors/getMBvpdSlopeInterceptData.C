/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getMBvpdSlopeInterceptData.C $ */
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
///  @file getMBvpdSlopeInterceptData.C
///  @brief get master and supplier power slope and intercept from MBvpd
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#include    <stdint.h>
#include <fapi2_mbvpd_access.H>
//  fapi2 support
#include    <fapi2.H>
#include    <getMBvpdSlopeInterceptData.H>

extern "C"
{

// local function to get master power slope and intercept data
    fapi2::ReturnCode getMBvpdMasterData(
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&   i_mbTarget,
        const fapi2::MBvpdSlopeIntercept i_attr,
        uint32_t& o_val);

// local function to get supplier power slope and intercept data
    fapi2::ReturnCode getMBvpdSupplierData(
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&   i_mbTarget,
        const fapi2::MBvpdSlopeIntercept i_attr,
        uint32_t& o_val);

///
/// @brief Return power slope and intercept data from cvpd record VSPD
///        keyword MW and MV
///
/// The Master power slope and intercept data is in the MW keyword.
/// The Supplier power slope and intercept data is in the MV keyword.
/// The #I keyword has the Module ID for this CDIMM. The MV keyword
///  has the supplier power slope and intercept for multiple vendors.
///  The list in MV is searched for the Module ID in the #I keyword.
///  Values for the matching vendor are returned.
///
/// @param[in]  i_mbTarget   -   membuf chip target
/// @param[in]  i_attr       -   enumerator to select requested value
/// @param[out] o_val        -   master/supplier slope/intercept value
/// @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success, relevant error code for failure.
///
    fapi2::ReturnCode getMBvpdSlopeInterceptData(
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&   i_mbTarget,
        const fapi2::MBvpdSlopeIntercept i_attr,
        uint32_t& o_val)
    {
        FAPI_DBG("getMBvpdSlopeInterceptData: entry ");

        // get master values from MW keyword or supplier values from MV keyword
        switch (i_attr)
        {
            case fapi2::MASTER_POWER_SLOPE:
            case fapi2::MASTER_POWER_INTERCEPT:
            case fapi2::MASTER_TOTAL_POWER_SLOPE:
            case fapi2::MASTER_TOTAL_POWER_INTERCEPT:
                FAPI_TRY(getMBvpdMasterData(i_mbTarget, i_attr, o_val));
                break;

            case fapi2::SUPPLIER_POWER_SLOPE:
            case fapi2::SUPPLIER_POWER_INTERCEPT:
            case fapi2::SUPPLIER_TOTAL_POWER_SLOPE:
            case fapi2::SUPPLIER_TOTAL_POWER_INTERCEPT:
                FAPI_TRY(getMBvpdSupplierData(i_mbTarget, i_attr, o_val));
                break;

            default: // Unlikely, but needs to be caught
                FAPI_ASSERT(false,
                            fapi2::CEN_MBVPD_INVALID_ATTRIBUTE_ID().
                            set_ATTR_ID(i_attr),
                            "getMBvpdSlopeInterceptData: invalid attribute ID 0x%02x",
                            i_attr);
        }

        FAPI_DBG("getMBvpdSlopeInterceptData: exit ");
    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief local function to get master power slope and intercept data
/// @param[in] i_mbTarget - reference to membuf chip target
/// @param[in] i_attr - S/I Attribute
/// @param[out] o_val
/// @return FAPI2_RC_SUCCESS if success, relevant error code for failure.
///
    fapi2::ReturnCode getMBvpdMasterData(
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&   i_mbTarget,
        const fapi2::MBvpdSlopeIntercept i_attr,
        uint32_t& o_val)
    {
        //MW keyword layout
        struct mw_keyword
        {
            uint8_t     MWKeywordVersion;
            uint8_t     masterPowerSlope_MSB;     //big endian order
            uint8_t     masterPowerSlope_LSB;
            uint8_t     masterPowerIntercept_MSB; //big endian order
            uint8_t     masterPowerIntercept_LSB;
            uint8_t     masterTotalPowerSlope_MSB;     //big endian order
            uint8_t     masterTotalPowerSlope_LSB;
            uint8_t     masterTotalPowerIntercept_MSB; //big endian order
            uint8_t     masterTotalPowerIntercept_LSB;
            uint8_t     tempSensorPrimaryLayout;
            uint8_t     tempSensorSecondaryLayout;
        };
        const uint32_t MW_KEYWORD_SIZE = sizeof(mw_keyword);  // keyword size

        mw_keyword* l_pMwBuffer = NULL;  // MBvpd MW keyword buffer
        size_t l_MwBufsize = sizeof(mw_keyword);

        FAPI_DBG("getMBvpdMasterData: entry ");

        do
        {

            l_pMwBuffer = new mw_keyword;

            // Read the MW keyword field
            FAPI_TRY(getMBvpdField(fapi2::MBVPD_RECORD_VSPD,
                                   fapi2::MBVPD_KEYWORD_MW,
                                   i_mbTarget,
                                   reinterpret_cast<uint8_t*>(l_pMwBuffer),
                                   l_MwBufsize), "getMBvpdMasterData: Read of MV keyword failed");

            // Check that sufficient MW keyword was returned.
            FAPI_ASSERT(l_MwBufsize >= MW_KEYWORD_SIZE,
                        fapi2::CEN_MBVPD_INSUFFICIENT_VPD_RETURNED().
                        set_KEYWORD(fapi2::MBVPD_KEYWORD_MW).
                        set_RETURNED_SIZE(l_MwBufsize).
                        set_CHIP_TARGET(i_mbTarget),
                        "getMBvpdMasterData:"
                        " less MW keyword returned than expected %d < %d",
                        l_MwBufsize, MW_KEYWORD_SIZE);

            // Return requested value
            switch (i_attr)
            {
                case fapi2::MASTER_POWER_SLOPE:  //get each byte to perserve endian
                    o_val = l_pMwBuffer->masterPowerSlope_LSB;
                    o_val |= (l_pMwBuffer->masterPowerSlope_MSB << 8);
                    break;

                case fapi2::MASTER_POWER_INTERCEPT:  //get each byte to perserve endian
                    o_val = l_pMwBuffer->masterPowerIntercept_LSB;
                    o_val |= (l_pMwBuffer->masterPowerIntercept_MSB << 8);
                    break;

                case fapi2::MASTER_TOTAL_POWER_SLOPE:  //get each byte to perserve endian
                    o_val = l_pMwBuffer->masterTotalPowerSlope_LSB;
                    o_val |= (l_pMwBuffer->masterTotalPowerSlope_MSB << 8);
                    break;

                case fapi2::MASTER_TOTAL_POWER_INTERCEPT:  //get each byte to perserve endian
                    o_val = l_pMwBuffer->masterTotalPowerIntercept_LSB;
                    o_val |= (l_pMwBuffer->masterTotalPowerIntercept_MSB << 8);
                    break;

                default: //i_attr value was checked before call so should not get here
                    break;
            }

        }
        while (0);

        delete l_pMwBuffer;
        l_pMwBuffer = NULL;

        FAPI_DBG("getMBvpdMasterData: exit");
    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief local function to get supplier power slope and intercept data
///
/// Read the #I keyword to get the module ID of this CDIMM
/// Then read the #MV keyword which has all the vendor supplied info
/// and search the list for the module ID found in the #I keyword
///
/// @param[in] i_mbTarget - Reference to Membuf Chip
/// @param[in] i_attr S/I attribute
/// @param[out] o_val
/// @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success, relevant error code for failure.
///
    fapi2::ReturnCode getMBvpdSupplierData(
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&   i_mbTarget,
        const fapi2::MBvpdSlopeIntercept i_attr,
        uint32_t& o_val)
    {

        //#I keyword layout
        const uint32_t  PDI_DDR3_KEYWORD_SIZE = 256;
        const uint32_t  PDI_DDR4_KEYWORD_SIZE = 384; // assumed size for DDR4
        const uint8_t   SPD_DDR3 = 0xB;
        const uint8_t   SPD_DDR4 = 0xC;
        struct pdI_keyword
        {
            union
            {
                struct // common
                {
                    uint8_t   filler1[2];
                    uint8_t   mem_type;
                } common;
                struct // DDR3 layout of #I
                {
                    uint8_t   filler1[117]; // other fields and reserved bytes
                    uint8_t   moduleID_MSB; // at offset 117. Big endian order
                    uint8_t   moduleID_LSB; // VPD data CCIN_31E1_v.5.3.ods
                    uint8_t   filler2[PDI_DDR3_KEYWORD_SIZE - 117 - 2]; //trailing space
                } ddr3;
                struct // DDR4 layout of #I
                {
                    uint8_t   filler1[350]; // other fields and reserved bytes
                    uint8_t   moduleID_MSB; // at offset 320. Big endian order
                    uint8_t   moduleID_LSB; //
                    uint8_t   filler2[PDI_DDR4_KEYWORD_SIZE - 350 - 2]; //trailing space
                } ddr4;
            } pdI;
        };

        //MV keyword layout
        struct mv_vendorInfo
        {
            uint8_t   supplierID_MSB;              // Big endian order
            uint8_t   supplierID_LSB;
            uint8_t   supplierPowerSlope_MSB;      // Big endian order
            uint8_t   supplierPowerSlope_LSB;
            uint8_t   supplierPowerIntercept_MSB;  // Big endian order
            uint8_t   supplierPowerIntercept_LSB;
            uint8_t   supplierTotalPowerSlope_MSB;      // Big endian order
            uint8_t   supplierTotalPowerSlope_LSB;
            uint8_t   supplierTotalPowerIntercept_MSB;  // Big endian order
            uint8_t   supplierTotalPowerIntercept_LSB;

        };
        struct mv_keyword //variable length. Structure is size of 1 entry.
        {
            uint8_t   version;
            uint8_t   numEntries;
            mv_vendorInfo firstVendorInfo;
            // variable number of vendor supplied entries
        };

        fapi2::ReturnCode l_fapi2rc;
        pdI_keyword*    l_pPdIBuffer = NULL;   // MBvpd #I keyword buffer
        size_t l_pdIBufsize = sizeof(pdI_keyword);
        uint8_t         l_moduleID_LSB = 0;    // module ID to look for
        uint8_t         l_moduleID_MSB = 0;
        mv_keyword*     l_pMvBuffer = NULL;    // MBvpd MV keyword buffer
        size_t l_mvBufsize = 0;       // variable length
        mv_vendorInfo* l_pVendorInfo = NULL;
        uint32_t        l_offset = 0;
        bool            l_found = false;

        do
        {

            l_pPdIBuffer = new pdI_keyword;

            // Read the #I keyword field to get the Module ID
            FAPI_TRY(getMBvpdField(fapi2::MBVPD_RECORD_VSPD,
                                   fapi2::MBVPD_KEYWORD_PDI,
                                   i_mbTarget,
                                   reinterpret_cast<uint8_t*>(l_pPdIBuffer),
                                   l_pdIBufsize), "getMBvpdSupplierData: Read of #I keyword failed");

            FAPI_DBG("getMBvpdSupplierData: #I mem type=0x%02x ",
                     l_pPdIBuffer->pdI.common.mem_type);

            // check for DDR3 or DDR4
            if (SPD_DDR3 == l_pPdIBuffer->pdI.common.mem_type )
            {
                // Check that sufficient #I was returned.
                FAPI_ASSERT(l_pdIBufsize >= PDI_DDR3_KEYWORD_SIZE,
                            fapi2::CEN_MBVPD_INSUFFICIENT_VPD_RETURNED().
                            set_KEYWORD(fapi2::MBVPD_KEYWORD_PDI).
                            set_RETURNED_SIZE(l_pdIBufsize).
                            set_CHIP_TARGET(i_mbTarget),
                            "getMBvpdSupplierData:"
                            " less DDR3 #I keyword returned than expected %d < %d",
                            l_pdIBufsize, PDI_DDR3_KEYWORD_SIZE);

                // grab module ID
                l_moduleID_LSB = l_pPdIBuffer->pdI.ddr3.moduleID_LSB;
                l_moduleID_MSB = l_pPdIBuffer->pdI.ddr3.moduleID_MSB;
            }
            else if (SPD_DDR4 == l_pPdIBuffer->pdI.common.mem_type )
            {
                // Check that sufficient #I was returned.
                FAPI_ASSERT(l_pdIBufsize >= PDI_DDR4_KEYWORD_SIZE,
                            fapi2::CEN_MBVPD_INSUFFICIENT_VPD_RETURNED().
                            set_KEYWORD(fapi2::MBVPD_KEYWORD_PDI).
                            set_RETURNED_SIZE(l_pdIBufsize).
                            set_CHIP_TARGET(i_mbTarget),
                            "getMBvpdSupplierData:"
                            " less DDR4 #I keyword returned than expected %d < %d",
                            l_pdIBufsize, PDI_DDR3_KEYWORD_SIZE);

                // grab module ID
                l_moduleID_LSB = l_pPdIBuffer->pdI.ddr4.moduleID_LSB;
                l_moduleID_MSB = l_pPdIBuffer->pdI.ddr4.moduleID_MSB;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MBVPD_UNEXPECTED_MEM_TYPE().
                            set_MEM_TYPE(l_pPdIBuffer->pdI.common.mem_type).
                            set_MEMBUF_TARGET(i_mbTarget),
                            "getMBvpdSupplierData:"
                            " unexpected memory type in #I");
            }

            // Done with #I buffer. Error paths free buffer at end.
            delete l_pPdIBuffer;
            l_pPdIBuffer = NULL;

            FAPI_DBG("getMBvpdSupplierData: #I moduleID=0x%08x ",
                     l_moduleID_LSB + (l_moduleID_MSB << 8));

            // see how big the MV keyword is as it is variable length
            FAPI_TRY(getMBvpdField(fapi2::MBVPD_RECORD_VSPD,
                                   fapi2::MBVPD_KEYWORD_MV,
                                   i_mbTarget,
                                   NULL, //pass NULL buff pointer to get size
                                   l_mvBufsize), "getMBvpdSupplierData: Read of MV keyword failed");

            // read MV keyword
            l_pMvBuffer = (mv_keyword*)new uint8_t[l_mvBufsize];

            FAPI_TRY(getMBvpdField(fapi2::MBVPD_RECORD_VSPD,
                                   fapi2::MBVPD_KEYWORD_MV,
                                   i_mbTarget,
                                   reinterpret_cast<uint8_t*>(l_pMvBuffer),
                                   l_mvBufsize), "getMBvpdSupplierData: Read of MV keyword failed");

            // Check that sufficient MV was returned to get at least the count.
            l_pVendorInfo = &(l_pMvBuffer->firstVendorInfo);
            l_offset = (uint8_t*)l_pVendorInfo - (uint8_t*)l_pMvBuffer;

            FAPI_ASSERT(l_mvBufsize >= l_offset,
                        fapi2::CEN_MBVPD_INSUFFICIENT_VPD_RETURNED().
                        set_KEYWORD(fapi2::MBVPD_KEYWORD_MV).
                        set_RETURNED_SIZE(l_mvBufsize).
                        set_CHIP_TARGET(i_mbTarget),
                        "getMBvpdSupplierData:"
                        " less MV keyword returned than expected %d < %d",
                        l_mvBufsize, l_offset);

            // look for matching module ID
            for (uint32_t l_count = 0; l_count < l_pMvBuffer->numEntries; l_count++)
            {
                // shouldn't run past end of buffer, checking to be sure
                if (l_offset + sizeof (mv_vendorInfo) > l_mvBufsize)
                {
                    break;
                }

                FAPI_DBG("getMBvpdSupplierData: cnt=%d this supplier ID= 0x%08x ",
                         l_count,
                         l_pVendorInfo->supplierID_LSB + (l_pVendorInfo->supplierID_MSB << 8));

                if ((l_pVendorInfo->supplierID_LSB == l_moduleID_LSB ) &&
                    (l_pVendorInfo->supplierID_MSB == l_moduleID_MSB ))
                {
                    l_found = true;
                    break;
                }

                l_offset += sizeof (mv_vendorInfo);
                l_pVendorInfo++;
            }

            // Return requested value if found
            if ( l_found )
            {
                switch (i_attr)
                {
                    case fapi2::SUPPLIER_POWER_SLOPE:  //get each byte to perserve endian
                        o_val = l_pVendorInfo->supplierPowerSlope_LSB;
                        o_val |= (l_pVendorInfo->supplierPowerSlope_MSB << 8);
                        break;

                    case fapi2::SUPPLIER_POWER_INTERCEPT: //get each byte to perserve endian
                        o_val = l_pVendorInfo->supplierPowerIntercept_LSB;
                        o_val |= (l_pVendorInfo->supplierPowerIntercept_MSB << 8);
                        break;

                    case fapi2::SUPPLIER_TOTAL_POWER_SLOPE:  //get each byte to perserve endian
                        o_val = l_pVendorInfo->supplierTotalPowerSlope_LSB;
                        o_val |= (l_pVendorInfo->supplierTotalPowerSlope_MSB << 8);
                        break;

                    case fapi2::SUPPLIER_TOTAL_POWER_INTERCEPT: //get each byte to perserve endian
                        o_val = l_pVendorInfo->supplierTotalPowerIntercept_LSB;
                        o_val |= (l_pVendorInfo->supplierTotalPowerIntercept_MSB << 8);
                        break;

                    default: //i_attr value was checked already so should not get here
                        break;
                }
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MBVPD_SUPPLIER_ID_NOT_IN_MV_VPD().
                            set_MODULE_ID( l_moduleID_LSB + (l_moduleID_MSB << 8)).
                            set_MEMBUF_TARGET(i_mbTarget),
                            "getMBvpdSupplierData:"
                            " supplier ID not found 0x%04x",
                            l_moduleID_LSB + (l_moduleID_MSB << 8));
            }

        }
        while (0);

        delete l_pPdIBuffer;
        l_pPdIBuffer = NULL;
        delete l_pMvBuffer;
        l_pMvBuffer = NULL;

        FAPI_DBG("getMBvpdSupplierData: exit");

    fapi_try_exit:
        return fapi2::current_err;
    }


}   // extern "C"
