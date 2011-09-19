//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/vfs/test/vfstest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
                ERRORLOG::errlCommit(err);
            }

            err = VFS::module_address("testdata",addr,size);
            if(err)
            {
                TS_FAIL("module_address failed");
                ERRORLOG::errlCommit(err);
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
};


#endif
