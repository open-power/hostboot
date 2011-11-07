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


namespace   HWAS
{
trace_desc_t *g_trac_hwas = NULL;
TRAC_INIT(&g_trac_hwas, "HWAS", 1024 );

using   namespace   TARGETING;

void    init_target_states( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( g_trac_hwas, "init_target_states entry" );


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

    //@todo
    //@VBU workaround - Disable init_fsi
    //Temporarily disable the FSI initialization in VBU because of
    //an MFSI/CFSI XSCOM hardware bug.
    TARGETING::EntityPath syspath(TARGETING::EntityPath::PATH_PHYSICAL);
    syspath.addLast(TARGETING::TYPE_SYS,0);
    TARGETING::Target* sys = TARGETING::targetService().toTarget(syspath);
    uint8_t vpo_mode = 0;
    if( sys
            && sys->tryGetAttr<TARGETING::ATTR_VPO_MODE>(vpo_mode)
            && (vpo_mode == 1) )
    {
        //  wait here on the barrier, then end the task.
        pTaskArgs->waitChildSync();
        task_end();
        TRACFCOMP( g_trac_hwas, "HWBUG Workaround - No FSI initialization");
        return;
    }

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


    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


};   // end namespace

