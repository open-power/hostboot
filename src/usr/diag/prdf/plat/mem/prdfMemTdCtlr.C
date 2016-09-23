/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTdCtlr.C $                  */
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

#include <prdfMemTdCtlr.H>

#include <prdfMemAddress.H>
#include <prdfP9McbistExtraSig.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::handleCmdComplete( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr::handleCmdComplete] "

    uint32_t o_rc = SUCCESS;

    do
    {
        #ifdef __HOSTBOOT_RUNTIME

        // Make sure the TD controller is initialized.
        o_rc = initialize();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "initialize() failed" );
            break;
        }

        #else // IPL only

        PRDF_ASSERT( isInMdiaMode() ); // MDIA must be running.

        // Inform MDIA the command has completed and PRD is starting analysis.
        o_rc = mdiaSendEventMsg( iv_chip->getTrgt(), MDIA::RESET_TIMER );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mdiaSendEventMsg(RESET_TIMER) failed" );
            break;
        }

        #endif

        if ( nullptr == iv_curProcedure )
        {
            // There are no TD procedures currently in progress.

            // First, keep track of where the command stopped. Must be done
            // before calling checkEcc().
            o_rc = initStoppedRank();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "initStoppedRank() failed" );
                break;
            }

            // Then, check for ECC errors, if they exist.
            bool errorsFound = false;
            o_rc = checkEcc( errorsFound, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "checkEcc(0x%08x) failed",
                          iv_chip->getHuid() );
                break;
            }

            // If the command completed successfully with no error, the error
            // log will not have any useful information. Therefore, do not
            // commit the error log. This is done to avoid useless
            // informational error logs.
            if ( !errorsFound ) io_sc.service_data->setDontCommitErrl();
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
        io_sc.service_data->setSignature( iv_chip->getHuid(),
                                          PRDFSIG_CmdComplete_ERROR );

        // Something definitely failed, so callout 2nd level support.
        io_sc.service_data->SetCallout( NextLevelSupport_ENUM, MRU_HIGH );
        io_sc.service_data->setServiceCall();

        #ifndef __HOSTBOOT_RUNTIME // IPL only

        // Tell MDIA to skip further analysis on this target.
        uint32_t l_rc = mdiaSendEventMsg( iv_chip->getTrgt(),
                                          MDIA::STOP_TESTING );
        if ( SUCCESS != l_rc )
            PRDF_ERR( PRDF_FUNC "mdiaSendEventMsg(STOP_TESTING) failed" );

        #endif
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_MCBIST>::initStoppedRank()
{
    #define PRDF_FUNC "[initStoppedRank] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Get all ports in which the command was run. In broadcast mode, the
        // rank configuration for all ports will be the same. In non-broadcast
        // mode, there will only be one MCA in the list. Therefore, we can
        // simply use the first MCA in the list for all configs.
        std::vector<ExtensibleChip *> portList;
        o_rc = getMcbistMaintPort( iv_chip, portList );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMcbistMaintPort(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // Get the rank in which the command stopped.
        MemAddr addr;
        o_rc = getMemMaintAddr<TYPE_MCBIST>( iv_chip, addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemMaintAddr<TYPE_MCBIST>(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // Update iv_stoppedRank.
        iv_stoppedRank = TdRankListEntry ( portList.front(), addr.getRank() );
        #ifndef __HOSTBOOT_RUNTIME
        // Update iv_broadcastMode.
        iv_broadcastMode = ( 1 < portList.size() );
        #endif

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_MBA>::initStoppedRank()
{
    #define PRDF_FUNC "[initStoppedRank] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Get the rank in which the command stopped.
        MemAddr addr;
        o_rc = getMemMaintAddr<TYPE_MBA>( iv_chip, addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemMaintAddr<TYPE_MBA>(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // Update iv_stoppedRank.
        iv_stoppedRank = TdRankListEntry( iv_chip, addr.getRank() );

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Avoid linker errors with the template.
template class MemTdCtlr<TYPE_MCBIST>;
template class MemTdCtlr<TYPE_MBA>;

//------------------------------------------------------------------------------

} // end namespace PRDF

