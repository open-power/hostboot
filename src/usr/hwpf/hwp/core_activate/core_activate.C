/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/core_activate.C $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <initservice/isteps_trace.H>
#include    <initservice/istepdispatcherif.H>

#include    <hwpisteperror.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/namedtarget.H>
#include    <targeting/attrsync.H>

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
// #include    "host_activate_slave_cores/host_activate_slave_cores.H"
#include    "proc_switch_cfsim.H"

namespace   CORE_ACTIVATE
{

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

        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_host_activate_master: Find master chip: " );
        TARGETING::Target* l_cpu_target = const_cast<TARGETING::Target *>
                                          ( getParentChip( l_masterCore ) );

        //  dump physical path to target
        EntityPath l_path;
        l_path  =   l_cpu_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_cpu_target(
                                            TARGET_TYPE_PROC_CHIP,
                                            reinterpret_cast<void *>
                                            (const_cast<TARGETING::Target*>
                                                        (l_cpu_target)) );

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_activate_master: call proc_prep_master_winkle." );


        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP( l_errl,
                         proc_prep_master_winkle,
                         l_fapi_cpu_target,
                         true  );
        if ( l_errl )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "proc_prep_master_winkle ERROR : Returning errorlog, PLID=0x%x",
                l_errl->plid() );
            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "proc_prep_master_winkle SUCCESS"  );
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
                   "Call proc_stop_deadman_timer..." );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP( l_errl,
                         proc_stop_deadman_timer,
                         l_fapi_cpu_target  );
        if ( l_errl )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "proc_stop_deadman_timer ERROR : Returning errorlog, PLID=0x%x",
                       l_errl->plid() );
            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "proc_prep_master_winkle SUCCESS"  );
        }

    }   while ( 0 );

    // @@@@@    END CUSTOM BLOCK:   @@@@@
    if( l_errl )
    {
        /*@
         * @errortype
         * @reasoncode      ISTEP_CORE_ACTIVATE_FAILED
         * @severity        ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid        ISTEP_HOST_ACTIVATE_MASTER
         * @userdata1       bytes 0-1: plid identifying first error
         *                  bytes 2-3: reason code of first error
         * @userdata2       bytes 0-1: total number of elogs included
         *                  bytes 2-3: N/A
         * @devdesc         call to host_activate_master failed see
         *                  error identified by the plid in user data
         *                  field.
         */
        l_stepError.addErrorDetails(ISTEP_CORE_ACTIVATE_FAILED,
                         ISTEP_HOST_ACTIVATE_MASTER,
                         l_errl );

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

    for(TargetHandleList::const_iterator l_core = l_cores.begin();
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

        uint64_t pir = l_coreId << 3;
        pir |= l_chipId << 7;
        pir |= l_logicalNodeId << 10;

        if (pir != l_masterCoreID)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "call_host_activate_slave_cores: Waking %x", pir);

            int rc = cpu_start_core(pir);

            // We purposefully only create one error log here.  The only
            // failure from the kernel is a bad PIR, which means we have
            // a pervasive attribute problem of some sort.  Just log the
            // first failing PIR.
            if ((0 != rc) && (NULL == l_errl))
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "call_host_activate_slave_cores: Error from kernel"
                           " %d on core %x",
                           rc, pir);
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
                l_errl =
                    new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            ISTEP_HOST_ACTIVATE_SLAVE_CORES,
                                            ISTEP_BAD_RC,
                                            pir,
                                            rc );
            }
        }
    }

    if ( ! l_errl )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "set PORE bars back to 0" );

        //  @todo   see RTC 51264 -
        //  This has to be modified if we are loading other AVP's instead
        //  of PHYP
        TARGETING::TargetHandleList l_procTargetList;
        getAllChips(l_procTargetList, TYPE_PROC);

        // loop thru all the cpu's
        for ( uint8_t l_procNum=0; l_procNum < l_procTargetList.size(); l_procNum++)
        {
            //  make a local copy of the CPU target
            TARGETING::Target*  l_proc_target = l_procTargetList[l_procNum];

            //  dump physical path to target
            EntityPath l_path;
            l_path  =   l_proc_target->getAttr<ATTR_PHYS_PATH>();
            l_path.dump();

            // cast OUR type of target to a FAPI type of target.
            fapi::Target l_fapi_proc_target(
                                           TARGET_TYPE_PROC_CHIP,
                                           reinterpret_cast<void *>
                                           (const_cast<TARGETING::Target*>(l_proc_target)) );

            //  reset pore bar notes:
            //  A mem_size of 0 means to ignore the image address
            //  This image should have been moved to memory after winkle

            //  call the HWP with each fapi::Target
            FAPI_INVOKE_HWP( l_errl,
                             p8_set_pore_bar,
                             l_fapi_proc_target,
                             0,
                             0,
                             0,
                             SLW_MEMORY
                           );
            if ( l_errl )
            {
                /*@
                 * @errortype
                 * @reasoncode      ISTEP_RESET_PORE_BARS_FAILED
                 * @severity        ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid        ISTEP_HOST_ACTIVATE_SLAVE_CORES
                 * @userdata1       0
                 * @userdata2       0
                 * @devdesc         call to set_pore_bars failed.
                 *                  see error identified by the plid in
                 *                  user data field.
                 */
                l_stepError.addErrorDetails(ISTEP_RESET_PORE_BARS_FAILED,
                                            ISTEP_HOST_ACTIVATE_SLAVE_CORES,
                                            l_errl );

                errlCommit( l_errl, HWPF_COMP_ID );

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR : p8_set_pore_bar, PLID=0x%x",
                          l_errl->plid()  );
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS : p8_set_pore_bar" );
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
        // We only need to do this to the master Processor.

        TARGETING::Target * l_masterProc =   NULL;
        (void)TARGETING::targetService().masterProcChipTargetHandle( l_masterProc );

        const fapi::Target l_fapi_proc_target(
                TARGET_TYPE_PROC_CHIP,
                reinterpret_cast<void *>
                ( const_cast<TARGETING::Target*>(l_masterProc) ) );

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running proc_switch_cfsim HWP on ...");
        EntityPath l_path;
        l_path  =   l_masterProc->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        //  call proc_switch_cfsim
        FAPI_INVOKE_HWP(l_err, proc_switch_cfsim, l_fapi_proc_target,
                        true, // RESET
                        true, // RESET_OPB_SWITCH
                        true, // FENCE_FSI0
                        true, // FENCE_PIB_NH
                        true, // FENCE_PIB_H
                        true, // FENCE_FSI1
                        true); // FENCE_PIB_SW1
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: proc_switch_cfsim HWP returns error",
                      l_err->reasonCode());
            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS: proc_switch_cfsim HWP( )" );
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
        /*@
         * @errortype
         * @reasoncode      ISTEP_CORE_ACTIVATE_FAILED
         * @severity        ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid        ISTEP_HOST_IPL_COMPLETE
         * @userdata1       bytes 0-1: plid identifying first error
         *                  bytes 2-3: reason code of first error
         * @userdata2       bytes 0-1: total number of elogs included
         *                  bytes 2-3: N/A
         * @devdesc         call to host_ipl_complete failed see
         *                  error identified by the plid in user data
         *                  field.
         */
        l_stepError.addErrorDetails(ISTEP_CORE_ACTIVATE_FAILED,
                                    ISTEP_HOST_IPL_COMPLETE,
                                    l_err );

        errlCommit( l_err, HWPF_COMP_ID );
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_ipl_complete exit ");


    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}


};   // end namespace
