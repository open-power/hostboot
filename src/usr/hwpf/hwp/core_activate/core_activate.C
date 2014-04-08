/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/core_activate.C $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 *  @file core_activate.C
 *
 *  Support file for IStep: core_activate
 *   Core Activate
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <errno.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <initservice/isteps_trace.H>
#include    <initservice/istepdispatcherif.H>

#include    <hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <intr/interrupt.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/namedtarget.H>
#include    <targeting/attrsync.H>
#include    <runtime/runtime.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>
#include    <hwpf/istepreasoncodes.H>

#include    "core_activate.H"
#include    <sys/task.h>
#include    <sys/misc.h>

//  Uncomment these files as they become available:
#include    "proc_prep_master_winkle.H"
#include    "proc_stop_deadman_timer.H"
#include    "p8_set_pore_bar.H"
#include    "proc_switch_cfsim.H"
#include    "proc_switch_rec_attn.H"
#include    "cen_switch_rec_attn.H"
#include    "proc_post_winkle.H"
#include    "proc_check_slw_done.H"
#include    "p8_block_wakeup_intr.H"
#include    "p8_cpu_special_wakeup.H"

// mss_scrub support
#include    <diag/prdf/prdfMain.H>
#include <util/misc.H>

namespace   CORE_ACTIVATE
{

using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   fapi;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;



//
//  Wrapper function to call host_activate_master
//
void*    call_host_activate_master( void    *io_pArgs )
{

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_activate_master entry" );

    errlHndl_t  l_errl  =   NULL;
    IStepError  l_stepError;

    // @@@@@    CUSTOM BLOCK:   @@@@@

    do  {

        // find the master core, i.e. the one we are running on
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_host_activate_master: Find master core: " );

        const TARGETING::Target*  l_masterCore  = getMasterCore( );
        assert( l_masterCore != NULL );

        TARGETING::Target* l_cpu_target = const_cast<TARGETING::Target *>
                                          ( getParentChip( l_masterCore ) );

        // Cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_cpu_target( TARGET_TYPE_PROC_CHIP,
                           (const_cast<TARGETING::Target*> (l_cpu_target)) );

        // Pass in Master EX target
        const TARGETING::Target* l_masterEx = getExChiplet(l_masterCore);
        assert(l_masterEx != NULL );

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_host_activate_master: call proc_prep_master_winkle. "
                   "Target HUID %.8X",
                    TARGETING::get_huid(l_masterEx));

        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_ex_target( TARGET_TYPE_EX_CHIPLET,
                           (const_cast<TARGETING::Target*> (l_masterEx)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP( l_errl,
                         proc_prep_master_winkle,
                         l_fapi_ex_target,
                         true  );
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


        // Call p8_block_wakeup_intr to prevent stray interrupts from
        // popping core out of winkle before SBE sees it.

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_host_activated_master: call p8_block_wakeup_intr(SET) "
                   "Target HUID %.8x",
                   TARGETING::get_huid(l_masterEx) );

        FAPI_INVOKE_HWP( l_errl,
                         p8_block_wakeup_intr,
                         l_fapi_ex_target,
                         BLKWKUP_SET );

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

        FAPI_INVOKE_HWP(l_errl, p8_cpu_special_wakeup,
                        l_fapi_ex_target,
                        SPCWKUP_DISABLE,
                        HOST);

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

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Call proc_stop_deadman_timer. Target %.8X",
                    TARGETING::get_huid(l_cpu_target) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP( l_errl,
                         proc_stop_deadman_timer,
                         l_fapi_cpu_target  );
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

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Enable special wakeup on master core");

        FAPI_INVOKE_HWP(l_errl, p8_cpu_special_wakeup,
                        l_fapi_ex_target,
                        SPCWKUP_ENABLE,
                        HOST);

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

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();

}



//
//  Wrapper function to call host_activate_slave_cores
//
void*    call_host_activate_slave_cores( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    IStepError  l_stepError;

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
        FABRIC_NODE_ID_ATTR l_logicalNodeId =
          l_processor->getAttr<TARGETING::ATTR_FABRIC_NODE_ID>();
        FABRIC_CHIP_ID_ATTR l_chipId =
          l_processor->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);
        assert( sys != NULL );
        uint64_t en_threads = sys->getAttr<ATTR_ENABLED_THREADS>();

        uint64_t pir = INTR::PIR_t(l_logicalNodeId, l_chipId, l_coreId).word;

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
            TARGETING::Target* l_ex = targetList[0];
            const fapi::Target l_fapi_ex_target( TARGET_TYPE_EX_CHIPLET,
                                 const_cast<TARGETING::Target*>(l_ex) );

            int rc = cpu_start_core(pir,en_threads);

            // Handle time out error
            if (ETIME == rc)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "call_host_activate_slave_cores: "
                           "Time out rc from kernel %d on core %x",
                           rc,
                           pir);

                FAPI_INVOKE_HWP( l_errl, proc_check_slw_done,
                                 l_fapi_ex_target);
                if (l_errl)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "ERROR : proc_check_slw_done" );
                    // Add chip target info
                    ErrlUserDetailsTarget(l_processor).addToLog( l_errl );
                    // Create IStep error log
                    l_stepError.addErrorDetails(l_errl);
                    // Commit error
                    errlCommit( l_errl, HWPF_COMP_ID );
                    break;
                }
                else
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SUCCESS : proc_check_slw_done - SLW is in clean state");
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
                 * @reasoncode  ISTEP_BAD_RC
                 * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid    ISTEP_HOST_ACTIVATE_SLAVE_CORES
                 * @userdata1   PIR of failing core.
                 * @userdata2   rc of cpu_start_core().
                 *
                 * @devdesc Kernel returned error when trying to activate core.
                 */
                errlHndl_t l_tmperrl =
                    new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            ISTEP_HOST_ACTIVATE_SLAVE_CORES,
                                            ISTEP_BAD_RC,
                                            pir,
                                            rc );

                // Callout core that failed to wake up.
                l_tmperrl->addHwCallout(*l_core,
                                        HWAS::SRCI_PRIORITY_MED,
                                        HWAS::DECONFIG,
                                        HWAS::GARD_Predictive);

                if (NULL == l_errl)
                {
                    l_errl = l_tmperrl;
                }
                else
                {
                    errlCommit( l_tmperrl, HWPF_COMP_ID );
                }
            }
            else //Core out of winkle sucessfully, issue SPWU for PRD
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "Running p8_cpu_special_wakeup (ENABLE)"
                          " EX target HUID %.8X",
                          TARGETING::get_huid(l_ex));

                // Enable special wakeup on core
                FAPI_INVOKE_HWP( l_errl,
                                 p8_cpu_special_wakeup,
                                 l_fapi_ex_target,
                                 SPCWKUP_ENABLE,
                                 HOST);

                if( l_errl )
                {
                    ErrlUserDetailsTarget(l_ex).addToLog( l_errl );

                    // Create IStep error log and cross ref error that occurred
                    l_stepError.addErrorDetails( l_errl );

                    // Commit Error
                    errlCommit( l_errl, HWPF_COMP_ID );

                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                             "ERROR : enable p8_cpu_special_wakeup, PLID=0x%x",
                             l_errl->plid()  );
                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "SUCCESS: enable p8_cpu_special_wakeup");
                }
            }
        }
    }

    if (l_errl)
    {
        // Create IStep error log and cross reference error that occurred
        l_stepError.addErrorDetails( l_errl );

        // Commit Error
        errlCommit(l_errl, HWPF_COMP_ID);
    }
    else
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
                fapi::Target l_fapi_ex_target( TARGET_TYPE_EX_CHIPLET,
                         (const_cast<TARGETING::Target*>(l_exTarget)) );

                //  call the HWP with each fapi::Target
                FAPI_INVOKE_HWP( l_errl,
                                 proc_post_winkle,
                                 l_fapi_ex_target);

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

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_activate_slave_cores exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}



//
//  Wrapper function to call mss_scrub
//
void * call_mss_scrub( void * io_pArgs )
{
    IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_scrub entry" );

    // There are performance issues and some functional deficiencies
    //  that make runtime scrub problematic, so turning it off
    if( Util::isSimicsRunning() )
    {
        TRACFCOMP(  ISTEPS_TRACE::g_trac_isteps_trace, "Skipping runtime scrub in Simics" );
        return NULL;
    }

    errlHndl_t l_errl = PRDF::startScrub();
    if ( NULL != l_errl )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Error returned from call to PRDF::startScrub" );

        l_stepError.addErrorDetails( l_errl );

        errlCommit( l_errl, HWPF_COMP_ID );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_scrub exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}




//
//  Wrapper function to call host_ipl_complete
//
void*    call_host_ipl_complete( void    *io_pArgs )
{
    errlHndl_t  l_err  =   NULL;

    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_ipl_complete entry" );
    do
    {
        // We only need to run cfsim on the master Processor.
        TARGETING::Target * l_masterProc =   NULL;
        (void)TARGETING::targetService().
            masterProcChipTargetHandle( l_masterProc );

        const fapi::Target l_fapi_proc_target( TARGET_TYPE_PROC_CHIP,
                ( const_cast<TARGETING::Target*>(l_masterProc) ) );

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Running proc_switch_cfsim HWP on target HUID %.8X",
                TARGETING::get_huid(l_masterProc) );


        //  call proc_switch_cfsim
    // TODO: RTC 64136 - Comment out to work around Centaur FSI scom issue
    // during BU
    // RTC 64136 is opened to undo this when in-band scoms are available.
#if 0
        FAPI_INVOKE_HWP(l_err, proc_switch_cfsim, l_fapi_proc_target,
                        true, // RESET
                        true, // RESET_OPB_SWITCH
                        true, // FENCE_FSI0
                        true, // FENCE_PIB_NH
                        true, // FENCE_PIB_H
                        true, // FENCE_FSI1
                        true); // FENCE_PIB_SW1
#endif
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: proc_switch_cfsim HWP returned error",
                      l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_masterProc).addToLog( l_err );

            // Create IStep error log and cross reference error that occurred
            l_stepError.addErrorDetails( l_err );

            // commit errorlog
            errlCommit( l_err, HWPF_COMP_ID );

            //break to end because if proc_switch_cfsim fails
            //then FSP does not have FSI control again and system is toast
            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS: proc_switch_cfsim HWP( )" );
        }


        //  Loop through all the centaurs in the system
        //  and run cen_switch_rec_attn
        TARGETING::TargetHandleList l_memTargetList;
        getAllChips(l_memTargetList, TYPE_MEMBUF );

        for ( TargetHandleList::iterator l_iter = l_memTargetList.begin();
              l_iter != l_memTargetList.end();
              ++l_iter )
        {
            TARGETING::Target * l_memChip  =   (*l_iter) ;

            //  dump physical path to target
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "Running cen_switch_rec_attn HWP on target HUID %.8X",
                       TARGETING::get_huid(l_memChip) );

            // cast OUR type of target to a FAPI type of target.
            fapi::Target l_fapi_centaur_target( TARGET_TYPE_MEMBUF_CHIP,
                                                l_memChip );
            FAPI_INVOKE_HWP( l_err,
                             cen_switch_rec_attn,
                             l_fapi_centaur_target );
            if (l_err)
            {
                // log error for this centaur and continue

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X: cen_switch_rec_attn HWP( )",
                          l_err->reasonCode() );

                // Add all the details for this centaur
                ErrlUserDetailsTarget myDetails(l_memChip);

                // capture the target data in the elog
                myDetails.addToLog(l_err);

                // Create IStep error log and cross ref error that occurred
                l_stepError.addErrorDetails( l_err );

                // Commit Error
                errlCommit( l_err, HWPF_COMP_ID );
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS: cen_switch_rec_attn HWP( )" );
            }
        }   // endfor


        //  Loop through all the mcs in the system
        //  and run proc_switch_rec_attn
        TARGETING::TargetHandleList l_mcsTargetList;
        getAllChiplets(l_mcsTargetList, TYPE_MCS);

        for ( TargetHandleList::iterator l_iter = l_mcsTargetList.begin();
            l_iter != l_mcsTargetList.end();
            ++l_iter )
        {
            TARGETING::Target * l_mcsChiplet  =   (*l_iter) ;

            //  dump physical path to target
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "Running cen_switch_rec_attn HWP on target HUID %.8X",
                       TARGETING::get_huid(l_mcsChiplet) );

            // cast OUR type of target to a FAPI type of target.
            fapi::Target l_fapi_mcs_target( TARGET_TYPE_MCS_CHIPLET,
                                            l_mcsChiplet );

            FAPI_INVOKE_HWP( l_err,
                             proc_switch_rec_attn,
                             l_fapi_mcs_target );
            if (l_err)
            {
                // log error for this mcs and continue

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X: proc_switch_rec_attn HWP( )",
                          l_err->reasonCode() );

                // Add all the details for this proc
                ErrlUserDetailsTarget myDetails(l_mcsChiplet);

                // capture the target data in the elog
                myDetails.addToLog(l_err);

                // Create IStep error log and cross ref error that occurred
                l_stepError.addErrorDetails( l_err );

                // Commit Error
                errlCommit( l_err, HWPF_COMP_ID );
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS: proc_switch_rec_attn HWP( )" );
            }

        }   //  endfor


        //If Sapphire Payload need to set payload base to zero
        if (is_sapphire_load())
        {
            TARGETING::Target* sys = NULL;
            TARGETING::targetService().getTopLevelTarget(sys);
            assert( sys != NULL );
            sys->setAttr<ATTR_PAYLOAD_BASE>(0x0);
        }

        // Sync attributes to Fsp
        l_err = syncAllAttributesToFsp();

        if( l_err )
        {
            break;
        }

        // Send Sync Point to Fsp
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   INFO_MRK"Send SYNC_POINT_REACHED msg to Fsp" );
        l_err = INITSERVICE::sendSyncPoint();

    } while( 0 );

    if( l_err )
    {
        // collect and log any remaining errors

        // Create IStep error log and cross reference error that occurred
        l_stepError.addErrorDetails( l_err );

        // Commit Error
        errlCommit( l_err, HWPF_COMP_ID );
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_ipl_complete exit ");

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}


};   // end namespace
