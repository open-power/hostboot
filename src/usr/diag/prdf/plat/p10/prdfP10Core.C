/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/p10/prdfP10Core.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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

#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginDef.H>
#include <prdfPluginMap.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace p10_core
{

#ifdef __HOSTBOOT_RUNTIME
/**
 * @brief Helper function to mask off all attentions from a core due to a core
 *        unit checkstop.
 * @param The target core.
 */
void __maskIfCoreCs(ExtensibleChip* i_chip)
{
    // Masking at the chiplet level. Will need the parent EQ and the bit
    // position of the core within the chiplet FIRs.
    ExtensibleChip* eq = getConnectedParent(i_chip, TYPE_EQ);
    unsigned int bit = 5 + i_chip->getPos() % MAX_EC_PER_EQ; // bits 5-8

    // Mask this core in the chiplet FIRs for all attention types.
    const char* list[] = {"EQ_CHIPLET_CS_FIR_MASK",
                          "EQ_CHIPLET_RE_FIR_MASK",
                          "EQ_CHIPLET_UCS_FIR_MASK"};
    for (auto reg : list)
    {
        SCAN_COMM_REGISTER_CLASS* mask = eq->getRegister(reg);
        if ((SUCCESS == mask->Read()) && !mask->IsBitSet(bit))
        {
            mask->SetBit(bit);
            mask->Write();
        }
    }
}
#endif

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_chip    EC chip.
 * @param  io_sc     The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis(ExtensibleChip* i_chip, STEP_CODE_DATA_STRUCT& io_sc)
{
    #ifdef __HOSTBOOT_RUNTIME
    if ( io_sc.service_data->isProcCoreCS() )
    {
        // Mask off all attentions for this core.
        __maskIfCoreCs(i_chip);

        // Mask off all attentions for the neighbor core, if it exists. Note
        // that if the attention existed in the odd core in the core pair,
        // analysis likely shifted from the even core to the odd core via
        // EQ_CORE_FIR[57]. This will result in the post analysis of the odd
        // core being called, then the post analysis of the even code being
        // called. This will actually result in the this function being called
        // twice for each core. It's a little annoying, but at least we will
        // ensure the appropriate bits are masked in all cases.
        ExtensibleChip* neighborCore = getNeighborCore(i_chip);
        if (neighborCore != nullptr)
        {
            __maskIfCoreCs(neighborCore);
        }

        // NOTE: We no longer need to do a runtime deconfig of the core here as
        // in P10 there is now support for non-fatal unit checkstops at runtime.
        // We want to avoid runtime deconfiguring of the core to avoid problems
        // that it can potentially cause for MPIPL and HWPs.
    }
    else
    {
        int32_t l_rc = restartTraceArray(i_chip->getTrgt());
        if (SUCCESS != l_rc)
        {
            PRDF_ERR( "[EC PostAnalysis HUID: 0x%08x RestartTraceArray failed",
                      i_chip->GetId());
        }

    }
    #endif

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( p10_core, PostAnalysis );

/**
 * @brief  Plugin function for handling the LPC workaround to check if we should
 *         blame the LPC bus for the NCU hang.
 * @param  i_chip    CORE chip.
 * @param  io_sc     The step code data struct.
 * @return PRD_SCAN_COMM_REGISTER_ZERO.
 */
int32_t lpcWorkaround( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[p10_core::lpcWorkaround] "

    // No-op in Hostboot.
    return PRD_SCAN_COMM_REGISTER_ZERO;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( p10_core, lpcWorkaround );

} // end namespace p10_core

} // end namespace PRDF
