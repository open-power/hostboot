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
#include <arch/magic.H>

// Trace
#include <trace/interface.H>

// Initservice
#include <initservice/taskargs.H>
#include <initservice/isteps_trace.H>

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

// Targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/trace.H>
#include <targeting/common/mfgFlagAccessors.H>

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

typedef std::map<ATTR_HUID_type, ATTR_IOHS_LINK_TRAIN_type > IohsHuidAttrMap_t;

void fillAttrMap (IohsHuidAttrMap_t& o_map)
{
    // IOHS buses
    TargetHandleList l_buses;
    getAllChiplets(l_buses, TYPE_IOHS);
    ATTR_IOHS_CONFIG_MODE_type l_configMode;

    for (const auto& l_bus : l_buses)
    {
        // Only care about X and A config mode
        l_configMode = l_bus->getAttr<ATTR_IOHS_CONFIG_MODE>();

        if ((l_configMode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX) ||
            (l_configMode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA))
        {
            o_map[get_huid(l_bus)] = l_bus->getAttr<ATTR_IOHS_LINK_TRAIN>();
        }
    }
}


void calloutBUS(const TargetHandle_t i_proc,
                const IohsHuidAttrMap_t& i_attrMapBeforeHWP,
                errlHndl_t& io_errl)
{
    TargetHandleList l_buses;
    getChildChiplets(l_buses, i_proc, TYPE_IOHS);

    for (const auto& l_bus : l_buses)
    {
        auto l_trainVal = l_bus->getAttr<ATTR_IOHS_LINK_TRAIN>();
        int l_trainValBefore = -1;

        auto l_itr = i_attrMapBeforeHWP.find(get_huid(l_bus));
        if (l_itr != i_attrMapBeforeHWP.end())
        {
            l_trainValBefore = l_itr->second;
        }

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "calloutBUS: HUID=0x%x BeforeTrainVal=0x%x CurrTrainVal=0x%x",
                  get_huid(l_bus),
                  l_trainValBefore,
                  l_trainVal);

        if (l_trainVal == l_trainValBefore)
        {
            // This IOHS BUS link is fine. Value is as exepected after running HWP
            continue;
        }

        // Get the iohs paths
        const auto l_iohsPath = l_bus->getAttr<ATTR_PHYS_PATH>();
        const auto l_peerPath = l_bus->getAttr<ATTR_PEER_PATH>();

        // Set the bus type
        const auto l_configMode = l_bus->getAttr<ATTR_IOHS_CONFIG_MODE>();
        HWAS::busTypeEnum l_busType = HWAS::FSI_BUS_TYPE;
        if (l_configMode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX)
        {
            l_busType = X_BUS_TYPE;
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "calloutBUS: bustype=%d",l_busType);
        }
        else if (l_configMode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA)
        {
            l_busType = A_BUS_TYPE;
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "calloutBUS: bustype=%d",l_busType);
        }
        else
        {
            // Only callout X/A bus type
            continue;
        }

// @todo RTC:256842 Everest support for half links
#if 0
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
#endif

    }

}


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

    //Save off the state of ATTR_IOHS_LINK_TRAIN
    IohsHuidAttrMap_t l_attrMapBeforeHWP;
    fillAttrMap(l_attrMapBeforeHWP);

    // Loop through all processors including master
    for (const auto & l_cpu_target: l_cpuTargetList)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_target(l_cpu_target);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "Running p10_fabric_iovalid HWP on processor target 0x%.8X",
                  get_huid(l_cpu_target));

        if (TARGETING::isSMPWrapConfig())
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
            for (auto l_rc : l_fapiRcs)
            {
                errlHndl_t l_tempErr = rcToErrl(l_rc);
                if (l_tempErr)
                {
                    l_tempErr->plid(l_errl->plid());

                    // capture the target data in the elog
                    ErrlUserDetailsTarget(l_cpu_target).addToLog(l_tempErr);

                    // callout any IOHS buses we need to
                    calloutBUS(l_cpu_target,
                               l_attrMapBeforeHWP,
                               l_tempErr);

                    // save the error
                    captureError(l_tempErr,
                                 l_StepError,
                                 HWPF_COMP_ID,
                                 l_cpu_target);
                }
            }
        }
        else
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

            //@FIXME-RTC:254475-Remove once this works everywhere
            if( MAGIC_INST_CHECK_FEATURE(MAGIC_FEATURE__IGNORESMPFAIL) )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "WORKAROUND> Ignoring error for now - p10_fabric_iovalid" );
                l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                errlCommit( l_errl, HWPF_COMP_ID );
            }
            else
            {
                captureError(l_errl, l_StepError, HWPF_COMP_ID, l_cpu_target);
            }
        }
    } // end of going through all processors

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_proc_fabric_iovalid exit");

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

} // end namespace
