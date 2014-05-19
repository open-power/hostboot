/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/fapiTestHwpDq.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
