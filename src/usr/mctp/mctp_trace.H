/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/mctp_trace.H $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
#include <stdio.h>
#include <trace/interface.H>

/**
 * @file  mctp_trace.H
 * @brief Declaration of the function to be supplied for the libmctp core
 *        code's trace logic.
 */

extern trace_desc_t* g_trac_mctp;

/**
 * @brief Provide interface compatible with mctp core's trace hook which will
 *        print the string using Hostboot's TRACFCOMP interface. The max size
 *        allocated to the formatted string is 180 bytes which includes a
 *        null-terminator and any remaining bytes will be ignored.
 *
 * @param[in] level The trace level, we only print traces level MCTP_LOG_WARNING
 *                  or MCTP_LOG_ERR
 * @param[in] fmt   Format string
 * @param[in] args  Arguments for the format string
 *
 */
void mctp_log_fn(int level, const char * fmt, va_list args);