/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_trace.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file plat_trace.H
/// @brief Defines the FAPI2 trace macros.
///
/// Note that platform code must provide the implementation.
///
/// FAPI has provided a default implementation. Platform code must
/// provide an alternate implementation if needed.
///

#ifndef PLAT_TRACE_H_
#define PLAT_TRACE_H_

// Use the same macro from FAPI1
#include <fapiPlatTrace.H>

namespace fapi2
{
  static const uint32_t MAX_ECMD_STRING_LEN = 64;
}
#endif // PLAT_TRACE_H_
