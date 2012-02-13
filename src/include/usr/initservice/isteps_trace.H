//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/initservice/isteps_trace.H $
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
#ifndef __INITSERVICE_ISTEPS_TRACE_H
#define __INITSERVICE_ISTEPS_TRACE_H

/**
 * @file    isteps_trace.H
 *
 *  Include the Isteps trace buffer pointer for all isteps
 *  This is initialized in istepdispatcher.C
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <trace/interface.H>

namespace ISTEPS_TRACE
{

extern trace_desc_t *g_trac_isteps_trace;

}   //  end namespace

#endif
