/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/backtrace.H $                            */
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
#ifndef __BACKTRACE_H
#define __BACKTRACE_H
/**
 *  @file backtrace.H
 *
 *  @brief  Backtrace support for errorlog classes.
 *  This header provides the interfaces for errorlog, or any other user
 *  code to gather backtraces for the current location in the code.
 *
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdint.h>
#include <vector>


namespace ERRORLOG
{

/**
* @brief This function will be called during errorlog creation and will
*       add an FFDC section that contains the addresses needed for
*       decoding the backtrace at a later time.  The later time would be
*       when error log details are printed.
*
* @param[out] i_addrVector - Vector of addresses collected.
*
* @return None.
*/
void collectBacktrace ( std::vector<uint64_t> & o_addrVector );


} // End namespace

#endif //__BACKTRACE_H
