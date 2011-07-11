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
#include    <errl/errlmanager.H>
#include    <initservice/taskargs.H>       //  task args

//  pull in stuff to run HW procedure - from Andrew's hwpf testcase 2
//  NOTE:  there are extra include paths in isteps/makefile to find the fapi includes:
//      EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
//      EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
//      EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat

#include <fapi.H>
#include <fapiPlatHwpInvoker.H>
#include <fapiPlatHwpInvoker.H>
#include <targeting/targetservice.H>

using namespace fapi;
using namespace TARGETING;

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
    errlHndl_t l_err = NULL;
    uint64_t    command     =   pTaskArgs->getCommand();
    uint64_t    returncode  =   pTaskArgs->getReturnCode();


    // print out stuff from taskargs
    TRACFCOMP( g_trac_istep1,
            "starting IStep 1, command=0x%llx, returncode=0x%llx",
            command, returncode );
    //  -----   start ISTEP --------------------------------------------------


    // Set processor chip to the master
     TARGETING::Target* l_testTarget = MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

    l_err = invokeHwpInitialTest(l_testTarget);
    if (l_err)
    {
        TRACFCOMP( g_trac_istep1,
                "IStep1 failed, posting error code 1");

        // Commit/delete error
        errlCommit(l_err);

        pTaskArgs->postReturnCode( 1 );
    }
    else
    {
        TRACFCOMP( g_trac_istep1,
                "ISTep1 finished successfully.");

        pTaskArgs->postReturnCode( 0 );
    }


//  -----   end ISTEP   ------------------------------------------------------
    TRACFCOMP( g_trac_istep1,
            EXIT_MRK "ending  IStep 1");

    if  ( pTaskArgs )
    {
        pTaskArgs->waitChildSync();
    }

    task_end();
}


} // namespace
