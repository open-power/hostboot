/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_MfgSync.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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

#ifndef __TEST_PRDFTESTMFGSYNC_H
#define __TEST_PRDFTESTMFGSYNC_H

/**
 *  @file prdfTest_MfgSync.H
 *
 *  @brief prdf unit test
 */

#ifdef __HOSTBOOT_MODULE
  #include <cxxtest/TestSuite.H>
  #include <errl/errlentry.H>
  #include <errl/errlmanager.H>
#else
  #include <cxxtest/TestSuite.h>
  #include <fsp/FipsGlobalFixture.H>
  #include <errlentry.H>
#endif

#include <prdfTrace.H>
#include <prdfMain.H>
#include "prdfsimMacros.H"
#include "prdfsimMfgSync.H"
#include <prdfErrlUtil.H>
#include <prdfMain_common.H>
#include <prdfCalloutsData.H>

using namespace PRDF;

class PrdfTest_MfgSync: public CxxTest::TestSuite
{
    public:
    void TestMfgTraceSync(void)
    {
        #define PRDF_FUNC "PrdfTest_MfgTraceSync"

        PRDF_ENTER(PRDF_FUNC);
        ErrorSignature l_errSig;
        PfaData        l_pfaData;
        errlHndl_t     l_err = nullptr;

        l_errSig.setChipId(0xffffffff);
        l_errSig.setRegId(0xffff);
        l_errSig.setErrCode((uint16_t)NO_PRD_ANALYSIS);

        l_pfaData.mruListCount = 1;

        l_pfaData.mruList[0].callout  = 0;
        l_pfaData.mruList[0].type     = PRDcalloutData::TYPE_TARGET;
        l_pfaData.mruList[0].priority = MRU_LOW;

        // Test 1: Test with mailbox status disabled
        getSimMfgSync().setMailBoxStatus(false);
        l_err = getSimMfgSync().syncMfgTraceToFsp(&l_errSig, l_pfaData);
        if (l_err)
        {
            PRDF_ERR(PRDF_FUNC " MfgTraceSync test1 failed to sync to FSP");
            PRDF_COMMIT_ERRL(l_err, ERRL_ACTION_REPORT);
            TS_FAIL(PRDF_FUNC " MfgTraceSync test1 failed to sync to FSP");
        }
        else
        {
            PRDF_TRAC(PRDF_FUNC " MfgTraceSync test1 is a success.");
        }

        getSimMfgSync().setMailBoxStatus(true);

        // Test 2: Test with mailbox status enabled
        l_err = getSimMfgSync().syncMfgTraceToFsp(&l_errSig, l_pfaData);
        if (l_err)
        {
            PRDF_ERR(PRDF_FUNC " MfgTraceSync test2 failed to sync to FSP");
            PRDF_COMMIT_ERRL(l_err, ERRL_ACTION_REPORT);
            TS_FAIL(PRDF_FUNC " MfgTraceSync test2 failed to sync to FSP");
        }
        else
        {
            PRDF_TRAC(PRDF_FUNC " MfgTraceSync test2 is a success.");
        }

        // Test 3: Test with mailbox status enabled and max MRU List count
        l_pfaData.mruListCount = 8;
        for(uint8_t i = 0; i < l_pfaData.mruListCount; i++)
        {
            l_pfaData.mruList[i].callout  = 0;
            l_pfaData.mruList[i].type     = PRDcalloutData::TYPE_TARGET;
            l_pfaData.mruList[i].priority = MRU_LOW;
        }

        l_err = getSimMfgSync().syncMfgTraceToFsp(&l_errSig, l_pfaData);
        if (l_err)
        {
            PRDF_TRAC(PRDF_FUNC " MfgTraceSync test3 failed to sync to FSP.");
            PRDF_COMMIT_ERRL(l_err, ERRL_ACTION_REPORT);
            TS_FAIL(PRDF_FUNC " MfgTraceSync test3 failed to sync to FSP");
        }
        else
        {
            PRDF_TRAC(PRDF_FUNC " MfgTraceSync test3 is a success.");
        }

        // Test 4: Test with mailbox status enabled and zero MRU List count
        l_pfaData.mruListCount = 0;
        l_err = getSimMfgSync().syncMfgTraceToFsp(&l_errSig, l_pfaData);
        if (l_err)
        {
            PRDF_TRAC(PRDF_FUNC " MfgTraceSync test4 failed to sync to FSP.");
            PRDF_COMMIT_ERRL(l_err, ERRL_ACTION_REPORT);
            TS_FAIL(PRDF_FUNC " MfgTraceSync test4 failed to sync to FSP");
        }
        else
        {
            PRDF_TRAC(PRDF_FUNC " MfgTraceSync test4 is a success.");
        }

        getSimMfgSync().setMailBoxStatus(false);

        PRDF_EXIT(PRDF_FUNC);
        #undef PRDF_FUNC
    }
};
#endif

