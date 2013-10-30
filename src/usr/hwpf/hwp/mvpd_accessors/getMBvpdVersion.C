/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getMBvpdVersion.C $           */
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
// $Id: getMBvpdVersion.C,v 1.1 2013/10/30 21:07:58 whs Exp $
/**
 *  @file getMBvpdVersion.C
 *
 *  @brief get the vpd version from MBvpd record VINI keyword VZ
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>
#include    <fapiUtil.H>
#include    <getMBvpdVersion.H>

extern "C"
{
using   namespace   fapi;

fapi::ReturnCode getMBvpdVersion(
                              const fapi::Target   &i_mbaTarget,
                              uint32_t  & o_val)
{
    fapi::ReturnCode l_fapirc;
    fapi::Target l_mbTarget;
    uint16_t l_vpdVersion = 0;
    uint32_t l_bufSize = sizeof(l_vpdVersion);

    FAPI_DBG("getMBvpdVersion: entry ");

    do {
        // find the Centaur memory buffer from the passed MBA
        l_fapirc = fapiGetParentChip (i_mbaTarget,l_mbTarget);
        if (l_fapirc)
        {
            FAPI_ERR("getMBvpdVersion: Finding the parent mb failed ");
            break;  //  break out with fapirc
        }
        FAPI_DBG("getMBvpdVersion: parent path=%s ",
             l_mbTarget.toEcmdString()  );

        // get vpd version from record VINI keyword VZ
        l_fapirc = fapiGetMBvpdField(fapi::MBVPD_RECORD_VINI,
                                     fapi::MBVPD_KEYWORD_VZ,
                                     l_mbTarget,
                                     reinterpret_cast<uint8_t *>(&l_vpdVersion),
                                     l_bufSize);
        if (l_fapirc)
        {
            FAPI_ERR("getMBvpdVersion: Read of VZ keyword failed");
            break;  //  break out with fapirc
        }

        // Check that sufficient size was returned.
        if (l_bufSize < sizeof(l_vpdVersion) )
        {
            FAPI_ERR("getMBvpdVersion:"
                     " less keyword data returned than expected %d < %d",
                       l_bufSize, sizeof(l_vpdVersion));
            const uint32_t & KEYWORD = sizeof(l_vpdVersion);
            const uint32_t & RETURNED_SIZE = l_bufSize;
            FAPI_SET_HWP_ERROR(l_fapirc,RC_MBVPD_INSUFFICIENT_VPD_RETURNED);
            break;  //  break out with fapirc
        }
        // return value
        o_val = static_cast<uint32_t>(FAPI_BE16TOH(l_vpdVersion));

        FAPI_DBG("getMBvpdVersion: vpd version=0x%08x",
                o_val);


    } while (0);

    FAPI_DBG("getMBvpdVersion: exit rc=0x%08x)",
               static_cast<uint32_t>(l_fapirc));

    return  l_fapirc;
}

}   // extern "C"
