/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/common/include/p9_misc_scom_addresses_fld_fixes.H $  */
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

//Example
//Copy the whole line from the *scom_addresses_fld.H file.  Then add FIX in front of REG
//and add another paramter that is the new value you want.
//
//FIXREG64_FLD( PU_ALTD_CMD_REG_FBC_WITH_TM_QUIESCE, 24, SH_UNT, SH_ACS_SCOM, SH_FLD_FBC_WITH_TM_QUIESCE,
//              12);


#endif
