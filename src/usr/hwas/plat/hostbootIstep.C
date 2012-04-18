//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwas/plat/hostbootIstep.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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
 *  @file hostbootIstep.C
 *
 *  @brief hostboot istep-called functions
 */

#include <hwas/hwas.H>
#include <hwas/hwasCommon.H>

#include <hwas/plat/hostbootIstep.H>
#include <hwas/deconfigGard.H>

#include <fsi/fsiif.H>
#include <initservice/taskargs.H>

namespace HWAS
{

// functions called from the istep dispatcher -- hostboot only

//******************************************************************************
// host_init_fsi function
//******************************************************************************
void host_init_fsi( void *io_pArgs )
{
    errlHndl_t errl = FSI::initializeHardware( );

    task_end2(errl);
}

//******************************************************************************
// host_set_ipl_parms function
//******************************************************************************
void host_set_ipl_parms( void *io_pArgs )
{
    errlHndl_t errl = NULL;

    // stub -- nothing here currently

    task_end2(errl);
}

//******************************************************************************
// host_discover_targets function
//******************************************************************************
void host_discover_targets( void *io_pArgs )
{
    errlHndl_t errl = discoverTargets();

    task_end2(errl);
}

//******************************************************************************
// host_gard function
//******************************************************************************
void host_gard( void *io_pArgs )
{
    errlHndl_t errl = collectGard();

    task_end2(errl);
}

//******************************************************************************
// host_cancontinue_clear function
//******************************************************************************
void host_cancontinue_clear( void *io_pArgs )
{
    errlHndl_t errl = NULL;

    // stub -- nothing here currently

    task_end2(errl);
}

//******************************************************************************
// proc_check_slave_sbe_seeprom_complete function
//******************************************************************************
void proc_check_slave_sbe_seeprom_complete( void *io_pArgs )
{
    errlHndl_t errl = NULL;

    // stub -- nothing here currently

    task_end2(errl);
}

//******************************************************************************
// proc_xmit_sbe function
//******************************************************************************
void proc_xmit_sbe( void *io_pArgs )
{
    errlHndl_t errl = NULL;

    // stub -- nothing here currently

    task_end2(errl);
}

} // namespace HWAS
