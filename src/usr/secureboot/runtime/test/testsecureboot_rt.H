/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/runtime/test/testsecureboot_rt.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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

/**
 *  @file testsecureboot_rt.H
 *  @brief Test secureboot runtime functions
 */

#ifndef __TESTSECUREBOOT_RT_H
#define __TESTSECUREBOOT_RT_H

#include <cxxtest/TestSuite.H>
#include <runtime/interface.h>

#include <targeting/runtime/rt_targeting.H>
#include <errl/errlmanager.H>
#include <devicefw/userif.H>

#include "common/securetrace.H"
#include <secureboot/service.H>
#include <secureboot/settings.H>
#include <pnor/pnorif.H>
#include <pnor/pnor_reasoncodes.H>
#include "../../../pnor/pnor_utils.H"

//See rt_secureboot.C
namespace SECUREBOOT
{
int verify_container(
    const void*  i_pContainer,
    const void*  i_pHwKeyHash,
    const size_t i_hwKeyHashSize);
}

class SecurebootRtTestSuite: public CxxTest::TestSuite
{
    public:

    void testVerifyContainer()
    {
        SB_ENTER("SecurebootRtTestSuite::testVerifyContainer");

        do {

        auto pRtIntf = getRuntimeInterfaces();
        if (nullptr == pRtIntf)
        {
            TS_FAIL("testVerifyContainer: runtime interfaces pointer "
                "not set");
            break;
        }

#ifndef CONFIG_SECUREBOOT

        if (nullptr != pRtIntf->verify_container)
        {
            TS_FAIL("testVerifyContainer: verify_container function pointer "
                "set unexpectedly with secureboot compiled out");
            break;
        }

#else

        if (nullptr == pRtIntf->verify_container)
        {
            TS_FAIL("testVerifyContainer: verify_container function pointer "
                "not set with secureboot compiled in");
            break;
        }

        if (&SECUREBOOT::verify_container != pRtIntf->verify_container)
        {
            TS_FAIL("testVerifyContainer: verify_container function pointer is not set to SECUREBOOT::verify_container()");
            break;
        }

        // If secureboot is compiled in, perform various API tests

        // TODO: RTC 156485 For now, function is a no op; add real tests here
        // when verify_container is fully implemented
        auto rc = SECUREBOOT::verify_container(nullptr,nullptr,0);
        if(rc != 0)
        {
            TS_FAIL("testVerifyContainer: expected verify_container to succeed "
                "when secureboot is compiled in -and- verify_container is not "
                "fully implemented, but it failed with rc = %d",
                rc);
            break;
        }

#endif

        } while(0);

        SB_EXIT("SecurebootRtTestSuite::testVerifyContainer");
    }

    void testBaseInterfaces()
    {
        SB_ENTER("SecurebootRtTestSuite::testBaseInterfaces");

        errlHndl_t l_errl = nullptr;

        do {

        // Runtime scom tests return zeroed buffers unless a write is
        // performed first, so write Security register.
        uint64_t l_regValue = 0;
        size_t l_size = sizeof(l_regValue);

        TARGETING::TargetService& tS = TARGETING::targetService();
        TARGETING::Target* masterProcChipTargetHandle = nullptr;

        l_errl = tS.queryMasterProcChipTargetHandle(masterProcChipTargetHandle);

        if (l_errl)
        {
            TS_FAIL("SecurebootRtTestSuite::testBaseInterfaces: Failed to get masterProcChipTargetHandle");
            break;
        }

        // Set SAB and SUL
        l_regValue |= static_cast<uint64_t>(SECUREBOOT::ProcSecurity::SabBit);
        l_regValue |= static_cast<uint64_t>(SECUREBOOT::ProcSecurity::SULBit);
        l_errl = deviceWrite(
                     masterProcChipTargetHandle,
                     &l_regValue, l_size,
                     DEVICE_SCOM_ADDRESS(
                         static_cast<uint64_t>(
                             SECUREBOOT::ProcSecurity::SwitchRegister)));

        if (l_errl)
        {
            TS_FAIL("SecurebootRtTestSuite::testBaseInterfaces: Failed to Write Security Switch Register");
            break;
        }
        assert(l_size == sizeof(l_regValue));


        SB_INF("SECUREBOOT::enabled() = %d", SECUREBOOT::enabled());

        SB_INF("SECUREBOOT::allowAttrOverrides() = %d",
               SECUREBOOT::allowAttrOverrides());

        } while(0);

        if (l_errl)
        {
            errlCommit(l_errl, SECURE_COMP_ID);
        }

        SB_EXIT("SecurebootRtTestSuite::testBaseInterfaces");
    }

    /**
     * @brief Helper to test case that runs getSectionInfo scenarios and checks
     *        for desired results.
     *        If secure, should throw an error
     *        Otherwise no error
     * @param[in] i_id, Pnor Section ID
     *
     * @return N/A
     */
    void runAccessSecurePnorTest(PNOR::SectionId i_id)
    {
#if 0 //@TODO-RTC:208802-Remove all runtime pnor access once PLDM is live
        errlHndl_t l_errl = nullptr;
        bool l_secure = PNOR::isEnforcedSecureSection(i_id);
        PNOR::SectionInfo_t l_info;

        SB_ENTER("runAccessSecurePnorTest %s", PNOR::SectionIdToString(i_id));

        l_errl = PNOR::getSectionInfo(i_id, l_info);
        if(l_secure)
        {
            SB_INF("runAccessSecurePnorTest is secure");
            if (l_errl &&
                (l_errl->reasonCode() == PNOR::RC_RTPNOR_INVALID_SECTION))
            {
                SB_INF("runAccessSecurePnorTest caught correct error");
                delete l_errl;
                l_errl = nullptr;
            }
            else
            {
                if (l_errl)
                {
                    TS_FAIL("testAccessSecurePnorSection: unexpected reason code for Secure Section %s. Expected RC 0x%.4X Actual RC 0x%.4X",
                            PNOR::SectionIdToString(i_id),
                            PNOR::RC_RTPNOR_INVALID_SECTION,
                            l_errl->reasonCode());
                    errlCommit(l_errl, SECURE_COMP_ID);
                }
                else
                {
                    TS_FAIL("testAccessSecurePnorSection: no error found when one was expected");
                }
            }
        }
        else if(l_errl)
        {
            TS_FAIL("testAccessSecurePnorSection: getSectionInfo failed for section %s",
                        PNOR::SectionIdToString(i_id));
            errlCommit(l_errl, SECURE_COMP_ID);
        }

        SB_EXIT("runAccessSecurePnorTest");
#endif
    }

    void testAccessSecurePnorSection()
    {
#ifdef CONFIG_SECUREBOOT
        SB_ENTER("testAccessSecurePnorSection");

        // Should thow an error for trying to read a secure section
        runAccessSecurePnorTest(PNOR::OCC);
        runAccessSecurePnorTest(PNOR::HB_EXT_CODE);

        // No error for trying to read a secure section
        runAccessSecurePnorTest(PNOR::TEST);
#endif
    }


    private:

};

#endif
