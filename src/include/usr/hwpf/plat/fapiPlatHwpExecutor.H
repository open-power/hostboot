/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/plat/fapiPlatHwpExecutor.H $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
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
#include <fapiTestHwpConfig.H>
#include <fapiTestHwpAttr.H>
#include <fapiTestHwpDq.H>
#include <dimmBadDqBitmapAccessHwp.H>

/**
 * @brief HWP Executor macro
 *
 * Call the HWP directly.
 */
#define FAPI_PLAT_EXEC_HWP(RC, FUNC, _args_...) \
    RC = FUNC(_args_)

#endif // FAPIPLATHWPEXECUTOR_H_
