//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/HWPs/dmi_training/fapi_sbe_common.h $
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
#ifndef __FAPI_SBE_COMMON_H
#define __FAPI_SBE_COMMON_H

// $Id: fapi_sbe_common.h,v 1.1 2011/07/06 04:06:49 bcbrock Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/fapi_sbe_common.h,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME  :               Email:

/// \file fapi_sbe_common.h
/// \brief Definitions common to FAPI and SBE procedures
///
/// Several preprocessor macros are required to have different definitions in
/// traditional C, C++ and SBE assembly procedures.  These common forms are
/// collected here.

#ifdef __ASSEMBLER__

#define CONST_UINT8_T(name, expr) .set name, (expr)
#define CONST_UINT32_T(name, expr) .set name, (expr)
#define CONST_UINT64_T(name, expr) .set name, (expr)

#define ULL(x) x

#else 

#include <stdint.h>

#define CONST_UINT8_T(name, expr) const uint8_t name = (expr);
#define CONST_UINT32_T(name, expr) const uint32_t name = (expr);
#define CONST_UINT64_T(name, expr) const uint64_t name = (expr);

#define ULL(x) x##ull

#endif  // __ASSEMBLER__

#endif  // __FAPI_SBE_COMMON_H
