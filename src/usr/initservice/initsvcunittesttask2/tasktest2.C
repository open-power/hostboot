/**
 *  @file tasktest2.H
 *
  */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <sys/task.h>
#include <trace/interface.H>
#include <initservice/taskargs.H>

#include "tasktest2.H"

namespace   INITSVCTASKTEST2
{


/******************************************************************************/
// Globals/Constants
/******************************************************************************/

/******************************************************************************/
// InitService::getTheInstance return the only instance
/******************************************************************************/
InitSvcTaskTest2& InitSvcTaskTest2::getTheInstance()
{
    return Singleton<InitSvcTaskTest2>::instance();
}


/**
 * @brief   _start() - task entry point for this module
 *
 */
extern "C"
void _start( void *io_pArgs )
{
    INITSERVICE::TaskArgs::TaskArgs *pTaskArgs  = (INITSERVICE::TaskArgs::TaskArgs *)io_pArgs;

    //  create an instance of InitService
    InitSvcTaskTest2::InitSvcTaskTest2& tt = InitSvcTaskTest2::getTheInstance();

    // initialize the base modules in Hostboot.
    tt.init( io_pArgs );

    if  ( pTaskArgs )
    {
        pTaskArgs->waitChildSync();
    }

    task_end();
}

void    InitSvcTaskTest2::init( void *i_args )
{

    return;
};

} // namespace
