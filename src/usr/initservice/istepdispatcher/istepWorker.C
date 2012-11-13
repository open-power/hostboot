/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/initservice/istepdispatcher/istepWorker.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 *  @file istepWorker.C
 *
 *  IStep Dispatcher worker thread.
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <sys/msg.h>

#include <errl/errlentry.H>

#include <isteps/istepmasterlist.H>

#include    "../baseinitsvc/initservice.H"

//#include <initservice/initsvcudistep.H>  //  InitSvcUserDetailsIstep

#include "istep_mbox_msgs.H"
#include "istepWorker.H"

//  -----   namespace   INITSERVICE -------------------------------------------
namespace   INITSERVICE
{
/******************************************************************************/
// Globals/Constants
/******************************************************************************/
extern trace_desc_t *g_trac_initsvc;


// ----------------------------------------------------------------------------
// startIStepWorkerThread
// ----------------------------------------------------------------------------
void* startIStepWorkerThread ( void * io_args )
{
    TRACFCOMP( g_trac_initsvc,
               ENTER_MRK"startIStepWorkerThread()" );

    // detach from main istep dispatcher thread
    task_detach();

    // Worker thread entry
    iStepWorkerThread( io_args );

    TRACDCOMP( g_trac_initsvc,
               EXIT_MRK"startIStepWorkerThread()" );

    // Shutdown.
    return NULL;
}


// ----------------------------------------------------------------------------
// iStepWorkerThread()
// ----------------------------------------------------------------------------
void iStepWorkerThread ( void * i_msgQ )
{
    errlHndl_t err          =   NULL;
    msg_q_t theQ            =   static_cast<msg_q_t>( i_msgQ );
    msg_t * theMsg          =   NULL;
    uint32_t istep          =   0x0;
    uint32_t substep        =   0x0;
    uint64_t progressCode   =   0x0;
    bool first = true;

    TRACDCOMP( g_trac_initsvc,
               ENTER_MRK"iStepWorkerThread()" );

    while( 1 )
    {
        // Send More Work Needed msg to the main thread.
        theMsg = msg_allocate();
        theMsg->type = MORE_WORK_NEEDED;
        theMsg->data[0] = first ? 1 : 0x0;
        if ( err )
        {
            // The size of the errorlog (data[1]) is intentionally left at 0;
            //  the main thread will commit this errorlog.  We do not really
            //  need to send the size of the errorlog.
            theMsg->data[1] = 0;
            TRACFCOMP( g_trac_initsvc,
                       "istepWorker:  send errlog back to main, PLID = 0x%x",
                       err->plid()  );
        }

        theMsg->extra_data = err;
        err = NULL;
        TRACDCOMP( g_trac_initsvc,
        INFO_MRK"istepWorker: sendmsg t=0x%08x, d0=0x%016x, d1=0x%016x, x=%p",
                   theMsg->type,
                   theMsg->data[0],
                   theMsg->data[1],
                   theMsg->extra_data );

        // Wait here until the main thread has work for us.
        msg_sendrecv( theQ,
                      theMsg );

        TRACDCOMP( g_trac_initsvc,
        INFO_MRK"istepWorker: rcvmsg t=0x%08x, d0=0x%016x, d1=0x%016x, x=%p",
                   theMsg->type,
                   theMsg->data[0],
                   theMsg->data[1],
                   theMsg->extra_data );

        first = false;

        // Got a response...  The step/substep to execute are in data[0]
        istep = ((theMsg->data[0] & 0xFF00) >> 8);
        substep = (theMsg->data[0] & 0xFF);

        // Post the Progress Code
        // TODO - Covered with RTC: 34046
        InitService::getTheInstance().setProgressCode( progressCode );

        // Get the Task Info for this step
        const TaskInfo * theStep = findTaskInfo( istep,
                                                 substep );

        if( NULL != theStep )
        {
            TRACFCOMP( g_trac_initsvc,
                       "IStepDispatcher (worker): Run Istep (%d), substep(%d), "
                       "- %s",
                       istep, substep, theStep->taskname );

            err = InitService::getTheInstance().executeFn( theStep,
                                                           NULL );

            if( err )
            {
                TRACFCOMP( g_trac_initsvc,
                           "IStepDipspatcher (worker): Istep %s returned "
                           "errlog=%p",
                           theStep->taskname, err );
            }
        }
        else
        {
#if 1
            //  Nothing to do for this istep.
            TRACFCOMP( g_trac_initsvc,
                       INFO_MRK"Empty Istep, Nothing to do!" );
#else
            //  $$  please save, need to fix for
            //  $$      IPL service not returning error on invalid isteps
            //  This istep should have not been sent here to run, make up
            //  an errorlog and return it.
            /*@
             * @errortype
             * @reasoncode       ISTEP_INVALID_ISTEP
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         ISTEP_INITSVC_MOD_ID
             * @userdata1        Current Istep
             * @userdata2        Current SubStep
             * @devdesc          An invalid istep or substep was passed.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           ISTEP_INITSVC_MOD_ID,
                                           ISTEP_INVALID_ISTEP,
                                           istep,
                                           substep  );

            TRACFCOMP( g_trac_initsvc,
                       ERR_MRK"Invalid Istep %d.%d, return errlog plid=0x%x",
                       istep,
                       substep,
                       err->plid()  );
#endif
        }

        //  flush contTrace after each istep/substep  returns
        TRACE::Trace::getTheInstance().flushContBuffers();

        msg_free( theMsg );
        theMsg = NULL;
    }   // end while(1)

    // Something bad happened...  this thread should never exit once started
    assert( 0 );
    TRACDCOMP( g_trac_initsvc,
               ENTER_MRK"iStepWorkerThread()" );
}


// ----------------------------------------------------------------------------
// findTaskInfo()
// ----------------------------------------------------------------------------
const TaskInfo * findTaskInfo( const uint32_t i_IStep,
                               const uint32_t i_SubStep )
{
    //  default return is NULL
    const TaskInfo *l_pistep = NULL;

    //  apply filters
    do
    {
        //  Sanity check / dummy IStep
        if( g_isteps[i_IStep].pti == NULL)
        {
            TRACDCOMP( g_trac_initsvc,
                       "g_isteps[%d].pti == NULL (substep=%d)",
                       i_IStep,
                       i_SubStep );
            break;
        }

        // check input range - IStep
        if( i_IStep >= INITSERVICE::MaxISteps )
        {
            TRACDCOMP( g_trac_initsvc,
                       "IStep %d out of range. (substep=%d) ",
                       i_IStep,
                       i_SubStep );
            break;      // break out with l_pistep set to NULL
        }

        //  check input range - ISubStep
        if( i_SubStep >= g_isteps[i_IStep].numitems )
        {
            TRACDCOMP( g_trac_initsvc,
                       "IStep %d Substep %d out of range.",
                       i_IStep,
                       i_SubStep );
            break;      // break out with l_pistep set to NULL
        }

        //   check for end of list.
        if( g_isteps[i_IStep].pti[i_SubStep].taskflags.task_type
            == END_TASK_LIST )
        {
            TRACDCOMP( g_trac_initsvc,
                       "IStep %d SubStep %d task_type==END_TASK_LIST.",
                       i_IStep,
                       i_SubStep );
            break;
        }

        //  check to see if the pointer to the function is NULL.
        //  This is possible if some of the substeps aren't working yet
        //  and are just placeholders.
        if( g_isteps[i_IStep].pti[i_SubStep].taskfn == NULL )
        {
            TRACDCOMP( g_trac_initsvc,
                       "IStep %d SubStep %d fn ptr is NULL.",
                       i_IStep,
                       i_SubStep );
            break;
        }

        //  we're good, set the istep & return it to caller
        l_pistep = &( g_isteps[i_IStep].pti[i_SubStep] );
    } while( 0 );

    return  l_pistep;
}


} // namespace
