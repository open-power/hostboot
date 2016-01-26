/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep16/call_host_activate_master.C $          */
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


// Error Handling
#include    <errl/errlentry.H>
#include    <errl/errlmanager.H>
#include    <initservice/isteps_trace.H>
#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>
#include    <intr/interrupt.H>
#include    <console/consoleif.H>

//  targeting support
#include    <targeting/namedtarget.H>
#include    <targeting/attrsync.H>
#include    <fapi2/target.H>

//SBE interfacing
#include    <sbeio/sbeioif.H>
#include    <sys/misc.h>

//Import directory (EKB)
#include    <p9_block_wakeup_intr.H>
#include    <p9_cpu_special_wakeup.H>

//HWP invoker
#include    <fapi2/plat_hwp_invoker.H>

using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   p9specialWakeup;


namespace ISTEP_16
{
void* call_host_activate_master (void *io_pArgs)
{
    IStepError  l_stepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_activate_master entry" );

    errlHndl_t  l_errl  =   NULL;

    do  {
        // find the master core, i.e. the one we are running on
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_host_activate_master: Find master core: " );

        const TARGETING::Target*  l_masterCore  = getMasterCore( );
        assert( l_masterCore != NULL );

        TARGETING::Target* l_core_target = const_cast<TARGETING::Target *>
                                          ( getParentChip( l_masterCore ) );

        // Cast OUR type of target to a FAPI2 type of target.
        const fapi2::Target<fapi2::TARGET_TYPE_CORE> l_fapi2_coreTarget(
                                const_cast<TARGETING::Target*> (l_core_target));

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_host_activate_master: About to start deadman loop... "
                   "Target HUID %.8X",
                    TARGETING::get_huid(l_fapi2_coreTarget));

// @TODO RTC:147553 Enable startDeadmanLoop
//In the future possibly move default "waitTime" value to SBEIO code
//          uint64_t waitTime = 10000;
//          l_errl = SBEIO::startDeadmanLoop(waitTime);

        if ( l_errl )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "startDeadmanLoop ERROR : Returning errorlog, reason=0x%x",
                l_errl->reasonCode() );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_core_target).addToLog( l_errl );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "startDeadManLoop SUCCESS"  );
        }

        //Because of a bug in how the SBE injects the IPI used to wake
        //up the master core, need to ensure no mailbox traffic
        //or even an interrupt in the interrupt presenter
        // 1) suspend the mailbox with interrupt disable
        // 2) ensure that interrupt presenter is drained
        l_errl = MBOX::suspend(true, true);
        if (l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "call_host_activate_master ERROR : MBOX::suspend");
            break;
        }
           //@TODO RTC:137564 Support for thread-specific interrupts
//         TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "draining interrupt Q");
//         INTR::drainQueue();


        // Call p9_block_wakeup_intr to prevent stray interrupts from
        // popping core out of winkle before SBE sees it.

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_host_activated_master: call p9_block_wakeup_intr(SET) "
                   "Target HUID %.8x",
                   TARGETING::get_huid(l_fapi2_coreTarget) );

        FAPI_INVOKE_HWP( l_errl,
                        p9_block_wakeup_intr,
                        l_fapi2_coreTarget,
                        p9pmblockwkup::SET );

        if ( l_errl )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "p9_block_wakeup_intr ERROR : Returning errorlog, reason=0x%x",
                l_errl->reasonCode() );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_core_target).addToLog( l_errl );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "p9_block_wakeup_intr SUCCESS"  );
        }

        // Clear special wakeup
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Disable special wakeup on master core");

        FAPI_INVOKE_HWP(l_errl, p9_cpu_special_wakeup,
                        l_fapi2_coreTarget,
                        SPCWKUP_DISABLE,
                        HOST);


        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "Disable p9_cpu_special_wakeup ERROR : Returning errorlog,"
            " reason=0x%x",
                l_errl->reasonCode() );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_core_target).addToLog( l_errl );

            break;
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Disable special wakeup on master core SUCCESS");
        }


        //  put the master into winkle.
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_host_activate_master: put master into winkle..." );

        // Flush any lingering console traces first
        CONSOLE::flush();
        bool l_fusedCores = is_fused_mode();

        int l_rc    =   cpu_master_winkle(l_fusedCores);
        if ( l_rc )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : failed to winkle master, rc=0x%x",
                      l_rc  );
            /*@
             * @errortype
             * @reasoncode  RC_FAIL_MASTER_WINKLE
             * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid    MOD_HOST_ACTIVATE_MASTER
             * @userdata1   return code from cpu_master_winkle
             * @userdata2   Fused core indicator
             *
             * @devdesc cpu_master_winkle returned an error
             */
            l_errl =
            new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MOD_HOST_ACTIVATE_MASTER,
                                    RC_FAIL_MASTER_WINKLE,
                                    l_rc, l_fusedCores );
            break;
        }


        //  --------------------------------------------------------
        //  should return from Winkle at this point
        //  --------------------------------------------------------
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Returned from Winkle." );

        //Re-enable the mailbox
        l_errl = MBOX::resume();
        if (l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "call_host_activate_master ERROR : MBOX::resume");
            break;
        }

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Call proc_stop_deadman_timer. Target %.8X",
                    TARGETING::get_huid(l_core_target) );

// @TODO RTC:147553 Enable stopDeadmanLoop
//         l_errl = SBEIO::stopDeadmanLoop();

        if ( l_errl )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "stopDeadmanLoop ERROR : "
                       "Returning errorlog, reason=0x%x",
                       l_errl->reasonCode() );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_core_target).addToLog( l_errl );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "stopDeadmanLoop SUCCESS"  );
        }
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Enable special wakeup on master core");


        FAPI_INVOKE_HWP(l_errl, p9_cpu_special_wakeup,
                        l_fapi2_coreTarget,
                        SPCWKUP_ENABLE,
                        HOST);

        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "Enable p9_cpu_special_wakeup ERROR : Returning errorlog, "
            "reason=0x%x",
                l_errl->reasonCode() );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_core_target).addToLog( l_errl );

            break;
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Enable special wakeup on master core SUCCESS");
        }

    }   while ( 0 );

    if( l_errl )
    {
        // Create IStep error log and cross reference error that occurred
        l_stepError.addErrorDetails( l_errl );

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_activate_master exit" );
    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();

}



};
