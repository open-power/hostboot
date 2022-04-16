/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/pm/runtime/test/pmtestRt.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2022                        */
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
#include <arch/magic.H>

//See rt_pm.C
namespace RTPM
{
    int load_pm_complex( uint64_t i_chip,
                         uint64_t i_homer_addr,
                         uint64_t i_occ_common_addr,
                         uint32_t i_mode );
    int start_pm_complex( uint64_t i_chip );
}

//trace
namespace ISTEPS_TRACE
{
extern trace_desc_t* g_trac_isteps_trace;
}

using namespace HBPM;
using namespace TARGETING;
using namespace CxxTest;

class PMTest : public CxxTest::TestSuite
{
  public:

    void testLoadAndStartOcc(void)
    {
        Target* l_proc = nullptr;
        errlHndl_t l_errl = nullptr;
        int l_rc = 0;

        do {
        //@FIXME-CQ:SW493238
        if( MAGIC_INST_CHECK_FEATURE(MAGIC_FEATURE__SKIPOCC) )
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

        if(l_homerAddr == 0 || l_occCommonAddr == 0)
        {
            TS_FAIL("testLoadAndStartOcc: Invalid HOMER or OCC common address. HOMER addr: 0x%016x; OCC Common addr: 0x%016x",
                    l_homerAddr, l_occCommonAddr);
            break;
        }

        TS_INFO("testLoadAndStartOcc: OCC common addr: 0x%016lx; HOMER addr: 0x%016lx",
                l_occCommonAddr, l_homerAddr);

        // Check the load_pm_complex runtime interface connection
        // but do not use it when testing the load_pm_complex function
        if(getRuntimeInterfaces()->load_pm_complex == nullptr)
        {
            TS_FAIL("testLoadAndStartOcc: no load_pm_complex interface found!");
            break;
        }
        l_rc = RTPM::load_pm_complex(l_chipId,
                                     l_homerAddr,
                                     l_occCommonAddr,
                                     HBRT_PM_LOAD);
        if(l_rc)
        {
            TS_FAIL("testLoadAndStartOcc: Could not load OCC; RC: %d", l_rc);
            break;
        }

        // Check the start_pm_complex runtime interface connection
        // but do not use it when testing the start_pm_complex function
        if(getRuntimeInterfaces()->start_pm_complex == nullptr)
        {
            TS_FAIL("testLoadAndStartOcc:no start_pm_complex interface found!");
            break;
        }
        l_rc = RTPM::start_pm_complex(l_chipId);
        if(l_rc)
        {
            TS_FAIL("testLoadAndStartOcc: Could not start OCC; RC: %d", l_rc);
            break;
        }

        }while(0);
    }
};

#endif
