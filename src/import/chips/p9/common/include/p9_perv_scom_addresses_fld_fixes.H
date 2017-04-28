/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/include/p9_perv_scom_addresses_fld_fixes.H $ */
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
/// @file perv_scom_addresses_fld_fixes.H
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

#include <p9_const_common.H>

#ifndef __P9_PERV_SCOM_ADDRESSES_FLD_FIXES_H
#define __P9_PERV_SCOM_ADDRESSES_FLD_FIXES_H

#include <p9_perv_scom_addresses_fixes.H>

//Example
//Copy the whole line from the *scom_addresses_fld.H file.  Then add FIX in front of REG
//and add another paramter that is the new value you want.
//
//FIXREG64_FLD( PU_ALTD_CMD_REG_FBC_WITH_TM_QUIESCE, 24, SH_UNT, SH_ACS_SCOM, SH_FLD_FBC_WITH_TM_QUIESCE,
//              12);

static const uint64_t SH_FLD_CLOCK_REGION_ALL_UNITS = 32006;
static const uint64_t SH_FLD_CLOCK_REGION_ALL_UNITS_LEN = 32007;
static const uint64_t SH_FLD_SEL_THOLD_ALL = 32008;
static const uint64_t SH_FLD_SEL_THOLD_ALL_LEN = 32009;
static const uint64_t SH_FLD_ALL_UNITS = 32010;
static const uint64_t SH_FLD_ALL_UNITS_LEN = 32011;
static const uint64_t SH_FLD_TC_ALL_REGIONS_FENCE = 32012;
static const uint64_t SH_FLD_TC_ALL_REGIONS_FENCE_LEN = 32013;
static const uint64_t SH_FLD_SCAN_REGION_ALL_UNITS = 32014;
static const uint64_t SH_FLD_SCAN_REGION_ALL_UNITS_LEN = 32015;
static const uint64_t SH_FLD_SCAN_ALL_TYPES = 32016;
static const uint64_t SH_FLD_SCAN_ALL_TYPES_LEN = 32017;
static const uint64_t SH_FLD_TSFSI_NV_REFCLK_EN_DC = 22564;
static const uint64_t SH_FLD_TSFSI_NV_REFCLK_EN_DC_LEN = 22565;

REG64_FLD( PERV_1_CLK_REGION_CLOCK_REGION_ALL_UNITS           , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_REGION_ALL_UNITS );
REG64_FLD( PERV_1_CLK_REGION_CLOCK_REGION_ALL_UNITS_LEN       , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_REGION_ALL_UNITS_LEN );
REG64_FLD( PERV_1_CLK_REGION_SEL_THOLD_ALL                    , 48  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEL_THOLD_ALL );
REG64_FLD( PERV_1_CLK_REGION_SEL_THOLD_ALL_LEN                , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEL_THOLD_ALL_LEN );
REG64_FLD( PERV_1_CLK_REGION_CLOCK_REGION_PERV                , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_PERV );

REG64_FLD( PERV_1_BIST_TC_BIST_START_TEST_DC                      , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_TC_START_TEST_DC );
REG64_FLD( PERV_1_BIST_BIST_ALL_UNITS                             , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ALL_UNITS );
REG64_FLD( PERV_1_BIST_BIST_ALL_UNITS_LEN                         , 11   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ALL_UNITS_LEN );

REG64_FLD( PERV_1_OPCG_GO                                         , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_GO );
REG64_FLD( PERV_1_OPCG_STARTS_BIST                                , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STARTS_BIST );

REG64_FLD( PERV_1_CPLT_CTRL1_TC_ALL_REGIONS_FENCE                 , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_ALL_REGIONS_FENCE );
REG64_FLD( PERV_1_CPLT_CTRL1_TC_ALL_REGIONS_FENCE_LEN             , 11   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_ALL_REGIONS_FENCE_LEN );

REG64_FLD( PERV_1_SCAN_REGION_TYPE_SCAN_REGION_ALL_UNITS          , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SCAN_REGION_ALL_UNITS );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_SCAN_REGION_ALL_UNITS_LEN      , 11   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SCAN_REGION_ALL_UNITS_LEN );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_SCAN_ALL_TYPES                 , 48   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SCAN_ALL_TYPES );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_SCAN_ALL_TYPES_LEN             , 12   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SCAN_ALL_TYPES_LEN );

REG64_FLD( PERV_1_OPCG_REG0_OPCG_STARTS_BIST                       , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STARTS_BIST );
REG64_FLD( PERV_1_OPCG_REG0_OPCG_GO                                , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_GO         );

REG64_FLD( PERV_ROOT_CTRL6_TSFSI_NV_REFCLK_EN_DC                   , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TSFSI_NV_REFCLK_EN_DC );
REG64_FLD( PERV_ROOT_CTRL6_TSFSI_NV_REFCLK_EN_DC_LEN               , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TSFSI_NV_REFCLK_EN_DC_LEN );


#endif
