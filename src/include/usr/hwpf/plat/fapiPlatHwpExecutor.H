/**
 *  @file fapiPlatHwpExecutor.H
 *
 *  @brief Defines the FAPI PLAT HWP Executor Macro.
 *
 *  The PLAT HWP Executor macro is called by the FAPI HWP Executor macro when a
 *  PLAT invoker function or a HWP wants to execute a HWP. Each platform can
 *  modify the macro to do any platform specific work to execute the HWP (e.g.
 *  dlopening a shared library)
 */

#ifndef FAPIPLATHWPEXECUTOR_H_
#define FAPIPLATHWPEXECUTOR_H_

#include <fapiTestHwp.H>
#include <fapiTestHwpError.H>
#include <fapiTestHwpFfdc.H>

/**
 * @brief HWP Executor macro
 *
 * By default, this macro just calls the HWP directly. If this cannot be done
 * then the platform needs to modify
 */
#define FAPI_PLAT_EXEC_HWP(RC, FUNC, TARGET, _args_...) \
    RC = FUNC(TARGET, ##_args_)

#endif // FAPIPLATHWPEXECUTOR_H_
