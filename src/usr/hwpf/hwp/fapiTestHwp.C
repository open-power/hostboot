//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/fapiTestHwp.C $
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
/**
 *  @file fapiTestHwp.C
 *
 *  @brief Implements a simple test Hardware Procedure
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/21/2011  Created.
 *                          mjjones     06/02/2011  Use ecmdDataBufferBase
 *                          mjjones     06/28/2011  Removed attribute tests
 *                          andrewg     07/07/2011  Added test for hw team to fill in
 *                          mjjones     08/10/2011  Removed clock HWP
 *                          mjjones     09/01/2011  Call toString in InitialTest
 *                          mjjones     09/14/2011  Update to scom function name
 *                          camvanng    09/28/2011  Added test for initfile
 *
 */

#include <fapiTestHwp.H>
#include <fapiHwAccess.H>
#include <fapiHwpExecInitFile.H>
extern "C"
{

//******************************************************************************
// Forward Declaration
//******************************************************************************
fapi::ReturnCode testExecInitFile(const fapi::Target & i_chip);

//******************************************************************************
// hwpInitialTest function - Override with whatever you want here
//******************************************************************************
fapi::ReturnCode hwpInitialTest(const fapi::Target & i_chip)
{
    FAPI_INF("Performing HWP: hwpInitialTest");

    // Print the ecmd string of the chip
    char l_string[fapi::MAX_ECMD_STRING_LEN] = {0};
    i_chip.toString(l_string);
    FAPI_INF("hwpInitialTest: Chip: %s", l_string);
    fapi::ReturnCode l_rc;
    uint32_t l_ecmdRc = ECMD_DBUF_SUCCESS;

    do
    {
        // Use this SCOM register for testing
        const uint64_t l_addr = 0x13010002;
        ecmdDataBufferBase l_ScomData(64);
        uint64_t l_originalScomData = 0;

        // --------------------------------------------------------
        // 1. fapiGetScom test
        // --------------------------------------------------------
        l_rc = fapiGetScom(i_chip, l_addr, l_ScomData);
        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: Error from fapiGetScom");
            break;
        }
        else
        {
            // Save the original data so we can restore it later
            l_originalScomData = l_ScomData.getDoubleWord(0);
            FAPI_INF("hwpInitialTest: GetScom data 0x%.16llX", l_originalScomData);
        }

        // --------------------------------------------------------
        // 2. fapiPutScom test
        // --------------------------------------------------------
        uint64_t l_scomWriteValue = 0x9000000000000000;

        l_ecmdRc = l_ScomData.setDoubleWord(0, l_scomWriteValue);
        if (l_ecmdRc != ECMD_DBUF_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: fapiPutScom test, error from ecmdDataBuffer setDoubleWord() - rc 0x%.8X", l_ecmdRc);
            l_rc = l_ecmdRc;
            break;
        }

        l_rc = fapiPutScom(i_chip, l_addr, l_ScomData);
        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: Error from fapiPutScom");
            break;
        }
        else
        {
            FAPI_INF("hwpInitialTest: PutScom data 0x%.16llX", l_scomWriteValue);
        }

        // --------------------------------------------------------
        // 3. fapiPutScomUnderMask test
        // --------------------------------------------------------
        l_scomWriteValue = 0xA000000000000000;
        uint64_t l_mask  = 0x3000000000000000;
        ecmdDataBufferBase l_maskData(64);

        l_ecmdRc = l_ScomData.setDoubleWord(0, l_scomWriteValue);
        l_ecmdRc |= l_maskData.setDoubleWord(0, l_mask);
        if (l_ecmdRc != ECMD_DBUF_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: fapiPutScomUnderMask test, error from ecmdDataBuffer setDoubleWord() - rc 0x%.8X", l_ecmdRc);
            l_rc = l_ecmdRc;
            break;
        }


        l_rc = fapiPutScomUnderMask(i_chip, l_addr, l_ScomData, l_maskData);
        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: Error from fapiPutScomUnderMask");
            break;
        }
        else
        {
            FAPI_INF("hwpInitialTest: fapiPutScomUnderMask data 0x%.16llX, mask 0x%.16llX",
                     l_scomWriteValue, l_mask);
        }

        // --------------------------------------------------------
        // 4. fapiPutScom to restore original value
        // --------------------------------------------------------
        l_ecmdRc = l_ScomData.setDoubleWord(0, l_originalScomData);
        if (l_ecmdRc != ECMD_DBUF_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: fapiPutScom to restore, error from ecmdDataBuffer setDoubleWord() - rc 0x%.8X", l_ecmdRc);
            l_rc = l_ecmdRc;
            break;
        }

        l_rc = fapiPutScom(i_chip, l_addr, l_ScomData);
        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: Error from fapiPutScom");
            break;
        }
        else
        {
            FAPI_INF("hwpInitialTest: PutScom data 0x%.16llX", l_originalScomData);
        }

#if 0
// @todo
// Per Dean, there's no access to the CFAM engines on the master processor, therefore,
// we *should not* allow access to them on any processor in any position
// from a FAPI standpoint.
// This means that get/put/modifyCfamRegister can't not be called on any of the processors.
// These functions, therefore, can only be called on the Centaur, which is not available
// at this time.
// When Centaur is supported:
//  - Don't use i_chip (a processor) as a target. Set the target as one of the Centaurs.
//  - Enable this block of code and test the cfam access functions on the Centaur.

        // --------------------------------------------------------
        // 5. fapiGetCfamRegister test
        // --------------------------------------------------------
        ecmdDataBufferBase l_cfamData(32); // 32-bit cfam data holder
        uint32_t l_originalCfamData = 0;
        const uint32_t l_cfamAddr = 0x100A; // ChipID register
        l_rc = fapiGetCfamRegister(i_chip, l_cfamAddr, l_cfamData);
        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: Error from fapiGetCfamRegister");
            break;
        }
        else
        {
            l_originalCfamData = l_cfamData.getWord(0);
            FAPI_INF("hwpInitialTest: fapiGetCfamRegister data 0x%.8X",
                    l_originalCfamData);
        }

        // --------------------------------------------------------
        // 6. fapiPutCfamRegister test
        // --------------------------------------------------------
        uint32_t l_cfamWriteValue = 0x90000000;
        l_ecmdRc = l_cfamData.setWord(0, l_cfamWriteValue);
        if (l_ecmdRc != ECMD_DBUF_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: fapiPutCfamRegister test, error from ecmdDataBuffer setWord() - rc 0x%.8X", l_ecmdRc);
            l_rc = l_ecmdRc;
            break;
        }


        l_rc = fapiPutCfamRegister(i_chip, l_cfamAddr, l_cfamData);
        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: Error from fapiPutCfamRegister");
            break;
        }
        else
        {
            FAPI_INF("hwpInitialTest: fapiPutCfamRegister data 0x%.8X",
                    l_cfamData.getWord(0));
        }

        // --------------------------------------------------------
        // 7. fapiModifyCfamRegister test
        // --------------------------------------------------------
        l_cfamWriteValue = 0xA0000000;
        l_ecmdRc = l_cfamData.setWord(0, l_cfamWriteValue);
        if (l_ecmdRc != ECMD_DBUF_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: fapiModifyCfamRegister test, error from ecmdDataBuffer setWord() - rc 0x%.8X", l_ecmdRc);
            l_rc = l_ecmdRc;
            break;
        }

        l_rc = fapiModifyCfamRegister(i_chip, l_cfamAddr,
                l_cfamData, fapi::CHIP_OP_MODIFY_MODE_AND);
        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: Error from fapiPutCfamRegister");
            break;
        }
        else
        {
            FAPI_INF("hwpInitialTest: fapiPutCfamRegister data 0x%.8X",
                    l_cfamData.getWord(0));
        }

        // --------------------------------------------------------
        // 8. fapiPutCfamRegister to restore original CFAM value
        // --------------------------------------------------------
        l_ecmdRc = l_cfamData.setWord(0, l_originalCfamData);
        if (l_ecmdRc != ECMD_DBUF_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: fapiPutCfamRegister to restore, error from ecmdDataBuffer setWord() - rc 0x%.8X", l_ecmdRc);
            l_rc = l_ecmdRc;
            break;
        }

        l_rc = fapiPutCfamRegister(i_chip, l_cfamAddr, l_cfamData);
        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: Error from fapiPutCfamRegister to restore");
            break;
        }
        else
        {
            FAPI_INF("hwpInitialTest: fapiPutCfamRegister data 0x%.8X",
                    l_cfamData.getWord(0));
        }

#endif

        // --------------------------------------------------------
        // 9. hwpExecInitFile test
        // --------------------------------------------------------

        l_rc = testExecInitFile(i_chip);
        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: Error from testExecInitFile");
            break;
        }
        else
        {
            FAPI_INF("hwpInitialTest: Test testExecInitFile passed");
        }

    } while (0);

    return l_rc;
}


//******************************************************************************
// testExecInitFile function - function to test sample initfile
//******************************************************************************
fapi::ReturnCode testExecInitFile(const fapi::Target & i_chip)
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
        {0x0000000013010002, 0, 0x0000000000000181},
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
        {0x0000000013013289, 0, 0x8000000000000000 >> 0x17},
        {0x0000000013030007, 0, 0x0000000000000182}
    };

    fapi::ReturnCode l_rc = fapi::FAPI_RC_SUCCESS;
    uint32_t l_ecmdRc = ECMD_DBUF_SUCCESS;
    ecmdDataBufferBase l_ScomData(64);

    do {
        // Set up some attributes for testing
        uint8_t l_uint8 = 1;
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_1, NULL, l_uint8);
        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: testExecInitFile: "
                     "ATTR_SCRATCH_UINT8_1. Error from SET");
            break;
        }

        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_2, NULL, l_uint8);
        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: testExecInitFile: "
                     "ATTR_SCRATCH_UINT8_2. Error from SET");
            break;
        }

        uint32_t l_uint32 = 3;
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT32_1, NULL, l_uint32);
        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: testExecInitFile: "
                     "ATTR_SCRATCH_UINT32_1. Error from SET");
            break;
        }

        uint64_t l_uint64 = 2;
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_1, NULL, l_uint64);
        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: testExecInitFile: "
                     "ATTR_SCRATCH_UINT64_1. Error from SET");
            break;
        }

        uint8_t l_uint8array1[32];
        l_uint8array1[2] = 1;
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_ARRAY_1, NULL, l_uint8array1);
        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: testExecInitFile: "
                     "ATTR_SCRATCH_UINT8_ARRAY_1. Error from SET");
            break;
        }

        // Save original scom data to restore at end of test
        for (uint32_t i = 0; i < sizeof(l_ifScomData)/sizeof(ifScom_t); i++)
        {
            l_rc = fapiGetScom(i_chip, l_ifScomData[i].addr, l_ScomData);
            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                FAPI_ERR("hwpInitialTest: testExecInitFile: Error from "
                         "fapiGetScom");
                break;
            }

            l_ifScomData[i].origData = l_ScomData.getDoubleWord(0);
        }

        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            break;
        }

        // Set scom data to 0 to start from known state for bit ops
        l_ScomData.setDoubleWord(0, 0ll);
        for (uint32_t i = 0; i < sizeof(l_ifScomData)/sizeof(ifScom_t); i++)
        {
            l_rc = fapiPutScom(i_chip, l_ifScomData[i].addr, l_ScomData);
            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                FAPI_ERR("hwpInitialTest: testExecInitFile: Error from "
                         "fapiPutScom");
                break;
            }
        }

        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            break;
        }

        //Call Hwp to execute the initfile
        FAPI_EXEC_HWP(l_rc, hwpExecInitFile, i_chip, "sample.if");
        
        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: Error from hwpExecInitFile");
            break;
        }

        //Verify the data written
        for (uint32_t i = 0; i < sizeof(l_ifScomData)/sizeof(ifScom_t); i++)
        {
            l_rc = fapiGetScom(i_chip, l_ifScomData[i].addr, l_ScomData);
            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                FAPI_ERR("hwpInitialTest: testExecInitFile: Error from "
                         "fapiGetScom");
                break;
            }

            if (l_ScomData.getDoubleWord(0) != l_ifScomData[i].writtenData)
            {
                FAPI_ERR("hwpInitialTest: testExecInitFile: GetScom addr "
                         "0x%.16llX data read 0x%.16llX data expected 0x%.16llX",
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

        // Restore the original Scom data
        for (uint32_t i = 0; i < sizeof(l_ifScomData)/sizeof(ifScom_t); i++)
        {
            l_ecmdRc = l_ScomData.setDoubleWord(0, l_ifScomData[i].origData);
            if (l_ecmdRc != ECMD_DBUF_SUCCESS)
            {
                FAPI_ERR("hwpInitialTest: testExecInitFile: fapiPutScom to "
                         "restore, error from ecmdDataBuffer setDoubleWord() - "
                         "rc 0x%.8X", l_ecmdRc);
                l_rc = l_ecmdRc;
                break;
            }

            l_rc = fapiPutScom(i_chip, l_ifScomData[i].addr, l_ScomData);
            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                FAPI_ERR("hwpInitialTest: testExecInitFile: Error from "
                         "fapiGetScom");
                break;
            }
        }

        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            break;
        }

    } while (0);

    return l_rc;
}


} // extern "C"
