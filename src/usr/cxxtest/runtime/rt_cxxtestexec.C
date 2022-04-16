/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/cxxtest/runtime/rt_cxxtestexec.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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

#ifdef PROFILE_CODE
// There is not technically supposed to be a rt_vfs.H because
// rt_vfs.C is supposed to implement the exact API of the common
// vfs.H.  In the one off coverage case though, the test executor
// needs access to the special vfs_module_fini API.  Just forward
// declare the API defintion to make that access possible.
void vfs_module_fini();
#endif

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

            #ifdef PROFILE_CODE
            getRuntimeInterfaces()->unload = &vfs_module_fini;
            #endif
        }
    };
    registerCxxTest g_register;
}
