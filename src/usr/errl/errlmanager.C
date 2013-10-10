/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errlmanager.C $                                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errl/errlmanager.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <sys/task.h>
#include <stdlib.h>
#include <string.h>
#include <mbox/mbox_queues.H>
#include <mbox/mboxif.H>
#include <initservice/initserviceif.H>
#include <pnor/pnorif.H>
#include <sys/mm.h>

namespace ERRORLOG
{

extern trace_desc_t* g_trac_errl;


// Scaffolding
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


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlManager::ErrlManager()
{
    TRACFCOMP( g_trac_errl, ENTER_MRK "ErrlManager::ErrlManager constructor" );

    iv_hwasProcessCalloutFn = NULL;

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

    // to determine the starting log ID, we need to look thru PNOR and see
    //  what error records are there; ours will be 1 after the highest found.

    // first, determine our node
    TARGETING::Target* l_pMasterProcChip = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(l_pMasterProcChip);
    assert(l_pMasterProcChip != NULL);

    const uint64_t l_node =
        l_pMasterProcChip->getAttr<TARGETING::ATTR_PHYS_PATH>().
            pathElementOfType(TARGETING::TYPE_NODE).instance;

    // current log id is 0x9# where # is the node instance.
    iv_currLogId = ERRLOG_PLID_BASE + (l_node << ERRLOG_PLID_NODE_SHIFT);

    // now walk thru memory, finding error logs and determine the highest ID
    uint32_t l_maxId = 0;

    // Follow the markers.  The start-of-list marker:
    marker_t* pMarker = OFFSET2MARKER(iv_pStorage->offsetStart);
    while (pMarker->offsetNext)
    {
        pelPrivateHeaderSection_t * pPrivateHdr =
            reinterpret_cast<pelPrivateHeaderSection_t*>(pMarker+1);

        if (pPrivateHdr->eid > l_maxId)
        {
            l_maxId = pPrivateHdr->eid;
        }

        // next marker/error log
        pMarker = OFFSET2MARKER(pMarker->offsetNext);
    } // while

    // bump the current plid to 1 past the max eid found
    iv_currLogId += (l_maxId & ERRLOG_PLID_MASK) + 1;

    TRACFCOMP( g_trac_errl, INFO_MRK"ErrlManager on proc %.8X, LogId 0x%X",
        get_huid(l_pMasterProcChip), iv_currLogId);

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
void ErrlManager::msgQueueInit ( void )
{
    errlHndl_t l_err = NULL;

    TRACFCOMP( g_trac_errl, ENTER_MRK "ErrlManager::msgQueueInit ..." );

    do
    {
        // Create error log message queue.
        iv_msgQ = msg_q_create();

        // Register messageQ with Mailbox to receive message.
        l_err = MBOX::msgq_register( MBOX::HB_ERROR_MSGQ,
                                       iv_msgQ );
        if( l_err )
        {
            TRACFCOMP(g_trac_errl, ERR_MRK "Msg queue already registered");

            delete( l_err );
            l_err = NULL;

            //If we got an error then it means the message queue is
            //registered with mailbox. This should not happen.
            //So assert here.
            assert(0);

            break;
        }

        // Register for error log manager shutdown event
        INITSERVICE::registerShutdownEvent( iv_msgQ, ERRLOG_SHUTDOWN,
                                                  INITSERVICE::NO_PRIORITY );

    } while (0);

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
void ErrlManager::errlogMsgHndlr ( void )
{
    errlHndl_t l_err = NULL;
    msg_t * theMsg = NULL;

    TRACFCOMP( g_trac_errl, ENTER_MRK "Enter ErrlManager::errlogMsgHndlr" );

    while( 1 )
    {
        theMsg = msg_wait( iv_msgQ );
        TRACFCOMP( g_trac_errl, INFO_MRK"Got an error log Msg - Type: 0x%08x",
                                                               theMsg->type );
        //Process message just received
        switch( theMsg->type )
        {
            case ERRLOG_NEEDS_TO_BE_COMMITTED_TYPE:
                {

                    //Extract error log handle from the message. We need the
                    // error log handle to pass along to saveErrlogEntry and
                    // sendMboxMsg
                    l_err = (errlHndl_t) theMsg->extra_data;

                    //Ask the ErrlEntry to assign commit component, commit time
                    l_err->commit( (compId_t) theMsg->data[0] );

                    //Write the error log to L3 memory till PNOR is implemented
                    //RTC #47517 for future task to write error log to PNOR
                    saveErrLogEntry ( l_err );

                    //Create a mbox message with the error log and send it to
                    // FSP.
                    // We only send error log to FSP when mailbox is enabled
                    if( MBOX::mailbox_enabled() )
                    {
                        sendMboxMsg ( l_err );
                    }

                    //Ask the ErrlEntry to process any callouts
                    l_err->processCallout();

                    //Ask if it is a terminating log
                    if( l_err->isTerminateLog() )
                    {

                        TRACFCOMP( g_trac_errl, INFO_MRK
                                   "Terminating error was commited"
                                   " errlmanager is reqesting a shutdown.");

                        INITSERVICE::Shutdown(l_err->plid());

                        TRACDCOMP( g_trac_errl,
                                INFO_MRK"shutdown in progress" );

                    }

                    //We are done with the error log handle so delete it.
                    delete l_err;
                    l_err = NULL;

                    //We are done with the msg
                    msg_free(theMsg);

                    // else go back and wait for a next msg
                    break;
                }
            case ERRLOG_COMMITTED_ACK_RESPONSE_TYPE:
                //Hostboot must keep track and clean up hostboot error
                //logs in PNOR after it is committed by FSP.

                //TODO: We have an RTC 47517 for this work. New code need
                //to be added to mark the error log in PNOR as committed.

                TRACFCOMP( g_trac_errl, INFO_MRK"Got a acked msg - Type: 0x%08x",
                                                                  theMsg->type );
                msg_free(theMsg);
                break;

            case ERRLOG_SHUTDOWN:
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
        }
    }

    //The errlogMsgHndlr should run all the time. It only
    //exits when error log message thread is killed.
    TRACFCOMP( g_trac_errl, EXIT_MRK "Exit ErrlManager::errlogMsgHndlr" );
    return;
}


///////////////////////////////////////////////////////////////////////////////
// ErrlManager::sendMboxMsg()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::sendMboxMsg ( errlHndl_t& io_err )
{
    errlHndl_t l_err = NULL;
    msg_t  *  msg  = NULL;

    TRACFCOMP( g_trac_errl, ENTER_MRK"ErrlManager::sendMboxMsg" );
    do
    {
         //Create a mailbox message to send to FSP
         msg = msg_allocate();
         msg->type = ERRLOG_SEND_TO_FSP_TYPE;

         uint32_t l_msgSize = io_err->flattenedSize();

         //Data[0] will be hostboot error log ID so Hostboot can
         //keep track of the error log when FSP responses back.
         //The error log ID is also the plid (platform log identify)

         msg->data[0] = io_err->plid();
         msg->data[1] = l_msgSize;

         void * temp_buff = malloc( l_msgSize );
         io_err->flatten ( temp_buff, l_msgSize );
         msg->extra_data = temp_buff;

        TRACDCOMP( g_trac_errl, INFO_MRK"Send msg to FSP for errlogId [0x%08x]",
                                                               io_err->plid() );

        l_err = MBOX::send( MBOX::FSP_ERROR_MSGQ, msg );
        if( l_err )
        {
           TRACFCOMP(g_trac_errl, ERR_MRK "Failed sending error log to FSP");

           //Free the extra data due to the error
           if( msg != NULL && msg->extra_data != NULL )
           {
               free( msg->extra_data );
               msg_free( msg );
           }

           delete l_err;
           l_err = NULL;

        }
    } while (0);

    TRACFCOMP( g_trac_errl, EXIT_MRK"sendMboxMsg()" );
    return;
}

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

        TRACFCOMP(g_trac_errl, "commitErrLog() called by %.4X for plid=0x%X,"
                               "Reasoncode=%.4X", i_committerComp,
                               io_err->plid(), io_err->reasonCode() );

        //Ask ErrlEntry to check for any special deferred deconfigure callouts
        io_err->deferredDeconfigure();

        //Offload the error log to the errlog message queue
        sendErrlogToMessageQueue ( io_err, i_committerComp );
        io_err = NULL;

   } while( 0 );

   TRACDCOMP( g_trac_errl, EXIT_MRK"ErrlManager::commitErrLog" );

   return;
}

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::saveErrLogEntry()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::saveErrLogEntry( errlHndl_t& io_err )
{
    TRACFCOMP( g_trac_errl, ENTER_MRK"ErrlManager::saveErrLogEntry" );
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
    TRACFCOMP( g_trac_errl, EXIT_MRK"ErrlManager::saveErrLogEntry" );
    return;
}



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
                                " to commit. plid=0x%X", io_err->plid() );

        //Send the error log to error message queue to handle.
        //Message is sent as asynchronous.
        int rc = msg_send ( iv_msgQ, msg );

        //Return code is non-zero when the message queue is invalid
        //or the message type is invalid.
        if ( rc )
        {
            TRACFCOMP( g_trac_errl, ERR_MRK "Failed to send mailbox message"
                       "to message queue. plid=0x%X", io_err->plid() );
            break;
        }

    } while (0);
    TRACFCOMP( g_trac_errl, EXIT_MRK"ErrlManager::sendErrlogToMessageQueue" );
    return;
}

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::errlogShutdown()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::errlogShutdown(void)
{
    errlHndl_t l_err = NULL;
    PNOR::SectionInfo_t l_section;

    // Ensure that all the error logs are pushed out to PNOR
    // prior to the PNOR resource provider shutting down.

    l_err = PNOR::getSectionInfo(PNOR::HB_ERRLOGS, PNOR::CURRENT_SIDE,
                                    l_section);

    if(l_err)
    {
        TRACFCOMP(g_trac_errl, ERR_MRK "Error in getting PNOR section info");
        //We are shutting the error log manager so we can not commit
        //error. So just log the error trace for the error.
        delete l_err;
        l_err = NULL;
    }
    else
    {
        int l_rc = mm_remove_pages(FLUSH, (void *) l_section.vaddr,
                                                   l_section.size);
        if( l_rc )
        {
            //If mm_remove_pages returns none zero for error then
            //log an error trace in this case.
            TRACFCOMP(g_trac_errl, ERR_MRK "Fail to flush the page");
        }
    }

    // Un-register error log message queue from the shutdown
    INITSERVICE::unregisterShutdownEvent( iv_msgQ);

    // Un-register error log message queue from the mailbox service
    MBOX::msgq_unregister( MBOX::HB_ERROR_MSGQ );

    // destroy the queue
    msg_q_destroy(iv_msgQ);

    return;
}

} // End namespace
