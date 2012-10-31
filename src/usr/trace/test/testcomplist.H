/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/test/testcomplist.H $                           */
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
#include "../compdesc.H"

#include <cxxtest/TestSuite.H>

using namespace TRACE;

class ComponentListTest : public CxxTest::TestSuite
{
    public:
        void testGetDescriptor()
        {
            ComponentList l;

            ComponentDesc* t = l.getDescriptor("TEST", 2048);

            if (NULL == t)
            {
                TS_FAIL("Component descriptor was NULL.");
            }

            ComponentDesc* t2 = l.getDescriptor("teST", 2048);
            if (t2 != t)
            {
                TS_FAIL("Component descriptor failed case-insensitive test.");
            }

            ComponentDesc* t3 = l.getDescriptor("TEST2", 0);
            if (NULL != t3)
            {
                TS_FAIL("Component descriptor failed non-existance test.");
            }

            t3 = l.getDescriptor("TEST2", 2048);
            if (t3 == t)
            {
                TS_FAIL("Component descriptor failed uniqueness test.");
            }
        }
};
