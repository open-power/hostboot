/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTps.H $                     */
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

/** @file prdfMemTps.H */

#ifndef __prdfMemTps_H
#define __prdfMemTps_H

// Platform includes
#include <prdfMemTdQueue.H>
#include <prdfMemUtils.H>

namespace PRDF
{

struct CeCount
{
    MemUtils::MaintSymbols symList;
    uint32_t count = 0;
};

/** @brief Two-Phase Scrub procedure. */
template <TARGETING::TYPE T>
class TpsEvent : public TdEntry
{
  public: // functions

    /**
     * @brief Constructor
     * @param i_chip MCA or MBA.
     * @param i_rank Target rank.
     * @param i_ban  True to ban all subsequent requests for TPS on this rank.
     */
    TpsEvent<T>( ExtensibleChip * i_chip, MemRank i_rank, bool i_ban = false ) :
        TdEntry(TPS_EVENT, i_chip, i_rank)
    {
        PRDF_ASSERT( nullptr != i_chip );
        PRDF_ASSERT( T == i_chip->getType() );
    }

  public: // overloaded functions from parent class

    uint32_t nextStep( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );

    uint32_t getKey() const { return iv_rank.getKey(); } // Master and slave

  private: // functions

    #ifdef __HOSTBOOT_RUNTIME

    /**
     * @brief  Starts phase 1 of the procedure.
     * @param  io_sc  The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t startTpsPhase1_rt( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Analyzes phase 1 of the procedure.
     * @param  io_sc  The step code data struct.
     * @param  o_done True if the procedure is complete or has aborted.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t analyzeTpsPhase1_rt(STEP_CODE_DATA_STRUCT & io_sc, bool & o_done);

    /**
     * @brief  Does isolation for ECC attentions.
     * @param  i_eccAttns Mask of all currently active maintenance attentions.
     *                    See enum MaintEccAttns for values.
     * @param  io_sc      The step code data struct.
     * @param  o_done     True if the procedure is complete or has aborted.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t analyzeEcc( const uint32_t & i_eccAttns,
                         STEP_CODE_DATA_STRUCT & io_sc,
                         bool & o_done );

    /**
     * @brief  Gets the counts that summarize the symbol CE counts.
     * @param  io_badDqCount      Number of nibbles with a bad DQ
     * @param  io_badChipCount    Number of nibbles with a bad Chip
     * @param  io_nonZeroSumCount Number of nibbles under threshold with a
     *                            non-zero sum
     * @param  io_singleSymCount  Number of nibbles under threshold with a
     *                            single symbol count greater than one
     * @param  o_symList          Vector of all symbols with CE counts > 0.
     * @param  io_sc              The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t getSymbolCeCounts( CeCount & io_badDqCount,
        CeCount & io_badChipCount, CeCount & io_nonZeroSumCount,
        CeCount & io_singleSymCount, MemUtils::MaintSymbols & o_symList,
        STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Does isolation for CE attentions.
     * @param  io_sc      The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t analyzeCe( STEP_CODE_DATA_STRUCT & io_sc );

    #endif // __HOSTBOOT_RUNTIME

};

} // end namespace PRDF

#endif // __prdfMemTps_H

