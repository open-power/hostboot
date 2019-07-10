/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfP9Dmi_common.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginDef.H>
#include <prdfPluginMap.H>
#include <UtilHash.H> // for Util::hashString

// Platform includes
#include <prdfMemUtils.H>
#include <prdfPlatServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace cumulus_dmi
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Analysis code that is called before the main analyze() function.
 * @param  i_chip     A DMI chip.
 * @param  io_sc      The step code data struct.
 * @param  o_analyzed True if analysis is done on this chip, false otherwise.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t PreAnalysis( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc,
                     bool & o_analyzed )
{
    // The hardware team requested that we capture the MCFIR in the FFDC.
    ExtensibleChip * miChip = getConnectedParent( i_chip, TYPE_MI );
    miChip->CaptureErrorData( io_sc.service_data->GetCaptureData(),
                              Util::hashString("MirrorConfig") );

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( cumulus_dmi, PreAnalysis );

//------------------------------------------------------------------------------

} // end namespace cumulus_dmi

} // end namespace PRDF

