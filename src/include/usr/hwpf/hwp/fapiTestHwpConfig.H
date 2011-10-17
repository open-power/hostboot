//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/hwp/fapiTestHwpConfig.H $
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
 *  @file fapiTestHwpConfig.H
 *
 *  @brief Defines a Hardware Procedure that exercises the FAPI System Config
 *         Query functions.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     09/12/2011  Created.
 *                          mjjones     10/17/2011  Added func pointer
 */

#ifndef FAPITESTHWCONFIG_H_
#define FAPITESTHWCONFIG_H_

#include <fapi.H>

typedef fapi::ReturnCode (*hwpTestConfig_FP_t)(const fapi::Target &);

extern "C"
{

/**
 * @brief A simple HWP that exercises the FAPI System Config Query functions.
 *
 * @param[in] i_chip Reference to target processor chip
 *
 * @return ReturnCode
 */
fapi::ReturnCode hwpTestConfig(const fapi::Target & i_chip);

}

#endif
