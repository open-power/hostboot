/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10PllDomain.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2003,2022                        */
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

PllDomain::PllDomain(DOMAIN_ID i_domainId) :
    RuleChipDomain(i_domainId, PllDomain::CONTAINER_SIZE),
    ExtensibleDomain("PllDomain")
{}

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

int32_t PllDomain::Analyze(STEP_CODE_DATA_STRUCT& io_sc,
                           ATTENTION_TYPE attentionType)
{
    ExtensibleChipFunction* func = nullptr;

    #ifdef __HOSTBOOT_MODULE
    // Due to clock issues some chips may be moved to non-functional during
    // analysis. In this case, these chips will need to be removed from the
    // domains.
    std::vector<ExtensibleChip*> nfchips;
    #endif

    #ifdef __HOSTBOOT_MODULE
    // A summary of all error types that need to be masked and/or cleared. These
    // are two separate variables because we only want to mask attentions when
    // they have hit their respective thresholds.
    std::map<ExtensibleChip*, PllErrTypes> maskErrTypes;
    std::map<ExtensibleChip*, PllErrTypes> clearErrTypes;
    #endif

    // Keep track of all chips with PLL unlock attentions because callout
    // priorities are dependend on number of chips at attention.
    std::vector<ExtensibleChip*> pllUnlockClk0;
    std::vector<ExtensibleChip*> pllUnlockClk1;

    #ifndef __HOSTBOOT_MODULE
    // Will need to set the dump content if there are any active attentions.
    // This only needs to be done once.
    bool dumpContentSet = false;
    #endif

    // Keep track of the chips with errors so that we can add more FFDC later.
    std::vector<ExtensibleChip*> ffdcChips{};

    // Examine each chip in the domain.
    for (unsigned int index = 0; index < GetSize(); ++index)
    {
        ExtensibleChip* chip = LookUp(index);
        TargetHandle_t  trgt = chip->getTrgt();
        HUID            huid = chip->getHuid();

        #ifdef __HOSTBOOT_MODULE
        // Skip this chip if it is non-functional.
        if (!PlatServices::isFunctional(trgt))
        {
            nfchips.push_back(chip);
            continue;
        }
        #endif

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

        #ifdef __HOSTBOOT_MODULE
        // Keep a cumulative list of the error types that need to be cleared.
        clearErrTypes[chip] = errTypes;
        #endif

        // Capture any registers needed for PLL analysis, which would be
        // captured by default during normal analysis.
        chip->CaptureErrorData(io_sc.service_data->GetCaptureData(),
                               Util::hashString("default_pll_ffdc"));

        // Keep track of the chips with errors so that we can add more FFDC
        // later.
        ffdcChips.push_back(chip);

        // Set the primary signature to the generic error signature.
        io_sc.service_data->setSignature(huid, PRDFSIG_RCS_PLL_ERROR);

        // Add each error type to the multi-signature list and keep track of
        // each chip which will be used later.
        #define TMP_FUNC(TYPE) \
        if (errTypes.query(PllErrTypes::TYPE)) \
        {\
            io_sc.service_data->AddSignatureList(trgt, PRDFSIG_##TYPE); \
        }

        TMP_FUNC(PLL_UNLOCK_0   )
        TMP_FUNC(PLL_UNLOCK_1   )
        TMP_FUNC(RCS_OSC_ERROR_0)
        TMP_FUNC(RCS_OSC_ERROR_1)
        TMP_FUNC(RCS_UNLOCKDET_0)
        TMP_FUNC(RCS_UNLOCKDET_1)

        #undef TMP_FUNC

        // The RCS OSC error and RCS unlock detect attentions have a shared
        // threshold counter per chip per clock.
        if (errTypes.query(PllErrTypes::RCS_OSC_ERROR_0) ||
            errTypes.query(PllErrTypes::RCS_UNLOCKDET_0))
        {
            // Callout the clock.
            PRDcallout clockCallout {trgt, PRDcalloutData::TYPE_PROCCLK0};
            io_sc.service_data->SetCallout(clockCallout, MRU_HIGH);

            // Callout the processor. Do not guard on any callout.
            io_sc.service_data->SetCallout(trgt, MRU_LOW, NO_GARD);

            #ifdef __HOSTBOOT_MODULE

            // Initiate recovery (if RCS OSC error).
            bool recovFail = false;
            if (errTypes.query(PllErrTypes::RCS_OSC_ERROR_0))
            {
                recovFail = rcsTransientErrorRecovery(chip, 0);
            }

            // Check threshold (still required even if recovery fails).
            bool atTh = iv_thRcsClk0[chip].inc(io_sc);

            if (recovFail || atTh)
            {
                // Make a predictive callout.
                io_sc.service_data->setPredictive();

                // Ensure these attentions are masked later.
                maskErrTypes[chip].set(PllErrTypes::RCS_OSC_ERROR_0);
                maskErrTypes[chip].set(PllErrTypes::RCS_UNLOCKDET_0);

                // Set alternate ref clock mode on this chip.
                SCAN_COMM_REGISTER_CLASS* r3 = chip->getRegister("ROOT_CTRL3");
                if (SUCCESS == r3->Read())
                {
                    r3->SetBit(3);
                    r3->Write();
                }

                // Prevent failing over to the bad clock.
                SCAN_COMM_REGISTER_CLASS* r5 = chip->getRegister("ROOT_CTRL5");
                if (SUCCESS == r5->Read())
                {
                    r5->SetBit(5);
                    r5->Write();
                }
            }

            #endif // __HOSTBOOT_MODULE
        }

        // The RCS OSC error and RCS unlock detect attentions have a shared
        // threshold counter per chip per clock.
        if (errTypes.query(PllErrTypes::RCS_OSC_ERROR_1) ||
            errTypes.query(PllErrTypes::RCS_UNLOCKDET_1))
        {
            // Callout the clock.
            PRDcallout clockCallout {trgt, PRDcalloutData::TYPE_PROCCLK1};
            io_sc.service_data->SetCallout(clockCallout, MRU_HIGH);

            // Callout the processor. Do not guard on any callout.
            io_sc.service_data->SetCallout(trgt, MRU_LOW, NO_GARD);

            #ifdef __HOSTBOOT_MODULE

            // Initiate recovery (if RCS OSC error).
            bool recovFail = false;
            if (errTypes.query(PllErrTypes::RCS_OSC_ERROR_1))
            {
                recovFail = rcsTransientErrorRecovery(chip, 1);
            }

            // Check threshold (still required even if recovery fails).
            bool atTh = iv_thRcsClk1[chip].inc(io_sc);

            if (recovFail || atTh)
            {
                // Make a predictive callout.
                io_sc.service_data->setPredictive();

                // Ensure these attentions are masked later.
                maskErrTypes[chip].set(PllErrTypes::RCS_OSC_ERROR_1);
                maskErrTypes[chip].set(PllErrTypes::RCS_UNLOCKDET_1);

                // Set alternate ref clock mode on this chip.
                SCAN_COMM_REGISTER_CLASS* r3 = chip->getRegister("ROOT_CTRL3");
                if (SUCCESS == r3->Read())
                {
                    r3->SetBit(7);
                    r3->Write();
                }

                // Prevent failing over to the bad clock.
                SCAN_COMM_REGISTER_CLASS* r5 = chip->getRegister("ROOT_CTRL5");
                if (SUCCESS == r5->Read())
                {
                    r5->SetBit(5);
                    r5->Write();
                }
            }

            #endif // __HOSTBOOT_MODULE
        }

        // Keep a running list of chips with PLL unlock attentions.
        if (errTypes.query(PllErrTypes::PLL_UNLOCK_0))
        {
            pllUnlockClk0.push_back(chip);
        }
        if (errTypes.query(PllErrTypes::PLL_UNLOCK_1))
        {
            pllUnlockClk1.push_back(chip);
        }

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

        #ifndef __HOSTBOOT_MODULE
        // Set the dump content. This only needs to be done once.
        if (!dumpContentSet)
        {
            io_sc.service_data->SetDump(CONTENT_HW, trgt);
            dumpContentSet = true;
        }
        #endif
    }

    // Capture more FFDC, if possible. The reason this is here in a separate
    // loop from above is that there is only so much space for FFDC and we are
    // capturing a lot of registers. The registers we captured above are
    // essential for debug and the rest of the registers are only useful if we
    // have the room.
    for (const auto& chip : ffdcChips)
    {
        // Capture the rest of this chip's PLL FFDC.
        func = chip->getExtensibleFunction("capturePllFfdc");
        (*func)(chip, PluginDef::bindParm<STEP_CODE_DATA_STRUCT &>(io_sc));
    }

    #ifdef __HOSTBOOT_MODULE
    // Remove all non-functional chips.
    for (const auto& i : nfchips)
    {
        systemPtr->RemoveStoppedChips(i->getTrgt());
    }
    #endif

    // Check PLL unlock attentions on OSC 0.
    if (!pllUnlockClk0.empty())
    {
        PRDpriority clockPri = (1 == pllUnlockClk0.size()) ? MRU_MED : MRU_HIGH;

        #ifdef __HOSTBOOT_MODULE
        // Check threshold.
        bool atTh = iv_thPllClk0.inc(io_sc);
        #endif

        // Add callouts for each chip.
        for (const auto& chip : pllUnlockClk0)
        {
            TargetHandle_t trgt = chip->getTrgt();

            // Callout the clock.
            PRDcallout clockCallout {trgt, PRDcalloutData::TYPE_PROCCLK0};
            io_sc.service_data->SetCallout(clockCallout, clockPri);

            // Callout the processor. Do not guard on any callout.
            io_sc.service_data->SetCallout(trgt, MRU_MED, NO_GARD);

            #ifdef __HOSTBOOT_MODULE
            // Actions if at threshold.
            if (atTh)
            {
                // Make a predictive callout.
                io_sc.service_data->setPredictive();

                // Ensure these attentions are masked later.
                maskErrTypes[chip].set(PllErrTypes::PLL_UNLOCK_0);
            }
            #endif
        }
    }

    // Check PLL unlock attentions on OSC 1.
    if (!pllUnlockClk1.empty())
    {
        PRDpriority clockPri = (1 == pllUnlockClk1.size()) ? MRU_MED : MRU_HIGH;

        #ifdef __HOSTBOOT_MODULE
        // Check threshold.
        bool atTh = iv_thPllClk1.inc(io_sc);
        #endif

        // Add callouts for each chip.
        for (const auto& chip : pllUnlockClk1)
        {
            TargetHandle_t trgt = chip->getTrgt();

            // Callout the clock.
            PRDcallout clockCallout {trgt, PRDcalloutData::TYPE_PROCCLK1};
            io_sc.service_data->SetCallout(clockCallout, clockPri);

            // Callout the processor. Do not guard on any callout.
            io_sc.service_data->SetCallout(trgt, MRU_MED, NO_GARD);

            #ifdef __HOSTBOOT_MODULE
            // Actions if at threshold.
            if (atTh)
            {
                // Make a predictive callout.
                io_sc.service_data->setPredictive();

                // Ensure these attentions are masked later.
                maskErrTypes[chip].set(PllErrTypes::PLL_UNLOCK_1);
            }
            #endif
        }
    }

    #ifdef __HOSTBOOT_MODULE // only allowed to modify hardware from the host

    // The following plugins to mask/clear attentions follow all the rules for
    // masking/clearing attentions on a single chip. However, if there were ANY
    // active attentions we would want clear/mask PLL unlock attentions on all
    // chips due to the rules specified in the design dococument.
    if (!maskErrTypes.empty())
    {
        for (unsigned int index = 0; index < GetSize(); ++index)
        {
            ExtensibleChip* chip = LookUp(index);
            maskErrTypes[chip].set(PllErrTypes::PLL_UNLOCK_0);
            maskErrTypes[chip].set(PllErrTypes::PLL_UNLOCK_1);
        }
    }
    if (!clearErrTypes.empty())
    {
        for (unsigned int index = 0; index < GetSize(); ++index)
        {
            ExtensibleChip* chip = LookUp(index);
            clearErrTypes[chip].set(PllErrTypes::PLL_UNLOCK_0);
            clearErrTypes[chip].set(PllErrTypes::PLL_UNLOCK_1);
        }
    }

    // Mask attentions.
    for (const auto& e : maskErrTypes)
    {
        func = e.first->getExtensibleFunction("maskPllErrTypes");
        (*func)(e.first, PluginDef::bindParm<const PllErrTypes&>(e.second));
    }

    // Clear attentions.
    for (const auto& e : clearErrTypes)
    {
        func = e.first->getExtensibleFunction("clearPllErrTypes");
        (*func)(e.first, PluginDef::bindParm<const PllErrTypes&>(e.second));
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

