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
// $Id: getPllRingAttr.C,v 1.6 2014/04/16 19:23:11 thi Exp $
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

#include <stdint.h>

// Undefine HW for VBU
#define HW
//  fapi support
#include <fapiPllRingAttr.H>
#include <getPllRingAttr.H>

// Maximum # of frequencies needed to determine correct PLL ring data
#define MAX_FREQ_KEYS 4

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

// getPllRingAttr
fapi::ReturnCode getPllRingAttr( const fapi::AttributeId i_attrId,
                                 const fapi::Target i_pChipTarget,
                                 uint32_t & o_ringBitLength,
                                 uint8_t *o_data)
{
    // Define and initialize variables
    const uint32_t PU_PCIE_REF_CLOCK_CONST = 100;
    fapi::ReturnCode rc;
    fapi::ATTR_NAME_Type    l_chipType = 0x00;
    fapi::ATTR_EC_Type      l_attrDdLevel = 0x00;
    uint8_t                 l_numKeys = 0;
    uint8_t                 l_arySize = 0;
    uint8_t                 l_idx = 0;
    uint16_t                l_arrayEntryLength = 0;
    // Up to 4 frequencies to query to get PLL data
    uint32_t                l_freqKeys[MAX_FREQ_KEYS] =  {0,0,0,0};
    const PLL_RING_ATTR_WITH_4_KEYS * l_pllArrayPtr = NULL;
    const PLL_RING_ATTR_WITH_2_KEYS * l_2KeyPllArrayPtr = NULL;
    const PLL_RING_ATTR_WITH_1_KEYS * l_1KeyPllArrayPtr = NULL;

    // Error FFDC
    const fapi::AttributeId & ATTR_ID = i_attrId;
    const fapi::Target & PROC_CHIP = i_pChipTarget;
    const fapi::ATTR_NAME_Type & CHIP_NAME = l_chipType;
    const fapi::ATTR_NAME_Type & CHIP_EC = l_attrDdLevel;

    // Initialize array pointers to base EC level arrays
    FAPI_DBG("getPllRingAttr: request i_attrId=0x%x",i_attrId );

    do
    {
        // Get chip type
        FAPI_DBG("getPllRingAttr: Querying Chip type");
        rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_NAME, &i_pChipTarget, l_chipType);
        if (rc)
        {
            FAPI_ERR("getPllRingAttr: Get ATTR_NAME failed");
            break;
        }

        // Get EC level
        FAPI_DBG("getPllRingAttr: Querying EC level");
        rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_EC, &i_pChipTarget, l_attrDdLevel);
        if (rc)
        {
            FAPI_ERR("getPllRingAttr: Get ATTR_EC failed");
            break;
        }

        // Murano DD1.2 and DD1.0 are equivalent in terms of engineering data
        if ((l_chipType == fapi::ENUM_ATTR_NAME_MURANO) &&
            (l_attrDdLevel == 0x12))
        {
            FAPI_INF("getPllRingAttr: Treating Murano EC1.2 like EC1.0");
            l_attrDdLevel = 0x10;
        }

        FAPI_DBG("getPllRingAttr: Chip type=0x%02x EC=0x%02x", l_chipType,
                 l_attrDdLevel);

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
                rc = FAPI_ATTR_GET(ATTR_FREQ_A, NULL, l_freqKeys[0]);
                if (rc)
                {
                   FAPI_ERR("getPllRingAttr: Get ATTR_FREQ_A failed");
                   break;
                }
                // a bus frequency needs to be halved for table lookup
                l_freqKeys[0] /= 2;
                FAPI_DBG("getPllRingAttr: Queryied frequency ATTR_FREQ_A = %i ",
                         l_freqKeys[0]);
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
                rc = FAPI_ATTR_GET(ATTR_FREQ_X, NULL, l_freqKeys[0]);
                if (rc)
                {
                   FAPI_ERR("getPllRingAttr: Get ATTR_FREQ_X failed");
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
                rc = FAPI_ATTR_GET(ATTR_FREQ_PCIE, NULL, l_freqKeys[0]);
                if (rc)
                {
                   FAPI_ERR("getPllRingAttr: Get ATTR_FREQ_PCIE failed");
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
                rc = FAPI_ATTR_GET(ATTR_NEST_FREQ_MHZ, NULL, l_freqKeys[0]);
                if (rc)
                {
                   FAPI_ERR("getPllRingAttr: Get ATTR_NEST_FREQ_MHZ failed ");
                   break;
                }

                // No equivalent FAPI attribute exists for this cronus key.
                // Always set to 100.
                l_freqKeys[1] = PU_PCIE_REF_CLOCK_CONST;

                rc = FAPI_ATTR_GET(ATTR_FREQ_PROC_REFCLOCK, NULL,
                                   l_freqKeys[2]);
                if (rc)
                {
                   FAPI_ERR("getPllRingAttr: Get ATTR_FREQ_PROC_REFCLOCK failed");
                   break;
                }

                rc = FAPI_ATTR_GET(ATTR_FREQ_X, NULL, l_freqKeys[3]);
                if (rc)
                {
                   FAPI_ERR("getPllRingAttr: Get ATTR_FREQ_X failed");
                   break;
                }
                FAPI_DBG("getPllRingAttr: Queryied frequency ATTR_FREQ_X = %i ",
                         l_freqKeys[3]);
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
                rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &i_pChipTarget,
                                   l_freqKeys[0]);
                if (rc)
                {
                   FAPI_ERR("getPllRingAttr: Get ATTR_MSS_FREQ failed");
                   break;
                }

                rc = FAPI_ATTR_GET(ATTR_FREQ_X, NULL, l_freqKeys[1]);
                if (rc)
                {
                   FAPI_ERR("getPllRingAttr: Get ATTR_FREQ_X failed");
                   break;
                }
                break;
            default:
                FAPI_ERR("getPllRingAttr: Requested attribute not supported. attrId=0x%x",
                         i_attrId);
                FAPI_SET_HWP_ERROR(rc, RC_GET_PLL_RING_ATTR_INVALID_ATTRIBUTE_ID);
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
                if (l_chipType == ENUM_ATTR_NAME_MURANO)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &S1_10_ATTR_PROC_AB_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(S1_10_ATTR_PROC_AB_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x13)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(
                            &S1_13_ATTR_PROC_AB_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(S1_13_ATTR_PROC_AB_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(
                            &S1_20_ATTR_PROC_AB_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(S1_20_ATTR_PROC_AB_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x21)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(
                            &S1_21_ATTR_PROC_AB_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(S1_21_ATTR_PROC_AB_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                else if (l_chipType == ENUM_ATTR_NAME_VENICE)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &P8_10_ATTR_PROC_AB_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(P8_10_ATTR_PROC_AB_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr =
                            reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>
                            ( &P8_20_ATTR_PROC_AB_BNDY_PLL_DATA_array);
                        l_arySize =
                            sizeof(P8_20_ATTR_PROC_AB_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                break;
            case fapi::ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA:
            case fapi::ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_LENGTH:
                if (l_chipType == ENUM_ATTR_NAME_MURANO)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &S1_10_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array);
                        l_arySize = sizeof(S1_10_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x13)
                    {
                        l_pllArrayPtr =
                            reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                                &S1_13_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array);
                        l_arySize = sizeof(S1_13_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(
                            &S1_20_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array);
                        l_arySize = sizeof(S1_20_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x21)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(
                            &S1_21_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array);
                        l_arySize = sizeof(S1_21_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                else if (l_chipType == ENUM_ATTR_NAME_VENICE)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &P8_10_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array);
                        l_arySize = sizeof(P8_10_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr =
                            reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>
                            (&P8_20_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array);
                        l_arySize =
                      sizeof(P8_20_ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                break;
            case fapi::ATTR_PROC_PB_BNDY_DMIPLL_DATA:
            case fapi::ATTR_PROC_PB_BNDY_DMIPLL_FLUSH:
            case fapi::ATTR_PROC_PB_BNDY_DMIPLL_LENGTH:
                if (l_chipType == ENUM_ATTR_NAME_MURANO)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &S1_10_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array);
                        l_arySize = sizeof(S1_10_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x13)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &S1_13_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array);
                        l_arySize = sizeof(S1_13_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(
                            &S1_20_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array);
                        l_arySize = sizeof(S1_20_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x21)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(
                            &S1_21_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array);
                        l_arySize = sizeof(S1_21_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                else if (l_chipType == ENUM_ATTR_NAME_VENICE)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &P8_10_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array);
                        l_arySize = sizeof(P8_10_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr =
                            reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>
                            ( &P8_20_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array);
                        l_arySize =
                            sizeof(P8_20_ATTR_PROC_PB_BNDY_DMIPLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                break;
            case fapi::ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA:
//            case fapi::ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_FLUSH:
            case fapi::ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_LENGTH:
                if (l_chipType == ENUM_ATTR_NAME_MURANO)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &S1_10_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array);
                        l_arySize = sizeof(S1_10_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x13)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &S1_13_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array);
                        l_arySize = sizeof(S1_13_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(
                            &S1_20_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array);
                        l_arySize = sizeof(S1_20_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x21)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(
                            &S1_21_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array);
                        l_arySize = sizeof(S1_21_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                else if (l_chipType == ENUM_ATTR_NAME_VENICE)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &P8_10_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array);
                        l_arySize = sizeof(P8_10_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr =
                            reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>
                        ( &P8_20_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array);
                        l_arySize =
                   sizeof(P8_20_ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                break;
            case fapi::ATTR_PROC_PCI_BNDY_PLL_DATA:
            case fapi::ATTR_PROC_PCI_BNDY_PLL_FLUSH:
            case fapi::ATTR_PROC_PCI_BNDY_PLL_LENGTH:
                if (l_chipType == ENUM_ATTR_NAME_MURANO)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(
                            &S1_10_ATTR_PROC_PCI_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(S1_10_ATTR_PROC_PCI_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x13)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &S1_13_ATTR_PROC_PCI_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(S1_13_ATTR_PROC_PCI_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(
                            &S1_20_ATTR_PROC_PCI_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(S1_20_ATTR_PROC_PCI_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x21)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(
                            &S1_21_ATTR_PROC_PCI_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(S1_21_ATTR_PROC_PCI_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                else if (l_chipType == ENUM_ATTR_NAME_VENICE)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &P8_10_ATTR_PROC_PCI_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(P8_10_ATTR_PROC_PCI_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr =
                            reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>
                            ( &P8_20_ATTR_PROC_PCI_BNDY_PLL_DATA_array);
                        l_arySize =
                            sizeof(P8_20_ATTR_PROC_PCI_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                break;
            case fapi::ATTR_PROC_PERV_BNDY_PLL_DATA:
            case fapi::ATTR_PROC_PERV_BNDY_PLL_FLUSH:
            case fapi::ATTR_PROC_PERV_BNDY_PLL_LENGTH:
                if (l_chipType == ENUM_ATTR_NAME_MURANO)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &S1_10_ATTR_PROC_PERV_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(S1_10_ATTR_PROC_PERV_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x13)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &S1_13_ATTR_PROC_PERV_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(S1_13_ATTR_PROC_PERV_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(
                            &S1_20_ATTR_PROC_PERV_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(S1_20_ATTR_PROC_PERV_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x21)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS*>(
                            &S1_21_ATTR_PROC_PERV_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(S1_21_ATTR_PROC_PERV_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                else if (l_chipType == ENUM_ATTR_NAME_VENICE)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &P8_10_ATTR_PROC_PERV_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(P8_10_ATTR_PROC_PERV_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr =
                             reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>
                             ( &P8_20_ATTR_PROC_PERV_BNDY_PLL_DATA_array);
                        l_arySize =
                            sizeof(P8_20_ATTR_PROC_PERV_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_DATA:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_LENGTH:
                if (l_chipType == ENUM_ATTR_NAME_CENTAUR)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_10_ATTR_MEMB_TP_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_20_ATTR_MEMB_TP_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x21)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_21_ATTR_MEMB_TP_BNDY_PLL_DATA_array);
                        l_arySize = sizeof(Centaur_21_ATTR_MEMB_TP_BNDY_PLL_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_LENGTH:
                if (l_chipType == ENUM_ATTR_NAME_CENTAUR)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_10_ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_DATA_array);
                        l_arySize = sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_20_ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_DATA_array);
                        l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x21)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_21_ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_DATA_array);
                        l_arySize = sizeof(Centaur_21_ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_LENGTH:
                if (l_chipType == ENUM_ATTR_NAME_CENTAUR)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_DATA_array);
                        l_arySize = sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_DATA_array);
                        l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x21)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_21_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_DATA_array);
                        l_arySize = sizeof(Centaur_21_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_LENGTH:
                if (l_chipType == ENUM_ATTR_NAME_CENTAUR)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_DATA_array);
                        l_arySize = sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_DATA_array);
                        l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x21)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_21_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_DATA_array);
                        l_arySize = sizeof(Centaur_21_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_LENGTH:
                if (l_chipType == ENUM_ATTR_NAME_CENTAUR)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_DATA_array);
                        l_arySize = sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_DATA_array);
                        l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x21)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_21_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_DATA_array);
                        l_arySize = sizeof(Centaur_21_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_LENGTH:
                if (l_chipType == ENUM_ATTR_NAME_CENTAUR)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_DATA_array);
                        l_arySize = sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_DATA_array);
                        l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x21)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_21_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_DATA_array);
                        l_arySize = sizeof(Centaur_21_ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_LENGTH:
                if (l_chipType == ENUM_ATTR_NAME_CENTAUR)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_DATA_array);
                        l_arySize = sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_DATA_array);
                        l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x21)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_21_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_DATA_array);
                        l_arySize = sizeof(Centaur_21_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_LENGTH:
                if (l_chipType == ENUM_ATTR_NAME_CENTAUR)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_DATA_array);
                        l_arySize = sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_DATA_array);
                        l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x21)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_21_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_DATA_array);
                        l_arySize = sizeof(Centaur_21_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_LENGTH:
                if (l_chipType == ENUM_ATTR_NAME_CENTAUR)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_DATA_array);
                        l_arySize = sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_DATA_array) /
                        l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_DATA_array);
                        l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x21)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_21_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_DATA_array);
                        l_arySize = sizeof(Centaur_21_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                break;
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_DATA:
//            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_FLUSH:
            case fapi::ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_LENGTH:
                if (l_chipType == ENUM_ATTR_NAME_CENTAUR)
                {
                    if (l_attrDdLevel == 0x10)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_DATA_array);
                        l_arySize = sizeof(Centaur_10_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x20)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_DATA_array);
                        l_arySize = sizeof(Centaur_20_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_DATA_array) /
                            l_arrayEntryLength;
                    }
                    else if (l_attrDdLevel == 0x21)
                    {
                        l_pllArrayPtr = reinterpret_cast<const PLL_RING_ATTR_WITH_4_KEYS *>(
                            &Centaur_21_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_DATA_array);
                        l_arySize = sizeof(Centaur_21_ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_DATA_array) /
                            l_arrayEntryLength;
                    }
                }
                break;
            default:
                FAPI_ERR("getPllRingAttr: Requested attribute not supported. attrId=0x%x",
                         i_attrId);
                FAPI_SET_HWP_ERROR(rc, RC_GET_PLL_RING_ATTR_INVALID_ATTRIBUTE_ID);
        };

        // Exit on error
        if (rc)
        {
           break;
        }
        
        if (l_pllArrayPtr == NULL)
        {
            FAPI_ERR("getPllRingAttr: Bad chip name (0x%02x) or Bad EC (0x%02x) for attrId 0x%x",
                     l_chipType, l_attrDdLevel, i_attrId);
            FAPI_SET_HWP_ERROR(rc, RC_GET_PLL_RING_ATTR_BAD_CHIP_NAME_EC);
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
        if (l_foundMatch)
        {
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
                    FAPI_ERR("getPllRingAttr: Requested attribute not supported. attrId=0x%x",
                             i_attrId);
                    FAPI_SET_HWP_ERROR(rc, RC_GET_PLL_RING_ATTR_INVALID_ATTRIBUTE_ID);
                    break;
            };
        }
        else
        {
            if (l_numKeys == 1)
            {
                FAPI_ERR("getPllRingAttr: No match found for attrId=0x%x chiptype=0x%x EC=0x%x freq1=%d",
                         i_attrId, l_chipType, l_attrDdLevel, l_freqKeys[0]);
                const uint32_t & FREQ_1 = l_pllArrayPtr->l_freq_1;
                FAPI_SET_HWP_ERROR(rc, RC_GET_PLL_RING_ATTR_UNSUPPORTED_FREQ_1);
            }
            else if (l_numKeys == 2)
            {
                FAPI_ERR("getPllRingAttr: No match found for attrId=0x%x chiptype=0x%x EC=0x%x",
                         i_attrId, l_chipType, l_attrDdLevel);
                FAPI_ERR("getPllRingAttr: freq1=%d, freq2=%d", l_freqKeys[0],
                         l_freqKeys[1]);
                const uint32_t & FREQ_1 = l_pllArrayPtr->l_freq_1;
                const uint32_t & FREQ_2 = l_pllArrayPtr->l_freq_2;
                FAPI_SET_HWP_ERROR(rc, RC_GET_PLL_RING_ATTR_UNSUPPORTED_FREQ_2);
            }
            else
            {
                FAPI_ERR("getPllRingAttr: No match found for attrId=0x%x chiptype=0x%x EC=0x%x",
                         i_attrId, l_chipType, l_attrDdLevel);
                FAPI_ERR("getPllRingAttr: freq1=%d, freq2=%d, freq3=%d, freq4=%d",
                         l_freqKeys[0], l_freqKeys[1], l_freqKeys[2],
                         l_freqKeys[3]);
                const uint32_t & FREQ_1 = l_pllArrayPtr->l_freq_1;
                const uint32_t & FREQ_2 = l_pllArrayPtr->l_freq_2;
                const uint32_t & FREQ_3 = l_pllArrayPtr->l_freq_3;
                const uint32_t & FREQ_4 = l_pllArrayPtr->l_freq_4;
                FAPI_SET_HWP_ERROR(rc, RC_GET_PLL_RING_ATTR_UNSUPPORTED_FREQ_4);
            }
            break;
        }
    } while (0);

    FAPI_DBG("getPllRingAttr: exit rc=0x%08x",static_cast<uint32_t>(rc));
    return rc;
}

}   // extern "C"

