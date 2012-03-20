//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/initservice/taskargs.H $
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

#ifndef __TASKARGS_TASKARGS_H
#define __TASKARGS_TASKARGS_H

/**
 * @file    taskargs.H
 *
 *  Common file to hold arguments passed to and from tasks.
 *
 */

#include    <assert.h>
#include    <sys/sync.h>
#include    <trace/interface.H>
#include    <sys/task.h>                // needed to make macro work

#include    <errl/errlentry.H>
#include    <errl/errlmanager.H>

/**
 *
 *  @def TASK_ENTRY_MACRO( MyInitFn )
 *
 *  set up a _start() task entry routine.
 *
 *  MyInitFn should be declared in your task/namespace with one parameter,
 *      a reference to an errorlog.
 *
 *      Example:
 *
 *      static void init( errlHndl_t &io_rtaskRetErrl );
 *
 *  Then if you wish to terminate with an error, say
 *
 *      io_rtaskRetErrl =   my_errl;
 *      return;
 *
 *  This is not as flexible as the old TaskArgs setup but much simpler.
 *
 *  Alternatively you can call task_end2() directly from the MyInitFn:
 *
 *      task_end2( l_errl );
 *
 */

#define TASK_ENTRY_MACRO( MyInitFn )                                        \
        extern "C"                                                          \
        void _start( void *io_pArgs )                                       \
        {                                                                   \
            errlHndl_t  io_rtaskRetErrl =   NULL;                           \
            void        *ret            =   NULL;                           \
                                                                            \
            MyInitFn( io_rtaskRetErrl );                                    \
                                                                            \
            ret =   reinterpret_cast<void *>(io_rtaskRetErrl);              \
                                                                            \
            task_end2( ret );                                               \
        }

#endif
