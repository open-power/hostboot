/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getMBvpdAddrMirrorData.C $    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// $Id$
/**
 *  @file getMBvpdAddrMirrorData.C
 *
 *  @brief get Address Mirroring Data from MBvpd AM keyword
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>
#include    <fapiUtil.H>
#include    <getMBvpdAddrMirrorData.H>

extern "C"
{
using   namespace   fapi;

fapi::ReturnCode getMBvpdAddrMirrorData(
                              const fapi::Target   &i_mbaTarget,
                              uint8_t (& o_val)[2][2])
{
    //AM keyword layout
    //The following constants are for readibility. They need to stay in sync
    //  with the vpd layout.
    const uint8_t NUM_MBAS =  2;   //There are 2 MBAs per Centaur memory buffer
    const uint8_t NUM_PORTS = 2;   //Each MBA has 2 ports
    struct port_attributes
    {
       uint8_t dimm0 : 4 ;
       uint8_t dimm1 : 4 ;
    };
    struct mba_attributes
    {
        port_attributes mba_port[NUM_PORTS];
    };
    struct ma_keyword
    {
        mba_attributes mb_mba[NUM_MBAS];
    };
    const uint32_t AM_KEYWORD_SIZE = sizeof(ma_keyword);  // keyword size

    fapi::ReturnCode l_fapirc;
    fapi::Target l_mbTarget;
    uint8_t l_mbaPos = NUM_MBAS; //initialize to out of range value (+1)
    ma_keyword * l_pMaBuffer = NULL; // MBvpd MT keyword buffer
    uint32_t  l_MaBufsize = sizeof(ma_keyword);

    FAPI_DBG("getMBvpdAddrMirrorData: entry ");

    do {

        // find the position of the passed mba on the centuar
        l_fapirc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS,&i_mbaTarget,l_mbaPos);
        if (l_fapirc)
        {
            FAPI_ERR(" getMBvpdAddrMirrorData: Get MBA position failed ");
            break;  //  break out with fapirc
        }
        FAPI_DBG("getMBvpdAddrMirrorData: mba %s position=%d",
             i_mbaTarget.toEcmdString(),
             l_mbaPos);

        // find the Centaur memmory buffer from the passed MBA
        l_fapirc = fapiGetParentChip (i_mbaTarget,l_mbTarget);
        if (l_fapirc)
        {
            FAPI_ERR("getMBvpdAddrMirrorData: Finding the parent mb failed ");
            break;  //  break out with fapirc
        }
        FAPI_DBG("getMBvpdAddrMirrorData: parent mb path=%s ",
             l_mbTarget.toEcmdString()  );

        // Read the AM keyword field
        l_pMaBuffer = new ma_keyword;

        l_fapirc = fapiGetMBvpdField(fapi::MBVPD_RECORD_VSPD,
                                     fapi::MBVPD_KEYWORD_AM,
                                     l_mbTarget,
                                     reinterpret_cast<uint8_t *>(l_pMaBuffer),
                                     l_MaBufsize);
        if (l_fapirc)
        {
            FAPI_ERR("getMBvpdAddrMirrorData: Read of AM keyword failed");
            break;  //  break out with fapirc
        }

        // Check that sufficient AM was returned.
        if (l_MaBufsize < AM_KEYWORD_SIZE )
        {
            FAPI_ERR("getMBvpdAddrMirrorData:"
                     " less AM keyword returned than expected %d < %d",
                       l_MaBufsize, AM_KEYWORD_SIZE);
            const uint32_t & KEYWORD = fapi::MBVPD_KEYWORD_AM;
            const uint32_t & RETURNED_SIZE = l_MaBufsize;
            FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_INSUFFICIENT_VPD_RETURNED );
            break;  //  break out with fapirc
        }

        // Return the 4 bits of address mirroring data for each
        // of the 4 DIMMs for the requested mba from the AM keyword buffer
        for (uint8_t l_port=0; l_port<NUM_PORTS; l_port++)
        {
            o_val[l_port][0]= l_pMaBuffer->
                       mb_mba[l_mbaPos].mba_port[l_port].dimm0;
            o_val[l_port][1]= l_pMaBuffer->
                       mb_mba[l_mbaPos].mba_port[l_port].dimm1;
        }

    } while (0);

    delete l_pMaBuffer;
    l_pMaBuffer = NULL;

    FAPI_DBG("getMBvpdAddrMirrorData: exit rc=0x%08x",
               static_cast<uint32_t>(l_fapirc));
    return  l_fapirc;
}

}   // extern "C"
