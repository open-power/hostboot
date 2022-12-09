/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/limits.h $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2023                        */
/* [+] Google Inc.                                                        */
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
#ifndef __LIMITS_H
#define __LIMITS_H

#define KILOBYTE  (1024ul)            /**< 1 KB */
#define MEGABYTE  (1024 * 1024ul)     /**< 1 MB */
#define GIGABYTE  (MEGABYTE * 1024ul) /**< 1 GB */
#define TERABYTE  (GIGABYTE * 1024ul) /**< 1 TB */

#define PAGESIZE  (4*KILOBYTE)  /**< 4 KB */
#define PAGE_SIZE PAGESIZE

#define INT_MAX   __INT_MAX__
#define SHRT_MAX  __SHRT_MAX__
#define SSIZE_MAX __INT64_MAX__
#define CHAR_BIT    __CHAR_BIT__

#define SCHAR_MAX   __SCHAR_MAX__
#define SCHAR_MIN   (-SCHAR_MAX - 1)
#define UCHAR_MAX   (SCHAR_MAX * 2 + 1)

#ifdef __CHAR_UNSIGNED__
  #define CHAR_MAX  UCHAR_MAX
  #define CHAR_MIN  0
#else
  #define CHAR_MAX  SCHAR_MAX
  #define CHAR_MIN  SCHAR_MIN
#endif

#define SHRT_MIN    (-SHRT_MAX - 1)
#define USHRT_MAX   (SHRT_MAX * 2 + 1)

#define INT_MIN     (-INT_MAX - 1)
#define UINT_MAX    (INT_MAX * 2U + 1U)

#define LONG_MAX    __LONG_MAX__
#define LONG_MIN    (-LONG_MAX - 1L)
#define ULONG_MAX   (LONG_MAX * 2UL + 1UL)

#define LLONG_MAX   __LONG_LONG_MAX__
#define LLONG_MIN   (-LLONG_MAX - 1LL)
#define ULLONG_MAX  (LLONG_MAX * 2ULL + 1ULL)

#endif
