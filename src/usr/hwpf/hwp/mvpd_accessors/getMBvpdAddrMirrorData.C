/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getMBvpdAddrMirrorData.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: getMBvpdAddrMirrorData.C,v 1.4 2014/02/12 22:11:32 mjjones Exp $
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
       uint8_t iv_dimm ; // bits 0:3 DIMM 0 bits 4:7 DIMM 1
    };
    struct mba_attributes
    {
        port_attributes mba_port[NUM_PORTS];
    };
    struct am_keyword
    {
        mba_attributes mb_mba[NUM_MBAS];
        uint8_t        spare[8]; //VPD data CCIN_31E1_v.5.3.ods
    };
    const uint32_t AM_KEYWORD_SIZE = sizeof(am_keyword);  // keyword size

    fapi::ReturnCode l_fapirc;
    fapi::Target l_mbTarget;
    uint8_t l_mbaPos = NUM_MBAS; //initialize to out of range value (+1)
    am_keyword * l_pMaBuffer = NULL; // MBvpd MT keyword buffer
    uint32_t  l_MaBufsize = sizeof(am_keyword);

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
        l_pMaBuffer = new am_keyword;

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
            const fapi::Target & CHIP_TARGET = l_mbTarget;
            FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_INSUFFICIENT_VPD_RETURNED );
            break;  //  break out with fapirc
        }

        // Return the 4 bits of address mirroring data for each
        // of the 4 DIMMs for the requested mba from the AM keyword buffer
        for (uint8_t l_port=0; l_port<NUM_PORTS; l_port++)
        {
            uint8_t l_dimm = l_pMaBuffer->
                                mb_mba[l_mbaPos].mba_port[l_port].iv_dimm;
            o_val[l_port][0]= ((l_dimm & 0xF0)>>4);
            o_val[l_port][1]= l_dimm & 0x0F;
        }

    } while (0);

    delete l_pMaBuffer;
    l_pMaBuffer = NULL;

    FAPI_DBG("getMBvpdAddrMirrorData: exit rc=0x%08x",
               static_cast<uint32_t>(l_fapirc));
    return  l_fapirc;
}

}   // extern "C"
