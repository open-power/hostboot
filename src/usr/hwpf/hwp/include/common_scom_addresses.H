//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/HWPs/common_scom_addresses.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
// $Id: common_scom_addresses.H,v 1.1 2012/01/06 22:21:10 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/common_scom_addresses.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
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

#include "fapi_sbe_common.h"


/******************************************************************************/
/**********************************  CHIPLET  *********************************/
/******************************************************************************/
//      use for lpcs P0, <chipletID>
CONST_UINT64_T( STBY_CHIPLET_0x00000000               , ULL(0x00000000) );
CONST_UINT64_T( TP_CHIPLET_0x01000000                 , ULL(0x01000000) );
CONST_UINT64_T( NEST_CHIPLET_0x02000000               , ULL(0x02000000) );


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
//      GENERIC CLOCK CONTROL
//------------------------------------------------------------------------------
CONST_UINT64_T( GENERIC_OPCG_CNTL0_0x00030002         , ULL(0x00030002) );
CONST_UINT64_T( GENERIC_OPCG_CNTL1_0x00030003         , ULL(0x00030003) );
CONST_UINT64_T( GENERIC_OPCG_CNTL2_0x00030004         , ULL(0x00030004) );
CONST_UINT64_T( GENERIC_OPCG_CNTL3_0x00030005         , ULL(0x00030005) );
CONST_UINT64_T( GENERIC_CLK_REGION_0x00030006         , ULL(0x00030006) );
CONST_UINT64_T( GENERIC_CLK_SCANSEL_0x00030007        , ULL(0x00030007) );
CONST_UINT64_T( GENERIC_CLK_STATUS_0x00030008         , ULL(0x00030008) );
CONST_UINT64_T( GENERIC_CLK_SCANDATA0_0x00038000      , ULL(0x00038000) );

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
CONST_UINT32_T( CFAM_FSI_STATUS_0x00001007            , ULL(0x00001007) );
CONST_UINT32_T( CFAM_FSI_GP1_0x00001010               , ULL(0x00001010) );
CONST_UINT32_T( CFAM_FSI_GP2_0x00001011               , ULL(0x00001011) );
CONST_UINT32_T( CFAM_FSI_GP3_0x00001012               , ULL(0x00001012) );
CONST_UINT32_T( CFAM_FSI_GP4_0x00001013               , ULL(0x00001013) );
CONST_UINT32_T( CFAM_FSI_GP5_0x00001014               , ULL(0x00001014) );
CONST_UINT32_T( CFAM_FSI_GP6_0x00001015               , ULL(0x00001015) );
CONST_UINT32_T( CFAM_FSI_GP7_0x00001016               , ULL(0x00001016) );
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
CONST_UINT64_T( MBOX_OSC_S1_0x00050019                , ULL(0x00050019) );
CONST_UINT64_T( MBOX_OSC_S2_0x0005001A                , ULL(0x0005001A) );
CONST_UINT64_T( MBOX_GP3MIR_0x0005001B                , ULL(0x0005001B) );
CONST_UINT64_T( MBOX_SBEVITAL_0x0005001C              , ULL(0x0005001C) );

//------------------------------------------------------------------------------
//      I2C MASTER (MEMS0)
//------------------------------------------------------------------------------
CONST_UINT64_T( I2CMS_MEMS0_CONTROL_0x000A0000        , ULL(0x000A0000) );
CONST_UINT64_T( I2CMS_MEMS0_RESET_0x000A0001          , ULL(0x000A0001) );
CONST_UINT64_T( I2CMS_MEMS0_STATUS_0x000A0002         , ULL(0x000A0002) );
CONST_UINT64_T( I2CMS_MEMS0_DATA_0x000A0003           , ULL(0x000A0003) );
CONST_UINT64_T( I2CMS_MEMS0_COMMAND_0x000A0005        , ULL(0x000A0005) );

//------------------------------------------------------------------------------
//      PCB MASTER
//------------------------------------------------------------------------------
CONST_UINT64_T( PCBMS_0x000F0000                      , ULL(0x000F0000) );
CONST_UINT64_T( PCBMS_DEVICE_ID_0x000F000F            , ULL(0x000F000F) );
CONST_UINT64_T( MASTER_PCB_INT_0x000F001A             , ULL(0x000F001A) );
CONST_UINT64_T( PRV_PIB_PCBMS_RESET_REG_0x000F001D    , ULL(0x000F001D) );
CONST_UINT64_T( MASTER_PCB_ERR_0x000F001F             , ULL(0x000F001F) );

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
//      TP ITR
//------------------------------------------------------------------------------
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
CONST_UINT64_T( TP_HANG_P1_0x010F0021                  , ULL(0x010F0021) );     // PRV: setup hang pulse register0
CONST_UINT64_T( TP_HANG_P2_0x010F0022                  , ULL(0x010F0022) );     // PRV: setup hang pulse register1
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
//      NEST CLOCK CONTROL
//------------------------------------------------------------------------------
CONST_UINT64_T( NEST_OPCG_CNTL0_0x02030002            , ULL(0x02030002) );
CONST_UINT64_T( NEST_OPCG_CNTL1_0x02030003            , ULL(0x02030003) );
CONST_UINT64_T( NEST_OPCG_CNTL2_0x02030004            , ULL(0x02030004) );
CONST_UINT64_T( NEST_OPCG_CNTL3_0x02030005            , ULL(0x02030005) );
CONST_UINT64_T( NEST_CLK_REGION_0x02030006            , ULL(0x02030006) );
CONST_UINT64_T( NEST_CLK_SCANSEL_0x02030007           , ULL(0x02030007) );
CONST_UINT64_T( NEST_CLK_STATUS_0x02030008            , ULL(0x02030008) );

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
CONST_UINT64_T( NEST_HANG_PRE_0x020F0028              , ULL(0x020F0028) );     // NEST (PB): setup hang precounter (HEX:01)


//******************************************************************************/
//*********  ADDRESS PREFIXES FOR SUBROUTINE SCAN0_MODULE CALLS ****************/
//******************************************************************************/
CONST_UINT64_T( SCAN_ALLSCANEXVITAL,              ULL(0x0FF00FFE00000000) );
CONST_UINT64_T( SCAN_ALLSCANEXPRV,                ULL(0x0FF00DCE00000000) );
CONST_UINT64_T( SCAN_GPTR_TIME_REP,               ULL(0x0FF0023000000000) );
CONST_UINT64_T( SCAN_TIME_REP,                    ULL(0x0CF0003000000000) );

CONST_UINT8_T( SCAN_CHIPLET_TP,                   ULL(0x01) );
CONST_UINT8_T( SCAN_CHIPLET_NEST,                 ULL(0x02) );
CONST_UINT8_T( SCAN_CHIPLET_MEM,                  ULL(0x03) );
CONST_UINT8_T( SCAN_CHIPLET_ALL,                  ULL(0x69) );
CONST_UINT8_T( SCAN_CHIPLET_GROUP3,               ULL(0x6B) );


#endif


/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.

$Log: common_scom_addresses.H,v $
Revision 1.1  2012/01/06 22:21:10  jmcgill
initial release




*/
