/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/lib/p9_hcd_common.H $                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
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
#define BITS16(b, n) ((0xffff                << (16 - (n))) >> (b))
#define BITS8(b, n)  ((0xff                  << (8  - (n))) >> (b))

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

// Constants to work with fapi2target
enum P9_HCD_TARGET_CONSTANTS
{
    PERV_TO_EQ_POS_OFFSET   = 0x10,
    PERV_TO_CORE_POS_OFFSET = 0x20
};

// Init Vectors for Register Setup
enum P9_HCD_COMMON_INIT_VECTORS
{
    // 1     -  PCB_EP_RESET
    // 2     -  SKEW_ADJUST_RESET
    // 3     -  PLL_TEST_EN
    // 4     -  PLLRST
    // 5     -  PLLBYP
    // 11    -  EDIS
    // 12    -  VITL_MPW1
    // 13    -  VITL_MPW2
    // 14    -  VITL_MPW3
    // 18    -  FENCE_EN
    // 22    -  SKEW_ADJUST_FUNC_CLKSEL
    // 26    -  LVLTRANS_FENCE
    Q_NET_CTRL0_INIT_VECTOR = (BITS64(1, 5) | BITS64(11, 4) |
                               BIT64(18) | BIT64(22) | BIT64(26)),
    C_NET_CTRL0_INIT_VECTOR = (BIT64(1) | BITS64(3, 3) | BITS64(11, 4) |
                               BIT64(18) | BIT64(22) | BIT64(26)),
};

// Clock Control Constants
enum P9_HCD_COMMON_CLK_CTRL_CONSTANTS
{
    CLK_STOP_CMD                             = BIT64(0),
    CLK_START_CMD                            = BIT64(1),
    CLK_SLAVE_MODE                           = BIT64(2),
    CLK_MASTER_MODE                          = BIT64(3),
    CLK_REGION_ANEP                          = BIT64(10),
    CLK_REGION_DPLL                          = BIT64(14),
    CLK_REGION_ALL_BUT_EX_DPLL               = BITS64(4, 2) | BITS64(10, 2),
    CLK_REGION_EX0_L2_L3_REFR                = BIT64(6) | BIT64(8) | BIT64(12),
    CLK_REGION_EX1_L2_L3_REFR                = BIT64(7) | BIT64(9) | BIT64(13),
    CLK_REGION_ALL                           = BITS64(4, 11),
    CLK_REGION_NONE                          = 0,
    CLK_THOLD_ALL                            = BITS64(48, 3),
    CLK_THOLD_NSL_ARY                        = BITS64(49, 2)
};

// Clock Control Vectors
enum P9_HCD_COMMON_CLK_CTRL_VECTORS
{
    CLK_START_REGION_ALL_THOLD_NSL_ARY =
        (CLK_START_CMD | CLK_REGION_ALL | CLK_THOLD_NSL_ARY),
    CLK_START_REGION_ALL_THOLD_ALL =
        (CLK_START_CMD | CLK_REGION_ALL | CLK_THOLD_ALL),
    CLK_START_REGION_NONE_THOLD_NSL_ARY =
        (CLK_START_CMD | CLK_REGION_NONE | CLK_THOLD_NSL_ARY),
    CLK_START_REGION_NONE_THOLD_ALL =
        (CLK_START_CMD | CLK_REGION_NONE | CLK_THOLD_ALL),
    CLK_START_REGION_DPLL_THOLD_NSL_ARY =
        (CLK_START_CMD | CLK_REGION_DPLL | CLK_THOLD_NSL_ARY),
    CLK_START_REGION_DPLL_THOLD_ALL =
        (CLK_START_CMD | CLK_REGION_DPLL | CLK_THOLD_ALL),
    CLK_START_REGION_ANEP_THOLD_NSL_ARY =
        (CLK_START_CMD | CLK_REGION_ANEP | CLK_THOLD_NSL_ARY),
    CLK_START_REGION_ANEP_THOLD_ALL =
        (CLK_START_CMD | CLK_REGION_ANEP | CLK_THOLD_ALL)
};

// SCAN0 Constants
enum P9_HCD_COMMON_SCAN0_CONSTANTS
{
    SCAN0_REGION_ALL                         = 0x7FF,
    SCAN0_REGION_ALL_BUT_EX                  = 0x619,
    SCAN0_REGION_ALL_BUT_EX_DPLL             = 0x618,
    SCAN0_REGION_ALL_BUT_EX_ANEP_DPLL        = 0x608,
    SCAN0_REGION_EX0_L2_L3_REFR              = 0x144,
    SCAN0_REGION_EX1_L2_L3_REFR              = 0x0A2,
    SCAN0_REGION_DPLL                        = 0x001,
    SCAN0_REGION_ANEP_DPLL                   = 0x011,
    SCAN0_REGION_CORE_ONLY                   = 0x300,
    SCAN0_REGION_PERV_CORE                   = 0x700,
    SCAN0_TYPE_ALL_BUT_GPTR_REPR_TIME        = 0xDCF,
    SCAN0_TYPE_ALL_BUT_GPTR                  = 0xDFF,
    SCAN0_TYPE_GPTR_REPR_TIME                = 0x230,
    SCAN0_TYPE_REPR_TIME                     = 0x030,
    SCAN0_TYPE_GPTR                          = 0x200,
    SCAN0_TYPE_FUNC                          = 0x800,
    SCAN0_TYPE_FUNC_BNDY                     = 0x808
};

//OCC FLag defines
enum PM_GPE_OCCFLG_DEFS
{
    SGPE_ACTIVE    = 8
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


} // END OF NAMESPACE p9hcd


/// @todo needs to review this
/// SCAN Repeats(from P8)
/*
#define GENERIC_CC_SCAN0_MAXIMUM   8191
#define SCAN0_FUNC_FLUSH_LENGTH    8000
#define SCAN0_GPTR_FLUSH_LENGTH    14000
#define P9_HCD_SCAN_FUNC_REPEAT    \
    ((SCAN0_FUNC_FLUSH_LENGTH / GENERIC_CC_SCAN0_MAXIMUM)+1)
#define P9_HCD_SCAN_GPTR_REPEAT    \
    ((SCAN0_GPTR_FLUSH_LENGTH / GENERIC_CC_SCAN0_MAXIMUM)+1)
*/
#define P9_HCD_SCAN_FUNC_REPEAT 40
#define P9_HCD_SCAN_GPTR_REPEAT 40

/// @todo remove these once correct header contains them
/// Scom addresses missing from p9_quad_scom_addresses.H
#define EQ_QPPM_QCCR_WOR                 0x100F01BF
#define CME_LCL_SICR_OR                  0xc0000510
#define CME_LCL_SICR_CLR                 0xc0000518
#define CME_LCL_SISR                     0xc0000520

#endif  // __P9_HCD_COMMON_H__
