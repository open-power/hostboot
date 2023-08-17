/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/odyssey/prdfOdyPllDomain.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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

#include <UtilHash.H>
#include <iipServiceDataCollector.h>
#include <iipSystem.h>
#include <iipsdbug.h>
#include <prdfOdyExtraSig.H>
#include <prdfOdyPllDomain.H>
#include <prdfPlatServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

bool OdyPllDomain::Query(ATTENTION_TYPE i_attnType)
{
    // Ensure the list of chips with PLL attentions is initially empty.
    iv_pllChips.clear();

    // This is an overloaded function from the parent class, which requires the
    // attention type parameter. PLL errors only report as recoverable
    // attentions, which are always checked first in the case of a system
    // checkstop. Therefore, this function only reports attentions if the given
    // type is recoverable.
    if (RECOVERABLE != i_attnType)
    {
        return false;
    }

#ifdef __HOSTBOOT_MODULE

    // Due to clock issues some chips may be moved to non-functional during
    // analysis. In this case, these chips will need to be removed from the
    // domains. Only valid to do for Hostboot/HBRT because the functional status
    // is only synched to FSP at select times.
    std::vector<ExtensibleChip*> nfchips;
    for (unsigned int index = 0; index < GetSize(); ++index)
    {
        ExtensibleChip* chip = LookUp(index);
        if (!PlatServices::isFunctional(chip->getTrgt()))
        {
            nfchips.push_back(chip);
        }
    }
    for (const auto& chip : nfchips)
    {
        systemPtr->RemoveStoppedChips(chip->getTrgt());
    }

    // In an effort to avoid unnecessry SCOMs to hardware, we can query the
    // list of chips with attentions that ATTN passes to PRD. Note that this
    // will only work for Hostboot/HBRT because the FSP does not have access to
    // the true value of the ATTR_ATTN_CHK_OCMBS attribute and won't be able to
    // determine if the attention list is accurate for the current IPL state.
    // Therefore, FSP must SCOM all of the OCMBs regardless.

    // When the IPL-only ATTR_ATTN_CHK_OCMBS attribute is set to a non-zero
    // value, the system has IPLed to a point where the OCMBs are active, but
    // the OMI bus has not yet been configured to forward attention to the
    // processor. In which case, ATTN will add all OCMBs with active attentions
    // to the list of chips it passes to PRD. This will be checked later when we
    // iterate the chips in the domain.
    bool checkOcmbs = false;
#ifndef __HOSTBOOT_RUNTIME
    checkOcmbs = (0 != getSystemTarget()->getAttr<ATTR_ATTN_CHK_OCMBS>());
#endif

    // When the ATTR_ATTN_CHK_OCMBS attribute is set to zero, there will only be
    // processor chips in the attention list. So the best we can do is look at
    // the state of the connected processor. This only needs to be checked once
    // for the domain since all OCMBs in the domain are behind the same
    // processor.
    if (!checkOcmbs && 0 < GetSize())
    {
        ExtensibleChip* ocmbChip = LookUp(0); // Just use the first one.
        auto procTrgt = getConnectedParent(ocmbChip->getTrgt(), TYPE_PROC);
        SYSTEM_DEBUG_CLASS sysdbug;
        if (!sysdbug.isActiveAttentionPending(procTrgt, RECOVERABLE))
        {
            return false;
        }
    }

#endif // __HOSTBOOT_MODULE

    for (unsigned int index = 0; index < GetSize(); ++index)
    {
        ExtensibleChip* chip = LookUp(index);

#ifdef __HOSTBOOT_MODULE

        // When the ATTR_ATTN_CHK_OCMBS attribute is set to a non-zero value,
        // check if this chip is in the list of chips with active attentions.
        if (checkOcmbs)
        {
            SYSTEM_DEBUG_CLASS sysdbug;
            if (!sysdbug.isActiveAttentionPending(chip->getTrgt(), RECOVERABLE))
            {
                continue; // Try the next chip.
            }
        }

#endif // __HOSTBOOT_MODULE

        // Query this chip for an active attention.
        bool attn  = false;
        auto func  = chip->getExtensibleFunction("queryPllUnlock");
        int32_t rc = (*func)(chip, PluginDef::bindParm<bool&>(attn));

        if (PRD_POWER_FAULT == rc)
        {
            PRDF_ERR("[OdyPllDomain::Query] Power Fault detected: chip=0x%08x",
                     chip->getHuid());
            break; // No need to continue.
        }
        else if (SUCCESS != rc)
        {
            PRDF_ERR("[OdyPllDomain::Query] SCOM failed: rc=%x chip=0x%08x", rc,
                     chip->getHuid());
            continue; // Try the next chip.
        }
        else if (attn)
        {
            // There is an active attention. So add this chip to the list.
            iv_pllChips.push_back(chip);
        }
    }

    return !iv_pllChips.empty();
}

//------------------------------------------------------------------------------

int32_t OdyPllDomain::Analyze(STEP_CODE_DATA_STRUCT& io_sc,
                              ATTENTION_TYPE i_attnType)
{
    // This function should never be called when iv_pllChips is empty. That
    // would be an internal logic error.
    if (iv_pllChips.empty())
    {
        PRDF_ERR("[OdyPllDomain::Analyze] no active attentions");
        return PRD_INTERNAL_CODE_ERROR;
    }

    // Get the first OCMB in the list and the connected processor chip. These
    // will be useful in several places where iterating will not be necessary.
    // Reminder: there should only be one connected processor per Odyssey PLL
    // domain.
    auto firstTrgt = iv_pllChips.front()->getTrgt();
    auto procTrgt  = getConnectedParent(firstTrgt, TYPE_PROC);

    // Set the primary signature indicating there was a PLL unlock. Just use the
    // first OCMB in the list if there are more than one.
    io_sc.service_data->setSignature(getHuid(firstTrgt), PRDFSIG_PLL_UNLOCK);

    for (const auto& chip : iv_pllChips)
    {
        // Add the error signature for each chip to the multi-signature list.
        io_sc.service_data->AddSignatureList(chip->getTrgt(),
                                             PRDFSIG_PLL_UNLOCK);

        // Capture any registers needed for PLL analysis, which would be
        // captured by default during normal analysis.
        chip->CaptureErrorData(io_sc.service_data->GetCaptureData(),
                               Util::hashString("default_pll_ffdc"));

        // PLL unlock attentions could have downstream effects. Link this log to
        // any possible recent HWP failures.
        PlatServices::hwpErrorIsolation(chip, io_sc);
    }

    // Capture more FFDC, if possible. The reason this is here in a separate
    // loop from above is that there is only so much space for FFDC and we are
    // capturing a lot of registers. The registers we captured above are
    // essential for debug and the rest of the registers are only useful if we
    // have the room.
    for (const auto& chip : iv_pllChips)
    {
        chip->CaptureErrorData(io_sc.service_data->GetCaptureData(),
                               Util::hashString("pll_ffdc"));
    }

    // The hardware callouts will be all OCMBs with PLL unlock attentions and
    // the connected processor chip. The callout priorities are dependent on the
    // number of chips at attention.
    if (1 == iv_pllChips.size())
    {
        // There is only one OCMB chip with a PLL unlock. So, the error is
        // likely in the OCMB.
        io_sc.service_data->SetCallout(firstTrgt, MRU_HIGH, GARD);
        io_sc.service_data->SetCallout(procTrgt, MRU_LOW, NO_GARD);
    }
    else
    {
        // There are more than one OCMB chip with a PLL unlock. So, the error is
        // likely the clock source, which is the processor.
        io_sc.service_data->SetCallout(procTrgt, MRU_HIGH, GARD);
        for (const auto& ocmb : iv_pllChips)
        {
            io_sc.service_data->SetCallout(ocmb->getTrgt(), MRU_LOW, NO_GARD);
        }
    }

#ifdef __HOSTBOOT_MODULE // Special cases for Hostboot/HBRT only

    // Increment the threshold counter. If at threshold, make the log predictive
    // and mask PLL unlock attentions on all chips in the domain.
    if (iv_thPll.inc(io_sc))
    {
        io_sc.service_data->setPredictive();

        for (unsigned int index = 0; index < GetSize(); ++index)
        {
            auto chip = LookUp(index);
            auto func = chip->getExtensibleFunction("maskPllUnlock");
            (*func)(chip, PluginDef::bindParm<void*>(nullptr));
        }
    }

    // Clear PLL unlock attentions on all chips in the domain.
    for (unsigned int index = 0; index < GetSize(); ++index)
    {
        auto chip = LookUp(index);
        auto func = chip->getExtensibleFunction("clearPllUnlock");
        (*func)(chip, PluginDef::bindParm<void*>(nullptr));
    }

#else // Special cases for FSP only

    // Set the dump content for system checkstop analysis.
    io_sc.service_data->SetDump(CONTENT_HW, procTrgt);

    // TODO: RTC 184513 - It is possible to have a PLL unlock, a UE RE, and an
    // SUE CS. Isolation should be to the PLL error and then the additional FFDC
    // should show there was an SUE CS were the root is the UE RE. However, PRD
    // does not know how to handle three attentions at the same time. For now
    // this will remain a limitation due to time constraints, but there is a
    // proposal in RTC 184513 that will be solved later. In the meantime, there
    // is a hole in our analysis that needs to be fixed. If there is an SUE CS
    // and no UE RE, PRD assumes the UE RE was already predictively called out
    // in a previous error log. Therefore, nothing will be guarded in this error
    // log. In the example stated above, the current PRD code will not see the
    // UE RE because of the higher priority PLL unlock. So even though there is
    // a UE RE present, nothing gets guarded. To circumvent this, we will set
    // the UE RE flag here even though the PLL error is not the true SUE source.
    if (CHECK_STOP == io_sc.service_data->getPrimaryAttnType())
    {
        io_sc.service_data->SetUERE();
    }

#endif // Special cases

    return SUCCESS;
}

//------------------------------------------------------------------------------

} // end namespace PRDF
