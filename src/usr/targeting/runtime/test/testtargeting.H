/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/runtime/test/testtargeting.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
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
#include <targeting/common/commontargeting.H>
#include <runtime/interface.h>
#include <runtime/rt_targeting.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/trace.H>
#include <targeting/common/utilFilter.H>
#include <targeting/attrPlatOverride.H>
#include <util/runtime/util_rt.H>
#include <targeting/attrrp.H>

#define MEMCMPPTR(addr, offset) \
        reinterpret_cast<void*>(reinterpret_cast<uint64_t>(addr) + offset)

class TargetingTestSuite : public CxxTest::TestSuite
{
    public:
        void testTopLevelTarget()
        {
            using namespace TARGETING;

            TargetService& l_targetService = targetService();

            TARGETING::Target* l_pTarget = NULL;
            (void) l_targetService.getTopLevelTarget(l_pTarget);
            if (l_pTarget == NULL)
            {
                TS_FAIL("Top level target handle is NULL");
                return;
            }

            (void)l_pTarget->getAttr<ATTR_PHYS_PATH>().dump();
        }

        void testHBRT_targets()
        {
            using namespace TARGETING;
            errlHndl_t err = NULL;
            RT_TARG::rtChipId_t rt_chipid;

            TARGETING::TargetHandleList allTargets;
            TARGETING::TargetHandleList targetList;

            getAllChips(targetList, TYPE_PROC);

            allTargets.insert(allTargets.end(),
                              targetList.begin(),
                              targetList.end());

            targetList.clear();
            getAllChips(targetList,TYPE_MEMBUF);

            allTargets.insert(allTargets.end(),
                              targetList.begin(),
                              targetList.end());

            targetList.clear();
            getAllChiplets(targetList, TYPE_CORE);

            allTargets.insert(allTargets.end(),
                              targetList.begin(),
                              targetList.end());


            for(TargetHandleList::iterator pTarg = allTargets.begin();
                pTarg != allTargets.end(); ++pTarg)
            {
                err = RT_TARG::getRtTarget(*pTarg, rt_chipid);
                if( err )
                {
                    TS_FAIL("getRtTarget returned error log");
                    errlCommit( err, TARG_COMP_ID);
                    err = NULL;
                    break;
                }
                TRACDCOMP(g_trac_targeting,"chipId = %x",rt_chipid);

                TARGETING::Target * target = NULL;

                err = RT_TARG::getHbTarget(rt_chipid, target);
                if(err)
                {
                    TS_FAIL("getRtTarget_returned error log");
                    errlCommit( err, TARG_COMP_ID);
                    err = NULL;
                    break;
                }

                if(*pTarg != target)
                {
                    TS_FAIL("testHBRT_targets failed for rt_chipID %x "
                            "target_in %p, huid %x, target_out %p, huid %x",
                            rt_chipid,
                            *pTarg,
                            get_huid(*pTarg),
                            target,
                            get_huid(target));
                }
            }
        }

        // Verify HBRT is picking up the overrides from the IPL
        //  Note: must be before testApplyAttrOverrides, because that
        //        test clears out all of the overrides
        void testIplOverrides()
        {
            using namespace TARGETING;
            TRACFCOMP(g_trac_targeting,"testIplOverrides");
#if 0
// @TODO RTC 144077 - rt_get_targ_override() no longer sets attribute up

            //See rt_get_targ_override() for setup details about setting
            // SYSTEM:ATTR_SCRATCH_INT32_1 = -99

            TargetService& l_targetService = targetService();
            TARGETING::Target* l_pTarget = NULL;
            (void) l_targetService.getTopLevelTarget(l_pTarget);
            if (l_pTarget == NULL)
            {
                TS_FAIL("Top level target handle is NULL");
            }
            else
            {
                ATTR_SCRATCH_INT32_1_type l_val =
                  l_pTarget->getAttr<TARGETING::ATTR_SCRATCH_INT32_1>();
                if( l_val != -99 )
                {
                    TS_FAIL("testIplOverrides> SCRATCH_INT32_1=%d, expected %d", l_val, -99 );
                }
            }
#endif
        }


        void testApplyAttrOverrides()
        {
            using namespace TARGETING;
            TRACFCOMP(g_trac_targeting,"testApplyAttrOverrides (temporarily allow Attr Overrides)");

            // Must Temporarily Allow Attribute Overrides since secureboot is
            // now set at runtime.  Will restore later.
            bool allow_attr_overrides = false;
            TargetService& l_targetService = targetService();
            TARGETING::Target* l_pTarget = nullptr;
            (void) l_targetService.getTopLevelTarget(l_pTarget);
            if (l_pTarget == nullptr)
            {
                TS_FAIL("Top level target handle is NULL");
            }
            else
            {
                  allow_attr_overrides = l_pTarget->getAttr<
                    TARGETING::ATTR_ALLOW_ATTR_OVERRIDES_IN_SECURE_MODE>();

                  l_pTarget->setAttr<
                    TARGETING::ATTR_ALLOW_ATTR_OVERRIDES_IN_SECURE_MODE>(true);
            }

            do
            {
                // Get the address of the runtime apply overrides function
                runtimeInterfaces_t* rt_intf = getRuntimeInterfaces();
                if(rt_intf == NULL)
                {
                    TS_FAIL("runtimeIntfaces not set");
                    break;
                }
                if( rt_intf->apply_attr_override == NULL )
                {
                    TS_FAIL("runtimeInterfaces->apply_attr_override not set");
                    break;
                }

                // Get the initial value of the test attribute
                uint8_t l_attrVal =
                         l_pTarget->getAttr<TARGETING::ATTR_SCRATCH_UINT8_1>();
                uint8_t l_attrOverrideVal = l_attrVal + 1;
                TRACFCOMP(g_trac_targeting,
                      "apply_attr_override attribute value = 0x%02x",
                      l_attrVal);

                // Set up attribute override binary blob
                const uint64_t l_attrBlobSizeMax = 4096;
                uint8_t l_pAttrOverrideBlob[l_attrBlobSizeMax] = {0xff};
                AttributeTank l_TargetTank;
                l_TargetTank.setAttribute(ATTR_SCRATCH_UINT8_1,
                                      TYPE_SYS,
                                      AttributeTank::ATTR_POS_NA,
                                      AttributeTank::ATTR_UNIT_POS_NA,
                                      AttributeTank::ATTR_NODE_NA,
                                      0,
                                      sizeof(l_attrOverrideVal),
                                      &l_attrOverrideVal);
                AttributeTank::AttributeSerializedChunks_t l_attributes;
                l_TargetTank.serializeAttributes(
                             AttributeTank::ALLOC_TYPE_NEW,
                             l_attrBlobSizeMax,
                             l_attributes);
                // Copy override chunk to form attribute override section
                AttributeTank::AttributeSerializedChunk l_chunk;
                AttrOverrideSection * l_pAttrOverSec = NULL;
                uint32_t l_tmpIndex = 0;
                for (AttributeTank::AttributeSerializedChunks_t::iterator
                        chunkIter = l_attributes.begin();
                        chunkIter != l_attributes.end();
                        ++chunkIter)
                {
                    l_chunk = *chunkIter;
                    l_pAttrOverSec = reinterpret_cast<AttrOverrideSection *>
                                        (l_pAttrOverrideBlob + l_tmpIndex);
                    l_pAttrOverSec->iv_layer = AttributeTank::TANK_LAYER_TARG;
                    l_pAttrOverSec->iv_size = l_chunk.iv_size;
                    memcpy(&l_pAttrOverSec->iv_chunk, l_chunk.iv_pAttributes,
                        l_chunk.iv_size);
                    l_tmpIndex += sizeof(AttrOverrideSection)+
                                        l_pAttrOverSec->iv_size;
                }
                // Add termination section
                l_pAttrOverSec = reinterpret_cast<AttrOverrideSection *>
                                        (l_pAttrOverrideBlob + l_tmpIndex);
                l_pAttrOverSec->iv_layer = AttributeTank::TANK_LAYER_TERM;
                l_pAttrOverSec->iv_size = 0;
                l_tmpIndex += sizeof(AttrOverrideSection);
                // call runtime override attributes
                int rc = rt_intf->apply_attr_override(
                                    l_pAttrOverrideBlob,
                                    l_tmpIndex);
                if (rc)
                {
                    TS_FAIL("apply_attr_override empty list failed rc=%x",rc);
                    break;
                }
                // verify the overriden value
                uint8_t l_attrNewVal =
                         l_pTarget->getAttr<TARGETING::ATTR_SCRATCH_UINT8_1>();
                TRACFCOMP(g_trac_targeting,
                      "apply_attr_override overriden attribute value = 0x%02x",
                      l_attrNewVal);
                if (l_attrNewVal != l_attrOverrideVal)
                {
                    TS_FAIL("apply_attr_override value=0x%02x expected=0x%02x",
                       l_attrNewVal,l_attrOverrideVal);
                    break;
                }

                // verify that any previous overrides are not still there
                ATTR_SCRATCH_INT32_1_type l_val =
                  l_pTarget->getAttr<TARGETING::ATTR_SCRATCH_INT32_1>();
                if( l_val == -99 )
                {
                    TS_FAIL("testApplyAttrOverrides> SCRATCH_INT32_1=%d, expected %d", -99, 0 );
                    break;
                }

                TRACFCOMP(g_trac_targeting,"testApplyAttrOverrides SUCCESS");
            } while (0);

            // Restore allow_attr_overrides setting
            l_pTarget->setAttr<
              TARGETING::ATTR_ALLOW_ATTR_OVERRIDES_IN_SECURE_MODE>(
                allow_attr_overrides);
        }

        // Test the two internal functions used during HBRT concurrent update.
        // The first function validates the LID Structure against the Reserved
        // Memory data.  The second function saves and restores attribute
        // values from current Reserved Memory data into new LID Structure
        // data.  This testcase uses Reserved Memory data to make its LID
        // Structure, so it tests basic logic in the functions, but does not
        // test more complex handling of special data conditions.
        void _testSaveRestoreAttrs()
        {
#if 0 //@todo-RTC:188625-Turn this back on
            using namespace TARGETING;
            TRACFCOMP(g_trac_targeting,ENTER_MRK"testSaveRestoreAttrs");

            int rc = 0;
            uint64_t l_userdata2 = 0;
            void *l_lidStruct = nullptr;

            do
            {
                uint64_t l_attr_size = 0;
                uint64_t l_rsvdMem =
                    hb_get_rt_rsvd_mem(Util::HBRT_MEM_LABEL_ATTR,
                                       0,
                                       l_attr_size);
                void *l_rsvdMemPtr = reinterpret_cast<void*>(l_rsvdMem);

                // Allocate memory for new LID structure
                l_lidStruct = malloc(l_attr_size);

                // Make LID structure from current Reserved Memory data
                memcpy(l_lidStruct,
                       l_rsvdMemPtr,
                       l_attr_size);

                // Validate LID Structure against Reserved Memory
                /* Check that the TargetingHeader eyecatchers are valid, that
                   number of sections match, and that the types of each
                   TargetingSection match. */
                size_t l_lidDataSize = 0;
                rc = RT_TARG::validateData(l_lidStruct,
                                           l_rsvdMemPtr,
                                           l_lidDataSize,
                                           l_userdata2);
                if(rc)
                {
                    TS_FAIL("testSaveRestoreAttrs> unexpected return code from "
                            "validateData, received 0x%.2x",
                            rc);
                    break;
                }
                else if(l_userdata2 != 0)
                {
                    TS_FAIL("testSaveRestoreAttrs> unexpected user data from "
                            "validateData, received 0x%.16llx",
                            l_userdata2);
                    break;
                }

#if 0 //@todo-RTC:188625-Need to figure out a way to get the size of the original data
                if( l_lidDataSize != TARGETING::AttrRP::maxSize() )
                {
                    TS_FAIL("testSaveRestoreAttrs> size mismatch : cur=0x%llX vs new=0x%llX",
                            TARGETING::AttrRP::maxSize(), l_lidDataSize);
                    break;
                }
#endif

                // Save/Restore attribute values
                /* Copy attribute values from current Reserved Memory data
                   into new LID Structure data.  Leave attribute values in new
                   LID Structure data as is, if there is no value from current
                   Reserved Memory data. */
                rc = RT_TARG::saveRestoreAttrs(l_rsvdMemPtr,
                                               l_lidStruct,
                                               l_userdata2);
                if(rc)
                {
                    TS_FAIL("testSaveRestoreAttrs> unexpected return code from "
                            "saveRestoreAttrs, received 0x%.2x",
                            rc);
                    break;
                }
                else if(l_userdata2 != 0)
                {
                    TS_FAIL("testSaveRestoreAttrs> unexpected user data from "
                            "saveRestoreAttrs, received 0x%.8x",
                            l_userdata2);
                    break;
                }

                // Prepare to compare current attributes to new attributes
                TRACFCOMP(g_trac_targeting,"testSaveRestoreAttrs> comparing "
                          "data from new LID Structure at %p to current "
                          "Reserved Memory at %p",
                          MEMCMPPTR(l_lidStruct, 0),
                          MEMCMPPTR(l_rsvdMemPtr, 0));

                // Compare the complete set of memory
                if( memcmp( l_lidStruct, l_rsvdMemPtr, l_attr_size ) )
                {
                    TS_FAIL( "testSaveRestoreAttrs> Data does not match" );
                }

                uint64_t l_memcmpOffset = 0;
                uint64_t l_memcmpLimit = 0;
                uint64_t l_memcmpSize = 8;
                int l_memcmpRtn = 0;
                uint32_t l_memcmpCount = 0;
                uint32_t l_memcmpFailed = 0;

                // Access TargetingHeader in current data
                TargetingHeader* l_headerRsvd =
                    reinterpret_cast<TargetingHeader*>(l_rsvdMemPtr);

                // Verify TargetingHeader in current data
                if (l_headerRsvd->eyeCatcher != PNOR_TARG_EYE_CATCHER)
                {
                    TS_FAIL("testSaveRestoreAttrs>  bad eyecatcher 0x%.8x "
                            "found in Reserved Memory TargetingHeader",
                            l_headerRsvd->eyeCatcher);

                    break;
                }

                // First compare header and section data
                l_memcmpLimit = l_headerRsvd->headerSize; // Total header size
                for(;
                    l_memcmpOffset < l_memcmpLimit;
                    l_memcmpOffset += l_memcmpSize)
                {
                    // Increment compare count
                    l_memcmpCount += 1;

                    // Compare new LID Structure and current Reserved Memory
                    l_memcmpRtn =
                        memcmp(MEMCMPPTR(l_lidStruct, l_memcmpOffset),
                               MEMCMPPTR(l_rsvdMemPtr, l_memcmpOffset),
                               (l_memcmpOffset + l_memcmpSize <= l_memcmpLimit)
                                   ? l_memcmpSize
                                   : (l_memcmpLimit - l_memcmpOffset));
                    if(0 != l_memcmpRtn)
                    {
                        TRACFCOMP(g_trac_targeting,"miscompare offset 0x%.8x "
                                  "in header and section data, "
                                  "LID 0x%0.16llx, Rsvd 0x%0.16llx, "
                                  "memcmp return 0x%llx ",
                                  l_memcmpOffset,
                                  *static_cast<uint64_t *>(
                                      MEMCMPPTR(l_lidStruct, l_memcmpOffset)),
                                  *static_cast<uint64_t *>(
                                      MEMCMPPTR(l_rsvdMemPtr, l_memcmpOffset)),
                                  l_memcmpRtn);

                        l_memcmpFailed += 1;
                    }
                }

                // Count of attribute sections
                size_t l_sectionCount = l_headerRsvd->numSections;

                // Find start to the first section in current data:
                //      (header address + size of header + offset in header)
                TargetingSection* l_sectionRsvd =
                    reinterpret_cast<TargetingSection*>(
                        reinterpret_cast<uint64_t>(l_headerRsvd) +
                        sizeof(TargetingHeader) +
                        l_headerRsvd->offsetToSections);

                // Then compare each section
                for(size_t i = 0;
                    i < l_sectionCount;
                    ++i)
                {
                    // Compare a section
                    TRACFCOMP(g_trac_targeting,"testSaveRestoreAttrs> "
                          "comparing section type %d data from new LID "
                          "Structure at %p to current Reserved Memory at %p",
                          l_sectionRsvd[i].sectionType,
                          MEMCMPPTR(l_lidStruct, l_memcmpOffset),
                          MEMCMPPTR(l_rsvdMemPtr, l_memcmpOffset));
                    l_memcmpLimit =
                        std::min(l_memcmpOffset + l_sectionRsvd[i].sectionSize,
                                 l_attr_size);
                    for(;
                        l_memcmpOffset < l_memcmpLimit;
                        l_memcmpOffset += l_memcmpSize)
                    {
                        // Increment compare count
                        l_memcmpCount += 1;

                        // Compare new LID Structure and current Reserved Memory
                        l_memcmpRtn =
                            memcmp(MEMCMPPTR(l_lidStruct, l_memcmpOffset),
                                   MEMCMPPTR(l_rsvdMemPtr, l_memcmpOffset),
                                   (l_memcmpOffset + l_memcmpSize
                                    <= l_memcmpLimit)
                                       ? l_memcmpSize
                                       : (l_memcmpLimit - l_memcmpOffset));
                        if(0 != l_memcmpRtn)
                        {
                            TRACFCOMP(g_trac_targeting,"miscompare offset "
                                      "0x%.8x in %d type section, "
                                      "LID 0x%0.16llx, Rsvd 0x%0.16llx, "
                                      "memcmp return 0x%llx ",
                                      l_memcmpOffset,
                                      l_sectionRsvd[i].sectionType,
                                      *static_cast<uint64_t *>(
                                          MEMCMPPTR(l_lidStruct,
                                                    l_memcmpOffset)),
                                      *static_cast<uint64_t *>(
                                          MEMCMPPTR(l_rsvdMemPtr,
                                                    l_memcmpOffset)),
                                      l_memcmpRtn);

                            l_memcmpFailed += 1;
                        }
                    }
                }

                TRACFCOMP(g_trac_targeting,"testSaveRestoreAttrs> Pointers "
                          "after compare, new LID Structure %p, current "
                          "Reserved Memory %p",
                          MEMCMPPTR(l_lidStruct, l_memcmpOffset),
                          MEMCMPPTR(l_rsvdMemPtr, l_memcmpOffset));

                if(l_memcmpFailed != 0)
                {
                    TS_FAIL("testSaveRestoreAttrs FAILED memcmp %d "
                              ERR_MRK"testSaveRestoreAttrs FAILED memcmp %d "
                              "(0x%.8x) times out of %d (0x%.8x)",
                              l_memcmpFailed,
                              l_memcmpFailed,
                              l_memcmpCount,
                              l_memcmpCount);
                    break;
                }

                // Detect invalid LID Structure TargetingHeader eyecatcher
                TargetingHeader* l_headerLid =
                    reinterpret_cast<TargetingHeader*>(l_lidStruct);
                uint32_t *l_pEyeCatcher =
                    reinterpret_cast<uint32_t*>(reinterpret_cast<uint64_t>(
                        &l_headerLid->eyeCatcher));
                *l_pEyeCatcher += 0x20202020;
                rc = RT_TARG::validateData(l_lidStruct,
                                           l_rsvdMemPtr,
                                           l_lidDataSize,
                                           l_userdata2);
                if(rc != 0x11)
                {
                    TS_FAIL("testSaveRestoreAttrs> unexpected return code from "
                            "validateData, expected 0x11, received 0x%.2x",
                            rc);
                    break;
                }
                else if(l_userdata2 != l_headerLid->eyeCatcher)
                {
                    TS_FAIL("testSaveRestoreAttrs> unexpected user data from "
                            "validateData, expected 0x%.16llx, rcvd 0x%.16llx",
                            l_headerLid->eyeCatcher,
                            l_userdata2);
                    break;
                }
                else
                {
                    *l_pEyeCatcher -= 0x20202020;
                    l_userdata2 = 0;
                }

                // Detect invalid Reserved Memory TargetingHeader eyecatcher
                l_pEyeCatcher =
                    reinterpret_cast<uint32_t*>(reinterpret_cast<uint64_t>(
                        &l_headerRsvd->eyeCatcher));
                *l_pEyeCatcher += 0x00202020;
                rc = RT_TARG::validateData(l_lidStruct,
                                           l_rsvdMemPtr,
                                           l_lidDataSize,
                                           l_userdata2);
                if(rc != 0x12)
                {
                    TS_FAIL("testSaveRestoreAttrs> unexpected return code from "
                            "validateData, expected 0x12, received 0x%.2x",
                            rc);
                    break;
                }
                else if(l_userdata2 != l_headerRsvd->eyeCatcher)
                {
                    TS_FAIL("testSaveRestoreAttrs> unexpected user data from "
                            "validateData, expected 0x%.16llx, rcvd 0x%.16llx",
                            l_headerRsvd->eyeCatcher,
                            l_userdata2);
                    break;
                }
                else
                {
                    *l_pEyeCatcher -= 0x00202020;
                    l_userdata2 = 0;
                }

                // Detect TargetingHeader number of sections mismatch
                uint32_t *l_pNumSections =
                    reinterpret_cast<uint32_t*>(reinterpret_cast<uint64_t>(
                        &l_headerRsvd->numSections));
                *l_pNumSections += 2;
                uint64_t l_expected =
                    TWO_UINT32_TO_UINT64(l_headerLid->numSections,
                                         l_headerRsvd->numSections);
                rc = RT_TARG::validateData(l_lidStruct,
                                           l_rsvdMemPtr,
                                           l_lidDataSize,
                                           l_userdata2);
                if(rc != 0x13)
                {
                    TS_FAIL("testSaveRestoreAttrs> unexpected return code from "
                            "validateData, expected 0x13, received 0x%.2x",
                            rc);
                    break;
                }
                else if(l_userdata2 != l_expected)
                {
                    TS_FAIL("testSaveRestoreAttrs> unexpected user data from "
                            "validateData, expected 0x%.16llx, rcvd 0x%.16llx",
                            l_expected,
                            l_userdata2);
                    break;
                }
                else
                {
                    *l_pNumSections -= 2;
                    l_userdata2 = 0;
                }

                // Detect TargetingSection type mismatch
                TargetingSection* l_sectionLid =
                    reinterpret_cast<TargetingSection*>(
                        reinterpret_cast<uint64_t>(l_headerLid) +
                        sizeof(TargetingHeader) +
                        l_headerLid->offsetToSections);
                uint8_t l_sectionType = l_sectionLid[0].sectionType;
                uint8_t *l_pSectionType =
                    reinterpret_cast<uint8_t*>(reinterpret_cast<uint64_t>(
                        &l_sectionLid[0])); // sectionType is first field
                *l_pSectionType = l_sectionType + 0xF0;
                l_expected =
                    TWO_UINT32_TO_UINT64(l_sectionLid[0].sectionType,
                                         l_sectionRsvd[0].sectionType);
                rc = RT_TARG::validateData(l_lidStruct,
                                           l_rsvdMemPtr,
                                           l_lidDataSize,
                                           l_userdata2);
                if(rc != 0x14)
                {
                    TS_FAIL("testSaveRestoreAttrs> unexpected return code from "
                            "validateData, expected 0x14, received 0x%.2x",
                            rc);
                    break;
                }
                else if(l_userdata2 != l_expected)
                {
                    TS_FAIL("testSaveRestoreAttrs> unexpected user data from "
                            "validateData, expected 0x%.16llx, rcvd 0x%.16llx",
                            l_expected,
                            l_userdata2);
                    break;
                }
                else
                {
                    *l_pSectionType = l_sectionType;
                    l_userdata2 = 0;
                }

                // Validate LID Structure against Reserved Memory
                rc = RT_TARG::validateData(l_lidStruct,
                                           l_rsvdMemPtr,
                                           l_lidDataSize,
                                           l_userdata2);
                if(rc)
                {
                    TS_FAIL("testSaveRestoreAttrs> unexpected return code from "
                            "validateData, received 0x%.2x",
                            rc);
                    break;
                }
                else if(l_userdata2 != 0)
                {
                    TS_FAIL("testSaveRestoreAttrs> unexpected user data from "
                            "validateData, received 0x%.16llx",
                            l_userdata2);
                    break;
                }

                TRACFCOMP(g_trac_targeting,"testSaveRestoreAttrs SUCCESS");
            } while(false);

            free(l_lidStruct);
            l_lidStruct = nullptr;

            TRACFCOMP(g_trac_targeting,EXIT_MRK"testSaveRestoreAttrs");
#endif
        }

};
