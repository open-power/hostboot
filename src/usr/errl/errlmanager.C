/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errlmanager.C $                                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
 *  @file errlmanager.C
 *
 *  @brief Implementation of ErrlManager class
 */

#define STORE_ERRL_IN_L3

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errl/errlmanager.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <initservice/taskargs.H>
#include <sys/task.h>
#include <stdlib.h>
#include <string.h>
#include <mbox/mbox_queues.H>
#include <mbox/mboxif.H>
#include <initservice/initserviceif.H>
#include <pnor/pnorif.H>
#include <sys/mm.h>
#include <intr/interrupt.H>

namespace ERRORLOG
{

extern trace_desc_t* g_trac_errl;

#ifdef STORE_ERRL_IN_L3
// Store error logs in this memory buffer in L3 RAM.
char* g_ErrlStorage = new char[ ERRL_STORAGE_SIZE ];

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

#else

char* g_ErrlStorage;

#endif

const uint32_t PNOR_ERROR_LENGTH = 4096;
const uint32_t EMPTY_ERRLOG_IN_PNOR = 0xFFFFFFFF;

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
    iv_hwasProcessCalloutFn(NULL),
    iv_msgQ(NULL),
    iv_pnorAddr(NULL),
    iv_maxErrlInPnor(0),
    iv_pnorOpenSlot(0),
    iv_isSpBaseServices(true),  // queue msgs for fsp until we find we shouldnt
    iv_isMboxEnabled(false),    // but mbox isn't ready yet..
    iv_nonInfoCommitted(false)
{
    TRACFCOMP( g_trac_errl, ENTER_MRK "ErrlManager::ErrlManager constructor" );

#ifdef STORE_ERRL_IN_L3
    // Scaffolding.
    // For now, put error logs in a 64KB buffer in L3 RAM
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
#endif

    // to determine the starting log ID, we need to do this in 2 steps
    // first, determine our node
    // BYTE 0 of the PLID is the ID: 0x9# where # is the node instance.
    //   [0..3] for hostboot on master proc (chip==0) on node [0..3]
    //   [4..7] for hostboot on alternate proc on node [0..3]

    const INTR::PIR_t masterCpu = task_getcpuid();
    const uint32_t l_eid_id = (masterCpu.chipId == 0) ?
                                    masterCpu.nodeId :
                                    masterCpu.nodeId + 4;

    iv_currLogId = ERRLOG_PLID_BASE + ERRLOG_PLID_INITIAL +
                        (l_eid_id << ERRLOG_PLID_NODE_SHIFT);

    // next, we need to look thru PNOR and see what error records are there;
    //   ours will be 1 after the highest found.
    // BUT that can't happen until AFTER PNOR is up and running... so we'll do
    // that in the daemon. if PNOR reports an error, then the EID will just be
    // whatever it is.

    TRACFCOMP( g_trac_errl, INFO_MRK"ErrlManager on node %d (%smaster proc), LogId 0x%X",
        masterCpu.nodeId, (masterCpu.chipId == 0) ? "" : "alternate ",
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
    // message to error log daemon and tell it to shutdow and delete
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
    INITSERVICE::registerShutdownEvent( iv_msgQ, ERRLOG_SHUTDOWN_TYPE,
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
    return NULL;
}


///////////////////////////////////////////////////////////////////////////////
// ErrlManager::errlogMsgHndlr()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::errlogMsgHndlr ()
{
    TRACFCOMP( g_trac_errl, ENTER_MRK "Enter ErrlManager::errlogMsgHndlr" );

    while( 1 )
    {
        msg_t * theMsg = msg_wait( iv_msgQ );
        TRACFCOMP( g_trac_errl, INFO_MRK"Got an error log Msg - Type: 0x%08x",
                                                               theMsg->type );
        //Process message just received
        switch( theMsg->type )
        {
            case ERRLOG_ACCESS_PNOR_TYPE:
                {
                    // PNOR is up and running now.

                    setupPnorInfo();

                    //We are done with the msg
                    msg_free(theMsg);

                    // go back and wait for a next msg
                    break;
                }
            case ERRLOG_ACCESS_TARG_TYPE:
                {
                    // TARGETING is up and running now.

                    //  do we NOT need to send the error?
                    TARGETING::Target * sys = NULL;
                    TARGETING::targetService().getTopLevelTarget( sys );
                    TARGETING::SpFunctions spfn;

                    if (!(sys &&
                          sys->tryGetAttr<TARGETING::ATTR_SP_FUNCTIONS>(spfn) &&
                          spfn.baseServices))
                    {
                        iv_isSpBaseServices = false;

                        // if there are queued msgs, delete them
                        while (!iv_errlToSend.empty())
                        {
                            msg_t * msg = iv_errlToSend.front();
                            free( msg->extra_data );
                            msg_free( msg );
                            // delete from the list
                            iv_errlToSend.pop_front();
                        } // while items on iv_errlToSend list
                    }

                    //We are done with the msg
                    msg_free(theMsg);

                    // go back and wait for a next msg
                    break;
                }
            case ERRLOG_ACCESS_MBOX_TYPE:
                {
                    // MBOX is up and running now.

                    // do we need to send the errorlog
                    TARGETING::Target * sys = NULL;
                    TARGETING::targetService().getTopLevelTarget( sys );
                    TARGETING::SpFunctions spfn;

                    if (sys &&
                        sys->tryGetAttr<TARGETING::ATTR_SP_FUNCTIONS>(spfn) &&
                        spfn.mailboxEnabled)
                    {
                        iv_isMboxEnabled = true;
                    }

                    // if we're supposed to and can now send msgs, do it.
                    if (iv_isSpBaseServices && iv_isMboxEnabled)
                    {
                        // Register messageQ with Mailbox to receive message.
                        errlHndl_t l_err =
                                MBOX::msgq_register( MBOX::HB_ERROR_MSGQ,
                                                    iv_msgQ );
                        if( l_err )
                        {
                            TRACFCOMP(g_trac_errl, ERR_MRK "Msg queue already registered");

                            delete( l_err );
                            l_err = NULL;

                            //If we got an error then it means the message queue
                            //is registered with mailbox.
                            //This should not happen. So assert here.
                            assert(0);
                        }

                        // if error(s) came in before MBOX was ready,
                        // the msg(s) would be on this list. send it now.
                        while (!iv_errlToSend.empty())
                        {
                            msg_t * msg = iv_errlToSend.front();

                            l_err = MBOX::send( MBOX::FSP_ERROR_MSGQ, msg );
                            if( l_err )
                            {
                               TRACFCOMP(g_trac_errl, ERR_MRK "Failed sending error log to FSP");

                               //Free the extra data due to the error
                               free( msg->extra_data );
                               msg_free( msg );

                               delete l_err;
                               l_err = NULL;
                            }

                            // delete from the list
                            iv_errlToSend.pop_front();
                        } // while items on list
                    }
                    else
                    {
                        // if there are queued msgs, delete them
                        while (!iv_errlToSend.empty())
                        {
                            msg_t * msg = iv_errlToSend.front();
                            free( msg->extra_data );
                            msg_free( msg );
                            // delete from the list
                            iv_errlToSend.pop_front();
                        } // while items on iv_errlToSend list
                    }

                    //We are done with the msg
                    msg_free(theMsg);

                    // go back and wait for a next msg
                    break;
                }
            case ERRLOG_NEEDS_TO_BE_COMMITTED_TYPE:
                {
                    //Extract error log handle from the message. We need the
                    // error log handle to pass along to saveErrLogEntry and
                    // sendErrLogToMbox
                    errlHndl_t l_err = (errlHndl_t) theMsg->extra_data;

                    //Ask the ErrlEntry to assign commit component, commit time
                    l_err->commit( (compId_t) theMsg->data[0] );

                    //Save the error log to PNOR
                    bool l_savedToPnor = saveErrLogToPnor(l_err);

#ifdef STORE_ERRL_IN_L3
                    //Write the error log to L3 memory
                    //useful ONLY for the hb-errl tool
                    saveErrLogEntry ( l_err );
#endif

                    //Try to send the error log if someone is there to receive
                    if (iv_isSpBaseServices)
                    {
                        msg_t *l_sentToMbox = sendErrLogToMbox ( l_err );
                        if (l_sentToMbox != NULL)
                        {
                            // we were supposed to send it and couldn't;
                            // save it on the queue.
                            iv_errlToSend.push_back(l_sentToMbox);
                        }
                    }

                    //Ask the ErrlEntry to process any callouts
                    l_err->processCallout();

                    //Ask if it is a terminating log
                    if( l_err->isTerminateLog() )
                    {
                        TRACFCOMP( g_trac_errl, INFO_MRK
                                   "Terminating error was commited"
                                   " errlmanager is reqesting a shutdown.");

                        INITSERVICE::doShutdown(l_err->plid(), true);

                        TRACDCOMP( g_trac_errl,
                                INFO_MRK"shutdown in progress" );
                    }

                    // check if we actually saved the msg to PNOR
                    if (l_savedToPnor)
                    {
                        //done with the error log handle so delete it.
                        delete l_err;
                        l_err = NULL;
                    }
                    else
                    {   // save didn't work - push into a list to do when
                        //  the next ACK gets processed.
                        iv_errlToSave.push_back(l_err);
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
                        // ToSave list - maybe it's there waiting
                        for (std::list<errlHndl_t>::iterator
                            it = iv_errlToSave.begin();
                            it != iv_errlToSave.end();
                            it++)
                        {
                            errlHndl_t l_err = *it;
                            if (l_err->eid() == l_tmpPlid)
                            {
                                // we found it
                                // done with the error log handle so delete it.
                                delete l_err;
                                l_err = NULL;

                                // delete from the list
                                iv_errlToSave.erase(it);

                                // break out of the for loop - we're done
                                break;
                            }
                        } // for
                    }

                    msg_free(theMsg);

                    if (!iv_errlToSave.empty())
                    {
                        //we didn't have room before in PNOR to save an
                        // error log, so try now since we just ACKed one.
                        errlHndl_t l_err = iv_errlToSave.front();

                        bool l_savedToPnor = saveErrLogToPnor(l_err);

                        // check if we actually saved the msg to PNOR
                        if (l_savedToPnor)
                        {   // if so, we're done - clean up

                            //done with the error log handle so delete it.
                            delete l_err;
                            l_err = NULL;

                            // delete from the list
                            iv_errlToSave.pop_front();
                        }
                        // else, still couldn't save it (for some reason) so
                        // it's still on the list.
                    }
                    break;
                }
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
// ErrlManager::sendErrLogToMbox()
///////////////////////////////////////////////////////////////////////////////
msg_t *ErrlManager::sendErrLogToMbox ( errlHndl_t& io_err )
{
    msg_t *msg = NULL;

    TRACFCOMP( g_trac_errl, ENTER_MRK"ErrlManager::sendErrLogToMbox" );
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

        void * temp_buff = malloc( l_msgSize );
        io_err->flatten ( temp_buff, l_msgSize );
        msg->extra_data = temp_buff;

        TRACDCOMP( g_trac_errl, INFO_MRK"Send msg to FSP for errlogId %.8x",
                                                               io_err->eid() );

        if (iv_isMboxEnabled)
        {
            errlHndl_t l_err = MBOX::send( MBOX::FSP_ERROR_MSGQ, msg );
            if( !l_err )
            {
                // clear this - we're done with the message;
                // the receiver will free the storage when it's done
                msg = NULL;
            }
            else
            {
               TRACFCOMP(g_trac_errl, ERR_MRK"Failed sending error log to FSP");

               //Free the extra data due to the error
               free( msg->extra_data );
               msg_free( msg );
               msg = NULL;

               delete l_err;
               l_err = NULL;
            }
        }
        // else, we created the msg, but couldn't send it - return it so that
        // it can be saved and sent later when the MBOX is up.
    } while (0);

    TRACFCOMP( g_trac_errl, EXIT_MRK"sendErrLogToMbox() returning %p", msg);
    return msg;
} // sendErrLogToMbox

///////////////////////////////////////////////////////////////////////////////
//  Handling commit error log.
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::commitErrLog(errlHndl_t& io_err, compId_t i_committerComp )
{

    TRACDCOMP( g_trac_errl, ENTER_MRK"ErrlManager::commitErrLog" );
    do
    {
        if (io_err == NULL)
        {
            // put out warning trace
            TRACFCOMP(g_trac_errl, ERR_MRK "commitErrLog() - NULL pointer");
            break;
        }

        TRACFCOMP(g_trac_errl, "commitErrLog() called by %.4X for eid=%.8x, Reasoncode=%.4X",
                    i_committerComp, io_err->eid(), io_err->reasonCode() );

        if (io_err->sev() != ERRORLOG::ERRL_SEV_INFORMATIONAL)
        {
            iv_nonInfoCommitted = true;
            lwsync();
        }

        //Ask ErrlEntry to check for any special deferred deconfigure callouts
        io_err->deferredDeconfigure();

        //Offload the error log to the errlog message queue
        sendErrlogToMessageQueue ( io_err, i_committerComp );
        io_err = NULL;

   } while( 0 );

   TRACDCOMP( g_trac_errl, EXIT_MRK"ErrlManager::commitErrLog" );

   return;
}

#ifdef STORE_ERRL_IN_L3
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
#endif


///////////////////////////////////////////////////////////////////////////////
// Atomically increment log id and return it.
uint32_t ErrlManager::getUniqueErrId()
{
    return (__sync_add_and_fetch(&iv_currLogId, 1));
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

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Global function (not a method on an object) to commit the error log.
void errlCommit(errlHndl_t& io_err, compId_t i_committerComp )
{
    ERRORLOG::theErrlManager::instance().commitErrLog(io_err, i_committerComp );
    return;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Global function (not a method on an object) to commit the error log.
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
    msg_t  *  msg     = NULL;

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
}

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::errlogShutdown()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::errlogShutdown()
{
    // if there are errorlogs that didn't get sent via the MBOX to FSP,
    //  trace them and clean up
    while (!iv_errlToSend.empty())
    {
        msg_t * msg = iv_errlToSend.front();
        TRACDCOMP(g_trac_errl, INFO_MRK "Failed to send to FSP: eid %.8x",
                msg->data[0]);
        free( msg->extra_data );
        msg_free( msg );
        // delete from the list
        iv_errlToSend.pop_front();
    } // while items on iv_errlToSend list

    // if there are errorlogs that didn't get stored in PNOR,
    //  trace them and clean up
    while (!iv_errlToSave.empty())
    {
        errlHndl_t l_err = iv_errlToSave.front();
        TRACFCOMP(g_trac_errl, ERR_MRK "Failed to store to PNOR: eid %.8x",
                l_err->eid());
        delete l_err;
        // delete from the list
        iv_errlToSave.pop_front();
    } // while items on iv_errlToSave list

    // Ensure that all the error logs are pushed out to PNOR
    // prior to the PNOR resource provider shutting down.
    int l_rc = mm_remove_pages(FLUSH, (void *) iv_pnorAddr,
                    iv_maxErrlInPnor * PNOR_ERROR_LENGTH);
    if( l_rc )
    {
        //If mm_remove_pages returns none zero for error then
        //log an error trace in this case.
        TRACFCOMP(g_trac_errl, ERR_MRK "Fail to flush the page %p size %d",
                iv_pnorAddr, iv_maxErrlInPnor * PNOR_ERROR_LENGTH);
    }

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

    return;
}

// ------------------------------------------------------------------
// setupPnorInfo
// ------------------------------------------------------------------
void ErrlManager::setupPnorInfo()
{
    TRACFCOMP( g_trac_errl, ENTER_MRK"setupPnorInfo" );

    do
    {
        // Get SPD PNOR section info from PNOR RP
        PNOR::SectionInfo_t info;
        errlHndl_t err = PNOR::getSectionInfo( PNOR::HB_ERRLOGS, info );

        if (err)
        {
            TRACFCOMP( g_trac_errl, INFO_MRK"setupPnorInfo getSectionInfo failed");
            assert(err == NULL);
            break;
        }

        TRACFCOMP( g_trac_errl, INFO_MRK"setupPnorInfo sectionInfo id %d name \"%s\" size %d",
                info.id, info.name, info.size );

        // Set the globals appropriately
        iv_pnorAddr = reinterpret_cast<char *> (info.vaddr);
        iv_maxErrlInPnor = info.size / PNOR_ERROR_LENGTH;

        TRACFCOMP( g_trac_errl, INFO_MRK"setupPnorInfo iv_pnorAddr %p maxErrlInPnor %d",
                iv_pnorAddr, iv_maxErrlInPnor );

        // initial value, in case PNOR is empty - start at this end slot
        // so that our first save will increment and wrap correctly
        iv_pnorOpenSlot = (iv_maxErrlInPnor - 1);

        // walk thru memory, finding error logs and determine the highest ID
        uint32_t l_maxId = 0;
        for (uint32_t i = 0; i < iv_maxErrlInPnor; i++)
        {
            if (!isSlotEmpty(i))
            {
                uint32_t l_eid = readEidFromFlattened(i);
                if (l_eid > l_maxId )
                {
                    l_maxId = l_eid;

                    // set this - start at this 'max' slot so that our first
                    // save will increment correctly
                    iv_pnorOpenSlot = i;
                }
                // also check if it's ACKed or not. and ACK it.
                // for FSP system, this shouldn't ever happen.
                // for non-FSP systems, this clears out all 'last IPL' logs
                if (!isSlotACKed(i))
                {
                    TRACFCOMP( g_trac_errl, INFO_MRK"setupPnorInfo slot %d eid %.8X was not ACKed.",
                        i, l_eid);
                    setACKInFlattened(i);
                } // not ACKed
            } // not empty
        } // for

        // bump the current eid to 1 past the max eid found
        while (!__sync_bool_compare_and_swap(&iv_currLogId, iv_currLogId,
                    (iv_currLogId & ERRLOG_PLID_BASE_MASK) +
                    (l_maxId & ERRLOG_PLID_MASK) + 1));
        TRACFCOMP( g_trac_errl, INFO_MRK"setupPnorInfo reseting LogId 0x%X", iv_currLogId);

        // if error(s) came in before PNOR was ready,
        // the error log(s) would be on this list. save now.
        while (!iv_errlToSave.empty())
        {
            errlHndl_t l_err = iv_errlToSave.front();

            //ACK it if no one is there to receive
            bool l_savedToPnor = saveErrLogToPnor(l_err);

            // check if we actually saved the msg to PNOR
            if (l_savedToPnor)
            {   // if so, we're done - clean up

                //done with the error log handle so delete it.
                delete l_err;
                l_err = NULL;

                // delete from the list
                iv_errlToSave.pop_front();
            }
            else
            {
                // still couldn't save it (PNOR maybe full) so
                // it's still on the list.
                break; // get out of this while loop.
            }
        } // while entries on list

    } while (0);

    TRACFCOMP( g_trac_errl, EXIT_MRK"setupPnorInfo");
} // setupPnorInfo

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::incrementPnorOpenSlot()
///////////////////////////////////////////////////////////////////////////////
bool ErrlManager::incrementPnorOpenSlot()
{
    uint32_t initialSlot = iv_pnorOpenSlot; // starting slot
    do
    {
        iv_pnorOpenSlot++;
        if (iv_pnorOpenSlot == iv_maxErrlInPnor)
        {   // wrap
            iv_pnorOpenSlot = 0;
        }
    } while (   !isSlotEmpty(iv_pnorOpenSlot) &&
                !isSlotACKed(iv_pnorOpenSlot) &&
                (iv_pnorOpenSlot != initialSlot));

    // if we got a different slot, return true; else false - no open slots
    return (iv_pnorOpenSlot != initialSlot);
} // incrementPnorOpenSlot

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::saveErrLogToPnor()
///////////////////////////////////////////////////////////////////////////////
bool ErrlManager::saveErrLogToPnor( errlHndl_t& io_err)
{
    TRACFCOMP( g_trac_errl, ENTER_MRK"saveErrLogToPnor eid=%.8x", io_err->eid());
    bool rc = false;

    // actually, if it's an INFORMATIONAL log, we don't want to waste the write
    // cycles, so we'll just 'say' that we saved it and go on.
    if (io_err->sev() == ERRORLOG::ERRL_SEV_INFORMATIONAL)
    {
        TRACDCOMP( g_trac_errl, INFO_MRK"saveErrLogToPnor: INFORMATIONAL log, skipping");
        rc = true;
    }
    else
    {
        // save our current slot, and see if there's an open slot
        uint32_t l_previousSlot = iv_pnorOpenSlot;  // in case flatten fails

        if ((iv_pnorAddr != NULL) && incrementPnorOpenSlot())
        {
            // flatten into PNOR, truncate to the slot size
            char *l_pnorAddr =
                iv_pnorAddr + (PNOR_ERROR_LENGTH * iv_pnorOpenSlot);
            TRACDBIN( g_trac_errl, INFO_MRK"saveErrLogToPnor: l_pnorAddr before",
                l_pnorAddr, 128);
            uint64_t l_errSize = io_err->flatten(l_pnorAddr,
                                    PNOR_ERROR_LENGTH, true);
            if (l_errSize !=0)
            {
                TRACFCOMP( g_trac_errl, INFO_MRK"saveErrLogToPnor: %d bytes flattened into %p, slot %d",
                    l_errSize, l_pnorAddr, iv_pnorOpenSlot );

                TRACDBIN( g_trac_errl, INFO_MRK"saveErrLogToPnor: l_pnorAddr after",
                    l_pnorAddr, 128);

                // Ensure that this error log is pushed out to PNOR
                int l_rc = mm_remove_pages(FLUSH,
                                (void *) l_pnorAddr, l_errSize);
                if( l_rc )
                {
                    //If mm_remove_pages returns none zero for error then
                    //log an error trace in this case.
                    TRACFCOMP(g_trac_errl, ERR_MRK "Fail to flush the page %p size %d",
                            l_pnorAddr, PNOR_ERROR_LENGTH);
                }
            }
            else
            {
                // flatten didn't work, so still return true - we don't want
                // to try to save this errlog.

                TRACFCOMP( g_trac_errl, ERR_MRK"saveErrLogToPnor: could not flatten data");
                // restore slot so that our next save will find this slot
                iv_pnorOpenSlot = l_previousSlot;
            }
            rc = true;
        }
        // else no open slot - return false
    }

    TRACFCOMP( g_trac_errl, EXIT_MRK"saveErrLogToPnor returning %s",
            rc ?  "true" : "false");
    return rc;
} // saveErrLogToPnor

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::ackErrLogInPnor()
///////////////////////////////////////////////////////////////////////////////
bool ErrlManager::ackErrLogInPnor( uint32_t i_errEid )
{
    TRACFCOMP( g_trac_errl, ENTER_MRK"ackErrLogInPnor(%.8x)", i_errEid);
    bool rc = true;

    // look for an un-ACKed log that matches this eid
    uint32_t i;
    for (i = 0; i < iv_maxErrlInPnor; i++)
    {
        if (!isSlotEmpty(i) && !isSlotACKed(i))
        {
            uint32_t l_eid = readEidFromFlattened(i);
            if (l_eid == i_errEid)
            {
                TRACDCOMP( g_trac_errl, INFO_MRK"ackErrLogInPnor: match in slot %d", i);
                setACKInFlattened(i);
                break;
            }
        }
    } // for

    // if we made it through the loop w/out breaking early
    if (i == iv_maxErrlInPnor)
    {
        //could not find the errorlog to mark for acknowledgment
        TRACDCOMP( g_trac_errl, ERR_MRK"ackErrLogInPnor failed to find the error log" );
        rc = false;
    }

    TRACFCOMP( g_trac_errl, EXIT_MRK"ackErrLogInPnor returning %s",
            rc ? "true" : "false");
    return rc;
} // ackErrLogInPnor


bool ErrlManager::isSlotEmpty(uint32_t i_position)
{
    // checks the first word of the flattened errlog, which should be a
    //  pelsectionheader - which will NEVER be 0xFFFFFFFF if it's valid.
    char * l_pnorAddr = iv_pnorAddr + (PNOR_ERROR_LENGTH * i_position);
    bool rc = (memcmp(l_pnorAddr, &EMPTY_ERRLOG_IN_PNOR, sizeof(uint32_t))
                    == 0);
    TRACDCOMP( g_trac_errl, "isSlotEmpty: slot %d @ %p is %s",
        i_position, l_pnorAddr, rc ? "empty" : "not empty");
    return rc;
}

// readEidFromFlattened()
// i_position MUST be valid errlog (not EMPTY_ERRLOG_IN_PNOR)
uint32_t ErrlManager::readEidFromFlattened(uint32_t i_position)
{
    const char * l_pnorAddr = iv_pnorAddr + (PNOR_ERROR_LENGTH * i_position);
    const pelPrivateHeaderSection_t *pPH =
            reinterpret_cast<const pelPrivateHeaderSection_t *>(l_pnorAddr);
    TRACDCOMP(g_trac_errl, "readEid(%d): eid %.8x", i_position, pPH->eid);

    return pPH->eid;
}

// isSlotACKed()
// i_position MUST be valid errlog (not EMPTY_ERRLOG_IN_PNOR)
bool ErrlManager::isSlotACKed(uint32_t i_position)
{
    const char * l_pnorAddr = iv_pnorAddr + (PNOR_ERROR_LENGTH * i_position);
    l_pnorAddr += sizeof(pelPrivateHeaderSection_t);
    l_pnorAddr += sizeof(pelUserHeaderSection_t);
    const pelSRCSection_t *pSRC =
            reinterpret_cast<const pelSRCSection_t *>(l_pnorAddr);

    TRACDCOMP(g_trac_errl, "isSlotACKed(%d): word5 %08x - %s",
        i_position, pSRC->word5,
        (pSRC->word5 & ErrlSrc::ACK_BIT) ? "not ACKed" : "ACKed");

    return (pSRC->word5 & ErrlSrc::ACK_BIT) ? false : true;
}

// setACKInFlattened()
void ErrlManager::setACKInFlattened(uint32_t i_position)
{
    char * l_pnorErrlAddr = iv_pnorAddr + (PNOR_ERROR_LENGTH * i_position);
    char * l_pnorAddr = l_pnorErrlAddr + sizeof(pelPrivateHeaderSection_t);
    l_pnorAddr += sizeof(pelUserHeaderSection_t);
    pelSRCSection_t *pSRC = reinterpret_cast<pelSRCSection_t *>(l_pnorAddr);

    pSRC->word5 &= ~(ErrlSrc::ACK_BIT);

    TRACDCOMP(g_trac_errl, "setACKInFlattened(%d): word5 %08x - %s",
        i_position, pSRC->word5,
        (pSRC->word5 & ErrlSrc::ACK_BIT) ? "not ACKed" : "ACKed");

    return;
}

} // End namespace
