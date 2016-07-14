/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTdCtlr.H $                  */
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

/** @file  prdfMemTdCtlr.H
 *  @brief A state machine for memory Targeted Diagnostics (TD).
 */

#ifndef __prdfMemTdCtlr_H
#define __prdfMemTdCtlr_H

// Framework includes
#include <iipServiceDataCollector.h>

// Platform includes
#include <prdfMemTdQueue.H>
#include <prdfPlatServices.H>

namespace PRDF
{

/**
 * @brief A state machine for memory Targeted Diagnostics (TD).
 */
template <TARGETING::TYPE T, typename D>
class MemTdCtlr
{
  public:

    /**
     * @brief Constructor
     *
     * This contructor will only be called in the MCBIST or MBA data bundle,
     * which already checks for a valid type.
     *
     * @param i_chip An MCBIST or MBA chip.
     */
    explicit MemTdCtlr( ExtensibleChip * i_chip ) :
        iv_chip( i_chip )
    {
        PRDF_ASSERT( T == iv_chip->getTrgtType() );
    }

    /**
     * @brief  Determines and executes the next course of action after a
     *         maintenance command complete attention.
     * @note   Initializes the TD controller, if needed (runtime only).
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t handleCmdComplete( STEP_CODE_DATA_STRUCT & io_sc );

    #ifdef __HOSTBOOT_RUNTIME

    /**
     * @brief  Adds a new TD procedure to the queue.
     *
     * This is only supported during runtime. It is used to process TD requests
     * during analysis of attentions other than the command complete attention
     * (i.e. memory CEs and UEs). If there isn't a current TD procedure in
     * progress, this function will stop background scrubbing and start this new
     * procedure. Otherwise, this new procedure is simply added to the queue.
     *
     * It is possible that some of the other attentions my occur during the IPL
     * after Hostboot has been flushed from the cache to system memory. At that
     * point we don't have time to complete a TD procedure. Therefore, the
     * requests will be ignored. Any chip marks placed during this time will be
     * redetected when the runtime TD controller is initialized.
     *
     * @note   Initializes the TD controller, if needed.
     * @param  io_sc    The step code data struct.
     * @param  i_entry  The new TD queue entry.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t handleTdEvent( STEP_CODE_DATA_STRUCT & io_sc,
                            TdEntry<T> * i_entry );

    #endif

  private:

    /**
     * @brief This is called when there are no more TD procedures to execute.
     *
     * During Memory Diagnostics, this means the current pattern test command
     * has reached the end of memory on the MBA or MCBIST. So this function will
     * tell MDIA to move onto the next pattern test command, if needed.
     *
     * At runtime, this function will restart background scrubbing.
     *
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t defaultStep( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief Progresses onto the next step of the state machine.
     *
     * This function will move onto the next step of the current procedure, if
     * one is in progress. Otherwise, it pops the next procedure off of the
     * queue, if one exists, and starts that procedure.
     *
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t nextStep( STEP_CODE_DATA_STRUCT & io_sc )
    {
        uint32_t rc = SUCCESS;

        if ( nullptr == iv_curProcedure ) // Nothing currently in progress.
        {
            if ( iv_queue.empty() ) // No more TD procedures.
            {
                rc = defaultStep( io_sc );
            }
            else
            {
                // Get the next entry in the queue and move forward.
                iv_curProcedure = iv_queue.getNextEntry();
                rc = nextStep( io_sc );
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
                rc = nextStep( io_sc );
            }
        }

        return rc;
    }

    #ifdef __HOSTBOOT_RUNTIME

    /**
     * @brief  Initializes the TD controller, if needed.
     *
     * This is only supported during runtime. This is mostly useful at runtime
     * to query hardware for any unverified chip marks. Those may occur after
     * starting background scrubbing, but before PRD is up and running. We may
     * also have unverified chip marks if the HBRT service is stopped and
     * restarted (PRD is reinitialize and all previous state machine data is
     * lost).
     *
     * @note   Should be called at the beginning of every public function to
     *         ensure the TD controller is initialized.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t initialize();

    #endif

  private: // instance variables

    /** An MCBIST or MBA chip associated with this TD controller. */
    ExtensibleChip * const iv_chip;

    /** The TD queue that contains all of the pending TD procedures. */
    TdQueue<T> iv_queue;

    /** The procedure that is currently in progress. */
    TdEntry<T> * iv_curProcedure = nullptr;

    #ifdef __HOSTBOOT_RUNTIME

    /** True if the TD controller has been initialized. False otherwise. */
    bool iv_initialized = false;

    #endif

};

} // end namespace PRDF

#endif // __prdfMemTdCtlr_H

