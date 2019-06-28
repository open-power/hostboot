/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_mss_power_cleanup.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>

#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>

#include    <config.h>
/* FIXME RTC: 210975
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <p9_mss_power_cleanup.H>
*/

#ifdef CONFIG_NVDIMM
// NVDIMM support
#include    <isteps/nvdimm/nvdimm.H>
#endif

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

namespace ISTEP_14
{
void* call_mss_power_cleanup (void *io_pArgs)
{
    IStepError  l_stepError;
/* FIXME RTC: 210975
    errlHndl_t  l_err  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_power_cleanup entry" );

    TARGETING::Target* l_sys = nullptr;
    TARGETING::targetService().getTopLevelTarget( l_sys );
    assert(l_sys, "call_mss_power_cleanup: no TopLevelTarget");
    uint8_t l_mpipl = l_sys->getAttr<ATTR_IS_MPIPL_HB>();
    if (!l_mpipl)
    {
        TARGETING::TargetHandleList l_mcbistTargetList;
        getAllChiplets(l_mcbistTargetList, TYPE_MCBIST);

        for (const auto & l_target : l_mcbistTargetList)
        {
            // Dump current run on target
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running mss_power_cleanup HWP on "
                    "target HUID %.8X",
                    TARGETING::get_huid(l_target));

            fapi2::Target <fapi2::TARGET_TYPE_MCBIST> l_fapi_target
                (l_target);

            //  call the HWP with each fapi2::Target
            FAPI_INVOKE_HWP(l_err, p9_mss_power_cleanup, l_fapi_target);

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X: mss_power_cleanup HWP returns error",
                          l_err->reasonCode());

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_target).addToLog(l_err);

                // Create IStep error log and cross reference to error that
                // occurred
                l_stepError.addErrorDetails( l_err );

                // Commit Error
                errlCommit( l_err, HWPF_COMP_ID );
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS :  mss_power_cleanup HWP( )" );
            }
        }
    }

#ifdef CONFIG_NVDIMM
    TARGETING::TargetHandleList l_procList;
    getAllChips(l_procList, TARGETING::TYPE_PROC, false);
    TARGETING::ATTR_MODEL_type l_chipModel =
            l_procList[0]->getAttr<TARGETING::ATTR_MODEL>();

    if(l_chipModel == TARGETING::MODEL_NIMBUS)
    {
        // Check for any NVDIMMs after the mss_power_cleanup
        TARGETING::TargetHandleList l_dimmTargetList;
        TARGETING::TargetHandleList l_nvdimmTargetList;
        getAllLogicalCards(l_dimmTargetList, TYPE_DIMM);

        // Walk the dimm list and collect all the nvdimm targets
        for (auto const l_dimm : l_dimmTargetList)
        {
            if (TARGETING::isNVDIMM(l_dimm))
            {
                l_nvdimmTargetList.push_back(l_dimm);
            }
        }

        // Run the nvdimm management function if the list is not empty
        if (!l_nvdimmTargetList.empty()){
            NVDIMM::nvdimm_restore(l_nvdimmTargetList);
        }
    }
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_power_cleanup exit" );

*/
    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

};
