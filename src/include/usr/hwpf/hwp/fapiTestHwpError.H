/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/fapiTestHwpError.H $                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
 *  @file fapiTestHwpError.H
 *
 *  @brief Defines a simple test Hardware Procedure that returns an error
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     08/08/2011  Created.
 *                          mjjones     10/17/2011  Added func pointer
 *                          rjknight    09/30/2013  Add 2nd target to fctn ptr
 */

#ifndef FAPITESTHWPERROR_H_
#define FAPITESTHWPERROR_H_

#include <fapi.H>

typedef fapi::ReturnCode (*hwpTestError_FP_t)(const fapi::Target &T1,
                                              const fapi::Target &T2);

extern "C"
{

/**
 * @brief Simple HWP that returns an error (RC_TEST_ERROR_A)
 *
 * @param[in] i_procTarget Reference to a processor target type
 * @param[in] i_mbaTarget  Reference to an mba target type
 *
 * @return ReturnCode
 */
 fapi::ReturnCode hwpTestError(const fapi::Target& i_procTarget,
                               const fapi::Target& i_mbaTarget);

}

#endif
