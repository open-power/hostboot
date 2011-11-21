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
#include <fapiHwpExecInitFile.H>

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
            // Delete the error rather than committing it to avoid it getting
            // interpreted as a real problem
            TS_TRACE("testHwpf2: Unit Test passed. hwpTestError failed. Error deleted");
            delete l_err;
            l_err = NULL;
        }
        else
        {
            TS_FAIL("testHwpf2: Unit Test failed. hwpTestError passed. Error logged");
        }
    }

    /**
     * @brief Test HWPF Config: call a test procedure that exercises the FAPI
     *        config query functions
     */
    void testHwpf3()
    {
        errlHndl_t l_err = NULL;

        // Get the master processor chip
        TARGETING::Target* l_pTarget = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(l_pTarget);

        // Create a FAPI Target and invoke the hwpTestConfig HWP. The HWP
        // exercises the FAPI config query functions
        fapi::Target l_fapiTarget(TARGET_TYPE_PROC_CHIP,
                                  reinterpret_cast<void *> (l_pTarget));

        FAPI_INVOKE_HWP(l_err, hwpTestConfig, l_fapiTarget);

        if (l_err)
        {
            TS_FAIL("testHwpf3: Unit Test failed. hwpTestConfig failed. Error logged");
            errlCommit(l_err,HWPF_COMP_ID);
        }
        else
        {
            TS_TRACE("testHwpf3: Unit Test passed. hwpTestConfig passed. Error logged");
        }
    }

    /**
     * @brief Test HWPF Attributes: call a test procedure that exercises the FAPI
     *        scratch attributes
     */
    void testHwpf4()
    {
        errlHndl_t l_err = NULL;

        FAPI_INVOKE_HWP(l_err, hwpTestAttributes);

        if (l_err)
        {
            TS_FAIL("testHwpf4: Unit Test failed. hwpTestAttributes failed. Error logged");
            errlCommit(l_err,HWPF_COMP_ID);
        }
        else
        {
            TS_TRACE("testHwpf4: Unit Test passed. hwpTestAttributes passed. Error logged");
        }
    }

    /**
     * @brief Test HWPF InitFile: call the procedure that exercises a sample initfile
     */
    void testHwpf5()
    {
        typedef struct ifScom {
            uint64_t addr;
            uint64_t origData;
            uint64_t writtenData;
        }ifScom_t;

        //Note:  this data is based on the sample.initfile.
        //If the initfile changes, this data will also need to be changed.
        ifScom_t l_ifScomData[] =
        {
            {0x000000000006002b, 0, 0x0000000000000183},
            {0x000000000006002c, 0, 0x0000000000000183},
            {0x000000000006800b, 0, 0},
            {0x000000000006800c, 0, 0x8000000000000000 >> 0x17},
            {0x0000000013010002, 0, 0xAABBC00000000000},
            {0x0000000013030007, 0, 0x00000CDE00000000},
            /*
             * @todo
             * @VBU workaround
             * All SCR reg addresses below are only supported from chip release 052 and beyond.
             * Release 051, which is used by current VBU model, contain different addresses for
             * these registers.
             * Disable them for now, needs to re-enable them when VBU upgrade to use chip release 052
                        {0x0000000013013283, 0, 0x3c90000000000000 |
                                                0x8000000000000000 >> 0x0c |
                                                0x8000000000000000 >> 0x0d |
                                                0x0306400412000000 >> 0x0e},
                        {0x0000000013013284, 0, 0x3c90000000000000},
                        {0x0000000013013285, 0, 0x8000000000000000 >> 0x0f |
                                                0x8000000000000000 >> 0x10 |
                                                0x8000000000000000 >> 0x13 |
                                                0x0306400412000000 >> 0x15 },
                        {0x0000000013013286, 0, 0},
                        {0x0000000013013287, 0, 0x0000000000000182},
                        {0x0000000013013288, 0, 0x0000000000000192},
                        {0x0000000013013289, 0, 0x8000000000000000 >> 0x17}
            */
        };

        fapi::ReturnCode l_rc = fapi::FAPI_RC_SUCCESS;
        ecmdDataBufferBase l_ScomData(64);

        do {
            // Set up some attributes for testing
            uint8_t l_uint8 = 1;
            l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_1, NULL, l_uint8);
            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                TS_FAIL("testHwpf5: ATTR_SCRATCH_UINT8_1. Error from SET");
                break;
            }

            l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_2, NULL, l_uint8);
            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                TS_FAIL("testHwpf5: ATTR_SCRATCH_UINT8_2. Error from SET");
                break;
            }

            uint32_t l_uint32 = 3;
            l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT32_1, NULL, l_uint32);
            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                TS_FAIL("testHwpf5: ATTR_SCRATCH_UINT32_1. Error from SET");
                break;
            }

            uint64_t l_uint64 = 2;
            l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_1, NULL, l_uint64);
            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                TS_FAIL("testHwpf5: ATTR_SCRATCH_UINT64_1. Error from SET");
                break;
            }

            uint8_t l_uint8array1[32];
            l_uint8array1[2] = 1;
            l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_ARRAY_1, NULL, l_uint8array1);
            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                TS_FAIL("testHwpf5: ATTR_SCRATCH_UINT8_ARRAY_1. Error from SET");
                break;
            }

            uint8_t l_uint8array2[2][3][4];
            l_uint8array2[1][2][3] = 0xBE;
            l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_ARRAY_2, NULL, l_uint8array2);
            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                FAPI_IMP("testHwpf5: ATTR_SCRATCH_UINT8_ARRAY_2. Error from SET");
                break;
            }

            // Get the master processor chip
            TARGETING::Target* l_pTarget = NULL;
            TARGETING::targetService().masterProcChipTargetHandle(l_pTarget);

            // Create a FAPI Target and invoke the hwpInitialTest HWP
            fapi::Target l_fapiTarget(TARGET_TYPE_PROC_CHIP,
                                      reinterpret_cast<void *> (l_pTarget));

            /*
            // Save original scom data to restore at end of test
            for (uint32_t i = 0; i < sizeof(l_ifScomData)/sizeof(ifScom_t); i++)
            {
                l_rc = fapiGetScom(l_fapiTarget, l_ifScomData[i].addr, l_ScomData);
                if (l_rc != fapi::FAPI_RC_SUCCESS)
                {
                    TS_FAIL("testHwpf5: Error from fapiGetScom");
                    break;
                }

                l_ifScomData[i].origData = l_ScomData.getDoubleWord(0);
            }

            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                break;
            }
            */

            // Set scom data to 0 to start from known state for bit ops
            l_ScomData.setDoubleWord(0, 0ll);
            for (uint32_t i = 0; i < sizeof(l_ifScomData)/sizeof(ifScom_t); i++)
            {
                l_rc = fapiPutScom(l_fapiTarget, l_ifScomData[i].addr, l_ScomData);
                if (l_rc != fapi::FAPI_RC_SUCCESS)
                {
                    TS_FAIL("testHwpf5: Error from fapiPutScom");
                    break;
                }
            }

            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                break;
            }

            //Call Hwp to execute the initfile
            FAPI_EXEC_HWP(l_rc, hwpExecInitFile, l_fapiTarget, "sample.if");
            
            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                TS_FAIL("testHwpf5: Error from hwpExecInitFile");
                break;
            }

            //Verify the data written
            for (uint32_t i = 0; i < sizeof(l_ifScomData)/sizeof(ifScom_t); i++)
            {
                l_rc = fapiGetScom(l_fapiTarget, l_ifScomData[i].addr, l_ScomData);
                if (l_rc != fapi::FAPI_RC_SUCCESS)
                {
                    TS_FAIL("testHwpf5: Error from fapiGetScom");
                    break;
                }

                if (l_ScomData.getDoubleWord(0) != l_ifScomData[i].writtenData)
                {
                    TS_FAIL("testHwpf5: GetScom addr 0x%.16llX data read 0x%.16llX "
                             "data expected 0x%.16llX",
                             l_ifScomData[i].addr, l_ScomData.getDoubleWord(0),
                             l_ifScomData[i].writtenData);
                    l_rc = fapi::RC_HWP_EXEC_INITFILE_TEST_FAILED;
                    break;
                }
            }

            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                break;
            }

            /*
            // Restore the original Scom data
            //uint32_t l_ecmdRc = ECMD_DBUF_SUCCESS;
            for (uint32_t i = 0; i < sizeof(l_ifScomData)/sizeof(ifScom_t); i++)
            {
                l_ecmdRc = l_ScomData.setDoubleWord(0, l_ifScomData[i].origData);
                if (l_ecmdRc != ECMD_DBUF_SUCCESS)
                {
                    TS_FAIL("testHwpf5: fapiPutScom to restore, error from "
                             "ecmdDataBuffer setDoubleWord() - rc 0x%.8X", l_ecmdRc);
                    l_rc = l_ecmdRc;
                    break;
                }

                l_rc = fapiPutScom(l_fapiTarget, l_ifScomData[i].addr, l_ScomData);
                if (l_rc != fapi::FAPI_RC_SUCCESS)
                {
                    TS_FAIL("testHwpf5: Error from fapiGetScom");
                    break;
                }
            }

            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                break;
            }
            */

        } while (0);

        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            fapiLogError(l_rc);
            TS_FAIL("testHwpf5: Unit Test failed. Error logged");
        }
        else
        {
            TS_TRACE("testHwpf5: Unit Test passed. hwpExecInitFile passed.");
        }
    }

};

#endif
