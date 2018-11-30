/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/occ_firdata/firDataConst_common.h $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
    /* NOTE: These will be used as array indexes. */
    TRGT_FIRST = 0,

    /** Common Nimbus/Axone types */
    TRGT_PROC = TRGT_FIRST,
    TRGT_CAPP,
    TRGT_XBUS,
    TRGT_OBUS,
    TRGT_PEC,
    TRGT_PHB,
    TRGT_EQ,
    TRGT_EX,
    TRGT_EC,

    /* Nimbus only */
    TRGT_MCBIST,
    TRGT_MCS,
    TRGT_MCA,

    /* Axone only */
    TRGT_MC,
    TRGT_MI,
    TRGT_MCC,
    TRGT_OMIC,
    TRGT_NPU,

    /* Explorer only */
    TRGT_OCMB,

    TRGT_MAX,

} TrgtType_t;

/** Boundary/position ranges for each target type. */
typedef enum
{
    /* Common Nimbus/Axone */
    MAX_PROC_PER_NODE   =  8,
    MAX_CAPP_PER_PROC   =  2,
    MAX_XBUS_PER_PROC   =  3, /* Nimbus 1 and 2, Axone 0, 1, and 2 */
    MAX_OBUS_PER_PROC   =  4, /* Nimbus 0 and 3, Axone 0, 1, 2, and 3 */
    MAX_PEC_PER_PROC    =  3,
    MAX_PHB_PER_PROC    =  6,
    MAX_EQ_PER_PROC     =  6,
    MAX_EX_PER_PROC     = 12,
    MAX_EC_PER_PROC     = 24,

    /** Nimbus only */
    MAX_MCBIST_PER_PROC =  2,
    MAX_MCS_PER_PROC    =  4,
    MAX_MCA_PER_PROC    =  8,

    /** Axone only */
    MAX_MC_PER_PROC     =  2,
    MAX_MI_PER_PROC     =  4,
    MAX_MCC_PER_PROC    =  8,
    MAX_OMIC_PER_PROC   =  6,
    MAX_NPU_PER_PROC    =  3,

    /** Explorer only */
    MAX_OCMB_PER_PROC   = 16 ,
    MAX_OCMB_PER_NODE   = MAX_OCMB_PER_PROC * MAX_PROC_PER_NODE,

} TrgtPos_t;

/** All register types. */
typedef enum
{
    /* NOTE: These will be used as array indexes. */
    REG_FIRST = 0,

    REG_GLBL = REG_FIRST, /* 32-bit addresses, 64-bit value */
    REG_FIR,              /* 32-bit addresses, 64-bit value */
    REG_REG,              /* 32-bit addresses, 64-bit value */
    REG_IDFIR,            /* 64-bit addresses, 32-bit value */
    REG_IDREG,            /* 64-bit addresses, 32-bit value */

    REG_MAX,

} RegType_t;

/** Indicates the state of the machine when the checkstop occurred. */
typedef enum
{
    FIRDATA_STATE_RUNTIME = 0,
    FIRDATA_STATE_IPL     = 1,

} IplState_t;

#endif /* __firDataConst_common_h */
