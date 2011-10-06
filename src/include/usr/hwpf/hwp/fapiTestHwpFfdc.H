//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/hwp/fapiTestHwpFfdc.H $
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
 *  @file fapiTestHwpFfdc.H
 *
 *  @brief Defines a simple test Hardware Procedure that collects FFDC data 
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     08/08/2011  Created.
 *
 */

#ifndef FAPITESTHWPFFDC_H_
#define FAPITESTHWPFFDC_H_

#include <fapi.H>

// HWPs are defined as C functions because platforms may wish to package them
// in linux shared libraries which are DL-Opened
extern "C"
{

/**
 * @brief Simple FFDC HWP that collects TestFfdc1 data
 *
 * @param[in]  i_target Reference to target (unused by this HWP)
 * @param[out] o_rc     Reference to ReturnCode that is updated with FFDC
 *
 * @return ReturnCode
 */
fapi::ReturnCode hwpTestFfdc1(const fapi::Target & i_target,
                              fapi::ReturnCode & o_rc);

} // extern "C"

#endif // FAPITESTHWPFFDC_H_
