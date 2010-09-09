#include <kernel/console.H>
#include <sys/mutex.h>
#include <sys/vfs.h>
#include <sys/task.h>

static mutex_t value = mutex_create();

extern "C"
void _init(void*)
{
    // Call default constructors for any static objects.
    extern void (*ctor_start_address)();
    extern void (*ctor_end_address)();
    void(**ctors)() = &ctor_start_address;
    while(ctors != &ctor_end_address)
    {
	(*ctors)();
	ctors++;
    }

    printk("Here! %llx, %s\n", (uint64_t) value, VFS_ROOT);
}

extern "C"
void _start(void*)
{
    task_end();
}
