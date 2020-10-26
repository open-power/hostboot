/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10Eq.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_chip    EQ chip.
 * @param  io_sc     The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_chip,
                      STEP_CODE_DATA_STRUCT & io_sc )
{
    #ifdef __HOSTBOOT_RUNTIME
    int32_t l_rc = restartTraceArray(i_chip->getTrgt());
    if (SUCCESS != l_rc)
    {
        PRDF_ERR( "[EQ PostAnalysis HUID: 0x%08x RestartTraceArray failed",
                  i_chip->GetId());
    }
    #endif
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( p10_eq, PostAnalysis );

/**
 * @brief  Plugin function for handling the core UCS summary bit
 * @param  i_chip    EQ chip.
 * @param  io_sc     The step code data struct.
 * @return Return code from analysis of the UCS. SUCCESS if no UCS found.
 */
int32_t coreUcsSummary( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc )
{
    int32_t o_rc = SUCCESS;

    // Check the EQ_CHIPLET_UCS_FIR for which core has a UCS
    SCAN_COMM_REGISTER_CLASS * fir = i_chip->getRegister("EQ_CHIPLET_UCS_FIR");

    if ( SUCCESS == fir->Read() )
    {
        // Bits 5:8 correspond to cores 0:3 respectively.
        // Bit 5 = Core 0
        if ( fir->IsBitSet(5) )
        {
            ExtensibleChip * core = getConnectedChild( i_chip, TYPE_CORE, 0 );
            o_rc = core->Analyze( io_sc, UNIT_CS );
        }
        // Bit 6 = Core 1
        else if ( fir->IsBitSet(6) )
        {
            ExtensibleChip * core = getConnectedChild( i_chip, TYPE_CORE, 1 );
            o_rc = core->Analyze( io_sc, UNIT_CS );
        }
        // Bit 7 = Core 2
        else if ( fir->IsBitSet(7) )
        {
            ExtensibleChip * core = getConnectedChild( i_chip, TYPE_CORE, 2 );
            o_rc = core->Analyze( io_sc, UNIT_CS );
        }
        // Bit 8 = Core 3
        else if ( fir->IsBitSet(8) )
        {
            ExtensibleChip * core = getConnectedChild( i_chip, TYPE_CORE, 3 );
            o_rc = core->Analyze( io_sc, UNIT_CS );
        }
    }

    return o_rc;
}
PRDF_PLUGIN_DEFINE( p10_eq, coreUcsSummary );

} // namespace p10_eq

} // namespace PRDF
