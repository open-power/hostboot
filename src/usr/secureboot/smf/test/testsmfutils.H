/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/smf/test/testsmfutils.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
#include <targeting/common/util.H>
#include <errl/errlmanager.H>
#include <hbotcompid.H>
#include <secureboot/secure_reasoncodes.H>
#include <secureboot/smf_utils.H>
#include <errl/errlmanager.H>
#include <vfs/vfs.H>

class SmfUtilsTestSuite : public CxxTest::TestSuite
{
private:
    bool cv_isSmfLoaded;

public:

    SmfUtilsTestSuite() : cv_isSmfLoaded(false)
    {
        errlHndl_t l_errl = nullptr;
        l_errl = VFS::module_load("libsmf.so");
        if(l_errl)
        {
            TS_FAIL("SmfUtilsTestSuite(): could not load libsmf.so");
            errlCommit(l_errl, CXXTEST_COMP_ID);
            cv_isSmfLoaded = false;
        }
        else
        {
            cv_isSmfLoaded = true;
        }
    }

    ~SmfUtilsTestSuite()
    {
        if(cv_isSmfLoaded)
        {
            errlHndl_t l_errl = nullptr;
            l_errl = VFS::module_unload("libsmf.so");
            if(l_errl)
            {
                TS_FAIL("~SmfUtilsTestSuite(): could not unload libsmf.so");
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
        }
    }

    /**
     * @brief Test isSmfEnabled helper function
     */
    void testIsSmfEnabled() const
    {
        TS_INFO(ENTER_MRK "testIsSmfEnabled");

        do {
        if(!cv_isSmfLoaded)
        {
            break;
        }

        TARGETING::Target* l_sys = nullptr;
        TARGETING::targetService().getTopLevelTarget(l_sys);
        assert(l_sys, "The top level target is nullptr!");
        l_sys->setAttr<TARGETING::ATTR_SMF_CONFIG>(true);

        bool l_smfEnabled = SECUREBOOT::SMF::isSmfEnabled();
        if(l_smfEnabled != true)
        {
            TS_FAIL("testIsSmfEnabled: expected SMF to be enabled, but it's disabled");
        }

        l_sys->setAttr<TARGETING::ATTR_SMF_CONFIG>(false);
        l_smfEnabled = SECUREBOOT::SMF::isSmfEnabled();
        if(l_smfEnabled != false)
        {
            TS_FAIL("testIsSmfEnabled: expected SMF to be disabled, but it's enabled");
        }

        } while (0);

        TS_INFO(EXIT_MRK "testIsSmfEnabled");
    }
};

#endif
