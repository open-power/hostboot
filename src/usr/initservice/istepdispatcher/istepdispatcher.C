/****************************************************************************
 * $IBMCopyrightBlock:
 * 
 *  IBM Confidential
 * 
 *  Licensed Internal Code Source Materials
 * 
 *  IBM HostBoot Licensed Internal Code
 * 
 *  (C) Copyright IBM Corp. 2011
 * 
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 * $
****************************************************************************/

/**
 *  @file istepdispatcher.C
 *
 *  IStep Dispatcher interface.  Launched from Extended Initialization Service
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <stdio.h>
#include    <string.h>

#include    <sys/task.h>                // tid_t, task_create, etc
#include    <trace/interface.H>         //  trace support
#include    <errl/errlentry.H>          //  errlHndl_t

#include    "istepdispatcher.H"
#include    "isteplist.H"


namespace   INITSERVICE
{

/******************************************************************************/
// Globals/Constants
/******************************************************************************/
extern trace_desc_t *g_trac_initsvc;

/**
 * @brief   set up _start() task entry procedure using the macro
 */
TASK_ENTRY_MACRO( IStepDispatcher::getTheInstance().init );


IStepDispatcher::IStepDispatcher()
:   iv_istepmodeflag(false),
    iv_nextistep( 0 ),
    iv_cancontinueflag(false)
{

}


IStepDispatcher::~IStepDispatcher()
{

}


IStepDispatcher& IStepDispatcher::getTheInstance()
{
    return Singleton<IStepDispatcher>::instance();
}


void IStepDispatcher::init( void * ptr )
{
    errlHndl_t          errl            =   NULL;
    uint64_t            nextIStep       =   0;
    const TaskInfo      *pistep         =   NULL;
    TaskArgs::TaskArgs  args;

    TRACFCOMP( g_trac_initsvc,
            ENTER_MRK "starting IStepDispatcher, ptr=%p. &args=%p",
            ptr, &args );

    for (   nextIStep=0;
            nextIStep<INITSERVICE::MAX_ISTEPS;
            nextIStep++ )
    {
        pistep    =   &(g_isteps[nextIStep]);
        if ( pistep->taskflags.task_type ==  END_TASK_LIST )
        {
            TRACDCOMP( g_trac_initsvc,
                    "End of IStep list.\n" );
            break;
        }


        args.clear();           // clear the args struct for the next istep
        errl = InitService::getTheInstance().executeFn( pistep,
                                                        &args );

        //  handle an errorlog from the parent, if it exists
        InitService::getTheInstance().reportError( errl );

        /**
         * @todo call getCanContinueProcedure when we have some ISteps that
         *          require them.
         */

        if ( args.getReturnCode() != TASKARGS_UNDEFINED64 )
        {
            TRACFCOMP( g_trac_initsvc,
                        ERR_MRK "IStep TaskArgs returned 0x%llx, errlog=%p",
                        args.getReturnCode(),
                        args.getErrorLog()
                        );
        }

        // report an error from the child, if it exists.
        reportIStepErrorLog( pistep, args.getErrorLog() );

    }   // endfor


    TRACFCOMP( g_trac_initsvc,
            EXIT_MRK "IStepDispatcher finished.");

}



/**
 * @note    IStep Mode is hardwired to false for now
 *
 * @todo    revisit this when PNOR Driver is implemented
 */
bool IStepDispatcher::getIStepMode( )  const
{

    return  false;
}



bool IStepDispatcher::getCanContinueProcedure(  const  TaskInfo &i_failingIStep,
                                                errlHndl_t      &i_failingError,
                                                TaskInfo        &io_nextIstep
                                                ) const
{

    return  false;
}

void IStepDispatcher::reportIStepErrorLog(  const TaskInfo  *i_failingIStep,
                                            errlHndl_t    io_errl )
{

    InitService::getTheInstance().reportError( io_errl );
}

} // namespace
