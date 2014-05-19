/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/runtime/test/testtargeting.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#include <runtime/rt_targeting.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/trace.H>
#include <targeting/common/utilFilter.H>

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
};
