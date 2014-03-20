/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/fapiTestHwpError.C $                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
/**
 *  @file fapiTestHwpError.C
 *
 *  @brief Implements a simple test Hardware Procedure that returns an error
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     08/08/2011  Created.
 *                          camvanng    09/06/2011  Added code to test
 *                                                  fapiLogError
 *                          mjjones     10/06/2011  Major updates due to new
 *                                                  ErrorInfo design
 *                          mjjones     10/17/2011  Moved AnalyzeError to new file
 *                          rjknight    09/28/2013  Added callout test for MBA
 *                                                  dimm callout support
 *                          whs         03/11/2014  Add FW traces to error logs
 *
 *
 *  HWP_IGNORE_VERSION_CHECK
 */

#include <fapiTestHwpError.H>

extern "C"
{

//******************************************************************************
// hwpTestError function
//******************************************************************************
fapi::ReturnCode hwpTestError(const fapi::Target & i_procTarget,
                              const fapi::Target & i_mbaTarget )
{
    FAPI_INF("hwpTestError: Start HWP");

    fapi::ReturnCode l_rc;

    // Test ability for FAPI to request FW traces added to error log
    FAPI_ERR("hwpTestError: Generating RC_TEST_COLLECT_TRACE");
    uint32_t  FFDC_VALUE = 0xBEF2;
    FAPI_SET_HWP_ERROR(l_rc, RC_TEST_COLLECT_TRACE);
    // Log the error
    fapiLogError(l_rc, fapi::FAPI_ERRL_SEV_PREDICTIVE, true);

    // Local data that needs to be captured as FFDC
    uint32_t l_ffdc = 0x12345678;
    ecmdDataBufferBase l_buf(65);
    l_buf.setBit(1);
    l_buf.setBit(64);

    FAPI_ERR("hwpTestError: Generating RC_TEST_ERROR_A");
    const fapi::Target & UNIT_TEST_CHIP_TARGET = i_procTarget;
    const fapi::Target & UNIT_TEST_MBA_TARGET = i_mbaTarget;
    uint32_t & UNIT_TEST_FFDC_DATA_INTEGER = l_ffdc;
    ecmdDataBufferBase & UNIT_TEST_FFDC_DATA_BUF = l_buf;
    FAPI_SET_HWP_ERROR(l_rc, RC_TEST_ERROR_A);

    // Log the error
    fapiLogError(l_rc, fapi::FAPI_ERRL_SEV_PREDICTIVE, true);

    // Check that the return code is set to success
    if (!l_rc.ok())
    {
        FAPI_ERR("Performing HWP: hwpTestError: rc is 0x%x, "
                 "expected success", static_cast<uint32_t>(l_rc));
    }

    FAPI_INF("Test calling out all DIMMs based on mba port 0");

    // all dimms on a specific port
    FAPI_ERR("Generating RC_TEST_DIMM_CALLOUT_MBA_A");
    uint8_t UNIT_TEST_MBA_PORT_NUMBER = 0x0;
    FAPI_SET_HWP_ERROR(l_rc, RC_TEST_DIMM_CALLOUT_MBA_A);
    fapiLogError( l_rc,fapi::FAPI_ERRL_SEV_PREDICTIVE, true );

    // specific dimm on a specific port
    FAPI_INF("Test calling out DIMM3 based on port and dimm number");

    UNIT_TEST_MBA_PORT_NUMBER = 0x1;
    uint8_t UNIT_TEST_DIMM_NUMBER = 0x01;

    FAPI_ERR("Generating RC_TEST_DIMM_CALLOUT_MBA_B");
    FAPI_SET_HWP_ERROR(l_rc, RC_TEST_DIMM_CALLOUT_MBA_B);
    fapiLogError( l_rc,fapi::FAPI_ERRL_SEV_PREDICTIVE, true );

    FAPI_INF("Test calling out all dimms of an mba");
    // all dimms on an mba target
    FAPI_ERR("Generating RC_TEST_DIMM_CALLOUT_MBA_C");
    FAPI_SET_HWP_ERROR(l_rc, RC_TEST_DIMM_CALLOUT_MBA_C);
    fapiLogError( l_rc,fapi::FAPI_ERRL_SEV_PREDICTIVE, true );

    // commented out due to ci test failing on deconfigured parts
    FAPI_INF("Test deconfigure all dimms of mba with port 0 specified");
    UNIT_TEST_MBA_PORT_NUMBER = 0x0;

    // deconfigure all dimms on port 0
    FAPI_ERR("Generating RC_TEST_DIMM_DECONFIGURE_MBA_A ");
    FAPI_SET_HWP_ERROR(l_rc,RC_TEST_DIMM_DECONFIGURE_MBA_A);
    fapiLogError( l_rc,fapi::FAPI_ERRL_SEV_PREDICTIVE, true );

    FAPI_INF("Test gard of DIMM2");
    // gard dimm 0 onn port 1
    UNIT_TEST_DIMM_NUMBER = 0x00;
    UNIT_TEST_MBA_PORT_NUMBER = 0x01;

    FAPI_ERR("Generating RC_TEST_DIMM_GARD_MBA_B ");
    FAPI_SET_HWP_ERROR(l_rc, RC_TEST_DIMM_GARD_MBA_B);
    fapiLogError( l_rc,fapi::FAPI_ERRL_SEV_PREDICTIVE, true );

    // Generate the same error again need to return an error
    // to make the test code happy
    FAPI_ERR("hwpTestError: Generating RC_TEST_ERROR_A again");
    FAPI_SET_HWP_ERROR(l_rc, RC_TEST_ERROR_A);

    FAPI_INF("hwpTestError: End HWP");
    return l_rc;
}

}
