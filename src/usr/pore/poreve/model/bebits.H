//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pore/poreve/model/bebits.H $
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
#ifndef __VSBE_BEBITS_H
#define __VSBE_BEBITS_H

// $Id: bebits.H,v 1.3 2011/06/30 03:34:58 bcbrock Exp $

/// \file bebits.H
/// \brief Bit manipulation for Big-Endian data


/// A bit mask for a range of bits in a big-endian uint64_t
#define BE64_MASK(begin, end) \
    ((0xffffffffffffffffull >> (64 - ((end) - (begin) + 1))) << (63 - (end)))

/// A single bit mask for a big-endian uint64_t
#define BE64_BIT(n) (BE64_MASK((n), (n)))

/// Extract an unsigned field from a uint64_t
#define BE64_GET_FIELD(x, begin, end) \
    (((x) & BE64_MASK((begin), (end))) >> (63 - (end)))

/// Update an unsigned field in a uint64_t from a right-justified uint64_t value
#define BE64_SET_FIELD(x, begin, end, val)                      \
    ((((val) << (63 - (end))) &  BE64_MASK((begin), (end))) |   \
     ((x) & ~BE64_MASK((begin), (end))))

#endif // __VSBE_BEBITS_H
