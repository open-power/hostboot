/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10Iohs_common.C $      */
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

#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginDef.H>
#include <prdfPluginMap.H>

#include <prdfPlatServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace p10_iohs
{

/**
 * @brief  Adds a callout for the OpenCAPI adapter on IOHS link 0.
 * @param  i_chip IOHS processor unit.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS always.
 */
int32_t opencapi_callout_l0(ExtensibleChip* i_chip,
                            STEP_CODE_DATA_STRUCT& io_sc)
{
    calloutOpenCapiAdapter(i_chip, 0, io_sc);
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(p10_iohs, opencapi_callout_l0);

/**
 * @brief  Adds a callout for the OpenCAPI adapter on IOHS link 1.
 * @param  i_chip IOHS processor unit.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS always.
 */
int32_t opencapi_callout_l1(ExtensibleChip* i_chip,
                            STEP_CODE_DATA_STRUCT& io_sc)
{
    calloutOpenCapiAdapter(i_chip, 1, io_sc);
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(p10_iohs, opencapi_callout_l1);

} // namespace p10_iohs

} // namespace PRDF

