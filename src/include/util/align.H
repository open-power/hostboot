/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/align.H $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
#ifndef __UTIL_ALIGN_H
#define __UTIL_ALIGN_H

#include <limits.h>

// Return a number >= input that is aligned up to the next x boundary,
// where x is a power of 2.
#define ALIGN_X(u,x) (((u) + ((x)-1)) & ~((x)-1))

// Return a number <= input that is aligned on a x boundary, where x
// is a power of 2.
#define ALIGN_DOWN_X(u,x) ((u) - (u)%(x))

// Useful shortcut macros for 4.
#define ALIGN_4(u)              (ALIGN_X(u,4))
#define ALIGN_DOWN_4(u)         (ALIGN_DOWN_X(u,4))

// Useful shortcut macros for 8.
#define ALIGN_8(u)              (ALIGN_X(u,8))
#define ALIGN_DOWN_8(u)         (ALIGN_DOWN_X(u,8))

// Useful shortcut macros for a page.
#define ALIGN_PAGE(u)           (ALIGN_X(u,PAGESIZE))
#define ALIGN_PAGE_DOWN(u)      (ALIGN_DOWN_X(u,PAGESIZE))

// Useful shortcut macros for a MB.
#define ALIGN_MEGABYTE(u)       (ALIGN_X(u,MEGABYTE))
#define ALIGN_MEGABYTE_DOWN(u)  (ALIGN_DOWN_X(u,MEGABYTE))

// Returns a number that is aligned to the next highest power of 2 number of
// pages for the given buffer.
#define ALIGN_TO_NEXT_POWER_OF_TWO_PAGES(b)   ({\
    unsigned int v = ALIGN_PAGE(b)/PAGE_SIZE;\
    v--;\
    v |= v >> 1;\
    v |= v >> 2;\
    v |= v >> 4;\
    v |= v >> 8;\
    v |= v >> 16;\
    v++;\
    v * PAGE_SIZE;\
    })

#endif
