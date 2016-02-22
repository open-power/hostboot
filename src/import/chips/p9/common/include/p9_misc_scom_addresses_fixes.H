/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/common/include/p9_misc_scom_addresses_fixes.H $      */
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
/// @file misc_scom_addresses_fixes.H
/// @brief The *scom_addresses.H files are  generated form figtree, but
///        the figree can be wrong.  This file is included at the end
///        of scom_addresses.H and allows incorrect constants to be
///        fixed manually.
///
// *HWP HWP Owner: Ben Gass <bgass@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Infrastructure
// *HWP Level: 1
// *HWP Consumed by: FSP:HB:HS:OCC:SBE:CME:SGPE:PGPE:FPPE:IPPE

#ifndef __P9_MISC_SCOM_ADDRESSES_FIXES_H
#define __P9_MISC_SCOM_ADDRESSES_FIXES_H


//Example,
//Copy the whole line from the *scom_addresses.H file.  Then add
//FIX in front of REG, and add another paramter that is the new
//corrected value.
//FIXREG64( PU_ALTD_ADDR_REG,
//          RULL(0x05022800), SH_UNT, SH_ACS_SCOM,
//          RULL(0x00090000)
//        );

// ADU registers
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020000) != RULL(0xC0040000)  name: PU_PBAMODE_OCI

// PBA registers
FIXREG64( PU_PBAMODE_OCI,
          RULL(0xC0040000), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020000)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016840) != RULL(0x00014040)  name: PU_PBAMODE_SCOM
FIXREG64( PU_PBAMODE_SCOM,
          RULL(0x00014040), SH_UNT, SH_ACS_SCOM,
          RULL(0x00068000)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020008) != RULL(0xC0040008)  name: PU_PBASLVRST_OCI
FIXREG64( PU_PBASLVRST_OCI,
          RULL(0xC0040008), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020008)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016841) != RULL(0x00014041)  name: PU_PBASLVRST_SCOM
FIXREG64( PU_PBASLVRST_SCOM,
          RULL(0x00014041), SH_UNT, SH_ACS_SCOM,
          RULL(0x00068001)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020020) != RULL(0xC0040020)  name: PU_PBASLVCTL0_OCI
FIXREG64( PU_PBASLVCTL0_OCI,
          RULL(0xC0040020), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020020)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016844) != RULL(0x00014044)  name: PU_PBASLVCTL0_SCOM
FIXREG64( PU_PBASLVCTL0_SCOM,
          RULL(0x00014044), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068004)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020028) != RULL(0xC0040028)  name: PU_PBASLVCTL1_OCI
FIXREG64( PU_PBASLVCTL1_OCI,
          RULL(0xC0040028), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020028)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016845) != RULL(0x00014045)  name: PU_PBASLVCTL1_SCOM
FIXREG64( PU_PBASLVCTL1_SCOM,
          RULL(0x00014045), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068005)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020030) != RULL(0xC0040030)  name: PU_PBASLVCTL2_OCI
FIXREG64( PU_PBASLVCTL2_OCI,
          RULL(0xC0040030), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020030)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016846) != RULL(0x00014046)  name: PU_PBASLVCTL2_SCOM
FIXREG64( PU_PBASLVCTL2_SCOM,
          RULL(0x00014046), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068006)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020038) != RULL(0xC0040038)  name: PU_PBASLVCTL3_OCI
FIXREG64( PU_PBASLVCTL3_OCI,
          RULL(0xC0040038), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020038)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016847) != RULL(0x00014047)  name: PU_PBASLVCTL3_SCOM
FIXREG64( PU_PBASLVCTL3_SCOM,
          RULL(0x00014047), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068007)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020080) != RULL(0xC0040080)  name: PU_BCDE_CTL_OCI
FIXREG64( PU_BCDE_CTL_OCI,
          RULL(0xC0040080), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020080)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016850) != RULL(0x00014050)  name: PU_BCDE_CTL_SCOM
FIXREG64( PU_BCDE_CTL_SCOM,
          RULL(0x00014050), SH_UNT, SH_ACS_SCOM,
          RULL(0x00068010)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020088) != RULL(0xC0040088)  name: PU_BCDE_SET_OCI
FIXREG64( PU_BCDE_SET_OCI,
          RULL(0xC0040088), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020088)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016851) != RULL(0x00014051)  name: PU_BCDE_SET_SCOM
FIXREG64( PU_BCDE_SET_SCOM,
          RULL(0x00014051), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068011)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020090) != RULL(0xC0040090)  name: PU_BCDE_STAT_OCI
FIXREG64( PU_BCDE_STAT_OCI,
          RULL(0xC0040090), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020090)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016852) != RULL(0x00014052)  name: PU_BCDE_STAT_SCOM
FIXREG64( PU_BCDE_STAT_SCOM,
          RULL(0x00014052), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x00068012)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020098) != RULL(0xC0040098)  name: PU_BCDE_PBADR_OCI
FIXREG64( PU_BCDE_PBADR_OCI,
          RULL(0xC0040098), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020098)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016853) != RULL(0x00014053)  name: PU_BCDE_PBADR_SCOM
FIXREG64( PU_BCDE_PBADR_SCOM,
          RULL(0x00014053), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068013)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200A0) != RULL(0xC00400A0)  name: PU_BCDE_OCIBAR_OCI
FIXREG64( PU_BCDE_OCIBAR_OCI,
          RULL(0xC00400A0), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200A0)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016854) != RULL(0x00014054)  name: PU_BCDE_OCIBAR_SCOM
FIXREG64( PU_BCDE_OCIBAR_SCOM,
          RULL(0x00014054), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068014)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200A8) != RULL(0xC00400A8)  name: PU_BCUE_CTL_OCI
FIXREG64( PU_BCUE_CTL_OCI,
          RULL(0xC00400A8), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200A8)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016855) != RULL(0x00014055)  name: PU_BCUE_CTL_SCOM
FIXREG64( PU_BCUE_CTL_SCOM,
          RULL(0x00014055), SH_UNT, SH_ACS_SCOM,
          RULL(0x00068015)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200B0) != RULL(0xC00400B0)  name: PU_BCUE_SET_OCI
FIXREG64( PU_BCUE_SET_OCI,
          RULL(0xC00400B0), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200B0)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016856) != RULL(0x00014056)  name: PU_BCUE_SET_SCOM
FIXREG64( PU_BCUE_SET_SCOM,
          RULL(0x00014056), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068016)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200B8) != RULL(0xC00400B8)  name: PU_BCUE_STAT_OCI
FIXREG64( PU_BCUE_STAT_OCI,
          RULL(0xC00400B8), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200B8)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016857) != RULL(0x00014057)  name: PU_BCUE_STAT_SCOM
FIXREG64( PU_BCUE_STAT_SCOM,
          RULL(0x00014057), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x00068017)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200C0) != RULL(0xC00400C0)  name: PU_BCUE_PBADR_OCI
FIXREG64( PU_BCUE_PBADR_OCI,
          RULL(0xC00400C0), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200C0)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016858) != RULL(0x00014058)  name: PU_BCUE_PBADR_SCOM
FIXREG64( PU_BCUE_PBADR_SCOM,
          RULL(0x00014058), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068018)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200C8) != RULL(0xC00400C8)  name: PU_BCUE_OCIBAR_OCI
FIXREG64( PU_BCUE_OCIBAR_OCI,
          RULL(0xC00400C8), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200C8)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016859) != RULL(0x00014059)  name: PU_BCUE_OCIBAR_SCOM
FIXREG64( PU_BCUE_OCIBAR_SCOM,
          RULL(0x00014059), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068019)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200D0) != RULL(0xC00400D0)  name: PU_PBAPBOCR0_OCI
FIXREG64( PU_PBAPBOCR0_OCI,
          RULL(0xC00400D0), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200D0)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x0501685A) != RULL(0x0001405A)  name: PU_PBAPBOCR0_SCOM
FIXREG64( PU_PBAPBOCR0_SCOM,
          RULL(0x0001405A), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x0006801A)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200D8) != RULL(0xC00400D8)  name: PU_PBAPBOCR1_OCI
FIXREG64( PU_PBAPBOCR1_OCI,
          RULL(0xC00400D8), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200D8)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x0501685B) != RULL(0x0001405B)  name: PU_PBAPBOCR1_SCOM
FIXREG64( PU_PBAPBOCR1_SCOM,
          RULL(0x0001405B), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x0006801B)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200E0) != RULL(0xC00400E0)  name: PU_PBAPBOCR2_OCI
FIXREG64( PU_PBAPBOCR2_OCI,
          RULL(0xC00400E0), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200E0)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x0501685C) != RULL(0x0001405C)  name: PU_PBAPBOCR2_SCOM
FIXREG64( PU_PBAPBOCR2_SCOM,
          RULL(0x0001405C), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x0006801C)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200E8) != RULL(0xC00400E8)  name: PU_PBAPBOCR3_OCI
FIXREG64( PU_PBAPBOCR3_OCI,
          RULL(0xC00400E8), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200E8)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x0501685D) != RULL(0x0001405D)  name: PU_PBAPBOCR3_SCOM
FIXREG64( PU_PBAPBOCR3_SCOM,
          RULL(0x0001405D), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x0006801D)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200F0) != RULL(0xC00400F0)  name: PU_PBAPBOCR4_OCI
FIXREG64( PU_PBAPBOCR4_OCI,
          RULL(0xC00400F0), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200F0)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x0501685E) != RULL(0x0001405E)  name: PU_PBAPBOCR4_SCOM
FIXREG64( PU_PBAPBOCR4_SCOM,
          RULL(0x0001405E), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x0006801E)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200F8) != RULL(0xC00400F8)  name: PU_PBAPBOCR5_OCI
FIXREG64( PU_PBAPBOCR5_OCI,
          RULL(0xC00400F8), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200F8)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x0501685F) != RULL(0x0001405F)  name: PU_PBAPBOCR5_SCOM
FIXREG64( PU_PBAPBOCR5_SCOM,
          RULL(0x0001405F), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x0006801F)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020100) != RULL(0xC0040100)  name: PU_PBAXSNDTX_OCI
FIXREG64( PU_PBAXSNDTX_OCI,
          RULL(0xC0040100), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020100)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016860) != RULL(0x00014060)  name: PU_PBAXSNDTX_SCOM
FIXREG64( PU_PBAXSNDTX_SCOM,
          RULL(0x00014060), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068020)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020108) != RULL(0xC0040108)  name: PU_PBAXCFG_OCI
FIXREG64( PU_PBAXCFG_OCI,
          RULL(0xC0040108), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020108)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016861) != RULL(0x00014061)  name: PU_PBAXCFG_SCOM
FIXREG64( PU_PBAXCFG_SCOM,
          RULL(0x00014061), SH_UNT, SH_ACS_SCOM,
          RULL(0x00068021)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020110) != RULL(0xC0040110)  name: PU_PBAXSNDSTAT_OCI
FIXREG64( PU_PBAXSNDSTAT_OCI,
          RULL(0xC0040110), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020110)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016862) != RULL(0x00014062)  name: PU_PBAXSNDSTAT_SCOM
FIXREG64( PU_PBAXSNDSTAT_SCOM,
          RULL(0x00014062), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x00068022)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020120) != RULL(0xC0040120)  name: PU_PBAXRCVSTAT_OCI
FIXREG64( PU_PBAXRCVSTAT_OCI,
          RULL(0xC0040120), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020120)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016864) != RULL(0x00014064)  name: PU_PBAXRCVSTAT_SCOM
FIXREG64( PU_PBAXRCVSTAT_SCOM,
          RULL(0x00014064), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x00068024)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020130) != RULL(0xC0040130)  name: PU_PBAXSHBR0_OCI
FIXREG64( PU_PBAXSHBR0_OCI,
          RULL(0xC0040130), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020130)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016866) != RULL(0x00014066)  name: PU_PBAXSHBR0_SCOM
FIXREG64( PU_PBAXSHBR0_SCOM,
          RULL(0x00014066), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068026)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020138) != RULL(0xC0040138)  name: PU_PBAXSHCS0_OCI
FIXREG64( PU_PBAXSHCS0_OCI,
          RULL(0xC0040138), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020138)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x05016867) != RULL(0x00014067)  name: PU_PBAXSHCS0_SCOM
FIXREG64( PU_PBAXSHCS0_SCOM,
          RULL(0x00014067), SH_UNT, SH_ACS_SCOM,
          RULL(0x00068027)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020150) != RULL(0xC0040150)  name: PU_PBAXSHBR1_OCI
FIXREG64( PU_PBAXSHBR1_OCI,
          RULL(0xC0040150), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020150)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x0501686A) != RULL(0x0001406A)  name: PU_PBAXSHBR1_SCOM
FIXREG64( PU_PBAXSHBR1_SCOM,
          RULL(0x0001406A), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x0006802A)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020158) != RULL(0xC0040158)  name: PU_PBAXSHCS1_OCI
FIXREG64( PU_PBAXSHCS1_OCI,
          RULL(0xC0040158), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020158)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x0501686B) != RULL(0x0001406B)  name: PU_PBAXSHCS1_SCOM
FIXREG64( PU_PBAXSHCS1_SCOM,
          RULL(0x0001406B), SH_UNT, SH_ACS_SCOM,
          RULL(0x0006802B)
        );


//WARNING: This register is not defined anymore in the figtree.
REG64( PU_BCDE_SET_SCOM, RULL(0x00068011), SH_UNT, SH_ACS_SCOM_RW);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBAPBOCR4_SCOM, RULL(0x0006801E), SH_UNT, SH_ACS_SCOM_RO);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBAPBOCR2_SCOM, RULL(0x0006801C), SH_UNT, SH_ACS_SCOM_RO);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBAXSHCS0_SCOM, RULL(0x00068027), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBAPBOCR3_SCOM, RULL(0x0006801D), SH_UNT, SH_ACS_SCOM_RO);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_BCUE_STAT_SCOM, RULL(0x00068017), SH_UNT, SH_ACS_SCOM_RO);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_BCUE_OCIBAR_SCOM, RULL(0x00068019), SH_UNT, SH_ACS_SCOM_RW);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBAXSNDTX_SCOM, RULL(0x00068020), SH_UNT, SH_ACS_SCOM_RW);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_BCDE_CTL_SCOM, RULL(0x00068010), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBASLVCTL0_SCOM, RULL(0x00068004), SH_UNT, SH_ACS_SCOM_RW);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBAPBOCR1_SCOM, RULL(0x0006801B), SH_UNT, SH_ACS_SCOM_RO);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBAXSHBR1_SCOM, RULL(0x0006802A), SH_UNT, SH_ACS_SCOM_RW);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBASLVCTL2_SCOM, RULL(0x00068006), SH_UNT, SH_ACS_SCOM_RW);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBASLVCTL1_SCOM, RULL(0x00068005), SH_UNT, SH_ACS_SCOM_RW);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_BCUE_SET_SCOM, RULL(0x00068016), SH_UNT, SH_ACS_SCOM_RW);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBAPBOCR0_SCOM, RULL(0x0006801A), SH_UNT, SH_ACS_SCOM_RO);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBAMODE_SCOM, RULL(0x00068000), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBAXSHBR0_SCOM, RULL(0x00068026), SH_UNT, SH_ACS_SCOM_RW);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBASLVCTL3_SCOM, RULL(0x00068007), SH_UNT, SH_ACS_SCOM_RW);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_BCUE_PBADR_SCOM, RULL(0x00068018), SH_UNT, SH_ACS_SCOM_RW);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBAPBOCR5_SCOM, RULL(0x0006801F), SH_UNT, SH_ACS_SCOM_RO);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBAXSHCS1_SCOM, RULL(0x0006802B), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBAXRCVSTAT_SCOM, RULL(0x00068024), SH_UNT, SH_ACS_SCOM_RO);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_BCUE_CTL_SCOM, RULL(0x00068015), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBASLVRST_SCOM, RULL(0x00068001), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_BCDE_PBADR_SCOM, RULL(0x00068013), SH_UNT, SH_ACS_SCOM_RW);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBAXSNDSTAT_SCOM, RULL(0x00068022), SH_UNT, SH_ACS_SCOM_RO);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_BCDE_OCIBAR_SCOM, RULL(0x00068014), SH_UNT, SH_ACS_SCOM_RW);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_BCDE_STAT_SCOM, RULL(0x00068012), SH_UNT, SH_ACS_SCOM_RO);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PBAXCFG_SCOM, RULL(0x00068021), SH_UNT, SH_ACS_SCOM);

REG64( PEC_PCS_RX_CONFIG_MODE_REG                              , RULL(0x800004800D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_RX_CONFIG_MODE_REG                            , RULL(0x800004800D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_RX_CONFIG_MODE_REG                            , RULL(0x800004800E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_RX_CONFIG_MODE_REG                            , RULL(0x800004800F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PCS_RX_ROT_CNTL_REG                                 , RULL(0x800004820D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_RX_ROT_CNTL_REG                               , RULL(0x800004820D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_RX_ROT_CNTL_REG                               , RULL(0x800004820E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_RX_ROT_CNTL_REG                               , RULL(0x800004820F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PCS_RX_CDR_GAIN_REG                                 , RULL(0x800004B30D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_RX_CDR_GAIN_REG                               , RULL(0x800004B30D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_RX_CDR_GAIN_REG                               , RULL(0x800004B30E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_RX_CDR_GAIN_REG                               , RULL(0x800004B30F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PCS_RX_LOFF_CONTROL_REG                             , RULL(0x800004A60D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_RX_LOFF_CONTROL_REG                           , RULL(0x800004A60D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_RX_LOFF_CONTROL_REG                           , RULL(0x800004A60E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_RX_LOFF_CONTROL_REG                           , RULL(0x800004A60F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PCS_RX_SIGDET_CONTROL_REG                           , RULL(0x800004A70D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_RX_SIGDET_CONTROL_REG                         , RULL(0x800004A70D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_RX_SIGDET_CONTROL_REG                         , RULL(0x800004A70E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_RX_SIGDET_CONTROL_REG                         , RULL(0x800004A70F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PCS_RX_VGA_CONTROL1_REG                             , RULL(0x8000048B0D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_RX_VGA_CONTROL1_REG                           , RULL(0x8000048B0D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_RX_VGA_CONTROL1_REG                           , RULL(0x8000048B0E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_RX_VGA_CONTROL1_REG                           , RULL(0x8000048B0F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PCS_RX_VGA_CONTROL2_REG                             , RULL(0x8000048C0D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_RX_VGA_CONTROL2_REG                           , RULL(0x8000048C0D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_RX_VGA_CONTROL2_REG                           , RULL(0x8000048C0E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_RX_VGA_CONTROL2_REG                           , RULL(0x8000048C0F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PCS_RX_VGA_CONTROL3_REG                             , RULL(0x8000048D0D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_RX_VGA_CONTROL3_REG                           , RULL(0x8000048D0D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_RX_VGA_CONTROL3_REG                           , RULL(0x8000048D0E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_RX_VGA_CONTROL3_REG                           , RULL(0x8000048D0F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PCS_TX_DCLCK_ROTATOR_REG                            , RULL(0x800004450D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_TX_DCLCK_ROTATOR_REG                          , RULL(0x800004450D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_TX_DCLCK_ROTATOR_REG                          , RULL(0x800004450E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_TX_DCLCK_ROTATOR_REG                          , RULL(0x800004450F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PCS_TX_FIFO_CONFIG_OFFSET_REG                       , RULL(0x8000044F0D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_TX_FIFO_CONFIG_OFFSET_REG                     , RULL(0x8000044F0D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_TX_FIFO_CONFIG_OFFSET_REG                     , RULL(0x8000044F0E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_TX_FIFO_CONFIG_OFFSET_REG                     , RULL(0x8000044F0F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PCS_TX_PCIE_REC_DETECT_CNTL1_REG                    , RULL(0x8000046C0D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_TX_PCIE_REC_DETECT_CNTL1_REG                  , RULL(0x8000046C0D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_TX_PCIE_REC_DETECT_CNTL1_REG                  , RULL(0x8000046C0E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_TX_PCIE_REC_DETECT_CNTL1_REG                  , RULL(0x8000046C0F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PCS_TX_PCIE_REC_DETECT_CNTL2_REG                    , RULL(0x8000046D0D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_TX_PCIE_REC_DETECT_CNTL2_REG                  , RULL(0x8000046D0D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_TX_PCIE_REC_DETECT_CNTL2_REG                  , RULL(0x8000046D0E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_TX_PCIE_REC_DETECT_CNTL2_REG                  , RULL(0x8000046D0F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PCS_TX_POWER_SEQ_ENABLE_REG                         , RULL(0x800004700D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_TX_POWER_SEQ_ENABLE_REG                       , RULL(0x800004700D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_TX_POWER_SEQ_ENABLE_REG                       , RULL(0x800004700E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_TX_POWER_SEQ_ENABLE_REG                       , RULL(0x800004700F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PCS_PCLCK_CNTL_PLLA_REG                             , RULL(0x8000050F0D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_PCLCK_CNTL_PLLA_REG                           , RULL(0x8000050F0D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_PCLCK_CNTL_PLLA_REG                           , RULL(0x8000050F0E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_PCLCK_CNTL_PLLA_REG                           , RULL(0x8000050F0F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PCS_PCLCK_CNTL_PLLB_REG                             , RULL(0x8000054F0D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_PCLCK_CNTL_PLLB_REG                           , RULL(0x8000054F0D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_PCLCK_CNTL_PLLB_REG                           , RULL(0x8000054F0E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_PCLCK_CNTL_PLLB_REG                           , RULL(0x8000054F0F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );


#endif
