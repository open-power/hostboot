/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/plat_trace.H $                         */
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
/// @file plat_trace.H
/// @brief Defines the FAPI2 trace macros.
///
/// Note that platform code must provide the implementation.
///
/// FAPI has provided a default implementation. Platform code must
/// provide an alternate implementation if needed.
///

#ifndef PLAT_TRACE_BOOTLOADER__
#define PLAT_TRACE_BOOTLOADER__

// @TODO RTC 249817 No fapi traces are enabled currently.

// Information traces (go into fast trace buffer that can wrap often)
#define FAPI_INF(_fmt_, _args_...) do {} while(0)

// Important traces (go into slow trace buffer that should not wrap often)
#define FAPI_IMP(_fmt_, _args_...) do {} while(0)

// Error traces (go into slow trace buffer that should not wrap often)
#define FAPI_ERR(_fmt_, _args_...) do {} while(0)

// Debug traces
#define FAPI_DBG(_fmt_, _args_...) do {} while(0)

// Scan traces
#define FAPI_SCAN(_fmt_, _args_...) do {} while(0)


#endif // PLAT_TRACE_BOOTLOADER__
