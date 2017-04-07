/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfP9Mcbist_common.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

/** @file  prdfP9Mcbist.C
 *  @brief Contains plugin code for MCBIST on FSP.
 */

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginDef.H>
#include <prdfPluginMap.H>
#include <UtilHash.H>

namespace PRDF
{

using namespace PlatServices;
using namespace TARGETING;

namespace p9_mcbist
{

//##############################################################################
//
//                                 MCBISTFIR
//
//##############################################################################

/**
 * @brief  Plugin that captures all the registers of the MCAs attached
 *         to the MCBIST
 * @param  i_mcbChip An MCBIST chip.
 * @param  i_sc      The step code data struct.
 * @return SUCCESS
 */
int32_t CaptureMcaRegisters( ExtensibleChip * i_mcbChip,
                             STEP_CODE_DATA_STRUCT & io_sc  )
{
    #define PRDF_FUNC "[p9_mcbist::CaptureMcaRegisters] "

    CaptureData & cd = io_sc.service_data->GetCaptureData();

    // get connected MCAs
    ExtensibleChipList mcaList = getConnected( i_mcbChip, TYPE_MCA );

    // iterate over all MCAs
    for ( auto & mca : mcaList )
    {
        // capture registers of the MCA
        mca->CaptureErrorData( cd, Util::hashString("McbistCapture") );
    }

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( p9_mcbist, CaptureMcaRegisters );

} // end namespace p9_mcbist

} // end namespace PRDF
