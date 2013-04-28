/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/tod_init/TodTrace.H $                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#ifndef TODTRACE_H
#define TODTRACE_H

#include <tracinterface.H>

namespace TOD
{

extern trace_desc_t * g_trac_tod;

// field traces -------------------

#define TOD_TRAC(args...)  TRACFCOMP(TOD::g_trac_tod, args)
#define TOD_ENTER(args...) TRACFCOMP(TOD::g_trac_tod, ENTER_MRK"" args)
#define TOD_EXIT(args...)  TRACFCOMP(TOD::g_trac_tod, EXIT_MRK"" args)
#define TOD_ERR(args...)   TRACFCOMP(TOD::g_trac_tod, ERR_MRK"" args)
#define TOD_INF(args...)   TRACFCOMP(TOD::g_trac_tod, INFO_MRK"" args)

// debug traces -------------------

#define TOD_DTRAC(args...)  TRACDCOMP(TOD::g_trac_tod, args)
#define TOD_DENTER(args...) TRACDCOMP(TOD::g_trac_tod, ENTER_MRK"" args)
#define TOD_DEXIT(args...)  TRACDCOMP(TOD::g_trac_tod, EXIT_MRK"" args)

}

#endif

