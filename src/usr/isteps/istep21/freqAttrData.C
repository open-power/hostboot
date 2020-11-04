/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep21/freqAttrData.C $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
 * @file freqAttrSync.C
 * @brief Interrupt Resource Provider
 */

#include "freqAttrData.H"
#include <trace/interface.H>
#include <errno.h>
#include <initservice/taskargs.H>
#include <initservice/initserviceif.H>
#include <initservice/istepdispatcherif.H>
#include <initservice/isteps_trace.H>
#include <isteps/hwpisteperror.H>
#include <isteps/istep_reasoncodes.H>
#include <isteps/hwpf_reasoncodes.H>
#include <util/singleton.H>
#include <kernel/ipc.H>
#include <sys/task.h>
#include <vmmconst.h>
#include <targeting/common/targetservice.H>
#include <targeting/common/attributes.H>
#include <targeting/common/utilFilter.H>
#include <devicefw/userif.H>
#include <sys/time.h>
#include <sys/vfs.h>
#include <arch/ppc.H>
#include <mbox/ipc_msg_types.H>

/* FIXME RTC: 256840
#include <fapi2.H>
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
*/
#include <errl/errlreasoncodes.H>

#define INTR_TRACE_NAME INTR_COMP_NAME

using namespace TARGETING;
using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;

namespace ISTEP_21
{
void* sendFreqAttrData_timer(void* i_msgQPtr)

{
    int rc=0;

    msg_t* msg = msg_allocate();
    msg->type = HB_FREQ_ATTR_DATA_TIMER_MSG;
    uint32_t l_time_ms =0;

    msg_q_t* msgQ = static_cast<msg_q_t*>(i_msgQPtr);


    //this loop will be broken when the main thread receives
    //all the messages and the timer thread receives the
    //HB_FREQ_ATTR_DATA_MSG_DONE message

    do
    {

        if (l_time_ms < MAX_TIME_ALLOWED_MS)
        {
            msg->data[1] = CONTINUE_WAIT_FOR_MSGS;
        }
        else
        {
            // HB_FREQ_ATTR_DATA_TIMER_MSG is sent to the main thread indicating
            // timer expired so the main thread responds back with HB_FREQ_ATTR_DATA_MSG_DONE
            // indicating the timer is not needed and exit the loop
            msg->data[1]=TIME_EXPIRED;

        }

        rc= msg_sendrecv(*msgQ, msg);

        if (rc)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "sendFreqAttrData_timer failed msg sendrecv.");
        }
        if (msg->data[1] == HB_FREQ_ATTR_DATA_MSG_DONE)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "sendFreqAttrData_timer not needed.");
            break;
        }

        nanosleep(0,NS_PER_MSEC);
        l_time_ms++;

    }while(1);

    msg_free(msg);

    return NULL;
}

errlHndl_t sendFreqAttrData()
{
    errlHndl_t  l_elog = nullptr;
    tid_t l_progTid = 0;

    do {

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "sendFreqAttrData" );

        TARGETING::Target * sys = nullptr;

        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != nullptr);

        // Figure out which node we are running on
        TARGETING::Target* mproc = nullptr;

        TARGETING::targetService().masterProcChipTargetHandle(mproc);

        TARGETING::EntityPath epath = mproc->getAttr<TARGETING::ATTR_PHYS_PATH>();

        const TARGETING::EntityPath::PathElement pe =
          epath.pathElementOfType(TARGETING::TYPE_NODE);

        uint32_t nodeid = pe.instance;

        // ATTR_HB_EXISTING_IMAGE only gets set on a multi-drawer system.
        // Currently set up in host_sys_fab_iovalid_processing() which only
        // gets called if there are multiple physical nodes.   It eventually
        // needs to be setup by a hb routine that snoops for multiple nodes.
        TARGETING::ATTR_HB_EXISTING_IMAGE_type hb_images =
          sys->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "sendFreqAttrData hb_images = 0x%x, nodeid = 0x%x", hb_images, nodeid);

        if(0 == hb_images)
        {
            // Single node system
            break;
        }

        // multi-node system
        // This msgQ catches the node responses from the commands
        msg_q_t msgQ = msg_q_create();
        l_elog = MBOX::msgq_register(MBOX::HB_FREQ_ATTR_DATA_MSGQ,msgQ);
        if(l_elog)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "sendFreqAttrData MBOX::msgq_register failed!" );
            break;
        }

        // keep track of the number of messages we send so we
        // know how many responses to expect
        uint64_t msg_count = 0;
        freq_data freq_data_obj{0};

        // Fill in the frequency attribute data of master node
        // Copy the master node frequency data into two uint64_t
        // so that this data will be sent to the slaves using IPC below
        freq_data_obj.nominalFreq = sys->getAttr<ATTR_NOMINAL_FREQ_MHZ>();
        freq_data_obj.floorFreq = sys->getAttr<ATTR_MIN_FREQ_MHZ>();
        freq_data_obj.ceilingFreq = sys->getAttr<ATTR_FREQ_CORE_CEILING_MHZ>();
        freq_data_obj.ultraTurboFreq = sys->getAttr<ATTR_ULTRA_TURBO_FREQ_MHZ>();
        freq_data_obj.turboFreq = sys->getAttr<ATTR_FREQ_CORE_MAX>();
        freq_data_obj.nestFreq = sys->getAttr<ATTR_FREQ_PB_MHZ>();
        freq_data_obj.powerModeNom = mproc->getAttr<ATTR_SOCKET_POWER_NOMINAL>();
        freq_data_obj.powerModeTurbo = sys->getAttr<ATTR_SOCKET_POWER_TURBO>();

        // loop thru rest all nodes -- sending msg to each
        TARGETING::ATTR_HB_EXISTING_IMAGE_type mask = 0x1 <<
          ((sizeof(TARGETING::ATTR_HB_EXISTING_IMAGE_type) * 8) -1);

        for (uint32_t l_node=0; (l_node < MAX_NODES_PER_SYS ); l_node++ )
        {
            // skip sending to ourselves
            if(l_node == nodeid)
            {
                continue;
            }

            if( 0 != ((mask >> l_node) & hb_images ) )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "send IPC_FREQ_ATTR_DATA "
                           "message to node %d",l_node );


                msg_t * msg = msg_allocate();

                msg->type = IPC::IPC_FREQ_ATTR_DATA;

                // pack destination node and master node in msg->data[0]
                msg->data[0] = TWO_UINT32_TO_UINT64(l_node, nodeid);

                msg->data[1] = freq_data_obj.freqData1;

                msg->extra_data = reinterpret_cast<uint64_t*>(freq_data_obj.freqData2);

                // send the message to the slave hb instance
                l_elog = MBOX::send(MBOX::HB_IPC_MSGQ, msg, l_node);

                if( l_elog )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "MBOX::send to node %d"
                               " failed", l_node);
                    break;
                }

                ++msg_count;

            } // end if node to process
        } // end for loop on nodes

        if(l_elog)
        {
            break;
        }
        //wait for all hb images to respond
        //want to spawn a timer thread
        l_progTid = task_create(sendFreqAttrData_timer,&msgQ);

        assert( l_progTid > 0 ,"sendFreqAttrData_timer failed");

        while(msg_count)
        {
            msg_t* response = msg_wait(msgQ);

            if (response->type == HB_FREQ_ATTR_DATA_TIMER_MSG)
            {
                if (response->data[1] == TIME_EXPIRED)
                {
                    //timer has expired
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "IPC_FREQ_ATTR_DATA failed to "
                            "receive messages from all hb images in time" );
                    //tell the timer thread to exit
                    response->data[1] = HB_FREQ_ATTR_DATA_MSG_DONE;
                    msg_respond(msgQ,response);

                    // @Todo RTRC:192370 Add node specific info
                    // Include the number of nodes,  number of non-responses (bit masks)
                    // to know exactly which nodes didn't answer and which did

                    //generate an errorlog
                    /*@
                     *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
                     *  @moduleid       ISTEP::MOD_FREQ_ATTR_DATA,
                     *  @reasoncode     ISTEP::RC_FREQ_ATTR_TIMER_EXPIRED,
                     *  @userdata1      MAX_TIME_ALLOWED_MS
                     *  @userdata2      Number of nodes that have not
                     *                  responded
                     *
                     *  @devdesc        messages from other nodes have
                     *                  not returned in time
                     */
                    l_elog = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                    ISTEP::MOD_FREQ_ATTR_DATA,
                                    ISTEP::RC_FREQ_ATTR_TIMER_EXPIRED,
                                    MAX_TIME_ALLOWED_MS,
                                    msg_count   );
                    l_elog->collectTrace("ISTEPS_TRACE");
                    l_elog->collectTrace("IPC");
                    l_elog->collectTrace("MBOXMSG");

                    l_elog->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                             HWAS::SRCI_PRIORITY_HIGH);

                    // Break the While loop and wait for the child thread to exit
                    break;

                }
                else if( response->data[1] == CONTINUE_WAIT_FOR_MSGS)
                {
                    response->data[1] = HB_FREQ_ATTR_DATA_WAITING_FOR_MSG;
                    msg_respond(msgQ,response);
                }
            }
            else if (response->type == IPC::IPC_FREQ_ATTR_DATA)
            {
               TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                          "sendFreqAttrData Got response from node %d", response->data[0]>>32 );
                --msg_count;
                msg_free(response);
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "sendFreqAttrData_timer : unexpected message from drawer %d ",
                    response->data[0]>>32);
            }

        }

        if(l_elog)
        {
            break;
        }


        //the msg_count should be 0 at this point to have
        //exited from the loop above.  If the msg count
        //is not zero then the timer must have expired.
        //Now need to tell the child timer thread to exit

        //simics takes a long time for FLEETWOOD to IPL
        //A check to tell the child timer thread to exit if didn't
        //already timeout
        if (msg_count == 0)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "IPC_FREQ_ATTR_DATA msg_count: %d", msg_count);

            msg_t* response = msg_wait(msgQ);

            if (response->type == HB_FREQ_ATTR_DATA_TIMER_MSG)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "IPC_FREQ_ATTR_DATA received from all hb "
                        "images in time");

                response->data[1] = HB_FREQ_ATTR_DATA_MSG_DONE;
                msg_respond(msgQ,response);
            }
        }

        //wait for the child thread to end
        int l_childsts =0;
        void* l_childrc = NULL;
        tid_t l_tidretrc = task_wait_tid(l_progTid,&l_childsts,&l_childrc);
        if ((static_cast<int16_t>(l_tidretrc) < 0)
            || (l_childsts != TASK_STATUS_EXITED_CLEAN ))
        {
            // the launched task failed or crashed,
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "task_wait_tid failed; l_tidretrc=0x%x, l_childsts=0x%x",
                l_tidretrc, l_childsts);

                    //generate an errorlog
                    /*@
                     *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
                     *  @moduleid       ISTEP::MOD_FREQ_ATTR_DATA,
                     *  @reasoncode     ISTEP::RC_FREQ_ATTR_TIMER_THREAD_FAIL,
                     *  @userdata1      l_tidretrc,
                     *  @userdata2      l_childsts,
                     *
                     *  @devdesc        Freq attribute DATA timer thread
                     *                  failed
                     */
                    l_elog = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                    ISTEP::MOD_FREQ_ATTR_DATA,
                                    ISTEP::RC_FREQ_ATTR_TIMER_THREAD_FAIL,
                                    l_tidretrc,
                                    l_childsts);

                    l_elog->collectTrace("ISTEPS_TRACE");

                    l_elog->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                             HWAS::SRCI_PRIORITY_HIGH);

                    errlCommit(l_elog, HWPF_COMP_ID);

        }

        MBOX::msgq_unregister(MBOX::HB_FREQ_ATTR_DATA_MSGQ);
        msg_q_destroy(msgQ);

    } while(0);

    return(l_elog);
}

errlHndl_t callCheckFreqAttrData(uint64_t freqData1, uint64_t freqData2)
{
    TARGETING::Target * sys = nullptr;
    errlHndl_t  l_elog = nullptr;
    freq_data freq_data_obj{0};
    ISTEP_ERROR::IStepError l_stepError;
    uint16_t errCaseId = 0xFF;
    freq_data master_freq_data_obj{0};

    TARGETING::targetService().getTopLevelTarget( sys );
    assert(sys != nullptr);

    master_freq_data_obj.freqData1 = freqData1;
    master_freq_data_obj.freqData2 = freqData2;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "callCheckFreqAttrData - Mater Freq Data: 0x%016lx 0x%016lx",
               freqData1, freqData2);

    // Figure out which node we are running on
    TARGETING::Target* mproc = nullptr;
    TARGETING::targetService().masterProcChipTargetHandle(mproc);

    // Get the frequency attributes
    freq_data_obj.nominalFreq = sys->getAttr<TARGETING::ATTR_NOMINAL_FREQ_MHZ>();
    freq_data_obj.powerModeNom = mproc->getAttr<TARGETING::ATTR_SOCKET_POWER_NOMINAL>();
    freq_data_obj.powerModeTurbo = sys->getAttr<TARGETING::ATTR_SOCKET_POWER_TURBO>();

    freq_data_obj.floorFreq = sys->getAttr<TARGETING::ATTR_MIN_FREQ_MHZ>();
    freq_data_obj.ceilingFreq = sys->getAttr<TARGETING::ATTR_FREQ_CORE_CEILING_MHZ>();
    freq_data_obj.ultraTurboFreq = sys->getAttr<TARGETING::ATTR_ULTRA_TURBO_FREQ_MHZ>();
    freq_data_obj.turboFreq = sys->getAttr<TARGETING::ATTR_FREQ_CORE_MAX>();
    freq_data_obj.nestFreq = sys->getAttr<TARGETING::ATTR_FREQ_PB_MHZ>();


    do {

        // All of the buckets should report the same Power mode
        if((freq_data_obj.powerModeNom != master_freq_data_obj.powerModeNom )||
          (freq_data_obj.powerModeTurbo != master_freq_data_obj.powerModeTurbo ))
        {
            errCaseId = 0;
        }
        else if(freq_data_obj.nominalFreq != master_freq_data_obj.nominalFreq )
        {
            errCaseId = 1;
        }
        else if(freq_data_obj.floorFreq != master_freq_data_obj.floorFreq )
        {
            errCaseId = 2;
        }
        else if(freq_data_obj.ceilingFreq != master_freq_data_obj.ceilingFreq )
        {
            errCaseId = 3;
        }
        else if(freq_data_obj.ultraTurboFreq != master_freq_data_obj.ultraTurboFreq )
        {
            errCaseId = 4;
        }
        else if(freq_data_obj.turboFreq != master_freq_data_obj.turboFreq )
        {
            errCaseId = 5;
        }
        else if(freq_data_obj.nestFreq != master_freq_data_obj.nestFreq )
        {
            errCaseId = 6;
        }

        switch(errCaseId)
        {
            case 0:

                 TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "frequency attribute data MISMATCH! "
                    "expected PowerNom %d actual PowerMom %d "
                    "expected PowerTurbo %d actual PowerTurbo %d",
                    master_freq_data_obj.powerModeNom,
                    freq_data_obj.powerModeNom,
                    master_freq_data_obj.powerModeTurbo,
                    freq_data_obj.powerModeTurbo);


                //generate an errorlog
                /*@
                 * @errortype        ERRL_SEV_CRITICAL_SYS_TERM
                 * @moduleid         ISTEP::MOD_FREQ_ATTR_DATA,
                 * @reasoncode       ISTEP::RC_POWER_MODE_MISMATCH,
                 * @userdata1[00:31]  Master node nominal power mode
                 * @userdata1[32:63]  Current node nominal power mode
                 * @userdata2[00:31]  Master node turbo power mode
                 * @userdata2[32:63]  Current node turbo power mode
                 * @devdesc           Power Mode mismatch between drawers
                 * @custdesc          Incompatible processor modules
                 *                    installed between drawers.

                 */
                l_elog = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                ISTEP::MOD_FREQ_ATTR_DATA,
                                ISTEP::RC_POWER_MODE_MISMATCH,
                                TWO_UINT32_TO_UINT64(
                                   master_freq_data_obj.powerModeNom,
                                   freq_data_obj.powerModeNom),
                                TWO_UINT32_TO_UINT64(
                                   master_freq_data_obj.powerModeTurbo,
                                   freq_data_obj.powerModeTurbo), false);



            break;


            case 1:

             TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "nominal frequency data MISMATCH! "
                "expected Nominal %d actual Nominal %d ",
                master_freq_data_obj.nominalFreq,
                freq_data_obj.nominalFreq);


            //generate an errorlog
            /*@
             * @errortype        ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid         ISTEP::MOD_FREQ_ATTR_DATA,
             * @reasoncode       ISTEP::RC_NOMINAL_FREQ_MISMATCH,
             * @userdata1        Master node nominal frequency
             * @userdata2[00:31] Current node nominal frequency
             * @userdata2[32:63] Error category INVALID_PART
             * @devdesc          Nominal Mode mismatch between drawers
             * @custdesc         Incompatible processor modules
             *                   installed between drawers.

             */
            l_elog = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                            ISTEP::MOD_FREQ_ATTR_DATA,
                            ISTEP::RC_NOMINAL_FREQ_MISMATCH,
                            master_freq_data_obj.nominalFreq,
                            TWO_UINT32_TO_UINT64 (
                               freq_data_obj.nominalFreq,
                               HWAS::ERR_CATEGORY_INVALID_PART ), false);


            break;

            case 2:

             TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Floor frequency data MISMATCH! "
                "expected Floor Freq %d actual Floor Freq %d ",
                master_freq_data_obj.floorFreq,
                freq_data_obj.floorFreq);


            //generate an errorlog
            /*@
             * @errortype        ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid         ISTEP::MOD_FREQ_ATTR_DATA,
             * @reasoncode       ISTEP::RC_FLOOR_FREQ_MISMATCH,
             * @userdata1        Master node Floor frequency
             * @userdata2[00:31] Current node floor frequency
             * @userdata2[32:63] Error category INVALID_PART
             * @devdesc          Floor Freq mismatch between drawers
             * @custdesc         Incompatible processor modules
             *                   installed between drawers.

             */
            l_elog = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                            ISTEP::MOD_FREQ_ATTR_DATA,
                            ISTEP::RC_FLOOR_FREQ_MISMATCH,
                            master_freq_data_obj.floorFreq,
                            TWO_UINT32_TO_UINT64 (
                               freq_data_obj.floorFreq,
                               HWAS::ERR_CATEGORY_INVALID_PART ), false);


            break;

            case 3:

             TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Ceiling frequency data MISMATCH! "
                "expected Ceiling Freq %d actual Ceiling Freq %d ",
                master_freq_data_obj.ceilingFreq,
                freq_data_obj.ceilingFreq);


            //generate an errorlog
            /*@
             * @errortype        ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid         ISTEP::MOD_FREQ_ATTR_DATA,
             * @reasoncode       ISTEP::RC_CEIL_FREQ_MISMATCH,
             * @userdata1        Master node Ceil frequency
             * @userdata2[00:31] Current node Ceil frequency
             * @userdata2[32:63] Error category INVALID_PART
             * @devdesc          Ceil Freq mismatch between drawers
             * @custdesc         Incompatible processor modules
             *                   installed between drawers.

             */
            l_elog = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                            ISTEP::MOD_FREQ_ATTR_DATA,
                            ISTEP::RC_CEIL_FREQ_MISMATCH,
                            master_freq_data_obj.ceilingFreq,
                            TWO_UINT32_TO_UINT64 (
                               freq_data_obj.ceilingFreq,
                               HWAS::ERR_CATEGORY_INVALID_PART ), false);


            break;


            case 4:

             TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "UltraTurbo frequency data MISMATCH! "
                "expected UltraTurbo Freq %d actual UltraTurbo Freq %d ",
                master_freq_data_obj.ultraTurboFreq,
                freq_data_obj.ultraTurboFreq);


            //generate an errorlog
            /*@
             * @errortype        ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid         ISTEP::MOD_FREQ_ATTR_DATA,
             * @reasoncode       ISTEP::RC_ULTRA_TURBO_FREQ_MISMATCH,
             * @userdata1        Master node UltraTurbo frequency
             * @userdata2[00:31] Current node UltraTurbo frequency
             * @userdata2[32:63] Error category INVALID_PART
             * @devdesc          UltraTurbo Freq mismatch between drawers
             * @custdesc         Incompatible processor modules
             *                   installed between drawers.

             */
            l_elog = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                            ISTEP::MOD_FREQ_ATTR_DATA,
                            ISTEP::RC_ULTRA_TURBO_FREQ_MISMATCH,
                            master_freq_data_obj.ultraTurboFreq,
                            TWO_UINT32_TO_UINT64 (
                               freq_data_obj.ultraTurboFreq,
                               HWAS::ERR_CATEGORY_INVALID_PART ), false);


            break;

            case 5:

             TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Turbo frequency data MISMATCH! "
                "expected Turbo Freq %d actual Turbo Freq %d ",
                master_freq_data_obj.turboFreq,
                freq_data_obj.turboFreq);


            //generate an errorlog
            /*@
             * @errortype        ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid         ISTEP::MOD_FREQ_ATTR_DATA,
             * @reasoncode       ISTEP::RC_TURBO_FREQ_MISMATCH,
             * @userdata1        Master node Turbo frequency
             * @userdata2[00:31] Current node Turbo frequency
             * @userdata2[32:63] Error category INVALID_PART
             * @devdesc          Turbo Freq mismatch between drawers
             * @custdesc         Incompatible processor modules
             *                   installed between drawers.

             */
            l_elog = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                            ISTEP::MOD_FREQ_ATTR_DATA,
                            ISTEP::RC_TURBO_FREQ_MISMATCH,
                            master_freq_data_obj.turboFreq,
                            TWO_UINT32_TO_UINT64 (
                               freq_data_obj.turboFreq,
                               HWAS::ERR_CATEGORY_INVALID_PART ), false);


            break;

            case 6:

             TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Nest frequency data MISMATCH! "
                "expected Nest Freq %d actual Nest Freq %d ",
                master_freq_data_obj.nestFreq,
                freq_data_obj.nestFreq);


            //generate an errorlog
            /*@
             * @errortype        ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid         ISTEP::MOD_FREQ_ATTR_DATA,
             * @reasoncode       ISTEP::RC_NEST_FREQ_MISMATCH,
             * @userdata1        Master node Nest frequency
             * @userdata2[00:31] Current node Nest frequency
             * @userdata2[32:63] Error category INVALID_PART
             * @devdesc          Nest Freq mismatch between drawers
             * @custdesc         Incompatible processor modules
             *                   installed between drawers.

             */
            l_elog = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                            ISTEP::MOD_FREQ_ATTR_DATA,
                            ISTEP::RC_NEST_FREQ_MISMATCH,
                            master_freq_data_obj.nestFreq,
                            TWO_UINT32_TO_UINT64 (
                               freq_data_obj.nestFreq,
                               HWAS::ERR_CATEGORY_INVALID_PART ), false);


            break;

            default: // do nothing
            break;

        }
        if(errCaseId != 0xFF)
        {
            TargetHandleList procList;

            // Get the child proc chips
            getChildAffinityTargets(procList,
                                    sys,
                                    CLASS_CHIP,
                                    TYPE_PROC );
            for( const auto & proc : procList )
            {
                l_elog->addHwCallout(proc,
                                     HWAS::SRCI_PRIORITY_MEDA,
                                     HWAS::NO_DECONFIG,
                                     HWAS::GARD_NULL );
            }

            l_elog->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                        HWAS::SRCI_PRIORITY_LOW);

            l_elog->addProcedureCallout(HWAS::EPUB_PRC_INVALID_PART,
                                        HWAS::SRCI_PRIORITY_HIGH);

            l_elog->collectTrace("ISTEPS_TRACE");

            l_elog->addFFDC(ISTEP_COMP_ID,
                            &master_freq_data_obj,
                            sizeof(freq_data),
                            0,                   // Version
                            ERRL_UDT_CALLOUT,
                            false);

            l_elog->addFFDC(ISTEP_COMP_ID,
                            &freq_data_obj,
                            sizeof(freq_data),
                            0,                   // Version
                            ERRL_UDT_CALLOUT,
                            false);

            // Create IStep error log and
            // cross reference occurred error
            l_stepError.addErrorDetails( l_elog );
        }
    }while(0);

    return l_elog;

}

}
