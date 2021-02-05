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
void maskIfCoreCs( ExtensibleChip * i_chip )
{
    int32_t l_rc = SUCCESS;

    ExtensibleChip * eq = getConnectedParent( i_chip, TYPE_EQ );

    do
    {
        // Get the EQ chiplet level mask registers.
        SCAN_COMM_REGISTER_CLASS * eq_chiplet_cs_fir_mask =
            eq->getRegister("EQ_CHIPLET_CS_FIR_MASK");

        SCAN_COMM_REGISTER_CLASS * eq_chiplet_re_fir_mask =
            eq->getRegister("EQ_CHIPLET_RE_FIR_MASK");

        SCAN_COMM_REGISTER_CLASS * eq_chiplet_ucs_fir_mask =
            eq->getRegister("EQ_CHIPLET_UCS_FIR_MASK");

        // Read values.
        l_rc  = eq_chiplet_cs_fir_mask->Read();
        l_rc |= eq_chiplet_re_fir_mask->Read();
        l_rc |= eq_chiplet_ucs_fir_mask->Read();

        if ( SUCCESS != l_rc ) break;

        uint8_t corePos = i_chip->getPos() % MAX_EC_PER_EQ; // 0-3

        // Mask analysis to the EQ_CORE_FIR depending on the core position
        eq_chiplet_cs_fir_mask->SetBit(5+corePos);
        eq_chiplet_re_fir_mask->SetBit(5+corePos);
        eq_chiplet_ucs_fir_mask->SetBit(5+corePos);

        eq_chiplet_cs_fir_mask->Write();
        eq_chiplet_re_fir_mask->Write();
        eq_chiplet_ucs_fir_mask->Write();

        // Clear the local checkstop summary bit on bit 2 of the RE chiplet FIR
        SCAN_COMM_REGISTER_CLASS * eq_chiplet_re_fir =
            eq->getRegister("EQ_CHIPLET_RE_FIR");
        l_rc = eq_chiplet_re_fir->ForceRead();

        if ( SUCCESS != l_rc ) break;

        if ( eq_chiplet_re_fir->IsBitSet(2) )
        {
            eq_chiplet_re_fir->ClearBit(2);
            eq_chiplet_re_fir->Write();
        }
    }while(0);
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
    // EQ_CORE_FIR[56] indicates that there was a recoverable attention on the
    // other core in the fused core pair. This bit is useless for PRD because
    // the other attention will be reported appropriately. Unfortunately, we
    // can't mask it because the hardware uses this to communicate info to the
    // other core. We have code in place to tell PRD to analyze the other core
    // if it sees this bit. The problem is that if PRD handles the recoverable
    // error on the other core first, we'll need to manually clear this bit so
    // we don't get an errant attention. Therefore, we'll just blindly clear it
    // in the Hostboot post analysis. Note that this is not necessary for
	// EQ_CORE_FIR[57] since that is a core unit checkstop case and the entire
	// fused core pair will be masked off (see below).
    ExtensibleChip* neighborCore = getNeighborCore(i_chip);
    if (nullptr != neighborCore)
    {
        // Must do a RMW to the WOF register.
        auto wof = neighborCore->getRegister("EQ_CORE_FIR_WOF");
        if (SUCCESS == wof->Read() && wof->IsBitSet(56))
        {
            wof->ClearBit(56);
            wof->Write();
        }
    }

    #ifdef __HOSTBOOT_RUNTIME
    if ( io_sc.service_data->isProcCoreCS() )
    {
        maskIfCoreCs(i_chip);
        if (neighborCore != nullptr)
        {
            maskIfCoreCs(neighborCore);
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

} // end namespace p10_core

} // end namespace PRDF
