/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/occ/test/rt_occtest.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2022                        */
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
#ifndef __RT_OCCTEST_H
#define __RT_OCCTEST_H

#include <cxxtest/TestSuite.H>
#include <runtime/interface.h>
//#include <hwpf/hwp/occ/occ_common.H>
#include <fapi.H>
#include <targeting/common/commontargeting.H>
#include <vmmconst.h>
#include <sys/mm.h>
#include <util/utillidmgr.H>

//See utillidmgr_rt.C
const uint32_t * UtilLidMgr::getLidList(size_t * o_num);

class OccTest: public CxxTest::TestSuite
{
    public:

    void testOccIntf()
    {
        FAPI_INF("testOccIntf");

        runtimeInterfaces_t* rt_intf = getRuntimeInterfaces();
        if(rt_intf == NULL)
        {
            TS_FAIL("runtimeIntfaces not set");
            return;
        }

        if( rt_intf->get_lid_list == NULL )
        {
            TS_FAIL("runtimeInterfaces->get_lid_list not set");
        }

        if( rt_intf->occ_load == NULL )
        {
            TS_FAIL("runtimeInterfaces->loadOCC not set");
        }

        if( rt_intf->occ_start == NULL )
        {
            TS_FAIL("runtimeInterfaces->startOCCs not set");
        }

        if( rt_intf->occ_stop == NULL )
        {
            TS_FAIL("runtimeInterfaces->stopOCCs not set");
        }

        /* Test case for stopAllOCCs
        int err = stopAllOCCs();
        if( err == -1 )
        {
            TS_FAIL("FAILURE!");
        }
        */

    }

    void testGetLidList()
    {
        FAPI_INF("testGetLidList");
        runtimeInterfaces_t* rt_intf = getRuntimeInterfaces();
        if(rt_intf && rt_intf->get_lid_list)
        {
            size_t size = 0;
            const uint32_t * list = UtilLidMgr::getLidList(&size);
            if(size > 1)
            {
                TS_FAIL("UtilLidMgr::getLidList empty list");
            }
            else if (list[0] != Util::OCC_LIDID)
            {
                TS_FAIL("UtilLidMgr::getLidList missing OCCLID");
            }
        }

    }


    private:

};

#endif
