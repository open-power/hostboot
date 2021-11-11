/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errlmanager.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
/**
 *  @file errlmanager.C
 *
 *  @brief Implementation of ErrlManager class
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errl/errlmanager.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <initservice/taskargs.H>
#include <sys/task.h>
#include <arch/ppc.H>
#include <stdlib.h>
#include <string.h>
#include <mbox/mbox_queues.H>
#include <mbox/mboxif.H>
#include <initservice/initserviceif.H>
#include <pnor/pnorif.H>
#include <sys/mm.h>
#include <arch/pirformat.H>
#include <errldisplay/errldisplay.H>
#include <console/consoleif.H>
#include <functional>
#include <hwas/common/deconfigGard.H>
#include <kernel/terminate.H>
#include <debugpointers.H>
#include <sys/sync.h>
#include <sys/time.h>
#include <time.h>

namespace ERRORLOG
{

// Declared in errlentry.C
extern std::map<uint8_t, const char *> errl_sev_str_map;

extern trace_desc_t* g_trac_errl;

// Store error logs in this memory buffer in L3 RAM.
char* g_ErrlStorage = new char[ ERRL_STORAGE_SIZE ];

// Allow Hidden error logs to be shown by default
uint8_t ErrlManager::iv_hiddenErrLogsEnable =
            TARGETING::HIDDEN_ERRLOGS_ENABLE_ALLOW_ALL_LOGS;

/**
* @brief
* In storage, the flattened error logs are interspersed with "markers."
* CBMARKER is the count of bytes in one marker.
* CB2MARKERS is the count of bytes in two markers.
*/
#define CBMARKER (sizeof(marker_t))
#define CB2MARKERS (2*sizeof(marker_t))

/**
* @brief OFFSET2MARKER()
* Convert an offset within the buffer to a marker_t pointer.
*/
#define OFFSET2MARKER(off) (reinterpret_cast<marker_t*>(&g_ErrlStorage[off]))

/**
* @brief POINTER2OFFSET()
* Convert a marker_t pointer to its offset within the buffer.
*/
#define POINTER2OFFSET(p) ((reinterpret_cast<char*>(p))-(g_ErrlStorage))

// Comparator function to check if a eid and a plid are equal
bool compareEidToPlid(const uint32_t i_plid,
                      const std::pair<errlHndl_t, uint8_t> i_pair)
{
    return (i_pair.first->eid() == i_plid);
}

class AtLoadFunctions
{
    public:
    AtLoadFunctions()
    {
        // call errlManager ctor so that we're ready and waiting for errors.
        ERRORLOG::theErrlManager::instance();
    }
};
// this causes the function to get run at module load.
AtLoadFunctions atLoadFunction;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlManager::ErrlManager() :
    iv_pnorReadyForErrorLogs(false),
    iv_recvdShutdownEvent(false),
    iv_hwasProcessCalloutFn(nullptr),
    iv_msgQ(nullptr),
    iv_pnorAddr(nullptr),
    iv_maxErrlInPnor(0),
    iv_pnorOpenSlot(0),
    iv_isFSP(true),  // queue msgs for fsp until we find we shouldn't
    iv_isMboxEnabled(false),    // assume mbox isn't ready yet..
    iv_nonInfoCommitted(false),
    iv_isErrlDisplayEnabled(false),
    iv_pldWaitEnable(true), // error on the side of caution and default to waitings
    iv_isBmcInterfaceEnabled(false)    // assume bmc interface isn't ready yet..
{
    TRACFCOMP( g_trac_errl, ENTER_MRK "ErrlManager::ErrlManager constructor" );

    // Put error logs in a 64KB buffer in memory
    // This buffer has a header (storage_header_t) followed by
    // storage.
    iv_pStorage = reinterpret_cast<storage_header_t*>(g_ErrlStorage);
    memset( iv_pStorage, 0, sizeof(storage_header_t));

    // Storage size is placed here for benefit of downstream parsers.
    iv_pStorage->cbStorage    = ERRL_STORAGE_SIZE;

    // Offsets are zero-based at &g_ErrlStorage[0],
    // so the first usable offset is just past the header.
    iv_pStorage->offsetMarker = sizeof(storage_header_t);
    iv_pStorage->offsetStart  = sizeof(storage_header_t);

    marker_t* l_pMarker = OFFSET2MARKER( iv_pStorage->offsetStart );
    l_pMarker->offsetNext = 0;
    l_pMarker->length     = 0;

    DEBUG::add_debug_pointer(DEBUG::ERRORLOGS,
                             &g_ErrlStorage,
                             4);

    // to determine the starting log ID, we need to do this in 2 steps
    // first, determine our node
    // BYTE 0 of the PLID is the ID: 0x9# where # is the node instance.
    //   [0..3] for hostboot on master proc (chip==0) on node [0..3]
    //   [4..7] for hostboot on alternate proc on node [0..3]

    const PIR_t masterCpu = task_getcpuid();
    int group_id = 0;
    int chip_id = 0;
    if (masterCpu.word == 0)
    {
        // Assume chip is group mode GGGC
        int groupMask = 0b1110; // extract GGG from GGGC
        int chipMask = 0b0001;  // extract C from GGGC

        group_id = (masterCpu.topologyId & groupMask) >> 1;
        chip_id = (masterCpu.topologyId & chipMask);
    }
    else
    {
        // Assume chip is node mode GGCC
        int groupMask = 0b1100; // extract GG from GGCC
        int chipMask = 0b0011;  // extract CC from GGCC

        group_id = (masterCpu.topologyId & groupMask) >> 2;
        chip_id = (masterCpu.topologyId & chipMask);
    }
    const uint32_t l_eid_id = (chip_id == 0) ?
                                    group_id :
                                    group_id + 4;

    iv_baseNodeId = ERRLOG_PLID_BASE + (l_eid_id << ERRLOG_PLID_NODE_SHIFT);
    iv_currLogId = iv_baseNodeId | ERRLOG_PLID_INITIAL;

    // next, we need to look thru PNOR and see what error records are there;
    //   ours will be 1 after the highest found.
    // BUT that can't happen until AFTER PNOR is up and running... so we'll do
    // that in the daemon. if PNOR reports an error, then the EID will just be
    // whatever it is.

    TRACFCOMP( g_trac_errl, INFO_MRK"ErrlManager on node %d (%smaster proc), LogId 0x%X",
        group_id, (chip_id == 0) ? "" : "alternate ",
        iv_currLogId);

    // Create and register error log message queue.
    msgQueueInit();

    // Startup the error log processing thread.
    task_create( ErrlManager::startup, this );

    TRACFCOMP( g_trac_errl, EXIT_MRK "ErrlManager::ErrlManager constructor." );
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlManager::~ErrlManager()
{
    TRACFCOMP( g_trac_errl, ENTER_MRK "ErrlManager::ErrlManager destructor" );

    // Singleton destructor gets run when module gets unloaded.
    // This errorlog module never gets unloaded. So rather to send a
    // message to error log daemon and tell it to shutdown and delete
    // the queue we will assert here because the destructor never gets
    // call.
    assert(0);

    TRACFCOMP( g_trac_errl, EXIT_MRK "ErrlManager::ErrlManager destructor." );
}

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::msgQueueInit()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::msgQueueInit ()
{
    TRACFCOMP( g_trac_errl, ENTER_MRK "ErrlManager::msgQueueInit ..." );

    // Create error log message queue.
    iv_msgQ = msg_q_create();

    // Register for error log manager shutdown event
    INITSERVICE::registerShutdownEvent( ERRL_COMP_ID,
                                        iv_msgQ,
                                        ERRLOG_SHUTDOWN_TYPE,
                                        INITSERVICE::NO_PRIORITY );

    TRACFCOMP( g_trac_errl, EXIT_MRK "ErrlManager::msgQueueInit" );
    return;
}

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::startup()
///////////////////////////////////////////////////////////////////////////////
void * ErrlManager::startup ( void* i_self )
{
    TRACFCOMP( g_trac_errl, ENTER_MRK "ErrlManager::startup..." );

    //Start a thread and let error log message handler running.
    reinterpret_cast<ErrlManager *>(i_self)->errlogMsgHndlr();

    TRACFCOMP( g_trac_errl, EXIT_MRK "ErrlManager::startup" );
    return nullptr;
}

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::pnorSetupThread()
///////////////////////////////////////////////////////////////////////////////
void * ErrlManager::pnorSetupThread ( void* i_self )
{
    TRACFCOMP( g_trac_errl, ENTER_MRK "ErrlManager::pnorSetupThread..." );

    //Start a thread to deal with PNOR setup
    reinterpret_cast<ErrlManager *>(i_self)->setupPnorInfo();

    TRACFCOMP( g_trac_errl, EXIT_MRK "ErrlManager::pnorSetupThread" );
    return nullptr;
}


///////////////////////////////////////////////////////////////////////////////
// ErrlManager::errlogMsgHndlr()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::errlogMsgHndlr ()
{
    TRACFCOMP( g_trac_errl, ENTER_MRK "Enter ErrlManager::errlogMsgHndlr" );

    task_detach();

    while( 1 )
    {
        msg_t * theMsg = msg_wait( iv_msgQ );
        TRACFCOMP( g_trac_errl, INFO_MRK"Got an error log Msg - Type: 0x%08x",
                                                               theMsg->type );

        // if we've been shut down then do nothing except delete the msg or send
        // a response depending on the message type.
        if(iv_recvdShutdownEvent)
        {
            TRACFCOMP( g_trac_errl, INFO_MRK "Error log service is shutdown. "
                                             "Message will be ignored.");
            switch( theMsg->type )
            {
                // Shutdown and flush message types expect a response
                case ERRLOG_SHUTDOWN_TYPE:
                case ERRLOG_FLUSH_TYPE:
                    msg_respond ( iv_msgQ, theMsg );
                    break;

                // All other messages just need to be freed
                default:
                    msg_free(theMsg);
                    break;
            }
            // wait for next message
            continue;
        }

        //Process message just received
        switch( theMsg->type )
        {
            case ERRLOG_ACCESS_PNOR_TYPE:
                {
                    // PNOR is up and running now.
                    // This can fail if there is bad ECC in HBEL (which is
                    // somewhat common on power faults).  Because of this,
                    // trigger this as separate task so message that kills
                    //task on bad ECC doesn't bring down the whole daemon
                    auto l_tid = task_create(ErrlManager::pnorSetupThread,
                                             this);

                    //  status of the task ( OK or Crashed )
                    int l_childsts    = 0;
                    auto l_tidretrc = task_wait_tid( l_tid, &l_childsts, 0);

                    if ((static_cast<int16_t>(l_tidretrc) < 0 ) ||
                        (l_childsts != TASK_STATUS_EXITED_CLEAN ))
                    {
                        TRACFCOMP(g_trac_errl, ERR_MRK "Failed to setup PNOR; l_tidretrc=0x%x,"
                                  " l_childsts=0x%x", l_tidretrc, l_childsts);
                        //Set iv_pnorAddr to nullptr to prevent writes
                        iv_pnorAddr = nullptr;
                    }

                    //We are done with the msg
                    msg_free(theMsg);

                    // go back and wait for a next msg
                    break;
                }
            case ERRLOG_ACCESS_TARG_TYPE:
                {
                    // TARGETING is up and running now.

                    //  do we NOT need to send the error?
                    TARGETING::Target * sys = nullptr;
                    TARGETING::targetService().getTopLevelTarget( sys );

                    // Cache current 'hidden error log enable' value for tracing
                    auto l_hiddenErrLogsEnableOldValue = iv_hiddenErrLogsEnable;

                    // set whether we want to skip certain error logs or not.
                    iv_hiddenErrLogsEnable =
                          sys->getAttr<TARGETING::ATTR_HIDDEN_ERRLOGS_ENABLE>();

                    TRACFCOMP( g_trac_errl, INFO_MRK
                    "ErrlManager::errlogMsgHndlr(ERRLOG_ACCESS_TARG_TYPE"
                    "(0x%02X)) - updating 'hidden error logs enable' "
                    "from 0x%02X to 0x%02X",
                    ERRLOG_ACCESS_TARG_TYPE,
                    l_hiddenErrLogsEnableOldValue,
                    iv_hiddenErrLogsEnable  );

                    TARGETING::SpFunctions spfn;

                    if (!(sys &&
                          sys->tryGetAttr<TARGETING::ATTR_SP_FUNCTIONS>(spfn) &&
                          spfn.baseServices))
                    {
                        iv_isFSP = false;

                        // if there are queued errors, clear the Mbox flag
                        // since they will never be sent, which will delete
                        // the errors that have been fully processed
                        ErrlListItr_t it = iv_errlList.begin();
                        while(it != iv_errlList.end())
                        {
                            // Mark MBOX processing complete
                            _clearFlag(*it, MBOX_FLAG);
                            _updateErrlListIter(it);
                        }
                    }

                    // If this isn't an FSP system, and we do not have PLD wait
                    // specifically disabled via the attribute ATTR_DISABLE_PLD_WAIT,
                    // then PLD waits are enabled.
                    iv_pldWaitEnable = !iv_isFSP && !sys->getAttr<TARGETING::ATTR_DISABLE_PLD_WAIT>();

                    //We are done with the msg
                    msg_free(theMsg);

                    // go back and wait for a next msg
                    break;
                }
            case ERRLOG_UPDATE_ATTRIB_VARS_TYPE:
                {
                    TARGETING::Target * sys(nullptr);
                    TARGETING::targetService().getTopLevelTarget( sys );

                    // Cache current 'hidden error log enable' value for tracing
                    auto l_hiddenErrLogsEnableOldValue = iv_hiddenErrLogsEnable;

                    // Refresh/update attribute vars
                    iv_hiddenErrLogsEnable =
                          sys->getAttr<TARGETING::ATTR_HIDDEN_ERRLOGS_ENABLE>();

                    TRACFCOMP( g_trac_errl, INFO_MRK
                    "ErrlManager::errlogMsgHndlr(ERRLOG_UPDATE_ATTRIB_VARS_TYPE"
                    "(0x%02X)) - updating 'hidden error logs enable' "
                    "from 0x%02X to 0x%02X",
                    ERRLOG_UPDATE_ATTRIB_VARS_TYPE,
                    l_hiddenErrLogsEnableOldValue,
                    iv_hiddenErrLogsEnable  );

                    // go back and wait for a next msg
                    break;
                }
            case ERRLOG_ACCESS_MBOX_TYPE:
                {
                    // MBOX is up and running now.

                    // do we need to send the errorlog
                    TARGETING::Target * sys = nullptr;
                    TARGETING::targetService().getTopLevelTarget( sys );
                    TARGETING::SpFunctions spfn;

                    if (sys &&
                        sys->tryGetAttr<TARGETING::ATTR_SP_FUNCTIONS>(spfn) &&
                        spfn.mailboxEnabled)
                    {
                        iv_isMboxEnabled = true;
                    }

                    // if we're supposed to and can now send msgs, do it.
                    if (iv_isFSP && iv_isMboxEnabled)
                    {
                        // Register messageQ with Mailbox to receive message.
                        errlHndl_t l_err =
                                MBOX::msgq_register( MBOX::HB_ERROR_MSGQ,
                                                    iv_msgQ );
                        if( l_err )
                        {
                            TRACFCOMP(g_trac_errl, ERR_MRK "Msg queue already registered");

                            delete( l_err );
                            l_err = nullptr;

                            //If we got an error then it means the message queue
                            //is registered with mailbox.
                            //This should not happen. So assert here.
                            assert(0);
                        }

                        // if errors came in before MBOX was ready,
                        // the errors would be on this list. send them now.
                        ErrlListItr_t it = iv_errlList.begin();
                        while(it != iv_errlList.end())
                        {
                            // Check if MBOX processing is needed
                            if (_isFlagSet(*it, MBOX_FLAG))
                            {
                                // send errlog
                                sendErrLogToFSP(it->first);
                                // Mark MBOX processing complete
                                _clearFlag(*it, MBOX_FLAG);
                            }
                            _updateErrlListIter(it);
                        }
                    }
                    else
                    {
                        // Delete errors that have been completely processed
                        ErrlListItr_t it = iv_errlList.begin();
                        while(it != iv_errlList.end())
                        {
                            // Mark MBOX processing complete
                            _clearFlag(*it, MBOX_FLAG);
                            _updateErrlListIter(it);
                        }
                    }

                    //We are done with the msg
                    msg_free(theMsg);

                    // go back and wait for a next msg
                    break;
                }
            case ERRLOG_ACCESS_BMC_TYPE:
                {
#ifdef CONFIG_PLDM
                    // BMC interface is up and running now.
                    iv_isBmcInterfaceEnabled = true;

                    // if we can now send msgs, do it.
                    // if errors came in before BMC interface was ready,
                    // the errors would be on this list. send them now.
                    ErrlListItr_t it = iv_errlList.begin();
                    while(it != iv_errlList.end())
                    {
                        // Check if BMC error log processing is needed
                        if (_isFlagSet(*it, BMC_FLAG))
                        {
                            // send errorlog
                            sendErrLogToBmc(it->first);
                            // Mark BMC processing complete
                            _clearFlag(*it, BMC_FLAG);
                        }
                        else if (_isFlagSet(*it, BMC_PREV_ERR_FLAG))
                        {
                            // send previous boot errorlog
                            sendErrLogToBmc(it->first, true);
                            // Mark BMC processing complete
                            _clearFlag(*it, BMC_PREV_ERR_FLAG);
                        }
                        _updateErrlListIter(it);
                    }
#endif

                    //We are done with the msg
                    msg_free(theMsg);

                    // go back and wait for a next msg
                    break;
                }
            case ERRLOG_ACCESS_ERRLDISP_TYPE:
                {
#ifdef CONFIG_CONSOLE_OUTPUT_ERRORDISPLAY
                    // Errldisplay now ready
                    iv_isErrlDisplayEnabled = true;
                    if(!iv_errlList.empty())
                    {
                        CONSOLE::displayf(CONSOLE::DEFAULT, "ERRL",
                        "Dumping errors reported prior to registration");
                    }
                    // Display errlogs to errldisplay
                    ErrlListItr_t it = iv_errlList.begin();
                    while(it != iv_errlList.end())
                    {
                        // Check if ERRLDISP processing is needed
                        if (_isFlagSet(*it, ERRLDISP_FLAG))
                        {
                            ERRORLOGDISPLAY::errLogDisplay().msgDisplay
                                        (it->first,
                                        ((it->first->reasonCode()) & 0xFF00));
                            // Mark ERRLDISP processing complete
                            _clearFlag(*it, ERRLDISP_FLAG);
                        }
                        _updateErrlListIter(it);
                    }
#endif
                    //We are done with the msg
                    msg_free(theMsg);
                    break;
                }
            case ERRLOG_NEEDS_TO_BE_COMMITTED_TYPE:
                {
                    // Extract error log handle from the message. We need the
                    // error log handle to pass along
                    errlHndl_t l_err = (errlHndl_t) theMsg->extra_data;

                    // If PLD waits are enabled and this log has a callout that
                    // could trigger a maintenance request,we have to allow
                    // time for the BMC to detect possible Power Line
                    // Disturbances before we process the log
                    if (iv_pldWaitEnable && l_err->hasMaintenanceCallout())
                    {
                        auto time_waited_ticks = getTB() - l_err->timeCreated();
                        timespec_t time_waited_mono;
                        TimeManager::convertTicksToSec(time_waited_ticks,
                                                      time_waited_mono.tv_sec,
                                                      time_waited_mono.tv_nsec);

                        if(time_waited_mono.tv_sec < MIN_PLD_WAIT_TIME_SEC)
                        {
                            // Ensure we have waited at least 10 seconds since
                            // the error log was created before we commit it.
                            nanosleep(MIN_PLD_WAIT_TIME_SEC - time_waited_mono.tv_sec, 0);
                        }
                    }

                    // Ask the ErrlEntry to assign commit component, commit time
                    l_err->commit( (compId_t) theMsg->data[0] );

                    // Pair with all flags set to add to the errlList
                    ErrlFlagPair_t l_pair(l_err, ALL_FLAGS);

#ifdef CONFIG_CONSOLE_OUTPUT_ERRORDISPLAY
                    // Display errl to errldisplay
                    if (iv_isErrlDisplayEnabled)
                    {
                        ERRORLOGDISPLAY::errLogDisplay().msgDisplay
                                            (l_err,
                                            ( (l_err->reasonCode()) & 0xFF00));
                        // Mark ERRLDISP processing complete on this error
                        _clearFlag(l_pair, ERRLDISP_FLAG);
                    }
#endif
                    //Save the error log to PNOR
                    bool l_savedToPnor = saveErrLogToPnor(l_err);

                    // Check if we actually saved the msg to PNOR
                    if (l_savedToPnor)
                    {
                        // Mark PNOR processing complete on this error
                        _clearFlag(l_pair, PNOR_FLAG);
                    }

                    //Write the error log to local memory
                    //useful ONLY for the hb-errl tool
                    saveErrLogEntry ( l_err );

                    //Try to send the error log if someone is there to receive
                    if (!iv_isFSP)
                    {
                        // Mark MBOX processing complete on this error
                        _clearFlag(l_pair, MBOX_FLAG);
                    }
                    else if (iv_isFSP && iv_isMboxEnabled)
                    {
                        sendErrLogToFSP(l_err);

                        // Mark MBOX processing complete on this error
                        _clearFlag(l_pair, MBOX_FLAG);
                    }

#ifdef CONFIG_PLDM
                    if (iv_isBmcInterfaceEnabled)
                    {
                        // send to BMC
                        sendErrLogToBmc(l_err);

                        // Mark BMC processing complete on this error
                        _clearFlag(l_pair, BMC_FLAG);
                    }
                    else
                    {
                        TRACFCOMP( g_trac_errl,
                            ERR_MRK"BMC interface down, cannot send EID[0x%08x] SEV[0x%02x]",
                            l_err->eid(), l_err->sev() );
                        l_err->traceLogEntry();
                    }
#endif

                    //Ask the ErrlEntry to process any callouts
                    l_err->processCallout();

                    //Ask if it is a terminating log
                    if( l_err->isTerminateLog() )
                    {
                        TRACFCOMP( g_trac_errl, INFO_MRK
                                   "Terminating error was committed"
                                   " errlmanager is reqesting a shutdown.");

                        INITSERVICE::doShutdown(l_err->eid(), true);

                        TRACDCOMP( g_trac_errl,
                                INFO_MRK"shutdown in progress" );
                    }

                    // If l_errl has not been fully proccessed delete it
                    // otherwise add to list
                    if (l_pair.second == 0)
                    {
                        delete l_err;
                        l_err = nullptr;
                    }
                    else
                    {
                        iv_errlList.push_back(l_pair);
                    }

                    //We are done with the msg
                    msg_free(theMsg);

                    // else go back and wait for a next msg
                    break;
                }
            case ERRLOG_COMMITTED_ACK_RESPONSE_TYPE:
                {
                    //Hostboot must keep track and clean up hostboot error
                    //logs in PNOR after it is committed by FSP.
                    uint32_t l_tmpPlid = theMsg->data[0]>>32;
                    TRACFCOMP( g_trac_errl, INFO_MRK"ack: %.8x", l_tmpPlid);

                    bool didAck = ackErrLogInPnor(l_tmpPlid);
                    if (!didAck)
                    {
                        // couldn't find that errlog in PNOR, look in our
                        // errlMsgList - maybe it's there waiting
                        ErrlListItr_t it = std::find_if(iv_errlList.begin(),
                                        iv_errlList.end(),
                                        std::bind1st(ptr_fun(&compareEidToPlid)
                                                             ,l_tmpPlid));
                        // Check if such errl was found
                        if (it != iv_errlList.end())
                        {
                            // We found the errlog
                            // Mark PNOR processing complete
                            _clearFlag(*it, PNOR_FLAG);
                            _updateErrlListIter(it);
                        }
                    }

                    msg_free(theMsg);

                    // We didn't have room before in PNOR to save an
                    // error log, so try now since we just ACKed one.
                    ErrlListItr_t it = std::find_if(iv_errlList.begin(),
                                        iv_errlList.end(),
                                        bind2nd(ptr_fun(_isFlagSet),
                                        PNOR_FLAG));

                    // Check if such errl was found
                    if (it != iv_errlList.end())
                    {
                        bool l_savedToPnor = saveErrLogToPnor(it->first);

                        // check if we actually saved the msg to PNOR
                        if (l_savedToPnor)
                        {
                            // Mark PNOR processing complete
                            _clearFlag(*it, PNOR_FLAG);
                            _updateErrlListIter(it);
                        }
                        // else, still couldn't save it (for some reason) so
                        // it's still on the list.
                    }
                    break;
                }
            case ERRLOG_FLUSH_TYPE:
                TRACFCOMP( g_trac_errl, INFO_MRK "Flush message received" );

                // Since the errorlog is FIFO, all we need to do is respond
                // to this message
                msg_respond ( iv_msgQ, theMsg );
                break;
            case ERRLOG_SHUTDOWN_TYPE:
                TRACFCOMP( g_trac_errl, INFO_MRK "Shutdown event received" );

                //Start shutdown process for error log
                errlogShutdown();

                // Respond that we are done shutting down.
                msg_respond ( iv_msgQ, theMsg );

                TRACFCOMP( g_trac_errl, INFO_MRK "Shutdown event processed" );

                break;

            default:
                // Default Message
                TRACFCOMP( g_trac_errl, ERR_MRK "Unexpected message type 0x%08x",
                                                                  theMsg->type );
                msg_free(theMsg);
                break;
        } // switch
    }

    //The errlogMsgHndlr should run all the time. It only
    //exits when error log message thread is killed.
    TRACFCOMP( g_trac_errl, EXIT_MRK "Exit ErrlManager::errlogMsgHndlr" );
    return;
}


///////////////////////////////////////////////////////////////////////////////
// ErrlManager::sendErrLogToFSP()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::sendErrLogToFSP ( errlHndl_t& io_err )
{
    msg_t *msg = nullptr;

    TRACFCOMP( g_trac_errl, ENTER_MRK"ErrlManager::sendErrLogToFSP" );
    do
    {
        //Create a mailbox message to send to FSP
        msg = msg_allocate();
        msg->type = ERRLOG_SEND_TO_FSP_TYPE;

        uint32_t l_msgSize = io_err->flattenedSize();

        //Data[0] will be hostboot error log ID so Hostboot can
        //keep track of the error log when FSP responses back.

        msg->data[0] = io_err->eid();
        msg->data[1] = l_msgSize;

        void * temp_buff = MBOX::allocate( l_msgSize );

        io_err->flatten ( temp_buff, l_msgSize );
        msg->extra_data = temp_buff;

        TRACDCOMP( g_trac_errl, INFO_MRK"Send msg to FSP for errlogId %.8x",
                                                               io_err->eid() );
        errlHndl_t l_err = MBOX::send( MBOX::FSP_ERROR_MSGQ, msg );
        if( !l_err )
        {
            // clear this - we're done with the message;
            // the receiver will free the storage when it's done
            msg = nullptr;
        }
        else
        {
           TRACFCOMP(g_trac_errl, ERR_MRK"Failed sending error log to FSP");

           //Free the extra data due to the error
           MBOX::deallocate( msg->extra_data );
           msg_free( msg );
           msg = nullptr;

           delete l_err;
           l_err = nullptr;
        }
    } while (0);

    TRACFCOMP( g_trac_errl, EXIT_MRK"ErrlManager::sendErrLogToFSP" );
} // sendErrLogToFSP

///////////////////////////////////////////////////////////////////////////////
//  Handling commit error log.
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::commitErrLog(errlHndl_t& io_err, compId_t i_committerComp )
{

    TRACDCOMP( g_trac_errl, ENTER_MRK"ErrlManager::commitErrLog" );
    do
    {
        if (io_err == nullptr)
        {
            // put out warning trace
            TRACFCOMP(g_trac_errl, ERR_MRK "commitErrLog() - nullptr pointer");
            break;
        }

        TRACFCOMP(g_trac_errl, "commitErrLog() called by %.4X for eid=%.8x, Reasoncode=%.4X, Sev=%s",
                  i_committerComp, io_err->eid(), io_err->reasonCode(), errl_sev_str_map.at(io_err->sev()) );

        if ( (io_err->sev() != ERRORLOG::ERRL_SEV_INFORMATIONAL) &&
             (io_err->sev() != ERRORLOG::ERRL_SEV_RECOVERED) )
        {
            iv_nonInfoCommitted = true;
            lwsync();
        }

        //Ask ErrlEntry to check for any special deferred deconfigure callouts
        io_err->deferredDeconfigure();

        // Is error flagged for doing HB Dump during a shutdown / TI?
        if (io_err->getDoHbDump() == true)
        {
            // Then set flag in TI data
            termSetHbDump();
        }

        //Offload the error log to the errlog message queue
        sendErrlogToMessageQueue ( io_err, i_committerComp );
        io_err = nullptr;

   } while( 0 );

   TRACDCOMP( g_trac_errl, EXIT_MRK"ErrlManager::commitErrLog" );

   return;
}

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::saveErrLogEntry()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::saveErrLogEntry( errlHndl_t& io_err )
{
    TRACDCOMP( g_trac_errl, ENTER_MRK"ErrlManager::saveErrLogEntry eid %.8x",
        io_err->eid());
    do
    {
        // Get flattened count of bytes.
        uint32_t l_cbActualFlat = io_err->flattenedSize();

        // Round this copy up to next nearest word (32-bit) boundary.
        uint32_t l_cbflat = ((l_cbActualFlat+3) & ~3);

        // Save/flatten the error log to the storage buffer.
        uint32_t l_extent = iv_pStorage->offsetMarker + CB2MARKERS + l_cbflat;

        if( l_extent < ERRL_STORAGE_SIZE)
        {
            // New data and its surrounding markers can fit between
            // the insertion point and the end of the storage buffer.
            // Flatten the data at the insertion point.
            marker_t * l_pMarker = OFFSET2MARKER( iv_pStorage->offsetMarker );
            io_err->flatten( l_pMarker+1, l_cbflat );
            l_pMarker->length = l_cbActualFlat;

            // Assign offset to next marker to this marker.
            l_pMarker->offsetNext=iv_pStorage->offsetMarker+CBMARKER+l_cbflat;

            // Save new insertion point in header.
            iv_pStorage->offsetMarker = l_pMarker->offsetNext;

            // Initialize the marker at the new insertion point.
            marker_t * pNew = OFFSET2MARKER( iv_pStorage->offsetMarker );
            pNew->offsetNext = 0;
            pNew->length = 0;
        }

        // Count of error logs called to commit, regardless if there was
        // room to commit them or not.
        iv_pStorage->cInserted++;

    } while( 0 );
    TRACDCOMP( g_trac_errl, EXIT_MRK"ErrlManager::saveErrLogEntry" );
    return;
}

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::callFlushErrorLogs()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::callFlushErrorLogs()
{
    ERRORLOG::theErrlManager::instance().flushErrorLogs();
    return;
}
///////////////////////////////////////////////////////////////////////////////
// ErrlManager::flushErrorLogs()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::flushErrorLogs()
{
    TRACDCOMP( g_trac_errl, ENTER_MRK "ErrlManager::flushErrorLogs" );

    // Create message to send to msg handler
    msg_t *msg = nullptr;
    msg = msg_allocate();
    msg->type = ERRLOG_FLUSH_TYPE;
    do{
        // Send message to msg handler, get msg back on l_RecvMsgQ
        int rc = msg_sendrecv(iv_msgQ,msg);

        // Always free the message since send/recv implies ownership
        msg_free(msg);
        msg=nullptr;

        if(rc)
        {
            TRACFCOMP(g_trac_errl, "Error sending error log flush message. "
                "RC= %d",rc);
            break;
        }
        // Msg_sendrecv doesn't return until the message has been responded
        // to. So we do not need to check message type back.
    }while(0);

    TRACDCOMP( g_trac_errl, EXIT_MRK"ErrlManager::flushErrorLogs" );
    return;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::setHwasProcessCalloutFn(HWAS::processCalloutFn i_fn)
{
    // sync to ensure that all of HWAS is fully constructed BEFORE we
    //  write this function pointer
    lwsync();
    ERRORLOG::theErrlManager::instance().iv_hwasProcessCalloutFn = i_fn;
}

void ErrlManager::errlResourceReady(errlManagerNeeds i_needs)
{
    ERRORLOG::theErrlManager::instance().sendResourcesMsg(i_needs);
    return;
}

void ErrlManager::sendResourcesMsg(errlManagerNeeds i_needs)
{
    TRACFCOMP( g_trac_errl, ENTER_MRK"ErrlManager::sendResourcesMsg %d", i_needs);

    //Create a message to send to Host boot error message queue.
    msg_t *msg = msg_allocate();

    switch (i_needs)
    {
        case PNOR:
            msg->type = ERRORLOG::ErrlManager::ERRLOG_ACCESS_PNOR_TYPE;
            break;
        case TARG:
            msg->type = ERRORLOG::ErrlManager::ERRLOG_ACCESS_TARG_TYPE;
            break;
        case MBOX:
            msg->type = ERRORLOG::ErrlManager::ERRLOG_ACCESS_MBOX_TYPE;
            break;
        case BMC:
            msg->type = ERRORLOG::ErrlManager::ERRLOG_ACCESS_BMC_TYPE;
            break;
        case ERRLDISP:
            msg->type = ERRORLOG::ErrlManager::ERRLOG_ACCESS_ERRLDISP_TYPE;
            break;
        case UPDATE_ATTRIB_VARS:
            msg->type = ERRORLOG::ErrlManager::ERRLOG_UPDATE_ATTRIB_VARS_TYPE;
            break;
        default:
        {
            TRACFCOMP( g_trac_errl, ERR_MRK "bad msg!!");
            assert(0);
        }
    }

    //Send the msg asynchronously to error message queue to handle.
    int rc = msg_send ( ERRORLOG::ErrlManager::iv_msgQ, msg );

    //Return code is non-zero when the message queue is invalid
    //or the message type is invalid.
    if ( rc )
    {
        TRACFCOMP( g_trac_errl, ERR_MRK "Failed (rc=%d) to send %d message.", rc, i_needs);
    }
    return;
}


bool ErrlManager::errlCommittedThisBoot()
{
    isync();
    return theErrlManager::instance().iv_nonInfoCommitted;
}


///////////////////////////////////////////////////////////////////////////////
// ErrlManager::sendErrlogToMessageQueue()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::sendErrlogToMessageQueue ( errlHndl_t& io_err,
                                             compId_t i_committerComp )
{
    msg_t  *  msg     = nullptr;

    TRACFCOMP( g_trac_errl, ENTER_MRK"ErrlManager::sendErrlogToMessageQueue" );

    do
    {
        //Create a message to send to Host boot error message queue.
        msg = msg_allocate();

        msg->type = ERRLOG_NEEDS_TO_BE_COMMITTED_TYPE;

        //Pass along the component id in the message
        msg->data[0] = i_committerComp;

        //Pass along the error log handle in the message
        msg->data[1] = 8;
        msg->extra_data = io_err;

        TRACFCOMP( g_trac_errl, INFO_MRK"Send an error log to message queue"
                                " to commit. eid=%.8X", io_err->eid() );

        //Send the error log to error message queue to handle.
        //Message is sent as asynchronous.
        int rc = msg_send ( iv_msgQ, msg );

        //Return code is non-zero when the message queue is invalid
        //or the message type is invalid.
        if ( rc )
        {
            TRACFCOMP( g_trac_errl, ERR_MRK "Failed to send mailbox message"
                       "to message queue. eid=%.8X", io_err->eid() );
            break;
        }

    } while (0);
    TRACFCOMP( g_trac_errl, EXIT_MRK"ErrlManager::sendErrlogToMessageQueue" );
    return;
} // sendErrlogToMessageQueue

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::errlogShutdown()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::errlogShutdown()
{
    // if there are errorlogs that didn't get fully processed, trace them
    // and clean up
    while (!iv_errlList.empty())
    {
        // Get errl and its flags
        ErrlFlagPair_t l_pair = iv_errlList.front();
        // If still true that means it was not processed

        TRACFCOMP(g_trac_errl, INFO_MRK "Failed to fully process Errl(eid %.8x) - Errl Flags Bitfield = 0x%X",
                    l_pair.first->eid(), l_pair.second);

        delete l_pair.first;
        l_pair.first = nullptr;
        // delete from the list
        iv_errlList.pop_front();
    } // while items on iv_errlList list

    // Un-register error log message queue from the shutdown
    INITSERVICE::unregisterShutdownEvent( iv_msgQ);

    if (iv_isMboxEnabled)
    {
        // Un-register error log message queue from the mailbox service
        MBOX::msgq_unregister( MBOX::HB_ERROR_MSGQ );
    }

    // Do not destroy the queue... there are paths where the daemon thread
    // still has references to the queue or the unregisterShutdownEvent did
    // not take effect because we were already in the middle of a system
    // shutdown.
    // Leaving this message queue around really isn't a leak because we are
    // shutting down.
    // msg_q_destroy(iv_msgQ);

    // Ensure that all the error logs are pushed out to PNOR
    // prior to the PNOR resource provider shutting down.
    PNOR::flush(PNOR::HB_ERRLOGS);

    // Remember that we have recieved the shutdown event
    iv_recvdShutdownEvent = true;

    return;
}

bool ErrlManager::_updateErrlListIter(ErrlListItr_t & io_it)
{
    bool l_removed = false;
    // Delete if this error has been fully processed (flags cleared)
    if (io_it->second == 0)
    {
        // Delete errl
        delete io_it->first;
        io_it->first = nullptr;
        io_it = iv_errlList.erase(io_it);
        l_removed = true;
    }
    else
    {
        ++io_it;
    }
    return l_removed;
}

} // End namespace
