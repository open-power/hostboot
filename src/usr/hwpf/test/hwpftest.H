//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/test/hwpftest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __HWPFTEST_H
#define __HWPFTEST_H

/**
 *  @file hwpftest.H
 *
 *  @brief Test case for HWPF implementation
*/

#include <cxxtest/TestSuite.H>
#include <fapi.H>
#include <fapiPlatHwpInvoker.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/targetservice.H>

using namespace fapi;
using namespace TARGETING;

class HwpfTest: public CxxTest::TestSuite
{
public:

    /**
      * @brief Test HWPF trace
      */
    void testHwpf1()
    {
        // Trace into all the FAPI trace buffers
        uint32_t l_val = 4;
        const char * l_pStr = "test-str";

        FAPI_INF("Test INF Trace");
        FAPI_INF("Test INF Trace. hex: 0x%x", l_val);
        FAPI_INF("Test INF Trace. string: %s", l_pStr);
        FAPI_INF("Test INF Trace. 0x%x, %s", l_val, l_pStr);

        FAPI_IMP("Test IMP Trace");
        FAPI_IMP("Test IMP Trace. hex: 0x%x", l_val);
        FAPI_IMP("Test IMP Trace. string: %s", l_pStr);
        FAPI_IMP("Test IMP Trace. 0x%x, %s", l_val, l_pStr);

        FAPI_ERR("Test ERR Trace");
        FAPI_ERR("Test ERR Trace. hex: 0x%x", l_val);
        FAPI_ERR("Test ERR Trace. string: %s", l_pStr);
        FAPI_ERR("Test ERR Trace. 0x%x, %s", l_val, l_pStr);

        FAPI_DBG("Test DBG Trace");
        FAPI_DBG("Test DBG Trace. hex: 0x%x", l_val);
        FAPI_DBG("Test DBG Trace. string: %s", l_pStr);
        FAPI_DBG("Test DBG Trace. 0x%x, %s", l_val, l_pStr);

        return;
    }

    /**
      * @brief Test HWPF: call a test procedure that generates an error
      */
    void testHwpf2()
    {
        // Call a test hardware procedure
        errlHndl_t l_err = NULL;

        // Set processor chip to NULL. The target is not used by this HWP
        TARGETING::Target* l_pTarget = NULL;

        // Create a FAPI Target and invoke the hwpTestError HWP. The HWP
        // returns an error to test out error handling
        fapi::Target l_fapiTarget(TARGET_TYPE_PROC_CHIP,
                                  reinterpret_cast<void *> (l_pTarget));

        FAPI_INVOKE_HWP(l_err, hwpTestError, l_fapiTarget);

        if (l_err)
        {
            TS_TRACE("testHwpf2: Unit Test passed. hwpTestError failed. Error logged");
            errlCommit(l_err);
        }
        else
        {
            TS_FAIL("testHwpf2: Unit Test failed. hwpTestError passed. Error logged");
        }
    }
};

#endif
