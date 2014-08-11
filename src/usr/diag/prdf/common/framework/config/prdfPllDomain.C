/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfPllDomain.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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

#include <CcAutoDeletePointer.h>
#include <iipscr.h>
#include <iipsdbug.h>
#include <iipServiceDataCollector.h>
#include <prdfErrorSignature.H>
#include <prdfPllDomain.H>
#include <iipResolution.h>
#include <prdfPlatServices.H>
#include <prdfPluginDef.H>
#include <prdfGlobal.H>
#include <iipSystem.h>
#include <UtilHash.H>
#include <prdfP8ProcMbCommonExtraSig.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

void PllDomain::InitChipPluginFuncs()
{
    if ( CLOCK_DOMAIN_IO == GetId() )
    {
        QueryPllFunc = "QueryPllIo";
        CapturePllFunc = "capturePllFfdcIo";
        CalloutPllFunc = "CalloutPllIo";
        MaskPllFunc = "MaskPllIo";
        ClearPllFunc = "ClearPllIo";
        PostAnalysisPllFunc = "PllPostAnalysisIo";
    }
    else
    {
        QueryPllFunc = "QueryPll";
        CapturePllFunc = "capturePllFfdc";
        CalloutPllFunc = "CalloutPll";
        MaskPllFunc = "MaskPll";
        ClearPllFunc = "ClearPll";
        PostAnalysisPllFunc = "PllPostAnalysis";
    }
}

//------------------------------------------------------------------------------

int32_t PllDomain::Initialize(void)
{

  int32_t rc = SUCCESS;
  if(PlatServices::isMasterFSP())
  {
//@jl01 D-START
//Deleting the call of the ClearPll error.
//These errors used to have to be cleared before you tried to use the chips.
//However, the inits from other comps are better are cleaning up the PLL errors.
//    for (unsigned int i = 0; i < GetSize() && rc == SUCCESS; ++i)
//    {
//      ExtensibleChip * l_chip = LookUp(i);
//      ExtensibleFunction * l_clearPll = l_chip->getExtensibleFunction("ClearPll");
      // Call ClearPll on this chip  (see prdfPluginDef.H for bindParm defn)
//      (*l_clearPll)(l_chip,PluginDef::bindParm<void *>(NULL));
//@jl01 D-END

// Don't unmask   04/20/2006 Review
//      ExtensibleFunction * l_unmask = l_chip->getExtensibleFunction("UnmaskPll");
//      (*l_unmask)(l_chip,PluginDef::bindParm<void *>(NULL));
//    }
  }
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
            if(sysdbug.IsAttentionActive(LookUp(index)->GetChipHandle()))
            {
                ExtensibleChip * l_chip = LookUp(index);
                ExtensibleChipFunction * l_query =
                                    l_chip->getExtensibleFunction(QueryPllFunc);
                int32_t rc = (*l_query)(l_chip,PluginDef::bindParm<bool &>(atAttn));
                // if rc then scom read failed - Error log has already been generated
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

int32_t PllDomain::Analyze(STEP_CODE_DATA_STRUCT & serviceData,
                          ATTENTION_TYPE attentionType)
{
    typedef ExtensibleChip * ChipPtr;
    CcAutoDeletePointerVector<ChipPtr> chip(new ChipPtr[GetSize()]());
    int count = 0;
    int32_t rc = SUCCESS;

    // Due to clock issues some chips may be moved to non-functional during
    // analysis. In this case, these chips will need to be removed from their
    // domains.
    typedef std::vector<ExtensibleChip *> NonFuncChips;
    NonFuncChips nfchips;

    // Count # of chips that had PLL error
    for(unsigned int index = 0; index < GetSize(); ++index)
    {
        ExtensibleChip * l_chip = LookUp(index);
        bool atAttn = false;

        ExtensibleChipFunction * l_query =
            l_chip->getExtensibleFunction(QueryPllFunc);
        rc |= (*l_query)(l_chip,PluginDef::bindParm<bool &>(atAttn));

        if ( atAttn )
        {
            chip()[count] = LookUp(index);
            ++count;
            l_chip->CaptureErrorData(
                    serviceData.service_data->GetCaptureData());
            // Capture PllFIRs group
            l_chip->CaptureErrorData(
                    serviceData.service_data->GetCaptureData(),
                    Util::hashString("PllFIRs"));

            // Call this chip's capturePllFfdc plugin if it exists.
            ExtensibleChipFunction * l_captureFfdc =
                l_chip->getExtensibleFunction(CapturePllFunc, true);
            if ( NULL != l_captureFfdc )
            {
                (*l_captureFfdc)( l_chip,
                PluginDef::bindParm<STEP_CODE_DATA_STRUCT &>(serviceData) );
            }
        }
        else if ( !PlatServices::isFunctional(l_chip->GetChipHandle()) )
        {
            // The chip is now non-functional.
            nfchips.push_back( l_chip );
        }
    }

    // Remove all non-functional chips.
    for ( NonFuncChips::iterator i = nfchips.begin(); i != nfchips.end(); i++ )
    {
        systemPtr->RemoveStoppedChips( (*i)->GetChipHandle() );
    }

    // always suspect the clock source
    closeClockSource.Resolve(serviceData);
    if(&closeClockSource != &farClockSource)
    {
        farClockSource.Resolve(serviceData);
    }

    // If only one detected the error, add it to the callout list.
    if ( 1 == count )
    {
        const uint32_t tmpCount = serviceData.service_data->getMruListSize();

        // Call this chip's CalloutPll plugin if it exists.
        ExtensibleChipFunction * l_callout =
                chip()[0]->getExtensibleFunction( CalloutPllFunc, true );
        if ( NULL != l_callout )
        {
            (*l_callout)( chip()[0],
                PluginDef::bindParm<STEP_CODE_DATA_STRUCT &>(serviceData) );
        }

        if ( tmpCount == serviceData.service_data->getMruListSize() )
        {
            // No additional callouts were made so add this chip to the list.
            serviceData.service_data->SetCallout( chip()[0]->GetChipHandle());
        }
    }

    iv_threshold.Resolve(serviceData);
    // Test for threshold
    if(serviceData.service_data->IsAtThreshold())
    {
        // Mask in all chips in domain
        ExtensibleDomainFunction * l_mask = getExtensibleFunction("MaskPll");
        (*l_mask)(this,
                  PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(serviceData));
    }
    // Set Signature
    serviceData.service_data->GetErrorSignature()->setChipId(chip()[0]->GetId());
    serviceData.service_data->SetErrorSig( PRDFSIG_PLL_ERROR );

#ifndef __HOSTBOOT_MODULE
    // Set dump flag dg09a
    serviceData.service_data->SetDump(iv_dumpContent,chip()[0]->GetChipHandle());
#endif

    // Clear PLLs from this domain.
    ExtensibleDomainFunction * l_clear = getExtensibleFunction("ClearPll");
    (*l_clear)(this,
               PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(serviceData));

    // Run any PLL Post Analysis functions from this domain.
    for(int i = 0; i < count; i++)
    {
        ExtensibleChip * l_chip = chip()[i];
        // Send any special messages indicating there was a PLL error.
        ExtensibleChipFunction * l_pllPostAnalysis =
                l_chip->getExtensibleFunction(PostAnalysisPllFunc, true);
        (*l_pllPostAnalysis)(l_chip,
                PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(serviceData));
    }

    return rc;
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

    const char * clearPllFuncName = "ClearPll";
    if ( CLOCK_DOMAIN_IO == l_domain->GetId() )
    {
        clearPllFuncName = "ClearPllIo";
    }

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
                            STEP_CODE_DATA_STRUCT & i_sc )
{
    PllDomain * l_domain = (PllDomain *) i_domain;

    const char * maskPllFuncName = "MaskPll";
    if ( CLOCK_DOMAIN_IO == l_domain->GetId() )
    {
        maskPllFuncName = "MaskPllIo";
    }

    // Mask children chips.
    for ( uint32_t i = 0; i < l_domain->GetSize(); i++ )
    {
        ExtensibleChip * l_chip = l_domain->LookUp(i);
        ExtensibleChipFunction * l_mask =
                            l_chip->getExtensibleFunction(maskPllFuncName);
        (*l_mask)( l_chip,
                   PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(i_sc) );
    }

    // Mask children domains.
    // This looks like a recursive call.  It calls other domains of Mask.
    ParentDomain<ExtensibleDomain>::iterator i;
    for (i = l_domain->getBeginIterator(); i != l_domain->getEndIterator(); i++)
    {
        ExtensibleDomainFunction * l_mask =
                                (i->second)->getExtensibleFunction("MaskPll");
        (*l_mask)( i->second,
                   PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(i_sc) );
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( PllDomain, MaskPll );

//------------------------------------------------------------------------------

} // end namespace PRDF

