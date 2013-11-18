/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMemUtils.H $     */
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

/**
 * @brief  Checks CE stats on a MBA.
 * @param  i_mbaChip   MBA chip.
 * @param  o_maintStats Output vector. Contains symbols with CE count.
 * @param  i_rank Rank for which stat collection will be done.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t collectCeStats( ExtensibleChip * i_mbaChip, MaintSymbols & o_maintStats,
                        const CenRank & i_rank );

/**
 * @brief  Gets DRAM size for an MBA.
 * @param  i_mbaChip   MBA chip.
 * @param  o_size  size for a DRAM.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t getDramSize( ExtensibleChip * i_mbaChip, uint8_t & o_size );

/**
 * @brief  Cleanup for channel CS on Centaur.
 * @param  i_mbChip   Membuf chip.
 * @param  i_sc  Service Data Collector.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t chnlCsCleanup( ExtensibleChip *i_mbChip,
                       STEP_CODE_DATA_STRUCT & i_sc );

} // end namespace MemUtils

} // end namespace PRDF

#endif
