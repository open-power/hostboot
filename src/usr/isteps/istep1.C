/**
 *  @file isteps.C
 *
 *  Collection of IStep modules
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <stdio.h>
#include    <string.h>

#include    <sys/task.h>

#include    <trace/interface.H>         //  trace support
#include    <errl/errlentry.H>          //  errlHndl_t
#include    <initservice/taskargs.H>       //  task args

namespace   ISTEPS
{

/******************************************************************************/
// Globals/Constants
/******************************************************************************/
trace_desc_t *g_trac_istep1 = NULL;
TRAC_INIT(&g_trac_istep1, "ISTEP1", 4096);

extern  "C"
void    IStep1( void * io_pArgs )
{
    INITSERVICE::TaskArgs::TaskArgs *pTaskArgs  =
             reinterpret_cast<INITSERVICE::TaskArgs::TaskArgs *>(io_pArgs);

    TRACFCOMP( g_trac_istep1,
                ENTER_MRK "starting IStep 1");



    if  ( pTaskArgs )
    {
        pTaskArgs->waitChildSync();
    }

    task_end();
}


} // namespace
