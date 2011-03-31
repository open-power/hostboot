#include <kernel/console.H>
#include <sys/mutex.h>
#include <sys/vfs.h>
#include <sys/task.h>
#include <tracinterface.H>

//static mutex_t value = mutex_create();

trace_desc_t g_exampleTrace;
TRAC_INIT(&g_exampleTrace, "EXAMPLE", 4096);

extern "C"
void _start(void*)
{
    printk("Executing example module.\n");
    TRACFCOMP(g_exampleTrace, "Executing example module: %d", task_gettid());
    task_end();
}
