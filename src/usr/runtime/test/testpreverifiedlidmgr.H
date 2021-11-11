/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/test/testpreverifiedlidmgr.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
#ifndef _TESTPREVERIFIEDLIDMGR_H
#define _TESTPREVERIFIEDLIDMGR_H

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <runtime/preverifiedlidmgr.H>
#include <secureboot/service.H>
#include <usr/vmmconst.h>
#include <runtime/populate_hbruntime.H>
#include <pnor/pnorif.H>
#include <runtime/common/runtime_utils.H>
#include <vfs/vfs.H>

extern trace_desc_t* g_trac_runtime;

class PreVerifiedLidMgrTest : public CxxTest::TestSuite
{
  public:

    void testPreVerifiedLidMgrInit()
    {
        // Initialize Pre verified lid manager with test address space and
        // payload kind none
        PreVerifiedLidMgr::initLock(PREVERLIDMGR_TEST_ADDR);

        // Get Instance of Pre-Verified lid manager
        auto l_preVerLidMgr = PreVerifiedLidMgr::getInstance();

        if (l_preVerLidMgr.cv_payloadKind != TARGETING::PAYLOAD_KIND_NONE)
        {
            TS_FAIL("testPreVerifiedLidMgrInit> payload kind incorrect");
        }

        if (l_preVerLidMgr.cv_resvMemInfo.curAddr != PREVERLIDMGR_TEST_ADDR)
        {
            TS_FAIL("testPreVerifiedLidMgrInit> payload kind incorrect");
        }

        PreVerifiedLidMgr::unlock();
    }

    void testLoadFromPnor()
    {
        TRACFCOMP( g_trac_runtime, ENTER_MRK"testLoadFromPnor start" );

        errlHndl_t l_errl = nullptr;

        do {

        // Initialize Pre verified lid manager with test address space and
        // payload kind none
        PreVerifiedLidMgr::initLock(PREVERLIDMGR_TEST_ADDR);

        // Get Instance of Pre-Verified lid manager
        auto l_preVerLidMgr = PreVerifiedLidMgr::getInstance();

        // Clear lids loaded cache as other test cases fill it in.
        l_preVerLidMgr.cv_lidsLoaded.clear();

        // Handle all Pre verified PNOR sections
        for (const auto & secIdPair : RUNTIME::preVerifiedPnorSections)
        {
            TRACFCOMP( g_trac_runtime, "section=%d", secIdPair.first  );

            l_errl = RUNTIME::hbResvLoadSecureSection(secIdPair.first,
                                                      secIdPair.second);
            if (l_errl)
            {
                errlCommit(l_errl, RUNTIME_COMP_ID);
                TS_FAIL("testLoadFromPnor> Failed to Load Pnor Section %s",
                        PNOR::SectionIdToString(secIdPair.first));
                break;
            }
        }
        if (l_errl)
        {
            break;
        }

        // Each section has 2 lids each (Header, Content)
        // Note: even the RINGOVD section adds a Header element, although it is
        //       INVALID_LID
        // See runtime_utils.C for full list of PNOR sections and utillidpnor.C
        //     for the mappings (PnorToLidsMap)
        size_t l_numSections = RUNTIME::preVerifiedPnorSections.size();
        size_t l_expectedLids = (2 * l_numSections);
        if (SECUREBOOT::enabled())
        {
            // RINGOVD not permitted in secure mode, unless we are allowing
            // attribute overrides.. Meaning the Header and Content lid will
            // be missing.
            if (!SECUREBOOT::allowAttrOverrides())
            {
                l_expectedLids -= 2;
            }
        }

        // Ensure the expected number of lids were loaded.
        if (l_preVerLidMgr.cv_lidsLoaded.size() != l_expectedLids)
        {
            TS_FAIL("testLoadFromPnor> Num of lids loaded not correct %d expected %d",
                    l_preVerLidMgr.cv_lidsLoaded.size(),
                    l_expectedLids);
            break;
        }

        } while(0);

        PreVerifiedLidMgr::unlock();

        TRACFCOMP( g_trac_runtime, EXIT_MRK"testLoadFromPnor complete" );
    }

    // Handle the case where we are running the testcases before the
    //  libruntime.so module has been loaded
    bool iv_loaded_libruntime;

    PreVerifiedLidMgrTest()
      : CxxTest::TestSuite(), iv_loaded_libruntime(false)
    {
        // Need to load up the runtime module if it isn't already loaded
        if (  !VFS::module_is_loaded( "libruntime.so" ) )
        {
            errlHndl_t errhdl = VFS::module_load( "libruntime.so" );
            if ( errhdl )
            {
                TS_FAIL("PreVerifiedLidMgrTest> Failed to load libruntime.so");
                errlCommit(errhdl,RUNTIME_COMP_ID);
            }
            else
            {
                iv_loaded_libruntime = true;
            }
        }
    }

    ~PreVerifiedLidMgrTest()
    {
        if( iv_loaded_libruntime )
        {
            errlHndl_t errhdl = VFS::module_unload( "libruntime.so" );
            if ( errhdl )
            {
                TS_FAIL("PreVerifiedLidMgrTest> Failed to unload libruntime.so");
                errlCommit(errhdl,RUNTIME_COMP_ID);
            }
        }
    }
};

#endif
