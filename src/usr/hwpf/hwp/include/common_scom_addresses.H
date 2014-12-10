/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/include/common_scom_addresses.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: common_scom_addresses.H,v 1.49 2014/01/30 16:19:26 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/common_scom_addresses.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE : common_scom_addresses.H
// *! DESCRIPTION : Defines for common/generic scom addresses shared between P8/Centaur
// *! OWNER NAME  : Jeshua Smith  Email: jeshua@us.ibm.com
// *! BACKUP NAME :               Email:       @us.ibm.com
// #! ADDITIONAL COMMENTS :
//
// The purpose of this header is to define scom addresses for use by procedures.
// This will help catch address typos at compile time, and will make it easy
// to track down which procedures use each address
//

#ifndef COMMON_SCOM_ADDRESSES
#define COMMON_SCOM_ADDRESSES

//----------------------------------------------------------------------
//  Scom address overview
//----------------------------------------------------------------------
// P8 uses 64-bit scom addresses, which are classified into two formats:
//
// "Normal" (legacy) format
//
//            111111 11112222 22222233 33333333 44444444 44555555 55556666
// 01234567 89012345 67890123 45678901 23456789 01234567 89012345 67890123
// -------- -------- -------- -------- -------- -------- -------- --------
// 00000000 00000000 00000000 00000000 0MCCCCCC ????PPPP 00LLLLLL LLLLLLLL
//                                      ||          |    |
//                                      ||          |    `-> Local Address*
//                                      ||          |
//                                      ||          `-> Port
//                                      ||
//                                      |`-> Chiplet ID**
//                                      |
//                                      `-> Multicast bit
//
//  * Local address is composed of "00" + 4-bit ring + 10-bit ID
//    The 10-bit ID is usually 4-bit sat_id and 6-bit reg_id
//
// ** Chiplet ID turns into multicast operation type and group number
//    if the multicast bit is set
//
// "Indirect" format
//
//
//            111111 11112222 22222233 33333333 44444444 44555555 55556666
// 01234567 89012345 67890123 45678901 23456789 01234567 89012345 67890123
// -------- -------- -------- -------- -------- -------- -------- --------
// 10000000 0000IIII IIIIIGGG GGGLLLLL 0MCCCCCC ????PPPP 00LLLLLL LLLLLLLL
//              |         |      |      ||          |    |
//              |         |      |      ||          |    `-> Local Address*
//              |         |      |      ||          |
//              |         |      |      ||          `-> Port
//              |         |      |      ||
//              |         |      |      |`-> Chiplet ID**
//              |         |      |      |
//              |         |      |      `-> Multicast bit
//              |         |      |
//              |         |      `-> Lane ID
//              |         |
//              |         `-> RX or TX Group ID
//              |
//              `-> Indirect Register Address
//
//  * Local address is composed of "00" + 4-bit ring + 4-bit sat_id + "111111"
//
// ** Chiplet ID turns into multicast operation type and group number
//    if the multicast bit is set
//

#include "fapi_sbe_common.H"


/******************************************************************************/
/**********************************  CHIPLET  *********************************/
/******************************************************************************/
//      use for lpcs P0, <chipletID>
CONST_UINT64_T( STBY_CHIPLET_0x00000000               , ULL(0x00000000) );
CONST_UINT64_T( TP_CHIPLET_0x01000000                 , ULL(0x01000000) );
CONST_UINT64_T( NEST_CHIPLET_0x02000000               , ULL(0x02000000) );
CONST_UINT64_T( XBUS_CHIPLET_0x04000000               , ULL(0x04000000) );


/******************************************************************************/
/******************************  GENERIC CHIPLET  *****************************/
/******************************************************************************/

//------------------------------------------------------------------------------
//      GENERIC GP
//------------------------------------------------------------------------------
CONST_UINT64_T( GENERIC_GP0_0x00000000                , ULL(0x00000000) );
CONST_UINT64_T( GENERIC_GP1_0x00000001                , ULL(0x00000001) );
CONST_UINT64_T( GENERIC_GP2_0x00000002                , ULL(0x00000002) );
CONST_UINT64_T( GENERIC_GP4_0x00000003                , ULL(0x00000003) );
CONST_UINT64_T( GENERIC_GP0_AND_0x00000004            , ULL(0x00000004) );
CONST_UINT64_T( GENERIC_GP0_OR_0x00000005             , ULL(0x00000005) );

//------------------------------------------------------------------------------
//      GENERIC DEBUG
//------------------------------------------------------------------------------
CONST_UINT64_T( GENERIC_DBG_MODE_REG_0x000107C0        , ULL(0x000107C0) );
CONST_UINT64_T( GENERIC_DBG_INST1_COND_REG1_0x000107C1 , ULL(0x000107C1) );
CONST_UINT64_T( GENERIC_DBG_INST1_COND_REG2_0x000107C2 , ULL(0x000107C2) );
CONST_UINT64_T( GENERIC_DBG_INST2_COND_REG1_0x000107C3 , ULL(0x000107C3) );
CONST_UINT64_T( GENERIC_DBG_INST2_COND_REG2_0x000107C4 , ULL(0x000107C4) );
CONST_UINT64_T( GENERIC_DBG_TRACE_REG0_0x000107C9      , ULL(0x000107C9) );
CONST_UINT64_T( GENERIC_DBG_TRACE_REG1_0x000107CA      , ULL(0x000107CA) );
CONST_UINT64_T( GENERIC_DBG_TRACE_REG2_0x000107CB      , ULL(0x000107CB) );

//------------------------------------------------------------------------------
//      GENERIC CLOCK CONTROL
//------------------------------------------------------------------------------
CONST_UINT64_T( GENERIC_OPCG_CNTL0_0x00030002         , ULL(0x00030002) );
CONST_UINT64_T( GENERIC_OPCG_CNTL1_0x00030003         , ULL(0x00030003) );
CONST_UINT64_T( GENERIC_OPCG_CNTL2_0x00030004         , ULL(0x00030004) );
CONST_UINT64_T( GENERIC_OPCG_CNTL3_0x00030005         , ULL(0x00030005) );
CONST_UINT64_T( GENERIC_CLK_SYNC_CONFIG_0x00030000    , ULL(0x00030000) );
CONST_UINT64_T( GENERIC_CLK_REGION_0x00030006         , ULL(0x00030006) );
CONST_UINT64_T( GENERIC_CLK_SCANSEL_0x00030007        , ULL(0x00030007) );
CONST_UINT64_T( GENERIC_CLK_STATUS_0x00030008         , ULL(0x00030008) );
CONST_UINT64_T( GENERIC_CLK_ERROR_0x00030009          , ULL(0x00030009) );
CONST_UINT64_T( GENERIC_CLK_SCANDATA0_0x00038000      , ULL(0x00038000) );
CONST_UINT64_T( GENERIC_CLK_SCAN_UPDATEDR_0x0003A000  , ULL(0x0003A000) );
CONST_UINT64_T( GENERIC_CLK_SCAN_CAPTUREDR_0x0003C000 , ULL(0x0003C000) );

//------------------------------------------------------------------------------
//      GENERIC FIR
//------------------------------------------------------------------------------
CONST_UINT64_T( GENERIC_XSTOP_0x00040000              , ULL(0x00040000) );
CONST_UINT64_T( GENERIC_RECOV_0x00040001              , ULL(0x00040001) );
CONST_UINT64_T( GENERIC_FIR_MASK_0x00040002           , ULL(0x00040002) );
CONST_UINT64_T( GENERIC_SPATTN_0x00040004             , ULL(0x00040004) );
CONST_UINT64_T( GENERIC_SPATTN_AND_0x00040005         , ULL(0x00040005) );
CONST_UINT64_T( GENERIC_SPATTN_OR_0x00040006          , ULL(0x00040006) );
CONST_UINT64_T( GENERIC_SPATTN_MASK_0x00040007        , ULL(0x00040007) );
CONST_UINT64_T( GENERIC_FIR_MODE_0x00040008           , ULL(0x00040008) );
CONST_UINT64_T( GENERIC_PERV_LFIR_0x0004000A          , ULL(0x0004000A) );
CONST_UINT64_T( GENERIC_PERV_LFIR_AND_0x0004000B      , ULL(0x0004000B) );
CONST_UINT64_T( GENERIC_PERV_LFIR_OR_0x0004000C       , ULL(0x0004000C) );
CONST_UINT64_T( GENERIC_PERV_LFIR_MASK_0x0004000D     , ULL(0x0004000D) );
CONST_UINT64_T( GENERIC_PERV_LFIR_MASK_AND_0x0004000E , ULL(0x0004000E) );
CONST_UINT64_T( GENERIC_PERV_LFIR_MASK_OR_0x0004000F  , ULL(0x0004000F) );
CONST_UINT64_T( GENERIC_PERV_LFIR_ACT0_0x00040010     , ULL(0x00040010) );
CONST_UINT64_T( GENERIC_PERV_LFIR_ACT1_0x00040011     , ULL(0x00040011) );

//------------------------------------------------------------------------------
//      GENERIC PCB SLAVE
//------------------------------------------------------------------------------
//Multicast Group Registers
CONST_UINT64_T( GENERIC_MCGR1_0x000F0001              , ULL(0x000F0001) );
CONST_UINT64_T( GENERIC_MCGR2_0x000F0002              , ULL(0x000F0002) );
CONST_UINT64_T( GENERIC_MCGR3_0x000F0003              , ULL(0x000F0003) );
CONST_UINT64_T( GENERIC_MCGR4_0x000F0004              , ULL(0x000F0004) );

//GP3 Register
CONST_UINT64_T( GENERIC_GP3_0x000F0012                , ULL(0x000F0012) );
CONST_UINT64_T( GENERIC_GP3_AND_0x000F0013            , ULL(0x000F0013) );
CONST_UINT64_T( GENERIC_GP3_OR_0x000F0014             , ULL(0x000F0014) );

// PM GP0 Register
CONST_UINT64_T( GENERIC_PMGP0_OR_0x000F0102           , ULL(0x000F0102) );

// PCB ERROR
CONST_UINT64_T( GENERIC_PCB_ERR_0x000F001F            , ULL(0x000F001F) );

//------------------------------------------------------------------------------
//      GENERIC PLLLOCK REG
//------------------------------------------------------------------------------
CONST_UINT64_T( GENERIC_PLLLOCKREG_0x000F0019         , ULL(0x000F0019) );

//------------------------------------------------------------------------------
//      GENERIC HANG PULSE CONTROL
//------------------------------------------------------------------------------
CONST_UINT64_T( GENERIC_HANG_P0_0x000F0020            , ULL(0x000F0020) );
CONST_UINT64_T( GENERIC_HANG_P1_0x000F0021            , ULL(0x000F0021) );
CONST_UINT64_T( GENERIC_HANG_P2_0x000F0022            , ULL(0x000F0022) );
CONST_UINT64_T( GENERIC_HANG_PRE_0x000F0028           , ULL(0x000F0028) );


/******************************************************************************/
/********************************  TP CHIPLET  ********************************/
/******************************************************************************/

//------------------------------------------------------------------------------
//      CFAM Registers
//------------------------------------------------------------------------------
CONST_UINT32_T( CFAM_FSI_SHIFT_CTRL_0x00000C10        , ULL(0x00000C10) );
CONST_UINT32_T( CFAM_FSI_DATA_0_0x00001000            , ULL(0x00001000) );
CONST_UINT32_T( CFAM_FSI_DATA_1_0x00001001            , ULL(0x00001001) );
CONST_UINT32_T( CFAM_FSI_CMD_REG_0x00001002           , ULL(0x00001002) );
CONST_UINT32_T( CFAM_FSI_RESET_0x00001006             , ULL(0x00001006) );
CONST_UINT32_T( CFAM_FSI_STATUS_0x00001007            , ULL(0x00001007) );
CONST_UINT32_T( CFAM_FSI_GP1_0x00001010               , ULL(0x00001010) );
CONST_UINT32_T( CFAM_FSI_GP2_0x00001011               , ULL(0x00001011) );
CONST_UINT32_T( CFAM_FSI_GP3_0x00001012               , ULL(0x00001012) );
CONST_UINT32_T( CFAM_FSI_GP4_0x00001013               , ULL(0x00001013) );
CONST_UINT32_T( CFAM_FSI_GP5_0x00001014               , ULL(0x00001014) );
CONST_UINT32_T( CFAM_FSI_GP6_0x00001015               , ULL(0x00001015) );
CONST_UINT32_T( CFAM_FSI_GP7_0x00001016               , ULL(0x00001016) );
CONST_UINT32_T( CFAM_FSI_GP8_0x00001017               , ULL(0x00001017) );
CONST_UINT32_T( CFAM_FSI_GP3_MIRROR_0x0000101B        , ULL(0x0000101B) );

//------------------------------------------------------------------------------
//      OTPROM
//------------------------------------------------------------------------------
CONST_UINT64_T( OTPROM_0x00010000                     , ULL(0x00010000) );

//------------------------------------------------------------------------------
//      MFSI0
//------------------------------------------------------------------------------
CONST_UINT64_T( MFSI0_0x00020000                      , ULL(0x00020000) );

//------------------------------------------------------------------------------
//      MFSI1
//------------------------------------------------------------------------------
CONST_UINT64_T( MFSI1_0x00030000                      , ULL(0x00030000) );

//------------------------------------------------------------------------------
//      TOD
//------------------------------------------------------------------------------
CONST_UINT64_T( TOD_0x00040000                        , ULL(0x00040000) );

//------------------------------------------------------------------------------
//      FSI MBOX
//------------------------------------------------------------------------------
CONST_UINT64_T( MBOX_FSIRESET_0x00050006              , ULL(0x00050006) );
CONST_UINT64_T( MBOX_FSISTATUS_0x00050007             , ULL(0x00050007) );
CONST_UINT64_T( MBOX_CFAMID_0x0005000A                , ULL(0x0005000A) );
CONST_UINT64_T( MBOX_TMASK_0x0005000D                 , ULL(0x0005000D) );
CONST_UINT64_T( MBOX_CMASK_0x0005000C                 , ULL(0x0005000C) );
CONST_UINT64_T( MBOX_FSIGP3_0x00050012                , ULL(0x00050012) );
CONST_UINT64_T( MBOX_FSIGP4_0x00050013                , ULL(0x00050013) );
CONST_UINT64_T( MBOX_FSIGP5_0x00050014                , ULL(0x00050014) );
CONST_UINT64_T( MBOX_FSIGP6_0x00050015                , ULL(0x00050015) );
CONST_UINT64_T( MBOX_FSIGP7_0x00050016                , ULL(0x00050016) );
CONST_UINT64_T( MBOX_FSIGP8_0x00050017                , ULL(0x00050017) );
CONST_UINT64_T( MBOX_OSC_S1_0x00050019                , ULL(0x00050019) );
CONST_UINT64_T( MBOX_OSC_S2_0x0005001A                , ULL(0x0005001A) );
CONST_UINT64_T( MBOX_GP3MIR_0x0005001B                , ULL(0x0005001B) );
CONST_UINT64_T( MBOX_SBEVITAL_0x0005001C              , ULL(0x0005001C) );
CONST_UINT64_T( MBOX_SCRATCH_REG0_0x00050038          , ULL(0x00050038) );
CONST_UINT64_T( MBOX_SCRATCH_REG1_0x00050039          , ULL(0x00050039) );
CONST_UINT64_T( MBOX_SCRATCH_REG2_0x0005003A          , ULL(0x0005003A) );
CONST_UINT64_T( MBOX_SCRATCH_REG3_0x0005003B          , ULL(0x0005003B) );

//------------------------------------------------------------------------------
//      TP ADDITIONAL REGISTER
//------------------------------------------------------------------------------
CONST_UINT64_T( TP_PLL_LOCK_0x010F0019                , ULL(0x010F0019) );
CONST_UINT64_T( TP_CLK_ADJ_SET_0x010F0016             , ULL(0x010F0016) );

//------------------------------------------------------------------------------
//      ECCB REGISTERS
//------------------------------------------------------------------------------

CONST_UINT64_T( ECCB_ECC_ADDR_REG_0x000C0004          , ULL(0x000C0004) );

//------------------------------------------------------------------------------
//      I2C MASTER (MEMS0)
//------------------------------------------------------------------------------
CONST_UINT64_T( I2CMS_MEMS0_CONTROL_0x000A0000        , ULL(0x000A0000) );
CONST_UINT64_T( I2CMS_MEMS0_RESET_0x000A0001          , ULL(0x000A0001) );
CONST_UINT64_T( I2CMS_MEMS0_STATUS_0x000A0002         , ULL(0x000A0002) );
CONST_UINT64_T( I2CMS_MEMS0_DATA_0x000A0003           , ULL(0x000A0003) );
CONST_UINT64_T( I2CMS_MEMS0_COMMAND_0x000A0005        , ULL(0x000A0005) );
CONST_UINT64_T( I2CMS_MEMS0_MODE_0x000A0006           , ULL(0x000A0006) );
CONST_UINT64_T( I2CMS_MEMS0_STATUS_0x000A000B         , ULL(0x000A000B) );

//------------------------------------------------------------------------------
//      PCB MASTER
//------------------------------------------------------------------------------
CONST_UINT64_T( PCBMS_0x000F0000                      , ULL(0x000F0000) );
CONST_UINT64_T( PCBMS_REC_ACK_REG_0x000F0010          , ULL(0x000F0010) );
CONST_UINT64_T( PCBMS_REC_ERR_REG0_0x000F0011         , ULL(0x000F0011) );
CONST_UINT64_T( PCBMS_REC_ERR_REG1_0x000F0012         , ULL(0x000F0012) );
CONST_UINT64_T( PCBMS_DEVICE_ID_0x000F000F            , ULL(0x000F000F) );
CONST_UINT64_T( PCB_TIMEOUT_0x000F0019                , ULL(0x000F0019) );
CONST_UINT64_T( MASTER_PCB_INT_0x000F001A             , ULL(0x000F001A) );
CONST_UINT64_T( PRV_PIB_PCBMS_RESET_REG_0x000F001D    , ULL(0x000F001D) );
CONST_UINT64_T( PCBMS_FIRST_ERR_REG_0x000F001E        , ULL(0x000F001E) );
CONST_UINT64_T( MASTER_PCB_ERR_0x000F001F             , ULL(0x000F001F) );
CONST_UINT64_T( PCBSL_ERROR_REG_ALL_0x400F001F        , ULL(0x400F001F) );

//------------------------------------------------------------------------------
//      TP GPIO
//------------------------------------------------------------------------------
CONST_UINT64_T( TP_GP0_0x01000000                     , ULL(0x01000000) );
CONST_UINT64_T( TP_GP1_0x01000001                     , ULL(0x01000001) );
CONST_UINT64_T( TP_GP2_0x01000002                     , ULL(0x01000002) );
CONST_UINT64_T( TP_GP4_0x01000003                     , ULL(0x01000003) );
CONST_UINT64_T( TP_GP0_AND_0x01000004                 , ULL(0x01000004) );
CONST_UINT64_T( TP_GP0_OR_0x01000005                  , ULL(0x01000005) );
CONST_UINT64_T( TP_GP4_AND_0x01000006                 , ULL(0x01000006) );
CONST_UINT64_T( TP_GP4_OR_0x01000007                  , ULL(0x01000007) );

//------------------------------------------------------------------------------
//      TP SCOM
//------------------------------------------------------------------------------
CONST_UINT64_T( TP_SCOM_0x01010000                    , ULL(0x01010000) );

//------------------------------------------------------------------------------
//      TP TRACE
//------------------------------------------------------------------------------
CONST_UINT64_T( TP_TRACE_STATUS_0x01010004            , ULL(0x01010004) );
CONST_UINT64_T( TP_TRACE_DATA_HI_0x01010400           , ULL(0x01010400) );
CONST_UINT64_T( TP_TRACE_DATA_LO_0x01010401           , ULL(0x01010401) );

//------------------------------------------------------------------------------
//      TP ITR
//------------------------------------------------------------------------------
CONST_UINT64_T( TP_INTRPT_PRES_TYP1_0x01020000        , ULL(0x01020000) );
CONST_UINT64_T( TP_INTRPT_PRES_TYP1_OR_0x01020001     , ULL(0x01020001) );
CONST_UINT64_T( TP_INTRPT_PRES_TYP1_AND_0x01020002    , ULL(0x01020002) );
CONST_UINT64_T( TP_INTRPT_PRES_TYP2_0x01020003        , ULL(0x01020003) );
CONST_UINT64_T( TP_INTRPT_PRES_TYP2_OR_0x01020004     , ULL(0x01020004) );
CONST_UINT64_T( TP_INTRPT_PRES_TYP2_AND_0x01020005    , ULL(0x01020005) );
CONST_UINT64_T( TP_INTRPT_PRES_TYP3_0x01020006        , ULL(0x01020006) );
CONST_UINT64_T( TP_INTRPT_PRES_TYP3_OR_0x01020007     , ULL(0x01020007) );
CONST_UINT64_T( TP_INTRPT_PRES_TYP3_AND_0x01020008    , ULL(0x01020008) );
CONST_UINT64_T( TP_INTRPT_PRES_TYP4_0x01020009        , ULL(0x01020009) );
CONST_UINT64_T( TP_INTRPT_PRES_TYP4_OR_0x0102000A     , ULL(0x0102000A) );
CONST_UINT64_T( TP_INTRPT_PRES_TYP4_AND_0x0102000B    , ULL(0x0102000B) );

CONST_UINT64_T( TP_INTRPT_TYP_MSK_0x0102000C          , ULL(0x0102000C) );
CONST_UINT64_T( TP_INTRPT_TYP_MSK_OR_0x0102000D       , ULL(0x0102000D) );
CONST_UINT64_T( TP_INTRPT_TYP_MSK_AND_0x0102000E      , ULL(0x0102000E) );

CONST_UINT64_T( TP_INTRPT_CONFIG_0x0102000F           , ULL(0x0102000F) );
CONST_UINT64_T( TP_INTRPT_CONFIG_OR_0x01020010        , ULL(0x01020010) );
CONST_UINT64_T( TP_INTRPT_CONFIG_AND_0x01020011       , ULL(0x01020011) );

CONST_UINT64_T( TP_INTRPT_HOLD_0x01020012             , ULL(0x01020012) );
CONST_UINT64_T( TP_IPOLL_MSK_0x01020013               , ULL(0x01020013) );
CONST_UINT64_T( TP_ITR_ERR_STAT_0x01020014            , ULL(0x01020014) );
CONST_UINT64_T( TP_OSCERR_HOLD_0x01020019             , ULL(0x01020019) );
CONST_UINT64_T( TP_OSC_MSK_0x0102001A                 , ULL(0x0102001A) );

//------------------------------------------------------------------------------
//      TP CLOCK CONTROL
//------------------------------------------------------------------------------
CONST_UINT64_T( TP_OPCG_CNTL0_0x01030002              , ULL(0x01030002) );
CONST_UINT64_T( TP_OPCG_CNTL1_0x01030003              , ULL(0x01030003) );
CONST_UINT64_T( TP_OPCG_CNTL2_0x01030004              , ULL(0x01030004) );
CONST_UINT64_T( TP_OPCG_CNTL3_0x01030005              , ULL(0x01030005) );
CONST_UINT64_T( TP_CLK_REGION_0x01030006              , ULL(0x01030006) );

CONST_UINT64_T( TP_CLK_SCANSEL_0x01030007             , ULL(0x01030007) );
CONST_UINT64_T( TP_CLK_STATUS_0x01030008              , ULL(0x01030008) );
CONST_UINT64_T( TP_CC_ERROR_STATUS_0x01030009         , ULL(0x01030009) );
CONST_UINT64_T( TP_CC_PROTECT_MODE_0x010303FE         , ULL(0x010303FE) );

//------------------------------------------------------------------------------
//      TP FIR
//------------------------------------------------------------------------------
CONST_UINT64_T( TP_XSTOP_0x01040000                   , ULL(0x01040000) );
CONST_UINT64_T( TP_RECOV_0x01040001                   , ULL(0x01040001) );
CONST_UINT64_T( TP_FIR_MASK_0x01040002                , ULL(0x01040002) );
CONST_UINT64_T( TP_SPATTN_0x01040004                  , ULL(0x01040004) );
CONST_UINT64_T( TP_SPATTN_AND_0x01040005              , ULL(0x01040005) );
CONST_UINT64_T( TP_SPATTN_OR_0x01040006               , ULL(0x01040006) );
CONST_UINT64_T( TP_SPATTN_MASK_0x01040007             , ULL(0x01040007) );
CONST_UINT64_T( TP_FIR_MODE_0x01040008                , ULL(0x01040008) );
CONST_UINT64_T( TP_PERV_LFIR_0x0104000A               , ULL(0x0104000A) );
CONST_UINT64_T( TP_PERV_LFIR_AND_0x0104000B           , ULL(0x0104000B) );
CONST_UINT64_T( TP_PERV_LFIR_OR_0x0104000C            , ULL(0x0104000C) );
CONST_UINT64_T( TP_PERV_LFIR_MASK_0x0104000D          , ULL(0x0104000D) );
CONST_UINT64_T( TP_PERV_LFIR_MASK_AND_0x0104000E      , ULL(0x0104000E) );
CONST_UINT64_T( TP_PERV_LFIR_MASK_OR_0x0104000F       , ULL(0x0104000F) );
CONST_UINT64_T( TP_PERV_LFIR_ACT0_0x01040010          , ULL(0x01040010) );
CONST_UINT64_T( TP_PERV_LFIR_ACT1_0x01040011          , ULL(0x01040011) );

//------------------------------------------------------------------------------
//      TP PCB SLAVE
//------------------------------------------------------------------------------
//Multicast Group Registers
CONST_UINT64_T( TP_MCGR1_0x010F0001                   , ULL(0x010F0001) );
CONST_UINT64_T( TP_MCGR2_0x010F0002                   , ULL(0x010F0002) );
CONST_UINT64_T( TP_MCGR3_0x010F0003                   , ULL(0x010F0003) );
CONST_UINT64_T( TP_MCGR4_0x010F0004                   , ULL(0x010F0004) );
//GP3 Register
//Figtree says GP3 register doesn't exist in TP chiplet
//CONST_UINT64_T( TP_GP3_0x010F0012                    , ULL(0x010F0012) );
//CONST_UINT64_T( TP_GP3_AND_0x010F0013                , ULL(0x010F0013) );
//CONST_UINT64_T( TP_GP3_OR_0x010F0014                 , ULL(0x010F0014) );

//------------------------------------------------------------------------------
//      TP HANG DETECTION
//------------------------------------------------------------------------------
CONST_UINT64_T( TP_HANG_P0_0x010F0020                  , ULL(0x010F0020) );     // PRV: setup hang pulse register0
CONST_UINT64_T( TP_HANG_P1_0x010F0021                  , ULL(0x010F0021) );     // PRV: setup hang pulse register1
CONST_UINT64_T( TP_HANG_P2_0x010F0022                  , ULL(0x010F0022) );     // PRV: setup hang pulse register2
CONST_UINT64_T( TP_HANG_P3_0x010F0023                  , ULL(0x010F0023) );     // PRV: setup hang pulse register3
CONST_UINT64_T( TP_HANG_P4_0x010F0024                  , ULL(0x010F0024) );     // PRV: setup hang pulse register4
CONST_UINT64_T( TP_HANG_P5_0x010F0025                  , ULL(0x010F0025) );     // PRV: setup hang pulse register5
CONST_UINT64_T( TP_HANG_P6_0x010F0026                  , ULL(0x010F0026) );     // PRV: setup hang pulse register6
CONST_UINT64_T( TP_HANG_PRE_0x010F0028                 , ULL(0x010F0028) );     // PRV: setup hang precounter (HEX:01)


/******************************************************************************/
/*******************************  NEST CHIPLET  *******************************/
/******************************************************************************/

//------------------------------------------------------------------------------
//      NEST GPIO
//------------------------------------------------------------------------------
CONST_UINT64_T( NEST_GP0_0x02000000                   , ULL(0x02000000) );
CONST_UINT64_T( NEST_GP1_0x02000001                   , ULL(0x02000001) );
CONST_UINT64_T( NEST_GP2_0x02000002                   , ULL(0x02000002) );
CONST_UINT64_T( NEST_GP0_AND_0x02000004               , ULL(0x02000004) );
CONST_UINT64_T( NEST_GP0_OR_0x02000005                , ULL(0x02000005) );
CONST_UINT64_T( NEST_GP4_AND_0x02000006               , ULL(0x02000006) );
CONST_UINT64_T( NEST_GP4_OR_0x02000007                , ULL(0x02000007) );

//------------------------------------------------------------------------------
//      NEST SCOM
//------------------------------------------------------------------------------
CONST_UINT64_T( NEST_SCOM_0x02010000                  , ULL(0x02010000) );

//------------------------------------------------------------------------------
//      NEST TRACE
//------------------------------------------------------------------------------
CONST_UINT64_T( NEST_TRACE_STATUS_0x02010004          , ULL(0x02010004) );

//------------------------------------------------------------------------------
//      NEST CLOCK CONTROL
//------------------------------------------------------------------------------
CONST_UINT64_T( NEST_OPCG_CNTL0_0x02030002            , ULL(0x02030002) );
CONST_UINT64_T( NEST_OPCG_CNTL1_0x02030003            , ULL(0x02030003) );
CONST_UINT64_T( NEST_OPCG_CNTL2_0x02030004            , ULL(0x02030004) );
CONST_UINT64_T( NEST_OPCG_CNTL3_0x02030005            , ULL(0x02030005) );
CONST_UINT64_T( NEST_CLK_REGION_0x02030006            , ULL(0x02030006) );
CONST_UINT64_T( NEST_CLK_SCANSEL_0x02030007           , ULL(0x02030007) );
CONST_UINT64_T( NEST_CLK_STATUS_0x02030008            , ULL(0x02030008) );
CONST_UINT64_T( NEST_CC_ERROR_STATUS_0x02030009       , ULL(0x02030009) );
CONST_UINT64_T( NEST_CC_PROTECT_MODE_0x020303FE       , ULL(0x020303FE) );

//------------------------------------------------------------------------------
//      NEST FIR
//------------------------------------------------------------------------------
CONST_UINT64_T( NEST_XSTOP_0x02040000                 , ULL(0x02040000) );
CONST_UINT64_T( NEST_RECOV_0x02040001                 , ULL(0x02040001) );
CONST_UINT64_T( NEST_FIR_MASK_0x02040002              , ULL(0x02040002) );
CONST_UINT64_T( NEST_SPATTN_0x02040004                , ULL(0x02040004) );
CONST_UINT64_T( NEST_SPATTN_AND_0x02040005            , ULL(0x02040005) );
CONST_UINT64_T( NEST_SPATTN_OR_0x02040006             , ULL(0x02040006) );
CONST_UINT64_T( NEST_SPATTN_MASK_0x02040007           , ULL(0x02040007) );
CONST_UINT64_T( NEST_FIR_MODE_0x02040008              , ULL(0x02040008) );
CONST_UINT64_T( NEST_PERV_LFIR_0x0204000A             , ULL(0x0204000A) );
CONST_UINT64_T( NEST_PERV_LFIR_AND_0x0204000B         , ULL(0x0204000B) );
CONST_UINT64_T( NEST_PERV_LFIR_OR_0x0204000C          , ULL(0x0204000C) );
CONST_UINT64_T( NEST_PERV_LFIR_MASK_0x0204000D        , ULL(0x0204000D) );
CONST_UINT64_T( NEST_PERV_LFIR_MASK_AND_0x0204000E    , ULL(0x0204000E) );
CONST_UINT64_T( NEST_PERV_LFIR_MASK_OR_0x0204000F     , ULL(0x0204000F) );
CONST_UINT64_T( NEST_PERV_LFIR_ACT0_0x02040010        , ULL(0x02040010) );
CONST_UINT64_T( NEST_PERV_LFIR_ACT1_0x02040011        , ULL(0x02040011) );

//------------------------------------------------------------------------------
//      NEST PCB SLAVE
//------------------------------------------------------------------------------
//Multicast Group Registers
CONST_UINT64_T( NEST_MCGR1_0x020F0001                 , ULL(0x020F0001) );
CONST_UINT64_T( NEST_MCGR2_0x020F0002                 , ULL(0x020F0002) );
CONST_UINT64_T( NEST_MCGR3_0x020F0003                 , ULL(0x020F0003) );
CONST_UINT64_T( NEST_MCGR4_0x020F0004                 , ULL(0x020F0004) );
//GP3 Register
CONST_UINT64_T( NEST_GP3_0x020F0012                   , ULL(0x020F0012) );
CONST_UINT64_T( NEST_GP3_AND_0x020F0013               , ULL(0x020F0013) );
CONST_UINT64_T( NEST_GP3_OR_0x020F0014                , ULL(0x020F0014) );

//------------------------------------------------------------------------------
//      NEST HANG DETECTION
//------------------------------------------------------------------------------
CONST_UINT64_T( NEST_HANG_P0_0x020F0020               , ULL(0x020F0020) );     // NEST (PB): setup hang pulse register0
CONST_UINT64_T( NEST_HANG_P1_0x020F0021               , ULL(0x020F0021) );     // NEST     : setup hang pulse register1
CONST_UINT64_T( NEST_HANG_P2_0x020F0022               , ULL(0x020F0022) );     // NEST     : setup hang pulse register2
CONST_UINT64_T( NEST_HANG_P3_0x020F0023               , ULL(0x020F0023) );     // NEST     : setup hang pulse register3
CONST_UINT64_T( NEST_HANG_P4_0x020F0024               , ULL(0x020F0024) );     // NEST     : setup hang pulse register4
CONST_UINT64_T( NEST_HANG_P5_0x020F0025               , ULL(0x020F0025) );     // NEST     : setup hang pulse register5
CONST_UINT64_T( NEST_HANG_P6_0x020F0026               , ULL(0x020F0026) );     // NEST     : setup hang pulse register6
CONST_UINT64_T( NEST_HANG_PRE_0x020F0028              , ULL(0x020F0028) );     // NEST (PB): setup hang precounter (HEX:01)


/******************************************************************************/
/*********  MULTICAST REGISTER DEFINITIONS FOR PERVASIVE INITs ****************/
/******************************************************************************/

CONST_UINT64_T( READ_ALL_GP0_0x43000000               , ULL(0x43000000) );       // all GP0 but not PRV
CONST_UINT64_T( WRITE_ALL_GP0_0x6B000000              , ULL(0x6B000000) );       // all GP0 but not PRV
CONST_UINT64_T( WRITE_ALL_GP0_AND_0x6B000004          , ULL(0x6B000004) );       // all GP0 AND but not PRV
CONST_UINT64_T( WRITE_ALL_GP0_OR_0x6B000005           , ULL(0x6B000005) );       // all GP0 OR but not PRV

CONST_UINT64_T( READ_ALL_GP1_AND_0x4B000001           , ULL(0x4B000001) );       // and all GP1 but not PRV

CONST_UINT64_T( WRITE_ALL_CLK_REGION_0x6B030006       , ULL(0x6B030006) );       // all GP3 but not PRV

CONST_UINT64_T( READ_ALL_OPCG_CNTL0_0x43030002        , ULL(0x43030002) );       // all OPCG0 but not PRV
CONST_UINT64_T( WRITE_ALL_OPCG_CNTL0_0x6B030002       , ULL(0x6B030002) );       // all OPCG0 but not PRV

CONST_UINT64_T( READ_ALL_OPCG_CNTL2_0x43030004        , ULL(0x43030004) );       // all OPCG2 but not PRV
CONST_UINT64_T( WRITE_ALL_OPCG_CNTL2_0x6B030004       , ULL(0x6B030004) );       // all OPCG2 but not PRV

CONST_UINT64_T( READ_ALL_FUNC_GP3_0x430F0012          , ULL(0x430F0012) );       // all GP3 but not PRV

CONST_UINT64_T( SLAVE_PCB_ERR_0x6B0F001F              , ULL(0x6B0F001F) );


CONST_UINT64_T( READ_OR_ALL_FUNC_GP0_0x43000000         , ULL(0x43000000) ); // group3: all except PRV: GP0
CONST_UINT64_T( READ_OR_ALL_FUNC_GP1_0x43000001         , ULL(0x43000001) ); // group3: all except PRV: GP1
CONST_UINT64_T( READ_OR_ALL_FUNC_GP2_0x43000002         , ULL(0x43000002) ); // group3: all except PRV: GP2
CONST_UINT64_T( READ_OR_ALL_FUNC_GP4_0x43000003         , ULL(0x43000003) ); // group3: all except PRV: GP4
CONST_UINT64_T( READ_OR_ALL_FUNC_OPCG_CNTL0_0x43030002  , ULL(0x43030002) ); // group3: all except PRV: OPCG_CNTL0
CONST_UINT64_T( READ_OR_ALL_FUNC_OPCG_CNTL1_0x43030003  , ULL(0x43030003) ); // group3: all except PRV: OPCG_CNTL1
CONST_UINT64_T( READ_OR_ALL_FUNC_OPCG_CNTL2_0x43030004  , ULL(0x43030004) ); // group3: all except PRV: OPCG_CNTL2
CONST_UINT64_T( READ_OR_ALL_FUNC_OPCG_CNTL3_0x43030005  , ULL(0x43030005) ); // group3: all except PRV: OPCG_CNTL3
CONST_UINT64_T( READ_OR_ALL_FUNC_CLK_REGION_0x43030006  , ULL(0x43030006) ); // group3: all except PRV: CLK_REGION
CONST_UINT64_T( READ_OR_ALL_FUNC_CLK_SCANSEL_0x43030007 , ULL(0x43030007) ); // group3: all except PRV: CLK_SCANSEL
CONST_UINT64_T( READ_OR_ALL_FUNC_CLK_STATUS_0x43030008  , ULL(0x43030008) ); // group3: all except PRV: CLK_STATUS
CONST_UINT64_T( READ_OR_ALL_FUNC_GP3_0x430F0012         , ULL(0x430F0012) ); // group3: all except PRV: GP3
CONST_UINT64_T( READ_OR_ALL_PCB_SLAVE_ERRREG_0x430F001F , ULL(0x430F001F) ); // group3: all except PRV:

CONST_UINT64_T( READ_AND_ALL_FUNC_GP0_0x4B000000         , ULL(0x4B000000) ); // group3: all except PRV: GP0
CONST_UINT64_T( READ_AND_ALL_FUNC_GP1_0x4B000001         , ULL(0x4B000001) ); // group3: all except PRV: GP1
CONST_UINT64_T( READ_AND_ALL_FUNC_GP2_0x4B000002         , ULL(0x4B000002) ); // group3: all except PRV: GP2
CONST_UINT64_T( READ_AND_ALL_FUNC_GP4_0x4B000003         , ULL(0x4B000003) ); // group3: all except PRV: GP4
CONST_UINT64_T( READ_AND_ALL_FUNC_OPCG_CNTL0_0x4B030002  , ULL(0x4B030002) ); // group3: all except PRV: OPCG_CNTL0
CONST_UINT64_T( READ_AND_ALL_FUNC_OPCG_CNTL1_0x4B030003  , ULL(0x4B030003) ); // group3: all except PRV: OPCG_CNTL1
CONST_UINT64_T( READ_AND_ALL_FUNC_OPCG_CNTL2_0x4B030004  , ULL(0x4B030004) ); // group3: all except PRV: OPCG_CNTL2
CONST_UINT64_T( READ_AND_ALL_FUNC_OPCG_CNTL3_0x4B030005  , ULL(0x4B030005) ); // group3: all except PRV: OPCG_CNTL3
CONST_UINT64_T( READ_AND_ALL_FUNC_CLK_REGION_0x4B030006  , ULL(0x4B030006) ); // group3: all except PRV: CLK_REGION
CONST_UINT64_T( READ_AND_ALL_FUNC_CLK_SCANSEL_0x4B030007 , ULL(0x4B030007) ); // group3: all except PRV: CLK_SCANSEL
CONST_UINT64_T( READ_AND_ALL_FUNC_CLK_STATUS_0x4B030008  , ULL(0x4B030008) ); // group3: all except PRV: CLK_STATUS
CONST_UINT64_T( READ_AND_ALL_FUNC_GP3_0x4B0F0012         , ULL(0x4B0F0012) ); // group3: all except PRV: GP3
CONST_UINT64_T( READ_AND_ALL_PCB_SLAVE_ERRREG_0x4B0F001F , ULL(0x4B0F001F) ); // group3: all except PRV:

CONST_UINT64_T( READ_ALL_PCB_SLAVE_ATTN_INT_0x500F001A   , ULL(0x500F001A) ); // group0: all chiplets
CONST_UINT64_T( READ_ALL_PCB_SLAVE_RECOV_INT_0x500F001B  , ULL(0x500F001B) ); // group0: all chiplets
CONST_UINT64_T( READ_ALL_PCB_SLAVE_XSTOP_INT_0x500F001C  , ULL(0x500F001C) ); // group0: all chiplets

CONST_UINT64_T( WRITE_ALL_GP0_OR_0x68000005              , ULL(0x68000005) ); // group0: all chiplets

CONST_UINT64_T( WRITE_ALL_FUNC_GP0_0x6B000000            , ULL(0x6B000000) ); // group3: all except PRV: GP0
CONST_UINT64_T( WRITE_ALL_FUNC_GP1_0x6B000001            , ULL(0x6B000001) ); // group3: all except PRV: GP1
CONST_UINT64_T( WRITE_ALL_FUNC_GP2_0x6B000002            , ULL(0x6B000002) ); // group3: all except PRV: GP2
CONST_UINT64_T( WRITE_ALL_FUNC_GP4_0x6B000003            , ULL(0x6B000003) ); // group3: all except PRV: GP4
CONST_UINT64_T( WRITE_ALL_FUNC_GP0_AND_0x6B000004        , ULL(0x6B000004) ); // group3: all except PRV: GP0 AND (for clearing bits)
CONST_UINT64_T( WRITE_ALL_FUNC_GP0_OR_0x6B000005         , ULL(0x6B000005) ); // group3: all except PRV: GP0 OR  (for setting bits)
CONST_UINT64_T( WRITE_ALL_FUNC_GP4_AND_0x6B000006        , ULL(0x6B000006) ); // group3: all except PRV: GP4 AND (for clearing bits)
CONST_UINT64_T( WRITE_ALL_FUNC_GP4_OR_0x6B000007         , ULL(0x6B000007) ); // group3: all except PRV: GP4 OR  (for setting bits)
CONST_UINT64_T( WRITE_ALL_FUNC_OPCG_CNTL0_0x6B030002     , ULL(0x6B030002) ); // group3: all except PRV: OPCG_CNTL0
CONST_UINT64_T( WRITE_ALL_FUNC_OPCG_CNTL1_0x6B030003     , ULL(0x6B030003) ); // group3: all except PRV: OPCG_CNTL1
CONST_UINT64_T( WRITE_ALL_FUNC_OPCG_CNTL2_0x6B030004     , ULL(0x6B030004) ); // group3: all except PRV: OPCG_CNTL2
CONST_UINT64_T( WRITE_ALL_FUNC_OPCG_CNTL3_0x6B030005     , ULL(0x6B030005) ); // group3: all except PRV: OPCG_CNTL3
CONST_UINT64_T( WRITE_ALL_FUNC_CLK_REGION_0x6B030006     , ULL(0x6B030006) ); // group3: all except PRV: CLK_REGION
CONST_UINT64_T( WRITE_ALL_FUNC_CLK_SCANSEL_0x6B030007    , ULL(0x6B030007) ); // group3: all except PRV: CLK_SCANSEL
CONST_UINT64_T( WRITE_ALL_FUNC_CLK_STATUS_0x6B030008     , ULL(0x6B030008) ); // group3: all except PRV: CLK_STATUS
CONST_UINT64_T( WRITE_ALL_FUNC_GP3_0x6B0F0012            , ULL(0x6B0F0012) ); // group3: all except PRV: GP3
CONST_UINT64_T( WRITE_ALL_FUNC_GP3_AND_0x6B0F0013        , ULL(0x6B0F0013) ); // group3: all except PRV: GP3 AND (for clearing bits)
CONST_UINT64_T( WRITE_ALL_FUNC_GP3_OR_0x6B0F0014         , ULL(0x6B0F0014) ); // group3: all except PRV: GP3 OR  (for setting bits)
CONST_UINT64_T( WRITE_ALL_PCB_SLAVE_ERRREG_0x6B0F001F    , ULL(0x6B0F001F) ); // group3: all except PRV:


//******************************************************************************/
//*********  ADDRESS PREFIXES FOR SUBROUTINE SCAN0_MODULE CALLS ****************/
//******************************************************************************/


CONST_UINT64_T( SCAN_ALLREGIONEXVITAL,              ULL(0x0FF00E0000000000) );
CONST_UINT64_T( SCAN_CLK_ALL,                       ULL(0x0FF00E0000000000) );
CONST_UINT64_T( SCAN_CLK_ALLEXDPLL,                 ULL(0x0FE00E0000000000) );
CONST_UINT64_T( SCAN_CLK_ALL_BUT_PLL,               ULL(0x0FE00E0000000000) );
CONST_UINT64_T( SCAN_CLK_PLL,                       ULL(0x00100E0000000000) );
CONST_UINT64_T( SCAN_CLK_CORE_ONLY,                 ULL(0x06000E0000000000) );


CONST_UINT64_T( SCAN_ALLSCANEXVITAL,                ULL(0x0FF00DCE00000000) );  // Looking to be deprecated
CONST_UINT64_T( SCAN_ALLSCANEXPRV,                  ULL(0x0FF00DCE00000000) );  // Looking to be deprecated
CONST_UINT64_T( SCAN_ALL_BUT_GPTRTIMEREP,           ULL(0x0FF00DCE00000000) );
CONST_UINT64_T( SCAN_ALL_BUT_VITALDPLLGPTRTIME,     ULL(0x0FE00DCE00000000) );
CONST_UINT64_T( SCAN_GPTR_TIME_REP,                 ULL(0x0FF0023000000000) );
CONST_UINT64_T( SCAN_PLL_GPTR,                      ULL(0x0010020000000000) );
CONST_UINT64_T( SCAN_PLL_BNDY_FUNC,                 ULL(0x0010080800000000) );
CONST_UINT64_T( SCAN_TIME_REP,                      ULL(0x0CF0003000000000) );

CONST_UINT64_T( SCAN_CORE_ALL,                      ULL(0x06000FFE00000000) );
CONST_UINT64_T( SCAN_CORE_ALL_BUT_GPTRTIMEREP,      ULL(0x06000DCE00000000) );
CONST_UINT64_T( SCAN_CORE_GPTR_TIME_REP,            ULL(0x0600023000000000) );
CONST_UINT64_T( SCAN_CORE_TIME_REP,                 ULL(0x0600003000000000) );

CONST_UINT64_T( SCAN_TP_ARRAY_INIT_REGIONS,         ULL(0x09000e0000000000) );
CONST_UINT64_T( SCAN_TP_REGIONS_EXCEPT_PIB_PCB,     ULL(0x09e00e0000000000) );
CONST_UINT64_T( SCAN_TP_SCAN_SELECTS,               ULL(0x09e00dce00000000) );

CONST_UINT8_T( SCAN_CHIPLET_STBY,                   ULL(0x00) );
CONST_UINT8_T( SCAN_CHIPLET_TP,                     ULL(0x01) );
CONST_UINT8_T( SCAN_CHIPLET_NEST,                   ULL(0x02) );
CONST_UINT8_T( SCAN_CHIPLET_MEM,                    ULL(0x03) );
CONST_UINT8_T( SCAN_CHIPLET_ALL,                    ULL(0x68) );
CONST_UINT8_T( SCAN_CHIPLET_GROUP1,                 ULL(0x69) );
CONST_UINT8_T( SCAN_CHIPLET_GROUP3,                 ULL(0x6B) );


CONST_UINT8_T( READ_OR_ALL_CHIPLETS,                ULL(0x40) );   // group 0: all chiplets
CONST_UINT8_T( READ_OR_ALL_FUNC_CHIPLETS,           ULL(0x43) );   // group 3: all functional chiplets
// CONST_UINT8_T( READ_AND_ALL_CHIPLETS,              ULL(0x48) );   // group 0: all chiplets
CONST_UINT8_T( READ_AND_ALL_FUNC_CHIPLETS,          ULL(0x4B) );   // group 3: all functional chiplets
CONST_UINT8_T( WRITE_ALL_CHIPLETS,                  ULL(0x68) );   // group 0: all chiplets
CONST_UINT8_T( WRITE_ALL_FUNC_CHIPLETS,             ULL(0x6B) );   // group 3: all functional chiplets

#endif


/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.

$Log: common_scom_addresses.H,v $
Revision 1.49  2014/01/30 16:19:26  mfred
Add some clock control regs for FFDC.

Revision 1.48  2013/11/04 14:31:08  kahnevan
Added missing addresses used by proc_perv_registers.xml

Revision 1.47  2013/07/10 15:30:36  jmcgill
add entries for SCOM debug resources

Revision 1.46  2013/05/06 21:03:10  jeshua
Added GENERIC_PCB_ERR_0x000F001F

Revision 1.45  2013/04/16 22:16:16  jeshua
Moved P8 cfam addresses and PIBMEM_REPAIR_0x00088007 to p8_scom_addresses.H

Revision 1.44  2013/03/18 19:43:27  jeshua
Removed OTPROM_SECURE_SWITCHES_0x00010005 because it's not common between P8 and Centaur. P8 code should use OTPC_M_SECURITY_SWITCH_0x00010005

Revision 1.43  2013/03/07 17:02:58  gweber
moved centaur-only SCAN_ constants to cen_scom_addresses.H

Revision 1.42  2013/03/06 12:43:59  gweber
Set CLOCK_REGION_PERV for scan0 perv

Revision 1.41  2013/02/20 17:44:46  cmolsen
Added CC error reg 30009.

Revision 1.40  2013/01/08 18:24:16  koenig
Updates - AK

Revision 1.39  2012/12/10 22:02:51  mfred
Adding addresses for interrupt macro.

Revision 1.38  2012/11/17 19:53:05  jmcgill
add trace status registers

Revision 1.37  2012/11/16 15:19:48  jeshua
Added defines for PLL scan0

Revision 1.36  2012/11/16 04:06:18  jmcgill
add FSI2PIB reset register

Revision 1.35  2012/10/30 15:28:50  koenig
New ECCB register for ecc enable - AK

Revision 1.34  2012/10/25 11:54:47  koenig
Added some hangcounter register - AK

Revision 1.33  2012/10/24 12:36:18  gweber
added FSI_DATA reg addresses

Revision 1.32  2012/10/23 12:45:50  koenig
Added Secure Switches in OTPROM - AK

Revision 1.31  2012/09/28 15:00:35  rkoester
add FSI SBE VITAL REG

Revision 1.30  2012/09/13 19:55:40  mfred
Move group 1 multicast definitions (EX chiplet) to p8_scom_addresses.H.

Revision 1.29  2012/09/13 19:42:43  mfred
fix misleading comment.

Revision 1.28  2012/09/12 17:10:18  jmcgill
add remainder of mailbox scratch registers

Revision 1.27  2012/08/17 16:46:50  mfred
Committing common PLL lock address for EX cores.

Revision 1.26  2012/08/16 13:06:19  gweber
added remaining CFAM-addresses 28xx

Revision 1.25  2012/08/11 22:20:37  jmcgill
add multicast GP0 OR address (all chiplets)

Revision 1.24  2012/08/08 13:28:18  gweber
added CFAM-addresses 28xx

Revision 1.23  2012/08/07 09:09:43  koenig
Added TP skewadjust register - AK

Revision 1.22  2012/07/24 15:52:06  koenig
Added EX GP3 OR codepoint - AK

Revision 1.21  2012/07/06 09:49:48  rkoester
add clock region / scan region for tp_arrayinit, make this common

Revision 1.20  2012/07/03 09:38:25  rkoester
add address for Centaur Scan0

Revision 1.19  2012/07/02 16:43:47  rkoester
add vector for scan_no_pll

Revision 1.18  2012/06/25 17:52:34  bcbrock
Modified proc_sbe_decompress_scan.S: 1) Removed comments and code related to
the "polling" protocol. 2) Added a final SCOM to always issue a "setpulse"
after acanning.

Revision 1.17  2012/06/20 14:49:29  rkoester
add plllock register

Revision 1.16  2012/06/17 20:25:57  jmcgill
update trace SCOM addresses

Revision 1.15  2012/06/14 14:21:03  koenig
Added MBOX scratch and I2CMS status - AK

Revision 1.14  2012/06/11 16:14:56  rkoester
FSI GP8 CFAM address added

Revision 1.13  2012/06/05 17:05:41  mfred
Added constants for reading PCB interrupt regs.

Revision 1.12  2012/05/31 12:15:24  stillgs
Update constant names for (ex) scan0 routines that do real scanning

Revision 1.11  2012/05/23 17:03:25  rkoester
scan0 vectors for scan0 module modified, Option 1 wrong

Revision 1.10  2012/04/27 15:08:29  koenig
Added GENERIC_CLK_SYNC - AK

Revision 1.9  2012/04/19 22:05:35  koenig
Added AND write to EX MCGR GP3 - AK

Revision 1.8  2012/04/16 23:55:34  bcbrock
Corrected problems related to C/C++ and 32-bit/64-bit portability and Host
Boot after initial review by FW team.

o Renamed fapi_sbe_common.h to fapi_sbe_common.H
o Renamed p8_scan_compression.[ch] to .[CH] since these are for use by C++
  procedures only (no requirement to execute on OCC).
o Modified sbe_xip_image.c to use the C99 standard way to print uint64_t
  variables.
o Added __cplusplus guards to sbe_xip_image.h

Revision 1.7  2012/04/04 11:41:15  koenig
Added TP hangcounter 6 and MBOX_FSIGP8

Revision 1.6  2012/03/26 15:16:52  stillgs
Added SCAN_CORE_ALL, SCAN_CORE_GPTR_TIME_REP, SCAN_CORE_TIME_REP constants for use by Sleep Exit

Revision 1.5  2012/02/10 23:09:50  jmcgill
add trace array addresses

Revision 1.4  2012/01/30 10:07:53  gweber
changed SCAN_CHIPLET_ALL to 0x68

Revision 1.3  2012/01/27 09:36:42  koenig
Added a region vector for scan0 module

Revision 1.2  2012/01/24 21:59:39  mfred
Moved common multicast address constants to common_scom_accresses.H

Revision 1.1  2012/01/06 22:21:10  jmcgill
initial release




*/
