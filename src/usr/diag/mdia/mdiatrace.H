//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/mdia/mdiatrace.H $
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
#ifndef __MDIA_MDIATRACE_H
#define __MDIA_MDIATRACE_H

/**
 * @file mdiatrace.H
 * @brief mdia trace macros
 */

#include <trace/interface.H>

namespace MDIA
{

extern trace_desc_t * fastTd;
extern trace_desc_t * slowTd;

}

#define MDIA_DBG( _fmt_, _args_...) TRACDCOMP( MDIA::fastTd, INFO_MRK""_fmt_, ##_args_)
#define MDIA_FAST( _fmt_, _args_...) TRACFCOMP( MDIA::fastTd, INFO_MRK""_fmt_, ##_args_)
#define MDIA_SLOW( _fmt_, _args_...) TRACFCOMP( MDIA::slowTd, INFO_MRK""_fmt_, ##_args_)
#define MDIA_ERR( _fmt_, _args_...) TRACFCOMP( MDIA::slowTd, ERR_MRK""_fmt_, ##_args_)

#endif
