/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_hcd_common.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
///
/// @file p10_hcd_common.H
/// @brief common hcode includes

// *HWP HWP Owner          : David Du               <daviddu@us.ibm.com>
// *HWP Backup HWP Owner   : Greg Still             <stillgs@us.ibm.com>
// *HWP FW Owner           : Prasad Brahmasamurdra  <prasadbgr@in.ibm.com>
// *HWP Team               : PM
// *HWP Consumed by        : SBE:QME
// *HWP Level              : 2

#ifndef __P10_HCD_COMMON_H__
#define __P10_HCD_COMMON_H__

// TODO RTC 207122 remove when scomdef address header is merged
#define  G_CPLT_CTRL0                 0x20000000
#define  G_CPLT_CTRL0_OR              0x20000010
#define  G_CPLT_CTRL0_CLR             0x20000020
#define  G_CPLT_CTRL1                 0x20000001
#define  G_CPLT_CTRL1_OR              0x20000011
#define  G_CPLT_CTRL1_CLR             0x20000021
#define  G_CPLT_CTRL2                 0x20000002
#define  G_CPLT_CTRL2_OR              0x20000012
#define  G_CPLT_CTRL2_CLR             0x20000022
#define  G_CPLT_CTRL3                 0x20000003
#define  G_CPLT_CTRL3_OR              0x20000013
#define  G_CPLT_CTRL3_CLR             0x20000023
#define  G_CPLT_CTRL4                 0x20000004
#define  G_CPLT_CTRL4_OR              0x20000014
#define  G_CPLT_CTRL4_CLR             0x20000024
#define  G_CPLT_STAT0                 0x20000100
#define  G_SCAN_REGION_TYPE           0x20030005
#define  G_CLK_REGION_TYPE            0x20030006
#define  G_CLOCK_STAT_SL              0x20030008
#define  G_CLOCK_STAT_NSL             0x20030009
#define  G_CLOCK_STAT_ARY             0x2003000A
#define  G_QME_CPMS_CGCSR             0x200E0E00
#define  G_QME_CPMS_CGCSR_CLR         0x200E0E02
#define  G_QME_CPMS_CGCSR_OR          0x200E0E03

//-------------------------
// Macros
//-------------------------

// Create a multi-bit mask of \a n bits starting at bit \a b
#define BITS64(b, n) ((0xffffffffffffffffull << (64 - (n))) >> (b))
#define BITS32(b, n) ((0xffffffff            << (32 - (n))) >> (b))
#define BITS16(b, n) (((0xffff               << (16 - (n))) & 0xffff) >> (b))
#define BITS8(b, n)  (((0xff                 << (8  - (n))) & 0xff) >> (b))

// Create a single bit mask at bit \a b
#define BIT64(b) BITS64((b), 1)
#define BIT32(b) BITS32((b), 1)
#define BIT16(b) BITS16((b), 1)
#define BIT8(b)  BITS8((b), 1)

// Create a amount of shift to bit location \a b
#define SHIFT64(b) (63-b)
#define SHIFT32(b) (31-b)
#define SHIFT16(b) (15-b)
#define SHIFT8(b)  (7-b)

/// Macro used for second word operation
#define BIT64SH(bit64)          BIT32((bit64-32))
#define BITS64SH(bit64, size)   BITS32((bit64-32), size)
#define SHIFT64SH(bit64)        SHIFT32((bit64-32))

/// Macros used for insertFromRight
#define MASK32(start,size,val)  (val << (32-(start+size)))
#define MASK64(start,size,val)  (val << (64-(start+size)))

// The BUF_* macros apply operations to a newly constructed buffer
#define BUF_SET(bit)   fapi2::buffer<uint64_t>().setBit<bit>()
#define BUF_UNSET(bit) fapi2::buffer<uint64_t>().flush<1>().clearBit<bit>()
#define BUF_INSERT(start,size,val) \
    fapi2::buffer<uint64_t>().insertFromRight<start,size>(val)
#define BUF_REPLACE(start,size,val) \
    fapi2::buffer<uint64_t>().flush<1>().insertFromRight<start,size>(val)

// The following DATA_* and MASK_* macros assume you have
// "fapi2::buffer<uint64_t> l_data64" declared

// The DATA_* macros apply operations to a buffer contains existing data
#define DATA_BIT(buf,op,bit)              buf.op##Bit<bit>()
#define DATA_SET(bit)                     DATA_BIT(l_data64,set,bit)
#define DATA_UNSET(bit)                   DATA_BIT(l_data64,clear,bit)
#define DATA_GET(bit)                     DATA_BIT(l_data64,get,bit)

#define DATA_FIELD(buf,op,start,size,val) buf.op##Right<start,size>(val)
#define DATA_INSERT(start,size,val)       DATA_FIELD(l_data64,insertFrom,start,size,val)
#define DATA_H32W(val)                    DATA_INSERT(0, 32, val)
#define DATA_L32W(val)                    DATA_INSERT(32,32, val)

#define DATA_EXTRACT(start,size,val)      DATA_FIELD(l_data64,extractTo,start,size,val)
#define DATA_H32R(val)                    DATA_EXTRACT(0, 32, val)
#define DATA_L32R(val)                    DATA_EXTRACT(32,32, val)

// The MASK_* macros apply operations to a buffer to create a new data mask
// data previously stored in the buffer will be overwritten.
#define MASK_FLUSH(buf,mask)             buf.flush<mask>()
#define MASK_ZERO                        MASK_FLUSH(l_data64,0)
#define MASK_ALL                         MASK_FLUSH(l_data64,1)

#define MASK_BIT(buf,mask,op,bit)        buf.flush<mask>().op##Bit<bit>()
#define MASK_SET(bit)                    MASK_BIT(l_data64,0,set,bit)
#define MASK_UNSET(bit)                  MASK_BIT(l_data64,1,clear,bit)

#define MASK_FIELD(buf,mask,start,size,val) \
    buf.flush<mask>().insertFromRight<start,size>(val)
#define MASK_OR(start,size,val)          MASK_FIELD(l_data64,0,start,size,val)
#define MASK_AND(start,size,val)         MASK_FIELD(l_data64,1,start,size,val)
#define MASK_CLR(start,size,val)         MASK_FIELD(l_data64,0,start,size,val)

#define MASK_FIELD2(buf,mask,start1,size1,val1,start2,size2,val2) \
    buf.flush<mask>().insertFromRight<start1,size1>(val1).insertFromRight<start2,size2>(val2)
#define MASK_H32(val)                    MASK_OR(0, 32,val)
#define MASK_L32(val)                    MASK_OR(32,32,val)
#define MASK_HL(hword, lword)            MASK_FIELD2(l_data64,0,0,32,hword,32,32,lword)

//-------------------------
// Constants
//-------------------------

// Do NOT put any namespace in this or any Hcode related header or source files
// for general comptiablity to C source based code in PPE image
// Instead of namespace protection, here will always use unique HCD prefix
// in ALL namings that shouldnt be used outside of Hcode team.


// Constants to calculate hcd poll timeout intervals
enum P10_HCD_TIMEOUT_CONSTANTS
{
    CYCLES_PER_MS       = 500000, // PPE FREQ 500MHZ
    INSTS_PER_POLL_LOOP = 8       //
};

// Constants to calculate the delay in nanoseconds or simcycles
// Source | Domain | Freq    | cyc/ns | Period |
// DPLL   | Core   | 4GHz    | 4      | 250ps  |
//        | Cache  | 2GHz    | 2      | 500ps  |
//        | PPE    | 500MHz  | 0.5    | 2ns    |
// Refclk | Refclk | 100Mhz  | 0.1    | 10ns   |
enum P10_HCD_DELAY_CONSTANTS
{
    SIM_CYCLE_1U1D        = 2,   // fastest internal oscillator
    SIM_CYCLE_4U4D        = 8,   // 4Ghz   ideal dpll
    SIM_CYCLE_150UD       = 300, // 133Mhz refclk
    SIM_CYCLE_200UD       = 400, // 100Mhz refclk external oscillator
    CLK_PERIOD_250PS      = 250, // 4GHZ dpll
    CLK_PERIOD_10NS       = 10,  // 100Mhz refclk
    CLK_PERIOD_CORE2CACHE = 2,
    CLK_PERIOD_CORE2PPE   = 8,
    CLK_PERIOD_CORE2REF   = 40
};

// PFET Control Constants
enum P10_HCD_PFET_CTRL_CONSTANTS
{
    HCD_POWER_CL2_OFF                        = 0x0, //00
    HCD_POWER_CL2_ON                         = 0x1, //01
    HCD_POWER_L3_OFF                         = 0x2, //10
    HCD_POWER_L3_ON                          = 0x3, //11
    HCD_PFET_L3_MASK                         = 0x2, //otherwise cl2
    HCD_PFET_ON_MASK                         = 0x1  //otherwise off
};

// Clock Control Constants
enum P10_HCD_CLK_CTRL_CONSTANTS
{
    HCD_CLK_STOP                                 = BIT32(0),
    HCD_CLK_START                                = BIT32(1),
    HCD_CLK_SLAVE                                = BIT32(2),
    HCD_CLK_MASTER                               = BIT32(3),
    HCD_CLK_REGION_PERV                          = BIT32(4),
    HCD_CLK_REGION_ECL2                          = BITS32(5, 4),
    HCD_CLK_REGION_L3                            = BITS32(9, 4),
    HCD_CLK_REGION_MMA                           = BITS32(16, 4),
    HCD_CLK_THOLD_ALL                            = BITS64SH(48, 3),
    HCD_CLK_THOLD_SL                             = BIT64SH(48),
    HCD_CLK_THOLD_NSL                            = BIT64SH(49),
    HCD_CLK_THOLD_ARY                            = BIT64SH(50)
};

// Scan Type Constants
enum P10_HCD_SCAN_TYPE_CONSTANTS
{
    SCAN_TYPE_FUNC                          = BIT64(48),
    SCAN_TYPE_CFG                           = BIT64(49),
    SCAN_TYPE_CCFG_GPTR                     = BIT64(50),
    SCAN_TYPE_REGF                          = BIT64(51),
    SCAN_TYPE_LBIST                         = BIT64(52),
    SCAN_TYPE_ABIST                         = BIT64(53),
    SCAN_TYPE_REPR                          = BIT64(54),
    SCAN_TYPE_TIME                          = BIT64(55),
    SCAN_TYPE_BNDY                          = BIT64(56),
    SCAN_TYPE_FARR                          = BIT64(57),
    SCAN_TYPE_CMSK                          = BIT64(58),
    SCAN_TYPE_INEX                          = BIT64(59)
};

// Scan Flush Constants
enum P10_HCD_SCAN0_CONSTANTS
{
    SCAN0_REGION_ALL                         = 0x7FF,
    SCAN0_REGION_ALL_BUT_PLL                 = 0x7FE,
    SCAN0_TYPE_GPTR_REPR_TIME                = 0x230,
    SCAN0_TYPE_ALL_BUT_GPTR_REPR_TIME        = 0xDCF
};

// XSR defines
enum XSR_DEFS
{
    HALTED_STATE         = 0,
    HALT_CONDITION_START = 1,
    HALT_CONDITION_LEN   = 3,
    XCR_CMD_HALT         = 1,
    WDT_HALT             = 2,
    UMI_HALT             = 3,
    DEBUG_HALT           = 4,
    DBCR_HALT            = 5,
    INPUT_HALT           = 6,
    HW_FAILURE           = 7
};

// XCR defines
enum XCR_DEFS
{
    CLEAR_DEBUG_STATUS = 0,
    HALT               = 1,
    RESUME             = 2,
    SINGLE_STEP        = 3,
    TOGGLE_XSR_TRH     = 4,
    SOFT_RESET         = 5,
    HARD_RESET         = 6,
    FORCE_HALT         = 7
};
enum SLAVE_CONFIG_DEFS
{
    CFG_PM_DISABLE     = 6,
    CFG_PM_MUX_DISABLE = 7
};

#define p10_HCD_SCAN_FUNC_REPEAT 1
#define p10_HCD_SCAN_GPTR_REPEAT 1

#endif  // __P10_HCD_COMMON_H__
