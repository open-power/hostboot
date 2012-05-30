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
#include <targeting/common/targetservice.H>
#include <vector>

using namespace fapi;

/******************************************************************************/
// Globals/Constants
/******************************************************************************/
namespace HWAS
{

extern HWAS_TD_t g_trac_imp_hwas;

void    testHWP( void * io_pArgs )
{
    errlHndl_t l_err = NULL;
    std::vector<fapi::Target> l_target;

    // Get the master processor chip
    TARGETING::Target* l_pTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(l_pTarget);

    // Create the FAPI Targets and invoke the hwpInitialTest HWP
    fapi::Target l_fapiTarget(TARGET_TYPE_PROC_CHIP,
                              reinterpret_cast<void *> (l_pTarget));

    l_target.push_back(l_fapiTarget);

    // Get the target for the MBA chiplets of the first MEMBUF chip
    TARGETING::PredicateCTM l_membufChip(TARGETING::CLASS_CHIP,
                                         TARGETING::TYPE_MEMBUF);

    TARGETING::TargetRangeFilter l_filter(
        TARGETING::targetService().begin(),
        TARGETING::targetService().end(),
        &l_membufChip);

    PredicateCTM l_mba(CLASS_UNIT,TYPE_MBA);

    // Just look at the first MEMBUF chip
    if (l_filter)
    {
        TargetHandleList l_list;
        (void) targetService().getAssociated(
            l_list,
            *l_filter,
            TARGETING::TargetService::CHILD,
            TARGETING::TargetService::ALL,
            &l_mba);

        if (2 == l_list.size())
        {
            for (size_t i = 0; i < l_list.size(); i++)
            {
                //Set the associated targets
                fapi::Target l_fapiTargetAssoc(fapi::TARGET_TYPE_MBA_CHIPLET,
                    reinterpret_cast<void *>(l_list.at(i)));
                l_target.push_back(l_fapiTargetAssoc);
            }

            FAPI_INVOKE_HWP(l_err, hwpInitialTest, l_target);
        }
        else
        {
            HWAS_ERR("testHWP: Incorrect # of MBAs found: %u",
                l_list.size());

            size_t l_ffdc = l_list.size();
            size_t & FFDC_IF_TEST_NUM_MBAS_FOUND = l_ffdc;
            FAPI_SET_HWP_ERROR(l_rc,
                RC_HWP_EXEC_INITFILE_TEST_INCORRECT_NUM_MBAS_FOUND);
            l_err = fapiRcToErrl(l_rc);
        }
    }
    else
    {
        HWAS_ERR("testHWP: No MEMBUFs found");
        FAPI_SET_HWP_ERROR(l_rc, RC_HWP_EXEC_INITFILE_TEST_NO_MEMBUF_FOUND);
        l_err = fapiRcToErrl(l_rc);
    }

    if (l_err)
    {
        TRACFCOMP( g_trac_hwas, "testHWP failed. ");
    }

    task_end2( l_err );
}


} // namespace
