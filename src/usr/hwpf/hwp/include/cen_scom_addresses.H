/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/include/cen_scom_addresses.H $               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: cen_scom_addresses.H,v 1.46 2012/12/19 15:31:24 gollub Exp $
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
//  1.46   | gollub   |19-Dec-12| Added:
//         |          |         | MCBERRPTQ
//         |          |         | MBA_MAINT_BUFF
//         |          |         | MBA_MAINT_BUFF_65TH_BYTE_64B_ECC
//         |          |         | MBA_ERR_REPORTQ
//         |          |         | MBSECCERR
//         |          |         | MBMMRQ
//         |          |         | MBS_MAINT_BUFF0_DATA
//         |          |         | MBS_MAINT_BUFF0_DATA_ECC
//         |          |         | MBSEC
//         |          |         | MBSSYMEC
//         |          |         | MBSEVRQ
//         |          |         | MBNCERQ
//         |          |         | MBRCERQ
//         |          |         | MBMPERQ
//         |          |         | MBUERQ
//  1.44   | sglancy  |19-Nov-12| added ECID addresses
//  1.42   | pardeik  |09-Nov-12| add N/M throttle register in (again)
//  1.41   | gollub   |26-Oct-12| Added MBECCFIR AND/OR MASK registers
//         |          |         | Added MBSPA AND/OR MASK registers
//  1.38   | pardeik  |31-Oct-12| Added N/M Throttling Control Register
//  1.37   | aditya   |26-Oct-12| Added MCBIST Random Data Seed Registers 
//  1.36   | menlowuu |25-Oct-12| Added PHY port 1 disable bit registers
//  1.35   | menlowuu |25-Oct-12| Added PHY disable bit registers
//  1.34   | aditya   |12-Oct-12| Added MCBIST and DPHY registers
//  1.33   | baysah   |11-Oct-12| Added MBI FIR mask and action registers
//  1.32   | menlowuu |11-Oct-12| Added PHY slew calibration registers
//  1.31   | bellows  |10-Oct-12| Per Joab Request, remove duplicate trace_data reg
//  1.30   | menlowuu |09-Oct-12| Added PHY slew registers
//  1.29   | sglancy  |28-Sep-12| Added registers for loopback
//  1.28   | jdsloat  |10-Sep-12| Fixed MBA CAL Names
//  1.27   | gollub   |07-Sep-12| Fixed address for MBA01_MBA_WRD_MODE
//         |          |         | Added Maint Read Buffers 65th Byte
//  1.26   | jdsloat  |06-Sep-12| Added MBA CAL Registers
//  1.25   | gollub   |31-Aug-12| Added MBACALFIR Registers
//         |          |         | Added MBSFIR Registers
//         |          |         | Added MBAFIR Registers
//         |          |         | Added MBSPA Registers
//         |          |         | Added MBECCFIR Registers
//         |          |         | Added SCAC Registers
//  1.24   | jdsloat  |20-Aug-12| Added Primary Rank Pair MRS Shadow Regs
//  1.23   | gollub   |27-Jul-12| Added MBS FIR Registers
//         |          |         | Added DDRPHY FIR Registers
//         |          |         | Added MBA_RRQ Register
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
/************************************  ECID  **********************************/
/******************************************************************************/
CONST_UINT64_T( ECID_PART_0_0x00010000                , ULL(0x00010000) );
CONST_UINT64_T( ECID_PART_1_0x00010001                , ULL(0x00010001) );

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
CONST_UINT64_T( MBI_FIRMASK_0x02010803                 , ULL(0x02010803) );
CONST_UINT64_T( MBI_FIRACT0_0x02010806                 , ULL(0x02010806) );
CONST_UINT64_T( MBI_FIRACT1_0x02010807                 , ULL(0x02010807) );
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
CONST_UINT64_T( MEM_TRACE_STATUS_0x03010004            , ULL(0x03010004) );
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
CONST_UINT64_T( DPHY01_DDRPHY_PC_IO_PVT_FET_STATUS_P0_0x8000C01B0301143F,            ULL(0x8000C01B0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_IO_PVT_FET_STATUS_P1_0x8001C01B0301143F,            ULL(0x8001C01B0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR0_PRI_RP0_P0_0x8000C01C0301143F,                  ULL(0x8000C01C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR1_PRI_RP0_P0_0x8000C01D0301143F,                  ULL(0x8000C01D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR2_PRI_RP0_P0_0x8000C01E0301143F,                  ULL(0x8000C01E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR3_PRI_RP0_P0_0x8000C01F0301143F,                  ULL(0x8000C01F0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR0_PRI_RP1_P0_0x8000C11C0301143F,                  ULL(0x8000C11C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR1_PRI_RP1_P0_0x8000C11D0301143F,                  ULL(0x8000C11D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR2_PRI_RP1_P0_0x8000C11E0301143F,                  ULL(0x8000C11E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR3_PRI_RP1_P0_0x8000C11F0301143F,                  ULL(0x8000C11F0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR0_PRI_RP2_P0_0x8000C21C0301143F,                  ULL(0x8000C21C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR1_PRI_RP2_P0_0x8000C21D0301143F,                  ULL(0x8000C21D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR2_PRI_RP2_P0_0x8000C21E0301143F,                  ULL(0x8000C21E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR3_PRI_RP2_P0_0x8000C21F0301143F,                  ULL(0x8000C21F0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR0_PRI_RP3_P0_0x8000C31C0301143F,                  ULL(0x8000C31C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR1_PRI_RP3_P0_0x8000C31D0301143F,                  ULL(0x8000C31D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR2_PRI_RP3_P0_0x8000C31E0301143F,                  ULL(0x8000C31E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR3_PRI_RP3_P0_0x8000C31F0301143F,                  ULL(0x8000C31F0301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_PC_MR0_SEC_RP0_P0_0x8000C02C0301143F,                  ULL(0x8000C02C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR1_SEC_RP0_P0_0x8000C02D0301143F,                  ULL(0x8000C02D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR2_SEC_RP0_P0_0x8000C02E0301143F,                  ULL(0x8000C02E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR3_SEC_RP0_P0_0x8000C02F0301143F,                  ULL(0x8000C02F0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR0_SEC_RP1_P0_0x8000C12C0301143F,                  ULL(0x8000C12C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR1_SEC_RP1_P0_0x8000C12D0301143F,                  ULL(0x8000C12D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR2_SEC_RP1_P0_0x8000C12E0301143F,                  ULL(0x8000C12E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR3_SEC_RP1_P0_0x8000C12F0301143F,                  ULL(0x8000C12F0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR0_SEC_RP2_P0_0x8000C22C0301143F,                  ULL(0x8000C22C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR1_SEC_RP2_P0_0x8000C22D0301143F,                  ULL(0x8000C22D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR2_SEC_RP2_P0_0x8000C22E0301143F,                  ULL(0x8000C22E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR3_SEC_RP2_P0_0x8000C22F0301143F,                  ULL(0x8000C22F0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR0_SEC_RP3_P0_0x8000C32C0301143F,                  ULL(0x8000C32C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR1_SEC_RP3_P0_0x8000C32D0301143F,                  ULL(0x8000C32D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR2_SEC_RP3_P0_0x8000C32E0301143F,                  ULL(0x8000C32E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR3_SEC_RP3_P0_0x8000C32F0301143F,                  ULL(0x8000C32F0301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_PC_MR0_PRI_RP0_P1_0x8001C01C0301143F,                  ULL(0x8001C01C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR1_PRI_RP0_P1_0x8001C01D0301143F,                  ULL(0x8001C01D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR2_PRI_RP0_P1_0x8001C01E0301143F,                  ULL(0x8001C01E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR3_PRI_RP0_P1_0x8001C01F0301143F,                  ULL(0x8001C01F0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR0_PRI_RP1_P1_0x8001C11C0301143F,                  ULL(0x8001C11C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR1_PRI_RP1_P1_0x8001C11D0301143F,                  ULL(0x8001C11D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR2_PRI_RP1_P1_0x8001C11E0301143F,                  ULL(0x8001C11E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR3_PRI_RP1_P1_0x8001C11F0301143F,                  ULL(0x8001C11F0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR0_PRI_RP2_P1_0x8001C21C0301143F,                  ULL(0x8001C21C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR1_PRI_RP2_P1_0x8001C21D0301143F,                  ULL(0x8001C21D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR2_PRI_RP2_P1_0x8001C21E0301143F,                  ULL(0x8001C21E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR3_PRI_RP2_P1_0x8001C21F0301143F,                  ULL(0x8001C21F0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR0_PRI_RP3_P1_0x8001C31C0301143F,                  ULL(0x8001C31C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR1_PRI_RP3_P1_0x8001C31D0301143F,                  ULL(0x8001C31D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR2_PRI_RP3_P1_0x8001C31E0301143F,                  ULL(0x8001C31E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR3_PRI_RP3_P1_0x8001C31F0301143F,                  ULL(0x8001C31F0301143F) );


CONST_UINT64_T( DPHY01_DDRPHY_PC_MR0_SEC_RP0_P1_0x8001C02C0301143F,                  ULL(0x8001C02C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR1_SEC_RP0_P1_0x8001C02D0301143F,                  ULL(0x8001C02D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR2_SEC_RP0_P1_0x8001C02E0301143F,                  ULL(0x8001C02E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR3_SEC_RP0_P1_0x8001C02F0301143F,                  ULL(0x8001C02F0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR0_SEC_RP1_P1_0x8001C12C0301143F,                  ULL(0x8001C12C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR1_SEC_RP1_P1_0x8001C12D0301143F,                  ULL(0x8001C12D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR2_SEC_RP1_P1_0x8001C12E0301143F,                  ULL(0x8001C12E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR3_SEC_RP1_P1_0x8001C12F0301143F,                  ULL(0x8001C12F0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR0_SEC_RP2_P1_0x8001C22C0301143F,                  ULL(0x8001C22C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR1_SEC_RP2_P1_0x8001C22D0301143F,                  ULL(0x8001C22D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR2_SEC_RP2_P1_0x8001C22E0301143F,                  ULL(0x8001C22E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR3_SEC_RP2_P1_0x8001C22F0301143F,                  ULL(0x8001C22F0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR0_SEC_RP3_P1_0x8001C32C0301143F,                  ULL(0x8001C32C0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR1_SEC_RP3_P1_0x8001C32D0301143F,                  ULL(0x8001C32D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR2_SEC_RP3_P1_0x8001C32E0301143F,                  ULL(0x8001C32E0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_MR3_SEC_RP3_P1_0x8001C32F0301143F,                  ULL(0x8001C32F0301143F) );
//------------------------------------------------------------------------------
//   DISABLE BIT SCOM ADDRESSES (DPHY REGISTERS)
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_0_0x8000007c0301143F,		ULL(0x8000007c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_1_0x8000047c0301143F,		ULL(0x8000047c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_2_0x8000087c0301143F,		ULL(0x8000087c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_3_0x80000c7c0301143F,		ULL(0x80000c7c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_4_0x8000107c0301143F,		ULL(0x8000107c0301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_0_0x8000017c0301143F,		ULL(0x8000017c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_1_0x8000057c0301143F,		ULL(0x8000057c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_2_0x8000097c0301143F,		ULL(0x8000097c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_3_0x80000d7c0301143F,		ULL(0x80000d7c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_4_0x8000117c0301143F,		ULL(0x8000117c0301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_0_0x8000027c0301143F,		ULL(0x8000027c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_1_0x8000067c0301143F,		ULL(0x8000067c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_2_0x80000a7c0301143F,		ULL(0x80000a7c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_3_0x80000e7c0301143F,		ULL(0x80000e7c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_4_0x8000127c0301143F,		ULL(0x8000127c0301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_0_0x8000037c0301143F,		ULL(0x8000037c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_1_0x8000077c0301143F,		ULL(0x8000077c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_2_0x80000b7c0301143F,		ULL(0x80000b7c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_3_0x80000f7c0301143F,		ULL(0x80000f7c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_4_0x8000137c0301143F,		ULL(0x8000137c0301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_0_0x8001007c0301143F,		ULL(0x8001007c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_1_0x8001047c0301143F,		ULL(0x8001047c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_2_0x8001087c0301143F,		ULL(0x8001087c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_3_0x80010c7c0301143F,		ULL(0x80010c7c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_4_0x8001107c0301143F,		ULL(0x8001107c0301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_0_0x8001017c0301143F,		ULL(0x8001017c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_1_0x8001057c0301143F,		ULL(0x8001057c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_2_0x8001097c0301143F,		ULL(0x8001097c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_3_0x80010d7c0301143F,		ULL(0x80010d7c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_4_0x8001117c0301143F,		ULL(0x8001117c0301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_0_0x8001027c0301143F,		ULL(0x8001027c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_1_0x8001067c0301143F,		ULL(0x8001067c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_2_0x80010a7c0301143F,		ULL(0x80010a7c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_3_0x80010e7c0301143F,		ULL(0x80010e7c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_4_0x8001127c0301143F,		ULL(0x8001127c0301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_0_0x8001037c0301143F,		ULL(0x8001037c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_1_0x8001077c0301143F,		ULL(0x8001077c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_2_0x80010b7c0301143F,		ULL(0x80010b7c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_3_0x80010f7c0301143F,		ULL(0x80010f7c0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_4_0x8001137c0301143F,		ULL(0x8001137c0301143F) );
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
CONST_UINT64_T( MBA01_MBAFIRMASK_0x03010603        , ULL(0x03010603) );
CONST_UINT64_T( MBA01_MBAFIRMASK_AND_0x03010604    , ULL(0x03010604) );
CONST_UINT64_T( MBA01_MBAFIRMASK_OR_0x03010605     , ULL(0x03010605) );
CONST_UINT64_T( MBA01_MBAFIRACT0_0x03010606        , ULL(0x03010606) );
CONST_UINT64_T( MBA01_MBAFIRACT1_0x03010607        , ULL(0x03010607) );

//------------------------------------------------------------------------------
//      MBA Error Report Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBA_MCBERRPTQ_0x030106e7     , ULL(0x030106e7) );

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
CONST_UINT64_T( MBA01_MBSPAQ_AND_0x03010612       , ULL(0x03010612) );
CONST_UINT64_T( MBA01_MBSPAQ_OR_0x03010613        , ULL(0x03010613) );
CONST_UINT64_T( MBA01_MBSPAMSKQ_0x03010614        , ULL(0x03010614) );

//------------------------------------------------------------------------------
//      MBA Maint Read Buffers corresponding to ports 0/1
//------------------------------------------------------------------------------

// Maint Read Buffer0
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF0_DATA0_0x03010655           , ULL(0x03010655) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF0_DATA1_0x03010656           , ULL(0x03010656) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF0_DATA2_0x03010657           , ULL(0x03010657) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF0_DATA3_0x03010658           , ULL(0x03010658) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF0_DATA4_0x03010659           , ULL(0x03010659) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF0_DATA5_0x0301065a           , ULL(0x0301065a) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF0_DATA6_0x0301065b           , ULL(0x0301065b) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF0_DATA7_0x0301065c           , ULL(0x0301065c) );

// Maint Read Buffer1
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF1_DATA0_0x03010665           , ULL(0x03010665) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF1_DATA1_0x03010666           , ULL(0x03010666) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF1_DATA2_0x03010667           , ULL(0x03010667) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF1_DATA3_0x03010668           , ULL(0x03010668) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF1_DATA4_0x03010669           , ULL(0x03010669) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF1_DATA5_0x0301066a           , ULL(0x0301066a) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF1_DATA6_0x0301066b           , ULL(0x0301066b) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF1_DATA7_0x0301066c           , ULL(0x0301066c) );

// Maint Read Buffer2
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF2_DATA0_0x03010675           , ULL(0x03010675) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF2_DATA1_0x03010676           , ULL(0x03010676) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF2_DATA2_0x03010677           , ULL(0x03010677) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF2_DATA3_0x03010678           , ULL(0x03010678) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF2_DATA4_0x03010679           , ULL(0x03010679) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF2_DATA5_0x0301067a           , ULL(0x0301067a) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF2_DATA6_0x0301067b           , ULL(0x0301067b) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF2_DATA7_0x0301067c           , ULL(0x0301067c) );

// Maint Read Buffer3
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF3_DATA0_0x03010685           , ULL(0x03010685) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF3_DATA1_0x03010686           , ULL(0x03010686) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF3_DATA2_0x03010687           , ULL(0x03010687) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF3_DATA3_0x03010688           , ULL(0x03010688) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF3_DATA4_0x03010689           , ULL(0x03010689) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF3_DATA5_0x0301068a           , ULL(0x0301068a) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF3_DATA6_0x0301068b           , ULL(0x0301068b) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF3_DATA7_0x0301068c           , ULL(0x0301068c) );

// Maint Read Buffers 65th Byte
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF_65TH_BYTE_64B_ECC0_0x03010695 , ULL(0x03010695) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF_65TH_BYTE_64B_ECC1_0x03010696 , ULL(0x03010696) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF_65TH_BYTE_64B_ECC2_0x03010697 , ULL(0x03010697) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF_65TH_BYTE_64B_ECC3_0x03010698 , ULL(0x03010698) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF_65TH_BYTE_64B_ECC4_0x03010699 , ULL(0x03010699) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF_65TH_BYTE_64B_ECC5_0x0301069a , ULL(0x0301069a) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF_65TH_BYTE_64B_ECC6_0x0301069b , ULL(0x0301069b) );
CONST_UINT64_T( MAINT0_MBA_MAINT_BUFF_65TH_BYTE_64B_ECC7_0x0301069c , ULL(0x0301069c) );


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
//      MBA CAL FIR Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBACALFIR_0x03010400           , ULL(0x03010400) );
CONST_UINT64_T( MBA01_MBACALFIR_MASK_0x03010403      , ULL(0x03010403) );
CONST_UINT64_T( MBA01_MBACALFIR_MASK_AND_0x03010404  , ULL(0x03010404) );
CONST_UINT64_T( MBA01_MBACALFIR_MASK_OR_0x03010405   , ULL(0x03010405) );
CONST_UINT64_T( MBA01_MBACALFIR_ACTION0_0x03010406   , ULL(0x03010406) );
CONST_UINT64_T( MBA01_MBACALFIR_ACTION1_0x03010407   , ULL(0x03010407) );

//------------------------------------------------------------------------------
//      MBA Error report register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBA_ERR_REPORTQ_0x0301041A     , ULL(0x0301041A) );

//------------------------------------------------------------------------------
//      MBA WRD Mode Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBA_WRD_MODE_0x03010449           , ULL(0x03010449) );





//------------------------------------------------------------------------------
//      Address Translate Control Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( MBAXCR01Q_0x0201140B           , ULL(0x0201140B) );
CONST_UINT64_T( MBAXCR23Q_0x0201140C           , ULL(0x0201140C) );

//------------------------------------------------------------------------------
//      MBS ECC Decoder FIR Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( MBS_ECC0_MBECCFIR_0x02011440           , ULL(0x02011440) );
CONST_UINT64_T( MBS_ECC0_MBECCFIR_AND_0x02011441       , ULL(0x02011441) );
CONST_UINT64_T( MBS_ECC0_MBECCFIR_OR_0x02011442        , ULL(0x02011442) );
CONST_UINT64_T( MBS_ECC0_MBECCFIR_MASK_0x02011443      , ULL(0x02011443) );
CONST_UINT64_T( MBS_ECC0_MBECCFIR_MASK_AND_0x02011444  , ULL(0x02011444) );
CONST_UINT64_T( MBS_ECC0_MBECCFIR_MASK_OR_0x02011445   , ULL(0x02011445) );
CONST_UINT64_T( MBS_ECC0_MBECCFIR_ACTION0_0x02011446   , ULL(0x02011446) );
CONST_UINT64_T( MBS_ECC0_MBECCFIR_ACTION1_0x02011447   , ULL(0x02011447) );

CONST_UINT64_T( MBS_ECC1_MBECCFIR_0x02011480           , ULL(0x02011480) );
CONST_UINT64_T( MBS_ECC0_MBECCFIR_AND_0x02011481       , ULL(0x02011481) );
CONST_UINT64_T( MBS_ECC0_MBECCFIR_OR_0x02011482        , ULL(0x02011482) );
CONST_UINT64_T( MBS_ECC1_MBECCFIR_MASK_0x02011483      , ULL(0x02011483) );
CONST_UINT64_T( MBS_ECC1_MBECCFIR_MASK_AND_0x02011484  , ULL(0x02011484) );
CONST_UINT64_T( MBS_ECC1_MBECCFIR_MASK_OR_0x02011485   , ULL(0x02011485) );
CONST_UINT64_T( MBS_ECC1_MBECCFIR_ACTION0_0x02011486   , ULL(0x02011486) );
CONST_UINT64_T( MBS_ECC1_MBECCFIR_ACTION1_0x02011487   , ULL(0x02011487) );

//------------------------------------------------------------------------------
//      MBS ECC Error Report Hold Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( MBS_ECC0_MBSECCERR0_0x02011466           , ULL(0x02011466) );
CONST_UINT64_T( MBS_ECC0_MBSECCERR1_0x02011467           , ULL(0x02011467) );
CONST_UINT64_T( MBS_ECC1_MBSECCERR0_0x020114A6           , ULL(0x020114A6) );
CONST_UINT64_T( MBS_ECC1_MBSECCERR1_0x020114A7           , ULL(0x020114A7) );

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
//      MBS Maintenance Mark Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( MBS_ECC0_MBMMRQ_0x0201145B          , ULL(0x0201145B) );
CONST_UINT64_T( MBS_ECC1_MBMMRQ_0x0201149B          , ULL(0x0201149B) );

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
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF0_DATA4_0x0201160E				, ULL(0x0201160E) );

CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF0_DATA_ECC0_0x02011612			, ULL(0x02011612) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF0_DATA_ECC1_0x02011613			, ULL(0x02011613) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF0_DATA_ECC2_0x02011614			, ULL(0x02011614) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF0_DATA_ECC3_0x02011615			, ULL(0x02011615) );
CONST_UINT64_T( MAINT0_MBS_MAINT_BUFF0_DATA_ECC4_0x02011616			, ULL(0x02011616) );

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
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF0_DATA4_0x0201170E				, ULL(0x0201170E) );

CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF0_DATA_ECC0_0x02011712			, ULL(0x02011712) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF0_DATA_ECC1_0x02011713			, ULL(0x02011713) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF0_DATA_ECC2_0x02011714			, ULL(0x02011714) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF0_DATA_ECC3_0x02011715			, ULL(0x02011715) );
CONST_UINT64_T( MAINT1_MBS_MAINT_BUFF0_DATA_ECC4_0x02011716			, ULL(0x02011716) );

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
CONST_UINT64_T( MBS01_MBSTRQ_0x02011655           , ULL(0x02011655) );
CONST_UINT64_T( MBS23_MBSTRQ_0x02011755           , ULL(0x02011755) );

//------------------------------------------------------------------------------
//	    MBS Memory Scrub/Read Error Count Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( MBS01_MBSEC0Q_0x02011653           , ULL(0x02011653) );
CONST_UINT64_T( MBS01_MBSEC1Q_0x02011654           , ULL(0x02011654) );
CONST_UINT64_T( MBS23_MBSEC0Q_0x02011753           , ULL(0x02011753) );
CONST_UINT64_T( MBS23_MBSEC1Q_0x02011754           , ULL(0x02011754) );

//------------------------------------------------------------------------------
//      MBS Memory Scrub/Read Symbol Error Count Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( MBS01_MBSSYMEC0Q_0x02011656           , ULL(0x02011656) );
CONST_UINT64_T( MBS01_MBSSYMEC1Q_0x02011657           , ULL(0x02011657) );
CONST_UINT64_T( MBS01_MBSSYMEC2Q_0x02011658           , ULL(0x02011658) );
CONST_UINT64_T( MBS01_MBSSYMEC3Q_0x02011659           , ULL(0x02011659) );
CONST_UINT64_T( MBS01_MBSSYMEC4Q_0x0201165A           , ULL(0x0201165A) );
CONST_UINT64_T( MBS01_MBSSYMEC5Q_0x0201165B           , ULL(0x0201165B) );
CONST_UINT64_T( MBS01_MBSSYMEC6Q_0x0201165C           , ULL(0x0201165C) );
CONST_UINT64_T( MBS01_MBSSYMEC7Q_0x0201165D           , ULL(0x0201165D) );
CONST_UINT64_T( MBS01_MBSSYMEC8Q_0x0201165E           , ULL(0x0201165E) );
CONST_UINT64_T( MBS23_MBSSYMEC0Q_0x02011756           , ULL(0x02011756) );
CONST_UINT64_T( MBS23_MBSSYMEC1Q_0x02011757           , ULL(0x02011757) );
CONST_UINT64_T( MBS23_MBSSYMEC2Q_0x02011758           , ULL(0x02011758) );
CONST_UINT64_T( MBS23_MBSSYMEC3Q_0x02011759           , ULL(0x02011759) );
CONST_UINT64_T( MBS23_MBSSYMEC4Q_0x0201175A           , ULL(0x0201175A) );
CONST_UINT64_T( MBS23_MBSSYMEC5Q_0x0201175B           , ULL(0x0201175B) );
CONST_UINT64_T( MBS23_MBSSYMEC6Q_0x0201175C           , ULL(0x0201175C) );
CONST_UINT64_T( MBS23_MBSSYMEC7Q_0x0201175D           , ULL(0x0201175D) );
CONST_UINT64_T( MBS23_MBSSYMEC8Q_0x0201175E           , ULL(0x0201175E) );


//------------------------------------------------------------------------------
//      MBS Memory Error Vector Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBS01_MBSEVRQ_0x0201165F              , ULL(0x0201165F) );
CONST_UINT64_T( MBS23_MBSEVRQ_0x0201175F              , ULL(0x0201175F) );

//------------------------------------------------------------------------------
//      MBS Memory NCE Error Address Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBS01_MBNCERQ_0x02011660              , ULL(0x02011660) );
CONST_UINT64_T( MBS23_MBNCERQ_0x02011760              , ULL(0x02011760) );

//------------------------------------------------------------------------------
//      MBS Memory RCE Error Address Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBS01_MBRCERQ_0x02011661              , ULL(0x02011661) );
CONST_UINT64_T( MBS23_MBRCERQ_0x02011761              , ULL(0x02011761) );

//------------------------------------------------------------------------------
//      MBS Memory MPE Error Address Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBS01_MBMPERQ_0x02011662              , ULL(0x02011662) );
CONST_UINT64_T( MBS23_MBMPERQ_0x02011762              , ULL(0x02011762) );

//------------------------------------------------------------------------------
//      MBS Memory UE Error Address Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBS01_MBUERQ_0x02011663               , ULL(0x02011663) );
CONST_UINT64_T( MBS23_MBUERQ_0x02011763               , ULL(0x02011763) );

//------------------------------------------------------------------------------
//      MBS FIR Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( MBS_FIR_REG_0x02011400              , ULL(0x02011400) );
CONST_UINT64_T( MBS_FIR_MASK_REG_0x02011403         , ULL(0x02011403) );
CONST_UINT64_T( MBS_FIR_MASK_REG_AND_0x02011404     , ULL(0x02011404) );
CONST_UINT64_T( MBS_FIR_MASK_REG_OR_0x02011405      , ULL(0x02011405) );
CONST_UINT64_T( MBS_FIR_ACTION0_REG_0x02011406      , ULL(0x02011406) );
CONST_UINT64_T( MBS_FIR_ACTION1_REG_0x02011407      , ULL(0x02011407) );

//------------------------------------------------------------------------------
//      DDRPHY FIR Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( PHY01_DDRPHY_FIR_REG_0x800200900301143f             , ULL(0x800200900301143f) );
CONST_UINT64_T( PHY01_DDRPHY_FIR_MASK_REG_0x800200930301143f        , ULL(0x800200930301143f) );
CONST_UINT64_T( PHY01_DDRPHY_FIR_MASK_REG_AND_0x800200940301143f    , ULL(0x800200940301143f) );
CONST_UINT64_T( PHY01_DDRPHY_FIR_MASK_REG_OR_0x800200950301143f     , ULL(0x800200950301143f) );
CONST_UINT64_T( PHY01_DDRPHY_FIR_ACTION0_REG_0x800200960301143f     , ULL(0x800200960301143f) );
CONST_UINT64_T( PHY01_DDRPHY_FIR_ACTION1_REG_0x800200970301143f     , ULL(0x800200970301143f) );

//------------------------------------------------------------------------------
//      MBA RRQ0 Register - DDR read command parameters
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBA_RRQ0Q_0x0301040E               , ULL(0x0301040e) );

//------------------------------------------------------------------------------
//      MBA CAL Registers - DDR CAL REGs
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBA_CAL0Q_0x0301040F               , ULL(0x0301040F) );
CONST_UINT64_T( MBA01_MBA_CAL1Q_0x03010410               , ULL(0x03010410) );
CONST_UINT64_T( MBA01_MBA_CAL2Q_0x03010411               , ULL(0x03010411) );
CONST_UINT64_T( MBA01_MBA_CAL3Q_0x03010412               , ULL(0x03010412) );


//------------------------------------------------------------------------------
//      MBSFIR Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( MBS01_MBSFIRQ_0x02011600            , ULL(0x02011600) );
CONST_UINT64_T( MBS01_MBSFIRMASK_0x02011603         , ULL(0x02011603) );
CONST_UINT64_T( MBS01_MBSFIRMASK_AND_0x02011604     , ULL(0x02011604) );
CONST_UINT64_T( MBS01_MBSFIRMASK_OR_0x02011605      , ULL(0x02011605) );
CONST_UINT64_T( MBS01_MBSFIRACT0_0x02011606         , ULL(0x02011606) );
CONST_UINT64_T( MBS01_MBSFIRACT1_0x02011607         , ULL(0x02011607) );

CONST_UINT64_T( MBS23_MBSFIRQ_0x02011700            , ULL(0x02011700) );
CONST_UINT64_T( MBS23_MBSFIRMASK_0x02011703         , ULL(0x02011703) );
CONST_UINT64_T( MBS23_MBSFIRMASK_AND_0x02011704     , ULL(0x02011704) );
CONST_UINT64_T( MBS23_MBSFIRMASK_OR_0x02011705      , ULL(0x02011705) );
CONST_UINT64_T( MBS23_MBSFIRACT0_0x02011706         , ULL(0x02011706) );
CONST_UINT64_T( MBS23_MBSFIRACT1_0x02011707         , ULL(0x02011707) );

//------------------------------------------------------------------------------
//      SCAC Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( SCAC_LFIR_0x020115C0            , ULL(0x020115C0) );
CONST_UINT64_T( SCAC_FIRMASK_0x020115C3         , ULL(0x020115C3) );
CONST_UINT64_T( SCAC_FIRMASK_AND_0x020115C4     , ULL(0x020115C4) );
CONST_UINT64_T( SCAC_FIRMASK_OR_0x020115C5      , ULL(0x020115C5) );
CONST_UINT64_T( SCAC_FIRACTION0_0x020115C6      , ULL(0x020115C6) );
CONST_UINT64_T( SCAC_FIRACTION1_0x020115C7      , ULL(0x020115C7) );

//------------------------------------------------------------------------------
//      DQ/DQS Slew Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P0_0_0x800000750301143F , ULL(0x800000750301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P0_1_0x800004750301143F , ULL(0x800004750301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P0_2_0x800008750301143F , ULL(0x800008750301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P0_3_0x80000C750301143F , ULL(0x80000C750301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P0_4_0x800010750301143F , ULL(0x800010750301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P1_0_0x800100750301143F , ULL(0x800100750301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P1_1_0x800104750301143F , ULL(0x800104750301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P1_2_0x800108750301143F , ULL(0x800108750301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P1_3_0x80010C750301143F , ULL(0x80010C750301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P1_4_0x800110750301143F , ULL(0x800110750301143F) );

//------------------------------------------------------------------------------
//      ADR Slew Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P0_ADR0_0x8000401A0301143F , ULL(0x8000401A0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P0_ADR1_0x8000441A0301143F , ULL(0x8000441A0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P0_ADR2_0x8000481A0301143F , ULL(0x8000481A0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P0_ADR3_0x80004C1A0301143F , ULL(0x80004C1A0301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P1_ADR0_0x8001401A0301143F , ULL(0x8001401A0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P1_ADR1_0x8001441A0301143F , ULL(0x8001441A0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P1_ADR2_0x8001481A0301143F , ULL(0x8001481A0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P1_ADR3_0x80014C1A0301143F , ULL(0x80014C1A0301143F) );

//------------------------------------------------------------------------------
//      ADR Slew Calibration Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0_0x800080390301143F , ULL(0x800080390301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S1_0x800084390301143F , ULL(0x800084390301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_ADR_SLEW_CAL_CNTL_P1_ADR32S0_0x800180390301143F , ULL(0x800180390301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_SLEW_CAL_CNTL_P1_ADR32S1_0x800184390301143F , ULL(0x800184390301143F) );

//------------------------------------------------------------------------------
//      DQ/DQS Slew Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_VALUE_P0_0_0x800000730301143F , ULL(0x800000730301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_VALUE_P0_1_0x800004730301143F , ULL(0x800004730301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_VALUE_P0_2_0x800008730301143F , ULL(0x800008730301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_VALUE_P0_3_0x80000C730301143F , ULL(0x80000C730301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_VALUE_P0_4_0x800010730301143F , ULL(0x800010730301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_VALUE_P1_0_0x800100730301143F , ULL(0x800100730301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_VALUE_P1_1_0x800104730301143F , ULL(0x800104730301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_VALUE_P1_2_0x800108730301143F , ULL(0x800108730301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_VALUE_P1_3_0x80010C730301143F , ULL(0x80010C730301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_SYSCLK_PR_VALUE_P1_4_0x800110730301143F , ULL(0x800110730301143F) );

//------------------------------------------------------------------------------
//      ADR Slew Calibration Status Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0_0x800080340301143F , ULL(0x800080340301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S1_0x800084340301143F , ULL(0x800084340301143F) );

CONST_UINT64_T( DPHY01_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P1_ADR32S0_0x800180340301143F , ULL(0x800180340301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P1_ADR32S1_0x800184340301143F , ULL(0x800184340301143F) );

//------------------------------------------------------------------------------
// DP18 IO Driver N FET Slice Termination Enable Registers
//------------------------------------------------------------------------------

CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P0_0_0x8000007A0301143F,	           ULL(0x8000007A0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P0_1_0x8000047A0301143F,	           ULL(0x8000047A0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P0_2_0x8000087A0301143F,	           ULL(0x8000087A0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P0_3_0x80000C7A0301143F,	           ULL(0x80000C7A0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P0_4_0x8000107A0301143F,	           ULL(0x8000107A0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P1_0_0x8001007A0301143F,	           ULL(0x8001007A0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P1_1_0x8001047A0301143F,	           ULL(0x8001047A0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P1_2_0x8001087A0301143F,	           ULL(0x8001087A0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P1_3_0x80010C7A0301143F,	           ULL(0x80010C7A0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P1_4_0x8001107A0301143F,	           ULL(0x8001107A0301143F) );
                                                                                       
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P0_0_0x8000007B0301143F,	           ULL(0x8000007B0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P0_1_0x8000047B0301143F,	           ULL(0x8000047B0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P0_2_0x8000087B0301143F,	           ULL(0x8000087B0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P0_3_0x80000C7B0301143F,	           ULL(0x80000C7B0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P0_4_0x8000107B0301143F,	           ULL(0x8000107B0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P1_0_0x8001007B0301143F,	           ULL(0x8001007B0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P1_1_0x8001047B0301143F,	           ULL(0x8001047B0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P1_2_0x8001087B0301143F,	           ULL(0x8001087B0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P1_3_0x80010C7B0301143F,	           ULL(0x80010C7B0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P1_4_0x8001107B0301143F,	           ULL(0x8001107B0301143F) );

//------------------------------------------------------------------------------
// PC VREF Driver Control Registers
//------------------------------------------------------------------------------

CONST_UINT64_T( DPHY01_DDRPHY_PC_VREF_DRV_CONTROL_P0_0x8000C0150301143F,  ULL(0x8000c0150301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_PC_VREF_DRV_CONTROL_P1_0x8001C0150301143F,  ULL(0x8001c0150301143F) );

//------------------------------------------------------------------------------
// DP18 IO RX Configuration Registers
//------------------------------------------------------------------------------

CONST_UINT64_T( DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_0_0x800000060301143F,    ULL(0x800000060301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_1_0x800004060301143F,	   ULL(0x800004060301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_2_0x800008060301143F,	   ULL(0x800008060301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_3_0x80000c060301143F,	   ULL(0x80000c060301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_4_0x800010060301143F,	   ULL(0x800010060301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_0_0x800100060301143F,	   ULL(0x800100060301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_1_0x800104060301143F,	   ULL(0x800104060301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_2_0x800108060301143F,	   ULL(0x800108060301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_3_0x80010c060301143F,	   ULL(0x80010c060301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_4_0x800110060301143F,	   ULL(0x800110060301143F) );


//------------------------------------------------------------------------------
//      NFET Slice Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P0_0_0x800000780301143F , ULL(0x800000780301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P0_1_0x800004780301143F , ULL(0x800004780301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P0_2_0x800008780301143F , ULL(0x800008780301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P0_3_0x80000C780301143F , ULL(0x80000C780301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P0_4_0x800010780301143F , ULL(0x800010780301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P1_0_0x800100780301143F , ULL(0x800100780301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P1_1_0x800104780301143F , ULL(0x800104780301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P1_2_0x800108780301143F , ULL(0x800108780301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P1_3_0x80010C780301143F , ULL(0x80010C780301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P1_4_0x800110780301143F , ULL(0x800110780301143F) );

//------------------------------------------------------------------------------
//      PFET Slice Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P0_0_0x800000790301143F , ULL(0x800000790301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P0_1_0x800004790301143F , ULL(0x800004790301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P0_2_0x800008790301143F , ULL(0x800008790301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P0_3_0x80000C790301143F , ULL(0x80000C790301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P0_4_0x800010790301143F , ULL(0x800010790301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P1_0_0x800100790301143F , ULL(0x800100790301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P1_1_0x800104790301143F , ULL(0x800104790301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P1_2_0x800108790301143F , ULL(0x800108790301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P1_3_0x80010C790301143F , ULL(0x80010C790301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P1_4_0x800110790301143F , ULL(0x800110790301143F) );

//------------------------------------------------------------------------------
//      DFT Wrap Status Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DFT_WRAP_STATUS_P0_0_0x8000001D0301143F , ULL(0x8000001D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DFT_WRAP_STATUS_P0_1_0x8000041D0301143F , ULL(0x8000041D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DFT_WRAP_STATUS_P0_2_0x8000081D0301143F , ULL(0x8000081D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DFT_WRAP_STATUS_P0_3_0x80000C1D0301143F , ULL(0x80000C1D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DFT_WRAP_STATUS_P0_4_0x8000101D0301143F , ULL(0x8000101D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DFT_WRAP_STATUS_P1_0_0x8001001D0301143F , ULL(0x8001001D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DFT_WRAP_STATUS_P1_1_0x8001041D0301143F , ULL(0x8001041D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DFT_WRAP_STATUS_P1_2_0x8001081D0301143F , ULL(0x8001081D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DFT_WRAP_STATUS_P1_3_0x80010C1D0301143F , ULL(0x80010C1D0301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DFT_WRAP_STATUS_P1_4_0x8001101D0301143F , ULL(0x8001101D0301143F) );

//------------------------------------------------------------------------------
//      Data Bit Enable 0 Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P0_0_0x800000000301143F , ULL(0x800000000301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P0_1_0x800004000301143F , ULL(0x800004000301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P0_2_0x800008000301143F , ULL(0x800008000301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P0_3_0x80000C000301143F , ULL(0x80000C000301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P0_4_0x800010000301143F , ULL(0x800010000301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P1_0_0x800100000301143F , ULL(0x800100000301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P1_1_0x800104000301143F , ULL(0x800104000301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P1_2_0x800108000301143F , ULL(0x800108000301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P1_3_0x80010C000301143F , ULL(0x80010C000301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P1_4_0x800110000301143F , ULL(0x800110000301143F) );

//------------------------------------------------------------------------------
//      Data Bit Enable 1 Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P0_0_0x800000010301143F , ULL(0x800000010301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P0_1_0x800004010301143F , ULL(0x800004010301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P0_2_0x800008010301143F , ULL(0x800008010301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P0_3_0x80000C010301143F , ULL(0x80000C010301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P0_4_0x800010010301143F , ULL(0x800010010301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P1_0_0x800100010301143F , ULL(0x800100010301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P1_1_0x800104010301143F , ULL(0x800104010301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P1_2_0x800108010301143F , ULL(0x800108010301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P1_3_0x80010C010301143F , ULL(0x80010C010301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DATA_BIT_ENABLE0_P1_4_0x800110010301143F , ULL(0x800110010301143F) );

//------------------------------------------------------------------------------
//      DQS CLK Phase Rotators 0
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR0_RANK_PAIR0_P0_0_0x800000300301143F , ULL(0x800000300301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR0_RANK_PAIR0_P0_1_0x800004300301143F , ULL(0x800004300301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR0_RANK_PAIR0_P0_2_0x800008300301143F , ULL(0x800008300301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR0_RANK_PAIR0_P0_3_0x80000C300301143F , ULL(0x80000C300301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR0_RANK_PAIR0_P0_4_0x800010300301143F , ULL(0x800010300301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR0_RANK_PAIR0_P1_0_0x800100300301143F , ULL(0x800100300301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR0_RANK_PAIR0_P1_1_0x800104300301143F , ULL(0x800104300301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR0_RANK_PAIR0_P1_2_0x800108300301143F , ULL(0x800108300301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR0_RANK_PAIR0_P1_3_0x80010C300301143F , ULL(0x80010C300301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR0_RANK_PAIR0_P1_4_0x800110300301143F , ULL(0x800110300301143F) );

//------------------------------------------------------------------------------
//      DQS CLK Phase Rotators 1
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR1_RANK_PAIR0_P0_0_0x800000310301143F , ULL(0x800000310301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR1_RANK_PAIR0_P0_1_0x800004310301143F , ULL(0x800004310301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR1_RANK_PAIR0_P0_2_0x800008310301143F , ULL(0x800008310301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR1_RANK_PAIR0_P0_3_0x80000C310301143F , ULL(0x80000C310301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR1_RANK_PAIR0_P0_4_0x800010310301143F , ULL(0x800010310301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR1_RANK_PAIR0_P1_0_0x800100310301143F , ULL(0x800100310301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR1_RANK_PAIR0_P1_1_0x800104310301143F , ULL(0x800104310301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR1_RANK_PAIR0_P1_2_0x800108310301143F , ULL(0x800108310301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR1_RANK_PAIR0_P1_3_0x80010C310301143F , ULL(0x80010C310301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQSCLK_PR1_RANK_PAIR0_P1_4_0x800110310301143F , ULL(0x800110310301143F) );


//------------------------------------------------------------------------------
//      Read clock Address for all rank pairs and all ports and all DP18s
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR0_P0_0_0x800000040301143F , ULL(0x800000040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR1_P0_0_0x800001040301143F , ULL(0x800001040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR2_P0_0_0x800002040301143F , ULL(0x800002040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR3_P0_0_0x800003040301143F , ULL(0x800003040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR0_P0_1_0x800004040301143F , ULL(0x800004040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR1_P0_1_0x800005040301143F , ULL(0x800005040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR2_P0_1_0x800006040301143F , ULL(0x800006040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR3_P0_1_0x800007040301143F , ULL(0x800007040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR0_P0_2_0x800008040301143F , ULL(0x800008040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR1_P0_2_0x800009040301143F , ULL(0x800009040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR2_P0_2_0x80000A040301143F , ULL(0x80000A040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR3_P0_2_0x80000B040301143F , ULL(0x80000B040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR0_P0_3_0x80000C040301143F , ULL(0x80000C040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR1_P0_3_0x80000D040301143F , ULL(0x80000D040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR2_P0_3_0x80000E040301143F , ULL(0x80000E040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR3_P0_3_0x80000F040301143F , ULL(0x80000F040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR0_P0_4_0x800010040301143F , ULL(0x800010040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR1_P0_4_0x800011040301143F , ULL(0x800011040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR2_P0_4_0x800012040301143F , ULL(0x800012040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR3_P0_4_0x800013040301143F , ULL(0x800013040301143F));

CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR0_P1_0_0x800100040301143F , ULL(0x800100040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR1_P1_0_0x800101040301143F , ULL(0x800101040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR2_P1_0_0x800102040301143F , ULL(0x800102040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR3_P1_0_0x800103040301143F , ULL(0x800103040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR0_P1_1_0x800104040301143F , ULL(0x800104040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR1_P1_1_0x800105040301143F , ULL(0x800105040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR2_P1_1_0x800106040301143F , ULL(0x800106040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR3_P1_1_0x800107040301143F , ULL(0x800107040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR0_P1_2_0x800108040301143F , ULL(0x800108040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR1_P1_2_0x800109040301143F , ULL(0x800109040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR2_P1_2_0x80010A040301143F , ULL(0x80010A040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR3_P1_2_0x80010B040301143F , ULL(0x80010B040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR0_P1_3_0x80010C040301143F , ULL(0x80010C040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR1_P1_3_0x80010D040301143F , ULL(0x80010D040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR2_P1_3_0x80010E040301143F , ULL(0x80010E040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR3_P1_3_0x80010F040301143F , ULL(0x80010F040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR0_P1_4_0x800110040301143F , ULL(0x800110040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR1_P1_4_0x800111040301143F , ULL(0x800111040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR2_P1_4_0x800112040301143F , ULL(0x800112040301143F));
CONST_UINT64_T( DPHY01_DDRPHY_DP18_READ_CLOCK_RANK_PAIR3_P1_4_0x800113040301143F , ULL(0x800113040301143F));

//------------------------------------------------------------------------------
//     Write Clock Enable registers for Rank Pair 0
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_DP18_WRCLK_EN_RP0_P0_0_0x800000050301143F , ULL(0x800000050301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_WRCLK_EN_RP0_P0_1_0x800004050301143F , ULL(0x800004050301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_WRCLK_EN_RP0_P0_2_0x800008050301143F , ULL(0x800008050301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_WRCLK_EN_RP0_P0_3_0x80000C050301143F , ULL(0x80000C050301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_WRCLK_EN_RP0_P0_4_0x800010050301143F , ULL(0x800010050301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_WRCLK_EN_RP0_P1_0_0x800100050301143F , ULL(0x800100050301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_WRCLK_EN_RP0_P1_1_0x800104050301143F , ULL(0x800104050301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_WRCLK_EN_RP0_P1_2_0x800108050301143F , ULL(0x800108050301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_WRCLK_EN_RP0_P1_3_0x80010C050301143F , ULL(0x80010C050301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_WRCLK_EN_RP0_P1_4_0x800110050301143F , ULL(0x800110050301143F) );

//------------------------------------------------------------------------------
//     DQS Phase Select Rank Pair 0
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_0x800000090301143F , ULL(0x800000090301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_1_0x800004090301143F , ULL(0x800004090301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_2_0x800008090301143F , ULL(0x800008090301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_3_0x80000C090301143F , ULL(0x80000C090301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_4_0x800010090301143F , ULL(0x800010090301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_0_0x800100090301143F , ULL(0x800100090301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_1_0x800104090301143F , ULL(0x800104090301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_2_0x800108090301143F , ULL(0x800108090301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_3_0x80010C090301143F , ULL(0x80010C090301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_4_0x800110090301143F , ULL(0x800110090301143F) );


//------------------------------------------------------------------------------
//     DQS Gate Delay Rank Pair 0
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_0_0x800000130301143F , ULL(0x800000130301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_1_0x800004130301143F , ULL(0x800004130301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_2_0x800008130301143F , ULL(0x800008130301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_3_0x80000C130301143F , ULL(0x80000C130301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_4_0x800010130301143F , ULL(0x800010130301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_0_0x800100130301143F , ULL(0x800100130301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_1_0x800104130301143F , ULL(0x800104130301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_2_0x800108130301143F , ULL(0x800108130301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_3_0x80010C130301143F , ULL(0x80010C130301143F) );
CONST_UINT64_T( DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_4_0x800110130301143F , ULL(0x800110130301143F) );


//------------------------------------------------------------------------------
//    RC config registers 0 and 3
//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_RC_CONFIG0_P0_0x8000C8000301143F , ULL (0x8000C8000301143F));
CONST_UINT64_T( DPHY01_DDRPHY_RC_CONFIG0_P1_0x8001C8000301143F , ULL (0x8001C8000301143F));
CONST_UINT64_T( DPHY01_DDRPHY_RC_CONFIG3_P0_0x8000C8070301143F , ULL (0x8000C8070301143F));
CONST_UINT64_T( DPHY01_DDRPHY_RC_CONFIG3_P1_0x8001C8070301143F , ULL (0x8001C8070301143F));
//------------------------------------------------------------------------------
//     MBS Fixed Data Seed Registers
//------------------------------------------------------------------------------
CONST_UINT64_T( MBS_MCBIST01_MBS_MCBFD0Q_0x02011681  , ULL(0x02011681) );
CONST_UINT64_T( MBS_MCBIST01_MBS_MCBFD1Q_0x02011682  , ULL(0x02011682) );
CONST_UINT64_T( MBS_MCBIST01_MBS_MCBFD2Q_0x02011683  , ULL(0x02011683) );
CONST_UINT64_T( MBS_MCBIST01_MBS_MCBFD3Q_0x02011684  , ULL(0x02011684) );
CONST_UINT64_T( MBS_MCBIST01_MBS_MCBFD4Q_0x02011685  , ULL(0x02011685) );
CONST_UINT64_T( MBS_MCBIST01_MBS_MCBFD5Q_0x02011686  , ULL(0x02011686) );
CONST_UINT64_T( MBS_MCBIST01_MBS_MCBFD6Q_0x02011687  , ULL(0x02011687) );
CONST_UINT64_T( MBS_MCBIST01_MBS_MCBFD7Q_0x02011688  , ULL(0x02011688) );
CONST_UINT64_T( MBS_MCBIST01_MBS_MCBFDQ_0x02011689   , ULL(0x02011689) );
CONST_UINT64_T( MBS_MCBIST01_MBS_MCBFDSPQ_0x0201168A , ULL(0x0201168A) );


CONST_UINT64_T( MBS_MCBIST23_MBS_MCBFD0Q_0x02011781  , ULL(0x02011781) );
CONST_UINT64_T( MBS_MCBIST23_MBS_MCBFD1Q_0x02011782  , ULL(0x02011782) );
CONST_UINT64_T( MBS_MCBIST23_MBS_MCBFD2Q_0x02011783  , ULL(0x02011783) );
CONST_UINT64_T( MBS_MCBIST23_MBS_MCBFD3Q_0x02011784  , ULL(0x02011784) );
CONST_UINT64_T( MBS_MCBIST23_MBS_MCBFD4Q_0x02011785  , ULL(0x02011785) );
CONST_UINT64_T( MBS_MCBIST23_MBS_MCBFD5Q_0x02011786  , ULL(0x02011786) ); 
CONST_UINT64_T( MBS_MCBIST23_MBS_MCBFD6Q_0x02011787  , ULL(0x02011787) );
CONST_UINT64_T( MBS_MCBIST23_MBS_MCBFD7Q_0x02011788  , ULL(0x02011788) );
CONST_UINT64_T( MBS_MCBIST23_MBS_MCBFDQ_0x02011789   , ULL(0x02011789) );
CONST_UINT64_T( MBS_MCBIST23_MBS_MCBFDSPQ_0x0201178A , ULL(0x0201178A) );
//------------------------------------------------------------------------------
//     MBA Configured Command Sequence Registers
//------------------------------------------------------------------------------

CONST_UINT64_T( MBA01_CCS_MODEQ_0x030106a7       		, ULL(0x030106a7) );
CONST_UINT64_T( MBA01_MCBIST_MCB_CNTLSTATQ_0x030106dc	, ULL(0x030106dc) ); 
//------------------------------------------------------------------------------
//     MBA MCBIST Configuration Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MCBIST_MCBCFGQ_0x030106e0  		, ULL(0x030106e0) );

//------------------------------------------------------------------------------
//     MBS Error Map Register

//------------------------------------------------------------------------------
CONST_UINT64_T( MBS_MCBIST01_MCBEMA1Q_0x0201166a 		, ULL(0x0201166a) ); 
CONST_UINT64_T( MBS_MCBIST01_MCBEMA2Q_0x0201166b 		, ULL(0x0201166b) ); 
CONST_UINT64_T( MBS_MCBIST01_MCBEMA3Q_0x0201166c 		, ULL(0x0201166c) ); 
CONST_UINT64_T( MBS_MCBIST01_MCBEMB1Q_0x0201166d 		, ULL(0x0201166d) ); 
CONST_UINT64_T( MBS_MCBIST01_MCBEMB2Q_0x0201166e 		, ULL(0x0201166e) ); 
CONST_UINT64_T( MBS_MCBIST01_MCBEMB3Q_0x0201166f 		, ULL(0x0201166f) ); 
//------------------------------------------------------------------------------
//     MBA MCBIST Memory Register

//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MCBIST_MCBMR0Q_0x030106a8  		, ULL(0x030106a8) );         
CONST_UINT64_T( MBA01_MCBIST_MCBMR1Q_0x030106a9  		, ULL(0x030106a9) );         
CONST_UINT64_T( MBA01_MCBIST_MCBMR2Q_0x030106aa  		, ULL(0x030106aa) );         
CONST_UINT64_T( MBA01_MCBIST_MCBMR3Q_0x030106ab  		, ULL(0x030106ab) );   
CONST_UINT64_T( MBA01_MCBIST_MCBMR4Q_0x030106ac  		, ULL(0x030106ac) );      
CONST_UINT64_T( MBA01_MCBIST_MCBMR5Q_0x030106ad  		, ULL(0x030106ad) );      
CONST_UINT64_T( MBA01_MCBIST_MCBMR6Q_0x030106ae  		, ULL(0x030106ae) );  
CONST_UINT64_T( MBA01_MCBIST_MCBMR7Q_0x030106df  		, ULL(0x030106df) ); 
CONST_UINT64_T( MBA01_MCBIST_RUNTIMECTRQ_0x030106b0		, ULL(0x030106b0) ); 
//------------------------------------------------------------------------------
//     MBA Fixed Data Seed Registers

//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MCBIST_MCBFD0Q_0x030106be  		, ULL(0x030106be) );
CONST_UINT64_T( MBA01_MCBIST_MCBFD1Q_0x030106bf  		, ULL(0x030106bf) );      
CONST_UINT64_T( MBA01_MCBIST_MCBFD2Q_0x030106c0  		, ULL(0x030106c0) );         
CONST_UINT64_T( MBA01_MCBIST_MCBFD3Q_0x030106c1  		, ULL(0x030106c1) );         
CONST_UINT64_T( MBA01_MCBIST_MCBFD4Q_0x030106c2  		, ULL(0x030106c2) );         
CONST_UINT64_T( MBA01_MCBIST_MCBFD5Q_0x030106c3  		, ULL(0x030106c3) );   
CONST_UINT64_T( MBA01_MCBIST_MCBFD6Q_0x030106c4  		, ULL(0x030106c4) );   
CONST_UINT64_T( MBA01_MCBIST_MCBFD7Q_0x030106c5  		, ULL(0x030106c5) );   
CONST_UINT64_T( MBA01_MCBIST_MCBFDQ_0x030106c6   		, ULL(0x030106c6) );   
CONST_UINT64_T( MBA01_MCBIST_MCBFDSPQ_0x030106c7 		, ULL(0x030106c7) ); 
//------------------------------------------------------------------------------
//     MBA Data Rotate Configuration Register

//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MCBIST_MCBDRCRQ_0x030106bd 		, ULL(0x030106bd) );
//------------------------------------------------------------------------------
//    MBS Compare Mask Registers

//------------------------------------------------------------------------------
CONST_UINT64_T( MBS_MCBIST01_MCBCMA1Q_0x02011672 		, ULL(0x02011672) );

CONST_UINT64_T( MBS_MCBIST01_MCBCMB1Q_0x02011673 		, ULL(0x02011673) );      
CONST_UINT64_T( MBS_MCBIST01_MCBCMABQ_0x02011674 		, ULL(0x02011674) );
//------------------------------------------------------------------------------
//    MBA MCBIST Control Register

//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MCBIST_MCB_CNTLQ_0x030106db		, ULL(0x030106db) );
//------------------------------------------------------------------------------
//    MBA MCBIST Memory Parameter Register

//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MCBIST_MCBPARMQ_0x030106af 		, ULL(0x030106af) ); 
//------------------------------------------------------------------------------
//    MBA Address Map Registers

//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MCBIST_MCBAMR0A0Q_0x030106c8, ULL(0x030106c8) );      
CONST_UINT64_T( MBA01_MCBIST_MCBAMR1A0Q_0x030106c9, ULL(0x030106c9) );    
CONST_UINT64_T( MBA01_MCBIST_MCBAMR2A0Q_0x030106ca, ULL(0x030106ca) );       
CONST_UINT64_T( MBA01_MCBIST_MCBAMR3A0Q_0x030106cb, ULL(0x030106cb) ); 
      
CONST_UINT64_T( MBA01_MCBIST_MCBAMR0A1Q_0x030106d7, ULL(0x030106d7) );  
  
CONST_UINT64_T( MBA01_MCBIST_MCBAMR1A1Q_0x030106d8, ULL(0x030106d8) );   
CONST_UINT64_T( MBA01_MCBIST_MCBAMR2A1Q_0x030106d9, ULL(0x030106d9) );   
CONST_UINT64_T( MBA01_MCBIST_MCBAMR3A1Q_0x030106da, ULL(0x030106da) ); 
  
CONST_UINT64_T( MBA01_MCBIST_MCBLFSRA0Q_0x030106d4, ULL(0x030106d4) );  
CONST_UINT64_T( MBA01_MCBIST_MCBLFSRA1Q_0x030106d5, ULL(0x030106d5) );   
CONST_UINT64_T( MBA01_MCBIST_MCBSEARA0Q_0x030106d2, ULL(0x030106d2) );  
CONST_UINT64_T( MBA01_MCBIST_MCBSEARA1Q_0x030106d3, ULL(0x030106d3) );   
CONST_UINT64_T( MBA01_MCBIST_MCBRSARA0Q_0x030106cc, ULL(0x030106cc) );   

CONST_UINT64_T( MBA01_MCBIST_MCBRSARA1Q_0x030106cd, ULL(0x030106cd) ); 
  
CONST_UINT64_T( MBA01_MCBIST_MCBREARA0Q_0x030106ce, ULL(0x030106ce) );   
CONST_UINT64_T( MBA01_MCBIST_MCBREARA1Q_0x030106cf, ULL(0x030106cf) );   
CONST_UINT64_T( MBA01_MCBIST_MCBSSARA0Q_0x030106d0, ULL(0x030106d0) );   
CONST_UINT64_T( MBA01_MCBIST_MCBSSARA1Q_0x030106d1, ULL(0x030106d1) ); 
CONST_UINT64_T( MBA01_MCBIST_MCBAGRAQ_0x030106d6  , ULL(0x030106d6) );
//------------------------------------------------------------------------------
//    MBA Performance monitor  Registers

//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBA_PMU0Q_0x03010437        , ULL(0x03010437) );  
//------------------------------------------------------------------------------
//    MBA Maintenance Buffer Registers

//------------------------------------------------------------------------------
CONST_UINT64_T( MBS_MCBIST01_MCB_ERRCNTA1Q_0x02011664, ULL(0x02011664) );   
CONST_UINT64_T( MBS_MCBIST01_MCB_ERRCNTA2Q_0x02011665, ULL(0x02011665) );   
CONST_UINT64_T( MBS_MCBIST01_MCB_ERRCNTB1Q_0x02011667, ULL(0x02011667) );   
CONST_UINT64_T( MBS_MCBIST01_MCB_ERRCNTB2Q_0x02011668, ULL(0x02011668) );   
//------------------------------------------------------------------------------
//    DPHY01 PC Rank Pair Registers

//------------------------------------------------------------------------------
CONST_UINT64_T( DPHY01_DDRPHY_PC_RANK_PAIR0_P0, ULL(0x8000c0020301143f) );   
CONST_UINT64_T( DPHY01_DDRPHY_PC_RANK_PAIR0_P1, ULL(0x8001c0020301143f) );   
CONST_UINT64_T( DPHY01_DDRPHY_PC_RANK_PAIR1_P0, ULL(0x8000c0030301143f) );   
CONST_UINT64_T( DPHY01_DDRPHY_PC_RANK_PAIR1_P1, ULL(0x8001c0030301143f) );   
CONST_UINT64_T( DPHY01_DDRPHY_PC_RANK_PAIR2_P0, ULL(0x8000c0300301143f) );   
CONST_UINT64_T( DPHY01_DDRPHY_PC_RANK_PAIR2_P1, ULL(0x8001c0300301143f) ); 
CONST_UINT64_T( DPHY01_DDRPHY_PC_RANK_PAIR3_P0, ULL(0x8000c0310301143f) ); 
CONST_UINT64_T( DPHY01_DDRPHY_PC_RANK_PAIR3_P1, ULL(0x8001c0310301143f) ); 
//------------------------------------------------------------------------------
//    MCBIST Random Data Seed Registers

//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MCBIST_MCBRDS0Q_0x030106b2                     , ULL(0x030106b2) );
CONST_UINT64_T( MBA01_MCBIST_MCBRDS1Q_0x030106b3                     , ULL(0x030106b3) );
CONST_UINT64_T( MBA01_MCBIST_MCBRDS2Q_0x030106b4                     , ULL(0x030106b4) );
CONST_UINT64_T( MBA01_MCBIST_MCBRDS3Q_0x030106b5                     , ULL(0x030106b5) );
CONST_UINT64_T( MBA01_MCBIST_MCBRDS4Q_0x030106b6                     , ULL(0x030106b6) );
CONST_UINT64_T( MBA01_MCBIST_MCBRDS5Q_0x030106b7                     , ULL(0x030106b7) );
CONST_UINT64_T( MBA01_MCBIST_MCBRDS6Q_0x030106b8                     , ULL(0x030106b8) );
CONST_UINT64_T( MBA01_MCBIST_MCBRDS7Q_0x030106b9                     , ULL(0x030106b9) );
CONST_UINT64_T( MBA01_MCBIST_MCBRDS8Q_0x030106ba                     , ULL(0x030106ba) );
CONST_UINT64_T( MBA01_MCBIST_MCBDRSRQ_0x030106bc                     , ULL(0x030106bc) );
//------------------------------------------------------------------------------
//    N/M Throttling Control Register
//------------------------------------------------------------------------------
CONST_UINT64_T( MBA01_MBA_FARB3Q_0x03010416, ULL(0x03010416) );


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
Revision 1.46  2012/12/19 15:31:24  gollub

Added:
MCBERRPTQ
MBA_MAINT_BUFF
MBA_MAINT_BUFF_65TH_BYTE_64B_ECC
MBA_ERR_REPORTQ
MBSECCERR
MBMMRQ
MBS_MAINT_BUFF0_DATA
MBS_MAINT_BUFF0_DATA_ECC
MBSEC
MBSSYMEC
MBSEVRQ
MBNCERQ
MBRCERQ
MBMPERQ
MBUERQ

Revision 1.45  2012/11/20 18:51:15  lapietra
Fixed errors in get_data

Revision 1.44  2012/11/19 16:17:47  lapietra
Added ECID Addresses

Revision 1.43  2012/11/19 05:08:15  jmcgill
add mem chiplet debug status register

Revision 1.42  2012/11/09 14:53:43  pardeik
added N/M throttle register back in... somehow it was removed

Revision 1.41  2012/11/09 14:47:30  gollub

Added MBECCFIR AND/OR MASK registers
Added MBSPA AND/OR MASK registers

Revision 1.40  2012/11/08 15:54:21  lapietra
Added addresses necessary for loopback characerization test

Revision 1.39  2012/10/31 13:44:30  pardeik
Added N/M throttling control register

Revision 1.38  2012/10/26 09:44:56  sasethur
 Added MCBIST Random Data Seed Registers

Revision 1.37  2012/10/26 02:05:07  mwuu
Added PHY port 1 disable bit registers

Revision 1.36  2012/10/26 00:19:53  mwuu
Added PHY disable bit registers

Revision 1.35  2012/10/16 03:44:53  jmcgill
restore TP trace array address constants (Centaur addresses here are unique and are not the same as those included in common_scom_addresses header)

Revision 1.34  2012/10/12 12:43:32  sasethur
Added MCBIST and DPHY registers

Revision 1.33  2012/10/12 03:17:07  baysah
Added MBI FIR mask and action registers.

Revision 1.32  2012/10/11 22:39:53  mwuu
Added PHY slew calibration registers

Revision 1.31  2012/10/10 21:26:29  bellows
removed duplicate scom address

Revision 1.30  2012/10/09 18:15:46  mwuu
Added PHY slew registers

Revision 1.29  2012/09/28 13:32:34  lapietra
Added registers for loopback (NFET/PFET Slice, DFT Wrap Status, Data Bit Enable 0/1, Read clock, write clock, and RC config 0 and 3 registers)

Revision 1.28  2012/09/10 14:34:14  jdsloat
Fixed MBA CAL Names

Revision 1.27  2012/09/07 21:29:39  gollub

Fixed address for MBA01_MBA_WRD_MODE
Added Maint Read Buffers 65th Byte

Revision 1.26  2012/09/06 18:39:34  jdsloat
Added MBA CAL Registers

Revision 1.25  2012/09/06 13:28:25  gollub

Added more FIR registers.

Revision 1.24  2012/08/20 17:12:23  jdsloat
Added Primary Rank Pair MRS Shadow Regs

Revision 1.23  2012/08/17 20:15:03  gollub

Added MBS FIR Registers
Added DDRPHY FIR Registers
Added MBA_RRQ Register

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
