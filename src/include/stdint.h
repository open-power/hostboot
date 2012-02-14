//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/stdint.h $
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
#ifndef __STDINT_H
#define __STDINT_H

#include <stddef.h>

typedef signed char 			int8_t;
typedef short int 		int16_t;
typedef int			int32_t;
typedef long int		int64_t;

typedef unsigned char 		uint8_t;
typedef unsigned short int 	uint16_t;
typedef unsigned int	 	uint32_t;
typedef unsigned long int 	uint64_t;

typedef uint64_t 		size_t;
typedef int64_t 		ssize_t;

typedef ssize_t                 ptrdiff_t;

#define UINT8_MAX	(255U)
#define UINT16_MAX	(65535U)
#define UINT32_MAX	(4294967295U)
#define UINT64_MAX	(18446744073709551615U)

#endif
