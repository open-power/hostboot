//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/hwp/fapiTestHwp.H $
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
 *  @file fapiTestHwp.H
 *
 *  @brief Defines a simple test Hardware Procedure
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/21/2011  Created.
 *                          mjjones     06/28/2011  Updated comment
 *                          mjjones     08/11/2011  Removed Clock HWP
 *                          mjjones     10/17/2011  Added func pointer
 *                          camvanng    05/07/2012  Support for associated
 *                                                  attributes
 */

#ifndef FAPITESTHW_H_
#define FAPITESTHW_H_

#include <fapi.H>
#include <vector>

typedef fapi::ReturnCode (*hwpInitialTest_FP_t)(const std::vector<fapi::Target> &);

extern "C"
{

/**
 * @brief A simple HWP. Can easily be modified by HW dev team for test
 *
 * @param[in] i_target Reference to std::vector of targets
 *
 * @return ReturnCode
 */
fapi::ReturnCode hwpInitialTest(const std::vector<fapi::Target> & i_target);

}

#endif
