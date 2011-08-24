//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/fapi/fapiHwpExecutor.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 *  @file fapiHwpExecutor.H
 *
 *  @brief Defines the FAPI HWP Executor Macro.
 *
 *  The FAPI HWP Executor macro is called when a PLAT invoker function or a HWP
 *  wants to execute a HWP.
 */

#ifndef FAPIHWPEXECUTOR_H_
#define FAPIHWPEXECUTOR_H_

#include <fapiPlatHwpExecutor.H>

/**
 * @brief HWP Executor macro
 *
 * This macro calls a PLAT macro which will do any platform specific work to
 * execute the HWP (e.g. dlopening a shared library) and then calls a function
 * on the ReturnCode to store the error target if there is an error
 */
#define FAPI_EXEC_HWP(RC, FUNC, TARGET, _args_...) \
    FAPI_PLAT_EXEC_HWP(RC, FUNC, TARGET, ##_args_); \
    RC.setErrTarget(TARGET)

#endif // FAPIHWPEXECUTOR_H_
