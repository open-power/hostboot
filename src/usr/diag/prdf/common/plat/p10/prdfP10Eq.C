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
int32_t coreUcsSummary( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc )
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
PRDF_PLUGIN_DEFINE( p10_eq, coreUcsSummary );

} // namespace p10_eq

} // namespace PRDF
