/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemDqBitmap.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2023                        */
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
#include <prdfTrace.H>

namespace PRDF
{

class CaptureData;
class MemSymbol;

/**
 * @brief Container for DIMM's DQ bitmap.
 */
class MemDqBitmap
{
  public: // constructors

    /** @brief Default constructor */
    MemDqBitmap() {}

    /** @brief Constructor from components */
    MemDqBitmap( TARGETING::TargetHandle_t i_trgt, const MemRank & i_rank,
                 const uint8_t (&i_d)[DQ_BITMAP::BITMAP_SIZE] ) :
                 iv_trgt(i_trgt), iv_rank(i_rank), iv_x4Dram(true)
    {
        memcpy(iv_bitmap, i_d, sizeof(iv_bitmap));
        if ( TARGETING::TYPE_MEM_PORT == PlatServices::getTargetType(iv_trgt) )
        {
            iv_spareByte = 5;
            TARGETING::TargetHandle_t dimm = PlatServices::getConnectedChild(
                iv_trgt, TARGETING::TYPE_DIMM, iv_rank.getDimmSlct() );
            iv_x4Dram = PlatServices::isDramWidthX4( dimm );
        }
        else
        {
            PRDF_ERR("MemDqBitmap: Invalid target passed to constructor: "
                     "0x%08x", PlatServices::getHuid(i_trgt));
            PRDF_ASSERT(false);
        }
    }

  public: // functions

    /**
     * @brief  Queries if there are any bad DQs present.
     * @return TRUE if any bad DQs present.
     */
    bool badDqs() const;

    /**
     * @brief  Sets the specified DQ.
     * @param  i_dq       The target DQ.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    uint32_t setDq( uint8_t i_dq );

    /**
     * @brief  Sets the specified symbol.
     * @note   Will adjust for DRAM spares, if applicable.
     * @param  i_symbol The target symbol.
     * @param  i_pins   Optional 2-bit value of the symbol's pins. The default
     *                  is to set both pins.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    uint32_t setSymbol( const MemSymbol & i_symbol, uint8_t i_pins = 0x3 );

    /**
     * @brief  Sets the specified DRAM.
     * @note   Will adjust for DRAM spares, if applicable.
     * @param  i_symbol A symbol on the target DRAM.
     * @param  i_pins   Optional 8-bit (x8 mode) or 4-bit (x4 mode) value of the
     *                  DRAM's pins. The default is to set all pins.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    uint32_t setDram( const MemSymbol & i_symbol, uint8_t i_pins = 0xff );

    /**
     * @brief  Clears the specified DRAM.
     * @note   Will adjust for DRAM spares, if applicable.
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
     * @brief Adds the bitmap to the capture data.
     * @param o_cd Capture data struct.
     */
    void getCaptureData( CaptureData & o_cd ) const;
    /**
     * @brief  Gets the bitmap data.
     * @return A reference to the bitmap data.
     */
    const uint8_t (&getData()const)[DQ_BITMAP::BITMAP_SIZE]
    {
        return iv_bitmap;
    }

    /**
     * @brief  Support function to calculate the byte index, and
     *         bit index based on the given symbol.
     * @note   Will adjust the indexes for DRAM spares, if applicable.
     * @param  i_symbol   The target symbol.
     * @param  o_byteIdx  The byte index of the symbol (0-9).
     * @param  o_bitIdx   The bit index of the symbol (0,2,4,6).
     * @return Non-SUCCESS if the symbol is invalid, SUCCESS otherwise.
     */
    uint32_t getByteBitIdx(const MemSymbol & i_symbol, uint8_t & o_byteIdx,
                           uint8_t & o_bitIdx) const;

    /**
     * @brief  Checks if chip mark is present on specified DRAM.
     * @note   Will adjust for DRAM spares, if applicable.
     * @param  i_symbol A symbol on the target DRAM.
     * @param  o_cm     True if chip mark is present false otherwise.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    uint32_t isChipMark( const MemSymbol & i_symbol, bool & o_cm );

    /**
     * @brief  Helper function for getSymbolList to adjust for possible spares
     * @param  i_symbol   A symbol on the target DRAM.
     * @param  o_symOnSp0 True if the symbol is on spare 0, false otherwise
     * @param  o_symOnSp1 True if the symbol is on spare 1, false otherwise
     */
    void checkIfSymSpared( uint8_t i_symbol, bool & o_symOnSp0,
                           bool & o_symOnSp1 );

    /**
     * @brief  Returns a list of all active (non-zero) symbols.
     * @return Vector of all active symbols.
     */
    std::vector<MemSymbol> getSymbolList();


    /**
     * @brief  Queries for DRAM spare status.
     * @param  o_sp0Avail TRUE if DRAM spare 0 is available, FALSE otherwise.
     * @param  o_sp1Avail TRUE if DRAM spare 1 is available, FALSE otherwise.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    uint32_t isSpareAvailable( bool & o_sp0Avail, bool & o_sp1Avail );

  private: // instance variables

    TARGETING::TargetHandle_t iv_trgt; ///< Target MEM_PORT
    MemRank iv_rank;                   ///< Target rank
    bool iv_x4Dram;                    ///< TRUE if iv_trgt uses x4 DRAMs
    uint8_t iv_spareByte;              ///< Specifies the spare byte location

    /** A bitmap of all bad DQs for the associated port/rank */
    uint8_t iv_bitmap[DQ_BITMAP::BITMAP_SIZE];
};

//##############################################################################
//                              Utility Functions
//##############################################################################

/**
 * @brief  Sets the inputted dram in DRAM repairs VPD.
 * @param  i_trgt   MEM_PORT target.
 * @param  i_rank   Target rank.
 * @param  i_symbol A symbol on the target DRAM.
 * @return Non-SUCCESS if an internal function fails. SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t setDramInVpd( TARGETING::TargetHandle_t i_trgt,
                       const MemRank & i_rank, MemSymbol i_symbol );

/**
 * @brief  Clears the inputted dram in DRAM repairs VPD.
 * @param  i_trgt MEM_PORT target.
 * @param  i_rank Target rank.
 * @param  i_symbol A symbol on the target DRAM.
 * @return Non-SUCCESS if an internal function fails. SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t clearDramInVpd( TARGETING::TargetHandle_t i_trgt,
                         const MemRank & i_rank, MemSymbol i_symbol );

} // end namespace PRDF

#endif // __prdfMemDqBitmap_H

