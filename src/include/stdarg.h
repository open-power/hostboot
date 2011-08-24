//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/stdarg.h $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2010 - 2011
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
#ifndef __STDARG_H
#define __STDARG_H

#define va_list 	__builtin_va_list
#define va_start(a,b)	__builtin_va_start(a,b)
#define va_arg(a,b) 	__builtin_va_arg(a,b)
#define va_end(a)	__builtin_va_end(a)
#define va_copy(a,b)	__builtin_va_copy(a,b)

#endif
