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
#include <targeting/common/commontargeting.H>
#include <fapiHwpExecInitFile.H>
#include <spd/spdenums.H>

using namespace fapi;
using namespace TARGETING;

struct ifScom_t {
    uint64_t addr;
    uint64_t data;
};

struct hwpfTestArgs_t {
    ifScom_t      ifScom;
    fapi::Target  fapiTarget;
    uint32_t      count;
    tid_t         tid;
    struct {
        uint64_t  Write:1;    // 1 = Write
        uint64_t  AttrTest:1; // 1 = run Attr access test
        uint64_t  ScomTest:1; // 1 = run Scom register access test
    };
};

static const uint32_t ATTR_TEST_VALUE   = 10;
static const uint32_t MAX_TEST_TASKS    = 30;
static const uint32_t CREATE_TASK_PAIRS = 6;
static const uint32_t MAX_TEST_COUNT    = 0x000001FF;

/**
 * @brief repeated Scom access and Attrubute access through Fapi until
 *        MAX_TEST_COUNT accesses has been done or an error occurs.
 */
void testHwpScomAcc( void *i_phwpTestArgs )
{
    fapi::ReturnCode l_rc = fapi::FAPI_RC_SUCCESS;
    ecmdDataBufferBase l_ScomData(64);

    hwpfTestArgs_t * l_args = static_cast<hwpfTestArgs_t *>(i_phwpTestArgs);

    // repeat as long as no error and in running mode until count reaches
    // at MAX_TEST_COUNT or an error occurs
    for (l_args->count = 0; l_args->count != MAX_TEST_COUNT; ++l_args->count)
    {
        if (l_args->Write)
        {
            if (l_args->ScomTest)
            {
                // set up ecmdDataBuffer with written data
                l_ScomData.setDoubleWord(0, (l_args->ifScom).data);
                l_rc = fapiPutScom( l_args->fapiTarget,
                                    (l_args->ifScom).addr, l_ScomData );

                if (l_rc != fapi::FAPI_RC_SUCCESS)
                {
                    TS_TRACE("testHwpScomAcc: Error from fapiPutScom");
                    break;
                }
            }

            if (l_args->AttrTest)
            {
                uint8_t l_uint8_1 = ATTR_TEST_VALUE;
                l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_1, NULL, l_uint8_1);
                if (l_rc != fapi::FAPI_RC_SUCCESS)
                {
                    TS_TRACE("testHwpScomAcc: ATTR_SCRATCH_UINT8_1. "
                             "Error from SET");
                    break;
                }
            }
        }
        else
        {
            if (l_args->ScomTest)
            {
                l_rc = fapiGetScom( l_args->fapiTarget,
                                    (l_args->ifScom).addr, l_ScomData );
                if (l_rc != fapi::FAPI_RC_SUCCESS)
                {
                    TS_TRACE("testHwpScomAcc: Error RC from fapiGetScom");
                    break;
                }
                if ((l_args->ifScom).data != l_ScomData.getDoubleWord(0))
                {
                    (l_args->ifScom).data = l_ScomData.getDoubleWord(0);
                    TS_TRACE("testHwpScomAcc: Error Data from fapiGetScom");
                    break;
                }
            }

            if (l_args->AttrTest)
            {
                uint8_t l_uint8_2 = 0xff;
                l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT8_1, NULL, l_uint8_2);
                if (l_rc != fapi::FAPI_RC_SUCCESS)
                {
                    TS_TRACE("testHwpScomAcc: ATTR_SCRATCH_UINT8_1."
                            "  Error RC from GET");
                    break;
                }
                if (l_uint8_2 != ATTR_TEST_VALUE)
                {
                    TS_TRACE("testHwpScomAcc: ATTR_SCRATCH_UINT8_1."
                            " Error data %d from GET", l_uint8_2);
                    break;
                }
            }
        }
    }
}

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
        errlHndl_t l_err = NULL;

        // Get the master processor chip
        TARGETING::Target* l_pTarget = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(l_pTarget);

        // Create a FAPI Target and invoke the hwpTestError HWP. The HWP
        // returns an error to test out error handling
        fapi::Target l_fapiTarget(TARGET_TYPE_PROC_CHIP,
                                  reinterpret_cast<void *> (l_pTarget));

        FAPI_INVOKE_HWP(l_err, hwpTestError, l_fapiTarget);

        if (l_err)
        {
            // Delete the error rather than committing it to avoid it getting
            // interpreted as a real problem
            TS_TRACE("testHwpf2: Unit Test passed. "
                     "hwpTestError failed. Error deleted");
            delete l_err;
            l_err = NULL;
        }
        else
        {
            TS_FAIL("testHwpf2: Unit Test failed. "
                    "hwpTestError passed. Error logged");
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
            TS_FAIL("testHwpf3: Unit Test failed. "
                    "hwpTestConfig failed. Error logged");
            errlCommit(l_err,HWPF_COMP_ID);
        }
        else
        {
            TS_TRACE("testHwpf3: Unit Test passed. "
                     "hwpTestConfig passed. Error logged");
        }
    }

    /**
     * @brief Test HWPF Attributes: call a test procedure that exercises
     *        the FAPI scratch attributes
     */
    void testHwpf4()
    {
        errlHndl_t l_err = NULL;

        FAPI_INVOKE_HWP(l_err, hwpTestAttributes);

        if (l_err)
        {
            TS_FAIL("testHwpf4: Unit Test failed. "
                    "hwpTestAttributes failed. Error logged");
            errlCommit(l_err,HWPF_COMP_ID);
        }
        else
        {
            TS_TRACE("testHwpf4: Unit Test passed. "
                     "hwpTestAttributes passed. Error logged");
        }
    }

    /**
     * @brief Test HWPF InitFile: call the procedure that exercises a
     *        sample initfile
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
            {0x000000000006002b, 0, 0x0000000000000000 |
                                    (0x00000000000000C4ll << (64 - (32 + 8)))},
            {0x000000000006002c, 0, (0x0000000000000001ll << (64 - 8)) |
                                    (0x0000000000000008ll << (64 - (24 + 8)))},
            {0x000000000006800b, 0, 0},
            {0x000000000006800c, 0, (0x8000000000000000 >> 0x17) |
                                    (0x00000000000000BEll << (64 - (24 + 8))) |
                                    0x0000000000000003},
            {0x0000000013010002, 0, 0xAABBC00000000000},
            {0x0000000013030007, 0, 0x00000CDE00000000},
            {0x0000000013013283, 0, 0x3c90000000000000 |
                                    (0x8000000000000000 >> 0x0c) |
                                    (0x8000000000000000 >> 0x0d) |
                                    (0x0306400412000000 >> 0x0e)},
            {0x0000000013013284, 0, 0x3c90000000000000},
            {0x0000000013013285, 0, (0x8000000000000000 >> 0x0f) |
                                    (0x8000000000000000 >> 0x10) |
                                    (0x8000000000000000 >> 0x13) |
                                    (0x0306400412000000 >> 0x15) },
            {0x0000000013013286, 0, 0},
            {0x0000000013013287, 0, 0x0000000000000182},
            {0x0000000013013288, 0, 0x0000000000000192},
            {0x0000000013013289, 0, 0x8000000000000000 >> 0x17}
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
            l_uint8array1[0] = 1;
            l_uint8array1[1] = 4;
            l_uint8array1[2] = 1;
            l_uint8array1[3] = 2;
            l_uint8array1[7] = 1;
            l_uint8array1[17] = 6;
            l_uint8array1[18] = 6;
            l_uint8array1[31] = 8;
            l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_ARRAY_1,
                                                       NULL, l_uint8array1);
            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                TS_FAIL("testHwpf5: ATTR_SCRATCH_UINT8_ARRAY_1. "
                        " Error from SET");
                break;
            }

            uint8_t l_uint8array2[2][3][4];
            l_uint8array2[0][1][2] = 0xC4;
            l_uint8array2[1][2][3] = 0xBE;
            l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_ARRAY_2,
                                                       NULL, l_uint8array2);
            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                TS_FAIL("testHwpf5: ATTR_SCRATCH_UINT8_ARRAY_2. "
                        "Error from SET");
                break;
            }

            // Test ATTR_IS_SIMULATION access through FAPI
            uint8_t l_flag;
            l_rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, l_flag);
            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                TS_FAIL("testHwpf5: ATTR_IS_SIMULATION. Error from GET");
                break;
            }
            else
            {
                //printk("ATTR_IS_SIMULATION = %d\n", l_flag);
            }

            // Get the master processor chip
            TARGETING::Target* l_pTarget = NULL;
            TARGETING::targetService().masterProcChipTargetHandle(l_pTarget);

            fapi::Target l_fapiTarget(TARGET_TYPE_PROC_CHIP,
                                      reinterpret_cast<void *> (l_pTarget));

            // Test ATTR_EC attribute access through FAPI
            uint8_t l_EC_R = 0xFF;

            l_rc = FAPI_ATTR_GET(ATTR_EC, &l_fapiTarget, l_EC_R);
            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                TS_FAIL("testHwpf5: ATTR_EC. Error from GET");
                break;
            }

            //printk("EC = %d\n", l_EC_R);

            /*
            // Save original scom data to restore at end of test
            for (uint32_t i = 0; i < sizeof(l_ifScomData)/sizeof(ifScom_t); i++)
            {
                l_rc = fapiGetScom(l_fapiTarget, l_ifScomData[i].addr,
                                                                   l_ScomData);
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
                l_rc = fapiPutScom(l_fapiTarget, l_ifScomData[i].addr,
                                                                   l_ScomData);
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
            FAPI_EXEC_HWP(l_rc, fapiHwpExecInitFile, l_fapiTarget, "sample.if");
            
            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                TS_FAIL("testHwpf5: Error from fapiHwpExecInitFile");
                break;
            }

            //Verify the data written
            for (uint32_t i = 0; i < sizeof(l_ifScomData)/sizeof(ifScom_t); i++)
            {
                l_rc = fapiGetScom(l_fapiTarget, l_ifScomData[i].addr,
                                                                   l_ScomData);
                if (l_rc != fapi::FAPI_RC_SUCCESS)
                {
                    TS_FAIL("testHwpf5: Error from fapiGetScom");
                    break;
                }

                if (l_ScomData.getDoubleWord(0) != l_ifScomData[i].writtenData)
                {
                    TS_FAIL("testHwpf5: GetScom addr 0x%.16llX "
                            "data read 0x%.16llX data expected 0x%.16llX",
                             l_ifScomData[i].addr, l_ScomData.getDoubleWord(0),
                             l_ifScomData[i].writtenData);
                    FAPI_SET_HWP_ERROR(l_rc, RC_HWP_EXEC_INITFILE_TEST_FAILED);
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
                l_ecmdRc = l_ScomData.setDoubleWord(0,l_ifScomData[i].origData);
                if (l_ecmdRc != ECMD_DBUF_SUCCESS)
                {
                    TS_FAIL("testHwpf5: fapiPutScom to restore, error from "
                            "ecmdDataBuffer setDoubleWord() - rc 0x%.8X",
                            l_ecmdRc);
                    l_rc.setEcmdError(l_ecmdRc);
                    break;
                }

                l_rc = fapiPutScom(l_fapiTarget, l_ifScomData[i].addr,
                                                                   l_ScomData);
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
            TS_TRACE("testHwpf5: Unit Test passed. "
                     "fapiHwpExecInitFile passed.");
        }
    }

    /**
     * @brief Test case for stressing the taskmgr, memory usage, and HWPF API
     *        It starts (CREATE_TASK_PAIRS * 2) tasks.
     */
    void testHwpf6()
    {
        fapi::ReturnCode l_rc = fapi::FAPI_RC_SUCCESS;

        // Get the sys target handle
        TARGETING::Target* l_pTarget = NULL;
        TARGETING::targetService().getTopLevelTarget(l_pTarget);

        uint8_t l_vpoMode = 0;

        if (l_pTarget &&
            l_pTarget->tryGetAttr<TARGETING::ATTR_IS_SIMULATION>(l_vpoMode) &&
            l_vpoMode == 0)
        {
            static const uint32_t NUM_OF_SCOMREGS = 6;
            ifScom_t l_ifScom[NUM_OF_SCOMREGS] =
            {
                {0x000000000006002b, 0x0000000000000183},
                {0x000000000006002c, 0x0000000000000183},
                {0x000000000006800b, 0},
                {0x000000000006800c, 0x8000000000000000 >> 0x17},
                {0x0000000013010002, 0xAABBC00000000000},
                {0x0000000013030007, 0x00000CDE00000000},
            };

            // Get the master processor chip
            l_pTarget = NULL;
            TARGETING::targetService().masterProcChipTargetHandle(l_pTarget);

            // Create a FAPI Target of the master processor
            fapi::Target l_fapiTarget(TARGET_TYPE_PROC_CHIP,
                                          reinterpret_cast<void *> (l_pTarget));

            hwpfTestArgs_t l_args[MAX_TEST_TASKS] = {{{0},},};

            uint8_t l_index = 0;
            uint32_t i;

            for (i = 0; i < (CREATE_TASK_PAIRS * 2); i++)
            {
                // start one task
                l_args[i].ifScom      = l_ifScom[l_index];
                l_args[i].fapiTarget  = l_fapiTarget;
                l_args[i].Write       = (i % 2) ? 0 : 1;
                l_args[i].AttrTest    = 1;
                l_args[i].ScomTest    = 1;
                l_args[i].tid = task_create(testHwpScomAcc,
                                            static_cast<void *>(&l_args[i]));
                // Change ifScom register after a pair of tasks started
                l_index = (i % 2) ? (l_index + 1) % NUM_OF_SCOMREGS : l_index;
            }

            int status;

            for (i = 0; i < MAX_TEST_TASKS; i++)
            {
                if (l_args[i].ifScom.addr != 0)
                {
                    task_wait_tid( l_args[i].tid, &status,  NULL );
                }
            }

            for (i = 0; i < NUM_OF_SCOMREGS; i++)
            {
                ecmdDataBufferBase l_ScomData(64);
                l_rc = fapiGetScom( l_fapiTarget, l_ifScom[i].addr,
                                                             l_ScomData );
                if (l_rc != fapi::FAPI_RC_SUCCESS ||
                    l_ScomData.getDoubleWord(0) != l_ifScom[i].data)
                {
                    TS_FAIL("testHwpf6: Scom register has unexpected data");
                    break;
                }
            }

            if (l_rc.ok() && i == NUM_OF_SCOMREGS)
            {
                uint8_t l_uint8 = 0;
                l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT8_1, NULL, l_uint8);
                if (l_rc != fapi::FAPI_RC_SUCCESS || l_uint8 != ATTR_TEST_VALUE)
                {
                    TS_FAIL("testHwpf6: ATTR_SCRATCH_UINT8_1"
                             " has unexpected data");
                }
                else
                {
                    TS_TRACE("testHwpf6: Unit Test passed.");
                }
            }
        }
    }

//    // unit test breakpoint
//    void testHwpf7()
//    {
//        fapi::Target  fapiTarget;
//        FAPI_INF("AT breakpoint");
//        fapiBreakPoint(fapiTarget,__LINE__);
//
//        // requires outside hb-istep resume  command to continue
//
//        FAPI_INF("RESUME from breakpoint");
//    }

    /**
     * @brief Test case Accessing DIMM SPD Attribute from FAPI
     *
     */
    void testHwpf8()
    {
        fapi::ReturnCode l_rc;

        do
        {
            // Get top level system target
            TARGETING::TargetService& tS = TARGETING::targetService();
            TARGETING::Target * sysTarget = NULL;
            tS.getTopLevelTarget( sysTarget );

            if (sysTarget == NULL)
            {
                FAPI_ERR("testHwpf8: Can't obtain system target");
                break;
            }

            // Get a DIMM Target
            TARGETING::PredicateCTM predDimm( TARGETING::CLASS_LOGICAL_CARD,
                                              TARGETING::TYPE_DIMM );
            TargetHandleList dimmList;

            tS.getAssociated( dimmList,
                              sysTarget,
                              TARGETING::TargetService::CHILD,
                              TARGETING::TargetService::ALL,
                              &predDimm );
 
            if (dimmList.size())
            {
                fapi::Target l_dTarget(TARGET_TYPE_DIMM,
                                       static_cast<void *> (dimmList[0]));

                uint8_t opt[18] = { 0, };

                l_rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_PART_NUMBER,
                                                       &l_dTarget, opt);

                if (l_rc.ok())
                {
                    FAPI_INF("testHwpf8: PN = %s", opt);
                }
                else
                {
                    TS_FAIL("testHwpf8: ATTR_SPD_MODULE_PART_NUMBER GET fails");
                }
            }

        } while(0);

    }

    /**
     * @brief Call a test procedure that exercises the Bad DQ data
     */
    void testHwpf9()
    {
        errlHndl_t l_err = NULL;

        // Look for MBA chiplets
        TARGETING::PredicateCTM l_mbaFilter(CLASS_UNIT, TYPE_MBA);
        TARGETING::TargetRangeFilter l_filter(
            TARGETING::targetService().begin(),
            TARGETING::targetService().end(),
            &l_mbaFilter);

        // Invoke the HWP on the first one
        if (l_filter)
        {
            fapi::Target l_fapiTarget(TARGET_TYPE_MBA_CHIPLET,
                static_cast<void *> (*l_filter));

            FAPI_INVOKE_HWP(l_err, fapiTestHwpDq, l_fapiTarget);

            if (l_err)
            {
                TS_FAIL("testHwpf9: fapiTestHwpDq failed. Error logged");
                errlCommit(l_err, HWPF_COMP_ID);
            }
            else
            {
                TS_TRACE("testHwpf9: Unit Test passed");
            }
        }
        else
        {
            TS_TRACE("testHwpf9: No MBAs found, skipping test");
        }
    }
};

#endif
