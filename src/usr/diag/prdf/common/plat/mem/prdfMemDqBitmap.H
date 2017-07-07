/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemDqBitmap.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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

#include <prdfPlatServices.H>

#include <prdfMemAddress.H>
#include <prdfMemSymbol.H>
#include <prdfMemConst.H>
#include <prdfParserEnums.H>

namespace PRDF
{

class CaptureData;
class MemSymbol;

enum DIMMS_PER_RANK : uint8_t
{
    MCA = MCA_DIMMS_PER_RANK,
    MBA = MBA_DIMMS_PER_RANK,
};

/**
 * @brief Container for DIMM's DQ bitmap.
 */
template <DIMMS_PER_RANK T>
class MemDqBitmap
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
    MemDqBitmap()
    {
        memset( iv_data, 0x00, sizeof(iv_data) );
    }

    /** @brief Constructor from components */
    MemDqBitmap( TARGETING::TargetHandle_t i_trgt, const MemRank & i_rank,
                 const uint8_t (&i_d)[T][DQ_BITMAP::BITMAP_SIZE] ) :
        iv_trgt(i_trgt), iv_rank(i_rank),
        iv_x4Dram(PlatServices::isDramWidthX4(i_trgt))
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
     * @param  i_portSlct The optional target port. The default is port 0.
     * @param  o_badDqs   TRUE if there are bad DQS present the given port,
     *                    FALSE otherwise.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t badDqs( bool & o_badDqs, uint8_t i_portSlct = 0 ) const;

    /**
     * @brief  Sets the specified DQ.
     * @param  i_dq       The target DQ.
     * @param  i_portSlct The optional target port. The default is port 0.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t setDq( uint8_t i_dq, uint8_t i_portSlct = 0 );

    /**
     * @brief  Sets the specified symbol.
     * @note   Will adjust for DRAM or ECC spares, if applicable.
     * @param  i_symbol The target symbol.
     * @param  i_pins   Optional 2-bit value of the symbol's pins. The default
     *                  is to set both pins.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t setSymbol( const MemSymbol & i_symbol, uint8_t i_pins = 0x3 );

    /**
     * @brief  Sets the specified DRAM.
     * @note   Will adjust for DRAM or ECC spares, if applicable.
     * @param  i_symbol A symbol on the target DRAM.
     * @param  i_pins   Optional 8-bit (x8 mode) or 4-bit (x4 mode) value of the
     *                  DRAM's pins. The default is to set all pins.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t setDram( const MemSymbol & i_symbol, uint8_t i_pins = 0xff );

    /**
     * @brief Adds the bitmaps for both ports to the capture data.
     * @param o_cd Capture data struct.
     */
    void getCaptureData( CaptureData & o_cd ) const;

    /** @return A reference to the data array. */
    const uint8_t (&getData()const)[T][DQ_BITMAP::BITMAP_SIZE]
    {
        return iv_data;
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
    int32_t getPortByteBitIdx( const MemSymbol & i_symbol, uint8_t & o_portSlct,
                               uint8_t & o_byteIdx, uint8_t & o_bitIdx ) const;

    /**
     * @brief  Returns a list of all active (non-zero) symbols.
     * @param  i_portSlct The port select. Default is 0. Only needed for MBA.
     * @return Vector of all active symbols.
     */
    std::vector<MemSymbol> getSymbolList( uint8_t i_portSlct = 0 );

  private: // instance variables

    TARGETING::TargetHandle_t iv_trgt; ///< Target MBA/MCA
    MemRank iv_rank;                   ///< Target rank
    bool iv_x4Dram;                    ///< TRUE if iv_trgt uses x4 DRAMs

    /** A bitmap of all bad DQs for each port. */
    uint8_t iv_data[T][DQ_BITMAP::BITMAP_SIZE];
};

} // end namespace PRDF

#endif // __prdfMemDqBitmap_H

