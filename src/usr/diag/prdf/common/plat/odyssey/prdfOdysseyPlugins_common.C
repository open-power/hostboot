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
    if ( MemEcc::queryIueTh<TYPE_OCMB_CHIP>(i_chip, io_sc) )
    {
       if ( SUCCESS != MemEcc::triggerChnlFail<TYPE_OCMB_CHIP>(i_chip) )
       {
           PRDF_ERR( PRDF_FUNC "triggerChnlFail(0x%08x) failed",
           i_chip->getHuid() );
       }
    }

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

    rdffir->clearAllBits();
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

/**
 * @brief  Masks the given bit in the given FIR without clearing it.
 * @param  i_chip    OCMB chip.
 * @param  io_sc     The step code data struct.
 * @param  i_bit     The bit position to mask.
 * @param  i_regName The name of the register to mask. Should be the MASK_OR of
 *                   the FIR.
 * @return SUCCESS
 */
int32_t __maskButDontClear(ExtensibleChip * i_chip,
    STEP_CODE_DATA_STRUCT & io_sc, uint8_t i_bit, const char * i_regName)
{
    #define PRDF_FUNC "[odyssey_ocmb::__maskButDontClear] "

    PRDF_ASSERT(nullptr != i_chip);
    PRDF_ASSERT(TYPE_OCMB_CHIP == i_chip->getType());

    #ifdef __HOSTBOOT_MODULE
    // Only mask if at threshold
    if ( io_sc.service_data->IsAtThreshold() )
    {
        SCAN_COMM_REGISTER_CLASS * mask_or = i_chip->getRegister(i_regName);
        mask_or->clearAllBits();
        mask_or->SetBit(i_bit);
        if ( SUCCESS != mask_or->Write() )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed for %s on 0x%08x", i_regName,
                      i_chip->getHuid() );
        }

        // Return PRD_NO_CLEAR_FIR_BITS so the rule code doesn't clear the bit
        return PRD_NO_CLEAR_FIR_BITS;
    }
    #endif

    return SUCCESS;

    #undef PRDF_FUNC
}

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

    if (nullptr == memPort)
    {
        PRDF_ERR("odyssey_ocmb::CalloutAttachedDimmsHigh: Could not get child "
                 "MEM_PORT %d from 0x%08x", i_port, i_chip->getHuid());
    }
    else
    {
        for ( auto & dimm : getConnectedChildren(memPort, TYPE_DIMM) )
            io_sc.service_data->SetCallout( dimm, MRU_HIGH );
    }

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

/**
 * @brief   Whenever an OMI link has degraded, the bus must be reconfigured to
 *          avoid infinite retrains.
 * @param   i_chip An OCMB chip.
 * @param   io_sc  The step code data struct.
 * @returns SUCCESS always.
 */
int32_t omiDegradeRetrainWorkaround(ExtensibleChip* i_chip,
                                    STEP_CODE_DATA_STRUCT& io_sc)
{
    #ifdef __HOSTBOOT_MODULE
    auto omiTarget = getConnectedParent(i_chip->getTrgt(), TYPE_OMI);

    if (nullptr != omiTarget)
    {
        PlatServices::omiDegradeDlReconfig(omiTarget);
    }
    #endif

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(odyssey_ocmb, omiDegradeRetrainWorkaround);

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
#define ANALYZE_FETCH_NCE_TCE_PLUGIN(POS) \
int32_t AnalyzeFetchNceTce_##POS( ExtensibleChip * i_chip, \
                            STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    MemEcc::analyzeFetchNceTce<TYPE_OCMB_CHIP>( i_chip, POS, io_sc ); \
    return SUCCESS; \
} \
PRDF_PLUGIN_DEFINE( odyssey_ocmb, AnalyzeFetchNceTce_##POS );

ANALYZE_FETCH_NCE_TCE_PLUGIN(0);
ANALYZE_FETCH_NCE_TCE_PLUGIN(1);

//------------------------------------------------------------------------------

/**
 * @brief  RDF_FIR[15] - Mainline UE.
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
#define ANALYZE_FETCH_UE_PLUGIN(POS) \
int32_t AnalyzeFetchUe_##POS( ExtensibleChip * i_chip, \
                              STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    MemEcc::analyzeFetchUe<TYPE_OCMB_CHIP>( i_chip, POS, io_sc ); \
    return SUCCESS; \
} \
PRDF_PLUGIN_DEFINE( odyssey_ocmb, AnalyzeFetchUe_##POS );

ANALYZE_FETCH_UE_PLUGIN(0);
ANALYZE_FETCH_UE_PLUGIN(1);

//------------------------------------------------------------------------------

/**
 * @brief  RDF_FIR[18] - Mainline read IUE.
 * @param  i_chip OCMB chip.
 * @param  i_port Target port select.
 * @param  io_sc  The step code data struct.
 * @return PRD_NO_CLEAR_FIR_BITS if IUE threshold is reached, else SUCCESS.
 */
int32_t AnalyzeMainlineIue( ExtensibleChip * i_chip, uint8_t i_port,
                            STEP_CODE_DATA_STRUCT & io_sc )
{
    int32_t rc = SUCCESS;
    MemEcc::analyzeMainlineIue<TYPE_OCMB_CHIP>( i_chip, i_port, io_sc );
    #ifdef __HOSTBOOT_MODULE
    if ( MemEcc::queryIueTh<TYPE_OCMB_CHIP>(i_chip, io_sc) )
        rc = PRD_NO_CLEAR_FIR_BITS;
    #endif
    return rc;
}

#define ANALYZE_MAINLINE_IUE_PLUGIN(POS) \
int32_t AnalyzeMainlineIue_##POS( ExtensibleChip * i_chip, \
                                  STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return AnalyzeMainlineIue(i_chip, POS, io_sc); \
} \
PRDF_PLUGIN_DEFINE( odyssey_ocmb, AnalyzeMainlineIue_##POS );

ANALYZE_MAINLINE_IUE_PLUGIN(0);
ANALYZE_MAINLINE_IUE_PLUGIN(1);

//------------------------------------------------------------------------------

/**
 * @brief  RDF_FIR[38] - Maint IUE.
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return PRD_NO_CLEAR_FIR_BITS if IUE threshold is reached, else SUCCESS.
 */
int32_t AnalyzeMaintIue( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc )
{
    int32_t rc = SUCCESS;
    MemEcc::analyzeMaintIue<TYPE_OCMB_CHIP>( i_chip, io_sc );

    #ifdef __HOSTBOOT_MODULE

    if ( MemEcc::queryIueTh<TYPE_OCMB_CHIP>(i_chip, io_sc) )
        rc = PRD_NO_CLEAR_FIR_BITS;

    #endif

    return rc; // nothing to return to rule code
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, AnalyzeMaintIue );

//------------------------------------------------------------------------------

/**
 * @brief  RDF_FIR[20,40] - Mainline and Maint IMPE
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @param  i_port Target port select.
 * @return SUCCESS
 */
int32_t AnalyzeImpe( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc,
                     uint8_t i_port )
{
    MemEcc::analyzeImpe<TYPE_OCMB_CHIP>( i_chip, io_sc, i_port );
    return SUCCESS; // nothing to return to rule code
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, AnalyzeImpe );

#define ANALYZE_IMPE_PLUGIN(POS) \
int32_t AnalyzeImpe_##POS( ExtensibleChip * i_chip, \
                           STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return AnalyzeImpe(i_chip, io_sc, POS); \
} \
PRDF_PLUGIN_DEFINE( odyssey_ocmb, AnalyzeImpe_##POS );

ANALYZE_IMPE_PLUGIN(0);
ANALYZE_IMPE_PLUGIN(1);

//------------------------------------------------------------------------------

/**
 * @brief  RDFFIR[34] - Maintenance AUE
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t AnalyzeMaintAue( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[odyssey_ocmb::AnalyzeMaintAue] "

    MemAddr addr;
    if ( SUCCESS != getMemMaintAddr<TYPE_OCMB_CHIP>(i_chip, addr) )
    {
        PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                  i_chip->getHuid() );
    }
    else
    {
        PRDpriority dimmPriority = MRU_HIGH;
        GARD_POLICY dimmGard = GARD;
        // If there is a possible root cause in the ODP_FIR, adjust the
        // callout to MEM_PORT high, DIMM low
        if (MemUtils::checkOdpRootCause<TYPE_OCMB_CHIP>(i_chip, addr.getPort()))
        {
            TargetHandle_t memport = getConnectedChild(i_chip->getTrgt(),
                TYPE_MEM_PORT, addr.getPort());
            io_sc.service_data->SetCallout(memport, MRU_HIGH);
            dimmPriority = MRU_LOW;
            dimmGard = NO_GARD;
        }

        MemRank rank = addr.getRank();
        MemoryMru mm { i_chip->getTrgt(), rank, addr.getPort(),
                       MemoryMruData::CALLOUT_RANK };
        io_sc.service_data->SetCallout( mm, dimmPriority, dimmGard );
    }

    return SUCCESS; // nothing to return to rule code

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, AnalyzeMaintAue );

//------------------------------------------------------------------------------

/**
 * @brief  Checks for ODP data corruption root causes. Calls out MEM_PORT high,
 *         DIMM low if root cause found, else returns
 *         PRD_SCAN_COMM_REGISTER_ZERO so the rule code will make the callout
 *         using a try statement.
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @param  i_port The port position.
 * @return SUCCESS if a root cause is found, else PRD_SCAN_COMM_REGISTER_ZERO.
 */
int32_t __odpDataCorruptSideEffect( ExtensibleChip * i_chip,
    STEP_CODE_DATA_STRUCT & io_sc, uint8_t i_port )
{
    #define PRDF_FUNC "[odyssey_ocmb::odpDataCorruptSideEffect] "

    int32_t o_rc = PRD_SCAN_COMM_REGISTER_ZERO;

    if (MemUtils::checkOdpRootCause<TYPE_OCMB_CHIP>(i_chip, i_port))
    {
        TargetHandle_t memport = getConnectedChild(i_chip->getTrgt(),
            TYPE_MEM_PORT, i_port);
        io_sc.service_data->SetCallout(memport, MRU_HIGH);

        for ( auto & dimm : getConnectedChildren(memport, TYPE_DIMM) )
            io_sc.service_data->SetCallout(dimm, MRU_LOW, NO_GARD);

        // Root cause found, return SUCCESS so the rule code doesn't make
        // further callouts.
        o_rc = SUCCESS;
    }

    return o_rc;

    #undef PRDF_FUNC
}

#define PLUGIN_ODP_DATA_CORRUPT_SIDE_EFFECT(PORT) \
int32_t odpDataCorruptSideEffect_##PORT(ExtensibleChip * i_chip, \
    STEP_CODE_DATA_STRUCT & io_sc) \
{ \
    return __odpDataCorruptSideEffect(i_chip, io_sc, PORT); \
} \
PRDF_PLUGIN_DEFINE(odyssey_ocmb, odpDataCorruptSideEffect_##PORT);

PLUGIN_ODP_DATA_CORRUPT_SIDE_EFFECT(0);
PLUGIN_ODP_DATA_CORRUPT_SIDE_EFFECT(1);

//##############################################################################
//
//                               SRQ_FIR
//
//##############################################################################
/**
 * @brief  In the case where SRQFIR[46] (Firmware initiated channel fail due to
 *         IUE threshold) causes a system checkstop, the IUE bits which are
 *         left on at threshold should be blamed as the root cause. A separate
 *         log for the IUE threshold should already be committed.
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t checkIueTh( ExtensibleChip * i_chip,
                    STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[odyssey_ocmb::checkIueTh] "

    // By default, let the rule code make the callout
    uint32_t o_rc = PRD_SCAN_COMM_REGISTER_ZERO;

    // If a system checkstop occurred
    if ( CHECK_STOP == io_sc.service_data->getPrimaryAttnType() )
    {
        // Check for the IUE bits (RDFFIR[18,38])
        SCAN_COMM_REGISTER_CLASS * rdffir0 = i_chip->getRegister("RDF_FIR_0");
        SCAN_COMM_REGISTER_CLASS * rdffir1 = i_chip->getRegister("RDF_FIR_1");
        if ( SUCCESS != rdffir0->Read() || SUCCESS != rdffir1->Read() )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed for RDF_FIR on 0x%08x",
                      i_chip->getHuid() );
        }
        else
        {
            if ( rdffir0->IsBitSet(18) || rdffir0->IsBitSet(38) ||
                 rdffir1->IsBitSet(18) || rdffir1->IsBitSet(38) )
            {
                o_rc = i_chip->Analyze(io_sc, RECOVERABLE);
            }
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, checkIueTh );

//##############################################################################
//
//                             ODP_FIR
//
//##############################################################################

/**
 * @brief  Masks bits in the ODP_FIR that are possible root causes of
 *         ODP data corruption without clearing them.
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @param  i_port The port position.
 * @param  i_bit  The bit position.
 * @return SUCCESS
 */
#define PLUGIN_ODP_DATA_CORRUPT_ROOT_CAUSE(PORT, BIT) \
int32_t odpDataCorruptRootCause_##PORT##_##BIT(ExtensibleChip * i_chip, \
    STEP_CODE_DATA_STRUCT & io_sc) \
{ \
    char regName[64]; \
    sprintf(regName, "ODP_FIR_MASK_OR_%x", PORT); \
    return __maskButDontClear(i_chip, io_sc, BIT, regName); \
} \
PRDF_PLUGIN_DEFINE(odyssey_ocmb, odpDataCorruptRootCause_##PORT##_##BIT);

PLUGIN_ODP_DATA_CORRUPT_ROOT_CAUSE(0,6);
PLUGIN_ODP_DATA_CORRUPT_ROOT_CAUSE(0,9);
PLUGIN_ODP_DATA_CORRUPT_ROOT_CAUSE(0,10);
PLUGIN_ODP_DATA_CORRUPT_ROOT_CAUSE(0,11);
PLUGIN_ODP_DATA_CORRUPT_ROOT_CAUSE(0,12);
PLUGIN_ODP_DATA_CORRUPT_ROOT_CAUSE(0,13);
PLUGIN_ODP_DATA_CORRUPT_ROOT_CAUSE(1,6);
PLUGIN_ODP_DATA_CORRUPT_ROOT_CAUSE(1,9);
PLUGIN_ODP_DATA_CORRUPT_ROOT_CAUSE(1,10);
PLUGIN_ODP_DATA_CORRUPT_ROOT_CAUSE(1,11);
PLUGIN_ODP_DATA_CORRUPT_ROOT_CAUSE(1,12);
PLUGIN_ODP_DATA_CORRUPT_ROOT_CAUSE(1,13);


//##############################################################################
//
//                          CRC related errors
//
//##############################################################################

/**
 * @brief  Masks bits in the OCMB_PHY_FIR that are possible root causes of
 *         CRC errors without clearing them.
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @param  i_bit  The bit position.
 * @return SUCCESS
 */
#define PLUGIN_CRC_ERROR_ROOT_CAUSE_PHY(BIT) \
int32_t crcErrorRootCausePhy_##BIT(ExtensibleChip * i_chip, \
    STEP_CODE_DATA_STRUCT & io_sc) \
{ \
    return __maskButDontClear(i_chip, io_sc, BIT, "OCMB_PHY_FIR_MASK_OR"); \
} \
PRDF_PLUGIN_DEFINE(odyssey_ocmb, crcErrorRootCausePhy_##BIT);

PLUGIN_CRC_ERROR_ROOT_CAUSE_PHY(1);
PLUGIN_CRC_ERROR_ROOT_CAUSE_PHY(5);
PLUGIN_CRC_ERROR_ROOT_CAUSE_PHY(13);
PLUGIN_CRC_ERROR_ROOT_CAUSE_PHY(14);
PLUGIN_CRC_ERROR_ROOT_CAUSE_PHY(15);
PLUGIN_CRC_ERROR_ROOT_CAUSE_PHY(16);
PLUGIN_CRC_ERROR_ROOT_CAUSE_PHY(17);
PLUGIN_CRC_ERROR_ROOT_CAUSE_PHY(18);
PLUGIN_CRC_ERROR_ROOT_CAUSE_PHY(20);
PLUGIN_CRC_ERROR_ROOT_CAUSE_PHY(23);
PLUGIN_CRC_ERROR_ROOT_CAUSE_PHY(26);
PLUGIN_CRC_ERROR_ROOT_CAUSE_PHY(27);

/**
 * @brief  Masks bits in the DLX_FIR_MASK_OR that are possible root causes of
 *         CRC errors without clearing them.
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @param  i_bit  The bit position.
 * @return SUCCESS
 */
#define PLUGIN_CRC_ERROR_ROOT_CAUSE_DLX(BIT) \
int32_t crcErrorRootCauseDlx_##BIT(ExtensibleChip * i_chip, \
    STEP_CODE_DATA_STRUCT & io_sc) \
{ \
    return __maskButDontClear(i_chip, io_sc, BIT, "DLX_FIR_MASK_OR"); \
} \
PRDF_PLUGIN_DEFINE(odyssey_ocmb, crcErrorRootCauseDlx_##BIT);

PLUGIN_CRC_ERROR_ROOT_CAUSE_DLX(21);

//##############################################################################
//
//                      Special Clearing Plugins
//
//##############################################################################

/**
 * @brief  Helper function for clearing a register
 * @param  i_chip OCMB chip.
 * @param  i_regName Name of the register to clear.
 * @return SUCCESS
 */
void __clearReg(ExtensibleChip * i_chip, const char * i_regName)
{
    SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister(i_regName);
    reg->clearAllBits();
    uint32_t rc = reg->Write();
    if ( SUCCESS != rc )
    {
        PRDF_ERR("Write to %s failed on 0x%08x", i_regName, i_chip->getHuid());
    }
}

/**
 * @brief  Clear TP_ERR_STATUS register
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t clearTpErrStat( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    // Write 0 to the TP_ERR_STATUS to clear
    __clearReg(i_chip, "TP_ERR_STATUS");
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, clearTpErrStat );

/**
 * @brief  Clear TP_PSCOM_STATUS_ERR register
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t clearTpPscomStat(ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc)
{
    // Write 0 to the TP_PSCOM_STATUS_ERR to clear
    __clearReg(i_chip, "TP_PSCOM_STAT_ERR");
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, clearTpPscomStat );

/**
 * @brief  Clear TP_DTS_ER register
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t clearTpDtsErr(ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc)
{
    // Write 0 to the TP_DTS_ERR to clear
    __clearReg(i_chip, "TP_DTS_ERR");
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, clearTpDtsErr );

/**
 * @brief  Clear TP_FMU_ERR_RPT register
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t clearTpFmuErrRpt(ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc)
{
    // Write 0 to the TP_FMU_ERR_RPT to clear
    __clearReg(i_chip, "TP_FMU_ERR_RPT");
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, clearTpFmuErrRpt );

/**
 * @brief  Clear PCBCTL_ERR register
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t clearPcbCtlErr(ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc)
{
    // Write 0 to the PCBCTL_ERR to clear
    __clearReg(i_chip, "PCBCTL_ERR");
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, clearPcbCtlErr );

/**
 * @brief  Clear RESET_REG_B register
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t clearResetRegB(ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc)
{
    // Write 0 to the RESET_REG_B to clear
    __clearReg(i_chip, "RESET_REG_B");
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, clearResetRegB );

/**
 * @brief  Clear MEM_ERR_STATUS register
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t clearMemErrStat(ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc)
{
    // Write 0 to the MEM_ERR_STATUS to clear
    __clearReg(i_chip, "MEM_ERR_STATUS");
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, clearMemErrStat );

/**
 * @brief  Clear MEM_PSCOM_STATUS_ERR register
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t clearMemPscomStat(ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & io_sc)
{
    // Write 0 to the MEM_PSCOM_STATUS_ERR to clear
    __clearReg(i_chip, "MEM_PSCOM_STATUS_ERR");
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, clearMemPscomStat );

/**
 * @brief  Clear MEM_DTS_ERR register
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t clearMemDtsErr(ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc)
{
    // Write 0 to the MEM_DTS_ERR to clear
    __clearReg(i_chip, "MEM_DTS_ERR");
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( odyssey_ocmb, clearMemDtsErr );

} // end namespace odyssey_ocmb

} // end namespace PRDF