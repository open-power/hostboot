/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/runtime/test/testtargeting.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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
#include <hwpf/plat/fapiPlatAttrOverrideSync.H>

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
            getAllChiplets(targetList, TYPE_EX);

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
                    TS_FAIL("testHBRT_targets failed for rt_chipID %x"
                            "target_in %p, target_out %p",
                            rt_chipid,
                            *pTarg,
                            target);
                }
            }
        }

        void testApplyAttrOverrides()
        {
            using namespace TARGETING;
            TRACFCOMP(g_trac_targeting,"testApplyAttrOverrides");
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
                TargetService& l_targetService = targetService();
                TARGETING::Target* l_pTarget = NULL;
                (void) l_targetService.getTopLevelTarget(l_pTarget);
                if (l_pTarget == NULL)
                {
                    TS_FAIL("Top level target handle is NULL");
                    break;
                }
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
                TRACFCOMP(g_trac_targeting,"testApplyAttrOverrides SUCCESS");

            } while (0);
        }
};
