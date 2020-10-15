/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/smf/test/testmemutils.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
#ifndef __TEST_MEM_UTILS_H
#define __TEST_MEM_UTILS_H

#include <cxxtest/TestSuite.H>

#include <isteps/mem_utils.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <errl/errlmanager.H>
#include <hbotcompid.H>
#include <stdint.h>
#include <vfs/vfs.H>


class MemUtilsTestSuite : public CxxTest::TestSuite
{
private:
    bool cv_isSmfLoaded;

public:

    MemUtilsTestSuite() : cv_isSmfLoaded(false)
    {
        errlHndl_t l_errl = nullptr;
        l_errl = VFS::module_load("libsmf.so");
        if(l_errl)
        {
            TS_FAIL("MemUtilsTestSuite(): could not load libsmf.so");
            errlCommit(l_errl, CXXTEST_COMP_ID);
            cv_isSmfLoaded = false;
        }
        else
        {
            cv_isSmfLoaded = true;
        }
    }

    ~MemUtilsTestSuite()
    {
        if(cv_isSmfLoaded)
        {
            errlHndl_t l_errl = nullptr;
            l_errl = VFS::module_unload("libsmf.so");
            if(l_errl)
            {
                TS_FAIL("~MemUtilsTestSuite(): could not unload libsmf.so");
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
        }
    }

    /**
     * @brief Test get_top_mem_addr and get_bottom_mem_addr helper functions;
     *        test both calls with and without a proc argument.
     */
    void testGetTopBotMemAddr() const
    {
        TS_INFO(ENTER_MRK "testGetTopBotMemAddr");
        errlHndl_t l_errl = nullptr;

        do {
        if(!cv_isSmfLoaded)
        {
            break;
        }

        const uint64_t TEST_TOP_MEM_SIZE = 0xdeadbeefbeefdead;
        TARGETING::ATTR_PROC_MEM_SIZES_type l_mProcMemSizes = {
            TEST_TOP_MEM_SIZE, 0, 0, 0, 0, 0, 0, 0};
        TARGETING::ATTR_PROC_MEM_BASES_type l_mProcMemBases = {
            0, 0, 0, 0, 0, 0, 0, 0};
        TARGETING::ATTR_PROC_MEM_SIZES_type l_origMemSizes = {};
        TARGETING::ATTR_PROC_MEM_BASES_type l_origMemBases = {};

        TARGETING::Target* l_masterProc = nullptr;

        l_errl = TARGETING::targetService()
                                 .queryMasterProcChipTargetHandle(l_masterProc);
        if(l_errl)
        {
            TS_FAIL("testGetTopBotMemAddr: could not get master proc");
            errlCommit(l_errl, CXXTEST_COMP_ID);
            break;
        }

        assert(l_masterProc->tryGetAttr<TARGETING::ATTR_PROC_MEM_SIZES>(l_origMemSizes),
               "Could not get ATTR_PROC_MEM_SIZES from a proc target!");
        assert(l_masterProc->tryGetAttr<TARGETING::ATTR_PROC_MEM_BASES>(l_origMemBases),
               "Could not get ATTR_PROC_MEM_BASES from a proc target!");

        uint64_t l_topMemAddr = ISTEP::get_top_mem_addr();
        // Default top addr should be something different
        if(l_topMemAddr == TEST_TOP_MEM_SIZE)
        {
            TS_FAIL("testGetTopBotMemAddr: unexpected default top address returned. Returned address: 0x%x", TEST_TOP_MEM_SIZE);
        }

        l_masterProc->setAttr<TARGETING::ATTR_PROC_MEM_SIZES>(l_mProcMemSizes);
        l_masterProc->setAttr<TARGETING::ATTR_PROC_MEM_BASES>(l_mProcMemBases);

        // Test the top system address
        l_topMemAddr = ISTEP::get_top_mem_addr();
        if(l_topMemAddr != TEST_TOP_MEM_SIZE)
        {
            TS_FAIL("testGetTopBotMemAddr: unexpected top address returned. Expected 0x%x, actual 0x%x", TEST_TOP_MEM_SIZE, l_topMemAddr);
        }

        // Test the top address of the master proc
        l_topMemAddr = ISTEP::get_top_mem_addr(l_masterProc);
        if(l_topMemAddr != TEST_TOP_MEM_SIZE)
        {
            TS_FAIL("testGetTopBotMemAddr: unexpected top address on master proc. Expected 0x%x, actual 0x%x", TEST_TOP_MEM_SIZE, l_topMemAddr);
        }

        const uint64_t BIG_MEM_BASE = 0x0fffffffffffffff;
        const uint64_t TEST_BOT_MEM_BASE = 0x1;
        TARGETING::ATTR_PROC_MEM_BASES_type l_mProcBotMemBases = {
         BIG_MEM_BASE, BIG_MEM_BASE, BIG_MEM_BASE, BIG_MEM_BASE, BIG_MEM_BASE,
         BIG_MEM_BASE, BIG_MEM_BASE, TEST_BOT_MEM_BASE };
        TARGETING::ATTR_PROC_MEM_SIZES_type l_mProcBotMemSizes = {
         1, 1, 1, 1, 1, 1, 1, 1 };

        uint64_t l_bottomMemAddr = ISTEP::get_bottom_mem_addr();
        // Default bottom address should be different
        if(l_bottomMemAddr == TEST_BOT_MEM_BASE)
        {
            TS_FAIL("testGetTopBotMemAddr: unexpected default bottom address returned. Returned address: 0x%x", TEST_BOT_MEM_BASE);
        }

        l_masterProc->setAttr<TARGETING::ATTR_PROC_MEM_BASES>(l_mProcBotMemBases);
        l_masterProc->setAttr<TARGETING::ATTR_PROC_MEM_SIZES>(l_mProcBotMemSizes);

        // Test the bottom system address
        l_bottomMemAddr = ISTEP::get_bottom_mem_addr();
        if(l_bottomMemAddr != TEST_BOT_MEM_BASE)
        {
            TS_FAIL("testGetTopBotMemAddr: unexpected bottom address returned. Expected 0x%x, actual 0x%x", TEST_BOT_MEM_BASE, l_bottomMemAddr);
        }

        // Test the bottom address of the master proc
        l_bottomMemAddr = ISTEP::get_bottom_mem_addr(l_masterProc);
        if(l_bottomMemAddr != TEST_BOT_MEM_BASE)
        {
            TS_FAIL("testGetTopBotMemAddr: unexpected bottom address on master proc. Expected 0x%x, actual 0x%x", TEST_BOT_MEM_BASE, l_bottomMemAddr);
        }


        // Restore the originals in case something else wants to use them
        l_masterProc->setAttr<TARGETING::ATTR_PROC_MEM_SIZES>(l_origMemSizes);
        l_masterProc->setAttr<TARGETING::ATTR_PROC_MEM_BASES>(l_origMemBases);
        } while(0);

        TS_INFO(EXIT_MRK "testGetTopBotMemAddr");
    }

    /**
     * @brief Test get_top_smf_mem_addr; test both calls with and without
     * a proc argument.
     */
    void testGetTopSmfMemAddr() const
    {
        TS_INFO(ENTER_MRK "testGetTopSmfMemAddr");
        errlHndl_t l_errl = nullptr;

        do {
        if(!cv_isSmfLoaded)
        {
            break;
        }

        const uint64_t TEST_SMF_MEM_SIZE = 0xbeefdeaddeadbeef;
        const uint64_t TEST_SMF_BAR = 0;

        TARGETING::Target* l_masterProc = nullptr;

        l_errl = TARGETING::targetService()
                                 .queryMasterProcChipTargetHandle(l_masterProc);
        if(l_errl)
        {
            TS_FAIL("testGetTopSmfMemAddr: could not get master proc");
            errlCommit(l_errl, CXXTEST_COMP_ID);
            break;
        }

        const auto l_origSmfMemBar =
                l_masterProc->getAttr<TARGETING::ATTR_PROC_SMF_BAR_BASE_ADDR>();
        const auto l_origSmfMemSize =
                l_masterProc->getAttr<TARGETING::ATTR_PROC_SMF_BAR_SIZE>();

        l_masterProc->
                  setAttr<TARGETING::ATTR_PROC_SMF_BAR_BASE_ADDR>(TEST_SMF_BAR);
        l_masterProc->
                  setAttr<TARGETING::ATTR_PROC_SMF_BAR_SIZE>(TEST_SMF_MEM_SIZE);

        uint64_t l_topSmfAddr = ISTEP::get_top_smf_mem_addr();
        if(l_topSmfAddr != TEST_SMF_MEM_SIZE)
        {
            TS_FAIL("testGetTopSmfMemAddr: unexpected top SMF address on the system. Expected 0x%x, actual 0x%x", TEST_SMF_MEM_SIZE, l_topSmfAddr);
        }

        l_topSmfAddr = ISTEP::get_top_smf_mem_addr(l_masterProc);
        if(l_topSmfAddr != TEST_SMF_MEM_SIZE)
        {
            TS_FAIL("testGetTopSmfMemAddr: unexpected top SMF address on master proc. Expected 0x%x, actual 0x%x", TEST_SMF_MEM_SIZE, l_topSmfAddr);
        }

        l_masterProc->
               setAttr<TARGETING::ATTR_PROC_SMF_BAR_BASE_ADDR>(l_origSmfMemBar);
        l_masterProc->
                   setAttr<TARGETING::ATTR_PROC_SMF_BAR_SIZE>(l_origSmfMemSize);
        } while(0);

        TS_INFO(EXIT_MRK "testGetTopSmfMemAddr");
    }

    /**
     * @brief test the get_top_homer_mem_addr helper function when SMF is
     *        enabled and disabled
     */
    void testGetTopHomerMemAddr() const
    {
        TS_INFO(ENTER_MRK"testGetTopHomerMemAddr");
        errlHndl_t l_errl = nullptr;

        do {
        if(!cv_isSmfLoaded)
        {
            break;
        }

        const uint64_t TEST_SMF_BAR = 0;
        const uint64_t TEST_SMF_BAR_SIZE = 0xdeadbeefdeadbeef;

        TARGETING::Target* l_sys = nullptr;
        TARGETING::Target* l_masterProc = nullptr;

        l_errl = TARGETING::targetService()
                                 .queryMasterProcChipTargetHandle(l_masterProc);
        if(l_errl)
        {
            TS_FAIL("testGetTopHomerMemAddr: could not get master proc");
            errlCommit(l_errl, CXXTEST_COMP_ID);
            break;
        }

        TARGETING::targetService().getTopLevelTarget(l_sys);
        assert(l_sys, "testGetTopHomerMemAddr: could not get top level target");

        const auto l_origSmfMemBar =
                l_masterProc->getAttr<TARGETING::ATTR_PROC_SMF_BAR_BASE_ADDR>();
        const auto l_origSmfMemSize =
                l_masterProc->getAttr<TARGETING::ATTR_PROC_SMF_BAR_SIZE>();

        l_masterProc->
                  setAttr<TARGETING::ATTR_PROC_SMF_BAR_BASE_ADDR>(TEST_SMF_BAR);
        l_masterProc->
                  setAttr<TARGETING::ATTR_PROC_SMF_BAR_SIZE>(TEST_SMF_BAR_SIZE);

        l_sys->setAttr<TARGETING::ATTR_SMF_CONFIG>(false);

        uint64_t l_topHomerAddr = ISTEP::get_top_homer_mem_addr();
        if(l_topHomerAddr == TEST_SMF_BAR_SIZE)
        {
            // We should have gotten something different with SMF disabled
            TS_FAIL("testGetTopHomerMemAddr: unexpected address returned from get_top_homer_mem_addr while SMF is DISABLED. Returned address: 0x%x", l_topHomerAddr);
        }

        l_sys->setAttr<TARGETING::ATTR_SMF_CONFIG>(true);
        l_topHomerAddr = ISTEP::get_top_homer_mem_addr();
        if(l_topHomerAddr != TEST_SMF_BAR_SIZE)
        {
            TS_FAIL("testGetTopHomerMemAddr: unexpected address returned from get_top_homer_mem_addr while SMF is ENABLED. Expected 0x%x, actual 0x%x", TEST_SMF_BAR_SIZE, l_topHomerAddr);
        }

        // Restore originals
        l_masterProc->
               setAttr<TARGETING::ATTR_PROC_SMF_BAR_BASE_ADDR>(l_origSmfMemBar);
        l_masterProc->
                   setAttr<TARGETING::ATTR_PROC_SMF_BAR_SIZE>(l_origSmfMemSize);
        l_sys->setAttr<TARGETING::ATTR_SMF_CONFIG>(false);
        } while(0);

        TS_INFO(EXIT_MRK"testGetTopHomerMemAddr");
    }

};

#endif
