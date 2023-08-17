/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/odyssey/prdfOdyPllPlugins.C $   */
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

#include <prdfBitString.H>
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfPluginMap.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace odyssey_ocmb
{

//------------------------------------------------------------------------------

/**
 * @brief  Queries for PLL unlock attentions on this chip.
 * @param  i_chip An OCMB chip.
 * @param  o_attn True, if there is an active attention. False, otherwise.
 * @return PRD_POWER_FAULT if a power fault is detected on during a SCOM
 *         operation. Non-SUCCESS on any other failure. SUCCESS, otherwise.
 */
int32_t queryPllUnlock(ExtensibleChip* i_chip, bool& o_attn)
{
    int32_t rc = SUCCESS;

    o_attn = false; // default

    do
    {
        auto fir = i_chip->getRegister("TP_LOCAL_FIR");
        auto msk = i_chip->getRegister("TP_LOCAL_FIR_MASK");
        auto err = i_chip->getRegister("BC_OR_PCBSLV_ERROR");

        // clang-format off
        rc = fir->Read(); if (SUCCESS != rc) break;
        rc = msk->Read(); if (SUCCESS != rc) break;
        rc = err->Read(); if (SUCCESS != rc) break;
        // clang-format on

        // If the PCB slave error bit is set and BC_OR_PCBSLV_ERROR[24:31] has a
        // non-zero value, there is a PLL unlock error on this chip.
        if (fir->IsBitSet(18) && !msk->IsBitSet(18) &&
            (0 != err->GetBitFieldJustified(24, 8)))
        {
            o_attn = true;
        }

    } while (0);

    return rc;
}
PRDF_PLUGIN_DEFINE(odyssey_ocmb, queryPllUnlock);

//------------------------------------------------------------------------------
} // end namespace odyssey_ocmb

} // end namespace PRDF
