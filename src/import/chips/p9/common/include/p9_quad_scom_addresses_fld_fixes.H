/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/include/p9_quad_scom_addresses_fld_fixes.H $ */
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
/// @file quad_scom_addresses_fld_fixes.H
/// @brief The *scom_addresses_fld.H files are generated form figtree,
///        but the figree can be wrong.  This file is included in
///        *_scom_addresses_fld.H and allows incorrect constants to be
///        fixed manually.
///
// *HWP HWP Owner: Ben Gass <bgass@us.ibm.com>
// *HWP FW Owner: ? <?>
// *HWP Team: SAO
// *HWP Level: 3
// *HWP Consumed by: FSP:HB:HS:OCC:SBE:CME:SGPE:PGPE:FPPE:IPPE

#ifndef __P9_QUAD_SCOM_ADDRESSES_FLD_FIXES_H
#define __P9_QUAD_SCOM_ADDRESSES_FLD_FIXES_H

//Example
//Copy the whole line from the *scom_addresses_fld.H file.  Then add FIX in front of REG
//and add another paramter that is the new value you want.
//
//FIXREG64_FLD( PU_ALTD_CMD_REG_FBC_WITH_TM_QUIESCE, 24, SH_UNT, SH_ACS_SCOM, SH_FLD_FBC_WITH_TM_QUIESCE,
//              12);


//L2 loader fixes
REG64_FLD( EQ_QPPM_QACCR_L2_EX0_CLK_SYNC_ENABLE                    , 13  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX0_CLK_SYNC_ENABLE );

REG64_FLD( EQ_QPPM_QACCR_L2_EX1_CLK_SYNC_ENABLE                    , 33  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX1_CLK_SYNC_ENABLE );

REG64_FLD( EQ_QPPM_QACCR_L2_EX0_CLKGLM_SEL                         , 19  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX0_CLKGLM_SEL );

REG64_FLD( EQ_QPPM_QACCR_L2_EX1_CLKGLM_SEL                         , 39  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX1_CLKGLM_SEL );


#endif
