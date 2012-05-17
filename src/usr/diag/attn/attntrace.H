//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/attn/attntrace.H $
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
#ifndef __ATTN_ATTNTRACE_H
#define __ATTN_ATTNTRACE_H

/**
 * @file attntrace.H
 *
 * @brief HBATTN trace macros.
 */

#include <trace/interface.H>

namespace ATTN
{

extern trace_desc_t * fastTd;
extern trace_desc_t * slowTd;

}

#define ATTN_DBG( _fmt_, _args_...) TRACDCOMP( ATTN::fastTd, INFO_MRK""_fmt_, ##_args_)
#define ATTN_FAST( _fmt_, _args_...) TRACFCOMP( ATTN::fastTd, INFO_MRK""_fmt_, ##_args_)
#define ATTN_SLOW( _fmt_, _args_...) TRACFCOMP( ATTN::slowTd, INFO_MRK""_fmt_, ##_args_)
#define ATTN_ERR( _fmt_, _args_...) TRACFCOMP( ATTN::slowTd, ERR_MRK""_fmt_, ##_args_)

#endif
