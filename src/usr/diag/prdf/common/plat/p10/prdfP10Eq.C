/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10Eq.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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

#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace p10_eq
{

/**
 * @brief  Plugin function for handling the core UCS summary bit
 * @param  i_chip    EQ chip.
 * @param  io_sc     The step code data struct.
 * @return Return code from analysis of the UCS. SUCCESS if no UCS found.
 */
int32_t analyzeUcs( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    // Check the EQ_CHIPLET_UCS_FIR for which core has a UCS
    auto fir = i_chip->getRegister("EQ_CHIPLET_UCS_FIR");
    auto msk = i_chip->getRegister("EQ_CHIPLET_UCS_FIR_MASK");

    if ( SUCCESS == (fir->Read() | msk->Read()) )
    {
        // NOTE: If analysis fails on one core, check the other cores.

        // Bit 5 = Core 0
        if ( fir->IsBitSet(5) && !msk->IsBitSet(5) )
        {
            ExtensibleChip * core = getConnectedChild( i_chip, TYPE_CORE, 0 );
            if (SUCCESS == core->Analyze(io_sc, UNIT_CS))
                return SUCCESS;
        }

        // Bit 6 = Core 1
        if ( fir->IsBitSet(6) && !msk->IsBitSet(6) )
        {
            ExtensibleChip * core = getConnectedChild( i_chip, TYPE_CORE, 1 );
            if (SUCCESS == core->Analyze(io_sc, UNIT_CS))
                return SUCCESS;
        }

        // Bit 7 = Core 2
        if ( fir->IsBitSet(7) && !msk->IsBitSet(7) )
        {
            ExtensibleChip * core = getConnectedChild( i_chip, TYPE_CORE, 2 );
            if (SUCCESS == core->Analyze(io_sc, UNIT_CS))
                return SUCCESS;
        }

        // Bit 8 = Core 3
        if ( fir->IsBitSet(8) && !msk->IsBitSet(8) )
        {
            ExtensibleChip * core = getConnectedChild( i_chip, TYPE_CORE, 3 );
            if (SUCCESS == core->Analyze(io_sc, UNIT_CS))
                return SUCCESS;
        }
    }

    return PRD_SCAN_COMM_REGISTER_ZERO; // default if nothing found
}
PRDF_PLUGIN_DEFINE( p10_eq, analyzeUcs );

/**
 * @brief  Plugin function for recoverable analysis to the core and then to
 *         mask the EQ_CORE_FIR off at the EQ chiplet level if at threshold.
 * @param  i_chip    An EQ chip.
 * @param  io_sc     The step code data struct.
 * @param  i_corePos The position of the analyzed core.
 * @return SUCCESS if analysis to core completes, else the failed return code
 *         from analysis.
 */
int32_t __analyzeCoreFir( ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & io_sc, uint8_t i_corePos )
{
    #define PRDF_FUNC "[p10_eq::__analyzeCoreFir] "

    int32_t o_rc = SUCCESS;

    // First, analyze to the core. If analysis is not successful, just return
    // the failed return code.
    ExtensibleChip * core = getConnectedChild( i_chip, TYPE_CORE, i_corePos );
    o_rc = core->Analyze( io_sc, RECOVERABLE );
    if ( SUCCESS != o_rc )
    {
        PRDF_TRAC(PRDF_FUNC "Analysis failed to core 0x%08x", core->getHuid());
        return o_rc;
    }

    // Note that we cannot set the mask of recoverable bits that have reached
    // threshold in the EQ_CORE_FIR. Instead, we will mask the core off at the
    // EQ_CHIPLET_RE_FIR level here.

    #ifdef __HOSTBOOT_MODULE

    // Mask and clear EQ_CORE_FIR recoverable attentions.
    if (RECOVERABLE == io_sc.service_data->getPrimaryAttnType())
    {
        if (io_sc.service_data->IsAtThreshold())
        {
            // We can't mask recoverable errors in the CORE_FIR like we do on
            // all of the other FIRs because it will cause core recovery to
            // hang. Therefore, we will mask recoverable attentions for the
            // entire FIR (at threshold).
            auto chipletMask = i_chip->getRegister("EQ_CHIPLET_RE_FIR_MASK");

            if ( SUCCESS == chipletMask->Read() )
            {
                // EQ_CHIPLET_RE_FIR_MASK[5:8] is for the four attached cores.
                // In fused core mode, any other FIR bits that fire in a masked
                // core will trigger EQ_CORE_FIR_WOF[56] in the neighbor core.
                // To prevent the unexpected attentions, we will need to mask
                // off both cores in the fused core pair.
                for (const auto& c : {core, getNeighborCore(core)})
                {
                    if (nullptr == c) continue; // in case neighbor core is null

                    chipletMask->SetBit(5 + (c->getPos() % MAX_EC_PER_EQ));
                }

                if ( SUCCESS != chipletMask->Write() )
                {
                    PRDF_ERR(PRDF_FUNC "Failed to write EQ_CHIPLET_RE_FIR_MASK "
                             "on 0x%08x", i_chip->getHuid());
                }
            }
            else
            {
                PRDF_ERR(PRDF_FUNC "Failed to read EQ_CHIPLET_RE_FIR_MASK on "
                         "0x%08x", i_chip->getHuid());
            }
        }

        // If there is a recoverable attention on a core in fused core mode,
        // EQ_CORE_FIR_WOF[56] will be set by hardware on the other core in the
        // core pair. If this bit is left on, PHYP will be unable to put the
        // core to sleep, which is a small hit to power performance. Therefore,
        // we need to ensure this bit is clear. Note that it is possible the
        // rule code will clear it. So check if it is set before writing again.
        auto neighbor = getNeighborCore(core);
        if (nullptr != neighbor)
        {
            auto wof = neighbor->getRegister("EQ_CORE_FIR_WOF");
            if (SUCCESS == wof->Read() && wof->IsBitSet(56))
            {
                wof->ClearBit(56);
                wof->Write();
            }
        }
    }

    #endif // __HOSTBOOT_MODULE

    return o_rc;

    #undef PRDF_FUNC
}


#define PLUGIN_ANALYZE_CORE_FIR( POS ) \
int32_t analyzeCoreFir_##POS( ExtensibleChip * i_chip, \
                              STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return __analyzeCoreFir( i_chip, io_sc, POS ); \
} \
PRDF_PLUGIN_DEFINE( p10_eq, analyzeCoreFir_##POS );

PLUGIN_ANALYZE_CORE_FIR(0);
PLUGIN_ANALYZE_CORE_FIR(1);
PLUGIN_ANALYZE_CORE_FIR(2);
PLUGIN_ANALYZE_CORE_FIR(3);

} // namespace p10_eq

} // namespace PRDF
