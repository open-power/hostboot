//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/hwp/fapiTestHwpAttr.H $
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
 *  @file fapiTestHwpAttr.H
 *
 *  @brief Defines a test Hardware Procedure that exercises the test attributes
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     06/30/2011  Created.
 *                          mjjones     10/07/2011  Removed target param
 */

#ifndef FAPITESTHWPATTR_H_
#define FAPITESTHWPATTR_H_

#include <fapi.H>

// HWPs are defined as C functions because platforms may wish to package them
// in linux shared libraries which are DL-Opened
extern "C"
{

/**
 * @brief HWP that exercises attributes
 *
 * @return ReturnCode
 */
fapi::ReturnCode hwpTestAttributes();

} // extern "C"

#endif // FAPITESTHWPATTR_H_
