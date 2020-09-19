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

                if ( ( l_errType & SYS_PLL_UNLOCK ) ||
                     ( l_errType & SYS_OSC_FAILOVER ) )
                    atAttn = true;

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

int32_t PllDomain::Analyze(STEP_CODE_DATA_STRUCT& io_sc,
                           ATTENTION_TYPE attentionType)
{
    #define PRDF_FUNC "[PllDomain::Analyze] "
    std::vector<ExtensibleChip *> pllUnlockList;
    std::vector<ExtensibleChip *> failoverList;
    int32_t rc = SUCCESS;
    uint32_t mskErrType =  0;

    ExtensibleChipFunction * func = nullptr;

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
        func = l_chip->getExtensibleFunction("CheckErrorType");
        rc |= (*func)(l_chip, PluginDef::bindParm<uint32_t &>(l_errType));

        // Continue if no clock errors reported on this chip
        if ( 0 == l_errType )
            continue;

        if (l_errType & SYS_PLL_UNLOCK  ) pllUnlockList.push_back(l_chip);
        if (l_errType & SYS_OSC_FAILOVER)  failoverList.push_back(l_chip);

        // Capture any registers needed for PLL analysis, which would be
        // captured by default during normal analysis.
        l_chip->CaptureErrorData(io_sc.service_data->GetCaptureData(),
                                 Util::hashString("default_pll_ffdc"));

        // Capture the rest of this chip's PLL FFDC.
        func = l_chip->getExtensibleFunction("capturePllFfdc");
        (*func)(l_chip, PluginDef::bindParm<STEP_CODE_DATA_STRUCT &>(io_sc));

        // In the case of a PLL_UNLOCK error, we want to do additional isolation
        // in case of a HWP failure.
        if ( l_errType & SYS_PLL_UNLOCK )
        {
            PlatServices::hwpErrorIsolation( l_chip, io_sc );
        }
    } // end for each chip in domain

    // Remove all non-functional chips.
    if ( CHECK_STOP != io_sc.service_data->getPrimaryAttnType() )
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
    if ( CHECK_STOP == io_sc.service_data->getPrimaryAttnType() )
    {
        io_sc.service_data->SetUERE();
    }

    closeClockSource.Resolve(io_sc);
    if(&closeClockSource != &farClockSource)
    {
        farClockSource.Resolve(io_sc);
    }

    if (pllUnlockList.size() > 0)
    {
        // Test for threshold
        iv_threshold.Resolve(io_sc);
        if(io_sc.service_data->IsAtThreshold())
        {
            mskErrType |= SYS_PLL_UNLOCK;
        }

        // Set Signature
        io_sc.service_data->GetErrorSignature()->
            setChipId(pllUnlockList[0]->getHuid());
        io_sc.service_data->SetErrorSig( PRDFSIG_PLL_ERROR );

        // If only one detected sys ref error, add it to the callout list.
        if (pllUnlockList.size() == 1)
        {
            const uint32_t tmpCount =
                io_sc.service_data->getMruListSize();

            // Call this chip's CalloutPll plugin if it exists.
            func = pllUnlockList[0]->getExtensibleFunction("CalloutPll", true);
            if ( nullptr != func )
            {
                (*func)(pllUnlockList[0],
                        PluginDef::bindParm<STEP_CODE_DATA_STRUCT &>(io_sc));
            }

            // If CalloutPll plugin does not add anything new to the callout
            // list, callout this chip
            if ( tmpCount == io_sc.service_data->getMruListSize() )
            {
                // No additional callouts were made so add this chip to the list
                io_sc.service_data->SetCallout(
                    pllUnlockList[0]->getTrgt());
            }
        }
    }

    if (failoverList.size() > 0)
    {
        io_sc.service_data->GetErrorSignature()->
            setChipId(failoverList[0]->getHuid());

        // Mask failovers for this domain
        mskErrType |= SYS_OSC_FAILOVER;

        // Set signature
        io_sc.service_data->SetErrorSig( PRDFSIG_SYS_REF_FAILOVER );

        // Make the error log predictive on first occurrence.
        io_sc.service_data->SetThresholdMaskId(0);
    }

    if (io_sc.service_data->IsAtThreshold())
    {
        // Mask appropriate errors on all chips in domain
        ExtensibleDomainFunction * mask = getExtensibleFunction("MaskPll");
        (*mask)(this, PluginDef::bindParm<STEP_CODE_DATA_STRUCT&, uint32_t>
                          (io_sc, mskErrType));
    }

    // Clear PLLs from this domain.
    ExtensibleDomainFunction * clear = getExtensibleFunction("ClearPll");
    (*clear)(this, PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(io_sc));

    // Run PLL Post Analysis on any analyzed chips in this domain.
    for(auto l_chip : pllUnlockList)
    {
        // Send any special messages indicating there was a PLL error.
        func = l_chip->getExtensibleFunction("PllPostAnalysis", true);
        (*func)(l_chip, PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(io_sc));
    }

    for(auto l_chip : failoverList)
    {
        // Send any special messages indicating there was a PLL error.
        func = l_chip->getExtensibleFunction("PllPostAnalysis", true);
        (*func)(l_chip, PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(io_sc));
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

    // Clear children chips.
    for ( uint32_t i = 0; i < l_domain->GetSize(); i++ )
    {
        ExtensibleChip * l_chip = l_domain->LookUp(i);
        ExtensibleChipFunction * l_clear =
                        l_chip->getExtensibleFunction("ClearPll");
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

