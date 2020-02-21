/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/plat_error_scope.H $                   */
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
/**
 * @file plat_error_scope.H
 * @brief platform definitions which create a scope for automatic error handling
 */

#ifndef __FAPI2_PLAT_ERROR_SCOPE_BOOTLOADER__
#define __FAPI2_PLAT_ERROR_SCOPE_BOOTLOADER__

#define PLAT_FAPI_TRY_NO_TRACE( __operation__ )                         \
    if ((fapi2::current_err = (__operation__)) != fapi2::FAPI2_RC_SUCCESS) \
    {                                                                   \
        goto fapi_try_exit;                                             \
    }

#define PLAT_FAPI_TRY_TRACE( __operation__, ... )                       \
    PLAT_FAPI_TRY_NO_TRACE(__operation__)

///
/// @brief Assert a conditional is true.
/// If it is not, then fapi2::current_err will be set to a failing return code
/// as determined by the __ffdc__ return code passed in.
///
/// Note: see the generated file hwp_return_codes.H for
///       details on the __ffdc__ return codes
///
/// @param[in] __conditional__ the condition to assert
/// @param[in] __ffdc__ the return code to set fapi2::current_err to.
///
///
#define PLAT_FAPI_ASSERT( __conditional__, __ffdc__, ...)            \
    if (! (__conditional__))                                    \
    {                                                           \
        fapi2::current_err = __ffdc__;                          \
        goto fapi_try_exit;                                     \
    }


#endif // end __FAPI2_PLAT_ERROR_SCOPE_BOOTLOADER__
