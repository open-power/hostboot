/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/hwas/hwasPlatTrace.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 *  @file hwas/hwasPlatTrace.H
 *
 *  @brief Defines platform interfaces and whatnot needed for trace in the
 *         HWAS common and platform specific functions
 */

#ifndef HWASPLATTRACE_H_
#define HWASPLATTRACE_H_

#include <trace/interface.H>
#include <errl/errlentry.H>

//******************************************************************************
// Trace descriptors that are defined in a C file
//******************************************************************************
namespace HWAS
{
    typedef trace_desc_t* HWAS_TD_t;
    extern HWAS_TD_t g_trac_dbg_hwas; // debug - fast
    extern HWAS_TD_t g_trac_imp_hwas; // important - slow
}

// Debug traces (go into fast trace buffer that can wrap often)
#define HWAS_DBG(_fmt_, _args_...) \
    TRACDCOMP(g_trac_dbg_hwas, TRACE_FILENAME _fmt_, ##_args_)

// Information traces (go into slow trace buffer that should not wrap often)
#define HWAS_INF(_fmt_, _args_...) \
    TRACFCOMP(g_trac_imp_hwas, TRACE_FILENAME _fmt_, ##_args_)

// Error traces (go into slow trace buffer that should not wrap often)
#define HWAS_ERR(_fmt_, _args_...) \
    TRACFCOMP(g_trac_imp_hwas, TRACE_FILENAME _fmt_, ##_args_)

#endif // HWASPLATTRACE_H_
