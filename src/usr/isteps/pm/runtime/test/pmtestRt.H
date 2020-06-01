/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/pm/runtime/test/pmtestRt.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
#ifndef __TEST_PMTESTRT_H
#define __TEST_PMTESTRT_H

/**
 * @file pmtestRt.H
 *
 * @brief Unit test for runtime pm
 */

#include <cxxtest/TestSuite.H>
#include <runtime/interface.h>
#include <targeting/runtime/rt_targeting.H>
#include <targeting/common/utilFilter.H>
#include <errl/errlmanager.H>
#include <devicefw/userif.H>
#include <devicefw/driverif.H>
#include <initservice/isteps_trace.H>
#include <runtime/runtime.H>
#include <runtime/runtime_reasoncodes.H>

#include <isteps/pm/pm_common_ext.H>
#include <pnor/pnorif.H>
#include <hbotcompid.H>
#include <targeting/runtime/rt_targeting.H>
#include <sys/mm.h>
#include <util/misc.H>

/* FIXME RTC: 210975
#include <stopreg/p9_stop_api.H>
*/

//trace
namespace ISTEPS_TRACE
{
extern trace_desc_t* g_trac_isteps_trace;
}

using namespace RTPM;
using namespace HBPM;
using namespace TARGETING;
using namespace CxxTest;

class PMTest : public CxxTest::TestSuite
{
  public:

    void test_hcode_update(void)
    {
//         errlHndl_t l_err;
//
//         TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
//             ENTER_MRK "test_hcode_update Enter");
//
//         TARGETING::TargetHandleList l_coreList;
//         getAllChiplets(l_coreList, TYPE_CORE, true);
//
//         for (const auto & l_core: l_coreList)
//         {
//             const TARGETING::Target * l_parentChip =
//                 getParentChip(const_cast<TARGETING::Target *>(l_core));
//
//             TARGETING::Target * l_parentTarget =
//                 const_cast<TARGETING::Target *>(l_parentChip);
//
//             /*
//              * TODO RTC 177702
//              * We should be calling load_pm_complex here, but due to a
//              * simics issue, load_pm_complex will fail.  Instead, we'll
//              * just run these 2 tests which set the HOMER_HCODE_LOADED
//              * attribute and check for result.
//              */
//
//             // Set to not loaded, should get NULL for errl
//             TS_INFO("pm_runtime_test: hcode_update with"
//                     " HCODE_NOT_LOADED on target 0x%llx",
//                     get_huid(l_parentTarget));
//             l_parentTarget->setAttr<ATTR_HOMER_HCODE_LOADED>(
//                 HCODE_NOT_LOADED);
//
//             l_err = RTPM::hcode_update(
//                         stopImageSection::P9_STOP_SECTION_CORE_SCOM,
//                         stopImageSection::P9_STOP_SCOM_APPEND,
//                         l_core,
//                         0x20010A43,
//                         0x0 );
//
//             if(l_err == NULL)
//             {
//                 TS_INFO("hcode_update with HCODE_NOT_LOADED PASSED");
//             }
//             else
//             {
//                 TS_FAIL("hcode_update with HCODE_NOT_LOADED FAILED");
//             }
//
//             // Set to loaded, should not get errl
//             TS_INFO("pm_runtime_test: hcode_update with"
//                     " HCODE_LOADED on target 0x%llx",
//                     get_huid(l_parentTarget));
//             l_parentTarget->setAttr<ATTR_HOMER_HCODE_LOADED>(
//                 HCODE_LOADED);
//
//             l_err = RTPM::hcode_update(
//                         stopImageSection::P9_STOP_SECTION_CORE_SCOM,
//                         stopImageSection::P9_STOP_SCOM_APPEND,
//                         l_core,
//                         0x20010A43,
//                         0x0 );
//
//             if(l_err)
//             {
//                 TS_FAIL("hcode_update with HCODE_LOADED FAILED");
//             }
//             else
//             {
//                 TS_INFO("hcode_update with HCODE_LOADED PASSED");
//             }
//         }
//         TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
//             EXIT_MRK "test_hcode_update Exit");
    }

    void testLoadAndStartOcc(void)
    {
        Target* l_proc = nullptr;
        errlHndl_t l_errl = nullptr;
        int l_rc = 0;

        do {
        //@FIXME-CQ:SW493238
        if( Util::isMultiprocSupported() )
        {
            TS_INFO( "Skipping testLoadAndStartOcc in multiproc config");
            break;
        }

        l_errl = targetService().queryMasterProcChipTargetHandle(l_proc);
        if(l_errl)
        {
            TS_FAIL("testLoadAndStartOcc: could not fetch master proc target");
            errlCommit(l_errl, CXXTEST_COMP_ID);
            break;
        }

        uint64_t l_occCommonAddr = 0;
        uint64_t l_homerAddr = 0;
        uint64_t l_chipId = l_proc->getAttr<ATTR_HBRT_HYP_ID>();

        l_rc = g_hostInterfaces->get_pm_complex_addresses(l_chipId,
                                                          l_homerAddr,
                                                          l_occCommonAddr);
        if(l_rc)
        {
            TS_FAIL("testLoadAndStartOcc: could not get PM complex addresses."
                    " RC: %d",
                    l_rc);
            break;
        }

        TS_INFO("testLoadAndStartOcc: OCC common addr: 0x%016lx; HOMER addr: 0x%016lx",
                l_occCommonAddr, l_homerAddr);

        runtimeInterfaces_t* l_rtInterfaces = getRuntimeInterfaces();

        if(l_rtInterfaces->load_pm_complex == nullptr)
        {
            TS_FAIL("testLoadAndStartOcc: no load_pm_complex interface found!");
            break;
        }

        l_rc = l_rtInterfaces->load_pm_complex(l_chipId,
                                               l_homerAddr,
                                               l_occCommonAddr,
                                               HBRT_PM_LOAD);
        if(l_rc)
        {
            TS_FAIL("testLoadAndStartOcc: Could not load OCC; RC: %d", l_rc);
            break;
        }

        if(l_rtInterfaces->start_pm_complex == nullptr)
        {
            TS_FAIL("testLoadAndStartOcc:no start_pm_complex interface found!");
            break;
        }

        l_rc = l_rtInterfaces->start_pm_complex(l_chipId);
        if(l_rc)
        {
            TS_FAIL("testLoadAndStartOcc: Could not start OCC; RC: %d", l_rc);
            break;
        }

        }while(0);
    }
};

#endif
