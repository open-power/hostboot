/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep16/call_host_activate_slave_cores.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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

#include    <errl/errlentry.H>
#include    <errno.h>
#include    <initservice/isteps_trace.H>
#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <arch/pirformat.H>
#include    <console/consoleif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/namedtarget.H>
#include    <fapi2/target.H>
#include    <errl/errlmanager.H>
#include    <sys/task.h>
#include    <sys/misc.h>

#include    <fapi2/plat_hwp_invoker.H>
#include    <p9_cpu_special_wakeup.H>

using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   p9specialWakeup;

namespace ISTEP_16
{
void* call_host_activate_slave_cores (void *io_pArgs)
{
    IStepError  l_stepError;

//     errlHndl_t  l_timeout_errl  =   NULL;
    errlHndl_t  l_errl          =   NULL;


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_activate_slave_cores entry" );

    // @@@@@    CUSTOM BLOCK:   @@@@@

    uint64_t l_masterCoreID = PIR_t::coreFromPir(task_getcpuid());

    TargetHandleList l_cores;
    getAllChiplets(l_cores, TYPE_CORE);
    uint32_t l_numCores = 0;

    for(TargetHandleList::const_iterator
        l_core = l_cores.begin();
        l_core != l_cores.end();
        ++l_core)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Iterating all cores in system - "
                   "This is core: %d", l_numCores);
        l_numCores += 1;

        ConstTargetHandle_t l_processor = getParentChip(*l_core);

        CHIP_UNIT_ATTR l_coreId =
                (*l_core)->getAttr<TARGETING::ATTR_CHIP_UNIT>();
        FABRIC_GROUP_ID_ATTR l_logicalGroupId =
          l_processor->getAttr<TARGETING::ATTR_FABRIC_GROUP_ID>();
        FABRIC_CHIP_ID_ATTR l_chipId =
          l_processor->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);
        assert( sys != NULL );

        const fapi2::Target<fapi2::TARGET_TYPE_CORE> l_fapi2_coreTarget(
              const_cast<TARGETING::Target*> (*l_core));

        //Determine PIR and threads to enable for this core
        uint64_t pir = PIR_t(l_logicalGroupId, l_chipId, l_coreId).word;
        uint64_t en_threads = sys->getAttr<ATTR_ENABLED_THREADS>();
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "pir for this core is: %lx", pir);

        if (pir != l_masterCoreID)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "call_host_activate_slave_cores: Waking %x.",
                       pir );

            int rc = cpu_start_core(pir, en_threads);

            // Handle time out error
            if (-ETIME == rc)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "call_host_activate_slave_cores: "
                        "Time out rc from kernel %d on core %x",
                        rc,
                        pir);

//@TODO RTC:147376
//Spoke with Thi and he said this is not planned for awhile
//FAPI_INVOKE_HWP( l_timeout_errl, proc_check_slw_done,
//l_fapi2_ex_target);
//                 if (l_timeout_errl)
//                 {
//                     TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
//                             "ERROR : proc_check_slw_done" );
//                     // Add chip target info
//                     ErrlUserDetailsTarget(l_processor).addToLog(
//                                                             l_timeout_errl );
//                     // Create IStep error log
//                     l_stepError.addErrorDetails(l_timeout_errl);
//                     // Commit error
//                     errlCommit( l_timeout_errl, HWPF_COMP_ID );
//                     break;
//                 }
//                 else
//                 {
//                     TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
//                             "SUCCESS : proc_check_slw_done - "
//                               "SLW is in clean state");
//                 }
            }
            // Create error log
            if (0 != rc)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "call_host_activate_slave_cores: "
                        "Error from kernel %d on core %x",
                        rc,
                        pir);
                /*@
                  * @errortype
                  * @reasoncode  RC_BAD_RC
                  * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
                  * @moduleid    MOD_HOST_ACTIVATE_SLAVE_CORES
                  * @userdata1   PIR of failing core.
                  * @userdata2   rc of cpu_start_core().
                  *
                  * @devdesc Kernel returned error when trying to activate
                  *          core.
                  */
                errlHndl_t l_errl =
                    new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            MOD_HOST_ACTIVATE_SLAVE_CORES,
                            RC_BAD_RC,
                            pir,
                            rc );

                // Callout core that failed to wake up.
                l_errl->addHwCallout(*l_core,
                        HWAS::SRCI_PRIORITY_MED,
                        HWAS::DECONFIG,
                        HWAS::GARD_Predictive);

                l_stepError.addErrorDetails( l_errl );
                errlCommit( l_errl, HWPF_COMP_ID );
                break;
            }

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running p9_cpu_special_wakeup (ENABLE)"
                    " EX target HUID %.8X",
                    TARGETING::get_huid(*l_core));

            // Enable special wakeup on core
            FAPI_INVOKE_HWP( l_errl,
                    p9_cpu_special_wakeup,
                    l_fapi2_coreTarget,
                    SPCWKUP_ENABLE,
                    HOST);

            if( l_errl )
            {
                ErrlUserDetailsTarget(*l_core).addToLog( l_errl );

                // Create IStep error log and cross ref error that
                // occurred
                l_stepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR : enable p9_cpu_special_wakeup, "
                        "PLID=0x%x", l_errl->plid()  );
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "SUCCESS: enable p9_cpu_special_wakeup");
            }
        }
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@

#ifdef CONFIG_ENABLE_CHECKSTOP_ANALYSIS
    if( l_stepError.isNull() )
    {
        // update firdata inputs for OCC
        TARGETING::Target* masterproc = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(masterproc);
        l_errl = HBOCC::loadHostDataToSRAM(masterproc,
                                            PRDF::ALL_HARDWARE);
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Error returned from call to HBOCC::loadHostDataToSRAM");

            //Create IStep error log and cross reference error that occurred
            l_stepError.addErrorDetails(l_errl);

            // Commit Error
            errlCommit(l_errl, HWPF_COMP_ID);
        }
    }
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_activate_slave_cores exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

};
