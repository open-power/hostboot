/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfP8TodPlugins.C $           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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

#undef PLUGIN_TOD_UNEXPECTED_ATTN

} //namespace Proc ends

} //namespace PRDF ends
