/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/cxxtest/runtime/rt_cxxtestexec.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
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
