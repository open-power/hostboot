/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/explorer/prdfExplorerPlugins_common.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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

namespace explorer_ocmb
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Plugin that initializes the data bundle.
 * @param  i_chip An OCMB chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[explorer_ocmb::Initialize] "

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

    } while(0);
    #endif

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( explorer_ocmb, Initialize );

/**
 * @brief  During system or unit checkstop analysis, this is used to determine
 *         if a chip has any active recoverable attentions.
 * @param  i_chip     An OCMB chip.
 * @param  o_hasAttns True if a recoverable attention exists on the OCMB.
 * @return SUCCESS.
 */
int32_t CheckForRecovered(ExtensibleChip * i_chip, bool & o_hasAttns)
{
    o_hasAttns = false;

    SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister("OCMB_CHIPLET_RE_FIR");
    if (SUCCESS != reg->Read())
    {
        PRDF_ERR("[CheckForRecovered] OCMB_CHIPLET_RE_FIR read failed on "
                 "0x%08x", i_chip->getHuid());
    }
    else if (0 != reg->GetBitFieldJustified(1,10)) // bits 1-10
    {
        o_hasAttns = true;
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(explorer_ocmb, CheckForRecovered);

/**
 * @brief  During system checkstop analysis, this is used to determine if a chip
 *         has any active unit checkstop attentions.
 * @param  i_chip     An OCMB chip.
 * @param  o_hasAttns True if a unit checkstop attention exists on the OCMB.
 * @return SUCCESS.
 */
int32_t CheckForUnitCs(ExtensibleChip * i_chip, bool & o_hasAttns)
{
    o_hasAttns = false;

    // Note that OCMB checkstop attentions are all reported as unit checkstops
    // and they do not directly trigger system checkstops.

    SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister("OCMB_CHIPLET_CS_FIR");
    if (SUCCESS != reg->Read())
    {
        PRDF_ERR("[CheckForUnitCs] OCMB_CHIPLET_CS_FIR read failed on 0x%08x",
                 i_chip->getHuid());
    }
    else if (0 != reg->GetBitFieldJustified(3,10)) // bits 3-12
    {
        o_hasAttns = true;
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(explorer_ocmb, CheckForUnitCs);

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
PRDF_PLUGIN_DEFINE( explorer_ocmb, PreAnalysis );

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
    #define PRDF_FUNC "[explorer_ocmb::PostAnalysis] "

    #ifdef __HOSTBOOT_RUNTIME

    // If the IUE threshold in our data bundle has been reached, we trigger
    // a channel fail. Once we trigger the channel fail, the system may crash
    // right away. Since PRD is running in the hypervisor, it is possible we
    // may not get the error log. To better our chances, we trigger the port
    // fail here after the error log has been committed.
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
PRDF_PLUGIN_DEFINE( explorer_ocmb, PostAnalysis );

/**
 * @brief  Plugin that collects OMI fail related FFDC registers from the OMIC.
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t CollectOmiFfdc( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[explorer_ocmb::CollectOmiFfdc] "

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
PRDF_PLUGIN_DEFINE( explorer_ocmb, CollectOmiFfdc );

/**
 * @brief  Plugin that queries OCMB_LFIR[33] and collects MicroChips local
 *         scratchpad registers for FFDC if it's on. OCMB_LFIR[33] will then
 *         be cleared.
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t CollectScratchpad( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[explorer_ocmb::CollectScratchpad] "

    SCAN_COMM_REGISTER_CLASS * ocmb_lfir = i_chip->getRegister("OCMB_LFIR");

    if ( SUCCESS == ocmb_lfir->Read() && ocmb_lfir->IsBitSet(33) )
    {
        // Collect the scratchpad registers and then clear OCMB_LFIR[33]
        i_chip->CaptureErrorData( io_sc.service_data->GetCaptureData(),
                                  Util::hashString("local_scratchpad") );

        #ifdef __HOSTBOOT_MODULE
        SCAN_COMM_REGISTER_CLASS * ocmb_lfir_and =
            i_chip->getRegister("OCMB_LFIR_AND");
        ocmb_lfir_and->setAllBits();
        ocmb_lfir_and->ClearBit(33);
        if ( SUCCESS != ocmb_lfir_and->Write() )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed for OCMB_LFIR_AND on "
                      "0x%08x", i_chip->getHuid() );
        }
        #endif
    }

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( explorer_ocmb, CollectScratchpad );

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
PRDF_PLUGIN_DEFINE( explorer_ocmb, returnNoClearFirBits );


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
PRDF_PLUGIN_DEFINE(explorer_ocmb, calloutBusInterface);

//##############################################################################
//
//                               OCMB_LFIR
//
//##############################################################################

/**
 * @brief  OCMB_LFIR[39:46] - Foxhound Fatal
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @param  i_lane The lane pos (0:7)
 * @return SUCCESS
 */
int32_t __foxhoundFatal( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc,
                         uint8_t i_lane )
{
    #define PRDF_FUNC "[explorer_ocmb::__foxhoundFatal] "

    char ffdcName[64];
    sprintf( ffdcName, "foxhound_lane%x", i_lane );

    i_chip->CaptureErrorData( io_sc.service_data->GetCaptureData(),
                              Util::hashString(ffdcName) );

    return SUCCESS;

    #undef PRDF_FUNC
}

#define PLUGIN_FOXHOUND_FATAL(POS) \
int32_t FoxhoundFatal_##POS( ExtensibleChip * i_chip, \
                              STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return __foxhoundFatal( i_chip, io_sc, POS ); \
} \
PRDF_PLUGIN_DEFINE( explorer_ocmb, FoxhoundFatal_##POS );

PLUGIN_FOXHOUND_FATAL(0);
PLUGIN_FOXHOUND_FATAL(1);
PLUGIN_FOXHOUND_FATAL(2);
PLUGIN_FOXHOUND_FATAL(3);
PLUGIN_FOXHOUND_FATAL(4);
PLUGIN_FOXHOUND_FATAL(5);
PLUGIN_FOXHOUND_FATAL(6);
PLUGIN_FOXHOUND_FATAL(7);

/**
 * @brief  OCMB_LFIR[31] - Can be a root cause triggering downstream x4 mode.
 *         This will mask the bit but not clear it at threshold so that
 *         OMIDLFIR[5] can blame it as a root cause later.
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return PRD_NO_CLEAR_FIR_BITS if at threshold, SUCCESS otherwise.
 */
int32_t x4RootCause( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[explorer_ocmb::x4RootCause] "

    #ifdef __HOSTBOOT_MODULE
    // Mask the bit in the OCMB_LFIR manually if we're at threshold
    if ( io_sc.service_data->IsAtThreshold() )
    {
        SCAN_COMM_REGISTER_CLASS * mask_or =
            i_chip->getRegister( "OCMB_LFIR_MASK_OR" );

        mask_or->SetBit(31);
        if ( SUCCESS != mask_or->Write() )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed for OCMB_LFIR_MASK_OR on "
                      "0x%08x", i_chip->getHuid() );
        }

        // Return PRD_NO_CLEAR_FIR_BITS so the rule code doesn't clear the bit
        return PRD_NO_CLEAR_FIR_BITS;
    }
    #endif

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( explorer_ocmb, x4RootCause );


//##############################################################################
//
//                               OMIDLFIR
//
//##############################################################################

/**
 * @brief  OMIDLFIR[0] - OMI-DL0 Fatal Error
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return PRD_SCAN_COMM_REGISTER_ZERO for the bus callout, else SUCCESS
 */
int32_t DlFatalError( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[explorer_ocmb::DlFatalError] "

    int32_t rc = SUCCESS;

    do
    {
        // Check DL0_ERROR_HOLD[52:63] to determine callout
        SCAN_COMM_REGISTER_CLASS * dl0_error_hold =
            i_chip->getRegister( "DL0_ERROR_HOLD" );

        if ( SUCCESS != dl0_error_hold->Read() )
        {
            PRDF_ERR( PRDF_FUNC "Read() Failed on DL0_ERROR_HOLD: "
                      "i_chip=0x%08x", i_chip->getHuid() );
            break;
        }

        if ( dl0_error_hold->IsBitSet(53) ||
             dl0_error_hold->IsBitSet(55) ||
             dl0_error_hold->IsBitSet(57) ||
             dl0_error_hold->IsBitSet(58) ||
             dl0_error_hold->IsBitSet(59) ||
             dl0_error_hold->IsBitSet(60) ||
             dl0_error_hold->IsBitSet(62) ||
             dl0_error_hold->IsBitSet(63) )
        {
            // callout OCMB
            io_sc.service_data->SetCallout( i_chip->getTrgt() );
        }
        else if ( dl0_error_hold->IsBitSet(54) ||
                  dl0_error_hold->IsBitSet(56) ||
                  dl0_error_hold->IsBitSet(61) )
        {
            // callout the OMI target, the OMI bus, and the OCMB.
            // Return PRD_SCAN_COMM_REGISTER_ZERO so the rule code knows to
            // make the correct callout.
            rc = PRD_SCAN_COMM_REGISTER_ZERO;
        }

    }while(0);

    return rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( explorer_ocmb, DlFatalError );

/**
 * @brief  OMIDLFIR[5] - OMI-DL0 running in degraded mode
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS if OCMB_LFIR[31] or a CRC root cause bit are found.
 *         PRD_SCAN_COMM_REGISTER_ZERO otherwise.
 */
int32_t OmiRunningInDegradedMode( ExtensibleChip * i_chip,
                                  STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[explorer_ocmb::OmiRunningInDegradedMode] "

    // Return PRD_SCAN_COMM_REGISTER_ZERO to let the rule code handle the
    // callout if no different root cause found.
    int32_t o_rc = PRD_SCAN_COMM_REGISTER_ZERO;

    // Check OCMB_LFIR[31] on, callout the explorer
    SCAN_COMM_REGISTER_CLASS * ocmb_lfir = i_chip->getRegister( "OCMB_LFIR" );
    if ( SUCCESS == ocmb_lfir->Read() && ocmb_lfir->IsBitSet(31) )
    {
        io_sc.service_data->SetCallout( i_chip->getTrgt() );
        o_rc = SUCCESS;
    }

    return o_rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( explorer_ocmb, OmiRunningInDegradedMode );

//##############################################################################
//
//                               RDFFIR
//
//##############################################################################

/**
 * @brief  Adds all attached DIMMs at HIGH priority.
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t CalloutAttachedDimmsHigh( ExtensibleChip * i_chip,
                                  STEP_CODE_DATA_STRUCT & io_sc )
{
    for ( auto & dimm : getConnectedChildren(i_chip->getTrgt(), TYPE_DIMM) )
        io_sc.service_data->SetCallout( dimm, MRU_HIGH );

    return SUCCESS; // nothing to return to rule code
}
PRDF_PLUGIN_DEFINE( explorer_ocmb, CalloutAttachedDimmsHigh );

/**
 * @brief  Plugin to clear the side-effect mainline IUEs (RDFFIR[17]) when
 *         we get a mainline UE (RDFFIR[14])
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t ClearMainlineIue( ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[explorer_ocmb::ClearMainlineIue] "

    SCAN_COMM_REGISTER_CLASS * rdffir_and = i_chip->getRegister( "RDFFIR_AND" );

    rdffir_and->setAllBits();
    rdffir_and->ClearBit(17);

    if ( SUCCESS != rdffir_and->Write() )
    {
        PRDF_ERR( PRDF_FUNC "Write() failed on RDFFFIR_AND. i_chip huid=0x%08x",
                  i_chip->getHuid() );
    }

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( explorer_ocmb, ClearMainlineIue );

//------------------------------------------------------------------------------

/**
 * @brief  RDFFIR[0:7] - Mainline MPE.
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
#define PLUGIN_FETCH_MPE_ERROR( RANK ) \
int32_t AnalyzeFetchMpe_##RANK( ExtensibleChip * i_chip, \
                                STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    MemRank rank ( RANK ); \
    MemEcc::analyzeFetchMpe<TYPE_OCMB_CHIP>( i_chip, rank, io_sc ); \
    return SUCCESS; \
} \
PRDF_PLUGIN_DEFINE( explorer_ocmb, AnalyzeFetchMpe_##RANK );

PLUGIN_FETCH_MPE_ERROR( 0 )
PLUGIN_FETCH_MPE_ERROR( 1 )
PLUGIN_FETCH_MPE_ERROR( 2 )
PLUGIN_FETCH_MPE_ERROR( 3 )
PLUGIN_FETCH_MPE_ERROR( 4 )
PLUGIN_FETCH_MPE_ERROR( 5 )
PLUGIN_FETCH_MPE_ERROR( 6 )
PLUGIN_FETCH_MPE_ERROR( 7 )

#undef PLUGIN_FETCH_MPE_ERROR

//------------------------------------------------------------------------------

/**
 * @brief  RDFFIR[8:9] - Mainline NCE and/or TCE.
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
PRDF_PLUGIN_DEFINE( explorer_ocmb, AnalyzeFetchNceTce );

//------------------------------------------------------------------------------

/**
 * @brief  RDFFIR[14] - Mainline UE.
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t AnalyzeFetchUe( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc )
{
    MemEcc::analyzeFetchUe<TYPE_OCMB_CHIP>( i_chip, io_sc );
    return SUCCESS; // nothing to return to rule code
}
PRDF_PLUGIN_DEFINE( explorer_ocmb, AnalyzeFetchUe );

//------------------------------------------------------------------------------

/**
 * @brief  RDFFIR[17] - Mainline read IUE.
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return PRD_NO_CLEAR_FIR_BITS if IUE threshold is reached, else SUCCESS.
 */
int32_t AnalyzeMainlineIue( ExtensibleChip * i_chip,
                            STEP_CODE_DATA_STRUCT & io_sc )
{
    int32_t rc = SUCCESS;
    MemEcc::analyzeMainlineIue<TYPE_OCMB_CHIP>( i_chip, io_sc );

    #ifdef __HOSTBOOT_MODULE

    if ( MemEcc::queryIueTh<TYPE_OCMB_CHIP>(i_chip, io_sc) )
        rc = PRD_NO_CLEAR_FIR_BITS;

    #endif

    return rc; // nothing to return to rule code
}
PRDF_PLUGIN_DEFINE( explorer_ocmb, AnalyzeMainlineIue );

//------------------------------------------------------------------------------

/**
 * @brief  RDFFIR[37] - Maint IUE.
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
PRDF_PLUGIN_DEFINE( explorer_ocmb, AnalyzeMaintIue );

//------------------------------------------------------------------------------

/**
 * @brief  RDFFIR[19,39] - Mainline and Maint IMPE
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t AnalyzeImpe( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    MemEcc::analyzeImpe<TYPE_OCMB_CHIP>( i_chip, io_sc );
    return SUCCESS; // nothing to return to rule code
}
PRDF_PLUGIN_DEFINE( explorer_ocmb, AnalyzeImpe );

//------------------------------------------------------------------------------

/**
 * @brief  RDFFIR[13,16] - Mainline AUE and IAUE
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t AnalyzeFetchAueIaue( ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[explorer_ocmb::AnalyzeFetchAueIaue] "

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
PRDF_PLUGIN_DEFINE( explorer_ocmb, AnalyzeFetchAueIaue );

//------------------------------------------------------------------------------

/**
 * @brief  RDFFIR[33] - Maintenance AUE
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t AnalyzeMaintAue( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[explorer_ocmb::AnalyzeMaintAue] "

    MemAddr addr;
    if ( SUCCESS != getMemMaintAddr<TYPE_OCMB_CHIP>(i_chip, addr) )
    {
        PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
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
PRDF_PLUGIN_DEFINE( explorer_ocmb, AnalyzeMaintAue );


//##############################################################################
//
//                               TLXFIR
//
//##############################################################################

/**
 * @brief  Clear/Mask TLXFIR[9]
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t clearAndMaskTlxtRe( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[explorer_ocmb::clearAndMaskTlxtRe] "

    do
    {
        // If we are at threshold, mask TLXFIR[9].
        if ( io_sc.service_data->IsAtThreshold() )
        {
            SCAN_COMM_REGISTER_CLASS * tlxfir_mask_or =
                i_chip->getRegister( "TLXFIR_MASK_OR" );

            tlxfir_mask_or->SetBit(9);
            if ( SUCCESS != tlxfir_mask_or->Write() )
            {
                PRDF_ERR( PRDF_FUNC "Write() Failed on TLXFIR_MASK_OR: "
                          "i_chip=0x%08x", i_chip->getHuid() );
                break;
            }
        }

        // Clear TLXFIR[9]
        SCAN_COMM_REGISTER_CLASS * tlxfir_and =
            i_chip->getRegister( "TLXFIR_AND" );
        tlxfir_and->setAllBits();

        tlxfir_and->ClearBit(9);
        if ( SUCCESS != tlxfir_and->Write() )
        {
            PRDF_ERR( PRDF_FUNC "Write() Failed on TLXFIR_AND: "
                      "i_chip=0x%08x", i_chip->getHuid() );
            break;
        }
    }while(0);

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( explorer_ocmb, clearAndMaskTlxtRe );

//##############################################################################
//
//                               SRQFIR
//
//##############################################################################

/**
 * @brief  In the case where SRQFIR[25] (Firmware initiated channel fail due to
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
    #define PRDF_FUNC "[explorer_ocmb::checkIueTh] "

    // By default, let the rule code make the callout
    uint32_t o_rc = PRD_SCAN_COMM_REGISTER_ZERO;

    // If a system check occurred
    if ( CHECK_STOP == io_sc.service_data->getPrimaryAttnType() )
    {
        // Check for the IUE bits (RDFFIR[17,37])
        SCAN_COMM_REGISTER_CLASS * rdffir = i_chip->getRegister("RDFFIR");
        if ( SUCCESS != rdffir->Read() )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed for RDFFIR on 0x%08x",
                      i_chip->getHuid() );
        }
        else
        {
            if ( rdffir->IsBitSet(17) || rdffir->IsBitSet(37) )
            {
                o_rc = i_chip->Analyze(io_sc, RECOVERABLE);
            }
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( explorer_ocmb, checkIueTh );


} // end namespace explorer_ocmb

} // end namespace PRDF

