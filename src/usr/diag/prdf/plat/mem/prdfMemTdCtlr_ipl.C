/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTdCtlr_ipl.C $              */
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

/** @file  prdfMemTdCtlr_ipl.C
 *  @brief A state machine for memory Targeted Diagnostics (IPL only).
 */

#include <prdfMemTdCtlr.H>

// Platform includes
#include <prdfMemExtraSig.H>
#include <prdfP9McbistDataBundle.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

template <TYPE T, typename D>
uint32_t MemTdCtlr<T,D>::handleCmdComplete( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr::handleCmdComplete] "

    PRDF_ASSERT( isInMdiaMode() ); // MDIA must be running.

    uint32_t o_rc = SUCCESS;

    TargetHandle_t trgt = iv_chip->getTrgt();

    do
    {
        // Inform MDIA the command has completed and PRD is starting analysis.
        o_rc = mdiaSendEventMsg( trgt, MDIA::RESET_TIMER );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mdiaSendEventMsg(RESET_TIMER) failed" );
            break;
        }

        if ( nullptr == iv_curProcedure )
        {
            // There is nothing currently in progress, which means the command
            // either stopped at the end of memory successfully (nothing to do,
            // so call nextStep() to initiate defaultStep()) or stopped at the
            // end of a rank due to an error (will need to add procedures to the
            // queue to handle the errors and finish the pattern test to the end
            // of memory).

            // TODO: RTC 157892 Check why the command stopped and take actions
            //       appropriately. Note that since nothing is happening here at
            //       the moment, the code will simply assume the command stopped
            //       at the end of memory with no errors.

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

        // Tell MDIA to skip further analysis on this target.
        uint32_t l_rc = mdiaSendEventMsg( trgt, MDIA::STOP_TESTING );
        if ( SUCCESS != l_rc )
            PRDF_ERR( PRDF_FUNC "mdiaSendEventMsg(STOP_TESTING) failed" );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TYPE T, typename D>
uint32_t MemTdCtlr<T,D>::defaultStep( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr::defaultStep] "

    uint32_t o_rc = SUCCESS;

    // The command complete message to MDIA must be sent after clearing the
    // attention. Otherwise, we may run into a race condition where MDIA may try
    // to start the next command before PRD clears the FIR bits.
    D db = static_cast<D>(iv_chip->getDataBundle());
    db->iv_sendCmdCompleteMsg = true;

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Avoid linker errors with the template.
template class MemTdCtlr<TYPE_MCBIST, McbistDataBundle *>;

//------------------------------------------------------------------------------

} // end namespace PRDF


