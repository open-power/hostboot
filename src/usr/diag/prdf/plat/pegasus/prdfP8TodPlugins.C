/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfP8TodPlugins.C $           */
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

/**@file   prdfP8TodPlugins.C
 * @brief  defines all the dummy TOD error plugins for hostboot platform
 */
#include <iipstep.h>
#include <prdfPluginDef.H>
#include <prdfExtensibleChip.H>
#include <iipSystem.h>
#include <prdfCalloutUtil.H>
#include <iipServiceDataCollector.h>

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

PLUGIN_TOD_UNEXPECTED_ATTN( todRestorePCRP0 )
PLUGIN_TOD_UNEXPECTED_ATTN( todRestorePCRP1 )
PLUGIN_TOD_UNEXPECTED_ATTN( todRestoreSCRP0 )
PLUGIN_TOD_UNEXPECTED_ATTN( todRestoreSCRP1 )
PLUGIN_TOD_UNEXPECTED_ATTN( todRestoreMPCR )
PLUGIN_TOD_UNEXPECTED_ATTN( todRestorePSMSCR )
PLUGIN_TOD_UNEXPECTED_ATTN( todRestoreIPCR )
PLUGIN_TOD_UNEXPECTED_ATTN( todRestoreSPCR )
PLUGIN_TOD_UNEXPECTED_ATTN( clearServiceCallFlag )
PLUGIN_TOD_UNEXPECTED_ATTN( todNewTopologyIfBackupMDMT )
PLUGIN_TOD_UNEXPECTED_ATTN( todStepCheckFault )
PLUGIN_TOD_UNEXPECTED_ATTN( requestTopologySwitch )

#undef PLUGIN_TOD_UNEXPECTED_ATTN

} //namespace Proc ends

} //namespace PRDF ends
