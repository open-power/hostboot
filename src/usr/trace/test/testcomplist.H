/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/test/testcomplist.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
