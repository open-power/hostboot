//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/baseinitsvc/initservicetaskentry.C $
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
 * @file    initservicetaskentry.C
 *  task entry point for Initialization Service.
 *  init_main.C will call this by executing
 *          task_exec( "libinitservice.so", NULL );
 *  From there we can execute the classes that will run in the task.
 *
 *  At the end, we must run task_end().
 */
#include <kernel/console.H>
#include <sys/vfs.h>
#include <sys/task.h>
#include <trace/interface.H>
#include <errl/errlentry.H>

#include    "initservice.H"



namespace   INITSERVICE
{

extern  trace_desc_t *g_trac_initsvc;

/**
 *  @brief task entry routine, called  by init_main.C
 *
 */

extern "C"
void _start(void *ptr)
{
    TRACFCOMP( g_trac_initsvc,
            ENTER_MRK "Executing Initialization Service module." );

    // initialize the base modules in Hostboot.
    InitService::getTheInstance().init( ptr );

    TRACFCOMP( g_trac_initsvc,
            EXIT_MRK "return from Initialization Service module." );

    printk( "Initialization Service terminated.\n" );

    task_end();
}

}   // namespace
