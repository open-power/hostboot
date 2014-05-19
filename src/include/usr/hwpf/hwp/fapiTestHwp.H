/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/fapiTestHwp.H $                      */
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
 *                          mjjones     10/17/2011  Added func pointer
 *                          camvanng    05/07/2012  Support for associated
 *                                                  attributes
 */

#ifndef FAPITESTHW_H_
#define FAPITESTHW_H_

#include <fapi.H>
#include <vector>

typedef fapi::ReturnCode (*hwpInitialTest_FP_t)(const std::vector<fapi::Target> &);

extern "C"
{

/**
 * @brief A simple HWP. Can easily be modified by HW dev team for test
 *
 * @param[in] i_target Reference to std::vector of targets
 *
 * @return ReturnCode
 */
fapi::ReturnCode hwpInitialTest(const std::vector<fapi::Target> & i_target);

}

#endif
