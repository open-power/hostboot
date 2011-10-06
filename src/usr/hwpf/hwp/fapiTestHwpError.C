//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/fapiTestHwpError.C $
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
 *
 */

#include <fapiTestHwpError.H>

extern "C"
{

//******************************************************************************
// hwpTestAnalyzeError function
//******************************************************************************
fapi::ReturnCode hwpTestAnalyzeError(const fapi::Target & i_target)
{
    FAPI_INF("hwpTestAnalyzeError: Start HWP (analysis HWP)");

    // This HWP analyses an error condition to decide what the error actually is
    // In real life, this HWP may look at chip error registers
    fapi::ReturnCode l_rc;

    // Local FFDC that needs to be captured
    uint32_t l_ffdc = 0x12345678;

    // Analysis reveals that the error is RC_TEST_ERROR_A
    FAPI_ERR("hwpTestAnalyzeError: Generating RC_TEST_ERROR_A");

    const fapi::Target & MASTER_CHIP = i_target;
    uint32_t & FFDC_DATA_1 = l_ffdc;
    FAPI_SET_HWP_ERROR(l_rc, RC_TEST_ERROR_A);

    FAPI_INF("hwpTestAnalyzeError: End HWP");
    return l_rc;
}

//******************************************************************************
// hwpTestError function
//******************************************************************************
fapi::ReturnCode hwpTestError(const fapi::Target & i_target)
{
    FAPI_INF("hwpTestError: Start HWP");

    fapi::ReturnCode l_rc;

    // Error RC_TEST_ERROR_B encountered, the error information requests that
    // hwpTestAnalyzeError be called to analyze the error condition
    FAPI_ERR("hwpTestError: Generating RC_TEST_ERROR_B");
    const fapi::Target & MASTER_CHIP = i_target;
    FAPI_SET_HWP_ERROR(l_rc, RC_TEST_ERROR_B);

    // Log the error
    fapiLogError(l_rc);

    // Check that the return code is set to success
    if (!l_rc.ok())
    {
        FAPI_ERR("Performing HWP: hwpTestError: rc is 0x%x, " \
                 "expected success", static_cast<uint32_t>(l_rc));
    }

    // Reset the return code
    FAPI_ERR("hwpTestError: Generating RC_TEST_ERROR_B");
    FAPI_SET_HWP_ERROR(l_rc, RC_TEST_ERROR_B);

    FAPI_INF("hwpTestError: End HWP");
    return l_rc;
}

} // extern "C"
