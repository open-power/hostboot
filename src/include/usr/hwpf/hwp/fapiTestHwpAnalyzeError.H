//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/hwp/fapiTestHwpAnalyzeError.H $
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
 *  @file fapiTestHwpAnalyzeError.H
 *
 *  @brief Defines a simple test Hardware Procedure that returns an error
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     08/08/2011  Created. Moved from other file
 *
 */

#ifndef FAPITESTHWPANALYZEERROR_H_
#define FAPITESTHWPANALYZEERROR_H_

#include <fapi.H>

typedef fapi::ReturnCode (*hwpTestAnalyzeError_FP_t)(const fapi::Target &);

extern "C"
{

/**
 * @brief Simple HWP that analyzes an error and returns an error describing the
 *        problem (RC_TEST_ERROR_B)
 *
 * @param[in] i_target Reference to target (unused by HWP)
 *
 * @return ReturnCode
 */
fapi::ReturnCode hwpTestAnalyzeError(const fapi::Target & i_target);

}

#endif
