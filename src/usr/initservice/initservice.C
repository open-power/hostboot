/**
 * @file    initservice.C
 *
 *  Implements Initialization Service for Host boot.
 *  See initservice.H for details
 *
 */

#include <kernel/console.H>
#include <sys/vfs.h>
#include <sys/task.h>
#include <trace/interface.H>
#include <errl/errlentry.H>

#include "initservice.H"



namespace   INITSERVICE
{

//  always set up a trace buffer
trace_desc_t *g_trac_errl = NULL;
TRAC_INIT(&g_trac_errl, "INITSERVICE", 4096);


/******************************************************************************/
// InitService::getTheInstance return the only instance
/******************************************************************************/
InitService& InitService::getTheInstance()
{
    return Singleton<InitService>::instance();
}

/******************************************************************************/
// InitService::Initservice constructor
/******************************************************************************/
InitService::InitService()
{

}

/******************************************************************************/
// InitService::~InitService destructor
/******************************************************************************/
InitService::~InitService()
{

}

/**
 * @todo    failure to start a task is considered FATAL, revisit later.
 */

tid_t   InitService::startTask( const TaskInfo &i_rtask, errlHndl_t &io_rerrl ) const
{
    tid_t   tidrc   =   0;


    if ( i_rtask.taskflags.startflag )
    {
        TRACFCOMP(INITSERVICE::g_trac_errl, "startflag is on, starting task...\n" );
        printk( "startflag is on, starting task %s\n", i_rtask.taskname );
        tidrc   =   task_exec( i_rtask.taskname, NULL );
        if ( (int16_t)tidrc < 0 )
        {

            io_rerrl = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                    i_rtask.taskflags.module_id,
                    INITSERVICE::START_TASK_FAILED,
                    0,
                    0
            );
            TRACFCOMP(INITSERVICE::g_trac_errl, "ERROR %d starting task, errlog p = %p\n",
                    tidrc, io_rerrl );

        }  // endif tidrc
        else
        {
            TRACFCOMP(INITSERVICE::g_trac_errl, "task number %d started. errlog p = %p\n",
                    tidrc, io_rerrl );
        }
    }

    return tidrc;
}

/**
 * @todo    commit the error log here, and then delete it
 * @todo    dump some or all of the error log so we know who died.
 *
 */
void    InitService::reportError(errlHndl_t &io_rerrl ) const
{

    TRACFCOMP(INITSERVICE::g_trac_errl, "reportError!!!");

    if ( io_rerrl == NULL )
    {
        TRACFCOMP(INITSERVICE::g_trac_errl, "ERROR: reportError was passed a NULL errorlog handle.\n");
    }
    else
    {

        TRACFCOMP(INITSERVICE::g_trac_errl,
                "TODO:  commit the error log.  delete errl and set to NULL for now.\n"
        );
        /**

         * @todo    cannot commit an error log until the errorlog service is started up.
         *          do some checking here
         * @todo    commit the error log here, note that the commit should delete the log and
         *          set the handle to NULL
         */

        delete( io_rerrl );
        io_rerrl    =   NULL;       // $$TODO set errl back to NULL for now so all the tasks run
    }

    return;
}


void    InitService::start( void *i_ptr )
{
    errlHndl_t errl =   NULL;   // steps will return an error handle if failure

    TRACFCOMP(INITSERVICE::g_trac_errl, "+++++ Initialization Service is starting." );

    //  ----------------------------------------------------------------
    //  Start up any tasks necessary in the base modules...
    //  ----------------------------------------------------------------
    do  {

        //  startTrace
        TRACFCOMP(INITSERVICE::g_trac_errl, "running startTrace...");
        startTrace( errl );
        if  ( errl )
        {
            TRACFCOMP(INITSERVICE::g_trac_errl, "startTrace failed");
            break;        // break out and report error
        }

        //  startErrorLog
        TRACFCOMP(INITSERVICE::g_trac_errl, "running startErrLog...");
        startErrLog( errl );
        if  ( errl )
        {
            TRACFCOMP(INITSERVICE::g_trac_errl, "startErrLog failed");
            break;        // break out and report error
        }

        //  startXSCOM
        TRACFCOMP(INITSERVICE::g_trac_errl, "running startXSCOM...");
        startXSCOMDD( errl );
        if  ( errl )
        {
            TRACFCOMP(INITSERVICE::g_trac_errl, "startSCOMDD failed");
            break;        // break out and report error
        }

        //  startPNOR
        TRACFCOMP( INITSERVICE::g_trac_errl, "running startPNORDD");
        startPNORDD( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "startPNOR failed");
            break;        // break out and report error
        }

        //  startVFS_2
        TRACFCOMP( INITSERVICE::g_trac_errl, "running startVFS_2");
        startVFS_2( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "startVFS_2 failed");
            break;        // break out and report error
        }

    }   while( false );


    /**
     * @todo  stop here now if someone posted an error log, revisit this
     *          when we know what to do.
     */
    if  ( errl )
    {
        TRACFCOMP(INITSERVICE::g_trac_errl, "Errorlog posted, commit and die.");
        reportError( errl );
    }

    assert( errl == NULL );


    //  ----------------------------------------------------------------
    //  start running the extended modules
    //  ----------------------------------------------------------------
    do  {
        //  startTargetting
        TRACFCOMP( INITSERVICE::g_trac_errl, "running startTargetting");
        startTargetting( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "startTargetting failed");

            break;        // break out and report error
        }

        //  getMasterChipTarget
        TRACFCOMP( INITSERVICE::g_trac_errl, "running getMasterChipTarget");
        getMasterChipTarget( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "getMasterChipTarget failed");

            break;        // break out and report error
        }

        //  startMailboxDD
        TRACFCOMP( INITSERVICE::g_trac_errl, "running startMailboxDD");
        startMailboxDD( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "startMailboxDD failed");

            break;        // break out and report error
        }

        //  startSPComm
        TRACFCOMP( INITSERVICE::g_trac_errl, "running startSPComm");
        startSPComm( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "startSPComm failed");

            break;        // break out and report error
        }

        //  enableStreamingTrace
        TRACFCOMP( INITSERVICE::g_trac_errl, "running enableStreamingTrace");
        enableStreamingTrace( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "enableStreamingTrace failed");

            break;        // break out and report error
        }

        //  startProgressCodes
        TRACFCOMP( INITSERVICE::g_trac_errl, "running startProgressCodes");
        startProgressCodes( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "startProgressCodes failed");

            break;        // break out and report error
        }

        //  startFSIDD
        TRACFCOMP( INITSERVICE::g_trac_errl, "running startFSIDD");
        startFSIDD( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "startFSIDD failed");

            break;        // break out and report error
        }

        //  setupSlaveLinks
        TRACFCOMP( INITSERVICE::g_trac_errl, "running setupSlaveLinks");
        setupSlaveLinks( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "setupSlaveLinks failed");

            break;        // break out and report error
        }

        //  startFSISCOM
        TRACFCOMP( INITSERVICE::g_trac_errl, "running startFSISCOM");
        startFSISCOM( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "startFSISCOM failed");

            break;        // break out and report error
        }

        //  startFSII2C
        TRACFCOMP( INITSERVICE::g_trac_errl, "running startFSII2C");
        startFSII2C( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "startFSII2C failed");

            break;        // break out and report error
        }

        //  startHWP
        TRACFCOMP( INITSERVICE::g_trac_errl, "running startHWP");
        startHWPF( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "startHWP failed");

            break;        // break out and report error
        }

        //  readMaxConfigfromPNOR
        TRACFCOMP( INITSERVICE::g_trac_errl, "running readMaxConfigfromPNOR");
        readMaxConfigfromPNOR( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "readMaxConfigfromPNOR failed");

            break;        // break out and report error
        }

        //  applyPresenceDetect
        TRACFCOMP( INITSERVICE::g_trac_errl, "running applyPresenceDetect");
        applyPresenceDetect( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "applyPresenceDetect failed");

            break;        // break out and report error
        }

        //  applyPartialBad
        TRACFCOMP( INITSERVICE::g_trac_errl, "running applyPartialBad");
        applyPartialBad( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "applyPartialBad failed");

            break;        // break out and report error
        }

        //  applyGard
        TRACFCOMP( INITSERVICE::g_trac_errl, "running applyGard...");
        applyGard( errl );
        if  ( errl )
        {

            TRACFCOMP( INITSERVICE::g_trac_errl, "applyGard failed");
            break;        // break out and report error
        }

        //  collectHWIDEC
        TRACFCOMP( INITSERVICE::g_trac_errl, "running collectHWIDEC...");
        collectHWIDEC( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "collectHWIDEC failed");

            break;        // break out and report error
        }

        //  verifyIDEC
        TRACFCOMP( INITSERVICE::g_trac_errl, "running verifyIDEC");
        verifyIDEC( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "verifyIDEC failed");

            break;        // break out and report error
        }

        //  disableWatchDog
        TRACFCOMP( INITSERVICE::g_trac_errl, "running disableWatchDog");
        disableWatchDog( errl );
        if  ( errl )
        {
            TRACFCOMP( INITSERVICE::g_trac_errl, "disableWatchDog failed");

            break;        // break out and report error
        }


    }   while ( false );


    /**
     * @todo  stop here now if someone posted an error log, revisit this
     *          when we know what to do.
     */
    if  ( errl )
    {
        TRACFCOMP(INITSERVICE::g_trac_errl, "Errorlog posted, commit and die.");
        reportError( errl );
    }

    assert( errl == NULL );



    //  executeISteps
    TRACFCOMP( INITSERVICE::g_trac_errl, "running executeISteps");
    executeISteps( errl );

    if  ( errl )
    {
        TRACFCOMP( INITSERVICE::g_trac_errl, "executeISteps failed");
        reportError( errl );
        assert( errl == NULL );
    }


    TRACFCOMP( INITSERVICE::g_trac_errl, "+++++ Initilization Service finished.  IN THE REAL CODE WE WILL NEVER GET HERE");

    // return to _start(), which may end the task or die.
    return;
}


}   // namespace    INITSERVICE
