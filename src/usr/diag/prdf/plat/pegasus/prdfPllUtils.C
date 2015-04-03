/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfPllUtils.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

#include <prdfExtensibleChip.H>
#include <prdfTrace.H>
#include <UtilHash.H>
#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
#include <prdfPciOscSwitchDomain.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace Proc
{

/**
 * @brief queries if there is PCI osc error.
 * @param   i_procChip       P8 proc chip.
 * @param   o_pciOscError    PCI Osc error status.
 * @return  SUCCESS if query is successful FAIL otherwise.
 */
int32_t  queryPciOscErr( ExtensibleChip * i_procChip,
                         bool & o_pciClkSwitchOver )
{
    #define PRDF_FUNC "[Proc::queryPciOscErr] "

    int32_t o_rc = FAIL;
    o_pciClkSwitchOver = false;
    PRDF_TRAC( PRDF_FUNC "PCI Osc Switch over not expected during hostboot "
               "HUID: 0x%08x", i_procChip->GetId() );

    return o_rc;
    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE_NS( NaplesProc, Proc, queryPciOscErr );
PRDF_PLUGIN_DEFINE_NS( MuranoVeniceProc, Proc, queryPciOscErr );

//------------------------------------------------------------------------------

/**
 * @brief analyzes PCI osc error and switchover.
 * @param   i_procChip       P8 proc chip.
 * @param   PciOscConnList   PCI osc error data.
 * @return  SUCCESS if analysis is successful FAIL otherwise.
 */
int32_t analyzePciClkFailover( ExtensibleChip * i_procChip,
                               PciOscConnList & o_pciOscSwitchData )
{
    #define PRDF_FUNC "Proc::analyzePciClkFailover "

    int32_t o_rc = FAIL;
    PRDF_TRAC( PRDF_FUNC "PCI Osc Switch over not expected during hostboot "
               "HUID: 0x%08x", i_procChip->GetId() );
    return o_rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE_NS( NaplesProc, Proc, analyzePciClkFailover );
PRDF_PLUGIN_DEFINE_NS( MuranoVeniceProc, Proc, analyzePciClkFailover );

//------------------------------------------------------------------------------

/**
 * @brief   cleans up PCI osc error data.
 * @param   i_chip           P8 proc chip.
 * @param   i_faultyOscPos   position of faulty PCI osc.
 * @return  SUCCESS if cleanup is successful FAIL otherwise.
 */
int32_t clearPciOscFailOver( ExtensibleChip * i_procChip,
                             PciOscConnList & i_oscData )
{
    #define PRDF_FUNC "Proc::clearPciOscFailOver "

    int32_t o_rc = FAIL;
    PRDF_TRAC( PRDF_FUNC "PCI Osc Switch over not expected during hostboot "
               "HUID: 0x%08x", i_procChip->GetId() );
    return o_rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE_NS( NaplesProc, Proc, clearPciOscFailOver );
PRDF_PLUGIN_DEFINE_NS( MuranoVeniceProc, Proc, clearPciOscFailOver );

} // end namespace Proc

} // end namespace PRDF

