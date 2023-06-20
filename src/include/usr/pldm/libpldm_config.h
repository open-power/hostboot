/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/libpldm_config.h $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
 *  @file Controls which libpldm functions are allowed to compile.
 *     Currently, Hostboot uses all of the stable, testing, and deprecated
 *     APIs to compile the libpldm code.  By release time, Hostboot should
 *     attempt to use just stable APIs, if possible.
 */

#ifndef LIBPLDM_CONFIG_H

// To prevent compiling any of these interfaces add:
//     __attribute__((error("<type> APIs are not allowed")))
// where <type> is one of Stable | Testing | Deprecated

#define LIBPLDM_ABI_STABLE
#define LIBPLDM_ABI_TESTING
#define LIBPLDM_ABI_DEPRECATED

#endif // LIBPLDM_CONFIG_H
