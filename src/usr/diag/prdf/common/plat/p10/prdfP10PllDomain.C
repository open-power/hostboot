/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10PllDomain.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2003,2020                        */
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

/** @file  prdfPllDomain.C
 *  @brief Definition of PllDomain class
 */

#include <prdfPllDomain.H>

#include <CcAutoDeletePointer.h>
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
#include <prdfP10Pll.H>

#include <prdfP10ProcExtraSig.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;
using namespace PLL;

//------------------------------------------------------------------------------

int32_t PllDomain::Initialize(void)
{

  int32_t rc = SUCCESS;
  return(rc);
}

//------------------------------------------------------------------------------

bool PllDomain::Query(ATTENTION_TYPE attentionType)
{
    bool atAttn = false;
    // System always checks for RE's first, even if there is an XSTOP
    // So we only need to check for PLL errors on RECOVERABLE type
    if(attentionType == RECOVERABLE)
    {
        // check sysdbug for attention first
        SYSTEM_DEBUG_CLASS sysdbug;
        for(unsigned int index = 0; (index < GetSize()) && (atAttn == false);
            ++index)
        {
            ExtensibleChip * l_chip = LookUp( index );
            TARGETING::TargetHandle_t l_chipTgt = l_chip->getTrgt();
            bool l_analysisPending =
                  sysdbug.isActiveAttentionPending( l_chipTgt, RECOVERABLE );

            if( l_analysisPending )
            {
                // Check if any clock errors are present
                uint32_t l_errType = 0;
                ExtensibleChipFunction * l_query =
                    l_chip->getExtensibleFunction("CheckErrorType");
                int32_t rc = (*l_query)(l_chip,
                    PluginDef::bindParm<uint32_t &> (l_errType));

                // Check if clock errors apply to this domain
                if ( GetId() == CLOCK_DOMAIN_IO )
                {
                    if ( ( l_errType & PCI_PLL_UNLOCK ) ||
                         ( l_errType & PCI_OSC_FAILOVER ) )
                        atAttn = true;
                }
                else
                {
                    if ( ( l_errType & SYS_PLL_UNLOCK ) ||
                         ( l_errType & SYS_OSC_FAILOVER ) )
                        atAttn = true;
                }

                // if rc then scom read failed
                // Error log has already been generated
                if( PRD_POWER_FAULT == rc )
                {
                    PRDF_ERR( "prdfPllDomain::Query() Power Fault detected!" );
                    break;
                }
                else if(SUCCESS != rc)
                {
                    PRDF_ERR( "prdfPllDomain::Query() SCOM fail. RC=%x", rc );
                }
            }
        }
    }

    return(atAttn);
}

//------------------------------------------------------------------------------

void mfClockResolution( STEP_CODE_DATA_STRUCT &io_sc,
                        std::vector<ExtensibleChip *> i_chipList )
{
    for ( auto chip : i_chipList )
    {
        bool bothClocksFailed = false;
        TargetHandle_t chipTgt = chip->getTrgt();

        SCAN_COMM_REGISTER_CLASS *oscSw = chip->getRegister("OSC_SW_SENSE");
        uint32_t l_rc = oscSw->Read();
        if ( SUCCESS == l_rc )
        {
            const uint32_t OSC_0_OK = 28;
            const uint32_t OSC_1_OK = 29;
            if ( !(oscSw->IsBitSet(OSC_0_OK) || oscSw->IsBitSet(OSC_1_OK) ) )
            {
                bothClocksFailed = true;

                // Callout both PCI Clocks
                #ifndef __HOSTBOOT_MODULE
                TargetHandle_t pciOsc =
                    getClockId( chipTgt, TYPE_OSCPCICLK, 0 );
                if (pciOsc)
                    io_sc.service_data->SetCallout( pciOsc );

                pciOsc = getClockId( chipTgt, TYPE_OSCPCICLK, 1 );
                if (pciOsc)
                    io_sc.service_data->SetCallout( pciOsc );

                #else
                io_sc.service_data->SetCallout( PRDcallout(chipTgt,
                                                PRDcalloutData::TYPE_PCICLK0));
                io_sc.service_data->SetCallout( PRDcallout(chipTgt,
                                                PRDcalloutData::TYPE_PCICLK1));
                #endif
            }
        }
        else
        {
            PRDF_ERR( "ClockResolution::Resolve "
                      "Read() failed on OSC_SW_SENSE huid 0x%08X", chipTgt );
        }

        if ( !bothClocksFailed )
        {
            TargetHandle_t l_ptargetClock =
                PlatServices::getActiveRefClk(chipTgt, TYPE_OSCPCICLK);

            // Callout this chip if nothing else.
            if(nullptr == l_ptargetClock)
            {
                l_ptargetClock = chipTgt;
            }

            // callout the clock source
            // HB does not have the osc target modeled
            // so we need to use the proc target with
            // osc clock type to call out
            #ifndef __HOSTBOOT_MODULE
            io_sc.service_data->SetCallout(l_ptargetClock);
            #else
            io_sc.service_data->SetCallout( PRDcallout(l_ptargetClock,
                                            PRDcalloutData::TYPE_PCICLK));
            #endif
        }
    }
}

int32_t PllDomain::Analyze(STEP_CODE_DATA_STRUCT & serviceData,
                           ATTENTION_TYPE attentionType)
{
    #define PRDF_FUNC "[PllDomain::Analyze] "
    std::vector<ExtensibleChip *> pllUnlockList;
    std::vector<ExtensibleChip *> failoverList;
    int32_t rc = SUCCESS;
    uint32_t mskErrType =  0;

    // Due to clock issues some chips may be moved to non-functional during
    // analysis. In this case, these chips will need to be removed from their
    // domains.
    std::vector<ExtensibleChip *>  nfchips;

    // Examine each chip in domain
    for(unsigned int index = 0; index < GetSize(); ++index)
    {
        uint32_t l_errType = 0;

        ExtensibleChip * l_chip = LookUp(index);

        if ( !PlatServices::isFunctional(l_chip->getTrgt()) )
        {
            // The chip is now non-functional.
            nfchips.push_back( l_chip );
            continue;
        }

        // Check if this chip has a clock error
        ExtensibleChipFunction * l_query =
            l_chip->getExtensibleFunction("CheckErrorType");
        rc |= (*l_query)(l_chip,
            PluginDef::bindParm<uint32_t &> (l_errType));

        // Continue if no clock errors reported on this chip
        if ( 0 == l_errType )
            continue;

        if (GetId() == CLOCK_DOMAIN_IO)
        {
            if (l_errType & PCI_PLL_UNLOCK  ) pllUnlockList.push_back(l_chip);
            if (l_errType & PCI_OSC_FAILOVER)  failoverList.push_back(l_chip);
        }
        else
        {
            if (l_errType & SYS_PLL_UNLOCK  ) pllUnlockList.push_back(l_chip);
            if (l_errType & SYS_OSC_FAILOVER)  failoverList.push_back(l_chip);
        }

        // Get this chip's capture data for any error
        l_chip->CaptureErrorData(
                    serviceData.service_data->GetCaptureData());
        // Capture PllFIRs group
        l_chip->CaptureErrorData(
                    serviceData.service_data->GetCaptureData(),
                    Util::hashString("PllFIRs"));

        // Call this chip's capturePllFfdc plugin if it exists.
        ExtensibleChipFunction * l_captureFfdc =
            l_chip->getExtensibleFunction("capturePllFfdc", true);
        if ( nullptr != l_captureFfdc )
        {
            (*l_captureFfdc)( l_chip,
            PluginDef::bindParm<STEP_CODE_DATA_STRUCT &>(serviceData) );
        }

        // In the case of a PLL_UNLOCK error, we want to do additional isolation
        // in case of a HWP failure.
        if ( (l_errType & SYS_PLL_UNLOCK) || (l_errType & PCI_PLL_UNLOCK) )
        {
            PlatServices::hwpErrorIsolation( l_chip, serviceData );
        }
    } // end for each chip in domain

    // Remove all non-functional chips.
    if ( CHECK_STOP != serviceData.service_data->getPrimaryAttnType() )
    {
        for (  auto i : nfchips )
        {
            systemPtr->RemoveStoppedChips( i->getTrgt() );
        }
    }

    // TODO: RTC 184513 - It is possible to have a PLL unlock, a UE RE, and an
    //       SUE CS. Isolation should be to the PLL error and then the
    //       additional FFDC should show there was an SUE CS were the root is
    //       the UE RE. However, PRD does not know how to handle three
    //       attentions at the same time. For now this will remain a limitation
    //       due to time contraits, but there is a proposal in RTC 184513 that
    //       will be solved later. In the meantime, there is a hole in our
    //       analysis that needs to be fixed. If the is a SUE CS and no UE RE,
    //       PRD assumes the UE RE was already predictively called out in a
    //       previous error log. Therefore, nothing will be garded in this error
    //       log. In the example stated above, the current PRD code will not see
    //       the UE RE because of the higher priority PLL unlock. So even though
    //       there is a UE RE present, nothing gets garded. To circumvent this,
    //       we will set the UERE flag here even though the PLL error is not the
    //       true SUE source.
    if ( CHECK_STOP == serviceData.service_data->getPrimaryAttnType() )
    {
        serviceData.service_data->SetUERE();
    }

    // always suspect the clock source
    if (GetId() == CLOCK_DOMAIN_IO)
    {
        mfClockResolution(serviceData, failoverList);
        mfClockResolution(serviceData, pllUnlockList);
    }
    else
    {
        closeClockSource.Resolve(serviceData);
        if(&closeClockSource != &farClockSource)
        {
            farClockSource.Resolve(serviceData);
        }
    }

    if (pllUnlockList.size() > 0)
    {
        // Test for threshold
        iv_threshold.Resolve(serviceData);
        if(serviceData.service_data->IsAtThreshold())
        {
            mskErrType |= (GetId() == CLOCK_DOMAIN_IO) ?
                         PCI_PLL_UNLOCK : SYS_PLL_UNLOCK;
        }

        // Set Signature
        serviceData.service_data->GetErrorSignature()->
            setChipId(pllUnlockList[0]->getHuid());
        serviceData.service_data->SetErrorSig( PRDFSIG_PLL_ERROR );

        // If only one detected sys ref error, add it to the callout list.
        if (pllUnlockList.size() == 1)
        {
            const uint32_t tmpCount =
                serviceData.service_data->getMruListSize();

            // Call this chip's CalloutPll plugin if it exists.
            ExtensibleChipFunction * l_callout =
                pllUnlockList[0]->getExtensibleFunction( "CalloutPll", true );
            if ( nullptr != l_callout )
            {
                (*l_callout)( pllUnlockList[0],
                    PluginDef::bindParm<STEP_CODE_DATA_STRUCT &>(serviceData) );
            }

            // If CalloutPll plugin does not add anything new to the callout
            // list, callout this chip
            if ( tmpCount == serviceData.service_data->getMruListSize() )
            {
                // No additional callouts were made so add this chip to the list
                serviceData.service_data->SetCallout(
                    pllUnlockList[0]->getTrgt());
            }
        }
    }

    if (failoverList.size() > 0)
    {
        serviceData.service_data->GetErrorSignature()->
            setChipId(failoverList[0]->getHuid());

        if (GetId() == CLOCK_DOMAIN_IO)
        {
            // Mask failovers for this domain
            mskErrType |= PCI_OSC_FAILOVER;

            // Set signature
            serviceData.service_data->SetErrorSig( PRDFSIG_MF_REF_FAILOVER );
        }
        else
        {
            // Mask failovers for this domain
            mskErrType |= SYS_OSC_FAILOVER;

            // Set signature
            serviceData.service_data->SetErrorSig( PRDFSIG_SYS_REF_FAILOVER );
        }

        // Make the error log predictive on first occurrence.
        serviceData.service_data->SetThresholdMaskId(0);
    }

    if (serviceData.service_data->IsAtThreshold())
    {
        // Mask appropriate errors on all chips in domain
        ExtensibleDomainFunction * l_mask =
                            getExtensibleFunction("MaskPll");
        (*l_mask)(this,
              PluginDef::bindParm<STEP_CODE_DATA_STRUCT&, uint32_t>
                  (serviceData, mskErrType));
    }

    // Clear PLLs from this domain.
    ExtensibleDomainFunction * l_clear = getExtensibleFunction("ClearPll");
    (*l_clear)(this,
               PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(serviceData));

    // Run PLL Post Analysis on any analyzed chips in this domain.
    for(auto l_chip : pllUnlockList)
    {
        // Send any special messages indicating there was a PLL error.
        ExtensibleChipFunction * l_pllPostAnalysis =
                l_chip->getExtensibleFunction("PllPostAnalysis", true);
        (*l_pllPostAnalysis)(l_chip,
                PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(serviceData));
    }

    for(auto l_chip : failoverList)
    {
        // Send any special messages indicating there was a PLL error.
        ExtensibleChipFunction * l_pllPostAnalysis =
                l_chip->getExtensibleFunction("PllPostAnalysis", true);
        (*l_pllPostAnalysis)(l_chip,
                PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(serviceData));
    }

    return SUCCESS;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void PllDomain::Order(ATTENTION_TYPE attentionType)
{
    // Order is not important for PLL errors
}

//------------------------------------------------------------------------------

int32_t PllDomain::ClearPll( ExtensibleDomain * i_domain,
                             STEP_CODE_DATA_STRUCT & i_sc )
{
    PllDomain * l_domain = (PllDomain *) i_domain;

    const char * clearPllFuncName = (l_domain->GetId() == CLOCK_DOMAIN_IO) ?
        "ClearMfPll" : "ClearPll";

    // Clear children chips.
    for ( uint32_t i = 0; i < l_domain->GetSize(); i++ )
    {
        ExtensibleChip * l_chip = l_domain->LookUp(i);
        ExtensibleChipFunction * l_clear =
                        l_chip->getExtensibleFunction(clearPllFuncName);
        (*l_clear)( l_chip,
                    PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(i_sc) );
    }

    // Clear children domains.
    // This looks like a recursive call.  It calls other domains of Clear.
    ParentDomain<ExtensibleDomain>::iterator i;
    for (i = l_domain->getBeginIterator(); i != l_domain->getEndIterator(); i++)
    {
        // Clear PLLs from this domain.
        ExtensibleDomainFunction * l_clear =
                                (i->second)->getExtensibleFunction("ClearPll");
        (*l_clear)( i->second,
                    PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(i_sc) );
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( PllDomain, ClearPll );

//------------------------------------------------------------------------------

int32_t PllDomain::MaskPll( ExtensibleDomain * i_domain,
                            STEP_CODE_DATA_STRUCT & i_sc,
                            uint32_t i_errType )
{
    PllDomain * l_domain = (PllDomain *) i_domain;

    // Mask children chips.
    for ( uint32_t i = 0; i < l_domain->GetSize(); i++ )
    {
        ExtensibleChip * l_chip = l_domain->LookUp(i);
        ExtensibleChipFunction * l_mask =
                            l_chip->getExtensibleFunction("MaskPll");
        (*l_mask)( l_chip,
            PluginDef::bindParm<STEP_CODE_DATA_STRUCT&, uint32_t>
                (i_sc, i_errType) );
    }

    // Mask children domains.
    // This looks like a recursive call.  It calls other domains of Mask.
    ParentDomain<ExtensibleDomain>::iterator i;
    for (i = l_domain->getBeginIterator(); i != l_domain->getEndIterator(); i++)
    {
        ExtensibleDomainFunction * l_mask =
                                (i->second)->getExtensibleFunction("MaskPll");
        (*l_mask)( i->second,
            PluginDef::bindParm<STEP_CODE_DATA_STRUCT&, uint32_t>
                (i_sc, i_errType) );
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( PllDomain, MaskPll );

//------------------------------------------------------------------------------

} // end namespace PRDF

