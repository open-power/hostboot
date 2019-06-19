/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_nmmu_c.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_nmmu_c_H_
#define __p10_scom_nmmu_c_H_


namespace scomt
{
namespace nmmu
{


static const uint64_t CFG_NMMU_CTL_MISC = 0x02010c53ull;

static const uint32_t CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS = 1;
static const uint32_t CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN = 2;
static const uint32_t CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN = 3;
static const uint32_t CFG_NMMU_CTL_MISC_CTL_LFSR_DIS = 8;
static const uint32_t CFG_NMMU_CTL_MISC_FBC_LFSR_DIS = 9;
static const uint32_t CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS = 10;
static const uint32_t CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS = 12;
static const uint32_t CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS = 13;
static const uint32_t CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS = 14;
static const uint32_t CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS = 15;
static const uint32_t CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS = 16;
static const uint32_t CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS = 17;
static const uint32_t CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS = 18;
static const uint32_t CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS = 19;
static const uint32_t CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS = 20;
static const uint32_t CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS = 21;
static const uint32_t CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS = 22;
static const uint32_t CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS = 23;
static const uint32_t CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS = 24;
static const uint32_t CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS = 25;
static const uint32_t CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS = 26;
static const uint32_t CFG_NMMU_CTL_MISC_HANG_PLS_MULT = 32;
static const uint32_t CFG_NMMU_CTL_MISC_HANG_PLS_MULT_LEN = 16;
static const uint32_t CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE = 48;
static const uint32_t CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE_LEN = 8;
static const uint32_t CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE = 56;
static const uint32_t CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE_LEN = 8;
// nmmu/reg00012.H

}
}
#ifndef __PPE_HCODE__
    #include "nmmu/reg00012.H"
#endif
#endif
