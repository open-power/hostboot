/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_hcd_common.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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

#include <stdint.h>

#ifndef __PPE_QME

    #define CPMS_MMAR_WO_OR              CPMS_MMAR_SCOM2

    #define CPMS_FDCR_WO_CLEAR           CPMS_FDCR_SCOM1
    #define CPMS_FDCR_WO_OR              CPMS_FDCR_SCOM2

    #define CPMS_CUCR_WO_CLEAR           CPMS_CUCR_SCOM1
    #define CPMS_CUCR_WO_OR              CPMS_CUCR_SCOM2

    #define QME_SCSR_WO_OR               QME_SCSR_SCOM2

    #define QME_TFCSR_WO_CLEAR           QME_TFCSR_SCOM1
    #define QME_TFCSR_WO_OR              QME_TFCSR_SCOM2

#else
    #ifndef QME_IMAGE_SOURCE

        #define CPMS_MMAR_WO_OR              CPMS_MMAR_PPE2

        #define CPMS_FDCR_WO_CLEAR           CPMS_FDCR_PPE1
        #define CPMS_FDCR_WO_OR              CPMS_FDCR_PPE2

        #define CPMS_CUCR_WO_CLEAR           CPMS_CUCR_PPE1
        #define CPMS_CUCR_WO_OR              CPMS_CUCR_PPE2

        #define QME_SCSR_WO_OR               QME_SCSR_PPE2

        #define QME_TFCSR_WO_CLEAR           QME_TFCSR_PPE1
        #define QME_TFCSR_WO_OR              QME_TFCSR_PPE2

    #endif
#endif

//-------------------------
// Test Switches
//-------------------------

#define P10_HCD_SCAN0_FUNC_REPEAT    1
#define P10_HCD_SCAN0_GPTR_REPEAT    1

//-------------------------
// Macros
//-------------------------

/// \defgroup be64_bits Bit manipulation for 64-bit Big-Endian values
///
/// \note These macros only work in the assembler context because we build our
/// assemblers to do 64-bit arithmetic, which is required for PORE assembly.
///
/// @{

/// Create a multi-bit mask of \a n bits starting at bit \a b
#define BITS64(b, n) ((0xffffffffffffffffull << (64 - (n))) >> (b))
#define BITS32(b, n) ((0xffffffff            << (32 - (n))) >> (b))
#define BITS16(b, n) (((0xffff               << (16 - (n))) & 0xffff) >> (b))
#define BITS8(b, n)  (((0xff                 << (8  - (n))) & 0xff) >> (b))

/// Create a single bit mask at bit \a b
#define BIT64(b) BITS64((b), 1)
#define BIT32(b) BITS32((b), 1)
#define BIT16(b) BITS16((b), 1)
#define BIT8(b)  BITS8((b), 1)

/// Create a amount of shift to bit location \a b
#define SHIFT64(b) (63-(b))
#define SHIFT32(b) (31-(b))
#define SHIFT16(b) (15-(b))
#define SHIFT8(b)  (7-(b))

/// Macro used for second word operation
#define BIT64SH(bit64)          BIT32((bit64-32))
#define BITS64SH(bit64, size)   BITS32((bit64-32), size)
#define SHIFT64SH(bit64)        SHIFT32((bit64-32))

/// Second Half Local Register Access
/// use in32/out32 for first half
#define in32_sh(addr)           in32(addr+4)
#define out32_sh(addr, data)    out32(addr+4, data)

/// Macros used for insertFromRight
#define MASK32(start,size,val)  (val << (32-(start+size)))
#define MASK64(start,size,val)  (val << (64-(start+size)))

// local/scom addr switcher
// Through several experiments with plat_target,
// it was very costly to overlay core select
// and on top of that, scom and local
// core_select bit locations are differnt.
// one on first half word, another on second,
// the instruction is working on 16bit boundary
// on immediates, therefore the cost depends
// very much on whether the overlay happened
// on the first half or second half
// because first half anyway needs to overlay
// the multicast info or chiplet_id

// IMPORTANT NOTE:
// only use the following macro on any register
// that has both local and scom address
#ifdef __PPE_QME
    typedef uint32_t buffer_t;
    #define MMIO_LOWADDR(addr)                 (addr+4)
    #define MMIO_LOWBIT(bit)                   (bit-32)

    #define HCD_PUTMMIO_C(target, addr, data)  putMmioCore(target, addr, data)
    #define HCD_GETMMIO_C(target, addr, data)  getMmioCore(target, addr, data)
    #define HCD_PUTMMIO_Q(target, addr, data)  putMmioQuad(target, addr, data)
    #define HCD_GETMMIO_Q(target, addr, data)  getMmioQuad(target, addr, data)

    #define HCD_PUTSCOM_C(target, addr, data)  putScomCore(target, addr, data)
    #define HCD_GETSCOM_C(target, addr, data)  getScomCore(target, addr, data)
    #define HCD_PUTSCOM_Q(target, addr, data)  putScomQuad(target, addr, data)
    #define HCD_GETSCOM_Q(target, addr, data)  getScomQuad(target, addr, data)
#else
    typedef uint64_t buffer_t;
    #define MMIO_LOWADDR(addr)                 (addr)
    #define MMIO_LOWBIT(bit)                   (bit)

    #define HCD_PUTMMIO_C(target, addr, data)  putScom(target, addr, data)
    #define HCD_GETMMIO_C(target, addr, data)  getScom(target, addr, data)
    #define HCD_PUTMMIO_Q(target, addr, data)  putScom(target, addr, data)
    #define HCD_GETMMIO_Q(target, addr, data)  getScom(target, addr, data)

    #define HCD_PUTSCOM_C(target, addr, data)  putScom(target, addr, data)
    #define HCD_GETSCOM_C(target, addr, data)  getScom(target, addr, data)
    #define HCD_PUTSCOM_Q(target, addr, data)  putScom(target, addr, data)
    #define HCD_GETSCOM_Q(target, addr, data)  getScom(target, addr, data)
#endif

// The following MMIO_* and SCOM_* macros assume you have
// BUF_MMIO defined as variable name of your mmio buffer
// BUF_SCOM defined as variable name of your scom buffer
#define BUF_MMIO l_mmioData
#define BUF_SCOM l_scomData

// The following macros apply operations to a buffer contains existing data
#define BUF_BIT(buf,op,bit)               buf.op##Bit<bit>()
#define MMIO_GET(bit)                     BUF_BIT(BUF_MMIO,get,bit)
#define MMIO_SET(bit)                     BUF_BIT(BUF_MMIO,set,bit)
#define MMIO_UNSET(bit)                   BUF_BIT(BUF_MMIO,clear,bit)

#define SCOM_GET(bit)                     BUF_BIT(BUF_SCOM,get,bit)
#define SCOM_SET(bit)                     BUF_BIT(BUF_SCOM,set,bit)
#define SCOM_UNSET(bit)                   BUF_BIT(BUF_SCOM,clear,bit)

#define BUF_FIELD(buf,op,start,size,val)  buf.op##Right<start,size>(val)
#define MMIO_INSERT(start,size,val)       BUF_FIELD(BUF_MMIO,insertFrom,start,size,val)
#define MMIO_EXTRACT(start,size,val)      BUF_FIELD(BUF_MMIO,extractTo,start,size,val)
#define SCOM_INSERT(start,size,val)       BUF_FIELD(BUF_SCOM,insertFrom,start,size,val)
#define SCOM_EXTRACT(start,size,val)      BUF_FIELD(BUF_SCOM,extractTo,start,size,val)

#define MMIO_PUT32H(val)                  MMIO_INSERT(0, 32, val)
#define MMIO_PUT32L(val)                  MMIO_INSERT(MMIO_LOWBIT(32), 32, val)
#define MMIO_GET32H(val)                  MMIO_EXTRACT(0, 32, val)
#define MMIO_GET32L(val)                  MMIO_EXTRACT(MMIO_LOWBIT(32),32, val)

#define SCOM_PUT32H(val)                  SCOM_INSERT(0, 32, val)
#define SCOM_PUT32L(val)                  SCOM_INSERT(32,32, val)
#define SCOM_GET32H(val)                  SCOM_EXTRACT(0, 32, val)
#define SCOM_GET32L(val)                  SCOM_EXTRACT(32,32, val)

// The following macros apply operations to a buffer to create a new data mask
// data previously stored in the buffer will be overwritten.
#define BUF_FLUSH(buf,mask)               buf.flush<mask>()
#define MMIO_ZERO                         BUF_FLUSH(BUF_MMIO,0)
#define MMIO_ALL1                         BUF_FLUSH(BUF_MMIO,1)
#define SCOM_ZERO                         BUF_FLUSH(BUF_SCOM,0)
#define SCOM_ALL1                         BUF_FLUSH(BUF_SCOM,1)

#define BUF_BITMASK(buf,mask,op,bit)      buf.flush<mask>().op##Bit<bit>()
#define MMIO_1BIT(bit)                    BUF_BITMASK(BUF_MMIO,0,set,bit)
#define MMIO_1ZERO(bit)                   BUF_BITMASK(BUF_MMIO,1,clear,bit)
#define SCOM_1BIT(bit)                    BUF_BITMASK(BUF_SCOM,0,set,bit)
#define SCOM_1ZERO(bit)                   BUF_BITMASK(BUF_SCOM,1,clear,bit)

#define BUF_LOAD(buf,mask,start,size,val) \
    buf.flush<mask>().insertFromRight<start,size>(val)
#define MMIO_ZEROS(start,size,val)        BUF_LOAD(BUF_MMIO,1,start,size,val)
#define MMIO_BITS(start,size,val)         BUF_LOAD(BUF_MMIO,0,start,size,val)
#define MMIO_LOAD32H(val)                 MMIO_BITS(0, 32,val)
#define MMIO_LOAD32L(val)                 MMIO_BITS(MMIO_LOWBIT(32), 32,val)

#define SCOM_ZEROS(start,size,val)        BUF_LOAD(BUF_SCOM,1,start,size,val)
#define SCOM_BITS(start,size,val)         BUF_LOAD(BUF_SCOM,0,start,size,val)
#define SCOM_LOAD32H(val)                 SCOM_BITS(0, 32,val)
#define SCOM_LOAD32L(val)                 SCOM_BITS(32,32,val)

#define BUF_LOAD2(buf,mask,start1,size1,val1,start2,size2,val2) \
    buf.flush<mask>().insertFromRight<start1,size1>(val1).insertFromRight<start2,size2>(val2)
#define SCOM_LOAD64(hword, lword)         BUF_LOAD2(BUF_SCOM,0,0,32,hword,32,32,lword)

//-------------------------
// Structs
//-------------------------

typedef struct
{
    uint32_t scomEntryAddress;
    uint64_t scomEntryData;
} __attribute__((packed)) ScomEntry_t;

//-------------------------
// Constants
//-------------------------

// Do NOT put any namespace in this or any Hcode related header or source files
// for general comptiablity to C source based code in PPE image
// Instead of namespace protection, here will always use unique HCD prefix
// in ALL namings that shouldnt be used outside of Hcode team.

enum P10_QME_SCOM_RESTORE_CONST
{
    SCOM_REST_SKIP_CODE = 0x60000000,
};

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
    HCD_POWER_CL2_OFF                        = 0x0, //000
    HCD_POWER_CL2_ON                         = 0x1, //001
    HCD_POWER_L3_OFF                         = 0x2, //010
    HCD_POWER_L3_ON                          = 0x3, //011
    HCD_POWER_MMA_OFF                        = 0x4, //100
    HCD_POWER_MMA_ON                         = 0x5, //101
    HCD_PFET_MMA_MASK                        = 0x4, //otherwise cl2 or l3
    HCD_PFET_L3_MASK                         = 0x2, //otherwise cl2
    HCD_PFET_ON_MASK                         = 0x1,  //otherwise off

// For SBE, the initial power-on times are not overly time critical so they are
// hardcoded for the delay necessary when running with the core at 4GHZ which has
// the QME logic area running off of a 2GHz grid.  When these same values are used
// with slower nest frequencies, the delays will get longer (more conservative).
//
// For istep 15, the delay settings are computed based on the setting of
// ATTR_FREQ_CORE_CEILING_MHZ.
//
// pfet_delay = (1/nest_frequency_mhz)*1000*4 (QME clock period in ns) *
//               2^(15-pfet_delay_value).
//
// or
//
//                                                pfet_delay
// 2^(15-pfet_delay_value) =           ------------------------------
//                                     (1/nest_frequency_mhz)*1000*4
//
//                                     pfet_delay * nest_frequency_mhz
// 2^(15-pfet_delay_value  =           ------------------------------
//                                                1000*4
//
//                                    ( pfet_delay * nest_frequency_mhz)
// 15-pfet_delay_value     =      log2(  ------------------------------)
//                                    (             1000*4             )
//
//                                    ( pfet_delay * nest_frequency_mhz)
// pfet_delay_value        = 15 - log2(  ------------------------------)
//                                    (             1000*4             )
//
//            ( pfet_delay * nest_frequency_mhz)
// logexp   = (  ------------------------------)
//            (             1000*4             )
//
//          = pfet_delay * nest_frequency_mhz / (1000 * 4)
//          = pfet_delay * (nest_frequency_mhz / (1000 * 4))
//          = pfet_delay * (2000 / (1000 * 4))
//          = pfet_delay * (.5)
//
// For core delay of 250ns per step, logexp = 250 * .5 = 125
//   --> log2(125) = 7 (rounded up to next integer)
//  -- > pfet_delay_value = 15 - 7 = 8
//
    HCD_PFET_DELAY_POWERDOWN                = 0xB,
#ifndef PRODUCT_DEFAULT_PFET_DELAYS
    HCD_PFET_DELAY_POWERUP_L3               = 0xB,
    HCD_PFET_DELAY_POWERUP_CL2              = 0xB,
    HCD_PFET_DELAY_POWERUP_MMA              = 0xB,
#else
    HCD_PFET_DELAY_POWERUP_L3               = 0x8,
    HCD_PFET_DELAY_POWERUP_CL2              = 0x8,
    HCD_PFET_DELAY_POWERUP_MMA              = 0x8
#endif
};

// Clock Control Constants
enum P10_HCD_CLK_CTRL_CONSTANTS
{
    HCD_CLK_STOP                                = BIT32(0),
    HCD_CLK_START                               = BIT32(1),
    HCD_CLK_SLAVE                               = BIT32(2),
    HCD_CLK_MASTER                              = BIT32(3),
    HCD_CLK_REGION_PERV                         = BIT32(4),
    HCD_CLK_REGION_ECL2                         = BITS32(5, 4),
    HCD_CLK_REGION_L3                           = BITS32(9, 4),
    HCD_CLK_REGION_QME                          = BIT32(13),
    HCD_CLK_REGION_CLKADJ                       = BIT32(14),
    HCD_CLK_REGION_MMA                          = BITS32(15, 4),
    HCD_CLK_REGION_EQ                           = (BIT32(4) | BITS32(13, 2)),
    HCD_CLK_REGION_ALL                          = BITS32(4, 15),
    HCD_CLK_THOLD_ALL                           = BITS64SH(48, 3),
    HCD_CLK_THOLD_SL                            = BIT64SH(48),
    HCD_CLK_THOLD_NSL                           = BIT64SH(49),
    HCD_CLK_THOLD_ARY                           = BIT64SH(50)
};

// Scan Type Constants
enum P10_HCD_SCAN_TYPE_CONSTANTS
{
    HCD_SCAN_TYPE_FUNC                          = BIT64(48),
    HCD_SCAN_TYPE_CFG                           = BIT64(49),
    HCD_SCAN_TYPE_CCFG_GPTR                     = BIT64(50),
    HCD_SCAN_TYPE_REGF                          = BIT64(51),
    HCD_SCAN_TYPE_LBIST                         = BIT64(52),
    HCD_SCAN_TYPE_ABIST                         = BIT64(53),
    HCD_SCAN_TYPE_REPR                          = BIT64(54),
    HCD_SCAN_TYPE_TIME                          = BIT64(55),
    HCD_SCAN_TYPE_BNDY                          = BIT64(56),
    HCD_SCAN_TYPE_FARR                          = BIT64(57),
    HCD_SCAN_TYPE_CMSK                          = BIT64(58),
    HCD_SCAN_TYPE_INEX                          = BIT64(59)
};

// Scan Flush Constants
enum P10_HCD_SCAN0_CONSTANTS
{
    HCD_SCAN0_REGION_ALL                        = 0x7FF,
    HCD_SCAN0_REGION_ALL_BUT_PLL                = 0x7FE,
    HCD_SCAN0_TYPE_GPTR_REPR_TIME               = 0x230,
    HCD_SCAN0_TYPE_ALL_BUT_GPTR_REPR_TIME       = 0xDCF
};

// XSR defines
enum XSR_DEFS
{
    XSR_HALTED_STATE         = 0,
    XSR_HALT_CONDITION_START = 1,
    XSR_HALT_CONDITION_LEN   = 3,
    XSR_XCR_CMD_HALT         = 1,
    XSR_WDT_HALT             = 2,
    XSR_UMI_HALT             = 3,
    XSR_DEBUG_HALT           = 4,
    XSR_DBCR_HALT            = 5,
    XSR_INPUT_HALT           = 6,
    XSR_HW_FAILURE           = 7
};

// XCR defines
enum XCR_DEFS
{
    XCR_CLEAR_DEBUG_STATUS  = 0,
    XCR_HALT                = 1,
    XCR_RESUME              = 2,
    XCR_SINGLE_STEP         = 3,
    XCR_TOGGLE_XSR_TRH      = 4,
    XCR_SOFT_RESET          = 5,
    XCR_HARD_RESET          = 6,
    XCR_FORCE_HALT          = 7
};


/**
 * @brief  various SCOM operations supported for QME
 */
enum QME_SCOM_CONTROLS
{
    QME_SCOM_NOP                    = 0,
    QME_SCOM_OR                     = 1,
    QME_SCOM_AND                    = 2,
    QME_SCOM_QUEUED                 = 3
};

#endif  // __P10_HCD_COMMON_H__
