/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTdCtlr.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2024                        */
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

/** @file  prdfMemTdCtlr.H
 *  @brief A state machine for memory Targeted Diagnostics (TD).
 */

#ifndef __prdfMemTdCtlr_H
#define __prdfMemTdCtlr_H

// Framework includes
#include <iipServiceDataCollector.h>

// Platform includes
#include <prdfMemAddress.H>
#include <prdfMemTdQueue.H>
#include <prdfMemTdRankList.H>
#include <prdfPlatServices.H>

namespace PRDF
{

/**
 * @brief A state machine for memory Targeted Diagnostics (TD).
 */
template <TARGETING::TYPE T>
class MemTdCtlr
{
  public:

    MemTdCtlr() = delete; // Don't allow default contructor

    /**
     * @brief Constructor
     *
     * This contructor will only be called in the MCBIST, MBA, or OCMB data
     * bundle, which already checks for a valid type.
     *
     * Need to initialize iv_stoppedRank to a valid entry in iv_rankList. Use
     * the last entry in the list so that the 'next' rank is the first entry
     * in the list.
     *
     * @param i_chip An MCBIST, MBA, or OCMB chip.
     */
    explicit MemTdCtlr( ExtensibleChip * i_chip ) :
        iv_chip( i_chip ), iv_rankList( i_chip ),
        iv_stoppedRank( iv_rankList.getList().back() )
    {
        PRDF_ASSERT( T == iv_chip->getType() );
    }

    /**
     * @brief  Determines and executes the next course of action after a
     *         maintenance command complete attention.
     * @note   Initializes the TD controller, if needed.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t handleCmdComplete( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  This only pushes a new TdEntry to the back of iv_queue.
     * @post   Fetch attentions must also call handleTdEvent() to trigger
     *         diagnostics, if not already in progress.
     * @param  i_entry  The new TD queue entry.
     */
    void pushToQueue( TdEntry * i_entry )
    {
        #ifdef __HOSTBOOT_RUNTIME
        if ( TdEntry::TPS_EVENT == i_entry->getType() &&
             isTpsBanned(i_entry->getChip(), i_entry->getRank(),
                         i_entry->getPort()) )
        {
            PRDF_ERR( "[MemTdCtlr::pushToQueue] TPS banned on 0x%08x 0x%02x",
                      i_entry->getChip()->getHuid(), i_entry->getRank() );
            return; // prevent the entry from being added to the queue.
        }
        #endif

        iv_queue.push(i_entry);
    }

    /**
     * @brief  This tells the TD controller there was a DSD (dram spare deploy)
     *         event added to the queue because of an IMPE threshold and
     *         additional processing may be needed to start the next TD
     *         procedure. This is similar to handleTdEvent below, but is used
     *         after we hit IMPE threshold to trigger a DSD (dram spare deploy)
     *         event which could be either IPL or runtime.
     *
     * @pre    A TdEntry must be added to the queue (via pushToQueue) before
     *         calling this function.
     *
     * @note   Initializes the TD controller, if needed.
     * @param  io_sc    The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t handleDsdImpeTh( STEP_CODE_DATA_STRUCT & io_sc );


    #ifdef __HOSTBOOT_RUNTIME

    /**
     * @brief  This tells the TD controller there was a TdEntry added to the
     *         queue (via pushToQueue) because of a fetch attention and
     *         additional processing may be needed to start the next TD
     *         procedure. If there isn't a current TD procedure in progress,
     *         this function will stop background scrubbing and starts the first
     *         procedure in the queue.
     *
     * @pre    A TdEntry must be added to the queue (via pushToQueue) before
     *         calling this function.
     *
     * @note   Initializes the TD controller, if needed.
     * @param  io_sc    The step code data struct.
     * @param  i_port   Target memory port.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t handleTdEvent( STEP_CODE_DATA_STRUCT & io_sc, uint8_t i_port );

    /**
     * @brief  Bans TPS on the given rank. Any attempts to add a TPS procedure
     *         to the queue for this rank will be ignored.
     * @param  i_chip OCMB chip.
     * @param  i_rank The target slave rank.
     * @param  i_port The target port select.
     */
    void banTps( ExtensibleChip * i_chip, const MemRank & i_rank,
                 uint8_t i_port )
    {
        // It doesn't matter what we set the value to, we just need to make sure
        // the rank exists in the map.
        iv_tpsBans[std::make_tuple(i_chip, i_rank, i_port)] = true;
    }

    /**
     * @brief Handles reset-reload or FO scenario.
     *
     * This does not call initialize() or start any maintenance commands.
     * Instead, it checks the hardware's current state and ensures by the end of
     * the function that either a command is currently running or there will be
     * a command complete attention pending that PRD will handle separately.
     *
     * If there is already an active command complete attention. This function
     * does nothing because PRD will handle the attention soon.
     *
     * If there is no active command complete attention and there is no command
     * currently in progress, it will set the command complete attention and PRD
     * will handle that attention soon.
     *
     * Otherwise, there is a command in progress. So, it will check for any
     * unverified chip marks. If any exist, it will force the current command to
     * stop, causing a command complete attention that PRD will handle soon.
     *
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t handleRrFo();

    /**
     * @brief  Masks NCE and TCE ECC attentions.
     * @note   Only intended to be used just before starting a new TD procedure.
     * @param  i_port Target memory port.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t maskEccAttns(uint8_t i_port);

    #endif

  private:

    /**
     * @brief  Initializes the TD controller, if needed.
     *
     * This should be called at the beginning of every public function to ensure
     * the TD controller is initialized.
     *
     * During MemDiags, this initializes iv_broadcastModeCapable.
     *
     * At runtime, this is used to query hardware for any unverified chip marks
     * that may have occurred after starting background scrubbing, but before
     * PRD is up and running. We may also have unverified chip marks if the HBRT
     * service is stopped and restarted (PRD is reinitialize and all previous
     * state machine data is lost).
     *
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t initialize();

    /**
     * @brief This is called when there are no more TD procedures to execute.
     *
     * During Memory Diagnostics, this means the current pattern test command
     * has reached the end of memory on the MBA or MCBIST. So this function will
     * tell MDIA to move onto the next pattern test command, if needed.
     *
     * At runtime, this function will restart background scrubbing.
     *
     * @param  io_sc  The step code data struct.
     * @param  i_addr The address the command complete stopped on.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t defaultStep(STEP_CODE_DATA_STRUCT & io_sc, const MemAddr & i_addr);

    /**
     * @brief Progresses onto the next step of the state machine.
     *
     * This function will move onto the next step of the current procedure, if
     * one is in progress. Otherwise, it pops the next procedure off of the
     * queue, if one exists, and starts that procedure.
     *
     * @param  io_sc  The step code data struct.
     * @param  i_addr The address the command complete stopped on.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t nextStep( STEP_CODE_DATA_STRUCT & io_sc, const MemAddr & i_addr )
    {
        uint32_t rc = SUCCESS;

        if ( nullptr == iv_curProcedure ) // Nothing currently in progress.
        {
            if ( iv_queue.empty() ) // No more TD procedures.
            {
                rc = defaultStep( io_sc, i_addr );
            }
            else
            {
                // Get the next entry in the queue and move forward.
                iv_curProcedure = iv_queue.getNextEntry();
                rc = nextStep( io_sc, i_addr );
            }
        }
        else
        {
            // Do the next step of the current procedure.
            bool done = false;
            rc = iv_curProcedure->nextStep( io_sc, done );
            if ( SUCCESS != rc )
            {
                // Something failed. Clean up the current command and stop.
                iv_curProcedure = nullptr; iv_queue.pop();
            }
            else if ( done )
            {
                // This procedure is done so clean it up and move on.
                iv_curProcedure = nullptr; iv_queue.pop();
                rc = nextStep( io_sc, i_addr );
            }
        }

        return rc;
    }

    /**
     * @brief Adds the TD controller state to the  capture data.
     * @param io_sc      The step code data struct.
     * @param i_startEnd Description tag for the capture data. Used to
     *        distinguish between data captured at the beginning or end of
     *        analysis.
     */
    void collectStateCaptureData( STEP_CODE_DATA_STRUCT & io_sc,
                                  const char * i_startEnd );

    /**
     * @brief  Refreshes all relevant registers that may have changed since the
     *         initial capture.
     * @param  io_sc The step code data struct.
     */
    void recaptureRegs(STEP_CODE_DATA_STRUCT & io_sc);

    /**
     * @brief  Returns the rank of the address that the command stopped on. In
     *         simics will just return the last configured rank.
     * @param  i_addr The address the command stopped on.
     * @return The rank of the address that the command stopped on.
     */
    TdRankListEntry getStopRank(const MemAddr & i_addr);


    /**
     * @brief  Checks for, and handles, any ECC errors that have triggered.
     * @param  i_chip        OCMB chip.
     * @param  i_addr        The address the command stopped on.
     * @param  o_errorsFound True if any ECC error found and handled.
     * @param  io_sc         The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t checkEcc( ExtensibleChip * i_chip, const MemAddr & i_addr,
                       bool & o_errorsFound, STEP_CODE_DATA_STRUCT & io_sc );

    #ifdef __HOSTBOOT_RUNTIME

    /**
     * @brief  Returns whether TPS has been banned on the input rank/port.
     * @param  i_chip OCMB chip.
     * @param  i_rank The target slave rank.
     * @param  i_port The target port select.
     * @return True, if this slave rank has been banned. False, otherwise.
     */
    bool isTpsBanned( ExtensibleChip * i_chip, const MemRank & i_rank,
                      uint8_t i_port )
    {
        // Check if this rank exists in the map.
        std::tuple<ExtensibleChip *, MemRank, uint8_t> e =
            std::make_tuple(i_chip, i_rank, i_port);
        return ( iv_tpsBans.end() != iv_tpsBans.find(e) );
    }

    /**
     * @brief  Clears and unmasks NCE and TCE ECC attentions.
     * @note   maskEccAttns() will not mask fetch UEs, however, this function
     *         will unmask them because it is possible that UEs exceeded
     *         threshold and were masked by the rule code.
     * @note   Only intended to be used just after completing a TD procedure.
     * @param  i_port Target memory port
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t unmaskEccAttns(uint8_t i_port);

    /**
     * @param  o_canResume True, if background scrubbing can be resumed. False,
     *                     if a new background scrub command must be started.
     * @param  io_sc       The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t canResumeBgScrub( bool & o_canResume,
                               STEP_CODE_DATA_STRUCT & io_sc );

    #endif

  private: // instance variables

    /** An MCBIST, MBA, or OCMB chip associated with this TD controller. */
    ExtensibleChip * const iv_chip;

    /** The TD queue that contains all of the pending TD procedures. */
    TdQueue iv_queue;

    /** The procedure that is currently in progress. */
    TdEntry * iv_curProcedure = nullptr;

    /** A list of all ranks behind iv_chip. */
    TdRankList<T> iv_rankList;

    /** If a non-TD command stopped somewhere in the middle of memory, PRD will
     *  need to restart that command on the next configured rank. This variable
     *  stores where the non-TD command stopped. The non-command will then be
     *  restarted on the next rank in defaultStep() after all targeted
     *  diagnostics are complete. */
    TdRankListEntry iv_stoppedRank;

    /** True if the TD controller has been initialized. False otherwise. */
    bool iv_initialized = false;

    #ifdef __HOSTBOOT_RUNTIME

    /** True if background scrubbing should be resumed after pausing on error.
     *  False if a TD procedure had been executed and background scrubbing needs
     *  to be restarted with a new command. */
    bool iv_resumeBgScrub = false;

    /** Odyssey only. True if background steering should be restarted on the
     * next address as opposed to the next rank. This is solely for scenarios
     * where a single address steer was used during error analysis and as such
     * the continue_cmd procedure cannot be used to resume background steer. */
    bool iv_restartOnNextAddr = false;

    /** Map to keep track of ranks that have banned TPS. */
    std::map< std::tuple<ExtensibleChip *, MemRank, uint8_t>, bool > iv_tpsBans;

    #else // IPL only

    /** Indicates if broadcast mode is capable on iv_chip. */
    bool iv_broadcastModeCapable = false;

    #endif

};

} // end namespace PRDF

#endif // __prdfMemTdCtlr_H

