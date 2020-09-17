/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/test/rcExpLog.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
 * @file  rcExpLog.H
 *
 * @brief These procedures provide fapi2 return codes with desired data to
 *        support testing from expErrlTest
 */
#ifndef _RC_EXPLOG_H_
#define _RC_EXPLOG_H_

#include <fapi2.H>


/**
 * @brief Creates a test RC with added Explorer log trace data
 * @param i_ocmb_target - Explorer target
 * @param i_active_log_size - maximum size of active (RAM) data to add
 * @param i_saved_log_A_size - maximum size of saved image A (SPI flash) data to add
 * @param i_saved_log_B_size - maximum size of saved image B (SPI flash) data to add
 * @return ReturnCode with added error log data
 */
fapi2::ReturnCode exp_error_rc(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
               const uint32_t i_active_log_size,
               const uint32_t i_saved_log_A_size,
               const uint32_t i_saved_log_B_size);

#endif
