//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwas/testHWP.C $
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
 *  @file testHWP.C
 *
 *  testHWP -this is the last substep of IStep4 (HWAS)
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

//  pull in stuff to run HW procedure -
//  NOTE:  there are extra include paths in the makefile to find the fapi
//          includes:
//      EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
//      EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
//      EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
//      EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp
//

#include <fapiTarget.H>
#include <fapiPlatHwpInvoker.H>
#include <targeting/targetservice.H>

using namespace fapi;
using namespace TARGETING;

/******************************************************************************/
// Globals/Constants
/******************************************************************************/
extern trace_desc_t *g_trac_imp_hwas;

namespace HWAS
{

void    testHWP( void * io_pArgs )
{
    errlHndl_t l_err = NULL;

    // Get the master processor chip
    TARGETING::Target* l_pTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(l_pTarget);

    // Create a FAPI Target and invoke the hwpInitialTest HWP
    fapi::Target l_fapiTarget(TARGET_TYPE_PROC_CHIP,
                              reinterpret_cast<void *> (l_pTarget));

    FAPI_INVOKE_HWP(l_err, hwpInitialTest, l_fapiTarget);

    if (l_err)
    {
        TRACFCOMP( g_trac_hwas, "testHWP failed. ");
    }

    task_end2( l_err );
}


} // namespace
