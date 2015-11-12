/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/common/include/quad_scom_addresses_fixes.H $         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file quad_scom_addresses_fixes.H
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

#ifndef __P9_QUAD_SCOM_ADDRESSES_FIXES_H
#define __P9_QUAD_SCOM_ADDRESSES_FIXES_H

//Example,
//Copy the whole line from the *scom_addresses.H file.  Then add
//FIX in front of REG, and add another paramter that is the new
//corrected value.
//FIXREG64( PU_ALTD_ADDR_REG,
//          RULL(0x05022800), SH_UNT, SH_ACS_SCOM,
//          RULL(0x00090000)
//        );

//L2 laoder
REG64( EQ_QPPM_QACCR_SCOM2                                     , RULL(0x100F0162), SH_UNT_EQ       , SH_ACS_SCOM2     );
REG64( EQ_PPM_CGCR_OR                                          , RULL(0x100F0167), SH_UNT_EQ       , SH_ACS_SCOM2_OR  );

REG64( EQ_PPM_CGCR_CLEAR                                       , RULL(0x100F0166), SH_UNT_EQ       ,
       SH_ACS_SCOM1_CLEAR );

REG64( C_PPM_CGCR_CLEAR                                        , RULL(0x200F0166), SH_UNT_C        ,
       SH_ACS_SCOM1_CLEAR );

REG64( C_PPM_CGCR_OR                                           , RULL(0x200F0167), SH_UNT_C        , SH_ACS_SCOM2_OR  );

#endif
