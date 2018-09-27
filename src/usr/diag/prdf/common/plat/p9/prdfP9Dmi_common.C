/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfP9Dmi_common.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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

namespace p9_dmi
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
PRDF_PLUGIN_DEFINE( p9_dmi, PreAnalysis );

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_chip A DMI chip.
 * @param  io_sc  The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    // If there was a channel failure some cleanup is required to ensure
    // there are no more attentions from this channel.
    MemUtils::cleanupChnlFail<TYPE_DMI>( i_chip, io_sc );

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( p9_dmi, PostAnalysis );

//##############################################################################
//
//                                  CHIFIR
//
//##############################################################################
/**
 * @brief  Checks if we have a legitimate CHIFIR[61] channel timeout or if its
 *         a side effect of a MBSFIR[4] internal timeout.
 * @param  i_dmiChip DMI chip.
 * @param  io_sc     Step code data struct
 * @return SUCCESS if MBSFIR[4] is set but MBSFIR[3] is not.
 *         PRD_SCAN_COMM_REGISTER_ZERO otherwise.

 */
int32_t dsffChannelTimeoutCheck( ExtensibleChip * i_dmiChip,
                                  STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[dsffChannelTimeoutCheck] "

    int32_t o_rc = SUCCESS;

    ExtensibleChip * membChip = getConnectedChild( i_dmiChip, TYPE_MEMBUF, 0 );
    PRDF_ASSERT( nullptr != membChip );

    do
    {
        // Get MBSFIR
        SCAN_COMM_REGISTER_CLASS * mbsFir = membChip->getRegister("MBSFIR");

        o_rc = mbsFir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "MBSFIR read failed for 0x%08x",
                    membChip->getHuid() );
            break;
        }

        // If MBSFIR[4] is set and MBSFIR[3] is not set
        if( mbsFir->IsBitSet(4) && !mbsFir->IsBitSet(3) )
        {
            // MBSFIR[4] internal timeout, predictive centaur callout
            io_sc.service_data->SetCallout( membChip->getTrgt() );
        }
        else
        {
            // CHIFIR[61] channel timeout, predictive DMI callout
            io_sc.service_data->SetCallout( i_dmiChip->getTrgt() );
        }

    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( p9_dmi, dsffChannelTimeoutCheck );

//------------------------------------------------------------------------------

} // end namespace p9_dmi

} // end namespace PRDF

