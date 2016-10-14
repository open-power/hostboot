/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemSymbol.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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

#ifndef __prdfMemSymbol_H
#define __prdfMemSymbol_H

/** @file  prdfMemSymbol.H
 *  @brief Utility functions that help decode memory symbols.
 */

#include <prdfMemAddress.H>
#include <prdfMemConst.H>
#include <prdfParserUtils.H>
#include <prdfPlatServices.H>

//##############################################################################
//                           class MemSymbol
//##############################################################################

namespace PRDF
{

/**
 * @brief Container for a memory symbol.
 */
template <TARGETING::TYPE T>
class MemSymbol
{

  public: // constructor

    /** @brief Default constructor. Intentionally creates an invalid symbol. */
    MemSymbol() :
        iv_trgt(NULL), iv_rank(),
        iv_symbol( SYMBOLS_PER_RANK ), iv_pins( CEN_SYMBOL::NO_SYMBOL_DQS ),
        iv_isDramSpared(false), iv_isEccSpared(false)
    {}

  private: // constructor

    /** @brief Constructor from components. Used only by the static initializer
     *         functions below. Guarantees the symbol is valid or asserts. */
    MemSymbol( TARGETING::TargetHandle_t i_trgt, const MemRank & i_rank,
               uint8_t i_symbol, uint8_t i_pins ) :
        iv_trgt(i_trgt), iv_rank(i_rank), iv_symbol(i_symbol),
        iv_pins(i_pins), iv_isDramSpared(false), iv_isEccSpared(false)
    {
        PRDF_ASSERT( NULL != i_trgt );
        PRDF_ASSERT( T == PlatServices::getTargetType(i_trgt) );
        PRDF_ASSERT( i_symbol < SYMBOLS_PER_RANK );
        PRDF_ASSERT( i_pins <= CEN_SYMBOL::BOTH_SYMBOL_DQS );
    }

  public: // functions

    /**
     * @brief  Creates a MemSymbol from a symbol.
     * @param  i_trgt   The target.
     * @param  i_rank   The rank this symbol is on.
     * @param  i_symbol The input symbol.
     * @param  i_pins   See enum DqMask.
     * @return A MemSymbol. Must call isValid() to determine if the function was
     *         successful in creating a valid object.
     */
    static MemSymbol<T> fromSymbol( TARGETING::TargetHandle_t i_trgt,
                                    const MemRank & i_rank, uint8_t i_symbol,
                                    uint8_t i_pins = CEN_SYMBOL::NO_SYMBOL_DQS )
    {
        return MemSymbol ( i_trgt, i_rank, i_symbol, i_pins );
    }

    /**
     * @brief  Creates a MemSymbol from a Galois field.
     * @param  i_trgt   The target.
     * @param  i_rank   The rank this symbol is on.
     * @param  i_galois The Galois field.
     * @param  i_mask   The bit mask.
     * @return A MemSymbol. Must call isValid() to determine if the function was
     *         successful in creating a valid object.
     */
    static MemSymbol<T> fromGalois( TARGETING::TargetHandle_t i_trgt,
                                    const MemRank & i_rank, uint8_t i_galois,
                                    uint8_t i_mask = 0 );

    /** @return true if symbol is within the valid range, false otherwise. */
    bool isValid() const { return iv_symbol < SYMBOLS_PER_RANK; }

    /** @return This symbol's numerical value (0-71). */
    uint8_t getSymbol() const { return iv_symbol; }

    /** @return The bad pins associated with this symbol (2-bits). */
    uint8_t getPins() const { return iv_pins; }

    /** @return The the first DQ of this symbol. */
    uint8_t getDq() const { return PARSERUTILS::symbol2Dq<T>(iv_symbol); }

    /** @return rank associated with this symbol. */
    MemRank getRank() const { return iv_rank; };

    /** @return Marks this symbol as steered to a DRAM spare. */
    void setDramSpared() { iv_isDramSpared = true; }

    /** @return Marks this symbol as steered to the ECC spare. */
    void setEccSpared() { iv_isEccSpared = true; }

    /** @return TRUE this symbol is on a DRAM spare, FALSE otherwise. */
    bool isDramSpared() const { return iv_isDramSpared; }

    /** @return TRUE this symbol is on the ECC spare, FALSE otherwise. */
    bool isEccSpared() const { return iv_isEccSpared; }

    /**
     * @brief   Overrides the '<' operator.
     * @param   i_symbol The symbol to compare with.
     * @return  TRUE if this symbol is less than i_symbol, FALSE otherwise.
     * @note    Compares against iv_symbol and iv_rank. There is currently no
     *          need to compare against iv_trgt.
     */
    bool operator < ( const MemSymbol<T> & i_symbol ) const
    {
        return ( (iv_symbol < i_symbol.iv_symbol) ||
                 ( (iv_symbol == i_symbol.iv_symbol) &&
                   (iv_rank   <  i_symbol.iv_rank ) ) );
    }

    /**
     * @brief  Overrides the '==' operator.
     * @param  i_symbol The symbol to compare with.
     * @return TRUE if the two symbols are equivalent, FALSE otherwise.
     * @note   Compares against iv_symbol and iv_rank. There is currently no
     *         need to compare against iv_trgt.
     */
    bool operator == ( const MemSymbol<T> & i_symbol ) const
    {
        return ( (iv_symbol == i_symbol.iv_symbol) &&
                 (iv_rank   == i_symbol.iv_rank  ) );
    }

  private: // instance variables

    TARGETING::TargetHandle_t iv_trgt; ///< Target handle.
    MemRank iv_rank;                   ///< The rank this symbol is on.
    uint8_t iv_symbol;                 ///< This symbol's numerical value.
    uint8_t iv_pins;                   ///< See enum DqMask.
    bool iv_isDramSpared; ///< TRUE if symbol resides on DRAM spare.
    bool iv_isEccSpared;  ///< TRUE if symbol resides on ECC spare.
};

} // end namespace PRDF

#endif // __prdfMemSymbol_H

