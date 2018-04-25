/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMembuf.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2018                        */
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

/** @file  prdfCenMembuf.C
 *  @brief Contains all the plugin code for the PRD Centaur Membuf
 */

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfPluginMap.H>
#include <prdfGlobal.H>
#include <iipSystem.h>
#include <UtilHash.H>

// Pegasus includes
#include <prdfCalloutUtil.H>
#include <prdfCenAddress.H>
#include <prdfCenMarkstore.H>
#include <prdfCenMbaCaptureData.H>
#include <prdfCenMbaDataBundle.H>
#include <prdfCenMbaTdCtlr_common.H>
#include <prdfCenMbaThresholds.H>
#include <prdfCenMembufDataBundle.H>
#include <prdfCenMembufExtraSig.H>
#include <prdfLaneRepair.H>
#include <prdfCenMemUtils.H>
#if !defined(__HOSTBOOT_MODULE) || defined(__HOSTBOOT_RUNTIME)
  #include <prdfCenMbaDynMemDealloc_rt.H>
#endif
#include <prdfMemEccAnalysis.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace Membuf
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Plugin that initializes the P8 Centaur Membuf data bundle.
 * @param  i_mbaChip A Centaur Membuf chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_mbaChip )
{
    i_mbaChip->getDataBundle() = new CenMembufDataBundle( i_mbaChip );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Membuf, Initialize );

//------------------------------------------------------------------------------

/**
 * @fn CheckForRecovered
 * @brief Used when the chip has a CHECK_STOP attention to check for the
 * presence of recovered errors.
 *
 * @param  i_chip       The Centaur chip.
 * @param  o_hasRecovered TRUE if a recoverable attention exists in the Centaur.
 *
 * @return SUCCESS.

 */
int32_t CheckForRecovered(ExtensibleChip * i_chip,
                          bool & o_hasRecovered)
{
    o_hasRecovered = false;

    int32_t l_rc = SUCCESS;

    SCAN_COMM_REGISTER_CLASS * l_grer = i_chip->getRegister("GLOBAL_RE_FIR");
    l_rc = l_grer->Read();

    if ( SUCCESS != l_rc )
    {
        PRDF_ERR("[CheckForRecovered] GLOBAL_RE_FIR read failed"
                 "for 0x%08x", i_chip->GetId());
    }
    else if ( 0 != l_grer->GetBitFieldJustified(1,3) )
    {
        o_hasRecovered = true;
    }

    return SUCCESS;

} PRDF_PLUGIN_DEFINE( Membuf, CheckForRecovered );

//------------------------------------------------------------------------------

/**
 * @brief Analysis code that is called before the main analyze() function.
 * @param i_mbChip A MEMBUF chip.
 * @param i_sc Step Code Data structure
 * @param o_analyzed TRUE if analysis has been done on this chip
 * @return failure or success
 */
int32_t PreAnalysis( ExtensibleChip * i_mbChip, STEP_CODE_DATA_STRUCT & i_sc,
                     bool & o_analyzed )
{
    #define PRDF_FUNC "[Membuf::PreAnalysis] "

    int32_t o_rc = SUCCESS;

    o_analyzed = false;

    // Get memory capture data.
    CaptureData & cd = i_sc.service_data->GetCaptureData();
    CenMembufDataBundle * mbdb = getMembufDataBundle( i_mbChip );
    ExtensibleChip * mcsChip = mbdb->getMcsChip();
    if ( NULL != mcsChip )
    {
        mcsChip->CaptureErrorData( cd, Util::hashString("FirRegs") );
        mcsChip->CaptureErrorData( cd, Util::hashString("CerrRegs") );

        CenMbaCaptureData::addMemChipletFirRegs( i_mbChip, cd );
    }

    // Check for a Centaur Checkstop
    do
    {
        // Skip if we're already analyzing a unit checkstop
        if ( i_sc.service_data->IsUnitCS() )
            break;

        // Skip if we're analyzing a special attention.
        // This is a required for a rare scenario when Centaur CS bit comes
        // up after attention has called PRD and PRD was still at start of
        // analysis.
        if ( SPECIAL == i_sc.service_data->getPrimaryAttnType() )
            break;

        // MCIFIR[31] is not always reliable if the unit CS originated on the
        // Centaur. This is due to packets not getting forwarded to the MCS.
        // Instead, check for non-zero GLOBAL_CS_FIR.

        SCAN_COMM_REGISTER_CLASS * fir = i_mbChip->getRegister("GLOBAL_CS_FIR");
        o_rc = fir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read GLOBAL_CS_FIR on 0x%08x",
                      i_mbChip->GetId() );
            break;
        }

        if ( fir->BitStringIsZero() ) break; // No unit checkstop

        // Set Unit checkstop flag
        i_sc.service_data->setFlag(ServiceDataCollector::UNIT_CS);
        i_sc.service_data->SetThresholdMaskId(0);

        // Set the cause attention type
        i_sc.service_data->setSecondaryAttnType(UNIT_CS);

        // Indicate that cleanup is required.
        mbdb->iv_doChnlFailCleanup = true;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Membuf, PreAnalysis );

//------------------------------------------------------------------------------

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_mbChip A Centaur chip.
 * @param  i_sc     The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_mbChip, STEP_CODE_DATA_STRUCT & i_sc )
{
    #define PRDF_FUNC "[Membuf::PostAnalysis] "
    int32_t l_rc;

    // In hostboot, we need to clear associated bits in the MCIFIR bits.
    l_rc = MemUtils::mcifirCleanup( i_mbChip, i_sc );
    if( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC "mcifirCleanup() failed");
    }

    l_rc = MemUtils::chnlCsCleanup( i_mbChip, i_sc );
    if( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC "ChnlCsCleanup() failed");
    }

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Membuf, PostAnalysis );

//##############################################################################
//
//                               DMIFIR
//
//##############################################################################

/**
 * @brief Handle lane repair spare deployed
 * @param  i_membChip A Centaur chip.
 * @param  i_sc       The step code data struct
 * @return SUCCESS
 */
int32_t spareDeployed( ExtensibleChip * i_membChip,
                       STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent( i_membChip, TYPE_MEMBUF, 0, i_sc,
                                              true );
}
PRDF_PLUGIN_DEFINE( Membuf, spareDeployed );

/**
 * @brief  Handle lane repair max spares exceeded
 * @param  i_membChip A Centaur chip.
 * @param  i_sc       The step code data struct
 * @return SUCCESS
 */
int32_t maxSparesExceeded( ExtensibleChip * i_membChip,
                           STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent( i_membChip, TYPE_MEMBUF, 0, i_sc,
                                              false );
}
PRDF_PLUGIN_DEFINE( Membuf, maxSparesExceeded );

//##############################################################################
//
//                               MBSECCFIRs
//
//##############################################################################

int32_t calloutInterface_dmi( ExtensibleChip * i_membChip,
                              STEP_CODE_DATA_STRUCT & io_sc )
{
    CalloutUtil::calloutBusInterface( i_membChip, MRU_LOW );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Membuf, calloutInterface_dmi );

} // end namespace Membuf

} // end namespace PRDF
