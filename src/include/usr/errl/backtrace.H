//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/errl/backtrace.H $
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
#ifndef __BACKTRACE_H
#define __BACKTRACE_H
/**
 *  @file backtrace.H
 *
 *  @brief  Backtrace support for errorlog classes.
 *  This header provides the interfaces for errorlog, or any other user
 *  code to gather backtraces for the current location in the code.
 *
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdint.h>
#include <errl/errltypes.H>
#include <vector>


namespace ERRORLOG
{

/**
* @brief This function will be called during errorlog creation and will
*       add an FFDC section that contains the addresses needed for
*       decoding the backtrace at a later time.  The later time would be
*       when error log details are printed.
*
* @param[out] i_addrVector - Vector of addresses collected.
*
* @return None.
*/
void collectBacktrace ( std::vector<uint64_t> & o_addrVector );


} // End namespace

#endif //__BACKTRACE_H
