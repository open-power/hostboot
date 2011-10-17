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
 *                          mjjones     10/17/2011  Moved AnalyzeError to new file
 *
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

    // Generate the same error again
    FAPI_ERR("hwpTestError: Generating RC_TEST_ERROR_B");
    FAPI_SET_HWP_ERROR(l_rc, RC_TEST_ERROR_B);

    FAPI_INF("hwpTestError: End HWP");
    return l_rc;
}

}
