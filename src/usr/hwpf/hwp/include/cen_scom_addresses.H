/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/include/cen_scom_addresses.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
// $Id: cen_scom_addresses.H,v 1.22 2012/06/18 01:58:44 jmcgill Exp $
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
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//         |          |         |
//  1.22   | jmcgill  |17-Jun-12| Added trace related SCOM addresses
//  1.21   | gollub   |23-May-12| Added regs needed for mss_maint_cmds
//  1.20   | jdsloat  |17-May-12| Added MBA/MBS level PM, REF register addresses
//  1.19   | gollub   |25-Apr-12| Added MBS ECC regs
//  1.15   | divyakum |06-Mar-12| Added calibration status regs
//  1.14   | divyakum |22-Feb-12| Added CALIBRATION registers.
//         |          |         | Added Change history table
//  1.13   | mfred    |24-Jan-12| Moved common multicast address constants to common_scom_accresses.H
//  1.12   | mfred    |24-Jan-12| Move multicast group 1 to group 3 for consistency with P8
//  1.11   | jmcgill  |06-Jan-12| move shared/common addresses to common_scom_addresses.H, general cleanup
//  1.10   | mfred    |26-Oct-12| Fix error.  Extra space in an address was causing compile failure.
//  1.9    | mfred    |25-Oct-12| Added MEM chiplet indirect scom addresses (DPHY registers).
//  1.8    | venton   |20-Sep-12| Add missing SCOMs from P8
//  1.7    | mfred    |02-Aug-12| added some 8-bit constants for use with P0 and P1
//  1.6    | mfred    |28-Aug-12| Added more multicast addresses.
//  1.5    | mfred    |27-Jul-12| Added multicast addresses for OPCG, etc.
//  1.3    | gweber   |25-Jul-12| moved centaur constants from p8_scom_addresses.H
//  1.2    | mfred    |13-Jul-12| Get rid of some temp lines and comments.
//  1.1    | mfred    |07-Jul-12| Adding first version of scom address file.  Was created from P8 version.


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
#include "fapi_sbe_common.H"


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

CONST_UINT64_T( TP_TRACE_DATA_HI_0x01010440            , ULL(0x01010440) );
CONST_UINT64_T( TP_TRACE_DATA_LO_0x01010441            , ULL(0x01010441) ); 

/******************************************************************************/
/*******************************  NEST CHIPLET  *******************************/
/******************************************************************************/

//------------------------------------------------------------------------------
//      MBU
//------------------------------------------------------------------------------
// MBI
CONST_UINT64_T( MBI_FIR_0x02010800                     , ULL(0x02010800) );
CONST_UINT64_T( MBI_CFG_0x0201080A                     , ULL(0x0201080A) );
CONST_UINT64_T( MBI_STAT_0x0201080B                    , ULL(0x0201080B) );

CONST_UINT64_T( NEST_TRACE_DATA_HI_MBI_0x02010C40      , ULL(0x02010C40) );
CONST_UINT64_T( NEST_TRACE_DATA_LO_MBI_0x02010C41	   , ULL(0x02010C41) );
// MBS
CONST_UINT64_T( MBSSQ_0x02011417                       , ULL(0x02011417) );

CONST_UINT64_T( NEST_TRACE_DATA_HI_MBS1_0x02011880	   , ULL(0x02011880) );
CONST_UINT64_T( NEST_TRACE_DATA_LO_MBS1_0x02011881	   , ULL(0x02011881) );
CONST_UINT64_T( NEST_TRACE_DATA_HI_MBS2_0x020118C0	   , ULL(0x020118C0) );
CONST_UINT64_T( NEST_TRACE_DATA_LO_MBS2_0x020118C1     , ULL(0x020118C1) );

// MBA
CONST_UINT64_T( MBA01_REF0Q_0x03010432                 , ULL(0x03010432) );
CONST_UINT64_T( MBA01_PM0Q_0x03010434                  , ULL(0x03010434) );

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
//      MEM TRACE
//------------------------------------------------------------------------------
CONST_UINT64_T( MEM_TRACE_DATA_HI_MBA01_0x03010880     , ULL(0x03010880) );
CONST_UINT64_T( MEM_TRACE_DATA_LO_MBA01_0x03010881     , ULL(0x03010881) );
CONST_UINT64_T( MEM_TRACE_DATA_HI_MBA23_0x030110C0     , ULL(0x030110C0) );
CONST_UINT64_T( MEM_TRACE_DATA_LO_MBA23_0x030110C1     , ULL(0x030110C1) );

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
// Note - on March 30,2012, at the request of the GFW team, I removed all the DPHY23 addresses that were listed below.
// These adddresses should not be needed because the procedures are written using DPHY01 as the target and
// the platform translates the address for DPHY23.
// If you should need these dphy23 address for some reason, I have saved a copy of them here:
//  /afs/rchland.ibm.com/usr5/mfred/vbu_files/cen_scom_addresses.H.dphy23               Mark Fredrickson

CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_0_0x800000070301143F,                ULL(0x800000070301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_0_0x800100070301143F,                ULL(0x800100070301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P0_0_0x800000760301143F,              ULL(0x800000760301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P1_0_0x800100760301143F,              ULL(0x800100760301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P0_0_0x800000770301143F,              ULL(0x800000770301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P1_0_0x800100770301143F,              ULL(0x800100770301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_1_0x800004070301143F,                ULL(0x800004070301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_1_0x800104070301143F,                ULL(0x800104070301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P0_1_0x800004760301143F,              ULL(0x800004760301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P1_1_0x800104760301143F,              ULL(0x800104760301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P0_1_0x800004770301143F,              ULL(0x800004770301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P1_1_0x800104770301143F,              ULL(0x800104770301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_2_0x800008070301143F,                ULL(0x800008070301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_2_0x800108070301143F,                ULL(0x800108070301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P0_2_0x800008760301143F,              ULL(0x800008760301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P1_2_0x800108760301143F,              ULL(0x800108760301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P0_2_0x800008770301143F,              ULL(0x800008770301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P1_2_0x800108770301143F,              ULL(0x800108770301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_3_0x80000C070301143F,                ULL(0x80000C070301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_3_0x80010C070301143F,                ULL(0x80010C070301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P0_3_0x80000C760301143F,              ULL(0x80000C760301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P1_3_0x80010C760301143F,              ULL(0x80010C760301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P0_3_0x80000C770301143F,              ULL(0x80000C770301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P1_3_0x80010C770301143F,              ULL(0x80010C770301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_4_0x800010070301143F,                ULL(0x800010070301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_4_0x800110070301143F,                ULL(0x800110070301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P0_4_0x800010760301143F,              ULL(0x800010760301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG0_P1_4_0x800110760301143F,              ULL(0x800110760301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P0_4_0x800010770301143F,              ULL(0x800010770301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_PLL_CONFIG1_P1_4_0x800110770301143F,              ULL(0x800110770301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_0_P0_ADR32S0_0x800080300301143F,   ULL(0x800080300301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_0_P1_ADR32S0_0x800180300301143F,   ULL(0x800180300301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_1_P0_ADR32S0_0x800080310301143F,   ULL(0x800080310301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_1_P1_ADR32S0_0x800180310301143F,   ULL(0x800180310301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0_0x800080320301143F,      ULL(0x800080320301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S0_0x800180320301143F,      ULL(0x800180320301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_0_P0_ADR32S1_0x800084300301143F,   ULL(0x800084300301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_0_P1_ADR32S1_0x800184300301143F,   ULL(0x800184300301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_1_P0_ADR32S1_0x800084310301143F,   ULL(0x800084310301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_1_P1_ADR32S1_0x800184310301143F,   ULL(0x800184310301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1_0x800084320301143F,      ULL(0x800084320301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S1_0x800184320301143F,      ULL(0x800184320301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P0_0x8000C0000301143F,         ULL(0x8000C0000301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P1_0x8001C0000301143F,         ULL(0x8001C0000301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P0_0x8000C0010301143F,        ULL(0x8000C0010301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P1_0x8001C0010301143F,        ULL(0x8001C0010301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_CONFIG0_P0_0x8000C00C0301143F,                      ULL(0x8000C00C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_CONFIG0_P1_0x8001C00C0301143F,                      ULL(0x8001C00C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_RESETS_P0_0x8000C00E0301143F,                       ULL(0x8000C00E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_RESETS_P1_0x8001C00E0301143F,                       ULL(0x8001C00E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P0_0x8000C0140301143F,           ULL(0x8000C0140301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P1_0x8001C0140301143F,           ULL(0x8001C0140301143F) );

//------------------------------------------------------------------------------
//      CALIBRATION SCOM ADDRESSES (DPHY REGISTERS)
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_PC_INIT_CAL_CONFIG0_P0_0x8000C0160301143F,             ULL(0x8000C0160301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_INIT_CAL_CONFIG0_P1_0x8001C0160301143F,             ULL(0x8001C0160301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_PC_INIT_CAL_CONFIG1_P0_0x8000C0170301143F,             ULL(0x8000C0170301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_INIT_CAL_CONFIG1_P1_0x8001C0170301143F,             ULL(0x8001C0170301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_PC_INIT_CAL_STATUS_P0_0x8000C0190301143F,              ULL(0x8000C0190301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_INIT_CAL_STATUS_P1_0x8001C0190301143F,              ULL(0x8001C0190301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_PC_INIT_CAL_ERROR_P0_0x8000C0180301143F,               ULL(0x8000C0180301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_INIT_CAL_ERROR_P1_0x8001C0180301143F,               ULL(0x8001C0180301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_PC_INIT_CAL_MASK_P0_0x8000C01A0301143F,                ULL(0x8000C01A0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_INIT_CAL_MASK_P1_0x8001C01A0301143F,                ULL(0x8001C01A0301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_PC_PER_CAL_CONFIG_P0_0x8000C00B0301143F,               ULL(0x8000C00B0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_PER_CAL_CONFIG_P1_0x8001C00B0301143F,               ULL(0x8001C00B0301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_PC_PER_ZCAL_CONFIG_P0_0x8000C00F0301143F,              ULL(0x8000C00F0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_PER_ZCAL_CONFIG_P1_0x8001C00F0301143F,              ULL(0x8001C00F0301143F) );

//------------------------------------------------------------------------------
//      MBA Fault Isolation Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBAFIRQ_0x03010600           , ULL(0x03010600) );

//------------------------------------------------------------------------------
//      MBA Maintenance Command Type Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBMCTQ_0x0301060A           , ULL(0x0301060A) );

//------------------------------------------------------------------------------
//      MBA Maintenance Command Control Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBMCCQ_0x0301060B           , ULL(0x0301060B) );

//------------------------------------------------------------------------------
//      MBA Maintenance Command Status Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBMSRQ_0x0301060C           , ULL(0x0301060C) );

//------------------------------------------------------------------------------
//      MBA Maintenance Command Address Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBMACAQ_0x0301060D           , ULL(0x0301060D) );

//------------------------------------------------------------------------------
//      MBA Maintenance Command End Address Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBMEAQ_0x0301060E           , ULL(0x0301060E) );

//------------------------------------------------------------------------------
//      MBA Memory Scrub/Read Control Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBASCTLQ_0x0301060F           , ULL(0x0301060F) );

//------------------------------------------------------------------------------
//      MBA Error Control Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBECTLQ_0x03010610           , ULL(0x03010610) );

//------------------------------------------------------------------------------
//      MBA Special Attention Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBSPAQ_0x03010611           , ULL(0x03010611) );

//------------------------------------------------------------------------------
//      MBA Maint Read Buffers corresponding to ports 0/1
//------------------------------------------------------------------------------

CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF0_DATA0_0x03010655           , ULL(0x03010655) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF0_DATA1_0x03010656           , ULL(0x03010656) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF0_DATA2_0x03010657           , ULL(0x03010657) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF0_DATA3_0x03010658           , ULL(0x03010658) );

CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF1_DATA0_0x03010665           , ULL(0x03010665) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF1_DATA1_0x03010666           , ULL(0x03010666) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF1_DATA2_0x03010667           , ULL(0x03010667) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF1_DATA3_0x03010668           , ULL(0x03010668) );

CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF2_DATA0_0x03010675           , ULL(0x03010675) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF2_DATA1_0x03010676           , ULL(0x03010676) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF2_DATA2_0x03010677           , ULL(0x03010677) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF2_DATA3_0x03010678           , ULL(0x03010678) );

CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF3_DATA0_0x03010685           , ULL(0x03010685) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF3_DATA1_0x03010686           , ULL(0x03010686) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF3_DATA2_0x03010687           , ULL(0x03010687) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF3_DATA3_0x03010688           , ULL(0x03010688) );

//------------------------------------------------------------------------------
//      MBA Write Bit Steer Control Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBABS0_0x03010440           , ULL(0x03010440) );
CONST_UINT64_T( MBA01_MBABS1_0x03010441           , ULL(0x03010441) );
CONST_UINT64_T( MBA01_MBABS2_0x03010442           , ULL(0x03010442) );
CONST_UINT64_T( MBA01_MBABS3_0x03010443           , ULL(0x03010443) );
CONST_UINT64_T( MBA01_MBABS4_0x03010444           , ULL(0x03010444) );
CONST_UINT64_T( MBA01_MBABS5_0x03010445           , ULL(0x03010445) );
CONST_UINT64_T( MBA01_MBABS6_0x03010446           , ULL(0x03010446) );
CONST_UINT64_T( MBA01_MBABS7_0x03010447           , ULL(0x03010447) );

//------------------------------------------------------------------------------
//      MBA CAL FIR Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBACALFIR_0x03010400           , ULL(0x03010400) );

//------------------------------------------------------------------------------
//      MBA WRD Mode Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBA_WRD_MODE_0x03010429           , ULL(0x03010429) );





//------------------------------------------------------------------------------
//      Address Translate Control Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( MBAXCR01Q_0x0201140B           , ULL(0x0201140B) );
CONST_UINT64_T( MBAXCR23Q_0x0201140C           , ULL(0x0201140C) );

//------------------------------------------------------------------------------
//      MBS ECC Decoder FIR Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( MBS_ECC0_MBECCFIR_0x02011440           , ULL(0x02011440) );
CONST_UINT64_T( MBS_ECC1_MBECCFIR_0x02011480           , ULL(0x02011480) );

//------------------------------------------------------------------------------
//      MBS Memory ECC Mark Store Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( MBS_ECC0_MBMS0_0x0201144B           , ULL(0x0201144B) );
CONST_UINT64_T( MBS_ECC0_MBMS1_0x0201144C           , ULL(0x0201144C) );
CONST_UINT64_T( MBS_ECC0_MBMS2_0x0201144D           , ULL(0x0201144D) );
CONST_UINT64_T( MBS_ECC0_MBMS3_0x0201144E           , ULL(0x0201144E) );
CONST_UINT64_T( MBS_ECC0_MBMS4_0x0201144F           , ULL(0x0201144F) );
CONST_UINT64_T( MBS_ECC0_MBMS5_0x02011450           , ULL(0x02011450) );
CONST_UINT64_T( MBS_ECC0_MBMS6_0x02011451           , ULL(0x02011451) );
CONST_UINT64_T( MBS_ECC0_MBMS7_0x02011452           , ULL(0x02011452) );

CONST_UINT64_T( MBS_ECC1_MBMS0_0x0201148B           , ULL(0x0201148B) );
CONST_UINT64_T( MBS_ECC1_MBMS1_0x0201148C           , ULL(0x0201148C) );
CONST_UINT64_T( MBS_ECC1_MBMS2_0x0201148D           , ULL(0x0201148D) );
CONST_UINT64_T( MBS_ECC1_MBMS3_0x0201148E           , ULL(0x0201148E) );
CONST_UINT64_T( MBS_ECC1_MBMS4_0x0201148F           , ULL(0x0201148F) );
CONST_UINT64_T( MBS_ECC1_MBMS5_0x02011490           , ULL(0x02011490) );
CONST_UINT64_T( MBS_ECC1_MBMS6_0x02011491           , ULL(0x02011491) );
CONST_UINT64_T( MBS_ECC1_MBMS7_0x02011492           , ULL(0x02011492) );

//------------------------------------------------------------------------------
//      MBS Read Bit Steer Control Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( MBS_ECC0_MBSBS0_0x0201145E           , ULL(0x0201145E) );
CONST_UINT64_T( MBS_ECC0_MBSBS1_0x0201145F           , ULL(0x0201145F) );
CONST_UINT64_T( MBS_ECC0_MBSBS2_0x02011460           , ULL(0x02011460) );
CONST_UINT64_T( MBS_ECC0_MBSBS3_0x02011461           , ULL(0x02011461) );
CONST_UINT64_T( MBS_ECC0_MBSBS4_0x02011462           , ULL(0x02011462) );
CONST_UINT64_T( MBS_ECC0_MBSBS5_0x02011463           , ULL(0x02011463) );
CONST_UINT64_T( MBS_ECC0_MBSBS6_0x02011464           , ULL(0x02011464) );
CONST_UINT64_T( MBS_ECC0_MBSBS7_0x02011465           , ULL(0x02011465) );

CONST_UINT64_T( MBS_ECC1_MBSBS0_0x0201149E           , ULL(0x0201149E) );
CONST_UINT64_T( MBS_ECC1_MBSBS1_0x0201149F           , ULL(0x0201149F) );
CONST_UINT64_T( MBS_ECC1_MBSBS2_0x020114A0           , ULL(0x020114A0) );
CONST_UINT64_T( MBS_ECC1_MBSBS3_0x020114A1           , ULL(0x020114A1) );
CONST_UINT64_T( MBS_ECC1_MBSBS4_0x020114A2           , ULL(0x020114A2) );
CONST_UINT64_T( MBS_ECC1_MBSBS5_0x020114A3           , ULL(0x020114A3) );
CONST_UINT64_T( MBS_ECC1_MBSBS6_0x020114A4           , ULL(0x020114A4) );
CONST_UINT64_T( MBS_ECC1_MBSBS7_0x020114A5           , ULL(0x020114A5) );


//------------------------------------------------------------------------------
//      MBS Maint Write Buffers corresponding to ports 0/1
//------------------------------------------------------------------------------

// Maint Write Buffer 0
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF0_DATA0_0x0201160A				, ULL(0x0201160A) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF0_DATA1_0x0201160B				, ULL(0x0201160B) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF0_DATA2_0x0201160C				, ULL(0x0201160C) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF0_DATA3_0x0201160D				, ULL(0x0201160D) );

CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF0_DATA_ECC0_0x02011612			, ULL(0x02011612) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF0_DATA_ECC1_0x02011613			, ULL(0x02011613) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF0_DATA_ECC2_0x02011614			, ULL(0x02011614) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF0_DATA_ECC3_0x02011615			, ULL(0x02011615) );

// Maint Write Buffer 1
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF1_DATA0_0x0201161A				, ULL(0x0201161A) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF1_DATA1_0x0201161B				, ULL(0x0201161B) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF1_DATA2_0x0201161C				, ULL(0x0201161C) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF1_DATA3_0x0201161D				, ULL(0x0201161D) );

CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF1_DATA_ECC0_0x02011622			, ULL(0x02011622) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF1_DATA_ECC1_0x02011623			, ULL(0x02011623) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF1_DATA_ECC2_0x02011624			, ULL(0x02011624) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF1_DATA_ECC3_0x02011625			, ULL(0x02011625) );

// Maint Write Buffer 2
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF2_DATA0_0x0201162A				, ULL(0x0201162A) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF2_DATA1_0x0201162B				, ULL(0x0201162B) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF2_DATA2_0x0201162C				, ULL(0x0201162C) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF2_DATA3_0x0201162D				, ULL(0x0201162D) );

CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF2_DATA_ECC0_0x02011632			, ULL(0x02011632) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF2_DATA_ECC1_0x02011633			, ULL(0x02011633) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF2_DATA_ECC2_0x02011634			, ULL(0x02011634) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF2_DATA_ECC3_0x02011635			, ULL(0x02011635) );
		
// Maint Write Buffer 3
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF3_DATA0_0x0201163A				, ULL(0x0201163A) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF3_DATA1_0x0201163B				, ULL(0x0201163B) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF3_DATA2_0x0201163C				, ULL(0x0201163C) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF3_DATA3_0x0201163D				, ULL(0x0201163D) );

CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF3_DATA_ECC0_0x02011642			, ULL(0x02011642) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF3_DATA_ECC1_0x02011643			, ULL(0x02011643) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF3_DATA_ECC2_0x02011644			, ULL(0x02011644) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF3_DATA_ECC3_0x02011645			, ULL(0x02011645) );

// Maint Write Buffer 65th Byte
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF_65TH_BYTE_64B_ECC0_0x0201164A , ULL(0x0201164A) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF_65TH_BYTE_64B_ECC1_0x0201164B , ULL(0x0201164B) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF_65TH_BYTE_64B_ECC2_0x0201164C , ULL(0x0201164C) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF_65TH_BYTE_64B_ECC3_0x0201164D , ULL(0x0201164D) );


//------------------------------------------------------------------------------
//      MBS Maint Write Buffers corresponding to ports 2/3
//------------------------------------------------------------------------------

// Maint Write Buffer 0
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF0_DATA0_0x0201170A				, ULL(0x0201170A) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF0_DATA1_0x0201170B				, ULL(0x0201170B) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF0_DATA2_0x0201170C				, ULL(0x0201170C) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF0_DATA3_0x0201170D				, ULL(0x0201170D) );

CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF0_DATA_ECC0_0x02011712			, ULL(0x02011712) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF0_DATA_ECC1_0x02011713			, ULL(0x02011713) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF0_DATA_ECC2_0x02011714			, ULL(0x02011714) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF0_DATA_ECC3_0x02011715			, ULL(0x02011715) );

// Maint Write Buffer 1
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF1_DATA0_0x0201171A				, ULL(0x0201171A) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF1_DATA1_0x0201171B				, ULL(0x0201171B) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF1_DATA2_0x0201171C				, ULL(0x0201171C) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF1_DATA3_0x0201171D				, ULL(0x0201171D) );

CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF1_DATA_ECC0_0x02011722			, ULL(0x02011722) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF1_DATA_ECC1_0x02011723			, ULL(0x02011723) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF1_DATA_ECC2_0x02011724			, ULL(0x02011724) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF1_DATA_ECC3_0x02011725			, ULL(0x02011725) );

// Maint Write Buffer 2
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF2_DATA0_0x0201172A				, ULL(0x0201172A) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF2_DATA1_0x0201172B				, ULL(0x0201172B) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF2_DATA2_0x0201172C				, ULL(0x0201172C) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF2_DATA3_0x0201172D				, ULL(0x0201172D) );

CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF2_DATA_ECC0_0x02011732			, ULL(0x02011732) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF2_DATA_ECC1_0x02011733			, ULL(0x02011733) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF2_DATA_ECC2_0x02011734			, ULL(0x02011734) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF2_DATA_ECC3_0x02011735			, ULL(0x02011735) );
	
// Maint Write Buffer 3
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF3_DATA0_0x0201173A				, ULL(0x0201173A) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF3_DATA1_0x0201173B				, ULL(0x0201173B) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF3_DATA2_0x0201173C				, ULL(0x0201173C) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF3_DATA3_0x0201173D				, ULL(0x0201173D) );

CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF3_DATA_ECC0_0x02011742			, ULL(0x02011742) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF3_DATA_ECC1_0x02011743			, ULL(0x02011743) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF3_DATA_ECC2_0x02011744			, ULL(0x02011744) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF3_DATA_ECC3_0x02011745			, ULL(0x02011745) );

// Maint Write Buffer 65th Byte
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF_65TH_BYTE_64B_ECC0_0x0201174A , ULL(0x0201174A) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF_65TH_BYTE_64B_ECC1_0x0201174B , ULL(0x0201174B) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF_65TH_BYTE_64B_ECC2_0x0201174C , ULL(0x0201174C) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF_65TH_BYTE_64B_ECC3_0x0201174D , ULL(0x0201174D) );

//------------------------------------------------------------------------------
//      MBS Memory ECC Control Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( MBS_ECC0_MBSECCQ_0x0201144A           , ULL(0x0201144A) );
CONST_UINT64_T( MBS_ECC1_MBSECCQ_0x0201148A           , ULL(0x0201148A) );

//------------------------------------------------------------------------------
//      MBS Memory Scrub/Read Error Threshold Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( MBS01_MBSTRQ_0x02011655           , ULL(02011655) );
CONST_UINT64_T( MBS23_MBSTRQ_0x02011755           , ULL(02011755) );



/******************************************************************************/
/*********  MULTICAST REGISTER DEFINITIONS FOR PERVASIVE INITs ****************/
/******************************************************************************/
// moved to common_scom_addresses.H       1/24/2010   mfred


//******************************************************************************/
//*********  ADDRESS PREFIXES FOR SUBROUTINE SCAN0_MODULE CALLS ****************/
//******************************************************************************/
// moved to common_scom_addresses.H       1/24/2010   mfred

#endif


/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.

$Log: cen_scom_addresses.H,v $
Revision 1.22  2012/06/18 01:58:44  jmcgill
added trace related SCOM addresses

Revision 1.21  2012/05/23 15:54:03  gollub

Added regs needed for mss_maint_cmds.

Revision 1.20  2012/05/17 21:55:05  jdsloat
Added MBA/MBS level PM, REF register addresses

Revision 1.19  2012/04/25 22:28:06  gollub
Added MBS ECC regs

Revision 1.18  2012/04/16 23:56:39  bcbrock
Corrected problems related to C/C++ and 32-bit/64-bit portability and Host
Boot after initial review by FW team.

o Renamed fapi_sbe_common.h to fapi_sbe_common.H

Revision 1.17  2012/03/30 19:59:23  mfred
removing dphy23 addresses completely.  Should not be needed.

Revision 1.16  2012/03/30 19:29:44  mfred
Fix some DPHY23 addresses and comment out all the DPHY23 addresses.  Should not be needed.

Revision 1.15  2012/03/06 16:40:00  divyakum
Added calibration status regs

Revision 1.14  2012/02/22 22:50:52  divyakum
Added CALIBRATION registers. Added Change history table.

Revision 1.13  2012/01/24 21:58:33  mfred
Moved common multicast address constants to common_scom_accresses.H

Revision 1.12  2012/01/24 20:50:01  mfred
Move multicast group 1 to group 3 for consistency with P8

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
