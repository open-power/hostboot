//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/endian.h $
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
#ifndef __ENDIAN_H
#define __ENDIAN_H

#define __LITTLE_ENDIAN (1234)
#define __BIG_ENDIAN    (4321)

#define __BYTE_ORDER __BIG_ENDIAN

#define __swap16(x) \
    ((((x) & 0xFF00) >> 8) | \
     (((x) & 0x00FF) << 8))

#if __BYTE_ORDER == __BIG_ENDIAN
// Big Endian system
#define htobe16(x) (x)
#define htole16(x) __swap16(x)
#define be16toh(x) (x)
#define le16toh(x) __swap16(x)

#define htobe32(x) (x)
#define htole32(x) __builtin_bswap32(x)
#define be32toh(x) (x)
#define le32toh(x) __builtin_bswap32(x)

#define htobe64(x) (x)
#define htole64(x) __builtin_bswap64(x)
#define be64toh(x) (x)
#define le64toh(x) __builtin_bswap64(x)
#else
// Little Endian system
#define htobe16(x) __swap16(x)
#define htole16(x) (x)
#define be16toh(x) __swap16(x)
#define le16toh(x) (x)

#define htobe32(x) __builtin_bswap32(x)
#define htole32(x) (x)
#define be32toh(x) __builtin_bswap32(x)
#define le32toh(x) (x)

#define htobe64(x) __builtin_bswap64(x)
#define htole64(x) (x)
#define be64toh(x) __builtin_bswap64(x)
#define le64toh(x) (x)
#endif

#endif
