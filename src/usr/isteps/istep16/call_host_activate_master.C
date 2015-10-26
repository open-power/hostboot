/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep16/call_host_activate_master.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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

#include    <intr/interrupt.H>
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
    //@TODO RTC:133832 call p9_sbe_trigger_stop15.C HWP
    //@TODO RTC:133832 call p9_block_wakeup_intr.C HWP
void* call_host_activate_master (void *io_pArgs)
{
    IStepError  l_stepError;
#if 0

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_activate_master entry" );

    errlHndl_t  l_errl  =   NULL;

    // @@@@@    CUSTOM BLOCK:   @@@@@

    do  {

        // find the master core, i.e. the one we are running on
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_host_activate_master: Find master core: " );

        const TARGETING::Target*  l_masterCore  = getMasterCore( );
        assert( l_masterCore != NULL );

        TARGETING::Target* l_cpu_target = const_cast<TARGETING::Target *>
                                          ( getParentChip( l_masterCore ) );

        //@TODO RTC:133832
        // Cast OUR type of target to a FAPI type of target.
        //const fapi::Target l_fapi_cpu_target( TARGET_TYPE_PROC_CHIP,
        //                   (const_cast<TARGETING::Target*> (l_cpu_target)) );

        // Pass in Master EX target
        const TARGETING::Target* l_masterEx = getExChiplet(l_masterCore);
        assert(l_masterEx != NULL );

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_host_activate_master: call proc_prep_master_winkle. "
                   "Target HUID %.8X",
                    TARGETING::get_huid(l_masterEx));

        //@TODO RTC:133832
        // cast OUR type of target to a FAPI type of target.
        //const fapi::Target l_fapi_ex_target( TARGET_TYPE_EX_CHIPLET,
        //                   (const_cast<TARGETING::Target*> (l_masterEx)) );

        //  call the HWP with each fapi::Target
        //FAPI_INVOKE_HWP( l_errl,
        //                 proc_prep_master_winkle,
        //                 l_fapi_ex_target,
        //                 true  );
        if ( l_errl )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "proc_prep_master_winkle ERROR : Returning errorlog, reason=0x%x",
                l_errl->reasonCode() );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_masterEx).addToLog( l_errl );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "proc_prep_master_winkle SUCCESS"  );
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

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "draining interrupt Q");
        INTR::drainQueue();


        // Call p8_block_wakeup_intr to prevent stray interrupts from
        // popping core out of winkle before SBE sees it.

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_host_activated_master: call p8_block_wakeup_intr(SET) "
                   "Target HUID %.8x",
                   TARGETING::get_huid(l_masterEx) );

        //@TODO RTC:133832
        //FAPI_INVOKE_HWP( l_errl,
        //                 p8_block_wakeup_intr,
        //                 l_fapi_ex_target,
        //                 BLKWKUP_SET );

        if ( l_errl )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "p8_block_wakeup_intr ERROR : Returning errorlog, reason=0x%x",
                l_errl->reasonCode() );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_masterEx).addToLog( l_errl );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "p8_block_wakeup_intr SUCCESS"  );
        }

        // Clear special wakeup
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Disable special wakeup on master core");

        //@TODO RTC:133832
        /*
        FAPI_INVOKE_HWP(l_errl, p8_cpu_special_wakeup,
                        l_fapi_ex_target,
                        SPCWKUP_DISABLE,
                        HOST);
        */

        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "Disable p8_cpu_special_wakeup ERROR : Returning errorlog,"
            " reason=0x%x",
                l_errl->reasonCode() );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_masterEx).addToLog( l_errl );

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

        int l_rc    =   cpu_master_winkle( );
        if ( l_rc )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : failed to winkle master, rc=0x%x",
                      l_rc  );
            /*@
             * @errortype
             * @reasoncode  ISTEP_FAIL_MASTER_WINKLE_RC
             * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid    ISTEP_HOST_ACTIVATE_MASTER
             * @userdata1   return code from cpu_master_winkle
             *
             * @devdesc p8_pore_gen_cpureg returned an error when
             *          attempting to change a reg value in the PORE image.
             */
            l_errl =
            new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    ISTEP_HOST_ACTIVATE_MASTER,
                                    ISTEP_FAIL_MASTER_WINKLE_RC,
                                    l_rc  );
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
                    TARGETING::get_huid(l_cpu_target) );

        //  call the HWP with each fapi::Target
        bool l_sbeIntrServiceActive = false;
        //@TODO RTC:133832
/*        FAPI_INVOKE_HWP( l_errl,
                         proc_stop_deadman_timer,
                         l_fapi_cpu_target,
                         l_sbeIntrServiceActive  );
*/
        if ( l_errl )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "proc_stop_deadman_timer ERROR : "
                       "Returning errorlog, reason=0x%x",
                       l_errl->reasonCode() );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_cpu_target).addToLog( l_errl );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "proc_prep_master_winkle SUCCESS"  );
        }
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);
        sys->setAttr<ATTR_SBE_MASTER_INTR_SERVICE_ENABLED>
                                                    (l_sbeIntrServiceActive);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Enable special wakeup on master core");

        //@TODO RTC:133832
        /*
        FAPI_INVOKE_HWP(l_errl, p8_cpu_special_wakeup,
                        l_fapi_ex_target,
                        SPCWKUP_ENABLE,
                        HOST);
*/
        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "Enable p8_cpu_special_wakeup ERROR : Returning errorlog, "
            "reason=0x%x",
                l_errl->reasonCode() );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_masterEx).addToLog( l_errl );

            break;
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Enable special wakeup on master core SUCCESS");
        }

    }   while ( 0 );

    // @@@@@    END CUSTOM BLOCK:   @@@@@
    if( l_errl )
    {
        // Create IStep error log and cross reference error that occurred
        l_stepError.addErrorDetails( l_errl );

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_activate_master exit" );
#endif
    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();

}



};
