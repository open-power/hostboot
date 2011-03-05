#include <kernel/console.H>
#include <sys/mutex.h>
#include <sys/vfs.h>
#include <sys/task.h>
#include <tracinterface.H>

static mutex_t value = mutex_create();

extern "C"
void _start(void*)
{
    printk("Executing example module.\n");
    task_end();
}
