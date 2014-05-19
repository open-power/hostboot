/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/fapiTestHwpConfig.H $                */
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
