/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenConst.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2014              */
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

    DQS_PER_X8DRAM = DQS_PER_SYMBOL * SYMBOLS_PER_X8DRAM,
    DQS_PER_X4DRAM = DQS_PER_SYMBOL * SYMBOLS_PER_X4DRAM,

    X8DRAMS_PER_RANK = SYMBOLS_PER_RANK / SYMBOLS_PER_X8DRAM,
    X4DRAMS_PER_RANK = SYMBOLS_PER_RANK / SYMBOLS_PER_X4DRAM,
};

} // end namespace PRDF

#endif // PRDF_CEN_CONST_H

