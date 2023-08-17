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

#ifdef __HOSTBOOT_MODULE

/**
 * @brief  Clears PLL unlock attentions on this chip.
 * @param  i_chip An OCMB chip.
 * @return Non-SUCCESS on failure. SUCCESS, otherwise.
 */
int32_t clearPllUnlock(ExtensibleChip* i_chip)
{
    // Clear the attention by clearing BC_OR_PCBSLV_ERROR[24:31]. Note this
    // register is "write-to-clear". So setting a bit to 1 will tell hardware to
    // clear the bit.
    auto err = i_chip->getRegister("BC_OR_PCBSLV_ERROR");
    err->clearAllBits();
    err->SetBitFieldJustified(24, 8, 0xFF);
    err->Write();

    // Clear the PCB slave error bit in the TP_LOCAL_FIR (by setting the bit).
    auto fir = i_chip->getRegister("TP_LOCAL_FIR");
    fir->clearAllBits();
    fir->SetBit(18);
    fir->Write();

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(odyssey_ocmb, clearPllUnlock);

#endif // __HOSTBOOT_MODULE

//------------------------------------------------------------------------------

#ifdef __HOSTBOOT_MODULE

/**
 * @brief  Masks PLL unlock attentions on this chip.
 * @param  i_chip An OCMB chip.
 * @return Non-SUCCESS on failure. SUCCESS, otherwise.
 */
int32_t maskPllUnlock(ExtensibleChip* i_chip)
{
    // Mask PLL unlock attentions by setting xx_PCBSLV_CONFIG[12:19] in each
    // chiplet to all 1's using a read-modify-write.

    auto tp_config = i_chip->getRegister("TP_PCBSLV_CONFIG");
    if (SUCCESS == tp_config->Read())
    {
        tp_config->SetBitFieldJustified(12, 8, 0xFF);
        tp_config->Write();
    }

    auto mem_config = i_chip->getRegister("MEM_PCBSLV_CONFIG");
    if (SUCCESS == mem_config->Read())
    {
        mem_config->SetBitFieldJustified(12, 8, 0xFF);
        mem_config->Write();
    }

    // Do NOT mask the PCB slave error bit in the TP_LOCAL_FIR because that bit
    // also reports parity errors. Masking the underlying bits should be enough.

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(odyssey_ocmb, maskPllUnlock);

#endif // __HOSTBOOT_MODULE

//------------------------------------------------------------------------------

} // end namespace odyssey_ocmb

} // end namespace PRDF
