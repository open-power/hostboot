/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getMBvpdSensorMap.C $         */
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
// $Id: getMBvpdSensorMap.C,v 1.2 2014/02/12 22:11:52 mjjones Exp $

/**
 * @file getMBvpdSensorMap.C
 *
 * @brief Return primary and secondary sensor map from cvpd record VSPD
 *        keyword MW for attributes:
 *
 *        ATTR_VPD_CDIMM_SENSOR_MAP_PRIMARY
 *        ATTR_VPD_CDIMM_SENSOR_MAP_SECONDARY
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>
#include    <getMBvpdSensorMap.H>

extern "C"
{
using   namespace   fapi;

fapi::ReturnCode getMBvpdSensorMap(
                    const        fapi::Target &i_mbTarget,
                    const        fapi::MBvpdSensorMap i_attr,
                    uint8_t      &o_val)

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

    FAPI_DBG("getMBvpdSensorMap: entry ");

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
            FAPI_ERR("getMBvpdSensorMap: Read of MV keyword failed");
            break;  //  break out with fapirc
        }
        // Check that sufficient MW keyword was returned.
        if (l_MwBufsize < MW_KEYWORD_SIZE )
        {
            FAPI_ERR("getMBvpdSensorMap:"
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
           case SENSOR_MAP_PRIMARY:
               o_val = l_pMwBuffer->tempSensorPrimaryLayout;
               break;
           case SENSOR_MAP_SECONDARY:
               o_val = l_pMwBuffer->tempSensorSecondaryLayout;
               break;
           default: // Hard to do, but needs to be caught
               FAPI_ERR("getMBvpdSensorMap: invalid attribute ID 0x%02x",
                       i_attr);
               const fapi::MBvpdSensorMap & ATTR_ID = i_attr;
               FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_INVALID_ATTRIBUTE_ID);
               break;
       }

    } while (0);

    delete l_pMwBuffer;
    l_pMwBuffer = NULL;

    FAPI_DBG("getMBvpdSensorMap: exit rc=0x%08x",
               static_cast<uint32_t>(l_fapirc));

    return  l_fapirc;

}

}   // extern "C"
