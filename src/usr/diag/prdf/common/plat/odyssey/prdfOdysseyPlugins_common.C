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
        if ( SUCCESS != db->iv_addrConfig.getMcAddrTrans3( temp ) )
        {
            PRDF_ERR( PRDF_FUNC "Failed to initialize mc_addr_trans3 in ocmb "
                      "data bundle for 0x%08x", i_chip->getHuid() );
            break;
        }

    } while(0);
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

/**
 * @brief  Plugin to clear the side-effect mainline IUEs (RDFFIR[17]) when
 *         we get a mainline UE (RDFFIR[14])
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @param  i_port Target memory port.
 * @return SUCCESS
 */
int32_t ClearMainlineIue( ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & io_sc, uint8_t i_port )
{
    #define PRDF_FUNC "[odyssey_ocmb::ClearMainlineIue] "

    // Note: Odyssey FIRs are write to clear.

    char regName[64];

    sprintf(regName, "RDF_FIR_%x", i_port);

    SCAN_COMM_REGISTER_CLASS * rdffir = i_chip->getRegister(regName);

    rdffir->SetBit(18);

    if ( SUCCESS != rdffir->Write() )
    {
        PRDF_ERR( PRDF_FUNC "Write() failed on %s. i_chip huid=0x%08x",
                  regName, i_chip->getHuid() );
    }

    return SUCCESS;

    #undef PRDF_FUNC
}

#define CLEAR_MAINLINE_IUE(POS) \
int32_t ClearMainlineIue_##POS( ExtensibleChip * i_chip, \
                                STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return ClearMainlineIue(i_chip, io_sc, POS); \
} \
PRDF_PLUGIN_DEFINE( odyssey_ocmb, ClearMainlineIue_##POS );

CLEAR_MAINLINE_IUE(0);
CLEAR_MAINLINE_IUE(1);

//##############################################################################
//
//                             Callout plugins
//
//##############################################################################

/**
 * @brief  Calls out the entire OMI bus interface.
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t calloutBusInterface(ExtensibleChip* i_chip,
                            STEP_CODE_DATA_STRUCT& io_sc)
{
    TargetHandle_t rxTrgt = i_chip->getTrgt();
    TargetHandle_t txTrgt = getConnectedParent(rxTrgt, TYPE_OMI);

    calloutBus(io_sc, rxTrgt, txTrgt, HWAS::OMI_BUS_TYPE);

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(odyssey_ocmb, calloutBusInterface);

/**
 * @brief  Adds all attached DIMMs at HIGH priority.
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @param  i_port Target memory port.
 * @return SUCCESS
 */
int32_t CalloutAttachedDimmsHigh( ExtensibleChip * i_chip,
                                  STEP_CODE_DATA_STRUCT & io_sc,
                                  uint8_t i_port )
{
    TargetHandle_t memPort = getConnectedChild(i_chip->getTrgt(), TYPE_MEM_PORT,
                                               i_port);
    for ( auto & dimm : getConnectedChildren(memPort, TYPE_DIMM) )
        io_sc.service_data->SetCallout( dimm, MRU_HIGH );

    return SUCCESS; // nothing to return to rule code
}

#define CALLOUT_ATTACHED_DIMMS_PLUGIN(POS) \
int32_t CalloutAttachedDimmsHigh_##POS( ExtensibleChip * i_chip, \
                                        STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return CalloutAttachedDimmsHigh(i_chip, io_sc, POS); \
} \
PRDF_PLUGIN_DEFINE( odyssey_ocmb, CalloutAttachedDimmsHigh_##POS );

CALLOUT_ATTACHED_DIMMS_PLUGIN(0);
CALLOUT_ATTACHED_DIMMS_PLUGIN(1);

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

//##############################################################################
//
//                             DLX_FIR
//
//##############################################################################

/**
 * @brief  Plugin that collects OMI fail related FFDC registers from the OMIC.
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t CollectOmiFfdc( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[odyssey_ocmb::CollectOmiFfdc] "

    // Get the OMI and OMIC targets
    TargetHandle_t omiTrgt = getConnectedParent( i_chip->getTrgt(), TYPE_OMI );
    TargetHandle_t omicTrgt = getConnectedParent( omiTrgt, TYPE_OMIC );

    // Get the FFDC for the appropriate DL
    uint8_t omiPosRelOmic = omiTrgt->getAttr<ATTR_REL_POS>(); // 0:1
    char ffdcName[64];
    sprintf( ffdcName, "dl%x_ffdc", omiPosRelOmic );

    // Collect the capture data
    ExtensibleChip * omicChip = (ExtensibleChip *)systemPtr->GetChip(omicTrgt);
    if ( nullptr != omicChip )
    {
        omicChip->CaptureErrorData( io_sc.service_data->GetCaptureData(),
                                    Util::hashString(ffdcName) );
    }
    else
    {
        PRDF_ERR( PRDF_FUNC "Failed to get OMIC ExtensibleChip for trgt "
                  "huid=0x%08x.", getHuid(omicTrgt) );
    }

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, CollectOmiFfdc );

//##############################################################################
//
//                               RDF_FIR
//
//##############################################################################

/**
 * @brief  RDF_FIR[1:8] - Mainline MPE.
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
#define PLUGIN_FETCH_MPE_ERROR(PORT,RANK) \
int32_t AnalyzeFetchMpe_##PORT##_##RANK( ExtensibleChip * i_chip, \
                                         STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    MemRank rank ( RANK ); \
    MemEcc::analyzeFetchMpe<TYPE_OCMB_CHIP>( i_chip, rank, PORT, io_sc ); \
    return SUCCESS; \
} \
PRDF_PLUGIN_DEFINE( odyssey_ocmb, AnalyzeFetchMpe_##PORT##_##RANK );

PLUGIN_FETCH_MPE_ERROR(0,0);
PLUGIN_FETCH_MPE_ERROR(0,1);
PLUGIN_FETCH_MPE_ERROR(0,2);
PLUGIN_FETCH_MPE_ERROR(0,3);
PLUGIN_FETCH_MPE_ERROR(0,4);
PLUGIN_FETCH_MPE_ERROR(0,5);
PLUGIN_FETCH_MPE_ERROR(0,6);
PLUGIN_FETCH_MPE_ERROR(0,7);
PLUGIN_FETCH_MPE_ERROR(1,0);
PLUGIN_FETCH_MPE_ERROR(1,1);
PLUGIN_FETCH_MPE_ERROR(1,2);
PLUGIN_FETCH_MPE_ERROR(1,3);
PLUGIN_FETCH_MPE_ERROR(1,4);
PLUGIN_FETCH_MPE_ERROR(1,5);
PLUGIN_FETCH_MPE_ERROR(1,6);
PLUGIN_FETCH_MPE_ERROR(1,7);

#undef PLUGIN_FETCH_MPE_ERROR

//------------------------------------------------------------------------------

/**
 * @brief  RDF_FIR[9:10] - Mainline NCE and/or TCE.
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t AnalyzeFetchNceTce( ExtensibleChip * i_chip,
                            STEP_CODE_DATA_STRUCT & io_sc )
{
    MemEcc::analyzeFetchNceTce<TYPE_OCMB_CHIP>( i_chip, io_sc );
    return SUCCESS; // nothing to return to rule code
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, AnalyzeFetchNceTce );

//------------------------------------------------------------------------------

/**
 * @brief  RDF_FIR[14,17] - Mainline AUE and IAUE
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t AnalyzeFetchAueIaue( ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[odyssey_ocmb::AnalyzeFetchAueIaue] "

    MemAddr addr;
    if ( SUCCESS != getMemReadAddr<TYPE_OCMB_CHIP>(i_chip,
                                                   MemAddr::READ_AUE_ADDR,
                                                   addr) )
    {
        PRDF_ERR( PRDF_FUNC "getMemReadAddr(0x%08x,READ_AUE_ADDR) failed",
                  i_chip->getHuid() );
    }
    else
    {
        MemRank rank = addr.getRank();
        MemoryMru mm { i_chip->getTrgt(), rank, MemoryMruData::CALLOUT_RANK };
        io_sc.service_data->SetCallout( mm, MRU_HIGH );
    }

    return SUCCESS; // nothing to return to rule code

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, AnalyzeFetchAueIaue );

} // end namespace odyssey_ocmb

} // end namespace PRDF
