/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2CreatePlatLogTest.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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

#include <plat_utils.H>
#include <hwpf_fapi2_reasoncodes.H>
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/hberrltypes.H>
#include <errl/errlreasoncodes.H>
#include <errl/errlentry.H>

extern trace_desc_t* g_trac_runtime;

class CreatePlatLogTest : public CxxTest::TestSuite
{
public:

    void testCreatePlatLogCreatorFapi2()
    {
        TRACFCOMP(g_trac_runtime, "testCreatePlatLogCreatorFapi2 running");

        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_INVALID_ATTR_GET;
        fapi2::errlSeverity_t l_sev = fapi2::FAPI2_ERRL_SEV_RECOVERED;
        createPlatLog(l_rc, l_sev);
        errlHndl_t l_errl = reinterpret_cast<errlHndl_t>(l_rc.getPlatDataPtr());
        if(l_errl->sev() != ERRORLOG::ERRL_SEV_RECOVERED)
        {
            TS_FAIL("testCreatePlatLogCreatorFapi2: incorrect errl severity. "
                    "Expected: %x Actual: %x",
                    ERRORLOG::ERRL_SEV_RECOVERED,
                    l_errl->sev());
        }
        else
        {
            TRACDCOMP(g_trac_runtime, "testCreatePlatLogCreatorFapi2: ERRL_SEV_RECOVERED passed");
        }
        l_rc.forgetData();


        l_sev = fapi2::FAPI2_ERRL_SEV_PREDICTIVE;
        createPlatLog(l_rc, l_sev);
        l_errl = reinterpret_cast<errlHndl_t>(l_rc.getPlatDataPtr());
        if(l_errl->sev() != ERRORLOG::ERRL_SEV_PREDICTIVE)
        {
            TS_FAIL("testCreatePlatLogCreatorFapi2: incorrect errl severity. "
                    "Expected: %x Actual: %x",
                    ERRORLOG::ERRL_SEV_PREDICTIVE,
                    l_errl->sev());
        }
        else
        {
            TRACDCOMP(g_trac_runtime, "testCreatePlatLogCreatorFapi2: ERRL_SEV_PREDICTIVE passed");
        }
        l_rc.forgetData();


        l_sev = fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE;
        createPlatLog(l_rc, l_sev);
        if(l_errl->sev() != ERRORLOG::ERRL_SEV_UNRECOVERABLE)
        {
            TS_FAIL("testCreatePlatLogCreatorFapi2: incorrect errl severity. "
                    "Expected: %x Actual: %x",
                    ERRORLOG::ERRL_SEV_PREDICTIVE,
                    l_errl->sev());

        }
        else
        {
            TRACDCOMP(g_trac_runtime, "testCreatePlatLogCreatorFapi2: ERRL_SEV_UNRECOVERABLE passed");
        }
        l_rc.forgetData();

        TRACFCOMP(g_trac_runtime, "testCreatePlatLogCreatorFapi2 done");
    }

    void testCreatePlatLogCreatorPlat()
    {
        TRACFCOMP(g_trac_runtime, "testCreatePlatLogCreatorPlat running");

        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_PLAT_ERR_SEE_DATA;
        fapi2::errlSeverity_t l_sev = fapi2::FAPI2_ERRL_SEV_RECOVERED;
        // Allocate a fake error log since PLAT code path expects a non-null ptr
        errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                ERRORLOG::ERRL_FIRST_MODULE_ID,
                                fapi2::RC_HWP_GENERATED_ERROR,
                                ERRORLOG::ERRL_TEST_REASON_CODE);
        l_rc.setPlatDataPtr(reinterpret_cast<void *>(l_errl));

        createPlatLog(l_rc, l_sev);
        l_errl = reinterpret_cast<errlHndl_t>(l_rc.getPlatDataPtr());
        if(l_errl->sev() != ERRORLOG::ERRL_SEV_RECOVERED)
        {
            TS_FAIL("testCreatePlatLogCreatorPlat: incorrect errl severity. "
                    "Expected: %x Actual: %x",
                    ERRORLOG::ERRL_SEV_RECOVERED,
                    l_errl->sev());
        }
        else
        {
            TRACDCOMP(g_trac_runtime, "testCreatePlatLogCreatorPlat: ERRL_SEV_RECOVERED passed");
        }

        l_sev = fapi2::FAPI2_ERRL_SEV_PREDICTIVE;
        createPlatLog(l_rc, l_sev);
        l_errl = reinterpret_cast<errlHndl_t>(l_rc.getPlatDataPtr());
        if(l_errl->sev() != ERRORLOG::ERRL_SEV_PREDICTIVE)
        {
            TS_FAIL("testCreatePlatLogCreatorPlat: incorrect errl severity. "
                    "Expected: %x Actual: %x",
                    ERRORLOG::ERRL_SEV_PREDICTIVE,
                    l_errl->sev());
        }
        else
        {
            TRACDCOMP(g_trac_runtime, "testCreatePlatLogCreatorPlat: ERRL_SEV_PREDICTIVE passed");
        }

        l_sev = fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE;
        createPlatLog(l_rc, l_sev);
        l_errl = reinterpret_cast<errlHndl_t>(l_rc.getPlatDataPtr());
        if(l_errl->sev() != ERRORLOG::ERRL_SEV_UNRECOVERABLE)
        {
            TS_FAIL("testCreatePlatLogCreatorPlat: incorrect errl severity. "
                    "Expected: %x Actual: %x",
                    ERRORLOG::ERRL_SEV_PREDICTIVE,
                    l_errl->sev());

        }
        else
        {
            TRACDCOMP(g_trac_runtime, "testCreatePlatLogCreatorPlat: ERRL_SEV_UNRECOVERABLE passed");
        }
        l_rc.forgetData();

        TRACFCOMP(g_trac_runtime, "testCreatePlatLogCreatorPlat done");
    }

    void testCreatePlatLogCreatorHwp()
    {
        TRACFCOMP(g_trac_runtime, "testCreatePlatLogCreatorHwp running");

        fapi2::ReturnCode l_rc = 0x00000001; // Fake return code wit creator == HWP
        fapi2::errlSeverity_t l_sev = fapi2::FAPI2_ERRL_SEV_RECOVERED;
        createPlatLog(l_rc, l_sev);
        errlHndl_t l_errl = reinterpret_cast<errlHndl_t>(l_rc.getPlatDataPtr());
        if(l_errl->sev() != ERRORLOG::ERRL_SEV_RECOVERED)
        {
            TS_FAIL("testCreatePlatLogCreatorHwp: incorrect errl severity. "
                    "Expected: %x Actual: %x",
                    ERRORLOG::ERRL_SEV_RECOVERED,
                    l_errl->sev());
        }
        else
        {
            TRACDCOMP(g_trac_runtime, "testCreatePlatLogCreatorHwp: ERRL_SEV_RECOVERED passed");
        }
        l_rc.forgetData();

        l_sev = fapi2::FAPI2_ERRL_SEV_PREDICTIVE;
        createPlatLog(l_rc, l_sev);
        l_errl = reinterpret_cast<errlHndl_t>(l_rc.getPlatDataPtr());
        if(l_errl->sev() != ERRORLOG::ERRL_SEV_PREDICTIVE)
        {
            TS_FAIL("testCreatePlatLogCreatorHwp: incorrect errl severity. "
                    "Expected: %x Actual: %x",
                    ERRORLOG::ERRL_SEV_PREDICTIVE,
                    l_errl->sev());
        }
        else
        {
            TRACDCOMP(g_trac_runtime, "testCreatePlatLogCreatorHwp: ERRL_SEV_PREDICTIVE passed");
        }
        l_rc.forgetData();

        l_sev = fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE;
        createPlatLog(l_rc, l_sev);
        l_errl = reinterpret_cast<errlHndl_t>(l_rc.getPlatDataPtr());
        if(l_errl->sev() != ERRORLOG::ERRL_SEV_UNRECOVERABLE)
        {
            TS_FAIL("testCreatePlatLogCreatorHwp: incorrect errl severity. "
                    "Expected: %x Actual: %x",
                    ERRORLOG::ERRL_SEV_PREDICTIVE,
                    l_errl->sev());

        }
        else
        {
            TRACDCOMP(g_trac_runtime, "testCreatePlatLogCreatorHwp: ERRL_SEV_UNRECOVERABLE passed");
        }
        l_rc.forgetData();

        TRACFCOMP(g_trac_runtime, "testCreatePlatLogCreatorHwp done");
    }
};

