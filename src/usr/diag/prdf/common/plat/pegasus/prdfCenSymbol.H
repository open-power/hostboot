/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenSymbol.H $       */
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

#ifndef prdfCenSymbol_H
#define prdfCenSymbol_H

/** @file  prdfCenSymbol.H
 *  @brief Utility functions that help decode memory syndromes.
 */

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

#include <prdfCenAddress.H>
#include <prdfCenConst.H>
#include <prdfPlatServices.H>
#include <prdfTargetFwdRef.H>
#include <prdfParserEnums.H>

//##############################################################################
//                           class CenSymbol
//##############################################################################

namespace PRDF
{

/**
 * @brief Container for a memory symbol.
 */
class CenSymbol
{

  public: // constructor

    /**
     * @brief Default constructor
     */
    CenSymbol() :
        iv_mbaTarget(NULL), iv_rank(),
        iv_wiringType( CEN_SYMBOL::WIRING_INVALID ),
        iv_symbol( SYMBOLS_PER_RANK ), iv_pins( CEN_SYMBOL::NO_SYMBOL_DQS ),
        iv_x4Dram(false),iv_isDramSpared(false), iv_isEccSpared(false)
    {}

  private: // constructor

    /**
     * @brief Constructor from components
     */
    CenSymbol( TARGETING::TargetHandle_t i_mba, const CenRank & i_rank,
               CEN_SYMBOL::WiringType i_wiringType, uint8_t i_symbol,
               uint8_t i_pins, bool i_x4Dram ) :
        iv_mbaTarget(i_mba), iv_rank(i_rank), iv_wiringType(i_wiringType),
        iv_symbol(i_symbol), iv_pins(i_pins), iv_x4Dram(i_x4Dram),
        iv_isDramSpared(false), iv_isEccSpared(false)
    {}

  public: // functions

    /**
     * @brief  Creates a CenSymbol from a symbol.
     * @param  i_mba    The MBA target.
     * @param  i_rank   The rank this symbol is on.
     * @param  i_symbol The input symbol.
     * @param  i_pins   See enum DqMask.
     * @return A CenSymbol. Must call isValid() to determine if the function was
     *         successful in creating a valid object.
     */
    static CenSymbol fromSymbol( TARGETING::TargetHandle_t i_mba,
                                 const CenRank & i_rank, uint8_t i_symbol,
                                 uint8_t i_pins = CEN_SYMBOL::NO_SYMBOL_DQS );

    /**
     * @brief  Creates a CenSymbol from a DIMM DQ.
     * @param  i_mba      The MBA target.
     * @param  i_rank     The rank this symbol is on.
     * @param  i_dimmDq   The failing DIMM DQ.
     * @param  i_portSlct The port select.
     * @param  o_symbol   The returned symbol object.
     * @note   For Centaur DIMMs, a DIMM DQ is the same as a Centaur DQ.
     *         For IS DIMMs, the mapping between DIMM DQ and Centaur DQ is
     *         determined by card that the DIMM is plugged into. See enum
     *         WiringType for more details.
     * @return A CenSymbol. Must call isValid() to determine if the function was
     *         successful in creating a valid object.
     */
    static CenSymbol fromDimmDq( TARGETING::TargetHandle_t i_mba,
                                 const CenRank & i_rank, uint8_t i_dimmDq,
                                 uint8_t i_portSlct );

    /**
     * @brief  Creates a CenSymbol from a Galois field.
     * @param  i_mba    The MBA target.
     * @param  i_rank   The rank this symbol is on.
     * @param  i_galois The Galois field.
     * @param  i_mask   The bit mask.
     * @return A CenSymbol. Must call isValid() to determine if the function was
     *         successful in creating a valid object.
     */
    static CenSymbol fromGalois( TARGETING::TargetHandle_t i_mba,
                                 const CenRank & i_rank, uint8_t i_galois,
                                 uint8_t i_mask = 0 );

    /**
     * @brief  Returns the dimm's wiring type.
     * @param  i_mba        MBA Target handle.
     * @param  i_rank       The rank this symbol is on.
     * @param  o_wiringType See enum WiringType.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    static int32_t getWiringType( TARGETING::TargetHandle_t i_mba,
                                  const CenRank & i_rank,
                                  CEN_SYMBOL::WiringType & o_wiringType );

    /** @return true if symbol is within the valid range, false otherwise. */
    bool isValid() const { return iv_symbol < SYMBOLS_PER_RANK; }

    /** @return This symbol's wiring type. */
    CEN_SYMBOL::WiringType getWiringType() const { return iv_wiringType; }

    /** @return This symbol's numerical value (0-71). */
    uint8_t getSymbol() const { return iv_symbol; }

    /** @return The bad pins associated with this symbol (2-bits). */
    uint8_t getPins() const { return iv_pins; }

    /** @return The even Centaur DQ of this symbol. */
    uint8_t getEvenDq() const;

    /** @return The port select for this symbol. */
    uint8_t getPortSlct() const;

    /** @return The DRAM index for this symbol. */
    uint8_t getDram() const;

    /**
     * @return The first symbol of the DRAM associated with this symbol.
     * @note   Needed for input into mss_put_mark_store and mss_put_steer_mux
     *         hardware procedures.
     */
    uint8_t getDramSymbol() const;

    /** @return The bad pins associated with this symbol in relation to the DRAM
     *          (x4 mode is 4-bits, x8 mode is 8-bits,). */
    uint8_t getDramPins() const;

    /** @return rank associated with this symbol. */
    CenRank getRank() const { return iv_rank; };

    /**
     * @brief  Sets this symbol's pin to a new set of bad pins.
     * @param  The new pins.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t setPins( uint8_t i_pins );

    /** @return TRUE this symbol is on a x4 DRAM, FALSE otherwise. */
    bool isX4Dram() const { return iv_x4Dram; }

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
     *          need to compare against iv_mbaTarget.
     */
    bool operator < ( const CenSymbol & i_symbol ) const
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
     *         need to compare against iv_mbaTarget.
     */
    bool operator == ( const CenSymbol & i_symbol ) const
    {
        return ( (iv_symbol == i_symbol.iv_symbol) &&
                 (iv_rank   == i_symbol.iv_rank  ) );
    }

  private: // functions

    /**
     * @brief  Returns the symbol associated with the given DIMM DQ.
     * @param  i_rank        The rank this symbol is on.
     * @param  i_wiringType  The DIMM's wiring type.
     * @param  i_dimmDq      The failing DIMM DQ.
     * @param  i_portSlct    The DIMM's port select.
     * @param  o_symbol      The returned symbol.
     * @return Non-SUCCESS if an invalid parameter is given, SUCCESS otherwise.
     */
    static int32_t getSymbol( const CenRank & i_rank,
                              CEN_SYMBOL::WiringType i_wiringType,
                              uint8_t i_dimmDq, uint8_t i_portSlct,
                              uint8_t & o_symbol );

  private: // instance variables

    TARGETING::TargetHandle_t iv_mbaTarget; ///< MBA Target handle.
    CenRank iv_rank;                        ///< The rank this symbol is on.
    CEN_SYMBOL::WiringType iv_wiringType;   ///< This symbol's wiring type.
    uint8_t iv_symbol;                      ///< This symbol's numerical value.
    uint8_t iv_pins;                        ///< See enum DqMask.
    bool iv_x4Dram;                         ///< TRUE x4 DRAM, FALSE x8 DRAM.
    bool iv_isDramSpared; ///< TRUE if symbol resides on DRAM spare.
    bool iv_isEccSpared;  ///< TRUE if symbol resides on ECC spare.
};

} // end namespace PRDF

#endif // prdfCenSymbol_H

