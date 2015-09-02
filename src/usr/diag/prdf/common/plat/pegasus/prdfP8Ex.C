/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8Ex.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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


/** @file  prdfP8Ex.C
 *  @brief Contains all the plugin code for the PRD P8 EX chiplet
 */

#include <prdfGlobal.H>
#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>
#include <prdfMfgThresholdMgr.H>
#include <prdfMfgThreshold.H>
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
    if ( i_sc.service_data->IsAtThreshold() && !mfgMode() &&
         (CHECK_STOP != i_sc.service_data->getPrimaryAttnType()) &&
         (!i_sc.service_data->queryFlag(ServiceDataCollector::UNIT_CS)) )
    {
        i_sc.service_data->clearFlag(ServiceDataCollector::SERVICE_CALL);
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
