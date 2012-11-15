/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfFabricDomain.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2012              */
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
// Description:
//
// End Module Description **********************************************

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define prdfFabricDomain_C

#include <iipglobl.h>
#include <iipstep.h>
#include <iipsdbug.h>
#include <iipErrorRegister.h>
#include <iipServiceDataCollector.h>
#include <prdfFabricDomain.H>
#include <UtilHash.H>
#include <prdfPluginDef.H>

#include <prdfPlatServices.H>

#include <algorithm>

#undef prdfFabricDomain_C
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
int32_t FabricDomain::Analyze(STEP_CODE_DATA_STRUCT & serviceData,
                              ATTENTION_TYPE attentionType)
{
    using namespace PRDF;

    int32_t l_rc;
    l_rc = DomainContainer<PrdfRuleChip>::Analyze(serviceData, attentionType);


    if( l_rc == PRD_POWER_FAULT )
    {
        PRDF_ERR( "PrdfFabricDomain::Analyze::Power Fault detected!" );
    }
    else
    {
      // Capture Global FIRs on xstp and recovered errors for domain.
      if ((attentionType == MACHINE_CHECK) || (attentionType == RECOVERABLE))
      {
        for (uint32_t i = 1; i < GetSize(); ++i) // start at 1 to skip analyzed.
        {
          LookUp(i)->CaptureErrorData(
                                      serviceData.service_data->GetCaptureData(),
                                      Util::hashString("GlobalFIRs"));

          if (attentionType == MACHINE_CHECK)
          {
            LookUp(i)->CaptureErrorData(
                                        serviceData.service_data->GetCaptureData(),
                                        Util::hashString("AllFIRs"));
          }
        }
      }
    }

    return l_rc;
}

void FabricDomain::Order(ATTENTION_TYPE attentionType)
{
    using namespace PRDF;
    using PrdfPluginDef::bindParm;

    if (attentionType == MACHINE_CHECK)
    {
        SortForXstop();

    }
    else if (attentionType == RECOVERABLE)
    {
        SortForRecov();
    }
    else // Recovered or Special
    {
        SYSTEM_DEBUG_CLASS sysdbug;
        for (int32_t i = (GetSize() - 1); i >= 0; --i) //pw03
        {
            PrdfRuleChip * l_fabChip = LookUp(i);
            TARGETING::TargetHandle_t l_pchipHandle = l_fabChip->GetChipHandle();
            if ((sysdbug.IsAttentionActive(l_pchipHandle)) &&
                    (sysdbug.GetAttentionType(l_pchipHandle ) == attentionType))
            {
                MoveToFront(i);  //pw03
                break;
            }
        }
    }
}

// Determine the proper sorting for a checkstop based on:
//         1. Find only a single chip with an internal checkstop
//         2. Graph reduction algorithm
//         3. WOF/TOD counters
void FabricDomain::SortForXstop()
{
    using namespace PrdfPluginDef;
    using namespace TARGETING;

    uint32_t l_internalOnlyCount = 0;
    int l_chip = 0;

    uint64_t l_externalDrivers[GetSize()];
    uint64_t l_wofValues[GetSize()];
    bool l_internalCS[GetSize()];

    union { uint64_t * u; CPU_WORD * c; } ptr; // zs01

    // Get internal setting and external driver list for each chip.
    for(uint32_t i = 0; i < GetSize(); ++i)
    {
        l_externalDrivers[i] = 0;
        l_wofValues[i] = 0;

        PrdfRuleChip * l_fabChip = LookUp(i);

        ptr.u = &l_externalDrivers[i]; // zs01
        prdfBitString l_externalChips(GetSize(), ptr.c); // zs01
        TargetHandleList l_tmpList;

        // Call "GetCheckstopInfo" plugin.
        PrdfExtensibleChipFunction * l_extFunc
            = l_fabChip->getExtensibleFunction("GetCheckstopInfo");

        (*l_extFunc)(l_fabChip,
                     bindParm<bool &, TargetHandleList &, uint64_t &>
                        (l_internalCS[i],
                         l_tmpList,
                         l_wofValues[i]
                     )
        );


        // Update bit buffer.
        for (TargetHandleList::iterator j = l_tmpList.begin();
             j != l_tmpList.end(); ++j)
        {
            for (uint32_t k = 0; k < GetSize(); k++)
                if ((*j) == LookUp(k)->GetChipHandle())
                    l_externalChips.Set(k);
        };

        // Check if is internal.
        if (l_internalCS[i])
        {
            l_internalOnlyCount++;
            l_chip = i;
        }
    }

    // Check if we are done... only one with an internal error.
    if (1 == l_internalOnlyCount)
    {
        MoveToFront(l_chip);  //pw03
        return;
    }
    else if (0 == l_internalOnlyCount)
    {
        // TODO : add trace here... continue with analysis to determine
        // which chip origined though.
    }

    // --- Do graph reduction ---
    // Currently does not do cycle elimination.

    // Get initial list (all chips).
    BIT_STRING_BUFFER_CLASS l_current(GetSize());
    l_current.Pattern(0,GetSize(),0xFFFFFFFF, 32); // turn on all bits.

    // Do reduction.
    // When done, l_prev will have the minimal list.
    BIT_STRING_BUFFER_CLASS l_prev(GetSize());
    l_prev.Clear();

    while ((!(l_current == l_prev)) && (!l_current.IsZero()))
    {
        l_prev = l_current;
        l_current.Clear();

        for (uint32_t i = 0; i < GetSize(); i++)
        {
            if (l_prev.IsSet(i)) // skip if this chip isn't in the pool.
                for (uint32_t j = 0; j < GetSize(); j++)
                {
                    ptr.u = &l_externalDrivers[i]; // zs01
                    if ( prdfBitString(GetSize(), ptr.c).IsSet(j) ) // zs01
                        l_current.Set(j);
                }
        }
    }

    // Hopefully, we got just one chip left...
    if (1 == l_prev.GetSetCount())
    {
        // Now find it.
        for (uint32_t i = 0; i < GetSize(); i++)
            if ((l_prev.IsSet(i)) &&
                (l_internalCS[i] || (0 == l_internalOnlyCount)))
            {
                MoveToFront(i);  //pw03
                return;
            }
    }

    // --- Do WOF compare ---
    uint32_t l_minWof = 0;
    for (uint32_t i = 0; i < GetSize(); i++)
    {
        // Search for minimum WOF value.
        if (l_wofValues[i] < l_wofValues[l_minWof])
                // Only choose chips with internal checkstop,
                // unless no internals.
            if ((l_internalCS[i] || (0 == l_internalOnlyCount)))
                l_minWof = i;
    }
    MoveToFront(l_minWof);  //pw03
    return;

};

namespace __prdfFabricDomain // pw03 ---
{
    // This function is used for the std::max_element function in SortForRecov
    // to ensure that elements towards the end of the list are favored (and
    // therefore preventing starvation of chips at the end of the domain list)
    inline bool lessThanOperator(uint32_t & l, uint32_t & r)
    {
        if (l == r)
        {
            return ((void *)&l) < ((void *)&r);
        }
        return l < r;
    }
}; // --- pw03

void FabricDomain::SortForRecov()
{
    using namespace PRDF;
    using namespace PrdfPluginDef;

    SYSTEM_DEBUG_CLASS sysdbug;
    uint32_t l_sev[GetSize()];
    std::fill(&l_sev[0], &l_sev[GetSize()], 0);

    // Loop through all chips.
    for (uint32_t i = 0; i < GetSize(); ++i)
    {
        PrdfRuleChip * l_fabChip = LookUp(i);
        TARGETING::TargetHandle_t l_pchipHandle = l_fabChip->GetChipHandle();
        if (sysdbug.IsAttentionActive(l_pchipHandle))  // If at attention, check.
        {

            if (RECOVERABLE == sysdbug.GetAttentionType( l_pchipHandle))
            {
                // Recovered, set sev 1.
                l_sev[i] = 1;
            }
            else if (CHECK_STOP == sysdbug.GetAttentionType(l_pchipHandle))
            {
                // Check for recovered error at checkstop.
                PrdfExtensibleChipFunction * l_extFunc
                    = l_fabChip->getExtensibleFunction("CheckForRecovered");

                bool l_hasRer = false;

                (*l_extFunc)(l_fabChip, bindParm<bool &>(l_hasRer));

                if (l_hasRer)
                {
                    // Has a recovered error, sev 1.
                    l_sev[i] = 1;
                }
            }

            // Find real severity level.
            if (0 != l_sev[i])
            {
                PrdfExtensibleChipFunction * l_extFunc
                        = l_fabChip->getExtensibleFunction(
                                                    "CheckForRecoveredSev");

                uint32_t l_cSev = 1;
                (*l_extFunc)(l_fabChip, bindParm<uint32_t &>(l_cSev));

                l_sev[i] = l_cSev;
            }
        }
    }

    // Find item with highest severity.
    MoveToFront(std::distance(&l_sev[0],
                       std::max_element(&l_sev[0],
                                        &l_sev[GetSize()],
                                        __prdfFabricDomain::lessThanOperator))
               ); //pw03
}


//Analyze a subset of chips in a Domain...
//This is a mini analysis of some of the chips in the Fabric Domain.
int32_t FabricDomain::AnalyzeTheseChips(STEP_CODE_DATA_STRUCT & serviceData,
                                        ATTENTION_TYPE attentionType,
                                        TARGETING::TargetHandleList & i_chips)
{
    using namespace TARGETING ;
    PRDF_DENTER( "FabricDomain::AnalyzeTheseChips" );
    int32_t l_rc = ~SUCCESS;

    PRDF_DTRAC( "FabricDomain::AnalyzeTheseChips:: Domain ID = 0x%X", GetId() );

    if(i_chips.size() != 0)
    {

        for (TargetHandleList::iterator i = i_chips.begin(); i != i_chips.end(); ++i)
        {
            PRDF_DTRAC( "FabricDomain::AnalyzeTheseChips::Before--chip=0x%X",
                        PRDF::PlatServices::getHuid(*i));
        }

        OrderTheseChips(attentionType, i_chips);

        for (TargetHandleList::iterator i = i_chips.begin(); i != i_chips.end(); ++i)
        {
            PRDF_DTRAC( "FabricDomain::AnalyzeTheseChips::After--chip=0x%X",
                        PRDF::PlatServices::getHuid(*i) );
        }
        //After the Order function is called the first chip should contain the chip to look at.
        //Look here for the correct LookUp function.  I don't think this is working.
        PrdfRuleChip * l_fabChip = FindChipInTheseChips(i_chips[0], i_chips);
        PRDF_DTRAC( "FabricDomain::AnalyzeTheseChips::Analyzing this one: 0x%X",
                    l_fabChip->GetId() );
        if(NULL != l_fabChip)
        {
            l_rc = l_fabChip->Analyze(serviceData, attentionType);
        }
        else
        {
            PRDF_DTRAC( "FabricDomain::AnalyzeTheseChips::l_fabChip is NULL" );
            l_rc = ~SUCCESS;
        }
    }
    else
    {
        PRDF_DTRAC( "FabricDomain::AnalyzeTheseChips::i_chips = %d",
                    i_chips.size() );
    }

    //Get P7 chip Global FIR data for FFDC
    for (TargetHandleList::iterator i = i_chips.begin(); i != i_chips.end(); ++i)
    {
        PrdfRuleChip * l_fabChip = FindChipInTheseChips(*i, i_chips);
        l_fabChip->CaptureErrorData(
                                    serviceData.service_data->GetCaptureData(),
                                    Util::hashString("GlobalFIRs"));
    }


    PRDF_DEXIT( "FabricDomain::AnalyzeTheseChips" );
    return l_rc;
}


int32_t FabricDomain::OrderTheseChips(ATTENTION_TYPE attentionType,
                                      TARGETING::TargetHandleList & i_chips)
{
    using namespace PrdfPluginDef;
    using namespace TARGETING;
    PRDF_DENTER( "FabricDomain::OrderTheseChips" );

    uint32_t l_internalOnlyCount = 0;
    uint64_t l_externalDrivers[i_chips.size()];
    uint64_t l_wofValues[i_chips.size()];
    bool l_internalCS[i_chips.size()];

    union { uint64_t * u; CPU_WORD * c; } ptr;

    uint32_t l_chip = 0;
    uint32_t l_chipToFront = 0;
    // Get internal setting and external driver list for each chip.
    for (TargetHandleList::iterator i = i_chips.begin(); i != i_chips.end(); ++i)
    {

        PrdfRuleChip * l_fabChip = FindChipInTheseChips(*i, i_chips);

        ptr.u = &l_externalDrivers[l_chip];
        prdfBitString l_externalChips(i_chips.size(), ptr.c);
        TargetHandleList l_tmpList;

        if(l_fabChip != NULL)
        {
            // Call "GetCheckstopInfo" plugin.
            PrdfExtensibleChipFunction * l_extFunc
                = l_fabChip->getExtensibleFunction("GetCheckstopInfo");

            (*l_extFunc)(l_fabChip,
                     bindParm<bool &, TargetHandleList &, uint64_t &>
                        (l_internalCS[l_chip],
                         l_tmpList,
                         l_wofValues[l_chip]
                     )
            );
        }
        else
        {
            l_internalCS[l_chip] = false;
            PRDF_DTRAC( "FabricDomain::OrderTheseChips: l_fabChip is NULL" );
        }

        //If we are just checking for internal errors then there is no need for
        //a list of what chips sent checkstops where.
        // Update bit buffer.
        for (TargetHandleList::iterator j = l_tmpList.begin();
             j != l_tmpList.end();
             ++j)
        {
            for (uint32_t k = 0; k < i_chips.size(); k++)
                if ((*j) == LookUp(k)->GetChipHandle())
                    l_externalChips.Set(k);
        };

        // Check if is internal.
        if (l_internalCS[l_chip])
        {
            l_internalOnlyCount++;
            l_chipToFront = l_chip;
        }
        l_chip++;  //Move to next chip in the list.
    }

    // Check if we are done... only one with an internal error.
    if (1 == l_internalOnlyCount)
    {
        MoveToFrontInTheseChips(l_chipToFront, i_chips);
        return(SUCCESS);
    }

    PRDF_DEXIT( "FabricDomain::OrderTheseChips" );
    return(SUCCESS);
}

//This function is to ensure the order of the chip in the list is the correct chip.
//Because there is no garaunteed order within the domain container this is necessary.
PrdfRuleChip * FabricDomain::FindChipInTheseChips(TARGETING::TargetHandle_t i_pchipHandle, TARGETING::TargetHandleList & i_chips)
{
    using namespace TARGETING;

    PRDF_DENTER( "FabricDomain::FindChipNumber" );
    PrdfRuleChip * l_fabChip = NULL;
    TargetHandle_t l_tmpfabHandle= NULL;
    // Loop through all chips.
    for (TargetHandleList::iterator iter = i_chips.begin(); iter != i_chips.end(); ++iter)
    {
        for (uint32_t i = 0; i < GetSize(); ++i)
        {
            l_fabChip = LookUp(i);
            l_tmpfabHandle = l_fabChip->GetChipHandle();
            if( (l_tmpfabHandle == (*iter)) && (l_tmpfabHandle == i_pchipHandle) ) return(l_fabChip);
        }
    }

    PRDF_DEXIT( "FabricDomain::FindChipNumber" );
    return(NULL);
}

//Swaps chip at location 0 with a chip at location i_chipToFront
void FabricDomain::MoveToFrontInTheseChips(uint32_t i_chipToFront, TARGETING::TargetHandleList & i_chips)
{
    using namespace TARGETING;

    for (TargetHandleList::iterator i = i_chips.begin()+i_chipToFront; i != i_chips.begin(); i--)
    {
        std::swap((*i), (*(i-1)));
    }
}
