/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenSymbol.H $       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
  public: // constants, enums

    enum WiringType
    {
        WIRING_INVALID =  0, // An invalid wiring type
    };

    /** Used as a 2-bit mask to display which of the DQs on this symbol are
     *  failing. */
    enum DqMask
    {
        NO_SYMBOL_DQS   = 0x0,
        EVEN_SYMBOL_DQ  = 0x2,
        ODD_SYMBOL_DQ   = 0x1,
        BOTH_SYMBOL_DQS = EVEN_SYMBOL_DQ | ODD_SYMBOL_DQ,
    };

  public: // constructor

    /**
     * @brief Default constructor
     */
    CenSymbol() :
        iv_mbaTarget(NULL), iv_rank(), iv_wiringType(WIRING_INVALID),
        iv_symbol(SYMBOLS_PER_RANK), iv_pins(NO_SYMBOL_DQS)
    {}

  private: // constructor

    /**
     * @brief Constructor from components
     */
    CenSymbol( TARGETING::TargetHandle_t i_mba, const CenRank & i_rank,
               WiringType i_wiringType, uint8_t i_symbol, uint8_t i_pins,
               bool i_x4Dram ) :
        iv_mbaTarget(i_mba), iv_rank(i_rank), iv_wiringType(i_wiringType),
        iv_symbol(i_symbol), iv_pins(i_pins), iv_x4Dram(i_x4Dram)
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
                                 uint8_t i_pins = NO_SYMBOL_DQS );

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
                                  WiringType & o_wiringType );

    /** @return true if symbol is within the valid range, false otherwise. */
    bool isValid() const { return iv_symbol < SYMBOLS_PER_RANK; }

    /** @return This symbol's wiring type. */
    WiringType getWiringType() const { return iv_wiringType; }

    /** @return This symbol's numerical value (0-71). */
    uint8_t getSymbol() const { return iv_symbol; }

    /** @return The bad pins associated with this symbol (2-bits). */
    uint8_t getPins() const { return iv_pins; }

    /** @return The even Centaur DQ of this symbol. */
    uint8_t getEvenDq() const { return symbol2CenDq( iv_symbol ); }

    /** @return The port select for this symbol. */
    uint8_t getPortSlct() const { return symbol2PortSlct( iv_symbol ); }

    /** @return The DRAM index for this symbol. */
    uint8_t getDram() const { return symbol2Dram( iv_symbol, iv_x4Dram ); }

    /**
     * @return The first symbol of the DRAM associated with this symbol.
     * @note   Needed for input into mss_put_mark_store and mss_put_steer_mux
     *         hardware procedures.
     */
    uint8_t getDramSymbol() const
    { return dram2Symbol( symbol2Dram(iv_symbol, iv_x4Dram), iv_x4Dram); }

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

    /** @return The symbol of the given Centaur DQ and port select. */
    static uint8_t cenDq2Symbol( uint8_t i_CenDq, uint8_t i_ps );

    /** @return The even Centaur DQ of the given symbol. */
    static uint8_t symbol2CenDq( uint8_t i_symbol );

    /** @return The port select for given symbol. */
    static uint8_t symbol2PortSlct( uint8_t i_symbol );

    /** @return The DRAM index for the given symbol. */
    static uint8_t symbol2Dram( uint8_t i_symbol, bool i_isX4Dram );

    /** @return The first symbol of the given DRAM index. */
    static uint8_t dram2Symbol( uint8_t i_dram, bool i_isX4Dram );

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
    static int32_t getSymbol( const CenRank & i_rank, WiringType i_wiringType,
                              uint8_t i_dimmDq, uint8_t i_portSlct,
                              uint8_t & o_symbol );

  private: // instance variables

    TARGETING::TargetHandle_t iv_mbaTarget; ///< MBA Target handle.
    CenRank iv_rank;                        ///< The rank this symbol is on.
    WiringType iv_wiringType;               ///< This symbol's wiring type.
    uint8_t iv_symbol;                      ///< This symbol's numerical value.
    uint8_t iv_pins;                        ///< See enum DqMask.
    bool iv_x4Dram;                         ///< TRUE x4 DRAM, FALSE x8 DRAM.
};

} // end namespace PRDF

#endif // prdfCenSymbol_H

