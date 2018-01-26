/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/pm/runtime/test/pmtestRt.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
#include <runtime/rt_targeting.H>
#include <targeting/common/utilFilter.H>
#include <errl/errlmanager.H>
#include <devicefw/userif.H>
#include <devicefw/driverif.H>
#include <initservice/isteps_trace.H>
#include <runtime/runtime.H>
#include <runtime/runtime_reasoncodes.H>

#include <isteps/pm/pm_common_ext.H>
#include <pnor/pnorif.H>
#include <stopreg/p9_stop_api.H>

//trace
extern trace_desc_t* g_trac_isteps_trace;

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
};

#endif
