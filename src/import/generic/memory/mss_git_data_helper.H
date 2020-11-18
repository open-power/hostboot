/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/mss_git_data_helper.H $             */
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
///
/// @file mss_git_data_helper.H
/// @brief Helper file to print out the git data
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_GIT_DATA_HELPER_
#define _MSS_GIT_DATA_HELPER_

#ifndef __HOSTBOOT_MODULE
    #include <generic/memory/mss_git_data.H>
#endif

namespace mss
{

///
/// @brief Prints out the git commit data
/// @pram[in] i_print additional print information to be added to the print statement
///
inline void display_git_commit_info(const char* i_print)
{
#ifndef __HOSTBOOT_MODULE
    FAPI_INF("%s Git commit ID: %s", i_print, GIT_COMMIT_ID.c_str());
#endif
}

} // ns mss

#endif
