/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfPlatServices_rt.C $                */
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

/**
 * @file  prdfPlatServices_rt.C
 * @brief Wrapper code for external interfaces used by PRD.
 *
 * This file contains code that is strictly specific to Hostboot. All code that
 * is common between FSP and Hostboot should be in the respective common file.
 */

// Framework includes
#include <prdfErrlUtil.H>
#include <prdfTrace.H>

// Platform includes
#include <prdfPlatServices.H>

// Other includes
#include <runtime/interface.h>

//------------------------------------------------------------------------------

using namespace TARGETING;

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##                        Memory specific functions
//##############################################################################

void sendPageGardRequest( uint64_t i_systemAddress )
{
    #define PRDF_FUNC "[PlatServices::sendPageGardRequest] "

    do
    {
        if( !g_hostInterfaces || !g_hostInterfaces->memory_error )
        {
            PRDF_ERR(PRDF_FUNC " memory_error() interface is not defined");
            break;
        }

        int32_t rc = g_hostInterfaces->memory_error( i_systemAddress,
                                                      i_systemAddress,
                                                      MEMORY_ERROR_CE );
        if( SUCCESS != rc )
        {
            PRDF_ERR(PRDF_FUNC " memory_error() failed");
            break;
        }
    }while(0);

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void sendLmbGardRequest( uint64_t i_systemAddress, bool i_isFetchUE )
{
    //NO-OP for OPAL
}
//------------------------------------------------------------------------------

void sendDynMemDeallocRequest( uint64_t i_startAddr, uint64_t i_endAddr )
{
    #define PRDF_FUNC "[PlatServices::sendDynMemDeallocRequest] "

    do
    {
        if( !g_hostInterfaces || !g_hostInterfaces->memory_error )
        {
            PRDF_ERR(PRDF_FUNC " memory_error() interface is not defined");
            break;
        }

        int32_t rc = g_hostInterfaces->memory_error( i_startAddr,
                                                     i_endAddr,
                                                     MEMORY_ERROR_UE );
        if( SUCCESS != rc )
        {
            PRDF_ERR(PRDF_FUNC " memory_error() failed");
            break;
        }
    }while(0);

    #undef PRDF_FUNC
}

//##############################################################################
//##                    Nimbus Maintenance Command wrappers
//##############################################################################

template<>
uint32_t stopBgScrub<TYPE_MCBIST>( ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[PlatServices::stopBgScrub<TYPE_MCBIST>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCBIST == i_chip->getType() );

    uint32_t rc = SUCCESS;

    fapi2::Target<fapi2::TARGET_TYPE_MCBIST> fapiTrgt ( i_chip->getTrgt() );

    errlHndl_t errl;
    FAPI_INVOKE_HWP( errl, memdiags::stop, fapiTrgt );

    if ( nullptr != errl )
    {
        PRDF_ERR( PRDF_FUNC "memdiags::stop(0x%08x) failed", i_chip->getHuid());
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        rc = FAIL;
    }

    return rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t stopBgScrub<TYPE_MCA>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    return stopBgScrub<TYPE_MCBIST>( getConnectedParent(i_chip, TYPE_MCBIST) );
}

//##############################################################################
//##                   Centaur Maintenance Command wrappers
//##############################################################################

template<>
uint32_t stopBgScrub<TYPE_MBA>( ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[PlatServices::stopBgScrub<TYPE_MBA>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    uint32_t rc = SUCCESS;

    PRDF_ERR( PRDF_FUNC "function not implemented yet" );
/* TODO RTC 136126
    // It is safe to create a dummy command object because runtime commands do
    // not store anything for cleanupCmd() and the stopCmd() function is generic
    // for all command types. Also, since we are only stopping the command, all
    // of the parameters for the command object are junk except for the target.
    ecmdDataBufferBase i_startAddr, i_endAddr;
    mss_TimeBaseScrub cmd { getFapiTarget(i_trgt), i_startAddr, i_endAddr,
                            mss_MaintCmd::FAST_MAX_BW_IMPACT, 0, false };

    errlHndl_t errl = fapi::fapiRcToErrl( cmd.stopCmd() );
    if ( nullptr != errl )
    {
        PRDF_ERR( PRDF_FUNC "mss_TimeBaseScrub::stop(0x%08x) failed",
                  getHuid(i_trgt) );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        rc = FAIL;
    }
*/

    return rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PlatServices

} // end namespace PRDF

