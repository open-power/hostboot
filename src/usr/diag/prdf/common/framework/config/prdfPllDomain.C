/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfPllDomain.C $   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
#include <iipglobl.h>
#include <iipSystem.h>

namespace PRDF
{

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
                                    l_chip->getExtensibleFunction("QueryPll");
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
    CcAutoDeletePointerVector<ChipPtr> chip(new ChipPtr[GetSize()]);
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
        ExtensibleChipFunction * l_query = l_chip->getExtensibleFunction("QueryPll");
        bool atAttn;
        rc = (*l_query)(l_chip,PluginDef::bindParm<bool &>(atAttn));
        if(atAttn == true)
        {
            chip()[count] = LookUp(index);
            ++count;
            l_chip->CaptureErrorData(serviceData.service_data->GetCaptureData());
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
    closeClockSource.Resolve(serviceData);  // dg06c
    if(&closeClockSource != &farClockSource)
    {
        farClockSource.Resolve(serviceData); // dg06c
    }

    // If only one detected the error, add it to the callout list.
    if ( 1 == count )
    {
        const uint32_t tmpCount = serviceData.service_data->GetMruList().size();

        // Call this chip's CalloutPll plugin if it exists.
        ExtensibleChipFunction * l_callout =
                chip()[0]->getExtensibleFunction( "CalloutPll", true );
        if ( NULL != l_callout )
        {
            (*l_callout)( chip()[0],
                PluginDef::bindParm<STEP_CODE_DATA_STRUCT &>(serviceData) );
        }

        if ( tmpCount == serviceData.service_data->GetMruList().size() )
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
    serviceData.service_data->GetErrorSignature()->setRegId(PRDF_PLL_ERROR);

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
                        l_chip->getExtensibleFunction("PllPostAnalysis", true);
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
                             STEP_CODE_DATA_STRUCT i_sc )
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
                            STEP_CODE_DATA_STRUCT i_sc )
{
    PllDomain * l_domain = (PllDomain *) i_domain;

    // Mask children chips.
    for ( uint32_t i = 0; i < l_domain->GetSize(); i++ )
    {
        ExtensibleChip * l_chip = l_domain->LookUp(i);
        ExtensibleChipFunction * l_mask =
                                    l_chip->getExtensibleFunction("MaskPll");
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

