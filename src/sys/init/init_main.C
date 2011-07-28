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
