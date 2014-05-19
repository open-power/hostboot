/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenDqBitmap.H $     */
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

/** @file  prdfCenDqBitmap.H */

#ifndef __prdfCenDqBitmap_H
#define __prdfCenDqBitmap_H

#include <prdfPlatServices.H>

#include <prdfCenAddress.H>
#include <prdfCenConst.H>

namespace PRDF
{

class CaptureData;

/**
 * @brief Container for DIMM's Centaur DQ bitmap.
 */
class CenDqBitmap
{
  private: // enums, constants

    enum
    {
        DRAM_SPARE_BYTE = 9, // Same byte for both ports.

        ECC_SPARE_BYTE  = 8, // ECC spare is on second nibble of this byte.
        ECC_SPARE_PORT  = 1, // Only on port 1.
    };

  public: // constructors

    /** @brief Default constructor */
    CenDqBitmap()
    {
        memset( iv_data, 0x00, sizeof(iv_data) );
    }

    /** @brief Constructor from components */
    CenDqBitmap( TARGETING::TargetHandle_t i_mba, const CenRank & i_rank,
           const uint8_t (&i_d)[PORT_SLCT_PER_MBA][DIMM_DQ_RANK_BITMAP_SIZE] ) :
        iv_mba(i_mba), iv_rank(i_rank),
        iv_x4Dram(PlatServices::isDramWidthX4(i_mba))
    {
        memcpy( iv_data, i_d, sizeof(iv_data) );
    }

  public: // functions

    /**
     * @brief  Queries if there are any bad DQs present on either port.
     * @return TRUE if any bad DQs present.
     */
    bool badDqs() const;

    /**
     * @brief  Queries the given port to determine if there are any bad DQs
     *         present.
     * @param  i_portSlct The target port.
     * @param  o_badDqs   TRUE if there are bad DQS present the given port,
     *                    FALSE otherwise.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t badDqs( uint8_t i_portSlct, bool & o_badDqs ) const;

    /**
     * @brief  Sets the specified Centaur DQ.
     * @param  i_dq       The target Centaur DQ.
     * @param  i_portSlct The target port.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t setDq( uint8_t i_dq, uint8_t i_portSlct );

    /**
     * @brief  Sets the specified symbol.
     * @note   Will adjust for DRAM or ECC spares, if applicable.
     * @param  i_symbol The target symbol.
     * @param  i_pins   Optional 2-bit value of the symbol's pins. The default
     *                  is to set both pins.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t setSymbol( const CenSymbol & i_symbol, uint8_t i_pins = 0x3 );

    /**
     * @brief  Sets the specified DRAM.
     * @note   Will adjust for DRAM or ECC spares, if applicable.
     * @param  i_symbol A symbol on the target DRAM.
     * @param  i_pins   Optional 8-bit (x8 mode) or 4-bit (x4 mode) value of the
     *                  DRAM's pins. The default is to set all pins.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t setDram( const CenSymbol & i_symbol, uint8_t i_pins = 0xff );

    /**
     * @brief  Checks if chip mark is present on specified DRAM.
     * @note   Will adjust for DRAM or ECC spares, if applicable.
     * @param  i_symbol A symbol on the target DRAM.
     * @param  o_cm     True if chip mark is present false otherwise.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t isChipMark( const CenSymbol & i_symbol, bool & o_cm );

    /**
     * @brief  Sets the DRAM spare on the specified port.
     * @param  i_portSlct The target port.
     * @param  i_pins     Optional 8-bit (x8 mode) or 4-bit (x4 mode) value of
     *                    the DRAM's pins. The default is to set all pins.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t setDramSpare( uint8_t i_portSlct, uint8_t i_pins = 0xff );

    /**
     * @brief  Sets the ECC spare on the specified port (x4 mode only).
     * @param  i_pins     Optional 4-bit value of the DRAM's pins.
     *                    The default is to set all pins.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t setEccSpare( uint8_t i_pins = 0xf );

    /**
     * @brief  Queries for DRAM spare status.
     * @param  i_portSlct  The target port.
     * @param  o_available TRUE if the spare is available, FALSE if it is used.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t isDramSpareAvailable( uint8_t i_portSlct, bool & o_available );

    /**
     * @brief Adds the bitmaps for both ports to the capture data.
     * @param o_cd Capture data struct.
     */
    void getCaptureData( CaptureData & o_cd ) const;

    /** @return A reference to the data array. */
    const uint8_t (&getData()const)[PORT_SLCT_PER_MBA][DIMM_DQ_RANK_BITMAP_SIZE]
    {
        return iv_data;
    }

  public: // functions

    /**
     * @brief  Support function to calculate the port select, byte index, and
     *         bit index based on the given symbol.
     * @note   Will adjust the indexes for DRAM or ECC spares, if applicable.
     * @param  i_symbol   The target symbol.
     * @param  o_portSlct The port select (0-1).
     * @param  o_byteIdx  The byte index of the symbol (0-9).
     * @param  o_bitIdx   The bit index of the symbol (0,2,4,6).
     * @return Non-SUCCESS if the symbol is invalid, SUCCESS otherwise.
     */
    int32_t getPortByteBitIdx( const CenSymbol & i_symbol, uint8_t & o_portSlct,
                               uint8_t & o_byteIdx, uint8_t & o_bitIdx ) const;

  private: // instance variables

    TARGETING::TargetHandle_t iv_mba; ///< Target MBA
    CenRank iv_rank;                  ///< Target rank
    bool iv_x4Dram;                   ///< TRUE if iv_mba uses x4 DRAMs

    /** A bitmap of all bad DQs for each port. */
    uint8_t iv_data[PORT_SLCT_PER_MBA][DIMM_DQ_RANK_BITMAP_SIZE];
};

} // end namespace PRDF

#endif // __prdfCenDqBitmap_H

