/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemMark.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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

#ifndef __prdfMemMark_H
#define __prdfMemMark_H

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>

// Platform includes
#include <prdfMemAddress.H>
#include <prdfMemSymbol.H>
#include <prdfP9McaExtraSig.H>
#include <prdfPlatServices.H>

//##############################################################################
//                           class MemMark
//##############################################################################

namespace PRDF
{

/** @brief Container for a memory mark (chip or symbol). */
class MemMark
{
  public: // constructor

    /** Default constructor. */
    MemMark() = default;

    /**
     * @brief Constructor from components.
     * @param i_trgt   MBA or MCA target.
     * @param i_rank   The rank this mark is on.
     * @param i_galois The Galois field.
     */
    MemMark( TARGETING::TargetHandle_t i_trgt, const MemRank & i_rank,
             uint8_t i_galois ) :
        iv_galois( i_galois ),
        iv_symbol( MemSymbol::fromGalois(i_trgt, i_rank, i_galois) )
    {}

    /**
     * @brief Cosntructor from components.
     * @param i_trgt   MBA or MCA target.
     * @param i_rank   The rank this mark is on.
     * @param i_symbol The symbol representing this mark.
     */
    MemMark( TARGETING::TargetHandle_t i_trgt, const MemRank & i_rank,
             const MemSymbol & i_symbol ) :
        iv_galois( i_symbol.getGalois() ),
        iv_symbol( i_symbol )
    {}

  public: // functions

    /** @return The Galois field representing this mark. */
    uint8_t getGalois() const { return iv_galois; }

    /** @return The Galois field associated with the chip this mark is in.
     *  Will correspond to the rightmost/least index symbol in the chip. You
     *  must check for a valid symbol before calling this function. */
    uint8_t getChipGalois() const
    {
        PRDF_ASSERT( iv_symbol.isValid() );
        return symbol2Galois[(iv_symbol.getSymbol()/4)*4];
    }

    /** @return The symbol representing this mark. */
    MemSymbol getSymbol() const { return iv_symbol; }

    /** @return The symbol representing this mark. */
    bool isValid() const { return iv_symbol.isValid(); }

  private: // instance variables

    /** Galois field representing any symbol on this mark. */
    uint8_t iv_galois = 0;

    /** Any symbol on this mark (must match iv_galois). */
    MemSymbol iv_symbol = MemSymbol();
};

//##############################################################################
//                      Utilities to read/write markstore
//##############################################################################

namespace MarkStore
{

/**
 * @brief  Reads markstore and returns the chip mark for the given rank.
 * @param  i_chip MBA or MCA chip.
 * @param  i_rank Target rank.
 * @param  o_mark The returned chip mark.
 * @return Non-SUCCESS if an internal function fails. SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t readChipMark( ExtensibleChip * i_chip, const MemRank & i_rank,
                       MemMark & o_mark );

/**
 * @brief  Writes a chip mark into markstore for the given rank.
 * @param  i_chip MBA or MCA chip.
 * @param  i_rank Target rank.
 * @param  i_mark Target chip mark.
 * @return Non-SUCCESS if an internal function fails. SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t writeChipMark( ExtensibleChip * i_chip, const MemRank & i_rank,
                        const MemMark & i_mark );

/**
 * @brief  Clear chip mark in markstore for the given rank.
 * @param  i_chip MBA or MCA chip.
 * @param  i_rank Target rank.
 * @return Non-SUCCESS if an internal function fails. SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t clearChipMark( ExtensibleChip * i_chip, const MemRank & i_rank );

/**
 * @brief  Reads markstore and returns the symbol mark for the given rank.
 * @param  i_chip MBA or MCA chip.
 * @param  i_rank Target rank.
 * @param  o_mark The returned symbol mark.
 * @return Non-SUCCESS if an internal function fails. SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t readSymbolMark( ExtensibleChip * i_chip, const MemRank & i_rank,
                         MemMark & o_mark );

/**
 * @brief  Writes a symbol mark into markstore for the given rank.
 * @param  i_chip MBA or MCA chip.
 * @param  i_rank Target rank.
 * @param  i_mark Target symbol mark.
 * @return Non-SUCCESS if an internal function fails. SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t writeSymbolMark( ExtensibleChip * i_chip, const MemRank & i_rank,
                          const MemMark & i_mark );

/**
 * @brief  Clear symbol mark in markstore for the given rank.
 * @param  i_chip MBA or MCA chip.
 * @param  i_rank Target rank.
 * @return Non-SUCCESS if an internal function fails. SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t clearSymbolMark( ExtensibleChip * i_chip, const MemRank & i_rank );

/**
 * @brief  If a chip mark has been verified or explicitly set due other RAS
 *         policies, this function does all the necessary cleanup.
 *
 * Function details:
 *  - Adds the chip mark to the callout list.
 *  - Removes the symbol mark if it is on the same DRAM as the chip mark.
 *  - Adds the symbol mark to the callout list if it exists on another DRAM.
 *  - If DRAM repairs are disabled:
 *      - Makes the error log predictive.
 *  - Otherwise:
 *      - Sets the DRAM in the DRAM Repair VPD.
 *      - Makes the error log predictive if RAS policies apply.
 *      - Adds a DSD procedure to the TD queue is a DRAM spare is available.
 *      - Bans TPS on the rank if all repairs are used.
 *
 * @param  i_chip MBA or MCA chip.
 * @param  i_rank Target rank.
 * @param  io_sc  The step code data struct.
 * @return Non-SUCCESS if an internal function fails. SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t chipMarkCleanup( ExtensibleChip * i_chip, const MemRank & i_rank,
                          STEP_CODE_DATA_STRUCT & io_sc );

} // end namespace MarkStore

} // end namespace PRDF

#endif // __prdfMemMark_H

