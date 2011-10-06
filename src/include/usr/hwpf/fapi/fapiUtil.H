//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/fapi/fapiUtil.H $
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
 *  @file fapiUtil.H
 *
 *  @brief Defines utility functions that the platform code must implement.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/13/2011  Created.
 *                          camvanng    05/31/2011  Removed fapiOutputx macros
 *                          mjjones     06/30/2011  Removed #include
 *                          mjjones     07/05/2011  Removed rogue tab
 *                          camvanng    09/06/2011  Added fapiLogError
 *                          mjjones     09/14/2011  Prepended fapi to delay
 *                          mjjones     10/05/2011  Added fapiCheckType
 *
 */

#ifndef FAPIUTIL_H_
#define FAPIUTIL_H_

#include <stdint.h>
#include <stddef.h>
#include <fapi.H>

namespace fapi
{
/**
 * @brief Assert that an expression is true. Aborting the process if false.
 *
 * @note Implemented by platform code
 *
 * @param[in] i_expression If not true then process should be aborted
 */
void fapiAssert(bool i_expression);

/**
 * @brief Delay this thread. Hostboot will use the nanoseconds parameter
 * and make a syscall to nanosleep. While in the syscall, the hostboot
 * kernel will continue to consume CPU cycles as it looks for a runnable
 * task.  When the delay time expires, the task becomes runnable and will soon
 * return from the syscall.  Callers of delay() in the hostboot environment
 * will likely have to know the mHz clock speed they are running on and
 * compute a non-zero value for i_nanoSeconds. 
 * 
 * On the FSP, it was sometimes acceptable to just provide zero for the
 * sleep delay time, causing the task to yield its time slice. By the
 * time the calling task could run again, it was pretty certain enough
 * host cycles had past.  This is probably not acceptable in
 * the hostboot environment. Callers should calculate and provide a
 * sleep value in nanoseconds relative to host clock speed.  
 *
 * On FSP when VBU is the target, then the i_simCycles parameter will be
 * used instead.  The FSP needs to use the simdispatcher client/server
 * API and issue a command to the awan to advance the simulation the
 * specified number of cycles. 
 * 
 * @param[in] i_nanoSeconds    nanoseconds to sleep 
 * @param[in] i_simCycles      count of Awan cycles to advance
 * 
 * @return ReturnCode. Zero on success, else platform specified error.
 */
fapi::ReturnCode fapiDelay(uint64_t i_nanoSeconds, uint64_t i_simCycles);

/**
 * @brief Log an error.
 *
 * This function can be called by HWP to log an error.
 *
 * @note Implemented by platform code
 *
 * @param[io] Reference to ReturnCode (Any references to data and error
 *            target are removed and rc value is set to success after
 *            function ends.)
 *
 * Example usage:
 *     fapi::ReturnCode l_rc;
 *     FAPI_EXEC_HWP(l_rc, function1, i_target);
 *     if (!l_rc)
 *     {
 *         fapiLogError(l_rc);
 *     }
 *
 *     FAPI_EXEC_HWP(l_rc, function2, i_target)
 *     return rc;
 */
void fapiLogError(ReturnCode & io_rc);

/**  @brief This function answers the question, is scand tracing turned on?
 *   The implementation of this function is specific to the platform.
 *
 *   @returns Boolean indication
 */
bool platIsScanTraceEnabled();

/**  @brief Alter the state of scand tracing.
 *   The implementation of this function is specific to the platform.
 *
 *   @param[in] True to enable or false to disable scan trace.
 *   @return  void
 */
void platSetScanTrace( bool i_enable );

/**
 * @brief Check the type of a variable
 *
 * This function can be called to check that a variable type is as expected
 */
template<typename T>
void fapiCheckType(const T &) {}

}

#endif // FAPIUTIL_H_
