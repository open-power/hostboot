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
      * @brief Test HWPF: calling a procedure
      */
    void testHwpf2()
    {
        // Call a test hardware procedure
        errlHndl_t l_err = NULL;

        // Set processor chip to the master
        TARGETING::Target* l_testTarget = MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

        // Call the hardware procedure
        bool l_clocksOn = false;
        l_err = invokeHwpIsP7EM0ChipletClockOn(l_testTarget, l_clocksOn);
        if (l_err)
        {
            TS_FAIL("testHwpf2: Unit Test failed. HWP failed. Error logged");
            // Commit/delete error
            errlCommit(l_err);
        }
        else
        {
            if (l_clocksOn)
            {
                TS_TRACE("testHwpf2: Success. Clocks are on");
            }
            else
            {
                TS_TRACE("testHwpf2: Success. Clocks are off");
            }
        }

        return;
    }

};

#endif
