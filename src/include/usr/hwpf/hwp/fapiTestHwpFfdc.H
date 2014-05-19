/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/fapiTestHwpFfdc.H $                  */
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
 *  @file fapiTestHwpFfdc.H
 *
 *  @brief Defines a simple test Hardware Procedure that collects FFDC data 
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     08/08/2011  Created.
 *                          mjjones     10/17/2011  Added func pointer
 */

#ifndef FAPITESTHWPFFDC_H_
#define FAPITESTHWPFFDC_H_

#include <fapi.H>

typedef fapi::ReturnCode (*hwpTestFfdc1_FP_t)(const fapi::Target &, fapi::ReturnCode &);

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

}

#endif
