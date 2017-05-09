/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfP9Xbus.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
// Framework includes
#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>

#include <prdfLaneRepair.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;
using namespace LaneRepair;

namespace p9_xbus
{

/**
 * @brief  Handles Spare Lane Deployed Event
 * @param  i_chip XBUS chip.
 * @param  io_sc  Step code data struct.
 * @return SUCCESS always
 */
int32_t spareDeployed( ExtensibleChip * i_chip,
                       STEP_CODE_DATA_STRUCT & io_sc )
{
    if ( CHECK_STOP != io_sc.service_data->getPrimaryAttnType() )
        return handleLaneRepairEvent(i_chip, io_sc, true);
    else
        return SUCCESS;
} PRDF_PLUGIN_DEFINE( p9_xbus, spareDeployed );

/**
 * @brief  Handles Max Spares Exceeded Event
 * @param  i_chip XBUS chip.
 * @param  io_sc  Step code data struct.
 * @return SUCCESS always
 */
int32_t maxSparesExceeded( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & io_sc )
{
    if ( CHECK_STOP != io_sc.service_data->getPrimaryAttnType() )
        return handleLaneRepairEvent(i_chip, io_sc, false);
    else
        return SUCCESS;
} PRDF_PLUGIN_DEFINE( p9_xbus, maxSparesExceeded );

/**
 * @brief  Handles Too Many Bus Errors Event
 * @param  i_chip XBUS chip.
 * @param  io_sc  Step code data struct.
 * @return SUCCESS always
 */
int32_t tooManyBusErrors( ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & io_sc )
{
    if ( CHECK_STOP != io_sc.service_data->getPrimaryAttnType() )
        return handleLaneRepairEvent(i_chip, io_sc, false);
    else
        return SUCCESS;
} PRDF_PLUGIN_DEFINE( p9_xbus, tooManyBusErrors );

/**
 * @brief Add callouts for an XBUS interface
 * @param  i_chip XBUS chip.
 * @param  io_sc  Step code data struct.
 * @return SUCCESS always
 */
int32_t calloutInterface_xbus( ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & io_sc )
{
    calloutBusInterface(i_chip, io_sc, MRU_LOW);
    return SUCCESS;
} PRDF_PLUGIN_DEFINE( p9_xbus, calloutInterface_xbus );

} // end namespace Proc
} // end namespace PRDF
