//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/sys/init/init_main.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2010 - 2011
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
#include <kernel/console.H>  // TODO : Remove this.

#include <kernel/syscalls.H>
#include <sys/syscall.h>

#include <sys/task.h>
#include <sys/sync.h>
#include <sys/msg.h>
#include <sys/mmio.h>
#include <assert.h>


void vfs_main(void*);

void init_main(void* unused)
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
    if ( (int16_t)tidrc < 0 )       //  task_exec returned a -1
    {
        printk( "ERROR: init_main: failed to launch initservice: %d\n", tidrc );

        crit_assert( 0 );        // stop here.
    }

    // should never reach this point...
    task_end();


    while(1)
        task_yield();
}
