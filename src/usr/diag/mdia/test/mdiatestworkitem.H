//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/mdia/test/mdiatestworkitem.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __TEST_MDIATESTWORKITEM_H
#define __TEST_MDIATESTWORKITEM_H

/**
 * @file mdiatestworkitem.H
 * @brief work item unit test
 */

#include <builtins.h>
#include <cxxtest/TestSuite.H>
#include <targeting/target.H>
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

            TargetHandle_t target = 0;

            WorkItem wi1(s, START_SCRUB, target, 2222),
                     wi2(s, START_SCRUB, target, 1111);

            if(wi2 < wi1)
            {
                TS_FAIL("wi2 < wi1");
            }

            if(!(wi1 < wi2))
            {
                TS_FAIL("wi1 !< wi2");
            }

            TS_TRACE(EXIT_MRK "testWorkItem");
        }
};
#endif
