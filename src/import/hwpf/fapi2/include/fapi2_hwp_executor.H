/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: hwpf/fapi2/include/fapi2_hwp_executor.H $                     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file fapi2_hwp_executor.H
///
/// @brief Defines the FAPI2 HWP Executor Macro.
///
/// The FAPI2 HWP Executor macro is called when a PLAT invoker function or a HWP
/// wants to execute a HWP.
///

#ifndef FAPI2HWPEXECUTOR_H_
#define FAPI2HWPEXECUTOR_H_

#include <hwp_executor.H>

/**
 * @brief HWP Executor macro
 *
 * This macro calls a PLAT macro which will do any platform specific work to
 * execute the HWP (e.g. dlopening a shared library)
 */
#define FAPI_EXEC_HWP(RC, FUNC, _args_...) \
    FAPI_PLAT_EXEC_HWP(RC, FUNC, ##_args_)

#endif // FAPI2HWPEXECUTOR_H_
