#include <kernel/console.H>  // TODO : Remove this.

#include <sys/task.h>

void init_child(void* unused)
{
    printk("Here I am %d\n", task_gettid());
    task_end();
}

void init_main(void* unused)
{
    printk("Starting init!\n");

    while(1)
    {
	int t = task_create(&init_child, NULL);
	printk("Created child %d\n", t);
	for (volatile int i = 0 ; i < 10000000; i++);
    }
}
