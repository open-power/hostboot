/**
 *  @file fapiPlatHwpExecutor.H
 *
 *  @brief Defines the FAPI HWP Executor Macro.
 *
 *  The HWP Executor macro is called when a PLAT invoker function or a HWP wants
 *  to execute a HWP. Each platform can modify the macro to do any platform
 *  specific work to execute the HWP (e.g. dlopening a shared library)
 */

#ifndef FAPIPLATHWPEXECUTOR_H_
#define FAPIPLATHWPEXECUTOR_H_

/**
 * @brief HWP Executor macro
 *
 * By default, this macro just calls the HWP directly. If this cannot be done
 * then the platform needs to modify
 */
#define FAPI_EXEC_HWP(RC, FUNC, _args_...) RC = FUNC(_args_)

#endif // FAPIPLATHWPEXECUTOR_H_
