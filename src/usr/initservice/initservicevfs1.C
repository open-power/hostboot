/**
 * @file    initservicevfs1.C
 *
 *  Private functions for VFS1 phase.
 */

#include <kernel/console.H>
#include <sys/vfs.h>
#include <sys/task.h>
#include <trace/interface.H>

#include    "initservice.H"

#include    "initsvctasks.H"


namespace   INITSERVICE
{

/******************************************************************************/
//  private functions for VFS 1 phase
/******************************************************************************/

void    InitService::startTrace( errlHndl_t &io_rerrl ) const
{

    //  start up the task
    startTask( TASK_TRACE,  io_rerrl );

    return;
}


void    InitService::startErrLog( errlHndl_t &io_rerrl )    const
{

    startTask( TASK_ERRORLOG, io_rerrl );

    return;
}


void    InitService::startXSCOMDD( errlHndl_t &io_rerrl )    const
{

    startTask( TASK_XSCOMDD, io_rerrl );

    return;
}


void    InitService::startPNORDD( errlHndl_t &io_rerrl )    const
{

    startTask( TASK_PNORDD, io_rerrl );

    return;
}


void    InitService::startVFS_2(  errlHndl_t &io_rerrl )    const
{

    startTask( TASK_VFS_2, io_rerrl );

    return;
}

}   // namespace    INITSERVICE
