/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/occ_firdata/homerData_common.h $            */
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

#ifndef __homerData_common_h
#define __homerData_common_h

/** NOTE: This file is common between OCC and Hosboot. Any change to this file
 *        must be mirrored to both repositories. Also, this must be C, not C++,
 *        because OCC strictly uses C. */

#include <firDataConst_common.h>
#include <string.h>

/** This file is used to define the format of the register list stored in the
 *  HOMER data that the OCC will use to determine what register data to capture
 *  in the event of a system checkstop. The data will be stored in the following
 *  format:
 *
 *  - HOMER_Data_t struct - This contains PNOR information, IPL state, number of
 *      configured chips, and number of register addresses per target type per
 *      register type.
 *
 *  - For each configured chip, the following format will be used:
 *      - HOMER_Chip_t struct - containing FSI base address, chip type, and chip
 *        position.
 *      - Immediately following will be a chip struct that is specific to the
 *        chip type stored in the preceding struct. These vary in size and
 *        structure depending on the chip type.
 *
 *  - Register address lists - These lists vary in size depending on the number
 *      of register addresses needed in each list. The list counts are stored in
 *      HOMER_Data_t::regCounts. Order of the lists must match the array indexes
 *      of HOMER_Data_t::regCounts, which are specified in TrgtType_t and
 *      RegType_t.
 *
 *  - Chip specific address list - This is a list of HOMER_ChipSpecAddr_t
 *      structs and will vary in size depending on the number of register
 *      addresses that are specific to a certain chip or DD level. The number of
 *      entries in this list is stored in HOMER_Data_t::ecDepCounts.
 *
 *  IMPORTANT NOTE: All of the structs used here are packed. Therefore, we must
 *      ensure the variables within the struct are byte aligned. Meaning each
 *      uint32_t within the struct must be 4-byte aligned and each uint16_t must
 *      be 2-byte aligned. This also means the structs must always start on a
 *      4-bye word boundary to maintain alignment. This is required due to the
 *      limitations of the PPE42/SRAM hardware.
 *
 *  Note that FIRs and indirect-SCOM FIRs characterize a set of registers to
 *  capture. In addition to capturing the FIR (or ID FIR), the OCC will need to
 *  capture the following addresses for each type:
 *      - FIR
 *          - MASK (FIR address + 3)
 *          - ACT0 (FIR address + 6)
 *          - ACT1 (FIR address + 7)
 *      - ID FIR
 *          - ID MASK (ID FIR address + 0x300000000ll)
 *          - ID ACT0 (ID FIR address + 0x600000000ll)
 *          - ID ACT1 (ID FIR address + 0x700000000ll)
 *  Note that not all FIRs have a corresponding WOF register. So any WOFs needed
 *  for analysis will need to be explicitly listed in the corresponding
 *  'Registers' lists.
 */

typedef enum
{
    HOMER_FIR1 = 0x46495231, /** FIR data version 1 ("FIR1" in ascii) P8 */
    HOMER_FIR2 = 0x46495232, /** FIR data version 1 ("FIR2" in ascii) P9 */

} HOMER_Version_t;

/** PNOR information contained within the HOMER data. */
/* NOTE: This structure is 4-byte word aligned. */
typedef struct __attribute__((packed))
{
    uint32_t pnorOffset;     /** Physical offset of FIRDATA in PNOR */
    uint32_t pnorSize;       /** Maximum size of FIRDATA (includes ECC) */
    uint32_t mmioOffset;     /** Address of MMIO access */
    uint32_t norWorkarounds; /** NOR flash vendor */

} HOMER_PnorInfo_t;

/** HOMER data header information containing hardware configurations and
 *  register counts. */
/* NOTE: This structure may, or may not, be 4-byte word aligned. It all depends
 *       on the size of regCounts, which will change based on the number of
 *       target types and register types we support. When reading/writing this
 *       data ensure that proper padding has been added after this structure so
 *       that subsequent structures are 4-byte word aligned. */
typedef struct __attribute__((packed))
{
    uint32_t header; /** Magic number to indicate valid data and version */

    uint32_t chipCount   :  8; /** Number of configured chips per node */
    uint32_t ecDepCounts :  8; /** Number of regs that are EC dependent */
    uint32_t iplState    :  1; /** See IplState_t. */
    uint32_t reserved    : 15;

    /** Information regarding the PNOR location and size. */
    HOMER_PnorInfo_t pnorInfo;

    /** Contains number of registers per type for each target type. */
    uint8_t regCounts[TRGT_MAX][REG_MAX];

} HOMER_Data_t;

/** @return An initialized HOMER_Data_t struct. */
static inline HOMER_Data_t HOMER_getData()
{
    HOMER_Data_t d; memset( &d, 0x00, sizeof(d) ); /* init to zero */

    d.header = HOMER_FIR2;

    return d;
}

/*----------------------------------------------------------------------------*/

/** Supported chip types. */
typedef enum
{
    HOMER_CHIP_NIMBUS,  /** P9 Nimbus processor chip */
    HOMER_CHIP_CUMULUS, /** P9 Cumulus processor chip */
    HOMER_CHIP_CENTAUR, /** Centaur memory buffer chip */

} HOMER_ChipType_t;

/** Information for each configured chip. */
/* NOTE: This structure is 4-byte word aligned. */
typedef struct __attribute__((packed))
{
    uint32_t fsiBaseAddr;   /** FSI base address for the chip. */

    uint32_t chipType    :  4; /** Chip type (see HOMER_ChipType_t) */
    uint32_t chipPos     :  6; /** Chip position relative to the node. */
    uint32_t chipEcLevel :  8; /** EC level for this chip */
    uint32_t reserved    : 14;

} HOMER_Chip_t;

/** Used for Registers that have EC level dependencies */
/* NOTE: This structure is 4-byte word aligned. */
typedef struct __attribute__((packed))
{
    uint32_t chipType :  4; /** See HOMER_ChipType_t. */
    uint32_t trgtType :  6; /** See TrgtType_t. */
    uint32_t regType  :  4; /** See RegType_t. */
    uint32_t ddLevel  :  8; /** A zero value applies to all levels on a chip. */
    uint32_t reserved : 10; /** unused at this time */

    /** The 32 or 64 bit address (right justified). */
    uint64_t address;

} HOMER_ChipSpecAddr_t;

/** @return An initialized HOMER_Chip_t struct. */
static inline HOMER_Chip_t HOMER_getChip( HOMER_ChipType_t i_type )
{
    HOMER_Chip_t c; memset( &c, 0x00, sizeof(c) ); /* init to zero */

    c.fsiBaseAddr = 0xffffffff;
    c.chipType    = i_type;

    return c;
}

/*----------------------------------------------------------------------------*/

/** Information specific to a P9 Nimbus processor chip. */
/* NOTE: This structure is 4-byte word aligned. */
typedef struct __attribute__((packed))
{
    uint32_t isMaster   :  1; /** 1 if this is the master PROC, 0 otherwise */
    uint32_t xbusMask   :  3; /** Mask of configured XBUS units (0-2) */
    uint32_t obusMask   :  4; /** Mask of configured OBUS units (0-3) */
    uint32_t ecMask     : 24; /** Mask of configured EC units (0-23) */

    uint32_t eqMask     :  6; /** Mask of configured EQ units (0-5) */
    uint32_t exMask     : 12; /** Mask of configured EX units (0-11) */
    uint32_t mcbistMask :  2; /** Mask of configured MCBIST units (0-1) */
    uint32_t mcsMask    :  4; /** Mask of configured MCS units (0-3) */
    uint32_t mcaMask    :  8; /** Mask of configured MCA units (0-7) */

    uint32_t cappMask   :  2; /** Mask of configured CAPP units (0-1) */
    uint32_t pecMask    :  3; /** Mask of configured PEC units (0-2) */
    uint32_t phbMask    :  6; /** Mask of configured PHB units (0-5) */
    uint32_t reserved   : 21;

} HOMER_ChipNimbus_t;

/** @return An initialized HOMER_ChipNimbus_t struct. */
static inline HOMER_ChipNimbus_t HOMER_initChipNimbus()
{
    HOMER_ChipNimbus_t c; memset( &c, 0x00, sizeof(c) ); /* init to zero */

    return c;
}

/*----------------------------------------------------------------------------*/

/** Information specific to a P9 Cumulus processor chip. */
/* NOTE: This structure is 4-byte word aligned. */
typedef struct __attribute__((packed))
{
    uint32_t isMaster :  1; /** 1 if this is the master PROC, 0 otherwise */
    uint32_t xbusMask :  3; /** Mask of configured XBUS units (0-2) */
    uint32_t obusMask :  4; /** Mask of configured OBUS units (0-3) */
    uint32_t ecMask   : 24; /** Mask of configured EC units (0-23) */

    uint32_t eqMask   :  6; /** Mask of configured EQ units (0-5) */
    uint32_t exMask   : 12; /** Mask of configured EX units (0-11) */
    uint32_t mcMask   :  2; /** Mask of configured MC units (0-1) */
    uint32_t miMask   :  4; /** Mask of configured MI units (0-3) */
    uint32_t dmiMask  :  8; /** Mask of configured DMI units (0-7) */

    uint32_t cappMask :  2; /** Mask of configured CAPP units (0-1) */
    uint32_t pecMask  :  3; /** Mask of configured PEC units (0-2) */
    uint32_t phbMask  :  6; /** Mask of configured PHB units (0-5) */
    uint32_t reserved : 21;

} HOMER_ChipCumulus_t;

/** @return An initialized HOMER_ChipCumulus_t struct. */
static inline HOMER_ChipCumulus_t HOMER_initChipCumulus()
{
    HOMER_ChipCumulus_t c; memset( &c, 0x00, sizeof(c) ); /* init to zero */

    return c;
}

/*----------------------------------------------------------------------------*/

/** Information specific to a Centaur memory buffer chip. */
/* NOTE: This structure is 4-byte word aligned. */
typedef struct __attribute__((packed))
{
    uint32_t mbaMask  :  2; /** Mask of configured MBA units (0-1) */
    uint32_t reserved : 30;

} HOMER_ChipCentaur_t;

/** @return An initialized HOMER_ChipCentaur_t struct. */
static inline HOMER_ChipCentaur_t HOMER_initChipCentaur()
{
    HOMER_ChipCentaur_t c; memset( &c, 0x00, sizeof(c) ); /* init to zero */

    return c;
}

#endif /* __homerData_common_h */
