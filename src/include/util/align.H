/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/align.H $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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

// Return a number >= input that is aligned up to the next 4-byte boundary
#define ALIGN_4(u) (((u) + 0x3ull) & ~0x3ull)

// Return a number <= input that is rounded down to nearest 4-byte boundary
#define ALIGN_DOWN_4(u) ((u) & ~3ull)

// Return a number >= input that is aligned up to the next 8-byte bounday
#define ALIGN_8(u) (((u) + 0x7ull) & ~0x7ull)

// Return a number <= input that is rounded down to nearest 8-byte boundary
#define ALIGN_DOWN_8(u) ((u) & ~7ull)

// Return a number >= input that is aligned up to the next page boundary
#define ALIGN_PAGE(u) (((u) + (PAGESIZE-1)) & ~(PAGESIZE-1))

// Return a number <= input that is aligned on a page boundary
#define ALIGN_PAGE_DOWN(u) ((u) - (u)%PAGESIZE)

// Return a number >= input that is aligned up to the next MB boundary
#define ALIGN_MEGABYTE(u) (((u) + (MEGABYTE-1)) & ~(MEGABYTE-1))

// Return a number <= input that is aligned on a MB boundary
#define ALIGN_MEGABYTE_DOWN(u) ((u) - (u)%MEGABYTE)


#endif
