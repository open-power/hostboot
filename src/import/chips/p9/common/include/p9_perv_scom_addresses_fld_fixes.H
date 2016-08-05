/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/include/p9_perv_scom_addresses_fld_fixes.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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

//static const uint64_t SH_UNT_PERV_CBS_ENVSTAT = 514;
static const uint64_t SH_FLD_C4_TEST_ENABLE = 32000;
static const uint64_t SH_FLD_C4_CARD_TEST_BSC = 32001;
static const uint64_t SH_FLD_C4_VDN_GPOOD = 32002;
static const uint64_t SH_FLD_C4_FSI_IN_ENA = 32003;
static const uint64_t SH_FLD_C4_CHIP_MASTER = 32004;
static const uint64_t SH_FLD_C4_SMD = 32005;

REG64_FLD( PERV_CBS_ENVSTAT_C4_TEST_ENABLE                        , 0   , SH_UNT_PERV_CBS_ENVSTAT     ,
           SH_ACS_SCOM     ,
           SH_FLD_C4_TEST_ENABLE );
REG64_FLD( PERV_CBS_ENVSTAT_C4_CARD_TEST_BSC                      , 1   , SH_UNT_PERV_CBS_ENVSTAT     ,
           SH_ACS_SCOM     ,
           SH_FLD_C4_CARD_TEST_BSC );
REG64_FLD( PERV_CBS_ENVSTAT_C4_VDN_GPOOD                          , 2   , SH_UNT_PERV_CBS_ENVSTAT     ,
           SH_ACS_SCOM     ,
           SH_FLD_C4_VDN_GPOOD );
REG64_FLD( PERV_CBS_ENVSTAT_C4_FSI_IN_ENA                         , 3   , SH_UNT_PERV_CBS_ENVSTAT     ,
           SH_ACS_SCOM     ,
           SH_FLD_C4_FSI_IN_ENA );
REG64_FLD( PERV_CBS_ENVSTAT_C4_CHIP_MASTER                        , 4   , SH_UNT_PERV_CBS_ENVSTAT     ,
           SH_ACS_SCOM     ,
           SH_FLD_C4_CHIP_MASTER );
REG64_FLD( PERV_CBS_ENVSTAT_C4_SMD                                , 5   , SH_UNT_PERV_CBS_ENVSTAT     ,
           SH_ACS_SCOM     ,
           SH_FLD_C4_SMD );

#endif
