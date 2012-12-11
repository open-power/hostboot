/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/test/mdiatest.H $                           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
#ifndef __TEST_MDIATESTMDIA_H
#define __TEST_MDIATESTMDIA_H

/**
 * @file mdiatestmdia.H
 * @brief mdia.C unit tests
 */

#include <builtins.h>
#include <cxxtest/TestSuite.H>
#include <targeting/common/target.H>
#include "../mdiafwd.H"

class MdiaTest : public CxxTest::TestSuite
{
    public:

        void testRunStep(void)
        {
            using namespace MDIA;
            using namespace TARGETING;

            TS_TRACE(ENTER_MRK "testRunStep");

            TargetHandleList list;

            errlHndl_t err = runStep(list);

            if(err)
            {
                TS_FAIL("runStep failed unexpectedly");
            }

            TS_TRACE(EXIT_MRK "testRunStep");
        }
};
#endif
