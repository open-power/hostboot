/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/occ_firdata/firDataConst_common.h $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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

#ifndef __firDataConst_common_h
#define __firDataConst_common_h

/** NOTE: This file is common between OCC and Hosboot. Any change to this file
 *        must be mirrored to both repositories. Also, this must be C, not C++,
 *        because OCC strictly uses C. */

#include <stdint.h>

/** Target types for all supported targets. */
typedef enum
{
    // NOTE: These will be used as array indexes.
    FIRST_TRGT = 0,
    PROC       = FIRST_TRGT,
    EX,
    MCS,
    MEMB,
    MBA,
    MAX_TRGTS,

} TrgtType_t;

/** Boundary/position ranges for each target type. */
typedef enum
{
    MAX_PROC_PER_NODE = 8,
    MAX_EX_PER_PROC   = 16,
    MAX_MCS_PER_PROC  = 8,
    MAX_MEMB_PER_PROC = MAX_MCS_PER_PROC,
    MAX_MEMB_PER_NODE = MAX_MEMB_PER_PROC * MAX_PROC_PER_NODE,
    MAX_MBA_PER_MEMB  = 2,
    MAX_MBA_PER_PROC  = MAX_MEMB_PER_PROC * MAX_MBA_PER_MEMB,

} TrgtPos_t;

/** All register types. */
typedef enum
{
    // NOTE: These will be used as array indexes.
    FIRST_REG = 0,
    GLBL      = FIRST_REG,
    FIR,
    REG,
    IDFIR,
    IDREG,
    MAX_REGS,

} RegType_t;

/** IPL or Runtime flag in HOMER data */
typedef enum
{
    HOMER_RUNTIME_STATE = 0,
    HOMER_IPL_STATE     = 1
} Homer_IplRuntime_t;

#endif // __firDataConst_common_h
