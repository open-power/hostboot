/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/test/mdiatestworkitem.H $                   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
#ifndef __TEST_MDIATESTWORKITEM_H
#define __TEST_MDIATESTWORKITEM_H

/**
 * @file mdiatestworkitem.H
 * @brief work item unit test
 */

#include <builtins.h>
#include <cxxtest/TestSuite.H>
#include "../mdiaworkitem.H"
#include "../mdiasm.H"

class MdiaWorkItemTest : public CxxTest::TestSuite
{
    public:

        void testWorkItem(void)
        {
            using namespace MDIA;
            using namespace TARGETING;

            TS_TRACE(ENTER_MRK "testWorkItem");

            StateMachine s;
            WorkFlowProperties * notUsed = 0;

            WorkItem wi1(s, notUsed, 2222, 0),
                     wi2(s, notUsed, 1111, 0);

            if(wi2 < wi1)
            {
                TS_FAIL("wi2 < wi1");
            }

            if(!(wi1 < wi2))
            {
                TS_FAIL("wi1 !< wi2");
            }

            wi1.iv_priority = 1111;
            wi2.iv_priority = 1111;
            wi1.iv_chipUnit = 0;
            wi2.iv_chipUnit = 0;

            if(wi2 < wi1)
            {
                TS_FAIL("wi2 < wi1");
            }

            if(wi1 < wi2)
            {
                TS_FAIL("wi1 < wi2");
            }

            wi1.iv_chipUnit = 1;
            wi2.iv_chipUnit = 1;

            if(wi2 < wi1)
            {
                TS_FAIL("wi2 < wi1");
            }

            if(wi1 < wi2)
            {
                TS_FAIL("wi1 < wi2");
            }

            wi1.iv_chipUnit = 0;

            if(wi2 < wi1)
            {
                TS_FAIL("wi2 < wi1");
            }

            if(!(wi1 < wi2))
            {
                TS_FAIL("wi1 !< wi2");
            }

            wi1.iv_chipUnit = 1;
            wi2.iv_chipUnit = 0;

            if(!(wi2 < wi1))
            {
                TS_FAIL("wi2 !< wi1");
            }

            if(wi1 < wi2)
            {
                TS_FAIL("wi1 < wi2");
            }


            TS_TRACE(EXIT_MRK "testWorkItem");
        }
};
#endif
