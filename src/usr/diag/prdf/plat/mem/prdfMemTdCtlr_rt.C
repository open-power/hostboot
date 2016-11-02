/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTdCtlr_rt.C $               */
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

/** @file  prdfMemTdCtlr_rt.C
 *  @brief A state machine for memory Targeted Diagnostics (runtime only).
 */

#include <prdfMemTdCtlr.H>

// Framework includes

// Platform includes
#include <prdfPlatServices.H>
#include <prdfP9McbistDataBundle.H>
#include <prdfP9McbistExtraSig.H>

using namespace TARGETING;

namespace PRDF
{

template <TYPE T, typename D>
uint32_t MemTdCtlr<T,D>::handleCmdComplete( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr::handleCmdComplete] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Make sure the TD controller is initialized.
        o_rc = initialize();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "initialize() failed" );
            break;
        }

        if ( nullptr == iv_curProcedure )
        {
            // Determine why background scrubbing has stopped, add any necessary
            // procedures to the queue and move on to the next step in the state
            // machine.

            // TODO: RTC 136126 Note that since nothing is happening here at
            //       the moment, the code will simply assume the command stopped
            //       without error and background scrubbing will resume.

            // If the command completed successfully with no error, do not
            // commit the error log. This is done to suppress unnecessary
            // information error logs.
            io_sc.service_data->setDontCommitErrl();
        }

        // Move onto the next step in the state machine.
        o_rc = nextStep( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "nextStep() failed" );
            break;
        }

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failed on 0x%08x", iv_chip->getHuid() );

        // Just in case it was a legitimate command complete (error log not
        // committed) but something else failed.
        io_sc.service_data->clearDontCommitErrl();

        // Change signature indicating there was an error in analysis.
        io_sc.service_data->SetErrorSig( PRDFSIG_CmdComplete_ERROR );

        // Something definitely failed, so callout 2nd level support.
        io_sc.service_data->SetCallout( NextLevelSupport_ENUM, MRU_HIGH );
        io_sc.service_data->setServiceCall();
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TYPE T, typename D>
uint32_t MemTdCtlr<T,D>::handleTdEvent( STEP_CODE_DATA_STRUCT & io_sc,
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
        o_rc = PlatServices::stopBgScrub<T>( iv_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "stopBgScrub<T>(0x%08x) failed",
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

template <TYPE T, typename D>
uint32_t MemTdCtlr<T,D>::initialize()
{
    #define PRDF_FUNC "[MemTdCtlr::initialize] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( iv_initialized ) break; // nothing to do

        // Add any unverified chip marks to the TD queue
        // TODO: RTC 136126

        // At this point, the TD controller is initialized.
        iv_initialized = true;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TYPE T, typename D>
uint32_t MemTdCtlr<T,D>::defaultStep( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr::defaultStep] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Restart background scrubbing.
        // TODO: RTC 136126

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Avoid linker errors with the template.
template class MemTdCtlr<TYPE_MCBIST, McbistDataBundle *>;

//------------------------------------------------------------------------------

} // end namespace PRDF


