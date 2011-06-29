#include <sys/vfs.h>
#include <sys/task.h>
#include <string.h>
#include <kernel/console.H>
#include <sys/time.h>
#include <sys/sync.h>

#include <cxxtest/TestSuite.H>

namespace CxxTest
{
    uint64_t    g_ModulesStarted = 0;
    uint64_t    g_ModulesCompleted = 0;
}

/**
 *  @brief _start()
 *  Iterate through all modules in the VFS named "libtest*" and create children
 * tasks to execute them.
 *
 */
extern "C"
void _start(void*)
{
    VfsSystemModule* vfsItr = &VFS_MODULES[0];
    tid_t   tidrc   =   0;

    printk( "Executing CxxTestExec.\n");
    __sync_add_and_fetch(&CxxTest::g_ModulesStarted, 1);

    while(vfsItr->module[0] != '\0')
    {
        if (0 == memcmp(vfsItr->module, "libtest", 7))
        {
            if (NULL != vfsItr->start)
            {
                __sync_add_and_fetch(&CxxTest::g_ModulesStarted, 1);

                printk( "CxxTestExec %d : running %s, ModulesStarted=0x%ld\n",
                        __LINE__,
                        vfsItr->module,
                        CxxTest::g_ModulesStarted );
                tidrc = task_exec( vfsItr->module, NULL );
                printk( "CxxTestExec %d : tidrc=%d\n",
                        __LINE__, tidrc );

            }
        }
        vfsItr++;
    }

    __sync_add_and_fetch(&CxxTest::g_ModulesCompleted, 1);
    printk( " ModulesCompleted=0x%ld\n", CxxTest::g_ModulesCompleted );


    printk( "total tests:   %ld\n", CxxTest::g_TotalTests  );
    printk( "failed tests:  %ld\n", CxxTest::g_FailedTests );
    printk( "warnings:      %ld\n", CxxTest::g_Warnings    );
    printk( "trace calls:   %ld\n", CxxTest::g_TraceCalls  );


    task_end();
}
