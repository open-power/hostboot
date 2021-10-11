/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/stdint.h $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2021                        */
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
#ifndef __STDINT_H
#define __STDINT_H

#include <stddef.h>

typedef signed char         int8_t;
typedef short int           int16_t;
typedef int                 int32_t;
typedef long int            int64_t;

typedef signed char         int_least8_t;
typedef short int           int_least16_t;
typedef int                 int_least32_t;
typedef long int            int_least64_t;

typedef signed char         int_fast8_t;
typedef long int            int_fast16_t;
typedef long int            int_fast32_t;
typedef long int            int_fast64_t;

typedef unsigned char       uint8_t;
typedef unsigned short int  uint16_t;
typedef unsigned int        uint32_t;
typedef unsigned long int   uint64_t;

typedef unsigned char       uint_least8_t;
typedef unsigned short int  uint_least16_t;
typedef unsigned int        uint_least32_t;
typedef unsigned long int   uint_least64_t;

typedef unsigned char       uint_fast8_t;
typedef unsigned long int   uint_fast16_t;
typedef unsigned long int   uint_fast32_t;
typedef unsigned long int   uint_fast64_t;


typedef uint64_t            size_t;
typedef int64_t             ssize_t;

typedef ssize_t             ptrdiff_t;

#define UINT8_MAX  (255U)
#define UINT16_MAX (65535U)
#define UINT32_MAX (4294967295U)
#define UINT64_MAX (18446744073709551615U)
#define SIZE_MAX   UINT64_MAX
#define INT64_MAX  (9223372036854775807U)

//  add (u)intptr_t support
typedef long int            intptr_t;
typedef unsigned long int   uintptr_t;

#endif
