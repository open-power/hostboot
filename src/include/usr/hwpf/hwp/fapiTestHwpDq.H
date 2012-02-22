//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/hwp/fapiTestHwpDq.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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
 *  @file fapiTestHwpDq.H
 *
 *  @brief Test Hardware Procedure that exercises the bad DQ data
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     02/21/2012  Created
 */

#ifndef FAPITESTHWPDQ_H_
#define FAPITESTHWPDQ_H_

#include <fapi.H>

typedef fapi::ReturnCode (*fapiTestHwpDq_FP_t)(const fapi::Target &);

extern "C"
{

/**
 * @brief Test Hardware Procedure that exercises the bad DQ data
 *
 * @param[in] i_mba Reference to MBA chiplet
 *
 * @return ReturnCode
 */
fapi::ReturnCode fapiTestHwpDq(const fapi::Target & i_mba);

}

#endif
