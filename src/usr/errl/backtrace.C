//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/errl/backtrace.C $
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
 *  @file backtrace.C
 *
 *  @brief Provide backtrace support to the errorlog classes.
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <trace/interface.H>
#include <errl/backtrace.H>
#include <vector>

#include <kernel/console.H>

namespace ERRORLOG
{

// ------------------------------------------------------------------
// collectBacktrace
// ------------------------------------------------------------------
void collectBacktrace ( std::vector<uint64_t> & o_addrVector )
{
    o_addrVector.clear();

    uint64_t* frame = static_cast<uint64_t*>(framePointer());
    bool first = true;
    while (frame != NULL)
    {
        if ((0 != *frame) && (!first))
        {
            o_addrVector.push_back( frame[2] );
        }

        frame = reinterpret_cast<uint64_t*>(*frame);
        first = false;
    }
} // End collectBacktrace


} // End ERRORLOG namespace

