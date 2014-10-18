/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfPllUtils.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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

/** @file prdfPllUtils.C */

#include <prdfPllUtils.H>

#include <prdfPlatServices.H>
#include <prdfTrace.H>
#include <prdfGlobal.H>
#include <UtilHash.H>
#include <iipServiceDataCollector.h>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace PLL
{

uint32_t getIoOscPos( ExtensibleChip * i_chip,
                      STEP_CODE_DATA_STRUCT & io_sc)
{
    #define PRDF_FUNC "[PLL::getIoOscPos] "
    uint32_t o_oscPos = MAX_PCIE_OSC_PER_NODE;

    do
    {
        int32_t rc = SUCCESS;

        SCAN_COMM_REGISTER_CLASS * pcieOscSwitchReg =
                i_chip->getRegister("PCIE_OSC_SWITCH");

        rc = pcieOscSwitchReg->Read();
        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC"PCIE_OSC_SWITCH read failed"
                     "for 0x%08x", i_chip->GetId());
            break;
        }

        // [ 16 ] == 1    ( OSC 0 is active )
        // [ 16 ] == 0    ( OSC 1 is active )
        if(pcieOscSwitchReg->IsBitSet(16))
        {
            o_oscPos = 0;
        }
        else
        {
            o_oscPos = 1;
        }

    } while(0);

    return o_oscPos;

    #undef PRDF_FUNC
}

} // namespace PLL

} // end namespace PRDF

