/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getMBvpdPhaseRotatorData.C $  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: getMBvpdPhaseRotatorData.C,v 1.7 2014/01/11 13:35:43 whs Exp $
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
#include    <getMBvpdVersion.H>

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
    // Mask off to isolate vpd offset. MBvpdPhaseRatorData value is the offset
    // into vpd. Also protects against indexing out of bounds.
    uint8_t   l_attrOffset = i_attr & PHASE_ROT_OFFSET_MASK;
    uint32_t  l_special = i_attr & PHASE_ROT_SPECIAL_MASK; // mask off to
                                // isolate special processing flags
    FAPI_DBG("getMBvpdPhaseRotatorData: entry attr=0x%04x ",
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

        // Check if the old vpd layout is different for this attr
        if (PHASE_ROT_CHK60 & i_attr) // need to check vpd version for this attr
        {
            uint32_t l_vpdVersion = 0;
            const uint32_t VPD_VERSION_V60=0x3130; // Version 6.0 is ascii "10"

            // get vpd version
            FAPI_EXEC_HWP(l_fapirc,
                          getMBvpdVersion,
                          i_mbaTarget,
                          l_vpdVersion);
            if (l_fapirc)
            {
                FAPI_ERR("getMBvpdPhaseRotatorData: getMBvpdVersion failed");
                break;  //  break out with fapirc
            }

            FAPI_DBG("getMBvpdPhaseRotatorData: vpd version=0x%08x",
                l_vpdVersion);

            // Check if work around needed
            if (l_vpdVersion < VPD_VERSION_V60)
            {
                // use the v5.3 offsets and special processing
                if (PHASE_ROT_TSYS_ADR == i_attr)
                {
                    l_attrOffset=PHASE_ROT_TSYS_ADR_V53 & PHASE_ROT_OFFSET_MASK;
                    l_special=PHASE_ROT_TSYS_ADR_V53 & PHASE_ROT_SPECIAL_MASK;
                }
                else if (PHASE_ROT_TSYS_DP18 == i_attr)
                {
                    l_attrOffset=PHASE_ROT_TSYS_DP18_V53 &
                        PHASE_ROT_OFFSET_MASK;
                    l_special=PHASE_ROT_TSYS_DP18_V53 & PHASE_ROT_SPECIAL_MASK;
                }
            }
        }

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

        // pull data from MR keyword buffer
        uint8_t l_port0=
                l_pMrBuffer->mb_mba[l_pos].mba_port[0].port_attr[l_attrOffset];
        uint8_t l_port1=
                l_pMrBuffer->mb_mba[l_pos].mba_port[1].port_attr[l_attrOffset];
        switch (l_special)
        {
            case PHASE_ROT_LOW_NIBBLE: // return low nibble
                l_port0 = l_port0 & 0x0F;
                l_port1 = l_port1 & 0x0F;
                break;

            case PHASE_ROT_HIGH_NIBBLE: // return high nibble
                l_port0 = ((l_port0 & 0xF0)>>4);
                l_port1 = ((l_port1 & 0xF0)>>4);
                break;

            case PHASE_ROT_PORT00: // return port 0 for both ports 0 and 1
                l_port1=l_port0;
                break;

            case PHASE_ROT_PORT11:// return port 1 for both ports 0 and 1
                l_port0=l_port1;
                break;

            default:
                 ;      // data is ok directly from MR keyword buffer
        }

        // return the requested attributes from the MR keyword buffer
        o_val[0]=l_port0;
        o_val[1]=l_port1;

    } while (0);

    delete l_pMrBuffer;
    l_pMrBuffer = NULL;

    FAPI_DBG("getMBvpdPhaseRotatorData: exit rc=0x%08x (0x%02x,0x%02x)",
               static_cast<uint32_t>(l_fapirc),
               o_val[0],o_val[1] );

    return  l_fapirc;
}

}   // extern "C"
