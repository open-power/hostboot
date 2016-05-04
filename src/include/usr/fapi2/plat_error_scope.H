/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_error_scope.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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

#ifndef __FAPI2_PLAT_ERROR_SCOPE__
#define __FAPI2_PLAT_ERROR_SCOPE__

/// @cond
#define PLAT_FAPI_TRY_NO_TRACE( __operation__ )                         \
    if ((fapi2::current_err = (__operation__)) != fapi2::FAPI2_RC_SUCCESS) \
    {                                                                   \
        goto fapi_try_exit;                                             \
    }

#define PLAT_FAPI_TRY_TRACE( __operation__, ... )                       \
    if ((fapi2::current_err = (__operation__)) != fapi2::FAPI2_RC_SUCCESS) \
    {                                                                   \
        FAPI_ERR(__VA_ARGS__);                                          \
        goto fapi_try_exit;                                             \
    }

///
/// @brief Assert a conditional is true.
/// If it is not, the FFDC gathering function is called and
/// the text in varargs is sent to the hostboot trace
/// as a FAPI_ERR trace.
/// fapi2::current_err will be set to a failing return code
/// as determined by the __ffdc__ class passed in.
///
/// Note: see the generated file hwp_ffdc_classes.H for
///       details on the __ffdc__ functions
///
/// @param[in] __conditional__ the condition to assert
/// @param[in] __ffdc__ the FFDC gathering function
/// @param[in] ... varargs, as input to FAPI_ERR
///
///
#define PLAT_FAPI_ASSERT( __conditional__, __ffdc__, ... )      \
    if (! (__conditional__))                                    \
    {                                                           \
        (__ffdc__).execute();                                   \
        FAPI_ERR(__VA_ARGS__);                                  \
        goto fapi_try_exit;                                     \
    }

///
/// @brief Assert a conditional is true.
/// If it is not, the FFDC gathering function is called, A
/// platform error is created and committed.
/// fapi2::current_err will be set to fapi2::FAPI2_RC_SUCCESS
/// and the text in varargs is sent to the hostboot trace as a
/// FAPI_ERR trace.
///
/// @param[in] __conditional__ the condition to assert
/// @param[in] __ffdc__ the FFDC gathering function
/// @param[in] ... varargs, as input to FAPI_ERR
///
/// @note: This assert does not cause a branch to the
///        fapi_try_exit label.
///
#define PLAT_FAPI_ASSERT_NOEXIT( __conditional__, __ffdc__, ... ) \
    if (! (__conditional__))                                    \
    {                                                           \
        __ffdc__.execute(                                       \
                fapi2::FAPI2_ERRL_SEV_UNDEFINED, true);         \
        fapi2::current_err =  fapi2::FAPI2_RC_SUCCESS;          \
        FAPI_ERR(__VA_ARGS__);                                  \
    }                                                           \

/// @endcond

#endif
