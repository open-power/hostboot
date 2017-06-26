/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/include/p9_misc_scom_addresses_fld_fixes.H $ */
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
/// @file misc_scom_addresses_fld_fixes.H
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

#ifndef __P9_MISC_SCOM_ADDRESSES_FLD_FIXES_H
#define __P9_MISC_SCOM_ADDRESSES_FLD_FIXES_H

// N2 Chiplet Config Register1
REG64_FLD(PERV_N2_CPLT_CONF1_TC_PSI_IOVALID_DC,  10, SH_UNT, SH_ACS_SCOM, SH_FLD_UNUSED);

// PSI Receive Status Register
REG64_FLD(PU_RX_PSI_STATUS_CHECK_PASS,            0, SH_UNT, SH_ACS_SCOM, SH_FLD_UNUSED);
REG64_FLD(PU_RX_PSI_STATUS_CHECK_FAIL,            1, SH_UNT, SH_ACS_SCOM, SH_FLD_UNUSED);

// PSI Transmit Control Register
REG64_FLD(PU_TX_PSI_CNTL_IORESET,                 0, SH_UNT, SH_ACS_SCOM, SH_FLD_UNUSED);

// PSI Receive Control Register
REG64_FLD(PU_RX_PSI_CNTL_IORESET,                 0, SH_UNT, SH_ACS_SCOM, SH_FLD_UNUSED);

// PSI Transmit Channel Internal Address Register
REG64_FLD(PU_TX_CH_INTADDR_IAR_ADDR,              0, SH_UNT, SH_ACS_SCOM, SH_FLD_UNUSED);
REG64_FLD(PU_TX_CH_INTADDR_IAR_ADDR_LEN,          8, SH_UNT, SH_ACS_SCOM, SH_FLD_UNUSED);

// PSI Transmit Channel Misc Register
REG64_FLD(PU_TX_CH_MISC_WEN0,                    12, SH_UNT, SH_ACS_SCOM, SH_FLD_UNUSED);
REG64_FLD(PU_TX_CH_MISC_WEN1,                    13, SH_UNT, SH_ACS_SCOM, SH_FLD_UNUSED);
REG64_FLD(PU_TX_CH_MISC_WEN2,                    14, SH_UNT, SH_ACS_SCOM, SH_FLD_UNUSED);

// RX VGA Control Register1
REG64_FLD(PEC_SCOM0X0B_EDMOD,                    52, SH_UNT_PEC, SH_ACS_SCOM, SH_FLD_UNUSED);
REG64_FLD(PEC_SCOM0X0B_EDMOD_LEN,                 2, SH_UNT_PEC, SH_ACS_SCOM, SH_FLD_UNUSED);

//Example
//Copy the whole line from the *scom_addresses_fld.H file.  Then add FIX in front of REG
//and add another paramter that is the new value you want.
//
//FIXREG64_FLD( PU_ALTD_CMD_REG_FBC_WITH_TM_QUIESCE, 24, SH_UNT, SH_ACS_SCOM, SH_FLD_FBC_WITH_TM_QUIESCE,
//              12);


#endif
