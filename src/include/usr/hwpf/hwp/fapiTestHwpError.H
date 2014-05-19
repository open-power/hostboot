/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/fapiTestHwpError.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
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
