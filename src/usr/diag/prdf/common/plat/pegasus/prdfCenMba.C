/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMba.C $          */
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

/** @file  prdfCenMba.C
 *  @brief Contains all common plugin code for the Centaur MBA
 */

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfPluginMap.H>

// Pegasus includes
#include <prdfCalloutUtil.H>
#include <prdfCenMbaCaptureData.H>
#include <prdfCenMbaDataBundle.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace Mba
{
// Forward Declarations

int32_t CalloutMbaAndDimm( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & i_sc, uint32_t i_port );

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Plugin that initializes the P8 Centaur MBA data bundle.
 * @param  i_mbaChip A Centaur MBA chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_mbaChip )
{
    i_mbaChip->getDataBundle() = new CenMbaDataBundle( i_mbaChip );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Mba, Initialize );

//##############################################################################
//
//                                   MBASPA
//
//##############################################################################

/**
 * @brief  MBASPA[0] - Maintenance command complete.
 * @param  i_mbaChip A Centaur MBA chip.
 * @param  i_sc      The step code data struct.
 * @return SUCCESS
 */
int32_t MaintCmdComplete( ExtensibleChip * i_mbaChip,
                          STEP_CODE_DATA_STRUCT & i_sc )
{
    #define PRDF_FUNC "[Mba::MaintCmdComplete] "

    int32_t l_rc = SUCCESS;

    CenMbaDataBundle * mbadb = getMbaDataBundle( i_mbaChip );

    // Tell the TD controller that a maintenance command complete occurred.
    l_rc = mbadb->iv_tdCtlr.handleCmdCompleteEvent( i_sc );
    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failed: i_mbaChip=0x%08x", i_mbaChip->GetId() );
        CalloutUtil::defaultError( i_sc );
    }

    // Gather capture data even if something failed above.
    // NOTE: There is no need to capture if the maintenance command complete was
    //       successful with no errors because the error log will not be
    //       committed.
    if ( !i_sc.service_data->IsDontCommitErrl() )
        CenMbaCaptureData::addMemEccData( i_mbaChip, i_sc );

    return PRD_NO_CLEAR_FIR_BITS; // FIR bits are cleared by this plugin

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Mba, MaintCmdComplete );

/**
 * @brief  Plugin to add MBA and Dimms behind port 0 to callout list.
 * @param  i_chip   mba chip
 * @param  i_sc     The step code data struct.
 * @return SUCCESS
 */
int32_t CalloutMbaAndDimmOnPort0( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & i_sc )
{
    return CalloutMbaAndDimm( i_chip, i_sc, 0);
}
PRDF_PLUGIN_DEFINE( Mba, CalloutMbaAndDimmOnPort0 );

/**
 * @brief  Plugin to add MBA and Dimms behind port 1 to callout list.
 * @param  i_chip   mba chip
 * @param  i_sc     The step code data struct.
 * @return SUCCESS
 */
int32_t CalloutMbaAndDimmOnPort1( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & i_sc )
{
    return CalloutMbaAndDimm( i_chip, i_sc, 1);
}
PRDF_PLUGIN_DEFINE( Mba, CalloutMbaAndDimmOnPort1 );

/**
 * @brief  Plugin to add MBA and Dimms behind given port to callout list.
 * @param  i_chip   mba chip
 * @param  i_sc     The step code data struct.
 * @param  i_port   Port Number.
 * @return SUCCESS
 */
int32_t CalloutMbaAndDimm( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & i_sc, uint32_t i_port )
{
    using namespace TARGETING;
    using namespace CalloutUtil;
    int32_t o_rc = SUCCESS;
    TargetHandle_t mbaTarget = i_chip->GetChipHandle();

    TargetHandleList calloutList = getConnectedDimms( mbaTarget, i_port );
    i_sc.service_data->SetCallout( mbaTarget, MRU_LOW );

    for ( TargetHandleList::iterator it = calloutList.begin();
          it != calloutList.end(); it++)
    {
       i_sc.service_data->SetCallout( *it,MRU_HIGH );
    }
    return o_rc;
}

/**
 * @brief  Plugin to mask the side effects of an RCD parity error
 * @param  i_mbaChip A Centaur MBA chip.
 * @param  i_sc      The step code data struct.
 * @return SUCCESS
 */
int32_t maskRcdParitySideEffects( ExtensibleChip * i_mbaChip,
                                    STEP_CODE_DATA_STRUCT & i_sc )
{
    #define PRDF_FUNC "[maskRcdParitySideEffects] "

    int32_t l_rc = SUCCESS;

    do
    {
        //use a data bundle to get the membuf chip
        CenMbaDataBundle * mbadb = getMbaDataBundle( i_mbaChip );
        ExtensibleChip * membChip = mbadb->getMembChip();
        if (NULL == membChip)
        {
            PRDF_ERR(PRDF_FUNC "getMembChip() failed");
            break;
        }

        //get the FIRs
        SCAN_COMM_REGISTER_CLASS * mbsFir =
            membChip->getRegister("MBSFIR");
        SCAN_COMM_REGISTER_CLASS * mbaCalFir =
            i_mbaChip->getRegister("MBACALFIR");
        SCAN_COMM_REGISTER_CLASS * mbaFir =
            i_mbaChip->getRegister("MBAFIR");

        l_rc  = mbsFir->Read();
        l_rc |= mbaCalFir->Read();
        l_rc |= mbaFir->Read();

        if (SUCCESS != l_rc)
        {
            PRDF_ERR(PRDF_FUNC "MBSFIR/MBACALFIR/MBAFIR read failed for"
                     " 0x%08x", i_mbaChip->GetId());
            break;
        }

        //get the masks for each FIR
        SCAN_COMM_REGISTER_CLASS * mbsFirMaskOr =
            membChip->getRegister("MBSFIR_MASK_OR");
        SCAN_COMM_REGISTER_CLASS * mbaCalMaskOr =
            i_mbaChip->getRegister("MBACALFIR_MASK_OR");
        SCAN_COMM_REGISTER_CLASS * mbaFirMaskOr =
            i_mbaChip->getRegister("MBAFIR_MASK_OR");

        //set the masks only if the side effect bit is set
        if (mbaFir->IsBitSet(2))
        {
            mbaFirMaskOr->SetBit(2);
            l_rc = mbaFirMaskOr->Write();
            if (SUCCESS != l_rc)
            {
                PRDF_ERR(PRDF_FUNC "MBAFIR_MASK_OR write failed for "
                         "0x%08x", i_mbaChip->GetId());
                break;
            }
        }

        if (mbaCalFir->IsBitSet(2))
        {
            mbaCalMaskOr->SetBit(2);
            l_rc = mbaCalMaskOr->Write();
            if (SUCCESS != l_rc)
            {
                PRDF_ERR(PRDF_FUNC "MBACALFIR_MASK_OR write failed for "
                         "0x%08x", i_mbaChip->GetId());
                break;
            }

        }

        if (mbaCalFir->IsBitSet(17))
        {
            mbaCalMaskOr->SetBit(17);
            l_rc = mbaCalMaskOr->Write();
            if (SUCCESS != l_rc)
            {
                PRDF_ERR(PRDF_FUNC "MBACALFIR_MASK_OR write failed for "
                         "0x%08x", i_mbaChip->GetId());
                break;
            }
        }

        if (mbsFir->IsBitSet(4))
        {
            mbsFirMaskOr->SetBit(4);
            l_rc = mbsFirMaskOr->Write();
            if (SUCCESS != l_rc)
            {
                PRDF_ERR(PRDF_FUNC "MBSFIR_MASK_OR write failed for "
                         "0x%08x", membChip->GetId());
                break;
            }

        }
    }while(0);

    return SUCCESS;
    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Mba, maskRcdParitySideEffects );


//------------------------------------------------------------------------------

/**
 * @brief   When not in MNFG mode, clear the service call flag so that
 *          thresholding will still be done, but no visible error log committed.
 * @param   i_chip MBA chip
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
PRDF_PLUGIN_DEFINE( Mba, ClearServiceCallFlag );

} // end namespace Mba

} // end namespace PRDF
