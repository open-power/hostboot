/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/fapi2_subroutine_executor.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file fapi2_subroutine_executor.H
///
/// @brief Defines the FAPI2 Subroutine Executor Macro.
///
/// The FAPI2 Subroutine Executor macro is called to execute a chip-op
/// or subroutine.
///

#ifndef FAPI2SUBEXECUTOR_H_
#define FAPI2SUBEXECUTOR_H_

#include <subroutine_executor.H>

/**
 * @brief Subroutine Executor macro
 *
 * This macro calls a PLAT macro which will do any platform specific work to
 * execute the Subroutine (e.g. dlopening a shared library)
 */
#define FAPI_CALL_SUBROUTINE(RC, FUNC, _args_...) \
    FAPI_PLAT_CALL_SUBROUTINE(RC, FUNC, ##_args_)

#endif // FAPI2SUBEXECUTOR_H_
