/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10ProcDomain.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2002,2020                        */
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
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <prdfGlobal.H>
#include <iipstep.h>
#include <iipsdbug.h>
#include <iipErrorRegister.h>
#include <iipServiceDataCollector.h>
#include <prdfP10ProcDomain.H>
#include <UtilHash.H>
#include <prdfPluginDef.H>

#include <prdfPlatServices.H>

#include <algorithm>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

int32_t ProcDomain::Analyze(STEP_CODE_DATA_STRUCT & serviceData,
                              ATTENTION_TYPE attentionType)
{
    int32_t l_rc;
    l_rc = DomainContainer<RuleChip>::Analyze(serviceData, attentionType);


    if( l_rc == PRD_POWER_FAULT )
    {
        PRDF_ERR( "PrdfProcDomain::Analyze::Power Fault detected!" );
    }
    else
    {
        // Capture Global FIRs on xstp and recovered errors for domain.
        if ((attentionType == MACHINE_CHECK) || (attentionType == RECOVERABLE))
        {
            // start at 1 to skip analyzed
            for (uint32_t i = 1; i < GetSize(); ++i)
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

void ProcDomain::Order(ATTENTION_TYPE attentionType)
{

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
        for (int32_t i = (GetSize() - 1); i >= 0; --i)
        {
            RuleChip * l_procChip = LookUp(i);
            TargetHandle_t l_pchipHandle = l_procChip->GetChipHandle();
            bool l_analysisPending =
                sysdbug.isActiveAttentionPending(l_pchipHandle, attentionType );
            if ( l_analysisPending )
            {
                MoveToFront(i);
                break;
            }
        }
    }
}

// Finds the first chip with an active checkstop attention that did not
// originate from a connected processor and moves it to the front of the domain.
void ProcDomain::SortForXstop()
{
    // Before stitching the nodes together, any system checkstop will be limited
    // to a single node and ATTN will only pass us chips belonging to the node
    // that raised the attention. In this scenario, we should only consider
    // chips belonging this node.
    TargetHandle_t nodeTrgt = nullptr;
    if ( false == isSmpCoherent() )
    {
        SYSTEM_DEBUG_CLASS sysDebug;
        TargetHandle_t proc = sysDebug.getTargetWithAttn(TYPE_PROC,
                                                         MACHINE_CHECK);
        nodeTrgt = getConnectedParent(proc, TYPE_NODE);
    }

    // Look for the first chip with active checkstop attentions that did not
    // originate from a connected processor. In case of soft reIPL (i.e. the
    // service processor is not reset), start looking at the end of the domain
    // to avoid possible starvation.
    for (int i = (GetSize() - 1); i >= 0; --i)
    {
        RuleChip * procChip = LookUp(i);

        // Limit the scope to a node if needed.
        if ((nullptr != nodeTrgt) &&
            (nodeTrgt != getConnectedParent(procChip->getTrgt(), TYPE_NODE)))
        {
            continue;
        }

        // Determine if a checkstop attention originated from this chip.
        bool internalAttn = false;

        ExtensibleChipFunction * extFunc
            = procChip->getExtensibleFunction("GetCheckstopInfo");

        (*extFunc)(procChip, PluginDef::bindParm<bool &>(internalAttn));

        if (internalAttn)
        {
            // Move this chip to the front of the domain.
            MoveToFront(i);
            break;
        }
    }
}

namespace __prdfProcDomain
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
};

void ProcDomain::SortForRecov()
{
    using namespace PluginDef;

    SYSTEM_DEBUG_CLASS sysdbug;
    uint32_t l_sev[GetSize()];
    std::fill(&l_sev[0], &l_sev[GetSize()], 0);

    // Loop through all chips.
    for ( uint32_t i = 0; i < GetSize(); ++i )
    {
        RuleChip * l_procChip = LookUp(i);
        TargetHandle_t l_pchipHandle = l_procChip->GetChipHandle();

        //check if chip has an attention which has not been analyzed as yet
        if( sysdbug.isActiveAttentionPending( l_pchipHandle, RECOVERABLE ) )
        {
            // Find severity level.
            ExtensibleChipFunction * l_extFunc
                    = l_procChip->getExtensibleFunction(
                                                "CheckForRecoveredSev");

            (*l_extFunc)(l_procChip, bindParm<uint32_t &>( l_sev[i] ));
        }

    }

    // Find item with highest severity.
    MoveToFront(std::distance(&l_sev[0],
                              std::max_element(&l_sev[0],
                                              &l_sev[GetSize()],
                             __prdfProcDomain::lessThanOperator)));
}

} //end namespace PRDF
