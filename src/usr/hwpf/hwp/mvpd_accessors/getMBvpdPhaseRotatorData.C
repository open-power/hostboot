/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getMBvpdPhaseRotatorData.C $  */
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
// $Id: getMBvpdPhaseRotatorData.C,v 1.4 2013/06/12 21:12:49 whs Exp $
/**
 *  @file getMBvpdPhaseRotatorData.C
 *
 *  @brief get Phase Rotator Data from MBvpd MR keyword
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>
#include    <getMBvpdPhaseRotatorData.H>

extern "C"
{
using   namespace   fapi;

fapi::ReturnCode getMBvpdPhaseRotatorData(
                    const        fapi::Target &i_mbaTarget,
                    const        fapi::MBvpdPhaseRotatorData i_attr,
                    uint8_t      (&o_val)[2])

{

    //MR keyword layout
    const uint8_t NUM_MBA =  2;    //There are 2 MBAs per Centaur memory buffer
    const uint8_t NUM_PORTS = 2;   //Each MBA has 2 ports
    const uint8_t PHASE_ROTATOR_ATTR_SIZE = 64; //Each port has 64 bytes
                                                // for attributes
    struct port_attributes
    {
       uint8_t port_attr[PHASE_ROTATOR_ATTR_SIZE];
    };
    struct mba_attributes
    {
        port_attributes mba_port[NUM_PORTS];
    };
    struct mr_keyword
    {
        mba_attributes mb_mba[NUM_MBA];
    };
    // The actual size of the MR keword is 255 bytes, which is one byte short
    // of the mr_keyword struct. One byte is used for the size in the vpd.
    // As long as there is at least one reserved attribute, then all will fit.
    const uint32_t MR_KEYWORD_SIZE = 255;  // keyword size

    fapi::ReturnCode l_fapirc;
    fapi::Target l_mbTarget;
    uint8_t l_pos = NUM_PORTS; //initialize to out of range value (+1)
    mr_keyword * l_pMrBuffer = NULL; // MBvpd MR keyword buffer
    uint32_t  l_MrBufsize = sizeof(mr_keyword);

    FAPI_DBG("getMBvpdPhaseRotatorData: entry attr=0x%02x ",
             i_attr  );

    do {
        // find the position of the passed mba on the centuar
        l_fapirc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS,&i_mbaTarget,l_pos);
        if (l_fapirc)
        {
            FAPI_ERR(" getMBvpdPhaseRotatorData: Get MBA position failed ");
            break;  //  break out with fapirc
        }
        FAPI_DBG("getMBvpdPhaseRotatorData: mba %s position=%d",
             i_mbaTarget.toEcmdString(),
             l_pos);

        // find the Centaur memmory buffer from the passed MBA
        l_fapirc = fapiGetParentChip (i_mbaTarget,l_mbTarget);
        if (l_fapirc)
        {
            FAPI_ERR("getMBvpdPhaseRotatorData: Finding the parent mb failed ");
            break;  //  break out with fapirc
        }
        FAPI_DBG("getMBvpdPhaseRotatorData: parent path=%s ",
             l_mbTarget.toEcmdString()  );

        // Read the MR keyword field
        l_pMrBuffer = new mr_keyword;

        l_fapirc = fapiGetMBvpdField(fapi::MBVPD_RECORD_VSPD,
                                     fapi::MBVPD_KEYWORD_MR,
                                     l_mbTarget,
                                     reinterpret_cast<uint8_t *>(l_pMrBuffer),
                                     l_MrBufsize);
        if (l_fapirc)
        {
            FAPI_ERR("getMBvpdPhaseRotatorData: Read of MR keyword failed");
            break;  //  break out with fapirc
        }

        // Check that sufficient MR was returned.
        if (l_MrBufsize < MR_KEYWORD_SIZE )
        {
            FAPI_ERR("getMBvpdPhaseRotatorData:"
                     " less MR keyword returned than expected %d < %d",
                       l_MrBufsize, MR_KEYWORD_SIZE);
            const uint32_t & KEYWORD = fapi::MBVPD_KEYWORD_MR;
            const uint32_t & RETURNED_SIZE = l_MrBufsize;
            FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_INSUFFICIENT_VPD_RETURNED );
            break;  //  break out with fapirc
        }

        // return the requested attributes from the MR keyword buffer
        for (uint8_t l_port=0 ; l_port<NUM_PORTS ; l_port++)
        {
            o_val[l_port]=l_pMrBuffer->
                      mb_mba[l_pos].mba_port[l_port].port_attr[i_attr];
        }

    } while (0);

    delete l_pMrBuffer;
    l_pMrBuffer = NULL;

    FAPI_DBG("getMBvpdPhaseRotatorData: exit rc=0x%08x (0x%02x,0x%02x)",
               static_cast<uint32_t>(l_fapirc),
               o_val[0],o_val[1] );

    return  l_fapirc;
}

}   // extern "C"
