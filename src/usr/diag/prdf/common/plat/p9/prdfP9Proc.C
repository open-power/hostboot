/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfP9Proc.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

/** @file  prdfP9Proc.C
 *  @brief Contains all the plugin code for the PRD P9 Proc
 */

// Framework includes
#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>

// Platform includes

namespace PRDF
{

namespace Proc
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Used when the chip has a CHECK_STOP or UNIT_CS attention to check for
 *         the presence of recoverable attentions.
 * @param  i_chip         A P9 chip.
 * @param  o_hasRecovered True if the chip has a recoverable attention.
 * @return SUCCESS
 */
int32_t CheckForRecovered( ExtensibleChip * i_chip,
                           bool & o_hasRecovered )
{
    o_hasRecovered = false;

    // TODO: RTC 152590 Will be implemented later.

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p9_nimbus, Proc, CheckForRecovered );

} // end namespace Proc

} // end namespace PRDF

