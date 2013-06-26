/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_MfgThresSync.H $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef __TEST_PRDFTESTMFGTHRESSYNC_H
#define __TEST_PRDFTESTMFGTHRESSYNC_H

/**
 *  @file prdfTest_MfgThresSync.H
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
#include "prdfsimMfgThresholdSync.H"
#include <prdfErrlUtil.H>

class PrdfTest_MfgThresSync: public CxxTest::TestSuite
{
    #define FUNC "PrdfTest_MfgThresSync"
    PRDF_ENTER(FUNC);
    PRDF::SimMfgThresholdSync l_syncer;

    errlHndl_t l_err = l_syncer.syncMfgThresholdFromFsp();
    if (l_err)
    {
        PRDF_ERR(FUNC" MfgThresSync test failed to sync from FSP");
        PRDF_COMMIT_ERRL(l_err, ERRL_ACTION_REPORT);
        TS_FAIL(FUNC" MfgThresSync test failed to sync from FSP");
    }
    else
    {
        PRDF_TRAC(FUNC" MfgThresSync test is a success.");
    }
    PRDF_EXIT(FUNC);
    #undef FUNC
};
#endif

