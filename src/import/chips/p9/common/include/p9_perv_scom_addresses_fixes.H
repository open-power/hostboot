/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/common/include/p9_perv_scom_addresses_fixes.H $      */
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
/// @file perv_scom_addresses_fixes.H
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

#ifndef __P9_PERV_SCOM_ADDRESSES_FIXES_H
#define __P9_PERV_SCOM_ADDRESSES_FIXES_H

//Example,
//Copy the whole line from the *scom_addresses.H file.  Then add
//FIX in front of REG, and add another paramter that is the new
//corrected value.
//FIXREG64( PU_ALTD_ADDR_REG,
//          RULL(0x05022800), SH_UNT, SH_ACS_SCOM,
//          RULL(0x00090000)
//        );

static const uint64_t SH_UNT_PERV_10 = 512;
static const uint64_t SH_UNT_PERV_11 = 513;

REG64( PERV_OB1_CPLT_CONF1,
       RULL(0x0A000009), SH_UNT_PERV_10, SH_ACS_SCOM_RW);
REG64( PERV_OB1_CPLT_CONF1_OR,
       RULL(0x0A000019), SH_UNT_PERV_10, SH_ACS_SCOM1_OR);
REG64( PERV_OB1_CPLT_CONF1_CLEAR,
       RULL(0x0A000029), SH_UNT_PERV_10, SH_ACS_SCOM2_CLEAR);

REG64( PERV_OB2_CPLT_CONF1,
       RULL(0x0B000009), SH_UNT_PERV_11, SH_ACS_SCOM_RW);
REG64( PERV_OB2_CPLT_CONF1_OR,
       RULL(0x0B000019), SH_UNT_PERV_11, SH_ACS_SCOM1_OR);
REG64( PERV_OB2_CPLT_CONF1_CLEAR,
       RULL(0x0B000029), SH_UNT_PERV_11, SH_ACS_SCOM2_CLEAR);


#endif
