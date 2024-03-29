/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/fapi2.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
/// @file fapi2.H
/// @brief top level header for fapi2
///

#ifndef __FAPI2_TOP_LEVEL__
#define __FAPI2_TOP_LEVEL__

#include <target.H>
#include <return_code.H>
#include <buffer.H>
#include <hw_access.H>
#include <utils.H>
#include <plat_trace.H>

// In turn includes the needed generated headers (hwp_ffd_classes, etc.)
#include <error_scope.H>

#include <fapi2_hwp_executor.H>
#include <fapi2_attribute_service.H>

// Not supported by Hostboot Bootloader
#ifndef PLAT_EC_FEATURE_NOT_SUPPORTED
    #include <fapi2_chip_ec_feature.H>
#endif

#include <mvpd_access.H>

// Block of headers not currently in fapi2
#ifdef FAPI2_MISSING_HEADERS
    #include <mbvpdAccess.H>
#endif

#endif // __FAPI2_TOP_LEVEL__
