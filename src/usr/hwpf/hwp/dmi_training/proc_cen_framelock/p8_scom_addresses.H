//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/HWPs/dmi_training/p8_scom_addresses.H $
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
// $Id: p8_scom_addresses.H,v 1.50 2012/01/06 22:20:53 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/p8_scom_addresses.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE : p8_scom_addresses.H
// *! DESCRIPTION : Defines for P8 scom addresses
// *! OWNER NAME  : Jeshua Smith  Email: jeshua@us.ibm.com
// *! BACKUP NAME :               Email:       @us.ibm.com
// #! ADDITIONAL COMMENTS :
//
// The purpose of this header is to define scom addresses for use by procedures.
// This will help catch address typos at compile time, and will make it easy
// to track down which procedures use each address
//

#ifndef P8_SCOM_ADDRESSES
#define P8_SCOM_ADDRESSES

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

#include "common_scom_addresses.H"
#include "fapi_sbe_common.h"

/******************************************************************************/
/**********************************  CHIPLET  *********************************/
/******************************************************************************/
//      use for lpcs P0, <chipletID>
CONST_UINT64_T( X_BUS_CHIPLET_0x04000000              , ULL(0x04000000) );
CONST_UINT64_T( PCIE_CHIPLET_0x08000000               , ULL(0x08000000) );
CONST_UINT64_T( A_BUS_CHIPLET_0x09000000              , ULL(0x09000000) );
// EX00_CHIPLET - EX15_CHIPLET defined in the EX CHIPLET section
// "Multicast" chiplets
CONST_UINT64_T( ALL_CHIPLETS_OR_0x40000000            , ULL(0x40000000) );
CONST_UINT64_T( ALL_CHIPLETS_AND_0x48000000           , ULL(0x48000000) );
CONST_UINT64_T( ALL_CHIPLETS_BITX_0x50000000          , ULL(0x50000000) );
CONST_UINT64_T( ALL_CHIPLETS_COMP_0x60000000          , ULL(0x60000000) );
CONST_UINT64_T( ALL_CHIPLETS_WRITE_0x68000000         , ULL(0x68000000) );

CONST_UINT64_T( ALL_EXS_OR_0x41000000                 , ULL(0x41000000) );
CONST_UINT64_T( ALL_EXS_AND_0x49000000                , ULL(0x49000000) );
CONST_UINT64_T( ALL_EXS_BITX_0x51000000               , ULL(0x51000000) );
CONST_UINT64_T( ALL_EXS_COMP_0x61000000               , ULL(0x61000000) );
CONST_UINT64_T( ALL_EXS_WRITE_0x69000000              , ULL(0x69000000) );

CONST_UINT64_T( ALL_CORES_OR_0x42000000               , ULL(0x42000000) );
CONST_UINT64_T( ALL_CORES_AND_0x4A000000              , ULL(0x4A000000) );
CONST_UINT64_T( ALL_CORES_BITX_0x52000000             , ULL(0x52000000) );
CONST_UINT64_T( ALL_CORES_COMP_0x62000000             , ULL(0x62000000) );
CONST_UINT64_T( ALL_CORES_WRITE_0x6A000000            , ULL(0x6A000000) );


/******************************************************************************/
/********************************  TP CHIPLET  ********************************/
/******************************************************************************/

//------------------------------------------------------------------------------
//      PORE-GPE0
//------------------------------------------------------------------------------
CONST_UINT64_T( PORE_GPE0_0x00060000                   , ULL(0x00060000) );
CONST_UINT64_T( PORE_GPE0_STATUS_0x00060000            , ULL(0x00060000) );
CONST_UINT64_T( PORE_GPE0_CONTROL_0x00060001           , ULL(0x00060001) );
CONST_UINT64_T( PORE_GPE0_RESET_0x00060002             , ULL(0x00060002) );
CONST_UINT64_T( PORE_GPE0_ERROR_MASK_0x00060003        , ULL(0x00060003) );
CONST_UINT64_T( PORE_GPE0_PRV_BASE_ADDRESS0_0x00060004 , ULL(0x00060004) );
CONST_UINT64_T( PORE_GPE0_PRV_BASE_ADDRESS1_0x00060005 , ULL(0x00060005) );
CONST_UINT64_T( PORE_GPE0_OCI_BASE_ADDRESS0_0x00060006 , ULL(0x00060006) );
CONST_UINT64_T( PORE_GPE0_OCI_BASE_ADDRESS1_0x00060007 , ULL(0x00060007) );
CONST_UINT64_T( PORE_GPE0_TABLE_BASE_ADDR_0x00060008   , ULL(0x00060008) );
CONST_UINT64_T( PORE_GPE0_EXE_TRIGGER_0x00060009       , ULL(0x00060009) );
CONST_UINT64_T( PORE_GPE0_SCRATCH0_0x0006000A          , ULL(0x0006000A) );
CONST_UINT64_T( PORE_GPE0_SCRATCH1_0x0006000B          , ULL(0x0006000B) );
CONST_UINT64_T( PORE_GPE0_SCRATCH2_0x0006000C          , ULL(0x0006000C) );
CONST_UINT64_T( PORE_GPE0_IBUF_01_0x0006000D           , ULL(0x0006000D) );
CONST_UINT64_T( PORE_GPE0_IBUF_2_0x0006000E            , ULL(0x0006000E) );
CONST_UINT64_T( PORE_GPE0_DBG0_0x0006000F              , ULL(0x0006000F) );
CONST_UINT64_T( PORE_GPE0_DBG1_0x00060010              , ULL(0x00060010) );
CONST_UINT64_T( PORE_GPE0_PC_STACK0_0x00060011         , ULL(0x00060011) );
CONST_UINT64_T( PORE_GPE0_PC_STACK1_0x00060012         , ULL(0x00060012) );
CONST_UINT64_T( PORE_GPE0_PC_STACK2_0x00060013         , ULL(0x00060013) );
CONST_UINT64_T( PORE_GPE0_ID_FLAGS_0x00060014          , ULL(0x00060014) );
CONST_UINT64_T( PORE_GPE0_DATA0_0x00060015             , ULL(0x00060015) );
CONST_UINT64_T( PORE_GPE0_MEMORY_RELOC_0x00060016      , ULL(0x00060016) );
CONST_UINT64_T( PORE_GPE0_I2C_E0_PARAM_0x00060017      , ULL(0x00060017) );
CONST_UINT64_T( PORE_GPE0_I2C_E1_PARAM_0x00060018      , ULL(0x00060018) );
CONST_UINT64_T( PORE_GPE0_I2C_E2_PARAM_0x00060019      , ULL(0x00060019) );

//------------------------------------------------------------------------------
//      PORE-GPE1
//------------------------------------------------------------------------------
CONST_UINT64_T( PORE_GPE1_0x00060020                   , ULL(0x00060020) );
CONST_UINT64_T( PORE_GPE1_STATUS_0x00060020            , ULL(0x00060020) );
CONST_UINT64_T( PORE_GPE1_CONTROL_0x00060021           , ULL(0x00060021) );
CONST_UINT64_T( PORE_GPE1_RESET_0x00060022             , ULL(0x00060022) );
CONST_UINT64_T( PORE_GPE1_ERROR_MASK_0x00060023        , ULL(0x00060023) );
CONST_UINT64_T( PORE_GPE1_PRV_BASE_ADDRESS0_0x00060024 , ULL(0x00060024) );
CONST_UINT64_T( PORE_GPE1_PRV_BASE_ADDRESS1_0x00060025 , ULL(0x00060025) );
CONST_UINT64_T( PORE_GPE1_OCI_BASE_ADDRESS0_0x00060026 , ULL(0x00060026) );
CONST_UINT64_T( PORE_GPE1_OCI_BASE_ADDRESS1_0x00060027 , ULL(0x00060027) );
CONST_UINT64_T( PORE_GPE1_TABLE_BASE_ADDR_0x00060028   , ULL(0x00060028) );
CONST_UINT64_T( PORE_GPE1_EXE_TRIGGER_0x00060029       , ULL(0x00060029) );
CONST_UINT64_T( PORE_GPE1_SCRATCH0_0x0006002A          , ULL(0x0006002A) );
CONST_UINT64_T( PORE_GPE1_SCRATCH1_0x0006002B          , ULL(0x0006002B) );
CONST_UINT64_T( PORE_GPE1_SCRATCH2_0x0006002C          , ULL(0x0006002C) );
CONST_UINT64_T( PORE_GPE1_IBUF_01_0x0006002D           , ULL(0x0006002D) );
CONST_UINT64_T( PORE_GPE1_IBUF_2_0x0006002E            , ULL(0x0006002E) );
CONST_UINT64_T( PORE_GPE1_DBG0_0x0006002F              , ULL(0x0006002F) );
CONST_UINT64_T( PORE_GPE1_DBG1_0x00060030              , ULL(0x00060030) );
CONST_UINT64_T( PORE_GPE1_PC_STACK0_0x00060031         , ULL(0x00060031) );
CONST_UINT64_T( PORE_GPE1_PC_STACK1_0x00060032         , ULL(0x00060032) );
CONST_UINT64_T( PORE_GPE1_PC_STACK2_0x00060033         , ULL(0x00060033) );
CONST_UINT64_T( PORE_GPE1_ID_FLAGS_0x00060034          , ULL(0x00060034) );
CONST_UINT64_T( PORE_GPE1_DATA0_0x00060035             , ULL(0x00060035) );
CONST_UINT64_T( PORE_GPE1_MEMORY_RELOC_0x00060036      , ULL(0x00060036) );
CONST_UINT64_T( PORE_GPE1_I2C_E0_PARAM_0x00060037      , ULL(0x00060037) );
CONST_UINT64_T( PORE_GPE1_I2C_E1_PARAM_0x00060038      , ULL(0x00060038) );
CONST_UINT64_T( PORE_GPE1_I2C_E2_PARAM_0x00060039      , ULL(0x00060039) );

//------------------------------------------------------------------------------
//      PORE-SLW
//------------------------------------------------------------------------------
CONST_UINT64_T( PORE_SLW_0x00068000                   , ULL(0x00068000) );
CONST_UINT64_T( PORE_SLW_STATUS_0x00068000            , ULL(0x00068000) );
CONST_UINT64_T( PORE_SLW_CONTROL_0x00068001           , ULL(0x00068001) );
CONST_UINT64_T( PORE_SLW_RESET_0x00068002             , ULL(0x00068002) );
CONST_UINT64_T( PORE_SLW_ERROR_MASK_0x00068003        , ULL(0x00068003) );
CONST_UINT64_T( PORE_SLW_PRV_BASE_ADDRESS0_0x00068004 , ULL(0x00068004) );
CONST_UINT64_T( PORE_SLW_PRV_BASE_ADDRESS1_0x00068005 , ULL(0x00068005) );
CONST_UINT64_T( PORE_SLW_OCI_BASE_ADDRESS0_0x00068006 , ULL(0x00068006) );
CONST_UINT64_T( PORE_SLW_OCI_BASE_ADDRESS1_0x00068007 , ULL(0x00068007) );
CONST_UINT64_T( PORE_SLW_TABLE_BASE_ADDR_0x00068008   , ULL(0x00068008) );
CONST_UINT64_T( PORE_SLW_EXE_TRIGGER_0x00068009       , ULL(0x00068009) );
CONST_UINT64_T( PORE_SLW_SCRATCH0_0x0006800A          , ULL(0x0006800A) );
CONST_UINT64_T( PORE_SLW_SCRATCH1_0x0006800B          , ULL(0x0006800B) );
CONST_UINT64_T( PORE_SLW_SCRATCH2_0x0006800C          , ULL(0x0006800C) );
CONST_UINT64_T( PORE_SLW_IBUF_01_0x0006800D           , ULL(0x0006800D) );
CONST_UINT64_T( PORE_SLW_IBUF_2_0x0006800E            , ULL(0x0006800E) );
CONST_UINT64_T( PORE_SLW_DBG0_0x0006800F              , ULL(0x0006800F) );
CONST_UINT64_T( PORE_SLW_DBG1_0x00068010              , ULL(0x00068010) );
CONST_UINT64_T( PORE_SLW_PC_STACK0_0x00068011         , ULL(0x00068011) );
CONST_UINT64_T( PORE_SLW_PC_STACK1_0x00068012         , ULL(0x00068012) );
CONST_UINT64_T( PORE_SLW_PC_STACK2_0x00068013         , ULL(0x00068013) );
CONST_UINT64_T( PORE_SLW_ID_FLAGS_0x00068014          , ULL(0x00068014) );
CONST_UINT64_T( PORE_SLW_DATA0_0x00068015             , ULL(0x00068015) );
CONST_UINT64_T( PORE_SLW_MEMORY_RELOC_0x00068016      , ULL(0x00068016) );
CONST_UINT64_T( PORE_SLW_I2C_E0_PARAM_0x00068017      , ULL(0x00068017) );
CONST_UINT64_T( PORE_SLW_I2C_E1_PARAM_0x00068018      , ULL(0x00068018) );
CONST_UINT64_T( PORE_SLW_I2C_E2_PARAM_0x00068019      , ULL(0x00068019) );

//------------------------------------------------------------------------------
//      OCC/OCB
//------------------------------------------------------------------------------
CONST_UINT64_T( OCC_CONTROL_0x0006B000                , ULL(0x0006B000) );
CONST_UINT64_T( OCC_CONTROL_AND_0x0006B001            , ULL(0x0006B001) );
CONST_UINT64_T( OCC_CONTROL_OR_0x0006B002             , ULL(0x0006B002) );
CONST_UINT64_T( OCC_DEBUG_MODE_0x0006B003             , ULL(0x0006B003) );

CONST_UINT64_T( OCB0_ADDRESS_0x0006B010               , ULL(0x0006B010) );
CONST_UINT64_T( OCB0_STATUS_CONTROL_0x0006B011        , ULL(0x0006B011) );
CONST_UINT64_T( OCB0_STATUS_CONTROL_AND_0x0006B012    , ULL(0x0006B012) );
CONST_UINT64_T( OCB0_STATUS_CONTROL_OR_0x0006B013     , ULL(0x0006B013) );
CONST_UINT64_T( OCB0_ERROR_STATUS_0x0006B014          , ULL(0x0006B014) );
CONST_UINT64_T( OCB0_DATA_0x0006B015                  , ULL(0x0006B015) );

CONST_UINT64_T( OCB1_ADDRESS_0x0006B030               , ULL(0x0006B030) );
CONST_UINT64_T( OCB1_STATUS_CONTROL_0x0006B031        , ULL(0x0006B031) );
CONST_UINT64_T( OCB1_STATUS_CONTROL_AND_0x0006B032    , ULL(0x0006B032) );
CONST_UINT64_T( OCB1_STATUS_CONTROL_OR_0x0006B032     , ULL(0x0006B033) );
CONST_UINT64_T( OCB1_ERROR_STATUS_0x0006B034          , ULL(0x0006B034) );
CONST_UINT64_T( OCB1_DATA_0x0006B035                  , ULL(0x0006B035) );

CONST_UINT64_T( OCB2_ADDRESS_0x0006B050               , ULL(0x0006B050) );
CONST_UINT64_T( OCB2_STATUS_CONTROL_0x0006B051        , ULL(0x0006B051) );
CONST_UINT64_T( OCB2_STATUS_CONTROL_AND_0x0006B052    , ULL(0x0006B052) );
CONST_UINT64_T( OCB2_STATUS_CONTROL_OR_0x0006B052     , ULL(0x0006B053) );
CONST_UINT64_T( OCB2_ERROR_STATUS_0x0006B054          , ULL(0x0006B054) );
CONST_UINT64_T( OCB2_DATA_0x0006B055                  , ULL(0x0006B055) );

CONST_UINT64_T( OCB3_ADDRESS_0x0006B070               , ULL(0x0006B070) );
CONST_UINT64_T( OCB3_STATUS_CONTROL_0x0006B071        , ULL(0x0006B071) );
CONST_UINT64_T( OCB3_STATUS_CONTROL_AND_0x0006B072    , ULL(0x0006B072) );
CONST_UINT64_T( OCB3_STATUS_CONTROL_OR_0x0006B072     , ULL(0x0006B073) );
CONST_UINT64_T( OCB3_ERROR_STATUS_0x0006B074          , ULL(0x0006B074) );
CONST_UINT64_T( OCB3_DATA_0x0006B075                  , ULL(0x0006B075) );

//------------------------------------------------------------------------------
//      SPIADC
//------------------------------------------------------------------------------
CONST_UINT64_T( SPIADC_0x00070000                     , ULL(0x00070000) );

//------------------------------------------------------------------------------
//      PIB-ATTACHED MEMORY
//------------------------------------------------------------------------------
CONST_UINT64_T( PIBMEM0_0x00080000                    , ULL(0x00080000) );

//------------------------------------------------------------------------------
//      I2C MASTER (MEMS1)
//------------------------------------------------------------------------------
CONST_UINT64_T( I2CMS_MEMS1_CONTROL_0x000A0020        , ULL(0x000A0020) );
CONST_UINT64_T( I2CMS_MEMS1_RESET_0x000A0021          , ULL(0x000A0021) );
CONST_UINT64_T( I2CMS_MEMS1_STATUS_0x000A0022         , ULL(0x000A0022) );
CONST_UINT64_T( I2CMS_MEMS1_DATA_0x000A0023           , ULL(0x000A0023) );
CONST_UINT64_T( I2CMS_MEMS1_COMMAND_0x000A0025        , ULL(0x000A0025) );

//------------------------------------------------------------------------------
//      I2C MASTER (PCI)
//------------------------------------------------------------------------------
CONST_UINT64_T( I2CMS_PCI_0x000A0040                  , ULL(0x000A0040) );
CONST_UINT64_T( I2CMS_PCI_CONTROL_0x000A0040          , ULL(0x000A0040) );
CONST_UINT64_T( I2CMS_PCI_RESET_0x000A0041            , ULL(0x000A0041) );
CONST_UINT64_T( I2CMS_PCI_STATUS_0x000A0042           , ULL(0x000A0042) );
CONST_UINT64_T( I2CMS_PCI_DATA_0x000A0043             , ULL(0x000A0043) );
CONST_UINT64_T( I2CMS_PCI_COMMAND_0x000A0045          , ULL(0x000A0045) );

//------------------------------------------------------------------------------
//      PORE-SBE
//------------------------------------------------------------------------------
CONST_UINT64_T( PORE_SBE_0x000E0000                   , ULL(0x000E0000) );
CONST_UINT64_T( PORE_SBE_STATUS_0x000E0000            , ULL(0x000E0000) );
CONST_UINT64_T( PORE_SBE_CONTROL_0x000E0001           , ULL(0x000E0001) );
CONST_UINT64_T( PORE_SBE_RESET_0x000E0002             , ULL(0x000E0002) );
CONST_UINT64_T( PORE_SBE_ERROR_MASK_0x000E0003        , ULL(0x000E0003) );
CONST_UINT64_T( PORE_SBE_PRV_BASE_ADDRESS0_0x000E0004 , ULL(0x000E0004) );
CONST_UINT64_T( PORE_SBE_PRV_BASE_ADDRESS1_0x000E0005 , ULL(0x000E0005) );
CONST_UINT64_T( PORE_SBE_OCI_BASE_ADDRESS0_0x000E0006 , ULL(0x000E0006) );
CONST_UINT64_T( PORE_SBE_OCI_BASE_ADDRESS1_0x000E0007 , ULL(0x000E0007) );
CONST_UINT64_T( PORE_SBE_TABLE_BASE_ADDR_0x000E0008   , ULL(0x000E0008) );
CONST_UINT64_T( PORE_SBE_EXE_TRIGGER_0x000E0009       , ULL(0x000E0009) );
CONST_UINT64_T( PORE_SBE_SCRATCH0_0x000E000A          , ULL(0x000E000A) );
CONST_UINT64_T( PORE_SBE_SCRATCH1_0x000E000B          , ULL(0x000E000B) );
CONST_UINT64_T( PORE_SBE_SCRATCH2_0x000E000C          , ULL(0x000E000C) );
CONST_UINT64_T( PORE_SBE_IBUF_01_0x000E000D           , ULL(0x000E000D) );
CONST_UINT64_T( PORE_SBE_IBUF_2_0x000E000E            , ULL(0x000E000E) );
CONST_UINT64_T( PORE_SBE_DBG0_0x000E000F              , ULL(0x000E000F) );
CONST_UINT64_T( PORE_SBE_DBG1_0x000E0010              , ULL(0x000E0010) );
CONST_UINT64_T( PORE_SBE_PC_STACK0_0x000E0011         , ULL(0x000E0011) );
CONST_UINT64_T( PORE_SBE_PC_STACK1_0x000E0012         , ULL(0x000E0012) );
CONST_UINT64_T( PORE_SBE_PC_STACK2_0x000E0013         , ULL(0x000E0013) );
CONST_UINT64_T( PORE_SBE_ID_FLAGS_0x000E0014          , ULL(0x000E0014) );
CONST_UINT64_T( PORE_SBE_DATA0_0x000E0015             , ULL(0x000E0015) );
CONST_UINT64_T( PORE_SBE_MEMORY_RELOC_0x000E0016      , ULL(0x000E0016) );
CONST_UINT64_T( PORE_SBE_I2C_E0_PARAM_0x000E0017      , ULL(0x000E0017) );
CONST_UINT64_T( PORE_SBE_I2C_E1_PARAM_0x000E0018      , ULL(0x000E0018) );
CONST_UINT64_T( PORE_SBE_I2C_E2_PARAM_0x000E0019      , ULL(0x000E0019) );

//------------------------------------------------------------------------------
//      TP SCOM
//         ring 1  = Trace
//         ring 2  = OCC
//         ring 3  = PIB
//         ring 15 = OCCSEC
//------------------------------------------------------------------------------


/******************************************************************************/
/*******************************  NEST CHIPLET  *******************************/
/******************************************************************************/

//------------------------------------------------------------------------------
//      NEST SCOM
//         ring  1 = Trace
//         ring  2 = TCBR
//         ring  3 = PB
//         ring  6 = MCL
//                   MC0 MCS0   = 0x02011800
//                   MC0 MCS1   = 0x02011880
//                   MC1 MCS0   = 0x02011900
//                   MC1 MCS0   = 0x02011980
//                   IOMC0      = 0x02011A00
//         ring  7 = MCR
//                   MC2 MCS0   = 0x02011C00
//                   MC2 MCS1   = 0x02011C80
//                   MC3 MCS0   = 0x02011D00
//                   MC3 MCS1   = 0x02011D80
//                   IOMC1      = 0x02011E00
//         ring  8 = PCIS0
//         ring  9 = PCIS1
//         ring 10 = PCIS2
//         ring 11 = PCIS3
//         ring 12 = NX
//         ring 13 = MCD
//         ring 15 = TCBRSEC
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//      POWERBUS ACCESS BRIDGE (PBA)
//------------------------------------------------------------------------------
CONST_UINT64_T( PBA_FIR_0x02010840                    , ULL(0x02010840) );
CONST_UINT64_T( PBA_FIR_AND_0x02010841                , ULL(0x02010841) );
CONST_UINT64_T( PBA_FIR_OR_0x02010842                 , ULL(0x02010842) );
CONST_UINT64_T( PBA_FIR_ACTION0_0x02010843            , ULL(0x02010843) );
CONST_UINT64_T( PBA_FIR_ACTION1_0x02010844            , ULL(0x02010844) );
CONST_UINT64_T( PBA_FIR_MASK_0x02010846               , ULL(0x02010846) );
CONST_UINT64_T( PBA_FIR_MASK_AND_0x02010847           , ULL(0x02010847) );
CONST_UINT64_T( PBA_FIR_MASK_OR_0x02010848            , ULL(0x02010848) );
CONST_UINT64_T( PBA_OCC_ACTION_0x0201084A             , ULL(0x0201084A) );
CONST_UINT64_T( PBA_CONFIG_0x0201084B                 , ULL(0x0201084B) );
CONST_UINT64_T( PBA_ERR_RPT0_0x0201084C               , ULL(0x0201084C) );
CONST_UINT64_T( PBA_ERR_RPT1_0x0201084D               , ULL(0x0201084D) );
CONST_UINT64_T( PBA_ERR_RPT2_0x0201084E               , ULL(0x0201084E) );
CONST_UINT64_T( PBA_RBUFVAL0_0x02010850               , ULL(0x02010850) );
CONST_UINT64_T( PBA_RBUFVAL1_0x02010851               , ULL(0x02010851) );
CONST_UINT64_T( PBA_RBUFVAL2_0x02010852               , ULL(0x02010852) );
CONST_UINT64_T( PBA_RBUFVAL3_0x02010853               , ULL(0x02010853) );
CONST_UINT64_T( PBA_RBUFVAL4_0x02010854               , ULL(0x02010854) );
CONST_UINT64_T( PBA_RBUFVAL5_0x02010855               , ULL(0x02010855) );
CONST_UINT64_T( PBA_WBUFVAL0_0x02010858               , ULL(0x02010858) );
CONST_UINT64_T( PBA_WBUFVAL1_0x02010859               , ULL(0x02010859) );

CONST_UINT64_T( PBA_MODE_0x00064000                   , ULL(0x00064000) );
CONST_UINT64_T( PBA_SLVRST_0x00064001                 , ULL(0x00064001) );
CONST_UINT64_T( PBA_SLVCTL0_0x00064004                , ULL(0x00064004) );
CONST_UINT64_T( PBA_SLVCTL1_0x00064005                , ULL(0x00064005) );
CONST_UINT64_T( PBA_SLVCTL2_0x00064006                , ULL(0x00064006) );
CONST_UINT64_T( PBA_SLVCTL3_0x00064007                , ULL(0x00064007) );
CONST_UINT64_T( PBA_BCDE_CTL_0x00064010               , ULL(0x00064010) );
CONST_UINT64_T( PBA_BCDE_SET_0x00064011               , ULL(0x00064011) );
CONST_UINT64_T( PBA_BCDE_STAT_0x00064012              , ULL(0x00064012) );
CONST_UINT64_T( PBA_BCDE_PBADR_0x00064013             , ULL(0x00064013) );
CONST_UINT64_T( PBA_BCDE_OCIBAR_0x00064014            , ULL(0x00064014) );
CONST_UINT64_T( PBA_BCUE_CTL_0x00064015               , ULL(0x00064015) );
CONST_UINT64_T( PBA_BCUE_SET_0x00064016               , ULL(0x00064016) );
CONST_UINT64_T( PBA_BCUE_STAT_0x00064017              , ULL(0x00064017) );
CONST_UINT64_T( PBA_BCUE_PBADR_0x00064018             , ULL(0x00064018) );
CONST_UINT64_T( PBA_BCUE_OCIBAR_0x00064019            , ULL(0x00064019) );
CONST_UINT64_T( PBA_PBOCR0_0x00064020                 , ULL(0x00064020) );
CONST_UINT64_T( PBA_PBOCR1_0x00064021                 , ULL(0x00064021) );
CONST_UINT64_T( PBA_PBOCR2_0x00064022                 , ULL(0x00064022) );
CONST_UINT64_T( PBA_PBOCR3_0x00064023                 , ULL(0x00064023) );
CONST_UINT64_T( PBA_PBOCR4_0x00064024                 , ULL(0x00064024) );
CONST_UINT64_T( PBA_PBOCR5_0x00064025                 , ULL(0x00064025) );

CONST_UINT64_T( PBA_BAR0_0x02013F00                   , ULL(0x02013F00) );
CONST_UINT64_T( PBA_BARMSK0_0x02013F04                , ULL(0x02013F04) );
CONST_UINT64_T( PBA_BAR1_0x02013F01                   , ULL(0x02013F01) );
CONST_UINT64_T( PBA_BARMSK1_0x02013F05                , ULL(0x02013F05) );
CONST_UINT64_T( PBA_BAR2_0x02013F02                   , ULL(0x02013F02) );
CONST_UINT64_T( PBA_BARMSK2_0x02013F06                , ULL(0x02013F06) );
CONST_UINT64_T( PBA_BAR3_0x02013F03                   , ULL(0x02013F03) );
CONST_UINT64_T( PBA_BARMSK3_0x02013F07                , ULL(0x02013F07) );
CONST_UINT64_T( PBA_TRUSTMODE_0x02013F08              , ULL(0x02013F08) );

//------------------------------------------------------------------------------
//      NEST PB EH
//------------------------------------------------------------------------------
// registers with multiple physical/shadow copies (all must be configured consistently)
// west
CONST_UINT64_T( PB_MODE_WEST_0x02010C0A               , ULL(0x02010C0A) );
CONST_UINT64_T( PB_HP_MODE_NEXT_WEST_0x02010C0B       , ULL(0x02010C0B) );
CONST_UINT64_T( PB_HP_MODE_CURR_WEST_0x02010C0C       , ULL(0x02010C0C) );
CONST_UINT64_T( PB_HPX_MODE_NEXT_WEST_0x02010C0D      , ULL(0x02010C0D) );
CONST_UINT64_T( PB_HPX_MODE_CURR_WEST_0x02010C0E      , ULL(0x02010C0E) );
CONST_UINT64_T( PB_FLMCFG0_WEST_0x02010C12            , ULL(0x02010C12) );
CONST_UINT64_T( PB_FLMCFG1_WEST_0x02010C13            , ULL(0x02010C13) );
CONST_UINT64_T( PB_FRMCFG0_WEST_0x02010C14            , ULL(0x02010C14) );
CONST_UINT64_T( PB_FRMCFG1_WEST_0x02010C15            , ULL(0x02010C15) );
// center
CONST_UINT64_T( PB_MODE_CENT_0x02010C4A               , ULL(0x02010C4A) );
CONST_UINT64_T( PB_HP_MODE_NEXT_CENT_0x02010C4B       , ULL(0x02010C4B) );
CONST_UINT64_T( PB_HP_MODE_CURR_CENT_0x02010C4C       , ULL(0x02010C4C) );
CONST_UINT64_T( PB_HPX_MODE_NEXT_CENT_0x02010C4D      , ULL(0x02010C4D) );
CONST_UINT64_T( PB_HPX_MODE_CURR_CENT_0x02010C4E      , ULL(0x02010C4E) );
CONST_UINT64_T( PB_FLMCFG0_CENT_0x02010C5E            , ULL(0x02010C5E) );
CONST_UINT64_T( PB_FLMCFG1_CENT_0x02010C5F            , ULL(0x02010C5F) );
CONST_UINT64_T( PB_FRMCFG0_CENT_0x02010C60            , ULL(0x02010C60) );
CONST_UINT64_T( PB_FRMCFG1_CENT_0x02010C61            , ULL(0x02010C61) );
// east
CONST_UINT64_T( PB_MODE_EAST_0x02010C8A               , ULL(0x02010C8A) );
CONST_UINT64_T( PB_HP_MODE_NEXT_EAST_0x02010C8B       , ULL(0x02010C8B) );
CONST_UINT64_T( PB_HP_MODE_CURR_EAST_0x02010C8C       , ULL(0x02010C8C) );
CONST_UINT64_T( PB_HPX_MODE_NEXT_EAST_0x02010C8D      , ULL(0x02010C8D) );
CONST_UINT64_T( PB_HPX_MODE_CURR_EAST_0x02010C8E      , ULL(0x02010C8E) );
CONST_UINT64_T( PB_FLMCFG0_EAST_0x02010C92            , ULL(0x02010C92) );
CONST_UINT64_T( PB_FLMCFG1_EAST_0x02010C93            , ULL(0x02010C93) );
CONST_UINT64_T( PB_FRMCFG0_EAST_0x02010C94            , ULL(0x02010C94) );
CONST_UINT64_T( PB_FRMCFG1_EAST_0x02010C95            , ULL(0x02010C95) );

// registers without shadow copies
// center
CONST_UINT64_T( PB_PMU_0x02010C4F                     , ULL(0x02010C4F) );
CONST_UINT64_T( PB_NMPM_COUNT_0x02010C50              , ULL(0x02010C50) );
CONST_UINT64_T( PB_LMPM_COUNT_0x02010C51              , ULL(0x02010C51) );
CONST_UINT64_T( PB_RCMD_INTDAT_COUNT_0x02010C52       , ULL(0x02010C52) );
CONST_UINT64_T( PB_EXTDAT_COUNT_0x02010C53            , ULL(0x02010C53) );
CONST_UINT64_T( PB_PMU_COUNT0_0x02010C54              , ULL(0x02010C54) );
CONST_UINT64_T( PB_PMU_COUNT1_0x02010C55              , ULL(0x02010C55) );
CONST_UINT64_T( PB_PMU_COUNT2_0x02010C56              , ULL(0x02010C56) );
CONST_UINT64_T( PB_PMU_COUNT3_0x02010C57              , ULL(0x02010C57) );
CONST_UINT64_T( PB_RGMCFG00_0x02010C58                , ULL(0x02010C58) );
CONST_UINT64_T( PB_RGMCFG01_0x02010C59                , ULL(0x02010C59) );
CONST_UINT64_T( PB_RGMCFG10_0x02010C5A                , ULL(0x02010C5A) );
CONST_UINT64_T( PB_RGMCFGM00_0x02010C5B               , ULL(0x02010C5B) );
CONST_UINT64_T( PB_RGMCFGM01_0x02010C5C               , ULL(0x02010C5C) );
CONST_UINT64_T( PB_RGMCFGM10_0x02010C5D               , ULL(0x02010C5D) );
CONST_UINT64_T( PB_GP_CMD_RATE_DP0_0x02010C62         , ULL(0x02010C62) );
CONST_UINT64_T( PB_GP_CMD_RATE_DP1_0x02010C63         , ULL(0x02010C63) );
CONST_UINT64_T( PB_RGP_CMD_RATE_DP0_0x02010C64        , ULL(0x02010C64) );
CONST_UINT64_T( PB_RGP_CMD_RATE_DP1_0x02010C65        , ULL(0x02010C65) );
CONST_UINT64_T( PB_SP_CMD_RATE_DP0_0x02010C66         , ULL(0x02010C66) );
CONST_UINT64_T( PB_SP_CMD_RATE_DP1_0x02010C67         , ULL(0x02010C67) );
CONST_UINT64_T( PB_EVENT_TRACE_0x02010C68             , ULL(0x02010C68) );
CONST_UINT64_T( PB_EVENT_COMPA_0x02010C69             , ULL(0x02010C69) );
CONST_UINT64_T( PB_EVENT_COMPB_0x02010C6A             , ULL(0x02010C6A) );
CONST_UINT64_T( PB_CR_ERROR_0x02010C6B                , ULL(0x02010C6B) );

//------------------------------------------------------------------------------
//      NEST PB EH FIR
//------------------------------------------------------------------------------
// west FIR
CONST_UINT64_T( PB_FIR_WEST_0x02010C00                , ULL(0x02010C00) );
CONST_UINT64_T( PB_FIR_AND_WEST_0x02010C01            , ULL(0x02010C01) );
CONST_UINT64_T( PB_FIR_OR_WEST_0x02010C02             , ULL(0x02010C02) );
CONST_UINT64_T( PB_FIR_MASK_WEST_0x02010C03           , ULL(0x02010C03) );
CONST_UINT64_T( PB_FIR_MASK_AND_WEST_0x02010C04       , ULL(0x02010C04) );
CONST_UINT64_T( PB_FIR_MASK_OR_WEST_0x02010C05        , ULL(0x02010C05) );
CONST_UINT64_T( PB_FIR_ACTION0_WEST_0x02010C06        , ULL(0x02010C06) );
CONST_UINT64_T( PB_FIR_ACTION1_WEST_0x02010C07        , ULL(0x02010C07) );
// center FIR
CONST_UINT64_T( PB_FIR_CENT_0x02010C40                , ULL(0x02010C40) );
CONST_UINT64_T( PB_FIR_AND_CENT_0x02010C41            , ULL(0x02010C41) );
CONST_UINT64_T( PB_FIR_OR_CENT_0x02010C42             , ULL(0x02010C42) );
CONST_UINT64_T( PB_FIR_MASK_CENT_0x02010C43           , ULL(0x02010C43) );
CONST_UINT64_T( PB_FIR_MASK_AND_CENT_0x02010C44       , ULL(0x02010C44) );
CONST_UINT64_T( PB_FIR_MASK_OR_CENT_0x02010C45        , ULL(0x02010C45) );
CONST_UINT64_T( PB_FIR_ACTION0_CENT_0x02010C46        , ULL(0x02010C46) );
CONST_UINT64_T( PB_FIR_ACTION1_CENT_0x02010C47        , ULL(0x02010C47) );
// east FIR
CONST_UINT64_T( PB_FIR_EAST_0x02010C80                , ULL(0x02010C80) );
CONST_UINT64_T( PB_FIR_AND_EAST_0x02010C81            , ULL(0x02010C81) );
CONST_UINT64_T( PB_FIR_OR_EAST_0x02010C82             , ULL(0x02010C82) );
CONST_UINT64_T( PB_FIR_MASK_EAST_0x02010C83           , ULL(0x02010C83) );
CONST_UINT64_T( PB_FIR_MASK_AND_EAST_0x02010C84       , ULL(0x02010C84) );
CONST_UINT64_T( PB_FIR_MASK_OR_EAST_0x02010C85        , ULL(0x02010C85) );
CONST_UINT64_T( PB_FIR_ACTION0_EAST_0x02010C86        , ULL(0x02010C86) );
CONST_UINT64_T( PB_FIR_ACTION1_EAST_0x02010C87        , ULL(0x02010C87) );
// RAS FIR
CONST_UINT64_T( PB_RAS_FIR_0x02010C6C                 , ULL(0x02010C6C) );
CONST_UINT64_T( PB_RAS_FIR_AND_0x02010C6D             , ULL(0x02010C6D) );
CONST_UINT64_T( PB_RAS_FIR_OR_0x02010C6E              , ULL(0x02010C6E) );
CONST_UINT64_T( PB_RAS_FIR_MASK_0x02010C6F            , ULL(0x02010C6F) );
CONST_UINT64_T( PB_RAS_FIR_MASK_AND_0x02010C70        , ULL(0x02010C70) );
CONST_UINT64_T( PB_RAS_FIR_MASK_OR_0x02010C71         , ULL(0x02010C71) );
CONST_UINT64_T( PB_RAS_FIR_ACTION0_0x02010C72         , ULL(0x02010C72) );
CONST_UINT64_T( PB_RAS_FIR_ACTION1_0x02010C73         , ULL(0x02010C73) );

//------------------------------------------------------------------------------
//      MCS
//------------------------------------------------------------------------------
// MCI
CONST_UINT64_T( MCI_FIR_0x02011840                    , ULL(0x02011840) );
CONST_UINT64_T( MCI_CFG_0x0201184A                    , ULL(0x0201184A) );
CONST_UINT64_T( MCI_STAT_0x0201184B                   , ULL(0x0201184B) );

//------------------------------------------------------------------------------
//      NEST Alter-Diplay Unit (ADU)
//------------------------------------------------------------------------------
CONST_UINT64_T( ADU_CONTROL_0x02020000                , ULL(0x02020000) );
CONST_UINT64_T( ADU_COMMAND_0x02020001                , ULL(0x02020001) );
CONST_UINT64_T( ADU_STATUS_0x02020002                 , ULL(0x02020002) );
CONST_UINT64_T( ADU_DATA_0x02020003                   , ULL(0x02020003) );
CONST_UINT64_T( ADU_FORCE_ECC_0x02020010              , ULL(0x02020010) );
CONST_UINT64_T( ADU_PMISC_MODE_0x0202000B             , ULL(0x0202000B) );


/******************************************************************************/
/******************************  X-BUS CHIPLET  *******************************/
/******************************************************************************/

//------------------------------------------------------------------------------
//      X-BUS GPIO
//------------------------------------------------------------------------------
CONST_UINT64_T( X_GP0_0x04000000                      , ULL(0x04000000) );
CONST_UINT64_T( X_GP1_0x04000001                      , ULL(0x04000001) );
CONST_UINT64_T( X_GP2_0x04000002                      , ULL(0x04000002) );

//------------------------------------------------------------------------------
//      X-BUS SCOM
//            ring 1 = Trace 0
//            ring 2 = Trace 1
//            ring 3 = PBEN
//            ring 4 = IOX0
//            ring 5 = IOX1
//            ring 6 = IOX3
//            ring 7 = IOX2
//            ring 9 = IOPSI
//------------------------------------------------------------------------------
CONST_UINT64_T( X_SCOM_0x04010000                     , ULL(0x04010000) );

//------------------------------------------------------------------------------
//      X-BUS CLOCK CONTROL
//------------------------------------------------------------------------------
CONST_UINT64_T( X_OPCG_CNTL0_0x04030002               , ULL(0x04030002) );
CONST_UINT64_T( X_OPCG_CNTL1_0x04030003               , ULL(0x04030003) );
CONST_UINT64_T( X_OPCG_CNTL2_0x04030004               , ULL(0x04030004) );
CONST_UINT64_T( X_OPCG_CNTL3_0x04030005               , ULL(0x04030005) );
CONST_UINT64_T( X_CLK_REGION_0x04030006               , ULL(0x04030006) );
CONST_UINT64_T( X_CLK_SCANSEL_0x04030007              , ULL(0x04030007) );
CONST_UINT64_T( X_CLK_STATUS_0x04030008               , ULL(0x04030008) );

//------------------------------------------------------------------------------
//      X-BUS FIR
//------------------------------------------------------------------------------
CONST_UINT64_T( X_XSTOP_0x04040000                    , ULL(0x04040000) );
CONST_UINT64_T( X_RECOV_0x04040001                    , ULL(0x04040001) );
CONST_UINT64_T( X_FIR_MASK_0x04040002                 , ULL(0x04040002) );
CONST_UINT64_T( X_SPATTN_0x04040004                   , ULL(0x04040004) );
CONST_UINT64_T( X_SPATTN_AND_0x04040005               , ULL(0x04040005) );
CONST_UINT64_T( X_SPATTN_OR_0x04040006                , ULL(0x04040006) );
CONST_UINT64_T( X_SPATTN_MASK_0x04040007              , ULL(0x04040007) );
CONST_UINT64_T( X_FIR_MODE_0x04040008                 , ULL(0x04040008) );
CONST_UINT64_T( X_PERV_LFIR_0x0404000A                , ULL(0x0404000A) );
CONST_UINT64_T( X_PERV_LFIR_AND_0x0404000B            , ULL(0x0404000B) );
CONST_UINT64_T( X_PERV_LFIR_OR_0x0404000C             , ULL(0x0404000C) );
CONST_UINT64_T( X_PERV_LFIR_MASK_0x0404000D           , ULL(0x0404000D) );
CONST_UINT64_T( X_PERV_LFIR_MASK_AND_0x0404000E       , ULL(0x0404000E) );
CONST_UINT64_T( X_PERV_LFIR_MASK_OR_0x0404000F        , ULL(0x0404000F) );
CONST_UINT64_T( X_PERV_LFIR_ACT0_0x04040010           , ULL(0x04040010) );
CONST_UINT64_T( X_PERV_LFIR_ACT1_0x04040011           , ULL(0x04040011) );

//------------------------------------------------------------------------------
//      X-BUS THERMAL
//------------------------------------------------------------------------------
CONST_UINT64_T( X_THERM_0x04050000                    , ULL(0x04050000) );

//------------------------------------------------------------------------------
//      X-BUS PCB SLAVE
//------------------------------------------------------------------------------
//Multicast Group Registers
CONST_UINT64_T( X_MCGR1_0x040F0001                    , ULL(0x040F0001) );
CONST_UINT64_T( X_MCGR2_0x040F0002                    , ULL(0x040F0002) );
CONST_UINT64_T( X_MCGR3_0x040F0003                    , ULL(0x040F0003) );
CONST_UINT64_T( X_MCGR4_0x040F0004                    , ULL(0x040F0004) );
//GP0 Register
CONST_UINT64_T( X_GP0_AND_0x04000004                  , ULL(0x04000004) );
CONST_UINT64_T( X_GP0_OR_0x04000005                   , ULL(0x04000005) );
//GP3 Register
CONST_UINT64_T( X_GP3_0x040F0012                      , ULL(0x040F0012) );
CONST_UINT64_T( X_GP3_AND_0x040F0013                  , ULL(0x040F0013) );
CONST_UINT64_T( X_GP3_OR_0x040F0014                   , ULL(0x040F0014) );

//------------------------------------------------------------------------------
//      X-BUS HANG DETECTION
//------------------------------------------------------------------------------
CONST_UINT64_T( X_HANG_P0_XBUS_0x040F0020             , ULL(0x040F0020) );   // XBUS     : setup hang pulse register0
CONST_UINT64_T( X_HANG_PRE_XBUS_0x040F0028            , ULL(0x040F0028) );   // XBUS     : setup hang precounter (HEX:01)

//------------------------------------------------------------------------------
//      X-BUS PBEN
//------------------------------------------------------------------------------
CONST_UINT64_T( X_PB_MODE_0x04010C0A                  , ULL(0x04010C0A) );


/******************************************************************************/
/******************************  A-BUS CHIPLET  *******************************/
/******************************************************************************/
//------------------------------------------------------------------------------
//      A-BUS GPIO
//------------------------------------------------------------------------------
CONST_UINT64_T( A_GP0_0x08000000                      , ULL(0x08000000) );
CONST_UINT64_T( A_GP1_0x08000001                      , ULL(0x08000001) );
CONST_UINT64_T( A_GP2_0x08000002                      , ULL(0x08000002) );

//------------------------------------------------------------------------------
//      A-BUS SCOM
//            ring 1 = trace
//            ring 2 = PBES
//            ring 3 = IOA
//------------------------------------------------------------------------------
CONST_UINT64_T( A_SCOM_0x08010000                     , ULL(0x08010000) );

//------------------------------------------------------------------------------
//      A-BUS CLOCK CONTROL
//------------------------------------------------------------------------------
CONST_UINT64_T( A_OPCG_CNTL0_0x08030002               , ULL(0x08030002) );
CONST_UINT64_T( A_OPCG_CNTL1_0x08030003               , ULL(0x08030003) );
CONST_UINT64_T( A_OPCG_CNTL2_0x08030004               , ULL(0x08030004) );
CONST_UINT64_T( A_OPCG_CNTL3_0x08030005               , ULL(0x08030005) );
CONST_UINT64_T( A_CLK_REGION_0x08030006               , ULL(0x08030006) );
CONST_UINT64_T( A_CLK_SCANSEL_0x08030007              , ULL(0x08030007) );
CONST_UINT64_T( A_CLK_STATUS_0x08030008               , ULL(0x08030008) );

//------------------------------------------------------------------------------
//      A-BUS FIR
//------------------------------------------------------------------------------
CONST_UINT64_T( A_XSTOP_0x08040000                    , ULL(0x08040000) );
CONST_UINT64_T( A_RECOV_0x08040001                    , ULL(0x08040001) );
CONST_UINT64_T( A_FIR_MASK_0x08040002                 , ULL(0x08040002) );
CONST_UINT64_T( A_SPATTN_0x08040004                   , ULL(0x08040004) );
CONST_UINT64_T( A_SPATTN_AND_0x08040005               , ULL(0x08040005) );
CONST_UINT64_T( A_SPATTN_OR_0x08040006                , ULL(0x08040006) );
CONST_UINT64_T( A_SPATTN_MASK_0x08040007              , ULL(0x08040007) );
CONST_UINT64_T( A_FIR_MODE_0x08040008                 , ULL(0x08040008) );
CONST_UINT64_T( A_PERV_LFIR_0x0804000A                , ULL(0x0804000A) );
CONST_UINT64_T( A_PERV_LFIR_AND_0x0804000B            , ULL(0x0804000B) );
CONST_UINT64_T( A_PERV_LFIR_OR_0x0804000C             , ULL(0x0804000C) );
CONST_UINT64_T( A_PERV_LFIR_MASK_0x0804000D           , ULL(0x0804000D) );
CONST_UINT64_T( A_PERV_LFIR_MASK_AND_0x0804000E       , ULL(0x0804000E) );
CONST_UINT64_T( A_PERV_LFIR_MASK_OR_0x0804000F        , ULL(0x0804000F) );
CONST_UINT64_T( A_PERV_LFIR_ACT0_0x08040010           , ULL(0x08040010) );
CONST_UINT64_T( A_PERV_LFIR_ACT1_0x08040011           , ULL(0x08040011) );

//------------------------------------------------------------------------------
//      A-BUS THERMAL
//------------------------------------------------------------------------------
CONST_UINT64_T( A_THERM_0x08050000                    , ULL(0x08050000) );

//------------------------------------------------------------------------------
//      A-BUS PCB SLAVE
//------------------------------------------------------------------------------
//Multicast Group Registers
CONST_UINT64_T( A_MCGR1_0x080F0001                    , ULL(0x080F0001) );
CONST_UINT64_T( A_MCGR2_0x080F0002                    , ULL(0x080F0002) );
CONST_UINT64_T( A_MCGR3_0x080F0003                    , ULL(0x080F0003) );
CONST_UINT64_T( A_MCGR4_0x080F0004                    , ULL(0x080F0004) );
//GP0 Register
CONST_UINT64_T( A_GP0_AND_0x08000004                  , ULL(0x08000004) );
CONST_UINT64_T( A_GP0_OR_0x08000005                   , ULL(0x08000005) );
//GP3 Register
CONST_UINT64_T( A_GP3_0x080F0012                      , ULL(0x080F0012) );
CONST_UINT64_T( A_GP3_AND_0x080F0013                  , ULL(0x080F0013) );
CONST_UINT64_T( A_GP3_OR_0x080F0014                   , ULL(0x080F0014) );

//------------------------------------------------------------------------------
//      A-BUS HANG DETECTION
//------------------------------------------------------------------------------
CONST_UINT64_T( A_HANG_P0_0x080F0020                  , ULL(0x080F0020) ); // ABUS     : setup hang pulse register0
CONST_UINT64_T( A_HANG_PRE_0x080F0028                 , ULL(0x080F0028) ); // ABUS     : setup hang precounter (HEX:01)

//------------------------------------------------------------------------------
//      A-BUS PBES
//------------------------------------------------------------------------------
CONST_UINT64_T( A_PB_MODE_0x0801080A                  , ULL(0x0801080A) );


/******************************************************************************/
/*****************************  PCIE-BUS CHIPLET  *****************************/
/******************************************************************************/
//------------------------------------------------------------------------------
//      PCIE-BUS GPIO
//------------------------------------------------------------------------------
CONST_UINT64_T( PCIE_GP0_0x09000000                   , ULL(0x09000000) );
CONST_UINT64_T( PCIE_GP1_0x09000001                   , ULL(0x09000001) );
CONST_UINT64_T( PCIE_GP2_0x09000002                   , ULL(0x09000002) );

//------------------------------------------------------------------------------
//      PCIE-BUS SCOM
//            ring  1 = trace
//            ring  2 = PBF
//            ring  5 = IOPCI0
//            ring  6 = IOPCI1
//            ring  7 = IOPCI2
//            ring  8 = PCI0
//            ring  9 = PCI1
//            ring 10 = PCI2
//            ring 11 = PCI3
//------------------------------------------------------------------------------
CONST_UINT64_T( PCIE_SCOM_0x09010000                  , ULL(0x09010000) );

//------------------------------------------------------------------------------
//      PCIE-BUS CLOCK CONTROL
//------------------------------------------------------------------------------
CONST_UINT64_T( PCIE_OPCG_CNTL0_0x09030002            , ULL(0x09030002) );
CONST_UINT64_T( PCIE_OPCG_CNTL1_0x09030003            , ULL(0x09030003) );
CONST_UINT64_T( PCIE_OPCG_CNTL2_0x09030004            , ULL(0x09030004) );
CONST_UINT64_T( PCIE_OPCG_CNTL3_0x09030005            , ULL(0x09030005) );
CONST_UINT64_T( PCIE_CLK_REGION_0x09030006            , ULL(0x09030006) );
CONST_UINT64_T( PCIE_CLK_SCANSEL_0x09030007           , ULL(0x09030007) );
CONST_UINT64_T( PCIE_CLK_STATUS_0x09030008            , ULL(0x09030008) );

//------------------------------------------------------------------------------
//      PCIE-BUS FIR
//------------------------------------------------------------------------------
CONST_UINT64_T( PCIE_XSTOP_0x09040000                 , ULL(0x09040000) );
CONST_UINT64_T( PCIE_RECOV_0x09040001                 , ULL(0x09040001) );
CONST_UINT64_T( PCIE_FIR_MASK_0x09040002              , ULL(0x09040002) );
CONST_UINT64_T( PCIE_SPATTN_0x09040004                , ULL(0x09040004) );
CONST_UINT64_T( PCIE_SPATTN_AND_0x09040005            , ULL(0x09040005) );
CONST_UINT64_T( PCIE_SPATTN_OR_0x09040006             , ULL(0x09040006) );
CONST_UINT64_T( PCIE_SPATTN_MASK_0x09040007           , ULL(0x09040007) );
CONST_UINT64_T( PCIE_FIR_MODE_0x09040008              , ULL(0x09040008) );
CONST_UINT64_T( PCIE_PERV_LFIR_0x0904000A             , ULL(0x0904000A) );
CONST_UINT64_T( PCIE_PERV_LFIR_AND_0x0904000B         , ULL(0x0904000B) );
CONST_UINT64_T( PCIE_PERV_LFIR_OR_0x0904000C          , ULL(0x0904000C) );
CONST_UINT64_T( PCIE_PERV_LFIR_MASK_0x0904000D        , ULL(0x0904000D) );
CONST_UINT64_T( PCIE_PERV_LFIR_MASK_AND_0x0904000E    , ULL(0x0904000E) );
CONST_UINT64_T( PCIE_PERV_LFIR_MASK_OR_0x0904000F     , ULL(0x0904000F) );
CONST_UINT64_T( PCIE_PERV_LFIR_ACT0_0x09040010        , ULL(0x09040010) );
CONST_UINT64_T( PCIE_PERV_LFIR_ACT1_0x09040011        , ULL(0x09040011) );

//------------------------------------------------------------------------------
//      PCIE-BUS THERMAL
//------------------------------------------------------------------------------
CONST_UINT64_T( PCIE_THERM_0x09050000                 , ULL(0x09050000) );

//------------------------------------------------------------------------------
//      PCIE-BUS PCB SLAVE
//------------------------------------------------------------------------------
//Multicast Group Registers
CONST_UINT64_T( PCIE_MCGR1_0x090F0001                 , ULL(0x090F0001) );
CONST_UINT64_T( PCIE_MCGR2_0x090F0002                 , ULL(0x090F0002) );
CONST_UINT64_T( PCIE_MCGR3_0x090F0003                 , ULL(0x090F0003) );
CONST_UINT64_T( PCIE_MCGR4_0x090F0004                 , ULL(0x090F0004) );
//GP3 Register
CONST_UINT64_T( PCIE_GP3_0x090F0012                   , ULL(0x090F0012) );
CONST_UINT64_T( PCIE_GP3_AND_0x090F0013               , ULL(0x090F0013) );
CONST_UINT64_T( PCIE_GP3_OR_0x090F0014                , ULL(0x090F0014) );

//------------------------------------------------------------------------------
//      PCIE-BUS HANG DETECTION
//------------------------------------------------------------------------------
CONST_UINT64_T( PCIE_HANG_PRE_0x090F0028              , ULL(0x090F0028) );       // PCIE     : setup hang precounter (HEX:01)


/******************************************************************************/
/********************************  EX CHIPLET  ********************************/
/******************************************************************************/
// Note: ECMD will require the use of these addresses, and it will update them
//       under the covers to point to the actual EX chiplet in question.
//
//       Example: getscom pu.ex 10000001 -c3   ---> scom address 0x13000001

//------------------------------------------------------------------------------
//      EX CHIPLET ID
//      use for lpcs P0, <chipletID>
//------------------------------------------------------------------------------
CONST_UINT64_T( EX00_CHIPLET_0x10000000               , ULL(0x10000000) );
CONST_UINT64_T( EX01_CHIPLET_0x11000000               , ULL(0x11000000) );
CONST_UINT64_T( EX02_CHIPLET_0x12000000               , ULL(0x12000000) );
CONST_UINT64_T( EX03_CHIPLET_0x13000000               , ULL(0x13000000) );
CONST_UINT64_T( EX04_CHIPLET_0x14000000               , ULL(0x14000000) );
CONST_UINT64_T( EX05_CHIPLET_0x15000000               , ULL(0x15000000) );
CONST_UINT64_T( EX06_CHIPLET_0x16000000               , ULL(0x16000000) );
CONST_UINT64_T( EX07_CHIPLET_0x17000000               , ULL(0x17000000) );
CONST_UINT64_T( EX08_CHIPLET_0x18000000               , ULL(0x18000000) );
CONST_UINT64_T( EX09_CHIPLET_0x19000000               , ULL(0x19000000) );
CONST_UINT64_T( EX10_CHIPLET_0x1A000000               , ULL(0x1A000000) );
CONST_UINT64_T( EX11_CHIPLET_0x1B000000               , ULL(0x1B000000) );
CONST_UINT64_T( EX12_CHIPLET_0x1C000000               , ULL(0x1C000000) );
CONST_UINT64_T( EX13_CHIPLET_0x1D000000               , ULL(0x1D000000) );
CONST_UINT64_T( EX14_CHIPLET_0x1E000000               , ULL(0x1E000000) );
CONST_UINT64_T( EX15_CHIPLET_0x1F000000               , ULL(0x1F000000) );

//------------------------------------------------------------------------------
//      EX GPIO
//------------------------------------------------------------------------------
CONST_UINT64_T( EX_GP0_0x10000000                     , ULL(0x10000000) );
CONST_UINT64_T( EX_GP1_0x10000001                     , ULL(0x10000001) );
CONST_UINT64_T( EX_GP2_0x10000002                     , ULL(0x10000002) );

//------------------------------------------------------------------------------
//      EX SCOM
//         ring 1  = ECO trace
//         ring 2  = L3
//         ring 3  = NC
//         ring 4  = HTM
//         ring 8  = L2 trace 0
//         ring 9  = L2 trace 1
//         ring 10 = L2
//         ring 11 = PC trace
//         ring 12 = PC
//         ring 15 = PC sec
//------------------------------------------------------------------------------
//ECO Trace
CONST_UINT64_T( EX_ECO_TRACE0_0x10010400              , ULL(0x10010400) );
CONST_UINT64_T( EX_ECO_TRACE1_0x10010401              , ULL(0x10010401) );
//L3
CONST_UINT64_T( EX_L3_MODE_REG1_0x1001080A            , ULL(0x1001080A) );
CONST_UINT64_T( EX_L3_MODE_REG0_0x1001082B            , ULL(0x1001082B) );
//L2
CONST_UINT64_T( EX_L2_MODE_REG0_0x1001280A            , ULL(0x1001280A) );
CONST_UINT64_T( EX_L2_PURGE_CMD_PRD_0x1001280E        , ULL(0x1001280E) );
CONST_UINT64_T( EX_L2_PURGE_CMD_PHYP_0x1001280F       , ULL(0x1001280F) );

//------------------------------------------------------------------------------
//      EX/CORE PERVASIVE THREAD CONTROLS
//        (chiplet/core set by P0 register)
//------------------------------------------------------------------------------
// TCTL Direct Controls (for each thread)
CONST_UINT64_T( EX_PERV_TCTL0_DIRECT_0x10013000       , ULL(0x10013000) );
CONST_UINT64_T( EX_PERV_TCTL1_DIRECT_0x10013010       , ULL(0x10013010) );
CONST_UINT64_T( EX_PERV_TCTL2_DIRECT_0x10013020       , ULL(0x10013020) );
CONST_UINT64_T( EX_PERV_TCTL3_DIRECT_0x10013030       , ULL(0x10013030) );
CONST_UINT64_T( EX_PERV_TCTL4_DIRECT_0x10013040       , ULL(0x10013040) );
CONST_UINT64_T( EX_PERV_TCTL5_DIRECT_0x10013050       , ULL(0x10013050) );
CONST_UINT64_T( EX_PERV_TCTL6_DIRECT_0x10013060       , ULL(0x10013060) );
CONST_UINT64_T( EX_PERV_TCTL7_DIRECT_0x10013070       , ULL(0x10013070) );

// TCTL RAS Status (for each thread)
CONST_UINT64_T( EX_PERV_TCTL0_R_STAT_0x10013002       , ULL(0x10013002) );
CONST_UINT64_T( EX_PERV_TCTL1_R_STAT_0x10013012       , ULL(0x10013012) );
CONST_UINT64_T( EX_PERV_TCTL2_R_STAT_0x10013022       , ULL(0x10013022) );
CONST_UINT64_T( EX_PERV_TCTL3_R_STAT_0x10013032       , ULL(0x10013032) );
CONST_UINT64_T( EX_PERV_TCTL4_R_STAT_0x10013042       , ULL(0x10013042) );
CONST_UINT64_T( EX_PERV_TCTL5_R_STAT_0x10013052       , ULL(0x10013052) );
CONST_UINT64_T( EX_PERV_TCTL6_R_STAT_0x10013062       , ULL(0x10013062) );
CONST_UINT64_T( EX_PERV_TCTL7_R_STAT_0x10013072       , ULL(0x10013072) );

//------------------------------------------------------------------------------
//      EX OHA
//------------------------------------------------------------------------------
CONST_UINT64_T( EX_SCOM_0x10020000                    , ULL(0x10020000) );

//------------------------------------------------------------------------------
//      EX CLOCK CONTROL
//------------------------------------------------------------------------------
CONST_UINT64_T( EX_OPCG_CNTL0_0x10030002              , ULL(0x10030002) );
CONST_UINT64_T( EX_OPCG_CNTL1_0x10030003              , ULL(0x10030003) );
CONST_UINT64_T( EX_OPCG_CNTL2_0x10030004              , ULL(0x10030004) );
CONST_UINT64_T( EX_OPCG_CNTL3_0x10030005              , ULL(0x10030005) );
CONST_UINT64_T( EX_CLK_REGION_0x10030006              , ULL(0x10030006) );
CONST_UINT64_T( EX_CLK_SCANSEL_0x10030007             , ULL(0x10030007) );
CONST_UINT64_T( EX_CLK_STATUS_0x10030008              , ULL(0x10030008) );

//------------------------------------------------------------------------------
//      EX FIR
//------------------------------------------------------------------------------
CONST_UINT64_T( EX_XSTOP_0x10040000                   , ULL(0x10040000) );
CONST_UINT64_T( EX_RECOV_0x10040001                   , ULL(0x10040001) );
CONST_UINT64_T( EX_FIR_MASK_0x10040002                , ULL(0x10040002) );
CONST_UINT64_T( EX_SPATTN_0x10040004                  , ULL(0x10040004) );
CONST_UINT64_T( EX_SPATTN_AND_0x10040005              , ULL(0x10040005) );
CONST_UINT64_T( EX_SPATTN_OR_0x10040006               , ULL(0x10040006) );
CONST_UINT64_T( EX_SPATTN_MASK_0x10040007             , ULL(0x10040007) );
CONST_UINT64_T( EX_FIR_MODE_0x10040008                , ULL(0x10040008) );
CONST_UINT64_T( EX_PERV_LFIR_0x1004000A               , ULL(0x1004000A) );
CONST_UINT64_T( EX_PERV_LFIR_AND_0x1004000B           , ULL(0x1004000B) );
CONST_UINT64_T( EX_PERV_LFIR_OR_0x1004000C            , ULL(0x1004000C) );
CONST_UINT64_T( EX_PERV_LFIR_MASK_0x1004000D          , ULL(0x1004000D) );
CONST_UINT64_T( EX_PERV_LFIR_MASK_AND_0x1004000E      , ULL(0x1004000E) );
CONST_UINT64_T( EX_PERV_LFIR_MASK_OR_0x1004000F       , ULL(0x1004000F) );
CONST_UINT64_T( EX_PERV_LFIR_ACT0_0x10040010          , ULL(0x10040010) );
CONST_UINT64_T( EX_PERV_LFIR_ACT1_0x10040011          , ULL(0x10040011) );

//------------------------------------------------------------------------------
//      EX THERMAL
//------------------------------------------------------------------------------
CONST_UINT64_T( EX_THERM_0x10050000                   , ULL(0x10050000) );

//------------------------------------------------------------------------------
//      EX PCB SLAVE
//------------------------------------------------------------------------------
//Generic names (need to add in (cuTarget.chipUnitNum * 0x01000000)) when being used
//Multicast Group Registers
CONST_UINT64_T( EX_MCGR1_0x100F0001                   , ULL(0x100F0001) );
CONST_UINT64_T( EX_MCGR2_0x100F0002                   , ULL(0x100F0002) );
CONST_UINT64_T( EX_MCGR3_0x100F0003                   , ULL(0x100F0003) );
CONST_UINT64_T( EX_MCGR4_0x100F0004                   , ULL(0x100F0004) );
//GP3 Register
CONST_UINT64_T( EX_GP3_0x100F0012                     , ULL(0x100F0012) );
CONST_UINT64_T( EX_GP3_AND_0x100F0013                 , ULL(0x100F0013) );
CONST_UINT64_T( EX_GP3_OR_0x100F0014                  , ULL(0x100F0014) );
//PMGP0 Register
CONST_UINT64_T( EX_PMGP0_0x100F0100                   , ULL(0x100F0100) );
CONST_UINT64_T( EX_PMGP0_AND_0x100F0101               , ULL(0x100F0101) );
CONST_UINT64_T( EX_PMGP0_OR_0x100F0102                , ULL(0x100F0102) );

//Chiplet specific names (probably won't ever be used)
CONST_UINT64_T( EX00_GP3_0x100F0012                   , ULL(0x100F0012) );
CONST_UINT64_T( EX00_GP3_AND_0x100F0013               , ULL(0x100F0013) );
CONST_UINT64_T( EX00_GP3_OR_0x100F0014                , ULL(0x100F0014) );

CONST_UINT64_T( EX01_GP3_0x110F0012                   , ULL(0x110F0012) );
CONST_UINT64_T( EX01_GP3_AND_0x110F0013               , ULL(0x110F0013) );
CONST_UINT64_T( EX01_GP3_OR_0x110F0014                , ULL(0x110F0014) );

CONST_UINT64_T( EX02_GP3_0x120F0012                   , ULL(0x120F0012) );
CONST_UINT64_T( EX02_GP3_AND_0x120F0013               , ULL(0x120F0013) );
CONST_UINT64_T( EX02_GP3_OR_0x120F0014                , ULL(0x120F0014) );

CONST_UINT64_T( EX03_GP3_0x130F0012                   , ULL(0x130F0012) );
CONST_UINT64_T( EX03_GP3_AND_0x130F0013               , ULL(0x130F0013) );
CONST_UINT64_T( EX03_GP3_OR_0x130F0014                , ULL(0x130F0014) );

CONST_UINT64_T( EX04_GP3_0x140F0012                   , ULL(0x140F0012) );
CONST_UINT64_T( EX04_GP3_AND_0x140F0013               , ULL(0x140F0013) );
CONST_UINT64_T( EX04_GP3_OR_0x140F0014                , ULL(0x140F0014) );

CONST_UINT64_T( EX05_GP3_0x150F0012                   , ULL(0x150F0012) );
CONST_UINT64_T( EX05_GP3_AND_0x150F0013               , ULL(0x150F0013) );
CONST_UINT64_T( EX05_GP3_OR_0x150F0014                , ULL(0x150F0014) );

CONST_UINT64_T( EX06_GP3_0x160F0012                   , ULL(0x160F0012) );
CONST_UINT64_T( EX06_GP3_AND_0x160F0013               , ULL(0x160F0013) );
CONST_UINT64_T( EX06_GP3_OR_0x160F0014                , ULL(0x160F0014) );

CONST_UINT64_T( EX07_GP3_0x170F0012                   , ULL(0x170F0012) );
CONST_UINT64_T( EX07_GP3_AND_0x170F0013               , ULL(0x170F0013) );
CONST_UINT64_T( EX07_GP3_OR_0x170F0014                , ULL(0x170F0014) );

CONST_UINT64_T( EX08_GP3_0x180F0012                   , ULL(0x180F0012) );
CONST_UINT64_T( EX08_GP3_AND_0x180F0013               , ULL(0x180F0013) );
CONST_UINT64_T( EX08_GP3_OR_0x180F0014                , ULL(0x180F0014) );

CONST_UINT64_T( EX09_GP3_0x190F0012                   , ULL(0x190F0012) );
CONST_UINT64_T( EX09_GP3_AND_0x190F0013               , ULL(0x190F0013) );
CONST_UINT64_T( EX09_GP3_OR_0x190F0014                , ULL(0x190F0014) );

CONST_UINT64_T( EX10_GP3_0x1A0F0012                   , ULL(0x1A0F0012) );
CONST_UINT64_T( EX10_GP3_AND_0x1A0F0013               , ULL(0x1A0F0013) );
CONST_UINT64_T( EX10_GP3_OR_0x1A0F0014                , ULL(0x1A0F0014) );

CONST_UINT64_T( EX11_GP3_0x1B0F0012                   , ULL(0x1B0F0012) );
CONST_UINT64_T( EX11_GP3_AND_0x1B0F0013               , ULL(0x1B0F0013) );
CONST_UINT64_T( EX11_GP3_OR_0x1B0F0014                , ULL(0x1B0F0014) );

CONST_UINT64_T( EX12_GP3_0x1C0F0012                   , ULL(0x1C0F0012) );
CONST_UINT64_T( EX12_GP3_AND_0x1C0F0013               , ULL(0x1C0F0013) );
CONST_UINT64_T( EX12_GP3_OR_0x1C0F0014                , ULL(0x1C0F0014) );

CONST_UINT64_T( EX13_GP3_0x1D0F0012                   , ULL(0x1D0F0012) );
CONST_UINT64_T( EX13_GP3_AND_0x1D0F0013               , ULL(0x1D0F0013) );
CONST_UINT64_T( EX13_GP3_OR_0x1D0F0014                , ULL(0x1D0F0014) );

CONST_UINT64_T( EX14_GP3_0x1E0F0012                   , ULL(0x1E0F0012) );
CONST_UINT64_T( EX14_GP3_AND_0x1E0F0013               , ULL(0x1E0F0013) );
CONST_UINT64_T( EX14_GP3_OR_0x1E0F0014                , ULL(0x1E0F0014) );

CONST_UINT64_T( EX15_GP3_0x1F0F0012                   , ULL(0x1F0F0012) );
CONST_UINT64_T( EX15_GP3_AND_0x1F0F0013               , ULL(0x1F0F0013) );
CONST_UINT64_T( EX15_GP3_OR_0x1F0F0014                , ULL(0x1F0F0014) );

//------------------------------------------------------------------------------
//      EX PCB SLAVE PM
//------------------------------------------------------------------------------
//Generic names (need to add in (cuTarget.chipUnitNum * 0x01000000)) when being used

CONST_UINT64_T( EX_IDLEGOTO_0x100F0114                , ULL(0x100F0114) );
CONST_UINT64_T( EX_FREQCNTL_0x100F0151                , ULL(0x100F0151) );


//******************************************************************************/
//*********  MULTICAST REGISTER DEFINITIONS FOR PERVASIVE INITs ****************/
//******************************************************************************/

CONST_UINT64_T( READ_ALL_GP0_0x43000000               , ULL(0x43000000) );       // all GP0 but not PRV
CONST_UINT64_T( WRITE_ALL_GP0_0x6B000000              , ULL(0x6B000000) );       // all GP0 but not PRV
CONST_UINT64_T( WRITE_ALL_GP0_AND_0x6B000004          , ULL(0x6B000004) );       // all GP0 AND but not PRV
CONST_UINT64_T( WRITE_ALL_GP0_OR_0x6B000005           , ULL(0x6B000005) );       // all GP0 OR but not PRV

CONST_UINT64_T( READ_ALL_GP1_AND_0x4B000001           , ULL(0x4B000001) );       // and all GP1 but not PRV

CONST_UINT64_T( WRITE_ALL_CLK_REGION_0x6B030006       , ULL(0x6B030006) );       // all GP3 but not PRV

CONST_UINT64_T( READ_ALL_OPCG_CNTL0_0x43030002        , ULL(0x43030002) );       // all EX OPCG0
CONST_UINT64_T( WRITE_ALL_OPCG_CNTL0_0x6B030002       , ULL(0x6B030002) );       // all EX OPCG0

CONST_UINT64_T( READ_ALL_OPCG_CNTL2_0x43030004        , ULL(0x43030004) );       // all OPCG2 but not PRV
CONST_UINT64_T( WRITE_ALL_OPCG_CNTL2_0x6B030004       , ULL(0x6B030004) );       // all OPCG2 but not PRV

CONST_UINT64_T( READ_ALL_FUNC_GP3_0x430F0012          , ULL(0x430F0012) );       // all GP3 but not PRV
CONST_UINT64_T( WRITE_ALL_FUNC_GP3_0x6B0F0012         , ULL(0x6B0F0012) );       // all GP3 but not PRV
CONST_UINT64_T( WRITE_ALL_FUNC_GP3_AND_0x6B0F0013     , ULL(0x6B0F0013) );       // all GP3 but not PRV
CONST_UINT64_T( WRITE_ALL_FUNC_GP3_OR_0x6B0F0014      , ULL(0x6B0F0014) );       // all GP3 but not PRV

CONST_UINT64_T( WRITE_ALL_HPRE0_0x690F0020            , ULL(0x690F0020) );       // hang pulse register 0
CONST_UINT64_T( WRITE_ALL_HPRE1_0x690F0021            , ULL(0x690F0021) );       // hang pulse register 1
CONST_UINT64_T( WRITE_ALL_HPRE2_0x690F0022            , ULL(0x690F0022) );       // hang pulse register 2
CONST_UINT64_T( WRITE_ALL_HPCRE_0x690F0028            , ULL(0x690F0028) );       // hang pulse count register

CONST_UINT64_T( WRITE_EX_PMGP0_AND_0x690F0101         , ULL(0x690F0101) );       // PM GP0 initialization

CONST_UINT64_T( SLAVE_PCB_ERR_0x6B0F001F              , ULL(0x6B0F001F) );


#endif


/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.

$Log: p8_scom_addresses.H,v $
Revision 1.50  2012/01/06 22:20:53  jmcgill
move shared/common addresses to common_scom_addresses.H, general cleanup

Revision 1.49  2012/01/05 22:07:47  jeshua
Updated ring numbers for most chiplets

Revision 1.48  2012/01/05 21:38:17  jmcgill
adjust EX SCOM ring comments, pervasive thread control/status register addresses

Revision 1.47  2012/01/05 20:18:16  jmcgill
adjust L2 SCOM addresses

Revision 1.46  2011/12/15 17:49:30  bcbrock
Added the PIBMEM base address to p8_scom_addresses.H

Revision 1.45  2011/11/07 23:52:21  bcbrock
Added GENERIC_CLK_SCANDATA0_0x00038000

Revision 1.44  2011/11/07 05:49:06  jmcgill
update PBA trusted SCOM ring and PB X mode register addresses, add GP0 and/or addresses for A bus chiplet

Revision 1.43  2011/09/28 12:49:47  stillgs
Added some PCBS-PM addresses for early PM FAPI work

Revision 1.42  2011/09/16 16:01:34  jeshua
Added MBOX_SBEVITAL

Revision 1.41  2011/09/16 16:00:26  jeshua
Undo Ralph's X-bus change. The X-bus is now chiplet 4, not chiplet 3.

Revision 1.40  2011/09/16 10:28:56  rkoester
wrong X-BUS addresses corrected, changed from 0b04 to 0b03

Revision 1.39  2011/09/09 21:00:33  jeshua
X_BUS is now chiplet 4 (as of 051 chip)

Revision 1.37  2011/09/02 18:45:46  dan
Added scan_time_rep

Revision 1.36  2011/09/01 20:37:17  jmcgill
add PBA config register, shift L2 scom addresses for HW170113, fix L3 Mode Reg0 address

Revision 1.35  2011/08/30 22:07:37  jeshua
Added NEST_GP0_AND

Revision 1.34  2011/08/29 21:11:31  jmcgill
add generic PM GP0 OR constant

Revision 1.33  2011/08/26 15:51:38  jeshua
Added chiplet defines for multicast operations

Revision 1.32  2011/08/26 12:53:27  gweber
added constant SCAN_ALLSCANEXPRV_IMM

Revision 1.31  2011/08/11 20:56:24  dan
removed redundant GENERIC_PMGP0_AND_0x000F0101.
added WRITE_ALL_GP0_AND_0x6B000004, WRITE_ALL_GP0_OR_0x6B000005

Revision 1.30  2011/07/28 16:36:30  jmcgill
add comment regarding L2 SCOM addresses which need to be adjusted when model fixes arrive (HW170113)

Revision 1.29  2011/07/27 12:28:55  dan
Added scan0 defines.

Revision 1.28  2011/07/25 22:31:03  venton
Added back in global addresses still used in SBe procs from version 1.24

Revision 1.27  2011/07/25 20:52:58  jmcgill
temporary workaround for L2 Purge Register SCOM access

Revision 1.26  2011/07/25 17:30:35  dan
Added some generic registers.

Revision 1.25  2011/07/25 13:05:09  gweber
moved centaur constants to cen_scom_addresses.H

Revision 1.23  2011/07/20 15:32:10  gweber
added some centaur constants

Revision 1.22  2011/07/15 20:50:13  jeshua
Added chiplet and some generic addresses

Revision 1.21  2011/07/15 20:24:14  jeshua
TP_GP3_0x01000003 should be TP_GP4_0x01000003

Revision 1.20  2011/07/08 19:49:01  jeshua
Moved some addresses to their appropriate sections
Fixes some addresses that didn't match their name
Added EX08-15 generics
Removed some non-generic EX01 addresses

Revision 1.19  2011/07/07 21:36:11  rkoester
more addresses added

Revision 1.18  2011/07/07 16:27:49  karm
added chiplet_core_pervasive registers for start and status, added chiplet id

Revision 1.17  2011/07/07 12:24:49  rkoester
addresses added

Revision 1.16  2011/07/06 20:03:46  jmcgill
updates to handle TP design modifications which changed SCOM access method for subset of PBA facilities

Revision 1.15  2011/07/06 15:01:36  bcbrock
Fix header file name

Revision 1.14  2011/07/06 04:06:49  bcbrock
Added a common header for FAPI/SBE #defines, fapi_sbe_common.h

Revision 1.13  2011/07/01 15:13:16  rkoester
addresses added for mailbox register

Revision 1.12  2011/06/30 09:50:28  rkoester
private version of .H file released back to LIB, MBOX addresses added

Revision 1.11  2011/06/15 22:46:26  jeshua
Added Mailbox registers

Revision 1.10  2011/06/14 15:55:46  rkoester
move SCOM addresses from porinit.C to p8_scom_addresses.H

Revision 1.9  2011/06/14 04:57:04  bcbrock
Latest version of PGAS and PORE inline tools; Added PORE SCOM addresses

Revision 1.8  2011/06/07 21:26:49  jeshua
Updated OCB names to have the correct addresses

Revision 1.7  2011/06/02 14:28:26  jmcgill
add PB EH scom addresses, L3 mode register1 address

Revision 1.6  2011/05/31 22:09:47  jeshua
Updated the ULL macro, because the previous one didn't work with the assembler

Revision 1.5  2011/05/27 21:49:13  jeshua
Switch to constants instead of #defines
Added in a macro to allow PORE assembler to use this header as well

Revision 1.4  2011/05/24 19:01:58  jmcgill
add addresses from OCC/OCB/PBA

Revision 1.3  2011/04/21 19:48:23  jeshua
Added L2 and L3 Mode Reg 0

Revision 1.2  2011/04/06 18:27:01  jmcgill
fixup ADU Control Register name, add ADU PMISC Mode Register address

Revision 1.1  2011/02/23 17:09:44  jeshua
Initial version



*/
