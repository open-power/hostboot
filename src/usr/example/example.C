#include <kernel/console.H>
#include <sys/mutex.h>
#include <sys/vfs.h>
#include <sys/task.h>
#include <trace/interface.H>
#include <example/example.H>

//static mutex_t value = mutex_create();
trace_desc_t *g_trac_test = NULL;
TRAC_INIT(&g_trac_test, "EXAMPLE", 4096);

extern "C"
void _start(void*)
{
    printk("Executing example module.\n");

    task_end();
}

uint64_t example1_function()
{
    uint64_t    l_rc = 0;

    //TRACFCOMP(g_trac_test, "Someone Called example1_function!");

    return l_rc;
}
