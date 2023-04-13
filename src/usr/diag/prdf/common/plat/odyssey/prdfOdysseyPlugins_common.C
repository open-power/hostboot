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

/**
 * @brief  Plugin that initializes the data bundle.
 * @param  i_chip An OCMB chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[odyssey_ocmb::Initialize] "

    i_chip->getDataBundle() = new OcmbDataBundle( i_chip );

    #ifdef __HOSTBOOT_RUNTIME
    // Initialize the address configuration variable within the OcmbDataBundle
    /* TODO: Addr translation register format has changed for odyssey
    do
    {
        // Call getMcAddrTrans# to populate those instance variables with data
        // in the MC_ADDR_TRANS registers
        OcmbDataBundle * db = getOcmbDataBundle( i_chip );
        BitStringBuffer temp(64);

        if ( SUCCESS != db->iv_addrConfig.getMcAddrTrans0( temp ) )
        {
            PRDF_ERR( PRDF_FUNC "Failed to initialize mc_addr_trans0 in ocmb "
                      "data bundle for 0x%08x", i_chip->getHuid() );
            break;
        }
        if ( SUCCESS != db->iv_addrConfig.getMcAddrTrans1( temp ) )
        {
            PRDF_ERR( PRDF_FUNC "Failed to initialize mc_addr_trans1 in ocmb "
                      "data bundle for 0x%08x", i_chip->getHuid() );
            break;
        }
        if ( SUCCESS != db->iv_addrConfig.getMcAddrTrans2( temp ) )
        {
            PRDF_ERR( PRDF_FUNC "Failed to initialize mc_addr_trans2 in ocmb "
                      "data bundle for 0x%08x", i_chip->getHuid() );
            break;
        }

    } while(0);*/
    #endif

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, Initialize );

/**
 * @brief  Analysis code that is called before the main analyze() function.
 * @param  i_chip     An OCMB chip.
 * @param  io_sc      The step code data struct.
 * @param  o_analyzed True if analysis is done on this chip, false otherwise.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t PreAnalysis( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc,
                     bool & o_analyzed )
{
    // Check for a channel failure before analyzing this chip.
    o_analyzed = MemUtils::analyzeChnlFail<TYPE_OCMB_CHIP>( i_chip, io_sc );

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, PreAnalysis );

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[odyssey_ocmb::PostAnalysis] "

    #ifdef __HOSTBOOT_RUNTIME

    // If the IUE threshold in our data bundle has been reached, we trigger
    // a channel fail. Once we trigger the channel fail, the system may crash
    // right away. Since PRD is running in the hypervisor, it is possible we
    // may not get the error log. To better our chances, we trigger the port
    // fail here.
    // TODO: need to verify IUE threshold handling and update triggerChnlFail
    //if ( MemEcc::queryIueTh<TYPE_OCMB_CHIP>(i_chip, io_sc) )
    //{
    //    if ( SUCCESS != MemEcc::triggerChnlFail<TYPE_OCMB_CHIP>(i_chip) )
    //    {
    //        PRDF_ERR( PRDF_FUNC "triggerChnlFail(0x%08x) failed",
    //        i_chip->getHuid() );
    //    }
    //}

    #endif // __HOSTBOOT_RUNTIME

    // If there was a channel failure some cleanup is required to ensure
    // there are no more attentions from this channel.
    MemUtils::cleanupChnlFail<TYPE_OCMB_CHIP>( i_chip, io_sc );

    // Cleanup processor FIR bits on the other side of the channel.
    MemUtils::cleanupChnlAttns<TYPE_OCMB_CHIP>( i_chip, io_sc );

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, PostAnalysis );

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

//##############################################################################
//
//                             MCBIST_FIR
//
//##############################################################################

/**
 * @brief  MCBISTFIR[10] - MCBIST Command Complete.
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t McbistCmdComplete( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[odyssey_ocmb::McbistCmdComplete] "

    // TODO - split between HB and FSP files if needed
    #ifdef __HOSTBOOT_MODULE

    // Tell the TD controller there was a command complete attention.
    OcmbDataBundle * db = getOcmbDataBundle( i_chip );
    if ( SUCCESS != db->getTdCtlr()->handleCmdComplete(io_sc) )
    {
        // Something failed. It is possible the command complete attention has
        // not been cleared. Make the rule code do it.
        return SUCCESS;
    }
    else
    {
        // Everything was successful. Whether we started a new command or told
        // MDIA to do it, the command complete bit has already been cleared.
        // Don't do it again.
        return PRD_NO_CLEAR_FIR_BITS;
    }

    #else

    PRDF_ERR( PRDF_FUNC "not supported on FSP" );
    PRDF_ASSERT(false); // This is definitely a code bug.

    return SUCCESS;

    #endif

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, McbistCmdComplete );


} // end namespace explorer_ocmb

} // end namespace PRDF
