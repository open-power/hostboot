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

#include <iipsdbug.h>
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

        auto fir = chip->getRegister("TP_LOCAL_FIR");
        auto msk = chip->getRegister("TP_LOCAL_FIR_MASK");
        auto err = chip->getRegister("BC_OR_PCBSLV_ERROR");

        int32_t rc = SUCCESS;

        // clang-format off
        do {
            rc = fir->Read(); if (SUCCESS != rc) break;
            rc = msk->Read(); if (SUCCESS != rc) break;
            rc = err->Read(); if (SUCCESS != rc) break;
        } while (0);
        // clang-format on

        if (PRD_POWER_FAULT == rc)
        {
            PRDF_ERR("[OdyPllDomain::Query] Power Fault detected: chip=0x%08x",
                     chip->getHuid());
            break; // No need to continue.
        }
        else if (SUCCESS != rc)
        {
            PRDF_ERR("[OdyPllDomain::Query] SCOM failed: rc=%x chip=0x%08x",
                     rc, chip->getHuid());
            continue; // Try the next chip.
        }

        // If TP_LOCAL_FIR[18] set and BC_OR_PCBSLV_ERROR[24:31] has a non-zero
        // value, there is a PLL unlock error on this chip.
        if (fir->IsBitSet(18) && !msk->IsBitSet(18) &&
            (0 != err->GetBitFieldJustified(24, 8)))
        {
            iv_pllChips.push_back(chip);
        }
    }

    return !iv_pllChips.empty();
}

//------------------------------------------------------------------------------

int32_t OdyPllDomain::Analyze(STEP_CODE_DATA_STRUCT& io_sc,
                              ATTENTION_TYPE i_attnType)
{
    // TODO

    return SUCCESS;
}

//------------------------------------------------------------------------------

} // end namespace PRDF
