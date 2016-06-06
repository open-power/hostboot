/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_hwp_invoker.H $                    */
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
/**
 *  @file plat_hwp_invoker.H
 *
 *  @brief Defines the HostBoot HWP invoker macro and a function to convert a
 *         fapi::ReturnCode to an error log
 */

///
/// @file src/include/usr/hwpf/plat/plat_hwp_invoker.H
///
/// @brief Defines the HostBoot FAPI2 HWP invoker macro and a function to
/// convert a fapi2::ReturnCode to an error log
///
/// Note that platform code must provide the code.
///

#ifndef PLATHWPINVOKER_H_
#define PLATHWPINVOKER_H_

#include <return_code.H>
#include <plat_utils.H>

/**
 * @brief HWP Invoker macro
 *
 * This macro is called by HostBoot PLAT code to invoke a HW Procedure (HWP).
 * The caller must create any necessary fapi::Targets and pass them as
 * parameters. This macro simply calls the FAPI HWP executor macro and converts
 * the returned fapi::Return code to a HostBoot error log
 *
 * ERRHNDL    - errlHndl_t
 * FUNC       - HWP function name
 * _args_...  - Any additional arguments that the HWP requires
 */

#define FAPI_INVOKE_HWP(ERRHNDL, FUNC, _args_...) \
    {\
        fapi2::ReturnCode l_rc; \
        FAPI_EXEC_HWP(l_rc, FUNC, ##_args_); \
        ERRHNDL = fapi2::rcToErrl(l_rc);\
        if( ERRHNDL ) {\
            ERRHNDL->collectTrace(FAPI_IMP_TRACE_NAME,256);\
            ERRHNDL->collectTrace(FAPI_TRACE_NAME,384);\
        }\
    }

#endif // PLATHWPINVOKER_H_
