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
