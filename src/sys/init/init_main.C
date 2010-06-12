#include <kernel/console.H>  // TODO : Remove this.

#include <sys/task.h>
#include <sys/mutex.h>

mutex_t global_mutex;

void init_child(void* unused)
{
    mutex_lock(global_mutex);
    printk("Here I am %d\n", task_gettid());
    mutex_unlock(global_mutex);
    task_end();
}

void init_main(void* unused)
{
    printk("Starting init!\n");

    global_mutex = mutex_create();

    while(1)
    {
	mutex_lock(global_mutex);
	int t = task_create(&init_child, NULL);
	printk("Created child %d\n", t);
	for (volatile int i = 0 ; i < 10000000; i++);
	mutex_unlock(global_mutex);
    }
}
