/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/iipSystem.C $       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1996,2013              */
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

// Module Description **************************************************
//
// Description: This module provides the implementation for the PRD
//              System class.
//
// End Module Description **********************************************

/*--------------------------------------------------------------------*/
/* Emit the virtual function tables and inline function defintions in
 this translation unit.                                             */
/*--------------------------------------------------------------------*/
#ifdef __GNUC__
#endif

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

#include <prdfMain.H>
#include <iipSystem.h>
#include <iipResolution.h>
#include <iipsdbug.h>
#include <iipchip.h>
#include <iipDomain.h>
#include <iipServiceDataCollector.h>
#include <iipResolutionFactory.h>
#include <iipglobl.h>
#include <prdfPlatServices.H>

#ifndef __HOSTBOOT_MODULE
  #include <prdfMfgThresholdMgr.H>
#endif

namespace PRDF
{

//----------------------------------------------------------------------
//  User Types
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Macros
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Internal Function Prototypes
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Global Variables
//----------------------------------------------------------------------

//---------------------------------------------------------------------
// Member Function Specifications
//---------------------------------------------------------------------

System::System( Resolution & noSystemAttentions ) :
    chips(),
    prioritizedDomains(),
    noAttnResolution(noSystemAttentions)
{}

System::~System(void)
{
    for(ChipMapType::iterator chipIterator = chips.begin();
        chipIterator != chips.end();chipIterator++)
    {
        delete (*chipIterator);
    }

    // change to delete prioritiezed Domains instead of domains dg04
    for(DomainContainerType::iterator domainIterator = prioritizedDomains.begin();
        domainIterator != prioritizedDomains.end();domainIterator++)
    {
        delete (*domainIterator);
    }
    // clear the Resolution factory
    ResolutionFactory::Access().Reset();

#ifndef __HOSTBOOT_MODULE
    // FIXME: need to implement MfgThresholdMgr in Hostboot
    // clear the MfgThresholdMgr
    MfgThresholdMgr::getInstance()->reset();
#endif

    // clear the threshold policies
    ThresholdResolution::reset();
}

CHIP_CLASS * System::GetChip(TARGETING::TargetHandle_t i_pchipHandle )
{
    CHIP_CLASS * chipPtr = NULL;

    //  chips.LookUp(chipPtr, chipId);
    for(uint32_t i = 0; i < chips.size(); ++i)
    {
        if(chips[i]->GetChipHandle() == i_pchipHandle)
        {
            chipPtr = chips[i];
            break;
        }
    }

    return(chipPtr);
}

Domain * System::GetDomain(DOMAIN_ID domainId)
{
    Domain * domainPtr = NULL;

    //  domains.LookUp(domainPtr, domainId);
    for(uint32_t i = 0; i < prioritizedDomains.size(); ++i)
    {
        if(prioritizedDomains[i]->GetId() == domainId)
        {
            domainPtr = prioritizedDomains[i];
            break;
        }
    }

    return(domainPtr);
}

void System::AddChips(ChipContainerIterator begin,
                      ChipContainerIterator end)
{
    size_t l_size = 0;
    if(begin < end) l_size = end-begin;
    else l_size = begin-end;
    chips.reserve(chips.size()+l_size);
    while(begin != end)
    {
        chips.push_back(*begin);
        begin++;
    }
}

void System::AddDomains(DomainContainerIterator begin,
                        DomainContainerIterator end)
{
    size_t l_size = 0;
    if(begin < end) l_size = end-begin;
    else l_size = begin-end;
    prioritizedDomains.reserve(prioritizedDomains.size()+l_size);
    // The Configurator owns determining the priority of the domains.
    while(begin != end)
    {
        prioritizedDomains.push_back(*begin);        // dg01 - add: Keep order given
        begin++;
    }
}

void System::RemoveStoppedChips(TARGETING::TargetHandle_t i_pchipHandle)
{
    for(DomainContainerType::iterator domainIterator = prioritizedDomains.begin();
        domainIterator != prioritizedDomains.end(); domainIterator++)
    {
        (*domainIterator)->Remove(i_pchipHandle);
    }
}

// --------------------------------------------------------------------

void System::RemoveNonFunctionalChips()
{
    ChipMapType l_chips;

    for(ChipMapType::iterator chipIterator = chips.begin();
        chipIterator != chips.end();
        chipIterator++)
    {
        if(!PlatServices::isFunctional((*chipIterator)->GetChipHandle()))
        {
            l_chips.push_back(*chipIterator);
        }
    }

    // The reason for l_chips is because we can't remove elements from a vector
    // as we are iterating on it. Otherwise, it will foul up the iterators.
    // Now, this is not the most efficient way to remove the chips, because this
    // implementation will remove (put at the end of the vector) the chip then
    // erase it and repeat for each element. Instead, it should remove all chips
    // then erase all removed chips. However, for the scope of this code, the
    // efficiency increase is nominal so it can be left for future improvements.
    for(ChipMapType::iterator chipIterator = l_chips.begin();
        chipIterator != l_chips.end();
        chipIterator++)
    {
        RemoveStoppedChips((*chipIterator)->GetChipHandle());
    }
}

// --------------------------------------------------------------------

void System::Initialize(void)
{
    uint32_t rc = SUCCESS;
    //SYSTEM_DEBUG_CLASS sysdebug; dg08d

    for(ChipMapType::iterator chipIterator = chips.begin();
        (chipIterator != chips.end()) && (rc == SUCCESS);chipIterator++)
    {
        rc = (*chipIterator)->Initialize();
        // if rc then an error log was (will be) committed
        if(rc != SUCCESS)
        {
            PRDF_ERR( "System::Initialize of chips failed. rc = %x", rc );
        }
    }

    // change domains to priortizedDomains  dg04
    for(DomainContainerType::iterator domainIterator = prioritizedDomains.begin();
        (domainIterator != prioritizedDomains.end()) && (rc == SUCCESS);
        domainIterator++)
    {
        rc = (*domainIterator)->Initialize();

        if(rc != SUCCESS)
        {
            PRDF_ERR( "System::Initialize of chips failed. rc = %x", rc );
        }
    }
}

// -------------------------------------------------------------------

int System::Analyze(STEP_CODE_DATA_STRUCT & serviceData,
                    ATTENTION_TYPE attentionType)
{
    SYSTEM_DEBUG_CLASS sysdebug;
    Domain * domainAtAttentionPtr = NULL;
    ServiceDataCollector * l_saved_sdc = NULL;

    int rc = (prioritizedDomains.empty() ? NO_DOMAINS_IN_SYSTEM : SUCCESS);
    int l_saved_rc = 0;

    if(rc == SUCCESS)
    {
        // IF machine check then check for recoverable errors first
        // otherwise just check for the given type of attention
        ATTENTION_TYPE startAttention = attentionType;
        if((attentionType == MACHINE_CHECK) || (attentionType == UNIT_CS))
            startAttention = RECOVERABLE;
        ATTENTION_TYPE atnType = startAttention;
        for(atnType = startAttention;
            domainAtAttentionPtr == NULL && atnType >= attentionType ;
            --atnType)
        {
            for(DomainContainerType::iterator domainIterator = prioritizedDomains.begin();
                domainIterator != prioritizedDomains.end() && domainAtAttentionPtr == NULL;
                domainIterator++)
            {
                domainAtAttentionPtr = ((*domainIterator)->Query(atnType)) ? (*domainIterator) : NULL;
                if(domainAtAttentionPtr != NULL)
                {
                    serviceData.service_data->SetCauseAttentionType(atnType);
                    rc = domainAtAttentionPtr->Analyze(serviceData, atnType);
                    if((rc == PRD_SCAN_COMM_REGISTER_ZERO) ||
                        (rc == PRD_POWER_FAULT))
                    {
                        // save sdc, and continue
                        if(l_saved_sdc == NULL)
                        {
                            l_saved_sdc = new ServiceDataCollector(
                                                *serviceData.service_data);
                            l_saved_rc = rc;
                        }
                        // TODO clear serviceData ?
                        domainAtAttentionPtr = NULL;

                        if(rc == PRD_POWER_FAULT)
                        {
                            PRDF_ERR( "System::Analyze() Power Fault detected!" );
                            break;
                        }
                    }
                }
            }
        }

        // if ptr is NULL && we don't have a saved SDC than we have noAttns
        // if ptr is NULL && we have a saved SDC then we have an attn with no-bits-on
        // otherwise we are done - aready did the analysis
        if(domainAtAttentionPtr == NULL)
        {
            if(l_saved_sdc == NULL)
            {
                rc = noAttnResolution.Resolve(serviceData);
            }
            else
            {
                *serviceData.service_data = *l_saved_sdc;
                sysdebug.CalloutThoseAtAttention(serviceData);
                rc = l_saved_rc;
            }
        }
        //else
        //{
        //  // mk442956 a Add atnType to CauseAttentionType in sdc
        //  serviceData.service_data->SetCauseAttentionType(atnType+1);
        //  rc = domainAtAttentionPtr->Analyze(serviceData, atnType+1); // jp01
        //}
        if(l_saved_sdc != NULL) delete l_saved_sdc; //dg05a

    }

    return(rc);
}

} // end namespace PRDF

