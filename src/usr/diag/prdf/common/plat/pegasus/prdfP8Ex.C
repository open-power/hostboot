/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8Ex.C $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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


/** @file  prdfP8Ex.C
 *  @brief Contains all the plugin code for the PRD P8 EX chiplet
 */

#include <prdfGlobal.H>
#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>
#include <prdfMfgThresholdMgr.H>
#include <prdfMfgThresholds.H>
#include <prdfMfgThresholdFile_common.H>

namespace PRDF
{

namespace Ex
{

/**
 * @brief   When not in MNFG mode, clear the service call flag so that
 *          thresholding will still be done, but not visible errorlog.
 * @param   i_chip   Ex rulechip
 * @param   i_sc     service data collector
 * @returns Success
 */
int32_t ClearServiceCallFlag( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & i_sc )
{
    if( i_sc.service_data->IsAtThreshold() && !PlatServices::mfgMode() )
    {
        i_sc.service_data->ClearFlag(ServiceDataCollector::SERVICE_CALL);
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Ex, ClearServiceCallFlag );


} // namespace Ex ends

}// namespace PRDF ends
