/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/sys/init/init_main.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2014              */
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
#include <kernel/console.H>  // TODO : Remove this.

#include <kernel/syscalls.H>
#include <sys/syscall.h>

#include <sys/task.h>
#include <sys/sync.h>
#include <sys/msg.h>
#include <sys/mmio.h>
#include <assert.h>


void* vfs_main(void*);

void* init_main(void* unused)
{
    tid_t   tidrc   =   0;
    barrier_t l_barrier;
    barrier_init(&l_barrier,2);

    printk("Starting init!\n");

    printk("Bringing up VFS...");
    task_create( &vfs_main, &l_barrier );

    barrier_wait(&l_barrier);

    //  run initialization service to start up everything else.
    printk("init_main: Starting Initialization Service...\n");
    tidrc   =   task_exec( "libinitservice.so", NULL );
    if ( (int16_t)tidrc < 0 )       //  task_exec returned an error.
    {
        printk( "ERROR: init_main: failed to launch initservice: %d\n", tidrc );

        crit_assert( 0 );        // stop here.
    }

    return NULL;
}
