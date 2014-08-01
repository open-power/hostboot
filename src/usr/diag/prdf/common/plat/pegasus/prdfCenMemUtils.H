/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMemUtils.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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

#ifndef prdfCenMemUtils_H
#define prdfCenMemUtils_H

/** @file  prdfCenMemUtils.H
 *  @brief General utility functions for Centaur
 */

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

#include <vector>
#include <prdfCenSymbol.H>
#include <prdfParserEnums.H>

namespace PRDF
{

class ExtensibleChip;
struct STEP_CODE_DATA_STRUCT;

namespace MemUtils
{

//==============================================================================
//  Constants and Enums
//==============================================================================

/**
 * @brief Lists all possible sizes for a DRAM.
 * @note  These values must match the defintion of MBAXCR[6:7]. They are
 *        important for calculations.
 */
enum DramSize
{
    SIZE_2GB  = 0,
    SIZE_4GB  = 1,
    SIZE_8GB  = 2,
    SIZE_16GB = 3,
};

//==============================================================================
//  Maintenance statistics
//==============================================================================

/**
 * @brief Collects CE symbol data.
 */
struct SymbolData
{
    CenSymbol symbol;
    uint8_t count;
    SymbolData() : count(0) {}
};

typedef std::vector<SymbolData> MaintSymbols;

/** Functor for MaintSymbols to sort by count. */
inline bool sortSymDataCount( const SymbolData & i, const SymbolData & j )
{
    return i.count < j.count;
}

/** Functor for MaintSymbols to match a DRAM. */
class MatchSymDataDram
{
  public:
    explicit MatchSymDataDram( const CenSymbol & i_d ) : iv_d(i_d.getDram()) {}

    bool operator() ( const SymbolData & i_data ) const
    { return ( iv_d == i_data.symbol.getDram() ); }

  private:
    uint8_t iv_d;
};

/** Functor for MaintSymbols to match a symbol. */
class MatchSymDataSymbol
{
  public:
    explicit MatchSymDataSymbol( const CenSymbol & i_s ) : iv_s(i_s) {}

    bool operator() ( const SymbolData & i_data ) const
    { return ( iv_s == i_data.symbol ); }

  private:
    CenSymbol iv_s;
};

/**
 * @brief  Queries the per symbol counters and returns a sorted list of symbols
 *         with a count greater than or equal to the given threshold.
 * @note   The returned list will be sorted from lowest count to highest count.
 * @param  i_mbaChip     Target MBA chip.
 * @param  i_rank        Target rank.
 * @param  o_maintStats  Returns the list of symbols and counts.
 * @param  o_chipMark    This represents the DRAM in which a chip mark should be
 *                       placed, if necessary, based on the following:
 *                         - In x4 mode, this represents the DRAM with the
 *                           highest total per symbol count with at least 1
 *                           symbol that has exceeded threshold.
 *                         - In x8 mode, this represents the DRAM with the
 *                           highest total per symbol count with at least 2
 *                           symbols that have exceeded threshold.
 *                       It is possible that there will be symbols returned in
 *                       o_maintStats that do not meet the criteria stated
 *                       above. Therefore, the user must check if o_chipMark is
 *                       valid before using it.
 * @param  i_thr         The count threshold. Each symbol count must be greater
 *                       than or equal to this value to be added to the list.
 *                       The default is 1, which means all non-zero counts will
 *                       be added to the list. A value of 0 will result in a bad
 *                       return code.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t collectCeStats( ExtensibleChip * i_mbaChip, const CenRank & i_rank,
                        MaintSymbols & o_maintStats, CenSymbol & o_chipMark,
                        uint8_t i_thr = 1 );

/**
 * @brief  Clears the per symbol CE counters on a target MBA (via MEMBUF and MBA
 *         position number).
 * @param  i_membChip MEMBUF chip.
 * @param  i_mbaPos   MBA positions number (0-1).
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t clearPerSymbolCounters( ExtensibleChip * i_membChip,
                                uint32_t i_mbaPos );

/**
 * @brief  Gets DRAM size for an MBA.
 * @param  i_mbaChip   MBA chip.
 * @param  o_size  size for a DRAM.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t getDramSize( ExtensibleChip * i_mbaChip, uint8_t & o_size );

/**
 * @brief  Check for channel fail attentions on the MCS side of the DMI bus.
 * @param  i_mcsChip An MCS chip.
 * @param  io_sc     The step code data struct.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t checkMcsChannelFail( ExtensibleChip * i_mcsChip,
                             STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief  Cleanup for channel CS on Centaur.
 * @param  i_mbChip   Membuf chip.
 * @param  i_sc  Service Data Collector.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t chnlCsCleanup( ExtensibleChip *i_mbChip,
                       STEP_CODE_DATA_STRUCT & i_sc );

/**
 * @brief  determines the type of Centaur based raw card  associated with MBA.
 * @param  i_mba    mba target
 * @param  o_type   raw card type.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 * @note   Function is not intended for IS DIMM.
 */
int32_t getRawCardType( TARGETING::TargetHandle_t i_mba,
                        CEN_SYMBOL::WiringType & o_type );

/**
 * @brief  Cleanup MCIFIR bits on proc side for hostboot.
 * @param  i_mbChip   Membuf chip.
 * @param  i_sc  Service Data Collector.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t mcifirCleanup( ExtensibleChip *i_mbChip,
                       STEP_CODE_DATA_STRUCT & i_sc );

} // end namespace MemUtils

} // end namespace PRDF

#endif
