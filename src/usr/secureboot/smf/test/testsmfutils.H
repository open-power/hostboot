/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/smf/test/testsmfutils.H $                  */
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
#ifndef __TESTSMFUTILS_H
#define __TESTSMFUTILS_H

#include <cxxtest/TestSuite.H>

#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <errl/errlmanager.H>
#include <hbotcompid.H>
#include <targeting/targplatutil.H>
#include <secureboot/secure_reasoncodes.H>
#include <secureboot/smf_utils.H>
#include <errl/errlmanager.H>
#include <vfs/vfs.H>

class SmfUtilsTestSuite : public CxxTest::TestSuite
{
public:

    /**
     * @brief Test isSmfEnabled helper function
     */
    void testIsSmfEnabled() const
    {
        TS_INFO(ENTER_MRK "testIsSmfEnabled");

        do {
        TARGETING::Target* l_sys = nullptr;
        TARGETING::targetService().getTopLevelTarget(l_sys);
        assert(l_sys, "The top level target is nullptr!");
        l_sys->setAttr<TARGETING::ATTR_SMF_ENABLED>(true);

        errlHndl_t l_errl = VFS::module_load("libsmf.so");
        if(l_errl)
        {
            TS_FAIL("Could not load libsmf.so");
            errlCommit(l_errl, CXXTEST_COMP_ID);
            break;
        }

        bool l_smfEnabled = SECUREBOOT::SMF::isSmfEnabled();
        if(l_smfEnabled != true)
        {
            TS_FAIL("testIsSmfEnabled: expected SMF to be enabled, but it's disabled");
        }

        l_sys->setAttr<TARGETING::ATTR_SMF_ENABLED>(false);
        l_smfEnabled = SECUREBOOT::SMF::isSmfEnabled();
        if(l_smfEnabled != false)
        {
            TS_FAIL("testIsSmfEnabled: expected SMF to be disabled, but it's enabled");
        }

        l_errl = VFS::module_unload("libsmf.so");
        if(l_errl)
        {
            TS_FAIL("Could not unload libsmf.so");
            errlCommit(l_errl, CXXTEST_COMP_ID);
            break;
        }
        } while (0);

        TS_INFO(EXIT_MRK "testIsSmfEnabled");
    }

    /**
     * @brief Test checkRiskLevelForSmf helper function
     */
    void testCheckRiskLevelForSmf() const
    {
        TS_INFO(ENTER_MRK "testCheckRiskLevelForSmf");
        bool l_libsmf_loaded = false;
        errlHndl_t l_errl = nullptr;

        do {
        TARGETING::Target* l_masterProc = nullptr;

        l_errl = VFS::module_load("libsmf.so");
        if(l_errl)
        {
            TS_FAIL("Could not load libsmf.so");
            errlCommit(l_errl, CXXTEST_COMP_ID);
            break;
        }
        l_libsmf_loaded = true;

        l_errl = TARGETING::targetService()
                                 .queryMasterProcChipTargetHandle(l_masterProc);
        if(l_errl)
        {
            TS_FAIL("testCheckRiskLevelForSmf: could not get master proc");
            errlCommit(l_errl, CXXTEST_COMP_ID);
            break;
        }

        if(l_masterProc->getAttr<TARGETING::ATTR_MODEL>() ==
            TARGETING::MODEL_AXONE)
        {
            // SMF is enabled by default on Axone
            l_errl = SECUREBOOT::SMF::checkRiskLevelForSmf();
            if(l_errl)
            {
                TS_FAIL("testCheckRiskLevelForSmf: checkRiskLevelForSmf returned an error for Axone; plid = 0x%x", l_errl->plid());
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
        }
        else // NIMBUS or CUMULUS
        {
            TARGETING::Target* l_sys = nullptr;
            TARGETING::targetService().getTopLevelTarget(l_sys);
            l_sys->setAttr<TARGETING::ATTR_RISK_LEVEL>(
                  TARGETING::UTIL::P9N23_P9C13_NATIVE_SMF_RUGBY_FAVOR_SECURITY);
            l_errl = SECUREBOOT::SMF::checkRiskLevelForSmf();
            if(l_errl)
            {
                TS_FAIL("testCheckRiskLevelForSmf: checkRiskLevelForSmf returned an error for CUMULUS/NIMBUS; plid = 0x%x", l_errl->plid());
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }

            l_sys->setAttr<TARGETING::ATTR_RISK_LEVEL>(
                                        TARGETING::UTIL::P9N22_P9N23_JAVA_PERF);
            l_errl = SECUREBOOT::SMF::checkRiskLevelForSmf();
            if(!l_errl)
            {
                TS_FAIL("testCheckRiskLevelForSmf: expected error was not returned from checkRiskLevelForSmf");
            }
            else
            {
                if(l_errl->reasonCode() != SECUREBOOT::RC_RISK_LEVEL_TOO_LOW)
                {
                    TS_FAIL("testCheckRiskLevelForSmf: incorrect reason code returned from checkRiskLevelForSmf. Expected 0x%x; actual 0x%x", SECUREBOOT::RC_RISK_LEVEL_TOO_LOW, l_errl->reasonCode());
                }
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
        }
        } while(0);

        if(l_libsmf_loaded)
        {
            l_errl = VFS::module_unload("libsmf.so");
            if(l_errl)
            {
                TS_FAIL("Could not unload libsmf.so");
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
        }

        TS_INFO(EXIT_MRK "testCheckRiskLevelForSmf");
    }
};

#endif
