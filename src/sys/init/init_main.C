#include <kernel/console.H>  // TODO : Remove this.

#include <kernel/syscalls.H>
#include <sys/syscall.h>

#include <sys/task.h>
#include <sys/mutex.h>
#include <sys/msg.h>
#include <sys/mmio.h>

mutex_t global_mutex;

/*
void init_child(void* unused)
{
    mutex_lock(global_mutex);
    printk("Crun: %d on %d\n", task_gettid(), task_getcpuid());
    mutex_unlock(global_mutex);
    for (volatile int i = 0 ; i < 100000; i++);
    task_end();
}
*/

void vfs_main(void*);

void init_main(void* unused)
{
    printk("Starting init!\n");
    
    printk("Bringing up VFS..."); 
    task_create(&vfs_main, NULL);
    
    // TODO... add a barrier to ensure VFS is fully up.
    while (NULL == _syscall0(Systemcalls::MSGQ_RESOLVE_ROOT))
	task_yield(); 


/* 
    uint64_t* mmio_addr = (uint64_t*) mmio_map((void*)0x800000000, 1);
    printk("MMIO Access %lx\n", *mmio_addr);

    global_mutex = mutex_create();

    msg_q_t msgq = msg_q_create();
    msg_q_register(msgq, "/msg/init");

    msg_t* msg = msg_allocate();
    msg->type = 1; msg->data[0] = 0xDEADBEEF12345678;
    msg_send(msgq, msg);
    msg = msg_wait(msgq);

    printk("Got Message: %lx\n", msg->data[0]);

    while(1)
    {
	mutex_lock(global_mutex);
	int t = task_create(&init_child, NULL);
	printk("Create child %d\n", t);
	for (volatile int i = 0 ; i < 1000000; i++);
	mutex_unlock(global_mutex);
    }
*/

    task_exec("libexample.so", NULL);
    
    while(1)
	task_yield();
}
