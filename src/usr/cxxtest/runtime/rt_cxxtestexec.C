/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/cxxtest/runtime/rt_cxxtestexec.C $                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include <cxxtest/TestSuite.H>
#include <limits.h>
#include <hbotcompid.H>
#include <runtime/interface.h>

#include <kernel/console.H>
#include <vfs/vfs.H>

trace_desc_t *g_trac_cxxtest = NULL;
TRAC_INIT(&g_trac_cxxtest, CXXTEST_COMP_NAME, KILOBYTE );

namespace CxxTest
{
    void execute(void* io_stats)
    {
        CxxTestStats* stats = reinterpret_cast<CxxTestStats*>(io_stats);

        std::vector<const char*> module_list;
        VFS::find_test_modules(module_list);

        printk("Running Runtime CXX Tests: %ld\n", module_list.size());

        g_ModulesStarted++;
        for (std::vector<const char*>::const_iterator i = module_list.begin();
             i != module_list.end();
             ++i)
        {
            g_ModulesStarted++;

            printk("\tRunning Runtime test: %s\n", *i);
            void* (*start_entry)(void*) = reinterpret_cast<void*(*)(void*)>(
                vfs_start_entrypoint(vfs_find_module(VFS_MODULES, *i)));
            start_entry(NULL);
        }

        g_ModulesCompleted++;

        __sync_add_and_fetch(stats->totalTests, g_TotalTests);
        __sync_add_and_fetch(stats->traceCalls, g_TraceCalls);
        __sync_add_and_fetch(stats->warnings, g_Warnings);
        __sync_add_and_fetch(stats->failedTests, g_FailedTests);
        __sync_add_and_fetch(stats->modulesStarted, g_ModulesStarted);
        __sync_add_and_fetch(stats->modulesCompleted, g_ModulesCompleted);
    }

    struct registerCxxTest
    {
        registerCxxTest()
        {
            getRuntimeInterfaces()->cxxtestExecute = &execute;
        }
    };
    registerCxxTest g_register;
}
