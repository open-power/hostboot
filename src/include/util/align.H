//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/util/align.H $
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
#ifndef __UTIL_ALIGN_H
#define __UTIL_ALIGN_H

#include <limits.h>

#define ALIGN_4(u) ((u + 0x3ull) & ~0x3ull)
#define ALIGN_PAGE(u) ((u + (PAGESIZE-1)) & ~(PAGESIZE-1))

#endif
