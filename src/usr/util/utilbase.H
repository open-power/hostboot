//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/util/utilbase.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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

#ifndef __UTIL_UTILBASE_H
#define __UTIL_UTILBASE_H

#include <trace/interface.H>

namespace Util
{
    extern trace_desc_t* g_util_trace;
};

#define UTIL_DT(...)    TRACDCOMP( Util::g_util_trace, __VA_ARGS__ )
#define UTIL_FT(...)    TRACFCOMP( Util::g_util_trace, __VA_ARGS__ )

#define UTIL_BOOL_ALPHA(x) ((x) ? "TRUE" : "FALSE")

#endif
