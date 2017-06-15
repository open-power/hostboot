/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/occ_firdata/firDataConst_common.h $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/** NOTE: These are used to build the register list in HOMER data      */
/**       and also to create the exiting chiplet masks. Hence,         */
/**       the numbers assigned here have to match the sequence         */
/**       of chiplets in HOMER_ChipNimbus_t, HOMER_ChipCumulus_t, etc. */
typedef enum
{
    /* NOTE: These will be used as array indexes. */
    TRGT_FIRST = 0,

    /** Common Nimbus/Cumulus types */
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

    /* Cumulus only */
    /* NOTE: Nimbus and Cumulus cannot be used at the same time. So we can have
     *       These array indexes overlap to save space. */
    TRGT_MC = TRGT_MCBIST,
    TRGT_MI,
    TRGT_DMI,

    /* Centaur only */
    TRGT_MEMBUF,
    TRGT_MBA,

    TRGT_MAX,

} TrgtType_t;

/** Boundary/position ranges for each target type. */
typedef enum
{
    /* Common Nimbus/Cumulus */
    MAX_PROC_PER_NODE   =  8,
    MAX_CAPP_PER_PROC   =  2,
    MAX_XBUS_PER_PROC   =  3, /* Nimbus 1 and 2, Cumulus 0, 1, and 2 */
    MAX_OBUS_PER_PROC   =  4, /* Nimbus 0 and 3, Cumulus 0, 1, 2, and 3 */
    MAX_PEC_PER_PROC    =  3,
    MAX_PHB_PER_PROC    =  6,
    MAX_EQ_PER_PROC     =  6,
    MAX_EX_PER_PROC     = 12,
    MAX_EC_PER_PROC     = 24,

    /** Nimbus only */
    MAX_MCBIST_PER_PROC =  2,
    MAX_MCS_PER_PROC    =  4,
    MAX_MCA_PER_PROC    =  8,

    /** Cumulus only */
    MAX_MC_PER_PROC     =  2,
    MAX_MI_PER_PROC     =  4,
    MAX_DMI_PER_PROC    =  8,

    /** Centaur only */
    MAX_MEMBUF_PER_PROC =  8,
    MAX_MEMBUF_PER_NODE =  MAX_MEMBUF_PER_PROC * MAX_PROC_PER_NODE,
    MAX_MBA_PER_MEMBUF  =  2,
    MAX_MBA_PER_PROC    =  MAX_MEMBUF_PER_PROC * MAX_MBA_PER_MEMBUF,

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
