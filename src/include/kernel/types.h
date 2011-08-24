//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/types.h $
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
#ifndef __KERNEL_TYPES_H
#define __KNERLE_TYPES_H

#include <stdint.h>

typedef uint16_t 	tid_t;	// This is 16-bit for the VMM mapping of 
				// stacks.  See VmmManager.
struct task_t;

typedef uint64_t	cpuid_t;
struct cpu_t;

#endif
