//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/isteps/istep1.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

/**
 *  @file istep1.C
 *
 *  test ISTep file
 *
 *  @note, you must update isteps.h if you change this one
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
//  NOTE:  there are extra include paths in isteps/makefile to find the fapi
//          includes:
//      EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
//      EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
//      EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat

#include <fapiTarget.H>
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
void    IStep0sub0( void * io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs  =
            static_cast<INITSERVICE::TaskArgs *>(io_pArgs);
    errlHndl_t l_err = NULL;
    uint64_t    command     =   pTaskArgs->getCommand();
    uint64_t    returncode  =   pTaskArgs->getReturnCode();


    // print out stuff from taskargs
    TRACFCOMP( g_trac_istep1,
            ENTER_MRK "starting IStep0sub0, command=0x%llx, returncode=0x%llx",
            command, returncode );
    //  -----   start ISTEP --------------------------------------------------

    // Get the master processor chip
    TARGETING::Target* l_pTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(l_pTarget);

    // Create a FAPI Target and invoke the hwpInitialTest HWP
    fapi::Target l_fapiTarget(TARGET_TYPE_PROC_CHIP,
                              reinterpret_cast<void *> (l_pTarget));

    FAPI_INVOKE_HWP(l_err, hwpInitialTest, l_fapiTarget);

    if (l_err)
    {
        TRACFCOMP( g_trac_istep1, "IStep1 failed, posting error code 1");
        errlCommit(l_err);
        pTaskArgs->postReturnCode( 1 );
    }
    else
    {
        TRACFCOMP( g_trac_istep1, "IStep1 finished successfully.");
        pTaskArgs->postReturnCode( 0 );
    }


//  -----   end ISTEP   ------------------------------------------------------
    TRACFCOMP( g_trac_istep1,
            EXIT_MRK "ending  IStep0sub0");

    // if non-null, wait for the barrier, otherwise just return
    if  ( pTaskArgs )
    {
        pTaskArgs->waitChildSync();
    }

    task_end();
}

extern  "C"
void    IStep0sub1( void * io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs  =
            static_cast<INITSERVICE::TaskArgs *>(io_pArgs);
    uint64_t    command     =   pTaskArgs->getCommand();
    uint64_t    returncode  =   pTaskArgs->getReturnCode();


    // print out stuff from taskargs
    TRACFCOMP( g_trac_istep1,
            ENTER_MRK "starting IStep0sub1, command=0x%llx, returncode=0x%llx",
            command, returncode );
    //  -----   start ISTEP --------------------------------------------------

    pTaskArgs->postReturnCode( 0 );

    //  -----   end ISTEP   ------------------------------------------------------
    TRACFCOMP( g_trac_istep1,
            EXIT_MRK "ending  IStep0sub1");

    // if non-null, wait for the barrier, otherwise just return
    if  ( pTaskArgs )
    {
        pTaskArgs->waitChildSync();
    }

    task_end();
}

extern  "C"
void    IStep1sub0( void * io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs  =
            static_cast<INITSERVICE::TaskArgs *>(io_pArgs);
    uint64_t    command     =   pTaskArgs->getCommand();
    uint64_t    returncode  =   pTaskArgs->getReturnCode();


    // print out stuff from taskargs
    TRACFCOMP( g_trac_istep1,
            ENTER_MRK "starting IStep1sub0, command=0x%llx, returncode=0x%llx",
            command, returncode );
    //  -----   start ISTEP --------------------------------------------------

    pTaskArgs->postReturnCode( 0 );

    //  -----   end ISTEP   --------------------------------------------------
    TRACFCOMP( g_trac_istep1,
            EXIT_MRK "ending  IStep1sub0");

    // if non-null, wait for the barrier, otherwise just return
    if  ( pTaskArgs )
    {
        pTaskArgs->waitChildSync();
    }

    task_end();
}

} // namespace
