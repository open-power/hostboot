/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfCenMbaTdCtlr.H $           */
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

/** @file  prdfCenMbaTdCtlr.H
 *  @brief The Hostboot implementation of the MBA TD Controller.
 */

#ifndef __prdfCenMbaTdCtlr_H
#define __prdfCenMbaTdCtlr_H

#include <prdfCenMbaTdCtlr_common.H>

namespace PRDF
{

/**
 * @brief A state machine for memory targeted diagnostics during Hostboot MDIA.
 */
class CenMbaTdCtlr : public CenMbaTdCtlrCommon
{
  private: // constants, enums

    // Function pointers for maintenance command complete events.
    typedef int32_t (CenMbaTdCtlr::*FUNCS)( STEP_CODE_DATA_STRUCT & io_sc );

  public: // functions

    /**
     * @brief Constructor
     *
     * This contructor will be called in the MBA data bundle code. Therefore,
     * no register reads/writes can be done in this constructor. Anything needed
     * to initialize the instance variables that requires register reads/writes
     * or is non-trivial should be done in initialize().
     *
     * @param i_mbaChip An MBA chip.
     */
    explicit CenMbaTdCtlr( ExtensibleChip * i_mbaChip ) :
        CenMbaTdCtlrCommon(i_mbaChip)
    {}

  public: // Overloaded functions

    int32_t handleCmdCompleteEvent( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t handleTdEvent( STEP_CODE_DATA_STRUCT & io_sc,
                           const CenRank & i_rank, const TdType i_event,
                           bool i_banTps = false );

  private: // Overloaded functions

    int32_t initialize();

    int32_t analyzeCmdComplete( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t analyzeVcmPhase1( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t analyzeVcmPhase2( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t analyzeDsdPhase1( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t analyzeDsdPhase2( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t analyzeTpsPhase1( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t analyzeTpsPhase2( STEP_CODE_DATA_STRUCT & io_sc );

    int32_t startVcmPhase1( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t startVcmPhase2( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t startDsdPhase1( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t startDsdPhase2( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t startTpsPhase1( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t startTpsPhase2( STEP_CODE_DATA_STRUCT & io_sc );

  public: // functions

    /**
     * @brief  Start the initial background scrub. This is done at the very end
     *         of Hostboot after the last call to checkForIplAttns().
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t startInitialBgScrub();

  private: // functions

    /**
     * @brief  Handle UEs during TD analysis.
     * @param  io_sc Service data collector.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleUE( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Handle MPE event
     * @param  io_sc Service data collector.
     * @note   This will start VCM phase 1.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleMPE( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Handle CE ETE during MNFG CE analysis.
     * @param  io_sc Service data collector.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleMnfgCeEte( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Sends a message to MDIA that a maintenance command has completed.
     * @note   If for some reason PRD needed to do some targeted diagnotics and
     *         on a rank that was not the last rank behind the MBA, this
     *         function will need to send a message to MDIA indicating that the
     *         command stopped and MDIA will need to restart the pattern testing
     *         from the next address to the end of memory.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t signalMdiaCmdComplete();

    /**
     * @brief  Does mnfg setup for CE threshold.
     * @note   Before calling this function, set current state to new
     *         value (TPS_PHASE_1/ TPS_PHASE_2).
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t mnfgCeSetup();

  private: // instance variables

    /** Array of functions pointers for TD controller states. This is used to
     *  determine the next course of action after a maintenance command complete
     *  attention.
     */
    static FUNCS cv_cmdCompleteFuncs[MAX_TD_STATE];

}; // CenMbaTdCtlr

} // end namespace PRDF

#endif // __prdfCenMbaTdCtlr_H

