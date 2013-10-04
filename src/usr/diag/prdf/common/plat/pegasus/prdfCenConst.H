/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenConst.H $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2013              */
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

#ifndef PRDF_CEN_CONST_H
#define PRDF_CEN_CONST_H

/**
 *   @file prdfCenConst.H
 *   @brief Defines Centaur related constants
 */
//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

namespace PRDF
{

enum
{
    PORT_SLCT_PER_MBA = 2,
    DIMM_SLCT_PER_MBA = 2,

    MASTER_RANKS_PER_DIMM_SLCT  = 4,
    SLAVE_RANKS_PER_MASTER_RANK = 8,

    MASTER_RANKS_PER_MBA = DIMM_SLCT_PER_MBA * MASTER_RANKS_PER_DIMM_SLCT,

    SYMBOLS_PER_RANK = 72,
    DQS_PER_DIMM     = 72,

    SYMBOLS_PER_BYTE = 4,
    DQS_PER_SYMBOL   = 2,
    DQS_PER_BYTE     = SYMBOLS_PER_BYTE * DQS_PER_SYMBOL,

    SYMBOLS_PER_X8DRAM = 4,
    SYMBOLS_PER_X4DRAM = 2,

    X8DRAMS_PER_RANK = SYMBOLS_PER_RANK / SYMBOLS_PER_X8DRAM,
    X4DRAMS_PER_RANK = SYMBOLS_PER_RANK / SYMBOLS_PER_X4DRAM,
};

} // end namespace PRDF

#endif // PRDF_CEN_CONST_H

