//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/HWPs/dmi_training/cen_scom_addresses.H $
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
// $Id: cen_scom_addresses.H,v 1.11 2012/01/06 22:34:45 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/cen_scom_addresses.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : cen_scom_addresses.H
// *! DESCRIPTION : Defines for Centaur chip scom addresses
// *! OWNER NAME  : Mark Fredrickson  Email: mfred@us.ibm.com
// *! BACKUP NAME :                   Email:      @us.ibm.com
// #! ADDITIONAL COMMENTS :
//
// The purpose of this header is to define scom addresses for use by procedures.
// This will help catch address typos at compile time, and will make it easy
// to track down which procedures use each address
//

#ifndef CEN_SCOM_ADDRESSES
#define CEN_SCOM_ADDRESSES

//----------------------------------------------------------------------
//  Scom address overview
//----------------------------------------------------------------------
// Centaur uses 64-bit scom addresses, which are classified into two formats:
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
CONST_UINT64_T( MEM_CHIPLET_0x03000000                , ULL(0x03000000) );


/******************************************************************************/
/********************************  TP CHIPLET  ********************************/
/******************************************************************************/

//------------------------------------------------------------------------------
//      CENTAUR REPAIR LOADER REGISTERS
//------------------------------------------------------------------------------
CONST_UINT64_T( CEN_WRITE_ARRAY_REPAIR_REG_0x00050000,     ULL(0x00050000) );
CONST_UINT64_T( CEN_WRITE_ARRAY_REPAIR_CMD_0x00050002,     ULL(0x00050002) );
CONST_UINT64_T( CEN_READ_ARRAY_REPAIR_STATUS_0x00050003,   ULL(0x00050003) );
CONST_UINT64_T( CEN_READ_ECC_TRAP_REGISTER_0x00050004,     ULL(0x00050004) );


/******************************************************************************/
/*******************************  NEST CHIPLET  *******************************/
/******************************************************************************/

//------------------------------------------------------------------------------
//      MBU
//------------------------------------------------------------------------------
// MBI
CONST_UINT64_T( MBI_FIR_0x02010800                    , ULL(0x02010800) );
CONST_UINT64_T( MBI_CFG_0x0201080A                    , ULL(0x0201080A) );
CONST_UINT64_T( MBI_STAT_0x0201080B                   , ULL(0x0201080B) );


/******************************************************************************/
/******************************  MEM CHIPLET  *********************************/
/******************************************************************************/

//------------------------------------------------------------------------------
//      MEM GPIO
//------------------------------------------------------------------------------
CONST_UINT64_T( MEM_GP0_0x03000000                     , ULL(0x03000000) );
CONST_UINT64_T( MEM_GP1_0x03000001                     , ULL(0x03000001) );
CONST_UINT64_T( MEM_GP2_0x03000002                     , ULL(0x03000002) );
CONST_UINT64_T( MEM_GP4_0x03000003                     , ULL(0x03000003) );
CONST_UINT64_T( MEM_GP0_AND_0x03000004                 , ULL(0x03000004) );
CONST_UINT64_T( MEM_GP0_OR_0x03000005                  , ULL(0x03000005) );
CONST_UINT64_T( MEM_GP4_AND_0x03000006                 , ULL(0x03000006) );
CONST_UINT64_T( MEM_GP4_OR_0x03000007                  , ULL(0x03000007) );

//------------------------------------------------------------------------------
//      MEM SCOM
//------------------------------------------------------------------------------
CONST_UINT64_T( MEM_SCOM_0x03010000                    , ULL(0x03010000) );

CONST_UINT64_T( MEM_MBA01_CCS_MODEQ_0x030106A7         , ULL(0x030106A7) );
CONST_UINT64_T( MEM_MBA23_CCS_MODEQ_0x03010EA7         , ULL(0x03010EA7) );

//------------------------------------------------------------------------------
//      MEM CLOCK CONTROL
//------------------------------------------------------------------------------
CONST_UINT64_T( MEM_OPCG_CNTL0_0x03030002              , ULL(0x03030002) );
CONST_UINT64_T( MEM_OPCG_CNTL1_0x03030003              , ULL(0x03030003) );
CONST_UINT64_T( MEM_OPCG_CNTL2_0x03030004              , ULL(0x03030004) );
CONST_UINT64_T( MEM_OPCG_CNTL3_0x03030005              , ULL(0x03030005) );
CONST_UINT64_T( MEM_CLK_REGION_0x03030006              , ULL(0x03030006) );
CONST_UINT64_T( MEM_CLK_SCANSEL_0x03030007             , ULL(0x03030007) );
CONST_UINT64_T( MEM_CLK_STATUS_0x03030008              , ULL(0x03030008) );

//------------------------------------------------------------------------------
//      MEM FIR
//------------------------------------------------------------------------------
CONST_UINT64_T( MEM_XSTOP_0x03040000                   , ULL(0x03040000) );
CONST_UINT64_T( MEM_RECOV_0x03040001                   , ULL(0x03040001) );
CONST_UINT64_T( MEM_FIR_MASK_0x03040002                , ULL(0x03040002) );
CONST_UINT64_T( MEM_SPATTN_0x03040004                  , ULL(0x03040004) );
CONST_UINT64_T( MEM_SPATTN_AND_0x03040005              , ULL(0x03040005) );
CONST_UINT64_T( MEM_SPATTN_OR_0x03040006               , ULL(0x03040006) );
CONST_UINT64_T( MEM_SPATTN_MASK_0x03040007             , ULL(0x03040007) );
CONST_UINT64_T( MEM_FIR_MODE_0x03040008                , ULL(0x03040008) );
CONST_UINT64_T( MEM_PERV_LFIR_0x0304000A               , ULL(0x0304000A) );
CONST_UINT64_T( MEM_PERV_LFIR_AND_0x0304000B           , ULL(0x0304000B) );
CONST_UINT64_T( MEM_PERV_LFIR_OR_0x0304000C            , ULL(0x0304000C) );
CONST_UINT64_T( MEM_PERV_LFIR_MASK_0x0304000D          , ULL(0x0304000D) );
CONST_UINT64_T( MEM_PERV_LFIR_MASK_AND_0x0304000E      , ULL(0x0304000E) );
CONST_UINT64_T( MEM_PERV_LFIR_MASK_OR_0x0304000F       , ULL(0x0304000F) );
CONST_UINT64_T( MEM_PERV_LFIR_ACT0_0x03040010          , ULL(0x03040010) );
CONST_UINT64_T( MEM_PERV_LFIR_ACT1_0x03040011          , ULL(0x03040011) );

//------------------------------------------------------------------------------
//      MEM THERMAL
//------------------------------------------------------------------------------
CONST_UINT64_T( MEM_THERM_0x03050000                   , ULL(0x03050000) );

//------------------------------------------------------------------------------
//      MEM PCB SLAVE
//------------------------------------------------------------------------------
//Multicast Group Registers
CONST_UINT64_T( MEM_MCGR1_0x030F0001                   , ULL(0x030F0001) );
CONST_UINT64_T( MEM_MCGR2_0x030F0002                   , ULL(0x030F0002) );
CONST_UINT64_T( MEM_MCGR3_0x030F0003                   , ULL(0x030F0003) );
CONST_UINT64_T( MEM_MCGR4_0x030F0004                   , ULL(0x030F0004) );
//GP3 Register
CONST_UINT64_T( MEM_GP3_0x030F0012                     , ULL(0x030F0012) );
CONST_UINT64_T( MEM_GP3_AND_0x030F0013                 , ULL(0x030F0013) );
CONST_UINT64_T( MEM_GP3_OR_0x030F0014                  , ULL(0x030F0014) );
 
//------------------------------------------------------------------------------
//      MEM CHIPLET INDIRECT SCOM ADDRESSES (DPHY REGISTERS)
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_0_0x800000070301143F,                ULL(0x800000070301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_0_0x800100070301143F,                ULL(0x800100070301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_SYSCLK_PR_P0_0_0x800000070301183F,                ULL(0x800000070301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_SYSCLK_PR_P1_0_0x800100070301183F,                ULL(0x800100070301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P0_0_0x800000760301143F,              ULL(0x800000760301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P1_0_0x800100760301143F,              ULL(0x800100760301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG0_P0_0_0x800000760301183F,              ULL(0x800000760301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG0_P1_0_0x800100760301183F,              ULL(0x800100760301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P0_0_0x800000770301143F,              ULL(0x800000770301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P1_0_0x800100770301143F,              ULL(0x800100770301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG1_P0_0_0x800000770301183F,              ULL(0x800000770301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG1_P1_0_0x800100770301183F,              ULL(0x800100770301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_1_0x800004070301143F,                ULL(0x800004070301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_1_0x800104070301143F,                ULL(0x800104070301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_SYSCLK_PR_P0_1_0x800004070301183F,                ULL(0x800004070301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_SYSCLK_PR_P1_1_0x800104070301183F,                ULL(0x800104070301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P0_1_0x800004760301143F,              ULL(0x800004760301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P1_1_0x800104760301143F,              ULL(0x800104760301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG0_P0_1_0x800004760301183F,              ULL(0x800004760301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG0_P1_1_0x800104760301183F,              ULL(0x800104760301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P0_1_0x800004770301143F,              ULL(0x800004770301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P1_1_0x800104770301143F,              ULL(0x800104770301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG1_P0_1_0x800004770301183F,              ULL(0x800004770301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG1_P1_1_0x800104770301183F,              ULL(0x800104770301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_2_0x800008070301143F,                ULL(0x800008070301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_2_0x800108070301143F,                ULL(0x800108070301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_SYSCLK_PR_P0_2_0x800008070301183F,                ULL(0x800008070301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_SYSCLK_PR_P1_2_0x800108070301183F,                ULL(0x800108070301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P0_2_0x800008760301143F,              ULL(0x800008760301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P1_2_0x800108760301143F,              ULL(0x800108760301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG0_P0_2_0x800008760301183F,              ULL(0x800008760301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG0_P1_2_0x800108760301183F,              ULL(0x800108760301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P0_2_0x800008770301143F,              ULL(0x800008770301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P1_2_0x800108770301143F,              ULL(0x800108770301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG1_P0_2_0x800008770301183F,              ULL(0x800008770301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG1_P1_2_0x800108770301183F,              ULL(0x800108770301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_3_0x80000C070301143F,                ULL(0x80000C070301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_3_0x80010C070301143F,                ULL(0x80010C070301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_SYSCLK_PR_P0_3_0x80000C070301183F,                ULL(0x80000C070301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_SYSCLK_PR_P1_3_0x80010C070301183F,                ULL(0x80010C070301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P0_3_0x80000C760301143F,              ULL(0x80000C760301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P1_3_0x80010C760301143F,              ULL(0x80010C760301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG0_P0_3_0x80000C760301183F,              ULL(0x80000C760301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG0_P1_3_0x80010C760301183F,              ULL(0x80010C760301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P0_3_0x80000C770301143F,              ULL(0x80000C770301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P1_3_0x80010C770301143F,              ULL(0x80010C770301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG1_P0_3_0x80000C770301183F,              ULL(0x80000C770301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG1_P1_3_0x80010C770301183F,              ULL(0x80010C770301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_4_0x800010070301143F,                ULL(0x800010070301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_4_0x800110070301143F,                ULL(0x800110070301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_SYSCLK_PR_P0_4_0x800010070301183F,                ULL(0x800010070301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_SYSCLK_PR_P1_4_0x800110070301183F,                ULL(0x800110070301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P0_4_0x800010760301143F,              ULL(0x800010760301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P1_4_0x800110760301143F,              ULL(0x800110760301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG0_P0_4_0x800010760301183F,              ULL(0x800010760301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG0_P1_4_0x800110760301183F,              ULL(0x800110760301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P0_4_0x800010770301143F,              ULL(0x800010770301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P1_4_0x800110770301143F,              ULL(0x800110770301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG1_P0_4_0x800010770301183F,              ULL(0x800010770301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_DP18_PLL_CONFIG1_P1_4_0x800110770301183F,              ULL(0x800110770301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_0_P0_ADR32S0_0x800080300301143F,   ULL(0x800080300301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_0_P1_ADR32S0_0x800180300301143F,   ULL(0x800180300301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_ADR_PLL_VREG_CONFIG_0_P0_ADR32S0_0x800080300301183F,   ULL(0x800080300301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_ADR_PLL_VREG_CONFIG_0_P1_ADR32S0_0x800180300301183F,   ULL(0x800180300301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_1_P0_ADR32S0_0x800080310301143F,   ULL(0x800080310301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_1_P1_ADR32S0_0x800180310301143F,   ULL(0x800180310301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_ADR_PLL_VREG_CONFIG_1_P0_ADR32S0_0x800080310301183F,   ULL(0x800080310301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_ADR_PLL_VREG_CONFIG_1_P1_ADR32S0_0x800180310301183F,   ULL(0x800180310301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0_0x800080320301143F,      ULL(0x800080320301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S0_0x800180320301143F,      ULL(0x800180320301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0_0x800080320301183F,      ULL(0x800080320301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S0_0x800180320301183F,      ULL(0x800180320301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_0_P0_ADR32S1_0x800084300301143F,   ULL(0x800084300301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_0_P1_ADR32S1_0x800184300301143F,   ULL(0x800184300301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_ADR_PLL_VREG_CONFIG_0_P0_ADR32S1_0x800084300301183F,   ULL(0x800084300301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_ADR_PLL_VREG_CONFIG_0_P1_ADR32S1_0x800184300301183F,   ULL(0x800184300301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_1_P0_ADR32S1_0x800084310301143F,   ULL(0x800084310301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_1_P1_ADR32S1_0x800184310301143F,   ULL(0x800184310301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_ADR_PLL_VREG_CONFIG_1_P0_ADR32S1_0x800084310301183F,   ULL(0x800084310301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_ADR_PLL_VREG_CONFIG_1_P1_ADR32S1_0x800184310301183F,   ULL(0x800184310301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1_0x800084320301143F,      ULL(0x800084320301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S1_0x800184320301143F,      ULL(0x800184320301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1_0x800084320301183F,      ULL(0x800084320301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S1_0x800184320301183F,      ULL(0x800184320301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P0_0x8000C0000301143F,         ULL(0x8000C0000301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P1_0x8001C0000301143F,         ULL(0x8001C0000301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P0_0x8000C0000301183F,         ULL(0x8000C0000301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P1_0x8001C0000301183F,         ULL(0x8001C0000301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P0_0x8000C0010301143F,        ULL(0x8000C0010301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P1_0x8001C0010301143F,        ULL(0x8001C0010301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P0_0x8000C0010301183F,        ULL(0x8000C0010301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P1_0x8001C0010301183F,        ULL(0x8001C0010301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_CONFIG0_P0_0x8000C00C0301143F,                      ULL(0x8000C00C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_CONFIG0_P1_0x8001C00C0301143F,                      ULL(0x8001C00C0301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_PC_CONFIG0_P0_0x8000C00C0301183F,                      ULL(0x8000C00C0301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_PC_CONFIG0_P1_0x8001C00C0301183F,                      ULL(0x8001C00C0301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_RESETS_P0_0x8000C00E0301143F,                       ULL(0x8000C00E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_RESETS_P1_0x8001C00E0301143F,                       ULL(0x8001C00E0301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_PC_RESETS_P0_0x8000C00E0301183F,                       ULL(0x8000C00E0301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_PC_RESETS_P1_0x8001C00E0301183F,                       ULL(0x8001C00E0301183F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P0_0x8000C0140301143F,           ULL(0x8000C0140301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P1_0x8001C0140301143F,           ULL(0x8001C0140301143F) );
CONST_UINT64_T( DPHY23_DDRPHY_PC_IO_PVT_FET_CONTROL_P0_0x8000C0140301183F,           ULL(0x8000C0140301183F) );
CONST_UINT64_T( DPHY23_DDRPHY_PC_IO_PVT_FET_CONTROL_P1_0x8001C0140301183F,           ULL(0x8001C0140301183F) );
 
 
/******************************************************************************/
/*********  MULTICAST REGISTER DEFINITIONS FOR PERVASIVE INITs ****************/
/******************************************************************************/
CONST_UINT64_T( READ_OR_ALL_FUNC_GP0_0x41000000         , ULL(0x41000000) ); // group1: all except PRV: GP0
CONST_UINT64_T( READ_OR_ALL_FUNC_GP1_0x41000001         , ULL(0x41000001) ); // group1: all except PRV: GP1
CONST_UINT64_T( READ_OR_ALL_FUNC_GP2_0x41000002         , ULL(0x41000002) ); // group1: all except PRV: GP2
CONST_UINT64_T( READ_OR_ALL_FUNC_GP4_0x41000003         , ULL(0x41000003) ); // group1: all except PRV: GP4
CONST_UINT64_T( READ_OR_ALL_FUNC_OPCG_CNTL0_0x41030002  , ULL(0x41030002) ); // group1: all except PRV: OPCG_CNTL0
CONST_UINT64_T( READ_OR_ALL_FUNC_OPCG_CNTL1_0x41030003  , ULL(0x41030003) ); // group1: all except PRV: OPCG_CNTL1
CONST_UINT64_T( READ_OR_ALL_FUNC_OPCG_CNTL2_0x41030004  , ULL(0x41030004) ); // group1: all except PRV: OPCG_CNTL2
CONST_UINT64_T( READ_OR_ALL_FUNC_OPCG_CNTL3_0x41030005  , ULL(0x41030005) ); // group1: all except PRV: OPCG_CNTL3
CONST_UINT64_T( READ_OR_ALL_FUNC_CLK_REGION_0x41030006  , ULL(0x41030006) ); // group1: all except PRV: CLK_REGION
CONST_UINT64_T( READ_OR_ALL_FUNC_CLK_SCANSEL_0x41030007 , ULL(0x41030007) ); // group1: all except PRV: CLK_SCANSEL
CONST_UINT64_T( READ_OR_ALL_FUNC_CLK_STATUS_0x41030008  , ULL(0x41030008) ); // group1: all except PRV: CLK_STATUS
CONST_UINT64_T( READ_OR_ALL_FUNC_GP3_0x410F0012         , ULL(0x410F0012) ); // group1: all except PRV: GP3
CONST_UINT64_T( READ_OR_ALL_PCB_SLAVE_ERRREG_0x410F001F , ULL(0x410F001F) ); // group1: all except PRV:

CONST_UINT64_T( READ_AND_ALL_FUNC_GP0_0x49000000         , ULL(0x49000000) ); // group1: all except PRV: GP0
CONST_UINT64_T( READ_AND_ALL_FUNC_GP1_0x49000001         , ULL(0x49000001) ); // group1: all except PRV: GP1
CONST_UINT64_T( READ_AND_ALL_FUNC_GP2_0x49000002         , ULL(0x49000002) ); // group1: all except PRV: GP2
CONST_UINT64_T( READ_AND_ALL_FUNC_GP4_0x49000003         , ULL(0x49000003) ); // group1: all except PRV: GP4
CONST_UINT64_T( READ_AND_ALL_FUNC_OPCG_CNTL0_0x49030002  , ULL(0x49030002) ); // group1: all except PRV: OPCG_CNTL0
CONST_UINT64_T( READ_AND_ALL_FUNC_OPCG_CNTL1_0x49030003  , ULL(0x49030003) ); // group1: all except PRV: OPCG_CNTL1
CONST_UINT64_T( READ_AND_ALL_FUNC_OPCG_CNTL2_0x49030004  , ULL(0x49030004) ); // group1: all except PRV: OPCG_CNTL2
CONST_UINT64_T( READ_AND_ALL_FUNC_OPCG_CNTL3_0x49030005  , ULL(0x49030005) ); // group1: all except PRV: OPCG_CNTL3
CONST_UINT64_T( READ_AND_ALL_FUNC_CLK_REGION_0x49030006  , ULL(0x49030006) ); // group1: all except PRV: CLK_REGION
CONST_UINT64_T( READ_AND_ALL_FUNC_CLK_SCANSEL_0x49030007 , ULL(0x49030007) ); // group1: all except PRV: CLK_SCANSEL
CONST_UINT64_T( READ_AND_ALL_FUNC_CLK_STATUS_0x49030008  , ULL(0x49030008) ); // group1: all except PRV: CLK_STATUS
CONST_UINT64_T( READ_AND_ALL_FUNC_GP3_0x490F0012         , ULL(0x490F0012) ); // group1: all except PRV: GP3
CONST_UINT64_T( READ_AND_ALL_PCB_SLAVE_ERRREG_0x490F001F , ULL(0x490F001F) ); // group1: all except PRV:

CONST_UINT64_T( WRITE_ALL_FUNC_GP0_0x69000000            , ULL(0x69000000) ); // group1: all except PRV: GP0
CONST_UINT64_T( WRITE_ALL_FUNC_GP1_0x69000001            , ULL(0x69000001) ); // group1: all except PRV: GP1
CONST_UINT64_T( WRITE_ALL_FUNC_GP2_0x69000002            , ULL(0x69000002) ); // group1: all except PRV: GP2
CONST_UINT64_T( WRITE_ALL_FUNC_GP4_0x69000003            , ULL(0x69000003) ); // group1: all except PRV: GP4
CONST_UINT64_T( WRITE_ALL_FUNC_GP0_AND_0x69000004        , ULL(0x69000004) ); // group1: all except PRV: GP0 AND (for clearing bits)
CONST_UINT64_T( WRITE_ALL_FUNC_GP0_OR_0x69000005         , ULL(0x69000005) ); // group1: all except PRV: GP0 OR  (for setting bits)
CONST_UINT64_T( WRITE_ALL_FUNC_GP4_AND_0x69000006        , ULL(0x69000006) ); // group1: all except PRV: GP4 AND (for clearing bits)
CONST_UINT64_T( WRITE_ALL_FUNC_GP4_OR_0x69000007         , ULL(0x69000007) ); // group1: all except PRV: GP4 OR  (for setting bits)
CONST_UINT64_T( WRITE_ALL_FUNC_OPCG_CNTL0_0x69030002     , ULL(0x69030002) ); // group1: all except PRV: OPCG_CNTL0
CONST_UINT64_T( WRITE_ALL_FUNC_OPCG_CNTL1_0x69030003     , ULL(0x69030003) ); // group1: all except PRV: OPCG_CNTL1
CONST_UINT64_T( WRITE_ALL_FUNC_OPCG_CNTL2_0x69030004     , ULL(0x69030004) ); // group1: all except PRV: OPCG_CNTL2
CONST_UINT64_T( WRITE_ALL_FUNC_OPCG_CNTL3_0x69030005     , ULL(0x69030005) ); // group1: all except PRV: OPCG_CNTL3
CONST_UINT64_T( WRITE_ALL_FUNC_CLK_REGION_0x69030006     , ULL(0x69030006) ); // group1: all except PRV: CLK_REGION
CONST_UINT64_T( WRITE_ALL_FUNC_CLK_SCANSEL_0x69030007    , ULL(0x69030007) ); // group1: all except PRV: CLK_SCANSEL
CONST_UINT64_T( WRITE_ALL_FUNC_CLK_STATUS_0x69030008     , ULL(0x69030008) ); // group1: all except PRV: CLK_STATUS
CONST_UINT64_T( WRITE_ALL_FUNC_GP3_0x690F0012            , ULL(0x690F0012) ); // group1: all except PRV: GP3
CONST_UINT64_T( WRITE_ALL_FUNC_GP3_AND_0x690F0013        , ULL(0x690F0013) ); // group1: all except PRV: GP3 AND (for clearing bits)
CONST_UINT64_T( WRITE_ALL_FUNC_GP3_OR_0x690F0014         , ULL(0x690F0014) ); // group1: all except PRV: GP3 OR  (for setting bits)
CONST_UINT64_T( WRITE_ALL_PCB_SLAVE_ERRREG_0x690F001F    , ULL(0x690F001F) ); // group1: all except PRV:

//******************************************************************************/
//*********  ADDRESS PREFIXES FOR SUBROUTINE SCAN0_MODULE CALLS ****************/
//******************************************************************************/

CONST_UINT8_T( READ_OR_ALL_CHIPLETS,              ULL(0x40) );   // group 0: TP, MEM, NEST
CONST_UINT8_T( READ_OR_ALL_FUNC_CHIPLETS,         ULL(0x41) );   // group 1: MEM, NEST// CONST_UINT8_T( READ_AND_ALL_CHIPLETS,             ULL(0x48) );   // group 0: TP, MEM, NEST
CONST_UINT8_T( READ_AND_ALL_FUNC_CHIPLETS,        ULL(0x49) );   // group 1: MEM, NEST
CONST_UINT8_T( WRITE_ALL_CHIPLETS,                ULL(0x68) );   // group 0: TP, MEM, NEST
CONST_UINT8_T( WRITE_ALL_FUNC_CHIPLETS,           ULL(0x69) );   // group 1: MEM, NEST


#endif


/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.

$Log: cen_scom_addresses.H,v $
Revision 1.11  2012/01/06 22:34:45  jmcgill
move shared/common addresses to common_scom_addresses.H, general cleanup

Revision 1.10  2011/10/26 21:37:03  mfred
Fix error.  Extra space in an address was causing compile failure.

Revision 1.9  2011/10/25 22:53:46  mfred
Added MEM chiplet indirect scom addresses (DPHY registers).

Revision 1.8  2011/09/20 15:51:30  venton
Add missing SCOMs from P8

Revision 1.7  2011/08/02 20:28:40  mfred
added some 8-bit constants for use with P0 and P1

Revision 1.6  2011/07/28 14:44:51  mfred
Added more multicast addresses.

Revision 1.5  2011/07/27 20:08:01  mfred
Added multicast addresses for OPCG, etc.

Revision 1.3  2011/07/25 13:03:53  gweber
moved centaur constants from p8_scom_addresses.H

Revision 1.2  2011/07/13 18:35:13  mfred
Get rid of some temp lines and comments.

Revision 1.1  2011/07/07 13:07:52  mfred
Adding first version of scom address file.  Was created from P8 version.




*/
