/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/occ_firdata/pnorData_common.h $             */
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

#ifndef __pnorData_common_h
#define __pnorData_common_h

/** NOTE: This file is common between OCC and Hosboot. Any change to this file
 *        must be mirrored to both repositories. Also, this must be C, not C++,
 *        because OCC strictly uses C. */

#include <firDataConst_common.h>

/** This file is used to define the format of the register data captured by the
 *  OCC and stored in PNOR. The data will be stored in the following format:
 *
 *  - PNOR_Data_t struct - This has all of the information characterizing how
 *          many targets that have register data.
 *  - For each target with register data, the following format will be used:
 *      - PNOR_Trgt_t struct - Contains the target type, position, and how many
 *              registers are in the register list.
 *      - A list of all regular registers (PNOR_Reg_t).
 *      - A list of all indirect-SCOM registers (PNOR_IdReg_t).
 *
 *  The PNOR has limited data space. So the following rules will apply:
 *      - Any registers with the value of zero will not be captured.
 *      - Registers with SCOM errors will not be captured, however, the number
 *        of SCOM errors detected should be stored in each PNOR_Trgt_t struct.
 *      - If the value of a FIR (or ID FIR) is zero, do not capture the
 *        associated ACT0 and ACT1 registers. Note that the associated MASK and
 *        WOF registers are still needed.
 *      - Each target type may have associated global registers. If none exist,
 *        simply capture all registers for that type. However, if they do exist
 *        and the values of ALL the global registers are zero, skip capturing
 *        the associated targets using the following rules:
 *          - For a PROC, skip this PROC and all associated EXs, and MCSs.
 *          - For an EX,  skip this EX.
 *          - For an MCS, skip this MCS.
 *          - For a MEMB, skip this MEMB and all associated MBAs.
 *          - For an MBA, skip this MBA.
 *      - If for some reason we run out of space in the PNOR, do not SCOM any
 *        more registers, set the 'full' bit in the PNOR_Data_t struct, and
 *        write all data successfully captured to PNOR.
 */

typedef enum
{
    PNOR_FIR1 = 0x46495231, ///< FIR data version 1 ("FIR1" in ascii)

} PNOR_Version_t;

/** PNOR data header information. */
typedef struct
{
    uint32_t header; ///< Magic number to indicate valid data and version

    uint32_t trgts    :  8; ///< Number of targets with register data
    uint32_t full     :  1; ///< 1 if PNOR data is full and data may be missing
    uint32_t reserved : 23;

} PNOR_Data_t;

/** @return An initialized PNOR_Data_t struct. */
static inline PNOR_Data_t PNOR_getData()
{
    PNOR_Data_t d;
    d.header   = PNOR_FIR1;
    d.trgts    = 0;
    d.full     = 0;
    d.reserved = 0;

    return d;
};

/** These values will match the corresponding bit fields in PNOR_Trgt_t. */
typedef enum
{
    PNOR_Trgt_MAX_REGS_PER_TRGT    = 511, // Currently expect 266 on the PROC
    PNOR_Trgt_MAX_ID_REGS_PER_TRGT =  15, // Currently expect 9 on the MBA
    PNOR_Trgt_MAX_SCOM_ERRORS      = 511, // Should be plenty

} PNOR_Trgt_RegLimits_t;

/** Information for each target with SCOM data. */
typedef struct
{
    uint32_t type     : 3; ///< Target type. See enum TrgtType_t
    uint32_t procPos  : 3; ///< The processor position (0-7)
    uint32_t unitPos  : 4; ///< Unit position relative to the processor (0-15)
    uint32_t regs     : 9; ///< Number of normal registers
    uint32_t idRegs   : 4; ///< Number of indirect-SCOM registers
    uint32_t scomErrs : 9; ///< Number of SCOM errors detected

} PNOR_Trgt_t;

/** @param  i_type        Target type. See enum TrgtType_t.
 *  @param  i_procPos     The processor position.
 *  @param  i_procUnitPos Unit position relative to the processor.
 *  @return An initialized PNOR_Data_t struct.
 */
static inline PNOR_Trgt_t PNOR_getTrgt( uint32_t i_type, uint32_t i_procPos,
                                        uint32_t i_procUnitPos )
{
    PNOR_Trgt_t t;
    t.type     = i_type;
    t.procPos  = i_procPos;
    t.unitPos  = i_procUnitPos;
    t.regs     = 0;
    t.idRegs   = 0;
    t.scomErrs = 0;

    return t;
};

/** Information for a normal register. */
typedef struct
{
    uint32_t addr;  ///< 32-bit address
    uint64_t val;   ///< 64-bit value

} PNOR_Reg_t;

/** Information for an indirect-SCOM register. */
typedef struct
{
    uint64_t addr;  ///< 64-bit address
    uint32_t val;   ///< 32-bit value

} PNOR_IdReg_t;

#endif // __pnorData_common_h

