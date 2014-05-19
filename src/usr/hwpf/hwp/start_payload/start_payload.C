/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/start_payload/start_payload.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
 *  @file start_payload.C
 *
 *  Support file for IStep: start_payload
 *   Start Payload
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <kernel/console.H>              //  printk status
#include    <sys/misc.h>
#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <vfs/vfs.H>
#include    <initservice/initserviceif.H>
#include    <initservice/extinitserviceif.H>
#include    <initservice/istepdispatcherif.H>
#include    <usr/cxxtest/TestSuite.H>
#include    <hwpf/istepreasoncodes.H>
#include    <errl/errludtarget.H>
#include    <sys/time.h>
#include    <sys/mmio.h>
#include    <mbox/mbox_queues.H>
#include    <mbox/mboxif.H>
#include    <i2c/i2cif.H>
#include    <hwpf/hwp/occ/occ.H>
#include    <sys/mm.h>
#include    <devicefw/userif.H>

#include    <initservice/isteps_trace.H>
#include    <hwpisteperror.H>

//  targeting support
#include    <targeting/common/commontargeting.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>
#include    "p8_set_pore_bar.H"
#include    "p8_cpu_special_wakeup.H"
#include    "p8_pore_table_gen_api.H"
#include    <p8_scom_addresses.H>

#include    "start_payload.H"
#include    <runtime/runtime.H>
#include    <devtree/devtreeif.H>
#include    <sys/task.h>
#include    <intr/interrupt.H>
#include    <kernel/ipc.H> // for internode data areas
#include    <mbox/ipc_msg_types.H>

//  Uncomment these files as they become available:
// #include    "host_start_payload/host_start_payload.H"

namespace   START_PAYLOAD
{

using   namespace   TARGETING;
using   namespace   fapi;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;


/**
 * @brief This function will call the Initservice interface to shutdown
 *      Hostboot.  This function will call shutdown, passing in system
 *      attribute variables for the Payload base and Payload offset.
 *
 * @param[in] Host boot master instance number (logical node number)
 * @param[in] Is this the master HB instance [true|false]
 *
 * @return errlHndl_t - NULL if succesful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t callShutdown ( uint64_t i_hbInstance, bool i_masterIntance );

/**
 * @brief This function will send an IPC message to all other HB instances
 *        to perfrom the shutdown sequence.
 * @param[in] Hostboot master instance number (logical node number)
 * @Return errlHndlt_t - Null if succesful, otherwise an error Handle
 */
errlHndl_t broadcastShutdown ( uint64_t i_hbInstance );

/**
 * @brief This function will check the Istep mode and send the appropriate
 *      mailbox message to the Fsp to indicate what we're doing.
 *
 * @param[in] i_istepModeFlag - Whether or not Isteps is enabled.
 *
 * @param[in] i_spFuncs - The SpFuncs system attribute.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t notifyFsp ( bool i_istepModeFlag,
                       TARGETING::SpFunctions i_spFuncs );

/**
 * @brief This function disables the special wakeup that allows scom
 *        operations on napped cores
 *
 * @return errlHndl_t error handle
 */
errlHndl_t disableSpecialWakeup();

/**
 * @brief Re-enables the local core checkstop function
 *
 * @return errlHndl_t error handle
 */
errlHndl_t enableCoreCheckstops();


/**
 * @brief This function will clear the PORE BARs.  Needs to be done
 *      depending on payload type
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t clearPoreBars ( void )
{
    errlHndl_t l_errl = NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "set PORE bars back to 0" );

    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    // loop thru all the cpus and reset the pore bars.
    for (TargetHandleList::const_iterator
         l_proc_iter = l_procTargetList.begin();
         l_proc_iter != l_procTargetList.end();
         ++l_proc_iter)
    {
        //  make a local copy of the CPU target
        const TARGETING::Target* l_proc_target = *l_proc_iter;

        //  trace HUID
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "target HUID %.8X", TARGETING::get_huid(l_proc_target));

        // cast OUR type of target to a FAPI type of target.
        fapi::Target l_fapi_proc_target( TARGET_TYPE_PROC_CHIP,
                                         (const_cast<TARGETING::Target*>(
                                                         l_proc_target)) );

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
            // capture the target data in the elog
            ERRORLOG::ErrlUserDetailsTarget(l_proc_target).addToLog( l_errl );

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : p8_set_pore_bar, PLID=0x%x",
                      l_errl->plid()  );
            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS : p8_set_pore_bar" );
        }

    }   // end for

    return l_errl;
}


//
//  Wrapper function to call host_runtime_setup
//
void*    call_host_runtime_setup( void    *io_pArgs )
{

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_host_runtime_setup entry" );

    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    // Need to wait here until Fsp tells us go
    INITSERVICE::waitForSyncPoint();

    do
    {

        // Need to load up the runtime module if it isn't already loaded
        if (  !VFS::module_is_loaded( "libruntime.so" ) )
        {
            l_err = VFS::module_load( "libruntime.so" );

            if ( l_err )
            {
                //  load module returned with errl set
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "Could not load runtime module" );
                // break from do loop if error occured
                break;
            }
        }

        // Map the Host Data into the VMM if applicable
        l_err = RUNTIME::load_host_data();
        if( l_err )
        {
            break;
        }

        //Start OCC in AVP
        if( is_avp_load() )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "Starting OCC" );

            //Load modules needed by OCC
            bool occ_loaded = false;

            if (  !VFS::module_is_loaded( "libocc.so" ) )
            {
                l_err = VFS::module_load( "libocc.so" );

                if ( l_err )
                {
                    //  load module returned with errl set
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "Could not load occ module" );
                    // break from do loop if error occured
                    break;
                }
                occ_loaded = true;
            }

            l_err = HBOCC::loadnStartAllOccs();
            if(l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadnStartAllOccs failed" );
            }

            //make sure we always unload the module
            if (occ_loaded)
            {
                errlHndl_t  l_tmpErrl  =   NULL;
                l_tmpErrl = VFS::module_unload( "libocc.so" );
                if ( l_tmpErrl )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               ERR_MRK"Error unloading libocc module" );
                    if(l_err)
                    {
                        errlCommit( l_tmpErrl, HWPF_COMP_ID );
                    }
                    else
                    {
                        l_err = l_tmpErrl;
                    }
                }
            }

            if (l_err)
            {
                break;
            }
        }

        if( is_sapphire_load() && (!INITSERVICE::spBaseServicesEnabled()) )
        {
            // Write the devtree out in Sapphire mode when SP Base Services not
            // enabled
            l_err = DEVTREE::build_flatdevtree();
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Could not build dev tree" );
                // break from do loop if error occured
                break;
            }
        }
        else if( is_sapphire_load() )
        {
            // Find area in HDAT to load devtree.
            uint64_t l_dtAddr = 0;
            size_t l_dtSize = 0;
            l_err = RUNTIME::get_host_data_section(RUNTIME::HSVC_SYSTEM_DATA,
                                                   0, l_dtAddr, l_dtSize);

            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Could not find system data area for Devtree.");
                break;
            }

            l_err = DEVTREE::build_flatdevtree(l_dtAddr, l_dtSize, true);

            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Failed to build small dev-tree for HDAT.");
                break;
            }

        }
        else if( is_phyp_load() )
        {
            //If PHYP then clear out the PORE BARs
            l_err = clearPoreBars();
            if( l_err )
            {
                break;
            }

            //Update the MDRT value (for MS Dump)
            l_err = RUNTIME::writeActualCount(RUNTIME::MS_DUMP_RESULTS_TBL);
            if(l_err != NULL)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "write_MDRT_Count failed" );
                break;
            }

            // Write the HostServices attributes into mainstore
            l_err = RUNTIME::populate_attributes();
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Could not populate attributes" );
                // break from do loop if error occured
                break;
            }
        }
        else if( !is_avp_load() )
        {
            // Write the HostServices attributes into mainstore
            //  for our testcases
            l_err = RUNTIME::populate_attributes();
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Could not populate attributes" );
                // break from do loop if error occured
                break;
            }
        }

        // Revert back to standard runtime mode where core checkstops
        //  do not escalate to system checkstops
        // Workaround for HW286670
        l_err = enableCoreCheckstops();
        if ( l_err )
        {
            break;
        }

        //  - Update HDAT/DEVTREE with tpmd logs

    } while(0);

    if( l_err )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "istep start_payload_failed see plid 0x%x", l_err->plid());

        // Create IStep error log and cross reference error that occurred
        l_StepError.addErrorDetails( l_err );

        // Commit Error
        errlCommit(l_err, ISTEP_COMP_ID);

    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_host_runtime_setup exit" );

    return l_StepError.getErrorHandle();
}

//
//  Wrapper function to call host_start_payload
//
void*    call_host_verify_hdat( void    *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_verify_hdat entry" );

    errlHndl_t l_err = NULL;

    // Host Start Payload procedure, per documentation from Patrick.
    //  - Verify target image
    //      - TODO - Done via call to Secure Boot ROM.
    //      - Will be done in future sprints

    // stub for now..

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_verify_hdat exit" );

    return l_err;
}
//
//  Wrapper function to call host_start_payload
//
void*    call_host_start_payload( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_host_start_payload entry" );

    // For single-node systems, the non-master processors can be in a
    // different logical (powerbus) node.  Need to migrate task to master.
    task_affinity_pin();
    task_affinity_migrate_to_master();

    uint64_t this_node = INTR::PIR_t(task_getcpuid()).nodeId;

    task_affinity_unpin();

    // broadcast shutdown to other HB instances.
    l_errl = broadcastShutdown(this_node);

    if( l_errl == NULL)
    {
        //  - Run CXX testcases
        l_errl = INITSERVICE::executeUnitTests();
    }

    if( l_errl == NULL )
    {
        l_errl = disableSpecialWakeup();
    }

    if( l_errl == NULL )
    {
        //  - Call shutdown using payload base, and payload entry.
        //      - base/entry will be from system attributes
        //      - this will start the payload (Phyp)
        // NOTE: this call will not return if successful.
        l_errl = callShutdown(this_node, true);

    };

    if( l_errl )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "istep start_payload_failed see plid 0x%x", l_errl->plid());

        // Create IStep error log and cross reference error that occurred
        l_StepError.addErrorDetails( l_errl );

        // Commit Error
        errlCommit(l_errl, ISTEP_COMP_ID);

    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_host_start_payload exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}


//
// Call shutdown
//
errlHndl_t callShutdown ( uint64_t i_masterInstance,
                          bool i_isMaster)
{
    errlHndl_t err = NULL;
    uint64_t payloadBase = 0x0;
    uint64_t payloadEntry = 0x0;
    uint64_t payloadData = 0x0;
    bool istepModeFlag = false;
    uint64_t status = SHUTDOWN_STATUS_GOOD;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               ENTER_MRK"callShutdown()" );

    do
    {
        // Phyp needs us to program all of the I2C masters with the bus
        // divisor
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Setup I2C Masters" );
        err = I2C::i2cSetupMasters();
        if( err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "Error setting up I2C Bus Divisors" );
            break;
        }

        // Get Target Service, and the system target.
        TargetService& tS = targetService();
        TARGETING::Target* sys = NULL;
        (void) tS.getTopLevelTarget( sys );

        if( NULL == sys )
        {
            // Error getting system target to get payload related values.  We
            // will create an error to be passed back.  This will cause the
            // istep to fail.
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       ERR_MRK"System Target was NULL!" );

            /*@
             * @errortype
             * @reasoncode       ISTEP_TARGET_NULL
             * @severity         ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid         ISTEP_START_PAYLOAD_CALL_SHUTDOWN
             * @userdata1        <UNUSED>
             * @userdata2        <UNUSED>
             * @devdesc          System target was NULL!
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                           ISTEP_START_PAYLOAD_CALL_SHUTDOWN,
                                           ISTEP_TARGET_NULL,
                                           0x0,
                                           0x0 );

            break;
        }

        // Get Payload base/entry from attributes
        payloadBase = sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>();
        payloadEntry = sys->getAttr<TARGETING::ATTR_PAYLOAD_ENTRY>();
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   INFO_MRK"Payload Base: 0x%08x, Entry: 0x%08x",
                   payloadBase, payloadEntry );
        payloadBase = (payloadBase * MEGABYTE);
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   INFO_MRK"   base: 0x%08x",
                   payloadBase );

        // Get Istep Mode flag
        istepModeFlag = sys->getAttr<ATTR_ISTEP_MODE>();
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   INFO_MRK"Istep mode flag: %s",
                   ((istepModeFlag) ? "Enabled" : "Disabled") );

        // Get the Service Processor Functions
        TARGETING::SpFunctions spFuncs =
                sys->getAttr<TARGETING::ATTR_SP_FUNCTIONS>();

        if(i_isMaster)
        {
            // Notify Fsp with appropriate mailbox message.
            err = notifyFsp( istepModeFlag,
                             spFuncs );

            if( err )
            {
                break;
            }

            // Load payload data in Sapphire mode when
            // SP Base Services not enabled
            if( is_sapphire_load() && (!INITSERVICE::spBaseServicesEnabled()))
            {
                payloadData = DEVTREE::get_flatdevtree_phys_addr();
            }
        }

        // do the shutdown.
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "callShutdown finished, shutdown = 0x%x.",
                   status );
        INITSERVICE::doShutdown( status,
                                 false,
                                 payloadBase,
                                 payloadEntry,
                                 payloadData,
                                 i_masterInstance);

    } while( 0 );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               EXIT_MRK"callShutdown()" );

    return err;
}

//
// Notify the Fsp via Mailbox Message
//
errlHndl_t notifyFsp ( bool i_istepModeFlag,
                       TARGETING::SpFunctions i_spFuncs )
{
    errlHndl_t err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               ENTER_MRK"notifyFsp()" );

    do
    {
        if( i_istepModeFlag )
        {
            // Istep Mode send istep complete
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       INFO_MRK"Isteps enabled, send istep complete msg" );

            err = INITSERVICE::sendIstepCompleteMsg();

            if( err )
            {
                break;
            }
        }
        else
        {
            // Non-Istep mode send SYNC_POINT_REACHED
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       INFO_MRK"Isteps disabled, send SYNC_POINT_REACHED msg" );

            err = INITSERVICE::sendSyncPoint();

            if( err )
            {
                break;
            }
        }
    } while( 0 );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               EXIT_MRK"notifyFsp()" );

    return err;
}




errlHndl_t broadcastShutdown ( uint64_t i_hbInstance )
{
    errlHndl_t err = NULL;
    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );
    assert(sys != NULL);

    TARGETING::ATTR_HB_EXISTING_IMAGE_type hb_images =
        sys->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();

    do
    {
        // Set up the start_payload_data_area before
        // broadcasting the shutdown to the slave HB instances
        memset(&KernelIpc::start_payload_data_area,
               '\0',
               sizeof(KernelIpc::start_payload_data_area));

        KernelIpc::start_payload_data_area.node_count = 0;
        KernelIpc::start_payload_data_area.lowest_PIR = 0xfffffffffffffffful;

        // ATTR_HB_EXISTING_IMAGE only gets set on a multi-drawer system.
        // Currently set up in host_sys_fab_iovalid_processing() which only
        // gets called if there are multiple physical nodes.
        if(hb_images == 0)
        {
            // Single node system
            KernelIpc::start_payload_data_area.node_count = 1;
            break;
        }

        // continue - multi-node

        uint8_t node_map
            [sizeof(TARGETING::ATTR_FABRIC_TO_PHYSICAL_NODE_MAP_type)];

        sys->tryGetAttr<TARGETING::ATTR_FABRIC_TO_PHYSICAL_NODE_MAP>(node_map);

        uint64_t node_count = 0;

        // Count the number of hb instances before sending
        // any start_payload messages
        for(uint64_t drawer = 0; drawer < sizeof(node_map); ++drawer)
        {
            uint64_t node = node_map[drawer];

            if(node < (sizeof(TARGETING::ATTR_HB_EXISTING_IMAGE_type) * 8))
            {

                // set mask to msb
                TARGETING::ATTR_HB_EXISTING_IMAGE_type mask = 0x1 <<
                    ((sizeof(TARGETING::ATTR_HB_EXISTING_IMAGE_type) * 8) -1);

                if( 0 != ((mask >> node) & hb_images ) )
                {
                    ++node_count;
                }
            }
        }

        KernelIpc::start_payload_data_area.node_count = node_count;

        // send message to all other existing hb instances except this one.
        for(uint64_t drawer = 0; drawer < sizeof(node_map); ++drawer)
        {
            uint64_t node = node_map[drawer];

            if(node < (sizeof(TARGETING::ATTR_HB_EXISTING_IMAGE_type) * 8) &&
               node != i_hbInstance)
            {

                // set mask to msb
                TARGETING::ATTR_HB_EXISTING_IMAGE_type mask = 0x1 <<
                    ((sizeof(TARGETING::ATTR_HB_EXISTING_IMAGE_type) * 8) -1);

                if( 0 != ((mask >> node) & hb_images ) )
                {
                    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "start_payload-sending msg for drawer %d",
                               drawer );
                    msg_t * msg = msg_allocate();
                    msg->type = IPC::IPC_START_PAYLOAD;
                    msg->data[0] = i_hbInstance;
                    err = MBOX::send(MBOX::HB_IPC_MSGQ, msg, node);
                    if (err)
                    {
                        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "MBOX::send failed");
                        break;
                    }
                }
            }
        }

    } while(0);

    return err;
}


errlHndl_t disableSpecialWakeup()
{
    errlHndl_t l_errl = NULL;

    // loop thru all proc and find all functional ex units
    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);
    for (TargetHandleList::const_iterator l_procIter =
         l_procTargetList.begin();
         l_procIter != l_procTargetList.end();
         ++l_procIter)
    {
        const TARGETING::Target* l_pChipTarget = *l_procIter;

        // Get EX list under this proc
        TARGETING::TargetHandleList l_exList;
        getChildChiplets( l_exList, l_pChipTarget, TYPE_EX );

        for (TargetHandleList::const_iterator
             l_exIter = l_exList.begin();
             l_exIter != l_exList.end();
             ++l_exIter)
        {
            const TARGETING::Target * l_exTarget = *l_exIter;

            fapi::Target l_fapi_ex_target
                ( TARGET_TYPE_EX_CHIPLET,
                  (const_cast<TARGETING::Target*>(l_exTarget)) );

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Running p8_cpu_special_wakeup(DISABLE) "
                      "on EX target HUID %.8X",
                      TARGETING::get_huid(l_exTarget));

            FAPI_INVOKE_HWP(l_errl,
                            p8_cpu_special_wakeup,
                            l_fapi_ex_target,
                            SPCWKUP_DISABLE,
                            HOST);

            if(l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Disable p8_cpu_special_wakeup ERROR :"
                           " Returning errorlog, reason=0x%x",
                           l_errl->reasonCode() );

                // capture the target data in the elog
                ERRORLOG::ErrlUserDetailsTarget(l_exTarget).addToLog( l_errl );

                break;
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "SUCCESS: Disable special wakeup");
            }
        }
        if(l_errl)
        {
            break;
        }
    }

    return l_errl;
}


/**
 * @brief Re-enables the local core checkstop function
 */
errlHndl_t enableCoreCheckstops()
{
    errlHndl_t l_errl = NULL;
    void* l_slwPtr = NULL;
    int mm_rc = 0;

    // loop thru all proc and find all functional ex units
    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);
    for (TargetHandleList::const_iterator l_procIter =
         l_procTargetList.begin();
         l_procIter != l_procTargetList.end();
         ++l_procIter)
    {
        const TARGETING::Target* l_pChipTarget = *l_procIter;

        //  calculate location of the SLW output buffer
        uint64_t l_physAddr =
          l_pChipTarget->getAttr<TARGETING::ATTR_SLW_IMAGE_ADDR>();
        l_slwPtr = mm_block_map(reinterpret_cast<void*>(l_physAddr),
                                HOMER_MAX_SLW_IMG_SIZE_IN_MB*MEGABYTE);
        if( l_slwPtr == NULL )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "Error from mm_block_map : phys=%.16X", l_physAddr );
            /*@
             * @errortype
             * @reasoncode   ISTEP::ISTEP_MM_MAP_ERR
             * @moduleid     ISTEP::ISTEP_ENABLE_CORE_CHECKSTOPS
             * @severity     ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @userdata1    <unused>
             * @userdata2    Physical address
             * @devdesc      mm_block_map() returns error
             */
            l_errl =
              new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      ISTEP::ISTEP_ENABLE_CORE_CHECKSTOPS,
                                      ISTEP::ISTEP_MM_MAP_ERR,
                                      0,
                                      l_physAddr);
        }

        // Get EX list under this proc
        TARGETING::TargetHandleList l_exList;
        getChildChiplets( l_exList, l_pChipTarget, TYPE_EX );

        for (TargetHandleList::const_iterator
             l_exIter = l_exList.begin();
             l_exIter != l_exList.end();
             ++l_exIter)
        {
            TARGETING::Target* l_exTarget = *l_exIter;

            // Write the runtime version of the Action1 reg
            // Core FIR Action1 Register value from Nick
            uint64_t action1_reg = 0xFEFC17F78F9C8A01;
            size_t opsize = sizeof(uint64_t);
            l_errl = deviceWrite( l_exTarget,
                        &action1_reg,
                        opsize,
                        DEVICE_SCOM_ADDRESS(EX_CORE_FIR_ACTION1_0x10013107) );
            if( l_errl )
            {
                break;
            }

            // Need to force core checkstops to escalate to a system checkstop
            //  by telling the SLW to update the ACTION1 register when it
            //  comes out of winkle  (see HW286670)
            TARGETING::ATTR_CHIP_UNIT_type l_coreId =
              l_exTarget->getAttr<ATTR_CHIP_UNIT>();
            uint32_t l_rc = p8_pore_gen_scom_fixed( l_slwPtr,
                                           P8_SLW_MODEBUILD_IPL,
                                           EX_CORE_FIR_ACTION1_0x10013107,
                                           l_coreId,
                                           action1_reg,//ignored
                                           P8_PORE_SCOM_NOOP,
                                           P8_SCOM_SECTION_NC );
            if( l_rc )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "ERROR: ACTION1: chip=%.8X, core=0x%x,l_rc=0x%x",
                           get_huid(l_pChipTarget), l_coreId, l_rc );
                /*@
                 * @errortype
                 * @reasoncode  ISTEP_BAD_RC
                 * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid    ISTEP_ENABLE_CORE_CHECKSTOPS
                 * @userdata1[00:31]  rc from p8_pore_gen_scom_fixed function
                 * @userdata1[32:63]  address being added to image
                 * @userdata2[00:31]  Failing Proc HUID
                 * @userdata2[32:63]  Failing Core Id
                 *
                 * @devdesc p8_pore_gen_scom_fixed returned an error when
                 *          attempting to erase a reg value in the PORE image.
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                                     ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                     ISTEP::ISTEP_ENABLE_CORE_CHECKSTOPS,
                                     ISTEP::ISTEP_BAD_RC,
                                     TWO_UINT32_TO_UINT64(l_rc,
                                             EX_CORE_FIR_ACTION1_0x10013107),
                                     TWO_UINT32_TO_UINT64(
                                             get_huid(l_pChipTarget),
                                             l_coreId) );
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
                l_errl->collectTrace("ISTEPS_TRACE",256);
                break;
            }
        }

        mm_rc = mm_block_unmap(l_slwPtr);
        if( mm_rc )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "Error from mm_block_unmap : rc=%d, ptr=%p", mm_rc, l_slwPtr );
            /*@
             * @errortype
             * @reasoncode   ISTEP::ISTEP_MM_UNMAP_ERR
             * @moduleid     ISTEP::ISTEP_ENABLE_CORE_CHECKSTOPS
             * @severity     ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @userdata1    Return Code
             * @userdata2    Unmap address
             * @devdesc      mm_block_unmap() returns error
             */
            l_errl =
              new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      ISTEP::ISTEP_ENABLE_CORE_CHECKSTOPS,
                                      ISTEP::ISTEP_MM_UNMAP_ERR,
                                      mm_rc,
                                      reinterpret_cast<uint64_t>
                                      (l_slwPtr));
            // Just commit error and keep going
            errlCommit( l_errl, ISTEP_COMP_ID );
        }
        l_slwPtr = NULL;

        if(l_errl)
        {
            break;
        }
    }

    return l_errl;
}

};   // end namespace
