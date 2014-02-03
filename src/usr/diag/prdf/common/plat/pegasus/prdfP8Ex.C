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
#include <prdfPlatServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace Ex
{

/**
 * @brief   When not in MNFG mode, clear the service call flag so that
 *          thresholding will still be done, but no visible error log committed.
 * @param   i_chip EX chip
 * @param   i_sc   Step code data struct
 * @returns SUCCESS always
 */
int32_t ClearServiceCallFlag( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & i_sc )
{
    if ( i_sc.service_data->IsAtThreshold() && !mfgMode() )
    {
        i_sc.service_data->ClearFlag(ServiceDataCollector::SERVICE_CALL);
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Ex, ClearServiceCallFlag );

/**
  * @brief  Checks if parent PROC is not Venice DD1.x and not Murano DD1.x.
  * @param  i_ex             EX chip.
  * @param  o_isMurVenNotDD1 TRUE parent PROC is not Venice DD1.x and not Murano
  *         DD1.x, FALSE otherwise.
  * @return SUCCESS
  */
int32_t isMuranoVeniceNotDD1( ExtensibleChip * i_ex, bool & o_isMurVenNotDD1 )
{
    o_isMurVenNotDD1 = true;

    TargetHandle_t proc = getParentChip( i_ex->GetChipHandle() );
    if ( NULL != proc )
    {
        if ( ( (MODEL_VENICE == getProcModel(proc)) ||
               (MODEL_MURANO == getProcModel(proc)) ) &&
             ( 0x20 > getChipLevel(proc) ) )
        {
            o_isMurVenNotDD1 = false;
        }
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Ex, isMuranoVeniceNotDD1 );

} // namespace Ex ends

}// namespace PRDF ends
