/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/common/include/centaur_misc_constants.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file centaur_misc_scom_addresses.H
/// @brief  Defines constants for common used data.
///
// *HWP HWP Owner: Peng Fei GOU <shgoupf@cn.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: SOA
// *HWP Level: 2
// *HWP Consumed by: FSP:HB:HS:OCC:SBE:CME:SGPE:PGPE:FPPE:IPPE

#include <p9_const_common.H>

#ifndef __CENTAUR_MISC_CONSTANTS_H
#define __CENTAUR_MISC_CONSTANTS_H

#define CFAM_STATUS_RESET_DATA  0xFFFFFFFF
#define CFAM_FSI_GP3_RESET_DATA 0x00000FFB
#define CFAM_FSI_GP4_RESET_DATA 0x0000C280
#define CFAM_FSI_GP5_RESET_DATA 0x00000100
#define CFAM_FSI_GP6_RESET_DATA 0x00000000
#define CFAM_FSI_GP7_RESET_DATA 0x00000000

#define PERV_GP3_RESET_DATA 0x44166000

#define MAX_FLUSH_LOOPS  400
#define MAX_REPAIR_POLL_LOOPS  100
#define SIM_FLUSH_DELAY  400000
#define NANO_FLUSH_DELAY 10000

#define MULTI_CAST_PATTERN 0x0000000000000078
#define MULTI_CAST_COMPARE 0x0000000000000068
#define MULTI_CAST_READ_OP 0x0000000000000047
#define MULTI_CAST_WAIT_WR 0x000000000000005F

#define SCAN_TP_ARRAY_INIT_REGIONS         0x09000e0000000000
#define SCAN_TP_REGIONS_EXCEPT_PIB_PCB     0x09e00e0000000000
#define SCAN_TP_SCAN_SELECTS               0x09e00dce00000000
#define SCAN_TP_PLL_REGIONS                0x08100E0000000000

#define SCAN_REGION_TP_PLL_GPTR            0x0810020000000000
#define SCAN_REGION_TP_PLL_BNDY_FUNC       0x0810080800000000

#define SCAN_CLK_ALL_BUT_PLL               0x0FE00E0000000000
#define SCAN_GPTR_TIME_REP_NO_PLL          0x0FE0023000000000
#define SCAN_ALL_BUT_VITALPLLGPTRTIME      0x0FE00DCE00000000
#define SCAN_ALL_BUT_VITALDPLLGPTRTIME     0x0FE00DCE00000000
#define SCAN_GPTR_TIME_REP                 0x0FF0023000000000
#define SCAN_ALLSCANEXPRV                  0x0FF00DCE00000000
#define SCAN_ALLREGIONEXVITAL              0x0FF00E0000000000

#define SCAN_STBY_CHIPLET                  RULL(0x00)
#define SCAN_CHIPLET_TP                    RULL(0x01)
#define SCAN_CHIPLET_NEST                  RULL(0x02)
#define SCAN_CHIPLET_MEM                   RULL(0x03)
#define SCAN_CHIPLET_GROUP1                RULL(0x69)
#define SCAN_CHIPLET_GROUP3                RULL(0x6B)

#define CLOCK_START_REGIONS_all            0x4FE00E0000000000
#define EXPECTED_CC_STATUS_START_all       0x000007FFFFFFFFFF

#define REPAIR_COMMAND_VALIDATION_ENTRIES_DD1             0xFE0 // control words 0-6
#define REPAIR_COMMAND_VALIDATION_ENTRIES_DD2             0xFE4 // control words 0-6,9
#define REPAIR_COMMAND_VALIDATION_ENTRY_TCN_REFR_TIME_DD2 0x008 // control word 8
#define REPAIR_COMMAND_START_ADDRESS                      0x27F
#define REPAIR_STATUS_POLL_MASK 0xA400038000000000
#define REPAIR_STATUS_POLL_BUSY1 0xA000000000000000
#define REPAIR_STATUS_POLL_BUSY2 0x8000000000000000

#define REPAIR_CMD_VALIDATION_ENTRIES      0x010
#define REPAIR_CMD_START_ADDR              0x27F
#define REPAIR_ECC_TRAP_MASK               0x0F00300000000000
#define REPAIR_ECC_TRAP_EXP                0x0000300000000000
#define REPAIR_STATUS_CHECK_MASK           0xA6FFFF8000000000
#define REPAIR_STATUS_CHECK_EXP            0x2080000000000000
#define CLOCK_START_REGIONS_PIBNET         0x46000E0000000000
#define STRT_CLK_REGION_NSL                0x4FE0060000000000
#define STRT_CLK_REGION_SL                 0x4FE00E0000000000
#define EXPECTED_CLK_STATUS                0x0000001FFFFFFFFF

#define EXPECTED_CC_STATUS_START_PIBNET    0xE07FFFFFFFFFFFFF

#endif

