/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep21/call_host_start_payload.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
/* [+] Google Inc.                                                        */
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
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <initservice/isteps_trace.H>
#include <isteps/hwpisteperror.H>
#include <isteps/istep_reasoncodes.H>
#include <pm/pm_common.H>
#include <initservice/initserviceif.H>
#include <initservice/istepdispatcherif.H>
#include <secureboot/trustedbootif.H>
#include <sys/task.h>
#include <initservice/extinitserviceif.H>
#include <hbotcompid.H>
#include <sys/misc.h>
#include <targeting/common/mfgFlagAccessors.H>
#include <targeting/targplatutil.H>
#include <pnor/pnorif.H>
#include <kernel/console.H>
#include <util/misc.H>
#include <sys/mm.h>
#include <kernel/ipc.H> // for internode data areas
#include <mbox/ipc_msg_types.H>
#include <devicefw/userif.H>
#include <arch/pirformat.H>
#include <isteps/hwpf_reasoncodes.H>

//Fapi support
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
/* FIXME RTC:257487
#include <p9n2_quad_scom_addresses_fld.H>
#include <p9_quad_scom_addresses.H>
*/
#include <ipmi/ipmiwatchdog.H>
#include <errno.h>
#include <p10_int_scom.H>
#include <sbeio/sbeioif.H>
#include <runtime/runtime.H>
/* FIXME RTC:257487
#include <p9_stop_api.H>
*/
#include <kernel/memstate.H>
#include <kernel/misc.H>
#include "../hdat/hdattpmdata.H"
#include "hdatstructs.H"

using namespace ERRORLOG;
using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace TARGETING;
using namespace fapi2;

namespace ISTEP_21
{
/**
 * @brief This function will call the Initservice interface to shutdown
 *      Hostboot.  This function will call shutdown, passing in system
 *      attribute variables for the Payload base and Payload offset.
 *
 * @param[in] Host boot master instance number (logical node number)
 * @param[in] Is this the master HB instance [true|false]
 * @param[in] The lowest addressable location in the system, derived from the
 *            HRMOR of the master node.
 *
 * @return errlHndl_t - nullptr if succesful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t callShutdown ( uint64_t i_hbInstance,
                          bool i_masterIntance,
                          const uint64_t i_commBase);

/**
 * @brief This function will send an IPC message to all other HB instances
 *        to perfrom the shutdown sequence.
 * @param[in] Hostboot master instance number (logical node number)
 * @Return errlHndlt_t - nullptr if succesful, otherwise an error Handle
 */
errlHndl_t broadcastShutdown ( uint64_t i_hbInstance );


/**
 * @brief Re-enables the local core checkstop function
 *
 * @return errlHndl_t error handle
 */
errlHndl_t enableCoreCheckstops();

/**
 * @brief This function will check the Istep mode and send the appropriate
 *      mailbox message to the Fsp to indicate what we're doing.
 *
 * @param[in] i_istepModeFlag - Whether or not Isteps is enabled.
 *
 * @param[in] i_spFuncs - The SpFuncs system attribute.
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t notifyFsp ( bool i_istepModeFlag,
                       TARGETING::SpFunctions i_spFuncs );

enum msg_preshutdown_types_t
{
    MSG_PRE_SHUTDOWN_INITS = 1 //Tells the msgQ to run inits that
                               //are needed before shutdown
};

void msgHandler(msg_q_t i_msgQ)
{
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ENTER_MRK"call_host_start_payload::msgHandler()");

    while(1)
    {
        msg_t* msg = msg_wait(i_msgQ); // wait for interrupt msg

        switch(msg->type)
        {
            case MSG_PRE_SHUTDOWN_INITS:
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "call_host_start_payload::msgHandler: Pre-shutdown inits event received");

                errlHndl_t l_errl = nullptr;
                TARGETING::TargetHandleList l_procTargetList;
                const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

                // Get a list of all proc chips
                getAllChips(l_procTargetList, TYPE_PROC);

                for (const auto & l_cpu_target: l_procTargetList)
                {
                    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                            l_fapi2_cpu_target (l_cpu_target);

                    //Call p10_int_scom hwp
                    FAPI_INVOKE_HWP( l_errl, p10_int_scom,
                                     l_fapi2_cpu_target, FAPI_SYSTEM);
                    if(l_errl)
                    {
                        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                                   "ERROR in p10_int_scom HWP(): failed on target 0x%.08X. "
                                   TRACE_ERR_FMT,
                                   get_huid(l_cpu_target),
                                   TRACE_ERR_ARGS(l_errl));

                        // Commit Error
                        l_errl->collectTrace("ISTEPS_TRACE",256);
                        errlCommit(l_errl, ISTEP_COMP_ID );
                   }
                }

                msg_respond(i_msgQ, msg);
                break;
            }
            default:
                msg->data[1] = -EINVAL;
                msg_respond(i_msgQ, msg);
                break;
        }
    }
}


/**
* Helper function to start the messge handler
*/
void* msg_handler(msg_q_t i_msgQ)
{
    msgHandler(i_msgQ);
    return nullptr;
}

/**
* Function to align the trustedboot status on all nodes
*/
errlHndl_t calcTrustedBootState()
{
    errlHndl_t l_errl = nullptr;

    do {

    TARGETING::Target* l_sys = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_sys);
    assert(l_sys != nullptr, "Could not get sys target!");
    auto l_hbInstanceMap = l_sys->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();
    const size_t l_hbInstanceCount = __builtin_popcount(l_hbInstanceMap);
    if((l_hbInstanceCount < 2) ||
       (!TARGETING::UTIL::isCurrentMasterNode()))
    {
        break; // No-op on single node systems and non-master nodes.
    }

    uint32_t l_instance = 0;
    uint64_t l_hdatBaseAddr = 0;
    uint64_t l_dataSizeMax = 0; //unused
    uint64_t l_hdatInstanceCount = 0;
    uint64_t l_hbrtDataAddr = 0;

    l_errl = RUNTIME::get_host_data_section(RUNTIME::IPLPARMS_SYSTEM,
                                            l_instance, // instance 0
                                            l_hbrtDataAddr,
                                            l_dataSizeMax);
    if(l_errl)
    {
        break;
    }

    hdatSysParms_t* const l_hdatSysParms =
                             reinterpret_cast<hdatSysParms_t*>(l_hbrtDataAddr);

    SysSecSets* const l_sysSecuritySettings =
         reinterpret_cast<SysSecSets*>(&l_hdatSysParms->hdatSysSecuritySetting);

    l_errl = RUNTIME::get_instance_count(RUNTIME::NODE_TPM_RELATED,
                                         l_hdatInstanceCount);
    if(l_errl)
    {
        break;
    }

    assert(l_hdatInstanceCount == l_hbInstanceCount,
           "Inconsistent number of functional nodes reported");

    for(l_instance = 0; l_instance < l_hdatInstanceCount; ++l_instance)
    {
        l_errl = RUNTIME::get_host_data_section(RUNTIME::NODE_TPM_RELATED,
                                                l_instance,
                                                l_hdatBaseAddr,
                                                l_dataSizeMax);
        if(l_errl)
        {
            break;
        }

        auto const l_hdatTpmData = reinterpret_cast<HDAT::hdatTpmData_t*>
                                                               (l_hdatBaseAddr);
        auto const l_hdatTpmInfo =
                     reinterpret_cast<HDAT::hdatHDIFDataArray_t*>
                     (reinterpret_cast<uint64_t>(l_hdatTpmData) +
                      l_hdatTpmData->hdatSbTpmInfo.hdatOffset);
        auto const l_hdatTpmInstInfo =
                                   reinterpret_cast<HDAT::hdatSbTpmInstInfo_t*>(
                                     reinterpret_cast<uint64_t>(l_hdatTpmInfo) +
                                     sizeof(*l_hdatTpmInfo));
        TRACFBIN(ISTEPS_TRACE::g_trac_isteps_trace,
                 "calcTrustedBootState: l_hdatTpmInstInfo:",
                 l_hdatTpmInstInfo, sizeof(*l_hdatTpmInstInfo));
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "calcTrustedBootState: Primary TPM's functional status ="
                  " %d", l_hdatTpmInstInfo->hdatFunctionalStatus);

        if(l_hdatTpmInstInfo->hdatFunctionalStatus ==
           HDAT::TpmPresentAndFunctional)
        {
            l_sysSecuritySettings->trustedboot &= 1;
        }
        else
        {
            l_sysSecuritySettings->trustedboot &= 0;
        }
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
             "calcTrustedBootState: final trusted boot enabled status = %d",
              l_sysSecuritySettings->trustedboot);

    } while(0);

    return l_errl;
}

void* call_host_start_payload (void *io_pArgs)
{
    errlHndl_t  l_errl  =   nullptr;

    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_host_start_payload entry" );

    do{

        // Place a separator in the TPM to indicate we are passing control
        //  to the next level of firmware in the stack. Send the synchronous
        //  message to make sure that the traces are flushed prior to the daemon
        //  shutdown.
        l_errl = TRUSTEDBOOT::pcrExtendSeparator(false);

        if(l_errl)
        {
            break;
        }

        l_errl = calcTrustedBootState();
        if(l_errl)
        {
            break;
        }

        // For single-node systems, the non-master processors can be in a
        // different logical (powerbus) group.  Need to migrate task to master.
        task_affinity_pin();
        task_affinity_migrate_to_master();

        uint64_t this_node = PIR_t::nodeOrdinalFromPir(PIR_t(task_getcpuid()).word);

        task_affinity_unpin();

#ifdef CONFIG_BMC_IPMI
        // Run the watchdog with a longer expiration during the transition
        // into OPAL.
        errlHndl_t err_ipmi = IPMIWATCHDOG::setWatchDogTimer(
                IPMIWATCHDOG::DEFAULT_HB_OPAL_TRANSITION_COUNTDOWN);

        if(err_ipmi)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                            "init: ERROR: Set IPMI watchdog Failed");
                err_ipmi->collectTrace("ISTEPS_TRACE",256);
                errlCommit(err_ipmi, ISTEP_COMP_ID );
        }
#endif

        // broadcast shutdown to other HB instances.
        l_errl = broadcastShutdown(this_node);

        if(l_errl)
        {
            break;
        }
        //  - Run CXX testcases
        l_errl = INITSERVICE::executeUnitTests();

        if(l_errl)
        {
            break;
        }

        // calculate the memory location to be used as COMM base
        uint64_t l_commBase = RUNTIME::getHbBaseAddr() + PHYP_ATTN_AREA_OFFSET;

        //  - Call shutdown using payload base, and payload entry.
        //      - base/entry will be from system attributes
        //      - this will start the payload (Phyp)
        // NOTE: this call will not return if successful.
        l_errl = callShutdown(this_node, true, l_commBase);
        if(l_errl)
        {
            break;
        }

    }while(0);

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
                          bool i_isMaster,
                          const uint64_t i_commBase)
{
    errlHndl_t err = nullptr;
    uint64_t payloadBase = 0x0;
    uint64_t payloadEntry = 0x0;
    uint64_t payloadData = 0x0;
    bool istepModeFlag = false;
    uint64_t status = SHUTDOWN_STATUS_GOOD;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               ENTER_MRK"callShutdown()" );

    do
    {
        // Register event to be called on shutdown
        msg_q_t l_msgQ = msg_q_create();
        INITSERVICE::registerShutdownEvent(ISTEP_COMP_ID, l_msgQ,
                                      MSG_PRE_SHUTDOWN_INITS,
                                      INITSERVICE::PRESHUTDOWN_INIT_PRIORITY);
        // Create a task to handle the messages
        task_create(ISTEP_21::msg_handler, l_msgQ);

        // Unregister the AttrRP shutdown handler which synchronizes all
        // attributes at shutdown, as closing the SBE memory regions below will
        // cause all DMAs (and thus attribute sync) to fail.  Intentionally
        // ignore the response from unregister.  This API will get called on
        // all nodes.
        auto pAttrMsgQ = msg_q_resolve(TARGETING::ATTRRP_ATTR_SYNC_MSG_Q);
        INITSERVICE::unregisterShutdownEvent(pAttrMsgQ);

        // Tell SBE to Close All Unsecure Memory Regions
        err = SBEIO::closeAllUnsecureMemRegions();
        if (err)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       ERR_MRK "callShutdown: Failed SBEIO::closeAllUnsecureMemRegions" );
            break;
        }

        // Revert back to standard runtime mode where core checkstops
        // do not escalate to system checkstops
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "calling enableCoreCheckstops() in node");

        err = enableCoreCheckstops();

        if ( err )
        {
            break;
        }

        // Get Target Service, and the system target.
        TargetService& tS = targetService();
        TARGETING::Target* sys = nullptr;
        (void) tS.getTopLevelTarget( sys );

        if( nullptr == sys )
        {
            // Error getting system target to get payload related values.  We
            // will create an error to be passed back.  This will cause the
            // istep to fail.
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       ERR_MRK"System Target was NULL!" );

            /*@
             * @errortype
             * @reasoncode       RC_TARGET_NULL
             * @severity         ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid         MOD_START_PAYLOAD_CALL_SHUTDOWN
             * @userdata1        <UNUSED>
             * @userdata2        <UNUSED>
             * @devdesc          System target was NULL!
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                           MOD_START_PAYLOAD_CALL_SHUTDOWN,
                                           RC_TARGET_NULL,
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
        istepModeFlag = sys->getAttr<TARGETING::ATTR_ISTEP_MODE>();
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   INFO_MRK"Istep mode flag: %s",
                   ((istepModeFlag) ? "Enabled" : "Disabled") );

        // Get the Service Processor Functions
        TARGETING::SpFunctions spFuncs =
                sys->getAttr<TARGETING::ATTR_SP_FUNCTIONS>();

        // Open untrusted SP communication area if there is a PAYLOAD
        // NOTE: Must be after all HDAT processing
        if( !(TARGETING::is_no_load()) )
        {
            err = RUNTIME::openUntrustedSpCommArea(i_commBase);
            if (err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"callShutdown: Failed openUntrustedSpCommArea" );
                break;
            }
        }

        if(i_isMaster)
        {
            // Notify Fsp with appropriate mailbox message.
            err = notifyFsp( istepModeFlag,
                             spFuncs );

            if( err )
            {
                break;
            }
        }

        if ( is_sapphire_load() )
        {
            // opal load, Set the ATTN enable bit in the HID register
            uint64_t  l_enblAttnMask =
                    0x8000000000000000ull >> CPU_SPR_HID_EN_ATTN;

            uint64_t l_curHidVal =  cpu_spr_value( CPU_SPR_HID );
            uint64_t l_newHidVal = l_curHidVal | l_enblAttnMask;

            uint64_t rc = cpu_spr_set( CPU_SPR_HID, l_newHidVal);

            if ( rc == false )
            {
                // Error writing the SPR or
                // SPR is unsupported/restricted from being written
                // We will create an error to be passed back.
                // This will cause the istep to fail.
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"call_host_start_payload()::"
                                  "callShutdown() -"
                                  " Write of HID SPR failed" );

                /*@
                 * @errortype
                 * @reasoncode       RC_FAILED_WRITE_SPR
                 * @severity         ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM
                 * @moduleid         MOD_START_PAYLOAD_CALL_SHUTDOWN
                 * @userdata1        current value of HID
                 * @userdata2        write value attempted to HID
                 * @devdesc          Write of HID SPR failed
                 * @custdesc         A problem occurred during the IPL
                 *                   of the system.
                 */
                err =
                  new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                           MOD_START_PAYLOAD_CALL_SHUTDOWN,
                                           RC_FAILED_WRITE_SPR,
                                           l_curHidVal,
                                           l_newHidVal );

                err->collectTrace(ISTEP_COMP_NAME);

                break;
            }
        } // end opal load
        else
        {
            // PHYP load, do not enable ATTN
        }

        // Invalidate Hostboot load address across all (intentional) processors
        // so that FSP will not attempt a dump when the load address in the core
        // scratch register returns 0 (as happens during the shutdown).  The
        // update will take effect from FSP perspective when Hostboot
        // synchronizes its attributes down during the attribute resource
        // provider shutdown.
        TargetHandleList procs;
        (void)getAllChips(procs, TYPE_PROC,false);
        for(auto pProc : procs)
        {
            pProc->setAttr<TARGETING::ATTR_HB_HRMOR_BYTES>(
                KernelMemState::HbLoadAddrRsvd::NOT_APPLICABLE);
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

errlHndl_t broadcastShutdown ( uint64_t i_hbInstance )
{
    errlHndl_t err = nullptr;
    TARGETING::Target * sys = nullptr;
    TARGETING::targetService().getTopLevelTarget( sys );
    assert(sys != nullptr);

    TARGETING::ATTR_HB_EXISTING_IMAGE_type hb_images =
        sys->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();

    do
    {
        // First, save off the Payload's ATTN Area address into core scratch
        // reg0.
        uint64_t l_payloadAttnAreaAddr = 0;

        if(!TARGETING::is_no_load())
        {
            err = RUNTIME::getPayloadAttnAreaAddr(l_payloadAttnAreaAddr);
            if(err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                         "broadcastShutdown: could not get ATTN area address!");
                break;
            }

            // Save off the calculated Payload TI Area addr
            KernelMisc::g_payload_attn_area_addr =
                l_payloadAttnAreaAddr;
        }

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

        // calculate the memory location from the master node
        // hrmor value and send to slave nodes
        const uint64_t l_commBase = cpu_spr_value(CPU_SPR_HRMOR) +
                                    PHYP_ATTN_AREA_OFFSET;

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
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "start_payload-sending msg for drawer %d,"
                               "node %d, found existing HB images 0x%08x",
                               drawer, node, hb_images );
                    msg_t * msg = msg_allocate();
                    msg->type = IPC::IPC_START_PAYLOAD;
                    msg->data[0] = i_hbInstance;
                    msg->data[1] = l_commBase;
                    msg->extra_data =
                        reinterpret_cast<void*>(l_payloadAttnAreaAddr);
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


/**
 * @brief Re-enables the local core checkstop function
 */
errlHndl_t enableCoreCheckstops()
{
    errlHndl_t l_errl = nullptr;

/* FIXME RTC: 257487
    // If we're running on a PHYP system, we need
    // to switch back to running unit checkstops
    if(! is_sapphire_load() )
    {
        TARGETING::TargetHandleList l_coreTargetList;
        getAllChiplets(l_coreTargetList, TYPE_CORE);

        for( auto l_core_target : l_coreTargetList)
        {
            l_errl = HBPM::core_checkstop_helper_hwp( l_core_target,
                                                      false);

            if(l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "p9_core_checkup_handler_hwp ERROR : Returning "
                    "errorlog, reason=0x%x",l_errl->reasonCode() );

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_core_target).addToLog( l_errl );

                break;
            }
        }
    }
*/
    return l_errl;
}

//
// Notify the Fsp via Mailbox Message
//
errlHndl_t notifyFsp ( bool i_istepModeFlag,
                       TARGETING::SpFunctions i_spFuncs )
{
    errlHndl_t err = nullptr;

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


};
