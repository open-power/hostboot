/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/include/p9a_perv_scom_addresses_fld.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file p9a_perv_scom_addresses_fld.H
/// @brief  Defines constants for scom addresses
///
// *HWP HWP Owner: Ben Gass <bgass@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: SOA
// *HWP Level: 1
// *HWP Consumed by: FSP:HB:HS:OCC:SBE:CME:SGPE:PGPE:FPPE:IPPE


#ifndef __P9A_PERV_SCOM_ADDRESSES_FLD_H
#define __P9A_PERV_SCOM_ADDRESSES_FLD_H



static const uint8_t P9A_PERV_1_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR = 0   ;
static const uint8_t P9A_PERV_1_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN = 16  ;
static const uint8_t P9A_PERV_1_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR = 16  ;
static const uint8_t P9A_PERV_1_ADDR_TRAP_REG_RESERVED_LAST_LT               = 17  ;
static const uint8_t P9A_PERV_1_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR = 18  ;
static const uint8_t P9A_PERV_1_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN = 13  ;
static const uint8_t P9A_PERV_1_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY = 31  ;
static const uint8_t P9A_PERV_1_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR = 32  ;
static const uint8_t P9A_PERV_1_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION = 33  ;
static const uint8_t P9A_PERV_1_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER = 34  ;

static const uint8_t P9A_PERV_1_ASSIST_INTERRUPT_REG_ATTN                    = 0   ;
static const uint8_t P9A_PERV_1_ASSIST_INTERRUPT_REG_RECOV                   = 1   ;
static const uint8_t P9A_PERV_1_ASSIST_INTERRUPT_REG_XSTOP                   = 2   ;

static const uint8_t P9A_PERV_1_ATOMIC_LOCK_MASK_LATCH_REG_MASK              = 0   ;
static const uint8_t P9A_PERV_1_ATOMIC_LOCK_MASK_LATCH_REG_MASK_LEN          = 16  ;

static const uint8_t P9A_PERV_1_ATOMIC_LOCK_REG_ENABLE                       = 0   ;
static const uint8_t P9A_PERV_1_ATOMIC_LOCK_REG_ID                           = 1   ;
static const uint8_t P9A_PERV_1_ATOMIC_LOCK_REG_ID_LEN                       = 4   ;
static const uint8_t P9A_PERV_1_ATOMIC_LOCK_REG_ACTIVITY                     = 8   ;
static const uint8_t P9A_PERV_1_ATOMIC_LOCK_REG_ACTIVITY_LEN                 = 8   ;

static const uint8_t P9A_PERV_1_ATTN_INTERRUPT_REG_ATTN                      = 0   ;

static const uint8_t P9A_PERV_1_BIST_TC_START_TEST_DC                        = 0   ;
static const uint8_t P9A_PERV_1_BIST_TC_SRAM_ABIST_MODE_DC                   = 1   ;
static const uint8_t P9A_PERV_1_BIST_TC_EDRAM_ABIST_MODE_DC                  = 2   ;
static const uint8_t P9A_PERV_1_BIST_TC_IOBIST_MODE_DC                       = 3   ;
static const uint8_t P9A_PERV_1_BIST_PERV                                    = 4   ;
static const uint8_t P9A_PERV_1_BIST_UNIT1                                   = 5   ;
static const uint8_t P9A_PERV_1_BIST_UNIT2                                   = 6   ;
static const uint8_t P9A_PERV_1_BIST_UNIT3                                   = 7   ;
static const uint8_t P9A_PERV_1_BIST_UNIT4                                   = 8   ;
static const uint8_t P9A_PERV_1_BIST_UNIT5                                   = 9   ;
static const uint8_t P9A_PERV_1_BIST_UNIT6                                   = 10  ;
static const uint8_t P9A_PERV_1_BIST_UNIT7                                   = 11  ;
static const uint8_t P9A_PERV_1_BIST_UNIT8                                   = 12  ;
static const uint8_t P9A_PERV_1_BIST_UNIT9                                   = 13  ;
static const uint8_t P9A_PERV_1_BIST_UNIT10                                  = 14  ;
static const uint8_t P9A_PERV_1_BIST_STROBE_WINDOW_EN                        = 48  ;

static const uint8_t P9A_PERV_BIT_SEL_REG_2_SELECT_REGISTER_FSP2PIB          = 0   ;
static const uint8_t P9A_PERV_BIT_SEL_REG_2_SELECT_REGISTER_FSP2PIB_LEN      = 6   ;

static const uint8_t P9A_PERV_CBS_CS_START_BOOT_SEQUENCER                    = 0   ;
static const uint8_t P9A_PERV_CBS_CS_1_UNUSED                                = 1   ;
static const uint8_t P9A_PERV_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART            = 2   ;
static const uint8_t P9A_PERV_CBS_CS_OPTION_PREVENT_SBE_START                = 3   ;
static const uint8_t P9A_PERV_CBS_CS_SECURE_ACCESS_BIT                       = 4   ;
static const uint8_t P9A_PERV_CBS_CS_SAMPLED_SMD_PIN                         = 5   ;
static const uint8_t P9A_PERV_CBS_CS_STATE_MACHINE_TRANSITION_DELAY          = 6   ;
static const uint8_t P9A_PERV_CBS_CS_STATE_MACHINE_TRANSITION_DELAY_LEN      = 10  ;
static const uint8_t P9A_PERV_CBS_CS_INTERNAL_STATE_VECTOR                   = 16  ;
static const uint8_t P9A_PERV_CBS_CS_INTERNAL_STATE_VECTOR_LEN               = 16  ;

static const uint8_t P9A_PERV_CBS_EL_ENVSTAT_CHANGE                          = 0   ;
static const uint8_t P9A_PERV_CBS_EL_ENVSTAT_CHANGE_LEN                      = 16  ;
static const uint8_t P9A_PERV_CBS_EL_PGOOD_DROP_DURING                       = 16  ;
static const uint8_t P9A_PERV_CBS_EL_PGOOD_DROP_AFTER                        = 17  ;
static const uint8_t P9A_PERV_CBS_EL_CTRL_WRITE_DURING                       = 18  ;
static const uint8_t P9A_PERV_CBS_EL_INVALID_STATE                           = 19  ;
static const uint8_t P9A_PERV_CBS_EL_PGOOD_LOW_WHILE_UNFENCED                = 24  ;

static const uint8_t P9A_PERV_CBS_ENVSTAT_C4_TEST_ENABLE                     = 0   ;
static const uint8_t P9A_PERV_CBS_ENVSTAT_C4_CARD_TEST_BSC                   = 1   ;
static const uint8_t P9A_PERV_CBS_ENVSTAT_C4_VDN_GPOOD                       = 2   ;
static const uint8_t P9A_PERV_CBS_ENVSTAT_C4_FSI_IN_ENA                      = 3   ;
static const uint8_t P9A_PERV_CBS_ENVSTAT_C4_CHIP_MASTER                     = 4   ;
static const uint8_t P9A_PERV_CBS_ENVSTAT_C4_SMD                             = 5   ;
static const uint8_t P9A_PERV_CBS_ENVSTAT_C4_JTAG_TMS                        = 6   ;
static const uint8_t P9A_PERV_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER              = 7   ;
static const uint8_t P9A_PERV_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER_LEN          = 25  ;

static const uint8_t P9A_PERV_CBS_STAT_DBG_RESET_EP                          = 0   ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_OPCG_IP                           = 1   ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_VITL_CLKOFF                       = 2   ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_TEST_ENABLE                       = 3   ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_REQ                               = 4   ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_CMD                               = 5   ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_CMD_LEN                           = 3   ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_STATE                             = 8   ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_STATE_LEN                         = 5   ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_SECURITY_DEBUG_MODE               = 13  ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_PROTOCOL_ERROR                    = 14  ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_PCB_IDLE                          = 15  ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_CURRENT_OPCG_MODE                 = 16  ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_CURRENT_OPCG_MODE_LEN             = 4   ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_LAST_OPCG_MODE                    = 20  ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_LAST_OPCG_MODE_LEN                = 4   ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_PCB_ERROR                         = 24  ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_PARITY_ERROR                      = 25  ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_CC_ERROR                          = 26  ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_CHIPLET_IS_ALIGNED                = 27  ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_PCB_REQUEST_SINCE_RESET           = 28  ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_PARANOIA_TEST_ENABLE_CHANGE       = 29  ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_PARANOIA_VITL_CLKOFF_CHANGE       = 30  ;
static const uint8_t P9A_PERV_CBS_STAT_DBG_TP_TPFSI_ACK                      = 31  ;

static const uint8_t P9A_PERV_CBS_TR_SIGNATURE                               = 0   ;
static const uint8_t P9A_PERV_CBS_TR_SIGNATURE_LEN                           = 16  ;
static const uint8_t P9A_PERV_CBS_TR_UNUSED                                  = 16  ;
static const uint8_t P9A_PERV_CBS_TR_UNUSED_LEN                              = 6   ;
static const uint8_t P9A_PERV_CBS_TR_TRANS_DELAY                             = 22  ;
static const uint8_t P9A_PERV_CBS_TR_TRANS_DELAY_LEN                         = 10  ;

static const uint8_t P9A_PERV_1_CC_ATOMIC_LOCK_REG_ENABLE                    = 0   ;
static const uint8_t P9A_PERV_1_CC_ATOMIC_LOCK_REG_ID                        = 1   ;
static const uint8_t P9A_PERV_1_CC_ATOMIC_LOCK_REG_ID_LEN                    = 4   ;
static const uint8_t P9A_PERV_1_CC_ATOMIC_LOCK_REG_ACTIVITY                  = 8   ;
static const uint8_t P9A_PERV_1_CC_ATOMIC_LOCK_REG_ACTIVITY_LEN              = 8   ;

static const uint8_t P9A_PERV_1_CC_PROTECT_MODE_REG_READ_ENABLE              = 0   ;
static const uint8_t P9A_PERV_1_CC_PROTECT_MODE_REG_WRITE_ENABLE             = 1   ;

static const uint8_t P9A_PERV_1_CLK_REGION_CLOCK_CMD                         = 0   ;
static const uint8_t P9A_PERV_1_CLK_REGION_CLOCK_CMD_LEN                     = 2   ;
static const uint8_t P9A_PERV_1_CLK_REGION_SLAVE_MODE                        = 2   ;
static const uint8_t P9A_PERV_1_CLK_REGION_MASTER_MODE                       = 3   ;
static const uint8_t P9A_PERV_1_CLK_REGION_CLOCK_PERV                        = 4   ;
static const uint8_t P9A_PERV_1_CLK_REGION_CLOCK_UNIT1                       = 5   ;
static const uint8_t P9A_PERV_1_CLK_REGION_CLOCK_UNIT2                       = 6   ;
static const uint8_t P9A_PERV_1_CLK_REGION_CLOCK_UNIT3                       = 7   ;
static const uint8_t P9A_PERV_1_CLK_REGION_CLOCK_UNIT4                       = 8   ;
static const uint8_t P9A_PERV_1_CLK_REGION_CLOCK_UNIT5                       = 9   ;
static const uint8_t P9A_PERV_1_CLK_REGION_CLOCK_UNIT6                       = 10  ;
static const uint8_t P9A_PERV_1_CLK_REGION_CLOCK_UNIT7                       = 11  ;
static const uint8_t P9A_PERV_1_CLK_REGION_CLOCK_UNIT8                       = 12  ;
static const uint8_t P9A_PERV_1_CLK_REGION_CLOCK_UNIT9                       = 13  ;
static const uint8_t P9A_PERV_1_CLK_REGION_CLOCK_UNIT10                      = 14  ;
static const uint8_t P9A_PERV_1_CLK_REGION_SEL_THOLD_SL                      = 48  ;
static const uint8_t P9A_PERV_1_CLK_REGION_SEL_THOLD_NSL                     = 49  ;
static const uint8_t P9A_PERV_1_CLK_REGION_SEL_THOLD_ARY                     = 50  ;
static const uint8_t P9A_PERV_1_CLK_REGION_CLOCK_PULSE_USE_EVEN              = 52  ;

static const uint8_t P9A_PERV_1_CLOCK_STAT_ARY_STATUS_PERV                   = 4   ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_ARY_STATUS_UNIT1                  = 5   ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_ARY_STATUS_UNIT2                  = 6   ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_ARY_STATUS_UNIT3                  = 7   ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_ARY_STATUS_UNIT4                  = 8   ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_ARY_STATUS_UNIT5                  = 9   ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_ARY_STATUS_UNIT6                  = 10  ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_ARY_STATUS_UNIT7                  = 11  ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_ARY_STATUS_UNIT8                  = 12  ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_ARY_STATUS_UNIT9                  = 13  ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_ARY_STATUS_UNIT10                 = 14  ;

static const uint8_t P9A_PERV_1_CLOCK_STAT_NSL_STATUS_PERV                   = 4   ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_NSL_STATUS_UNIT1                  = 5   ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_NSL_STATUS_UNIT2                  = 6   ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_NSL_STATUS_UNIT3                  = 7   ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_NSL_STATUS_UNIT4                  = 8   ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_NSL_STATUS_UNIT5                  = 9   ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_NSL_STATUS_UNIT6                  = 10  ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_NSL_STATUS_UNIT7                  = 11  ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_NSL_STATUS_UNIT8                  = 12  ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_NSL_STATUS_UNIT9                  = 13  ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_NSL_STATUS_UNIT10                 = 14  ;

static const uint8_t P9A_PERV_1_CLOCK_STAT_SL_STATUS_PERV                    = 4   ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_SL_STATUS_UNIT1                   = 5   ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_SL_STATUS_UNIT2                   = 6   ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_SL_STATUS_UNIT3                   = 7   ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_SL_STATUS_UNIT4                   = 8   ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_SL_STATUS_UNIT5                   = 9   ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_SL_STATUS_UNIT6                   = 10  ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_SL_STATUS_UNIT7                   = 11  ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_SL_STATUS_UNIT8                   = 12  ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_SL_STATUS_UNIT9                   = 13  ;
static const uint8_t P9A_PERV_1_CLOCK_STAT_SL_STATUS_UNIT10                  = 14  ;

static const uint8_t P9A_PERV_PIB2OPB1_CMD_WRDAT_WRITE_NOT_READ              = 0   ;
static const uint8_t P9A_PERV_PIB2OPB1_CMD_WRDAT_CMD                         = 1   ;
static const uint8_t P9A_PERV_PIB2OPB1_CMD_WRDAT_CMD_LEN                     = 31  ;
static const uint8_t P9A_PERV_PIB2OPB1_CMD_WRDAT_WDATA                       = 32  ;
static const uint8_t P9A_PERV_PIB2OPB1_CMD_WRDAT_WDATA_LEN                   = 32  ;

static const uint8_t P9A_PERV_CMD_WRDAT_WRITE_NOT_READ                       = 0   ;
static const uint8_t P9A_PERV_CMD_WRDAT_CMD                                  = 1   ;
static const uint8_t P9A_PERV_CMD_WRDAT_CMD_LEN                              = 31  ;
static const uint8_t P9A_PERV_CMD_WRDAT_WDATA                                = 32  ;
static const uint8_t P9A_PERV_CMD_WRDAT_WDATA_LEN                            = 32  ;

static const uint8_t P9A_PERV_PIB2OPB0_CMD_WRDAT_WRITE_NOT_READ              = 0   ;
static const uint8_t P9A_PERV_PIB2OPB0_CMD_WRDAT_CMD                         = 1   ;
static const uint8_t P9A_PERV_PIB2OPB0_CMD_WRDAT_CMD_LEN                     = 31  ;
static const uint8_t P9A_PERV_PIB2OPB0_CMD_WRDAT_WDATA                       = 32  ;
static const uint8_t P9A_PERV_PIB2OPB0_CMD_WRDAT_WDATA_LEN                   = 32  ;

static const uint8_t P9A_PERV_FSI2PIB_COMMAND_REGISTER_CMD_REG               = 0   ;
static const uint8_t P9A_PERV_FSI2PIB_COMMAND_REGISTER_CMD_REG_LEN           = 32  ;

static const uint8_t P9A_PERV_COMMAND_REGISTER_CMD_REG_BIT_WITHSTART         = 0   ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_CMD_REG_BIT_WITHADDR          = 1   ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_CMD_REG_BIT_READCONT          = 2   ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_CMD_REG_BIT_WITHSTOP          = 3   ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_CMD_REG_LENGTH                = 4   ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_CMD_REG_LENGTH_LEN            = 4   ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_UNUSED_8_14                   = 8   ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_UNUSED_8_14_LEN               = 7   ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_CMD_REG_BIT_RNW               = 15  ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_UNUSED_16_22                  = 16  ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_UNUSED_16_22_LEN              = 7   ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_REG_ADDR_LENGTH               = 23  ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_REG_ADDR_LENGTH_LEN           = 3   ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_UNUSED_26_31                  = 26  ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_UNUSED_26_31_LEN              = 6   ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_CMD_REG_ADDR_1                = 32  ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_CMD_REG_ADDR_1_LEN            = 8   ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_CMD_REG_ADDR_2                = 40  ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_CMD_REG_ADDR_2_LEN            = 8   ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_CMD_REG_ADDR_3                = 48  ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_CMD_REG_ADDR_3_LEN            = 8   ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_CMD_REG_ADDR_4                = 56  ;
static const uint8_t P9A_PERV_COMMAND_REGISTER_CMD_REG_ADDR_4_LEN            = 8   ;

static const uint8_t P9A_PERV_FSISHIFT_COMMAND_REGISTER_CMDREG_WRITE_FLAG    = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_COMMAND_REGISTER_CMDREG_BROADCAST_FLAG = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_COMMAND_REGISTER_CMDREG_SCAN_ADDRESS  = 2   ;
static const uint8_t P9A_PERV_FSISHIFT_COMMAND_REGISTER_CMDREG_SCAN_ADDRESS_LEN = 14  ;
static const uint8_t P9A_PERV_FSISHIFT_COMMAND_REGISTER_CMDREG_SCAN_REGION   = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_COMMAND_REGISTER_CMDREG_SCAN_REGION_LEN = 12  ;
static const uint8_t P9A_PERV_FSISHIFT_COMMAND_REGISTER_CMDREG_SCAN_TYPE     = 28  ;
static const uint8_t P9A_PERV_FSISHIFT_COMMAND_REGISTER_CMDREG_SCAN_TYPE_LEN = 4   ;

static const uint8_t P9A_PERV_FSII2C_COMMAND_REGISTER_A_WITH_START_0         = 0   ;
static const uint8_t P9A_PERV_FSII2C_COMMAND_REGISTER_A_WITH_ADDRESS_0       = 1   ;
static const uint8_t P9A_PERV_FSII2C_COMMAND_REGISTER_A_READ_CONTINUE_0      = 2   ;
static const uint8_t P9A_PERV_FSII2C_COMMAND_REGISTER_A_WITH_STOP_0          = 3   ;
static const uint8_t P9A_PERV_FSII2C_COMMAND_REGISTER_A_NOT_USED_0           = 4   ;
static const uint8_t P9A_PERV_FSII2C_COMMAND_REGISTER_A_NOT_USED_0_LEN       = 4   ;
static const uint8_t P9A_PERV_FSII2C_COMMAND_REGISTER_A_DEVICE_ADDRESS_0     = 8   ;
static const uint8_t P9A_PERV_FSII2C_COMMAND_REGISTER_A_DEVICE_ADDRESS_0_LEN = 7   ;
static const uint8_t P9A_PERV_FSII2C_COMMAND_REGISTER_A_READ_NOT_WRITE_0     = 15  ;
static const uint8_t P9A_PERV_FSII2C_COMMAND_REGISTER_A_LENGTH_IN_BYTES_0    = 16  ;
static const uint8_t P9A_PERV_FSII2C_COMMAND_REGISTER_A_LENGTH_IN_BYTES_0_LEN = 16  ;

static const uint8_t P9A_PERV_FSI2PIB_COMPLEMENT_MASK_REG                    = 0   ;
static const uint8_t P9A_PERV_FSI2PIB_COMPLEMENT_MASK_REG_LEN                = 32  ;

static const uint8_t P9A_PERV_FSISHIFT_COMPLEMENT_MASK_REG                   = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_COMPLEMENT_MASK_REG_LEN               = 32  ;

static const uint8_t P9A_PERV_1_CONTROL_REG_RESET_TRIP_HISTORY               = 0   ;
static const uint8_t P9A_PERV_1_CONTROL_REG_RESET_SAMPLE_PULSE_CNT           = 1   ;
static const uint8_t P9A_PERV_1_CONTROL_REG_F_RESET_CPM_RD                   = 2   ;
static const uint8_t P9A_PERV_1_CONTROL_REG_F_RESET_CPM_WR                   = 3   ;
static const uint8_t P9A_PERV_1_CONTROL_REG_RESET_SAMPLE_DTS                 = 4   ;
static const uint8_t P9A_PERV_1_CONTROL_REG_FORCE_SAMPLE_DTS                 = 5   ;
static const uint8_t P9A_PERV_1_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE   = 6   ;
static const uint8_t P9A_PERV_1_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS      = 7   ;
static const uint8_t P9A_PERV_1_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS      = 8   ;
static const uint8_t P9A_PERV_1_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS      = 9   ;
static const uint8_t P9A_PERV_1_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE = 10  ;
static const uint8_t P9A_PERV_1_CONTROL_REG_FORCE_RESET_MEASURE_VOLT         = 11  ;
static const uint8_t P9A_PERV_1_CONTROL_REG_FORCE_SHIFT_SENSOR               = 12  ;

static const uint8_t P9A_PERV_1_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC           = 0   ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN       = 6   ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_6C                       = 6   ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_7C                       = 7   ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC           = 8   ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN       = 6   ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_14C                      = 14  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_15C                      = 15  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC           = 16  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN       = 6   ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_22C                      = 22  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_23C                      = 23  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC           = 24  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN       = 6   ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_30C                      = 30  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_31C                      = 31  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_CTRL_CC_OFLOW_FEH_SEL_DC          = 32  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC           = 33  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_CTRL_CC_SDIS_DC_N                 = 34  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_CTRL_CC_SCAN_DIAG                 = 35  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_TEST_CONTROL_36C         = 36  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_TEST_CONTROL_37C         = 37  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_TEST_CONTROL_38C         = 38  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_TEST_CONTROL_39C         = 39  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC     = 40  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC = 41  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_42C                      = 42  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_43C                      = 43  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN           = 44  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_45C                      = 45  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_46C                      = 46  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_47C                      = 47  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_UNUSED_48C                        = 48  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_UNUSED_49C                        = 49  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_UNUSED_50C                        = 50  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_UNUSED_51C                        = 51  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_TC_UNIT_CHIP_ID_DC                = 52  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_TC_UNIT_CHIP_ID_DC_LEN            = 3   ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_ID_55C                   = 55  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_UNUSED_56C                        = 56  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_UNUSED_57C                        = 57  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_UNUSED_58C                        = 58  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_UNUSED_59C                        = 59  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_UNUSED_60C                        = 60  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_ID_61C                   = 61  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_ID_62C                   = 62  ;
static const uint8_t P9A_PERV_1_CPLT_CONF0_RESERVED_ID_63C                   = 63  ;

static const uint8_t P9A_PERV_1_CPLT_CONF1_TCPERV_AMUX_VSELECT_CHIP          = 0   ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_TCPERV_AMUX_VSELECT_CHIP_LEN      = 3   ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_3D                         = 3   ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_4D                         = 4   ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_5D                         = 5   ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_6D                         = 6   ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_7D                         = 7   ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_8D                         = 8   ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_9D                         = 9   ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_10D                        = 10  ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_11D                        = 11  ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_TP_IO_SPI_APSS_MCPRECOMP          = 12  ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_TP_IO_SPI_APSS_MCPRECOMP_LEN      = 2   ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_TP_IO_SPARE2_MCPRECOMP            = 14  ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_TP_IO_SPARE2_MCPRECOMP_LEN        = 2   ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_TP_IO_SPARE3_MCPRECOMP            = 16  ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_TP_IO_SPARE3_MCPRECOMP_LEN        = 2   ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_18D                        = 18  ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_19D                        = 19  ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_20D                        = 20  ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_21D                        = 21  ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_22D                        = 22  ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_23D                        = 23  ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_24D                        = 24  ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_25D                        = 25  ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_26D                        = 26  ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_27D                        = 27  ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_28D                        = 28  ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_29D                        = 29  ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_30D                        = 30  ;
static const uint8_t P9A_PERV_1_CPLT_CONF1_UNUSED_31D                        = 31  ;

static const uint8_t P9A_PERV_1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC         = 0   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC         = 1   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH_DC          = 2   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN_DC            = 3   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC           = 4   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_UNUSED_5A                         = 5   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_UNUSED_6A                         = 6   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_UNUSED_7A                         = 7   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC    = 8   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_UNUSED_9A                         = 9   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_UNUSED_10A                        = 10  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_RESERVED_11A                      = 11  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_UNUSED_12A                        = 12  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENABLE_DC = 13  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC     = 14  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENABLE_DC       = 15  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_UNUSED_16A                        = 16  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_UNUSED_17A                        = 17  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_RESERVED_18A                      = 18  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_RESERVED_19A                      = 19  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_TC_PSRO_SEL_DC                    = 20  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN                = 8   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_UNUSED_28A                        = 28  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_UNUSED_29A                        = 29  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_UNUSED_30A                        = 30  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_UNUSED_31A                        = 31  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_UNUSED_32A                        = 32  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_RESERVED_33A                      = 33  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_RESERVED_34A                      = 34  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_RESERVED_35A                      = 35  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_UNUSED_36A                        = 36  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_UNUSED_37A                        = 37  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_RESERVED_38A                      = 38  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_RESERVED_39A                      = 39  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC           = 40  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN       = 2   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_RESERVED_42A                      = 42  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_RESERVED_43A                      = 43  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_UNUSED_44A                        = 44  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC            = 45  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC          = 46  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC              = 47  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_FREE_USAGE_48A                    = 48  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_FREE_USAGE_49A                    = 49  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_FREE_USAGE_50A                    = 50  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_FREE_USAGE_51A                    = 51  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_FREE_USAGE_52A                    = 52  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_FREE_USAGE_53A                    = 53  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_FREE_USAGE_54A                    = 54  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_FREE_USAGE_55A                    = 55  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_FREE_USAGE_56A                    = 56  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_FREE_USAGE_57A                    = 57  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_FREE_USAGE_58A                    = 58  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_FREE_USAGE_59A                    = 59  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_FREE_USAGE_60A                    = 60  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_FREE_USAGE_61A                    = 61  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_FREE_USAGE_62A                    = 62  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL0_FREE_USAGE_63A                    = 63  ;

static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_0B                         = 0   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_1B                         = 1   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_2B                         = 2   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_TC_VITL_REGION_FENCE              = 3   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_TC_PERV_REGION_FENCE              = 4   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_TC_REGION1_FENCE                  = 5   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_TC_REGION2_FENCE                  = 6   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_TC_REGION3_FENCE                  = 7   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_8B                         = 8   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_9B                         = 9   ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_10B                        = 10  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_11B                        = 11  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_12B                        = 12  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_13B                        = 13  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_14B                        = 14  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_RESERVED                          = 15  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE     = 16  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_17B                        = 17  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_18B                        = 18  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_19B                        = 19  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_TC_PERV_EXPORT_FREEZE             = 20  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_21B                        = 21  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_TC_STG_ACT_EN_DC                  = 22  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_23B                        = 23  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_24B                        = 24  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_25B                        = 25  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_26B                        = 26  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_27B                        = 27  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_28B                        = 28  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_29B                        = 29  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_30B                        = 30  ;
static const uint8_t P9A_PERV_1_CPLT_CTRL1_UNUSED_31B                        = 31  ;

static const uint8_t P9A_PERV_1_CPLT_MASK0_CPLTMASK0                         = 0   ;
static const uint8_t P9A_PERV_1_CPLT_MASK0_CPLTMASK0_LEN                     = 24  ;

static const uint8_t P9A_PERV_1_CPLT_STAT0_ABIST_DONE_DC                     = 0   ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_EBIST_DONE_DC                     = 1   ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_RESERVED_2E                       = 2   ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_RESERVED_3E                       = 3   ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_TC_DIAG_PORT0_OUT                 = 4   ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_TC_DIAG_PORT1_OUT                 = 5   ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_RESERVED_6E                       = 6   ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_PLL_DESTOUT                       = 7   ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC              = 8   ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC     = 9   ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_FREE_USAGE_10E                    = 10  ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_FREE_USAGE_11E                    = 11  ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_FREE_USAGE_12E                    = 12  ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_FREE_USAGE_13E                    = 13  ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_FREE_USAGE_14E                    = 14  ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_FREE_USAGE_15E                    = 15  ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_FREE_USAGE_16E                    = 16  ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_FREE_USAGE_17E                    = 17  ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_FREE_USAGE_18E                    = 18  ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_FREE_USAGE_19E                    = 19  ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_FREE_USAGE_20E                    = 20  ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_FREE_USAGE_21E                    = 21  ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_FREE_USAGE_22E                    = 22  ;
static const uint8_t P9A_PERV_1_CPLT_STAT0_FREE_USAGE_23E                    = 23  ;

static const uint8_t P9A_PERV_CSAR_SRAM_ADDRESS                              = 16  ;
static const uint8_t P9A_PERV_CSAR_SRAM_ADDRESS_LEN                          = 13  ;

static const uint8_t P9A_PERV_CSCR_SRAM_ACCESS_MODE                          = 0   ;
static const uint8_t P9A_PERV_CSCR_SRAM_SCRUB_ENABLE                         = 1   ;
static const uint8_t P9A_PERV_CSCR_ECC_CORRECT_DIS                           = 2   ;
static const uint8_t P9A_PERV_CSCR_ECC_DETECT_DIS                            = 3   ;
static const uint8_t P9A_PERV_CSCR_ECC_INJECT_TYPE                           = 4   ;
static const uint8_t P9A_PERV_CSCR_ECC_INJECT_ERR                            = 5   ;
static const uint8_t P9A_PERV_CSCR_SPARE_6_7                                 = 6   ;
static const uint8_t P9A_PERV_CSCR_SPARE_6_7_LEN                             = 2   ;
static const uint8_t P9A_PERV_CSCR_SRAM_SCRUB_INDEX                          = 47  ;
static const uint8_t P9A_PERV_CSCR_SRAM_SCRUB_INDEX_LEN                      = 13  ;

static const uint8_t P9A_PERV_CSDR_SRAM_DATA                                 = 0   ;
static const uint8_t P9A_PERV_CSDR_SRAM_DATA_LEN                             = 64  ;

static const uint8_t P9A_PERV_1_CTRL_ATOMIC_LOCK_REG_ENABLE                  = 0   ;
static const uint8_t P9A_PERV_1_CTRL_ATOMIC_LOCK_REG_ID                      = 1   ;
static const uint8_t P9A_PERV_1_CTRL_ATOMIC_LOCK_REG_ID_LEN                  = 4   ;
static const uint8_t P9A_PERV_1_CTRL_ATOMIC_LOCK_REG_ACTIVITY                = 8   ;
static const uint8_t P9A_PERV_1_CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN            = 8   ;

static const uint8_t P9A_PERV_1_CTRL_PROTECT_MODE_REG_READ_ENABLE            = 0   ;
static const uint8_t P9A_PERV_1_CTRL_PROTECT_MODE_REG_WRITE_ENABLE           = 1   ;

static const uint8_t P9A_PERV_DATA_REGISTER_OTP                              = 0   ;
static const uint8_t P9A_PERV_DATA_REGISTER_OTP_LEN                          = 64  ;

static const uint8_t P9A_PERV_FSI2PIB_DATA_REGISTER_0_REG                    = 0   ;
static const uint8_t P9A_PERV_FSI2PIB_DATA_REGISTER_0_REG_LEN                = 32  ;

static const uint8_t P9A_PERV_FSI2PIB_DATA_REGISTER_1_REG                    = 0   ;
static const uint8_t P9A_PERV_FSI2PIB_DATA_REGISTER_1_REG_LEN                = 32  ;

static const uint8_t P9A_PERV_1_DBG_CBS_CC_RESET_EP                          = 0   ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_OPCG_IP                           = 1   ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_VITL_CLKOFF                       = 2   ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_TEST_ENABLE                       = 3   ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_REQ                               = 4   ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_CMD                               = 5   ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_CMD_LEN                           = 3   ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_STATE                             = 8   ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_STATE_LEN                         = 5   ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_SECURITY_DEBUG_MODE               = 13  ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_PROTOCOL_ERROR                    = 14  ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_PCB_IDLE                          = 15  ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_CURRENT_OPCG_MODE                 = 16  ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_CURRENT_OPCG_MODE_LEN             = 4   ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_LAST_OPCG_MODE                    = 20  ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_LAST_OPCG_MODE_LEN                = 4   ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_PCB_ERROR                         = 24  ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_PARITY_ERROR                      = 25  ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_ERROR                             = 26  ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_CHIPLET_IS_ALIGNED                = 27  ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_PCB_REQUEST_SINCE_RESET           = 28  ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_PARANOIA_TEST_ENABLE_CHANGE       = 29  ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_PARANOIA_VITL_CLKOFF_CHANGE       = 30  ;
static const uint8_t P9A_PERV_1_DBG_CBS_CC_TP_TPFSI_ACK                      = 31  ;

static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_COND1_SEL_A             = 0   ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN         = 8   ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_COND1_SEL_B             = 8   ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN         = 8   ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_COND2_SEL_A             = 16  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN         = 8   ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_COND2_SEL_B             = 24  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN         = 8   ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_C1_INAROW_MODE          = 32  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1       = 33  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1       = 34  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1      = 35  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_UNUSED                  = 36  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_UNUSED_LEN              = 3   ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_C2_INAROW_MODE          = 39  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2       = 40  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2       = 41  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2      = 42  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_UNUSED_2                = 43  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_UNUSED_2_LEN            = 3   ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET      = 46  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_EXACT_TO_MODE           = 47  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1     = 48  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_RESET_C3_ON_C0          = 49  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_SLOW_TO_MODE            = 50  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO    = 51  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_C1_COUNT_LT             = 52  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN         = 4   ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_C2_COUNT_LT             = 56  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN         = 4   ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_RESET_C3_SELECT         = 60  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN     = 3   ;

static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0   ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5   ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5   ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5   ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_A   = 10  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_A_LEN = 5   ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_B   = 15  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_B_LEN = 5   ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_2_TO_CMP_LT               = 20  ;
static const uint8_t P9A_PERV_1_DBG_INST1_COND_REG_2_TO_CMP_LT_LEN           = 24  ;

static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_COND1_SEL_A             = 0   ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN         = 8   ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_COND1_SEL_B             = 8   ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN         = 8   ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_COND2_SEL_A             = 16  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN         = 8   ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_COND2_SEL_B             = 24  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN         = 8   ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_C1_INAROW_MODE          = 32  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1       = 33  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1       = 34  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1      = 35  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_UNUSED                  = 36  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_UNUSED_LEN              = 3   ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_C2_INAROW_MODE          = 39  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2       = 40  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2       = 41  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2      = 42  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_UNUSED_2                = 43  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_UNUSED_2_LEN            = 3   ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET      = 46  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_EXACT_TO_MODE           = 47  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1     = 48  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_RESET_C3_ON_C0          = 49  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_SLOW_TO_MODE            = 50  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO    = 51  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_C1_COUNT_LT             = 52  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN         = 4   ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_C2_COUNT_LT             = 56  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN         = 4   ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_RESET_C3_SELECT         = 60  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN     = 3   ;

static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0   ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5   ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5   ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5   ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_A   = 10  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_A_LEN = 5   ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_B   = 15  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_B_LEN = 5   ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_2_TO_CMP_LT               = 20  ;
static const uint8_t P9A_PERV_1_DBG_INST2_COND_REG_2_TO_CMP_LT_LEN           = 24  ;

static const uint8_t P9A_PERV_1_DBG_MODE_REG_GLB_BRCST                       = 0   ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_GLB_BRCST_LEN                   = 3   ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_TRACE_SEL                       = 3   ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_TRACE_SEL_LEN                   = 3   ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_TRIG_SEL                        = 6   ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_TRIG_SEL_LEN                    = 2   ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION         = 8   ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION     = 9   ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION        = 10  ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_FREEZE_SEL                      = 11  ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_SYNC_BRCST                      = 12  ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_SYNC_BRCST_LEN                  = 2   ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_TRACE_RUN_STATUS                = 17  ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_TRACE_RUN_STATUS_LEN            = 2   ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_IS_FROZEN_STATUS                = 19  ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS  = 20  ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3   ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS  = 23  ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3   ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_INST3_CONDITION_HISTORY_STATUS  = 26  ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_INST3_CONDITION_HISTORY_STATUS_LEN = 3   ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_INST4_CONDITION_HISTORY_STATUS  = 29  ;
static const uint8_t P9A_PERV_1_DBG_MODE_REG_INST4_CONDITION_HISTORY_STATUS_LEN = 2   ;

static const uint8_t P9A_PERV_1_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_MODE_REG_2_IMM_FREEZE              = 16  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_MODE_REG_2_STOP_ON_ERR             = 17  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH      = 18  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_MODE_REG_2_FORCE_TEST              = 19  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_MODE_REG_2_ACCUM_HIST              = 20  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON_FRZ        = 21  ;

static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST1_COND3_ENABLE           = 0   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST2_COND3_ENABLE           = 1   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST3_COND3_ENABLE           = 2   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST4_COND3_ENABLE           = 3   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE         = 4   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE         = 5   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE         = 6   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE         = 7   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL    = 8   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL    = 10  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL    = 12  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL    = 14  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL    = 16  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL    = 18  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP             = 32  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE           = 33  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL           = 34  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN       = 5   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL           = 39  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN       = 5   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_PC_TP_TRIG_SEL               = 44  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN           = 2   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_ARM_SEL                      = 46  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_ARM_SEL_LEN                  = 4   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL              = 50  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN          = 4   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL              = 54  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN          = 4   ;

static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST1_CONDITION1_ACTION_DO   = 0   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST1_CONDITION1_ACTION_DO_LEN = 2   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST1_CONDITION2_ACTION_DO   = 2   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST1_CONDITION2_ACTION_DO_LEN = 2   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST1_C2_TIMEOUT_ACTION_DO   = 4   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST1_C2_TIMEOUT_ACTION_DO_LEN = 2   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST2_CONDITION1_ACTION_DO   = 6   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST2_CONDITION1_ACTION_DO_LEN = 2   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST2_CONDITION2_ACTION_DO   = 8   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST2_CONDITION2_ACTION_DO_LEN = 2   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST2_C2_TIMEOUT_ACTION_DO   = 10  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST2_C2_TIMEOUT_ACTION_DO_LEN = 2   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST1_CONDITION1_ACTION_WAITN = 24  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST1_CONDITION2_ACTION_WAITN = 25  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST1_C2_TIMEOUT_ACTION_WAITN = 26  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST2_CONDITION1_ACTION_WAITN = 27  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST2_CONDITION2_ACTION_WAITN = 28  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST2_C2_TIMEOUT_ACTION_WAITN = 29  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST1_CONDITION1_ACTION_BANK = 36  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST1_CONDITION2_ACTION_BANK = 37  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST1_C2_TIMEOUT_ACTION_BANK = 38  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST2_CONDITION1_ACTION_BANK = 39  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST2_CONDITION2_ACTION_BANK = 40  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST2_C2_TIMEOUT_ACTION_BANK = 41  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST1_CHECKSTOP_MODE_LT      = 48  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST1_CHECKSTOP_MODE_LT_LEN  = 3   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST1_CHECKSTOP_MODE_SELECTOR = 51  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST2_CHECKSTOP_MODE_LT      = 52  ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST2_CHECKSTOP_MODE_LT_LEN  = 3   ;
static const uint8_t P9A_PERV_1_DBG_TRACE_REG_1_INST2_CHECKSTOP_MODE_SELECTOR = 55  ;

static const uint8_t P9A_PERV_1_DEBUG_TRACE_CONTROL_SCOM_TRACE_START         = 0   ;
static const uint8_t P9A_PERV_1_DEBUG_TRACE_CONTROL_SCOM_TRACE_STOP          = 1   ;
static const uint8_t P9A_PERV_1_DEBUG_TRACE_CONTROL_SCOM_TRACE_RESET         = 2   ;

static const uint8_t P9A_PERV_DEVICE_ID_REG_SOCKET                           = 36  ;
static const uint8_t P9A_PERV_DEVICE_ID_REG_SOCKET_LEN                       = 3   ;
static const uint8_t P9A_PERV_DEVICE_ID_REG_CHIPPOS                          = 39  ;
static const uint8_t P9A_PERV_DEVICE_ID_REG_FUSED_CORE_MODE_SEL0             = 55  ;
static const uint8_t P9A_PERV_DEVICE_ID_REG_FUSED_CORE_MODE_SEL1             = 56  ;
static const uint8_t P9A_PERV_DEVICE_ID_REG_HW_MODE_SEL                      = 57  ;
static const uint8_t P9A_PERV_DEVICE_ID_REG_TP_EX_FUSE_SMT8_CTYPE_EN         = 58  ;

static const uint8_t P9A_PERV_DISABLE_FORCE_PFET_OFF_REG                     = 0   ;
static const uint8_t P9A_PERV_DISABLE_FORCE_PFET_OFF_REG_LEN                 = 30  ;
static const uint8_t P9A_PERV_DISABLE_FORCE_PFET_OFF_RESERVED                = 30  ;
static const uint8_t P9A_PERV_DISABLE_FORCE_PFET_OFF_RESERVED_LEN            = 12  ;

static const uint8_t P9A_PERV_FSISHIFT_DMA_ERROR_PTR_REGISTER_REG            = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_DMA_ERROR_PTR_REGISTER_REG_LEN        = 32  ;

static const uint8_t P9A_PERV_FSISHIFT_DMA_MODE_REGISTER_REG_ENABLE          = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_DMA_MODE_REGISTER_REG_FIFO_SIZE_EQ_1  = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_DMA_MODE_REGISTER_REG_UNUSED          = 2   ;
static const uint8_t P9A_PERV_FSISHIFT_DMA_MODE_REGISTER_REG_UNUSED_LEN      = 30  ;

static const uint8_t P9A_PERV_FSISHIFT_DMA_OP_BLOCKSIZE_REGISTER_OPCODE      = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_DMA_OP_BLOCKSIZE_REGISTER_OPCODE_LEN  = 8   ;
static const uint8_t P9A_PERV_FSISHIFT_DMA_OP_BLOCKSIZE_REGISTER_SIZE        = 8   ;
static const uint8_t P9A_PERV_FSISHIFT_DMA_OP_BLOCKSIZE_REGISTER_SIZE_LEN    = 24  ;

static const uint8_t P9A_PERV_FSISHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_BUF0_REG_DATA0 = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_BUF0_REG_DATA0_LEN = 32  ;

static const uint8_t P9A_PERV_FSISHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_BUF1_REG_DATA1 = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_BUF1_REG_DATA1_LEN = 32  ;

static const uint8_t P9A_PERV_FSISHIFT_DMA_PIB_SND_BUFFER0_REGISTER_BUF0_REG_DATA0 = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_DMA_PIB_SND_BUFFER0_REGISTER_BUF0_REG_DATA0_LEN = 32  ;

static const uint8_t P9A_PERV_FSISHIFT_DMA_PIB_SND_BUFFER1_REGISTER_BUF1_REG_DATA0 = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_DMA_PIB_SND_BUFFER1_REGISTER_BUF1_REG_DATA0_LEN = 32  ;

static const uint8_t P9A_PERV_FSISHIFT_DMA_REM_SIZE_REGISTER_REMAINING_WORDS = 8   ;
static const uint8_t P9A_PERV_FSISHIFT_DMA_REM_SIZE_REGISTER_REMAINING_WORDS_LEN = 24  ;

static const uint8_t P9A_PERV_FSISHIFT_DMA_SCOM_CMD_REGISTER_REG             = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_DMA_SCOM_CMD_REGISTER_REG_LEN         = 32  ;

static const uint8_t P9A_PERV_FSISHIFT_DMA_STAT_COMP_MASK_REGISTER_REG       = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_DMA_STAT_COMP_MASK_REGISTER_REG_LEN   = 32  ;

static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_PERMISSION_TO_SEND_1 = 0   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_ABORT_1        = 1   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_LBUS_SLAVE_1B_PENDING = 2   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_PIB_SLAVE_PENDING = 3   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_UNUSED_27      = 4   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_XDN_1          = 5   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_XUP_1          = 6   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_UNUSED_24      = 7   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_HEADER_COUNT   = 8   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_HEADER_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_DATA_COUNT     = 12  ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_DATA_COUNT_LEN = 8   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_HEADER_COUNT_1B = 20  ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_HEADER_COUNT_1B_LEN = 4   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_DATA_COUNT_1B  = 24  ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_DATA_COUNT_1B_LEN = 8   ;

static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_PERMISSION_TO_SEND_2 = 0   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_ABORT_2        = 1   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_LBUS_SLAVE_2B_PENDING = 2   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_PIB_SLAVE_PENDING = 3   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_UNUSED_27      = 4   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_XDN_2          = 5   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_XUP_2          = 6   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_UNUSED_24      = 7   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_HEADER_COUNT   = 8   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_HEADER_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_DATA_COUNT     = 12  ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_DATA_COUNT_LEN = 8   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_HEADER_COUNT_2B = 20  ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_HEADER_COUNT_2B_LEN = 4   ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_DATA_COUNT_2B  = 24  ;
static const uint8_t P9A_PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_DATA_COUNT_2B_LEN = 8   ;

static const uint8_t P9A_PERV_1_DTS_RESULT0_0_RESULT                         = 0   ;
static const uint8_t P9A_PERV_1_DTS_RESULT0_0_RESULT_LEN                     = 16  ;
static const uint8_t P9A_PERV_1_DTS_RESULT0_1_RESULT                         = 16  ;
static const uint8_t P9A_PERV_1_DTS_RESULT0_1_RESULT_LEN                     = 16  ;

static const uint8_t P9A_PERV_1_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE       = 0   ;
static const uint8_t P9A_PERV_1_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE_LEN   = 44  ;
static const uint8_t P9A_PERV_1_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR = 44  ;
static const uint8_t P9A_PERV_1_DTS_TRC_RESULT_1                             = 48  ;
static const uint8_t P9A_PERV_1_DTS_TRC_RESULT_1_LEN                         = 16  ;

static const uint8_t P9A_PERV_1_EDRAM_STATUS_STAT                            = 0   ;
static const uint8_t P9A_PERV_1_EDRAM_STATUS_STAT_LEN                        = 4   ;

static const uint8_t P9A_PERV_ERROR_REG_TIMEOUT_ACTIVE                       = 0   ;
static const uint8_t P9A_PERV_ERROR_REG_PARITY_ERR                           = 1   ;
static const uint8_t P9A_PERV_ERROR_REG_BEAT_NUM_ERR                         = 2   ;
static const uint8_t P9A_PERV_ERROR_REG_BEAT_REC_ERR                         = 3   ;
static const uint8_t P9A_PERV_ERROR_REG_RECEIVED                             = 4   ;
static const uint8_t P9A_PERV_ERROR_REG_RX_PCB_DATA_P_ERR                    = 5   ;
static const uint8_t P9A_PERV_ERROR_REG_PIB_ADDR_P_ERR                       = 6   ;
static const uint8_t P9A_PERV_ERROR_REG_PIB_DATA_P_ERR                       = 7   ;

static const uint8_t P9A_PERV_1_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR       = 0   ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR        = 1   ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR           = 2   ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR       = 3   ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR          = 4   ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR          = 5   ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR = 6   ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR         = 7   ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR       = 8   ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR       = 9   ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR          = 10  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_SCAN_COLLISION_ERR              = 11  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR    = 12  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_OPCG_TRIGGER_ERR                = 13  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR        = 14  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR         = 15  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR           = 16  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR     = 17  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR          = 18  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR   = 19  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR         = 20  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR          = 21  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_CLKCMD_REQUEST_ERR              = 22  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_CBS_PROTOCOL_ERR                = 23  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_VITL_ALIGN_ERR                  = 24  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_UNIT_SYNC_LVL_ERR               = 25  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR = 26  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR         = 27  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_EDRAM_SCAN_PREVENTED_ERR        = 28  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_UNUSED_ERROR29                  = 29  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_UNUSED_ERROR30                  = 30  ;
static const uint8_t P9A_PERV_1_ERROR_STATUS_UNUSED_ERROR31                  = 31  ;

static const uint8_t P9A_PERV_1_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD = 0   ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD = 1   ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD = 2   ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD = 3   ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD = 4   ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD  = 5   ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD = 6   ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD          = 7   ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_RUN_STATE_ERR_HOLD            = 8   ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD    = 9   ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD = 10  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD       = 11  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD        = 12  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_TIMEOUT_ERR_HOLD              = 13  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_F_SKITTER_ERR_HOLD            = 14  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_PCB_ERR_HOLD_OUT              = 15  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_MASK = 16  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_THERM_MODEREG_PARITY_MASK     = 17  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_MASK   = 18  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_MASK  = 19  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_SCAN_INIT_VERSION_PARITY_MASK = 20  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_VOLT_MODEREG_PARITY_MASK      = 21  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_COUNT_STATE_MASK              = 23  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_RUN_STATE_MASK                = 24  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_THRES_STATE_MASK              = 25  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_OVERFLOW_MASK                 = 26  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_SHIFTER_PARITY_MASK           = 27  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_SHIFTER_VALID_MASK            = 28  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_TIMEOUT_MASK                  = 29  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_F_SKITTER_READ_MASK           = 30  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_PCB_MASK                      = 31  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_COUNT_STATE_LT                = 40  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_COUNT_STATE_LT_LEN            = 4   ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_RUN_STATE_LT                  = 44  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_RUN_STATE_LT_LEN              = 3   ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_SHIFT_DTS_LT                  = 47  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_SHIFT_VOLT_LT                 = 48  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_READ_STATE_LT                 = 49  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_READ_STATE_LT_LEN             = 2   ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_WRITE_STATE_LT                = 51  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_WRITE_STATE_LT_LEN            = 4   ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_SAMPLE_DTS_LT                 = 55  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_MEASURE_VOLT_LT               = 56  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_READ_CPM_LT                   = 57  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_WRITE_CPM_LT                  = 58  ;
static const uint8_t P9A_PERV_1_ERR_STATUS_REG_UNUSED                        = 59  ;

static const uint8_t P9A_PERV_EXPORT_REGL_CTRL_TP_NX_ALLOW_CRYPTO_DC         = 0   ;
static const uint8_t P9A_PERV_EXPORT_REGL_CTRL_TP_EX_FUSE_VMX_CRYPTO_DIS_DC  = 1   ;
static const uint8_t P9A_PERV_EXPORT_REGL_CTRL_TP_EX_FUSE_FP_THROTTLE_EN_DC  = 2   ;
static const uint8_t P9A_PERV_EXPORT_REGL_CTRL_TP_PB_FUSE_TOPOLOGY_2CHIP     = 3   ;
static const uint8_t P9A_PERV_EXPORT_REGL_CTRL_TP_PB_FUSE_TOPOLOGY_GROUP     = 4   ;
static const uint8_t P9A_PERV_EXPORT_REGL_CTRL_TP_PB_FUSE_TOPOLOGY_GROUP_LEN = 2   ;
static const uint8_t P9A_PERV_EXPORT_REGL_CTRL_TP_NP_NVLINK_DISABLE          = 6   ;
static const uint8_t P9A_PERV_EXPORT_REGL_CTRL_OTP_PCBMS_HW_MODE_SEL_DC      = 7   ;
static const uint8_t P9A_PERV_EXPORT_REGL_CTRL_OTP_PCBMS_FUSED_CORE_MODE_SEL0_DC = 8   ;
static const uint8_t P9A_PERV_EXPORT_REGL_CTRL_OTP_PCBMS_FUSED_CORE_MODE_SEL1_DC = 9   ;

static const uint8_t P9A_PERV_FSII2C_EXTENDED_STATUS_A_MSM_CURR_STATE_0      = 11  ;
static const uint8_t P9A_PERV_FSII2C_EXTENDED_STATUS_A_MSM_CURR_STATE_0_LEN  = 5   ;
static const uint8_t P9A_PERV_FSII2C_EXTENDED_STATUS_A_SELF_BUSY_0           = 25  ;

static const uint8_t P9A_PERV_FSII2C_FIFO1_REGISTER_READ_A_FIFO_BITS_READ0_0 = 0   ;
static const uint8_t P9A_PERV_FSII2C_FIFO1_REGISTER_READ_A_FIFO_BITS_READ0_0_LEN = 8   ;

static const uint8_t P9A_PERV_FIRST_ERR_REG_TIMEOUT_ACTIVE                   = 0   ;
static const uint8_t P9A_PERV_FIRST_ERR_REG_PARITY                           = 1   ;
static const uint8_t P9A_PERV_FIRST_ERR_REG_BEAT_NUM                         = 2   ;
static const uint8_t P9A_PERV_FIRST_ERR_REG_BEAT_REC                         = 3   ;
static const uint8_t P9A_PERV_FIRST_ERR_REG_RECEIVED_ERROR                   = 4   ;
static const uint8_t P9A_PERV_FIRST_ERR_REG_RX_PCB_DATA_P                    = 5   ;
static const uint8_t P9A_PERV_FIRST_ERR_REG_PIB_ADDR_P                       = 6   ;
static const uint8_t P9A_PERV_FIRST_ERR_REG_PIB_DATA_P                       = 7   ;

static const uint8_t P9A_PERV_FIRST_REPLY_REG_REGISTER                       = 0   ;
static const uint8_t P9A_PERV_FIRST_REPLY_REG_REGISTER_LEN                   = 6   ;

static const uint8_t P9A_PERV_FIR_ACTION0_REG_ACTION0                        = 0   ;
static const uint8_t P9A_PERV_FIR_ACTION0_REG_ACTION0_LEN                    = 50  ;

static const uint8_t P9A_PERV_FIR_ACTION1_REG_ACTION1                        = 0   ;
static const uint8_t P9A_PERV_FIR_ACTION1_REG_ACTION1_LEN                    = 50  ;

static const uint8_t P9A_PERV_1_FIR_MASK_IN0                                 = 0   ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN1                                 = 1   ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN2                                 = 2   ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN3                                 = 3   ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN4                                 = 4   ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN5                                 = 5   ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN6                                 = 6   ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN7                                 = 7   ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN8                                 = 8   ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN9                                 = 9   ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN10                                = 10  ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN11                                = 11  ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN12                                = 12  ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN13                                = 13  ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN14                                = 14  ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN15                                = 15  ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN16                                = 16  ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN17                                = 17  ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN18                                = 18  ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN19                                = 19  ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN20                                = 20  ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN21                                = 21  ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN21_LEN                            = 5   ;
static const uint8_t P9A_PERV_1_FIR_MASK_IN26                                = 26  ;

static const uint8_t P9A_PERV_FIR_MASK_REG_RX_INVALID_STATE_OR_PARITY_ERROR  = 0   ;
static const uint8_t P9A_PERV_FIR_MASK_REG_TX_INVALID_STATE_OR_PARITY_ERROR  = 1   ;
static const uint8_t P9A_PERV_FIR_MASK_REG_GCR_HANG_ERROR                    = 2   ;
static const uint8_t P9A_PERV_FIR_MASK_REG_UNUSED                            = 3   ;
static const uint8_t P9A_PERV_FIR_MASK_REG_UNUSED_LEN                        = 45  ;
static const uint8_t P9A_PERV_FIR_MASK_REG_INTERNAL_SCOM_ERROR               = 48  ;
static const uint8_t P9A_PERV_FIR_MASK_REG_INTERNAL_SCOM_ERROR_CLONE         = 49  ;

static const uint8_t P9A_PERV_FIR_REG_RX_INVALID_STATE_OR_PARITY_ERROR       = 0   ;
static const uint8_t P9A_PERV_FIR_REG_TX_INVALID_STATE_OR_PARITY_ERROR       = 1   ;
static const uint8_t P9A_PERV_FIR_REG_GCR_HANG_ERROR                         = 2   ;
static const uint8_t P9A_PERV_FIR_REG_UNUSED                                 = 3   ;
static const uint8_t P9A_PERV_FIR_REG_UNUSED_LEN                             = 45  ;
static const uint8_t P9A_PERV_FIR_REG_SCOMFIR_ERROR                          = 48  ;
static const uint8_t P9A_PERV_FIR_REG_SCOMFIR_ERROR_CLONE                    = 49  ;

static const uint8_t P9A_PERV_FIR_WOF_REG_WOF                                = 0   ;
static const uint8_t P9A_PERV_FIR_WOF_REG_WOF_LEN                            = 50  ;

static const uint8_t P9A_PERV_1_FMU_FORCE_OP_REG_FORCE_MEASURE               = 0   ;
static const uint8_t P9A_PERV_1_FMU_FORCE_OP_REG_FORCE_FMU_SM_RESET          = 1   ;

static const uint8_t P9A_PERV_1_FMU_KVREF_DATAREG_FMU_KVREF_DATAREG          = 0   ;
static const uint8_t P9A_PERV_1_FMU_KVREF_DATAREG_FMU_KVREF_DATAREG_LEN      = 64  ;

static const uint8_t P9A_PERV_1_FMU_MODE_REG_TOD_CNTR_REF                    = 12  ;
static const uint8_t P9A_PERV_1_FMU_MODE_REG_TOD_CNTR_REF_LEN                = 4   ;
static const uint8_t P9A_PERV_1_FMU_MODE_REG_UNUSED1                         = 16  ;
static const uint8_t P9A_PERV_1_FMU_MODE_REG_POWER_UP_CNTR_REF               = 17  ;
static const uint8_t P9A_PERV_1_FMU_MODE_REG_POWER_UP_CNTR_REF_LEN           = 3   ;
static const uint8_t P9A_PERV_1_FMU_MODE_REG_UNUSED2                         = 20  ;
static const uint8_t P9A_PERV_1_FMU_MODE_REG_UNUSED2_LEN                     = 4   ;

static const uint8_t P9A_PERV_1_FMU_OSC_CNTR1_REG_FMU_PULSE_GEN_REG_ERR      = 1   ;
static const uint8_t P9A_PERV_1_FMU_OSC_CNTR1_REG_FMU_MODEREG_P_ERR          = 2   ;
static const uint8_t P9A_PERV_1_FMU_OSC_CNTR1_REG_RESULT_AVAILABLE           = 3   ;
static const uint8_t P9A_PERV_1_FMU_OSC_CNTR1_REG_PULSE1_CNTR                = 4   ;
static const uint8_t P9A_PERV_1_FMU_OSC_CNTR1_REG_PULSE1_CNTR_LEN            = 24  ;

static const uint8_t P9A_PERV_1_FMU_OSC_CNTR2_REG_FMU_PULSE_GEN_REG_ERR      = 1   ;
static const uint8_t P9A_PERV_1_FMU_OSC_CNTR2_REG_FMU_MODEREG_P_ERR          = 2   ;
static const uint8_t P9A_PERV_1_FMU_OSC_CNTR2_REG_RESULT_AVAILABLE           = 3   ;
static const uint8_t P9A_PERV_1_FMU_OSC_CNTR2_REG_PULSE2_CNTR                = 4   ;
static const uint8_t P9A_PERV_1_FMU_OSC_CNTR2_REG_PULSE2_CNTR_LEN            = 24  ;

static const uint8_t P9A_PERV_1_FMU_PULSE_GEN_REG_INT_ENA                    = 0   ;
static const uint8_t P9A_PERV_1_FMU_PULSE_GEN_REG_UNUSED3                    = 1   ;
static const uint8_t P9A_PERV_1_FMU_PULSE_GEN_REG_INT_CNTR_REF               = 2   ;
static const uint8_t P9A_PERV_1_FMU_PULSE_GEN_REG_INT_CNTR_REF_LEN           = 10  ;

static const uint8_t P9A_PERV_1_FMU_VMEAS_MAX_RESULT_VMEAS_MAX_RESULT        = 0   ;
static const uint8_t P9A_PERV_1_FMU_VMEAS_MAX_RESULT_VMEAS_MAX_RESULT_LEN    = 8   ;

static const uint8_t P9A_PERV_1_FMU_VMEAS_MIN_RESULT_VMEAS_MIN_RESULT        = 0   ;
static const uint8_t P9A_PERV_1_FMU_VMEAS_MIN_RESULT_VMEAS_MIN_RESULT_LEN    = 8   ;

static const uint8_t P9A_PERV_FSB_FSB_DNFIFO_DATA_OUT_DNFIFO_DATA_OUT_PORT   = 0   ;
static const uint8_t P9A_PERV_FSB_FSB_DNFIFO_DATA_OUT_DNFIFO_DATA_OUT_PORT_LEN = 32  ;

static const uint8_t P9A_PERV_FSB_FSB_DOWNFIFO_ACK_EOT_DNFIFO_ACK            = 0   ;

static const uint8_t P9A_PERV_FSB_FSB_DOWNFIFO_MTC_DNFIFO_MCT                = 0   ;
static const uint8_t P9A_PERV_FSB_FSB_DOWNFIFO_MTC_DNFIFO_MCT_LEN            = 32  ;

static const uint8_t P9A_PERV_FSB_FSB_DOWNFIFO_RESET_DNFIFO_RESET            = 0   ;

static const uint8_t P9A_PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_REQ_RESET_FR_SBE = 6   ;
static const uint8_t P9A_PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_REQ_RESET_FR_SP = 7   ;
static const uint8_t P9A_PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_DEQUEUED_EOT_FLAG = 8   ;
static const uint8_t P9A_PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_FIFO_FULL       = 10  ;
static const uint8_t P9A_PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_FIFO_EMPTY      = 11  ;
static const uint8_t P9A_PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_FIFO_ENTRY_COUNT = 12  ;
static const uint8_t P9A_PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_FIFO_ENTRY_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_FIFO_VALID_FLAGS = 16  ;
static const uint8_t P9A_PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_FIFO_VALID_FLAGS_LEN = 8   ;
static const uint8_t P9A_PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_FIFO_EOT_FLAGS  = 24  ;
static const uint8_t P9A_PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_FIFO_EOT_FLAGS_LEN = 8   ;

static const uint8_t P9A_PERV_FSB_FSB_UPFIFO_DATA_IN_UPFIFO_DATA_IN_PORT     = 0   ;
static const uint8_t P9A_PERV_FSB_FSB_UPFIFO_DATA_IN_UPFIFO_DATA_IN_PORT_LEN = 32  ;

static const uint8_t P9A_PERV_FSB_FSB_UPFIFO_REQ_RESET_UPFIFO_REQ_RESET      = 0   ;

static const uint8_t P9A_PERV_FSB_FSB_UPFIFO_SIG_EOT_UPFIFO_SIGNAL           = 0   ;

static const uint8_t P9A_PERV_FSB_FSB_UPFIFO_STATUS_REQ_RESET_FR_SP          = 6   ;
static const uint8_t P9A_PERV_FSB_FSB_UPFIFO_STATUS_REQ_RESET_FR_SBE         = 7   ;
static const uint8_t P9A_PERV_FSB_FSB_UPFIFO_STATUS_DEQUEUED_EOT_FLAG        = 8   ;
static const uint8_t P9A_PERV_FSB_FSB_UPFIFO_STATUS_FIFO_FULL                = 10  ;
static const uint8_t P9A_PERV_FSB_FSB_UPFIFO_STATUS_FIFO_EMPTY               = 11  ;
static const uint8_t P9A_PERV_FSB_FSB_UPFIFO_STATUS_FIFO_ENTRY_COUNT         = 12  ;
static const uint8_t P9A_PERV_FSB_FSB_UPFIFO_STATUS_FIFO_ENTRY_COUNT_LEN     = 4   ;
static const uint8_t P9A_PERV_FSB_FSB_UPFIFO_STATUS_FIFO_VALID_FLAGS         = 16  ;
static const uint8_t P9A_PERV_FSB_FSB_UPFIFO_STATUS_FIFO_VALID_FLAGS_LEN     = 8   ;
static const uint8_t P9A_PERV_FSB_FSB_UPFIFO_STATUS_FIFO_EOT_FLAGS           = 24  ;
static const uint8_t P9A_PERV_FSB_FSB_UPFIFO_STATUS_FIFO_EOT_FLAGS_LEN       = 8   ;

static const uint8_t P9A_PERV_FSISCRPD1_FSI_SCRATCH_PAD1                     = 0   ;
static const uint8_t P9A_PERV_FSISCRPD1_FSI_SCRATCH_PAD1_LEN                 = 32  ;

static const uint8_t P9A_PERV_FSISCRPD2_FSI_SCRATCH_PAD2                     = 0   ;
static const uint8_t P9A_PERV_FSISCRPD2_FSI_SCRATCH_PAD2_LEN                 = 32  ;

static const uint8_t P9A_PERV_FSISCRPD3_FSI_SCRATCH_PAD3                     = 0   ;
static const uint8_t P9A_PERV_FSISCRPD3_FSI_SCRATCH_PAD3_LEN                 = 32  ;

static const uint8_t P9A_PERV_FSI_A_LLMOD_EXTEND_TIMO                        = 29  ;
static const uint8_t P9A_PERV_FSI_A_LLMOD_DISABLE_GAP                        = 30  ;
static const uint8_t P9A_PERV_FSI_A_LLMOD_ASYNC_MODE                         = 31  ;

static const uint8_t P9A_PERV_FSI_A_LLSTAT_RESERVED_0                        = 0   ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_RESERVED_0_LEN                    = 7   ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_NO_CLK                            = 7   ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_RESERVED_2                        = 8   ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_RESERVED_2_LEN                    = 2   ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_BAD_HANDSHAKE_AT_START            = 10  ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_TIMEOUT                           = 11  ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_LBUS_BUSY                         = 12  ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_OPB_BUSY                          = 13  ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_RESERVED_3                        = 14  ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_BREAK_PENDING                     = 15  ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_RESERVED_4                        = 16  ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_RESERVED_4_LEN                    = 2   ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_HANDSHAKE_STATE                   = 18  ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_HANDSHAKE_STATE_LEN               = 2   ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_CFAM_CYCLE_TIME                   = 20  ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_CFAM_CYCLE_TIME_LEN               = 4   ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_REFCLOCK_STATUS                   = 24  ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_REFCLOCK_STATUS_LEN               = 4   ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_RESERVED_5                        = 28  ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_RESERVED_5_LEN                    = 3   ;
static const uint8_t P9A_PERV_FSI_A_LLSTAT_ASYNC_MODE                        = 31  ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MAEB_BRIDGE_ERROR                  = 0   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MAEB_BRIDGE_ERROR         = 0   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MCENP0_CLR_PORT_ENABLE             = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MCENP0_CLR_PORT_ENABLE_LEN         = 8   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MCENP0_CLR_PORT_ENABLE    = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MCENP0_CLR_PORT_ENABLE_LEN = 8   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MENP0_PORT_ENABLE                  = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MENP0_PORT_1_ENABLE                = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MENP0_PORT_2_ENABLE                = 2   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MENP0_PORT_3_ENABLE                = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MENP0_PORT_4_ENABLE                = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MENP0_PORT_5_ENABLE                = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MENP0_PORT_6_ENABLE                = 6   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MENP0_PORT_7_ENABLE                = 7   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MENP0_PORT_ENABLE         = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MENP0_PORT_1_ENABLE       = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MENP0_PORT_2_ENABLE       = 2   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MENP0_PORT_3_ENABLE       = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MENP0_PORT_4_ENABLE       = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MENP0_PORT_5_ENABLE       = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MENP0_PORT_6_ENABLE       = 6   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MENP0_PORT_7_ENABLE       = 7   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_FIRST_ERROR                 = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_FIRST_ERROR_LEN             = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_CRC_ERROR_COUNT             = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_MMODE_PARITY_CHECK          = 8   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_MDLYR_PARITY_CHECK          = 9   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_MCRSP0_PARITY_CHECK         = 10  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_MENP0_PARITY_CHECK          = 11  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_MSIEP0_PARITY_CHECK         = 12  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_MSSIEP0_PARITY_CHECK        = 13  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_REGISTER_ACCESS_FSM_CHECK   = 14  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_OPB_BUS_ACCESS_FSM_CHECK    = 15  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_REGISTER_ACCESS_ERROR       = 16  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_FAILING_OPB_MASTER_FRST     = 17  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_FAILING_OPB_MASTER_FRST_LEN = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_ACTUAL_ERROR                = 20  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_ACTUAL_ERROR_LEN            = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_SELECTED_ERROR              = 24  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_SELECTED_ERROR_LEN          = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_FAILING_OPB_MASTER_ACT      = 29  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MESRB0_FAILING_OPB_MASTER_ACT_LEN  = 3   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_FIRST_ERROR        = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_FIRST_ERROR_LEN    = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_CRC_ERROR_COUNT    = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_CRC_ERROR_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_MMODE_PARITY_CHECK = 8   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_MDLYR_PARITY_CHECK = 9   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_MCRSP0_PARITY_CHECK = 10  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_MENP0_PARITY_CHECK = 11  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_MSIEP0_PARITY_CHECK = 12  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_MSSIEP0_PARITY_CHECK = 13  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_REGISTER_ACCESS_FSM_CHECK = 14  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_OPB_BUS_ACCESS_FSM_CHECK = 15  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_REGISTER_ACCESS_ERROR = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_FAILING_OPB_MASTER_FRST = 17  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_FAILING_OPB_MASTER_FRST_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_ACTUAL_ERROR       = 20  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_ACTUAL_ERROR_LEN   = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_SELECTED_ERROR     = 24  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_SELECTED_ERROR_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_FAILING_OPB_MASTER_ACT = 29  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MESRB0_FAILING_OPB_MASTER_ACT_LEN = 3   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MLEVP0_PORT_LEVEL                  = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MLEVP0_PORT_LEVEL_1                = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MLEVP0_PORT_LEVEL_2                = 2   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MLEVP0_PORT_LEVEL_3                = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MLEVP0_PORT_LEVEL_4                = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MLEVP0_PORT_LEVEL_5                = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MLEVP0_PORT_LEVEL_6                = 6   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MLEVP0_PORT_LEVEL_7                = 7   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MLEVP0_PORT_LEVEL         = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MLEVP0_PORT_LEVEL_1       = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MLEVP0_PORT_LEVEL_2       = 2   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MLEVP0_PORT_LEVEL_3       = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MLEVP0_PORT_LEVEL_4       = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MLEVP0_PORT_LEVEL_5       = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MLEVP0_PORT_LEVEL_6       = 6   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MLEVP0_PORT_LEVEL_7       = 7   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MLEVP1_PORT_LEVEL                  = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MLEVP1_PORT_LEVEL_1                = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MLEVP1_PORT_LEVEL_2                = 2   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MLEVP1_PORT_LEVEL_3                = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MLEVP1_PORT_LEVEL_4                = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MLEVP1_PORT_LEVEL_5                = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MLEVP1_PORT_LEVEL_6                = 6   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MLEVP1_PORT_LEVEL_7                = 7   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MLEVP1_PORT_LEVEL         = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MLEVP1_PORT_LEVEL_1       = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MLEVP1_PORT_LEVEL_2       = 2   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MLEVP1_PORT_LEVEL_3       = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MLEVP1_PORT_LEVEL_4       = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MLEVP1_PORT_LEVEL_5       = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MLEVP1_PORT_LEVEL_6       = 6   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MLEVP1_PORT_LEVEL_7       = 7   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA         = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY     = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS = 2   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MMODE_ENABLE_PARITY_CHECK          = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MMODE_CLOCK_RATE_SELECTION         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MMODE_CLOCK_RATE_SELECTION_LEN     = 10  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1       = 14  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1_LEN   = 10  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MMODE_CLOCK_DIV_4                  = 25  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MMODE_TIMEOUT_SEL                  = 26  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MMODE_TIMEOUT_SEL_LEN              = 2   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MMODE_RECEIVER_MODE                = 29  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MMODE_RECEIVER_MODE_LEN            = 3   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS = 2   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MMODE_ENABLE_PARITY_CHECK = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MMODE_CLOCK_RATE_SELECTION = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MMODE_CLOCK_RATE_SELECTION_LEN = 10  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1 = 14  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1_LEN = 10  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MMODE_CLOCK_DIV_4         = 25  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MMODE_TIMEOUT_SEL         = 26  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MMODE_TIMEOUT_SEL_LEN     = 2   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MMODE_RECEIVER_MODE       = 29  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MMODE_RECEIVER_MODE_LEN   = 3   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MREFP0_PORT_HOT_PLUG               = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MREFP0_PORT_HOT_PLUG_1             = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MREFP0_PORT_HOT_PLUG_2             = 2   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MREFP0_PORT_HOT_PLUG_3             = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MREFP0_PORT_HOT_PLUG_4             = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MREFP0_PORT_HOT_PLUG_5             = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MREFP0_PORT_HOT_PLUG_6             = 6   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MREFP0_PORT_HOT_PLUG_7             = 7   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MREFP0_PORT_HOT_PLUG      = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MREFP0_PORT_HOT_PLUG_1    = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MREFP0_PORT_HOT_PLUG_2    = 2   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MREFP0_PORT_HOT_PLUG_3    = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MREFP0_PORT_HOT_PLUG_4    = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MREFP0_PORT_HOT_PLUG_5    = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MREFP0_PORT_HOT_PLUG_6    = 6   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MREFP0_PORT_HOT_PLUG_7    = 7   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MREFP1_PORT_HOT_PLUG               = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MREFP1_PORT_HOT_PLUG_1             = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MREFP1_PORT_HOT_PLUG_2             = 2   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MREFP1_PORT_HOT_PLUG_3             = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MREFP1_PORT_HOT_PLUG_4             = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MREFP1_PORT_HOT_PLUG_5             = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MREFP1_PORT_HOT_PLUG_6             = 6   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MREFP1_PORT_HOT_PLUG_7             = 7   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MREFP1_PORT_HOT_PLUG      = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MREFP1_PORT_HOT_PLUG_1    = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MREFP1_PORT_HOT_PLUG_2    = 2   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MREFP1_PORT_HOT_PLUG_3    = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MREFP1_PORT_HOT_PLUG_4    = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MREFP1_PORT_HOT_PLUG_5    = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MREFP1_PORT_HOT_PLUG_6    = 6   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MREFP1_PORT_HOT_PLUG_7    = 7   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MRESB0_BRIDGE_GENERAL_RESET        = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MRESB0_BRIDGE_ERROR_RESET          = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MRESB0_SET_DMA_IRQ_SUSPEND_MODE    = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MRESB0_CLEAR_DMA_IRQ_SUSPEND_MODE  = 6   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MRESB0_SET_DLY_MEASUREMENT         = 7   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESB0_BRIDGE_GENERAL_RESET = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESB0_BRIDGE_ERROR_RESET = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESB0_SET_DMA_IRQ_SUSPEND_MODE = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESB0_CLEAR_DMA_IRQ_SUSPEND_MODE = 6   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESB0_SET_DLY_MEASUREMENT = 7   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP0_PORT_GENERAL_RESET          = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP0_PORT_ERROR_RESET            = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP0_ALL_BRIDGE_GENERAL_RESET    = 2   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP0_ALL_PORT_GENERAL_RESET      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP0_CONTROL_REGISTER_RESET      = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP0_PARITY_ERROR_RESET          = 5   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP0_PORT_GENERAL_RESET = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP0_PORT_ERROR_RESET   = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP0_ALL_BRIDGE_GENERAL_RESET = 2   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP0_ALL_PORT_GENERAL_RESET = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP0_CONTROL_REGISTER_RESET = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP0_PARITY_ERROR_RESET = 5   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP1_PORT_GENERAL_RESET_1        = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP1_PORT_ERROR_RESET_1          = 1   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP1_PORT_GENERAL_RESET_1 = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP1_PORT_ERROR_RESET_1 = 1   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP2_PORT_GENERAL_RESET_2        = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP2_PORT_ERROR_RESET_2          = 1   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP2_PORT_GENERAL_RESET_2 = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP2_PORT_ERROR_RESET_2 = 1   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP3_PORT_GENERAL_RESET_3        = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP3_PORT_ERROR_RESET_3          = 1   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP3_PORT_GENERAL_RESET_3 = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP3_PORT_ERROR_RESET_3 = 1   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP4_PORT_GENERAL_RESET_4        = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP4_PORT_ERROR_RESET_4          = 1   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP4_PORT_GENERAL_RESET_4 = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP4_PORT_ERROR_RESET_4 = 1   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP5_PORT_GENERAL_RESET_5        = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP5_PORT_ERROR_RESET_5          = 1   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP5_PORT_GENERAL_RESET_5 = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP5_PORT_ERROR_RESET_5 = 1   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP6_PORT_GENERAL_RESET_6        = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP6_PORT_ERROR_RESET_6          = 1   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP6_PORT_GENERAL_RESET_6 = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP6_PORT_ERROR_RESET_6 = 1   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP7_PORT_GENERAL_RESET_7        = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MRESP7_PORT_ERROR_RESET_7          = 1   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP7_PORT_GENERAL_RESET_7 = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MRESP7_PORT_ERROR_RESET_7 = 1   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MSENP0_SET_PORT_ENABLE             = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSENP0_SET_PORT_ENABLE_LEN         = 8   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSENP0_SET_PORT_ENABLE    = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSENP0_SET_PORT_ENABLE_LEN = 8   ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE            = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_1          = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_1_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP0_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP0_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP0_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP0_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP0_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE   = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_1 = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_1_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_2 = 9   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_2_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP0_FOURTH_ERROR       = 13  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP0_FOURTH_ERROR_LEN   = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP0_CRC_ERROR_COUNT    = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP0_CRC_ERROR_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP0_HOT_PLUG_FLAG      = 20  ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE            = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_1          = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_1_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP1_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP1_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP1_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP1_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP1_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE   = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_1 = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_1_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_2 = 9   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_2_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP1_FOURTH_ERROR       = 13  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP1_FOURTH_ERROR_LEN   = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP1_CRC_ERROR_COUNT    = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP1_CRC_ERROR_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP1_HOT_PLUG_FLAG      = 20  ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE            = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_1          = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_1_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP2_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP2_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP2_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP2_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP2_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE   = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_1 = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_1_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_2 = 9   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_2_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP2_FOURTH_ERROR       = 13  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP2_FOURTH_ERROR_LEN   = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP2_CRC_ERROR_COUNT    = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP2_CRC_ERROR_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP2_HOT_PLUG_FLAG      = 20  ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE            = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_1          = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_1_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP3_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP3_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP3_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP3_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP3_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE   = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_1 = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_1_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_2 = 9   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_2_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP3_FOURTH_ERROR       = 13  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP3_FOURTH_ERROR_LEN   = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP3_CRC_ERROR_COUNT    = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP3_CRC_ERROR_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP3_HOT_PLUG_FLAG      = 20  ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE            = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_1          = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_1_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP4_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP4_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP4_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP4_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP4_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE   = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_1 = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_1_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_2 = 9   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_2_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP4_FOURTH_ERROR       = 13  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP4_FOURTH_ERROR_LEN   = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP4_CRC_ERROR_COUNT    = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP4_CRC_ERROR_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP4_HOT_PLUG_FLAG      = 20  ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE            = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_1          = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_1_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP5_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP5_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP5_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP5_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP5_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE   = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_1 = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_1_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_2 = 9   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_2_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP5_FOURTH_ERROR       = 13  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP5_FOURTH_ERROR_LEN   = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP5_CRC_ERROR_COUNT    = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP5_CRC_ERROR_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP5_HOT_PLUG_FLAG      = 20  ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE            = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_1          = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_1_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP6_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP6_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP6_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP6_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP6_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE   = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_1 = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_1_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_2 = 9   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_2_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP6_FOURTH_ERROR       = 13  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP6_FOURTH_ERROR_LEN   = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP6_CRC_ERROR_COUNT    = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP6_CRC_ERROR_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP6_HOT_PLUG_FLAG      = 20  ;

static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE            = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_1          = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_1_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP7_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP7_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP7_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP7_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_0_MSTAP7_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE   = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_1 = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_1_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_2 = 9   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_2_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP7_FOURTH_ERROR       = 13  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP7_FOURTH_ERROR_LEN   = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP7_CRC_ERROR_COUNT    = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP7_CRC_ERROR_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_A_MST_0_MSTAP7_HOT_PLUG_FLAG      = 20  ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MAEB_BRIDGE_ERROR                  = 0   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MCENP0_CLR_PORT_ENABLE             = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MCENP0_CLR_PORT_ENABLE_LEN         = 8   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MENP0_PORT_0_ENABLE                = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MENP0_PORT_ENABLE                  = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MENP0_PORT_2_ENABLE                = 2   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MENP0_PORT_3_ENABLE                = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MENP0_PORT_4_ENABLE                = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MENP0_PORT_5_ENABLE                = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MENP0_PORT_6_ENABLE                = 6   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MENP0_PORT_7_ENABLE                = 7   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_FIRST_ERROR                 = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_FIRST_ERROR_LEN             = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_CRC_ERROR_COUNT             = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_MMODE_PARITY_CHECK          = 8   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_MDLYR_PARITY_CHECK          = 9   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_MCRSP0_PARITY_CHECK         = 10  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_MENP0_PARITY_CHECK          = 11  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_MSIEP0_PARITY_CHECK         = 12  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_MSSIEP0_PARITY_CHECK        = 13  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_REGISTER_ACCESS_FSM_CHECK   = 14  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_OPB_BUS_ACCESS_FSM_CHECK    = 15  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_REGISTER_ACCESS_ERROR       = 16  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_FAILING_OPB_MASTER_FRST     = 17  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_FAILING_OPB_MASTER_FRST_LEN = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_ACTUAL_ERROR                = 20  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_ACTUAL_ERROR_LEN            = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_SELECTED_ERROR              = 24  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_SELECTED_ERROR_LEN          = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_FAILING_OPB_MASTER_ACT      = 29  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MESRB0_FAILING_OPB_MASTER_ACT_LEN  = 3   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MLEVP0_PORT_LEVEL_0                = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MLEVP0_PORT_LEVEL                  = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MLEVP0_PORT_LEVEL_2                = 2   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MLEVP0_PORT_LEVEL_3                = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MLEVP0_PORT_LEVEL_4                = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MLEVP0_PORT_LEVEL_5                = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MLEVP0_PORT_LEVEL_6                = 6   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MLEVP0_PORT_LEVEL_7                = 7   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MLEVP1_PORT_LEVEL_0                = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MLEVP1_PORT_LEVEL                  = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MLEVP1_PORT_LEVEL_2                = 2   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MLEVP1_PORT_LEVEL_3                = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MLEVP1_PORT_LEVEL_4                = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MLEVP1_PORT_LEVEL_5                = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MLEVP1_PORT_LEVEL_6                = 6   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MLEVP1_PORT_LEVEL_7                = 7   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA         = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY     = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS = 2   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MMODE_ENABLE_PARITY_CHECK          = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MMODE_CLOCK_RATE_SELECTION_0       = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MMODE_CLOCK_RATE_SELECTION_0_LEN   = 10  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MMODE_CLOCK_RATE_SELECTION         = 14  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MMODE_CLOCK_RATE_SELECTION_LEN     = 10  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MMODE_CLOCK_DIV_4                  = 25  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MMODE_TIMEOUT_SEL                  = 26  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MMODE_TIMEOUT_SEL_LEN              = 2   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MMODE_RECEIVER_MODE                = 29  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MMODE_RECEIVER_MODE_LEN            = 3   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MREFP0_PORT_HOT_PLUG_0             = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MREFP0_PORT_HOT_PLUG               = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MREFP0_PORT_HOT_PLUG_2             = 2   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MREFP0_PORT_HOT_PLUG_3             = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MREFP0_PORT_HOT_PLUG_4             = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MREFP0_PORT_HOT_PLUG_5             = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MREFP0_PORT_HOT_PLUG_6             = 6   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MREFP0_PORT_HOT_PLUG_7             = 7   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MREFP1_PORT_HOT_PLUG_0             = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MREFP1_PORT_HOT_PLUG               = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MREFP1_PORT_HOT_PLUG_2             = 2   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MREFP1_PORT_HOT_PLUG_3             = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MREFP1_PORT_HOT_PLUG_4             = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MREFP1_PORT_HOT_PLUG_5             = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MREFP1_PORT_HOT_PLUG_6             = 6   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MREFP1_PORT_HOT_PLUG_7             = 7   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MRESB0_BRIDGE_GENERAL_RESET        = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MRESB0_BRIDGE_ERROR_RESET          = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MRESB0_SET_DMA_IRQ_SUSPEND_MODE    = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MRESB0_CLEAR_DMA_IRQ_SUSPEND_MODE  = 6   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MRESB0_SET_DLY_MEASUREMENT         = 7   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP0_PORT_GENERAL_RESET          = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP0_PORT_ERROR_RESET            = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP0_ALL_BRIDGE_GENERAL_RESET    = 2   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP0_ALL_PORT_GENERAL_RESET      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP0_CONTROL_REGISTER_RESET      = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP0_PARITY_ERROR_RESET          = 5   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP1_PORT_GENERAL_RESET          = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP1_PORT_ERROR_RESET            = 1   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP2_PORT_GENERAL_RESET_2        = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP2_PORT_ERROR_RESET_2          = 1   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP3_PORT_GENERAL_RESET_3        = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP3_PORT_ERROR_RESET_3          = 1   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP4_PORT_GENERAL_RESET_4        = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP4_PORT_ERROR_RESET_4          = 1   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP5_PORT_GENERAL_RESET_5        = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP5_PORT_ERROR_RESET_5          = 1   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP6_PORT_GENERAL_RESET_6        = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP6_PORT_ERROR_RESET_6          = 1   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP7_PORT_GENERAL_RESET_7        = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MRESP7_PORT_ERROR_RESET_7          = 1   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MSENP0_SET_PORT_ENABLE             = 0   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSENP0_SET_PORT_ENABLE_LEN         = 8   ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP0_PORT0_ERROR_CODE_0          = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP0_PORT0_ERROR_CODE_0_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP0_PORT0_ERROR_CODE            = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP0_PORT0_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP0_PORT0_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP0_PORT0_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP0_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP0_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP0_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP0_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP0_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP1_PORT1_ERROR_CODE_0          = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP1_PORT1_ERROR_CODE_0_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP1_PORT1_ERROR_CODE            = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP1_PORT1_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP1_PORT1_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP1_PORT1_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP1_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP1_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP1_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP1_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP1_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP2_PORT2_ERROR_CODE_0          = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP2_PORT2_ERROR_CODE_0_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP2_PORT2_ERROR_CODE            = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP2_PORT2_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP2_PORT2_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP2_PORT2_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP2_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP2_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP2_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP2_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP2_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP3_PORT3_ERROR_CODE_0          = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP3_PORT3_ERROR_CODE_0_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP3_PORT3_ERROR_CODE            = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP3_PORT3_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP3_PORT3_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP3_PORT3_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP3_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP3_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP3_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP3_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP3_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP4_PORT4_ERROR_CODE_0          = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP4_PORT4_ERROR_CODE_0_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP4_PORT4_ERROR_CODE            = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP4_PORT4_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP4_PORT4_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP4_PORT4_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP4_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP4_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP4_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP4_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP4_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP5_PORT5_ERROR_CODE_0          = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP5_PORT5_ERROR_CODE_0_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP5_PORT5_ERROR_CODE            = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP5_PORT5_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP5_PORT5_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP5_PORT5_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP5_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP5_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP5_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP5_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP5_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP6_PORT6_ERROR_CODE_0          = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP6_PORT6_ERROR_CODE_0_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP6_PORT6_ERROR_CODE            = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP6_PORT6_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP6_PORT6_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP6_PORT6_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP6_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP6_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP6_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP6_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP6_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP7_PORT7_ERROR_CODE_0          = 1   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP7_PORT7_ERROR_CODE_0_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP7_PORT7_ERROR_CODE            = 5   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP7_PORT7_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP7_PORT7_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP7_PORT7_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP7_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP7_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP7_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP7_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_A_MST_1_MSTAP7_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSI_A_SDMA_DMA_REQUEST_1_SELECT                = 3   ;
static const uint8_t P9A_PERV_FSI_A_SDMA_DMA_REQUEST_1_SELECT_LEN            = 5   ;
static const uint8_t P9A_PERV_FSI_A_SDMA_DMA_REQUEST_2_SELECT                = 11  ;
static const uint8_t P9A_PERV_FSI_A_SDMA_DMA_REQUEST_2_SELECT_LEN            = 5   ;
static const uint8_t P9A_PERV_FSI_A_SDMA_CMFSI_PORT_ID_SELECT                = 19  ;
static const uint8_t P9A_PERV_FSI_A_SDMA_CMFSI_PORT_ID_SELECT_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_A_SDMA_CMFSI_SLAVE_ID_SELECT               = 22  ;
static const uint8_t P9A_PERV_FSI_A_SDMA_CMFSI_SLAVE_ID_SELECT_LEN           = 2   ;
static const uint8_t P9A_PERV_FSI_A_SDMA_MFSI_PORT_ID_SELECT                 = 27  ;
static const uint8_t P9A_PERV_FSI_A_SDMA_MFSI_PORT_ID_SELECT_LEN             = 3   ;
static const uint8_t P9A_PERV_FSI_A_SDMA_MFSI_SLAVE_ID_SELECT                = 30  ;
static const uint8_t P9A_PERV_FSI_A_SDMA_MFSI_SLAVE_ID_SELECT_LEN            = 2   ;

static const uint8_t P9A_PERV_FSI_A_SLBUS_FORCE_LBUS_OWNERSHIP               = 0   ;
static const uint8_t P9A_PERV_FSI_A_SLBUS_REQUEST_LBUS_OWNERSHIP             = 1   ;
static const uint8_t P9A_PERV_FSI_A_SLBUS_RELEASE_LBUS_OWNERSHIP             = 2   ;
static const uint8_t P9A_PERV_FSI_A_SLBUS_RELEASE_LBUS_OWNERSHIP_LEN         = 2   ;
static const uint8_t P9A_PERV_FSI_A_SLBUS_RESET_LBUS_REQUEST                 = 4   ;
static const uint8_t P9A_PERV_FSI_A_SLBUS_LOCK_LBUS_ACCESS                   = 8   ;
static const uint8_t P9A_PERV_FSI_A_SLBUS_LOCK_LBUS_ACCESS_LEN               = 8   ;

static const uint8_t P9A_PERV_FSI_A_SMODE_WARM_START_COMPLETED               = 0   ;
static const uint8_t P9A_PERV_FSI_A_SMODE_ENABLE_AUX_PORT_UNUSED             = 1   ;
static const uint8_t P9A_PERV_FSI_A_SMODE_ENABLE_HW_ERROR_RECOVERY           = 2   ;
static const uint8_t P9A_PERV_FSI_A_SMODE_OWN_ID_THIS_SLAVE                  = 6   ;
static const uint8_t P9A_PERV_FSI_A_SMODE_OWN_ID_THIS_SLAVE_LEN              = 2   ;
static const uint8_t P9A_PERV_FSI_A_SMODE_ECHO_DELAY_CYCLES                  = 8   ;
static const uint8_t P9A_PERV_FSI_A_SMODE_ECHO_DELAY_CYCLES_LEN              = 4   ;
static const uint8_t P9A_PERV_FSI_A_SMODE_SEND_DELAY_CYCLES                  = 12  ;
static const uint8_t P9A_PERV_FSI_A_SMODE_SEND_DELAY_CYCLES_LEN              = 4   ;
static const uint8_t P9A_PERV_FSI_A_SMODE_LBUS_CLOCK_DIVIDER                 = 20  ;
static const uint8_t P9A_PERV_FSI_A_SMODE_LBUS_CLOCK_DIVIDER_LEN             = 4   ;
static const uint8_t P9A_PERV_FSI_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1      = 28  ;
static const uint8_t P9A_PERV_FSI_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1_LEN  = 4   ;

static const uint8_t P9A_PERV_FSI_A_SSTAT_ANY_SLV_ERROR                      = 0   ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_ID_DIRTY                           = 1   ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_WARM_START_SYNC_FR_LEFT            = 2   ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_WARM_START_SYNC_FR_RIGHT           = 3   ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_MAIL_DELIVERED_TO_LEFT             = 4   ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_MAIL_DELIVERED_TO_RIGHT            = 5   ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_MAIL_RECEIVED_FR_LEFT              = 6   ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_MAIL_RECEIVED_FR_RIGHT             = 7   ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT         = 8   ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT_LEN     = 4   ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT        = 12  ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT_LEN    = 4   ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_LBUS_REQ_SYNC_FR_LEFT              = 16  ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_LBUS_REQ_SYNC_FR_RIGHT             = 17  ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_THIS_LBUS_REQ                      = 18  ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_LBUS_LOCK                          = 19  ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_LBUS_GNT                           = 20  ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_LBUS_GNT_LEN                       = 2   ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_THIS_SIDE                          = 22  ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_THIS_SIDE_LEN                      = 2   ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_OWNERSHIP_FF1                      = 24  ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_OWNERSHIP_FF2                      = 25  ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_AUX_DI_LEVEL                       = 26  ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_AUX_DI_REFERENCE                   = 27  ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_CRC_ERR_CTR                        = 28  ;
static const uint8_t P9A_PERV_FSI_A_SSTAT_CRC_ERR_CTR_LEN                    = 4   ;

static const uint8_t P9A_PERV_FSI_B_LLMOD_EXTEND_TIMO                        = 29  ;
static const uint8_t P9A_PERV_FSI_B_LLMOD_DISABLE_GAP                        = 30  ;
static const uint8_t P9A_PERV_FSI_B_LLMOD_ASYNC_MODE                         = 31  ;

static const uint8_t P9A_PERV_FSI_B_LLSTAT_RESERVED_0                        = 0   ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_RESERVED_0_LEN                    = 7   ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_NO_CLK                            = 7   ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_RESERVED_2                        = 8   ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_RESERVED_2_LEN                    = 2   ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_BAD_HANDSHAKE_AT_START            = 10  ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_TIMEOUT                           = 11  ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_LBUS_BUSY                         = 12  ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_OPB_BUSY                          = 13  ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_RESERVED_3                        = 14  ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_BREAK_PENDING                     = 15  ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_RESERVED_4                        = 16  ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_RESERVED_4_LEN                    = 2   ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_HANDSHAKE_STATE                   = 18  ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_HANDSHAKE_STATE_LEN               = 2   ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_CFAM_CYCLE_TIME                   = 20  ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_CFAM_CYCLE_TIME_LEN               = 4   ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_REFCLOCK_STATUS                   = 24  ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_REFCLOCK_STATUS_LEN               = 4   ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_RESERVED_5                        = 28  ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_RESERVED_5_LEN                    = 3   ;
static const uint8_t P9A_PERV_FSI_B_LLSTAT_ASYNC_MODE                        = 31  ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MAEB_BRIDGE_ERROR                  = 0   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MAEB_BRIDGE_ERROR         = 0   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MCENP0_CLR_PORT_ENABLE             = 0   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MCENP0_CLR_PORT_ENABLE_LEN         = 8   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MCENP0_CLR_PORT_ENABLE    = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MCENP0_CLR_PORT_ENABLE_LEN = 8   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MENP0_PORT_ENABLE                  = 0   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MENP0_PORT_1_ENABLE                = 1   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MENP0_PORT_2_ENABLE                = 2   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MENP0_PORT_3_ENABLE                = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MENP0_PORT_4_ENABLE                = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MENP0_PORT_5_ENABLE                = 5   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MENP0_PORT_6_ENABLE                = 6   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MENP0_PORT_7_ENABLE                = 7   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MENP0_PORT_ENABLE         = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MENP0_PORT_1_ENABLE       = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MENP0_PORT_2_ENABLE       = 2   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MENP0_PORT_3_ENABLE       = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MENP0_PORT_4_ENABLE       = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MENP0_PORT_5_ENABLE       = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MENP0_PORT_6_ENABLE       = 6   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MENP0_PORT_7_ENABLE       = 7   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_FIRST_ERROR                 = 0   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_FIRST_ERROR_LEN             = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_CRC_ERROR_COUNT             = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_MMODE_PARITY_CHECK          = 8   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_MDLYR_PARITY_CHECK          = 9   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_MCRSP0_PARITY_CHECK         = 10  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_MENP0_PARITY_CHECK          = 11  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_MSIEP0_PARITY_CHECK         = 12  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_MSSIEP0_PARITY_CHECK        = 13  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_REGISTER_ACCESS_FSM_CHECK   = 14  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_OPB_BUS_ACCESS_FSM_CHECK    = 15  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_REGISTER_ACCESS_ERROR       = 16  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST     = 17  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST_LEN = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_ACTUAL_ERROR                = 20  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_ACTUAL_ERROR_LEN            = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_SELECTED_ERROR              = 24  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_SELECTED_ERROR_LEN          = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT      = 29  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT_LEN  = 3   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_FIRST_ERROR        = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_FIRST_ERROR_LEN    = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_CRC_ERROR_COUNT    = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_CRC_ERROR_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_MMODE_PARITY_CHECK = 8   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_MDLYR_PARITY_CHECK = 9   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_MCRSP0_PARITY_CHECK = 10  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_MENP0_PARITY_CHECK = 11  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_MSIEP0_PARITY_CHECK = 12  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_MSSIEP0_PARITY_CHECK = 13  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_REGISTER_ACCESS_FSM_CHECK = 14  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_OPB_BUS_ACCESS_FSM_CHECK = 15  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_REGISTER_ACCESS_ERROR = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST = 17  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_ACTUAL_ERROR       = 20  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_ACTUAL_ERROR_LEN   = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_SELECTED_ERROR     = 24  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_SELECTED_ERROR_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT = 29  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT_LEN = 3   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MLEVP0_PORT_LEVEL                  = 0   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MLEVP0_PORT_LEVEL_1                = 1   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MLEVP0_PORT_LEVEL_2                = 2   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MLEVP0_PORT_LEVEL_3                = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MLEVP0_PORT_LEVEL_4                = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MLEVP0_PORT_LEVEL_5                = 5   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MLEVP0_PORT_LEVEL_6                = 6   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MLEVP0_PORT_LEVEL_7                = 7   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MLEVP0_PORT_LEVEL         = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MLEVP0_PORT_LEVEL_1       = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MLEVP0_PORT_LEVEL_2       = 2   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MLEVP0_PORT_LEVEL_3       = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MLEVP0_PORT_LEVEL_4       = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MLEVP0_PORT_LEVEL_5       = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MLEVP0_PORT_LEVEL_6       = 6   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MLEVP0_PORT_LEVEL_7       = 7   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MLEVP1_PORT_LEVEL                  = 0   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MLEVP1_PORT_LEVEL_1                = 1   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MLEVP1_PORT_LEVEL_2                = 2   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MLEVP1_PORT_LEVEL_3                = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MLEVP1_PORT_LEVEL_4                = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MLEVP1_PORT_LEVEL_5                = 5   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MLEVP1_PORT_LEVEL_6                = 6   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MLEVP1_PORT_LEVEL_7                = 7   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MLEVP1_PORT_LEVEL         = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MLEVP1_PORT_LEVEL_1       = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MLEVP1_PORT_LEVEL_2       = 2   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MLEVP1_PORT_LEVEL_3       = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MLEVP1_PORT_LEVEL_4       = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MLEVP1_PORT_LEVEL_5       = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MLEVP1_PORT_LEVEL_6       = 6   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MLEVP1_PORT_LEVEL_7       = 7   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MMODE_ENABLE_IPOLL_AND_DMA         = 0   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY     = 1   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS = 2   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MMODE_ENABLE_PARITY_CHECK          = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MMODE_CLOCK_RATE_SELECTION         = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MMODE_CLOCK_RATE_SELECTION_LEN     = 10  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MMODE_CLOCK_RATE_SELECTION_1       = 14  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MMODE_CLOCK_RATE_SELECTION_1_LEN   = 10  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MMODE_CLOCK_DIV_4                  = 25  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MMODE_TIMEOUT_SEL                  = 26  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MMODE_TIMEOUT_SEL_LEN              = 2   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MMODE_RECEIVER_MODE                = 29  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MMODE_RECEIVER_MODE_LEN            = 3   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MMODE_ENABLE_IPOLL_AND_DMA = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS = 2   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MMODE_ENABLE_PARITY_CHECK = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MMODE_CLOCK_RATE_SELECTION = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MMODE_CLOCK_RATE_SELECTION_LEN = 10  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MMODE_CLOCK_RATE_SELECTION_1 = 14  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MMODE_CLOCK_RATE_SELECTION_1_LEN = 10  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MMODE_CLOCK_DIV_4         = 25  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MMODE_TIMEOUT_SEL         = 26  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MMODE_TIMEOUT_SEL_LEN     = 2   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MMODE_RECEIVER_MODE       = 29  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MMODE_RECEIVER_MODE_LEN   = 3   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MREFP0_PORT_HOT_PLUG               = 0   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MREFP0_PORT_HOT_PLUG_1             = 1   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MREFP0_PORT_HOT_PLUG_2             = 2   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MREFP0_PORT_HOT_PLUG_3             = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MREFP0_PORT_HOT_PLUG_4             = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MREFP0_PORT_HOT_PLUG_5             = 5   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MREFP0_PORT_HOT_PLUG_6             = 6   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MREFP0_PORT_HOT_PLUG_7             = 7   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MREFP0_PORT_HOT_PLUG      = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MREFP0_PORT_HOT_PLUG_1    = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MREFP0_PORT_HOT_PLUG_2    = 2   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MREFP0_PORT_HOT_PLUG_3    = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MREFP0_PORT_HOT_PLUG_4    = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MREFP0_PORT_HOT_PLUG_5    = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MREFP0_PORT_HOT_PLUG_6    = 6   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MREFP0_PORT_HOT_PLUG_7    = 7   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MREFP1_PORT_HOT_PLUG               = 0   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MREFP1_PORT_HOT_PLUG_1             = 1   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MREFP1_PORT_HOT_PLUG_2             = 2   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MREFP1_PORT_HOT_PLUG_3             = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MREFP1_PORT_HOT_PLUG_4             = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MREFP1_PORT_HOT_PLUG_5             = 5   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MREFP1_PORT_HOT_PLUG_6             = 6   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MREFP1_PORT_HOT_PLUG_7             = 7   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MREFP1_PORT_HOT_PLUG      = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MREFP1_PORT_HOT_PLUG_1    = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MREFP1_PORT_HOT_PLUG_2    = 2   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MREFP1_PORT_HOT_PLUG_3    = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MREFP1_PORT_HOT_PLUG_4    = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MREFP1_PORT_HOT_PLUG_5    = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MREFP1_PORT_HOT_PLUG_6    = 6   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MREFP1_PORT_HOT_PLUG_7    = 7   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MRESB0_BRIDGE_GENERAL_RESET        = 0   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MRESB0_BRIDGE_ERROR_RESET          = 1   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MRESB0_SET_DMA_IRQ_SUSPEND_MODE    = 5   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MRESB0_CLEAR_DMA_IRQ_SUSPEND_MODE  = 6   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MRESB0_SET_DLY_MEASUREMENT         = 7   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESB0_BRIDGE_GENERAL_RESET = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESB0_BRIDGE_ERROR_RESET = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESB0_SET_DMA_IRQ_SUSPEND_MODE = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESB0_CLEAR_DMA_IRQ_SUSPEND_MODE = 6   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESB0_SET_DLY_MEASUREMENT = 7   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP0_PORT_GENERAL_RESET          = 0   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP0_PORT_ERROR_RESET            = 1   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP0_ALL_BRIDGE_GENERAL_RESET    = 2   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP0_ALL_PORT_GENERAL_RESET      = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP0_CONTROL_REGISTER_RESET      = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP0_PARITY_ERROR_RESET          = 5   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP0_PORT_GENERAL_RESET = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP0_PORT_ERROR_RESET   = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP0_ALL_BRIDGE_GENERAL_RESET = 2   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP0_ALL_PORT_GENERAL_RESET = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP0_CONTROL_REGISTER_RESET = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP0_PARITY_ERROR_RESET = 5   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP1_PORT_GENERAL_RESET_1        = 0   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP1_PORT_ERROR_RESET_1          = 1   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP1_PORT_GENERAL_RESET_1 = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP1_PORT_ERROR_RESET_1 = 1   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP2_PORT_GENERAL_RESET_2        = 0   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP2_PORT_ERROR_RESET_2          = 1   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP2_PORT_GENERAL_RESET_2 = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP2_PORT_ERROR_RESET_2 = 1   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP3_PORT_GENERAL_RESET_3        = 0   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP3_PORT_ERROR_RESET_3          = 1   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP3_PORT_GENERAL_RESET_3 = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP3_PORT_ERROR_RESET_3 = 1   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP4_PORT_GENERAL_RESET_4        = 0   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP4_PORT_ERROR_RESET_4          = 1   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP4_PORT_GENERAL_RESET_4 = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP4_PORT_ERROR_RESET_4 = 1   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP5_PORT_GENERAL_RESET_5        = 0   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP5_PORT_ERROR_RESET_5          = 1   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP5_PORT_GENERAL_RESET_5 = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP5_PORT_ERROR_RESET_5 = 1   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP6_PORT_GENERAL_RESET_6        = 0   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP6_PORT_ERROR_RESET_6          = 1   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP6_PORT_GENERAL_RESET_6 = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP6_PORT_ERROR_RESET_6 = 1   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP7_PORT_GENERAL_RESET_7        = 0   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MRESP7_PORT_ERROR_RESET_7          = 1   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP7_PORT_GENERAL_RESET_7 = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MRESP7_PORT_ERROR_RESET_7 = 1   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MSENP0_SET_PORT_ENABLE             = 0   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSENP0_SET_PORT_ENABLE_LEN         = 8   ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSENP0_SET_PORT_ENABLE    = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSENP0_SET_PORT_ENABLE_LEN = 8   ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE            = 1   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_1          = 5   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_1_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP0_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP0_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP0_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP0_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP0_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE   = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_1 = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_1_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_2 = 9   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_2_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP0_FOURTH_ERROR       = 13  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP0_FOURTH_ERROR_LEN   = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP0_CRC_ERROR_COUNT    = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP0_CRC_ERROR_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP0_HOT_PLUG_FLAG      = 20  ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE            = 1   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_1          = 5   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_1_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP1_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP1_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP1_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP1_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP1_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE   = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_1 = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_1_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_2 = 9   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_2_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP1_FOURTH_ERROR       = 13  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP1_FOURTH_ERROR_LEN   = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP1_CRC_ERROR_COUNT    = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP1_CRC_ERROR_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP1_HOT_PLUG_FLAG      = 20  ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE            = 1   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_1          = 5   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_1_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP2_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP2_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP2_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP2_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP2_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE   = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_1 = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_1_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_2 = 9   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_2_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP2_FOURTH_ERROR       = 13  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP2_FOURTH_ERROR_LEN   = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP2_CRC_ERROR_COUNT    = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP2_CRC_ERROR_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP2_HOT_PLUG_FLAG      = 20  ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE            = 1   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_1          = 5   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_1_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP3_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP3_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP3_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP3_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP3_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE   = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_1 = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_1_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_2 = 9   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_2_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP3_FOURTH_ERROR       = 13  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP3_FOURTH_ERROR_LEN   = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP3_CRC_ERROR_COUNT    = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP3_CRC_ERROR_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP3_HOT_PLUG_FLAG      = 20  ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE            = 1   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_1          = 5   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_1_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP4_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP4_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP4_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP4_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP4_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE   = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_1 = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_1_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_2 = 9   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_2_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP4_FOURTH_ERROR       = 13  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP4_FOURTH_ERROR_LEN   = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP4_CRC_ERROR_COUNT    = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP4_CRC_ERROR_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP4_HOT_PLUG_FLAG      = 20  ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE            = 1   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_1          = 5   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_1_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP5_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP5_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP5_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP5_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP5_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE   = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_1 = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_1_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_2 = 9   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_2_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP5_FOURTH_ERROR       = 13  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP5_FOURTH_ERROR_LEN   = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP5_CRC_ERROR_COUNT    = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP5_CRC_ERROR_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP5_HOT_PLUG_FLAG      = 20  ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE            = 1   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_1          = 5   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_1_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP6_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP6_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP6_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP6_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP6_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE   = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_1 = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_1_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_2 = 9   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_2_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP6_FOURTH_ERROR       = 13  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP6_FOURTH_ERROR_LEN   = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP6_CRC_ERROR_COUNT    = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP6_CRC_ERROR_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP6_HOT_PLUG_FLAG      = 20  ;

static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE            = 1   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_LEN        = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_1          = 5   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_1_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_2          = 9   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_2_LEN      = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP7_FOURTH_ERROR                = 13  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP7_FOURTH_ERROR_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP7_CRC_ERROR_COUNT             = 16  ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP7_CRC_ERROR_COUNT_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI_B_MST_0_MSTAP7_HOT_PLUG_FLAG               = 20  ;

static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE   = 1   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_1 = 5   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_1_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_2 = 9   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_2_LEN = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP7_FOURTH_ERROR       = 13  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP7_FOURTH_ERROR_LEN   = 3   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP7_CRC_ERROR_COUNT    = 16  ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP7_CRC_ERROR_COUNT_LEN = 4   ;
static const uint8_t P9A_PERV_FSISHIFT_FSI_B_MST_0_MSTAP7_HOT_PLUG_FLAG      = 20  ;

static const uint8_t P9A_PERV_FSI_B_SDMA_DMA_REQUEST_1_SELECT                = 3   ;
static const uint8_t P9A_PERV_FSI_B_SDMA_DMA_REQUEST_1_SELECT_LEN            = 5   ;
static const uint8_t P9A_PERV_FSI_B_SDMA_DMA_REQUEST_2_SELECT                = 11  ;
static const uint8_t P9A_PERV_FSI_B_SDMA_DMA_REQUEST_2_SELECT_LEN            = 5   ;
static const uint8_t P9A_PERV_FSI_B_SDMA_CMFSI_PORT_ID_SELECT                = 19  ;
static const uint8_t P9A_PERV_FSI_B_SDMA_CMFSI_PORT_ID_SELECT_LEN            = 3   ;
static const uint8_t P9A_PERV_FSI_B_SDMA_CMFSI_SLAVE_ID_SELECT               = 22  ;
static const uint8_t P9A_PERV_FSI_B_SDMA_CMFSI_SLAVE_ID_SELECT_LEN           = 2   ;
static const uint8_t P9A_PERV_FSI_B_SDMA_MFSI_PORT_ID_SELECT                 = 27  ;
static const uint8_t P9A_PERV_FSI_B_SDMA_MFSI_PORT_ID_SELECT_LEN             = 3   ;
static const uint8_t P9A_PERV_FSI_B_SDMA_MFSI_SLAVE_ID_SELECT                = 30  ;
static const uint8_t P9A_PERV_FSI_B_SDMA_MFSI_SLAVE_ID_SELECT_LEN            = 2   ;

static const uint8_t P9A_PERV_FSI_B_SLBUS_FORCE_LBUS_OWNERSHIP               = 0   ;
static const uint8_t P9A_PERV_FSI_B_SLBUS_REQUEST_LBUS_OWNERSHIP             = 1   ;
static const uint8_t P9A_PERV_FSI_B_SLBUS_RELEASE_LBUS_OWNERSHIP             = 2   ;
static const uint8_t P9A_PERV_FSI_B_SLBUS_RELEASE_LBUS_OWNERSHIP_LEN         = 2   ;
static const uint8_t P9A_PERV_FSI_B_SLBUS_RESET_LBUS_REQUEST                 = 4   ;
static const uint8_t P9A_PERV_FSI_B_SLBUS_LOCK_LBUS_ACCESS                   = 8   ;
static const uint8_t P9A_PERV_FSI_B_SLBUS_LOCK_LBUS_ACCESS_LEN               = 8   ;

static const uint8_t P9A_PERV_FSI_B_SMODE_WARM_START_COMPLETED               = 0   ;
static const uint8_t P9A_PERV_FSI_B_SMODE_ENABLE_AUX_PORT_UNUSED             = 1   ;
static const uint8_t P9A_PERV_FSI_B_SMODE_ENABLE_HW_ERROR_RECOVERY           = 2   ;
static const uint8_t P9A_PERV_FSI_B_SMODE_OWN_ID_THIS_SLAVE                  = 6   ;
static const uint8_t P9A_PERV_FSI_B_SMODE_OWN_ID_THIS_SLAVE_LEN              = 2   ;
static const uint8_t P9A_PERV_FSI_B_SMODE_ECHO_DELAY_CYCLES                  = 8   ;
static const uint8_t P9A_PERV_FSI_B_SMODE_ECHO_DELAY_CYCLES_LEN              = 4   ;
static const uint8_t P9A_PERV_FSI_B_SMODE_SEND_DELAY_CYCLES                  = 12  ;
static const uint8_t P9A_PERV_FSI_B_SMODE_SEND_DELAY_CYCLES_LEN              = 4   ;
static const uint8_t P9A_PERV_FSI_B_SMODE_LBUS_CLOCK_DIVIDER                 = 20  ;
static const uint8_t P9A_PERV_FSI_B_SMODE_LBUS_CLOCK_DIVIDER_LEN             = 4   ;
static const uint8_t P9A_PERV_FSI_B_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_0      = 24  ;
static const uint8_t P9A_PERV_FSI_B_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_0_LEN  = 4   ;

static const uint8_t P9A_PERV_FSI_B_SSTAT_ANY_SLV_ERROR                      = 0   ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_ID_DIRTY                           = 1   ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_WARM_START_SYNC_FR_LEFT            = 2   ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_WARM_START_SYNC_FR_RIGHT           = 3   ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_MAIL_DELIVERED_TO_LEFT             = 4   ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_MAIL_DELIVERED_TO_RIGHT            = 5   ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_MAIL_RECEIVED_FR_LEFT              = 6   ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_MAIL_RECEIVED_FR_RIGHT             = 7   ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT         = 8   ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT_LEN     = 4   ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT        = 12  ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT_LEN    = 4   ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT              = 16  ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT             = 17  ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_THIS_LBUS_REQ                      = 18  ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_LBUS_LOCK                          = 19  ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_LBUS_GNT                           = 20  ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_LBUS_GNT_LEN                       = 2   ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_THIS_SIDE                          = 22  ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_THIS_SIDE_LEN                      = 2   ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_OWNERSHIP_FF1                      = 24  ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_OWNERSHIP_FF2                      = 25  ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_AUX_DI_LEVEL                       = 26  ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_AUX_DI_REFERENCE                   = 27  ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_CRC_ERR_CTR                        = 28  ;
static const uint8_t P9A_PERV_FSI_B_SSTAT_CRC_ERR_CTR_LEN                    = 4   ;

static const uint8_t P9A_PERV_GPWRP_MAGIC_COOKIE                             = 0   ;
static const uint8_t P9A_PERV_GPWRP_MAGIC_COOKIE_LEN                         = 16  ;
static const uint8_t P9A_PERV_GPWRP_EN_OR_DIS_WRITE_PROTECTION               = 16  ;
static const uint8_t P9A_PERV_GPWRP_EN_OR_DIS_WRITE_PROTECTION_LEN           = 16  ;

static const uint8_t P9A_PERV_1_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN0             = 0   ;
static const uint8_t P9A_PERV_1_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN1             = 1   ;
static const uint8_t P9A_PERV_1_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN2             = 2   ;
static const uint8_t P9A_PERV_1_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN3             = 3   ;
static const uint8_t P9A_PERV_1_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN4             = 4   ;
static const uint8_t P9A_PERV_1_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN5             = 5   ;
static const uint8_t P9A_PERV_1_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN6             = 6   ;
static const uint8_t P9A_PERV_1_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN7             = 7   ;
static const uint8_t P9A_PERV_1_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN8             = 8   ;
static const uint8_t P9A_PERV_1_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN9             = 9   ;
static const uint8_t P9A_PERV_1_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN10            = 10  ;
static const uint8_t P9A_PERV_1_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN11            = 11  ;

static const uint8_t P9A_PERV_1_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN0             = 0   ;
static const uint8_t P9A_PERV_1_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN1             = 1   ;
static const uint8_t P9A_PERV_1_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN2             = 2   ;
static const uint8_t P9A_PERV_1_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN3             = 3   ;
static const uint8_t P9A_PERV_1_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN4             = 4   ;
static const uint8_t P9A_PERV_1_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN5             = 5   ;
static const uint8_t P9A_PERV_1_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN6             = 6   ;
static const uint8_t P9A_PERV_1_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN7             = 7   ;
static const uint8_t P9A_PERV_1_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN8             = 8   ;
static const uint8_t P9A_PERV_1_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN9             = 9   ;
static const uint8_t P9A_PERV_1_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN10            = 10  ;
static const uint8_t P9A_PERV_1_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN11            = 11  ;

static const uint8_t P9A_PERV_1_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN0             = 0   ;
static const uint8_t P9A_PERV_1_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN1             = 1   ;
static const uint8_t P9A_PERV_1_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN2             = 2   ;
static const uint8_t P9A_PERV_1_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN3             = 3   ;
static const uint8_t P9A_PERV_1_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN4             = 4   ;
static const uint8_t P9A_PERV_1_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN5             = 5   ;
static const uint8_t P9A_PERV_1_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN6             = 6   ;
static const uint8_t P9A_PERV_1_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN7             = 7   ;
static const uint8_t P9A_PERV_1_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN8             = 8   ;
static const uint8_t P9A_PERV_1_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN9             = 9   ;
static const uint8_t P9A_PERV_1_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN10            = 10  ;
static const uint8_t P9A_PERV_1_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN11            = 11  ;

static const uint8_t P9A_PERV_1_GXSTOP_TRIG_REG_GXSTP_IN0                    = 0   ;
static const uint8_t P9A_PERV_1_GXSTOP_TRIG_REG_GXSTP_IN1                    = 1   ;
static const uint8_t P9A_PERV_1_GXSTOP_TRIG_REG_GXSTP_IN2                    = 2   ;
static const uint8_t P9A_PERV_1_GXSTOP_TRIG_REG_GXSTP_IN3                    = 3   ;
static const uint8_t P9A_PERV_1_GXSTOP_TRIG_REG_GXSTP_IN4                    = 4   ;
static const uint8_t P9A_PERV_1_GXSTOP_TRIG_REG_GXSTP_IN5                    = 5   ;
static const uint8_t P9A_PERV_1_GXSTOP_TRIG_REG_GXSTP_IN6                    = 6   ;
static const uint8_t P9A_PERV_1_GXSTOP_TRIG_REG_GXSTP_IN7                    = 7   ;
static const uint8_t P9A_PERV_1_GXSTOP_TRIG_REG_GXSTP_IN8                    = 8   ;
static const uint8_t P9A_PERV_1_GXSTOP_TRIG_REG_GXSTP_IN9                    = 9   ;
static const uint8_t P9A_PERV_1_GXSTOP_TRIG_REG_GXSTP_IN10                   = 10  ;
static const uint8_t P9A_PERV_1_GXSTOP_TRIG_REG_GXSTP_IN11                   = 11  ;

static const uint8_t P9A_PERV_1_HANG_PULSE_0_REG_0                           = 0   ;
static const uint8_t P9A_PERV_1_HANG_PULSE_0_REG_0_LEN                       = 6   ;
static const uint8_t P9A_PERV_1_HANG_PULSE_0_REG_SUPPRESS                    = 6   ;

static const uint8_t P9A_PERV_1_HANG_PULSE_1_REG_1                           = 0   ;
static const uint8_t P9A_PERV_1_HANG_PULSE_1_REG_1_LEN                       = 6   ;
static const uint8_t P9A_PERV_1_HANG_PULSE_1_REG_SUPPRESS                    = 6   ;

static const uint8_t P9A_PERV_1_HANG_PULSE_2_REG_2                           = 0   ;
static const uint8_t P9A_PERV_1_HANG_PULSE_2_REG_2_LEN                       = 6   ;
static const uint8_t P9A_PERV_1_HANG_PULSE_2_REG_SUPPRESS                    = 6   ;

static const uint8_t P9A_PERV_1_HANG_PULSE_3_REG_3                           = 0   ;
static const uint8_t P9A_PERV_1_HANG_PULSE_3_REG_3_LEN                       = 6   ;
static const uint8_t P9A_PERV_1_HANG_PULSE_3_REG_SUPPRESS                    = 6   ;

static const uint8_t P9A_PERV_1_HANG_PULSE_4_REG_4                           = 0   ;
static const uint8_t P9A_PERV_1_HANG_PULSE_4_REG_4_LEN                       = 6   ;
static const uint8_t P9A_PERV_1_HANG_PULSE_4_REG_SUPPRESS                    = 6   ;

static const uint8_t P9A_PERV_1_HANG_PULSE_5_REG_5                           = 0   ;
static const uint8_t P9A_PERV_1_HANG_PULSE_5_REG_5_LEN                       = 6   ;
static const uint8_t P9A_PERV_1_HANG_PULSE_5_REG_SUPPRESS                    = 6   ;

static const uint8_t P9A_PERV_1_HANG_PULSE_6_REG_6                           = 0   ;
static const uint8_t P9A_PERV_1_HANG_PULSE_6_REG_6_LEN                       = 6   ;
static const uint8_t P9A_PERV_1_HANG_PULSE_6_REG_SUPPRESS                    = 6   ;

static const uint8_t P9A_PERV_1_HEARTBEAT_REG_DEAD                           = 0   ;

static const uint8_t P9A_PERV_1_HOSTATTN_IN0                                 = 0   ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN1                                 = 1   ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN2                                 = 2   ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN3                                 = 3   ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN4                                 = 4   ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN5                                 = 5   ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN6                                 = 6   ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN7                                 = 7   ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN8                                 = 8   ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN9                                 = 9   ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN10                                = 10  ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN11                                = 11  ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN12                                = 12  ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN13                                = 13  ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN14                                = 14  ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN15                                = 15  ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN16                                = 16  ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN17                                = 17  ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN18                                = 18  ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN19                                = 19  ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN20                                = 20  ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN21                                = 21  ;
static const uint8_t P9A_PERV_1_HOSTATTN_IN22                                = 22  ;

static const uint8_t P9A_PERV_1_HOSTATTN_MASK_IN                             = 0   ;
static const uint8_t P9A_PERV_1_HOSTATTN_MASK_IN_LEN                         = 22  ;

static const uint8_t P9A_PERV_HOST_MASK_REG_IPOLL_0                          = 0   ;
static const uint8_t P9A_PERV_HOST_MASK_REG_IPOLL_1                          = 1   ;
static const uint8_t P9A_PERV_HOST_MASK_REG_IPOLL_2                          = 2   ;
static const uint8_t P9A_PERV_HOST_MASK_REG_IPOLL_3                          = 3   ;
static const uint8_t P9A_PERV_HOST_MASK_REG_IPOLL_4                          = 4   ;
static const uint8_t P9A_PERV_HOST_MASK_REG_IPOLL_5                          = 5   ;
static const uint8_t P9A_PERV_HOST_MASK_REG_ERROR_0                          = 6   ;
static const uint8_t P9A_PERV_HOST_MASK_REG_ERROR_1                          = 7   ;
static const uint8_t P9A_PERV_HOST_MASK_REG_ERROR_2                          = 8   ;
static const uint8_t P9A_PERV_HOST_MASK_REG_ERROR_3                          = 9   ;
static const uint8_t P9A_PERV_HOST_MASK_REG_ERROR_4                          = 10  ;
static const uint8_t P9A_PERV_HOST_MASK_REG_ERROR_5                          = 11  ;

static const uint8_t P9A_PERV_IGNORE_PAR_REG_PARITY                          = 0   ;
static const uint8_t P9A_PERV_IGNORE_PAR_REG_DISABLE_ECC_CORRECTION          = 1   ;
static const uint8_t P9A_PERV_IGNORE_PAR_REG_ECC_S_BIT_ERROR                 = 2   ;
static const uint8_t P9A_PERV_IGNORE_PAR_REG_CHKSW_AR012                     = 3   ;

static const uint8_t P9A_PERV_1_INJECT_REG_THERM_TRIP                        = 0   ;
static const uint8_t P9A_PERV_1_INJECT_REG_THERM_TRIP_LEN                    = 2   ;
static const uint8_t P9A_PERV_1_INJECT_REG_THERM_MODE                        = 2   ;
static const uint8_t P9A_PERV_1_INJECT_REG_THERM_MODE_LEN                    = 2   ;

static const uint8_t P9A_PERV_FSI2PIB_INTERRUPT_STATUS_REG                   = 0   ;
static const uint8_t P9A_PERV_FSI2PIB_INTERRUPT_STATUS_REG_LEN               = 32  ;

static const uint8_t P9A_PERV_INTERRUPT1_REG_INTERRUPT1                      = 0   ;
static const uint8_t P9A_PERV_INTERRUPT1_REG_INTERRUPT1_LEN                  = 56  ;

static const uint8_t P9A_PERV_INTERRUPT2_REG_INTERRUPT2                      = 0   ;
static const uint8_t P9A_PERV_INTERRUPT2_REG_INTERRUPT2_LEN                  = 56  ;

static const uint8_t P9A_PERV_INTERRUPT3_REG_INTERRUPT3                      = 0   ;
static const uint8_t P9A_PERV_INTERRUPT3_REG_INTERRUPT3_LEN                  = 56  ;

static const uint8_t P9A_PERV_INTERRUPT4_REG_INTERRUPT4                      = 0   ;
static const uint8_t P9A_PERV_INTERRUPT4_REG_INTERRUPT4_LEN                  = 56  ;

static const uint8_t P9A_PERV_FSII2C_INTERRUPT_COND_A_INVALID_CMD_0          = 16  ;
static const uint8_t P9A_PERV_FSII2C_INTERRUPT_COND_A_LBUS_PARITY_ERROR_0    = 17  ;
static const uint8_t P9A_PERV_FSII2C_INTERRUPT_COND_A_BE_OV_ERROR_0          = 18  ;
static const uint8_t P9A_PERV_FSII2C_INTERRUPT_COND_A_BE_ACC_ERROR_0         = 19  ;
static const uint8_t P9A_PERV_FSII2C_INTERRUPT_COND_A_ARBITRATION_LOST_ERROR_0 = 20  ;
static const uint8_t P9A_PERV_FSII2C_INTERRUPT_COND_A_NACK_RECEIVED_ERROR_0  = 21  ;
static const uint8_t P9A_PERV_FSII2C_INTERRUPT_COND_A_DATA_REQUEST_0         = 22  ;
static const uint8_t P9A_PERV_FSII2C_INTERRUPT_COND_A_STOP_ERROR_0           = 24  ;

static const uint8_t P9A_PERV_INTERRUPT_CONF_REG_UNUSED0                     = 0   ;
static const uint8_t P9A_PERV_INTERRUPT_CONF_REG_SEL0                        = 1   ;
static const uint8_t P9A_PERV_INTERRUPT_CONF_REG_SEL0_LEN                    = 3   ;
static const uint8_t P9A_PERV_INTERRUPT_CONF_REG_UNUSED4                     = 4   ;
static const uint8_t P9A_PERV_INTERRUPT_CONF_REG_SEL1                        = 5   ;
static const uint8_t P9A_PERV_INTERRUPT_CONF_REG_SEL1_LEN                    = 3   ;
static const uint8_t P9A_PERV_INTERRUPT_CONF_REG_GP                          = 8   ;
static const uint8_t P9A_PERV_INTERRUPT_CONF_REG_CC                          = 9   ;
static const uint8_t P9A_PERV_INTERRUPT_CONF_REG_UNUSED2                     = 10  ;
static const uint8_t P9A_PERV_INTERRUPT_CONF_REG_UNUSED3                     = 11  ;

static const uint8_t P9A_PERV_INTERRUPT_HOLD_REG_HOLD                        = 0   ;
static const uint8_t P9A_PERV_INTERRUPT_HOLD_REG_HOLD_LEN                    = 26  ;

static const uint8_t P9A_PERV_FSII2C_INTERRUPT_MASK_REGISTER_A_INT_0         = 16  ;
static const uint8_t P9A_PERV_FSII2C_INTERRUPT_MASK_REGISTER_A_INT_0_LEN     = 16  ;

static const uint8_t P9A_PERV_FSII2C_INTERRUPT_MASK_REGISTER_READ_A_INT_0    = 16  ;
static const uint8_t P9A_PERV_FSII2C_INTERRUPT_MASK_REGISTER_READ_A_INT_0_LEN = 16  ;

static const uint8_t P9A_PERV_INTERRUPT_TYPE_MASK_REG_GP                     = 0   ;
static const uint8_t P9A_PERV_INTERRUPT_TYPE_MASK_REG_CC                     = 1   ;
static const uint8_t P9A_PERV_INTERRUPT_TYPE_MASK_REG_UNUSED2                = 2   ;
static const uint8_t P9A_PERV_INTERRUPT_TYPE_MASK_REG_UNUSED3                = 3   ;

static const uint8_t P9A_PERV_INTERRUPT_TYPE_REG_ATTENTION                   = 0   ;
static const uint8_t P9A_PERV_INTERRUPT_TYPE_REG_RECOVERABLE_ERROR           = 1   ;
static const uint8_t P9A_PERV_INTERRUPT_TYPE_REG_CHECKSTOP                   = 2   ;

static const uint8_t P9A_PERV_IODA_TCD_IDIAL_VLD                             = 0   ;
static const uint8_t P9A_PERV_IODA_TCD_IDIAL_RSVD0                           = 1   ;
static const uint8_t P9A_PERV_IODA_TCD_IDIAL_RSVD0_LEN                       = 5   ;
static const uint8_t P9A_PERV_IODA_TCD_IDIAL_PC                              = 6   ;
static const uint8_t P9A_PERV_IODA_TCD_IDIAL_PC_LEN                          = 2   ;
static const uint8_t P9A_PERV_IODA_TCD_IDIAL_PE                              = 8   ;
static const uint8_t P9A_PERV_IODA_TCD_IDIAL_PE_LEN                          = 4   ;
static const uint8_t P9A_PERV_IODA_TCD_IDIAL_EA                              = 12  ;
static const uint8_t P9A_PERV_IODA_TCD_IDIAL_EA_LEN                          = 37  ;
static const uint8_t P9A_PERV_IODA_TCD_IDIAL_RSVD1                           = 49  ;
static const uint8_t P9A_PERV_IODA_TCD_IDIAL_RSVD1_LEN                       = 15  ;

static const uint8_t P9A_PERV_IODA_TDR_IDIAL_RA                              = 0   ;
static const uint8_t P9A_PERV_IODA_TDR_IDIAL_RA_LEN                          = 39  ;
static const uint8_t P9A_PERV_IODA_TDR_IDIAL_RSVD0                           = 39  ;
static const uint8_t P9A_PERV_IODA_TDR_IDIAL_RSVD0_LEN                       = 2   ;
static const uint8_t P9A_PERV_IODA_TDR_IDIAL_PAR                             = 41  ;
static const uint8_t P9A_PERV_IODA_TDR_IDIAL_PAR_LEN                         = 5   ;

static const uint8_t P9A_PERV_IODA_TDR_MEM_IDIAL_RSVD0                       = 0   ;
static const uint8_t P9A_PERV_IODA_TDR_MEM_IDIAL_RSVD0_LEN                   = 13  ;
static const uint8_t P9A_PERV_IODA_TDR_MEM_IDIAL_RA                          = 13  ;
static const uint8_t P9A_PERV_IODA_TDR_MEM_IDIAL_RA_LEN                      = 39  ;
static const uint8_t P9A_PERV_IODA_TDR_MEM_IDIAL_RSVD1                       = 52  ;
static const uint8_t P9A_PERV_IODA_TDR_MEM_IDIAL_RSVD1_LEN                   = 10  ;
static const uint8_t P9A_PERV_IODA_TDR_MEM_IDIAL_PC                          = 62  ;
static const uint8_t P9A_PERV_IODA_TDR_MEM_IDIAL_PC_LEN                      = 2   ;

static const uint8_t P9A_PERV_FSB_IODA_TVT_TVT0_XLAT_ADDR                    = 0   ;
static const uint8_t P9A_PERV_FSB_IODA_TVT_TVT0_XLAT_ADDR_LEN                = 48  ;
static const uint8_t P9A_PERV_FSB_IODA_TVT_TVT0_TABLE_LEVEL                  = 48  ;
static const uint8_t P9A_PERV_FSB_IODA_TVT_TVT0_TABLE_LEVEL_LEN              = 3   ;
static const uint8_t P9A_PERV_FSB_IODA_TVT_TVT0_TABLE_SIZE                   = 51  ;
static const uint8_t P9A_PERV_FSB_IODA_TVT_TVT0_TABLE_SIZE_LEN               = 5   ;
static const uint8_t P9A_PERV_FSB_IODA_TVT_TVT0_SPARE                        = 56  ;
static const uint8_t P9A_PERV_FSB_IODA_TVT_TVT0_SPARE_LEN                    = 3   ;
static const uint8_t P9A_PERV_FSB_IODA_TVT_TVT0_PAGE_SIZE                    = 59  ;
static const uint8_t P9A_PERV_FSB_IODA_TVT_TVT0_PAGE_SIZE_LEN                = 5   ;

static const uint8_t P9A_PERV_IODA_XLT_EA_IDIAL_EA                           = 0   ;
static const uint8_t P9A_PERV_IODA_XLT_EA_IDIAL_EA_LEN                       = 37  ;
static const uint8_t P9A_PERV_IODA_XLT_EA_IDIAL_PE                           = 37  ;
static const uint8_t P9A_PERV_IODA_XLT_EA_IDIAL_PE_LEN                       = 4   ;
static const uint8_t P9A_PERV_IODA_XLT_EA_IDIAL_RNW                          = 41  ;
static const uint8_t P9A_PERV_IODA_XLT_EA_IDIAL_TAG                          = 42  ;
static const uint8_t P9A_PERV_IODA_XLT_EA_IDIAL_TAG_LEN                      = 8   ;
static const uint8_t P9A_PERV_IODA_XLT_EA_IDIAL_RSVD0                        = 50  ;
static const uint8_t P9A_PERV_IODA_XLT_EA_IDIAL_RSVD0_LEN                    = 14  ;

static const uint8_t P9A_PERV_1_KVREF_AND_VMEAS_MODE_STATUS_REG_START_CAL    = 0   ;
static const uint8_t P9A_PERV_1_KVREF_AND_VMEAS_MODE_STATUS_REG_DATA_SEL     = 1   ;
static const uint8_t P9A_PERV_1_KVREF_AND_VMEAS_MODE_STATUS_REG_BYPASS       = 2   ;
static const uint8_t P9A_PERV_1_KVREF_AND_VMEAS_MODE_STATUS_REG_MEASURE      = 8   ;
static const uint8_t P9A_PERV_1_KVREF_AND_VMEAS_MODE_STATUS_REG_MAX          = 9   ;
static const uint8_t P9A_PERV_1_KVREF_AND_VMEAS_MODE_STATUS_REG_MIN          = 10  ;
static const uint8_t P9A_PERV_1_KVREF_AND_VMEAS_MODE_STATUS_REG_CAL_DONE     = 16  ;
static const uint8_t P9A_PERV_1_KVREF_AND_VMEAS_MODE_STATUS_REG_TIMEOUT      = 18  ;
static const uint8_t P9A_PERV_1_KVREF_AND_VMEAS_MODE_STATUS_REG_RESULT_VALID = 19  ;

static const uint8_t P9A_PERV_1_KVREF_TUNE_DATA_FMU_KVREF_TUNE_DATA          = 0   ;
static const uint8_t P9A_PERV_1_KVREF_TUNE_DATA_FMU_KVREF_TUNE_DATA_LEN      = 12  ;

static const uint8_t P9A_PERV_1_LOCAL_FIR_IN0                                = 0   ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN1                                = 1   ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN2                                = 2   ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN3                                = 3   ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN4                                = 4   ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN5                                = 5   ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN6                                = 6   ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN7                                = 7   ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN8                                = 8   ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN9                                = 9   ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN10                               = 10  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN11                               = 11  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN12                               = 12  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN13                               = 13  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN14                               = 14  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN15                               = 15  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN16                               = 16  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN17                               = 17  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN18                               = 18  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN19                               = 19  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN20                               = 20  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN21                               = 21  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN22                               = 22  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN23                               = 23  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN24                               = 24  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN25                               = 25  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN26                               = 26  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN27                               = 27  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN28                               = 28  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN29                               = 29  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN30                               = 30  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN31                               = 31  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN32                               = 32  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN33                               = 33  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN34                               = 34  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN35                               = 35  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN36                               = 36  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN37                               = 37  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN38                               = 38  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN39                               = 39  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN40                               = 40  ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_IN41                               = 41  ;

static const uint8_t P9A_PERV_1_LOCAL_FIR_ACTION0_IN                         = 0   ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_ACTION0_IN_LEN                     = 42  ;

static const uint8_t P9A_PERV_1_LOCAL_FIR_ACTION1_IN                         = 0   ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_ACTION1_IN_LEN                     = 42  ;

static const uint8_t P9A_PERV_1_LOCAL_FIR_MASK_LFIR_IN                       = 0   ;
static const uint8_t P9A_PERV_1_LOCAL_FIR_MASK_LFIR_IN_LEN                   = 42  ;

static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN0                          = 0   ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN1                          = 1   ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN2                          = 2   ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN3                          = 3   ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN4                          = 4   ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN5                          = 5   ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN6                          = 6   ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN7                          = 7   ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN8                          = 8   ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN9                          = 9   ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN10                         = 10  ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN11                         = 11  ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN12                         = 12  ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN13                         = 13  ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN14                         = 14  ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN15                         = 15  ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN16                         = 16  ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN17                         = 17  ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN18                         = 18  ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN19                         = 19  ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN20                         = 20  ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN21                         = 21  ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_ERR_IN22                         = 22  ;

static const uint8_t P9A_PERV_1_LOCAL_XSTOP_MASK_IN                          = 0   ;
static const uint8_t P9A_PERV_1_LOCAL_XSTOP_MASK_IN_LEN                      = 22  ;

static const uint8_t P9A_PERV_M1A_DATA_AREA_0_MDA_M1A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1A_DATA_AREA_0_MDA_M1A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1A_DATA_AREA_1_MDA_M1A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1A_DATA_AREA_1_MDA_M1A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1A_DATA_AREA_10_MDA_M1A_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M1A_DATA_AREA_10_MDA_M1A_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M1A_DATA_AREA_11_MDA_M1A_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M1A_DATA_AREA_11_MDA_M1A_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M1A_DATA_AREA_12_MDA_M1A_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M1A_DATA_AREA_12_MDA_M1A_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M1A_DATA_AREA_13_MDA_M1A_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M1A_DATA_AREA_13_MDA_M1A_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M1A_DATA_AREA_14_MDA_M1A_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M1A_DATA_AREA_14_MDA_M1A_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1A_DATA_AREA_3_MDA_M1A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1A_DATA_AREA_3_MDA_M1A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1A_DATA_AREA_4_MDA_M1A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1A_DATA_AREA_4_MDA_M1A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1A_DATA_AREA_5_MDA_M1A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1A_DATA_AREA_5_MDA_M1A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1A_DATA_AREA_6_MDA_M1A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1A_DATA_AREA_6_MDA_M1A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1A_DATA_AREA_7_MDA_M1A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1A_DATA_AREA_7_MDA_M1A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1A_DATA_AREA_8_MDA_M1A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1A_DATA_AREA_8_MDA_M1A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1A_DATA_AREA_9_MDA_M1A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1A_DATA_AREA_9_MDA_M1A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1B_DATA_AREA_0_MDA_M1B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1B_DATA_AREA_0_MDA_M1B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1B_DATA_AREA_1_MDA_M1B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1B_DATA_AREA_1_MDA_M1B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1B_DATA_AREA_10_MDA_M1B_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M1B_DATA_AREA_10_MDA_M1B_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M1B_DATA_AREA_11_MDA_M1B_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M1B_DATA_AREA_11_MDA_M1B_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M1B_DATA_AREA_12_MDA_M1B_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M1B_DATA_AREA_12_MDA_M1B_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M1B_DATA_AREA_13_MDA_M1B_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M1B_DATA_AREA_13_MDA_M1B_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M1B_DATA_AREA_14_MDA_M1B_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M1B_DATA_AREA_14_MDA_M1B_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M1B_DATA_AREA_15_MDA_M1B_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M1B_DATA_AREA_15_MDA_M1B_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M1B_DATA_AREA_2_MDA_M1B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1B_DATA_AREA_2_MDA_M1B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1B_DATA_AREA_3_MDA_M1B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1B_DATA_AREA_3_MDA_M1B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1B_DATA_AREA_4_MDA_M1B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1B_DATA_AREA_4_MDA_M1B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1B_DATA_AREA_5_MDA_M1B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1B_DATA_AREA_5_MDA_M1B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1B_DATA_AREA_6_MDA_M1B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1B_DATA_AREA_6_MDA_M1B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1B_DATA_AREA_7_MDA_M1B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1B_DATA_AREA_7_MDA_M1B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M1B_DATA_AREA_9_MDA_M1B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M1B_DATA_AREA_9_MDA_M1B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2A_DATA_AREA_0_MDA_M2A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2A_DATA_AREA_0_MDA_M2A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2A_DATA_AREA_1_MDA_M2A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2A_DATA_AREA_1_MDA_M2A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2A_DATA_AREA_10_MDA_M2A_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M2A_DATA_AREA_10_MDA_M2A_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M2A_DATA_AREA_12_MDA_M2A_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M2A_DATA_AREA_12_MDA_M2A_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M2A_DATA_AREA_13_MDA_M2A_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M2A_DATA_AREA_13_MDA_M2A_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M2A_DATA_AREA_14_MDA_M2A_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M2A_DATA_AREA_14_MDA_M2A_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M2A_DATA_AREA_15_MDA_M2A_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M2A_DATA_AREA_15_MDA_M2A_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M2A_DATA_AREA_2_MDA_M2A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2A_DATA_AREA_2_MDA_M2A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2A_DATA_AREA_3_MDA_M2A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2A_DATA_AREA_3_MDA_M2A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2A_DATA_AREA_4_MDA_M2A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2A_DATA_AREA_4_MDA_M2A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2A_DATA_AREA_5_MDA_M2A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2A_DATA_AREA_5_MDA_M2A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2A_DATA_AREA_6_MDA_M2A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2A_DATA_AREA_6_MDA_M2A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2A_DATA_AREA_7_MDA_M2A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2A_DATA_AREA_7_MDA_M2A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2A_DATA_AREA_8_MDA_M2A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2A_DATA_AREA_8_MDA_M2A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2A_DATA_AREA_9_MDA_M2A_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2A_DATA_AREA_9_MDA_M2A_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2B_DATA_AREA_0_MDA_M2B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2B_DATA_AREA_0_MDA_M2B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2B_DATA_AREA_1_MDA_M2B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2B_DATA_AREA_1_MDA_M2B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2B_DATA_AREA_10_MDA_M2B_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M2B_DATA_AREA_10_MDA_M2B_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M2B_DATA_AREA_11_MDA_M2B_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M2B_DATA_AREA_11_MDA_M2B_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M2B_DATA_AREA_12_MDA_M2B_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M2B_DATA_AREA_12_MDA_M2B_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M2B_DATA_AREA_13_MDA_M2B_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M2B_DATA_AREA_13_MDA_M2B_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M2B_DATA_AREA_14_MDA_M2B_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M2B_DATA_AREA_14_MDA_M2B_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M2B_DATA_AREA_15_MDA_M2B_DATA_AREA             = 0   ;
static const uint8_t P9A_PERV_M2B_DATA_AREA_15_MDA_M2B_DATA_AREA_LEN         = 32  ;

static const uint8_t P9A_PERV_M2B_DATA_AREA_2_MDA_M2B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2B_DATA_AREA_2_MDA_M2B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2B_DATA_AREA_3_MDA_M2B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2B_DATA_AREA_3_MDA_M2B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2B_DATA_AREA_5_MDA_M2B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2B_DATA_AREA_5_MDA_M2B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2B_DATA_AREA_6_MDA_M2B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2B_DATA_AREA_6_MDA_M2B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2B_DATA_AREA_7_MDA_M2B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2B_DATA_AREA_7_MDA_M2B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2B_DATA_AREA_8_MDA_M2B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2B_DATA_AREA_8_MDA_M2B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_M2B_DATA_AREA_9_MDA_M2B_DATA_AREA              = 0   ;
static const uint8_t P9A_PERV_M2B_DATA_AREA_9_MDA_M2B_DATA_AREA_LEN          = 32  ;

static const uint8_t P9A_PERV_MAILBOX_1_HEADER_COMMAND_0_A_M1HC0A            = 0   ;
static const uint8_t P9A_PERV_MAILBOX_1_HEADER_COMMAND_0_A_M1HC0A_LEN        = 32  ;

static const uint8_t P9A_PERV_MAILBOX_1_HEADER_COMMAND_0_B_M1HC0B            = 0   ;
static const uint8_t P9A_PERV_MAILBOX_1_HEADER_COMMAND_0_B_M1HC0B_LEN        = 32  ;

static const uint8_t P9A_PERV_MAILBOX_1_HEADER_COMMAND_1_A_M1HC1A            = 0   ;
static const uint8_t P9A_PERV_MAILBOX_1_HEADER_COMMAND_1_A_M1HC1A_LEN        = 32  ;

static const uint8_t P9A_PERV_MAILBOX_1_HEADER_COMMAND_1_B_M1HC1B            = 0   ;
static const uint8_t P9A_PERV_MAILBOX_1_HEADER_COMMAND_1_B_M1HC1B_LEN        = 32  ;

static const uint8_t P9A_PERV_MAILBOX_1_HEADER_COMMAND_2_A_M1HC2A            = 0   ;
static const uint8_t P9A_PERV_MAILBOX_1_HEADER_COMMAND_2_A_M1HC2A_LEN        = 32  ;

static const uint8_t P9A_PERV_MAILBOX_1_HEADER_COMMAND_2_B_M1HC2B            = 0   ;
static const uint8_t P9A_PERV_MAILBOX_1_HEADER_COMMAND_2_B_M1HC2B_LEN        = 32  ;

static const uint8_t P9A_PERV_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_1_M1SASIM1_ENABLE_PIB_ERROR = 29  ;
static const uint8_t P9A_PERV_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_1_M1SASIM1_ENABLE_XUP = 30  ;
static const uint8_t P9A_PERV_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_1_M1SASIM1_ENABLE_PIB_PENDING = 31  ;

static const uint8_t P9A_PERV_MAILBOX_2_HEADER_COMMAND_0_A_M2HC0A            = 0   ;
static const uint8_t P9A_PERV_MAILBOX_2_HEADER_COMMAND_0_A_M2HC0A_LEN        = 32  ;

static const uint8_t P9A_PERV_MAILBOX_2_HEADER_COMMAND_0_B_M2HC0B            = 0   ;
static const uint8_t P9A_PERV_MAILBOX_2_HEADER_COMMAND_0_B_M2HC0B_LEN        = 32  ;

static const uint8_t P9A_PERV_MAILBOX_2_HEADER_COMMAND_1_A_M2HC1A            = 0   ;
static const uint8_t P9A_PERV_MAILBOX_2_HEADER_COMMAND_1_A_M2HC1A_LEN        = 32  ;

static const uint8_t P9A_PERV_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B            = 0   ;
static const uint8_t P9A_PERV_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_LEN        = 32  ;

static const uint8_t P9A_PERV_MAILBOX_2_HEADER_COMMAND_2_A_M2HC2A            = 0   ;
static const uint8_t P9A_PERV_MAILBOX_2_HEADER_COMMAND_2_A_M2HC2A_LEN        = 32  ;

static const uint8_t P9A_PERV_MAILBOX_2_HEADER_COMMAND_2_B_M2HC2B            = 0   ;
static const uint8_t P9A_PERV_MAILBOX_2_HEADER_COMMAND_2_B_M2HC2B_LEN        = 32  ;

static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_UNUSED_31_28 = 0   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_UNUSED_31_28_LEN = 4   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_ILLEGAL_OPERATION_ATTEMPTED_1 = 4   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_WRITE_FULL_PIB_1 = 5   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_READ_EMPTY_PIB_1 = 6   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_LBUS_B_RAM_PARITY_DETECTED_1 = 7   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_ADDRESS_OF_LBUS_PARITY_1 = 8   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_ADDRESS_OF_LBUS_PARITY_1_LEN = 7   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_CLEAR_1 = 15  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_UNUSED_15_12 = 16  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_UNUSED_15_12_LEN = 4   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_ILLEGAL_OPERATION_ATTEMPTED_2 = 20  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_WRITE_FULL_PIB_2 = 21  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_READ_EMPTY_PIB_2 = 22  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_LBUS_B_RAM_PARITY_DETECTED_2 = 23  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_ADDRESS_OF_LBUS_PARITY_2 = 24  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_ADDRESS_OF_LBUS_PARITY_2_LEN = 7   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_CLEAR_2 = 31  ;

static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_UNUSED_31_11 = 11  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_UNUSED_31_11_LEN = 10  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_PIB_ERROR_2 = 21  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_XUP_2 = 22  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_PIB_PENDING_2 = 23  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_UNUSED_7_3 = 24  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_UNUSED_7_3_LEN = 5   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_PIB_ERROR_1 = 29  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_XUP_1 = 30  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_PIB_PENDING_1 = 31  ;

static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_UNUSED_31_28 = 0   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_UNUSED_31_28_LEN = 4   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_ILLEGAL_OPERATION_ATTEMPTED_1 = 4   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_WRITE_FULL_PIB_A_1 = 5   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_READ_EMPTY_PIB_A_1 = 6   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_PIB_A_RAM_PARITY_DETECTED_1 = 7   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_ADDRESS_OF_PIB_PARITY_1 = 8   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_ADDRESS_OF_PIB_PARITY_1_LEN = 7   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_CLEAR_1 = 15  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_UNUSED_15_12 = 16  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_UNUSED_15_12_LEN = 4   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_ILLEGAL_OPERATION_ATTEMPTED_2 = 20  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_WRITE_FULL_PIB_A_2 = 21  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_READ_EMPTY_PIB_A_2 = 22  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_PIB_A_RAM_PARITY_DETECTED_2 = 23  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_ADDRESS_OF_PIB_PARITY_2 = 24  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_ADDRESS_OF_PIB_PARITY_2_LEN = 7   ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_CLEAR_2 = 31  ;

static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MSBDI_ABORT_MAILBOX_2 = 24  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MSBDI_ABORT_MAILBOX_1 = 25  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MSBDI_LBUS_ERROR_2 = 26  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MSBDI_LBUS_ERROR_1 = 27  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MSBDI_XDN_2 = 28  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MSBDI_XDN_1 = 29  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MSBDI_LBUS_PENDING_2 = 30  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MSBDI_LBUS_PENDING_1 = 31  ;

static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_MSBDIM1_ENABLE_LBUS_PENDING = 24  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_MSBDIM1_ENABLE_LBUS_PENDING_2 = 25  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_MSBDIM1_ENABLE_XDN = 26  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_MSBDIM1_ENABLE_XDN_2 = 27  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_MSBDIM1_ENABLE_LBUS_ERROR = 28  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_MSBDIM1_ENABLE_LBUS_ERROR_2 = 29  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_MSBDIM1_ENABLE_ABORT = 30  ;
static const uint8_t P9A_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_MSBDIM1_ENABLE_ABORT_2 = 31  ;

static const uint8_t P9A_PERV_MCAST_COMP_MASK_REG_MULTICAST_COMPARE_REGISTER = 0   ;
static const uint8_t P9A_PERV_MCAST_COMP_MASK_REG_MULTICAST_COMPARE_REGISTER_LEN = 64  ;

static const uint8_t P9A_PERV_MCAST_COMP_REG_MULTICAST_COMPARE_REGISTER      = 0   ;
static const uint8_t P9A_PERV_MCAST_COMP_REG_MULTICAST_COMPARE_REGISTER_LEN  = 2   ;

static const uint8_t P9A_PERV_MCAST_COMP_VAL_REG_MULTICAST_COMPARE_VALUE_REGISTER = 0   ;
static const uint8_t P9A_PERV_MCAST_COMP_VAL_REG_MULTICAST_COMPARE_VALUE_REGISTER_LEN = 64  ;

static const uint8_t P9A_PERV_MCAST_GRP_0_SLAVES_REG_GROUP                   = 0   ;
static const uint8_t P9A_PERV_MCAST_GRP_0_SLAVES_REG_GROUP_LEN               = 6   ;

static const uint8_t P9A_PERV_MCAST_GRP_1_SLAVES_REG_GROUP                   = 0   ;
static const uint8_t P9A_PERV_MCAST_GRP_1_SLAVES_REG_GROUP_LEN               = 6   ;

static const uint8_t P9A_PERV_MCAST_GRP_2_SLAVES_REG_GROUP                   = 0   ;
static const uint8_t P9A_PERV_MCAST_GRP_2_SLAVES_REG_GROUP_LEN               = 6   ;

static const uint8_t P9A_PERV_MCAST_GRP_3_SLAVES_REG_GROUP                   = 0   ;
static const uint8_t P9A_PERV_MCAST_GRP_3_SLAVES_REG_GROUP_LEN               = 6   ;

static const uint8_t P9A_PERV_MCAST_GRP_4_SLAVES_REG_GROUP                   = 0   ;
static const uint8_t P9A_PERV_MCAST_GRP_4_SLAVES_REG_GROUP_LEN               = 6   ;

static const uint8_t P9A_PERV_MCAST_GRP_5_SLAVES_REG_GROUP                   = 0   ;
static const uint8_t P9A_PERV_MCAST_GRP_5_SLAVES_REG_GROUP_LEN               = 6   ;

static const uint8_t P9A_PERV_MCAST_GRP_6_SLAVES_REG_GROUP                   = 0   ;
static const uint8_t P9A_PERV_MCAST_GRP_6_SLAVES_REG_GROUP_LEN               = 6   ;

static const uint8_t P9A_PERV_MIB_XIICAC_ICACHE_TAG_ADDR                     = 0   ;
static const uint8_t P9A_PERV_MIB_XIICAC_ICACHE_TAG_ADDR_LEN                 = 27  ;
static const uint8_t P9A_PERV_MIB_XIICAC_ICACHE_ERR                          = 32  ;
static const uint8_t P9A_PERV_MIB_XIICAC_PIB_IFETCH_PENDING                  = 34  ;
static const uint8_t P9A_PERV_MIB_XIICAC_XIMEM_MEM_IFETCH_PENDING            = 35  ;
static const uint8_t P9A_PERV_MIB_XIICAC_ICACHE_VALID                        = 36  ;
static const uint8_t P9A_PERV_MIB_XIICAC_ICACHE_VALID_LEN                    = 4   ;
static const uint8_t P9A_PERV_MIB_XIICAC_ICACHE_LINE2_VALID                  = 40  ;
static const uint8_t P9A_PERV_MIB_XIICAC_ICACHE_LINE2_VALID_LEN              = 4   ;
static const uint8_t P9A_PERV_MIB_XIICAC_ICACHE_LINE_PTR                     = 45  ;
static const uint8_t P9A_PERV_MIB_XIICAC_ICACHE_LINE2_ERR                    = 46  ;
static const uint8_t P9A_PERV_MIB_XIICAC_ICACHE_PREFETCH_PENDING             = 47  ;

static const uint8_t P9A_PERV_MIB_XIMEM_MEM_ADDR                             = 0   ;
static const uint8_t P9A_PERV_MIB_XIMEM_MEM_ADDR_LEN                         = 32  ;
static const uint8_t P9A_PERV_MIB_XIMEM_MEM_R_NW                             = 32  ;
static const uint8_t P9A_PERV_MIB_XIMEM_MEM_BUSY                             = 33  ;
static const uint8_t P9A_PERV_MIB_XIMEM_MEM_IMPRECISE_ERROR_PENDING          = 34  ;
static const uint8_t P9A_PERV_MIB_XIMEM_MEM_BYTE_ENABLE                      = 35  ;
static const uint8_t P9A_PERV_MIB_XIMEM_MEM_BYTE_ENABLE_LEN                  = 8   ;
static const uint8_t P9A_PERV_MIB_XIMEM_MEM_LINE_MODE                        = 43  ;
static const uint8_t P9A_PERV_MIB_XIMEM_MEM_ERROR                            = 49  ;
static const uint8_t P9A_PERV_MIB_XIMEM_MEM_ERROR_LEN                        = 3   ;
static const uint8_t P9A_PERV_MIB_XIMEM_MEM_IFETCH_PENDING                   = 62  ;
static const uint8_t P9A_PERV_MIB_XIMEM_MEM_DATAOP_PENDING                   = 63  ;

static const uint8_t P9A_PERV_MIB_XISGB_STORE_ADDRESS                        = 0   ;
static const uint8_t P9A_PERV_MIB_XISGB_STORE_ADDRESS_LEN                    = 32  ;
static const uint8_t P9A_PERV_MIB_XISGB_XIMEM_MEM_IMPRECISE_ERROR_PENDING    = 35  ;
static const uint8_t P9A_PERV_MIB_XISGB_SGB_BYTE_VALID                       = 36  ;
static const uint8_t P9A_PERV_MIB_XISGB_SGB_BYTE_VALID_LEN                   = 4   ;
static const uint8_t P9A_PERV_MIB_XISGB_SGB_FLUSH_PENDING                    = 63  ;

static const uint8_t P9A_PERV_1_MODE_REG_IN0                                 = 0   ;
static const uint8_t P9A_PERV_1_MODE_REG_IN1                                 = 1   ;
static const uint8_t P9A_PERV_1_MODE_REG_IN2                                 = 2   ;
static const uint8_t P9A_PERV_1_MODE_REG_IN3                                 = 3   ;
static const uint8_t P9A_PERV_1_MODE_REG_IN4                                 = 4   ;
static const uint8_t P9A_PERV_1_MODE_REG_IN5                                 = 5   ;
static const uint8_t P9A_PERV_1_MODE_REG_IN6                                 = 6   ;
static const uint8_t P9A_PERV_1_MODE_REG_IN7                                 = 7   ;
static const uint8_t P9A_PERV_1_MODE_REG_IN8                                 = 8   ;
static const uint8_t P9A_PERV_1_MODE_REG_IN9                                 = 9   ;
static const uint8_t P9A_PERV_1_MODE_REG_IN10                                = 10  ;
static const uint8_t P9A_PERV_1_MODE_REG_IN11                                = 11  ;
static const uint8_t P9A_PERV_1_MODE_REG_IN                                  = 12  ;
static const uint8_t P9A_PERV_1_MODE_REG_IN_LEN                              = 4   ;

static const uint8_t P9A_PERV_MODE_REGISTER_DCOMP_ENABLE                     = 0   ;
static const uint8_t P9A_PERV_MODE_REGISTER_ECC_ENABLE                       = 1   ;
static const uint8_t P9A_PERV_MODE_REGISTER_PROGRAM_ENABLE                   = 2   ;
static const uint8_t P9A_PERV_MODE_REGISTER_ECC_CHK_DISABLE                  = 3   ;
static const uint8_t P9A_PERV_MODE_REGISTER_UNUSED_4_15                      = 4   ;
static const uint8_t P9A_PERV_MODE_REGISTER_UNUSED_4_15_LEN                  = 12  ;
static const uint8_t P9A_PERV_MODE_REGISTER_CLK_RATE_SEL                     = 16  ;
static const uint8_t P9A_PERV_MODE_REGISTER_CLK_RATE_SEL_LEN                 = 16  ;

static const uint8_t P9A_PERV_FSII2C_MODE_REGISTER_A_BIT_RATE_DIVISOR_0      = 0   ;
static const uint8_t P9A_PERV_FSII2C_MODE_REGISTER_A_BIT_RATE_DIVISOR_0_LEN  = 16  ;
static const uint8_t P9A_PERV_FSII2C_MODE_REGISTER_A_PORT_NUMBER_0           = 16  ;
static const uint8_t P9A_PERV_FSII2C_MODE_REGISTER_A_PORT_NUMBER_0_LEN       = 6   ;
static const uint8_t P9A_PERV_FSII2C_MODE_REGISTER_A_FGAT_0                  = 28  ;
static const uint8_t P9A_PERV_FSII2C_MODE_REGISTER_A_DIAG_0                  = 29  ;
static const uint8_t P9A_PERV_FSII2C_MODE_REGISTER_A_PACING_ALLOW_0          = 30  ;
static const uint8_t P9A_PERV_FSII2C_MODE_REGISTER_A_WRAP_0                  = 31  ;

static const uint8_t P9A_PERV_1_MULTICAST_GROUP_1_MULTICAST1                 = 3   ;
static const uint8_t P9A_PERV_1_MULTICAST_GROUP_1_MULTICAST1_LEN             = 3   ;

static const uint8_t P9A_PERV_1_MULTICAST_GROUP_2_MULTICAST2                 = 3   ;
static const uint8_t P9A_PERV_1_MULTICAST_GROUP_2_MULTICAST2_LEN             = 3   ;

static const uint8_t P9A_PERV_1_MULTICAST_GROUP_3_MULTICAST3                 = 3   ;
static const uint8_t P9A_PERV_1_MULTICAST_GROUP_3_MULTICAST3_LEN             = 3   ;

static const uint8_t P9A_PERV_1_MULTICAST_GROUP_4_MULTICAST4                 = 3   ;
static const uint8_t P9A_PERV_1_MULTICAST_GROUP_4_MULTICAST4_LEN             = 3   ;

static const uint8_t P9A_PERV_1_NET_CTRL0_CHIPLET_ENABLE                     = 0   ;
static const uint8_t P9A_PERV_1_NET_CTRL0_PCB_EP_RESET                       = 1   ;
static const uint8_t P9A_PERV_1_NET_CTRL0_CLK_ASYNC_RESET                    = 2   ;
static const uint8_t P9A_PERV_1_NET_CTRL0_PLL_TEST_EN                        = 3   ;
static const uint8_t P9A_PERV_1_NET_CTRL0_PLL_RESET                          = 4   ;
static const uint8_t P9A_PERV_1_NET_CTRL0_PLL_BYPASS                         = 5   ;
static const uint8_t P9A_PERV_1_NET_CTRL0_VITAL_SCAN                         = 6   ;
static const uint8_t P9A_PERV_1_NET_CTRL0_VITAL_SCAN_IN                      = 7   ;
static const uint8_t P9A_PERV_1_NET_CTRL0_VITAL_PHASE                        = 8   ;
static const uint8_t P9A_PERV_1_NET_CTRL0_FLUSH_ALIGN_OVR                    = 9   ;
static const uint8_t P9A_PERV_1_NET_CTRL0_VITAL_AL                           = 10  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_ACT_DIS                            = 11  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_MPW1                               = 12  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_MPW2                               = 13  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_MPW3                               = 14  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_DELAY_LCLKR                        = 15  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_VITAL_THOLD                        = 16  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_FLUSH_SCAN_N                       = 17  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_FENCE_EN                           = 18  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_CPLT_RCTRL                         = 19  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_CPLT_DCTRL                         = 20  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_ADJ_FUNC_CLKSEL                    = 22  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_TP_SRAM_ENABLE                     = 23  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_TP_FENCE_PCB                       = 25  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_LVLTRANS_FENCE                     = 26  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_ARRAY_WRITE_ASSIST_EN              = 27  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_HTB_INTEST                         = 28  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_HTB_EXTEST                         = 29  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_PM_ACCESS                          = 30  ;
static const uint8_t P9A_PERV_1_NET_CTRL0_PLLFORCE_OUT_EN                    = 31  ;

static const uint8_t P9A_PERV_1_NET_CTRL1_PLL_CLKIN_SEL                      = 0   ;
static const uint8_t P9A_PERV_1_NET_CTRL1_CLK_DCC_BYPASS_EN                  = 1   ;
static const uint8_t P9A_PERV_1_NET_CTRL1_CLK_PDLY_BYPASS_EN                 = 2   ;
static const uint8_t P9A_PERV_1_NET_CTRL1_CLK_DIV_BYPASS_EN                  = 3   ;
static const uint8_t P9A_PERV_1_NET_CTRL1_REFCLK_CLKMUX0_SEL                 = 4   ;
static const uint8_t P9A_PERV_1_NET_CTRL1_REFCLK_CLKMUX1_SEL                 = 5   ;
static const uint8_t P9A_PERV_1_NET_CTRL1_PLL_BNDY_BYPASS_EN                 = 6   ;
static const uint8_t P9A_PERV_1_NET_CTRL1_DPLL_TEST_SEL                      = 8   ;
static const uint8_t P9A_PERV_1_NET_CTRL1_DPLL_TEST_SEL_LEN                  = 8   ;
static const uint8_t P9A_PERV_1_NET_CTRL1_SB_STRENGTH                        = 16  ;
static const uint8_t P9A_PERV_1_NET_CTRL1_SB_STRENGTH_LEN                    = 4   ;
static const uint8_t P9A_PERV_1_NET_CTRL1_ASYNC_TYPE                         = 20  ;
static const uint8_t P9A_PERV_1_NET_CTRL1_ASYNC_OBS                          = 21  ;
static const uint8_t P9A_PERV_1_NET_CTRL1_CPM_CAL_SET                        = 22  ;
static const uint8_t P9A_PERV_1_NET_CTRL1_SENSEADJ_RESET0                    = 23  ;
static const uint8_t P9A_PERV_1_NET_CTRL1_SENSEADJ_RESET1                    = 24  ;
static const uint8_t P9A_PERV_1_NET_CTRL1_CLK_PULSE_EN                       = 25  ;
static const uint8_t P9A_PERV_1_NET_CTRL1_CLK_PULSE_MODE                     = 26  ;
static const uint8_t P9A_PERV_1_NET_CTRL1_CLK_PULSE_MODE_LEN                 = 2   ;
static const uint8_t P9A_PERV_1_NET_CTRL1_PCB_ACCESS                         = 28  ;
static const uint8_t P9A_PERV_1_NET_CTRL1_PCB_ACCESS_LEN                     = 4   ;

static const uint8_t P9A_PERV_1_OPCG_ALIGN_INOP                              = 0   ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_INOP_LEN                          = 4   ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_SNOP                              = 4   ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_SNOP_LEN                          = 4   ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_ENOP                              = 8   ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_ENOP_LEN                          = 4   ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_INOP_WAIT                         = 12  ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_INOP_WAIT_LEN                     = 8   ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_SNOP_WAIT                         = 20  ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_SNOP_WAIT_LEN                     = 12  ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_ENOP_WAIT                         = 32  ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_ENOP_WAIT_LEN                     = 8   ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_INOP_FORCE_SG                     = 40  ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_SNOP_FORCE_SG                     = 41  ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_ENOP_FORCE_SG                     = 42  ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD                = 43  ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_SOURCE_SELECT                     = 44  ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_SOURCE_SELECT_LEN                 = 2   ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_UNUSED46                          = 46  ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_SCAN_RATIO                        = 47  ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_SCAN_RATIO_LEN                    = 5   ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_WAIT_CYCLES                       = 52  ;
static const uint8_t P9A_PERV_1_OPCG_ALIGN_WAIT_CYCLES_LEN                   = 12  ;

static const uint8_t P9A_PERV_1_OPCG_CAPT1_COUNT                             = 0   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_COUNT_LEN                         = 4   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_01                            = 4   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_01_LEN                        = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_02                            = 9   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_02_LEN                        = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_03                            = 14  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_03_LEN                        = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_04                            = 19  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_04_LEN                        = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_05                            = 24  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_05_LEN                        = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_06                            = 29  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_06_LEN                        = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_07                            = 34  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_07_LEN                        = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_08                            = 39  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_08_LEN                        = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_09                            = 44  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_09_LEN                        = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_10                            = 49  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_10_LEN                        = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_11                            = 54  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_11_LEN                        = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_12                            = 59  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT1_SEQ_12_LEN                        = 5   ;

static const uint8_t P9A_PERV_1_OPCG_CAPT2_UNUSED                            = 0   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_UNUSED_LEN                        = 4   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_13_01EVEN                     = 4   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_13_01EVEN_LEN                 = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_14_01ODD                      = 9   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_14_01ODD_LEN                  = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_15_02EVEN                     = 14  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_15_02EVEN_LEN                 = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_16_02ODD                      = 19  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_16_02ODD_LEN                  = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_17_03EVEN                     = 24  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_17_03EVEN_LEN                 = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_18_03ODD                      = 29  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_18_03ODD_LEN                  = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_19_04EVEN                     = 34  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_19_04EVEN_LEN                 = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_20_04ODD                      = 39  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_20_04ODD_LEN                  = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_21_05EVEN                     = 44  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_21_05EVEN_LEN                 = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_22_05ODD                      = 49  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_22_05ODD_LEN                  = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_23_06EVEN                     = 54  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_23_06EVEN_LEN                 = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_24_06ODD                      = 59  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT2_SEQ_24_06ODD_LEN                  = 5   ;

static const uint8_t P9A_PERV_1_OPCG_CAPT3_UNUSED                            = 0   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_UNUSED_LEN                        = 4   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_07EVEN                        = 4   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_07EVEN_LEN                    = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_07ODD                         = 9   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_07ODD_LEN                     = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_08EVEN                        = 14  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_08EVEN_LEN                    = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_08ODD                         = 19  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_08ODD_LEN                     = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_09EVEN                        = 24  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_09EVEN_LEN                    = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_09ODD                         = 29  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_09ODD_LEN                     = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_10EVEN                        = 34  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_10EVEN_LEN                    = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_10ODD                         = 39  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_10ODD_LEN                     = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_11EVEN                        = 44  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_11EVEN_LEN                    = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_11ODD                         = 49  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_11ODD_LEN                     = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_12EVEN                        = 54  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_12EVEN_LEN                    = 5   ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_12ODD                         = 59  ;
static const uint8_t P9A_PERV_1_OPCG_CAPT3_SEQ_12ODD_LEN                     = 5   ;

static const uint8_t P9A_PERV_1_OPCG_REG0_RUNN_MODE                          = 0   ;
static const uint8_t P9A_PERV_1_OPCG_REG0_GO                                 = 1   ;
static const uint8_t P9A_PERV_1_OPCG_REG0_RUN_SCAN0                          = 2   ;
static const uint8_t P9A_PERV_1_OPCG_REG0_SCAN0_MODE                         = 3   ;
static const uint8_t P9A_PERV_1_OPCG_REG0_IN_SLAVE_MODE                      = 4   ;
static const uint8_t P9A_PERV_1_OPCG_REG0_IN_MASTER_MODE                     = 5   ;
static const uint8_t P9A_PERV_1_OPCG_REG0_KEEP_MS_MODE                       = 6   ;
static const uint8_t P9A_PERV_1_OPCG_REG0_TRIGGER_ON_UNIT0_SYNC_LVL          = 7   ;
static const uint8_t P9A_PERV_1_OPCG_REG0_TRIGGER_ON_UNIT1_SYNC_LVL          = 8   ;
static const uint8_t P9A_PERV_1_OPCG_REG0_RUN_CHIPLET_SCAN0                  = 9   ;
static const uint8_t P9A_PERV_1_OPCG_REG0_RUN_CHIPLET_SCAN0_NO_PLL           = 10  ;
static const uint8_t P9A_PERV_1_OPCG_REG0_RUN_ON_UPDATE_DR                   = 11  ;
static const uint8_t P9A_PERV_1_OPCG_REG0_RUN_ON_CAPTURE_DR                  = 12  ;
static const uint8_t P9A_PERV_1_OPCG_REG0_STOP_RUNN_ON_XSTOP                 = 13  ;
static const uint8_t P9A_PERV_1_OPCG_REG0_STARTS_BIST                        = 14  ;
static const uint8_t P9A_PERV_1_OPCG_REG0_UNUSED1520                         = 15  ;
static const uint8_t P9A_PERV_1_OPCG_REG0_UNUSED1520_LEN                     = 6   ;
static const uint8_t P9A_PERV_1_OPCG_REG0_LOOP_COUNT                         = 21  ;
static const uint8_t P9A_PERV_1_OPCG_REG0_LOOP_COUNT_LEN                     = 43  ;

static const uint8_t P9A_PERV_1_OPCG_REG1_SCAN_COUNT                         = 0   ;
static const uint8_t P9A_PERV_1_OPCG_REG1_SCAN_COUNT_LEN                     = 12  ;
static const uint8_t P9A_PERV_1_OPCG_REG1_MISR_A_VAL                         = 12  ;
static const uint8_t P9A_PERV_1_OPCG_REG1_MISR_A_VAL_LEN                     = 12  ;
static const uint8_t P9A_PERV_1_OPCG_REG1_MISR_B_VAL                         = 24  ;
static const uint8_t P9A_PERV_1_OPCG_REG1_MISR_B_VAL_LEN                     = 12  ;
static const uint8_t P9A_PERV_1_OPCG_REG1_MISR_INIT_WAIT                     = 36  ;
static const uint8_t P9A_PERV_1_OPCG_REG1_MISR_INIT_WAIT_LEN                 = 12  ;
static const uint8_t P9A_PERV_1_OPCG_REG1_SUPPRESS_LAST_RUNN_CLK             = 48  ;
static const uint8_t P9A_PERV_1_OPCG_REG1_SCAN_CLK_USE_EVEN                  = 49  ;
static const uint8_t P9A_PERV_1_OPCG_REG1_UNUSED2                            = 50  ;
static const uint8_t P9A_PERV_1_OPCG_REG1_UNUSED2_LEN                        = 2   ;
static const uint8_t P9A_PERV_1_OPCG_REG1_RTIM_THOLD_FORCE                   = 52  ;
static const uint8_t P9A_PERV_1_OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL        = 53  ;
static const uint8_t P9A_PERV_1_OPCG_REG1_SG_HIGH_DURING_FILL                = 54  ;
static const uint8_t P9A_PERV_1_OPCG_REG1_LBIST_SKITTER_CTL                  = 55  ;
static const uint8_t P9A_PERV_1_OPCG_REG1_LBIST_SKITTER_CTL_LEN              = 2   ;
static const uint8_t P9A_PERV_1_OPCG_REG1_MISR_MODE                          = 57  ;
static const uint8_t P9A_PERV_1_OPCG_REG1_INFINITE_MODE                      = 58  ;
static const uint8_t P9A_PERV_1_OPCG_REG1_NSL_FILL_COUNT                     = 59  ;
static const uint8_t P9A_PERV_1_OPCG_REG1_NSL_FILL_COUNT_LEN                 = 5   ;

static const uint8_t P9A_PERV_1_OPCG_REG2_GO2                                = 0   ;
static const uint8_t P9A_PERV_1_OPCG_REG2_PRPG_WEIGHTING                     = 1   ;
static const uint8_t P9A_PERV_1_OPCG_REG2_PRPG_WEIGHTING_LEN                 = 3   ;
static const uint8_t P9A_PERV_1_OPCG_REG2_PRPG_VALUE                         = 4   ;
static const uint8_t P9A_PERV_1_OPCG_REG2_PRPG_VALUE_LEN                     = 12  ;
static const uint8_t P9A_PERV_1_OPCG_REG2_PRPG_A_VAL                         = 16  ;
static const uint8_t P9A_PERV_1_OPCG_REG2_PRPG_A_VAL_LEN                     = 12  ;
static const uint8_t P9A_PERV_1_OPCG_REG2_PRPG_B_VAL                         = 28  ;
static const uint8_t P9A_PERV_1_OPCG_REG2_PRPG_B_VAL_LEN                     = 12  ;
static const uint8_t P9A_PERV_1_OPCG_REG2_PRPG_MODE                          = 40  ;
static const uint8_t P9A_PERV_1_OPCG_REG2_UNUSED41_63                        = 41  ;
static const uint8_t P9A_PERV_1_OPCG_REG2_UNUSED41_63_LEN                    = 23  ;

static const uint8_t P9A_PERV_1_OSCERR_HOLD_CP                               = 0   ;
static const uint8_t P9A_PERV_1_OSCERR_HOLD_CP_LEN                           = 4   ;
static const uint8_t P9A_PERV_1_OSCERR_HOLD_MEM                              = 4   ;
static const uint8_t P9A_PERV_1_OSCERR_HOLD_MEM_LEN                          = 4   ;
static const uint8_t P9A_PERV_1_OSCERR_HOLD_GX                               = 8   ;
static const uint8_t P9A_PERV_1_OSCERR_HOLD_GX_LEN                           = 4   ;
static const uint8_t P9A_PERV_1_OSCERR_HOLD_CPLITE                           = 12  ;
static const uint8_t P9A_PERV_1_OSCERR_HOLD_CPLITE_LEN                       = 4   ;

static const uint8_t P9A_PERV_1_OSCERR_MASK_CP                               = 0   ;
static const uint8_t P9A_PERV_1_OSCERR_MASK_CP_LEN                           = 4   ;
static const uint8_t P9A_PERV_1_OSCERR_MASK_MEM                              = 4   ;
static const uint8_t P9A_PERV_1_OSCERR_MASK_MEM_LEN                          = 4   ;
static const uint8_t P9A_PERV_1_OSCERR_MASK_GX                               = 8   ;
static const uint8_t P9A_PERV_1_OSCERR_MASK_GX_LEN                           = 4   ;
static const uint8_t P9A_PERV_1_OSCERR_MASK_CPLITE                           = 12  ;
static const uint8_t P9A_PERV_1_OSCERR_MASK_CPLITE_LEN                       = 4   ;

static const uint8_t P9A_PERV_1_OSCERR_MCODE_IN                              = 0   ;
static const uint8_t P9A_PERV_1_OSCERR_MCODE_IN_LEN                          = 4   ;

static const uint8_t P9A_PERV_1_PCB_OPCG_GO_OPCGGO                           = 0   ;

static const uint8_t P9A_PERV_1_PCB_OPCG_STOP_OPCGSTOP                       = 0   ;

static const uint8_t P9A_PERV_PEEK4A0_FSI_A_MST_0_ACTUAL_ERROR               = 4   ;
static const uint8_t P9A_PERV_PEEK4A0_FSI_A_MST_0_ACTUAL_ERROR_LEN           = 4   ;
static const uint8_t P9A_PERV_PEEK4A0_FSI_A_MST_0_PORT_0_ENABLE              = 8   ;
static const uint8_t P9A_PERV_PEEK4A0_FSI_A_MST_0_PORT_1_ENABLE              = 12  ;
static const uint8_t P9A_PERV_PEEK4A0_FSI_A_MST_0_PORT_2_ENABLE              = 16  ;
static const uint8_t P9A_PERV_PEEK4A0_FSI_A_MST_0_PORT_3_ENABLE              = 20  ;
static const uint8_t P9A_PERV_PEEK4A0_FSI_A_MST_0_PORT_4_ENABLE              = 24  ;
static const uint8_t P9A_PERV_PEEK4A0_FSI_A_MST_0_PORT_5_ENABLE              = 28  ;

static const uint8_t P9A_PERV_PEEK4A4_FSI_A_MST_0_PORT_6_ENABLE              = 0   ;
static const uint8_t P9A_PERV_PEEK4A4_FSI_A_MST_0_PORT_7_ENABLE              = 4   ;
static const uint8_t P9A_PERV_PEEK4A4_FSI_A_MST_1_ACTUAL_ERROR               = 8   ;
static const uint8_t P9A_PERV_PEEK4A4_FSI_A_MST_1_ACTUAL_ERROR_LEN           = 4   ;
static const uint8_t P9A_PERV_PEEK4A4_FSI_A_MST_1_PORT_0_ENABLE              = 12  ;
static const uint8_t P9A_PERV_PEEK4A4_FSI_A_MST_1_PORT_1_ENABLE              = 16  ;
static const uint8_t P9A_PERV_PEEK4A4_FSI_A_MST_1_PORT_2_ENABLE              = 20  ;
static const uint8_t P9A_PERV_PEEK4A4_FSI_A_MST_1_PORT_3_ENABLE              = 24  ;
static const uint8_t P9A_PERV_PEEK4A4_FSI_A_MST_1_PORT_4_ENABLE              = 28  ;

static const uint8_t P9A_PERV_PEEK4A8_FSI_B_MST_0_ACTUAL_ERROR               = 4   ;
static const uint8_t P9A_PERV_PEEK4A8_FSI_B_MST_0_ACTUAL_ERROR_LEN           = 4   ;
static const uint8_t P9A_PERV_PEEK4A8_FSI_B_MST_0_PORT_0_ENABLE              = 8   ;
static const uint8_t P9A_PERV_PEEK4A8_FSI_B_MST_0_PORT_1_ENABLE              = 12  ;
static const uint8_t P9A_PERV_PEEK4A8_FSI_B_MST_0_PORT_2_ENABLE              = 16  ;
static const uint8_t P9A_PERV_PEEK4A8_FSI_B_MST_0_PORT_3_ENABLE              = 20  ;
static const uint8_t P9A_PERV_PEEK4A8_FSI_B_MST_0_PORT_4_ENABLE              = 24  ;
static const uint8_t P9A_PERV_PEEK4A8_FSI_B_MST_0_PORT_5_ENABLE              = 28  ;

static const uint8_t P9A_PERV_PEEK4AC_FSI_B_MST_0_PORT_6_ENABLE              = 0   ;
static const uint8_t P9A_PERV_PEEK4AC_FSI_B_MST_0_PORT_7_ENABLE              = 4   ;

static const uint8_t P9A_PERV_PERV_CTRL0_TP_CHIPLET_EN_DC                    = 0   ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_PCB_EP_RESET_DC                  = 1   ;
static const uint8_t P9A_PERV_PERV_CTRL0_2_RESERVED                          = 2   ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_PLL_TEST_EN_DC                   = 3   ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_PLLRST_DC                        = 4   ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_PLLBYP_DC                        = 5   ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_VITL_SCAN_CLK_DC                 = 6   ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_VITL_SCIN_DC                     = 7   ;
static const uint8_t P9A_PERV_PERV_CTRL0_8_RESERVED                          = 8   ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_FLUSH_ALIGN_OVERWRITE            = 9   ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_ARRAY_WRITE_ASSIST_EN_DC         = 10  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_VITL_ACT_DIS_DC                  = 11  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_VITL_MPW1_DC_N                   = 12  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_VITL_MPW2_DC_N                   = 13  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_VITL_MPW3_DC_N                   = 14  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_VITL_DELAY_LCLKR_DC              = 15  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_VITL_CLKOFF_DC                   = 16  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_FLUSH_SCAN_DC_N                  = 17  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_FENCE_EN_DC                      = 18  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_RI_DC_N                          = 19  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_DI1_DC_N                         = 20  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_DI2_DC_N                         = 21  ;
static const uint8_t P9A_PERV_PERV_CTRL0_22_RESERVED                         = 22  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE         = 23  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_TCPERV_SRAM_ENABLE_DC            = 24  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_FENCE_PCB_DC                     = 25  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_LVLTRANS_FENCE_DC                = 26  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_EDRAM_ENABLE_DC                  = 27  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_I2CM_MVPD0_PROTECT               = 28  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_I2CM_MVPD1_PROTECT               = 29  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC             = 30  ;
static const uint8_t P9A_PERV_PERV_CTRL0_TP_PLLCHIPLET_FORCE_OUT_EN_DC       = 31  ;

static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_CHIPLET_EN_DC              = 0   ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_PCB_EP_RESET_DC            = 1   ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_2_RESERVED                    = 2   ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_PLL_TEST_EN_DC             = 3   ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_PLLRST_DC                  = 4   ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_PLLBYP_DC                  = 5   ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_VITL_SCAN_CLK_DC           = 6   ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_VITL_SCIN_DC               = 7   ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_8_RESERVED                    = 8   ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_FLUSH_ALIGN_OVERWRITE      = 9   ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_ARRAY_WRITE_ASSIST_EN_DC   = 10  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_VITL_ACT_DIS_DC            = 11  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_VITL_MPW1_DC_N             = 12  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_VITL_MPW2_DC_N             = 13  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_VITL_MPW3_DC_N             = 14  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_VITL_DELAY_LCLKR_DC        = 15  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_VITL_CLKOFF_DC             = 16  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_FLUSH_SCAN_DC_N            = 17  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_FENCE_EN_DC                = 18  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_RI_DC_N                    = 19  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_DI1_DC_N                   = 20  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_DI2_DC_N                   = 21  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_22_RESERVED                   = 22  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_OTP_SCOM_FUSED_CORE_MODE   = 23  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_TCPERV_SRAM_ENABLE_DC      = 24  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_FENCE_PCB_DC               = 25  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_LVLTRANS_FENCE_DC          = 26  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_EDRAM_ENABLE_DC            = 27  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_I2CM_MVPD0_PROTECT         = 28  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_I2CM_MVPD1_PROTECT         = 29  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_EX_SINGLE_LPAR_EN_DC       = 30  ;
static const uint8_t P9A_PERV_PERV_CTRL0_CLEAR_TP_PLLCHIPLET_FORCE_OUT_EN_DC = 31  ;

static const uint8_t P9A_PERV_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG            = 0   ;
static const uint8_t P9A_PERV_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG_LEN        = 32  ;

static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_CHIPLET_EN_DC                = 0   ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_PCB_EP_RESET_DC              = 1   ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_2_RESERVED                      = 2   ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_PLL_TEST_EN_DC               = 3   ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_PLLRST_DC                    = 4   ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_PLLBYP_DC                    = 5   ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_VITL_SCAN_CLK_DC             = 6   ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_VITL_SCIN_DC                 = 7   ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_8_RESERVED                      = 8   ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_FLUSH_ALIGN_OVERWRITE        = 9   ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_ARRAY_WRITE_ASSIST_EN_DC     = 10  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_VITL_ACT_DIS_DC              = 11  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_VITL_MPW1_DC_N               = 12  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_VITL_MPW2_DC_N               = 13  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_VITL_MPW3_DC_N               = 14  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_VITL_DELAY_LCLKR_DC          = 15  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC               = 16  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_FLUSH_SCAN_DC_N              = 17  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_FENCE_EN_DC                  = 18  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_RI_DC_N                      = 19  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_DI1_DC_N                     = 20  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_DI2_DC_N                     = 21  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_22_RESERVED                     = 22  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE     = 23  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_TCPERV_SRAM_ENABLE_DC        = 24  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_FENCE_PCB_DC                 = 25  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_LVLTRANS_FENCE_DC            = 26  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_EDRAM_ENABLE_DC              = 27  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_I2CM_MVPD0_PROTECT           = 28  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_I2CM_MVPD1_PROTECT           = 29  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC         = 30  ;
static const uint8_t P9A_PERV_PERV_CTRL0_SET_TP_PLLCHIPLET_FORCE_OUT_EN_DC   = 31  ;

static const uint8_t P9A_PERV_PERV_CTRL1_TP_CHIPLET_PLL_CLKIN_SEL_DC         = 0   ;
static const uint8_t P9A_PERV_PERV_CTRL1_TP_CHIPLET_CLK_DCCDIV_BYPASS_EN_DC  = 1   ;
static const uint8_t P9A_PERV_PERV_CTRL1_TP_CHIPLET_CLK_PROGDLY_BYPASS_EN_DC = 2   ;
static const uint8_t P9A_PERV_PERV_CTRL1_3_RESERVED                          = 3   ;
static const uint8_t P9A_PERV_PERV_CTRL1_4_RESERVED                          = 4   ;
static const uint8_t P9A_PERV_PERV_CTRL1_5_RESERVED                          = 5   ;
static const uint8_t P9A_PERV_PERV_CTRL1_6_RESERVED                          = 6   ;
static const uint8_t P9A_PERV_PERV_CTRL1_7_RESERVED                          = 7   ;
static const uint8_t P9A_PERV_PERV_CTRL1_8_RESERVED                          = 8   ;
static const uint8_t P9A_PERV_PERV_CTRL1_9_RESERVED                          = 9   ;
static const uint8_t P9A_PERV_PERV_CTRL1_10_RESERVED                         = 10  ;
static const uint8_t P9A_PERV_PERV_CTRL1_11_RESERVED                         = 11  ;
static const uint8_t P9A_PERV_PERV_CTRL1_12_RESERVED                         = 12  ;
static const uint8_t P9A_PERV_PERV_CTRL1_13_RESERVED                         = 13  ;
static const uint8_t P9A_PERV_PERV_CTRL1_14_RESERVED                         = 14  ;
static const uint8_t P9A_PERV_PERV_CTRL1_15_RESERVED                         = 15  ;
static const uint8_t P9A_PERV_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC          = 16  ;
static const uint8_t P9A_PERV_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC_LEN      = 4   ;
static const uint8_t P9A_PERV_PERV_CTRL1_20_RESERVED                         = 20  ;
static const uint8_t P9A_PERV_PERV_CTRL1_21_RESERVED                         = 21  ;
static const uint8_t P9A_PERV_PERV_CTRL1_22_RESERVED                         = 22  ;
static const uint8_t P9A_PERV_PERV_CTRL1_23_RESERVED                         = 23  ;
static const uint8_t P9A_PERV_PERV_CTRL1_24_RESERVED                         = 24  ;
static const uint8_t P9A_PERV_PERV_CTRL1_TP_CLK_PULSE_ENABLE_DC              = 25  ;
static const uint8_t P9A_PERV_PERV_CTRL1_TP_CLK_PULSE_MODE_DC                = 26  ;
static const uint8_t P9A_PERV_PERV_CTRL1_TP_CLK_PULSE_MODE_DC_LEN            = 2   ;
static const uint8_t P9A_PERV_PERV_CTRL1_TP_RESCLK_DIS_DC                    = 28  ;
static const uint8_t P9A_PERV_PERV_CTRL1_TP_CPM_CAL_SET                      = 29  ;
static const uint8_t P9A_PERV_PERV_CTRL1_30_RESERVED                         = 30  ;
static const uint8_t P9A_PERV_PERV_CTRL1_TP_PCB_PM_MUX_SEL_DC                = 31  ;

static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_TP_CHIPLET_PLL_CLKIN_SEL_DC   = 0   ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCCDIV_BYPASS_EN_DC = 1   ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PROGDLY_BYPASS_EN_DC = 2   ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_3_RESERVED                    = 3   ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_4_RESERVED                    = 4   ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_5_RESERVED                    = 5   ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_6_RESERVED                    = 6   ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_7_RESERVED                    = 7   ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_8_RESERVED                    = 8   ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_9_RESERVED                    = 9   ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_10_RESERVED                   = 10  ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_11_RESERVED                   = 11  ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_12_RESERVED                   = 12  ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_13_RESERVED                   = 13  ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_14_RESERVED                   = 14  ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_15_RESERVED                   = 15  ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC    = 16  ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC_LEN = 4   ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_20_RESERVED                   = 20  ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_21_RESERVED                   = 21  ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_22_RESERVED                   = 22  ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_23_RESERVED                   = 23  ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_24_RESERVED                   = 24  ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_TP_CLK_PULSE_ENABLE_DC        = 25  ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_TP_CLK_PULSE_MODE_DC          = 26  ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_TP_CLK_PULSE_MODE_DC_LEN      = 2   ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_TP_RESCLK_DIS_DC              = 28  ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_TP_CPM_CAL_SET                = 29  ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_30_RESERVED                   = 30  ;
static const uint8_t P9A_PERV_PERV_CTRL1_CLEAR_TP_PCB_PM_MUX_SEL_DC          = 31  ;

static const uint8_t P9A_PERV_PERV_CTRL1_COPY_PERV_CTRL1_COPY_REG            = 0   ;
static const uint8_t P9A_PERV_PERV_CTRL1_COPY_PERV_CTRL1_COPY_REG_LEN        = 32  ;

static const uint8_t P9A_PERV_PERV_CTRL1_SET_TP_CHIPLET_PLL_CLKIN_SEL_DC     = 0   ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_TP_CHIPLET_CLK_DCCDIV_BYPASS_EN_DC = 1   ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_TP_CHIPLET_CLK_PROGDLY_BYPASS_EN_DC = 2   ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_3_RESERVED                      = 3   ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_4_RESERVED                      = 4   ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_5_RESERVED                      = 5   ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_6_RESERVED                      = 6   ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_7_RESERVED                      = 7   ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_8_RESERVED                      = 8   ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_9_RESERVED                      = 9   ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_10_RESERVED                     = 10  ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_11_RESERVED                     = 11  ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_12_RESERVED                     = 12  ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_13_RESERVED                     = 13  ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_14_RESERVED                     = 14  ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_15_RESERVED                     = 15  ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_TP_SEC_BUF_DRV_STRENGTH_DC      = 16  ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_TP_SEC_BUF_DRV_STRENGTH_DC_LEN  = 4   ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_20_RESERVED                     = 20  ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_21_RESERVED                     = 21  ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_22_RESERVED                     = 22  ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_23_RESERVED                     = 23  ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_24_RESERVED                     = 24  ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_TP_CLK_PULSE_ENABLE_DC          = 25  ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_TP_CLK_PULSE_MODE_DC            = 26  ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_TP_CLK_PULSE_MODE_DC_LEN        = 2   ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_TP_RESCLK_DIS_DC                = 28  ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_TP_CPM_CAL                      = 29  ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_30_RESERVED                     = 30  ;
static const uint8_t P9A_PERV_PERV_CTRL1_SET_TP_PCB_PM_MUX_SEL_DC            = 31  ;

static const uint8_t P9A_PERV_1_PLL_LOCK_REG_LOCK                            = 0   ;
static const uint8_t P9A_PERV_1_PLL_LOCK_REG_LOCK_LEN                        = 4   ;

static const uint8_t P9A_PERV_PPE_FIR_ACTION0_REG_ACTION0                    = 0   ;
static const uint8_t P9A_PERV_PPE_FIR_ACTION0_REG_ACTION0_LEN                = 13  ;

static const uint8_t P9A_PERV_PPE_FIR_ACTION1_REG_ACTION1                    = 0   ;
static const uint8_t P9A_PERV_PPE_FIR_ACTION1_REG_ACTION1_LEN                = 13  ;

static const uint8_t P9A_PERV_PPE_FIR_MASK_REG_ERROR                         = 0   ;
static const uint8_t P9A_PERV_PPE_FIR_MASK_REG_ERROR_LEN                     = 4   ;
static const uint8_t P9A_PERV_PPE_FIR_MASK_REG_HALTED                        = 4   ;
static const uint8_t P9A_PERV_PPE_FIR_MASK_REG_WATCHDOG_TIMEOUT              = 5   ;
static const uint8_t P9A_PERV_PPE_FIR_MASK_REG_MMIO_DATA_IN                  = 6   ;
static const uint8_t P9A_PERV_PPE_FIR_MASK_REG_ARB_MISSED_SCRUB_TICK         = 7   ;
static const uint8_t P9A_PERV_PPE_FIR_MASK_REG_ARB_ARY_UE                    = 8   ;
static const uint8_t P9A_PERV_PPE_FIR_MASK_REG_ARB_ARY_CE                    = 9   ;
static const uint8_t P9A_PERV_PPE_FIR_MASK_REG_RESERVED                      = 10  ;
static const uint8_t P9A_PERV_PPE_FIR_MASK_REG_INTERNAL_SCOM_ERROR           = 11  ;
static const uint8_t P9A_PERV_PPE_FIR_MASK_REG_INTERNAL_SCOM_ERROR_CLONE     = 12  ;

static const uint8_t P9A_PERV_PPE_FIR_REG_ERROR                              = 0   ;
static const uint8_t P9A_PERV_PPE_FIR_REG_ERROR_LEN                          = 4   ;
static const uint8_t P9A_PERV_PPE_FIR_REG_HALTED                             = 4   ;
static const uint8_t P9A_PERV_PPE_FIR_REG_WATCHDOG_TIMEOUT                   = 5   ;
static const uint8_t P9A_PERV_PPE_FIR_REG_MMIO_DATA_IN                       = 6   ;
static const uint8_t P9A_PERV_PPE_FIR_REG_ARB_MISSED_SCRUB_TICK              = 7   ;
static const uint8_t P9A_PERV_PPE_FIR_REG_ARB_ARY_UE                         = 8   ;
static const uint8_t P9A_PERV_PPE_FIR_REG_ARB_ARY_CE                         = 9   ;
static const uint8_t P9A_PERV_PPE_FIR_REG_RESERVED                           = 10  ;
static const uint8_t P9A_PERV_PPE_FIR_REG_SCOMFIR_ERROR                      = 11  ;
static const uint8_t P9A_PERV_PPE_FIR_REG_SCOMFIR_ERROR_CLONE                = 12  ;

static const uint8_t P9A_PERV_PPE_FIR_WOF_REG_WOF                            = 0   ;
static const uint8_t P9A_PERV_PPE_FIR_WOF_REG_WOF_LEN                        = 13  ;

static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_HS                            = 0   ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_HC                            = 1   ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_HC_LEN                        = 3   ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_HCP                           = 4   ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_RIP                           = 5   ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_SIP                           = 6   ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_TRAP                          = 7   ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_IAC                           = 8   ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_NULL_MSR_SIBRC                    = 9   ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_NULL_MSR_SIBRC_LEN                = 3   ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_DACR                          = 12  ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_DACW                          = 13  ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_NULL_MSR_WE                       = 14  ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_TRH                           = 15  ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_SMS                           = 16  ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_SMS_LEN                       = 4   ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_NULL_MSR_LP                       = 20  ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_EP                            = 21  ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_PTR                           = 24  ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_ST                            = 25  ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_MFE                           = 28  ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_MCS                           = 29  ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_XSR_MCS_LEN                       = 3   ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_IAR                               = 32  ;
static const uint8_t P9A_PERV_PPE_XIDBGPRO_IAR_LEN                           = 30  ;

static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_HS                            = 0   ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_HC                            = 1   ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_HC_LEN                        = 3   ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_HCP                           = 4   ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_RIP                           = 5   ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_SIP                           = 6   ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_TRAP                          = 7   ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_IAC                           = 8   ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_NULL_MSR_SIBRC                    = 9   ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_NULL_MSR_SIBRC_LEN                = 3   ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_DACR                          = 12  ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_DACW                          = 13  ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_NULL_MSR_WE                       = 14  ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_TRH                           = 15  ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_SMS                           = 16  ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_SMS_LEN                       = 4   ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_NULL_MSR_LP                       = 20  ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_EP                            = 21  ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_PTR                           = 24  ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_ST                            = 25  ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_MFE                           = 28  ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_MCS                           = 29  ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XSR_MCS_LEN                       = 3   ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XIRAMRA_SPRG0                     = 32  ;
static const uint8_t P9A_PERV_PPE_XIRAMDBG_XIRAMRA_SPRG0_LEN                 = 32  ;

static const uint8_t P9A_PERV_PPE_XIRAMEDR_XIRAMGA_IR                        = 0   ;
static const uint8_t P9A_PERV_PPE_XIRAMEDR_XIRAMGA_IR_LEN                    = 32  ;
static const uint8_t P9A_PERV_PPE_XIRAMEDR_EDR                               = 32  ;
static const uint8_t P9A_PERV_PPE_XIRAMEDR_EDR_LEN                           = 32  ;

static const uint8_t P9A_PERV_PPE_XIRAMGA_IR                                 = 0   ;
static const uint8_t P9A_PERV_PPE_XIRAMGA_IR_LEN                             = 32  ;
static const uint8_t P9A_PERV_PPE_XIRAMGA_XIRAMRA_SPRG0                      = 32  ;
static const uint8_t P9A_PERV_PPE_XIRAMGA_XIRAMRA_SPRG0_LEN                  = 32  ;

static const uint8_t P9A_PERV_PPE_XIRAMRA_XIXCR_XCR                          = 1   ;
static const uint8_t P9A_PERV_PPE_XIRAMRA_XIXCR_XCR_LEN                      = 3   ;
static const uint8_t P9A_PERV_PPE_XIRAMRA_SPRG0                              = 32  ;
static const uint8_t P9A_PERV_PPE_XIRAMRA_SPRG0_LEN                          = 32  ;

static const uint8_t P9A_PERV_PPE_XIXCR_XCR                                  = 1   ;
static const uint8_t P9A_PERV_PPE_XIXCR_XCR_LEN                              = 3   ;

static const uint8_t P9A_PERV_1_PRE_COUNTER_REG_COUNTER                      = 0   ;
static const uint8_t P9A_PERV_1_PRE_COUNTER_REG_COUNTER_LEN                  = 8   ;

static const uint8_t P9A_PERV_PRGM_REGISTER_PRGM_ADDR                        = 0   ;
static const uint8_t P9A_PERV_PRGM_REGISTER_PRGM_ADDR_LEN                    = 32  ;
static const uint8_t P9A_PERV_PRGM_REGISTER_PRG_BIT_LOCATION                 = 32  ;
static const uint8_t P9A_PERV_PRGM_REGISTER_PRG_BIT_LOCATION_LEN             = 6   ;

static const uint8_t P9A_PERV_1_PRIMARY_ADDRESS_REG_PRIMARY_ADDRESS          = 0   ;
static const uint8_t P9A_PERV_1_PRIMARY_ADDRESS_REG_PRIMARY_ADDRESS_LEN      = 6   ;

static const uint8_t P9A_PERV_PROBE_PROTECT_STATUS_BITS                      = 0   ;
static const uint8_t P9A_PERV_PROBE_PROTECT_STATUS_BITS_LEN                  = 42  ;

static const uint8_t P9A_PERV_1_PROTECT_MODE_REG_READ_ENABLE                 = 0   ;
static const uint8_t P9A_PERV_1_PROTECT_MODE_REG_WRITE_ENABLE                = 1   ;

static const uint8_t P9A_PERV_1_PSCOM_ERROR_MASK_PCB_WDATA_PARITY            = 0   ;
static const uint8_t P9A_PERV_1_PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY          = 1   ;
static const uint8_t P9A_PERV_1_PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY      = 2   ;
static const uint8_t P9A_PERV_1_PSCOM_ERROR_MASK_DL_RETURN_P0                = 3   ;
static const uint8_t P9A_PERV_1_PSCOM_ERROR_MASK_UL_RDATA_PARITY             = 4   ;
static const uint8_t P9A_PERV_1_PSCOM_ERROR_MASK_UL_P0                       = 5   ;
static const uint8_t P9A_PERV_1_PSCOM_ERROR_MASK_PARITY_ON_INTERFACE_MACHINE = 6   ;
static const uint8_t P9A_PERV_1_PSCOM_ERROR_MASK_PARITY_ON_P2S_MACHINE       = 7   ;
static const uint8_t P9A_PERV_1_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8   ;
static const uint8_t P9A_PERV_1_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9   ;
static const uint8_t P9A_PERV_1_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10  ;
static const uint8_t P9A_PERV_1_PSCOM_ERROR_MASK_PARALLEL_WRITE_NVLD         = 11  ;
static const uint8_t P9A_PERV_1_PSCOM_ERROR_MASK_PARALLEL_READ_NVLD          = 12  ;
static const uint8_t P9A_PERV_1_PSCOM_ERROR_MASK_PARALLEL_ADDR_INVALID       = 13  ;
static const uint8_t P9A_PERV_1_PSCOM_ERROR_MASK_PCB_COMMAND_PARITY          = 14  ;
static const uint8_t P9A_PERV_1_PSCOM_ERROR_MASK_GENERAL_TIMEOUT             = 15  ;
static const uint8_t P9A_PERV_1_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16  ;
static const uint8_t P9A_PERV_1_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17  ;

static const uint8_t P9A_PERV_1_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR = 0   ;
static const uint8_t P9A_PERV_1_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR = 1   ;
static const uint8_t P9A_PERV_1_PSCOM_MODE_REG_UNUSED_BIT_2                  = 2   ;
static const uint8_t P9A_PERV_1_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR = 3   ;
static const uint8_t P9A_PERV_1_PSCOM_MODE_REG_WATCHDOG_ENABLE               = 4   ;
static const uint8_t P9A_PERV_1_PSCOM_MODE_REG_SCOM_HANG_LIMIT               = 5   ;
static const uint8_t P9A_PERV_1_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN           = 2   ;
static const uint8_t P9A_PERV_1_PSCOM_MODE_REG_FORCE_ALL_RINGS               = 7   ;
static const uint8_t P9A_PERV_1_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE = 8   ;
static const uint8_t P9A_PERV_1_PSCOM_MODE_REG_RESERVED_LT                   = 9   ;
static const uint8_t P9A_PERV_1_PSCOM_MODE_REG_RESERVED_LT_LEN               = 3   ;

static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_WDATA_PARITY = 0   ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_ADDRESS_PARITY = 1   ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_WDATA_PARITY = 2   ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_P0 = 3   ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_RDATA_PARITY = 4   ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_P0     = 5   ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ON_INTERFACE_MACHINE = 6   ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ON_P2S_MACHINE = 7   ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8   ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9   ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARALLEL_WRITE_NVLD = 11  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARALLEL_READ_NVLD = 12  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARALLEL_ADDR_INVALID = 13  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_COMMAND_PARITY = 14  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_ACCUMULATED_GENERAL_TIMEOUT = 15  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_WDATA_PARITY = 18  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_ADDRESS_PARITY = 19  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_WDATA_PARITY = 20  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_P0  = 21  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_TRAPPED_UL_RDATA_PARITY = 22  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_TRAPPED_UL_P0         = 23  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ON_INTERFACE_MACHINE = 24  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ON_P2S_MACHINE = 25  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 26  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 27  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 28  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_TRAPPED_PARALLEL_WRITE_NVLD = 29  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_TRAPPED_PARALLEL_READ_NVLD = 30  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_TRAPPED_PARALLEL_ADDR_INVALID = 31  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_COMMAND_PARITY = 32  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_TRAPPED_GENERAL_TIMEOUT = 33  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 34  ;
static const uint8_t P9A_PERV_1_PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 35  ;

static const uint8_t P9A_PERV_FSISHIFT_READ_BUFFER_REG                       = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_READ_BUFFER_REG_LEN                   = 32  ;

static const uint8_t P9A_PERV_1_RECOV_INTERRUPT_REG_RECOV                    = 0   ;

static const uint8_t P9A_PERV_REC_ACK_REG_RECEIVE_ACKNOWLEDGE_REGISTER       = 0   ;
static const uint8_t P9A_PERV_REC_ACK_REG_RECEIVE_ACKNOWLEDGE_REGISTER_LEN   = 64  ;

static const uint8_t P9A_PERV_REC_ERR_REG0_MASTER_RESPONSE_BIT               = 0   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_MASTER_ERROR_CODE                 = 1   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_MASTER_ERROR_CODE_LEN             = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE1_RESPONSE_BIT               = 4   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE1_ERROR_CODE                 = 5   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE1_ERROR_CODE_LEN             = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE2_RESPONSE_BIT               = 8   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE2_ERROR_CODE                 = 9   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE2_ERROR_CODE_LEN             = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE3_RESPONSE_BIT               = 12  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE3_ERROR_CODE                 = 13  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE3_ERROR_CODE_LEN             = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE4_RESPONSE_BIT               = 16  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE4_ERROR_CODE                 = 17  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE4_ERROR_CODE_LEN             = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE5_RESPONSE_BIT               = 20  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE5_ERROR_CODE                 = 21  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE5_ERROR_CODE_LEN             = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE6_RESPONSE_BIT               = 24  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE6_ERROR_CODE                 = 25  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE6_ERROR_CODE_LEN             = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE7_RESPONSE_BIT               = 28  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE7_ERROR_CODE                 = 29  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE7_ERROR_CODE_LEN             = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE8_RESPONSE_BIT               = 32  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE8_ERROR_CODE                 = 33  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE8_ERROR_CODE_LEN             = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE9_RESPONSE_BIT               = 36  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE9_ERROR_CODE                 = 37  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE9_ERROR_CODE_LEN             = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE10_RESPONSE_BIT              = 40  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE10_ERROR_CODE                = 41  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE10_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE11_RESPONSE_BIT              = 44  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE11_ERROR_CODE                = 45  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE11_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE12_RESPONSE_BIT              = 48  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE12_ERROR_CODE                = 49  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE12_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE13_RESPONSE_BIT              = 52  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE13_ERROR_CODE                = 53  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE13_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE14_RESPONSE_BIT              = 56  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE14_ERROR_CODE                = 57  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE14_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE15_RESPONSE_BIT              = 60  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE15_ERROR_CODE                = 61  ;
static const uint8_t P9A_PERV_REC_ERR_REG0_SLAVE15_ERROR_CODE_LEN            = 3   ;

static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE16_RESPONSE_BIT              = 0   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE16_ERROR_CODE                = 1   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE16_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE17_RESPONSE_BIT              = 4   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE17_ERROR_CODE                = 5   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE17_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE18_RESPONSE_BIT              = 8   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE18_ERROR_CODE                = 9   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE18_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE19_RESPONSE_BIT              = 12  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE19_ERROR_CODE                = 13  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE19_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE20_RESPONSE_BIT              = 16  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE20_ERROR_CODE                = 17  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE20_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE21_RESPONSE_BIT              = 20  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE21_ERROR_CODE                = 21  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE21_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE22_RESPONSE_BIT              = 24  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE22_ERROR_CODE                = 25  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE22_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE23_RESPONSE_BIT              = 28  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE23_ERROR_CODE                = 29  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE23_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE24_RESPONSE_BIT              = 32  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE24_ERROR_CODE                = 33  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE24_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE25_RESPONSE_BIT              = 36  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE25_ERROR_CODE                = 37  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE25_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE26_RESPONSE_BIT              = 40  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE26_ERROR_CODE                = 41  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE26_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE27_RESPONSE_BIT              = 44  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE27_ERROR_CODE                = 45  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE27_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE28_RESPONSE_BIT              = 48  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE28_ERROR_CODE                = 49  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE28_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE29_RESPONSE_BIT              = 52  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE29_ERROR_CODE                = 53  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE29_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE30_RESPONSE_BIT              = 56  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE30_ERROR_CODE                = 57  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE30_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE31_RESPONSE_BIT              = 60  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE31_ERROR_CODE                = 61  ;
static const uint8_t P9A_PERV_REC_ERR_REG1_SLAVE31_ERROR_CODE_LEN            = 3   ;

static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE32_RESPONSE_BIT              = 0   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE32_ERROR_CODE                = 1   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE32_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE33_RESPONSE_BIT              = 4   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE33_ERROR_CODE                = 5   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE33_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE34_RESPONSE_BIT              = 8   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE34_ERROR_CODE                = 9   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE34_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE35_RESPONSE_BIT              = 12  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE35_ERROR_CODE                = 13  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE35_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE36_RESPONSE_BIT              = 16  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE36_ERROR_CODE                = 17  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE36_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE37_RESPONSE_BIT              = 20  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE37_ERROR_CODE                = 21  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE37_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE38_RESPONSE_BIT              = 24  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE38_ERROR_CODE                = 25  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE38_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE39_RESPONSE_BIT              = 28  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE39_ERROR_CODE                = 29  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE39_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE40_RESPONSE_BIT              = 32  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE40_ERROR_CODE                = 33  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE40_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE41_RESPONSE_BIT              = 36  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE41_ERROR_CODE                = 37  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE41_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE42_RESPONSE_BIT              = 40  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE42_ERROR_CODE                = 41  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE42_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE43_RESPONSE_BIT              = 44  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE43_ERROR_CODE                = 45  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE43_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE44_RESPONSE_BIT              = 48  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE44_ERROR_CODE                = 49  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE44_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE45_RESPONSE_BIT              = 52  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE45_ERROR_CODE                = 53  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE45_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE46_RESPONSE_BIT              = 56  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE46_ERROR_CODE                = 57  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE46_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE47_RESPONSE_BIT              = 60  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE47_ERROR_CODE                = 61  ;
static const uint8_t P9A_PERV_REC_ERR_REG2_SLAVE47_ERROR_CODE_LEN            = 3   ;

static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE48_RESPONSE_BIT              = 0   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE48_ERROR_CODE                = 1   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE48_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE49_RESPONSE_BIT              = 4   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE49_ERROR_CODE                = 5   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE49_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE50_RESPONSE_BIT              = 8   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE50_ERROR_CODE                = 9   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE50_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE51_RESPONSE_BIT              = 12  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE51_ERROR_CODE                = 13  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE51_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE52_RESPONSE_BIT              = 16  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE52_ERROR_CODE                = 17  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE52_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE53_RESPONSE_BIT              = 20  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE53_ERROR_CODE                = 21  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE53_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE54_RESPONSE_BIT              = 24  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE54_ERROR_CODE                = 25  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE54_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE55_RESPONSE_BIT              = 28  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE55_ERROR_CODE                = 29  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE55_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE56_RESPONSE_BIT              = 32  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE56_ERROR_CODE                = 33  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE56_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE57_RESPONSE_BIT              = 36  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE57_ERROR_CODE                = 37  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE57_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE58_RESPONSE_BIT              = 40  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE58_ERROR_CODE                = 41  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE58_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE59_RESPONSE_BIT              = 44  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE59_ERROR_CODE                = 45  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE59_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE60_RESPONSE_BIT              = 48  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE60_ERROR_CODE                = 49  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE60_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE61_RESPONSE_BIT              = 52  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE61_ERROR_CODE                = 53  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE61_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE62_RESPONSE_BIT              = 56  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE62_ERROR_CODE                = 57  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE62_ERROR_CODE_LEN            = 3   ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE63_RESPONSE_BIT              = 60  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE63_ERROR_CODE                = 61  ;
static const uint8_t P9A_PERV_REC_ERR_REG3_SLAVE63_ERROR_CODE_LEN            = 3   ;

static const uint8_t P9A_PERV_RESET_REG_PCB                                  = 0   ;
static const uint8_t P9A_PERV_RESET_REG_ENDPOINTS                            = 1   ;
static const uint8_t P9A_PERV_RESET_REG_TIMEOUT_EN                           = 2   ;

static const uint8_t P9A_PERV_RESET_REGISTER_CHICKEN_SWITCH                  = 0   ;

static const uint8_t P9A_PERV_FSII2C_RESIDUAL_FRONT_END_BACK_END_LENGTH_A_RESID_FE_LEN_0 = 0   ;
static const uint8_t P9A_PERV_FSII2C_RESIDUAL_FRONT_END_BACK_END_LENGTH_A_RESID_FE_LEN_0_LEN = 16  ;

static const uint8_t P9A_PERV_1_RFIR_IN0                                     = 0   ;
static const uint8_t P9A_PERV_1_RFIR_LFIR_RECOV_ERR                          = 1   ;
static const uint8_t P9A_PERV_1_RFIR_IN4                                     = 2   ;
static const uint8_t P9A_PERV_1_RFIR_IN5                                     = 3   ;
static const uint8_t P9A_PERV_1_RFIR_IN6                                     = 4   ;
static const uint8_t P9A_PERV_1_RFIR_IN7                                     = 5   ;
static const uint8_t P9A_PERV_1_RFIR_IN8                                     = 6   ;
static const uint8_t P9A_PERV_1_RFIR_IN9                                     = 7   ;
static const uint8_t P9A_PERV_1_RFIR_IN10                                    = 8   ;
static const uint8_t P9A_PERV_1_RFIR_IN11                                    = 9   ;
static const uint8_t P9A_PERV_1_RFIR_IN12                                    = 10  ;
static const uint8_t P9A_PERV_1_RFIR_IN13                                    = 11  ;
static const uint8_t P9A_PERV_1_RFIR_IN14                                    = 12  ;
static const uint8_t P9A_PERV_1_RFIR_IN15                                    = 13  ;
static const uint8_t P9A_PERV_1_RFIR_IN16                                    = 14  ;
static const uint8_t P9A_PERV_1_RFIR_IN17                                    = 15  ;
static const uint8_t P9A_PERV_1_RFIR_IN18                                    = 16  ;
static const uint8_t P9A_PERV_1_RFIR_IN19                                    = 17  ;
static const uint8_t P9A_PERV_1_RFIR_IN20                                    = 18  ;
static const uint8_t P9A_PERV_1_RFIR_IN21                                    = 19  ;
static const uint8_t P9A_PERV_1_RFIR_IN21_LEN                                = 5   ;

static const uint8_t P9A_PERV_1_RING_FENCE_MASK_LATCH_REG_ENABLE             = 1   ;
static const uint8_t P9A_PERV_1_RING_FENCE_MASK_LATCH_REG_ENABLE_LEN         = 15  ;

static const uint8_t P9A_PERV_ROOT_CTRL0_FENCE0_DC                           = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_TPFSI_TP_FENCE_VTLIO_DC             = 1   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC            = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC             = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC_LEN         = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_TPCFSI_OPB_SW1_FENCE_DC             = 6   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_TPCFSI_OPB_SW1_FENCE_DC_LEN         = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_FENCE1_DC                           = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_FENCE2_DC                           = 9   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_FENCE3_DC                           = 10  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_FENCE4_DC                           = 11  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_FENCE5_DC                           = 12  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_FENCE6_DC                           = 13  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SPARE_FENCE_CONTROL                 = 14  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC                = 15  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_FSI2PCB_DC                          = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_OOB_MUX                             = 17  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_PIB2PCB_DC                          = 18  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_PCB2PCB_DC                          = 19  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ                  = 20  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD                  = 21  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD_LEN              = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_24_SPARE_CBS_CONTROL                = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_25_SPARE_CBS_CONTROL                = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_26_SPARE_CBS_CONTROL                = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_27_SPARE_CBS_CONTROL                = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_28_SPARE_RESET                      = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_OCMB_RESET_EN_DC                    = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_PCB_RESET_DC                        = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_GLOBAL_EP_RESET_DC                  = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_FENCE0_DC                     = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_TPFSI_TP_FENCE_VTLIO_DC       = 1   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC      = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC       = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC_LEN   = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW1_FENCE_DC       = 6   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW1_FENCE_DC_LEN   = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_FENCE1_DC                     = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_FENCE2_DC                     = 9   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_FENCE3_DC                     = 10  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_FENCE4_DC                     = 11  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_FENCE5_DC                     = 12  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_FENCE6_DC                     = 13  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL           = 14  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC          = 15  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_FSI2PCB_DC                    = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_OOB_MUX                       = 17  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_PIB2PCB_DC                    = 18  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_PCB2PCB_DC                    = 19  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ            = 20  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD            = 21  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD_LEN        = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_24_SPARE_CBS_CONTROL          = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_25_SPARE_CBS_CONTROL          = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_26_SPARE_CBS_CONTROL          = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_27_SPARE_CBS_CONTROL          = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_28_SPARE_RESET                = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_OCMB_RESET_EN_DC              = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_PCB_RESET_DC                  = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC            = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG            = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG_LEN        = 32  ;

static const uint8_t P9A_PERV_ROOT_CTRL0_SET_FENCE0_DC                       = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_TPFSI_TP_FENCE_VTLIO_DC         = 1   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_TPFSI_TPI2C_BUS_FENCE_DC        = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_TPCFSI_OPB_SW0_FENCE_DC         = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_TPCFSI_OPB_SW0_FENCE_DC_LEN     = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_TPCFSI_OPB_SW1_FENCE_DC         = 6   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_TPCFSI_OPB_SW1_FENCE_DC_LEN     = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_FENCE1_DC                       = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_FENCE2_DC                       = 9   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_FENCE3_DC                       = 10  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_FENCE4_DC                       = 11  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_FENCE5_DC                       = 12  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_FENCE6_DC                       = 13  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_SPARE_FENCE_CONTROL             = 14  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_VDD2VIO_LVL_FENCE_DC            = 15  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_FSI2PCB_DC                      = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_OOB_MUX                         = 17  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_PIB2PCB_DC                      = 18  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_PCB2PCB_DC                      = 19  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_FSI_CC_VSB_CBS_REQ              = 20  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_FSI_CC_VSB_CBS_CMD              = 21  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_FSI_CC_VSB_CBS_CMD_LEN          = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_24_SPARE_CBS_CONTROL            = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_25_SPARE_CBS_CONTROL            = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_26_SPARE_CBS_CONTROL            = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_27_SPARE_CBS_CONTROL            = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_28_SPARE_RESET                  = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_OCMB_RESET_EN_DC                = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_PCB_RESET_DC                    = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL0_SET_GLOBAL_EP_RESET_DC              = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL1_TP_PROBE0_SEL_DC                    = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_TP_PROBE0_SEL_DC_LEN                = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_TP_PROBE1_SEL_DC                    = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_TP_PROBE1_SEL_DC_LEN                = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC                = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_TP_PROBE_DRV_EN_DC                  = 9   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_TP_PROBE_HIGHDRIVE_DC               = 10  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC                 = 11  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC_LEN             = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_13_SPARE_PROBE                      = 13  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_14_SPARE_PROBE                      = 14  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_15_SPARE_PROBE                      = 15  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_TP_IDDQ_DC                          = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SPARE_RI_CONTROL                    = 17  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SPARE_DI_CONTROL                    = 18  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_TP_RI_DC_B                          = 19  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_TP_DI1_DC_B                         = 20  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_TP_DI2_DC_B                         = 21  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_22_SPARE_TEST                       = 22  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_23_SPARE_TEST                       = 23  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC              = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC       = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_TPFSI_TP_LOWFREQTEST_REFCLK_DC_UNUSED = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_TP_GLBCK_MEM_TESTCLK_SEL_DC         = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_28_SPARE_TEST_CONTROL               = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_29_SPARE_TEST_CONTROL               = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_30_SPARE_TEST_CONTROL               = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_31_SPARE_TEST_CONTROL               = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_TP_PROBE0_SEL_DC              = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_TP_PROBE0_SEL_DC_LEN          = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_TP_PROBE1_SEL_DC              = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_TP_PROBE1_SEL_DC_LEN          = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_TP_PROBE_MESH_SEL_DC          = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_TP_PROBE_DRV_EN_DC            = 9   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_TP_PROBE_HIGHDRIVE_DC         = 10  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_TP_FSI_PROBE_SEL_DC           = 11  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_TP_FSI_PROBE_SEL_DC_LEN       = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_13_SPARE_PROBE                = 13  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_14_SPARE_PROBE                = 14  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_15_SPARE_PROBE                = 15  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_TP_IDDQ_DC                    = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_SPARE_RI_CONTROL              = 17  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_SPARE_DI_CONTROL              = 18  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_TP_RI_DC_B                    = 19  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_TP_DI1_DC_B                   = 20  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_TP_DI2_DC_B                   = 21  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_22_SPARE_TEST                 = 22  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_23_SPARE_TEST                 = 23  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_TP_TEST_BURNIN_MODE_DC        = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_TPFSI_ARRAY_SET_VBL_TO_VDD_DC = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_TPFSI_TP_LOWFREQTEST_REFCLK_DC_UNUSED = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_TP_GLBCK_MEM_TESTCLK_SEL_DC   = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_28_SPARE_TEST_CONTROL         = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_29_SPARE_TEST_CONTROL         = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_30_SPARE_TEST_CONTROL         = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_CLEAR_31_SPARE_TEST_CONTROL         = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG            = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG_LEN        = 32  ;

static const uint8_t P9A_PERV_ROOT_CTRL1_SET_TP_PROBE0_SEL_DC                = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_TP_PROBE0_SEL_DC_LEN            = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_TP_PROBE1_SEL_DC                = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_TP_PROBE1_SEL_DC_LEN            = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_TP_PROBE_MESH_SEL_DC            = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_TP_PROBE_DRV_EN_DC              = 9   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_TP_PROBE_HIGHDRIVE_DC           = 10  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_TP_FSI_PROBE_SEL_DC             = 11  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_TP_FSI_PROBE_SEL_DC_LEN         = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_13_SPARE_PROBE                  = 13  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_14_SPARE_PROBE                  = 14  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_15_SPARE_PROBE                  = 15  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_TP_IDDQ_DC                      = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_SPARE_RI_CONTROL                = 17  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_SPARE_DI_CONTROL                = 18  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_TP_RI_DC_B                      = 19  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_TP_DI1_DC_B                     = 20  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_TP_DI2_DC_B                     = 21  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_22_SPARE_TEST                   = 22  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_23_SPARE_TEST                   = 23  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_TP_TEST_BURNIN_MODE_DC          = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_TPFSI_ARRAY_VBL_TO_VDD_DC       = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_TPFSI_TP_LOWFREQTEST_REFCLK_DC_UNUSED = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_TP_GLBCK_MEM_TESTCLK_SEL_DC     = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_28_SPARE_TEST_CONTROL           = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_29_SPARE_TEST_CONTROL           = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_30_SPARE_TEST_CONTROL           = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL1_SET_31_SPARE_TEST_CONTROL           = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL2_TPFSI_TP_VSB_DBG_PCB_ASYNC_EN_DC    = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TPFSI_TP_VSB_DBG_PCB_DATA_PAR_DIS_DC = 1   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TPFSI_TP_VSB_DBG_PCB_TYPE_PAR_DIS_DC = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TPFSI_TP_VSB_PCB_GSD_LATCHED_MODE_DC = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TP_PIB_VSB_DISABLE_PARITY_DC        = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC           = 5   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE           = 6   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP           = 7   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT                 = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT_LEN             = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SPARE_PIB_CONTROL                   = 11  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC              = 12  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_13_SPARE_OPB_CONTROL                = 13  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_14_SPARE_OPB_CONTROL                = 14  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_15_SPARE_OPB_CONTROL                = 15  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TPFSI_TP_EDRAM_CTRL_GATE            = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TP_GLBCK_VSB_NEST_VREGDLY_SHUTOFF_DC = 17  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TPFSI_TP_PFET_FORCE_OFF_DC          = 18  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TPFSI_TP_PFET_OVERRIDE_ON_DC_N      = 19  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TPFSI_TC_HSSPORWREN_ALLOW           = 20  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_21_FREE_USAGE                       = 21  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_22_FREE_USAGE                       = 22  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_23_FREE_USAGE                       = 23  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TP_IO_VSB_OP0A_V1P8_EN              = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TP_IO_VSB_OP0B_V1P8_EN              = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_26_FREE_USAGE                       = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_27_FREE_USAGE                       = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_28_FREE_USAGE                       = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_29_FREE_USAGE                       = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TP_IO_VSB_OP3A_V1P8_EN              = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_TP_IO_VSB_OP3B_V1P8_EN              = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TPFSI_TP_VSB_DBG_PCB_ASYNC_EN_DC = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TPFSI_TP_VSB_DBG_PCB_DATA_PAR_DIS_DC = 1   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TPFSI_TP_VSB_DBG_PCB_TYPE_PAR_DIS_DC = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TPFSI_TP_VSB_PCB_GSD_LATCHED_MODE_DC = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TP_PIB_VSB_DISABLE_PARITY_DC  = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TP_PIB_TRACE_MODE_DATA_DC     = 5   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TP_PIB_VSB_SBE_TRACE_MODE     = 6   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TP_TPCPERV_VSB_TRACE_STOP     = 7   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TP_GPIO_PIB_TIMEOUT           = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TP_GPIO_PIB_TIMEOUT_LEN       = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_SPARE_PIB_CONTROL             = 11  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TPCFSI_OPB_SW_RESET_DC        = 12  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_13_SPARE_OPB_CONTROL          = 13  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_14_SPARE_OPB_CONTROL          = 14  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_15_SPARE_OPB_CONTROL          = 15  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TPFSI_TP_EDRAM_CTRL_GATE      = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TP_GLBCK_VSB_NEST_VREGDLY_SHUTOFF_DC = 17  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TPFSI_TP_PFET_FORCE_OFF_DC    = 18  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TPFSI_TP_PFET_OVERRIDE_ON_DC_N = 19  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TPFSI_TC_HSSPORWREN_ALLOW     = 20  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_21_FREE_USAGE                 = 21  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_22_FREE_USAGE                 = 22  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_23_FREE_USAGE                 = 23  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TP_IO_VSB_OP0A_V1P8_EN        = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TP_IO_VSB_OP0B_V1P8_EN        = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_26_FREE_USAGE                 = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_27_FREE_USAGE                 = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_28_FREE_USAGE                 = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_29_FREE_USAGE                 = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TP_IO_VSB_OP3A_V1P8_EN        = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_CLEAR_TP_IO_VSB_OP3B_V1P8_EN        = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG            = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG_LEN        = 32  ;

static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TPFSI_TP_VSB_DBG_PCB_ASYNC_EN_DC = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TPFSI_TP_VSB_DBG_PCB_DATA_PAR_DIS_DC = 1   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TPFSI_TP_VSB_DBG_PCB_TYPE_PAR_DIS_DC = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TPFSI_TP_VSB_PCB_GSD_LATCHED_MODE_DC = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TP_PIB_VSB_DISABLE_PARITY_DC    = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TP_PIB_TRACE_MODE_DATA_DC       = 5   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TP_PIB_VSB_SBE_TRACE_MODE       = 6   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TP_TPCPERV_VSB_TRACE_STOP       = 7   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TP_GPIO_PIB_TIMEOUT             = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TP_GPIO_PIB_TIMEOUT_LEN         = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_SPARE_PIB_CONTROL               = 11  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TPCFSI_OPB_SW_RESET_DC          = 12  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_13_SPARE_OPB_CONTROL            = 13  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_14_SPARE_OPB_CONTROL            = 14  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_15_SPARE_OPB_CONTROL            = 15  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TPFSI_TP_EDRAM_CTRL_GATE        = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TP_GLBCK_VSB_NEST_VREGDLY_SHUTOFF_DC = 17  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TPFSI_TP_PFET_FORCE_OFF_DC      = 18  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TPFSI_TP_PFET_OVERRIDE_ON_DC_N  = 19  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TPFSI_TC_HSSPORWREN_ALLOW       = 20  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_21_FREE_USAGE                   = 21  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_22_FREE_USAGE                   = 22  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_23_FREE_USAGE                   = 23  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TP_IO_VSB_OP0A_V1P8_EN          = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TP_IO_VSB_OP0B_V1P8_EN          = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_26_FREE_USAGE                   = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_27_FREE_USAGE                   = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_28_FREE_USAGE                   = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_29_FREE_USAGE                   = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TP_IO_VSB_OP3A_V1P8_EN          = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL2_SET_TP_IO_VSB_OP3B_V1P8_EN          = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL3_OSCSWITCH_CNTL0_DC                  = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL3_OSCSWITCH_CNTL0_DC_LEN              = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL3_TP_GLBCK_VSB_PCIESW_USEOSC_DC       = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL3_TP_GLBCK_VSB_PCIESW_USEOSC_DC_LEN   = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL3_TP_GLBCK_VSB_PCIESW_TWEAK_DC        = 20  ;
static const uint8_t P9A_PERV_ROOT_CTRL3_TP_GLBCK_VSB_PCIESW_TWEAK_DC_LEN    = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL3_OSCSWITCH_CNTL1_DC                  = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL3_OSCSWITCH_CNTL1_DC_LEN              = 8   ;

static const uint8_t P9A_PERV_ROOT_CTRL3_CLEAR_OSCSWITCH_CNTL0_DC            = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL3_CLEAR_OSCSWITCH_CNTL0_DC_LEN        = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL3_CLEAR_TP_GLBCK_VSB_PCIESW_USEOSC_DC = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL3_CLEAR_TP_GLBCK_VSB_PCIESW_USEOSC_DC_LEN = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL3_CLEAR_TP_GLBCK_VSB_PCIESW_TWEAK_DC  = 20  ;
static const uint8_t P9A_PERV_ROOT_CTRL3_CLEAR_TP_GLBCK_VSB_PCIESW_TWEAK_DC_LEN = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL3_CLEAR_OSCSWITCH_CNTL1_DC            = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL3_CLEAR_OSCSWITCH_CNTL1_DC_LEN        = 8   ;

static const uint8_t P9A_PERV_ROOT_CTRL3_COPY_ROOT_CTRL3_COPY_REG            = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL3_COPY_ROOT_CTRL3_COPY_REG_LEN        = 32  ;

static const uint8_t P9A_PERV_ROOT_CTRL3_SET_OSCSWITCH_CNTL0_DC              = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL3_SET_OSCSWITCH_CNTL0_DC_LEN          = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL3_SET_TP_GLBCK_VSB_PCIESW_USEOSC_DC   = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL3_SET_TP_GLBCK_VSB_PCIESW_USEOSC_DC_LEN = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL3_SET_TP_GLBCK_VSB_PCIESW_TWEAK_DC    = 20  ;
static const uint8_t P9A_PERV_ROOT_CTRL3_SET_TP_GLBCK_VSB_PCIESW_TWEAK_DC_LEN = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL3_SET_OSCSWITCH_CNTL1_DC              = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL3_SET_OSCSWITCH_CNTL1_DC_LEN          = 8   ;

static const uint8_t P9A_PERV_ROOT_CTRL4_TP_OSCSWITCH_VSB                    = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL4_TP_OSCSWITCH_VSB_LEN                = 32  ;

static const uint8_t P9A_PERV_ROOT_CTRL4_CLEAR_TP_OSCSWITCH_VSB              = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL4_CLEAR_TP_OSCSWITCH_VSB_LEN          = 32  ;

static const uint8_t P9A_PERV_ROOT_CTRL4_COPY_ROOT_CTRL4_COPY_REG            = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL4_COPY_ROOT_CTRL4_COPY_REG_LEN        = 32  ;

static const uint8_t P9A_PERV_ROOT_CTRL4_SET_TP_OSCSWITCH_VSB                = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL4_SET_TP_OSCSWITCH_VSB_LEN            = 32  ;

static const uint8_t P9A_PERV_ROOT_CTRL5_TPFSI_OSCSW_ERRINJ0_DC              = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_TPFSI_OSCSW_ERRINJ0_DC_LEN          = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_TPFSI_OSCSW_ERRINJ1_DC              = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_TPFSI_OSCSW_ERRINJ1_DC_LEN          = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_TPFSI_OSCSW_TWEAK_DC                = 6   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_TPFSI_OSCSW_TWEAK_DC_LEN            = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_TPFSI_OSCSW_SKEW_ADJUST_DC          = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_TPFSI_OSCSW_SKEW_ADJUST_DC_LEN      = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_TPFSI_OSCSW_SNS_CONTENT_SEL_DC      = 12  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_TPFSI_OSCSW_SNS_CONTENT_SEL_DC_LEN  = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_15_SPARE_OSC                        = 15  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_TPFSI_TP_CHKSW_DD1_DC               = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_TPFSI_TP_CHKSW_DD1_DC_LEN           = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_24_SPARE_OSC                        = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_25_SPARE_OSC                        = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_26_SPARE_OSC                        = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_27_SPARE_OSC                        = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_28_SPARE_OSC                        = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_29_SPARE_OSC                        = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_30_SPARE_OSC                        = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_31_SPARE_OSC                        = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_TPFSI_OSCSW_ERRINJ0_DC        = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_TPFSI_OSCSW_ERRINJ0_DC_LEN    = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_TPFSI_OSCSW_ERRINJ1_DC        = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_TPFSI_OSCSW_ERRINJ1_DC_LEN    = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_TPFSI_OSCSW_TWEAK_DC          = 6   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_TPFSI_OSCSW_TWEAK_DC_LEN      = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_TPFSI_OSCSW_SKEW_ADJUST_DC    = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_TPFSI_OSCSW_SKEW_ADJUST_DC_LEN = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_TPFSI_OSCSW_SNS_CONTENT_SEL_DC = 12  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_TPFSI_OSCSW_SNS_CONTENT_SEL_DC_LEN = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_15_SPARE_OSC                  = 15  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_TPFSI_TP_CHKSW_DD1_DC         = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_TPFSI_TP_CHKSW_DD1_DC_LEN     = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_24_SPARE_OSC                  = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_25_SPARE_OSC                  = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_26_SPARE_OSC                  = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_27_SPARE_OSC                  = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_28_SPARE_OSC                  = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_29_SPARE_OSC                  = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_30_SPARE_OSC                  = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_CLEAR_31_SPARE_OSC                  = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL5_COPY_ROOT_CTRL5_COPY_REG            = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_COPY_ROOT_CTRL5_COPY_REG_LEN        = 32  ;

static const uint8_t P9A_PERV_ROOT_CTRL5_SET_TPFSI_OSCSW_ERRINJ0_DC          = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_TPFSI_OSCSW_ERRINJ0_DC_LEN      = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_TPFSI_OSCSW_ERRINJ1_DC          = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_TPFSI_OSCSW_ERRINJ1_DC_LEN      = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_TPFSI_OSCSW_TWEAK_DC            = 6   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_TPFSI_OSCSW_TWEAK_DC_LEN        = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_TPFSI_OSCSW_SKEW_ADJUST_DC      = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_TPFSI_OSCSW_SKEW_ADJUST_DC_LEN  = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_TPFSI_OSCSW_SNS_CONTENT_SEL_DC  = 12  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_TPFSI_OSCSW_SNS_CONTENT_SEL_DC_LEN = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_15_SPARE_OSC                    = 15  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_TPFSI_TP_CHKSW_DD1_DC           = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_TPFSI_TP_CHKSW_DD1_DC_LEN       = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_24_SPARE_OSC                    = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_25_SPARE_OSC                    = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_26_SPARE_OSC                    = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_27_SPARE_OSC                    = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_28_SPARE_OSC                    = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_29_SPARE_OSC                    = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_30_SPARE_OSC                    = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL5_SET_31_SPARE_OSC                    = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL6_TP_PLLREFCLK_RCVR_TERM_DC           = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_TP_PLLREFCLK_RCVR_TERM_DC_LEN       = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_TP_PCIREFCLK_RCVR_TERM_DC           = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_TP_PCIREFCLK_RCVR_TERM_DC_LEN       = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_REFCLK_0_TERM_DIS_DC                = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_REFCLK_1_TERM_DIS_DC                = 5   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_6_SPARE_TERM_DIS                    = 6   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_7_SPARE_TERM_DIS                    = 7   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_TPFSI_OSCSW0_PGOOD_N                = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_TPFSI_OSCSW1_PGOOD                  = 9   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_10_SPARE_REFCLOCK                   = 10  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_11_SPARE_REFCLOCK                   = 11  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_12TO23_SPARE                        = 12  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_12TO23_SPARE_LEN                    = 12  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_GP_TP_GLBCK_VSB_NEST_MESH_SEL_DC    = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_25_SPARE_REFCLOCK_CONTROL           = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_26_SPARE_REFCLOCK_CONTROL           = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_TPFSI_ALTREFCLK_SEL                 = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_TPFSI_ALTREFCLK_SE1                 = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_29_SPARE_REFCLOCK_CONTROL           = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_30_SPARE_REFCLOCK_CONTROL           = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_31_SPARE_REFCLOCK_CONTROL           = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_TP_PLLREFCLK_RCVR_TERM_DC     = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_TP_PLLREFCLK_RCVR_TERM_DC_LEN = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_TP_PCIREFCLK_RCVR_TERM_DC     = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_TP_PCIREFCLK_RCVR_TERM_DC_LEN = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_REFCLK_0_TERM_DIS_DC          = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_REFCLK_1_TERM_DIS_DC          = 5   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_6_SPARE_TERM_DIS              = 6   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_7_SPARE_TERM_DIS              = 7   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_TPFSI_OSCSW0_PGOOD_N          = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_TPFSI_OSCSW1_PGOOD            = 9   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_10_SPARE_REFCLOCK             = 10  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_11_SPARE_REFCLOCK             = 11  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_12TO23_SPARE                  = 12  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_12TO23_SPARE_LEN              = 12  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_GP_TP_GLBCK_VSB_NEST_MESH_SEL_DC = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_25_SPARE_REFCLOCK_CONTROL     = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_26_SPARE_REFCLOCK_CONTROL     = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_TPFSI_ALTREFCLK_SEL           = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_TPFSI_ALTREFCLK_SE1           = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_29_SPARE_REFCLOCK_CONTROL     = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_30_SPARE_REFCLOCK_CONTROL     = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_CLEAR_31_SPARE_REFCLOCK_CONTROL     = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG            = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG_LEN        = 32  ;

static const uint8_t P9A_PERV_ROOT_CTRL6_SET_TP_PLLREFCLK_RCVR_TERM_DC       = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_TP_PLLREFCLK_RCVR_TERM_DC_LEN   = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_TP_PCIREFCLK_RCVR_TERM_DC       = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_TP_PCIREFCLK_RCVR_TERM_DC_LEN   = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_REFCLK_0_TERM_DIS_DC            = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_REFCLK_1_TERM_DIS_DC            = 5   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_6_SPARE_TERM_DIS                = 6   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_7_SPARE_TERM_DIS                = 7   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_TPFSI_OSCSW0_PGOOD_N            = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_TPFSI_OSCSW1_PGOOD              = 9   ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_10_SPARE_REFCLOCK               = 10  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_11_SPARE_REFCLOCK               = 11  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_12TO23_SPARE                    = 12  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_12TO23_SPARE_LEN                = 12  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_GP_TP_GLBCK_VSB_NEST_MESH_SEL_DC = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_25_SPARE_REFCLOCK_CONTROL       = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_26_SPARE_REFCLOCK_CONTROL       = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_TPFSI_ALTREFCLK_SEL             = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_TPFSI_ALTREFCLK_SE1             = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_29_SPARE_REFCLOCK_CONTROL       = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_30_SPARE_REFCLOCK_CONTROL       = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL6_SET_31_SPARE_REFCLOCK_CONTROL       = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL7_TP_TPIO_OMI_REFCLK_EN_DC            = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL7_TP_TPIO_OMI_REFCLK_EN_DC_LEN        = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_16_SPARE_RESONANT_CLOCKING_CONTROL  = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_17_SPARE_RESONANT_CLOCKING_CONTROL  = 17  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_TP_TPIO_NV_REFCLK_EN_DC             = 18  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_TP_TPIO_NV_REFCLK_EN_DC_LEN         = 6   ;
static const uint8_t P9A_PERV_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL  = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL  = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL  = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL  = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL  = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL  = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL  = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL  = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL7_CLEAR_TP_TPIO_OMI_REFCLK_EN_DC      = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL7_CLEAR_TP_TPIO_OMI_REFCLK_EN_DC_LEN  = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_CLEAR_16_SPARE_RESONANT_CLOCKING_CONTROL = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_CLEAR_17_SPARE_RESONANT_CLOCKING_CONTROL = 17  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_CLEAR_TP_TPIO_NV_REFCLK_EN_DC       = 18  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_CLEAR_TP_TPIO_NV_REFCLK_EN_DC_LEN   = 6   ;
static const uint8_t P9A_PERV_ROOT_CTRL7_CLEAR_24_SPARE_RESONANT_CLOCKING_CONTROL = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_CLEAR_25_SPARE_RESONANT_CLOCKING_CONTROL = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_CLEAR_26_SPARE_RESONANT_CLOCKING_CONTROL = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_CLEAR_27_SPARE_RESONANT_CLOCKING_CONTROL = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_CLEAR_28_SPARE_RESONANT_CLOCKING_CONTROL = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_CLEAR_29_SPARE_RESONANT_CLOCKING_CONTROL = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_CLEAR_30_SPARE_RESONANT_CLOCKING_CONTROL = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_CLEAR_31_SPARE_RESONANT_CLOCKING_CONTROL = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG            = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG_LEN        = 32  ;

static const uint8_t P9A_PERV_ROOT_CTRL7_SET_TP_TPIO_OMI_REFCLK_EN_DC        = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL7_SET_TP_TPIO_OMI_REFCLK_EN_DC_LEN    = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_SET_16_SPARE_RESONANT_CLOCKING_CONTROL = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_SET_17_SPARE_RESONANT_CLOCKING_CONTROL = 17  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_SET_TP_TPIO_NV_REFCLK_EN_DC         = 18  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_SET_TP_TPIO_NV_REFCLK_EN_DC_LEN     = 6   ;
static const uint8_t P9A_PERV_ROOT_CTRL7_SET_24_SPARE_RESONANT_CLOCKING_CONTROL = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_SET_25_SPARE_RESONANT_CLOCKING_CONTROL = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_SET_26_SPARE_RESONANT_CLOCKING_CONTROL = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_SET_27_SPARE_RESONANT_CLOCKING_CONTROL = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_SET_28_SPARE_RESONANT_CLOCKING_CONTROL = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_SET_29_SPARE_RESONANT_CLOCKING_CONTROL = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_SET_30_SPARE_RESONANT_CLOCKING_CONTROL = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL7_SET_31_SPARE_RESONANT_CLOCKING_CONTROL = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL8_TP_SS0_PLL_RESET                    = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_SS0_PLL_BYPASS                   = 1   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_SS0_PLL_TEST_EN                  = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_3_SPARE_SS_PLL_CONTROL              = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_FILT0_PLL_RESET                  = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_FILT0_PLL_BYPASS                 = 5   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_FILT0_PLL_TEST_EN                = 6   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SPARE_FILT0_PLL                     = 7   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_FILT1_PLL_RESET                  = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_FILT1_PLL_BYPASS                 = 9   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_FILT1_PLL_TEST_EN                = 10  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SPARE_FILT1_PLL                     = 11  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_PLL_TEST_EN                      = 12  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_PLL_FORCE_OUT_EN_DC              = 13  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_14_SPARE_PLL                        = 14  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_15_SPARE_PLL                        = 15  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_CLK_ASYNC_RESET_DC               = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_CLK_DIV_BYPASS_EN_DC             = 17  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_CLK_PDLY_BYPASS1_EN_DC           = 18  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_CLK_PDLY_BYPASS2_EN_DC           = 19  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_PLL_CLKIN_SEL8_DC                = 20  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_21_SPARE_PLL_CONTROL                = 21  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_22_SPARE_PLL_CONTROL                = 22  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_23_SPARE_PLL_CONTROL                = 23  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_FSI_CLKIN_SEL_DC                 = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_PLL_CLKIN_SEL5_DC                = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_PLL_CLKIN_SEL6_DC                = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_PLL_CLKIN_SEL7_DC                = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_PLL_CLKIN_SEL1_DC                = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_PLL_CLKIN_SEL2_DC                = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_PLL_CLKIN_SEL3_DC                = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_PLL_CLKIN_SEL4_DC                = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_SS0_PLL_RESET              = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_SS0_PLL_BYPASS             = 1   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_SS0_PLL_TEST_EN            = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_3_SPARE_SS_PLL_CONTROL        = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_FILT0_PLL_RESET            = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_FILT0_PLL_BYPASS           = 5   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_FILT0_PLL_TEST_EN          = 6   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_SPARE_FILT0_PLL               = 7   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_FILT1_PLL_RESET            = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_FILT1_PLL_BYPASS           = 9   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_FILT1_PLL_TEST_EN          = 10  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_SPARE_FILT1_PLL               = 11  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_PLL_TEST_EN                = 12  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_PLL_FORCE_OUT_EN_DC        = 13  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_14_SPARE_PLL                  = 14  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_15_SPARE_PLL                  = 15  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_CLK_ASYNC_RESET_DC         = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_CLK_DIV_BYPASS_EN_DC       = 17  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_CLK_PDLY_BYPASS1_EN_DC     = 18  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_CLK_PDLY_BYPASS2_EN_DC     = 19  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_PLL_CLKIN_SEL8_DC          = 20  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_21_SPARE_PLL_CONTROL          = 21  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_22_SPARE_PLL_CONTROL          = 22  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_23_SPARE_PLL_CONTROL          = 23  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_FSI_CLKIN_SEL_DC           = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_PLL_CLKIN_SEL5_DC          = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_PLL_CLKIN_SEL6_DC          = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_PLL_CLKIN_SEL7_DC          = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_PLL_CLKIN_SEL1_DC          = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_PLL_CLKIN_SEL2_DC          = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_PLL_CLKIN_SEL3_DC          = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_CLEAR_TP_PLL_CLKIN_SEL4_DC          = 31  ;

static const uint8_t P9A_PERV_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG            = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG_LEN        = 32  ;

static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_SS0_PLL_RESET                = 0   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_SS0_PLL_BYPASS               = 1   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_SS0_PLL_TEST_EN              = 2   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_3_SPARE_SS_PLL_CONTROL          = 3   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_FILT0_PLL_RESET              = 4   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_FILT0_PLL_BYPASS             = 5   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_FILT0_PLL_TEST_EN            = 6   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_SPARE_FILT0_PLL                 = 7   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_FILT1_PLL_RESET              = 8   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_FILT1_PLL_BYPASS             = 9   ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_FILT1_PLL_TEST_EN            = 10  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_SPARE_FILT1_PLL                 = 11  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_PLL_TEST_EN                  = 12  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_PLL_FORCE_OUT_EN_DC          = 13  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_14_SPARE_PLL                    = 14  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_15_SPARE_PLL                    = 15  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_CLK_ASYNC_RESET_DC           = 16  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_CLK_DIV_BYPASS_EN_DC         = 17  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_CLK_PDLY_BYPASS1_EN_DC       = 18  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_CLK_PDLY_BYPASS2_EN_DC       = 19  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_PLL_CLKIN_SEL8_DC            = 20  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_21_SPARE_PLL_CONTROL            = 21  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_22_SPARE_PLL_CONTROL            = 22  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_23_SPARE_PLL_CONTROL            = 23  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_FSI_CLKIN_SEL_DC             = 24  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_PLL_CLKIN_SEL5_DC            = 25  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_PLL_CLKIN_SEL6_DC            = 26  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_PLL_CLKIN_SEL7_DC            = 27  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_PLL_CLKIN_SEL1_DC            = 28  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_PLL_CLKIN_SEL2_DC            = 29  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_PLL_CLKIN_SEL3_DC            = 30  ;
static const uint8_t P9A_PERV_ROOT_CTRL8_SET_TP_PLL_CLKIN_SEL4_DC            = 31  ;

static const uint8_t P9A_PERV_RSB_FDA_IODA_ADDR_0220_REG_AUTO_INCR_EN        = 0   ;
static const uint8_t P9A_PERV_RSB_FDA_IODA_ADDR_0220_REG_TABLE_SELECT        = 11  ;
static const uint8_t P9A_PERV_RSB_FDA_IODA_ADDR_0220_REG_TABLE_SELECT_LEN    = 5   ;
static const uint8_t P9A_PERV_RSB_FDA_IODA_ADDR_0220_REG_TABLE_ADDRESS_VALUE = 53  ;
static const uint8_t P9A_PERV_RSB_FDA_IODA_ADDR_0220_REG_TABLE_ADDRESS_VALUE_LEN = 10  ;

static const uint8_t P9A_PERV_RSB_FDA_PHB_CR_0160_REG_32BIT_MSI_ENABLE       = 8   ;
static const uint8_t P9A_PERV_RSB_FDA_PHB_CR_0160_REG_64BIT_MSI_ENABLE       = 14  ;

static const uint8_t P9A_PERV_RSB_FDA_SPEC_CTL_0218_REG_TCE_DMARD_EN         = 0   ;
static const uint8_t P9A_PERV_RSB_FDA_SPEC_CTL_0218_REG_TCE_DMAWR_EN         = 1   ;
static const uint8_t P9A_PERV_RSB_FDA_SPEC_CTL_0218_REG_RTC_DMARD_EN         = 2   ;
static const uint8_t P9A_PERV_RSB_FDA_SPEC_CTL_0218_REG_RTC_DMAWR_EN         = 3   ;
static const uint8_t P9A_PERV_RSB_FDA_SPEC_CTL_0218_REG_TCE_LRU_UPD_DISABLE  = 5   ;
static const uint8_t P9A_PERV_RSB_FDA_SPEC_CTL_0218_REG_RTC_LRU_UPD_RID_DISABLE = 6   ;

static const uint8_t P9A_PERV_RXE_ARB_FDA_ASN_01C0_REG_NOTIFY_CMP_VALUE      = 0   ;
static const uint8_t P9A_PERV_RXE_ARB_FDA_ASN_01C0_REG_NOTIFY_CMP_VALUE_LEN  = 16  ;
static const uint8_t P9A_PERV_RXE_ARB_FDA_ASN_01C0_REG_NOTIFY_MSK_VALUE      = 16  ;
static const uint8_t P9A_PERV_RXE_ARB_FDA_ASN_01C0_REG_NOTIFY_MSK_VALUE_LEN  = 16  ;
static const uint8_t P9A_PERV_RXE_ARB_FDA_ASN_01C0_REG_NOTIFY_EN             = 42  ;

static const uint8_t P9A_PERV_RXE_ARB_FDA_ASN_01C8_REG_CAPP_NOTIFY_CMP_VALUE = 0   ;
static const uint8_t P9A_PERV_RXE_ARB_FDA_ASN_01C8_REG_CAPP_NOTIFY_CMP_VALUE_LEN = 16  ;
static const uint8_t P9A_PERV_RXE_ARB_FDA_ASN_01C8_REG_CAPP_NOTIFY_MSK_VALUE = 16  ;
static const uint8_t P9A_PERV_RXE_ARB_FDA_ASN_01C8_REG_CAPP_NOTIFY_MSK_VALUE_LEN = 16  ;
static const uint8_t P9A_PERV_RXE_ARB_FDA_ASN_01C8_REG_CAPP_NOTIFY_EN        = 42  ;

static const uint8_t P9A_PERV_RXE_ARB_FDA_PELTV_BAR_0188_REG_EN              = 0   ;
static const uint8_t P9A_PERV_RXE_ARB_FDA_PELTV_BAR_0188_REG_VALUE           = 8   ;
static const uint8_t P9A_PERV_RXE_ARB_FDA_PELTV_BAR_0188_REG_VALUE_LEN       = 43  ;

static const uint8_t P9A_PERV_RXE_ARB_FDA_RTT_BAR_0168_REG_EN                = 0   ;
static const uint8_t P9A_PERV_RXE_ARB_FDA_RTT_BAR_0168_REG_VALUE             = 8   ;
static const uint8_t P9A_PERV_RXE_ARB_FDA_RTT_BAR_0168_REG_VALUE_LEN         = 39  ;

static const uint8_t P9A_PERV_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL          = 48  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN      = 2   ;
static const uint8_t P9A_PERV_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A                 = 50  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B                 = 51  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE              = 52  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL2_EO_PL_PR_DDC_A                    = 53  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL2_EO_PL_PR_DDC_B                    = 54  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A           = 55  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B           = 56  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI              = 57  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI              = 58  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A    = 59  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B    = 60  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A          = 61  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B          = 62  ;

static const uint8_t P9A_PERV_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET            = 48  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN        = 6   ;
static const uint8_t P9A_PERV_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET            = 54  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN        = 6   ;
static const uint8_t P9A_PERV_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE                = 60  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN   = 61  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE   = 62  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_PERV_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP           = 48  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM             = 49  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN         = 5   ;
static const uint8_t P9A_PERV_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP        = 54  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM          = 55  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN      = 3   ;
static const uint8_t P9A_PERV_RX_BIT_CNTL4_EO_PL_PR_RESET                    = 62  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL4_EO_PL_IORESET                     = 63  ;

static const uint8_t P9A_PERV_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_PERV_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_PERV_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL               = 48  ;
static const uint8_t P9A_PERV_RX_BIT_CNTLX1_EO_PL_PIPE_SEL                   = 49  ;
static const uint8_t P9A_PERV_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN               = 2   ;
static const uint8_t P9A_PERV_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A                 = 51  ;
static const uint8_t P9A_PERV_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN                = 52  ;
static const uint8_t P9A_PERV_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE                 = 53  ;
static const uint8_t P9A_PERV_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN             = 2   ;
static const uint8_t P9A_PERV_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT       = 57  ;

static const uint8_t P9A_PERV_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN               = 48  ;
static const uint8_t P9A_PERV_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL           = 49  ;
static const uint8_t P9A_PERV_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A             = 50  ;
static const uint8_t P9A_PERV_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B             = 51  ;
static const uint8_t P9A_PERV_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS           = 52  ;
static const uint8_t P9A_PERV_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS           = 53  ;

static const uint8_t P9A_PERV_RX_BIT_MODE2_EO_PL_PR_FW_OFF                   = 56  ;
static const uint8_t P9A_PERV_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT           = 57  ;
static const uint8_t P9A_PERV_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN       = 3   ;
static const uint8_t P9A_PERV_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP               = 60  ;
static const uint8_t P9A_PERV_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN           = 4   ;

static const uint8_t P9A_PERV_RX_BIT_MODE3_EO_PL_BER_CFG                     = 48  ;
static const uint8_t P9A_PERV_RX_BIT_MODE3_EO_PL_BER_CFG_LEN                 = 3   ;
static const uint8_t P9A_PERV_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG                = 51  ;
static const uint8_t P9A_PERV_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN            = 2   ;
static const uint8_t P9A_PERV_RX_BIT_MODE3_EO_PL_DDC_CFG                     = 53  ;
static const uint8_t P9A_PERV_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN                 = 2   ;

static const uint8_t P9A_PERV_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN           = 48  ;
static const uint8_t P9A_PERV_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN   = 49  ;
static const uint8_t P9A_PERV_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE    = 50  ;
static const uint8_t P9A_PERV_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_PERV_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE        = 53  ;
static const uint8_t P9A_PERV_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN    = 4   ;
static const uint8_t P9A_PERV_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL    = 57  ;
static const uint8_t P9A_PERV_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_PERV_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_PERV_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL  = 48  ;
static const uint8_t P9A_PERV_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_PERV_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_PERV_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_PERV_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ              = 60  ;
static const uint8_t P9A_PERV_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN          = 4   ;

static const uint8_t P9A_PERV_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_PERV_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_PERV_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_PERV_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL    = 53  ;
static const uint8_t P9A_PERV_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL  = 54  ;
static const uint8_t P9A_PERV_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_PERV_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_PERV_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_PERV_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_PERV_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_PERV_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_PERV_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_PERV_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ             = 60  ;
static const uint8_t P9A_PERV_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN         = 4   ;

static const uint8_t P9A_PERV_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_PERV_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_PERV_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_PERV_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_PERV_RX_CTL_CNTL10_EO_PG_BIST_PRBS_TEST_TIME        = 48  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL10_EO_PG_BIST_PRBS_TEST_TIME_LEN    = 4   ;
static const uint8_t P9A_PERV_RX_CTL_CNTL10_EO_PG_BIST_BUS_DATA_MODE         = 52  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL10_EO_PG_BIST_PRBS_PROP_TIME        = 53  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL10_EO_PG_BIST_PRBS_PROP_TIME_LEN    = 4   ;

static const uint8_t P9A_PERV_RX_CTL_CNTL11_EO_PG_DACTEST_LLMT               = 48  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL11_EO_PG_DACTEST_LLMT_LEN           = 9   ;
static const uint8_t P9A_PERV_RX_CTL_CNTL11_EO_PG_DACTEST_RESET              = 57  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL11_EO_PG_DACTEST_START              = 58  ;

static const uint8_t P9A_PERV_RX_CTL_CNTL12_EO_PG_DACTEST_HLMT               = 48  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL12_EO_PG_DACTEST_HLMT_LEN           = 9   ;

static const uint8_t P9A_PERV_RX_CTL_CNTL13_EO_PG_HIST_MIN_EYE_WIDTH_VALID   = 48  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL13_EO_PG_HIST_MIN_EYE_WIDTH_LANE    = 49  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL13_EO_PG_HIST_MIN_EYE_WIDTH_LANE_LEN = 5   ;
static const uint8_t P9A_PERV_RX_CTL_CNTL13_EO_PG_HIST_MIN_EYE_WIDTH         = 54  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL13_EO_PG_HIST_MIN_EYE_WIDTH_LEN     = 8   ;

static const uint8_t P9A_PERV_RX_CTL_CNTL14_EO_PG_HIST_MIN_EYE_HEIGHT_VALID  = 48  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL14_EO_PG_HIST_MIN_EYE_HEIGHT_LANE   = 49  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL14_EO_PG_HIST_MIN_EYE_HEIGHT_LANE_LEN = 5   ;
static const uint8_t P9A_PERV_RX_CTL_CNTL14_EO_PG_HIST_MIN_EYE_HEIGHT        = 54  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL14_EO_PG_HIST_MIN_EYE_HEIGHT_LEN    = 8   ;

static const uint8_t P9A_PERV_RX_CTL_CNTL1_EO_PG_BER_EN                      = 48  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL1_EO_PG_BER_TIMER_FREEZE_EN         = 49  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL1_EO_PG_BER_COUNT_FREEZE_EN         = 50  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL1_EO_PG_BER_COUNT_SEL               = 51  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL1_EO_PG_BER_COUNT_SEL_LEN           = 4   ;
static const uint8_t P9A_PERV_RX_CTL_CNTL1_EO_PG_BER_TIMER_SEL               = 56  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL1_EO_PG_BER_TIMER_SEL_LEN           = 3   ;
static const uint8_t P9A_PERV_RX_CTL_CNTL1_EO_PG_BER_CLR_COUNT_ON_READ_EN    = 59  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL1_EO_PG_BER_CLR_TIMER_ON_READ_EN    = 60  ;

static const uint8_t P9A_PERV_RX_CTL_CNTL2_EO_PG_TRC_MODE                    = 48  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL2_EO_PG_TRC_MODE_LEN                = 4   ;

static const uint8_t P9A_PERV_RX_CTL_CNTL3_EO_PG_INT_MODE                    = 48  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL3_EO_PG_INT_MODE_LEN                = 4   ;
static const uint8_t P9A_PERV_RX_CTL_CNTL3_EO_PG_INT_CURRENT_STATE           = 52  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL3_EO_PG_INT_CURRENT_STATE_LEN       = 12  ;

static const uint8_t P9A_PERV_RX_CTL_CNTL4_EO_PG_INT_ENABLE_ENC              = 48  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL4_EO_PG_INT_ENABLE_ENC_LEN          = 4   ;
static const uint8_t P9A_PERV_RX_CTL_CNTL4_EO_PG_INT_NEXT_STATE              = 52  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL4_EO_PG_INT_NEXT_STATE_LEN          = 12  ;

static const uint8_t P9A_PERV_RX_CTL_CNTL5_EO_PG_INT_GOTO_STATE              = 52  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL5_EO_PG_INT_GOTO_STATE_LEN          = 12  ;

static const uint8_t P9A_PERV_RX_CTL_CNTL6_EO_PG_INT_RETURN_STATE            = 52  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL6_EO_PG_INT_RETURN_STATE_LEN        = 12  ;

static const uint8_t P9A_PERV_RX_CTL_CNTL8_EO_PG_SERVO_OP                    = 48  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL8_EO_PG_SERVO_OP_LEN                = 15  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL8_EO_PG_SERVO_DONE                  = 63  ;

static const uint8_t P9A_PERV_RX_CTL_CNTL9_EO_PG_BIST_EN                     = 48  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL9_EO_PG_BIST_EXT_START_MODE         = 49  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL9_EO_PG_BIST_INIT_DISABLE           = 50  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL9_EO_PG_BIST_INIT_DISABLE_LEN       = 3   ;
static const uint8_t P9A_PERV_RX_CTL_CNTL9_EO_PG_BIST_CUPLL_LOCK_CHECK_EN    = 53  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL9_EO_PG_BIST_STORE_EYES_LANE_SEL    = 54  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL9_EO_PG_BIST_STORE_EYES_LANE_SEL_LEN = 6   ;
static const uint8_t P9A_PERV_RX_CTL_CNTL9_EO_PG_BIST_STORE_EYES_BANK_SEL    = 60  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL9_EO_PG_BIST_STORE_EYES_BANK_SEL_LEN = 2   ;
static const uint8_t P9A_PERV_RX_CTL_CNTL9_EO_PG_PERVASIVE_CAPT              = 62  ;
static const uint8_t P9A_PERV_RX_CTL_CNTL9_EO_PG_BIST_LL_TEST_EN             = 63  ;

static const uint8_t P9A_PERV_RX_CTL_CNTLX7_EO_PG_CAL_LANE_PHY_GCRMSG        = 56  ;
static const uint8_t P9A_PERV_RX_CTL_CNTLX7_EO_PG_CAL_LANE_PHY_GCRMSG_LEN    = 5   ;

static const uint8_t P9A_PERV_RX_CTL_MODE10_EO_PG_AMP_INIT_CFG               = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE10_EO_PG_AMP_INIT_CFG_LEN           = 3   ;
static const uint8_t P9A_PERV_RX_CTL_MODE10_EO_PG_AMP_RECAL_CFG              = 51  ;
static const uint8_t P9A_PERV_RX_CTL_MODE10_EO_PG_AMP_RECAL_CFG_LEN          = 3   ;
static const uint8_t P9A_PERV_RX_CTL_MODE10_EO_PG_PEAK_INIT_CFG              = 54  ;
static const uint8_t P9A_PERV_RX_CTL_MODE10_EO_PG_PEAK_INIT_CFG_LEN          = 3   ;
static const uint8_t P9A_PERV_RX_CTL_MODE10_EO_PG_PEAK_RECAL_CFG             = 57  ;
static const uint8_t P9A_PERV_RX_CTL_MODE10_EO_PG_PEAK_RECAL_CFG_LEN         = 3   ;
static const uint8_t P9A_PERV_RX_CTL_MODE10_EO_PG_AMP_CFG                    = 60  ;
static const uint8_t P9A_PERV_RX_CTL_MODE10_EO_PG_AMP_CFG_LEN                = 4   ;

static const uint8_t P9A_PERV_RX_CTL_MODE11_EO_PG_OFF_INIT_CFG               = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE11_EO_PG_OFF_INIT_CFG_LEN           = 3   ;
static const uint8_t P9A_PERV_RX_CTL_MODE11_EO_PG_OFF_RECAL_CFG              = 51  ;
static const uint8_t P9A_PERV_RX_CTL_MODE11_EO_PG_OFF_RECAL_CFG_LEN          = 3   ;
static const uint8_t P9A_PERV_RX_CTL_MODE11_EO_PG_CM_CFG                     = 54  ;
static const uint8_t P9A_PERV_RX_CTL_MODE11_EO_PG_CM_CFG_LEN                 = 3   ;
static const uint8_t P9A_PERV_RX_CTL_MODE11_EO_PG_AMIN_CFG                   = 57  ;
static const uint8_t P9A_PERV_RX_CTL_MODE11_EO_PG_AMIN_CFG_LEN               = 3   ;
static const uint8_t P9A_PERV_RX_CTL_MODE11_EO_PG_USERDEF_CFG                = 60  ;
static const uint8_t P9A_PERV_RX_CTL_MODE11_EO_PG_USERDEF_CFG_LEN            = 4   ;

static const uint8_t P9A_PERV_RX_CTL_MODE12_EO_PG_SERVO_CHG_CFG              = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE12_EO_PG_SERVO_CHG_CFG_LEN          = 4   ;
static const uint8_t P9A_PERV_RX_CTL_MODE12_EO_PG_DAC_BO_CFG                 = 52  ;
static const uint8_t P9A_PERV_RX_CTL_MODE12_EO_PG_DAC_BO_CFG_LEN             = 3   ;
static const uint8_t P9A_PERV_RX_CTL_MODE12_EO_PG_FILTER_MODE                = 55  ;
static const uint8_t P9A_PERV_RX_CTL_MODE12_EO_PG_FILTER_MODE_LEN            = 2   ;
static const uint8_t P9A_PERV_RX_CTL_MODE12_EO_PG_MISC_CFG                   = 57  ;
static const uint8_t P9A_PERV_RX_CTL_MODE12_EO_PG_MISC_CFG_LEN               = 2   ;
static const uint8_t P9A_PERV_RX_CTL_MODE12_EO_PG_DISABLE_H1_CLEAR           = 59  ;
static const uint8_t P9A_PERV_RX_CTL_MODE12_EO_PG_VOFF_CFG                   = 60  ;
static const uint8_t P9A_PERV_RX_CTL_MODE12_EO_PG_VOFF_CFG_LEN               = 3   ;
static const uint8_t P9A_PERV_RX_CTL_MODE12_EO_PG_LOFF_AMP_EN                = 63  ;

static const uint8_t P9A_PERV_RX_CTL_MODE13_EO_PG_CM_OFFSET_VAL              = 49  ;
static const uint8_t P9A_PERV_RX_CTL_MODE13_EO_PG_CM_OFFSET_VAL_LEN          = 7   ;
static const uint8_t P9A_PERV_RX_CTL_MODE13_EO_PG_SERVO_THRESH1              = 56  ;
static const uint8_t P9A_PERV_RX_CTL_MODE13_EO_PG_SERVO_THRESH1_LEN          = 4   ;
static const uint8_t P9A_PERV_RX_CTL_MODE13_EO_PG_SERVO_THRESH2              = 60  ;
static const uint8_t P9A_PERV_RX_CTL_MODE13_EO_PG_SERVO_THRESH2_LEN          = 4   ;

static const uint8_t P9A_PERV_RX_CTL_MODE14_EO_PG_AMP_INIT_TIMEOUT           = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE14_EO_PG_AMP_INIT_TIMEOUT_LEN       = 4   ;
static const uint8_t P9A_PERV_RX_CTL_MODE14_EO_PG_AMP_RECAL_TIMEOUT          = 52  ;
static const uint8_t P9A_PERV_RX_CTL_MODE14_EO_PG_AMP_RECAL_TIMEOUT_LEN      = 4   ;
static const uint8_t P9A_PERV_RX_CTL_MODE14_EO_PG_PEAK_INIT_TIMEOUT          = 56  ;
static const uint8_t P9A_PERV_RX_CTL_MODE14_EO_PG_PEAK_INIT_TIMEOUT_LEN      = 4   ;
static const uint8_t P9A_PERV_RX_CTL_MODE14_EO_PG_PEAK_RECAL_TIMEOUT         = 60  ;
static const uint8_t P9A_PERV_RX_CTL_MODE14_EO_PG_PEAK_RECAL_TIMEOUT_LEN     = 4   ;

static const uint8_t P9A_PERV_RX_CTL_MODE15_EO_PG_OFF_INIT_TIMEOUT           = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE15_EO_PG_OFF_INIT_TIMEOUT_LEN       = 4   ;
static const uint8_t P9A_PERV_RX_CTL_MODE15_EO_PG_OFF_RECAL_TIMEOUT          = 52  ;
static const uint8_t P9A_PERV_RX_CTL_MODE15_EO_PG_OFF_RECAL_TIMEOUT_LEN      = 4   ;
static const uint8_t P9A_PERV_RX_CTL_MODE15_EO_PG_CM_TIMEOUT                 = 56  ;
static const uint8_t P9A_PERV_RX_CTL_MODE15_EO_PG_CM_TIMEOUT_LEN             = 4   ;
static const uint8_t P9A_PERV_RX_CTL_MODE15_EO_PG_AMIN_TIMEOUT               = 60  ;
static const uint8_t P9A_PERV_RX_CTL_MODE15_EO_PG_AMIN_TIMEOUT_LEN           = 4   ;

static const uint8_t P9A_PERV_RX_CTL_MODE16_EO_PG_AMP_TIMEOUT                = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE16_EO_PG_AMP_TIMEOUT_LEN            = 4   ;
static const uint8_t P9A_PERV_RX_CTL_MODE16_EO_PG_USERDEF_TIMEOUT            = 52  ;
static const uint8_t P9A_PERV_RX_CTL_MODE16_EO_PG_USERDEF_TIMEOUT_LEN        = 4   ;
static const uint8_t P9A_PERV_RX_CTL_MODE16_EO_PG_BER_TIMEOUT                = 56  ;
static const uint8_t P9A_PERV_RX_CTL_MODE16_EO_PG_BER_TIMEOUT_LEN            = 4   ;
static const uint8_t P9A_PERV_RX_CTL_MODE16_EO_PG_SPARE4_TIMEOUT             = 60  ;
static const uint8_t P9A_PERV_RX_CTL_MODE16_EO_PG_SPARE4_TIMEOUT_LEN         = 4   ;

static const uint8_t P9A_PERV_RX_CTL_MODE17_EO_PG_AMAX_HIGH                  = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE17_EO_PG_AMAX_HIGH_LEN              = 8   ;
static const uint8_t P9A_PERV_RX_CTL_MODE17_EO_PG_AMAX_LOW                   = 56  ;
static const uint8_t P9A_PERV_RX_CTL_MODE17_EO_PG_AMAX_LOW_LEN               = 8   ;

static const uint8_t P9A_PERV_RX_CTL_MODE18_EO_PG_AMP0_FILTER_MASK           = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE18_EO_PG_AMP0_FILTER_MASK_LEN       = 8   ;
static const uint8_t P9A_PERV_RX_CTL_MODE18_EO_PG_AMP1_FILTER_MASK           = 56  ;
static const uint8_t P9A_PERV_RX_CTL_MODE18_EO_PG_AMP1_FILTER_MASK_LEN       = 8   ;

static const uint8_t P9A_PERV_RX_CTL_MODE19_EO_PG_CTLE_GAIN_MAX              = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE19_EO_PG_CTLE_GAIN_MAX_LEN          = 4   ;
static const uint8_t P9A_PERV_RX_CTL_MODE19_EO_PG_AMP_START_VAL              = 56  ;
static const uint8_t P9A_PERV_RX_CTL_MODE19_EO_PG_AMP_START_VAL_LEN          = 8   ;

static const uint8_t P9A_PERV_RX_CTL_MODE1_EO_PG_CLKDIST_PDWN                = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE1_EO_PG_CLKDIST_PDWN_LEN            = 3   ;
static const uint8_t P9A_PERV_RX_CTL_MODE1_EO_PG_BIST_MIN_EYE_WIDTH          = 51  ;
static const uint8_t P9A_PERV_RX_CTL_MODE1_EO_PG_BIST_MIN_EYE_WIDTH_LEN      = 6   ;
static const uint8_t P9A_PERV_RX_CTL_MODE1_EO_PG_A_BIST_EN                   = 57  ;
static const uint8_t P9A_PERV_RX_CTL_MODE1_EO_PG_B_BIST_EN                   = 58  ;
static const uint8_t P9A_PERV_RX_CTL_MODE1_EO_PG_E_BIST_EN                   = 59  ;
static const uint8_t P9A_PERV_RX_CTL_MODE1_EO_PG_BISTCLK_EN                  = 60  ;
static const uint8_t P9A_PERV_RX_CTL_MODE1_EO_PG_BISTCLK_EN_LEN              = 2   ;
static const uint8_t P9A_PERV_RX_CTL_MODE1_EO_PG_DISABLE_BANK_PDWN           = 62  ;

static const uint8_t P9A_PERV_RX_CTL_MODE1_O_PG_MINIKERF                     = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE1_O_PG_MINIKERF_LEN                 = 16  ;

static const uint8_t P9A_PERV_RX_CTL_MODE20_EO_PG_DFE_CONVERGED_CNT_MAX      = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE20_EO_PG_DFE_CONVERGED_CNT_MAX_LEN  = 4   ;
static const uint8_t P9A_PERV_RX_CTL_MODE20_EO_PG_AP110_AP010_DELTA_MAX      = 52  ;
static const uint8_t P9A_PERV_RX_CTL_MODE20_EO_PG_AP110_AP010_DELTA_MAX_LEN  = 4   ;

static const uint8_t P9A_PERV_RX_CTL_MODE21_EO_PG_ENABLE_INTEG_LATCH_OFFSET_CAL = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE21_EO_PG_ENABLE_CTLE_COARSE_CAL     = 49  ;
static const uint8_t P9A_PERV_RX_CTL_MODE21_EO_PG_ENABLE_DAC_H1_CAL          = 50  ;
static const uint8_t P9A_PERV_RX_CTL_MODE21_EO_PG_ENABLE_VGA_CAL             = 51  ;
static const uint8_t P9A_PERV_RX_CTL_MODE21_EO_PG_ENABLE_DFE_H1_CAL          = 52  ;
static const uint8_t P9A_PERV_RX_CTL_MODE21_EO_PG_ENABLE_H1AP_TWEAK          = 53  ;
static const uint8_t P9A_PERV_RX_CTL_MODE21_EO_PG_ENABLE_DDC                 = 54  ;
static const uint8_t P9A_PERV_RX_CTL_MODE21_EO_PG_ENABLE_CM_COARSE_CAL       = 55  ;
static const uint8_t P9A_PERV_RX_CTL_MODE21_EO_PG_ENABLE_CM_FINE_CAL         = 56  ;
static const uint8_t P9A_PERV_RX_CTL_MODE21_EO_PG_ENABLE_VGA_EDGE_OFFSET_CAL = 57  ;
static const uint8_t P9A_PERV_RX_CTL_MODE21_EO_PG_ENABLE_CTLE_EDGE_OFFSET_CAL = 58  ;

static const uint8_t P9A_PERV_RX_CTL_MODE22_EO_PG_RC_ENABLE_INTEG_LATCH_OFFSET_CAL = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE22_EO_PG_RC_ENABLE_CTLE_COARSE_CAL  = 49  ;
static const uint8_t P9A_PERV_RX_CTL_MODE22_EO_PG_RC_ENABLE_DAC_H1_CAL       = 50  ;
static const uint8_t P9A_PERV_RX_CTL_MODE22_EO_PG_RC_ENABLE_VGA_CAL          = 51  ;
static const uint8_t P9A_PERV_RX_CTL_MODE22_EO_PG_RC_ENABLE_DFE_H1_CAL       = 52  ;
static const uint8_t P9A_PERV_RX_CTL_MODE22_EO_PG_RC_ENABLE_H1AP_TWEAK       = 53  ;
static const uint8_t P9A_PERV_RX_CTL_MODE22_EO_PG_RC_ENABLE_DDC              = 54  ;
static const uint8_t P9A_PERV_RX_CTL_MODE22_EO_PG_RC_ENABLE_CM_COARSE_CAL    = 55  ;
static const uint8_t P9A_PERV_RX_CTL_MODE22_EO_PG_RC_ENABLE_CM_FINE_CAL      = 56  ;
static const uint8_t P9A_PERV_RX_CTL_MODE22_EO_PG_RC_ENABLE_VGA_EDGE_OFFSET_CAL = 57  ;
static const uint8_t P9A_PERV_RX_CTL_MODE22_EO_PG_RC_ENABLE_CTLE_EDGE_OFFSET_CAL = 58  ;

static const uint8_t P9A_PERV_RX_CTL_MODE23_EO_PG_IREF_RES_DAC               = 50  ;
static const uint8_t P9A_PERV_RX_CTL_MODE23_EO_PG_IREF_RES_DAC_LEN           = 3   ;
static const uint8_t P9A_PERV_RX_CTL_MODE23_EO_PG_IREF_BYPASS                = 53  ;
static const uint8_t P9A_PERV_RX_CTL_MODE23_EO_PG_IREF_PDWN_B                = 54  ;

static const uint8_t P9A_PERV_RX_CTL_MODE24_EO_PG_H1AP_CFG                   = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE24_EO_PG_H1AP_CFG_LEN               = 2   ;
static const uint8_t P9A_PERV_RX_CTL_MODE24_EO_PG_CTLE_UPDATE_MODE           = 50  ;
static const uint8_t P9A_PERV_RX_CTL_MODE24_EO_PG_USER_FILTER_MASK           = 56  ;
static const uint8_t P9A_PERV_RX_CTL_MODE24_EO_PG_USER_FILTER_MASK_LEN       = 8   ;

static const uint8_t P9A_PERV_RX_CTL_MODE26_EO_PG_ENABLE_CTLE_1ST_LATCH_OFFSET_CAL = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE26_EO_PG_ENABLE_CTLE_2ND_LATCH_OFFSET_CAL = 49  ;
static const uint8_t P9A_PERV_RX_CTL_MODE26_EO_PG_ENABLE_VGA_AMAX_MODE       = 50  ;

static const uint8_t P9A_PERV_RX_CTL_MODE27_EO_PG_RC_ENABLE_CTLE_1ST_LATCH_OFFSET_CAL = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE27_EO_PG_RC_ENABLE_CTLE_2ND_LATCH_OFFSET_CAL = 49  ;
static const uint8_t P9A_PERV_RX_CTL_MODE27_EO_PG_RC_ENABLE_VGA_AMAX_MODE    = 50  ;
static const uint8_t P9A_PERV_RX_CTL_MODE27_EO_PG_RC_ENABLE_AUTO_RECAL       = 51  ;

static const uint8_t P9A_PERV_RX_CTL_MODE28_EO_PG_DC_ENABLE_CM_COARSE_CAL    = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE28_EO_PG_DC_ENABLE_CM_FINE_CAL      = 49  ;
static const uint8_t P9A_PERV_RX_CTL_MODE28_EO_PG_DC_ENABLE_CTLE_1ST_LATCH_OFFSET_CAL = 50  ;
static const uint8_t P9A_PERV_RX_CTL_MODE28_EO_PG_DC_ENABLE_CTLE_2ND_LATCH_OFFSET_CAL = 51  ;
static const uint8_t P9A_PERV_RX_CTL_MODE28_EO_PG_DC_ENABLE_INTEG_LATCH_OFFSET_CAL = 52  ;

static const uint8_t P9A_PERV_RX_CTL_MODE29_EO_PG_APX111_HIGH                = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE29_EO_PG_APX111_HIGH_LEN            = 8   ;
static const uint8_t P9A_PERV_RX_CTL_MODE29_EO_PG_APX111_LOW                 = 56  ;
static const uint8_t P9A_PERV_RX_CTL_MODE29_EO_PG_APX111_LOW_LEN             = 8   ;

static const uint8_t P9A_PERV_RX_CTL_MODE2_EO_PG_DFE_CA_CFG                  = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE2_EO_PG_DFE_CA_CFG_LEN              = 2   ;
static const uint8_t P9A_PERV_RX_CTL_MODE2_EO_PG_SCOPE_CONTROL               = 50  ;
static const uint8_t P9A_PERV_RX_CTL_MODE2_EO_PG_SCOPE_CONTROL_LEN           = 4   ;
static const uint8_t P9A_PERV_RX_CTL_MODE2_EO_PG_RECAL_REQ_DL_MASK           = 54  ;
static const uint8_t P9A_PERV_RX_CTL_MODE2_EO_PG_RECAL_DONE_DL_MASK          = 55  ;
static const uint8_t P9A_PERV_RX_CTL_MODE2_EO_PG_RUN_LANE_DL_MASK            = 56  ;
static const uint8_t P9A_PERV_RX_CTL_MODE2_EO_PG_RECAL_ABORT_DL_MASK         = 57  ;
static const uint8_t P9A_PERV_RX_CTL_MODE2_EO_PG_INIT_DONE_DL_MASK           = 58  ;
static const uint8_t P9A_PERV_RX_CTL_MODE2_EO_PG_DATA_PIPE_CLR_ON_READ_MODE  = 59  ;

static const uint8_t P9A_PERV_RX_CTL_MODE2_O_PG_OCTANT_SELECT                = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE2_O_PG_OCTANT_SELECT_LEN            = 3   ;
static const uint8_t P9A_PERV_RX_CTL_MODE2_O_PG_SPEED_SELECT                 = 51  ;
static const uint8_t P9A_PERV_RX_CTL_MODE2_O_PG_SPEED_SELECT_LEN             = 2   ;
static const uint8_t P9A_PERV_RX_CTL_MODE2_O_PG_AC_COUPLED                   = 53  ;

static const uint8_t P9A_PERV_RX_CTL_MODE5_EO_PG_TRACKING_TIMEOUT_SEL        = 56  ;
static const uint8_t P9A_PERV_RX_CTL_MODE5_EO_PG_TRACKING_TIMEOUT_SEL_LEN    = 4   ;

static const uint8_t P9A_PERV_RX_CTL_MODE6_EO_PG_CONVERGED_END_COUNT         = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE6_EO_PG_CONVERGED_END_COUNT_LEN     = 4   ;
static const uint8_t P9A_PERV_RX_CTL_MODE6_EO_PG_HIST_MIN_EYE_WIDTH_MODE     = 52  ;
static const uint8_t P9A_PERV_RX_CTL_MODE6_EO_PG_HIST_MIN_EYE_WIDTH_MODE_LEN = 2   ;
static const uint8_t P9A_PERV_RX_CTL_MODE6_EO_PG_HIST_MIN_EYE_HEIGHT_MODE    = 54  ;
static const uint8_t P9A_PERV_RX_CTL_MODE6_EO_PG_HIST_MIN_EYE_HEIGHT_MODE_LEN = 2   ;
static const uint8_t P9A_PERV_RX_CTL_MODE6_EO_PG_AMP_GAIN_CNT_MAX            = 56  ;
static const uint8_t P9A_PERV_RX_CTL_MODE6_EO_PG_AMP_GAIN_CNT_MAX_LEN        = 4   ;

static const uint8_t P9A_PERV_RX_CTL_MODE7_EO_PG_ABORT_CHECK_TIMEOUT_SEL     = 48  ;
static const uint8_t P9A_PERV_RX_CTL_MODE7_EO_PG_ABORT_CHECK_TIMEOUT_SEL_LEN = 4   ;
static const uint8_t P9A_PERV_RX_CTL_MODE7_EO_PG_POLLING_TIMEOUT_SEL         = 52  ;
static const uint8_t P9A_PERV_RX_CTL_MODE7_EO_PG_POLLING_TIMEOUT_SEL_LEN     = 4   ;

static const uint8_t P9A_PERV_RX_CTL_MODE9_EO_PG_MIN_EYE_WIDTH               = 50  ;
static const uint8_t P9A_PERV_RX_CTL_MODE9_EO_PG_MIN_EYE_WIDTH_LEN           = 6   ;
static const uint8_t P9A_PERV_RX_CTL_MODE9_EO_PG_MIN_EYE_HEIGHT              = 56  ;
static const uint8_t P9A_PERV_RX_CTL_MODE9_EO_PG_MIN_EYE_HEIGHT_LEN          = 8   ;

static const uint8_t P9A_PERV_RX_CTL_STAT1_EO_PG_SERVO_RESULT                = 48  ;
static const uint8_t P9A_PERV_RX_CTL_STAT1_EO_PG_SERVO_RESULT_LEN            = 8   ;

static const uint8_t P9A_PERV_RX_CTL_STAT2_EO_PG_BIST_INIT_DONE              = 48  ;
static const uint8_t P9A_PERV_RX_CTL_STAT2_EO_PG_BIST_DONE                   = 49  ;
static const uint8_t P9A_PERV_RX_CTL_STAT2_EO_PG_BIST_LL_ERR                 = 50  ;
static const uint8_t P9A_PERV_RX_CTL_STAT2_EO_PG_BIST_NO_EDGE_DET            = 51  ;
static const uint8_t P9A_PERV_RX_CTL_STAT2_EO_PG_BIST_EYE_A_WIDTH            = 52  ;
static const uint8_t P9A_PERV_RX_CTL_STAT2_EO_PG_BIST_EYE_A_WIDTH_LEN        = 6   ;
static const uint8_t P9A_PERV_RX_CTL_STAT2_EO_PG_BIST_EYE_B_WIDTH            = 58  ;
static const uint8_t P9A_PERV_RX_CTL_STAT2_EO_PG_BIST_EYE_B_WIDTH_LEN        = 6   ;

static const uint8_t P9A_PERV_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE               = 48  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN           = 5   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN                 = 53  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN             = 4   ;

static const uint8_t P9A_PERV_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS             = 48  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN         = 6   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN               = 54  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA              = 55  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN          = 3   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS             = 58  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN         = 6   ;

static const uint8_t P9A_PERV_RX_DAC_CNTL1_O_PL_B_CONTROLS                   = 48  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN               = 5   ;

static const uint8_t P9A_PERV_RX_DAC_CNTL2_EO_PL_A_CONTROLS                  = 48  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN              = 6   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL2_EO_PL_CM_CNTL                     = 54  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN                 = 3   ;

static const uint8_t P9A_PERV_RX_DAC_CNTL2_O_PL_B_OFFSET_E0                  = 48  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN              = 7   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL2_O_PL_B_OFFSET_E1                  = 56  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN              = 7   ;

static const uint8_t P9A_PERV_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0                 = 48  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN             = 7   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1                 = 56  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN             = 7   ;

static const uint8_t P9A_PERV_RX_DAC_CNTL3_O_PL_B_OFFSET_O0                  = 48  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN              = 7   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL3_O_PL_B_OFFSET_O1                  = 56  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN              = 7   ;

static const uint8_t P9A_PERV_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0                 = 48  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN             = 7   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1                 = 56  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN             = 7   ;

static const uint8_t P9A_PERV_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN          = 48  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN      = 4   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN       = 52  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN   = 5   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN        = 57  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN    = 5   ;

static const uint8_t P9A_PERV_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN         = 48  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN     = 4   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN      = 52  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN  = 5   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN       = 57  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN   = 5   ;

static const uint8_t P9A_PERV_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE                = 48  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN            = 5   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN                  = 53  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN              = 4   ;

static const uint8_t P9A_PERV_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE               = 48  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN           = 5   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN                 = 53  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN             = 4   ;

static const uint8_t P9A_PERV_RX_DAC_CNTL6_O_PL_B_H1E_VAL                    = 48  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN                = 7   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL6_O_PL_B_H1O_VAL                    = 56  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN                = 7   ;

static const uint8_t P9A_PERV_RX_DAC_CNTL7_EO_PL_A_H1E_VAL                   = 48  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN               = 7   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL7_EO_PL_A_H1O_VAL                   = 56  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN               = 7   ;

static const uint8_t P9A_PERV_RX_DAC_CNTL7_O_PL_E_CONTROLS                   = 48  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN               = 3   ;

static const uint8_t P9A_PERV_RX_DAC_CNTL8_EO_PL_AMP_VAL                     = 48  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN                 = 8   ;

static const uint8_t P9A_PERV_RX_DAC_CNTL8_O_PL_E_OFFSET_E                   = 48  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN               = 7   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL8_O_PL_E_OFFSET                     = 56  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN                 = 7   ;

static const uint8_t P9A_PERV_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN          = 48  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN      = 4   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN       = 52  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN   = 5   ;
static const uint8_t P9A_PERV_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN        = 57  ;
static const uint8_t P9A_PERV_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN    = 5   ;

static const uint8_t P9A_PERV_RX_DATASM_CNTLX1_EO_PG_RX_BER_COUNT_CLR_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_PERV_RX_DATASM_CNTLX1_EO_PG_RX_BER_TIMER_CLR_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_PERV_RX_DATASM_CNTLX1_EO_PG_RX_SCOPE_CAPTURE_WO_PULSE_SLOW_SIGNAL = 51  ;
static const uint8_t P9A_PERV_RX_DATASM_CNTLX1_EO_PG_RX_DATA_PIPE_CAPTURE_WO_PULSE_SLOW_SIGNAL = 52  ;
static const uint8_t P9A_PERV_RX_DATASM_CNTLX1_EO_PG_RX_RESET_SERVO_STATUS_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_PERV_RX_DATASM_CNTLX1_EO_PG_RX_BER_RESET_WO_PULSE_SLOW_SIGNAL = 54  ;

static const uint8_t P9A_PERV_RX_DATASM_SPARE_MODE_PG_0                      = 48  ;
static const uint8_t P9A_PERV_RX_DATASM_SPARE_MODE_PG_1                      = 49  ;
static const uint8_t P9A_PERV_RX_DATASM_SPARE_MODE_PG_2                      = 50  ;
static const uint8_t P9A_PERV_RX_DATASM_SPARE_MODE_PG_3                      = 51  ;
static const uint8_t P9A_PERV_RX_DATASM_SPARE_MODE_PG_4                      = 52  ;
static const uint8_t P9A_PERV_RX_DATASM_SPARE_MODE_PG_5                      = 53  ;
static const uint8_t P9A_PERV_RX_DATASM_SPARE_MODE_PG_6                      = 54  ;
static const uint8_t P9A_PERV_RX_DATASM_SPARE_MODE_PG_7                      = 55  ;
static const uint8_t P9A_PERV_RX_DATASM_SPARE_MODE_PG_SERVO_CONFIG           = 56  ;
static const uint8_t P9A_PERV_RX_DATASM_SPARE_MODE_PG_SERVO_CONFIG_LEN       = 4   ;
static const uint8_t P9A_PERV_RX_DATASM_SPARE_MODE_PG_CTL_CLKDIST_PDWN       = 60  ;

static const uint8_t P9A_PERV_RX_DATASM_STAT10_EO_PG_RX_SCAN_N_16_23_RO_SIGNAL = 56  ;
static const uint8_t P9A_PERV_RX_DATASM_STAT10_EO_PG_RX_SCAN_N_16_23_RO_SIGNAL_LEN = 8   ;

static const uint8_t P9A_PERV_RX_DATASM_STAT11_EO_PG_RX_SCAN_N_0_15_RO_SIGNAL = 48  ;
static const uint8_t P9A_PERV_RX_DATASM_STAT11_EO_PG_RX_SCAN_N_0_15_RO_SIGNAL_LEN = 16  ;

static const uint8_t P9A_PERV_RX_DATASM_STAT1_EO_PG_RX_BER_COUNT_RO_SIGNAL   = 48  ;
static const uint8_t P9A_PERV_RX_DATASM_STAT1_EO_PG_RX_BER_COUNT_RO_SIGNAL_LEN = 11  ;
static const uint8_t P9A_PERV_RX_DATASM_STAT1_EO_PG_RX_BER_COUNT_SATURATED_RO_SIGNAL = 59  ;
static const uint8_t P9A_PERV_RX_DATASM_STAT1_EO_PG_RX_BER_COUNT_FROZEN_BY_ERR_CNT_RO_SIGNAL = 60  ;
static const uint8_t P9A_PERV_RX_DATASM_STAT1_EO_PG_RX_BER_COUNT_FROZEN_BY_TIMER_RO_SIGNAL = 61  ;
static const uint8_t P9A_PERV_RX_DATASM_STAT1_EO_PG_RX_BER_TIMER_SATURATED_RO_SIGNAL = 62  ;

static const uint8_t P9A_PERV_RX_DATASM_STAT2_EO_PG_RX_BER_TIMER_VALUE_0_15_RO_SIGNAL = 48  ;
static const uint8_t P9A_PERV_RX_DATASM_STAT2_EO_PG_RX_BER_TIMER_VALUE_0_15_RO_SIGNAL_LEN = 16  ;

static const uint8_t P9A_PERV_RX_DATASM_STAT3_EO_PG_RX_BER_TIMER_VALUE_16_31_RO_SIGNAL = 48  ;
static const uint8_t P9A_PERV_RX_DATASM_STAT3_EO_PG_RX_BER_TIMER_VALUE_16_31_RO_SIGNAL_LEN = 16  ;

static const uint8_t P9A_PERV_RX_DATASM_STAT4_EO_PG_RX_DATA_PIPE_0_15_RO_SIGNAL = 48  ;
static const uint8_t P9A_PERV_RX_DATASM_STAT4_EO_PG_RX_DATA_PIPE_0_15_RO_SIGNAL_LEN = 16  ;

static const uint8_t P9A_PERV_RX_DATASM_STAT5_EO_PG_RX_DATA_PIPE_16_31_RO_SIGNAL = 48  ;
static const uint8_t P9A_PERV_RX_DATASM_STAT5_EO_PG_RX_DATA_PIPE_16_31_RO_SIGNAL_LEN = 16  ;

static const uint8_t P9A_PERV_RX_DATASM_STAT6_EO_PG_RX_SERVO_STATUS_RO_SIGNAL = 48  ;
static const uint8_t P9A_PERV_RX_DATASM_STAT6_EO_PG_RX_SERVO_STATUS_RO_SIGNAL_LEN = 16  ;

static const uint8_t P9A_PERV_RX_DATASM_STAT7_EO_PG_RX_SERVO_CHG_CNT_RO_SIGNAL = 48  ;
static const uint8_t P9A_PERV_RX_DATASM_STAT7_EO_PG_RX_SERVO_CHG_CNT_RO_SIGNAL_LEN = 4   ;
static const uint8_t P9A_PERV_RX_DATASM_STAT7_EO_PG_RX_IREF_PARITY_CHK_RO_SIGNAL = 59  ;
static const uint8_t P9A_PERV_RX_DATASM_STAT7_EO_PG_RX_IREF_PARITY_CHK_RO_SIGNAL_LEN = 4   ;
static const uint8_t P9A_PERV_RX_DATASM_STAT7_EO_PG_RX_PRVCPT_CHANGE_DET_RO_SIGNAL = 63  ;

static const uint8_t P9A_PERV_RX_DATASM_STAT8_EO_PG_RX_SCAN_P_0_15_RO_SIGNAL = 48  ;
static const uint8_t P9A_PERV_RX_DATASM_STAT8_EO_PG_RX_SCAN_P_0_15_RO_SIGNAL_LEN = 16  ;

static const uint8_t P9A_PERV_RX_DATASM_STAT9_EO_PG_RX_SCAN_P_16_23_RO_SIGNAL = 48  ;
static const uint8_t P9A_PERV_RX_DATASM_STAT9_EO_PG_RX_SCAN_P_16_23_RO_SIGNAL_LEN = 9   ;

static const uint8_t P9A_PERV_RX_DATA_DAC_SPARE_MODE_PL_0                    = 48  ;
static const uint8_t P9A_PERV_RX_DATA_DAC_SPARE_MODE_PL_1                    = 49  ;
static const uint8_t P9A_PERV_RX_DATA_DAC_SPARE_MODE_PL_2                    = 50  ;
static const uint8_t P9A_PERV_RX_DATA_DAC_SPARE_MODE_PL_3                    = 51  ;
static const uint8_t P9A_PERV_RX_DATA_DAC_SPARE_MODE_PL_4                    = 52  ;
static const uint8_t P9A_PERV_RX_DATA_DAC_SPARE_MODE_PL_5                    = 53  ;
static const uint8_t P9A_PERV_RX_DATA_DAC_SPARE_MODE_PL_6                    = 54  ;
static const uint8_t P9A_PERV_RX_DATA_DAC_SPARE_MODE_PL_7                    = 55  ;
static const uint8_t P9A_PERV_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC           = 60  ;
static const uint8_t P9A_PERV_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN       = 4   ;

static const uint8_t P9A_PERV_RX_DATA_WORK_SPARE_MODE_PL_0                   = 48  ;
static const uint8_t P9A_PERV_RX_DATA_WORK_SPARE_MODE_PL_1                   = 49  ;
static const uint8_t P9A_PERV_RX_DATA_WORK_SPARE_MODE_PL_2                   = 50  ;
static const uint8_t P9A_PERV_RX_DATA_WORK_SPARE_MODE_PL_3                   = 51  ;
static const uint8_t P9A_PERV_RX_DATA_WORK_SPARE_MODE_PL_4                   = 52  ;
static const uint8_t P9A_PERV_RX_DATA_WORK_SPARE_MODE_PL_5                   = 53  ;
static const uint8_t P9A_PERV_RX_DATA_WORK_SPARE_MODE_PL_6                   = 54  ;
static const uint8_t P9A_PERV_RX_DATA_WORK_SPARE_MODE_PL_7                   = 55  ;

static const uint8_t P9A_PERV_RX_FIR1_ERROR_INJECT_PG_ERR_INJ                = 48  ;
static const uint8_t P9A_PERV_RX_FIR1_ERROR_INJECT_PG_ERR_INJ_LEN            = 15  ;

static const uint8_t P9A_PERV_RX_FIR1_MASK_PG_ERRS                           = 48  ;
static const uint8_t P9A_PERV_RX_FIR1_MASK_PG_ERRS_LEN                       = 15  ;

static const uint8_t P9A_PERV_RX_FIR1_PG_RX_PG_FIR_ERR_PG_REGS_RO_SIGNAL     = 48  ;
static const uint8_t P9A_PERV_RX_FIR1_PG_RX_PG_FIR_ERR_GCR_BUFF_RO_SIGNAL    = 49  ;
static const uint8_t P9A_PERV_RX_FIR1_PG_RX_PG_FIR_ERR_GCRS_LD_SM_RO_SIGNAL  = 50  ;
static const uint8_t P9A_PERV_RX_FIR1_PG_RX_PG_FIR_ERR_GCRS_UNLD_SM_RO_SIGNAL = 51  ;
static const uint8_t P9A_PERV_RX_FIR1_PG_RX_PG_FIR_ERR_GLBSM_REGS_RO_SIGNAL  = 52  ;
static const uint8_t P9A_PERV_RX_FIR1_PG_RX_PG_FIR_ERR_GLBSM_REGRW_RO_SIGNAL = 53  ;
static const uint8_t P9A_PERV_RX_FIR1_PG_RX_PG_FIR_ERR_DATASM_REGS_RO_SIGNAL = 54  ;
static const uint8_t P9A_PERV_RX_FIR1_PG_RX_PG_FIR_ERR_DATASM_REGRW_RO_SIGNAL = 55  ;
static const uint8_t P9A_PERV_RX_FIR1_PG_RX_PG_FIR_ERR_EYEOPT_SM_RO_SIGNAL   = 56  ;
static const uint8_t P9A_PERV_RX_FIR1_PG_RX_PG_FIR_ERR_BIST_MAIN_STATE_RO_SIGNAL = 57  ;
static const uint8_t P9A_PERV_RX_FIR1_PG_RX_PG_FIR_ERR_BIST_INIT_STATE_RO_SIGNAL = 58  ;
static const uint8_t P9A_PERV_RX_FIR1_PG_RX_PG_FIR_ERR_RX_SERVO_SM_RO_SIGNAL = 59  ;
static const uint8_t P9A_PERV_RX_FIR1_PG_RX_PG_FIR_ERR_WORK_REGS_RO_SIGNAL   = 60  ;
static const uint8_t P9A_PERV_RX_FIR1_PG_RX_PL_FIR_ERR_RO_SIGNAL             = 62  ;

static const uint8_t P9A_PERV_RX_FIR_ERROR_INJECT_PB_ERRS_INJ                = 48  ;
static const uint8_t P9A_PERV_RX_FIR_ERROR_INJECT_PB_ERRS_INJ_LEN            = 10  ;

static const uint8_t P9A_PERV_RX_FIR_ERROR_INJECT_PL_ERR_INJ                 = 48  ;
static const uint8_t P9A_PERV_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN             = 3   ;

static const uint8_t P9A_PERV_RX_FIR_MASK_PB_ERRS                            = 48  ;
static const uint8_t P9A_PERV_RX_FIR_MASK_PB_ERRS_LEN                        = 10  ;

static const uint8_t P9A_PERV_RX_FIR_MASK_PL_ERRS                            = 48  ;
static const uint8_t P9A_PERV_RX_FIR_MASK_PL_ERRS_LEN                        = 3   ;

static const uint8_t P9A_PERV_RX_FIR_PB_RX_PB_FIR_ERRS_RO_SIGNAL             = 48  ;
static const uint8_t P9A_PERV_RX_FIR_PB_RX_PB_FIR_ERRS_RO_SIGNAL_LEN         = 10  ;

static const uint8_t P9A_PERV_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL             = 48  ;
static const uint8_t P9A_PERV_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN         = 3   ;

static const uint8_t P9A_PERV_RX_FIR_RESET_PB_CLR_PAR_ERRS                   = 62  ;
static const uint8_t P9A_PERV_RX_FIR_RESET_PB_RESET                          = 63  ;

static const uint8_t P9A_PERV_RX_GLBSM_CNTL2_EO_PG_CNT_SINGLE_LANE_RECAL     = 49  ;
static const uint8_t P9A_PERV_RX_GLBSM_CNTL2_EO_PG_RECAL_LANE_TO_MONITOR     = 50  ;
static const uint8_t P9A_PERV_RX_GLBSM_CNTL2_EO_PG_RECAL_LANE_TO_MONITOR_LEN = 5   ;

static const uint8_t P9A_PERV_RX_GLBSM_CNTL3_EO_PG_MANUAL_RECAL_REQUEST      = 48  ;
static const uint8_t P9A_PERV_RX_GLBSM_CNTL3_EO_PG_MANUAL_RECAL_LANE         = 51  ;
static const uint8_t P9A_PERV_RX_GLBSM_CNTL3_EO_PG_MANUAL_RECAL_LANE_LEN     = 5   ;

static const uint8_t P9A_PERV_RX_GLBSM_CNTL4_EO_PG_RX_CLR_RECAL_CNT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_PERV_RX_GLBSM_CNTL4_EO_PG_RX_INT_RETURN_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_PERV_RX_GLBSM_CNTL4_EO_PG_RX_MANUAL_RECAL_ABORT_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_PERV_RX_GLBSM_CNTL4_EO_PG_RX_MANUAL_RECAL_CONTINUE_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_PERV_RX_GLBSM_CNTLX1_EO_PG_CLR_PAR_ERRS             = 62  ;
static const uint8_t P9A_PERV_RX_GLBSM_CNTLX1_EO_PG_FIR_RESET                = 63  ;

static const uint8_t P9A_PERV_RX_GLBSM_MODE1_EO_PG_RC_ENABLE_PU_EDGE_TRACK   = 48  ;

static const uint8_t P9A_PERV_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_PERV_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_PERV_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_PERV_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_PERV_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE                = 48  ;
static const uint8_t P9A_PERV_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL               = 49  ;
static const uint8_t P9A_PERV_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ               = 50  ;
static const uint8_t P9A_PERV_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT             = 51  ;
static const uint8_t P9A_PERV_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED           = 52  ;
static const uint8_t P9A_PERV_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE         = 53  ;
static const uint8_t P9A_PERV_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE        = 54  ;

static const uint8_t P9A_PERV_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL  = 48  ;
static const uint8_t P9A_PERV_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_PERV_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL  = 50  ;
static const uint8_t P9A_PERV_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_PERV_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_PERV_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_PERV_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_PERV_RX_GLBSM_SPARE_MODE_PG_0                       = 48  ;
static const uint8_t P9A_PERV_RX_GLBSM_SPARE_MODE_PG_1                       = 49  ;
static const uint8_t P9A_PERV_RX_GLBSM_SPARE_MODE_PG_2                       = 50  ;
static const uint8_t P9A_PERV_RX_GLBSM_SPARE_MODE_PG_3                       = 51  ;
static const uint8_t P9A_PERV_RX_GLBSM_SPARE_MODE_PG_4                       = 52  ;
static const uint8_t P9A_PERV_RX_GLBSM_SPARE_MODE_PG_5                       = 53  ;
static const uint8_t P9A_PERV_RX_GLBSM_SPARE_MODE_PG_6                       = 54  ;
static const uint8_t P9A_PERV_RX_GLBSM_SPARE_MODE_PG_7                       = 55  ;

static const uint8_t P9A_PERV_RX_GLBSM_STAT1_EO_PG_RX_EYE_OPT_STATE_RO_SIGNAL = 48  ;
static const uint8_t P9A_PERV_RX_GLBSM_STAT1_EO_PG_RX_EYE_OPT_STATE_RO_SIGNAL_LEN = 12  ;

static const uint8_t P9A_PERV_RX_GLBSM_STAT2_EO_PG_RX_RECAL_CNT_RO_SIGNAL    = 48  ;
static const uint8_t P9A_PERV_RX_GLBSM_STAT2_EO_PG_RX_RECAL_CNT_RO_SIGNAL_LEN = 16  ;

static const uint8_t P9A_PERV_RX_GLBSM_STAT3_EO_PG_RX_DACTEST_ISGT_RO_SIGNAL = 48  ;
static const uint8_t P9A_PERV_RX_GLBSM_STAT3_EO_PG_RX_DACTEST_ISLT_RO_SIGNAL = 49  ;
static const uint8_t P9A_PERV_RX_GLBSM_STAT3_EO_PG_RX_DACTEST_ISEQ_RO_SIGNAL = 50  ;
static const uint8_t P9A_PERV_RX_GLBSM_STAT3_EO_PG_RX_DACTEST_DIFF_RO_SIGNAL = 51  ;
static const uint8_t P9A_PERV_RX_GLBSM_STAT3_EO_PG_RX_DACTEST_DIFF_RO_SIGNAL_LEN = 9   ;

static const uint8_t P9A_PERV_RX_GLBSM_STAT4_EO_PG_RX_INT_REQ_RO_SIGNAL      = 48  ;
static const uint8_t P9A_PERV_RX_GLBSM_STAT4_EO_PG_RX_INT_REQ_RO_SIGNAL_LEN  = 16  ;

static const uint8_t P9A_PERV_RX_GLBSM_STAT5_EO_PG_RX_LANE_CURRENTLY_INITIALIZING_RO_SIGNAL = 48  ;
static const uint8_t P9A_PERV_RX_GLBSM_STAT5_EO_PG_RX_LANE_CURRENTLY_RECALIBRATING_RO_SIGNAL = 49  ;
static const uint8_t P9A_PERV_RX_GLBSM_STAT5_EO_PG_RX_CURRENT_RECAL_INIT_LANE_RO_SIGNAL = 50  ;
static const uint8_t P9A_PERV_RX_GLBSM_STAT5_EO_PG_RX_CURRENT_RECAL_INIT_LANE_RO_SIGNAL_LEN = 5   ;
static const uint8_t P9A_PERV_RX_GLBSM_STAT5_EO_PG_RX_MANUAL_RECAL_DONE_RO_SIGNAL = 55  ;

static const uint8_t P9A_PERV_RX_ID1_PG_BUS_ID                               = 48  ;
static const uint8_t P9A_PERV_RX_ID1_PG_BUS_ID_LEN                           = 6   ;

static const uint8_t P9A_PERV_RX_SPARE_MODE_PG_0                             = 48  ;
static const uint8_t P9A_PERV_RX_SPARE_MODE_PG_1                             = 49  ;
static const uint8_t P9A_PERV_RX_SPARE_MODE_PG_2                             = 50  ;
static const uint8_t P9A_PERV_RX_SPARE_MODE_PG_3                             = 51  ;
static const uint8_t P9A_PERV_RX_SPARE_MODE_PG_4                             = 52  ;

static const uint8_t P9A_PERV_RX_SPARE_MODE_PL_0                             = 48  ;
static const uint8_t P9A_PERV_RX_SPARE_MODE_PL_1                             = 49  ;
static const uint8_t P9A_PERV_RX_SPARE_MODE_PL_2                             = 50  ;
static const uint8_t P9A_PERV_RX_SPARE_MODE_PL_3                             = 51  ;
static const uint8_t P9A_PERV_RX_SPARE_MODE_PL_4                             = 52  ;
static const uint8_t P9A_PERV_RX_SPARE_MODE_PL_5                             = 53  ;
static const uint8_t P9A_PERV_RX_SPARE_MODE_PL_6                             = 54  ;
static const uint8_t P9A_PERV_RX_SPARE_MODE_PL_7                             = 55  ;

static const uint8_t P9A_PERV_RX_WORK_CNTL1_O_PL_REGS_IORESET                = 48  ;

static const uint8_t P9A_PERV_RX_WORK_STAT1_EO_PL_BIST_ERR_A                 = 61  ;
static const uint8_t P9A_PERV_RX_WORK_STAT1_EO_PL_BIST_ERR_B                 = 62  ;
static const uint8_t P9A_PERV_RX_WORK_STAT1_EO_PL_BIST_ERR_E                 = 63  ;

static const uint8_t P9A_PERV_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV             = 48  ;
static const uint8_t P9A_PERV_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV             = 49  ;
static const uint8_t P9A_PERV_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT            = 50  ;
static const uint8_t P9A_PERV_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT            = 51  ;
static const uint8_t P9A_PERV_RX_WORK_STAT2_EO_PL_A_AP                       = 52  ;
static const uint8_t P9A_PERV_RX_WORK_STAT2_EO_PL_A_AP_LEN                   = 8   ;

static const uint8_t P9A_PERV_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN            = 48  ;
static const uint8_t P9A_PERV_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN        = 6   ;
static const uint8_t P9A_PERV_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD             = 54  ;
static const uint8_t P9A_PERV_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN         = 6   ;

static const uint8_t P9A_PERV_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN             = 48  ;
static const uint8_t P9A_PERV_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN         = 6   ;
static const uint8_t P9A_PERV_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD              = 54  ;
static const uint8_t P9A_PERV_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN          = 6   ;

static const uint8_t P9A_PERV_SBE_LCL_DBG_EN                                 = 0   ;
static const uint8_t P9A_PERV_SBE_LCL_DBG_HALT_ON_XSTOP                      = 1   ;
static const uint8_t P9A_PERV_SBE_LCL_DBG_HALT_ON_TRIG                       = 2   ;
static const uint8_t P9A_PERV_SBE_LCL_DBG_RESERVED3                          = 3   ;
static const uint8_t P9A_PERV_SBE_LCL_DBG_EN_INTR_ADDR                       = 4   ;
static const uint8_t P9A_PERV_SBE_LCL_DBG_EN_TRACE_EXTRA                     = 5   ;
static const uint8_t P9A_PERV_SBE_LCL_DBG_EN_TRACE_STALL                     = 6   ;
static const uint8_t P9A_PERV_SBE_LCL_DBG_EN_WAIT_CYCLES                     = 7   ;
static const uint8_t P9A_PERV_SBE_LCL_DBG_EN_FULL_SPEED                      = 8   ;
static const uint8_t P9A_PERV_SBE_LCL_DBG_RESERVED9                          = 9   ;
static const uint8_t P9A_PERV_SBE_LCL_DBG_TRACE_MODE_SEL                     = 10  ;
static const uint8_t P9A_PERV_SBE_LCL_DBG_TRACE_MODE_SEL_LEN                 = 2   ;
static const uint8_t P9A_PERV_SBE_LCL_DBG_FIR_TRIGGER                        = 16  ;
static const uint8_t P9A_PERV_SBE_LCL_DBG_MIB_GPIO                           = 17  ;
static const uint8_t P9A_PERV_SBE_LCL_DBG_MIB_GPIO_LEN                       = 3   ;
static const uint8_t P9A_PERV_SBE_LCL_DBG_TRACE_DATA_SEL                     = 20  ;
static const uint8_t P9A_PERV_SBE_LCL_DBG_TRACE_DATA_SEL_LEN                 = 4   ;
static const uint8_t P9A_PERV_SBE_LCL_DBG_HALT_INPUT                         = 24  ;

static const uint8_t P9A_PERV_SBE_LCL_EIMR_START0                            = 0   ;
static const uint8_t P9A_PERV_SBE_LCL_EIMR_START1                            = 1   ;
static const uint8_t P9A_PERV_SBE_LCL_EIMR_INTR0                             = 2   ;
static const uint8_t P9A_PERV_SBE_LCL_EIMR_INTR1                             = 3   ;
static const uint8_t P9A_PERV_SBE_LCL_EIMR_DRTM_REQ                          = 4   ;
static const uint8_t P9A_PERV_SBE_LCL_EIMR_SBEFIFO_RESET                     = 5   ;
static const uint8_t P9A_PERV_SBE_LCL_EIMR_SBEFIFO_DATA                      = 6   ;
static const uint8_t P9A_PERV_SBE_LCL_EIMR_SPARE                             = 7   ;
static const uint8_t P9A_PERV_SBE_LCL_EIMR_TRIG                              = 8   ;
static const uint8_t P9A_PERV_SBE_LCL_EIMR_XSTOP                             = 9   ;

static const uint8_t P9A_PERV_SBE_LCL_EINR_START0                            = 0   ;
static const uint8_t P9A_PERV_SBE_LCL_EINR_START1                            = 1   ;
static const uint8_t P9A_PERV_SBE_LCL_EINR_INTR0                             = 2   ;
static const uint8_t P9A_PERV_SBE_LCL_EINR_INTR1                             = 3   ;
static const uint8_t P9A_PERV_SBE_LCL_EINR_DRTM_REQ                          = 4   ;
static const uint8_t P9A_PERV_SBE_LCL_EINR_SBEFIFO_RESET                     = 5   ;
static const uint8_t P9A_PERV_SBE_LCL_EINR_SBEFIFO_DATA                      = 6   ;
static const uint8_t P9A_PERV_SBE_LCL_EINR_SPARE                             = 7   ;
static const uint8_t P9A_PERV_SBE_LCL_EINR_TRIG                              = 8   ;
static const uint8_t P9A_PERV_SBE_LCL_EINR_XSTOP                             = 9   ;

static const uint8_t P9A_PERV_SBE_LCL_EIPR_START0                            = 0   ;
static const uint8_t P9A_PERV_SBE_LCL_EIPR_START1                            = 1   ;
static const uint8_t P9A_PERV_SBE_LCL_EIPR_INTR0                             = 2   ;
static const uint8_t P9A_PERV_SBE_LCL_EIPR_INTR1                             = 3   ;
static const uint8_t P9A_PERV_SBE_LCL_EIPR_DRTM_REQ                          = 4   ;
static const uint8_t P9A_PERV_SBE_LCL_EIPR_SBEFIFO_RESET                     = 5   ;
static const uint8_t P9A_PERV_SBE_LCL_EIPR_SBEFIFO_DATA                      = 6   ;
static const uint8_t P9A_PERV_SBE_LCL_EIPR_SPARE                             = 7   ;
static const uint8_t P9A_PERV_SBE_LCL_EIPR_TRIG                              = 8   ;
static const uint8_t P9A_PERV_SBE_LCL_EIPR_XSTOP                             = 9   ;

static const uint8_t P9A_PERV_SBE_LCL_EISR_START0                            = 0   ;
static const uint8_t P9A_PERV_SBE_LCL_EISR_START1                            = 1   ;
static const uint8_t P9A_PERV_SBE_LCL_EISR_INTR0                             = 2   ;
static const uint8_t P9A_PERV_SBE_LCL_EISR_INTR1                             = 3   ;
static const uint8_t P9A_PERV_SBE_LCL_EISR_DRTM_REQ                          = 4   ;
static const uint8_t P9A_PERV_SBE_LCL_EISR_SBEFIFO_RESET                     = 5   ;
static const uint8_t P9A_PERV_SBE_LCL_EISR_SBEFIFO_DATA                      = 6   ;
static const uint8_t P9A_PERV_SBE_LCL_EISR_SPARE                             = 7   ;
static const uint8_t P9A_PERV_SBE_LCL_EISR_TRIG                              = 8   ;
static const uint8_t P9A_PERV_SBE_LCL_EISR_XSTOP                             = 9   ;

static const uint8_t P9A_PERV_SBE_LCL_EISTR_INTERRUPT_STATUS                 = 0   ;
static const uint8_t P9A_PERV_SBE_LCL_EISTR_INTERRUPT_STATUS_LEN             = 10  ;

static const uint8_t P9A_PERV_SBE_LCL_EITR_START0                            = 0   ;
static const uint8_t P9A_PERV_SBE_LCL_EITR_START1                            = 1   ;
static const uint8_t P9A_PERV_SBE_LCL_EITR_INTR0                             = 2   ;
static const uint8_t P9A_PERV_SBE_LCL_EITR_INTR1                             = 3   ;
static const uint8_t P9A_PERV_SBE_LCL_EITR_DRTM_REQ                          = 4   ;
static const uint8_t P9A_PERV_SBE_LCL_EITR_SBEFIFO_RESET                     = 5   ;
static const uint8_t P9A_PERV_SBE_LCL_EITR_SBEFIFO_DATA                      = 6   ;
static const uint8_t P9A_PERV_SBE_LCL_EITR_SPARE                             = 7   ;
static const uint8_t P9A_PERV_SBE_LCL_EITR_TRIG                              = 8   ;
static const uint8_t P9A_PERV_SBE_LCL_EITR_XSTOP                             = 9   ;

static const uint8_t P9A_PERV_SBE_LCL_IVPR_IVPR                              = 0   ;
static const uint8_t P9A_PERV_SBE_LCL_IVPR_IVPR_LEN                          = 23  ;

static const uint8_t P9A_PERV_SBE_LCL_TBR_TIMEBASE                           = 0   ;
static const uint8_t P9A_PERV_SBE_LCL_TBR_TIMEBASE_LEN                       = 32  ;

static const uint8_t P9A_PERV_SBE_LCL_TSEL_FIT_SEL                           = 0   ;
static const uint8_t P9A_PERV_SBE_LCL_TSEL_FIT_SEL_LEN                       = 4   ;
static const uint8_t P9A_PERV_SBE_LCL_TSEL_WATCHDOG_SEL                      = 4   ;
static const uint8_t P9A_PERV_SBE_LCL_TSEL_WATCHDOG_SEL_LEN                  = 4   ;

static const uint8_t P9A_PERV_SB_CS_SECURE_DEBUG_MODE                        = 0   ;
static const uint8_t P9A_PERV_SB_CS_START_RESTART_VECTOR0                    = 12  ;
static const uint8_t P9A_PERV_SB_CS_START_RESTART_VECTOR1                    = 13  ;
static const uint8_t P9A_PERV_SB_CS_INTERRUPT_S0                             = 14  ;
static const uint8_t P9A_PERV_SB_CS_INTERRUPT_S1                             = 15  ;
static const uint8_t P9A_PERV_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM        = 16  ;
static const uint8_t P9A_PERV_SB_CS_SELECT_SECONDARY_SEEPROM                 = 17  ;
static const uint8_t P9A_PERV_SB_CS_DEBUG_BOLT_ON_CONTROL_BITS               = 25  ;
static const uint8_t P9A_PERV_SB_CS_DEBUG_BOLT_ON_CONTROL_BITS_LEN           = 7   ;

static const uint8_t P9A_PERV_1_SCAN32_SCAN32_REG                            = 0   ;
static const uint8_t P9A_PERV_1_SCAN32_SCAN32_REG_LEN                        = 32  ;

static const uint8_t P9A_PERV_1_SCAN64_SCAN64_REG                            = 0   ;
static const uint8_t P9A_PERV_1_SCAN64_SCAN64_REG_LEN                        = 64  ;

static const uint8_t P9A_PERV_1_SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG            = 0   ;
static const uint8_t P9A_PERV_1_SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG_LEN        = 32  ;

static const uint8_t P9A_PERV_1_SCAN_CAPTUREDR_LONG_SCAN_CAPTUREDR_LONG_REG  = 0   ;
static const uint8_t P9A_PERV_1_SCAN_CAPTUREDR_LONG_SCAN_CAPTUREDR_LONG_REG_LEN = 32  ;

static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_SYSTEM_FAST_INIT            = 0   ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_VITL                        = 3   ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_PERV                        = 4   ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_UNIT1                       = 5   ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_UNIT2                       = 6   ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_UNIT3                       = 7   ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_UNIT4                       = 8   ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_UNIT5                       = 9   ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_UNIT6                       = 10  ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_UNIT7                       = 11  ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_UNIT8                       = 12  ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_UNIT9                       = 13  ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_UNIT10                      = 14  ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_FUNC                        = 48  ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_CFG                         = 49  ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_CCFG_GPTR                   = 50  ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_REGF                        = 51  ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_LBIST                       = 52  ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_ABIST                       = 53  ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_REPR                        = 54  ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_TIME                        = 55  ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_BNDY                        = 56  ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_FARR                        = 57  ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_CMSK                        = 58  ;
static const uint8_t P9A_PERV_1_SCAN_REGION_TYPE_INEX                        = 59  ;

static const uint8_t P9A_PERV_1_SCAN_UPDATEDR_SCAN_UPDATEDR_REG              = 0   ;
static const uint8_t P9A_PERV_1_SCAN_UPDATEDR_SCAN_UPDATEDR_REG_LEN          = 32  ;

static const uint8_t P9A_PERV_1_SCAN_UPDATEDR_LONG_SCAN_UPDATEDR_LONG_REG    = 0   ;
static const uint8_t P9A_PERV_1_SCAN_UPDATEDR_LONG_SCAN_UPDATEDR_LONG_REG_LEN = 32  ;

static const uint8_t P9A_PERV_SCOM_MODE_PB_GCR_TEST                          = 0   ;
static const uint8_t P9A_PERV_SCOM_MODE_PB_ENABLE_GCR_OFL_BUFF               = 1   ;
static const uint8_t P9A_PERV_SCOM_MODE_PB_IORESET_HARD_BUS0                 = 2   ;
static const uint8_t P9A_PERV_SCOM_MODE_PB_MMIO_PG_REG_ACCESS                = 3   ;
static const uint8_t P9A_PERV_SCOM_MODE_PB_SPARES1                           = 4   ;
static const uint8_t P9A_PERV_SCOM_MODE_PB_SPARES1_LEN                       = 4   ;
static const uint8_t P9A_PERV_SCOM_MODE_PB_GCR_HANG_DET_SEL                  = 8   ;
static const uint8_t P9A_PERV_SCOM_MODE_PB_GCR_HANG_DET_SEL_LEN              = 3   ;
static const uint8_t P9A_PERV_SCOM_MODE_PB_GCR_BUFFER_ENABLED_RO_SIGNAL      = 11  ;
static const uint8_t P9A_PERV_SCOM_MODE_PB_GCR_HANG_ERROR_MASK               = 12  ;
static const uint8_t P9A_PERV_SCOM_MODE_PB_GCR_HANG_ERROR_INJ                = 13  ;
static const uint8_t P9A_PERV_SCOM_MODE_PB_PPE_GCR                           = 14  ;
static const uint8_t P9A_PERV_SCOM_MODE_PB_CHAN_FAIL_MASK                    = 15  ;
static const uint8_t P9A_PERV_SCOM_MODE_PB_CHAN_FAIL_MASK_LEN                = 8   ;
static const uint8_t P9A_PERV_SCOM_MODE_PB_SPARES2                           = 23  ;
static const uint8_t P9A_PERV_SCOM_MODE_PB_SPARES2_LEN                       = 8   ;

static const uint8_t P9A_PERV_SCOM_PPE_CNTL_IORESET                          = 0   ;
static const uint8_t P9A_PERV_SCOM_PPE_CNTL_PDWN                             = 1   ;
static const uint8_t P9A_PERV_SCOM_PPE_CNTL_INTERRUPT                        = 2   ;
static const uint8_t P9A_PERV_SCOM_PPE_CNTL_ARB_ECC_INJECT_ERR               = 3   ;
static const uint8_t P9A_PERV_SCOM_PPE_CNTL_SPARES                           = 4   ;
static const uint8_t P9A_PERV_SCOM_PPE_CNTL_SPARES_LEN                       = 12  ;

static const uint8_t P9A_PERV_SCOM_PPE_FLAGS_FIELD                           = 0   ;
static const uint8_t P9A_PERV_SCOM_PPE_FLAGS_FIELD_LEN                       = 16  ;

static const uint8_t P9A_PERV_SCOM_PPE_WORK_REG1_WORK1                       = 0   ;
static const uint8_t P9A_PERV_SCOM_PPE_WORK_REG1_WORK1_LEN                   = 32  ;

static const uint8_t P9A_PERV_SCOM_PPE_WORK_REG2_WORK2                       = 0   ;
static const uint8_t P9A_PERV_SCOM_PPE_WORK_REG2_WORK2_LEN                   = 32  ;

static const uint8_t P9A_PERV_SCRATCH_REGISTER_1_SR                          = 0   ;
static const uint8_t P9A_PERV_SCRATCH_REGISTER_1_SR_LEN                      = 32  ;

static const uint8_t P9A_PERV_SCRATCH_REGISTER_2_SR                          = 0   ;
static const uint8_t P9A_PERV_SCRATCH_REGISTER_2_SR_LEN                      = 32  ;

static const uint8_t P9A_PERV_SCRATCH_REGISTER_3_SR                          = 0   ;
static const uint8_t P9A_PERV_SCRATCH_REGISTER_3_SR_LEN                      = 32  ;

static const uint8_t P9A_PERV_SCRATCH_REGISTER_4_SR                          = 0   ;
static const uint8_t P9A_PERV_SCRATCH_REGISTER_4_SR_LEN                      = 32  ;

static const uint8_t P9A_PERV_SCRATCH_REGISTER_5_SR                          = 0   ;
static const uint8_t P9A_PERV_SCRATCH_REGISTER_5_SR_LEN                      = 32  ;

static const uint8_t P9A_PERV_SCRATCH_REGISTER_6_SR                          = 0   ;
static const uint8_t P9A_PERV_SCRATCH_REGISTER_6_SR_LEN                      = 32  ;

static const uint8_t P9A_PERV_SCRATCH_REGISTER_7_SR                          = 0   ;
static const uint8_t P9A_PERV_SCRATCH_REGISTER_7_SR_LEN                      = 32  ;

static const uint8_t P9A_PERV_SCRATCH_REGISTER_8_SR                          = 0   ;
static const uint8_t P9A_PERV_SCRATCH_REGISTER_8_SR_LEN                      = 32  ;

static const uint8_t P9A_PERV_SECURITY_SWITCH_REGISTER_SECURE_ACCESS         = 0   ;
static const uint8_t P9A_PERV_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY   = 1   ;
static const uint8_t P9A_PERV_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY = 2   ;
static const uint8_t P9A_PERV_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED = 3   ;
static const uint8_t P9A_PERV_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK   = 4   ;
static const uint8_t P9A_PERV_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS     = 5   ;
static const uint8_t P9A_PERV_SECURITY_SWITCH_REGISTER_SECURE_DEBUG          = 6   ;
static const uint8_t P9A_PERV_SECURITY_SWITCH_REGISTER_CMFSI_ACCESS_PROTCT   = 7   ;
static const uint8_t P9A_PERV_SECURITY_SWITCH_REGISTER_ABUS_LOCK             = 8   ;
static const uint8_t P9A_PERV_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK  = 9   ;
static const uint8_t P9A_PERV_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0        = 10  ;
static const uint8_t P9A_PERV_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1        = 11  ;
static const uint8_t P9A_PERV_SECURITY_SWITCH_REGISTER_I2CM_TPM_DECONFIG_PROTECT = 12  ;
static const uint8_t P9A_PERV_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0        = 13  ;
static const uint8_t P9A_PERV_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1        = 14  ;
static const uint8_t P9A_PERV_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE2        = 15  ;

static const uint8_t P9A_PERV_FSISHIFT_SHIFT_CONTROL_REGISTER_2_REGISTER     = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_SHIFT_CONTROL_REGISTER_2_REGISTER_LEN = 32  ;

static const uint8_t P9A_PERV_1_SKITTER_CLKSRC_REG_SKITTER0                  = 0   ;
static const uint8_t P9A_PERV_1_SKITTER_CLKSRC_REG_SKITTER0_LEN              = 3   ;
static const uint8_t P9A_PERV_1_SKITTER_CLKSRC_REG_SKITTER0_DELAY_SELECT     = 36  ;
static const uint8_t P9A_PERV_1_SKITTER_CLKSRC_REG_SKITTER0_DELAY_SELECT_LEN = 2   ;

static const uint8_t P9A_PERV_1_SKITTER_FORCE_REG_F_READ                     = 0   ;

static const uint8_t P9A_PERV_1_SKITTER_MODE_REG_HOLD_SAMPLE                 = 0   ;
static const uint8_t P9A_PERV_1_SKITTER_MODE_REG_DISABLE_STICKINESS          = 1   ;
static const uint8_t P9A_PERV_1_SKITTER_MODE_REG_UNUSED1                     = 2   ;
static const uint8_t P9A_PERV_1_SKITTER_MODE_REG_UNUSED1_LEN                 = 2   ;
static const uint8_t P9A_PERV_1_SKITTER_MODE_REG_HOLD_DBGTRIG_SEL            = 4   ;
static const uint8_t P9A_PERV_1_SKITTER_MODE_REG_HOLD_DBGTRIG_SEL_LEN        = 2   ;
static const uint8_t P9A_PERV_1_SKITTER_MODE_REG_RESET_TRIG_SEL              = 6   ;
static const uint8_t P9A_PERV_1_SKITTER_MODE_REG_RESET_TRIG_SEL_LEN          = 2   ;
static const uint8_t P9A_PERV_1_SKITTER_MODE_REG_SAMPLE_GUTS                 = 8   ;
static const uint8_t P9A_PERV_1_SKITTER_MODE_REG_SAMPLE_GUTS_LEN             = 2   ;
static const uint8_t P9A_PERV_1_SKITTER_MODE_REG_HOLD_SAMPLE_WITH_TRIGGER    = 44  ;
static const uint8_t P9A_PERV_1_SKITTER_MODE_REG_DATA_V_LT                   = 45  ;

static const uint8_t P9A_PERV_1_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK = 0   ;
static const uint8_t P9A_PERV_1_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN  = 1   ;
static const uint8_t P9A_PERV_1_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP  = 2   ;
static const uint8_t P9A_PERV_1_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK  = 3   ;
static const uint8_t P9A_PERV_1_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT       = 4   ;
static const uint8_t P9A_PERV_1_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO   = 5   ;
static const uint8_t P9A_PERV_1_SLAVE_CONFIG_REG_CFG_PM_DISABLE              = 6   ;
static const uint8_t P9A_PERV_1_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE          = 7   ;
static const uint8_t P9A_PERV_1_SLAVE_CONFIG_REG_CFG_MASK_PARITY_ERRS        = 8   ;
static const uint8_t P9A_PERV_1_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS        = 9   ;
static const uint8_t P9A_PERV_1_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS     = 10  ;
static const uint8_t P9A_PERV_1_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS         = 11  ;
static const uint8_t P9A_PERV_1_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS           = 12  ;
static const uint8_t P9A_PERV_1_SLAVE_CONFIG_REG_CFG_MASK_EDRAM_ERRS         = 13  ;

static const uint8_t P9A_PERV_SNS1LTH_SNS1_0_31                              = 0   ;
static const uint8_t P9A_PERV_SNS1LTH_SNS1_0_31_LEN                          = 32  ;

static const uint8_t P9A_PERV_SNS2LTH_SNS2_UNUSED_0_31                       = 0   ;
static const uint8_t P9A_PERV_SNS2LTH_SNS2_UNUSED_0_31_LEN                   = 32  ;

static const uint8_t P9A_PERV_SPARE_MODE_PB_0                                = 48  ;
static const uint8_t P9A_PERV_SPARE_MODE_PB_1                                = 49  ;
static const uint8_t P9A_PERV_SPARE_MODE_PB_2                                = 50  ;
static const uint8_t P9A_PERV_SPARE_MODE_PB_3                                = 51  ;
static const uint8_t P9A_PERV_SPARE_MODE_PB_4                                = 52  ;
static const uint8_t P9A_PERV_SPARE_MODE_PB_5                                = 53  ;
static const uint8_t P9A_PERV_SPARE_MODE_PB_6                                = 54  ;
static const uint8_t P9A_PERV_SPARE_MODE_PB_7                                = 55  ;

static const uint8_t P9A_PERV_1_SPATTN_IN0                                   = 0   ;
static const uint8_t P9A_PERV_1_SPATTN_IN1                                   = 1   ;
static const uint8_t P9A_PERV_1_SPATTN_IN2                                   = 2   ;
static const uint8_t P9A_PERV_1_SPATTN_IN3                                   = 3   ;
static const uint8_t P9A_PERV_1_SPATTN_IN4                                   = 4   ;
static const uint8_t P9A_PERV_1_SPATTN_IN5                                   = 5   ;
static const uint8_t P9A_PERV_1_SPATTN_IN6                                   = 6   ;
static const uint8_t P9A_PERV_1_SPATTN_IN7                                   = 7   ;
static const uint8_t P9A_PERV_1_SPATTN_IN8                                   = 8   ;
static const uint8_t P9A_PERV_1_SPATTN_IN9                                   = 9   ;

static const uint8_t P9A_PERV_1_SPA_MASK_IN                                  = 0   ;
static const uint8_t P9A_PERV_1_SPA_MASK_IN_LEN                              = 10  ;

static const uint8_t P9A_PERV_FSI2PIB_STATUS_ANY_ERROR                       = 0   ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_SYSTEM_CHECKSTOP                = 1   ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_SPECIAL_ATTENTION               = 2   ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_RECOVERABLE_ERROR               = 3   ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST     = 4   ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_PARITY_CHECK                    = 5   ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT      = 6   ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_PROTECTION_CHECK                = 7   ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_RESERVED_8                      = 8   ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_RESERVED_9                      = 9   ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_IDLE_INDICATION                 = 10  ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_PIB_ABORT                       = 11  ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_USE_OSC_OBSERVATION             = 12  ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_USE_OSC_OBSERVATION_LEN         = 4   ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_VDD_NEST_OBSERVE                = 16  ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_PIB_ERROR_CODE                  = 17  ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_PIB_ERROR_CODE_LEN              = 3   ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_OSCILLATOR                      = 20  ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_OSCILLATOR_LEN                  = 4   ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_PLLLOCK_0                       = 24  ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_PLLLOCK_1                       = 25  ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_PLLLOCK_2                       = 26  ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_PLLLOCK_3                       = 27  ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING     = 28  ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_INTERRUPT_ENABLED               = 29  ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION       = 30  ;
static const uint8_t P9A_PERV_FSI2PIB_STATUS_RESERVED_31                     = 31  ;

static const uint8_t P9A_PERV_FSISHIFT_STATUS_4                              = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_STATUS_4_LEN                          = 32  ;

static const uint8_t P9A_PERV_STATUS_REGISTER_ADDR_NVLD                      = 0   ;
static const uint8_t P9A_PERV_STATUS_REGISTER_WRITE_NVLD                     = 1   ;
static const uint8_t P9A_PERV_STATUS_REGISTER_READ_NVLD                      = 2   ;
static const uint8_t P9A_PERV_STATUS_REGISTER_INVLD_CMD_ERR                  = 3   ;
static const uint8_t P9A_PERV_STATUS_REGISTER_CORR_ERR                       = 4   ;
static const uint8_t P9A_PERV_STATUS_REGISTER_UNCORR_ERROR                   = 5   ;
static const uint8_t P9A_PERV_STATUS_REGISTER_DATA_REG_0_31                  = 6   ;
static const uint8_t P9A_PERV_STATUS_REGISTER_DATA_REG_0_31_LEN              = 32  ;
static const uint8_t P9A_PERV_STATUS_REGISTER_UNUSED_39_43                   = 39  ;
static const uint8_t P9A_PERV_STATUS_REGISTER_UNUSED_39_43_LEN               = 5   ;
static const uint8_t P9A_PERV_STATUS_REGISTER_CTRL_BUSY                      = 44  ;
static const uint8_t P9A_PERV_STATUS_REGISTER_DCOMP_ERR                      = 45  ;
static const uint8_t P9A_PERV_STATUS_REGISTER_INVLD_PRGM_ERR                 = 46  ;
static const uint8_t P9A_PERV_STATUS_REGISTER_UNUSED_47_51                   = 47  ;
static const uint8_t P9A_PERV_STATUS_REGISTER_UNUSED_47_51_LEN               = 5   ;
static const uint8_t P9A_PERV_STATUS_REGISTER_COMMAND_COMPLETE               = 52  ;
static const uint8_t P9A_PERV_STATUS_REGISTER_UNUSED_53                      = 53  ;
static const uint8_t P9A_PERV_STATUS_REGISTER_RDWR_OP_BUSY                   = 54  ;
static const uint8_t P9A_PERV_STATUS_REGISTER_DCOMP_ENGINE_BUSY              = 55  ;
static const uint8_t P9A_PERV_STATUS_REGISTER_RD_DATA_COUNT                  = 56  ;
static const uint8_t P9A_PERV_STATUS_REGISTER_RD_DATA_COUNT_LEN              = 8   ;

static const uint8_t P9A_PERV_FSII2C_STATUS_REGISTER_ENGINE_A_INVALID_CMD_0  = 0   ;
static const uint8_t P9A_PERV_FSII2C_STATUS_REGISTER_ENGINE_A_LBUS_PARITY_ERROR_0 = 1   ;
static const uint8_t P9A_PERV_FSII2C_STATUS_REGISTER_ENGINE_A_BE_OV_ERROR_0  = 2   ;
static const uint8_t P9A_PERV_FSII2C_STATUS_REGISTER_ENGINE_A_BE_ACC_ERROR_0 = 3   ;
static const uint8_t P9A_PERV_FSII2C_STATUS_REGISTER_ENGINE_A_ARBITRATION_LOST_ERROR_0 = 4   ;
static const uint8_t P9A_PERV_FSII2C_STATUS_REGISTER_ENGINE_A_NACK_RECEIVED_ERROR_0 = 5   ;
static const uint8_t P9A_PERV_FSII2C_STATUS_REGISTER_ENGINE_A_DATA_REQUEST_0 = 6   ;
static const uint8_t P9A_PERV_FSII2C_STATUS_REGISTER_ENGINE_A_STOP_ERROR_0   = 8   ;
static const uint8_t P9A_PERV_FSII2C_STATUS_REGISTER_ENGINE_A_BUSY           = 22  ;
static const uint8_t P9A_PERV_FSII2C_STATUS_REGISTER_ENGINE_A_SELF_BUSY_0    = 23  ;
static const uint8_t P9A_PERV_FSII2C_STATUS_REGISTER_ENGINE_A_FIFO_ENTRY_COUNT_0 = 28  ;
static const uint8_t P9A_PERV_FSII2C_STATUS_REGISTER_ENGINE_A_FIFO_ENTRY_COUNT_0_LEN = 4   ;

static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_ANY_ERROR            = 0   ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_CMD_PARITY_ERROR     = 1   ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_WR_DATA_PARITY_ERROR = 2   ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_RD_DATA_PARITY_ERROR = 3   ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_LCK_STATUS_PARITY_ERROR = 4   ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_FSM_PARITY_ERROR     = 5   ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_OPB_COMMAND_OVERRUN_ERROR = 7   ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_OPB_PARITY_ERROR     = 8   ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_OPB_PROTOCOL_ERROR   = 9   ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_OPB_TIMEOUT_BIT      = 10  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_OPB_ERRACK           = 11  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_INVALID_ADDRESS      = 12  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_PORT_IS_FENCED       = 13  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_READ_DATA_VALID      = 14  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_OPB_BUSY_FLAG        = 15  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_CM_ANY_MASTER_ERROR  = 16  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_CM_ANY_PORT_INTERRUPT = 17  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_CM_HOT_PLUG_EVENT    = 18  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_CM_CONTROL_REGISTER_PARITY_INTERRUPT = 19  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_CM_ANY_INTR_1_REMOTE_SLAVE_INTERRUPT = 20  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_CM_ANY_INTR_2_REMOTE_SLAVE_INTERRUPT = 21  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_M_ANY_MASTER_ERROR   = 24  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_M_ANY_PORT_INTERRUPT = 25  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_M_HOT_PLUG_EVENT     = 26  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_M_CONTROL_REGISTER_PARITY_INTERRUPT = 27  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_M_ANY_INTR_1_REMOTE_SLAVE_INTERRUPT = 28  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_M_ANY_INTR_2_REMOTE_SLAVE_INTERRUPT = 29  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_READ_DATA            = 32  ;
static const uint8_t P9A_PERV_PIB2OPB1_STAT_RDDAT_ERRES_READ_DATA_LEN        = 32  ;

static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_ANY_ERROR                     = 0   ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_CMD_PARITY_ERROR              = 1   ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_WR_DATA_PARITY_ERROR          = 2   ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_RD_DATA_PARITY_ERROR          = 3   ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_LCK_STATUS_PARITY_ERROR       = 4   ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_FSM_PARITY_ERROR              = 5   ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_OPB_COMMAND_OVERRUN_ERROR     = 7   ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_OPB_PARITY_ERROR              = 8   ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_OPB_PROTOCOL_ERROR            = 9   ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_OPB_TIMEOUT_BIT               = 10  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_OPB_ERRACK                    = 11  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_INVALID_ADDRESS               = 12  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_PORT_IS_FENCED                = 13  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_READ_DATA_VALID               = 14  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_OPB_BUSY_FLAG                 = 15  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_CM_ANY_MASTER_ERROR           = 16  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_CM_ANY_PORT_INTERRUPT         = 17  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_CM_HOT_PLUG_EVENT             = 18  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_CM_CONTROL_REGISTER_PARITY_INTERRUPT = 19  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_CM_ANY_INTR_1_REMOTE_SLAVE_INTERRUPT = 20  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_CM_ANY_INTR_2_REMOTE_SLAVE_INTERRUPT = 21  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_M_ANY_MASTER_ERROR            = 24  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_M_ANY_PORT_INTERRUPT          = 25  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_M_HOT_PLUG_EVENT              = 26  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_M_CONTROL_REGISTER_PARITY_INTERRUPT = 27  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_M_ANY_INTR_1_REMOTE_SLAVE_INTERRUPT = 28  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_M_ANY_INTR_2_REMOTE_SLAVE_INTERRUPT = 29  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_READ_DATA                     = 32  ;
static const uint8_t P9A_PERV_STAT_RDDAT_ERRES_READ_DATA_LEN                 = 32  ;

static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_ANY_ERROR            = 0   ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_CMD_PARITY_ERROR     = 1   ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_WR_DATA_PARITY_ERROR = 2   ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_RD_DATA_PARITY_ERROR = 3   ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_LCK_STATUS_PARITY_ERROR = 4   ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_FSM_PARITY_ERROR     = 5   ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_OPB_COMMAND_OVERRUN_ERROR = 7   ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_OPB_PARITY_ERROR     = 8   ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_OPB_PROTOCOL_ERROR   = 9   ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_OPB_TIMEOUT_BIT      = 10  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_OPB_ERRACK           = 11  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_INVALID_ADDRESS      = 12  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_PORT_IS_FENCED       = 13  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_READ_DATA_VALID      = 14  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_OPB_BUSY_FLAG        = 15  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_CM_ANY_MASTER_ERROR  = 16  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_CM_ANY_PORT_INTERRUPT = 17  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_CM_HOT_PLUG_EVENT    = 18  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_CM_CONTROL_REGISTER_PARITY_INTERRUPT = 19  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_CM_ANY_INTR_1_REMOTE_SLAVE_INTERRUPT = 20  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_CM_ANY_INTR_2_REMOTE_SLAVE_INTERRUPT = 21  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_M_ANY_MASTER_ERROR   = 24  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_M_ANY_PORT_INTERRUPT = 25  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_M_HOT_PLUG_EVENT     = 26  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_M_CONTROL_REGISTER_PARITY_INTERRUPT = 27  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_M_ANY_INTR_1_REMOTE_SLAVE_INTERRUPT = 28  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_M_ANY_INTR_2_REMOTE_SLAVE_INTERRUPT = 29  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_READ_DATA            = 32  ;
static const uint8_t P9A_PERV_PIB2OPB0_STAT_RDDAT_ERRES_READ_DATA_LEN        = 32  ;

static const uint8_t P9A_PERV_1_SUM_MASK_REG_SMASK_IN0                       = 0   ;
static const uint8_t P9A_PERV_1_SUM_MASK_REG_SMASK_IN1                       = 1   ;
static const uint8_t P9A_PERV_1_SUM_MASK_REG_SMASK_IN2                       = 2   ;
static const uint8_t P9A_PERV_1_SUM_MASK_REG_SMASK_IN3                       = 3   ;
static const uint8_t P9A_PERV_1_SUM_MASK_REG_SMASK_IN4                       = 4   ;

static const uint8_t P9A_PERV_1_SYNC_CONFIG_PULSE_DELAY                      = 0   ;
static const uint8_t P9A_PERV_1_SYNC_CONFIG_PULSE_DELAY_LEN                  = 4   ;
static const uint8_t P9A_PERV_1_SYNC_CONFIG_LISTEN_TO_PULSE_DIS              = 4   ;
static const uint8_t P9A_PERV_1_SYNC_CONFIG_PULSE_INPUT_SEL                  = 5   ;
static const uint8_t P9A_PERV_1_SYNC_CONFIG_USE_FOR_SCAN                     = 6   ;
static const uint8_t P9A_PERV_1_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED         = 7   ;
static const uint8_t P9A_PERV_1_SYNC_CONFIG_UNIT_REGION_CLKCMD_ENABLE        = 8   ;
static const uint8_t P9A_PERV_1_SYNC_CONFIG_DISABLE_PCB_ITR                  = 9   ;
static const uint8_t P9A_PERV_1_SYNC_CONFIG_ENABLE_VITL_ALIGN_CHECK          = 10  ;
static const uint8_t P9A_PERV_1_SYNC_CONFIG_PULSE_OUT_DIS                    = 11  ;
static const uint8_t P9A_PERV_1_SYNC_CONFIG_CHKSW_PCB_RESPONCE_DATA          = 12  ;
static const uint8_t P9A_PERV_1_SYNC_CONFIG_CHKSW_2TO1_CLK_GATING            = 13  ;
static const uint8_t P9A_PERV_1_SYNC_CONFIG_UNUSED1415                       = 14  ;
static const uint8_t P9A_PERV_1_SYNC_CONFIG_UNUSED1415_LEN                   = 2   ;
static const uint8_t P9A_PERV_1_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE       = 16  ;
static const uint8_t P9A_PERV_1_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_LEN   = 8   ;

static const uint8_t P9A_PERV_1_THERM_MODE_REG_DIS_CPM_BUBBLE_CORR           = 0   ;
static const uint8_t P9A_PERV_1_THERM_MODE_REG_FORCE_THRES_ACT               = 1   ;
static const uint8_t P9A_PERV_1_THERM_MODE_REG_THRES_TRIP_ENA                = 2   ;
static const uint8_t P9A_PERV_1_THERM_MODE_REG_THRES_TRIP_ENA_LEN            = 3   ;
static const uint8_t P9A_PERV_1_THERM_MODE_REG_DTS_SAMPLE_ENA                = 5   ;
static const uint8_t P9A_PERV_1_THERM_MODE_REG_SAMPLE_PULSE_CNT              = 6   ;
static const uint8_t P9A_PERV_1_THERM_MODE_REG_SAMPLE_PULSE_CNT_LEN          = 4   ;
static const uint8_t P9A_PERV_1_THERM_MODE_REG_THRES_ENA                     = 10  ;
static const uint8_t P9A_PERV_1_THERM_MODE_REG_THRES_ENA_LEN                 = 2   ;
static const uint8_t P9A_PERV_1_THERM_MODE_REG_DTS_TRIGGER                   = 12  ;
static const uint8_t P9A_PERV_1_THERM_MODE_REG_DTS_TRIGGER_SEL               = 13  ;
static const uint8_t P9A_PERV_1_THERM_MODE_REG_THRES_OVERFLOW_MASK           = 14  ;
static const uint8_t P9A_PERV_1_THERM_MODE_REG_UNUSED                        = 15  ;
static const uint8_t P9A_PERV_1_THERM_MODE_REG_DTS_READ_SEL                  = 16  ;
static const uint8_t P9A_PERV_1_THERM_MODE_REG_DTS_READ_SEL_LEN              = 4   ;
static const uint8_t P9A_PERV_1_THERM_MODE_REG_DTS_ENABLE_L1                 = 20  ;
static const uint8_t P9A_PERV_1_THERM_MODE_REG_DTS_ENABLE_L1_LEN             = 2   ;
static const uint8_t P9A_PERV_1_THERM_MODE_REG_THERM_CPM_ENABLE_L1           = 35  ;
static const uint8_t P9A_PERV_1_THERM_MODE_REG_THERM_CPM_ENABLE_L1_LEN       = 2   ;

static const uint8_t P9A_PERV_TIMEOUT_REG_REGISTER                           = 0   ;
static const uint8_t P9A_PERV_TIMEOUT_REG_REGISTER_LEN                       = 8   ;

static const uint8_t P9A_PERV_1_TIMESTAMP_COUNTER_READ_VALUE                 = 0   ;
static const uint8_t P9A_PERV_1_TIMESTAMP_COUNTER_READ_VALUE_LEN             = 44  ;
static const uint8_t P9A_PERV_1_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR          = 44  ;

static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE              = 0   ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT = 1   ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT_LEN = 3   ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE    = 4   ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE = 5   ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE    = 6   ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_MOVE_TO_TB_ON_2X_SYNC_ENABLE = 7   ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM        = 8   ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC             = 9   ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE         = 10  ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE_LEN     = 6   ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE = 16  ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_0X10_SPARE_17_18             = 17  ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_0X10_SPARE_17_18_LEN         = 2   ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_0X10_SPARE_19_23             = 19  ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_0X10_SPARE_19_23_LEN         = 5   ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_0X10_SPARE_24_25             = 24  ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_0X10_SPARE_24_25_LEN         = 2   ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET    = 26  ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_0X10_SPARE_27                = 27  ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE      = 28  ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_0X10_SPARE_29                = 29  ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_XSTOP_GATE                   = 30  ;
static const uint8_t P9A_PERV_TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE   = 31  ;

static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X00_DATA_PARITY          = 0   ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_M_PATH_0_PARITY           = 1   ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_M_PATH_1_PARITY           = 2   ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X01_DATA_PARITY          = 3   ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X02_DATA_PARITY          = 4   ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X03_DATA_PARITY          = 5   ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X04_DATA_PARITY          = 6   ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X05_DATA_PARITY          = 7   ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X06_DATA_PARITY          = 8   ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X07_DATA_PARITY          = 9   ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_S_PATH_0_PARITY           = 10  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X08_DATA_PARITY          = 11  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X09_DATA_PARITY          = 12  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X0A_DATA_PARITY          = 13  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK       = 14  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK       = 15  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK       = 16  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK         = 17  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_PSS_HAM                   = 18  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X0B_DATA_PARITY          = 19  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_S_PATH_1_PARITY           = 20  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK       = 21  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY = 22  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X0C_DATA_PARITY          = 23  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY = 24  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X17_0X18_0X21_0X22_DATA_PARITY = 25  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X1D_0X1E_0X1F_DATA_PARITY = 26  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X20_DATA_PARITY          = 27  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X23_DATA_PARITY          = 28  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X24_DATA_PARITY          = 29  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X29_DATA_PARITY          = 30  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X30_0X31_0X32_0X33_DATA_PARITY = 31  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X10_DATA_PARITY          = 32  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK         = 33  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY   = 34  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_I_PATH_TIME_PARITY        = 35  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_I_PATH_TIME_OVERFLOW      = 36  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY = 37  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_RX_TTYPE_0                = 38  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_RX_TTYPE_1                = 39  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_RX_TTYPE_2                = 40  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_RX_TTYPE_3                = 41  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_RX_TTYPE_4                = 42  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_RX_TTYPE_5                = 43  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID    = 44  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID   = 45  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID    = 46  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY     = 47  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY     = 48  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_0X27_DATA_PARITY          = 49  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_PIB_MASTER_RSP_INFO       = 50  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_PIB_MASTER_RSP_INFO_LEN   = 3   ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID          = 53  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY    = 54  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST        = 55  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_PIB_RESET_DURING_PIB_ACCESS = 56  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP            = 57  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_SPARE_58                  = 58  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_SPARE_59                  = 59  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_SPARE_60                  = 60  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_SPARE_61                  = 61  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT       = 62  ;
static const uint8_t P9A_PERV_TOD_ERROR_INJECT_REG_CORE_STEP                 = 63  ;

static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X00_DATA_PARITY            = 0   ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_M_PATH_0_PARITY             = 1   ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_M_PATH_1_PARITY             = 2   ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X01_DATA_PARITY            = 3   ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X02_DATA_PARITY            = 4   ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X03_DATA_PARITY            = 5   ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X04_DATA_PARITY            = 6   ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X05_DATA_PARITY            = 7   ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X06_DATA_PARITY            = 8   ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X07_DATA_PARITY            = 9   ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_S_PATH_0_PARITY             = 10  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X08_DATA_PARITY            = 11  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X09_DATA_PARITY            = 12  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X0A_DATA_PARITY            = 13  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK         = 14  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK         = 15  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK         = 16  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK           = 17  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_PSS_HAM                     = 18  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X0B_DATA_PARITY            = 19  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_S_PATH_1_PARITY             = 20  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK         = 21  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY = 22  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X0C_DATA_PARITY            = 23  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY = 24  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X17_0X18_0X21_0X22_DATA_PARITY = 25  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X1D_0X1E_0X1F_DATA_PARITY  = 26  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X20_DATA_PARITY            = 27  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X23_DATA_PARITY            = 28  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X24_DATA_PARITY            = 29  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X29_DATA_PARITY            = 30  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X30_0X31_0X32_0X33_DATA_PARITY = 31  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X10_DATA_PARITY            = 32  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK           = 33  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY     = 34  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_I_PATH_TIME_PARITY          = 35  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_I_PATH_TIME_OVERFLOW        = 36  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY = 37  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_RX_TTYPE_0                  = 38  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_RX_TTYPE_1                  = 39  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_RX_TTYPE_2                  = 40  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_RX_TTYPE_3                  = 41  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_RX_TTYPE_4                  = 42  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_RX_TTYPE_5                  = 43  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID      = 44  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID     = 45  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID      = 46  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY       = 47  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY       = 48  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_0X27_DATA_PARITY            = 49  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO         = 50  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_LEN     = 3   ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_RX_TTYPE_INVALID            = 53  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY      = 54  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST          = 55  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_PIB_RESET_DURING_PIB_ACCESS = 56  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_EXTERNAL_XSTOP              = 57  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_SPARE_58                    = 58  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_SPARE_59                    = 59  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_SPARE_60                    = 60  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_SPARE_61                    = 61  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT         = 62  ;
static const uint8_t P9A_PERV_TOD_ERROR_MASK_REG_SPARE_63                    = 63  ;

static const uint8_t P9A_PERV_TOD_ERROR_REG_0X00_DATA_PARITY                 = 0   ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_M_PATH_0_PARITY                  = 1   ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_M_PATH_1_PARITY                  = 2   ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X01_DATA_PARITY                 = 3   ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X02_DATA_PARITY                 = 4   ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X03_DATA_PARITY                 = 5   ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X04_DATA_PARITY                 = 6   ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X05_DATA_PARITY                 = 7   ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X06_DATA_PARITY                 = 8   ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X07_DATA_PARITY                 = 9   ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_S_PATH_0_PARITY                  = 10  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X08_DATA_PARITY                 = 11  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X09_DATA_PARITY                 = 12  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X0A_DATA_PARITY                 = 13  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_M_PATH_0_STEP_CHECK              = 14  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_M_PATH_1_STEP_CHECK              = 15  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_S_PATH_0_STEP_CHECK              = 16  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_I_PATH_STEP_CHECK                = 17  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_PSS_HAM                          = 18  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X0B_DATA_PARITY                 = 19  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_S_PATH_1_PARITY                  = 20  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_S_PATH_1_STEP_CHECK              = 21  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY   = 22  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X0C_DATA_PARITY                 = 23  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY = 24  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X17_0X18_0X21_0X22_DATA_PARITY  = 25  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X1D_0X1E_0X1F_DATA_PARITY       = 26  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X20_DATA_PARITY                 = 27  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X23_DATA_PARITY                 = 28  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X24_DATA_PARITY                 = 29  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X29_DATA_PARITY                 = 30  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X30_0X31_0X32_0X33_DATA_PARITY  = 31  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X10_DATA_PARITY                 = 32  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_I_PATH_SYNC_CHECK                = 33  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY          = 34  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_I_PATH_TIME_PARITY               = 35  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_I_PATH_TIME_OVERFLOW             = 36  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY = 37  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_RX_TTYPE_0                       = 38  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_RX_TTYPE_1                       = 39  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_RX_TTYPE_2                       = 40  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_RX_TTYPE_3                       = 41  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_RX_TTYPE_4                       = 42  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_RX_TTYPE_5                       = 43  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID           = 44  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID          = 45  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_PIB_SLAVE_READ_INVALID           = 46  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY            = 47  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY            = 48  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_0X27_DATA_PARITY                 = 49  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_PIB_MASTER_RSP_INFO              = 50  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_PIB_MASTER_RSP_INFO_LEN          = 3   ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_RX_TTYPE_INVALID                 = 53  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY           = 54  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_PIB_MASTER_REQUEST               = 55  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_PIB_RESET_DURING_PIB_ACCESS      = 56  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_EXTERNAL_XSTOP                   = 57  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_SPARE_58                         = 58  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_SPARE_59                         = 59  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_SPARE_60                         = 60  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_SPARE_61                         = 61  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_OSCSWITCH_INTERRUPT              = 62  ;
static const uint8_t P9A_PERV_TOD_ERROR_REG_SPARE_63                         = 63  ;

static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X00_DATA_PARITY         = 0   ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY          = 1   ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY          = 2   ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X01_DATA_PARITY         = 3   ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X02_DATA_PARITY         = 4   ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X03_DATA_PARITY         = 5   ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X04_DATA_PARITY         = 6   ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X05_DATA_PARITY         = 7   ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X06_DATA_PARITY         = 8   ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X07_DATA_PARITY         = 9   ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY          = 10  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X08_DATA_PARITY         = 11  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X09_DATA_PARITY         = 12  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X0A_DATA_PARITY         = 13  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK      = 14  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK      = 15  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK      = 16  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK        = 17  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK = 18  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X0B_DATA_PARITY         = 19  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY          = 20  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK      = 21  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY = 22  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X0C_DATA_PARITY         = 23  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY = 24  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X17_0X18_0X21_0X22_DATA_PARITY = 25  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X1D_0X1E_0X1F_DATA_PARITY = 26  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X20_DATA_PARITY         = 27  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X23_DATA_PARITY         = 28  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X24_DATA_PARITY         = 29  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X29_DATA_PARITY         = 30  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X30_0X31_0X32_0X33_DATA_PARITY = 31  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X10_DATA_PARITY         = 32  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK        = 33  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY  = 34  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_I_PATH_TIME_PARITY       = 35  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_I_PATH_TIME_OVERFLOW_CORE_INTERRUPT = 36  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY = 37  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_RX_TTYPE_0               = 38  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_RX_TTYPE_1               = 39  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_RX_TTYPE_2               = 40  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_RX_TTYPE_3               = 41  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_RX_TTYPE_4               = 42  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_RX_TTYPE_5               = 43  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID   = 44  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID  = 45  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID   = 46  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY    = 47  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY    = 48  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_0X27_DATA_PARITY         = 49  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO      = 50  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_LEN  = 3   ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID         = 53  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY   = 54  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST       = 55  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_PIB_ACCESS = 56  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP           = 57  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_SPARE_58                 = 58  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_SPARE_59                 = 59  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_SPARE_60                 = 60  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_SPARE_61                 = 61  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT      = 62  ;
static const uint8_t P9A_PERV_TOD_ERROR_ROUTING_REG_SPARE_63                 = 63  ;

static const uint8_t P9A_PERV_TOD_FSM_REG_I_PATH_STATE                       = 0   ;
static const uint8_t P9A_PERV_TOD_FSM_REG_I_PATH_STATE_LEN                   = 4   ;
static const uint8_t P9A_PERV_TOD_FSM_REG_IS_RUNNING                         = 4   ;
static const uint8_t P9A_PERV_TOD_FSM_REG_0X24_SPARE_05_07                   = 5   ;
static const uint8_t P9A_PERV_TOD_FSM_REG_0X24_SPARE_05_07_LEN               = 3   ;

static const uint8_t P9A_PERV_TOD_I_PATH_CTRL_REG_DELAY_DISABLE              = 0   ;
static const uint8_t P9A_PERV_TOD_I_PATH_CTRL_REG_DELAY_ADJUST_DISABLE       = 1   ;
static const uint8_t P9A_PERV_TOD_I_PATH_CTRL_REG_0X06_SPARE_02_04           = 2   ;
static const uint8_t P9A_PERV_TOD_I_PATH_CTRL_REG_0X06_SPARE_02_04_LEN       = 3   ;
static const uint8_t P9A_PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_STEP_SELECT     = 5   ;
static const uint8_t P9A_PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR = 6   ;
static const uint8_t P9A_PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN = 2   ;
static const uint8_t P9A_PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION   = 8   ;
static const uint8_t P9A_PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_LEN = 4   ;
static const uint8_t P9A_PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_CONSTANT_CPS_ENABLE = 12  ;
static const uint8_t P9A_PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_VALIDITY_COUNT  = 13  ;
static const uint8_t P9A_PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_VALIDITY_COUNT_LEN = 3   ;
static const uint8_t P9A_PERV_TOD_I_PATH_CTRL_REG_0X06_SPARE_16_21           = 16  ;
static const uint8_t P9A_PERV_TOD_I_PATH_CTRL_REG_0X06_SPARE_16_21_LEN       = 6   ;
static const uint8_t P9A_PERV_TOD_I_PATH_CTRL_REG_DELAY_ADJUST_VALUE         = 22  ;
static const uint8_t P9A_PERV_TOD_I_PATH_CTRL_REG_DELAY_ADJUST_VALUE_LEN     = 10  ;
static const uint8_t P9A_PERV_TOD_I_PATH_CTRL_REG_CPS                        = 32  ;
static const uint8_t P9A_PERV_TOD_I_PATH_CTRL_REG_CPS_LEN                    = 8   ;

static const uint8_t P9A_PERV_TOD_LOAD_TOD_MOD_REG_FSM_TRIGGER               = 0   ;
static const uint8_t P9A_PERV_TOD_LOAD_TOD_MOD_REG_FSM_SYNC_ENABLE           = 1   ;

static const uint8_t P9A_PERV_TOD_LOAD_TOD_REG_VALUE                         = 0   ;
static const uint8_t P9A_PERV_TOD_LOAD_TOD_REG_VALUE_LEN                     = 60  ;
static const uint8_t P9A_PERV_TOD_LOAD_TOD_REG_WOF                           = 60  ;
static const uint8_t P9A_PERV_TOD_LOAD_TOD_REG_WOF_LEN                       = 4   ;

static const uint8_t P9A_PERV_TOD_LOW_ORDER_STEP_REG_COUNTER_VALUE           = 0   ;
static const uint8_t P9A_PERV_TOD_LOW_ORDER_STEP_REG_COUNTER_VALUE_LEN       = 6   ;
static const uint8_t P9A_PERV_TOD_LOW_ORDER_STEP_REG_0X23_SPARE_06_07        = 6   ;
static const uint8_t P9A_PERV_TOD_LOW_ORDER_STEP_REG_0X23_SPARE_06_07_LEN    = 2   ;

static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_ENABLE = 0   ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_ENABLE = 1   ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_ENABLE = 2   ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_ENABLE = 3   ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_0X0B_SPARE_04_05            = 4   ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_0X0B_SPARE_04_05_LEN        = 2   ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_SYNC_DISABLE = 6   ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_SYNC_DISABLE = 7   ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE       = 8   ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE       = 9   ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE       = 10  ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE       = 11  ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_DISABLE  = 12  ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_TRIGGER  = 13  ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_ENABLE    = 14  ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_TRIGGER   = 15  ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_TRACE_ENABLE                = 16  ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_0X0B_SPARE_17               = 17  ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_TRACE_DATA_SELECT           = 18  ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_TRACE_DATA_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_ENABLE = 20  ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_ENABLE = 21  ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD = 22  ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST         = 23  ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE = 24  ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE_LEN = 9   ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_0X0B_SPARE_33_39            = 33  ;
static const uint8_t P9A_PERV_TOD_MISC_RESET_REG_0X0B_SPARE_33_39_LEN        = 7   ;

static const uint8_t P9A_PERV_TOD_MOVE_TOD_TO_TB_REG_TRIGGER                 = 0   ;

static const uint8_t P9A_PERV_TOD_M_PATH_0_STEP_STEER_REG_MODE               = 0   ;
static const uint8_t P9A_PERV_TOD_M_PATH_0_STEP_STEER_REG_RATE               = 1   ;
static const uint8_t P9A_PERV_TOD_M_PATH_0_STEP_STEER_REG_RATE_LEN           = 31  ;
static const uint8_t P9A_PERV_TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG  = 32  ;
static const uint8_t P9A_PERV_TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE = 33  ;
static const uint8_t P9A_PERV_TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE_LEN = 31  ;

static const uint8_t P9A_PERV_TOD_M_PATH_1_STEP_STEER_REG_MODE               = 0   ;
static const uint8_t P9A_PERV_TOD_M_PATH_1_STEP_STEER_REG_RATE               = 1   ;
static const uint8_t P9A_PERV_TOD_M_PATH_1_STEP_STEER_REG_RATE_LEN           = 31  ;
static const uint8_t P9A_PERV_TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG  = 32  ;
static const uint8_t P9A_PERV_TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE = 33  ;
static const uint8_t P9A_PERV_TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE_LEN = 31  ;

static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID            = 0   ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID            = 1   ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE       = 2   ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE       = 3   ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE = 4   ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT     = 5   ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT_LEN = 3   ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION = 8   ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION_LEN = 4   ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE = 12  ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT = 13  ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT_LEN = 3   ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION = 16  ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION_LEN = 4   ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE = 20  ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT = 21  ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT_LEN = 3   ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR = 24  ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN = 2   ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE   = 26  ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE   = 27  ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE        = 28  ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE        = 29  ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE = 30  ;
static const uint8_t P9A_PERV_TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE = 31  ;

static const uint8_t P9A_PERV_TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD   = 0   ;
static const uint8_t P9A_PERV_TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD_LEN = 8   ;
static const uint8_t P9A_PERV_TOD_M_PATH_STATUS_REG_0_CPS                    = 8   ;
static const uint8_t P9A_PERV_TOD_M_PATH_STATUS_REG_0_CPS_LEN                = 8   ;
static const uint8_t P9A_PERV_TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD   = 16  ;
static const uint8_t P9A_PERV_TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD_LEN = 8   ;
static const uint8_t P9A_PERV_TOD_M_PATH_STATUS_REG_1_CPS                    = 24  ;
static const uint8_t P9A_PERV_TOD_M_PATH_STATUS_REG_1_CPS_LEN                = 8   ;

static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_RX_SELECT              = 0   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_RX_SELECT_LEN          = 3   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_0X01_SPARE_03          = 3   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X0_TX_SELECT           = 4   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X0_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X1_TX_SELECT           = 6   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X1_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X2_TX_SELECT           = 8   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X2_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X3_TX_SELECT           = 10  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X3_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X4_TX_SELECT           = 12  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X4_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X5_TX_SELECT           = 14  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X5_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X6_TX_SELECT           = 16  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X6_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X7_TX_SELECT           = 18  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X7_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X0_TX_ENABLE           = 20  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X1_TX_ENABLE           = 21  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X2_TX_ENABLE           = 22  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X3_TX_ENABLE           = 23  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X4_TX_ENABLE           = 24  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X5_TX_ENABLE           = 25  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X6_TX_ENABLE           = 26  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_X7_TX_ENABLE           = 27  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_0X01_SPARE_28_31       = 28  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_0X01_SPARE_28_31_LEN   = 4   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_I_PATH_DELAY_VALUE     = 32  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_0_CTRL_REG_I_PATH_DELAY_VALUE_LEN = 8   ;

static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_RX_SELECT              = 0   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_RX_SELECT_LEN          = 3   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_0X02_SPARE_03          = 3   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X0_TX_SELECT           = 4   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X0_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X1_TX_SELECT           = 6   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X1_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X2_TX_SELECT           = 8   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X2_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X3_TX_SELECT           = 10  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X3_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X4_TX_SELECT           = 12  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X4_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X5_TX_SELECT           = 14  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X5_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X6_TX_SELECT           = 16  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X6_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X7_TX_SELECT           = 18  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X7_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X0_TX_ENABLE           = 20  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X1_TX_ENABLE           = 21  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X2_TX_ENABLE           = 22  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X3_TX_ENABLE           = 23  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X4_TX_ENABLE           = 24  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X5_TX_ENABLE           = 25  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X6_TX_ENABLE           = 26  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_X7_TX_ENABLE           = 27  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_0X02_SPARE_28_31       = 28  ;
static const uint8_t P9A_PERV_TOD_PRI_PORT_1_CTRL_REG_0X02_SPARE_28_31_LEN   = 4   ;

static const uint8_t P9A_PERV_TOD_PROBE_SELECT_REG_0_DATA                    = 0   ;
static const uint8_t P9A_PERV_TOD_PROBE_SELECT_REG_0_DATA_LEN                = 8   ;
static const uint8_t P9A_PERV_TOD_PROBE_SELECT_REG_1_DATA                    = 8   ;
static const uint8_t P9A_PERV_TOD_PROBE_SELECT_REG_1_DATA_LEN                = 8   ;
static const uint8_t P9A_PERV_TOD_PROBE_SELECT_REG_2_DATA                    = 16  ;
static const uint8_t P9A_PERV_TOD_PROBE_SELECT_REG_2_DATA_LEN                = 8   ;
static const uint8_t P9A_PERV_TOD_PROBE_SELECT_REG_3_DATA                    = 24  ;
static const uint8_t P9A_PERV_TOD_PROBE_SELECT_REG_3_DATA_LEN                = 8   ;

static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT         = 0   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_S_SELECT            = 1   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT     = 2   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE = 3   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE = 4   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE = 5   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE = 6   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE = 7   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT         = 8   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_S_SELECT            = 9   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT     = 10  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE = 11  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE = 12  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE = 13  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE = 14  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE = 15  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_SWITCH_SYNC_ERROR_DISABLE = 16  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE = 17  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH = 18  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_0X07_SPARE_19             = 19  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_0X07_SPARE_20             = 20  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM      = 21  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_0X07_SPARE_22_31          = 22  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_CTRL_REG_0X07_SPARE_22_31_LEN      = 10  ;

static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT          = 0   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT_LEN      = 3   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_0X08_SPARE_03           = 3   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID  = 4   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID  = 5   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID = 6   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID = 7   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID = 8   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID = 9   ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID = 10  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL              = 11  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT       = 12  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_PRI_M_S_SELECT          = 13  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT   = 14  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT       = 15  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT       = 16  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_SEC_M_S_SELECT          = 17  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT   = 18  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT       = 19  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_IS_RUNNING              = 20  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY              = 21  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY            = 22  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER        = 23  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER        = 24  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_IS_SLAVE                = 25  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT           = 26  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT           = 27  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH = 28  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH = 29  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_0X08_SPARE_30           = 30  ;
static const uint8_t P9A_PERV_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER   = 31  ;

static const uint8_t P9A_PERV_TOD_RX_TTYPE_CTRL_REG_DATA                     = 0   ;
static const uint8_t P9A_PERV_TOD_RX_TTYPE_CTRL_REG_DATA_LEN                 = 64  ;

static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_RX_SELECT              = 0   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_RX_SELECT_LEN          = 3   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_0X03_SPARE_03          = 3   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X0_TX_SELECT           = 4   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X0_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X1_TX_SELECT           = 6   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X1_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X2_TX_SELECT           = 8   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X2_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X3_TX_SELECT           = 10  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X3_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X4_TX_SELECT           = 12  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X4_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X5_TX_SELECT           = 14  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X5_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X6_TX_SELECT           = 16  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X6_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X7_TX_SELECT           = 18  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X7_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X0_TX_ENABLE           = 20  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X1_TX_ENABLE           = 21  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X2_TX_ENABLE           = 22  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X3_TX_ENABLE           = 23  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X4_TX_ENABLE           = 24  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X5_TX_ENABLE           = 25  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X6_TX_ENABLE           = 26  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_X7_TX_ENABLE           = 27  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_0X03_SPARE_28_31       = 28  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_0X03_SPARE_28_31_LEN   = 4   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_I_PATH_DELAY_VALUE     = 32  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_0_CTRL_REG_I_PATH_DELAY_VALUE_LEN = 8   ;

static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_RX_SELECT              = 0   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_RX_SELECT_LEN          = 3   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_0X04_SPARE_03          = 3   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X0_TX_SELECT           = 4   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X0_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X1_TX_SELECT           = 6   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X1_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X2_TX_SELECT           = 8   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X2_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X3_TX_SELECT           = 10  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X3_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X4_TX_SELECT           = 12  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X4_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X5_TX_SELECT           = 14  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X5_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X6_TX_SELECT           = 16  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X6_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X7_TX_SELECT           = 18  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X7_TX_SELECT_LEN       = 2   ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X0_TX_ENABLE           = 20  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X1_TX_ENABLE           = 21  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X2_TX_ENABLE           = 22  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X3_TX_ENABLE           = 23  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X4_TX_ENABLE           = 24  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X5_TX_ENABLE           = 25  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X6_TX_ENABLE           = 26  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_X7_TX_ENABLE           = 27  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_0X04_SPARE_28_31       = 28  ;
static const uint8_t P9A_PERV_TOD_SEC_PORT_1_CTRL_REG_0X04_SPARE_28_31_LEN   = 4   ;

static const uint8_t P9A_PERV_TOD_START_TOD_REG_FSM_TRIGGER                  = 0   ;
static const uint8_t P9A_PERV_TOD_START_TOD_REG_0X22_SPARE_01                = 1   ;
static const uint8_t P9A_PERV_TOD_START_TOD_REG_FSM_DATA02                   = 2   ;
static const uint8_t P9A_PERV_TOD_START_TOD_REG_0X22_SPARE_03_07             = 3   ;
static const uint8_t P9A_PERV_TOD_START_TOD_REG_0X22_SPARE_03_07_LEN         = 5   ;

static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_PRI_SELECT                 = 0   ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_0X05_SPARE_01              = 1   ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_M_CPS_ENABLE               = 2   ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_DISABLE        = 3   ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_SEC_SELECT                 = 4   ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_0X05_SPARE_05              = 5   ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR = 6   ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN = 2   ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION = 8   ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION_LEN = 4   ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE = 12  ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT = 13  ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT_LEN = 3   ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION = 16  ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION_LEN = 4   ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE = 20  ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT = 21  ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT_LEN = 3   ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_ERROR_DISABLE  = 24  ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_CHECK_M_CPS_DISABLE = 25  ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR = 26  ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR_LEN = 2   ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_CHECK_CPS_DEVIATION = 28  ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_CHECK_CPS_DEVIATION_LEN = 4   ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_MISS_COUNT_MAX = 32  ;
static const uint8_t P9A_PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_MISS_COUNT_MAX_LEN = 8   ;

static const uint8_t P9A_PERV_TOD_S_PATH_STATUS_REG_M_0_STEP_ALIGN_FSM_STATE = 0   ;
static const uint8_t P9A_PERV_TOD_S_PATH_STATUS_REG_M_0_STEP_ALIGN_FSM_STATE_LEN = 4   ;
static const uint8_t P9A_PERV_TOD_S_PATH_STATUS_REG_M_1_STEP_ALIGN_FSM_STATE = 4   ;
static const uint8_t P9A_PERV_TOD_S_PATH_STATUS_REG_M_1_STEP_ALIGN_FSM_STATE_LEN = 4   ;
static const uint8_t P9A_PERV_TOD_S_PATH_STATUS_REG_I_DELAY_ADJUST_RATIO     = 8   ;
static const uint8_t P9A_PERV_TOD_S_PATH_STATUS_REG_I_DELAY_ADJUST_RATIO_LEN = 5   ;
static const uint8_t P9A_PERV_TOD_S_PATH_STATUS_REG_0X0A_SPARE_13_15         = 13  ;
static const uint8_t P9A_PERV_TOD_S_PATH_STATUS_REG_0X0A_SPARE_13_15_LEN     = 3   ;
static const uint8_t P9A_PERV_TOD_S_PATH_STATUS_REG_0_CPS                    = 16  ;
static const uint8_t P9A_PERV_TOD_S_PATH_STATUS_REG_0_CPS_LEN                = 8   ;
static const uint8_t P9A_PERV_TOD_S_PATH_STATUS_REG_1_CPS                    = 24  ;
static const uint8_t P9A_PERV_TOD_S_PATH_STATUS_REG_1_CPS_LEN                = 8   ;
static const uint8_t P9A_PERV_TOD_S_PATH_STATUS_REG_0_REMOTE_SYNC_LATE_SYNC_COUNT = 32  ;
static const uint8_t P9A_PERV_TOD_S_PATH_STATUS_REG_0_REMOTE_SYNC_LATE_SYNC_COUNT_LEN = 8   ;
static const uint8_t P9A_PERV_TOD_S_PATH_STATUS_REG_1_REMOTE_SYNC_LATE_SYNC_COUNT = 40  ;
static const uint8_t P9A_PERV_TOD_S_PATH_STATUS_REG_1_REMOTE_SYNC_LATE_SYNC_COUNT_LEN = 8   ;

static const uint8_t P9A_PERV_TOD_TIMER_REG_VALUE                            = 0   ;
static const uint8_t P9A_PERV_TOD_TIMER_REG_VALUE_LEN                        = 60  ;
static const uint8_t P9A_PERV_TOD_TIMER_REG_ENABLE0                          = 60  ;
static const uint8_t P9A_PERV_TOD_TIMER_REG_ENABLE1                          = 61  ;
static const uint8_t P9A_PERV_TOD_TIMER_REG_STATUS0                          = 62  ;
static const uint8_t P9A_PERV_TOD_TIMER_REG_STATUS1                          = 63  ;

static const uint8_t P9A_PERV_TOD_TRACE_DATA_1_REG_SET                       = 0   ;
static const uint8_t P9A_PERV_TOD_TRACE_DATA_1_REG_SET_LEN                   = 64  ;

static const uint8_t P9A_PERV_TOD_TRACE_DATA_2_REG_SET                       = 0   ;
static const uint8_t P9A_PERV_TOD_TRACE_DATA_2_REG_SET_LEN                   = 64  ;

static const uint8_t P9A_PERV_TOD_TRACE_DATA_3_REG_SET                       = 0   ;
static const uint8_t P9A_PERV_TOD_TRACE_DATA_3_REG_SET_LEN                   = 64  ;

static const uint8_t P9A_PERV_TOD_TX_TTYPE_0_REG_TRIGGER                     = 0   ;

static const uint8_t P9A_PERV_TOD_TX_TTYPE_1_REG_TRIGGER                     = 0   ;

static const uint8_t P9A_PERV_TOD_TX_TTYPE_2_REG_TRIGGER                     = 0   ;

static const uint8_t P9A_PERV_TOD_TX_TTYPE_3_REG_TRIGGER                     = 0   ;

static const uint8_t P9A_PERV_TOD_TX_TTYPE_4_REG_TRIGGER                     = 0   ;

static const uint8_t P9A_PERV_TOD_TX_TTYPE_5_REG_TRIGGER                     = 0   ;

static const uint8_t P9A_PERV_TOD_TX_TTYPE_CTRL_REG_MOVE_TO_TB_CORE_ADDRESS  = 0   ;
static const uint8_t P9A_PERV_TOD_TX_TTYPE_CTRL_REG_MOVE_TO_TB_CORE_ADDRESS_LEN = 24  ;
static const uint8_t P9A_PERV_TOD_TX_TTYPE_CTRL_REG_MOVE_TO_TB_CORE_ID       = 24  ;
static const uint8_t P9A_PERV_TOD_TX_TTYPE_CTRL_REG_MOVE_TO_TB_CORE_ID_LEN   = 8   ;
static const uint8_t P9A_PERV_TOD_TX_TTYPE_CTRL_REG_4_SEND_MODE              = 32  ;
static const uint8_t P9A_PERV_TOD_TX_TTYPE_CTRL_REG_4_SEND_ENABLE            = 33  ;
static const uint8_t P9A_PERV_TOD_TX_TTYPE_CTRL_REG_0X27_SPARE_34            = 34  ;
static const uint8_t P9A_PERV_TOD_TX_TTYPE_CTRL_REG_MOVE_TO_TB_CORE_ADDRESS_ENABLE = 35  ;
static const uint8_t P9A_PERV_TOD_TX_TTYPE_CTRL_REG_0X27_SPARE_36            = 36  ;
static const uint8_t P9A_PERV_TOD_TX_TTYPE_CTRL_REG_PIB_FSM_STATE            = 37  ;
static const uint8_t P9A_PERV_TOD_TX_TTYPE_CTRL_REG_PIB_FSM_STATE_LEN        = 3   ;

static const uint8_t P9A_PERV_TOD_VALUE_REG_VALUE                            = 0   ;
static const uint8_t P9A_PERV_TOD_VALUE_REG_VALUE_LEN                        = 60  ;
static const uint8_t P9A_PERV_TOD_VALUE_REG_WOF_COUNTER                      = 60  ;
static const uint8_t P9A_PERV_TOD_VALUE_REG_WOF_COUNTER_LEN                  = 4   ;

static const uint8_t P9A_PERV_FSI2PIB_TRUE_MASK_REG                          = 0   ;
static const uint8_t P9A_PERV_FSI2PIB_TRUE_MASK_REG_LEN                      = 32  ;

static const uint8_t P9A_PERV_FSISHIFT_TRUE_MASK_REG                         = 0   ;
static const uint8_t P9A_PERV_FSISHIFT_TRUE_MASK_REG_LEN                     = 32  ;

static const uint8_t P9A_PERV_TXE_FDA_CRW_BAR_01B0_REG_BASE_ADDRESS_VALUE    = 32  ;
static const uint8_t P9A_PERV_TXE_FDA_CRW_BAR_01B0_REG_BASE_ADDRESS_VALUE_LEN = 20  ;

static const uint8_t P9A_PERV_TXE_FDA_CRW_GATHER_01B8_REG_EN                 = 0   ;
static const uint8_t P9A_PERV_TXE_FDA_CRW_GATHER_01B8_REG_NUM_VALUE          = 12  ;
static const uint8_t P9A_PERV_TXE_FDA_CRW_GATHER_01B8_REG_NUM_VALUE_LEN      = 3   ;
static const uint8_t P9A_PERV_TXE_FDA_CRW_GATHER_01B8_REG_TIMER_VALUE        = 17  ;
static const uint8_t P9A_PERV_TXE_FDA_CRW_GATHER_01B8_REG_TIMER_VALUE_LEN    = 6   ;

static const uint8_t P9A_PERV_TXE_FDA_M32_SAR_01A0_REG_START_ADDR_VALUE      = 32  ;
static const uint8_t P9A_PERV_TXE_FDA_M32_SAR_01A0_REG_START_ADDR_VALUE_LEN  = 16  ;

static const uint8_t P9A_PERV_TXE_FDA_PEOBRQ_UAR_01F0_REG_OB_UPPER_ADDRESS_VALUE = 0   ;
static const uint8_t P9A_PERV_TXE_FDA_PEOBRQ_UAR_01F0_REG_OB_UPPER_ADDRESS_VALUE_LEN = 8   ;

static const uint8_t P9A_PERV_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_PERV_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_PERV_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_PERV_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_PERV_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_PERV_TX_CNTL2_O_PL_IORESET                          = 48  ;

static const uint8_t P9A_PERV_TX_CNTL3_EO_PL_TDR_ENABLE                      = 48  ;

static const uint8_t P9A_PERV_TX_CTLSM_CNTL1_EO_PG_PSEG_PRE_EN               = 51  ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL1_EO_PG_PSEG_PRE_EN_LEN           = 5   ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL1_EO_PG_PSEG_PRE_SEL              = 56  ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL1_EO_PG_PSEG_PRE_SEL_LEN          = 5   ;

static const uint8_t P9A_PERV_TX_CTLSM_CNTL1_O_PG_PSEG_POST_EN               = 49  ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL1_O_PG_PSEG_POST_EN_LEN           = 7   ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL1_O_PG_PSEG_POST_SEL              = 56  ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL1_O_PG_PSEG_POST_SEL_LEN          = 7   ;

static const uint8_t P9A_PERV_TX_CTLSM_CNTL2_EO_PG_NSEG_PRE_EN               = 51  ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL2_EO_PG_NSEG_PRE_EN_LEN           = 5   ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL2_EO_PG_NSEG_PRE_SEL              = 56  ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL2_EO_PG_NSEG_PRE_SEL_LEN          = 5   ;

static const uint8_t P9A_PERV_TX_CTLSM_CNTL2_O_PG_NSEG_POST_EN               = 49  ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL2_O_PG_NSEG_POST_EN_LEN           = 7   ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL2_O_PG_NSEG_POST_SEL              = 56  ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL2_O_PG_NSEG_POST_SEL_LEN          = 7   ;

static const uint8_t P9A_PERV_TX_CTLSM_CNTL3_EO_PG_PSEG_MARGINPU_EN          = 48  ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL3_EO_PG_PSEG_MARGINPU_EN_LEN      = 8   ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL3_EO_PG_PSEG_MARGINPD_EN          = 56  ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL3_EO_PG_PSEG_MARGINPD_EN_LEN      = 8   ;

static const uint8_t P9A_PERV_TX_CTLSM_CNTL4_EO_PG_NSEG_MARGINPU_EN          = 48  ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL4_EO_PG_NSEG_MARGINPU_EN_LEN      = 8   ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL4_EO_PG_NSEG_MARGINPD_EN          = 56  ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL4_EO_PG_NSEG_MARGINPD_EN_LEN      = 8   ;

static const uint8_t P9A_PERV_TX_CTLSM_CNTL5_EO_PG_MARGINPU_SEL              = 48  ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL5_EO_PG_MARGINPU_SEL_LEN          = 8   ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL5_EO_PG_MARGINPD_SEL              = 56  ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL5_EO_PG_MARGINPD_SEL_LEN          = 8   ;

static const uint8_t P9A_PERV_TX_CTLSM_CNTL6_EO_PG_PSEG_MAIN_EN              = 51  ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL6_EO_PG_PSEG_MAIN_EN_LEN          = 7   ;

static const uint8_t P9A_PERV_TX_CTLSM_CNTL7_EO_PG_NSEG_MAIN_EN              = 51  ;
static const uint8_t P9A_PERV_TX_CTLSM_CNTL7_EO_PG_NSEG_MAIN_EN_LEN          = 7   ;

static const uint8_t P9A_PERV_TX_CTLSM_MODE1_EO_PG_SEG_TEST_MODE             = 50  ;
static const uint8_t P9A_PERV_TX_CTLSM_MODE1_EO_PG_SEG_TEST_MODE_LEN         = 8   ;
static const uint8_t P9A_PERV_TX_CTLSM_MODE1_EO_PG_FFE_BOOST_EN              = 59  ;
static const uint8_t P9A_PERV_TX_CTLSM_MODE1_EO_PG_SEG_TEST_LEAKAGE_CTRL     = 61  ;

static const uint8_t P9A_PERV_TX_CTLSM_SPARE_MODE_PG_CTL_SM_0                = 48  ;
static const uint8_t P9A_PERV_TX_CTLSM_SPARE_MODE_PG_CTL_SM_1                = 49  ;
static const uint8_t P9A_PERV_TX_CTLSM_SPARE_MODE_PG_CTL_SM_2                = 50  ;
static const uint8_t P9A_PERV_TX_CTLSM_SPARE_MODE_PG_CTL_SM_3                = 51  ;
static const uint8_t P9A_PERV_TX_CTLSM_SPARE_MODE_PG_CTL_SM_4                = 52  ;
static const uint8_t P9A_PERV_TX_CTLSM_SPARE_MODE_PG_CTL_SM_5                = 53  ;
static const uint8_t P9A_PERV_TX_CTLSM_SPARE_MODE_PG_CTL_SM_6                = 54  ;
static const uint8_t P9A_PERV_TX_CTLSM_SPARE_MODE_PG_CTL_SM_7                = 55  ;

static const uint8_t P9A_PERV_TX_CTLSM_STAT1_EO_PG_TX_BIST_DONE_RO_SIGNAL    = 50  ;

static const uint8_t P9A_PERV_TX_CTL_CNTL10_EO_PG_TDR_PULSE_WIDTH            = 48  ;
static const uint8_t P9A_PERV_TX_CTL_CNTL10_EO_PG_TDR_PULSE_WIDTH_LEN        = 8   ;

static const uint8_t P9A_PERV_TX_CTL_CNTL2_EO_PG_ERR_INJ_A_FINE_SEL          = 48  ;
static const uint8_t P9A_PERV_TX_CTL_CNTL2_EO_PG_ERR_INJ_A_FINE_SEL_LEN      = 3   ;
static const uint8_t P9A_PERV_TX_CTL_CNTL2_EO_PG_ERR_INJ_A_COARSE_SEL        = 51  ;
static const uint8_t P9A_PERV_TX_CTL_CNTL2_EO_PG_ERR_INJ_A_COARSE_SEL_LEN    = 4   ;
static const uint8_t P9A_PERV_TX_CTL_CNTL2_EO_PG_ERR_INJ_A_BER_SEL           = 55  ;
static const uint8_t P9A_PERV_TX_CTL_CNTL2_EO_PG_ERR_INJ_A_BER_SEL_LEN       = 6   ;
static const uint8_t P9A_PERV_TX_CTL_CNTL2_EO_PG_ERR_INJ_ENABLE              = 61  ;
static const uint8_t P9A_PERV_TX_CTL_CNTL2_EO_PG_ERR_INJ_CLOCK_ENABLE        = 62  ;

static const uint8_t P9A_PERV_TX_CTL_CNTL3_EO_PG_ERR_INJ_B_FINE_SEL          = 48  ;
static const uint8_t P9A_PERV_TX_CTL_CNTL3_EO_PG_ERR_INJ_B_FINE_SEL_LEN      = 3   ;
static const uint8_t P9A_PERV_TX_CTL_CNTL3_EO_PG_ERR_INJ_B_COARSE_SEL        = 51  ;
static const uint8_t P9A_PERV_TX_CTL_CNTL3_EO_PG_ERR_INJ_B_COARSE_SEL_LEN    = 4   ;
static const uint8_t P9A_PERV_TX_CTL_CNTL3_EO_PG_ERR_INJ_B_BER_SEL           = 55  ;
static const uint8_t P9A_PERV_TX_CTL_CNTL3_EO_PG_ERR_INJ_B_BER_SEL_LEN       = 6   ;

static const uint8_t P9A_PERV_TX_CTL_CNTL8_EO_PG_TDR_DAC_CNTL                = 48  ;
static const uint8_t P9A_PERV_TX_CTL_CNTL8_EO_PG_TDR_DAC_CNTL_LEN            = 8   ;
static const uint8_t P9A_PERV_TX_CTL_CNTL8_EO_PG_TDR_PHASE_SEL               = 57  ;

static const uint8_t P9A_PERV_TX_CTL_CNTL9_EO_PG_TDR_PULSE_OFFSET            = 48  ;
static const uint8_t P9A_PERV_TX_CTL_CNTL9_EO_PG_TDR_PULSE_OFFSET_LEN        = 14  ;

static const uint8_t P9A_PERV_TX_CTL_CNTLG1_EO_PG_DRV_DATA_PATTERN_GCRMSG    = 50  ;
static const uint8_t P9A_PERV_TX_CTL_CNTLG1_EO_PG_DRV_DATA_PATTERN_GCRMSG_LEN = 4   ;

static const uint8_t P9A_PERV_TX_CTL_MODE1_EO_PG_CLKDIST_PDWN                = 48  ;
static const uint8_t P9A_PERV_TX_CTL_MODE1_EO_PG_CLKDIST_PDWN_LEN            = 3   ;
static const uint8_t P9A_PERV_TX_CTL_MODE1_EO_PG_BIST_EN                     = 51  ;
static const uint8_t P9A_PERV_TX_CTL_MODE1_EO_PG_EXBIST_MODE                 = 52  ;

static const uint8_t P9A_PERV_TX_FIR_ERROR_INJECT_PG_ERR_INJ                 = 48  ;
static const uint8_t P9A_PERV_TX_FIR_ERROR_INJECT_PG_ERR_INJ_LEN             = 5   ;

static const uint8_t P9A_PERV_TX_FIR_ERROR_INJECT_PL_ERR_INJ                 = 48  ;

static const uint8_t P9A_PERV_TX_FIR_MASK_PG_ERRS                            = 48  ;
static const uint8_t P9A_PERV_TX_FIR_MASK_PG_ERRS_LEN                        = 5   ;
static const uint8_t P9A_PERV_TX_FIR_MASK_PG_PL_ERR                          = 63  ;

static const uint8_t P9A_PERV_TX_FIR_MASK_PL_ERRS                            = 48  ;

static const uint8_t P9A_PERV_TX_FIR_PG_TX_PG_FIR_ERR_TX_SM_REGS_RO_SIGNAL   = 48  ;
static const uint8_t P9A_PERV_TX_FIR_PG_TX_PG_FIR_ERR_GCR_BUFF_RO_SIGNAL     = 49  ;
static const uint8_t P9A_PERV_TX_FIR_PG_TX_PG_FIR_ERR_GCRS_LD_SM_RO_SIGNAL   = 50  ;
static const uint8_t P9A_PERV_TX_FIR_PG_TX_PG_FIR_ERR_GCRS_UNLD_SM_RO_SIGNAL = 51  ;
static const uint8_t P9A_PERV_TX_FIR_PG_TX_PG_FIR_ERR_CTL_REGS_RO_SIGNAL     = 52  ;
static const uint8_t P9A_PERV_TX_FIR_PG_TX_PL_FIR_ERR_RO_SIGNAL              = 63  ;

static const uint8_t P9A_PERV_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL             = 48  ;

static const uint8_t P9A_PERV_TX_FIR_RESET_PG_CLR_PAR_ERRS                   = 62  ;
static const uint8_t P9A_PERV_TX_FIR_RESET_PG_RESET                          = 63  ;

static const uint8_t P9A_PERV_TX_ID1_PG_BUS_ID                               = 48  ;
static const uint8_t P9A_PERV_TX_ID1_PG_BUS_ID_LEN                           = 6   ;

static const uint8_t P9A_PERV_TX_IMPCAL2_PB_TX_ZCAL_ANS_NOT_FOUND_ERROR_RO_SIGNAL = 49  ;
static const uint8_t P9A_PERV_TX_IMPCAL2_PB_TX_ZCAL_ANS_RANGE_ERROR_RO_SIGNAL = 50  ;
static const uint8_t P9A_PERV_TX_IMPCAL2_PB_TX_ZCAL_TEST_ENABLE_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_PERV_TX_IMPCAL2_PB_TX_ZCAL_TEST_STATUS_RO_SIGNAL    = 54  ;
static const uint8_t P9A_PERV_TX_IMPCAL2_PB_TX_ZCAL_TEST_DONE_RO_SIGNAL      = 55  ;

static const uint8_t P9A_PERV_TX_IMPCAL_NVAL_PB_ZCAL_N                       = 48  ;
static const uint8_t P9A_PERV_TX_IMPCAL_NVAL_PB_ZCAL_N_LEN                   = 9   ;

static const uint8_t P9A_PERV_TX_IMPCAL_PB_TX_ZCAL_REQ_WO_PULSE_SLOW_SIGNAL  = 49  ;
static const uint8_t P9A_PERV_TX_IMPCAL_PB_TX_ZCAL_DONE_RO_SIGNAL            = 50  ;
static const uint8_t P9A_PERV_TX_IMPCAL_PB_TX_ZCAL_ERROR_RO_SIGNAL           = 51  ;
static const uint8_t P9A_PERV_TX_IMPCAL_PB_TX_ZCAL_BUSY_RO_SIGNAL            = 52  ;
static const uint8_t P9A_PERV_TX_IMPCAL_PB_TX_ZCAL_FORCE_SAMPLE_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_PERV_TX_IMPCAL_PB_TX_ZCAL_CMP_OUT_RO_SIGNAL         = 54  ;
static const uint8_t P9A_PERV_TX_IMPCAL_PB_TX_ZCAL_SAMPLE_CNT_RO_SIGNAL      = 55  ;
static const uint8_t P9A_PERV_TX_IMPCAL_PB_TX_ZCAL_SAMPLE_CNT_RO_SIGNAL_LEN  = 9   ;

static const uint8_t P9A_PERV_TX_IMPCAL_PVAL_PB_ZCAL_P                       = 48  ;
static const uint8_t P9A_PERV_TX_IMPCAL_PVAL_PB_ZCAL_P_LEN                   = 9   ;

static const uint8_t P9A_PERV_TX_IMPCAL_P_4X_PB_ZCAL                         = 48  ;
static const uint8_t P9A_PERV_TX_IMPCAL_P_4X_PB_ZCAL_LEN                     = 5   ;

static const uint8_t P9A_PERV_TX_IMPCAL_SWO1_PB_ZCAL_SWO_EN                  = 48  ;
static const uint8_t P9A_PERV_TX_IMPCAL_SWO1_PB_ZCAL_SWO_CAL_SEGS            = 49  ;
static const uint8_t P9A_PERV_TX_IMPCAL_SWO1_PB_ZCAL_SWO_CMP_INV             = 50  ;
static const uint8_t P9A_PERV_TX_IMPCAL_SWO1_PB_ZCAL_SWO_CMP_OFFSET          = 51  ;
static const uint8_t P9A_PERV_TX_IMPCAL_SWO1_PB_ZCAL_SWO_CMP_RESET           = 52  ;
static const uint8_t P9A_PERV_TX_IMPCAL_SWO1_PB_ZCAL_SWO_POWERDOWN           = 53  ;
static const uint8_t P9A_PERV_TX_IMPCAL_SWO1_PB_ZCAL_SWO_TCOIL               = 54  ;
static const uint8_t P9A_PERV_TX_IMPCAL_SWO1_PB_ZCAL_RANGE_CHECK             = 55  ;
static const uint8_t P9A_PERV_TX_IMPCAL_SWO1_PB_ZCAL_CYA_DATA_INV            = 56  ;
static const uint8_t P9A_PERV_TX_IMPCAL_SWO1_PB_ZCAL_TEST_OVR_2R             = 57  ;
static const uint8_t P9A_PERV_TX_IMPCAL_SWO1_PB_ZCAL_TEST_OVR_1R             = 58  ;
static const uint8_t P9A_PERV_TX_IMPCAL_SWO1_PB_ZCAL_TEST_OVR_4X_SEG         = 59  ;
static const uint8_t P9A_PERV_TX_IMPCAL_SWO1_PB_ZCAL_TEST_CLK_DIV            = 60  ;

static const uint8_t P9A_PERV_TX_IMPCAL_SWO2_PB_ZCAL_SM_MIN_VAL              = 48  ;
static const uint8_t P9A_PERV_TX_IMPCAL_SWO2_PB_ZCAL_SM_MIN_VAL_LEN          = 7   ;
static const uint8_t P9A_PERV_TX_IMPCAL_SWO2_PB_ZCAL_SM_MAX_VAL              = 55  ;
static const uint8_t P9A_PERV_TX_IMPCAL_SWO2_PB_ZCAL_SM_MAX_VAL_LEN          = 7   ;

static const uint8_t P9A_PERV_TX_MODE1_PL_LANE_PDWN                          = 48  ;
static const uint8_t P9A_PERV_TX_MODE1_PL_LANE_INVERT                        = 49  ;
static const uint8_t P9A_PERV_TX_MODE1_PL_LANE_QUIESCE                       = 50  ;
static const uint8_t P9A_PERV_TX_MODE1_PL_LANE_QUIESCE_LEN                   = 2   ;
static const uint8_t P9A_PERV_TX_MODE1_PL_PSAVE_REQ_DIS                      = 54  ;
static const uint8_t P9A_PERV_TX_MODE1_PL_ERR_INJ_A_ENABLE                   = 55  ;
static const uint8_t P9A_PERV_TX_MODE1_PL_ERR_INJ_B_ENABLE                   = 56  ;
static const uint8_t P9A_PERV_TX_MODE1_PL_SPARE_MODE_0                       = 60  ;
static const uint8_t P9A_PERV_TX_MODE1_PL_SPARE_MODE_1                       = 61  ;
static const uint8_t P9A_PERV_TX_MODE1_PL_SPARE_MODE_2                       = 62  ;
static const uint8_t P9A_PERV_TX_MODE1_PL_SPARE_MODE_3                       = 63  ;

static const uint8_t P9A_PERV_TX_MODE2_PL_FIFO_L2U_DLY                       = 48  ;
static const uint8_t P9A_PERV_TX_MODE2_PL_FIFO_L2U_DLY_LEN                   = 3   ;
static const uint8_t P9A_PERV_TX_MODE2_PL_UNLOAD_CLK_DISABLE                 = 56  ;
static const uint8_t P9A_PERV_TX_MODE2_PL_RXCAL                              = 57  ;
static const uint8_t P9A_PERV_TX_MODE2_PL_UNLOAD_SEL                         = 58  ;
static const uint8_t P9A_PERV_TX_MODE2_PL_UNLOAD_SEL_LEN                     = 3   ;

static const uint8_t P9A_PERV_TX_SPARE_MODE_PG_0                             = 48  ;
static const uint8_t P9A_PERV_TX_SPARE_MODE_PG_1                             = 49  ;
static const uint8_t P9A_PERV_TX_SPARE_MODE_PG_2                             = 50  ;
static const uint8_t P9A_PERV_TX_SPARE_MODE_PG_3                             = 51  ;
static const uint8_t P9A_PERV_TX_SPARE_MODE_PG_4                             = 52  ;
static const uint8_t P9A_PERV_TX_SPARE_MODE_PG_5                             = 53  ;
static const uint8_t P9A_PERV_TX_SPARE_MODE_PG_6                             = 54  ;
static const uint8_t P9A_PERV_TX_SPARE_MODE_PG_7                             = 55  ;
static const uint8_t P9A_PERV_TX_SPARE_MODE_PG_8_9                           = 56  ;
static const uint8_t P9A_PERV_TX_SPARE_MODE_PG_8_9_LEN                       = 2   ;

static const uint8_t P9A_PERV_TX_STAT1_PL_LANE_BIST_ERR                      = 48  ;
static const uint8_t P9A_PERV_TX_STAT1_PL_LANE_BIST_ACTVITY_DET              = 49  ;
static const uint8_t P9A_PERV_TX_STAT1_PL_SEG_TEST_STATUS                    = 50  ;
static const uint8_t P9A_PERV_TX_STAT1_PL_SEG_TEST_STATUS_LEN                = 2   ;
static const uint8_t P9A_PERV_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL          = 63  ;

static const uint8_t P9A_PERV_1_VMEAS_RESULT_REG_RESULT                      = 0   ;
static const uint8_t P9A_PERV_1_VMEAS_RESULT_REG_RESULT_LEN                  = 8   ;

static const uint8_t P9A_PERV_FSII2C_WATER_MARK_REGISTER_A_WATERMARK_REG_0   = 16  ;
static const uint8_t P9A_PERV_FSII2C_WATER_MARK_REGISTER_A_WATERMARK_REG_0_LEN = 16  ;

static const uint8_t P9A_PERV_1_WRITE_PROTECT_ENABLE_REG_RING_LOCKING        = 0   ;
static const uint8_t P9A_PERV_1_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING = 1   ;

static const uint8_t P9A_PERV_1_WRITE_PROTECT_RINGS_REG_RINGS                = 0   ;
static const uint8_t P9A_PERV_1_WRITE_PROTECT_RINGS_REG_RINGS_LEN            = 16  ;

static const uint8_t P9A_PERV_1_XFIR_IN0                                     = 0   ;
static const uint8_t P9A_PERV_1_XFIR_IN1                                     = 1   ;
static const uint8_t P9A_PERV_1_XFIR_IN2                                     = 2   ;
static const uint8_t P9A_PERV_1_XFIR_IN3                                     = 3   ;
static const uint8_t P9A_PERV_1_XFIR_IN4                                     = 4   ;
static const uint8_t P9A_PERV_1_XFIR_IN5                                     = 5   ;
static const uint8_t P9A_PERV_1_XFIR_IN6                                     = 6   ;
static const uint8_t P9A_PERV_1_XFIR_IN7                                     = 7   ;
static const uint8_t P9A_PERV_1_XFIR_IN8                                     = 8   ;
static const uint8_t P9A_PERV_1_XFIR_IN9                                     = 9   ;
static const uint8_t P9A_PERV_1_XFIR_IN10                                    = 10  ;
static const uint8_t P9A_PERV_1_XFIR_IN11                                    = 11  ;
static const uint8_t P9A_PERV_1_XFIR_IN12                                    = 12  ;
static const uint8_t P9A_PERV_1_XFIR_IN13                                    = 13  ;
static const uint8_t P9A_PERV_1_XFIR_IN14                                    = 14  ;
static const uint8_t P9A_PERV_1_XFIR_IN15                                    = 15  ;
static const uint8_t P9A_PERV_1_XFIR_IN16                                    = 16  ;
static const uint8_t P9A_PERV_1_XFIR_IN17                                    = 17  ;
static const uint8_t P9A_PERV_1_XFIR_IN18                                    = 18  ;
static const uint8_t P9A_PERV_1_XFIR_IN19                                    = 19  ;
static const uint8_t P9A_PERV_1_XFIR_IN20                                    = 20  ;
static const uint8_t P9A_PERV_1_XFIR_IN21                                    = 21  ;
static const uint8_t P9A_PERV_1_XFIR_IN21_LEN                                = 5   ;
static const uint8_t P9A_PERV_1_XFIR_IN26                                    = 26  ;

static const uint8_t P9A_PERV_1_XSTOP1_MASK_B                                = 0   ;
static const uint8_t P9A_PERV_1_XSTOP1_ALIGNED                               = 1   ;
static const uint8_t P9A_PERV_1_XSTOP1_TRIGGER_OPCG_ON                       = 2   ;
static const uint8_t P9A_PERV_1_XSTOP1_WAIT_ALLWAYS                          = 3   ;
static const uint8_t P9A_PERV_1_XSTOP1_PERV                                  = 4   ;
static const uint8_t P9A_PERV_1_XSTOP1_UNIT1                                 = 5   ;
static const uint8_t P9A_PERV_1_XSTOP1_UNIT2                                 = 6   ;
static const uint8_t P9A_PERV_1_XSTOP1_UNIT3                                 = 7   ;
static const uint8_t P9A_PERV_1_XSTOP1_UNIT4                                 = 8   ;
static const uint8_t P9A_PERV_1_XSTOP1_UNIT5                                 = 9   ;
static const uint8_t P9A_PERV_1_XSTOP1_UNIT6                                 = 10  ;
static const uint8_t P9A_PERV_1_XSTOP1_UNIT7                                 = 11  ;
static const uint8_t P9A_PERV_1_XSTOP1_UNIT8                                 = 12  ;
static const uint8_t P9A_PERV_1_XSTOP1_UNIT9                                 = 13  ;
static const uint8_t P9A_PERV_1_XSTOP1_UNIT10                                = 14  ;
static const uint8_t P9A_PERV_1_XSTOP1_WAIT_CYCLES                           = 48  ;
static const uint8_t P9A_PERV_1_XSTOP1_WAIT_CYCLES_LEN                       = 12  ;

static const uint8_t P9A_PERV_1_XSTOP2_MASK_B                                = 0   ;
static const uint8_t P9A_PERV_1_XSTOP2_ALIGNED                               = 1   ;
static const uint8_t P9A_PERV_1_XSTOP2_TRIGGER_OPCG_ON                       = 2   ;
static const uint8_t P9A_PERV_1_XSTOP2_WAIT_ALLWAYS                          = 3   ;
static const uint8_t P9A_PERV_1_XSTOP2_PERV                                  = 4   ;
static const uint8_t P9A_PERV_1_XSTOP2_UNIT1                                 = 5   ;
static const uint8_t P9A_PERV_1_XSTOP2_UNIT2                                 = 6   ;
static const uint8_t P9A_PERV_1_XSTOP2_UNIT3                                 = 7   ;
static const uint8_t P9A_PERV_1_XSTOP2_UNIT4                                 = 8   ;
static const uint8_t P9A_PERV_1_XSTOP2_UNIT5                                 = 9   ;
static const uint8_t P9A_PERV_1_XSTOP2_UNIT6                                 = 10  ;
static const uint8_t P9A_PERV_1_XSTOP2_UNIT7                                 = 11  ;
static const uint8_t P9A_PERV_1_XSTOP2_UNIT8                                 = 12  ;
static const uint8_t P9A_PERV_1_XSTOP2_UNIT9                                 = 13  ;
static const uint8_t P9A_PERV_1_XSTOP2_UNIT10                                = 14  ;
static const uint8_t P9A_PERV_1_XSTOP2_WAIT_CYCLES                           = 48  ;
static const uint8_t P9A_PERV_1_XSTOP2_WAIT_CYCLES_LEN                       = 12  ;

static const uint8_t P9A_PERV_1_XSTOP3_MASK_B                                = 0   ;
static const uint8_t P9A_PERV_1_XSTOP3_ALIGNED                               = 1   ;
static const uint8_t P9A_PERV_1_XSTOP3_TRIGGER_OPCG_ON                       = 2   ;
static const uint8_t P9A_PERV_1_XSTOP3_WAIT_ALLWAYS                          = 3   ;
static const uint8_t P9A_PERV_1_XSTOP3_PERV                                  = 4   ;
static const uint8_t P9A_PERV_1_XSTOP3_UNIT1                                 = 5   ;
static const uint8_t P9A_PERV_1_XSTOP3_UNIT2                                 = 6   ;
static const uint8_t P9A_PERV_1_XSTOP3_UNIT3                                 = 7   ;
static const uint8_t P9A_PERV_1_XSTOP3_UNIT4                                 = 8   ;
static const uint8_t P9A_PERV_1_XSTOP3_UNIT5                                 = 9   ;
static const uint8_t P9A_PERV_1_XSTOP3_UNIT6                                 = 10  ;
static const uint8_t P9A_PERV_1_XSTOP3_UNIT7                                 = 11  ;
static const uint8_t P9A_PERV_1_XSTOP3_UNIT8                                 = 12  ;
static const uint8_t P9A_PERV_1_XSTOP3_UNIT9                                 = 13  ;
static const uint8_t P9A_PERV_1_XSTOP3_UNIT10                                = 14  ;
static const uint8_t P9A_PERV_1_XSTOP3_WAIT_CYCLES                           = 48  ;
static const uint8_t P9A_PERV_1_XSTOP3_WAIT_CYCLES_LEN                       = 12  ;

static const uint8_t P9A_PERV_1_XSTOP_INTERRUPT_REG_XSTOP                    = 0   ;

static const uint8_t P9A_PERV_1_XTRA_TRACE_MODE_DATA                         = 0   ;
static const uint8_t P9A_PERV_1_XTRA_TRACE_MODE_DATA_LEN                     = 42  ;

#endif
