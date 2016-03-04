/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaTdCtlr_rt.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

/** @file  prdfCenMbaTdCtlr_rt.H
 *  @brief The FSP implementation of the MBA TD Controller.
 */

#ifndef __prdfCenMbaTdCtlr_rt_H
#define __prdfCenMbaTdCtlr_rt_H

// Pegasus includes
#include <prdfCenMbaTdQueue_rt.H>
#include <prdfCenMbaTdRankData_rt.H>

// Should be included last in case there are any platform specific includes that
// the common code needs.
#include <prdfCenMbaTdCtlr_common.H>

namespace PRDF
{

class CenAddr;

/**
 * @brief A state machine for memory targeted diagnostics and background
 *        scrubbing during FSP runtime.
 */
class CenMbaTdCtlr : public CenMbaTdCtlrCommon
{
  private: // constants, enums

    // Function pointers for maintenance command complete events.
    typedef int32_t (CenMbaTdCtlr::*FUNCS)( STEP_CODE_DATA_STRUCT & io_sc,
                                            const CenAddr & i_stopAddr,
                                            const CenAddr & i_endAddr );

    enum RuntimeStopConditions
    {
        COND_RT_VCM_DSD =
            COND_TARGETED_CMD |
            mss_MaintCmd::STOP_ON_UE |
            mss_MaintCmd::STOP_IMMEDIATE,

        COND_RT_TPS_HARD_CE =
            COND_TARGETED_CMD |
            mss_MaintCmd::STOP_ON_HARD_NCE_ETE |
            mss_MaintCmd::STOP_ON_MPE |
            mss_MaintCmd::STOP_ON_UE |
            mss_MaintCmd::STOP_IMMEDIATE,

        COND_RT_TPS_ALL_CE =
            COND_RT_TPS_HARD_CE |
            mss_MaintCmd::STOP_ON_INT_NCE_ETE  |
            mss_MaintCmd::STOP_ON_SOFT_NCE_ETE,
    };

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
        CenMbaTdCtlrCommon(i_mbaChip), iv_queue(), iv_masterRanks(),
        iv_vcmRankData(), iv_tpsRankData(), iv_tpsFalseAlarm(false),
        iv_scrubResumeCounter(), iv_fetchAttnsMasked(false)
    {}

    /**
     * @brief Handles reset-reload or FO scenario.
     * @note  This function will check if PRD was unable to restart maintenance
     *        command before R/R or FO. In that scenario, this function will
     *        start maintenance command. As during R/R or F/O we do not have any
     *        mechanism to restore the complete state of TD controller, we will
     *        not start any interrupted or pending TD procedure. We will only
     *        start BG scrub. If we found any chip marks during TD state
     *        machine initialize we will start VCM procedure rather than
     *        BG scrub.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleRrFo();

  public: // Overloaded functions

    int32_t handleCmdCompleteEvent( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t handleTdEvent( STEP_CODE_DATA_STRUCT & io_sc,
                           const CenRank & i_rank, const TdType i_event,
                           bool i_banTps = false );

  private: // Overloaded functions

    int32_t initialize();

    int32_t analyzeCmdComplete( STEP_CODE_DATA_STRUCT & io_sc,
                                const CenAddr & i_stopAddr,
                                const CenAddr & i_endAddr );
    int32_t analyzeVcmPhase1( STEP_CODE_DATA_STRUCT & io_sc,
                              const CenAddr & i_stopAddr,
                              const CenAddr & i_endAddr );
    int32_t analyzeVcmPhase2( STEP_CODE_DATA_STRUCT & io_sc,
                              const CenAddr & i_stopAddr,
                              const CenAddr & i_endAddr );
    int32_t analyzeDsdPhase1( STEP_CODE_DATA_STRUCT & io_sc,
                              const CenAddr & i_stopAddr,
                              const CenAddr & i_endAddr );
    int32_t analyzeDsdPhase2( STEP_CODE_DATA_STRUCT & io_sc,
                              const CenAddr & i_stopAddr,
                              const CenAddr & i_endAddr ) { return FAIL; }
    int32_t analyzeTpsPhase1( STEP_CODE_DATA_STRUCT & io_sc,
                              const CenAddr & i_stopAddr,
                              const CenAddr & i_endAddr );
    int32_t analyzeTpsPhase2( STEP_CODE_DATA_STRUCT & io_sc,
                              const CenAddr & i_stopAddr,
                              const CenAddr & i_endAddr ) { return FAIL; }

    int32_t startVcmPhase1( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t startVcmPhase2( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t startDsdPhase1( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t startDsdPhase2( STEP_CODE_DATA_STRUCT & io_sc ) { return FAIL; }
    int32_t startTpsPhase1( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t startTpsPhase2( STEP_CODE_DATA_STRUCT & io_sc ) { return FAIL; }

  private: // functions

    /**
     * @brief  Starts/restarts background scrubbing.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t startBgScrub( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Starts the next TD procedure based on the next event in iv_queue.
     * @param  io_sc The step code data struct.
     * @note   If iv_queue is empty, this function will resume background
     *         scrubbing.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t startNextTd( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Resumes a scrub from the address after the current stopped
     *         address.
     * @param  io_sc          The step code data struct.
     * @param  i_eccErrorMask Bitwise mask indicating which ECC errors have
     *                        occurred (see enum EccErrorMask).
     * @note   This function should only be called from the background scrub or
     *         TPS analysis functions.
     * @note   This function will not clear the total and per symbol CE
     *         counters. Instead, it clears the counters specifically for the
     *         errors at attention (specified by i_eccErrorMask).
     * @note   Before calling this function, should check that the stopped
     *         address does not equal the end address in hardware. Otherwise, it
     *         will result in an additional scrub of all memory, which will not
     *         be desirable.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t resumeScrub( STEP_CODE_DATA_STRUCT & io_sc,
                         uint32_t i_eccErrorMask );

    /**
     * @brief  Handle TD (VCM|TPS) completion sequence.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleTdComplete( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Adds a VCM event to the TD queue and sets the rank as bad.
     * @param  i_rank   Target rank.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t addTdQueueEntryVCM( const CenRank & i_rank );

    /**
     * @brief  Adds a TPS event to the TD queue and sets the rank as bad.
     * @param  i_rank   Target rank.
     * @param  io_sc    The step code data struct.
     * @param  i_banTps TRUE to ban any future TPS requests for this rank,
     *                  default FALSE.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t addTdQueueEntryTPS( const CenRank & i_rank,
                                STEP_CODE_DATA_STRUCT & io_sc,
                                bool i_banTps = false );

    /**
     * @brief  Pops the first entry off the TD queue and sets the rank as good,
     *         if possible.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t removeTdQueueEntry();

    /**
     * @brief Will first sync the SDC then call the parent version of this
     *        function. The SDC needed to be synched because the parent function
     *        will clear the maintenance command complete attention and we need
     *        to protect against reset/reloads and failovers.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t cleanupPrevCmd( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief Will first sync the SDC then call the parent version of this
     *        function. The SDC needed to be synched because the parent function
     *        will clear the maintenance command complete attention and we need
     *        to protect against reset/reloads and failovers.
     * @param  io_sc The step code data struct.
     * @param  i_clearStats True if this function should clear the total and per
     *                      symbol CE counters (default), false otherwise.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t prepareNextCmd( STEP_CODE_DATA_STRUCT & io_sc,
                            bool i_clearStats = true );

    /**
     * @brief  Handles UEs during a TD procedure.
     * @param  io_sc           The step code data struct.
     * @param  i_stopAddr      The address in which the command stopped.
     * @param  i_addTpsRequest True to add a TPS request in addition to the rest
     *                         of the analysis, false otherwise.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleUe_Td( STEP_CODE_DATA_STRUCT & io_sc,
                         const CenAddr & i_stopAddr,
                         bool i_addTpsRequest = true );

    /**
     * @brief  Handles RCE ETEs during a TD procedure.
     * @param  io_sc  The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleRceEte_Td( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Handles MPEs during a TPS procedure.
     * @param  io_sc  The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleMpe_Tps( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Handles CE ( soft/intermittent|Hard ) ETE attention in TPS mode.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleCeEte_Tps( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Handles UEs during background scrub.
     * @param  io_sc  The step code data struct.
     * @param  i_addr The address in which the maintenance command stopped.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleUe_NonTd( STEP_CODE_DATA_STRUCT & io_sc,
                            const CenAddr & i_addr );

    /**
     * @brief  Handles MPEs during background scrub.
     * @param  io_sc  The step code data struct.
     * @param  i_addr The address in which the maintenance command stopped.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleMpe_NonTd( STEP_CODE_DATA_STRUCT & io_sc,
                             const CenAddr & i_addr );

    /**
     * @brief  Handles RCE ETEs during background scrub.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleRceEte_NonTd( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Handles hard CE ETEs during background scrub.
     * @param  io_sc  The step code data struct.
     * @param  i_addr The address in which the maintenance command stopped.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleHardCeEte_NonTd( STEP_CODE_DATA_STRUCT & io_sc,
                                   const CenAddr & i_addr );

    /**
     * @brief  Handles soft and intermittent CEs during background scrub.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleSoftIntCeEte_NonTd( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Handles TPS false alarms.
     * @param  io_sc The step code data struct.
     * @note   Should only be called at the end of TPS phase 2 if no ECC errors
     *         that have reached threshold have been found.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleTpsFalseAlarm( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Calculates the CE threshold used during a TPS procedure.
     * @param  o_thr  Threshold based on TPS phase and MNFG vs. non-MNFG.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     * @note   iv_tdState must be set to a valid TPS phase before calling this
     *         function.
     */
    int32_t getTpsCeThr( uint16_t & o_thr );

    /**
     * @brief  Sets the CE thresholds in hardware for a TPS procedure.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     * @note   iv_tdState must be set to a valid TPS phase before calling this
     *         function.
     */
    int32_t setTpsThresholds();

    /**
     * @brief  Sets iv_mark in hardware and adds a VCM request to the TD queue.
     * @param  io_sc The step code data struct.
     * @note   iv_mark must be set with the chip mark before calling this
     *         function.
     * @note   If the write to markstore is blocked by hardware, iv_mark is
     *         updated to contain the new chip mark placed by hardware. No retry
     *         is attempted.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t tpsChipMark( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Sets iv_mark in hardware.
     * @param  io_sc The step code data struct.
     * @note   iv_mark must be set with the symbol mark before calling this
     *         function.
     * @note   If the write to markstore is blocked by hardware, iv_mark is
     *         updated to contain the new chip mark placed by hardware. Then
     *         this function retries the write to hardware.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t tpsSymbolMark( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Masks fetch ECC attentions.
     * @note   Only intended to be used just before starting a new TD procedure.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t maskFetchAttns();

    /**
     * @brief  Clears and unmasks fetch ECC attentions.
     * @note   maskFetchAttns() will not mask fetch UEs, however, this function
     *         will unmask them because it is possible that fetch UEs exceeded
     *         threshold and were masked by the rule code.
     * @note   Only intended to be used just after completing a TD procedure.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t unmaskFetchAttns();

    /**
     * @brief  Conditionally clears the CE counters based on the error types
     *         given.
     * @param  i_eccErrorMask Bitwise mask indicating which ECC errors have
     *                        occurred (see enum EccErrorMask).
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t clearCeCounters( uint32_t i_eccErrorMask );

    /**
     * @brief  Helper function to start a maintenance command for background
     *         scrub.
     * @param  i_stopCond      Bit mask for conditions in which to stop command.
     * @param  i_flags         See enum CtrlFlags for details.
     * @param  i_sAddrOverride A non-NULL value indicates to use this start
     *                         address and not the start address of i_rank.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t doBgScrubCmd( uint32_t i_stopCond,
                          uint32_t i_flags =
                               PlatServices::mss_MaintCmdWrapper::END_OF_MEMORY,
                          const CenAddr * i_sAddrOverride = NULL );

    /**
     * @brief  Helper function to start a maintenance command for targeted
     *         diagnostics scrub.
     * @param  i_stopCond      Bit mask for conditions in which to stop command.
     * @param  i_flags         See enum CtrlFlags for details.
     * @param  i_sAddrOverride A non-NULL value indicates to use this start
     *                         address and not the start address of i_rank.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t doTdScrubCmd( uint32_t i_stopCond,
                          uint32_t i_flags =
                               PlatServices::mss_MaintCmdWrapper::NO_FLAGS,
                          const CenAddr * i_sAddrOverride = NULL );

    /**
     * @brief  Queries for any available spares on iv_rank and the given port.
     * @param  i_ps    Target port select.
     * @param  o_avail True a spare DRAM or ECC spare is avaiable, false
     *                 otherwise.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t checkForAvailableSpares( uint8_t i_ps, bool & o_avail );

    /**
     * @brief Adds the TD controller state at the beginning of analysis to the
     *        capture data.
     * @param io_sc The step code data struct.
     */
    void collectStateCaptureDataStart( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief Adds the TD controller state at the end of analysis to the
     *        capture data.
     * @param io_sc The step code data struct.
     */
    void collectStateCaptureDataEnd( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief Adds the TD controller state to the  capture data.
     * @param io_sc     The step code data struct.
     * @param i_descTag Description tag for the capture data. Used to
     *        distinguish between data captured at the beginning or end or
     *        analysis.
     * @note  Only intended to be called by collectStateCaptureDataStart() or
     *        collectStateCaptureDataEnd().
     */
    void collectStateCaptureData( STEP_CODE_DATA_STRUCT & io_sc,
                                  const char * i_descTag );

  private: // classes

    /** @brief Simple class to abstract the common actions done on
     *         iv_scrubResumeCounter. */
    class ScrubResumCounter
    {
      public:
        ScrubResumCounter() : iv_counter(0) {}
        void reset()             { iv_counter = 0;          }
        void incCount()          { iv_counter++;            }
        bool isTh() const        { return 16 <= iv_counter; }
        uint8_t getCount() const { return iv_counter;       }
      private:
        uint8_t iv_counter;
    };

  private: // instance variables

    /** Array of functions pointers for TD controller states. This is used to
     *  determine the next course of action after a maintenance command complete
     *  attention.
     */
    static FUNCS cv_cmdCompleteFuncs[MAX_TD_STATE];

    TdQueue     iv_queue;         ///< Queue for all TD events
    TdRankList  iv_masterRanks;   ///< List of master ranks
    VcmRankData iv_vcmRankData;   ///< VCM specific data for each rank.
    TpsRankData iv_tpsRankData;   ///< TPS specific data for each rank.
    bool        iv_tpsFalseAlarm; ///< TPS false alarm

    /** This is used to limit the number of times a scrub is resumed on a rank
     *  in order to prevent flooding of attentions */
    ScrubResumCounter iv_scrubResumeCounter;

    /** Keeps track if the fetch attentions have been masked during a TD
     *  procedure. */
    bool iv_fetchAttnsMasked;

}; // CenMbaTdCtlr

} // end namespace PRDF

#endif // __prdfCenMbaTdCtlr_rt_H

