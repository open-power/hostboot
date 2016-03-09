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

#include <errl/errlentry.H>
#include    <stdint.h>
#include    <errno.h>
#include    <config.h>
#include    <initservice/initserviceif.H>
#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <initservice/isteps_trace.H>
#include    <initservice/istepdispatcherif.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <arch/pirformat.H>
#include    <console/consoleif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/namedtarget.H>
#include    <targeting/attrsync.H>
#include    <runtime/runtime.H>

#include    <sys/task.h>
#include    <sys/misc.h>

#include <util/misc.H>

using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;


namespace ISTEP_16
{
void* call_host_activate_slave_cores (void *io_pArgs)
{
    IStepError  l_stepError;
#if 0
    errlHndl_t  l_timeout_errl  =   NULL;
    errlHndl_t  l_errl          =   NULL;


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_activate_slave_cores entry" );

    // @@@@@    CUSTOM BLOCK:   @@@@@

    uint64_t l_masterCoreID = task_getcpuid() & ~7;

    TargetHandleList l_cores;
    getAllChiplets(l_cores, TYPE_CORE);

    for(TargetHandleList::const_iterator
        l_core = l_cores.begin();
        l_core != l_cores.end();
        ++l_core)
    {
        ConstTargetHandle_t l_processor = getParentChip(*l_core);

        CHIP_UNIT_ATTR l_coreId =
                (*l_core)->getAttr<TARGETING::ATTR_CHIP_UNIT>();
        FABRIC_GROUP_ID_ATTR l_logicalNodeId =
          l_processor->getAttr<TARGETING::ATTR_FABRIC_GROUP_ID>();
        FABRIC_CHIP_ID_ATTR l_chipId =
          l_processor->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);
        assert( sys != NULL );
        uint64_t en_threads = sys->getAttr<ATTR_ENABLED_THREADS>();

        uint64_t pir = PIR_t(l_logicalNodeId, l_chipId, l_coreId).word;

        if (pir != l_masterCoreID)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "call_host_activate_slave_cores: Waking %x",
                       pir );

            // Get EX FAPI target
            TARGETING::TargetHandleList targetList;
            getParentAffinityTargets(targetList,
                                     (*l_core),
                                     TARGETING::CLASS_UNIT,
                                     TARGETING::TYPE_EX);


            // verify the list has one entry, see SW272212.
            if( targetList.size() == 1 )
            {
                TARGETING::Target* l_ex = targetList[0];
                //@TODO RTC:133832
                //const fapi::Target l_fapi_ex_target( TARGET_TYPE_EX_CHIPLET,
                //        const_cast<TARGETING::Target*>(l_ex) );

                int rc = cpu_start_core(pir,en_threads);

                // Handle time out error
                if (-ETIME == rc)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "call_host_activate_slave_cores: "
                            "Time out rc from kernel %d on core %x",
                            rc,
                            pir);

                    //@TODO RTC:133832
                    //FAPI_INVOKE_HWP( l_timeout_errl, proc_check_slw_done,
                    //l_fapi_ex_target);
                    if (l_timeout_errl)
                    {
                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                "ERROR : proc_check_slw_done" );
                        // Add chip target info
                        ErrlUserDetailsTarget(l_processor).addToLog(
                                                               l_timeout_errl );
                        // Create IStep error log
                        l_stepError.addErrorDetails(l_timeout_errl);
                        // Commit error
                        errlCommit( l_timeout_errl, HWPF_COMP_ID );
                        break;
                    }
                    else
                    {
                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                "SUCCESS : proc_check_slw_done - "
                                 "SLW is in clean state");
                    }
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
                else //Core out of winkle sucessfully, issue SPWU for PRD
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                            "Running p8_cpu_special_wakeup (ENABLE)"
                            " EX target HUID %.8X",
                            TARGETING::get_huid(l_ex));

                    // Enable special wakeup on core
                    //@TODO RTC:133832
                    /*FAPI_INVOKE_HWP( l_errl,
                            p8_cpu_special_wakeup,
                            l_fapi_ex_target,
                            SPCWKUP_ENABLE,
                            HOST);
                    */
                    if( l_errl )
                    {
                        ErrlUserDetailsTarget(l_ex).addToLog( l_errl );

                        // Create IStep error log and cross ref error that
                        // occurred
                        l_stepError.addErrorDetails( l_errl );

                        // Commit Error
                        errlCommit( l_errl, HWPF_COMP_ID );

                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                "ERROR : enable p8_cpu_special_wakeup, "
                                "PLID=0x%x", l_errl->plid()  );
                    }
                    else
                    {
                        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                                "SUCCESS: enable p8_cpu_special_wakeup");
                    }
                }
            }
            else
            {
                // wrong number of targets in the list, create an error log
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "ERROR: call to getParentAffinityTarget "
                            "returned %d instead of 1", targetList.size() );
                /*@
                 * @errortype
                 * @reasoncode  RC_INCORRECT_TARGET_COUNT
                 * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid    MOD_HOST_ACTIVATE_SLAVE_CORES
                 * @userdata1   PIR of failing core.
                 * @userdata2   number of targets returned
                 *
                 * @devdesc     Call to getParentAffinityTarget requesting
                 *              the number of EX chips with parent affinity
                 *              to a core, returned an incorrect vector size,
                 *              the expected size is 1.
                 *
                 * @custdec     A problem occurred during the IPL of the system.
                 *
                 */
                l_errl =
                    new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            MOD_HOST_ACTIVATE_SLAVE_CORES,
                            RC_INCORRECT_TARGET_COUNT,
                            pir,
                            targetList.size(), true);
                // Create IStep error log and cross ref error that occurred
                l_stepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );
            }
        }
    }

    if( l_stepError.isNull() )
    {
        // Call proc_post_winkle
        TARGETING::TargetHandleList l_procTargetList;
        getAllChips(l_procTargetList, TYPE_PROC);

        // Done activate all master/slave cores.
        // Run post winkle check on all EX targets, one proc at a time.
        for (TargetHandleList::const_iterator l_procIter =
             l_procTargetList.begin();
             l_procIter != l_procTargetList.end();
             ++l_procIter)
        {
            const TARGETING::Target* l_pChipTarget = *l_procIter;
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Running proc_post_winkle on chip HUID %.8X",
                TARGETING::get_huid(l_pChipTarget));

            // Get EX list under this proc
            TARGETING::TargetHandleList l_exList;
            getChildChiplets( l_exList, l_pChipTarget, TYPE_EX );

            for (TargetHandleList::const_iterator
                l_exIter = l_exList.begin();
                l_exIter != l_exList.end();
                ++l_exIter)
            {
                const TARGETING::Target * l_exTarget = *l_exIter;

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Running proc_post_winkle on EX target HUID %.8X",
                TARGETING::get_huid(l_exTarget));

                // cast OUR type of target to a FAPI type of target.
                //@TODO RTC:133832
                /*
                fapi::Target l_fapi_ex_target( TARGET_TYPE_EX_CHIPLET,
                         (const_cast<TARGETING::Target*>(l_exTarget)) );

                //  call the HWP with each fapi::Target
                FAPI_INVOKE_HWP( l_errl,
                                 proc_post_winkle,
                                 l_fapi_ex_target);
                */
                if ( l_errl )
                {
                    // capture the target data in the elog
                    ErrlUserDetailsTarget(l_pChipTarget).addToLog( l_errl );

                    // Create IStep error log and cross ref error that occurred
                    l_stepError.addErrorDetails( l_errl );

                    // Commit Error
                    errlCommit( l_errl, HWPF_COMP_ID );

                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                             "ERROR : proc_post_winkle, PLID=0x%x",
                             l_errl->plid()  );
                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "SUCCESS : proc_post_winkle" );
                }
            }

        }   // end for

    }   // end if

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
#endif
    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

};
