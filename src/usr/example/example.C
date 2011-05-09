/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 * $ag000                   andrewg     04/01/2011  Updated
 *
*/

#include <kernel/console.H>
#include <sys/mutex.h>
#include <sys/vfs.h>
#include <sys/task.h>
#include <trace/interface.H>

//static mutex_t value = mutex_create();
trace_desc_t *g_trac_test = NULL;
TRAC_INIT(&g_trac_test, "EXAMPLE", 4096);

extern "C"
void _start(void*)
{
    printk("Executing example module.\n");

    // Component trace tests
    //for(uint32_t i=0;i<100;i++)
    //{
        uint32_t i=0;
        TRACFCOMP(g_trac_test, "Executing example module: %d", task_gettid());
        TRACFCOMP(g_trac_test, "Test 2: %d %u %c", i,i+1,'a');
        TRACFCOMP(g_trac_test, "Test 3: %d %u 0x%X", i+2,i+3,
                  0x123456789ABCDEF0);
    //}

    // Pointer trace
    //TRACFCOMP(g_trac_test, "Pointer Test: %llp",g_trac_test);

    // Binary Trace
    TRACFBIN(g_trac_test,"Binary dump of trace descriptor",
             g_trac_test,sizeof(trace_desc_t));



    task_end();
}
