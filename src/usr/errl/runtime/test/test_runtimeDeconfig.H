/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/runtime/test/test_runtimeDeconfig.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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
#ifndef _TEST_DECONFIGRUNTIME_H
#define _TEST_DECONFIGRUNTIME_H

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <hbotcompid.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <hwas/common/deconfigGard.H>
#include <targeting/common/utilFilter.H>
#include <runtime/interface.h>
#include "errno.h"

extern trace_desc_t* g_trac_runtime;

// enable this test to execute all unit tests
//#define __ENABLE_DECONFIG_TEST

namespace ERRORLOG
{
namespace initiate_gard
{

hostInterfaces::InitiateGardResourceType get_resource_type(TARGETING::Target* i_target);
uint16_t get_resource_id(TARGETING::Target* i_target);

}
}

class deconfigureTargetAtRuntimeTest : public CxxTest::TestSuite
{
    public:


        void testNullTarget()
        {
            TRACFCOMP(g_trac_runtime, "testNullTarget running");

            // pass in a null target pointer
            TARGETING::Target * l_target = nullptr;

            errlHndl_t l_errl = nullptr;
            l_errl = HWAS::theDeconfigGard().deconfigureTargetAtRuntime(
                    l_target,
                    HWAS::DeconfigGard::FULLY_AT_RUNTIME,
                    l_errl);

            do{

                if(l_errl)
                {
                    TRACFCOMP(g_trac_runtime, "testNullTarget:"
                            " errl returned (expected)");

                    //Check module id and reason code
                    if((l_errl->moduleId() == HWAS::MOD_RUNTIME_DECONFIG) and
                            (l_errl->reasonCode() == HWAS::RC_NULL_TARGET))
                    {
                        TRACFCOMP(g_trac_runtime, "testNullTarget:"
                                " error's module id and reason code match "
                                "expected values");

                    }
                    else
                    {
                        TS_FAIL("testNullTarget: error with unexpected"
                                " module id/reason code returned. Expected module "
                                "id = 0x%x returned module id = 0x%x; expected "
                                "reason code ="
                                " 0x%x returned reason code = 0x%x",
                                HWAS::MOD_RUNTIME_DECONFIG,
                                l_errl->moduleId(),
                                HWAS::RC_INVALID_TARGET,
                                l_errl->reasonCode());
                        errlCommit(l_errl, CXXTEST_COMP_ID);
                        break;
                    }
                    delete l_errl;
                    l_errl = nullptr;
                }
                else
                {
                    TS_FAIL("testNullTarget: no errl returned from"
                            " checkHbResMemLimit under error condition");
                }

            }while(0);
            TRACFCOMP(g_trac_runtime, "testNullTarget finished");
        }


        void testInvalidDeconfigOption()
        {
            TRACFCOMP(g_trac_runtime, "testInvalidDeconfig running");

            TARGETING::Target * l_target = nullptr;

            TARGETING::TargetHandleList l_cores;
            TARGETING::getAllChiplets(l_cores, TARGETING::TYPE_CORE);

            if( l_cores.size() == 0 )
            {
                TS_FAIL("Unable to execute test, found 0 cores");

            }

            l_target = l_cores.at(0);

            errlHndl_t l_errl = nullptr;
            l_errl = HWAS::theDeconfigGard().deconfigureTargetAtRuntime(
                    l_target,
                    HWAS::DeconfigGard::SPEC_DECONFIG,
                    l_errl);
            do{

                if(l_errl)
                {
                    TRACDCOMP(g_trac_runtime, "testInvalidDeconfigOption:"
                            " errl returned (expected)");

                    //Check module id and reason code
                    if((l_errl->moduleId() == HWAS::MOD_RUNTIME_DECONFIG) and
                            (l_errl->reasonCode() == HWAS::RC_INVALID_PARAM))
                    {
                        TRACDCOMP(g_trac_runtime, "testInvalidDeconfigOption:"
                                " error's module id and reason code match "
                                "expected values");

                    }
                    else
                    {
                        TS_FAIL("testInvalidDeconfigOption: error with unexpected"
                                " module id/reason code returned. Expected module "
                                "id = 0x%x returned module id = 0x%x; expected "
                                "reason code = 0x%x returned reason code = 0x%x",
                                HWAS::MOD_RUNTIME_DECONFIG,
                                l_errl->moduleId(),
                                HWAS::RC_INVALID_PARAM,
                                l_errl->reasonCode());
                        errlCommit(l_errl, CXXTEST_COMP_ID);
                        break;
                    }
                    delete l_errl;
                    l_errl = nullptr;
                }
                else
                {
                    TS_FAIL("testInvalidDeconfigOption: no errl returned from"
                            " checkHbResMemLimit under error condition");
                }

            }while(0);
            TRACFCOMP(g_trac_runtime, "testInvalidDeconfigOption finished");
        }

        void testInvalidTarget()
        {
            TRACFCOMP(g_trac_runtime, "testInvalidTarget running");

            TARGETING::TargetHandleList l_proc;
            TARGETING::getAllChips(l_proc, TARGETING::TYPE_PROC);

            if( l_proc.size() == 0 )
            {
                TS_FAIL("Unable to execute test, found procs");
            }

            TARGETING::Target * l_target = l_proc.at(0);

            errlHndl_t l_errl = nullptr;
            l_errl = HWAS::theDeconfigGard().deconfigureTargetAtRuntime(
                    l_target,
                    HWAS::DeconfigGard::FULLY_AT_RUNTIME,
                    l_errl);

            do{

                if(l_errl)
                {
                    TRACDCOMP(g_trac_runtime, "deconfigureTargetAtRuntime:"
                            " errl returned (expected)");
                    //Check module id and reason code
                    if((l_errl->moduleId() == HWAS::MOD_RUNTIME_DECONFIG) and
                            (l_errl->reasonCode() == HWAS::RC_INVALID_TARGET))
                    {
                        TRACDCOMP(g_trac_runtime, "testInvalidTarget:"
                                " error's module id and reason code match "
                                "expected values");
                    }
                    else
                    {

                        TS_FAIL("testInvalidTarget: error with unexpected"
                                " module id/reason code returned. Expected "
                                "module id = 0x%x returned module id = "
                                "0x%x; expected reason code = 0x%x returned "
                                "reason code = 0x%x",
                                HWAS::MOD_RUNTIME_DECONFIG,
                                l_errl->moduleId(),
                                HWAS::RC_INVALID_TARGET,
                                l_errl->reasonCode());
                        errlCommit(l_errl, CXXTEST_COMP_ID);
                        break;

                    }
                    delete l_errl;
                    l_errl = nullptr;
                }
                else
                {
                    TS_FAIL("testInvalidTarget: no errl returned from"
                            " deconfigTargetAtRuntime under error condition");
                }

            }while(0);
            TRACFCOMP(g_trac_runtime, "testInvalidTarget finished");
        }

        void testDeconfigAtRuntime()
        {
            TRACFCOMP(g_trac_runtime, "testDeconfigAtRuntime ENTRY");

#ifndef __ENABLE_DECONFIG_TEST
            //  NOTE:  This test marks targets nonfunctional and then
            //         restore them.  Since all the unit tests run in
            //         parallel, this may cause other tests to fail.
            //         Do not leave this test enabled for normal operations.
            TS_INFO(INFO_MRK "testDeconfigAtRuntime SKIPPING: other tests could be affected.");
#else
            TS_INFO(INFO_MRK "testDeconfigAtRuntime: RUNNING other tests could be affected.");
            TARGETING::TargetHandleList l_cores;
            TARGETING::getAllChiplets(l_cores, TARGETING::TYPE_CORE);

            if( l_cores.size() == 0 )
            {
                TS_FAIL("Unable to execute test, found procs");
            }

            TARGETING::Target * l_target = l_cores.at(0);

            TARGETING::HwasState l_origState =
                l_target->getAttr<TARGETING::ATTR_HWAS_STATE>();

            errlHndl_t l_errl =
                HWAS::theDeconfigGard().deconfigureTargetAtRuntime(
                    l_target,
                    HWAS::DeconfigGard::FULLY_AT_RUNTIME,
                    l_errl);

            if(l_errl)
            {
                TS_FAIL("testDeconfigAtRuntime: deconfigureTargetAtRuntime"
                        " returned an unexpected error");
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
            else
            {
                TRACDCOMP(g_trac_runtime, "testDeconfigAtRuntime:"
                        " no error returned (expected)");

                TARGETING::HwasState l_state =
                    l_target->getAttr<TARGETING::ATTR_HWAS_STATE>();

                if(l_state.functional)
                {
                    TS_FAIL("testDeconfigureAtRuntime(): target functional after deconfigure");
                }

                l_target->setAttr<TARGETING::ATTR_HWAS_STATE>(l_origState);
            }
#endif
            TRACFCOMP(g_trac_runtime, "testDeconfigAtRuntime finished");
        }

        void testRuntimeGuardHypNotification()
        {
            using namespace TARGETING;
            using namespace ERRORLOG;
            using namespace ERRORLOG::initiate_gard;

            TRACFCOMP(g_trac_runtime, ENTER_MRK"testRuntimeGuardHypNotification");

            // These variables are shared by our firmware request hook below and by this testcase function.
            static decltype(hostInterfaces::firmware_request) original_fw_request;
            static std::vector<hostInterfaces::initiate_gard_t> gard_stats;

            /* @brief Firmware request hook. This function will replace the original firmware_request host interface for the
             * duration of this testcase and log data about certain requests for verification. See
             * g_hostInterfaces->firmware_request for parameter documentation.
             */
            const auto my_firmware_request = [](const uint64_t i_reqLen, void* const i_req, uint64_t* const io_respLen, void* const o_resp) -> int
                {
                    size_t retVal = 0;

                    do
                    {
                        if (!i_req || !io_respLen || !o_resp)
                        {
                            retVal = -EINVAL;
                            break;
                        }

                        const auto l_req_fw_msg = static_cast<hostInterfaces::hbrt_fw_msg*>(i_req);
                        const auto l_resp_fw_msg = static_cast<hostInterfaces::hbrt_fw_msg*>(o_resp);
                        if (hostInterfaces::HBRT_FW_MSG_TYPE_INITIATE_GARD == l_req_fw_msg->io_type)
                        {
                            TS_TRACE(INFO_MRK"rt_firmware_request for INITIATE_GARD: "
                                     "resourceType:%d, errorType:%d, resourceId:%d",
                                     l_req_fw_msg->initiate_gard.resourceType,
                                     l_req_fw_msg->initiate_gard.errorType,
                                     l_req_fw_msg->initiate_gard.resourceId);

                            if (i_reqLen < hostInterfaces::HBRT_FW_MSG_BASE_SIZE + sizeof(l_req_fw_msg->initiate_gard))
                            {
                                TS_TRACE(ERR_MRK"rt_firmware_request for INITIATE_GARD: request too short (got %d bytes, expected %d)",
                                         i_reqLen,
                                         hostInterfaces::HBRT_FW_MSG_BASE_SIZE + sizeof(l_req_fw_msg->initiate_gard));
                                retVal = -EINVAL;
                                break;
                            }

                            if (*io_respLen < hostInterfaces::HBRT_FW_MSG_BASE_SIZE + sizeof(l_resp_fw_msg->resp_generic))
                            {
                                TS_TRACE(ERR_MRK"rt_firmware_request for INITIATE_GARD: response data too short (got %d bytes, expected %d)",
                                         *io_respLen,
                                         hostInterfaces::HBRT_FW_MSG_BASE_SIZE + sizeof(l_resp_fw_msg->resp_generic));
                                retVal = -EINVAL;
                                break;
                            }

                            TS_TRACE(INFO_MRK"rt_firmware_request for INITIATE_GARD is correctly formed");

                            gard_stats.push_back(l_req_fw_msg->initiate_gard);

                            retVal = 0;
                        }
                        else
                        {
                            // Pass the firmware request off to the original firmware_request function to handle it for us.
                            retVal = original_fw_request(i_reqLen, i_req, io_respLen, o_resp);
                        }
                    } while (false);

                    return retVal;
                };

            // "Hook" the host interfaces firmware_request function by replacing it with our own. We also save the original
            // so that we can call it for any firmware requests that don't pertain to our testcase.
            original_fw_request = g_hostInterfaces->firmware_request;
            g_hostInterfaces->firmware_request = my_firmware_request;

            /* Guard list of targets and check which ones the hypervisor was
             * notified of.  Logs a testcase failure if the hypervisor was
             * notified of any target that was not in the list.
             *
             * @param[in] i_targets   The targets to guard
             * @param[in] i_testname  Name of the test, for debug traces
             * @return                List of targets that the hypervisor was not notified of.
             */
            const auto guard_targets = [](const std::vector<Target*>& i_targets, const char* const i_testname)
                {
                    // Reset the list of gard notifications; we only want to collect the ones from this new testcase.
                    gard_stats.clear();

                    // Call out all of the targets. Each callout will generate a hypervisor guard notification firmware
                    // request if necessary, which we are logging above in our firmware request hook.
                    errlHndl_t errl = new ErrlEntry(ERRL_SEV_PREDICTIVE, 0, 0, 0, 0, ErrlEntry::NO_SW_CALLOUT);

                    for (const auto target : i_targets)
                    {
                        errl->addHwCallout(target, HWAS::SRCI_PRIORITY_HIGH, HWAS::NO_DECONFIG, HWAS::GARD_Predictive);
                    }

                    errlCommit(errl, 0);

                    // Check to make sure each target was called out. We will remove correct entries from this list
                    // below, and if we're left with anything, it means that a target that wasn't called out was
                    // guarded, which is a testcase failure.
                    auto runtime_gard_notifications = gard_stats;

                    std::vector<Target*> missing_targets;

                    for (const auto target : i_targets)
                    {
                        const auto gard = std::find_if(runtime_gard_notifications.begin(), runtime_gard_notifications.end(),
                                                       [rid = get_resource_id(target), rtype = get_resource_type(target)](const auto g) {
                                                           return g.resourceId == rid && g.resourceType == rtype;
                                                       });

                        if (gard == runtime_gard_notifications.end())
                        {
                            missing_targets.push_back(target);
                        }
                        else
                        {
                            runtime_gard_notifications.erase(gard);
                        }
                    }

                    for (const auto noti : runtime_gard_notifications)
                    {
                        TS_FAIL("testRuntimeGuardHypNotification::guard_targets(%s): Runtime guard notification made for target that "
                                "wasn't called out (resourceType = %d, errorType = %d, resourceId = %d)",
                                i_testname, noti.resourceType, noti.errorType, noti.resourceId);
                    }

                    return missing_targets;
                };

            { // Test deconfiguring 1 core.
                TargetHandleList cores;
                getAllChiplets(cores, TYPE_CORE);

                auto core = cores.back();

                const auto missing_targets = guard_targets({ core }, "1 core");

                for (const auto target : missing_targets)
                {
                    TS_FAIL("testRuntimeGuardHypNotification(1): guarded 0x%08x but notification wasn't sent to hypervisor",
                            get_huid(target));
                }
            }

            { // Test deconfiguring all FCs.
                TargetHandleList fcs;
                getAllChiplets(fcs, TYPE_FC);

                const auto missing_targets = guard_targets(fcs, "all cores");

                for (const auto target : missing_targets)
                {
                    TS_FAIL("testRuntimeGuardHypNotification(2): guarded 0x%08x but notification wasn't sent to hypervisor",
                            get_huid(target));
                }
            }

            { // Test deconfiguring all NXs.
                TargetHandleList nxs;
                getAllChiplets(nxs, TYPE_NX);

                const auto missing_targets = guard_targets(nxs, "all NXs");

                for (const auto target : missing_targets)
                {
                    TS_FAIL("testRuntimeGuardHypNotification(3): guarded 0x%08x but notification wasn't sent to hypervisor",
                            get_huid(target));
                }
            }

            { // Test deconfiguring a mix of targets.
                TargetHandleList nxs;
                getAllChiplets(nxs, TYPE_NX);
                TargetHandleList fcs;
                getAllChiplets(fcs, TYPE_FC);
                TargetHandleList cores;
                getAllChiplets(cores, TYPE_CORE);
                TargetHandleList procs;
                getAllChips(procs, TYPE_PROC); // We don't support sending hypervisor notifications for PROC, so these
                                               // shouldn't generate notifications.

                const auto missing_targets = guard_targets({ nxs.front(), fcs.back(), cores.front(), procs.back() },
                                                           "mix");

                for (const auto target : missing_targets)
                {
                    if (target->getAttr<ATTR_TYPE>() != TYPE_PROC)
                    {
                        TS_FAIL("testRuntimeGuardHypNotification(4): guarded 0x%08x but notification wasn't sent to hypervisor",
                                get_huid(target));
                    }
                }

                // If the "missing" list is empty it means we called out all the targets, which means we sent a notification
                // for the PROC, which is a bug.
                if (missing_targets.empty())
                {
                    TS_FAIL("testRuntimeGuardHypNotification(4): PROC notification was sent to hypervisor; we only support CORE, FC, and NX");
                }
            }

            // Restore the original firmware request handler.
            g_hostInterfaces->firmware_request = original_fw_request;

            TRACFCOMP(g_trac_runtime, EXIT_MRK"testRuntimeGuardHypNotification");
        }
};


#endif
