/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/runtime/test/testtargeting.H $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
};
