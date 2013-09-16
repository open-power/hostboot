/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/plat/fapiPlatHwpInvoker.H $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
 *  @file fapiPlatHwpInvoker.H
 *
 *  @brief Defines the HostBoot HWP invoker macro and a function to convert a
 *         fapi::ReturnCode to an error log
 */

#ifndef FAPIPLATHWPINVOKER_H_
#define FAPIPLATHWPINVOKER_H_

#include <errl/errlentry.H>
#include <fapiReturnCode.H>
#include <fapiHwpExecutor.H>

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
    fapi::ReturnCode l_rc; \
    FAPI_EXEC_HWP(l_rc, FUNC, ##_args_); \
    ERRHNDL = fapi::fapiRcToErrl(l_rc); \
    }

namespace fapi
{

/**
 * @brief Converts a fapi::ReturnCode to a HostBoot PLAT error log
 *
 * @param[io] io_rc Reference to ReturnCode (set to success after function ends)
 * @param[in] i_sev Error log severity defaulted to unrecoverable
 *
 * @return errlHndl_t (NULL if Return Code contained success)
 */
errlHndl_t fapiRcToErrl(ReturnCode & io_rc,
                        ERRORLOG::errlSeverity_t i_sev =
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE);

}

#endif // FAPIPLATHWPINVOKER_H_
