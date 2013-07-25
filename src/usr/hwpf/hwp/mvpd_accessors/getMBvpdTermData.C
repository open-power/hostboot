/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getMBvpdTermData.C $          */
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
// $Id: getMBvpdTermData.C,v 1.2 2013/06/13 13:48:46 whs Exp $
/**
 *  @file getMBvpdTermData.C
 *
 *  @brief get Termination Data from MBvpd MT keyword
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>
#include    <fapiUtil.H>
#include    <getMBvpdTermData.H>

extern "C"
{
using   namespace   fapi;

fapi::ReturnCode getMBvpdTermData(
                              const fapi::Target   &i_mbaTarget,
                              const fapi::MBvpdTermData i_attr,
                              void  * o_pVal,
                              const uint32_t i_valSize)
{
    //MT keyword layout
    //The following constants are for readibility. They need to stay in sync
    //  with the attributes and vpd layout.
    const uint8_t NUM_MBA =  2;    //There are 2 MBAs per Centaur memory buffer
    const uint8_t NUM_PORTS = 2;   //Each MBA has 2 ports
    const uint8_t NUM_DIMMS = 2;   //Each port has 2 DIMMs
    const uint8_t NUM_RANKS = 4;   //Number of ranks
    const uint8_t TERM_DATA_ATTR_SIZE = 64; //Each port has 64 bytes
                                            // for attributes
    struct port_attributes
    {
       uint8_t port_attr[TERM_DATA_ATTR_SIZE];
    };
    struct mba_attributes
    {
        port_attributes mba_port[NUM_PORTS];
    };
    struct mt_keyword
    {
        mba_attributes mb_mba[NUM_MBA];
    };
    // The actual size of the MT keyword is 255 bytes, which is one byte short
    // of the mt_keyword struct. One byte is used for the size in the vpd.
    // As long as there is at least one reserved attribute, then all will fit.
    const uint32_t MT_KEYWORD_SIZE = 255;  // keyword size

    fapi::ReturnCode l_fapirc;
    fapi::Target l_mbTarget;
    uint8_t l_pos = NUM_PORTS; //initialize to out of range value (+1)
    mt_keyword * l_pMtBuffer = NULL; // MBvpd MT keyword buffer
    uint32_t  l_MtBufsize = sizeof(mt_keyword);
    uint32_t  l_sizeCheck = 0; //invalid size

    FAPI_DBG("getMBvpdTermData: entry attr=0x%02x, size=%d ",
             i_attr,i_valSize  );

    do {
        // validate proper output variable size for the attribute
        switch (i_attr)
        {
           case TERM_DATA_DRAM_RON:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_DRAM_RON>::Type);
               break;
           case TERM_DATA_DRAM_RTT_NOM:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_DRAM_RTT_NOM>::Type);
               break;
           case TERM_DATA_DRAM_RTT_WR:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_DRAM_RTT_WR>::Type);
               break;
           case TERM_DATA_ODT_RD:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_ODT_RD>::Type);
               break;
           case TERM_DATA_ODT_WR:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_ODT_WR>::Type);
               break;
           case TERM_DATA_CEN_RD_VREF:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_CEN_RD_VREF>::Type);
               break;
           case TERM_DATA_DRAM_WR_VREF:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_DRAM_WR_VREF>::Type);
               break;
           case TERM_DATA_DRAM_WRDDR4_VREF:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_DRAM_WRDDR4_VREF>::Type);
               break;
           case TERM_DATA_CEN_RCV_IMP_DQ_DQS:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_CEN_RCV_IMP_DQ_DQS>::Type);
               break;
           case TERM_DATA_CEN_DRV_IMP_DQ_DQS:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_CEN_DRV_IMP_DQ_DQS>::Type);
               break;
           case TERM_DATA_CEN_DRV_IMP_CNTL:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_CEN_DRV_IMP_CNTL>::Type);
               break;
           case TERM_DATA_CEN_DRV_IMP_ADDR:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_CEN_DRV_IMP_ADDR>::Type);
               break;
           case TERM_DATA_CEN_DRV_IMP_CLK:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_CEN_DRV_IMP_CLK>::Type);
               break;
           case TERM_DATA_CEN_DRV_IMP_SPCKE:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_CEN_DRV_IMP_SPCKE>::Type);
               break;
           case TERM_DATA_CEN_SLEW_RATE_DQ_DQS:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_CEN_SLEW_RATE_DQ_DQS>::Type);
               break;
           case TERM_DATA_CEN_SLEW_RATE_CNTL:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_CEN_SLEW_RATE_CNTL>::Type);
               break;
           case TERM_DATA_CEN_SLEW_RATE_ADDR:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_CEN_SLEW_RATE_ADDR>::Type);
               break;
           case TERM_DATA_CEN_SLEW_RATE_CLK:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_CEN_SLEW_RATE_CLK>::Type);
               break;
           case TERM_DATA_CEN_SLEW_RATE_SPCKE:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_CEN_SLEW_RATE_SPCKE>::Type);
               break;
           default: // Hard to do, but needs to be caught
               FAPI_ERR("getMBvpdTermData: invalid attribute ID 0x%02x",
                       i_attr);
               const fapi::MBvpdTermData & ATTR_ID = i_attr;
               FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_INVALID_ATTRIBUTE_ID);
               break;  //  break out with fapirc
        }
        if (l_fapirc)
        {
            break;  //  break out with fapirc
        }
        if (l_sizeCheck != i_valSize)
        {
            FAPI_ERR("getMBvpdTermData:"
                     " output variable size does not match expected %d != %d",
                       l_sizeCheck, i_valSize);
            const uint32_t & EXPECTED_SIZE = l_sizeCheck;
            const uint32_t & PASSED_SIZE = i_valSize;
            FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_INVALID_OUTPUT_VARIABLE_SIZE);
            break;  //  break out with fapirc
        }

        // find the position of the passed mba on the centuar
        l_fapirc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS,&i_mbaTarget,l_pos);
        if (l_fapirc)
        {
            FAPI_ERR(" getMBvpdTermData: Get MBA position failed ");
            break;  //  break out with fapirc
        }
        FAPI_DBG("getMBvpdTermData: mba %s position=%d",
             i_mbaTarget.toEcmdString(),
             l_pos);

        // find the Centaur memmory buffer from the passed MBA
        l_fapirc = fapiGetParentChip (i_mbaTarget,l_mbTarget);
        if (l_fapirc)
        {
            FAPI_ERR("getMBvpdTermData: Finding the parent mb failed ");
            break;  //  break out with fapirc
        }
        FAPI_DBG("getMBvpdTermData: parent path=%s ",
             l_mbTarget.toEcmdString()  );

        // Read the MT keyword field
        l_pMtBuffer = new mt_keyword;

        l_fapirc = fapiGetMBvpdField(fapi::MBVPD_RECORD_VSPD,
                                     fapi::MBVPD_KEYWORD_MT,
                                     l_mbTarget,
                                     reinterpret_cast<uint8_t *>(l_pMtBuffer),
                                     l_MtBufsize);
        if (l_fapirc)
        {
            FAPI_ERR("getMBvpdTermData: Read of MT keyword failed");
            break;  //  break out with fapirc
        }

        // Check that sufficient MT was returned.
        if (l_MtBufsize < MT_KEYWORD_SIZE )
        {
            FAPI_ERR("getMBvpdTermData:"
                     " less MT keyword returned than expected %d < %d",
                       l_MtBufsize, MT_KEYWORD_SIZE);
            const uint32_t & KEYWORD = fapi::MBVPD_KEYWORD_MT;
            const uint32_t & RETURNED_SIZE = l_MtBufsize;
            FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_INSUFFICIENT_VPD_RETURNED );
            break;  //  break out with fapirc
        }

        // return data according to the attribute varible type
        // The value of the attribute is used as an index into the MT buffer
        switch (i_attr)
        {
            // return the uint8_t [2][2] attributes from the MT keyword buffer
            case TERM_DATA_DRAM_RON:
            {
                uint8_t (* l_pVal)[2][2] = (uint8_t (*)[2][2])o_pVal;
                for (uint8_t l_port=0; l_port<NUM_PORTS;l_port++)
                {
                    for (uint8_t l_j=0; l_j<NUM_DIMMS; l_j++)
                    {
                        (*l_pVal)[l_port][l_j] = l_pMtBuffer->
                           mb_mba[l_pos].mba_port[l_port].port_attr[i_attr+l_j];
                    }
               }
               break;
            }
            // return the uint8_t [2][2][4] attributes from the MT keyword
            case TERM_DATA_DRAM_RTT_NOM:
            case TERM_DATA_DRAM_RTT_WR:
            case TERM_DATA_ODT_RD:
            case TERM_DATA_ODT_WR:
            {
                uint8_t (* l_pVal)[2][2][4] = (uint8_t (*)[2][2][4])o_pVal;
                for (uint8_t l_port=0; l_port<NUM_PORTS;l_port++)
                {
                    for (uint8_t l_j=0; l_j<NUM_DIMMS; l_j++)
                    {
                        for (uint8_t l_k=0; l_k<NUM_RANKS; l_k++)
                        {
                            (*l_pVal)[l_port][l_j][l_k] = l_pMtBuffer->
           mb_mba[l_pos].mba_port[l_port].port_attr[i_attr+(l_j*NUM_RANKS)+l_k];
                        }
                    }
               }
               break;
            }
            // return the uint32_t [2] attributes from the MT keyword buffer
            // need to consider endian since they are word fields
            case TERM_DATA_CEN_RD_VREF:
            case TERM_DATA_DRAM_WR_VREF:
            {
                uint32_t (* l_pVal)[2] = (uint32_t (*)[2])o_pVal;
                for (uint8_t l_port=0; l_port<2;l_port++)
                {
                    uint32_t * l_pWord =  (uint32_t *)&l_pMtBuffer->
                         mb_mba[l_pos].mba_port[l_port].port_attr[i_attr];
                    (*l_pVal)[l_port] = FAPI_BE32TOH(*l_pWord);
                }
                break;
            }
            // return the uint8_t [2] attributes from the MT keyword buffer
            case TERM_DATA_DRAM_WRDDR4_VREF:
            case TERM_DATA_CEN_RCV_IMP_DQ_DQS:
            case TERM_DATA_CEN_DRV_IMP_DQ_DQS:
            case TERM_DATA_CEN_DRV_IMP_CNTL:
            case TERM_DATA_CEN_DRV_IMP_ADDR:
            case TERM_DATA_CEN_DRV_IMP_CLK:
            case TERM_DATA_CEN_DRV_IMP_SPCKE:
            case TERM_DATA_CEN_SLEW_RATE_DQ_DQS:
            case TERM_DATA_CEN_SLEW_RATE_CNTL:
            case TERM_DATA_CEN_SLEW_RATE_ADDR:
            case TERM_DATA_CEN_SLEW_RATE_CLK:
            case TERM_DATA_CEN_SLEW_RATE_SPCKE:
            {
                uint8_t (* l_pVal)[2] = (uint8_t (*)[2])o_pVal;
                for (uint8_t l_port=0; l_port<NUM_PORTS;l_port++)
                {
                    (*l_pVal)[l_port] = l_pMtBuffer->
                        mb_mba[l_pos].mba_port[l_port].port_attr[i_attr];
                }
                break;
            }
        }


    } while (0);

    delete l_pMtBuffer;
    l_pMtBuffer = NULL;

    FAPI_DBG("getMBvpdTermData: exit rc=0x%08x)",
               static_cast<uint32_t>(l_fapirc));

    return  l_fapirc;
}

}   // extern "C"
