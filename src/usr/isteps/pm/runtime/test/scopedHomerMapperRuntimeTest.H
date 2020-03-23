/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/pm/runtime/test/scopedHomerMapperRuntimeTest.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#ifndef _TEST_SCOPED_MAPPER_RUNTIME
#define _TEST_SCOPED_MAPPER_RUNTIME

/**
 * @file scopedHomerMapperRuntimeTest.H
 *
 * @brief Unit tests for ScopedHomerMapper
 */

#include <cxxtest/TestSuite.H>
#include <isteps/pm/scopedHomerMapper.H>
#include <targeting/common/targetservice.H>
#include <targeting/targplatutil.H>
#include <hbotcompid.H>

class scopedMapperTestRuntime : public CxxTest::TestSuite
{
public:
    void testScopeNonPhypLoad(void)
    {
        errlHndl_t l_errl = nullptr;
        TARGETING::Target* l_proc = nullptr;
        TS_INFO("testScopeNonPhypLoad start");

        do {
        l_errl = TARGETING::targetService().queryMasterProcChipTargetHandle(l_proc);
        if(l_errl)
        {
            TS_FAIL("testScopeNonPhypLoad: could not fetch master proc!");
            break;
        }

        // Sanitize HOMER Virt before running mapper tests
        l_proc->setAttr<TARGETING::ATTR_HOMER_VIRT_ADDR>(0);

        // Create a temp scope
        {
            HBPM::ScopedHomerMapper l_mapper(l_proc);
            l_errl = l_mapper.map();
            if(l_errl)
            {
                TS_FAIL("testScopeNonPhypLoad: could not map HOMER!");
                break;
            }
            if(l_mapper.getHomerVirtAddr() == 0)
            {
                TS_FAIL("testScopeNonPhypLoad: HOMER virt address is 0!");
                break;
            }

            // Misc class member funciton verifications
            if(l_mapper.getHomerVirtAddr() !=
               l_proc->getAttr<TARGETING::ATTR_HOMER_VIRT_ADDR>())
            {
                TS_FAIL("testScopeNonPhypLoad: HOMER virtual addresses don't match! Expected HOMER virt 0x%016lx; actual HOMER virt 0x%016lx",
                        l_proc->getAttr<TARGETING::ATTR_HOMER_VIRT_ADDR>(),
                        l_mapper.getHomerVirtAddr());
                break;
            }
            if(l_mapper.getHomerPhysAddr() !=
               l_proc->getAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>())
            {
                TS_FAIL("testScopeNonPhypLoad: HOMER physical addresses don't match! Expected HOMER phys 0x%016lx; actual HOMER phys 0x%016lx",
                        l_proc->getAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>(),
                        l_mapper.getHomerPhysAddr());
                break;
            }
            if(l_mapper.getProc() != l_proc)
            {
                TS_FAIL("testScopeNonPhypLoad: Incorrect proc returned from ScopedHomerMapper. Expected HUID 0x%08x; actual HUID 0x%08x",
                        TARGETING::get_huid(l_proc),
                        TARGETING::get_huid(l_mapper.getProc()));
                break;
            }
        }

        // The ScopedHomerMapper went out of scope. However, on non-PHYP loads
        // no unmapping should occur - the HOMER_VIRT attribute should still be
        // set.
        if(l_proc->getAttr<TARGETING::ATTR_HOMER_VIRT_ADDR>() == 0)
        {
            TS_FAIL("testScopeNonPhypLoad: HOMER virtual space was unmapped in non-PHYP load (unexpected)!");
            break;
        }
        } while(0);

        if(l_errl)
        {
            errlCommit(l_errl, CXXTEST_COMP_ID);
        }
        TS_INFO("testScopeNonPhypLoad end");
    }

    void testScopePhypLoad(void)
    {
        errlHndl_t l_errl = nullptr;
        TARGETING::Target* l_proc = nullptr;
        TARGETING::Target* l_sys = TARGETING::UTIL::assertGetToplevelTarget();
        TS_INFO("testScopePhypLoad start");

        do {
        l_errl =
            TARGETING::targetService().queryMasterProcChipTargetHandle(l_proc);
        if(l_errl)
        {
            TS_FAIL("testScopePhypLoad: could not fetch master proc!");
            break;
        }

        // Sanitize HOMER Virt before running mapper tests
        l_proc->setAttr<TARGETING::ATTR_HOMER_VIRT_ADDR>(0);

        // Create a temp scope
        {
            // Fake a PHYP load so that unmapping occurs
            l_sys->setAttr<TARGETING::ATTR_PAYLOAD_KIND>(
                        TARGETING::PAYLOAD_KIND_PHYP);
            HBPM::ScopedHomerMapper l_mapper(l_proc);
            l_errl = l_mapper.map();
            if(l_errl)
            {
                TS_FAIL("testScopePhypLoad: could not map HOMER!");
                break;
            }

            if(l_mapper.getHomerVirtAddr() == 0)
            {
                TS_FAIL("testScopePhypLoad: HOMER virt address is 0!");
                break;
            }

            // Note: other class APIs were tested in testScopeNonPhypLoad; their
            // behavior does not change.
        }

        // The ScopedHomerMapper went out of scope. If the load is PHYP, then
        // the HOMER virtual space should have been de-allocated and the
        // HOMER virtual address zeroed out.
        if(l_proc->getAttr<TARGETING::ATTR_HOMER_VIRT_ADDR>() != 0)
        {
            TS_FAIL("testScopePhypLoad: HOMER virtual space was not deallocated in PHYP load (unexpected)!");
            break;
        }

        } while(0);

        // Reset the load kind
        l_sys->setAttr<TARGETING::ATTR_PAYLOAD_KIND>(
                        TARGETING::PAYLOAD_KIND_NONE);

        if(l_errl)
        {
            errlCommit(l_errl, CXXTEST_COMP_ID);
        }
        TS_INFO("testScopePhypLoad end");
    }

    void testRecursiveMap(void)
    {
        errlHndl_t l_errl = nullptr;
        TARGETING::Target* l_proc = nullptr;
        TARGETING::Target* l_sys = TARGETING::UTIL::assertGetToplevelTarget();
        TS_INFO("testRecursiveMap start");

        do {
        l_errl =
            TARGETING::targetService().queryMasterProcChipTargetHandle(l_proc);
        if(l_errl)
        {
            TS_FAIL("testRecursiveMap: could not fetch master proc!");
            break;
        }

        // Sanitize HOMER Virt before running mapper tests
        l_proc->setAttr<TARGETING::ATTR_HOMER_VIRT_ADDR>(0);

        // Create a temp scope
        {
            // Fake a PHYP load so that unmapping occurs
            l_sys->setAttr<TARGETING::ATTR_PAYLOAD_KIND>(
                    TARGETING::PAYLOAD_KIND_PHYP);
            HBPM::ScopedHomerMapper l_mapper(l_proc);
            l_errl = l_mapper.map();
            if(l_errl)
            {
                TS_FAIL("testRecursiveMap: could not map HOMER!");
                break;
            }

            if(l_mapper.getHomerVirtAddr() == 0)
            {
                TS_FAIL("testRecursiveMap: HOMER virt address is 0!");
                break;
            }

            // Create a nested scope to simulate recursive mapping
            {
                // Create a second mapper for the same proc
                HBPM::ScopedHomerMapper l_mapper1(l_proc);
                // This should be a no-op and no error should be returned
                l_errl = l_mapper1.map();
                if(l_errl)
                {
                    TS_FAIL("testRecursiveMap: could not map HOMER the second time!");
                    break;
                }
                // The HOMER should be mapped at this point
                if(l_mapper1.getHomerVirtAddr() == 0)
                {
                    TS_FAIL("testRecursiveMap: HOMER virt address is 0 (second mapping)!");
                    break;
                }
            }

            // Even though l_mapper1 went out of scope, HOMER should still be
            // mapped by l_mapper.
            if(l_proc->getAttr<TARGETING::ATTR_HOMER_VIRT_ADDR>() == 0)
            {
                TS_FAIL("testRecursiveMap: HOMER virtual address should still be mapped!");
                break;
            }
        }

        // Now l_mapper went out of scope, so HOMER should be unmapped
        if(l_proc->getAttr<TARGETING::ATTR_HOMER_VIRT_ADDR>() != 0)
        {
            TS_FAIL("testRecursiveMap: HOMER virtual space was not unmapped!");
            break;
        }

        }while(0);

        // Reset the load kind
        l_sys->setAttr<TARGETING::ATTR_PAYLOAD_KIND>(
                        TARGETING::PAYLOAD_KIND_NONE);

        if(l_errl)
        {
            errlCommit(l_errl, CXXTEST_COMP_ID);
        }
        TS_INFO("testRecursiveMap end");
    }
};

#endif
