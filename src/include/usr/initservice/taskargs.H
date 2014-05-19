/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/initservice/taskargs.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

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
 */

#define TASK_ENTRY_MACRO( MyInitFn )                                        \
        extern "C"                                                          \
        void * _start( void *io_pArgs )                                       \
        {                                                                   \
            errlHndl_t  io_rtaskRetErrl =   NULL;                           \
            void        *ret            =   NULL;                           \
                                                                            \
            MyInitFn( io_rtaskRetErrl );                                    \
                                                                            \
            ret =   reinterpret_cast<void *>(io_rtaskRetErrl);              \
            return ret;                                                    \
        }

#endif
