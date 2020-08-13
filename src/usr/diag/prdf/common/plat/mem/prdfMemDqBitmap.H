/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemDqBitmap.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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

/** @file  prdfMemDqBitmap.H */

#ifndef __prdfMemDqBitmap_H
#define __prdfMemDqBitmap_H

#include <map>

#include <prdfPlatServices.H>

#include <prdfMemAddress.H>
#include <prdfMemSymbol.H>
#include <prdfMemConst.H>
#include <prdfParserEnums.H>

namespace PRDF
{

class CaptureData;
class MemSymbol;

struct data
{
    uint8_t bitmap[DQ_BITMAP::BITMAP_SIZE];
};
// Map from port (uint8_t) to the bitmap data (uint8_t[DQ_BITMAP::BITMAP_SIZE])
typedef std::map<uint8_t, data> BitmapData;

/**
 * @brief Container for DIMM's DQ bitmap.
 */
class MemDqBitmap
{
  private: // enums, constants

    enum
    {
        ECC_SPARE_BYTE  = 8, // ECC spare is on second nibble of this byte.
        ECC_SPARE_PORT  = 1, // Only on port 1.
    };

  public: // constructors

    /** @brief Default constructor */
    MemDqBitmap() {}

    /** @brief Constructor from components */
    MemDqBitmap( TARGETING::TargetHandle_t i_trgt, const MemRank & i_rank,
                 BitmapData i_d ) : iv_trgt(i_trgt), iv_rank(i_rank),
                 iv_x4Dram(true), iv_data(i_d)
    {
        if ( TARGETING::TYPE_MEM_PORT == PlatServices::getTargetType(iv_trgt) ||
             TARGETING::TYPE_OCMB_CHIP ==
                  PlatServices::getTargetType(iv_trgt) )
        {
            iv_spareByte = 5;
            // TODO RTC 210072 - Support multiple ports
            TARGETING::TargetHandle_t dimm =
                PlatServices::getConnectedDimm( iv_trgt, iv_rank );
            iv_x4Dram = PlatServices::isDramWidthX4( dimm );
        }
        else
        {
            iv_spareByte = 9;
            iv_x4Dram = PlatServices::isDramWidthX4( iv_trgt );
        }
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
     * @param  i_portSlct The optional target port. The default is port 0.
     * @param  o_badDqs   TRUE if there are bad DQS present the given port,
     *                    FALSE otherwise.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    uint32_t badDqs( bool & o_badDqs, uint8_t i_portSlct = 0 ) const;

    /**
     * @brief  Sets the specified DQ.
     * @param  i_dq       The target DQ.
     * @param  i_portSlct The optional target port. The default is port 0.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    uint32_t setDq( uint8_t i_dq, uint8_t i_portSlct = 0 );

    /**
     * @brief  Sets the specified symbol.
     * @note   Will adjust for DRAM or ECC spares, if applicable.
     * @param  i_symbol The target symbol.
     * @param  i_pins   Optional 2-bit value of the symbol's pins. The default
     *                  is to set both pins.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    uint32_t setSymbol( const MemSymbol & i_symbol, uint8_t i_pins = 0x3 );

    /**
     * @brief  Sets the specified DRAM.
     * @note   Will adjust for DRAM or ECC spares, if applicable.
     * @param  i_symbol A symbol on the target DRAM.
     * @param  i_pins   Optional 8-bit (x8 mode) or 4-bit (x4 mode) value of the
     *                  DRAM's pins. The default is to set all pins.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    uint32_t setDram( const MemSymbol & i_symbol, uint8_t i_pins = 0xff );

    /**
     * @brief  Clears the specified DRAM.
     * @note   Will adjust for DRAM or ECC spares, if applicable.
     * @param  i_symbol A symbol on the target DRAM.
     * @param  i_pins   Optional 8-bit (x8 mode) or 4-bit (x4 mode) value of the
     *                  DRAM's pins. The default is to clear all pins.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    uint32_t clearDram( const MemSymbol & i_symbol, uint8_t i_pins = 0xff );

    /**
     * @brief Clears the entire bitmap.
     */
    void clearBitmap();

    /**
     * @brief Adds the bitmaps for both ports to the capture data.
     * @param o_cd Capture data struct.
     */
    void getCaptureData( CaptureData & o_cd ) const;

    /** @return The bitmap data. */
    const BitmapData & getData() const
    {
        return iv_data;
    }

    /**
     * @brief  Gets the bitmap data for a specified port.
     * @param  i_ps The port select.
     * @return A reference to the bitmap data at a certain port.
     */
    const uint8_t (&getData(uint8_t i_ps)const)[DQ_BITMAP::BITMAP_SIZE]
    {
        return iv_data.at(i_ps).bitmap;
    }

    /** @return The size of the data map, ie how many ports there are */
    const size_t getNumPorts() const
    {
        return iv_data.size();
    }

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
    uint32_t getPortByteBitIdx(const MemSymbol & i_symbol, uint8_t & o_portSlct,
                               uint8_t & o_byteIdx, uint8_t & o_bitIdx) const;

    /**
     * @brief  Checks if chip mark is present on specified DRAM.
     * @note   Will adjust for DRAM or ECC spares, if applicable.
     * @param  i_symbol A symbol on the target DRAM.
     * @param  o_cm     True if chip mark is present false otherwise.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    uint32_t isChipMark( const MemSymbol & i_symbol, bool & o_cm );

    /**
     * @brief  Returns a list of all active (non-zero) symbols.
     * @param  i_portSlct The port select. Default is 0. Only needed for MBA.
     * @return Vector of all active symbols.
     */
    std::vector<MemSymbol> getSymbolList( uint8_t i_portSlct = 0 );


    /**
     * @brief  Queries for DRAM spare status.
     * @param  i_portSlct  The target port.
     * @param  o_dramSpare TRUE if the DRAM spare is available, FALSE otherwise.
     * @param  o_eccSpare  TRUE if the ECC spare is available, FALSE otherwise.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    uint32_t isSpareAvailable( uint8_t i_portSlct,
                               bool & o_dramSpare, bool & o_eccSpare );

    /**
     * @brief  Sets the ECC spare on the specified port (x4 mode only).
     * @param  i_pins     Optional 4-bit value of the DRAM's pins.
     *                    The default is to set all pins.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    uint32_t setEccSpare( uint8_t i_pins = 0x0f );

    /**
     * @brief  Sets the DRAM spare on the specified port.
     * @param  i_portSlct The target port.
     * @param  i_pins     Optional 8-bit (x8 mode) or 4-bit (x4 mode) value of
     *                    the DRAM's pins. The default is to set all pins.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    uint32_t setDramSpare( uint8_t i_portSlct, uint8_t i_pins = 0xff );


  private: // instance variables

    TARGETING::TargetHandle_t iv_trgt; ///< Target MBA/MCA/MEM_PORT/OCMB_CHIP
    MemRank iv_rank;                   ///< Target rank
    bool iv_x4Dram;                    ///< TRUE if iv_trgt uses x4 DRAMs
    uint8_t iv_spareByte;              ///< Specifies the spare byte location

    /** A bitmap of all bad DQs for each port. */
    BitmapData iv_data;
};

//##############################################################################
//                              Utility Functions
//##############################################################################

/**
 * @brief  Sets the inputted dram in DRAM repairs VPD.
 * @param  i_trgt MBA, MCA, MEM_PORT, or OCMB chip.
 * @param  i_rank Target rank.
 * @return Non-SUCCESS if an internal function fails. SUCCESS otherwise.
 */
uint32_t setDramInVpd( TARGETING::TargetHandle_t i_trgt, const MemRank & i_rank,
                       MemSymbol i_symbol );

/**
 * @brief  Clears the inputted dram in DRAM repairs VPD.
 * @param  i_trgt MBA, MCA, MEM_PORT, or OCMB chip.
 * @param  i_rank Target rank.
 * @return Non-SUCCESS if an internal function fails. SUCCESS otherwise.
 */
uint32_t clearDramInVpd( TARGETING::TargetHandle_t i_trgt,
                         const MemRank & i_rank,
                         MemSymbol i_symbol );

} // end namespace PRDF

#endif // __prdfMemDqBitmap_H

