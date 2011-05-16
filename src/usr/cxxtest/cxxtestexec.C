#include <sys/vfs.h>
#include <sys/task.h>
#include <string.h>

/* Iterate through all modules in the VFS named "libtest*" and create children
 * tasks to execute them. 
 */
extern "C"
void _start(void*) 
{
    VfsSystemModule* vfsItr = &VFS_MODULES[0];

    while(vfsItr->module[0] != '\0')
    {
        if (0 == memcmp(vfsItr->module, "libtest", 7))
        {
            if (NULL != vfsItr->start)
            {
                task_exec(vfsItr->module, NULL);
            }
        }
        vfsItr++;
    }

    task_end();
}
