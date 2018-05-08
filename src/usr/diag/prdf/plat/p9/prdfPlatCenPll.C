/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/p9/prdfPlatCenPll.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
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

/** @file  prdfPlatCenPLL.C
 *  @brief Contains all Hostboot-only plugin code for the Centaur PLL logic.
 */

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>
#include <prdfPlatServices.H>
#include <prdfMemUtils.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace cen_centaur
{

/**
 * @brief  Optional plugin function called after analysis is complete but
 *         before PRD exits.
 * @param  i_chip A MEMBUF  chip.
 * @param  io_sc      The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PllPostAnalysis( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[Membuf::PllPostAnalysis] "

    int32_t o_rc = SUCCESS;


    do
    {
        // The PLL FIR bits have been cleared on the MEMBUF, but there are some
        // bits on the processor side of the bus that need to be cleared in
        // order to completely clear the attentions.
        MemUtils::cleanupChnlAttns<TYPE_MEMBUF>( i_chip, io_sc );

        #ifndef __HOSTBOOT_RUNTIME

        if ( isInMdiaMode() &&
             io_sc.service_data->IsAtThreshold() &&
             io_sc.service_data->isGardRequested() )
        {
            // Tell MDIA to stop testing on all attached MBAs.
            for ( auto & trgt : getConnected(i_chip->getTrgt(), TYPE_MBA) )
            {
                if ( SUCCESS != mdiaSendEventMsg(trgt, MDIA::STOP_TESTING) )
                {
                    PRDF_ERR( PRDF_FUNC "mdiaSendEventMsg(0x%08x,STOP_TESTING) "
                              "failed", getHuid(trgt) );
                    o_rc = FAIL;
                    continue; // keep going
                }
            }
        }
        #endif
    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( cen_centaur, PllPostAnalysis );

} // end namespace cen_centaur

} // end namespace PRDF
