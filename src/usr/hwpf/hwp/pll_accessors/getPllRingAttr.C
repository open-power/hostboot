/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pll_accessors/getPllRingAttr.C $             */
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
// $Id: getPllRingAttr.C,v 1.2 2014/01/10 19:37:13 dedahle Exp $
/**
 *  @file getPllRingAttr.C
 *
 *  @brief fetch PLL ring attributes based on chip EC and frequencies
 *         from data from static arrays (fapiPllRingAttr.H)
 *         Note: Throughout this program all 3 potential attributes
 *               (i.e. _DATA, _FLUSH & _LENGTH) for each PLL ring have
 *               been listed with those that are not currently defined
 *               being commented out.  This was done to help show that
 *               these were not accidentally left out.
 *
 */

#include    <stdint.h>

// Undefine HW for VBU
#define HW
//  fapi support
#include    <fapiPllRingAttr.H>
#include    <getPllRingAttr.H>

// Maximum # of frequencies needed to determine correct PLL ring data
#define   MAX_FREQ_KEYS 4

// Logic overview

// Define and initialize variables
// Get chip type
// Get EC level
// Case statement to get frequncy keys
//   1. Set array element length
//   2. Get additional keys
// Case statement for each PLL ring
//   1. Set pointer to first array element
//   2. Set array size
// Loop through array to return requested element
// Case statement for each attribute
//   1. Set return attr value

extern "C"
{
//    using   namespace   fapi;

    // getPllRingAttr
    fapi::ReturnCode getPllRingAttr( const fapi::AttributeId i_attrId,
                                     const fapi::Target  i_pChipTarget,
                                     uint32_t & o_ringBitLength,
                                     uint8_t *o_data)
    {

        // Define and initialize variables
        const uint32_t DEFAULT_EC_VALUE = 0x10;
        const uint32_t PU_PCIE_REF_CLOCK_CONST = 100;

        fapi::ReturnCode l_fapirc = FAPI_RC_SUCCESS;
        fapi::ReturnCode rc       = FAPI_RC_SUCCESS;
        fapi::ATTR_NAME_Type    l_chipType = 0x00;
        uint8_t                 l_attrDdLevel = DEFAULT_EC_VALUE;
        uint8_t                 l_numKeys = 0;
        uint8_t                 l_arySize = 0;
        uint8_t                 l_idx = 0;
        uint16_t                l_arrayEntryLength = 0;
        // Up to 4 frequencies to query to get PLL data
        uint32_t                l_freqKeys[MAX_FREQ_KEYS] =  {0,0,0,0};
        const PLL_RING_ATTR_WITH_4_KEYS * l_pllArrayPtr = NULL;
        const PLL_RING_ATTR_WITH_2_KEYS * l_2KeyPllArrayPtr = NULL;
        const PLL_RING_ATTR_WITH_1_KEYS * l_1KeyPllArrayPtr = NULL;


        // Initialize array pointers to base EC level arrays


        FAPI_DBG("getPllRingAttr: request i_attrId=0x%x",i_attrId );

        do
        {
            // Get chip type

            FAPI_DBG("getPllRingAttr: Querying Chip type");
            rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_NAME,
                                          &i_pChipTarget,
                                          l_chipType);
            if (rc)  {
                FAPI_ERR("getPllRingAttr:  FAPI_ATTR_GET_PRIVILEGED() "
                         "failed w/rc=0x%08x and chip type=0x%02x",
                         static_cast<uint32_t>(rc),l_chipType);
                break;
            }

            // Get EC level

            FAPI_DBG("getPllRingAttr: Querying EC level");
            rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_EC,
                                          &i_pChipTarget,
                                          l_attrDdLevel);

            if (rc)  {
                FAPI_ERR("getPllRingAttr:  FAPI_ATTR_GET_PRIVILEGED() "
                         "failed w/rc=0x%08x and ddLevel=0x%02x",
                         static_cast<uint32_t>(rc),l_attrDdLevel);
                break;
            }
            FAPI_DBG("getPllRingAttr:  Chip type=0x%02x EC=0x%02x",l_chipType,l_attrDdLevel);

            // Case statement to get frequncy keys
            //   1. Set array element length
            //   2. Get additional keys
            switch (i_attrId)
            {
            case fapi::ATTR_PROC_AB_BNDY_PLL_DATA:
            case fapi::ATTR_PROC_AB_BNDY_PLL_FLUSH:
            case fapi::ATTR_PROC_AB_BNDY_PLL_LENGTH:
            case fapi::ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA:
//            case fapi::ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_FLUSH:
            case fapi::ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_LENGTH:
                // Set entry size
                l_numKeys = 1;
                l_arrayEntryLength = sizeof(PLL_RING_ATTR_WITH_1_KEYS);
                // Get a bus frequency attribute
                rc = FAPI_ATTR_GET(ATTR_FREQ_A,
                                   NULL,
                                   l_freqKeys[0]);
                if (rc)  {
                   FAPI_ERR("getPllRingAttr:  FAPI_ATTR_GET() failed w/rc=0x%08x",
                             static_cast<uint32_t>(rc));
                   break;
                }
                // a bus frequency needs to be halved for table lookup
                l_freqKeys[0] /= 2;
                FAPI_DBG("getPllRingAttr: Queryied frequency ATTR_FREQ_A = %i ", l_freqKeys[0]);
                break;
            case fapi::ATTR_PROC_PB_BNDY_DMIPLL_DATA:
            case fapi::ATTR_PROC_PB_BNDY_DMIPLL_FLUSH:
            case fapi::ATTR_PROC_PB_BNDY_DMIPLL_LENGTH:
            case fapi::ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA:
//            case fapi::ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_FLUSH:
            case fapi::ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_LENGTH:
                // Set entry size
                l_numKeys = 1;
                l_arrayEntryLength = sizeof(PLL_RING_ATTR_WITH_1_KEYS);
                // Get pb frequency attribute
                rc = FAPI_ATTR_GET(ATTR_FREQ_X,
                                   NULL,
                                   l_freqKeys[0]);
                if (rc)  {
                   FAPI_ERR("getPllRingAttr:  FAPI_ATTR_GET() failed w/rc=0x%08x",
                             static_cast<uint32_t>(rc));
                   break;
                }
                break;
            case fapi::ATTR_PROC_PCI_BNDY_PLL_DATA:
            case fapi::ATTR_PROC_PCI_BNDY_PLL_FLUSH:
            case fapi::ATTR_PROC_PCI_BNDY_PLL_LENGTH:
                // Set entry size
                l_numKeys = 1;
                l_arrayEntryLength = sizeof(PLL_RING_ATTR_WITH_1_KEYS);
                // Get PCI frequency attribute
                rc = FAPI_ATTR_GET(ATTR_FREQ_PCIE,
                                   NULL,
                                   l_freqKeys[0]);
                if (rc)  {
                   FAPI_ERR("getPllRingAttr:  FAPI_ATTR_GET() failed w/rc=0x%08x",
                             static_cast<uint32_t>(rc));
                   break;
                }
                break;
            case fapi::ATTR_PROC_PERV_BNDY_PLL_DATA:
            case fapi::ATTR_PROC_PERV_BNDY_PLL_FLUSH:
            case fapi::ATTR_PROC_PERV_BNDY_PLL_LENGTH:
                // Set entry size
                l_numKeys = 4;
                l_arrayEntryLength = sizeof(PLL_RING_ATTR_WITH_4_KEYS);
                // Get pu nest, PCI, ref clock and x bus frequencies attributes
                rc = FAPI_ATTR_GET(ATTR_NEST_FREQ_MHZ,
                                   NULL,
                                   l_freqKeys[0]);
                if (rc)  {
                   FAPI_ERR("getPllRingAttr:  FAPI_ATTR_GET() failed w/rc=0x%08x",
                             static_cast<uint32_t>(rc));
                   break;
                }

                // No equivalent FAPI attribute exists for this cronus key.
                // Always set to 100.
                l_freqKeys[1] = PU_PCIE_REF_CLOCK_CONST;

                rc = FAPI_ATTR_GET(ATTR_FREQ_PROC_REFCLOCK,
                                   NULL,
                                   l_freqKeys[2]);
                if (rc)  {
                   FAPI_ERR("getPllRingAttr:  FAPI_ATTR_GET() failed w/rc=0x%08x",
                              static_cast<uint32_t>(rc));
                   break;
                }

                rc = FAPI_ATTR_GET(ATTR_FREQ_X,
                                   NULL,
                                   l_freqKeys[3]);
                if (rc)  {
                   FAPI_ERR("getPllRingAttr:  FAPI_ATTR_GET() failed w/rc=0x%08x",
                              static_cast<uint32_t>(rc));
                   break;
                }
                FAPI_DBG("getPllRingAttr: Queryied frequency ATTR_FREQ_X = %i ", l_freqKeys[3]);
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_DATA:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_LENGTH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_LENGTH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_LENGTH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_LENGTH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_LENGTH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_LENGTH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_LENGTH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_LENGTH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_LENGTH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_LENGTH:
                // Set entry size
                l_numKeys = 2;
                l_arrayEntryLength = sizeof(PLL_RING_ATTR_WITH_2_KEYS);
                // Get keys
                rc = FAPI_ATTR_GET(ATTR_MSS_FREQ,
                                   &i_pChipTarget,
                                   l_freqKeys[0]);
                if (rc)  {
                   FAPI_ERR("getPllRingAttr:  FAPI_ATTR_GET() failed w/rc=0x%08x",
                             static_cast<uint32_t>(rc));
                   break;
                }

                rc = FAPI_ATTR_GET(ATTR_FREQ_X,
                                   NULL,
                                   l_freqKeys[1]);
                if (rc)  {
                   FAPI_ERR("getPllRingAttr:  FAPI_ATTR_GET() failed w/rc=0x%08x",
                             static_cast<uint32_t>(rc));
                   break;
                }
                break;

            default:
                FAPI_ERR("getPllRingAttr:  Requested attribute not supported. attrId=0x%x", i_attrId);
                rc = FAPI_RC_INVALID_ATTR_GET;
                break;
            };

            // Exit on error
            if (rc)
            {
               break;
            }

            // Case statement for each PLL ring
            //   1. Set pointer to first array element
            //   2. Set array size (# of elements)

        switch (i_attrId)
            {
            case fapi::ATTR_PROC_AB_BNDY_PLL_DATA:
            case fapi::ATTR_PROC_AB_BNDY_PLL_FLUSH:
            case fapi::ATTR_PROC_AB_BNDY_PLL_LENGTH:
                // Is chip type Murano or Venice
                if (l_chipType == ENUM_ATTR_NAME_MURANO) {
                    // Establish default array to S1 EC 10 array
                    l_pllArrayPtr =  reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&S1_10_ATTR_PROC_AB_BNDY_PLL_DATA_array);
                    // Save # of array entries
                    l_arySize = sizeof(S1_10_ATTR_PROC_AB_BNDY_PLL_DATA_array)/l_arrayEntryLength;
                    // For EC 13 use EC specific array
                    if (l_attrDdLevel == 0x13) {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(&S1_13_ATTR_PROC_AB_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(S1_13_ATTR_PROC_AB_BNDY_PLL_DATA_array)/l_arrayEntryLength;
		    } else if (l_attrDdLevel == 0x20) {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(&S1_20_ATTR_PROC_AB_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(S1_20_ATTR_PROC_AB_BNDY_PLL_DATA_array)/l_arrayEntryLength;
		    }
                } else if (l_chipType == ENUM_ATTR_NAME_VENICE) {
                    // Reestablish default array to P8 EC 10 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&P8_10_ATTR_PROC_AB_BNDY_PLL_DATA_array);
                    // Save # of array entries
                    l_arySize = sizeof(P8_10_ATTR_PROC_AB_BNDY_PLL_DATA_array)/l_arrayEntryLength;
                } else {
                    // Not a valid chip type
                    FAPI_ERR("getPllRingAttr:  Invalid chip type = 0x%02x",
                         l_chipType);
                    rc = FAPI_RC_INVALID_CHIP_EC_FEATURE_GET;
                   break;
                }
                break;
            case fapi::ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA:
            case fapi::ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_LENGTH:
                // Is chip type Murano or Venice
                if (l_chipType == ENUM_ATTR_NAME_MURANO) {
                    // Establish default array to S1 EC 10 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&S1_10_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array);
                    // Save # of array entries
                    l_arySize = sizeof(S1_10_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array)/l_arrayEntryLength;
                    // For EC 13 use EC specific array
                    if (l_attrDdLevel == 0x13) {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&S1_13_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array);
                        l_arySize = sizeof(S1_13_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array)/l_arrayEntryLength;
		    } else if (l_attrDdLevel == 0x20) {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(&S1_20_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array);
                        l_arySize = sizeof(S1_20_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array)/l_arrayEntryLength;
		    }
                } else if (l_chipType == ENUM_ATTR_NAME_VENICE) {
                    // Reestablish default array to P8 EC 10 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&P8_10_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array);
                    // Save # of array entries
                    l_arySize = sizeof(P8_10_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array)/l_arrayEntryLength;
                } else {
                    // Not a valid chip type
                    FAPI_ERR("getPllRingAttr:  Invalid chip type = 0x%02x",
                         l_chipType);
                    rc = FAPI_RC_INVALID_CHIP_EC_FEATURE_GET;
                   break;
                }
                break;
            case fapi::ATTR_PROC_PB_BNDY_DMIPLL_DATA:
            case fapi::ATTR_PROC_PB_BNDY_DMIPLL_FLUSH:
            case fapi::ATTR_PROC_PB_BNDY_DMIPLL_LENGTH:
                // Is chip type Murano or Venice
                if (l_chipType == ENUM_ATTR_NAME_MURANO) {
                    // Establish default array to S1 EC 10 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&S1_10_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array);
                    // Save # of array entries
                    l_arySize = sizeof(S1_10_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array)/l_arrayEntryLength;
                    // For EC 13 use EC specific array
                    if (l_attrDdLevel == 0x13) {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&S1_13_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array);
                        l_arySize = sizeof(S1_13_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array)/l_arrayEntryLength;
                    } else if (l_attrDdLevel == 0x20) {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(&S1_20_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array);
                        l_arySize = sizeof(S1_20_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array)/l_arrayEntryLength;
		    }
                } else if (l_chipType == ENUM_ATTR_NAME_VENICE) {
                    // Reestablish default array to P8 EC 10 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&P8_10_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array);
                    // Save # of array entries
                    l_arySize = sizeof(P8_10_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array)/l_arrayEntryLength;
                } else {
                    // Not a valid chip type
                    FAPI_ERR("getPllRingAttr:  Invalid chip type = 0x%02x",
                         l_chipType);
                    rc = FAPI_RC_INVALID_CHIP_EC_FEATURE_GET;
                   break;
                }
                break;
            case fapi::ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA:
//            case fapi::ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_FLUSH:
            case fapi::ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_LENGTH:
                // Is chip type Murano or Venice
                if (l_chipType == ENUM_ATTR_NAME_MURANO) {
                    // Establish default array to S1 EC 10 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&S1_10_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array);
                    // Save # of array entries
                    l_arySize = sizeof(S1_10_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array)/l_arrayEntryLength;
                    // For EC 13 use EC specific array
                    if (l_attrDdLevel == 0x13) {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&S1_13_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array);
                        l_arySize = sizeof(S1_13_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array)/l_arrayEntryLength;
                    } else if (l_attrDdLevel == 0x20) {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(&S1_20_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array);
                        l_arySize = sizeof(S1_20_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array)/l_arrayEntryLength;
                    }
                } else if  (l_chipType == ENUM_ATTR_NAME_VENICE) {
                    // Reestablish default array to P8 EC 10 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&P8_10_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array);
                    // Save # of array entries
                    l_arySize = sizeof(P8_10_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array)/l_arrayEntryLength;
                } else {
                    // Not a valid chip type
                    FAPI_ERR("getPllRingAttr:  Invalid chip type = 0x%02x",
                         l_chipType);
                    rc = FAPI_RC_INVALID_CHIP_EC_FEATURE_GET;
                   break;
                }
                break;
            case fapi::ATTR_PROC_PCI_BNDY_PLL_DATA:
            case fapi::ATTR_PROC_PCI_BNDY_PLL_FLUSH:
            case fapi::ATTR_PROC_PCI_BNDY_PLL_LENGTH:
                // Is chip type Murano or Venice
                if (l_chipType == ENUM_ATTR_NAME_MURANO) {
                    // Establish default array to S1 EC 10 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(&S1_10_ATTR_PROC_PCI_BNDY_PLL_DATA_array);
                    // Save # of array entries
                    l_arySize = sizeof(S1_10_ATTR_PROC_PCI_BNDY_PLL_DATA_array)/l_arrayEntryLength;
                    // For EC 13 use EC specific array
                    if (l_attrDdLevel == 0x13) {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&S1_13_ATTR_PROC_PCI_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(S1_13_ATTR_PROC_PCI_BNDY_PLL_DATA_array)/l_arrayEntryLength;
                    } else if (l_attrDdLevel == 0x20) {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(&S1_20_ATTR_PROC_PCI_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(S1_20_ATTR_PROC_PCI_BNDY_PLL_DATA_array)/l_arrayEntryLength;
		    }
                } else if (l_chipType == ENUM_ATTR_NAME_VENICE) {
                    // Reestablish default array to P8 EC 10 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&P8_10_ATTR_PROC_PCI_BNDY_PLL_DATA_array);
                    // Save # of array entries
                    l_arySize = sizeof(P8_10_ATTR_PROC_PCI_BNDY_PLL_DATA_array)/l_arrayEntryLength;
                } else {
                    // Not a valid chip type
                    FAPI_ERR("getPllRingAttr:  Invalid chip type = 0x%02x",
                         l_chipType);
                    rc = FAPI_RC_INVALID_CHIP_EC_FEATURE_GET;
                   break;
                }
                break;
            case fapi::ATTR_PROC_PERV_BNDY_PLL_DATA:
            case fapi::ATTR_PROC_PERV_BNDY_PLL_FLUSH:
            case fapi::ATTR_PROC_PERV_BNDY_PLL_LENGTH:
                // Is chip type Murano or Venice
                if (l_chipType == ENUM_ATTR_NAME_MURANO) {
                    // Establish default array to S1 EC 10 array
                    l_pllArrayPtr =
                    reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&S1_10_ATTR_PROC_PERV_BNDY_PLL_DATA_array);
                    // Save # of array entries
                    l_arySize = sizeof(S1_10_ATTR_PROC_PERV_BNDY_PLL_DATA_array)/l_arrayEntryLength;
                    // For EC 13 use EC specific array
                    if (l_attrDdLevel == 0x13) {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&S1_13_ATTR_PROC_PERV_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(S1_13_ATTR_PROC_PERV_BNDY_PLL_DATA_array)/l_arrayEntryLength;
                    } else if (l_attrDdLevel == 0x20) {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(&S1_20_ATTR_PROC_PERV_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(S1_20_ATTR_PROC_PERV_BNDY_PLL_DATA_array)/l_arrayEntryLength;
		    }
                } else if (l_chipType == ENUM_ATTR_NAME_VENICE) {
                    // Reestablish default array to P8 EC 10 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&P8_10_ATTR_PROC_PERV_BNDY_PLL_DATA_array);
                    // Save # of array entries
                    l_arySize = sizeof(P8_10_ATTR_PROC_PERV_BNDY_PLL_DATA_array)/l_arrayEntryLength;
                } else {
                    // Not a valid chip type
                    FAPI_ERR("getPllRingAttr:  Invalid chip type = 0x%02x",
                         l_chipType);
                    rc = FAPI_RC_INVALID_CHIP_EC_FEATURE_GET;
                   break;
                }
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_DATA:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_LENGTH:
                // Establish default array to Centaur EC 10 array
                l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_10_ATTR_MEMB_TP_BNDY_PLL_DATA_array);
                // Save # of array entries
                l_arySize = sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_DATA_array)/l_arrayEntryLength;
                if (l_attrDdLevel == 0x20) {
                    // Reestablish default array to Centaur EC 20 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_20_ATTR_MEMB_TP_BNDY_PLL_DATA_array);
                    l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_DATA_array)/l_arrayEntryLength;
		}
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_LENGTH:
                // Establish default array to Centaur EC 10 array
                l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_10_ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_DATA_array);
                // Save # of array entries
                l_arySize = sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_DATA_array)/l_arrayEntryLength;
                if (l_attrDdLevel == 0x20) {
                    // Reestablish default array to Centaur EC 20 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_20_ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_DATA_array);
                    l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_DATA_array)/l_arrayEntryLength;
		}
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_LENGTH:
                // Establish default array to Centaur EC 10 array
                l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_DATA_array);
                // Save # of array entries
                l_arySize = sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_DATA_array)/l_arrayEntryLength;
                if (l_attrDdLevel == 0x20) {
                    // Reestablish default array to Centaur EC 20 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_DATA_array);
                    l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_DATA_array)/l_arrayEntryLength;
		}
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_LENGTH:
                // Establish default array to Centaur EC 10 array
                l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_DATA_array);
                // Save # of array entries
                l_arySize = sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_DATA_array)/l_arrayEntryLength;
                if (l_attrDdLevel == 0x20) {
                    // Reestablish default array to Centaur EC 20 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_DATA_array);
                    l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_DATA_array)/l_arrayEntryLength;
		}
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_LENGTH:
                // Establish default array to Centaur EC 10 array
                l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_DATA_array);
                // Save # of array entries
                l_arySize = sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_DATA_array)/l_arrayEntryLength;
                if (l_attrDdLevel == 0x20) {
                    // Reestablish default array to Centaur EC 20 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_DATA_array);
                    l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_DATA_array)/l_arrayEntryLength;
		}
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_LENGTH:
                // Establish default array to Centaur EC 10 array
                l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_DATA_array);
                // Save # of array entries
                l_arySize = sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_DATA_array)/l_arrayEntryLength;
                if (l_attrDdLevel == 0x20) {
                    // Reestablish default array to Centaur EC 20 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_DATA_array);
                    l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_DATA_array)/l_arrayEntryLength;
		}
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_LENGTH:
                // Establish default array to Centaur EC 10 array
                l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_DATA_array);
                // Save # of array entries
                l_arySize = sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_DATA_array)/l_arrayEntryLength;
                if (l_attrDdLevel == 0x20) {
                    // Reestablish default array to Centaur EC 20 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_DATA_array);
                    l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_DATA_array)/l_arrayEntryLength;
		}
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_LENGTH:
                // Establish default array to Centaur EC 10 array
                l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_DATA_array);
                // Save # of array entries
                l_arySize = sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_DATA_array)/l_arrayEntryLength;
                if (l_attrDdLevel == 0x20) {
                    // Reestablish default array to Centaur EC 20 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_DATA_array);
                    l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_DATA_array)/l_arrayEntryLength;
		}
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_LENGTH:
                // Establish default array to Centaur EC 10 array
                l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_DATA_array);
                // Save # of array entries
                l_arySize =
                  sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_DATA_array)
                  /l_arrayEntryLength;
                if (l_attrDdLevel == 0x20) {
                    // Reestablish default array to Centaur EC 20 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_DATA_array);
                    l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_DATA_array)/l_arrayEntryLength;
		}
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_LENGTH:
                // Establish default array to Centaur EC 10 array
                l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_DATA_array);
                // Save # of array entries
                l_arySize =
                  sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_DATA_array)
                  /l_arrayEntryLength;
                if (l_attrDdLevel == 0x20) {
                    // Reestablish default array to Centaur EC 20 array
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(&Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_DATA_array);
                    l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_DATA_array)/l_arrayEntryLength;
		}
                break;
            default:
                FAPI_ERR("getPllRingAttr:  Requested attribute not supported. attrId=0x%x", i_attrId);
                rc = FAPI_RC_INVALID_ATTR_GET;
                break;
         };
            // Exit on error
            if (rc)
            {
               break;
            }

            // Loop through array to return requested element

            bool l_foundMatch = false;

            // Find array entry for that frequency
            for(l_idx = 0; (l_idx < l_arySize) && (!l_foundMatch); l_idx++ )
            {
                // For each frequency key to match
                if (((l_numKeys == 1) &&
                     (l_pllArrayPtr->l_freq_1 == l_freqKeys[0])) ||
                    ((l_numKeys == 2) &&
                     (l_pllArrayPtr->l_freq_1 == l_freqKeys[0]) &&
                     (l_pllArrayPtr->l_freq_2 == l_freqKeys[1])) ||
                    ((l_numKeys == 4) &&
                     (l_pllArrayPtr->l_freq_1 == l_freqKeys[0]) &&
                     (l_pllArrayPtr->l_freq_2 == l_freqKeys[1]) &&
                     (l_pllArrayPtr->l_freq_3 == l_freqKeys[2]) &&
                     (l_pllArrayPtr->l_freq_4 == l_freqKeys[3])))
                {
                    FAPI_DBG("getPllRingAttr:  Found matching array entry");
                    l_foundMatch = true;
                }
                else
                {
                    // Move to next entry
                    uint64_t l_rawAddr = reinterpret_cast<uint64_t>(l_pllArrayPtr);
                    l_rawAddr += l_arrayEntryLength;
                    l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(l_rawAddr);
                }
            }
            if (l_foundMatch) {

                // Case statement for each attribute (grouped by number
                // of keys and attribute type (i.e. data, flush, length)
                // 1. Set return attr value

                l_1KeyPllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_1_KEYS *>(l_pllArrayPtr);
                l_2KeyPllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_2_KEYS *>(l_pllArrayPtr);
                switch (i_attrId)
                {
                case fapi::ATTR_PROC_AB_BNDY_PLL_DATA:
                case fapi::ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA:
                case fapi::ATTR_PROC_PB_BNDY_DMIPLL_DATA:
                case fapi::ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA:
                case fapi::ATTR_PROC_PCI_BNDY_PLL_DATA:
                    // Copy ring data
                    for (uint16_t i = 0;
                         i < (l_1KeyPllArrayPtr -> l_ATTR_PLL_RING_BYTE_LENGTH);
                         i++)
                    {
                        o_data[i] =l_1KeyPllArrayPtr->l_ATTR_PLL_RING_DATA[i];
                    }
                    break;
                case fapi::ATTR_PROC_AB_BNDY_PLL_FLUSH:
//                case fapi::ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_FLUSH:
                case fapi::ATTR_PROC_PB_BNDY_DMIPLL_FLUSH:
//                case fapi::ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_FLUSH:
                case fapi::ATTR_PROC_PCI_BNDY_PLL_FLUSH:
                    // Copy flush data
                    for (uint16_t i = 0;
                         i < (l_1KeyPllArrayPtr -> l_ATTR_PLL_RING_BYTE_LENGTH);
                         i++)
                    {
                        o_data[i] =l_1KeyPllArrayPtr->l_ATTR_PLL_RING_FLUSH[i];
                    }
                    break;
                case fapi::ATTR_PROC_AB_BNDY_PLL_LENGTH:
                case fapi::ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_LENGTH:
                case fapi::ATTR_PROC_PB_BNDY_DMIPLL_LENGTH:
                case fapi::ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_LENGTH:
                case fapi::ATTR_PROC_PCI_BNDY_PLL_LENGTH:
                    // Set length
                    o_ringBitLength = l_1KeyPllArrayPtr -> l_ATTR_PLL_RING_BIT_LENGTH;
                    break;
                case fapi::ATTR_PROC_PERV_BNDY_PLL_DATA:
                    // Copy ring data
                    for (uint16_t i = 0;
                         i < (l_pllArrayPtr -> l_ATTR_PLL_RING_BYTE_LENGTH);
                         i++)
                    {
                        o_data[i] =l_pllArrayPtr->l_ATTR_PLL_RING_DATA[i];
                    }
                    break;
                case fapi::ATTR_PROC_PERV_BNDY_PLL_FLUSH:
                    // Copy flush data
                    for (uint16_t i = 0;
                         i < (l_pllArrayPtr -> l_ATTR_PLL_RING_BYTE_LENGTH);
                         i++)
                    {
                        o_data[i] =l_pllArrayPtr->l_ATTR_PLL_RING_FLUSH[i];
                    }
                    break;
                case fapi::ATTR_PROC_PERV_BNDY_PLL_LENGTH:
                    // Set length
                    o_ringBitLength = l_pllArrayPtr -> l_ATTR_PLL_RING_BIT_LENGTH;
                    break;
                case fapi::ATTR_MEMB_TP_BNDY_PLL_DATA:
                case fapi::ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_DATA:
                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_DATA:
                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_DATA:
                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_DATA:
                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_DATA:
                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_DATA:
                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_DATA:
                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_DATA:
                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_DATA:
                    // Copy ring data
                    for (uint16_t i = 0;
                         i < (l_2KeyPllArrayPtr -> l_ATTR_PLL_RING_BYTE_LENGTH);
                         i++)
                    {
                        o_data[i] = l_2KeyPllArrayPtr->l_ATTR_PLL_RING_DATA[i];
                    }
                    break;
                case fapi::ATTR_MEMB_TP_BNDY_PLL_FLUSH:
//                case fapi::ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_FLUSH:
//                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_FLUSH:
//                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_FLUSH:
//                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_FLUSH:
//                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_FLUSH:
//                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_FLUSH:
//                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_FLUSH:
//                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_FLUSH:
//                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_FLUSH:
                    // Copy flush data
                    for (uint16_t i = 0;
                         i < (l_2KeyPllArrayPtr->l_ATTR_PLL_RING_BYTE_LENGTH);
                         i++)
                    {
                        o_data[i] = l_2KeyPllArrayPtr->l_ATTR_PLL_RING_FLUSH[i];
                    }
                    break;
                case fapi::ATTR_MEMB_TP_BNDY_PLL_LENGTH:
                case fapi::ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_LENGTH:
                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_LENGTH:
                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_LENGTH:
                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_LENGTH:
                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_LENGTH:
                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_LENGTH:
                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_LENGTH:
                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_LENGTH:
                case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_LENGTH:
                    // Set length
                    o_ringBitLength = l_2KeyPllArrayPtr->l_ATTR_PLL_RING_BIT_LENGTH;
                    break;
                default:
                    FAPI_ERR("getPllRingAttr:  Requested attribute not supported. attrId=0x%x", i_attrId);
                    break;
                };
            } else {
                FAPI_ERR("getPllRingAttr:  No match found for attrId=0x%x chiptype=0x%x EC=0x%x frequency=%d", i_attrId, l_chipType, l_attrDdLevel, l_freqKeys[0]);
                // Return error on get attr
                rc = FAPI_RC_INVALID_CHIP_EC_FEATURE_GET;
                break;
            }
        } while (0);


        l_fapirc = rc;


        FAPI_DBG("getPllRingAttr: exit rc=0x%08x",static_cast<uint32_t>(l_fapirc));

        return  l_fapirc;
    }
}   // extern "C"



