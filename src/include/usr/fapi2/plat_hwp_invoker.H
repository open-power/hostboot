/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_hwp_invoker.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
/// @brief Defines the HostBoot FAPI2 HWP invoker macro and a function to
/// convert a fapi2::ReturnCode to an error log
///
/// Note that platform code must provide the code.
///

#ifndef PLATHWPINVOKER_H_
#define PLATHWPINVOKER_H_

#include <return_code.H>
#include <hw_access_def.H>
#include "plat_utils.H"
#include <xscom/piberror.H>
#include <errl/errludstring.H>

namespace fapi2 {
/*
 * @brief Resets all HWP thread_local vars
 */
void hwpResetGlobals(void);
}

/**
 * @brief HWP Invoker macro
 *
 * This macro is called by HostBoot PLAT code to invoke a HW Procedure (HWP).
 * The caller must create any necessary fapi::Targets and pass them as
 * parameters. This macro simply calls the FAPI HWP executor macro and converts
 * the returned fapi::Return code to a HostBoot error log
 *
 * ERRHNDL    - local errlHndl_t
 * FUNC       - HWP function name
 * _args_...  - Any additional arguments that the HWP requires
 */

#define FAPI_INVOKE_HWP(ERRHNDL, FUNC, _args_...) \
    {\
        fapi2::hwpResetGlobals(); \
        fapi2::ReturnCode invoke_rc; \
        FAPI_EXEC_HWP(invoke_rc, FUNC, ##_args_); \
        ERRHNDL = fapi2::rcToErrl(invoke_rc);\
        if( ERRHNDL ) {\
            ERRHNDL->collectTrace(FAPI_IMP_TRACE_NAME,256);\
            ERRHNDL->collectTrace(FAPI_TRACE_NAME,384);\
            ERRORLOG::ErrlUserDetailsString(#FUNC).addToLog(ERRHNDL);\
        }\
        fapi2::hwpResetGlobals(); \
    }

/**
 * @brief HWP Invoker macro that returns the fapi RC
 *
 * This macro is called by HostBoot PLAT code to invoke a HW Procedure (HWP).
 * The caller must create any necessary fapi::Targets and pass them as
 * parameters. This macro simply calls the FAPI HWP executor macro and converts
 * the returned fapi::Return code to a HostBoot error log
 *
 * ERRHNDL    - local errlHndl_t
 * _RC        - local fapi2::ReturnCode
 * FUNC       - HWP function name
 * _args_...  - Any additional arguments that the HWP requires
 */

#define FAPI_INVOKE_HWP_RC(ERRHNDL, _RC, FUNC, _args_...) \
    {\
        fapi2::hwpResetGlobals(); \
        FAPI_EXEC_HWP(_RC, FUNC, ##_args_); \
        ERRHNDL = fapi2::rcToErrl(_RC);\
        if( ERRHNDL ) {\
            ERRHNDL->collectTrace(FAPI_IMP_TRACE_NAME,256);\
            ERRHNDL->collectTrace(FAPI_TRACE_NAME,384);\
        }\
        fapi2::hwpResetGlobals(); \
    }

/**
 * @brief Pseudo-HWP Invoker macro
 *
 * This macro is called by HostBoot PLAT code to invoke a HW Procedure (HWP)
 * that returns a ReturnCode
 *
 *  RETURN  - Local var to store the return value
 *  FUNC    - HWP function name
 * _args_...  - Any additional arguments that the HWP requires
 */
#define FAPI_CALL_HWP( RETURN, FUNC, _args_...) \
   {\
        fapi2::hwpResetGlobals(); \
        RETURN = FUNC(_args_); \
        fapi2::hwpResetGlobals(); \
   }

/**
 * @brief Pseudo-HWP Invoker macro
 *
 * This macro is called by HostBoot PLAT code to invoke a HW Procedure (HWP)
 * that does not return a ReturnCode
 *
 *  FUNC    - HWP function name
 * _args_...  - Any additional arguments that the HWP requires
 */
#define FAPI_CALL_HWP_NORETURN( FUNC, _args_...) \
   {\
        fapi2::hwpResetGlobals(); \
        FUNC(_args_); \
        fapi2::hwpResetGlobals(); \
   }

/* @brief Invoke a hardware procedure on each element of a container. If the
 *        hardware procedure fails, stop iterating and return the error.
 *
 * @param[in] i_hwp        Hardware procedure to invoke (can be a lambda)
 * @param[in] i_container  Container of elements
 * @param[out] o_fail_elem Optional pointer to element of the same type as
 *                         the container's elements. If the HWP fails and
 *                         o_fail_elem is not nullptr, the element that the
 *                         HWP failed on is assigned to it.
 */
template<typename F, typename Container, typename Element>
errlHndl_t hwp_for_each(F&& i_hwp, const Container& i_container, Element* o_fail_elem)
{
    errlHndl_t errl = nullptr;

    for (const auto& value : i_container)
    {
        FAPI_INVOKE_HWP(errl, i_hwp, { value });

        if (errl)
        {
            if (o_fail_elem)
            {
                *o_fail_elem = value;
            }

            break;
        }
    }

    return errl;
}

#endif // PLATHWPINVOKER_H_
