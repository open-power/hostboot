/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/test/testmclmgr.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#ifndef _TESTMASTERCONTAINERLIDMGR_H
#define _TESTMASTERCONTAINERLIDMGR_H


#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <util/utilmclmgr.H>
#include "../utilbase.H"
#include <usr/vmmconst.h>
#include <runtime/preverifiedlidmgr.H>
#include <util/util_reasoncodes.H>

namespace MCL
{

// Constants to simplify code
const ComponentID COMP_TEST1 {"TEST1"};
const ComponentID COMP_TEST2 {"TEST2"};
const ComponentID COMP_TEST3 {"TEST3"};
// Component ids are not null terminated. So test a 16 byte comp ID
// NOTE: You cannot use a CHAR initializer list equal to the size of the array
//       as the compiler expects a space for the null terminator.
//       So setting the hex values directly.
// ASCII: TESTMAXSIZEOFSTR
const ComponentID COMP_TEST4 {0x54,0x45,0x53,0x54,0x4d,0x41,0x58,0x53,
                              0x49,0x5a,0x45,0x4f,0x46,0x53,0x54,0x52};

// Define deault vectors to simplify syntax
const std::vector<uint32_t> defaultLids {0xA1234567, 0x89ABCDEF, 0x13579246};
const std::vector<std::pair<ComponentID,bool> > defaultComps{
                                                    {COMP_TEST1,1} ,
                                                    {COMP_TEST2, 0} ,
                                                    {COMP_TEST3, 1},
                                                    {COMP_TEST4, 0}
                                                 };
}

using namespace MCL;

class MasterContainerLidMgrTest : public CxxTest::TestSuite
{
public:

    class TestMcl
    {
        public:

        // Actual Size
        size_t iv_size;

        // Pointers to internal buffer
        uint8_t* iv_bufferCur;
        uint8_t* iv_bufferStart;

        // Pointers within internal buffer to useful information
        MclHeader* iv_pHeader;
        std::vector<MclCompSection*> iv_compSections;

        // Max Size of buffer
        static const size_t iv_maxSize = 256;

        // Comp Info Cache
        CompInfoMap iv_compInfoCache;

        // Vector of test lids
        std::vector<uint32_t> iv_testLids;

        // Vector of pairs for test components and if they are signed or not
        std::vector<std::pair<ComponentID,bool> > iv_testComps;

        TestMcl()
        : iv_size(0),iv_bufferCur(nullptr),iv_bufferStart(nullptr),
          iv_pHeader(nullptr), iv_compInfoCache{}, iv_testLids{defaultLids},
          iv_testComps{defaultComps}
        {
            initMcl();
        }

        TestMcl(const std::vector<uint32_t>& i_lids)
        : iv_size(0),iv_bufferCur(nullptr),iv_bufferStart(nullptr),
          iv_pHeader(nullptr), iv_compInfoCache{}, iv_testLids{i_lids},
          iv_testComps{defaultComps}
        {
            initMcl();
        }

        TestMcl(const std::vector<uint32_t>& i_lids,
                const std::vector<std::pair<ComponentID,bool> >& i_comps)
        : iv_size(0),iv_bufferCur(nullptr),iv_bufferStart(nullptr),
          iv_pHeader(nullptr), iv_compInfoCache{}, iv_testLids{i_lids},
          iv_testComps{i_comps}
        {
            initMcl();
        }

        void initMcl()
        {
            // Note: () zero initializes
            iv_bufferStart = new uint8_t[iv_maxSize]();
            iv_bufferCur = iv_bufferStart;
            genMcl();
            genCompInfoCache();
        }


        ~TestMcl()
        {
            delete[] iv_bufferStart;
            iv_bufferStart = nullptr;
        }

        void genMcl()
        {
            // Handle MCL Header
            auto l_pMclHdrSec = reinterpret_cast<MclHeader*>(iv_bufferCur);
            l_pMclHdrSec->version = 0xDEADBEEF;
            l_pMclHdrSec->offsetToCompSection = sizeof(MclHeader);
            l_pMclHdrSec->numComponents = iv_testComps.size();

            // Store MCL header pointer for reference
            iv_pHeader = l_pMclHdrSec;

            // Increment member variables
            iv_bufferCur += l_pMclHdrSec->offsetToCompSection;
            iv_size += l_pMclHdrSec->offsetToCompSection;
            // Assert we have not surpased max buffer size
            assert(iv_size <= iv_maxSize, "TestMcl internal buffer ran out of space");

            // Get size of of all lid ids
            auto l_lidsSize = sizeof(uint32_t) * iv_testLids.size();

            // Handle MCL Component Sections
            for (auto compPair : iv_testComps)
            {
                auto comp = compPair.first;
                auto secure = compPair.second;

                // Assert we have enough room for next component
                assert( (iv_size + sizeof(MclCompSection) + l_lidsSize) <= iv_maxSize, "TestMcl internal buffer ran out of space");

                auto l_pMclCompSec = reinterpret_cast<MclCompSection*>(iv_bufferCur);
                memcpy(l_pMclCompSec->compId.data(), &comp, sizeof(ComponentID));
                l_pMclCompSec->sizeCompList = sizeof(MclCompSection) +
                                             l_lidsSize;
                l_pMclCompSec->numLids = iv_testLids.size();
                if (secure)
                {
                    l_pMclCompSec->flags = CompFlags::SIGNED_PRE_VERIFY;
                }
                else
                {
                    l_pMclCompSec->flags = CompFlags::UNSIGNED;
                }
                memcpy(&l_pMclCompSec->lidArray, iv_testLids.data(), l_lidsSize);

                // Pad to MclCompSectionPadSize byte boundary
                auto l_padMod = l_pMclCompSec->sizeCompList %
                                  MclCompSectionPadSize;
                if (l_padMod)
                {
                    auto l_padSize = MclCompSectionPadSize - l_padMod;
                    auto l_end = reinterpret_cast<uint8_t*>(l_pMclCompSec) +
                                        l_pMclCompSec->sizeCompList;
                    memset(l_end, 0, l_padSize);
                    l_pMclCompSec->sizeCompList += l_padSize;
                }

                // Store comp sections for reference
                iv_compSections.push_back(l_pMclCompSec);

                // Increment member variables
                iv_bufferCur += l_pMclCompSec->sizeCompList;
                iv_size += l_pMclCompSec->sizeCompList;
                // Assert we have not surpased max buffer size
                assert(iv_size <= iv_maxSize, "TestMcl internal buffer ran out of space");
            }
        }

        void genCompInfoCache()
        {
            // Add MCL itself to Cache
            CompInfo l_compHdrInfo(CompFlags::SIGNED_PRE_VERIFY);
            l_compHdrInfo.lidIds.push_back(Util::MCL_LIDID);
            iv_compInfoCache.insert(std::make_pair(g_MclCompId, l_compHdrInfo));

            // Add all components in MCL to cache
            for ( const auto comp : iv_compSections)
            {
                CompInfo l_compInfo(comp->flags);
                auto * l_pId = comp->lidArray;
                for (uint8_t i = 0; i < comp->numLids; ++i)
                {
                    l_compInfo.lidIds.push_back(*l_pId);
                    l_pId++;
                }
                iv_compInfoCache.insert(std::make_pair(comp->compId, l_compInfo));
            }
        }
    };

    /**
     *  @brief Test that MCL manager properly parses a MCL
     */
    void testMclParser(void)
    {
        UTIL_FT(ENTER_MRK"testMclParser start" );
        // Generate test MCL
        TestMcl l_TestMcl{};

        // Pass test MCL to MCL manager
        MasterContainerLidMgr l_mcl(l_TestMcl.iv_bufferStart,
                                    l_TestMcl.iv_size);

        // Ensure the Comp Info Caches match
        if (l_TestMcl.iv_compInfoCache != l_mcl.iv_compInfoCache)
        {
            TS_FAIL("testMclParser> Comp Info Caches do not match");
        }

        UTIL_FT(EXIT_MRK"testMclParser complete");
    }

    void testProcessMclComponents()
    {
        UTIL_FT(ENTER_MRK"testProcessMclComponents start" );

        errlHndl_t l_errl = nullptr;

        // Generate test MCL with test lids
        TestMcl l_TestMcl { {Util::TEST_LIDID, Util::TEST_LIDID},
                            {{COMP_TEST1,false}}
                          };

        // Pass test MCL to MCL manager
        MasterContainerLidMgr l_mcl(l_TestMcl.iv_bufferStart,
                                    l_TestMcl.iv_size);

        // Ensure the Comp Info Caches match
        if (l_TestMcl.iv_compInfoCache != l_mcl.iv_compInfoCache)
        {
            TS_FAIL("testProcessMclComponents> Comp Info Caches do not match");
        }

        PreVerifiedLidMgr::initLock(PREVERLIDMGR_TEST_ADDR);

        // Get Instance of Pre-Verified lid manager
        auto l_preVerLidMgr = PreVerifiedLidMgr::getInstance();

        // Clear lids loaded cache as other test cases fill it in.
        l_preVerLidMgr.cv_lidsLoaded.clear();

        l_errl = l_mcl.processComponents();
        if(l_errl)
        {
            errlCommit(l_errl,UTIL_COMP_ID);
            TS_FAIL("testProcessMclComponents> processComponents failed");
        }

        PreVerifiedLidMgr::unlock();

        UTIL_FT(EXIT_MRK"testProcessMclComponents complete");
    }

    void testProcessSecureMclComponents()
    {
        UTIL_FT(ENTER_MRK"testProcessSecureMclComponents start" );

        errlHndl_t l_errl = nullptr;

        // Generate test MCL with Secure Lids
        TestMcl l_TestMcl { {Util::TEST_LIDID},
                            {{COMP_TEST2,true}}
                          };

        // Pass test MCL to MCL manager
        MasterContainerLidMgr l_mcl(l_TestMcl.iv_bufferStart,
                                    l_TestMcl.iv_size);

        // Ensure the Comp Info Caches match
        if (l_TestMcl.iv_compInfoCache != l_mcl.iv_compInfoCache)
        {
            TS_FAIL("testProcessSecureMclComponents> Comp Info Caches do not match");
        }

        PreVerifiedLidMgr::initLock(PREVERLIDMGR_TEST_ADDR);

        // Get Instance of Pre-Verified lid manager
        auto l_preVerLidMgr = PreVerifiedLidMgr::getInstance();

        // Clear lids loaded cache as other test cases fill it in.
        l_preVerLidMgr.cv_lidsLoaded.clear();

        l_errl = l_mcl.processComponents();
        if(l_errl)
        {
            errlCommit(l_errl,UTIL_COMP_ID);
            TS_FAIL("testProcessSecureMclComponents> processComponents failed");
        }

        PreVerifiedLidMgr::unlock();

        UTIL_FT(EXIT_MRK"testProcessSecureMclComponents complete");
    }

    void testMclSizeMismatch()
    {
        UTIL_FT(ENTER_MRK"testMclSizeMismatch start" );

        errlHndl_t l_errl = nullptr;

        // Generate test MCL with Secure Lids
        // Add 2 secure sections.
        // The secure header for the first one will only have the size of 1 lid
        // So we will get a mismatch between the Secure header's total container
        // size and what the UtilLidMgr reads out.
        TestMcl l_TestMcl { {Util::TEST_LIDID, Util::TEST_LIDID},
                            {{COMP_TEST2,true}}
                          };

        // Pass test MCL to MCL manager
        MasterContainerLidMgr l_mcl(l_TestMcl.iv_bufferStart,
                                    l_TestMcl.iv_size);

        // Ensure the Comp Info Caches match
        if (l_TestMcl.iv_compInfoCache != l_mcl.iv_compInfoCache)
        {
            TS_FAIL("testMclSizeMismatch> Comp Info Caches do not match");
        }

        PreVerifiedLidMgr::initLock(PREVERLIDMGR_TEST_ADDR);

        // Get Instance of Pre-Verified lid manager
        auto l_preVerLidMgr = PreVerifiedLidMgr::getInstance();

        // Clear lids loaded cache as other test cases fill it in.
        l_preVerLidMgr.cv_lidsLoaded.clear();

        l_errl = l_mcl.processComponents();
        if(l_errl)
        {
            // Expected Error
            if(l_errl->reasonCode() == Util::UTIL_MCL_SIZE_MISMATCH)
            {
                delete l_errl;
                l_errl = nullptr;
                UTIL_FT("testMclSizeMismatch expected error");
            }
            // Not Expected Error
            else
            {
                errlCommit(l_errl,UTIL_COMP_ID);
                TS_FAIL("testMclSizeMismatch> processComponents returned an unexpected error");
            }
        }
        else
        {
            TS_FAIL("testMclSizeMismatch> processComponents did not return expected error");
        }

        PreVerifiedLidMgr::unlock();

        UTIL_FT(EXIT_MRK"testMclSizeMismatch complete");
    }
};

#endif