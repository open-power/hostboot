/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vfs/test/vfstest.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#ifndef __VFSTEST_H
#define __VFSTEST_H

#include <cxxtest/TestSuite.H>
#include <vfs/vfs.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <string.h>


class VfsTest: public CxxTest::TestSuite
{
    public:

        /**
         * @brief VFS read data module
         */
        void test_readDataModule( void )
        {
            errlHndl_t err = NULL;
            size_t size = 0;
            const char * addr = NULL;

            err = VFS::module_load("testdata");
            if(err)
            {
                TS_FAIL("module_load failed");
                ERRORLOG::errlCommit(err,VFS_COMP_ID);
            }

            err = VFS::module_address("testdata",addr,size);
            if(err)
            {
                TS_FAIL("module_address failed");
                ERRORLOG::errlCommit(err,VFS_COMP_ID);
            }
            else
            {
                if(memcmp(addr,"This is a test image",20))
                {
                    TS_FAIL("Data module addr = %p, size = %ld",addr,size);
                    TS_FAIL("%s",addr);
                }
            }

            err = VFS::module_unload("testdata");
            if(err)
            {
                TS_FAIL("module_unload failed");
            }
        }

        void test_findModule(void)
        {
            size_t size = 0;
            const char * addr = NULL;
            const char * name = "testdata";

            errlHndl_t err = VFS::module_address(name , addr, size);
            if (err)
            {
                TS_FAIL("module_address failed");
                ERRORLOG::errlCommit(err,VFS_COMP_ID);
            }

            name = VFS::module_find_name(addr);
            TS_TRACE("VFS module @ %p is %s",addr,name);

            if(strcmp(name,"testdata") != 0)
            {
                TS_FAIL("VFS find module by address failed!");
            }

            if(VFS::module_is_loaded(name))
            {
                TS_TRACE("VFS module %s is loaded",name);
                TS_FAIL("VFS module should NOT be loaded");
            }
            else
            {
                TS_TRACE("VFS module %s is not loaded",name);
            }
        }
};


#endif
