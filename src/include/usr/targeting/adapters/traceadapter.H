//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/targeting/adapters/traceadapter.H $
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

#ifndef __TARGETING_TRACEADAPTER_H
#define __TARGETING_TRACEADAPTER_H

/**
 *  @file targeting/adapters/traceadapter.H
 *
 *  @brief Platform specific targeting trace macro support
 */

//******************************************************************************
// Includes
//******************************************************************************

// Other Components
#include <trace/interface.H>

// Give callers access to the trace buffer
namespace TARGETING
{

/**
 *  @brief Map common trace type to platform specific trace type
 */
typedef trace_desc_t* TARG_TD_t;

/**
 *  @brief Export trace descriptor
 */
extern TARG_TD_t g_trac_targeting;

} // End namespace TARGETING

#endif // __TARGETING_TRACEADAPTER_H
