/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/common/include/p9_mc_scom_addresses_fixes.H $        */
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
/// @file mc_scom_addresses_fixes.H
/// @brief The *scom_addresses.H files are  generated form figtree, but
///        the figree can be wrong.  This file is included at the end
///        of scom_addresses.H and allows incorrect constants to be
///        fixed manually.
///
// *HWP HWP Owner: Ben Gass <bgass@us.ibm.com>
// *HWP FW Owner: ? <?>
// *HWP Team: SAO
// *HWP Level: 1
// *HWP Consumed by: FSP:HB:HS:OCC:SBE:CME:SGPE:PGPE:FPPE:IPPE

#ifndef __P9_MC_SCOM_ADDRESSES_FIXES_H
#define __P9_MC_SCOM_ADDRESSES_FIXES_H

// More of an addition than a fix.
REG64( MCA_MBA_MCP0XLT0                                     , RULL(0x05010820), SH_UNT_MCA      , SH_ACS_SCOM_RW   );
REG64( MCA_MBA_MCP0XLT1                                     , RULL(0x05010821), SH_UNT_MCA      , SH_ACS_SCOM_RW   );
REG64( MCA_MBA_MCP0XLT2                                     , RULL(0x05010822), SH_UNT_MCA      , SH_ACS_SCOM_RW   );

// FIXREG64( MCBIST_MCBIST_CCSARRERRINJQ                                    , RULL(0x07010FDE),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701219E) );
// FIXREG64( MCBIST_MCBIST_0_CCSARRERRINJQ                                  , RULL(0x07010FDE),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701219E) );
// FIXREG64( MCBIST_MCBIST_1_CCSARRERRINJQ                                  , RULL(0x08010FDE),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801219E) );
// FIXREG64( MCBIST_MCBIST_CCS_CNTLQ                                        , RULL(0x07010FA5),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012165) );
// FIXREG64( MCBIST_MCBIST_0_CCS_CNTLQ                                      , RULL(0x07010FA5),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012165) );
// FIXREG64( MCBIST_MCBIST_1_CCS_CNTLQ                                      , RULL(0x08010FA5),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012165) );
// FIXREG64( MCBIST_MCBIST_CCS_FIXED_DATA0Q                                 , RULL(0x07010FE5),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070121A5) );
// FIXREG64( MCBIST_MCBIST_0_CCS_FIXED_DATA0Q                               , RULL(0x07010FE5),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070121A5) );
// FIXREG64( MCBIST_MCBIST_1_CCS_FIXED_DATA0Q                               , RULL(0x08010FE5),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080121A5) );
// FIXREG64( MCBIST_MCBIST_CCS_FIXED_DATA1Q                                 , RULL(0x07010FE6),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070121A6) );
// FIXREG64( MCBIST_MCBIST_0_CCS_FIXED_DATA1Q                               , RULL(0x07010FE6),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070121A6) );
// FIXREG64( MCBIST_MCBIST_1_CCS_FIXED_DATA1Q                               , RULL(0x08010FE6),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080121A6) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_00                                 , RULL(0x07010F15),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120D5) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_00                               , RULL(0x07010F15),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120D5) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_00                               , RULL(0x08010F15),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120D5) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_01                                 , RULL(0x07010F16),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120D6) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_01                               , RULL(0x07010F16),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120D6) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_01                               , RULL(0x08010F16),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120D6) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_02                                 , RULL(0x07010F17),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120D7) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_02                               , RULL(0x07010F17),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120D7) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_02                               , RULL(0x08010F17),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120D7) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_03                                 , RULL(0x07010F18),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120D8) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_03                               , RULL(0x07010F18),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120D8) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_03                               , RULL(0x08010F18),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120D8) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_04                                 , RULL(0x07010F19),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120D9) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_04                               , RULL(0x07010F19),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120D9) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_04                               , RULL(0x08010F19),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120D9) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_05                                 , RULL(0x07010F1A),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120DA) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_05                               , RULL(0x07010F1A),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120DA) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_05                               , RULL(0x08010F1A),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120DA) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_06                                 , RULL(0x07010F1B),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120DB) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_06                               , RULL(0x07010F1B),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120DB) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_06                               , RULL(0x08010F1B),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120DB) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_07                                 , RULL(0x07010F1C),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120DC) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_07                               , RULL(0x07010F1C),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120DC) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_07                               , RULL(0x08010F1C),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120DC) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_08                                 , RULL(0x07010F1D),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120DD) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_08                               , RULL(0x07010F1D),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120DD) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_08                               , RULL(0x08010F1D),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120DD) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_09                                 , RULL(0x07010F1E),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120DE) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_09                               , RULL(0x07010F1E),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120DE) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_09                               , RULL(0x08010F1E),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120DE) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_10                                 , RULL(0x07010F1F),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120DF) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_10                               , RULL(0x07010F1F),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120DF) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_10                               , RULL(0x08010F1F),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120DF) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_11                                 , RULL(0x07010F20),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E0) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_11                               , RULL(0x07010F20),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E0) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_11                               , RULL(0x08010F20),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120E0) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_12                                 , RULL(0x07010F21),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E1) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_12                               , RULL(0x07010F21),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E1) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_12                               , RULL(0x08010F21),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120E1) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_13                                 , RULL(0x07010F22),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E2) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_13                               , RULL(0x07010F22),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E2) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_13                               , RULL(0x08010F22),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120E2) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_14                                 , RULL(0x07010F23),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E3) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_14                               , RULL(0x07010F23),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E3) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_14                               , RULL(0x08010F23),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120E3) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_15                                 , RULL(0x07010F24),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E4) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_15                               , RULL(0x07010F24),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E4) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_15                               , RULL(0x08010F24),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120E4) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_16                                 , RULL(0x07010F25),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E5) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_16                               , RULL(0x07010F25),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E5) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_16                               , RULL(0x08010F25),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120E5) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_17                                 , RULL(0x07010F26),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E6) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_17                               , RULL(0x07010F26),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E6) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_17                               , RULL(0x08010F26),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120E6) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_18                                 , RULL(0x07010F27),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E7) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_18                               , RULL(0x07010F27),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E7) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_18                               , RULL(0x08010F27),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120E7) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_19                                 , RULL(0x07010F28),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E8) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_19                               , RULL(0x07010F28),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E8) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_19                               , RULL(0x08010F28),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120E8) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_20                                 , RULL(0x07010F29),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E9) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_20                               , RULL(0x07010F29),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120E9) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_20                               , RULL(0x08010F29),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120E9) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_21                                 , RULL(0x07010F2A),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120EA) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_21                               , RULL(0x07010F2A),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120EA) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_21                               , RULL(0x08010F2A),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120EA) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_22                                 , RULL(0x07010F2B),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120EB) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_22                               , RULL(0x07010F2B),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120EB) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_22                               , RULL(0x08010F2B),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120EB) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_23                                 , RULL(0x07010F2C),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120EC) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_23                               , RULL(0x07010F2C),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120EC) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_23                               , RULL(0x08010F2C),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120EC) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_24                                 , RULL(0x07010F2D),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120ED) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_24                               , RULL(0x07010F2D),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120ED) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_24                               , RULL(0x08010F2D),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120ED) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_25                                 , RULL(0x07010F2E),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120EE) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_25                               , RULL(0x07010F2E),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120EE) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_25                               , RULL(0x08010F2E),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120EE) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_26                                 , RULL(0x07010F2F),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120EF) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_26                               , RULL(0x07010F2F),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120EF) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_26                               , RULL(0x08010F2F),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120EF) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_27                                 , RULL(0x07010F30),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F0) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_27                               , RULL(0x07010F30),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F0) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_27                               , RULL(0x08010F30),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120F0) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_28                                 , RULL(0x07010F31),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F1) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_28                               , RULL(0x07010F31),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F1) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_28                               , RULL(0x08010F31),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120F1) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_29                                 , RULL(0x07010F32),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F2) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_29                               , RULL(0x07010F32),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F2) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_29                               , RULL(0x08010F32),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120F2) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_30                                 , RULL(0x07010F33),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F3) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_30                               , RULL(0x07010F33),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F3) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_30                               , RULL(0x08010F33),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120F3) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR0_31                                 , RULL(0x07010F34),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F4) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR0_31                               , RULL(0x07010F34),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F4) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR0_31                               , RULL(0x08010F34),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120F4) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_00                                 , RULL(0x07010F35),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F5) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_00                               , RULL(0x07010F35),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F5) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_00                               , RULL(0x08010F35),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120F5) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_01                                 , RULL(0x07010F36),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F6) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_01                               , RULL(0x07010F36),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F6) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_01                               , RULL(0x08010F36),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120F6) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_02                                 , RULL(0x07010F37),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F7) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_02                               , RULL(0x07010F37),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F7) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_02                               , RULL(0x08010F37),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120F7) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_03                                 , RULL(0x07010F38),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F8) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_03                               , RULL(0x07010F38),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F8) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_03                               , RULL(0x08010F38),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120F8) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_04                                 , RULL(0x07010F39),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F9) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_04                               , RULL(0x07010F39),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120F9) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_04                               , RULL(0x08010F39),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120F9) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_05                                 , RULL(0x07010F3A),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120FA) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_05                               , RULL(0x07010F3A),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120FA) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_05                               , RULL(0x08010F3A),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120FA) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_06                                 , RULL(0x07010F3B),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120FB) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_06                               , RULL(0x07010F3B),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120FB) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_06                               , RULL(0x08010F3B),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120FB) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_07                                 , RULL(0x07010F3C),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120FC) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_07                               , RULL(0x07010F3C),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120FC) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_07                               , RULL(0x08010F3C),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120FC) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_08                                 , RULL(0x07010F3D),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120FD) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_08                               , RULL(0x07010F3D),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120FD) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_08                               , RULL(0x08010F3D),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120FD) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_09                                 , RULL(0x07010F3E),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120FE) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_09                               , RULL(0x07010F3E),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120FE) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_09                               , RULL(0x08010F3E),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120FE) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_10                                 , RULL(0x07010F3F),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120FF) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_10                               , RULL(0x07010F3F),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120FF) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_10                               , RULL(0x08010F3F),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120FF) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_11                                 , RULL(0x07010F40),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012100) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_11                               , RULL(0x07010F40),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012100) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_11                               , RULL(0x08010F40),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012100) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_12                                 , RULL(0x07010F41),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012101) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_12                               , RULL(0x07010F41),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012101) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_12                               , RULL(0x08010F41),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012101) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_13                                 , RULL(0x07010F42),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012102) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_13                               , RULL(0x07010F42),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012102) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_13                               , RULL(0x08010F42),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012102) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_14                                 , RULL(0x07010F43),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012103) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_14                               , RULL(0x07010F43),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012103) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_14                               , RULL(0x08010F43),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012103) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_15                                 , RULL(0x07010F44),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012104) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_15                               , RULL(0x07010F44),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012104) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_15                               , RULL(0x08010F44),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012104) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_16                                 , RULL(0x07010F45),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012105) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_16                               , RULL(0x07010F45),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012105) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_16                               , RULL(0x08010F45),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012105) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_17                                 , RULL(0x07010F46),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012106) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_17                               , RULL(0x07010F46),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012106) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_17                               , RULL(0x08010F46),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012106) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_18                                 , RULL(0x07010F47),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012107) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_18                               , RULL(0x07010F47),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012107) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_18                               , RULL(0x08010F47),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012107) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_19                                 , RULL(0x07010F48),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012108) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_19                               , RULL(0x07010F48),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012108) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_19                               , RULL(0x08010F48),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012108) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_20                                 , RULL(0x07010F49),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012109) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_20                               , RULL(0x07010F49),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012109) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_20                               , RULL(0x08010F49),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012109) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_21                                 , RULL(0x07010F4A),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701210A) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_21                               , RULL(0x07010F4A),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701210A) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_21                               , RULL(0x08010F4A),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801210A) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_22                                 , RULL(0x07010F4B),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701210B) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_22                               , RULL(0x07010F4B),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701210B) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_22                               , RULL(0x08010F4B),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801210B) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_23                                 , RULL(0x07010F4C),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701210C) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_23                               , RULL(0x07010F4C),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701210C) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_23                               , RULL(0x08010F4C),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801210C) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_24                                 , RULL(0x07010F4D),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701210D) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_24                               , RULL(0x07010F4D),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701210D) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_24                               , RULL(0x08010F4D),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801210D) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_25                                 , RULL(0x07010F4E),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701210E) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_25                               , RULL(0x07010F4E),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701210E) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_25                               , RULL(0x08010F4E),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801210E) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_26                                 , RULL(0x07010F4F),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701210F) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_26                               , RULL(0x07010F4F),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701210F) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_26                               , RULL(0x08010F4F),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801210F) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_27                                 , RULL(0x07010F50),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012110) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_27                               , RULL(0x07010F50),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012110) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_27                               , RULL(0x08010F50),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012110) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_28                                 , RULL(0x07010F51),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012111) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_28                               , RULL(0x07010F51),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012111) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_28                               , RULL(0x08010F51),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012111) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_29                                 , RULL(0x07010F52),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012112) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_29                               , RULL(0x07010F52),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012112) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_29                               , RULL(0x08010F52),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012112) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_30                                 , RULL(0x07010F53),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012113) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_30                               , RULL(0x07010F53),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012113) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_30                               , RULL(0x08010F53),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012113) );
// FIXREG64( MCBIST_MCBIST_CCS_INST_ARR1_31                                 , RULL(0x07010F54),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012114) );
// FIXREG64( MCBIST_MCBIST_0_CCS_INST_ARR1_31                               , RULL(0x07010F54),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012114) );
// FIXREG64( MCBIST_MCBIST_1_CCS_INST_ARR1_31                               , RULL(0x08010F54),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012114) );
// FIXREG64( MCBIST_MCBIST_CCS_MODEQ                                        , RULL(0x07010FA7),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012167) );
// FIXREG64( MCBIST_MCBIST_0_CCS_MODEQ                                      , RULL(0x07010FA7),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012167) );
// FIXREG64( MCBIST_MCBIST_1_CCS_MODEQ                                      , RULL(0x08010FA7),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012167) );
// FIXREG64( MCBIST_MCBIST_CCS_STATQ                                        , RULL(0x07010FA6),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012166) );
// FIXREG64( MCBIST_MCBIST_0_CCS_STATQ                                      , RULL(0x07010FA6),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012166) );
// FIXREG64( MCBIST_MCBIST_1_CCS_STATQ                                      , RULL(0x08010FA6),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012166) );
// FIXREG64( MCBIST_MCBIST_MBAUER0Q                                         , RULL(0x07010F6E),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701212E) );
// FIXREG64( MCBIST_MCBIST_0_MBAUER0Q                                       , RULL(0x07010F6E),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701212E) );
// FIXREG64( MCBIST_MCBIST_1_MBAUER0Q                                       , RULL(0x08010F6E),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801212E) );
// FIXREG64( MCBIST_MCBIST_MBAUER1Q                                         , RULL(0x07010F73),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012133) );
// FIXREG64( MCBIST_MCBIST_0_MBAUER1Q                                       , RULL(0x07010F73),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012133) );
// FIXREG64( MCBIST_MCBIST_1_MBAUER1Q                                       , RULL(0x08010F73),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012133) );
// FIXREG64( MCBIST_MCBIST_MBAUER2Q                                         , RULL(0x07010F78),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012138) );
// FIXREG64( MCBIST_MCBIST_0_MBAUER2Q                                       , RULL(0x07010F78),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012138) );
// FIXREG64( MCBIST_MCBIST_1_MBAUER2Q                                       , RULL(0x08010F78),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012138) );
// FIXREG64( MCBIST_MCBIST_MBAUER3Q                                         , RULL(0x07010F7D),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701213D) );
// FIXREG64( MCBIST_MCBIST_0_MBAUER3Q                                       , RULL(0x07010F7D),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701213D) );
// FIXREG64( MCBIST_MCBIST_1_MBAUER3Q                                       , RULL(0x08010F7D),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801213D) );
// FIXREG64( MCBIST_MCBIST_MBA_MCBERRPTQ                                    , RULL(0x07010FE7),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RO   , RULL(0x070121A7) );
// FIXREG64( MCBIST_MCBIST_0_MBA_MCBERRPTQ                                  , RULL(0x07010FE7),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RO   , RULL(0x070121A7) );
// FIXREG64( MCBIST_MCBIST_1_MBA_MCBERRPTQ                                  , RULL(0x08010FE7),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RO   , RULL(0x080121A7) );
// FIXREG64( MCBIST_MCBIST_MBECTLQ                                          , RULL(0x07010F10),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120D0) );
// FIXREG64( MCBIST_MCBIST_0_MBECTLQ                                        , RULL(0x07010F10),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120D0) );
// FIXREG64( MCBIST_MCBIST_1_MBECTLQ                                        , RULL(0x08010F10),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120D0) );
// FIXREG64( MCBIST_MCBIST_MBMPER0Q                                         , RULL(0x07010F6C),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701212C) );
// FIXREG64( MCBIST_MCBIST_0_MBMPER0Q                                       , RULL(0x07010F6C),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701212C) );
// FIXREG64( MCBIST_MCBIST_1_MBMPER0Q                                       , RULL(0x08010F6C),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801212C) );
// FIXREG64( MCBIST_MCBIST_MBMPER1Q                                         , RULL(0x07010F71),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012131) );
// FIXREG64( MCBIST_MCBIST_0_MBMPER1Q                                       , RULL(0x07010F71),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012131) );
// FIXREG64( MCBIST_MCBIST_1_MBMPER1Q                                       , RULL(0x08010F71),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012131) );
// FIXREG64( MCBIST_MCBIST_MBMPER2Q                                         , RULL(0x07010F76),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012136) );
// FIXREG64( MCBIST_MCBIST_0_MBMPER2Q                                       , RULL(0x07010F76),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012136) );
// FIXREG64( MCBIST_MCBIST_1_MBMPER2Q                                       , RULL(0x08010F76),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012136) );
// FIXREG64( MCBIST_MCBIST_MBMPER3Q                                         , RULL(0x07010F7B),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701213B) );
// FIXREG64( MCBIST_MCBIST_0_MBMPER3Q                                       , RULL(0x07010F7B),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701213B) );
// FIXREG64( MCBIST_MCBIST_1_MBMPER3Q                                       , RULL(0x08010F7B),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801213B) );
// FIXREG64( MCBIST_MCBIST_MBNCER0Q                                         , RULL(0x07010F6A),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701212A) );
// FIXREG64( MCBIST_MCBIST_0_MBNCER0Q                                       , RULL(0x07010F6A),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701212A) );
// FIXREG64( MCBIST_MCBIST_1_MBNCER0Q                                       , RULL(0x08010F6A),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801212A) );
// FIXREG64( MCBIST_MCBIST_MBNCER1Q                                         , RULL(0x07010F6F),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701212F) );
// FIXREG64( MCBIST_MCBIST_0_MBNCER1Q                                       , RULL(0x07010F6F),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701212F) );
// FIXREG64( MCBIST_MCBIST_1_MBNCER1Q                                       , RULL(0x08010F6F),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801212F) );
// FIXREG64( MCBIST_MCBIST_MBNCER2Q                                         , RULL(0x07010F74),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012134) );
// FIXREG64( MCBIST_MCBIST_0_MBNCER2Q                                       , RULL(0x07010F74),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012134) );
// FIXREG64( MCBIST_MCBIST_1_MBNCER2Q                                       , RULL(0x08010F74),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012134) );
// FIXREG64( MCBIST_MCBIST_MBNCER3Q                                         , RULL(0x07010F79),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012139) );
// FIXREG64( MCBIST_MCBIST_0_MBNCER3Q                                       , RULL(0x07010F79),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012139) );
// FIXREG64( MCBIST_MCBIST_1_MBNCER3Q                                       , RULL(0x08010F79),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012139) );
// FIXREG64( MCBIST_MCBIST_MBRCER0Q                                         , RULL(0x07010F6B),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701212B) );
// FIXREG64( MCBIST_MCBIST_0_MBRCER0Q                                       , RULL(0x07010F6B),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701212B) );
// FIXREG64( MCBIST_MCBIST_1_MBRCER0Q                                       , RULL(0x08010F6B),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801212B) );
// FIXREG64( MCBIST_MCBIST_MBRCER1Q                                         , RULL(0x07010F70),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012130) );
// FIXREG64( MCBIST_MCBIST_0_MBRCER1Q                                       , RULL(0x07010F70),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012130) );
// FIXREG64( MCBIST_MCBIST_1_MBRCER1Q                                       , RULL(0x08010F70),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012130) );
// FIXREG64( MCBIST_MCBIST_MBRCER2Q                                         , RULL(0x07010F75),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012135) );
// FIXREG64( MCBIST_MCBIST_0_MBRCER2Q                                       , RULL(0x07010F75),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012135) );
// FIXREG64( MCBIST_MCBIST_1_MBRCER2Q                                       , RULL(0x08010F75),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012135) );
// FIXREG64( MCBIST_MCBIST_MBRCER3Q                                         , RULL(0x07010F7A),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701213A) );
// FIXREG64( MCBIST_MCBIST_0_MBRCER3Q                                       , RULL(0x07010F7A),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701213A) );
// FIXREG64( MCBIST_MCBIST_1_MBRCER3Q                                       , RULL(0x08010F7A),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801213A) );
// FIXREG64( MCBIST_MCBIST_MBSEC0Q                                          , RULL(0x07010F55),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012115) );
// FIXREG64( MCBIST_MCBIST_0_MBSEC0Q                                        , RULL(0x07010F55),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012115) );
// FIXREG64( MCBIST_MCBIST_1_MBSEC0Q                                        , RULL(0x08010F55),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012115) );
// FIXREG64( MCBIST_MCBIST_MBSEC1Q                                          , RULL(0x07010F56),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012116) );
// FIXREG64( MCBIST_MCBIST_0_MBSEC1Q                                        , RULL(0x07010F56),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012116) );
// FIXREG64( MCBIST_MCBIST_1_MBSEC1Q                                        , RULL(0x08010F56),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012116) );
// FIXREG64( MCBIST_MCBIST_MBSEVR0Q                                         , RULL(0x07010F7E),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701213E) );
// FIXREG64( MCBIST_MCBIST_0_MBSEVR0Q                                       , RULL(0x07010F7E),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701213E) );
// FIXREG64( MCBIST_MCBIST_1_MBSEVR0Q                                       , RULL(0x08010F7E),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801213E) );
// FIXREG64( MCBIST_MCBIST_MBSEVR1Q                                         , RULL(0x07010F7F),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701213F) );
// FIXREG64( MCBIST_MCBIST_0_MBSEVR1Q                                       , RULL(0x07010F7F),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701213F) );
// FIXREG64( MCBIST_MCBIST_1_MBSEVR1Q                                       , RULL(0x08010F7F),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801213F) );
// FIXREG64( MCBIST_MCBIST_MBSMODESQ                                        , RULL(0x07010F62),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012122) );
// FIXREG64( MCBIST_MCBIST_0_MBSMODESQ                                      , RULL(0x07010F62),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012122) );
// FIXREG64( MCBIST_MCBIST_1_MBSMODESQ                                      , RULL(0x08010F62),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012122) );
// FIXREG64( MCBIST_MCBIST_MBSMSECQ                                         , RULL(0x07010F69),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012129) );
// FIXREG64( MCBIST_MCBIST_0_MBSMSECQ                                       , RULL(0x07010F69),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012129) );
// FIXREG64( MCBIST_MCBIST_1_MBSMSECQ                                       , RULL(0x08010F69),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012129) );
// FIXREG64( MCBIST_MCBIST_MBSSYMEC0Q                                       , RULL(0x07010F58),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012118) );
// FIXREG64( MCBIST_MCBIST_0_MBSSYMEC0Q                                     , RULL(0x07010F58),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012118) );
// FIXREG64( MCBIST_MCBIST_1_MBSSYMEC0Q                                     , RULL(0x08010F58),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012118) );
// FIXREG64( MCBIST_MCBIST_MBSSYMEC1Q                                       , RULL(0x07010F59),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012119) );
// FIXREG64( MCBIST_MCBIST_0_MBSSYMEC1Q                                     , RULL(0x07010F59),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012119) );
// FIXREG64( MCBIST_MCBIST_1_MBSSYMEC1Q                                     , RULL(0x08010F59),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012119) );
// FIXREG64( MCBIST_MCBIST_MBSSYMEC2Q                                       , RULL(0x07010F5A),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701211A) );
// FIXREG64( MCBIST_MCBIST_0_MBSSYMEC2Q                                     , RULL(0x07010F5A),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701211A) );
// FIXREG64( MCBIST_MCBIST_1_MBSSYMEC2Q                                     , RULL(0x08010F5A),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801211A) );
// FIXREG64( MCBIST_MCBIST_MBSSYMEC3Q                                       , RULL(0x07010F5B),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701211B) );
// FIXREG64( MCBIST_MCBIST_0_MBSSYMEC3Q                                     , RULL(0x07010F5B),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701211B) );
// FIXREG64( MCBIST_MCBIST_1_MBSSYMEC3Q                                     , RULL(0x08010F5B),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801211B) );
// FIXREG64( MCBIST_MCBIST_MBSSYMEC4Q                                       , RULL(0x07010F5C),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701211C) );
// FIXREG64( MCBIST_MCBIST_0_MBSSYMEC4Q                                     , RULL(0x07010F5C),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701211C) );
// FIXREG64( MCBIST_MCBIST_1_MBSSYMEC4Q                                     , RULL(0x08010F5C),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801211C) );
// FIXREG64( MCBIST_MCBIST_MBSSYMEC5Q                                       , RULL(0x07010F5D),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701211D) );
// FIXREG64( MCBIST_MCBIST_0_MBSSYMEC5Q                                     , RULL(0x07010F5D),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701211D) );
// FIXREG64( MCBIST_MCBIST_1_MBSSYMEC5Q                                     , RULL(0x08010F5D),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801211D) );
// FIXREG64( MCBIST_MCBIST_MBSSYMEC6Q                                       , RULL(0x07010F5E),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701211E) );
// FIXREG64( MCBIST_MCBIST_0_MBSSYMEC6Q                                     , RULL(0x07010F5E),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701211E) );
// FIXREG64( MCBIST_MCBIST_1_MBSSYMEC6Q                                     , RULL(0x08010F5E),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801211E) );
// FIXREG64( MCBIST_MCBIST_MBSSYMEC7Q                                       , RULL(0x07010F5F),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701211F) );
// FIXREG64( MCBIST_MCBIST_0_MBSSYMEC7Q                                     , RULL(0x07010F5F),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701211F) );
// FIXREG64( MCBIST_MCBIST_1_MBSSYMEC7Q                                     , RULL(0x08010F5F),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801211F) );
// FIXREG64( MCBIST_MCBIST_MBSSYMEC8Q                                       , RULL(0x07010F60),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012120) );
// FIXREG64( MCBIST_MCBIST_0_MBSSYMEC8Q                                     , RULL(0x07010F60),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012120) );
// FIXREG64( MCBIST_MCBIST_1_MBSSYMEC8Q                                     , RULL(0x08010F60),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012120) );
// FIXREG64( MCBIST_MCBIST_MBSTRQ                                           , RULL(0x07010F57),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012117) );
// FIXREG64( MCBIST_MCBIST_0_MBSTRQ                                         , RULL(0x07010F57),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012117) );
// FIXREG64( MCBIST_MCBIST_1_MBSTRQ                                         , RULL(0x08010F57),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012117) );
// FIXREG64( MCBIST_MCBIST_MBUER0Q                                          , RULL(0x07010F6D),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701212D) );
// FIXREG64( MCBIST_MCBIST_0_MBUER0Q                                        , RULL(0x07010F6D),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701212D) );
// FIXREG64( MCBIST_MCBIST_1_MBUER0Q                                        , RULL(0x08010F6D),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801212D) );
// FIXREG64( MCBIST_MCBIST_MBUER1Q                                          , RULL(0x07010F72),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012132) );
// FIXREG64( MCBIST_MCBIST_0_MBUER1Q                                        , RULL(0x07010F72),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012132) );
// FIXREG64( MCBIST_MCBIST_1_MBUER1Q                                        , RULL(0x08010F72),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012132) );
// FIXREG64( MCBIST_MCBIST_MBUER2Q                                          , RULL(0x07010F77),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012137) );
// FIXREG64( MCBIST_MCBIST_0_MBUER2Q                                        , RULL(0x07010F77),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012137) );
// FIXREG64( MCBIST_MCBIST_1_MBUER2Q                                        , RULL(0x08010F77),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012137) );
// FIXREG64( MCBIST_MCBIST_MBUER3Q                                          , RULL(0x07010F7C),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701213C) );
// FIXREG64( MCBIST_MCBIST_0_MBUER3Q                                        , RULL(0x07010F7C),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701213C) );
// FIXREG64( MCBIST_MCBIST_1_MBUER3Q                                        , RULL(0x08010F7C),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801213C) );
// FIXREG64( MCBIST_MCBIST_MCBACQ                                           , RULL(0x07010FD5),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012195) );
// FIXREG64( MCBIST_MCBIST_0_MCBACQ                                         , RULL(0x07010FD5),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012195) );
// FIXREG64( MCBIST_MCBIST_1_MCBACQ                                         , RULL(0x08010FD5),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012195) );
// FIXREG64( MCBIST_MCBIST_MCBAGRAQ                                         , RULL(0x07010FD6),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012196) );
// FIXREG64( MCBIST_MCBIST_0_MCBAGRAQ                                       , RULL(0x07010FD6),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012196) );
// FIXREG64( MCBIST_MCBIST_1_MCBAGRAQ                                       , RULL(0x08010FD6),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012196) );
// FIXREG64( MCBIST_MCBIST_MCBAMR0A0Q                                       , RULL(0x07010FC8),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012188) );
// FIXREG64( MCBIST_MCBIST_0_MCBAMR0A0Q                                     , RULL(0x07010FC8),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012188) );
// FIXREG64( MCBIST_MCBIST_1_MCBAMR0A0Q                                     , RULL(0x08010FC8),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012188) );
// FIXREG64( MCBIST_MCBIST_MCBAMR1A0Q                                       , RULL(0x07010FC9),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012189) );
// FIXREG64( MCBIST_MCBIST_0_MCBAMR1A0Q                                     , RULL(0x07010FC9),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012189) );
// FIXREG64( MCBIST_MCBIST_1_MCBAMR1A0Q                                     , RULL(0x08010FC9),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012189) );
// FIXREG64( MCBIST_MCBIST_MCBAMR2A0Q                                       , RULL(0x07010FCA),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701218A) );
// FIXREG64( MCBIST_MCBIST_0_MCBAMR2A0Q                                     , RULL(0x07010FCA),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701218A) );
// FIXREG64( MCBIST_MCBIST_1_MCBAMR2A0Q                                     , RULL(0x08010FCA),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801218A) );
// FIXREG64( MCBIST_MCBIST_MCBAMR3A0Q                                       , RULL(0x07010FCB),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701218B) );
// FIXREG64( MCBIST_MCBIST_0_MCBAMR3A0Q                                     , RULL(0x07010FCB),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701218B) );
// FIXREG64( MCBIST_MCBIST_1_MCBAMR3A0Q                                     , RULL(0x08010FCB),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801218B) );
// FIXREG64( MCBIST_MCBIST_MCBCFGQ                                          , RULL(0x07010FE0),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070121A0) );
// FIXREG64( MCBIST_MCBIST_0_MCBCFGQ                                        , RULL(0x07010FE0),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070121A0) );
// FIXREG64( MCBIST_MCBIST_1_MCBCFGQ                                        , RULL(0x08010FE0),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080121A0) );
// FIXREG64( MCBIST_MCBIST_MCBDRCRQ                                         , RULL(0x07010FBD),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701217D) );
// FIXREG64( MCBIST_MCBIST_0_MCBDRCRQ                                       , RULL(0x07010FBD),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701217D) );
// FIXREG64( MCBIST_MCBIST_1_MCBDRCRQ                                       , RULL(0x08010FBD),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801217D) );
// FIXREG64( MCBIST_MCBIST_MCBDRSRQ                                         , RULL(0x07010FBC),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701217C) );
// FIXREG64( MCBIST_MCBIST_0_MCBDRSRQ                                       , RULL(0x07010FBC),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701217C) );
// FIXREG64( MCBIST_MCBIST_1_MCBDRSRQ                                       , RULL(0x08010FBC),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801217C) );
// FIXREG64( MCBIST_MCBIST_MCBEA0Q                                          , RULL(0x07010FCE),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701218E) );
// FIXREG64( MCBIST_MCBIST_0_MCBEA0Q                                        , RULL(0x07010FCE),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701218E) );
// FIXREG64( MCBIST_MCBIST_1_MCBEA0Q                                        , RULL(0x08010FCE),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801218E) );
// FIXREG64( MCBIST_MCBIST_MCBEA1Q                                          , RULL(0x07010FCF),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701218F) );
// FIXREG64( MCBIST_MCBIST_0_MCBEA1Q                                        , RULL(0x07010FCF),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701218F) );
// FIXREG64( MCBIST_MCBIST_1_MCBEA1Q                                        , RULL(0x08010FCF),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801218F) );
// FIXREG64( MCBIST_MCBIST_MCBEA2Q                                          , RULL(0x07010FD2),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012192) );
// FIXREG64( MCBIST_MCBIST_0_MCBEA2Q                                        , RULL(0x07010FD2),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012192) );
// FIXREG64( MCBIST_MCBIST_1_MCBEA2Q                                        , RULL(0x08010FD2),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012192) );
// FIXREG64( MCBIST_MCBIST_MCBEA3Q                                          , RULL(0x07010FD3),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012193) );
// FIXREG64( MCBIST_MCBIST_0_MCBEA3Q                                        , RULL(0x07010FD3),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012193) );
// FIXREG64( MCBIST_MCBIST_1_MCBEA3Q                                        , RULL(0x08010FD3),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012193) );
// FIXREG64( MCBIST_MCBIST_MCBFD0Q                                          , RULL(0x07010FBE),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701217E) );
// FIXREG64( MCBIST_MCBIST_0_MCBFD0Q                                        , RULL(0x07010FBE),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701217E) );
// FIXREG64( MCBIST_MCBIST_1_MCBFD0Q                                        , RULL(0x08010FBE),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801217E) );
// FIXREG64( MCBIST_MCBIST_MCBFD1Q                                          , RULL(0x07010FBF),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701217F) );
// FIXREG64( MCBIST_MCBIST_0_MCBFD1Q                                        , RULL(0x07010FBF),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701217F) );
// FIXREG64( MCBIST_MCBIST_1_MCBFD1Q                                        , RULL(0x08010FBF),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801217F) );
// FIXREG64( MCBIST_MCBIST_MCBFD2Q                                          , RULL(0x07010FC0),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012180) );
// FIXREG64( MCBIST_MCBIST_0_MCBFD2Q                                        , RULL(0x07010FC0),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012180) );
// FIXREG64( MCBIST_MCBIST_1_MCBFD2Q                                        , RULL(0x08010FC0),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012180) );
// FIXREG64( MCBIST_MCBIST_MCBFD3Q                                          , RULL(0x07010FC1),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012181) );
// FIXREG64( MCBIST_MCBIST_0_MCBFD3Q                                        , RULL(0x07010FC1),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012181) );
// FIXREG64( MCBIST_MCBIST_1_MCBFD3Q                                        , RULL(0x08010FC1),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012181) );
// FIXREG64( MCBIST_MCBIST_MCBFD4Q                                          , RULL(0x07010FC2),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012182) );
// FIXREG64( MCBIST_MCBIST_0_MCBFD4Q                                        , RULL(0x07010FC2),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012182) );
// FIXREG64( MCBIST_MCBIST_1_MCBFD4Q                                        , RULL(0x08010FC2),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012182) );
// FIXREG64( MCBIST_MCBIST_MCBFD5Q                                          , RULL(0x07010FC3),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012183) );
// FIXREG64( MCBIST_MCBIST_0_MCBFD5Q                                        , RULL(0x07010FC3),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012183) );
// FIXREG64( MCBIST_MCBIST_1_MCBFD5Q                                        , RULL(0x08010FC3),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012183) );
// FIXREG64( MCBIST_MCBIST_MCBFD6Q                                          , RULL(0x07010FC4),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012184) );
// FIXREG64( MCBIST_MCBIST_0_MCBFD6Q                                        , RULL(0x07010FC4),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012184) );
// FIXREG64( MCBIST_MCBIST_1_MCBFD6Q                                        , RULL(0x08010FC4),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012184) );
// FIXREG64( MCBIST_MCBIST_MCBFD7Q                                          , RULL(0x07010FC5),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012185) );
// FIXREG64( MCBIST_MCBIST_0_MCBFD7Q                                        , RULL(0x07010FC5),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012185) );
// FIXREG64( MCBIST_MCBIST_1_MCBFD7Q                                        , RULL(0x08010FC5),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012185) );
// FIXREG64( MCBIST_MCBIST_MCBFDQ                                           , RULL(0x07010FC6),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012186) );
// FIXREG64( MCBIST_MCBIST_0_MCBFDQ                                         , RULL(0x07010FC6),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012186) );
// FIXREG64( MCBIST_MCBIST_1_MCBFDQ                                         , RULL(0x08010FC6),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012186) );
// FIXREG64( MCBIST_MCBIST_MCBISTFIRACT0                                    , RULL(0x07010F06),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120C6) );
// FIXREG64( MCBIST_MCBIST_0_MCBISTFIRACT0                                  , RULL(0x07010F06),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120C6) );
// FIXREG64( MCBIST_MCBIST_1_MCBISTFIRACT0                                  , RULL(0x08010F06),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120C6) );
// FIXREG64( MCBIST_MCBIST_MCBISTFIRACT1                                    , RULL(0x07010F07),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120C7) );
// FIXREG64( MCBIST_MCBIST_0_MCBISTFIRACT1                                  , RULL(0x07010F07),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120C7) );
// FIXREG64( MCBIST_MCBIST_1_MCBISTFIRACT1                                  , RULL(0x08010F07),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120C7) );
// FIXREG64( MCBIST_MCBIST_MCBISTFIRMASK                                    , RULL(0x07010F03),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120C3) );
// FIXREG64( MCBIST_MCBIST_MCBISTFIRMASK_AND                                , RULL(0x07010F04),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM1_AND , RULL(0x070120C4) );
// FIXREG64( MCBIST_MCBIST_MCBISTFIRMASK_OR                                 , RULL(0x07010F05),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM2_OR  , RULL(0x070120C5) );
// FIXREG64( MCBIST_MCBIST_0_MCBISTFIRMASK                                  , RULL(0x07010F03),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120C3) );
// FIXREG64( MCBIST_MCBIST_0_MCBISTFIRMASK_AND                              , RULL(0x07010F04),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM1_AND , RULL(0x070120C4) );
// FIXREG64( MCBIST_MCBIST_0_MCBISTFIRMASK_OR                               , RULL(0x07010F05),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM2_OR  , RULL(0x070120C5) );
// FIXREG64( MCBIST_MCBIST_1_MCBISTFIRMASK                                  , RULL(0x08010F03),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120C3) );
// FIXREG64( MCBIST_MCBIST_1_MCBISTFIRMASK_AND                              , RULL(0x08010F04),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM1_AND , RULL(0x080120C4) );
// FIXREG64( MCBIST_MCBIST_1_MCBISTFIRMASK_OR                               , RULL(0x08010F05),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM2_OR  , RULL(0x080120C5) );
// FIXREG64( MCBIST_MCBIST_MCBISTFIRQ                                       , RULL(0x07010F00),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x070120C0) );
// FIXREG64( MCBIST_MCBIST_MCBISTFIRQ_AND                                   , RULL(0x07010F01),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM1_AND , RULL(0x070120C1) );
// FIXREG64( MCBIST_MCBIST_MCBISTFIRQ_OR                                    , RULL(0x07010F02),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM2_OR  , RULL(0x070120C2) );
// FIXREG64( MCBIST_MCBIST_0_MCBISTFIRQ                                     , RULL(0x07010F00),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x070120C0) );
// FIXREG64( MCBIST_MCBIST_0_MCBISTFIRQ_AND                                 , RULL(0x07010F01),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM1_AND , RULL(0x070120C1) );
// FIXREG64( MCBIST_MCBIST_0_MCBISTFIRQ_OR                                  , RULL(0x07010F02),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM2_OR  , RULL(0x070120C2) );
// FIXREG64( MCBIST_MCBIST_1_MCBISTFIRQ                                     , RULL(0x08010F00),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x080120C0) );
// FIXREG64( MCBIST_MCBIST_1_MCBISTFIRQ_AND                                 , RULL(0x08010F01),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM1_AND , RULL(0x080120C1) );
// FIXREG64( MCBIST_MCBIST_1_MCBISTFIRQ_OR                                  , RULL(0x08010F02),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM2_OR  , RULL(0x080120C2) );
// FIXREG64( MCBIST_MCBIST_MCBISTFIRWOF                                     , RULL(0x07010F08),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RO   , RULL(0x070120C8) );
// FIXREG64( MCBIST_MCBIST_0_MCBISTFIRWOF                                   , RULL(0x07010F08),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RO   , RULL(0x070120C8) );
// FIXREG64( MCBIST_MCBIST_1_MCBISTFIRWOF                                   , RULL(0x08010F08),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RO   , RULL(0x080120C8) );
// FIXREG64( MCBIST_MCBIST_MCBLFSRA0Q                                       , RULL(0x07010FD4),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012194) );
// FIXREG64( MCBIST_MCBIST_0_MCBLFSRA0Q                                     , RULL(0x07010FD4),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012194) );
// FIXREG64( MCBIST_MCBIST_1_MCBLFSRA0Q                                     , RULL(0x08010FD4),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012194) );
// FIXREG64( MCBIST_MCBIST_MCBMCATQ                                         , RULL(0x07010FD7),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012197) );
// FIXREG64( MCBIST_MCBIST_0_MCBMCATQ                                       , RULL(0x07010FD7),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012197) );
// FIXREG64( MCBIST_MCBIST_1_MCBMCATQ                                       , RULL(0x08010FD7),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012197) );
// FIXREG64( MCBIST_MCBIST_MCBMR0Q                                          , RULL(0x07010FA8),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012168) );
// FIXREG64( MCBIST_MCBIST_0_MCBMR0Q                                        , RULL(0x07010FA8),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012168) );
// FIXREG64( MCBIST_MCBIST_1_MCBMR0Q                                        , RULL(0x08010FA8),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012168) );
// FIXREG64( MCBIST_MCBIST_MCBMR1Q                                          , RULL(0x07010FA9),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012169) );
// FIXREG64( MCBIST_MCBIST_0_MCBMR1Q                                        , RULL(0x07010FA9),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012169) );
// FIXREG64( MCBIST_MCBIST_1_MCBMR1Q                                        , RULL(0x08010FA9),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012169) );
// FIXREG64( MCBIST_MCBIST_MCBMR2Q                                          , RULL(0x07010FAA),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701216A) );
// FIXREG64( MCBIST_MCBIST_0_MCBMR2Q                                        , RULL(0x07010FAA),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701216A) );
// FIXREG64( MCBIST_MCBIST_1_MCBMR2Q                                        , RULL(0x08010FAA),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801216A) );
// FIXREG64( MCBIST_MCBIST_MCBMR3Q                                          , RULL(0x07010FAB),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701216B) );
// FIXREG64( MCBIST_MCBIST_0_MCBMR3Q                                        , RULL(0x07010FAB),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701216B) );
// FIXREG64( MCBIST_MCBIST_1_MCBMR3Q                                        , RULL(0x08010FAB),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801216B) );
// FIXREG64( MCBIST_MCBIST_MCBMR4Q                                          , RULL(0x07010FAC),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701216C) );
// FIXREG64( MCBIST_MCBIST_0_MCBMR4Q                                        , RULL(0x07010FAC),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701216C) );
// FIXREG64( MCBIST_MCBIST_1_MCBMR4Q                                        , RULL(0x08010FAC),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801216C) );
// FIXREG64( MCBIST_MCBIST_MCBMR5Q                                          , RULL(0x07010FAD),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701216D) );
// FIXREG64( MCBIST_MCBIST_0_MCBMR5Q                                        , RULL(0x07010FAD),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701216D) );
// FIXREG64( MCBIST_MCBIST_1_MCBMR5Q                                        , RULL(0x08010FAD),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801216D) );
// FIXREG64( MCBIST_MCBIST_MCBMR6Q                                          , RULL(0x07010FAE),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701216E) );
// FIXREG64( MCBIST_MCBIST_0_MCBMR6Q                                        , RULL(0x07010FAE),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701216E) );
// FIXREG64( MCBIST_MCBIST_1_MCBMR6Q                                        , RULL(0x08010FAE),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801216E) );
// FIXREG64( MCBIST_MCBIST_MCBMR7Q                                          , RULL(0x07010FDF),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701219F) );
// FIXREG64( MCBIST_MCBIST_0_MCBMR7Q                                        , RULL(0x07010FDF),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701219F) );
// FIXREG64( MCBIST_MCBIST_1_MCBMR7Q                                        , RULL(0x08010FDF),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801219F) );
// FIXREG64( MCBIST_MCBIST_MCBPARMQ                                         , RULL(0x07010FAF),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701216F) );
// FIXREG64( MCBIST_MCBIST_0_MCBPARMQ                                       , RULL(0x07010FAF),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701216F) );
// FIXREG64( MCBIST_MCBIST_1_MCBPARMQ                                       , RULL(0x08010FAF),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801216F) );
// FIXREG64( MCBIST_MCBIST_MCBRCRQ                                          , RULL(0x07010FB1),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012171) );
// FIXREG64( MCBIST_MCBIST_0_MCBRCRQ                                        , RULL(0x07010FB1),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012171) );
// FIXREG64( MCBIST_MCBIST_1_MCBRCRQ                                        , RULL(0x08010FB1),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012171) );
// FIXREG64( MCBIST_MCBIST_MCBRDS0Q                                         , RULL(0x07010FB2),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012172) );
// FIXREG64( MCBIST_MCBIST_0_MCBRDS0Q                                       , RULL(0x07010FB2),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012172) );
// FIXREG64( MCBIST_MCBIST_1_MCBRDS0Q                                       , RULL(0x08010FB2),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012172) );
// FIXREG64( MCBIST_MCBIST_MCBRDS1Q                                         , RULL(0x07010FB3),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012173) );
// FIXREG64( MCBIST_MCBIST_0_MCBRDS1Q                                       , RULL(0x07010FB3),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012173) );
// FIXREG64( MCBIST_MCBIST_1_MCBRDS1Q                                       , RULL(0x08010FB3),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012173) );
// FIXREG64( MCBIST_MCBIST_MCBSA0Q                                          , RULL(0x07010FCC),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701218C) );
// FIXREG64( MCBIST_MCBIST_0_MCBSA0Q                                        , RULL(0x07010FCC),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701218C) );
// FIXREG64( MCBIST_MCBIST_1_MCBSA0Q                                        , RULL(0x08010FCC),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801218C) );
// FIXREG64( MCBIST_MCBIST_MCBSA1Q                                          , RULL(0x07010FCD),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701218D) );
// FIXREG64( MCBIST_MCBIST_0_MCBSA1Q                                        , RULL(0x07010FCD),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701218D) );
// FIXREG64( MCBIST_MCBIST_1_MCBSA1Q                                        , RULL(0x08010FCD),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801218D) );
// FIXREG64( MCBIST_MCBIST_MCBSA2Q                                          , RULL(0x07010FD0),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012190) );
// FIXREG64( MCBIST_MCBIST_0_MCBSA2Q                                        , RULL(0x07010FD0),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012190) );
// FIXREG64( MCBIST_MCBIST_1_MCBSA2Q                                        , RULL(0x08010FD0),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012190) );
// FIXREG64( MCBIST_MCBIST_MCBSA3Q                                          , RULL(0x07010FD1),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012191) );
// FIXREG64( MCBIST_MCBIST_0_MCBSA3Q                                        , RULL(0x07010FD1),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012191) );
// FIXREG64( MCBIST_MCBIST_1_MCBSA3Q                                        , RULL(0x08010FD1),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012191) );
// FIXREG64( MCBIST_MCBIST_MCBSTATQ                                         , RULL(0x07010F66),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RO   , RULL(0x07012126) );
// FIXREG64( MCBIST_MCBIST_0_MCBSTATQ                                       , RULL(0x07010F66),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RO   , RULL(0x07012126) );
// FIXREG64( MCBIST_MCBIST_1_MCBSTATQ                                       , RULL(0x08010F66),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RO   , RULL(0x08012126) );
// FIXREG64( MCBIST_MCBIST_MCB_CNTLQ                                        , RULL(0x07010FDB),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701219B) );
// FIXREG64( MCBIST_MCBIST_0_MCB_CNTLQ                                      , RULL(0x07010FDB),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701219B) );
// FIXREG64( MCBIST_MCBIST_1_MCB_CNTLQ                                      , RULL(0x08010FDB),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801219B) );
// FIXREG64( MCBIST_MCBIST_MCB_CNTLSTATQ                                    , RULL(0x07010FDC),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701219C) );
// FIXREG64( MCBIST_MCBIST_0_MCB_CNTLSTATQ                                  , RULL(0x07010FDC),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701219C) );
// FIXREG64( MCBIST_MCBIST_1_MCB_CNTLSTATQ                                  , RULL(0x08010FDC),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801219C) );
// FIXREG64( MCBIST_MCBIST_RCD_LRDIM_CNTL_WORD0_15Q                         , RULL(0x07010FDD),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x0701219D) );
// FIXREG64( MCBIST_MCBIST_0_RCD_LRDIM_CNTL_WORD0_15Q                       , RULL(0x07010FDD),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x0701219D) );
// FIXREG64( MCBIST_MCBIST_1_RCD_LRDIM_CNTL_WORD0_15Q                       , RULL(0x08010FDD),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x0801219D) );
// FIXREG64( MCBIST_MCBIST_RUNTIMECTRQ                                      , RULL(0x07010FB0),  SH_UNT_MCBIST   ,
//           SH_ACS_SCOM_RW   , RULL(0x07012170) );
// FIXREG64( MCBIST_MCBIST_0_RUNTIMECTRQ                                    , RULL(0x07010FB0),  SH_UNT_MCBIST_0 ,
//           SH_ACS_SCOM_RW   , RULL(0x07012170) );
// FIXREG64( MCBIST_MCBIST_1_RUNTIMECTRQ                                    , RULL(0x08010FB0),  SH_UNT_MCBIST_1 ,
//           SH_ACS_SCOM_RW   , RULL(0x08012170) );
//
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_19, RULL(0x070120E8), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBISTFIRACT1, RULL(0x080120C7), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBISTFIRWOF, RULL(0x070120C8), SH_UNT_MCBIST_0, SH_ACS_SCOM_RO);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBSEC0Q, RULL(0x08012115), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_10, RULL(0x070120DF), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBNCER2Q, RULL(0x08012134), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBUER0Q, RULL(0x0701212D), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_CNTLQ, RULL(0x08012165), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBISTFIRQ, RULL(0x070120C0), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_18, RULL(0x07012107), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBDRCRQ, RULL(0x0701217D), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBAMR0A0Q, RULL(0x07012188), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_31, RULL(0x07012114), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBFD3Q, RULL(0x08012181), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBEA2Q, RULL(0x07012192), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_12, RULL(0x07012101), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBRCER1Q, RULL(0x08012130), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBSTRQ, RULL(0x07012117), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_27, RULL(0x07012110), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_FIXED_DATA0Q, RULL(0x070121A5), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_00, RULL(0x070120D5), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCB_CNTLQ, RULL(0x0801219B), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBFD4Q, RULL(0x07012182), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBEA2Q, RULL(0x07012192), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_07, RULL(0x070120DC), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBUER3Q, RULL(0x0801213C), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_09, RULL(0x080120FE), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_17, RULL(0x08012106), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBAMR0A0Q, RULL(0x08012188), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBRDS1Q, RULL(0x07012173), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBNCER1Q, RULL(0x0801212F), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBISTFIRMASK_OR, RULL(0x080120C5), SH_UNT_MCBIST_1, SH_ACS_SCOM2_OR);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_07, RULL(0x070120DC), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_14, RULL(0x08012103), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBPARMQ, RULL(0x0701216F), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBMR4Q, RULL(0x0701216C), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_14, RULL(0x07012103), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBRCRQ, RULL(0x08012171), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_29, RULL(0x070120F2), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBUER2Q, RULL(0x08012137), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBAUER1Q, RULL(0x07012133), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_00, RULL(0x070120F5), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_01, RULL(0x070120F6), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBEA1Q, RULL(0x0701218F), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBSSYMEC5Q, RULL(0x0801211D), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBFD3Q, RULL(0x07012181), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBSSYMEC0Q, RULL(0x07012118), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_16, RULL(0x07012105), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_FIXED_DATA1Q, RULL(0x070121A6), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_20, RULL(0x070120E9), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBEA3Q, RULL(0x07012193), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBSA1Q, RULL(0x0801218D), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_CNTLQ, RULL(0x07012165), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBSSYMEC1Q, RULL(0x07012119), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_24, RULL(0x070120ED), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBMPER1Q, RULL(0x07012131), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_26, RULL(0x080120EF), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_22, RULL(0x0801210B), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCSARRERRINJQ, RULL(0x0701219E), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBISTFIRMASK, RULL(0x070120C3), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_27, RULL(0x07012110), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBMR5Q, RULL(0x0701216D), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_20, RULL(0x07012109), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBSMSECQ, RULL(0x07012129), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBMR2Q, RULL(0x0701216A), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_10, RULL(0x080120FF), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBSSYMEC3Q, RULL(0x0701211B), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBMPER1Q, RULL(0x07012131), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_23, RULL(0x0701210C), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBNCER0Q, RULL(0x0801212A), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBSEC1Q, RULL(0x07012116), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBSEC1Q, RULL(0x07012116), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBSSYMEC2Q, RULL(0x0701211A), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_24, RULL(0x0701210D), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBFDQ, RULL(0x08012186), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBISTFIRACT1, RULL(0x070120C7), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBSSYMEC6Q, RULL(0x0701211E), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBISTFIRQ, RULL(0x080120C0), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_RUNTIMECTRQ, RULL(0x07012170), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBSSYMEC4Q, RULL(0x0801211C), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBFD1Q, RULL(0x0701217F), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBDRCRQ, RULL(0x0701217D), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBSSYMEC7Q, RULL(0x0801211F), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_21, RULL(0x070120EA), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBEA0Q, RULL(0x0801218E), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBEA1Q, RULL(0x0801218F), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBPARMQ, RULL(0x0801216F), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBSTATQ, RULL(0x07012126), SH_UNT_MCBIST_0, SH_ACS_SCOM_RO);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBAUER3Q, RULL(0x0701213D), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_05, RULL(0x070120FA), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_09, RULL(0x070120FE), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_20, RULL(0x08012109), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_09, RULL(0x080120DE), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_05, RULL(0x080120DA), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_10, RULL(0x080120DF), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBISTFIRMASK_AND, RULL(0x070120C4), SH_UNT_MCBIST, SH_ACS_SCOM1_AND);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBA_MCBERRPTQ, RULL(0x070121A7), SH_UNT_MCBIST_0, SH_ACS_SCOM_RO);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_28, RULL(0x07012111), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_02, RULL(0x070120D7), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBSMODESQ, RULL(0x08012122), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_23, RULL(0x080120EC), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_06, RULL(0x070120FB), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBNCER1Q, RULL(0x0701212F), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_26, RULL(0x0801210F), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_15, RULL(0x070120E4), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBFD7Q, RULL(0x08012185), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_30, RULL(0x08012113), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_03, RULL(0x070120F8), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_14, RULL(0x080120E3), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_13, RULL(0x08012102), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBUER1Q, RULL(0x07012132), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_02, RULL(0x080120F7), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBISTFIRWOF, RULL(0x080120C8), SH_UNT_MCBIST_1, SH_ACS_SCOM_RO);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBMR5Q, RULL(0x0701216D), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBRCER3Q, RULL(0x0701213A), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_24, RULL(0x070120ED), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBAMR1A0Q, RULL(0x07012189), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBAGRAQ, RULL(0x07012196), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_FIXED_DATA1Q, RULL(0x070121A6), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBNCER3Q, RULL(0x08012139), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_28, RULL(0x070120F1), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_11, RULL(0x07012100), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_14, RULL(0x070120E3), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBRDS1Q, RULL(0x08012173), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_16, RULL(0x070120E5), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_23, RULL(0x070120EC), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBEA3Q, RULL(0x07012193), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBSSYMEC4Q, RULL(0x0701211C), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBRCER2Q, RULL(0x07012135), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBUER2Q, RULL(0x07012137), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBSSYMEC5Q, RULL(0x0701211D), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBRCER0Q, RULL(0x0801212B), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_25, RULL(0x080120EE), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_03, RULL(0x080120F8), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBAUER0Q, RULL(0x0701212E), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_00, RULL(0x080120F5), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBSEC1Q, RULL(0x08012116), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBMR1Q, RULL(0x07012169), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_30, RULL(0x07012113), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_25, RULL(0x0801210E), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBRCER1Q, RULL(0x07012130), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_13, RULL(0x07012102), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBRCER1Q, RULL(0x07012130), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBFD0Q, RULL(0x0801217E), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBFD0Q, RULL(0x0701217E), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBFD1Q, RULL(0x0801217F), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_15, RULL(0x08012104), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBLFSRA0Q, RULL(0x07012194), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBECTLQ, RULL(0x080120D0), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBSMSECQ, RULL(0x07012129), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCB_CNTLQ, RULL(0x0701219B), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_15, RULL(0x07012104), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_19, RULL(0x080120E8), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBDRSRQ, RULL(0x0801217C), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBMR0Q, RULL(0x07012168), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBSEC0Q, RULL(0x07012115), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBSSYMEC2Q, RULL(0x0801211A), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_17, RULL(0x070120E6), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBMR7Q, RULL(0x0801219F), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBMR4Q, RULL(0x0701216C), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBSSYMEC6Q, RULL(0x0701211E), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBECTLQ, RULL(0x070120D0), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBSSYMEC7Q, RULL(0x0701211F), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBAMR3A0Q, RULL(0x0701218B), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBAUER0Q, RULL(0x0801212E), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_08, RULL(0x080120FD), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_23, RULL(0x0701210C), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBRCER2Q, RULL(0x07012135), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_26, RULL(0x0701210F), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCB_CNTLSTATQ, RULL(0x0801219C), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBUER0Q, RULL(0x0701212D), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBMR6Q, RULL(0x0701216E), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBSSYMEC0Q, RULL(0x07012118), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_10, RULL(0x070120DF), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_01, RULL(0x070120D6), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBMR1Q, RULL(0x07012169), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_00, RULL(0x070120F5), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBSA2Q, RULL(0x08012190), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_11, RULL(0x070120E0), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_06, RULL(0x070120DB), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_00, RULL(0x080120D5), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBSSYMEC2Q, RULL(0x0701211A), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_11, RULL(0x08012100), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBDRSRQ, RULL(0x0701217C), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBAGRAQ, RULL(0x08012196), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBNCER2Q, RULL(0x07012134), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBISTFIRQ_AND, RULL(0x080120C1), SH_UNT_MCBIST_1, SH_ACS_SCOM1_AND);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBEA3Q, RULL(0x08012193), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_04, RULL(0x070120D9), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBRCER0Q, RULL(0x0701212B), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_02, RULL(0x070120F7), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_29, RULL(0x08012112), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_FIXED_DATA1Q, RULL(0x080121A6), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_27, RULL(0x070120F0), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBSA0Q, RULL(0x0801218C), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBSSYMEC3Q, RULL(0x0801211B), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_19, RULL(0x07012108), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBMR7Q, RULL(0x0701219F), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBRCRQ, RULL(0x07012171), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBACQ, RULL(0x08012195), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_18, RULL(0x08012107), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_30, RULL(0x070120F3), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBISTFIRQ_AND, RULL(0x070120C1), SH_UNT_MCBIST_0, SH_ACS_SCOM1_AND);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBA_MCBERRPTQ, RULL(0x080121A7), SH_UNT_MCBIST_1, SH_ACS_SCOM_RO);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBMR3Q, RULL(0x0801216B), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_29, RULL(0x080120F2), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_16, RULL(0x070120E5), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_30, RULL(0x080120F3), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBRCER2Q, RULL(0x08012135), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_12, RULL(0x070120E1), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBMR1Q, RULL(0x08012169), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_05, RULL(0x070120FA), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_MODEQ, RULL(0x07012167), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_11, RULL(0x080120E0), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_15, RULL(0x080120E4), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBMPER2Q, RULL(0x07012136), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_11, RULL(0x070120E0), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_26, RULL(0x0701210F), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBISTFIRQ, RULL(0x070120C0), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBNCER3Q, RULL(0x07012139), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBNCER3Q, RULL(0x07012139), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_23, RULL(0x070120EC), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBFD2Q, RULL(0x07012180), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_20, RULL(0x070120E9), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBA_MCBERRPTQ, RULL(0x070121A7), SH_UNT_MCBIST, SH_ACS_SCOM_RO);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_10, RULL(0x070120FF), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_04, RULL(0x070120F9), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBRDS0Q, RULL(0x08012172), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_08, RULL(0x080120DD), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBSMODESQ, RULL(0x07012122), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBSMSECQ, RULL(0x08012129), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_04, RULL(0x080120D9), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_17, RULL(0x07012106), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBECTLQ, RULL(0x070120D0), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBAUER3Q, RULL(0x0801213D), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBNCER2Q, RULL(0x07012134), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_22, RULL(0x0701210B), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_08, RULL(0x070120FD), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBISTFIRMASK_OR, RULL(0x070120C5), SH_UNT_MCBIST, SH_ACS_SCOM2_OR);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBMR6Q, RULL(0x0701216E), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBSA2Q, RULL(0x07012190), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_31, RULL(0x08012114), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBSSYMEC5Q, RULL(0x0701211D), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_05, RULL(0x070120DA), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBMPER1Q, RULL(0x08012131), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_22, RULL(0x080120EB), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_09, RULL(0x070120DE), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_00, RULL(0x070120D5), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_RCD_LRDIM_CNTL_WORD0_15Q, RULL(0x0801219D), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_12, RULL(0x07012101), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBSEVR1Q, RULL(0x0701213F), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBFD7Q, RULL(0x07012185), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBRDS0Q, RULL(0x07012172), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCSARRERRINJQ, RULL(0x0701219E), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBRDS0Q, RULL(0x07012172), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_20, RULL(0x080120E9), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBMR4Q, RULL(0x0801216C), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_14, RULL(0x07012103), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBSTATQ, RULL(0x07012126), SH_UNT_MCBIST, SH_ACS_SCOM_RO);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBSSYMEC4Q, RULL(0x0701211C), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBISTFIRACT1, RULL(0x070120C7), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBAMR2A0Q, RULL(0x0701218A), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_03, RULL(0x080120D8), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_27, RULL(0x070120F0), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_11, RULL(0x07012100), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBFD3Q, RULL(0x07012181), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_07, RULL(0x080120DC), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_24, RULL(0x080120ED), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBISTFIRQ_OR, RULL(0x080120C2), SH_UNT_MCBIST_1, SH_ACS_SCOM2_OR);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_22, RULL(0x070120EB), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBMPER0Q, RULL(0x0801212C), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_01, RULL(0x080120F6), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBAMR3A0Q, RULL(0x0701218B), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_22, RULL(0x070120EB), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBSEVR1Q, RULL(0x0801213F), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBSEVR0Q, RULL(0x0701213E), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBEA1Q, RULL(0x0701218F), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBRCER0Q, RULL(0x0701212B), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBMCATQ, RULL(0x07012197), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBISTFIRMASK_AND, RULL(0x070120C4), SH_UNT_MCBIST_0, SH_ACS_SCOM1_AND);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBUER0Q, RULL(0x0801212D), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBSSYMEC8Q, RULL(0x08012120), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBSSYMEC6Q, RULL(0x0801211E), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBMPER2Q, RULL(0x07012136), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_24, RULL(0x0801210D), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBSSYMEC0Q, RULL(0x08012118), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_CNTLQ, RULL(0x07012165), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_25, RULL(0x0701210E), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBFD0Q, RULL(0x0701217E), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBMPER0Q, RULL(0x0701212C), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_RUNTIMECTRQ, RULL(0x07012170), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_STATQ, RULL(0x07012166), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBCFGQ, RULL(0x070121A0), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBSSYMEC1Q, RULL(0x08012119), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_MODEQ, RULL(0x07012167), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_06, RULL(0x070120DB), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBSMODESQ, RULL(0x07012122), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_09, RULL(0x070120FE), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBISTFIRMASK_AND, RULL(0x080120C4), SH_UNT_MCBIST_1, SH_ACS_SCOM1_AND);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_28, RULL(0x080120F1), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBISTFIRACT0, RULL(0x070120C6), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBMCATQ, RULL(0x08012197), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBRCER3Q, RULL(0x0801213A), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_RUNTIMECTRQ, RULL(0x08012170), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBMR5Q, RULL(0x0801216D), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBFD6Q, RULL(0x07012184), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBFD5Q, RULL(0x07012183), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBSA0Q, RULL(0x0701218C), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBAMR2A0Q, RULL(0x0701218A), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBUER2Q, RULL(0x07012137), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBAMR2A0Q, RULL(0x0801218A), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_29, RULL(0x07012112), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_22, RULL(0x0701210B), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_07, RULL(0x070120FC), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBAUER2Q, RULL(0x07012138), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_18, RULL(0x07012107), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBSA1Q, RULL(0x0701218D), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_03, RULL(0x070120F8), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBSA2Q, RULL(0x07012190), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_26, RULL(0x070120EF), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_31, RULL(0x080120F4), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_04, RULL(0x070120D9), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBFD2Q, RULL(0x08012180), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_19, RULL(0x08012108), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBMPER0Q, RULL(0x0701212C), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_17, RULL(0x070120E6), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_16, RULL(0x080120E5), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_12, RULL(0x080120E1), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBMPER3Q, RULL(0x0701213B), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_18, RULL(0x070120E7), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_03, RULL(0x070120D8), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_28, RULL(0x08012111), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_31, RULL(0x070120F4), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBSSYMEC8Q, RULL(0x07012120), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBAMR1A0Q, RULL(0x08012189), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBCFGQ, RULL(0x080121A0), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBSSYMEC1Q, RULL(0x07012119), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_04, RULL(0x080120F9), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_26, RULL(0x070120EF), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_01, RULL(0x070120F6), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_09, RULL(0x070120DE), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_MODEQ, RULL(0x08012167), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_13, RULL(0x07012102), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_16, RULL(0x07012105), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBISTFIRQ_OR, RULL(0x070120C2), SH_UNT_MCBIST_0, SH_ACS_SCOM2_OR);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_02, RULL(0x070120D7), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBFD6Q, RULL(0x08012184), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_21, RULL(0x0701210A), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBAGRAQ, RULL(0x07012196), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBAMR1A0Q, RULL(0x07012189), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBRCRQ, RULL(0x07012171), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBMR7Q, RULL(0x0701219F), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBMPER3Q, RULL(0x0801213B), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_25, RULL(0x0701210E), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBFDQ, RULL(0x07012186), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_04, RULL(0x070120F9), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBMR0Q, RULL(0x08012168), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_07, RULL(0x080120FC), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_31, RULL(0x070120F4), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBAUER0Q, RULL(0x0701212E), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBUER1Q, RULL(0x08012132), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBSTRQ, RULL(0x07012117), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBMPER2Q, RULL(0x08012136), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCB_CNTLQ, RULL(0x0701219B), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_30, RULL(0x07012113), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_FIXED_DATA0Q, RULL(0x070121A5), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBAUER3Q, RULL(0x0701213D), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBSSYMEC8Q, RULL(0x07012120), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBISTFIRMASK_OR, RULL(0x070120C5), SH_UNT_MCBIST_0, SH_ACS_SCOM2_OR);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBAUER2Q, RULL(0x08012138), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBACQ, RULL(0x07012195), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBRCER3Q, RULL(0x0701213A), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBLFSRA0Q, RULL(0x08012194), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBAUER1Q, RULL(0x08012133), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBAMR0A0Q, RULL(0x07012188), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCB_CNTLSTATQ, RULL(0x0701219C), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBNCER0Q, RULL(0x0701212A), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_03, RULL(0x070120D8), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_19, RULL(0x070120E8), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBRDS1Q, RULL(0x07012173), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBEA0Q, RULL(0x0701218E), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBSA3Q, RULL(0x08012191), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBFD6Q, RULL(0x07012184), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBSTATQ, RULL(0x08012126), SH_UNT_MCBIST_1, SH_ACS_SCOM_RO);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_21, RULL(0x070120EA), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBSTRQ, RULL(0x08012117), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBSA3Q, RULL(0x07012191), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBISTFIRWOF, RULL(0x070120C8), SH_UNT_MCBIST, SH_ACS_SCOM_RO);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_10, RULL(0x070120FF), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_28, RULL(0x07012111), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_FIXED_DATA0Q, RULL(0x080121A5), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBLFSRA0Q, RULL(0x07012194), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_08, RULL(0x070120DD), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBUER3Q, RULL(0x0701213C), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_06, RULL(0x080120FB), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBSEC0Q, RULL(0x07012115), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBFD1Q, RULL(0x0701217F), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBFD7Q, RULL(0x07012185), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_12, RULL(0x070120E1), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBFD5Q, RULL(0x08012183), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBNCER1Q, RULL(0x0701212F), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_08, RULL(0x070120DD), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_13, RULL(0x070120E2), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_18, RULL(0x070120E7), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_19, RULL(0x07012108), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_02, RULL(0x080120D7), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBFD4Q, RULL(0x07012182), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_07, RULL(0x070120FC), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_RCD_LRDIM_CNTL_WORD0_15Q, RULL(0x0701219D), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_21, RULL(0x080120EA), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_06, RULL(0x080120DB), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBMR6Q, RULL(0x0801216E), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_28, RULL(0x070120F1), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_20, RULL(0x07012109), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBUER1Q, RULL(0x07012132), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_27, RULL(0x080120F0), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBISTFIRACT0, RULL(0x070120C6), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBFD4Q, RULL(0x08012182), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_23, RULL(0x0801210C), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_25, RULL(0x070120EE), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBAUER1Q, RULL(0x07012133), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBACQ, RULL(0x07012195), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_21, RULL(0x0701210A), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_30, RULL(0x070120F3), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBPARMQ, RULL(0x0701216F), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_16, RULL(0x08012105), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBISTFIRMASK, RULL(0x070120C3), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_15, RULL(0x07012104), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_05, RULL(0x070120DA), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBMCATQ, RULL(0x07012197), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBISTFIRACT0, RULL(0x080120C6), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_RCD_LRDIM_CNTL_WORD0_15Q, RULL(0x0701219D), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBSEVR1Q, RULL(0x0701213F), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_08, RULL(0x070120FD), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBDRCRQ, RULL(0x0801217D), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_17, RULL(0x07012106), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBFDQ, RULL(0x07012186), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_13, RULL(0x080120E2), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBMR2Q, RULL(0x0801216A), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCSARRERRINJQ, RULL(0x0801219E), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_13, RULL(0x070120E2), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_24, RULL(0x0701210D), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_17, RULL(0x080120E6), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBFD5Q, RULL(0x07012183), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBISTFIRQ_AND, RULL(0x070120C1), SH_UNT_MCBIST, SH_ACS_SCOM1_AND);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBSSYMEC7Q, RULL(0x0701211F), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBISTFIRMASK, RULL(0x080120C3), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBFD2Q, RULL(0x07012180), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBMR3Q, RULL(0x0701216B), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBSA0Q, RULL(0x0701218C), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBAUER2Q, RULL(0x07012138), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBNCER0Q, RULL(0x0701212A), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_STATQ, RULL(0x07012166), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBEA2Q, RULL(0x08012192), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_15, RULL(0x070120E4), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBDRSRQ, RULL(0x0701217C), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MCBAMR3A0Q, RULL(0x0801218B), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_25, RULL(0x070120EE), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBMPER3Q, RULL(0x0701213B), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_01, RULL(0x080120D6), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCB_CNTLSTATQ, RULL(0x0701219C), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBSA3Q, RULL(0x07012191), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_06, RULL(0x070120FB), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_02, RULL(0x070120F7), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBMR2Q, RULL(0x0701216A), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBMR0Q, RULL(0x07012168), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBSEVR0Q, RULL(0x0701213E), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_27, RULL(0x08012110), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBSA1Q, RULL(0x0701218D), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR1_31, RULL(0x07012114), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MBUER3Q, RULL(0x0701213C), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR0_18, RULL(0x080120E7), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_05, RULL(0x080120FA), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_29, RULL(0x070120F2), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBISTFIRQ_OR, RULL(0x070120C2), SH_UNT_MCBIST, SH_ACS_SCOM2_OR);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_STATQ, RULL(0x08012166), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_CCS_INST_ARR0_01, RULL(0x070120D6), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MBSSYMEC3Q, RULL(0x0701211B), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_MCBCFGQ, RULL(0x070121A0), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBMR3Q, RULL(0x0701216B), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_21, RULL(0x0801210A), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_CCS_INST_ARR1_12, RULL(0x08012101), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_MCBEA0Q, RULL(0x0701218E), SH_UNT_MCBIST, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR0_14, RULL(0x070120E3), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_0_CCS_INST_ARR1_29, RULL(0x07012112), SH_UNT_MCBIST_0, SH_ACS_SCOM_RW);
// //WARNING: This register is not defined anymore in the figtree.
// REG64( MCBIST_MCBIST_1_MBSEVR0Q, RULL(0x0801213E), SH_UNT_MCBIST_1, SH_ACS_SCOM_RW);
#endif
