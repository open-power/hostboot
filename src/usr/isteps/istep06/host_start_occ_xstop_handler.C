/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/host_start_occ_xstop_handler.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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

#include <stdint.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <kernel/vmmmgr.H>
#include <sys/mm.h>
#include <pm/pm_common.H>
#include <targeting/common/commontargeting.H>
#include <isteps/pm/occCheckstop.H>

namespace ISTEP_06
{
void* host_start_occ_xstop_handler( void *io_pArgs )
{
    ISTEP_ERROR::IStepError l_stepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "host_start_occ_xstop_handler entry" );
#ifdef CONFIG_IPLTIME_CHECKSTOP_ANALYSIS
    errlHndl_t l_errl = NULL;
    TARGETING::Target * l_sys = nullptr;
    TARGETING::targetService().getTopLevelTarget( l_sys );
    assert(l_sys != nullptr);

    TARGETING::Target* masterproc = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(masterproc);

    void* l_homerVirtAddrBase = reinterpret_cast<void*>
                                                 (VmmManager::INITIAL_MEM_SIZE);
    uint64_t l_homerPhysAddrBase = mm_virt_to_phys(l_homerVirtAddrBase);
    uint64_t l_commonPhysAddr = l_homerPhysAddrBase + VMM_HOMER_REGION_SIZE;

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "host_start_occ_xstop_handler:"
                             " l_homerPhysAddrBase=0x%x, l_commonPhysAddr=0x%x",
                             l_homerPhysAddrBase, l_commonPhysAddr);
    do
    {
        l_errl = HBPM::loadPMComplex(masterproc,
                                    l_homerPhysAddrBase,
                                    l_commonPhysAddr,
                                    HBPM::PM_LOAD,
                                    true);
        if(l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                                        "loadPMComplex failed");
            l_stepError.addErrorDetails(l_errl);
            ERRORLOG::errlCommit(l_errl, HWPF_COMP_ID);
            break;
        }

        l_errl = HBOCC::startOCCFromSRAM(masterproc);
        if(l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                                     "startOCCFromSRAM failed");
            l_stepError.addErrorDetails(l_errl);
            ERRORLOG::errlCommit(l_errl, HWPF_COMP_ID);
            break;
        }

    }while(0);
#endif
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "host_start_occ_xstop_handler exit" );

    return l_stepError.getErrorHandle();
}

};
