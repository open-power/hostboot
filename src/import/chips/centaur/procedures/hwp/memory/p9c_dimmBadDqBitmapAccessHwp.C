/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_dimmBadDqBitmapAccessHwp.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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

///
/// @file p9c_dimmBadDqBitmapAccessHwp.C
/// @brief FW Team HWP that accesses the Bad DQ Bitmap.
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

#include <fapi2.H>
#include <p9c_dimmBadDqBitmapAccessHwp.H>

// DQ Data format in DIMM SPD
enum dq_data : size_t
{
    DIMM_BAD_DQ_MAGIC_NUMBER = 0xbadd4471,
    DIMM_BAD_DQ_VERSION = 1,
    ECC_DQ_BYTE_NUMBER_INDEX = 8,
    SPARE_DRAM_DQ_BYTE_NUMBER_INDEX = 9,
};

///
/// @class dimmBadDqDataFormat
/// @brief Structure that holds bad DQ data
///
struct dimmBadDqDataFormat
{
    uint32_t iv_magicNumber;
    uint8_t  iv_version;
    uint8_t  iv_reserved1;
    uint8_t  iv_reserved2;
    uint8_t  iv_reserved3;
    uint8_t  iv_bitmaps[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE];

    ///
    /// @brief default ctor
    ///
    dimmBadDqDataFormat() = default;

    ///
    /// @brief default dtor
    ///
    ~dimmBadDqDataFormat() = default;
};

extern "C"
{

    ///
    /// @brief Returns bits for unconnected spare DRAM.
    /// @param[in] i_mba Reference to MBA
    /// @param[in] i_dimm Reference to DIMM
    /// @param[out] o_spareByte Reference to the spare byte returned to caller.
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    fapi2::ReturnCode dimmGetDqBitmapSpareByte(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba,
            const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
            uint8_t (&o_spareByte)[MAX_RANKS_PER_DIMM])
    {
        // Spare DRAM Attribute: Returns spare DRAM availability for
        // all DIMMs associated with the target MBA.
        uint8_t l_mbaSpare[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {};
        uint8_t l_mbaPort = 0;
        uint8_t l_dimm = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DIMM_SPARE, i_mba,  l_mbaSpare));
        // Find the mba port this dimm is connected to
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_PORT, i_dimm,  l_mbaPort));
        // Find the dimm number associated with this dimm
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_DIMM, i_dimm,  l_dimm));

        // Iterate through each rank of this DIMM
        for (uint8_t i = 0; i < MAX_RANKS_PER_DIMM; ++i)
        {
            // Handle spare DRAM configuration cases
            switch (l_mbaSpare[l_mbaPort][l_dimm][i])
            {
                case fapi2::ENUM_ATTR_CEN_VPD_DIMM_SPARE_NO_SPARE:
                    // Set DQ bits reflecting unconnected
                    // spare DRAM in caller's data
                    o_spareByte[i] = 0xFF;
                    break;

                case fapi2::ENUM_ATTR_CEN_VPD_DIMM_SPARE_LOW_NIBBLE:
                    o_spareByte[i] = 0x0F;
                    break;

                case fapi2::ENUM_ATTR_CEN_VPD_DIMM_SPARE_HIGH_NIBBLE:
                    o_spareByte[i] = 0xF0;
                    break;

                // As erroneous value will not be encountered.
                case fapi2::ENUM_ATTR_CEN_VPD_DIMM_SPARE_FULL_BYTE:
                default:
                    o_spareByte[i] = 0x0;
                    break;
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Called by dimmBadDqBitmapAccessHwp() to query ATTR_EFF_DIMM_SPARE
    /// and set bits for unconnected spare DRAM in caller's data.
    /// @param[in] i_mba Reference to MBA Target
    /// @param[in] i_dimm Reference to DIMM Target
    /// @param[out]  o_data Reference to Bad DQ Bitmap set by
    ///                   the caller.  Only the SPARE_DRAM_DQ_BYTE_NUMBER_INDEX
    ///                   byte is modified by this function.
    /// @return FAPI2_RC_SUCCESS iff okay
    ///

    fapi2::ReturnCode dimmUpdateDqBitmapSpareByte(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba,
            const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
            uint8_t (&o_data)[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE])
    {

        uint8_t spareByte[MAX_RANKS_PER_DIMM] = {};
        memset(spareByte, 0, sizeof(spareByte));

        FAPI_TRY(dimmGetDqBitmapSpareByte(i_mba, i_dimm, spareByte));

        for (uint32_t i = 0; i < MAX_RANKS_PER_DIMM; ++i)
        {
            o_data[i][SPARE_DRAM_DQ_BYTE_NUMBER_INDEX] |= spareByte[i];
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Called by dimmBadDqBitmapAccessHwp() to query
    /// ATTR_SPD_MODULE_MEMORY_BUS_WIDTH in order to determine
    /// ECC support for this DIMM.  This function will set
    /// bits in the caller's data if ECC lines are not present.
    /// @param[in] i_dimm Reference to DIMM Target<fapi2::TARGET_TYPE_MBA>.
    /// @param[out] o_data Reference to Bad DQ Bitmap set by
    ///                   the caller.  Only the ECC_DQ_BYTE_NUMBER_INDEX
    ///                    byte is modified by this function.
    /// @return FAPI2_RC_SUCCESS iff okay
    ////
    fapi2::ReturnCode dimmUpdateDqBitmapEccByte( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
            uint8_t (&o_data)[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE])
    {
        // Memory Bus Width Attribute
        uint8_t l_eccBits = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_MODULE_MEMORY_BUS_WIDTH, i_dimm, l_eccBits));

        // The ATTR_SPD_MODULE_MEMORY_BUS_WIDTH contains ENUM values
        // for bus widths of 8, 16, 32, and 64 bits both with ECC
        // and without ECC.  WExx ENUMS deonote the ECC extension
        // is present, and all have bit 3 set.  Therefore,
        // it is only required to check against the WE8 = 0x08 ENUM
        // value in order to determine if ECC lines are present.

        // If ECCs are disconnected
        if (!(fapi2::ENUM_ATTR_CEN_SPD_MODULE_MEMORY_BUS_WIDTH_WE8 & l_eccBits))
        {
            // Iterate through each rank and set DQ bits in
            // caller's data.
            for (uint8_t i = 0; i < MAX_RANKS_PER_DIMM; ++i)
            {
                // Set DQ bits in caller's data
                o_data[i][ECC_DQ_BYTE_NUMBER_INDEX] = 0xFF;
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Called by dimmBadDqBitmapAccessHwp() to query ATTR_SPD_BAD_DQ_DATA
    /// @param[in] i_mba Reference to MBA Target
    /// @param[in] i_dimm Reference to DIMM Target
    /// @param[out] o_data Reference to Bad DQ Bitmap set by this function
    /// @param[in] i_wiringData Reference to Centaur DQ to DIMM Connector DQ Wiring attribute.
    /// @param[in] i_allMnfgFlags Manufacturing flags bitmap
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    fapi2::ReturnCode dimmBadDqBitmapGet(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba,
                                         const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
                                         uint8_t (&o_data)[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE],
                                         const uint8_t (&i_wiringData)[DIMM_DQ_NUM_DQS],
                                         const uint64_t i_allMnfgFlags)
    {

        // DQ SPD Attribute
        uint8_t (&l_spdData)[DIMM_DQ_SPD_DATA_SIZE] =
            *(reinterpret_cast<uint8_t(*)[DIMM_DQ_SPD_DATA_SIZE]>(new uint8_t[DIMM_DQ_SPD_DATA_SIZE]()));

        // memset to avoid known syntax issue with previous compiler versions
        // and ensure zero initialized array.
        memset(l_spdData, 0, sizeof(l_spdData));

        dimmBadDqDataFormat* l_pSpdData = reinterpret_cast<dimmBadDqDataFormat*>(l_spdData);

        // Pointer which will be used to initialize a clean bitmap during
        // manufacturing mode
        uint8_t (*l_pBuf)[DIMM_DQ_RANK_BITMAP_SIZE] = nullptr;

        // Get the SPD DQ attribute
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_BAD_DQ_DATA, i_dimm,  l_spdData));

        // Zero caller's data
        memset(o_data, 0, sizeof(o_data));

        // Check the magic number and version number. Note that the
        // magic number is stored in SPD in big endian format and
        // platforms of any endianness can access it
        if ((be32toh(l_pSpdData->iv_magicNumber) != DIMM_BAD_DQ_MAGIC_NUMBER) ||
            (l_pSpdData->iv_version != DIMM_BAD_DQ_VERSION))
        {
            FAPI_INF("SPD DQ not initialized");
        }
        else
        {
            // Translate bitmap from DIMM DQ to Centaur DQ point of view
            // for each rank
            for (uint8_t i = 0; i < MAX_RANKS_PER_DIMM; ++i)
            {
                // Iterate through all the DQ bits in the rank
                for (uint8_t j = 0; j < DIMM_DQ_NUM_DQS; ++j)
                {
                    // There is a byte for each 8 DQs, j/8 gives the
                    // byte number. The MSB in each byte is the lowest
                    // DQ, (0x80 >> (j % 8)) gives the bit mask
                    // corresponding to the DQ within the byte
                    const size_t BYTE_NUM = j / 8;
                    const size_t DQ_BIT_MASK = 0x80 >> (j % 8);

                    if ((l_pSpdData->iv_bitmaps[i][BYTE_NUM]) & DQ_BIT_MASK)
                    {
                        // DIMM DQ bit is set in SPD data.
                        // Set Centaur DQ bit in caller's data.
                        // The wiring data maps Centaur DQ to DIMM DQ
                        // Find the Centaur DQ that maps to this DIMM DQ
                        uint8_t k = 0;

                        for (; k < DIMM_DQ_NUM_DQS; ++k)
                        {
                            if (i_wiringData[k] == j)
                            {
                                o_data[i][k / 8] |= (0x80 >> (k % 8));
                                break;
                            }
                        }

                        if (k == DIMM_DQ_NUM_DQS)
                        {
                            FAPI_INF("Centaur DQ not found for %d!", j);
                        }
                    }
                }// DIMM_DQ_NUM_DQS
            } // MAX_RANKS_PER_DIMM
        }// end else

        // Set bits for any unconnected DQs.
        // First, check ECC.
        FAPI_TRY(dimmUpdateDqBitmapEccByte(i_dimm, o_data));

        // Check spare DRAM
        FAPI_TRY(dimmUpdateDqBitmapSpareByte(i_mba, i_dimm, o_data));

        // If system is in DISABLE_DRAM_REPAIRS mode
        if (i_allMnfgFlags & fapi2::ENUM_ATTR_MNFG_FLAGS_MNFG_DISABLE_DRAM_REPAIRS)
        {
            // Create a local zero-initialized bad dq bitmap
            l_pBuf = new uint8_t[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE]();

            uint8_t (&l_data)[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE] =
                *(reinterpret_cast<uint8_t(*)[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE]>(l_pBuf));

            // memset to avoid known syntax issue with previous
            // compiler versions and ensure zero initialized array.
            memset(l_data, 0, sizeof(l_data));

            // Check ECC.
            FAPI_TRY(dimmUpdateDqBitmapEccByte(i_dimm, l_data));
            // Check spare DRAM
            FAPI_TRY(dimmUpdateDqBitmapSpareByte(i_mba, i_dimm, l_data));

            // Compare l_data, which represents a bad dq bitmap with the
            // appropriate spare/ECC bits set (if any) and all other DQ
            // lines functional, to caller's o_data.
            // If discrepancies are found, we know this is the result of
            // a manufacturing mode process and these bits should not be
            // recorded.
            for (uint8_t i = 0; i < MAX_RANKS_PER_DIMM; ++i)
            {
                for (uint8_t j = 0; j < (DIMM_DQ_RANK_BITMAP_SIZE); ++j)
                {
                    // Create and log fapi2 error if discrepancies were found
                    // Get this DIMM's position
                    uint32_t l_dimm_pos = 0;
                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POS, i_dimm,  l_dimm_pos));

                    FAPI_ASSERT_NOEXIT(o_data[i][j] != l_data[i][j],
                                       fapi2::CEN_BAD_DQ_MFG_MODE_BITS_FOUND_DURING_GET().
                                       set_CLEAN_BAD_DQ_BITMAP_RANK0(l_data[0][j]).
                                       set_CLEAN_BAD_DQ_BITMAP_RANK1(l_data[1][j]).
                                       set_CLEAN_BAD_DQ_BITMAP_RANK2(l_data[2][j]).
                                       set_CLEAN_BAD_DQ_BITMAP_RANK3(l_data[3][j]).
                                       set_CURRENT_BAD_DQ_BITMAP_RANK0(o_data[0][j]).
                                       set_CURRENT_BAD_DQ_BITMAP_RANK1(o_data[1][j]).
                                       set_CURRENT_BAD_DQ_BITMAP_RANK2(o_data[2][j]).
                                       set_CURRENT_BAD_DQ_BITMAP_RANK3(o_data[3][j]).
                                       set_DIMM(i_dimm),
                                       "Read requested while in DISABLE_DRAM_REPAIRS mode found"
                                       " extra bad bits set for rank:%d, DQ rank bitmap num:%d, DIMM pos: %d",
                                       i, j, l_dimm_pos);
                }// bitmap size
            }// ranks

            // correct the output bit map
            for (uint8_t i = 0; i < MAX_RANKS_PER_DIMM; ++i)
            {
                for (uint8_t j = 0; j < (DIMM_DQ_RANK_BITMAP_SIZE); ++j)
                {
                    o_data[i][j] = l_data[i][j];
                }
            }// end for
        }

        delete [] &l_spdData;
        delete [] l_pBuf;

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Called by dimmBadDqBitmapAccessHwp() to set ATTR_SPD_BAD_DQ_DATA
    /// Also checks if a bad Dq bit is set by first calling dimmBadDqBitmapGet()
    /// and sets ATTR_RECONFIGURE_LOOP with the 'OR' of the current value and
    /// the fapi2 enum BAD_DQ_BIT_SET if appropriate
    /// @param[in] i_mba Reference to MBA Target<fapi2::TARGET_TYPE_MBA>.
    /// @param[in] i_dimm Reference to DIMM Target<fapi2::TARGET_TYPE_MBA>.
    /// @param[in] i_data Reference to Bad DQ Bitmap set by the caller
    /// @param[in] i_wiringData Reference to Centaur DQ to DIMM Connector DQ Wiring attribute.
    /// @param[in] i_allMnfgFlags Manufacturing flags bitmap
    /// @return FAPI2_RC_SUCCESS
    ///

    fapi2::ReturnCode dimmBadDqBitmapSet( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba,
                                          const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
                                          const uint8_t (&i_data)[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE],
                                          const uint8_t (&i_wiringData)[DIMM_DQ_NUM_DQS],
                                          const uint64_t i_allMnfgFlags)
    {
        // Read current BadDqBitmap into l_prev_data
        uint8_t l_prev_data[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE] = {};
        bool badDQSet = false;

        // DQ SPD Attribute
        uint8_t (&l_spdData)[DIMM_DQ_SPD_DATA_SIZE] =
            *(reinterpret_cast<uint8_t(*)[DIMM_DQ_SPD_DATA_SIZE]>
              (new uint8_t[DIMM_DQ_SPD_DATA_SIZE]()));

        fapi2::ATTR_RECONFIGURE_LOOP_Type l_reconfigAttr = 0;
        dimmBadDqDataFormat* l_pSpdData = reinterpret_cast<dimmBadDqDataFormat*>(l_spdData);

        // Pointer which will be used to initialize a clean bitmap during
        // manufacturing mode
        uint8_t (*l_pBuf)[DIMM_DQ_RANK_BITMAP_SIZE] = nullptr;
        uint8_t spareByte[MAX_RANKS_PER_DIMM] = {};

        FAPI_TRY(dimmBadDqBitmapGet(i_mba, i_dimm, l_prev_data, i_wiringData, i_allMnfgFlags));

        // Check if Bad DQ bit set
        for (uint8_t i = 0; i < MAX_RANKS_PER_DIMM; ++i)
        {
            for (uint8_t j = 0; j < (DIMM_DQ_RANK_BITMAP_SIZE); ++j)
            {
                if (i_data[i][j] != l_prev_data[i][j])
                {
                    badDQSet = true;
                    break;
                }
            }

            if (badDQSet)
            {
                break;
            }
        }

        // Set ATTR_RECONFIGURE_LOOP to indicate a bad DqBitMap was set
        if (badDQSet)
        {
            FAPI_INF("Reconfigure needed, Bad DQ set");

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_RECONFIGURE_LOOP, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_reconfigAttr));

            // 'OR' values in case of multiple reasons for reconfigure
            l_reconfigAttr |= fapi2::ENUM_ATTR_RECONFIGURE_LOOP_BAD_DQ_BIT_SET;

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_RECONFIGURE_LOOP, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_reconfigAttr));
        }

        // memset to avoid known syntax issue with previous compiler versions
        // and ensure zero initialized array.
        memset(l_spdData, 0, sizeof(l_spdData));

        // If system is in DISABLE_DRAM_REPAIRS mode
        if (i_allMnfgFlags & fapi2::ENUM_ATTR_MNFG_FLAGS_MNFG_DISABLE_DRAM_REPAIRS)
        {
            // Create a local zero-initialized bad dq bitmap
            l_pBuf = new uint8_t[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE]();

            uint8_t (&l_data)[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE] =
                *(reinterpret_cast<uint8_t(*)[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE]>(l_pBuf));

            // memset to avoid known syntax issue with previous
            // compiler versions and ensure zero initialized array.
            memset(l_data, 0, sizeof(l_data));

            // Check ECC.
            FAPI_TRY(dimmUpdateDqBitmapEccByte(i_dimm, l_data));
            // Check spare DRAM
            FAPI_TRY(dimmUpdateDqBitmapSpareByte(i_mba, i_dimm, l_data));

            // Compare l_data, which represents a bad dq bitmap with the
            // appropriate spare/ECC bits set (if any) and all other DQ
            // lines functional, to caller's i_data.
            // If discrepancies are found, we know this is the result of
            // a manufacturing mode process and these bits should not be
            // recorded.
            for (uint8_t i = 0; i < MAX_RANKS_PER_DIMM; ++i)
            {
                for (uint8_t j = 0; j < (DIMM_DQ_RANK_BITMAP_SIZE); ++j)
                {
                    // Create and log fapi2 error if discrepancies were found
                    // Get this DIMM's position
                    uint32_t l_dimm_pos = 0;
                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POS, i_dimm,  l_dimm_pos));

                    FAPI_ASSERT(i_data[i][j] != l_data[i][j],
                                fapi2::CEN_BAD_DQ_MFG_MODE_BITS_FOUND_DURING_SET().
                                set_CLEAN_BAD_DQ_BITMAP_RANK0(l_data[0][j]).
                                set_CLEAN_BAD_DQ_BITMAP_RANK1(l_data[1][j]).
                                set_CLEAN_BAD_DQ_BITMAP_RANK2(l_data[2][j]).
                                set_CLEAN_BAD_DQ_BITMAP_RANK3(l_data[3][j]).
                                set_UPDATE_BAD_DQ_BITMAP_RANK0(i_data[0][j]).
                                set_UPDATE_BAD_DQ_BITMAP_RANK1(i_data[1][j]).
                                set_UPDATE_BAD_DQ_BITMAP_RANK2(i_data[2][j]).
                                set_UPDATE_BAD_DQ_BITMAP_RANK3(i_data[3][j]).
                                set_DIMM(i_dimm),
                                "Write requested while in DISABLE_DRAM_REPAIRS mode"
                                " extra bad bits set for rank:%d, DQ rank bitmap num:%d, DIMM pos: %d",
                                i, j, l_dimm_pos);
                }
            }
        }

        // Set up the data to write to SPD
        l_pSpdData->iv_magicNumber = htobe32(DIMM_BAD_DQ_MAGIC_NUMBER);
        l_pSpdData->iv_version = DIMM_BAD_DQ_VERSION;
        l_pSpdData->iv_reserved1 = 0;
        l_pSpdData->iv_reserved2 = 0;
        l_pSpdData->iv_reserved3 = 0;
        memset(l_pSpdData->iv_bitmaps, 0, sizeof(l_pSpdData->iv_bitmaps));

        // Get the spare byte
        memset(spareByte, 0, sizeof(spareByte));

        FAPI_TRY(dimmGetDqBitmapSpareByte(i_mba, i_dimm, spareByte));

        // Translate bitmap from Centaur DQ to DIMM DQ point of view for
        // each rank
        for (uint8_t i = 0; i < MAX_RANKS_PER_DIMM; ++i)
        {
            // Iterate through all the DQ bits in the rank
            for (uint8_t j = 0; j < DIMM_DQ_NUM_DQS; ++j)
            {
                const size_t BYTE_NUM = j / 8;
                const size_t DQ_BIT_MASK = 0x80 >> (j % 8);

                if ((BYTE_NUM) == SPARE_DRAM_DQ_BYTE_NUMBER_INDEX)
                {
                    // The spareByte can be one of: 0x00 0x0F 0xF0 0xFF
                    // If a bit is set, then that spare is unconnected
                    // so continue to the next num_dqs, do not translate
                    if (spareByte[i] & DQ_BIT_MASK)
                    {
                        continue;
                    }
                }

                if ((i_data[i][BYTE_NUM]) & DQ_BIT_MASK)
                {
                    // Centaur DQ bit set in callers data.
                    // Set DIMM DQ bit in SPD data.
                    // The wiring data maps Centaur DQ to DIMM DQ
                    uint8_t dBit = i_wiringData[j];
                    l_pSpdData->iv_bitmaps[i][dBit / 8] |= (0x80 >> (dBit % 8));
                }
            }// dq
        }// ranks

        // Set the SPD DQ attribute
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_BAD_DQ_DATA, i_dimm, l_spdData));

    fapi_try_exit:
        delete [] &l_spdData;
        delete [] l_pBuf;

        return fapi2::current_err;
    }

    /// @brief FW Team HWP that accesses the Bad DQ Bitmap.
    ///        It accesses the raw data from DIMM SPD and does
    ///        any necessary processing to turn it into a
    ///        bitmap from a Centaur DQ point of view. If the data in SPD is not
    ///        valid then it has never been written and all zeroes are returned (no
    ///        bad DQs).
    ///
    /// This HWP should be called by HWP/PLAT code to access the BAD DQ Bitmap
    ///
    /// @param[in] i_mba Reference to MBA Target
    /// @param[in] i_dimm Reference to DIMM Target
    /// @param[in,out] io_data Reference to bad DQ bitmap data for the DIMM.
    /// @param[in] i_get True if getting DQ Bitmap data. False if setting data.
    /// @return FAPI2_RC_SUCCESS iff okay
    /// @note that the MSB of each byte corresponds to the lowest DQ.
    /// if (data[1][0] == 0x80) then rank 1, Centaur DQ0 is bad
    /// if (data[1][0] == 0x40) then rank 1, Centaur DQ1 is bad
    /// if (data[1][1] == 0x20) then rank 1, Centaur DQ10 is bad
    ///
    fapi2::ReturnCode dimmBadDqBitmapAccessHwp(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba,
            const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
            uint8_t (&io_data)[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE],
            const bool i_get)
    {
        // Note the use of heap based arrays to avoid large stack allocations
        // Centaur DQ to DIMM Connector DQ Wiring attribute.
        uint8_t (&l_wiringData)[DIMM_DQ_NUM_DQS] =
            *(reinterpret_cast<uint8_t(*)[DIMM_DQ_NUM_DQS]>
              (new uint8_t[DIMM_DQ_NUM_DQS]()));

        // memset to avoid known syntax issue with previous compiler versions
        // and ensure zero initialized array.
        memset(l_wiringData, 0, sizeof(l_wiringData));

        // Manufacturing flags attribute
        uint64_t l_allMnfgFlags = 0;

        // Get the manufacturing flags bitmap to be used in both get and set
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MNFG_FLAGS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_allMnfgFlags));

        // Get the Centaur DQ to DIMM Connector DQ Wiring attribute.
        // Note that for C-DIMMs, this will return a simple 1:1 mapping.
        // This code cannot tell the difference between C-DIMMs and IS-DIMMs.
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_DQ_TO_DIMM_CONN_DQ,
                               i_dimm, l_wiringData));

        if (i_get)
        {
            FAPI_INF("Getting bitmap");
            FAPI_TRY(dimmBadDqBitmapGet(i_mba, i_dimm, io_data, l_wiringData, l_allMnfgFlags));
        }
        else
        {
            FAPI_INF("Setting bitmap");
            FAPI_TRY(dimmBadDqBitmapSet(i_mba, i_dimm, io_data, l_wiringData, l_allMnfgFlags));
        }

    fapi_try_exit:
        delete [] &l_wiringData;
        FAPI_DBG("End");

        return fapi2::current_err;
    }

}// extern C
