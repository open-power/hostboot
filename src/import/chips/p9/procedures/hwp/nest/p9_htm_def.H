/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_htm_def.H $                   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/// ----------------------------------------------------------------------------
/// @file  p9_htm_def.H
///
/// @brief Common definitions for HTM related values in P9
///
/// ----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 2
/// *HWP Consumed by : HB
/// ----------------------------------------------------------------------------
#ifndef _P9_HTM_DEF_H_
#define _P9_HTM_DEF_H_

//----------------------------------------------------------------------------
// Include
//----------------------------------------------------------------------------
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>
#include <p9_quad_scom_addresses.H>
#include <p9_quad_scom_addresses_fld.H>

//----------------------------------------------------------------------------
// Constant definitions
//----------------------------------------------------------------------------
const uint8_t NUM_NHTM_ENGINES         = 2;
const uint8_t NUM_CHTM_ENGINES         = 24;
const uint8_t NUM_CHTM_REG_MAP_INDEX   = 2;
const uint32_t P9_HTM_CTRL_TIMEOUT_COUNT  = 20;   // HTM control time-out

// HTM operations delay times for HW/sim
const uint32_t P9_HTM_CTRL_HW_NS_DELAY     = 50000;
const uint32_t P9_HTM_CTRL_SIM_CYCLE_DELAY = 50000;

// NHTM
constexpr uint64_t NHTM_modeRegList[NUM_NHTM_ENGINES] =
{
    PU_HTM0_HTM_MODE,
    PU_HTM1_HTM_MODE
};

// CHTM
// Note: Absolute HTM_MODE reg addresses
//       EX_0_HTM_MODE,             // EX0,  core 0      0x10012200
//       EX_0_HTM_MODE + 0x100,     // EX0,  core 1      0x10012300
//       EX_1_CHTMLBS0_HTM_MODE,    // EX1,  core 2      0x10012600
//       EX_1_CHTMLBS1_HTM_MODE,    // EX1,  core 3      0x10012700
//       EX_2_HTM_MODE,             // EX2,  core 4      0x11012200
//       EX_2_HTM_MODE + 0x100,     // EX2,  core 5      0x11012300
//       EX_3_CHTMLBS0_HTM_MODE,    // EX3,  core 6      0x11012600
//       EX_3_CHTMLBS1_HTM_MODE,    // EX3,  core 7      0x11012700
//       EX_4_HTM_MODE,             // EX4,  core 8      0x12012200
//       EX_4_HTM_MODE + 0x100,     // EX4,  core 9      0x12012300
//       EX_5_CHTMLBS0_HTM_MODE,    // EX5,  core 10     0x12012600
//       EX_5_CHTMLBS1_HTM_MODE,    // EX5,  core 11     0x12012700
//       EX_6_HTM_MODE,             // EX6,  core 12     0x13012200
//       EX_6_HTM_MODE + 0x100,     // EX6,  core 13     0x13012300
//       EX_7_CHTMLBS0_HTM_MODE,    // EX7,  core 14     0x13012600
//       EX_7_CHTMLBS1_HTM_MODE,    // EX7,  core 15     0x13012700
//       EX_8_HTM_MODE,             // EX8,  core 16     0x14012200
//       EX_8_HTM_MODE + 0x100,     // EX8,  core 17     0x14012300
//       EX_9_CHTMLBS0_HTM_MODE,    // EX9,  core 18     0x14012600
//       EX_9_CHTMLBS1_HTM_MODE,    // EX9,  core 19     0x14012700
//       EX_10_HTM_MODE,            // EX10, core 20     0x15012200
//       EX_10_HTM_MODE + 0x100,    // EX10, core 21     0x15012300
//       EX_11_CHTMLBS0_HTM_MODE,   // EX11, core 22     0x15012600
//       EX_11_CHTMLBS1_HTM_MODE    // EX11, core 23     0x15012700
//
// Note: use EX0 to let scom translation getting the absolute address
//
constexpr uint64_t CHTM_modeReg[NUM_CHTM_REG_MAP_INDEX] =
{
    EX_0_HTM_MODE,             // Any EX core 0
    EX_0_HTM_MODE + 0x100
};   // Any EX core 1

//-----------------
// Register offsets
//-----------------
// Register offsets from HTM Collection Mode Register, for NHTM and CHTM
const uint32_t HTM_MODE = 0x0;
const uint32_t HTM_MEM  = 0x1;
const uint32_t HTM_STAT = 0x2;
const uint32_t HTM_LAST = 0x3;
const uint32_t HTM_TRIG = 0x4;
const uint32_t HTM_CTRL = 0x5;

// Register offsets from HTM Collection Mode Register, for NHTM only
const uint32_t NHTM_FILT       = 0x6;
const uint32_t NHTM_TTYPE_FILT = 0x7;
const uint32_t NHTM_CFG        = 0x8;

// Register offsets from HTM Collection Mode Register, for CHTM only
const uint32_t HTM_IMA_STATUS  = 0x0A;
const uint32_t CHTM_PDBAR      = 0x0B;

#endif // _P9_HTM_DEF_H_
