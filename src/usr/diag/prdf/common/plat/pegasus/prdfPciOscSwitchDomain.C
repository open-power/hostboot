/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfPciOscSwitchDomain.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

/** @file  PciOscSwitchDomain.C
 *  @brief Definition of PllDomain class
 */

#include <iipscr.h>
#include <iipsdbug.h>
#include <iipServiceDataCollector.h>
#include <prdfErrorSignature.H>
#include <iipResolution.h>
#include <prdfPlatServices.H>
#include <prdfPluginDef.H>
#include <prdfGlobal.H>
#include <iipSystem.h>
#include <UtilHash.H>
#include <prdfPciOscSwitchDomain.H>
#include <prdfP8ProcExtraSig.H>

#ifndef __HOSTBOOT_MODULE
#include <hdctContent.H>
#include <prdfSdcFileControl.H>
#endif

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

int32_t PciOscSwitchDomain::Initialize(void)
{
    return SUCCESS;
}

//------------------------------------------------------------------------------

bool PciOscSwitchDomain::Query(ATTENTION_TYPE attentionType)
{
    #define  PRDF_FUNC  "PciOscSwitchDomain::Query "
    bool errorFound = false;

    // Only check for PCI osc switchover on redundant clock systems
    // System always checks for RE's first, even if there is an XSTOP
    // So we only need to check for PLL errors on RECOVERABLE type
    if( hasRedundantClocks() && ( attentionType == RECOVERABLE ) )
    {
        // check sysdbug for attention first
        SYSTEM_DEBUG_CLASS sysdbug;
        for( unsigned int index = 0;
             (index < GetSize()) && (errorFound == false); ++index )
        {
            ExtensibleChip * l_chip = LookUp( index );
            TARGETING::TargetHandle_t l_chipTgt = l_chip->GetChipHandle();
            bool l_analysisPending =
                  sysdbug.isActiveAttentionPending( l_chipTgt, RECOVERABLE );

            if( l_analysisPending )
            {
                ExtensibleChipFunction * l_query =
                            l_chip->getExtensibleFunction("queryPciOscErr");
                int32_t rc = (*l_query)(l_chip,
                          PluginDef::bindParm< bool &>(errorFound) );

                // if rc then scom read failed - Error log has already
                // been generated.

                if( PRD_POWER_FAULT == rc )
                {
                    PRDF_ERR( PRDF_FUNC "Power Fault detected!" );
                    break;
                }

                if( SUCCESS != rc )
                {
                    PRDF_ERR( PRDF_FUNC "SCOM fail. RC=%x", rc );
                }
            }
        }
    }

    #undef PRDF_FUNC
    return errorFound;
}

//------------------------------------------------------------------------------
int32_t PciOscSwitchDomain::Analyze( STEP_CODE_DATA_STRUCT & i_sc,
                                     ATTENTION_TYPE i_attentionType )
{
    #define PRDF_FUNC "PciOscSwitchDomain::Analyze "

    int32_t o_rc = SUCCESS;
    bool foundAttn = false;

    for( uint32_t index = 0; index < GetSize(); ++index )
    {
        ExtensibleChip * l_chip = LookUp( index );
        ExtensibleChipFunction * l_query =
            l_chip->getExtensibleFunction( "queryPciOscErr" );

        if( NULL == l_query )
        {
            continue;
        }

        o_rc = (*l_query)(l_chip,
                          PluginDef::bindParm< bool &>(foundAttn) );

        if( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Query failed HUID: 0x%08x", l_chip->GetId() );
            break;
        }

        if( foundAttn )
        {
            // Set Signature
            i_sc.service_data->GetErrorSignature()->setChipId(
                                                        l_chip->GetId());

            PciOscConnList l_pciOscData;
            o_rc = analyzePciOscSwitch( l_chip, i_sc, l_pciOscData );

            if( SUCCESS != o_rc )
            {
                PRDF_ERR(PRDF_FUNC " PCI CLK Switch over analysis failed" );
                break;
            }

            addHwCalloutAndSignature( i_sc, l_pciOscData );

            // Set dump flag
            i_sc.service_data->SetDump( CONTENT_HW,
                                        l_chip->GetChipHandle() );
            break;
        }
    }//end of for loop

    #undef PRDF_FUNC
    return o_rc;
}

//------------------------------------------------------------------------------

int32_t PciOscSwitchDomain::analyzePciOscSwitch(
                                        ExtensibleChip * i_chip,
                                        STEP_CODE_DATA_STRUCT & i_sc,
                                        PciOscConnList & o_pciOscSwitchData )
{
    #define PRDF_FUNC "PciOscSwitchDomain::analyzePciOscSwitch "
    int32_t o_rc = SUCCESS;

    do
    {

        TargetHandle_t l_chipTgt = i_chip->GetChipHandle();
        ExtensibleChipFunction * l_anlzPci =
                i_chip->getExtensibleFunction( "analyzePciClkFailover" );

        if( NULL == l_anlzPci )
        {
            o_rc = FAIL;
            break;
        }

        TargetHandle_t nodeTgt = getConnectedParent( l_chipTgt, TYPE_NODE );

        if( NULL == nodeTgt )
        {
            PRDF_ERR( PRDF_FUNC "unable to get node HUID: 0x%08x ",
                       i_chip->GetId() );
            o_rc = FAIL;
            break;
        }

        TargetHandleList pciConProcList = getConnected( nodeTgt, TYPE_PROC );

        for( TargetHandleList::iterator it = pciConProcList.begin();
             it != pciConProcList.end(); it++ )
        {
            ExtensibleChip * l_procChip = findChip( *it );

            if( NULL == l_procChip )
            {
                PRDF_ERR( PRDF_FUNC " could not find chip 0x%08x",
                          getHuid(*it) );
                continue;
            }

            // Capture PllFIRs group
            l_procChip->CaptureErrorData(
                    i_sc.service_data->GetCaptureData(),
                    Util::hashString("PllFIRs"));

            // Call this chip's capturePllFfdc plugin if it exists.
            ExtensibleChipFunction * l_captureFfdc =
                l_procChip->getExtensibleFunction("capturePllFfdcIo", true);

            if ( NULL != l_captureFfdc )
            {
                (*l_captureFfdc)( l_procChip,
                                  PluginDef::bindParm<STEP_CODE_DATA_STRUCT &>
                                  (i_sc) );
            }

            o_rc = (*l_anlzPci)( l_procChip,
                                 PluginDef::bindParm< PciOscConnList& >
                                 ( o_pciOscSwitchData ));
            if( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "analysis failed HUID: 0x%08x",
                          l_procChip->GetId() );
                break;
            }
        }

        #ifndef __HOSTBOOT_MODULE
        ServiceDataCollector & sdc = *(i_sc.service_data);
        SyncAnalysis (sdc);  //Add call to Sync SDC
        #endif

        o_rc = clearPciSwitchError( o_pciOscSwitchData );

        if( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC " Failed to clear PCI Osc error" );
            break;
        }

    }while(0);

    #undef PRDF_FUNC

    return o_rc;
}

//------------------------------------------------------------------------------

bool PciOscSwitchDomain::checkMultiOscFailure( PciOscConnList & i_pciOscData )
{
    bool o_multipleOscFail = false;
    do
    {
        if( 0 == i_pciOscData.size() )
        {
            break;
        }

        PciOscConnList::iterator it = i_pciOscData.begin();
        uint32_t firstOscPos = it->pciOscPosition;

        for( ; it != i_pciOscData.end(); it++ )
        {
            if( firstOscPos != it->pciOscPosition )
            {
                o_multipleOscFail = true;
                break;
            }
        }

    }while(0);

    return o_multipleOscFail;
}

//------------------------------------------------------------------------------

void PciOscSwitchDomain::addHwCalloutAndSignature( STEP_CODE_DATA_STRUCT & i_sc,
                                        PciOscConnList & i_pciOscSwitchData )
{
    #define PRDF_FUNC "PciOscSwitchDomain::addHwCalloutAndSignature "
    ErrorSignature * esig = i_sc.service_data->GetErrorSignature();
    uint32_t signature = esig->getSigId();

    do
    {
        uint32_t listSize = i_pciOscSwitchData.size();

        if( 0 == listSize )
        {
            PRDF_ERR( PRDF_FUNC "PCI Osc Switch Over: Analysis failed");
            i_sc.service_data->SetCallout( NextLevelSupport_ENUM,
                                           MRU_MED, NO_GARD );
            signature = PRDFSIG_PCI_OSC_ANL_FAILED;
            break;
        }

        PciOscConnList::iterator it = i_pciOscSwitchData.begin();
        TargetHandle_t procTgt = it->pciParentProc->GetChipHandle();
        TargetHandle_t l_nodeTgt =
                getConnectedParent( procTgt, TYPE_NODE );

        if( 1 < listSize )
        {
            if( 0 == it->pciOscPosition )
            {
                signature = PRDFSIG_MULTI_PROC_PCI_OSC0_FAILOVER;
            }
            else
            {
                signature = PRDFSIG_MULTI_PROC_PCI_OSC1_FAILOVER;
            }

            if( checkMultiOscFailure( i_pciOscSwitchData ) )
            {
                PRDF_ERR( PRDF_FUNC "Multiple pci Osc failures detected");
                signature = PRDFSIG_PCI_MULTIPLE_OSC_FO;
                i_sc.service_data->SetCallout( NextLevelSupport_ENUM,
                                               MRU_MED, NO_GARD );
            }

            i_sc.service_data->SetCallout( it->pciOscCard, MRU_HIGH );
            i_sc.service_data->SetCallout( l_nodeTgt, MRU_LOW, NO_GARD );
        }
        else
        {
            // Pci Osc endpoints are not supported as gardable
            // so instead, we'll need to callout/gard the source PCI OSC
            i_sc.service_data->SetCallout( procTgt, MRU_MED, NO_GARD);
            i_sc.service_data->SetCallout( l_nodeTgt, MRU_LOW , NO_GARD );
            i_sc.service_data->SetCallout( it->pciOscCard, MRU_HIGH );
            //i_sc.service_data->SetCallout( it->procPciEndPoint, MRU_MEDA );
            //i_sc.service_data->SetCallout( it->oscPciEndPoint, MRU_MEDA );

            if( 0 == it->pciOscPosition )
            {
                signature = PRDFSIG_PCI_OSC0_FAILOVER;
            }
            else
            {
                signature = PRDFSIG_PCI_OSC1_FAILOVER;
            }
        }
    }while(0);

    i_sc.service_data->SetErrorSig( signature );
    i_sc.service_data->setServiceCall();
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t PciOscSwitchDomain::clearPciSwitchError(
                                PciOscConnList & io_oscSwitchData )
{
    #define PRDF_FUNC "PciOscSwitchDomain::clearPciSwitchError "
    uint32_t o_rc = SUCCESS;

    for( PciOscConnList::iterator it = io_oscSwitchData.begin();
         it != io_oscSwitchData.end(); it++ )
    {
        ExtensibleChipFunction * l_clrPci =
                it->pciParentProc->getExtensibleFunction("clearPciOscFailOver");

        o_rc = (* l_clrPci )( it->pciParentProc,
                      PluginDef::bindParm< uint32_t &> ( it->pciOscPosition ));

        if( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC " Failed to clear PCI clk error bits"
                      "HUID: 0x%08x", it->pciParentProc->GetId() );
            break;
        }

    }

    #undef PRDF_FUNC
    return o_rc;
}

void PciOscSwitchDomain::Order( ATTENTION_TYPE i_attentionType )
{
    //Order is not relevant.
}

ExtensibleChip * PciOscSwitchDomain::findChip( TargetHandle_t i_chipTgt )
{
    ExtensibleChip * l_procChip = NULL;
    for( uint32_t i = 0; i < GetSize(); i++ )
    {
        l_procChip = LookUp( i );
        if( i_chipTgt == l_procChip->GetChipHandle() )
        {
            break;
        }

        l_procChip = NULL;
    }

    return l_procChip;
}

} // end namespace PRDF

