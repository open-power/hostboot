/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/test/testhllmgr.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2024                        */
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
#ifndef _TESTHLLMGR_H
#define _TESTHLLMGR_H


#include <cxxtest/TestSuite.H>
#include <util/utilhllmgr.H>
#include "../utilbase.H"

namespace HLL
{
extern const GroupID g_HLLPowerVM;

// Define default vectors to simplify syntax
const std::vector<uint32_t> defaultLids {0xA1234567, 0x89ABCDEF, 0x13579246};
}

using namespace HLL;

class HLLTest : public CxxTest::TestSuite
{
public:

    class TestHll
    {
        public:
        // Actual Size
        size_t iv_size;

        // Pointers to internal buffer
        uint8_t* iv_bufferCur;
        uint8_t* iv_bufferStart;

        // Pointers within internal buffer to useful information
        HLLHeader* iv_pHeader;

        // Max Size of buffer
        size_t iv_maxSize = sizeof(HLLHeader) + sizeof(PowerVmHeader) + (sizeof(uint32_t) * HLL::defaultLids.size());

        // Group Info Cache
        GroupInfoMap iv_groupInfoCache;

        // Vector of test lids
        std::vector<uint32_t> iv_testLids;

        bool iv_bad_format = false; // flag to indicate whether to populate custom HLL with invalid info

        TestHll(bool i_bad_format = false)
        : iv_size(0),iv_bufferCur(nullptr),iv_bufferStart(nullptr),
          iv_pHeader(nullptr), iv_groupInfoCache{}, iv_testLids{HLL::defaultLids}, iv_bad_format(i_bad_format)
        {
            initHll();
        }

        void initHll()
        {
            iv_bufferStart = new uint8_t[iv_maxSize]();
            iv_bufferCur = iv_bufferStart;
            genHll();
        }

        ~TestHll()
        {
            delete[] iv_bufferStart;
            iv_bufferStart = nullptr;
        }

        void genHll()
        {
            // Set up some dummy info in the hand built HLL to exercise the real HLLMgr class constructor
            auto l_pHdr = reinterpret_cast<HLLHeader*>(iv_bufferCur);
            l_pHdr->OffsetToPowerVM = sizeof(HLLHeader);
            l_pHdr->EyeCatcher = HLL_EYE_CATCHER;
            if (iv_bad_format)
            {
                l_pHdr->version = 0xFF; // some invalid version
                l_pHdr->CompatibleVersion = 0xFF; // some invalid version
            }
            else
            {
                l_pHdr->version = HLL_SUPPORTED_VERSION;
            }
            auto l_pPowerVMHdr = reinterpret_cast<PowerVmHeader*>(iv_bufferCur+l_pHdr->OffsetToPowerVM);
            l_pPowerVMHdr->EyeCatcher = HLL_POWERVM_EYE_CATCHER;
            l_pPowerVMHdr->NumberOfPowerVmLids = iv_testLids.size();

            // Seed the test HLL with a simulated PowerVM group to dump out
            // Goal is to just exercise the HLLMgr class constructor
            GroupInfo l_groupInfo (HllEntryFlags::SIGNED_PRE_VERIFY);
            auto l_pLids = reinterpret_cast<uint32_t*>(l_pPowerVMHdr->PowerVmLids);
            for (uint8_t lid = 0; lid < l_pPowerVMHdr->NumberOfPowerVmLids; ++lid)
            {
                *l_pLids = iv_testLids[lid];
                LidInfo l_lidInfo(*l_pLids);
                l_lidInfo.hllHash = {};
                l_groupInfo.lidIds.push_back(l_lidInfo);
                l_pLids++;
            }
            iv_groupInfoCache.insert(std::make_pair(g_HLLPowerVM, l_groupInfo));

            // Dump out the Test dummy HLL which should only have the PowerVM group populated
            UTIL_FT("TestHll::printGroupInfoCache:");
            for (const auto &i : iv_groupInfoCache)
            {
                UTIL_FBIN("- Group Id:", &i.first, sizeof(GroupID));
                i.second.print();
            }

            // Store HLL header pointer for reference
            iv_pHeader = l_pHdr;
        }
    };

    void testHllGood()
    {
        UTIL_FT("testHllGood ENTER");
        // Create a dummy test HLL with minimal info
        TestHll l_TestHll {};

        // Send the pre-populated test HLL to the real HLLMgr
        HLLMgr l_hll(l_TestHll.iv_bufferStart,
                                    l_TestHll.iv_maxSize);

        // Simple checks to validate the buffer
        auto l_pHdr_checker = reinterpret_cast<HLLHeader*>(l_TestHll.iv_bufferStart);
        if (l_pHdr_checker->EyeCatcher != HLL_EYE_CATCHER)
        {
            TS_FAIL("testHllGood problem l_pHdr_checker->EyeCatcher=0x%X should match HLL_EYE_CATCHER=0x%X",
                l_pHdr_checker->EyeCatcher, HLL_EYE_CATCHER);
        }
        else
        {
            TS_INFO("testHllGood good results l_pHdr_checker->EyeCatcher=0x%X matches HLL_EYE_CATCHER=0x%X",
                l_pHdr_checker->EyeCatcher, HLL_EYE_CATCHER);
        }
        auto l_pPowerVMHdr_checker = reinterpret_cast<PowerVmHeader*>(l_TestHll.iv_bufferStart+l_pHdr_checker->OffsetToPowerVM);
        if (l_pPowerVMHdr_checker->EyeCatcher != HLL_POWERVM_EYE_CATCHER)
        {
            TS_FAIL("testHllGood problem l_pPowerVMHdr_checker->EyeCatcher=0x%X should match HLL_POWERVM_EYE_CATCHER=0x%X",
                l_pPowerVMHdr_checker->EyeCatcher, HLL_POWERVM_EYE_CATCHER);
        }
        else
        {
            TS_INFO("testHllGood good results l_pPowerVMHdr_checker->EyeCatcher=0x%X matches HLL_POWERVM_EYE_CATCHER=0x%X",
                l_pPowerVMHdr_checker->EyeCatcher, HLL_POWERVM_EYE_CATCHER);
        }

        // Dump out the real HLLMgr cache
        l_hll.printGroupInfoCache();

        // Check that the versions are good
        bool version_checks_good = l_hll.isValid();
        if (version_checks_good)
        {
            TS_INFO("testHllGood version checks passed");
        }
        else
        {
            TS_FAIL("testHllGood version checks failed");
        }

        // We would need some real lids available to load with PLDM
        // to test out the methods managePowerVMGroup or
        // managePreVerifiedGroup, so since these are standalone tests
        // we are only exercising the class creation and some simple
        // validations.

        UTIL_FT("testHllGood EXIT");
    }

        void testHllBad()
    {
        UTIL_FT("testHllBad ENTER");
        // Create a bad dummy test HLL with minimal info
        TestHll l_TestHll {true};

        // Send the pre-populated badly formatted test HLL to the real HLLMgr
        HLLMgr l_hll(l_TestHll.iv_bufferStart,
                                    l_TestHll.iv_maxSize);

        // Check that the versions are good
        // Running in simics the HLLMgr class will update the invalid versions to be valid
        // so we know that we fell into the proper flows, we cannot allow the simics
        // tests to do what the IPL time flow would do which is perform a shutdown,
        // so we fake things out to just make sure the class methods are accessible, etc.
        bool version_checks_good = l_hll.isValid();
        if (version_checks_good)
        {
            TS_FAIL("testHllBad version checks passed which is unexpected");
        }
        else
        {
            TS_INFO("testHllBad version checks failed which is what we expect");
        }

        UTIL_FT("testHllBad EXIT");
    }

};

#endif
