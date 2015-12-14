/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/common/include/p9_misc_scom_addresses_fixes.H $      */
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
FIXREG64( PU_ALTD_ADDR_REG,
          RULL(0x05022800), SH_UNT, SH_ACS_SCOM,
          RULL(0x00090000)
        );
FIXREG64( PU_ALTD_CMD_REG,
          RULL(0x05022801), SH_UNT, SH_ACS_SCOM,
          RULL(0x00090001)
        );
FIXREG64( PU_ALTD_OPTION_REG,
          RULL(0x05022802), SH_UNT, SH_ACS_SCOM,
          RULL(0x00090002)
        );
FIXREG64( PU_ALTD_STATUS_REG,
          RULL(0x05022803), SH_UNT, SH_ACS_SCOM,
          RULL(0x00090003)
        );
FIXREG64( PU_ALTD_DATA_REG,
          RULL(0x05022804), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00090004)
        );
FIXREG64( PU_FORCE_ECC_REG,
          RULL(0x0502280D), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x0009000D)
        );
FIXREG64( PU_XSCOM_BASE_REG,
          RULL(0x05022810), SH_UNT, SH_ACS_SCOM,
          RULL(0x00090010)
        );
FIXREG64( PU_XSCOM_MODE_REG,
          RULL(0x05022811), SH_UNT, SH_ACS_SCOM,
          RULL(0x00090011)
        );
FIXREG64( PU_XSCOM_LOG_REG,
          RULL(0x05022812), SH_UNT, SH_ACS_SCOM,
          RULL(0x00090012)
        );
FIXREG64( PU_XSCOM_ERR_REG,
          RULL(0x05022813), SH_UNT, SH_ACS_SCOM_WCLRREG,
          RULL(0x00090013)
        );
FIXREG64( PU_XSCOM_RCVED_STAT_REG,
          RULL(0x05022818), SH_UNT, SH_ACS_SCOM_WCLRREG,
          RULL(0x00090018)
        );
FIXREG64( PU_ADS_XSCOM_CMD_REG,
          RULL(0x0502281C), SH_UNT, SH_ACS_SCOM,
          RULL(0x0009001C)
        );
FIXREG64( PU_XSCOM_DAT0_REG,
          RULL(0x0502281E), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x0009001E)
        );
FIXREG64( PU_XSCOM_DAT1_REG,
          RULL(0x0502281F), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x0009001F)
        );
FIXREG64( PU_SND_STAT_REG,
          RULL(0x05022820), SH_UNT, SH_ACS_SCOM,
          RULL(0x00090020)
        );
FIXREG64( PU_SND_MODE_REG,
          RULL(0x05022821), SH_UNT, SH_ACS_SCOM,
          RULL(0x00090021)
        );
FIXREG64( PU_RCV_ERRLOG0_REG,
          RULL(0x05022822), SH_UNT, SH_ACS_SCOM_WAND,
          RULL(0x00090022)
        );
FIXREG64( PU_RCV_ERRLOG1_REG,
          RULL(0x05022823), SH_UNT, SH_ACS_SCOM_WAND,
          RULL(0x00090023)
        );
FIXREG64( PU_TOD_DATA_SND_REG,
          RULL(0x05022828), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00090028)
        );
FIXREG64( PU_TOD_DATA_RCV_REG,
          RULL(0x05022829), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x00090029)
        );
FIXREG64( PU_TOD_CMD_REG,
          RULL(0x0502282A), SH_UNT, SH_ACS_SCOM,
          RULL(0x0009002A)
        );
FIXREG64( PU_IO_DATA_REG,
          RULL(0x05022830), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x00090030)
        );
FIXREG64( PU_PIB_CMD_REG,
          RULL(0x05022831), SH_UNT, SH_ACS_SCOM,
          RULL(0x00090031)
        );
FIXREG64( PU_PIB_DATA_REG,
          RULL(0x05022832), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x00090032)
        );
FIXREG64( PU_PIB_RESET_REG,
          RULL(0x05022833), SH_UNT, SH_ACS_SCOM,
          RULL(0x00090033)
        );
FIXREG64( PU_LPC_BASE_REG,
          RULL(0x05022840), SH_UNT, SH_ACS_SCOM,
          RULL(0x00090040)
        );
FIXREG64( PU_LPC_CMD_REG,
          RULL(0x05022841), SH_UNT, SH_ACS_SCOM,
          RULL(0x00090041)
        );
FIXREG64( PU_LPC_DATA_REG,
          RULL(0x05022842), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x00090042)
        );
FIXREG64( PU_ADU_HANG_DIV_REG,
          RULL(0x05022850), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00090050)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020000) != RULL(0xC0040000)  name: PU_PBAMODE_OCI

// PBA registers
FIXREG64( PU_PBAMODE_OCI,
          RULL(0xC0040000), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020000)
        );
FIXREG64( PU_PBAMODE_SCOM,
          RULL(0x05016840), SH_UNT, SH_ACS_SCOM,
          RULL(0x00068000)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020008) != RULL(0xC0040008)  name: PU_PBASLVRST_OCI
FIXREG64( PU_PBASLVRST_OCI,
          RULL(0xC0040008), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020008)
        );
FIXREG64( PU_PBASLVRST_SCOM,
          RULL(0x05016841), SH_UNT, SH_ACS_SCOM,
          RULL(0x00068001)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020020) != RULL(0xC0040020)  name: PU_PBASLVCTL0_OCI
FIXREG64( PU_PBASLVCTL0_OCI,
          RULL(0xC0040020), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020020)
        );
FIXREG64( PU_PBASLVCTL0_SCOM,
          RULL(0x05016844), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068004)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020028) != RULL(0xC0040028)  name: PU_PBASLVCTL1_OCI
FIXREG64( PU_PBASLVCTL1_OCI,
          RULL(0xC0040028), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020028)
        );
FIXREG64( PU_PBASLVCTL1_SCOM,
          RULL(0x05016845), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068005)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020030) != RULL(0xC0040030)  name: PU_PBASLVCTL2_OCI
FIXREG64( PU_PBASLVCTL2_OCI,
          RULL(0xC0040030), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020030)
        );
FIXREG64( PU_PBASLVCTL2_SCOM,
          RULL(0x05016846), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068006)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020038) != RULL(0xC0040038)  name: PU_PBASLVCTL3_OCI
FIXREG64( PU_PBASLVCTL3_OCI,
          RULL(0xC0040038), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020038)
        );
FIXREG64( PU_PBASLVCTL3_SCOM,
          RULL(0x05016847), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068007)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020080) != RULL(0xC0040080)  name: PU_BCDE_CTL_OCI
FIXREG64( PU_BCDE_CTL_OCI,
          RULL(0xC0040080), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020080)
        );
FIXREG64( PU_BCDE_CTL_SCOM,
          RULL(0x05016850), SH_UNT, SH_ACS_SCOM,
          RULL(0x00068010)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020088) != RULL(0xC0040088)  name: PU_BCDE_SET_OCI
FIXREG64( PU_BCDE_SET_OCI,
          RULL(0xC0040088), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020088)
        );
FIXREG64( PU_BCDE_SET_SCOM,
          RULL(0x05016851), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068011)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020090) != RULL(0xC0040090)  name: PU_BCDE_STAT_OCI
FIXREG64( PU_BCDE_STAT_OCI,
          RULL(0xC0040090), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020090)
        );
FIXREG64( PU_BCDE_STAT_SCOM,
          RULL(0x05016852), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x00068012)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020098) != RULL(0xC0040098)  name: PU_BCDE_PBADR_OCI
FIXREG64( PU_BCDE_PBADR_OCI,
          RULL(0xC0040098), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020098)
        );
FIXREG64( PU_BCDE_PBADR_SCOM,
          RULL(0x05016853), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068013)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200A0) != RULL(0xC00400A0)  name: PU_BCDE_OCIBAR_OCI
FIXREG64( PU_BCDE_OCIBAR_OCI,
          RULL(0xC00400A0), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200A0)
        );
FIXREG64( PU_BCDE_OCIBAR_SCOM,
          RULL(0x05016854), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068014)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200A8) != RULL(0xC00400A8)  name: PU_BCUE_CTL_OCI
FIXREG64( PU_BCUE_CTL_OCI,
          RULL(0xC00400A8), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200A8)
        );
FIXREG64( PU_BCUE_CTL_SCOM,
          RULL(0x05016855), SH_UNT, SH_ACS_SCOM,
          RULL(0x00068015)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200B0) != RULL(0xC00400B0)  name: PU_BCUE_SET_OCI
FIXREG64( PU_BCUE_SET_OCI,
          RULL(0xC00400B0), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200B0)
        );
FIXREG64( PU_BCUE_SET_SCOM,
          RULL(0x05016856), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068016)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200B8) != RULL(0xC00400B8)  name: PU_BCUE_STAT_OCI
FIXREG64( PU_BCUE_STAT_OCI,
          RULL(0xC00400B8), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200B8)
        );
FIXREG64( PU_BCUE_STAT_SCOM,
          RULL(0x05016857), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x00068017)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200C0) != RULL(0xC00400C0)  name: PU_BCUE_PBADR_OCI
FIXREG64( PU_BCUE_PBADR_OCI,
          RULL(0xC00400C0), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200C0)
        );
FIXREG64( PU_BCUE_PBADR_SCOM,
          RULL(0x05016858), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068018)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200C8) != RULL(0xC00400C8)  name: PU_BCUE_OCIBAR_OCI
FIXREG64( PU_BCUE_OCIBAR_OCI,
          RULL(0xC00400C8), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200C8)
        );
FIXREG64( PU_BCUE_OCIBAR_SCOM,
          RULL(0x05016859), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068019)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200D0) != RULL(0xC00400D0)  name: PU_PBAPBOCR0_OCI
FIXREG64( PU_PBAPBOCR0_OCI,
          RULL(0xC00400D0), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200D0)
        );
FIXREG64( PU_PBAPBOCR0_SCOM,
          RULL(0x0501685A), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x0006801A)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200D8) != RULL(0xC00400D8)  name: PU_PBAPBOCR1_OCI
FIXREG64( PU_PBAPBOCR1_OCI,
          RULL(0xC00400D8), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200D8)
        );
FIXREG64( PU_PBAPBOCR1_SCOM,
          RULL(0x0501685B), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x0006801B)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200E0) != RULL(0xC00400E0)  name: PU_PBAPBOCR2_OCI
FIXREG64( PU_PBAPBOCR2_OCI,
          RULL(0xC00400E0), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200E0)
        );
FIXREG64( PU_PBAPBOCR2_SCOM,
          RULL(0x0501685C), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x0006801C)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200E8) != RULL(0xC00400E8)  name: PU_PBAPBOCR3_OCI
FIXREG64( PU_PBAPBOCR3_OCI,
          RULL(0xC00400E8), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200E8)
        );
FIXREG64( PU_PBAPBOCR3_SCOM,
          RULL(0x0501685D), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x0006801D)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200F0) != RULL(0xC00400F0)  name: PU_PBAPBOCR4_OCI
FIXREG64( PU_PBAPBOCR4_OCI,
          RULL(0xC00400F0), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200F0)
        );
FIXREG64( PU_PBAPBOCR4_SCOM,
          RULL(0x0501685E), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x0006801E)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x400200F8) != RULL(0xC00400F8)  name: PU_PBAPBOCR5_OCI
FIXREG64( PU_PBAPBOCR5_OCI,
          RULL(0xC00400F8), SH_UNT, SH_ACS_OCI,
          RULL(0xC00200F8)
        );
FIXREG64( PU_PBAPBOCR5_SCOM,
          RULL(0x0501685F), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x0006801F)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020100) != RULL(0xC0040100)  name: PU_PBAXSNDTX_OCI
FIXREG64( PU_PBAXSNDTX_OCI,
          RULL(0xC0040100), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020100)
        );
FIXREG64( PU_PBAXSNDTX_SCOM,
          RULL(0x05016860), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068020)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020108) != RULL(0xC0040108)  name: PU_PBAXCFG_OCI
FIXREG64( PU_PBAXCFG_OCI,
          RULL(0xC0040108), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020108)
        );
FIXREG64( PU_PBAXCFG_SCOM,
          RULL(0x05016861), SH_UNT, SH_ACS_SCOM,
          RULL(0x00068021)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020110) != RULL(0xC0040110)  name: PU_PBAXSNDSTAT_OCI
FIXREG64( PU_PBAXSNDSTAT_OCI,
          RULL(0xC0040110), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020110)
        );
FIXREG64( PU_PBAXSNDSTAT_SCOM,
          RULL(0x05016862), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x00068022)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020120) != RULL(0xC0040120)  name: PU_PBAXRCVSTAT_OCI
FIXREG64( PU_PBAXRCVSTAT_OCI,
          RULL(0xC0040120), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020120)
        );
FIXREG64( PU_PBAXRCVSTAT_SCOM,
          RULL(0x05016864), SH_UNT, SH_ACS_SCOM_RO,
          RULL(0x00068024)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020130) != RULL(0xC0040130)  name: PU_PBAXSHBR0_OCI
FIXREG64( PU_PBAXSHBR0_OCI,
          RULL(0xC0040130), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020130)
        );
FIXREG64( PU_PBAXSHBR0_SCOM,
          RULL(0x05016866), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x00068026)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020138) != RULL(0xC0040138)  name: PU_PBAXSHCS0_OCI
FIXREG64( PU_PBAXSHCS0_OCI,
          RULL(0xC0040138), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020138)
        );
FIXREG64( PU_PBAXSHCS0_SCOM,
          RULL(0x05016867), SH_UNT, SH_ACS_SCOM,
          RULL(0x00068027)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020150) != RULL(0xC0040150)  name: PU_PBAXSHBR1_OCI
FIXREG64( PU_PBAXSHBR1_OCI,
          RULL(0xC0040150), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020150)
        );
FIXREG64( PU_PBAXSHBR1_SCOM,
          RULL(0x0501686A), SH_UNT, SH_ACS_SCOM_RW,
          RULL(0x0006802A)
        );
//WARNING AUTO CORRECT: val mismatch: RULL(0x40020158) != RULL(0xC0040158)  name: PU_PBAXSHCS1_OCI
FIXREG64( PU_PBAXSHCS1_OCI,
          RULL(0xC0040158), SH_UNT, SH_ACS_OCI,
          RULL(0xC0020158)
        );
FIXREG64( PU_PBAXSHCS1_SCOM,
          RULL(0x0501686B), SH_UNT, SH_ACS_SCOM,
          RULL(0x0006802B)
        );


//WARNING: This register is not defined anymore in the figtree.
REG64( PU_XSCOM_DAT0_REG, RULL(0x0009001E), SH_UNT, SH_ACS_SCOM_RW);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_RCV_ERRLOG1_REG, RULL(0x00090023), SH_UNT, SH_ACS_SCOM_WAND);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_TOD_DATA_SND_REG, RULL(0x00090028), SH_UNT, SH_ACS_SCOM_RW);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PIB_CMD_REG, RULL(0x00090031), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_FORCE_ECC_REG, RULL(0x0009000D), SH_UNT, SH_ACS_SCOM_RW);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_IO_DATA_REG, RULL(0x00090030), SH_UNT, SH_ACS_SCOM_RO);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_ALTD_STATUS_REG, RULL(0x00090003), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_LPC_BASE_REG, RULL(0x00090040), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_TOD_DATA_RCV_REG, RULL(0x00090029), SH_UNT, SH_ACS_SCOM_RO);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_SND_MODE_REG, RULL(0x00090021), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_XSCOM_LOG_REG, RULL(0x00090012), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_XSCOM_MODE_REG, RULL(0x00090011), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_XSCOM_RCVED_STAT_REG, RULL(0x00090018), SH_UNT, SH_ACS_SCOM_WCLRREG);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_ADS_XSCOM_CMD_REG, RULL(0x0009001C), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_XSCOM_ERR_REG, RULL(0x00090013), SH_UNT, SH_ACS_SCOM_WCLRREG);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_SND_STAT_REG, RULL(0x00090020), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_XSCOM_BASE_REG, RULL(0x00090010), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_ALTD_ADDR_REG, RULL(0x00090000), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_TOD_CMD_REG, RULL(0x0009002A), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_LPC_DATA_REG, RULL(0x00090042), SH_UNT, SH_ACS_SCOM_RO);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_XSCOM_DAT1_REG, RULL(0x0009001F), SH_UNT, SH_ACS_SCOM_RW);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PIB_RESET_REG, RULL(0x00090033), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_PIB_DATA_REG, RULL(0x00090032), SH_UNT, SH_ACS_SCOM_RO);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_ALTD_DATA_REG, RULL(0x00090004), SH_UNT, SH_ACS_SCOM_RW);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_ALTD_OPTION_REG, RULL(0x00090002), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_ALTD_CMD_REG, RULL(0x00090001), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_LPC_CMD_REG, RULL(0x00090041), SH_UNT, SH_ACS_SCOM);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_RCV_ERRLOG0_REG, RULL(0x00090022), SH_UNT, SH_ACS_SCOM_WAND);
//WARNING: This register is not defined anymore in the figtree.
REG64( PU_ADU_HANG_DIV_REG, RULL(0x00090050), SH_UNT, SH_ACS_SCOM_RW);
#endif
