/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/runtime/test/attntest_rt.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#ifndef __ATTNTEST_RT_H
#define __ATTNTEST_RT_H

#include <cxxtest/TestSuite.H>
#include <runtime/interface.h>
#include <targeting/common/commontargeting.H>
#include "../../common/attntrace.H"

class AttnTestRT: public CxxTest::TestSuite
{
    public:

    void testAttnIntf()
    {
        ATTN_SLOW("runtime testAttnIntf");

        runtimeInterfaces_t* rt_intf = getRuntimeInterfaces();
        if (NULL == rt_intf)
        {
            TS_FAIL("AttnTestRT: runtimeIntfaces not set");
            return;
        }
    }

    private:

};

#endif
