//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/fapiTestHwpAnalyzeError.C $
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
 *  @file fapiTestHwpAnalyzeError.C
 *
 *  @brief Implements a simple test Hardware Procedure that analyzes an error
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     10/17/2011  Created (moved from other file)
 */

#include <fapiTestHwpAnalyzeError.H>

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

    // Generate error
    const fapi::Target & MASTER_CHIP = i_target;
    uint32_t & FFDC_DATA_1 = l_ffdc;
    FAPI_SET_HWP_ERROR(l_rc, RC_TEST_ERROR_A);

    FAPI_INF("hwpTestAnalyzeError: End HWP");
    return l_rc;
}

}
