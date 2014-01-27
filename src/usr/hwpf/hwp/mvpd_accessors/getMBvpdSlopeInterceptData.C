/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getMBvpdSlopeInterceptData.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: getMBvpdSlopeInterceptData.C,v 1.4 2014/02/12 22:12:00 mjjones Exp $
/**
 *  @file getMBvpdSlopeInterceptData.C
 *
 *  @brief get master and supplier power slope and intercept data
 *         from MBvpd MV and MW keywords
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>
#include    <getMBvpdSlopeInterceptData.H>

extern "C"
{
using namespace fapi;

// local function to get master power slope and intercept data
fapi::ReturnCode getMBvpdMasterData(
                              const fapi::Target   &i_mbTarget,
                              const fapi::MBvpdSlopeIntercept i_attr,
                              uint32_t & o_val);

// local function to get supplier power slope and intercept data
fapi::ReturnCode getMBvpdSupplierData(
                              const fapi::Target   &i_mbTarget,
                              const fapi::MBvpdSlopeIntercept i_attr,
                              uint32_t & o_val);

/**
 * @brief get power slope and intercept data from cvpd record VSPD
 *        keyword MW and MV
 * @param[in]  i_mbTarget   -   mb target
 * @param[in]  i_attr       -   enumerator to select requested value
 * @param[out] o_val        -   master/supplier slope/intercept value
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */

fapi::ReturnCode getMBvpdSlopeInterceptData(
                              const fapi::Target   &i_mbTarget,
                              const fapi::MBvpdSlopeIntercept i_attr,
                              uint32_t & o_val)
{
    fapi::ReturnCode l_fapirc;

    FAPI_DBG("getMBvpdSlopeInterceptData: entry ");

    // get master values from MW keyword or supplier values from MV keyword
    switch (i_attr)
    {
       case MASTER_POWER_SLOPE:
       case MASTER_POWER_INTERCEPT:
           l_fapirc = getMBvpdMasterData(i_mbTarget, i_attr, o_val);
           break;
       case SUPPLIER_POWER_SLOPE:
       case SUPPLIER_POWER_INTERCEPT:
           l_fapirc = getMBvpdSupplierData(i_mbTarget, i_attr, o_val);
           break;
       default: // Unlikely, but needs to be caught
           FAPI_ERR("getMBvpdSlopeInterceptData: invalid attribute ID 0x%02x",
                       i_attr);
           const fapi::MBvpdSlopeIntercept & ATTR_ID = i_attr;
           FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_INVALID_ATTRIBUTE_ID);
    }

    FAPI_DBG("getMBvpdSlopeInterceptData: exit rc=0x%08x",
               static_cast<uint32_t>(l_fapirc));
    return  l_fapirc;
}

// local function to get master power slope and intercept data
//
// the master power slope and intercept are in the MW keyword
//
fapi::ReturnCode getMBvpdMasterData(
                              const fapi::Target   &i_mbTarget,
                              const fapi::MBvpdSlopeIntercept i_attr,
                              uint32_t & o_val)
{
    fapi::ReturnCode l_fapirc;

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

    mw_keyword * l_pMwBuffer = NULL; // MBvpd MW keyword buffer
    uint32_t  l_MwBufsize = sizeof(mw_keyword);

    FAPI_DBG("getMBvpdMasterData: entry ");

    do {

        l_pMwBuffer = new mw_keyword;

        // Read the MW keyword field
        l_fapirc = fapiGetMBvpdField(fapi::MBVPD_RECORD_VSPD,
                                     fapi::MBVPD_KEYWORD_MW,
                                     i_mbTarget,
                                     reinterpret_cast<uint8_t *>(l_pMwBuffer),
                                     l_MwBufsize);
        if (l_fapirc)
        {
            FAPI_ERR("getMBvpdMasterData: Read of MV keyword failed");
            break;  //  break out with fapirc
        }

        // Check that sufficient MW keyword was returned.
        if (l_MwBufsize < MW_KEYWORD_SIZE )
        {
            FAPI_ERR("getMBvpdMasterData:"
                     " less MW keyword returned than expected %d < %d",
                       l_MwBufsize, MW_KEYWORD_SIZE);
            const uint32_t & KEYWORD = fapi::MBVPD_KEYWORD_MW;
            const uint32_t & RETURNED_SIZE = l_MwBufsize;
            const fapi::Target & CHIP_TARGET = i_mbTarget;
            FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_INSUFFICIENT_VPD_RETURNED );
            break;  //  break out with fapirc
        }

        // Return requested value
        switch (i_attr)
        {
           case MASTER_POWER_SLOPE:  //get each byte to perserve endian
               o_val = l_pMwBuffer->masterPowerSlope_LSB;
               o_val |= (l_pMwBuffer->masterPowerSlope_MSB << 8);
               break;
           case MASTER_POWER_INTERCEPT:  //get each byte to perserve endian
               o_val = l_pMwBuffer->masterPowerIntercept_LSB;
               o_val |= (l_pMwBuffer->masterPowerIntercept_MSB << 8);
               break;
       default: //i_attr value was checked before call so should not get here
               break;
       }

    } while (0);

    delete l_pMwBuffer;
    l_pMwBuffer = NULL;

    FAPI_DBG("getMBvpdMasterData: exit rc=0x%08x",
               static_cast<uint32_t>(l_fapirc));

    return  l_fapirc;
}

// local function to get supplier power slope and intercept data
//
// Read the #I keyword to get the module ID of this CDIMM
// Then read the #MV keyword which has all the vendor supplied info
// and search the list for the module ID found in the #I keyword
//
fapi::ReturnCode getMBvpdSupplierData(
                              const fapi::Target   &i_mbTarget,
                              const fapi::MBvpdSlopeIntercept i_attr,
                              uint32_t & o_val)
{

    //#I keyword layout
    const uint32_t  PDI_DDR3_KEYWORD_SIZE = 256;
    const uint32_t  PDI_DDR4_KEYWORD_SIZE = 512; // assumed size for DDR4
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
                uint8_t   filler2[PDI_DDR3_KEYWORD_SIZE-117-2]; //trailing space
            } ddr3;
            struct // DDR4 layout of #I
            {
                uint8_t   filler1[320]; // other fields and reserved bytes
                uint8_t   moduleID_MSB; // at offset 320. Big endian order
                uint8_t   moduleID_LSB; //
                uint8_t   filler2[PDI_DDR4_KEYWORD_SIZE-320-2]; //trailing space
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
        uint8_t   reserved[4];
    };
    struct mv_keyword //variable length. Structure is size of 1 entry.
    {
        uint8_t   version;
        uint8_t   numEntries;
        mv_vendorInfo firstVendorInfo;
       // variable number of vendor supplied entries
    };

    fapi::ReturnCode l_fapirc;
    pdI_keyword  *  l_pPdIBuffer = NULL;   // MBvpd #I keyword buffer
    uint32_t        l_pdIBufsize = sizeof(pdI_keyword);
    uint8_t         l_moduleID_LSB = 0;    // module ID to look for
    uint8_t         l_moduleID_MSB = 0;
    mv_keyword   *  l_pMvBuffer = NULL;    // MBvpd MV keyword buffer
    uint32_t        l_mvBufsize = 0;       // variable length
    mv_vendorInfo * l_pVendorInfo = NULL;
    uint32_t        l_offset = 0;
    bool            l_found = false;

    do {

        l_pPdIBuffer = new pdI_keyword;

        // Read the #I keyword field to get the Module ID
        l_fapirc = fapiGetMBvpdField(fapi::MBVPD_RECORD_VSPD,
                                     fapi::MBVPD_KEYWORD_PDI,
                                     i_mbTarget,
                                     reinterpret_cast<uint8_t *>(l_pPdIBuffer),
                                     l_pdIBufsize);
        if (l_fapirc)
        {
            FAPI_ERR("getMBvpdSupplierData: Read of pdI keyword failed");
            break;  //  break out with fapirc
        }

        FAPI_DBG("getMBvpdSupplierData: #I mem type=0x%02x ",
            l_pPdIBuffer->pdI.common.mem_type);

        // check for DDR3 or DDR4
        if (SPD_DDR3 == l_pPdIBuffer->pdI.common.mem_type )
        {
            // Check that sufficient #I was returned.
            if (l_pdIBufsize < PDI_DDR3_KEYWORD_SIZE )
            {
                FAPI_ERR("getMBvpdSupplierData:"
                         " less DDR3 #I keyword returned than expected %d < %d",
                           l_pdIBufsize, PDI_DDR3_KEYWORD_SIZE);
                const uint32_t & KEYWORD = fapi::MBVPD_KEYWORD_PDI;
                const uint32_t & RETURNED_SIZE = l_pdIBufsize;
                const fapi::Target & CHIP_TARGET = i_mbTarget;
                FAPI_SET_HWP_ERROR(l_fapirc,RC_MBVPD_INSUFFICIENT_VPD_RETURNED);
                break;  //  break out with fapirc
            }

            // grab module ID
            l_moduleID_LSB = l_pPdIBuffer->pdI.ddr3.moduleID_LSB;
            l_moduleID_MSB = l_pPdIBuffer->pdI.ddr3.moduleID_MSB;
        }
        else if (SPD_DDR4 == l_pPdIBuffer->pdI.common.mem_type )
        {
            // Check that sufficient #I was returned.
            if (l_pdIBufsize < PDI_DDR4_KEYWORD_SIZE )
            {
                FAPI_ERR("getMBvpdSupplierData:"
                         " less DDR4 #I keyword returned than expected %d < %d",
                           l_pdIBufsize, PDI_DDR4_KEYWORD_SIZE);
                const uint32_t & KEYWORD = fapi::MBVPD_KEYWORD_PDI;
                const uint32_t & RETURNED_SIZE = l_pdIBufsize;
                const fapi::Target & CHIP_TARGET = i_mbTarget;
                FAPI_SET_HWP_ERROR(l_fapirc,RC_MBVPD_INSUFFICIENT_VPD_RETURNED);
                break;  //  break out with fapirc
            }

            // grab module ID
            l_moduleID_LSB = l_pPdIBuffer->pdI.ddr4.moduleID_LSB;
            l_moduleID_MSB = l_pPdIBuffer->pdI.ddr4.moduleID_MSB;
        }
        else
        {
            FAPI_ERR("getMBvpdSupplierData:"
                     " unexpected memory type in #I");
            const uint8_t & MEM_TYPE = l_pPdIBuffer->pdI.common.mem_type;
            const fapi::Target & MEMBUF_TARGET = i_mbTarget;
            FAPI_SET_HWP_ERROR(l_fapirc,RC_MBVPD_UNEXPECTED_MEM_TYPE);
            break;  //  break out with fapirc
        }

        // Done with #I buffer. Error paths free buffer at end.
        delete l_pPdIBuffer;
        l_pPdIBuffer = NULL;

        FAPI_DBG("getMBvpdSupplierData: #I moduleID=0x%08x ",
            l_moduleID_LSB+(l_moduleID_MSB<<8));

        // see how big the MV keyword is as it is variable length
        l_fapirc = fapiGetMBvpdField(fapi::MBVPD_RECORD_VSPD,
                                     fapi::MBVPD_KEYWORD_MV,
                                     i_mbTarget,
                                     NULL, //pass NULL buff pointer to get size
                                     l_mvBufsize);
        if (l_fapirc)
        {
             FAPI_ERR("getMBvpdSupplierData: Read of MV keyword failed");
             break;  //  break out with fapirc
        }

        // read MV keyword
        l_pMvBuffer = (mv_keyword *)new uint8_t[l_mvBufsize];

        l_fapirc = fapiGetMBvpdField(fapi::MBVPD_RECORD_VSPD,
                                     fapi::MBVPD_KEYWORD_MV,
                                     i_mbTarget,
                                     reinterpret_cast<uint8_t *>(l_pMvBuffer),
                                     l_mvBufsize);
        if (l_fapirc)
        {
            FAPI_ERR("getMBvpdSupplierData: Read of MV keyword failed");
            break;  //  break out with fapirc
        }

        // Check that sufficient MV was returned to get at least the count.
        l_pVendorInfo = &(l_pMvBuffer->firstVendorInfo);
        l_offset = (uint8_t *)l_pVendorInfo - (uint8_t *)l_pMvBuffer;

        if (l_mvBufsize < l_offset )
        {
            FAPI_ERR("getMBvpdSupplierData:"
                     " less MV keyword returned than expected %d < %d",
                       l_mvBufsize, l_offset);
            const uint32_t & KEYWORD = fapi::MBVPD_KEYWORD_MV;
            const uint32_t & RETURNED_SIZE = l_mvBufsize;
            const fapi::Target & CHIP_TARGET = i_mbTarget;
            FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_INSUFFICIENT_VPD_RETURNED );
            break;  //  break out with fapirc
        }

        // look for matching module ID
        for (uint32_t l_count=0;l_count < l_pMvBuffer->numEntries;l_count++)
        {
            // shouldn't run past end of buffer, checking to be sure
            if (l_offset + sizeof (mv_vendorInfo) > l_mvBufsize)
            {
                break;
            }

            FAPI_DBG("getMBvpdSupplierData: cnt=%d this supplier ID= 0x%08x ",
              l_count,
              l_pVendorInfo->supplierID_LSB+(l_pVendorInfo->supplierID_MSB<<8));

            if ((l_pVendorInfo->supplierID_LSB == l_moduleID_LSB ) &&
                (l_pVendorInfo->supplierID_MSB == l_moduleID_MSB ))
            {
                l_found = true;
                break;
            }
            l_offset += sizeof (mv_vendorInfo);
            l_pVendorInfo++;
        }

        // If not found, see if first supplier should be used
        // and there is one (unlikely that there is not one).
        if ( ! l_found &&
             0 < l_pMvBuffer->numEntries &&
             sizeof (mv_keyword) <= l_mvBufsize)
        {
            uint8_t l_checkUseFirstSupplier = 0;
            l_fapirc = FAPI_ATTR_GET(
                       ATTR_CENTAUR_EC_USE_FIRST_SUPPLIER_FOR_INVALID_MODULE_ID,
                       &i_mbTarget,
                       l_checkUseFirstSupplier);
            if (l_fapirc)
            {
                FAPI_ERR("getMBvpdSupplierData:"
                         " get attr use first supplier failed");
                break;  //  break out with fapirc
            }
            FAPI_DBG("getMBvpdSupplierData: attr use first supplier = 0x%02x",
                      l_checkUseFirstSupplier);
            if ( l_checkUseFirstSupplier)
            {
                l_pVendorInfo = &(l_pMvBuffer->firstVendorInfo);
                l_found = true;
            }
        }

        // Return requested value if found
        if ( l_found )
        {
            switch (i_attr)
            {
               case SUPPLIER_POWER_SLOPE:  //get each byte to perserve endian
                   o_val = l_pVendorInfo->supplierPowerSlope_LSB;
                   o_val |= (l_pVendorInfo->supplierPowerSlope_MSB << 8);
                   break;
               case SUPPLIER_POWER_INTERCEPT: //get each byte to perserve endian
                   o_val = l_pVendorInfo->supplierPowerIntercept_LSB;
                   o_val |= (l_pVendorInfo->supplierPowerIntercept_MSB << 8);
                   break;
           default: //i_attr value was checked already so should not get here
                   break;
            }
       }
       else
       {
           FAPI_ERR("getMBvpdSupplierData:"
                    " supplier ID not found 0x%04x",
                      l_moduleID_LSB+(l_moduleID_MSB<<8));
           const uint32_t & MODULE_ID = l_moduleID_LSB+(l_moduleID_MSB<<8);
           const fapi::Target & MEMBUF_TARGET = i_mbTarget;
           FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_SUPPLIER_ID_NOT_IN_MV_VPD );
       }

    } while (0);

    delete l_pPdIBuffer;
    l_pPdIBuffer = NULL;
    delete l_pMvBuffer;
    l_pMvBuffer = NULL;

    FAPI_DBG("getMBvpdSupplierData: exit rc=0x%08x",
               static_cast<uint32_t>(l_fapirc));

    return  l_fapirc;
}


}   // extern "C"
