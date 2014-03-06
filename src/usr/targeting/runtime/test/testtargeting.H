/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/runtime/test/testtargeting.H $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
