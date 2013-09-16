/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/fapiTestHwpError.C $                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
fapi::ReturnCode hwpTestError(const fapi::Target & i_target)
{
    FAPI_INF("hwpTestError: Start HWP");

    fapi::ReturnCode l_rc;

    // Local data that needs to be captured as FFDC
    uint32_t l_ffdc = 0x12345678;
    ecmdDataBufferBase l_buf(65);
    l_buf.setBit(1);
    l_buf.setBit(64);

    FAPI_ERR("hwpTestError: Generating RC_TEST_ERROR_A");
    const fapi::Target & UNIT_TEST_FFDC_MASTER_CHIP_TARGET = i_target;
    uint32_t & UNIT_TEST_FFDC_DATA_INTEGER = l_ffdc;
    ecmdDataBufferBase & UNIT_TEST_FFDC_DATA_BUF = l_buf;
    FAPI_SET_HWP_ERROR(l_rc, RC_TEST_ERROR_A);

    // Log the error
    fapiLogError(l_rc, fapi::FAPI_ERRL_SEV_PREDICTIVE);

    // Check that the return code is set to success
    if (!l_rc.ok())
    {
        FAPI_ERR("Performing HWP: hwpTestError: rc is 0x%x, " \
                 "expected success", static_cast<uint32_t>(l_rc));
    }

    // Generate the same error again
    FAPI_ERR("hwpTestError: Generating RC_TEST_ERROR_A again");
    FAPI_SET_HWP_ERROR(l_rc, RC_TEST_ERROR_A);

    FAPI_INF("hwpTestError: End HWP");
    return l_rc;
}

}
