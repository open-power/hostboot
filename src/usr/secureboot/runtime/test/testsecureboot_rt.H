/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/runtime/test/testsecureboot_rt.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#include <config.h>

#include <runtime/rt_targeting.H>
#include <errl/errlmanager.H>
#include <devicefw/userif.H>

#include "common/securetrace.H"
#include <secureboot/service.H>
#include <secureboot/settings.H>
#include <pnor/pnorif.H>
#include <pnor/pnor_reasoncodes.H>

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

        // If secureboot is compiled in, perform various API tests

        // TODO: RTC 156485 For now, function is a no op; add real tests here
        // when verify_container is fully implemented
        auto rc = pRtIntf->verify_container(
            nullptr,nullptr,0);
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
     * @param[in] i_id, Pnor Section ID
     * @param[in] i_secure, Indicates if section is expected to be secure or not
     *
     * @return N/A
     */
    void runAccessSecurePnorTest(PNOR::SectionId i_id, bool i_secure)
    {
        errlHndl_t l_errl = nullptr;
        PNOR::SectionInfo_t l_info;

        l_errl = PNOR::getSectionInfo(i_id, l_info);
        if(l_errl)
        {
            TS_FAIL("testAccessSecurePnorSection: Failed for section %s",
                        PNOR::SectionIdToString(i_id));
            errlCommit(l_errl, SECURE_COMP_ID);
        }

        // TODO: RTC:180063 change this test case back to how it was before
        //                  having secure sections return vaddr = 0
        //                  previously in HB commit cefc4c
        // If we expect the section to be secure, make sure it returns secure
        // and a vaddr of 0
        if (i_secure)
        {
            if (l_info.secure != 1)
            {
                TS_FAIL("testAccessSecurePnorSection: Did not return %s as a secure section",
                            PNOR::SectionIdToString(i_id));
            }
            else if (l_info.vaddr != 0)
            {
                TS_FAIL("testAccessSecurePnorSection: Did not return a vaddr of 0 for secure section %s",
                            PNOR::SectionIdToString(i_id));
            }
        }
        // If we expect the section to be secure, make sure it returns secure
        // and a vaddr of 0
        else
        {
            if (l_info.vaddr == 0)
            {
                TS_FAIL("testAccessSecurePnorSection: Did not return a vaddr of non-zero for a non-secure section %s",
                            PNOR::SectionIdToString(i_id));
            }
        }
    }

    // TODO: RTC:180063 change this test case back to how it was before
    //                  having secure sections return vaddr = 0 previously
    //                  in HB commit cefc4c
    void testAccessSecurePnorSection()
    {
        SB_ENTER("testAccessSecurePnorSection");


        // Ensure we get a vaddr of 0 at Runtime
        runAccessSecurePnorTest(PNOR::OCC, true);
        runAccessSecurePnorTest(PNOR::HB_EXT_CODE, true);

        // Ensure we get a vaddr of  at Runtime
        runAccessSecurePnorTest(PNOR::TEST, false);

        SB_EXIT("testAccessSecurePnorSection");
    }


    private:

};

#endif
