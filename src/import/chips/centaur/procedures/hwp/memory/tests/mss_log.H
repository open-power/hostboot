/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/tests/mss_log.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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

///
/// @file mss_log.H
/// @brief Header for mss logging functionality
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 4
// *HWP Consumed by: CI

#ifndef   _MSS_LOG_H_
#define   _MSS_LOG_H_

namespace mss
{

///
/// @brief Logging Level enum for mss library
///
enum logging_level
{
    TRACE, ///< Logs at trace level
    DEBUG, ///< Logs at debug level
    INFO,  ///< Logs at info level
    WARN,  ///< Logs at warning level
    ERROR, ///< Logs an error
    FATAL, ///< Logs a fatal error and stops
};

///
/// @brief Log a string to the mss log logging system
/// @param[in] i_level Level to log messages
/// @param[in] i_msg message to log.
///
void log(const logging_level i_level, const std::string& i_msg);

///
/// @brief Log a string to the mss log logging system using a formatter
/// @param[in] i_level Level to log messages
/// @param[in] i_format_str is the string format @note see printf
/// @param[in] ... variable list of args to be written out
///
void logf(const logging_level i_level, const char* i_format_str, ...);

} /* ns mss */




#endif /* _MSS_LOG_H_ */
