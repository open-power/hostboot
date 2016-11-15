/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_hcd_common.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file p9_hcd_common.H
/// @brief common hcode includes

// *HWP HWP Owner          : David Du       <daviddu@us.ibm.com>
// *HWP Backup HWP Owner   : Greg Still     <stillgs@us.ibm.com>
// *HWP FW Owner           : Sangeetha T S  <sangeet2@in.ibm.com>
// *HWP Team               : PM
// *HWP Consumed by        : SBE:SGPE:CME
// *HWP Level              : 2

#ifndef __P9_HCD_COMMON_H__
#define __P9_HCD_COMMON_H__

//-------------------------
// Macros
//-------------------------

// Create a multi-bit mask of \a n bits starting at bit \a b
#define BITS64(b, n) ((0xffffffffffffffffull << (64 - (n))) >> (b))
#define BITS32(b, n) ((0xffffffff            << (32 - (n))) >> (b))
#define BITS16(b, n) (((0xffff                << (16 - (n))) & 0xffff) >> (b))
#define BITS8(b, n)  (((0xff                  << (8  - (n))) & 0xff) >> (b))

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
#define DATA_BIT(buf,op,bit)             buf.op##Bit<bit>()
#define DATA_SET(bit)                    DATA_BIT(l_data64,set,bit)
#define DATA_UNSET(bit)                  DATA_BIT(l_data64,clear,bit)
#define DATA_FIELD(buf,start,size,val)   buf.insertFromRight<start,size>(val)
#define DATA_INSERT(start,size,val)      DATA_FIELD(l_data64,start,size,val)

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

//-------------------------
// Constants
//-------------------------

namespace p9hcd
{

// Bit masks used by CME hcode
enum P9_HCD_CME_CORE_MASKS
{
    LEFT_CORE  = 0x2,
    RIGHT_CORE = 0x1,
    BOTH_CORES = 0x3,
    NO_CORE    = 0x0
};

// Control parameters for PCB Aribter
enum P9_HCD_PCB_ARBITER_CTRL
{
    REQUEST_ARBITER = 1,
    RELEASE_ARBITER = 0
};

// Constants to calculate hcd poll timeout intervals
enum P9_HCD_TIMEOUT_CONSTANTS
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
enum P9_HCD_DELAY_CONSTANTS
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

// Chip Position Constants
enum P9_HCD_CHIP_POS_CONSTANTS
{
    PERV_TO_EQ_POS_OFFSET   = 0x10,
    PERV_TO_CORE_POS_OFFSET = 0x20
};

// EX Constants
enum P9_HCD_EX_CTRL_CONSTANTS
{
    ODD_EX                  = 1,
    EVEN_EX                 = 2,
    BOTH_EX                 = 3,
    QCSR_MASK_EX0           = (BIT64(0) | BIT64(2) | BIT64(4) |
                               BIT64(6) | BIT64(8) | BIT64(10)),
    QCSR_MASK_EX1           = (BIT64(1) | BIT64(3) | BIT64(5) |
                               BIT64(7) | BIT64(9) | BIT64(11))
};

// Multicast Constants
enum P9_HCD_MULTICAST_CONSTANTS
{
    MULTICAST_GROUP_4       = 4, // QUAD
    MULTICAST_GROUP_5       = 5, // EX0
    MULTICAST_GROUP_6       = 6  // EX1
};

// Clock Control Constants
enum P9_HCD_CLK_CTRL_CONSTANTS
{
    CLK_STOP_CMD                             = BIT64(0),
    CLK_START_CMD                            = BIT64(1),
    CLK_REGION_PERV                          = BIT64(4),
    CLK_REGION_ANEP                          = BIT64(10),
    CLK_REGION_DPLL                          = BIT64(14),
    CLK_REGION_REFR                          = BITS64(12, 2),
    CLK_REGION_L3_REFR                       = BITS64(6, 2) | BITS64(12, 2),
    CLK_REGION_EX0_L3                        = BIT64(6),
    CLK_REGION_EX1_L3                        = BIT64(7),
    CLK_REGION_EX0_L2                        = BIT64(8),
    CLK_REGION_EX1_L2                        = BIT64(9),
    CLK_REGION_EX0_REFR                      = BIT64(12),
    CLK_REGION_EX1_REFR                      = BIT64(13),
    CLK_REGION_EX0_L2_L3_REFR                = BIT64(6) | BIT64(8) | BIT64(12),
    CLK_REGION_EX1_L2_L3_REFR                = BIT64(7) | BIT64(9) | BIT64(13),
    CLK_REGION_ALL_BUT_L3_REFR               = BITS64(4, 2) | BITS64(8, 4) | BIT64(14),
    CLK_REGION_ALL_BUT_L3_REFR_DPLL          = BITS64(4, 2) | BITS64(8, 4),
    CLK_REGION_ALL_BUT_EX                    = BITS64(4, 2) | BITS64(10, 2) | BIT64(14),
    CLK_REGION_ALL_BUT_EX_DPLL               = BITS64(4, 2) | BITS64(10, 2),
    CLK_REGION_ALL_BUT_EX_ANEP_DPLL          = BITS64(4, 2) | BIT64(11),
    CLK_REGION_ALL_BUT_PLL                   = BITS64(4, 10),
    CLK_REGION_ALL_BUT_PLL_REFR              = BITS64(4, 8),
    CLK_REGION_ALL                           = BITS64(4, 11),
    CLK_THOLD_ALL                            = BITS64(48, 3),
    CLK_THOLD_SL                             = BIT64(48),
    CLK_THOLD_NSL                            = BIT64(49),
    CLK_THOLD_ARY                            = BIT64(50)
};

// Scan Type Constants
enum P9_HCD_SCAN_TYPE_CONSTANTS
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
enum P9_HCD_SCAN0_CONSTANTS
{
    SCAN0_REGION_ALL                         = 0x7FF,
    SCAN0_REGION_ALL_BUT_PLL                 = 0x7FE,
    SCAN0_REGION_ALL_BUT_EX                  = 0x619,
    SCAN0_REGION_ALL_BUT_EX_DPLL             = 0x618,
    SCAN0_REGION_ALL_BUT_EX_ANEP_DPLL        = 0x608,
    SCAN0_REGION_EX0_L2_L3_REFR              = 0x144,
    SCAN0_REGION_EX1_L2_L3_REFR              = 0x0A2,
    SCAN0_TYPE_GPTR_REPR_TIME                = 0x230,
    SCAN0_TYPE_ALL_BUT_GPTR_REPR_TIME        = 0xDCF
};

// XSR defines
enum XSR_DEFS
{
    HALTED_STATE    = 0
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

} // END OF NAMESPACE p9hcd


#define P9_HCD_SCAN_FUNC_REPEAT 1
#define P9_HCD_SCAN_GPTR_REPEAT 1

/// @todo remove these once correct header contains them
/// Scom addresses missing from p9_quad_scom_addresses.H
#define PU_OCB_OCI_QSSR_CLEAR            PU_OCB_OCI_QSSR_SCOM1
#define PU_OCB_OCI_QSSR_OR               PU_OCB_OCI_QSSR_SCOM2
#define EQ_QPPM_QCCR_WCLEAR              EQ_QPPM_QCCR_SCOM1
#define EQ_QPPM_QCCR_WOR                 EQ_QPPM_QCCR_SCOM2
#define EX_0_CME_SCOM_SICR_CLEAR         EX_0_CME_SCOM_SICR_SCOM1
#define EX_1_CME_SCOM_SICR_CLEAR         EX_1_CME_SCOM_SICR_SCOM1
#define EX_0_CME_SCOM_SICR_OR            EX_0_CME_SCOM_SICR_SCOM2
#define EX_1_CME_SCOM_SICR_OR            EX_1_CME_SCOM_SICR_SCOM2
#define EX_0_CME_SCOM_LMCR_CLEAR         EX_0_CME_SCOM_LMCR_SCOM1
#define EX_1_CME_SCOM_LMCR_CLEAR         EX_1_CME_SCOM_LMCR_SCOM1
#define EX_0_CME_SCOM_LMCR_OR            EX_0_CME_SCOM_LMCR_SCOM2
#define EX_1_CME_SCOM_LMCR_OR            EX_1_CME_SCOM_LMCR_SCOM2

#endif  // __P9_HCD_COMMON_H__
