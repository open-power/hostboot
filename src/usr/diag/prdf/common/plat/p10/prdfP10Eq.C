/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10Eq.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace p10_eq
{

/**
 * @brief  Add all functional cores connected to this EQ to the callout list.
 * @param  i_chip EQ chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS.
 */
int32_t calloutConnectedCores(ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & io_sc)
{
    for (const auto& core : getConnectedChildren(i_chip->getTrgt(), TYPE_CORE))
    {
        io_sc.service_data->SetCallout(core, MRU_MEDA);
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(p10_eq, calloutConnectedCores);

} // namespace p10_eq

} // namespace PRDF
