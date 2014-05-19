/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/model/bebits.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
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
