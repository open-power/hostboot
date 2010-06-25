#include <kernel/console.H>  // TODO : Remove this.

#include <sys/task.h>
#include <sys/mutex.h>
#include <sys/msg.h>

mutex_t global_mutex;

void init_child(void* unused)
{
    mutex_lock(global_mutex);
    printk("Here I am %d\n", task_gettid());
    mutex_unlock(global_mutex);
    task_end();
}

void vfs_main(void*);

void init_main(void* unused)
{
    printk("Starting init!\n");
    
    printk("Bringing up VFS...");
    task_create(&vfs_main, NULL);
    task_yield(); // TODO... add a barrier to ensure VFS is fully up.

    global_mutex = mutex_create();

    msg_q_t msgq = msg_q_create();
    msg_q_register(msgq, "/msg/init");

    msg_t* msg = msg_allocate();
    msg->type = 1; msg->data[0] = 0xDEADBEEF12345678;
    msg_send(msgq, msg);
    msg = msg_wait(msgq);

    printk("Got Message: %llx\n", msg->data[0]);

    while(1)
    {
	mutex_lock(global_mutex);
	int t = task_create(&init_child, NULL);
	printk("Created child %d\n", t);
	for (volatile int i = 0 ; i < 10000000; i++);
	mutex_unlock(global_mutex);
    }
}
