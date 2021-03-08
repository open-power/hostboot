/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemSymbol.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
#include <prdfPlatServices.H>

//##############################################################################
//                           class MemSymbol
//##############################################################################

namespace PRDF
{

// Symbol to Galois code mapping table
static const uint8_t symbol2Galois[] =
{
    0x80, 0xa0, 0x90, 0xf0, 0x08, 0x0a, 0x09, 0x0f, // symbols  0- 7
    0x98, 0xda, 0xb9, 0x7f, 0x91, 0xd7, 0xb2, 0x78, // symbols  8-15
    0x28, 0xea, 0x49, 0x9f, 0x9a, 0xd4, 0xbd, 0x76, // symbols 16-23
    0x60, 0xb0, 0xc0, 0x20, 0x06, 0x0b, 0x0c, 0x02, // symbols 24-31
    0xc6, 0xfb, 0x1c, 0x42, 0xca, 0xf4, 0x1d, 0x46, // symbols 32-39
    0xd6, 0x8b, 0x3c, 0xc2, 0xcb, 0xf3, 0x1f, 0x4e, // symbols 40-47
    0xe0, 0x10, 0x50, 0xd0, 0x0e, 0x01, 0x05, 0x0d, // symbols 48-55
    0x5e, 0x21, 0xa5, 0x3d, 0x5b, 0x23, 0xaf, 0x3e, // symbols 56-63
    0xfe, 0x61, 0x75, 0x5d, 0x51, 0x27, 0xa2, 0x38, // symbols 64-71
};

class ExtensibleChip;

/**
 * @brief Container for a memory symbol.
 */
class MemSymbol
{

  public: // constructor

    /** @brief Default constructor. Intentionally creates an invalid symbol. */
    MemSymbol() = default;

  private: // constructor

    /** @brief Constructor from components. Used only by the static initializer
     *         functions below. Guarantees the symbol is valid or asserts. */
    MemSymbol( TARGETING::TargetHandle_t i_trgt, const MemRank & i_rank,
               uint8_t i_symbol );

  public: // functions

    /**
     * @brief  Creates a MemSymbol from a symbol.
     * @param  i_trgt   OCMB_CHIP target.
     * @param  i_rank   The rank this symbol is on.
     * @param  i_symbol The input symbol.
     * @return A MemSymbol. Must call isValid() to determine if the function was
     *         successful in creating a valid object.
     */
    static MemSymbol fromSymbol( TARGETING::TargetHandle_t i_trgt,
                                 const MemRank & i_rank, uint8_t i_symbol )
    {
        return MemSymbol ( i_trgt, i_rank, i_symbol );
    }

    /**
     * @brief  Creates a MemSymbol from a Galois field.
     * @param  i_trgt   OCMB_CHIP target.
     * @param  i_rank   The rank this symbol is on.
     * @param  i_galois The Galois field.
     * @param  i_mask   The bit mask.
     * @return A MemSymbol. Must call isValid() to determine if the function was
     *         successful in creating a valid object.
     */
    static MemSymbol fromGalois( TARGETING::TargetHandle_t i_trgt,
                                 const MemRank & i_rank, uint8_t i_galois,
                                 uint8_t i_mask = 0 );

    /** @return true if symbol is within the valid range, false otherwise. */
    bool isValid() const { return iv_symbol < SYMBOLS_PER_RANK; }

    /** @return This symbol's numerical value (0-71). */
    uint8_t getSymbol() const { return iv_symbol; }

    /** @return The bad pins associated with this symbol (2-bits). */
    uint8_t getPins() const { return iv_pins; }

    /** @return The the first DQ of this symbol. */
    uint8_t getDq() const;

    /** @return rank associated with this symbol. */
    MemRank getRank() const { return iv_rank; };

    /** @return The port select for this symbol. */
    uint8_t getPortSlct() const;

    /** @return The DRAM index for this symbol. */
    uint8_t getDram() const;

    /** @return The DRAM index for this sym, adjusted if steered to a spare. */
    uint8_t getDramSpareAdjusted() const;

    /** @return The bad pins associated with this symbol in relation to the DRAM
     *          (x4 mode is 4-bits, x8 mode is 8-bits). */
    uint8_t getDramPins() const;

    /** @return The first symbol (smallest index) on the associated DRAM. */
    uint8_t getDramSymbol() const;

    /** @return The Galois field associated with this symbol. */
    uint8_t getGalois() const;

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
    bool operator < ( const MemSymbol & i_symbol ) const
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
    bool operator == ( const MemSymbol & i_symbol ) const
    {
        return ( (iv_symbol == i_symbol.iv_symbol) &&
                 (iv_rank   == i_symbol.iv_rank  ) );
    }

    /**
     * @brief  Checks if the current symbol is on any of the spares
     *         Sets iv_isDramSpared if found on at least one of the valid spares
     *         Sets iv_isEccSpared if found on valid i_ecc
     *         Usually call mssGetSteerMux to fill in associated symbols
     *
     * @param  i_sp0 A symbol associated with the spare on port 0.
     * @param  i_sp1 A symbol associated with the spare on port 1.
     * @param  i_ecc A symbol associated with the ECC spare (x4 mode only).
     */
    void updateSpared(const MemSymbol & i_sp0,
                      const MemSymbol & i_sp1,
                      const MemSymbol & i_ecc);


  private: // instance variables

    TARGETING::TargetHandle_t iv_trgt = nullptr; ///< Target handle.

    /* The rank containing this symbol. */
    MemRank iv_rank = MemRank(0);

    /* This symbol's numerical value. Initialize to SYMBOLS_PER_RANK to ensure
     * this object is initially invalid. */
    uint8_t iv_symbol = SYMBOLS_PER_RANK;

    uint8_t iv_pins = 0; ///< See enum DqMask.

    bool iv_isDramSpared = false; ///< TRUE if symbol resides on DRAM spare.
    bool iv_isEccSpared  = false; ///< TRUE if symbol resides on ECC spare.
};

//------------------------------------------------------------------------------
//                       Symbol Accessor Functions
//------------------------------------------------------------------------------

/**
 * @brief  Reads the memory NCE/TCE vector trap register from hardware.
 * @param  i_chip   OCMB_CHIP.
 * @param  i_rank   The rank this symbol is on.
 * @param  o_sym1   The first symbol. Should always be valid for both NCE/TCE.
 * @param  o_sym2   The second symbol. Only valid for TCEs.
 * @note   For OCMBs, both NCEs and TCEs report to the same error vector and
 *         only the latest NCE/TCE is recorded. Therefore, it is possible that
 *         PRD handles a TCE attention, but only one symbol is found because a
 *         NCE was reported afterwards, wiping out the error vector for the TCE.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t getMemReadSymbol( ExtensibleChip * i_chip, const MemRank & i_rank,
                           MemSymbol & o_sym1, MemSymbol & o_sym2 );

} // end namespace PRDF

#endif // __prdfMemSymbol_H

