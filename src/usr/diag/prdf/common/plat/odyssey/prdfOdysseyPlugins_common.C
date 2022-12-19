/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/odyssey/prdfOdysseyPlugins_common.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
#include <iipSystem.h>
#include <prdfExtensibleChip.H>
#include <prdfGlobal_common.H>
#include <prdfPluginMap.H>
#include <UtilHash.H>

// Platform includes
#include <prdfMemDbUtils.H>
#include <prdfMemEccAnalysis.H>
#include <prdfMemUtils.H>
#include <prdfPlatServices.H>

#include <stdio.h>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace odyssey_ocmb
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Returns PRD_NO_CLEAR_FIR_BITS if the primary attention type is
 *         CHECK_STOP or UNIT_CS
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return PRD_NO_CLEAR_FIR_BITS if CHECK_STOP or UNIT_CS attn, else SUCCESS
 */
int32_t returnNoClearFirBits( ExtensibleChip* i_chip,
                              STEP_CODE_DATA_STRUCT& io_sc )
{
    int32_t o_rc = SUCCESS;

    if ( CHECK_STOP == io_sc.service_data->getPrimaryAttnType() ||
         UNIT_CS    == io_sc.service_data->getPrimaryAttnType() ||
         UNIT_CS    == io_sc.service_data->getSecondaryAttnType() )
    {
        o_rc = PRD_NO_CLEAR_FIR_BITS;
    }

    return o_rc;
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, returnNoClearFirBits );


} // end namespace explorer_ocmb

} // end namespace PRDF
