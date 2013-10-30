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
// $Id: getMBvpdTermData.C,v 1.6 2013/10/31 18:03:28 whs Exp $
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
#include    <getMBvpdPhaseRotatorData.H>
#include    <getMBvpdVersion.H>

// Used to ensure attribute enums are equal at compile time
class Error_ConstantsDoNotMatch;
template<const bool MATCH> void checkConstantsMatch()
{
    Error_ConstantsDoNotMatch();
}
template <> inline void checkConstantsMatch<true>() {}

extern "C"
{
using   namespace   fapi;

// local procedures
fapi::ReturnCode translate_DRAM_RON (const fapi::MBvpdTermData i_attr,
                              uint8_t & io_value);
fapi::ReturnCode translate_DRAM_RTT_NOM (const fapi::MBvpdTermData i_attr,
                              uint8_t & io_value);
fapi::ReturnCode translate_DRAM_RTT_WR (const fapi::MBvpdTermData i_attr,
                              uint8_t & io_value);
fapi::ReturnCode translate_DRAM_WR_VREF (const fapi::MBvpdTermData i_attr,
                              uint32_t & io_value);
fapi::ReturnCode translate_CEN_RD_VREF (const fapi::MBvpdTermData i_attr,
                              uint32_t & io_value);
fapi::ReturnCode translate_SLEW_RATE (const fapi::MBvpdTermData i_attr,
                              uint8_t & io_value);

// ----------------------------------------------------------------------------
// HWP accessor to get Termination Data for MBvpd MT keyword
// ----------------------------------------------------------------------------
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
    // Mask off to isolate vpd offset. MBvpdTermData value is offset into vpd.
    // Also protects against indexing out of bounds
    uint8_t   l_attrOffset = i_attr & TERM_DATA_OFFSET_MASK;

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
           case TERM_DATA_CKE_PRI_MAP:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_CKE_PRI_MAP>::Type);
               break;
           case TERM_DATA_CKE_PWR_MAP:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_CKE_PWR_MAP>::Type);
               break;
           case TERM_DATA_RLO:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_RLO>::Type);
               break;
           case TERM_DATA_WLO:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_WLO>::Type);
               break;
           case TERM_DATA_GPO:
               l_sizeCheck=
               sizeof (MBvpdTermDataSize<TERM_DATA_GPO>::Type);
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

        // Check if the old vpd layout is different for this attr
        if (TERM_DATA_CHK60 & i_attr) // need to check vpd version for this attr
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
                FAPI_ERR("getMBvpdTermData: getMBvpdVersion failed");
                break;  //  break out with fapirc
            }
            FAPI_DBG("getMBvpdTermData: vpd version=0x%08x",
                l_vpdVersion);

            // Check if work around needed
            if (l_vpdVersion < VPD_VERSION_V60)
            {
                MBvpdPhaseRotatorData l_phaseRotAttr = PHASE_ROT_INVALID;

                if (TERM_DATA_RLO == i_attr)
                {
                    l_phaseRotAttr = PHASE_ROT_RLO_V53;
                }
                else if (TERM_DATA_WLO == i_attr)
                {
                    l_phaseRotAttr = PHASE_ROT_WLO_V53;
                }
                else if (TERM_DATA_GPO == i_attr)
                {
                    l_phaseRotAttr = PHASE_ROT_GPO_V53;
                }
                else // not expected
                {
                    FAPI_ERR("getMBvpdTermData: invalid attribute ID 0x%02x",
                       i_attr);
                    const fapi::MBvpdTermData & ATTR_ID = i_attr;
                    FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_INVALID_ATTRIBUTE_ID);
                    break;  //  break out with fapirc
                }

                // Retrieve these attributes from the MR keyword
                FAPI_EXEC_HWP(l_fapirc,
                              getMBvpdPhaseRotatorData,
                              i_mbaTarget,
                              l_phaseRotAttr,
                              *((uint8_t (*)[2])o_pVal));
                break; // break out with Phase Rotator data fapirc
            }
        }

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
            // requires translation
            case TERM_DATA_DRAM_RON:
            {
                uint8_t (* l_pVal)[2][2] = (uint8_t (*)[2][2])o_pVal;
                uint8_t l_value = 0;

                for (uint8_t l_port=0; l_port<NUM_PORTS;l_port++)
                {
                    for (uint8_t l_j=0; l_j<NUM_DIMMS; l_j++)
                    {
                        l_value = l_pMtBuffer->
                     mb_mba[l_pos].mba_port[l_port].port_attr[l_attrOffset+l_j];
                        l_fapirc = translate_DRAM_RON(i_attr,l_value);
                        if (l_fapirc)
                        {
                            break; // break with error
                        }
                        (*l_pVal)[l_port][l_j] = l_value;
                    }
                    if (l_fapirc)
                    {
                        break; // break with error
                    }
               }
               break;
            }
            // return the uint8_t [2][2][4] attributes from the MT keyword
            // requires translation
            case TERM_DATA_DRAM_RTT_NOM:
            case TERM_DATA_DRAM_RTT_WR:
            {
                uint8_t (* l_pVal)[2][2][4] = (uint8_t (*)[2][2][4])o_pVal;
                uint8_t l_value = 0;

                for (uint8_t l_port=0; l_port<NUM_PORTS;l_port++)
                {
                    for (uint8_t l_j=0; l_j<NUM_DIMMS; l_j++)
                    {
                        for (uint8_t l_k=0; l_k<NUM_RANKS; l_k++)
                        {
                            l_value = l_pMtBuffer->
     mb_mba[l_pos].mba_port[l_port].port_attr[l_attrOffset+(l_j*NUM_RANKS)+l_k];
                            if (TERM_DATA_DRAM_RTT_NOM == i_attr)
                            {
                                l_fapirc=translate_DRAM_RTT_NOM(i_attr,l_value);
                            }
                            else
                            {
                                l_fapirc=translate_DRAM_RTT_WR(i_attr,l_value);
                            }
                            if (l_fapirc)
                            {
                                break; // break with error
                            }
                            (*l_pVal)[l_port][l_j][l_k] = l_value;
                        }
                        if (l_fapirc)
                        {
                            break; // break with error
                        }
                    }
                    if (l_fapirc)
                    {
                        break; // break with error
                    }
               }
               break;
            }
            // return the uint8_t [2][2][4] attributes from the MT keyword
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
     mb_mba[l_pos].mba_port[l_port].port_attr[l_attrOffset+(l_j*NUM_RANKS)+l_k];
                        }
                    }
               }
               break;
            }
            // return the uint32_t [2] attributes from the MT keyword buffer
            // need to consider endian since they are word fields
            // requires translation
            case TERM_DATA_CEN_RD_VREF:
            case TERM_DATA_DRAM_WR_VREF:
            {
                uint32_t (* l_pVal)[2] = (uint32_t (*)[2])o_pVal;
                uint32_t l_value = 0;

                for (uint8_t l_port=0; l_port<2;l_port++)
                {
                    uint32_t * l_pWord =  (uint32_t *)&l_pMtBuffer->
                       mb_mba[l_pos].mba_port[l_port].port_attr[l_attrOffset];
                    l_value  = FAPI_BE32TOH(* l_pWord);
                    if (TERM_DATA_CEN_RD_VREF == i_attr)
                    {
                        l_fapirc=translate_CEN_RD_VREF(i_attr,l_value);
                    }
                    else
                    {
                        l_fapirc=translate_DRAM_WR_VREF(i_attr,l_value);
                    }
                    if (l_fapirc)
                    {
                        break; // break with error
                    }
                    (*l_pVal)[l_port] = l_value;
                }
                break;
            }
            // return the uint16_t [2] attributes from the MT keyword buffer
            // return the uint32_t [2] attributes from the MT keyword buffer
            // need to consider endian since they are word fields
            case TERM_DATA_CKE_PWR_MAP:
            {
                uint32_t (* l_pVal)[2] = (uint32_t (*)[2])o_pVal;
                for (uint8_t l_port=0; l_port<2;l_port++)
                {
                    uint32_t * l_pWord =  (uint32_t *)&l_pMtBuffer->
                        mb_mba[l_pos].mba_port[l_port].port_attr[l_attrOffset];
                    (*l_pVal)[l_port] = FAPI_BE32TOH(*l_pWord);
                }
                break;
            }
            // return the uint16_t [2] attributes from the MT keyword buffer
            // into the return uint32_t [2]
            // need to consider endian since they are word fields
            case TERM_DATA_CKE_PRI_MAP:
            {
                uint32_t (* l_pVal)[2] = (uint32_t (*)[2])o_pVal;
                (*l_pVal)[0] = l_pMtBuffer->
                    mb_mba[l_pos].mba_port[0].port_attr[l_attrOffset+1]; //LSB
                (*l_pVal)[0] |= (l_pMtBuffer->
                    mb_mba[l_pos].mba_port[0].port_attr[l_attrOffset]<<8); //MSB
                (*l_pVal)[1] = l_pMtBuffer->
                    mb_mba[l_pos].mba_port[1].port_attr[l_attrOffset+1]; //LSB
                (*l_pVal)[1] |= (l_pMtBuffer->
                    mb_mba[l_pos].mba_port[1].port_attr[l_attrOffset]<<8); //MSB
                break;
            }
            // return the uint8_t [2] attributes from the MT keyword buffer
            // requires translation
            case TERM_DATA_CEN_SLEW_RATE_DQ_DQS:
            case TERM_DATA_CEN_SLEW_RATE_CNTL:
            case TERM_DATA_CEN_SLEW_RATE_ADDR:
            case TERM_DATA_CEN_SLEW_RATE_CLK:
            case TERM_DATA_CEN_SLEW_RATE_SPCKE:
            {
                uint8_t (* l_pVal)[2] = (uint8_t (*)[2])o_pVal;
                uint8_t l_value = 0;

                for (uint8_t l_port=0; l_port<NUM_PORTS;l_port++)
                {
                    l_value= l_pMtBuffer->
                        mb_mba[l_pos].mba_port[l_port].port_attr[i_attr];
                    l_fapirc = translate_SLEW_RATE(i_attr,l_value);
                    if (l_fapirc)
                    {
                        break; // break with error
                    }
                    (*l_pVal)[l_port] = l_value;
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
            case TERM_DATA_RLO:
            case TERM_DATA_WLO:
            case TERM_DATA_GPO:
            {
                uint8_t (* l_pVal)[2] = (uint8_t (*)[2])o_pVal;

                // pull data from keyword buffer
                uint8_t l_port0 = l_pMtBuffer->
                        mb_mba[l_pos].mba_port[0].port_attr[l_attrOffset];
                uint8_t l_port1 = l_pMtBuffer->
                        mb_mba[l_pos].mba_port[1].port_attr[l_attrOffset];

                // isolate special processing flags
                uint32_t  l_special = i_attr & TERM_DATA_SPECIAL_MASK;
                switch (l_special)
                {
                case TERM_DATA_LOW_NIBBLE: // return low nibble
                    l_port0 = l_port0 & 0x0F;
                    l_port1 = l_port1 & 0x0F;
                    break;

                case TERM_DATA_HIGH_NIBBLE: // return high nibble
                    l_port0 = ((l_port0 & 0xF0)>>4);
                    l_port1 = ((l_port1 & 0xF0)>>4);
                    break;
                default:
                         ;      // data is ok directly from keyword buffer
                }

                (*l_pVal)[0] = l_port0;
                (*l_pVal)[1] = l_port1;
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

// ----------------------------------------------------------------------------
// Translate vpd values to attribute enumeration for ATTR_VPD_DRAM_RON
// ----------------------------------------------------------------------------
fapi::ReturnCode translate_DRAM_RON (const fapi::MBvpdTermData i_attr,
                                     uint8_t & io_value)
{
    fapi::ReturnCode l_fapirc;
    const uint8_t VPD_DRAM_RON_INVALID = 0x00;
    const uint8_t VPD_DRAM_RON_OHM34 = 0x07;
    const uint8_t VPD_DRAM_RON_OHM40 = 0x03;

    switch (io_value)
    {
    case VPD_DRAM_RON_INVALID:
        io_value=fapi::ENUM_ATTR_VPD_DRAM_RON_INVALID;
        break;
    case VPD_DRAM_RON_OHM34:
        io_value=fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34;
        break;
    case VPD_DRAM_RON_OHM40:
        io_value=fapi::ENUM_ATTR_VPD_DRAM_RON_OHM40;
        break;
    default:
        FAPI_ERR("Unsupported VPD encode for ATTR_VPD_DRAM_RON 0x%02x",
                 io_value);
        const fapi::MBvpdTermData & ATTR_ID = i_attr;
        const uint8_t  & VPD_VALUE = io_value;
        FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_TERM_DATA_UNSUPPORTED_VPD_ENCODE);
        break;
    }

    return  l_fapirc;
}

// ----------------------------------------------------------------------------
// Translate vpd values to attribute enumeration for ATTR_VPD_DRAM_RTT_NOM
// ----------------------------------------------------------------------------
fapi::ReturnCode translate_DRAM_RTT_NOM (const fapi::MBvpdTermData i_attr,
                                         uint8_t & io_value)
{
    fapi::ReturnCode l_fapirc;
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
        io_value=fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE;
        break;
    case DRAM_RTT_NOM_OHM20:
        io_value= fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM20;
        break;
    case DRAM_RTT_NOM_OHM30:
        io_value= fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30;
        break;
    case DRAM_RTT_NOM_OHM34:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM34;
        break;
    case DRAM_RTT_NOM_OHM40:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40;
        break;
    case DRAM_RTT_NOM_OHM48:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM48;
        break;
    case DRAM_RTT_NOM_OHM60:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60;
        break;
    case DRAM_RTT_NOM_OHM80:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM80;
        break;
    case DRAM_RTT_NOM_OHM120:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM120;
        break;
    case DRAM_RTT_NOM_OHM240:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM240;
        break;
    default:
        FAPI_ERR("Unsupported VPD encode for ATTR_VPD_DRAM_RTT_NOM 0x%02x",
                    io_value);
        const fapi::MBvpdTermData & ATTR_ID = i_attr;
        const uint8_t  & VPD_VALUE = io_value;
        FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_TERM_DATA_UNSUPPORTED_VPD_ENCODE);
        break;
    }

    return  l_fapirc;
}

// ----------------------------------------------------------------------------
// Translate vpd values to attribute enumeration for ATTR_VPD_DRAM_RTT_WR
// ----------------------------------------------------------------------------
fapi::ReturnCode translate_DRAM_RTT_WR (const fapi::MBvpdTermData i_attr,
                                        uint8_t & io_value)
{
    fapi::ReturnCode l_fapirc;
    const uint8_t DRAM_RTT_WR_DISABLE = 0x00;
    const uint8_t DRAM_RTT_WR_OHM60   = 0x01;
    const uint8_t DRAM_RTT_WR_OHM120  = 0x02;

    switch(io_value)
    {
    case DRAM_RTT_WR_DISABLE:
        io_value=fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE;
        break;
    case DRAM_RTT_WR_OHM60:
        io_value= fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60;
        break;
    case DRAM_RTT_WR_OHM120:
        io_value= fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120;
        break;
    default:
        FAPI_ERR("Unsupported VPD encode for ATTR_VPD_DRAM_RTT_WR 0x%02x",
                    io_value);
        const fapi::MBvpdTermData & ATTR_ID = i_attr;
        const uint8_t  & VPD_VALUE = io_value;
        FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_TERM_DATA_UNSUPPORTED_VPD_ENCODE);
        break;
    }

    return  l_fapirc;
}

// ----------------------------------------------------------------------------
// Translate vpd values to attribute enumeration for ATTR_VPD_DRAM_WR_VREF
// ----------------------------------------------------------------------------
fapi::ReturnCode translate_DRAM_WR_VREF (const fapi::MBvpdTermData i_attr,
                                         uint32_t & io_value)
{
    fapi::ReturnCode l_fapirc;
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
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD420;
        break;
    case WR_VREF_VDD425:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD425;
        break;
    case WR_VREF_VDD430:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD430;
        break;
    case WR_VREF_VDD435:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD435;
        break;
    case WR_VREF_VDD440:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD440;
        break;
    case WR_VREF_VDD445:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD445;
        break;
    case WR_VREF_VDD450:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD450;
        break;
    case WR_VREF_VDD455:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD455;
        break;
    case WR_VREF_VDD460:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD460;
        break;
    case WR_VREF_VDD465:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD465;
        break;
    case WR_VREF_VDD470:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD470;
        break;
    case WR_VREF_VDD475:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD475;
        break;
    case WR_VREF_VDD480:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD480;
        break;
    case WR_VREF_VDD485:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD485;
        break;
    case WR_VREF_VDD490:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD490;
        break;
    case WR_VREF_VDD495:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD495;
        break;
    case WR_VREF_VDD500:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500;
        break;
    case WR_VREF_VDD505:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD505;
        break;
    case WR_VREF_VDD510:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD510;
        break;
    case WR_VREF_VDD515:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD515;
        break;
    case WR_VREF_VDD520:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD520;
        break;
    case WR_VREF_VDD525:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD525;
        break;
    case WR_VREF_VDD530:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD530;
        break;
    case WR_VREF_VDD535:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD535;
        break;
    case WR_VREF_VDD540:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD540;
        break;
    case WR_VREF_VDD545:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD545;
        break;
    case WR_VREF_VDD550:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD550;
        break;
    case WR_VREF_VDD555:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD555;
        break;
    case WR_VREF_VDD560:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD560;
        break;
    case WR_VREF_VDD565:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD565;
        break;
    case WR_VREF_VDD570:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD570;
        break;
    case WR_VREF_VDD575:
        io_value = fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD575;
        break;
    default:
        FAPI_ERR("Unsupported VPD encode for ATTR_VPD_DRAM_WR_VREF 0x%08x",
                    io_value);
        const fapi::MBvpdTermData & ATTR_ID = i_attr;
        const uint32_t  & VPD_VALUE = io_value;
        FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_TERM_DATA_UNSUPPORTED_VPD_ENCODE);
        break;
    }

    return  l_fapirc;
}

// ----------------------------------------------------------------------------
// Translate vpd values to attribute enumeration for ATTR_VPD_CEN_RD_VREF
// ----------------------------------------------------------------------------
fapi::ReturnCode translate_CEN_RD_VREF (const fapi::MBvpdTermData i_attr,
                                        uint32_t & io_value)
{
    fapi::ReturnCode l_fapirc;
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
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD61000;
        break;
    case RD_VREF_VDD59625:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD59625;
        break;
    case RD_VREF_VDD58250:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD58250;
        break;
    case RD_VREF_VDD56875:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD56875;
        break;
    case RD_VREF_VDD55500:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD55500;
        break;
    case RD_VREF_VDD54125:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD54125;
        break;
    case RD_VREF_VDD52750:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD52750;
        break;
    case RD_VREF_VDD51375:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD51375;
        break;
    case RD_VREF_VDD50000:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000;
        break;
    case RD_VREF_VDD48625:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD48625;
        break;
    case RD_VREF_VDD47250:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD47250;
        break;
    case RD_VREF_VDD45875:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD45875;
        break;
    case RD_VREF_VDD44500:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD44500;
        break;
    case RD_VREF_VDD43125:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD43125;
        break;
    case RD_VREF_VDD41750:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD41750;
        break;
    case RD_VREF_VDD40375:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD40375;
        break;
    case RD_VREF_VDD81000:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD81000;
        break;
    case RD_VREF_VDD79625:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD79625;
        break;
    case RD_VREF_VDD78250:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD78250;
        break;
    case RD_VREF_VDD76875:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD76875;
        break;
    case RD_VREF_VDD75500:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD75500;
        break;
    case RD_VREF_VDD74125:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD74125;
        break;
    case RD_VREF_VDD72750:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD72750;
        break;
    case RD_VREF_VDD71375:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD71375;
        break;
    case RD_VREF_VDD70000:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD70000;
        break;
    case RD_VREF_VDD68625:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD68625;
        break;
    case RD_VREF_VDD67250:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD67250;
        break;
    case RD_VREF_VDD65875:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD65875;
        break;
    case RD_VREF_VDD64500:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD64500;
        break;
    case RD_VREF_VDD63125:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD63125;
        break;
    case RD_VREF_VDD61750:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD61750;
        break;
    case RD_VREF_VDD60375:
        io_value = fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD60375;
        break;
    default:
        FAPI_ERR("Unsupported VPD encode for ATTR_VPD_CEN_RD_VREF 0x%08x",
                    io_value);
        const fapi::MBvpdTermData & ATTR_ID = i_attr;
        const uint32_t  & VPD_VALUE = io_value;
        FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_TERM_DATA_UNSUPPORTED_VPD_ENCODE);
        break;
    }

    return  l_fapirc;
}

// ----------------------------------------------------------------------------
// Translate vpd values to attribute enumeration for
//   ATTR_VPD_CEN_SLEW_RATE_DQ_DQS
//   ATTR_VPD_CEN_SLEW_RATE_ADDR
//   ATTR_VPD_CEN_SLEW_RATE_CLK
//   ATTR_VPD_CEN_SLEW_RATE_SPCKE
//   ATTR_VPD_CEN_SLEW_RATE_CNTL
// They all have the same mapping and can share a translation procedure
// ----------------------------------------------------------------------------
fapi::ReturnCode translate_SLEW_RATE (const fapi::MBvpdTermData i_attr,
                                     uint8_t & io_value)
{
    fapi::ReturnCode l_fapirc;
    const uint8_t SLEW_RATE_3V_NS = 0x03;
    const uint8_t SLEW_RATE_4V_NS = 0x04;
    const uint8_t SLEW_RATE_5V_NS = 0x05;
    const uint8_t SLEW_RATE_6V_NS = 0x06;
    const uint8_t SLEW_RATE_MAXV_NS = 0x0F;

//  Ensure that the enums are equal so that one routine can be shared
    checkConstantsMatch<(uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_3V_NS==
                        (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS>();
    checkConstantsMatch<(uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_3V_NS==
                        (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS>();
    checkConstantsMatch<(uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_3V_NS==
                       (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS>();
    checkConstantsMatch<(uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_3V_NS==
                        (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS>();

    checkConstantsMatch<(uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS==
                        (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_4V_NS>();
    checkConstantsMatch<(uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS==
                        (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_4V_NS>();
    checkConstantsMatch<(uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS==
                       (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_4V_NS>();
    checkConstantsMatch<(uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS==
                        (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_4V_NS>();

    checkConstantsMatch<(uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_5V_NS==
                        (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_5V_NS>();
    checkConstantsMatch<(uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_5V_NS==
                        (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_5V_NS>();
    checkConstantsMatch<(uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_5V_NS==
                       (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_5V_NS>();
    checkConstantsMatch<(uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_5V_NS==
                        (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_5V_NS>();

    checkConstantsMatch<(uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_6V_NS==
                        (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_6V_NS>();
    checkConstantsMatch<(uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_6V_NS==
                        (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_6V_NS>();
    checkConstantsMatch<(uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_6V_NS==
                       (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_6V_NS>();
    checkConstantsMatch<(uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_6V_NS==
                        (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_6V_NS>();

    checkConstantsMatch<
                     (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_MAXV_NS==
                     (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_MAXV_NS>();
    checkConstantsMatch<
                     (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_MAXV_NS==
                     (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_MAXV_NS>();
    checkConstantsMatch<
                     (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_MAXV_NS==
                     (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_MAXV_NS>();
    checkConstantsMatch<
                     (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_MAXV_NS==
                     (uint8_t)ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_MAXV_NS>();

    switch(io_value)
    {
    case SLEW_RATE_3V_NS:
        io_value = fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_3V_NS;
        break;
    case SLEW_RATE_4V_NS:
        io_value = fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS;
        break;
    case SLEW_RATE_5V_NS:
        io_value = fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_5V_NS;
        break;
    case SLEW_RATE_6V_NS:
        io_value = fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_6V_NS;
        break;
    case SLEW_RATE_MAXV_NS:
        io_value = fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_MAXV_NS;
        break;
    default:
         FAPI_ERR("Unsupported VPD encode for ATTR_VPD_CEN_SLEW_RATE 0x%02x",
                    io_value);
        const fapi::MBvpdTermData & ATTR_ID = i_attr;
        const uint8_t  & VPD_VALUE = io_value;
        FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_TERM_DATA_UNSUPPORTED_VPD_ENCODE);
        break;
    }

    return  l_fapirc;
}

}   // extern "C"
