//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwas/hwas.C $
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
 *  @file hwas.C
 *
 *  HardWare Availability Service functions.
 *  See hwas.H for doxygen documentation tags.
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <kernel/console.H>
#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <targeting/targetservice.H>
#include    <fsi/fsiif.H>
#include    <hwas/hwas.H>
#include    <hwas/deconfigGard.H>
#include    <targeting/util.H>

namespace   HWAS
{
trace_desc_t *g_trac_hwas = NULL;
TRAC_INIT(&g_trac_hwas, "HWAS", 2048 );

using   namespace   TARGETING;


void    init_target_states( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( g_trac_hwas, "init_target_states entry: set default HWAS state:" );

    //  loop through all the targets and set HWAS_STATE to a known default
    TARGETING::TargetIterator l_pTarget = TARGETING::targetService().begin();
    for(    ;
            l_pTarget != TARGETING::targetService().end();
            ++l_pTarget
            )
    {
        // HWAS_STATE attribute definition in the attribute_types.xml file
        //  gets translated into TARGETING::HwasState .
        //  fetch it from targeting - this is not strictly necessary (right now)
        //  but makes debug easier later.
        TARGETING::HwasState l_hwasState =
            l_pTarget->getAttr<ATTR_HWAS_STATE>();

        l_hwasState.poweredOn             =   false;
        l_hwasState.present               =   false;
        l_hwasState.functional            =   false;
        l_hwasState.changedSinceLastIPL   =   false;
        l_hwasState.gardLevel             =   0;

        //  Now write the modified value back to Targeting.
        l_pTarget->setAttr<ATTR_HWAS_STATE>( l_hwasState );
    }


    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


void    init_fsi( void *io_pArgs )
{
    errlHndl_t  l_errl      =   NULL;
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( g_trac_hwas, "init_fsi entry" );

    l_errl  =   FSI::initializeHardware( );
    if ( l_errl )
    {
        TRACFCOMP( g_trac_hwas, "ERROR: failed to init FSI hardware" );
        pTaskArgs->postErrorLog( l_errl );
    }

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}

void    apply_fsi_info( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( g_trac_hwas, "apply_fsi_info entry" );


    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}

void    apply_dd_presence( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( g_trac_hwas, "apply_dd_presence entry" );


    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}

void    apply_pr_keyword_data( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( g_trac_hwas, "apply_pr_keyword_data" );


    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}

void    apply_partial_bad( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( g_trac_hwas, "apply_partial_bad entry" );


    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}

void    apply_gard( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( g_trac_hwas, "apply_gard entry" );

    errlHndl_t l_errl = theDeconfigGard().clearGardRecordsForReplacedTargets();

    if (l_errl)
    {
        TRACFCOMP(g_trac_hwas, "ERROR: apply_gard failed to clear GARD Records for replaced Targets");
        pTaskArgs->postErrorLog(l_errl);
    }
    else
    {
        l_errl = theDeconfigGard().deconfigureTargetsFromGardRecordsForIpl();

        if (l_errl)
        {
            TRACFCOMP(g_trac_hwas, "ERROR: apply_gard failed to deconfigure Targets from GARD Records for IPL");
            pTaskArgs->postErrorLog(l_errl);
        }
        else
        {
            TRACFCOMP(g_trac_hwas, "apply_gard completed successfully");
        }
    }

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


};   // end namespace

