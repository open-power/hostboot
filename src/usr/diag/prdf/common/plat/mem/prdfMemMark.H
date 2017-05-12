/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemMark.H $             */
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

#ifndef __prdfMemMark_H
#define __prdfMemMark_H

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>

// Platform includes
#include <prdfMemAddress.H>
#include <prdfMemSymbol.H>
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

  public: // functions

    /** @return The Galois field representing this mark. */
    uint8_t getGalois() const { return iv_galois; }

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
 * @brief  If a rank contains a symbol mark that is on the same DRAM as the chip
 *         mark, the symbol mark is removed. This is done to free up available
 *         repairs. Will also apply RAS policies where necessary.
 * @param  i_chip MBA or MCA chip.
 * @param  i_rank Target rank.
 * @param  io_sc  The step code data struct.
 * @return Non-SUCCESS if an internal function fails. SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t balance( ExtensibleChip * i_chip, const MemRank & i_rank,
                  STEP_CODE_DATA_STRUCT & io_sc )
{
    uint32_t o_rc = SUCCESS;

    do
    {
        // Get the chip mark.
        MemMark chipMark;
        o_rc = readChipMark<T>( i_chip, i_rank, chipMark );
        if ( SUCCESS != o_rc ) break;
        if ( !chipMark.isValid() ) break; // nothing to do.

        // Get the symbol mark.
        MemMark symMark;
        o_rc = readSymbolMark<T>( i_chip, i_rank, symMark );
        if ( SUCCESS != o_rc ) break;
        if ( !symMark.isValid() ) break; // nothing to do.

        // If both the chip and symbol mark are on the same DRAM, clear the
        // symbol mark.
        if ( chipMark.getSymbol().getDram() == symMark.getSymbol().getDram() )
        {
            o_rc = clearSymbolMark<T>( i_chip, i_rank );
            if ( SUCCESS != o_rc ) break;
        }
        else
        {
            // Both a chip and symbol mark exist, but they are on separate
            // DRAMs. So, make the error log predictive.
            io_sc.service_data->setServiceCall();
        }

    } while (0);

    return o_rc;
}

} // end namespace MarkStore

} // end namespace PRDF

#endif // __prdfMemMark_H

