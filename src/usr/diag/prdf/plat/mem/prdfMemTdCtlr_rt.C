/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTdCtlr_rt.C $               */
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

/** @file  prdfMemTdCtlr_rt.C
 *  @brief A state machine for memory Targeted Diagnostics (runtime only).
 */

#include <prdfMemTdCtlr.H>

// Platform includes
#include <prdfMemScrubUtils.H>
#include <prdfPlatServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::handleTdEvent( STEP_CODE_DATA_STRUCT & io_sc,
                                      TdEntry * i_entry )
{
    #define PRDF_FUNC "[MemTdCtlr::handleTdEvent] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Make sure the TD controller is initialized.
        o_rc = initialize();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "initialize() failed on 0x%08x",
                      iv_chip->getHuid() );
            break;
        }

        // Add this entry to the queue.
        iv_queue.push( i_entry );

        // Don't interrupt a TD procedure if one is already in progress.
        if ( nullptr != iv_curProcedure ) break;

        // Stop background scrubbing.
        o_rc = stopBgScrub<T>( iv_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "stopBgScrub<T>(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // Since we had to manually stop the maintenance command, refresh all
        // relevant registers that may have changed since the initial capture.
        // TODO: RTC 166837

        // It is possible that background scrub could have found an ECC error
        // before we had a chance to stop the command. Therefore, we need to
        // call analyzeCmdComplete() first so that any ECC errors found can be
        // handled. Also, analyzeCmdComplete() will initialize the variables
        // needed so we know where to restart background scrubbing.
        bool junk = false;
        o_rc = analyzeCmdComplete( junk, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "analyzeCmdComplete(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // Move onto the next step in the state machine.
        o_rc = nextStep( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "nextStep() failed on 0x%08x",
                      iv_chip->getHuid() );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::initialize()
{
    #define PRDF_FUNC "[MemTdCtlr::initialize] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( iv_initialized ) break; // nothing to do

        // Add any unverified chip marks to the TD queue
        // TODO: RTC 171866

        // At this point, the TD controller is initialized.
        iv_initialized = true;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::defaultStep( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr::defaultStep] "

    uint32_t o_rc = SUCCESS;

    if ( iv_resumeBgScrub )
    {
        // Background scrubbing paused for FFDC collection only. Resume the
        // current command.

        iv_resumeBgScrub = false;

        PRDF_TRAC( PRDF_FUNC "Calling resumeBgScrub<T>(0x%08x)",
                   iv_chip->getHuid() );

        o_rc = resumeBgScrub<T>( iv_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "resumeBgScrub<T>(0x%08x) failed",
                      iv_chip->getHuid() );
        }
    }
    else
    {
        // A TD procedure has completed. Restart background scrubbing on the
        // next rank.

        TdRankListEntry nextRank = iv_rankList.getNext( iv_stoppedRank );

        PRDF_TRAC( PRDF_FUNC "Calling startBgScrub<T>(0x%08x, m%ds%d)",
                   nextRank.getChip()->getHuid(),
                   nextRank.getRank().getMaster(),
                   nextRank.getRank().getSlave() );

        o_rc = startBgScrub<T>( nextRank.getChip(), nextRank.getRank() );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "startBgScrub<T>(0x%08x,m%ds%d) failed",
                      nextRank.getChip()->getHuid(),
                      nextRank.getRank().getMaster(),
                      nextRank.getRank().getSlave() );
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t __checkEcc( ExtensibleChip * i_chip, TdQueue & io_queue,
                     const MemRank & i_rank, bool & o_errorsFound,
                     STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[__checkEcc] "

    uint32_t o_rc = SUCCESS;

    o_errorsFound = false;

    do
    {
        // Check for ECC errors.
        uint32_t eccAttns = 0;
        o_rc = checkEccFirs<T>( i_chip, eccAttns );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "checkEccFirs<T>(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // TODO RTC 171915

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template
uint32_t __checkEcc<TYPE_MCA>( ExtensibleChip * i_chip, TdQueue & io_queue,
                               const MemRank & i_rank, bool & o_errorsFound,
                               STEP_CODE_DATA_STRUCT & io_sc );

template
uint32_t __checkEcc<TYPE_MBA>( ExtensibleChip * i_chip, TdQueue & io_queue,
                               const MemRank & i_rank, bool & o_errorsFound,
                               STEP_CODE_DATA_STRUCT & io_sc );

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
void MemTdCtlr<T>::collectStateCaptureData( STEP_CODE_DATA_STRUCT & io_sc,
                                            const char * i_startEnd )
{
    #define PRDF_FUNC "[MemTdCtlr<T>::collectStateCaptureData] "

    // TODO RTC 167827

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Avoid linker errors with the template.
template class MemTdCtlr<TYPE_MCBIST>;
template class MemTdCtlr<TYPE_MBA>;

//------------------------------------------------------------------------------

} // end namespace PRDF


