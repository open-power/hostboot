/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/test/runtime/rt_occtest.H $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
#ifndef __RT_OCCTEST_H
#define __RT_OCCTEST_H

#include <cxxtest/TestSuite.H>
#include <runtime/interface.h>
#include <hwpf/hwp/occ/occ.H>
#include <fapi.H>
#include <targeting/common/commontargeting.H>
#include <vmmconst.h>
#include <sys/mm.h>

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

        if( rt_intf->loadOCC == NULL )
        {
            TS_FAIL("runtimeInterfaces->loadOCC not set");
        }

        if( rt_intf->startOCCs == NULL )
        {
            TS_FAIL("runtimeInterfaces->startOCCs not set");
        }

        if( rt_intf->stopOCCs == NULL )
        {
            TS_FAIL("runtimeInterfaces->stopOCCs not set");
        }
    }

    void testGetLidList()
    {
        FAPI_INF("testGetLidList");
        runtimeInterfaces_t* rt_intf = getRuntimeInterfaces();
        if(rt_intf && rt_intf->get_lid_list)
        {
            size_t size = 0;
            const uint32_t * list = rt_intf->get_lid_list(&size);
            if(size > 1)
            {
                TS_FAIL("runtimeInterfaces->get_lid_list empty list");
            }
            else if (list[0] != HBOCC::OCC_LIDID)
            {
                TS_FAIL("runtimeInterface->get_list_list missing OCCLID");
            }
        }

    }


    private:

};

#endif
