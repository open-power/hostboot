/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfP8TodPlugins.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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

/**@file   prdfP8TodPlugins.C
 * @brief  defines all the dummy TOD error plugins for hostboot platform
 */
#include <iipstep.h>
#include <prdfPluginDef.H>
#include <prdfExtensibleChip.H>
#include <iipSystem.h>
#include <prdfCalloutUtil.H>
#include <iipServiceDataCollector.h>
#include <prdfPlatUtil.H>

using namespace TARGETING;

namespace PRDF
{

namespace Proc
{

/** Defines TOD parity error plugins for hostboot */
#define PLUGIN_TOD_UNEXPECTED_ATTN( FUNC ) \
int32_t FUNC( ExtensibleChip * i_procChip, STEP_CODE_DATA_STRUCT & i_sc ) \
{ \
    PRDF_ERR( "["#FUNC"] Unexpected attention due to TOD errors on" \
              "Hostboot: HUID=0x%08x", i_procChip->GetId() ); \
    CalloutUtil::defaultError( i_sc ); \
    return SUCCESS; \
} \
PRDF_PLUGIN_DEFINE( Proc, FUNC );

PLUGIN_TOD_UNEXPECTED_ATTN( clearServiceCallFlag )
PLUGIN_TOD_UNEXPECTED_ATTN( todNewTopologyIfBackupMDMT )
PLUGIN_TOD_UNEXPECTED_ATTN( todStepCheckFault )
PLUGIN_TOD_UNEXPECTED_ATTN( requestTopologySwitch )

#undef PLUGIN_TOD_UNEXPECTED_ATTN

/**
 * @brief   Checks if TOD errors are disabled on the platform.
 * @param   i_chip      chip reporting TOD logic parity error.
 * @param   i_stepcode  The step code data struct.
 * @return  SUCCESS
 * @note    TOD errors are not expected during hostboot and its
 *          analysis is disabled during HBRT. So, just returning SUCCESS.
 *          This prevents execution of alternate resolution associated with
 *          try resolution.
 */
int32_t isTodDisabled( ExtensibleChip * i_chip,
                       STEP_CODE_DATA_STRUCT & i_stepcode )
{
    //FIXME RTC Issue 120820: Investigate behavior for manufacturing
    //environment.
    //On OPAL machine, mask TOD errors on first instance. There
    //should not be any service action.

    if( !PlatUtil::ignoreErrorForSapphire( i_stepcode ) )
    {
        CalloutUtil::defaultError( i_stepcode );
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Proc, isTodDisabled );

} //namespace Proc ends

} //namespace PRDF ends
