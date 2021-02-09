/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/devtree/test/devtreetest.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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

#ifndef __DEVTREETEST_H
#define __DEVTREETEST_H

/**
 *  @file devtreetest.H
 *
 *  @brief Test case for device tree functions
*/

#include <cxxtest/TestSuite.H>
#include <trace/trace.H>
#include <hbotcompid.H>

// Devtree
#include <devtree/devtree.H>
#include <libfdt.h>

// PNOR
#include <pnor/pnorif.H>

// Errl
#include <errl/errludtarget.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <errl/errlreasoncodes.H>

// Targeting
#include <targeting/common/target.H>
#include <targeting/namedtarget.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/predicates/predicates.H>
#include <targeting/common/utilFilter.H>
#include <targeting/targplatutil.H>

class DevtreeTest: public CxxTest::TestSuite
{
public:

    static void* get_fdt()
    {
        // Get a pointer to the flattened device tree in the pnor
        PNOR::SectionInfo_t devtreeInfo;

        auto err = PNOR::getSectionInfo(PNOR::DEVTREE, devtreeInfo);

        void* fdt = nullptr;

        if(err)
        {
            TS_INFO(ERR_MRK"DevtreeTest::get_fdt(): Error obtaining devicetree pointer: "
                    TRACE_ERR_FMT,
                    TRACE_ERR_ARGS(err));

            errlCommit(err, DEVTREE_COMP_ID);
        }
        else
        {
            fdt = reinterpret_cast<void *>(devtreeInfo.vaddr);
        }

        return fdt;
    }

    /**
     * @brief Test the device tree Target -> devtree node cache to ensure that
     *        cached node lookups match uncached node lookups.
     */
    void test_devtree_cache()
    {
        using namespace TARGETING;
        using namespace DEVTREE;

        TS_INFO(ENTER_MRK"DevtreeTest::test_devtree_cache");

        void* const fdt = get_fdt();

        do
        {

        if (!fdt)
        {
            TS_FAIL("DevtreeTest::test_devtree_cache: Can't get devicetree pointer");
            break;
        }

        Target* const sys = UTIL::assertGetToplevelTarget();

        TargetHandleList alltargets;
        targetService().getAssociated(alltargets, sys,
                                      TargetService::CHILD,
                                      TargetService::ALL, nullptr);

        // Add sys target to the list
        alltargets.push_back(sys);

        const auto devtree_target_cache = devtree_cache_targets(fdt);

        // Look up every target in the cache and in the devtree directly
        for (const auto target : alltargets)
        {
            // Target PHYS_PATH used as key to find associated node in devtree
            const EntityPath physPath = target->getAttr<TARGETING::ATTR_PHYS_PATH>();

            const int dtreeNodeOffset = fdt_node_offset_by_prop_value(fdt,
                                                                      DTREE_START_OFFSET,
                                                                      PHYS_BIN_PROPERTY,
                                                                      &physPath,
                                                                      sizeof(physPath));

            const int cachedtreeNodeOffset = devtree_cache_lookup(devtree_target_cache, target);

            if (cachedtreeNodeOffset != dtreeNodeOffset)
            {
                TS_FAIL("test_devtree_cache(): Cache lookup disagrees with manual lookup "
                        "(cached node: %d, real node: %d, huid: 0x%08x)",
                        cachedtreeNodeOffset, dtreeNodeOffset, get_huid(target));
            }
        }

        } while(0);

        TS_INFO(EXIT_MRK"DevtreeTest::test_devtree_cache");
    }

};

#endif
