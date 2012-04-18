//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/targeting/trace.H $
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

#ifndef __TARGETING_COMMON_TRACE_H
#define __TARGETING_COMMON_TRACE_H

/**
 *  @file targeting/common/trace.H
 *
 *  @brief Targeting related trace macros.  Callers of these macros must
 *      define TARG_NAMESPACE, TARG_CLASS, and TARG_FN as appropriate
 */

//******************************************************************************
// Includes
//******************************************************************************

// Other includes
#include <targeting/adapters/traceadapter.H>

#define TARG_LOC TARG_NAMESPACE TARG_CLASS TARG_FN ": "

#define TARG_ERR_LOC ERR_MRK " " TARG_LOC

#define TARG_TAG "[TARG]"
#define TARG_ENTER(args...) \
    TRACFCOMP(TARGETING::g_trac_targeting,TARG_TAG " " \
        ENTER_MRK " " TARG_NAMESPACE \
        TARG_CLASS TARG_FN " " args)

#define TARG_EXIT(args...) \
    TRACFCOMP(TARGETING::g_trac_targeting,TARG_TAG " " \
        EXIT_MRK " " TARG_NAMESPACE \
        TARG_CLASS TARG_FN " " args)

#define TARG_ERR(args...) \
    TRACFCOMP(TARGETING::g_trac_targeting,TARG_TAG " " ERR_MRK " " args)

#define TARG_INF(args...) \
    TRACFCOMP(TARGETING::g_trac_targeting,TARG_TAG " " INFO_MRK " " args)

#define TARG_BIN(args...) \
    TRACFBIN(TARGETING::g_trac_targeting,TARG_TAG " " args)

#endif // __TARGETING_COMMON_TRACE_H
