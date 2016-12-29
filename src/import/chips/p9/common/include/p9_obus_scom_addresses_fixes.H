/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/include/p9_obus_scom_addresses_fixes.H $ */
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
/// @file obus_scom_addresses_fixes.H
/// @brief The *scom_addresses.H files are  generated form figtree, but
///        the figree can be wrong.  This file is included at the end
///        of scom_addresses.H and allows incorrect constants to be
///        fixed manually.
///
///
// *HWP HWP Owner: Ben Gass <bgass@us.ibm.com>
// *HWP FW Owner: ? <?>
// *HWP Team: SAO
// *HWP Level: 1
// *HWP Consumed by: FSP:HB:HS:OCC:SBE:CME:SGPE:PGPE:FPPE:IPPE

#ifndef __P9_OBUS_SCOM_ADDRESSES_FIXES_H
#define __P9_OBUS_SCOM_ADDRESSES_FIXES_H

//Example,
//Copy the whole line from the *scom_addresses.H file.  Then add
//FIX in front of REG, and add another paramter that is the new
//corrected value.
//FIXREG64( PU_ALTD_ADDR_REG,
//          RULL(0x05022800), SH_UNT, SH_ACS_SCOM,
//          RULL(0x00090000)
//        );

static const uint64_t SH_UNT_OBUS_1 = 514;
static const uint64_t SH_UNT_OBUS_2 = 515;

REG64( OBUS_1_LL1_IOOL_CONTROL,
       RULL(0x0A01080B), SH_UNT_OBUS_1, SH_ACS_SCOM );
REG64( OBUS_1_LL1_LL1_LL1_PB_IOOL_FIR_REG,
       RULL(0x0A010800), SH_UNT_OBUS_2, SH_ACS_SCOM );

REG64( OBUS_2_LL2_IOOL_CONTROL,
       RULL(0x0B01080B), SH_UNT_OBUS_2, SH_ACS_SCOM );
REG64( OBUS_2_LL2_LL2_LL2_PB_IOOL_FIR_REG,
       RULL(0x0B010800), SH_UNT_OBUS_2, SH_ACS_SCOM );

REG64( OBUS_0_IOPPE_PPE_FIR_ACTION0_REG,
       RULL(0x09011046), SH_UNT_OBUS_0, SH_ACS_SCOM );
REG64( OBUS_0_IOPPE_PPE_FIR_ACTION1_REG,
       RULL(0x09011047), SH_UNT_OBUS_0, SH_ACS_SCOM );
REG64( OBUS_0_IOPPE_PPE_FIR_MASK_REG,
       RULL(0x09011043), SH_UNT_OBUS_0, SH_ACS_SCOM );

REG64( OBUS_1_IOPPE_PPE_FIR_ACTION0_REG,
       RULL(0x0A011046), SH_UNT_OBUS_1, SH_ACS_SCOM );
REG64( OBUS_1_IOPPE_PPE_FIR_ACTION1_REG,
       RULL(0x0A011047), SH_UNT_OBUS_1, SH_ACS_SCOM );
REG64( OBUS_1_IOPPE_PPE_FIR_MASK_REG,
       RULL(0x0A011043), SH_UNT_OBUS_1, SH_ACS_SCOM );

REG64( OBUS_2_IOPPE_PPE_FIR_ACTION0_REG,
       RULL(0x0B011046), SH_UNT_OBUS_2, SH_ACS_SCOM );
REG64( OBUS_2_IOPPE_PPE_FIR_ACTION1_REG,
       RULL(0x0B011047), SH_UNT_OBUS_2, SH_ACS_SCOM );
REG64( OBUS_2_IOPPE_PPE_FIR_MASK_REG,
       RULL(0x0B011043), SH_UNT_OBUS_2, SH_ACS_SCOM );

REG64( OBUS_3_IOPPE_PPE_FIR_ACTION0_REG,
       RULL(0x0C011046), SH_UNT_OBUS_3, SH_ACS_SCOM );
REG64( OBUS_3_IOPPE_PPE_FIR_ACTION1_REG,
       RULL(0x0C011047), SH_UNT_OBUS_3, SH_ACS_SCOM );
REG64( OBUS_3_IOPPE_PPE_FIR_MASK_REG,
       RULL(0x0C011043), SH_UNT_OBUS_3, SH_ACS_SCOM );

#endif
