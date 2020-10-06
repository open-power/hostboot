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

#include <prdfP10ProcExtraSig.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

int32_t PllDomain::Initialize(void)
{

  int32_t rc = SUCCESS;
  return(rc);
}

//------------------------------------------------------------------------------

bool PllDomain::Query(ATTENTION_TYPE i_attnType)
{
    bool atAttn = false;

    // System always checks for RE's first, even if there is an XSTOP
    // So we only need to check for PLL errors on RECOVERABLE type
    if (RECOVERABLE == i_attnType)
    {
        int32_t rc = SUCCESS;
        ExtensibleChipFunction* func = nullptr;
        SYSTEM_DEBUG_CLASS sysdbug;

        for (unsigned int index = 0; index < GetSize(); ++index)
        {
            ExtensibleChip* chip = LookUp(index);

            // Only query if there is an active pending recoverable attention on
            // this chip.
            if (!sysdbug.isActiveAttentionPending(chip->getTrgt(), RECOVERABLE))
                continue;

            // Query for any clock errors.
            PllErrTypes errTypes;
            func = chip->getExtensibleFunction("queryPllErrTypes");
            rc = (*func)(chip, PluginDef::bindParm<PllErrTypes&>(errTypes));

            if (PRD_POWER_FAULT == rc)
            {
                PRDF_ERR("[PllDomain::Query] Power Fault detected: "
                         "chip=0x%08x", chip->getHuid());
                break; // No need to continue.
            }
            else if (SUCCESS != rc)
            {
                PRDF_ERR("[PllDomain::Query] SCOM failed: rc=%x "
                         "chip=0x%08x", rc, chip->getHuid());
                continue; // Try the next chip.
            }

            // If there are any clock errors, we are done.
            if ( errTypes.any() )
            {
                atAttn = true;
                break;
            }
        }
    }

    return atAttn;
}

//------------------------------------------------------------------------------

void __callout(STEP_CODE_DATA_STRUCT& io_sc,
                   std::map<PllErrTypes::Types,
                            std::vector<ExtensibleChip*>>& i_errList,
                   PllErrTypes::Types i_errType,
                   PRDpriority i_clockPri = MRU_HIGH,
                   PRDpriority i_procPri  = MRU_LOW)
{
    // Get the clock callout type.
    PRDcalloutData::MruType clockType = PRDcalloutData::TYPE_NONE;
    switch (i_errType)
    {
        case PllErrTypes::PLL_UNLOCK_0:
        case PllErrTypes::RCS_OSC_ERROR_0:
        case PllErrTypes::RCS_UNLOCKDET_0:
            clockType = PRDcalloutData::TYPE_PROCCLK0;
            break;

        case PllErrTypes::PLL_UNLOCK_1:
        case PllErrTypes::RCS_OSC_ERROR_1:
        case PllErrTypes::RCS_UNLOCKDET_1:
            clockType = PRDcalloutData::TYPE_PROCCLK1;
            break;

        default:
            PRDF_ASSERT(0);
    }

    // Add callouts for each chip in the list, if needed.
    for (const auto& chip : i_errList[i_errType])
    {
        // Callout the clock.
        PRDcallout clockCallout { chip->getTrgt(), clockType };
        io_sc.service_data->SetCallout(clockCallout, i_clockPri);

        // Callout the processor.
        io_sc.service_data->SetCallout(chip->getTrgt(), i_procPri);
    }
}

int32_t PllDomain::Analyze(STEP_CODE_DATA_STRUCT& io_sc,
                           ATTENTION_TYPE attentionType)
{
    // Due to clock issues some chips may be moved to non-functional during
    // analysis. In this case, these chips will need to be removed from the
    // domains.
    std::vector<ExtensibleChip*> nfchips;

    // A summary of all error types found.
    PllErrTypes errTypesSummary;

    // Keep track of all chips with attentions. They will be used for the
    // primary signature and callouts later.
    std::map<PllErrTypes::Types, std::vector<ExtensibleChip*>> errList;

    // Examine each chip in the domain.
    for (unsigned int index = 0; index < GetSize(); ++index)
    {
        ExtensibleChip*         chip = LookUp(index);
        ExtensibleChipFunction* func = nullptr;
        TargetHandle_t          trgt = chip->getTrgt();

        // Skip this chip if it is non-functional.
        if (!PlatServices::isFunctional(trgt))
        {
            nfchips.push_back(chip);
            continue;
        }

        // Check if this chip has a clock error.
        PllErrTypes errTypes;
        func = chip->getExtensibleFunction("queryPllErrTypes");
        int32_t rc = (*func)(chip, PluginDef::bindParm<PllErrTypes&>(errTypes));
        if (SUCCESS != rc)
        {
            continue; // Try the next chip.
        }

        // Skip this chip if it does not have any clock errors.
        if (!errTypes.any())
        {
            continue;
        }

        // Keep a cumulative list of the error types.
        errTypesSummary = errTypesSummary | errTypes;

        // Capture any registers needed for PLL analysis, which would be
        // captured by default during normal analysis.
        chip->CaptureErrorData(io_sc.service_data->GetCaptureData(),
                               Util::hashString("default_pll_ffdc"));

        // Capture the rest of this chip's PLL FFDC.
        func = chip->getExtensibleFunction("capturePllFfdc");
        (*func)(chip, PluginDef::bindParm<STEP_CODE_DATA_STRUCT &>(io_sc));

        // Add each error type to the multi-signature list and keep track of
        // each chip which will be used later.
        #define TMP_FUNC(TYPE) \
        if (errTypes.query(PllErrTypes::TYPE)) \
        {\
            io_sc.service_data->AddSignatureList(trgt, PRDFSIG_##TYPE); \
            errList[PllErrTypes::TYPE].push_back(chip); \
        }

        TMP_FUNC(PLL_UNLOCK_0   )
        TMP_FUNC(PLL_UNLOCK_1   )
        TMP_FUNC(RCS_OSC_ERROR_0)
        TMP_FUNC(RCS_OSC_ERROR_1)
        TMP_FUNC(RCS_UNLOCKDET_0)
        TMP_FUNC(RCS_UNLOCKDET_1)

        #undef TMP_FUNC

        // Special cases for types that could have downstream effects.
        if (errTypes.query(PllErrTypes::PLL_UNLOCK_0   ) ||
            errTypes.query(PllErrTypes::PLL_UNLOCK_1   ) ||
            errTypes.query(PllErrTypes::RCS_OSC_ERROR_0) ||
            errTypes.query(PllErrTypes::RCS_OSC_ERROR_1))
        {
            // If any RCS OSC errors or PLL unlocks on this chip, link this log
            // to any possible recent HWP failures.
            PlatServices::hwpErrorIsolation(chip, io_sc);

            // TODO: RTC 184513 - It is possible to have a PLL unlock, a UE RE,
            // and an SUE CS. Isolation should be to the PLL error and then the
            // additional FFDC should show there was an SUE CS were the root is
            // the UE RE. However, PRD does not know how to handle three
            // attentions at the same time. For now this will remain a
            // limitation due to time contraits, but there is a proposal in RTC
            // 184513 that will be solved later. In the meantime, there is a
            // hole in our analysis that needs to be fixed. If the is a SUE CS
            // and no UE RE, PRD assumes the UE RE was already predictively
            // called out in a previous error log. Therefore, nothing will be
            // garded in this error log. In the example stated above, the
            // current PRD code will not see the UE RE because of the higher
            // priority PLL unlock. So even though there is a UE RE present,
            // nothing gets garded. To circumvent this, we will set the UERE
            // flag here even though the PLL error is not the true SUE
            // source.
            if (CHECK_STOP == io_sc.service_data->getPrimaryAttnType())
            {
                io_sc.service_data->SetUERE();
            }
        }
    }

    // Remove all non-functional chips.
    if (CHECK_STOP != io_sc.service_data->getPrimaryAttnType())
    {
        for (const auto& i : nfchips)
        {
            systemPtr->RemoveStoppedChips(i->getTrgt());
        }
    }

    // Set the primary signature to the highest priority attention type.
    #define TMP_FUNC(TYPE) \
    if (!errList[PllErrTypes::TYPE].empty()) \
    {\
        HUID huid = errList[PllErrTypes::TYPE].front()->getHuid(); \
        io_sc.service_data->setSignature(huid, PRDFSIG_##TYPE); \
    }

    // This list needs to be from lowest to highest priority so that the last
    // signature set is the highest priority.
    TMP_FUNC(RCS_UNLOCKDET_0)
    TMP_FUNC(RCS_UNLOCKDET_1)
    TMP_FUNC(PLL_UNLOCK_0   )
    TMP_FUNC(PLL_UNLOCK_1   )
    TMP_FUNC(RCS_OSC_ERROR_0)
    TMP_FUNC(RCS_OSC_ERROR_1)

    #undef TMP_FUNC

    // RCS OSC error attentions have the potential of generating PLL unlock
    // attentions, but it is also possible the PLL unlock attentions could have
    // asserted on their own. Unfortunately, there may have been one or more
    // clock failovers due to the RCS OSC error attentions. Therefore, it would
    // be impossible to tell which clock may have generated the PLL unlock
    // attentions. So, if any RCS OSC error attentions are present, PRD must
    // ignore all PLL unlock attentions

    // Similarly, RCS unlock detect attentions only have meaning if found on
    // the non-primary clock. Again, due to potential clock failovers, it would
    // be impossible to tell which clock may have been the primary at the time
    // of the RCS unlock attention. Therefore, PRD must also ignore all RCS
    // unlock detect attentions if there are any RCS OSC error attentions
    // present.

    // Certain PLL unlock attentions have the potential of causing RCS unlock
    // detect attentions, but it is also possible the two error types could
    // have asserted on their own. Regardless, the callouts will be accurate,
    // assuming there are no RCS OSC error attentions. So, the decision is to
    // treat PLL unlock attentions and RCS unlock detect attentions as
    // individual events to simplify PRD analysis.

    // Slow frequency drifts or jitter from the clocks will be reported as PLL
    // unlock attentions. In addition, PLL unlock attentions may indicate there
    // is a problem within the processor that reported the error. Therefore,
    // PRD must call out both the primary clock and the processor. If more than
    // one processor in the clock domain is reporting PLL unlock attentions,
    // then the primary clock is more likely at fault than the processors.
    // Similarly, if all PLL unlock attentions are scoped to a single processor
    // in the clock domain, then the processor is more likely at fault than the
    // primary clock.

    if (errTypesSummary.query(PllErrTypes::RCS_OSC_ERROR_0) ||
        errTypesSummary.query(PllErrTypes::RCS_OSC_ERROR_1))
    {
        // Callout associated clocks/procs, if needed.
        __callout(io_sc, errList, PllErrTypes::RCS_OSC_ERROR_0);
        __callout(io_sc, errList, PllErrTypes::RCS_OSC_ERROR_1);

        // Ensure any PLL unlock or RCS unlock detect errors on either side are
        // ignored. Generally, this means the attentions should be cleared, but
        // we will have to mask these attentions as well if either RCS OSC error
        // attention is masked.
        errTypesSummary.set(PllErrTypes::PLL_UNLOCK_0   );
        errTypesSummary.set(PllErrTypes::PLL_UNLOCK_1   );
        errTypesSummary.set(PllErrTypes::RCS_UNLOCKDET_0);
        errTypesSummary.set(PllErrTypes::RCS_UNLOCKDET_1);
    }
    else
    {
        // Callout associated clocks/procs, if needed.
        __callout(io_sc, errList, PllErrTypes::RCS_UNLOCKDET_0);
        __callout(io_sc, errList, PllErrTypes::RCS_UNLOCKDET_1);

        // Get the total number of chips that reported PLL errors. Note that it
        // should not be possible for a chip to report PLL errors from both
        // clocks because they should only come from the primary clock.
        unsigned int pllChips = errList[PllErrTypes::PLL_UNLOCK_0].size() +
                                errList[PllErrTypes::PLL_UNLOCK_1].size();
        if (0 < pllChips)
        {
            // If PLL unlock errors are present on more than one chip, the clock
            // is more likely to be the problem. If PLL unlock errors are scoped
            // to a single chip, the chip is more likely to be the problem.
            PRDpriority clockPri = (1 == pllChips) ? MRU_MED  : MRU_HIGH;
            PRDpriority procPri  = (1 == pllChips) ? MRU_HIGH : MRU_MED;

            // Callout associated clocks, if needed.
            __callout(io_sc, errList, PllErrTypes::PLL_UNLOCK_0,
                      clockPri, procPri);
            __callout(io_sc, errList, PllErrTypes::PLL_UNLOCK_1,
                      clockPri, procPri);
        }
    }

    // TODO: Currently unsure what the threshold should be for each error type.
    //       Waiting for a response from the RAS team. Will use the default PLL
    //       error threshold for now.
    iv_thPllUnlock.Resolve(io_sc);

    #ifdef __HOSTBOOT_MODULE // only allowed to modify hardware from the host

    // Mask/clear attentions on all chips in the domain.
    for (unsigned int index = 0; index < GetSize(); ++index)
    {
        ExtensibleChip*         c = LookUp(index);
        ExtensibleChipFunction* f = nullptr;

        if (io_sc.service_data->IsAtThreshold())
        {
            f = c->getExtensibleFunction("maskPllErrTypes");
            (*f)(c, PluginDef::bindParm<const PllErrTypes&>(errTypesSummary));
        }

        f = c->getExtensibleFunction("clearPllErrTypes");
        (*f)(c, PluginDef::bindParm<const PllErrTypes&>(errTypesSummary));
    }

    #endif // __HOSTBOOT_MODULE

    return SUCCESS;
}

//------------------------------------------------------------------------------

void PllDomain::Order(ATTENTION_TYPE attentionType)
{
    // Order is not important for PLL errors
}

//------------------------------------------------------------------------------

} // end namespace PRDF

