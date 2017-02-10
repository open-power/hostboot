/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/tests/p9c_mss_ut.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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

///
/// @file $Source: chips/p9/procedures/hwp/memory/ $
/// @brief Unit tests for memory apis
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 4
// *HWP Consumed by: CI

#define CATCH_CONFIG_RUNNER

#include <string>
#include <sstream>
#include <vector>

#include <prcdUtils.H>

#include <fapi2.H>
#include <fapi2ClientCapi.H>
#include <fapi2SharedUtils.H>
#include <catch.hpp>

#include <target_fixture.H>
#include <mss_lab_tools.H>
#include <c_str.H>

using fapi2::TARGET_TYPE_MEMBUF_CHIP;
using fapi2::TARGET_TYPE_PROC_CHIP;
using fapi2::TARGET_TYPE_MBA;

namespace mss
{
namespace test
{
const char*  g_MEM_HWP_DESCRIPTOR("p9c_mss_ut");
const char* g_MEM_HWP_REVISION("$Revision: 1.1 $");
} /* ns test */
} /* ns mss */


// main function
int main(int i_argc, char* i_argv[])
{
    //This forces mss logging to be console only
    setenv("MSS_LOG_OUTPUT_TARGETS", "CONSOLE", 1);

    //initialize ecmd/fapi2 interface
    fapi2::ReturnCode l_rc;
    mss::lab::tool_init lab_tool(l_rc, i_argc, i_argv);

    //Verify lab_tool initialized everythign ok.
    mss::lab::is_ok(l_rc, "Failed initializing ecmd");

    // Load the current state of the attributes in to the current process's attributes
    // We can't call a unit test here as catch isn't setup yet. There doesn't appear to
    // be a way to force a test to always run first, so we build what ammounts to part of
    // and ecmd wrapper to handle things for us.
    {
        ecmdChipTarget l_target;
        std::unique_ptr<mss::ecmd::ecmd_config_looper> l_looper;
        bool l_found_targets = false;

        l_target.chipType      = "cen";     //Also could be "p9n";
        l_target.chipTypeState = ECMD_TARGET_FIELD_VALID;
        l_target.chipUnitType  = "mba";
        l_target.chipUnitTypeState = ECMD_TARGET_FIELD_VALID;
        l_target.cageState     = ECMD_TARGET_FIELD_WILDCARD;
        l_target.nodeState     = ECMD_TARGET_FIELD_WILDCARD;
        l_target.slotState     = ECMD_TARGET_FIELD_WILDCARD;
        l_target.posState      = ECMD_TARGET_FIELD_WILDCARD;
        l_target.threadState   = ECMD_TARGET_FIELD_UNUSED;
        l_target.chipUnitNumState = ECMD_TARGET_FIELD_WILDCARD;

        l_looper.reset(new mss::ecmd::ecmd_config_looper(l_target));
        mss::lab::is_ok(!l_looper->status(), "ECMD looper didn't initialize" );

        while (l_looper->next(l_target))
        {
            fapi2::Target<TARGET_TYPE_MBA> l_my_target(&l_target);
            l_found_targets = true;
        }

        mss::lab::is_ok(l_found_targets == true, "ECMD looper didn't give us any targets");
    }

    //Run Catch Unit Test Suite Runner
    return Catch::Session().run( i_argc, i_argv );
}
