/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/occ_firdata/homerData_common.h $            */
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

#ifndef __homerData_common_h
#define __homerData_common_h

/** NOTE: This file is common between OCC and Hosboot. Any change to this file
 *        must be mirrored to both repositories. */

#include <firDataConst_common.h>
#include <string.h>

/** This file is used to define the format of the register list stored in the
 *  HOMER data that the OCC will use to determine what register data to capture
 *  in the event of a system checkstop. The data will be stored in the following
 *  format:
 *
 *  - HOMER_Data_t struct - This has all of the information characterizing what
 *          hardware is configured and how many addresses are in each register
 *          list. See the struct definition below.
 *
 *  - Rgister address lists - These lists vary in size depending on the number
 *          of register addresses needed in each list. The list counts are
 *          stored in HOMER_Data_t::counts. All lists for each target type will
 *          be stored in the following order:
 *              - PROC lists
 *              - EX lists
 *              - MCS lists
 *              - MEMB lists
 *              - MBA lists
 *          Each target type will have a set of lists that will be stored in the
 *          following order:
 *              - Global FIRs               32-bit addresses
 *              - FIRs                      32-bit addresses
 *              - Registers                 32-bit addresses
 *              - Indirect-SCOM FIRs        64-bit addresses
 *              - Indirect-SCOM registers   64-bit addresses
 *
 *  Note that FIRs and indirect-SCOM FIRs characterize a set of registers to
 *  capture. In addition to capturing the FIR (or ID FIR), the OCC will need to
 *  capture the following addresses for each type:
 *      - FIR
 *          - MASK (FIR address + 3)
 *          - ACT0 (FIR address + 6)
 *          - ACT1 (FIR address + 7)
 *          - WOF  (FIR address + 8)
 *      - ID FIR
 *          - ID MASK (ID FIR address + 0x300000000ll)
 *          - ID ACT0 (ID FIR address + 0x600000000ll)
 *          - ID ACT1 (ID FIR address + 0x700000000ll)
 *          - ID WOF  (ID FIR address + 0x800000000ll)
 */

typedef enum
{
    HOMER_FIR1 = 0x46495231, ///< FIR data version 1 ("FIR1" in ascii)

} HOMER_Version_t;

/** PNOR information contained within the HOMER data. */
typedef struct
{
    uint32_t pnorOffset;     ///< Physical offset of FIRDATA in PNOR
    uint32_t pnorSize;       ///< Maximum size of FIRDATA (includes ECC)
    uint32_t mmioOffset;     ///< Address of MMIO access
    uint32_t norWorkarounds; ///< NOR flash vendor

} HOMER_PnorInfo_t;

/** HOMER data header information containing hardware configurations and
 *  register counts. */
typedef struct
{
    uint32_t header; ///< Magic number to indicate valid data and version

    uint16_t reserved;

    uint8_t masterProc; ///< The position of the master PROC

    /** Bitwise mask to indicate which PROCs are configured (max 8). The mask
     *  bit position is consistant with PROC ATTR_POSITION attribute. */
    uint8_t procMask;

    /** Bitwise masks to indicate which EXs are configured (16 per PROC). The
     *  array index is the associated PROC position. The mask bit position is
     *  consistant with the EX's ATTR_CHIP_UNIT attribute. */
    uint16_t exMasks[MAX_PROC_PER_NODE];

    /** Bitwise masks to indicate which MCSs are configured (8 per PROC). The
     *  array index is the associated PROC position. The mask bit position is
     *  consistant with the MCS's ATTR_CHIP_UNIT attribute. */
    uint8_t mcsMasks[MAX_PROC_PER_NODE];

    /** Bitwise masks to indicate which MEMBs are configured (8 per PROC). The
     *  array index is the associated PROC position. The mask bit position is
     *  consistant with the ATTR_CHIP_UNIT attribute of the connected MCS. */
    uint8_t membMasks[MAX_PROC_PER_NODE];

    /** Bitwise masks to indicate which MBAs are configured (16 per PROC). The
     *  array index is the associated PROC position. The mask bit position is
     *  calculated as:
     *    (MEMB position * MAX_MBA_PER_MEMB) + MBA's ATTR_CHIP_UNIT attribute
     */
    uint16_t mbaMasks[MAX_PROC_PER_NODE];

    /** Contains number of registers per type for each target type. */
    uint8_t counts[MAX_TRGTS][MAX_REGS];

    /** FSI base address for each PROC chip. */
    uint32_t procFsiBaseAddr[MAX_PROC_PER_NODE];

    /** FSI base address for each MEMB chip. */
    uint32_t membFsiBaseAddr[MAX_PROC_PER_NODE][MAX_MEMB_PER_PROC];

    /** Information regarding the PNOR location and size. */
    HOMER_PnorInfo_t pnorInfo;

} HOMER_Data_t;

/** @return An initialized HOMER_Data_t struct. */
static inline HOMER_Data_t HOMER_getData()
{
    HOMER_PnorInfo_t p;
    HOMER_Data_t d;

    p.pnorOffset     = 0;
    p.pnorSize       = 0;
    p.mmioOffset     = 0;
    p.norWorkarounds = 0;

    d.header     = HOMER_FIR1;
    d.reserved   = 0;
    d.masterProc = 0;
    d.procMask   = 0;
    d.pnorInfo   = p;

    memset( d.exMasks,         0x00, sizeof(d.exMasks)         );
    memset( d.mcsMasks,        0x00, sizeof(d.mcsMasks)        );
    memset( d.membMasks,       0x00, sizeof(d.membMasks)       );
    memset( d.mbaMasks,        0x00, sizeof(d.mbaMasks)        );
    memset( d.counts,          0x00, sizeof(d.counts)          );
    memset( d.procFsiBaseAddr, 0xff, sizeof(d.procFsiBaseAddr) );
    memset( d.membFsiBaseAddr, 0xff, sizeof(d.membFsiBaseAddr) );

    return d;
}

#endif // __homerData_common_h
