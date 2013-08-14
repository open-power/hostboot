/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dimmBadDqBitmapAccessHwp.C $                 */
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
// $Id: dimmBadDqBitmapAccessHwp.C,v 1.3 2013/08/13 20:29:15 mjjones Exp $
/**
 *  @file dimmBadDqBitmapAccessHwp.C
 *
 *  @brief FW Team HWP that accesses the Bad DQ Bitmap.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     02/17/2012  Created.
 *                          mjjones     01/30/2013  Cope with platform endian
 *                                                  differences
 *                          dedahle     06/22/2013  Show unconnected DQ lines
 */

#include <dimmBadDqBitmapAccessHwp.H>

// DQ Data format in DIMM SPD
const uint32_t DIMM_BAD_DQ_MAGIC_NUMBER = 0xbadd4471;
const uint8_t DIMM_BAD_DQ_VERSION = 1;
const uint8_t ECC_DQ_BYTE_NUMBER_INDEX = 8;
const uint8_t SPARE_DRAM_DQ_BYTE_NUMBER_INDEX = 9;

struct dimmBadDqDataFormat
{
    uint32_t iv_magicNumber;
    uint8_t  iv_version;
    uint8_t  iv_reserved1;
    uint8_t  iv_reserved2;
    uint8_t  iv_reserved3;
    uint8_t  iv_bitmaps[DIMM_DQ_MAX_DIMM_RANKS][DIMM_DQ_RANK_BITMAP_SIZE];
};


extern "C"
{

/**
 * @brief Called by dimmBadDqBitmapAccessHwp() to query ATR_VPD_DIMM_SPARE
 * and set bits for unconnected spare DRAM in caller's data.
 *
 *
 * @param[in] i_dimm      Reference to DIMM Target.
 * @param[o]  o_data      Reference to Bad DQ Bitmap set by
 *                        the caller.  Only the SPARE_DRAM_DQ_BYTE_NUMBER_INDEX
 *                        byte is modified by this function.
 *
 * @return ReturnCode
 */

fapi::ReturnCode dimmUpdateDqBitmapSpareByte(
    const fapi::Target & i_dimm,
    uint8_t (&o_data)[DIMM_DQ_MAX_DIMM_RANKS][DIMM_DQ_RANK_BITMAP_SIZE])
{
    fapi::ReturnCode l_rc;

    do
    {
        // Spare DRAM Attribute
        uint8_t l_dimmSpare = 0;
        l_rc = FAPI_ATTR_GET(ATTR_VPD_DIMM_SPARE, &i_dimm, l_dimmSpare);
        if (l_rc)
        {
            FAPI_ERR("dimmCheckSpareDram: "
                     "Error getting DRAM Spare data");
            break;
        }

        // Bitmask and beginning bit shift values for decoding
        // ATTR_VPD_DIMM_SPARE attribute as described in
        // dimm_spd_attributes.xml.
        uint8_t l_dimmMask = 0xC0;
        uint8_t l_rankBitShift = 6;

        // Iterate through each rank of this DIMM
        for (uint8_t i = 0; i < DIMM_DQ_MAX_DIMM_RANKS; i++)
        {
            // Handle spare DRAM configuration cases
            switch ((l_dimmSpare & l_dimmMask) >> l_rankBitShift)
            {
                case fapi::ENUM_ATTR_VPD_DIMM_SPARE_NO_SPARE:
                    // Set DQ bits reflecting unconnected
                    // spare DRAM in caller's data
                    o_data[i][SPARE_DRAM_DQ_BYTE_NUMBER_INDEX] = 0xFF;
                    break;

                case fapi::ENUM_ATTR_VPD_DIMM_SPARE_LOW_NIBBLE:
                    o_data[i][SPARE_DRAM_DQ_BYTE_NUMBER_INDEX] = 0x0F;
                    break;

                case fapi::ENUM_ATTR_VPD_DIMM_SPARE_HIGH_NIBBLE:
                    o_data[i][SPARE_DRAM_DQ_BYTE_NUMBER_INDEX] = 0xF0;
                    break;

                case fapi::ENUM_ATTR_VPD_DIMM_SPARE_FULL_BYTE:
                // As erroneous value will not be encountered.
                default:
                    o_data[i][SPARE_DRAM_DQ_BYTE_NUMBER_INDEX] = 0x00;
                    break;
            }

            l_dimmMask >>= 2;
            l_rankBitShift -= 2;
        }
    }while(0);
    return l_rc;
}

}

extern "C"
{

fapi::ReturnCode dimmBadDqBitmapAccessHwp(
    const fapi::Target & i_dimm,
    uint8_t (&io_data)[DIMM_DQ_MAX_DIMM_RANKS][DIMM_DQ_RANK_BITMAP_SIZE],
    const bool i_get)
{
    if (i_get)
    {
        FAPI_INF(">>dimmBadDqBitmapAccessHwp: Getting bitmap");
    }
    else
    {
        FAPI_INF(">>dimmBadDqBitmapAccessHwp: Setting bitmap");
    }

    fapi::ReturnCode l_rc;

    // Note the use of heap based arrays to avoid large stack allocations

    // Centaur DQ to DIMM Connector DQ Wiring attribute.
    uint8_t (&l_wiringData)[DIMM_DQ_NUM_DQS] =
        *(reinterpret_cast<uint8_t(*)[DIMM_DQ_NUM_DQS]>
            (new uint8_t[DIMM_DQ_NUM_DQS]));

    // DQ SPD Attribute
    uint8_t (&l_spdData)[DIMM_DQ_SPD_DATA_SIZE] =
        *(reinterpret_cast<uint8_t(*)[DIMM_DQ_SPD_DATA_SIZE]>
            (new uint8_t[DIMM_DQ_SPD_DATA_SIZE]));

    // Memory Bus Width Attribute
    uint8_t l_eccBits = 0;

    dimmBadDqDataFormat * l_pSpdData =
        reinterpret_cast<dimmBadDqDataFormat *>(l_spdData);

    // Get the Centaur DQ to DIMM Connector DQ Wiring attribute. Note that for
    // C-DIMMs, this will return a simple 1:1 mapping. This code cannot tell
    // the difference between C-DIMMs and IS-DIMMs
    do
    {
        l_rc = FAPI_ATTR_GET(ATTR_CEN_DQ_TO_DIMM_CONN_DQ,
                             &i_dimm, l_wiringData);

        if (l_rc)
        {
            FAPI_ERR("dimmBadDqBitmapAccessHwp: "
                     "Error getting wiring attribute");
            break;
        }
        if (i_get)
        {
            // Get the SPD DQ attribute
            l_rc = FAPI_ATTR_GET(ATTR_SPD_BAD_DQ_DATA, &i_dimm, l_spdData);

            if (l_rc)
            {
                FAPI_ERR("dimmBadDqBitmapAccessHwp: Error getting SPD data");
                break;
            }
            // Zero caller's data
            memset(io_data, 0, sizeof(io_data));
            // Check the magic number and version number. Note that the
            // magic number is stored in SPD in big endian format and
            // platforms of any endianness can access it
            if ((FAPI_BE32TOH(l_pSpdData->iv_magicNumber) !=
                   DIMM_BAD_DQ_MAGIC_NUMBER) ||
                (l_pSpdData->iv_version != DIMM_BAD_DQ_VERSION))
            {
                FAPI_INF("dimmBadDqBitmapAccessHwp: SPD DQ not initialized");
            }
            else
            {
                // Translate bitmap from DIMM DQ to Centaur DQ point of view
                // for each rank
                for (uint8_t i = 0; i < DIMM_DQ_MAX_DIMM_RANKS; i++)
                {
                    // Iterate through all the DQ bits in the rank
                    for (uint8_t j = 0; j < DIMM_DQ_NUM_DQS; j++)
                    {
                        // There is a byte for each 8 DQs, j/8 gives the
                        // byte number. The MSB in each byte is the lowest
                        // DQ, (0x80 >> (j % 8)) gives the bit mask
                        // corresponding to the DQ within the byte
                        if ((l_pSpdData->iv_bitmaps[i][j/8]) &
                            (0x80 >> (j % 8)))
                        {
                            // DIMM DQ bit is set in SPD data.
                            // Set Centaur DQ bit in caller's data.
                            // The wiring data maps Centaur DQ to DIMM DQ
                            // Find the Centaur DQ that maps to this DIMM DQ
                            uint8_t k = 0;
                            for (; k < DIMM_DQ_NUM_DQS; k++)
                            {
                                if (l_wiringData[k] == j)
                                {
                                    io_data[i][k/8] |= (0x80 >> (k % 8));
                                    break;
                                }
                            }

                            if (k == DIMM_DQ_NUM_DQS)
                            {
                                FAPI_INF("dimmBadDqBitmapAccessHwp: "
                                         "Centaur DQ not found for %d!",j);
                            }
                        }
                    }
                }
            }
            // Set bits for any unconnected DQs.
            // First, check ECC.
            l_rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_MEMORY_BUS_WIDTH,
                                         &i_dimm, l_eccBits);
            if (l_rc)
            {
                FAPI_ERR("dimmBadDqBitmapAccessHwp: "
                         "Error getting ECC data");
                break;
            }

            // The ATTR_SPD_MODULE_MEMORY_BUS_WIDTH contains ENUM values
            // for bus widths of 8, 16, 32, and 64 bits both with ECC
            // and without ECC.  WExx ENUMS deonote the ECC extension
            // is present, and all have bit 3 set.  Therefore,
            // it is only required to check against the WE8 = 0x08 ENUM
            // value in order to determine if ECC lines are present.

            // If ECCs are disconnected
            if (!(fapi::ENUM_ATTR_SPD_MODULE_MEMORY_BUS_WIDTH_WE8 &
                  l_eccBits))
            {
                // Iterate through each rank and set DQ bits in
                // caller's data.
                for (uint8_t i = 0; i < DIMM_DQ_MAX_DIMM_RANKS; i++)
                {
                    // Set DQ bits in caller's data
                    io_data[i][ECC_DQ_BYTE_NUMBER_INDEX] = 0xFF;
                }
            }
            // Check spare DRAM
            l_rc = dimmUpdateDqBitmapSpareByte(i_dimm, io_data);
            if (l_rc)
            {
                FAPI_ERR("dimmBadDqBitmapAccessHwp: "
                         "Error getting spare DRAM data");
                break;
            }
        }
        else
        {
            // Set up the data to write to SPD
            l_pSpdData->iv_magicNumber = FAPI_HTOBE32(DIMM_BAD_DQ_MAGIC_NUMBER);
            l_pSpdData->iv_version = DIMM_BAD_DQ_VERSION;
            l_pSpdData->iv_reserved1 = 0;
            l_pSpdData->iv_reserved2 = 0;
            l_pSpdData->iv_reserved3 = 0;
            memset(l_pSpdData->iv_bitmaps, 0, sizeof(l_pSpdData->iv_bitmaps));

            // Translate bitmap from Centaur DQ to DIMM DQ point of view for
            // each rank
            for (uint8_t i = 0; i < DIMM_DQ_MAX_DIMM_RANKS; i++)
            {
                // Iterate through all the DQ bits in the rank
                for (uint8_t j = 0; j < DIMM_DQ_NUM_DQS; j++)
                {
                    if ((io_data[i][j/8]) & (0x80 >> (j % 8)))
                    {
                        // Centaur DQ bit set in callers data.
                        // Set DIMM DQ bit in SPD data.
                        // The wiring data maps Centaur DQ to DIMM DQ
                        uint8_t dBit = l_wiringData[j];
                        l_pSpdData->iv_bitmaps[i][dBit/8] |=
                            (0x80 >> (dBit % 8));
                    }
                }
            }

            // Set the SPD DQ attribute
            l_rc = FAPI_ATTR_SET(ATTR_SPD_BAD_DQ_DATA, &i_dimm, l_spdData);

            if (l_rc)
            {
                FAPI_ERR("dimmBadDqBitmapAccessHwp: Error setting SPD data");
                break;
            }
        }
    }while(0);

    delete [] &l_wiringData;
    delete [] &l_spdData;
    FAPI_INF("<<dimmBadDqBitmapAccessHwp");
    return l_rc;
}

}
