/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/fapiTestHwpAttr.H $                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
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
 *                          mjjones     10/17/2011  Added func pointer
 */

#ifndef FAPITESTHWPATTR_H_
#define FAPITESTHWPATTR_H_

#include <fapi.H>

typedef fapi::ReturnCode (*hwpTestAttributes_FP_t)();

extern "C"
{

/**
 * @brief HWP that exercises attributes
 *
 * @param[in] i_mbaTarget  Reference to MBA chiplet target
 * @param[in] i_procTarget Reference to processor chip target
 * @return ReturnCode
 */
fapi::ReturnCode hwpTestAttributes(fapi::Target & i_mbaTarget,
                                   fapi::Target & i_procTarget);

}

#endif
