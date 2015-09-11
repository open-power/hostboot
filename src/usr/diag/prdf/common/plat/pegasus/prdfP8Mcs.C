/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8Mcs.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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

/** @file  prdfP8Mcs.C
 *  @brief Contains all the plugin code for the PRD P8 MCS
 */

// Framework includes
#include <iipServiceDataCollector.h>
#include <iipSystem.h>
#include <prdfExtensibleChip.H>
#include <prdfGlobal.H>
#include <prdfPluginMap.H>
#include <UtilHash.H>

// Pegasus includes
#include <prdfCalloutUtil.H>
#include <prdfCenMbaCaptureData.H>
#include <prdfCenMembufDataBundle.H>
#include <prdfLaneRepair.H>
#include <prdfP8McsDataBundle.H>
#include <prdfCenMemUtils.H>

#include <prdfP8McsExtraSig.H>

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

namespace PRDF
{

using namespace PlatServices;
using namespace TARGETING;

namespace Mcs
{

/**
 * @brief  Plugin that initializes the MCS data bundle.
 * @param  i_mcsChip An MCS chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_mcsChip )
{
    i_mcsChip->getDataBundle() = new P8McsDataBundle( i_mcsChip );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Mcs, Initialize );

/**
 * @brief Analysis code that is called before the main analyze() function.
 * @param i_mcsChip An MCS chip.
 * @param i_sc Step Code Data structure
 * @param o_analyzed TRUE if analysis has been done on this chip
 * @return failure or success
 */
int32_t PreAnalysis( ExtensibleChip * i_mcsChip, STEP_CODE_DATA_STRUCT & i_sc,
                     bool & o_analyzed )
{
    o_analyzed = false;

    // Get memory capture data.
    CaptureData & cd = i_sc.service_data->GetCaptureData();
    P8McsDataBundle * mcsdb = getMcsDataBundle( i_mcsChip );
    ExtensibleChip * membChip = mcsdb->getMembChip();
    if ( NULL != membChip )
    {
        membChip->CaptureErrorData( cd, Util::hashString("FirRegs") );
        membChip->CaptureErrorData( cd, Util::hashString("CerrRegs") );

        CenMbaCaptureData::addMemChipletFirRegs( membChip, cd );
    }

    // Check for a Centaur Checkstop
    int32_t o_rc = MemUtils::checkMcsChannelFail( i_mcsChip, i_sc );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( "[Mcs::PreAnalysis] MemUtils::checkMcsChannelFail() failed" );
    }

    return o_rc;
}
PRDF_PLUGIN_DEFINE( Mcs, PreAnalysis );

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_mcsChip MCS chip
 * @param  i_sc      The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_mcsChip,
                      STEP_CODE_DATA_STRUCT & i_sc )
{
    #define PRDF_FUNC "[Mcs::PostAnalysis] "
    int32_t l_rc = SUCCESS;

    P8McsDataBundle * mcsdb = getMcsDataBundle( i_mcsChip );
    ExtensibleChip * membChip = mcsdb->getMembChip();
    if ( NULL != membChip )
    {
        l_rc = MemUtils::chnlCsCleanup( membChip, i_sc );
        if( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "ChnlCsCleanup() failed for Membuf:0x%08X",
                      membChip->GetId() );
        }
    }

    return SUCCESS;
    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Mcs, PostAnalysis );

/**
 * @brief  Checks if spare deployed bit for DMI bus for this MCS is set.
 * @param  i_mcsChip MCS chip
 * @param  i_sc      The step code data struct.
 * @return SUCCESS if bit is on, FAIL otherwise.
 */
int32_t checkSpareBit( ExtensibleChip * i_mcsChip,
                       STEP_CODE_DATA_STRUCT & i_sc )
{
    using namespace LaneRepair;

    int32_t l_rc = FAIL; // Default is to handle the attention (via rule code).

    ExtensibleChip * mbChip = getMcsDataBundle( i_mcsChip )->getMembChip();

    if ( isSpareBitOnDMIBus(i_mcsChip, mbChip) )
    {
        // Ignore attention and do not commit the error log.
        i_sc.service_data->setDontCommitErrl();
        l_rc = SUCCESS;
    }

    return l_rc;
}
PRDF_PLUGIN_DEFINE( Mcs, checkSpareBit );

/**
 * @fn ClearMbsSecondaryBits
 * @brief Clears MBS secondary Fir bits which may come up because of MCIFIR
 * @param  i_chip       The Mcs chip.
 * @param  i_sc         ServiceDataColector.
 * @return SUCCESS.

 */
int32_t ClearMbsSecondaryBits( ExtensibleChip * i_chip,
                               STEP_CODE_DATA_STRUCT & i_sc  )
{
    #define PRDF_FUNC "[ClearMbsSecondaryBits] "

    int32_t l_rc = SUCCESS;
    do
    {
        P8McsDataBundle * mcsdb = getMcsDataBundle( i_chip );
        ExtensibleChip * membChip = mcsdb->getMembChip();

        if ( NULL == membChip ) break;

        // Not checking if MBSFIR bits are set or not.
        // Clearing them blindly as it will give better performance.
        SCAN_COMM_REGISTER_CLASS * mbsAndFir =
                                membChip->getRegister("MBSFIR_AND");

        if( NULL == mbsAndFir )
        {
            PRDF_ERR( PRDF_FUNC "Can not find MBSFIR_AND "
                       "for 0x%08x", membChip->GetId());
            break;
        }
        mbsAndFir->setAllBits();

        mbsAndFir->ClearBit(3);
        mbsAndFir->ClearBit(4);
        l_rc = mbsAndFir->Write();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "MBSFIR_AND write failed"
                       "for 0x%08x", membChip->GetId());
            break;
        }
    }while( 0 );
    return SUCCESS;

    #undef PRDF_FUNC
} PRDF_PLUGIN_DEFINE( Mcs, ClearMbsSecondaryBits );

//------------------------------------------------------------------------------

/**
 * @brief   When not in MNFG mode, clear the service call flag so that
 *          thresholding will still be done, but no visible error log committed.
 * @param   i_chip MCS chip
 * @param   i_sc   Step code data struct
 * @returns SUCCESS always
 */
int32_t ClearServiceCallFlag( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & i_sc )
{
    if ( i_sc.service_data->IsAtThreshold() && !mfgMode() &&
         (CHECK_STOP != i_sc.service_data->getPrimaryAttnType()) &&
         (!i_sc.service_data->queryFlag(ServiceDataCollector::UNIT_CS)) )
    {
        i_sc.service_data->clearServiceCall();
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Mcs, ClearServiceCallFlag );

/**
 * @brief   Checks if the parent proc chip is either a Murano at DD least 2.0
 *          or a Venice. If neither, implements the DD1 actions
 *          of MBSFIR for the specified bit.
 * @param   i_mcsChip MCS chip
 * @param   i_sc      Step code data struct
 * @return  FAIL if MuranoDD2Plus or Venice, SUCCESS otherwise
 */
int32_t dd1mcifirBit(ExtensibleChip * i_mcsChip,
                     STEP_CODE_DATA_STRUCT & i_sc,
                     uint32_t i_bitNum )
{
    int32_t l_rc = SUCCESS;
    bool isMuranoDD2Plus = false;
    bool isVenice = false;
    TargetHandle_t l_mcsTrgt = i_mcsChip->GetChipHandle();
    TargetHandle_t l_proc  = getParentChip( l_mcsTrgt );
    uint8_t l_chipLevel = getChipLevel(l_proc);
    MODEL l_model = getProcModel(l_proc);

    if( MODEL_VENICE == l_model )
        isVenice = true;
    else if( (0x20 <= l_chipLevel) && (MODEL_MURANO == l_model) )
        isMuranoDD2Plus = true;

    if(isMuranoDD2Plus || isVenice)
    {
        l_rc = FAIL;
    }
    else
    {
        i_sc.service_data->SetCallout(l_mcsTrgt, MRU_MED);
        ClearServiceCallFlag(i_mcsChip, i_sc);
        if(48 == i_bitNum)
            i_sc.service_data->SetErrorSig( PRDFSIG_MciFir_48_DD1Signature );
        else if(49 == i_bitNum)
            i_sc.service_data->SetErrorSig( PRDFSIG_MciFir_49_DD1Signature );
    }

    return l_rc;
}

#define PLUGIN_MCIFIR_DD1_CHECK( BITNUM )                     \
int32_t dd1mcifirBit##BITNUM (ExtensibleChip * i_mcsChip,     \
                              STEP_CODE_DATA_STRUCT & i_sc )  \
{                                                             \
    return dd1mcifirBit( i_mcsChip, i_sc, BITNUM );           \
}                                                             \
PRDF_PLUGIN_DEFINE( Mcs, dd1mcifirBit##BITNUM );

PLUGIN_MCIFIR_DD1_CHECK( 48 )
PLUGIN_MCIFIR_DD1_CHECK( 49 )

//------------------------------------------------------------------------------

/**
 * @brief   Handles a memory mirror action event.
 * @param   i_mcsChip An MCS chip.
 * @param   i_sc      The step code data struct
 * @returns SUCCESS always
 */
int32_t handleMirrorAction( ExtensibleChip * i_mcsChip,
                            STEP_CODE_DATA_STRUCT & i_sc )
{
    #define PRDF_FUNC "[handleMirrorAction] "

    int32_t l_rc = SUCCESS;

    do
    {
        // Get the primary MCS of the mirrored pair.
        P8McsDataBundle * mcsdb = getMcsDataBundle( i_mcsChip );
        ExtensibleChip * primcs = mcsdb->getPrimaryMirroredMcs();
        if ( NULL == primcs )
        {
            PRDF_ERR( PRDF_FUNC "getPrimaryMirroredMcs() failed: "
                      "i_mcsChip=0x%08x", i_mcsChip->GetId() );
            break;
        }

        // Manually capture the registers needed from the primary MCS.
        CaptureData & cd = i_sc.service_data->GetCaptureData();
        primcs->CaptureErrorData( cd, Util::hashString("MirrorRegs") );

        SCAN_COMM_REGISTER_CLASS * reg = primcs->getRegister("MCHWFM");
        l_rc = reg->Read();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MCHWFM: primcs=0x%08x",
                      primcs->GetId() );
            break;
        }

        if ( i_sc.service_data->IsAtThreshold() )
        {
            if ( reg->IsBitSet(1) ) // Mirror disabled.
            {
                // Error log will be predictive.
                i_sc.service_data->SetErrorSig( PRDFSIG_MirrorActionTH );
            }
            else // Mirror still enabled but getting a flood of attentions.
            {
                // Just submit the error log as hidden.
                i_sc.service_data->clearLogging();
            }
        }
        else // Under threshold
        {
            // Re-enable the mirror.
            reg->ClearBit(1);
            reg->ClearBit(2);
            reg->ClearBit(3);

            l_rc = reg->Write();
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on MCHWFM: primcs=0x%08x",
                          primcs->GetId() );
                break;
            }
        }

    } while (0);

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Mcs, handleMirrorAction );

//------------------------------------------------------------------------------

int32_t calloutInterface_dmi( ExtensibleChip * i_mcsChip,
                              STEP_CODE_DATA_STRUCT & io_sc )
{
    CalloutUtil::calloutBusInterface( i_mcsChip, MRU_LOW );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Mcs, calloutInterface_dmi );

} // end namespace Mcs
} // end namespace PRDF

