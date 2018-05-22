/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTps.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
#include <prdfTargetServices.H>

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
        TdEntry(TPS_EVENT, i_chip, i_rank), iv_ban(i_ban)
    {
        PRDF_ASSERT( nullptr != i_chip );
        PRDF_ASSERT( T == i_chip->getType() );
    }

  public: // overloaded functions from parent class

    uint32_t nextStep( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done )
    {
        #define PRDF_FUNC "[TpsEvent::nextStep] "

        #ifndef __HOSTBOOT_RUNTIME
        // Should only do this procedure if MNFG IPL CE handling is enabled.
        PRDF_ASSERT( PlatServices::isMfgCeCheckingEnabled() );
        #endif

        uint32_t o_rc = SUCCESS;

        o_done = false;

        do
        {
            // First, do analysis.
            o_rc = analyzePhase( io_sc, o_done );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "analyzePhase() failed on 0x%08x, 0x%2x",
                          iv_chip->getHuid(), getKey() );
                break;
            }

            if ( o_done ) break; // Nothing more to do.

            // Then, start the next phase of the procedure.
            o_rc = startNextPhase( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "startNextPhase() failed on 0x%08x, 0x%2x",
                          iv_chip->getHuid(), getKey() );
                break;
            }

        } while (0);

        // Add the rank to the callout list if no callouts in the list.
        if ( 0 == io_sc.service_data->getMruListSize() )
        {
            MemoryMru mm { iv_chip->getTrgt(), iv_rank,
                           MemoryMruData::CALLOUT_RANK };
            io_sc.service_data->SetCallout( mm );
        }

        return o_rc;

        #undef PRDF_FUNC
    }

    uint32_t getKey() const { return iv_rank.getKey(); } // Master and slave

  private: // functions

    /**
     * @brief  Does analysis of the command that just completed for the current
     *         phase.
     * @param  io_sc  The step code data struct.
     * @param  o_done True if the procedure is complete or has aborted, false
     *                otherwise.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t analyzePhase( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );

    /**
     * @brief  Does analysis on any ECC errors found during the current phase.
     * @param  i_eccAttns Mask of all currently active maintenance attentions.
     *                    See enum MaintEccAttns for values.
     * @param  io_sc      The step code data struct.
     * @param  o_done     True if the procedure is complete or has aborted.
     *                    False otherwise.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t analyzeEccErrors( const uint32_t & i_eccAttns,
                               STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );

    /**
     * @brief  Starts the appropriate maintenance command based on iv_phase.
     * @pre    iv_phase must be set appropriately before calling this function.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t startCmd();

    /**
     * @brief  Starts the next phase of the procedure.
     * @param  io_sc  The step code data struct.
     * @post   iv_phase will be updated appropriately per design.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t startNextPhase( STEP_CODE_DATA_STRUCT & io_sc );

    #ifdef __HOSTBOOT_RUNTIME

    /**
     * @brief  Analyzes the counts that summarize the symbol CE counts.
     * @param  i_badDqCount       Number of nibbles with a bad DQ
     * @param  i_badChipCount     Number of nibbles with a bad Chip
     * @param  i_sumAboveOneCount Number of nibbles under threshold with a
     *                            sum greater than 1
     * @param  i_singleSymCount   Number of nibbles under threshold with only
     *                            a single symbol with a non-zero count, and
     *                            that count is > 1
     * @param  io_sc      The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t analyzeCeSymbolCounts( CeCount i_badDqCount,
        CeCount i_badChipCount, CeCount i_sumAboveOneCount,
        CeCount i_singleSymCount, STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Gets the counts that summarize the symbol CE counts.
     * @param  io_badDqCount       Number of nibbles with a bad DQ
     * @param  io_badChipCount     Number of nibbles with a bad Chip
     * @param  io_sumAboveOneCount Number of nibbles under threshold with a
     *                             sum greater than 1
     * @param  io_singleSymCount   Number of nibbles under threshold with only
     *                             a single symbol with a non-zero count, and
     *                             that count is > 1
     * @param  io_sc               The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t getSymbolCeCounts( CeCount & io_badDqCount,
        CeCount & io_badChipCount, CeCount & io_sumAboveOneCount,
        CeCount & io_singleSymCount, STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Analyzes the maintenance CE statistics.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t analyzeCeStats( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief Additional processing if no errors are handled during the
     *        procedure.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t handleFalseAlarm( STEP_CODE_DATA_STRUCT & io_sc );

    #endif // __HOSTBOOT_RUNTIME


  private: // instance variables

    /** True to ban all subsequent requests for TPS on this rank. */
    bool iv_ban = false;

    #ifdef __HOSTBOOT_RUNTIME
    /** TPS false alarm (MBA only). Initially true when the object is created.
     *  Will be set to false if any ECC errors are found during the procedure.*/
    bool iv_tpsFalseAlarm = true;
    #endif
};

} // end namespace PRDF

#endif // __prdfMemTps_H

