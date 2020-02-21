/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/plat_utils.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file plat_utils.H
///
/// @brief FAPI2 utility functions
///
/// Note that platform code must provide the implementation.
///

#ifndef PLAT_UTILS_BOOTLOADER_
#define PLAT_UTILS_BOOTLOADER_

#include <plat_types.H>

namespace fapi2
{

/// EKB code requires this to be defined by platform code.
/// This allows code to use the is_platform<>() template function
/// to replace any #ifdefs that might have been used to conditionally
/// compile platform specific code.  See plat_types.H for a list
/// of possible platforms.
static const PlatformType PLATFORM = PLAT_HOSTBOOT_BOOTLOADER;

///
///  @brief This function answers the question, is scand tracing turned on?
///  The implementation of this function is specific to the platform.
///
///  @returns Boolean indicates whether the SCAN trace is enabled
///
bool platIsScanTraceEnabled();

} // End namespace fapi2


#endif // PLAT_UTILS_BOOTLOADER_
