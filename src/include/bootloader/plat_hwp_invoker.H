/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/plat_hwp_invoker.H $                   */
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
/**
 *  @file plat_hwp_invoker.H
 *
 *  @brief Defines the Bootloader HWP invoker macro
 */

///
/// @brief Defines the Bootloader FAPI2 HWP invoker macro
///
/// Note that platform code must provide the code.
///

#ifndef PLAT_HWP_INVOKER_BOOTLOADER
#define PLAT_HWP_INVOKER_BOOTLOADER

namespace fapi2 {
/*
 * @brief Resets all HWP thread_local vars
 */
void hwpResetGlobals(void);
}

/**
 * @brief Pseudo-HWP Invoker macro
 *
 * This macro is called by Bootloader PLAT code to invoke a HW Procedure (HWP)
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
 * This macro is called by Bootloader PLAT code to invoke a HW Procedure (HWP)
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


#endif // PLAT_HWP_INVOKER_BOOTLOADER
