/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/fapiTestHwp.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
 *                          camvanng    11/16/2011  Change function name
 *                                                  fapiHwpExecInitFile()
 *                          mjjones     01/13/2012  Use new ReturnCode interfaces
 *                          mjjones     02/21/2012  Use new Target toEcmdString
 *                          camvanng    05/07/2012  Suppport for associated
 *                                                  target attributes
 *
 *  HWP_IGNORE_VERSION_CHECK
 */

#include <fapiTestHwp.H>
#include <fapiHwAccess.H>
#include <fapiHwpExecInitFile.H>
extern "C"
{

//******************************************************************************
// hwpInitialTest function - Override with whatever you want here
//******************************************************************************
fapi::ReturnCode hwpInitialTest(const std::vector<fapi::Target> & i_target)
{
    FAPI_INF("Performing HWP: hwpInitialTest");

    // Print the ecmd string of the target(s)
    for (size_t i = 0; i < i_target.size(); i++)
    {
        FAPI_INF("hwpInitialTest: target[%u]: %s", i, i_target.at(i).toEcmdString());
    }

    fapi::ReturnCode l_rc;
    uint32_t l_ecmdRc = ECMD_DBUF_SUCCESS;

    do
    {
        // Use PORE_GPE0_SCRATCH2_0x0006000C Scom register for testing
        const uint64_t l_addr = 0x0006000C;
        ecmdDataBufferBase l_ScomData(64);
        uint64_t l_originalScomData = 0;

        // --------------------------------------------------------
        // 1. fapiGetScom test
        // --------------------------------------------------------
        l_rc = fapiGetScom(i_target.front(), l_addr, l_ScomData);
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
        uint64_t l_scomWriteValue = 0x9000000000000000ULL;

        l_ecmdRc = l_ScomData.setDoubleWord(0, l_scomWriteValue);
        if (l_ecmdRc != ECMD_DBUF_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: fapiPutScom test, error from ecmdDataBuffer setDoubleWord() - rc 0x%.8X", l_ecmdRc);
            l_rc.setEcmdError(l_ecmdRc);
            break;
        }

        l_rc = fapiPutScom(i_target.front(), l_addr, l_ScomData);
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
        l_scomWriteValue = 0xA000000000000000ULL;
        uint64_t l_mask  = 0x3000000000000000ULL;
        ecmdDataBufferBase l_maskData(64);

        l_ecmdRc = l_ScomData.setDoubleWord(0, l_scomWriteValue);
        l_ecmdRc |= l_maskData.setDoubleWord(0, l_mask);
        if (l_ecmdRc != ECMD_DBUF_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: fapiPutScomUnderMask test, error from ecmdDataBuffer setDoubleWord() - rc 0x%.8X", l_ecmdRc);
            l_rc.setEcmdError(l_ecmdRc);;
            break;
        }


        l_rc = fapiPutScomUnderMask(i_target.front(), l_addr, l_ScomData, l_maskData);
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
            l_rc.setEcmdError(l_ecmdRc);
            break;
        }

        l_rc = fapiPutScom(i_target.front(), l_addr, l_ScomData);
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
//  - Don't use i_target.front() (a processor) as a target. Set the target as one of the Centaurs.
//  - Enable this block of code and test the cfam access functions on the Centaur.

        // --------------------------------------------------------
        // 5. fapiGetCfamRegister test
        // --------------------------------------------------------
        ecmdDataBufferBase l_cfamData(32); // 32-bit cfam data holder
        uint32_t l_originalCfamData = 0;
        const uint32_t l_cfamAddr = 0x100A; // ChipID register
        l_rc = fapiGetCfamRegister(i_target.front(), l_cfamAddr, l_cfamData);
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
            l_rc.setEcmdError(l_ecmdRc);;
            break;
        }


        l_rc = fapiPutCfamRegister(i_target.front(), l_cfamAddr, l_cfamData);
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
            l_rc.setEcmdError(l_ecmdRc);;
            break;
        }

        l_rc = fapiModifyCfamRegister(i_target.front(), l_cfamAddr,
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
            l_rc.setEcmdError(l_ecmdRc);;
            break;
        }

        l_rc = fapiPutCfamRegister(i_target.front(), l_cfamAddr, l_cfamData);
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
        // 9. fapiHwpExecInitFile test
        // --------------------------------------------------------

        //Call Hwp to execute the sample initfile
        FAPI_EXEC_HWP(l_rc, fapiHwpExecInitFile, i_target, "sample.if");
        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            FAPI_ERR("hwpInitialTest: Error from fapiHwpExecInitFile");
            break;
        }
        else
        {
            FAPI_INF("hwpInitialTest: fapiHwpExecInitFile passed");
        }

    } while (0);

    return l_rc;
}


} // extern "C"
