/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/test/test_checkHbResMemLimit.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
#ifndef _TEST_CHECKHBRESMEMLIMIT_H
#define _TEST_CHECKHBRESMEMLIMIT_H

#include <cxxtest/TestSuite.H>
#include <runtime/populate_hbruntime.H>
#include <errl/errlmanager.H>
#include <hdat/hdat.H>
#include <runtime/interface.h>
#include <runtime/runtime_reasoncodes.H>
#include <vmmconst.h>
#include <vfs/vfs.H>

// Hardcode address limits to match our known setup in standalone simics
const uint64_t HB_BASE_ADDR = 4*GIGABYTE - 512*MEGABYTE;
const uint64_t HB_RES_MEM_LOWER_LIMIT = HB_BASE_ADDR + RESERVED_MEM_START_OFFSET;
const uint64_t HB_RES_MEM_UPPER_LIMIT = HB_BASE_ADDR + RESERVED_MEM_END_OFFSET;

extern trace_desc_t* g_trac_runtime;

class CheckHbResMemLimitTest : public CxxTest::TestSuite
{
public:

    void testAddressWithinHbResMemRange()
    {
        TRACFCOMP(g_trac_runtime, "testAddressWithinHbResMemRange running");
        errlHndl_t l_errl = nullptr;
        l_errl = RUNTIME::checkHbResMemLimit(HB_RES_MEM_LOWER_LIMIT, //i_addr
                                             1); //i_size
        if(l_errl)
        {
            TS_FAIL("testAddressWithinHbResMemRange: checkHbResMemLimit"
                                               " returned an unexpected error");
            errlCommit(l_errl, CXXTEST_COMP_ID);
        }
        else
        {
            TRACDCOMP(g_trac_runtime, "testAddressWithinHbResMemRange:"
                                               " no error returned (expected)");
        }
        TRACFCOMP(g_trac_runtime, "testAddressWithinHbResMemRange finished");
    }

    void testAddressAboveHbResMemRange()
    {
        TRACFCOMP(g_trac_runtime, "testAddressAboveHbResMemRange running");
        errlHndl_t l_errl = nullptr;
        l_errl = RUNTIME::checkHbResMemLimit(HB_RES_MEM_UPPER_LIMIT, //i_addr
                                             10); //i_size
        do{

        if(l_errl)
        {
            TRACDCOMP(g_trac_runtime, "testAddressAboveHbResMemRange:"
                      " errl returned (expected)");

            //Check module id and reason code
            if((l_errl->moduleId() == RUNTIME::MOD_CHECK_HB_RES_MEM_LIMIT) and
               (l_errl->reasonCode() == RUNTIME::RC_HB_RES_MEM_EXCEEDED))
            {
                TRACDCOMP(g_trac_runtime, "testAddressAboveHbResMemRange:"
                " error's module id and reason code match expected values");
            }
            else
            {
                TS_FAIL("testAddressAboveHbResMemRange: error with unexpected"
                        " module id/reason code returned. Expected module id = "
                        "0x%x returned module id = 0x%x; expected reason code ="
                        " 0x%x returned reason code = 0x%x",
                        RUNTIME::MOD_CHECK_HB_RES_MEM_LIMIT,
                        l_errl->moduleId(),
                        RUNTIME::RC_HB_RES_MEM_EXCEEDED,
                        l_errl->reasonCode());
                errlCommit(l_errl, CXXTEST_COMP_ID);
                break;
            }
            delete l_errl;
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("testAddressAboveHbResMemRange: no errl returned from"
                                   " checkHbResMemLimit under error condition");
        }

        }while(0);
        TRACFCOMP(g_trac_runtime, "testAddressAboveHbResMemRange finished");
    }

    void testAddressBelowHbResMemRange()
    {
        TRACFCOMP(g_trac_runtime, "testAddressBelowHbResMemRange running");

        errlHndl_t l_errl = nullptr;
        l_errl = RUNTIME::checkHbResMemLimit(HB_RES_MEM_LOWER_LIMIT
                                             - 11, //i_addr
                                               10); //i_size
        do{

        if(l_errl)
        {
            TRACDCOMP(g_trac_runtime, "testAddressBelowHbResMemRange:"
                                                  " errl returned (expected).");
            //Check module id and reason code
            if((l_errl->moduleId() == RUNTIME::MOD_CHECK_HB_RES_MEM_LIMIT) and
               (l_errl->reasonCode() == RUNTIME::RC_HB_RES_MEM_EXCEEDED))
            {
                TRACDCOMP(g_trac_runtime, "testAddressBelowHbResMemRange:"
                " error's module id and reason code match expected values");
            }
            else
            {
                TS_FAIL("testAddressBelowHbResMemRange: error with unexpected"
                        " module id/reason code returned. Expected module id = "
                        "0x%x returned module id = 0x%x; expected reason code ="
                        " 0x%x returned reason code = 0x%x",
                        RUNTIME::MOD_CHECK_HB_RES_MEM_LIMIT,
                        l_errl->moduleId(),
                        RUNTIME::RC_HB_RES_MEM_EXCEEDED,
                        l_errl->reasonCode());
                errlCommit(l_errl, CXXTEST_COMP_ID);
                break;
            }
            delete l_errl;
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("testAddressBelowHbResMemRange: no errl returned from"
                                   " checkHbResMemLimit under error condition");
        }

        }while(0);
        TRACFCOMP(g_trac_runtime, "testAddressBelowHbResMemRange finished");
    }


    // Handle the case where we are running the testcases before the
    //  libruntime.so module has been loaded
    bool iv_loaded_libruntime;

    CheckHbResMemLimitTest()
      : CxxTest::TestSuite(), iv_loaded_libruntime(false)
    {
        // Need to load up the runtime module if it isn't already loaded
        if (  !VFS::module_is_loaded( "libruntime.so" ) )
        {
            errlHndl_t errhdl = VFS::module_load( "libruntime.so" );
            if ( errhdl )
            {
                TS_FAIL("CheckHbResMemLimitTest> Failed to load libruntime.so");
                errlCommit(errhdl,RUNTIME_COMP_ID);
            }
            else
            {
                iv_loaded_libruntime = true;
            }
        }
    }

    ~CheckHbResMemLimitTest()
    {
        if( iv_loaded_libruntime )
        {
            errlHndl_t errhdl = VFS::module_unload( "libruntime.so" );
            if ( errhdl )
            {
                TS_FAIL("CheckHbResMemLimitTest> Failed to unload libruntime.so");
                errlCommit(errhdl,RUNTIME_COMP_ID);
            }
        }
    }
};


#endif
