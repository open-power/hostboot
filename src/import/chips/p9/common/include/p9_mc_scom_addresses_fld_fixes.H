/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/include/p9_mc_scom_addresses_fld_fixes.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file mc_scom_addresses_fld_fixes.H
/// @brief The *scom_addresses_fld.H files are generated form figtree,
///        but the figree can be wrong.  This file is included in
///        *_scom_addresses_fld.H and allows incorrect constants to be
///        fixed manually.
///
// *HWP HWP Owner: Ben Gass <bgass@us.ibm.com>
// *HWP FW Owner: ? <?>
// *HWP Team: SAO
// *HWP Level: 1
// *HWP Consumed by: FSP:HB:HS:OCC:SBE:CME:SGPE:PGPE:FPPE:IPPE

#ifndef __P9_MC_SCOM_ADDRESSES_FLD_FIXES_H
#define __P9_MC_SCOM_ADDRESSES_FLD_FIXES_H

//Example
//Copy the whole line from the *scom_addresses_fld.H file.  Then add FIX in front of REG
//and add another paramter that is the new value you want.
//
//FIXREG64_FLD( PU_ALTD_CMD_REG_FBC_WITH_TM_QUIESCE, 24, SH_UNT, SH_ACS_SCOM, SH_FLD_FBC_WITH_TM_QUIESCE,
//              12);


static const uint64_t SH_FLD_COMMAND_LIST_TIMEOUT_SPEC = 99990000;
static const uint64_t SH_FLD_CFG_PAUSE_ON_MCE = 99990001;
static const uint64_t SH_FLD_01_BIT0      = 99990002;
static const uint64_t SH_FLD_01_BIT0_LEN  = 99990003;
static const uint64_t SH_FLD_23_BIT0      = 99990004;
static const uint64_t SH_FLD_23_BIT0_LEN  = 99990005;
static const uint64_t SH_FLD_4_BIT0       = 99990006;
static const uint64_t SH_FLD_4_BIT0_LEN   = 99990007;
static const uint64_t SH_FLD_01_BIT1      = 99990008;
static const uint64_t SH_FLD_01_BIT1_LEN  = 99990009;
static const uint64_t SH_FLD_23_BIT1      = 99990010;
static const uint64_t SH_FLD_23_BIT1_LEN  = 99990011;
static const uint64_t SH_FLD_4_BIT1       = 99990012;
static const uint64_t SH_FLD_4_BIT1_LEN   = 99990013;
static const uint64_t SH_FLD_01_BIT2      = 99990014;
static const uint64_t SH_FLD_01_BIT2_LEN  = 99990015;
static const uint64_t SH_FLD_23_BIT2      = 99990016;
static const uint64_t SH_FLD_23_BIT2_LEN  = 99990017;
static const uint64_t SH_FLD_4_BIT2       = 99990018;
static const uint64_t SH_FLD_4_BIT2_LEN   = 99990019;
static const uint64_t SH_FLD_01_BIT3      = 99990020;
static const uint64_t SH_FLD_01_BIT3_LEN  = 99990021;
static const uint64_t SH_FLD_23_BIT3      = 99990022;
static const uint64_t SH_FLD_23_BIT3_LEN  = 99990023;
static const uint64_t SH_FLD_4_BIT3       = 99990024;
static const uint64_t SH_FLD_4_BIT3_LEN   = 99990025;
static const uint64_t SH_FLD_01_BIT4      = 99990026;
static const uint64_t SH_FLD_01_BIT4_LEN  = 99990027;
static const uint64_t SH_FLD_23_BIT4      = 99990028;
static const uint64_t SH_FLD_23_BIT4_LEN  = 99990029;
static const uint64_t SH_FLD_4_BIT4       = 99990030;
static const uint64_t SH_FLD_4_BIT4_LEN   = 99990031;
static const uint64_t SH_FLD_01_BIT5      = 99990032;
static const uint64_t SH_FLD_01_BIT5_LEN  = 99990033;
static const uint64_t SH_FLD_23_BIT5      = 99990034;
static const uint64_t SH_FLD_23_BIT5_LEN  = 99990035;
static const uint64_t SH_FLD_4_BIT5       = 99990036;
static const uint64_t SH_FLD_4_BIT5_LEN   = 99990037;
static const uint64_t SH_FLD_01_BIT6      = 99990038;
static const uint64_t SH_FLD_01_BIT6_LEN  = 99990039;
static const uint64_t SH_FLD_23_BIT6      = 99990040;
static const uint64_t SH_FLD_23_BIT6_LEN  = 99990041;
static const uint64_t SH_FLD_4_BIT6       = 99990042;
static const uint64_t SH_FLD_4_BIT6_LEN   = 99990043;
static const uint64_t SH_FLD_01_BIT7      = 99990044;
static const uint64_t SH_FLD_01_BIT7_LEN  = 99990045;
static const uint64_t SH_FLD_23_BIT7      = 99990046;
static const uint64_t SH_FLD_23_BIT7_LEN  = 99990047;
static const uint64_t SH_FLD_4_BIT7       = 99990048;
static const uint64_t SH_FLD_4_BIT7_LEN   = 99990049;
static const uint64_t SH_FLD_01_BIT8      = 99990050;
static const uint64_t SH_FLD_01_BIT8_LEN  = 99990051;
static const uint64_t SH_FLD_23_BIT8      = 99990052;
static const uint64_t SH_FLD_23_BIT8_LEN  = 99990053;
static const uint64_t SH_FLD_4_BIT8       = 99990054;
static const uint64_t SH_FLD_4_BIT8_LEN   = 99990055;
static const uint64_t SH_FLD_01_BIT9      = 99990056;
static const uint64_t SH_FLD_01_BIT9_LEN  = 99990057;
static const uint64_t SH_FLD_23_BIT9      = 99990058;
static const uint64_t SH_FLD_23_BIT9_LEN  = 99990059;
static const uint64_t SH_FLD_4_BIT9       = 99990060;
static const uint64_t SH_FLD_4_BIT9_LEN   = 99990061;
static const uint64_t SH_FLD_01_BIT10     = 99990062;
static const uint64_t SH_FLD_01_BIT10_LEN = 99990063;
static const uint64_t SH_FLD_23_BIT10     = 99990064;
static const uint64_t SH_FLD_23_BIT10_LEN = 99990065;
static const uint64_t SH_FLD_4_BIT10      = 99990066;
static const uint64_t SH_FLD_4_BIT10_LEN  = 99990067;
static const uint64_t SH_FLD_01_BIT11     = 99990068;
static const uint64_t SH_FLD_01_BIT11_LEN = 99990069;
static const uint64_t SH_FLD_23_BIT11     = 99990070;
static const uint64_t SH_FLD_23_BIT11_LEN = 99990071;
static const uint64_t SH_FLD_4_BIT11      = 99990072;
static const uint64_t SH_FLD_4_BIT11_LEN  = 99990073;
static const uint64_t SH_FLD_01_BIT12     = 99990074;
static const uint64_t SH_FLD_01_BIT12_LEN = 99990075;
static const uint64_t SH_FLD_23_BIT12     = 99990076;
static const uint64_t SH_FLD_23_BIT12_LEN = 99990077;
static const uint64_t SH_FLD_4_BIT12      = 99990078;
static const uint64_t SH_FLD_4_BIT12_LEN  = 99990079;
static const uint64_t SH_FLD_01_BIT13     = 99990080;
static const uint64_t SH_FLD_01_BIT13_LEN = 99990081;
static const uint64_t SH_FLD_23_BIT13     = 99990082;
static const uint64_t SH_FLD_23_BIT13_LEN = 99990083;
static const uint64_t SH_FLD_4_BIT13      = 99990084;
static const uint64_t SH_FLD_4_BIT13_LEN  = 99990085;
static const uint64_t SH_FLD_01_BIT14     = 99990086;
static const uint64_t SH_FLD_01_BIT14_LEN = 99990087;
static const uint64_t SH_FLD_23_BIT14     = 99990088;
static const uint64_t SH_FLD_23_BIT14_LEN = 99990089;
static const uint64_t SH_FLD_4_BIT14      = 99990090;
static const uint64_t SH_FLD_4_BIT14_LEN  = 99990091;
static const uint64_t SH_FLD_01_BIT15     = 99990092;
static const uint64_t SH_FLD_01_BIT15_LEN = 99990093;
static const uint64_t SH_FLD_23_BIT15     = 99990094;
static const uint64_t SH_FLD_23_BIT15_LEN = 99990095;
static const uint64_t SH_FLD_4_BIT15      = 99990096;
static const uint64_t SH_FLD_4_BIT15_LEN  = 99990097;
static const uint64_t SH_FLD_01_DD2_PERBIT_RDVREF_DISABLE = 99990098;
static const uint64_t SH_FLD_23_DD2_PERBIT_RDVREF_DISABLE = 99990099;
static const uint64_t SH_FLD_4_DD2_PERBIT_RDVREF_DISABLE  = 99990100;
static const uint64_t SH_FLD_01_DD2_BLUE_EXTEND_RANGE     = 99990101;
static const uint64_t SH_FLD_01_DD2_BLUE_EXTEND_RANGE_LEN = 99990102;
static const uint64_t SH_FLD_DD2_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_ADJUST_LEN = 99990103;
static const uint64_t SH_FLD_DD2_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_CAL_ENABLE = 99990104;
static const uint64_t SH_FLD_DD2_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_POWERDOWN = 99990105;
static const uint64_t SH_FLD_DD2_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_CAL_DONE = 99990106;
static const uint64_t SH_FLD_DD2_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_CAL_ERROR = 99990107;

REG64_FLD( MCA_DDRPHY_DP16_SYSCLK_PR0_P0_0_01_ENABLE               , 48  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           0 );

REG64_FLD( MCA_DDRPHY_WC_RTT_WL_SWAP_ENABLE_P0                     , 48  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           0 );
REG64_FLD( MCA_DDRPHY_WC_RTT_WR_CTL_SWAP_ENABLE_P0                 , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           0 );

REG64_FLD( MCBIST_MCBCFGQ_CFG_MCBIST_CFG_FORCE_PAUSE_AFTER_RANK    , 34  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           0 );

REG64_FLD( MCBIST_MBSTRQ_CFG_PAUSE_ON_MCE                          , 33  , SH_UNT_MCBIST   , SH_ACS_SCOM_RW  ,
           SH_FLD_CFG_PAUSE_ON_MCE );

REG64_FLD( MCS_MCMODE0_GROUP_INTERLEAVE_GRANULARITY                , 52  , SH_UNT_MCS      , SH_ACS_SCOM_RW  ,
           0 );
REG64_FLD( MCS_MCMODE0_GROUP_INTERLEAVE_GRANULARITY_LEN            , 4   , SH_UNT_MCS      , SH_ACS_SCOM_RW  ,
           0 );
REG64_FLD( MCS_MCMODE0_DISABLE_MC_SYNC                             , 27  , SH_UNT_MCS      , SH_ACS_SCOM_RW  ,
           0 );
REG64_FLD( MCS_MCMODE0_DISABLE_MC_PAIR_SYNC                        , 28  , SH_UNT_MCS      , SH_ACS_SCOM_RW  ,
           0 );

// DDRPHY fields renamed in DD2.0
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_0_01_NIB0_EN_FORCE , 48  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_NIB0_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_0_01_BIT0          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT0    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_0_01_BIT0_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT0_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_0_01_NIB1_EN_FORCE , 56  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_NIB1_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_0_01_BIT1          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT1    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_0_01_BIT1_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT1_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_1_01_NIB0_EN_FORCE , 48  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_NIB0_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_1_01_BIT0          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT0    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_1_01_BIT0_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT0_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_1_01_NIB1_EN_FORCE , 56  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_NIB1_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_1_01_BIT1          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT1    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_1_01_BIT1_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT1_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_2_23_NIB0_EN_FORCE , 48  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_NIB0_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_2_23_BIT0          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT0    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_2_23_BIT0_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT0_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_2_23_NIB1_EN_FORCE , 56  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_NIB1_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_2_23_BIT1          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT1    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_2_23_BIT1_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT1_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_3_23_NIB0_EN_FORCE , 48  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_NIB0_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_3_23_BIT0          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT0    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_3_23_BIT0_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT0_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_3_23_NIB1_EN_FORCE , 56  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_NIB1_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_3_23_BIT1          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT1    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_3_23_BIT1_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT1_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_4_4_NIB0_EN_FORCE  , 48  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_NIB0_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_4_4_BIT0           , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT0     );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_4_4_BIT0_LEN       , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT0_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_4_4_NIB1_EN_FORCE  , 56  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_NIB1_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_4_4_BIT1           , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT1     );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_0_P0_4_4_BIT1_LEN       , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT1_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_0_01_NIB2_EN_FORCE , 48  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_NIB2_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_0_01_BIT2          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT2    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_0_01_BIT2_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT2_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_0_01_NIB3_EN_FORCE , 56  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_NIB3_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_0_01_BIT3          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT3    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_0_01_BIT3_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT3_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_1_01_NIB2_EN_FORCE , 48  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_NIB2_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_1_01_BIT2          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT2    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_1_01_BIT2_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT2_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_1_01_NIB3_EN_FORCE , 56  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_NIB3_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_1_01_BIT3          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT3    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_1_01_BIT3_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT3_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_2_23_NIB2_EN_FORCE , 48  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_NIB2_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_2_23_BIT2          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT2    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_2_23_BIT2_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT2_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_2_23_NIB3_EN_FORCE , 56  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_NIB3_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_2_23_BIT3          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT3    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_2_23_BIT3_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT3_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_3_23_NIB2_EN_FORCE , 48  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_NIB2_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_3_23_BIT2          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT2    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_3_23_BIT2_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT2_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_3_23_NIB3_EN_FORCE , 56  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_NIB3_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_3_23_BIT3          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT3    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_3_23_BIT3_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT3_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_4_4_NIB2_EN_FORCE  , 48  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_NIB2_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_4_4_BIT2           , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT2     );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_4_4_BIT2_LEN       , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT2_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_4_4_NIB3_EN_FORCE  , 56  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_NIB3_EN_FORCE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_4_4_BIT3           , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT3     );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_1_P0_4_4_BIT3_LEN       , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT3_LEN );

// DDRPHY fields added in DD2.0
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_0_01_BIT4          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT4    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_0_01_BIT4_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT4_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_0_01_BIT5          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT5    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_0_01_BIT5_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT5_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_1_01_BIT4          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT4    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_1_01_BIT4_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT4_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_1_01_BIT5          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT5    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_1_01_BIT5_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT5_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_2_23_BIT4          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT4    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_2_23_BIT4_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT4_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_2_23_BIT5          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT5    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_2_23_BIT5_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT5_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_3_23_BIT4          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT4    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_3_23_BIT4_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT4_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_3_23_BIT5          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT5    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_3_23_BIT5_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT5_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_4_4_BIT4           , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT4     );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_4_4_BIT4_LEN       , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT4_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_4_4_BIT5           , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT5     );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_2_P0_4_4_BIT5_LEN       , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT5_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_0_01_BIT6          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT6    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_0_01_BIT6_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT6_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_0_01_BIT7          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT7    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_0_01_BIT7_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT7_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_1_01_BIT6          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT6    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_1_01_BIT6_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT6_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_1_01_BIT7          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT7    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_1_01_BIT7_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT7_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_2_23_BIT6          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT6    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_2_23_BIT6_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT6_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_2_23_BIT7          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT7    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_2_23_BIT7_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT7_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_3_23_BIT6          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT6    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_3_23_BIT6_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT6_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_3_23_BIT7          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT7    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_3_23_BIT7_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT7_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_4_4_BIT6           , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT6     );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_4_4_BIT6_LEN       , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT6_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_4_4_BIT7           , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT7     );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_3_P0_4_4_BIT7_LEN       , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT7_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_0_01_BIT8          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT8    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_0_01_BIT8_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT8_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_0_01_BIT9          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT9    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_0_01_BIT9_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT9_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_1_01_BIT8          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT8    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_1_01_BIT8_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT8_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_1_01_BIT9          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT9    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_1_01_BIT9_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT9_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_2_23_BIT8          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT8    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_2_23_BIT8_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT8_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_2_23_BIT9          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT9    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_2_23_BIT9_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT9_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_3_23_BIT8          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT8    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_3_23_BIT8_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT8_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_3_23_BIT9          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT9    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_3_23_BIT9_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT9_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_4_4_BIT8           , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT8     );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_4_4_BIT8_LEN       , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT8_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_4_4_BIT9           , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT9     );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_4_P0_4_4_BIT9_LEN       , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT9_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_0_01_BIT10          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT10    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_0_01_BIT10_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT10_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_0_01_BIT11          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT11    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_0_01_BIT11_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT11_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_1_01_BIT10          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT10    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_1_01_BIT10_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT10_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_1_01_BIT11          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT11    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_1_01_BIT11_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT11_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_2_23_BIT10          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT10    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_2_23_BIT10_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT10_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_2_23_BIT11          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT11    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_2_23_BIT11_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT11_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_3_23_BIT10          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT10    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_3_23_BIT10_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT10_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_3_23_BIT11          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT11    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_3_23_BIT11_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT11_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_4_4_BIT10           , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT10     );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_4_4_BIT10_LEN       , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT10_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_4_4_BIT11           , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT11     );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_5_P0_4_4_BIT11_LEN       , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT11_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_0_01_BIT12          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT12    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_0_01_BIT12_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT12_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_0_01_BIT13          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT13    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_0_01_BIT13_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT13_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_1_01_BIT12          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT12    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_1_01_BIT12_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT12_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_1_01_BIT13          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT13    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_1_01_BIT13_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT13_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_2_23_BIT12          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT12    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_2_23_BIT12_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT12_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_2_23_BIT13          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT13    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_2_23_BIT13_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT13_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_3_23_BIT12          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT12    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_3_23_BIT12_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT12_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_3_23_BIT13          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT13    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_3_23_BIT13_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT13_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_4_4_BIT12           , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT12     );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_4_4_BIT12_LEN       , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT12_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_4_4_BIT13           , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT13     );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_6_P0_4_4_BIT13_LEN       , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT13_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_0_01_DD2_PERBIT_RDVREF_DISABLE , 48  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_DD2_PERBIT_RDVREF_DISABLE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_0_01_BIT14          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT14    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_0_01_BIT14_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT14_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_0_01_BIT15          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT15    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_0_01_BIT15_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT15_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_1_01_DD2_PERBIT_RDVREF_DISABLE , 48  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_DD2_PERBIT_RDVREF_DISABLE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_1_01_BIT14          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT14    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_1_01_BIT14_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT14_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_1_01_BIT15          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT15    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_1_01_BIT15_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_BIT15_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_2_23_DD2_PERBIT_RDVREF_DISABLE , 48  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_DD2_PERBIT_RDVREF_DISABLE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_2_23_BIT14          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT14    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_2_23_BIT14_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT14_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_2_23_BIT15          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT15    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_2_23_BIT15_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT15_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_3_23_DD2_PERBIT_RDVREF_DISABLE , 48  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_DD2_PERBIT_RDVREF_DISABLE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_3_23_BIT14          , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT14    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_3_23_BIT14_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT14_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_3_23_BIT15          , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT15    );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_3_23_BIT15_LEN      , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_23_BIT15_LEN );

REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_4_4_DD2_PERBIT_RDVREF_DISABLE , 48  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_DD2_PERBIT_RDVREF_DISABLE );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_4_4_BIT14           , 49  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT14     );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_4_4_BIT14_LEN       , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT14_LEN );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_4_4_BIT15           , 57  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT15     );
REG64_FLD( MCA_DDRPHY_DP16_RD_VREF_DAC_7_P0_4_4_BIT15_LEN       , 7   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_4_BIT15_LEN );

REG64_FLD( MCA_DDRPHY_DP16_DRIFT_LIMITS_P0_0_01_DD2_BLUE_EXTEND_RANGE , 48  , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_DD2_BLUE_EXTEND_RANGE );
REG64_FLD( MCA_DDRPHY_DP16_DRIFT_LIMITS_P0_0_01_DD2_BLUE_EXTEND_RANGE_LEN , 2   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_01_DD2_BLUE_EXTEND_RANGE_LEN );

// DCD DD2 field updates
REG64_FLD( DD2_MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_ADJUST_LEN , 8   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_DD2_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_ADJUST_LEN );
REG64_FLD( DD2_MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_CAL_ENABLE , 58   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_DD2_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_CAL_ENABLE );
REG64_FLD( DD2_MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_POWERDOWN , 60   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_DD2_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_POWERDOWN );
REG64_FLD( DD2_MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_CAL_DONE , 61   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_DD2_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_CAL_DONE );
REG64_FLD( DD2_MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_CAL_ERROR , 62   , SH_UNT_MCA      , SH_ACS_SCOM_RW  ,
           SH_FLD_DD2_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_CAL_ERROR );
#endif
