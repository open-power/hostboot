#include <kernel/console.H>  // TODO : Remove this.
#include <sys/syscall.h>     // TODO : Remove this.

void init_main(void* unused)
{
    printk("Starting init!\n");

    while(1)
    {
	_syscall0(Systemcalls::TASK_YIELD);
	for (volatile int i = 0 ; i < 100000; i++);
    }
}
