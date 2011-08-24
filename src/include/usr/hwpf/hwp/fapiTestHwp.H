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
 *
 */

#ifndef FAPITESTHWPROC_H_
#define FAPITESTHWPROC_H_

#include <fapi.H>

// HWPs are defined as C functions because platforms may wish to package them
// in linux shared libraries which are DL-Opened
extern "C"
{

/**
 * @brief A simple HWP. Can easily be modified by HW dev team for test
 *
 * @param[in] i_chip Reference to target chip
 *
 * @return ReturnCode
 */
fapi::ReturnCode hwpInitialTest(const fapi::Target & i_chip);



} // extern "C"

#endif // FAPITESTHWPROC_H_
