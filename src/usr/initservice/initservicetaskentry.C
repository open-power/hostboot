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

/**
 *  @brief task entry routine, called  by init_main.C
 *
 */

extern "C"
void _start(void *ptr)
{
    tid_t   tidrc   =   0;

    printk("===== Executing Initialization Service modules\n" );


    //  create an instance of InitService
    InitService::InitService& is =   InitService::getTheInstance();

    // initialize the base modules in Hostboot.
    is.start( ptr );



    //  -----   run unit tests and example code, if present ----------------
    /**
     * @todo    remove this eventually, figure out where to run UnitTests.
     */
    printk("===== Executing Unit Tests\n" );

    // run unit tests if present (i.e. we are running hbicore_test.bin)
    tidrc = task_exec("libcxxtest.so", NULL);

    /**
     * @todo   barrier here to wait for all the tests to finish...
     */

    printk( "===== Done, terminating Initialization service...");

    /**
     * @todo add assert(0) here???
     */


    task_end();
}

}   // INITSERVICE
