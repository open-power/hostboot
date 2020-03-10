/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_proc_fabric_iovalid.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/**
 *  @file call_proc_fabric_iovalid.C
 *
 *  Support file for IStep: proc_fabric_iovalid
 *   Lower functional fences on local SMP
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

// Standard library
#include <stdint.h>
#include <map>

// Trace
#include <trace/interface.H>

// Initservice
#include <initservice/taskargs.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>

// Error log
#include <errl/errlentry.H>
#include <errl/errludtarget.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>

// IStep-related
#include <isteps/hwpisteperror.H>
#include <istepHelperFuncs.H>

// HWAS
#include <hwas/common/deconfigGard.H>
#include <hwas/common/hwasCommon.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/trace.H>

// FAPI
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>

// HWP
#include <p10_fabric_iovalid.H>

namespace ISTEP_09
{

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;
using namespace HWAS;

#if 0 // TODO RTC 246933: Reincorporate SMP wrap functionality

typedef std::map<ATTR_HUID_type, ATTR_LINK_TRAIN_type > OBUSHuidAttrMap_t;

void fillAttrMap (OBUSHuidAttrMap_t& o_map)
{
    TargetHandleList l_obuses;
    getAllChiplets(l_obuses, TYPE_OBUS);
    for (const auto& l_obus : l_obuses)
    {
        o_map[get_huid(l_obus)] = l_obus->getAttr<ATTR_LINK_TRAIN>();
    }
}

void calloutOBUS(TargetHandle_t i_proc,
                 OBUSHuidAttrMap_t& i_attrMapBeforeHWP,
                 errlHndl_t& io_errl)
{
    TargetHandleList l_obuses;
    getChildChiplets(l_obuses, i_proc, TYPE_OBUS);
    for (const auto& l_obus : l_obuses)
    {
        auto l_trainVal = l_obus->getAttr<ATTR_LINK_TRAIN>();
        int l_trainValBefore = -1;

        auto l_itr = i_attrMapBeforeHWP.find(get_huid(l_obus));
        if (l_itr != i_attrMapBeforeHWP.end())
        {
            l_trainValBefore = l_itr->second;
        }

        TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "calloutOBUS: HUID=0x%x BeforeTrainVal=0x%x CurrTrainVal=0x%x",
                  get_huid(l_obus),
                  l_trainValBefore,
                  l_trainVal);

        if (l_trainVal == l_trainValBefore)
        {
            //This OBUS link is fine. Value is as exepected after running HWP
            continue;
        }

        TargetHandleList l_smpGroupTargets;
        getChildAffinityTargets(l_smpGroupTargets,
                                l_obus,
                                CLASS_UNIT,
                                TYPE_SMPGROUP,
                                false);
        for (const auto l_smpGrp : l_smpGroupTargets)
        {
            auto l_smpGrpPos = l_smpGrp->getAttr<ATTR_REL_POS>();
            //if smpGrpPos%2==0, then ODD links are functional, callout even
            //if smpGrpPos%2==1, then even are functional, callout odd

            //In the rc vector we get back, we only get training errors for
            //odd or even links or none of links train error. However, if
            //none of the links were trained, then the OBUS target is already
            //deconfigured. Therefore, we will never get here if LINK_TRAIN_NONE
            if (((l_smpGrpPos % 2 == 0) && (l_trainVal == LINK_TRAIN_ODD_ONLY))
            || ((l_smpGrpPos % 2 == 1) && (l_trainVal == LINK_TRAIN_EVEN_ONLY)))
            {
                const auto l_smp     = l_smpGrp->getAttr<ATTR_PHYS_PATH>();
                const auto l_peerSMP = l_smpGrp->getAttr<ATTR_PEER_PATH>();
                io_errl->addBusCallout (l_smp, l_peerSMP, O_BUS_TYPE,
                        SRCI_PRIORITY_MED);
            }
        }
    }

}

#endif

void* call_proc_fabric_iovalid(void* const io_pArgs)
{
    errlHndl_t l_errl = nullptr;
    IStepError l_StepError;
    std::vector<fapi2::ReturnCode> l_fapiRcs;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_fabric_iovalid entry" );

    // get a list of all the procs in the system
    TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

#if 0 // TODO RTC 246933: Reincorporate SMP wrap functionality
    //Save off the state of ATTR_LINK_TRAIN
    OBUSHuidAttrMap_t l_attrMapBeforeHWP;
    fillAttrMap(l_attrMapBeforeHWP);
#endif

    // Loop through all processors including master
    for (const auto & l_cpu_target: l_cpuTargetList)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_target(l_cpu_target);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "Running p10_fabric_iovalid HWP on processor target 0x%.8X",
                  get_huid(l_cpu_target));

#if 0 // TODO RTC 246933: Reincorporate SMP wrap functionality
        if (INITSERVICE::isSMPWrapConfig())
        {
            const bool l_set_not_clear = true,
                       l_update_internode = true,
                       l_update_intranode = true;

            FAPI_INVOKE_HWP(l_errl, p10_fabric_iovalid,
                            l_fapi2_proc_target,
                            l_set_not_clear,
                            l_update_intranode,
                            l_update_internode,
                            l_fapiRcs);

            if ((l_errl == nullptr) && !l_fapiRcs.empty())
            {
                //if HWP did not return an error, then create a new
                //error to link all the RCs with
                /*@
                 * @errortype  ERRL_SEV_UNRECOVERABLE
                 * @moduleid   MOD_SMP_WRAP_PROC_IOVALID
                 * @reasoncode RC_LINK_TRAIN_ERRORS_FROM_HWP
                 * @userdata0  PROC HUID
                 * @userdata1  Number of RCs from HWP
                 * @devdesc    p10_fabric_iovalid HWP returned errors on odd and
                 *             even links. Creating an error to link all the
                 *             individual link RCs together
                 * @custdesc   There was an error training the SMP cables.
                 */
                l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                       MOD_SMP_WRAP_PROC_IOVALID,
                                       RC_LINK_TRAIN_ERRORS_FROM_HWP,
                                       get_huid(l_cpu_target),
                                       l_fapiRcs.size());
            }

            //Something bad happened during the hwp run
            for (const auto l_rc : l_fapiRcs)
            {
                errlHndl_t l_tempErr = rcToErrl(l_rc);
                if (l_tempErr)
                {
                    l_tempErr->plid(l_errl->plid());

                    // capture the target data in the elog
                    ErrlUserDetailsTarget(l_cpu_target).addToLog(l_tempErr);

                    //callout any buses we need to.
                    calloutOBUS(l_cpu_target, l_attrMapBeforeHWP, l_tempErr);

                    captureError(l_tempErr, l_StepError, HWPF_COMP_ID, l_cpu_target);
                }
            }
        }
        else
#endif
        {
            const bool l_set_not_clear = true,
                       l_update_internode = false,
                       l_update_intranode = true;

            // Note:
            // When this HWP gets run under HB, it should only train X PHYS, not As.
            // The HWP shouldn't fill any data into vector l_fapiRcs for X's,
            // only for A's that could be used to trigger a reconfig loop in FSP.
            // Therefore, we ignore the check for l_fapiRcs here.
            FAPI_INVOKE_HWP(l_errl, p10_fabric_iovalid,
                            l_fapi2_proc_target,
                            l_set_not_clear,
                            l_update_intranode,
                            l_update_internode,
                            l_fapiRcs);
        }

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"p10_fabric_iovalid HWP returns error for HUID 0x%.8X"
                      TRACE_ERR_FMT,
                      get_huid(l_cpu_target),
                      TRACE_ERR_ARGS(l_errl));

            captureError(l_errl, l_StepError, HWPF_COMP_ID, l_cpu_target);
        }
    } // end of going through all processors

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_proc_fabric_iovalid exit");

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

} // end namespace
