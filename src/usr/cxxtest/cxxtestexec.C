#include <sys/vfs.h>
#include <sys/task.h>
#include <string.h>
#include <kernel/console.H>

namespace CxxTest
{
    uint64_t g_ModulesStarted = 0;
    uint64_t g_ModulesCompleted = 0;
}

/* Iterate through all modules in the VFS named "libtest*" and create children
 * tasks to execute them. 
 */
extern "C"
void _start(void*) 
{
    VfsSystemModule* vfsItr = &VFS_MODULES[0];

    printk( "Executing CxxTestExec module.\n");
    __sync_add_and_fetch(&CxxTest::g_ModulesStarted, 1);

    while(vfsItr->module[0] != '\0')
    {
        if (0 == memcmp(vfsItr->module, "libtest", 7))
        {
            if (NULL != vfsItr->start)
            {
                __sync_add_and_fetch(&CxxTest::g_ModulesStarted, 1);
                task_exec(vfsItr->module, NULL);
            }
        }
        vfsItr++;
    }

    __sync_add_and_fetch(&CxxTest::g_ModulesCompleted, 1);

    task_end();
}
